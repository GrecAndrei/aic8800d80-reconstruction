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

extern uint32_t off_13643C;
extern uint32_t dword_136444;
extern uint32_t dword_136440;

// sub_136408 @ 0x136408, size 52 bytes
// Doc: sub_1236408 [util]: Check shared half-word status flag from globals table and branch
// sub_1236408 [util]: Check shared half-word status flag from globals table and branch
int  sub_136408(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_13643C >= 0 || (value = msg_get_value(7u), value == 3) )
  {
    sub_13697C(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_136444, dword_136440, 415);
    sub_13697C(v2);
    return 0;
  }
}

