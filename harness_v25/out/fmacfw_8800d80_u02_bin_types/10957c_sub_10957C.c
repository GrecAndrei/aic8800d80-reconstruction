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

extern uint32_t dword_109758;
extern uint32_t dword_10975C;

// sub_10957C @ 0x10957c, size 476 bytes
int  sub_10957C(unsigned int a1, int a2, int *a3)
{
  int v3; // r12
  int v4; // r4
  int *v5; // r6
  unsigned int v6; // r5
  int v7; // r3
  int v9; // r7
  int v10; // t1
  int v11; // r1
  int v12; // r8
  unsigned int v13; // r0
  int *v14; // r5
  int v15; // r7
  unsigned int v16; // r4
  int v17; // r6
  int v18; // lr
  int v19; // r8
  signed int v20; // r1
  int v22; // r11
  uint8_t *v23; // r7
  uint8_t *v24; // r1
  int v25; // r5
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r4
  uint8_t *v30; // r5
  int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch] BYREF
  int16_t v33; // [sp+Ch] [bp-8h]
  uint8_t v34[4]; // [sp+10h] [bp-4h] BYREF

  v3 = (uint8_t)((a1 - 1) >> 1);
  v31 = v3;
  v32 = -2139062144;
  v33 = -32640;
  if ( a1 <= 1 )
    return a3[v31];
  v4 = 128;
  v5 = a3;
  v6 = 0;
  LOBYTE(v7) = 1;
  while ( 1 )
  {
    v9 = *v5;
    v10 = v5[1];
    ++v5;
    if ( v9 - v10 > a2 )
      break;
    if ( v4 == 128 )
      *((uint8_t *)&v32 + 2 * v6) = v7 - 1;
    v34[2 * v6 - 7] = v7;
LABEL_6:
    v7 = (uint8_t)(v7 + 1);
    if ( a1 == v7 )
      goto LABEL_14;
LABEL_7:
    v4 = *((uint8_t *)&v32 + 2 * v6);
  }
  if ( v4 == 128 )
    goto LABEL_6;
  v11 = a3[v4];
  if ( v11 > 14000 )
  {
    v12 = *((uint8_t *)&v32 + 2 * v6 + 1);
    goto LABEL_12;
  }
  v12 = *((uint8_t *)&v32 + 2 * v6 + 1);
  v22 = a3[v12];
  if ( v22 < dword_109758 || v11 < 1000 && v22 >= dword_10975C )
  {
LABEL_12:
    if ( v12 >= v4 + v3 )
      goto LABEL_13;
    goto LABEL_27;
  }
  if ( v12 < v4 + 2 )
  {
LABEL_27:
    v23 = &v34[2 * v6];
    *(v23 - 8) = 0x80;
    *(v23 - 7) = 0x80;
    goto LABEL_6;
  }
LABEL_13:
  v7 = (uint8_t)(v7 + 1);
  v6 = (uint8_t)(v6 + 1);
  if ( a1 != v7 )
    goto LABEL_7;
LABEL_14:
  if ( v6 <= 2 )
  {
    v24 = &v34[2 * v6];
    v25 = 2 * v6;
    v26 = (uint8_t)*(v24 - 8);
    if ( v26 != 128 )
    {
      v27 = a3[v26];
      v28 = (uint8_t)*(v24 - 7);
      if ( v27 <= 14000 )
      {
        v29 = a3[v28];
        if ( v29 >= dword_109758 && (v27 >= 1000 || v29 <= -1000) )
          v3 = 2;
      }
      if ( v28 < v3 + v26 )
      {
        v30 = &v34[v25];
        *(v30 - 8) = 0x80;
        *(v30 - 7) = 0x80;
      }
    }
  }
  if ( (uint8_t)v32 != 128 )
  {
    v13 = (uint8_t)(BYTE1(v32) + 1 - v32);
    v14 = &v32;
    v15 = 1;
    v16 = (uint16_t)((a3[(uint8_t)v32] - a3[BYTE1(v32)]) / (int)v13);
    v17 = 0;
    while ( 1 )
    {
      v18 = *((uint8_t *)v14 + 2);
      if ( v18 == 128 )
        break;
      v19 = *((uint8_t *)v14 + 3);
      v20 = (uint8_t)(v19 + 1 - v18);
      if ( v20 > v13 )
      {
        v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
        v13 = (uint8_t)(v19 + 1 - v18);
        v17 = (uint8_t)v15;
        v14 = (int *)((char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      else
      {
        if ( v20 == v13 && (uint16_t)((a3[v18] - a3[v19]) / v20) < v16 )
        {
          v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
          v17 = (uint8_t)v15;
        }
        v14 = (int *)((char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      v15 = 2;
    }
    v31 = (uint8_t)(*((uint8_t *)&v32 + 2 * v17)
                          + ((*((uint8_t *)&v32 + 2 * v17 + 1) - *((uint8_t *)&v32 + 2 * v17) + 1) >> 1));
  }
  return a3[v31];
}

