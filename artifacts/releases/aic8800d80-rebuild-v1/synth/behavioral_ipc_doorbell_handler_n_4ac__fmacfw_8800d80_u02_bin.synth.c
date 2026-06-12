/* task=behavioral_ipc_doorbell_handler_n_4ac class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12154d0 */

void ipc_doorbell_handler_n_4ac(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x1aU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182564U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1828c6U);
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x1676b4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x12154efU;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x18e622U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
