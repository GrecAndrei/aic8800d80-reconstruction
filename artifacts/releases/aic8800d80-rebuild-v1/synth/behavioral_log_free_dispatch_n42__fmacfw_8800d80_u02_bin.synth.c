/* task=behavioral_log_free_dispatch_n42 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x121004a */

void log_free_dispatch_n42(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    *((volatile uint32_t *)(uintptr_t)0x2007ff00U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff04U) = 0x0U;
}
