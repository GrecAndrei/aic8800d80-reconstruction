/* task=behavioral_ipc_doorbell_handler_n_157 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215824 */

void ipc_doorbell_handler_n_157(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0x10U);
}
