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

extern uint32_t off_10CCA0;

// gpio_set_pin8 @ 0x10cc94, size 10 bytes
// Doc: gpio_set_pin8 [mmio]: Write magic 0x100 to radio MMIO 0x40035100 to unlock/unblock
// gpio_set_pin8 [mmio]: Write magic 0x100 to radio MMIO 0x40035100 to unlock/unblock
void gpio_set_pin8()
{
  *(uint32_t *)off_10CCA0 = 256;
}

