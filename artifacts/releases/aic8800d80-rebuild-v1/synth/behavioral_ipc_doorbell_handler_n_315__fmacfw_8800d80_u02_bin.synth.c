/* task=behavioral_ipc_doorbell_handler_n_315 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215666 */

void ipc_doorbell_handler_n_315(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
    *((volatile uint32_t *)(uintptr_t)0x40328048U) = 0x80000000U;
    *((volatile uint32_t *)(uintptr_t)0x1U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
}
