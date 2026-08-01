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

extern uint32_t dword_104F00;
extern uint32_t dword_104F08;
extern uint32_t dword_104F0C;
extern uint32_t dword_104F10;
extern uint32_t dword_104F14;

// bt_encrypt_wrap @ 0x104c38, size 710 bytes
int  bt_encrypt_wrap(int *a1, int a2, int a3, int a4, uint64_t *a5)
{
  int v6; // r0
  int v8; // r2
  int v9; // r0
  float inited; // r0
  int *v11; // r11
  int v12; // r2
  uint64_t v13; // d9
  uint64_t v14; // r0
  uint64_t v15; // d13
  uint64_t v16; // r0
  int v17; // r0
  uint64_t v18; // r4
  int v19; // r8
  uint64_t v20; // r0
  int v21; // r0
  uint64_t v22; // d8
  uint64_t v23; // r0
  uint64_t v24; // r0
  int v25; // r6
  uint64_t v26; // r0
  int v27; // r0
  int *v28; // r10
  uint64_t v29; // d11
  uint64_t v30; // r6
  uint64_t v31; // r0
  uint64_t v32; // r8
  uint64_t v33; // r6
  uint64_t v34; // r0
  uint64_t v35; // d10
  uint64_t v36; // r6
  uint64_t v37; // r0
  uint64_t v38; // r6
  uint64_t v39; // r0
  uint64_t v40; // r6
  uint64_t v41; // r0
  uint64_t v42; // d12
  uint64_t v43; // r6
  uint64_t v44; // r0
  uint64_t v45; // r6
  uint64_t v46; // r0
  uint64_t v47; // r0
  uint64_t v48; // r8
  uint64_t v49; // r0
  uint64_t v50; // r6
  uint64_t v51; // r0
  uint64_t v52; // r6
  uint64_t v53; // r0
  uint64_t v54; // r0
  uint64_t v55; // r2
  uint64_t v56; // r0
  int v57; // r0
  int result; // r0
  int v59; // t1
  uint64_t v60; // r8
  uint64_t v61; // [sp+0h] [bp-1Ch]
  uint64_t v62; // [sp+8h] [bp-14h]
  uint64_t v63; // [sp+10h] [bp-Ch]

  v6 = __aeabi_d2lz(a3, a4);
  v9 = ke_event_schedule(dword_104F00, v6, v8);
  inited = gpio_init(v9);
  v11 = a1;
  ke_event_schedule(dword_104F08, (int)(float)(inited * flt_104F04), v12);
  v13 = a5[2];
  v14 = __aeabi_dmul(*((uint32_t *)a5 + 4), *((uint32_t *)a5 + 5), 0, dword_104F0C);
  __aeabi_d2lz(v14, HIDWORD(v14));
  v15 = a5[1];
  v16 = __aeabi_dmul(*((uint32_t *)a5 + 2), *((uint32_t *)a5 + 3), 0, dword_104F0C);
  v17 = __aeabi_d2lz(v16, HIDWORD(v16));
  v18 = *a5;
  v19 = v17;
  v20 = __aeabi_dmul(*(uint32_t *)a5, *((uint32_t *)a5 + 1), 0, dword_104F0C);
  v21 = __aeabi_d2lz(v20, HIDWORD(v20));
  v22 = a5[5];
  v63 = a5[4];
  v62 = a5[3];
  ke_event_schedule(dword_104F10, v21, v19);
  v23 = __aeabi_dmul(v22, HIDWORD(v22), 0, dword_104F0C);
  __aeabi_d2lz(v23, HIDWORD(v23));
  v24 = __aeabi_dmul(v63, HIDWORD(v63), 0, dword_104F0C);
  v25 = __aeabi_d2lz(v24, HIDWORD(v24));
  v26 = __aeabi_dmul(v62, HIDWORD(v62), 0, dword_104F0C);
  v27 = __aeabi_d2lz(v26, HIDWORD(v26));
  ke_event_schedule(dword_104F14, v27, v25);
  v28 = v11 + 32;
  do
  {
    v59 = *v11++;
    v60 = __aeabi_f2d(v59);
    if ( __aeabi_dcmpge(v18, HIDWORD(v18), v60, HIDWORD(v60)) )
    {
      v55 = v62;
    }
    else if ( __aeabi_dcmpeq(v15, HIDWORD(v15), v60, HIDWORD(v60)) )
    {
      v55 = v63;
    }
    else if ( __aeabi_dcmple(v13, HIDWORD(v13), v60, HIDWORD(v60)) )
    {
      v55 = v22;
    }
    else
    {
      v29 = __aeabi_dsub(v60, HIDWORD(v60), v15, HIDWORD(v15));
      v30 = __aeabi_dsub(v60, HIDWORD(v60), v13, HIDWORD(v13));
      v31 = __aeabi_dsub(v60, HIDWORD(v60), v18, HIDWORD(v18));
      v32 = v30;
      v33 = v31;
      v34 = __aeabi_dmul(v62, HIDWORD(v62), v29, HIDWORD(v29));
      v35 = v33;
      v36 = __aeabi_dmul(v34, HIDWORD(v34), v32, HIDWORD(v32));
      v37 = __aeabi_dsub(v18, HIDWORD(v18), v15, HIDWORD(v15));
      v38 = __aeabi_ddiv(v36, HIDWORD(v36), v37, HIDWORD(v37));
      v39 = __aeabi_dsub(v18, HIDWORD(v18), v13, HIDWORD(v13));
      v40 = __aeabi_ddiv(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = __aeabi_dmul(v63, HIDWORD(v63), v35, HIDWORD(v35));
      v42 = v40;
      v43 = __aeabi_dmul(v41, HIDWORD(v41), v32, HIDWORD(v32));
      v44 = __aeabi_dsub(v15, HIDWORD(v15), v18, HIDWORD(v18));
      v45 = __aeabi_ddiv(v43, HIDWORD(v43), v44, HIDWORD(v44));
      v46 = __aeabi_dsub(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v47 = __aeabi_ddiv(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = __aeabi_dadd(v42, HIDWORD(v42), v47, HIDWORD(v47));
      v49 = __aeabi_dmul(v22, HIDWORD(v22), v35, HIDWORD(v35));
      v50 = __aeabi_dmul(v49, HIDWORD(v49), v29, HIDWORD(v29));
      v51 = __aeabi_dsub(v13, HIDWORD(v13), v18, HIDWORD(v18));
      v52 = __aeabi_ddiv(v50, HIDWORD(v50), v51, HIDWORD(v51));
      v53 = __aeabi_dsub(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v54 = __aeabi_ddiv(v52, HIDWORD(v52), v53, HIDWORD(v53));
      v55 = __aeabi_dadd(v48, HIDWORD(v48), v54, HIDWORD(v54));
    }
    v61 = v55;
    v56 = __aeabi_f2d(v11[63]);
    v57 = __aeabi_dmul(v56, HIDWORD(v56), v61, HIDWORD(v61));
    result = double_to_float(v57);
    v11[31] = result;
  }
  while ( v11 != v28 );
  return result;
}

