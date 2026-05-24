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
void hw_config_init(void);
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
void crypto_hw_power_up(void);
void crypto_freq_set(void);
void log_printf(void);
void ke_evt_schedule(void);
void crypto_state_dump(void);
void crypto_power_calc(void);
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
  // reconstructed micro-flow: rf state check helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0144 class=medium score=3.879 addr=0x129e8 */
void rf_bus_reset(void) {
  uint32_t state = 0x1cd6aea5U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus reset helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_bus_mark();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0125 class=medium score=3.879 addr=0xe048 */
void rf_hw_timer_read(void) {
  uint32_t state = 0x91753fc7U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf hw timer read helper
  // step 1: read local state
  // callers observed: 1
  // step 2: advance timer state
  rf_level_step();
  rf_level_compute();
  // step 3: return observed value
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0083 class=medium score=3.879 addr=0x302f8 */
void rf_level_apply(void) {
  uint32_t state = 0x8ef44a7cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf level apply helper
  // step 1: prepare RF state
  // step 2: apply RF level
  sub_102a24();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0127 class=medium score=3.879 addr=0xc840 */
void sdio_dma_config(void) {
  uint32_t state = 0x5acfc8d2U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: sdio dma config helper
  // step 1: prepare SDIO state
  // callers observed: 1
  // step 2: apply firmware state
  crypto_hw_enable();
  feature_guard_sdio();
  hw_config_init();
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0128 class=medium score=3.879 addr=0x14eac */
void patch_apply(void) {
  uint32_t state = 0x6bbf288aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: patching helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: apply patch state
  fw_config_apply();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0118 class=medium score=3.879 addr=0xee40 */
void rf_reg_write_core(void) {
  uint32_t state = 0x816af6d4U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf reg write core helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0130 class=medium score=3.879 addr=0x30430 */
void rf_level_compute(void) {
  uint32_t state = 0x32db2d95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf level compute helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: compute RF level
  rf_hw_timer_read();
  rf_level_step();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0131 class=medium score=3.879 addr=0xd808 */
void sdio_transfer(void) {
  uint32_t state = 0x1eb6c054U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: sdio transfer helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: perform SDIO transfer
  log_hw_init();
  log_enqueue();
  sdio_buffer_prepare();
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0084 class=medium score=3.879 addr=0x3478 */
void phy_rf_init(void) {
  uint32_t state = 0x555f42b0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: rf phy init helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blockb();
  rf_init_blocka();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0133 class=medium score=3.879 addr=0xe2a0 */
void rf_init_blockc(void) {
  uint32_t state = 0xe668bdc8U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf init blockc helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockb();
  rf_init_blocka();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0085 class=medium score=3.879 addr=0x13350 */
void rf_stream_start(void) {
  uint32_t state = 0xc330047eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf stream start helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: start RF stream
  sub_111f08();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0086 class=medium score=3.879 addr=0x2eb18 */
void rf_mem_read(void) {
  uint32_t state = 0xba9f52ebU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf mem read helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0136 class=medium score=3.879 addr=0x13104 */
void rf_msg_handler(void) {
  uint32_t state = 0x47e35761U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf message helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0137 class=medium score=3.879 addr=0x11c1c */
void rf_bus_write2(void) {
  uint32_t state = 0x9a4dea85U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus write2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0138 class=medium score=3.879 addr=0x119fc */
void rf_bus_reset2(void) {
  uint32_t state = 0xbc0ca84dU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus reset2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_bus_mark();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0087 class=medium score=3.879 addr=0x11db8 */
void rf_bus_init(void) {
  uint32_t state = 0x9d0abc0fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_reg_write_cb();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0140 class=medium score=3.879 addr=0x2fb48 */
void rf_mem_write(void) {
  uint32_t state = 0xd2bc4021U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf mem write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0141 class=medium score=3.879 addr=0x10008 */
void log_free_dispatch(void) {
  uint32_t state = 0x2435190cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: logging free dispatcher
  // step 1: select dispatch target
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  log_free_pool_d();
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0088 class=medium score=3.879 addr=0x134b4 */
void rf_cmd_queue_next(void) {
  uint32_t state = 0xfea55400U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf cmd queue next helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: handle RF control sequence
  log_queue_push();
  log_queue_alloc();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0082 class=medium score=3.879 addr=0xef50 */
void rf_init_blocka(void) {
  uint32_t state = 0xecd14b95U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf init blocka helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blockb();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0117 class=medium score=3.879 addr=0x11efc */
void rf_bus_setup(void) {
  uint32_t state = 0xeea9976cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus setup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_reg_write_cb();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0089 class=medium score=3.879 addr=0x14748 */
void rf_fault_dump(void) {
  uint32_t state = 0xe2367dbfU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf fault dump helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0146 class=medium score=3.879 addr=0x12f70 */
void rf_cmd_wait(void) {
  uint32_t state = 0x83ac3d29U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf cmd wait helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0124 class=medium score=3.879 addr=0xfce0 */
void log_free_pool_dispatch2(void) {
  uint32_t state = 0xcd77b186U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: logging free pool dispatcher
  // step 1: select dispatch target
  // step 2: reclaim log pool resources
  log_free_pool_d();
  log_free_pool_a();
  log_free_pool_b();
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0148 class=medium score=3.879 addr=0x2f060 */
void rf_timer_toggle(void) {
  uint32_t state = 0xd55760eaU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf timer toggle helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0149 class=medium score=3.879 addr=0x133f0 */
void rf_stream_start2(void) {
  uint32_t state = 0xf43baf86U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf stream start2 helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: start RF stream
  rf_stream_start();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0113 class=medium score=3.879 addr=0x303a0 */
void rf_level_dump(void) {
  uint32_t state = 0x4671173aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf level dump helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0151 class=medium score=3.879 addr=0x13558 */
void rf_cmd_process(void) {
  uint32_t state = 0x4c7eb1baU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf cmd process helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0152 class=medium score=3.879 addr=0x2fa60 */
void rf_cmd_dispatch(void) {
  uint32_t state = 0xb0ea0c44U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf cmd dispatch helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0114 class=medium score=3.879 addr=0x11b64 */
void rf_bus_write(void) {
  uint32_t state = 0x160f630aU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf bus write helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_bus_clear();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0154 class=medium score=3.879 addr=0x13c48 */
void rf_msg_process_body(void) {
  uint32_t state = 0x70106120U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf message process body helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0115 class=medium score=3.879 addr=0x2c98c */
void message_dispatch(void) {
  uint32_t state = 0xe9f36f1cU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: message dispatch helper
  // step 1: select dispatch target
  // step 2: dispatch message payload
  buffer_pool_manage();
  // step 3: complete dispatch path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0116 class=medium score=3.879 addr=0x13010 */
void rf_cmd_send(void) {
  uint32_t state = 0x4a1f596aU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf cmd send helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0119 class=medium score=3.879 addr=0xd304 */
void sdio_status_check(void) {
  uint32_t state = 0xa5096345U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: sdio status check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check SDIO status
  feature_guard_sdio();
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0123 class=medium score=3.879 addr=0xe560 */
void rf_init_blockb(void) {
  uint32_t state = 0x0fded352U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: rf init blockb helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blocka();
  // step 3: finish initialization path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0122 class=medium score=3.879 addr=0x1597c */
void ipc_doorbell_handler(void) {
  uint32_t state = 0x840b7203U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: ipc doorbell handler
  // step 1: process inbound event state
  // callers observed: 1
  // step 2: dispatch SDIO doorbell state
  sdio_wait_busy();
  // step 3: acknowledge inbound handling
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0121 class=medium score=3.879 addr=0x2e11c */
void sdio_buffer_prepare(void) {
  uint32_t state = 0x122ba5f3U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: sdio buffer prepare helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: prepare SDIO buffer
  log_hw_init();
  log_enqueue();
  sub_1435d0();
  list_pop();
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0120 class=medium score=3.879 addr=0x11884 */
void rf_bus_mark(void) {
  uint32_t state = 0xdc422abcU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf bus mark helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0157 class=medium score=3.861 addr=0xed7c */
void rf_reg_write_cb(void) {
  uint32_t state = 0x2cbbf9e7U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf reg write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0201 class=medium score=3.844 addr=0xdff0 */
void rf_hw_timer_init(void) {
  uint32_t state = 0xdfc24d82U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf hw timer init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_timer_set();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0202 class=medium score=3.827 addr=0xedd8 */
void rf_reg_write_wait(void) {
  uint32_t state = 0x0712e06fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf reg write wait helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_reg_ack_cb();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0211 class=medium score=3.810 addr=0x141c8 */
void rf_msg_log_rate(void) {
  uint32_t state = 0x66490e26U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf message log rate helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0213 class=medium score=3.793 addr=0x2ea10 */
void sdio_wait_busy(void) {
  uint32_t state = 0xa411a997U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)4U << 8);
  // reconstructed control: sdio wait busy helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: poll SDIO busy state
  queue_check();
  tx_timeout_check();
  feature_guard_sdio();
  sdio_status_check();
  // step 3: commit SDIO state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0219 class=medium score=3.741 addr=0x14114 */
void rf_stream_start_once(void) {
  uint32_t state = 0xafed3abeU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: rf stream start once helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_send();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  rf_cmd_wait();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0214 class=medium score=3.741 addr=0x2b80 */
void rf_power_set(void) {
  uint32_t state = 0x76b7a883U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: rf power set helper
  // step 1: apply local update
  // callers observed: 1
  // step 2: apply RF power state
  sub_102b00();
  // step 3: commit updated state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0218 class=medium score=3.741 addr=0x304b0 */
void rf_timer_toggle_update(void) {
  uint32_t state = 0xc7e4458fU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: rf timer toggle update helper
  // step 1: apply local update
  // step 2: update RF timer state
  rf_hw_timer_read();
  rf_level_step();
  rf_level_compute();
  // step 3: commit updated state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0235 class=medium score=3.679 addr=0x2a0 */
void fw_config_apply(void) {
  uint32_t state = 0xb0cbe88dU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: firmware config apply helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: apply firmware state
  patch_apply();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0229 class=medium score=3.679 addr=0x2ea88 */
void msg_parse(void) {
  uint32_t state = 0xe33da892U;
  state ^= ((uint32_t)6U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: message parse helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 6
  // step 2: parse message payload
  msg_handler_tx();
  sub_137490();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0230 class=medium score=3.679 addr=0x13814 */
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

/* unit=lift_0255 class=medium score=3.679 addr=0x19fc */
void chip_feature_check(void) {
  uint32_t state = 0x247d772eU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: chip feature gate helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check feature gate
  feature_always_on();
  // step 3: return validation result
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0226 class=medium score=3.679 addr=0x2ca8 */
void crypto_hw_enable(void) {
  uint32_t state = 0xbcff72acU;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: crypto hardware enable helper
  // step 1: prepare crypto state
  // callers observed: 2
  // step 2: execute crypto sequence
  crypto_hw_disable();
  crypto_mac_core();
  // step 3: complete crypto step
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0245 class=medium score=3.679 addr=0x24e34 */
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

/* unit=lift_0227 class=medium score=3.679 addr=0x2d708 */
void fp_convert_int(void) {
  uint32_t state = 0xeae66cc6U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: fixed-point conversion helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 2
  // step 2: invoke specialized support sequence
  fp_convert_uint();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0232 class=medium score=3.679 addr=0x1115c */
void log_queue_push(void) {
  uint32_t state = 0xdf441f57U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: logging queue push helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: refill logging queue
  tx_dequeue();
  state ^= 0xD00D00D0U;
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0239 class=medium score=3.679 addr=0xc360 */
void tx_phy_config(void) {
  uint32_t state = 0xf99afe58U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: transmit phy config helper
  // step 1: prepare outbound work
  // step 2: apply firmware state
  crypto_hw_power_up();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0241 class=medium score=3.679 addr=0x8080 */
void crypto_channel_calc(void) {
  uint32_t state = 0x68bd2fecU;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: crypto channel calculation helper
  // step 1: prepare crypto state
  // step 2: compute crypto channel state
  crypto_freq_set();
  // step 3: complete crypto step
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0254 class=medium score=3.679 addr=0xff34 */
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

/* unit=lift_0244 class=medium score=3.679 addr=0x478 */
void firmware_init(void) {
  uint32_t state = 0x547c85c0U;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: initialization leaf
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  fw_config_apply();
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  ke_evt_schedule();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0252 class=medium score=3.679 addr=0x6d8 */
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

/* unit=lift_0249 class=medium score=3.679 addr=0x7518 */
void crypto_hw_clear_regs(void) {
  uint32_t state = 0xf580aa98U;
  state ^= ((uint32_t)3U << 16) ^ ((uint32_t)3U << 8);
  // reconstructed control: clear/reset helper
  // step 1: clear local state
  // callers observed: 3
  // step 2: clear crypto hardware registers
  crypto_state_dump();
  crypto_power_calc();
  crypto_power_apply();
  // step 3: complete clear path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0246 class=medium score=3.679 addr=0x4261c */
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

