#ifndef __L9965C_REGMAP_H
#define __L9965C_REGMAP_H
/******************************************************************************/
/*                           Module: L9965C_REGMAP                              */
/*      All fields declared are unsigned! Please cast them as convenient      */
/******************************************************************************/
struct L9965C_REGMAP_STRUCTURE
{
	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t name_id:8; //For UR1C -> DevName = 0x1c
			uint32_t silicon_id:3; //Silicon version identification
			uint32_t metal_id:5; //Metal layer version identification
		} bitfields;
	} CHIPID;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:12; //Unused
			uint32_t vif_id:6; //It identifies the device address
		} bitfields;
	} VIF_ID_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:3; //Unused
			uint32_t nvm_uploads_count:5; //It is the number of uploads already done (spec max = 31)
			uint32_t unused_0:2; //Unused
			uint32_t comm_tim_en:1; //It enables the communication timeout
			uint32_t comm_tim_th:2; //Communication timeout threshold -> 00 = 100ms, 01 = 500ms, 10 = 1s, 11 = 2s
			uint32_t broadcast_sel_1:2; //Mailbox configuration see spec for details
			uint32_t broadcast_sel_2:2; //Mailbox configuration see spec for details
			uint32_t unused_1:1; //Unused
		} bitfields;
	} DEV_GEN_CFG_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:9; //Unused
			uint32_t gpio0_ncs0_active_idle:1; //0: GPIO0_NCS0 is in HiZ when it is not used if SPI MASTER mode has been selected 1: GPIO0_NCS0 is kept to 1 when it is not used if SPI MASTER mode has been selected
			uint32_t gpio1_ncs1_active_idle:1; //0: GPIO1_NCS1 is in HiZ when it is not used if SPI MASTER mode has been selected 1: GPIO1_NCS1 is kept to 1 when it is not used if SPI MASTER mode has been selected
			uint32_t gpio1_ncs1_en:1; //Set to 1, if GPIO1_NCS1 is configured as second chip select
			uint32_t i2c_en:1; //It enables I2C master protocol, so GPIO5 and GPIO6 are configured as SDA and SCL respectively, regardless of the GPIO<x>_CONF
			uint32_t i2c_master_clk :1; //Select I2C master clock frequency -> 0 = 62.5kHz, 1 = 250kHz
			uint32_t spi_master_cpha1:1; //It configures SPI Master clk phase when it is  the chip select 1 (GPIO1_NCS1)
			uint32_t spi_master_cpha0:1; //It configures SPI Master clk phase when it is selected the chip select 0 (GPIO0_NCS0)
			uint32_t spi_master_cpol1:1; //It configures SPI Master clk polarity when it is selected the chip select 1 (GPIO1_NCS1)
			uint32_t spi_master_cpol0:1; //It configures SPI Master clk polarity when it is selected the chip select 0 (GPIO0_NCS0)
		} bitfields;
	} DEV_GEN_CFG_2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:7; //Unused
			uint32_t xcheck_high_th:2; //Xcheck CSA threshold for high range -> 00 = 1024LSB, 01 = 512LSB, 10 = 256LSB, 11 = 128LSB
			uint32_t xcheck_low_th:2; //Xcheck CSA threshold for low range -> 00 = 40LSB, 01 = 70LSB, 10 = 200LSB, 11 = 127LSB
			uint32_t csa_ol_set:3; //CSA open load settling time -> 000 = 25ms, 001 = 50ms, 010 = 75ms, 011 = 100ms, 100 = 125ms, 101 = 150ms, 110 = 175ms, 111 = 200ms 
			uint32_t sc1_en:1; //It enables Short Circuit Detection 1
			uint32_t sc0_en:1; //It enables Short Circuit Detection 0
			uint32_t ovc_en:1; //It enable OVC diagnostic (both CSAs)
			uint32_t cur_inst_en:1; //It enables CSA INST
		} bitfields;
	} CFG_DIAG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //Unused
			uint32_t gpio6_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO6 is a digital input)
			uint32_t gpio5_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO5 is a digital input)
			uint32_t gpio4_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO4 is a digital input)
			uint32_t gpio3_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO3 is a digital input)
			uint32_t gpio2_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO2 is a digital input)
			uint32_t gpio1_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO1 is a digital input)
			uint32_t gpio0_pu_pd:1; //0 = WEAK PULLDOWN, 1 = WEAK PULLUP (when GPIO0 is a digital input)
			uint32_t gpio6_conf:1; //It configures GPIO6: 0 = GENERIC DIGITAL INPUT (reading on GPI6 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO6 is driving by GPO0 bit)
			uint32_t gpio5_conf:1; //It configures GPIO5: 0 = GENERIC DIGITAL INPUT (reading on GPI5 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO5 is driving by GPO0 bit)
			uint32_t gpio4_conf:1; //It configures GPIO4: 0 = GENERIC DIGITAL INPUT (reading on GPI4 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO4 is driving by GPO0 bit)
			uint32_t gpio3_conf:1; //It configures GPIO3: 0 = GENERIC DIGITAL INPUT (reading on GPI3 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO3 is driving by GPO0 bit)
			uint32_t gpio2_conf:1; //It configures GPIO2: 0 = GENERIC DIGITAL INPUT (reading on GPI2 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO2 is driving by GPO0 bit)
			uint32_t gpio1_conf:1; //It configures GPIO1: 0 = GENERIC DIGITAL INPUT (reading on GPI1 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO1 is driving by GPO0 bit)
			uint32_t gpio0_conf:1; //It configures GPIO0: 0 = GENERIC DIGITAL INPUT (reading on GPI0 BIT), 1 = GENERIC DIGITAL OUTPUT (GPIO0 is driving by GPO0 bit)
		} bitfields;
	} CFG_GPIO;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:6; //Unused
			uint32_t sc_th_sel:8; //Same threshold for SC0 and SC1
			uint32_t fault0_level:1; //It sets failures state on FAULT0 -> 0 = failure state is low level or dcFAULT_LOW duty, 1 = failure state is high level or dcFAULT_HIGH duty
			uint32_t fault1_level:1; //It sets failures state on FAULT1 -> 0 = failure state is low level or dcFAULT_LOW duty, 1 = failure state is high level or dcFAULT_HIGH duty
			uint32_t sc0_fault_msk:1; //It masks reaction non FAULT0 pad
			uint32_t sc1_fault_msk:1; //It masks reaction non FAULT1 pad
		} bitfields;
	} SC_SET_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t gate7_pd:2; //GATE7 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate6_pd:2; //GATE6 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate5_pd:2; //GATE5 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate4_pd:2; //GATE4 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate3_pd:2; //GATE3 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate2_pd:2; //GATE2 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate1_pd:2; //GATE1 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate0_pd:2; //GATE0 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
		} bitfields;
	} GATE_PRDRV_PD_0_TO_7;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:14; //Unused
			uint32_t gate9_pd:2; //GATE9 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
			uint32_t gate8_pd:2; //GATE8 pulldown current -> 00 = 1mA, 01 = 5mA, 10 = 10mA, 11 = 15mA
		} bitfields;
	} GATE_PRDRV_PD_8_TO_9;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t ovc_dchg_th:8; //Same threshold for CSA0 and CSA1
			uint32_t ovc_chg_th:8; //Same threshold for CSA0 and CSA1
		} bitfields;
	} CSA_OVC_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //Unused
			uint32_t cc_stby_en:1; //STBY mode can be activated if CC_EN = 1 and CC_STBY_EN =1
			uint32_t cc_stby_cal_en:1; //It enables TADC STBY, that is used for CSA CC calibration
			uint32_t cc_en:1; //It enables CSA CC
			uint32_t cur_cc_fil:2; //Acquisition time for CC -> 00 = 68.64ms, 01 = 135.2ms, 10 = 268.32ms, 11 = 534.56ms
			uint32_t cc_wakeup_th:8; //Coulomb Counter wakeup threshold 
		} bitfields;
	} CFG_FOR_STBY_LOGIC;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //Unused
			uint32_t special_key:8; //unlock 1 0x55, unlock2 0x33, lock 0xAA  -- sw_reset frame1 0xE1, frame2 0x1E -- go2slp command 0xCC
		} bitfields;
	} SPECIAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //Unused
			uint32_t xcheck_adc_inst_cc:1; //Launch XCHECK CSAs
			uint32_t unused_0:10; //Unused
			uint32_t adc_inst_conv:1; //Launch CSA INST
			uint32_t soc:1; //Trigger of command frame
		} bitfields;
	} CMD1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //Unused
			uint32_t abist:1; //It is the ABIST trigger for NORMAL state, in CYCLIC WAKEUP it is automatic. Analog comparators are: vb_uv (only for normal), vtref ov_uv, vana ov_uv, v5v uv_ov
			uint32_t abist_cp_uv_ov:1; //It is the ABIST trigger for NORMAL state. Analog comparators are: cp_uv, cp_ov
			uint32_t csa1_ol_diag:1; //Launch open load diagnostic on CSA0
			uint32_t csa0_ol_diag:1; //Launch open load diagnostic on CSA1
			uint32_t gnd_loss_enable:1; //Enable gnd loss diagnostic
			uint32_t xcheck_csa_selftest:1; //Launch XCHECK CSA SELFTEST
			uint32_t xcheck_temp_fault_inj:1; //Set to 1 to inject a fault for XCHECK TEMP
			uint32_t xcheck_sc_conv_fault_inj:1; //Set to 1 to inject a fault for XCHECK SC
			uint32_t sc_inject :2; //01 = injects a fault on SC0, 10 = injects a fault on SC1, 00/11 = invalid codes
			uint32_t sc_arm:1; //Set to 1 to arm the fault cirvuit injection trigger. If time out expire must be reset
			uint32_t vadc_ain_fault_inj:1; //Set to 1 to inject a fault for VADC
			uint32_t vadc_ain_bist:1; //It is the ABIST trigger for VADC
		} bitfields;
	} CMD2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //Unused
			uint32_t bidi_answ:1; //1 (default) = device generates bi-directional answers on both ISOH and ISOL ports, 0 = device answer use the same ISO port that received the command
			uint32_t isoh_tx_en:1; //Enable in normal state ISOH transmitter
			uint32_t isol_tx_en:1; //Enable in normal state ISOL transmitter
			uint32_t nvm_crc_fail_msk:1; //It masks the replacement with all 0 the NVM sector download with CRC error
			uint32_t cyc_cfg_crc_dis:1; //Disable check of CRC cyclic on configuration regs
			uint32_t nvm_op_cmd:3; //101 = NVM download on demand, 011 = NVM upload on demand
		} bitfields;
	} GENERAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:15; //Unused
			uint32_t comm_tim:1; //Communication timeout has been expired
			uint32_t spi_mode:2; //00 = SPI slave, 01/10 = SPI disable, 11 = SPI master. Modificable only by VIF. No using SPI
		} bitfields;
	} SPI_VIF_CT;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //Unused
			uint32_t spi_master_busy:1; //Indicates that a SPI master communication is running
			uint32_t spi_frame_size1:3; //Set frame size for SPI communication on GPIO1_NCS1. 000 = 8  bits, 001 = 16 bits, 010 = 24 bits, 011 = 32 bits, others = 40 bits
			uint32_t spi_frame_size0:3; //Set frame size for SPI communication on GPIO0_NCS0. 000 = 8  bits, 001 = 16 bits, 010 = 24 bits, 011 = 32 bits, others = 40 bits
			uint32_t spi_ncs1:1; //Select GPIO1_NCS1 to be used as chip select for SPI master communication (both SPI_NCS0 and SPI_NCS1 = 1 is not valid)
			uint32_t spi_ncs0:1; //Select GPIO1_NCS0 to be used as chip select for SPI master communication (both SPI_NCS0 and SPI_NCS1 = 1 is not valid)
			uint32_t spi_transfer:1; //Trigger to launch a SPI communication (device is master, it sends MOSI frame)
		} bitfields;
	} SPI_MASTER;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //Unused
			uint32_t spi_mosi_39_32:8; //Fifth byte to send
		} bitfields;
	} SPI_MOSI_39_32;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t spi_mosi_31_24:8; //Fourth byte to send
			uint32_t spi_mosi_23_16:8; //Third byte to send
		} bitfields;
	} SPI_MOSI_31_16;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t spi_mosi_15_8:8; //Second byte to send
			uint32_t spi_mosi_7_0:8; //First byte to send
		} bitfields;
	} SPI_MOSI_15_0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //Unused
			uint32_t spi_miso_39_32:8; //Fifth byte to receive
		} bitfields;
	} SPI_MISO_39_32;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t spi_miso_31_24:8; //Fourth byte to receive
			uint32_t spi_miso_23_16:8; //Third byte to receive
		} bitfields;
	} SPI_MISO_31_16;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t spi_miso_15_8:8; //Second byte to receive
			uint32_t spi_miso_7_0:8; //First byte to receive
		} bitfields;
	} SPI_MISO_15_0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:7; //Unused
			uint32_t i2c_tx_err:1; //Error on TX I2C. TX has not been sent correctly on SDA
			uint32_t i2c_rx_ack_err:1; //Error on RX ACK
			uint32_t i2c_stop_after_nack:1; //Send a STOP after it has received/sent a NACK
			uint32_t i2c_force_nack:1; //Force NACK (when device drives NACK)
			uint32_t i2c_rd_wr_n:1; //0 = writing operation, 1 = reading operation
			uint32_t i2c_op_code:3; //3 bit to send: bit 2 = START, bit 1 = DATA, bit 0 = STOP (codes 000, 100, 101 are UNUSED)
			uint32_t i2c_frame_size:2; //Set frame size for I2C communication. 00 = 1 byte, 01 = 2 byte, 10 = 3 byte, 11 = 4 byte. To sends 40 bit => sends bytes in two times
			uint32_t i2c_transfer:1; //Trigger to launch a I2C communication (device is master)
		} bitfields;
	} I2C_MASTER;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t i2c_tx_byte_0:8; //First byte to send
			uint32_t i2c_tx_byte_1:8; //Second byte to send
		} bitfields;
	} I2C_TX_BYTE_0_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t i2c_tx_byte_2:8; //Third byte to send
			uint32_t i2c_tx_byte_3:8; //Fourth byte to send
		} bitfields;
	} I2C_TX_BYTE_2_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t i2c_rx_byte_0:8; //First byte to receive
			uint32_t i2c_rx_byte_1:8; //Second byte to receive
		} bitfields;
	} I2C_RX_BYTE_0_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t i2c_rx_byte_2:8; //Third byte to receive
			uint32_t i2c_rx_byte_3:8; //Fourth byte to receive
		} bitfields;
	} I2C_RX_BYTE_2_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:15; //Unused
			uint32_t cur_inst_fil:3;		} bitfields;
	} CFG_CSA_INST;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:14; //Unused
			uint32_t fault1_cyclic_bist:1; //If FAULT1 output is configure in level mode, a real-time BIST can be performed setting this bit to 1
			uint32_t fault0_cyclic_bist:1; //If FAULT0 output is configure in level mode, a real-time BIST can be performed setting this bit to 1
			uint32_t fault1_mode:1; //Configure FAULT1 output in: 0 = level mode, 1 = PWM mode
			uint32_t fault0_mode:1; //Configure FAULT0 output in: 0 = level mode, 1 = PWM mode
		} bitfields;
	} FAULT_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:16; //Unused
			uint32_t fltin_en:1; //Enable the capable of decoding fault signals incoming from fault line(FAULTx)
			uint32_t fltin_int_check_en:1; //Enable FLTIN line integrity check
		} bitfields;
	} FLTIN_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:15; //Unused
			uint32_t cwup_en:1; //Set to 1 to configure GPIO6_SCL_CWUP as CWUP
			uint32_t cwup_hold:1; //If CWUP_EN = 1 and this bit is set to 1 -> CWUP is held to high
			uint32_t cwup_tim_en:1; //Enable CWUP timer
		} bitfields;
	} CWUP_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:15; //Unused
			uint32_t tim_th_sel:3; //Configure the CWUP timer threshold
		} bitfields;
	} CWUP_CFG_TIM_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //Unused
			uint32_t gate9_en:1; //It enables gate9 pre-driver
			uint32_t gate8_en:1; //It enables gate8 pre-driver
			uint32_t gate7_en:1; //It enables gate7 pre-driver
			uint32_t gate6_en:1; //It enables gate6 pre-driver
			uint32_t gate5_en:1; //It enables gate5 pre-driver
			uint32_t gate4_en:1; //It enables gate4 pre-driver
			uint32_t gate3_en:1; //It enables gate3 pre-driver
			uint32_t gate2_en:1; //It enables gate2 pre-driver
			uint32_t gate1_en:1; //It enables gate1 pre-driver
			uint32_t gate0_en:1; //It enables gate0 pre-driver
		} bitfields;
	} GATE_PRDRV_EN;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //Unused
			uint32_t gate9:1; //Gate9 output follow this command bit
			uint32_t gate8:1; //Gate8 output follow this command bit
			uint32_t gate7:1; //Gate7 output follow this command bit
			uint32_t gate6:1; //Gate6 output follow this command bit
			uint32_t gate5:1; //Gate5 output follow this command bit
			uint32_t gate4:1; //Gate4 output follow this command bit
			uint32_t gate3:1; //Gate3 output follow this command bit
			uint32_t gate2:1; //Gate2 output follow this command bit
			uint32_t gate1:1; //Gate1 output follow this command bit
			uint32_t gate0:1; //Gate0 output follow this command bit
		} bitfields;
	} GATE_CMD;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //Unused
			uint32_t amuxp_conf :4; //It configures ADC input P. See spec for configuration
			uint32_t amuxn_conf:4; //It configures ADC input N. See spec for configuration
			uint32_t abs_ratio :1; //It defines the conversion type -> 0 = ratiometric, 1 = absolute measurement
			uint32_t tvolt_fil:3; //VADC filter time -> 000 = 0.532ms, 001 = 1.064ms, 010 = 2.128ms, 011 = 4.256ms, 100 = 8.512ms, 101 = 17.024ms, 110 = 34.048ms, 111 = 68.096ms
			uint32_t vconv:1; //It is the trigger for VADC on demand
		} bitfields;
	} AIN_CMD_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:11; //Unused
			uint32_t gpo6:1; //GPIO6 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo5:1; //GPIO5 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo4:1; //GPIO4 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo3:1; //GPIO3 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo2:1; //GPIO2 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo1:1; //GPIO1 can be driven according to this bit, when it is configure as GPIO digital output
			uint32_t gpo0:1; //GPIO0 can be driven according to this bit, when it is configure as GPIO digital output
		} bitfields;
	} GPO_CMD;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:11; //Unused
			uint32_t gpi6:1; //Input buffer GPIO6 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi5:1; //Input buffer GPIO5 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi4:1; //Input buffer GPIO4 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi3:1; //Input buffer GPIO3 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi2:1; //Input buffer GPIO2 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi1:1; //Input buffer GPIO1 status can be read in this bit, when it is configured as GPIO digital input
			uint32_t gpi0:1; //Input buffer GPIO0 status can be read in this bit, when it is configured as GPIO digital input
		} bitfields;
	} GPI_READ;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t dc_link_v_th:10; //It sets the VDC-LINK_OFF_TH for the detection of the end-of-charge
			uint32_t dc_link_diode:6; //It sets the recirculation offset 2VDW
			uint32_t dc_link_en:1; //To run the precharge DC LINK function
			uint32_t dc_link_ovc_safe_msk:1; //It masks reaction on GATE9 pre-driver and the detection (DC_LINK_OVC_SAFE)
		} bitfields;
	} DC_LINK_CFG_0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //Unused
			uint32_t dc_link_end:1; //If the converted voltage becomes higher or equal to VDC-LINK_OFF_TH, the DC_LINK_END latch is set and the switching activity is interrupted: GATE9 is then permanently OFF
			uint32_t dc_link_ripple:16; //It is the product between the current ripple and the pre-charge inductor
		} bitfields;
	} DC_LINK_CFG_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t cur_inst:18; //CSA 0 measurement
		} bitfields;
	} CSA_INST_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t cur_cc_msb:18; //Coulumb counter accumulator MSB measurement (See procedure to read in the spec)
		} bitfields;
	} CUR_CC_MSB;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t cur_cc_lsb:8; //Coulumb counter accumulator LSB measurement (See procedure to read in the spec)
			uint32_t cc_sample_cnt:8; //Coulumb Counter sample counter thats counts the number of samples stored in the accumulator
		} bitfields;
	} CUR_CC_LSB_CNT;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //Unused
			uint32_t data_ready_ain:1; //VADC data valid
			uint32_t ain_meas:16; //VADC measurement
		} bitfields;
	} AIN_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:6; //Unused
			uint32_t die_adc_temp_meas:12; //Junction temperature measurement
		} bitfields;
	} DIE_TEMP_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //Unused
			uint32_t vadc_ain_bist_fail:1; //Fail on the execution of ABIST for VADC
			uint32_t vadc_ain_bist_done:1; //Abist on VADC is completed
			uint32_t dc_link_ovc_safe:1; //It is latched, if during ON phase of DC_LINK, the voltage on AIN0 raises above VPRECHG_OC for longer than TPRECHG_OC_FIL
			uint32_t abist_fail:1; //Fail on the execution of ABIST on comparators vb_uv (only for normal), vtref ov_uv, vana ov_uv, v5v uv_ov
			uint32_t abist_done:1; //ABIST on comparators  vb_uv (only for normal), vtref ov_uv, vana ov_uv, v5v uv_ov is completed
			uint32_t gnd_loss_fail:1; //Fail on gnd loss
			uint32_t osc_fail:1; //Fail on oscillator main or stby
			uint32_t v5v_uv:1; //V5V under voltage
			uint32_t v5v_ov:1; //V5V over voltage
			uint32_t vcp_uv:1; //Voltage charge pump under voltage
			uint32_t vcp_ov:1; //Voltage charge pump over voltage
			uint32_t vana_uv:1; //VANA under voltage
			uint32_t vana_ov:1; //VANA over voltage
			uint32_t vtref_uv:1; //VTREF under voltage
			uint32_t vtref_ov:1; //VTREF over voltage
			uint32_t vb_uv:1; //VB under voltage
			uint32_t por_main_asserted:1; //1 -> POR_MAIN_N assertion occured between this reading and previous one on this register
		} bitfields;
	} DIAG_STATUS1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //Unused
			uint32_t abist_gnd_loss_ol_fail:1; //Fail on the execution of ABIST on compators gnd loss and open load csa0 and open load csa1 (executed only in cyclic wakeup)
			uint32_t abist_cp_uv_ov_fail:1; //Fail on the execution of ABIST on compators cp uv and cp ov
			uint32_t abist_cp_uv_ov_done:1; //ABIST on comparators cp_uv and cp_ov is completed
			uint32_t v5v_oc:1; //V5V over current
			uint32_t vana_oc:1; //VNA over current
			uint32_t cyc_cfg_crc_fail:1; //CRC cyclic on configuration bits
			uint32_t cyc_trim_cal_crc_fail:1; //CRC cyclic on trimming/calib bits
			uint32_t nvm_crc_trim_cal_fail:1; //NVM CRC error on at least one trimming/calibration NVM sector. If NVM_CRC_FAIL_MSK = 1, it can always cleared
			uint32_t nvm_crc_cfg_fail:1; //NVM CRC error on at least one configuration NVM sector. If NVM_CRC_FAIL_MSK = 1, it can always cleared
			uint32_t xcheck_temp_fail:1; //Fail of xcheck between 2 temperatures conversion
			uint32_t clock_mon_selftest_fail:1; //Fail of clock monitor selftest
			uint32_t unused_1:1; //Unused
			uint32_t xcheck_sc_conv_fail:1; //Fail of xcheck between SC0 and SC1 conversion
			uint32_t xcheck_csa_selftest_end:1; //Xcheck CSA selftest is completed
			uint32_t xcheck_csa_selftest_fail:1; //Fail of xcheck CSA selftest
			uint32_t xcheck_adc_inst_cc_end:1; //Xcheck betwenn CSA 0 and CSA 1 conversion is completed
			uint32_t xcheck_adc_inst_cc_fail:1; //Fail of xcheck between CSA0 and CSA1 conversion
		} bitfields;
	} DIAG_STATUS2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:13; //Unused
			uint32_t nvm_verify_err:1; //OR between erase verify and program verify error for NVM upload procedure
			uint32_t nvm_ready:1; //It indicates when NVM is ready (no operation)
			uint32_t gsw_cyc:1; //GSW latched at chekpoint of cyclic routine
			uint32_t timeout_fsm_cyclic:1; //It occured a timeout for cyclic routine
			uint32_t cyc_routine_busy:1; //Cyclic routine busy
		} bitfields;
	} DIAG_STATUS3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //Unused
			uint32_t fltin_time_out:1; //It is latched when the TFLTIN_TIMEOUT timeout expires
			uint32_t fltin_det:1; //FLTIN is detected low for longer than TFLTIN_DEGLITCH
			uint32_t sc1_dchg:1; //Fail of short circuit in discharge for SC1
			uint32_t sc0_dchg:1; //Fail of short circuit in discharge for SC0
			uint32_t csa1_open_busy:1; //Open load diagnostic on CSA1 is running
			uint32_t csa0_open_busy:1; //Open load diagnostic on CSA0 is running
			uint32_t csa1_open:1; //Fail of open load for CSA1
			uint32_t csa0_open:1; //Fail of open load for CSA0
			uint32_t ovc_chg_1:1; //Fail of overcurrent in charge for CSA1
			uint32_t ovc_dchg_1:1; //Fail of overcurrent in discharge for CSA1
			uint32_t ovc_chg_0:1; //Fail of overcurrent in charge for CSA0
			uint32_t ovc_dchg_0:1; //Fail of overcurrent in discharge for CSA0
			uint32_t data_ready_csa_inst:1; //Data valid of CSA0
		} bitfields;
	} DIAG_CSA_SC;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:11; //Unused
			uint32_t xcheck_cc_data_valid_fail:1; //Mismatch cc sample counter between CC and redundant logic
			uint32_t xcheck_cc_data_fail:1; //Mismatch cc accumulation value between CC and redundant logic
			uint32_t v5v_oc_ot:1; //V5V over current and over temperature
			uint32_t xcheck_pls_wakeup_fail:1; //Mismatch wakeup pls between CC and redundant logic
			uint32_t cc_wup:1; //Charge/discharge detection wakeup (device has been wakeup from stby by CC)
			uint32_t cc_sat:1; //Error of sample counter saturation
			uint32_t por_sleep_asserted:1; //1 -> POR_SLEEP_N assertion occured between this reading and previous one on this register
		} bitfields;
	} DIAG_STATUS_STBY;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:13; //Unused
			uint32_t vif_id_err:1; //Communication wrong VIF ID error (see spec fo the list of fault cases handled by this bit)
			uint32_t comm_crc_err:1; //Communication wrong CRC error (previous MOSI was corrupted and it had a wrong CRC)
			uint32_t wrong_addr:1; //Communication wrong address error (previous MOSI was specifying an inexistent address)
			uint32_t short_frame:1; //Communication short frame error (previous MOSI was shorter than 40 bit)
			uint32_t long_frame:1; //Communication long frame error (previous MOSI was longer than 40 bit)
		} bitfields;
	} COMM_ERR;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //Unused
			uint32_t spare_out:5; //RESERVED BIT
			uint32_t spare_in:5; //RESERVED BIT
		} bitfields;
	} SPARE;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:15; //Unused
			uint32_t input_short_enable:1; //RESERVED BIT
			uint32_t csa1_input_short:1; //RESERVED BIT
			uint32_t csa0_input_short:1; //RESERVED BIT
		} bitfields;
	} CSA_INPUT_SHORT;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data0:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data1:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data2:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data3:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data4:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA4;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //Unused
			uint32_t customer_data5:16; //NVM bits dedicated for customer
		} bitfields;
	} CUSTOMER_DATA5;

};

