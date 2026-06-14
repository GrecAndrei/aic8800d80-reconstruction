/* Auto-generated per-image composed reconstruction */
/* image: fmacfwbt_8800d80_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void rf_level_apply(void);
void rf_stream_start2_324c(void);
void sdio_dma_config(void);
void rf_bus_write(void);
void rf_bus_setup_1d58(void);
void rf_mem_read_ed40(void);
void rf_mem_write_fd64(void);
void rf_bus_write2_1a78(void);
void log_free_dispatch(void);
void patch_apply(void);
void rf_msg_handler(void);
void rf_init_blocka(void);
void rf_state_check(void);
void sdio_buffer_prepare(void);
void rf_fault_dump_n31c(void);
void rf_bus_reset2(void);
void rf_bus_reset_844(void);
void log_free_pool_dispatch2(void);
void message_dispatch(void);
void rf_bus_reset2_n236_fc7c(void);
void rf_cmd_send(void);
void phy_rf_init_2d0(void);
void rf_hw_timer_init(void);
void rf_level_compute(void);
void rf_cmd_wait(void);
void rf_stream_start_1ac(void);
void rf_reg_write_cb(void);
void rf_init_blockc(void);
void rf_init_blockb(void);
void rf_power_set(void);
void rf_reg_write_wait(void);
void rf_msg_process_body_3aa4(void);
void sdio_status_check(void);
void crypto_channel_calc(void);
void crypto_hw_disable(void);
void crypto_hw_power_up_39c4(void);
void log_queue_push(void);
void math_round(void);
void event_queue_push(void);
void math_helper_big(void);
void math_helper_big2(void);
void crypto_hw_enable(void);
void log_ptr_in_range(void);
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
void sub_102a24(void);
void chip_variant_detect(void);
void hw_config_init_0688(void);
void rf_bus_clear(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void fw_config_apply(void);
void log_enqueue(void);
void sub_1435d0(void);
void buffer_pool_manage(void);
void ke_timer_set(void);
void rf_hw_timer_read(void);
void rf_level_step_04e0(void);
void sub_111f08(void);
void sub_102b00(void);
void rf_reg_ack_cb(void);
void crypto_freq_set(void);
void crypto_mac_core(void);
void crypto_power_apply(void);
void tx_dequeue(void);
void math_helper_int(void);
void sub_142f2c(void);
void log_printf(void);
void sdio_transfer(void);
void log_pool_init_e(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void rf_msg_process_body_n1cc(void);
void rf_timer_abort_common(void);
void ke_evt_schedule(void);
void msg_parse_short(void);
void sub_1320bc(void);
void log_system_init(void);
void buffer_pool_get(void);
void rf_cmd_queue_next(void);
void error_handler(void);


/* unit=lift_0139 class=medium score=3.879 addr=0x30514 */
void rf_level_apply(void) {
  uint32_t state = 0x8ef44a7cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_102a24();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_102a24();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0104 class=medium score=3.879 addr=0x1324c */
void rf_stream_start2_324c(void) {
  uint32_t state = 0xf43baf86U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_stream_start_1ac();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start_1ac();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0155 class=medium score=3.879 addr=0xc698 */
void sdio_dma_config(void) {
  uint32_t state = 0x5acfc8d2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
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
      hw_config_init_0688();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      hw_config_init_0688();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0153 class=medium score=3.879 addr=0x119c0 */
void rf_bus_write(void) {
  uint32_t state = 0x160f630aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_bus_clear();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_bus_clear();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0102 class=medium score=3.879 addr=0x11d58 */
void rf_bus_setup_1d58(void) {
  uint32_t state = 0xeea9976cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_reg_write_cb();
    } else {
      state ^= 0x7f4a7c15U;
    }
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

/* unit=lift_0112 class=medium score=3.879 addr=0x2ed40 */
void rf_mem_read_ed40(void) {
  uint32_t state = 0xba9f52ebU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0110 class=medium score=3.879 addr=0x2fd64 */
void rf_mem_write_fd64(void) {
  uint32_t state = 0xd2bc4021U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0145 class=medium score=3.879 addr=0x11a78 */
void rf_bus_write2_1a78(void) {
  uint32_t state = 0x9a4dea85U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0143 class=medium score=3.879 addr=0xfe60 */
void log_free_dispatch(void) {
  uint32_t state = 0x2435190cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
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
  switch (dispatch & 3U) {
    case 0U:
      log_free_pool_d();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_free_pool_d();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0142 class=medium score=3.879 addr=0x154e8 */
void patch_apply(void) {
  uint32_t state = 0x6bbf288aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      fw_config_apply();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      fw_config_apply();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0156 class=medium score=3.879 addr=0x12f60 */
void rf_msg_handler(void) {
  uint32_t state = 0x47e35761U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0135 class=medium score=3.879 addr=0xeda8 */
void rf_init_blocka(void) {
  uint32_t state = 0xecd14b95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockb();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockb();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0134 class=medium score=3.879 addr=0x12030 */
void rf_state_check(void) {
  uint32_t state = 0x4ce0747eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0132 class=medium score=3.879 addr=0x2e344 */
void sdio_buffer_prepare(void) {
  uint32_t state = 0x122ba5f3U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
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

/* unit=lift_0103 class=medium score=3.879 addr=0x116e0 */
void rf_fault_dump_n31c(void) {
  uint32_t state = 0xdc422abcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0108 class=medium score=3.879 addr=0x11858 */
void rf_bus_reset2(void) {
  uint32_t state = 0xbc0ca84dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_fault_dump_n31c();
    } else {
      state ^= 0x7f4a7c15U;
    }
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

/* unit=lift_0129 class=medium score=3.879 addr=0x12844 */
void rf_bus_reset_844(void) {
  uint32_t state = 0x1cd6aea5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_fault_dump_n31c();
    } else {
      state ^= 0x7f4a7c15U;
    }
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

/* unit=lift_0109 class=medium score=3.879 addr=0xfb38 */
void log_free_pool_dispatch2(void) {
  uint32_t state = 0xcd77b186U;
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

/* unit=lift_0107 class=medium score=3.879 addr=0x2cbb4 */
void message_dispatch(void) {
  uint32_t state = 0xe9f36f1cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
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
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0111 class=medium score=3.879 addr=0x2fc7c */
void rf_bus_reset2_n236_fc7c(void) {
  uint32_t state = 0xb0ea0c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  volatile uint32_t *rf = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t op = rf[0] & 3U;
  switch (op) {
    case 0U: state ^= rf[1]; break;
    case 1U: state ^= rf[2]; break;
    case 2U: state ^= rf[3]; break;
    default: state ^= 0xDEAD0101U; break;
  }
  rf_cmd_send();
  rf_cmd_wait();
  (void)state;
}

/* unit=lift_0106 class=medium score=3.879 addr=0x12e6c */
void rf_cmd_send(void) {
  uint32_t state = 0x4a1f596aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0105 class=medium score=3.879 addr=0x32d0 */
void phy_rf_init_2d0(void) {
  uint32_t state = 0x555f42b0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockb();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockb();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blocka();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blocka();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0200 class=medium score=3.844 addr=0xde48 */
void rf_hw_timer_init(void) {
  uint32_t state = 0xdfc24d82U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_timer_set();
    } else {
      state ^= 0x7f4a7c15U;
    }
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

/* unit=lift_0207 class=medium score=3.810 addr=0x3064c */
void rf_level_compute(void) {
  uint32_t state = 0x32db2d95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_hw_timer_read();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_hw_timer_read();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_level_step_04e0();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_step_04e0();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0208 class=medium score=3.810 addr=0x12dcc */
void rf_cmd_wait(void) {
  uint32_t state = 0x83ac3d29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      ke_timer_set();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0209 class=medium score=3.810 addr=0x131ac */
void rf_stream_start_1ac(void) {
  uint32_t state = 0xc330047eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_111f08();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_111f08();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0210 class=medium score=3.810 addr=0xebd4 */
void rf_reg_write_cb(void) {
  uint32_t state = 0x2cbbf9e7U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0203 class=medium score=3.810 addr=0xe0f8 */
void rf_init_blockc(void) {
  uint32_t state = 0xe668bdc8U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockb();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockb();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blocka();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blocka();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0220 class=medium score=3.741 addr=0xe3b8 */
void rf_init_blockb(void) {
  uint32_t state = 0x0fded352U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blockc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blockc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_init_blocka();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_init_blocka();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0221 class=medium score=3.741 addr=0x29f8 */
void rf_power_set(void) {
  uint32_t state = 0x76b7a883U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_102b00();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_102b00();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0215 class=medium score=3.741 addr=0xec30 */
void rf_reg_write_wait(void) {
  uint32_t state = 0x0712e06fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_reg_ack_cb();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_reg_ack_cb();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0223 class=medium score=3.741 addr=0x13aa4 */
void rf_msg_process_body_3aa4(void) {
  uint32_t state = 0x70106120U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
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

/* unit=lift_0217 class=medium score=3.741 addr=0xd15c */
void sdio_status_check(void) {
  uint32_t state = 0xa5096345U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
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
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0236 class=medium score=3.679 addr=0x7ed8 */
void crypto_channel_calc(void) {
  uint32_t state = 0x68bd2fecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      crypto_freq_set();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_freq_set();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0234 class=medium score=3.679 addr=0x2b64 */
void crypto_hw_disable(void) {
  uint32_t state = 0x9dfc4011U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_enable();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_enable();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_mac_core();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_mac_core();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0253 class=medium score=3.679 addr=0x39c4 */
void crypto_hw_power_up_39c4(void) {
  uint32_t state = 0x97cd0bddU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      crypto_power_apply();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0237 class=medium score=3.679 addr=0x10fb8 */
void log_queue_push(void) {
  uint32_t state = 0xdf441f57U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
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
  tx_dequeue();
  (void)state;
}

/* unit=lift_0238 class=medium score=3.679 addr=0x426b8 */
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

/* unit=lift_0240 class=medium score=3.679 addr=0x2c964 */
void event_queue_push(void) {
  uint32_t state = 0x96540698U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
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
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0231 class=medium score=3.679 addr=0x42b44 */
void math_helper_big(void) {
  uint32_t state = 0x51fb6109U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      sub_142f2c();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_142f2c();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0256 class=medium score=3.679 addr=0x427d8 */
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

/* unit=lift_0242 class=medium score=3.679 addr=0x2b00 */
void crypto_hw_enable(void) {
  uint32_t state = 0xbcff72acU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_disable();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_disable();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      crypto_mac_core();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_mac_core();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0243 class=medium score=3.679 addr=0xfd8c */
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
      rf_stream_start_1ac();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_stream_start_1ac();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
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
      rf_msg_process_body_n1cc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_msg_process_body_n1cc();
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

