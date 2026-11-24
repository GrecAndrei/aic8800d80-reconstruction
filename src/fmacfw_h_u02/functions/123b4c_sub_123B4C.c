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


extern uint32_t dword_123E28;
extern uint32_t dword_123E38;
extern uint32_t dword_123E40;
extern uint32_t dword_123E4C;
extern uint32_t dword_124180;
extern uint32_t dword_1241B0;
extern uint32_t dword_1241C4;
extern uint32_t dword_1241D8;
extern uint32_t dword_1244FC;
extern uint32_t dword_12452C;
extern uint32_t dword_124818;
extern uint32_t dword_124830;
extern uint32_t off_123E20;
extern uint32_t off_123E24;
extern uint32_t off_123E30;
extern uint32_t off_123E34;
extern uint32_t off_123E44;
extern uint32_t off_123E48;
extern uint32_t off_123E50;
extern uint32_t off_12418C;
extern uint32_t off_124190;
extern uint32_t off_124194;
extern uint32_t off_124198;
extern uint32_t off_12419C;
extern uint32_t off_1241A0;
extern uint32_t off_1241A4;
extern uint32_t off_1241A8;
extern uint32_t off_1241AC;
extern uint32_t off_1241B4;
extern uint32_t off_1241B8;
extern uint32_t off_1241BC;
extern uint32_t off_1241C0;
extern uint32_t off_1241C8;
extern uint32_t off_1241CC;
extern uint32_t off_1241D0;
extern uint32_t off_1241D4;
extern uint32_t off_1244EC;
extern uint32_t off_1244F0;
extern uint32_t off_1244F4;
extern uint32_t off_124500;
extern uint32_t off_124504;
extern uint32_t off_124508;
extern uint32_t off_12450C;
extern uint32_t off_124514;
extern uint32_t off_124518;
extern uint32_t off_12451C;
extern uint32_t off_124520;
extern uint32_t off_124524;
extern uint32_t off_124528;
extern uint32_t off_124530;
extern uint32_t off_124810;
extern uint32_t off_124814;
extern uint32_t off_12481C;
extern uint32_t off_124820;
extern uint32_t off_124824;
extern uint32_t off_12482C;
extern uint32_t off_124834;
extern uint32_t off_124838;
extern uint32_t off_124844;

