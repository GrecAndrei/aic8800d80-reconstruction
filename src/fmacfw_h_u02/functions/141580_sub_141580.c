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

extern uint32_t dword_1415EC;

// ke_timer_clear @ 0x141580, size 106 bytes
uint32_t * ke_timer_clear(int a1, int a2)
{
  int v2; // r4
  int v4; // r6
  uint32_t *result; // r0

  if ( a2 )
  {
    v2 = dword_1415EC;
    v4 = *(uint32_t *)(dword_1415EC + 6480);
    if ( bt_global_state_read() )
    {
      if ( hci_cmd_handler(0xBu) == 3 )
        return (uint32_t *)ke_timer_check();
      else
        return ke_timer_tick_inc();
    }
    else
    {
      *(uint8_t *)(a1 + 98) = 1;
      acl_tx_setup(a1, 0, 0, v2 + 136 * v4 + 6336);
      return (uint32_t *)sec_check(a1, 3);
    }
  }
  else
  {
    result = hci_cmd_preprocess(0xBu, 0);
    *(uint32_t *)(dword_1415EC + 6480) = -1;
  }
  return result;
}

