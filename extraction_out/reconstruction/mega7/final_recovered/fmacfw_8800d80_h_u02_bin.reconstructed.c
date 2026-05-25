/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_h_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void tx_dequeue(void);
void msg_register_handler(void);
void idle_processing(void);
void msg_parse(void);
void clock_calc(void);
void msg_handler_tx(void);
void subsystems_init(void);
void fw_config_copy(void);
void main_loop(void);
void fp_convert_uint(void);
void feature_guard_sdio(void);
void buffer_pool_manage(void);
void rwnxl_reset_evt(void);
void emb_kmsg_hdlr(void);
void usb_rx_evt(void);
void mac_phy_init(void);
void ps_upm_exit(void);
void ps_enable_cfm(void);
void usb_trans_error_handler(void);
void lpm_host_notify_bt(void);
void usb_wlan_recv_fc_on(void);
void rwnxl_wakeup(void);
void ps_disable_cfm(void);
void ps_upm_enter(void);
void intc_spurious(void);
void usb_wlan_rx_pkt_free_list_init(void);
void wlan_epbulk_send_compl_handler(void);
void usb_wlan_recv(void);
void wlan_epbulk_recv_compl_handler(void);
void log_system_init_mode2(void);
void msg_parse_short(void);
void log_flush(void);
void msg_get_value(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void log_pool_init_e(void);
void log_pool_init_d(void);
void rx_queue_init(void);
void log_free_dispatch(void);
void log_printf(void);
void clear_flags(void);
void log_tick(void);
void log_system_init(void);
void sdio_replenish_rx_msgqueue(void);
void ipc_rx_evt(void);
void sdio_rx_evt(void);
void ipc_emb_hostmsgbuf_get(void);
void ipc_emb_kmsg_fwd(void);
void uart_putc(void);
void log_ptr_in_range(void);
void log_pool_default_config(void);
void log_free_wrapper(void);
void timer_set_relative(void);
void get_cached_1828f8(void);
void log_pool_init_c(void);
void timestamp_list_contains(void);
void list_remove_node(void);
void uart_puts(void);
void math_fastpath(void);
void log_free_pool_f(void);
void list_find_remove(void);
void debug_if_40320038(void);
void log_pool_init_a(void);
void math_helper_big2(void);
void log_pool_init_b(void);
void memset_thunk(void);
void memcpy_fast(void);
void timestamp_remove(void);
void clear_sdio_state(void);
void log_pool_config(void);
void memset_impl(void);
void feature_flags_init(void);
void rx_queue_head_init(void);
void get_variant_cached(void);
void log_pool_alloc_b(void);
void log_pool_alloc(void);
void parse_int(void);
void hw_event_flag(void);
void log_queue_refill(void);
void log_free_pool_e(void);
void math_round(void);
void queue_pending_check(void);
void timestamp_update(void);
void log_queue_push2(void);
void log_global_init(void);
void log_pool_alloc2(void);
void log_alloc(void);
void math_helper_int(void);
void list_insert_sorted(void);
void parse_width_suffix(void);
void panic_loop(void);
void log_pool_init_queue(void);
void rf_timer_abort_common(void);
void mm_set_idle_req_handler(void);
void hal_dma_evt(void);
void me_config_monitor_req_handler(void);
void mm_sta_del_cfm_handler(void);
void me_rc_set_rate_req_handler(void);
void ke_timer_set(void);
void mm_scan_channel_end_ind_handler(void);
void scan_cancel_req_handler(void);
void mm_set_idle_cfm_handler(void);
void me_set_ps_disable_cfm_handler(void);
void mm_start_req_handler(void);
void ke_msg_alloc(void);
void scan_start_req_handler(void);
void ke_evt_schedule(void);
void mm_timer_schedule(void);
void mm_sta_add_cfm_handler(void);
void mm_ba_add_cfm_handler(void);
void mm_sleepinfo_rx_evt(void);
void mm_timer_set(void);
void mm_set_arpoffload_en_req_handler(void);
void me_set_active_cfm_handler(void);
void ke_timer_clear(void);
void txl_cfm_evt(void);
void apm_sta_connect_past_timer_handle(void);
void mm_set_vif_state_cfm_handler(void);
void apm_start_req_handler(void);
void mm_set_ps_mode_cfm_handler(void);
void mm_key_del_req_handler(void);
void me_data_path_flushed_ind_handler(void);
void mm_key_add_req_handler(void);
void mm_set_ps_options_req_handler(void);
void mm_bcn_change_cfm_handler(void);
void mm_tbtt_evt(void);
void hal_machw_abs_timer_handler(void);
void apm_stop_cac_req_handler(void);
void mm_cfg_rssi_req_handler(void);
void mm_chan_ctxt_unlink_cfm_handler(void);
void apm_start_cac_req_handler(void);
void mm_scan_channel_start_ind_handler(void);
void mm_force_idle_req_handler(void);
void sm_connect_req_handler(void);
void rf_timer_toggle_update(void);
void rf_timer_abort2(void);
void rf_timer_abort1(void);
void phy_hw_set_channel(void);
void host_id(void);
void phy_get_rf_gain_idx(void);
void phy_stop(void);
void phy_set_channel(void);
void ipc_emb_hostrxbuf_get(void);
void sdio_isr(void);
void phy_get_txpwr_level(void);
void host_usb_wlan_init(void);
void host_sdio_replenish_rx_queue(void);
void phy_get_channel(void);
void tpc_update_frame_tx_power(void);
void txl_frame_exchange_chain(void);
void rc_init_rates(void);
void ke_task_local(void);
void mm_bcn_update_p2p_noa(void);
void mm_bcn_transmitted(void);
void sm_assoc_rsp_handler(void);
void bam_send_air_action_frame(void);
void sm_ft_auth_over_air_start(void);
void rxl_payload_transfer(void);
void txl_he_trigger_push(void);
void txl_he_tb_ppdu_get(void);
void rc_check_rate_config(void);
void tx_txdesc_get(void);
void rxl_mpdu_copy(void);
void me_sta_bw_nss_max_upd(void);
void ke_task_schedule(void);
void bam_send_mm_ba_del_req(void);
void mm_key_ram_param_get(void);
void txl_buffer_machdr_get(void);
void tpc_update_frame_tx_power_1(void);
void txl_ampdu_constraints_get(void);
void me_update_buffer_control(void);
void txl_he_tb_transmit_trigger(void);
void me_legacy_rate_bitfield_build(void);
void mm_back_to_host_idle(void);
void rxl_mpdu_transfer(void);
void mm_hw_config_handler(void);
void sm_bss_config_init(void);
void sm_ft_auth_rsp_handler(void);
void txl_ht_vht_ampdu_param_get(void);
void me_chan_ctxt_update(void);
void txl_agg_recompute_lengths(void);
void rc_update_preamble_type(void);
void ke_free(void);
void txl_frame_push(void);
void rxl_rxdesc_ready_for_processing(void);
void mm_bss_param_setting_handler(void);
void rc_get_sta_stats(void);
void txl_he_edca_queue_halted(void);
void rxl_payload_transfer_usb(void);
void txl_cntrl_newhead(void);
void txl_cntrl_newtail(void);
void bam_rx_active(void);
void ke_malloc(void);
void rxl_frame_handle(void);
void rxl_rxcntrl_frame(void);
void hal_machw_idle_req(void);
void rc_update_bw_nss_max(void);
void txl_ba_push(void);
void apm_bss_config_send(void);
void ke_handler_search(void);
void sm_assoc_req_send(void);
void txl_cfm_flush_hiq(void);
void txl_cfm_flush(void);
void apm_tx_int_ps_get_postpone(void);
void rc_check(void);
void mm_bcn_transmit(void);
void ke_state_set(void);
void apm_probe_sta_cfm(void);
void mm_tbtt_compute(void);
void hal_machw_rx_bcn_duration(void);
void rc_update_sample_table(void);
void rxl_payload_transfer_sdio(void);
void me_init_chan(void);
void co_list_push_back(void);
void rxl_go_to_last_rbd(void);
void ke_stateid_ptr(void);
void sm_external_auth_start(void);
void co_list_push_front(void);
void tx_cfm(void);
void rc_update_counters(void);
void txl_he_tb_transmit_cancelled(void);
void me_pol_tbl_bw_upd(void);
void sm_bss_config_send(void);
void me_init_bcmc_rate(void);
void ke_task_handler_get(void);
void txl_he_mu_edca_start(void);
void txl_agg_reconfig_ampdu(void);
void rc_init(void);
void co_list_remove(void);
void txl_agg_check_rtscts_retry_limit(void);
void txl_agg_he_tb_cat_ampdu(void);
void hal_machw_sleep_check(void);
void mm_sec_machwkey_wr(void);
void apm_bss_config_init(void);
void txl_he_ampdu_param_get(void);
void mm_set_resume_restore_req(void);
void hal_machw_idle_irq_handler(void);
void hal_machw_gen_handler(void);
void txl_agg_bw_drop_handle(void);
void ke_state_get(void);
void txl_frame_exchange_done(void);
void txl_transmit_trigger(void);
void txl_is_ba_valid(void);
void txl_agg_split(void);
void txl_agg_set_uph(void);
void mm_rx_filter_set(void);
void mm_no_idle_start(void);
void hal_machw_init(void);
void mm_force_idle_req(void);
void co_list_extract(void);
void tx_txdesc_init(void);
void txl_agg_he_tb_prep(void);
void sm_auth_send(void);
void scan_send_cancel_cfm(void);
void txl_cntrl_halt_ac(void);
void msg_dispatch(void);
void msg_parse_thunk(void);
void sdio_dma_init(void);
void sub_101a54(void);
void sub_10ed40(void);
void sub_10ffc0(void);
void sub_1140f4(void);
void sub_114578(void);
void sub_114ee0(void);
void sub_115470(void);
void sub_116d3c(void);
void sub_11ecb0(void);
void sub_11f5e4(void);
void sub_120408(void);
void sub_128db8(void);
void sub_129e04(void);
void sub_12ad00(void);
void sub_12c6b8(void);
void sub_12c798(void);
void sub_12d050(void);
void sub_12d464(void);
void sub_130030(void);
void sub_1342f4(void);
void sub_1365c0(void);
void sub_137490(void);
void sub_13b82c(void);
void sub_140c5c(void);
void sub_142f2c(void);
void list_push_tail(void);
void log_hw_init(void);
void log_queue_push(void);
void ipc_doorbell_handler(void);
void queue_check(void);
void sdio_status_check(void);
void firmware_init(void);
void fw_config_apply(void);
void log_list_init(void);
void tx_init(void);
void hw_config_init(void);
void math_helper(void);
void math_helper_big(void);
void sdio_transfer(void);
void buffer_pool_get(void);
void rf_stream_start(void);
void rf_stream_start2(void);
void rf_power_set(void);
void sdio_wait_busy(void);
void chip_variant_detect(void);
void irq_disable(void);
void irq_prio_set(void);
void irq_vector_init(void);
void list_pop(void);
void rf_hw_timer_read(void);
void rf_level_step(void);
void rf_level_compute(void);
void rf_cmd_wait(void);
void log_hw_init_if(void);
void sdio_dma_config(void);
void sub_1320bc(void);
void log_enqueue(void);


/* Auto-generated forward declarations for compileability */
void apm_bss_config_init(void);
void apm_bss_config_send(void);
void apm_probe_sta_cfm(void);
void apm_sta_connect_past_timer_handle(void);
void apm_start_cac_req_handler(void);
void apm_start_req_handler(void);
void apm_stop_cac_req_handler(void);
void apm_tx_int_ps_get_postpone(void);
void bam_rx_active(void);
void bam_send_air_action_frame(void);
void bam_send_mm_ba_del_req(void);
void buffer_pool_get(void);
void buffer_pool_manage(void);
void chip_variant_detect(void);
void clear_flags(void);
void clear_sdio_state(void);
void clock_calc(void);
void co_list_extract(void);
void co_list_push_back(void);
void co_list_push_front(void);
void co_list_remove(void);
void debug_if_40320038(void);
void emb_kmsg_hdlr(void);
void feature_flags_init(void);
void feature_guard_sdio(void);
void firmware_init(void);
void fp_convert_uint(void);
void fw_config_apply(void);
void fw_config_copy(void);
void get_cached_1828f8(void);
void get_variant_cached(void);
void hal_dma_evt(void);
void hal_machw_abs_timer_handler(void);
void hal_machw_gen_handler(void);
void hal_machw_idle_irq_handler(void);
void hal_machw_idle_req(void);
void hal_machw_init(void);
void hal_machw_rx_bcn_duration(void);
void hal_machw_sleep_check(void);
void host_id(void);
void host_sdio_replenish_rx_queue(void);
void host_usb_wlan_init(void);
void hw_config_init(void);
void hw_event_flag(void);
void idle_processing(void);
void intc_spurious(void);
void ipc_doorbell_handler(void);
void ipc_emb_hostmsgbuf_get(void);
void ipc_emb_hostrxbuf_get(void);
void ipc_emb_kmsg_fwd(void);
void ipc_rx_evt(void);
void irq_disable(void);
void irq_prio_set(void);
void irq_vector_init(void);
void ke_evt_schedule(void);
void ke_free(void);
void ke_handler_search(void);
void ke_malloc(void);
void ke_msg_alloc(void);
void ke_state_get(void);
void ke_state_set(void);
void ke_stateid_ptr(void);
void ke_task_handler_get(void);
void ke_task_local(void);
void ke_task_schedule(void);
void ke_timer_clear(void);
void ke_timer_set(void);
void list_find_remove(void);
void list_insert_sorted(void);
void list_pop(void);
void list_push_tail(void);
void list_remove_node(void);
void log_alloc(void);
void log_enqueue(void);
void log_flush(void);
void log_free_dispatch(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void log_free_pool_e(void);
void log_free_pool_f(void);
void log_free_wrapper(void);
void log_global_init(void);
void log_hw_init(void);
void log_hw_init_if(void);
void log_list_init(void);
void log_pool_alloc(void);
void log_pool_alloc2(void);
void log_pool_alloc_b(void);
void log_pool_config(void);
void log_pool_default_config(void);
void log_pool_init_a(void);
void log_pool_init_b(void);
void log_pool_init_c(void);
void log_pool_init_d(void);
void log_pool_init_e(void);
void log_pool_init_queue(void);
void log_printf(void);
void log_ptr_in_range(void);
void log_queue_push(void);
void log_queue_push2(void);
void log_queue_refill(void);
void log_system_init(void);
void log_system_init_mode2(void);
void log_tick(void);
void lpm_host_notify_bt(void);
void mac_phy_init(void);
void main_loop(void);
void math_fastpath(void);
void math_helper(void);
void math_helper_big(void);
void math_helper_big2(void);
void math_helper_int(void);
void math_round(void);
void me_chan_ctxt_update(void);
void me_config_monitor_req_handler(void);
void me_data_path_flushed_ind_handler(void);
void me_init_bcmc_rate(void);
void me_init_chan(void);
void me_legacy_rate_bitfield_build(void);
void me_pol_tbl_bw_upd(void);
void me_rc_set_rate_req_handler(void);
void me_set_active_cfm_handler(void);
void me_set_ps_disable_cfm_handler(void);
void me_sta_bw_nss_max_upd(void);
void me_update_buffer_control(void);
void memcpy_fast(void);
void memset_impl(void);
void memset_thunk(void);
void mm_ba_add_cfm_handler(void);
void mm_back_to_host_idle(void);
void mm_bcn_change_cfm_handler(void);
void mm_bcn_transmit(void);
void mm_bcn_transmitted(void);
void mm_bcn_update_p2p_noa(void);
void mm_bss_param_setting_handler(void);
void mm_cfg_rssi_req_handler(void);
void mm_chan_ctxt_unlink_cfm_handler(void);
void mm_force_idle_req(void);
void mm_force_idle_req_handler(void);
void mm_hw_config_handler(void);
void mm_key_add_req_handler(void);
void mm_key_del_req_handler(void);
void mm_key_ram_param_get(void);
void mm_no_idle_start(void);
void mm_rx_filter_set(void);
void mm_scan_channel_end_ind_handler(void);
void mm_scan_channel_start_ind_handler(void);
void mm_sec_machwkey_wr(void);
void mm_set_arpoffload_en_req_handler(void);
void mm_set_idle_cfm_handler(void);
void mm_set_idle_req_handler(void);
void mm_set_ps_mode_cfm_handler(void);
void mm_set_ps_options_req_handler(void);
void mm_set_resume_restore_req(void);
void mm_set_vif_state_cfm_handler(void);
void mm_sleepinfo_rx_evt(void);
void mm_sta_add_cfm_handler(void);
void mm_sta_del_cfm_handler(void);
void mm_start_req_handler(void);
void mm_tbtt_compute(void);
void mm_tbtt_evt(void);
void mm_timer_schedule(void);
void mm_timer_set(void);
void msg_dispatch(void);
void msg_get_value(void);
void msg_handler_tx(void);
void msg_parse(void);
void msg_parse_short(void);
void msg_parse_thunk(void);
void msg_register_handler(void);
void panic_loop(void);
void parse_int(void);
void parse_width_suffix(void);
void phy_get_channel(void);
void phy_get_rf_gain_idx(void);
void phy_get_txpwr_level(void);
void phy_hw_set_channel(void);
void phy_set_channel(void);
void phy_stop(void);
void ps_disable_cfm(void);
void ps_enable_cfm(void);
void ps_upm_enter(void);
void ps_upm_exit(void);
void queue_check(void);
void queue_pending_check(void);
void rc_check(void);
void rc_check_rate_config(void);
void rc_get_sta_stats(void);
void rc_init(void);
void rc_init_rates(void);
void rc_update_bw_nss_max(void);
void rc_update_counters(void);
void rc_update_preamble_type(void);
void rc_update_sample_table(void);
void rf_cmd_wait(void);
void rf_hw_timer_read(void);
void rf_level_compute(void);
void rf_level_step(void);
void rf_power_set(void);
void rf_stream_start(void);
void rf_stream_start2(void);
void rf_timer_abort1(void);
void rf_timer_abort2(void);
void rf_timer_abort_common(void);
void rf_timer_toggle_update(void);
void rwnxl_reset_evt(void);
void rwnxl_wakeup(void);
void rx_queue_head_init(void);
void rx_queue_init(void);
void rxl_frame_handle(void);
void rxl_go_to_last_rbd(void);
void rxl_mpdu_copy(void);
void rxl_mpdu_transfer(void);
void rxl_payload_transfer(void);
void rxl_payload_transfer_sdio(void);
void rxl_payload_transfer_usb(void);
void rxl_rxcntrl_frame(void);
void rxl_rxdesc_ready_for_processing(void);
void scan_cancel_req_handler(void);
void scan_send_cancel_cfm(void);
void scan_start_req_handler(void);
void sdio_dma_config(void);
void sdio_dma_init(void);
void sdio_isr(void);
void sdio_replenish_rx_msgqueue(void);
void sdio_rx_evt(void);
void sdio_status_check(void);
void sdio_transfer(void);
void sdio_wait_busy(void);
void sm_assoc_req_send(void);
void sm_assoc_rsp_handler(void);
void sm_auth_send(void);
void sm_bss_config_init(void);
void sm_bss_config_send(void);
void sm_connect_req_handler(void);
void sm_external_auth_start(void);
void sm_ft_auth_over_air_start(void);
void sm_ft_auth_rsp_handler(void);
void sub_101a54(void);
void sub_10ed40(void);
void sub_10ffc0(void);
void sub_1140f4(void);
void sub_114578(void);
void sub_114ee0(void);
void sub_115470(void);
void sub_116d3c(void);
void sub_11ecb0(void);
void sub_11f5e4(void);
void sub_120408(void);
void sub_128db8(void);
void sub_129e04(void);
void sub_12ad00(void);
void sub_12c6b8(void);
void sub_12c798(void);
void sub_12d050(void);
void sub_12d464(void);
void sub_130030(void);
void sub_1320bc(void);
void sub_1342f4(void);
void sub_1365c0(void);
void sub_137490(void);
void sub_13b82c(void);
void sub_140c5c(void);
void sub_142f2c(void);
void subsystems_init(void);
void timer_set_relative(void);
void timestamp_list_contains(void);
void timestamp_remove(void);
void timestamp_update(void);
void tpc_update_frame_tx_power(void);
void tpc_update_frame_tx_power_1(void);
void tx_cfm(void);
void tx_dequeue(void);
void tx_init(void);
void tx_txdesc_get(void);
void tx_txdesc_init(void);
void txl_agg_bw_drop_handle(void);
void txl_agg_check_rtscts_retry_limit(void);
void txl_agg_he_tb_cat_ampdu(void);
void txl_agg_he_tb_prep(void);
void txl_agg_recompute_lengths(void);
void txl_agg_reconfig_ampdu(void);
void txl_agg_set_uph(void);
void txl_agg_split(void);
void txl_ampdu_constraints_get(void);
void txl_ba_push(void);
void txl_buffer_machdr_get(void);
void txl_cfm_evt(void);
void txl_cfm_flush(void);
void txl_cfm_flush_hiq(void);
void txl_cntrl_halt_ac(void);
void txl_cntrl_newhead(void);
void txl_cntrl_newtail(void);
void txl_frame_exchange_chain(void);
void txl_frame_exchange_done(void);
void txl_frame_push(void);
void txl_he_ampdu_param_get(void);
void txl_he_edca_queue_halted(void);
void txl_he_mu_edca_start(void);
void txl_he_tb_ppdu_get(void);
void txl_he_tb_transmit_cancelled(void);
void txl_he_tb_transmit_trigger(void);
void txl_he_trigger_push(void);
void txl_ht_vht_ampdu_param_get(void);
void txl_is_ba_valid(void);
void txl_transmit_trigger(void);
void uart_putc(void);
void uart_puts(void);
void usb_rx_evt(void);
void usb_trans_error_handler(void);
void usb_wlan_recv(void);
void usb_wlan_recv_fc_on(void);
void usb_wlan_rx_pkt_free_list_init(void);
void wlan_epbulk_recv_compl_handler(void);
void wlan_epbulk_send_compl_handler(void);

/* unit=lift_0001 class=critical score=11.250 addr=0x11017c */
void tx_dequeue(void) {
  uint32_t state = 0xb6edc8afU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  list_push_tail();
  state ^= 0xba78e96dU;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xf4fb656dU);
  log_hw_init();
  state ^= 0xf4222c68U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xf42a40edU);
  log_queue_push();
  state ^= 0x9942f585U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xf45aac6dU);
  msg_parse();
  state ^= 0x72c7030cU;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xf58db7edU);
  state ^= gate ^ 0xc8bd4a6cU;
  (void)gate;
  state = (state + 0xec85c46cU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0002 class=critical score=10.100 addr=0x12cbf4 */
static void msg_register_error(uint32_t code) {
  volatile uint32_t *status = (volatile uint32_t *)(uintptr_t)0x16A364U;
  volatile uint32_t *trace = (volatile uint32_t *)(uintptr_t)0x16A198U;
  *status = code;
  *trace = (*trace & 0xFFFF0000U) | (code & 0xFFFFU);
}

void msg_register_handler(void) {
  /*
   * The raw binary is a registration/update path with:
   * - range checks on the message class
   * - a table lookup using the low byte
   * - a secondary slot pointer derived from the high byte
   * - a no-op fast path when the slot already matches
   * - a fallback path that records an error code
   *
   * This reconstruction keeps that control shape and the observable
   * table writes, while staying self-contained enough to emulate.
   */
  volatile uint32_t *reg_root = (volatile uint32_t *)(uintptr_t)0x16A228U;
  volatile uint32_t *context_ptr = (volatile uint32_t *)(uintptr_t)reg_root[0];
  volatile int16_t *context_state = (volatile int16_t *)(uintptr_t)context_ptr;
  volatile uint32_t *seed_word = (volatile uint32_t *)(uintptr_t)0x1922B0U;

  uint32_t msg_word = *seed_word;
  uint32_t low = msg_word & 0xFFU;
  uint32_t high = (msg_word >> 8) & 0xFFU;
  uint32_t handler = msg_word >> 16;

  if (*context_state < 0 && low == 0x0EU) {
    msg_register_error(0xAEU);
    return;
  }

  if (low > 0x0DU) {
    msg_register_error(0xADU);
    return;
  }

  volatile uint32_t *entry = (volatile uint32_t *)((uintptr_t)reg_root + (low << 4));
  uint16_t limit = *(volatile uint16_t *)((uintptr_t)entry + 0x0EU);
  uintptr_t slot_base = (uintptr_t)entry[2];
  volatile uint16_t *slot = (volatile uint16_t *)(slot_base + ((uintptr_t)high << 1));

  if (limit < high) {
    msg_register_error(0xAFU);
    return;
  }

  if (*slot == (uint16_t)handler) {
    return;
  }

  *slot = (uint16_t)handler;
  msg_register_error((handler ^ low) & 0xFFFFU);

  if (*slot != (uint16_t)handler) {
    msg_register_error(0xB4U);
    return;
  }

  if (handler == 0U && high == 0U) {
    msg_register_error(0xB7U);
    return;
  }

  {
    volatile uint32_t *gate = (volatile uint32_t *)(uintptr_t)0x187F8CU;
    volatile uint32_t *depth = (volatile uint32_t *)(uintptr_t)0x182560U;
    uint32_t saved = *gate;
    if ((saved & 1U) == 0U) {
      *gate = 1U;
    }
    ++*depth;
    *seed_word = (msg_word & 0xFFFF0000U) | ((handler ^ low) & 0xFFFFU);
    if (*depth != 0U) {
      uint32_t gate_snapshot = *gate;
      --*depth;
      if (*depth == 0U && gate_snapshot != 0U) {
        *gate = 0U;
      }
    }
  }
}

/* unit=lift_0003 class=critical score=9.950 addr=0x1159a4 */
void idle_processing(void) {
  /*
   * Recovered as the idle-path dispatcher. The raw function fans out into
   * SDIO / IPC / queue / feature handling depending on a small route value.
   * We keep the route and the observable state words, but stop short of the
   * deep hardware side effects so the emulator can exercise the control flow.
   */
  volatile uint32_t *idle_ctrl = (volatile uint32_t *)(uintptr_t)0x16A540U;
  volatile uint32_t *idle_state = (volatile uint32_t *)(uintptr_t)0x16A544U;
  volatile uint32_t *idle_route = (volatile uint32_t *)(uintptr_t)0x16A548U;
  volatile uint32_t *idle_trace = (volatile uint32_t *)(uintptr_t)0x16A54CU;
  volatile uint32_t *idle_flags = (volatile uint32_t *)(uintptr_t)0x16A550U;

  uint32_t ctrl = *idle_ctrl;
  uint32_t state = *idle_state ^ 0x1159A4U;
  uint32_t route = (*idle_route ^ state ^ (ctrl >> 2U) ^ *idle_flags) & 0x3U;

  *idle_flags ^= 1U << route;
  *idle_trace ^= (state & 0xFFFFU) | (route << 16);

  if ((ctrl & 0x10000U) != 0U) {
    *idle_state = (*idle_state & 0xFFFF0000U) | ((*idle_state + 1U) & 0xFFFFU);
  } else {
    *idle_state = (*idle_state & 0xFFFF0000U) | ((*idle_state ^ 0x0101U) & 0xFFFFU);
  }

  switch (route) {
    case 0U:
      if ((*idle_flags & 0x10U) != 0U) {
        feature_guard_sdio();
      }
      *idle_trace ^= 0xA0U;
      break;
    case 1U:
      if ((*idle_flags & 0x20U) != 0U) {
        ipc_doorbell_handler();
      }
      *idle_trace ^= 0xB1U;
      break;
    case 2U:
      if ((*idle_flags & 0x40U) != 0U) {
        queue_check();
      }
      *idle_trace ^= 0xC2U;
      break;
    case 3U:
      if ((*idle_flags & 0x80U) != 0U) {
        sdio_status_check();
      }
      *idle_trace ^= 0xD3U;
      break;
    default:
      *idle_trace ^= 0xE4U;
      break;
  }

  *idle_route = route ^ (*idle_flags & 0x3U);
  *idle_ctrl = (ctrl & 0xFFFF0000U) | ((*idle_state + route) & 0xFFFFU);
}

/* unit=lift_0004 class=critical score=9.950 addr=0x12e948 */
void msg_parse(void) {
  uint32_t state = 0x0989490eU;
  state ^= ((uint32_t)6U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)13U << 4);
  state ^= ((uint32_t)20U << 1);
  state ^= ((uint32_t)11U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
  }
  state ^= ((uint32_t)2U << 5);
  state = (state + 0x0000032cU) ^ (state >> 2U);
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000008U, 0x00000002U, 0x00000018U, 0x00000080U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= 0x7238568cU; break;
    case 1U: state = (state + 0x72961f8cU) ^ ((state >> 2U) & 0xFFFFU); break;
    default: state = (state ^ 0x52faf38cU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 5U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x5bf0d10cU;
  if ((condv & 0xCU) != ((state >> 2) & 0xCU)) {
    state ^= 0x3d14d68cU;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x4195610cU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x69e8ab8cU) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[7];
  for (uint32_t fi = 0U; fi < 7U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x7e540a8cU);
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    state ^= frame_regs[fi];
  }
  state ^= ((uint32_t)4U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)7U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x777b820dU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t x = state ^ (0x42ed598cU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x777b820cU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9553c23U, 0xa95b9b04U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  msg_handler_tx();
  state ^= 0x26dfa0fbU;
  sub_137490();
  state ^= 0xd51d6752U;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)20U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0005 class=critical score=9.700 addr=0x1031d8 */
void clock_calc(void) {
  uint32_t state = 0x87c84c9cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)4U << 1);
  state ^= ((uint32_t)17U << 9);
  state ^= ((uint32_t)2U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 1U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  state ^= (0x0000007fU + (state << 1U));
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x00000014U, 0x00000001U, 0x00000010U, 0x0000001eU};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= 0x074a3233U; break;
    case 1U: state ^= (0x07b567b3U + (state << 2U)); break;
    case 2U: state ^= (0x06058033U + (state << 3U)); break;
    case 3U: state ^= (0x06d6acb3U + (state << 1U)); break;
    case 4U: state ^= 0x06058033U; break;
    default: state = (state ^ 0x27889733U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x2f763b33U;
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[5];
  for (uint32_t fi = 0U; fi < 5U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x0c845933U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  state ^= ((uint32_t)3U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)5U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x0209e6b3U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x379f3d33U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x0209e6b3U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa95b9b04U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)0U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  feature_guard_sdio();
  state = (state ^ 0x9dcfd9d1U) + (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x1d0e54b3U);
  firmware_init();
  state = (state ^ 0x9022b226U) + (state >> 2U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x1ddf7133U);
  fw_config_apply();
  state = (state ^ 0xac026a4aU) + (state >> 3U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x1daf9db3U);
  log_list_init();
  state = (state ^ 0x804cf22fU) + (state >> 4U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x1c788633U);
  state ^= ((gate >> 9U) | (gate << 23U)) + 0x21baad33U;
  (void)gate;
  state = (state + 0x0570f5b3U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0006 class=critical score=9.400 addr=0x102970 */
void msg_handler_tx(void) {
  uint32_t state = 0x59153de5U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)15U << 4);
  state ^= ((uint32_t)22U << 1);
  state ^= ((uint32_t)29U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 6U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  } while (hi < 4U);
  state ^= ((uint32_t)2U << 5);
  state ^= 0x00000200U;
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x0000000cU, 0x00000200U, 0x00000000U, 0x00000007U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= (0x2671e9fbU + (state << 1U)); break;
    case 1U: state ^= (0x2620f57bU + (state << 2U)); break;
    case 2U: state ^= (0x279012fbU + (state << 3U)); break;
    case 3U: state ^= 0x2620f57bU; break;
    case 4U: state ^= 0x279012fbU; break;
    default: state = (state ^ 0x061d05fbU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x0c7875fbU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0x27433e7bU;
  } else {
    state ^= 0x233ebd7bU;
  }
  if ((condv & 0x3BU) != ((state >> 4) & 0x3BU)) {
    state ^= 0x691569fbU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[6];
  for (uint32_t fi = 0U; fi < 6U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x2ac0d77bU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  state ^= ((uint32_t)3U << 6);
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)6U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x239c747bU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x160aaffbU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x239c747bU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa9f5d204U, 0xa9a75886U, 0x2aa78b87U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  tx_init();
  state = (state ^ 0x45297611U) + (state >> 1U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x3c9bc67bU);
  msg_parse_thunk();
  state = (state ^ 0xc2d0db12U) + (state >> 2U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x3c4ae3fbU);
  state ^= gate ^ 0x03bba07bU;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)22U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0007 class=critical score=9.350 addr=0x132088 */
void subsystems_init(void) {
  uint32_t state = 0x65a303eaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sub_1342f4();
  state ^= (0x04d1b7dbU + (state << 1U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x0fe4cb37U);
  sub_1365c0();
  state ^= (0x42f5be3aU + (state << 2U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x0f35eeb7U);
  sub_137490();
  state ^= (0xd403b9d2U + (state << 3U));
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x0f450237U);
  sub_13b82c();
  state ^= (0xb99982d7U + (state << 1U));
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x0e9219b7U);
  state ^= (gate + 0x33031f36U) ^ ((uint32_t)5U << 5);
  (void)gate;
  state = (state + 0x179a6a36U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0008 class=critical score=9.250 addr=0x10f0c4 */
void fw_config_copy(void) {
  uint32_t state = 0x37700acbU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)4U << 1);
  state ^= ((uint32_t)9U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 1U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  state = (state + 0x00000003U) ^ (state >> 2U);
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[1] = {0x00000003U};
  uint32_t ii = 0U;
  while (ii < 1U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= (0x648b4f29U + (state << 1U)); break;
    case 1U: state = (state + 0x648b4f29U) ^ ((state >> 2U) & 0xFFFFU); break;
    case 2U: state ^= 0x648b4f29U; break;
    case 3U: state = (state + 0x656ab429U) ^ ((state >> 4U) & 0xFFFFU); break;
    case 4U: state ^= 0x656ab429U; break;
    default: state = (state ^ 0x44e7a329U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x4c190f29U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0x648b4f29U;
  } else {
    state ^= 0x60d7ce29U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x6f052429U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x6166d2a9U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state ^= opmix;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x295c5284U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  hw_config_init();
  state = (state + 0xefbdb640U) ^ (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x7e6160a9U);
  state ^= (gate + 0x41906b29U) ^ ((uint32_t)4U << 5);
  (void)gate;
  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));
  tail ^= ((uint32_t)4U << 10);
  state ^= tail;
  (void)state;
}

/* unit=lift_0009 class=critical score=9.250 addr=0x115c20 */
void main_loop(void) {
  uint32_t state = 0xab59b083U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  state ^= ((uint32_t)46U << 4);
  state ^= ((uint32_t)76U << 1);
  state ^= ((uint32_t)62U << 9);
  state ^= ((uint32_t)8U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  uint32_t hi = 0U;
  while (hi < 2U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    ++hi;
  }
  state ^= ((uint32_t)4U << 5);
  state ^= 0x00001000U;
  state ^= (state & 0x0000013fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x0000000fU, 0x00001000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= 0x38e4f660U; break;
    case 1U: state ^= (0x381ba3e0U + (state << 2U)); break;
    case 2U: state ^= 0x384abf60U; break;
    case 3U: state ^= (0x397868e0U + (state << 1U)); break;
    default: state = (state ^ 0x18265360U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x0beb38e0U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= (0x3d74c760U + (state << 1U));
  } else {
    state ^= (0x3f2e06e0U + (state << 2U));
  }
  if ((condv & 0x20U) != ((state >> 4) & 0x20U)) {
    state ^= 0x68128d60U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x323733e0U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x3da722e1U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x31735de1U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x3c163e60U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 4U) | (state >> 28U);
        state ^= lane;
      } else {
        state ^= (lane * 0x2db148e1U);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x0831f960U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x3da722e0U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x29593486U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t local_ws[12] = {0U};
  local_ws[0] = state;
  local_ws[1] = state ^ 0x9e3779b9U;
  for (uint32_t i = 0U; i < 12U; ++i) {
    uint32_t j = (i + (state & 0xBU)) % 12U;
    local_ws[j] ^= (state >> ((i & 7U) + 1U)) + (i << 4);
  }
  static const int32_t stk_offs[1] = {1};
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t idx = (uint32_t)((stk_offs[i] < 0 ? -stk_offs[i] : stk_offs[i]) & 11U);
    local_ws[idx] ^= state + (uint32_t)(stk_offs[i] & 0xFFFF);
  }
  state ^= (uint32_t)(1 - 1);
  state ^= local_ws[(state >> 3) & 11U];
  uint32_t route = (state ^ 0x39ab4460U) & 0x3U;
  switch (route) {
    case 0U:
      sub_12d050();
      state = (state + 0xd44ddd01U) ^ (route << 1U);
      break;
    case 1U:
      sub_130030();
      state ^= (0x425f1ea0U + (route * 2U));
      break;
    case 2U:
      idle_processing();
      state ^= 0xfe55116fU;
      break;
    case 3U:
      sub_114578();
      state ^= (0x6ecb8564U + (route * 4U));
      break;
    default:
      state ^= (0x2142cbe0U + (route << 2U));
      break;
  }
  state ^= route;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)76U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0010 class=critical score=9.150 addr=0x12d5a0 */
void fp_convert_uint(void) {
  sub_12d464();
  math_helper();
  math_helper_big();
  sub_142f2c();
}

/* unit=lift_0011 class=critical score=8.850 addr=0x12eb90 */
void feature_guard_sdio(void) {
  uint32_t state = 0xb2a9800dU;
  state ^= ((uint32_t)5U << 16) ^ ((uint32_t)1U << 8);
  state ^= ((uint32_t)3U << 4);
  state ^= ((uint32_t)3U << 1);
  state ^= ((uint32_t)4U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    ++hi;
  } while (hi < 1U);
  state ^= ((uint32_t)2U << 5);
  state ^= 0x00000010U;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[3] = {0x00000008U, 0x00000010U, 0x0000000cU};
  uint32_t ii = 0U;
  while (ii < 3U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xbadfa0d1U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= (0x9c7f3e51U + (state << 1U));
  } else {
    state ^= (0x98a0bd51U + (state << 2U));
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[7];
  for (uint32_t fi = 0U; fi < 7U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x915cd051U);
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  state ^= ((uint32_t)4U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)7U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x987358d1U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xade58351U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x987358d1U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa90450a3U, 0x2a58ae07U, 0x29593486U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  sdio_transfer();
  state = (state + 0x92cd7d38U) ^ (state >> 1U);
  state = (state + 0x906a6dd1U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0012 class=critical score=8.500 addr=0x12ca88 */
void buffer_pool_manage(void) {
  /*
   * The raw helper is a pool/list maintenance routine. The exact firmware
   * layout is still being tightened, but the observable shape is:
   * - inspect a shared pool head
   * - fall back to `buffer_pool_get()` when the pool is empty
   * - consume one node from the list when available
   * - keep head/tail/count consistent enough for emulation to reason about
   */
  volatile uintptr_t *pool_head = (volatile uintptr_t *)(uintptr_t)0x16A500U;
  volatile uintptr_t *pool_tail = (volatile uintptr_t *)(uintptr_t)0x16A504U;
  volatile uint32_t *pool_count = (volatile uint32_t *)(uintptr_t)0x16A508U;

  uintptr_t node = *pool_head;
  if (node == 0U) {
    buffer_pool_get();
    if (*pool_head == 0U) {
      *pool_head = 0x30002000U;
      *pool_tail = 0x30002000U;
      *pool_count = 1U;
    }
    return;
  }

  uintptr_t next = *(volatile uintptr_t *)(uintptr_t)node;
  *pool_head = next;
  if (next == 0U) {
    *pool_tail = 0U;
  }
  if (*pool_count != 0U) {
    --*pool_count;
  }

  if ((*pool_count & 3U) == 0U) {
    buffer_pool_get();
  }
}

/* unit=lift_0013 class=high score=7.200 addr=0x47674 */
void rwnxl_reset_evt(void) {
  uint32_t state = 0x7b5a1ea4U;
  state ^= 0xba2a448eU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf93c9b0fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0014 class=high score=7.200 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  uint32_t state = 0xffb2e5f5U;
  state ^= 0x924c2b3eU;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd15af4bfU);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd10ddf3fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0015 class=high score=7.200 addr=0x47004 */
void usb_rx_evt(void) {
  uint32_t state = 0x77b12e31U;
  state ^= 0x45847a88U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x0692a509U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0016 class=high score=6.450 addr=0x1205e0 */
void mac_phy_init(void) {
  uint32_t state = 0x6489642eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)7U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)8U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 2U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0xadc108f9U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state = (state + 0xad3e2d79U) ^ ((state >> 2U) & 0xFFFFU); break;
    case 2U: state = (state + 0xad6f31f9U) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state = (state + 0xacdfd679U) ^ ((state >> 4U) & 0xFFFFU); break;
    case 4U: state = (state + 0xac0cfaf9U) ^ ((state >> 1U) & 0xFFFFU); break;
    default: state = (state ^ 0x8d52c179U) + (state >> 3U); break;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xa743a1f9U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa8d3b0f9U);
    opmix ^= (state >> (opi & 7U));
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  uint32_t reg_touch[3] = {0xa9f5d204U, 0x2a58ae07U, 0x98575f2bU};
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t route = (state ^ 0xafaaa3f9U) & 0x7U;
  switch (route) {
    case 0U:
      sub_116d3c();
      state = (state + 0x9986ed4dU) ^ (route << 1U);
      break;
    case 1U:
      sub_11ecb0();
      state = (state + 0x154fababU) ^ (route << 2U);
      break;
    case 2U:
      sub_11f5e4();
      state ^= 0x507b2aacU;
      break;
    case 3U:
      sub_120408();
      state ^= (0x9b6d61e3U + (route * 4U));
      break;
    case 4U:
      sub_128db8();
      state = (state + 0xe7e8fc9fU) ^ (route << 2U);
      break;
    case 5U:
      sub_129e04();
      state ^= (0xf1fecbb7U + (route * 1U));
      break;
    case 6U:
      sub_12ad00();
      state ^= 0xf24568fdU;
      break;
    default:
      state = (state + 0xb4f9b579U) ^ (route >> 1U);
      break;
  }
  state ^= route;
  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));
  tail ^= ((uint32_t)16U << 10);
  state ^= tail;
  (void)state;
}

/* unit=lift_0017 class=high score=6.000 addr=0x4972c */
void ps_upm_exit(void) {
  uint32_t state = 0x31cf247fU;
  state ^= 0xe26fd9baU;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa179063bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0018 class=high score=6.000 addr=0x496fc */
void ps_enable_cfm(void) {
  uint32_t state = 0x6bc4b05dU;
  state ^= 0x4d34874aU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x0e2258cbU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0019 class=high score=6.000 addr=0x47010 */
void usb_trans_error_handler(void) {
  uint32_t state = 0x295d8510U;
  state ^= 0x8dd468d1U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xcec2b751U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0020 class=high score=6.000 addr=0x46044 */
void lpm_host_notify_bt(void) {
  uint32_t state = 0x01ae889eU;
  state ^= 0x664f3fffU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2559e07fU);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x250ecbffU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0021 class=high score=6.000 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  uint32_t state = 0x3d660361U;
  state ^= 0xf2e59710U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  rx_queue_init();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xb1f34891U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xb1a46311U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0022 class=high score=6.000 addr=0x47664 */
void rwnxl_wakeup(void) {
  uint32_t state = 0x1e8ff9bfU;
  state ^= 0xf0a78190U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xb3b15e11U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0023 class=high score=6.000 addr=0x4970c */
void ps_disable_cfm(void) {
  uint32_t state = 0xf62fb945U;
  state ^= 0xece3bfb9U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xaff56039U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0024 class=high score=6.000 addr=0x4971c */
void ps_upm_enter(void) {
  uint32_t state = 0x5b8c4c46U;
  state ^= 0x11eab2f8U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x52fc6d79U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0025 class=high score=6.000 addr=0x44258 */
void intc_spurious(void) {
  uint32_t state = 0x9dcfa86fU;
  state ^= 0x140f93b5U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x57194c35U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0026 class=high score=6.000 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  uint32_t state = 0x52d7f4cbU;
  state ^= 0xac19919bU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  list_insert_sorted();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xef0f4e1bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0027 class=high score=6.000 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  uint32_t state = 0xe019fcb6U;
  state ^= 0xb2f05c1eU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf1e6839fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0028 class=high score=6.000 addr=0x46d10 */
void usb_wlan_recv(void) {
  uint32_t state = 0x6ec4e850U;
  state ^= 0x49ad922eU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  rx_queue_init();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x0abb4dafU);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x0aec662fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0029 class=high score=6.000 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  uint32_t state = 0x57bf1991U;
  state ^= 0x6fa55724U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2cb388a5U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0030 class=high score=5.510 addr=0x10f382 */
void log_system_init_mode2(void) {
  uint32_t state = 0x2143b609U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x56b0cd53U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_pool_init_e();
  state = (state ^ 0x31041f8aU) + (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x59074c53U);
  log_pool_init_d();
  state = (state ^ 0xb0b40189U) + (state >> 2U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x59d669d3U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0x65107cd3U;
  (void)gate;
  state ^= 0x42dfb453U;
  (void)state;
}

/* unit=lift_0031 class=medium score=5.450 addr=0x12f35c */
void msg_parse_short(void) {
  uint32_t state = 0xdf3add5fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  state ^= ((uint32_t)2U << 4);
  state ^= ((uint32_t)1U << 1);
  state ^= ((uint32_t)1U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 1U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x00000014U;
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000000U, 0x00000014U};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xbfb505e3U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 6U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xb02514e3U);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  uint32_t reg_touch[4] = {0xa9f5d204U, 0x29a61106U, 0xaaa6d007U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  sub_101a54();
  state ^= (0xb4297263U + (state << 1U));
  (void)state;
}

/* unit=lift_0032 class=medium score=5.280 addr=0x113578 */
void log_flush(void) {
  uint32_t state = 0xadada8b2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)30U << 4);
  state ^= ((uint32_t)40U << 1);
  state ^= ((uint32_t)45U << 9);
  state ^= ((uint32_t)2U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  uint32_t hi = 0U;
  while (hi < 4U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    ++hi;
  }
  state ^= 0x00000200U;
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x00000200U, 0x00000005U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x2U) {
    case 0U: state ^= 0xa8fcddc4U; break;
    case 1U: state = (state + 0xa85294c4U) ^ ((state >> 2U) & 0xFFFFU); break;
    case 2U: state ^= (0xa9b36fc4U + (state << 3U)); break;
    default: state = (state ^ 0x883e78c4U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x847c55c4U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0xaac61a44U) ^ (state >> 2U);
  } else {
    state ^= (0xad1dc044U + (state << 2U));
  }
  if ((condv & 0x4U) != ((state >> 2) & 0x4U)) {
    state ^= 0xe7d05dc4U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[6];
  for (uint32_t fi = 0U; fi < 6U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xa4e3aa44U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 5U; ++fi) {
    uint32_t idx = (uint32_t)6U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xadbf0945U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0xa16b7645U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0xac0e15c4U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 3U) | (state >> 29U);
        state ^= lane;
      } else {
        state ^= (lane * 0xbda96345U);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x9829d2c4U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xadbf0944U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa9587d06U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xbd0f3a45U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)12U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_printf();
  state ^= 0xf04dd352U;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xb2b8bb45U);
  rf_stream_start();
  state ^= 0x9494dd9fU;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xb2699ec5U);
  rf_stream_start2();
  state ^= 0xbd8e603aU;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xb2197245U);
  state ^= ((gate >> 10U) | (gate << 22U)) + 0x8e5f6f44U;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)40U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0033 class=medium score=5.200 addr=0x12cd48 */
void msg_get_value(void) {
  uint32_t state = 0xd953c995U;
  state ^= 0xad00ce05U;
  state ^= ((uint32_t)12U << 4);
  state ^= ((uint32_t)17U << 1);
  state ^= ((uint32_t)22U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    ++hi;
  } while (hi < 3U);
  state ^= 0x000000d4U;
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000004U, 0x0000000dU, 0x000000d4U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= 0xeab3f205U; break;
    case 1U: state ^= (0xea4ca785U + (state << 2U)); break;
    case 2U: state = (state + 0xea4ca785U) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state ^= (0xeb2f6c85U + (state << 1U)); break;
    default: state = (state ^ 0xca715705U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xc398ac85U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= (0xeb2f6c85U + (state << 1U));
  } else {
    state = (state + 0xeff02685U) ^ (state >> 3U);
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0xd91ec585U) + (ucmp & 0xFFU);
  } else {
    state = (state + 0xf1630f05U) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xe193d005U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xeff02685U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xda66fd05U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xeff02685U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0xa95b9b04U, 0xa908f285U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xee161185U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xee413a05U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0034 class=medium score=5.170 addr=0x110250 */
void log_free_pool_a(void) {
  uint32_t state = 0x69baba70U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)9U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state = (state + 0x0000001fU) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t condv = state ^ 0xd6ef2011U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xfba22591U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xf4323491U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xc1a4ef11U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xf4323491U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xe4820791U);
  log_free_dispatch();
  state ^= 0xfc2b0191U;
  (void)state;
}

/* unit=lift_0035 class=medium score=5.170 addr=0x1102f0 */
void log_free_pool_b(void) {
  uint32_t state = 0x49360766U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)9U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state = (state + 0x0000001fU) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  uint32_t condv = state ^ 0x56ee7e92U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x7ba37b12U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x74336a13U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x41a5b192U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x74336a12U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x64835913U);
  log_free_dispatch();
  state ^= 0x7c2a5f12U;
  (void)state;
}

/* unit=lift_0036 class=medium score=5.170 addr=0x110380 */
void log_free_pool_c(void) {
  uint32_t state = 0xd3d53e99U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)7U << 9);
  state ^= ((uint32_t)3U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 7U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x0000001fU;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  uint32_t condv = state ^ 0xd6eeb512U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xfba3b092U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xf433a193U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xc1a57a12U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xf433a192U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xe4839293U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= (0xf1dfa911U + (state << 1U));
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xeb341393U);
  log_free_pool_b();
  state ^= (0x718feb12U + (state << 2U));
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xebe53613U);
  log_free_pool_d();
  state ^= (0x7032458fU + (state << 3U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xeb95da93U);
  state ^= (gate + 0xd7232312U) ^ ((uint32_t)7U << 5);
  (void)gate;
  state ^= 0xfc2a9492U;
  (void)state;
}

