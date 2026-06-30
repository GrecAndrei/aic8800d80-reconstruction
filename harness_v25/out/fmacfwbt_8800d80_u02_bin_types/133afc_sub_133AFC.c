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

extern uint32_t off_133B30;
extern uint32_t dword_133B38;
extern uint32_t dword_133B34;

// sub_133AFC @ 0x133afc, size 52 bytes
int  sub_133AFC(int a1)
{
  int v2; // r0

  if ( **(int16_t **)off_133B30 >= 0 || (a1 = sub_12D0B0(6u), a1 == 10) )
  {
    sub_1349D8(a1);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133B38, dword_133B34, 898);
    sub_1349D8(v2);
    return 0;
  }
}

