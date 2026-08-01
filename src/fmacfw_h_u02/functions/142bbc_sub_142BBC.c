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

// double_compare_core @ 0x142bbc, size 360 bytes
unsigned int  double_compare_core(unsigned int result, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // r5
  unsigned int v5; // r12
  int v6; // zf
  int v7; // r4
  int v8; // r4
  int v9; // lr
  unsigned int v10; // r1
  unsigned uint64_t v11; // r2
  unsigned int v12; // r5
  unsigned int v13; // r6
  unsigned int v14; // r1
  int v15; // cf
  unsigned int v16; // r4
  unsigned uint64_t v17; // kr00_8
  unsigned uint64_t v18; // r2
  int v19; // r0
  unsigned int v20; // r12
  unsigned uint64_t v21; // r2
  unsigned uint64_t v22; // r2
  int v23; // cc
  char v24; // cf
  int v25; // vf
  char v26; // cc
  int v27; // r4

  v5 = 2047;
  v7 = (a2 >> 20) & 0x7FF;
  v6 = v7 == 0;
  if ( v7 )
  {
    v4 = (a4 >> 20) & 0x7FF;
    v6 = v4 == 0;
  }
  if ( !v6 )
  {
    v6 = v7 == 0x7FF;
    if ( v7 != 0x7FF )
      v6 = v4 == 0x7FF;
  }
  if ( v6 )
    result = double_compare_ord();
  v8 = v7 - v4;
  v9 = a2 ^ a4;
  v10 = a2 << 12;
  if ( a3 | (a4 << 12) )
  {
    HIDWORD(v11) = (a4 << 8) & 0xFFFFFFF | 0x10000000 | HIBYTE(a3);
    LODWORD(v11) = a3 << 8;
    v12 = (v10 >> 4) | 0x10000000 | HIBYTE(result);
    v13 = result << 8;
    v14 = v9 & 0x80000000;
    v15 = v12 >= HIDWORD(v11);
    if ( v12 == HIDWORD(v11) )
      v15 = v13 >= (unsigned int)v11;
    v16 = v15 + v8 + 1021;
    if ( !v15 )
      v11 >>= 1;
    v17 = __PAIR64__(v12, v13) - v11;
    v18 = v11 >> 1;
    v19 = 0x100000;
    v20 = 0x80000;
    while ( 1 )
    {
      if ( v17 >= v18 )
      {
        v19 |= v20;
        v17 -= v18;
      }
      v21 = v18 >> 1;
      if ( v17 >= v21 )
      {
        v19 |= v20 >> 1;
        v17 -= v21;
      }
      v22 = v21 >> 1;
      if ( v17 >= v22 )
      {
        v19 |= v20 >> 2;
        v17 -= v22;
      }
      v18 = v22 >> 1;
      if ( v17 >= v18 )
      {
        v19 |= v20 >> 3;
        v17 -= v18;
      }
      if ( !v17 )
        break;
      v18 *= 8LL;
      v20 >>= 4;
      v17 *= 16LL;
      if ( !v20 )
      {
        if ( (v14 & 0x100000) != 0 )
          goto LABEL_28;
        v14 |= v19;
        v19 = 0;
        v20 = 0x80000000;
      }
    }
    if ( (v14 & 0x100000) == 0 )
      v19 = 0;
LABEL_28:
    v23 = v16 > 0xFD;
    if ( v16 > 0xFD )
      v23 = v16 - 253 > 0x700;
    if ( !v23 )
    {
      v24 = v17 >= v18;
      if ( v17 == v18 )
        v24 = v19 & 1;
      return v24 + v19;
    }
LABEL_38:
    JUMPOUT(0x142A46);
  }
  v25 = __OFADD__(v8, v5 >> 1);
  v27 = v8 + (v5 >> 1);
  v26 = (v27 < 0) ^ v25 | (v27 == 0);
  if ( !v26 )
    v26 = (int)v5 <= v27;
  if ( v26 )
    goto LABEL_38;
  return result;
}

