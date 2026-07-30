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

extern uint32_t dword_1051C8;
extern uint32_t dword_1051CC;
extern uint32_t dword_1051C4;

// sub_105118 @ 0x105118, size 168 bytes
int  sub_105118(float a1, int a2, int a3)
{
  float v5; // r0
  int v6; // r0
  uint64_t v7; // r0
  int16_t v8; // r0
  uint64_t v9; // kr00_8
  uint64_t v11; // kr08_8

  v5 = sub_12D3E0(a1 / 20.0);
  v6 = sub_1428B8((float)a2 * v5);
  v7 = sub_1424DC(v6);
  v8 = sub_142E9C(v7, HIDWORD(v7));
  if ( v8 <= 232 )
  {
    if ( v8 > 31 )
    {
      *(uint8_t *)(a3 + 104) = v8;
    }
    else
    {
      v11 = *(uint64_t *)(a3 + 112);
      *(uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v11) < (int)v11 )
        sub_12E948(dword_1051C8, HIDWORD(v11), v11);
    }
  }
  else
  {
    v9 = *(uint64_t *)(a3 + 112);
    *(uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v9) < (int)v9 )
      sub_12E948(dword_1051CC, HIDWORD(v9), v9);
  }
  return sub_12EB90(1, dword_1051C4);
}

