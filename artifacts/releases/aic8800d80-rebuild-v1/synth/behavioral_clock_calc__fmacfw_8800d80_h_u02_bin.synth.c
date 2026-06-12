/* task=behavioral_clock_calc class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x12031d8 */

void clock_calc(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x1642b0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1642b4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1642b8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1642bcU);
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40500010U);
    (void)*((volatile uint32_t *)(uintptr_t)0x171890U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40500020U);
    *((volatile uint32_t *)(uintptr_t)0x171898U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40100024U);
    *((volatile uint32_t *)(uintptr_t)0x171894U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
