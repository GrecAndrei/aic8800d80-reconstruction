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


extern float flt_109FE0;
extern float flt_109FE8;
extern uint32_t off_109FD8;

// sub_109DB4 @ 0x109db4, size 546 bytes
int  sub_109DB4(int a1, float *a2, int a3, int a4)
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
  uint64_t v33; // r0
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
  float *v50; // r9
  int v51; // t1
  float v52; // s16
  float *v53; // r5
  float v54; // s13
  int v56; // [sp+0h] [bp-44h]
  int v57; // [sp+4h] [bp-40h]
  float a2a[3]; // [sp+8h] [bp-3Ch] BYREF
  float a3a[3]; // [sp+14h] [bp-30h] BYREF
  uint32_t v60[9]; // [sp+20h] [bp-24h] BYREF

  v8 = ((uint32_t *)(uintptr_t)off_109FD8)[1];
  v9 = ((uint32_t *)(uintptr_t)off_109FD8)[2];
  v10 = ((uint32_t *)(uintptr_t)off_109FD8)[3];
  v60[0] = ((uint32_t *)(uintptr_t)off_109FD8)[0];
  v60[1] = v8;
  v60[2] = v9;
  v60[3] = v10;
  v11 = ((uint32_t *)(uintptr_t)off_109FD8)[5];
  v12 = ((uint32_t *)(uintptr_t)off_109FD8)[6];
  v13 = ((uint32_t *)(uintptr_t)off_109FD8)[7];
  v60[4] = ((uint32_t *)(uintptr_t)off_109FD8)[4];
  v60[5] = v11;
  v60[6] = v12;
  v60[7] = v13;
  v14 = a2[4];
  v15 = a2[34];
  v16 = a2[2];
  v17 = a2[36];
  a2a[1] = a2[3];
  v18 = 0.0;
  v19 = a1;
  a2a[2] = v14;
  a3a[0] = v15;
  v20 = a2[35];
  v57 = a1;
  a2a[0] = v16;
  a2[159] = 0.0;
  a2[160] = 0.0;
  v56 = a3;
  a3a[1] = v20;
  a3a[2] = v17;
  sub_109B30(0, a2a, a3a, a4);
  if ( v19 > 0 )
  {
    v21 = v60;
    v22 = a2;
    v23 = &a2[v19];
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
        v28 = sub_1429F8(COERCE_UNSIGNED_INT((float)(v27 - v26) + *(float *)(a4 + 12)));
        v29 = sub_142AA8(v28, v28);
        v30 = sub_1429F8(COERCE_UNSIGNED_INT((float)(v25 * v25) + 1.0));
        v31 = sub_142CFC(v29, v30);
        v32 = sub_1429F8(LODWORD(v18));
        v33 = sub_14273C(v31, v32);
        v18 = COERCE_FLOAT(sub_14306C(v33));
        if ( v22 == v23 )
          goto LABEL_6;
      }
    }
  }
LABEL_6:
  if ( !v56 )
  {
    sub_12ECD0(1, aDpdBypassStatu);
    v34 = v57;
    if ( v57 > 0 )
      goto LABEL_8;
LABEL_20:
    v45 = flt_109FE0;
    v46 = flt_109FE0;
    v49 = v56;
    goto LABEL_18;
  }
  sub_12ECD0(1, aDbdCalAmpmTabl);
  v34 = v57;
  if ( v57 <= 0 )
    goto LABEL_20;
LABEL_8:
  v35 = 4 * v34 + 384;
  v36 = v60;
  v37 = a2 + 96;
  v38 = flt_109FE0;
  v39 = (float *)((char *)a2 + v35);
  v40 = v60;
  v41 = a2 + 96;
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
  v48 = (float *)((char *)a2 + v35);
  v49 = v56;
  v50 = &a2[v56];
  while ( v48 != ++v37 )
  {
    while ( 1 )
    {
      v51 = *((uint8_t *)v36 + 1);
      v36 = (uint32_t *)((char *)v36 + 1);
      if ( v51 != 1 )
        break;
      v52 = *v37 - v47;
      if ( (float)sub_143708((int)v52) > v50[159] )
        v50[159] = (float)sub_143708((int)v52);
      ++v37;
      v46 = v46 + (float)(v52 * v52);
      if ( v48 == v37 )
        goto LABEL_18;
    }
  }
LABEL_18:
  v53 = &a2[v49];
  v54 = flt_109FE8;
  v53[128] = v18 / v45;
  v53[130] = v46 / v45;
  return sub_12ECD0(
           1,
           "am_var*1000000=%10d ph_var*1000000=%10d\n",
           (int)(float)((float)(v18 / v45) * v54),
           (int)(float)((float)(v46 / v45) * v54));
}
