/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void rf_state_check(void);
void rf_bus_reset(void);
void rf_hw_timer_read(void);
void rf_level_apply(void);
void sdio_dma_config(void);
void patch_apply(void);
void rf_reg_write_core(void);
void rf_level_compute(void);
void sdio_transfer(void);
void phy_rf_init(void);
void rf_init_blockc(void);
void rf_stream_start(void);
void rf_mem_read(void);
void rf_msg_handler(void);
void rf_bus_write2(void);
void rf_bus_reset2(void);
void rf_bus_init(void);
void rf_mem_write(void);
void log_free_dispatch(void);
void rf_cmd_queue_next(void);
void rf_init_blocka(void);
void rf_bus_setup(void);
void rf_fault_dump(void);
void rf_cmd_wait(void);
void log_free_pool_dispatch2(void);
void rf_timer_toggle(void);
void rf_stream_start2(void);
void rf_level_dump(void);
void rf_cmd_process(void);
void rf_cmd_dispatch(void);
void rf_bus_write(void);
void rf_msg_process_body(void);
void message_dispatch(void);
void rf_cmd_send(void);
void sdio_status_check(void);
void rf_init_blockb(void);
void ipc_doorbell_handler(void);
void sdio_buffer_prepare(void);
void rf_bus_mark(void);
void rf_reg_write_cb(void);
void rf_hw_timer_init(void);
void rf_reg_write_wait(void);
void rf_msg_log_rate(void);
void sdio_wait_busy(void);
void rf_stream_start_once(void);
void rf_power_set(void);
void rf_timer_toggle_update(void);
void fw_config_apply(void);
void msg_parse(void);
void log_pool_init_e(void);
void chip_feature_check(void);
void crypto_hw_enable(void);
void timestamp_remove(void);
void fp_convert_int(void);
void log_queue_push(void);
void tx_phy_config(void);
void crypto_channel_calc(void);
void log_ptr_in_range(void);
void firmware_init(void);
void panic_loop(void);
void crypto_hw_clear_regs(void);
void math_round(void);
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
void rf_level_step(void);
void sub_102a24(void);
void chip_variant_detect(void);
void hw_config_init(void);
void sub_111f08(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void log_queue_alloc(void);
void ke_timer_set(void);
void rf_bus_clear(void);
void buffer_pool_manage(void);
void log_enqueue(void);
void sub_1435d0(void);
void rf_reg_ack_cb(void);
void sub_102b00(void);
void msg_handler_tx(void);
void sub_137490(void);
void log_system_init_mode2(void);
void feature_always_on(void);
void crypto_hw_disable(void);
void crypto_mac_core(void);
void timestamp_list_contains(void);
void fp_convert_uint(void);
void tx_dequeue(void);
void crypto_hw_power_up(void);
void crypto_freq_set(void);
void log_printf(void);
void ke_evt_schedule(void);
void crypto_power_calc(void);
void crypto_state_dump(void);
void crypto_power_apply(void);
void math_helper_int(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void rf_timer_abort_common(void);
void msg_parse_short(void);
void sub_1320bc(void);
void log_system_init(void);
void buffer_pool_get(void);
void error_handler(void);


/* unit=lift_0126 class=medium score=3.879 addr=0x121d4 */
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

/* unit=lift_0144 class=medium score=3.879 addr=0x129e8 */
void rf_bus_reset(void) {
  uint32_t state = 0x1cd6aea5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_bus_mark();
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

/* unit=lift_0125 class=medium score=3.879 addr=0xe048 */
void rf_hw_timer_read(void) {
  uint32_t state = 0x91753fc7U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      rf_level_step();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_step();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_level_compute();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_compute();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0083 class=medium score=3.879 addr=0x302f8 */
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

/* unit=lift_0127 class=medium score=3.879 addr=0xc840 */
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
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0128 class=medium score=3.879 addr=0x14eac */
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

/* unit=lift_0118 class=medium score=3.879 addr=0xee40 */
void rf_reg_write_core(void) {
  uint32_t state = 0x816af6d4U;
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

/* unit=lift_0130 class=medium score=3.879 addr=0x30430 */
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
      rf_level_step();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_step();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0131 class=medium score=3.879 addr=0xd808 */
void sdio_transfer(void) {
  uint32_t state = 0x1eb6c054U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  volatile uint32_t *sdio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t cmd = state ^ 0xC001D00DU;
  sdio[0] = cmd;
  uint32_t wait = 256U;
  while (wait-- > 0U) {
    uint32_t st = sdio[1] & 0x3U;
    if (st == 0U) { break; }
    state ^= st + wait;
  }
  sdio[2] = state;
  sdio_buffer_prepare();
  (void)state;
}

/* unit=lift_0084 class=medium score=3.879 addr=0x3478 */
void phy_rf_init(void) {
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

/* unit=lift_0133 class=medium score=3.879 addr=0xe2a0 */
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

/* unit=lift_0085 class=medium score=3.879 addr=0x13350 */
void rf_stream_start(void) {
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

/* unit=lift_0086 class=medium score=3.879 addr=0x2eb18 */
void rf_mem_read(void) {
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

/* unit=lift_0136 class=medium score=3.879 addr=0x13104 */
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

/* unit=lift_0137 class=medium score=3.879 addr=0x11c1c */
void rf_bus_write2(void) {
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

/* unit=lift_0138 class=medium score=3.879 addr=0x119fc */
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
      rf_bus_mark();
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

/* unit=lift_0087 class=medium score=3.879 addr=0x11db8 */
void rf_bus_init(void) {
  uint32_t state = 0x9d0abc0fU;
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

/* unit=lift_0140 class=medium score=3.879 addr=0x2fb48 */
void rf_mem_write(void) {
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

/* unit=lift_0141 class=medium score=3.879 addr=0x10008 */
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

/* unit=lift_0088 class=medium score=3.879 addr=0x134b4 */
void rf_cmd_queue_next(void) {
  uint32_t state = 0xfea55400U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
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
      log_queue_alloc();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_queue_alloc();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0082 class=medium score=3.879 addr=0xef50 */
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

/* unit=lift_0117 class=medium score=3.879 addr=0x11efc */
void rf_bus_setup(void) {
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

/* unit=lift_0089 class=medium score=3.879 addr=0x14748 */
void rf_fault_dump(void) {
  uint32_t state = 0xe2367dbfU;
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

/* unit=lift_0146 class=medium score=3.879 addr=0x12f70 */
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

/* unit=lift_0124 class=medium score=3.879 addr=0xfce0 */
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

/* unit=lift_0148 class=medium score=3.879 addr=0x2f060 */
void rf_timer_toggle(void) {
  uint32_t state = 0xd55760eaU;
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

/* unit=lift_0149 class=medium score=3.879 addr=0x133f0 */
void rf_stream_start2(void) {
  uint32_t state = 0xf43baf86U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
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

/* unit=lift_0113 class=medium score=3.879 addr=0x303a0 */
void rf_level_dump(void) {
  uint32_t state = 0x4671173aU;
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

/* unit=lift_0151 class=medium score=3.879 addr=0x13558 */
void rf_cmd_process(void) {
  uint32_t state = 0x4c7eb1baU;
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

/* unit=lift_0152 class=medium score=3.879 addr=0x2fa60 */
void rf_cmd_dispatch(void) {
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

/* unit=lift_0114 class=medium score=3.879 addr=0x11b64 */
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

/* unit=lift_0154 class=medium score=3.879 addr=0x13c48 */
void rf_msg_process_body(void) {
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

/* unit=lift_0115 class=medium score=3.879 addr=0x2c98c */
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

/* unit=lift_0116 class=medium score=3.879 addr=0x13010 */
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

/* unit=lift_0119 class=medium score=3.879 addr=0xd304 */
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

/* unit=lift_0123 class=medium score=3.879 addr=0xe560 */
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

/* unit=lift_0122 class=medium score=3.879 addr=0x1597c */
void ipc_doorbell_handler(void) {
  uint32_t state = 0x840b7203U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
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

/* unit=lift_0121 class=medium score=3.879 addr=0x2e11c */
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

/* unit=lift_0120 class=medium score=3.879 addr=0x11884 */
void rf_bus_mark(void) {
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

/* unit=lift_0157 class=medium score=3.861 addr=0xed7c */
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

/* unit=lift_0201 class=medium score=3.844 addr=0xdff0 */
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

/* unit=lift_0202 class=medium score=3.827 addr=0xedd8 */
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

/* unit=lift_0211 class=medium score=3.810 addr=0x141c8 */
void rf_msg_log_rate(void) {
  uint32_t state = 0x66490e26U;
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

/* unit=lift_0213 class=medium score=3.793 addr=0x2ea10 */
void sdio_wait_busy(void) {
  uint32_t state = 0xa411a997U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
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
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0219 class=medium score=3.741 addr=0x14114 */
void rf_stream_start_once(void) {
  uint32_t state = 0xafed3abeU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      rf_cmd_send();
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

/* unit=lift_0214 class=medium score=3.741 addr=0x2b80 */
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

/* unit=lift_0218 class=medium score=3.741 addr=0x304b0 */
void rf_timer_toggle_update(void) {
  uint32_t state = 0xc7e4458fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
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
      rf_level_step();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_step();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      rf_level_compute();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      rf_level_compute();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0235 class=medium score=3.679 addr=0x2a0 */
void fw_config_apply(void) {
  uint32_t state = 0xb0cbe88dU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      patch_apply();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      patch_apply();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0229 class=medium score=3.679 addr=0x2ea88 */
void msg_parse(void) {
  uint32_t state = 0xe33da892U;
  state ^= ((uint32_t)6U << 16) ^ ((uint32_t)2U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      msg_handler_tx();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      msg_handler_tx();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  switch (dispatch & 3U) {
    case 0U:
      sub_137490();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      sub_137490();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0230 class=medium score=3.679 addr=0x13814 */
void log_pool_init_e(void) {
  uint32_t state = 0xe2d507c2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  log_system_init_mode2();
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0255 class=medium score=3.679 addr=0x19fc */
void chip_feature_check(void) {
  uint32_t state = 0x247d772eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      feature_always_on();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      feature_always_on();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0226 class=medium score=3.679 addr=0x2ca8 */
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

/* unit=lift_0245 class=medium score=3.679 addr=0x24e34 */
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

/* unit=lift_0227 class=medium score=3.679 addr=0x2d708 */
void fp_convert_int(void) {
  uint32_t state = 0xeae66cc6U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      fp_convert_uint();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      fp_convert_uint();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0232 class=medium score=3.679 addr=0x1115c */
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

/* unit=lift_0239 class=medium score=3.679 addr=0xc360 */
void tx_phy_config(void) {
  uint32_t state = 0xf99afe58U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_power_up();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_power_up();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0241 class=medium score=3.679 addr=0x8080 */
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

/* unit=lift_0254 class=medium score=3.679 addr=0xff34 */
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

/* unit=lift_0244 class=medium score=3.679 addr=0x478 */
void firmware_init(void) {
  uint32_t state = 0x547c85c0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      fw_config_apply();
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

/* unit=lift_0252 class=medium score=3.679 addr=0x6d8 */
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

/* unit=lift_0249 class=medium score=3.679 addr=0x7518 */
void crypto_hw_clear_regs(void) {
  uint32_t state = 0xf580aa98U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)3U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  volatile uint32_t *regs = (volatile uint32_t *)(uintptr_t)0x40030000U;
  for (uint32_t i = 0U; i < 16U; ++i) {
    regs[i] = 0U;
  }
  state ^= 0xC1EA4EA1U;
  crypto_power_calc();
  crypto_state_dump();
  crypto_power_apply();
  (void)state;
}

/* unit=lift_0246 class=medium score=3.679 addr=0x4261c */
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

