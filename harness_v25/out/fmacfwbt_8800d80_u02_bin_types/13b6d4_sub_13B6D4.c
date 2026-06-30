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

// sub_13B6D4 @ 0x13b6d4, size 50 bytes
// Doc: sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
// sub_123B6D4 [bt]: Helper in BT firmware, dispatches based on return value
int  sub_13B6D4(int a1, int a2, unsigned int a3)
{
  if ( msg_get_value(a3) == 2 )
  {
    rx_entry_lookup(a3 >> 8);
    list_push_tail(dword_13B70C, (uint32_t *)(dword_13B708 + 32 * (a3 >> 8)));
    rf_bus_mark_n_3b7(a3, 0);
  }
  return 0;
}

