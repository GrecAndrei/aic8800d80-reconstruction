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

extern uint32_t off_140464;
extern uint32_t dword_14046C;
extern uint32_t dword_140468;

// ble_ll_adv_enable @ 0x140430, size 50 bytes
// Doc: ble_ll_adv_enable [ipc]: Queries firmware command status (op 0xb)
// ble_ll_adv_enable [ipc]: Queries firmware command status (op 0xb)
int ble_ll_adv_enable()
{
  if ( rx_rate_field_parse(0xBu) == 1 )
  {
    ll_event_process();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140464 < 0 )
      call_shared_handler(dword_14046C, dword_140468, 157);
    return 0;
  }
}

