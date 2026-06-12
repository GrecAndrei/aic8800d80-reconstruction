/* task=behavioral_clear_sdio_state class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x120d2c4 */

void clear_sdio_state(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182aacU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ab0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ab4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ab8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182abcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ac0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ac4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ac8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182accU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ad0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ad4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ad8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182adcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182ae0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
