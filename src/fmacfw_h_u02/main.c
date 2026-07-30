/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_h_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void log_queue_alloc(void);
void clock_calc(void);
void feature_guard_sdio(void);
void log_flush(void);
void usb_wlan_recv(void);
void usb_wlan_recv_fc_on(void);
void log_system_init_mode2(void);
void log_printf(void);
void mm_set_vif_state_cfm_handler(void);
void mm_sta_del_cfm_handler(void);
void mm_scan_channel_start_ind_handler(void);
void mm_bcn_change_cfm_handler(void);
void mm_set_arpoffload_en_req_handler(void);
void msg_register_handler(void);
void rf_timer_toggle_update(void);
void ipc_emb_kmsg_fwd(void);
void idle_processing(void);
void log_free_wrapper(void);
void msg_parse_short(void);
void mm_scan_channel_end_ind_handler(void);
void wlan_epbulk_recv_compl_handler(void);
void ps_upm_enter(void);
void usb_wlan_rx_pkt_free_list_init(void);
void ipc_emb_hostmsgbuf_get(void);
void memset_impl(void);
void panic_loop(void);
void main_loop(void);
void list_find_remove(void);
void mm_key_add_req_handler(void);
void clear_flags(void);
void sdio_replenish_rx_msgqueue(void);
void mac_phy_init(void);
void log_queue_refill(void);
void log_pool_config(void);
void list_remove_node(void);
void log_pool_default_config(void);
void scan_start_req_handler(void);
void rf_timer_abort_common(void);
void list_insert_sorted(void);
void log_free_pool_d(void);
void log_free_pool_c(void);
void log_free_pool_b(void);
void log_free_pool_a(void);
void mm_rx_filter_set(void);
void mm_key_ram_param_get(void);
void mm_set_resume_restore_req(void);
void mm_cfg_rssi_req_handler(void);
void log_pool_init_d(void);
void log_pool_init_e(void);
void me_rc_set_rate_req_handler(void);
void rwnxl_reset_evt(void);
void rf_timer_abort1(void);
void rf_timer_abort2(void);
void fw_config_copy(void);
void clear_sdio_state(void);
void fp_convert_uint(void);
void rx_queue_head_init(void);
void log_pool_alloc_b(void);
void log_pool_init_b(void);
void log_free_pool_e(void);
void log_free_pool_f(void);
void log_pool_init_c(void);
void log_pool_init_a(void);
void memset_thunk(void);
void buffer_pool_get(void);
void log_pool_alloc(void);
void log_pool_alloc2(void);
void log_alloc(void);
void log_pool_init_queue(void);
void sdio_rx_evt(void);
void log_queue_push2(void);
void ke_msg_alloc(void);
void mm_timer_schedule(void);
void mm_timer_set(void);
void mm_tbtt_evt(void);
void mm_bcn_transmitted(void);
void wlan_epbulk_send_compl_handler(void);
void msg_parse(void);
void mm_bcn_update_p2p_noa(void);
void mm_sleepinfo_rx_evt(void);
void mm_set_idle_req_handler(void);
void mm_start_req_handler(void);
void mm_key_del_req_handler(void);
void sm_connect_req_handler(void);
void timestamp_list_contains(void);
void get_variant_cached(void);
void ipc_emb_hostrxbuf_get(void);
void msg_handler_tx(void);
void log_free_dispatch(void);
void log_global_init(void);
void log_ptr_in_range(void);
void rx_queue_init(void);
void subsystems_init(void);
void mm_sec_machwkey_wr(void);
void math_round(void);
void math_helper_big2(void);
void mm_no_idle_start(void);
void math_fastpath(void);
void math_helper_int(void);
void mm_tbtt_compute(void);
void queue_pending_check(void);
void uart_puts(void);
void mm_set_idle_cfm_handler(void);
void mm_sta_add_cfm_handler(void);
void rf_bus_reset_n_90_bc6c(void);
void mm_hw_config_handler(void);
void mm_bss_param_setting_handler(void);
void usb_trans_error_handler(void);
void rwnxl_wakeup(void);
void ps_upm_exit(void);
void ps_enable_cfm(void);
void ps_disable_cfm(void);
void usb_rx_evt(void);
void emb_kmsg_hdlr(void);
void msg_get_value(void);
void log_tick(void);
void log_system_init(void);
void ipc_rx_evt(void);
void hw_event_flag(void);
void timer_set_relative(void);
void scan_cancel_req_handler(void);
void mm_force_idle_req_handler(void);
void timestamp_update(void);
void mm_set_ps_mode_cfm_handler(void);
void mm_ba_add_cfm_handler(void);
void mm_set_ps_options_req_handler(void);
void uart_putc(void);
void ke_timer_clear(void);
void rf_bus_reset_n_42e(void);
void ke_evt_schedule(void);
void apm_start_req_handler(void);
void apm_start_cac_req_handler(void);
void lpm_host_notify_bt(void);
void apm_stop_cac_req_handler(void);
void usb_init(void);
void parse_int(void);
void mm_bcn_transmit(void);
void hal_machw_abs_timer_handler(void);
void hal_dma_evt(void);
void me_config_monitor_req_handler(void);
void me_set_ps_disable_cfm_handler(void);
void timestamp_remove(void);
void debug_if_40320038(void);
void intc_spurious(void);
void txl_cfm_evt(void);
void me_set_active_cfm_handler(void);
void feature_flags_init(void);
void parse_width_suffix(void);
void get_cached_1828f8(void);
void me_data_path_flushed_ind_handler(void);
void mm_back_to_host_idle(void);
void mm_force_idle_req(void);
void apm_sta_connect_past_timer_handle(void);
void memcpy_fast(void);
void phy_stop(void);
void phy_get_rf_gain_idx(void);
void phy_set_channel(void);
void host_id(void);
void phy_get_channel(void);
void host_sdio_replenish_rx_queue(void);
void host_usb_wlan_init(void);
void phy_get_txpwr_level(void);
void phy_hw_set_channel(void);
void apm_tx_int_ps_get_postpone(void);
void apm_bss_config_init(void);
void hal_machw_rx_bcn_duration(void);
void apm_probe_sta_cfm(void);
void ke_state_set(void);
void rc_check(void);
void rxl_payload_transfer_sdio(void);
void txl_cfm_flush(void);
void txl_frame_exchange_chain(void);
void sm_assoc_req_send(void);
void ke_handler_search(void);
void ke_malloc(void);
void bam_rx_active(void);
void txl_cntrl_newhead(void);
void rc_update_sample_table(void);
void rxl_payload_transfer_usb(void);
void apm_bss_config_send(void);
void txl_ba_push(void);
void rc_update_bw_nss_max(void);
void txl_buffer_machdr_get(void);
void bam_send_air_action_frame(void);
void rc_init_rates(void);
void txl_cfm_flush_hiq(void);
void txl_ampdu_constraints_get(void);
void me_update_buffer_control(void);
void txl_he_tb_transmit_trigger(void);
void me_legacy_rate_bitfield_build(void);
void rxl_mpdu_transfer(void);
void sm_bss_config_init(void);
void sm_ft_auth_rsp_handler(void);
void txl_ht_vht_ampdu_param_get(void);
void me_chan_ctxt_update(void);
void txl_agg_recompute_lengths(void);
void rc_update_preamble_type(void);
void hal_machw_idle_req(void);
void rxl_rxcntrl_frame(void);
void rxl_frame_handle(void);
void rc_get_sta_stats(void);
void ke_free(void);
void txl_he_edca_queue_halted(void);
void rxl_rxdesc_ready_for_processing(void);
void txl_frame_push(void);
void ke_task_local(void);
void tpc_update_frame_tx_power(void);
void sm_assoc_rsp_handler(void);
void sm_ft_auth_over_air_start(void);
void rxl_payload_transfer(void);
void txl_he_trigger_push(void);
void txl_he_tb_ppdu_get(void);
void rxl_go_to_last_rbd(void);
void ke_stateid_ptr(void);
void rc_check_rate_config(void);
void tx_txdesc_get(void);
void co_list_push_front(void);
void tx_cfm(void);
void rxl_mpdu_copy(void);
void rc_update_counters(void);
void txl_he_tb_transmit_cancelled(void);
void me_pol_tbl_bw_upd(void);
void sm_bss_config_send(void);
void me_init_bcmc_rate(void);
void txl_he_mu_edca_start(void);
void txl_agg_reconfig_ampdu(void);
void me_sta_bw_nss_max_upd(void);
void ke_task_schedule(void);
void rc_init(void);
void co_list_remove(void);
void txl_agg_check_rtscts_retry_limit(void);
void txl_agg_he_tb_cat_ampdu(void);
void hal_machw_sleep_check(void);
void bam_send_mm_ba_del_req(void);
void tpc_update_frame_tx_power_1(void);
void me_init_chan(void);
void co_list_push_back(void);
void hal_machw_idle_irq_handler(void);
void hal_machw_gen_handler(void);
void txl_cntrl_newtail(void);
void sm_external_auth_start(void);
void ke_task_handler_get(void);
void txl_he_ampdu_param_get(void);
void log_free_dispatch_n48c(void);
void scan_send_cancel_cfm(void);
void sm_auth_send(void);
void txl_agg_bw_drop_handle(void);
void ke_state_get(void);
void txl_frame_exchange_done(void);
void txl_transmit_trigger(void);
void txl_is_ba_valid(void);
void txl_agg_split(void);
void txl_agg_set_uph(void);
void hal_machw_init(void);
void txl_agg_he_tb_prep(void);
void co_list_extract(void);
void tx_txdesc_init(void);
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
void tx_dequeue(void);
int tx_submit(...);
int log_hw_init(...);
int sdio_transfer(...);
int log_queue_push(...);
int rf_cmd_queue_next(...);
int thunk(...);
int list_push_tail(...);
int list_pop(...);
int sdio_buffer_prepare(...);
int timer_init(...);
int crypto_mac_core(...);
int rf_stream_start(...);
int rf_stream_start2(...);
int irq_nesting_or(...);
int rf_hw_timer_read(...);
int rf_level_compute(...);
int rf_level_step(...);
int hw_config_init(...);
int sdio_status_check(...);
int crypto_power_apply(...);
int event_queue_push(...);
int message_dispatch(...);
int crypto_mac_dispatch(...);
int error_handler(...);
int tx_init(...);
int rf_power_set(...);


