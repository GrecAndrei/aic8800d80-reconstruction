/* task=behavioral_crypto_hw_clear_regs class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1207518 */

void crypto_hw_clear_regs(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x403420ccU);
    *((volatile uint32_t *)(uintptr_t)0x403420ccU) = 0x3000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420ccU);
    *((volatile uint32_t *)(uintptr_t)0x403420ccU) = 0x3030000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420ccU);
    *((volatile uint32_t *)(uintptr_t)0x403420ccU) = 0x3030300U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420ccU);
    *((volatile uint32_t *)(uintptr_t)0x403420ccU) = 0x3030303U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420d0U);
    *((volatile uint32_t *)(uintptr_t)0x403420d0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420d0U);
    *((volatile uint32_t *)(uintptr_t)0x403420d0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420d0U);
    *((volatile uint32_t *)(uintptr_t)0x403420d0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420d0U);
    *((volatile uint32_t *)(uintptr_t)0x403420d0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403420d4U);
    *((volatile uint32_t *)(uintptr_t)0x403420d4U) = 0x0U;
}
