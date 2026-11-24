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

// set_tx_power @ 0x124a50, size 46 bytes
int  set_tx_power(int a1, int a2)
{
  int v2; // r4

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130118, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_state_checked((uint16_t)v2);
    dispatch_event_handler_1("\x9A\x88  TX Len  = %d\n", v2);
    return 0;
  }
}
