/* task=behavioral_hw_config_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1200688 */

void hw_config_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40330000U);
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x40330000U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x182198U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x1200699U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40330000U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fedcU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x182198U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182198U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x18219cU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fee8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x164080U);
    (void)*((volatile uint32_t *)(uintptr_t)0x164082U);
    *((volatile uint32_t *)(uintptr_t)0x4034006cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182199U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182198U) = 0xffU;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
