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

extern uint32_t off_12C4E4;

// rf_get_rssi @ 0x12c4c8, size 26 bytes
// Doc: rf_cmd_dispatch_n2aa [rf]: Dispatches RF command to lower RF layer
// rf_cmd_dispatch_n2aa [rf]: Dispatches RF command to lower RF layer
int  rf_get_rssi(int a1, uint8_t *a2, uint8_t *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(uint32_t *)off_12C4E4;
  else
    result = (uint8_t)v3;
  if ( v3 == 127 )
    result = (uint8_t)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

