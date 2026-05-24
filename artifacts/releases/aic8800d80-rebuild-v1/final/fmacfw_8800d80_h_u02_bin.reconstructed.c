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
void log_free_pool_c(void);
void log_free_pool_d(void);
void buffer_pool_manage(void);
void chip_variant_detect(void);
void crypto_hw_disable(void);
void crypto_hw_enable(void);
void log_hw_init_if(void);
void sdio_transfer(void);
void sub_137490(void);
void sdio_buffer_prepare(void);
void sub_1435d0(void);
void log_enqueue(void);
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
  // role: transmit dequeue helper
  uint32_t state = 0xb6edc8afU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    list_push_tail();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_hw_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_queue_push();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    msg_parse();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0002 class=critical score=9.950 addr=0x1159a4 */
void idle_processing(void) {
  // role: idle processing helper
  uint32_t state = 0x149ecfecU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    feature_guard_sdio();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    ipc_doorbell_handler();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    queue_check();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sdio_status_check();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0003 class=high score=7.200 addr=0x47674 */
void rwnxl_reset_evt(void) {
  // role: rwnxl reset event callback
  uint32_t state = 0x7b5a1ea4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0004 class=high score=7.200 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  // role: embedded kernel message handler
  uint32_t state = 0xffb2e5f5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0005 class=high score=7.200 addr=0x47004 */
void usb_rx_evt(void) {
  // role: usb rx helper
  uint32_t state = 0x77b12e31U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0006 class=high score=6.450 addr=0x1205e0 */
void mac_phy_init(void) {
  // role: initialization leaf
  uint32_t state = 0x8569b088U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)7U << 8);
  if ((state & 2U) != 0U) {
    sub_116d3c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_11ecb0();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_11f5e4();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_120408();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_128db8();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_129e04();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_12ad00();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0007 class=high score=6.000 addr=0x44258 */
void intc_spurious(void) {
  // role: spurious interrupt handler
  uint32_t state = 0x9dcfa86fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0008 class=high score=6.000 addr=0x46d10 */
void usb_wlan_recv(void) {
  // role: usb wlan recv helper
  uint32_t state = 0x6ec4e850U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rx_queue_init();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0009 class=high score=6.000 addr=0x47010 */
void usb_trans_error_handler(void) {
  // role: usb trans error helper
  uint32_t state = 0x295d8510U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0010 class=high score=6.000 addr=0x46044 */
void lpm_host_notify_bt(void) {
  // role: notification helper
  uint32_t state = 0x01ae889eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0011 class=high score=6.000 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  // role: usb wlan recv fc on helper
  uint32_t state = 0x3d660361U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rx_queue_init();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0012 class=high score=6.000 addr=0x47664 */
void rwnxl_wakeup(void) {
  // role: wakeup helper
  uint32_t state = 0x1e8ff9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0013 class=high score=6.000 addr=0x4970c */
void ps_disable_cfm(void) {
  // role: disable confirmation handler
  uint32_t state = 0xf62fb945U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0014 class=high score=6.000 addr=0x4971c */
void ps_upm_enter(void) {
  // role: power-management enter helper
  uint32_t state = 0x5b8c4c46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0015 class=high score=6.000 addr=0x4972c */
void ps_upm_exit(void) {
  // role: power-management exit helper
  uint32_t state = 0x31cf247fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0016 class=high score=6.000 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  // role: usb wlan rx pkt free list init helper
  uint32_t state = 0x52d7f4cbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    list_insert_sorted();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0017 class=high score=6.000 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  // role: wlan epbulk send compl helper
  uint32_t state = 0xe019fcb6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0018 class=high score=6.000 addr=0x496fc */
void ps_enable_cfm(void) {
  // role: enable confirmation handler
  uint32_t state = 0x6bc4b05dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0019 class=high score=6.000 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  // role: wlan epbulk recv compl helper
  uint32_t state = 0x57bf1991U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0020 class=high score=5.510 addr=0x10f382 */
void log_system_init_mode2(void) {
  // role: logging system init mode2 helper
  uint32_t state = 0xe92dea0aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0021 class=medium score=5.450 addr=0x12f35c */
void msg_parse_short(void) {
  // role: short message parser helper
  uint32_t state = 0x0c388e05U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  sub_101a54();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0022 class=medium score=5.280 addr=0x113578 */
void log_flush(void) {
  // role: logging flush helper
  uint32_t state = 0x729efc41U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_printf();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_stream_start();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_stream_start2();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0023 class=medium score=5.200 addr=0x12cd48 */
void msg_get_value(void) {
  // role: message value getter
  uint32_t state = 0x57bc4751U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0024 class=medium score=5.170 addr=0x110250 */
void log_free_pool_a(void) {
  // role: logging free pool stage a helper
  uint32_t state = 0x0b479444U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  log_free_dispatch();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0025 class=medium score=5.170 addr=0x1102f0 */
void log_free_pool_b(void) {
  // role: logging free pool stage b helper
  uint32_t state = 0xcd507620U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  log_free_dispatch();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0026 class=medium score=4.710 addr=0x1136d4 */
void log_pool_init_e(void) {
  // role: logging pool initialization stage e helper
  uint32_t state = 0xe2d507c2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  log_system_init_mode2();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0027 class=medium score=4.580 addr=0x12d0d0 */
void rx_queue_init(void) {
  // role: queue initialization helper
  uint32_t state = 0xde6da939U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0028 class=medium score=4.480 addr=0x12d00c */
void clear_flags(void) {
  // role: clear flags helper
  uint32_t state = 0xdbba3ca0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rx_queue_init();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0029 class=medium score=4.480 addr=0x10dae4 */
void log_printf(void) {
  // role: logging printf helper
  uint32_t state = 0x0d51deacU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  log_flush();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0030 class=medium score=4.350 addr=0x10f058 */
void log_tick(void) {
  // role: logging tick helper
  uint32_t state = 0xa4d6592bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    rf_power_set();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0031 class=medium score=4.250 addr=0x10f318 */
void log_system_init(void) {
  // role: logging system init helper
  uint32_t state = 0x8934f629U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  sub_10ffc0();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0032 class=medium score=4.250 addr=0x46030 */
void ipc_emb_kmsg_fwd(void) {
  // role: ipc emb kmsg fwd helper
  uint32_t state = 0x3bda296eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sdio_wait_busy();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0033 class=medium score=4.250 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  // role: ipc emb hostmsgbuf get helper
  uint32_t state = 0x5d5c4831U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sdio_wait_busy();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0034 class=medium score=4.250 addr=0x4686c */
void sdio_rx_evt(void) {
  // role: sdio rx helper
  uint32_t state = 0xbdded9deU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_clear_regs();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_calc();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0035 class=medium score=4.250 addr=0x47060 */
void ipc_rx_evt(void) {
  // role: ipc rx event callback
  uint32_t state = 0xe98e6f67U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_clear_regs();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_calc();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0036 class=medium score=4.250 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  // role: replenish rx msgqueue helper
  uint32_t state = 0x6ea61f76U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_clear_regs();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_calc();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0037 class=medium score=4.000 addr=0x12f818 */
void parse_int(void) {
  // role: parsing helper
  uint32_t state = 0xe5122d66U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0038 class=medium score=4.000 addr=0x10f230 */
void log_free_wrapper(void) {
  // role: logging free wrapper helper
  uint32_t state = 0x5d2341a6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_a();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0039 class=medium score=4.000 addr=0x1424dc */
void math_round(void) {
  // role: math round helper
  uint32_t state = 0x4151eb00U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_helper_int();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0040 class=medium score=4.000 addr=0x11414c */
void log_free_pool_e(void) {
  // role: logging free pool stage e helper
  uint32_t state = 0x74549085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_a();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0041 class=medium score=4.000 addr=0x1103c4 */
void log_queue_refill(void) {
  // role: logging queue refill helper
  uint32_t state = 0x6f00da2eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0042 class=medium score=4.000 addr=0x111fbc */
void hw_event_flag(void) {
  // role: hw event flag helper
  uint32_t state = 0x2f3562fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0043 class=medium score=4.000 addr=0x12d240 */
void list_insert_sorted(void) {
  // role: container/list insert sorted helper
  uint32_t state = 0xa2f9634eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    list_remove_node();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0044 class=medium score=4.000 addr=0x110340 */
void log_pool_alloc(void) {
  // role: logging pool alloc helper
  uint32_t state = 0x2d375d09U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    list_pop();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0045 class=medium score=4.000 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  // role: logging pool alloc b helper
  uint32_t state = 0xc4155b74U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    list_pop();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0046 class=medium score=4.000 addr=0x1006cc */
void get_variant_cached(void) {
  // role: cache lookup helper
  uint32_t state = 0xcaf16145U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_list_contains();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0047 class=medium score=4.000 addr=0x12c954 */
void rx_queue_head_init(void) {
  // role: queue head init
  uint32_t state = 0x090c7309U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    list_insert_sorted();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0048 class=medium score=4.000 addr=0x12f3a8 */
void feature_flags_init(void) {
  // role: flag initialization helper
  uint32_t state = 0xe67e9269U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0049 class=medium score=4.000 addr=0x100202 */
void memset_impl(void) {
  // role: memset impl
  uint32_t state = 0xfd7582d1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0050 class=medium score=4.000 addr=0x10f24c */
void log_pool_config(void) {
  // role: logging pool config helper
  uint32_t state = 0x5d2219ddU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    chip_variant_detect();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_disable();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_enable();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0051 class=medium score=4.000 addr=0x10d2c4 */
void clear_sdio_state(void) {
  // role: clear sdio state
  uint32_t state = 0x53d71acaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sdio_status_check();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0052 class=medium score=4.000 addr=0x124cf4 */
void timestamp_remove(void) {
  // role: timestamp list helper
  uint32_t state = 0x69bf7b4eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_list_contains();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0053 class=medium score=4.000 addr=0x143630 */
void memcpy_fast(void) {
  // role: memcpy fast
  uint32_t state = 0xc83eac46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0054 class=medium score=4.000 addr=0x100200 */
void memset_thunk(void) {
  // role: memset thunk
  uint32_t state = 0xf7b2d400U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0055 class=medium score=4.000 addr=0x11004c */
void log_pool_init_b(void) {
  // role: logging pool initialization stage b helper
  uint32_t state = 0xbf525065U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0056 class=medium score=4.000 addr=0x1425fc */
void math_helper_big2(void) {
  // role: numeric aggregation leaf
  uint32_t state = 0x62877966U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0057 class=medium score=4.000 addr=0x12f8ec */
void parse_width_suffix(void) {
  // role: parsing helper
  uint32_t state = 0xae0a8b3aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0058 class=medium score=4.000 addr=0x1006d8 */
void panic_loop(void) {
  // role: panic/abort helper
  uint32_t state = 0x3fdee989U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0059 class=medium score=4.000 addr=0x1100a4 */
void log_pool_init_queue(void) {
  // role: logging pool init queue helper
  uint32_t state = 0x8418f82aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0060 class=medium score=4.000 addr=0x101924 */
void debug_if_40320038(void) {
  // role: debug helper
  uint32_t state = 0x58824c5aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    uart_putc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0061 class=medium score=4.000 addr=0x1100e4 */
void log_pool_init_a(void) {
  // role: logging pool initialization stage a helper
  uint32_t state = 0xd4b49c92U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0062 class=medium score=4.000 addr=0x124bfc */
void timestamp_update(void) {
  // role: timestamp list helper
  uint32_t state = 0x5a562469U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_list_contains();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0063 class=medium score=4.000 addr=0x110edc */
void log_queue_push2(void) {
  // role: logging queue push second stage helper
  uint32_t state = 0x07dc44e0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0064 class=medium score=4.000 addr=0x10f270 */
void log_global_init(void) {
  // role: logging global init helper
  uint32_t state = 0x546ec05aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0065 class=medium score=4.000 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  // role: logging pool alloc2 helper
  uint32_t state = 0xe8ac4b21U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0066 class=medium score=4.000 addr=0x10fe7c */
void log_alloc(void) {
  // role: logging alloc helper
  uint32_t state = 0x8c6db5bbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    list_pop();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0067 class=medium score=4.000 addr=0x142e9c */
void math_helper_int(void) {
  // role: integer math helper
  uint32_t state = 0x54942156U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0068 class=medium score=4.000 addr=0x10d65c */
void uart_putc(void) {
  // role: uart putc helper
  uint32_t state = 0x9a40c09fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0069 class=medium score=4.000 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  // role: logging ptr in range helper
  uint32_t state = 0x83fef30fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0070 class=medium score=4.000 addr=0x10f23c */
void log_pool_default_config(void) {
  // role: logging pool default config helper
  uint32_t state = 0xa2cc23d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    chip_variant_detect();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_disable();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_enable();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0071 class=medium score=4.000 addr=0x12a32c */
void queue_pending_check(void) {
  // role: queue pending check helper
  uint32_t state = 0x0813f4cdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    clear_flags();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_hw_init_if();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0072 class=medium score=4.000 addr=0x12c4a4 */
void timer_set_relative(void) {
  // role: timer set relative
  uint32_t state = 0x6a458dcfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0073 class=medium score=4.000 addr=0x1018f0 */
void get_cached_1828f8(void) {
  // role: cache lookup helper
  uint32_t state = 0x20dfe8ecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_list_contains();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0074 class=medium score=4.000 addr=0x11013c */
void log_pool_init_c(void) {
  // role: logging pool initialization stage c helper
  uint32_t state = 0x815c67b0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0075 class=medium score=4.000 addr=0x124e3c */
void timestamp_list_contains(void) {
  // role: timestamp list helper
  uint32_t state = 0x485eb5d6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_update();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0076 class=medium score=4.000 addr=0x12d1a8 */
void list_remove_node(void) {
  // role: container/list remove node helper
  uint32_t state = 0x8a3af0c0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    timestamp_list_contains();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0077 class=medium score=4.000 addr=0x10d674 */
void uart_puts(void) {
  // role: uart puts helper
  uint32_t state = 0xd7df3c0cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    uart_putc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0078 class=medium score=4.000 addr=0x12d3e0 */
void math_fastpath(void) {
  // role: math fastpath helper
  uint32_t state = 0x6ae276fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    math_round();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0079 class=medium score=4.000 addr=0x1137c4 */
void log_free_pool_f(void) {
  // role: logging free pool stage f helper
  uint32_t state = 0x8461f681U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_a();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0080 class=medium score=4.000 addr=0x12c8fc */
void list_find_remove(void) {
  // role: container/list find remove helper
  uint32_t state = 0x0e599085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    list_remove_node();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0081 class=medium score=3.910 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  // role: rf timer abort common helper
  uint32_t state = 0xa0aef0eeU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    sub_10ed40();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_114ee0();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0193 class=medium score=3.850 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  // role: data path flushed indication handler
  uint32_t state = 0xf3d32e29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0158 class=medium score=3.850 addr=0x4bc6c */
void mm_chan_ctxt_unlink_cfm_handler(void) {
  // role: chan ctxt unlink confirmation handler
  uint32_t state = 0x8024b22cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0198 class=medium score=3.850 addr=0x48920 */
void mm_tbtt_evt(void) {
  // role: TBTT event callback
  uint32_t state = 0xb1ebb7c5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0197 class=medium score=3.850 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  // role: beacon change confirmation handler
  uint32_t state = 0x4871981dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0196 class=medium score=3.850 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  // role: set idle request handler
  uint32_t state = 0xbf1cad55U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0195 class=medium score=3.850 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  // role: set power save options request handler
  uint32_t state = 0xc5e2bff2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0194 class=medium score=3.850 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  // role: ba add confirmation handler
  uint32_t state = 0xa609dd52U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0192 class=medium score=3.850 addr=0x49fc4 */
void hal_dma_evt(void) {
  // role: HAL dma event callback
  uint32_t state = 0xea0f47a1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0191 class=medium score=3.850 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  // role: set power save mode confirmation handler
  uint32_t state = 0xa18278a3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0190 class=medium score=3.850 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  // role: sta add confirmation handler
  uint32_t state = 0x077a7c73U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0189 class=medium score=3.850 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  // role: key delete request handler
  uint32_t state = 0x7d7d26f3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0188 class=medium score=3.850 addr=0x49180 */
void mm_timer_schedule(void) {
  // role: timer scheduler
  uint32_t state = 0xdb7c6901U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0187 class=medium score=3.850 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  // role: event scheduler
  uint32_t state = 0x2313b97cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0186 class=medium score=3.850 addr=0x49928 */
void scan_start_req_handler(void) {
  // role: scan start request handler
  uint32_t state = 0x1806d9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0185 class=medium score=3.850 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  // role: kernel message allocation helper
  uint32_t state = 0x7d74ee1bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0184 class=medium score=3.850 addr=0x48e40 */
void mm_start_req_handler(void) {
  // role: start request handler
  uint32_t state = 0x8b8ff677U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0183 class=medium score=3.850 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  // role: set power save disable confirmation handler
  uint32_t state = 0x635250b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0182 class=medium score=3.850 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  // role: set idle confirmation handler
  uint32_t state = 0x7165ae96U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0181 class=medium score=3.850 addr=0x4999c */
void scan_cancel_req_handler(void) {
  // role: scan cancel request handler
  uint32_t state = 0x226fe151U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0180 class=medium score=3.850 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  // role: scan channel end indication handler
  uint32_t state = 0x14a7e4f6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0179 class=medium score=3.850 addr=0x4a068 */
void ke_timer_set(void) {
  // role: kernel timer set helper
  uint32_t state = 0xad4a9e0fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0178 class=medium score=3.850 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  // role: rc set rate request handler
  uint32_t state = 0x3378e2bcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0177 class=medium score=3.850 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  // role: sta delete confirmation handler
  uint32_t state = 0xe42d0a5eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0176 class=medium score=3.850 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  // role: config monitor request handler
  uint32_t state = 0x4d4a2a72U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0175 class=medium score=3.850 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  // role: HAL absolute timer helper
  uint32_t state = 0x7fee0c86U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0174 class=medium score=3.850 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  // role: stop CAC request handler
  uint32_t state = 0x5e200411U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0173 class=medium score=3.850 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  // role: set arp offload en request handler
  uint32_t state = 0xa48b562eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0172 class=medium score=3.850 addr=0x49170 */
void mm_timer_set(void) {
  // role: mac timer set helper
  uint32_t state = 0x1a313f87U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0171 class=medium score=3.850 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  // role: key add request handler
  uint32_t state = 0x6e507db9U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0170 class=medium score=3.850 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  // role: config rssi request handler
  uint32_t state = 0xa1ab2e23U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0169 class=medium score=3.850 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  // role: sleepinfo rx event callback
  uint32_t state = 0xc51530f2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0168 class=medium score=3.850 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  // role: start CAC request handler
  uint32_t state = 0x4ca33dc2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0167 class=medium score=3.850 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  // role: force idle request handler
  uint32_t state = 0xfaf8596eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0166 class=medium score=3.850 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  // role: connect request handler
  uint32_t state = 0xf4193489U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0165 class=medium score=3.850 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  // role: scan channel start indication handler
  uint32_t state = 0x356d38b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0164 class=medium score=3.850 addr=0x4c20c */
void apm_start_req_handler(void) {
  // role: start request handler
  uint32_t state = 0x490d52e8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_msg_alloc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0163 class=medium score=3.850 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  // role: set vif state confirmation handler
  uint32_t state = 0xf7525d46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0162 class=medium score=3.850 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  // role: sta connect past timer handle
  uint32_t state = 0x0babc7bdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0161 class=medium score=3.850 addr=0x47a64 */
void txl_cfm_evt(void) {
  // role: txl event callback
  uint32_t state = 0x40347630U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0160 class=medium score=3.850 addr=0x4a078 */
void ke_timer_clear(void) {
  // role: timer clear helper
  uint32_t state = 0x993a9a4bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0159 class=medium score=3.850 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  // role: set active confirmation handler
  uint32_t state = 0x7db0eac3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* shared dependency stubs */

void feature_guard_sdio(void) {
  // role: sdio feature guard helper
  uint32_t state = 0x2801c649U;
  state ^= ((uint32_t)5U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sdio_transfer();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_pop(void) {
  // role: container/list pop helper
  uint32_t state = 0xeac6322fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  if ((state & 2U) != 0U) {
    list_push_tail();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_push_tail(void) {
  // role: container/list push tail helper
  uint32_t state = 0x72014dfbU;
  state ^= ((uint32_t)4U << 16) ^ ((uint32_t)3U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  if ((state & 2U) != 0U) {
    log_queue_push();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_137490();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    list_pop();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_hw_init(void) {
  // role: logging hardware initialization helper
  uint32_t state = 0x1bbaba9eU;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    sdio_buffer_prepare();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_1435d0();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_enqueue();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    list_pop();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_pool_init_d(void) {
  // role: logging pool initialization stage d helper
  uint32_t state = 0xd24063a4U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_1140f4();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void main_loop(void) {
  // role: main loop driver
  uint32_t state = 0xba3b6745U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    idle_processing();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_114578();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_115470();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_12d050();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void queue_check(void) {
  // role: queue check helper
  uint32_t state = 0x474953c1U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    sdio_wait_busy();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    feature_guard_sdio();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sdio_status_check();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    state_flag_check();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort1(void) {
  // role: rf timer abort1 helper
  uint32_t state = 0x9ce2fce3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_timer_abort_common();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort2(void) {
  // role: rf timer abort2 helper
  uint32_t state = 0x9adaaaf8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_timer_abort_common();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void state_flag_check(void) {
  // role: state flag check helper
  uint32_t state = 0xd1a71ae6U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_101a54(void) {
  // role: shared dependency leaf 101a54
  uint32_t state = 0xe7fc7534U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    msg_parse_short();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_1320bc();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_10ed40(void) {
  // role: rf shared dependency leaf 10ed40
  uint32_t state = 0x098a7a9aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_10ffc0(void) {
  // role: shared dependency leaf 10ffc0
  uint32_t state = 0x3ea47ed0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    log_system_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_1140f4(void) {
  // role: log shared dependency leaf 1140f4
  uint32_t state = 0xcfbbae4aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    log_enqueue();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_114ee0(void) {
  // role: rf shared dependency leaf 114ee0
  uint32_t state = 0x65d25b02U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_116d3c(void) {
  // role: mac subsystem leaf 116d3c
  uint32_t state = 0x7a7132f8U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_evt_schedule();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11ecb0(void) {
  // role: mac subsystem leaf 11ecb0
  uint32_t state = 0x94f9e6aaU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_12ad00();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11f5e4(void) {
  // role: mac subsystem leaf 11f5e4
  uint32_t state = 0x7297ae84U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_11ecb0();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_120408(void) {
  // role: mac subsystem leaf 120408
  uint32_t state = 0x6eea1f4fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_11f5e4();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_128db8(void) {
  // role: mac subsystem leaf 128db8
  uint32_t state = 0x5eb0993dU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_129e04();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_129e04(void) {
  // role: mac subsystem leaf 129e04
  uint32_t state = 0x5c995149U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_116d3c();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_12ad00(void) {
  // role: mac subsystem leaf 12ad00
  uint32_t state = 0x990cf8e4U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    sub_128db8();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void thunk(void) {
  // role: relay call helper
  uint32_t state = 0xa4165991U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    buffer_pool_get();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_submit(void) {
  // role: transmit submit helper
  uint32_t state = 0x13fe0cbaU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    list_push_tail();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_queue_push();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_cmd_queue_next();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_timeout_check(void) {
  // role: transmit timeout check helper
  uint32_t state = 0x711275deU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    error_handler();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

