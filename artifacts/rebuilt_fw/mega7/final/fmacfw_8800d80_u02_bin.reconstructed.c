/* Auto-generated per-image composed reconstruction */
/* image: fmacfw_8800d80_u02.bin */

#include <stdint.h>

/* unit=lift_0126 class=medium score=3.879 addr=0x121d4 */
void rf_state_check(void) {
  // reconstructed micro-flow: rf state check helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0144 class=medium score=3.879 addr=0x129e8 */
void rf_bus_reset(void) {
  // reconstructed micro-flow: rf bus reset helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_bus_mark();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0125 class=medium score=3.879 addr=0xe048 */
void rf_hw_timer_read(void) {
  // reconstructed control: rf hw timer read helper
  // step 1: read local state
  // callers observed: 1
  // step 2: advance timer state
  rf_level_step();
  rf_level_compute();
  // step 3: return observed value
}

/* unit=lift_0083 class=medium score=3.879 addr=0x302f8 */
void rf_level_apply(void) {
  // reconstructed control: rf level apply helper
  // step 1: prepare RF state
  // step 2: apply RF level
  sub_102a24();
  // step 3: commit RF state
}

/* unit=lift_0127 class=medium score=3.879 addr=0xc840 */
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

/* unit=lift_0128 class=medium score=3.879 addr=0x14eac */
void patch_apply(void) {
  // reconstructed control: patching helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: apply patch state
  fw_config_apply();
  // step 3: finalize state / completion path
}

/* unit=lift_0118 class=medium score=3.879 addr=0xee40 */
void rf_reg_write_core(void) {
  // reconstructed micro-flow: rf reg write core helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0130 class=medium score=3.879 addr=0x30430 */
void rf_level_compute(void) {
  // reconstructed control: rf level compute helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: compute RF level
  rf_level_step();
  rf_hw_timer_read();
  // step 3: commit RF state
}

/* unit=lift_0131 class=medium score=3.879 addr=0xd808 */
void sdio_transfer(void) {
  // reconstructed control: sdio transfer helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: perform SDIO transfer
  log_hw_init();
  log_enqueue();
  sdio_buffer_prepare();
  // step 3: commit SDIO state
}

/* unit=lift_0084 class=medium score=3.879 addr=0x3478 */
void phy_rf_init(void) {
  // reconstructed control: rf phy init helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blockb();
  rf_init_blocka();
  // step 3: finish initialization path
}

/* unit=lift_0133 class=medium score=3.879 addr=0xe2a0 */
void rf_init_blockc(void) {
  // reconstructed control: rf init blockc helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blocka();
  rf_init_blockb();
  // step 3: finish initialization path
}

/* unit=lift_0085 class=medium score=3.879 addr=0x13350 */
void rf_stream_start(void) {
  // reconstructed control: rf stream start helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: start RF stream
  sub_111f08();
  // step 3: commit RF state
}

/* unit=lift_0086 class=medium score=3.879 addr=0x2eb18 */
void rf_mem_read(void) {
  // reconstructed micro-flow: rf mem read helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0136 class=medium score=3.879 addr=0x13104 */
void rf_msg_handler(void) {
  // reconstructed micro-flow: rf message helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0137 class=medium score=3.879 addr=0x11c1c */
void rf_bus_write2(void) {
  // reconstructed micro-flow: rf bus write2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0138 class=medium score=3.879 addr=0x119fc */
void rf_bus_reset2(void) {
  // reconstructed micro-flow: rf bus reset2 helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_bus_mark();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0087 class=medium score=3.879 addr=0x11db8 */
void rf_bus_init(void) {
  // reconstructed micro-flow: rf bus init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_reg_write_cb();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0140 class=medium score=3.879 addr=0x2fb48 */
void rf_mem_write(void) {
  // reconstructed micro-flow: rf mem write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0141 class=medium score=3.879 addr=0x10008 */
void log_free_dispatch(void) {
  // reconstructed control: logging free dispatcher
  // step 1: select dispatch target
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  log_free_pool_d();
  // step 3: complete dispatch path
}

/* unit=lift_0088 class=medium score=3.879 addr=0x134b4 */
void rf_cmd_queue_next(void) {
  // reconstructed control: rf cmd queue next helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: handle RF control sequence
  log_queue_push();
  log_queue_alloc();
  // step 3: commit outbound completion
}

/* unit=lift_0082 class=medium score=3.879 addr=0xef50 */
void rf_init_blocka(void) {
  // reconstructed control: rf init blocka helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blockb();
  // step 3: finish initialization path
}

/* unit=lift_0117 class=medium score=3.879 addr=0x11efc */
void rf_bus_setup(void) {
  // reconstructed micro-flow: rf bus setup helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_reg_write_cb();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0089 class=medium score=3.879 addr=0x14748 */
void rf_fault_dump(void) {
  // reconstructed micro-flow: rf fault dump helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0146 class=medium score=3.879 addr=0x12f70 */
void rf_cmd_wait(void) {
  // reconstructed micro-flow: rf cmd wait helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  // step 3: complete local state transition
}

/* unit=lift_0124 class=medium score=3.879 addr=0xfce0 */
void log_free_pool_dispatch2(void) {
  // reconstructed control: logging free pool dispatcher
  // step 1: select dispatch target
  // step 2: reclaim log pool resources
  log_free_pool_a();
  log_free_pool_b();
  log_free_pool_c();
  // step 3: complete dispatch path
}

/* unit=lift_0148 class=medium score=3.879 addr=0x2f060 */
void rf_timer_toggle(void) {
  // reconstructed micro-flow: rf timer toggle helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0149 class=medium score=3.879 addr=0x133f0 */
void rf_stream_start2(void) {
  // reconstructed control: rf stream start2 helper
  // step 1: prepare RF state
  // callers observed: 1
  // step 2: start RF stream
  rf_stream_start();
  // step 3: commit RF state
}

/* unit=lift_0113 class=medium score=3.879 addr=0x303a0 */
void rf_level_dump(void) {
  // reconstructed micro-flow: rf level dump helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0151 class=medium score=3.879 addr=0x13558 */
void rf_cmd_process(void) {
  // reconstructed micro-flow: rf cmd process helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0152 class=medium score=3.879 addr=0x2fa60 */
void rf_cmd_dispatch(void) {
  // reconstructed micro-flow: rf cmd dispatch helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0114 class=medium score=3.879 addr=0x11b64 */
void rf_bus_write(void) {
  // reconstructed control: rf bus write helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_bus_clear();
  // step 3: commit RF state
}

/* unit=lift_0154 class=medium score=3.879 addr=0x13c48 */
void rf_msg_process_body(void) {
  // reconstructed micro-flow: rf message process body helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0115 class=medium score=3.879 addr=0x2c98c */
void message_dispatch(void) {
  // reconstructed control: message dispatch helper
  // step 1: select dispatch target
  // step 2: dispatch message payload
  buffer_pool_manage();
  // step 3: complete dispatch path
}

/* unit=lift_0116 class=medium score=3.879 addr=0x13010 */
void rf_cmd_send(void) {
  // reconstructed micro-flow: rf cmd send helper
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0119 class=medium score=3.879 addr=0xd304 */
void sdio_status_check(void) {
  // reconstructed control: sdio status check helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check SDIO status
  feature_guard_sdio();
  // step 3: return validation result
}

/* unit=lift_0123 class=medium score=3.879 addr=0xe560 */
void rf_init_blockb(void) {
  // reconstructed control: rf init blockb helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize RF state
  rf_init_blockc();
  rf_init_blocka();
  // step 3: finish initialization path
}

/* unit=lift_0122 class=medium score=3.879 addr=0x1597c */
void ipc_doorbell_handler(void) {
  // reconstructed control: ipc doorbell handler
  // step 1: process inbound event state
  // callers observed: 1
  // step 2: dispatch SDIO doorbell state
  sdio_wait_busy();
  // step 3: acknowledge inbound handling
}

/* unit=lift_0121 class=medium score=3.879 addr=0x2e11c */
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

/* unit=lift_0120 class=medium score=3.879 addr=0x11884 */
void rf_bus_mark(void) {
  // reconstructed micro-flow: rf bus mark helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0157 class=medium score=3.861 addr=0xed7c */
void rf_reg_write_cb(void) {
  // reconstructed micro-flow: rf reg write helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0201 class=medium score=3.844 addr=0xdff0 */
void rf_hw_timer_init(void) {
  // reconstructed micro-flow: rf hw timer init helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_timer_set();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0202 class=medium score=3.827 addr=0xedd8 */
void rf_reg_write_wait(void) {
  // reconstructed control: rf reg write wait helper
  // step 1: prepare RF state
  // step 2: write RF register or memory
  rf_reg_ack_cb();
  // step 3: commit RF state
}

/* unit=lift_0211 class=medium score=3.810 addr=0x141c8 */
void rf_msg_log_rate(void) {
  // reconstructed micro-flow: rf message log rate helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0213 class=medium score=3.793 addr=0x2ea10 */
void sdio_wait_busy(void) {
  // reconstructed control: sdio wait busy helper
  // step 1: prepare SDIO state
  // callers observed: 2
  // step 2: poll SDIO busy state
  queue_check();
  tx_timeout_check();
  feature_guard_sdio();
  sdio_status_check();
  // step 3: commit SDIO state
}

/* unit=lift_0219 class=medium score=3.741 addr=0x14114 */
void rf_stream_start_once(void) {
  // reconstructed micro-flow: rf stream start once helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  rf_cmd_send();
  rf_cmd_wait();
  // step 3: complete local state transition
}

/* unit=lift_0214 class=medium score=3.741 addr=0x2b80 */
void rf_power_set(void) {
  // reconstructed control: rf power set helper
  // step 1: apply local update
  // callers observed: 1
  // step 2: apply RF power state
  sub_102b00();
  // step 3: commit updated state
}

/* unit=lift_0218 class=medium score=3.741 addr=0x304b0 */
void rf_timer_toggle_update(void) {
  // reconstructed control: rf timer toggle update helper
  // step 1: apply local update
  // step 2: update RF timer state
  rf_hw_timer_read();
  rf_level_step();
  rf_level_compute();
  // step 3: commit updated state
}

/* unit=lift_0235 class=medium score=3.679 addr=0x2a0 */
void fw_config_apply(void) {
  // reconstructed control: firmware config apply helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 1
  // step 2: apply firmware state
  patch_apply();
  // step 3: finalize state / completion path
}

/* unit=lift_0229 class=medium score=3.679 addr=0x2ea88 */
void msg_parse(void) {
  // reconstructed control: message parse helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 6
  // step 2: parse message payload
  msg_handler_tx();
  sub_137490();
  // step 3: finalize state / completion path
}

/* unit=lift_0230 class=medium score=3.679 addr=0x13814 */
void log_pool_init_e(void) {
  // reconstructed control: logging pool initialization stage e helper
  // step 1: initialize local state
  // callers observed: 1
  // step 2: initialize logging state
  log_system_init_mode2();
  // step 3: finish initialization path
}

/* unit=lift_0255 class=medium score=3.679 addr=0x19fc */
void chip_feature_check(void) {
  // reconstructed control: chip feature gate helper
  // step 1: evaluate current state
  // callers observed: 1
  // step 2: check feature gate
  feature_always_on();
  // step 3: return validation result
}

/* unit=lift_0226 class=medium score=3.679 addr=0x2ca8 */
void crypto_hw_enable(void) {
  // reconstructed control: crypto hardware enable helper
  // step 1: prepare crypto state
  // callers observed: 2
  // step 2: execute crypto sequence
  crypto_hw_disable();
  crypto_mac_core();
  // step 3: complete crypto step
}

/* unit=lift_0245 class=medium score=3.679 addr=0x24e34 */
void timestamp_remove(void) {
  // reconstructed micro-flow: timestamp list helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  timestamp_list_contains();
  // step 3: complete local state transition
}

/* unit=lift_0227 class=medium score=3.679 addr=0x2d708 */
void fp_convert_int(void) {
  // reconstructed control: fixed-point conversion helper
  // step 1: load/update local state inferred from callers and edges
  // callers observed: 2
  // step 2: invoke specialized support sequence
  fp_convert_uint();
  // step 3: finalize state / completion path
}

/* unit=lift_0232 class=medium score=3.679 addr=0x1115c */
void log_queue_push(void) {
  // reconstructed control: logging queue push helper
  // step 1: prepare outbound work
  // callers observed: 2
  // step 2: refill logging queue
  tx_dequeue();
  // step 3: commit outbound completion
}

/* unit=lift_0239 class=medium score=3.679 addr=0xc360 */
void tx_phy_config(void) {
  // reconstructed control: transmit phy config helper
  // step 1: prepare outbound work
  // step 2: apply firmware state
  crypto_hw_power_up();
  // step 3: commit outbound completion
}

/* unit=lift_0241 class=medium score=3.679 addr=0x8080 */
void crypto_channel_calc(void) {
  // reconstructed control: crypto channel calculation helper
  // step 1: prepare crypto state
  // step 2: compute crypto channel state
  crypto_freq_set();
  // step 3: complete crypto step
}

/* unit=lift_0254 class=medium score=3.679 addr=0xff34 */
void log_ptr_in_range(void) {
  // reconstructed control: logging ptr in range helper
  // step 1: prepare logging context
  // step 2: validate log pointer range
  log_free_pool_a();
  log_pool_init_d();
  rf_power_set();
  // step 3: flush log updates
}

/* unit=lift_0244 class=medium score=3.679 addr=0x478 */
void firmware_init(void) {
  // reconstructed micro-flow: initialization leaf
  // callers observed: 1
  // step 1: decode local context
  // step 2: execute inferred helper chain
  fw_config_apply();
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0252 class=medium score=3.679 addr=0x6d8 */
void panic_loop(void) {
  // reconstructed micro-flow: panic/abort helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  ke_evt_schedule();
  // step 3: complete local state transition
}

/* unit=lift_0249 class=medium score=3.679 addr=0x7518 */
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

/* unit=lift_0246 class=medium score=3.679 addr=0x4261c */
void math_round(void) {
  // reconstructed micro-flow: math round helper
  // step 1: decode local context
  // step 2: execute inferred helper chain
  math_helper_int();
  // step 3: complete local state transition
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

