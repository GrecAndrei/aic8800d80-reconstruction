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

extern uint32_t off_124ED4;
extern uint32_t off_124ED8;
extern uint32_t off_124EDC;
extern uint32_t off_124EE0;
extern uint32_t dword_124EE4;

// set_cfg_flag @ 0x124e48, size 140 bytes
int  set_cfg_flag(uint8_t *a1, void *a2)
{
  int v2; // r3
  unsigned int v3; // r2

  v2 = *a1;
  v3 = v2 << 28;
  if ( v2 << 28 )
  {
    v3 = (unsigned int)off_124ED4;
    a2 = (void *)(v2 & 1);
    *(uint8_t *)off_124ED4 = v2 & 1;
  }
  if ( (v2 & 0xF0) != 0 )
  {
    v3 = (unsigned int)off_124ED8;
    *((uint8_t *)off_124ED8 + 408) = v2 & 0x10;
  }
  if ( a1[1] )
  {
    a2 = off_124EDC;
    v3 = *(uint32_t *)off_124EDC & 0xFFFFFF00;
    *(uint32_t *)off_124EDC = a1[1] | v3;
  }
  if ( a1[2] )
  {
    a2 = off_124EE0;
    v3 = *(uint32_t *)off_124EE0 & 0xFFFFFF00;
    *(uint32_t *)off_124EE0 = a1[2] | v3;
  }
  if ( a1[3] )
  {
    a2 = off_124EDC;
    v3 = *(uint32_t *)off_124EDC & 0xFFF00FFF;
    *(uint32_t *)off_124EDC = v3 | (a1[3] << 12);
  }
  if ( a1[4] )
  {
    a2 = off_124EE0;
    v3 = *(uint32_t *)off_124EE0 & 0xFFF00FFF;
    *(uint32_t *)off_124EE0 = v3 | (a1[4] << 12);
  }
  ke_event_schedule(dword_124EE4, a2, v3);
  return rx_packet_handler(a1, 5, 1, 0);
}

