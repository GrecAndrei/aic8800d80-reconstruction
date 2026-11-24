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


extern uint32_t dword_10E650;
extern uint32_t dword_10E658;
extern uint32_t dword_10E660;
extern uint32_t dword_10E670;
extern uint32_t dword_10E674;
extern uint32_t off_10E668;
extern uint32_t off_10E66C;
extern uint32_t off_10E690;

// sub_10E3B8 @ 0x10e3b8, size 664 bytes
int sub_10E3B8()
{
  uint32_t *v0; // r1
  int v1; // r3
  int v2; // r2
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r5
  int v8; // r10
  int v9; // r8
  int v10; // r0
  uint64_t v11; // r0
  uint64_t v12; // r0
  int v13; // r0
  int v14; // r9
  int v15; // r4
  uint32_t *v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int v21; // r3
  int v22; // r3
  uint32_t *v23; // r6
  int v24; // r4
  int i; // r7
  int v26; // r2
  uint64_t v27; // r0
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  int v31; // r10
  int v32; // r5
  int v33; // r2
  uint32_t *v34; // r2
  uint64_t v35; // r0
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  int v39; // r0
  int result; // r0
  int v41; // [sp+0h] [bp-Ch]
  int v42; // [sp+4h] [bp-8h]

  v0 = off_10E66C;
  v1 = dword_10E670;
  v2 = dword_10E674;
  *((uint32_t *)off_10E668 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = sub_142A50(v0[4]);
  v4 = sub_142B44(v3, *(uint64_t *)&dword_10E650);
  v5 = sub_142D98(v4, *(uint64_t *)&dword_10E658);
  v6 = sub_1427D4(v5, *(uint64_t *)&dword_10E650);
  v7 = sub_143078(v6);
  v8 = sub_10EBC4() & 0x1F;
  v9 = v7 - 840;
  sub_10DA7C("Initl vcore Volt: %d mV, reg: %x\n", v7, v8);
  v10 = abs32(v7 - 840);
  if ( v10 <= 47 )
  {
    if ( (unsigned int)(v10 - 1) > 0x2E )
    {
      v9 = 0;
      goto LABEL_33;
    }
    if ( v9 <= 0 )
      v22 = 1;
    else
      v22 = -1;
    v41 = v22;
    v14 = 0;
  }
  else
  {
    v11 = sub_142A70(v10);
    v12 = sub_142B44(v11, *(uint64_t *)&dword_10E660);
    v13 = sub_143078(v12);
    v14 = v13;
    if ( v9 <= 0 )
    {
      if ( v7 == 840 )
        goto LABEL_33;
      v15 = v13 + v8;
    }
    else
    {
      v15 = v8 - v13;
    }
    if ( v15 > 31 )
    {
      v9 = 9;
      goto LABEL_33;
    }
    if ( v15 <= 12 )
    {
      v9 = -9;
      goto LABEL_33;
    }
    sub_10EBD4();
    v16 = off_10E66C;
    *((uint32_t *)off_10E66C + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = sub_142A50(v16[4]);
    v18 = sub_142B44(v17, *(uint64_t *)&dword_10E650);
    v19 = sub_142D98(v18, *(uint64_t *)&dword_10E658);
    v20 = sub_1427D4(v19, *(uint64_t *)&dword_10E650);
    v7 = sub_143078(v20);
    sub_12ECB0("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = off_10E66C;
  v42 = v8;
  v24 = v41 + v14 * v41 + v8;
  for ( i = v14 + 1; ; ++i )
  {
    v26 = v14;
    v9 = v24 - v42;
    v14 = i;
    if ( (unsigned int)(v24 - 13) > 0x12 )
    {
      v9 = v41 * v26;
      goto LABEL_33;
    }
    sub_10EBD4();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = sub_142A50(v23[4]);
    v28 = sub_142B44(v27, *(uint64_t *)&dword_10E650);
    v29 = sub_142D98(v28, *(uint64_t *)&dword_10E658);
    v30 = sub_1427D4(v29, *(uint64_t *)&dword_10E650);
    v31 = sub_143078(v30);
    sub_12ECB0("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
    v32 = v7 - 840;
    v33 = v31 - 840;
    if ( v32 * (v31 - 840) <= 0 )
      break;
    v24 += v41;
    v7 = v31;
  }
  if ( v33 < 0 )
    v33 = 840 - v31;
  if ( v32 < 0 )
    v32 = -v32;
  if ( v33 > v32 )
    v9 -= v41;
LABEL_33:
  sub_10DA7C("reg_value_offset: %d\n", v9);
  sub_10EBD4();
  v34 = off_10E66C;
  *((uint32_t *)off_10E66C + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = sub_142A50(v34[4]);
  v36 = sub_142B44(v35, *(uint64_t *)&dword_10E650);
  v37 = sub_142D98(v36, *(uint64_t *)&dword_10E658);
  v38 = sub_1427D4(v37, *(uint64_t *)&dword_10E650);
  v39 = sub_143078(v38);
  sub_10DA7C("Calib vcore Volt: %d mV\n", v39);
  result = ((uint32_t *)(uintptr_t)off_10E690)[94];
  if ( result != 0x80000000 )
    return sub_111168(result);
  return result;
}
