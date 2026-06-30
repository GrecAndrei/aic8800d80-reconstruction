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

extern uint32_t off_13632C;
extern uint32_t dword_136334;
extern uint32_t dword_136330;

// sub_1362F8 @ 0x1362f8, size 52 bytes
// Doc: sub_12362F8 [util]: Checks a global state value and branches on result
// sub_12362F8 [util]: Checks a global state value and branches on result
int  sub_1362F8(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_13632C >= 0 || (value = msg_get_value(7u), value == 1) )
  {
    sub_136820(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_136334, dword_136330, 311);
    sub_136820(v2);
    return 0;
  }
}

