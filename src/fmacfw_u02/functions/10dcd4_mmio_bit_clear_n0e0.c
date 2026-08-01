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

extern uint32_t off_10DCE8;

// rf_disable_irq @ 0x10dcd4, size 18 bytes
// Doc: rf_disable_irq [mmio]: Clear a single bit in MMIO register at 0x40505000+8 indexed by r0
// rf_disable_irq [mmio]: Clear a single bit in MMIO register at 0x40505000+8 indexed by r0
int  rf_disable_irq(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DCE8 + 2) &= ~result;
  return result;
}

