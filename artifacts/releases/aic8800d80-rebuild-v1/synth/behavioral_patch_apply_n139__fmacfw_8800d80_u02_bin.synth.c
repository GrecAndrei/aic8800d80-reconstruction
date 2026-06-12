/* task=behavioral_patch_apply_n139 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1214fe4 */

void patch_apply_n139(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x200802d0U) = 0x0U;
}
