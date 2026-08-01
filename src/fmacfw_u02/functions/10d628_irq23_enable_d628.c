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

extern uint32_t off_10D640;
extern uint32_t off_10D63C;
extern uint32_t dword_10D644;

// irq_install_handler @ 0x10d628, size 20 bytes
// Doc: irq_install_handler [mmio]: Set pending bit 0x200000 in NVIC ISER to enable IRQ23
// irq_install_handler [mmio]: Set pending bit 0x200000 in NVIC ISER to enable IRQ23
void irq_install_handler()
{
  uint32_t *v0; // r3

  v0 = off_10D640;
  *(uint32_t *)(*((uint32_t *)off_10D63C + 2) + 148) = dword_10D644;
  *v0 = 0x200000;
}

