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

extern uint32_t off_1339BC;
extern uint32_t dword_1339C4;
extern uint32_t dword_1339C0;

// sub_133960 @ 0x133960, size 90 bytes
int sub_133960()
{
  int value; // r0

  if ( **(int16_t **)off_1339BC < 0 && msg_get_value(6u) != 4 && msg_get_value(6u) && msg_get_value(6u) != 10 )
    sub_12F46C(dword_1339C4, dword_1339C0, 636);
  value = msg_get_value(6u);
  if ( value != 4 )
  {
    value = msg_get_value(6u);
    if ( value != 10 )
      return 0;
  }
  sub_1347BC(value);
  return 0;
}

