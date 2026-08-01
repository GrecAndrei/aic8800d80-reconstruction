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

extern uint32_t off_11D66C;
extern uint32_t dword_11D64C;
extern uint32_t dword_11D648;
extern uint32_t off_11D630;
extern uint32_t off_11D634;
extern uint32_t off_11D650;
extern uint32_t dword_11D638;
extern uint32_t dword_11D654;
extern uint32_t dword_11D63C;
extern uint32_t off_11D640;
extern uint32_t dword_11D644;
extern uint32_t off_11D658;
extern uint32_t off_11D65C;
extern uint32_t off_11D660;
extern uint32_t off_11D670;
extern uint32_t dword_11D7A4;
extern uint32_t off_11D664;
extern uint32_t off_11D668;
extern uint32_t dword_11D788;
extern uint32_t off_11D78C;
extern uint32_t off_11D790;
extern uint32_t off_11D794;
extern uint32_t off_11D798;
extern uint32_t off_11D7A0;
extern uint32_t dword_11D7AC;
extern uint32_t dword_11D7A8;
extern uint32_t off_11D79C;
extern uint32_t dword_11D620;
extern uint32_t dword_11D624;
extern uint32_t dword_11D628;
extern uint32_t dword_11D62C;

// rf_rx_check @ 0x11d320, size 1128 bytes
BOOL  rf_rx_check(int a1)
{
  int16_t **v1; // r10
  int v2; // r8
  int v3; // r3
  int16_t *v5; // r9
  int16_t v6; // r11
  unsigned int v7; // r6
  int v8; // r5
  int v10; // r2
  unsigned int v11; // r7
  int v12; // r3
  unsigned int v13; // r3
  uint8_t *v14; // r5
  int v15; // r2
  int v16; // r3
  int v17; // r11
  int v18; // r7
  int v19; // r4
  uint64_t v20; // r0
  uint64_t v21; // r0
  unsigned int v22; // r2
  unsigned uint64_t v23; // r4
  uint64_t v24; // r0
  uint64_t v25; // r0
  uint64_t v26; // r0
  int v27; // r0
  uint8_t *v28; // r4
  uint32_t *v29; // r2
  int v30; // r8
  int *v31; // r11
  uint32_t *v32; // r7
  uint32_t *v33; // r6
  int v34; // r9
  uint32_t *v35; // r3
  uint32_t *v36; // r7
  uint32_t *v37; // r9
  int v38; // r5
  int v39; // r6
  int v40; // r5
  int v41; // r3
  int v42; // r2
  uint32_t *v43; // r6
  int v44; // r2
  unsigned int v45; // r3
  uint32_t *v46; // r6
  int v47; // r1
  unsigned int v48; // r3
  unsigned int v49; // [sp+4h] [bp-18h]
  int v50; // [sp+4h] [bp-18h]
  int v51; // [sp+8h] [bp-14h]
  int v52; // [sp+Ch] [bp-10h]
  int v53; // [sp+14h] [bp-8h] BYREF

  if ( *(uint16_t *)(a1 + 48) )
  {
    v1 = (int16_t **)off_11D66C;
    v2 = *(uint32_t *)(a1 + 28);
    v3 = **(int16_t **)off_11D66C;
    if ( v3 < 0 && !v2 )
    {
      v8 = 0;
      bad_func_0x12f408(dword_11D64C, dword_11D648, 423, v3);
      return v8;
    }
    v5 = *(int16_t **)(v2 + 8);
    v6 = *v5;
    v7 = *(uint32_t *)(a1 + 84);
    if ( *((uint8_t *)off_11D630 + 408)
      && (*((uint32_t *)off_11D634 + 1) & 0x40) != 0
      && (*(uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(uint32_t *)off_11D650;
    }
    else
    {
      if ( (dword_11D638 & ~v7) != 0 )
        return 0;
      *(uint32_t *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v8 = (v7 >> 15) & 0x1F0;
        if ( !v8 )
        {
          bad_func_0x12f408(dword_11D654, dword_11D648, 475, v3);
          return v8;
        }
      }
      v10 = dword_11D63C;
      v11 = (uint8_t)((v7 >> 15) - 16);
      v12 = dword_11D63C + 696 * v11;
      v8 = *(uint8_t *)(v12 + 37);
      if ( !*(uint8_t *)(v12 + 37) )
      {
        *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v8;
      }
      if ( v11 <= 0x23 )
        *(uint32_t *)(v12 + 664) = *((uint32_t *)off_11D640 + 4);
      v13 = v10 + 696 * v11;
      if ( *(uint16_t *)(v13 + 32) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        v49 = *(uint32_t *)(v13 + 44);
        *(uint32_t *)(a1 + 84) = v7 & 0xFE007FFF | ((*(uint8_t *)(v49 + 35) + 16) << 15);
      }
      else
      {
        v49 = v10 + 696 * v11;
      }
      v51 = *(uint8_t *)(v49 + 34);
      v14 = (uint8_t *)(dword_11D644 + 1320 * v51);
      v52 = 1320 * v51;
      radio_event_loop(v5, v11, v14[107]);
      if ( !v14[108] )
        return 0;
      v15 = v14[106];
      v16 = dword_11D644;
      if ( v14[106] )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v27 = memcmp(v5 + 8, v52 + 100 + dword_11D644, 6);
      v16 = dword_11D644;
      if ( v27 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
        {
LABEL_37:
          v15 = *(uint8_t *)(v16 + 1320 * v51 + 106);
          if ( !*(uint8_t *)(v16 + 1320 * v51 + 106) )
          {
LABEL_19:
            v17 = v6 & 0xFC;
            v18 = v52 + v16;
            if ( v17 == 128 )
            {
              v53 = 0;
              v40 = rx_process_packet(a1 + 20, v18, v49, &v53);
              wlc_ioctl_handler(v53, *(uint16_t *)(a1 + 48), v18);
              get_radio_state(v18);
              if ( v40 )
                llc_conn_idx_valid(v18, v2, a1 + 20);
              return v40 == 0;
            }
            if ( v17 == 80 )
            {
              v28 = off_11D658;
              if ( *((uint8_t *)off_11D658 + 29) == 7 )
              {
                v8 = *((uint8_t *)off_11D658 + 36);
                if ( !*((uint8_t *)off_11D658 + 36) )
                {
                  v29 = off_11D65C;
                  v30 = *(uint32_t *)off_11D65C & 0xF;
                  if ( v30 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(uint32_t *)off_11D660 = 1;
                    }
                    v31 = (int *)off_11D670;
                    v32 = off_11D65C;
                    v33 = off_11D640;
                    ++*(uint32_t *)off_11D670;
                    *v32 = 0;
                    v34 = v33[4];
                    while ( *v32 << 28 )
                    {
                      if ( (unsigned int)(v33[4] - v34) > 0x7530 )
                        check_status_bits(2, dword_11D7A4);
                    }
                    v35 = off_11D664;
                    v36 = off_11D640;
                    if ( (*(uint32_t *)off_11D668 & *(uint32_t *)off_11D664 & 4) == 0 )
                    {
                      v50 = v8;
                      v37 = off_11D668;
                      v38 = *((uint32_t *)off_11D640 + 4);
                      do
                      {
                        v39 = *v35 & *v37;
                        if ( (unsigned int)(v36[4] - v38) > 0x7530 )
                        {
                          check_status_bits(2, dword_11D788);
                          v35 = off_11D78C;
                        }
                      }
                      while ( (v39 & 4) == 0 );
                      v8 = v50;
                    }
                    *(uint32_t *)off_11D790 = 4;
                    if ( *v31 )
                    {
                      v41 = *v31 - 1;
                      v42 = *(uint32_t *)off_11D794;
                      *v31 = v41;
                      if ( !v41 )
                      {
                        if ( v42 )
                          __enable_irq();
                      }
                    }
                    v43 = off_11D798;
                    v44 = **v1;
                    v45 = *((uint32_t *)off_11D798 + 1) & 0xFFFFFDFF;
                    *((uint32_t *)off_11D798 + 1) = v45;
                    if ( v44 < 0 && *(uint32_t *)off_11D7A0 << 28 )
                    {
                      call_shared_handler(dword_11D7AC, dword_11D7A8, 472);
                      v45 = v43[1];
                    }
                    *(uint32_t *)off_11D79C = v45 | *v43;
                    *(uint32_t *)off_11D7A0 = 16 * v30;
                  }
                  else
                  {
                    v46 = off_11D798;
                    v47 = **v1;
                    v48 = *((uint32_t *)off_11D798 + 1) & 0xFFFFFDFF;
                    *((uint32_t *)off_11D798 + 1) = v48;
                    if ( v47 < 0 && *v29 << 28 )
                    {
                      call_shared_handler(dword_11D7AC, dword_11D7A8, 472);
                      v48 = v46[1];
                    }
                    *(uint32_t *)off_11D79C = v48 | *v46;
                  }
                  v28[36] = 1;
                  v28[29] = 0;
                  return v8;
                }
              }
            }
            else if ( v8 )
            {
              if ( v17 == 132 )
              {
                wlc_bus_state(v5, v7);
                return 0;
              }
            }
            else
            {
              wlc_bus_state(v5, v7);
              if ( *(uint8_t *)(dword_11D644 + 1320 * v51 + 1224) && v17 == 208 )
              {
                hci_cmd_preprocess(v18, *(uint32_t *)(v2 + 8), *(uint16_t *)(a1 + 48), *(uint32_t *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v15 == 2 && *(uint8_t *)(v49 + 35) <= 0x23u )
          {
            v19 = *(char *)(a1 + 65);
            rf_get_field0();
            if ( !*(uint8_t *)(v49 + 689) )
            {
              v8 = *(char *)(v49 + 689);
              *(uint8_t *)(v49 + 689) = v19;
              return v8;
            }
            v20 = int_to_double(*(char *)(v49 + 689));
            v21 = double_add(v20, HIDWORD(v20), dword_11D620, dword_11D624);
            v22 = v21;
            LODWORD(v21) = v19;
            v23 = __PAIR64__(HIDWORD(v21), v22);
            v24 = int_to_double(v21);
            v25 = double_add(v24, HIDWORD(v24), dword_11D628, dword_11D62C);
            v26 = double_compare(v23, HIDWORD(v23), v25, HIDWORD(v25));
            *(uint8_t *)(v49 + 689) = double_to_float(v26, HIDWORD(v26));
          }
          return 0;
        }
LABEL_36:
        tx_len_check(*(uint8_t *)(v16 + 1320 * v51 + 107), v11, 1);
        v16 = dword_11D644;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}

