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


extern uint32_t dword_10E6B8;
extern uint32_t dword_10E6C0;
extern uint32_t dword_10E6C8;
extern uint32_t dword_10E6D8;
extern uint32_t dword_10E6DC;
extern uint32_t off_10E6D0;
extern uint32_t off_10E6D4;
extern uint32_t off_10E6F8;

// sub_10E420 @ 0x10e420, size 664 bytes
int sub_10E420()
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

  v0 = off_10E6D4;
  v1 = dword_10E6D8;
  v2 = dword_10E6DC;
  *((uint32_t *)off_10E6D0 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = sub_142874(v0[4]);
  v4 = sub_142968(v3, *(uint64_t *)&dword_10E6B8);
  v5 = sub_142BBC(v4, *(uint64_t *)&dword_10E6C0);
  v6 = sub_1425F8(v5, *(uint64_t *)&dword_10E6B8);
  v7 = sub_142E9C(v6);
  v8 = sub_10EC2C() & 0x1F;
  v9 = v7 - 840;
  sub_10DAE4("Initl vcore Volt: %d mV, reg: %x\n", v7, v8);
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
    v11 = sub_142894(v10);
    v12 = sub_142968(v11, *(uint64_t *)&dword_10E6C8);
    v13 = sub_142E9C(v12);
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
    sub_10EC3C();
    v16 = off_10E6D4;
    *((uint32_t *)off_10E6D4 + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = sub_142874(v16[4]);
    v18 = sub_142968(v17, *(uint64_t *)&dword_10E6B8);
    v19 = sub_142BBC(v18, *(uint64_t *)&dword_10E6C0);
    v20 = sub_1425F8(v19, *(uint64_t *)&dword_10E6B8);
    v7 = sub_142E9C(v20);
    sub_12E948("step=%d, val=%x, volt=%d\n", v14, v15, v7);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v41 = v21;
  }
  v23 = off_10E6D4;
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
    sub_10EC3C();
    v23[1] = 1;
    while ( v23[7] != 1 )
      ;
    v23[7] = 1;
    v27 = sub_142874(v23[4]);
    v28 = sub_142968(v27, *(uint64_t *)&dword_10E6B8);
    v29 = sub_142BBC(v28, *(uint64_t *)&dword_10E6C0);
    v30 = sub_1425F8(v29, *(uint64_t *)&dword_10E6B8);
    v31 = sub_142E9C(v30);
    sub_12E948("ofst=%d, val=%x, volt=%d\n", v9, v24, v31);
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
  sub_10DAE4("reg_value_offset: %d\n", v9);
  sub_10EC3C();
  v34 = off_10E6D4;
  *((uint32_t *)off_10E6D4 + 1) = 1;
  while ( v34[7] != 1 )
    ;
  v34[7] = 1;
  v35 = sub_142874(v34[4]);
  v36 = sub_142968(v35, *(uint64_t *)&dword_10E6B8);
  v37 = sub_142BBC(v36, *(uint64_t *)&dword_10E6C0);
  v38 = sub_1425F8(v37, *(uint64_t *)&dword_10E6B8);
  v39 = sub_142E9C(v38);
  sub_10DAE4("Calib vcore Volt: %d mV\n", v39);
  result = ((uint32_t *)(uintptr_t)off_10E6F8)[94];
  if ( result != 0x80000000 )
    return sub_1111CC(result);
  return result;
}
