/* task=behavioral_irq_prio_set2 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120dcec */

void irq_prio_set2(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x1U;
}
