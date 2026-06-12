/* task=behavioral_message_dispatch_n_1b4 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x122c7d8 */

void message_dispatch_n_1b4(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x60U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x64U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x68U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x6cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee4U) = 0xa4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fee8U) = 0x70U;
    *((volatile uint32_t *)(uintptr_t)0x2007feecU) = 0xb8U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fed8U) = 0xa4U;
    *((volatile uint32_t *)(uintptr_t)0x2007fedcU) = 0x182560U;
}
