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

extern uint32_t off_122448;
extern uint32_t off_122458;
extern uint32_t off_122454;
extern uint32_t off_122480;
extern uint32_t off_122494;
extern uint32_t off_122484;
extern uint32_t off_122488;
extern uint32_t off_122498;
extern uint32_t off_122460;
extern uint32_t off_12245C;
extern uint32_t off_122464;
extern uint32_t off_122474;
extern uint32_t off_122468;
extern uint32_t dword_122490;
extern uint32_t off_122470;
extern uint32_t off_12248C;
extern uint32_t off_12246C;
extern uint32_t off_12247C;
extern uint32_t off_122478;

// sub_1221B4 @ 0x1221b4, size 660 bytes
uint32_t * sub_1221B4(uint32_t *result, int a2)
{
  float *v2; // r4
  int v3; // r7
  int v4; // r5
  int v5; // r6
  int v6; // r8
  float v7; // s17
  float v8; // s16
  int v9; // r3
  uint8_t *v10; // r7
  uint32_t *v11; // r10
  unsigned int *v12; // r9
  unsigned int *v13; // r8
  uint32_t *v14; // r0
  unsigned int v15; // r12
  char *v16; // r11
  uint32_t *v17; // r3
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r0
  unsigned int v21; // r2
  char v22; // r2
  int v23; // r1
  int v24; // r2
  int v25; // r1
  unsigned int *v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r3
  int v29; // r2
  uint32_t *v30; // r12
  uint32_t *v31; // r1
  uint8_t *v32; // r2
  int v33; // r3
  uint8_t *v34; // r0
  int v35; // r2
  unsigned int v37; // [sp+18h] [bp-Ch]
  uint8_t *v38; // [sp+18h] [bp-Ch]

  v2 = (float *)off_122448;
  v3 = *(char *)off_122448;
  if ( !*(uint8_t *)off_122448 )
    return result;
  v4 = (int)result;
  v5 = *((uint8_t *)off_122448 + 2);
  v6 = *((char *)off_122448 + 1);
  v7 = *((float *)off_122448 + 1);
  result = (uint32_t *)sub_12CD48(4);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12244C) + (float)a2) * flt_122450;
  v9 = (char)(int)v8;
  if ( v9 < v3 - v6 )
  {
    v10 = off_122458;
    v5 = 1;
    if ( *((uint8_t *)off_122454 + 408) )
      goto LABEL_8;
LABEL_27:
    v29 = *(uint8_t *)off_122480;
    v30 = off_122494;
    result = off_122484;
    v31 = off_122488;
    *(uint8_t *)off_122498 = 0;
    *(uint32_t *)v10 = 0;
    *v30 = 0;
    *result = 0;
    *v31 = 0;
    if ( !v29 )
      goto LABEL_22;
    goto LABEL_28;
  }
  if ( v3 < v9 )
    v5 = 0;
  v10 = off_122458;
  if ( !*((uint8_t *)off_122454 + 408) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = off_122494;
  v12 = (unsigned int *)off_122484;
  v13 = (unsigned int *)off_122488;
  v14 = off_122460;
  v15 = *(uint32_t *)v10;
  v16 = (char *)off_122498;
  v17 = (uint32_t *)((char *)off_12245C + 268);
  *(uint32_t *)off_122494 += *(uint32_t *)off_12245C;
  v18 = *v13;
  v19 = *v17 + *v12;
  *v12 = v19;
  v20 = *v14 + v18;
  if ( v20 <= v15 )
    v21 = 0;
  else
    v21 = v20 - v15;
  v37 = v21;
  v22 = *v16;
  v23 = *(uint8_t *)off_122464;
  *v13 = v20;
  v24 = (uint8_t)(v22 + 1);
  *v16 = v24;
  if ( v23 == v24 )
  {
    if ( *(uint8_t *)off_122474 == 1 && v19 <= 0x13 && v37 <= 9 )
    {
      v38 = (uint8_t *)off_122468;
      *(uint8_t *)off_122468 = 2;
    }
    else if ( *((uint8_t *)off_122464 + 3) <= v37 || v19 <= v37 * *((uint8_t *)off_122464 + 2) )
    {
      v38 = (uint8_t *)off_122468;
      *(uint8_t *)off_122468 = 0;
    }
    else
    {
      v38 = (uint8_t *)off_122468;
      *(uint8_t *)off_122468 = 1;
    }
    sub_12EB90(64, dword_122490);
    v25 = *v38;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(uint32_t *)v10 = 0;
    if ( v25 == 1 )
    {
      v34 = off_122470;
      v35 = *(uint8_t *)off_122470;
      *(uint8_t *)off_12248C = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
    else if ( !v25 )
    {
      v32 = off_12248C;
      v33 = *(uint8_t *)off_12248C;
      *(uint8_t *)off_122470 = 0;
      if ( v33 != 255 )
        *v32 = v33 + 1;
    }
  }
  else
  {
    v25 = *(uint8_t *)off_122468;
  }
  v26 = (unsigned int *)off_12246C;
  *(uint32_t *)off_12246C &= ~0x4000u;
  *v26 = (uint16_t)*v26;
  *v26 = *v26 & 0xFFFFFC00 | 0x44;
  *v26 |= 0x8000u;
  while ( (*v26 & 0x8000) != 0 )
    ;
  v27 = (unsigned int *)off_12246C;
  *v26 = *v26 & 0xFFFFFC00 | 0x54;
  result = (uint32_t *)(*v26 | 0x8000);
  *v26 = (unsigned int)result;
  while ( (*v27 & 0x8000) != 0 )
    ;
  *v27 = *v27 & 0xFFFFFC00 | 1;
  *v27 |= 0x8000u;
  if ( v25 == 2 )
    goto LABEL_22;
  v28 = *((uint8_t *)off_122464 + 1);
  if ( *(uint8_t *)off_122470 > v28 )
  {
    if ( *(uint8_t *)off_122474 != 1 )
      result = (uint32_t *)sub_1220DC(v4);
    goto LABEL_22;
  }
  if ( *(uint8_t *)off_12248C > v28 >> 1 && *(uint8_t *)off_122474 )
LABEL_28:
    result = (uint32_t *)sub_122044(v4);
LABEL_22:
  if ( !v5 || *((uint8_t *)off_12247C + 18) )
    *(uint32_t *)off_122478 &= ~0x200u;
  else
    *(uint32_t *)off_122478 |= 0x200u;
  *((uint8_t *)v2 + 2) = v5;
  v2[1] = v8;
  return result;
}

