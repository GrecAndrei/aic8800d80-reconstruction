/* task=behavioral_ps_upm_exit class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x124972c */

void ps_upm_exit(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0xdU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x15U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x54U);
    *((volatile uint32_t *)(uintptr_t)0x54U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x14U);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x14U);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x60U);
    *((volatile uint32_t *)(uintptr_t)0x14U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x14U);
    *((volatile uint32_t *)(uintptr_t)0xdU) = 0x20U;
    (void)*((volatile uint32_t *)(uintptr_t)0x50U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x14U);
}
