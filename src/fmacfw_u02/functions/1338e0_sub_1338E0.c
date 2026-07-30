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

extern uint32_t off_133914;
extern uint32_t dword_13391C;
extern uint32_t dword_133918;

// sub_1338E0 @ 0x1338e0, size 52 bytes
int  sub_1338E0(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_133914 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_13391C, dword_133918, 898);
    sub_1347BC(v2);
    return 0;
  }
}

