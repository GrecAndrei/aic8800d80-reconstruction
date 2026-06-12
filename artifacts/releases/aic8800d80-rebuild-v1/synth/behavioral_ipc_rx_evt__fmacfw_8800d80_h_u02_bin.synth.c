/* task=behavioral_ipc_rx_evt class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x1247060 */

void ipc_rx_evt(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x1U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1U);
    *((volatile uint32_t *)(uintptr_t)0x54U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x11U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x9U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x74U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x54U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x74U);
    *((volatile uint32_t *)(uintptr_t)0x64U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x60U);
}
