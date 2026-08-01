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

extern uint32_t dword_13B70C;
extern uint32_t dword_13B708;

// rf_is_ready @ 0x13b6d4, size 50 bytes
// Doc: sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
// sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
int  rf_is_ready(int a1, int a2, unsigned int a3)
{
  if ( hci_cmd_send_short(a3) == 2 )
  {
    rf_get_chan_cfg(a3 >> 8);
    check_abort_flag(dword_13B70C, (uint32_t *)(dword_13B708 + 32 * (a3 >> 8)));
    hci_cmd_send(a3, 0);
  }
  return 0;
}

