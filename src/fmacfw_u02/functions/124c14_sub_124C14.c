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


extern uint32_t off_124CA0;
extern uint32_t off_124CA4;
extern uint32_t off_124CA8;
extern uint32_t off_124CAC;

// util_get_flag @ 0x124c14, size 140 bytes
int  util_get_flag(uint8_t *a1)
{
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(uint8_t *)off_124CA0 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    LOBYTE(((uint32_t *)(uintptr_t)off_124CA4)[102]) = v1 & 0x10;
  if ( a1[1] )
    *(uint32_t *)off_124CA8 = a1[1] | *(uint32_t *)off_124CA8 & 0xFFFFFF00;
  if ( a1[2] )
    *(uint32_t *)off_124CAC = a1[2] | *(uint32_t *)off_124CAC & 0xFFFFFF00;
  if ( a1[3] )
    *(uint32_t *)off_124CA8 = *(uint32_t *)off_124CA8 & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(uint32_t *)off_124CAC = *(uint32_t *)off_124CAC & 0xFFF00FFF | (a1[4] << 12);
  event_dispatch(aSetVendorCca);
  return send_msg((int)a1, 5, 1, 0);
}
