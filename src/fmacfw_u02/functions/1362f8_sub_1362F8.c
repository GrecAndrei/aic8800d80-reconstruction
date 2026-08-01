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

extern uint32_t off_13632C;
extern uint32_t dword_136334;
extern uint32_t dword_136330;

// bt_hci_reset @ 0x1362f8, size 52 bytes
// Doc: sub_12362F8 [util]: Checks a global state value and branches on result
// sub_12362F8 [util]: Checks a global state value and branches on result
int  bt_hci_reset(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_13632C >= 0 || (value = rx_rate_field_parse(7u), value == 1) )
  {
    bt_ready_check(value);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_136334, dword_136330, 311);
    bt_ready_check(v2);
    return 0;
  }
}