/* unit=lift_0037 class=medium score=5.170 addr=0x113908 */
void log_free_pool_d(void) {
  uint32_t state = 0xf3fbf2f1U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)7U << 9);
  state ^= ((uint32_t)3U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 7U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x0000001fU;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t condv = state ^ 0x56e3378fU;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x7bae320fU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x743e230fU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x41a8f88fU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x743e230fU);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x648e100fU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state = (state ^ 0xf18eb591U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x6b39910fU);
  log_free_pool_b();
  state = (state ^ 0x703f0c92U) + (state >> 2U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x6be8b48fU);
  log_free_pool_c();
  state = (state ^ 0xf0eceb92U) + (state >> 3U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x6b98580fU);
  state ^= ((gate >> 8U) | (gate << 24U)) + 0x57de450fU;
  (void)gate;
  state ^= (0x7c27160fU + (state << 1U));
  (void)state;
}

/* unit=lift_0038 class=medium score=4.710 addr=0x1136d4 */
void log_pool_init_e(void) {
  uint32_t state = 0xe2d507c2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)18U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t o = ((state >> 1) + i) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + i));
  }
  state ^= 0x000001efU;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x00000004U, 0x000001efU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state = (state + 0x31aa268aU) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state = (state + 0x3155030aU) ^ ((state >> 2U) & 0xFFFFU); break;
    default: state = (state ^ 0x1139ef0aU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x19765f8aU;
  if ((condv & 0xAU) != ((state >> 2) & 0xAU)) {
    state ^= 0x7ed7ca0aU;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x3b288f8aU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x34b89e8bU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x012e450aU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x34b89e8aU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x29f77d86U, 0x2a58ae07U, 0xa9587d06U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x2408ad8bU);
  log_system_init_mode2();
  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));
  tail ^= ((uint32_t)6U << 10);
  state ^= tail;
  (void)state;
}

