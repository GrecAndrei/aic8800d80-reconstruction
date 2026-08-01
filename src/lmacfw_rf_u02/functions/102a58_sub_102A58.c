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

extern uint32_t off_102AB8;
extern uint32_t off_102ABC;
extern uint32_t dword_102AC0;
extern uint32_t dword_102AC4;
extern uint32_t dword_102AC8;
extern uint32_t dword_102ACC;
extern uint32_t dword_102AD0;
extern uint32_t dword_102AD4;
extern uint32_t off_102AD8;

// nvic_enable_irq @ 0x102a58, size 96 bytes
int nvic_enable_irq()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r3
  int v3; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r5
  int v7; // r6
  void *v8; // r4

  v0 = off_102AB8;
  v1 = off_102ABC;
  *(uint32_t *)(*((uint32_t *)off_102AB8 + 2) + 80) = dword_102AC0;
  *(uint32_t *)v1 = 16;
  v3 = dword_102AC4;
  *(uint32_t *)(v0[2] + 84) = dword_102AC4;
  *(uint32_t *)v1 = 32;
  v4 = dword_102AC8;
  *(uint32_t *)(v0[2] + 92) = v3;
  *(uint32_t *)v1 = 128;
  v5 = dword_102ACC;
  *(uint32_t *)(v0[2] + 72) = v4;
  *(uint32_t *)v1 = 4;
  v6 = dword_102AD0;
  *(uint32_t *)(v0[2] + 88) = v5;
  *(uint32_t *)v1 = 64;
  v7 = dword_102AD4;
  *(uint32_t *)(v0[2] + 76) = v6;
  v1[771] = -8;
  *(uint32_t *)v1 = 8;
  v8 = off_102AD8;
  *(uint32_t *)(v0[2] + 208) = v7;
  *((uint32_t *)v1 + 1) = 16;
  *(uint32_t *)(v0[2] + 212) = v8;
  *((uint32_t *)v1 + 1) = 32;
  __enable_irq();
  return 16;
}

