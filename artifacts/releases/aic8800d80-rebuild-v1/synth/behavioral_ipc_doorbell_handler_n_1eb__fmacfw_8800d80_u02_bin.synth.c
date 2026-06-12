/* task=behavioral_ipc_doorbell_handler_n_1eb class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215790 */

void ipc_doorbell_handler_n_1eb(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x20U) = 0x0U;
}
