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


extern uint32_t dword_12419C;
extern uint32_t dword_1241AC;
extern uint32_t dword_1241B4;
extern uint32_t dword_1241C0;
extern uint32_t dword_1244F4;
extern uint32_t dword_124524;
extern uint32_t dword_124538;
extern uint32_t dword_12454C;
extern uint32_t dword_124870;
extern uint32_t dword_1248A0;
extern uint32_t dword_124B8C;
extern uint32_t dword_124BA4;
extern uint32_t off_124194;
extern uint32_t off_124198;
extern uint32_t off_1241A4;
extern uint32_t off_1241A8;
extern uint32_t off_1241B8;
extern uint32_t off_1241BC;
extern uint32_t off_1241C4;
extern uint32_t off_124500;
extern uint32_t off_124504;
extern uint32_t off_124508;
extern uint32_t off_12450C;
extern uint32_t off_124510;
extern uint32_t off_124514;
extern uint32_t off_124518;
extern uint32_t off_12451C;
extern uint32_t off_124520;
extern uint32_t off_124528;
extern uint32_t off_12452C;
extern uint32_t off_124530;
extern uint32_t off_124534;
extern uint32_t off_12453C;
extern uint32_t off_124540;
extern uint32_t off_124544;
extern uint32_t off_124548;
extern uint32_t off_124860;
extern uint32_t off_124864;
extern uint32_t off_124868;
extern uint32_t off_124874;
extern uint32_t off_124878;
extern uint32_t off_12487C;
extern uint32_t off_124880;
extern uint32_t off_124888;
extern uint32_t off_12488C;
extern uint32_t off_124890;
extern uint32_t off_124894;
extern uint32_t off_124898;
extern uint32_t off_12489C;
extern uint32_t off_1248A4;
extern uint32_t off_124B84;
extern uint32_t off_124B88;
extern uint32_t off_124B90;
extern uint32_t off_124B94;
extern uint32_t off_124B98;
extern uint32_t off_124BA0;
extern uint32_t off_124BA8;
extern uint32_t off_124BAC;
extern uint32_t off_124BB8;

// process_float_packet @ 0x123ec0, size 3268 bytes
int  process_float_packet(unsigned int a1, uint8_t *a2, unsigned int a3, int a4)
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
  unsigned int v60; // r0
  uint8_t *v61; // r6
  int *v62; // r3
  uint8_t *v63; // r2
  int v64; // r3
  int v65; // r1
  uint8_t *v66; // r2
  int v67; // r1
  int *v68; // r3
  uint32_t *v69; // lr
  int v70; // r12
  uint32_t *v71; // r2
  int v72; // r0
  uint32_t *v73; // r3
  uint8_t *v74; // r3
  int v75; // r2
  int *v76; // r3
  int v77; // r0
  int v78; // r7
  int *v79; // r12
  int v80; // r1
  int *v81; // r3
  uint32_t *v82; // r12
  uint32_t *v83; // r2
  int v84; // r0
  int v85; // r3
  uint8_t *v86; // r8
  int v87; // r2
  uint32_t *v88; // r2
  uint32_t *v89; // r0
  int v90; // r1
  uint8_t *v91; // r8
  int *v92; // r0
  int *v93; // r1
  unsigned int v94; // r12
  unsigned int v95; // r3
  uint8_t *v96; // r3
  int *v97; // r12
  unsigned int v98; // r3
  unsigned int v99; // r1
  int v100; // [sp+Ch] [bp-18h]
  int *v101; // [sp+Ch] [bp-18h]
  int *v102; // [sp+Ch] [bp-18h]
  char v103; // [sp+Ch] [bp-18h]
  char v104; // [sp+Ch] [bp-18h]
  int v105; // [sp+10h] [bp-14h]
  int v106; // [sp+10h] [bp-14h]
  int v107; // [sp+14h] [bp-10h]
  int v108; // [sp+14h] [bp-10h]
  uint8_t a1a[8]; // [sp+1Ch] [bp-8h] BYREF

  v8 = hci_cmd_send_short(a3);
  if ( !v8 )
  {
    v10 = (uint16_t **)off_1241C4;
    v11 = **(uint16_t **)off_1241C4;
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
              v13 = off_124198;
              v14 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v13 = off_124198;
        *((uint8_t *)off_124198 + 48) = 0;
        v14 = ke_enter_critical(*(uint32_t *)a2);
        if ( v14 )
        {
          mac_check_hw_state(*(uint32_t *)a2);
          v14 = 0;
        }
        else if ( v13[49] )
        {
          v13[49] = 0;
          if ( check_bt_addr_valid(a1a) )
            bt_conn_read_info(
              *(uint8_t *)(*(uint32_t *)a1a + 1225),
              dword_12419C + 38 * *(uint8_t *)(*(uint32_t *)a1a + 107));
        }
        goto LABEL_10;
      }
