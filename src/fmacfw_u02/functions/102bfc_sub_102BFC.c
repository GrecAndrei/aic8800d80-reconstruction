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

extern uint32_t off_102C80;
extern uint32_t off_102C84;
extern uint32_t dword_102C88;
extern uint32_t dword_102C8C;
extern uint32_t dword_102C90;
extern uint32_t dword_102C94;
extern uint32_t dword_102C98;
extern uint32_t off_102C9C;
extern uint32_t off_102CA0;
extern uint32_t off_102CA4;

// install_isr @ 0x102bfc, size 132 bytes
int install_isr()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r3
  int v2; // r1
  int v3; // r0
  int v4; // r4
  int v5; // r0
  int v6; // r1
  uint8_t *v7; // r2
  int v8; // r2
  uint32_t *v9; // r2
  uint32_t *v10; // r3

  v0 = off_102C80;
  v1 = off_102C84;
  *(uint32_t *)(*((uint32_t *)off_102C80 + 2) + 80) = dword_102C88;
  *(uint32_t *)v1 = 16;
  v2 = dword_102C8C;
  *(uint32_t *)(v0[2] + 84) = dword_102C8C;
  *(uint32_t *)v1 = 32;
  v3 = dword_102C90;
  *(uint32_t *)(v0[2] + 92) = v2;
  *(uint32_t *)v1 = 128;
  v4 = dword_102C94;
  *(uint32_t *)(v0[2] + 72) = v3;
  *(uint32_t *)v1 = 4;
  v5 = dword_102C98;
  *(uint32_t *)(v0[2] + 88) = v4;
  *(uint32_t *)v1 = 64;
  v6 = v0[2];
  v7 = (uint8_t *)off_102C9C;
  *(uint32_t *)(v6 + 76) = v5;
  v8 = v7[413];
  v1[771] = -8;
  *(uint32_t *)v1 = 8;
  if ( v8 )
    *(uint32_t *)v1 = 512;
  v9 = off_102C80;
  v10 = off_102C84;
  *(uint32_t *)(*((uint32_t *)off_102C80 + 2) + 208) = off_102CA0;
  v10[1] = 16;
  *(uint32_t *)(v9[2] + 212) = off_102CA4;
  v10[1] = 32;
  *v10 = 0x800000;
  v10[1] = 64;
  __enable_irq();
  return 32;
}

