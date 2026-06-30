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

extern uint32_t off_134F44;
extern uint32_t dword_134F8C;
extern uint32_t dword_134F48;
extern uint32_t off_134F4C;
extern uint32_t off_134F50;
extern uint32_t off_134F54;
extern uint32_t off_134F58;
extern uint32_t off_134F84;
extern uint32_t off_134F74;
extern uint32_t dword_134F88;
extern uint32_t dword_134F5C;
extern uint32_t dword_134F60;
extern uint32_t off_134F64;
extern uint32_t off_134F68;
extern uint32_t off_134F6C;
extern uint32_t off_134F70;
extern uint32_t dword_134F78;
extern uint32_t off_134F7C;
extern uint32_t dword_134F80;

// sub_134CC4 @ 0x134cc4, size 166 bytes
// positive sp value has been detected, the output may be wrong!
void  sub_134CC4(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  uint32_t *v14; // r5
  int v15; // r11
  int v16; // r7
  int v17; // r4
  int v18; // r9
  int v19; // r10
  int v20; // r12
  uint8_t *v21; // r0
  unsigned int *v22; // r1
  unsigned int v23; // r2
  int *v24; // r3
  char *v25; // r1
  int *v26; // r3
  int v27; // r3
  int v28; // r2
  char v29; // lr
  int16_t v30; // r0
  int v31; // lr
  int v32; // r2
  int v33; // lr
  unsigned int v34; // r0
  unsigned int v35; // r3
  unsigned int v36; // r3
  int v37; // r2
  int v38; // r3
  int v39; // r3
  int v40; // r3
  void *v41; // r1
  uint16_t *v42; // r3
  int v43; // r3
  unsigned int v44; // r0
  uint32_t *v45; // r3
  uint32_t *v46; // r2
  int *v47; // r1
  int v48; // r0
  int v49; // [sp-8h] [bp-1Ch]
  void *v50; // [sp-8h] [bp-1Ch]

  v14 = off_134F44;
  v15 = dword_134F8C;
  v16 = *(uint8_t *)(*((uint32_t *)off_134F44 + 4) + 61);
  v17 = *((uint32_t *)off_134F44 + 5);
  v49 = *((uint32_t *)off_134F44 + 4);
  v18 = dword_134F8C + 1320 * v16;
  v19 = *(uint8_t *)(v18 + 116);
  sub_12E948(dword_134F48);
  v20 = v14[4];
  if ( !v20 )
LABEL_11:
    
  v21 = off_134F4C;
  v22 = (unsigned int *)off_134F50;
  *(uint8_t *)(v17 + 9) = *(uint8_t *)(v49 + 61);
  v23 = *v22 & 0xFFFFFFEF;
  v24 = *((int **)off_134F54 + 2);
  *(uint16_t *)v17 = a1;
  *v22 = v23;
  v25 = 0;
  v21[13] = 0;
  if ( v24 )
  {
    do
    {
      if ( !*((uint8_t *)v24 + 106) && *((uint8_t *)v24 + 108) )
        ++v25;
      v24 = (int *)*v24;
    }
    while ( v24 );
    if ( a1 )
      goto LABEL_8;
  }
  else
  {
    v25 = 0;
    if ( a1 )
    {
LABEL_8:
      v26 = (int *)off_134F58;
      *(uint8_t *)(v17 + 8) = (*(uint32_t *)(v20 + 48) & 0x60) != 0;
      if ( *v26 < 0 && !v25 )
      {
        v46 = off_134F84;
        v21[2] = 0;
        v47 = (int *)off_134F74;
        v48 = dword_134F88;
        *v46 |= 0x80000000;
        *v47 = v48;
      }
      sub_12CBF4(6u, 10);
      v14[2] = v18;
      *v14 = v17 - 12;
      sub_1346C0(v18);
LABEL_10:
      sub_12EB90(256, dword_134F5C, *(uint8_t *)(v17 + 9), a1, *(uint16_t *)(v17 + 820));
      sub_12C8F8(v14[4] - 12);
      v14[4] = 0;
      *((uint8_t *)v14 + 33) = 0;
      goto LABEL_11;
    }
  }
  v27 = v15 + 1320 * v16;
  v28 = dword_134F60;
  v29 = *(uint8_t *)(v27 + 116);
  *(uint32_t *)(v17 + 2) = *(uint32_t *)(v27 + 368);
  v30 = *(uint16_t *)(v27 + 372);
  *(uint8_t *)(v17 + 10) = v29;
  v31 = *(uint32_t *)(v27 + 72);
  *(uint16_t *)(v17 + 6) = v30;
  *(uint8_t *)(v17 + 11) = *(uint8_t *)(v31 + 24);
  v32 = *(uint8_t *)(v28 + 696 * v19 + 309);
  *(uint8_t *)(v17 + 826) = v32;
  *(uint8_t *)(v17 + 822) = *(uint8_t *)(v27 + 412);
  v33 = *(uint8_t *)(v27 + 413);
  v34 = *(uint16_t *)(v27 + 414);
  *(uint16_t *)(v17 + 824) = v34;
  if ( v33 == v32 )
  {
    *(uint32_t *)(v17 + 828) = *(uint16_t *)(v27 + 416);
  }
  else if ( v32 )
  {
    v35 = *(uint16_t *)(v27 + 416);
    if ( v34 >= v35 )
      v36 = v35 + 20;
    else
      v36 = v35 - 20;
    *(uint32_t *)(v17 + 828) = v36;
  }
  else
  {
    *(uint32_t *)(v17 + 828) = v34;
  }
  v37 = v15 + 1320 * v16;
  v38 = *(uint32_t *)(v37 + 472);
  *(uint32_t *)(v17 + 832) = *(uint16_t *)(v37 + 418);
  v39 = v38 & 1;
  *(uint8_t *)(v17 + 12) = v39;
  if ( v39 )
    LOBYTE(v39) = *(uint8_t *)(v37 + 457);
  *(uint8_t *)(v17 + 13) = v39;
  v40 = v15 + 1320 * v16;
  *(uint8_t *)(v17 + 8) = (*(uint32_t *)(v20 + 48) & 0x60) != 0;
  if ( *(uint8_t *)(v40 + 1224) )
  {
    *(uint32_t *)off_134F64 = *(uint16_t *)(v40 + 100) | (*(uint16_t *)(v40 + 102) << 16);
    *(uint32_t *)off_134F68 = *(uint16_t *)(v40 + 104);
    *(uint32_t *)off_134F6C = *(uint16_t *)(v40 + 64) | (*(uint16_t *)(v40 + 66) << 16);
    *(uint32_t *)off_134F70 = *(uint16_t *)(v40 + 68);
  }
  v50 = v25;
  sub_12C84C(v17);
  v41 = v50;
  *(uint32_t *)off_134F74 = dword_134F78;
  if ( v50 == (void *)1 )
  {
    v42 = (uint16_t *)(v15 + 1320 * v16);
    v41 = off_134F64;
    *(uint32_t *)off_134F64 = v42[50] | (v42[51] << 16);
    *(uint32_t *)off_134F68 = v42[52];
  }
  if ( *(uint8_t *)(v15 + 1320 * v16 + 413) == 2 )
    sub_12063C((int *)v18, 0, 1);
  v43 = v15 + 1320 * v16;
  v44 = *(uint16_t *)(v43 + 416);
  if ( v44 <= 0x1387 )
    sub_10D0BC(v44 | (*(uint8_t *)(v43 + 413) << 16) | 0x80000000, (int)v41, 4999);
  v45 = off_134F7C;
  *(uint8_t *)(v15 + 1320 * v16 + 149) = 1;
  sub_124BFC(1320 * v16 + 152 + v15, dword_134F80 + v45[4]);
  sub_12CBF4(6u, 0);
  goto LABEL_10;
}

