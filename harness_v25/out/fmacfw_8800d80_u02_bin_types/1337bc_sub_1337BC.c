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

extern uint32_t off_1337F0;
extern uint32_t dword_1337F8;
extern uint32_t dword_1337F4;

// sub_1337BC @ 0x1337bc, size 52 bytes
int  sub_1337BC(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_1337F0 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_134DF0(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_1337F8, dword_1337F4, 1038);
    sub_134DF0(v2);
    return 0;
  }
}

