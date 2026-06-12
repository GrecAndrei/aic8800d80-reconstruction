/* task=behavioral_irq_prio_set class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120dca4 */

void irq_prio_set(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40504080U);
    *((volatile uint32_t *)(uintptr_t)0x40504080U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505004U);
    *((volatile uint32_t *)(uintptr_t)0x40505004U) = 0x1U;
}
