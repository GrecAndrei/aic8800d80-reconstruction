/* task=behavioral_hw_reg_set_40035000 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120d224 */

void hw_reg_set_40035000(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x40035000U) = 0x2000000U;
}
