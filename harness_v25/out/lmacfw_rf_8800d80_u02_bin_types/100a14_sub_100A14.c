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

extern uint32_t off_100A70;
extern uint32_t dword_100A74;
extern uint32_t dword_100A78;
extern uint32_t off_100A7C;

// sub_100A14 @ 0x100a14, size 90 bytes
int sub_100A14()
{
  uint32_t *v0; // r2
  int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  uint32_t *v5; // r2
  uint32_t *v6; // r3

  v0 = off_100A70;
  *(uint32_t *)off_100A70 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (int *)dword_100A74;
  v2 = dword_100A74 + 2048;
  result = dword_100A78 - dword_100A74;
  do
  {
    v4 = *v1;
    v5 = (int *)((char *)v1++ + result);
    *v5 = v4;
  }
  while ( v1 != (int *)v2 );
  v6 = off_100A70;
  *(uint32_t *)off_100A70 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(uint32_t *)off_100A7C &= ~0x20000000u;
  return result;
}

