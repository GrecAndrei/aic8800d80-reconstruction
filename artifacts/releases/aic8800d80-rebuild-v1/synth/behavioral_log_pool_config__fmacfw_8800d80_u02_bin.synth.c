/* task=behavioral_log_pool_config class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120f38c */

void log_pool_config(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x656U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x980U) = 0x27U;
    *((volatile uint32_t *)(uintptr_t)0x982U) = 0x28U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    *((volatile uint32_t *)(uintptr_t)0x984U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x988U) = 0x0U;
}
