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

extern uint32_t off_1339BC;
extern uint32_t dword_1339C4;
extern uint32_t dword_1339C0;

// check_state_flag @ 0x133960, size 90 bytes
int check_state_flag()
{
  int value; // r0

  if ( **(int16_t **)off_1339BC < 0 && rx_rate_field_parse(6u) != 4 && rx_rate_field_parse(6u) && rx_rate_field_parse(6u) != 10 )
    mmio_clear_register(dword_1339C4, dword_1339C0, 636);
  value = rx_rate_field_parse(6u);
  if ( value != 4 )
  {
    value = rx_rate_field_parse(6u);
    if ( value != 10 )
      return 0;
  }
  bt_is_controller_ready(value);
  return 0;
}

