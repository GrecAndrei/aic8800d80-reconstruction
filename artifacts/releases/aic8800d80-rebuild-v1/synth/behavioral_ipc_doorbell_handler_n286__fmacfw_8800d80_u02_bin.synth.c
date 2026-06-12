/* task=behavioral_ipc_doorbell_handler_n286 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215c02 */

void ipc_doorbell_handler_n286(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x1215ccbU;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050012cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x187f90U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40500038U);
    *((volatile uint32_t *)(uintptr_t)0x40500038U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1822c5U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff04U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff08U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff0cU);
    *((volatile uint32_t *)(uintptr_t)0x2007ff04U) = 0x16775cU;
    *((volatile uint32_t *)(uintptr_t)0x2007ff08U) = 0x40500000U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff0cU) = 0x1822c5U;
    *((volatile uint32_t *)(uintptr_t)0x2007ff00U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007ff00U);
}
