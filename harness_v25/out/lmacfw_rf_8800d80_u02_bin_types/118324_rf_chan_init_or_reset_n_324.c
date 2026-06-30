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

// rf_chan_init_or_reset_n_324 @ 0x118324, size 26 bytes
// Doc: rf_chan_init_or_reset_n_324 [rf]: Initializes/resets an RF channel context structure
// rf_chan_init_or_reset_n_324 [rf]: Initializes/resets an RF channel context structure
int  rf_chan_init_or_reset_n_324(int a1)
{
  int result; // r0

  result = timestamp_remove(a1 + 48);
  if ( *(uint32_t *)(a1 + 72) )
    return rf_bus_reset2_c158(a1);
  return result;
}

