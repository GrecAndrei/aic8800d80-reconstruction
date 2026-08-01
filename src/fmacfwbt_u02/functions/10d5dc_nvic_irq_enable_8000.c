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

extern uint32_t off_10D5F0;

// irq_disable @ 0x10d5dc, size 20 bytes
// Doc: irq_disable [util]: Set NVIC pending bit 0x8000 via ICSR write
// irq_disable [util]: Set NVIC pending bit 0x8000 via ICSR write
void irq_disable()
{
  *((uint32_t *)off_10D5F0 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

