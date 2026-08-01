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

extern uint32_t off_1245DC;
extern uint32_t off_1245E0;
extern uint32_t off_1245EC;
extern uint32_t off_1245E4;
extern uint32_t off_1245E8;

// ke_state_event_1 @ 0x124594, size 72 bytes
// Doc: sub_1224594 [unknown]: Check shared init flag byte and branch on ready state
// sub_1224594 [unknown]: Check shared init flag byte and branch on ready state
int ke_state_event_1()
{
  uint16_t *v0; // r4
  int result; // r0
  int v2; // r3
  uint32_t *v3; // r2
  int v4; // r0

  if ( *(uint8_t *)off_1245DC != 1 )
  {
    v0 = off_1245E0;
    result = ke_handle_message(1u);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 1000 )
    {
      rf_set_flag(3);
      v3 = off_1245EC;
      v4 = *(uint32_t *)off_1245E4 + 19968;
      *(uint32_t *)off_1245E8 = 0;
      *v0 = 0;
      *v3 = 0;
      return mmio_write_register(v4 + 32);
    }
  }
  return result;
}

