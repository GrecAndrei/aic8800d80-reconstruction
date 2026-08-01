#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_102ADC;
extern uint32_t off_102AE0;
extern uint32_t dword_102AE4;
extern uint32_t dword_102AE8;
extern uint32_t dword_102AEC;
extern uint32_t off_102AF0;
extern uint32_t dword_102AF4;
extern uint32_t off_102AF8;
extern uint32_t off_102AFC;

// enable_nvic_irq @ 0x102a74, size 104 bytes
// Doc: enable_nvic_irq [mmio]: Set VTOR and enable NVIC interrupts in system control block
// enable_nvic_irq [mmio]: Set VTOR and enable NVIC interrupts in system control block
int enable_nvic_irq()
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

