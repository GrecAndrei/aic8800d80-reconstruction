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

extern uint32_t off_123E50;
extern uint32_t off_123E24;
extern uint32_t dword_123E28;
extern uint32_t off_123E20;
extern uint32_t dword_1244E8;
extern uint32_t dword_1244E4;
extern uint32_t off_124194;
extern uint32_t off_1241D0;
extern uint32_t off_1244F4;
extern uint32_t dword_1244F8;
extern uint32_t off_1241CC;
extern uint32_t off_1241C8;
extern uint32_t dword_1241C4;
extern uint32_t dword_124180;
extern uint32_t off_1241BC;
extern uint32_t off_1241C0;
extern uint32_t dword_1241B0;
extern uint32_t off_1241B8;
extern uint32_t off_1241B4;
extern uint32_t off_1241D4;
extern uint32_t off_124184;
extern uint32_t dword_124188;
extern uint32_t off_124190;
extern uint32_t off_12418C;
extern uint32_t dword_124828;
extern uint32_t dword_1241D8;
extern uint32_t off_1244EC;
extern uint32_t off_124838;
extern uint32_t dword_124840;
extern uint32_t dword_12483C;
extern uint32_t off_124520;
extern uint32_t off_124814;
extern uint32_t off_124198;
extern uint32_t off_124834;
extern uint32_t dword_124510;
extern uint32_t off_124514;
extern uint32_t dword_124818;
extern uint32_t off_124810;
extern uint32_t off_12481C;
extern uint32_t off_124844;
extern uint32_t off_124820;
extern uint32_t off_124824;
extern uint32_t off_1244F0;
extern uint32_t off_12419C;
extern uint32_t off_1241A0;
extern uint32_t off_12450C;
extern uint32_t off_124508;
extern uint32_t off_1241A4;
extern uint32_t off_1241A8;
extern uint32_t off_124504;
extern uint32_t off_1241AC;
extern uint32_t off_124518;
extern uint32_t off_12451C;
extern uint32_t off_124530;
extern uint32_t off_124524;
extern uint32_t off_124528;
extern uint32_t dword_12452C;
extern uint32_t off_12482C;
extern uint32_t dword_124830;
extern uint32_t off_123E48;
extern uint32_t off_123E44;
extern uint32_t dword_1244FC;
extern uint32_t off_124500;
extern uint32_t dword_123E38;
extern uint32_t dword_123E34;
extern uint32_t dword_123E3C;
extern uint32_t dword_123E4C;
extern uint32_t dword_123E40;
extern uint32_t dword_123E30;
extern uint32_t dword_123E2C;

