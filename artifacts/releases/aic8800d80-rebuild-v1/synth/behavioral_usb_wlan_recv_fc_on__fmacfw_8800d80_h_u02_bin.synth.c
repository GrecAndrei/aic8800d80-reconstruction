/* task=behavioral_usb_wlan_recv_fc_on class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x1246d20 */

void usb_wlan_recv_fc_on(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0xdU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x44U);
    (void)*((volatile uint32_t *)(uintptr_t)0x64U);
    *((volatile uint32_t *)(uintptr_t)0x9U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x34U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x34U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x74U);
}