/* unit=lift_0001 class=critical score=22.733 addr=0x11017c */
void log_queue_alloc(void) {
  msg_parse();
  tx_submit();
  log_hw_init();
  sdio_transfer();
  log_queue_push();
  rf_cmd_queue_next();
  thunk();
  list_push_tail();
  list_pop();
  sdio_buffer_prepare();
}

/* unit=lift_0005 class=critical score=20.836 addr=0x1031d8 */
void clock_calc(void) {
  // post: may invoke dependency helper chain
  // evidence: class=strong score=2.73
  uint32_t state = 0x5666cd88U;
  // Clock calculation: bounded divider and status settle
  volatile uint32_t *clk = (volatile uint32_t *)(uintptr_t)0x40035000U;
  uint32_t raw_div = clk[0] & 0x1FU;
  uint32_t frac = (clk[1] ^ 0x5666cd88U) & 0x3FFU;
  uint32_t div = raw_div + 1U;
  clk[2] = (div << 8U) | frac;
  clk[3] |= 1U;
  for (uint32_t wait = 0U; wait < 8U; ++wait) {
    uint32_t st = clk[3];
    state ^= st + div + frac + wait;
    if ((st & 1U) == 0U) { break; }
    clk[3] &= ~1U;
  }
  state ^= clk[2] ^ clk[4];
  timer_init();
  if ((state & 0x1U) == 0U) { log_tick(); }
  if ((state & 0x1U) == 0U) { timestamp_update(); }
  (void)state;
}

/* unit=lift_0011 class=critical score=20.049 addr=0x12eb90 */
void feature_guard_sdio(void) {
  // pre: expects readable MMIO/peripheral state
  // post: may invoke dependency helper chain
  // evidence: class=strong score=2.74
  uint32_t state = 0x512f3f50U;
  // Descriptor motif: bounded hardware polling loop
  volatile uint32_t *poll = (volatile uint32_t *)(uintptr_t)0x40000000U;
  uint32_t command = state ^ 0x3C6EF35FU;
  poll[1] = command;
  poll[2] = 1U;
  for (uint32_t wait = 128U; wait > 0U; --wait) {
    uint32_t status = poll[0] & 0xFFU;
    state ^= status + wait + poll[1];
    if ((status & 1U) == 0U) { break; }
    if ((wait & 7U) == 0U) { poll[0] &= ~1U; }
  }
  poll[3] = state ^ command;
  clock_calc();
  if ((state & 0x2U) == 0U) { crypto_mac_core(); }
  poll[2] = 0U;
  (void)state;
}

/* unit=lift_0032 class=critical score=17.780 addr=0x113578 */
void log_flush(void) {
  log_printf();
  rf_stream_start();
  rf_stream_start2();
}

