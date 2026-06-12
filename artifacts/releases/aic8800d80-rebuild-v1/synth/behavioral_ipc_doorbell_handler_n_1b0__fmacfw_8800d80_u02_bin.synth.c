/* task=behavioral_ipc_doorbell_handler_n_1b0 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12157cc */

void ipc_doorbell_handler_n_1b0(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    *((volatile uint32_t *)(uintptr_t)0x2007ff00U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff04U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x1922d4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922d4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922d8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922dcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922e0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x1922dcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922e0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
}
