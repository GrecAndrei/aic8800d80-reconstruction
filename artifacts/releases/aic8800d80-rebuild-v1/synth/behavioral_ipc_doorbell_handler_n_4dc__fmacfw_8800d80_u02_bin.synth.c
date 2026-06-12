/* task=behavioral_ipc_doorbell_handler_n_4dc class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12154a0 */

void ipc_doorbell_handler_n_4dc(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x4U) = 0xdeadc001U;
}
