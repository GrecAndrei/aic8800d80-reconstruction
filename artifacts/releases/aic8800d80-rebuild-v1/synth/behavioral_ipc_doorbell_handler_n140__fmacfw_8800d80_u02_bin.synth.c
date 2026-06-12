/* task=behavioral_ipc_doorbell_handler_n140 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215abc */

void ipc_doorbell_handler_n140(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x66U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x1828c6U);
    (void)*((volatile uint32_t *)(uintptr_t)0x18e622U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182b9cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x18e618U);
    *((volatile uint32_t *)(uintptr_t)0x187f90U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x167770U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x1215c5dU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    *((volatile uint32_t *)(uintptr_t)0x187f90U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x187f90U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x1215b21U;
    (void)*((volatile uint32_t *)(uintptr_t)0x190454U);
    (void)*((volatile uint32_t *)(uintptr_t)0x19047cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
