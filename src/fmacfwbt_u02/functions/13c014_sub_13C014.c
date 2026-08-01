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

extern uint32_t off_13C048;
extern uint32_t dword_13C04C;

// phy_is_ready @ 0x13c014, size 52 bytes
// Doc: sub_123C014 [util]: Loads pointer and dereferences offset 0x18
// sub_123C014 [util]: Loads pointer and dereferences offset 0x18
int phy_is_ready()
{
  uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13C048;
  if ( !*((uint32_t *)off_13C048 + 6)
    || (result = *((uint8_t *)list_pop_front((int)off_13C048 + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (uint8_t)rx_queue_flush((int **)dword_13C04C);
    if ( (uint8_t)v2 == 33 )
    {
      return 33;
    }
    else
    {
      rf_get_chan_info(v2);
      return 33;
    }
  }
  return result;
}

