/* task=behavioral_ipc_doorbell_handler_n_153 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215828 */

void ipc_doorbell_handler_n_153(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x10U);
}
