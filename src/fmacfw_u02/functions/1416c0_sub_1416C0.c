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

extern uint32_t dword_14172C;

// ll_event_remove @ 0x1416c0, size 106 bytes
uint32_t * ll_event_remove(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  uint32_t *result; // r0

  if ( a2 )
  {
    v2 = dword_14172C;
    v4 = *(uint32_t *)(dword_14172C + 6480);
    if ( ble_ll_adv_chk_active() )
    {
      if ( rx_rate_field_parse(0xBu) == 3 )
        return (uint32_t *)ll_event_process();
      else
        return ll_event_counter_inc();
    }
    else
    {
      *(uint8_t *)(a1 + 98) = 1;
      ble_ll_adv_event_start(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (uint32_t *)tx_path_status(a1, 3);
    }
  }
  else
  {
    result = rx_phy_status_parse(0xBu, 0);
    *(uint32_t *)(dword_14172C + 6480) = -1;
  }
  return result;
}

