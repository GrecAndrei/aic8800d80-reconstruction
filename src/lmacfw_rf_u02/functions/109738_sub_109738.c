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

extern uint32_t dword_1099A0;
extern uint32_t dword_1099A4;
extern uint32_t dword_1099AC;
extern uint32_t dword_1099B0;

// compare_float_samples @ 0x109738, size 610 bytes
int  compare_float_samples(unsigned int a1, float *a2, float *a3, int a4)
{
  float v4; // s13
  float v5; // s14
  float v10; // s15
  float v11; // s16
  float v12; // s19
  float v13; // s18
  float v14; // s20
  float v15; // s17
  float v16; // s21
  uint64_t v17; // r0
  int v18; // r1
  int v19; // r2
  int v20; // r0
  float v21; // s10
  float v22; // s11
  float v23; // s15
  float v24; // s17
  float v25; // s16
  int v26; // r0
  int result; // r0
  float v28; // s12
  float v29; // s15
  char v30; // r3
  uint64_t v31; // r0
  float v32; // s15
  float v33; // s13
  float v34; // s14
  float v35; // s9
  float v36; // s10
  float v37; // s11
  uint64_t v38; // r0

  v4 = a2[1];
  v5 = *a2;
  if ( v4 <= *a2 )
  {
    v4 = *a2;
    v5 = a2[1];
  }
  v10 = a2[2];
  if ( v10 <= v4 )
  {
    if ( v10 < v5 )
      v5 = a2[2];
    v10 = v4;
  }
  *(uint8_t *)(a4 + 2) = (unsigned int)(float)(v10 - v5);
  v11 = *a2;
  v12 = a2[1];
  v13 = a2[2];
  v14 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13);
  v15 = (float)(*a2 + v12) + v13;
  v16 = (float)(v14 * 3.0) - (float)(v15 * v15);
  if ( v16 > 0.0 )
  {
    v17 = aeabi_d2f((float)(v14 * 3.0) - (float)(v15 * v15));
    if ( !double_lt(v17, HIDWORD(v17), dword_1099A0, dword_1099A4) )
      goto LABEL_11;
    v16 = flt_1099A8;
    goto LABEL_10;
  }
  v38 = aeabi_d2f(-v16);
  if ( double_lt(v38, HIDWORD(v38), dword_1099A0, dword_1099A4) )
  {
    v16 = flt_1099B8;
LABEL_10:
    v20 = dword_1099AC;
    *(uint8_t *)a4 |= 4u;
    log_printf(v20, v18, v19);
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
  }
LABEL_11:
  v21 = a3[1];
  v22 = a3[2];
  v23 = -(float)((float)(1.0 / v16) * v15);
  v24 = (float)((float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v11) - (float)((float)(1.0 / v16) * v15))
                      * *a3)
              + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v12) - (float)((float)(1.0 / v16) * v15))
                      * v21))
      + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v13) - (float)((float)(1.0 / v16) * v15)) * v22);
  v25 = (float)((float)((float)((float)(v23 * v11) + (float)(v14 * (float)(1.0 / v16))) * *a3)
              + (float)((float)((float)(v23 * v12) + (float)(v14 * (float)(1.0 / v16))) * v21))
      + (float)((float)((float)(v23 * v13) + (float)(v14 * (float)(1.0 / v16))) * v22);
  if ( a1 > 0xD && v24 < 20.0
    || (v31 = aeabi_d2f(LODWORD(v24)), (result = double_lt(v31, HIDWORD(v31), dword_1099A0, dword_1099A4)) != 0) )
  {
    v26 = dword_1099B0;
    *(uint8_t *)a4 |= 8u;
    result = log_printf(v26, v18, v19);
    v24 = 1.0;
    v28 = 2.0;
  }
  else
  {
    v28 = (float)(v24 * v24) + 1.0;
  }
  v29 = (float)-v25 / v24;
  if ( v29 > flt_1099B4 )
  {
    v30 = -1;
  }
  else if ( v29 < 0.0 )
  {
    v30 = 0;
  }
  else
  {
    v30 = (unsigned int)(float)(v29 + 0.5);
  }
  *(uint8_t *)(a4 + 1) = v30;
  v32 = *a2;
  v33 = a2[1];
  v34 = a2[2];
  v35 = *a3;
  v36 = a3[1];
  v37 = a3[2];
  *(float *)(a4 + 12) = v25;
  *(float *)(a4 + 8) = v24;
  *(float *)(a4 + 4) = (float)((float)((float)((float)((float)((float)(v24 * v32) + v25) - v35)
                                             * (float)((float)((float)(v24 * v32) + v25) - v35))
                                     + (float)((float)((float)((float)(v24 * v33) + v25) - v36)
                                             * (float)((float)((float)(v24 * v33) + v25) - v36)))
                             + (float)((float)((float)((float)(v24 * v34) + v25) - v37)
                                     * (float)((float)((float)(v24 * v34) + v25) - v37)))
                     / v28;
  return result;
}

