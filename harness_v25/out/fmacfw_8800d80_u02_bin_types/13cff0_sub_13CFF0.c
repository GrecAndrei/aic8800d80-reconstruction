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

// sub_13CFF0 @ 0x13cff0, size 620 bytes
int  sub_13CFF0(int result, uint32_t *a2)
{
  unsigned int v2; // r6
  int v3; // r7
  int v4; // r2
  char v5; // r12
  unsigned int v6; // r3
  unsigned int v7; // r4
  int v8; // r5
  unsigned int v9; // r3
  int16_t v10; // lr
  char v11; // lr
  int v12; // lr
  unsigned int v13; // r5
  unsigned int v14; // r3
  unsigned int v15; // r2
  unsigned int v16; // r4
  unsigned int v17; // r2
  int v18; // r4
  int v19; // r12
  unsigned int v20; // r2
  int v21; // r12
  unsigned int v22; // r2
  unsigned int v23; // r9
  int v24; // r8
  int v25; // r2
  int v26; // r4
  uint16_t v27; // r12
  unsigned int v28; // r3
  unsigned int v29; // r12
  unsigned int v30; // r2
  unsigned int v31; // r3
  int v32; // r4
  int v33; // r6
  unsigned int v34; // lr
  unsigned int v35; // r8
  int v36; // r4
  int v37; // r3
  unsigned int v38; // r6

  v2 = *(uint16_t *)(result + 184);
  if ( !*(uint16_t *)(result + 184) )
  {
    v10 = *(uint16_t *)(result + 184);
    v3 = -1;
    goto LABEL_13;
  }
  v3 = v2 - 1;
  v4 = result;
  v5 = 0;
  while ( 1 )
  {
    v6 = *(uint16_t *)(v4 + 10);
    v7 = v6 >> 11;
    if ( (v6 & 0x2000) != 0 )
    {
      v9 = v6 & 0xF;
      v8 = v7 & 6;
    }
    else
    {
      v8 = (v6 >> 11) & 6;
      if ( (v7 & 6) != 0 )
        v9 = v6 & 7;
      else
        v9 = v6 & 0x7F;
    }
    if ( !v8 && v9 <= 3 || !*(uint8_t *)(v4 + 13) )
      goto LABEL_11;
    if ( *(uint16_t *)(v4 + 8) > 0x1998u )
      break;
    v5 = 1;
LABEL_11:
    v4 += 12;
    if ( result + 12 + 12 * (uint16_t)(v2 - 1) == v4 )
    {
      LOBYTE(v10) = 8 * v5;
      goto LABEL_13;
    }
  }
  LOBYTE(v10) = 0;
LABEL_13:
  v11 = v10 | *(uint8_t *)(result + 166) & 0xF7;
  *(uint8_t *)(result + 166) = v11;
  v12 = v11 & 2;
  if ( !v12 && *a2 > a2[v2 - 1] && *(uint8_t *)(result + 12 * v3 + 13) )
  {
    v13 = 0;
    v14 = 1;
  }
  else
  {
    v13 = (uint16_t)v3;
    v12 = (uint16_t)v3;
    v14 = 2;
  }
  *(uint16_t *)(result + 136) = v13;
  v15 = *(uint16_t *)(result + 12 * v12 + 10);
  v16 = v15 >> 11;
  if ( (v15 & 0x2000) != 0 )
  {
    v17 = v15 & 0xF;
    if ( (v16 & 6) != 0 )
      goto LABEL_19;
LABEL_54:
    if ( v17 > 3 )
      goto LABEL_19;
  }
  else
  {
    if ( (v16 & 6) == 0 )
    {
      v17 = v15 & 0x7F;
      goto LABEL_54;
    }
LABEL_19:
    if ( v3 > 0 )
    {
      LOWORD(v18) = 0;
      v19 = 0;
      do
      {
        v22 = *(uint16_t *)(result + 12 * v19 + 10);
        v23 = v22 >> 11;
        v24 = (v22 >> 11) & 6;
        if ( (v22 & 0x2000) != 0 )
        {
          v20 = v22 & 0xF;
          v24 = v23 & 6;
        }
        else if ( (v23 & 6) != 0 )
        {
          v20 = v22 & 7;
        }
        else
        {
          v20 = v22 & 0x7F;
        }
        v18 = (uint16_t)(v18 + 1);
        if ( !v24 )
        {
          v21 = 3 * v19;
          if ( v20 <= 3 )
            *(uint8_t *)(result + 4 * v21 + 14) = v24;
        }
        v19 = v18;
      }
      while ( v18 < v3 );
    }
    *(uint8_t *)(result + 12 * v12 + 14) = 1;
  }
  *(uint16_t *)(result + 138) = v13;
  if ( v14 >= v2 )
  {
LABEL_57:
    v30 = v13;
    v29 = v13;
  }
  else
  {
    v25 = result + 12 * (v2 - v14);
    while ( 1 )
    {
      v26 = *(uint8_t *)(v25 + 14);
      v27 = v14 + 1;
      v25 -= 12;
      if ( v26 )
        break;
      LOWORD(v14) = v14 + 1;
      if ( v27 == v2 )
        goto LABEL_57;
    }
    LOWORD(v29) = v2 - v14;
    v28 = (uint16_t)(v14 + 1);
    v29 = (uint16_t)v29;
    *(uint16_t *)(result + 138) = v29;
    if ( v2 <= v28 )
    {
LABEL_56:
      v30 = (uint16_t)v29;
    }
    else
    {
      v30 = v2 - v28;
      v31 = (v3 - v28) >> 16 << 16;
      v32 = result + 12 * v30;
      while ( 1 )
      {
        v33 = *(uint8_t *)(v32 + 14);
        v32 -= 12;
        if ( v33 )
          break;
        if ( v31 == --v30 )
          goto LABEL_56;
      }
    }
  }
  v34 = a2[v30];
  v35 = *(uint16_t *)(result + 12 * v30 + 8);
  if ( v29 )
  {
    v36 = result;
    v37 = 0;
    while ( 1 )
    {
      if ( !*(uint8_t *)(v36 + 14) || (uint16_t)v37 == v13 )
        goto LABEL_47;
      v38 = *(uint16_t *)(v36 + 8);
      if ( v38 > 0xF332 )
      {
        if ( a2[v37] >= v34 )
        {
          v35 = *(uint16_t *)(v36 + 8);
          v34 = a2[v37];
          LOWORD(v30) = v37;
        }
        goto LABEL_47;
      }
      if ( v38 < v35 )
      {
LABEL_47:
        ++v37;
        v36 += 12;
        if ( v29 <= (uint16_t)v37 )
          break;
      }
      else
      {
        v34 = a2[v37];
        LOWORD(v30) = v37++;
        v35 = *(uint16_t *)(v36 + 8);
        v36 += 12;
        if ( v29 <= (uint16_t)v37 )
          break;
      }
    }
  }
  *(uint16_t *)(result + 140) = v30;
  *(uint16_t *)(result + 142) = 0;
  return result;
}

