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

extern uint32_t dword_10E76C;
extern uint32_t dword_10E770;
extern uint32_t off_10E774;
extern uint32_t off_10E768;
extern uint32_t dword_10E778;
extern uint32_t dword_10E750;
extern uint32_t dword_10E754;
extern uint32_t dword_10E758;
extern uint32_t dword_10E75C;
extern uint32_t dword_10E77C;
extern uint32_t dword_10E780;
extern uint32_t dword_10E760;
extern uint32_t dword_10E764;
extern uint32_t dword_10E784;
extern uint32_t dword_10E790;
extern uint32_t dword_10E788;
extern uint32_t dword_10E78C;

// sub_10E4D8 @ 0x10e4d8, size 628 bytes
int sub_10E4D8()
{
  int v0; // r3
  int v1; // r0
  uint32_t *v2; // r4
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  int v6; // r5
  char v7; // r0
  int v8; // r4
  int v9; // r3
  int v10; // r6
  uint64_t v11; // r0
  uint64_t v12; // r0
  int v13; // r0
  int v14; // r8
  int v15; // r4
  uint32_t *v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  int v20; // r3
  int v21; // r3
  int v22; // r11
  uint32_t *v23; // r6
  int v24; // r10
  int v25; // r7
  int v26; // r4
  int v27; // r2
  int v28; // r9
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  int v32; // r5
  int v33; // r2
  int v34; // r3
  uint32_t *v35; // r2
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  int v39; // r0
  int v41; // [sp+4h] [bp-10h]
  int v42; // [sp+8h] [bp-Ch]
  int v43; // [sp+Ch] [bp-8h]

  v0 = dword_10E76C;
  v1 = dword_10E770;
  v2 = off_10E774;
  *((uint32_t *)off_10E768 + 14) = 296;
  v2[3] = v0 | v2[3] & 0xE0000000;
  sub_10EFB4(v1, 1024, 15360);
  v2[2] = dword_10E778 & v2[2] | 0x1200000F;
  v2[1] = 1;
  while ( v2[7] != 1 )
    ;
  v2[7] = 1;
  v3 = sub_12752C(v2[4]);
  v4 = sub_127620(v3, HIDWORD(v3), dword_10E750, dword_10E754);
  v5 = sub_1272B0(v4, HIDWORD(v4), dword_10E758, dword_10E75C);
  v6 = sub_127B54(v5, HIDWORD(v5));
  sub_11F504(dword_10E77C, v6);
  v7 = sub_10EFA4(dword_10E780);
  v8 = v6 - 1400;
  v9 = abs32(v6 - 1400);
  v10 = v7 & 0x3F;
  v42 = v10;
  if ( v9 > 49 )
  {
    v11 = sub_12754C(v9);
    v12 = sub_127620(v11, HIDWORD(v11), dword_10E760, dword_10E764);
    v13 = sub_127B54(v12, HIDWORD(v12));
    v14 = v13;
    if ( v8 <= 0 )
    {
      v34 = v10;
      if ( v6 == 1400 )
        goto LABEL_39;
      v15 = v13 + v10;
    }
    else
    {
      v15 = v10 - v13;
    }
    if ( v15 > 32 )
    {
      v28 = 7;
      v26 = v10 + 7;
      goto LABEL_28;
    }
    if ( v15 > 11 )
    {
      sub_10EFB4(dword_10E780, v15, 63);
      v16 = off_10E774;
      *((uint32_t *)off_10E774 + 1) = 1;
      while ( v16[7] != 1 )
        ;
      v16[7] = 1;
      v17 = sub_12752C(v16[4]);
      v18 = sub_127620(v17, HIDWORD(v17), dword_10E750, dword_10E754);
      v19 = sub_1272B0(v18, HIDWORD(v18), dword_10E758, dword_10E75C);
      v6 = sub_127B54(v19, HIDWORD(v19));
      sub_11F504(dword_10E784, v14);
      if ( v6 <= 1400 )
        v20 = 1;
      else
        v20 = -1;
      v43 = v20;
      goto LABEL_19;
    }
    v34 = v10;
LABEL_39:
    v26 = v34 - 13;
    v28 = -13;
    goto LABEL_28;
  }
  if ( (unsigned int)(v9 - 1) > 0x30 )
  {
    v26 = v7 & 0x3F;
    v28 = 0;
    goto LABEL_28;
  }
  if ( v8 <= 0 )
    v21 = 1;
  else
    v21 = -1;
  v43 = v21;
  v14 = 0;
LABEL_19:
  v22 = dword_10E780;
  v23 = off_10E774;
  v24 = dword_10E790;
  v25 = v14 + 1;
  v26 = v43 + v14 * v43 + v42;
  while ( 1 )
  {
    v27 = v14;
    v28 = v26 - v42;
    v14 = v25;
    if ( (unsigned int)(v26 - 12) > 0x14 )
    {
      v28 = v43 * v27;
      v26 = v42 + v43 * v27;
      goto LABEL_28;
    }
    sub_10EFB4(v22, v26, 63);
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v29 = sub_12752C(v23[4]);
    v30 = sub_127620(v29, HIDWORD(v29), dword_10E750, dword_10E754);
    v31 = sub_1272B0(v30, HIDWORD(v30), dword_10E758, dword_10E75C);
    v41 = sub_127B54(v31, HIDWORD(v31));
    sub_11F504(v24, v28);
    v32 = v6 - 1400;
    v33 = v41 - 1400;
    if ( v32 * (v41 - 1400) <= 0 )
      break;
    v26 += v43;
    v6 = v41;
    ++v25;
  }
  if ( v33 < 0 )
    v33 = 1400 - v41;
  if ( v32 < 0 )
    v32 = -v32;
  if ( v33 > v32 )
  {
    v28 -= v43;
    v26 = v42 + v28;
  }
LABEL_28:
  sub_11F504(dword_10E788, v28);
  sub_10EFB4(dword_10E780, v26, 63);
  v35 = off_10E774;
  *((uint32_t *)off_10E774 + 1) = 1;
  while ( v35[7] != 1 )
    ;
  v35[7] = 1;
  v36 = sub_12752C(v35[4]);
  v37 = sub_127620(v36, HIDWORD(v36), dword_10E750, dword_10E754);
  v38 = sub_1272B0(v37, HIDWORD(v37), dword_10E758, dword_10E75C);
  v39 = sub_127B54(v38, HIDWORD(v38));
  sub_11F504(dword_10E78C, v39);
  return sub_10EFB4(dword_10E770, 0, 15360);
}

