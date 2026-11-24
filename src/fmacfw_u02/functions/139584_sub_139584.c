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


extern uint32_t dword_139858;
extern uint32_t dword_13985C;
extern uint32_t dword_139860;
extern uint32_t dword_139864;
extern uint32_t dword_139868;
extern uint32_t dword_13986C;
extern uint32_t dword_139870;
extern uint32_t dword_139874;
extern uint32_t dword_139A90;
extern uint32_t dword_139AA0;
extern uint32_t dword_139AA8;
extern uint32_t dword_139AAC;

// bt_scan_event @ 0x139584, size 1284 bytes
int  bt_scan_event(uint16_t a1, int a2, int a3, int a4, uint8_t *a5, int a6, uint16_t *a7, uint8_t *a8)
{
  int v9; // r12
  unsigned int v11; // r5
  int v12; // r8
  int v13; // r4
  int v15; // r5
  unsigned int v16; // r0
  int v17; // r5
  int *v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // r5
  unsigned int v22; // r8
  unsigned int v23; // r6
  int v24; // r10
  uint16_t v25; // r11
  uint8_t *v26; // r3
  uint8_t *v27; // r0
  uint8_t *v28; // r10
  uint8_t *v29; // r11
  uint16_t v30; // r5
  unsigned int v31; // r1
  int v32; // r3
  uint8_t *v33; // r2
  int v34; // r4
  unsigned int v35; // r1
  uint16_t v36; // r0
  uint8_t *v37; // r8
  int v38; // r3
  int v39; // r9
  int v40; // r4
  unsigned int v41; // r10
  int v42; // r7
  uint8_t *v43; // r9
  unsigned int v44; // r4
  unsigned int v45; // r10
  int v46; // r0
  int v47; // r2
  unsigned int v48; // r1
  uint32_t *v49; // r0
  int v50; // r1
  uint8_t a3a; // [sp+Eh] [bp-6h] BYREF
  uint8_t v53[5]; // [sp+Fh] [bp-5h] BYREF

  v9 = (uint8_t)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      is_hw_feature_6();
      return 1;
    }
    if ( v16 > 0xB0 )
    {
      if ( v16 != 208 )
        return 1;
LABEL_12:
      v15 = a6 + a3;
      if ( a4 == 255 )
        return 1;
      switch ( *(uint8_t *)(a6 + a3) )
      {
        case 0:
          v39 = *(uint8_t *)(v15 + 1);
          event_dispatch("rx spectrum action: action code=%d\n", v39);
          v37 = (uint8_t *)(v15 + 1);
          if ( v39 == 4 )
          {
            v40 = (uint8_t)*a5;
            if ( v40 != 255 )
            {
              v41 = dword_139A90;
              v42 = (uint8_t)rx_packet_handler_2(v15 + 2, a2 - a3 - 2, v53, 1320 * v40 + 1212 + dword_139A90);
              event_dispatch("csa count=%d, mode=%d!\n", v42, v53[0]);
              if ( v42 )
              {
                v43 = (uint8_t *)(1320 * v40 + v41);
                if ( !v43[106] )
                {
                  if ( !v43[146] && v43[148] && v53[0] == 1 )
                    hci_send_cmd_0x59(v43[107], 0);
                  v44 = v41 + 1320 * v40;
                  *(uint8_t *)(v44 + 146) = v42;
                  *(uint8_t *)(v44 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v36 = ll_cmd_handler(a4, (uint16_t *)v15, *(uint8_t *)(v15 + 1));
          v9 = v36;
          if ( v36 != 33 )
          {
            v30 = (char)v36 << 8;
            v13 = 0;
            *a7 = 8;
            goto LABEL_49;
          }
          return 0;
        case 5:
          v31 = dword_139858;
          if ( *(uint8_t *)(dword_139858 + 1320 * v9 + 106) == 2
            || (v32 = *(uint8_t *)(v15 + 1), v33 = (uint8_t *)(v15 + 1), *(uint8_t *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v33 = (uint8_t *)(v15 + 1);
            if ( *(uint8_t *)(dword_139A90 + 1320 * v9 + 106) )
              goto LABEL_46;
            v9 = 255;
          }
          else
          {
            *a7 = 11;
            v34 = (uint8_t)*a5;
            if ( v34 == 255 )
            {
              v30 = v32;
              v13 = 1;
              goto LABEL_50;
            }
            v35 = v31 + 1320 * v34;
            v13 = *(uint8_t *)(v35 + 106);
            if ( *(uint8_t *)(v35 + 106) )
            {
              v9 = v32;
              v13 = 1;
              goto LABEL_48;
            }
            v9 = *(uint8_t *)(v35 + 106);
          }
          if ( (unsigned int)*v33 - 6 > 1 )
          {
LABEL_88:
            v13 = 1;
            goto LABEL_47;
          }
          *a7 = 12;
          v30 = 0;
LABEL_50:
          *a7 |= v30;
          return v13;
        case 7:
          v13 = *(uint8_t *)(v15 + 1);
          if ( *(uint8_t *)(v15 + 1) )
          {
            if ( v13 != 1 )
              goto LABEL_46;
            if ( (*(uint32_t *)(dword_139870 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(uint8_t *)(v15 + 2) & 1;
              if ( (*(uint8_t *)(v15 + 2) & 1) != 0 )
              {
                bt_get_conn_entry(a4, 0xFFu, 0);
                v13 = 0;
              }
              else
              {
                bt_get_conn_entry(a4, 0xFFu, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(uint32_t *)(dword_139AA0 + 696 * a4 + 4) & 2) != 0 )
          {
            v48 = *(uint8_t *)(v15 + 2);
            if ( v48 <= 1 )
            {
              bt_get_conn_entry(a4, v48, 0xFFu);
              v9 = 255;
              goto LABEL_47;
            }
          }
          goto LABEL_69;
        case 8:
          if ( a2 - a3 <= 3 )
            goto LABEL_69;
          if ( v9 == 255 )
            goto LABEL_88;
          v13 = *(uint8_t *)(v15 + 1) | *(uint8_t *)(dword_139A90 + 1320 * v9 + 106);
          if ( v13 )
            goto LABEL_46;
          *a7 = 6;
          v30 = 0;
          goto LABEL_50;
        case 0x15:
          v37 = (uint8_t *)(v15 + 1);
LABEL_65:
          v38 = *v37;
          if ( v38 == 1 )
          {
            rf_set_address((uint32_t *)(v15 + 2), (uint32_t *)(v15 + 10));
          }
          else
          {
            if ( v38 != 2 )
            {
LABEL_46:
              v13 = 1;
              v9 = 255;
              goto LABEL_47;
            }
            if ( (*(uint32_t *)(dword_139870 + 696 * a4 + 4) & 0x24) != 0 && *(char *)(v15 + 2) >= 0 )
            {
              bt_get_conn_entry(a4, *(uint8_t *)(v15 + 2) & 3, *(uint8_t *)(v15 + 2) >> 4);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v30 = (uint16_t)v9 << 8;
LABEL_49:
              if ( **(uint16_t **)dword_13986C < 0 && v9 == 255 )
                mmio_clear_register((int)aTaskIdx0xff, (int)aRxuMgtRouteAct, 2326);
              goto LABEL_50;
            }
          }
LABEL_69:
          v13 = 0;
          v9 = 255;
          goto LABEL_47;
        case 0x16:
          v13 = 0;
          goto LABEL_84;
        default:
          goto LABEL_46;
      }
    }
    if ( v16 == 64 )
    {
LABEL_33:
      if ( !*(uint8_t *)(dword_139860 + 0x12) )
        return 1;
      v20 = **(uint8_t **)dword_139864;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *(uint32_t *)(dword_139860 + 8);
      if ( !v21 )
        return 1;
      v22 = dword_139874;
      v23 = dword_139868;
      v13 = 1;
      while ( 1 )
      {
        if ( *(uint8_t *)(v21 + 106) == 2 && *(uint8_t *)(v21 + 108) && !*(uint8_t *)(v21 + 1224) )
        {
          v24 = *(uint8_t *)(v21 + 107);
          v25 = *(uint16_t *)(v22 + 2 * v24);
          v26 = buf_calc_3((uint8_t *)(a6 + 24), (uint16_t)(a2 - 24), &a3a);
          v27 = (uint8_t *)(v23 + (v24 << 9) + 36);
          v28 = v26;
          v29 = buf_calc_3(v27, (uint16_t)(v25 - 36), v53);
          if ( v53[0] )
          {
            if ( a3a )
            {
              v45 = (unsigned int)(v28 + 2);
              v46 = memcmp(v45, (unsigned int)aDirect, 7u);
              v47 = a3a;
              if ( v46 && a3a == v53[0] )
              {
                if ( !memcmp(v45, (unsigned int)(v29 + 2), a3a) )
                {
                  event_dispatch(aSsidMatch);
                  v49 = (uint32_t *)dword_139AAC;
                  *(uint8_t *)dword_139AA8 = 1;
                  v50 = (*(volatile uint32_t *)0x40501010u) + 200000;
                  unknown_worker(v49, v50);
                }
                v47 = a3a;
              }
              if ( v47
                && (!memcmp(v45, (unsigned int)aDirect, 7u)
                 || a3a != v53[0]
                 || memcmp(v45, (unsigned int)(v29 + 2), a3a)) )
              {
                goto LABEL_38;
              }
            }
          }
          else if ( a3a )
          {
            return 1;
          }
          bt_link_state_check(v21, (char *)(a6 + 10));
          v13 = 0;
        }
LABEL_38:
        v21 = *(uint32_t *)v21;
        if ( !v21 )
          return v13;
      }
    }
    if ( v16 != 128 )
      return 1;
    v17 = 0;
  }
  else
  {
    v11 = a1 & 0xFC;
    v12 = *(uint8_t *)(dword_139858 + 1320 * v9 + 106);
    if ( v11 != 128 )
    {
      if ( (a1 & 0xFCu) <= 0x80 )
      {
        if ( v11 != 64 )
        {
          if ( v11 > 0x40 )
          {
            v13 = 1;
            if ( v11 == 80 )
            {
              *a8 = 1;
              *a7 = 4;
            }
            return v13;
          }
          if ( (a1 & 0xDC) != 0x10 )
            return 1;
          goto LABEL_19;
        }
        goto LABEL_33;
      }
      if ( v11 != 192 )
      {
        if ( v11 > 0xC0 )
        {
          if ( v11 != 208 )
            return 1;
          goto LABEL_12;
        }
        if ( v11 != 160 && (v11 != 176 || is_hw_feature_6()) )
          return 1;
      }
LABEL_19:
      if ( !v12 )
      {
        *a7 = 6;
        return 1;
      }
      return 1;
    }
    v17 = dword_139858 + 1320 * v9;
  }
  if ( rx_rate_field_parse(4u) == 1 )
  {
    v18 = (int *)dword_13985C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(uint8_t *)(v19 + 366);
  }
  if ( a4 != 255 && *(uint8_t *)(v17 + 108) )
  {
    rx_process_packet_1(v17, a2, a6);
    return 1;
  }
  return 1;
}
