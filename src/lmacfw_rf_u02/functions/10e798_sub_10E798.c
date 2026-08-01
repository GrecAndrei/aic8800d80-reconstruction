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

extern uint32_t off_10EA4C;
extern uint32_t dword_10EA50;
extern uint32_t dword_10EA54;
extern uint32_t off_10EA48;
extern uint32_t dword_10EA30;
extern uint32_t dword_10EA34;
extern uint32_t dword_10EA38;
extern uint32_t dword_10EA3C;
extern uint32_t dword_10EA58;
extern uint32_t dword_10EA5C;
extern uint32_t dword_10EA40;
extern uint32_t dword_10EA44;
extern uint32_t dword_10EA60;
extern uint32_t dword_10EA64;
extern uint32_t dword_10EA68;
extern uint32_t dword_10EA6C;
extern uint32_t off_10EA70;

// periph_cmd_poll @ 0x10e798, size 664 bytes
int periph_cmd_poll()
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
  int v23; // r11
  uint32_t *v24; // r6
  int v25; // r4
  int i; // r7
  int v27; // r2
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  int v32; // r10
  int v33; // r5
  int v34; // r2
  uint32_t *v35; // r2
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  uint64_t v39; // r0
  int v40; // r0
  int result; // r0
  int v42; // [sp+0h] [bp-Ch]
  int v43; // [sp+4h] [bp-8h]

  v0 = off_10EA4C;
  v1 = dword_10EA50;
  v2 = dword_10EA54;
  *((uint32_t *)off_10EA48 + 14) = 296;
  v0[2] = v1 & v0[2] | 0x200000B;
  v0[3] = v2 | v0[3] & 0xE0000000;
  v0[1] = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v3 = double_to_float(v0[4]);
  v4 = aeabi_dadd(v3, HIDWORD(v3), dword_10EA30, dword_10EA34);
  v5 = aeabi_dsub(v4, HIDWORD(v4), dword_10EA38, dword_10EA3C);
  v6 = double_subtract(v5, HIDWORD(v5), dword_10EA30, dword_10EA34);
  v7 = double_to_float(v6, HIDWORD(v6));
  v8 = call_indirect_table(dword_10EA58) & 0x1F;
  v9 = v7 - 840;
  log_printf(dword_10EA5C, v7, v8);
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
    v42 = v22;
    v14 = 0;
  }
  else
  {
    v11 = aeabi_i2d(v10);
    v12 = aeabi_dadd(v11, HIDWORD(v11), dword_10EA40, dword_10EA44);
    v13 = double_to_float(v12, HIDWORD(v12));
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
      v8 += 9;
      v9 = 9;
      goto LABEL_33;
    }
    if ( v15 <= 12 )
    {
      v8 -= 9;
      v9 = -9;
      goto LABEL_33;
    }
    call_slot_0x1b8(dword_10EA58, v15, 31);
    v16 = off_10EA4C;
    *((uint32_t *)off_10EA4C + 1) = 1;
    while ( v16[7] != 1 )
      ;
    v16[7] = 1;
    v17 = double_to_float(v16[4]);
    v18 = aeabi_dadd(v17, HIDWORD(v17), dword_10EA30, dword_10EA34);
    v19 = aeabi_dsub(v18, HIDWORD(v18), dword_10EA38, dword_10EA3C);
    v20 = double_subtract(v19, HIDWORD(v19), dword_10EA30, dword_10EA34);
    v7 = double_to_float(v20, HIDWORD(v20));
    dispatch_event_handler(dword_10EA60, v14);
    if ( v7 <= 840 )
      v21 = 1;
    else
      v21 = -1;
    v42 = v21;
  }
  v23 = dword_10EA58;
  v24 = off_10EA4C;
  v43 = v8;
  v25 = v42 + v14 * v42 + v8;
  for ( i = v14 + 1; ; ++i )
  {
    v27 = v14;
    v9 = v25 - v43;
    v14 = i;
    if ( (unsigned int)(v25 - 13) > 0x12 )
    {
      v9 = v42 * v27;
      v8 = v43 + v42 * v27;
      goto LABEL_33;
    }
    call_slot_0x1b8(v23, v25, 31);
    v24[1] = 1;
    while ( v24[7] != 1 )
      ;
    v24[7] = 1;
    v28 = double_to_float(v24[4]);
    v29 = aeabi_dadd(v28, HIDWORD(v28), dword_10EA30, dword_10EA34);
    v30 = aeabi_dsub(v29, HIDWORD(v29), dword_10EA38, dword_10EA3C);
    v31 = double_subtract(v30, HIDWORD(v30), dword_10EA30, dword_10EA34);
    v32 = double_to_float(v31, HIDWORD(v31));
    dispatch_event_handler(dword_10EA64, v9);
    v33 = v7 - 840;
    v34 = v32 - 840;
    if ( v33 * (v32 - 840) <= 0 )
      break;
    v25 += v42;
    v7 = v32;
  }
  if ( v34 < 0 )
    v34 = 840 - v32;
  if ( v33 < 0 )
    v33 = -v33;
  if ( v34 > v33 )
  {
    v9 -= v42;
    v8 = v43 + v9;
  }
  else
  {
    v8 = v25;
  }
LABEL_33:
  log_printf(dword_10EA68, v9);
  call_slot_0x1b8(dword_10EA58, v8, 31);
  v35 = off_10EA4C;
  *((uint32_t *)off_10EA4C + 1) = 1;
  while ( v35[7] != 1 )
    ;
  v35[7] = 1;
  v36 = double_to_float(v35[4]);
  v37 = aeabi_dadd(v36, HIDWORD(v36), dword_10EA30, dword_10EA34);
  v38 = aeabi_dsub(v37, HIDWORD(v37), dword_10EA38, dword_10EA3C);
  v39 = double_subtract(v38, HIDWORD(v38), dword_10EA30, dword_10EA34);
  v40 = double_to_float(v39, HIDWORD(v39));
  log_printf(dword_10EA6C, v40);
  result = *((uint32_t *)off_10EA70 + 94);
  if ( result != 0x80000000 )
    return rf_reg_update();
  return result;
}

