/* task=behavioral_crypto_power_apply class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1207824 */

void crypto_power_apply(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x8U);
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x164cbcU;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x120783dU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x164cccU;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x1207847U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
}
