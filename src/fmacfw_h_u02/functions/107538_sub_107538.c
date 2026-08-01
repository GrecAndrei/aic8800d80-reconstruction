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

extern uint32_t off_10760C;
extern uint32_t off_107610;
extern uint32_t off_107614;
extern uint32_t dword_107618;
extern uint32_t dword_10761C;

// mmio_enable_aux @ 0x107538, size 212 bytes
int  mmio_enable_aux(int a1, int a2)
{
  uint32_t *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r1
  int v7; // r2
  int result; // r0

  v2 = off_10760C;
  v3 = (unsigned int *)off_107610;
  *(uint32_t *)off_10760C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  pll_set_clock();
  *v2 &= ~1u;
  mmio_read32(100);
  v5 = off_107614;
  v6 = dword_107618;
  *v3 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(uint32_t *)(a1 + 44) = v7;
  check_feature_flag(1, v6);
  mmio_read32(5);
  result = check_feature_flag(1, dword_10761C);
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

