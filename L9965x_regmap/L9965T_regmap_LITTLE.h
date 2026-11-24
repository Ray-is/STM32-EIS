#ifndef __L9965T_REGMAP_H
#define __L9965T_REGMAP_H
/******************************************************************************/
/*                           Module: L9965T_REGMAP                              */
/*      All fields declared are unsigned! Please cast them as convenient      */
/******************************************************************************/
struct L9965T_REGMAP_STRUCTURE
{
	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t name_id:8; //For UR1T -> DevName = x17
			uint32_t silicon_id:3; //Silicon version identification
			uint32_t metal_id:5; //Metal layer version identification
		} bitfields;
	} CHIPID;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:12;
			uint32_t vif_id:6; //It identifies the device address
		} bitfields;
	} VIF_ID_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused_2:3;
			uint32_t nvm_uploads_count:5; //It is the number of uploads already done
			uint32_t unused_1:5;
			uint32_t broadcast_sel_1:2; //Mailbox configuration see spec for details
			uint32_t broadcast_sel_2:2; //Mailbox configuration see spec for details
			uint32_t unused_0:1;
		} bitfields;
	} GEN_CFG1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused_1:15;
			uint32_t wkp_dis:1; //WKP pin assertion disabled: 0 -> WKP pin is asserted when device is in NORMAL; 1-> WKP pin is not asserted when device is in NORMAL.
			uint32_t unused_0:1;
			uint32_t msk_iso_err:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
		} bitfields;
	} GEN_CFG2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t msk_vb_uv:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_v3v3_int_ov:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_v5v_ov:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_v5v_uv:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_v5v_oc:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_tsd:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_wkp_ot:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_gnd_loss:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_bist_ana_fail:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_bist_osc_fail:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_osc_fail:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_flt_err:1; //Masking redirection of fault to GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_wkp_err:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_bne_err:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_fifo_rx_full:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
			uint32_t msk_fifo_tx_full:1; //Masking redirection of fault to FLT pin and GSW bit: 0 -> not masked; 1 -> masked
		} bitfields;
	} GEN_CFG3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused_1:11;
			uint32_t en_gnd_loss:1; //Enabling ground loss diagnostic: 0 -> disabled; 1 -> enabled
			uint32_t unused_0:6; //RESERVED BIT TO BE KEPT AT RESET VALUE: set speed mode for analog cell of GPIO
		} bitfields;
	} GEN_CFG4;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t por_sleep_asserted:1; //1 -> POR_SLEEP_N assertion occured between this reading and previous one on this register
			uint32_t bist_ana_enb:1; //Bist command for VB_UV, V3V_INT_OV, V5V_OV, V5V_UV analog comparators
			uint32_t wkp_set:1; //WKP pin assertion enabled: 1 -> WKP pin is asserted when device is in NORMAL.
			uint32_t iso_rx_timeout_enb:1; //Enabling of waiting time for ISO_RX state begin and ISO_RX state end. See spec for details. 0 -> timeout disabled; 1-> timeout enabled
			uint32_t spare_main_1:1; //Spare bit
			uint32_t spare_main_0:1; //Spare bit
			uint32_t spare_sleep_1:1; //Spare bit
			uint32_t spare_sleep_0:1; //Spare bit
			uint32_t wakeup_cyclic_timeout_listener_sel:3; //Listener timeout duration: see specs for details
			uint32_t wakeup_cyclic_timeout_sender_sel:3; //Sender timeout duration: see specs for details
			uint32_t wakeup_cyclic_listener:1; //Listener configurarion enabling: 1 -> transceiver configured as listener in double transceiver CYCLIC WAKUP function
			uint32_t wakeup_cyclic_sender:1; //Sender configurarion enabling: 1 -> transceiver configured as sender in double transceiver CYCLIC WAKEUP function
			uint32_t wakeup_cyclic_enb:1; //CYCLIC WAKEUP function enabling: 0 -> not enabled; 1-> enabled
			uint32_t wakeup_cyclic_end:1; //1 -> the CYCLIC WAKEUP diagnosis phase has reached the maximum duration.
		} bitfields;
	} GEN_CFG5;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1;
			uint32_t vb_uv:1; //1 -> VB undervoltage detected in NORMAL
			uint32_t v3v3_int_ov:1; //1 -> V3V3_INT overvoltage detected in NORMAL / CYCLIC_WAKEUP
			uint32_t v5v_ov:1; //1 -> V5V overvoltage detected in NORMAL / CYCLIC_WAKEUP
			uint32_t v5v_uv:1; //1 -> V5V undervoltage detected in NORMAL / CYCLIC_WAKEUP
			uint32_t v5v_ot:1; //1 -> V5V overtemperature detected in NORMAL / CYCLIC_WAKEUP
			uint32_t wkp_ot:1; //1 -> WKP pin overtemperature detected in NORMAL
			uint32_t gnd_loss:1; //1 -> Ground loss if enabled detected in NORMAL / CYCLIC_WAKEUP
			uint32_t trim_cyc_crc_fail:1; //1 -> fail of cyclic CRC check for trimming bits detected in NORMAL
			uint32_t conf_cyc_crc_fail:1; //1 -> fail of cyclic CRC check for configuration bits detected in NORMAL
			uint32_t osc_fail:1; //1 -> main and sleep oscillators frequency mismatch over threshold detected in NORMAL / CYCLIC_WAKEUP
			uint32_t flt_err:1; //1 -> FLT pin short detected in NORMAL
			uint32_t wkp_err:1; //1 -> WKP pin short detected in NORMAL
			uint32_t bne_err:1; //1 -> BNE pin short detected in NORMAL
			uint32_t iso_err:1; //1 -> Error detected in ISO data comunication detected in NORMAL
			uint32_t fifo_rx_empty:1; //1 -> read request to empty FIFO RX detected in NORMAL
			uint32_t fifo_rx_full:1; //1 -> write request to full FIFO RX detected in NORMAL
			uint32_t fifo_tx_full:1; //1 -> overwriting of last command from MICRO to be sent to ISO with new command detected in NORMAL
		} bitfields;
	} GEN_STATUS1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t wakeup_cyclic_trx_timeout:1; //1 -> the listener transceiver has not received the CYCLIC WAKEUP tone within the listener timeout detected in CYCLIC COUNT
			uint32_t wakeup_cyclic_trx_sender:1; //1-> transceiver is in sender status
			uint32_t wakeup_cyclic_trx_listener:1; //1 -> transceiver is in listener status
			uint32_t wakeup_cyclic_trx_counter:12; //Counter value for CYCLIC_COUNT phase. See spec for details.
			uint32_t wakeup_cyclic_vif:1; //1 -> detection of short tone from VIF
			uint32_t wakeup_fault_vif:1; //1 -> detection of long tone from VIF
			uint32_t wakeup_fault_spi:1; //1 -> detection of wakeup from SPI
		} bitfields;
	} GEN_STATUS2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t v5v_oc:1; //1 -> V5V overcurrent deteced in NORMAL / CYCLIC_WAKEUP
			uint32_t tsd:1; //1 -> device overtemperature detected in NORMAL / CYCLIC_WAKEUP
			uint32_t wkp_status:1; //1 -> the WKP pin is at high level
			uint32_t bne:1; //1 -> the BNE pin is at high level
			uint32_t bist_ana_done:1; //1 -> Analog comparators bist done
			uint32_t bist_ana_fail:1; //1 -> fail in the analog comparators bist NORMAL (VB_UV, V3V_INT_OV, V5V_OV, V5V_UV) CYCLIC_WAKEUP (V3V_INT_OV, V5V_OV, V5V_UV, GND_LOSS)
			uint32_t unused_1:1;
			uint32_t bist_osc_fail:1; //1 -> Clock monitor bist fail detected in NORMAL / CYCLIC_WAKEUP
			uint32_t trim_nvm_crc_fail:1; //1 -> fail of check at NVM download  for trimming bits detected in NORMAL / CYCLIC_WAKEUP
			uint32_t conf_nvm_crc_fail:1; //1 -> fail of check at NVM download for configuration bits detected in NORMAL / CYCLIC_WAKEUP
			uint32_t fifo_rx_add:6; //Number of words not read in FIFO
			uint32_t iso_idle:1; //1 -> Isolated line of VIF is in IDLE state
			uint32_t unused_0:1;
		} bitfields;
	} GEN_STATUS3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10;
			uint32_t special_key:8; //GO2SLEEP : hCC SW_RST_1 : hE1 SW_RST_2 : h1E UNLOCK_1 : h55 UNLOCK_2 : h33 LOCK : hAA
		} bitfields;
	} SPECIAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:17;
			uint32_t echo_soc:1; //address placeholder for start of convertion command
		} bitfields;
	} ECHO_SOC;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10;
			uint32_t cmd_trx:8; //WAKEUP_FAULT_TRX : hAE command to transceiver to wakeup devices in chain FIFO_RX_CLEAR : hDC command to transceiver to clear FIFO_RX FIFO_RX_READ : hB5 command to transceiver to read FIFO_RX
		} bitfields;
	} CMD_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused_1:7;
			uint32_t nvm_ready:1;
			uint32_t nvm_verify_err:1; //1 -> NVM erase verify error or NVM program verify error at NVM upload procedure
			uint32_t unused_0:3;
			uint32_t iso_tx_en:1; //1 -> to enable ISO transmitter in NORMAL
			uint32_t nvm_crc_fail_msk:1; //1 -> disable CRC check at NVM download of trimming and configuration bits
			uint32_t cyc_crc_dis:1; //1 -> disable CRC cyclic check of trimming and configuration bits
			uint32_t nvm_op_cmd:3; //NVM operation: 101 = download, 011 = upload
		} bitfields;
	} GENERAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:13;
			uint32_t spi_vif_id_err:1; //Communication wrong VIF ID error (see spec fo the list of fault cases handled by this bit)
			uint32_t spi_comm_crc_err:1; //Communication wrong CRC error (previous MOSI was corrupted and it had a wrong CRC)
			uint32_t spi_wrong_addr:1; //Communication wrong address error (previous MOSI was specifying an inexistent address)
			uint32_t spi_short_frame:1; //Communication short frame error (previous MOSI was shorter than 40 bit)
			uint32_t spi_long_frame:1; //Communication long frame error (previous MOSI was longer than 40 bit)
		} bitfields;
	} COMM_ERR_SPI;

};

#define L9965T_REGMAP_CHIPID_ADDR 0x0
#define L9965T_REGMAP_VIF_ID_CFG_ADDR 0x1
#define L9965T_REGMAP_GEN_CFG1_ADDR 0x2
#define L9965T_REGMAP_GEN_CFG2_ADDR 0x3
#define L9965T_REGMAP_GEN_CFG3_ADDR 0x4
#define L9965T_REGMAP_GEN_CFG4_ADDR 0x6
#define L9965T_REGMAP_GEN_CFG5_ADDR 0x7
#define L9965T_REGMAP_GEN_STATUS1_ADDR 0x8
#define L9965T_REGMAP_GEN_STATUS2_ADDR 0x9
#define L9965T_REGMAP_GEN_STATUS3_ADDR 0xA
#define L9965T_REGMAP_SPECIAL_REG_ADDR 0x1A
#define L9965T_REGMAP_ECHO_SOC_ADDR 0x1B
#define L9965T_REGMAP_CMD_REG_ADDR 0x1C
#define L9965T_REGMAP_GENERAL_REG_ADDR 0x1D
#define L9965T_REGMAP_COMM_ERR_SPI_ADDR 0x41
#endif
