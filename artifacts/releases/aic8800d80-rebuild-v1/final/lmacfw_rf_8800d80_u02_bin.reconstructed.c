/* Auto-generated per-image composed reconstruction */
/* image: lmacfw_rf_8800d80_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void sdio_dma_config(void);
void log_free_pool_dispatch2(void);
void rf_bus_setup(void);
void rf_cmd_dispatch(void);
void rf_bus_reset(void);
void rf_mem_write(void);
void rf_bus_write(void);
void rf_cmd_send(void);
void rf_bus_reset2(void);
void rf_bus_mark(void);
void sdio_buffer_prepare(void);
void rf_bus_write2(void);
void rf_mem_read(void);
void rf_level_apply(void);
void rf_hw_timer_init(void);
void rf_reg_write_cb(void);
void rf_cmd_wait(void);
void rf_level_compute(void);
void rf_init_blockc(void);
void rf_reg_write_wait(void);
void rf_init_blockb(void);
void rf_power_set(void);
void clock_calc(void);
void crypto_hw_disable(void);
void memset_impl(void);
void crypto_hw_clear_regs(void);
void crypto_iq_calculate(void);
void crypto_table_init(void);
void crypto_key_load(void);
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
void chip_variant_detect(void);
void hw_config_init(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void rf_bus_clear(void);
void log_enqueue(void);
void sub_1435d0(void);
void sub_102a24(void);
void ke_timer_set(void);
void rf_hw_timer_read(void);
void rf_level_step(void);
void rf_init_blocka(void);
void rf_reg_ack_cb(void);
void sub_102b00(void);
void firmware_init(void);
void fw_config_apply(void);
void log_list_init(void);
void crypto_hw_enable(void);
void crypto_mac_core(void);
void crypto_power_calc(void);
void crypto_state_dump(void);
void crypto_power_apply(void);
void crypto_hw_write32(void);
void sdio_transfer(void);
void log_queue_push(void);
void log_pool_init_e(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void sdio_status_check(void);
void ipc_doorbell_handler(void);
void rf_timer_abort_common(void);
void ke_evt_schedule(void);
void msg_parse_short(void);
void sub_1320bc(void);
void log_system_init(void);
void buffer_pool_get(void);
void rf_cmd_queue_next(void);
void error_handler(void);


/* unit=lift_0091 class=medium score=3.879 addr=0xcbe0 */
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

/* unit=lift_0098 class=medium score=3.879 addr=0xfbd0 */
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

/* unit=lift_0147 class=medium score=3.879 addr=0x11804 */
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

/* unit=lift_0150 class=medium score=3.879 addr=0x21f44 */
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

/* unit=lift_0101 class=medium score=3.879 addr=0x122f0 */
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

/* unit=lift_0100 class=medium score=3.879 addr=0x2202c */
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

/* unit=lift_0099 class=medium score=3.879 addr=0x1146c */
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

/* unit=lift_0094 class=medium score=3.879 addr=0x12918 */
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

/* unit=lift_0097 class=medium score=3.879 addr=0x11304 */
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

/* unit=lift_0096 class=medium score=3.879 addr=0x1118c */
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

/* unit=lift_0095 class=medium score=3.879 addr=0x1ebb4 */
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

/* unit=lift_0093 class=medium score=3.879 addr=0x11524 */
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

/* unit=lift_0090 class=medium score=3.879 addr=0x1f594 */
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

/* unit=lift_0092 class=medium score=3.879 addr=0x26dd8 */
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

/* unit=lift_0199 class=medium score=3.844 addr=0xde98 */
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

/* unit=lift_0206 class=medium score=3.810 addr=0xefb4 */
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

/* unit=lift_0204 class=medium score=3.810 addr=0x12878 */
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

/* unit=lift_0205 class=medium score=3.810 addr=0x26f10 */
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

/* unit=lift_0212 class=medium score=3.810 addr=0xe4d8 */
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

/* unit=lift_0224 class=medium score=3.741 addr=0xf010 */
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

/* unit=lift_0222 class=medium score=3.741 addr=0xe798 */
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

/* unit=lift_0216 class=medium score=3.741 addr=0x29dc */
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

/* unit=lift_0250 class=medium score=3.679 addr=0x3334 */
void clock_calc(void) {
  uint32_t state = 0xa6b74c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
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
      firmware_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      firmware_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
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
  switch (dispatch & 3U) {
    case 0U:
      log_list_init();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      log_list_init();
      break;
  }
  dispatch = (dispatch >> 1) ^ (state << 3);
  (void)dispatch;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0251 class=medium score=3.679 addr=0x2b40 */
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

/* unit=lift_0248 class=medium score=3.679 addr=0x202 */
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

/* unit=lift_0233 class=medium score=3.679 addr=0x6f08 */
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

/* unit=lift_0247 class=medium score=3.679 addr=0x3da8 */
void crypto_iq_calculate(void) {
  uint32_t state = 0x846ba426U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      clock_calc();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0228 class=medium score=3.679 addr=0x3a00 */
void crypto_table_init(void) {
  uint32_t state = 0x46ec633eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch_budget = (state & 3U) + 1U;
  for (uint32_t step = 0U; step < dispatch_budget; ++step) {
    state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
    if (((state >> (step & 7U)) & 1U) != 0U) {
      crypto_iq_calculate();
    } else {
      state ^= 0x7f4a7c15U;
    }
    state ^= (0x11110000U + step);
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0225 class=medium score=3.679 addr=0x948 */
void crypto_key_load(void) {
  uint32_t state = 0xd54fc822U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  uint32_t dispatch = 0U;
  dispatch = state ^ 0x6d2b79f5U;
  switch (dispatch & 3U) {
    case 0U:
      crypto_hw_write32();
      break;
    case 1U:
      state ^= 0x3c6ef372U;
      break;
    default:
      state = (state << 1) | (state >> 31);
      crypto_hw_write32();
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

