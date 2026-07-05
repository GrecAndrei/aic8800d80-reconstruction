#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_10D4E0 ((uint32_t)0xe000e100u)
#define off_10D4DC ((uint32_t)0xe000ed00u)
#define off_10D4E4 ((uint32_t)0x0012d44du)
// irq23_enable @ 0x10d4c8, size 20 bytes
// Doc: irq23_enable [mmio]: Enable IRQ line 23 in interrupt controller
// irq23_enable [mmio]: Enable IRQ line 23 in interrupt controller
void irq23_enable()
{
  uint32_t *v0; // r3

  v0 = off_10D4E0;
  *(uint32_t *)(*((uint32_t *)off_10D4DC + 2) + 148) = off_10D4E4;
  *v0 = 0x200000;
}

