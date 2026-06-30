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

extern uint32_t off_136538;
extern uint32_t dword_136540;
extern uint32_t dword_13653C;

// sub_136504 @ 0x136504, size 52 bytes
// Doc: sub_1236504 [util]: Loads a signed halfword from a global pointer table
// sub_1236504 [util]: Loads a signed halfword from a global pointer table
int  sub_136504(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_136538 >= 0 || (value = msg_get_value(7u), value == 1) )
  {
    sub_13697C(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_136540, dword_13653C, 311);
    sub_13697C(v2);
    return 0;
  }
}

