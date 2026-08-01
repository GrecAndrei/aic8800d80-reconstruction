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

extern uint32_t off_12457C;
extern uint32_t off_124580;
extern uint32_t off_124584;
extern uint32_t off_124588;
extern uint32_t off_12458C;
extern uint32_t off_124590;

// ke_state_event_0 @ 0x124520, size 90 bytes
void ke_state_event_0()
{
  uint16_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v3; // r3

  if ( *(uint8_t *)off_12457C != 1 )
  {
    v0 = off_124580;
    v1 = ke_handle_message(0);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 1000 )
    {
      if ( (unsigned int)*(uint8_t *)off_124584 - 2 <= 1 )
      {
        *v0 = 0;
        ll_state_reset(v1);
      }
      else
      {
        rf_set_flag(2);
        v3 = *(uint32_t *)off_124588;
        *(uint32_t *)off_12458C = *(uint32_t *)off_124588;
        *v0 = 0;
        *(uint32_t *)off_124590 = v3 + 1000000;
      }
    }
  }
}

