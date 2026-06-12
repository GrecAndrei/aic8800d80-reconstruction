/* task=behavioral_crypto_hw_write32 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120410c */

void crypto_hw_write32(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340010U);
    *((volatile uint32_t *)(uintptr_t)0x40340010U) = 0x1000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x8000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x8000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x8000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x208000U;
    *((volatile uint32_t *)(uintptr_t)0x40342280U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x208000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x8000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x208000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x200000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x600000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40342274U);
    *((volatile uint32_t *)(uintptr_t)0x40342274U) = 0x600000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340010U);
    *((volatile uint32_t *)(uintptr_t)0x40340010U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
