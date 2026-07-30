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

extern uint32_t off_133954;
extern uint32_t dword_13395C;
extern uint32_t dword_133958;

// sub_133920 @ 0x133920, size 52 bytes
// Doc: sub_1233920 [util]: Check global signed status word and branch
// sub_1233920 [util]: Check global signed status word and branch
int  sub_133920(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_133954 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_13395C, dword_133958, 871);
    sub_1347BC(v2);
    return 0;
  }
}

