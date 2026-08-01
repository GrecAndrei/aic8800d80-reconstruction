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

extern uint32_t off_127598;
extern uint32_t off_12759C;

// set_advertising_flag @ 0x127568, size 48 bytes
int set_advertising_flag()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_127598;
  if ( (*((uint8_t *)off_127598 + 88) & 0x10) == 0 )
  {
    v1 = *((uint8_t *)off_127598 + 90);
    *((uint8_t *)off_127598 + 88) |= 0x10u;
    if ( v1 )
      return ke_event_lock((int)v0 + 48, *((uint32_t *)off_12759C + 4) + 30000);
    else
      return read_rssi();
  }
  return result;
}

