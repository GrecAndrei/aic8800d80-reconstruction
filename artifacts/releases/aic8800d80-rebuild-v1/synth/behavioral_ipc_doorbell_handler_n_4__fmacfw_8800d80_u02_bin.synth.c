/* task=behavioral_ipc_doorbell_handler_n_4 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215978 */

void ipc_doorbell_handler_n_4(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x1cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320038U);
    *((volatile uint32_t *)(uintptr_t)0x182568U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320038U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x167724U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x1215999U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40320038U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
    *((volatile uint32_t *)(uintptr_t)0x40328048U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340018U);
    *((volatile uint32_t *)(uintptr_t)0x40340018U) = 0x111U;
    *((volatile uint32_t *)(uintptr_t)0x182569U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x40320038U) = 0x20U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40340018U);
    *((volatile uint32_t *)(uintptr_t)0x40340018U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x182566U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e200U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e100U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e204U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e104U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e208U);
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e108U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
