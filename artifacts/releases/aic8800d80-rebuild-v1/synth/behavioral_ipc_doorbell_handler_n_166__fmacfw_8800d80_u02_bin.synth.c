/* task=behavioral_ipc_doorbell_handler_n_166 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215816 */

void ipc_doorbell_handler_n_166(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40320400U);
    *((volatile uint32_t *)(uintptr_t)0x40320400U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320400U);
    *((volatile uint32_t *)(uintptr_t)0x40320400U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40501010U);
}
