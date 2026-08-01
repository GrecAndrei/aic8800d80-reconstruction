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

extern uint32_t off_136408;
extern uint32_t dword_136418;
extern uint32_t dword_136410;
extern uint32_t off_13640C;
extern uint32_t dword_136414;

// bt_cmd_guard_alt @ 0x13637c, size 140 bytes
int bt_cmd_guard_alt()
{
  int16_t **v0; // r4

  v0 = (int16_t **)off_136408;
  if ( **(int16_t **)off_136408 < 0 && rx_rate_field_parse(7u) != 1 && rx_rate_field_parse(7u) && rx_rate_field_parse(7u) != 3 )
    mmio_clear_register(dword_136418, dword_136410, 341);
  if ( rx_rate_field_parse(7u) == 1 )
  {
    if ( **v0 < 0 && *((uint32_t *)off_13640C + 1) )
      mmio_clear_register(dword_136414, dword_136410, 349);
    ke_send_event_0x3f();
  }
  else if ( rx_rate_field_parse(7u) == 3 )
  {
    ke_msg_send_no_param(7171, 13, 7);
    rx_phy_status_parse(7u, 0);
  }
  return 0;
}

