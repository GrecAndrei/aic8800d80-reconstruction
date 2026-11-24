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


extern uint32_t dword_11D37C;
extern uint32_t dword_11D380;
extern uint32_t dword_11D6E4;
extern uint32_t dword_11D6E8;
extern uint32_t dword_11D6F8;
extern uint32_t dword_11D758;
extern uint32_t off_11D384;
extern uint32_t off_11D388;
extern uint32_t off_11D38C;
extern uint32_t off_11D398;
extern uint32_t off_11D6EC;
extern uint32_t off_11D6FC;

// get_channel_config @ 0x11d0b8, size 1694 bytes
uint32_t * get_channel_config(uint32_t *result, int a2, int a3)
{
  int v3; // r8
  uint16_t v5; // r10
  int v6; // r9
  int v7; // r6
  uint32_t *v8; // r5
  int v9; // r4
  uint16_t v10; // r7
  int v11; // r7
  uint8_t *v12; // r5
  uint8_t v13; // r3
  int v14; // r9
  int v15; // r4
  unsigned int v16; // r2
  int v17; // r6
  uint16_t v18; // r2
  int v19; // r5
  int v20; // r9
  int v21; // r4
  unsigned int v22; // r3
  uint8_t *v23; // r0
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r9
  int v28; // r5
  int v29; // r4
  unsigned int v30; // r3
  uint8_t *v31; // r0
  int *v32; // r10
  int v33; // r7
  uint32_t *v34; // r5
  uint32_t *v35; // r4
  uint32_t *v36; // r9
  int v37; // r2
  int *v38; // r3
  int v39; // r3
  int v40; // r3
  uint8_t *v41; // r0
  int *v42; // r10
  uint32_t *v43; // r7
  int v44; // r3
  int v45; // r9
  uint32_t *v46; // r4
  uint32_t *v47; // r5
  int v48; // r1
  uint32_t *v49; // r3
  int v50; // r2
  int v51; // r0
  uint16_t *v52; // r0
  int *v53; // r9
  int v54; // r7
  uint32_t *v55; // r10
  uint32_t *v56; // r11
  int v57; // r6
  int v58; // r2
  int *v59; // r3
  int v60; // r3
  int v61; // r3
  int *v62; // r10
  int v63; // r7
  uint32_t *v64; // r6
  uint32_t *v65; // r5
  uint32_t *v66; // r9
  int v67; // r2
  int *v68; // r3
  int v69; // r3
  int v70; // r3
  int v71; // r0
  int v72; // r2
  int v73; // r0
  uint8_t *v74; // r0
  uint32_t *resulta; // [sp+4h] [bp-10h]
  int v76; // [sp+8h] [bp-Ch]
  int v77; // [sp+8h] [bp-Ch]

  v3 = dword_11D37C + 1320 * a3;
  if ( *(uint8_t *)(v3 + 106) == 2 )
  {
    v5 = *(uint16_t *)result;
    v6 = 696 * a2;
    v7 = dword_11D380 + 696 * a2;
    v8 = result;
    resulta = (uint32_t *)*(uint8_t *)(v7 + 36);
    v9 = a2;
    if ( resulta != (uint32_t *)1 )
    {
      if ( (v5 & 0x1404) != 0x1000 )
        return result;
      v16 = *(uint8_t *)(v7 + 35);
      *(uint8_t *)(v7 + 36) = 1;
      if ( v16 <= 0x1F )
      {
        v31 = (uint8_t *)bt_buf_alloc(73, 13, 0, 2);
        *v31 = v9;
        v31[1] = 1;
        hci_evt_send((int)v31);
        if ( !*(uint8_t *)(v7 + 36) && *(uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v32 = (int *)off_11D398;
          v33 = dword_11D37C + 1320 * *(uint8_t *)(v7 + 34);
          v34 = (uint32_t *)(dword_11D37C + 8 * (165 * *(uint8_t *)(v7 + 34) + 159));
          v35 = (uint32_t *)(dword_11D380 + 8 * (87 * (uint16_t)v9 + 78));
          v36 = (uint32_t *)(dword_11D380 + 664 + v6);
          do
          {
            if ( *(uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11D38C = 1;
              }
              ++*v32;
              ke_event_schedule_1(aCatTobe);
              list_merge(v35 - 10, v34 - 10);
              *(uint64_t *)(v33 + 1232) = *(uint64_t *)(v7 + 584);
              zero_struct(v35 - 10);
              v37 = *v32 - 1;
              if ( *v32 )
              {
                v38 = (int *)off_11D38C;
                *v32 = v37;
                v39 = *v38;
                if ( !v37 )
                {
                  if ( v39 )
                    __enable_irq();
                }
              }
            }
            v40 = *(uint32_t *)(v7 + 624);
            v33 += 8;
            v7 += 8;
            if ( v40 )
            {
              ke_event_schedule_1(aCatPs);
              list_merge(v34, v35);
              zero_struct(v35);
            }
            v35 += 2;
            v34 += 2;
          }
          while ( v35 != v36 );
          set_system_flag_1(512);
        }
      }
      v17 = dword_11D37C + 1320 * a3;
      v18 = *(uint8_t *)(v17 + 234);
      if ( !*(uint8_t *)(v17 + 234) )
      {
        v19 = (uint8_t)(a3 + 32);
        v20 = 696 * v19;
        v21 = dword_11D380 + 696 * v19;
        if ( *(uint8_t *)(v21 + 36) != 1 )
        {
          v22 = *(uint8_t *)(v21 + 35);
          *(uint8_t *)(v21 + 36) = 1;
          if ( v22 <= 0x1F )
          {
            v23 = (uint8_t *)bt_buf_alloc(73, 13, v18, 2);
            *v23 = v19;
            v23[1] = 1;
            hci_evt_send((int)v23);
            if ( *(uint8_t *)(v21 + 36) || *(uint8_t *)(v21 + 35) > 0x1Fu )
            {
              LOBYTE(v18) = *(uint8_t *)(v17 + 234);
            }
            else
            {
              v62 = (int *)off_11D6FC;
              v63 = dword_11D6E4 + 1320 * *(uint8_t *)(v21 + 34);
              v64 = (uint32_t *)(dword_11D6E4 + 8 * (165 * *(uint8_t *)(v21 + 34) + 159));
              v65 = (uint32_t *)(dword_11D6F8 - 664 + 8 * (87 * (uint8_t)(a3 + 32) + 78));
              v66 = (uint32_t *)(dword_11D6F8 + v20);
              do
              {
                if ( *(uint32_t *)(v21 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(uint32_t *)off_11D6EC = 1;
                  }
                  ++*v62;
                  ke_event_schedule_1(aCatTobe);
                  list_merge(v65 - 10, v64 - 10);
                  *(uint64_t *)(v63 + 1232) = *(uint64_t *)(v21 + 584);
                  zero_struct(v65 - 10);
                  v67 = *v62 - 1;
                  if ( *v62 )
                  {
                    v68 = (int *)off_11D6EC;
                    *v62 = v67;
                    v69 = *v68;
                    if ( !v67 )
                    {
                      if ( v69 )
                        __enable_irq();
                    }
                  }
                }
                v70 = *(uint32_t *)(v21 + 624);
                v63 += 8;
                v21 += 8;
                if ( v70 )
                {
                  ke_event_schedule_1(aCatPs);
                  list_merge(v64, v65);
                  zero_struct(v65);
                }
                v65 += 2;
                v64 += 2;
              }
              while ( v65 != v66 );
              set_system_flag_1(512);
              LOBYTE(v18) = *(uint8_t *)(dword_11D6E4 + 1320 * a3 + 234);
            }
          }
        }
      }
      v24 = v3;
      *(uint8_t *)(dword_11D37C + 1320 * a3 + 234) = v18 + 1;
      return (uint32_t *)bt_conn_get_entry(v24);
    }
    if ( (*(uint16_t *)result & 0x1404) == 0 )
    {
      v25 = *(uint8_t *)(v7 + 35);
      *(uint8_t *)(v7 + 36) = 0;
      if ( v25 <= 0x1F )
      {
        v41 = (uint8_t *)bt_buf_alloc(73, 13, 0, 2);
        *v41 = v9;
        v41[1] = 0;
        hci_evt_send((int)v41);
        if ( !*(uint8_t *)(v7 + 36) && *(uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v42 = (int *)off_11D6FC;
          v76 = v9;
          v43 = (uint32_t *)(dword_11D6E4 + 8 * (165 * *(uint8_t *)(v7 + 34) + 159));
          v44 = dword_11D6E8 + 664 + v6;
          v45 = dword_11D6E4 + 1320 * *(uint8_t *)(v7 + 34);
          v46 = (uint32_t *)(dword_11D6E8 + 8 * (87 * (uint16_t)v9 + 78));
          v47 = (uint32_t *)v44;
          do
          {
            if ( *(uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11D6EC = 1;
              }
              ++*v42;
              ke_event_schedule_1(aCatTobe);
              list_merge(v46 - 10, v43 - 10);
              *(uint64_t *)(v45 + 1232) = *(uint64_t *)(v7 + 584);
              zero_struct(v46 - 10);
              v48 = *v42 - 1;
              if ( *v42 )
              {
                v49 = off_11D6EC;
                *v42 = v48;
                if ( !v48 )
                {
                  if ( *v49 )
                    __enable_irq();
                }
              }
            }
            v50 = *(uint32_t *)(v7 + 624);
            v45 += 8;
            v7 += 8;
            if ( v50 )
            {
              ke_event_schedule_1(aCatPs);
              list_merge(v43, v46);
              zero_struct(v46);
            }
            v46 += 2;
            v43 += 2;
          }
          while ( v46 != v47 );
          v9 = v76;
          set_system_flag_1(512);
        }
      }
      txpwr_cal_entry_get(v3, v9);
      v26 = dword_11D37C + 1320 * a3;
      v27 = (uint8_t)(*(uint8_t *)(v26 + 234) - 1);
      *(uint8_t *)(v26 + 234) = v27;
      if ( !v27 )
      {
        v28 = (uint8_t)(a3 + 32);
        v29 = dword_11D380 + 696 * v28;
        if ( *(uint8_t *)(v29 + 36) )
        {
          v30 = *(uint8_t *)(v29 + 35);
          *(uint8_t *)(v29 + 36) = 0;
          if ( v30 <= 0x1F )
          {
            v52 = (uint16_t *)bt_buf_alloc(73, 13, 0, 2);
            *v52 = (uint8_t)v28;
            hci_evt_send((int)v52);
            if ( !*(uint8_t *)(v29 + 36) && *(uint8_t *)(v29 + 35) <= 0x1Fu )
            {
              v53 = (int *)off_11D6FC;
              v77 = (uint8_t)(a3 + 32);
              v54 = dword_11D6E4 + 1320 * *(uint8_t *)(v29 + 34);
              v55 = (uint32_t *)(dword_11D6E4 + 8 * (165 * *(uint8_t *)(v29 + 34) + 159));
              v56 = (uint32_t *)(dword_11D6F8 - 664 + 8 * (87 * v77 + 78));
              v57 = dword_11D6F8 + 696 * v28;
              do
              {
                if ( *(uint32_t *)(v29 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(uint32_t *)off_11D6EC = 1;
                  }
                  ++*v53;
                  ke_event_schedule_1(aCatTobe);
                  list_merge(v56 - 10, v55 - 10);
                  *(uint64_t *)(v54 + 1232) = *(uint64_t *)(v29 + 584);
                  zero_struct(v56 - 10);
                  v58 = *v53 - 1;
                  if ( *v53 )
                  {
                    v59 = (int *)off_11D6EC;
                    *v53 = v58;
                    v60 = *v59;
                    if ( !v58 )
                    {
                      if ( v60 )
                        __enable_irq();
                    }
                  }
                }
                v61 = *(uint32_t *)(v29 + 624);
                v54 += 8;
                v29 += 8;
                if ( v61 )
                {
                  ke_event_schedule_1(aCatPs);
                  list_merge(v55, v56);
                  zero_struct(v56);
                }
                v56 += 2;
                v55 += 2;
              }
              while ( (uint32_t *)v57 != v56 );
              v28 = v77;
              set_system_flag_1(512);
            }
          }
        }
        txpwr_cal_entry_get(v3, v28);
      }
      v24 = v3;
      return (uint32_t *)bt_conn_get_entry(v24);
    }
    if ( (v5 & 0xFC) == 0xA4 )
    {
      if ( (*(uint8_t *)(v7 + 53) & 2) != 0 )
      {
        *(uint8_t *)(v7 + 54) |= 1u;
        result = (uint32_t *)wlc_bsscfg_down(v3, v7, 1);
        *(uint8_t *)(v7 + 54) &= ~1u;
      }
      else
      {
        result = (uint32_t *)wlc_bsscfg_dump(v3, dword_11D380 + 696 * a2, 1);
        if ( !result )
        {
          v51 = bt_buf_alloc(74, 13, 0, 4);
          *(uint8_t *)v51 = v9;
          *(uint16_t *)(v51 + 1) = (uint8_t)resulta;
          result = hci_evt_send(v51);
        }
      }
    }
    if ( (v5 & 0x8C) == 0x88 )
    {
      v10 = (v5 & 0x300) == 0x300 ? *((uint16_t *)v8 + 15) : *((uint16_t *)v8 + 12);
      v11 = v10 & 7;
      v12 = (uint8_t *)(dword_11D380 + 696 * v9);
      if ( (*((uint8_t *)off_11D388 + *((uint8_t *)off_11D384 + v11)) & v12[310]) != 0 )
      {
        v13 = v12[53];
        if ( (v13 & 0xC) != 0 )
        {
          if ( (v12[54] & 6) == 0 )
          {
            v14 = v12[311];
            if ( (v12[53] & 8) != 0 )
            {
              v72 = v12[311];
              v12[54] = 2;
              v73 = wlc_bsscfg_down(v3, v7, v72);
              if ( v14 )
              {
                v14 -= v73;
                if ( v14 <= 0 )
                  goto LABEL_16;
              }
              v13 = v12[53];
            }
            if ( (v13 & 4) != 0 )
            {
              *(uint8_t *)(dword_11D758 + 696 * v9 + 54) = 4;
              v74 = (uint8_t *)bt_buf_alloc(74, 13, 0, 4);
              *v74 = v9;
              v74[1] = v14;
              v74[2] = 1;
              return hci_evt_send((int)v74);
            }
LABEL_16:
            v15 = dword_11D380 + 696 * v9;
            result = (uint32_t *)ble_acl_handle(*(uint8_t *)(v15 + 35), v11 | 0x10, 0, 0);
            *(uint8_t *)(v15 + 54) = 0;
          }
        }
        else if ( (v12[54] & 6) == 0 )
        {
          v71 = v12[35];
          v12[54] = 2;
          result = (uint32_t *)ble_acl_handle(v71, v11 | 0x10, 0, 0);
          v12[54] = 0;
        }
      }
    }
  }
  return result;
}
