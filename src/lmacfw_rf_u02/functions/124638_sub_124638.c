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

extern uint32_t off_124664;
extern uint32_t off_124668;

// ke_stop_event_81 @ 0x124638, size 44 bytes
// Doc: sub_1224640 [util]: Periodic counter increment utility, resets at threshold 0x64
// sub_1224640 [util]: Periodic counter increment utility, resets at threshold 0x64
int ke_stop_event_81()
{
  uint16_t *v0; // r4
  int result; // r0
  int v2; // r3

  if ( *(uint8_t *)off_124664 )
  {
    v0 = off_124668;
    result = ke_handle_message(0x81u);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 100 )
    {
      result = rf_set_flag(4);
      *v0 = 0;
    }
  }
  return result;
}

