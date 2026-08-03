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

extern uint32_t dword_12FDCC;
extern uint32_t dword_12FDD8;
extern uint32_t dword_12FDDC;
extern uint32_t dword_12FDD0;
extern uint32_t dword_12FDD4;

// sub_12FD64 @ 0x12fd64, size 104 bytes
int  sub_12FD64(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = sub_12F818(*(uint8_t **)(a2 + 4), 0, 0)) == 0 )
  {
    v5 = sub_12E910();
    sub_12E948(dword_12FDCC, v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      sub_12E948(dword_12FDD8);
    }
    else
    {
      v7 = sub_12F818(*(uint8_t **)(a2 + 8), 0, 0);
      if ( v7 > 5 )
      {
        sub_12E948(dword_12FDDC, v7);
      }
      else
      {
        sub_12E948(dword_12FDD0, v7);
        sub_12E8F8(v7);
      }
    }
    return 0;
  }
  sub_12E948(dword_12FDD4);
  return 0;
}

