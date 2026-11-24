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


extern uint32_t dword_11CD10;
extern uint32_t dword_11CD20;
extern uint32_t off_11CD04;
extern uint32_t off_11CD08;
extern uint32_t off_11CD0C;
extern uint32_t off_11CD14;

// sub_11CA18 @ 0x11ca18, size 748 bytes
int  sub_11CA18(int a1, int a2)
{
  uint8_t *v2; // r5
  int v3; // r11
  uint32_t *v4; // r7
  int v5; // r6
  int v7; // r10
  int v8; // r9
  int16_t v9; // r3
  int16_t v10; // r3
  int v11; // r8
  int v12; // r7
  int result; // r0
  int v14; // r9
  unsigned int v15; // r3
  int v16; // r10
  int v17; // r11
  int v18; // r1
  int64_t v19; // kr00_8
  int v20; // r8
  char v21; // r3
  int *v22; // r3
  int *v23; // r2
  int v24; // r1
  int v25; // t1
  unsigned int v26; // r1
  int v27; // r2
  void *v28; // r1
  int v29; // r2
  unsigned int v30; // r2
  int v31; // r0
  int v32; // r2
  unsigned int v33; // r2
  int v34; // [sp+0h] [bp-Ch]
  int *v35; // [sp+4h] [bp-8h]

  v2 = (uint8_t *)off_11CD04;
  v3 = *(uint32_t *)(a1 + 68);
  v4 = *(uint32_t **)(a1 + 76);
  v5 = *((uint8_t *)off_11CD04 + 190);
  v7 = a2;
  if ( (a2 & 0x800000) != 0 )
  {
    sub_11F03C();
    v8 = 9;
    while ( 1 )
    {
      v9 = *(uint16_t *)(v3 + 8);
      if ( (v9 & 0x20) != 0 )
        break;
      sub_11F03C();
      if ( !--v8 )
      {
        v10 = *(uint16_t *)(v3 + 8);
        if ( (v10 & 0x60) != 0x20 )
        {
          if ( (v10 & 0x20) == 0 )
          {
            v11 = dword_11CD20;
            v12 = 84 * v5;
            sub_12D4F8(84 * v5 + 28 + dword_11CD20);
            sub_11A710(v3);
            *(uint32_t *)(a1 + 68) = 0;
            goto LABEL_18;
          }
LABEL_7:
          sub_11A710(v3);
          *(uint32_t *)(a1 + 68) = 0;
          v11 = dword_11CD20;
          v12 = 84 * v5;
          if ( v2[199] )
            goto LABEL_19;
LABEL_8:
          sub_11B8D0(v2[190]);
          sub_12D4F8(v12 + 12 + v11);
          if ( *(uint16_t *)(a1 + 4) )
            return sub_118358((uint32_t *)a1, v7, v5);
          return sub_119120((uint32_t *)a1);
        }
        v7 &= ~0x800000u;
        v4[18] &= ~0x800000u;
        if ( (v10 & 0x20) == 0 )
          goto LABEL_22;
LABEL_31:
        sub_11A710(v3);
        v11 = dword_11CD20;
        *(uint32_t *)(a1 + 68) = 0;
        goto LABEL_12;
      }
    }
    if ( (v9 & 0x60) != 0x20 )
      goto LABEL_7;
    v7 &= ~0x800000u;
    v4[18] &= ~0x800000u;
    goto LABEL_31;
  }
  if ( (*(uint16_t *)(v3 + 8) & 0x20) != 0 )
  {
    v11 = dword_11CD20;
    sub_11A710(*(uint32_t *)(a1 + 68));
    *(uint32_t *)(a1 + 68) = 0;
  }
  else
  {
LABEL_22:
    v11 = dword_11CD20;
    sub_12D4F8(84 * (int16_t)v5 + 28 + dword_11CD20);
    sub_11A710(v3);
    *(uint32_t *)(a1 + 68) = 0;
  }
LABEL_12:
  v14 = BYTE1(v7);
  if ( v2[199] )
  {
    v15 = (HIBYTE(*(uint32_t *)off_11CD08) & 7) + 1;
    if ( v15 >= v2[165] )
      v15 = v2[165];
    *(uint32_t *)off_11CD08 = (v15 << 24) & 0x7000000 | *(uint32_t *)off_11CD08 & 0xF8FFFFFF;
  }
  if ( BYTE1(v7) <= 4u )
  {
    v16 = *(uint32_t *)(a1 + 72);
    if ( v14 )
    {
      v17 = v16 + 44;
    }
    else
    {
      if ( *(uint16_t *)(a1 + 4) )
      {
        v22 = *(int **)(a1 + 44);
        v17 = v16 + 44;
        v23 = v22;
        v24 = v16 + 40;
        do
        {
          v25 = *v23++;
          *(uint32_t *)(v24 + 4) = v25;
          v24 += 4;
        }
        while ( v22 + 16 != v23 );
        if ( (*(uint16_t *)(a1 + 30) & 0x2000) != 0 )
        {
          v34 = *(uint32_t *)(dword_11CD10 + 696 * *(uint8_t *)(a1 + 29) + 340);
          if ( **(int16_t **)off_11CD0C < 0 && !*(uint32_t *)(dword_11CD10 + 696 * *(uint8_t *)(a1 + 29) + 340) )
          {
            v35 = v22;
            sub_12F694((int)aRcSsNull, (int)aRcGetStaStats_1, 475);
            v22 = v35;
          }
          v26 = *(uint32_t *)(v34 + 156);
          *(uint32_t *)(v16 + 68) = v22[5];
          v27 = *(uint32_t *)(v34 + 160);
          *(uint32_t *)(v16 + 84) = v22[9];
          *(uint32_t *)(v16 + 64) = v26;
          *(uint32_t *)(v16 + 80) = v27;
          if ( ((v26 >> 11) & 5) == 5 )
          {
            v30 = v27 & 0xFFFCFFFF;
            if ( (v26 & 0x600) == 0x400 )
              v31 = 0x20000;
            else
              v31 = 0x10000;
            v32 = v30 | v31;
            if ( *(uint8_t *)(v34 + 165) )
              v33 = v32 | 0x40000;
            else
              v33 = v32 & 0xFFFBFFFF;
            *(uint32_t *)(v16 + 80) = v33;
          }
          if ( (v22[15] & 4) == 0 )
            *(uint32_t *)(v16 + 48) &= 0xFFFFFE7F;
        }
      }
      else
      {
        v17 = v16 + 44;
      }
      sub_11C9C8(a1);
    }
    v18 = *(uint32_t *)&v2[28 * v5 + 36];
    v19 = *(uint64_t *)(v16 + 96);
    v4[16] = v19;
    v4[18] = (v14 + 1) << 8;
    v4[11] = HIDWORD(v19);
    v4[12] = v17;
    result = (int)(v4 + 3);
    if ( v18 )
    {
      v4[4] = v18;
    }
    else
    {
      v28 = off_11CD14;
      *(uint32_t *)(v11 + 84 * v5) = result;
      v29 = 84 * v5 + v11;
      if ( !*(uint8_t *)(*(uint32_t *)v28 + 1) )
      {
        *(uint32_t *)(v29 + 4) = 0;
        *(uint32_t *)(v29 + 8) = 0;
      }
    }
    v20 = v11 + 84 * v5;
    v21 = *(uint8_t *)(v20 + 80) + 1;
    *(uint32_t *)&v2[28 * v5 + 36] = result;
    *(uint8_t *)(v20 + 80) = v21;
  }
  else
  {
    v4[18] |= 0x10000u;
    v12 = 84 * v5;
LABEL_18:
    if ( !v2[199] )
      goto LABEL_8;
LABEL_19:
    *(uint32_t *)off_11CD08 = (v2[164] << 24) & 0x7000000 | *(uint32_t *)off_11CD08 & 0xF8FFFFFF;
    sub_12D4F8(v12 + 12 + v11);
    if ( !*(uint16_t *)(a1 + 4) )
      return sub_119120((uint32_t *)a1);
    return sub_118358((uint32_t *)a1, v7, v5);
  }
  return result;
}
