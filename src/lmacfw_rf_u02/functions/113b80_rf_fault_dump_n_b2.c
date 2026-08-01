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

// mmio_write_reg2 @ 0x113b80, size 8 bytes
// Doc: mmio_write_reg2 [rf]: Dump RF fault state, iterating up to 0x5c entries
// mmio_write_reg2 [rf]: Dump RF fault state, iterating up to 0x5c entries
int  mmio_write_reg2(int a1)
{
  return mmio_write32(2u, a1);
}

