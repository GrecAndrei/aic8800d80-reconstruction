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

extern uint32_t off_133C18;
extern uint32_t dword_133C20;
extern uint32_t dword_133C1C;

// sub_133BE4 @ 0x133be4, size 52 bytes
int  sub_133BE4(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_133C18 >= 0 || (value = msg_get_value(6u), value == 4) )
  {
    sub_1349D8(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133C20, dword_133C1C, 670);
    sub_1349D8(v2);
    return 0;
  }
}

