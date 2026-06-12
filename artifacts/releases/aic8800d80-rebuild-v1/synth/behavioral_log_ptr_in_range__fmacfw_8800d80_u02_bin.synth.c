/* task=behavioral_log_ptr_in_range class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x120ff34 */

void log_ptr_in_range(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x182260U);
    (void)*((volatile uint32_t *)(uintptr_t)0x182264U);
}
