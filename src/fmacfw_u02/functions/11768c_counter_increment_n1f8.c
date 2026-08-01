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

extern uint32_t off_11769C;

// irq_counter_inc @ 0x11768c, size 14 bytes
// Doc: irq_counter_inc [util]: Increment 32-bit counter at offset 0x1f8
// irq_counter_inc [util]: Increment 32-bit counter at offset 0x1f8
void irq_counter_inc()
{
  ++*((uint32_t *)off_11769C + 126);
}

