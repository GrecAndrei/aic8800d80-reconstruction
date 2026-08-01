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

extern uint32_t off_11AA48;
extern uint32_t off_11AA4C;
extern uint32_t off_11AA50;
extern uint32_t off_11AA54;
extern uint32_t dword_11AA58;

// flag_update @ 0x11a9bc, size 140 bytes
int  flag_update(uint8_t *a1, void *a2)
{
  int v2; // r3

  v2 = *a1;
  if ( v2 << 28 )
  {
    a2 = (void *)(v2 & 1);
    *(uint8_t *)off_11AA48 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
    *((uint8_t *)off_11AA4C + 408) = v2 & 0x10;
  if ( a1[1] )
  {
    a2 = off_11AA50;
    *(uint32_t *)off_11AA50 = a1[1] | *(uint32_t *)off_11AA50 & 0xFFFFFF00;
  }
  if ( a1[2] )
  {
    a2 = off_11AA54;
    *(uint32_t *)off_11AA54 = a1[2] | *(uint32_t *)off_11AA54 & 0xFFFFFF00;
  }
  if ( a1[3] )
  {
    a2 = off_11AA50;
    *(uint32_t *)off_11AA50 = *(uint32_t *)off_11AA50 & 0xFFF00FFF | (a1[3] << 12);
  }
  if ( a1[4] )
  {
    a2 = off_11AA54;
    *(uint32_t *)off_11AA54 = *(uint32_t *)off_11AA54 & 0xFFF00FFF | (a1[4] << 12);
  }
  dispatch_event_handler(dword_11AA58, a2);
  return handle_ipc_request(a1, 5, 1, 0);
}

