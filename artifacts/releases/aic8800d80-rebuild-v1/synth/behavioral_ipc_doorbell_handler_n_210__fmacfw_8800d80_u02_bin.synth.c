/* task=behavioral_ipc_doorbell_handler_n_210 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x121576c */

void ipc_doorbell_handler_n_210(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1bU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1bU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x88U) = 0x0U;
}
