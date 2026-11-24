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


extern uint32_t dword_120EDC;
extern uint32_t dword_120EE0;
extern uint32_t dword_120EE4;
extern uint32_t dword_120EE8;
extern uint32_t dword_120EEC;
extern uint32_t dword_120EF0;
extern uint32_t dword_120EF4;
extern uint32_t dword_120EF8;
extern uint32_t dword_120EFC;
extern uint32_t dword_120F00;
extern uint32_t dword_120F08;
extern uint32_t dword_120F0C;
extern uint32_t dword_120F10;
extern uint32_t dword_120F14;
extern uint32_t dword_120F1C;
extern uint32_t dword_120F24;
extern uint32_t dword_120F34;
extern uint32_t dword_120F4C;
extern uint32_t dword_120F54;
extern uint32_t dword_120F5C;
extern uint32_t dword_121078;
extern uint32_t dword_121080;
extern uint32_t dword_121084;
extern uint32_t dword_121088;
extern uint32_t dword_12108C;
extern uint32_t dword_121090;
extern uint32_t dword_121094;
extern uint32_t dword_121098;
extern uint32_t dword_12109C;
extern uint32_t dword_1210A0;
extern uint32_t dword_1210B0;
extern uint32_t off_120F18;

// wait_for_hw_flag @ 0x120bd0, size 1192 bytes
int wait_for_hw_flag()
{
  unsigned int v0; // r10
  int v1; // r8
  int result; // r0
  unsigned int v3; // r4
  int v4; // r1
  uint32_t *v5; // r7
  uint32_t *v6; // r5
  uint32_t *v7; // r9
  int v8; // r3
  volatile unsigned int v9; // r2
  int v10; // r1
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r6
  unsigned int v14; // r5
  unsigned int v15; // r6
  int v16; // r1
  int v17; // r3
  volatile unsigned int v18; // r2
  char v19; // r5
  uint8_t **v20; // r7
  uint8_t *v21; // r1
  uint32_t *v22; // r3
  int v23; // r3
  uint16_t **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r1
  char v29; // r1
  volatile unsigned int v30; // r3
  uint32_t *v31; // r2
  uint32_t *v32; // r7
  uint32_t *v33; // r1
  unsigned int v34; // r3
  uint32_t *v35; // r9
  uint32_t *v36; // r5
  int v37; // r2
  volatile unsigned int v38; // r6
  int v39; // r2
  unsigned int v40; // r3
  uint32_t *v41; // r6
  volatile unsigned int v42; // r3
  int v43; // r3
  int v44; // r2
  uint32_t *v45; // r2
  volatile unsigned int v46; // r8
  unsigned int v47; // r1
  int v48; // r5
  uint64_t v49; // [sp+0h] [bp-Ch]
  int v50; // [sp+0h] [bp-Ch]
  int v51; // [sp+0h] [bp-Ch]

  v0 = dword_120F54;
  v1 = *(uint32_t *)(dword_120F54 + 0x20);
  result = unknown_func_12d14c(0x40000);
  if ( v1 )
  {
    v3 = dword_120EDC;
    v4 = *(uint8_t *)(dword_120EDC + 0x1E);
LABEL_3:
    v5 = (uint32_t *)dword_120EE0;
    v6 = (uint32_t *)dword_120EE4;
    v7 = (uint32_t *)dword_120F5C;
    while ( 1 )
    {
      if ( !v4 )
        return result;
      if ( (v4 & 8) != 0 )
      {
        v8 = *(uint32_t *)dword_120EE8;
        *(uint32_t *)dword_120EEC = 0x80000000;
        v9 = (*(volatile uint32_t *)0x40501010u);
        if ( (int)(*(uint32_t *)(v8 + 4) + *(uint32_t *)(v1 + 120) - v9) < 0
          && !rf_channel_get(*(uint8_t *)(v1 + 116), 0, 0) )
        {
          v30 = (*(volatile uint32_t *)0x40501010u);
          *(uint32_t *)(v1 + 120) = v30;
        }
        v4 = *(uint8_t *)(v3 + 0x1E) & 0xF7;
        *(uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 4) != 0 )
      {
        check_status_bits(2, (const char *)dword_120F14);
        v24 = (uint16_t **)dword_120EF8;
        v25 = *(uint32_t *)(v3 + 4);
        *v5 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *(uint32_t *)(v3 + 4) = v27;
        if ( v26 < 0 && *(uint32_t *)dword_120F24 << 28 )
        {
          call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_1, 472);
          v27 = *(uint32_t *)(v3 + 4);
        }
        v28 = off_120F18;
        *(uint32_t *)dword_120F1C = v27 | *(uint32_t *)v3;
        link_get_connection_info(*(uint8_t *)(v1 + 107), v28, v1);
        v29 = *(uint8_t *)(v3 + 0x1E);
        *v6 &= 0xFC0FFFFF;
        v4 = v29 & 0xFB;
        *v7 |= 0x400000u;
        *(uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 2) != 0 )
      {
        *(uint32_t *)(v1 + 4) &= ~2u;
        if ( *(uint8_t *)(v0 + 0x1D) == 5 )
        {
          fault_handler((uint32_t *)dword_120F34);
          LOBYTE(v4) = *(uint8_t *)(v3 + 0x1E);
          *(uint8_t *)(v0 + 0x1D) = 0;
        }
        v4 &= 0xFDu;
        *(uint8_t *)(v3 + 0x1E) = v4;
      }
      result = v4 << 31;
      if ( (v4 & 1) != 0 )
        break;
LABEL_20:
      if ( (v4 & 0x20) != 0 )
      {
        v14 = *(uint32_t *)dword_120F00;
        v15 = (*(uint32_t *)dword_120F00 >> 5) & 3;
        check_status_bits(2, "BCN:%d[%d]\r\n", v15, HIWORD(*(uint32_t *)(dword_120F00 - 12)) & 0x7FFF);
        v16 = *(uint32_t *)(v1 + 120);
        v17 = *(uint32_t *)(*(uint32_t *)dword_120EE8 + 4);
        *(uint8_t *)(v1 + 128) = 0;
        v18 = (*(volatile uint32_t *)0x40501010u);
        v19 = v14 >> 5;
        if ( (int)(v17 + v16 - v18) < 0 )
        {
          *(uint8_t *)(v3 + 0x1E) |= 8u;
          check_status_bits(2, aNull);
        }
        if ( v15 )
        {
          while ( (*(uint32_t *)dword_120F00 & 8) == 0 )
            ;
          v32 = (uint32_t *)dword_120F00;
          *(uint32_t *)dword_120F00 &= ~8u;
          if ( (*v32 & 0x10) != 0 )
          {
            check_status_bits(2, aFcsOk);
            *(uint8_t *)dword_120F08 = BYTE2(*(uint32_t *)dword_120F4C);
            wlc_rx_reclaim(v15 >> 1, v19 & 1, v1);
            *v32 &= ~0x10u;
          }
          else
          {
            *(uint32_t *)dword_121078 = 1;
            check_status_bits(2, aFcsNotOk);
            v33 = (uint32_t *)dword_121084;
            *(uint8_t *)dword_121080 = *(uint8_t *)(dword_121080 + 1) > 1u;
            *v33 = 1;
          }
        }
        else
        {
          *(uint8_t *)dword_120F08 = *(uint8_t *)(dword_120F08 + 1);
        }
        v20 = (uint8_t **)dword_120F10;
        *(uint32_t *)dword_120F0C &= ~0x200u;
        *(uint32_t *)(v1 + 4) &= ~1u;
        result = fault_handler((uint32_t *)(v1 + 48));
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)dword_121094 = 1;
          }
          v35 = (uint32_t *)dword_1210B0;
          v36 = (uint32_t *)dword_121088;
          v37 = *(uint32_t *)dword_121088;
          ++*(uint32_t *)dword_1210B0;
          *v36 = 0;
          v38 = (*(volatile uint32_t *)0x40501010u);
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            v40 = (*(volatile uint32_t *)0x40501010u) - v38;
            if ( v40 > 0x7530 )
            {
              v50 = v39;
              check_status_bits(2, aIdleErr);
              v39 = v50;
            }
          }
          v41 = (uint32_t *)dword_12109C;
          result = *(uint32_t *)dword_12109C;
          v42 = (*(volatile uint32_t *)0x40501010u);
          if ( v39 )
          {
            result &= *(uint32_t *)dword_121098;
            if ( (result & 4) == 0 )
            {
              v51 = v1;
              v45 = (uint32_t *)dword_121098;
              v46 = v42;
              do
              {
                result = 30000;
                v47 = (*(volatile uint32_t *)0x40501010u) - v46;
                v48 = *v45 & *v41;
                if ( v47 > 0x7530 )
                {
                  result = check_status_bits(2, aIdleIntErr);
                  v45 = (uint32_t *)dword_121098;
                }
              }
              while ( (v48 & 4) == 0 );
              v1 = v51;
            }
          }
          *(uint32_t *)dword_1210A0 = 4;
          if ( *v35 )
          {
            v43 = *v35 - 1;
            v44 = *(uint32_t *)dword_121094;
            *v35 = v43;
            if ( !v43 )
            {
              if ( v44 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = (uint32_t *)dword_120F00;
        *(uint32_t *)dword_120F00 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          v34 = (*(volatile uint32_t *)0x40501010u) + 32 * *(uint32_t *)dword_12108C;
          result = unknown_worker((uint32_t *)(v1 + 24), v34 - *(uint16_t *)(dword_121090 + 0xBA));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(uint32_t *)dword_121088 = 48;
          result = fatal_error_handler();
        }
        v4 = *(uint8_t *)(v3 + 0x1E) & 0xDF;
        *(uint8_t *)(v3 + 0x1E) = v4;
        goto LABEL_3;
      }
    }
    if ( (*(uint32_t *)dword_120EF0 & 0x4000000) != 0 )
    {
      v10 = HIWORD(*(uint32_t *)dword_120EF0);
      if ( (v10 & 0x3F0) != 0 )
      {
        v11 = (uint8_t)(v10 - 16);
        v12 = dword_120EF4 + 696 * v11;
        if ( *(uint8_t *)(v12 + 37) )
        {
          result = 1320;
          v13 = dword_120EFC + 1320 * *(uint8_t *)(v12 + 34);
          if ( **(uint16_t **)dword_120EF8 >= 0 || v1 == v13 )
          {
            if ( (*v6 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = mmio_clear_register((int)aVifStaVif, (int)aMmSleepinfoRxE, 864);
            if ( (*v6 & 0x70000) == 0 )
            {
LABEL_43:
              LODWORD(v49) = *(uint32_t *)dword_120EF0 >> 31;
              HIDWORD(v49) = (*(uint32_t *)dword_120EF0 >> 30) & 1;
              check_status_bits(2, "T=%d,%d\r\n", (uint32_t)v49, HIDWORD(v49));
              result = v49;
              if ( v49 )
              {
                result = wlc_rx_reclaim(v49, SHIDWORD(v49), v13);
                v31 = (uint32_t *)dword_120EF0;
                *(uint32_t *)dword_120EF0 &= ~0x80000000;
                *v31 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = event_dispatch("\x9B\x84Invalid STA:%d\n", v11);
        }
      }
      else
      {
        result = event_dispatch(asc_148810);
      }
    }
    else
    {
      result = event_dispatch("\x9B\x84Keyidx invalid,%02X\n", v4);
    }
    v4 = *(uint8_t *)(v3 + 0x1E) & 0xFE;
    *(uint8_t *)(v3 + 0x1E) = v4;
    goto LABEL_20;
  }
  return result;
}
