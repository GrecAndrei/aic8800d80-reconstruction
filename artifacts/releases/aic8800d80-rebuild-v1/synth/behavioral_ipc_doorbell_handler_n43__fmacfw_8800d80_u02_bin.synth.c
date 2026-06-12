/* task=behavioral_ipc_doorbell_handler_n43 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12159be */

void ipc_doorbell_handler_n43(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0xbdU);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x80000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340018U);
    *((volatile uint32_t *)(uintptr_t)0x40340018U) = 0x111U;
    *((volatile uint32_t *)(uintptr_t)0x1U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x40320038U) = 0x20U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340018U);
    *((volatile uint32_t *)(uintptr_t)0x40340018U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
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
}
