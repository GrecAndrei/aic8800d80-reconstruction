/* Auto-generated per-image composed reconstruction */
/* image: lmacfw_rf_8800d80_u02.bin */

#include <stdint.h>

/* unit=lift_0091 class=medium score=3.879 addr=0xcbe0 */
void sdio_dma_config(void) {
  // reconstructed control: sdio dma config helper
  // step 1: prepare SDIO state
  // callers observed: 1
  // step 2: apply firmware state
  chip_variant_detect();
  crypto_hw_enable();
  crypto_hw_power_up();
  // step 3: commit SDIO state
}

/* unit=lift_0098 class=medium score=3.879 addr=0xfbd0 */
void log_free_pool_dispatch2(void) {
  // reconstructed control: logging free pool dispatcher
  // step 1: select dispatch target
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  // step 3: complete dispatch path
}

/* unit=lift_0147 class=medium score=3.879 addr=0x11804 */
void rf_bus_setup(void) {
  // reconstructed micro-flow: rf bus setup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_reg_write_cb();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0150 class=medium score=3.879 addr=0x21f44 */
void rf_cmd_dispatch(void) {
  // reconstructed micro-flow: rf cmd dispatch helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0101 class=medium score=3.879 addr=0x122f0 */
void rf_bus_reset(void) {
  // reconstructed micro-flow: rf bus reset helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_bus_mark();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0100 class=medium score=3.879 addr=0x2202c */
void rf_mem_write(void) {
  // reconstructed micro-flow: rf mem write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0099 class=medium score=3.879 addr=0x1146c */
void rf_bus_write(void) {
  // reconstructed control: rf bus write helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_bus_clear();
  // step 3: commit RF state
}

/* unit=lift_0094 class=medium score=3.879 addr=0x12918 */
void rf_cmd_send(void) {
  // reconstructed micro-flow: rf cmd send helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0097 class=medium score=3.879 addr=0x11304 */
void rf_bus_reset2(void) {
  // reconstructed micro-flow: rf bus reset2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_bus_mark();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0096 class=medium score=3.879 addr=0x1118c */
void rf_bus_mark(void) {
  // reconstructed micro-flow: rf bus mark helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0095 class=medium score=3.879 addr=0x1ebb4 */
void sdio_buffer_prepare(void) {
  // reconstructed control: sdio buffer prepare helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: prepare SDIO buffer
  log_hw_init();
  sub_1435d0();
  log_enqueue();
  list_pop();
  // step 3: commit SDIO state
}

/* unit=lift_0093 class=medium score=3.879 addr=0x11524 */
void rf_bus_write2(void) {
  // reconstructed micro-flow: rf bus write2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0090 class=medium score=3.879 addr=0x1f594 */
void rf_mem_read(void) {
  // reconstructed micro-flow: rf mem read helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0092 class=medium score=3.879 addr=0x26dd8 */
void rf_level_apply(void) {
  // reconstructed control: rf level apply helper
  // step 1: prepare RF state
  // step 2: apply RF level
  sub_102a24();
  // step 3: commit RF state
}

/* unit=lift_0199 class=medium score=3.844 addr=0xde98 */
void rf_hw_timer_init(void) {
  // reconstructed micro-flow: rf hw timer init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0206 class=medium score=3.810 addr=0xefb4 */
void rf_reg_write_cb(void) {
  // reconstructed micro-flow: rf reg write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0204 class=medium score=3.810 addr=0x12878 */
void rf_cmd_wait(void) {
  // reconstructed micro-flow: rf cmd wait helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  // step 3: complete local state transition
}

/* unit=lift_0205 class=medium score=3.810 addr=0x26f10 */
void rf_level_compute(void) {
  // reconstructed control: rf level compute helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: compute RF level
  rf_level_step();
  rf_hw_timer_read();
  // step 3: commit RF state
}

/* unit=lift_0212 class=medium score=3.810 addr=0xe4d8 */
void rf_init_blockc(void) {
  // reconstructed control: rf init blockc helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blocka();
  rf_init_blockb();
  // step 3: finish initialization path
}

/* unit=lift_0224 class=medium score=3.741 addr=0xf010 */
void rf_reg_write_wait(void) {
  // reconstructed control: rf reg write wait helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_reg_ack_cb();
  // step 3: commit RF state
}

/* unit=lift_0222 class=medium score=3.741 addr=0xe798 */
void rf_init_blockb(void) {
  // reconstructed control: rf init blockb helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blocka();
  // step 3: finish initialization path
}

/* unit=lift_0216 class=medium score=3.741 addr=0x29dc */
void rf_power_set(void) {
  // reconstructed control: rf power set helper
  // step 1: apply local update
  // callers observed: 1
  // step 2: apply RF power state
  sub_102b00();
  // step 3: commit updated state
}

/* unit=lift_0250 class=medium score=3.679 addr=0x3334 */
void clock_calc(void) {
  // reconstructed control: clock calculation helper
  // step 1: load/update local state inferred from callers and edges
  // step 2: invoke specialized support sequence
  feature_guard_sdio();
  firmware_init();
  fw_config_apply();
  log_list_init();
  // step 3: finalize state / completion path
}

/* unit=lift_0251 class=medium score=3.679 addr=0x2b40 */
void crypto_hw_disable(void) {
  // reconstructed control: crypto hardware disable helper
  // step 1: prepare crypto state
  // callers observed: 2
  // step 2: execute crypto sequence
  crypto_hw_enable();
  crypto_mac_core();
  // step 3: complete crypto step
}

/* unit=lift_0248 class=medium score=3.679 addr=0x202 */
void memset_impl(void) {
  // reconstructed micro-flow: memset impl
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_round();
  // step 3: complete local state transition
}

/* unit=lift_0233 class=medium score=3.679 addr=0x6f08 */
void crypto_hw_clear_regs(void) {
  // reconstructed control: clear/reset helper
  // step 1: clear local state
  // callers observed: 3
  // step 2: clear crypto hardware registers
  crypto_state_dump();
  crypto_power_calc();
  crypto_power_apply();
  // step 3: complete clear path
}

/* unit=lift_0247 class=medium score=3.679 addr=0x3da8 */
void crypto_iq_calculate(void) {
  // reconstructed micro-flow: crypto IQ calculation helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  clock_calc();
  // step 3: complete local state transition
}

/* unit=lift_0228 class=medium score=3.679 addr=0x3a00 */
void crypto_table_init(void) {
  // reconstructed micro-flow: crypto table init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  crypto_iq_calculate();
  // step 3: complete local state transition
}

/* unit=lift_0225 class=medium score=3.679 addr=0x948 */
void crypto_key_load(void) {
  // reconstructed control: crypto key load helper
  // step 1: prepare crypto state
  // step 2: execute crypto sequence
  crypto_hw_write32();
  // step 3: complete crypto step
}

/* shared dependency stubs */

void feature_guard_sdio(void) {
  // reconstructed control: sdio feature guard helper
  // step 1: prepare SDIO state
  // callers observed: 5
  // step 2: check feature gate
  sdio_transfer();
  // step 3: commit SDIO state
}

void list_pop(void) {
  // reconstructed control: container/list pop helper
  // step 1: remove from collection
  // callers observed: 1
  // step 2: pop list entry
  list_push_tail();
  // step 3: complete removal
}

void list_push_tail(void) {
  // reconstructed control: container/list push tail helper
  // step 1: push into collection
  // callers observed: 4
  // step 2: append list entry
  log_queue_push();
  sub_137490();
  list_pop();
  // step 3: complete push operation
}

void log_hw_init(void) {
  // reconstructed control: logging hardware initialization helper
  // step 1: initialize local state
  // callers observed: 3
  // step 2: initialize logging state
  sdio_buffer_prepare();
  log_enqueue();
  sub_1435d0();
  list_pop();
  // step 3: finish initialization path
}

void log_pool_init_d(void) {
  // reconstructed control: logging pool initialization stage d helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_pool_init_e();
  sub_1140f4();
  // step 3: finish initialization path
}

void main_loop(void) {
  // reconstructed control: main loop driver
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: execute likely callee chain
  idle_processing();
  sub_114578();
  sub_115470();
  sub_12d050();
  // step 3: finalize state / completion path
}

void queue_check(void) {
  // reconstructed control: queue check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check queue state
  sdio_wait_busy();
  feature_guard_sdio();
  sdio_status_check();
  state_flag_check();
  // step 3: return validation result
}

void rf_timer_abort1(void) {
  // reconstructed control: rf timer abort1 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
}

void rf_timer_abort2(void) {
  // reconstructed control: rf timer abort2 helper
  // step 1: prepare RF state
  // step 2: update RF timer state
  rf_timer_abort_common();
  // step 3: commit RF state
}

void state_flag_check(void) {
  // reconstructed micro-flow: state flag check helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

void sub_101a54(void) {
  // inferred alias: shared_leaf_101a54
  // reconstructed control: shared dependency leaf 101a54
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  msg_parse_short();
  sub_1320bc();
  // step 3: finalize state / completion path
}

void sub_10ed40(void) {
  // inferred alias: rf_abort_10ed40
  // reconstructed micro-flow: rf shared dependency leaf 10ed40
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

void sub_10ffc0(void) {
  // inferred alias: shared_leaf_10ffc0
  // reconstructed control: shared dependency leaf 10ffc0
  // step 1: load/update local state inferred from callers and edges
  // step 2: call shared support leaves
  log_system_init();
  // step 3: finalize state / completion path
}

void sub_1140f4(void) {
  // inferred alias: log_log_1140f4
  // reconstructed micro-flow: log shared dependency leaf 1140f4
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  log_enqueue();
  // step 3: complete local state transition
}

void sub_114ee0(void) {
  // inferred alias: rf_abort_114ee0
  // reconstructed micro-flow: rf shared dependency leaf 114ee0
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

void sub_116d3c(void) {
  // inferred alias: mac_mac_116d3c
  // reconstructed micro-flow: mac subsystem leaf 116d3c
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

void sub_11ecb0(void) {
  // inferred alias: mac_mac_11ecb0
  // reconstructed micro-flow: mac subsystem leaf 11ecb0
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_12ad00();
  // step 3: complete local state transition
}

void sub_11f5e4(void) {
  // inferred alias: mac_mac_11f5e4
  // reconstructed micro-flow: mac subsystem leaf 11f5e4
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_11ecb0();
  // step 3: complete local state transition
}

void sub_120408(void) {
  // inferred alias: mac_mac_120408
  // reconstructed micro-flow: mac subsystem leaf 120408
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_11f5e4();
  // step 3: complete local state transition
}

void sub_128db8(void) {
  // inferred alias: mac_mac_128db8
  // reconstructed micro-flow: mac subsystem leaf 128db8
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_129e04();
  // step 3: complete local state transition
}

void sub_129e04(void) {
  // inferred alias: mac_mac_129e04
  // reconstructed micro-flow: mac subsystem leaf 129e04
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_116d3c();
  // step 3: complete local state transition
}

void sub_12ad00(void) {
  // inferred alias: mac_mac_12ad00
  // reconstructed micro-flow: mac subsystem leaf 12ad00
  // callers observed: 2
  // step 1: decode local context
  // step 2: execute inferred helper chain
  sub_128db8();
  // step 3: complete local state transition
}

void thunk(void) {
  // reconstructed control: relay call helper
  // step 1: relay incoming call
  // callers observed: 2
  // step 2: forward relay call
  buffer_pool_get();
  // step 3: return to caller
}

void tx_submit(void) {
  // reconstructed control: transmit submit helper
  // step 1: prepare outbound work
  // callers observed: 1
  // step 2: submit transmit work
  list_push_tail();
  log_queue_push();
  rf_cmd_queue_next();
  // step 3: commit outbound completion
}

void tx_timeout_check(void) {
  // reconstructed control: transmit timeout check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check transmit timeout
  error_handler();
  // step 3: return validation result
}

