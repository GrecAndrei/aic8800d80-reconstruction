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

extern uint32_t off_1339FC;
extern uint32_t dword_133A04;
extern uint32_t dword_133A00;

// check_state_and_call @ 0x1339c8, size 52 bytes
int  check_state_and_call(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_1339FC >= 0 || (value = rx_rate_field_parse(6u), value == 4) )
  {
    bt_is_controller_ready(value);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_133A04, dword_133A00, 670);
    bt_is_controller_ready(v2);
    return 0;
  }
}

