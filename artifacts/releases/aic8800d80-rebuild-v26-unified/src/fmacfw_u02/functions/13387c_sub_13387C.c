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

// sub_13387C @ 0x13387c, size 98 bytes
// Doc: sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
// sub_12023fc [unknown]: Unknown function in fmacfwbt firmware
int  sub_13387C(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( msg_get_value(6u) == 5 )
        sub_135A00(a2);
      break;
    case 16:
    case 48:
      if ( msg_get_value(6u) == 8 )
        msg_send_cmd_180a(a2);
      break;
    case 192:
    case 160:
      return timer_set_relative_5668(a2);
    default:
      if ( v2 == 208 && *(uint8_t *)(a2 + 12) == 8 )
        sub_135708(a2);
      break;
  }
  return 0;
}

