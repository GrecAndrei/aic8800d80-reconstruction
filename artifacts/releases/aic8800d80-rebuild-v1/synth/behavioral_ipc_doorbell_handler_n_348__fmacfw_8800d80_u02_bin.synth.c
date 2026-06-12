/* task=behavioral_ipc_doorbell_handler_n_348 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215634 */

void ipc_doorbell_handler_n_348(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0xfffffffcU;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0xfffffffcU;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40500038U);
    *((volatile uint32_t *)(uintptr_t)0x40500038U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0x403450e0U);
    *((volatile uint32_t *)(uintptr_t)0x403450e0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x1676c0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x403450e0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x1215667U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
    *((volatile uint32_t *)(uintptr_t)0x40328048U) = 0x80000000U;
    *((volatile uint32_t *)(uintptr_t)0x182569U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
}
