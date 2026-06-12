/* task=behavioral_lpm_host_notify_bt class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x1246044 */

void lpm_host_notify_bt(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x1U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x74U);
    *((volatile uint32_t *)(uintptr_t)0x11U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x64U);
    *((volatile uint32_t *)(uintptr_t)0x11U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x64U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x11U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x64U);
    *((volatile uint32_t *)(uintptr_t)0x54U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x44U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x3cU);
}
