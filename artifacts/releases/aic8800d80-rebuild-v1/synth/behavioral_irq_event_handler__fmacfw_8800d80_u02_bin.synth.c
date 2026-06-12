/* task=behavioral_irq_event_handler class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120de38 */

void irq_event_handler(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x166254U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x120de47U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x2007fee4U;
    *((volatile uint32_t *)(uintptr_t)0x2007feacU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007febcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x120dc37U;
}
