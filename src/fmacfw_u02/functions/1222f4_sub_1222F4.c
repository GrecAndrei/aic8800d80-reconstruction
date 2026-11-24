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


extern float flt_12258C;
extern float flt_122590;
extern uint32_t off_122588;
extern uint32_t off_122594;
extern uint32_t off_122598;
extern uint32_t off_12259C;
extern uint32_t off_1225A0;
extern uint32_t off_1225A4;
extern uint32_t off_1225A8;
extern uint32_t off_1225AC;
extern uint32_t off_1225B0;
extern uint32_t off_1225B4;
extern uint32_t off_1225B8;
extern uint32_t off_1225BC;
extern uint32_t off_1225C0;
extern uint32_t off_1225C4;
extern uint32_t off_1225C8;
extern uint32_t off_1225CC;
extern uint32_t off_1225D4;
extern uint32_t off_1225D8;

// rf_tx_power_calc @ 0x1222f4, size 660 bytes
uint32_t * rf_tx_power_calc(uint32_t *result, int a2)
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

  v2 = off_122588;
  v3 = *(char *)off_122588;
  if ( !*(uint8_t *)off_122588 )
    return result;
  v4 = result;
  v5 = *(uint8_t *)(off_122588 + 2);
  v6 = *(char *)(off_122588 + 1);
  v7 = *(float *)(off_122588 + 4);
  result = (uint32_t *)rx_rate_field_parse(4u);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12258C) + (float)a2) * flt_122590;
  v9 = (char)(int)v8;
  v39 = v9;
  if ( v9 < v3 - v6 )
  {
    v10 = off_122598;
    v5 = 1;
    if ( LOBYTE(((uint32_t *)(uintptr_t)off_122594)[102]) )
      goto LABEL_8;
LABEL_27:
    v30 = *(uint8_t *)off_1225C0;
    v31 = off_1225D4;
    result = off_1225C4;
    v32 = off_1225C8;
    *(uint8_t *)off_1225D8 = 0;
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
  v10 = off_122598;
  if ( !LOBYTE(((uint32_t *)(uintptr_t)off_122594)[102]) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = off_1225D4;
  v12 = (unsigned int *)off_1225C4;
  v13 = (unsigned int *)off_1225C8;
  v14 = off_1225A0;
  v15 = *(uint32_t *)v10;
  v16 = (char *)off_1225D8;
  v17 = *(uint32_t *)off_12259C + *(uint32_t *)off_1225D4;
  v18 = (uint32_t *)((char *)off_12259C + 268);
  *(uint32_t *)off_1225D4 = v17;
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
  v24 = *(uint8_t *)off_1225A4;
  *v13 = v21;
  v25 = (uint8_t)(v23 + 1);
  *v16 = v25;
  if ( v24 == v25 )
  {
    if ( *(uint8_t *)off_1225B4 == 1 && v20 <= 0x13 && v40 <= 9 )
    {
      v41 = (uint8_t *)off_1225A8;
      v33 = 2;
      *(uint8_t *)off_1225A8 = 2;
    }
    else if ( *(uint8_t *)(off_1225A4 + 3) <= v40 || v20 <= v40 * *(uint8_t *)(off_1225A4 + 2) )
    {
      v41 = (uint8_t *)off_1225A8;
      v33 = 0;
      *(uint8_t *)off_1225A8 = 0;
    }
    else
    {
      v41 = (uint8_t *)off_1225A8;
      v33 = 1;
      *(uint8_t *)off_1225A8 = 1;
    }
    check_status_bits(64, "$%d %d,%d,%d,%d %d\n", v33, v20, v21, v15, v17, v39);
    v26 = *v41;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(uint32_t *)v10 = 0;
    if ( v26 == 1 )
    {
      v36 = off_1225B0;
      v37 = *(uint8_t *)off_1225B0;
      *(uint8_t *)off_1225CC = 0;
      if ( v37 != 255 )
        *v36 = v37 + 1;
    }
    else if ( !v26 )
    {
      v34 = off_1225CC;
      v35 = *(uint8_t *)off_1225CC;
      *(uint8_t *)off_1225B0 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
  }
  else
  {
    v26 = *(uint8_t *)off_1225A8;
  }
  v27 = off_1225AC;
  *(uint32_t *)off_1225AC &= ~0x4000u;
  *v27 = (uint16_t)*v27;
  *v27 = *v27 & 0xFFFFFC00 | 0x44;
  *v27 |= 0x8000u;
  while ( (*v27 & 0x8000) != 0 )
    ;
  v28 = (unsigned int *)off_1225AC;
  *v27 = *v27 & 0xFFFFFC00 | 0x54;
  result = (uint32_t *)(*v27 | 0x8000);
  *v27 = result;
  while ( (*v28 & 0x8000) != 0 )
    ;
  *v28 = *v28 & 0xFFFFFC00 | 1;
  *v28 |= 0x8000u;
  if ( v26 == 2 )
    goto LABEL_22;
  v29 = *(uint8_t *)(off_1225A4 + 1);
  if ( *(uint8_t *)off_1225B0 > v29 )
  {
    if ( *(uint8_t *)off_1225B4 != 1 )
      result = (uint32_t *)mmio_masked_write((int)v4);
    goto LABEL_22;
  }
  if ( *(uint8_t *)off_1225CC > v29 >> 1 && *(uint8_t *)off_1225B4 )
LABEL_28:
    result = (uint32_t *)mmio_update((int)v4);
LABEL_22:
  if ( !v5 || *((uint8_t *)off_1225BC + 18) )
    *(uint32_t *)off_1225B8 &= ~0x200u;
  else
    *(uint32_t *)off_1225B8 |= 0x200u;
  *(uint8_t *)(v2 + 2) = v5;
  *(float *)(v2 + 4) = v8;
  return result;
}
