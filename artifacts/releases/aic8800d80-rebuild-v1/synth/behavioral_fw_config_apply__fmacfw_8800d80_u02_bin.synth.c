/* task=behavioral_fw_config_apply class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12002a0 */

void fw_config_apply(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182ba0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x34U);
    *((volatile uint32_t *)(uintptr_t)0x182584U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x24U);
    (void)*((volatile uint32_t *)(uintptr_t)0x28U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2cU);
    (void)*((volatile uint32_t *)(uintptr_t)0x30U);
    *((volatile uint32_t *)(uintptr_t)0x187f94U) = 0x1992f4U;
    *((volatile uint32_t *)(uintptr_t)0x182574U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x173334U) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x182578U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x173338U) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x17333cU) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x182580U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x173340U) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x173344U) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x18257cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed0U) = 0x163f70U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed4U) = 0x19ec00U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0x19934cU;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x3U;
    *((volatile uint32_t *)(uintptr_t)0x2007feccU) = 0x1200327U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fed0U);
    *((volatile uint32_t *)(uintptr_t)0x2007fec4U) = 0x2007fed4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fe9cU) = 0x173334U;
    *((volatile uint32_t *)(uintptr_t)0x2007fea0U) = 0x182ba0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fea4U) = 0x182b60U;
    *((volatile uint32_t *)(uintptr_t)0x2007fea8U) = 0x19934cU;
    *((volatile uint32_t *)(uintptr_t)0x2007feacU) = 0x19ec00U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007feb8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007febcU) = 0x120dc37U;
}
