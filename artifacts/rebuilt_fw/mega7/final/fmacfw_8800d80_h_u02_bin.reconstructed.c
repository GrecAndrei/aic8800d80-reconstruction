/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_h_u02.bin */

#include <stdint.h>

/* unit=lift_0001 class=critical score=11.250 addr=0x11017c */
void tx_dequeue(void) {
  // reconstructed control: transmit dequeue helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: dequeue transmit work
  list_push_tail();
  log_hw_init();
  log_queue_push();
  msg_parse();
  // step 3: commit outbound completion
}

/* unit=lift_0002 class=critical score=9.950 addr=0x1159a4 */
void idle_processing(void) {
  // reconstructed control: idle processing helper
  // step 1: process current inputs
  // callers observed: 1
  // step 2: invoke specialized support sequence
  feature_guard_sdio();
  ipc_doorbell_handler();
  queue_check();
  sdio_status_check();
  // step 3: commit processed results
}

/* unit=lift_0003 class=high score=7.200 addr=0x47674 */
void rwnxl_reset_evt(void) {
  // reconstructed micro-flow: rwnxl reset event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0004 class=high score=7.200 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  // reconstructed micro-flow: embedded kernel message handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0005 class=high score=7.200 addr=0x47004 */
void usb_rx_evt(void) {
  // reconstructed micro-flow: usb rx helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0006 class=high score=6.450 addr=0x1205e0 */
void mac_phy_init(void) {
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
}

/* unit=lift_0007 class=high score=6.000 addr=0x44258 */
void intc_spurious(void) {
  // reconstructed micro-flow: spurious interrupt handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0008 class=high score=6.000 addr=0x46d10 */
void usb_wlan_recv(void) {
  // reconstructed micro-flow: usb wlan recv helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rx_queue_init();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0009 class=high score=6.000 addr=0x47010 */
void usb_trans_error_handler(void) {
  // reconstructed micro-flow: usb trans error helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0010 class=high score=6.000 addr=0x46044 */
void lpm_host_notify_bt(void) {
  // reconstructed micro-flow: notification helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0011 class=high score=6.000 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  // reconstructed micro-flow: usb wlan recv fc on helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rx_queue_init();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0012 class=high score=6.000 addr=0x47664 */
void rwnxl_wakeup(void) {
  // reconstructed micro-flow: wakeup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0013 class=high score=6.000 addr=0x4970c */
void ps_disable_cfm(void) {
  // reconstructed micro-flow: disable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0014 class=high score=6.000 addr=0x4971c */
void ps_upm_enter(void) {
  // reconstructed micro-flow: power-management enter helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0015 class=high score=6.000 addr=0x4972c */
void ps_upm_exit(void) {
  // reconstructed micro-flow: power-management exit helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0016 class=high score=6.000 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  // reconstructed micro-flow: usb wlan rx pkt free list init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  list_insert_sorted();
  // step 3: complete local state transition
}

/* unit=lift_0017 class=high score=6.000 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  // reconstructed micro-flow: wlan epbulk send compl helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0018 class=high score=6.000 addr=0x496fc */
void ps_enable_cfm(void) {
  // reconstructed micro-flow: enable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0019 class=high score=6.000 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  // reconstructed micro-flow: wlan epbulk recv compl helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0020 class=high score=5.510 addr=0x10f382 */
void log_system_init_mode2(void) {
  // reconstructed control: logging system init mode2 helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_pool_init_e();
  log_pool_init_d();
  // step 3: finish initialization path
}

/* unit=lift_0021 class=medium score=5.450 addr=0x12f35c */
void msg_parse_short(void) {
  // reconstructed control: short message parser helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: parse message payload
  sub_101a54();
  // step 3: finalize state / completion path
}

/* unit=lift_0022 class=medium score=5.280 addr=0x113578 */
void log_flush(void) {
  // reconstructed control: logging flush helper
  // step 1: prepare logging context
  // step 2: emit log output
  log_printf();
  rf_stream_start();
  rf_stream_start2();
  // step 3: flush log updates
}

/* unit=lift_0023 class=medium score=5.200 addr=0x12cd48 */
void msg_get_value(void) {
  // reconstructed micro-flow: message value getter
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0024 class=medium score=5.170 addr=0x110250 */
void log_free_pool_a(void) {
  // reconstructed control: logging free pool stage a helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: reclaim log pool resources
  log_free_dispatch();
  // step 3: flush log updates
}

/* unit=lift_0025 class=medium score=5.170 addr=0x1102f0 */
void log_free_pool_b(void) {
  // reconstructed control: logging free pool stage b helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: reclaim log pool resources
  log_free_dispatch();
  // step 3: flush log updates
}

/* unit=lift_0026 class=medium score=4.710 addr=0x1136d4 */
void log_pool_init_e(void) {
  // reconstructed control: logging pool initialization stage e helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_system_init_mode2();
  // step 3: finish initialization path
}

/* unit=lift_0027 class=medium score=4.580 addr=0x12d0d0 */
void rx_queue_init(void) {
  // reconstructed control: queue initialization helper
  // step 1: initialize local state
  // step 2: process queue state
  clear_flags();
  // step 3: finish initialization path
}

/* unit=lift_0028 class=medium score=4.480 addr=0x12d00c */
void clear_flags(void) {
  // reconstructed micro-flow: clear flags helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rx_queue_init();
  // step 3: complete local state transition
}

/* unit=lift_0029 class=medium score=4.480 addr=0x10dae4 */
void log_printf(void) {
  // reconstructed control: logging printf helper
  // step 1: prepare logging context
  // callers observed: 1
  // step 2: emit log output
  log_flush();
  // step 3: flush log updates
}

/* unit=lift_0030 class=medium score=4.350 addr=0x10f058 */
void log_tick(void) {
  // reconstructed control: logging tick helper
  // step 1: prepare logging context
  // step 2: advance log tick state
  rf_power_set();
  // step 3: flush log updates
}

/* unit=lift_0031 class=medium score=4.250 addr=0x10f318 */
void log_system_init(void) {
  // reconstructed control: logging system init helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  sub_10ffc0();
  // step 3: finish initialization path
}

/* unit=lift_0032 class=medium score=4.250 addr=0x46030 */
void ipc_emb_kmsg_fwd(void) {
  // reconstructed control: ipc emb kmsg fwd helper
  // step 1: load/update local state inferred from callers and edges
  // step 2: handle message state
  sdio_wait_busy();
  // step 3: finalize state / completion path
}

/* unit=lift_0033 class=medium score=4.250 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  // reconstructed control: ipc emb hostmsgbuf get helper
  // step 1: read local state
  // step 2: handle message state
  sdio_wait_busy();
  // step 3: return observed value
}

/* unit=lift_0034 class=medium score=4.250 addr=0x4686c */
void sdio_rx_evt(void) {
  // reconstructed control: sdio rx helper
  // step 1: capture event context
  // step 2: dispatch event-specific state transitions
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: finalize event callback path
}

/* unit=lift_0035 class=medium score=4.250 addr=0x47060 */
void ipc_rx_evt(void) {
  // reconstructed control: ipc rx event callback
  // step 1: capture event context
  // step 2: dispatch event-specific state transitions
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: finalize event callback path
}

/* unit=lift_0036 class=medium score=4.250 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  // reconstructed control: replenish rx msgqueue helper
  // step 1: prepare outbound work
  // step 2: refill SDIO RX queue
  clear_flags();
  crypto_hw_clear_regs();
  crypto_power_calc();
  // step 3: commit outbound completion
}

/* unit=lift_0037 class=medium score=4.000 addr=0x12f818 */
void parse_int(void) {
  // reconstructed micro-flow: parsing helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0038 class=medium score=4.000 addr=0x10f230 */
void log_free_wrapper(void) {
  // reconstructed control: logging free wrapper helper
  // step 1: prepare logging context
  // step 2: handle logging state
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  // step 3: flush log updates
}

/* unit=lift_0039 class=medium score=4.000 addr=0x1424dc */
void math_round(void) {
  // reconstructed micro-flow: math round helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_helper_int();
  // step 3: complete local state transition
}

/* unit=lift_0040 class=medium score=4.000 addr=0x11414c */
void log_free_pool_e(void) {
  // reconstructed control: logging free pool stage e helper
  // step 1: prepare logging context
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  // step 3: flush log updates
}

/* unit=lift_0041 class=medium score=4.000 addr=0x1103c4 */
void log_queue_refill(void) {
  // reconstructed control: logging queue refill helper
  // step 1: prepare outbound work
  // step 2: refill logging queue
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: commit outbound completion
}

/* unit=lift_0042 class=medium score=4.000 addr=0x111fbc */
void hw_event_flag(void) {
  // reconstructed micro-flow: hw event flag helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0043 class=medium score=4.000 addr=0x12d240 */
void list_insert_sorted(void) {
  // reconstructed micro-flow: container/list insert sorted helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  list_remove_node();
  // step 3: complete local state transition
}

/* unit=lift_0044 class=medium score=4.000 addr=0x110340 */
void log_pool_alloc(void) {
  // reconstructed control: logging pool alloc helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_a();
  log_pool_init_d();
  // step 3: flush log updates
}

/* unit=lift_0045 class=medium score=4.000 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  // reconstructed control: logging pool alloc b helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_a();
  log_pool_init_d();
  // step 3: flush log updates
}

/* unit=lift_0046 class=medium score=4.000 addr=0x1006cc */
void get_variant_cached(void) {
  // reconstructed micro-flow: cache lookup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0047 class=medium score=4.000 addr=0x12c954 */
void rx_queue_head_init(void) {
  // reconstructed micro-flow: queue head init
  // step 1: decode local context
  // step 2: execute inferred helper chain
  list_insert_sorted();
  // step 3: complete local state transition
}

/* unit=lift_0048 class=medium score=4.000 addr=0x12f3a8 */
void feature_flags_init(void) {
  // reconstructed micro-flow: flag initialization helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0049 class=medium score=4.000 addr=0x100202 */
void memset_impl(void) {
  // reconstructed micro-flow: memset impl
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0050 class=medium score=4.000 addr=0x10f24c */
void log_pool_config(void) {
  // reconstructed control: logging pool config helper
  // step 1: prepare logging context
  // step 2: apply firmware state
  chip_variant_detect();
  crypto_hw_enable();
  crypto_hw_power_up();
  // step 3: flush log updates
}

/* unit=lift_0051 class=medium score=4.000 addr=0x10d2c4 */
void clear_sdio_state(void) {
  // reconstructed micro-flow: clear sdio state
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sdio_status_check();
  // step 3: complete local state transition
}

/* unit=lift_0052 class=medium score=4.000 addr=0x124cf4 */
void timestamp_remove(void) {
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0053 class=medium score=4.000 addr=0x143630 */
void memcpy_fast(void) {
  // reconstructed micro-flow: memcpy fast
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0054 class=medium score=4.000 addr=0x100200 */
void memset_thunk(void) {
  // reconstructed micro-flow: memset thunk
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0055 class=medium score=4.000 addr=0x11004c */
void log_pool_init_b(void) {
  // reconstructed control: logging pool initialization stage b helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: finish initialization path
}

/* unit=lift_0056 class=medium score=4.000 addr=0x1425fc */
void math_helper_big2(void) {
  // reconstructed micro-flow: numeric aggregation leaf
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0057 class=medium score=4.000 addr=0x12f8ec */
void parse_width_suffix(void) {
  // reconstructed micro-flow: parsing helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0058 class=medium score=4.000 addr=0x1006d8 */
void panic_loop(void) {
  // reconstructed micro-flow: panic/abort helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0059 class=medium score=4.000 addr=0x1100a4 */
void log_pool_init_queue(void) {
  // reconstructed control: logging pool init queue helper
  // step 1: initialize local state
  // step 2: initialize logging state
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: finish initialization path
}

/* unit=lift_0060 class=medium score=4.000 addr=0x101924 */
void debug_if_40320038(void) {
  // reconstructed micro-flow: debug helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  uart_putc();
  // step 3: complete local state transition
}

/* unit=lift_0061 class=medium score=4.000 addr=0x1100e4 */
void log_pool_init_a(void) {
  // reconstructed control: logging pool initialization stage a helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: finish initialization path
}

/* unit=lift_0062 class=medium score=4.000 addr=0x124bfc */
void timestamp_update(void) {
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0063 class=medium score=4.000 addr=0x110edc */
void log_queue_push2(void) {
  // reconstructed control: logging queue push second stage helper
  // step 1: prepare outbound work
  // step 2: refill logging queue
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: commit outbound completion
}

/* unit=lift_0064 class=medium score=4.000 addr=0x10f270 */
void log_global_init(void) {
  // reconstructed control: logging global init helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: finish initialization path
}

/* unit=lift_0065 class=medium score=4.000 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  // reconstructed control: logging pool alloc2 helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: flush log updates
}

/* unit=lift_0066 class=medium score=4.000 addr=0x10fe7c */
void log_alloc(void) {
  // reconstructed control: logging alloc helper
  // step 1: prepare logging context
  // step 2: allocate log buffer
  list_pop();
  log_free_pool_a();
  log_pool_init_d();
  // step 3: flush log updates
}

/* unit=lift_0067 class=medium score=4.000 addr=0x142e9c */
void math_helper_int(void) {
  // reconstructed micro-flow: integer math helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0068 class=medium score=4.000 addr=0x10d65c */
void uart_putc(void) {
  // reconstructed micro-flow: uart putc helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0069 class=medium score=4.000 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  // reconstructed control: logging ptr in range helper
  // step 1: prepare logging context
  // step 2: validate log pointer range
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: flush log updates
}

/* unit=lift_0070 class=medium score=4.000 addr=0x10f23c */
void log_pool_default_config(void) {
  // reconstructed control: logging pool default config helper
  // step 1: prepare logging context
  // step 2: apply firmware state
  chip_variant_detect();
  crypto_hw_enable();
  crypto_hw_power_up();
  // step 3: flush log updates
}

/* unit=lift_0071 class=medium score=4.000 addr=0x12a32c */
void queue_pending_check(void) {
  // reconstructed control: queue pending check helper
  // step 1: evaluate current state
  // step 2: check queue state
  buffer_pool_manage();
  clear_flags();
  list_pop();
  // step 3: return validation result
}

/* unit=lift_0072 class=medium score=4.000 addr=0x12c4a4 */
void timer_set_relative(void) {
  // reconstructed micro-flow: timer set relative
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0073 class=medium score=4.000 addr=0x1018f0 */
void get_cached_1828f8(void) {
  // reconstructed micro-flow: cache lookup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0074 class=medium score=4.000 addr=0x11013c */
void log_pool_init_c(void) {
  // reconstructed control: logging pool initialization stage c helper
  // step 1: initialize local state
  // step 2: initialize logging state
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: finish initialization path
}

/* unit=lift_0075 class=medium score=4.000 addr=0x124e3c */
void timestamp_list_contains(void) {
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_update();
  // step 3: complete local state transition
}

/* unit=lift_0076 class=medium score=4.000 addr=0x12d1a8 */
void list_remove_node(void) {
  // reconstructed micro-flow: container/list remove node helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0077 class=medium score=4.000 addr=0x10d674 */
void uart_puts(void) {
  // reconstructed micro-flow: uart puts helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  uart_putc();
  // step 3: complete local state transition
}

/* unit=lift_0078 class=medium score=4.000 addr=0x12d3e0 */
void math_fastpath(void) {
  // reconstructed micro-flow: math fastpath helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0079 class=medium score=4.000 addr=0x1137c4 */
void log_free_pool_f(void) {
  // reconstructed control: logging free pool stage f helper
  // step 1: prepare logging context
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  // step 3: flush log updates
}

/* unit=lift_0080 class=medium score=4.000 addr=0x12c8fc */
void list_find_remove(void) {
  // reconstructed micro-flow: container/list find remove helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  list_remove_node();
  // step 3: complete local state transition
}

/* unit=lift_0081 class=medium score=3.910 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  // reconstructed control: rf timer abort common helper
  // step 1: prepare RF state
  // callers observed: 2
  // step 2: update RF timer state
  sub_10ed40();
  sub_114ee0();
  // step 3: commit RF state
}

/* unit=lift_0193 class=medium score=3.850 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  // reconstructed micro-flow: data path flushed indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0158 class=medium score=3.850 addr=0x4bc6c */
void mm_chan_ctxt_unlink_cfm_handler(void) {
  // reconstructed micro-flow: chan ctxt unlink confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0198 class=medium score=3.850 addr=0x48920 */
void mm_tbtt_evt(void) {
  // reconstructed micro-flow: TBTT event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0197 class=medium score=3.850 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  // reconstructed micro-flow: beacon change confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0196 class=medium score=3.850 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  // reconstructed micro-flow: set idle request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0195 class=medium score=3.850 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  // reconstructed micro-flow: set power save options request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0194 class=medium score=3.850 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  // reconstructed micro-flow: ba add confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0192 class=medium score=3.850 addr=0x49fc4 */
void hal_dma_evt(void) {
  // reconstructed micro-flow: HAL dma event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0191 class=medium score=3.850 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  // reconstructed micro-flow: set power save mode confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0190 class=medium score=3.850 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  // reconstructed micro-flow: sta add confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0189 class=medium score=3.850 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  // reconstructed micro-flow: key delete request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0188 class=medium score=3.850 addr=0x49180 */
void mm_timer_schedule(void) {
  // reconstructed micro-flow: timer scheduler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0187 class=medium score=3.850 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  // reconstructed micro-flow: event scheduler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  // step 3: complete local state transition
}

/* unit=lift_0186 class=medium score=3.850 addr=0x49928 */
void scan_start_req_handler(void) {
  // reconstructed micro-flow: scan start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0185 class=medium score=3.850 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  // reconstructed micro-flow: kernel message allocation helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0184 class=medium score=3.850 addr=0x48e40 */
void mm_start_req_handler(void) {
  // reconstructed micro-flow: start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0183 class=medium score=3.850 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  // reconstructed micro-flow: set power save disable confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0182 class=medium score=3.850 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  // reconstructed micro-flow: set idle confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0181 class=medium score=3.850 addr=0x4999c */
void scan_cancel_req_handler(void) {
  // reconstructed micro-flow: scan cancel request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0180 class=medium score=3.850 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  // reconstructed micro-flow: scan channel end indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0179 class=medium score=3.850 addr=0x4a068 */
void ke_timer_set(void) {
  // reconstructed micro-flow: kernel timer set helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0178 class=medium score=3.850 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  // reconstructed micro-flow: rc set rate request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0177 class=medium score=3.850 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  // reconstructed micro-flow: sta delete confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0176 class=medium score=3.850 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  // reconstructed micro-flow: config monitor request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0175 class=medium score=3.850 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  // reconstructed micro-flow: HAL absolute timer helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0174 class=medium score=3.850 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  // reconstructed micro-flow: stop CAC request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0173 class=medium score=3.850 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  // reconstructed micro-flow: set arp offload en request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0172 class=medium score=3.850 addr=0x49170 */
void mm_timer_set(void) {
  // reconstructed micro-flow: mac timer set helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0171 class=medium score=3.850 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  // reconstructed micro-flow: key add request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0170 class=medium score=3.850 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  // reconstructed micro-flow: config rssi request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0169 class=medium score=3.850 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  // reconstructed micro-flow: sleepinfo rx event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0168 class=medium score=3.850 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  // reconstructed micro-flow: start CAC request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0167 class=medium score=3.850 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  // reconstructed micro-flow: force idle request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0166 class=medium score=3.850 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  // reconstructed micro-flow: connect request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0165 class=medium score=3.850 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  // reconstructed micro-flow: scan channel start indication handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0164 class=medium score=3.850 addr=0x4c20c */
void apm_start_req_handler(void) {
  // reconstructed micro-flow: start request handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_msg_alloc();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0163 class=medium score=3.850 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  // reconstructed micro-flow: set vif state confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0162 class=medium score=3.850 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  // reconstructed micro-flow: sta connect past timer handle
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0161 class=medium score=3.850 addr=0x47a64 */
void txl_cfm_evt(void) {
  // reconstructed micro-flow: txl event callback
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0160 class=medium score=3.850 addr=0x4a078 */
void ke_timer_clear(void) {
  // reconstructed micro-flow: timer clear helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0159 class=medium score=3.850 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  // reconstructed micro-flow: set active confirmation handler
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* shared dependency stubs */

void feature_guard_sdio(void) {
  // reconstructed control: sdio feature guard helper
  // step 1: prepare SDIO state
  // callers observed: 5
  // step 2: check feature gate
  sdio_transfer();
  // step 3: commit SDIO state
}

void list_pop(void) {
  // reconstructed control: container/list pop helper
  // step 1: remove from collection
  // callers observed: 1
  // step 2: pop list entry
  list_push_tail();
  // step 3: complete removal
}

void list_push_tail(void) {
  // reconstructed control: container/list push tail helper
  // step 1: push into collection
  // callers observed: 4
  // step 2: append list entry
  log_queue_push();
  sub_137490();
  list_pop();
  // step 3: complete push operation
}

void log_hw_init(void) {
  // reconstructed control: logging hardware initialization helper
  // step 1: initialize local state
  // callers observed: 3
  // step 2: initialize logging state
  sdio_buffer_prepare();
  log_enqueue();
  sub_1435d0();
  list_pop();
  // step 3: finish initialization path
}

void log_pool_init_d(void) {
  // reconstructed control: logging pool initialization stage d helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_pool_init_e();
  sub_1140f4();
  // step 3: finish initialization path
}

void main_loop(void) {
  // reconstructed control: main loop driver
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: execute likely callee chain
  idle_processing();
  sub_114578();
  sub_115470();
  sub_12d050();
  // step 3: finalize state / completion path
}

void queue_check(void) {
  // reconstructed control: queue check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check queue state
  sdio_wait_busy();
  feature_guard_sdio();
  sdio_status_check();
  state_flag_check();
  // step 3: return validation result
}

void rf_timer_abort1(void) {
  // reconstructed control: rf timer abort1 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
}

void rf_timer_abort2(void) {
  // reconstructed control: rf timer abort2 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
}

void state_flag_check(void) {
  // reconstructed micro-flow: state flag check helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

void sub_101a54(void) {
  // inferred alias: shared_leaf_101a54
  // reconstructed control: shared dependency leaf 101a54
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  msg_parse_short();
  sub_1320bc();
  // step 3: finalize state / completion path
}

void sub_10ed40(void) {
  // inferred alias: rf_abort_10ed40
  // reconstructed micro-flow: rf shared dependency leaf 10ed40
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

void sub_10ffc0(void) {
  // inferred alias: shared_leaf_10ffc0
  // reconstructed control: shared dependency leaf 10ffc0
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  log_system_init();
  // step 3: finalize state / completion path
}

void sub_1140f4(void) {
  // inferred alias: log_log_1140f4
  // reconstructed micro-flow: log shared dependency leaf 1140f4
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  log_enqueue();
  // step 3: complete local state transition
}

void sub_114ee0(void) {
  // inferred alias: rf_abort_114ee0
  // reconstructed micro-flow: rf shared dependency leaf 114ee0
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

void sub_116d3c(void) {
  // inferred alias: mac_mac_116d3c
  // reconstructed micro-flow: mac subsystem leaf 116d3c
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

void sub_11ecb0(void) {
  // inferred alias: mac_mac_11ecb0
  // reconstructed micro-flow: mac subsystem leaf 11ecb0
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_12ad00();
  // step 3: complete local state transition
}

void sub_11f5e4(void) {
  // inferred alias: mac_mac_11f5e4
  // reconstructed micro-flow: mac subsystem leaf 11f5e4
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_11ecb0();
  // step 3: complete local state transition
}

void sub_120408(void) {
  // inferred alias: mac_mac_120408
  // reconstructed micro-flow: mac subsystem leaf 120408
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_11f5e4();
  // step 3: complete local state transition
}

void sub_128db8(void) {
  // inferred alias: mac_mac_128db8
  // reconstructed micro-flow: mac subsystem leaf 128db8
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_129e04();
  // step 3: complete local state transition
}

void sub_129e04(void) {
  // inferred alias: mac_mac_129e04
  // reconstructed micro-flow: mac subsystem leaf 129e04
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_116d3c();
  // step 3: complete local state transition
}

void sub_12ad00(void) {
  // inferred alias: mac_mac_12ad00
  // reconstructed micro-flow: mac subsystem leaf 12ad00
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_128db8();
  // step 3: complete local state transition
}

void thunk(void) {
  // reconstructed control: relay call helper
  // step 1: relay incoming call
  // callers observed: 2
  // step 2: forward relay call
  buffer_pool_get();
  // step 3: return to caller
}

void tx_submit(void) {
  // reconstructed control: transmit submit helper
  // step 1: prepare outbound work
  // callers observed: 1
  // step 2: submit transmit work
  list_push_tail();
  log_queue_push();
  rf_cmd_queue_next();
  // step 3: commit outbound completion
}

void tx_timeout_check(void) {
  // reconstructed control: transmit timeout check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check transmit timeout
  error_handler();
  // step 3: return validation result
}

