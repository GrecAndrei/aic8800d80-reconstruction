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
void hw_config_init(void);
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
void log_printf(void);
void sdio_transfer(void);
void sub_137490(void);
void idle_processing(void);
void sub_114578(void);
void sub_115470(void);
void sub_12d050(void);
void ipc_doorbell_handler(void);
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
  // reconstructed control: rf level apply helper
  // step 1: prepare RF state
  // step 2: apply RF level
  sub_102a24();
  // step 3: commit RF state
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0104 class=medium score=3.879 addr=0x1324c */
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

/* unit=lift_0155 class=medium score=3.879 addr=0xc698 */
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

/* unit=lift_0153 class=medium score=3.879 addr=0x119c0 */
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

/* unit=lift_0102 class=medium score=3.879 addr=0x11d58 */
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

/* unit=lift_0112 class=medium score=3.879 addr=0x2ed40 */
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

/* unit=lift_0110 class=medium score=3.879 addr=0x2fd64 */
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

/* unit=lift_0145 class=medium score=3.879 addr=0x11a78 */
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

/* unit=lift_0143 class=medium score=3.879 addr=0xfe60 */
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

/* unit=lift_0142 class=medium score=3.879 addr=0x154e8 */
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

/* unit=lift_0156 class=medium score=3.879 addr=0x12f60 */
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

/* unit=lift_0135 class=medium score=3.879 addr=0xeda8 */
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

/* unit=lift_0134 class=medium score=3.879 addr=0x12030 */
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

/* unit=lift_0132 class=medium score=3.879 addr=0x2e344 */
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

/* unit=lift_0103 class=medium score=3.879 addr=0x116e0 */
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

/* unit=lift_0108 class=medium score=3.879 addr=0x11858 */
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

/* unit=lift_0129 class=medium score=3.879 addr=0x12844 */
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

/* unit=lift_0109 class=medium score=3.879 addr=0xfb38 */
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

/* unit=lift_0107 class=medium score=3.879 addr=0x2cbb4 */
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

/* unit=lift_0111 class=medium score=3.879 addr=0x2fc7c */
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

/* unit=lift_0106 class=medium score=3.879 addr=0x12e6c */
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

/* unit=lift_0105 class=medium score=3.879 addr=0x32d0 */
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

/* unit=lift_0200 class=medium score=3.844 addr=0xde48 */
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

/* unit=lift_0207 class=medium score=3.810 addr=0x3064c */
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

/* unit=lift_0208 class=medium score=3.810 addr=0x12dcc */
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

/* unit=lift_0209 class=medium score=3.810 addr=0x131ac */
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

/* unit=lift_0210 class=medium score=3.810 addr=0xebd4 */
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

/* unit=lift_0203 class=medium score=3.810 addr=0xe0f8 */
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

/* unit=lift_0220 class=medium score=3.741 addr=0xe3b8 */
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

/* unit=lift_0221 class=medium score=3.741 addr=0x29f8 */
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

/* unit=lift_0215 class=medium score=3.741 addr=0xec30 */
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

/* unit=lift_0223 class=medium score=3.741 addr=0x13aa4 */
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

/* unit=lift_0217 class=medium score=3.741 addr=0xd15c */
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

/* unit=lift_0236 class=medium score=3.679 addr=0x7ed8 */
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

/* unit=lift_0234 class=medium score=3.679 addr=0x2b64 */
void crypto_hw_disable(void) {
  uint32_t state = 0x9dfc4011U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)2U << 8);
  // reconstructed control: crypto hardware disable helper
  // step 1: prepare crypto state
  // callers observed: 2
  // step 2: execute crypto sequence
  crypto_hw_enable();
  crypto_mac_core();
  // step 3: complete crypto step
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0253 class=medium score=3.679 addr=0x39c4 */
void crypto_hw_power_up(void) {
  uint32_t state = 0x97cd0bddU;
  state ^= ((uint32_t)1U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: crypto hardware power up helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  crypto_power_apply();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0237 class=medium score=3.679 addr=0x10fb8 */
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

/* unit=lift_0238 class=medium score=3.679 addr=0x426b8 */
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

/* unit=lift_0240 class=medium score=3.679 addr=0x2c964 */
void event_queue_push(void) {
  uint32_t state = 0x96540698U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: event queue push
  // step 1: prepare outbound work
  // step 2: refill logging queue
  buffer_pool_manage();
  // step 3: commit outbound completion
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0231 class=medium score=3.679 addr=0x42b44 */
void math_helper_big(void) {
  uint32_t state = 0x51fb6109U;
  state ^= ((uint32_t)2U << 16) ^ ((uint32_t)1U << 8);
  // reconstructed control: numeric aggregation helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 2
  // step 2: compute numeric value
  sub_142f2c();
  // step 3: finalize state / completion path
  state ^= 0xC3C3C3C3U;
  (void)state;
}

/* unit=lift_0256 class=medium score=3.679 addr=0x427d8 */
void math_helper_big2(void) {
  uint32_t state = 0x62877966U;
  state ^= ((uint32_t)0U << 16) ^ ((uint32_t)0U << 8);
  // reconstructed micro-flow: numeric aggregation leaf
  // step 1: decode local context
  // step 2: execute inferred helper chain
  state = (state << 5) ^ (state >> 2) ^ 0x9e3779b9U;
  math_round();
  state ^= 0xA5A5A5A5U;
  (void)state;
}

/* unit=lift_0242 class=medium score=3.679 addr=0x2b00 */
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

/* unit=lift_0243 class=medium score=3.679 addr=0xfd8c */
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

