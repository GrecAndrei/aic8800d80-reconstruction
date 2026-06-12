/* task=behavioral_ipc_doorbell_handler_n22 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x121599e */

void ipc_doorbell_handler_n22(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40328074U);
    *((volatile uint32_t *)(uintptr_t)0x40328074U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4032806cU);
}
