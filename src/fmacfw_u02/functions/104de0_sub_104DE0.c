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

extern uint32_t dword_1050A8;
extern uint32_t dword_1050B0;
extern uint32_t dword_1050B4;
extern uint32_t dword_1050B8;
extern uint32_t dword_1050BC;

// rf_calibrate_power @ 0x104de0, size 710 bytes
// Doc: sub_1204DE0 [util]: Helper: bl-call wrapper with FPU save and stack alloc
// sub_1204DE0 [util]: Helper: bl-call wrapper with FPU save and stack alloc
int  rf_calibrate_power(int *a1, int a2, int a3, int a4, uint64_t *a5)
{
  int v6; // r0
  int v8; // r2
  int v9; // r0
  float v10; // r0
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

  v6 = double_to_float(a3, a4);
  v9 = event_dispatch(dword_1050A8, v6, v8);
  v10 = rf_core_reset(v9);
  v11 = a1;
  event_dispatch(dword_1050B0, (int)(float)(v10 * flt_1050AC), v12);
  v13 = a5[2];
  v14 = double_add(*((uint32_t *)a5 + 4), *((uint32_t *)a5 + 5), 0, dword_1050B4);
  double_to_float(v14, HIDWORD(v14));
  v15 = a5[1];
  v16 = double_add(*((uint32_t *)a5 + 2), *((uint32_t *)a5 + 3), 0, dword_1050B4);
  v17 = double_to_float(v16, HIDWORD(v16));
  v18 = *a5;
  v19 = v17;
  v20 = double_add(*(uint32_t *)a5, *((uint32_t *)a5 + 1), 0, dword_1050B4);
  v21 = double_to_float(v20, HIDWORD(v20));
  v22 = a5[5];
  v63 = a5[4];
  v62 = a5[3];
  event_dispatch(dword_1050B8, v21, v19);
  v23 = double_add(v22, HIDWORD(v22), 0, dword_1050B4);
  double_to_float(v23, HIDWORD(v23));
  v24 = double_add(v63, HIDWORD(v63), 0, dword_1050B4);
  v25 = double_to_float(v24, HIDWORD(v24));
  v26 = double_add(v62, HIDWORD(v62), 0, dword_1050B4);
  v27 = double_to_float(v26, HIDWORD(v26));
  event_dispatch(dword_1050BC, v27, v25);
  v28 = v11 + 32;
  do
  {
    v59 = *v11++;
    v60 = float_to_double(v59);
    if ( double_ge(v18, HIDWORD(v18), v60, HIDWORD(v60)) )
    {
      v55 = v62;
    }
    else if ( double_eq(v15, HIDWORD(v15), v60, HIDWORD(v60)) )
    {
      v55 = v63;
    }
    else if ( double_le(v13, HIDWORD(v13), v60, HIDWORD(v60)) )
    {
      v55 = v22;
    }
    else
    {
      v29 = double_compare_wrapper(v60, HIDWORD(v60), v15, HIDWORD(v15));
      v30 = double_compare_wrapper(v60, HIDWORD(v60), v13, HIDWORD(v13));
      v31 = double_compare_wrapper(v60, HIDWORD(v60), v18, HIDWORD(v18));
      v32 = v30;
      v33 = v31;
      v34 = double_add(v62, HIDWORD(v62), v29, HIDWORD(v29));
      v35 = v33;
      v36 = double_add(v34, HIDWORD(v34), v32, HIDWORD(v32));
      v37 = double_compare_wrapper(v18, HIDWORD(v18), v15, HIDWORD(v15));
      v38 = double_subtract(v36, HIDWORD(v36), v37, HIDWORD(v37));
      v39 = double_compare_wrapper(v18, HIDWORD(v18), v13, HIDWORD(v13));
      v40 = double_subtract(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = double_add(v63, HIDWORD(v63), v35, HIDWORD(v35));
      v42 = v40;
      v43 = double_add(v41, HIDWORD(v41), v32, HIDWORD(v32));
      v44 = double_compare_wrapper(v15, HIDWORD(v15), v18, HIDWORD(v18));
      v45 = double_subtract(v43, HIDWORD(v43), v44, HIDWORD(v44));
      v46 = double_compare_wrapper(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v47 = double_subtract(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = double_compare(v42, HIDWORD(v42), v47, HIDWORD(v47));
      v49 = double_add(v22, HIDWORD(v22), v35, HIDWORD(v35));
      v50 = double_add(v49, HIDWORD(v49), v29, HIDWORD(v29));
      v51 = double_compare_wrapper(v13, HIDWORD(v13), v18, HIDWORD(v18));
      v52 = double_subtract(v50, HIDWORD(v50), v51, HIDWORD(v51));
      v53 = double_compare_wrapper(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v54 = double_subtract(v52, HIDWORD(v52), v53, HIDWORD(v53));
      v55 = double_compare(v48, HIDWORD(v48), v54, HIDWORD(v54));
    }
    v61 = v55;
    v56 = float_to_double(v11[63]);
    v57 = double_add(v56, HIDWORD(v56), v61, HIDWORD(v61));
    result = double_to_uint(v57);
    v11[31] = result;
  }
  while ( v11 != v28 );
  return result;
}

