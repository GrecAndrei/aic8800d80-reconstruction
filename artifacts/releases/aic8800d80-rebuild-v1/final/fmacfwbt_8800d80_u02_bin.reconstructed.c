/* Auto-generated per-image composed reconstruction */
/* image: fmacfwbt_8800d80_u02.bin */

#include <stdint.h>

/* Auto-generated forward declarations for compileability */
void rf_level_apply(void);
void rf_stream_start2(void);
void sdio_dma_config(void);
void rf_bus_write(void);
void rf_bus_setup(void);
void rf_mem_read(void);
void rf_mem_write(void);
void rf_bus_write2(void);
void log_free_dispatch(void);
void patch_apply(void);
void rf_msg_handler(void);
void rf_init_blocka(void);
void rf_state_check(void);
void sdio_buffer_prepare(void);
void rf_bus_mark(void);
void rf_bus_reset2(void);
void rf_bus_reset(void);
void log_free_pool_dispatch2(void);
void message_dispatch(void);
void rf_cmd_dispatch(void);
void rf_cmd_send(void);
void phy_rf_init(void);
void rf_hw_timer_init(void);
void rf_level_compute(void);
void rf_cmd_wait(void);
void rf_stream_start(void);
void rf_reg_write_cb(void);
void rf_init_blockc(void);
void rf_init_blockb(void);
void rf_power_set(void);
void rf_reg_write_wait(void);
void rf_msg_process_body(void);
void sdio_status_check(void);
void crypto_channel_calc(void);
void crypto_hw_disable(void);
void crypto_hw_power_up(void);
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
void rf_level_step(void);
void sub_111f08(void);
void sub_102b00(void);
void rf_reg_ack_cb(void);
void crypto_freq_set(void);
void crypto_mac_core(void);
void crypto_power_apply(void);
void tx_dequeue(void);
void math_helper_int(void);
void sub_142f2c(void);
void log_pool_init_e(void);
void sdio_transfer(void);
void sub_137490(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void sdio_wait_busy(void);
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

/* unit=lift_0104 class=medium score=3.879 addr=0x1324c */
void rf_stream_start2(void) {
  // role: rf stream start2 helper
  uint32_t state = 0xf43baf86U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    rf_stream_start();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0155 class=medium score=3.879 addr=0xc698 */
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

/* unit=lift_0153 class=medium score=3.879 addr=0x119c0 */
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

/* unit=lift_0102 class=medium score=3.879 addr=0x11d58 */
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

/* unit=lift_0112 class=medium score=3.879 addr=0x2ed40 */
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

/* unit=lift_0110 class=medium score=3.879 addr=0x2fd64 */
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

/* unit=lift_0145 class=medium score=3.879 addr=0x11a78 */
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

/* unit=lift_0143 class=medium score=3.879 addr=0xfe60 */
void log_free_dispatch(void) {
  // role: logging free dispatcher
  uint32_t state = 0x2435190cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  if ((state & 2U) != 0U) {
    log_free_pool_a();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_free_pool_b();
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

/* unit=lift_0142 class=medium score=3.879 addr=0x154e8 */
void patch_apply(void) {
  // role: patching helper
  uint32_t state = 0x6bbf288aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    fw_config_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0156 class=medium score=3.879 addr=0x12f60 */
void rf_msg_handler(void) {
  // role: rf message helper
  uint32_t state = 0x47e35761U;
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

/* unit=lift_0135 class=medium score=3.879 addr=0xeda8 */
void rf_init_blocka(void) {
  // role: rf init blocka helper
  uint32_t state = 0xecd14b95U;
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
    rf_init_blockb();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0134 class=medium score=3.879 addr=0x12030 */
void rf_state_check(void) {
  // role: rf state check helper
  uint32_t state = 0x4ce0747eU;
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

/* unit=lift_0132 class=medium score=3.879 addr=0x2e344 */
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

/* unit=lift_0103 class=medium score=3.879 addr=0x116e0 */
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

/* unit=lift_0108 class=medium score=3.879 addr=0x11858 */
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

/* unit=lift_0129 class=medium score=3.879 addr=0x12844 */
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

/* unit=lift_0109 class=medium score=3.879 addr=0xfb38 */
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

/* unit=lift_0107 class=medium score=3.879 addr=0x2cbb4 */
void message_dispatch(void) {
  // role: message dispatch helper
  uint32_t state = 0xe9f36f1cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0111 class=medium score=3.879 addr=0x2fc7c */
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

/* unit=lift_0106 class=medium score=3.879 addr=0x12e6c */
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

/* unit=lift_0105 class=medium score=3.879 addr=0x32d0 */
void phy_rf_init(void) {
  // role: rf phy init helper
  uint32_t state = 0x555f42b0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    rf_init_blockc();
  } else {
    state ^= 0x3c6ef372U;
  }
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

/* unit=lift_0200 class=medium score=3.844 addr=0xde48 */
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

/* unit=lift_0207 class=medium score=3.810 addr=0x3064c */
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

/* unit=lift_0208 class=medium score=3.810 addr=0x12dcc */
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

/* unit=lift_0209 class=medium score=3.810 addr=0x131ac */
void rf_stream_start(void) {
  // role: rf stream start helper
  uint32_t state = 0xc330047eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *rf_mmio = (volatile uint32_t *)(uintptr_t)0x40010000U;
  uint32_t rf_reg = rf_mmio[(state >> 2) & 0x3FU];
  state ^= (rf_reg ^ 0x00A500A5U);
  if ((state & 2U) != 0U) {
    sub_111f08();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0210 class=medium score=3.810 addr=0xebd4 */
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

/* unit=lift_0203 class=medium score=3.810 addr=0xe0f8 */
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

/* unit=lift_0220 class=medium score=3.741 addr=0xe3b8 */
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

/* unit=lift_0221 class=medium score=3.741 addr=0x29f8 */
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

/* unit=lift_0215 class=medium score=3.741 addr=0xec30 */
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

/* unit=lift_0223 class=medium score=3.741 addr=0x13aa4 */
void rf_msg_process_body(void) {
  // role: rf message process body helper
  uint32_t state = 0x70106120U;
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

/* unit=lift_0217 class=medium score=3.741 addr=0xd15c */
void sdio_status_check(void) {
  // role: sdio status check helper
  uint32_t state = 0xa5096345U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  volatile uint32_t *sdio_mmio = (volatile uint32_t *)(uintptr_t)0x40020000U;
  uint32_t sdio_st = sdio_mmio[(state >> 3) & 0x1FU];
  state ^= (sdio_st << 1) ^ 0x5A5A0001U;
  if ((state & 2U) != 0U) {
    feature_guard_sdio();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0236 class=medium score=3.679 addr=0x7ed8 */
void crypto_channel_calc(void) {
  // role: crypto channel calculation helper
  uint32_t state = 0x68bd2fecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  if ((state & 2U) != 0U) {
    crypto_freq_set();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0234 class=medium score=3.679 addr=0x2b64 */
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

/* unit=lift_0253 class=medium score=3.679 addr=0x39c4 */
void crypto_hw_power_up(void) {
  // role: crypto hardware power up helper
  uint32_t state = 0x97cd0bddU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    crypto_power_apply();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0237 class=medium score=3.679 addr=0x10fb8 */
void log_queue_push(void) {
  // role: logging queue push helper
  uint32_t state = 0xdf441f57U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  uint32_t ring_idx = (state >> 4) & 0xFFU;
  state ^= (ring_idx * 0x45D9F3BU);
  tx_dequeue();
  state ^= 0xD00D00D0U;
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0238 class=medium score=3.679 addr=0x426b8 */
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

/* unit=lift_0240 class=medium score=3.679 addr=0x2c964 */
void event_queue_push(void) {
  // role: event queue push
  uint32_t state = 0x96540698U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0231 class=medium score=3.679 addr=0x42b44 */
void math_helper_big(void) {
  // role: numeric aggregation helper
  uint32_t state = 0x51fb6109U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sub_142f2c();
  } else {
    state ^= 0x3c6ef372U;
  }
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0256 class=medium score=3.679 addr=0x427d8 */
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

/* unit=lift_0242 class=medium score=3.679 addr=0x2b00 */
void crypto_hw_enable(void) {
  // role: crypto hardware enable helper
  uint32_t state = 0xbcff72acU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  uint32_t key_mix = (state ^ 0x9E3779B9U) + ((state << 7) | (state >> 25));
  state ^= key_mix;
  if ((state & 2U) != 0U) {
    crypto_hw_disable();
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

/* unit=lift_0243 class=medium score=3.679 addr=0xfd8c */
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

