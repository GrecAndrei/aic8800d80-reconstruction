/* task=behavioral_ipc_doorbell_handler_n_e1 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x121589a */

void ipc_doorbell_handler_n_e1(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x8U);
    (void)*((volatile uint32_t *)(uintptr_t)0xcU);
    *((volatile uint32_t *)(uintptr_t)0x403281d8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x403281dcU) = 0xfffffffcU;
    *((volatile uint32_t *)(uintptr_t)0x403281e0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x403281e4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x188424U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x18841cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x188420U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff10U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff14U);
}
