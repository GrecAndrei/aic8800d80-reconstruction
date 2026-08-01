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

extern uint32_t off_140500;
extern uint32_t dword_140508;
extern uint32_t dword_140504;

// check_controller_ready @ 0x1404cc, size 50 bytes
// Doc: check_controller_ready [bt]: Check/issue HCI command with id 0xb and verify result
// check_controller_ready [bt]: Check/issue HCI command with id 0xb and verify result
int check_controller_ready()
{
  if ( hci_cmd_send_short(0xBu) == 1 )
  {
    check_tx_power_valid();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140500 < 0 )
      mmio_field_update(dword_140508, dword_140504, 157);
    return 0;
  }
}

