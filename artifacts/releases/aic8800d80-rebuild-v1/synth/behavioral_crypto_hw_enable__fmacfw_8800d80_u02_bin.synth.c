/* task=behavioral_crypto_hw_enable class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1202ca8 */

void crypto_hw_enable(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40344094U);
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x40U;
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x50U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