#define L9965C_REGMAP_CHIPID_ADDR 0x0
#define L9965C_REGMAP_VIF_ID_CFG_ADDR 0x01
#define L9965C_REGMAP_DEV_GEN_CFG_1_ADDR 0x02
#define L9965C_REGMAP_DEV_GEN_CFG_2_ADDR 0x03
#define L9965C_REGMAP_CFG_DIAG_ADDR 0x04
#define L9965C_REGMAP_CFG_GPIO_ADDR 0x05
#define L9965C_REGMAP_SC_SET_CFG_ADDR 0x06
#define L9965C_REGMAP_GATE_PRDRV_PD_0_TO_7_ADDR 0x07
#define L9965C_REGMAP_GATE_PRDRV_PD_8_TO_9_ADDR 0x08
#define L9965C_REGMAP_CSA_OVC_TH_ADDR 0x09
#define L9965C_REGMAP_CFG_FOR_STBY_LOGIC_ADDR 0x0A
#define L9965C_REGMAP_SPECIAL_REG_ADDR 0x1A
#define L9965C_REGMAP_CMD1_ADDR 0x1B
#define L9965C_REGMAP_CMD2_ADDR 0x1C
#define L9965C_REGMAP_GENERAL_REG_ADDR 0x1D
#define L9965C_REGMAP_SPI_VIF_CT_ADDR 0x1E
#define L9965C_REGMAP_SPI_MASTER_ADDR 0x1F
#define L9965C_REGMAP_SPI_MOSI_39_32_ADDR 0x20
#define L9965C_REGMAP_SPI_MOSI_31_16_ADDR 0x21
#define L9965C_REGMAP_SPI_MOSI_15_0_ADDR 0x22
#define L9965C_REGMAP_SPI_MISO_39_32_ADDR 0x23
#define L9965C_REGMAP_SPI_MISO_31_16_ADDR 0x24
#define L9965C_REGMAP_SPI_MISO_15_0_ADDR 0x25
#define L9965C_REGMAP_I2C_MASTER_ADDR 0x26
#define L9965C_REGMAP_I2C_TX_BYTE_0_1_ADDR 0x27
#define L9965C_REGMAP_I2C_TX_BYTE_2_3_ADDR 0x28
#define L9965C_REGMAP_I2C_RX_BYTE_0_1_ADDR 0x29
#define L9965C_REGMAP_I2C_RX_BYTE_2_3_ADDR 0x2A
#define L9965C_REGMAP_CFG_CSA_INST_ADDR 0x2B
#define L9965C_REGMAP_FAULT_CFG_ADDR 0x2C
#define L9965C_REGMAP_FLTIN_CFG_ADDR 0x2D
#define L9965C_REGMAP_CWUP_CFG_ADDR 0x2E
#define L9965C_REGMAP_CWUP_CFG_TIM_TH_ADDR 0x2F
#define L9965C_REGMAP_GATE_PRDRV_EN_ADDR 0x30
#define L9965C_REGMAP_GATE_CMD_ADDR 0x31
#define L9965C_REGMAP_AIN_CMD_CFG_ADDR 0x32
#define L9965C_REGMAP_GPO_CMD_ADDR 0x33
#define L9965C_REGMAP_GPI_READ_ADDR 0x34
#define L9965C_REGMAP_DC_LINK_CFG_0_ADDR 0x35
#define L9965C_REGMAP_DC_LINK_CFG_1_ADDR 0x36
#define L9965C_REGMAP_CSA_INST_MEAS_ADDR 0x37
#define L9965C_REGMAP_CUR_CC_MSB_ADDR 0x38
#define L9965C_REGMAP_CUR_CC_LSB_CNT_ADDR 0x39
#define L9965C_REGMAP_AIN_MEAS_ADDR 0x3A
#define L9965C_REGMAP_DIE_TEMP_MEAS_ADDR 0x3B
#define L9965C_REGMAP_DIAG_STATUS1_ADDR 0x3C
#define L9965C_REGMAP_DIAG_STATUS2_ADDR 0x3D
#define L9965C_REGMAP_DIAG_STATUS3_ADDR 0x3E
#define L9965C_REGMAP_DIAG_CSA_SC_ADDR 0x3F
#define L9965C_REGMAP_DIAG_STATUS_STBY_ADDR 0x40
#define L9965C_REGMAP_COMM_ERR_ADDR 0x41
#define L9965C_REGMAP_SPARE_ADDR 0x42
#define L9965C_REGMAP_CSA_INPUT_SHORT_ADDR 0x43
#define L9965C_REGMAP_CUSTOMER_DATA0_ADDR 0x44
#define L9965C_REGMAP_CUSTOMER_DATA1_ADDR 0x45
#define L9965C_REGMAP_CUSTOMER_DATA2_ADDR 0x46
#define L9965C_REGMAP_CUSTOMER_DATA3_ADDR 0x47
#define L9965C_REGMAP_CUSTOMER_DATA4_ADDR 0x48
#define L9965C_REGMAP_CUSTOMER_DATA5_ADDR 0x49
#endif
