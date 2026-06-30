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

extern uint32_t off_1075A4;
extern uint32_t off_1075A8;
extern uint32_t off_1075AC;
extern uint32_t dword_1075B0;
extern uint32_t dword_1075B4;

// sub_1074D0 @ 0x1074d0, size 212 bytes
int  sub_1074D0(int a1, int a2)
{
  uint32_t *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r1
  int v7; // r2
  int result; // r0

  v2 = off_1075A4;
  v3 = (unsigned int *)off_1075A8;
  *(uint32_t *)off_1075A4 |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  sub_107370();
  *v2 &= ~1u;
  sub_100644(100);
  v5 = off_1075AC;
  v6 = dword_1075B0;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(uint32_t *)(a1 + 44) = v7;
  sub_12EEF8(1, v6);
  sub_100644(5);
  result = sub_12EEF8(1, dword_1075B4);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  return result;
}

