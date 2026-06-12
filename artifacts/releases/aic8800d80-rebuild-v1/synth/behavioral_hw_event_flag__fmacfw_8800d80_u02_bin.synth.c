/* task=behavioral_hw_event_flag class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12120fc */

void hw_event_flag(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40200b00U);
}
