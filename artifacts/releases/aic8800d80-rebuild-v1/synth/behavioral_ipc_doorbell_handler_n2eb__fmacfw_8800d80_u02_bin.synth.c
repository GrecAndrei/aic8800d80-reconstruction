/* task=behavioral_ipc_doorbell_handler_n2eb class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215c66 */

void ipc_doorbell_handler_n2eb(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x187f91U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x167798U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x187f91U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x1215ce5U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182750U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fedcU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x40032020U);
}