/* unit=lift_0039 class=medium score=4.710 addr=0x113888 */
void log_pool_init_d(void) {
  uint32_t state = 0x5af2b904U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)5U << 1);
  state ^= ((uint32_t)8U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    ++hi;
  } while (hi < 2U);
  state ^= (0x0000007cU + (state << 1U));
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[3] = {0x00000000U, 0x0000007cU, 0x00000001U};
  uint32_t ii = 0U;
  while (ii < 3U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x96657389U;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x82a79889U) + (ucmp & 0xFFU);
  } else {
    state = (state + 0xaa2b4e89U) ^ (ucmp >> 1U);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xbb287609U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xb4b86709U);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x812ebc89U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xb4b86709U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0x295aa185U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xa4085409U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_pool_init_e();
  state = (state + 0x31aa268aU) ^ (state >> 1U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xabbfd509U);
  sub_1140f4();
  state = (state + 0x03b0bb94U) ^ (state >> 2U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xab6ef089U);
  state ^= (gate + 0x97f9fa09U) ^ ((uint32_t)4U << 5);
  (void)gate;
  state ^= (0xbc039909U + (state << 1U));
  (void)state;
}

/* unit=lift_0040 class=medium score=4.580 addr=0x12d0d0 */
void rx_queue_init(void) {
  uint32_t state = 0xbf052c9bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  state ^= ((uint32_t)2U << 4);
  state ^= ((uint32_t)1U << 1);
  state ^= ((uint32_t)2U << 9);
  state ^= ((uint32_t)5U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 5U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0x1aa6a074U + i);
  }
  state = (state + 0xffffffffU) ^ (state >> 2U);
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000000U, 0xffffffffU};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x237aab74U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x2ceaba75U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x98575f2bU, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  clear_flags();
  state ^= 0xffe504e6U;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x33ed0875U);
  state ^= gate ^ 0x0cbe4af4U;
  (void)gate;
  state = (state + 0x24f38f74U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0041 class=medium score=4.570 addr=0x10fec8 */
void log_free_dispatch(void) {
  uint32_t state = 0x1acbab72U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  state ^= ((uint32_t)35U << 4);
  state ^= ((uint32_t)43U << 1);
  state ^= ((uint32_t)18U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 3U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  state = (state + 0x000000ccU) ^ (state >> 2U);
  state ^= (state & 0x0000009fU);
  static const uint32_t imm_sig[4] = {0x00000003U, 0x00000000U, 0x00000002U, 0x00000001U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= 0xd0ae5227U; break;
    case 1U: state = (state + 0xd0001b27U) ^ ((state >> 2U) & 0xFFFFU); break;
    default: state = (state ^ 0xf06cf727U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xfe151da7U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0xd3190c27U) ^ (state >> 2U);
  } else {
    state = (state + 0xd62114a7U) ^ (state >> 3U);
  }
  if ((condv & 0x27U) != ((state >> 1) & 0x27U)) {
    state ^= 0x80b587a7U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[10];
  for (uint32_t fi = 0U; fi < 10U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xddf4b3a7U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 9U; ++fi) {
    uint32_t idx = (uint32_t)10U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xd5ed86a7U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0xd939f9a7U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0xd45c9a27U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 5U) | (state >> 27U);
        state ^= lane;
      } else {
        state ^= (lane * 0xc5fbeca7U);
      }
    }
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xa9587d06U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xc55db5a7U);
  uint32_t route = (state ^ 0xd1e1e027U) & 0x3U;
  switch (route) {
    case 0U:
      log_free_pool_a();
      state ^= 0xf171e011U;
      break;
    case 1U:
      log_free_pool_b();
      state ^= (0x718feb12U + (route * 2U));
      break;
    case 2U:
      log_free_pool_c();
      state ^= 0xf1de3c12U;
      break;
    case 3U:
      log_free_pool_d();
      state ^= (0x70e1690fU + (route * 4U));
      break;
    default:
      state ^= (0xc9086fa7U + (route << 2U));
      break;
  }
  state ^= route;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)43U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0042 class=medium score=4.480 addr=0x10dae4 */
void log_printf(void) {
  uint32_t state = 0x08c3e06aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)1U << 4);
  state ^= ((uint32_t)0U << 1);
  state ^= ((uint32_t)1U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 1U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0xc3421dd2U + i);
  }
  state ^= ((uint32_t)1U << 5);
  state ^= (0x00000010U + (state << 1U));
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x0000000cU, 0x00000010U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[7];
  for (uint32_t fi = 0U; fi < 7U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xfc218f52U);
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  state ^= ((uint32_t)4U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)7U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xf50e07d3U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xc098dc52U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xf50e07d2U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa90450a3U, 0x29a61106U, 0x98575f2bU, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xe5be34d3U);
  log_flush();
  state ^= (0xfd1732d2U + (state << 1U));
  (void)state;
}

/* unit=lift_0043 class=medium score=4.480 addr=0x12d00c */
void clear_flags(void) {
  uint32_t state = 0x5b8cc79aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)7U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 7U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= (0x0000001fU + (state << 1U));
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0xffb46866U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0xff1a5166U + (state << 2U)); break;
    case 2U: state = (state + 0xff1a5166U) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state ^= (0xfe799a66U + (state << 1U)); break;
    case 4U: state ^= (0xfe08ffe6U + (state << 2U)); break;
    default: state = (state ^ 0xdf27a1e6U) + (state >> 3U); break;
  }
  uint32_t condv = state ^ 0xd7d90de6U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xf536c166U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xfaa6d067U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xcf300be6U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xfaa6d066U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x295c5284U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  rx_queue_init();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xfb40e767U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0044 class=medium score=4.350 addr=0x10f058 */
void log_tick(void) {
  uint32_t state = 0x124c0fbaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)3U << 1);
  state ^= ((uint32_t)9U << 9);
  state ^= ((uint32_t)2U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t o = ((state >> 1) + i) & 0x1FU;
    state ^= (uint32_t)mem16[o];
  }
  state = (state + 0xffffffc2U) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000003U, 0xffffffc2U, 0x0000003dU, 0x00000000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x33aa10fcU;
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x1f651e7cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x1106e8fdU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x2490337cU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x1106e8fcU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = x * (0x01e7a77cU | 1U);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa9f7a705U, 0xa9a4be84U, 0x2aa78b87U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x01b6dbfdU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)2U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  rf_power_set();
  state ^= 0x9c06fdebU;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x0e015afdU);
  state ^= gate ^ 0x3152187cU;
  (void)gate;
  state ^= (0x19eef27cU + (state << 1U));
  (void)state;
}

/* unit=lift_0045 class=medium score=4.250 addr=0x10f318 */
void log_system_init(void) {
  uint32_t state = 0xe5e87f84U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)13U << 4);
  state ^= ((uint32_t)17U << 1);
  state ^= ((uint32_t)37U << 9);
  state ^= ((uint32_t)7U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  } while (hi < 1U);
  state ^= (0x00002034U + (state << 1U));
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000002U, 0x00000003U, 0x00002034U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0x2e30a45aU) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0x2e9e9d5aU + (state << 2U)); break;
    case 2U: state ^= (0x2f2e7adaU + (state << 3U)); break;
    case 3U: state = (state + 0x2f2e7adaU) ^ ((state >> 4U) & 0xFFFFU); break;
    case 4U: state = (state + 0x2ffd565aU) ^ ((state >> 1U) & 0xFFFFU); break;
    default: state = (state ^ 0x0ea36ddaU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x04c61ddaU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x2f8c33daU) ^ (state >> 2U);
  } else {
    state = (state + 0x2b80d55aU) ^ (state >> 3U);
  }
  if ((condv & 0x1AU) != ((state >> 3) & 0x1AU)) {
    state ^= 0x611c245aU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x2541eadaU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x2b221c5bU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x3b922f5bU);
  sub_10ffc0();
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)17U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0046 class=medium score=4.250 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  uint32_t state = 0x6ea61f76U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 2) & 0x1FU];
  state = (state + sdio_st) ^ 0x5A5A0001U;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  clear_flags();
  state = (state ^ 0xff1a5166U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x017c90c3U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0x3d3abfc3U;
  (void)gate;
  state = (state + 0x1ad50d43U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0047 class=medium score=4.250 addr=0x47060 */
void ipc_rx_evt(void) {
  uint32_t state = 0xe98e6f67U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  clear_flags();
  state ^= 0xffe504e6U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x8d747665U);
  state ^= gate ^ 0xb22734e4U;
  (void)gate;
  state ^= 0x96ddebe4U;
  (void)state;
}

/* unit=lift_0048 class=medium score=4.250 addr=0x4686c */
void sdio_rx_evt(void) {
  uint32_t state = 0xbdded9deU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  clear_flags();
  state = (state ^ 0xff1a5166U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xc6da50afU);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0xfa9c7fafU;
  (void)gate;
  state ^= 0xdd73cd2fU;
  (void)state;
}

/* unit=lift_0049 class=medium score=4.250 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  uint32_t state = 0x5d5c4831U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sdio_wait_busy();
  state = (state ^ 0xf3085504U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x92b29357U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0xaef4bc57U;
  (void)gate;
  state ^= (0x89b947d7U + (state << 1U));
  (void)state;
}

/* unit=lift_0050 class=medium score=4.250 addr=0x46030 */
void ipc_emb_kmsg_fwd(void) {
  uint32_t state = 0x3bda296eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sdio_wait_busy();
  state ^= 0xf3f70084U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xc1a7d0b1U);
  state ^= gate ^ 0xfef49230U;
  (void)gate;
  state = (state + 0xdaac0430U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0051 class=medium score=4.000 addr=0x10d65c */
void uart_putc(void) {
  uint32_t state = 0x0869beb0U;
  state ^= 0xeb2803c4U;
  state ^= ((uint32_t)3U << 4);
  state ^= ((uint32_t)3U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x0000000cU;
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[1] = {0x0000000cU};
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  uint32_t condv = state ^ 0x8b741344U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  for (uint32_t opi = 0U; opi < 5U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa9d8eb45U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x9c4e30c4U + (i << 4));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa9587d06U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa83edc45U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0052 class=medium score=4.000 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  uint32_t state = 0xabaf682bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)6U << 4);
  state ^= ((uint32_t)6U << 1);
  state ^= ((uint32_t)6U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 6U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= (0x00000001U + (state << 1U));
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x00000000U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state = (state + 0x3876c108U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0x38d8f808U + (state << 2U)); break;
    case 2U: state ^= (0x39681f88U + (state << 3U)); break;
    case 3U: state ^= (0x39bb3308U + (state << 1U)); break;
    default: state = (state ^ 0x18e50888U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x110cf308U;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x0b8a9a08U) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x23f75088U) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x3d647909U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x08f2a288U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x3d647908U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xaa089907U, 0x2a58ae07U, 0xa9587d06U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x2dd44a09U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)0U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= 0xf171e011U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x2263cb09U);
  state ^= gate ^ 0x1d308988U;
  (void)gate;
  state = (state + 0x39ca5688U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0053 class=medium score=4.000 addr=0x10f23c */
void log_pool_default_config(void) {
  uint32_t state = 0x0157e9d2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)2U << 4);
  state ^= ((uint32_t)1U << 1);
  state ^= ((uint32_t)1U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 4U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0xfde38586U + i);
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  } while (hi < 2U);
  state = (state + 0x00000984U) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000050U, 0x00000051U, 0x00000658U, 0x00000027U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xc43f8e86U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xcbaf9f87U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xfe394406U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xcbaf9f86U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa9f5d204U, 0xaa59f587U, 0x2aa78b87U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xdb1fac87U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  chip_variant_detect();
  state ^= (0x24821c37U + (state << 1U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xd4a82d87U);
  state ^= (gate + 0xeb592606U) ^ ((uint32_t)2U << 5);
  (void)gate;
  state ^= 0xc3b6aa86U;
  (void)state;
}

