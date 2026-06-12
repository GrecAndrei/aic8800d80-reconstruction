/* task=behavioral_ipc_doorbell_handler_n_9a class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12158e2 */

void ipc_doorbell_handler_n_9a(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x4033b3acU);
    *((volatile uint32_t *)(uintptr_t)0x4033b3acU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4033b3d4U);
    *((volatile uint32_t *)(uintptr_t)0x4033b3d4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4033b3acU);
    *((volatile uint32_t *)(uintptr_t)0x4033b3acU) = 0xfd000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4033b3d4U);
    *((volatile uint32_t *)(uintptr_t)0x4033b3d4U) = 0xfd000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40501010U);
    *((volatile uint32_t *)(uintptr_t)0x7U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0xbU) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x1215917U;
}
