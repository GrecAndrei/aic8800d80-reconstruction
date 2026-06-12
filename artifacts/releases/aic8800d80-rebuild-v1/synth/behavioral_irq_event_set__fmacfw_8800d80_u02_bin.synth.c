/* task=behavioral_irq_event_set class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120d3ac */

void irq_event_set(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40506004U);
    *((volatile uint32_t *)(uintptr_t)0x40506004U) = 0x400000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
