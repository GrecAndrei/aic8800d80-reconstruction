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

extern uint32_t off_120F54;
extern uint32_t off_120EDC;
extern uint32_t off_120F58;
extern uint32_t off_120EE0;
extern uint32_t off_120EE4;
extern uint32_t off_120F5C;
extern uint32_t off_120EE8;
extern uint32_t off_120EEC;
extern uint32_t dword_120F14;
extern uint32_t off_120EF8;
extern uint32_t off_120F24;
extern uint32_t dword_120F2C;
extern uint32_t dword_120F28;
extern uint32_t off_120F18;
extern uint32_t off_120F1C;
extern uint32_t dword_120F34;
extern uint32_t off_120F00;
extern uint32_t dword_120F04;
extern uint32_t dword_120F50;
extern uint32_t dword_120F48;
extern uint32_t off_120F08;
extern uint32_t off_120F4C;
extern uint32_t dword_12107C;
extern uint32_t off_121078;
extern uint32_t off_121084;
extern uint32_t off_121080;
extern uint32_t off_120F10;
extern uint32_t off_120F0C;
extern uint32_t off_121094;
extern uint32_t off_1210B0;
extern uint32_t off_121088;
extern uint32_t dword_1210A4;
extern uint32_t off_12109C;
extern uint32_t off_121098;
extern uint32_t dword_1210AC;
extern uint32_t off_1210A0;
extern uint32_t off_12108C;
extern uint32_t off_121090;
extern uint32_t off_120EF0;
extern uint32_t dword_120EF4;
extern uint32_t dword_120EFC;
extern uint32_t dword_120F40;
extern uint32_t dword_120F3C;
extern uint32_t dword_120F44;
extern uint32_t dword_120F38;
extern uint32_t dword_120F30;
extern uint32_t dword_120F20;