LABEL_24:
      v13 = off_124198;
      v14 = 2;
      goto LABEL_10;
    }
    if ( !(*(uint32_t *)off_124194 << 28) )
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
    mmio_irq_clear((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
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
          v61 = (uint8_t *)bt_buf_alloc(7, a4, a3, 2);
          v13 = off_124508;
          *v61 = wlc_ioctl((int)(a2 + 2), *a2, a2[8], v61 + 1);
          hci_evt_send((int)v61);
          v14 = 0;
          goto LABEL_10;
        case 8u:
LABEL_71:
          v60 = *a2;
          if ( v60 <= 3 )
            wlc_phy_attach(v60);
          if ( !*((uint32_t *)off_124544 + 2) )
            mmio_disable_irq();
          hci_evt_alloc_send(9, a4, a3);
          v13 = off_124508;
          v14 = 0;
          goto LABEL_10;
        case 0xEu:
          v11 = **v10;
LABEL_69:
          v13 = off_124508;
          v59 = *(uint32_t *)a2;
          *(uint32_t *)off_124508 = *(uint32_t *)a2;
          if ( v11 < 0 && *(uint32_t *)off_124868 << 28 )
          {
            mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v59 = *(uint32_t *)v13;
          }
          *(uint32_t *)off_124540 = v59 | *((uint32_t *)v13 + 1);
          hci_evt_alloc_send(15, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v57 = bt_buf_alloc(17, a4, a3, 2);
          v13 = off_124508;
          v58 = v57;
          gpio_init((uint16_t *)a2, a2[10]);
          hci_evt_send(v58);
          v14 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v56 = off_12453C;
          v13 = off_124508;
          *(uint32_t *)off_12453C = *(uint32_t *)off_12453C & 0xFFFFFF00 | *a2;
          *v56 |= 0x80000000;
          hci_evt_alloc_send(19, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v54 = *(uint16_t *)a2;
          v55 = dword_124538 + 1320 * a2[2];
          if ( *(uint8_t *)(v55 + 106) )
            wlc_intr_off(v55, v54);
          else
            *(uint32_t *)(dword_1244F4 + 696 * *(uint8_t *)(v55 + 116) + 8) = v54 << 10;
          hci_evt_alloc_send(21, a4, a3);
          v13 = off_124508;
          v14 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v48 = *(char **)a2;
          v49 = a2[5];
          v13 = off_124508;
          v50 = *((uint32_t *)off_124530 + 10);
          v52 = (char *)(*(uint32_t *)a2 & 0xFFFFF1FF);
          v51 = v52 == nullptr;
          v53 = v49 + 4;
          if ( v52 )
            v48 = (char *)off_124508 + 4 * v53;
          else
            v52 = (char *)off_124508 + 4 * v53;
          if ( v51 )
            *((uint32_t *)v52 + 1) = v48;
          else
            *((uint32_t *)v48 + 1) = v52;
          if ( v50 && *(uint8_t *)(v50 + 4) == v49 )
            *(uint32_t *)off_124534 = *(uint32_t *)&v13[4 * v53 + 4];
          hci_evt_alloc_send(23, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v13 = off_124508;
          memcpy_aligned((char *)(dword_124524 + 1320 * a2[6]), (char *)a2, 6u);
          v46 = off_12452C;
          v47 = *((uint16_t *)a2 + 2);
          *(uint32_t *)off_124528 = *(uint32_t *)a2;
          *v46 = v47;
          hci_evt_alloc_send(25, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_76:
          v13 = off_124508;
          *(uint32_t *)off_124548 = (*a2 << 14) & 0x1C000 | *(uint32_t *)off_124548 & 0xFFFE3FFF;
          hci_evt_alloc_send(29, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = a2[3];
          v28 = dword_124538;
          v29 = dword_124538 + 1320 * v27;
          a1a[0] = 0;
          v105 = 1320 * v27;
          v30 = reset_event_flag(a1a);
          v31 = *(uint8_t *)(v29 + 106);
          v32 = a2[2];
          *(uint8_t *)(v29 + 108) = v32;
          v100 = v30;
          if ( !v31 )
          {
            v107 = *(uint8_t *)(v29 + 116);
            if ( v32 )
            {
              v33 = dword_1244F4 + 696 * *(uint8_t *)(v29 + 116);
              v34 = (*(volatile uint32_t *)0x40501010u);
              v35 = (uint32_t *)(v105 + 24 + v28);
              ke_event_lock(v35, v34 + *(uint32_t *)(v33 + 8));
              *(uint16_t *)(v33 + 32) = *(uint16_t *)a2;
              clear_intr_status();
              state_check_feature(
                256,
                "vif state active:%d,%d,%d,%d\r\n",
                *(uint8_t *)(v33 + 35),
                *(uint16_t *)(v33 + 32),
                *(uint8_t *)(v29 + 1224),
                v100);
              v36 = off_124504;
              *(uint32_t *)off_124500 = (uint16_t)*(uint32_t *)off_124500 | (*(uint16_t *)a2 << 16);
              if ( (*v36 & 0x8000) != 0 && sys_status_get_bit21() && (*(uint32_t *)(v33 + 4) & 0x20) != 0 )
              {
                rf_channel_set(*(uint16_t *)a2);
                check_hw_status();
                state_check_feature(256, aHeEnabled);
                enable_irq();
              }
              v13 = off_124508;
              v108 = dword_1244F4 + 696 * v107;
              v37 = v28 + 1320 * v27;
              v38 = *(uint32_t *)(v37 + 4) | 1;
              *(uint16_t *)(v108 + 30) = (unsigned int)(((unsigned int)dword_12454C
                                                    * (uint64_t)(*(uint32_t *)(v108 + 8)
                                                                       * ((unsigned int)*((uint16_t *)off_124508
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
              v106 = v37;
              bt_power_state((uint32_t *)v29);
              v40 = *(uint8_t *)(v106 + 1224);
              if ( *(uint8_t *)(v106 + 1224) )
              {
                if ( !v100 )
                  goto LABEL_39;
                v74 = off_124860;
                if ( !*((uint32_t *)off_124860 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124860 + 8) = 0;
                v74[36] = 0;
                set_reg_bit();
LABEL_120:
                v75 = **v10;
                *((uint32_t *)v13 + 1) |= 0x10u;
                if ( v75 < 0 && *(uint32_t *)off_124BAC << 28 )
                  mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                *(uint32_t *)off_124894 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                v32 = a2[2];
                goto LABEL_40;
              }
              if ( v100 )
              {
                if ( v100 != 1 )
                  goto LABEL_39;
                v86 = off_124B88;
                if ( v29 == *((uint32_t *)off_124B88 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124B88 + 8) = v40;
                v103 = v40;
                ke_event_set_lock(v35);
                v86[36] = v103;
                set_reg_bit();
                v32 = a2[2];
              }
              else
              {
                if ( *((uint32_t *)off_12450C + 8) )
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
                v97 = (int *)off_124BA8;
                v98 = *(uint32_t *)(v108 + 8);
                v99 = *(uint32_t *)off_124BA8;
                *((uint32_t *)off_12450C + 8) = v29;
                *v97 = (uint16_t)(v98 >> 10) | (HIWORD(v99) << 16);
                ke_event_set_lock(v35);
                *((uint8_t *)off_124B88 + 36) = 0;
                ke_evt_wait();
                v32 = a2[2];
              }
            }
            else
            {
              ke_event_set_lock((uint32_t *)(v105 + 24 + v28));
              nullsub_8();
              state_check_feature(256, "vif state inactive:%d,%d\r\n", *(uint8_t *)(v29 + 1224), v100);
              if ( (*(uint32_t *)off_124888 & 0x8000) != 0
                && sys_status_get_bit21()
                && (*(uint32_t *)(dword_124B8C + 696 * v107 + 4) & 0x20) != 0
                && *(uint8_t *)(v29 + 106) != 4 )
              {
                tx_slot_state_get(*(uint8_t *)(v29 + 107));
              }
              v64 = v28 + 1320 * v27;
              v65 = *(uint8_t *)(v64 + 1224);
              *(uint8_t *)(v64 + 1227) = 0;
              *(uint32_t *)(v64 + 1228) = 0;
              if ( v65 )
              {
                if ( v100 )
                {
                  v76 = *((int **)off_124B84 + 2);
                  if ( v76 )
                  {
                    while ( *((uint8_t *)v76 + 106)
                         || !*((uint8_t *)v76 + 108)
                         || (int *)v29 == v76
                         || *((uint8_t *)v76 + 1224) )
                    {
                      v76 = (int *)*v76;
                      if ( !v76 )
                        goto LABEL_102;
                    }
                    if ( !*((uint32_t *)off_124B88 + 8) )
                    {
                      v77 = *((uint8_t *)v76 + 116);
                      v78 = dword_124B8C;
                      v79 = (int *)off_124BA8;
                      *((uint32_t *)off_124B88 + 8) = v76;
                      *v79 = (uint16_t)(*(uint32_t *)(v78 + 696 * v77 + 8) >> 10) | (HIWORD(*v79) << 16);
                      v102 = v76;
                      ke_event_set_lock(v76 + 6);
                      *((uint8_t *)off_124B88 + 36) = 0;
                      v13 = off_124B90;
                      ke_evt_wait();
                      v80 = **v10;
                      v81 = v102;
                      *((uint32_t *)v13 + 1) &= ~0x10u;
                      if ( v80 < 0 && *(uint32_t *)off_124BAC << 28 )
                      {
                        mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                        v81 = v102;
                      }
                      v82 = off_124BB8;
                      *(uint32_t *)off_124B94 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                      v83 = off_124B98;
                      v84 = v81[16];
                      v85 = *((uint16_t *)v81 + 34);
                      *v82 = v84;
                      *v83 = v85;
                      v32 = a2[2];
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v100 == 2 )
              {
                v91 = off_124B88;
                if ( !*((uint32_t *)off_124B88 + 8) )
                {
                  v92 = *((int **)off_124B84 + 2);
                  if ( !v92 )
LABEL_170:
                    __und(0xFFu);
                  while ( *((uint8_t *)v92 + 106) || !*((uint8_t *)v92 + 108) || (int *)v29 == v92 || *((uint8_t *)v92 + 1224) )
                  {
                    v92 = (int *)*v92;
                    if ( !v92 )
                      goto LABEL_170;
                  }
                  v93 = (int *)off_124BA8;
                  v104 = *((uint8_t *)v92 + 1224);
                  v94 = *(uint32_t *)off_124BA8;
                  v95 = *(uint32_t *)(dword_124B8C + 696 * *((uint8_t *)v92 + 116) + 8);
                  *((uint32_t *)off_124B88 + 8) = v92;
                  *v93 = (uint16_t)(v95 >> 10) | (HIWORD(v94) << 16);
                  ke_event_set_lock(v92 + 6);
                  v91[36] = v104;
                  v13 = off_124B90;
                  ke_evt_wait();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( v100 == 1 )
              {
                v96 = off_124B88;
                if ( v29 == *((uint32_t *)off_124B88 + 8) )
                {
                  *((uint32_t *)off_124B88 + 8) = 0;
                  v96[36] = 0;
                  v13 = off_124B90;
                  set_reg_bit();
                  v32 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_102:
              v32 = a2[2];
              v13 = off_124864;
            }
LABEL_40:
            rx_frame_process((uint8_t *)v29, v32);
            if ( a2[2] )
            {
              v41 = *(uint32_t **)off_124510;
              v42 = **(uint32_t **)off_124510;
              if ( v42 )
                *(uint32_t *)off_124514 = v42;
              else
                *(uint32_t *)off_124880 = *(uint32_t *)(v28 + 1320 * v27 + 8);
              v43 = v41[1];
              if ( v43 )
              {
                if ( (v43 & 0xFFF) != 0 )
                  *(uint32_t *)off_12487C = v43;
                else
                  *(uint32_t *)off_124518 = v43 & 0xFFFFF000 | *(uint32_t *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(uint32_t *)off_12487C = *(uint32_t *)(v28 + 1320 * v27 + 12);
              }
              v44 = v41[2];
              if ( v44 )
                *(uint32_t *)off_12451C = v44;
              else
                *(uint32_t *)off_124878 = *(uint32_t *)(v28 + 1320 * v27 + 16);
              v45 = v41[3];
              if ( v45 )
                *(uint32_t *)off_124520 = v45;
              else
                *(uint32_t *)off_12488C = *(uint32_t *)(v28 + 1320 * v27 + 20);
              wait_rf_calibration();
            }
            hci_evt_alloc_send(31, a4, a3);
            v14 = 0;
            goto LABEL_10;
          }
          if ( !v30 )
          {
            if ( v32 )
            {
              v62 = nullptr;
              goto LABEL_85;
            }
LABEL_86:
            v13 = off_124864;
            goto LABEL_40;
          }
          v62 = *((int **)off_124890 + 2);
          if ( v62 )
          {
            do
            {
              if ( !*((uint8_t *)v62 + 106) && *((uint8_t *)v62 + 108) && (int *)v29 != v62 && !*((uint8_t *)v62 + 1224) )
                break;
              v62 = (int *)*v62;
            }
            while ( v62 );
            if ( !v32 )
            {
              v66 = off_124860;
              if ( !*((uint32_t *)off_124860 + 8) && v62 )
              {
                *((uint32_t *)off_124860 + 8) = v62;
                v66[36] = 0;
                v101 = v62;
                v13 = off_124864;
                ke_event_set_lock(v62 + 6);
                ke_evt_wait();
                v67 = **v10;
                v68 = v101;
                *((uint32_t *)v13 + 1) &= ~0x10u;
                if ( v67 < 0 && *(uint32_t *)off_124BAC << 28 )
                {
                  mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
                  v68 = v101;
                }
                v69 = off_1248A4;
                v70 = v68[16];
                *(uint32_t *)off_124894 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
                v71 = off_124898;
                v72 = *((uint16_t *)v68 + 34);
                *v69 = v70;
                v73 = off_12489C;
                *v71 = v72;
                *v73 = dword_1248A0;
                v71[8212] &= 0xFFFBFFFE;
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
          v63 = off_124860;
          if ( v62 == *((int **)off_124860 + 8) )
          {
            *((uint32_t *)off_124860 + 8) = 0;
            v63[36] = 0;
            v13 = off_124B90;
            set_reg_bit();
            v87 = **v10;
            *((uint32_t *)v13 + 1) |= 0x10u;
            if ( v87 < 0 && *(uint32_t *)off_124BAC << 28 )
              mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_4, 472);
            v88 = off_124B94;
            v89 = off_124BA0;
            *(uint32_t *)off_124B94 = *(uint32_t *)v13 | *((uint32_t *)v13 + 1);
            v90 = dword_124BA4;
            *v89 = dword_124BA4;
            v88[8197] |= v90;
            v32 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_86;
        case 0x20u:
LABEL_32:
          v13 = off_124198;
          *(uint32_t *)off_1241BC = *a2 | (((uint8_t)*(uint32_t *)off_1241B8 * *a2) << 8);
          hci_evt_alloc_send(33, a4, a3);
          v14 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v15 = *a2;
          if ( *a2 )
          {
            if ( get_instance_handle(dword_124870 + 696 * a2[1], a2[2], *((uint16_t *)a2 + 3)) )
            {
              *(uint32_t *)off_124874 |= 0x80u;
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
            v18 = *(uint32_t *)(dword_1241AC + 4 * *((uint8_t *)off_1241A8 + v16));
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
            ke_event_schedule_1("mm_ba_add_req_handler %d, %d, %d\n", v16, v17, v19);
            v20 = *((uint16_t *)a2 + 2);
            v21 = 696 * a2[1];
            v22 = *(uint8_t *)(v21 + 12 * a2[2] + dword_1241C0 + 453);
            v23 = *((uint16_t *)a2 + 3);
            v24 = v21 + 6 * a2[2] + dword_1241C0;
            v25 = dword_1241B4 + 32 * v22;
            *(uint16_t *)(v24 + 354) = v19;
            *(uint16_t *)(v24 + 356) = v20;
            *(uint16_t *)(v25 + 12) = v23;
          }
          v26 = (uint8_t *)bt_buf_alloc(41, a4, a3, 3);
          *v26 = a2[1];
          v26[1] = a2[2];
          v26[2] = v15;
          hci_evt_send((int)v26);
          v13 = off_124198;
          v14 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          ke_int_unlock();
          v13 = off_124198;
          v14 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          tx_packet_start(a2);
          hci_evt_alloc_send(60, a4, a3);
          v13 = off_124198;
          v14 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    if ( **v10 >= 0 )
      goto LABEL_24;
LABEL_21:
    v13 = off_124198;
    mmio_irq_clear(off_1241A4, (int)aMmHwConfigHand, 2552);
    v14 = 2;
LABEL_10:
    *(uint32_t *)off_124194 = (uint8_t)(16 * v13[19]);
    hci_cmd_send(a3, (uint8_t)v13[18]);
    return v14;
  }
  if ( (uint16_t)(v8 - 2) > 2u )
  {
    v12 = off_124198;
    *((uint8_t *)off_124198 + 19) = *(uint8_t *)off_124194 & 0xF;
    v12[18] = hci_cmd_send_short(a3);
    rf_check_clk_state();
    hci_cmd_send(a3, 2);
  }
  return 2;
}
