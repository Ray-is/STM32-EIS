// Minimal L9965A driver for bench testing over the SPI target interface.
// References: L9965A datasheet DS15021 Rev 2, register map L9965A_regmap (STSW-L9965FW).

#include "l9965a.h"
#include <SPI.h>
#include "L9965A_regmap_DEFINE.h"

// ---------------------------------------------------------------------------
// Hardware and protocol constants
// ---------------------------------------------------------------------------

// Arduino Uno: NCS = D10. MOSI = D11, MISO = D12, SCK = D13 are fixed by the SPI hardware.
static const uint8_t PIN_NCS = 10;

// SPI target: CPOL = 0, CPHA = 1 (SPI mode 1), max 2 MHz, 40-bit frames (Table 56).
static const SPISettings L9965A_SPI_SETTINGS(1000000, MSBFIRST, SPI_MODE1);

// 40-bit frame layout (Tables 58/59):
//   39 P.A. | 38 R/W (MOSI) or burst (MISO) | 37..32 DEV_ID | 31..25 ADDRESS |
//   24 RSVD (MOSI) or FAULT (MISO) | 23..6 DATA (18 bit) | 5..0 CRC
#define FRAME_PA_BIT     39
#define FRAME_RW_BIT     38
#define FRAME_DEVID_POS  32
#define FRAME_ADDR_POS   25
#define FRAME_DATA_POS   6
#define FRAME_DATA_MASK  0x3FFFFUL
#define FRAME_CRC_MASK   0x3F

// CRC-6, polynomial x^6 + x^5 + x^2 + x + 1, seed 0x38, over frame bits 39..6 (Table 67).
#define CRC6_POLY        0x27   // x^6 term implicit 01100111
#define CRC6_SEED        0x38

// The SPI ERROR frame answers with ADDRESS FEEDBACK = 0x7F (Table 65).
#define SPI_ERROR_ADDR_FEEDBACK 0x7F

// SPECIAL_KEY codes (Procedure 9).
#define KEY_PARTIAL_UNLOCK  0x55
#define KEY_CONFIRM_UNLOCK  0x33
#define KEY_LOCK            0xAA

// Timing.
#define NCS_HIGH_US           10    // NCS minimum high time is 8.25 us
#define WAKEUP_WAIT_MS        5     // TSPI_WAKEUP 2 ms max, NVM download (TNVM_DOWNLOAD) 4.4 ms max
#define NVM_READY_TIMEOUT_MS  20
#define VCR_TIMEOUT_MS        1000  // each routine step times out at 150 ms max (TVOLT_TIMEOUT)

// Cell measurement: 16 bit, 201.4 uV per LSB, range [-6.6, 6.6] V (VCELL_RES, NBIT_CELL).
// Treated as two's complement; for positive cell voltages signed and unsigned readings are identical.
#define VCELL_LSB_V 201.4e-6f

