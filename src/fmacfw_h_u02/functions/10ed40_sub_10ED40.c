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

extern uint32_t dword_10ED84;
extern uint32_t dword_10ED8C;
extern uint32_t dword_10ED88;
extern uint32_t dword_10ED90;
extern uint32_t dword_10ED94;

// rf_set_frequency @ 0x10ed40, size 66 bytes
int  rf_set_frequency(int a1, int a2, int a3)
{
  alloc_tx_event(dword_10ED84, a1, a3);
  mmio_rmw32(dword_10ED8C, 196608, dword_10ED88, 1);
  mmio_rmw32(1879048192, 1, 1, 1);
  mmio_read32_variant(dword_10ED90, a1, 1);
  return mmio_rmw32(dword_10ED94, 2, 2, 1);
}

