/* task=behavioral_log_free_pool_a class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1210390 */

void log_free_pool_a(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
}
