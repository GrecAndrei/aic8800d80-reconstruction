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

extern uint32_t off_14229C;
extern uint32_t dword_1422A0;

// sub_1421F8 @ 0x1421f8, size 162 bytes
int  sub_1421F8(int result, int16_t a2, uint16_t *a3)
{
  uint8_t *v3; // r6
  int16_t v4; // r2
  int v5; // r3
  int v6; // r4
  int v7; // r1
  int v8; // r5
  uint32_t *v9; // r5
  uint32_t *v10; // r4
  int16_t *v11; // t1
  int16_t v12; // r3
  int v13; // r3
  uint32_t _0[12]; // [sp+0h] [bp-20h] BYREF

  v3 = off_14229C;
  if ( (*a3 & 0x300) == 0x300 )
    v4 = a3[15];
  else
    v4 = a3[12];
  if ( *((uint8_t *)off_14229C + 1) )
  {
    if ( (a2 & 0x88) == 0x88 )
    {
      if ( (v4 & 0x10) == 0 )
        return result;
    }
    else if ( (a2 & 0x2000) == 0 )
    {
      return result;
    }
    v5 = dword_1422A0;
    v6 = *(uint8_t *)(result + 116);
    result = *(uint8_t *)(result + 107);
    v7 = dword_1422A0 + 576;
    v8 = 0;
    do
    {
      while ( (*(uint16_t *)v5 & 1) == 0 || *(uint8_t *)(v5 + 47) != result || *(uint8_t *)(v5 + 46) != v6 )
      {
        v5 += 72;
        if ( v5 == v7 )
          goto LABEL_13;
      }
      _0[v8] = v5;
      v5 += 72;
      v8 = (uint8_t)(v8 + 1);
    }
    while ( v5 != v7 );
LABEL_13:
    if ( v8 )
    {
      v9 = &_0[(uint8_t)(v8 - 1)];
      v10 = &_0[-1];
      do
      {
        v11 = (int16_t *)v10[1];
        ++v10;
        result = (int)v11;
        v12 = *v11;
        if ( (*v11 & 8) != 0 )
        {
          v13 = v12 & 9;
          if ( v3[1] )
          {
            if ( v13 == 9 )
              result = (int)sub_141D08(result);
          }
        }
      }
      while ( v10 != v9 );
    }
  }
  return result;
}

