/* task=behavioral_mac_phy_init class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1220720 */

void mac_phy_init(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b66U);
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x182b64U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x1220777U;
    *((volatile uint32_t *)(uintptr_t)0x40328050U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328050U);
}
