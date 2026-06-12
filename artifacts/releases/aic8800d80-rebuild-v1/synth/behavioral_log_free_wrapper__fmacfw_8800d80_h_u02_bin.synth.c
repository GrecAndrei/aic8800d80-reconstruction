/* task=behavioral_log_free_wrapper class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x120f230 */

void log_free_wrapper(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x120f239U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182260U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182264U);
}
