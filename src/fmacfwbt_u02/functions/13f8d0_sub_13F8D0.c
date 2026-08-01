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

extern uint32_t off_13FC80;
extern uint32_t dword_13FC78;
extern uint32_t dword_13FC70;
extern uint32_t dword_13FC50;
extern uint32_t off_13FC54;
extern uint32_t dword_140298;
extern uint32_t dword_140278;
extern uint32_t dword_140294;
extern uint32_t dword_14028C;
extern uint32_t dword_140288;
extern uint32_t dword_140004;
extern uint32_t dword_140290;
extern uint32_t off_140284;
extern uint32_t off_140008;
extern uint32_t dword_14029C;
extern uint32_t dword_14000C;
extern uint32_t dword_14027C;
extern uint32_t dword_13FC7C;
extern uint32_t dword_140000;
extern uint32_t dword_13FFF8;
extern uint32_t dword_13FFFC;
extern uint32_t dword_140280;
extern uint32_t dword_13FC74;
extern uint32_t dword_13FC5C;
extern uint32_t dword_13FC58;
extern uint32_t dword_13FC60;
extern uint32_t dword_13FC68;
extern uint32_t off_13FC64;
extern uint32_t dword_13FC6C;

// update_connection_stats @ 0x13f8d0, size 2470 bytes
int  update_connection_stats(int a1)
{
  int16_t **v1; // r11
  unsigned int v2; // r7
  int *v3; // r8
  int v5; // r6
  int16_t v6; // r3
  int v7; // r10
  int v8; // r9
  int v9; // r5
  int16_t v10; // r0
  int v11; // r3
  unsigned int v12; // r2
  int v13; // r0
  unsigned int v14; // r0
  int16_t *v15; // r3
  int16_t v16; // r3
  int16_t v17; // r0
  unsigned int v18; // r0
  int16_t *v19; // r3
  int v20; // r0
  unsigned int v21; // r0
  int16_t *v22; // r2
  unsigned int v23; // r0
  int16_t *v24; // r2
  int v25; // r3
  int v26; // r3
  int v27; // r0
  unsigned int v28; // r0
  int16_t *v29; // r2
  unsigned int v30; // r0
  int16_t *v31; // r2
  unsigned int v32; // r3
  int v33; // r1
  unsigned int v34; // r0
  int v35; // r7
  int16_t *v36; // r5
  int *v37; // r2
  int16_t v38; // t1
  int v39; // r2
  int v40; // r3
  int result; // r0
  int v42; // r3
  unsigned int v43; // r0
  int v44; // r3
  int16_t *v45; // r1
  unsigned int v46; // r3
  int16_t v47; // r0
  int v48; // r0
  unsigned int v49; // r0
  int16_t *v50; // r2
  unsigned int v51; // r0
  int16_t *v52; // r2
  int16_t v53; // r3
  int16_t v54; // r2
  unsigned int v55; // r3
  int v56; // r1
  int v57; // r0
  unsigned int v58; // r0
  int16_t *v59; // r3
  int16_t v60; // r3
  int16_t v61; // r0
  unsigned int v62; // r0
  int16_t *v63; // r3
  int v64; // r0
  unsigned int v65; // r0
  int16_t *v66; // r2
  unsigned int v67; // r0
  int16_t *v68; // r2
  int v69; // r3
  int v70; // r3
  int v71; // r2
  int v72; // r3
  int v73; // r0
  int v74; // r1
  unsigned int v75; // r1
  unsigned int v76; // r3
  unsigned int v77; // r2
  char v78; // r0
  int v79; // r2
  unsigned int v80; // r3
  unsigned int v81; // r1
  unsigned int v82; // r3
  unsigned int v83; // r2
  int16_t v84; // r2
  int v85; // [sp+10h] [bp-1Ch]
  int v86; // [sp+14h] [bp-18h]
  unsigned int v87; // [sp+18h] [bp-14h]
  unsigned int v88; // [sp+18h] [bp-14h]
  unsigned int v89; // [sp+18h] [bp-14h]
  unsigned int v90; // [sp+18h] [bp-14h]
  unsigned int v91; // [sp+18h] [bp-14h]
  unsigned int v92; // [sp+18h] [bp-14h]
  int16_t *v93; // [sp+18h] [bp-14h]
  unsigned int v94; // [sp+18h] [bp-14h]
  unsigned int v95; // [sp+18h] [bp-14h]
  uint16_t *v96; // [sp+1Ch] [bp-10h]
  int v97; // [sp+1Ch] [bp-10h]
  unsigned int v98; // [sp+20h] [bp-Ch]
  unsigned int v99; // [sp+20h] [bp-Ch]
  unsigned int v100; // [sp+20h] [bp-Ch]
  unsigned int v101; // [sp+20h] [bp-Ch]

  v1 = (int16_t **)off_13FC80;
  v2 = *(uint8_t *)(a1 + 35);
  v3 = *(int **)(a1 + 336);
  v86 = (uint8_t)(v2 + 16);
  if ( **(int16_t **)off_13FC80 < 0 && v2 > 0x1F )
  {
    mmio_irq_clear(dword_13FC78, dword_13FC70, 2825);
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
  v85 = sub_101954() << 14;
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
        v96 = off_13FC54;
        v13 = *(uint16_t *)(a1 + 244);
        *(uint8_t *)(v12 + 169) = 4;
        v87 = rf_get_chan_index(v13);
        v14 = rf_get_chan_index((uint16_t)v96[28]);
        if ( v14 >= v87 )
          v14 = v87;
        v15 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 180) = v14;
        if ( *v15 < 0 && v14 > 7 )
          mmio_irq_clear(dword_140298, dword_140278, 2992);
        v16 = llm_bitmap_to_mask(*(uint16_t *)(a1 + 244), (uint16_t)v96[28]);
        v17 = *(uint16_t *)(a1 + 244);
        *(uint16_t *)(v5 + 200 * v2 + 170) = v16;
        v88 = rf_phy_to_power_map(v17);
        v18 = rf_phy_to_power_map(v96[28]);
        if ( v18 >= v88 )
          v18 = v88;
        v19 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 176) = v18;
        if ( *v19 < 0 && v18 > 9 )
          mmio_irq_clear(dword_140294, dword_140278, 2998);
        v89 = v5 + 200 * v2;
        v20 = *(uint16_t *)(v89 + 174) & 0xF00F;
        *(uint16_t *)(v89 + 174) = v20;
        v21 = util_find_first_zero(v20);
        v22 = *v1;
        *(uint8_t *)(v89 + 177) = v21;
        if ( *v22 < 0 && v21 > 3 && v21 != 12 )
          mmio_irq_clear(dword_14028C, dword_140278, 3010);
        v90 = v5 + 200 * v2;
        v23 = util_find_first_set(*(uint16_t *)(v90 + 174));
        v24 = *v1;
        *(uint8_t *)(v90 + 178) = v23;
        if ( *v24 < 0 && v23 > 3 && v23 != 12 )
          mmio_irq_clear(dword_140288, dword_140278, 3012);
        *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
        if ( sys_status_get_bit26() )
        {
          v25 = *(uint32_t *)(a1 + 240);
          if ( (*((uint32_t *)v96 + 12) & 0x10) != 0 && (v25 & 0x10) != 0 )
            v85 |= 0x40u;
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
        v94 = llm_rx_validate_pdu((uint8_t *)(a1 + 211));
        v43 = llm_rx_validate_pdu((uint8_t *)dword_140004);
        v44 = a1 + 211;
        if ( v43 >= v94 )
          v43 = v94;
        v45 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 180) = v43;
        if ( *v45 < 0 && v43 > 3 )
        {
          mmio_irq_clear(dword_140290, dword_140278, 3054);
          v44 = a1 + 211;
        }
        memcpy_aligned(v9 + 170 + v5, v44, 4);
        v46 = v5 + 200 * v2;
        v47 = *(uint16_t *)(v46 + 174);
        *(uint8_t *)(v46 + 170) = -1;
        v48 = v47 & 0xF00F;
        *(uint8_t *)(v46 + 176) = 7;
        *(uint16_t *)(v46 + 174) = v48;
        v49 = util_find_first_zero(v48);
        v50 = *v1;
        *(uint8_t *)(v5 + 200 * v2 + 177) = v49;
        if ( *v50 < 0 && v49 > 3 && v49 != 12 )
          mmio_irq_clear(dword_14028C, dword_140278, 3065);
        v95 = v5 + 200 * v2;
        v51 = util_find_first_set(*(uint16_t *)(v95 + 174));
        v52 = *v1;
        *(uint8_t *)(v95 + 178) = v51;
        if ( *v52 < 0 && v51 > 3 && v51 != 12 )
          mmio_irq_clear(dword_140288, dword_140278, 3067);
        *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
        if ( sys_status_get_bit26() )
        {
          v53 = *(uint16_t *)(a1 + 208);
          if ( (*((uint16_t *)off_140284 + 6) & 1) != 0 && (v53 & 1) != 0 )
            v85 |= 0x40u;
        }
        else
        {
          v53 = *(uint16_t *)(a1 + 208);
        }
        if ( (v53 & 0x800) != 0 )
          v54 = 4021;
        else
          v54 = 3839;
        *(uint16_t *)(v5 + 200 * v2 + 186) = v54;
      }
      goto LABEL_53;
    }
    v56 = *(uint8_t *)(a1 + 34);
    v57 = *(uint16_t *)(a1 + 270);
    *(uint8_t *)(v12 + 169) = 5;
    v97 = v56;
    v98 = rf_get_chan_index(v57);
    v58 = rf_get_chan_index(*((uint16_t *)off_140008 + 40));
    if ( v58 >= v98 )
      v58 = v98;
    v59 = *v1;
    *(uint8_t *)(v5 + 200 * v2 + 180) = v58;
    if ( *v59 < 0 && v58 > 7 )
      mmio_irq_clear(dword_140298, dword_140278, 2869);
    v60 = llm_bitmap_to_mask(*(uint16_t *)(a1 + 270), *((uint16_t *)off_140008 + 40));
    v61 = *(uint16_t *)(a1 + 270);
    *(uint16_t *)(v5 + 200 * v2 + 170) = v60;
    v99 = rf_phy_to_power_map2(v61);
    v62 = rf_phy_to_power_map2(*((uint16_t *)off_140008 + 40));
    if ( v62 >= v99 )
      v62 = v99;
    v63 = *v1;
    *(uint8_t *)(v5 + 200 * v2 + 176) = v62;
    if ( *v63 < 0 && v62 > 0xB )
      mmio_irq_clear(dword_14029C, dword_140278, 2875);
    v100 = v5 + 200 * v2;
    v64 = *(uint16_t *)(v100 + 174) & 0xF00F;
    *(uint16_t *)(v100 + 174) = v64;
    v65 = util_find_first_zero(v64);
    v66 = *v1;
    *(uint8_t *)(v100 + 177) = v65;
    if ( *v66 < 0 && v65 > 3 && v65 != 12 )
      mmio_irq_clear(dword_14028C, dword_140278, 2879);
    v101 = v5 + 200 * v2;
    v67 = util_find_first_set(*(uint16_t *)(v101 + 174));
    v68 = *v1;
    *(uint8_t *)(v101 + 178) = v67;
    if ( *v68 < 0 && v67 > 3 && v67 != 12 )
      mmio_irq_clear(dword_140288, dword_140278, 2881);
    *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
    if ( sys_status_get_bit26()
      && (*((uint8_t *)off_140008 + 67) & 0x20) != 0
      && (*(uint8_t *)(a1 + 309) || (*(uint8_t *)(a1 + 259) & 0x20) != 0) )
    {
      v85 |= 0x40u;
    }
    if ( (*(uint32_t *)(a1 + 4) & 4) != 0 )
    {
      v69 = *(uint32_t *)(a1 + 240) & 3;
      if ( v69 == 1 )
      {
        *(uint16_t *)(v5 + 200 * v2 + 186) = 7917;
      }
      else if ( v69 == 2 )
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
        v84 = 7935;
      else
        v84 = 3839;
      *(uint16_t *)(v5 + 200 * v2 + 186) = v84;
    }
    v70 = dword_14000C + 1320 * v97;
    v71 = *(uint8_t *)(v70 + 106);
    if ( *(uint8_t *)(v70 + 106) )
    {
      v72 = *(uint32_t *)(v70 + 468);
      *(uint32_t *)(*(uint32_t *)(a1 + 336) + 60) &= ~0x80000000;
      if ( v72 < 0 )
      {
LABEL_73:
        if ( v71 == 2 )
        {
          v8 |= 0x10020000u;
LABEL_75:
          v75 = *((uint8_t *)off_140008 + 69);
          v76 = (*(uint8_t *)(a1 + 261) >> 3) & 3;
          if ( v76 >= (v75 & 3) )
            v76 = v75 & 3;
          v77 = v5 + 200 * v2;
          *(uint8_t *)(v77 + 194) = 1;
          switch ( v76 )
          {
            case 1u:
              *(uint8_t *)(v77 + 195) = 0;
              break;
            case 2u:
              *(uint8_t *)(v77 + 195) = 1;
              break;
            case 0u:
              *(uint8_t *)(v77 + 194) = 0;
LABEL_84:
              *(uint8_t *)(v5 + 200 * v2 + 183) = (*((uint8_t *)off_140008 + 72) & *(uint8_t *)(a1 + 264) & 0x20) != 0;
LABEL_53:
              v55 = *(uint8_t *)(a1 + 309);
              v31 = *v1;
              *(uint8_t *)(v5 + 200 * v2 + 179) = v55;
              if ( *v31 < 0 && v55 > 3 )
              {
                mmio_irq_clear(dword_14027C, dword_140278, 3099);
                v55 = *(uint8_t *)(a1 + 309);
                v31 = *v1;
              }
              switch ( v55 )
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
              *(uint8_t *)(v77 + 195) = 4;
              break;
          }
          v78 = *((uint8_t *)off_140008 + 75);
          v79 = *((uint8_t *)off_140008 + 74);
          v80 = v75 >> 2;
          v81 = v5 + 200 * v2;
          *(uint8_t *)(v81 + 196) = v80 & (*(uint8_t *)(a1 + 261) >> 5) & 1;
          v82 = ((int)*(uint8_t *)(a1 + 266) >> 6) | (4 * (*(uint8_t *)(a1 + 267) & 1));
          v83 = (v79 >> 6) | (4 * (v78 & 1));
          if ( v82 >= v83 )
            LOBYTE(v82) = v83;
          *(uint8_t *)(v81 + 197) = v82;
          goto LABEL_84;
        }
LABEL_74:
        v8 |= 0x10060000u;
        goto LABEL_75;
      }
    }
    else
    {
      v72 = *(uint32_t *)(v70 + 468);
      v73 = *(uint32_t *)(a1 + 336);
      v74 = *(uint32_t *)(v73 + 60);
      if ( (v72 & 0x10000) != 0 )
      {
        *(uint32_t *)(v73 + 60) = v74 & 0x7FFFFFFF;
        if ( v72 < 0 )
          goto LABEL_74;
      }
      else
      {
        *(uint32_t *)(v73 + 60) = v74 | 0x80000000;
        if ( v72 < 0 )
          goto LABEL_74;
      }
    }
    v8 |= (HIBYTE(v72) & 0x3F) << 20;
    goto LABEL_73;
  }
  v27 = llm_decrypt_adv_payload((uint8_t *)(a1 + 192), 0);
  v91 = v5 + 200 * v2;
  *(uint16_t *)(v91 + 174) = v27;
  v28 = util_find_first_zero(v27);
  v29 = *v1;
  *(uint8_t *)(v91 + 177) = v28;
  if ( *v29 < 0 && v28 > 0xB )
    mmio_irq_clear(dword_13FC7C, dword_13FC70, 3130);
  v92 = v5 + 200 * v2;
  v30 = util_find_first_set(*(uint16_t *)(v92 + 174));
  v31 = *v1;
  *(uint8_t *)(v92 + 178) = v30;
  if ( *v31 < 0 && v30 > 0xB )
  {
    mmio_irq_clear(dword_140000, dword_13FFF8, 3132);
    v31 = *v1;
  }
  v32 = v5 + 200 * v2;
  *(uint8_t *)(v32 + 176) = -1;
  v33 = *(uint8_t *)(a1 + 309);
  *(uint8_t *)(v32 + 179) = v33;
  if ( *v31 < 0 && v33 )
  {
    mmio_irq_clear(dword_13FFFC, dword_13FFF8, 3135);
    v31 = *v1;
  }
  *(uint8_t *)(v5 + 200 * v2 + 182) = (*(uint16_t *)(a1 + 348) & 0x400) != 0;
