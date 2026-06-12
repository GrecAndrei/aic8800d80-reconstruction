/* task=behavioral_fp_convert_uint class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x122d5a0 */

void fp_convert_uint(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0xdeadc001U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef4U);
}
