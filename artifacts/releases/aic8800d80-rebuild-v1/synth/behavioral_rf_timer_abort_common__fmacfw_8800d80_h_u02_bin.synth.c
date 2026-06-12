/* task=behavioral_rf_timer_abort_common class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x122ef88 */

void rf_timer_abort_common(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x122ef8fU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40500128U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40506008U);
    *((volatile uint32_t *)(uintptr_t)0xe000e188U) = 0x2U;
    *((volatile uint32_t *)(uintptr_t)0xe000e188U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0xe000e180U) = 0x8000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b5cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x3U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x122ef93U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x16632cU;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x10U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x8000U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec0U) = 0x10U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x120ed4dU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182750U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fec0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fec4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fec8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feccU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fedcU);
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x10U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x120ed5bU;
}
