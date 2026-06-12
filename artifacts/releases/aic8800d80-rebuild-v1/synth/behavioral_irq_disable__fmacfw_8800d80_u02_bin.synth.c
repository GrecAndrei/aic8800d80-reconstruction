/* task=behavioral_irq_disable class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120dd14 */

void irq_disable(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40505000U);
    *((volatile uint32_t *)(uintptr_t)0x40505000U) = 0x0U;
}
