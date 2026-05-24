/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_h_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void tx_dequeue(void);
void idle_processing(void);
void rwnxl_reset_evt(void);
void emb_kmsg_hdlr(void);
void usb_rx_evt(void);
void mac_phy_init(void);
void intc_spurious(void);
void usb_wlan_recv(void);
void usb_trans_error_handler(void);
void lpm_host_notify_bt(void);
void usb_wlan_recv_fc_on(void);
void rwnxl_wakeup(void);
void ps_disable_cfm(void);
void ps_upm_enter(void);
void ps_upm_exit(void);
void usb_wlan_rx_pkt_free_list_init(void);
void wlan_epbulk_send_compl_handler(void);
void ps_enable_cfm(void);
void wlan_epbulk_recv_compl_handler(void);
void log_system_init_mode2(void);
void msg_parse_short(void);
void log_flush(void);
void msg_get_value(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_pool_init_e(void);
void rx_queue_init(void);
void clear_flags(void);
void log_printf(void);
void log_tick(void);
void log_system_init(void);
void ipc_emb_kmsg_fwd(void);
void ipc_emb_hostmsgbuf_get(void);
void sdio_rx_evt(void);
void ipc_rx_evt(void);
void sdio_replenish_rx_msgqueue(void);
void parse_int(void);
void log_free_wrapper(void);
void math_round(void);
void log_free_pool_e(void);
void log_queue_refill(void);
void hw_event_flag(void);
void list_insert_sorted(void);
void log_pool_alloc(void);
void log_pool_alloc_b(void);
void get_variant_cached(void);
void rx_queue_head_init(void);
void feature_flags_init(void);
void memset_impl(void);
void log_pool_config(void);
void clear_sdio_state(void);
void timestamp_remove(void);
void memcpy_fast(void);
void memset_thunk(void);
void log_pool_init_b(void);
void math_helper_big2(void);
void parse_width_suffix(void);
void panic_loop(void);
void log_pool_init_queue(void);
void debug_if_40320038(void);
void log_pool_init_a(void);
void timestamp_update(void);
void log_queue_push2(void);
void log_global_init(void);
void log_pool_alloc2(void);
void log_alloc(void);
void math_helper_int(void);
void uart_putc(void);
void log_ptr_in_range(void);
void log_pool_default_config(void);
void queue_pending_check(void);
void timer_set_relative(void);
void get_cached_1828f8(void);
void log_pool_init_c(void);
void timestamp_list_contains(void);
void list_remove_node(void);
void uart_puts(void);
void math_fastpath(void);
void log_free_pool_f(void);
void list_find_remove(void);
void rf_timer_abort_common(void);
void me_data_path_flushed_ind_handler(void);
void mm_chan_ctxt_unlink_cfm_handler(void);
void mm_tbtt_evt(void);
void mm_bcn_change_cfm_handler(void);
void mm_set_idle_req_handler(void);
void mm_set_ps_options_req_handler(void);
void mm_ba_add_cfm_handler(void);
void hal_dma_evt(void);
void mm_set_ps_mode_cfm_handler(void);
void mm_sta_add_cfm_handler(void);
void mm_key_del_req_handler(void);
void mm_timer_schedule(void);
void ke_evt_schedule(void);
void scan_start_req_handler(void);
void ke_msg_alloc(void);
void mm_start_req_handler(void);
void me_set_ps_disable_cfm_handler(void);
void mm_set_idle_cfm_handler(void);
void scan_cancel_req_handler(void);
void mm_scan_channel_end_ind_handler(void);
void ke_timer_set(void);
void me_rc_set_rate_req_handler(void);
void mm_sta_del_cfm_handler(void);
void me_config_monitor_req_handler(void);
void hal_machw_abs_timer_handler(void);
void apm_stop_cac_req_handler(void);
void mm_set_arpoffload_en_req_handler(void);
void mm_timer_set(void);
void mm_key_add_req_handler(void);
void mm_cfg_rssi_req_handler(void);
void mm_sleepinfo_rx_evt(void);
void apm_start_cac_req_handler(void);
void mm_force_idle_req_handler(void);
void sm_connect_req_handler(void);
void mm_scan_channel_start_ind_handler(void);
void apm_start_req_handler(void);
void mm_set_vif_state_cfm_handler(void);
void apm_sta_connect_past_timer_handle(void);
void txl_cfm_evt(void);
void ke_timer_clear(void);
void me_set_active_cfm_handler(void);
void feature_guard_sdio(void);
void list_pop(void);
void list_push_tail(void);
void log_hw_init(void);
void log_pool_init_d(void);
void main_loop(void);
void queue_check(void);
void rf_timer_abort1(void);
void rf_timer_abort2(void);
void state_flag_check(void);
void sub_101a54(void);
void sub_10ed40(void);
void sub_10ffc0(void);
void sub_1140f4(void);
void sub_114ee0(void);
void sub_116d3c(void);
void sub_11ecb0(void);
void sub_11f5e4(void);
void sub_120408(void);
void sub_128db8(void);
void sub_129e04(void);
void sub_12ad00(void);
void thunk(void);
void tx_submit(void);
void tx_timeout_check(void);
void log_queue_push(void);
void msg_parse(void);
void ipc_doorbell_handler(void);
void sdio_status_check(void);
void rf_stream_start(void);
void rf_stream_start2(void);
void log_free_dispatch(void);
void rf_power_set(void);
void sdio_wait_busy(void);
void crypto_hw_clear_regs(void);
void crypto_power_calc(void);
void log_free_pool_d(void);
void buffer_pool_manage(void);
void crypto_hw_enable(void);
void hw_config_init(void);
void irq_vector_init(void);
void sdio_transfer(void);
void sub_137490(void);
void sdio_buffer_prepare(void);
void log_enqueue(void);
void sub_1435d0(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void sub_1320bc(void);
void rf_cmd_wait(void);
void buffer_pool_get(void);
void rf_cmd_queue_next(void);
void error_handler(void);


/* unit=lift_0001 class=critical score=11.250 addr=0x11017c */
void tx_dequeue(void) {
  uint32_t state = 0xb6edc8afU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: transmit dequeue helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: dequeue transmit work
  list_push_tail();
  log_hw_init();
  log_queue_push();
  msg_parse();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0002 class=critical score=9.950 addr=0x1159a4 */
void idle_processing(void) {
  uint32_t state = 0x149ecfecU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: idle processing helper
  // step 1: process current inputs
  // callers observed: 1
  // step 2: invoke specialized support sequence
  feature_guard_sdio();
  ipc_doorbell_handler();
  queue_check();
  sdio_status_check();
  // step 3: commit processed results
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0003 class=high score=7.200 addr=0x47674 */
void rwnxl_reset_evt(void) {
  uint32_t state = 0x7b5a1ea4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rwnxl reset event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0004 class=high score=7.200 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  uint32_t state = 0xffb2e5f5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: embedded kernel message handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0005 class=high score=7.200 addr=0x47004 */
void usb_rx_evt(void) {
  uint32_t state = 0x77b12e31U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: usb rx helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0006 class=high score=6.450 addr=0x1205e0 */
void mac_phy_init(void) {
  uint32_t state = 0x8569b088U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)7U << 8);
  // reconstructed control: initialization leaf
  // step 1: initialize local state
  // step 2: execute likely callee chain
  sub_116d3c();
  sub_11ecb0();
  sub_11f5e4();
  sub_120408();
  sub_128db8();
  sub_129e04();
  sub_12ad00();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0007 class=high score=6.000 addr=0x44258 */
void intc_spurious(void) {
  uint32_t state = 0x9dcfa86fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: spurious interrupt handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0008 class=high score=6.000 addr=0x46d10 */
void usb_wlan_recv(void) {
  uint32_t state = 0x6ec4e850U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: usb wlan recv helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rx_queue_init();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0009 class=high score=6.000 addr=0x47010 */
void usb_trans_error_handler(void) {
  uint32_t state = 0x295d8510U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: usb trans error helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0010 class=high score=6.000 addr=0x46044 */
void lpm_host_notify_bt(void) {
  uint32_t state = 0x01ae889eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: notification helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0011 class=high score=6.000 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  uint32_t state = 0x3d660361U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: usb wlan recv fc on helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rx_queue_init();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0012 class=high score=6.000 addr=0x47664 */
void rwnxl_wakeup(void) {
  uint32_t state = 0x1e8ff9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: wakeup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0013 class=high score=6.000 addr=0x4970c */
void ps_disable_cfm(void) {
  uint32_t state = 0xf62fb945U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: disable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0014 class=high score=6.000 addr=0x4971c */
void ps_upm_enter(void) {
  uint32_t state = 0x5b8c4c46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: power-management enter helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0015 class=high score=6.000 addr=0x4972c */
void ps_upm_exit(void) {
  uint32_t state = 0x31cf247fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: power-management exit helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0016 class=high score=6.000 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  uint32_t state = 0x52d7f4cbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: usb wlan rx pkt free list init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  list_insert_sorted();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0017 class=high score=6.000 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  uint32_t state = 0xe019fcb6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: wlan epbulk send compl helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0018 class=high score=6.000 addr=0x496fc */
void ps_enable_cfm(void) {
  uint32_t state = 0x6bc4b05dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: enable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0019 class=high score=6.000 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  uint32_t state = 0x57bf1991U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: wlan epbulk recv compl helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0020 class=high score=5.510 addr=0x10f382 */
void log_system_init_mode2(void) {
  uint32_t state = 0xe92dea0aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: logging system init mode2 helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_pool_init_e();
  log_pool_init_d();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0021 class=medium score=5.450 addr=0x12f35c */
void msg_parse_short(void) {
  uint32_t state = 0x0c388e05U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: short message parser helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: parse message payload
  sub_101a54();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0022 class=medium score=5.280 addr=0x113578 */
void log_flush(void) {
  uint32_t state = 0x729efc41U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging flush helper
  // step 1: prepare logging context
  // step 2: emit log output
  log_printf();
  rf_stream_start();
  rf_stream_start2();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0023 class=medium score=5.200 addr=0x12cd48 */
void msg_get_value(void) {
  uint32_t state = 0x57bc4751U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: message value getter
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0024 class=medium score=5.170 addr=0x110250 */
void log_free_pool_a(void) {
  uint32_t state = 0x0b479444U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free pool stage a helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: reclaim log pool resources
  log_free_dispatch();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0025 class=medium score=5.170 addr=0x1102f0 */
void log_free_pool_b(void) {
  uint32_t state = 0xcd507620U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free pool stage b helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: reclaim log pool resources
  log_free_dispatch();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0026 class=medium score=4.710 addr=0x1136d4 */
void log_pool_init_e(void) {
  uint32_t state = 0xe2d507c2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: logging pool initialization stage e helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_system_init_mode2();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0027 class=medium score=4.580 addr=0x12d0d0 */
void rx_queue_init(void) {
  uint32_t state = 0xde6da939U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: queue initialization helper
  // step 1: initialize local state
  // step 2: process queue state
  clear_flags();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0028 class=medium score=4.480 addr=0x12d00c */
void clear_flags(void) {
  uint32_t state = 0xdbba3ca0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: clear flags helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rx_queue_init();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0029 class=medium score=4.480 addr=0x10dae4 */
void log_printf(void) {
  uint32_t state = 0x0d51deacU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: logging printf helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: emit log output
  log_flush();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0030 class=medium score=4.350 addr=0x10f058 */
void log_tick(void) {
  uint32_t state = 0xa4d6592bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: logging tick helper
  // step 1: prepare logging context
  // step 2: advance log tick state
  rf_power_set();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0031 class=medium score=4.250 addr=0x10f318 */
void log_system_init(void) {
  uint32_t state = 0x8934f629U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging system init helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  sub_10ffc0();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0032 class=medium score=4.250 addr=0x46030 */
void ipc_emb_kmsg_fwd(void) {
  uint32_t state = 0x3bda296eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: ipc emb kmsg fwd helper
  // step 1: load/update local state inferred from callers and edges
  // step 2: handle message state
  sdio_wait_busy();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0033 class=medium score=4.250 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  uint32_t state = 0x5d5c4831U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: ipc emb hostmsgbuf get helper
  // step 1: read local state
  // step 2: handle message state
  sdio_wait_busy();
  // step 3: return observed value
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0034 class=medium score=4.250 addr=0x4686c */
void sdio_rx_evt(void) {
  uint32_t state = 0xbdded9deU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: sdio rx helper
  // step 1: capture event context
  // step 2: dispatch event-specific state transitions
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: finalize event callback path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0035 class=medium score=4.250 addr=0x47060 */
void ipc_rx_evt(void) {
  uint32_t state = 0xe98e6f67U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: ipc rx event callback
  // step 1: capture event context
  // step 2: dispatch event-specific state transitions
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: finalize event callback path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0036 class=medium score=4.250 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  uint32_t state = 0x6ea61f76U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: replenish rx msgqueue helper
  // step 1: prepare outbound work
  // step 2: refill SDIO RX queue
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0037 class=medium score=4.000 addr=0x12f818 */
void parse_int(void) {
  uint32_t state = 0xe5122d66U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: parsing helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0038 class=medium score=4.000 addr=0x10f230 */
void log_free_wrapper(void) {
  uint32_t state = 0x5d2341a6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free wrapper helper
  // step 1: prepare logging context
  // step 2: handle logging state
  log_free_pool_d();
  log_free_pool_a();
  log_free_pool_b();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0039 class=medium score=4.000 addr=0x1424dc */
void math_round(void) {
  uint32_t state = 0x4151eb00U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: math round helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_helper_int();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0040 class=medium score=4.000 addr=0x11414c */
void log_free_pool_e(void) {
  uint32_t state = 0x74549085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free pool stage e helper
  // step 1: prepare logging context
  // step 2: reclaim log pool resources
  log_free_pool_d();
  log_free_pool_a();
  log_free_pool_b();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0041 class=medium score=4.000 addr=0x1103c4 */
void log_queue_refill(void) {
  uint32_t state = 0x6f00da2eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging queue refill helper
  // step 1: prepare outbound work
  // step 2: refill logging queue
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0042 class=medium score=4.000 addr=0x111fbc */
void hw_event_flag(void) {
  uint32_t state = 0x2f3562fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: hw event flag helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0043 class=medium score=4.000 addr=0x12d240 */
void list_insert_sorted(void) {
  uint32_t state = 0xa2f9634eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: container/list insert sorted helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  list_remove_node();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0044 class=medium score=4.000 addr=0x110340 */
void log_pool_alloc(void) {
  uint32_t state = 0x2d375d09U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool alloc helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_d();
  log_pool_init_e();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0045 class=medium score=4.000 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  uint32_t state = 0xc4155b74U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool alloc b helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_d();
  log_pool_init_e();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0046 class=medium score=4.000 addr=0x1006cc */
void get_variant_cached(void) {
  uint32_t state = 0xcaf16145U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: cache lookup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_list_contains();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0047 class=medium score=4.000 addr=0x12c954 */
void rx_queue_head_init(void) {
  uint32_t state = 0x090c7309U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: queue head init
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  list_insert_sorted();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0048 class=medium score=4.000 addr=0x12f3a8 */
void feature_flags_init(void) {
  uint32_t state = 0xe67e9269U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: flag initialization helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0049 class=medium score=4.000 addr=0x100202 */
void memset_impl(void) {
  uint32_t state = 0xfd7582d1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: memset impl
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0050 class=medium score=4.000 addr=0x10f24c */
void log_pool_config(void) {
  uint32_t state = 0x5d2219ddU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool config helper
  // step 1: prepare logging context
  // step 2: apply firmware state
  crypto_hw_enable();
  hw_config_init();
  irq_vector_init();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0051 class=medium score=4.000 addr=0x10d2c4 */
void clear_sdio_state(void) {
  uint32_t state = 0x53d71acaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: clear sdio state
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sdio_status_check();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0052 class=medium score=4.000 addr=0x124cf4 */
void timestamp_remove(void) {
  uint32_t state = 0x69bf7b4eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_list_contains();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0053 class=medium score=4.000 addr=0x143630 */
void memcpy_fast(void) {
  uint32_t state = 0xc83eac46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: memcpy fast
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0054 class=medium score=4.000 addr=0x100200 */
void memset_thunk(void) {
  uint32_t state = 0xf7b2d400U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: memset thunk
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0055 class=medium score=4.000 addr=0x11004c */
void log_pool_init_b(void) {
  uint32_t state = 0xbf525065U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool initialization stage b helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0056 class=medium score=4.000 addr=0x1425fc */
void math_helper_big2(void) {
  uint32_t state = 0x62877966U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: numeric aggregation leaf
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0057 class=medium score=4.000 addr=0x12f8ec */
void parse_width_suffix(void) {
  uint32_t state = 0xae0a8b3aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: parsing helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0058 class=medium score=4.000 addr=0x1006d8 */
void panic_loop(void) {
  uint32_t state = 0x3fdee989U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: panic/abort helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0059 class=medium score=4.000 addr=0x1100a4 */
void log_pool_init_queue(void) {
  uint32_t state = 0x8418f82aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool init queue helper
  // step 1: initialize local state
  // step 2: initialize logging state
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0060 class=medium score=4.000 addr=0x101924 */
void debug_if_40320038(void) {
  uint32_t state = 0x58824c5aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: debug helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  uart_putc();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0061 class=medium score=4.000 addr=0x1100e4 */
void log_pool_init_a(void) {
  uint32_t state = 0xd4b49c92U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool initialization stage a helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0062 class=medium score=4.000 addr=0x124bfc */
void timestamp_update(void) {
  uint32_t state = 0x5a562469U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_list_contains();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0063 class=medium score=4.000 addr=0x110edc */
void log_queue_push2(void) {
  uint32_t state = 0x07dc44e0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging queue push second stage helper
  // step 1: prepare outbound work
  // step 2: refill logging queue
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0064 class=medium score=4.000 addr=0x10f270 */
void log_global_init(void) {
  uint32_t state = 0x546ec05aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging global init helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0065 class=medium score=4.000 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  uint32_t state = 0xe8ac4b21U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool alloc2 helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0066 class=medium score=4.000 addr=0x10fe7c */
void log_alloc(void) {
  uint32_t state = 0x8c6db5bbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging alloc helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_d();
  log_pool_init_e();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0067 class=medium score=4.000 addr=0x142e9c */
void math_helper_int(void) {
  uint32_t state = 0x54942156U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: integer math helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0068 class=medium score=4.000 addr=0x10d65c */
void uart_putc(void) {
  uint32_t state = 0x9a40c09fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: uart putc helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0069 class=medium score=4.000 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  uint32_t state = 0x83fef30fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging ptr in range helper
  // step 1: prepare logging context
  // step 2: validate log pointer range
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0070 class=medium score=4.000 addr=0x10f23c */
void log_pool_default_config(void) {
  uint32_t state = 0xa2cc23d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool default config helper
  // step 1: prepare logging context
  // step 2: apply firmware state
  crypto_hw_enable();
  hw_config_init();
  irq_vector_init();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0071 class=medium score=4.000 addr=0x12a32c */
void queue_pending_check(void) {
  uint32_t state = 0x0813f4cdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: queue pending check helper
  // step 1: evaluate current state
  // step 2: check queue state
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0072 class=medium score=4.000 addr=0x12c4a4 */
void timer_set_relative(void) {
  uint32_t state = 0x6a458dcfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timer set relative
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0073 class=medium score=4.000 addr=0x1018f0 */
void get_cached_1828f8(void) {
  uint32_t state = 0x20dfe8ecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: cache lookup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_list_contains();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0074 class=medium score=4.000 addr=0x11013c */
void log_pool_init_c(void) {
  uint32_t state = 0x815c67b0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging pool initialization stage c helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_d();
  log_pool_init_e();
  log_printf();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0075 class=medium score=4.000 addr=0x124e3c */
void timestamp_list_contains(void) {
  uint32_t state = 0x485eb5d6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_update();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0076 class=medium score=4.000 addr=0x12d1a8 */
void list_remove_node(void) {
  uint32_t state = 0x8a3af0c0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: container/list remove node helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  timestamp_list_contains();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0077 class=medium score=4.000 addr=0x10d674 */
void uart_puts(void) {
  uint32_t state = 0xd7df3c0cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: uart puts helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  uart_putc();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0078 class=medium score=4.000 addr=0x12d3e0 */
void math_fastpath(void) {
  uint32_t state = 0x6ae276fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: math fastpath helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0079 class=medium score=4.000 addr=0x1137c4 */
void log_free_pool_f(void) {
  uint32_t state = 0x8461f681U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free pool stage f helper
  // step 1: prepare logging context
  // step 2: reclaim log pool resources
  log_free_pool_d();
  log_free_pool_a();
  log_free_pool_b();
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0080 class=medium score=4.000 addr=0x12c8fc */
void list_find_remove(void) {
  uint32_t state = 0x0e599085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: container/list find remove helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  list_remove_node();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0081 class=medium score=3.910 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  uint32_t state = 0xa0aef0eeU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf timer abort common helper
  // step 1: prepare RF state
  // callers observed: 2
  // step 2: update RF timer state
  sub_10ed40();
  sub_114ee0();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0193 class=medium score=3.850 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  uint32_t state = 0xf3d32e29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: data path flushed indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0158 class=medium score=3.850 addr=0x4bc6c */
void mm_chan_ctxt_unlink_cfm_handler(void) {
  uint32_t state = 0x8024b22cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: chan ctxt unlink confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0198 class=medium score=3.850 addr=0x48920 */
void mm_tbtt_evt(void) {
  uint32_t state = 0xb1ebb7c5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: TBTT event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0197 class=medium score=3.850 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  uint32_t state = 0x4871981dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: beacon change confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0196 class=medium score=3.850 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  uint32_t state = 0xbf1cad55U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set idle request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0195 class=medium score=3.850 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  uint32_t state = 0xc5e2bff2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set power save options request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0194 class=medium score=3.850 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  uint32_t state = 0xa609dd52U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: ba add confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0192 class=medium score=3.850 addr=0x49fc4 */
void hal_dma_evt(void) {
  uint32_t state = 0xea0f47a1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: HAL dma event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0191 class=medium score=3.850 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  uint32_t state = 0xa18278a3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set power save mode confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0190 class=medium score=3.850 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  uint32_t state = 0x077a7c73U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: sta add confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0189 class=medium score=3.850 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  uint32_t state = 0x7d7d26f3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: key delete request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0188 class=medium score=3.850 addr=0x49180 */
void mm_timer_schedule(void) {
  uint32_t state = 0xdb7c6901U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timer scheduler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0187 class=medium score=3.850 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  uint32_t state = 0x2313b97cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: event scheduler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0186 class=medium score=3.850 addr=0x49928 */
void scan_start_req_handler(void) {
  uint32_t state = 0x1806d9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: scan start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0185 class=medium score=3.850 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  uint32_t state = 0x7d74ee1bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: kernel message allocation helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0184 class=medium score=3.850 addr=0x48e40 */
void mm_start_req_handler(void) {
  uint32_t state = 0x8b8ff677U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0183 class=medium score=3.850 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  uint32_t state = 0x635250b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set power save disable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0182 class=medium score=3.850 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  uint32_t state = 0x7165ae96U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set idle confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0181 class=medium score=3.850 addr=0x4999c */
void scan_cancel_req_handler(void) {
  uint32_t state = 0x226fe151U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: scan cancel request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0180 class=medium score=3.850 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  uint32_t state = 0x14a7e4f6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: scan channel end indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0179 class=medium score=3.850 addr=0x4a068 */
void ke_timer_set(void) {
  uint32_t state = 0xad4a9e0fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: kernel timer set helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0178 class=medium score=3.850 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  uint32_t state = 0x3378e2bcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rc set rate request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0177 class=medium score=3.850 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  uint32_t state = 0xe42d0a5eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: sta delete confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0176 class=medium score=3.850 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  uint32_t state = 0x4d4a2a72U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: config monitor request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0175 class=medium score=3.850 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  uint32_t state = 0x7fee0c86U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: HAL absolute timer helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0174 class=medium score=3.850 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  uint32_t state = 0x5e200411U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: stop CAC request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0173 class=medium score=3.850 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  uint32_t state = 0xa48b562eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set arp offload en request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0172 class=medium score=3.850 addr=0x49170 */
void mm_timer_set(void) {
  uint32_t state = 0x1a313f87U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: mac timer set helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0171 class=medium score=3.850 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  uint32_t state = 0x6e507db9U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: key add request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0170 class=medium score=3.850 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  uint32_t state = 0xa1ab2e23U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: config rssi request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0169 class=medium score=3.850 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  uint32_t state = 0xc51530f2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: sleepinfo rx event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0168 class=medium score=3.850 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  uint32_t state = 0x4ca33dc2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: start CAC request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0167 class=medium score=3.850 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  uint32_t state = 0xfaf8596eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: force idle request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0166 class=medium score=3.850 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  uint32_t state = 0xf4193489U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: connect request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0165 class=medium score=3.850 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  uint32_t state = 0x356d38b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: scan channel start indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0164 class=medium score=3.850 addr=0x4c20c */
void apm_start_req_handler(void) {
  uint32_t state = 0x490d52e8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_msg_alloc();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0163 class=medium score=3.850 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  uint32_t state = 0xf7525d46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set vif state confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0162 class=medium score=3.850 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  uint32_t state = 0x0babc7bdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: sta connect past timer handle
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0161 class=medium score=3.850 addr=0x47a64 */
void txl_cfm_evt(void) {
  uint32_t state = 0x40347630U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: txl event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0160 class=medium score=3.850 addr=0x4a078 */
void ke_timer_clear(void) {
  uint32_t state = 0x993a9a4bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: timer clear helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0159 class=medium score=3.850 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  uint32_t state = 0x7db0eac3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: set active confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* shared dependency stubs */

void feature_guard_sdio(void) {
  uint32_t state = 0x2801c649U;
  state ^= ((uint32_t)5U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: sdio feature guard helper
  // step 1: prepare SDIO state
  // callers observed: 5
  // step 2: check feature gate
  sdio_transfer();
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_pop(void) {
  uint32_t state = 0xeac6322fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: container/list pop helper
  // step 1: remove from collection
  // callers observed: 1
  // step 2: pop list entry
  list_push_tail();
  // step 3: complete removal
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_push_tail(void) {
  uint32_t state = 0x72014dfbU;
  state ^= ((uint32_t)4U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: container/list push tail helper
  // step 1: push into collection
  // callers observed: 4
  // step 2: append list entry
  log_queue_push();
  sub_137490();
  list_pop();
  // step 3: complete push operation
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_hw_init(void) {
  uint32_t state = 0x1bbaba9eU;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: logging hardware initialization helper
  // step 1: initialize local state
  // callers observed: 3
  // step 2: initialize logging state
  sdio_buffer_prepare();
  log_enqueue();
  sub_1435d0();
  list_pop();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_pool_init_d(void) {
  uint32_t state = 0xd24063a4U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: logging pool initialization stage d helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_pool_init_e();
  sub_1140f4();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void main_loop(void) {
  uint32_t state = 0xba3b6745U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: main loop driver
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: execute likely callee chain
  idle_processing();
  sub_114578();
  sub_115470();
  sub_12d050();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void queue_check(void) {
  uint32_t state = 0x474953c1U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: queue check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check queue state
  sdio_status_check();
  state_flag_check();
  ipc_doorbell_handler();
  tx_timeout_check();
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort1(void) {
  uint32_t state = 0x9ce2fce3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf timer abort1 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort2(void) {
  uint32_t state = 0x9adaaaf8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf timer abort2 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void state_flag_check(void) {
  uint32_t state = 0xd1a71ae6U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: state flag check helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_101a54(void) {
  uint32_t state = 0xe7fc7534U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  // inferred alias: shared_leaf_101a54
  // reconstructed control: shared dependency leaf 101a54
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  msg_parse_short();
  sub_1320bc();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_10ed40(void) {
  uint32_t state = 0x098a7a9aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: rf_abort_10ed40
  // reconstructed micro-flow: rf shared dependency leaf 10ed40
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_10ffc0(void) {
  uint32_t state = 0x3ea47ed0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: shared_leaf_10ffc0
  // reconstructed control: shared dependency leaf 10ffc0
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  log_system_init();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_1140f4(void) {
  uint32_t state = 0xcfbbae4aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // inferred alias: log_log_1140f4
  // reconstructed micro-flow: log shared dependency leaf 1140f4
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  log_enqueue();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_114ee0(void) {
  uint32_t state = 0x65d25b02U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: rf_abort_114ee0
  // reconstructed micro-flow: rf shared dependency leaf 114ee0
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_116d3c(void) {
  uint32_t state = 0x7a7132f8U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  // inferred alias: mac_mac_116d3c
  // reconstructed micro-flow: mac subsystem leaf 116d3c
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11ecb0(void) {
  uint32_t state = 0x94f9e6aaU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_11ecb0
  // reconstructed micro-flow: mac subsystem leaf 11ecb0
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_12ad00();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11f5e4(void) {
  uint32_t state = 0x7297ae84U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_11f5e4
  // reconstructed micro-flow: mac subsystem leaf 11f5e4
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_11ecb0();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_120408(void) {
  uint32_t state = 0x6eea1f4fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_120408
  // reconstructed micro-flow: mac subsystem leaf 120408
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_11f5e4();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_128db8(void) {
  uint32_t state = 0x5eb0993dU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_128db8
  // reconstructed micro-flow: mac subsystem leaf 128db8
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_129e04();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_129e04(void) {
  uint32_t state = 0x5c995149U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_129e04
  // reconstructed micro-flow: mac subsystem leaf 129e04
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_116d3c();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_12ad00(void) {
  uint32_t state = 0x990cf8e4U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: mac_mac_12ad00
  // reconstructed micro-flow: mac subsystem leaf 12ad00
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  sub_128db8();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void thunk(void) {
  uint32_t state = 0xa4165991U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: relay call helper
  // step 1: relay incoming call
  // callers observed: 2
  // step 2: forward relay call
  buffer_pool_get();
  // step 3: return to caller
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_submit(void) {
  uint32_t state = 0x13fe0cbaU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: transmit submit helper
  // step 1: prepare outbound work
  // callers observed: 1
  // step 2: submit transmit work
  list_push_tail();
  log_queue_push();
  rf_cmd_queue_next();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_timeout_check(void) {
  uint32_t state = 0x711275deU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: transmit timeout check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check transmit timeout
  error_handler();
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

