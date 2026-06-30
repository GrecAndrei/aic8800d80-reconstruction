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

// rf_bus_reset_n_90 @ 0x1146dc, size 14 bytes
// Doc: rf_bus_reset_n_90 [rf]: RF bus reset byte readback
// rf_bus_reset_n_90 [rf]: RF bus reset byte readback
void rf_bus_reset_n_90()
{
  *(uint32_t *)(*(uint32_t *)rf_fault_dump_n_5b + 8) |= 2u;
}

