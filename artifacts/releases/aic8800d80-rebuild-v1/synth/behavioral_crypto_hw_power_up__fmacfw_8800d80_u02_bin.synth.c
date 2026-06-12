/* task=behavioral_crypto_hw_power_up class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1203b6c */

void crypto_hw_power_up(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40344084U);
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40344084U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403440a8U);
}
