#ifndef __L9965A_REGMAP_H
#define __L9965A_REGMAP_H
/******************************************************************************/
/*                           Module: L9965A_REGMAP                              */
/*      All fields declared are unsigned! Please cast them as convenient      */
/******************************************************************************/
struct L9965A_REGMAP_STRUCTURE
{
	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t name_id:8; //0x1A for L9965A device
			uint32_t silicon_id:3; //Silicon Version NA= 000, A = 001, B = 010, C = 011  D = 100, E = 101, F = 110, G = 111
			uint32_t metal_id:5; //Metal Version NA= 00000, A = 00001, B = 00010, C = 00011  D = 00100, E = 00101, F = 00110, G = 00111
		} bitfields;
	} CHIPID;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:12; //-
			uint32_t vif_id:6; //Broadcast 0x00
		} bitfields;
	} VIF_ID;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:3; //-
			uint32_t nvm_uploads_count:5; //Number of writings performed
			uint32_t unused1:2; //-
			uint32_t comm_tim_en:1; //Communication timeout feauture enable
			uint32_t comm_tim_th:2; //Communication timeout threshold: 00: 100ms - 01: 500ms - 10: 1s - 11: 2s
			uint32_t broadcast_sel_1:2; //Mailbox configuration see spec section 4.11.2.5 for details
			uint32_t broadcast_sel_2:2; //Mailbox configuration see spec section 4.11.2.5 for details
			uint32_t unused2:1; //-
		} bitfields;
	} DEV_GEN_CFG_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:9; //-
			uint32_t gpio0_ncs0_active_idle:1; //0: GPIO0_NCS0 is in HiZ when it is not used if SPI MASTER mode has been selected 1: GPIO0_NCS0 is kept to 1 when it is not used if SPI MASTER mode has been selected
			uint32_t gpio1_ncs1_active_idle:1; //0: GPIO1_NCS1 is in HiZ when it is not used if SPI MASTER mode has been selected 1: GPIO1_NCS1 is kept to 1 when it is not used if SPI MASTER mode has been selected
			uint32_t gpio1_ncs1_en:1; //program to use the GPIO1_NCS1 pin as Chip Select master
			uint32_t i2c_en:1; //program to enable I2C if. GPIO5_SDA and GPIO6_SCL are automatically configured as open drain
			uint32_t i2c_master_clk:1; //0: I2C Master Clock Frequency 62.5kHz 1: I2C Master Clock Frequency 250kHz
			uint32_t spi_master_cpha1:1; //CPHA configuration applied to GPIO1_NCS1
			uint32_t spi_master_cpha0:1; //CPHA configuration applied to GPIO0_NCS0
			uint32_t spi_master_cpol1:1; //CPOL configuration applied to GPIO1_NCS1
			uint32_t spi_master_cpol0:1; //CPOL configuration applied to GPIO0_NCS0
		} bitfields;
	} DEV_GEN_CFG_2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_en:1; //enable to convert and make diagnostic on CELL 18
			uint32_t vcell17_en:1; //enable to convert and make diagnostic on CELL 17
			uint32_t vcell16_en:1; //enable to convert and make diagnostic on CELL 16
			uint32_t vcell15_en:1; //enable to convert and make diagnostic on CELL 15
			uint32_t vcell14_en:1; //enable to convert and make diagnostic on CELL 14
			uint32_t vcell13_en:1; //enable to convert and make diagnostic on CELL 13
			uint32_t vcell12_en:1; //enable to convert and make diagnostic on CELL 12
			uint32_t vcell11_en:1; //enable to convert and make diagnostic on CELL 11
			uint32_t vcell10_en:1; //enable to convert and make diagnostic on CELL 10
			uint32_t vcell9_en:1; //enable to convert and make diagnostic on CELL 9
			uint32_t vcell8_en:1; //enable to convert and make diagnostic on CELL 8
			uint32_t vcell7_en:1; //enable to convert and make diagnostic on CELL 7
			uint32_t vcell6_en:1; //enable to convert and make diagnostic on CELL 6
			uint32_t vcell5_en:1; //enable to convert and make diagnostic on CELL 5
			uint32_t vcell4_en:1; //enable to convert and make diagnostic on CELL 4
			uint32_t vcell3_en:1; //enable to convert and make diagnostic on CELL 3
			uint32_t vcell2_en:1; //enable to convert and make diagnostic on CELL 2
			uint32_t vcell1_en:1; //enable to convert and make diagnostic on CELL 1
		} bitfields;
	} VCELL_EN;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_bb:1; //set to 1 if there is a BB connected on CELL 18
			uint32_t vcell17_bb:1; //set to 1 if there is a BB connected on CELL 17
			uint32_t vcell16_bb:1; //set to 1 if there is a BB connected on CELL 16
			uint32_t vcell15_bb:1; //set to 1 if there is a BB connected on CELL 15
			uint32_t vcell14_bb:1; //set to 1 if there is a BB connected on CELL 14
			uint32_t vcell13_bb:1; //set to 1 if there is a BB connected on CELL 13
			uint32_t vcell12_bb:1; //set to 1 if there is a BB connected on CELL 12
			uint32_t vcell11_bb:1; //set to 1 if there is a BB connected on CELL 11
			uint32_t vcell10_bb:1; //set to 1 if there is a BB connected on CELL 10
			uint32_t vcell9_bb:1; //set to 1 if there is a BB connected on CELL 9
			uint32_t vcell8_bb:1; //set to 1 if there is a BB connected on CELL 8
			uint32_t vcell7_bb:1; //set to 1 if there is a BB connected on CELL 7
			uint32_t vcell6_bb:1; //set to 1 if there is a BB connected on CELL 6
			uint32_t vcell5_bb:1; //set to 1 if there is a BB connected on CELL 5
			uint32_t vcell4_bb:1; //set to 1 if there is a BB connected on CELL 4
			uint32_t vcell3_bb:1; //set to 1 if there is a BB connected on CELL 3
			uint32_t vcell2_bb:1; //set to 1 if there is a BB connected on CELL 2
			uint32_t vcell1_bb:1; //set to 1 if there is a BB connected on CELL 1
		} bitfields;
	} VCELL_BB;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t cell_uv_th:9; //Vcell_uv_th = 64*Vcell_res*CELL_UV_TH
			uint32_t cell_ov_th:9; //Vcell_ov_th = 64*Vcell_res*CELL_OV_TH+Vcell_uv_th
		} bitfields;
	} CELL_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:11; //-
			uint32_t bal_oc_bal_msk:1; //Masks BAL_OC reaction on balancing pins (Sx) --> this configuration will be kept in DEEP SLEEP and SILENT BALANCING states
			uint32_t tj_sd_bal_msk:1; //Masks TJ_SD reaction on balancing pins (Sx)
			uint32_t vbs_uv_bal_msk:1; //Masks VBS_UV reaction on balancing pins (Sx)
			uint32_t sum_uv_bal_msk:1; //Masks SUM_UV reaction on balancing pins (Sx)
			uint32_t bal_uv_bal_msk:1; //Masks BAL_UV reaction on balancing pins (Sx)
			uint32_t cell_uv_bal_msk:1; //Masks CELL_UV reaction on balancing pins (Sx)
			uint32_t vcp_uv_bal_msk:1; //Masks VCP_UV reaction on balancing pins (Sx)
		} bitfields;
	} MSK_FLT_CELL_INDEX;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t sum_uv_th:9; //Vsum_uv_th = 2048*Vcell_res*SUM_UV_TH
			uint32_t sum_ov_th:9; //Vsum_ov_th =  512*Vcell_res*SUM_OV_TH+Vsum_uv_th
		} bitfields;
	} SUM_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t vbs_ov_th:8; //Vvbs_ov_th = 128*Vbatt_res*VBS_OV_TH+Vvbs_uv_th
			uint32_t vbs_uv_th:8; //Vvbs_uv_th = 128*Vbatt_res*VBS_UV_TH
		} bitfields;
	} VBS_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t bb_ov_th:7; //Vbb_ov_th = 128*Vbb_res*BB_OV_TH
			uint32_t vbs_sum_th:4; //Vvbs_sum_th = 32*Vbatt_res*VBS_SUM_TH
			uint32_t unused0:1; //-
			uint32_t bb_add:1; //see spec section 4.4.2 for details
			uint32_t bb_en:1; //program if busbar pair (BBP - BBM) is used. See spec section 4.4.2 for details
			uint32_t vbs_en:1; //see spec section 4.4.3 1for details
			uint32_t tvolt_fil_wakeup:3; //Filter conversion applied during VOLT_CONV step execution in CYCLIC WAKEUP 000: 136 us 001: 264 us 010: 1.04 ms 011: 2.08 ms 100: 4.16 ms 101: 8.32 ms 110: 18.64 ms 111: 99.864 ms
		} bitfields;
	} VBS_BB_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t delta_vcx_th:4; //DeltaVcx_th0 = 8*Vcell_res*DELTA_VCX_TH DeltaVcx_th1 = 256*Vcell_res*DELTA_VCX_TH
			uint32_t cx_open_th:4; //Vc_open_th = 2048*Vcell_res*CX_OPEN_TH
			uint32_t bal_uv_th:9; //Vbal_uv_th = 64*Vcell_res*BAL_UV_TH+Vcell_uv_th
		} bitfields;
	} OTHER1_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:3; //-
			uint32_t gpio4_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio4_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio3_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio3_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio2_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio2_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio1_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio1_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio0_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio0_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
		} bitfields;
	} GPIO_CONF_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:3; //-
			uint32_t gpio9_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio9_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio8_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio8_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio7_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio7_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio6_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio6_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
			uint32_t gpio5_pu_pd:1; //0 (default) weak pulldown - 1 weak pullup
			uint32_t gpio5_conf:2; //00 (default) ADC input (absolute) 01 ADC input (ratiometric) 10 Generic Digital input 11 Generic Digital output
		} bitfields;
	} GPIO_CONF_2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //-
			uint32_t ntc_fastchg_ot_th:5; //Vntc_fastchg_ot_th = 128*Vntc_res*NTC_FASTCHG_OT_TH+Vntc_ot_th
			uint32_t ntc_th_hys:4; //Vntc_ot_hys = 128*Vntc_res*NTC_TH_HYS
			uint32_t delta_vntc_th:4; //DeltaVntc_th_0 = 128*Vntc_res*DELTA_VNTC_TH DeltaVntc_th_1 = 128*Vntc_res*DELTA_VNTC_TH
		} bitfields;
	} NTC_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc0_delta_msk:1; //Masks execution of NTC0 delta (in normal and in cyclic) diagnostic
			uint32_t ntc0_ot_bal_msk:1; //Masks NTC0_OT reaction on balancing pins (Sx)
			uint32_t ntc0_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC0_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC0_OT_TH
			uint32_t ntc0_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC0_UT_TH
		} bitfields;
	} NTC0_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc1_delta_msk:1; //Masks execution of NTC1 delta (in normal and in cyclic) diagnostic
			uint32_t ntc1_ot_bal_msk:1; //Masks NTC1_OT reaction on balancing pins (Sx)
			uint32_t ntc1_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC1_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC1_OT_TH
			uint32_t ntc1_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC1_UT_TH
		} bitfields;
	} NTC1_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc2_delta_msk:1; //Masks execution of NTC2 delta (in normal and in cyclic) diagnostic
			uint32_t ntc2_ot_bal_msk:1; //Masks NTC2_OT reaction on balancing pins (Sx)
			uint32_t ntc2_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC2_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC2_OT_TH
			uint32_t ntc2_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC2_UT_TH
		} bitfields;
	} NTC2_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc3_delta_msk:1; //Masks execution of NTC3 delta (in normal and in cyclic) diagnostic
			uint32_t ntc3_ot_bal_msk:1; //Masks NTC3_OT reaction on balancing pins (Sx)
			uint32_t ntc3_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC3_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC3_OT_TH
			uint32_t ntc3_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC3_UT_TH
		} bitfields;
	} NTC3_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc4_delta_msk:1; //Masks execution of NTC4 delta (in normal and in cyclic) diagnostic
			uint32_t ntc4_ot_bal_msk:1; //Masks NTC4_OT reaction on balancing pins (Sx)
			uint32_t ntc4_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC4_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC4_OT_TH
			uint32_t ntc4_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC4_UT_TH
		} bitfields;
	} NTC4_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc5_delta_msk:1; //Masks execution of NTC5 delta (in normal and in cyclic) diagnostic
			uint32_t ntc5_ot_bal_msk:1; //Masks NTC5_OT reaction on balancing pins (Sx)
			uint32_t ntc5_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC5_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC5_OT_TH
			uint32_t ntc5_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC5_UT_TH
		} bitfields;
	} NTC5_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc6_delta_msk:1; //Masks execution of NTC6 delta (in normal and in cyclic) diagnostic
			uint32_t ntc6_ot_bal_msk:1; //Masks NTC6_OT reaction on balancing pins (Sx)
			uint32_t ntc6_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC6_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC6_OT_TH
			uint32_t ntc6_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC6_UT_TH
		} bitfields;
	} NTC6_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc7_delta_msk:1; //Masks execution of NTC7 delta (in normal and in cyclic) diagnostic
			uint32_t ntc7_ot_bal_msk:1; //Masks NTC7_OT reaction on balancing pins (Sx)
			uint32_t ntc7_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC7_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC7_OT_TH
			uint32_t ntc7_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC7_UT_TH
		} bitfields;
	} NTC7_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc8_delta_msk:1; //Masks execution of NTC8 delta (in normal and in cyclic) diagnostic
			uint32_t ntc8_ot_bal_msk:1; //Masks NTC8_OT reaction on balancing pins (Sx)
			uint32_t ntc8_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC8_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC8_OT_TH
			uint32_t ntc8_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC8_UT_TH
		} bitfields;
	} NTC8_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t ntc9_delta_msk:1; //Masks execution of NTC9 delta (in normal and in cyclic) diagnostic
			uint32_t ntc9_ot_bal_msk:1; //Masks NTC9_OT reaction on balancing pins (Sx)
			uint32_t ntc9_ot_th:8; //Vntc_ot_th = 32*Vntc_res*NTC9_OT_TH Vgpio_uv_th = 128*Vgpio_res*NTC9_OT_TH
			uint32_t ntc9_ut_th:8; //Vntc_ut_th = 128*Vntc_res*NTC9_UT_TH
		} bitfields;
	} NTC9_UT_OT_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t bal_cooldown_en9:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en8:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en7:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en6:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en5:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en4:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en3:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en2:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en1:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
			uint32_t bal_cooldown_en0:1; //1: if GPIOx voltage rises above VNTCx_OT_TH +  VNTCx_OT_HYS the NTCx_OT flag can be cleared by MCU 0: if GPIOx voltage rises above VNTCx_OT_TH the NTCx_OT flag can be cleared by MCU
		} bitfields;
	} BAL_COOLDOWN_EN;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //-
			uint32_t special_key:8; //Configuration lock/unlock: 0x55 - partial unlock 0x33 - unlock confirmation 0xAA - lock SW RST: 0xE1 - software reset GO2SLP: 0xCC - go to sleep command
		} bitfields;
	} SPECIAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:6; //-
			uint32_t bist_fault_inj:2; //00: no fault injection applied 01: ADC bist fault injection and cyclic delta comparator fault injection applied during BIST step if BIST = 1 10: Analog BIST fault injection applied during BIST step if BIST = 1 11: all fault injection applied during BIST step  if BIST = 1
			uint32_t bist:1; //set to 1 to perferm BIST step
			uint32_t adc_swap:1; //set to 1 to perform ADC SWAP for next conversion
			uint32_t gain_adj:1; //set to 1 to perform gain adjustment only if BIST has been set to 1
			uint32_t abs_conv:1; //set to 1 to enable conversion of GPIOs configured as ABSOLUT
			uint32_t ratio_conv:1; //set to 1 to enable conversion of GPIOs configured as RATIOMETRIC
			uint32_t temp_open:1; //set to 1 to perform OPEN DIAGNOSTIC of all GPIOs enabled and configured as ABSOLUT or RATIOMETRIC
			uint32_t temp_conv:1; //set to 1 to perform CONVERSION of all GPIOs enabled and configured as ABSOLUT or RATIOMETRIC
			uint32_t volt_open:1; //set to 1 to perform OPEN DIAGNOSTIC of all CELLs enabled
			uint32_t volt_conv:1; //set to 1 to perform CONVERSION of all CELLs enabled
			uint32_t soc:1; //START OF CONVERSION request
		} bitfields;
	} VOLT_CONV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:13;
			uint32_t vadc_gain_int_fault_inj:1; //set to 1 to trigger a failure in the gain correction
			uint32_t vadc_temp_int_fault_inj:1; //set to 1 to trigger a failure in the temperature calibration ADC
			uint32_t tvolt_fil:3; //Filter conversion applied during VOLT_CONV step execution in NORMAL 000: 136 us 001: 264 us 010: 1.04 ms 011: 2.08 ms 100: 4.16 ms 101: 8.32 ms 110: 18.64 ms 111: 99.864 ms
		} bitfields;
	} VOLT_CONV_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:9;
			uint32_t ram_ecc_fail_msk:1; //dedicated masks for ram ecc check
			uint32_t bidi_answ:1; //BIDI_ANSW = 1 (default) the IC generates bi-directional answers on both ISOH and ISOL ports BIDI_ANSW = 0 the IC answers using the same ISO port that received the command
			uint32_t isoh_tx_en:1; //set to 1 (default) to enable TX to ISOH port - see spec section 4.11.2.5 for more details regardless Addresing Procedure
			uint32_t isol_tx_en:1; //set to 1 (default) to enable TX to ISOL port
			uint32_t nvm_crc_fail_msk:1; //In case of CRC error at NVM download it is possible to set this bit and retriggher a NVM download to force corrupted NVM content download on SFTY regs instead of 0.
			uint32_t cyc_cfg_crc_dis:1; //disable cyclic crc check and ram ecc check
			uint32_t nvm_op_cmd:3; //011: triggers the NVM upload and refresh 101: triggers the NVM refresh
		} bitfields;
	} GENERAL_REG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:14; //-
			uint32_t reserved:1; //-
			uint32_t comm_tim:1; //Communication Timeout Flag status
			uint32_t spi_mode:2; //only writable via VIF 00: SPI Slave 01,10: SPI Disable 11: SPI Master
		} bitfields;
	} SPI_MODE_COMM_TIM;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t spi_master_busy:1; //Indicates that a SPI master communication is running
			uint32_t spi_frame_size1:3; //selector for SPI master frame size sent using GPIO1_NCS1: 000: 8 bit, 001: 16 bit, 010: 24 bit, 011: 32 bit, 100 to 111: 40 bit
			uint32_t spi_frame_size0:3; //selector for SPI master frame size sent using GPIO0_NCS0 000: 8 bit, 001: 16 bit, 010: 24 bit, 011: 32 bit, 100 to 111: 40 bit
			uint32_t spi_ncs1:1; //set to 1 to use GPIO1_NCS1 as SPI master chip select
			uint32_t spi_ncs0:1; //set to 1 to use GPIO10_NCS0 as SPI master chip select
			uint32_t spi_transfer:1; //set to 1 to trigger SPI frame transfer
		} bitfields;
	} SPI_MASTER;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10; //-
			uint32_t mosi_39_32:8; //SPI master MOSI byte 5
		} bitfields;
	} GPIO_SPI_MOSI_BYTE_5;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t mosi_31_24:8; //SPI master MOSI byte 4
			uint32_t mosi_23_16:8; //SPI master MOSI byte 3
		} bitfields;
	} GPIO_SPI_MOSI_BYTE_4_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t mosi_15_8:8; //SPI master MOSI byte 2
			uint32_t mosi_7_0:8; //SPI master MOSI byte 1
		} bitfields;
	} GPIO_SPI_MOSI_BYTE_2_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:10;
			uint32_t miso_39_32:8; //SPI master MISO byte 1
		} bitfields;
	} GPIO_SPI_MISO_BYTE_5;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t miso_31_24:8; //SPI master MISO byte 4
			uint32_t miso_23_16:8; //SPI master MISO byte 3
		} bitfields;
	} GPIO_SPI_MISO_BYTE_4_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t miso_15_8:8; //SPI master MISO byte 2
			uint32_t miso_7_0:8; //SPI master MISO byte 1
		} bitfields;
	} GPIO_SPI_MISO_BYTE_2_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:7; //-
			uint32_t i2c_tx_err:1; //Error on TX I2C. TX has not been sent correctly on SDA
			uint32_t i2c_rx_ack_err:1; //Error on RX ACK
			uint32_t i2c_stop_after_nack:1; //Send a STOP after it has received or sent a NACK
			uint32_t i2c_force_nack:1; //not acknowledge
			uint32_t i2c_rd_wrn:1; //read (1) - write (0)
			uint32_t i2c_op_code:3; //001: STOP   010: DATA 011: DATA , STOP 110: START , DATA 111: START , DATA , STOP 000, 100, 101: RESERVED
			uint32_t i2c_frame_size:2; //00: 1 byte 01: 2 byte 10: 3 byte 11: 4 byte If 5 byte (40 bit) are needed, sent byte in 2 times
			uint32_t i2c_transfer:1; //set to 1 to trigger I2C frame transfer
		} bitfields;
	} I2C_MASTER;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t i2c_data_out_7_0:8; //I2C data out byte 1
			uint32_t i2c_data_out_15_8:8; //I2C data out byte 2
		} bitfields;
	} GPIO_I2C_DATA_OUT_BYTE_2_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t i2c_data_out_23_16:8; //I2C data out byte 3
			uint32_t i2c_data_out_31_24:8; //I2C data out byte 4
		} bitfields;
	} GPIO_I2C_DATA_OUT_BYTE_4_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t i2c_data_in_7_0:8; //I2C data in byte 1
			uint32_t i2c_data_in_15_8:8; //I2C data in byte 2
		} bitfields;
	} GPIO_I2C_DATA_IN_BYTE_2_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2;
			uint32_t i2c_data_in_23_16:8; //I2C data in byte 3
			uint32_t i2c_data_in_31_24:8; //I2C data in byte 4
		} bitfields;
	} GPIO_I2C_DATA_IN_BYTE_4_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:11;
			uint32_t bal_swap_period:3; //Tbal_swap_period = 4s*2^(BAL_SWAP_PERIOD)
			uint32_t bal_swap:1; //set to 1 to enable automatic balancing channels' swap with applied disoverlap and selected period
			uint32_t bal_pre_scal:1; //define bal timer resolution 0: pre scaler factor 4s, range 0s to 508s 1: pre scaler factor 512s, range 0s to 65024s
			uint32_t bal_mode:1; //0: set TIMED balancing mode 1: set PWM-BASED balancing mode
			uint32_t bal_start:1; //BAL_START 0 to 1 start balancing procedure BAL_START 1 to 0 stop balancing procedure and reset BAL_TIMER If BAL_START has been already set to 1, to start a new balancing procedure this bit must be set to 0 and then set to 1 again.
		} bitfields;
	} BAL_GEN_CFG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t bal18_on:1; //set to 1 to balance CELL 18
			uint32_t bal17_on:1; //set to 1 to balance CELL 17
			uint32_t bal16_on:1; //set to 1 to balance CELL 16
			uint32_t bal15_on:1; //set to 1 to balance CELL 15
			uint32_t bal14_on:1; //set to 1 to balance CELL 14
			uint32_t bal13_on:1; //set to 1 to balance CELL 13
			uint32_t bal12_on:1; //set to 1 to balance CELL 12
			uint32_t bal11_on:1; //set to 1 to balance CELL 11
			uint32_t bal10_on:1; //set to 1 to balance CELL 10
			uint32_t bal9_on:1; //set to 1 to balance CELL 9
			uint32_t bal8_on:1; //set to 1 to balance CELL 8
			uint32_t bal7_on:1; //set to 1 to balance CELL 7
			uint32_t bal6_on:1; //set to 1 to balance CELL 6
			uint32_t bal5_on:1; //set to 1 to balance CELL 5
			uint32_t bal4_on:1; //set to 1 to balance CELL 4
			uint32_t bal3_on:1; //set to 1 to balance CELL 3
			uint32_t bal2_on:1; //set to 1 to balance CELL 2
			uint32_t bal1_on:1; //set to 1 to balance CELL 1
		} bitfields;
	} BAL_ON;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t bal_timer_max_th:16; //Safety timer watchdog threshold used in PWM-BASED balancing mode Tbal_timer_max = BAL_TIMER_MAX_TH*1s
		} bitfields;
	} BAL_TIMER_MAX_TH;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal2_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL2_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL2_TH*pre scaler factor
			uint32_t bal1_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL1_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL1_TH*pre scaler factor
		} bitfields;
	} BAL_TH_1_2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal4_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL4_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL4_TH*pre scaler factor
			uint32_t bal3_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL3_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL3_TH*pre scaler factor
		} bitfields;
	} BAL_TH_3_4;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal6_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL6_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL6_TH*pre scaler factor
			uint32_t bal5_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL5_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL5_TH*pre scaler factor
		} bitfields;
	} BAL_TH_5_6;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal8_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL8_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL8_TH*pre scaler factor
			uint32_t bal7_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL7_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL7_TH*pre scaler factor
		} bitfields;
	} BAL_TH_7_8;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal10_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL10_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL10_TH*pre scaler factor
			uint32_t bal9_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL9_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL9_TH*pre scaler factor
		} bitfields;
	} BAL_TH_9_10;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal12_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL12_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL12_TH*pre scaler factor
			uint32_t bal11_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL11_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL11_TH*pre scaler factor
		} bitfields;
	} BAL_TH_11_12;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal14_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL14_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL14_TH*pre scaler factor
			uint32_t bal13_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL13_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL13_TH*pre scaler factor
		} bitfields;
	} BAL_TH_13_14;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal16_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL16_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL16_TH*pre scaler factor
			uint32_t bal15_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL15_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL15_TH*pre scaler factor
		} bitfields;
	} BAL_TH_15_16;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:4; //-
			uint32_t bal18_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL18_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL18_TH*pre scaler factor
			uint32_t bal17_th:7; //PWM-BASED balancing mode: Tbal_pwm_duty = (BAL17_TH(4:0)+1)*1s TIMED balancing mode: Bxal timer threshold =  BAL17_TH*pre scaler factor
		} bitfields;
	} BAL_TH_17_18;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t bal_timer:16; //Bal timer counter value: BAL_TIMER*1s
		} bitfields;
	} BAL_TIMER;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 1 new conversion flag
			uint32_t vcell1_meas:16; //differential voltages at C1-C0 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL1_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 2 new conversion flag
			uint32_t vcell2_meas:16; //differential voltages at C2-C1 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL2_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 3 new conversion flag
			uint32_t vcell3_meas:16; //differential voltages at C3-C2 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL3_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 4 new conversion flag
			uint32_t vcell4_meas:16; //differential voltages at C4-C3 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL4_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 5 new conversion flag
			uint32_t vcell5_meas:16; //differential voltages at C5-C4 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL5_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 6 new conversion flag
			uint32_t vcell6_meas:16; //differential voltages at C6-C5 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL6_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 7 new conversion flag
			uint32_t vcell7_meas:16; //differential voltages at C7-C6 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL7_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 8 new conversion flag
			uint32_t vcell8_meas:16; //differential voltages at C8-C7 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL8_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 9 new conversion flag
			uint32_t vcell9_meas:16; //differential voltages at C9-C8 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL9_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 10 new conversion flag
			uint32_t vcell10_meas:16; //differential voltages at C10-C9 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL10_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 11 new conversion flag
			uint32_t vcell11_meas:16; //differential voltages at C11-C10 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL11_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 12 new conversion flag
			uint32_t vcell12_meas:16; //differential voltages at C12-C11 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL12_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 13 new conversion flag
			uint32_t vcell13_meas:16; //differential voltages at C13-C12 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL13_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 14 new conversion flag
			uint32_t vcell14_meas:16; //differential voltages at C14-C13 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL14_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 15 new conversion flag
			uint32_t vcell15_meas:16; //differential voltages at C15-C14 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL15_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 16 new conversion flag
			uint32_t vcell16_meas:16; //differential voltages at C16-C15 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL16_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 17 new conversion flag
			uint32_t vcell17_meas:16; //differential voltages at C17-C16 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL17_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //CELL 18 new conversion flag
			uint32_t vcell18_meas:16; //differential voltages at C18-C17 pins converted during VOLT_CONV routine step
		} bitfields;
	} VCELL18_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //BB new conversion flag
			uint32_t bb_meas:16; //differential voltages at BBP-BBM pins converted during VOLT_CONV routine step
		} bitfields;
	} BB_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:1; //-
			uint32_t data_ready:1; //VBS new conversion flag
			uint32_t vbs_meas:16; //battery stack voltage measure
		} bitfields;
	} VBS_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t data_ready:1; //new data flag
			uint32_t vcell_sum_meas:17; //digital sum of cells (including always BB connected to a CELL pins, including BB connected to the dedicated BB pins only if BB_ADD = 1) used to perform the plausibility check between VBS and sum of cells
		} bitfields;
	} VCELL_SUM_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 0 new conversion flag
			uint32_t ntc_gpio_meas_0:15; //NTC/GPIO 0 meausure
		} bitfields;
	} NTC_GPIO_MEAS_0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 1 new conversion flag
			uint32_t ntc_gpio_meas_1:15; //NTC/GPIO 1 meausure
		} bitfields;
	} NTC_GPIO_MEAS_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 2 new conversion flag
			uint32_t ntc_gpio_meas_2:15; //NTC/GPIO 2 meausure
		} bitfields;
	} NTC_GPIO_MEAS_2;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 3 new conversion flag
			uint32_t ntc_gpio_meas_3:15; //NTC/GPIO 3 meausure
		} bitfields;
	} NTC_GPIO_MEAS_3;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 4 new conversion flag
			uint32_t ntc_gpio_meas_4:15; //NTC/GPIO 4 meausure
		} bitfields;
	} NTC_GPIO_MEAS_4;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 5 new conversion flag
			uint32_t ntc_gpio_meas_5:15; //NTC/GPIO 5 meausure
		} bitfields;
	} NTC_GPIO_MEAS_5;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 6 new conversion flag
			uint32_t ntc_gpio_meas_6:15; //NTC/GPIO 6 meausure
		} bitfields;
	} NTC_GPIO_MEAS_6;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 7 new conversion flag
			uint32_t ntc_gpio_meas_7:15; //NTC/GPIO 7 meausure
		} bitfields;
	} NTC_GPIO_MEAS_7;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 8 new conversion flag
			uint32_t ntc_gpio_meas_8:15; //NTC/GPIO 8 meausure
		} bitfields;
	} NTC_GPIO_MEAS_8;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t data_ready:1; //NTC/GPIO 9 new conversion flag
			uint32_t ntc_gpio_meas_9:15; //NTC/GPIO 9 meausure
		} bitfields;
	} NTC_GPIO_MEAS_9;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:6; //-
			uint32_t die_adc_temp_meas:12; //Junction temperature measurement T(°C)=DIE_TEMP_ADC_TEMP_MEAS*0.077338-82.30396
		} bitfields;
	} DIE_TEMP_MEAS;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t nvm_verify_err:1; //NVM program/erase verify error flag to ensure correct upload excecution
			uint32_t ram_ecc_fail:1; //RAM integrity check fail flag
			uint32_t cyc_trim_crc_fail:1; //Cyclic CRC integrity check on trimming data fail flag
			uint32_t cyc_cfg_crc_fail:1; //Cyclic CRC integrity check on configuration data fail flag
			uint32_t nvm_crc_cfg_fail:1; //Configuration CRC check at NVM download fail flag
			uint32_t nvm_crc_trim_cal_fail:1; //Trimming/calibration CRC check at NVM download fail flag
			uint32_t osci_fail:1; //Clock monitor hi/low frequency check fail flag
			uint32_t tj_sd:1; //Thermal Shut Down fail flag
			uint32_t tj_warn:1; //Thermal Warning  fail flag
			uint32_t vana_ov:1; //5V Analog LDO Over Voltage detection
			uint32_t vana_uv:1; //5V Analog LDO Under Voltage detection
			uint32_t v5v_ov:1; //5V LDO Over Voltage detection
			uint32_t v5v_uv:1; //5V LDO Under Voltage detection
			uint32_t vpre_ov:1; //Buck Pre-Regulator Over Voltage detection
			uint32_t vpre_uv:1; //Buck Pre-Regulator Under Voltage detection
			uint32_t vcp_uv:1; //Charge Pump Under Voltage detection
			uint32_t gnd_loss_pgnd:1; //Power Ground Loss Monitor detection
			uint32_t por_main:1; //Feedback about POR_MAIN_N assertion
		} bitfields;
	} GENERAL_DIAG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_uv:1; //CELL 18 Under Voltage flag
			uint32_t vcell17_uv:1; //CELL 17 Under Voltage flag
			uint32_t vcell16_uv:1; //CELL 16 Under Voltage flag
			uint32_t vcell15_uv:1; //CELL 15 Under Voltage flag
			uint32_t vcell14_uv:1; //CELL 14 Under Voltage flag
			uint32_t vcell13_uv:1; //CELL 13 Under Voltage flag
			uint32_t vcell12_uv:1; //CELL 12 Under Voltage flag
			uint32_t vcell11_uv:1; //CELL 11 Under Voltage flag
			uint32_t vcell10_uv:1; //CELL 10 Under Voltage flag
			uint32_t vcell9_uv:1; //CELL 9 Under Voltage flag
			uint32_t vcell8_uv:1; //CELL 8 Under Voltage flag
			uint32_t vcell7_uv:1; //CELL 7 Under Voltage flag
			uint32_t vcell6_uv:1; //CELL 6 Under Voltage flag
			uint32_t vcell5_uv:1; //CELL 5 Under Voltage flag
			uint32_t vcell4_uv:1; //CELL 4 Under Voltage flag
			uint32_t vcell3_uv:1; //CELL 3 Under Voltage flag
			uint32_t vcell2_uv:1; //CELL 2 Under Voltage flag
			uint32_t vcell1_uv:1; //CELL 1 Under Voltage flag
		} bitfields;
	} VCELL_UV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_ov:1; //CELL 18 Over Voltage flag
			uint32_t vcell17_ov:1; //CELL 17 Over Voltage flag
			uint32_t vcell16_ov:1; //CELL 16 Over Voltage flag
			uint32_t vcell15_ov:1; //CELL 15 Over Voltage flag
			uint32_t vcell14_ov:1; //CELL 14 Over Voltage flag
			uint32_t vcell13_ov:1; //CELL 13 Over Voltage flag
			uint32_t vcell12_ov:1; //CELL 12 Over Voltage flag
			uint32_t vcell11_ov:1; //CELL 11 Over Voltage flag
			uint32_t vcell10_ov:1; //CELL 10 Over Voltage flag
			uint32_t vcell9_ov:1; //CELL 9 Over Voltage flag
			uint32_t vcell8_ov:1; //CELL 8 Over Voltage flag
			uint32_t vcell7_ov:1; //CELL 7 Over Voltage flag
			uint32_t vcell6_ov:1; //CELL 6 Over Voltage flag
			uint32_t vcell5_ov:1; //CELL 5 Over Voltage flag
			uint32_t vcell4_ov:1; //CELL 4 Over Voltage flag
			uint32_t vcell3_ov:1; //CELL 3 Over Voltage flag
			uint32_t vcell2_ov:1; //CELL 2 Over Voltage flag
			uint32_t vcell1_ov:1; //CELL 1 Over Voltage flag
		} bitfields;
	} VCELL_OV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_delta:1; //CELL 18 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell17_delta:1; //CELL 17 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell16_delta:1; //CELL 16 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell15_delta:1; //CELL 15 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell14_delta:1; //CELL 14 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell13_delta:1; //CELL 13 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell12_delta:1; //CELL 12 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell11_delta:1; //CELL 11 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell10_delta:1; //CELL 10 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell9_delta:1; //CELL 9 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell8_delta:1; //CELL 8 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell7_delta:1; //CELL 7 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell6_delta:1; //CELL 6 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell5_delta:1; //CELL 5 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell4_delta:1; //CELL 4 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell3_delta:1; //CELL 3 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell2_delta:1; //CELL 2 Delta diagnostic in CYCLIC WAKEUP flag
			uint32_t vcell1_delta:1; //CELL 1 Delta diagnostic in CYCLIC WAKEUP flag
		} bitfields;
	} VCELL_DELTA;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t vcell18_bal_uv:1; //CELL 18 Under Voltage flag
			uint32_t vcell17_bal_uv:1; //CELL 17 Under Voltage flag
			uint32_t vcell16_bal_uv:1; //CELL 16 Under Voltage flag
			uint32_t vcell15_bal_uv:1; //CELL 15 Under Voltage flag
			uint32_t vcell14_bal_uv:1; //CELL 14 Under Voltage flag
			uint32_t vcell13_bal_uv:1; //CELL 13 Under Voltage flag
			uint32_t vcell12_bal_uv:1; //CELL 12 Under Voltage flag
			uint32_t vcell11_bal_uv:1; //CELL 11 Under Voltage flag
			uint32_t vcell10_bal_uv:1; //CELL 10 Under Voltage flag
			uint32_t vcell9_bal_uv:1; //CELL 9 Under Voltage flag
			uint32_t vcell8_bal_uv:1; //CELL 8 Under Voltage flag
			uint32_t vcell7_bal_uv:1; //CELL 7 Under Voltage flag
			uint32_t vcell6_bal_uv:1; //CELL 6 Under Voltage flag
			uint32_t vcell5_bal_uv:1; //CELL 5 Under Voltage flag
			uint32_t vcell4_bal_uv:1; //CELL 4 Under Voltage flag
			uint32_t vcell3_bal_uv:1; //CELL 3 Under Voltage flag
			uint32_t vcell2_bal_uv:1; //CELL 2 Under Voltage flag
			uint32_t vcell1_bal_uv:1; //CELL 1 Under Voltage flag
		} bitfields;
	} VCELL_BAL_UV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:2; //-
			uint32_t nvm_ready:1; //0: NVM is busy, some data could be not available 1: NVM is ready to start a new operation, all data are available
			uint32_t unused1:1; //-
			uint32_t swap_echo:1; //echo of SWAP configuration status
			uint32_t vadc_bist_done:1; //VADC BIST execution status
			uint32_t abist_done:1; //ABIST execution status
			uint32_t vcr_busy:1; //1 means that Voltage Conversion Routine is running
			uint32_t vcr_fail:1; //0: all VCR steps have been executed as expected 1: one or more VCR steps has not been completed correctly
			uint32_t sfirst_open:1; //S0/S1 open diagnostic fail flag
			uint32_t bb_open:1; //BB pin open diagnostic fail flag
			uint32_t bb_ov:1; //BB pin over voltage diagnostic fail flag
			uint32_t vcell_delta_normal:1; //CELL Delta diagnostic in NORMAL
			uint32_t vbs_sum_fail:1; //plausability check of VBS vs CELLs' SUM
			uint32_t vbs_ov:1; //battery stack over voltage detection
			uint32_t vbs_uv:1; //battery stack under voltage detection
			uint32_t sum_ov:1; //Cells' sum over voltage detection
			uint32_t sum_uv:1; //Cells' sum under voltage detection
		} bitfields;
	} GENERAL_CELL_DIAG;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t bist18_fail:1; //VADC 18 BIST fail flag
			uint32_t bist17_fail:1; //VADC 17 BIST fail flag
			uint32_t bist16_fail:1; //VADC 16 BIST fail flag
			uint32_t bist15_fail:1; //VADC 15 BIST fail flag
			uint32_t bist14_fail:1; //VADC 14 BIST fail flag
			uint32_t bist13_fail:1; //VADC 13 BIST fail flag
			uint32_t bist12_fail:1; //VADC 12 BIST fail flag
			uint32_t bist11_fail:1; //VADC 11 BIST fail flag
			uint32_t bist10_fail:1; //VADC 10 BIST fail flag
			uint32_t bist9_fail:1; //VADC 9 BIST fail flag
			uint32_t bist8_fail:1; //VADC 8 BIST fail flag
			uint32_t bist7_fail:1; //VADC 7 BIST fail flag
			uint32_t bist6_fail:1; //VADC 6 BIST fail flag
			uint32_t bist5_fail:1; //VADC 5 BIST fail flag
			uint32_t bist4_fail:1; //VADC 4 BIST fail flag
			uint32_t bist3_fail:1; //VADC 3 BIST fail flag
			uint32_t bist2_fail:1; //VADC 2 BIST fail flag
			uint32_t bist1_fail:1; //VADC 1 BIST fail flag
		} bitfields;
	} BIST_FAIL_0;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:12; //-
			uint32_t temp_int_red_err:1; //temperature calibration ADC fail flag
			uint32_t gain_int_red_err:1; //gain correction fail flag
			uint32_t clk_mon_selftest_fail:1; //clock monitor selftest fail flag
			uint32_t bist_analog_comp_fail:1; //Analog BIST fail flag
			uint32_t bist_bb_fail:1; //VADC BB BIST fail flag
			uint32_t bist_vb_fail:1; //VADC VBS BIST fail flag
		} bitfields;
	} BIST_FAIL_1;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t afe_diag9:2; //00: no fault 01: C9-C8 open 10: S9-S8 open 11: PCB open, C9-C8 open and S9-S8 open
			uint32_t afe_diag8:2; //00: no fault 01: C8-C7 open 10: S8-S7 open 11: PCB open, C8-C7 open and S8-S7 open
			uint32_t afe_diag7:2; //00: no fault 01: C7-C6 open 10: S7-S6 open 11: PCB open, C7-C6 open and S7-S6 open
			uint32_t afe_diag6:2; //00: no fault 01: C6-C5 open 10: S6-S5 open 11: PCB open, C6-C5 open and S6-S5 open
			uint32_t afe_diag5:2; //00: no fault 01: C5-C4 open 10: S5-S4 open 11: PCB open, C5-C4 open and S5-S4 open
			uint32_t afe_diag4:2; //00: no fault 01: C4-C3 open 10: S4-S3 open 11: PCB open, C4-C3 open and S4-S3 open
			uint32_t afe_diag3:2; //00: no fault 01: C3-C2 open 10: S3-S2 open 11: PCB open, C3-C2 open and S3-S2 open
			uint32_t afe_diag2:2; //00: no fault 01: C2-C1 open 10: S2-S1 open 11: PCB open, C2-C1 open and S2-S1 open
			uint32_t afe_diag1:2; //00: no fault 01: C1-C0 open 10: S1-S0 open 11: PCB open, C1-C0 open and S1-S0 open
		} bitfields;
	} AFE_DIAG_1_9;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t afe_diag18:2; //00: no fault 01: C18-C17 open 10: S18-S17 open 11: PCB open, C18-C17 open and S18-S17 open
			uint32_t afe_diag17:2; //00: no fault 01: C17-C16 open 10: S17-S16 open 11: PCB open, C17-C16 open and S17-S16 open
			uint32_t afe_diag16:2; //00: no fault 01: C16-C15 open 10: S16-S15 open 11: PCB open, C16-C15 open and S16-S15 open
			uint32_t afe_diag15:2; //00: no fault 01: C15-C14 open 10: S15-S14 open 11: PCB open, C15-C14 open and S15-S14 open
			uint32_t afe_diag14:2; //00: no fault 01: C14-C13 open 10: S14-S13 open 11: PCB open, C14-C13 open and S14-S13 open
			uint32_t afe_diag13:2; //00: no fault 01: C13-C12 open 10: S13-S12 open 11: PCB open, C13-C12 open and S13-S12 open
			uint32_t afe_diag12:2; //00: no fault 01: C12-C11 open 10: S12-S11 open 11: PCB open, C12-C11 open and S12-S11 open
			uint32_t afe_diag11:2; //00: no fault 01: C11-C10 open 10: S11-S10 open 11: PCB open, C11-C10 open and S11-S10 open
			uint32_t afe_diag10:2; //00: no fault 01: C10-C9 open 10: S10-S9 open 11: PCB open, C10-C9 open and S10-S9 open
		} bitfields;
	} AFE_DIAG_10_18;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t ntc_ot_gpio_uv_9:1; //GPIO 9 Under Voltage if ABSOLUTE cfg selected NTC 9 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_8:1; //GPIO 8 Under Voltage if ABSOLUTE cfg selected NTC 8 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_7:1; //GPIO 7 Under Voltage if ABSOLUTE cfg selected NTC 7 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_6:1; //GPIO 6 Under Voltage if ABSOLUTE cfg selected NTC 6 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_5:1; //GPIO 5 Under Voltage if ABSOLUTE cfg selected NTC 5 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_4:1; //GPIO 4 Under Voltage if ABSOLUTE cfg selected NTC 4 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_3:1; //GPIO 3 Under Voltage if ABSOLUTE cfg selected NTC 3 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_2:1; //GPIO 2 Under Voltage if ABSOLUTE cfg selected NTC 2 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_1:1; //GPIO 1 Under Voltage if ABSOLUTE cfg selected NTC 1 Over Temperature if RATIO cfg selected
			uint32_t ntc_ot_gpio_uv_0:1; //GPIO 0 Under Voltage if ABSOLUTE cfg selected NTC 0 Over Temperature if RATIO cfg selected
		} bitfields;
	} NTC_OT_GPIO_UV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t ntc_ut_gpio_ov_9:1; //GPIO 9 Over Voltage if ABSOLUTE cfg selected NTC 9 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_8:1; //GPIO 8 Over Voltage if ABSOLUTE cfg selected NTC 8 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_7:1; //GPIO 7 Over Voltage if ABSOLUTE cfg selected NTC 7 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_6:1; //GPIO 6 Over Voltage if ABSOLUTE cfg selected NTC 6 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_5:1; //GPIO 5 Over Voltage if ABSOLUTE cfg selected NTC 5 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_4:1; //GPIO 4 Over Voltage if ABSOLUTE cfg selected NTC 4 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_3:1; //GPIO 3 Over Voltage if ABSOLUTE cfg selected NTC 3 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_2:1; //GPIO 2 Over Voltage if ABSOLUTE cfg selected NTC 2 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_1:1; //GPIO 1 Over Voltage if ABSOLUTE cfg selected NTC 1 Under Temperature if RATIO cfg selected
			uint32_t ntc_ut_gpio_ov_0:1; //GPIO 0 Over Voltage if ABSOLUTE cfg selected NTC 0 Under Temperature if RATIO cfg selected
		} bitfields;
	} NTC_UT_GPIO_OV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t ntc_fastchg_ot_gpio_warn_uv_9:1; //GPIO 9 Warning Under Voltage if ABSOLUTE cfg selected NTC 9 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_8:1; //GPIO 8 Warning Under Voltage if ABSOLUTE cfg selected NTC 8 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_7:1; //GPIO 7 Warning Under Voltage if ABSOLUTE cfg selected NTC 7 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_6:1; //GPIO 6 Warning Under Voltage if ABSOLUTE cfg selected NTC 6 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_5:1; //GPIO 5 Warning Under Voltage if ABSOLUTE cfg selected NTC 5 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_4:1; //GPIO 4 Warning Under Voltage if ABSOLUTE cfg selected NTC 4 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_3:1; //GPIO 3 Warning Under Voltage if ABSOLUTE cfg selected NTC 3 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_2:1; //GPIO 2 Warning Under Voltage if ABSOLUTE cfg selected NTC 2 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_1:1; //GPIO 1 Warning Under Voltage if ABSOLUTE cfg selected NTC 1 Fast Charge Over Temperature if RATIO cfg selected
			uint32_t ntc_fastchg_ot_gpio_warn_uv_0:1; //GPIO 0 Warning Under Voltage if ABSOLUTE cfg selected NTC 0 Fast Charge Over Temperature if RATIO cfg selected
		} bitfields;
	} NTC_FASTCHG_OT_GPIO_WARN_UV;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:7; //-
			uint32_t ntc_delta_normal:1; //NTC delta diagnostic in NORMAL
			uint32_t ntc_delta_gpio_delta_9:1; //NTC 9 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_8:1; //NTC 8 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_7:1; //NTC 7 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_6:1; //NTC 6 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_5:1; //NTC 5 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_4:1; //NTC 4 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_3:1; //NTC 3 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_2:1; //NTC 2 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_1:1; //NTC 1 delta diagnostic in CYCLIC WAKEUP
			uint32_t ntc_delta_gpio_delta_0:1; //NTC 0 delta diagnostic in CYCLIC WAKEUP
		} bitfields;
	} NTC_DELTA_GPIO_DELTA;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t gpio9_open:1; //GPIO 9 open diagnostic
			uint32_t gpio8_open:1; //GPIO 8 open diagnostic
			uint32_t gpio7_open:1; //GPIO 7 open diagnostic
			uint32_t gpio6_open:1; //GPIO 6 open diagnostic
			uint32_t gpio5_open:1; //GPIO 5 open diagnostic
			uint32_t gpio4_open:1; //GPIO 4 open diagnostic
			uint32_t gpio3_open:1; //GPIO 3 open diagnostic
			uint32_t gpio2_open:1; //GPIO 2 open diagnostic
			uint32_t gpio1_open:1; //GPIO 1 open diagnostic
			uint32_t gpio0_open:1; //GPIO 0 open diagnostic
		} bitfields;
	} GPIO_OPEN;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:17; //-
			uint32_t por_sleep:1; //Feedback about POR_SLEEP_N assertion
		} bitfields;
	} PWR_SLEEP_READ;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t bal18_oc:1; //Balancing FET 18 Over Current detection
			uint32_t bal17_oc:1; //Balancing FET 17 Over Current detection
			uint32_t bal16_oc:1; //Balancing FET 16 Over Current detection
			uint32_t bal15_oc:1; //Balancing FET 15 Over Current detection
			uint32_t bal14_oc:1; //Balancing FET 14 Over Current detection
			uint32_t bal13_oc:1; //Balancing FET 13 Over Current detection
			uint32_t bal12_oc:1; //Balancing FET 12 Over Current detection
			uint32_t bal11_oc:1; //Balancing FET 11 Over Current detection
			uint32_t bal10_oc:1; //Balancing FET 10 Over Current detection
			uint32_t bal9_oc:1; //Balancing FET 9 Over Current detection
			uint32_t bal8_oc:1; //Balancing FET 8 Over Current detection
			uint32_t bal7_oc:1; //Balancing FET 7 Over Current detection
			uint32_t bal6_oc:1; //Balancing FET 6 Over Current detection
			uint32_t bal5_oc:1; //Balancing FET 5 Over Current detection
			uint32_t bal4_oc:1; //Balancing FET 4 Over Current detection
			uint32_t bal3_oc:1; //Balancing FET 3 Over Current detection
			uint32_t bal2_oc:1; //Balancing FET 2 Over Current detection
			uint32_t bal1_oc:1; //Balancing FET 1 Over Current detection
		} bitfields;
	} BAL_OC;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:13; //-
			uint32_t vif_id_err:1; //1 if DEV_ID frame field is different from configured VIF_ID
			uint32_t comm_crc_err:1; //Wrong CRC frame detected
			uint32_t wrong_addr:1; //Wrong addressing detected
			uint32_t short_frame:1; //Short frame error
			uint32_t long_frame:1; //Long frame error
		} bitfields;
	} COMM_ERR;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:5; //-
			uint32_t burst_mode:1; //0: standard BURST 1: compressed BURST
			uint32_t burst_wd:5; //just for standard BURST, select start address
			uint32_t burst_off:7; //just for standard BURST, select stop address
		} bitfields;
	} BURST_CMD;

	union {
		uint32_t reg;
		struct {
			uint32_t residual_unused:14;
			uint32_t unused0:8; //-
			uint32_t gpo9:1; //value with which to drive the GPIO 9 when configured as digital output
			uint32_t gpo8:1; //value with which to drive the GPIO 8 when configured as digital output
			uint32_t gpo7:1; //value with which to drive the GPIO 7 when configured as digital output
			uint32_t gpo6:1; //value with which to drive the GPIO 6 when configured as digital output
			uint32_t gpo5:1; //value with which to drive the GPIO 5 when configured as digital output
			uint32_t gpo4:1; //value with which to drive the GPIO 4 when configured as digital output
			uint32_t gpo3:1; //value with which to drive the GPIO 3 when configured as digital output
			uint32_t gpo2:1; //value with which to drive the GPIO 2 when configured as digital output
			uint32_t gpo1:1; //value with which to drive the GPIO 1 when configured as digital output
			uint32_t gpo0:1; //value with which to drive the GPIO 0 when configured as digital output
		} bitfields;
	} GPO;

};

