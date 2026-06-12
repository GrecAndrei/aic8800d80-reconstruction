/* task=behavioral_ipc_doorbell_handler_n10b class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215a86 */

void ipc_doorbell_handler_n10b(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x50U) = 0x80U;
    (void)*((volatile uint32_t *)(uintptr_t)0x50U);
    *((volatile uint32_t *)(uintptr_t)0x50U) = 0xb7U;
    (void)*((volatile uint32_t *)(uintptr_t)0x5cU);
    *((volatile uint32_t *)(uintptr_t)0x5cU) = 0x80000001U;
    *((volatile uint32_t *)(uintptr_t)0x182566U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e200U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e100U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e204U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e104U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e208U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e108U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    *((volatile uint32_t *)(uintptr_t)0x182566U) = 0x2566U;
}
