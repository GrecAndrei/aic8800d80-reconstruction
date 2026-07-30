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

extern uint32_t off_1352A0;
extern uint32_t dword_1352E8;
extern uint32_t dword_1352A4;
extern uint32_t off_1352A8;
extern uint32_t off_1352AC;
extern uint32_t off_1352B0;
extern uint32_t off_1352B4;
extern uint32_t off_1352E0;
extern uint32_t off_1352D0;
extern uint32_t dword_1352E4;
extern uint32_t dword_1352B8;
extern uint32_t dword_1352BC;
extern uint32_t off_1352C0;
extern uint32_t off_1352C4;
extern uint32_t off_1352C8;
extern uint32_t off_1352CC;
extern uint32_t dword_1352D4;
extern uint32_t off_1352D8;
extern uint32_t dword_1352DC;

// sub_135020 @ 0x135020, size 640 bytes
int  sub_135020(int a1)
{
  uint32_t *v2; // r5
  int v3; // r11
  int v4; // r7
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int result; // r0
  int v9; // r12
  uint8_t *v10; // r0
  unsigned int *v11; // r1
  unsigned int v12; // r2
  int *v13; // r3
  char *v14; // r1
  int *v15; // r3
  int v16; // r3
  int v17; // r2
  char v18; // lr
  int16_t v19; // r0
  int v20; // lr
  int v21; // r2
  int v22; // lr
  unsigned int v23; // r0
  unsigned int v24; // r3
  unsigned int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r3
  int v29; // r3
  void *v30; // r1
  uint16_t *v31; // r3
  int v32; // r3
  unsigned int v33; // r0
  uint32_t *v34; // r3
  uint32_t *v35; // r2
  int *v36; // r1
  int v37; // r0
  int v38; // [sp+Ch] [bp-8h]
  void *v39; // [sp+Ch] [bp-8h]

  v2 = off_1352A0;
  v3 = dword_1352E8;
  v4 = *(uint8_t *)(*((uint32_t *)off_1352A0 + 4) + 61);
  v5 = *((uint32_t *)off_1352A0 + 5);
  v38 = *((uint32_t *)off_1352A0 + 4);
  v6 = dword_1352E8 + 1320 * v4;
  v7 = *(uint8_t *)(v6 + 116);
  result = sub_12ECB0(dword_1352A4);
  v9 = v2[4];
  if ( v9 )
  {
    v10 = off_1352A8;
    v11 = (unsigned int *)off_1352AC;
    *(uint8_t *)(v5 + 9) = *(uint8_t *)(v38 + 61);
    v12 = *v11 & 0xFFFFFFEF;
    v13 = *((int **)off_1352B0 + 2);
    *(uint16_t *)v5 = a1;
    *v11 = v12;
    v14 = 0;
    v10[13] = 0;
    if ( v13 )
    {
      do
      {
        if ( !*((uint8_t *)v13 + 106) && *((uint8_t *)v13 + 108) )
          ++v14;
        v13 = (int *)*v13;
      }
      while ( v13 );
      if ( a1 )
        goto LABEL_8;
    }
    else
    {
      v14 = 0;
      if ( a1 )
      {
LABEL_8:
        v15 = (int *)off_1352B4;
        *(uint8_t *)(v5 + 8) = (*(uint32_t *)(v9 + 48) & 0x60) != 0;
        if ( *v15 < 0 && !v14 )
        {
          v35 = off_1352E0;
          v10[2] = 0;
          v36 = (int *)off_1352D0;
          v37 = dword_1352E4;
          *v35 |= 0x80000000;
          *v36 = v37;
        }
        rf_bus_mark_n_3b7(6u, 10);
        v2[2] = v6;
        *v2 = v5 - 12;
        bt_fw_init_handler(v6);
LABEL_10:
        feature_guard_sdio(256, dword_1352B8, *(uint8_t *)(v5 + 9), a1, *(uint16_t *)(v5 + 820));
        result = j_buffer_pool_get(v2[4] - 12);
        v2[4] = 0;
        *((uint8_t *)v2 + 33) = 0;
        return result;
      }
    }
    v16 = v3 + 1320 * v4;
    v17 = dword_1352BC;
    v18 = *(uint8_t *)(v16 + 116);
    *(uint32_t *)(v5 + 2) = *(uint32_t *)(v16 + 368);
    v19 = *(uint16_t *)(v16 + 372);
    *(uint8_t *)(v5 + 10) = v18;
    v20 = *(uint32_t *)(v16 + 72);
    *(uint16_t *)(v5 + 6) = v19;
    *(uint8_t *)(v5 + 11) = *(uint8_t *)(v20 + 24);
    v21 = *(uint8_t *)(v17 + 696 * v7 + 309);
    *(uint8_t *)(v5 + 826) = v21;
    *(uint8_t *)(v5 + 822) = *(uint8_t *)(v16 + 412);
    v22 = *(uint8_t *)(v16 + 413);
    v23 = *(uint16_t *)(v16 + 414);
    *(uint16_t *)(v5 + 824) = v23;
    if ( v22 == v21 )
    {
      *(uint32_t *)(v5 + 828) = *(uint16_t *)(v16 + 416);
    }
    else if ( v21 )
    {
      v24 = *(uint16_t *)(v16 + 416);
      if ( v23 >= v24 )
        v25 = v24 + 20;
      else
        v25 = v24 - 20;
      *(uint32_t *)(v5 + 828) = v25;
    }
    else
    {
      *(uint32_t *)(v5 + 828) = v23;
    }
    v26 = v3 + 1320 * v4;
    v27 = *(uint32_t *)(v26 + 472);
    *(uint32_t *)(v5 + 832) = *(uint16_t *)(v26 + 418);
    v28 = v27 & 1;
    *(uint8_t *)(v5 + 12) = v28;
    if ( v28 )
      LOBYTE(v28) = *(uint8_t *)(v26 + 457);
    *(uint8_t *)(v5 + 13) = v28;
    v29 = v3 + 1320 * v4;
    *(uint8_t *)(v5 + 8) = (*(uint32_t *)(v9 + 48) & 0x60) != 0;
    if ( *(uint8_t *)(v29 + 1224) )
    {
      *(uint32_t *)off_1352C0 = *(uint16_t *)(v29 + 100) | (*(uint16_t *)(v29 + 102) << 16);
      *(uint32_t *)off_1352C4 = *(uint16_t *)(v29 + 104);
      *(uint32_t *)off_1352C8 = *(uint16_t *)(v29 + 64) | (*(uint16_t *)(v29 + 66) << 16);
      *(uint32_t *)off_1352CC = *(uint16_t *)(v29 + 68);
    }
    v39 = v14;
    sub_12CBB4(v5);
    v30 = v39;
    *(uint32_t *)off_1352D0 = dword_1352D4;
    if ( v39 == (void *)1 )
    {
      v31 = (uint16_t *)(v3 + 1320 * v4);
      v30 = off_1352C0;
      *(uint32_t *)off_1352C0 = v31[50] | (v31[51] << 16);
      *(uint32_t *)off_1352C4 = v31[52];
    }
    if ( *(uint8_t *)(v3 + 1320 * v4 + 413) == 2 )
      sub_120AB4((int *)v6, 0, 1);
    v32 = v3 + 1320 * v4;
    v33 = *(uint16_t *)(v32 + 416);
    if ( v33 <= 0x1387 )
      sub_10D054(v33 | (*(uint8_t *)(v32 + 413) << 16) | 0x80000000, (int)v30, 4999);
    v34 = off_1352D8;
    *(uint8_t *)(v3 + 1320 * v4 + 149) = 1;
    timestamp_update_4f60(1320 * v4 + 152 + v3, dword_1352DC + v34[4]);
    rf_bus_mark_n_3b7(6u, 0);
    goto LABEL_10;
  }
  return result;
}

