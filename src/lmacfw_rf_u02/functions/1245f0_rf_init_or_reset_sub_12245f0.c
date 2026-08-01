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

extern uint32_t off_12462C;
extern uint32_t off_124630;
extern uint32_t off_124634;

// ke_start_event_80 @ 0x1245f0, size 60 bytes
// Doc: ke_start_event_80 [rf]: Trigger RF subsystem reset/initialization (param 0x80) via internal handler
// ke_start_event_80 [rf]: Trigger RF subsystem reset/initialization (param 0x80) via internal handler
int ke_start_event_80()
{
  uint16_t *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r0

  if ( *(uint8_t *)off_12462C )
  {
    v0 = off_124630;
    result = ke_handle_message(0x80u);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 10 )
    {
      rf_set_flag(1);
      v3 = *(uint32_t *)off_124634 + 39936;
      *v0 = 0;
      return mmio_write_register(v3 + 64);
    }
  }
  return result;
}