/* unit=lift_0028 class=critical score=17.258 addr=0x46d10 */
void usb_wlan_recv(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0021 class=critical score=17.232 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0030 class=critical score=17.072 addr=0x10f382 */
void log_system_init_mode2(void) {
  // post: may invoke dependency helper chain
  // evidence: class=medium score=2.05
  uint32_t state = 0xe92dea0aU;
  // State machine: pattern derived from behavioral class state_machine
  uint32_t cur_state = state & 0x7U;
  uint32_t next_state = cur_state;
  volatile uint32_t *sm_reg = (volatile uint32_t *)(uintptr_t)0x402dea00U;
  switch (cur_state) {
  case 0U: sm_reg[0U] = 0xe92dea0aU; next_state = 1U; break;
  case 1U: sm_reg[1U] = 0xe92dea19U; next_state = 2U; break;
  case 2U: sm_reg[2U] = 0xe92dea2cU; next_state = 3U; break;
  case 3U: sm_reg[3U] = 0xe92dea33U; next_state = 0U; break;
  default: sm_reg[0] = 0xBADF0000U; next_state = 0U; break;
  }
  sm_reg[cur_state] = next_state;
  state = (state & ~0x7U) | next_state;
  log_system_init();
  if ((state & 0x1U) == 0U) { log_hw_init(); }
  if ((state & 0x1U) == 0U) { log_global_init(); }
  (void)state;
}

/* unit=lift_0042 class=critical score=17.036 addr=0x10dae4 */
void log_printf(void) {
  log_flush();
}

/* unit=lift_0181 class=critical score=17.011 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0211 class=critical score=17.007 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0183 class=critical score=16.989 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0192 class=critical score=16.982 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0176 class=critical score=16.978 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0002 class=critical score=16.676 addr=0x12cbf4 */
void msg_register_handler(void) {
  msg_parse();
  subsystems_init();
  irq_nesting_or();
  list_push_tail();
  sub_137490();
}

/* unit=lift_0641 class=critical score=16.672 addr=0x130370 */
void rf_timer_toggle_update(void) {
  // pre: expects readable MMIO/peripheral state
  // post: may invoke dependency helper chain
  // post: may update timer/scheduling state
  // evidence: class=strong score=2.91
  uint32_t state = 0x9258f6f6U;
  // Descriptor motif: register commit with bounded ack wait
  volatile uint32_t *regs = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t reg = 0x1eU & 0x1FU;
  uint32_t value = state ^ 0xff1388e7U;
  uint32_t shadow = value ^ 0x55AA00FFU;
  regs[0] = reg;
  regs[1] = value;
  regs[2] = shadow;
  regs[3] = 1U;
  for (uint32_t wait = 52U; wait > 0U; --wait) {
    uint32_t mirror = regs[2] ^ shadow;
    uint32_t ack = regs[3] & 1U;
    state ^= regs[1] ^ mirror ^ ack ^ wait;
    if ((wait & 7U) == 0U) { regs[1] ^= (wait << 1U); }
    if ((wait & 3U) == 0U) { regs[3] = 0U; }
    if (ack == 0U) { break; }
  }
  regs[4] = regs[1] ^ shadow ^ state;
  rf_hw_timer_read();
  if ((state & 0x2U) == 0U) { rf_level_compute(); }
  if ((state & 0x4U) == 0U) { rf_level_step(); }
  if ((state & 1U) == 0U) { regs[5] ^= state; }
  (void)state;
}

/* unit=lift_0050 class=critical score=16.644 addr=0x46030 */
void ipc_emb_kmsg_fwd(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0003 class=critical score=16.589 addr=0x1159a4 */
void idle_processing(void) {
  // post: may invoke dependency helper chain
  // evidence: class=low score=1.45
  uint32_t state = 0x37b07301U;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000e400U;
  uint32_t pending = nvic[0];
  if (pending & 0x37b07301U) {
    nvic[0x0U] = pending & ~0x37b07301U;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x40007300U;
  timer[0] = state;
  state ^= timer[0U & 0x3U];
  (void)state;
}

/* unit=lift_0054 class=critical score=16.497 addr=0x10f230 */
void log_free_wrapper(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0031 class=critical score=16.479 addr=0x12f35c */
void msg_parse_short(void) {
  sub_101a54();
}

/* unit=lift_0208 class=critical score=16.470 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0029 class=critical score=16.438 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0024 class=critical score=16.415 addr=0x4971c */
void ps_upm_enter(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0026 class=critical score=16.405 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0049 class=critical score=16.339 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0073 class=critical score=15.575 addr=0x100202 */
void memset_impl(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0093 class=critical score=15.475 addr=0x1006d8 */
void panic_loop(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0009 class=critical score=15.278 addr=0x115c20 */
void main_loop(void) {
  idle_processing();
  clock_calc();
  sub_114578();
  sub_115470();
  sub_12d050();
  sub_130030();
}

/* unit=lift_0063 class=critical score=14.945 addr=0x12c8fc */
void list_find_remove(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0195 class=critical score=14.761 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0043 class=critical score=14.718 addr=0x12d00c */
void clear_flags(void) {
  // post: may invoke dependency helper chain
  // evidence: class=medium score=2.34
  uint32_t state = 0x6bc2d086U;
  // Descriptor motif: bounded hardware polling loop
  volatile uint32_t *poll = (volatile uint32_t *)(uintptr_t)0x40000000U;
  uint32_t command = state ^ 0x3C6EF35FU;
  poll[1] = command;
  poll[2] = 1U;
  for (uint32_t wait = 128U; wait > 0U; --wait) {
    uint32_t status = poll[0] & 0xFFU;
    state ^= status + wait + poll[1];
    if ((status & 1U) == 0U) { break; }
    if ((wait & 7U) == 0U) { poll[0] &= ~1U; }
  }
  poll[3] = state ^ command;
  rx_queue_init();
  if ((state & 0x2U) == 0U) { clear_sdio_state(); }
  poll[2] = 0U;
  (void)state;
}

/* unit=lift_0046 class=critical score=14.648 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0016 class=critical score=14.628 addr=0x1205e0 */
void mac_phy_init(void) {
  sub_116d3c();
  sub_11ecb0();
  sub_11f5e4();
  sub_120408();
  sub_128db8();
  sub_129e04();
  sub_12ad00();
}

/* unit=lift_0081 class=critical score=14.627 addr=0x1103c4 */
void log_queue_refill(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0072 class=critical score=14.519 addr=0x10f24c */
void log_pool_config(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0059 class=critical score=14.401 addr=0x12d1a8 */
void list_remove_node(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0053 class=critical score=14.266 addr=0x10f23c */
void log_pool_default_config(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0202 class=critical score=14.243 addr=0x49928 */
void scan_start_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0095 class=critical score=14.124 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  rf_timer_abort1();
  rf_timer_abort2();
  sub_10ed40();
  sub_114ee0();
}

/* unit=lift_0091 class=critical score=14.037 addr=0x12d240 */
void list_insert_sorted(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0037 class=critical score=13.894 addr=0x113908 */
void log_free_pool_d(void) {
  log_free_dispatch();
}

/* unit=lift_0036 class=critical score=13.894 addr=0x110380 */
void log_free_pool_c(void) {
  log_free_dispatch();
}

/* unit=lift_0035 class=critical score=13.894 addr=0x1102f0 */
void log_free_pool_b(void) {
  log_free_dispatch();
}

/* unit=lift_0034 class=critical score=13.894 addr=0x110250 */
void log_free_pool_a(void) {
  log_free_dispatch();
}

/* unit=lift_0695 class=critical score=13.857 addr=0x48278 */
void mm_rx_filter_set(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0679 class=critical score=13.818 addr=0x488e4 */
void mm_key_ram_param_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0708 class=critical score=13.787 addr=0x48f30 */
void mm_set_resume_restore_req(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0188 class=critical score=13.735 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0039 class=critical score=13.434 addr=0x113888 */
void log_pool_init_d(void) {
  log_system_init_mode2();
}

/* unit=lift_0038 class=critical score=13.434 addr=0x1136d4 */
void log_pool_init_e(void) {
  log_system_init_mode2();
}

/* unit=lift_0210 class=critical score=13.378 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0013 class=critical score=13.331 addr=0x47674 */
void rwnxl_reset_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0642 class=critical score=13.293 addr=0x12ef94 */
void rf_timer_abort1(void) {
  rf_timer_abort_common();
}

/* unit=lift_0643 class=critical score=13.289 addr=0x12efb0 */
void rf_timer_abort2(void) {
  rf_timer_abort_common();
}

/* unit=lift_0008 class=critical score=13.253 addr=0x10f0c4 */
void fw_config_copy(void) {
  // post: may invoke dependency helper chain
  // evidence: class=low score=1.35
  uint32_t state = 0x78645865U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  hw_config_init();
  state = (state + 0xefbdb640U) ^ (state >> 1U);
  gate = (gate >> 1) | (gate << 31);
  state ^= (gate & 0x7e6160a9U);
  state ^= ((gate << 1U) | (gate >> 31U)) ^ 0x414106a9U;
  (void)gate;
  state ^= (0x656ab429U + (state << 1U));
  (void)state;
}

/* unit=lift_0071 class=critical score=12.973 addr=0x10d2c4 */
void clear_sdio_state(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=1.33
  uint32_t state = 0xd2991b3aU;
  // State machine: pattern derived from behavioral class state_machine
  uint32_t cur_state = state & 0x7U;
  uint32_t next_state = cur_state;
  volatile uint32_t *sm_reg = (volatile uint32_t *)(uintptr_t)0x40991b00U;
  switch (cur_state) {
  case 0U: sm_reg[0U] = 0xd2991b3aU; next_state = 1U; break;
  case 1U: sm_reg[1U] = 0xd2991b29U; next_state = 2U; break;
  case 2U: sm_reg[2U] = 0xd2991b1cU; next_state = 3U; break;
  case 3U: sm_reg[3U] = 0xd2991b03U; next_state = 0U; break;
  default: sm_reg[0] = 0xBADF0000U; next_state = 0U; break;
  }
  sm_reg[cur_state] = next_state;
  state = (state & ~0x7U) | next_state;
  sdio_status_check();
  if ((state & 0x1U) == 0U) { feature_guard_sdio(); }
  if ((state & 0x1U) == 0U) { sdio_transfer(); }
  (void)state;
}

/* unit=lift_0010 class=critical score=12.942 addr=0x12d5a0 */
void fp_convert_uint(void) {
  // post: may invoke dependency helper chain
  // evidence: class=low score=1.32
  uint32_t state = 0x61318a68U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t gate = state ^ 0x6d2b79f5U;
  uint32_t flow_budget = 0U;
  flow_budget = 4U;
  if (flow_budget == 0U) { flow_budget = 1U; }
  crypto_power_apply();
  state ^= 0x58bb390eU;
  gate = (gate >> 2) | (gate << 30);
  state ^= (gate & 0x8b7b8f71U);
  state ^= gate ^ 0xb428cdf0U;
  (void)gate;
  state ^= (0x90705bf0U + (state << 1U));
  (void)state;
}

/* unit=lift_0075 class=critical score=12.742 addr=0x12c954 */
void rx_queue_head_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0077 class=critical score=12.724 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0067 class=critical score=12.724 addr=0x11004c */
void log_pool_init_b(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0082 class=critical score=12.724 addr=0x11414c */
void log_free_pool_e(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0062 class=critical score=12.724 addr=0x1137c4 */
void log_free_pool_f(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0057 class=critical score=12.724 addr=0x11013c */
void log_pool_init_c(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0065 class=critical score=12.724 addr=0x1100e4 */
void log_pool_init_a(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0068 class=critical score=12.714 addr=0x100200 */
void memset_thunk(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0012 class=critical score=12.710 addr=0x12ca88 */
void buffer_pool_get(void) {
  // post: may invoke dependency helper chain
  // evidence: class=medium score=2.07
  uint32_t state = 0xe6089c67U;
  // Descriptor motif: queue/ring pump with bounded backlog drain
  enum { QCAP = 16 };
  static uint32_t ring[QCAP];
  static uint32_t q_head, q_tail, q_count;
  uint32_t item = state ^ 0xac65a046U;
  if (q_count == QCAP) {
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_count--;
  }
  ring[q_tail] = item;
  q_tail = (q_tail + 1U) & (QCAP - 1U);
  q_count++;
  uint32_t budget = (state & 7U) + 4U;
  while (q_count > 0U && budget-- > 0U) {
    state ^= ring[q_head] + budget;
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_count--;
  }
  event_queue_push();
  if ((state & 0x2U) == 0U) { message_dispatch(); }
  if ((state & 0x4U) == 0U) { sub_12c6b8(); }
  (void)state;
}

/* unit=lift_0078 class=critical score=12.636 addr=0x110340 */
void log_pool_alloc(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0088 class=critical score=12.632 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0089 class=critical score=12.614 addr=0x10fe7c */
void log_alloc(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0094 class=critical score=12.614 addr=0x1100a4 */
void log_pool_init_queue(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0048 class=critical score=12.607 addr=0x4686c */
void sdio_rx_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0086 class=critical score=12.580 addr=0x110edc */
void log_queue_push2(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0203 class=critical score=12.500 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0200 class=critical score=12.196 addr=0x49180 */
void mm_timer_schedule(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0175 class=critical score=12.170 addr=0x49170 */
void mm_timer_set(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0191 class=critical score=12.125 addr=0x48920 */
void mm_tbtt_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0667 class=critical score=12.115 addr=0x4922c */
void mm_bcn_transmitted(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0027 class=critical score=12.084 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0004 class=critical score=12.081 addr=0x12e948 */
void msg_parse(void) {
  clock_calc();
  log_queue_alloc();
  msg_register_handler();
  crypto_mac_dispatch();
  tx_dequeue();
  msg_dispatch();
  error_handler();
}

/* unit=lift_0666 class=critical score=12.071 addr=0x49250 */
void mm_bcn_update_p2p_noa(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0174 class=critical score=12.070 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0193 class=critical score=12.055 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0204 class=critical score=12.025 addr=0x48e40 */
void mm_start_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0172 class=critical score=12.025 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0184 class=critical score=12.021 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0058 class=critical score=11.844 addr=0x124e3c */
void timestamp_list_contains(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0076 class=critical score=11.803 addr=0x1006cc */
void get_variant_cached(void) {
  // evidence: class=low score=0.79
  uint32_t state = 0x796f4320U;
  // Descriptor motif: queue/ring pump with bounded backlog drain
  enum { QCAP = 16 };
  static uint32_t ring[QCAP];
  static uint32_t q_head, q_tail, q_count;
  uint32_t item = state ^ 0x33027f01U;
  if (q_count == QCAP) {
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_count--;
  }
  ring[q_tail] = item;
  q_tail = (q_tail + 1U) & (QCAP - 1U);
  q_count++;
  uint32_t budget = (state & 7U) + 4U;
  while (q_count > 0U && budget-- > 0U) {
    state ^= ring[q_head] + budget;
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_count--;
  }
  (void)state;
}

/* unit=lift_0644 class=critical score=11.564 addr=0x46008 */
void ipc_emb_hostrxbuf_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0006 class=critical score=11.546 addr=0x102970 */
void msg_handler_tx(void) {
  tx_init();
  msg_parse_thunk();
  crypto_mac_dispatch();
}

/* unit=lift_0041 class=critical score=11.475 addr=0x10fec8 */
void log_free_dispatch(void) {
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  log_free_pool_d();
}

/* unit=lift_0087 class=critical score=11.144 addr=0x10f270 */
void log_global_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0052 class=critical score=11.133 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0040 class=critical score=10.974 addr=0x12d0d0 */
void rx_queue_init(void) {
  clear_flags();
}

/* unit=lift_0007 class=critical score=10.896 addr=0x132088 */
void subsystems_init(void) {
  msg_register_handler();
  sub_1342f4();
  sub_1365c0();
  sub_137490();
  sub_13b82c();
  sub_140c5c();
}

/* unit=lift_0685 class=critical score=10.698 addr=0x4892c */
void mm_sec_machwkey_wr(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0083 class=critical score=10.690 addr=0x1424dc */
void math_round(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0066 class=critical score=10.686 addr=0x1425fc */
void math_helper_big2(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0696 class=critical score=10.683 addr=0x4896c */
void mm_no_idle_start(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0061 class=critical score=10.683 addr=0x12d3e0 */
void math_fastpath(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0090 class=critical score=10.675 addr=0x142e9c */
void math_helper_int(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0760 class=critical score=10.657 addr=0x488fc */
void mm_tbtt_compute(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0084 class=critical score=10.346 addr=0x12a32c */
void queue_pending_check(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0060 class=critical score=10.316 addr=0x10d674 */
void uart_puts(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0206 class=critical score=9.994 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0199 class=critical score=9.990 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0187 class=critical score=9.961 addr=0x4bc6c */
void rf_bus_reset_n_90_bc6c(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0737 class=critical score=8.846 addr=0x48ebc */
void mm_hw_config_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0662 class=critical score=8.768 addr=0x4bc18 */
void mm_bss_param_setting_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0019 class=high score=11.683 addr=0x47010 */
void usb_trans_error_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0022 class=high score=11.661 addr=0x47664 */
void rwnxl_wakeup(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0017 class=high score=11.433 addr=0x4972c */
void ps_upm_exit(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0018 class=high score=11.396 addr=0x496fc */
void ps_enable_cfm(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0023 class=high score=11.370 addr=0x4970c */
void ps_disable_cfm(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0015 class=high score=11.232 addr=0x47004 */
void usb_rx_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0014 class=high score=10.885 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  // pre: expects non-null message/context buffers
  // evidence: class=low score=0.00
  uint32_t state = 0xdaa61edfU;
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

/* unit=lift_0033 class=high score=10.758 addr=0x12cd48 */
void msg_get_value(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0044 class=high score=10.041 addr=0x10f058 */
void log_tick(void) {
  rf_power_set();
}

/* unit=lift_0045 class=high score=9.996 addr=0x10f318 */
void log_system_init(void) {
  sub_10ffc0();
}

/* unit=lift_0047 class=high score=9.952 addr=0x47060 */
void ipc_rx_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0080 class=high score=9.791 addr=0x111fbc */
void hw_event_flag(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x9e3f98c2U;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000e9c0U;
  uint32_t pending = nvic[0];
  if (pending & 0x9e3f98c3U) {
    nvic[0x0U] = pending & ~0x9e3f98c3U;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x400f98c0U;
  timer[0] = state;
  state ^= timer[0U & 0x3U];
  (void)state;
}

/* unit=lift_0055 class=high score=9.735 addr=0x12c4a4 */
void timer_set_relative(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0207 class=high score=9.721 addr=0x4999c */
void scan_cancel_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0185 class=high score=9.700 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0085 class=high score=9.683 addr=0x124bfc */
void timestamp_update(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0198 class=high score=9.633 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0173 class=high score=9.611 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0194 class=high score=9.592 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0051 class=high score=9.566 addr=0x10d65c */
void uart_putc(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0178 class=high score=9.405 addr=0x4a078 */
void ke_timer_clear(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0209 class=high score=9.390 addr=0x4a068 */
void rf_bus_reset_n_42e(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0201 class=high score=9.361 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0182 class=high score=9.253 addr=0x4c20c */
void apm_start_req_handler(void) {
  // pre: expects non-null message/context buffers
  // evidence: class=low score=0.00
  uint32_t state = 0x57a74914U;
  // Error handler: pattern derived from behavioral class error_handler
  volatile uint32_t *status = (volatile uint32_t *)(uintptr_t)0x40004914U;
  uint32_t fault = status[0] & 0xFU;
  volatile uint32_t *dump = (volatile uint32_t *)(uintptr_t)0x20004910U;
  for (uint32_t i = 0U; i < 4U; ++i) {
    dump[i] = status[i];
  }
  dump[4U] = state;
  dump[5U] = fault;
  uint32_t spin = 16U + (fault & 0xFU);
  while (spin-- > 0U) {
    __asm__ volatile("wfi");
    state ^= spin ^ fault;
  }
  state ^= fault;
  (void)state;
}

/* unit=lift_0186 class=high score=9.253 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  // pre: expects non-null message/context buffers
  // evidence: class=low score=0.00
  uint32_t state = 0x588f4a4aU;
  // Error handler: pattern derived from behavioral class error_handler
  volatile uint32_t *status = (volatile uint32_t *)(uintptr_t)0x40004a48U;
  uint32_t fault = status[0] & 0xFU;
  volatile uint32_t *dump = (volatile uint32_t *)(uintptr_t)0x20004a40U;
  for (uint32_t i = 0U; i < 4U; ++i) {
    dump[i] = status[i];
  }
  dump[4U] = state;
  dump[5U] = fault;
  uint32_t spin = 16U + (fault & 0xFU);
  while (spin-- > 0U) {
    __asm__ volatile("wfi");
    state ^= spin ^ fault;
  }
  state ^= fault;
  (void)state;
}

/* unit=lift_0020 class=high score=9.089 addr=0x46044 */
void lpm_host_notify_bt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0189 class=high score=9.011 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  // pre: expects non-null message/context buffers
  // evidence: class=low score=0.00
  uint32_t state = 0xb351f4ceU;
  // Error handler: pattern derived from behavioral class error_handler
  volatile uint32_t *status = (volatile uint32_t *)(uintptr_t)0x4000f4ccU;
  uint32_t fault = status[0] & 0xFU;
  volatile uint32_t *dump = (volatile uint32_t *)(uintptr_t)0x2000f4c0U;
  for (uint32_t i = 0U; i < 4U; ++i) {
    dump[i] = status[i];
  }
  dump[4U] = state;
  dump[5U] = fault;
  uint32_t spin = 16U + (fault & 0xFU);
  while (spin-- > 0U) {
    __asm__ volatile("wfi");
    state ^= spin ^ fault;
  }
  state ^= fault;
  (void)state;
}

/* unit=lift_0650 class=high score=8.944 addr=0x46a70 */
void usb_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0079 class=high score=8.472 addr=0x12f818 */
void parse_int(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0757 class=high score=8.470 addr=0x49240 */
void mm_bcn_transmit(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0190 class=high score=8.433 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  // pre: expects non-null message/context buffers
  // pre: expects readable MMIO/peripheral state
  // post: may update timer/scheduling state
  // evidence: class=low score=0.39
  uint32_t state = 0xde693d4bU;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000ee40U;
  uint32_t pending = nvic[0];
  if (pending & 0xde693d4bU) {
    nvic[0x2U] = pending & ~0xde693d4bU;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x40093d40U;
  timer[0] = state;
  state ^= timer[0U & 0x3U];
  (void)state;
}

/* unit=lift_0197 class=high score=8.348 addr=0x49fc4 */
void hal_dma_evt(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x8ed91973U;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000ea70U;
  uint32_t pending = nvic[0];
  if (pending & 0x8ed91973U) {
    nvic[0x4U] = pending & ~0x8ed91973U;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x40091970U;
  timer[0] = state;
  state ^= timer[3U & 0x3U];
  (void)state;
}

/* unit=lift_0212 class=high score=8.218 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0205 class=high score=8.002 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0070 class=high score=7.969 addr=0x124cf4 */
void timestamp_remove(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0064 class=high score=7.924 addr=0x101924 */
void debug_if_40320038(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xe727723fU;
  state ^= 0x08cebb0cU;
  uint32_t chain_mix = (state << 5) ^ 0x6d2b79f5U;
  uart_putc();
  chain_mix = (chain_mix >> 3) ^ (chain_mix << 4) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x4bd8648dU);
  state ^= chain_mix;
  (void)state;
}

/* unit=lift_0025 class=high score=7.862 addr=0x44258 */
void intc_spurious(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x598c949cU;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000e590U;
  uint32_t pending = nvic[0];
  if (pending & 0x598c949dU) {
    nvic[0x7U] = pending & ~0x598c949dU;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x400c9490U;
  timer[0] = state;
  state ^= timer[1U & 0x3U];
  (void)state;
}

/* unit=lift_0179 class=high score=7.734 addr=0x47a64 */
void txl_cfm_evt(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0177 class=high score=7.685 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0074 class=high score=7.630 addr=0x12f3a8 */
void feature_flags_init(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xd32cfc84U;
  // Init sequence: pattern derived from behavioral class system_init
  volatile uint32_t *cfg = (volatile uint32_t *)(uintptr_t)0x4000fc84U;
  uint32_t mask = 0U;
  cfg[0U] = 0xd32cfc84U;
  mask |= cfg[0U];
  cfg[1U] = 0xd22dfd85U;
  mask |= cfg[1U];
  cfg[2U] = 0xd12efe86U;
  mask |= cfg[2U];
  cfg[3U] = 0xd02fff87U;
  mask |= cfg[3U];
  cfg[4U] = mask;
  state ^= mask;
  (void)state;
}

/* unit=lift_0092 class=high score=7.383 addr=0x12f8ec */
void parse_width_suffix(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0056 class=high score=7.358 addr=0x1018f0 */
void get_cached_1828f8(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x1eb14572U;
  state ^= 0xd810aacbU;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  timestamp_list_contains();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x9b06754bU);
  state = (state ^ chain_mix) + ((chain_mix >> 5U) & 0xFFFFU);
  (void)state;
}

/* unit=lift_0196 class=high score=7.233 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0735 class=high score=7.215 addr=0x48940 */
void mm_back_to_host_idle(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0698 class=high score=7.200 addr=0x48958 */
void mm_force_idle_req(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0180 class=high score=7.197 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  // post: may update timer/scheduling state
  // evidence: class=low score=0.00
  uint32_t state = 0x3839a2ebU;
  // Interrupt handler: pattern derived from behavioral class timer_callback
  volatile uint32_t *nvic = (volatile uint32_t *)(uintptr_t)0xe000e3e0U;
  uint32_t pending = nvic[0];
  if (pending & 0x3839a2ebU) {
    nvic[0x2U] = pending & ~0x3839a2ebU;
    state ^= pending;
  } else {
    state ^= 0xDEAD0001U;
  }
  volatile uint32_t *timer = (volatile uint32_t *)(uintptr_t)0x4009a2e0U;
  timer[0] = state;
  state ^= timer[2U & 0x3U];
  (void)state;
}

/* unit=lift_0069 class=medium score=5.851 addr=0x143630 */
void memcpy_fast(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0646 class=low score=3.050 addr=0x44224 */
void phy_stop(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0647 class=low score=3.050 addr=0x441c8 */
void phy_get_rf_gain_idx(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0645 class=low score=3.050 addr=0x44204 */
void phy_set_channel(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0648 class=low score=3.050 addr=0x4c722 */
void host_id(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xc68b2823U;
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

/* unit=lift_0654 class=low score=3.050 addr=0x44214 */
void phy_get_channel(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0653 class=low score=3.050 addr=0x4684c */
void host_sdio_replenish_rx_queue(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x3722247fU;
  state ^= 0xa750db7dU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xe502fafdU * i);
  }
  state ^= acc;
  uint32_t ch = (state >> 2U) & 0x1FU;
  state ^= (ch << 10U) ^ ((ch + 1U) << 5U);
  state ^= (0xebc3c57dU + (state << 1U));
  (void)state;
}

/* unit=lift_0652 class=low score=3.050 addr=0x46fe0 */
void host_usb_wlan_init(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xb2df309eU;
  state ^= 0x6d897cf6U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x2faa71f6U);
  }
  state ^= leaf_state[idx];
  uint32_t ch = state & 0xFU;
  state ^= (ch << 12U) ^ ((ch + 3U) << 4U);
  state = (state + 0x211a62f6U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0651 class=low score=3.050 addr=0x441dc */
void phy_get_txpwr_level(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0649 class=low score=3.050 addr=0x441a8 */
void phy_hw_set_channel(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0755 class=low score=2.650 addr=0x4c3e4 */
void apm_tx_int_ps_get_postpone(void) {
  // evidence: class=low score=0.00
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

/* unit=lift_0686 class=low score=2.650 addr=0x4c3bc */
void apm_bss_config_init(void) {
  // evidence: class=low score=0.00
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

/* unit=lift_0761 class=low score=2.650 addr=0x488b4 */
void hal_machw_rx_bcn_duration(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x8313d22dU;
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

/* unit=lift_0759 class=low score=2.650 addr=0x49268 */
void apm_probe_sta_cfm(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x1f10fe8cU;
  state ^= 0x5c1dcbb6U;
  uint32_t chain_mix = state ^ 0x6d2b79f5U;
  ke_evt_schedule();
  chain_mix = (chain_mix << 5) ^ (chain_mix >> 2) ^ 0x9e3779b9U;
  state ^= (chain_mix & 0x1f0b1437U);
  state ^= (chain_mix << 1U) | (chain_mix >> 31U);
  (void)state;
}

/* unit=lift_0758 class=low score=2.650 addr=0x4a308 */
void ke_state_set(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0756 class=low score=2.650 addr=0x4d608 */
void rc_check(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0725 class=low score=2.650 addr=0x4841c */
void rxl_payload_transfer_sdio(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0754 class=low score=2.650 addr=0x47a70 */
void txl_cfm_flush(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0753 class=low score=2.650 addr=0x478e0 */
void txl_frame_exchange_chain(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0752 class=low score=2.650 addr=0x4bf8c */
void sm_assoc_req_send(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0751 class=low score=2.650 addr=0x4a328 */
void ke_handler_search(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0750 class=low score=2.650 addr=0x4a150 */
void ke_malloc(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0749 class=low score=2.650 addr=0x4cb98 */
void bam_rx_active(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xd24dfc63U;
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

/* unit=lift_0748 class=low score=2.650 addr=0x478cc */
void txl_cntrl_newhead(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0726 class=low score=2.650 addr=0x4d61c */
void rc_update_sample_table(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0747 class=low score=2.650 addr=0x48400 */
void rxl_payload_transfer_usb(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0655 class=low score=2.650 addr=0x4c3d0 */
void apm_bss_config_send(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x175934ceU;
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

/* unit=lift_0656 class=low score=2.650 addr=0x47a58 */
void txl_ba_push(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0657 class=low score=2.650 addr=0x4d634 */
void rc_update_bw_nss_max(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0727 class=low score=2.650 addr=0x47888 */
void txl_buffer_machdr_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0728 class=low score=2.650 addr=0x4cb64 */
void bam_send_air_action_frame(void) {
  // evidence: class=low score=0.00
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

/* unit=lift_0729 class=low score=2.650 addr=0x4d5e4 */
void rc_init_rates(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0730 class=low score=2.650 addr=0x47a80 */
void txl_cfm_flush_hiq(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0731 class=low score=2.650 addr=0x47d84 */
void txl_ampdu_constraints_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0732 class=low score=2.650 addr=0x4b8f8 */
void me_update_buffer_control(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0733 class=low score=2.650 addr=0x48134 */
void txl_he_tb_transmit_trigger(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0734 class=low score=2.650 addr=0x4b8c4 */
void me_legacy_rate_bitfield_build(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0736 class=low score=2.650 addr=0x48474 */
void rxl_mpdu_transfer(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0738 class=low score=2.650 addr=0x4bf54 */
void sm_bss_config_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0739 class=low score=2.650 addr=0x4bc8c */
void sm_ft_auth_rsp_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0740 class=low score=2.650 addr=0x47d68 */
void txl_ht_vht_ampdu_param_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0741 class=low score=2.650 addr=0x4b89c */
void me_chan_ctxt_update(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0742 class=low score=2.650 addr=0x47da0 */
void txl_agg_recompute_lengths(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0743 class=low score=2.650 addr=0x4d64c */
void rc_update_preamble_type(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0658 class=low score=2.650 addr=0x49f44 */
void hal_machw_idle_req(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x881751f7U;
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

/* unit=lift_0659 class=low score=2.650 addr=0x483ec */
void rxl_rxcntrl_frame(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0660 class=low score=2.650 addr=0x4828c */
void rxl_frame_handle(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0661 class=low score=2.650 addr=0x47874 */
void rc_get_sta_stats(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0744 class=low score=2.650 addr=0x4a15c */
void ke_free(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0746 class=low score=2.650 addr=0x480cc */
void txl_he_edca_queue_halted(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0663 class=low score=2.650 addr=0x48488 */
void rxl_rxdesc_ready_for_processing(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0664 class=low score=2.650 addr=0x47b38 */
void txl_frame_push(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0665 class=low score=2.650 addr=0x45fe0 */
void ke_task_local(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0745 class=low score=2.650 addr=0x49fd4 */
void tpc_update_frame_tx_power(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0668 class=low score=2.650 addr=0x4bfa0 */
void sm_assoc_rsp_handler(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0669 class=low score=2.650 addr=0x4bfd0 */
void sm_ft_auth_over_air_start(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0670 class=low score=2.650 addr=0x48438 */
void rxl_payload_transfer(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0671 class=low score=2.650 addr=0x48150 */
void txl_he_trigger_push(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0672 class=low score=2.650 addr=0x48100 */
void txl_he_tb_ppdu_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0724 class=low score=2.650 addr=0x48450 */
void rxl_go_to_last_rbd(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0723 class=low score=2.650 addr=0x4a1cc */
void ke_stateid_ptr(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0673 class=low score=2.650 addr=0x4d5cc */
void rc_check_rate_config(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0674 class=low score=2.650 addr=0x476c4 */
void tx_txdesc_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0722 class=low score=2.650 addr=0x4a438 */
void co_list_push_front(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xcc38205fU;
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
  // TODO: integrate control/data flow.
}

/* unit=lift_0675 class=low score=2.650 addr=0x48464 */
void rxl_mpdu_copy(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0720 class=low score=2.650 addr=0x4d5f4 */
void rc_update_counters(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0719 class=low score=2.650 addr=0x48114 */
void txl_he_tb_transmit_cancelled(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0718 class=low score=2.650 addr=0x4b8b0 */
void me_pol_tbl_bw_upd(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0717 class=low score=2.650 addr=0x4bf68 */
void sm_bss_config_send(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0716 class=low score=2.650 addr=0x4b8e4 */
void me_init_bcmc_rate(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0715 class=low score=2.650 addr=0x480e8 */
void txl_he_mu_edca_start(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0714 class=low score=2.650 addr=0x47e30 */
void txl_agg_reconfig_ampdu(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0676 class=low score=2.650 addr=0x4b914 */
void me_sta_bw_nss_max_upd(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0677 class=low score=2.650 addr=0x4a350 */
void ke_task_schedule(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0713 class=low score=2.650 addr=0x4d614 */
void rc_init(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0712 class=low score=2.650 addr=0x4a45c */
void co_list_remove(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xe2471bebU;
  state ^= 0x11930d47U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x53c12cc7U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 4U) & 0xFFU;
  state ^= ((irq << 7U) | (irq >> 1U));
  state ^= 0x5d001347U;
  (void)state;
}

/* unit=lift_0711 class=low score=2.650 addr=0x47e0c */
void txl_agg_check_rtscts_retry_limit(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0710 class=low score=2.650 addr=0x47ddc */
void txl_agg_he_tb_cat_ampdu(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0709 class=low score=2.650 addr=0x49f68 */
void hal_machw_sleep_check(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x5685dcbcU;
  state ^= 0x58f043b0U;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x1ad34eb0U);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state = (state + 0x14635db0U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0678 class=low score=2.650 addr=0x4cb80 */
void bam_send_mm_ba_del_req(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0xf761ad7aU;
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

/* unit=lift_0680 class=low score=2.650 addr=0x49ff0 */
void tpc_update_frame_tx_power_1(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0681 class=low score=2.650 addr=0x4b7cc */
void me_init_chan(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0682 class=low score=2.650 addr=0x4a424 */
void co_list_push_back(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x11466223U;
  state ^= 0x46e1311aU;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0x04b3109aU * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 1U) & 0x3FFU;
  state ^= (irq << 3U) ^ (irq >> 2U);
  state ^= (0x0a722f1aU + (state << 1U));
  (void)state;
}

/* unit=lift_0707 class=low score=2.650 addr=0x49f28 */
void hal_machw_idle_irq_handler(void) {
  // pre: expects non-null message/context buffers
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x88bc64f8U;
  state ^= 0x463bbddaU;
  static uint32_t leaf_state[8];
  uint32_t idx = state & 7U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    uint32_t mix = (state << (i & 7U)) ^ (state >> ((8U - i) & 7U));
    leaf_state[(idx + i) & 7U] ^= mix + (i * 0x0418b0daU);
  }
  state ^= leaf_state[idx];
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state = (state + 0x0aa8a3daU) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0706 class=low score=2.650 addr=0x49f9c */
void hal_machw_gen_handler(void) {
  // pre: expects non-null message/context buffers
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x6badd473U;
  state ^= 0xa6ac7951U;
  uint32_t acc = state ^ 0xA5A5A5A5U;
  for (uint32_t i = 0U; i < 8U; ++i) {
    acc = (acc << 3) | (acc >> 29);
    acc ^= (state >> (i & 7U)) + (0xe4fe58d1U * i);
  }
  state ^= acc;
  uint32_t irq = (state >> 2U) & 0x1FFU;
  state ^= ((irq << 5U) | (irq >> 4U));
  state = (state + 0xea3f6751U) ^ (state >> 2U);
  (void)state;
}

/* unit=lift_0705 class=low score=2.650 addr=0x478a0 */
void txl_cntrl_newtail(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0683 class=low score=2.650 addr=0x4bfb8 */
void sm_external_auth_start(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0684 class=low score=2.650 addr=0x4a33c */
void ke_task_handler_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0687 class=low score=2.650 addr=0x48164 */
void txl_he_ampdu_param_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0704 class=low score=2.650 addr=0x478fc */
void log_free_dispatch_n48c(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0703 class=low score=2.650 addr=0x499dc */
void scan_send_cancel_cfm(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0702 class=low score=2.650 addr=0x4bf7c */
void sm_auth_send(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0688 class=low score=2.650 addr=0x47df4 */
void txl_agg_bw_drop_handle(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0689 class=low score=2.650 addr=0x4a318 */
void ke_state_get(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0690 class=low score=2.650 addr=0x478b4 */
void txl_frame_exchange_done(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0691 class=low score=2.650 addr=0x47910 */
void txl_transmit_trigger(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0692 class=low score=2.650 addr=0x47a48 */
void txl_is_ba_valid(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0693 class=low score=2.650 addr=0x47dcc */
void txl_agg_split(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0694 class=low score=2.650 addr=0x47dbc */
void txl_agg_set_uph(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0697 class=low score=2.650 addr=0x49f58 */
void hal_machw_init(void) {
  // pre: expects readable MMIO/peripheral state
  // evidence: class=low score=0.00
  uint32_t state = 0x2853cf26U;
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

/* unit=lift_0701 class=low score=2.650 addr=0x47e48 */
void txl_agg_he_tb_prep(void) {
  // TODO: integrate control/data flow.
}

/* unit=lift_0699 class=low score=2.650 addr=0x4a44c */
void co_list_extract(void) {
  // evidence: class=low score=0.00
  uint32_t state = 0x276ef59eU;
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
  // TODO: integrate control/data flow.
}

/* shared dependency implementations */

void msg_dispatch(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void msg_parse_thunk(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sdio_dma_init(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_101a54(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_10ed40(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_10ffc0(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_1140f4(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_114578(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_114ee0(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_115470(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_116d3c(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_11ecb0(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_11f5e4(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_120408(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_128db8(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_129e04(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_12ad00(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_12c6b8(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_12c798(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_12d050(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_12d464(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_130030(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_1342f4(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_1365c0(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_137490(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_13b82c(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_140c5c(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void sub_142f2c(void) {
  // dependency implementation emitted from mined call graph evidence.
}

void tx_dequeue(void) {
  // dependency implementation emitted from mined call graph evidence.
}

