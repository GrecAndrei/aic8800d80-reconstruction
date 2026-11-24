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

// sub_13E3C4 @ 0x13e3c4, size 440 bytes
int  sub_13E3C4(int a1)
{
  int v1; // r4
  int v3; // r8
  int v4; // r3
  int v5; // r9
  int result; // r0
  int v7; // r3
  uint16_t v8; // r7
  int v9; // r6
  int v10; // r3
  int v11; // r2
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r6
  int v16; // r10
  uint16_t v17; // r10
  int v18; // r11
  uint16_t v19; // r10
  uint16_t v20; // r11
  uint16_t v21; // r6
  int v22; // r3

  v1 = *(uint16_t *)(a1 + 184);
  if ( *(uint16_t *)(a1 + 184) )
  {
    v3 = v1 - 1;
    v4 = a1;
    do
    {
      *(uint16_t *)(v4 + 10) = -1;
      *(uint16_t *)(v4 + 4) = 0;
      *(uint16_t *)(v4 + 6) = 0;
      *(uint16_t *)(v4 + 8) = 0;
      *(uint8_t *)(v4 + 12) = 0;
      *(uint8_t *)(v4 + 13) = 0;
      *(uint8_t *)(v4 + 14) = 1;
      v4 += 12;
    }
    while ( v4 != a1 + 12 + 12 * (uint16_t)(v1 - 1) );
    v5 = v1 - 1;
  }
  else
  {
    v5 = -1;
    v3 = -1;
  }
  result = sub_13E35C(a1);
  v7 = *(uint8_t *)(a1 + 169);
  *(uint16_t *)(a1 + 10) = result;
  switch ( v7 )
  {
    case 0:
    case 1:
      v8 = ((uint16_t)v7 << 11) | (*(uint8_t *)(a1 + 182) << 10) | *(uint8_t *)(a1 + 178);
      break;
    case 2:
    case 3:
      result = *(uint8_t *)(a1 + 181);
      v8 = ((uint16_t)v7 << 11)
         | ((uint16_t)result << 9)
         | (*(uint8_t *)(a1 + 179) << 7)
         | (8 * *(uint8_t *)(a1 + 180))
         | (uint8_t)(31 - __clz(*(uint8_t *)(a1 + *(uint8_t *)(a1 + 180) + 170)));
      break;
    case 4:
      v17 = *(uint8_t *)(a1 + 180);
      v18 = ((int)*(uint16_t *)(a1 + 170) >> (2 * v17)) & 3;
      v19 = 16 * v17;
      v20 = v18 + 7;
      v21 = (*(uint8_t *)(a1 + 179) << 7) | (*(uint8_t *)(a1 + 181) << 9);
      do
      {
        v8 = v19 | v20 | v21 | 0x2000;
        result = sub_13D2F8(a1, v8);
        --v20;
      }
      while ( !result && (uint8_t)v20 != 6 );
      break;
    case 5:
      v14 = *(uint8_t *)(a1 + 180);
      v15 = 2 * (((int)*(uint16_t *)(a1 + 170) >> (2 * v14)) & 3) + 7;
      v16 = (16 * v14) | (*(uint8_t *)(a1 + 179) << 7);
      do
      {
        v8 = v16 | v15 | 0x2800;
        result = sub_13D2F8(a1, v16 | v15 | 0x2800);
        v15 = (uint16_t)(v15 - 1);
      }
      while ( !result && (uint8_t)v15 != 6 );
      break;
    default:
      v8 = 0;
      break;
  }
  v9 = 1;
  *(uint16_t *)(a1 + 12 * v5 + 10) = v8;
  if ( v3 <= 1 )
  {
LABEL_26:
    if ( !v1 )
      return result;
  }
  else
  {
    do
    {
      while ( 1 )
      {
        result = sub_13D730(a1);
        v1 = *(uint16_t *)(a1 + 184);
        if ( *(uint16_t *)(a1 + 184) )
          break;
LABEL_25:
        v22 = a1 + 12 * v9;
        v9 = (uint16_t)(v9 + 1);
        *(uint16_t *)(v22 + 10) = result;
        if ( v9 >= v1 - 1 )
          goto LABEL_26;
      }
      v10 = a1;
      v11 = 0;
      while ( 1 )
      {
        v12 = *(uint16_t *)(v10 + 10);
        ++v11;
        v10 += 12;
        if ( v12 == result )
          break;
        if ( v11 == v1 )
          goto LABEL_25;
      }
    }
    while ( v9 < v1 - 1 );
  }
  v13 = 0;
  do
    result = sub_13DB2C(a1, (uint16_t)v13++);
  while ( v13 < *(uint16_t *)(a1 + 184) );
  return result;
}
