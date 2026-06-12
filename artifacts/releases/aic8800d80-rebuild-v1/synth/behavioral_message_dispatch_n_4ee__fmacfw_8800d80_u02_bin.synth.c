/* task=behavioral_message_dispatch_n_4ee class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122c49e */

void message_dispatch_n_4ee(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0eU);
    (void)*((volatile uint32_t *)(uintptr_t)0x403200a0U);
    *((volatile uint32_t *)(uintptr_t)0x403200a0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403200a0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0fU);
    *((volatile uint32_t *)(uintptr_t)0x403200a0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff14U);
}
