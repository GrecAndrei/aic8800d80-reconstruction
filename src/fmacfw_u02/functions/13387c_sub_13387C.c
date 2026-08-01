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

// hci_evt_parse_opcode @ 0x13387c, size 98 bytes
// Doc: sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
// sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
int  hci_evt_parse_opcode(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( rx_rate_field_parse(6u) == 5 )
        bt_send_acl_event(a2);
      break;
    case 16:
    case 48:
      if ( rx_rate_field_parse(6u) == 8 )
        bt_send_profile_cmd(a2);
      break;
    case 192:
    case 160:
      return timer_set_relative_5668(a2);
    default:
      if ( v2 == 208 && *(uint8_t *)(a2 + 12) == 8 )
        bt_get_conn_by_index(a2);
      break;
  }
  return 0;
}

