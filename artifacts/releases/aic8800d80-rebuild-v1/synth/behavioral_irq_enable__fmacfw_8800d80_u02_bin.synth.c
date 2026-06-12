/* task=behavioral_irq_enable class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120dd00 */

void irq_enable(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40505000U);
    *((volatile uint32_t *)(uintptr_t)0x40505000U) = 0x1U;
}
