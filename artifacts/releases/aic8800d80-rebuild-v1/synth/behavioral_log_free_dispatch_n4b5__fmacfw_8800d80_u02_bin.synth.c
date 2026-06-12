/* task=behavioral_log_free_dispatch_n4b5 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12104bc */

void log_free_dispatch_n4b5(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x19U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
}
