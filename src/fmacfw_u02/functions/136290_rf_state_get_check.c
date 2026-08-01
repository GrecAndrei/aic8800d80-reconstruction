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

extern uint32_t off_1362EC;
extern uint32_t dword_1362F4;
extern uint32_t dword_1362F0;

// bt_cmd_guard @ 0x136290, size 90 bytes
// Doc: bt_cmd_guard [rf]: Read shared RF state word and branch on sign
// bt_cmd_guard [rf]: Read shared RF state word and branch on sign
int bt_cmd_guard()
{
  int value; // r0

  if ( **(int16_t **)off_1362EC < 0 && rx_rate_field_parse(7u) != 1 && rx_rate_field_parse(7u) && rx_rate_field_parse(7u) != 3 )
    mmio_clear_register(dword_1362F4, dword_1362F0, 274);
  value = rx_rate_field_parse(7u);
  if ( value != 1 )
  {
    value = rx_rate_field_parse(7u);
    if ( value != 3 )
      return 0;
  }
  bt_ready_check(value);
  return 0;
}

