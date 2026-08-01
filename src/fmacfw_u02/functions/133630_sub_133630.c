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

// unaligned_read @ 0x133630, size 314 bytes
uint32_t * unaligned_read(uint32_t *result, int a2, unsigned int a3)
{
  unsigned int *v3; // r6
  char v4; // r1
  unsigned int v5; // r7
  int v6; // r12
  int v7; // r5
  unsigned int v8; // r3
  uint32_t *v9; // r6
  unsigned int v10; // r1
  uint32_t *v11; // r9
  unsigned int v12; // r11
  unsigned int v13; // r8
  unsigned int v14; // r7
  int v15; // r4
  int v16; // r5
  int v17; // r10
  int *v18; // r1
  unsigned int *v19; // r8
  unsigned int *v20; // r9
  unsigned int v21; // r3
  int v22; // r2
  int v23; // r7
  int v24; // r2
  unsigned int v25; // r3
  unsigned int v26; // r7
  int v27; // r4
  unsigned int v28; // r3
  int v29; // r2
  char v30; // r2
  int v31; // r12
  int v32; // r2
  int v33; // [sp+4h] [bp-8h]

  v3 = (unsigned int *)(a2 & 0xFFFFFFFC);
  v4 = a2 & 3;
  v5 = *v3;
  v6 = *((uint8_t *)result + 12);
  v7 = result[2];
  v8 = (uint8_t)(4 - v4);
  v9 = v3 + 1;
  v10 = v5 >> (8 * v4);
  v11 = v9;
  if ( a3 >= v8 )
  {
    v14 = a3 - v8;
    v13 = (a3 - v8) >> 2;
    a3 = v8;
    v12 = v14 & 0xFFFFFFFC;
  }
  else
  {
    v12 = 0;
    v10 &= 0xFFFFFFFF >> (8 * (4 - a3));
    v13 = 0;
    v14 = 0;
  }
  v15 = v6 + a3;
  if ( v6 + a3 > 3 )
  {
    v30 = 8 * v6;
    v31 = 8 * (4 - v6);
    v32 = (v10 << v30) | v7;
    if ( v31 == 32 )
      v16 = 0;
    else
      v16 = v10 >> v31;
    v15 -= 4;
    result = crypto_mix_round(result, result + 1, v32);
  }
  else
  {
    v16 = v7 | (v10 << (8 * v6));
  }
  if ( v13 )
  {
    v17 = 8 * (4 - v15);
    v18 = result + 1;
    v33 = v13;
    v19 = &v9[v13];
    v20 = v9;
    do
    {
      v21 = *v20;
      v22 = (*v20++ << (8 * v15)) | v16;
      if ( v17 == 32 )
        v16 = 0;
      else
        v16 = v21 >> v17;
      result = crypto_mix_round(result, v18, v22);
    }
    while ( v20 != v19 );
    v11 = &v9[v33];
  }
  if ( v14 <= v12 )
    goto LABEL_20;
  v23 = v14 & 3;
  v24 = 8 * (4 - v23);
  if ( v24 == 32 )
  {
    v25 = 0;
  }
  else
  {
    v25 = (0xFFFFFFFF >> v24) & *v11;
    v16 |= v25 << (8 * v15);
  }
  v26 = v23 + v15;
  if ( v26 > 3 )
  {
    v27 = 8 * (4 - v15);
    if ( v27 == 32 )
      v28 = 0;
    else
      v28 = v25 >> v27;
    v29 = v16;
    LOBYTE(v15) = v26 - 4;
    v16 = v28;
    result = crypto_mix_round(result, result + 1, v29);
LABEL_20:
    result[2] = v16;
    *((uint8_t *)result + 12) = v15;
    return result;
  }
  result[2] = v16;
  *((uint8_t *)result + 12) = v26;
  return result;
}

