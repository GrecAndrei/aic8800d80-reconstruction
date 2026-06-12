/* task=behavioral_ipc_doorbell_handler_n_1ad class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12157ce */

void ipc_doorbell_handler_n_1ad(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x1922d4U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922d4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922d8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922dcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922e0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    *((volatile uint32_t *)(uintptr_t)0x1922dcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1922e0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