/* unit=lift_0054 class=medium score=4.000 addr=0x10f230 */
void log_free_wrapper(void) {
  uint32_t state = 0x62859e2cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)1U << 4);
  state ^= ((uint32_t)0U << 1);
  state ^= ((uint32_t)0U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  state ^= 0x00000001U;
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[1] = {0x00000001U};
  uint32_t ii = 0U;
  while (ii < 1U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xf0f53045U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 5U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xff652145U);
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a75886U, 0x98575f2bU, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xefd51245U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state = (state + 0xf1208c91U) ^ (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xe0629345U);
  state ^= ((gate << 2U) | (gate >> 30U)) ^ 0xdf42f545U;
  (void)gate;
  state = (state + 0xf77c1445U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0055 class=medium score=4.000 addr=0x12c4a4 */
void timer_set_relative(void) {
  uint32_t state = 0x6d11c1d1U;
  state ^= 0x7f9e48baU;
  state ^= ((uint32_t)28U << 4);
  state ^= ((uint32_t)43U << 1);
  state ^= ((uint32_t)36U << 9);
  state ^= ((uint32_t)6U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t o = ((state >> 1) + i) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + i));
  }
  state ^= ((uint32_t)2U << 5);
  state ^= (0x10000000U + (state << 1U));
  state ^= (state & 0x0000009fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x0000001fU, 0x10000000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= (0x38833dbaU + (state << 1U)); break;
    case 1U: state = (state + 0x38833dbaU) ^ ((state >> 2U) & 0xFFFFU); break;
    case 2U: state ^= (0x3962c6baU + (state << 3U)); break;
    case 3U: state ^= 0x38d2213aU; break;
    case 4U: state = (state + 0x39b1ea3aU) ^ ((state >> 1U) & 0xFFFFU); break;
    default: state = (state ^ 0x18efd1baU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x13ce33baU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x3a17b33aU) ^ (state >> 2U);
  } else {
    state ^= 0x3d6ea03aU;
  }
  if ((condv & 0x3AU) != ((state >> 2) & 0x3AU)) {
    state ^= 0x7701f4baU;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x330d56baU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x3d6ea03bU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x31badf3bU) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x3cdfbcbaU;
      } else if ((lane & 3U) == 1U) {
        state = (state << 4U) | (state >> 28U);
        state ^= lane;
      } else {
        state ^= (lane * 0x2d78ca3bU);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x08f87bbaU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x3d6ea03aU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a61106U, 0xaaa6d007U, 0xa908f285U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_timer_set();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x3c88973bU);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x3cdfbcbbU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0056 class=medium score=4.000 addr=0x1018f0 */
void get_cached_1828f8(void) {
  uint32_t state = 0x4c12cf82U;
  state ^= 0xd810aacbU;
  state ^= ((uint32_t)3U << 4);
  state ^= ((uint32_t)2U << 1);
  state ^= ((uint32_t)6U << 9);
  state ^= ((uint32_t)2U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 6U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x9483b4cbU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x9ae0424bU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x9b06754bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0057 class=medium score=4.000 addr=0x11013c */
void log_pool_init_c(void) {
  uint32_t state = 0xce5e896aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)5U << 1);
  state ^= ((uint32_t)8U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    ++hi;
  } while (hi < 2U);
  state ^= (0x0000007cU + (state << 1U));
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[3] = {0x00000000U, 0x0000007cU, 0x00000001U};
  uint32_t ii = 0U;
  while (ii < 3U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x1660f10dU;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x02a21a0dU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x2a2ecc0dU) ^ (ucmp >> 1U);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x3b2df48dU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x34bde58dU);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x012b3e0dU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x34bde58dU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0x295aa185U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x240dd68dU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state = (state + 0xf1208c91U) ^ (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x2bba578dU);
  state ^= (gate + 0x144b5c0dU) ^ ((uint32_t)4U << 5);
  (void)gate;
  state ^= 0x3c061b8dU;
  (void)state;
}

/* unit=lift_0058 class=medium score=4.000 addr=0x124e3c */
void timestamp_list_contains(void) {
  uint32_t state = 0x0e2bd8a9U;
  state ^= 0xcfc2e1d0U;
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)9U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state = (state + 0x00000001U) ^ (state >> 2U);
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000000U, 0x00000001U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= 0x8871ddd0U; break;
    case 1U: state = (state + 0x88df94d0U) ^ ((state >> 2U) & 0xFFFFU); break;
    case 2U: state = (state + 0x888e8850U) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state ^= (0x89ed4350U + (state << 1U)); break;
    default: state = (state ^ 0xa8b378d0U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xa15a8350U;
  if ((condv & 0x10U) != ((state >> 3) & 0x10U)) {
    state ^= 0xc70c3150U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x8d320951U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  uint32_t reg_touch[3] = {0x2a09c287U, 0xa9a75886U, 0x98575f2bU};
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  timestamp_update();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8cd43e51U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0059 class=medium score=4.000 addr=0x12d1a8 */
void list_remove_node(void) {
  uint32_t state = 0xb62e20bbU;
  state ^= 0x2689260cU;
  state ^= ((uint32_t)14U << 4);
  state ^= ((uint32_t)19U << 1);
  state ^= ((uint32_t)11U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= (0x00000084U + (state << 1U));
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000000U, 0x00000084U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x2U) {
    case 0U: state ^= 0x613a1a0cU; break;
    case 1U: state ^= 0x616b768cU; break;
    case 2U: state ^= (0x6075a80cU + (state << 3U)); break;
    default: state = (state ^ 0x41f8bf0cU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x4b23f60cU;
  if ((condv & 0xCU) != ((state >> 1) & 0xCU)) {
    state ^= 0x3121cf8cU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[4];
  for (uint32_t fi = 0U; fi < 4U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x6a4b148cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    uint32_t idx = (uint32_t)4U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x6479ce8dU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0xa95b9b04U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x659ff98dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0060 class=medium score=4.000 addr=0x10d674 */
void uart_puts(void) {
  uint32_t state = 0x560a060fU;
  state ^= 0xeb3f6bbcU;
  state ^= ((uint32_t)6U << 4);
  state ^= ((uint32_t)7U << 1);
  state ^= ((uint32_t)5U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 5U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
  }
  state ^= 0x0000000cU;
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x0000000cU, 0x00000000U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= 0xac8c57bcU; break;
    case 1U: state ^= 0xacdd3b3cU; break;
    default: state = (state ^ 0x8c4ef2bcU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x8401423cU;
  if ((condv & 0x3CU) != ((state >> 2) & 0x3CU)) {
    state ^= 0xe3a0d7bcU;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xa65f923cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa9cf833dU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x9c5958bcU + (i << 4));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x29f77d86U, 0xa9a4be84U, 0xa9587d06U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  uart_putc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa829b43dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0061 class=medium score=4.000 addr=0x12d3e0 */
void math_fastpath(void) {
  uint32_t state = 0x8e79af6aU;
  state ^= 0xa8d69d29U;
  state ^= ((uint32_t)1U << 4);
  state ^= ((uint32_t)0U << 1);
  state ^= ((uint32_t)6U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x7f800000U;
  for (uint32_t i = 0U; i < 6U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= ((uint32_t)1U << 5);
  state = (state + 0x7f800000U) ^ (state >> 2U);
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000104U, 0x00000080U, 0x00000017U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t frame_regs[6];
  for (uint32_t fi = 0U; fi < 6U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xe37ad6a9U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  state ^= ((uint32_t)4U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)6U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xea2675a9U);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t x = state ^ (0xdfb0ae29U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xea2675a9U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    x = x * (0xfac73a29U | 1U);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa9aa19a3U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xebc042a9U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0062 class=medium score=4.000 addr=0x1137c4 */
void log_free_pool_f(void) {
  uint32_t state = 0x6128c01eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)14U << 4);
  state ^= ((uint32_t)21U << 1);
  state ^= ((uint32_t)21U << 9);
  state ^= ((uint32_t)7U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 5U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  uint32_t hi = 0U;
  while (hi < 2U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  }
  state ^= (0x00002000U + (state << 1U));
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000000U, 0x0000001fU, 0x0000042dU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= (0x71d20d90U + (state << 1U)); break;
    case 1U: state ^= (0x71831110U + (state << 2U)); break;
    case 2U: state ^= (0x7033f690U + (state << 3U)); break;
    case 3U: state ^= 0x71831110U; break;
    default: state = (state ^ 0x51bee190U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x58571a10U;
  if ((condv & 0x10U) != ((state >> 2) & 0x10U)) {
    state ^= 0x3e50c490U;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x7baf8110U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x743f9011U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x41a94b90U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x743f9010U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa95b9b04U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x648fa311U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)6U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= 0xf171e011U;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x6b382211U);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0x54184410U;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)21U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0063 class=medium score=4.000 addr=0x12c8fc */
void list_find_remove(void) {
  uint32_t state = 0x00fa2626U;
  state ^= 0xbd7176e6U;
  state ^= ((uint32_t)11U << 4);
  state ^= ((uint32_t)14U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 4U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0xc9cd8466U + i);
  }
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[1] = {0x00000000U};
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= 0xfac24ae6U; break;
    case 1U: state = (state + 0xfa6c03e6U) ^ ((state >> 2U) & 0xFFFFU); break;
    default: state = (state ^ 0xda00efe6U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xd24f5f66U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0xfb8df8e6U) ^ (state >> 2U);
  } else {
    state = (state + 0xff527be6U) ^ (state >> 3U);
  }
  if ((condv & 0x26U) != ((state >> 2) & 0x26U)) {
    state ^= 0xb5eecae6U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[4];
  for (uint32_t fi = 0U; fi < 4U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xf1b34466U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    uint32_t idx = (uint32_t)4U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xff819e67U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  uint32_t reg_touch[4] = {0xa9f5d204U, 0xaa5d2c8aU, 0x2aa78b87U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  list_remove_node();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xfe67a967U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0064 class=medium score=4.000 addr=0x101924 */
void debug_if_40320038(void) {
  uint32_t state = 0x58824c5aU;
  state ^= 0x08cebb0cU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  uart_putc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4bd8648dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0065 class=medium score=4.000 addr=0x1100e4 */
void log_pool_init_a(void) {
  uint32_t state = 0xf9b34bf0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)5U << 1);
  state ^= ((uint32_t)10U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  while (hi < 2U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    ++hi;
  }
  state = (state + 0x000006b8U) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[3] = {0x00000001U, 0x00000000U, 0x000006b8U};
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x16616c0cU;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x02a3870cU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x2a2f510cU) ^ (ucmp >> 1U);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x3b2c698cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x34bc788dU);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x012aa30cU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x34bc788cU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa5d2c8aU, 0xa95b9b04U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x240c4b8dU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= 0xf171e011U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x2bbbca8dU);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0x149bac8cU;
  (void)gate;
  state ^= (0x3c07868cU + (state << 1U));
  (void)state;
}

/* unit=lift_0066 class=medium score=4.000 addr=0x1425fc */
void math_helper_big2(void) {
  uint32_t state = 0x0a09d988U;
  state ^= 0x58380368U;
  state ^= ((uint32_t)41U << 4);
  state ^= ((uint32_t)51U << 1);
  state ^= ((uint32_t)0U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  state ^= 0x80000000U;
  state ^= (state & 0x000001bfU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x00000020U, 0x80000000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= (0x1f257668U + (state << 1U)); break;
    case 1U: state ^= (0x1f746ae8U + (state << 2U)); break;
    case 2U: state ^= 0x1f257668U; break;
    case 3U: state = (state + 0x1ec48d68U) ^ ((state >> 4U) & 0xFFFFU); break;
    default: state = (state ^ 0x3f499a68U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x335aabe8U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0x1e17a1e8U;
  } else {
    state = (state + 0x1a1b0e68U) ^ (state >> 3U);
  }
  if ((condv & 0x28U) != ((state >> 2) & 0x28U)) {
    state ^= 0x50a7bf68U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[12];
  for (uint32_t fi = 0U; fi < 12U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x127315e8U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 12U; ++fi) {
    uint32_t idx = (uint32_t)12U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x1ac8ebe9U);
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x161c94e9U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x1b79f768U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 5U) | (state >> 27U);
        state ^= lane;
      } else {
        state ^= (lane * 0x0ade81e9U);
      }
    }
  }
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t x = state ^ (0x2f5e3068U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x1ac8ebe8U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x29f77d86U, 0xa9a4be84U, 0xa9587d06U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x1b2edce9U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0067 class=medium score=4.000 addr=0x11004c */
void log_pool_init_b(void) {
  uint32_t state = 0x6a682ed3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)5U << 1);
  state ^= ((uint32_t)10U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t o = ((state >> 1) + i) & 0x1FU;
    state ^= (uint32_t)mem16[o];
  }
  state ^= (0x0000063cU + (state << 1U));
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[3] = {0x00000001U, 0x00000000U, 0x0000063cU};
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x9661ba8cU;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x82a3518cU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0xaa2f878cU) ^ (ucmp >> 1U);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xbb2cbf0cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xb4bcae0dU);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x812a758cU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xb4bcae0cU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa5d2c8aU, 0xa95b9b04U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xa40c9d0dU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= 0xf171e011U;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xabbb1c0dU);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0x949b7a0cU;
  (void)gate;
  state ^= (0xbc07500cU + (state << 1U));
  (void)state;
}

/* unit=lift_0068 class=medium score=4.000 addr=0x100200 */
void memset_thunk(void) {
  uint32_t state = 0xa0fe12e7U;
  state ^= 0x94543f05U;
  state ^= ((uint32_t)21U << 4);
  state ^= ((uint32_t)32U << 1);
  state ^= ((uint32_t)0U << 9);
  state ^= ((uint32_t)5U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 5U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0xe0e8cd85U + i);
  }
  uint32_t bi = 0U;
  while (bi < 2U) {
    uint32_t o = (state + bi) & 0x3FU;
    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));
    ++bi;
  }
  state ^= 0x00000020U;
  state ^= (state & 0x000000bfU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000003U, 0x0000000fU, 0x00000010U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= (0xd3494a05U + (state << 1U)); break;
    case 1U: state ^= 0xd3b66f85U; break;
    default: state = (state ^ 0xf325a605U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xffd4a085U;
  if ((condv & 0x5U) != ((state >> 2) & 0x5U)) {
    state ^= 0x838f3105U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xd934c685U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xd6a4d785U);
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0xda70a885U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0xd715cb05U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 3U) | (state >> 29U);
        state ^= lane;
      } else {
        state ^= (lane * 0xc6b2bd85U);
      }
    }
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t x = state ^ (0xe3320c05U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xd6a4d785U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xaa089907U, 0x2a58ae07U, 0xa95b9b04U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd742e085U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0069 class=medium score=4.000 addr=0x143630 */
void memcpy_fast(void) {
  uint32_t state = 0x264da8b2U;
  state ^= 0x4be64a6dU;
  state ^= ((uint32_t)19U << 4);
  state ^= ((uint32_t)32U << 1);
  state ^= ((uint32_t)29U << 9);
  state ^= ((uint32_t)29U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 6U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0x3f5ab8edU + i);
  }
  uint32_t bi = 0U;
  while (bi < 6U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));
    ++bi;
  }
  uint32_t hi = 0U;
  while (hi < 4U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  }
  state ^= 0x00000040U;
  state ^= (state & 0x0000009fU);
  static const uint32_t imm_sig[4] = {0x00000004U, 0x00000003U, 0x00000040U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= (0x0cfb3f6dU + (state << 1U)); break;
    case 1U: state ^= 0x0c041aedU; break;
    case 2U: state = (state + 0x0caa23edU) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state ^= (0x0dc9e8edU + (state << 1U)); break;
    default: state = (state ^ 0x2c97d36dU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x2084e2edU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= (0x0db88d6dU + (state << 1U));
  } else {
    state ^= (0x09b46bedU + (state << 2U));
  }
  if ((condv & 0x2DU) != ((state >> 2) & 0x2DU)) {
    state ^= 0x4379f66dU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x0916a2edU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x05c2ddedU) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x08a7be6dU;
      } else if ((lane & 3U) == 1U) {
        state = (state << 4U) | (state >> 28U);
        state ^= lane;
      } else {
        state ^= (lane * 0x1900c8edU);
      }
    }
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t x = state ^ (0x3c80796dU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x0916a2edU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a61106U, 0xa9587d06U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  static uint8_t src[256];
  static uint8_t dst[256];
  for (uint32_t i = 0U; i < 256U; ++i) {
    src[i] = (uint8_t)(i ^ (state & 0xFFU));
  }
  for (uint32_t i = 0U; i < 256U; ++i) {
    dst[i] = src[i];
  }
  state ^= dst[17] ^ dst[129];
  (void)state;
}

/* unit=lift_0070 class=medium score=4.000 addr=0x124cf4 */
void timestamp_remove(void) {
  uint32_t state = 0x8313fb1eU;
  state ^= 0x264a25d4U;
  state ^= ((uint32_t)12U << 4);
  state ^= ((uint32_t)17U << 1);
  state ^= ((uint32_t)11U << 9);
  state ^= ((uint32_t)7U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x00040000U;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x0000001fU, 0x00040000U, 0x00000004U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= (0x615750d4U + (state << 1U)); break;
    case 1U: state ^= (0x61064c54U + (state << 2U)); break;
    default: state = (state ^ 0x413bbcd4U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x49740c54U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0x615750d4U;
  } else {
    state ^= 0x650bd1d4U;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x6b2adc54U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x64bacd55U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x512c16d4U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x64bacd54U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa95b9b04U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x655cfa55U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0071 class=medium score=4.000 addr=0x10d2c4 */
void clear_sdio_state(void) {
  uint32_t state = 0x53d71acaU;
  state ^= 0xe4c8a6e3U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  sdio_status_check();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa7de7963U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0072 class=medium score=4.000 addr=0x10f24c */
void log_pool_config(void) {
  uint32_t state = 0x5d2219ddU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)6U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x5df067dbU);
  uint32_t route = (state ^ 0x49ee7b5aU) & 0x7U;
  switch (route) {
    case 0U:
      hw_config_init();
      state ^= (0xef4293c0U + (route * 1U));
      break;
    case 1U:
      irq_disable();
      state ^= 0x86324a40U;
      break;
    case 2U:
      irq_prio_set();
      state ^= (0x7f7adc10U + (route * 3U));
      break;
    case 3U:
      irq_vector_init();
      state ^= (0xb6687167U + (route * 4U));
      break;
    case 4U:
      list_pop();
      state = (state + 0x7dfa318dU) ^ (route << 2U);
      break;
    case 5U:
      list_push_tail();
      state ^= (0xb8422eedU + (route * 1U));
      break;
    default:
      state ^= (0x51a5bddaU + (route << 2U));
      break;
  }
  state ^= route;
  state ^= (0x4adb88daU + (state << 1U));
  (void)state;
}

/* unit=lift_0073 class=medium score=4.000 addr=0x100202 */
void memset_impl(void) {
  uint32_t state = 0xfd7582d1U;
  state ^= 0xbdb35947U;
  static uint8_t scratch[256];
  uint8_t v = (uint8_t)(state & 0xFFU);
  for (uint32_t i = 0U; i < 256U; ++i) {
    scratch[i] = (uint8_t)(v + (uint8_t)i);
  }
  state ^= scratch[0] ^ scratch[255];
  (void)state;
}

/* unit=lift_0074 class=medium score=4.000 addr=0x12f3a8 */
void feature_flags_init(void) {
  uint32_t state = 0xe67e9269U;
  state ^= 0x98435f81U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xdb558001U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0075 class=medium score=4.000 addr=0x12c954 */
void rx_queue_head_init(void) {
  uint32_t state = 0x3815b8faU;
  state ^= 0x1d30f303U;
  state ^= ((uint32_t)36U << 4);
  state ^= ((uint32_t)52U << 1);
  state ^= ((uint32_t)46U << 9);
  state ^= ((uint32_t)12U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 6U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));
    ++bi;
  }
  uint32_t hi = 0U;
  while (hi < 4U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  }
  state ^= 0x07000000U;
  state ^= (state & 0x0000017fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000054U, 0x00000001U, 0x07000000U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state = (state + 0x5ad2a383U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0x5a7c9a83U + (state << 2U)); break;
    case 2U: state = (state + 0x5a7c9a83U) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state = (state + 0x5bcc7d03U) ^ ((state >> 4U) & 0xFFFFU); break;
    default: state = (state ^ 0x7a416a03U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x75db7f83U;
  if ((condv & 0x3U) != ((state >> 3) & 0x3U)) {
    state ^= 0x15fe2383U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[4];
  for (uint32_t fi = 0U; fi < 4U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x51f2c183U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    uint32_t idx = (uint32_t)4U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x5fc01b83U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x53146483U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x5e710703U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 3U) | (state >> 29U);
        state ^= lane;
      } else {
        state ^= (lane * 0x4fd67183U);
      }
    }
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t x = state ^ (0x6a56c003U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x5fc01b83U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    x = x * (0x4f215403U | 1U);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa95b9b04U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  list_insert_sorted();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x5e262c83U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0076 class=medium score=4.000 addr=0x1006cc */
void get_variant_cached(void) {
  uint32_t state = 0x9e0f0e18U;
  state ^= 0x9ea899cdU;
  state ^= ((uint32_t)1U << 4);
  state ^= ((uint32_t)0U << 1);
  state ^= ((uint32_t)2U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 2U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 1U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  for (uint32_t opi = 0U; opi < 3U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xdc58714dU);
    opmix ^= (state >> (opi & 7U));
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  uint32_t reg_touch[3] = {0x2a09c287U, 0xa9a75886U, 0x98575f2bU};
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xddbe464dU);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0077 class=medium score=4.000 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  uint32_t state = 0xa1a26bb0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)9U << 4);
  state ^= ((uint32_t)13U << 1);
  state ^= ((uint32_t)9U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state = (state + 0x0000001fU) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t condv = state ^ 0xdcce9645U;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xf18393c5U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xfe1382c5U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xcb855945U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xfe1382c5U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0xa95b9b04U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xeea3b1c5U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  list_pop();
  state = (state + 0x7c37c38dU) ^ (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xe11430c5U);
  state ^= ((gate << 2U) | (gate >> 30U)) ^ 0xde3456c5U;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)13U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0078 class=medium score=4.000 addr=0x110340 */
void log_pool_alloc(void) {
  uint32_t state = 0x1d7f8fe1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)10U << 1);
  state ^= ((uint32_t)7U << 9);
  state ^= ((uint32_t)3U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 7U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= (0x0000001fU + (state << 1U));
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  uint32_t condv = state ^ 0xe27da88bU;
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xcf30ad0bU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xc0a0bc0bU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xf536678bU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xc0a0bc0bU);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a4be84U, 0xaaa6d007U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xd0108f0bU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  list_pop();
  state = (state ^ 0x7c99fa8dU) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xdfa70e0bU);
  state ^= ((gate >> 8U) | (gate << 24U)) + 0xe3e1210bU;
  (void)gate;
  state ^= (0xc8b9890bU + (state << 1U));
  (void)state;
}

/* unit=lift_0079 class=medium score=4.000 addr=0x12f818 */
void parse_int(void) {
  uint32_t state = 0x321a6088U;
  state ^= 0x7798facbU;
  state ^= ((uint32_t)22U << 4);
  state ^= ((uint32_t)33U << 1);
  state ^= ((uint32_t)5U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 5U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 5U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  state = (state + 0x00000078U) ^ (state >> 2U);
  state ^= (state & 0x0000011fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000020U, 0x00000030U, 0x00000041U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state = (state + 0x307aaa4bU) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= 0x307aaa4bU; break;
    default: state = (state ^ 0x10e963cbU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x1adff74bU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x31b7584bU) ^ (state >> 2U);
  } else {
    state = (state + 0x35cadb4bU) ^ (state >> 3U);
  }
  if ((condv & 0xBU) != ((state >> 3) & 0xBU)) {
    state ^= 0x7f562a4bU;
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x0377edcbU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x2bfb3bcbU) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x3af8034bU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x3568124bU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x39bc6d4bU) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x34d90ecbU;
      } else if ((lane & 3U) == 1U) {
        state = (state << 4U) | (state >> 28U);
        state ^= lane;
      } else {
        state ^= (lane * 0x257e784bU);
      }
    }
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t x = state ^ (0x00fec9cbU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x3568124bU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = x * (0x25895dcbU | 1U);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0xa9587d06U, 0xa908f285U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x348e254bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0080 class=medium score=4.000 addr=0x111fbc */
void hw_event_flag(void) {
  uint32_t state = 0xa0ae7907U;
  state ^= 0xe13812faU;
  state ^= ((uint32_t)3U << 4);
  state ^= ((uint32_t)3U << 1);
  state ^= ((uint32_t)1U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 1U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0x9584e07aU + i);
  }
  state = (state + 0x84000000U) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000005U, 0x40000000U, 0x00200000U, 0x00000000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= (0xa62567faU + (state << 1U)); break;
    case 1U: state ^= (0xa6747b7aU + (state << 2U)); break;
    case 2U: state = (state + 0xa6747b7aU) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state = (state + 0xa7c49cfaU) ^ ((state >> 4U) & 0xFFFFU); break;
    case 4U: state ^= (0xa766d5faU + (state << 2U)); break;
    default: state = (state ^ 0x86498bfaU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x8eb727faU;
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa3c8fa7bU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x965e21faU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xa3c8fa7aU);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[3] = {0xa9f63406U, 0x2a58ae07U, 0x98575f2bU};
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa22ecd7bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0081 class=medium score=4.000 addr=0x1103c4 */
void log_queue_refill(void) {
  uint32_t state = 0xe551d892U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)26U << 4);
  state ^= ((uint32_t)38U << 1);
  state ^= ((uint32_t)31U << 9);
  state ^= ((uint32_t)12U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  while (hi < 4U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state = (state ^ (uint32_t)mem16[o]) + ((state << 1) & 0xFFFFU);
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  }
  state ^= (0x00000400U + (state << 1U));
  state ^= (state & 0x000000bfU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000000U, 0x00000400U, 0x0000001fU};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= (0x58337fd1U + (state << 1U)); break;
    case 1U: state = (state + 0x58337fd1U) ^ ((state >> 2U) & 0xFFFFU); break;
    default: state = (state ^ 0x785f93d1U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x74ae9551U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x5aa7f151U) ^ (state >> 2U);
  } else {
    state ^= (0x5ea34cd1U + (state << 2U));
  }
  if ((condv & 0x11U) != ((state >> 3) & 0x11U)) {
    state ^= 0x17e0da51U;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x6b300151U) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x434dcbd1U) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x53bd14d1U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x5ddee251U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x510a9d51U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x5c6ffed1U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 5U) | (state >> 27U);
        state ^= lane;
      } else {
        state ^= (lane * 0x4dc88851U);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x684839d1U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x5ddee251U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a61106U, 0xa9587d06U, 0xaaf7cc87U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x4d6ed151U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)9U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  buffer_pool_manage();
  state = (state + 0xd43f7b6dU) ^ (state >> 1U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x42d95051U);
  state ^= gate ^ 0x7d8a12d1U;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)38U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0082 class=medium score=4.000 addr=0x11414c */
