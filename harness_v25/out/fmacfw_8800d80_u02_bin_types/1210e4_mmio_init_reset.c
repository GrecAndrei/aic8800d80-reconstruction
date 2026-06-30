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

extern uint32_t off_1210F4;

// mmio_init_reset @ 0x1210e4, size 14 bytes
// Doc: mmio_init_reset [mmio]: Initialize MMIO control register 0x40320038
// mmio_init_reset [mmio]: Initialize MMIO control register 0x40320038
int mmio_init_reset()
{
  *(uint32_t *)off_1210F4 = 48;
  return sub_12CD34(0);
}

