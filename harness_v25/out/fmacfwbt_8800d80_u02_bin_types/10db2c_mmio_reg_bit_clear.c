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

extern uint32_t off_10DB40;

// mmio_reg_bit_clear @ 0x10db2c, size 18 bytes
// Doc: mmio_reg_bit_clear [mmio]: Clear a single bit in MMIO register at 0x40505000
// mmio_reg_bit_clear [mmio]: Clear a single bit in MMIO register at 0x40505000
int  mmio_reg_bit_clear(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DB40 + 2) &= ~result;
  return result;
}

