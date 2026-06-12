/* task=behavioral_crypto_hw_disable class=behavioral priority=critical score=25.000 */
/* image=lmacfw_rf_8800d80_u02_bin addr=0x1202b40 */

void crypto_hw_disable(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40344094U);
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x20U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x40344094U) = 0x30U;
}
