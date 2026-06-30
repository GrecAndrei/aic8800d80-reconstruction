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

extern uint32_t off_1265D0;
extern uint32_t dword_1265C0;
extern uint32_t dword_1265C8;
extern uint32_t dword_1265CC;
extern uint32_t dword_1265C4;

// sub_126444 @ 0x126444, size 378 bytes
int  sub_126444(int a1, int a2, int a3)
{
  uint32_t *v3; // r10
  int v4; // r5
  int v7; // r11
  int v8; // r8
  int v9; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r8
  int v13; // r3
  int result; // r0
  uint32_t *v15; // r9
  int v16; // r4
  int v17; // r4
  unsigned int v18; // r4
  int v19; // r3
  int v20; // zf
  int v21; // r3
  int v22; // r4
  int v23; // [sp+4h] [bp-8h]

  v3 = off_1265D0;
  v23 = a3;
  v4 = dword_1265C0;
  v7 = a1 + 76;
  if ( !a3 )
    goto LABEL_30;
  while ( 1 )
  {
    v8 = *(uint32_t *)(a1 + 72);
    if ( !v3[8] )
      break;
    v15 = (uint32_t *)v3[9];
    v16 = v15[1];
    v17 = v16 + 4000 + sub_101944();
    if ( v8 != v15[2] )
    {
      v17 += 4000 + sub_101944();
      if ( v15[3] )
        v17 += 10000;
    }
    v18 = (unsigned int)(a2 - v17) >> 31;
LABEL_18:
    if ( !v18 )
      goto LABEL_5;
    v11 = 0;
LABEL_20:
    if ( *(uint8_t *)(a1 + 1224) && *(uint8_t *)(dword_1265C8 + 140 * *(uint8_t *)(a1 + 1225) + 112) == 1 )
      sub_126334(a1, a2, v11);
    v19 = *(uint8_t *)(a1 + 106);
    if ( *(uint8_t *)(a1 + 106) )
    {
      v20 = v19 == 2;
      if ( v19 == 2 )
        v21 = *(uint16_t *)(a1 + 222);
      else
        v21 = 102400;
      if ( v20 )
        v21 <<= 10;
    }
    else
    {
      v21 = *(uint32_t *)(dword_1265CC + 696 * *(uint8_t *)(a1 + 116) + 8);
    }
    a2 += v21;
    if ( !++v23 )
    {
LABEL_30:
      if ( (*(uint8_t *)(a1 + 85) & 1) != 0 )
      {
        sub_12D1A8(dword_1265C4, v7);
        *(uint8_t *)(a1 + 85) &= ~1u;
      }
    }
  }
  v9 = v3[20];
  if ( v9 && v8 != v9 )
  {
    v22 = v3[21];
    v18 = (unsigned int)(a2 - v22 - 4000 - sub_101944()) >> 31;
    goto LABEL_18;
  }
LABEL_5:
  *(uint32_t *)(a1 + 80) = a2;
  v10 = sub_101944();
  v11 = v3[4];
  v12 = a2 + 13999 + v10;
  if ( v11 )
  {
    while ( 1 )
    {
      v13 = *(uint32_t *)(v11 + 4);
      if ( v12 - v13 < 0 )
        break;
      if ( *(uint32_t *)(v4 + 1320 * *(uint8_t *)(a1 + 84) + 72) != *(uint32_t *)(v4
                                                                                    + 1320
                                                                                    * *(uint8_t *)(v11 + 8)
                                                                                    + 72) )
      {
        if ( sub_125C88(v7, v11) )
          goto LABEL_20;
        v13 = *(uint32_t *)(v11 + 4);
      }
      if ( a2 - v13 < 0 )
        break;
      v11 = *(uint32_t *)v11;
      if ( !v11 )
        goto LABEL_33;
    }
  }
  else
  {
LABEL_33:
    v11 = 0;
  }
  result = sub_12D2C4(dword_1265C4, v11, v7);
  *(uint8_t *)(a1 + 85) |= 1u;
  return result;
}

