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

extern uint32_t dword_124C68;
extern uint32_t off_124C58;
extern uint32_t dword_124C6C;
extern uint32_t off_124C5C;
extern uint32_t off_124C60;
extern uint32_t dword_124C64;

// sub_124B04 @ 0x124b04, size 338 bytes
int  sub_124B04(int a1, int a2)
{
  uint8_t v3; // r0
  unsigned int v4; // r4
  int v5; // r3
  uint32_t *v6; // r1
  unsigned int v8; // r5
  uint64_t v9; // [sp+4h] [bp-18h] BYREF
  char v10; // [sp+Ch] [bp-10h] BYREF
  uint8_t v11; // [sp+Dh] [bp-Fh]
  uint16_t v12; // [sp+Eh] [bp-Eh]
  uint16_t v13; // [sp+10h] [bp-Ch]
  int16_t v14; // [sp+12h] [bp-Ah]
  char v15; // [sp+16h] [bp-6h]

  v3 = sub_121E3C(*(uint8_t **)(a2 + 4), 0, 0xAu);
  if ( a1 <= 1 || (v4 = v3) == 0 )
  {
    sub_11F504(dword_124C68);
    return -1;
  }
  *(uint32_t *)off_124C58 |= 0x500000u;
  sub_1019EC(&v9, 0);
  if ( v4 <= 0x23 )
  {
    v5 = BYTE1(v9);
    v10 = 0;
    v11 = BYTE1(v9);
    if ( v4 > 0xD )
    {
      if ( v4 != 14 )
      {
        sub_11F504(dword_124C6C, v4, (uint32_t)v9);
        return -2;
      }
      v13 = 2484;
      v14 = 0;
      v15 = 0;
      if ( !BYTE1(v9) )
        goto LABEL_6;
LABEL_13:
      v8 = WORD1(v9);
      if ( v5 == 1 )
      {
        if ( v8 < WORD2(v9) )
          goto LABEL_21;
      }
      else
      {
        if ( v5 != 2 )
          goto LABEL_7;
        if ( (int)(v8 + 20) < WORD2(v9) )
        {
          v12 = v13 - 30;
          goto LABEL_7;
        }
        if ( v8 < WORD2(v9) )
        {
LABEL_21:
          v12 = v13 - 10;
          goto LABEL_7;
        }
        if ( WORD2(v9) < (int)(v8 - 19) )
        {
          v12 = v13 + 30;
          goto LABEL_7;
        }
      }
      v12 = v13 + 10;
      goto LABEL_7;
    }
    v13 = 5 * v4 + 2407;
  }
  else
  {
    v5 = BYTE1(v9);
    v13 = 5 * v4 + 5000;
    v10 = 1;
    v11 = BYTE1(v9);
  }
  v14 = 0;
  v15 = 0;
  if ( v5 )
    goto LABEL_13;
LABEL_6:
  v12 = v13;
LABEL_7:
  *(uint8_t *)off_124C5C = 1;
  sub_1246F0(0, (int)&v10);
  v6 = off_124C60;
  *(uint32_t *)off_124C58 &= 0xFF87FFFF;
  if ( *v6 )
    sub_1268EC(*v6);
  sub_11F504(dword_124C64, v4, v13, v11);
  return 0;
}