// wait_for_hw_flag @ 0x120bd0, size 1192 bytes
int wait_for_hw_flag()
{
  uint8_t *v0; // r10
  int v1; // r8
  int result; // r0
  void *v3; // r4
  uint32_t *v4; // r11
  int v5; // r1
  uint32_t *v6; // r7
  uint32_t *v7; // r5
  uint32_t *v8; // r9
  int v9; // r3
  int v10; // r2
  int v11; // r1
  int v12; // r1
  int v13; // r3
  int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // r1
  int v18; // r3
  char v19; // r5
  uint8_t **v20; // r7
  uint8_t *v21; // r1
  uint32_t *v22; // r3
  int v23; // r3
  int16_t **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  void *v28; // r1
  char v29; // r1
  uint32_t *v30; // r2
  uint32_t *v31; // r7
  int v32; // r1
  int v33; // r1
  uint32_t *v34; // r1
  int *v35; // r9
  uint32_t *v36; // r5
  int v37; // r2
  int v38; // r6
  int v39; // r2
  uint32_t *v40; // r6
  int v41; // r3
  int v42; // r2
  uint32_t *v43; // r2
  int v44; // r8
  int v45; // r5
  int v46[3]; // [sp+0h] [bp-Ch]
  int v47; // [sp+0h] [bp-Ch]
  int v48; // [sp+0h] [bp-Ch]

  v0 = off_120F54;
  v1 = *((uint32_t *)off_120F54 + 8);
  result = unknown_func_12d14c(0x40000);
  if ( v1 )
  {
    v3 = off_120EDC;
    v4 = off_120F58;
    v5 = *((uint8_t *)off_120EDC + 30);
LABEL_3:
    v6 = off_120EE0;
    v7 = off_120EE4;
    v8 = off_120F5C;
    while ( 1 )
    {
      if ( !v5 )
        return result;
      if ( (v5 & 8) != 0 )
      {
        v9 = *(uint32_t *)off_120EE8;
        *(uint32_t *)off_120EEC = 0x80000000;
        if ( *(uint32_t *)(v9 + 4) + *(uint32_t *)(v1 + 120) - v4[4] < 0
          && !rf_channel_get(*(uint8_t *)(v1 + 116), 0, 0) )
        {
          *(uint32_t *)(v1 + 120) = v4[4];
        }
        v5 = *((uint8_t *)v3 + 30) & 0xF7;
        *((uint8_t *)v3 + 30) = v5;
      }
      if ( (v5 & 4) != 0 )
      {
        check_status_bits(2, dword_120F14);
        v24 = (int16_t **)off_120EF8;
        v25 = *((uint32_t *)v3 + 1);
        *v6 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *((uint32_t *)v3 + 1) = v27;
        if ( v26 < 0 && *(uint32_t *)off_120F24 << 28 )
        {
          call_shared_handler(dword_120F2C, dword_120F28, 472);
          v27 = *((uint32_t *)v3 + 1);
        }
        v28 = off_120F18;
        *(uint32_t *)off_120F1C = v27 | *(uint32_t *)v3;
        link_get_connection_info(*(uint8_t *)(v1 + 107), v28, v1);
        v29 = *((uint8_t *)v3 + 30);
        *v7 &= 0xFC0FFFFF;
        v5 = v29 & 0xFB;
        *v8 |= 0x400000u;
        *((uint8_t *)v3 + 30) = v5;
      }
      if ( (v5 & 2) != 0 )
      {
        *(uint32_t *)(v1 + 4) &= ~2u;
        if ( v0[29] == 5 )
        {
          fault_handler(dword_120F34);
          LOBYTE(v5) = *((uint8_t *)v3 + 30);
          v0[29] = 0;
        }
        v5 &= 0xFDu;
        *((uint8_t *)v3 + 30) = v5;
      }
      result = v5 << 31;
      if ( (v5 & 1) != 0 )
        break;
LABEL_20:
      if ( (v5 & 0x20) != 0 )
      {
        v15 = *(uint32_t *)off_120F00;
        v16 = (*(uint32_t *)off_120F00 >> 5) & 3;
        check_status_bits(2, dword_120F04);
        v17 = *(uint32_t *)(v1 + 120);
        v18 = *(uint32_t *)(*(uint32_t *)off_120EE8 + 4);
        *(uint8_t *)(v1 + 128) = 0;
        v19 = v15 >> 5;
        if ( v18 + v17 - v4[4] < 0 )
        {
          v32 = dword_120F50;
          *((uint8_t *)v3 + 30) |= 8u;
          check_status_bits(2, v32);
        }
        if ( v16 )
        {
          while ( (*(uint32_t *)off_120F00 & 8) == 0 )
            ;
          v31 = off_120F00;
          *(uint32_t *)off_120F00 &= ~8u;
          if ( (*v31 & 0x10) != 0 )
          {
            check_status_bits(2, dword_120F48);
            *(uint8_t *)off_120F08 = BYTE2(*(uint32_t *)off_120F4C);
            wlc_rx_reclaim(v16 >> 1, v19 & 1, v1);
            *v31 &= ~0x10u;
          }
          else
          {
            v33 = dword_12107C;
            *(uint32_t *)off_121078 = 1;
            check_status_bits(2, v33);
            v34 = off_121084;
            *(uint8_t *)off_121080 = *((uint8_t *)off_121080 + 1) > 1u;
            *v34 = 1;
          }
        }
        else
        {
          *(uint8_t *)off_120F08 = *((uint8_t *)off_120F08 + 1);
        }
        v20 = (uint8_t **)off_120F10;
        *(uint32_t *)off_120F0C &= ~0x200u;
        *(uint32_t *)(v1 + 4) &= ~1u;
        result = fault_handler(v1 + 48);
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_121094 = 1;
          }
          v35 = (int *)off_1210B0;
          v36 = off_121088;
          v37 = *(uint32_t *)off_121088;
          ++*(uint32_t *)off_1210B0;
          *v36 = 0;
          v38 = v4[4];
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            if ( (unsigned int)(v4[4] - v38) > 0x7530 )
            {
              v47 = v39;
              check_status_bits(2, dword_1210A4);
              v39 = v47;
            }
          }
          v40 = off_12109C;
          result = *(uint32_t *)off_12109C;
          if ( v39 )
          {
            result &= *(uint32_t *)off_121098;
            if ( (result & 4) == 0 )
            {
              v48 = v1;
              v43 = off_121098;
              v44 = v4[4];
              do
              {
                result = 30000;
                v45 = *v43 & *v40;
                if ( (unsigned int)(v4[4] - v44) > 0x7530 )
                {
                  result = check_status_bits(2, dword_1210AC);
                  v43 = off_121098;
                }
              }
              while ( (v45 & 4) == 0 );
              v1 = v48;
            }
          }
          *(uint32_t *)off_1210A0 = 4;
          if ( *v35 )
          {
            v41 = *v35 - 1;
            v42 = *(uint32_t *)off_121094;
            *v35 = v41;
            if ( !v41 )
            {
              if ( v42 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = off_120F00;
        *(uint32_t *)off_120F00 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          result = unknown_worker(
                     v1 + 24,
                     v4[4] + 32 * *(uint32_t *)off_12108C - *((uint16_t *)off_121090 + 93));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(uint32_t *)off_121088 = 48;
          result = fatal_error_handler();
        }
        v5 = *((uint8_t *)v3 + 30) & 0xDF;
        *((uint8_t *)v3 + 30) = v5;
        goto LABEL_3;
      }
    }
    v10 = 32 * *(uint32_t *)off_120EF0;
    if ( (*(uint32_t *)off_120EF0 & 0x4000000) != 0 )
    {
      v11 = HIWORD(*(uint32_t *)off_120EF0);
      if ( (v11 & 0x3F0) != 0 )
      {
        v12 = (uint8_t)(v11 - 16);
        v13 = dword_120EF4 + 696 * v12;
        if ( *(uint8_t *)(v13 + 37) )
        {
          result = 1320;
          v14 = dword_120EFC + 1320 * *(uint8_t *)(v13 + 34);
          if ( **(int16_t **)off_120EF8 >= 0 || v1 == v14 )
          {
            if ( (*v7 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = mmio_clear_register(dword_120F40, dword_120F3C, 864);
            if ( (*v7 & 0x70000) == 0 )
            {
LABEL_43:
              v46[0] = *(uint32_t *)off_120EF0 >> 31;
              v46[1] = (*(uint32_t *)off_120EF0 >> 30) & 1;
              check_status_bits(2, dword_120F44);
              result = v46[0];
              if ( *(uint64_t *)v46 )
              {
                result = wlc_rx_reclaim(v46[0], v46[1], v14);
                v30 = off_120EF0;
                *(uint32_t *)off_120EF0 &= ~0x80000000;
                *v30 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = event_dispatch(dword_120F38, v12, *(uint8_t *)(v13 + 37));
        }
      }
      else
      {
        result = event_dispatch(dword_120F30, v11, v10);
      }
    }
    else
    {
      result = event_dispatch(dword_120F20, v5, v10);
    }
    v5 = *((uint8_t *)v3 + 30) & 0xFE;
    *((uint8_t *)v3 + 30) = v5;
    goto LABEL_20;
  }
  return result;
}

