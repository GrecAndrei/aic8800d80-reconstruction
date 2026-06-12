/* task=behavioral_ipc_doorbell_handler_n24d class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215bc8 */

void ipc_doorbell_handler_n24d(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x1f8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40328074U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40032020U);
}
