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

extern uint32_t off_12F0BC;
extern uint32_t dword_12F0C0;
extern uint32_t off_12F0C4;

// rf_timer_toggle @ 0x12f060, size 90 bytes
// Doc: rf_timer_toggle [rf]: Toggle RF timer state
// rf_timer_toggle [rf]: Toggle RF timer state
int rf_timer_toggle()
{
  uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12F0BC;
  v1 = event_queue_push(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    rf_timer_toggle_start();
    timer_set_relative(1070, 1, dword_12F0C0);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_timer_toggle_update(v1);
      timer_set_relative(1070, 1, 1000 * *((uint32_t *)off_12F0C4 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

