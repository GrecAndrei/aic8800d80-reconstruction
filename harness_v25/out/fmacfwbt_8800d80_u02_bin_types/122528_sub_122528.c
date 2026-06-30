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

extern uint32_t off_1227BC;
extern uint32_t off_1227CC;
extern uint32_t off_1227C8;
extern uint32_t off_1227F4;
extern uint32_t off_122808;
extern uint32_t off_1227F8;
extern uint32_t off_1227FC;
extern uint32_t off_12280C;
extern uint32_t off_1227D4;
extern uint32_t off_1227D0;
extern uint32_t off_1227D8;
extern uint32_t off_1227E8;
extern uint32_t off_1227DC;
extern uint32_t dword_122804;
extern uint32_t off_1227E4;
extern uint32_t off_122800;
extern uint32_t off_1227E0;
extern uint32_t off_1227F0;
extern uint32_t off_1227EC;

// sub_122528 @ 0x122528, size 660 bytes
uint32_t * sub_122528(uint32_t *result, int a2)
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

  v2 = (float *)off_1227BC;
  v3 = *(char *)off_1227BC;
  if ( !*(uint8_t *)off_1227BC )
    return result;
  v4 = (int)result;
  v5 = *((uint8_t *)off_1227BC + 2);
  v6 = *((char *)off_1227BC + 1);
  v7 = *((float *)off_1227BC + 1);
  result = (uint32_t *)msg_get_value(4);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_1227C0) + (float)a2) * flt_1227C4;
  v9 = (char)(int)v8;
  if ( v9 < v3 - v6 )
  {
    v10 = off_1227CC;
    v5 = 1;
    if ( *((uint8_t *)off_1227C8 + 408) )
      goto LABEL_8;
LABEL_27:
    v29 = *(uint8_t *)off_1227F4;
    v30 = off_122808;
    result = off_1227F8;
    v31 = off_1227FC;
    *(uint8_t *)off_12280C = 0;
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
  v10 = off_1227CC;
  if ( !*((uint8_t *)off_1227C8 + 408) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = off_122808;
  v12 = (unsigned int *)off_1227F8;
  v13 = (unsigned int *)off_1227FC;
  v14 = off_1227D4;
  v15 = *(uint32_t *)v10;
  v16 = (char *)off_12280C;
  v17 = (uint32_t *)((char *)off_1227D0 + 268);
  *(uint32_t *)off_122808 += *(uint32_t *)off_1227D0;
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
  v23 = *(uint8_t *)off_1227D8;
  *v13 = v20;
  v24 = (uint8_t)(v22 + 1);
  *v16 = v24;
  if ( v23 == v24 )
  {
    if ( *(uint8_t *)off_1227E8 == 1 && v19 <= 0x13 && v37 <= 9 )
    {
      v38 = (uint8_t *)off_1227DC;
      *(uint8_t *)off_1227DC = 2;
    }
    else if ( *((uint8_t *)off_1227D8 + 3) <= v37 || v19 <= v37 * *((uint8_t *)off_1227D8 + 2) )
    {
      v38 = (uint8_t *)off_1227DC;
      *(uint8_t *)off_1227DC = 0;
    }
    else
    {
      v38 = (uint8_t *)off_1227DC;
      *(uint8_t *)off_1227DC = 1;
    }
    feature_guard_sdio(64, dword_122804);
    v25 = *v38;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(uint32_t *)v10 = 0;
    if ( v25 == 1 )
    {
      v34 = off_1227E4;
      v35 = *(uint8_t *)off_1227E4;
      *(uint8_t *)off_122800 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
    else if ( !v25 )
    {
      v32 = off_122800;
      v33 = *(uint8_t *)off_122800;
      *(uint8_t *)off_1227E4 = 0;
      if ( v33 != 255 )
        *v32 = v33 + 1;
    }
  }
  else
  {
    v25 = *(uint8_t *)off_1227DC;
  }
  v26 = (unsigned int *)off_1227E0;
  *(uint32_t *)off_1227E0 &= ~0x4000u;
  *v26 = (uint16_t)*v26;
  *v26 = *v26 & 0xFFFFFC00 | 0x44;
  *v26 |= 0x8000u;
  while ( (*v26 & 0x8000) != 0 )
    ;
  v27 = (unsigned int *)off_1227E0;
  *v26 = *v26 & 0xFFFFFC00 | 0x54;
  result = (uint32_t *)(*v26 | 0x8000);
  *v26 = (unsigned int)result;
  while ( (*v27 & 0x8000) != 0 )
    ;
  *v27 = *v27 & 0xFFFFFC00 | 1;
  *v27 |= 0x8000u;
  if ( v25 == 2 )
    goto LABEL_22;
  v28 = *((uint8_t *)off_1227D8 + 1);
  if ( *(uint8_t *)off_1227E4 > v28 )
  {
    if ( *(uint8_t *)off_1227E8 != 1 )
      result = (uint32_t *)mmio_reg_read_modify(v4);
    goto LABEL_22;
  }
  if ( *(uint8_t *)off_122800 > v28 >> 1 && *(uint8_t *)off_1227E8 )
LABEL_28:
    result = (uint32_t *)mmio_reg_init_patch(v4);
LABEL_22:
  if ( !v5 || *((uint8_t *)off_1227F0 + 18) )
    *(uint32_t *)off_1227EC &= ~0x200u;
  else
    *(uint32_t *)off_1227EC |= 0x200u;
  *((uint8_t *)v2 + 2) = v5;
  v2[1] = v8;
  return result;
}

