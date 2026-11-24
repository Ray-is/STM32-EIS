#ifndef __L9965P_REGMAP_H
#define __L9965P_REGMAP_H
/******************************************************************************/
/*                           Module: L9965P_REGMAP                              */
/*      All fields declared are unsigned! Please cast them as convenient      */
/******************************************************************************/
struct L9965P_REGMAP_STRUCTURE
{
	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2; //TBD
			uint16_t bms_id:8; //TBD
		} bitfields;
	} BMS_ID;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2; //TBD
			uint16_t silicon_id:3;
			uint16_t metal_id:5;
		} bitfields;
	} CHIP_ID;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:6;
			uint16_t fenl_int_check_en:1;
			uint16_t fenh_int_check_en:1;
			uint16_t faultn_force:1;
			uint16_t faultn_cyclic_pulse:1;
		} bitfields;
	} FAULT_DIAG_CONFIG;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:8;
			uint16_t fenl_mode:1;
			uint16_t fenh_mode:1;
		} bitfields;
	} FENH_L_CONFIG;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:1;
			uint16_t spi_diag_running:1;
			uint16_t spi_diag_end:1;
			uint16_t diag_start:1; //Start On-Demand Diag Routine
			uint16_t abist:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
			uint16_t adc_hwsc:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
			uint16_t vrcm_leak_test:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
			uint16_t pyro_res:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
			uint16_t fet_test:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
			uint16_t er_cap:1; //0: Disable execution in On-Demand Diag Routine 1: Enable execution in On-Demand Diag Routine
		} bitfields;
	} DIAG_CMD;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:4;
			uint16_t adc_busy:1;
			uint16_t adc_conv_rdy:1;
			uint16_t amux_conf:3;
			uint16_t adc_conv_cmd:1;
		} bitfields;
	} ADC_CONV_CMD;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t adc_conversion:10;
		} bitfields;
	} ADC_CONV_RESULT;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:4;
			uint16_t nvm_crc_fail_msk:1;
			uint16_t nvm_crc_cfg_fail:1;
			uint16_t nvm_crc_trim_cal_fail:1;
			uint16_t cyc_cfg_crc_fail:1;
			uint16_t cyc_trim_cal_crc_fail:1;
			uint16_t cyc_crc_dis:1; //Disable Cyclic CRC check on Trimming Registers (both internal and client)
		} bitfields;
	} CRC;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t fire_inhibit :1;
			uint16_t deploy_cnt:3;
			uint16_t fire_running:1;
			uint16_t fire_good:1; //0: Fire sequence successful 1: Fire sequence not successful
			uint16_t fire_end_by_fault:1; //0: Fire sequence not ended 1: Fire sequence ended by fault
			uint16_t fire_end:1; //0: Fire sequence not ended 1: Fire sequence ended
			uint16_t fenl_arm:1; //0: FENL ARM condition not detected 1: FENL ARM condition detected
			uint16_t fenh_arm:1; //0: FENH ARM condition not detected 1: FENH ARM condition detected
		} bitfields;
	} DEPLOY_STATUS;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t pr_stb:1; //0: PR leakage test good 1: PR leakage test fail
			uint16_t pr_stg:1; //0: PR leakage test good 1: PR leakage test fail
			uint16_t pf_stb:1; //0: PF leakage test good 1: PF leakage test fail
			uint16_t pf_stg:1; //0: PF leakage test good 1: PF leakage test fail
			uint16_t vrcm_stg_fail:1; //0: VRCM STG comparator selftest good 1: VRCM STG comparator selftest fail
			uint16_t vrcm_stb_fail:1; //0: VRCM STB comparator selftest good 1: VRCM STB comparator selftest fail
			uint16_t pr_fet_stb:1;
			uint16_t pr_fet_fail:1;
			uint16_t pf_fet_stg:1;
			uint16_t pf_fet_fail:1;
		} bitfields;
	} DEPLOY_DIAG_STATUS_0;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:3;
			uint16_t pf_pr_pre_hwsc_fail:1; //0: PFvsPR PRE HWSC test good 1: PFvsPR PRE HWSC test fail
			uint16_t pf_pr_post_hwsc_fail:1; //0: PFvsPR POST HWSC test good 1: PFvsPR POST HWSC test fail
			uint16_t vrcm_hwsc_fail:1;
			uint16_t ps_ov:1;
			uint16_t ps_uv:1;
			uint16_t pyro_high_res:1; //0:  PYRO Resistance test good 1:  PYRO Resistance test fail
			uint16_t pyro_low_res:1; //0:  PYRO Resistance test good 1:  PYRO Resistance test fail
		} bitfields;
	} DEPLOY_DIAG_STATUS_1;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:4;
			uint16_t erdchsw_ov:1;
			uint16_t ercdhsw_en:1; //Reset when ERCAP diag or Arming Starts
			uint16_t ercap_out_of_range:1; //0:  ERCAP test good 1:  ERCAP test fail
			uint16_t ercap_diag_end_to:1; //0:  ERCAP test good 1:  ERCAP test fail
			uint16_t ercap_high_esr:1; //0:  ERCAP test good 1:  ERCAP test fail
			uint16_t ercap_low_c:1; //0:  ERCAP test good 1:  ERCAP test fail
		} bitfields;
	} ERCAP;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t cap_value_lsb:10;
		} bitfields;
	} ERCAP_DIAG_CAP_READ_0;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:6;
			uint16_t cap_value_msb:4;
		} bitfields;
	} ERCAP_DIAG_CAP_READ_1;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t esr_value_lsb:10;
		} bitfields;
	} ERCAP_DIAG_ESR_READ_0;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:7;
			uint16_t esr_value_msb:3;
		} bitfields;
	} ERCAP_DIAG_ESR_READ_1;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spi_wakeup:1;
			uint16_t fenx_wakeup:1;
			uint16_t cwup_wakeup:1;
			uint16_t gnd_loss_pgnd:1;
			uint16_t npor_sleep_event:1;
			uint16_t osci_fail:1;
			uint16_t bias_warning:1;
			uint16_t v3v3_sleep_uv:1;
			uint16_t v3v3_sleep_ov:1;
			uint16_t abist_fail:1;
		} bitfields;
	} INTERNAL_STATUS;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:5;
			uint16_t spi_frame_short:1;
			uint16_t spi_frame_long:1;
			uint16_t spi_crc_error:1;
			uint16_t spi_address_error:1;
			uint16_t spi_frame_error:1;
		} bitfields;
	} SPI_STATUS;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t fenh_echo:1;
			uint16_t fenl_echo:1;
			uint16_t fenh_high_freq:1;
			uint16_t fenl_high_freq:1;
			uint16_t fenh_low_freq:1;
			uint16_t fenl_low_freq:1;
			uint16_t fenh_pwm_timeout:1;
			uint16_t fenl_pwm_timeout:1;
			uint16_t fenh_lev_timeout:1;
			uint16_t fenl_lev_timeout:1;
		} bitfields;
	} FENX_INTEGRITY_STATUS;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2;
			uint16_t cyc_diag_running:1;
			uint16_t cyc_diag_ncycle:7; //number of cyclic diagnosis routine cycle. Restart after 64 cycles.
		} bitfields;
	} CYCLIC_DIAG_STATUS;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2;
			uint16_t bst_gnd_loss:1;
			uint16_t erbst_oc:1;
			uint16_t erbst_diode_loss:1;
			uint16_t erbst_ot:1;
			uint16_t erbst_uv:1;
			uint16_t erbst_ov:1;
			uint16_t erbst_rdy:1;
			uint16_t erbst_dis:1;
		} bitfields;
	} ERBOOST;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:4;
			uint16_t spare_dig_2:1;
			uint16_t spare_dig_1:1;
			uint16_t spare_dig_0:1;
			uint16_t osc_ss_en:1;
			uint16_t pr_pd_dis:1;
			uint16_t ps_ov_fire_msk:1;
		} bitfields;
	} INTERNAL_CFG;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t res_meas_pre:10;
		} bitfields;
	} RES_MEAS_PRE;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t res_meas_post:10;
		} bitfields;
	} RES_MEAS_POST;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:1;
			uint16_t dep_curr_mon:9;
		} bitfields;
	} DEPLOY_CURRENT_MONITOR;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2;
			uint16_t temperature_code:8;
		} bitfields;
	} TEMPERATURE;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_24;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_25;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_26;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_27;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_28;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t spare:9;
			uint16_t unused0:1;
		} bitfields;
	} INTERNAL_REG_29;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_erbst_ov_fire_msk:1;
			uint16_t trim_erbst_ov_faultn_msk:1;
			uint16_t trim_fenl_pu_pd:1;
			uint16_t trim_fenh_pu_pd:1;
			uint16_t trim_fenl_freq:1;
			uint16_t trim_fenh_freq:1;
			uint16_t trim_fenl_level:1;
			uint16_t trim_fenh_level:1;
			uint16_t trim_fenl_en:1;
			uint16_t trim_fenh_en:1;
		} bitfields;
	} CLIENT_NVM_REG_0;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_fenx_fault_period:2;
			uint16_t trim_fenx_deglitch:2;
			uint16_t trim_pyro_high_res_faultn_msk:1;
			uint16_t trim_pyro_low_res_faultn_msk :1;
			uint16_t trim_i_deploy_cfg:2;
			uint16_t trim_fenx_dly_cfg:2;
		} bitfields;
	} CLIENT_NVM_REG_1;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_erbstsw_ot_faultn_msk:1;
			uint16_t trim_erbstsw_oc_faultn_msk:1;
			uint16_t trim_erbst_uv_faultn_msk  :1;
			uint16_t trim_vres_low_th:7;
		} bitfields;
	} CLIENT_NVM_REG_2;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_hs_ret_cfg:2;
			uint16_t trim_vres_high_th:7;
			uint16_t trim_erbst_dloss_faultn_msk:1;
		} bitfields;
	} CLIENT_NVM_REG_3;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_vres_thr_post_sel:1;
			uint16_t trim_pyro_res_en:1;
			uint16_t trim_leak_en:1;
			uint16_t trim_adc_hwsc_en:1;
			uint16_t trim_fet_en:1;
			uint16_t trim_er_cap_en:1;
			uint16_t trim_diag_routine_period:2;
			uint16_t trim_hs_ret_dly_cfg:2;
		} bitfields;
	} CLIENT_NVM_REG_4;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_fet_ncycle:2;
			uint16_t trim_pyro_res_ncycle:2;
			uint16_t trim_pf_fet_fail_faultn_msk:1;
			uint16_t trim_dep_mon_thr:5;
		} bitfields;
	} CLIENT_NVM_REG_5;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_er_cap_ncycle:2;
			uint16_t trim_pf_pr_stb_stg_faultn_msk:1;
			uint16_t trim_ercap_faultn_msk:1;
			uint16_t trim_leak_low_faultn_msk:1;
			uint16_t trim_vrcm_hwsc_faultn_msk:1;
			uint16_t trim_pf_pr_post_hwsc_faultn_msk:1;
			uint16_t trim_pf_pr_pre_hwsc_faultn_msk:1;
			uint16_t trim_adc_hwsc_ncycle:2;
		} bitfields;
	} CLIENT_NVM_REG_6;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_pf_fet_fail_fire_msk:1;
			uint16_t trim_leak_ncycle:2;
			uint16_t trim_t_dep_cfg:7;
		} bitfields;
	} CLIENT_NVM_REG_7;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_erbstsw_oc_fire_msk:1;
			uint16_t trim_ver_wkup:3;
			uint16_t trim_erbst_set:3;
			uint16_t trim_pin_limit:1;
			uint16_t trim_pr_fet_fail_fire_msk:1;
			uint16_t trim_pr_fet_fail_faultn_msk:1;
		} bitfields;
	} CLIENT_NVM_REG_8;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_gnd_loss_bstgnd_msk:1;
			uint16_t trim_erbst_en:1;
			uint16_t trim_ercap_c_thr:8;
		} bitfields;
	} CLIENT_NVM_REG_9;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t trim_fenx_timeout_faultn_msk :1;
			uint16_t trim_fenx_low_freq_faultn_msk:1;
			uint16_t trim_fenx_high_freq_faultn_msk:1;
			uint16_t trim_ercap_esr_thr:7;
		} bitfields;
	} CLIENT_NVM_REG_10;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t nvm_upload_count:5;
			uint16_t trim_faultn_dis:1;
			uint16_t trim_fire_good_sel:2;
			uint16_t trim_ps_uv_faultn_msk:1;
			uint16_t trim_ps_ov_faultn_msk:1;
		} bitfields;
	} CLIENT_NVM_REG_11;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2;
			uint16_t client_config_crc:8; //NB: Write by SPI WRITE ALWAYS LOCKED  Write only possible internally with NVM download
		} bitfields;
	} CLIENT_NVM_REG_12;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:2;
			uint16_t special_key:8; //0x55 partial unlock 0x33 full unlock 0xAA lock 0xE1 partial SW reset 0x1E full SW reset 0x77 partial GO2SLP 0xCC full GO2SLP
		} bitfields;
	} SPECIAL_KEY;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t unused0:4;
			uint16_t nvm_erase_verify_error:1;
			uint16_t nvm_program_verify_error:1;
			uint16_t nvm_busy:1;
			uint16_t nvm_operation:3; //0x3 upload Client NVM sect and download all NVM 0x5 download all NVM
		} bitfields;
	} NVM_OP_CMD;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t arm_hs_spi:10; //0x155 ARM HS
		} bitfields;
	} HS_CMD;

	union {
		uint16_t reg;
		struct {
			uint16_t residual_unused:6;
			uint16_t arm_ls_spi:10; //0x2AA ARM LS
		} bitfields;
	} LS_CMD;

};