#define L9965A_REGMAP_CHIPID_ADDR 0x00
#define L9965A_REGMAP_VIF_ID_ADDR 0x01
#define L9965A_REGMAP_DEV_GEN_CFG_1_ADDR 0x02
#define L9965A_REGMAP_DEV_GEN_CFG_2_ADDR 0x03
#define L9965A_REGMAP_VCELL_EN_ADDR 0x04
#define L9965A_REGMAP_VCELL_BB_ADDR 0x05
#define L9965A_REGMAP_CELL_TH_ADDR 0x06
#define L9965A_REGMAP_MSK_FLT_CELL_INDEX_ADDR 0x07
#define L9965A_REGMAP_SUM_TH_ADDR 0x08
#define L9965A_REGMAP_VBS_TH_ADDR 0x09
#define L9965A_REGMAP_VBS_BB_CFG_ADDR 0x0A
#define L9965A_REGMAP_OTHER1_TH_ADDR 0x0B
#define L9965A_REGMAP_GPIO_CONF_1_ADDR 0x0C
#define L9965A_REGMAP_GPIO_CONF_2_ADDR 0x0D
#define L9965A_REGMAP_NTC_CFG_ADDR 0x0E
#define L9965A_REGMAP_NTC0_UT_OT_TH_ADDR 0x0F
#define L9965A_REGMAP_NTC1_UT_OT_TH_ADDR 0x10
#define L9965A_REGMAP_NTC2_UT_OT_TH_ADDR 0x11
#define L9965A_REGMAP_NTC3_UT_OT_TH_ADDR 0x12
#define L9965A_REGMAP_NTC4_UT_OT_TH_ADDR 0x13
#define L9965A_REGMAP_NTC5_UT_OT_TH_ADDR 0x14
#define L9965A_REGMAP_NTC6_UT_OT_TH_ADDR 0x15
#define L9965A_REGMAP_NTC7_UT_OT_TH_ADDR 0x16
#define L9965A_REGMAP_NTC8_UT_OT_TH_ADDR 0x17
#define L9965A_REGMAP_NTC9_UT_OT_TH_ADDR 0x18
#define L9965A_REGMAP_BAL_COOLDOWN_EN_ADDR 0x19
#define L9965A_REGMAP_SPECIAL_REG_ADDR 0x1A
#define L9965A_REGMAP_VOLT_CONV_ADDR 0x1B
#define L9965A_REGMAP_VOLT_CONV_CFG_ADDR 0x1C
#define L9965A_REGMAP_GENERAL_REG_ADDR 0x1D
#define L9965A_REGMAP_SPI_MODE_COMM_TIM_ADDR 0x1E
#define L9965A_REGMAP_SPI_MASTER_ADDR 0x1F
#define L9965A_REGMAP_GPIO_SPI_MOSI_BYTE_5_ADDR 0x20
#define L9965A_REGMAP_GPIO_SPI_MOSI_BYTE_4_3_ADDR 0x21
#define L9965A_REGMAP_GPIO_SPI_MOSI_BYTE_2_1_ADDR 0x22
#define L9965A_REGMAP_GPIO_SPI_MISO_BYTE_5_ADDR 0x23
#define L9965A_REGMAP_GPIO_SPI_MISO_BYTE_4_3_ADDR 0x24
#define L9965A_REGMAP_GPIO_SPI_MISO_BYTE_2_1_ADDR 0x25
#define L9965A_REGMAP_I2C_MASTER_ADDR 0x26
#define L9965A_REGMAP_GPIO_I2C_DATA_OUT_BYTE_2_1_ADDR 0x27
#define L9965A_REGMAP_GPIO_I2C_DATA_OUT_BYTE_4_3_ADDR 0x28
#define L9965A_REGMAP_GPIO_I2C_DATA_IN_BYTE_2_1_ADDR 0x29
#define L9965A_REGMAP_GPIO_I2C_DATA_IN_BYTE_4_3_ADDR 0x2A
#define L9965A_REGMAP_BAL_GEN_CFG_ADDR 0x2B
#define L9965A_REGMAP_BAL_ON_ADDR 0x2C
#define L9965A_REGMAP_BAL_TIMER_MAX_TH_ADDR 0x2D
#define L9965A_REGMAP_BAL_TH_1_2_ADDR 0x2E
#define L9965A_REGMAP_BAL_TH_3_4_ADDR 0x2F
#define L9965A_REGMAP_BAL_TH_5_6_ADDR 0x30
#define L9965A_REGMAP_BAL_TH_7_8_ADDR 0x31
#define L9965A_REGMAP_BAL_TH_9_10_ADDR 0x32
#define L9965A_REGMAP_BAL_TH_11_12_ADDR 0x33
#define L9965A_REGMAP_BAL_TH_13_14_ADDR 0x34
#define L9965A_REGMAP_BAL_TH_15_16_ADDR 0x35
#define L9965A_REGMAP_BAL_TH_17_18_ADDR 0x36
#define L9965A_REGMAP_BAL_TIMER_ADDR 0x37
#define L9965A_REGMAP_VCELL1_MEAS_ADDR 0x38
#define L9965A_REGMAP_VCELL2_MEAS_ADDR 0x39
#define L9965A_REGMAP_VCELL3_MEAS_ADDR 0x3A
#define L9965A_REGMAP_VCELL4_MEAS_ADDR 0x3B
#define L9965A_REGMAP_VCELL5_MEAS_ADDR 0x3C
#define L9965A_REGMAP_VCELL6_MEAS_ADDR 0x3D
#define L9965A_REGMAP_VCELL7_MEAS_ADDR 0x3E
#define L9965A_REGMAP_VCELL8_MEAS_ADDR 0x3F
#define L9965A_REGMAP_VCELL9_MEAS_ADDR 0x40
#define L9965A_REGMAP_VCELL10_MEAS_ADDR 0x41
#define L9965A_REGMAP_VCELL11_MEAS_ADDR 0x42
#define L9965A_REGMAP_VCELL12_MEAS_ADDR 0x43
#define L9965A_REGMAP_VCELL13_MEAS_ADDR 0x44
#define L9965A_REGMAP_VCELL14_MEAS_ADDR 0x45
#define L9965A_REGMAP_VCELL15_MEAS_ADDR 0x46
#define L9965A_REGMAP_VCELL16_MEAS_ADDR 0x47
#define L9965A_REGMAP_VCELL17_MEAS_ADDR 0x48
#define L9965A_REGMAP_VCELL18_MEAS_ADDR 0x49
#define L9965A_REGMAP_BB_MEAS_ADDR 0x4A
#define L9965A_REGMAP_VBS_MEAS_ADDR 0x4B
#define L9965A_REGMAP_VCELL_SUM_MEAS_ADDR 0x4C
#define L9965A_REGMAP_NTC_GPIO_MEAS_0_ADDR 0x4D
#define L9965A_REGMAP_NTC_GPIO_MEAS_1_ADDR 0x4E
#define L9965A_REGMAP_NTC_GPIO_MEAS_2_ADDR 0x4F
#define L9965A_REGMAP_NTC_GPIO_MEAS_3_ADDR 0x50
#define L9965A_REGMAP_NTC_GPIO_MEAS_4_ADDR 0x51
#define L9965A_REGMAP_NTC_GPIO_MEAS_5_ADDR 0x52
#define L9965A_REGMAP_NTC_GPIO_MEAS_6_ADDR 0x53
#define L9965A_REGMAP_NTC_GPIO_MEAS_7_ADDR 0x54
#define L9965A_REGMAP_NTC_GPIO_MEAS_8_ADDR 0x55
#define L9965A_REGMAP_NTC_GPIO_MEAS_9_ADDR 0x56
#define L9965A_REGMAP_DIE_TEMP_MEAS_ADDR 0x57
#define L9965A_REGMAP_GENERAL_DIAG_ADDR 0x58
#define L9965A_REGMAP_VCELL_UV_ADDR 0x59
#define L9965A_REGMAP_VCELL_OV_ADDR 0x5A
#define L9965A_REGMAP_VCELL_DELTA_ADDR 0x5B
#define L9965A_REGMAP_VCELL_BAL_UV_ADDR 0x5C
#define L9965A_REGMAP_GENERAL_CELL_DIAG_ADDR 0x5D
#define L9965A_REGMAP_BIST_FAIL_0_ADDR 0x5E
#define L9965A_REGMAP_BIST_FAIL_1_ADDR 0x5F
#define L9965A_REGMAP_AFE_DIAG_1_9_ADDR 0x60
#define L9965A_REGMAP_AFE_DIAG_10_18_ADDR 0x61
#define L9965A_REGMAP_NTC_OT_GPIO_UV_ADDR 0x62
#define L9965A_REGMAP_NTC_UT_GPIO_OV_ADDR 0x63
#define L9965A_REGMAP_NTC_FASTCHG_OT_GPIO_WARN_UV_ADDR 0x64
#define L9965A_REGMAP_NTC_DELTA_GPIO_DELTA_ADDR 0x65
#define L9965A_REGMAP_GPIO_OPEN_ADDR 0x66
#define L9965A_REGMAP_PWR_SLEEP_READ_ADDR 0x67
#define L9965A_REGMAP_BAL_OC_ADDR 0x68
#define L9965A_REGMAP_COMM_ERR_ADDR 0x69
#define L9965A_REGMAP_BURST_CMD_ADDR 0x6A
#define L9965A_REGMAP_GPO_ADDR 0x6B
#endif
