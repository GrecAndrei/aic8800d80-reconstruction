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

extern uint32_t off_10D638;

// nvic_irq_enable @ 0x10d624, size 20 bytes
// Doc: nvic_irq_enable [util]: Enable NVIC interrupt 15 via ISER/ICER at 0xE000E100
// nvic_irq_enable [util]: Enable NVIC interrupt 15 via ISER/ICER at 0xE000E100
void nvic_irq_enable()
{
  *((uint32_t *)off_10D638 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}

