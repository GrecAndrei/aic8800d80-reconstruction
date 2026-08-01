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

extern uint32_t dword_104F90;
extern uint32_t dword_104F98;
extern uint32_t dword_104F9C;
extern uint32_t dword_104FA0;
extern uint32_t dword_104FA4;

// float_interp @ 0x104cc8, size 710 bytes
int  float_interp(int *a1, int a2, int a3, int a4, uint64_t *a5)
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
  v9 = alloc_tx_event(dword_104F90, v6, v8);
  v10 = hw_block_disable(v9);
  v11 = a1;
  alloc_tx_event(dword_104F98, (int)(float)(v10 * flt_104F94), v12);
  v13 = a5[2];
  v14 = double_compare_common(*((uint32_t *)a5 + 4), *((uint32_t *)a5 + 5), 0, dword_104F9C);
  double_to_float(v14, HIDWORD(v14));
  v15 = a5[1];
  v16 = double_compare_common(*((uint32_t *)a5 + 2), *((uint32_t *)a5 + 3), 0, dword_104F9C);
  v17 = double_to_float(v16, HIDWORD(v16));
  v18 = *a5;
  v19 = v17;
  v20 = double_compare_common(*(uint32_t *)a5, *((uint32_t *)a5 + 1), 0, dword_104F9C);
  v21 = double_to_float(v20, HIDWORD(v20));
  v22 = a5[5];
  v63 = a5[4];
  v62 = a5[3];
  alloc_tx_event(dword_104FA0, v21, v19);
  v23 = double_compare_common(v22, HIDWORD(v22), 0, dword_104F9C);
  double_to_float(v23, HIDWORD(v23));
  v24 = double_compare_common(v63, HIDWORD(v63), 0, dword_104F9C);
  v25 = double_to_float(v24, HIDWORD(v24));
  v26 = double_compare_common(v62, HIDWORD(v62), 0, dword_104F9C);
  v27 = double_to_float(v26, HIDWORD(v26));
  alloc_tx_event(dword_104FA4, v27, v25);
  v28 = v11 + 32;
  do
  {
    v59 = *v11++;
    v60 = float_to_double(v59);
    if ( double_greater_equal(v18, HIDWORD(v18), v60, HIDWORD(v60)) )
    {
      v55 = v62;
    }
    else if ( double_equals(v15, HIDWORD(v15), v60, HIDWORD(v60)) )
    {
      v55 = v63;
    }
    else if ( double_less_equal(v13, HIDWORD(v13), v60, HIDWORD(v60)) )
    {
      v55 = v22;
    }
    else
    {
      v29 = double_compare_neg(v60, HIDWORD(v60), v15, HIDWORD(v15));
      v30 = double_compare_neg(v60, HIDWORD(v60), v13, HIDWORD(v13));
      v31 = double_compare_neg(v60, HIDWORD(v60), v18, HIDWORD(v18));
      v32 = v30;
      v33 = v31;
      v34 = double_compare_common(v62, HIDWORD(v62), v29, HIDWORD(v29));
      v35 = v33;
      v36 = double_compare_common(v34, HIDWORD(v34), v32, HIDWORD(v32));
      v37 = double_compare_neg(v18, HIDWORD(v18), v15, HIDWORD(v15));
      v38 = double_compare_core(v36, HIDWORD(v36), v37, HIDWORD(v37));
      v39 = double_compare_neg(v18, HIDWORD(v18), v13, HIDWORD(v13));
      v40 = double_compare_core(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = double_compare_common(v63, HIDWORD(v63), v35, HIDWORD(v35));
      v42 = v40;
      v43 = double_compare_common(v41, HIDWORD(v41), v32, HIDWORD(v32));
      v44 = double_compare_neg(v15, HIDWORD(v15), v18, HIDWORD(v18));
      v45 = double_compare_core(v43, HIDWORD(v43), v44, HIDWORD(v44));
      v46 = double_compare_neg(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v47 = double_compare_core(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = double_compare_eq(v42, HIDWORD(v42), v47, HIDWORD(v47));
      v49 = double_compare_common(v22, HIDWORD(v22), v35, HIDWORD(v35));
      v50 = double_compare_common(v49, HIDWORD(v49), v29, HIDWORD(v29));
      v51 = double_compare_neg(v13, HIDWORD(v13), v18, HIDWORD(v18));
      v52 = double_compare_core(v50, HIDWORD(v50), v51, HIDWORD(v51));
      v53 = double_compare_neg(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v54 = double_compare_core(v52, HIDWORD(v52), v53, HIDWORD(v53));
      v55 = double_compare_eq(v48, HIDWORD(v48), v54, HIDWORD(v54));
    }
    v61 = v55;
    v56 = float_to_double(v11[63]);
    v57 = double_compare_common(v56, HIDWORD(v56), v61, HIDWORD(v61));
    result = double_to_int(v57);
    v11[31] = result;
  }
  while ( v11 != v28 );
  return result;
}

