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

extern uint32_t off_102B7C;

// rf_chan_mask_get @ 0x102b60, size 26 bytes
// Doc: rf_chan_mask_get [mmio]: Read RF channel count from MMIO and build 1<<n mask
// rf_chan_mask_get [mmio]: Read RF channel count from MMIO and build 1<<n mask
int rf_chan_mask_get()
{
  return (uint8_t)((1 << ((uint8_t)*(uint32_t *)off_102B7C >> 4)) - 1);
}

