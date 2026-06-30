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

extern uint32_t dword_126818;
extern uint32_t off_12681C;
extern uint32_t dword_126820;

// bt_event_handler @ 0x1267e0, size 56 bytes
// Doc: bt_event_handler [bt]: BT firmware event/task handler
// bt_event_handler [bt]: BT firmware event/task handler
int bt_event_handler()
{
  int result; // r0
  uint32_t *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = rf_bus_mark_n100_d2d0(dword_126818);
  if ( result )
  {
    v1 = off_12681C;
    timestamp_remove(dword_126820);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      list_push_tail(v2);
      result = rf_bus_mark_n100_d2d0(v3);
    }
    while ( result );
  }
  return result;
}

