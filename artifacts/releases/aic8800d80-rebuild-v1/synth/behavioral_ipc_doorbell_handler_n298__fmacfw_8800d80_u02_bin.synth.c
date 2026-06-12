/* task=behavioral_ipc_doorbell_handler_n298 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215c14 */

void ipc_doorbell_handler_n298(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c5U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    *((volatile uint32_t *)(uintptr_t)0x2007ff04U) = 0x16775cU;
    *((volatile uint32_t *)(uintptr_t)0x2007ff08U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff0cU) = 0x1822c5U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff00U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
}
