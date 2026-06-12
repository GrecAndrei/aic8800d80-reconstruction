/* task=behavioral_ipc_doorbell_handler_n_184 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12157f8 */

void ipc_doorbell_handler_n_184(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x16439cU;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x1677c4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x121580bU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
}
