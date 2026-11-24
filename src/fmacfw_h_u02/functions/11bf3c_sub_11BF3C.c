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


extern uint32_t dword_11C174;
extern uint32_t dword_11C17C;
extern uint32_t dword_11C190;
extern uint32_t off_11C16C;
extern uint32_t off_11C170;
extern uint32_t off_11C178;
extern uint32_t off_11C180;
extern uint32_t off_11C184;
extern uint32_t off_11C188;
extern uint32_t off_11C18C;
extern uint32_t off_11C1A4;
extern uint32_t off_11C1A8;
extern uint32_t off_11C1AC;
extern uint32_t off_11C1B0;

// tx_frame_send @ 0x11bf3c, size 560 bytes
int  tx_frame_send(int result)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r1
  uint16_t v6; // r0
  int v7; // r3
  int v8; // r1
  int v9; // r3
  int v10; // r4
  int v11; // r5
  int v12; // r6
  unsigned int v13; // r5
  int v14; // r8
  int v15; // r9
  int v16; // lr
  int v17; // nf
  int v18; // r0
  unsigned int v19; // r6
  int v20; // r12
  int v21; // r5
  unsigned int v22; // r4
  uint16_t v23; // r9
  unsigned int *v24; // r10
  unsigned int v25; // r11
  uint16_t v26; // r8
  int v27; // r1
  uint16_t v28; // r7
  uint16_t *v29; // r3
  char *v30; // r0
  int v31; // r2
  int v32; // r11
  char v33; // r7
  unsigned int v34; // r4
  uint16_t v35; // [sp+0h] [bp-Ch]
  uint16_t v36; // [sp+4h] [bp-8h]

  v1 = off_11C170;
  v2 = *(uint16_t **)off_11C16C;
  v3 = *(uint32_t *)(result + 84);
  v4 = *(uint32_t *)(result + 28);
  *((uint8_t *)off_11C170 + 200) = 0;
  v5 = *v2;
  if ( v5 < 0 )
  {
    result = *(uint16_t *)(result + 48);
    if ( (unsigned int)result <= 0x1C )
    {
      v30 = aHdrdescFrmlenH;
      v31 = 2509;
      return unknown_12f2c8((int)v30, (int)aTxlHeTriggerPu, v31);
    }
  }
  if ( (v3 & 0x2000000) == 0 )
    goto LABEL_18;
  v6 = v3 >> 15;
  v7 = (v3 >> 15) & 0x3FF;
  if ( v5 < 0 && (v6 & 0x3F0) == 0 )
  {
    v30 = aKeyIdxHwMmSecD;
    v31 = 2522;
    return unknown_12f2c8((int)v30, (int)aTxlHeTriggerPu, v31);
  }
  v8 = dword_11C174;
  v9 = (uint8_t)(v7 - 16);
  v10 = dword_11C174 + 696 * v9;
  result = *(uint8_t *)(v10 + 37);
  if ( *(uint8_t *)(v10 + 37) )
  {
    v11 = *(uint8_t *)(v10 + 34);
    v1[45] = *(uint32_t *)(v10 + 38);
    v12 = dword_11C17C;
    *((uint16_t *)off_11C178 + 2) = *(uint16_t *)(v10 + 42);
    result = v1[4];
    if ( result == v12 + 1320 * v11 )
    {
      result = *(uint32_t *)off_11C184 & 0x3F;
      if ( *(uint8_t *)(*(uint32_t *)off_11C180 + 62) + 3 < result )
      {
        v13 = *(uint32_t *)off_11C18C;
        v14 = v1[42];
        v15 = *(uint32_t *)off_11C188 & 0xF;
        v16 = HIWORD(*(uint32_t *)off_11C188) & 3;
        v17 = (*(uint32_t *)off_11C188 & 0x80000) != 0;
        v35 = (uint16_t)*(uint32_t *)off_11C188 >> 4;
        *((uint16_t *)v1 + 94) = v35;
        *((uint8_t *)v1 + 191) = v15;
        *((uint8_t *)v1 + 195) = v16;
        v18 = (uint8_t)v13 >> 4;
        v19 = v13 & 7;
        if ( v17 )
        {
          v32 = 2;
          v33 = 2;
          v36 = 1024;
        }
        else
        {
          v32 = 1;
          v33 = 1;
          v36 = 512;
        }
        v20 = (v13 >> 9) & 7;
        *((uint8_t *)v1 + 192) = v33;
        *((uint8_t *)v1 + 193) = v18;
        *((uint8_t *)v1 + 199) = (v13 & 0x1000) != 0;
        *((uint8_t *)v1 + 194) = v20;
        *((uint8_t *)v1 + 196) = v19;
        if ( v15 )
        {
          LOBYTE(v21) = *((uint8_t *)v1 + 198);
        }
        else
        {
          v34 = v13 >> 30;
          v21 = HIBYTE(v13) & 3;
          *((uint8_t *)v1 + 197) = *((uint8_t *)off_11C1AC + v34);
          *((uint8_t *)v1 + 198) = v21;
        }
        while ( *(int *)off_11C1A4 >= 0 )
          ;
        v22 = *(uint32_t *)off_11C1A4 & dword_11C190;
        if ( v19 > 2 )
          v23 = *((uint16_t *)&((uint32_t *)(uintptr_t)off_11C1B0)[3 * v18] + 3 * ((uint8_t)(v19 - 3) >> 1) + v32) << ((v19 - 3) & 1);
        else
          v23 = *(uint16_t *)(*(uint32_t *)&asc_148180[4 * v19] + 2 * (3 * v18 + v32));
        v24 = (unsigned int *)off_11C1A8;
        if ( v22 >= *(uint32_t *)(v14 + 12) )
          v22 = *(uint32_t *)(v14 + 12);
        v1[44] = v22;
        v25 = *v24;
        v26 = *(uint8_t *)(v14 + 28);
        v27 = v8 + 696 * v9;
        v28 = v36 | v18;
        result = *(uint32_t *)(v27 + 340);
        v1[42] = v27;
        *((uint8_t *)v1 + 200) = v22 > 0x27;
        *((uint16_t *)v1 + 93) = v26 * (1 << v21) * v23;
        v1[43] = (HIBYTE(v25) << 6) | 0x13;
        *(uint16_t *)(result + 130) = v28 | ((uint16_t)v16 << 7) | (16 * v20) | 0x3000;
        *(uint16_t *)(result + 132) = v19 | (8 * v35);
        v1[51] = 0;
      }
    }
  }
  else
  {
LABEL_18:
    v29 = *(uint16_t **)(v4 + 8);
    *((uint16_t *)v1 + 90) = v29[5];
    *((uint16_t *)v1 + 91) = v29[6];
    *((uint16_t *)v1 + 92) = v29[7];
  }
  return result;
}