#define L9965P_REGMAP_BMS_ID_ADDR 0x00
#define L9965P_REGMAP_CHIP_ID_ADDR 0x01
#define L9965P_REGMAP_FAULT_DIAG_CONFIG_ADDR 0x02
#define L9965P_REGMAP_FENH_L_CONFIG_ADDR 0x03
#define L9965P_REGMAP_DIAG_CMD_ADDR 0x04
#define L9965P_REGMAP_ADC_CONV_CMD_ADDR 0x05
#define L9965P_REGMAP_ADC_CONV_RESULT_ADDR 0x06
#define L9965P_REGMAP_CRC_ADDR 0x07
#define L9965P_REGMAP_DEPLOY_STATUS_ADDR 0x08
#define L9965P_REGMAP_DEPLOY_DIAG_STATUS_0_ADDR 0x09
#define L9965P_REGMAP_DEPLOY_DIAG_STATUS_1_ADDR 0x0A
#define L9965P_REGMAP_ERCAP_ADDR 0x0B
#define L9965P_REGMAP_ERCAP_DIAG_CAP_READ_0_ADDR 0x0C
#define L9965P_REGMAP_ERCAP_DIAG_CAP_READ_1_ADDR 0x0D
#define L9965P_REGMAP_ERCAP_DIAG_ESR_READ_0_ADDR 0x0E
#define L9965P_REGMAP_ERCAP_DIAG_ESR_READ_1_ADDR 0x0F
#define L9965P_REGMAP_INTERNAL_STATUS_ADDR 0x10
#define L9965P_REGMAP_SPI_STATUS_ADDR 0x11
#define L9965P_REGMAP_FENX_INTEGRITY_STATUS_ADDR 0x12
#define L9965P_REGMAP_CYCLIC_DIAG_STATUS_ADDR 0x13
#define L9965P_REGMAP_ERBOOST_ADDR 0x14
#define L9965P_REGMAP_INTERNAL_CFG_ADDR 0x15
#define L9965P_REGMAP_RES_MEAS_PRE_ADDR 0x16
#define L9965P_REGMAP_RES_MEAS_POST_ADDR 0x17
#define L9965P_REGMAP_DEPLOY_CURRENT_MONITOR_ADDR 0x18
#define L9965P_REGMAP_TEMPERATURE_ADDR 0x19
#define L9965P_REGMAP_INTERNAL_REG_24_ADDR 0x1A
#define L9965P_REGMAP_INTERNAL_REG_25_ADDR 0x1B
#define L9965P_REGMAP_INTERNAL_REG_26_ADDR 0x1C
#define L9965P_REGMAP_INTERNAL_REG_27_ADDR 0x1D
#define L9965P_REGMAP_INTERNAL_REG_28_ADDR 0x1E
#define L9965P_REGMAP_INTERNAL_REG_29_ADDR 0x1F
#define L9965P_REGMAP_CLIENT_NVM_REG_0_ADDR 0x20
#define L9965P_REGMAP_CLIENT_NVM_REG_1_ADDR 0x21
#define L9965P_REGMAP_CLIENT_NVM_REG_2_ADDR 0x22
#define L9965P_REGMAP_CLIENT_NVM_REG_3_ADDR 0x23
#define L9965P_REGMAP_CLIENT_NVM_REG_4_ADDR 0x24
#define L9965P_REGMAP_CLIENT_NVM_REG_5_ADDR 0x25
#define L9965P_REGMAP_CLIENT_NVM_REG_6_ADDR 0x26
#define L9965P_REGMAP_CLIENT_NVM_REG_7_ADDR 0x27
#define L9965P_REGMAP_CLIENT_NVM_REG_8_ADDR 0x28
#define L9965P_REGMAP_CLIENT_NVM_REG_9_ADDR 0x29
#define L9965P_REGMAP_CLIENT_NVM_REG_10_ADDR 0x2A
#define L9965P_REGMAP_CLIENT_NVM_REG_11_ADDR 0x2B
#define L9965P_REGMAP_CLIENT_NVM_REG_12_ADDR 0x2C
#define L9965P_REGMAP_SPECIAL_KEY_ADDR 0x30
#define L9965P_REGMAP_NVM_OP_CMD_ADDR 0x31
#define L9965P_REGMAP_HS_CMD_ADDR 0x32
#define L9965P_REGMAP_LS_CMD_ADDR 0x33


#endif
