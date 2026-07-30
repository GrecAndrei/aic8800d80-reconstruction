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

extern uint32_t off_1339FC;
extern uint32_t dword_133A04;
extern uint32_t dword_133A00;

// sub_1339C8 @ 0x1339c8, size 52 bytes
int  sub_1339C8(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_1339FC >= 0 || (value = msg_get_value(6u), value == 4) )
  {
    sub_1347BC(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_133A04, dword_133A00, 670);
    sub_1347BC(v2);
    return 0;
  }
}