// Register-map helpers built from L9965A_regmap_DEFINE.h.
#define REG_ADDR(reg) ((uint8_t)L9965A_REGMAP_##reg##_ADDR)
#define FIELD_MASK(reg, field)                                          \
    ((((uint32_t)1 << L9965A_REGMAP_##reg##_##field##_WIDTH) - 1)       \
     << L9965A_REGMAP_##reg##_##field##_OFFSET)

static_assert(L9965A_REGMAP_VCELL18_MEAS_ADDR == L9965A_REGMAP_VCELL1_MEAS_ADDR + 17,
              "VCELLx_MEAS registers are expected to be contiguous");

// ---------------------------------------------------------------------------
// Globals
// ---------------------------------------------------------------------------

int devId = -1;
float cellVoltages[L9965A_NUM_CELLS] = {
    -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f};

static uint64_t lastMiso = 0;   // last frame received, printed by handle_error()

// ---------------------------------------------------------------------------
// Error handling
// ---------------------------------------------------------------------------

static void print_hex40(uint64_t v) { // 0x1234
    for (int8_t shift = 36; shift >= 0; shift -= 4) {
        Serial.print((uint8_t)((v >> shift) & 0xF), HEX);
    }
}

template <typename T>
static void error_loop(T msg) {
    while (true) {
        Serial.print(F("ERROR: "));
        Serial.print(msg);
        Serial.print(F("  [last MISO 0x"));
        print_hex40(lastMiso);
        Serial.println(']');
        delay(1000);
    }
}

void handle_error(const char* msg) { error_loop(msg); }

// Same as above, for messages kept in flash with F("...") to save the Uno's 2 KB of RAM.
void handle_error(const __FlashStringHelper* msg) { error_loop(msg); }

static void require_dev_id() {
    if (devId < 0) handle_error(F("devId is -1: call set_vif_id() first"));
}

// ---------------------------------------------------------------------------
// SPI frame helpers
// ---------------------------------------------------------------------------

void init_spi() {
    Serial.begin(115200);   // matches monitor_speed; used by handle_error() and print_measurements()
    pinMode(PIN_NCS, OUTPUT);
    digitalWrite(PIN_NCS, HIGH);
    SPI.begin();
}

static uint8_t crc6(uint64_t frame) {
    uint8_t crc = CRC6_SEED;
    for (int8_t bit = 39; bit >= FRAME_DATA_POS; bit--) { // 40-1=39
        uint8_t feedback = (uint8_t)((frame >> bit) & 1) ^ ((crc >> 5) & 1);
        crc = (crc << 1) & FRAME_CRC_MASK;
        if (feedback) crc ^= CRC6_POLY;
    }
    return crc;
}

// Sends one 40-bit frame and returns the 40 bits clocked out at the same time.
// The protocol is out of frame: what comes back is the answer to the PREVIOUS frame.
static uint64_t spi_xfer(uint64_t mosi) {
    uint64_t miso = 0;
    SPI.beginTransaction(L9965A_SPI_SETTINGS);
    digitalWrite(PIN_NCS, LOW);
    for (int8_t shift = 32; shift >= 0; shift -= 8) {
        miso = (miso << 8) | SPI.transfer((uint8_t)(mosi >> shift));
    }
    digitalWrite(PIN_NCS, HIGH);
    SPI.endTransaction();
    delayMicroseconds(NCS_HIGH_US);
    lastMiso = miso;
    return miso;
}

static uint64_t make_frame(bool write, uint8_t dev, uint8_t addr, uint32_t data) {
    uint64_t frame = (uint64_t)1 << FRAME_PA_BIT;   // P.A. = 1: command from the MCU
    if (write) frame |= (uint64_t)1 << FRAME_RW_BIT;
    frame |= (uint64_t)(dev & 0x3F) << FRAME_DEVID_POS;
    frame |= (uint64_t)(addr & 0x7F) << FRAME_ADDR_POS;
    frame |= (uint64_t)(data & FRAME_DATA_MASK) << FRAME_DATA_POS;
    frame |= crc6(frame);
    return frame;
}

static bool is_valid_answer(uint64_t miso) {
    return crc6(miso) == (miso & FRAME_CRC_MASK) && !((miso >> FRAME_PA_BIT) & 1);
}

// Checks that `miso` is the answer to a read of `addr` on device `dev`.
static bool try_parse(uint64_t miso, uint8_t dev, uint8_t addr, uint32_t* data) {
    if (!is_valid_answer(miso)) return false;
    uint8_t ansDev = (miso >> FRAME_DEVID_POS) & 0x3F;
    uint8_t ansAddr = (miso >> FRAME_ADDR_POS) & 0x7F;
    if (ansAddr == SPI_ERROR_ADDR_FEEDBACK || ansDev != dev || ansAddr != addr) return false;
    *data = (uint32_t)(miso >> FRAME_DATA_POS) & FRAME_DATA_MASK;
    return true;
}

static void reg_write(uint8_t dev, uint8_t addr, uint32_t data) {
    spi_xfer(make_frame(true, dev, addr, data));   // returned frame is the previous command's answer
}

// Reads one register: the first frame sends the request, the second clocks out its answer.
static bool try_read(uint8_t dev, uint8_t addr, uint32_t* data) {
    spi_xfer(make_frame(false, dev, addr, 0));
    uint64_t miso = spi_xfer(make_frame(false, dev, addr, 0));
    return try_parse(miso, dev, addr, data);
}

static uint32_t reg_read(uint8_t addr) {
    uint32_t data;
    if (!try_read((uint8_t)devId, addr, &data)) {
        handle_error(F("Register read failed (bad CRC, SPI error frame, or wrong DEV_ID/address in answer)"));
    }
    return data;
}

static void config_unlock(uint8_t dev) {
    reg_write(dev, REG_ADDR(SPECIAL_REG), KEY_PARTIAL_UNLOCK);
    reg_write(dev, REG_ADDR(SPECIAL_REG), KEY_CONFIRM_UNLOCK);
}

static void config_lock(uint8_t dev) {
    reg_write(dev, REG_ADDR(SPECIAL_REG), KEY_LOCK);
}

// Read-modify-write of the bits in `mask`, inside an unlock/lock window, then read back to confirm.
// Writes to lock-protected registers are silently discarded while locked, so we always unlock.
static void update_field_verify(uint8_t addr, uint32_t mask, uint32_t value,
                                const __FlashStringHelper* errMsg) {
    config_unlock((uint8_t)devId);
    uint32_t reg = reg_read(addr);
    reg = (reg & ~mask) | (value & mask);
    reg_write((uint8_t)devId, addr, reg);
    config_lock((uint8_t)devId);
    if ((reg_read(addr) & mask) != (value & mask)) handle_error(errMsg);
    //if (reg != reg_read(addr)) handle_error(errMsg);
}

// ---------------------------------------------------------------------------
// Setup functions
// ---------------------------------------------------------------------------

void send_wakeup_spi() {
    // Wake-up pattern (5.10.5.4): NCS low, 40 SCK pulses, NCS high. The content is not decoded;
    // a READ is recommended so nothing gets written if the chip is already awake.
    spi_xfer(make_frame(false, 0, REG_ADDR(CHIPID), 0));
    delay(WAKEUP_WAIT_MS);   // DEEP SLEEP -> NORMAL, then the NVM download

    // The next frame clocks out the chip's first answer: the default frame 0x10 after a fresh
    // wake-up, or an SPI error frame if the chip was already awake (DEV_ID 0 can't be read).
    // Either way it must be a well-formed answer.
    spi_xfer(make_frame(false, 0, REG_ADDR(CHIPID), 0));
    if (!is_valid_answer(lastMiso)) {
        handle_error(F("No valid answer after wake-up: check VB supply, J5:J8 jumpers and SPI wiring"));
    }
}

void set_vif_id(int id) {
    if (id < 1 || id > 59) {
        handle_error(F("set_vif_id: id must be 1..59 (0 is broadcast, 60..63 are selective broadcast)"));
    }
    const uint8_t dev = (uint8_t)id;

    // Addressing (Procedure 8, single device): unlock, then write VIF_ID with a global broadcast.
    config_unlock(0);
    reg_write(0, REG_ADDR(VIF_ID), (uint32_t)dev << L9965A_REGMAP_VIF_ID_VIF_ID_OFFSET);

    // Read back at the new address. Broadcasts can't change a VIF_ID that is already non-zero
    // (for example one saved in NVM), in which case this read gets no matching answer.
    uint32_t data;
    if (!try_read(dev, REG_ADDR(VIF_ID), &data)) {
        handle_error(F("set_vif_id: no answer at the new ID (chip may already hold another VIF_ID)"));
    }
    uint32_t readBack = (data & FIELD_MASK(VIF_ID, VIF_ID)) >> L9965A_REGMAP_VIF_ID_VIF_ID_OFFSET;
    if (readBack != dev) handle_error(F("set_vif_id: VIF_ID readback mismatch"));
    devId = id;

    // We change registers without saving them to NVM, which would make the cyclic configuration
    // check set CYC_CFG_CRC_FAIL (and the FAULT bit) every 90 ms (5.13). Turn it off.
    update_field_verify(REG_ADDR(GENERAL_REG), FIELD_MASK(GENERAL_REG, CYC_CFG_CRC_DIS),
                        FIELD_MASK(GENERAL_REG, CYC_CFG_CRC_DIS),
                        F("set_vif_id: CYC_CFG_CRC_DIS readback failed"));

    // Clear communication errors latched during power-up and before addressing (5.10.1).
    reg_read(REG_ADDR(COMM_ERR));
}

void check_nvm() {
    require_dev_id();

    unsigned long start = millis();
    while (!(reg_read(REG_ADDR(GENERAL_CELL_DIAG)) & FIELD_MASK(GENERAL_CELL_DIAG, NVM_READY))) {
        if (millis() - start > NVM_READY_TIMEOUT_MS) handle_error(F("check_nvm: NVM_READY stayed 0"));
        delay(1);
    }

    // Clear-on-read corruption flags (5.13, 5.14).
    const uint32_t corruption = FIELD_MASK(GENERAL_DIAG, NVM_CRC_TRIM_CAL_FAIL) |
                                FIELD_MASK(GENERAL_DIAG, NVM_CRC_CFG_FAIL) |
                                FIELD_MASK(GENERAL_DIAG, CYC_TRIM_CRC_FAIL) |
                                FIELD_MASK(GENERAL_DIAG, RAM_ECC_FAIL);
    if (reg_read(REG_ADDR(GENERAL_DIAG)) & corruption) {
        handle_error(F("check_nvm: NVM/calibration corruption flag set in GENERAL_DIAG"));
    }
}

void enable_cells() {
    require_dev_id();
    // All cells are disabled by default (5.5.1). The EVL9965A load board supplies all 18.
    const uint32_t allCells = FIELD_MASK(VCELL_EN, VCELL1_EN) | FIELD_MASK(VCELL_EN, VCELL2_EN) |
                              FIELD_MASK(VCELL_EN, VCELL3_EN) | FIELD_MASK(VCELL_EN, VCELL4_EN) |
                              FIELD_MASK(VCELL_EN, VCELL5_EN) | FIELD_MASK(VCELL_EN, VCELL6_EN) |
                              FIELD_MASK(VCELL_EN, VCELL7_EN) | FIELD_MASK(VCELL_EN, VCELL8_EN) |
                              FIELD_MASK(VCELL_EN, VCELL9_EN) | FIELD_MASK(VCELL_EN, VCELL10_EN) |
                              FIELD_MASK(VCELL_EN, VCELL11_EN) | FIELD_MASK(VCELL_EN, VCELL12_EN) |
                              FIELD_MASK(VCELL_EN, VCELL13_EN) | FIELD_MASK(VCELL_EN, VCELL14_EN) |
                              FIELD_MASK(VCELL_EN, VCELL15_EN) | FIELD_MASK(VCELL_EN, VCELL16_EN) |
                              FIELD_MASK(VCELL_EN, VCELL17_EN) | FIELD_MASK(VCELL_EN, VCELL18_EN);
    update_field_verify(REG_ADDR(VCELL_EN), allCells, allCells,
                        F("enable_cells: VCELL_EN readback failed"));
}

void turnoff_balancing() {
    require_dev_id();
    update_field_verify(REG_ADDR(BAL_GEN_CFG), FIELD_MASK(BAL_GEN_CFG, BAL_START), 0,
                        F("turnoff_balancing: BAL_START readback failed"));
}

void turnoff_busbar() {
    require_dev_id();
    update_field_verify(REG_ADDR(VBS_BB_CFG), FIELD_MASK(VBS_BB_CFG, BB_EN), 0,
                        F("turnoff_busbar: BB_EN readback failed"));
}

// Optional. Without valid frames for TCOMM_TIM (reset value 2 s), the chip goes back to sleep.
// Call this if the measurement loop runs slower than that. Not acceptable for a real system.
void disable_comm_timeout() {
    require_dev_id();
    update_field_verify(REG_ADDR(DEV_GEN_CFG_1), FIELD_MASK(DEV_GEN_CFG_1, COMM_TIM_EN), 0,
                        F("disable_comm_timeout: COMM_TIM_EN readback failed"));
}

// ---------------------------------------------------------------------------
// Measurement cycle
// ---------------------------------------------------------------------------

void start_conversion() {
    require_dev_id();
    if (reg_read(REG_ADDR(GENERAL_CELL_DIAG)) & FIELD_MASK(GENERAL_CELL_DIAG, VCR_BUSY)) {
        // An SOC sent now would be discarded (5.5).
        handle_error(F("start_conversion: previous conversion still running"));
    }

    const uint32_t cmd = FIELD_MASK(VOLT_CONV, SOC) | FIELD_MASK(VOLT_CONV, VOLT_CONV) |
                         FIELD_MASK(VOLT_CONV, GAIN_ADJ);
    reg_write((uint8_t)devId, REG_ADDR(VOLT_CONV), cmd);

    // SOC is write-only, so confirm with the read/write step bits, which keep what was written.
    const uint32_t stepBits = FIELD_MASK(VOLT_CONV, VOLT_CONV) | FIELD_MASK(VOLT_CONV, VOLT_OPEN) |
                              FIELD_MASK(VOLT_CONV, TEMP_CONV) | FIELD_MASK(VOLT_CONV, TEMP_OPEN) |
                              FIELD_MASK(VOLT_CONV, RATIO_CONV) | FIELD_MASK(VOLT_CONV, ABS_CONV) |
                              FIELD_MASK(VOLT_CONV, GAIN_ADJ) | FIELD_MASK(VOLT_CONV, ADC_SWAP) |
                              FIELD_MASK(VOLT_CONV, BIST) | FIELD_MASK(VOLT_CONV, BIST_FAULT_INJ);
    if ((reg_read(REG_ADDR(VOLT_CONV)) & stepBits) != (cmd & stepBits)) {
        handle_error(F("start_conversion: VOLT_CONV readback mismatch"));
    }
}

void wait_for_data() {
    require_dev_id();
    bool failed = false;
    unsigned long start = millis();
    while (true) {
        uint32_t diag = reg_read(REG_ADDR(GENERAL_CELL_DIAG));   // VCR_FAIL clears on read
        if (diag & FIELD_MASK(GENERAL_CELL_DIAG, VCR_FAIL)) failed = true;
        if (!(diag & FIELD_MASK(GENERAL_CELL_DIAG, VCR_BUSY))) break;
        if (millis() - start > VCR_TIMEOUT_MS) handle_error(F("wait_for_data: VCR_BUSY stuck at 1"));
        delay(1);
    }
    if (failed) handle_error(F("wait_for_data: VCR_FAIL set (a routine step timed out)"));
}

void read_cell_voltages() {
    require_dev_id();
    const uint8_t dev = (uint8_t)devId;
    const uint8_t firstAddr = REG_ADDR(VCELL1_MEAS);

    // Pipelined reads: each frame requests the next cell and clocks out the previous answer,
    // so 18 registers take 19 frames. The last frame just repeats the cell 18 request.
    spi_xfer(make_frame(false, dev, firstAddr, 0));
    for (uint8_t i = 0; i < L9965A_NUM_CELLS; i++) {
        uint8_t nextAddr = firstAddr + ((i + 1 < L9965A_NUM_CELLS) ? i + 1 : i);
        uint64_t miso = spi_xfer(make_frame(false, dev, nextAddr, 0));

        uint32_t data;
        if (!try_parse(miso, dev, firstAddr + i, &data)) {
            handle_error(F("read_cell_voltages: bad answer for a VCELLx_MEAS register"));
        }
        // DATA_READY is set by each new conversion and cleared on read.
        if (!(data & FIELD_MASK(VCELL1_MEAS, DATA_READY))) {
            handle_error(F("read_cell_voltages: DATA_READY = 0 (no new measurement)"));
        }
        int16_t raw = (int16_t)(data & FIELD_MASK(VCELL1_MEAS, VCELL1_MEAS));
        cellVoltages[i] = raw * VCELL_LSB_V;
    }
}

void print_measurements() {
    require_dev_id();
    Serial.print(F("t = "));
    Serial.print(millis());
    Serial.println(F(" ms"));
    for (uint8_t i = 0; i < L9965A_NUM_CELLS; i++) {
        Serial.print(F("  Cell "));
        if (i + 1 < 10) Serial.print('0');
        Serial.print(i + 1);
        Serial.print(F(": "));
        Serial.print(cellVoltages[i], 4);
        Serial.println(F(" V"));
    }
}
