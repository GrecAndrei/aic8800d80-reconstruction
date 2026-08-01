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

extern uint32_t off_12451C;

// ke_timer_tick @ 0x1244f8, size 36 bytes
// Doc: ke_timer_tick [util]: Dispatches log free with rotated value, likely a logger release
// ke_timer_tick [util]: Dispatches log free with rotated value, likely a logger release
int ke_timer_tick()
{
  int result; // r0
  int v1; // r3

  result = ke_handle_message(2u);
  v1 = (uint16_t)(*(uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(uint16_t *)off_12451C = 0;
    return ll_state_reset(result);
  }
  else
  {
    *(uint16_t *)off_12451C = v1;
  }
  return result;
}

