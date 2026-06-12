/* task=behavioral_ipc_doorbell_handler_n_169 class=behavioral priority=critical score=25.000 */
/* image=fmacfw_8800d80_u02_bin addr=0x1215812 */

void ipc_doorbell_handler_n_169(void) {
  /* reconstructed_micro_flow: yes */
    (void)*((volatile uint32_t *)(uintptr_t)0x4032004cU);
    *((volatile uint32_t *)(uintptr_t)0x2007fef8U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x2007fefcU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x4032004cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40320038U) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x40320054U) = 0x3cU;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320038U);
    (void)*((volatile uint32_t *)(uintptr_t)0x40320054U);
    *((volatile uint32_t *)(uintptr_t)0x40320054U) = 0x1003cU;
    (void)*((volatile uint32_t *)(uintptr_t)0x4032808cU);
    *((volatile uint32_t *)(uintptr_t)0x4032808cU) = 0x0U;
    *((volatile uint32_t *)(uintptr_t)0x4032807cU) = 0xffffffffU;
    *((volatile uint32_t *)(uintptr_t)0x40328070U) = 0xb73f144U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328074U);
    *((volatile uint32_t *)(uintptr_t)0x40328074U) = 0x80000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328080U);
    (void)*((volatile uint32_t *)(uintptr_t)0x190458U);
    *((volatile uint32_t *)(uintptr_t)0x40328080U) = 0x80000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40328068U);
    *((volatile uint32_t *)(uintptr_t)0x40328068U) = 0x80000000U;
    (void)*((volatile uint32_t *)(uintptr_t)0x4032004cU);
    *((volatile uint32_t *)(uintptr_t)0x4032004cU) = 0x80U;
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fef8U);
    (void)*((volatile uint32_t *)(uintptr_t)0x2007fefcU);
    *((volatile uint32_t *)(uintptr_t)0x190458U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320400U);
    *((volatile uint32_t *)(uintptr_t)0x40320400U) = 0x0U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40320400U);
    *((volatile uint32_t *)(uintptr_t)0x40320400U) = 0x10U;
    (void)*((volatile uint32_t *)(uintptr_t)0x40501010U);
}
