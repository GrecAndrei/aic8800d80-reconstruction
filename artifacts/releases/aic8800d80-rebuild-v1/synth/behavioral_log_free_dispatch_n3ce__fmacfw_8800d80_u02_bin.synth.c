/* task=behavioral_log_free_dispatch_n3ce class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12103d6 */

void log_free_dispatch_n3ce(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x18U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
}
