/* task=behavioral_ipc_doorbell_handler_n_4da class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12154a2 */

void ipc_doorbell_handler_n_4da(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x4U) = 0xdeadc001U;
}
