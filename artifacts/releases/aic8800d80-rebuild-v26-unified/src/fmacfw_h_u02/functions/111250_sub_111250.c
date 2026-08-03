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

extern uint32_t off_1114D8;
extern uint32_t off_1114D4;
extern uint32_t dword_1116E8;
extern uint32_t dword_1116E4;
extern uint32_t off_1116F4;
extern uint32_t off_111708;
extern uint32_t dword_11170C;
extern uint32_t dword_111730;
extern uint32_t off_111714;
extern uint32_t off_111710;
extern uint32_t dword_111740;
extern uint32_t off_111718;
extern uint32_t off_111738;
extern uint32_t dword_11173C;
extern uint32_t off_11171C;
extern uint32_t dword_111734;
extern uint32_t dword_111720;
extern uint32_t dword_1114DC;
extern uint32_t off_1114E0;
extern uint32_t off_1114E4;
extern uint32_t off_1114E8;
extern uint32_t off_1114F0;
extern uint32_t dword_1114F4;
extern uint32_t dword_1116F0;
extern uint32_t off_1116EC;
extern uint32_t dword_1116FC;
extern uint32_t off_1116F8;
extern uint32_t dword_111704;
extern uint32_t off_111700;
extern uint32_t off_1114F8;
extern uint32_t dword_11172C;
extern uint32_t off_111500;
extern uint32_t dword_1114FC;
extern uint32_t off_111508;
extern uint32_t off_111504;
extern uint32_t off_11150C;
extern uint32_t off_111514;
extern uint32_t off_111510;
extern uint32_t dword_111518;
extern uint32_t dword_111724;
extern uint32_t off_111728;
extern uint32_t off_1116E0;
extern uint32_t off_1116D8;
extern uint32_t dword_1116DC;
extern uint32_t dword_11151C;
extern uint32_t off_111520;
extern uint32_t off_111524;
extern uint32_t dword_111528;
extern uint32_t off_11152C;
extern uint32_t dword_111544;
extern uint32_t off_111554;
extern uint32_t off_111558;
extern uint32_t dword_111530;
extern uint32_t off_111534;
extern uint32_t off_111538;
extern uint32_t off_111548;
extern uint32_t off_11154C;
extern uint32_t dword_111550;
extern uint32_t dword_11153C;
extern uint32_t off_111540;

