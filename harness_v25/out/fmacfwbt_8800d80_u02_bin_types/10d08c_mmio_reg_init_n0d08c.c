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

extern uint32_t off_10D098;

// mmio_reg_init_n0d08c @ 0x10d08c, size 10 bytes
// Doc: mmio_reg_init_n0d08c [mmio]: Initialize MMIO register at 0x40035000 with 0x4000000
// mmio_reg_init_n0d08c [mmio]: Initialize MMIO register at 0x40035000 with 0x4000000
void mmio_reg_init_n0d08c()
{
  *(uint32_t *)off_10D098 = 0x4000000;
}

