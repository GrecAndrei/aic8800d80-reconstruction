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

// mmio_rmw_field @ 0x113b5c, size 26 bytes
unsigned int  mmio_rmw_field(int a1)
{
  mmio_write32(1u, (a1 << 13) & 0x1E000);
  return ((unsigned int)mmio_read32(1u) >> 13) & 0xF;
}

