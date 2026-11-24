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


extern uint32_t dword_10A460;
extern float flt_10A46C;
extern float flt_10A484;
extern float flt_10A494;
extern float flt_10A498;
extern float flt_10A73C;
extern float flt_10A740;
extern float flt_10A758;
extern uint32_t off_10A468;
extern uint32_t off_10A4B4;
extern uint32_t off_10A748;

// sub_10A138 @ 0x10a138, size 1512 bytes
int  sub_10A138(
        uint32_t *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  uint32_t *v11; // r10
  int v13; // r1
  int v14; // r2
  float v15; // s20
  int v17; // r7
  unsigned int v19; // r3
  int v20; // r11
  unsigned int v21; // r0
  char *v22; // r7
  int v23; // r4
  float v24; // s16
  float v25; // s21
  float v26; // s22
  float v27; // s17
  int v28; // r8
  float v29; // s23
  float v30; // s16
  int v31; // s25
  unsigned int v32; // s15
  uint64_t v33; // r0
  int v34; // r3
  int v35; // cc
  int result; // r0
  uint32_t *v37; // r3
  int v38; // [sp+20h] [bp-20h]
  int v39; // [sp+24h] [bp-1Ch]
  int v40; // [sp+2Ch] [bp-14h]
  int a1a; // [sp+30h] [bp-10h]
  int *v42; // [sp+34h] [bp-Ch]
  int *v43; // [sp+38h] [bp-8h]
  unsigned int *v44; // [sp+3Ch] [bp-4h]
  uint32_t v45[3]; // [sp+40h] [bp+0h] BYREF
  int a2a[5]; // [sp+4Ch] [bp+Ch] BYREF
  float v47; // [sp+24Ch] [bp+20Ch]
  float v48; // [sp+250h] [bp+210h]
  float v49; // [sp+254h] [bp+214h]
  float v50; // [sp+258h] [bp+218h]
  char v51; // [sp+25Ch] [bp+21Ch] BYREF
  int v52; // [sp+2BCh] [bp+27Ch]
  unsigned int v53; // [sp+2CCh] [bp+28Ch]
  uint8_t v54[1204]; // [sp+2D0h] [bp+290h] BYREF

  v11 = off_10A4B4;
  v13 = ((uint32_t *)(uintptr_t)off_10A468)[1];
  v14 = ((uint32_t *)(uintptr_t)off_10A468)[2];
  v45[0] = ((uint32_t *)(uintptr_t)off_10A468)[0];
  v45[1] = v13;
  v45[2] = v14;
  v15 = flt_10A46C;
  v42 = v45;
  *(uint32_t *)(a5 + 4 * a4) = 1;
  v44 = (unsigned int *)(a2 - 4);
  v40 = 1;
  v43 = (int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = v44[1];
    ++v44;
    v20 = (uint8_t)v17;
    if ( !v19 )
    {
      sub_12ECD0(1, "===========table[%d]===========\n", v17);
      sub_12ECD0(1, "table %d dont need cal.\n", v17);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      sub_12ECD0(1, a24gTable1DontN);
      goto LABEL_29;
    }
    sub_12ECD0(1, "===========table[%d]===========\n", v17);
    v21 = *v44;
    v52 = 0;
    sub_105ABC(v21, (int)a2a, a4);
    sub_12ECD0(1, "table %d cal %d times.\n", v17, v52);
    v38 = *v42;
    if ( v52 <= 0 )
      goto LABEL_27;
    a1a = v17;
    v39 = 0;
    v22 = &v51;
    do
    {
      v23 = *((uint32_t *)v22 + 16);
      while ( !*a1 )
        sub_100644(1);
      sub_12ECD0(1, aStDpdCal);
      sub_105BA0((int)a2a, (int)v54, v20, v23, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109FF0(v23, a2a, (int)v54, v20, 0, a4, a6, a7, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      sub_12ECD0(1, aDpdCalEnd);
      while ( !a1[1] )
        sub_100644(1);
      v24 = flt_10A484;
      sub_12ECD0(1, aStDpdVerify);
      sub_105BA0((int)a2a, (int)v54, v20, v23, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109FF0(v23, a2a, (int)v54, v20, 1, a4, a6, 0, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      sub_12ECD0(1, aDpdCalEnd);
      sub_12ECD0(1, aDefaultDpdCal);
      sub_12ECD0(1, "am*1000000:%6d  %d\n", (int)(float)(v47 * v24), (int)(float)(v48 * v24));
      sub_12ECD0(1, "ph*1000000:%6d  %d\n", (int)(float)(v49 * v24), (int)(float)(v50 * v24));
      v25 = v47 / v48;
      v26 = v49 / v50;
      if ( v23 == 11 )
      {
        v27 = 3.0;
        v29 = 3.0;
        v28 = 30000;
      }
      else if ( (unsigned int)(v23 - 12) <= 1 )
      {
        v29 = flt_10A73C;
        v28 = 11000;
        v27 = 3.0;
      }
      else if ( v23 == 14 )
      {
        v29 = flt_10A740;
        v28 = 13000;
        v27 = 3.0;
      }
      else if ( v23 <= 7 )
      {
        v27 = v15;
        v29 = v15;
        v28 = 10010;
      }
      else
      {
        v27 = flt_10A494;
        v28 = 11000;
        v29 = flt_10A494;
      }
      v30 = flt_10A498;
      sub_12ECD0(1, "am_compare_thr * 10000 = %6d  ", v28);
      sub_12ECD0(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
      v31 = (int)(float)(v25 * v30);
      sub_12ECD0(1, "am_compare     * 10000 = %6d  ", v31);
      sub_12ECD0(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
      sub_12ECD0(1, "verify_ph_var_sum * 10000 = %6d\n", (int)(float)(v49 * v30));
      if ( v29 >= v25 )
      {
        v32 = v53;
        if ( *(float *)&v53 < 2.0 )
          goto LABEL_19;
        *(uint32_t *)v22 = 0;
        *((uint32_t *)v22 + 8) = 0;
        sub_12ECD0(1, "am_compare_thr * 10000 = %6d  ", v28);
        sub_12ECD0(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
        sub_12ECD0(1, "am_compare     * 10000 = %6d  ", (int)(float)(v25 * v30));
        sub_12ECD0(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
        sub_12ECD0(1, "table[%d] dpd cal is not good, ana_index %x use default.\n", a1a, v23);
        if ( v23 <= 10 && a1a == 1 )
        {
          v40 = 0;
          sub_12EA88("table 1 index %x dont use dpd\n", v23);
          *(uint32_t *)v22 = 1;
          *((uint32_t *)v22 + 8) = 1;
        }
      }
      else
      {
        if ( v27 < v26 )
        {
          v32 = v53;
LABEL_19:
          *(uint32_t *)v22 = 1;
          *((uint32_t *)v22 + 8) = 1;
          if ( v23 <= 8
            && v27 > v26
            && (v33 = sub_1429F8(v32), sub_142FC8(v33, *(uint64_t *)&dword_10A460))
            && a1a == 1 )
          {
            sub_12ECD0(1, "am_compare_thr * 10000 = %6d  ", v28);
            sub_12ECD0(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            sub_12ECD0(1, "am_compare     * 10000 = %6d  ", v31);
            sub_12ECD0(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            sub_12ECD0(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(float *)&v53 * flt_10A758));
            sub_12ECD0(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            v40 = 0;
          }
          else
          {
            sub_12ECD0(1, "table[%d] dpd cal success, ana_index %x can be used.\n", a1a, v23);
            v40 = 1;
          }
          goto LABEL_24;
        }
        v32 = v53;
        if ( *(float *)&v53 < 2.0 )
          goto LABEL_19;
        *(uint32_t *)v22 = 1;
        *((uint32_t *)v22 + 8) = 0;
        sub_12ECD0(1, "table[%d] dpd cal success, ph deviation is small, ana_index %x can be used.\n", a1a, v23);
        if ( v23 <= 8 && a1a == 1 )
        {
          if ( *(float *)&v53 > 2.0 )
          {
            sub_12ECD0(1, "am_compare_thr * 10000 = %6d  ", v28);
            sub_12ECD0(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            sub_12ECD0(1, "am_compare     * 10000 = %6d  ", v31);
            sub_12ECD0(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            sub_12ECD0(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(float *)&v53 * v30));
            sub_12ECD0(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            v40 = 0;
            sub_12ECD0(1, "table 1 index %x dont use dpd\n", v23);
          }
          else
          {
            v40 = 1;
          }
        }
        else
        {
          v40 = 1;
        }
      }
LABEL_24:
      v38 &= *(uint32_t *)v22;
      v34 = *v43 & v40;
      v35 = v52 <= ++v39;
      *v42 = v38;
      v22 += 4;
      *v43 = v34;
    }
    while ( !v35 );
    v17 = a1a;
LABEL_27:
    *v44 = *v44 & 0xFFFEFFFF | (v38 << 16);
LABEL_28:
    if ( v20 != 2 )
    {
LABEL_29:
      ++v17;
      ++v42;
      continue;
    }
    break;
  }
  while ( !a1[2] )
    sub_100644(1);
  result = sub_12ECD0(1, aDpdUse);
  v37 = off_10A748;
  *(uint32_t *)off_10A748 &= ~0x200u;
  *v37 |= 0x200u;
  *v37 &= ~0x200u;
  return result;
}
