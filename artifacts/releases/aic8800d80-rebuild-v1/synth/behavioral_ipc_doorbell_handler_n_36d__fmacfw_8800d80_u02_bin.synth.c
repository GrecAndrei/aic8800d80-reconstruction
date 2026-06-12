/* task=behavioral_ipc_doorbell_handler_n_36d class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x121560e */

void ipc_doorbell_handler_n_36d(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x40035108U) = 0x40000000U;
    *((volatile uint32_t *)(uintptr_t)0x184U) = 0x10U;
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
