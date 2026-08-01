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

extern uint32_t off_100764;
extern uint32_t off_100768;
extern uint32_t off_100760;

// enable_interrupt @ 0x100730, size 46 bytes
// Doc: enable_interrupt [mmio]: Initializes MMIO register at 0x40344084 by setting bit 0x10000
// enable_interrupt [mmio]: Initializes MMIO register at 0x40344084 by setting bit 0x10000
uint32_t *enable_interrupt()
{
  uint32_t *result; // r0
  int *v1; // r2

  result = off_100764;
  v1 = (int *)off_100768;
  *(uint32_t *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}

