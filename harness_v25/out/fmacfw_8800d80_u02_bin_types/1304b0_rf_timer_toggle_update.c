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

extern uint32_t dword_1304F0;
extern uint32_t off_1304F4;

// rf_timer_toggle_update @ 0x1304b0, size 62 bytes
// Doc: rf_timer_toggle_update [rf]: Update RF timer toggle value via float-to-int conversion
// rf_timer_toggle_update [rf]: Update RF timer toggle value via float-to-int conversion
unsigned int rf_timer_toggle_update()
{
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(rf_hw_timer_read());
  msg_parse(dword_1304F0, v0);
  v1 = (char)v0 - *((char *)off_1304F4 + 3);
  if ( v1 < 0 )
    v1 = *((char *)off_1304F4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((uint8_t *)off_1304F4 + 3) = v0;
    rf_level_compute((char)v0);
  }
  return rf_level_step_02c4();
}

