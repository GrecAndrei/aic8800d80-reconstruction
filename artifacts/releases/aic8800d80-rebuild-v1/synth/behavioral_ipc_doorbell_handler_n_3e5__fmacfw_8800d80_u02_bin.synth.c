/* task=behavioral_ipc_doorbell_handler_n_3e5 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215596 */

void ipc_doorbell_handler_n_3e5(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x1675b0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x12151c9U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x2007fef4U;
    *((volatile uint32_t *)(uintptr_t)0x2007febcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x120dc37U;
}