// rf_calibrate_1 @ 0x123b4c, size 3268 bytes
int  rf_calibrate_1(unsigned int a1, uint8_t *a2, unsigned int a3, int a4)
{
  int v8; // r0
  uint16_t **v10; // r8
  int v11; // r3
  uint8_t *v12; // r5
  uint8_t *v13; // r7
  int v14; // r6
  uint8_t v15; // r7
  int v16; // r1
  unsigned int v17; // r2
  signed int v18; // r3
  unsigned int v19; // r8
  uint16_t v20; // lr
  int v21; // r2
  int v22; // r3
  uint16_t v23; // r1
  int v24; // r2
  int v25; // r3
  uint8_t *v26; // r0
  int v27; // r11
  int v28; // r10
  int v29; // r9
  int v30; // r0
  int v31; // r2
  int v32; // r1
  int v33; // r7
  volatile unsigned int v34; // r1
  uint32_t *v35; // s16
  uint32_t *v36; // r1
  int v37; // r3
  int v38; // r12
  volatile unsigned int v39; // r0
  int v40; // r3
  uint32_t *v41; // r3
  int v42; // r2
  int v43; // r2
  int v44; // r2
  int v45; // r3
  uint32_t *v46; // r3
  int v47; // r2
  char *v48; // r3
  int v49; // r1
  int v50; // r0
  int v51; // zf
  char *v52; // r5
  int v53; // r2
  unsigned int v54; // r1
  int v55; // r0
  uint32_t *v56; // r2
  int v57; // r0
  int v58; // r6
  int v59; // r2
  int v60; // r3
  int v61; // r2
  unsigned int v62; // r0
  uint8_t *v63; // r6
  int *v64; // r3
  uint8_t *v65; // r2
  int v66; // r3
  int v67; // r1
  uint8_t *v68; // r2
  int v69; // r1
  int *v70; // r3
  uint32_t *v71; // lr
  int v72; // r12
  uint32_t *v73; // r2
  int v74; // r0
  uint32_t *v75; // r3
  uint8_t *v76; // r3
  int v77; // r2
  int *v78; // r3
  int v79; // r0
  int v80; // r7
  int *v81; // r12
  int v82; // r1
  int *v83; // r3
  uint32_t *v84; // r12
  uint32_t *v85; // r2
  int v86; // r0
  int v87; // r3
  uint8_t *v88; // r8
  int v89; // r2
  uint32_t *v90; // r2
  uint32_t *v91; // r0
  int v92; // r1
  uint8_t *v93; // r8
  int *v94; // r0
  int *v95; // r1
  unsigned int v96; // r12
  unsigned int v97; // r3
  uint8_t *v98; // r3
  int *v99; // r12
  unsigned int v100; // r3
  unsigned int v101; // r1
  int v102; // [sp+0h] [bp-24h]
  int v103; // [sp+4h] [bp-20h]
  int v104; // [sp+8h] [bp-1Ch]
  int v105; // [sp+Ch] [bp-18h]
  int *v106; // [sp+Ch] [bp-18h]
  int *v107; // [sp+Ch] [bp-18h]
  char v108; // [sp+Ch] [bp-18h]
  char v109; // [sp+Ch] [bp-18h]
  int v110; // [sp+10h] [bp-14h]
  int v111; // [sp+10h] [bp-14h]
  int v112; // [sp+14h] [bp-10h]
  int v113; // [sp+14h] [bp-10h]
  uint8_t a1a[8]; // [sp+1Ch] [bp-8h] BYREF

  v8 = hci_cmd_handler(a3);
  if ( !v8 )
  {
    v10 = (uint16_t **)off_123E50;
    v11 = **(uint16_t **)off_123E50;
    if ( v11 >= 0 )
    {
      if ( a1 <= 0x3B )
      {
        if ( a1 > 5 )
        {
          switch ( a1 )
          {
            case 6u:
              goto LABEL_77;
            case 8u:
              goto LABEL_71;
            case 0xEu:
              goto LABEL_69;
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
              goto LABEL_76;
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
              v13 = off_123E24;
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = off_123E24;
        *((uint8_t *)off_123E24 + 48) = 0;
        v14 = abs_i32(*(uint32_t *)a2);
        if ( v14 )
        {
          rf_is_ready(*(uint32_t *)a2);
          v14 = 0;
        }
        else if ( v13[49] )
        {
          v13[49] = 0;
          if ( patch_check_ready(a1a) )
            get_channel_entry_info(
              *(uint8_t *)(*(uint32_t *)a1a + 1225),
              dword_123E28 + 38 * *(uint8_t *)(*(uint32_t *)a1a + 107));
        }
        goto LABEL_10;
      }
LABEL_24:
      v13 = off_123E24;
      v14 = 2;
      goto LABEL_10;
    }
    if ( !(*(uint32_t *)off_123E20 << 28) )
    {
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        switch ( a1 )
        {
          case 6u:
            goto LABEL_77;
          case 8u:
            goto LABEL_71;
          case 0xEu:
            goto LABEL_69;
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
            goto LABEL_76;
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
            goto LABEL_21;
        }
      }
      goto LABEL_21;
    }
    irq_disable_mmio_write((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
    if ( a1 > 0x3B )
    {
      if ( a1 == 143 )
        goto LABEL_16;
    }
    else if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6u:
LABEL_77:
          v63 = (uint8_t *)tx_send_pdu(7, a4, a3, 2);
          v13 = off_124194;
          *v63 = transmit_radio_packet((int)(a2 + 2), *a2, a2[8], v63 + 1);
          rx_process_packet_1((int)v63);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_71:
          v62 = *a2;
          if ( v62 <= 3 )
            get_bss_by_index(v62);
          if ( !*((uint32_t *)off_1241D0 + 2) )
            rf_set_power_off();
          mac_write_header_word(9, a4, a3);
          v13 = off_124194;
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
          v11 = **v10;
LABEL_69:
          v13 = off_124194;
          v61 = *(uint32_t *)a2;
          *(uint32_t *)off_124194 = *(uint32_t *)a2;
          if ( v11 < 0 && *(uint32_t *)off_1244F4 << 28 )
          {
            mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v61 = *(uint32_t *)v13;
          }
          *(uint32_t *)off_1241CC = v61 | *((uint32_t *)v13 + 1);
          mac_write_header_word(15, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v57 = tx_send_pdu(17, a4, a3, 2);
          v13 = off_124194;
          v58 = v57;
          check_boot_flag((uint16_t *)a2, a2[10], v59, v60, v102, v103, v104);
          rx_process_packet_1(v58);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v56 = off_1241C8;
          v13 = off_124194;
          *(uint32_t *)off_1241C8 = *(uint32_t *)off_1241C8 & 0xFFFFFF00 | *a2;
          *v56 |= 0x80000000;
          mac_write_header_word(19, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v54 = *(uint16_t *)a2;
          v55 = dword_1241C4 + 1320 * a2[2];
          if ( *(uint8_t *)(v55 + 106) )
            set_bss_cap(v55, v54);
          else
            *(uint32_t *)(dword_124180 + 696 * *(uint8_t *)(v55 + 116) + 8) = v54 << 10;
          mac_write_header_word(21, a4, a3);
          v13 = off_124194;
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v48 = *(char **)a2;
          v49 = a2[5];
          v13 = off_124194;
          v50 = *((uint32_t *)off_1241BC + 10);
          v52 = (char *)(*(uint32_t *)a2 & 0xFFFFF1FF);
          v51 = v52 == nullptr;
          v53 = v49 + 4;
          if ( v52 )
            v48 = (char *)off_124194 + 4 * v53;
          else
            v52 = (char *)off_124194 + 4 * v53;
          if ( v51 )
            *((uint32_t *)v52 + 1) = v48;
          else
            *((uint32_t *)v48 + 1) = v52;
          if ( v50 && *(uint8_t *)(v50 + 4) == v49 )
            *(uint32_t *)off_1241C0 = *(uint32_t *)&v13[4 * v53 + 4];
          mac_write_header_word(23, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = off_124194;
          memcpy_1((char *)(dword_1241B0 + 1320 * a2[6]), (char *)a2, 6u);
          v46 = off_1241B8;
          v47 = *((uint16_t *)a2 + 2);
          *(uint32_t *)off_1241B4 = *(uint32_t *)a2;
          *v46 = v47;
          mac_write_header_word(25, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_76:
          v13 = off_124194;
          *(uint32_t *)off_1241D4 = (*a2 << 14) & 0x1C000 | *(uint32_t *)off_1241D4 & 0xFFFE3FFF;
          mac_write_header_word(29, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = a2[3];
          v28 = dword_1241C4;
          v29 = dword_1241C4 + 1320 * v27;
          a1a[0] = 0;
          v110 = 1320 * v27;
          v30 = reset_drv_flag(a1a);
          v31 = *(uint8_t *)(v29 + 106);
          v32 = a2[2];
          *(uint8_t *)(v29 + 108) = v32;
          v105 = v30;
          if ( !v31 )
          {
            v112 = *(uint8_t *)(v29 + 116);
            if ( v32 )
            {
              v33 = dword_124180 + 696 * *(uint8_t *)(v29 + 116);
              v34 = (*(volatile uint32_t *)0x40501010u);
              v35 = (uint32_t *)(v110 + 24 + v28);
              mem_copy_util(v35, v34 + *(uint32_t *)(v33 + 8));
              *(uint16_t *)(v33 + 32) = *(uint16_t *)a2;
              mac_clear_irq();
              check_feature_flag(
                256,
                "vif state active:%d,%d,%d,%d\r\n",
                *(uint8_t *)(v33 + 35),
                *(uint16_t *)(v33 + 32),
                *(uint8_t *)(v29 + 1224),
                v105);
              v36 = off_124190;
              *(uint32_t *)off_12418C = (uint16_t)*(uint32_t *)off_12418C | (*(uint16_t *)a2 << 16);
              if ( (*v36 & 0x8000) != 0 && rf_status_bit21() && (*(uint32_t *)(v33 + 4) & 0x20) != 0 )
              {
                set_rf_frequency(*(uint16_t *)a2);
                read_int_status();
                check_feature_flag(256, aHeEnabled);
                mmio_set_register_bit();
              }
              v13 = off_124194;
              v113 = dword_124180 + 696 * v112;
              v37 = v28 + 1320 * v27;
              v38 = *(uint32_t *)(v37 + 4) | 1;
              *(uint16_t *)(v113 + 30) = (unsigned int)(((unsigned int)dword_1241D8
                                                    * (uint64_t)(*(uint32_t *)(v113 + 8)
                                                                       * ((unsigned int)*((uint16_t *)off_124194
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              *(uint16_t *)(v37 + 112) = 0;
              *(uint8_t *)(v37 + 114) = 0;
              *(uint8_t *)(v37 + 148) = 0;
              *(uint8_t *)(v37 + 128) = 0;
              *(uint32_t *)(v37 + 124) = 0;
              *(uint32_t *)(v37 + 4) = v38;
              v39 = (*(volatile uint32_t *)0x40501010u);
              *(uint32_t *)(v37 + 120) = v39;
              v111 = v37;
              wifi_disable_action((uint32_t *)v29);
              v40 = *(uint8_t *)(v111 + 1224);
              if ( *(uint8_t *)(v111 + 1224) )
              {
                if ( !v105 )
                  goto LABEL_39;
                v76 = off_1244EC;
                if ( !*((uint32_t *)off_1244EC + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_1244EC + 8) = 0;
                v76[36] = 0;
                chip_register_set_bit();
LABEL_120:
                v77 = **v10;
                *((uint32_t *)v13 + 1) |= 0x10u;
                if ( v77 < 0 && *(uint32_t *)off_124838 << 28 )
                  mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                *(uint32_t *)off_124520 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                v32 = a2[2];
                goto LABEL_40;
              }
              if ( v105 )
              {
                if ( v105 != 1 )
                  goto LABEL_39;
                v88 = off_124814;
                if ( v29 == *((uint32_t *)off_124814 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124814 + 8) = v40;
                v108 = v40;
                mem_set_util(v35);
                v88[36] = v108;
                chip_register_set_bit();
                v32 = a2[2];
              }
              else
              {
                if ( *((uint32_t *)off_124198 + 8) )
                {
LABEL_39:
                  v32 = a2[2];
                  goto LABEL_40;
                }
                if ( a1a[0] )
                {
                  if ( a1a[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_120;
                }
                v99 = (int *)off_124834;
                v100 = *(uint32_t *)(v113 + 8);
                v101 = *(uint32_t *)off_124834;
                *((uint32_t *)off_124198 + 8) = v29;
                *v99 = (uint16_t)(v100 >> 10) | (HIWORD(v101) << 16);
                mem_set_util(v35);
                *((uint8_t *)off_124814 + 36) = 0;
                chip_register_read();
                v32 = a2[2];
              }
            }
            else
            {
              mem_set_util((uint32_t *)(v110 + 24 + v28));
              nullsub_8();
              check_feature_flag(256, "vif state inactive:%d,%d\r\n", *(uint8_t *)(v29 + 1224), v105);
              if ( (*(uint32_t *)off_124514 & 0x8000) != 0
                && rf_status_bit21()
                && (*(uint32_t *)(dword_124818 + 696 * v112 + 4) & 0x20) != 0
                && *(uint8_t *)(v29 + 106) != 4 )
              {
                init_chan_entry(*(uint8_t *)(v29 + 107));
              }
              v66 = v28 + 1320 * v27;
              v67 = *(uint8_t *)(v66 + 1224);
              *(uint8_t *)(v66 + 1227) = 0;
              *(uint32_t *)(v66 + 1228) = 0;
              if ( v67 )
              {
                if ( v105 )
                {
                  v78 = *((int **)off_124810 + 2);
                  if ( v78 )
                  {
                    while ( *((uint8_t *)v78 + 106)
                         || !*((uint8_t *)v78 + 108)
                         || (int *)v29 == v78
                         || *((uint8_t *)v78 + 1224) )
                    {
                      v78 = (int *)*v78;
                      if ( !v78 )
                        goto LABEL_102;
                    }
                    if ( !*((uint32_t *)off_124814 + 8) )
                    {
                      v79 = *((uint8_t *)v78 + 116);
                      v80 = dword_124818;
                      v81 = (int *)off_124834;
                      *((uint32_t *)off_124814 + 8) = v78;
                      *v81 = (uint16_t)(*(uint32_t *)(v80 + 696 * v79 + 8) >> 10) | (HIWORD(*v81) << 16);
                      v107 = v78;
                      mem_set_util(v78 + 6);
                      *((uint8_t *)off_124814 + 36) = 0;
                      v13 = off_12481C;
                      chip_register_read();
                      v82 = **v10;
                      v83 = v107;
                      *((uint32_t *)v13 + 1) &= ~0x10u;
                      if ( v82 < 0 && *(uint32_t *)off_124838 << 28 )
                      {
                        mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                        v83 = v107;
                      }
                      v84 = off_124844;
                      *(uint32_t *)off_124820 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                      v85 = off_124824;
                      v86 = v83[16];
                      v87 = *((uint16_t *)v83 + 34);
                      *v84 = v86;
                      *v85 = v87;
                      v32 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v105 == 2 )
              {
                v93 = off_124814;
                if ( !*((uint32_t *)off_124814 + 8) )
                {
                  v94 = *((int **)off_124810 + 2);
                  if ( !v94 )
LABEL_170:
                    __und(0xFFu);
                  while ( *((uint8_t *)v94 + 106) || !*((uint8_t *)v94 + 108) || (int *)v29 == v94 || *((uint8_t *)v94 + 1224) )
                  {
                    v94 = (int *)*v94;
                    if ( !v94 )
                      goto LABEL_170;
                  }
                  v95 = (int *)off_124834;
                  v109 = *((uint8_t *)v94 + 1224);
                  v96 = *(uint32_t *)off_124834;
                  v97 = *(uint32_t *)(dword_124818 + 696 * *((uint8_t *)v94 + 116) + 8);
                  *((uint32_t *)off_124814 + 8) = v94;
                  *v95 = (uint16_t)(v97 >> 10) | (HIWORD(v96) << 16);
                  mem_set_util(v94 + 6);
                  v93[36] = v109;
                  v13 = off_12481C;
                  chip_register_read();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( v105 == 1 )
              {
                v98 = off_124814;
                if ( v29 == *((uint32_t *)off_124814 + 8) )
                {
                  *((uint32_t *)off_124814 + 8) = 0;
                  v98[36] = 0;
                  v13 = off_12481C;
                  chip_register_set_bit();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_102:
              v32 = a2[2];
              v13 = off_1244F0;
            }
LABEL_40:
            bt_scan_start((uint8_t *)v29, v32);
            if ( a2[2] )
            {
              v41 = *(uint32_t **)off_12419C;
              v42 = **(uint32_t **)off_12419C;
              if ( v42 )
                *(uint32_t *)off_1241A0 = v42;
              else
                *(uint32_t *)off_12450C = *(uint32_t *)(v28 + 1320 * v27 + 8);
              v43 = v41[1];
              if ( v43 )
              {
                if ( (v43 & 0xFFF) != 0 )
                  *(uint32_t *)off_124508 = v43;
                else
                  *(uint32_t *)off_1241A4 = v43 & 0xFFFFF000 | *(uint32_t *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(uint32_t *)off_124508 = *(uint32_t *)(v28 + 1320 * v27 + 12);
              }
              v44 = v41[2];
              if ( v44 )
                *(uint32_t *)off_1241A8 = v44;
              else
                *(uint32_t *)off_124504 = *(uint32_t *)(v28 + 1320 * v27 + 16);
              v45 = v41[3];
              if ( v45 )
                *(uint32_t *)off_1241AC = v45;
              else
                *(uint32_t *)off_124518 = *(uint32_t *)(v28 + 1320 * v27 + 20);
              get_mac_ver();
            }
            mac_write_header_word(31, a4, a3);
            v14 = 0;
            goto LABEL_10;
          }
          if ( !v30 )
          {
            if ( v32 )
            {
              v64 = nullptr;
              goto LABEL_85;
            }
LABEL_86:
            v13 = off_1244F0;
            goto LABEL_40;
          }
          v64 = *((int **)off_12451C + 2);
          if ( v64 )
          {
            do
            {
              if ( !*((uint8_t *)v64 + 106) && *((uint8_t *)v64 + 108) && (int *)v29 != v64 && !*((uint8_t *)v64 + 1224) )
                break;
              v64 = (int *)*v64;
            }
            while ( v64 );
            if ( !v32 )
            {
              v68 = off_1244EC;
              if ( !*((uint32_t *)off_1244EC + 8) && v64 )
              {
                *((uint32_t *)off_1244EC + 8) = v64;
                v68[36] = 0;
                v106 = v64;
                v13 = off_1244F0;
                mem_set_util(v64 + 6);
                chip_register_read();
                v69 = **v10;
                v70 = v106;
                *((uint32_t *)v13 + 1) &= ~0x10u;
                if ( v69 < 0 && *(uint32_t *)off_124838 << 28 )
                {
                  mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                  v70 = v106;
                }
                v71 = off_124530;
                v72 = v70[16];
                *(uint32_t *)off_124520 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                v73 = off_124524;
                v74 = *((uint16_t *)v70 + 34);
                *v71 = v72;
                v75 = off_124528;
                *v73 = v74;
                *v75 = dword_12452C;
                v73[8212] &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_86;
            }
          }
          else if ( !v32 )
          {
            goto LABEL_86;
          }
LABEL_85:
          v65 = off_1244EC;
          if ( v64 == *((int **)off_1244EC + 8) )
          {
            *((uint32_t *)off_1244EC + 8) = 0;
            v65[36] = 0;
            v13 = off_12481C;
            chip_register_set_bit();
            v89 = **v10;
            *((uint32_t *)v13 + 1) |= 0x10u;
            if ( v89 < 0 && *(uint32_t *)off_124838 << 28 )
              mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v90 = off_124820;
            v91 = off_12482C;
            *(uint32_t *)off_124820 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
            v92 = dword_124830;
            *v91 = dword_124830;
            v90[8197] |= v92;
            v32 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_86;
        case 0x20u:
LABEL_32:
          v13 = off_123E24;
          *(uint32_t *)off_123E48 = *a2 | (((uint8_t)*(uint32_t *)off_123E44 * *a2) << 8);
          mac_write_header_word(33, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( dma_tx_ring(dword_1244FC + 696 * a2[1], a2[2], *((uint16_t *)a2 + 3)) )
            {
              *(uint32_t *)off_124500 |= 0x80u;
              v15 = 0;
            }
            else
            {
              v15 = 4;
            }
          }
          else
          {
            v16 = a2[2];
            v17 = *((uint16_t *)a2 + 2);
            v18 = *(uint32_t *)(dword_123E38 + 4 * *((uint8_t *)off_123E34 + v16));
            if ( (int)v17 >= v18 )
            {
              if ( v17 > 0x40 )
                v19 = (uint16_t)v18;
              else
                v19 = (uint16_t)(v18 / 2);
            }
            else
            {
              v19 = v17 >> 1;
            }
            alloc_tx_event("mm_ba_add_req_handler %d, %d, %d\n", v16, v17, v19);
            v20 = *((uint16_t *)a2 + 2);
            v21 = 696 * a2[1];
            v22 = *(uint8_t *)(v21 + 12 * a2[2] + dword_123E4C + 453);
            v23 = *((uint16_t *)a2 + 3);
            v24 = v21 + 6 * a2[2] + dword_123E4C;
            v25 = dword_123E40 + 32 * v22;
            *(uint16_t *)(v24 + 354) = v19;
            *(uint16_t *)(v24 + 356) = v20;
            *(uint16_t *)(v25 + 12) = v23;
          }
          v26 = (uint8_t *)tx_send_pdu(41, a4, a3, 3);
          *v26 = a2[1];
          v26[1] = a2[2];
          v26[2] = v15;
          rx_process_packet_1((int)v26);
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          unknown_12f378();
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          cfm_mac_info(a2);
          mac_write_header_word(60, a4, a3);
          v13 = off_123E24;
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    if ( **v10 >= 0 )
      goto LABEL_24;
LABEL_21:
    v13 = off_123E24;
    irq_disable_mmio_write(off_123E30, (int)aMmHwConfigHand, 2552);
    v14 = 2;
LABEL_10:
    *(uint32_t *)off_123E20 = (uint8_t)(16 * v13[19]);
    hci_cmd_preprocess(a3, (uint8_t)v13[18]);
    return v14;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v12 = off_123E24;
    *((uint8_t *)off_123E24 + 19) = *(uint8_t *)off_123E20 & 0xF;
    v12[18] = hci_cmd_handler(a3);
    rf_status_check();
    hci_cmd_preprocess(a3, 2);
  }
  return 2;
}
