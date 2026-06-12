/* task=behavioral_log_hw_regs_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120d1a8 */

void log_hw_regs_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40035008U) = 0xcc0000U;
    *((volatile uint32_t *)(uintptr_t)0x4003500cU) = 0xcc0000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40035018U);
    *((volatile uint32_t *)(uintptr_t)0x40035018U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40035018U);
    *((volatile uint32_t *)(uintptr_t)0x40035018U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40035018U);
    *((volatile uint32_t *)(uintptr_t)0x40035018U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40035018U);
    *((volatile uint32_t *)(uintptr_t)0x40035018U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40035008U) = 0x8000000U;
    *((volatile uint32_t *)(uintptr_t)0x4003500cU) = 0x8000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40035018U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x40035018U) = 0x0U;
}
