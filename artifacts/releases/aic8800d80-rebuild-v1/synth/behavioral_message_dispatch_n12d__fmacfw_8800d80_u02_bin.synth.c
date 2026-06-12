/* task=behavioral_message_dispatch_n12d class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122cab8 */

void message_dispatch_n12d(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
}
