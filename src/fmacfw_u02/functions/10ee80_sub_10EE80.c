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

extern uint32_t dword_10EEC4;
extern uint32_t dword_10EECC;
extern uint32_t dword_10EEC8;
extern uint32_t dword_10EED0;
extern uint32_t dword_10EED4;

// rf_set_channel @ 0x10ee80, size 66 bytes
int  rf_set_channel(int a1, int a2, int a3)
{
  event_dispatch(dword_10EEC4, a1, a3);
  mmio_rmw32(dword_10EECC, 196608, dword_10EEC8, 1);
  mmio_rmw32(1879048192, 1, 1, 1);
  mmio_write32(dword_10EED0, a1, 1);
  return mmio_rmw32(dword_10EED4, 2, 2, 1);
}

