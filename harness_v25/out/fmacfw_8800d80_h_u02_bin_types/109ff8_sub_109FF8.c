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

extern uint32_t off_10A374;
extern uint32_t dword_10A328;
extern uint32_t dword_10A60C;
extern uint32_t dword_10A610;
extern uint32_t dword_10A614;
extern uint32_t dword_10A330;
extern uint32_t dword_10A334;
extern uint32_t dword_10A338;
extern uint32_t dword_10A33C;
extern uint32_t dword_10A340;
extern uint32_t dword_10A348;
extern uint32_t dword_10A34C;
extern uint32_t dword_10A350;
extern uint32_t dword_10A35C;
extern uint32_t dword_10A360;
extern uint32_t dword_10A364;
extern uint32_t dword_10A368;
extern uint32_t dword_10A36C;
extern uint32_t dword_10A5E0;
extern uint32_t dword_10A5E4;
extern uint32_t dword_10A5E8;
extern uint32_t dword_10A5EC;
extern uint32_t dword_10A5F0;
extern uint32_t dword_10A5F4;
extern uint32_t dword_10A320;
extern uint32_t dword_10A324;
extern uint32_t dword_10A61C;
extern uint32_t dword_10A620;
extern uint32_t dword_10A370;
extern uint32_t dword_10A5F8;
extern uint32_t dword_10A604;
extern uint32_t off_10A608;

