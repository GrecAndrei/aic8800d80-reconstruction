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


extern uint32_t dword_13FC50;
extern uint32_t dword_13FC68;
extern uint32_t dword_13FC6C;
extern uint32_t dword_140004;
extern uint32_t dword_14000C;
extern uint32_t off_13FC54;
extern uint32_t off_13FC80;
extern uint32_t off_140008;
extern uint32_t off_140284;

// update_connection_stats @ 0x13f8d0, size 2470 bytes
int  update_connection_stats(int a1)
{
  uint16_t **v1; // r11
  unsigned int v2; // r7
  int *v3; // r8
  int v5; // r6
  uint16_t v6; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r5
  uint16_t v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r0
  uint16_t *v15; // r3
  uint16_t v16; // r3
  uint16_t v17; // r0
  unsigned int v18; // r0
  uint16_t *v19; // r3
  int v20; // r0
  unsigned int v21; // r0
  uint16_t *v22; // r2
  unsigned int v23; // r0
  uint16_t *v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // r0
  unsigned int v28; // r0
  uint16_t *v29; // r2
  unsigned int v30; // r0
  uint16_t *v31; // r2
  unsigned int v32; // r3
  int v33; // r1
  unsigned int v34; // r0
  int v35; // r7
  uint16_t *v36; // r5
  int *v37; // r2
  uint16_t v38; // t1
  int v39; // r2
  volatile unsigned int v40; // r1
  int v41; // r3
  int result; // r0
  int v43; // r3
  unsigned int v44; // r0
  char *v45; // r3
  uint16_t *v46; // r1
  unsigned int v47; // r3
  uint16_t v48; // r0
  int v49; // r0
  unsigned int v50; // r0
  uint16_t *v51; // r2
  unsigned int v52; // r0
  uint16_t *v53; // r2
  uint16_t v54; // r3
  uint16_t v55; // r2
  unsigned int v56; // r3
  int v57; // r1
  int v58; // r0
  unsigned int v59; // r0
  uint16_t *v60; // r3
  uint16_t v61; // r3
  uint16_t v62; // r0
  unsigned int v63; // r0
  uint16_t *v64; // r3
  int v65; // r0
  unsigned int v66; // r0
  uint16_t *v67; // r2
  unsigned int v68; // r0
  uint16_t *v69; // r2
  int v70; // r3
  int v71; // r3
  int v72; // r2
  int v73; // r3
  int v74; // r0
  int v75; // r1
  unsigned int v76; // r1
  unsigned int v77; // r3
  unsigned int v78; // r2
  char v79; // r0
  int v80; // r2
  unsigned int v81; // r3
  unsigned int v82; // r1
  unsigned int v83; // r3
  unsigned int v84; // r2
  uint16_t v85; // r2
  int v86; // [sp+10h] [bp-1Ch]
  int v87; // [sp+14h] [bp-18h]
  unsigned int v88; // [sp+18h] [bp-14h]
  unsigned int v89; // [sp+18h] [bp-14h]
  unsigned int v90; // [sp+18h] [bp-14h]
  unsigned int v91; // [sp+18h] [bp-14h]
  unsigned int v92; // [sp+18h] [bp-14h]
  unsigned int v93; // [sp+18h] [bp-14h]
  uint16_t *v94; // [sp+18h] [bp-14h]
  unsigned int v95; // [sp+18h] [bp-14h]
  unsigned int v96; // [sp+18h] [bp-14h]
  uint16_t *v97; // [sp+1Ch] [bp-10h]
  int v98; // [sp+1Ch] [bp-10h]
  char *a2; // [sp+20h] [bp-Ch]
  char *a2a; // [sp+20h] [bp-Ch]
  char *a2b; // [sp+20h] [bp-Ch]
  char *a2c; // [sp+20h] [bp-Ch]

  v1 = (uint16_t **)off_13FC80;
  v2 = *(uint8_t *)(a1 + 35);
  v3 = *(int **)(a1 + 336);
  v87 = (uint8_t)(v2 + 16);
  if ( **(uint16_t **)off_13FC80 < 0 && v2 > 0x1F )
  {
    mmio_irq_clear((int)aStaStaidNxRemo, (int)aRcInit_0, 2825);
    v2 = *(uint8_t *)(a1 + 35);
  }
  v5 = dword_13FC50;
  if ( (*(uint32_t *)(a1 + 4) & 0x40) != 0 )
    v6 = 0;
  else
    v6 = 1024;
  v7 = dword_13FC50 + 200 * v2;
  *(uint16_t *)(a1 + 348) = v6;
  *(uint32_t *)(a1 + 340) = v7;
  v86 = irq47_status_handler() << 14;
  v8 = get_hw_flash_size();
  memset_byte((int *)(v5 + 200 * v2), 0, 0xC8u);
  v9 = 200 * v2;
  if ( (*(uint32_t *)(a1 + 4) & 2) != 0 )
  {
    v10 = llm_decrypt_adv_payload((uint8_t *)(a1 + 192), 0);
    v11 = *(uint32_t *)(a1 + 4);
    v12 = v5 + 200 * v2;
    *(uint16_t *)(v12 + 174) = v10;
    if ( (v11 & 0x20) == 0 )
    {
      if ( (v11 & 4) != 0 )
      {
        v97 = off_13FC54;
        v13 = *(uint16_t *)(a1 + 244);
        *(uint8_t *)(v12 + 169) = 4;
        v88 = rf_get_chan_index(v13);
        v14 = rf_get_chan_index((uint16_t)v97[28]);
        if ( v14 >= v88 )
          v14 = v88;
        v15 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 180) = v14;
        if ( *v15 < 0 && v14 > 7 )
          mmio_irq_clear((int)aRcSsNoSs8, (int)aRcInit_0, 2992);
        v16 = llm_bitmap_to_mask(*(uint16_t *)(a1 + 244), (uint16_t)v97[28]);
        v17 = *(uint16_t *)(a1 + 244);
        *(uint16_t *)(v5 + 200 * v2 + 170) = v16;
        v89 = rf_phy_to_power_map(v17);
        v18 = rf_phy_to_power_map(v97[28]);
        if ( v18 >= v89 )
          v18 = v89;
        v19 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 176) = v18;
        if ( *v19 < 0 && v18 > 9 )
          mmio_irq_clear((int)aRcSsMcsMax10, (int)aRcInit_0, 2998);
        v90 = v5 + 200 * v2;
        v20 = *(uint16_t *)(v90 + 174) & 0xF00F;
        *(uint16_t *)(v90 + 174) = v20;
        v21 = util_find_first_zero(v20);
        v22 = *v1;
        *(uint8_t *)(v90 + 177) = v21;
        if ( *v22 < 0 && v21 > 3 && v21 != 12 )
          mmio_irq_clear((int)aRcSsRIdxMinHwR, (int)aRcInit_0, 3010);
        v91 = v5 + 200 * v2;
        v23 = util_find_first_set(*(uint16_t *)(v91 + 174));
        v24 = *v1;
        *(uint8_t *)(v91 + 178) = v23;
        if ( *v24 < 0 && v23 > 3 && v23 != 12 )
          mmio_irq_clear((int)aRcSsRIdxMaxHwR, (int)aRcInit_0, 3012);
        *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
        if ( sys_status_get_bit26() )
        {
          v25 = *(uint32_t *)(a1 + 240);
          if ( (*((uint32_t *)v97 + 12) & 0x10) != 0 && (v25 & 0x10) != 0 )
            v86 |= 0x40u;
        }
        else
        {
          v25 = *(uint32_t *)(a1 + 240);
        }
        v26 = v25 & 3;
        if ( v26 == 1 )
        {
          *(uint16_t *)(v5 + 200 * v2 + 186) = 7917;
        }
        else if ( v26 == 2 )
        {
          *(uint16_t *)(v5 + 200 * v2 + 186) = 11380;
        }
        else
        {
          *(uint16_t *)(v5 + 200 * v2 + 186) = 3821;
        }
      }
      else
      {
        *(uint8_t *)(v12 + 169) = 2;
        v95 = llm_rx_validate_pdu((uint8_t *)(a1 + 211));
        v44 = llm_rx_validate_pdu((uint8_t *)dword_140004);
        v45 = (char *)(a1 + 211);
        if ( v44 >= v95 )
          v44 = v95;
        v46 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 180) = v44;
        if ( *v46 < 0 && v44 > 3 )
        {
          mmio_irq_clear((int)aRcSsNoSs3, (int)aRcInit_0, 3054);
          v45 = (char *)(a1 + 211);
        }
        memcpy_aligned((char *)(v9 + 170 + v5), v45, 4u);
        v47 = v5 + 200 * v2;
        v48 = *(uint16_t *)(v47 + 174);
        *(uint8_t *)(v47 + 170) = -1;
        v49 = v48 & 0xF00F;
        *(uint8_t *)(v47 + 176) = 7;
        *(uint16_t *)(v47 + 174) = v49;
        v50 = util_find_first_zero(v49);
        v51 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 177) = v50;
        if ( *v51 < 0 && v50 > 3 && v50 != 12 )
          mmio_irq_clear((int)aRcSsRIdxMinHwR, (int)aRcInit_0, 3065);
        v96 = v5 + 200 * v2;
        v52 = util_find_first_set(*(uint16_t *)(v96 + 174));
        v53 = *v1;
        *(uint8_t *)(v96 + 178) = v52;
        if ( *v53 < 0 && v52 > 3 && v52 != 12 )
          mmio_irq_clear((int)aRcSsRIdxMaxHwR, (int)aRcInit_0, 3067);
        *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
        if ( sys_status_get_bit26() )
        {
          v54 = *(uint16_t *)(a1 + 208);
          if ( (*((uint16_t *)off_140284 + 6) & 1) != 0 && (v54 & 1) != 0 )
            v86 |= 0x40u;
        }
        else
        {
          v54 = *(uint16_t *)(a1 + 208);
        }
        if ( (v54 & 0x800) != 0 )
          v55 = 4021;
        else
          v55 = 3839;
        *(uint16_t *)(v5 + 200 * v2 + 186) = v55;
      }
      goto LABEL_53;
    }
    v57 = *(uint8_t *)(a1 + 34);
    v58 = *(uint16_t *)(a1 + 270);
    *(uint8_t *)(v12 + 169) = 5;
    v98 = v57;
    a2 = (char *)rf_get_chan_index(v58);
    v59 = rf_get_chan_index(*((uint16_t *)off_140008 + 40));
    if ( v59 >= (unsigned int)a2 )
      v59 = (unsigned int)a2;
    v60 = *v1;
    *(uint8_t *)(v5 + 200 * v2 + 180) = v59;
    if ( *v60 < 0 && v59 > 7 )
      mmio_irq_clear((int)aRcSsNoSs8, (int)aRcInit_0, 2869);
    v61 = llm_bitmap_to_mask(*(uint16_t *)(a1 + 270), *((uint16_t *)off_140008 + 40));
    v62 = *(uint16_t *)(a1 + 270);
    *(uint16_t *)(v5 + 200 * v2 + 170) = v61;
    a2a = (char *)rf_phy_to_power_map2(v62);
    v63 = rf_phy_to_power_map2(*((uint16_t *)off_140008 + 40));
    if ( v63 >= (unsigned int)a2a )
      v63 = (unsigned int)a2a;
    v64 = *v1;
    *(uint8_t *)(v5 + 200 * v2 + 176) = v63;
    if ( *v64 < 0 && v63 > 0xB )
      mmio_irq_clear((int)aRcSsMcsMax12, (int)aRcInit_0, 2875);
    a2b = (char *)(v5 + 200 * v2);
    v65 = *((uint16_t *)a2b + 87) & 0xF00F;
    *((uint16_t *)a2b + 87) = v65;
    v66 = util_find_first_zero(v65);
    v67 = *v1;
    a2b[177] = v66;
    if ( *v67 < 0 && v66 > 3 && v66 != 12 )
      mmio_irq_clear((int)aRcSsRIdxMinHwR, (int)aRcInit_0, 2879);
    a2c = (char *)(v5 + 200 * v2);
    v68 = util_find_first_set(*((uint16_t *)a2c + 87));
    v69 = *v1;
    a2c[178] = v68;
    if ( *v69 < 0 && v68 > 3 && v68 != 12 )
      mmio_irq_clear((int)aRcSsRIdxMaxHwR, (int)aRcInit_0, 2881);
    *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
    if ( sys_status_get_bit26()
      && (*((uint8_t *)off_140008 + 67) & 0x20) != 0
      && (*(uint8_t *)(a1 + 309) || (*(uint8_t *)(a1 + 259) & 0x20) != 0) )
    {
      v86 |= 0x40u;
    }
    if ( (*(uint32_t *)(a1 + 4) & 4) != 0 )
    {
      v70 = *(uint32_t *)(a1 + 240) & 3;
      if ( v70 == 1 )
      {
        *(uint16_t *)(v5 + 200 * v2 + 186) = 7917;
      }
      else if ( v70 == 2 )
      {
        *(uint16_t *)(v5 + 200 * v2 + 186) = 11380;
      }
      else
      {
        *(uint16_t *)(v5 + 200 * v2 + 186) = 3821;
      }
    }
    else
    {
      if ( (*(uint16_t *)(a1 + 208) & 0x800) != 0 )
        v85 = 7935;
      else
        v85 = 3839;
      *(uint16_t *)(v5 + 200 * v2 + 186) = v85;
    }
    v71 = dword_14000C + 1320 * v98;
    v72 = *(uint8_t *)(v71 + 106);
    if ( *(uint8_t *)(v71 + 106) )
    {
      v73 = *(uint32_t *)(v71 + 468);
      *(uint32_t *)(*(uint32_t *)(a1 + 336) + 60) &= ~0x80000000;
      if ( v73 < 0 )
      {
LABEL_73:
        if ( v72 == 2 )
        {
          v8 |= 0x10020000u;
LABEL_75:
          v76 = *((uint8_t *)off_140008 + 69);
          v77 = (*(uint8_t *)(a1 + 261) >> 3) & 3;
          if ( v77 >= (v76 & 3) )
            v77 = v76 & 3;
          v78 = v5 + 200 * v2;
          *(uint8_t *)(v78 + 194) = 1;
          switch ( v77 )
          {
            case 1u:
              *(uint8_t *)(v78 + 195) = 0;
              break;
            case 2u:
              *(uint8_t *)(v78 + 195) = 1;
              break;
            case 0u:
              *(uint8_t *)(v78 + 194) = 0;
LABEL_84:
              *(uint8_t *)(v5 + 200 * v2 + 183) = (*((uint8_t *)off_140008 + 72) & *(uint8_t *)(a1 + 264) & 0x20) != 0;
LABEL_53:
              v56 = *(uint8_t *)(a1 + 309);
              v31 = *v1;
              *(uint8_t *)(v5 + 200 * v2 + 179) = v56;
              if ( *v31 < 0 && v56 > 3 )
              {
                mmio_irq_clear((int)aRcSsBwMaxBw160, (int)aRcInit_0, 3099);
                v56 = *(uint8_t *)(a1 + 309);
                v31 = *v1;
              }
              switch ( v56 )
              {
                case 0u:
                  if ( (*(uint16_t *)(a1 + 208) & 0x20) != 0 )
                    goto LABEL_86;
                  break;
                case 1u:
                  if ( (*(uint16_t *)(a1 + 208) & 0x40) != 0 )
                    goto LABEL_86;
                  break;
                case 2u:
                  if ( (*(uint32_t *)(a1 + 240) & 0x20) != 0 )
                    goto LABEL_86;
                  break;
                case 3u:
                  if ( (*(uint32_t *)(a1 + 240) & 0x40) != 0 )
LABEL_86:
                    *(uint8_t *)(v5 + 200 * v2 + 181) = 1;
                  break;
                default:
                  goto LABEL_25;
              }
              goto LABEL_25;
            default:
              *(uint8_t *)(v78 + 195) = 4;
              break;
          }
          v79 = *((uint8_t *)off_140008 + 75);
          v80 = *((uint8_t *)off_140008 + 74);
          v81 = v76 >> 2;
          v82 = v5 + 200 * v2;
          *(uint8_t *)(v82 + 196) = v81 & (*(uint8_t *)(a1 + 261) >> 5) & 1;
          v83 = ((int)*(uint8_t *)(a1 + 266) >> 6) | (4 * (*(uint8_t *)(a1 + 267) & 1));
          v84 = (v80 >> 6) | (4 * (v79 & 1));
          if ( v83 >= v84 )
            LOBYTE(v83) = v84;
          *(uint8_t *)(v82 + 197) = v83;
          goto LABEL_84;
        }
LABEL_74:
        v8 |= 0x10060000u;
        goto LABEL_75;
      }
    }
    else
    {
      v73 = *(uint32_t *)(v71 + 468);
      v74 = *(uint32_t *)(a1 + 336);
      v75 = *(uint32_t *)(v74 + 60);
      if ( (v73 & 0x10000) != 0 )
      {
        *(uint32_t *)(v74 + 60) = v75 & 0x7FFFFFFF;
        if ( v73 < 0 )
          goto LABEL_74;
      }
      else
      {
        *(uint32_t *)(v74 + 60) = v75 | 0x80000000;
        if ( v73 < 0 )
          goto LABEL_74;
      }
    }
    v8 |= (HIBYTE(v73) & 0x3F) << 20;
    goto LABEL_73;
  }
  v27 = llm_decrypt_adv_payload((uint8_t *)(a1 + 192), 0);
  v92 = v5 + 200 * v2;
  *(uint16_t *)(v92 + 174) = v27;
  v28 = util_find_first_zero(v27);
  v29 = *v1;
  *(uint8_t *)(v92 + 177) = v28;
  if ( *v29 < 0 && v28 > 0xB )
    mmio_irq_clear((int)aRcSsRIdxMinMac, (int)aRcInit_0, 3130);
  v93 = v5 + 200 * v2;
  v30 = util_find_first_set(*(uint16_t *)(v93 + 174));
  v31 = *v1;
  *(uint8_t *)(v93 + 178) = v30;
  if ( *v31 < 0 && v30 > 0xB )
  {
    mmio_irq_clear((int)aRcSsRIdxMaxMac, (int)aRcInit_0, 3132);
    v31 = *v1;
  }
  v32 = v5 + 200 * v2;
  *(uint8_t *)(v32 + 176) = -1;
  v33 = *(uint8_t *)(a1 + 309);
  *(uint8_t *)(v32 + 179) = v33;
  if ( *v31 < 0 && v33 )
  {
    mmio_irq_clear((int)aRcSsBwMaxBw20m, (int)aRcInit_0, 3135);
    v31 = *v1;
  }
  *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
