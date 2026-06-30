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

extern uint32_t off_107524;
extern uint32_t off_107528;
extern uint32_t off_10752C;
extern uint32_t dword_107530;
extern uint32_t dword_107534;

// sub_107444 @ 0x107444, size 222 bytes
int  sub_107444(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (unsigned int *)off_107524;
  v3 = (unsigned int *)off_107528;
  *(uint32_t *)off_107524 = *(uint32_t *)off_107524 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  sub_1073D8();
  *v2 &= ~1u;
  sub_100644(140);
  v5 = off_10752C;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(uint32_t *)(a1 + 44) = v6;
  sub_100644(5);
  sub_12EB90(1, dword_107530);
  result = sub_12EB90(1, dword_107534);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

