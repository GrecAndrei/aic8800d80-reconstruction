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
void crypto_hw_power_up(void);
void log_enqueue(void);
void sub_111f08(void);
void log_free_pool_a(void);
void log_free_pool_b(void);
void log_free_pool_c(void);
void log_free_pool_d(void);
void log_queue_alloc(void);
void ke_timer_set(void);
void rf_bus_clear(void);
void buffer_pool_manage(void);
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
void crypto_freq_set(void);
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
  // role: rf state check helper
  uint32_t state = 0x4ce0747eU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0144 class=medium score=3.879 addr=0x129e8 */
void rf_bus_reset(void) {
  // role: rf bus reset helper
  uint32_t state = 0x1cd6aea5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0125 class=medium score=3.879 addr=0xe048 */
void rf_hw_timer_read(void) {
  // role: rf hw timer read helper
  uint32_t state = 0x91753fc7U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    rf_level_step();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_level_compute();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: return observed value
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0083 class=medium score=3.879 addr=0x302f8 */
void rf_level_apply(void) {
  // role: rf level apply helper
  uint32_t state = 0x8ef44a7cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sub_102a24();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0127 class=medium score=3.879 addr=0xc840 */
void sdio_dma_config(void) {
  // role: sdio dma config helper
  uint32_t state = 0x5acfc8d2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    chip_variant_detect();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_hw_power_up();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_enqueue();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0128 class=medium score=3.879 addr=0x14eac */
void patch_apply(void) {
  // role: patching helper
  uint32_t state = 0x6bbf288aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    fw_config_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0118 class=medium score=3.879 addr=0xee40 */
void rf_reg_write_core(void) {
  // role: rf reg write core helper
  uint32_t state = 0x816af6d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0130 class=medium score=3.879 addr=0x30430 */
void rf_level_compute(void) {
  // role: rf level compute helper
  uint32_t state = 0x32db2d95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
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
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0131 class=medium score=3.879 addr=0xd808 */
void sdio_transfer(void) {
  // role: sdio transfer helper
  uint32_t state = 0x1eb6c054U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)3U << 8);
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
    sdio_buffer_prepare();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0084 class=medium score=3.879 addr=0x3478 */
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
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0133 class=medium score=3.879 addr=0xe2a0 */
void rf_init_blockc(void) {
  // role: rf init blockc helper
  uint32_t state = 0xe668bdc8U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
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
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0085 class=medium score=3.879 addr=0x13350 */
void rf_stream_start(void) {
  // role: rf stream start helper
  uint32_t state = 0xc330047eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sub_111f08();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0086 class=medium score=3.879 addr=0x2eb18 */
void rf_mem_read(void) {
  // role: rf mem read helper
  uint32_t state = 0xba9f52ebU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0136 class=medium score=3.879 addr=0x13104 */
void rf_msg_handler(void) {
  // role: rf message helper
  uint32_t state = 0x47e35761U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0137 class=medium score=3.879 addr=0x11c1c */
void rf_bus_write2(void) {
  // role: rf bus write2 helper
  uint32_t state = 0x9a4dea85U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0138 class=medium score=3.879 addr=0x119fc */
void rf_bus_reset2(void) {
  // role: rf bus reset2 helper
  uint32_t state = 0xbc0ca84dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0087 class=medium score=3.879 addr=0x11db8 */
void rf_bus_init(void) {
  // role: rf bus init helper
  uint32_t state = 0x9d0abc0fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0140 class=medium score=3.879 addr=0x2fb48 */
void rf_mem_write(void) {
  // role: rf mem write helper
  uint32_t state = 0xd2bc4021U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0141 class=medium score=3.879 addr=0x10008 */
void log_free_dispatch(void) {
  // role: logging free dispatcher
  uint32_t state = 0x2435190cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
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
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0088 class=medium score=3.879 addr=0x134b4 */
void rf_cmd_queue_next(void) {
  // role: rf cmd queue next helper
  uint32_t state = 0xfea55400U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    log_queue_push();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_queue_alloc();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0082 class=medium score=3.879 addr=0xef50 */
void rf_init_blocka(void) {
  // role: rf init blocka helper
  uint32_t state = 0xecd14b95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    rf_init_blockb();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_init_blockc();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0117 class=medium score=3.879 addr=0x11efc */
void rf_bus_setup(void) {
  // role: rf bus setup helper
  uint32_t state = 0xeea9976cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0089 class=medium score=3.879 addr=0x14748 */
void rf_fault_dump(void) {
  // role: rf fault dump helper
  uint32_t state = 0xe2367dbfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0146 class=medium score=3.879 addr=0x12f70 */
void rf_cmd_wait(void) {
  // role: rf cmd wait helper
  uint32_t state = 0x83ac3d29U;
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

/* unit=lift_0124 class=medium score=3.879 addr=0xfce0 */
void log_free_pool_dispatch2(void) {
  // role: logging free pool dispatcher
  uint32_t state = 0xcd77b186U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
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
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0148 class=medium score=3.879 addr=0x2f060 */
void rf_timer_toggle(void) {
  // role: rf timer toggle helper
  uint32_t state = 0xd55760eaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0149 class=medium score=3.879 addr=0x133f0 */
void rf_stream_start2(void) {
  // role: rf stream start2 helper
  uint32_t state = 0xf43baf86U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    rf_stream_start();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0113 class=medium score=3.879 addr=0x303a0 */
void rf_level_dump(void) {
  // role: rf level dump helper
  uint32_t state = 0x4671173aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0151 class=medium score=3.879 addr=0x13558 */
void rf_cmd_process(void) {
  // role: rf cmd process helper
  uint32_t state = 0x4c7eb1baU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0152 class=medium score=3.879 addr=0x2fa60 */
void rf_cmd_dispatch(void) {
  // role: rf cmd dispatch helper
  uint32_t state = 0xb0ea0c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0114 class=medium score=3.879 addr=0x11b64 */
void rf_bus_write(void) {
  // role: rf bus write helper
  uint32_t state = 0x160f630aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    rf_bus_clear();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0154 class=medium score=3.879 addr=0x13c48 */
void rf_msg_process_body(void) {
  // role: rf message process body helper
  uint32_t state = 0x70106120U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0115 class=medium score=3.879 addr=0x2c98c */
void message_dispatch(void) {
  // role: message dispatch helper
  uint32_t state = 0xe9f36f1cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    buffer_pool_manage();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0116 class=medium score=3.879 addr=0x13010 */
void rf_cmd_send(void) {
  // role: rf cmd send helper
  uint32_t state = 0x4a1f596aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0119 class=medium score=3.879 addr=0xd304 */
void sdio_status_check(void) {
  // role: sdio status check helper
  uint32_t state = 0xa5096345U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    feature_guard_sdio();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0123 class=medium score=3.879 addr=0xe560 */
void rf_init_blockb(void) {
  // role: rf init blockb helper
  uint32_t state = 0x0fded352U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    rf_init_blocka();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    rf_init_blockc();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0122 class=medium score=3.879 addr=0x1597c */
void ipc_doorbell_handler(void) {
  // role: ipc doorbell handler
  uint32_t state = 0x840b7203U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sdio_wait_busy();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: acknowledge inbound handling
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0121 class=medium score=3.879 addr=0x2e11c */
void sdio_buffer_prepare(void) {
  // role: sdio buffer prepare helper
  uint32_t state = 0x122ba5f3U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
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
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0120 class=medium score=3.879 addr=0x11884 */
void rf_bus_mark(void) {
  // role: rf bus mark helper
  uint32_t state = 0xdc422abcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0157 class=medium score=3.861 addr=0xed7c */
void rf_reg_write_cb(void) {
  // role: rf reg write helper
  uint32_t state = 0x2cbbf9e7U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0201 class=medium score=3.844 addr=0xdff0 */
void rf_hw_timer_init(void) {
  // role: rf hw timer init helper
  uint32_t state = 0xdfc24d82U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
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

/* unit=lift_0202 class=medium score=3.827 addr=0xedd8 */
void rf_reg_write_wait(void) {
  // role: rf reg write wait helper
  uint32_t state = 0x0712e06fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    rf_reg_ack_cb();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0211 class=medium score=3.810 addr=0x141c8 */
void rf_msg_log_rate(void) {
  // role: rf message log rate helper
  uint32_t state = 0x66490e26U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_wait();
  } else {
    state ^= 0x7f4a7c15U;
  }
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0213 class=medium score=3.793 addr=0x2ea10 */
void sdio_wait_busy(void) {
  // role: sdio wait busy helper
  uint32_t state = 0xa411a997U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
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
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0219 class=medium score=3.741 addr=0x14114 */
void rf_stream_start_once(void) {
  // role: rf stream start once helper
  uint32_t state = 0xafed3abeU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    rf_cmd_send();
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

/* unit=lift_0214 class=medium score=3.741 addr=0x2b80 */
void rf_power_set(void) {
  // role: rf power set helper
  uint32_t state = 0x76b7a883U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    sub_102b00();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit updated state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0218 class=medium score=3.741 addr=0x304b0 */
void rf_timer_toggle_update(void) {
  // role: rf timer toggle update helper
  uint32_t state = 0xc7e4458fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
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
  if ((state & 2U) != 0U) {
    rf_level_compute();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit updated state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0235 class=medium score=3.679 addr=0x2a0 */
void fw_config_apply(void) {
  // role: firmware config apply helper
  uint32_t state = 0xb0cbe88dU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    patch_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0229 class=medium score=3.679 addr=0x2ea88 */
void msg_parse(void) {
  // role: message parse helper
  uint32_t state = 0xe33da892U;
  state ^= ((uint32_t)6U << 16) ^ ((uint32_t)2U << 8);
  if ((state & 2U) != 0U) {
    msg_handler_tx();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    sub_137490();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0230 class=medium score=3.679 addr=0x13814 */
void log_pool_init_e(void) {
  // role: logging pool initialization stage e helper
  uint32_t state = 0xe2d507c2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  log_system_init_mode2();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0255 class=medium score=3.679 addr=0x19fc */
void chip_feature_check(void) {
  // role: chip feature gate helper
  uint32_t state = 0x247d772eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    feature_always_on();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0226 class=medium score=3.679 addr=0x2ca8 */
void crypto_hw_enable(void) {
  // role: crypto hardware enable helper
  uint32_t state = 0xbcff72acU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
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
  // step 3: complete crypto step
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0245 class=medium score=3.679 addr=0x24e34 */
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

/* unit=lift_0227 class=medium score=3.679 addr=0x2d708 */
void fp_convert_int(void) {
  // role: fixed-point conversion helper
  uint32_t state = 0xeae66cc6U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    fp_convert_uint();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0232 class=medium score=3.679 addr=0x1115c */
void log_queue_push(void) {
  // role: logging queue push helper
  uint32_t state = 0xdf441f57U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  tx_dequeue();
  state ^= 0xD00D00D0U;
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0239 class=medium score=3.679 addr=0xc360 */
void tx_phy_config(void) {
  // role: transmit phy config helper
  uint32_t state = 0xf99afe58U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    crypto_hw_power_up();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0241 class=medium score=3.679 addr=0x8080 */
void crypto_channel_calc(void) {
  // role: crypto channel calculation helper
  uint32_t state = 0x68bd2fecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    crypto_freq_set();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: complete crypto step
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0254 class=medium score=3.679 addr=0xff34 */
void log_ptr_in_range(void) {
  // role: logging ptr in range helper
  uint32_t state = 0x83fef30fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    log_free_pool_c();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_d();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    log_pool_init_e();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: flush log updates
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0244 class=medium score=3.679 addr=0x478 */
void firmware_init(void) {
  // role: initialization leaf
  uint32_t state = 0x547c85c0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  if ((state & 1U) != 0U) {
    fw_config_apply();
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

/* unit=lift_0252 class=medium score=3.679 addr=0x6d8 */
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

/* unit=lift_0249 class=medium score=3.679 addr=0x7518 */
void crypto_hw_clear_regs(void) {
  // role: clear/reset helper
  uint32_t state = 0xf580aa98U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)3U << 8);
  if ((state & 2U) != 0U) {
    crypto_power_calc();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_state_dump();
  } else {
    state ^= 0x3c6ef372U;
  }
  if ((state & 2U) != 0U) {
    crypto_power_apply();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: complete clear path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0246 class=medium score=3.679 addr=0x4261c */
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
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_pop(void) {
  // role: container/list pop helper
  uint32_t state = 0xeac6322fU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    list_push_tail();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: complete removal
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void list_push_tail(void) {
  // role: container/list push tail helper
  uint32_t state = 0x72014dfbU;
  state ^= ((uint32_t)4U << 16) ^ ((uint32_t)3U << 8);
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
  // step 3: complete push operation
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_hw_init(void) {
  // role: logging hardware initialization helper
  uint32_t state = 0x1bbaba9eU;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)4U << 8);
  if ((state & 2U) != 0U) {
    sdio_buffer_prepare();
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
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void log_pool_init_d(void) {
  // role: logging pool initialization stage d helper
  uint32_t state = 0xd24063a4U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
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
  // step 3: finish initialization path
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
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void queue_check(void) {
  // role: queue check helper
  uint32_t state = 0x474953c1U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)4U << 8);
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
  if ((state & 2U) != 0U) {
    ipc_doorbell_handler();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort1(void) {
  // role: rf timer abort1 helper
  uint32_t state = 0x9ce2fce3U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    rf_timer_abort_common();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void rf_timer_abort2(void) {
  // role: rf timer abort2 helper
  uint32_t state = 0x9adaaaf8U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  if ((state & 2U) != 0U) {
    rf_timer_abort_common();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: commit RF state
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
  // inferred alias: shared_leaf_101a54
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
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_10ed40(void) {
  // role: rf shared dependency leaf 10ed40
  uint32_t state = 0x098a7a9aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // inferred alias: rf_abort_10ed40
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
  // inferred alias: shared_leaf_10ffc0
  if ((state & 2U) != 0U) {
    log_system_init();
  } else {
    state ^= 0x3c6ef372U;
  }
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

void sub_1140f4(void) {
  // role: log shared dependency leaf 1140f4
  uint32_t state = 0xcfbbae4aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // inferred alias: log_log_1140f4
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
  // inferred alias: rf_abort_114ee0
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
  // inferred alias: mac_mac_116d3c
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
  // inferred alias: mac_mac_11ecb0
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
  // inferred alias: mac_mac_11f5e4
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
  // inferred alias: mac_mac_120408
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
  // inferred alias: mac_mac_128db8
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
  // inferred alias: mac_mac_129e04
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
  // inferred alias: mac_mac_12ad00
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
  // step 3: return to caller
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
  // step 3: commit outbound completion
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
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

