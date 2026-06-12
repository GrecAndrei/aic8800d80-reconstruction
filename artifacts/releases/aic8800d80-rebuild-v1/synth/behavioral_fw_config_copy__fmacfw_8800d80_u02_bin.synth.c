/* task=behavioral_fw_config_copy class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120f204 */

void fw_config_copy(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x182b54U);
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x18U);
    (void)*((volatile uint32_t *)(uintptr_t)0x1cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x20U);
    (void)*((volatile uint32_t *)(uintptr_t)0x24U);
    *((volatile uint32_t *)(uintptr_t)0x182b38U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x28U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2cU);
    *((volatile uint32_t *)(uintptr_t)0x182b3cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182b40U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182b44U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182b48U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182b4cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x120f229U;
}
