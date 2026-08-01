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

extern uint32_t off_133A50;

// handle_state_five @ 0x133a08, size 72 bytes
int handle_state_five()
{
  if ( rx_rate_field_parse(6u) != 5 && rx_rate_field_parse(6u) != 6 && rx_rate_field_parse(6u) != 7 && rx_rate_field_parse(6u) != 8 )
    return 0;
  if ( *((uint8_t *)off_133A50 + 34) )
  {
    *((uint8_t *)off_133A50 + 34) = 0;
    return 0;
  }
  bt_setup_conn_profile(1);
  return 0;
}