LABEL_25:
  v94 = v31;
  v34 = scan_adv_state_switch(v7);
  *(uint16_t *)(v5 + 200 * v2 + 184) = v34;
  if ( *v94 < 0 )
  {
    if ( !v34 )
    {
      mmio_irq_clear((int)aRcSsNoSamples1, (int)aRcInit_0, 3141);
      if ( **v1 >= 0 )
        goto LABEL_26;
      v34 = *(uint16_t *)(v5 + 200 * v2 + 184);
    }
    if ( v34 > 0xA )
      mmio_irq_clear((int)aRcSsNoSamplesR, (int)aRcInit_0, 3142);
  }
LABEL_26:
  v35 = 200 * v2;
  state_check_feature(
    4096,
    "%s: station_id=%i format_mod=%i pre_type=%i short_gi=%i max_bw=%i\n",
    aRcInit,
    *(uint8_t *)(a1 + 35),
    *(uint8_t *)(v5 + v35 + 169),
    *(uint8_t *)(v5 + v35 + 182),
    *(uint8_t *)(v5 + v35 + 181),
    *(uint8_t *)(v5 + v35 + 179));
  state_check_feature(
    4096,
    "%s: mcs_max=%i r_idx_min=%i r_idx_max=%i dcm=%i ersu_ru106=%i\n",
    aRcInit,
    *(uint8_t *)(v5 + v35 + 176),
    *(uint8_t *)(v5 + v35 + 177),
    *(uint8_t *)(v5 + v35 + 178),
    *(uint8_t *)(v5 + v35 + 194),
    *(uint8_t *)(v5 + v35 + 183));
  check_connection_busy(*(uint8_t *)(a1 + 35));
  v36 = (uint16_t *)(v9 + 136 + v5);
  v37 = v3 + 5;
  do
  {
    v38 = *v36++;
    *v37++ = *(uint16_t *)(v35 + 12 * (uint8_t)v38 + v5 + 10) | 0x40000000;
  }
  while ( v3 + 9 != v37 );
  *(uint16_t *)(v5 + v35 + 192) = 0;
  scan_set_adv_flag(v7);
  v39 = dword_13FC68;
  v40 = (*(volatile uint32_t *)0x40501010u);
  *(uint32_t *)(v5 + v35) = v40;
  v41 = dword_13FC6C;
  *v3 = v39;
  v3[3] = v87 << 10;
  v3[4] = v41;
  v3[1] = v86;
  v3[2] = v8;
  result = sys_mode_get();
  if ( result )
    v3[2] |= 0x200u;
  v43 = *(uint32_t *)(a1 + 336);
  *(uint32_t *)(v43 + 56) = *(uint32_t *)(a1 + 24);
  *(uint32_t *)(v43 + 52) = 8704;
  *(uint8_t *)(a1 + 350) |= 0x11u;
  return result;
}
