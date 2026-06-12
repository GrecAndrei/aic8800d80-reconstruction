/* task=behavioral_uart_putc class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_h_u02_bin addr=0x120d65c */

void uart_putc(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x40032020U);
    *((volatile uint32_t *)(uintptr_t)0x40032000U) = 0x0U;
}
