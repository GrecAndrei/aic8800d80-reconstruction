/* task=behavioral_ipc_doorbell_handler_n40c class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215d88 */

void ipc_doorbell_handler_n40c(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    *((volatile uint32_t *)(uintptr_t)0x6U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x3U) = 0x1U;
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
}
