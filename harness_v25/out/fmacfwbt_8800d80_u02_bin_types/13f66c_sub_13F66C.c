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

// sub_13F66C @ 0x13f66c, size 452 bytes
// Doc: sub_123F66C [util]: Initializes struct field at offset 0x88 with provided data
// sub_123F66C [util]: Initializes struct field at offset 0x88 with provided data
int  sub_13F66C(int a1, int a2)
{
  uint16_t *v2; // r5
  uint16_t *v3; // r9
  uint16_t *v5; // r2
  int v6; // r6
  uint16_t *v7; // r7
  uint16_t *v8; // r1
  int v9; // t1
  uint64_t v10; // r2
  int v11; // r1
  uint16_t v12; // r1
  int v13; // r3
  int v14; // r2
  uint32_t *v15; // r1
  uint32_t *v16; // r2
  int v17; // r3
  uint16_t v18; // r8
  int v19; // r11
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  int v24; // r3
  int result; // r0
  int v26; // r3
  int v27; // t1
  int v28; // t1
  int v29; // r2
  uint8_t v31[8]; // [sp+8h] [bp-34h] BYREF
  uint32_t v32[11]; // [sp+10h] [bp-2Ch] BYREF

  v2 = (uint16_t *)(a1 + 136);
  v3 = (uint16_t *)v31;
  v5 = (uint16_t *)(a1 + 136);
  v6 = a1;
  v7 = (uint16_t *)(a1 + 144);
  v8 = v31;
  do
  {
    v9 = *v5++;
    *v8++ = *(uint16_t *)(a1 + 12 * v9 + 10);
  }
  while ( v5 != v7 );
  if ( *(uint16_t *)(a1 + 146) )
  {
    HIDWORD(v10) = ((unsigned int)((*(uint16_t *)(a1 + 144) << 16) / *(uint16_t *)(a1 + 146)
                                 + 3 * *(uint32_t *)(a1 + 148)) >> 2)
                 & 0x1FFFFFF;
    LODWORD(v10) = 0;
    *(uint64_t *)(a1 + 144) = v10;
  }
  sub_13E30C((uint16_t *)(a1 + 124));
  v11 = *(uint16_t *)(a1 + 184);
  if ( *(uint16_t *)(a1 + 124) )
  {
    if ( !*(uint16_t *)(a1 + 184) )
    {
LABEL_26:
      v29 = *(uint16_t *)(a1 + 190);
      result = 0;
      *(uint16_t *)(a1 + 124) = 0;
      *(uint16_t *)(a1 + 126) = 0;
      if ( v29 != 0xFFFF )
        return sub_13E57C(a1);
      return result;
    }
    v12 = v11 - 1;
    v13 = a1;
    while ( 1 )
    {
      v14 = *(uint16_t *)(v13 + 4);
      *(uint8_t *)(v13 + 14) = 1;
      v13 += 12;
      if ( v14 )
        break;
      if ( v13 == a1 + 12 + 12 * v12 )
        goto LABEL_26;
    }
    *(uint16_t *)(a1 + 124) = 0;
    *(uint16_t *)(a1 + 126) = 0;
  }
  else
  {
    *(uint16_t *)(a1 + 126) = 0;
    if ( !v11 )
    {
      if ( *(uint16_t *)(a1 + 190) == 0xFFFF )
        goto LABEL_18;
LABEL_29:
      result = sub_13E57C(a1);
      goto LABEL_23;
    }
    v12 = v11 - 1;
  }
  v15 = &v32[v12 + 1];
  v16 = v32;
  v17 = a1;
  do
  {
    *v16++ = 0;
    *(uint8_t *)(v17 + 14) = 1;
    v17 += 12;
  }
  while ( v16 != v15 );
  if ( *(uint16_t *)(a1 + 190) != 0xFFFF )
    goto LABEL_29;
  v18 = 0;
  do
  {
    v19 = v18;
    sub_13E30C((uint16_t *)(a1 + 12 * v18 + 4));
    v20 = (uint8_t)v18++;
    v21 = sub_13F54C(a1, v20, 1);
    v22 = *(uint16_t *)(a1 + 184);
    v32[v19] = v21;
  }
  while ( v22 > v18 );
LABEL_18:
  sub_13E26C(a1, (int)v32);
  sub_13D08C(a1, v32);
  if ( !a2 )
  {
    v23 = *(uint16_t *)(a1 + 184);
    *(uint8_t *)(a1 + 166) |= 0x40u;
    if ( v23 )
    {
      v24 = a1 + 12 + 12 * (uint16_t)(v23 - 1);
      do
      {
        *(uint16_t *)(v6 + 4) = a2;
        *(uint16_t *)(v6 + 6) = a2;
        v6 += 12;
      }
      while ( v6 != v24 );
    }
  }
  result = 0;
LABEL_23:
  while ( 1 )
  {
    v27 = *v2++;
    v26 = v27;
    v28 = *v3++;
    if ( *(uint16_t *)(a1 + 12 * v26 + 10) != v28 )
      break;
    if ( v2 == v7 )
      return result;
  }
  return 1;
}

