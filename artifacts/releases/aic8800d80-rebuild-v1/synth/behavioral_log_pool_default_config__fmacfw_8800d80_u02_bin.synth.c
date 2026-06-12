/* task=behavioral_log_pool_default_config class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120f37c */

void log_pool_default_config(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x1856f4U) = 0x50U;
    *((volatile uint32_t *)(uintptr_t)0x1856f6U) = 0x51U;
    *((volatile uint32_t *)(uintptr_t)0x1856f8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x1856fcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x185a20U) = 0x27U;
    *((volatile uint32_t *)(uintptr_t)0x185a22U) = 0x28U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x185a24U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x185a28U) = 0x0U;
}
