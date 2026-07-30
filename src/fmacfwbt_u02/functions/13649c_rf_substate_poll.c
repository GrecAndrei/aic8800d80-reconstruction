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

extern uint32_t off_1364F8;
extern uint32_t dword_136500;
extern uint32_t dword_1364FC;

// rf_substate_poll @ 0x13649c, size 90 bytes
// Doc: rf_substate_poll [rf]: Poll signed halfword RF sub-state and branch
// rf_substate_poll [rf]: Poll signed halfword RF sub-state and branch
int rf_substate_poll()
{
  int value; // r0

  if ( **(int16_t **)off_1364F8 < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F694(dword_136500, dword_1364FC, 274);
  value = msg_get_value(7u);
  if ( value != 1 )
  {
    value = msg_get_value(7u);
    if ( value != 3 )
      return 0;
  }
  sub_13697C(value);
  return 0;
}