// sub_111250 @ 0x111250, size 1160 bytes
int sub_111250()
{
  int v0; // r4
  int v1; // r2
  int v2; // r2
  int v3; // r1
  uint32_t *v4; // r2
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r2
  int v10; // r5
  unsigned int v11; // r2
  char *v12; // r3
  uint32_t *v13; // r7
  uint32_t *v14; // r0
  int v15; // r3
  char *v16; // r1
  uint32_t *v17; // r0
  uint8_t *v18; // r5
  unsigned int v19; // r1
  unsigned int v20; // r2
  int result; // r0
  uint8_t *v22; // r5
  int v23; // r2
  uint8_t *v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r2
  uint32_t *v27; // r3
  uint8_t *v28; // r5
  int v29; // r2
  uint32_t *v30; // r0
  unsigned int v31; // r2
  uint32_t *v32; // r3
  unsigned int v33; // r3
  uint32_t *v34; // r7
  unsigned int v35; // r3
  char *v36; // r2
  uint32_t *v37; // r5
  int v38; // r6
  int v39; // r7
  unsigned int v40; // r3
  char *v41; // r2
  int v42; // r0
  int v43; // r5
  int v44; // r0
  int v45; // r1
  int v46; // r0
  int v47; // r1
  uint32_t *v48; // r2
  int v49; // r5
  int v50; // r1
  int v51; // r1
  uint8_t *v52; // r6
  int v53; // r1
  int v54; // r1
  uint32_t *v55; // r2
  int v56; // r1

  v0 = *(uint32_t *)off_1114D8;
  if ( **(int16_t **)off_1114D4 < 0 && !v0 )
  {
    sub_12F35C(dword_1116E8, dword_1116E4, 39);
    goto LABEL_10;
  }
  v1 = v0 << 18;
  if ( (v0 & 0x2000) != 0 )
  {
    v48 = off_1116F4;
    v49 = *(uint32_t *)off_111708;
    *(uint32_t *)off_111708 = *(uint32_t *)off_111708;
    v50 = dword_11170C;
    *v48 &= ~0x20u;
    sub_12EB90(2, v50);
    if ( (v49 & 4) != 0 )
    {
      v53 = dword_111730;
      *(uint8_t *)off_111714 = 1;
      sub_12EB90(2, v53);
    }
    if ( (v49 & 1) != 0 )
    {
      v52 = off_111714;
      *(uint32_t *)off_111710 = 16;
      if ( *v52 )
      {
        sub_12EB90(2, dword_111740);
        *v52 = 0;
      }
      if ( *(uint8_t *)off_111718 )
      {
        v55 = off_111738;
        *((uint8_t *)off_111718 + 1) = 1;
        v56 = dword_11173C;
        *v55 |= 1u;
        sub_12EB90(2, v56);
      }
      v1 = 0;
      *(uint8_t *)off_11171C = 0;
    }
    if ( (v49 & 2) != 0 )
    {
      v54 = dword_111734;
      *(uint8_t *)off_11171C = 1;
      sub_12EB90(2, v54);
    }
    if ( (v49 & 8) != 0 )
      sub_12E948(dword_111720, v51, v1);
  }
  if ( (v0 & 1) != 0 )
  {
    sub_12E948(dword_1114DC, v0 << 31, v1);
    *(uint32_t *)off_1114E0 = 1;
  }
  v2 = v0 << 26;
  if ( (v0 & 0x20) != 0 )
  {
    sub_1111CC(*(uint32_t *)off_1114E4);
    v2 = 32;
    *(uint32_t *)off_1114E0 = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v3 = *(uint32_t *)off_1114E8;
    v4 = off_1114F0;
    *(uint32_t *)off_1114E8 = *(uint32_t *)off_1114E8;
    sub_12E948(dword_1114F4, v3, *v4);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v42 = dword_1116F0;
  v43 = *(uint32_t *)off_1116EC;
  *(uint32_t *)off_1116EC = *(uint32_t *)off_1116EC;
  sub_12E948(v42, v43, v2);
  if ( (v43 & 4) != 0 )
  {
    v2 = (int)off_1116F4;
    *(uint32_t *)off_1116F4 &= ~1u;
  }
  if ( (v43 & 8) == 0 )
  {
LABEL_10:
    v5 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_60:
    v44 = dword_1116FC;
    v45 = *(uint32_t *)off_1116F8;
    *(uint32_t *)off_1116F8 = *(uint32_t *)off_1116F8;
    sub_12E948(v44, v45, v2);
    v6 = v0 << 8;
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_61;
  }
  v2 = (int)off_1116F4;
  v5 = v0 << 9;
  *(uint32_t *)off_1116F4 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_60;
LABEL_11:
  v6 = v0 << 8;
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_61:
  v46 = dword_111704;
  v47 = *(uint32_t *)off_111700;
  *(uint32_t *)off_111700 = *(uint32_t *)off_111700;
  sub_12E948(v46, v47, v6);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v7 = off_1114F8;
    v8 = *((uint8_t *)off_1114F8 + 1621);
    v9 = *((uint8_t *)off_1114F8 + 1622);
    if ( v8 >= v9 )
    {
      sub_12E948(dword_11172C, v8, v9);
    }
    else
    {
      v10 = *(uint32_t *)off_111500;
      v11 = *((uint8_t *)off_1114F8 + 1620)
          + 1
          - 81
          * ((unsigned int)(((unsigned int)dword_1114FC
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_1114F8 + 1620) + 1)) >> 32) >> 6);
      v12 = (char *)off_1114F8 + 20 * v11;
      v13 = off_111508;
      *((uint32_t *)v12 + 1) = *(uint32_t *)off_111504;
      v7[1621] = v8 + 1;
      v14 = off_11150C;
      *((uint32_t *)v12 + 2) = *v13;
      v12[12] = v10;
      v7[1620] = v11;
      v12[13] = BYTE1(v10) & 7;
      *v14 = 16;
      do
        v15 = *v14 & 0x20;
      while ( v15 );
      v16 = &v7[20 * v11];
      if ( (v16[13] & 4) == 0 )
        v15 = *(uint32_t *)(*((uint32_t *)v16 + 2) + 4);
      v17 = off_111514;
      *(uint32_t *)off_111510 = v15;
      *v17 = 16;
      sub_12D108(dword_111518);
      sub_12CFC4(256);
    }
    v6 = 1024;
    *(uint32_t *)off_1114E0 = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    sub_12E948(dword_111724, v5, v6);
    *(uint32_t *)off_111728 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v18 = off_1114F8;
    v19 = *((uint8_t *)off_1114F8 + 2433);
    v20 = *((uint8_t *)off_1114F8 + 2434);
    if ( v19 < v20 )
    {
      v38 = *(uint32_t *)off_1116E0;
      v39 = *(uint32_t *)off_1116D8;
      v40 = *((uint8_t *)off_1114F8 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_1116DC
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_1114F8 + 2432) + 1)) >> 32) >> 5);
      v41 = (char *)off_1114F8 + 20 * v40;
      *((uint8_t *)off_1114F8 + 2432) = v40;
      v41[1645] = BYTE1(v38) & 7;
      *((uint32_t *)v41 + 409) = v39;
      *((uint32_t *)v41 + 410) = v39;
      v41[1644] = v38;
      v18[2433] = v19 + 1;
      sub_12D108(v18 + 2436);
      sub_12CFC4(0x400000);
    }
    else
    {
      sub_12E948(dword_11151C, v19, v20);
    }
    *(uint32_t *)off_1114E0 = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(uint8_t *)off_111520 )
    {
      v22 = off_111524;
      v23 = *((uint8_t *)off_111524 + 369);
      *(uint8_t *)off_111520 = 0;
      if ( v23 )
        sub_10DBC0(1);
      else
        sub_10DBD4(1);
      if ( v22[374] == 1 )
        sub_124CF4(dword_111528);
    }
    v24 = off_11152C;
    v25 = *((uint8_t *)off_11152C + 3074);
    v26 = *((uint8_t *)off_11152C + 3073);
    if ( v25 < v26 )
    {
      v35 = *((uint8_t *)off_11152C + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_11152C + 3072) + 1)) >> 32) >> 7);
      v36 = (char *)off_11152C + 16 * v35;
      *((uint32_t *)v36 + 1) = *(uint32_t *)off_111554;
      v37 = off_111558;
      v24[3072] = v35;
      *((uint16_t *)v36 + 4) = *v37;
      v24[3074] = v25 + 1;
      sub_12D108(v24 + 3080);
      result = sub_12CFC4(128);
    }
    else
    {
      result = sub_12E948(dword_111530, v25, v26);
    }
    v27 = off_111534;
    *(uint32_t *)off_1114E0 = 4096;
    if ( !*v27 )
      *(uint8_t *)off_111538 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(uint8_t *)off_111520 )
    {
      v28 = off_111524;
      v29 = *((uint8_t *)off_111524 + 369);
      *(uint8_t *)off_111520 = 0;
      if ( v29 )
        sub_10DBC0(1);
      else
        sub_10DBD4(1);
      if ( v28[374] == 1 )
        sub_124CF4(dword_111528);
    }
    v30 = off_11152C;
    v31 = *((uint8_t *)off_11152C + 6162);
    if ( *((uint8_t *)off_11152C + 6161) > v31 )
    {
      v33 = *((uint8_t *)off_11152C + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_11152C + 6160) + 1)) >> 32) >> 7);
      v34 = off_111548;
      *((uint8_t *)off_11152C + 6160) = v33;
      v30[4 * v33 + 773] = *v34;
      LOWORD(v30[4 * v33 + 774]) = *(uint32_t *)off_11154C;
      *((uint8_t *)v30 + 6162) = v31 + 1;
      sub_12D108(dword_111550);
      result = sub_12CFC4(64);
    }
    else
    {
      result = sub_12E948(dword_11153C, v31, v31);
    }
    v32 = off_111540;
    *(uint32_t *)off_1114E0 = 2048;
    if ( !*v32 )
      *(uint8_t *)off_111538 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)off_1114E0 = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)off_1114E0 = 8;
  return result;
}

