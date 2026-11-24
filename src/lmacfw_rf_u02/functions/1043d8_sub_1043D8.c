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


extern uint32_t dword_10470C;
extern float flt_104714;
extern float flt_104718;
extern float flt_10471C;
extern float flt_104720;
extern float flt_104724;
extern float flt_104728;
extern float flt_10472C;
extern float flt_1047B0;
extern uint32_t off_104704;
extern uint32_t off_104708;

// wlan_init_globals @ 0x1043d8, size 978 bytes
int  wlan_init_globals(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int *v7; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r6
  int v20; // r2
  int v21; // r5
  int v22; // r3
  uint32_t *v23; // r3
  float v24; // s23
  float v25; // s20
  float v26; // s19
  float v27; // s18
  float v28; // s21
  float v29; // s22
  int v30; // r8
  int v31; // r9
  int v32; // r3
  float v33; // s14
  int v34; // r7
  int v35; // r0
  float v36; // s17
  int i; // r5
  float v38; // s16
  float v39; // s15
  float v40; // s17
  float v41; // s17
  float v42; // s18
  float v43; // s17
  float v44; // s16
  float *v45; // r4
  int j; // r5
  float v47; // s15
  float v48; // r0
  char *v49; // r2
  float v50; // s15
  float v51; // s16
  float *v52; // r5
  float v53; // s14
  int result; // r0
  int v55; // r0
  int v56; // [sp+8h] [bp-14Ch]
  int v57; // [sp+Ch] [bp-148h]
  int v58; // [sp+10h] [bp-144h]
  int v59; // [sp+18h] [bp-13Ch]
  int v60; // [sp+1Ch] [bp-138h]
  int v61; // [sp+24h] [bp-130h]
  uint32_t v63[8]; // [sp+30h] [bp-124h]
  char a1a[128]; // [sp+50h] [bp-104h] BYREF
  char v65[132]; // [sp+D0h] [bp-84h] BYREF

  v7 = (int *)off_104704;
  check_interrupt_flag(1, aRunparescore);
  memcpy_large(a1a, (char *)off_104708, 0x80u);
  v11 = *v7;
  v12 = v7[1];
  v13 = v7[2];
  v14 = v7[3];
  v7 += 4;
  v63[0] = v11;
  v63[1] = v12;
  v63[2] = v13;
  v63[3] = v14;
  v15 = v7[1];
  v16 = v7[2];
  v17 = v7[3];
  v63[4] = *v7;
  v63[5] = v15;
  v63[6] = v16;
  v63[7] = v17;
  memcpy_large(v65, (char *)v7 + 16, 0x80u);
  v18 = tx_power_calibrate(0, 0, a3);
  v19 = v18;
  v58 = a1 + 128;
  v59 = a1 + 384;
  if ( a2 == 1 )
  {
    v55 = tx_power_calibrate(0, 1, a4);
    if ( v19 < v55 )
      v19 += 1280;
    v21 = v55;
    v20 = v19 - v55;
  }
  else
  {
    v20 = v18;
    v21 = 0;
  }
  v22 = ((int)((uint64_t)(dword_10470C * (uint64_t)(0x2000 - v19)) >> 32) >> 9) - ((0x2000 - v19) >> 31);
  if ( a6 )
  {
    if ( v22 >= 5 )
      v22 = 5;
  }
  else if ( v22 >= 10 )
  {
    v22 = 10;
  }
  v60 = v22;
  check_interrupt_flag(1, " est tx start = %4d, est rx start = %4d, dly = %d, total seg = %d, \n", v21, v19, v20, v22);
  v23 = (uint32_t *)(a1 + 128);
  do
  {
    *v23++ = 0;
    v23[63] = 0;
  }
  while ( v23 != (uint32_t *)(a1 + 256) );
  if ( v60 > 0 )
  {
    v24 = flt_104714;
    v25 = flt_104718;
    v26 = flt_10471C;
    v27 = flt_104720;
    v57 = v19;
    v28 = flt_104714;
    v61 = v21 - v19;
    do
    {
      v29 = flt_104724;
      v30 = 0;
      v31 = 2;
      while ( 1 )
      {
        if ( a6 == 1 && !*((uint8_t *)v63 + v31) )
          goto LABEL_12;
        v33 = flt_104714;
        v56 = *(uint32_t *)&v65[4 * v31];
        v34 = v56 + v57;
        do
        {
          v35 = lookup_rf_table(v34++, 0, a3);
          v33 = v33 + (float)v35;
        }
        while ( v34 != v56 + v57 + 12 );
        *(float *)(v58 + 4 * v31) = *(float *)(v58 + 4 * v31) + v33;
        if ( v31 <= 1 )
        {
LABEL_12:
          v32 = v30 + 1;
          if ( v30 == 31 )
            break;
          goto LABEL_13;
        }
        v36 = flt_104714;
        for ( i = 1; ; ++i )
        {
          v38 = COERCE_FLOAT(apply_tx_power(v56 + v57 - 1 + i, 0, a3));
          v39 = v38 - COERCE_FLOAT(apply_tx_power(v56 + v61 + v57 - 1 + i, 1, a4));
          if ( v39 < v25 )
            v39 = v39 + v26;
          if ( v39 > v27 )
            v39 = v39 - v26;
          if ( i == 1 )
          {
            v36 = v36 + v39;
            v28 = v39;
            continue;
          }
          if ( (float)(v39 - v28) <= v27 )
            break;
          v36 = v36 + (float)(v39 - v26);
          if ( i == 12 )
            goto LABEL_34;
LABEL_24:
          ;
        }
        if ( (float)(v39 - v28) < v25 )
          v39 = v39 + v26;
        v36 = v36 + v39;
        if ( i != 12 )
          goto LABEL_24;
LABEL_34:
        v40 = v36 * v29;
        if ( v40 <= 1.0 )
        {
          if ( v40 < -1.0 )
            v40 = v40 + 2.0;
          if ( v31 == 2 )
            goto LABEL_48;
LABEL_36:
          v41 = v40 - v24;
          if ( v41 <= 1.0 )
          {
            if ( v41 < -1.0 )
              v41 = v41 + 2.0;
          }
          else
          {
            v41 = v41 - 2.0;
          }
        }
        else
        {
          v40 = v40 - 2.0;
          if ( v31 != 2 )
            goto LABEL_36;
LABEL_48:
          v24 = v40;
          v41 = flt_104714;
        }
        *(float *)(4 * v31 + v59) = *(float *)(4 * v31 + v59) + v41;
        v32 = v30 + 1;
        if ( v30 == 31 )
          break;
LABEL_13:
        if ( v32 <= 2 )
          v31 = v30;
        else
          v31 = v32;
        v30 = v32;
      }
      v57 += 1280;
    }
    while ( v57 != v19 + 1280 * v60 );
  }
  v42 = flt_104728;
  v43 = flt_10472C;
  v44 = (float)v60;
  v45 = (float *)a1;
  for ( j = 1; ; ++j )
  {
    v48 = hash_const_init((float)(v45[32] / v44) / 12.0);
    v49 = &a1a[4 * j];
    v45[32] = v48;
    if ( (unsigned int)(j - 1) > 1 )
      break;
    v50 = (float)*((int *)v49 - 1) * v42;
    v45[96] = (float)(*(float *)(a1 + 392) / v44) * v43;
    *v45 = v50;
LABEL_42:
    ++v45;
  }
  v47 = (float)*((int *)v49 - 1) * v42;
  v45[96] = (float)(v45[96] / v44) * v43;
  *v45 = v47;
  if ( j != 32 )
    goto LABEL_42;
  v51 = flt_1047B0;
  check_interrupt_flag(1, aAmBeginAmBackP);
  v52 = (float *)a1;
  do
  {
    v53 = *v52++;
    result = check_interrupt_flag(
               1,
               "%10d %10d %10d\n",
               (int)(float)(v53 * v51),
               (int)(float)(v52[31] * v51),
               (int)(float)(v52[95] * v51));
  }
  while ( (float *)v58 != v52 );
  return result;
}
