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


extern float flt_12244C;
extern float flt_122450;
extern uint32_t off_122448;
extern uint32_t off_122454;
extern uint32_t off_122458;
extern uint32_t off_12245C;
extern uint32_t off_122460;
extern uint32_t off_122464;
extern uint32_t off_122468;
extern uint32_t off_12246C;
extern uint32_t off_122470;
extern uint32_t off_122474;
extern uint32_t off_122478;
extern uint32_t off_12247C;
extern uint32_t off_122480;
extern uint32_t off_122484;
extern uint32_t off_122488;
extern uint32_t off_12248C;
extern uint32_t off_122494;
extern uint32_t off_122498;

// process_hci_packet @ 0x1221b4, size 660 bytes
uint32_t * process_hci_packet(uint32_t *result, int a2)
{
  unsigned int v2; // r4
  int v3; // r7
  uint32_t *v4; // r5
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
  int v17; // lr
  uint32_t *v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r2
  char v23; // r2
  int v24; // r1
  int v25; // r2
  int v26; // r1
  uint32_t *v27; // r3
  unsigned int *v28; // r2
  unsigned int v29; // r3
  int v30; // r2
  uint32_t *v31; // r12
  uint32_t *v32; // r1
  int v33; // r2
  uint8_t *v34; // r2
  int v35; // r3
  uint8_t *v36; // r0
  int v37; // r2
  int v39; // [sp+14h] [bp-10h]
  unsigned int v40; // [sp+18h] [bp-Ch]
  uint8_t *v41; // [sp+18h] [bp-Ch]

  v2 = off_122448;
  v3 = *(char *)off_122448;
  if ( !*(uint8_t *)off_122448 )
    return result;
  v4 = result;
  v5 = *(uint8_t *)(off_122448 + 2);
  v6 = *(char *)(off_122448 + 1);
  v7 = *(float *)(off_122448 + 4);
  result = (uint32_t *)hci_cmd_handler(4u);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12244C) + (float)a2) * flt_122450;
  v9 = (char)(int)v8;
  v39 = v9;
  if ( v9 < v3 - v6 )
  {
    v10 = off_122458;
    v5 = 1;
    if ( LOBYTE(((uint32_t *)(uintptr_t)off_122454)[102]) )
      goto LABEL_8;
LABEL_27:
    v30 = *(uint8_t *)off_122480;
    v31 = off_122494;
    result = off_122484;
    v32 = off_122488;
    *(uint8_t *)off_122498 = 0;
    *(uint32_t *)v10 = 0;
    *v31 = 0;
    *result = 0;
    *v32 = 0;
    if ( !v30 )
      goto LABEL_22;
    goto LABEL_28;
  }
  if ( v3 < v9 )
    v5 = 0;
  v10 = off_122458;
  if ( !LOBYTE(((uint32_t *)(uintptr_t)off_122454)[102]) )
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
  v17 = *(uint32_t *)off_12245C + *(uint32_t *)off_122494;
  v18 = (uint32_t *)((char *)off_12245C + 268);
  *(uint32_t *)off_122494 = v17;
  v19 = *v13;
  v20 = *v18 + *v12;
  *v12 = v20;
  v21 = *v14 + v19;
  if ( v21 <= v15 )
    v22 = 0;
  else
    v22 = v21 - v15;
  v40 = v22;
  v23 = *v16;
  v24 = *(uint8_t *)off_122464;
  *v13 = v21;
  v25 = (uint8_t)(v23 + 1);
  *v16 = v25;
  if ( v24 == v25 )
  {
    if ( *(uint8_t *)off_122474 == 1 && v20 <= 0x13 && v40 <= 9 )
    {
      v41 = (uint8_t *)off_122468;
      v33 = 2;
      *(uint8_t *)off_122468 = 2;
    }
    else if ( *(uint8_t *)(off_122464 + 3) <= v40 || v20 <= v40 * *(uint8_t *)(off_122464 + 2) )
    {
      v41 = (uint8_t *)off_122468;
      v33 = 0;
      *(uint8_t *)off_122468 = 0;
    }
    else
    {
      v41 = (uint8_t *)off_122468;
      v33 = 1;
      *(uint8_t *)off_122468 = 1;
    }
    check_feature_flag(64, "$%d %d,%d,%d,%d %d\n", v33, v20, v21, v15, v17, v39);
    v26 = *v41;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(uint32_t *)v10 = 0;
    if ( v26 == 1 )
    {
      v36 = off_122470;
      v37 = *(uint8_t *)off_122470;
      *(uint8_t *)off_12248C = 0;
      if ( v37 != 255 )
        *v36 = v37 + 1;
    }
    else if ( !v26 )
    {
      v34 = off_12248C;
      v35 = *(uint8_t *)off_12248C;
      *(uint8_t *)off_122470 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
  }
  else
  {
    v26 = *(uint8_t *)off_122468;
  }
  v27 = off_12246C;
  *(uint32_t *)off_12246C &= ~0x4000u;
  *v27 = (uint16_t)*v27;
  *v27 = *v27 & 0xFFFFFC00 | 0x44;
  *v27 |= 0x8000u;
  while ( (*v27 & 0x8000) != 0 )
    ;
  v28 = (unsigned int *)off_12246C;
  *v27 = *v27 & 0xFFFFFC00 | 0x54;
  result = (uint32_t *)(*v27 | 0x8000);
  *v27 = result;
  while ( (*v28 & 0x8000) != 0 )
    ;
  *v28 = *v28 & 0xFFFFFC00 | 1;
  *v28 |= 0x8000u;
  if ( v26 == 2 )
    goto LABEL_22;
  v29 = *(uint8_t *)(off_122464 + 1);
  if ( *(uint8_t *)off_122470 > v29 )
  {
    if ( *(uint8_t *)off_122474 != 1 )
      result = (uint32_t *)rf_switch_channel((int)v4);
    goto LABEL_22;
  }
  if ( *(uint8_t *)off_12248C > v29 >> 1 && *(uint8_t *)off_122474 )
LABEL_28:
    result = (uint32_t *)rf_setup_channel((int)v4);
LABEL_22:
  if ( !v5 || *((uint8_t *)off_12247C + 18) )
    *(uint32_t *)off_122478 &= ~0x200u;
  else
    *(uint32_t *)off_122478 |= 0x200u;
  *(uint8_t *)(v2 + 2) = v5;
  *(float *)(v2 + 4) = v8;
  return result;
}
