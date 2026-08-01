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

extern uint32_t dword_10E38C;
extern uint32_t dword_10E390;
extern uint32_t off_10E394;
extern uint32_t off_10E388;
extern uint32_t dword_10E398;
extern uint32_t dword_10E370;
extern uint32_t dword_10E374;
extern uint32_t dword_10E378;
extern uint32_t dword_10E37C;
extern uint32_t dword_10E39C;
extern uint32_t dword_10E3A0;
extern uint32_t dword_10E380;
extern uint32_t dword_10E384;
extern uint32_t dword_10E3A4;
extern uint32_t dword_10E3B0;
extern uint32_t dword_10E3A8;
extern uint32_t dword_10E3AC;

// radio_init @ 0x10e0f8, size 628 bytes
// Doc: radio_init [rf]: Initialize RF subsystem with base addresses and register setup
// radio_init [rf]: Initialize RF subsystem with base addresses and register setup
int radio_init()
{
  int v0; // r3
  int v1; // r0
  uint32_t *v2; // r4
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r0
  int v6; // r5
  int v7; // r2
  char v8; // r0
  int v9; // r2
  int v10; // r4
  int v11; // r3
  int v12; // r6
  uint64_t v13; // r0
  uint64_t v14; // r0
  int v15; // r0
  int v16; // r8
  int v17; // r4
  uint32_t *v18; // r2
  uint64_t v19; // r0
  uint64_t v20; // r0
  uint64_t v21; // r0
  int v22; // r3
  int v23; // r3
  int v24; // r11
  uint32_t *v25; // r6
  int v26; // r10
  int v27; // r7
  int v28; // r4
  int v29; // r9
  uint64_t v30; // r0
  uint64_t v31; // r0
  uint64_t v32; // r0
  int v33; // r5
  int v34; // r3
  uint32_t *v35; // r2
  uint64_t v36; // r0
  uint64_t v37; // r0
  uint64_t v38; // r0
  int v39; // r0
  int v40; // r2
  int v42; // [sp+4h] [bp-10h]
  int v43; // [sp+8h] [bp-Ch]
  int v44; // [sp+Ch] [bp-8h]

  v0 = dword_10E38C;
  v1 = dword_10E390;
  v2 = off_10E394;
  *((uint32_t *)off_10E388 + 14) = 296;
  v2[3] = v0 | v2[3] & 0xE0000000;
  call_vector_1b8(v1, 1024, 15360);
  v2[2] = dword_10E398 & v2[2] | 0x1200000F;
  v2[1] = 1;
  while ( v2[7] != 1 )
    ;
  v2[7] = 1;
  v3 = __aeabi_ui2d(v2[4]);
  v4 = __aeabi_dmul(v3, HIDWORD(v3), dword_10E370, dword_10E374);
  v5 = __aeabi_dsub(v4, HIDWORD(v4), dword_10E378, dword_10E37C);
  v6 = __aeabi_d2lz(v5, HIDWORD(v5));
  ke_event_schedule(dword_10E39C, v6, v7);
  v8 = jump_table_1b0(dword_10E3A0);
  v10 = v6 - 1400;
  v11 = abs32(v6 - 1400);
  v12 = v8 & 0x3F;
  v43 = v12;
  if ( v11 > 49 )
  {
    v13 = __aeabi_i2d(v11);
    v14 = __aeabi_dmul(v13, HIDWORD(v13), dword_10E380, dword_10E384);
    v15 = __aeabi_d2lz(v14, HIDWORD(v14));
    v16 = v15;
    if ( v10 <= 0 )
    {
      v34 = v12;
      if ( v6 == 1400 )
        goto LABEL_39;
      v17 = v15 + v12;
    }
    else
    {
      v17 = v12 - v15;
    }
    if ( v17 > 32 )
    {
      v29 = 7;
      v28 = v12 + 7;
      goto LABEL_28;
    }
    if ( v17 > 11 )
    {
      call_vector_1b8(dword_10E3A0, v17, 63);
      v18 = off_10E394;
      *((uint32_t *)off_10E394 + 1) = 1;
      while ( v18[7] != 1 )
        ;
      v18[7] = 1;
      v19 = __aeabi_ui2d(v18[4]);
      v20 = __aeabi_dmul(v19, HIDWORD(v19), dword_10E370, dword_10E374);
      v21 = __aeabi_dsub(v20, HIDWORD(v20), dword_10E378, dword_10E37C);
      v6 = __aeabi_d2lz(v21, HIDWORD(v21));
      ke_event_schedule(dword_10E3A4, v16, v17);
      if ( v6 <= 1400 )
        v22 = 1;
      else
        v22 = -1;
      v44 = v22;
      goto LABEL_19;
    }
    v34 = v12;
LABEL_39:
    v28 = v34 - 13;
    v29 = -13;
    goto LABEL_28;
  }
  if ( (unsigned int)(v11 - 1) > 0x30 )
  {
    v28 = v8 & 0x3F;
    v29 = 0;
    goto LABEL_28;
  }
  if ( v10 <= 0 )
    v23 = 1;
  else
    v23 = -1;
  v44 = v23;
  v16 = 0;
LABEL_19:
  v24 = dword_10E3A0;
  v25 = off_10E394;
  v26 = dword_10E3B0;
  v27 = v16 + 1;
  v28 = v44 + v16 * v44 + v43;
  while ( 1 )
  {
    v9 = v16;
    v29 = v28 - v43;
    v16 = v27;
    if ( (unsigned int)(v28 - 12) > 0x14 )
    {
      v29 = v44 * v9;
      v28 = v43 + v44 * v9;
      goto LABEL_28;
    }
    call_vector_1b8(v24, v28, 63);
    v25[1] = 1;
    while ( v25[7] != 1 )
      ;
    v25[7] = 1;
    v30 = __aeabi_ui2d(v25[4]);
    v31 = __aeabi_dmul(v30, HIDWORD(v30), dword_10E370, dword_10E374);
    v32 = __aeabi_dsub(v31, HIDWORD(v31), dword_10E378, dword_10E37C);
    v42 = __aeabi_d2lz(v32, HIDWORD(v32));
    ke_event_schedule(v26, v29, v28);
    v33 = v6 - 1400;
    v9 = v42 - 1400;
    if ( v33 * (v42 - 1400) <= 0 )
      break;
    v28 += v44;
    v6 = v42;
    ++v27;
  }
  if ( v9 < 0 )
    v9 = 1400 - v42;
  if ( v33 < 0 )
    v33 = -v33;
  if ( v9 > v33 )
  {
    v29 -= v44;
    v28 = v43 + v29;
  }
LABEL_28:
  ke_event_schedule(dword_10E3A8, v29, v9);
  call_vector_1b8(dword_10E3A0, v28, 63);
  v35 = off_10E394;
  *((uint32_t *)off_10E394 + 1) = 1;
  while ( v35[7] != 1 )
    ;
  v35[7] = 1;
  v36 = __aeabi_ui2d(v35[4]);
  v37 = __aeabi_dmul(v36, HIDWORD(v36), dword_10E370, dword_10E374);
  v38 = __aeabi_dsub(v37, HIDWORD(v37), dword_10E378, dword_10E37C);
  v39 = __aeabi_d2lz(v38, HIDWORD(v38));
  ke_event_schedule(dword_10E3AC, v39, v40);
  return call_vector_1b8(dword_10E390, 0, 15360);
}

