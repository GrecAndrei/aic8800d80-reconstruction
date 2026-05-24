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
void crypto_hw_enable(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void log_free_pool_a(void);
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
void crypto_mac_core(void);
void math_round(void);
void crypto_state_dump(void);
void crypto_power_calc(void);
void crypto_power_apply(void);
void crypto_hw_write32(void);
void sdio_transfer(void);
void log_queue_push(void);
void sub_137490(void);
void log_pool_init_e(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void sdio_wait_busy(void);
void sdio_status_check(void);
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
  // role: sdio dma config helper
  uint32_t state = 0x5acfc8d2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
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

/* unit=lift_0098 class=medium score=3.879 addr=0xfbd0 */
void log_free_pool_dispatch2(void) {
  // role: logging free pool dispatcher
  uint32_t state = 0xcd77b186U;
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

/* unit=lift_0147 class=medium score=3.879 addr=0x11804 */
void rf_bus_setup(void) {
  // role: rf bus setup helper
  uint32_t state = 0xeea9976cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_reg_write_cb();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0150 class=medium score=3.879 addr=0x21f44 */
void rf_cmd_dispatch(void) {
  // role: rf cmd dispatch helper
  uint32_t state = 0xb0ea0c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0101 class=medium score=3.879 addr=0x122f0 */
void rf_bus_reset(void) {
  // role: rf bus reset helper
  uint32_t state = 0x1cd6aea5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_bus_mark();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0100 class=medium score=3.879 addr=0x2202c */
void rf_mem_write(void) {
  // role: rf mem write helper
  uint32_t state = 0xd2bc4021U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0099 class=medium score=3.879 addr=0x1146c */
void rf_bus_write(void) {
  // role: rf bus write helper
  uint32_t state = 0x160f630aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_bus_clear();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0094 class=medium score=3.879 addr=0x12918 */
void rf_cmd_send(void) {
  // role: rf cmd send helper
  uint32_t state = 0x4a1f596aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0097 class=medium score=3.879 addr=0x11304 */
void rf_bus_reset2(void) {
  // role: rf bus reset2 helper
  uint32_t state = 0xbc0ca84dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_bus_mark();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0096 class=medium score=3.879 addr=0x1118c */
void rf_bus_mark(void) {
  // role: rf bus mark helper
  uint32_t state = 0xdc422abcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0095 class=medium score=3.879 addr=0x1ebb4 */
void sdio_buffer_prepare(void) {
  // role: sdio buffer prepare helper
  uint32_t state = 0x122ba5f3U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  if ((state & 2U) != 0U) {
    log_hw_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_enqueue();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_1435d0();
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

/* unit=lift_0093 class=medium score=3.879 addr=0x11524 */
void rf_bus_write2(void) {
  // role: rf bus write2 helper
  uint32_t state = 0x9a4dea85U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0090 class=medium score=3.879 addr=0x1f594 */
void rf_mem_read(void) {
  // role: rf mem read helper
  uint32_t state = 0xba9f52ebU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0092 class=medium score=3.879 addr=0x26dd8 */
void rf_level_apply(void) {
  // role: rf level apply helper
  uint32_t state = 0x8ef44a7cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    sub_102a24();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0199 class=medium score=3.844 addr=0xde98 */
void rf_hw_timer_init(void) {
  // role: rf hw timer init helper
  uint32_t state = 0xdfc24d82U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0206 class=medium score=3.810 addr=0xefb4 */
void rf_reg_write_cb(void) {
  // role: rf reg write helper
  uint32_t state = 0x2cbbf9e7U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0204 class=medium score=3.810 addr=0x12878 */
void rf_cmd_wait(void) {
  // role: rf cmd wait helper
  uint32_t state = 0x83ac3d29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    ke_timer_set();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0205 class=medium score=3.810 addr=0x26f10 */
void rf_level_compute(void) {
  // role: rf level compute helper
  uint32_t state = 0x32db2d95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_hw_timer_read();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_level_step();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0212 class=medium score=3.810 addr=0xe4d8 */
void rf_init_blockc(void) {
  // role: rf init blockc helper
  uint32_t state = 0xe668bdc8U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_init_blockb();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_init_blocka();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0224 class=medium score=3.741 addr=0xf010 */
void rf_reg_write_wait(void) {
  // role: rf reg write wait helper
  uint32_t state = 0x0712e06fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_reg_ack_cb();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0222 class=medium score=3.741 addr=0xe798 */
void rf_init_blockb(void) {
  // role: rf init blockb helper
  uint32_t state = 0x0fded352U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_init_blockc();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_init_blocka();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0216 class=medium score=3.741 addr=0x29dc */
void rf_power_set(void) {
  // role: rf power set helper
  uint32_t state = 0x76b7a883U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    sub_102b00();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0250 class=medium score=3.679 addr=0x3334 */
void clock_calc(void) {
  // role: clock calculation helper
  uint32_t state = 0xa6b74c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    feature_guard_sdio();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    firmware_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    fw_config_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_list_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0251 class=medium score=3.679 addr=0x2b40 */
void crypto_hw_disable(void) {
  // role: crypto hardware disable helper
  uint32_t state = 0x9dfc4011U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  if ((state & 2U) != 0U) {
    crypto_hw_enable();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_mac_core();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0248 class=medium score=3.679 addr=0x202 */
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

/* unit=lift_0233 class=medium score=3.679 addr=0x6f08 */
void crypto_hw_clear_regs(void) {
  // role: clear/reset helper
  uint32_t state = 0xf580aa98U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)3U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  if ((state & 2U) != 0U) {
    crypto_state_dump();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_calc();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0247 class=medium score=3.679 addr=0x3da8 */
void crypto_iq_calculate(void) {
  // role: crypto IQ calculation helper
  uint32_t state = 0x846ba426U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    clock_calc();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0228 class=medium score=3.679 addr=0x3a00 */
void crypto_table_init(void) {
  // role: crypto table init helper
  uint32_t state = 0x46ec633eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    crypto_iq_calculate();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0225 class=medium score=3.679 addr=0x948 */
void crypto_key_load(void) {
  // role: crypto key load helper
  uint32_t state = 0xd54fc822U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  if ((state & 2U) != 0U) {
    crypto_hw_write32();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
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

