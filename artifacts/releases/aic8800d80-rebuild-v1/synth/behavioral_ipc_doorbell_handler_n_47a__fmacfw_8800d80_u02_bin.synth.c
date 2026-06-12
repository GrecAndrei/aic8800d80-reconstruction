/* task=behavioral_ipc_doorbell_handler_n_47a class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215502 */

void ipc_doorbell_handler_n_47a(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320064U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
}
