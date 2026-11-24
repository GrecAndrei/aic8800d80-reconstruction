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


extern uint32_t dword_109D98;
extern float flt_109DA0;
extern float flt_109DAC;
extern float flt_109DB0;

// sub_109B30 @ 0x109b30, size 610 bytes
int  sub_109B30(unsigned int a1, float *a2, float *a3, int a4)
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
  float v18; // s10
  float v19; // s11
  float v20; // s15
  float v21; // s17
  float v22; // s16
  int result; // r0
  float v24; // s12
  float v25; // s15
  char v26; // r3
  uint64_t v27; // r0
  float v28; // s15
  float v29; // s13
  float v30; // s14
  float v31; // s9
  float v32; // s10
  float v33; // s11
  uint64_t v34; // r0

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
    v17 = sub_1429F8(COERCE_UNSIGNED_INT((float)(v14 * 3.0) - (float)(v15 * v15)));
    if ( !sub_142F8C(v17, *(uint64_t *)&dword_109D98) )
      goto LABEL_11;
    v16 = flt_109DA0;
    goto LABEL_10;
  }
  v34 = sub_1429F8(COERCE_UNSIGNED_INT(-v16));
  if ( sub_142F8C(v34, *(uint64_t *)&dword_109D98) )
  {
    v16 = flt_109DB0;
LABEL_10:
    *(uint8_t *)a4 |= 4u;
    sub_10DC24(aDetectDivision);
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
  }
LABEL_11:
  v18 = a3[1];
  v19 = a3[2];
  v20 = -(float)((float)(1.0 / v16) * v15);
  v21 = (float)((float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v11) - (float)((float)(1.0 / v16) * v15))
                      * *a3)
              + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v12) - (float)((float)(1.0 / v16) * v15))
                      * v18))
      + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v13) - (float)((float)(1.0 / v16) * v15)) * v19);
  v22 = (float)((float)((float)((float)(v20 * v11) + (float)(v14 * (float)(1.0 / v16))) * *a3)
              + (float)((float)((float)(v20 * v12) + (float)(v14 * (float)(1.0 / v16))) * v18))
      + (float)((float)((float)(v20 * v13) + (float)(v14 * (float)(1.0 / v16))) * v19);
  if ( a1 > 0xD && v21 < 20.0
    || (v27 = sub_1429F8(LODWORD(v21)), (result = sub_142F8C(v27, *(uint64_t *)&dword_109D98)) != 0) )
  {
    *(uint8_t *)a4 |= 8u;
    result = sub_10DC24(aSlopeTooSmall);
    v21 = 1.0;
    v24 = 2.0;
  }
  else
  {
    v24 = (float)(v21 * v21) + 1.0;
  }
  v25 = (float)-v22 / v21;
  if ( v25 > flt_109DAC )
  {
    v26 = -1;
  }
  else if ( v25 < 0.0 )
  {
    v26 = 0;
  }
  else
  {
    v26 = (unsigned int)(float)(v25 + 0.5);
  }
  *(uint8_t *)(a4 + 1) = v26;
  v28 = *a2;
  v29 = a2[1];
  v30 = a2[2];
  v31 = *a3;
  v32 = a3[1];
  v33 = a3[2];
  *(float *)(a4 + 12) = v22;
  *(float *)(a4 + 8) = v21;
  *(float *)(a4 + 4) = (float)((float)((float)((float)((float)((float)(v21 * v28) + v22) - v31)
                                             * (float)((float)((float)(v21 * v28) + v22) - v31))
                                     + (float)((float)((float)((float)(v21 * v29) + v22) - v32)
                                             * (float)((float)((float)(v21 * v29) + v22) - v32)))
                             + (float)((float)((float)((float)(v21 * v30) + v22) - v33)
                                     * (float)((float)((float)(v21 * v30) + v22) - v33)))
                     / v24;
  return result;
}
