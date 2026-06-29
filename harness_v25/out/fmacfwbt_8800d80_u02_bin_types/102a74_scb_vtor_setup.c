// scb_vtor_setup @ 0x102a74, size 104 bytes
// Doc: scb_vtor_setup [mmio]: Set VTOR and enable NVIC interrupts in system control block
// scb_vtor_setup [mmio]: Set VTOR and enable NVIC interrupts in system control block
int scb_vtor_setup()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r3
  int v2; // r1
  int v4; // r6
  void *v5; // r5
  int v6; // r6
  void *v7; // r7
  void *v8; // r5

  v0 = off_102ADC;
  v1 = off_102AE0;
  *(uint32_t *)(*((uint32_t *)off_102ADC + 2) + 80) = dword_102AE4;
  *(uint32_t *)v1 = 16;
  v2 = dword_102AE8;
  *(uint32_t *)(v0[2] + 84) = dword_102AE8;
  *(uint32_t *)v1 = 32;
  v4 = dword_102AEC;
  *(uint32_t *)(v0[2] + 92) = v2;
  *(uint32_t *)v1 = 128;
  v5 = off_102AF0;
  *(uint32_t *)(v0[2] + 72) = v4;
  *(uint32_t *)v1 = 4;
  v6 = dword_102AF4;
  *(uint32_t *)(v0[2] + 88) = v5;
  *(uint32_t *)v1 = 64;
  v7 = off_102AF8;
  *(uint32_t *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(uint32_t *)v1 = 8;
  v8 = off_102AFC;
  *(uint32_t *)(v0[2] + 208) = v7;
  *((uint32_t *)v1 + 1) = 16;
  *(uint32_t *)(v0[2] + 212) = v8;
  *((uint32_t *)v1 + 1) = 32;
  *(uint32_t *)v1 = 0x800000;
  *((uint32_t *)v1 + 1) = 64;
  __enable_irq();
  return 32;
}

