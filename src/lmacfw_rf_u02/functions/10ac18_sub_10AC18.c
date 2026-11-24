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


extern uint32_t dword_10AF6C;
extern uint32_t dword_10AF70;
extern uint32_t dword_10AF74;
extern uint32_t dword_10AF78;
extern uint32_t dword_10AF90;
extern uint32_t dword_10AF98;
extern uint32_t off_10AF50;
extern uint32_t off_10AF54;
extern uint32_t off_10AF64;
extern uint32_t off_10AF7C;
extern uint32_t off_10AF8C;
extern uint32_t off_10B040;

// configure_dma_regs @ 0x10ac18, size 1062 bytes
int  configure_dma_regs(int a1, uint8_t *a2, int a3)
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
  int v19; // r3
  uint32_t *v20; // r9
  int v21; // r10
  unsigned int v22; // r4
  int v23; // r5
  int v24; // r4
  int v25; // r7
  int v26; // r9
  int v27; // r0
  int *v28; // r10
  int v29; // r1
  int v30; // r12
  unsigned int *v31; // r2
  unsigned int *v32; // r8
  int *v33; // r12
  int v34; // t1
  uint32_t *v35; // r0
  int v37; // r8
  unsigned int *v38; // r2
  int *v39; // lr
  unsigned int *v40; // r8
  int v41; // t1
  int v42; // r6
  unsigned int *v43; // r1
  int *v44; // r5
  unsigned int *v45; // r6
  unsigned int v46; // r3
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
  int a4; // [sp+10h] [bp-1BCh]
  int v71; // [sp+14h] [bp-1B8h]
  unsigned int *a2a; // [sp+18h] [bp-1B4h]
  uint8_t *v73; // [sp+1Ch] [bp-1B0h]
  int *v74; // [sp+20h] [bp-1ACh]
  int v75; // [sp+24h] [bp-1A8h]
  int v78; // [sp+34h] [bp-198h]
  uint8_t a1a[4]; // [sp+38h] [bp-194h] BYREF
  int v80; // [sp+3Ch] [bp-190h]
  uint16_t v81; // [sp+40h] [bp-18Ch]
  uint32_t v82[14]; // [sp+44h] [bp-188h] BYREF
  int v83; // [sp+7Ch] [bp-150h]
  uint8_t v84[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v85[196]; // [sp+108h] [bp-C4h] BYREF

  v3 = dword_10AF6C;
  v4 = dword_10AF74;
  v5 = dword_10AF98;
  dispatch_event_handler_1(aMiscCalibLoftC);
  v7 = *(uint32_t *)off_10AF50;
  v8 = *(uint32_t *)off_10AF50 & 0xFFFFFFFE;
  *(uint32_t *)a1a = 0;
  v80 = 0;
  v81 = 0;
  *(uint32_t *)off_10AF50 = v8;
  v75 = v7 & 1;
  gpio_set_pin(0);
  v9 = dword_10AF70;
  v10 = dword_10AF78;
  v11 = 0;
  v12 = (int *)v85;
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
      v42 = v5;
    }
    else
    {
      v13 = v3;
      v42 = v9;
    }
    v43 = (unsigned int *)(v42 + 4);
    v44 = (int *)&v84[64 * v11];
    v45 = (unsigned int *)(v42 + 516);
    do
    {
      v46 = *v43;
      *v43 &= 0xFFF1FFFF;
      v43 += 8;
      *v44++ = (v46 >> 17) & 7;
    }
    while ( v43 != v45 );
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
  v18 = off_10AF54;
  gpio_clear_pin(0);
  check_interrupt_flag(1, aTrigger);
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  dispatch_event_handler_1(aLoftStart);
  check_interrupt_flag(1, aLoftCal);
  if ( (*(uint32_t *)off_10AF64 & 2) != 0 )
    v19 = 8;
  else
    v19 = 56;
  v20 = v18;
  a4 = v19 + a3;
  do
  {
    v21 = *(uint8_t *)(a3 + 5);
    v22 = *(uint16_t *)(a3 + 2);
    *v20 |= 0x400u;
    *v20 &= ~0x400u;
    if ( v21 == 1 )
    {
      check_interrupt_flag(1, "**************************loft  freq= [%d] **************************\n", v22);
      if ( v22 > 0x1388 )
      {
        LOBYTE(v81) = 0;
        a1a[0] = 1;
        *(uint16_t *)&a1a[2] = v22;
        LOWORD(v80) = v22;
        HIWORD(v80) = v22;
        tx_set_power(a1a, 0);
        v68 = rf_check_freq(v22);
        v74 = &((uint32_t *)(uintptr_t)off_10B040)[96 * v68];
        a2a = (unsigned int *)(a1 + 1264 * (uint8_t)(v68 + 1));
        v47 = (uint8_t)(v68 + 1);
        v73 = &a2[v47];
      }
      else
      {
        LOWORD(v80) = v22;
        a1a[0] = 0;
        LOBYTE(v81) = 0;
        tx_set_power(a1a, 0);
        v74 = (int *)off_10AF8C;
        v73 = a2;
        v47 = 0;
        a2a = (unsigned int *)a1;
        v21 = 0;
      }
      rf_transmit_packet((int)(a2a + 292), a2a, 255, 0, 0, dword_10AF90, 0);
      write_timer_reg(10000);
      v78 = a3;
      *v73 = 1;
      v71 = v21;
      for ( i = 0; i != 3; ++i )
      {
        if ( !a2a[i] )
          check_interrupt_flag(1, "table [%d] dont need change\n", i);
        if ( v71 == 1 )
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
        a5 = (a2a[v49] >> 17) & 1;
        *v73 &= (a2a[v49] & 0x20000) != 0;
        check_interrupt_flag(1, "ch[%d] loft_ok[%d]=%d\n", v47, i, a5);
        mac_get_params(a2a[v49], v82);
        if ( v52 < v51 )
        {
          v53 = v83;
          v54 = v82[10];
          v55 = (int)&v74[v51 - 1];
          v56 = (unsigned int *)&v74[v52 - 1];
          v57 = v83 - 1;
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
                v63 = v82;
                v64 = 1;
                if ( v62 < v54 )
                {
LABEL_46:
                  v64 = v58 + 1;
                  if ( v71 != 1 )
                    v58 = 1;
                  goto LABEL_48;
                }
                while ( 1 )
                {
                  if ( v63[11] > v62 )
                    v58 = v64;
                  else
                    v58 += 2;
LABEL_48:
                  v65 = v64;
                  v66 = v57 <= v64;
                  v67 = v64 + 10;
                  if ( v66 )
                    break;
                  v58 = v65;
                  v66 = v62 < v82[v67];
                  v63 = &v82[v65];
                  v64 = v58 + 1;
                  if ( v66 )
                    goto LABEL_46;
                }
              }
              *v56 = v60 & 0xE7FFFFFF | (v58 << 27);
            }
          }
          while ( v59 != v56 );
        }
      }
      a3 = v78;
    }
    a3 += 8;
  }
  while ( a4 != a3 );
  v23 = dword_10AF6C;
  v24 = dword_10AF70;
  v25 = dword_10AF74;
  v26 = dword_10AF98;
  dispatch_event_handler_1(aLoftEnd);
  gpio_set_pin(0);
  v27 = dword_10AF78;
  v28 = (int *)v85;
  v29 = 0;
  while ( 2 )
  {
    if ( v29 )
    {
      if ( v29 != 1 )
      {
        v30 = v27;
        goto LABEL_18;
      }
      v30 = v25;
      v37 = v26;
    }
    else
    {
      v30 = v23;
      v37 = v24;
    }
    v38 = (unsigned int *)(v37 + 4);
    v39 = (int *)&v84[64 * v29];
    v40 = (unsigned int *)(v37 + 484);
    do
    {
      v41 = *v39++;
      *v38 = *v38 & 0xFFF1FFFF | (v41 << 17);
      v38 += 8;
    }
    while ( v40 != v38 );
LABEL_18:
    v31 = (unsigned int *)(v30 + 4);
    v32 = (unsigned int *)(v30 + 484);
    v33 = v28;
    do
    {
      v34 = *v33++;
      *v31 = *v31 & 0xFFF1FFFF | (v34 << 17);
      v31 += 8;
    }
    while ( v32 != v31 );
    ++v29;
    v28 += 16;
    if ( v29 != 3 )
      continue;
    break;
  }
  gpio_clear_pin(0);
  v35 = off_10AF7C;
  *(uint32_t *)off_10AF50 = *(uint32_t *)off_10AF50 & 0xFFFFFFFE | v75;
  check_interrupt_flag(1, "tia_aux_gbit000=%d\n", (*v35 >> 21) & 7);
  return dispatch_event_handler_1(aMiscLoftCalibS);
}
