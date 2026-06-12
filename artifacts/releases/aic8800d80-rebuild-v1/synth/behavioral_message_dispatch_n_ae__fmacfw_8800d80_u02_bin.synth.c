/* task=behavioral_message_dispatch_n_ae class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122c8de */

void message_dispatch_n_ae(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x187f8cU) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182560U);
    *((volatile uint32_t *)(uintptr_t)0x182560U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x1922b8U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x182560U;
}
