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


extern uint32_t dword_139958;
extern uint32_t dword_139968;
extern uint32_t dword_139970;
extern uint32_t dword_139974;
extern uint32_t dword_139B38;
extern uint32_t dword_139B48;
extern uint32_t off_13995C;
extern uint32_t off_139960;
extern uint32_t off_139964;
extern uint32_t off_13996C;

// rf_cal_config @ 0x139688, size 1192 bytes
int  rf_cal_config(char a1, int a2, int a3, int a4, uint8_t *a5, int a6, uint16_t *a7, uint8_t *a8)
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
  int v23; // r7
  int v24; // r9
  uint16_t v25; // r6
  uint8_t *v26; // r0
  int v27; // r1
  uint8_t *v28; // r6
  uint8_t *v29; // r9
  uint16_t v30; // r5
  int v31; // r1
  int v32; // r3
  uint8_t *v33; // r2
  int v34; // r4
  int v35; // r1
  uint16_t v36; // r0
  uint8_t *v37; // r8
  int v38; // r3
  int v39; // r9
  int v40; // r4
  int v41; // r10
  int v42; // r7
  uint8_t *v43; // r9
  int v44; // r4
  unsigned int v45; // r6
  unsigned int v46; // r1
  uint8_t a3a; // [sp+Eh] [bp-2h] BYREF
  uint8_t v49; // [sp+Fh] [bp-1h] BYREF

  v9 = (uint8_t)*a5;
  if ( v9 == 255 )
  {
    v16 = a1 & 0xFC;
    if ( v16 == 176 )
    {
      is_pll_freq_6();
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
          ke_event_schedule_1("rx spectrum action: action code=%d\n", v39);
          v37 = (uint8_t *)(v15 + 1);
          if ( v39 == 4 )
          {
            v40 = (uint8_t)*a5;
            if ( v40 != 255 )
            {
              v41 = dword_139B38;
              v42 = (uint8_t)rf_parse_cal_entry(v15 + 2, a2 - a3 - 2, &v49, 1320 * v40 + 1212 + dword_139B38);
              ke_event_schedule_1("csa count=%d, mode=%d!\n", v42, v49);
              if ( v42 )
              {
                v43 = (uint8_t *)(1320 * v40 + v41);
                if ( !v43[106] )
                {
                  if ( !v43[146] && v43[148] && v49 == 1 )
                    mmio_write_phy(v43[107], 0);
                  v44 = v41 + 1320 * v40;
                  *(uint8_t *)(v44 + 146) = v42;
                  *(uint8_t *)(v44 + 148) = 1;
                }
              }
            }
          }
          goto LABEL_65;
        case 3:
          v36 = rf_set_mode(a4, (uint16_t *)v15, *(uint8_t *)(v15 + 1));
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
          v31 = dword_139958;
          if ( *(uint8_t *)(dword_139958 + 1320 * v9 + 106) == 2
            || (v32 = *(uint8_t *)(v15 + 1), v33 = (uint8_t *)(v15 + 1), *(uint8_t *)(v15 + 1)) )
          {
            v13 = 1;
LABEL_84:
            if ( v9 == 255 )
              goto LABEL_88;
            v33 = (uint8_t *)(v15 + 1);
            if ( *(uint8_t *)(dword_139B38 + 1320 * v9 + 106) )
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
            if ( (*(uint32_t *)(dword_139970 + 696 * a4 + 4) & 2) != 0 )
            {
              v13 = *(uint8_t *)(v15 + 2) & 1;
              if ( (*(uint8_t *)(v15 + 2) & 1) != 0 )
              {
                rf_config_chan_table(a4, 0xFFu, 0);
                v13 = 0;
              }
              else
              {
                rf_config_chan_table(a4, 0xFFu, 0xFFu);
              }
              v9 = 255;
              goto LABEL_47;
            }
          }
          else if ( (*(uint32_t *)(dword_139B48 + 696 * a4 + 4) & 2) != 0 )
          {
            v46 = *(uint8_t *)(v15 + 2);
            if ( v46 <= 1 )
            {
              rf_config_chan_table(a4, v46, 0xFFu);
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
          v13 = *(uint8_t *)(v15 + 1) | *(uint8_t *)(dword_139B38 + 1320 * v9 + 106);
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
            rf_config_write((uint32_t *)(v15 + 2), (uint32_t *)(v15 + 10));
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
            if ( (*(uint32_t *)(dword_139970 + 696 * a4 + 4) & 0x24) != 0 && *(char *)(v15 + 2) >= 0 )
            {
              rf_config_chan_table(a4, *(uint8_t *)(v15 + 2) & 3, *(uint8_t *)(v15 + 2) >> 4);
              v13 = 0;
              v9 = 255;
LABEL_47:
              if ( *a7 == 255 )
                return v13;
LABEL_48:
              v30 = (uint16_t)v9 << 8;
LABEL_49:
              if ( **(uint16_t **)off_13996C < 0 && v9 == 255 )
                mmio_irq_clear((int)aTaskIdx0xff, (int)aRxuMgtRouteAct, 2326);
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
      if ( !*((uint8_t *)off_139960 + 18) )
        return 1;
      v20 = **(uint8_t **)off_139964;
      if ( (unsigned int)(v20 - 1) > 1 && v20 != 4 )
        return 1;
      v21 = *((uint32_t *)off_139960 + 2);
      if ( !v21 )
        return 1;
      v22 = dword_139974;
      v23 = (uint16_t)(a2 - 24);
      v13 = 1;
      while ( 1 )
      {
        if ( *(uint8_t *)(v21 + 106) != 2 || !*(uint8_t *)(v21 + 108) || *(uint8_t *)(v21 + 1224) )
          goto LABEL_38;
        v24 = *(uint8_t *)(v21 + 107);
        v25 = *(uint16_t *)(v22 + 2 * v24);
        v26 = find_char_1((uint8_t *)(a6 + 24), v23, &a3a);
        v27 = (uint16_t)(v25 - 36);
        v28 = v26;
        v29 = find_char_1((uint8_t *)(dword_139968 + (v24 << 9)), v27, &v49);
        if ( v49 )
        {
          if ( a3a )
          {
            v45 = (unsigned int)(v28 + 2);
            if ( !memcpy_1(v45, (unsigned int)aDirect, 7u)
              || a3a != v49
              || memcpy_1(v45, (unsigned int)(v29 + 2), a3a) )
            {
              goto LABEL_38;
            }
          }
        }
        else if ( a3a )
        {
          return 1;
        }
        rx_state_check(v21, (char *)(a6 + 10));
        v13 = 0;
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
    v12 = *(uint8_t *)(dword_139958 + 1320 * v9 + 106);
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
        if ( v11 != 160 && (v11 != 176 || is_pll_freq_6()) )
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
    v17 = dword_139958 + 1320 * v9;
  }
  if ( hci_cmd_send_short(4u) == 1 )
  {
    v18 = (int *)off_13995C;
    *a8 = 1;
    v19 = *v18;
    *a7 = 4;
    *a5 = *(uint8_t *)(v19 + 366);
  }
  if ( a4 != 255 && *(uint8_t *)(v17 + 108) )
  {
    rf_calibrate_init(v17, a2, a6);
    return 1;
  }
  return 1;
}
