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

extern uint32_t dword_10EF0C;
extern uint32_t dword_10EF08;
extern uint32_t dword_10EF10;

// rf_set_frequency @ 0x10eed8, size 46 bytes
int  rf_set_frequency(int a1)
{
  mmio_rmw32(dword_10EF0C, 196608, dword_10EF08, 1);
  mmio_write32(dword_10EF10, a1 << 15, 1);
  return mmio_rmw32(1879048192, 1, 1, 1);
}

