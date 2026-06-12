/* task=behavioral_ipc_doorbell_handler_n2d class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12159a8 */

void ipc_doorbell_handler_n2d(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
}
