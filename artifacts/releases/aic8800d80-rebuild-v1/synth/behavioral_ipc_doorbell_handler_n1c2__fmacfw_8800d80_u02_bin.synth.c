/* task=behavioral_ipc_doorbell_handler_n1c2 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215b3e */

void ipc_doorbell_handler_n1c2(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x4032004cU);
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x1215b45U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40501010U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40328040U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40501010U);
    (void)*((volatile uint32_t *)(uintptr_t)0x173194U);
    (void)*((volatile uint32_t *)(uintptr_t)0x173196U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
}
