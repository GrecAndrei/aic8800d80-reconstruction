/* task=behavioral_irq_nesting_or class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122d104 */

void irq_nesting_or(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
}
