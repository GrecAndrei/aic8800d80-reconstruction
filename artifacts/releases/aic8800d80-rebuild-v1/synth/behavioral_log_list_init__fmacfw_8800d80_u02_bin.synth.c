/* task=behavioral_log_list_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122ff98 */

void log_list_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x18221cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x173188U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182558U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    *((volatile uint32_t *)(uintptr_t)0x18221cU) = 0x1U;
}
