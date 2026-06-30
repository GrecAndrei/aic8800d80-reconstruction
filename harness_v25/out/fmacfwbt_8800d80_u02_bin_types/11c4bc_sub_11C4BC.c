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

extern uint32_t off_11C6F0;
extern uint32_t off_11C6EC;
extern uint32_t dword_11C718;
extern uint32_t dword_11C720;
extern uint32_t dword_11C71C;
extern uint32_t dword_11C6F4;
extern uint32_t dword_11C6FC;
extern uint32_t off_11C6F8;
extern uint32_t off_11C704;
extern uint32_t off_11C700;
extern uint32_t off_11C70C;
extern uint32_t off_11C708;
extern uint32_t dword_11C72C;
extern uint32_t off_11C724;
extern uint32_t dword_11C710;
extern uint32_t dword_11C730;
extern uint32_t dword_11C714;
extern uint32_t off_11C728;

// sub_11C4BC @ 0x11c4bc, size 560 bytes
int  sub_11C4BC(int result)
{
  uint32_t *v1; // r2
  int16_t *v2; // r1
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r1
  int16_t v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r4
  int v10; // r5
  int v11; // r6
  unsigned int v12; // r5
  int v13; // r8
  int v14; // r9
  int v15; // lr
  int v16; // nf
  int v17; // r0
  unsigned int v18; // r6
  int v19; // r12
  int v20; // r5
  unsigned int v21; // r4
  int16_t v22; // r9
  unsigned int *v23; // r10
  unsigned int v24; // r11
  int16_t v25; // r8
  int v26; // r1
  int16_t v27; // r7
  uint16_t *v28; // r3
  int v29; // r1
  int v30; // r0
  int v31; // r2
  int v32; // r11
  char v33; // r7
  unsigned int v34; // r4
  int16_t v35; // [sp+0h] [bp-Ch]
  int16_t v36; // [sp+4h] [bp-8h]

  v1 = off_11C6F0;
  v2 = *(int16_t **)off_11C6EC;
  v3 = *(uint32_t *)(result + 84);
  v4 = *(uint32_t *)(result + 28);
  *((uint8_t *)off_11C6F0 + 200) = 0;
  v5 = *v2;
  if ( v5 < 0 )
  {
    result = *(uint16_t *)(result + 48);
    if ( (unsigned int)result <= 0x1C )
    {
      v29 = dword_11C718;
      v30 = dword_11C720;
      v31 = 2509;
      return sub_12F630(v30, v29, v31, v3);
    }
  }
  if ( (v3 & 0x2000000) == 0 )
    goto LABEL_18;
  v6 = v3 >> 15;
  v3 = (v3 >> 15) & 0x3FF;
  if ( v5 < 0 && (v6 & 0x3F0) == 0 )
  {
    v29 = dword_11C718;
    v30 = dword_11C71C;
    v31 = 2522;
    return sub_12F630(v30, v29, v31, v3);
  }
  v7 = dword_11C6F4;
  v8 = (uint8_t)(v3 - 16);
  v9 = dword_11C6F4 + 696 * v8;
  result = *(uint8_t *)(v9 + 37);
  if ( *(uint8_t *)(v9 + 37) )
  {
    v10 = *(uint8_t *)(v9 + 34);
    v1[45] = *(uint32_t *)(v9 + 38);
    v11 = dword_11C6FC;
    *((uint16_t *)off_11C6F8 + 2) = *(uint16_t *)(v9 + 42);
    result = v1[4];
    if ( result == v11 + 1320 * v10 )
    {
      result = *(uint32_t *)off_11C704 & 0x3F;
      if ( *(uint8_t *)(*(uint32_t *)off_11C700 + 62) + 3 < result )
      {
        v12 = *(uint32_t *)off_11C70C;
        v13 = v1[42];
        v14 = *(uint32_t *)off_11C708 & 0xF;
        v15 = HIWORD(*(uint32_t *)off_11C708) & 3;
        v16 = (*(uint32_t *)off_11C708 & 0x80000) != 0;
        v35 = (uint16_t)*(uint32_t *)off_11C708 >> 4;
        *((uint16_t *)v1 + 94) = v35;
        *((uint8_t *)v1 + 191) = v14;
        *((uint8_t *)v1 + 195) = v15;
        v17 = (uint8_t)v12 >> 4;
        v18 = v12 & 7;
        if ( v16 )
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
        v19 = (v12 >> 9) & 7;
        *((uint8_t *)v1 + 192) = v33;
        *((uint8_t *)v1 + 193) = v17;
        *((uint8_t *)v1 + 199) = (v12 & 0x1000) != 0;
        *((uint8_t *)v1 + 194) = v19;
        *((uint8_t *)v1 + 196) = v18;
        if ( v14 )
        {
          LOBYTE(v20) = *((uint8_t *)v1 + 198);
        }
        else
        {
          v34 = v12 >> 30;
          v20 = HIBYTE(v12) & 3;
          *((uint8_t *)v1 + 197) = *(uint8_t *)(dword_11C72C + v34);
          *((uint8_t *)v1 + 198) = v20;
        }
        while ( *(int *)off_11C724 >= 0 )
          ;
        v21 = *(uint32_t *)off_11C724 & dword_11C710;
        if ( v18 > 2 )
          v22 = *(uint16_t *)(dword_11C730 + 2 * (3 * ((uint8_t)(v18 - 3) >> 1) + v32 + 6 * v17)) << ((v18 - 3) & 1);
        else
          v22 = *(uint16_t *)(*(uint32_t *)(dword_11C714 + 4 * v18) + 2 * (3 * v17 + v32));
        v23 = (unsigned int *)off_11C728;
        if ( v21 >= *(uint32_t *)(v13 + 12) )
          v21 = *(uint32_t *)(v13 + 12);
        v1[44] = v21;
        v24 = *v23;
        v25 = *(uint8_t *)(v13 + 28);
        v26 = v7 + 696 * v8;
        v27 = v36 | v17;
        result = *(uint32_t *)(v26 + 340);
        v1[42] = v26;
        *((uint8_t *)v1 + 200) = v21 > 0x27;
        *((uint16_t *)v1 + 93) = v25 * (1 << v20) * v22;
        v1[43] = (HIBYTE(v24) << 6) | 0x13;
        *(uint16_t *)(result + 130) = v27 | ((uint16_t)v15 << 7) | (16 * v19) | 0x3000;
        *(uint16_t *)(result + 132) = v18 | (8 * v35);
        v1[51] = 0;
      }
    }
  }
  else
  {
LABEL_18:
    v28 = *(uint16_t **)(v4 + 8);
    *((uint16_t *)v1 + 90) = v28[5];
    *((uint16_t *)v1 + 91) = v28[6];
    *((uint16_t *)v1 + 92) = v28[7];
  }
  return result;
}

