/* task=behavioral_feature_flags_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x122f3a8 */

void feature_flags_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x18274cU;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x18274cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182750U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    *((volatile uint32_t *)(uintptr_t)0x18274cU) = 0xffffffffU;
    *((volatile uint32_t *)(uintptr_t)0x182750U) = 0x2U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
