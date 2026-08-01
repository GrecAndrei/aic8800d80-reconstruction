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

extern uint32_t off_1246DC;
extern uint32_t off_1246EC;
extern uint32_t off_1246E0;
extern uint32_t off_1246E8;
extern uint32_t off_1246E4;

// util_alloc_buffer @ 0x12466c, size 112 bytes
void util_alloc_buffer()
{
  int v0; // r0

  v0 = enter_critical_section(0x2000);
  if ( rf_flag_is_set(v0) )
  {
    switch ( *(uint8_t *)off_1246DC )
    {
      case 1:
        ke_state_event_0();
        break;
      case 2:
        ke_state_event_1();
        break;
      case 3:
        ke_stop_event_81();
        break;
      case 4:
        if ( *(uint8_t *)off_1246EC != 1 )
          ke_timer_tick();
        break;
      case 5:
        ke_start_event_80();
        break;
      default:
        return;
    }
  }
  else if ( *(uint32_t *)off_1246E0 )
  {
    if ( !*(uint8_t *)off_1246E8 )
      wait_for_state();
  }
  else
  {
    *(uint32_t *)off_1246E4 = 0;
  }
}

