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

extern uint32_t off_1404A4;
extern uint32_t dword_1404AC;
extern uint32_t dword_1404A8;

// ble_ll_scan_enable @ 0x140470, size 50 bytes
int ble_ll_scan_enable()
{
  if ( rx_rate_field_parse(0xBu) == 4 )
  {
    ll_event_schedule();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_1404A4 < 0 )
      call_shared_handler(dword_1404AC, dword_1404A8, 129);
    return 0;
  }
}

