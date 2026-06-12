/* task=behavioral_ipc_doorbell_handler_n215 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215b90 */

void ipc_doorbell_handler_n215(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x182565U);
    *((volatile uint32_t *)(uintptr_t)0x187f91U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182564U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    *((volatile uint32_t *)(uintptr_t)0x2007ff04U) = 0x16773cU;
    *((volatile uint32_t *)(uintptr_t)0x2007ff08U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff0cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff00U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
}
