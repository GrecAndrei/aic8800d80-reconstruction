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


extern uint32_t dword_10E3D8;
extern uint32_t dword_10E3E0;
extern uint32_t dword_10E3E8;
extern uint32_t dword_10E3F4;
extern uint32_t dword_10E400;
extern uint32_t off_10E3F0;
extern uint32_t off_10E3FC;

// sub_10E160 @ 0x10e160, size 628 bytes
int sub_10E160()
{
  int v0; // r3
  uint32_t *v1; // r4
  uint64_t v2; // r0
  uint64_t v3; // r0
  uint64_t v4; // r0
  int v5; // r5
  char v6; // r0
  int v7; // r4
  int v8; // r3
  int v9; // r6
  uint64_t v10; // r0
  uint64_t v11; // r0
  int v12; // r0
  int v13; // r8
  int v14; // r4
  uint32_t *v15; // r2
  uint64_t v16; // r0
  uint64_t v17; // r0
  uint64_t v18; // r0
  int v19; // r3
  int v20; // r3
  uint32_t *v21; // r6
  int v22; // r7
  int v23; // r4
  int v24; // r2
  int v25; // r9
  uint64_t v26; // r0
  uint64_t v27; // r0
  uint64_t v28; // r0
  int v29; // r5
  int v30; // r2
  uint32_t *v31; // r2
  uint64_t v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  int v35; // r0
  int v37; // [sp+4h] [bp-10h]
  int v38; // [sp+8h] [bp-Ch]
  int v39; // [sp+Ch] [bp-8h]

  v0 = dword_10E3F4;
  v1 = off_10E3FC;
  *((uint32_t *)off_10E3F0 + 14) = 296;
  v1[3] = v0 | v1[3] & 0xE0000000;
  sub_10EC3C();
  v1[2] = dword_10E400 & v1[2] | 0x1200000F;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v2 = sub_142874(v1[4]);
  v3 = sub_142968(v2, *(uint64_t *)&dword_10E3D8);
  v4 = sub_1425F8(v3, *(uint64_t *)&dword_10E3E0);
  v5 = sub_142E9C(v4);
  sub_12E948("Initial    Volt:  %d mV\n", v5);
  v6 = sub_10EC2C();
  v7 = v5 - 1400;
  v8 = abs32(v5 - 1400);
  v9 = v6 & 0x3F;
  v38 = v9;
  if ( v8 > 49 )
  {
    v10 = sub_142894(v8);
    v11 = sub_142968(v10, *(uint64_t *)&dword_10E3E8);
    v12 = sub_142E9C(v11);
    v13 = v12;
    if ( v7 <= 0 )
    {
      if ( v5 == 1400 )
        goto LABEL_38;
      v14 = v12 + v9;
    }
    else
    {
      v14 = v9 - v12;
    }
    if ( v14 > 32 )
    {
      v25 = 7;
      goto LABEL_28;
    }
    if ( v14 > 11 )
    {
      sub_10EC3C();
      v15 = off_10E3FC;
      *((uint32_t *)off_10E3FC + 1) = 1;
      while ( v15[7] != 1 )
        ;
      v15[7] = 1;
      v16 = sub_142874(v15[4]);
      v17 = sub_142968(v16, *(uint64_t *)&dword_10E3D8);
      v18 = sub_1425F8(v17, *(uint64_t *)&dword_10E3E0);
      v5 = sub_142E9C(v18);
      sub_12E948("step=%d, val=%d, volt=%d\n", v13, v14, v5);
      if ( v5 <= 1400 )
        v19 = 1;
      else
        v19 = -1;
      v39 = v19;
      goto LABEL_19;
    }
LABEL_38:
    v25 = -13;
    goto LABEL_28;
  }
  if ( (unsigned int)(v8 - 1) > 0x30 )
  {
    v25 = 0;
    goto LABEL_28;
  }
  if ( v7 <= 0 )
    v20 = 1;
  else
    v20 = -1;
  v39 = v20;
  v13 = 0;
LABEL_19:
  v21 = off_10E3FC;
  v22 = v13 + 1;
  v23 = v39 + v13 * v39 + v38;
  while ( 1 )
  {
    v24 = v13;
    v25 = v23 - v38;
    v13 = v22;
    if ( (unsigned int)(v23 - 12) > 0x14 )
    {
      v25 = v39 * v24;
      goto LABEL_28;
    }
    sub_10EC3C();
    v21[1] = 1;
    while ( v21[7] != 1 )
      ;
    v21[7] = 1;
    v26 = sub_142874(v21[4]);
    v27 = sub_142968(v26, *(uint64_t *)&dword_10E3D8);
    v28 = sub_1425F8(v27, *(uint64_t *)&dword_10E3E0);
    v37 = sub_142E9C(v28);
    sub_12E948("ofst=%d, val=%d, volt=%d\n", v25, v23, v37);
    v29 = v5 - 1400;
    v30 = v37 - 1400;
    if ( v29 * (v37 - 1400) <= 0 )
      break;
    v23 += v39;
    v5 = v37;
    ++v22;
  }
  if ( v30 < 0 )
    v30 = 1400 - v37;
  if ( v29 < 0 )
    v29 = -v29;
  if ( v30 > v29 )
    v25 -= v39;
LABEL_28:
  sub_12E948("reg_value_offset: %d\n", v25);
  sub_10EC3C();
  v31 = off_10E3FC;
  *((uint32_t *)off_10E3FC + 1) = 1;
  while ( v31[7] != 1 )
    ;
  v31[7] = 1;
  v32 = sub_142874(v31[4]);
  v33 = sub_142968(v32, *(uint64_t *)&dword_10E3D8);
  v34 = sub_1425F8(v33, *(uint64_t *)&dword_10E3E0);
  v35 = sub_142E9C(v34);
  sub_12E948("Calibrated Volt:  %d mV\n", v35);
  return sub_10EC3C();
}