// rf_calibrate @ 0x123b4c, size 3268 bytes
// write access to const memory has been detected, the output may be wrong!
int  rf_calibrate(unsigned int a1, uint8_t *a2, uint32_t *a3, int a4)
{
  int v8; // r0
  int v9; // r1
  int16_t **v11; // r8
  int v12; // r3
  uint8_t *v13; // r5
  int v14; // r0
  uint8_t *v15; // r7
  int v16; // r6
  char v17; // r7
  int v18; // r1
  unsigned int v19; // r2
  signed int v20; // r3
  unsigned int v21; // r8
  int16_t v22; // lr
  int v23; // r2
  int v24; // r3
  int16_t v25; // r1
  int v26; // r2
  int v27; // r3
  uint8_t *v28; // r0
  int v29; // r11
  int v30; // r10
  uint8_t *v31; // r9
  int v32; // r0
  int v33; // r2
  int v34; // r1
  int v35; // r7
  int v36; // s16
  uint32_t *v37; // r1
  int v38; // r3
  int v39; // r12
  uint32_t *v40; // r0
  int v41; // r0
  int v42; // r3
  uint32_t *v43; // r3
  int v44; // r2
  int v45; // r2
  int v46; // r2
  int v47; // r3
  uint32_t *v48; // r3
  int v49; // r2
  char *v50; // r3
  int v51; // r1
  int v52; // r0
  int v53; // zf
  char *v54; // r5
  int v55; // r2
  unsigned int v56; // r1
  int v57; // r0
  uint32_t *v58; // r2
  int v59; // r0
  int v60; // r6
  int v61; // r2
  unsigned int v62; // r0
  uint8_t *v63; // r6
  int v64; // r1
  unsigned int v65; // r7
  uint8_t *v66; // r3
  uint8_t *v67; // r2
  int v68; // r0
  int v69; // r0
  int v70; // r3
  int v71; // r1
  uint8_t *v72; // r2
  int v73; // r0
  int v74; // r1
  uint8_t *v75; // r3
  uint32_t *v76; // lr
  int v77; // r12
  uint32_t *v78; // r2
  int v79; // r0
  uint32_t *v80; // r3
  uint8_t *v81; // r3
  int v82; // r2
  uint8_t *v83; // r3
  int v84; // r0
  int v85; // r7
  int *v86; // r12
  int v87; // r0
  int v88; // r1
  uint8_t *v89; // r3
  uint32_t *v90; // r12
  uint32_t *v91; // r2
  int v92; // r0
  int v93; // r3
  uint8_t *v94; // r8
  int v95; // r0
  int v96; // r2
  uint32_t *v97; // r2
  uint32_t *v98; // r0
  int v99; // r1
  uint8_t *v100; // r8
  uint8_t *v101; // r0
  int *v102; // r1
  unsigned int v103; // r12
  unsigned int v104; // r3
  int v105; // r0
  uint8_t *v106; // r3
  int *v107; // r12
  unsigned int v108; // r3
  unsigned int v109; // r1
  int v110; // r0
  int v111; // r6
  int v112; // r5
  int v113; // r4
  unsigned int v114; // r7
  int v115; // r0
  int v116; // r6
  int v117; // r5
  int v118; // r5
  int v119; // r4
  int v120; // r6
  int v121; // r0
  int v122; // r4
  int v123; // r0
  int v124; // r6
  int v125; // r5
  int v126; // r3
  int v127; // [sp+Ch] [bp-18h]
  uint8_t *v128; // [sp+Ch] [bp-18h]
  uint8_t *v129; // [sp+Ch] [bp-18h]
  char v130; // [sp+Ch] [bp-18h]
  uint8_t v131; // [sp+Ch] [bp-18h]
  int v132; // [sp+10h] [bp-14h]
  int v133; // [sp+10h] [bp-14h]
  int v134; // [sp+14h] [bp-10h]
  int v135; // [sp+14h] [bp-10h]
  uint8_t v136[8]; // [sp+1Ch] [bp-8h] BYREF

  v8 = hci_cmd_handler(a3);
  if ( !v8 )
  {
    v11 = (int16_t **)off_123E50;
    v12 = **(int16_t **)off_123E50;
    if ( v12 >= 0 )
    {
      if ( a1 <= 0x3B )
      {
        if ( a1 > 5 )
        {
          switch ( a1 )
          {
            case 6u:
              goto LABEL_76;
            case 8u:
              goto LABEL_70;
            case 0xEu:
              goto LABEL_68;
            case 0x10u:
              goto LABEL_67;
            case 0x12u:
              goto LABEL_66;
            case 0x14u:
              goto LABEL_63;
            case 0x16u:
              goto LABEL_53;
            case 0x18u:
              goto LABEL_52;
            case 0x1Cu:
              goto LABEL_75;
            case 0x1Eu:
              goto LABEL_33;
            case 0x20u:
              goto LABEL_32;
            case 0x28u:
              goto LABEL_27;
            case 0x30u:
              goto LABEL_26;
            case 0x3Bu:
              goto LABEL_25;
            default:
              v15 = off_123E24;
              v16 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v15 = off_123E24;
        *((uint8_t *)off_123E24 + 48) = 0;
        v16 = abs_i32(*(uint32_t *)a2);
        if ( v16 )
        {
          rf_is_ready(*(uint32_t *)a2);
          v16 = 0;
        }
        else if ( v15[49] )
        {
          v15[49] = 0;
          if ( patch_check_ready(v136) )
            get_channel_entry_info(
              *(uint8_t *)(*(uint32_t *)v136 + 1225),
              dword_123E28 + 38 * *(uint8_t *)(*(uint32_t *)v136 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(uint32_t *)off_123E20 << 28 )
    {
      irq_disable_mmio_write(dword_1244E8, dword_1244E4, 2493);
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        v65 = a1 - 6;
        switch ( v65 )
        {
          case 0u:
            *(uint32_t *)(a4 + 20) = &jpt_1241FE;
            *((uint32_t *)a2 + 21) = a2;
            a3[12] = 103;
            *((uint32_t *)a2 + 5) = 103;
            v111 = *((uint32_t *)a2 + 25);
            v112 = a3[17];
            v113 = a3[29];
            *(uint8_t *)(v112 + 17) = v65;
            *(uint32_t *)(v112 + 116) = v111;
            v114 = v65 - 1374;
            v115 = *(uint32_t *)(v111 + 4);
            *(uint8_t *)(v112 + 29) = v115;
            *(uint32_t *)(uintptr_t)(0x124340 + 3 * 4) = v114;
            *(uint8_t *)(v113 + 17) = v112;
            *(uint32_t *)(uintptr_t)(0x12436A) = v114;
            *(uint32_t *)(v112 + 20) = v115;
            v116 = *(uint32_t *)(v112 + 100);
            v117 = *(uint32_t *)(v113 + 68);
            *(uint32_t *)(v117 + 68) = v117;
            v118 = *(int16_t *)(2 * v117);
            *(uint8_t *)(v118 + 17) = *(uint32_t *)(v118 + 100);
            *(uint32_t *)(v113 + 84) = v114;
            v119 = *(int16_t *)(v116 + v118);
            *(uint32_t *)(v116 + 100) = v64;
            *(uint32_t *)(uintptr_t)(0x1243AA) = v114;
            v120 = *(int16_t *)(2 * v118);
            *(uint32_t *)(v118 + 68) = *(uint32_t *)(v119 + 20);
            v121 = *(uint32_t *)(v120 + 4);
            *(uint32_t *)(v119 + 84) = v114;
            v122 = *(uint8_t *)(v120 + 1);
            *(uint8_t *)(v120 + 29) = v121;
            *(uint32_t *)(v118 + 84) = v122;
            *(uint32_t *)(v120 + 84) = v120;
            v123 = *(uint32_t *)(v120 + 4);
            *(uint8_t *)(v118 + 29) = v123;
            *(uint32_t *)(uintptr_t)(0x124340 + 3 * 4) = v114;
            *(uint8_t *)(2 * v118 + 0x11) = v118;
            *(uint32_t *)(uintptr_t)(0x12436A) = v114;
            *(uint32_t *)(v118 + 20) = v123;
            v124 = *(uint32_t *)(v118 + 100);
            v125 = *(uint32_t *)(2 * v118 + 0x44);
            *(uint32_t *)(v124 + 84) = (uint32_t *)(uintptr_t)(0x124336);
            *(uint32_t *)(v125 + 84) = v124;
            *(uint32_t *)(2 * v125 + 0x54) = v114;
            v126 = *(uint32_t *)(*(int16_t *)(v124 + v125) + 4);
            *(uint32_t *)(v125 + 84) = v124;
            *(uint8_t *)(v124 + 17) = v126;
            *(uint8_t *)(v125 + 1) = v114;
            JUMPOUT(0x144230);
          default:
            break;
        }
      }
      if ( **v11 >= 0 )
      {
LABEL_24:
        v15 = off_123E24;
        v16 = 2;
        goto LABEL_10;
      }
    }
    else if ( a1 > 0x3B )
    {
      if ( a1 == 143 )
        goto LABEL_16;
    }
    else if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6u:
LABEL_76:
          v63 = (uint8_t *)tx_send_pdu(7, a4, a3, 2);
          v15 = off_124194;
          *v63 = transmit_radio_packet((int *)(a2 + 2), *a2, a2[8], v63 + 1);
          rx_process_packet(v63);
          v16 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v62 = *a2;
          if ( v62 <= 3 )
            v62 = get_bss_by_index(v62);
          if ( !*((uint32_t *)off_1241D0 + 2) )
            rf_set_power_off(v62, v9);
          mac_write_header_word(9, a4, a3);
          v15 = off_124194;
          v16 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v15 = off_124194;
          v61 = *(uint32_t *)a2;
          *(uint32_t *)off_124194 = *(uint32_t *)a2;
          if ( v12 < 0 && *(uint32_t *)off_1244F4 << 28 )
          {
            mmio_write_field(dword_1244E8, dword_1244F8, 472);
            v61 = *(uint32_t *)v15;
          }
          *(uint32_t *)off_1241CC = v61 | *((uint32_t *)v15 + 1);
          mac_write_header_word(15, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v59 = tx_send_pdu(17, a4, a3, 2);
          v15 = off_124194;
          v60 = v59;
          check_boot_flag((uint16_t *)a2, a2[10]);
          rx_process_packet(v60);
          v16 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v58 = off_1241C8;
          v15 = off_124194;
          *(uint32_t *)off_1241C8 = *(uint32_t *)off_1241C8 & 0xFFFFFF00 | *a2;
          *v58 |= 0x80000000;
          mac_write_header_word(19, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v56 = *(uint16_t *)a2;
          v57 = dword_1241C4 + 1320 * a2[2];
          if ( *(uint8_t *)(v57 + 106) )
            set_bss_cap(v57, v56);
          else
            *(uint32_t *)(dword_124180 + 696 * *(uint8_t *)(v57 + 116) + 8) = v56 << 10;
          mac_write_header_word(21, a4, a3);
          v15 = off_124194;
          v16 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v50 = *(char **)a2;
          v51 = a2[5];
          v15 = off_124194;
          v52 = *((uint32_t *)off_1241BC + 10);
          v54 = (char *)(*(uint32_t *)a2 & 0xFFFFF1FF);
          v53 = v54 == 0;
          v55 = v51 + 4;
          if ( v54 )
            v50 = (char *)off_124194 + 4 * v55;
          else
            v54 = (char *)off_124194 + 4 * v55;
          if ( v53 )
            *((uint32_t *)v54 + 1) = v50;
          else
            *((uint32_t *)v50 + 1) = v54;
          if ( v52 && *(uint8_t *)(v52 + 4) == v51 )
            *(uint32_t *)off_1241C0 = *(uint32_t *)&v15[4 * v55 + 4];
          mac_write_header_word(23, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v15 = off_124194;
          memcpy(dword_1241B0 + 1320 * a2[6], a2, 6);
          v48 = off_1241B8;
          v49 = *((uint16_t *)a2 + 2);
          *(uint32_t *)off_1241B4 = *(uint32_t *)a2;
          *v48 = v49;
          mac_write_header_word(25, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v15 = off_124194;
          *(uint32_t *)off_1241D4 = (*a2 << 14) & 0x1C000 | *(uint32_t *)off_1241D4 & 0xFFFE3FFF;
          mac_write_header_word(29, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v29 = a2[3];
          v30 = dword_1241C4;
          v31 = (uint8_t *)(dword_1241C4 + 1320 * v29);
          v136[0] = 0;
          v132 = 1320 * v29;
          v32 = reset_drv_flag(v136);
          v33 = v31[106];
          v34 = a2[2];
          v31[108] = v34;
          v127 = v32;
          if ( !v33 )
          {
            v134 = v31[116];
            if ( v34 )
            {
              v35 = dword_124180 + 696 * v31[116];
              v36 = v132 + 24 + v30;
              mem_copy_util(v36, *((uint32_t *)off_124184 + 4) + *(uint32_t *)(v35 + 8));
              *(uint16_t *)(v35 + 32) = *(uint16_t *)a2;
              mac_clear_irq();
              check_feature_flag(256, dword_124188);
              v37 = off_124190;
              *(uint32_t *)off_12418C = (uint16_t)*(uint32_t *)off_12418C | (*(uint16_t *)a2 << 16);
              if ( (*v37 & 0x8000) != 0 && rf_status_bit21() && (*(uint32_t *)(v35 + 4) & 0x20) != 0 )
              {
                set_rf_frequency(*(uint16_t *)a2);
                read_int_status();
                check_feature_flag(256, dword_124828);
                mmio_set_register_bit();
              }
              v15 = off_124194;
              v135 = dword_124180 + 696 * v134;
              v38 = v30 + 1320 * v29;
              v39 = *(uint32_t *)(v38 + 4) | 1;
              *(uint16_t *)(v135 + 30) = (unsigned int)(((unsigned int)dword_1241D8
                                                    * (unsigned uint64_t)(*(uint32_t *)(v135 + 8)
                                                                       * ((unsigned int)*((uint16_t *)off_124194
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v40 = off_124184;
              *(uint16_t *)(v38 + 112) = 0;
              *(uint8_t *)(v38 + 114) = 0;
              *(uint8_t *)(v38 + 148) = 0;
              *(uint8_t *)(v38 + 128) = 0;
              *(uint32_t *)(v38 + 124) = 0;
              *(uint32_t *)(v38 + 4) = v39;
              *(uint32_t *)(v38 + 120) = v40[4];
              v133 = v38;
              v41 = wifi_disable_action(v31);
              v42 = *(uint8_t *)(v133 + 1224);
              if ( *(uint8_t *)(v133 + 1224) )
              {
                if ( !v127 )
                  goto LABEL_39;
                v81 = off_1244EC;
                if ( !*((uint32_t *)off_1244EC + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_1244EC + 8) = 0;
                v81[36] = 0;
                chip_register_set_bit(v41);
LABEL_119:
                v82 = **v11;
                *((uint32_t *)v15 + 1) |= 0x10u;
                if ( v82 < 0 && *(uint32_t *)off_124838 << 28 )
                  mmio_write_field(dword_124840, dword_12483C, 472);
                *(uint32_t *)off_124520 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                v34 = a2[2];
                goto LABEL_40;
              }
              if ( v127 )
              {
                if ( v127 != 1 )
                  goto LABEL_39;
                v94 = off_124814;
                if ( v31 == *((uint8_t **)off_124814 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124814 + 8) = v42;
                v130 = v42;
                v95 = mem_set_util(v36);
                v94[36] = v130;
                chip_register_set_bit(v95);
                v34 = a2[2];
              }
              else
              {
                if ( *((uint32_t *)off_124198 + 8) )
                {
LABEL_39:
                  v34 = a2[2];
                  goto LABEL_40;
                }
                if ( v136[0] )
                {
                  if ( v136[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v107 = (int *)off_124834;
                v108 = *(uint32_t *)(v135 + 8);
                v109 = *(uint32_t *)off_124834;
                *((uint32_t *)off_124198 + 8) = v31;
                *v107 = (uint16_t)(v108 >> 10) | (HIWORD(v109) << 16);
                v110 = mem_set_util(v36);
                *((uint8_t *)off_124814 + 36) = 0;
                chip_register_read(v110);
                v34 = a2[2];
              }
            }
            else
            {
              v68 = mem_set_util(v132 + 24 + v30);
              nullsub_8(v68);
              v69 = check_feature_flag(256, dword_124510);
              if ( (*(uint32_t *)off_124514 & 0x8000) != 0 )
              {
                v69 = rf_status_bit21();
                if ( v69 )
                {
                  if ( (*(uint32_t *)(dword_124818 + 696 * v134 + 4) & 0x20) != 0 && v31[106] != 4 )
                    v69 = init_chan_entry(v31[107]);
                }
              }
              v70 = v30 + 1320 * v29;
              v71 = *(uint8_t *)(v70 + 1224);
              *(uint8_t *)(v70 + 1227) = 0;
              *(uint32_t *)(v70 + 1228) = 0;
              if ( v71 )
              {
                if ( v127 )
                {
                  v83 = *((uint8_t **)off_124810 + 2);
                  if ( v83 )
                  {
                    while ( v83[106] || !v83[108] || v31 == v83 || v83[1224] )
                    {
                      v83 = *(uint8_t **)v83;
                      if ( !v83 )
                        goto LABEL_101;
                    }
                    if ( !*((uint32_t *)off_124814 + 8) )
                    {
                      v84 = v83[116];
                      v85 = dword_124818;
                      v86 = (int *)off_124834;
                      *((uint32_t *)off_124814 + 8) = v83;
                      *v86 = (uint16_t)(*(uint32_t *)(v85 + 696 * v84 + 8) >> 10) | (HIWORD(*v86) << 16);
                      v129 = v83;
                      v87 = mem_set_util(v83 + 24);
                      *((uint8_t *)off_124814 + 36) = 0;
                      v15 = off_12481C;
                      chip_register_read(v87);
                      v88 = **v11;
                      v89 = v129;
                      *((uint32_t *)v15 + 1) &= ~0x10u;
                      if ( v88 < 0 && *(uint32_t *)off_124838 << 28 )
                      {
                        mmio_write_field(dword_124840, dword_12483C, 472);
                        v89 = v129;
                      }
                      v90 = off_124844;
                      *(uint32_t *)off_124820 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                      v91 = off_124824;
                      v92 = *((uint32_t *)v89 + 16);
                      v93 = *((uint16_t *)v89 + 34);
                      *v90 = v92;
                      *v91 = v93;
                      v34 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v127 == 2 )
              {
                v100 = off_124814;
                if ( !*((uint32_t *)off_124814 + 8) )
                {
                  v101 = *((uint8_t **)off_124810 + 2);
                  if ( !v101 )
LABEL_169:
                    __und(0xFFu);
                  while ( v101[106] || !v101[108] || v31 == v101 || v101[1224] )
                  {
                    v101 = *(uint8_t **)v101;
                    if ( !v101 )
                      goto LABEL_169;
                  }
                  v102 = (int *)off_124834;
                  v131 = v101[1224];
                  v103 = *(uint32_t *)off_124834;
                  v104 = *(uint32_t *)(dword_124818 + 696 * v101[116] + 8);
                  *((uint32_t *)off_124814 + 8) = v101;
                  *v102 = (uint16_t)(v104 >> 10) | (HIWORD(v103) << 16);
                  v105 = mem_set_util(v101 + 24);
                  v100[36] = v131;
                  v15 = off_12481C;
                  chip_register_read(v105);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( v127 == 1 )
              {
                v106 = off_124814;
                if ( v31 == *((uint8_t **)off_124814 + 8) )
                {
                  *((uint32_t *)off_124814 + 8) = 0;
                  v106[36] = 0;
                  v15 = off_12481C;
                  chip_register_set_bit(v69);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_101:
              v34 = a2[2];
              v15 = off_1244F0;
            }
LABEL_40:
            bt_scan_start(v31, v34);
            if ( a2[2] )
            {
              v43 = *(uint32_t **)off_12419C;
              v44 = **(uint32_t **)off_12419C;
              if ( v44 )
                *(uint32_t *)off_1241A0 = v44;
              else
                *(uint32_t *)off_12450C = *(uint32_t *)(v30 + 1320 * v29 + 8);
              v45 = v43[1];
              if ( v45 )
              {
                if ( (v45 & 0xFFF) != 0 )
                  *(uint32_t *)off_124508 = v45;
                else
                  *(uint32_t *)off_1241A4 = v45 & 0xFFFFF000 | *(uint32_t *)(v30 + 1320 * v29 + 12) & 0xFFF;
              }
              else
              {
                *(uint32_t *)off_124508 = *(uint32_t *)(v30 + 1320 * v29 + 12);
              }
              v46 = v43[2];
              if ( v46 )
                *(uint32_t *)off_1241A8 = v46;
              else
                *(uint32_t *)off_124504 = *(uint32_t *)(v30 + 1320 * v29 + 16);
              v47 = v43[3];
              if ( v47 )
                *(uint32_t *)off_1241AC = v47;
              else
                *(uint32_t *)off_124518 = *(uint32_t *)(v30 + 1320 * v29 + 20);
              get_mac_ver();
            }
            mac_write_header_word(31, a4, a3);
            v16 = 0;
            goto LABEL_10;
          }
          if ( !v32 )
          {
            if ( v34 )
            {
              v66 = 0;
              goto LABEL_84;
            }
LABEL_85:
            v15 = off_1244F0;
            goto LABEL_40;
          }
          v66 = *((uint8_t **)off_12451C + 2);
          if ( v66 )
          {
            do
            {
              if ( !v66[106] && v66[108] && v31 != v66 && !v66[1224] )
                break;
              v66 = *(uint8_t **)v66;
            }
            while ( v66 );
            if ( !v34 )
            {
              v72 = off_1244EC;
              if ( !*((uint32_t *)off_1244EC + 8) && v66 )
              {
                *((uint32_t *)off_1244EC + 8) = v66;
                v72[36] = 0;
                v128 = v66;
                v15 = off_1244F0;
                v73 = mem_set_util(v66 + 24);
                chip_register_read(v73);
                v74 = **v11;
                v75 = v128;
                *((uint32_t *)v15 + 1) &= ~0x10u;
                if ( v74 < 0 && *(uint32_t *)off_124838 << 28 )
                {
                  mmio_write_field(dword_124840, dword_12483C, 472);
                  v75 = v128;
                }
                v76 = off_124530;
                v77 = *((uint32_t *)v75 + 16);
                *(uint32_t *)off_124520 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                v78 = off_124524;
                v79 = *((uint16_t *)v75 + 34);
                *v76 = v77;
                v80 = off_124528;
                *v78 = v79;
                *v80 = dword_12452C;
                v78[8212] &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_85;
            }
          }
          else if ( !v34 )
          {
            goto LABEL_85;
          }
LABEL_84:
          v67 = off_1244EC;
          if ( v66 == *((uint8_t **)off_1244EC + 8) )
          {
            *((uint32_t *)off_1244EC + 8) = 0;
            v67[36] = 0;
            v15 = off_12481C;
            ((void (*)(void))chip_register_set_bit)();
            v96 = **v11;
            *((uint32_t *)v15 + 1) |= 0x10u;
            if ( v96 < 0 && *(uint32_t *)off_124838 << 28 )
              mmio_write_field(dword_124840, dword_12483C, 472);
            v97 = off_124820;
            v98 = off_12482C;
            *(uint32_t *)off_124820 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
            v99 = dword_124830;
            *v98 = dword_124830;
            v97[8197] |= v99;
            v34 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v15 = off_123E24;
          *(uint32_t *)off_123E48 = *a2 | (((uint8_t)*(uint32_t *)off_123E44 * *a2) << 8);
          mac_write_header_word(33, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v17 = *a2;
          if ( *a2 )
          {
            if ( dma_tx_ring(dword_1244FC + 696 * a2[1], a2[2], *((uint16_t *)a2 + 3)) )
            {
              *(uint32_t *)off_124500 |= 0x80u;
              v17 = 0;
            }
            else
            {
              v17 = 4;
            }
          }
          else
          {
            v18 = a2[2];
            v19 = *((uint16_t *)a2 + 2);
            v20 = *(uint32_t *)(dword_123E38 + 4 * *(uint8_t *)(dword_123E34 + v18));
            if ( (int)v19 >= v20 )
            {
              if ( v19 > 0x40 )
                LOWORD(v21) = *(uint32_t *)(dword_123E38 + 4 * *(uint8_t *)(dword_123E34 + v18));
              else
                LOWORD(v21) = v20 / 2;
            }
            else
            {
              v21 = v19 >> 1;
            }
            alloc_tx_event(dword_123E3C, v18, v19);
            v22 = *((uint16_t *)a2 + 2);
            v23 = 696 * a2[1];
            v24 = *(uint8_t *)(v23 + 12 * a2[2] + dword_123E4C + 453);
            v25 = *((uint16_t *)a2 + 3);
            v26 = v23 + 6 * a2[2] + dword_123E4C;
            v27 = dword_123E40 + 32 * v24;
            *(uint16_t *)(v26 + 354) = v21;
            *(uint16_t *)(v26 + 356) = v22;
            *(uint16_t *)(v27 + 12) = v25;
          }
          v28 = (uint8_t *)tx_send_pdu(41, a4, a3, 3);
          *v28 = a2[1];
          v28[1] = a2[2];
          v28[2] = v17;
          rx_process_packet(v28);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          unknown_12f378(a2);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          cfm_mac_info(a2);
          mac_write_header_word(60, a4, a3);
          v15 = off_123E24;
          v16 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v15 = off_123E24;
    irq_disable_mmio_write(dword_123E30, dword_123E2C, 2552);
    v16 = 2;
LABEL_10:
    *(uint32_t *)off_123E20 = (uint8_t)(16 * v15[19]);
    hci_cmd_preprocess(a3);
    return v16;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v13 = off_123E24;
    *((uint8_t *)off_123E24 + 19) = *(uint8_t *)off_123E20 & 0xF;
    v14 = hci_cmd_handler(a3);
    v13[18] = v14;
    rf_status_check(v14);
    hci_cmd_preprocess(a3);
  }
  return 2;
}