LABEL_25:
  v93 = v31;
  v34 = scan_adv_state_switch(v7);
  *(uint16_t *)(v5 + 200 * v2 + 184) = v34;
  if ( *v93 < 0 )
  {
    if ( !v34 )
    {
      mmio_irq_clear(dword_140280, dword_140278, 3141);
      if ( **v1 >= 0 )
        goto LABEL_26;
      v34 = *(uint16_t *)(v5 + 200 * v2 + 184);
    }
    if ( v34 > 0xA )
      mmio_irq_clear(dword_13FC74, dword_13FC70, 3142);
  }
LABEL_26:
  v35 = 200 * v2;
  state_check_feature(
    4096,
    dword_13FC5C,
    dword_13FC58,
    *(uint8_t *)(a1 + 35),
    *(uint8_t *)(v5 + v35 + 169),
    *(uint8_t *)(v5 + v35 + 182),
    *(uint8_t *)(v5 + v35 + 181),
    *(uint8_t *)(v5 + v35 + 179));
  state_check_feature(
    4096,
    dword_13FC60,
    dword_13FC58,
    *(uint8_t *)(v5 + v35 + 176),
    *(uint8_t *)(v5 + v35 + 177),
    *(uint8_t *)(v5 + v35 + 178),
    *(uint8_t *)(v5 + v35 + 194),
    *(uint8_t *)(v5 + v35 + 183));
  check_connection_busy(*(uint8_t *)(a1 + 35));
  v36 = (int16_t *)(v9 + 136 + v5);
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
  *(uint32_t *)(v5 + v35) = *((uint32_t *)off_13FC64 + 4);
  v40 = dword_13FC6C;
  *v3 = v39;
  v3[3] = v86 << 10;
  v3[4] = v40;
  v3[1] = v85;
  v3[2] = v8;
  result = sys_mode_get();
  if ( result )
    v3[2] |= 0x200u;
  v42 = *(uint32_t *)(a1 + 336);
  *(uint32_t *)(v42 + 56) = *(uint32_t *)(a1 + 24);
  *(uint32_t *)(v42 + 52) = 8704;
  *(uint8_t *)(a1 + 350) |= 0x11u;
  return result;
}

