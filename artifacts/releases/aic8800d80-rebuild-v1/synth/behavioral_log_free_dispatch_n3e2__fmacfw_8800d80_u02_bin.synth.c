/* task=behavioral_log_free_dispatch_n3e2 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12103ea */

void log_free_dispatch_n3e2(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x187f8cU) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182560U);
    *((volatile uint32_t *)(uintptr_t)0x182560U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x187e68U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182560U);
    (void)*((volatile uint32_t *)(uintptr_t)0x187f8cU);
    *((volatile uint32_t *)(uintptr_t)0x182560U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
}
