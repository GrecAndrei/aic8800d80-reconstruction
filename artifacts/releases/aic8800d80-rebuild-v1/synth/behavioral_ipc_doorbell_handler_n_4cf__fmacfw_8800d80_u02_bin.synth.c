/* task=behavioral_ipc_doorbell_handler_n_4cf class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x12154ac */

void ipc_doorbell_handler_n_4cf(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x10U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x0U) = 0x0U;
}
