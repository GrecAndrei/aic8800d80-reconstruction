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


extern uint32_t dword_10B214;
extern uint32_t dword_10B218;
extern uint32_t dword_10B21C;
extern uint32_t dword_10B220;
extern uint32_t dword_10B238;
extern uint32_t dword_10B240;
extern uint32_t off_10B1FC;
extern uint32_t off_10B200;
extern uint32_t off_10B224;
extern uint32_t off_10B234;
extern uint32_t off_10B2E8;

// rf_iqk_init @ 0x10aed0, size 1046 bytes
int  rf_iqk_init(int a1, uint8_t *a2, int a3)
{
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v7; // r1
  unsigned int v8; // r2
  int v9; // lr
  int v10; // r12
  int v11; // r0
  int *v12; // r2
  int v13; // r4
  unsigned int *v14; // r1
  unsigned int *v15; // r6
  int *v16; // r4
  unsigned int v17; // r3
  uint32_t *v18; // r4
  uint32_t *v19; // r9
  int v20; // r10
  unsigned int v21; // r4
  int v22; // r5
  int v23; // r4
  int v24; // r7
  int v25; // r9
  int v26; // r0
  int *v27; // r10
  int v28; // r1
  int v29; // r12
  unsigned int *v30; // r2
  unsigned int *v31; // r8
  int *v32; // r12
  int v33; // t1
  uint32_t *v34; // r0
  int v36; // r8
  unsigned int *v37; // r2
  int *v38; // lr
  unsigned int *v39; // r8
  int v40; // t1
  int v41; // r6
  unsigned int *v42; // r1
  int *v43; // r5
  unsigned int *v44; // r6
  unsigned int v45; // r3
  int v46; // r2
  int v47; // s16
  int i; // r8
  int v49; // r10
  int v50; // r7
  int v51; // r5
  int v52; // r6
  int v53; // lr
  int v54; // r10
  int v55; // r3
  unsigned int *v56; // r1
  int v57; // r12
  int v58; // r5
  unsigned int *v59; // r11
  unsigned int v60; // r2
  unsigned int v61; // t1
  int v62; // r6
  uint32_t *v63; // r0
  int v64; // r3
  int v65; // r0
  int v66; // cc
  int v67; // r3
  int v68; // r0
  unsigned int a5; // [sp+0h] [bp-1CCh]
  unsigned int a5a; // [sp+0h] [bp-1CCh]
  int a6; // [sp+4h] [bp-1C8h]
  int v72; // [sp+8h] [bp-1C4h]
  int v73; // [sp+10h] [bp-1BCh]
  int v74; // [sp+14h] [bp-1B8h]
  unsigned int *a2a; // [sp+18h] [bp-1B4h]
  uint8_t *v76; // [sp+1Ch] [bp-1B0h]
  int *v77; // [sp+20h] [bp-1ACh]
  int v78; // [sp+24h] [bp-1A8h]
  int v81; // [sp+34h] [bp-198h]
  uint16_t a1a[2]; // [sp+38h] [bp-194h] BYREF
  int v83; // [sp+3Ch] [bp-190h]
  uint16_t v84; // [sp+40h] [bp-18Ch]
  uint32_t v85[14]; // [sp+44h] [bp-188h] BYREF
  int v86; // [sp+7Ch] [bp-150h]
  uint8_t v87[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v88[196]; // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10B214;
  v4 = dword_10B21C;
  v5 = dword_10B240;
  alloc_tx_event(aMiscCalibLoftC);
  v7 = *(uint32_t *)off_10B1FC;
  v8 = *(uint32_t *)off_10B1FC & 0xFFFFFFFE;
  *(uint32_t *)a1a = 0;
  v83 = 0;
  v84 = 0;
  *(uint32_t *)off_10B1FC = v8;
  v78 = v7 & 1;
  rf_clear_control_bit_a(0);
  v9 = dword_10B218;
  v10 = dword_10B220;
  v11 = 0;
  v12 = (int *)v88;
  do
  {
    if ( v11 )
    {
      if ( v11 != 1 )
      {
        v13 = v10;
        goto LABEL_5;
      }
      v13 = v4;
      v41 = v5;
    }
    else
    {
      v13 = v3;
      v41 = v9;
    }
    v42 = (unsigned int *)(v41 + 4);
    v43 = (int *)&v87[64 * v11];
    v44 = (unsigned int *)(v41 + 516);
    do
    {
      v45 = *v42;
      *v42 &= 0xFFF1FFFF;
      v42 += 8;
      *v43++ = (v45 >> 17) & 7;
    }
    while ( v42 != v44 );
LABEL_5:
    v14 = (unsigned int *)(v13 + 4);
    v15 = (unsigned int *)(v13 + 516);
    v16 = v12;
    do
    {
      v17 = *v14;
      *v14 &= 0xFFF1FFFF;
      v14 += 8;
      *v16++ = (v17 >> 17) & 7;
    }
    while ( v15 != v14 );
    ++v11;
    v12 += 16;
  }
  while ( v11 != 3 );
  v18 = off_10B200;
  rf_clear_control_bit_b(0);
  check_feature_flag(1, aTrigger);
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  alloc_tx_event(aLoftStart);
  check_feature_flag(1, aLoftCal);
  v19 = v18;
  v73 = a3 + 56;
  do
  {
    v20 = *(uint8_t *)(a3 + 5);
    v21 = *(uint16_t *)(a3 + 2);
    *v19 |= 0x400u;
    *v19 &= ~0x400u;
    if ( v20 == 1 )
    {
      check_feature_flag(1, "**************************loft  freq= [%d] **************************\n", v21);
      if ( v21 > 0x1388 )
      {
        LOBYTE(v84) = 0;
        LOBYTE(a1a[0]) = 1;
        a1a[1] = v21;
        LOWORD(v83) = v21;
        HIWORD(v83) = v21;
        check_boot_flag(a1a, 0, v46, 5000, a5, a6, v72);
        v68 = check_magic_value(v21);
        v77 = (int *)((char *)off_10B2E8 + 384 * v68);
        a2a = (unsigned int *)(a1 + 1264 * (uint8_t)(v68 + 1));
        v47 = (uint8_t)(v68 + 1);
        v76 = &a2[v47];
      }
      else
      {
        LOWORD(v83) = v21;
        LOBYTE(a1a[0]) = 0;
        LOBYTE(v84) = 0;
        check_boot_flag(a1a, 0, v46, 5000, a5, a6, v72);
        v77 = (int *)off_10B234;
        v76 = a2;
        v47 = 0;
        a2a = (unsigned int *)a1;
        v20 = 0;
      }
      rf_phy_init((int)(a2a + 292), a2a, 255, 0, 0, dword_10B238, 0);
      mmio_read32(10000);
      v81 = a3;
      *v76 = 1;
      v74 = v20;
      for ( i = 0; i != 3; ++i )
      {
        if ( !a2a[i] )
          check_feature_flag(1, "table [%d] dont need change\n", i);
        if ( v74 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v49 = 1;
            else
              v49 = 2;
            if ( i == 1 )
              v50 = 8;
            else
              v50 = 9;
            if ( i == 1 )
              v51 = 64;
            else
              v51 = 96;
            if ( i == 1 )
              v52 = 32;
            else
              v52 = 64;
          }
          else
          {
            v49 = 0;
            v52 = 0;
            v50 = 9;
            v51 = 32;
          }
        }
        else
        {
          v49 = 2;
          v50 = 0;
          v51 = 96;
          v52 = 32;
        }
        a5a = (a2a[v49] >> 17) & 1;
        *v76 &= (a2a[v49] & 0x20000) != 0;
        check_feature_flag(1, "ch[%d] loft_ok[%d]=%d\n", v47, i, a5a);
        dma_chan_init(a2a[v49], v85);
        if ( v52 < v51 )
        {
          v53 = v86;
          v54 = v85[10];
          v55 = (int)&v77[v51 - 1];
          v56 = (unsigned int *)&v77[v52 - 1];
          v57 = v86 - 1;
          v58 = 0;
          v59 = (unsigned int *)v55;
          do
          {
            v61 = v56[1];
            ++v56;
            v60 = v61;
            v62 = (v61 >> 8) & 0xF;
            if ( v50 <= v62 )
            {
              if ( v53 == 1 )
              {
                v58 = v54 == v62;
              }
              else if ( v57 > 0 )
              {
                v58 = 0;
                v63 = v85;
                v64 = 1;
                if ( v62 < v54 )
                {
LABEL_43:
                  v64 = v58 + 1;
                  if ( v74 != 1 )
                    v58 = 1;
                  goto LABEL_45;
                }
                while ( 1 )
                {
                  if ( v63[11] > v62 )
                    v58 = v64;
                  else
                    v58 += 2;
LABEL_45:
                  v65 = v64;
                  v66 = v57 <= v64;
                  v67 = v64 + 10;
                  if ( v66 )
                    break;
                  v58 = v65;
                  v66 = v62 < v85[v67];
                  v63 = &v85[v65];
                  v64 = v58 + 1;
                  if ( v66 )
                    goto LABEL_43;
                }
              }
              *v56 = v60 & 0xE7FFFFFF | (v58 << 27);
            }
          }
          while ( v59 != v56 );
        }
      }
      a3 = v81;
    }
    a3 += 8;
  }
  while ( v73 != a3 );
  v22 = dword_10B214;
  v23 = dword_10B218;
  v24 = dword_10B21C;
  v25 = dword_10B240;
  alloc_tx_event(aLoftEnd);
  rf_clear_control_bit_a(0);
  v26 = dword_10B220;
  v27 = (int *)v88;
  v28 = 0;
  while ( 2 )
  {
    if ( v28 )
    {
      if ( v28 != 1 )
      {
        v29 = v26;
        goto LABEL_15;
      }
      v29 = v24;
      v36 = v25;
    }
    else
    {
      v29 = v22;
      v36 = v23;
    }
    v37 = (unsigned int *)(v36 + 4);
    v38 = (int *)&v87[64 * v28];
    v39 = (unsigned int *)(v36 + 484);
    do
    {
      v40 = *v38++;
      *v37 = *v37 & 0xFFF1FFFF | (v40 << 17);
      v37 += 8;
    }
    while ( v39 != v37 );
LABEL_15:
    v30 = (unsigned int *)(v29 + 4);
    v31 = (unsigned int *)(v29 + 484);
    v32 = v27;
    do
    {
      v33 = *v32++;
      *v30 = *v30 & 0xFFF1FFFF | (v33 << 17);
      v30 += 8;
    }
    while ( v31 != v30 );
    ++v28;
    v27 += 16;
    if ( v28 != 3 )
      continue;
    break;
  }
  rf_clear_control_bit_b(0);
  v34 = off_10B224;
  *(uint32_t *)off_10B1FC = *(uint32_t *)off_10B1FC & 0xFFFFFFFE | v78;
  check_feature_flag(1, "tia_aux_gbit000=%d\n", (*v34 >> 21) & 7);
  return alloc_tx_event(aMiscLoftCalibS);
}