// sub_109FF8 @ 0x109ff8, size 1512 bytes
int  sub_109FF8(
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
        uint64_t *a11)
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
  int v24; // r1
  int v25; // r1
  float v26; // s21
  float v27; // s22
  float v28; // s17
  float v29; // s23
  float v30; // s15
  uint64_t v31; // r0
  int v32; // r3
  int v33; // cc
  int v34; // r1
  int v35; // r2
  int v36; // r1
  int result; // r0
  uint32_t *v38; // r3
  int v39; // [sp+20h] [bp-20h]
  int v40; // [sp+24h] [bp-1Ch]
  int v41; // [sp+2Ch] [bp-14h]
  int v42; // [sp+30h] [bp-10h]
  int *v43; // [sp+34h] [bp-Ch]
  int *v44; // [sp+38h] [bp-8h]
  unsigned int *v45; // [sp+3Ch] [bp-4h]
  uint32_t v46[3]; // [sp+40h] [bp+0h] BYREF
  int v47[132]; // [sp+4Ch] [bp+Ch] BYREF
  char v48; // [sp+25Ch] [bp+21Ch] BYREF
  int v49; // [sp+2BCh] [bp+27Ch]
  float v50; // [sp+2CCh] [bp+28Ch]
  uint8_t v51[1204]; // [sp+2D0h] [bp+290h] BYREF

  v11 = off_10A374;
  v13 = *(uint32_t *)(dword_10A328 + 4);
  v14 = *(uint32_t *)(dword_10A328 + 8);
  v46[0] = *(uint32_t *)dword_10A328;
  v46[1] = v13;
  v46[2] = v14;
  v15 = flt_10A32C;
  v43 = v46;
  *(uint32_t *)(a5 + 4 * a4) = 1;
  v45 = (unsigned int *)(a2 - 4);
  v41 = 1;
  v44 = (int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = v45[1];
    ++v45;
    v20 = (uint8_t)v17;
    if ( !v19 )
    {
      sub_12EB90(1, dword_10A60C);
      sub_12EB90(1, dword_10A610);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      sub_12EB90(1, dword_10A614);
      goto LABEL_29;
    }
    sub_12EB90(1, dword_10A330);
    v21 = *v45;
    v49 = 0;
    sub_1059A4(v21, (int)v47, a4);
    sub_12EB90(1, dword_10A334);
    v39 = *v43;
    if ( v49 <= 0 )
      goto LABEL_27;
    v42 = v17;
    v40 = 0;
    v22 = &v48;
    do
    {
      v23 = *((uint32_t *)v22 + 16);
      while ( !*a1 )
        sub_100644(1);
      sub_12EB90(1, dword_10A338);
      sub_105A88((int)v47, (int)v51, v20, v23, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109EB0(v23, v47, (int)v51, v20, 0, a4, a6, a7, a9, a10, a11);
      v24 = dword_10A33C;
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      sub_12EB90(1, v24);
      while ( !a1[1] )
        sub_100644(1);
      sub_12EB90(1, dword_10A340);
      sub_105A88((int)v47, (int)v51, v20, v23, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      sub_109EB0(v23, v47, (int)v51, v20, 1, a4, a6, 0, a9, a10, a11);
      v25 = dword_10A33C;
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      sub_12EB90(1, v25);
      sub_12EB90(1, dword_10A348);
      sub_12EB90(1, dword_10A34C);
      sub_12EB90(1, dword_10A350);
      v26 = *(float *)&v47[128] / *(float *)&v47[129];
      v27 = *(float *)&v47[130] / *(float *)&v47[131];
      if ( v23 == 11 )
      {
        v28 = 3.0;
        v29 = 3.0;
      }
      else if ( (unsigned int)(v23 - 12) <= 1 )
      {
        v29 = flt_10A5FC;
        v28 = 3.0;
      }
      else if ( v23 == 14 )
      {
        v29 = flt_10A600;
        v28 = 3.0;
      }
      else if ( v23 <= 7 )
      {
        v28 = v15;
        v29 = v15;
      }
      else
      {
        v28 = flt_10A354;
        v29 = flt_10A354;
      }
      sub_12EB90(1, dword_10A35C);
      sub_12EB90(1, dword_10A360);
      sub_12EB90(1, dword_10A364);
      sub_12EB90(1, dword_10A368);
      sub_12EB90(1, dword_10A36C);
      if ( v29 >= v26 )
      {
        v30 = v50;
        if ( v50 < 2.0 )
          goto LABEL_19;
        v34 = dword_10A5E0;
        *(uint32_t *)v22 = 0;
        *((uint32_t *)v22 + 8) = 0;
        sub_12EB90(1, v34);
        sub_12EB90(1, dword_10A5E4);
        sub_12EB90(1, dword_10A5E8);
        sub_12EB90(1, dword_10A5EC);
        sub_12EB90(1, dword_10A5F0);
        if ( v23 <= 10 && v42 == 1 )
        {
          v41 = 0;
          sub_12E948(dword_10A5F4, v23, v35);
          *(uint32_t *)v22 = 1;
          *((uint32_t *)v22 + 8) = 1;
        }
      }
      else
      {
        if ( v28 < v27 )
        {
          v30 = v50;
LABEL_19:
          *(uint32_t *)v22 = 1;
          *((uint32_t *)v22 + 8) = 1;
          if ( v23 <= 8
            && v28 > v27
            && (v31 = sub_1428B8(LODWORD(v30)), sub_142E88(v31, HIDWORD(v31), dword_10A320, dword_10A324))
            && v42 == 1 )
          {
            sub_12EB90(1, dword_10A5E0);
            sub_12EB90(1, dword_10A5E4);
            sub_12EB90(1, dword_10A5E8);
            sub_12EB90(1, dword_10A5EC);
            sub_12EB90(1, dword_10A61C);
            sub_12EB90(1, dword_10A620);
            v41 = 0;
          }
          else
          {
            sub_12EB90(1, dword_10A370);
            v41 = 1;
          }
          goto LABEL_24;
        }
        v30 = v50;
        if ( v50 < 2.0 )
          goto LABEL_19;
        v36 = dword_10A5F8;
        *(uint32_t *)v22 = 1;
        *((uint32_t *)v22 + 8) = 0;
        sub_12EB90(1, v36);
        if ( v23 <= 8 && v42 == 1 )
        {
          if ( v50 > 2.0 )
          {
            sub_12EB90(1, dword_10A5E0);
            sub_12EB90(1, dword_10A5E4);
            sub_12EB90(1, dword_10A5E8);
            sub_12EB90(1, dword_10A5EC);
            sub_12EB90(1, dword_10A61C);
            sub_12EB90(1, dword_10A620);
            v41 = 0;
            sub_12EB90(1, dword_10A5F4);
          }
          else
          {
            v41 = 1;
          }
        }
        else
        {
          v41 = 1;
        }
      }
LABEL_24:
      v39 &= *(uint32_t *)v22;
      v32 = *v44 & v41;
      v33 = v49 <= ++v40;
      *v43 = v39;
      v22 += 4;
      *v44 = v32;
    }
    while ( !v33 );
    v17 = v42;
LABEL_27:
    *v45 = *v45 & 0xFFFEFFFF | (v39 << 16);
LABEL_28:
    if ( v20 != 2 )
    {
LABEL_29:
      ++v17;
      ++v43;
      continue;
    }
    break;
  }
  while ( !a1[2] )
    sub_100644(1);
  result = sub_12EB90(1, dword_10A604);
  v38 = off_10A608;
  *(uint32_t *)off_10A608 &= ~0x200u;
  *v38 |= 0x200u;
  *v38 &= ~0x200u;
  return result;
}

