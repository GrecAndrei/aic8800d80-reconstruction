/* task=behavioral_ipc_doorbell_handler_n_326 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215656 */

void ipc_doorbell_handler_n_326(void) {
  /* reconstructed_micro_flow: yes */
    *((volatile uint32_t *)(uintptr_t)0x2007fef4U) = 0x1676c0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fef0U) = 0x1215667U;
    (void)*((volatile uint32_t *)(uintptr_t)0x182b60U);
    (void)*((volatile uint32_t *)(uintptr_t)0x0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef0U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
    *((volatile uint32_t *)(uintptr_t)0x40328048U) = 0x80000000U;
    *((volatile uint32_t *)(uintptr_t)0x182569U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328048U);
}
