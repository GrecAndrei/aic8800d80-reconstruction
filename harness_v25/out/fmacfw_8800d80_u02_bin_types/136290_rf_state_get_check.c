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

extern uint32_t off_1362EC;
extern uint32_t dword_1362F4;
extern uint32_t dword_1362F0;

// rf_state_get_check @ 0x136290, size 90 bytes
// Doc: rf_state_get_check [rf]: Read shared RF state word and branch on sign
// rf_state_get_check [rf]: Read shared RF state word and branch on sign
int rf_state_get_check()
{
  int value; // r0

  if ( **(int16_t **)off_1362EC < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F46C(dword_1362F4, dword_1362F0, 274);
  value = msg_get_value(7u);
  if ( value != 1 )
  {
    value = msg_get_value(7u);
    if ( value != 3 )
      return 0;
  }
  sub_136820(value);
  return 0;
}

