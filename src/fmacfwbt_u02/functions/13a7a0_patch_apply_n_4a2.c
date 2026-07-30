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

extern uint32_t dword_13AA18;
extern uint32_t dword_13AA14;

// patch_apply_n_4a2 @ 0x13a7a0, size 626 bytes
// Doc: patch_apply_n_4a2 [patch]: apply firmware patch table entry
// patch_apply_n_4a2 [patch]: apply firmware patch table entry
int  patch_apply_n_4a2(int a1, int a2)
{
  int v2; // r11
  int v3; // r10
  int v4; // r8
  int v5; // r7
  int v6; // r6
  int v7; // r3
  int v8; // lr
  int v10; // r2
  int v12; // r4
  int16_t v13; // r3
  int v14; // r1
  int v15; // r0
  int16_t v16; // r1
  int v17; // r0
  int v18; // r3
  int v19; // r12
  int v20; // r3
  int v21; // r3
  int v22; // r3
  int16_t v24; // lr
  int16_t v25; // r3
  int16_t v26; // r3
  int v27; // r6
  int v28; // r6
  int v29; // r0
  int16_t v30; // r3
  int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch]
  int v33; // [sp+Ch] [bp-8h]

  v2 = *(uint8_t *)(a1 + 29);
  v3 = dword_13AA18;
  v4 = *(uint8_t *)(a1 + 28);
  v5 = dword_13AA14;
  v6 = 696 * v2;
  v7 = dword_13AA18 + 696 * v2;
  v8 = dword_13AA14 + 1320 * v4;
  v32 = *(uint32_t *)(v7 + 184);
  v10 = **(uint32_t **)(v7 + 188);
  v31 = *(uint32_t *)(v8 + 1200);
  v12 = a2 - *(uint8_t *)(a1 + 50);
  if ( *(uint8_t *)(v8 + 106) )
  {
    v13 = 0;
  }
  else
  {
    if ( (*(uint32_t *)(v7 + 4) & 0x20) == 0 )
    {
      v13 = 0;
      v14 = *(uint8_t *)(a1 + 27);
      if ( v14 == 255 )
        goto LABEL_4;
      goto LABEL_26;
    }
    v33 = **(uint32_t **)(v7 + 188);
    v29 = sub_11C7A4(a1, dword_13AA18 + 696 * v2);
    v10 = v33;
    *(uint32_t *)(a2 - 4) = v29;
    v13 = 0x8000;
  }
  v14 = *(uint8_t *)(a1 + 27);
  if ( v14 == 255 )
  {
LABEL_4:
    v15 = *(uint16_t *)(a1 + 30);
    *(uint16_t *)v12 = v13 | 8;
    *(uint8_t *)(v12 + 22) = 0;
    *(uint8_t *)(v12 + 23) = 0;
    v16 = v13 | 8;
    if ( (v15 & 0x800) != 0 )
    {
LABEL_5:
      v16 = v13 & 0xFCF7 | 8;
      *(uint16_t *)v12 = v16;
      goto LABEL_6;
    }
    if ( (v15 & 0x100) != 0 )
      goto LABEL_30;
    goto LABEL_32;
  }
LABEL_26:
  v15 = *(uint16_t *)(a1 + 30);
  *(uint16_t *)(v12 + 22) = 16 * *(uint16_t *)(a1 + 32);
  *(uint8_t *)(v12 + 1) = 0;
  if ( (v15 & 0x200) != 0 )
    LOWORD(v14) = v14 | 0x10;
  *(uint8_t *)v12 = 0x80;
  v24 = v13 | 0x88;
  if ( (v15 & 0x100) != 0 )
  {
    *(uint16_t *)(v12 + 30) = v14;
    v13 |= 0x80u;
    *(uint16_t *)v12 = v24;
    if ( (v15 & 0x800) != 0 )
      goto LABEL_5;
LABEL_30:
    v25 = v13 | 0x308;
    *(uint16_t *)v12 = v25;
    v16 = v25;
    goto LABEL_6;
  }
  *(uint16_t *)(v12 + 24) = v14;
  v13 |= 0x80u;
  *(uint16_t *)v12 = v24;
  v16 = v24;
  if ( (v15 & 0x800) != 0 )
    goto LABEL_5;
