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

extern uint32_t dword_10EDCC;
extern uint32_t dword_10EDC8;
extern uint32_t dword_10EDD0;

// rf_set_channel @ 0x10ed98, size 46 bytes
int  rf_set_channel(int a1)
{
  mmio_rmw32(dword_10EDCC, 196608, dword_10EDC8, 1);
  mmio_read32_variant(dword_10EDD0, a1 << 15, 1);
  return mmio_rmw32(1879048192, 1, 1, 1);
}

