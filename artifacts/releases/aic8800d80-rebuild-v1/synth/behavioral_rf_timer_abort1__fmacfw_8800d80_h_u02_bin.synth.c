/* task=behavioral_rf_timer_abort1 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x122ef94 */

void rf_timer_abort1(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x16ad44U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fec8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x122ef9dU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182750U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fec8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feccU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fedcU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee4U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x122efa7U;
}
