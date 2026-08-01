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

extern uint32_t dword_109FD8;
extern uint32_t dword_109FDC;
extern uint32_t dword_109FEC;
extern uint32_t dword_109FE4;

// struct_load @ 0x109db4, size 546 bytes
int  struct_load(int a1, int a2, int a3, int a4)
{
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  float v14; // r1
  float v15; // r0
  float v16; // r12
  float v17; // r4
  float v18; // r11
  int v19; // r8
  float v20; // r6
  uint32_t *v21; // r6
  float *v22; // r4
  float *v23; // r7
  int v24; // t1
  float v25; // s16
  float v26; // s13
  float v27; // s15
  uint64_t v28; // r0
  uint64_t v29; // r8
  uint64_t v30; // r0
  uint64_t v31; // r8
  uint64_t v32; // r0
  int v33; // r0
  int v34; // r3
  int v35; // r7
  uint32_t *v36; // r6
  float *v37; // r4
  float v38; // s15
  float *v39; // r12
  uint32_t *v40; // r2
  float *v41; // r3
  int v42; // r0
  int v43; // t1
  float v44; // s14
  float v45; // s17
  float v46; // s18
  float v47; // s19
  float *v48; // r7
  int v49; // r8
  int v50; // r9
  int v51; // t1
  float v52; // s16
  int v53; // r5
  int v54; // r1
  int v56; // [sp+0h] [bp-44h]
  int v57; // [sp+4h] [bp-40h]
  float v58[3]; // [sp+8h] [bp-3Ch] BYREF
  float v59[3]; // [sp+14h] [bp-30h] BYREF
  uint32_t v60[9]; // [sp+20h] [bp-24h] BYREF

  v8 = *(uint32_t *)(dword_109FD8 + 4);
  v9 = *(uint32_t *)(dword_109FD8 + 8);
  v10 = *(uint32_t *)(dword_109FD8 + 12);
  v60[0] = *(uint32_t *)dword_109FD8;
  v60[1] = v8;
  v60[2] = v9;
  v60[3] = v10;
  v11 = *(uint32_t *)(dword_109FD8 + 20);
  v12 = *(uint32_t *)(dword_109FD8 + 24);
  v13 = *(uint32_t *)(dword_109FD8 + 28);
  v60[4] = *(uint32_t *)(dword_109FD8 + 16);
  v60[5] = v11;
  v60[6] = v12;
  v60[7] = v13;
  v14 = *(float *)(a2 + 16);
  v15 = *(float *)(a2 + 136);
  v16 = *(float *)(a2 + 8);
  v17 = *(float *)(a2 + 144);
  v58[1] = *(float *)(a2 + 12);
  v18 = 0.0;
  v19 = a1;
  v58[2] = v14;
  v59[0] = v15;
  v20 = *(float *)(a2 + 140);
  v57 = a1;
  v58[0] = v16;
  *(uint32_t *)(a2 + 636) = 0;
  *(uint32_t *)(a2 + 640) = 0;
  v56 = a3;
  v59[1] = v20;
  v59[2] = v17;
  f32_pair_compare(0, v58, v59, a4);
  if ( v19 > 0 )
  {
    v21 = v60;
    v22 = (float *)a2;
    v23 = (float *)(a2 + 4 * v19);
    while ( ++v22 != v23 )
    {
      while ( 1 )
      {
        v24 = *((uint8_t *)v21 + 1);
        v21 = (uint32_t *)((char *)v21 + 1);
        if ( v24 != 1 )
          break;
        v25 = *(float *)(a4 + 8);
        v26 = v22[32];
        v27 = v25 * *v22++;
        v28 = float_to_double((float)(v27 - v26) + *(float *)(a4 + 12));
        v29 = double_add(v28, HIDWORD(v28), v28, HIDWORD(v28));
        v30 = float_to_double((float)(v25 * v25) + 1.0);
        v31 = double_subtract(v29, HIDWORD(v29), v30, HIDWORD(v30));
        v32 = float_to_double(LODWORD(v18));
        v33 = double_compare(v31, HIDWORD(v31), v32, HIDWORD(v32));
        v18 = COERCE_FLOAT(double_to_uint(v33));
        if ( v22 == v23 )
          goto LABEL_6;
      }
    }
  }
LABEL_6:
  if ( !v56 )
  {
    check_status_bits(1, dword_109FDC);
    v34 = v57;
    if ( v57 > 0 )
      goto LABEL_8;
LABEL_20:
    v45 = flt_109FE0;
    v46 = flt_109FE0;
    v49 = 4 * v56;
    goto LABEL_18;
  }
  check_status_bits(1, dword_109FEC);
  v34 = v57;
  if ( v57 <= 0 )
    goto LABEL_20;
LABEL_8:
  v35 = 4 * v34 + 384;
  v36 = v60;
  v37 = (float *)(a2 + 384);
  v38 = flt_109FE0;
  v39 = (float *)(a2 + v35);
  v40 = v60;
  v41 = (float *)(a2 + 384);
  v42 = 0;
  while ( ++v41 != v39 )
  {
    while ( 1 )
    {
      v43 = *((uint8_t *)v40 + 1);
      v40 = (uint32_t *)((char *)v40 + 1);
      if ( v43 != 1 )
        break;
      v44 = *v41++;
      v38 = v38 + v44;
      ++v42;
      if ( v41 == v39 )
        goto LABEL_12;
    }
  }
LABEL_12:
  v45 = (float)v42;
  v46 = flt_109FE0;
  v47 = v38 / (float)v42;
  v48 = (float *)(v35 + a2);
  v49 = 4 * v56;
  v50 = a2 + 4 * v56;
  while ( v48 != ++v37 )
  {
    while ( 1 )
    {
      v51 = *((uint8_t *)v36 + 1);
      v36 = (uint32_t *)((char *)v36 + 1);
      if ( v51 != 1 )
        break;
      v52 = *v37 - v47;
      if ( (float)abs_i32((int)v52) > *(float *)(v50 + 636) )
        *(float *)(v50 + 636) = (float)abs_i32((int)v52);
      ++v37;
      v46 = v46 + (float)(v52 * v52);
      if ( v48 == v37 )
        goto LABEL_18;
    }
  }
LABEL_18:
  v53 = a2 + v49;
  v54 = dword_109FE4;
  *(float *)(v53 + 512) = v18 / v45;
  *(float *)(v53 + 520) = v46 / v45;
  return check_status_bits(1, v54);
}

