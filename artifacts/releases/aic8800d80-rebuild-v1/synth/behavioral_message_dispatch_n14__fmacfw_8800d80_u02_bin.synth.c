/* task=behavioral_message_dispatch_n14 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122c9a0 */

void message_dispatch_n14(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x122c9b1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1922a8U);
    *((volatile uint32_t *)(uintptr_t)0x1922a8U) = 0xfffffff4U;
    *((volatile uint32_t *)(uintptr_t)0x1922acU) = 0xfffffff4U;
}
