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

extern uint32_t off_11C79C;

// enable_irq @ 0x11c790, size 12 bytes
// Doc: enable_irq [mmio]: Set bit 0x80 in MMIO register at 0x40320324
// enable_irq [mmio]: Set bit 0x80 in MMIO register at 0x40320324
void enable_irq()
{
  *(uint32_t *)off_11C79C |= 0x80u;
}

