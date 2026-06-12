/* task=behavioral_irq_mask_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120de94 */

void irq_mask_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40504084U);
    *((volatile uint32_t *)(uintptr_t)0x40504084U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505004U);
    *((volatile uint32_t *)(uintptr_t)0x40505004U) = 0x2U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x2U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40504088U);
    *((volatile uint32_t *)(uintptr_t)0x40504088U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505004U);
    *((volatile uint32_t *)(uintptr_t)0x40505004U) = 0x6U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x6U;
    (void)*((volatile uint32_t *)(uintptr_t)0x17324dU);
    (void)*((volatile uint32_t *)(uintptr_t)0x40505000U);
    *((volatile uint32_t *)(uintptr_t)0x40505000U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505000U);
    *((volatile uint32_t *)(uintptr_t)0x40505000U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x6U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050408cU);
    *((volatile uint32_t *)(uintptr_t)0x4050408cU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505004U);
    *((volatile uint32_t *)(uintptr_t)0x40505004U) = 0xeU;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505008U);
    *((volatile uint32_t *)(uintptr_t)0x40505008U) = 0x6U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505028U);
    *((volatile uint32_t *)(uintptr_t)0x40505028U) = 0x8U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050500cU);
    *((volatile uint32_t *)(uintptr_t)0x4050500cU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505010U);
    *((volatile uint32_t *)(uintptr_t)0x40505010U) = 0x8U;
    *((volatile uint32_t *)(uintptr_t)0x40505024U) = 0x8U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40505018U);
    *((volatile uint32_t *)(uintptr_t)0x40505018U) = 0x8U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4050502cU);
    *((volatile uint32_t *)(uintptr_t)0x4050502cU) = 0x7U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000e100U);
    *((volatile uint32_t *)(uintptr_t)0x18222cU) = 0x12de39U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x9cU) = 0x12dc41U;
    *((volatile uint32_t *)(uintptr_t)0xe000e417U) = 0xfcU;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x800000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007feecU);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
    *((volatile uint32_t *)(uintptr_t)0x182af8U) = 0x12de09U;
    *((volatile uint32_t *)(uintptr_t)0x182ae8U) = 0x12de21U;
    *((volatile uint32_t *)(uintptr_t)0x182aecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x182afcU) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
