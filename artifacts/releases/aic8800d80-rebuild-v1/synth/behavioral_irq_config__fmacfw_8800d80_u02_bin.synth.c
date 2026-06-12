/* task=behavioral_irq_config class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120dd44 */

void irq_config(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40504080U);
    *((volatile uint32_t *)(uintptr_t)0x40504080U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505004U);
    *((volatile uint32_t *)(uintptr_t)0x40505004U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505028U);
    *((volatile uint32_t *)(uintptr_t)0x40505028U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050500cU);
    *((volatile uint32_t *)(uintptr_t)0x4050500cU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505010U);
    *((volatile uint32_t *)(uintptr_t)0x40505010U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505014U);
    *((volatile uint32_t *)(uintptr_t)0x40505014U) = 0x1U;
    *((volatile uint32_t *)(uintptr_t)0x40505024U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505018U);
    *((volatile uint32_t *)(uintptr_t)0x40505018U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050502cU);
    *((volatile uint32_t *)(uintptr_t)0x4050502cU) = 0x7U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e100U);
    *((volatile uint32_t *)(uintptr_t)0x182220U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x9cU) = 0x12dc41U;
    *((volatile uint32_t *)(uintptr_t)0xe000e417U) = 0xfcU;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x800000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
