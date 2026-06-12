/* task=behavioral_ipc_doorbell_handler_n1ee class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215b6a */

void ipc_doorbell_handler_n1ee(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x6cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x167770U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x1215c5dU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c5U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
}
