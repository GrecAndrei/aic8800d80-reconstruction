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

extern uint32_t dword_1417C8;

// start_advertising @ 0x14175c, size 106 bytes
uint32_t * start_advertising(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  uint32_t *result; // r0

  if ( a2 )
  {
    v2 = dword_1417C8;
    v4 = *(uint32_t *)(dword_1417C8 + 6480);
    if ( is_controller_ready() )
    {
      if ( hci_cmd_send_short(0xBu) == 3 )
        return (uint32_t *)check_tx_power_valid();
      else
        return increment_event_counter();
    }
    else
    {
      *(uint8_t *)(a1 + 98) = 1;
      hci_le_set_scan_params(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (uint32_t *)ble_event_dispatch(a1, 3);
    }
  }
  else
  {
    result = hci_cmd_send(0xBu, 0);
    *(uint32_t *)(dword_1417C8 + 6480) = -1;
  }
  return result;
}