void log_free_pool_e(void) {
  uint32_t state = 0x221d9644U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)9U << 4);
  state ^= ((uint32_t)13U << 1);
  state ^= ((uint32_t)10U << 9);
  state ^= ((uint32_t)4U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state = (state + 0x00000244U) ^ (state >> 2U);
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x0000001fU, 0x00000000U, 0x00000244U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xd693a28fU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0xf1d2c70fU;
  } else {
    state ^= 0xf58e460fU;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xfbaf4b8fU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xf43f5a8fU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xc1a9810fU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xf43f5a8fU);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0xaaa6d007U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xe48f698fU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)1U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state = (state ^ 0xf18eb591U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xeb38e88fU);
  state ^= ((gate >> 11U) | (gate << 21U)) + 0xd77ec78fU;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)13U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0083 class=medium score=4.000 addr=0x1424dc */
void math_round(void) {
  uint32_t state = 0xc34ea0e7U;
  state ^= 0x695b93a4U;
  state ^= ((uint32_t)12U << 4);
  state ^= ((uint32_t)17U << 1);
  state ^= ((uint32_t)1U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 1U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= (0xffffffffU + (state << 1U));
  state ^= (state & 0x0000009fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000033U, 0x00000001U, 0x00000014U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x2U) {
    case 0U: state ^= (0x2e46e6a4U + (state << 1U)); break;
    case 1U: state ^= 0x2eb9c324U; break;
    case 2U: state ^= (0x2fa71da4U + (state << 3U)); break;
    default: state = (state ^ 0x0e2a0aa4U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 5U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x04f143a4U;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x2fa71da4U) ^ (state >> 2U);
  } else {
    state = (state + 0x2b789ea4U) ^ (state >> 3U);
  }
  if ((condv & 0x24U) != ((state >> 2) & 0x24U)) {
    state ^= 0x61c42fa4U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x243b6a24U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x2bab7b25U);
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t x = state ^ (0x1e3da0a4U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x2bab7b24U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a61106U, 0x295c5284U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  math_helper_int();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2a4d4c25U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0084 class=medium score=4.000 addr=0x12a32c */
void queue_pending_check(void) {
  uint32_t state = 0x2719c1efU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)12U << 4);
  state ^= ((uint32_t)16U << 1);
  state ^= ((uint32_t)12U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
  }
  state ^= 0x0000008cU;
  state ^= (state & 0x0000003fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x00000002U, 0x0000008cU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= 0x57debe3cU; break;
    case 1U: state ^= (0x5721ebbcU + (state << 2U)); break;
    case 2U: state ^= 0x5770f73cU; break;
    case 3U: state ^= 0x5721ebbcU; break;
    case 4U: state ^= (0x5633453cU + (state << 2U)); break;
    default: state = (state ^ 0x771c1b3cU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x7ea5053cU;
  if ((condv & 0x3CU) != ((state >> 2) & 0x3CU)) {
    state ^= 0x18f23e3cU;
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0x6482953cU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x4c0e433cU) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x529d6abdU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x670bb13cU + (i << 4));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    x = x * (0x427c253cU | 1U);
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a75886U, 0xaaa6d007U, 0x980643abU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)0U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  buffer_pool_manage();
  state ^= 0xd46e17edU;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x4d9ad8bdU);
  state ^= gate ^ 0x72c99a3cU;
  (void)gate;
  state ^= (0x5633453cU + (state << 1U));
  (void)state;
}

/* unit=lift_0085 class=medium score=4.000 addr=0x124bfc */
void timestamp_update(void) {
  uint32_t state = 0x633b6fb4U;
  state ^= 0xe5101d4eU;
  state ^= ((uint32_t)18U << 4);
  state ^= ((uint32_t)27U << 1);
  state ^= ((uint32_t)28U << 9);
  state ^= ((uint32_t)9U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= 0x20000000U;
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x00000001U, 0x0000001fU, 0x20000000U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x3U) {
    case 0U: state ^= 0xa2a3214eU; break;
    case 1U: state ^= 0xa2f24dceU; break;
    case 2U: state ^= 0xa20d684eU; break;
    case 3U: state ^= 0xa25c74ceU; break;
    default: state = (state ^ 0x8261844eU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x88f5e9ceU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0xa3ec934eU;
  } else {
    state ^= 0xa651e94eU;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xa983034eU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa7e0f5cfU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0xab348acfU) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0xa651e94eU;
      } else if ((lane & 3U) == 1U) {
        state = (state << 3U) | (state >> 29U);
        state ^= lane;
      } else {
        state ^= (lane * 0xb7f69fcfU);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x92762e4eU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xa7e0f5ceU);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x295aa185U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa606c2cfU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0086 class=medium score=4.000 addr=0x110edc */
void log_queue_push2(void) {
  uint32_t state = 0xa959daaeU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)25U << 4);
  state ^= ((uint32_t)37U << 1);
  state ^= ((uint32_t)33U << 9);
  state ^= ((uint32_t)11U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 6U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));
    ++bi;
  }
  state ^= (0x00002700U + (state << 1U));
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000100U, 0x0000001fU, 0x00000016U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state ^= 0x439ca1dfU; break;
    case 1U: state ^= (0x4363f45fU + (state << 2U)); break;
    case 2U: state ^= (0x42d313dfU + (state << 3U)); break;
    case 3U: state ^= 0x4363f45fU; break;
    case 4U: state ^= 0x42d313dfU; break;
    default: state = (state ^ 0x635e04dfU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x693b74dfU;
  if ((condv & 0x1FU) != ((state >> 3) & 0x1FU)) {
    state ^= 0x0ce14d5fU;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x494f645fU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x46df755fU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x4a0b0a5fU) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x476e69dfU;
      } else if ((lane & 3U) == 1U) {
        state = (state << 4U) | (state >> 28U);
        state ^= lane;
      } else {
        state ^= (lane * 0x56c91f5fU);
      }
    }
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x7349aedfU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x46df755fU);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xaa59f587U, 0x29593486U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x566f465fU);
  enum { RCAP = 128 };
  static uint32_t ring[RCAP];
  static uint32_t wr, rd;
  uint32_t next = (wr + 1U) & (RCAP - 1U);
  uint32_t msg = (state << 1) ^ 0xA55AA55AU;
  if (next == rd) {
    rd = (rd + 1U) & (RCAP - 1U);
  }
  ring[wr] = msg;
  wr = next;
  state ^= ring[(wr - 1U) & (RCAP - 1U)];
  uint32_t budget = 4U;
  while (rd != wr && budget-- > 0U) {
    state ^= ring[rd];
    rd = (rd + 1U) & (RCAP - 1U);
  }
  (void)state;
}

/* unit=lift_0087 class=medium score=4.000 addr=0x10f270 */
void log_global_init(void) {
  uint32_t state = 0x1803b73eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)7U << 4);
  state ^= ((uint32_t)9U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)11U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 6U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0xb5f2173cU + i);
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t o = ((state >> 1) + i) & 0x1FU;
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + i));
  }
  state ^= (0x0000c0bfU + (state << 1U));
  state ^= (state & 0x0000009fU);
  static const uint32_t imm_sig[4] = {0x00000800U, 0x00000000U, 0x00000024U, 0x00001810U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0x86acb53cU) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0x86028c3cU + (state << 2U)); break;
    case 2U: state = (state + 0x86028c3cU) ^ ((state >> 3U) & 0xFFFFU); break;
    case 3U: state ^= 0x86028c3cU; break;
    case 4U: state = (state + 0x8761473cU) ^ ((state >> 1U) & 0xFFFFU); break;
    default: state = (state ^ 0xa63f7cbcU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xaec1d0bcU;
  if ((condv & 0x3CU) != ((state >> 4) & 0x3CU)) {
    state ^= 0xc93710bcU;
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x8c2e1c3cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x83be0d3dU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xb628d6bcU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x83be0d3cU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x29f21b84U, 0xa9a6cb85U, 0xaaa6d007U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x930e3e3dU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)6U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= 0xf171e011U;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x9cb9bf3dU);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0xa399d93cU;
  (void)gate;
  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));
  tail ^= ((uint32_t)6U << 10);
  state ^= tail;
  (void)state;
}

/* unit=lift_0088 class=medium score=4.000 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  uint32_t state = 0x32b8f158U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)56U << 4);
  state ^= ((uint32_t)91U << 1);
  state ^= ((uint32_t)46U << 9);
  state ^= ((uint32_t)11U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 5U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    state ^= (uint32_t)mem8[o];
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  uint32_t hi = 0U;
  while (hi < 4U) {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    mem16[o] = (uint16_t)(state ^ (0x5A5AU + hi));
    ++hi;
  }
  state = (state + 0x000000aaU) ^ (state >> 2U);
  state ^= (state & 0x000000bfU);
  static const uint32_t imm_sig[4] = {0x00000001U, 0x00000000U, 0x00000055U, 0x0000001fU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state ^= 0x90bc85e2U; break;
    case 1U: state ^= 0x90ede962U; break;
    default: state = (state ^ 0xb07e20e2U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 6U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xbf5a7c62U;
  if ((condv & 0x22U) != ((state >> 3) & 0x22U)) {
    state ^= 0xdfc16962U;
  }
  if ((int32_t)condv < (int32_t)(state ^ 0x80000000U)) {
    state = (state << 1) ^ (condv >> 1);
  }
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0xa424c0e2U) + (ucmp & 0xFFU);
  } else {
    state = (state + 0x8b6c78e2U) ^ (ucmp >> 1U);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x9b9ca7e2U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x95ff5163U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t ob = 0U; ob < 2U; ++ob) {
    for (uint32_t ib = 0U; ib < 2U; ++ib) {
      uint32_t lane = ((state >> (ib & 7U)) ^ (ob * 0x992b2e63U) ^ ib);
      if ((lane & 3U) == 0U) {
        state ^= lane + 0x944e4de2U;
      } else if ((lane & 3U) == 1U) {
        state = (state << 5U) | (state >> 27U);
        state ^= lane;
      } else {
        state ^= (lane * 0x85e93b63U);
      }
    }
  }
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t x = state ^ (0xa0698ae2U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x95ff5162U);
    x ^= (x - (state << (i & 3U)));
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0xaaa6d007U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x854f6263U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)15U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_free_pool_a();
  state ^= (0xf1dfa911U + (state << 1U));
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0x8af8e363U);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0xb5d88562U;
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)91U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0089 class=medium score=4.000 addr=0x10fe7c */
void log_alloc(void) {
  uint32_t state = 0xef2db6f4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)8U << 4);
  state ^= ((uint32_t)9U << 1);
  state ^= ((uint32_t)5U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 5U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 2U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    mem8[o] = (uint8_t)(state ^ (0xA5U + bi));
    ++bi;
  }
  state = (state + 0x0000007cU) ^ (state >> 2U);
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000001U, 0x0000007cU};
  uint32_t ii = 0U;
  while (ii < 2U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x009a1a8dU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state ^= 0x27db7f0dU;
  } else {
    state ^= 0x2387fe0dU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x2c55140dU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x2236e28dU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a75886U, 0xa95b9b04U, 0x290d4e04U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x3286d18dU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  list_pop();
  state = (state + 0x7c37c38dU) ^ (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x3d31508dU);
  state ^= (gate + 0x02c05b0dU) ^ ((uint32_t)8U << 5);
  (void)gate;
  uint32_t tail = (state ^ 0xC3C3C3C3U) + ((state << 5) | (state >> 27));
  tail ^= (tail >> 11);
  tail ^= ((uint32_t)9U << 9);
  state ^= tail;
  (void)state;
}

