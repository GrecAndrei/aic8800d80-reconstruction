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

extern uint32_t off_1074F8;
extern uint32_t off_1074FC;
extern uint32_t off_107500;
extern uint32_t off_107504;
extern uint32_t off_107508;
extern uint32_t off_10750C;
extern uint32_t off_107510;
extern uint32_t off_107514;

// mmio_init_regs_n3cc @ 0x1073cc, size 298 bytes
// Doc: mmio_init_regs_n3cc [mmio]: Initializes MMIO register fields by clearing and setting bits across memory-mapped blocks
// mmio_init_regs_n3cc [mmio]: Initializes MMIO register fields by clearing and setting bits across memory-mapped blocks
uint32_t *mmio_init_regs_n3cc()
{
  uint32_t *result; // r0
  unsigned int *v1; // r2
  uint32_t *v2; // r3
  unsigned int *v3; // r4
  uint32_t *v4; // r5
  uint32_t *v5; // r6
  uint32_t *v6; // r1
  uint32_t *v7; // r2

  result = off_1074F8;
  v1 = (unsigned int *)off_1074FC;
  v2 = off_107500;
  *(uint32_t *)off_1074F8 &= ~0x80000000;
  v3 = (unsigned int *)off_107504;
  v4 = off_107508;
  v5 = off_10750C;
  *v1 = *v1 & 0xFFFF0FFF | 0xA000;
  *v2 &= 0xCFFFFFFF;
  *v2 &= ~0x40000000u;
  *v3 = *v3 & 0xF8FFFFFF | 0x5000000;
  *v3 = *v3 & 0xFFFFFF8F | 0x50;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v1 &= ~0x20000u;
  *v1 &= ~0x10000u;
  v6 = off_107510;
  *v4 &= ~0x10000000u;
  *v2 |= 0x400000u;
  *v2 |= 0x800000u;
  *v2 |= 0x200000u;
  *v2 |= 0x100000u;
  *v2 &= ~0x40u;
  *v5 &= ~0x1000000u;
  *v6 &= ~0x2000000u;
  *(unsigned int *)((char *)v3 + 0xFFFFFF5C) &= ~0x20000000u;
  v7 = off_107514;
  v4[128] &= ~0x200u;
  v6[49] &= 0xC0FFFFFF;
  v6[49] &= 0xFFC0FFFF;
  v6[49] &= 0xFFFFC0FF;
  v6[49] &= 0xFFFFFFC0;
  *v7 &= 0xC0FFFFFF;
  *v7 &= 0xFFC0FFFF;
  *v7 &= 0xFFFFC0FF;
  *v7 &= 0xFFFFFFC0;
  *v2 &= 0xFFFFFFC0;
  *result |= 0x4000u;
  return result;
}

