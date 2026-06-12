/* task=behavioral_ipc_doorbell_handler_n_bb class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12158c0 */

void ipc_doorbell_handler_n_bb(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0xffffffffU;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff10U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff14U);
}
