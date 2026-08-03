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

extern uint32_t dword_119B88;
extern uint32_t off_119BA4;
extern uint32_t off_119B8C;
extern uint32_t off_119B90;
extern uint32_t off_119B98;
extern uint32_t off_119B94;
extern uint32_t dword_119BA0;
extern uint32_t dword_119B9C;

// sub_119888 @ 0x119888, size 868 bytes
int  sub_119888(int a1, int *a2, unsigned int a3, unsigned int a4, uint8_t a5)
{
  int v5; // r5
  int v7; // r4
  int v8; // s16
  int v9; // r6
  int v10; // r11
  void *v12; // r10
  int v13; // r3
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  char v17; // r7
  unsigned int v18; // r11
  unsigned int v19; // r3
  unsigned int v20; // r8
  int16_t v21; // r0
  int16_t v22; // r1
  int v23; // r3
  int v24; // r12
  unsigned int v25; // lr
  int v26; // r3
  int v27; // r2
  char v28; // lr
  int v29; // r1
  int v30; // r3
  int v31; // r3
  int v32; // r7
  int v33; // r3
  int v34; // zf
  int v35; // r3
  int v36; // r3
  int v37; // r3
  char v38; // r2
  int v39; // r1
  int v40; // r3
  int v42; // r2
  int v43; // r6
  unsigned int v44; // r3
  unsigned int v45; // r7
  int v47; // [sp+8h] [bp-1Ch]
  uint32_t *v48; // [sp+Ch] [bp-18h]
  char v50; // [sp+18h] [bp-Ch]
  int v51; // [sp+1Ch] [bp-8h]

  v5 = *(uint32_t *)(a1 + 68);
  v51 = *(uint32_t *)(v5 + 324);
  v50 = *(uint8_t *)(*(uint32_t *)(v51 + 76) + 1);
  v7 = *a2;
  v8 = dword_119B88 + 84 * a5 + 28;
  v9 = *(uint32_t *)(*a2 + 68);
  v10 = *(uint32_t *)(*a2 + 76);
  sub_12D190(v8);
  if ( !sub_1195A0(a1, v7, a5)
    || (v12 = off_119BA4, *(uint8_t *)(*(uint32_t *)off_119BA4 + 62) > (*(uint32_t *)off_119B8C & 0x3Fu)) )
  {
    sub_12D150(v8, v5);
    return 0;
  }
  v13 = *(uint32_t *)(v51 + 36);
  v14 = *(uint32_t *)(v51 + 76);
  v15 = *a2;
  v48 = off_119B8C;
  *(uint32_t *)(v14 + 20) = v10 + 12;
  *(uint32_t *)(v51 + 36) = v13 & 0xFFC7FFFF | 0x300000;
  v47 = 0;
  v16 = *(uint32_t *)(v7 + 36) & 0xFFC7FFFF | 0x300000;
  *(uint32_t *)(v14 + 68) = v13 & 0xFFC7FEFF | 0x300100;
  *(uint32_t *)(v7 + 36) = v16;
  *(uint32_t *)(v10 + 68) = *(uint32_t *)(v15 + 36) | 0x100;
  v17 = 0;
  v18 = 0;
  while ( 1 )
  {
    v24 = *(uint32_t *)(v7 + 76);
    v19 = (uint16_t)(((*(uint32_t *)(v24 + 36) + 3) & 0xFFFC) + 4);
    v25 = (uint16_t)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    if ( v25 < a4 )
      break;
    v19 = (uint16_t)(v19 + 4 * ((v16 >> 9) & 0x3FF));
    v20 = v25 + *(uint32_t *)(v5 + 40);
    if ( v20 > a3 )
      goto LABEL_17;
LABEL_7:
    if ( *(uint8_t *)(*(uint32_t *)v12 + 62) > (*v48 & 0x3Fu) )
      goto LABEL_17;
    if ( *(uint32_t *)(v24 + 28) )
      *(uint32_t *)(*(uint32_t *)(v24 + 32) - 3) = *((uint32_t *)off_119B90 + 43);
    v21 = *(uint16_t *)(v7 + 80);
    v22 = *(uint16_t *)(v5 + 10);
    *(uint32_t *)(v7 + 68) = v5;
    *(uint16_t *)(v5 + 10) = v22 + v21;
    *(uint16_t *)(v9 + 10) -= v21;
    if ( v25 < a4 )
    {
      v16 = *(uint32_t *)(v24 + 68) & 0xFFF801FF | (v18 << 9);
      *(uint32_t *)(v7 + 36) = v16;
      v19 = v25;
      *(uint32_t *)(v24 + 68) = v16 | 0x100;
    }
    *(uint32_t *)(v5 + 40) = v20;
    *(uint32_t *)(v9 + 40) -= v19;
    if ( (v16 & 0x380000) == 0x380000 )
    {
      v37 = dword_119B88 + 84 * a5;
      v38 = *(uint8_t *)(v37 + 80);
      v39 = *(uint32_t *)off_119B98;
      *(uint32_t *)(v5 + 324) = v7;
      *(uint8_t *)(v37 + 80) = v38 - 1;
      if ( !*(uint8_t *)(v39 + 1) )
        *(uint32_t *)(v5 + 20) = *(uint32_t *)(v9 + 20);
      *(uint8_t *)(v24 + 1) = v50 + v17;
      sub_12D190(v8);
      sub_12D108(*(uint32_t *)(v9 + 340));
      v40 = *(uint32_t *)(v7 + 76);
      *a2 = *(uint32_t *)v7;
      *(uint32_t *)(v40 + 20) = 0;
      v32 = 1;
      goto LABEL_34;
    }
    v23 = *(uint32_t *)v7;
    if ( **(int16_t **)off_119B94 < 0 && !v23 )
    {
      sub_12F32C(dword_119BA0, dword_119B9C, 1713);
      v23 = 0;
    }
    v16 = *(uint32_t *)(v23 + 36);
    v47 = v7;
    ++v17;
    v7 = v23;
  }
  if ( v19 >= a4 )
  {
    v18 = 0;
  }
  else
  {
    v18 = ((unsigned int)(uint16_t)(a4 - v19) + 3) >> 2;
    v19 = (uint16_t)(v19 + 4 * v18);
  }
  v20 = v19 + *(uint32_t *)(v5 + 40);
  if ( v20 <= a3 )
    goto LABEL_7;
LABEL_17:
  if ( v47 )
  {
    v26 = dword_119B88 + 84 * a5;
    v27 = *(uint32_t *)(v47 + 36);
    v28 = *(uint8_t *)(v26 + 80);
    v29 = *(uint32_t *)(v47 + 76);
    *(uint32_t *)(v5 + 324) = v47;
    v27 |= 0x380000u;
    *(uint32_t *)(v47 + 36) = v27;
    *(uint32_t *)(v29 + 68) = v27 | 0x100;
    *(uint32_t *)(v29 + 20) = 0;
    *(uint8_t *)(v26 + 80) = v28 - 1;
    *(uint8_t *)(v29 + 1) = v50 + v17;
    *(uint8_t *)(*(uint32_t *)(*(uint32_t *)(v9 + 324) + 76) + 1) -= v17;
    v30 = *(uint32_t *)(v7 + 36);
    LOWORD(v27) = *(uint16_t *)(v9 + 8);
    *(uint32_t *)(v9 + 268) = v7;
    *(uint16_t *)(v9 + 8) = v27 | 0x400;
    if ( (v30 & 0x380000) == 0x380000 )
      sub_12D190(v8);
    v31 = *(uint32_t *)off_119B98;
    *a2 = v7;
    v32 = *(uint8_t *)(v31 + 1);
    if ( *(uint8_t *)(v31 + 1) )
    {
      v32 = 0;
    }
    else
    {
      v33 = *(uint32_t *)(v7 + 36) & 0x380000;
      v34 = v33 == 3670016;
      if ( v33 == 3670016 )
        v35 = *(uint32_t *)(v7 + 76);
      else
        v35 = *(uint32_t *)(v7 + 68);
      if ( v34 )
        v36 = v35 + 12;
      else
        v36 = v35 + 16;
      *(uint32_t *)(v5 + 20) = v36;
    }
LABEL_34:
    sub_12D150(v8, v5);
    return v32;
  }
  v42 = *(uint32_t *)(v51 + 36);
  v43 = *(uint32_t *)(v51 + 76);
  *(uint32_t *)(v43 + 20) = 0;
  *(uint32_t *)(v51 + 36) = v42 | 0x380000;
  v44 = *(uint32_t *)(v7 + 36) & 0xFFC7FFFF | 0x280000;
  v45 = *(uint32_t *)(v7 + 36) & 0xFFC7FEFF | 0x280100;
  *(uint32_t *)(v43 + 68) = v42 | 0x380100;
  *(uint32_t *)(v7 + 36) = v44;
  *(uint32_t *)(v24 + 68) = v45;
  sub_12D150(v8, v5);
  v32 = 0;
  *a2 = v7;
  return v32;
}

