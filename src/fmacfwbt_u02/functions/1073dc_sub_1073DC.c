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

extern uint32_t off_1074BC;
extern uint32_t off_1074C0;
extern uint32_t off_1074C4;
extern uint32_t dword_1074C8;
extern uint32_t dword_1074CC;

// rf_set_tx_power @ 0x1073dc, size 222 bytes
int  rf_set_tx_power(int a1, int a2)
{
  unsigned int *v2; // r5
  unsigned int *v3; // r4
  uint32_t *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (unsigned int *)off_1074BC;
  v3 = (unsigned int *)off_1074C0;
  *(uint32_t *)off_1074BC = *(uint32_t *)off_1074BC & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  rf_set_frequency();
  *v2 &= ~1u;
  timer_set(140);
  v5 = off_1074C4;
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(uint32_t *)(a1 + 44) = v6;
  timer_set(5);
  state_check_feature(1, dword_1074C8);
  result = state_check_feature(1, dword_1074CC);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}

