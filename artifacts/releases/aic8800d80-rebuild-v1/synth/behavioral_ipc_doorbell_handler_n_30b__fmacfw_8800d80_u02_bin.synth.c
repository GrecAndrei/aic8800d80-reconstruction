/* task=behavioral_ipc_doorbell_handler_n_30b class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215670 */

void ipc_doorbell_handler_n_30b(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
}
