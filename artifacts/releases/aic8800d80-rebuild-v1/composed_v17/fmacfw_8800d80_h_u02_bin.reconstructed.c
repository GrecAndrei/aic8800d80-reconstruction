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
void debug_if_check_40320038(void);
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
void rf_bus_reset_n_90_bc6c(void);
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
void rf_bus_reset_n_42e(void);
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
void buffer_pool_manage(void);
void chip_variant_detect(void);
void hw_config_init(void);
void irq_vector_init(void);
void sdio_transfer(void);
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
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      list_push_tail();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_push_tail();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_hw_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_hw_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_queue_push();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_queue_push();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      msg_parse();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      msg_parse();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0002 class=critical score=9.950 addr=0x1159a4 */
void idle_processing(void) {
  uint32_t state = 0x149ecfecU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      feature_guard_sdio();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      feature_guard_sdio();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      ipc_doorbell_handler();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      ipc_doorbell_handler();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      queue_check();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      queue_check();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sdio_status_check();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_status_check();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0003 class=high score=7.200 addr=0x47674 */
void rwnxl_reset_evt(void) {
  uint32_t state = 0x7b5a1ea4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0004 class=high score=7.200 addr=0x46020 */
void emb_kmsg_hdlr(void) {
  uint32_t state = 0xffb2e5f5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0005 class=high score=7.200 addr=0x47004 */
void usb_rx_evt(void) {
  uint32_t state = 0x77b12e31U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0006 class=high score=6.450 addr=0x1205e0 */
void mac_phy_init(void) {
  uint32_t state = 0x8569b088U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)7U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_116d3c();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_116d3c();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_11ecb0();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_11ecb0();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_11f5e4();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_11f5e4();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_120408();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_120408();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_128db8();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_128db8();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_129e04();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_129e04();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_12ad00();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_12ad00();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0007 class=high score=6.000 addr=0x44258 */
void intc_spurious(void) {
  uint32_t state = 0x9dcfa86fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0008 class=high score=6.000 addr=0x46d10 */
void usb_wlan_recv(void) {
  uint32_t state = 0x6ec4e850U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rx_queue_init();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0009 class=high score=6.000 addr=0x47010 */
void usb_trans_error_handler(void) {
  uint32_t state = 0x295d8510U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0010 class=high score=6.000 addr=0x46044 */
void lpm_host_notify_bt(void) {
  uint32_t state = 0x01ae889eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0011 class=high score=6.000 addr=0x46d20 */
void usb_wlan_recv_fc_on(void) {
  uint32_t state = 0x3d660361U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rx_queue_init();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0012 class=high score=6.000 addr=0x47664 */
void rwnxl_wakeup(void) {
  uint32_t state = 0x1e8ff9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0013 class=high score=6.000 addr=0x4970c */
void ps_disable_cfm(void) {
  uint32_t state = 0xf62fb945U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0014 class=high score=6.000 addr=0x4971c */
void ps_upm_enter(void) {
  uint32_t state = 0x5b8c4c46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0015 class=high score=6.000 addr=0x4972c */
void ps_upm_exit(void) {
  uint32_t state = 0x31cf247fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0016 class=high score=6.000 addr=0x46fc0 */
void usb_wlan_rx_pkt_free_list_init(void) {
  uint32_t state = 0x52d7f4cbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      list_insert_sorted();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0017 class=high score=6.000 addr=0x46fa0 */
void wlan_epbulk_send_compl_handler(void) {
  uint32_t state = 0xe019fcb6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0018 class=high score=6.000 addr=0x496fc */
void ps_enable_cfm(void) {
  uint32_t state = 0x6bc4b05dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0019 class=high score=6.000 addr=0x46f80 */
void wlan_epbulk_recv_compl_handler(void) {
  uint32_t state = 0x57bf1991U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0020 class=high score=5.510 addr=0x10f382 */
void log_system_init_mode2(void) {
  uint32_t state = 0xe92dea0aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_e();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_e();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0021 class=medium score=5.450 addr=0x12f35c */
void msg_parse_short(void) {
  uint32_t state = 0x0c388e05U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  sub_101a54();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0022 class=medium score=5.280 addr=0x113578 */
void log_flush(void) {
  uint32_t state = 0x729efc41U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start2();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start2();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0023 class=medium score=5.200 addr=0x12cd48 */
void msg_get_value(void) {
  uint32_t state = 0x57bc4751U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0024 class=medium score=5.170 addr=0x110250 */
void log_free_pool_a(void) {
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
  uint32_t state = 0xde6da939U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0028 class=medium score=4.480 addr=0x12d00c */
void clear_flags(void) {
  uint32_t state = 0xdbba3ca0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rx_queue_init();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0029 class=medium score=4.480 addr=0x10dae4 */
void log_printf(void) {
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
  uint32_t state = 0xa4d6592bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_power_set();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_power_set();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0031 class=medium score=4.250 addr=0x10f318 */
void log_system_init(void) {
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
  uint32_t state = 0x3bda296eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sdio_wait_busy();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_wait_busy();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0033 class=medium score=4.250 addr=0x45ff0 */
void ipc_emb_hostmsgbuf_get(void) {
  uint32_t state = 0x5d5c4831U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sdio_wait_busy();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_wait_busy();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0034 class=medium score=4.250 addr=0x4686c */
void sdio_rx_evt(void) {
  uint32_t state = 0xbdded9deU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_clear_regs();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_clear_regs();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_power_calc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_power_calc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0035 class=medium score=4.250 addr=0x47060 */
void ipc_rx_evt(void) {
  uint32_t state = 0xe98e6f67U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_clear_regs();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_clear_regs();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_power_calc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_power_calc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0036 class=medium score=4.250 addr=0x46830 */
void sdio_replenish_rx_msgqueue(void) {
  uint32_t state = 0x6ea61f76U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_clear_regs();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_clear_regs();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_power_calc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_power_calc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0037 class=medium score=4.000 addr=0x12f818 */
void parse_int(void) {
  uint32_t state = 0xe5122d66U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0038 class=medium score=4.000 addr=0x10f230 */
void log_free_wrapper(void) {
  uint32_t state = 0x5d2341a6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_a();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_a();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_b();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_b();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_c();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_c();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0039 class=medium score=4.000 addr=0x1424dc */
void math_round(void) {
  uint32_t state = 0x4151eb00U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_helper_int();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0040 class=medium score=4.000 addr=0x11414c */
void log_free_pool_e(void) {
  uint32_t state = 0x74549085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_a();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_a();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_b();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_b();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_c();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_c();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0041 class=medium score=4.000 addr=0x1103c4 */
void log_queue_refill(void) {
  uint32_t state = 0x6f00da2eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      buffer_pool_manage();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      buffer_pool_manage();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0042 class=medium score=4.000 addr=0x111fbc */
void hw_event_flag(void) {
  uint32_t state = 0x2f3562fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0043 class=medium score=4.000 addr=0x12d240 */
void list_insert_sorted(void) {
  uint32_t state = 0xa2f9634eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      list_remove_node();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0044 class=medium score=4.000 addr=0x110340 */
void log_pool_alloc(void) {
  uint32_t state = 0x2d375d09U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0045 class=medium score=4.000 addr=0x1102a0 */
void log_pool_alloc_b(void) {
  uint32_t state = 0xc4155b74U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0046 class=medium score=4.000 addr=0x1006cc */
void get_variant_cached(void) {
  uint32_t state = 0xcaf16145U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_list_contains();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0047 class=medium score=4.000 addr=0x12c954 */
void rx_queue_head_init(void) {
  uint32_t state = 0x090c7309U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      list_insert_sorted();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0048 class=medium score=4.000 addr=0x12f3a8 */
void feature_flags_init(void) {
  uint32_t state = 0xe67e9269U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0049 class=medium score=4.000 addr=0x100202 */
void memset_impl(void) {
  uint32_t state = 0xfd7582d1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  static uint8_t scratch[256];
  uint8_t v = (uint8_t)(state & 0xFFU);
  for (uint32_t i = 0U; i < 256U; ++i) {
    scratch[i] = (uint8_t)(v + (uint8_t)i);
  }
  state ^= scratch[0] ^ scratch[255];
  (void)state;
}

/* unit=lift_0050 class=medium score=4.000 addr=0x10f24c */
void log_pool_config(void) {
  uint32_t state = 0x5d2219ddU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      chip_variant_detect();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      chip_variant_detect();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      hw_config_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      hw_config_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      irq_vector_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      irq_vector_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0051 class=medium score=4.000 addr=0x10d2c4 */
void clear_sdio_state(void) {
  uint32_t state = 0x53d71acaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sdio_status_check();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0052 class=medium score=4.000 addr=0x124cf4 */
void timestamp_remove(void) {
  uint32_t state = 0x69bf7b4eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_list_contains();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0053 class=medium score=4.000 addr=0x143630 */
void memcpy_fast(void) {
  uint32_t state = 0xc83eac46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0054 class=medium score=4.000 addr=0x100200 */
void memset_thunk(void) {
  uint32_t state = 0xf7b2d400U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0055 class=medium score=4.000 addr=0x11004c */
void log_pool_init_b(void) {
  uint32_t state = 0xbf525065U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0056 class=medium score=4.000 addr=0x1425fc */
void math_helper_big2(void) {
  uint32_t state = 0x62877966U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0057 class=medium score=4.000 addr=0x12f8ec */
void parse_width_suffix(void) {
  uint32_t state = 0xae0a8b3aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0058 class=medium score=4.000 addr=0x1006d8 */
void panic_loop(void) {
  uint32_t state = 0x3fdee989U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0059 class=medium score=4.000 addr=0x1100a4 */
void log_pool_init_queue(void) {
  uint32_t state = 0x8418f82aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      buffer_pool_manage();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      buffer_pool_manage();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0060 class=medium score=4.000 addr=0x101924 */
void debug_if_check_40320038(void) {
  uint32_t state = 0x58824c5aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      uart_putc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0061 class=medium score=4.000 addr=0x1100e4 */
void log_pool_init_a(void) {
  uint32_t state = 0xd4b49c92U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0062 class=medium score=4.000 addr=0x124bfc */
void timestamp_update(void) {
  uint32_t state = 0x5a562469U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_list_contains();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0063 class=medium score=4.000 addr=0x110edc */
void log_queue_push2(void) {
  uint32_t state = 0x07dc44e0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
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

/* unit=lift_0064 class=medium score=4.000 addr=0x10f270 */
void log_global_init(void) {
  uint32_t state = 0x546ec05aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0065 class=medium score=4.000 addr=0x10f9e8 */
void log_pool_alloc2(void) {
  uint32_t state = 0xe8ac4b21U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0066 class=medium score=4.000 addr=0x10fe7c */
void log_alloc(void) {
  uint32_t state = 0x8c6db5bbU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0067 class=medium score=4.000 addr=0x142e9c */
void math_helper_int(void) {
  uint32_t state = 0x54942156U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0068 class=medium score=4.000 addr=0x10d65c */
void uart_putc(void) {
  uint32_t state = 0x9a40c09fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0069 class=medium score=4.000 addr=0x10fdf4 */
void log_ptr_in_range(void) {
  uint32_t state = 0x83fef30fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0070 class=medium score=4.000 addr=0x10f23c */
void log_pool_default_config(void) {
  uint32_t state = 0xa2cc23d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      chip_variant_detect();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      chip_variant_detect();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      hw_config_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      hw_config_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      irq_vector_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      irq_vector_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0071 class=medium score=4.000 addr=0x12a32c */
void queue_pending_check(void) {
  uint32_t state = 0x0813f4cdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      buffer_pool_manage();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      buffer_pool_manage();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      clear_flags();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      clear_flags();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0072 class=medium score=4.000 addr=0x12c4a4 */
void timer_set_relative(void) {
  uint32_t state = 0x6a458dcfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_bus_reset_n_42e();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0073 class=medium score=4.000 addr=0x1018f0 */
void get_cached_1828f8(void) {
  uint32_t state = 0x20dfe8ecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_list_contains();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0074 class=medium score=4.000 addr=0x11013c */
void log_pool_init_c(void) {
  uint32_t state = 0x815c67b0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_printf();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_printf();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0075 class=medium score=4.000 addr=0x124e3c */
void timestamp_list_contains(void) {
  uint32_t state = 0x485eb5d6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_update();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0076 class=medium score=4.000 addr=0x12d1a8 */
void list_remove_node(void) {
  uint32_t state = 0x8a3af0c0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      timestamp_list_contains();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0077 class=medium score=4.000 addr=0x10d674 */
void uart_puts(void) {
  uint32_t state = 0xd7df3c0cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      uart_putc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0078 class=medium score=4.000 addr=0x12d3e0 */
void math_fastpath(void) {
  uint32_t state = 0x6ae276fcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      math_round();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0079 class=medium score=4.000 addr=0x1137c4 */
void log_free_pool_f(void) {
  uint32_t state = 0x8461f681U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_a();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_a();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_b();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_b();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_c();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_c();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0080 class=medium score=4.000 addr=0x12c8fc */
void list_find_remove(void) {
  uint32_t state = 0x0e599085U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      list_remove_node();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0081 class=medium score=3.910 addr=0x12ef88 */
void rf_timer_abort_common(void) {
  uint32_t state = 0xa0aef0eeU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_10ed40();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_10ed40();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_114ee0();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_114ee0();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0193 class=medium score=3.850 addr=0x4bca4 */
void me_data_path_flushed_ind_handler(void) {
  uint32_t state = 0xf3d32e29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0158 class=medium score=3.850 addr=0x4bc6c */
void rf_bus_reset_n_90_bc6c(void) {
  uint32_t state = 0x8024b22cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0198 class=medium score=3.850 addr=0x48920 */
void mm_tbtt_evt(void) {
  uint32_t state = 0xb1ebb7c5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0197 class=medium score=3.850 addr=0x4c280 */
void mm_bcn_change_cfm_handler(void) {
  uint32_t state = 0x4871981dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0196 class=medium score=3.850 addr=0x48e58 */
void mm_set_idle_req_handler(void) {
  uint32_t state = 0xbf1cad55U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0195 class=medium score=3.850 addr=0x48ed4 */
void mm_set_ps_options_req_handler(void) {
  uint32_t state = 0xc5e2bff2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0194 class=medium score=3.850 addr=0x4ca78 */
void mm_ba_add_cfm_handler(void) {
  uint32_t state = 0xa609dd52U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0192 class=medium score=3.850 addr=0x49fc4 */
void hal_dma_evt(void) {
  uint32_t state = 0xea0f47a1U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0191 class=medium score=3.850 addr=0x4b6a4 */
void mm_set_ps_mode_cfm_handler(void) {
  uint32_t state = 0xa18278a3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0190 class=medium score=3.850 addr=0x4bbe0 */
void mm_sta_add_cfm_handler(void) {
  uint32_t state = 0x077a7c73U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0189 class=medium score=3.850 addr=0x48ea4 */
void mm_key_del_req_handler(void) {
  uint32_t state = 0x7d7d26f3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0188 class=medium score=3.850 addr=0x49180 */
void mm_timer_schedule(void) {
  uint32_t state = 0xdb7c6901U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_bus_reset_n_42e();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0187 class=medium score=3.850 addr=0x4a3a4 */
void ke_evt_schedule(void) {
  uint32_t state = 0x2313b97cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_bus_reset_n_42e();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0186 class=medium score=3.850 addr=0x49928 */
void scan_start_req_handler(void) {
  uint32_t state = 0x1806d9bfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0185 class=medium score=3.850 addr=0x4a0c0 */
void ke_msg_alloc(void) {
  uint32_t state = 0x7d74ee1bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0184 class=medium score=3.850 addr=0x48e40 */
void mm_start_req_handler(void) {
  uint32_t state = 0x8b8ff677U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0183 class=medium score=3.850 addr=0x4bbf8 */
void me_set_ps_disable_cfm_handler(void) {
  uint32_t state = 0x635250b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0182 class=medium score=3.850 addr=0x4b68c */
void mm_set_idle_cfm_handler(void) {
  uint32_t state = 0x7165ae96U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0181 class=medium score=3.850 addr=0x4999c */
void scan_cancel_req_handler(void) {
  uint32_t state = 0x226fe151U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0180 class=medium score=3.850 addr=0x49964 */
void mm_scan_channel_end_ind_handler(void) {
  uint32_t state = 0x14a7e4f6U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0179 class=medium score=3.850 addr=0x4a068 */
void rf_bus_reset_n_42e(void) {
  uint32_t state = 0xad4a9e0fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0178 class=medium score=3.850 addr=0x4b6c0 */
void me_rc_set_rate_req_handler(void) {
  uint32_t state = 0x3378e2bcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0177 class=medium score=3.850 addr=0x4bc54 */
void mm_sta_del_cfm_handler(void) {
  uint32_t state = 0xe42d0a5eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0176 class=medium score=3.850 addr=0x4b6dc */
void me_config_monitor_req_handler(void) {
  uint32_t state = 0x4d4a2a72U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0175 class=medium score=3.850 addr=0x49f80 */
void hal_machw_abs_timer_handler(void) {
  uint32_t state = 0x7fee0c86U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0174 class=medium score=3.850 addr=0x4c2f8 */
void apm_stop_cac_req_handler(void) {
  uint32_t state = 0x5e200411U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0173 class=medium score=3.850 addr=0x48ef4 */
void mm_set_arpoffload_en_req_handler(void) {
  uint32_t state = 0xa48b562eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0172 class=medium score=3.850 addr=0x49170 */
void mm_timer_set(void) {
  uint32_t state = 0x1a313f87U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_bus_reset_n_42e();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0171 class=medium score=3.850 addr=0x48e8c */
void mm_key_add_req_handler(void) {
  uint32_t state = 0x6e507db9U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0170 class=medium score=3.850 addr=0x48f18 */
void mm_cfg_rssi_req_handler(void) {
  uint32_t state = 0xa1ab2e23U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0169 class=medium score=3.850 addr=0x4890c */
void mm_sleepinfo_rx_evt(void) {
  uint32_t state = 0xc51530f2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0168 class=medium score=3.850 addr=0x4c2dc */
void apm_start_cac_req_handler(void) {
  uint32_t state = 0x4ca33dc2U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0167 class=medium score=3.850 addr=0x48e70 */
void mm_force_idle_req_handler(void) {
  uint32_t state = 0xfaf8596eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0166 class=medium score=3.850 addr=0x4bb98 */
void sm_connect_req_handler(void) {
  uint32_t state = 0xf4193489U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0165 class=medium score=3.850 addr=0x49940 */
void mm_scan_channel_start_ind_handler(void) {
  uint32_t state = 0x356d38b5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0164 class=medium score=3.850 addr=0x4c20c */
void apm_start_req_handler(void) {
  uint32_t state = 0x490d52e8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_msg_alloc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0163 class=medium score=3.850 addr=0x4c2bc */
void mm_set_vif_state_cfm_handler(void) {
  uint32_t state = 0xf7525d46U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0162 class=medium score=3.850 addr=0x463bc */
void apm_sta_connect_past_timer_handle(void) {
  uint32_t state = 0x0babc7bdU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0161 class=medium score=3.850 addr=0x47a64 */
void txl_cfm_evt(void) {
  uint32_t state = 0x40347630U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0160 class=medium score=3.850 addr=0x4a078 */
void ke_timer_clear(void) {
  uint32_t state = 0x993a9a4bU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t ticks = (state >> 5) & 0x7FFFU;
  state ^= (ticks * 1000U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0159 class=medium score=3.850 addr=0x4bc38 */
void me_set_active_cfm_handler(void) {
  uint32_t state = 0x7db0eac3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* shared dependency implementations */

void feature_guard_sdio(void) {
  uint32_t state = 0x2801c649U;
  state ^= ((uint32_t)5U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sdio_transfer();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_transfer();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_pop(void) {
  uint32_t state = 0xeac6322fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  enum { QCAP = 64 };
  static uint32_t q[QCAP];
  static uint32_t q_head, q_tail, q_count;
  uint32_t out = 0U;
  if (q_count > 0U) {
    out = q[q_head];
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_count--;
    state ^= out;
  } else {
    state ^= 0xBAD00000U;
  }
  if (q_tail >= QCAP) { q_tail = 0U; }
  list_push_tail();
  (void)state;
}

void list_push_tail(void) {
  uint32_t state = 0x72014dfbU;
  state ^= ((uint32_t)4U << 16) ^ ((uint32_t)3U << 8);
  uint32_t list_token = (state & 0xFFFFU) ^ 0x3C3C3C3CU;
  state ^= (list_token << 3);
  enum { QCAP = 64 };
  static uint32_t q[QCAP];
  static uint32_t q_head, q_tail, q_count;
  uint32_t item = (state ^ 0x9E3779B9U) + (q_tail << 3);
  if (q_count < QCAP) {
    q[q_tail] = item;
    q_tail = (q_tail + 1U) & (QCAP - 1U);
    q_count++;
  } else {
    q[q_tail] ^= item;
    q_head = (q_head + 1U) & (QCAP - 1U);
    q_tail = (q_tail + 1U) & (QCAP - 1U);
  }
  log_queue_push();
  (void)state;
}

void log_hw_init(void) {
  uint32_t state = 0x1bbaba9eU;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sdio_buffer_prepare();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_buffer_prepare();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_enqueue();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_enqueue();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_1435d0();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_1435d0();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      list_pop();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_pop();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_pool_init_d(void) {
  uint32_t state = 0xd24063a4U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_pool_init_e();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_pool_init_e();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_1140f4();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_1140f4();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void main_loop(void) {
  uint32_t state = 0xba3b6745U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      idle_processing();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      idle_processing();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_114578();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_114578();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_115470();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_115470();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_12d050();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_12d050();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void queue_check(void) {
  uint32_t state = 0x474953c1U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sdio_status_check();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sdio_status_check();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      state_flag_check();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      state_flag_check();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      ipc_doorbell_handler();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      ipc_doorbell_handler();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      tx_timeout_check();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      tx_timeout_check();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort1(void) {
  uint32_t state = 0x9ce2fce3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_timer_abort_common();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_timer_abort_common();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort2(void) {
  uint32_t state = 0x9adaaaf8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_timer_abort_common();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_timer_abort_common();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void state_flag_check(void) {
  uint32_t state = 0xd1a71ae6U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_101a54(void) {
  uint32_t state = 0xe7fc7534U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)2U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      msg_parse_short();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      msg_parse_short();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_1320bc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_1320bc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_10ed40(void) {
  uint32_t state = 0x098a7a9aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_cmd_wait();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_10ffc0(void) {
  uint32_t state = 0x3ea47ed0U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      log_system_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_system_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_1140f4(void) {
  uint32_t state = 0xcfbbae4aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      log_enqueue();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_114ee0(void) {
  uint32_t state = 0x65d25b02U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_cmd_wait();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_116d3c(void) {
  uint32_t state = 0x7a7132f8U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_evt_schedule();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11ecb0(void) {
  uint32_t state = 0x94f9e6aaU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_12ad00();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_11f5e4(void) {
  uint32_t state = 0x7297ae84U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_11ecb0();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_120408(void) {
  uint32_t state = 0x6eea1f4fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_11f5e4();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_128db8(void) {
  uint32_t state = 0x5eb0993dU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_129e04();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_129e04(void) {
  uint32_t state = 0x5c995149U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_116d3c();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void sub_12ad00(void) {
  uint32_t state = 0x990cf8e4U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      sub_128db8();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

void thunk(void) {
  uint32_t state = 0xa4165991U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      buffer_pool_get();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      buffer_pool_get();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_submit(void) {
  uint32_t state = 0x13fe0cbaU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      list_push_tail();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      list_push_tail();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      log_queue_push();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_queue_push();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_cmd_queue_next();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_cmd_queue_next();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void tx_timeout_check(void) {
  uint32_t state = 0x711275deU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      error_handler();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      error_handler();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

