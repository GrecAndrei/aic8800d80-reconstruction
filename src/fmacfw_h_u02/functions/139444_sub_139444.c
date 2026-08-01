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

extern uint32_t dword_139948;
extern uint32_t dword_139950;
extern uint32_t dword_13994C;
extern uint32_t dword_139718;
extern uint32_t dword_139730;
extern uint32_t dword_139960;
extern uint32_t off_13972C;
extern uint32_t dword_139958;
extern uint32_t dword_139954;
extern uint32_t off_139720;
extern uint32_t off_139724;
extern uint32_t dword_139734;
extern uint32_t dword_139728;
extern uint32_t off_139738;
extern uint32_t dword_13995C;
extern uint32_t dword_139964;
extern uint32_t dword_13996C;
extern uint32_t off_139968;
extern uint32_t off_13971C;

// bt_parse_rx_packet @ 0x139444, size 1284 bytes
int  bt_parse_rx_packet(char a1, int a2, int a3, int a4, uint8_t *a5, unsigned int a6, uint16_t *a7, uint8_t *a8)
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
  int v22; // r8
  int v23; // r6
  uint32_t *v24; // r9
  int v25; // r10
  int16_t v26; // r11
  uint8_t *v27; // r3
  uint8_t *v28; // r0
  uint8_t *v29; // r10
  int v30; // r2
  uint8_t *v31; // r11
  int16_t v32; // r5
  int v33; // r1
  int v34; // r3
  uint8_t *v35; // r2
  int v36; // r4
  int v37; // r1
  uint16_t v38; // r0
  uint8_t *v39; // r8
  int v40; // r3
  int v41; // r9
  int v42; // r4
  int v43; // r10
  int v44; // r7
  uint8_t *v45; // r9
  int v46; // r4
  uint8_t *v47; // r10
  int v48; // r0
  unsigned int v49; // r1
  int v50; // r0
  uint8_t v52; // [sp+Eh] [bp-6h] BYREF
  uint8_t v53[5]; // [sp+Fh] [bp-5h] BYREF

  v9 = (uint8_t)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      is_phy_ver_6();
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
          v41 = *(uint8_t *)(v15 + 1);
          alloc_tx_event(dword_139948, v41);
          v39 = (uint8_t *)(v15 + 1);
          if ( v41 == 4 )
          {
            v42 = (uint8_t)*a5;
            if ( v42 != 255 )
            {
              v43 = dword_139950;
              v44 = (uint8_t)handle_ampdu_action(
                                       (uint8_t *)(v15 + 2),
                                       a2 - a3 - 2,
                                       v53,
                                       1320 * v42 + 1212 + dword_139950);
              alloc_tx_event(dword_13994C, v44, v53[0]);
              if ( v44 )
              {
                v45 = (uint8_t *)(1320 * v42 + v43);
                if ( !v45[106] )
                {
                  if ( !v45[146] && v45[148] && v53[0] == 1 )
                    send_hci_event(v45[107], v45[146]);
                  v46 = v43 + 1320 * v42;
                  *(uint8_t *)(v46 + 146) = v44;
                  *(uint8_t *)(v46 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v38 = dispatch_command(a4, v15, *(uint8_t *)(v15 + 1));
          v9 = v38;
          if ( v38 != 33 )
          {
            v32 = (char)v38 << 8;
            v13 = 0;
            *a7 = 8;
            goto LABEL_49;
          }
          return 0;
        case 5:
          v33 = dword_139718;
          if ( *(uint8_t *)(dword_139718 + 1320 * v9 + 106) == 2
            || (v34 = *(uint8_t *)(v15 + 1), v35 = (uint8_t *)(v15 + 1), *(uint8_t *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v35 = (uint8_t *)(v15 + 1);
            if ( *(uint8_t *)(dword_139950 + 1320 * v9 + 106) )
              goto LABEL_46;
            v9 = 255;
          }
          else
          {
            *a7 = 11;
            v36 = (uint8_t)*a5;
            if ( v36 == 255 )
            {
              v32 = v34;
              v13 = 1;
              goto LABEL_50;
            }
            v37 = v33 + 1320 * v36;
            v13 = *(uint8_t *)(v37 + 106);
            if ( *(uint8_t *)(v37 + 106) )
            {
              v9 = v34;
              v13 = 1;
              goto LABEL_48;
            }
            v9 = *(uint8_t *)(v37 + 106);
          }
          if ( (unsigned int)*v35 - 6 > 1 )
          {
LABEL_88:
            v13 = 1;
            goto LABEL_47;
          }
          *a7 = 12;
          v32 = 0;
LABEL_50:
          *a7 |= v32;
          return v13;
        case 7:
          v13 = *(uint8_t *)(v15 + 1);
          if ( *(uint8_t *)(v15 + 1) )
          {
            if ( v13 != 1 )
              goto LABEL_46;
            if ( (*(uint32_t *)(dword_139730 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(uint8_t *)(v15 + 2) & 1;
              if ( (*(uint8_t *)(v15 + 2) & 1) != 0 )
              {
                ble_ll_conn_get(a4, 0xFFu);
                v13 = 0;
              }
              else
              {
                ble_ll_conn_get(a4, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(uint32_t *)(dword_139960 + 696 * a4 + 4) & 2) != 0 )
          {
            v49 = *(uint8_t *)(v15 + 2);
            if ( v49 <= 1 )
            {
              ble_ll_conn_get(a4, v49);
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
          v13 = *(uint8_t *)(v15 + 1) | *(uint8_t *)(dword_139950 + 1320 * v9 + 106);
          if ( v13 )
            goto LABEL_46;
          *a7 = 6;
          v32 = 0;
          goto LABEL_50;
        case 0x15:
          v39 = (uint8_t *)(v15 + 1);
LABEL_65:
          v40 = *v39;
          if ( v40 == 1 )
          {
            write_rf_cal_data((uint32_t *)(v15 + 2), (uint32_t *)(v15 + 10));
          }
          else
          {
            if ( v40 != 2 )
            {
LABEL_46:
              v13 = 1;
              v9 = 255;
              goto LABEL_47;
            }
            if ( (*(uint32_t *)(dword_139730 + 696 * a4 + 4) & 0x24) != 0 && *(char *)(v15 + 2) >= 0 )
            {
              ble_ll_conn_get(a4, *(uint8_t *)(v15 + 2) & 3);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v32 = (uint16_t)v9 << 8;
LABEL_49:
              if ( **(int16_t **)off_13972C < 0 && v9 == 255 )
                irq_disable_mmio_write(dword_139958, dword_139954, 2326);
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
      if ( !*((uint8_t *)off_139720 + 18) )
        return 1;
      v20 = **(uint8_t **)off_139724;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *((uint32_t *)off_139720 + 2);
      if ( !v21 )
        return 1;
      v22 = dword_139734;
      v23 = dword_139728;
      v24 = off_139738;
      v13 = 1;
      while ( 1 )
      {
        if ( *(uint8_t *)(v21 + 106) == 2 && *(uint8_t *)(v21 + 108) && !*(uint8_t *)(v21 + 1224) )
        {
          v25 = *(uint8_t *)(v21 + 107);
          v26 = *(uint16_t *)(v22 + 2 * v25);
          v27 = check_buf_range_12d7d8((uint8_t *)(a6 + 24), (uint16_t)(a2 - 24), &v52);
          v28 = (uint8_t *)(v23 + (v25 << 9) + 36);
          v29 = v27;
          v31 = check_buf_range_12d7d8(v28, (uint16_t)(v26 - 36), v53);
          if ( v53[0] )
          {
            if ( v52 )
            {
              v47 = v29 + 2;
              v48 = memcmp(v47, dword_13995C, 7);
              v30 = v52;
              if ( v48 && v52 == v53[0] )
              {
                if ( !memcmp(v47, v31 + 2, v52) )
                {
                  alloc_tx_event(dword_139964);
                  v50 = dword_13996C;
                  *(uint8_t *)off_139968 = 1;
                  mem_copy_util(v50, v24[4] + 200000);
                }
                v30 = v52;
              }
              if ( v30 && (!memcmp(v47, dword_13995C, 7) || v52 != v53[0] || memcmp(v47, v31 + 2, v52)) )
                goto LABEL_38;
            }
          }
          else if ( v52 )
          {
            return 1;
          }
          btm_chk_state(v21, a6 + 10, v30);
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
    v12 = *(uint8_t *)(dword_139718 + 1320 * v9 + 106);
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
        if ( v11 != 160 && (v11 != 176 || is_phy_ver_6()) )
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
    v17 = dword_139718 + 1320 * v9;
  }
  if ( hci_cmd_handler(4u) == 1 )
  {
    v18 = (int *)off_13971C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(uint8_t *)(v19 + 366);
  }
  if ( a4 != 255 && *(uint8_t *)(v17 + 108) )
  {
    ble_ll_conn_process(v17, a2, a6);
    return 1;
  }
  return 1;
}

