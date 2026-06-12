/* task=behavioral_irq_vector_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1202bfc */

void irq_vector_init(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x50U) = 0x137925U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x54U) = 0x13ebc5U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x20U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x5cU) = 0x13ebc5U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x80U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x48U) = 0x14bff1U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x4U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x58U) = 0x14c1e1U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x40U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0x4cU) = 0x1378c9U;
    (void)*((volatile uint32_t *)(uintptr_t)0x173279U);
    *((volatile uint32_t *)(uintptr_t)0xe000e403U) = 0xf8U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x8U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0xd0U) = 0x12cae1U;
    *((volatile uint32_t *)(uintptr_t)0xe000e104U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0xe000ed08U);
    *((volatile uint32_t *)(uintptr_t)0xd4U) = 0x12c985U;
    *((volatile uint32_t *)(uintptr_t)0xe000e104U) = 0x20U;
    *((volatile uint32_t *)(uintptr_t)0xe000e100U) = 0x800000U;
    *((volatile uint32_t *)(uintptr_t)0xe000e104U) = 0x40U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
}
