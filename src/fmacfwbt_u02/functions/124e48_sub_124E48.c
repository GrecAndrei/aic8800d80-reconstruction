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

// set_cfg_flag @ 0x124e48, size 140 bytes
int  set_cfg_flag(uint8_t *a1)
{
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(uint8_t *)off_124ED4 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    LOBYTE(((uint32_t *)(uintptr_t)off_124ED8)[102]) = v1 & 0x10;
  if ( a1[1] )
    *(uint32_t *)off_124EDC = a1[1] | *(uint32_t *)off_124EDC & 0xFFFFFF00;
  if ( a1[2] )
    *(uint32_t *)off_124EE0 = a1[2] | *(uint32_t *)off_124EE0 & 0xFFFFFF00;
  if ( a1[3] )
    *(uint32_t *)off_124EDC = *(uint32_t *)off_124EDC & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(uint32_t *)off_124EE0 = *(uint32_t *)off_124EE0 & 0xFFF00FFF | (a1[4] << 12);
  ke_event_schedule_1(aSetVendorCca);
  return rx_packet_handler_2((int)a1, 5, 1, 0);
}
