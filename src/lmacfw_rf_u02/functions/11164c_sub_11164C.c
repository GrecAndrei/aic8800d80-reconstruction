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

// rf_enable_tx_patch @ 0x11164c, size 36 bytes
// Doc: rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
// rf_bus_mark_n4c8 [rf]: Marks RF bus state for n4c8 access pattern
int * rf_enable_tx_patch(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_channel_get_flag(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_channel_set_flag(a2, 0x8000000, 0);
  }
  return result;
}