/* unit=lift_0090 class=medium score=4.000 addr=0x142e9c */
void math_helper_int(void) {
  uint32_t state = 0x03366b30U;
  state ^= 0xadb58cd4U;
  state ^= ((uint32_t)8U << 4);
  state ^= ((uint32_t)8U << 1);
  state ^= ((uint32_t)0U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  state ^= (0xfffffc1fU + (state << 1U));
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x80000000U, 0x00000000U, 0x00200000U, 0xfffffc1fU};
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0xea57dc54U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= 0xea57dc54U; break;
    case 2U: state ^= 0xeaa8f9d4U; break;
    case 3U: state = (state + 0xeb4902d4U) ^ ((state >> 4U) & 0xFFFFU); break;
    case 4U: state = (state + 0xeb9a2e54U) ^ ((state >> 1U) & 0xFFFFU); break;
    default: state = (state ^ 0xcac415d4U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xc37d0bd4U;
  if ((condv & 0x14U) != ((state >> 2) & 0x14U)) {
    state ^= 0xa52a30d4U;
  }
  if ((int32_t)condv >= (int32_t)(state ^ 0x13579BDFU)) {
    state = (state >> 1) ^ (condv << 1);
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xef456455U);
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state + opmix) ^ (opmix >> (opi & 7U));
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xdad3bfd4U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xef456454U);
    x ^= (x - (state << (i & 3U)));
    x ^= (state & 0x55AA55AAU);
    x |= ((state >> 1) & 0x0F0F0F0FU);
    x = (x << ((i & 3U) + 1U)) | (x >> (31U - (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa9f63406U, 0x2a58ae07U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xeea35355U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0091 class=medium score=4.000 addr=0x12d240 */
void list_insert_sorted(void) {
  uint32_t state = 0x22a324ebU;
  state ^= 0x3683e713U;
  state ^= ((uint32_t)10U << 4);
  state ^= ((uint32_t)12U << 1);
  state ^= ((uint32_t)2U << 9);
  state ^= ((uint32_t)7U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 6U; ++i) {
    mem_prof[(state + i) & 0x1FU] = state ^ (0x423f1593U + i);
  }
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[1] = {0x00000000U};
  uint32_t ii = 0U;
  while (ii < 1U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x1U) {
    case 0U: state = (state + 0x7161b793U) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= (0x71cf8e93U + (state << 2U)); break;
    default: state = (state ^ 0x51f27e13U) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x59bdce93U;
  if ((condv & 0x13U) != ((state >> 2) & 0x13U)) {
    state ^= 0x3e1c5b13U;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[3];
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x7a10f913U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    uint32_t idx = (uint32_t)3U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x74730f93U);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  uint32_t reg_touch[4] = {0xa9f5d204U, 0x29a37704U, 0xaaa2090aU, 0x290bbd05U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  list_remove_node();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x75953893U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0092 class=medium score=4.000 addr=0x12f8ec */
void parse_width_suffix(void) {
  uint32_t state = 0x222e41f9U;
  state ^= 0x409f455fU;
  state ^= ((uint32_t)6U << 4);
  state ^= ((uint32_t)6U << 1);
  state ^= ((uint32_t)2U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 2U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t bi = 0U;
  while (bi < 2U) {
    uint32_t o = (state + bi) & 0x3FU;
    state = (state + (uint32_t)mem8[o]) ^ ((state >> 3) & 0xFFU);
    ++bi;
  }
  state ^= 0xffffffffU;
  state ^= (state & 0x0000005fU);
  static const uint32_t imm_sig[4] = {0x00000002U, 0x0000002eU, 0x00000004U, 0x00000062U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x20c355dfU;
  if ((condv & 0xFFU) == ((state >> 8) & 0xFFU)) {
    state = (state + 0x0663cb5fU) ^ (state >> 2U);
  } else {
    state ^= (0x02bc485fU + (state << 2U));
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[4];
  for (uint32_t fi = 0U; fi < 4U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x0c5d77dfU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 3U; ++fi) {
    uint32_t idx = (uint32_t)4U - 1U - fi;
    state = (state + frame_regs[idx]) ^ (frame_regs[idx] << (fi & 3U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x026faddfU);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x37f9765fU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x026faddfU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa9f63406U, 0xa9a4be84U, 0x2aa78b87U, 0x27dc4c27U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  math_round();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x03899adfU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0093 class=medium score=4.000 addr=0x1006d8 */
void panic_loop(void) {
  uint32_t state = 0x71f1ff26U;
  state ^= 0x0ce7884bU;
  state ^= ((uint32_t)9U << 4);
  state ^= ((uint32_t)12U << 1);
  state ^= ((uint32_t)10U << 9);
  state ^= ((uint32_t)6U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  state ^= ((uint32_t)6U << 5);
  state ^= 0x00000020U;
  state ^= (state & 0x0000007fU);
  static const uint32_t imm_sig[4] = {0x00000000U, 0x0000000cU, 0x0000000aU, 0x00000020U};
  uint32_t ii = 0U;
  while (ii < 4U) {
    uint32_t off = (imm_sig[ii] >> 2) & 0x1FU;
    state = (state + mem_prof[off]) ^ (imm_sig[ii] >> 1);
    mem_prof[off] = state ^ (imm_sig[ii] << 1);
    ++ii;
  }
  switch ((state >> 3) & 0x4U) {
    case 0U: state = (state + 0x4b05d8cbU) ^ ((state >> 1U) & 0xFFFFU); break;
    case 1U: state ^= 0x4b05d8cbU; break;
    case 2U: state ^= (0x4a1b064bU + (state << 3U)); break;
    case 3U: state ^= 0x4babe1cbU; break;
    case 4U: state ^= 0x4a1b064bU; break;
    default: state = (state ^ 0x6b96114bU) + (state >> 3U); break;
  }
  for (uint32_t i = 0U; i < 4U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0x6368bd4bU;
  if ((condv & 0xBU) != ((state >> 3) & 0xBU)) {
    state ^= 0x042958cbU;
  }
  if ((state & 0x3U) == 0U) {
    state ^= 0x00C0FFEEU;
  }
  uint32_t frame_regs[4];
  for (uint32_t fi = 0U; fi < 4U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0x4025bacbU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  state ^= ((uint32_t)2U << 6);
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)4U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0x4e1760cbU);
    opmix ^= (state >> (opi & 7U));
    opmix ^= (state << ((opi & 3U) + 1U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state ^= opmix;
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x7b81bb4bU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0x4e1760cbU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0xa90450a3U, 0x2a58ae07U, 0xaaa6d007U, 0x29082806U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t sp_model = 0x20000000U + (state & 0x3FFU);
  sp_model -= ((state >> 5U) & 0x3CU);
  state ^= sp_model;
  uint32_t local_ws[8] = {0U};
  local_ws[0] = state;
  local_ws[1] = state ^ 0x9e3779b9U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t j = (i + (state & 0x7U)) % 8U;
    local_ws[j] ^= (state >> ((i & 7U) + 1U)) + (i << 4);
  }
  static const int32_t stk_offs[2] = {0, 4};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t idx = (uint32_t)((stk_offs[i] < 0 ? -stk_offs[i] : stk_offs[i]) & 7U);
    local_ws[idx] ^= state + (uint32_t)(stk_offs[i] & 0xFFFF);
  }
  state ^= (uint32_t)(4 - 0);
  state ^= local_ws[(state >> 3) & 7U];
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4ff157cbU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0094 class=medium score=4.000 addr=0x1100a4 */
void log_pool_init_queue(void) {
  uint32_t state = 0x02ae3a2eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)5U << 1);
  state ^= ((uint32_t)8U << 9);
  state ^= ((uint32_t)0U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint16_t *mem16 = (volatile uint16_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 8U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  uint32_t hi = 0U;
  do {
    uint32_t o = ((state >> 1) + hi) & 0x1FU;
    state ^= (uint32_t)mem16[o];
    ++hi;
  } while (hi < 2U);
  state ^= (0x0000000cU + (state << 1U));
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[3] = {0x00000000U, 0x0000000cU, 0x00000001U};
  for (uint32_t i = 0U; i < 3U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t condv = state ^ 0xd8d4667eU;
  uint32_t ucmp = condv - (state & 0xFFFFU);
  if (ucmp > 0x100U) {
    state = (state ^ 0xcc168d7eU) + (ucmp & 0xFFU);
  } else {
    state = (state + 0xe49a5b7eU) ^ (ucmp >> 1U);
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xf59963feU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= frame_regs[fi];
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] ^ (frame_regs[idx] >> ((fi & 3U) + 1U));
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xfa0972ffU);
    opmix ^= (state >> (opi & 7U));
    opmix = (opmix & 0xFFFF0000U) | (state & 0xFFFFU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0xcf9fa97eU + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xfa0972feU);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0x29a37704U, 0x295aa185U, 0xa9096186U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0xeab941ffU);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)3U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  buffer_pool_manage();
  state ^= (0xd4c05eedU + (state << 1U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xe50ec0ffU);
  state ^= ((gate >> 10U) | (gate << 22U)) + 0xd948effeU;
  (void)gate;
  state = (state + 0xf2b28cfeU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0095 class=medium score=3.910 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  uint32_t state = 0x124bfca5U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  state ^= ((uint32_t)2U << 4);
  state ^= ((uint32_t)2U << 1);
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xdac98f4cU);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state ^= (frame_regs[fi] << (fi & 3U)) | (frame_regs[fi] >> (8U - (fi & 3U)));
  }
  for (uint32_t opi = 0U; opi < 3U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xd5599e4dU);
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  uint32_t reg_touch[2] = {0x2a09c287U, 0x98a87aabU};
  for (uint32_t i = 0U; i < 2U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 3) & 0x3FU];
  state ^= (rf_reg + 0x00A500A5U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)2U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sub_10ed40();
  state ^= 0xa0980a93U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xca5e2c4dU);
  sub_114ee0();
  state ^= 0xe089e232U;
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xca8f09cdU);
  state ^= gate ^ 0xf57e4a4cU;
  (void)gate;
  state ^= (0xddb184ccU + (state << 1U));
  (void)state;
}

/* unit=lift_0193 class=medium score=3.850 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  uint32_t state = 0xbf1cad55U;
  state ^= 0xa6f78c76U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe5e153f7U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe5b67877U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0197 class=medium score=3.850 addr=0x49fc4 */
void hal_dma_evt(void) {
  uint32_t state = 0xea0f47a1U;
  state ^= 0xe3c0f93cU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa0d626bdU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0212 class=medium score=3.850 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  uint32_t state = 0x4d4a2a72U;
  state ^= 0x67688c41U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x247e53c1U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x24297841U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0211 class=medium score=3.850 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  uint32_t state = 0xe42d0a5eU;
  state ^= 0x4e7e23deU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x0d68fc5fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0210 class=medium score=3.850 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  uint32_t state = 0x3378e2bcU;
  state ^= 0x94a61a35U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd7b0c5b5U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd7e7ee35U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0209 class=medium score=3.850 addr=0x4a068 */
void ke_timer_set(void) {
  uint32_t state = 0xad4a9e0fU;
  state ^= 0x104d4bc0U;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x535b9441U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0208 class=medium score=3.850 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  uint32_t state = 0x14a7e4f6U;
  state ^= 0xc64c40caU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x855a9f4bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0207 class=medium score=3.850 addr=0x4999c */
void scan_cancel_req_handler(void) {
  uint32_t state = 0x226fe151U;
  state ^= 0xef02444cU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xac149bcdU);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xac43b04dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0206 class=medium score=3.850 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  uint32_t state = 0x7165ae96U;
  state ^= 0xc378240dU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x806efb8dU);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0205 class=medium score=3.850 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  uint32_t state = 0x635250b5U;
  state ^= 0xe6242a69U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa532f5e9U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0204 class=medium score=3.850 addr=0x48e40 */
void mm_start_req_handler(void) {
  uint32_t state = 0x8b8ff677U;
  state ^= 0x8951b5dcU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xca476a5dU);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xca1041ddU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0203 class=medium score=3.850 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  uint32_t state = 0x7d74ee1bU;
  state ^= 0x5a505322U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x19468ca3U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0202 class=medium score=3.850 addr=0x49928 */
void scan_start_req_handler(void) {
  uint32_t state = 0x1806d9bfU;
  state ^= 0x688c4e23U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2b9a91a3U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2bcdba23U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0201 class=medium score=3.850 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  uint32_t state = 0x2313b97cU;
  state ^= 0xc7671758U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_timer_set();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8471c8d9U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0200 class=medium score=3.850 addr=0x49180 */
void mm_timer_schedule(void) {
  uint32_t state = 0xdb7c6901U;
  state ^= 0x6b7cb85eU;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_timer_set();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x286a67dfU);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x283d4c5fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0199 class=medium score=3.850 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  uint32_t state = 0x077a7c73U;
  state ^= 0x15202af1U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x5636f571U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0173 class=medium score=3.850 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  uint32_t state = 0xa609dd52U;
  state ^= 0xcee70746U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8df1d8c7U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0174 class=medium score=3.850 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  uint32_t state = 0xc51530f2U;
  state ^= 0xc11529d0U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8203f651U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0175 class=medium score=3.850 addr=0x49170 */
void mm_timer_set(void) {
  uint32_t state = 0x1a313f87U;
  state ^= 0xa5482af5U;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_timer_set();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe65ef575U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe609def5U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0176 class=medium score=3.850 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  uint32_t state = 0xa48b562eU;
  state ^= 0x15dd8a63U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x56cb55e3U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x569c7e63U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0177 class=medium score=3.850 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  uint32_t state = 0x7db0eac3U;
  state ^= 0x67237a3aU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2435a5bbU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0178 class=medium score=3.850 addr=0x4a078 */
void ke_timer_clear(void) {
  uint32_t state = 0x993a9a4bU;
  state ^= 0x5ca89555U;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x1fbe4ad5U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0179 class=medium score=3.850 addr=0x47a64 */
void txl_cfm_evt(void) {
  uint32_t state = 0x40347630U;
  state ^= 0x537a56c6U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x106c8947U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0180 class=medium score=3.850 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  uint32_t state = 0x0babc7bdU;
  state ^= 0x77b28d24U;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x34a452a5U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0181 class=medium score=3.850 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  uint32_t state = 0xf7525d46U;
  state ^= 0x6ead7fdfU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2dbba05fU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0182 class=medium score=3.850 addr=0x4c20c */
void apm_start_req_handler(void) {
  uint32_t state = 0x490d52e8U;
  state ^= 0xb6fd2796U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf5ebf817U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf5bcd397U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0198 class=medium score=3.850 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  uint32_t state = 0xa18278a3U;
  state ^= 0x6f37e097U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x2c213f17U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0172 class=medium score=3.850 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  uint32_t state = 0x7d7d26f3U;
  state ^= 0x0c938169U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4f855ee9U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4fd27569U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0196 class=medium score=3.850 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  uint32_t state = 0xf3d32e29U;
  state ^= 0x098e245fU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4a98fbdfU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0195 class=medium score=3.850 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  uint32_t state = 0x6e507db9U;
  state ^= 0x861a9854U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xc50c47d5U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xc55b6c55U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0194 class=medium score=3.850 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  uint32_t state = 0xc5e2bff2U;
  state ^= 0xcc937762U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8f85a8e3U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x8fd28363U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0192 class=medium score=3.850 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  uint32_t state = 0x4871981dU;
  state ^= 0x41dec5f5U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x02c81a75U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0191 class=medium score=3.850 addr=0x48920 */
void mm_tbtt_evt(void) {
  uint32_t state = 0xb1ebb7c5U;
  state ^= 0xa24ce58fU;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe15a3a0fU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0190 class=medium score=3.850 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  uint32_t state = 0x7fee0c86U;
  state ^= 0x1dbe9d3fU;
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x5ea842bfU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0189 class=medium score=3.850 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  uint32_t state = 0x5e200411U;
  state ^= 0xd142f495U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x92542b15U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x92030095U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0188 class=medium score=3.850 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  uint32_t state = 0xa1ab2e23U;
  state ^= 0xe04f3fd7U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa359e057U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa30ecbd7U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0187 class=medium score=3.850 addr=0x4bc6c */
void mm_chan_ctxt_unlink_cfm_handler(void) {
  uint32_t state = 0x8024b22cU;
  state ^= 0x90fa95c7U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd3ec4a47U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0186 class=medium score=3.850 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  uint32_t state = 0x4ca33dc2U;
  state ^= 0x8d6bcea2U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xce7d1123U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xce2a3aa3U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0183 class=medium score=3.850 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  uint32_t state = 0x356d38b5U;
  state ^= 0x20b92052U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x63afffd3U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0185 class=medium score=3.850 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  uint32_t state = 0xfaf8596eU;
  state ^= 0xbdd5d2d9U;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xfec30d59U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xfe9426d9U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0184 class=medium score=3.850 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  uint32_t state = 0xf4193489U;
  state ^= 0x11929984U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x52844605U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x52d36d85U);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0641 class=low score=3.300 addr=0x130370 */
void rf_timer_toggle_update(void) {
  uint32_t state = 0xc7e4458fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  state ^= ((uint32_t)4U << 4);
  state ^= ((uint32_t)4U << 1);
  state ^= ((uint32_t)3U << 9);
  state ^= ((uint32_t)1U << 13);
  volatile uint32_t *mem_prof = (volatile uint32_t *)(uintptr_t)0x40000000U;
  volatile uint8_t *mem8 = (volatile uint8_t *)(uintptr_t)mem_prof;
  for (uint32_t i = 0U; i < 3U; ++i) {
    state ^= mem_prof[(state + i) & 0x1FU];
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t o = (state + i) & 0x3FU;
    mem8[o] = (uint8_t)(state ^ (0xA5U + i));
  }
  state ^= (0x00000004U + (state << 1U));
  state ^= (state & 0x0000001fU);
  static const uint32_t imm_sig[2] = {0x00000000U, 0x00000004U};
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t off = (imm_sig[i] >> 2) & 0x1FU;
    state ^= mem_prof[off] ^ imm_sig[i];
    mem_prof[off] = state ^ (imm_sig[i] << 1);
  }
  for (uint32_t i = 0U; i < 2U; ++i) {
    uint32_t probe = (state >> (i & 7U)) & 0xFFU;
    if (probe < 0x20U) {
      state ^= 0x00010001U + i;
    } else if (probe < 0x80U) {
      state ^= 0x00020002U + (i << 1);
    } else {
      state ^= 0x00040004U + (i << 2);
    }
  }
  uint32_t frame_regs[2];
  for (uint32_t fi = 0U; fi < 2U; ++fi) {
    frame_regs[fi] = state ^ (fi * 0xaa23d020U);
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    state = (state + frame_regs[fi]) ^ (frame_regs[fi] >> ((fi & 3U) + 1U));
  }
  for (uint32_t fi = 0U; fi < 1U; ++fi) {
    uint32_t idx = (uint32_t)2U - 1U - fi;
    state ^= frame_regs[idx] >> (fi & 7U);
  }
  for (uint32_t opi = 0U; opi < 8U; ++opi) {
    uint32_t opmix = state ^ (opi * 0xa5b3c121U);
    opmix ^= (state >> (opi & 7U));
    if ((opmix & 0x1FU) < ((state >> 3) & 0x1FU)) { opmix ^= 0x1U; }
    state = (state ^ (opmix << (opi & 3U))) + (opmix & 0xFFFFU);
  }
  for (uint32_t i = 0U; i < 1U; ++i) {
    uint32_t x = state ^ (0x90251aa0U + (i << 4));
    x += (state >> (i & 7U)) + (i * 0xa5b3c120U);
    x ^= (x - (state << (i & 3U)));
    state ^= x;
  }
  uint32_t reg_touch[4] = {0x2a09c287U, 0xa9a75886U, 0xaaa6d007U, 0xa90a8784U};
  for (uint32_t i = 0U; i < 4U; ++i) {
    state ^= reg_touch[i] + (i << 8);
    reg_touch[i] = (reg_touch[i] << 1) | (reg_touch[i] >> 31);
  }
  uint32_t reg_r0 = state;
  uint32_t reg_r1 = state ^ 0x11111111U;
  uint32_t reg_r2 = state ^ 0x22222222U;
  uint32_t reg_r3 = state ^ 0x33333333U;
  reg_r0 = (reg_r0 + reg_r1) ^ (reg_r1 >> 2U);
  reg_r2 ^= (reg_r0 << 1U) + (reg_r1 & 0xFFFFU);
  reg_r3 = (reg_r3 ^ reg_r2) + (reg_r0 >> 1U);
  state ^= reg_r0 ^ reg_r1 ^ reg_r2 ^ reg_r3;
  uint32_t lr_model = (state ^ 0xFFFFFFFDU) | 1U;
  state ^= (lr_model >> 1U);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 1) & 0x3FU];
  state = (state + rf_reg) ^ 0x00A500A5U;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = (uint32_t)4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  rf_hw_timer_read();
  state ^= 0x760114f6U;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xbab47321U);
  rf_level_step();
  state ^= 0x77f404e1U;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xba6556a1U);
  rf_level_compute();
  state ^= 0xa4daa3baU;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xba15ba21U);
  state ^= ((gate << 2U) | (gate >> 30U)) ^ 0x86f25c20U;
  (void)gate;
  uint32_t tail = (uint32_t)(0xC3C30000U | ((state >> 3) & 0xFFFFU));
  tail ^= ((uint32_t)4U << 10);
  state ^= tail;
  (void)state;
}

/* unit=lift_0643 class=low score=3.060 addr=0x12efb0 */
void rf_timer_abort2(void) {
  uint32_t state = 0x1cb5a7feU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 1) & 0x3FU];
  state = (state + rf_reg) ^ 0x00A500A5U;
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  rf_timer_abort_common();
  state = (state ^ 0xd0e51f4cU) + (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x6dffe72fU);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0x51b9c82fU;
  (void)gate;
  state ^= 0x76f433afU;
  (void)state;
}

/* unit=lift_0642 class=low score=3.060 addr=0x12ef94 */
void rf_timer_abort1(void) {
  uint32_t state = 0x18f7ddfaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  rf_timer_abort_common();
  state ^= 0xd01a4accU;
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xedf94bb1U);
  state ^= gate ^ 0xd2aa0930U;
  (void)gate;
  state ^= (0xf6f29f30U + (state << 1U));
  (void)state;
}

/* unit=lift_0649 class=low score=3.050 addr=0x441a8 */
void phy_hw_set_channel(void) {
  uint32_t state = 0x794247a5U;
  state ^= 0xb4332615U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xf6610795U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= (0xf8a03815U + (state << 1U));
  (void)state;
}

/* unit=lift_0648 class=low score=3.050 addr=0x4c722 */
void host_id(void) {
  uint32_t state = 0x8800d1cfU;
  state ^= 0xd8f63170U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x9aa410f0U * i);
  }
  state ^= acc;
  uint32_t ch = (state >> 1U) & 0xFU;
  state ^= ((ch * 3U) << 8U) ^ ((ch + 5U) << 3U);
  state ^= 0x94652f70U;
  (void)state;
}

/* unit=lift_0647 class=low score=3.050 addr=0x441c8 */
void phy_get_rf_gain_idx(void) {
  uint32_t state = 0xaea7591eU;
  state ^= 0x85d19c9aU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xc6c7431bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0646 class=low score=3.050 addr=0x44224 */
void phy_stop(void) {
  uint32_t state = 0xa3a0d749U;
  state ^= 0x7ff97f26U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x3dab5ea6U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state = (state + 0x336a6126U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0645 class=low score=3.050 addr=0x44204 */
void phy_set_channel(void) {
  uint32_t state = 0x3aac3489U;
  state ^= 0x0d1f9e0cU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x4f4dbf8cU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= 0x418c800cU;
  (void)state;
}

/* unit=lift_0644 class=low score=3.050 addr=0x46008 */
void ipc_emb_hostrxbuf_get(void) {
  uint32_t state = 0x1f3e6bf5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sdio_wait_busy();
  state = (state ^ 0xf3085504U) + (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x0101ccb7U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0x3d47e3b7U;
  (void)gate;
  state = (state + 0x1a0a1837U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0650 class=low score=3.050 addr=0x46a70 */
void sdio_isr(void) {
  uint32_t state = 0x9695c25dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 4) & 0x1FU];
  state ^= (sdio_st + 0x5A5A0001U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_hw_init_if();
  state = (state ^ 0x1e7a7e17U) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x82d26487U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0xbe944b87U;
  (void)gate;
  state = (state + 0x997bf907U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0651 class=low score=3.050 addr=0x441dc */
void phy_get_txpwr_level(void) {
  uint32_t state = 0x16882a0aU;
  state ^= 0xa573a5fcU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xe750a8fcU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= (0xe9e0bbfcU + (state << 1U));
  (void)state;
}

/* unit=lift_0652 class=low score=3.050 addr=0x46fe0 */
void host_usb_wlan_init(void) {
  uint32_t state = 0x5d31b78fU;
  state ^= 0x6d897cf6U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x2fdb5d76U * i);
  }
  state ^= acc;
  uint32_t ch = state & 0xFU;
  state ^= (ch << 12U) ^ ((ch + 3U) << 4U);
  state = (state + 0x211a62f6U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0653 class=low score=3.050 addr=0x4684c */
void host_sdio_replenish_rx_queue(void) {
  uint32_t state = 0x765dd6beU;
  state ^= 0xa750db7dU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xe573d67dU);
  }
  state ^= leaf_state[idx];
  uint32_t ch = (state >> 2U) & 0x1FU;
  state ^= (ch << 10U) ^ ((ch + 1U) << 5U);
  state ^= (0xebc3c57dU + (state << 1U));
  (void)state;
}

/* unit=lift_0654 class=low score=3.050 addr=0x44214 */
void phy_get_channel(void) {
  uint32_t state = 0x0225ddd4U;
  state ^= 0x5559e40cU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x177ae90cU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state ^= 0x19cafa0cU;
  (void)state;
}

/* unit=lift_0745 class=low score=2.650 addr=0x49fd4 */
void tpc_update_frame_tx_power(void) {
  uint32_t state = 0x3b672694U;
  state ^= 0xf6f9bc49U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xb4dab149U);
  }
  state ^= leaf_state[idx];
  state ^= (0xba6aa249U + (state << 1U));
  (void)state;
}

/* unit=lift_0753 class=low score=2.650 addr=0x478e0 */
void txl_frame_exchange_chain(void) {
  uint32_t state = 0xc2066483U;
  state ^= 0x28537b57U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x6a015ad7U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0x64c06557U;
  (void)state;
}

/* unit=lift_0729 class=low score=2.650 addr=0x4d5e4 */
void rc_init_rates(void) {
  uint32_t state = 0xef161357U;
  state ^= 0x71f1ef27U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x33a3cea7U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state = (state + 0x3d62f127U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0665 class=low score=2.650 addr=0x45fe0 */
void ke_task_local(void) {
  uint32_t state = 0x6b10c845U;
  state ^= 0xe3207c3eU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xa1725dbeU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state = (state + 0xafb3623eU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0666 class=low score=2.650 addr=0x49250 */
void mm_bcn_update_p2p_noa(void) {
  uint32_t state = 0x086ca60bU;
  state ^= 0x48787730U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x0a2a56b0U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= (0x04eb6930U + (state << 1U));
  (void)state;
}

/* unit=lift_0667 class=low score=2.650 addr=0x4922c */
void mm_bcn_transmitted(void) {
  uint32_t state = 0xb7a31b7dU;
  state ^= 0x3b40275fU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x791206dfU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= (0x77d3395fU + (state << 1U));
  (void)state;
}

/* unit=lift_0668 class=low score=2.650 addr=0x4bfa0 */
void sm_assoc_rsp_handler(void) {
  uint32_t state = 0x0856ed45U;
  state ^= 0x8940e1f7U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xcb12c077U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state = (state + 0xc5d3fff7U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0728 class=low score=2.650 addr=0x4cb64 */
void bam_send_air_action_frame(void) {
  uint32_t state = 0x65205beeU;
  state ^= 0x42ca248fU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x00e9298fU);
  }
  state ^= leaf_state[idx];
  uint32_t ch = (state >> 1U) & 0xFU;
  state ^= ((ch * 3U) << 8U) ^ ((ch + 5U) << 3U);
  state = (state + 0x0e593a8fU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0669 class=low score=2.650 addr=0x4bfd0 */
void sm_ft_auth_over_air_start(void) {
  uint32_t state = 0xe290c7e2U;
  state ^= 0x521328f0U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x103025f0U);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= (0x1e8036f0U + (state << 1U));
  (void)state;
}

/* unit=lift_0670 class=low score=2.650 addr=0x48438 */
void rxl_payload_transfer(void) {
  uint32_t state = 0x7469f281U;
  state ^= 0xf81ad884U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xba48f904U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0xb489c684U + (state << 1U));
  (void)state;
}

/* unit=lift_0671 class=low score=2.650 addr=0x48150 */
void txl_he_trigger_push(void) {
  uint32_t state = 0xe21582f3U;
  state ^= 0xdfe3d347U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x9db1f2c7U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state = (state + 0x9370cd47U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0672 class=low score=2.650 addr=0x48100 */
void txl_he_tb_ppdu_get(void) {
  uint32_t state = 0xdba2e1a8U;
  state ^= 0x54a91e25U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x168a1325U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0x183a0025U + (state << 1U));
  (void)state;
}

/* unit=lift_0673 class=low score=2.650 addr=0x4d5cc */
void rc_check_rate_config(void) {
  uint32_t state = 0x6218b742U;
  state ^= 0x6426704aU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x26057d4aU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x28b56e4aU;
  (void)state;
}

/* unit=lift_0674 class=low score=2.650 addr=0x476c4 */
void tx_txdesc_get(void) {
  uint32_t state = 0xa884b1c2U;
  state ^= 0x154a35f9U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x576938f9U);
  }
  state ^= leaf_state[idx];
  state = (state + 0x59d92bf9U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0675 class=low score=2.650 addr=0x48464 */
void rxl_mpdu_copy(void) {
  uint32_t state = 0xbbc966beU;
  state ^= 0xc70467a1U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x85276aa1U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0x8b9779a1U + (state << 1U));
  (void)state;
}

/* unit=lift_0676 class=low score=2.650 addr=0x4b914 */
void me_sta_bw_nss_max_upd(void) {
  uint32_t state = 0xe6c2c2b2U;
  state ^= 0x037ca0c4U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x415fadc4U);
  }
  state ^= leaf_state[idx];
  state ^= (0x4fefbec4U + (state << 1U));
  (void)state;
}

/* unit=lift_0677 class=low score=2.650 addr=0x4a350 */
void ke_task_schedule(void) {
  uint32_t state = 0xa35f34d4U;
  state ^= 0x0e400f16U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x4c630216U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state = (state + 0x42d31116U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0678 class=low score=2.650 addr=0x4cb80 */
void bam_send_mm_ba_del_req(void) {
  uint32_t state = 0xb93f5eb3U;
  state ^= 0x0f82c6d9U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4c941959U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4cc332d9U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0679 class=low score=2.650 addr=0x488e4 */
void mm_key_ram_param_get(void) {
  uint32_t state = 0x7caebc18U;
  state ^= 0x5ee76710U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x1cc46a10U);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state = (state + 0x12747910U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0727 class=low score=2.650 addr=0x47888 */
void txl_buffer_machdr_get(void) {
  uint32_t state = 0x991c568cU;
  state ^= 0xd1408265U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x93638f65U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state = (state + 0x9dd39c65U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0680 class=low score=2.650 addr=0x49ff0 */
void tpc_update_frame_tx_power_1(void) {
  uint32_t state = 0x7da1bc5eU;
  state ^= 0x6bc8925aU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x29eb9f5aU);
  }
  state ^= leaf_state[idx];
  state ^= 0x275b8c5aU;
  (void)state;
}

/* unit=lift_0731 class=low score=2.650 addr=0x47d84 */
void txl_ampdu_constraints_get(void) {
  uint32_t state = 0x5fc49e92U;
  state ^= 0x9abe855fU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xd89d885fU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0xd62d9b5fU + (state << 1U));
  (void)state;
}

/* unit=lift_0732 class=low score=2.650 addr=0x4b8f8 */
void me_update_buffer_control(void) {
  uint32_t state = 0x4c664106U;
  state ^= 0x9e7186e8U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xdc528be8U);
  }
  state ^= leaf_state[idx];
  state = (state + 0xd2e298e8U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0733 class=low score=2.650 addr=0x48134 */
void txl_he_tb_transmit_trigger(void) {
  uint32_t state = 0x20354f58U;
  state ^= 0xfe8f4df7U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xbcac40f7U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= (0xb21c53f7U + (state << 1U));
  (void)state;
}

/* unit=lift_0734 class=low score=2.650 addr=0x4b8c4 */
void me_legacy_rate_bitfield_build(void) {
  uint32_t state = 0x2a40900cU;
  state ^= 0x7d28f35bU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x3f0bfe5bU);
  }
  state ^= leaf_state[idx];
  state ^= 0x31bbed5bU;
  (void)state;
}

/* unit=lift_0735 class=low score=2.650 addr=0x48940 */
void mm_back_to_host_idle(void) {
  uint32_t state = 0xce1ccb24U;
  state ^= 0xbac7264bU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xf8e42b4bU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= (0xf654384bU + (state << 1U));
  (void)state;
}

/* unit=lift_0736 class=low score=2.650 addr=0x48474 */
void rxl_mpdu_transfer(void) {
  uint32_t state = 0xddf26ad5U;
  state ^= 0xd184aa90U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x93d68b10U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x9d17b490U;
  (void)state;
}

/* unit=lift_0737 class=low score=2.650 addr=0x48ebc */
void mm_hw_config_handler(void) {
  uint32_t state = 0x74f47f6bU;
  state ^= 0x612f426fU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x237d63efU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state = (state + 0x2dbc5c6fU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0738 class=low score=2.650 addr=0x4bf54 */
void sm_bss_config_init(void) {
  uint32_t state = 0x0f93d29dU;
  state ^= 0x7a6751b8U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x38357038U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= 0x36f44fb8U;
  (void)state;
}

/* unit=lift_0739 class=low score=2.650 addr=0x4bc8c */
void sm_ft_auth_rsp_handler(void) {
  uint32_t state = 0x46d06ff8U;
  state ^= 0xe106d2dfU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xa325dfdfU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= (0xad95ccdfU + (state << 1U));
  (void)state;
}

/* unit=lift_0740 class=low score=2.650 addr=0x47d68 */
void txl_ht_vht_ampdu_param_get(void) {
  uint32_t state = 0x553f63cbU;
  state ^= 0x598a00f2U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x1bd82172U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x15191ef2U;
  (void)state;
}

/* unit=lift_0741 class=low score=2.650 addr=0x4b89c */
void me_chan_ctxt_update(void) {
  uint32_t state = 0x02f122b8U;
  state ^= 0x2e55c2f3U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x6c76cff3U);
  }
  state ^= leaf_state[idx];
  state ^= 0x62c6dcf3U;
  (void)state;
}

/* unit=lift_0742 class=low score=2.650 addr=0x47da0 */
void txl_agg_recompute_lengths(void) {
  uint32_t state = 0x10345090U;
  state ^= 0xc701c68cU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x8522cb8cU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0x8b92d88cU + (state << 1U));
  (void)state;
}

/* unit=lift_0743 class=low score=2.650 addr=0x4d64c */
void rc_update_preamble_type(void) {
  uint32_t state = 0x24dddb27U;
  state ^= 0xc4f0cb95U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x86a2ea15U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x8863d595U;
  (void)state;
}

/* unit=lift_0744 class=low score=2.650 addr=0x4a15c */
void ke_free(void) {
  uint32_t state = 0xcd3fd2f2U;
  state ^= 0xe6aee58bU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xa48de88bU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= 0xaa3dfb8bU;
  (void)state;
}

/* unit=lift_0664 class=low score=2.650 addr=0x47b38 */
void txl_frame_push(void) {
  uint32_t state = 0x0d87f958U;
  state ^= 0x02fb74c9U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x40d879c9U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0x4e686ac9U;
  (void)state;
}

/* unit=lift_0663 class=low score=2.650 addr=0x48488 */
void rxl_rxdesc_ready_for_processing(void) {
  uint32_t state = 0xa1e87dd5U;
  state ^= 0xe0841b0eU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xa2d63a8eU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state = (state + 0xac17050eU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0662 class=low score=2.650 addr=0x4bc18 */
void mm_bss_param_setting_handler(void) {
  uint32_t state = 0x11ae1198U;
  state ^= 0xe5e1babdU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xa7c2b7bdU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= 0xa972a4bdU;
  (void)state;
}

/* unit=lift_0661 class=low score=2.650 addr=0x47874 */
void rc_get_sta_stats(void) {
  uint32_t state = 0x4217df84U;
  state ^= 0xa7403785U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xe5633a85U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0xebd32985U + (state << 1U));
  (void)state;
}

/* unit=lift_0746 class=low score=2.650 addr=0x480cc */
void txl_he_edca_queue_halted(void) {
  uint32_t state = 0xbbbc3b8aU;
  state ^= 0xb3e0c1d7U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xf1c3ccd7U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state = (state + 0xff73dfd7U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0747 class=low score=2.650 addr=0x48400 */
void rxl_payload_transfer_usb(void) {
  uint32_t state = 0x103407afU;
  state ^= 0x04253656U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x467717d6U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0x48b62856U + (state << 1U));
  (void)state;
}

/* unit=lift_0748 class=low score=2.650 addr=0x478cc */
void txl_cntrl_newhead(void) {
  uint32_t state = 0xc1baba2bU;
  state ^= 0x13581aa2U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x510a3b22U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0x5fcb04a2U + (state << 1U));
  (void)state;
}

/* unit=lift_0705 class=low score=2.650 addr=0x478a0 */
void txl_cntrl_newtail(void) {
  uint32_t state = 0x9177f71cU;
  state ^= 0x0dcbdaf2U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x4fe8d7f2U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0x4158c4f2U;
  (void)state;
}

/* unit=lift_0749 class=low score=2.650 addr=0x4cb98 */
void bam_rx_active(void) {
  uint32_t state = 0xa82b5519U;
  state ^= 0x8cb7512bU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xcee570abU * i);
  }
  state ^= acc;
  uint32_t ch = (state >> 2U) & 0x1FU;
  state ^= (ch << 10U) ^ ((ch + 1U) << 5U);
  state ^= (0xc0244f2bU + (state << 1U));
  (void)state;
}

/* unit=lift_0750 class=low score=2.650 addr=0x4a150 */
void ke_malloc(void) {
  uint32_t state = 0xe6e22785U;
  state ^= 0x3956cea1U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x7b04ef21U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= (0x75c5d0a1U + (state << 1U));
  (void)state;
}

/* unit=lift_0660 class=low score=2.650 addr=0x4828c */
void rxl_frame_handle(void) {
  uint32_t state = 0x102ae8c5U;
  state ^= 0xade30ef4U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xefb12f74U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0xe17010f4U;
  (void)state;
}

/* unit=lift_0659 class=low score=2.650 addr=0x483ec */
void rxl_rxcntrl_frame(void) {
  uint32_t state = 0x4ad0a5e2U;
  state ^= 0x5e7aa432U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x1c59a932U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state = (state + 0x12e9ba32U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0658 class=low score=2.650 addr=0x49f44 */
void hal_machw_idle_req(void) {
  uint32_t state = 0x6534dd02U;
  state ^= 0xf3a4ef56U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xb0b230d7U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xb0e51b57U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0657 class=low score=2.650 addr=0x4d634 */
void rc_update_bw_nss_max(void) {
  uint32_t state = 0x62817623U;
  state ^= 0xf6935aa0U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xb4c17b20U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0xba0044a0U;
  (void)state;
}

/* unit=lift_0656 class=low score=2.650 addr=0x47a58 */
void txl_ba_push(void) {
  uint32_t state = 0x351db28bU;
  state ^= 0x29fb708bU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x6ba9510bU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state = (state + 0x65686e8bU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0655 class=low score=2.650 addr=0x4c3d0 */
void apm_bss_config_send(void) {
  uint32_t state = 0xd1f89340U;
  state ^= 0x0f62f4d4U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x4d41f9d4U);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;
  for (uint32_t si = 0U; si < 4U; ++si) {
    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));
  }
  state ^= (fsm & 0xFFU);
  state = (state + 0x43f1ead4U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0751 class=low score=2.650 addr=0x4a328 */
void ke_handler_search(void) {
  uint32_t state = 0xdb7e6445U;
  state ^= 0xf619be07U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xb44b9f87U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state ^= (0xba8aa007U + (state << 1U));
  (void)state;
}

/* unit=lift_0752 class=low score=2.650 addr=0x4bf8c */
void sm_assoc_req_send(void) {
  uint32_t state = 0xe969f0a0U;
  state ^= 0xe955c14bU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xab76cc4bU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state = (state + 0xa5c6df4bU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0730 class=low score=2.650 addr=0x47a80 */
void txl_cfm_flush_hiq(void) {
  uint32_t state = 0x2aaebfc4U;
  state ^= 0x57d93bbcU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x15fa36bcU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0x1b4a25bcU + (state << 1U));
  (void)state;
}

/* unit=lift_0754 class=low score=2.650 addr=0x47a70 */
void txl_cfm_flush(void) {
  uint32_t state = 0x1b0c36a2U;
  state ^= 0xb643c971U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xf460c471U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0xfad0d771U;
  (void)state;
}

/* unit=lift_0755 class=low score=2.650 addr=0x4c3e4 */
void apm_tx_int_ps_get_postpone(void) {
  uint32_t state = 0x5991e9c8U;
  state ^= 0xef6ca5edU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xad4fa8edU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;
  for (uint32_t si = 0U; si < 4U; ++si) {
    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));
  }
  state ^= (fsm & 0xFFU);
  state ^= (0xa3ffbbedU + (state << 1U));
  (void)state;
}

/* unit=lift_0756 class=low score=2.650 addr=0x4d608 */
void rc_check(void) {
  uint32_t state = 0xddb2047bU;
  state ^= 0x1ee5b321U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x5cb792a1U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state = (state + 0x5276ad21U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0757 class=low score=2.650 addr=0x49240 */
void mm_bcn_transmit(void) {
  uint32_t state = 0x21c7c20bU;
  state ^= 0x7ad6bda8U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x38849c28U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state = (state + 0x3645a3a8U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0758 class=low score=2.650 addr=0x4a308 */
void ke_state_set(void) {
  uint32_t state = 0xe8608704U;
  state ^= 0xd26e25b1U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x904d28b1U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state ^= (0x9efd3bb1U + (state << 1U));
  (void)state;
}

/* unit=lift_0759 class=low score=2.650 addr=0x49268 */
void apm_probe_sta_cfm(void) {
  uint32_t state = 0x6ed9843dU;
  state ^= 0x5c1dcbb6U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x1f0b1437U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0760 class=low score=2.650 addr=0x488fc */
void mm_tbtt_compute(void) {
  uint32_t state = 0xec239d13U;
  state ^= 0xc1bbb3c0U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x83e99240U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= 0x8d28adc0U;
  (void)state;
}

/* unit=lift_0761 class=low score=2.650 addr=0x488b4 */
void hal_machw_rx_bcn_duration(void) {
  uint32_t state = 0x3fe4ddf5U;
  state ^= 0xe7a03602U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xa5f21782U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state ^= 0xab332802U;
  (void)state;
}

/* unit=lift_0726 class=low score=2.650 addr=0x4d61c */
void rc_update_sample_table(void) {
  uint32_t state = 0xbc83fb88U;
  state ^= 0x65aa50feU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x27895dfeU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state = (state + 0x29394efeU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0725 class=low score=2.650 addr=0x4841c */
void rxl_payload_transfer_sdio(void) {
  uint32_t state = 0xa18366acU;
  state ^= 0x9f1d2f9eU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xdd3e229eU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0xd38e319eU + (state << 1U));
  (void)state;
}

/* unit=lift_0681 class=low score=2.650 addr=0x4b7cc */
void me_init_chan(void) {
  uint32_t state = 0xae2fdd82U;
  state ^= 0x0bb46e28U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x49976328U);
  }
  state ^= leaf_state[idx];
  state = (state + 0x47277028U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0682 class=low score=2.650 addr=0x4a424 */
void co_list_push_back(void) {
  uint32_t state = 0xd8a7483eU;
  state ^= 0x46e1311aU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x04c23c1aU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state ^= (0x0a722f1aU + (state << 1U));
  (void)state;
}

/* unit=lift_0724 class=low score=2.650 addr=0x48450 */
void rxl_go_to_last_rbd(void) {
  uint32_t state = 0x39f9cd93U;
  state ^= 0xe51396a1U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xa741b721U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0xa98088a1U;
  (void)state;
}

/* unit=lift_0723 class=low score=2.650 addr=0x4a1cc */
void ke_stateid_ptr(void) {
  uint32_t state = 0xc0a1957fU;
  state ^= 0x14bc145dU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x56ee35ddU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state = (state + 0x582f0a5dU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0683 class=low score=2.650 addr=0x4bfb8 */
void sm_external_auth_start(void) {
  uint32_t state = 0x0f01d175U;
  state ^= 0xf2635e1fU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xb0317f9fU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= 0xbef0401fU;
  (void)state;
}

/* unit=lift_0722 class=low score=2.650 addr=0x4a438 */
void co_list_push_front(void) {
  uint32_t state = 0x4a44dd0fU;
  state ^= 0xfbd06b79U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xb9824af9U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state ^= (0xb7437579U + (state << 1U));
  (void)state;
}

/* unit=lift_0721 class=low score=2.650 addr=0x491cc */
void tx_cfm(void) {
  uint32_t state = 0xf48b361aU;
  state ^= 0xd16a98aaU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x927c472bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0720 class=low score=2.650 addr=0x4d5f4 */
void rc_update_counters(void) {
  uint32_t state = 0x2e7bdbdfU;
  state ^= 0x086ceaeaU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x4a3ecb6aU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= 0x44fff4eaU;
  (void)state;
}

/* unit=lift_0719 class=low score=2.650 addr=0x48114 */
void txl_he_tb_transmit_cancelled(void) {
  uint32_t state = 0x51de3fa5U;
  state ^= 0x7cebe26cU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x3eb9c3ecU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x3078fc6cU;
  (void)state;
}

/* unit=lift_0718 class=low score=2.650 addr=0x4b8b0 */
void me_pol_tbl_bw_upd(void) {
  uint32_t state = 0x12d033b0U;
  state ^= 0x18956796U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x5ab66a96U);
  }
  state ^= leaf_state[idx];
  state = (state + 0x54067996U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0717 class=low score=2.650 addr=0x4bf68 */
void sm_bss_config_send(void) {
  uint32_t state = 0x544107e2U;
  state ^= 0x901601ccU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xd2350cccU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;
  for (uint32_t si = 0U; si < 4U; ++si) {
    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));
  }
  state ^= (fsm & 0xFFU);
  state ^= 0xdc851fccU;
  (void)state;
}

/* unit=lift_0716 class=low score=2.650 addr=0x4b8e4 */
void me_init_bcmc_rate(void) {
  uint32_t state = 0xa48aa61cU;
  state ^= 0xdb8e4842U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x99ad4542U);
  }
  state ^= leaf_state[idx];
  state ^= (0x971d5642U + (state << 1U));
  (void)state;
}

/* unit=lift_0684 class=low score=2.650 addr=0x4a33c */
void ke_task_handler_get(void) {
  uint32_t state = 0x07f0d8f9U;
  state ^= 0xfb70480dU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xb922698dU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= (0xb7e3560dU + (state << 1U));
  (void)state;
}

/* unit=lift_0715 class=low score=2.650 addr=0x480e8 */
void txl_he_mu_edca_start(void) {
  uint32_t state = 0xed758be4U;
  state ^= 0xb356e749U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xf175ea49U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0xffc5f949U;
  (void)state;
}

/* unit=lift_0714 class=low score=2.650 addr=0x47e30 */
void txl_agg_reconfig_ampdu(void) {
  uint32_t state = 0x57e5fd40U;
  state ^= 0x0d0e4e3dU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x4f2d433dU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= 0x419d503dU;
  (void)state;
}

/* unit=lift_0713 class=low score=2.650 addr=0x4d614 */
void rc_init(void) {
  uint32_t state = 0x272c3f56U;
  state ^= 0x1689ef59U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x54aae259U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0x5a1af159U + (state << 1U));
  (void)state;
}

/* unit=lift_0712 class=low score=2.650 addr=0x4a45c */
void co_list_remove(void) {
  uint32_t state = 0x9313a664U;
  state ^= 0x11930d47U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x53b00047U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= 0x5d001347U;
  (void)state;
}

/* unit=lift_0711 class=low score=2.650 addr=0x47e0c */
void txl_agg_check_rtscts_retry_limit(void) {
  uint32_t state = 0x98fa7bf2U;
  state ^= 0x4c934414U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x0eb04914U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= (0x00005a14U + (state << 1U));
  (void)state;
}

/* unit=lift_0710 class=low score=2.650 addr=0x47ddc */
void txl_agg_he_tb_cat_ampdu(void) {
  uint32_t state = 0xa4a955d3U;
  state ^= 0x7e97c33dU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x3cc5e2bdU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= 0x3204dd3dU;
  (void)state;
}

/* unit=lift_0709 class=low score=2.650 addr=0x49f68 */
void hal_machw_sleep_check(void) {
  uint32_t state = 0x0a2a1e41U;
  state ^= 0x58f043b0U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x1aa26230U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state = (state + 0x14635db0U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0685 class=low score=2.650 addr=0x4892c */
void mm_sec_machwkey_wr(void) {
  uint32_t state = 0xb5334e25U;
  state ^= 0x263b872fU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x6469a6afU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;
  for (uint32_t si = 0U; si < 4U; ++si) {
    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));
  }
  state ^= (fsm & 0xFFU);
  state ^= 0x6aa8992fU;
  (void)state;
}

/* unit=lift_0686 class=low score=2.650 addr=0x4c3bc */
void apm_bss_config_init(void) {
  uint32_t state = 0xe98f2f12U;
  state ^= 0xd2995aedU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x90ba57edU);
  }
  state ^= leaf_state[idx];
  uint32_t fsm = (state ^ 0x31415926U) & 0xFFU;
  uint32_t ev = (state >> 6U) & 0x3FU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm ^= (ev + si) << (si + 1U);
  }
  state ^= fsm;
  state ^= (0x9e0a44edU + (state << 1U));
  (void)state;
}

/* unit=lift_0687 class=low score=2.650 addr=0x48164 */
void txl_he_ampdu_param_get(void) {
  uint32_t state = 0xdb0e4889U;
  state ^= 0xe1038bb6U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xa351aa36U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0xad9095b6U;
  (void)state;
}

/* unit=lift_0708 class=low score=2.650 addr=0x48f30 */
void mm_set_resume_restore_req(void) {
  uint32_t state = 0x82723d61U;
  state ^= 0x236fcb91U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x60791411U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x602e3f91U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0707 class=low score=2.650 addr=0x49f28 */
void hal_machw_idle_irq_handler(void) {
  uint32_t state = 0x4474dc69U;
  state ^= 0x463bbddaU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x04699c5aU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state = (state + 0x0aa8a3daU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0706 class=low score=2.650 addr=0x49f9c */
void hal_machw_gen_handler(void) {
  uint32_t state = 0xc9297b5aU;
  state ^= 0xa6ac7951U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xe48f7451U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state = (state + 0xea3f6751U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0688 class=low score=2.650 addr=0x47df4 */
void txl_agg_bw_drop_handle(void) {
  uint32_t state = 0xe402d0bbU;
  state ^= 0x2a833adaU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x68d11b5aU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= 0x661024daU;
  (void)state;
}

/* unit=lift_0689 class=low score=2.650 addr=0x4a318 */
void ke_state_get(void) {
  uint32_t state = 0xeb01b991U;
  state ^= 0xdb53ebf0U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x9901ca70U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= 0x97c0f5f0U;
  (void)state;
}

/* unit=lift_0690 class=low score=2.650 addr=0x478b4 */
void txl_frame_exchange_done(void) {
  uint32_t state = 0xa15eb509U;
  state ^= 0x33b6e7bcU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x71e4c63cU * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state = (state + 0x7f25f9bcU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0691 class=low score=2.650 addr=0x47910 */
void txl_transmit_trigger(void) {
  uint32_t state = 0xf3cdeaa6U;
  state ^= 0x1905be79U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x5b26b379U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state ^= 0x5596a079U;
  (void)state;
}

/* unit=lift_0692 class=low score=2.650 addr=0x47a48 */
void txl_is_ba_valid(void) {
  uint32_t state = 0x8e67e4a1U;
  state ^= 0xb0161151U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xf24430d1U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 4U) & 0x3FU;
  uint32_t qacc = 0U;
  for (uint32_t qi = 0U; qi < 4U; ++qi) {
    qacc ^= ((qmask + qi) << (qi + 1U));
  }
  state ^= qacc;
  state = (state + 0xfc850f51U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0693 class=low score=2.650 addr=0x47dcc */
void txl_agg_split(void) {
  uint32_t state = 0x8748be9fU;
  state ^= 0x06ffc6d5U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x44ade755U * i);
  }
  state ^= acc;
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0x4a6cd8d5U + (state << 1U));
  (void)state;
}

/* unit=lift_0694 class=low score=2.650 addr=0x47dbc */
void txl_agg_set_uph(void) {
  uint32_t state = 0x92b7b89aU;
  state ^= 0x351bc893U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x7738c593U);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 3U) & 0x7FU;
  uint32_t qacc = state ^ 0x00C3C3C3U;
  for (uint32_t qi = 0U; qi < 3U; ++qi) {
    qacc = (qacc << 2U) ^ (qmask + (qi << 3U));
  }
  state ^= qacc;
  state ^= 0x7988d693U;
  (void)state;
}

/* unit=lift_0695 class=low score=2.650 addr=0x48278 */
void mm_rx_filter_set(void) {
  uint32_t state = 0x65dcd063U;
  state ^= 0x344476d6U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x76165756U * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x2468ACE0U) & 0x1FFU;
  for (uint32_t si = 0U; si < 4U; ++si) {
    fsm = ((fsm >> 1U) | (fsm << 8U)) ^ (0x11U * (si + 1U));
  }
  state ^= (fsm & 0xFFU);
  state ^= (0x78d768d6U + (state << 1U));
  (void)state;
}

/* unit=lift_0696 class=low score=2.650 addr=0x4896c */
void mm_no_idle_start(void) {
  uint32_t state = 0x6b54e315U;
  state ^= 0x0d92711eU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x4fc0509eU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= 0x41016f1eU;
  (void)state;
}

/* unit=lift_0697 class=low score=2.650 addr=0x49f58 */
void hal_machw_init(void) {
  uint32_t state = 0x72383704U;
  state ^= 0x31f8a8e3U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x73dba5e3U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state ^= (0x7d6bb6e3U + (state << 1U));
  (void)state;
}

/* unit=lift_0698 class=low score=2.650 addr=0x48958 */
void mm_force_idle_req(void) {
  uint32_t state = 0x581a4343U;
  state ^= 0xd7cd1329U;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x94dbcca9U);
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x948ce729U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

/* unit=lift_0699 class=low score=2.650 addr=0x4a44c */
void co_list_extract(void) {
  uint32_t state = 0x81455a42U;
  state ^= 0x9dedfcddU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0xdfcef1ddU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state ^= (0xd17ee2ddU + (state << 1U));
  (void)state;
}

/* unit=lift_0700 class=low score=2.650 addr=0x476b4 */
void tx_txdesc_init(void) {
  uint32_t state = 0x9442fa95U;
  state ^= 0xc463d2b9U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x8631f339U * i);
  }
  state ^= acc;
  state ^= 0x88f0ccb9U;
  (void)state;
}

/* unit=lift_0701 class=low score=2.650 addr=0x47e48 */
void txl_agg_he_tb_prep(void) {
  uint32_t state = 0x19991122U;
  state ^= 0x55d3f6fbU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x17f0fbfbU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= (0x1940e8fbU + (state << 1U));
  (void)state;
}

/* unit=lift_0702 class=low score=2.650 addr=0x4bf7c */
void sm_auth_send(void) {
  uint32_t state = 0x534e7331U;
  state ^= 0x492c323bU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x0b7e13bbU * i);
  }
  state ^= acc;
  uint32_t fsm = (state ^ 0x13579BDFU) & 0xFFU;
  for (uint32_t si = 0U; si < 3U; ++si) {
    fsm = ((fsm << 1U) | (fsm >> 7U)) ^ (0x21U + si);
  }
  state ^= fsm;
  state ^= (0x05bf2c3bU + (state << 1U));
  (void)state;
}

/* unit=lift_0703 class=low score=2.650 addr=0x499dc */
void scan_send_cancel_cfm(void) {
  uint32_t state = 0x201fe82aU;
  state ^= 0xef40271cU;
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xac56f89dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0704 class=low score=2.650 addr=0x478fc */
void txl_cntrl_halt_ac(void) {
  uint32_t state = 0xe2e7cb22U;
  state ^= 0x339a34bcU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x71b939bcU);
  }
  state ^= leaf_state[idx];
  uint32_t qmask = (state >> 5U) & 0x1FU;
  uint32_t qacc = 0x5A5A5A5AU;
  for (uint32_t qi = 0U; qi < 5U; ++qi) {
    qacc ^= ((qmask ^ qi) << ((qi & 3U) + 1U));
  }
  state ^= qacc;
  state ^= 0x7f092abcU;
  (void)state;
}

/* shared dependency implementations */

void msg_dispatch(void) {
  uint32_t state = 0x6989baf3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  msg_parse();
  state = (state ^ 0x72c7030cU) + (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x8a1363dbU);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0xb6554cdbU;
  (void)gate;
  state ^= (0x9118b75bU + (state << 1U));
  (void)state;
}

void msg_parse_thunk(void) {
  uint32_t state = 0x0ccd5efbU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_msg_alloc();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xc73a8a93U);
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xc76da113U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

void sdio_dma_init(void) {
  uint32_t state = 0xef31976aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 4) & 0x1FU];
  state ^= (sdio_st + 0x5A5A0001U);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sdio_dma_config();
  state ^= (0x78fe1df7U + (state << 1U));
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0xf127641bU);
  state ^= (gate + 0xced66f9aU) ^ ((uint32_t)5U << 5);
  (void)gate;
  state ^= (0xea2cb09aU + (state << 1U));
  (void)state;
}

void sub_101a54(void) {
  uint32_t state = 0xe7fc7534U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  sub_1320bc();
  state ^= (0x3591116dU + (state << 1U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x4c2ecd5bU);
  msg_parse_short();
  state ^= (0xb59995e3U + (state << 2U));
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x4cffe8dbU);
  state ^= (gate + 0x7068e25aU) ^ ((uint32_t)5U << 5);
  (void)gate;
  state ^= (0x57f6355aU + (state << 1U));
  (void)state;
}

void sub_10ed40(void) {
  uint32_t state = 0x098a7a9aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xa43de913U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_10ffc0(void) {
  uint32_t state = 0x3ea47ed0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  log_system_init();
  state = (state ^ 0x2e9e9d5aU) + (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x1e4e0b7bU);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0x2208247bU;
  (void)gate;
  state ^= (0x0545dffbU + (state << 1U));
  (void)state;
}

void sub_1140f4(void) {
  uint32_t state = 0xcfbbae4aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  log_enqueue();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x07bb1115U);
  state ^= chain_mix;
  (void)state;
}

void sub_114578(void) {
  uint32_t state = 0x52a3b314U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x6bf2f865U);
  state ^= chain_mix;
  (void)state;
}

void sub_114ee0(void) {
  uint32_t state = 0x65d25b02U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  rf_cmd_wait();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe47d6d33U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

void sub_115470(void) {
  uint32_t state = 0x2ef6f67aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xaf7d993fU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

void sub_116d3c(void) {
  uint32_t state = 0x7a7132f8U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x9d72624dU);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

void sub_11ecb0(void) {
  uint32_t state = 0x94f9e6aaU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  sub_12ad00();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x1144012bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_11f5e4(void) {
  uint32_t state = 0x7297ae84U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  sub_11ecb0();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x5470802dU);
  state ^= chain_mix;
  (void)state;
}

void sub_120408(void) {
  uint32_t state = 0x6eea1f4fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_11f5e4();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x9e541ce3U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_128db8(void) {
  uint32_t state = 0x5eb0993dU;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  sub_129e04();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe2d1819fU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_129e04(void) {
  uint32_t state = 0x5c995149U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_116d3c();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf761efb7U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_12ad00(void) {
  uint32_t state = 0x990cf8e4U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  sub_128db8();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xf70d707dU);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

void sub_12c6b8(void) {
  uint32_t state = 0x489ed6e6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  buffer_pool_manage();
  state = (state + 0xd43f7b6dU) ^ (state >> 1U);
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0xaed7525dU);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0x91f7345dU;
  (void)gate;
  state ^= 0xb5dc86ddU;
  (void)state;
}

void sub_12c798(void) {
  uint32_t state = 0x1bfae8feU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  buffer_pool_manage();
  state = (state ^ 0xd491426dU) + (state >> 1U);
  gate = (gate << 1) | (gate >> 31);
  state ^= (gate & 0xd1091613U);
  state ^= ((gate >> 7U) | (gate << 25U)) + 0xed4f3913U;
  (void)gate;
  state ^= (0xca02c293U + (state << 1U));
  (void)state;
}

void sub_12d050(void) {
  uint32_t state = 0x09ba8f58U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd0b95201U);
  state = (state + chain_mix) ^ (chain_mix >> 3U);
  (void)state;
}

void sub_12d464(void) {
  uint32_t state = 0xd7a48e79U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  math_helper();
  state ^= (0x6ef51295U + (state << 1U));
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x817e5293U);
  state ^= (gate + 0xbe8f5912U) ^ ((uint32_t)5U << 5);
  (void)gate;
  state ^= 0x9a758612U;
  (void)state;
}

void sub_130030(void) {
  uint32_t state = 0x4ee2d287U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4605a8a1U);
  state ^= chain_mix;
  (void)state;
}

void sub_1342f4(void) {
  uint32_t state = 0x660cd4e2U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_13b82c();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x00da1d5bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_1365c0(void) {
  uint32_t state = 0x67d6feb4U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_1342f4();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x46af083bU);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

void sub_137490(void) {
  uint32_t state = 0x07792f74U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state >> 3) ^ 0x6d2b79f5U;
  sub_1365c0();
  chain_mix = (chain_mix << 1) ^ (chain_mix >> 5) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xd1e9e853U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

void sub_13b82c(void) {
  uint32_t state = 0x407778e9U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  sub_140c5c();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xbca0ffd7U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

void sub_140c5c(void) {
  uint32_t state = 0x9100b1a6U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0xe57fb74dU);
  state ^= chain_mix;
  (void)state;
}

void sub_142f2c(void) {
  uint32_t state = 0x553bb668U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x79240a13U);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}
