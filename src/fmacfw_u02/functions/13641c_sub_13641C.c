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

extern uint32_t dword_136470;
extern uint32_t dword_136474;

// bt_read_version @ 0x13641c, size 84 bytes
int  bt_read_version(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r4

  check_status_bits(256, dword_136470);
  v7 = dword_136474 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && *(uint8_t *)(v7 + 108) )
  {
    if ( rx_rate_field_parse(7u) )
    {
      return 2;
    }
    else
    {
      rf_send_command_0x1419(v7);
      return 0;
    }
  }
  else
  {
    ke_msg_send_no_param(7171, a4, a3);
    return 0;
  }
}

