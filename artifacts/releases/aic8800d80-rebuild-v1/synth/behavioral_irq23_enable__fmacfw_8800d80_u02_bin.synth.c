/* task=behavioral_irq23_enable class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120d628 */

void irq23_enable(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x94U) = 0x12d5adU;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x200000U;
}