LABEL_32:
  if ( *(uint8_t *)(v5 + 1320 * v4 + 106) )
  {
    if ( *(uint8_t *)(v5 + 1320 * v4 + 106) == 2 )
    {
      v30 = v13 | 0x208;
      *(uint16_t *)v12 = v30;
      v16 = v30;
    }
  }
  else
  {
    v26 = v13 | 0x108;
    *(uint16_t *)v12 = v26;
    v16 = v26;
  }
LABEL_6:
  v17 = v15 << 29;
  v18 = 1320 * v4;
  if ( v17 < 0 )
    v16 |= 0x2000u;
  v19 = v18 + 100;
  if ( v17 < 0 )
    *(uint16_t *)v12 = v16;
  *(uint16_t *)(v12 + 10) = *(uint16_t *)(v5 + v19);
  *(uint16_t *)(v12 + 12) = *(uint16_t *)(v5 + v19 + 2);
  *(uint16_t *)(v12 + 14) = *(uint16_t *)(v5 + v19 + 4);
  if ( (v16 & 0x300) == 0x100 )
  {
    v27 = v6 + 38;
    *(uint16_t *)(v12 + 4) = *(uint16_t *)(v3 + v27);
    *(uint16_t *)(v12 + 6) = *(uint16_t *)(v3 + v27 + 2);
    *(uint16_t *)(v12 + 8) = *(uint16_t *)(v3 + v27 + 4);
    *(uint16_t *)(v12 + 16) = *(uint16_t *)(a1 + 12);
    *(uint16_t *)(v12 + 18) = *(uint16_t *)(a1 + 14);
    *(uint16_t *)(v12 + 20) = *(uint16_t *)(a1 + 16);
  }
  else if ( (v16 & 0x300) == 0x200 )
  {
    *(uint16_t *)(v12 + 4) = *(uint16_t *)(a1 + 12);
    *(uint16_t *)(v12 + 6) = *(uint16_t *)(a1 + 14);
    *(uint16_t *)(v12 + 8) = *(uint16_t *)(a1 + 16);
    *(uint16_t *)(v12 + 16) = *(uint16_t *)(a1 + 18);
    *(uint16_t *)(v12 + 18) = *(uint16_t *)(a1 + 20);
    *(uint16_t *)(v12 + 20) = *(uint16_t *)(a1 + 22);
  }
  else if ( (v16 & 0x300) != 0 )
  {
    v28 = v6 + 38;
    *(uint16_t *)(v12 + 4) = *(uint16_t *)(v3 + v28);
    *(uint16_t *)(v12 + 6) = *(uint16_t *)(v3 + v28 + 2);
    *(uint16_t *)(v12 + 8) = *(uint16_t *)(v3 + v28 + 4);
    *(uint16_t *)(v12 + 16) = *(uint16_t *)(a1 + 12);
    *(uint16_t *)(v12 + 18) = *(uint16_t *)(a1 + 14);
    *(uint16_t *)(v12 + 20) = *(uint16_t *)(a1 + 16);
    *(uint16_t *)(v12 + 24) = *(uint16_t *)(a1 + 18);
    *(uint16_t *)(v12 + 26) = *(uint16_t *)(a1 + 20);
    *(uint16_t *)(v12 + 28) = *(uint16_t *)(a1 + 22);
  }
  else
  {
    *(uint16_t *)(v12 + 4) = *(uint16_t *)(a1 + 12);
    *(uint16_t *)(v12 + 6) = *(uint16_t *)(a1 + 14);
    *(uint16_t *)(v12 + 8) = *(uint16_t *)(a1 + 16);
    v20 = v18 + 368;
    *(uint16_t *)(v12 + 16) = *(uint16_t *)(v5 + v20);
    v21 = v20 + v5;
    *(uint16_t *)(v12 + 18) = *(uint16_t *)(v21 + 2);
    *(uint16_t *)(v12 + 20) = *(uint16_t *)(v21 + 4);
  }
  if ( v10
    && v31
    && ((*(uint32_t *)(v5 + 1320 * v4 + 1208) & 2) == 0
     || *(uint16_t *)(v3 + 696 * *(uint8_t *)(a1 + 29) + 56) != (uint16_t)__rev16(*(uint16_t *)(a1 + 24))) )
  {
    if ( !v32
      || (v22 = *(uint8_t *)(v32 + 96), v22 == 4)
      || (unsigned int)(v22 - 1) <= 1 && *(uint8_t *)(v3 + 696 * v2 + 669) > 1u )
    {
      *(uint16_t *)v12 = v16 | 0x4000;
    }
  }
  return v12;
}

