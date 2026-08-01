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

extern uint32_t off_11B678;
extern uint32_t off_11B67C;

// zero_global_if_flag_clear @ 0x11b634, size 68 bytes
BOOL  zero_global_if_flag_clear(BOOL result)
{
  int v1; // r3
  uint32_t *v2; // r2
  int v3; // r4

  v1 = *(uint8_t *)(result + 37);
  if ( *(uint8_t *)(result + 37) )
  {
    v3 = result;
    ke_event_lock(off_11B678, *((uint32_t *)off_11B67C + 4) + 5000);
    return phy_channel_configure(*(uint8_t *)(v3 + 35), 0, 2500, 37, 5u, 2u, 0, 0);
  }
  else
  {
    v2 = off_11B678;
    *((uint32_t *)off_11B678 + 1) = v1;
    v2[2] = v1;
  }
  return result;
}

