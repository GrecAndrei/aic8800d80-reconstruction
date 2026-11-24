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


extern uint32_t dword_10B354;
extern uint32_t dword_10B358;
extern uint32_t dword_10B35C;
extern uint32_t dword_10B360;
extern uint32_t dword_10B378;
extern uint32_t dword_10B380;
extern uint32_t off_10B33C;
extern uint32_t off_10B340;
extern uint32_t off_10B364;
extern uint32_t off_10B374;
extern uint32_t off_10B428;

// periph_base_setup @ 0x10b010, size 1046 bytes
int  periph_base_setup(int a1, uint8_t *a2, int a3)
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
  int v46; // s16
  int i; // r8
  int v48; // r10
  int v49; // r7
  int v50; // r5
  int v51; // r6
  int v52; // lr
  int v53; // r10
  int v54; // r3
  unsigned int *v55; // r1
  int v56; // r12
  int v57; // r5
  unsigned int *v58; // r11
  unsigned int v59; // r2
  unsigned int v60; // t1
  int v61; // r6
  uint32_t *v62; // r0
  int v63; // r3
  int v64; // r0
  int v65; // cc
  int v66; // r3
  int v67; // r0
  unsigned int a5; // [sp+0h] [bp-1CCh]
  int v69; // [sp+10h] [bp-1BCh]
  int v70; // [sp+14h] [bp-1B8h]
  unsigned int *a2a; // [sp+18h] [bp-1B4h]
  uint8_t *v72; // [sp+1Ch] [bp-1B0h]
  int *v73; // [sp+20h] [bp-1ACh]
  int v74; // [sp+24h] [bp-1A8h]
  int v77; // [sp+34h] [bp-198h]
  uint16_t a1a[2]; // [sp+38h] [bp-194h] BYREF
  int v79; // [sp+3Ch] [bp-190h]
  uint16_t v80; // [sp+40h] [bp-18Ch]
  uint32_t v81[14]; // [sp+44h] [bp-188h] BYREF
  int v82; // [sp+7Ch] [bp-150h]
  uint8_t v83[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v84[196]; // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10B354;
  v4 = dword_10B35C;
  v5 = dword_10B380;
  event_dispatch(aMiscCalibLoftC);
  v7 = *(uint32_t *)off_10B33C;
  v8 = *(uint32_t *)off_10B33C & 0xFFFFFFFE;
  *(uint32_t *)a1a = 0;
  v79 = 0;
  v80 = 0;
  *(uint32_t *)off_10B33C = v8;
  v74 = v7 & 1;
  set_wakeup_trigger(0);
  v9 = dword_10B358;
  v10 = dword_10B360;
  v11 = 0;
  v12 = (int *)v84;
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
    v43 = (int *)&v83[64 * v11];
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
  v18 = off_10B340;
  set_wakeup_polarity(0);
  check_status_bits(1, aTrigger);
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  event_dispatch(aLoftStart);
  check_status_bits(1, aLoftCal);
  v19 = v18;
  v69 = a3 + 56;
  do
  {
    v20 = *(uint8_t *)(a3 + 5);
    v21 = *(uint16_t *)(a3 + 2);
    *v19 |= 0x400u;
    *v19 &= ~0x400u;
    if ( v20 == 1 )
    {
      check_status_bits(1, "**************************loft  freq= [%d] **************************\n", v21);
      if ( v21 > 0x1388 )
      {
        LOBYTE(v80) = 0;
        LOBYTE(a1a[0]) = 1;
        a1a[1] = v21;
        LOWORD(v79) = v21;
        HIWORD(v79) = v21;
        rf_enable(a1a, 0);
        v67 = is_magic_value(v21);
        v73 = &((uint32_t *)(uintptr_t)off_10B428)[96 * v67];
        a2a = (unsigned int *)(a1 + 1264 * (uint8_t)(v67 + 1));
        v46 = (uint8_t)(v67 + 1);
        v72 = &a2[v46];
      }
      else
      {
        LOWORD(v79) = v21;
        LOBYTE(a1a[0]) = 0;
        LOBYTE(v80) = 0;
        rf_enable(a1a, 0);
        v73 = (int *)off_10B374;
        v72 = a2;
        v46 = 0;
        a2a = (unsigned int *)a1;
        v20 = 0;
      }
      periph_init_multi((int)(a2a + 292), a2a, 255, 0, 0, dword_10B378, 0);
      timer_delay(10000);
      v77 = a3;
      *v72 = 1;
      v70 = v20;
      for ( i = 0; i != 3; ++i )
      {
        if ( !a2a[i] )
          check_status_bits(1, "table [%d] dont need change\n", i);
        if ( v70 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v48 = 1;
            else
              v48 = 2;
            if ( i == 1 )
              v49 = 8;
            else
              v49 = 9;
            if ( i == 1 )
              v50 = 64;
            else
              v50 = 96;
            if ( i == 1 )
              v51 = 32;
            else
              v51 = 64;
          }
          else
          {
            v48 = 0;
            v51 = 0;
            v49 = 9;
            v50 = 32;
          }
        }
        else
        {
          v48 = 2;
          v49 = 0;
          v50 = 96;
          v51 = 32;
        }
        a5 = (a2a[v48] >> 17) & 1;
        *v72 &= (a2a[v48] & 0x20000) != 0;
        check_status_bits(1, "ch[%d] loft_ok[%d]=%d\n", v46, i, a5);
        mac_event_init(a2a[v48], v81);
        if ( v51 < v50 )
        {
          v52 = v82;
          v53 = v81[10];
          v54 = (int)&v73[v50 - 1];
          v55 = (unsigned int *)&v73[v51 - 1];
          v56 = v82 - 1;
          v57 = 0;
          v58 = (unsigned int *)v54;
          do
          {
            v60 = v55[1];
            ++v55;
            v59 = v60;
            v61 = (v60 >> 8) & 0xF;
            if ( v49 <= v61 )
            {
              if ( v52 == 1 )
              {
                v57 = v53 == v61;
              }
              else if ( v56 > 0 )
              {
                v57 = 0;
                v62 = v81;
                v63 = 1;
                if ( v61 < v53 )
                {
LABEL_43:
                  v63 = v57 + 1;
                  if ( v70 != 1 )
                    v57 = 1;
                  goto LABEL_45;
                }
                while ( 1 )
                {
                  if ( v62[11] > v61 )
                    v57 = v63;
                  else
                    v57 += 2;
LABEL_45:
                  v64 = v63;
                  v65 = v56 <= v63;
                  v66 = v63 + 10;
                  if ( v65 )
                    break;
                  v57 = v64;
                  v65 = v61 < v81[v66];
                  v62 = &v81[v64];
                  v63 = v57 + 1;
                  if ( v65 )
                    goto LABEL_43;
                }
              }
              *v55 = v59 & 0xE7FFFFFF | (v57 << 27);
            }
          }
          while ( v58 != v55 );
        }
      }
      a3 = v77;
    }
    a3 += 8;
  }
  while ( v69 != a3 );
  v22 = dword_10B354;
  v23 = dword_10B358;
  v24 = dword_10B35C;
  v25 = dword_10B380;
  event_dispatch(aLoftEnd);
  set_wakeup_trigger(0);
  v26 = dword_10B360;
  v27 = (int *)v84;
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
    v38 = (int *)&v83[64 * v28];
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
  set_wakeup_polarity(0);
  v34 = off_10B364;
  *(uint32_t *)off_10B33C = *(uint32_t *)off_10B33C & 0xFFFFFFFE | v74;
  check_status_bits(1, "tia_aux_gbit000=%d\n", (*v34 >> 21) & 7);
  return event_dispatch(aMiscLoftCalibS);
}
