/* task=behavioral_log_free_wrapper class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120f370 */

void log_free_wrapper(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x120f379U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182260U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182264U);
}
