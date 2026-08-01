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

extern uint32_t off_123F90;
extern uint32_t off_123F64;
extern uint32_t dword_123F68;
extern uint32_t off_123F60;
extern uint32_t dword_124628;
extern uint32_t dword_124624;
extern uint32_t off_1242D4;
extern uint32_t off_124310;
extern uint32_t off_124634;
extern uint32_t dword_124638;
extern uint32_t off_12430C;
extern uint32_t off_124308;
extern uint32_t dword_124304;
extern uint32_t dword_1242C0;
extern uint32_t off_1242FC;
extern uint32_t off_124300;
extern uint32_t dword_1242F0;
extern uint32_t off_1242F8;
extern uint32_t off_1242F4;
extern uint32_t off_124314;
extern uint32_t off_1242C4;
extern uint32_t dword_1242C8;
extern uint32_t off_1242D0;
extern uint32_t off_1242CC;
extern uint32_t dword_124968;
extern uint32_t dword_124318;
extern uint32_t off_12462C;
extern uint32_t off_124978;
extern uint32_t dword_124980;
extern uint32_t dword_12497C;
extern uint32_t off_124660;
extern uint32_t off_124954;
extern uint32_t off_1242D8;
extern uint32_t off_124974;
extern uint32_t dword_124650;
extern uint32_t off_124654;
extern uint32_t dword_124958;
extern uint32_t off_124950;
extern uint32_t off_12495C;
extern uint32_t off_124984;
extern uint32_t off_124960;
extern uint32_t off_124964;
extern uint32_t off_124630;
extern uint32_t off_1242DC;
extern uint32_t off_1242E0;
extern uint32_t off_12464C;
extern uint32_t off_124648;
extern uint32_t off_1242E4;
extern uint32_t off_1242E8;
extern uint32_t off_124644;
extern uint32_t off_1242EC;
extern uint32_t off_124658;
extern uint32_t off_12465C;
extern uint32_t off_124670;
extern uint32_t off_124664;
extern uint32_t off_124668;
extern uint32_t dword_12466C;
extern uint32_t off_12496C;
extern uint32_t dword_124970;
extern uint32_t off_123F88;
extern uint32_t off_123F84;
extern uint32_t dword_12463C;
extern uint32_t off_124640;
extern uint32_t dword_123F78;
extern uint32_t dword_123F74;
extern uint32_t dword_123F7C;
extern uint32_t dword_123F8C;
extern uint32_t dword_123F80;
extern uint32_t dword_123F70;
extern uint32_t dword_123F6C;

// rf_calibration_do @ 0x123c8c, size 3268 bytes
// write access to const memory has been detected, the output may be wrong!
int  rf_calibration_do(unsigned int a1, uint8_t *a2, uint32_t *a3, int a4)
{
  int value; // r0
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

  value = rx_rate_field_parse(a3);
  if ( !value )
  {
    v11 = (int16_t **)off_123F90;
    v12 = **(int16_t **)off_123F90;
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
              v15 = off_123F64;
              v16 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v15 = off_123F64;
        *((uint8_t *)off_123F64 + 48) = 0;
        v16 = util_abs(*(uint32_t *)a2);
        if ( v16 )
        {
          chip_state_handler(*(uint32_t *)a2);
          v16 = 0;
        }
        else if ( v15[49] )
        {
          v15[49] = 0;
          if ( llm_adv_param_check(v136) )
            rf_calib_params_get(
              *(uint8_t *)(*(uint32_t *)v136 + 1225),
              dword_123F68 + 38 * *(uint8_t *)(*(uint32_t *)v136 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(uint32_t *)off_123F60 << 28 )
    {
      mmio_clear_register(dword_124628, dword_124624, 2493);
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
            *(uint32_t *)(a4 + 20) = &jpt_12433E;
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
            *(uint32_t *)(uintptr_t)(0x124480 + 3 * 4) = v114;
            *(uint8_t *)(v113 + 17) = v112;
            *(uint32_t *)(uintptr_t)(0x1244AA) = v114;
            *(uint32_t *)(v112 + 20) = v115;
            v116 = *(uint32_t *)(v112 + 100);
            v117 = *(uint32_t *)(v113 + 68);
            *(uint32_t *)(v117 + 68) = v117;
            v118 = *(int16_t *)(2 * v117);
            *(uint8_t *)(v118 + 17) = *(uint32_t *)(v118 + 100);
            *(uint32_t *)(v113 + 84) = v114;
            v119 = *(int16_t *)(v116 + v118);
            *(uint32_t *)(v116 + 100) = v64;
            *(uint32_t *)(uintptr_t)(0x1244EA) = v114;
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
            *(uint32_t *)(uintptr_t)(0x124480 + 3 * 4) = v114;
            *(uint8_t *)(2 * v118 + 0x11) = v118;
            *(uint32_t *)(uintptr_t)(0x1244AA) = v114;
            *(uint32_t *)(v118 + 20) = v123;
            v124 = *(uint32_t *)(v118 + 100);
            v125 = *(uint32_t *)(2 * v118 + 0x44);
            *(uint32_t *)(v124 + 84) = (uint32_t *)(uintptr_t)(0x124476);
            *(uint32_t *)(v125 + 84) = v124;
            *(uint32_t *)(2 * v125 + 0x54) = v114;
            v126 = *(uint32_t *)(*(int16_t *)(v124 + v125) + 4);
            *(uint32_t *)(v125 + 84) = v124;
            *(uint8_t *)(v124 + 17) = v126;
            *(uint8_t *)(v125 + 1) = v114;
            JUMPOUT(0x144370);
          default:
            break;
        }
      }
      if ( **v11 >= 0 )
      {
LABEL_24:
        v15 = off_123F64;
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
          v63 = (uint8_t *)ke_msg_alloc(7, a4, a3, 2);
          v15 = off_1242D4;
          *v63 = task_event_handler((int *)(a2 + 2), *a2, a2[8], v63 + 1);
          ke_msg_send(v63);
          v16 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v62 = *a2;
          if ( v62 <= 3 )
            v62 = get_object_by_index(v62);
          if ( !*((uint32_t *)off_124310 + 2) )
            mmio_disable_bit(v62, v9);
          ke_msg_send_no_param(9, a4, a3);
          v15 = off_1242D4;
          v16 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v15 = off_1242D4;
          v61 = *(uint32_t *)a2;
          *(uint32_t *)off_1242D4 = *(uint32_t *)a2;
          if ( v12 < 0 && *(uint32_t *)off_124634 << 28 )
          {
            call_shared_handler(dword_124628, dword_124638, 472);
            v61 = *(uint32_t *)v15;
          }
          *(uint32_t *)off_12430C = v61 | *((uint32_t *)v15 + 1);
          ke_msg_send_no_param(15, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v59 = ke_msg_alloc(17, a4, a3, 2);
          v15 = off_1242D4;
          v60 = v59;
          rf_enable((uint16_t *)a2, a2[10]);
          ke_msg_send(v60);
          v16 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v58 = off_124308;
          v15 = off_1242D4;
          *(uint32_t *)off_124308 = *(uint32_t *)off_124308 & 0xFFFFFF00 | *a2;
          *v58 |= 0x80000000;
          ke_msg_send_no_param(19, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v56 = *(uint16_t *)a2;
          v57 = dword_124304 + 1320 * a2[2];
          if ( *(uint8_t *)(v57 + 106) )
            set_attribute_word(v57, v56);
          else
            *(uint32_t *)(dword_1242C0 + 696 * *(uint8_t *)(v57 + 116) + 8) = v56 << 10;
          ke_msg_send_no_param(21, a4, a3);
          v15 = off_1242D4;
          v16 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v50 = *(char **)a2;
          v51 = a2[5];
          v15 = off_1242D4;
          v52 = *((uint32_t *)off_1242FC + 10);
          v54 = (char *)(*(uint32_t *)a2 & 0xFFFFF1FF);
          v53 = v54 == 0;
          v55 = v51 + 4;
          if ( v54 )
            v50 = (char *)off_1242D4 + 4 * v55;
          else
            v54 = (char *)off_1242D4 + 4 * v55;
          if ( v53 )
            *((uint32_t *)v54 + 1) = v50;
          else
            *((uint32_t *)v50 + 1) = v54;
          if ( v52 && *(uint8_t *)(v52 + 4) == v51 )
            *(uint32_t *)off_124300 = *(uint32_t *)&v15[4 * v55 + 4];
          ke_msg_send_no_param(23, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v15 = off_1242D4;
          memcpy(dword_1242F0 + 1320 * a2[6], a2, 6);
          v48 = off_1242F8;
          v49 = *((uint16_t *)a2 + 2);
          *(uint32_t *)off_1242F4 = *(uint32_t *)a2;
          *v48 = v49;
          ke_msg_send_no_param(25, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v15 = off_1242D4;
          *(uint32_t *)off_124314 = (*a2 << 14) & 0x1C000 | *(uint32_t *)off_124314 & 0xFFFE3FFF;
          ke_msg_send_no_param(29, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v29 = a2[3];
          v30 = dword_124304;
          v31 = (uint8_t *)(dword_124304 + 1320 * v29);
          v136[0] = 0;
          v132 = 1320 * v29;
          v32 = clear_device_flag(v136);
          v33 = v31[106];
          v34 = a2[2];
          v31[108] = v34;
          v127 = v32;
          if ( !v33 )
          {
            v134 = v31[116];
            if ( v34 )
            {
              v35 = dword_1242C0 + 696 * v31[116];
              v36 = v132 + 24 + v30;
              unknown_worker(v36, *((uint32_t *)off_1242C4 + 4) + *(uint32_t *)(v35 + 8));
              *(uint16_t *)(v35 + 32) = *(uint16_t *)a2;
              clear_irq_if_idle();
              check_status_bits(256, dword_1242C8);
              v37 = off_1242D0;
              *(uint32_t *)off_1242CC = (uint16_t)*(uint32_t *)off_1242CC | (*(uint16_t *)a2 << 16);
              if ( (*v37 & 0x8000) != 0 && rf_get_status_bit21() && (*(uint32_t *)(v35 + 4) & 0x20) != 0 )
              {
                rf_set_channel(*(uint16_t *)a2);
                check_radio_interrupt();
                check_status_bits(256, dword_124968);
                mmio_set_radio_bit();
              }
              v15 = off_1242D4;
              v135 = dword_1242C0 + 696 * v134;
              v38 = v30 + 1320 * v29;
              v39 = *(uint32_t *)(v38 + 4) | 1;
              *(uint16_t *)(v135 + 30) = (unsigned int)(((unsigned int)dword_124318
                                                    * (unsigned uint64_t)(*(uint32_t *)(v135 + 8)
                                                                       * ((unsigned int)*((uint16_t *)off_1242D4
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v40 = off_1242C4;
              *(uint16_t *)(v38 + 112) = 0;
              *(uint8_t *)(v38 + 114) = 0;
              *(uint8_t *)(v38 + 148) = 0;
              *(uint8_t *)(v38 + 128) = 0;
              *(uint32_t *)(v38 + 124) = 0;
              *(uint32_t *)(v38 + 4) = v39;
              *(uint32_t *)(v38 + 120) = v40[4];
              v133 = v38;
              v41 = tx_enqueue_frame(v31);
              v42 = *(uint8_t *)(v133 + 1224);
              if ( *(uint8_t *)(v133 + 1224) )
              {
                if ( !v127 )
                  goto LABEL_39;
                v81 = off_12462C;
                if ( !*((uint32_t *)off_12462C + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_12462C + 8) = 0;
                v81[36] = 0;
                wlc_mmio_clock_enable(v41);
LABEL_119:
                v82 = **v11;
                *((uint32_t *)v15 + 1) |= 0x10u;
                if ( v82 < 0 && *(uint32_t *)off_124978 << 28 )
                  call_shared_handler(dword_124980, dword_12497C, 472);
                *(uint32_t *)off_124660 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                v34 = a2[2];
                goto LABEL_40;
              }
              if ( v127 )
              {
                if ( v127 != 1 )
                  goto LABEL_39;
                v94 = off_124954;
                if ( v31 == *((uint8_t **)off_124954 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124954 + 8) = v42;
                v130 = v42;
                v95 = fault_handler(v36);
                v94[36] = v130;
                wlc_mmio_clock_enable(v95);
                v34 = a2[2];
              }
              else
              {
                if ( *((uint32_t *)off_1242D8 + 8) )
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
                v107 = (int *)off_124974;
                v108 = *(uint32_t *)(v135 + 8);
                v109 = *(uint32_t *)off_124974;
                *((uint32_t *)off_1242D8 + 8) = v31;
                *v107 = (uint16_t)(v108 >> 10) | (HIWORD(v109) << 16);
                v110 = fault_handler(v36);
                *((uint8_t *)off_124954 + 36) = 0;
                wlc_mmio_regs(v110);
                v34 = a2[2];
              }
            }
            else
            {
              v68 = fault_handler(v132 + 24 + v30);
              nullsub_8(v68);
              v69 = check_status_bits(256, dword_124650);
              if ( (*(uint32_t *)off_124654 & 0x8000) != 0 )
              {
                v69 = rf_get_status_bit21();
                if ( v69 )
                {
                  if ( (*(uint32_t *)(dword_124958 + 696 * v134 + 4) & 0x20) != 0 && v31[106] != 4 )
                    v69 = tx_queue_entry_get(v31[107]);
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
                  v83 = *((uint8_t **)off_124950 + 2);
                  if ( v83 )
                  {
                    while ( v83[106] || !v83[108] || v31 == v83 || v83[1224] )
                    {
                      v83 = *(uint8_t **)v83;
                      if ( !v83 )
                        goto LABEL_101;
                    }
                    if ( !*((uint32_t *)off_124954 + 8) )
                    {
                      v84 = v83[116];
                      v85 = dword_124958;
                      v86 = (int *)off_124974;
                      *((uint32_t *)off_124954 + 8) = v83;
                      *v86 = (uint16_t)(*(uint32_t *)(v85 + 696 * v84 + 8) >> 10) | (HIWORD(*v86) << 16);
                      v129 = v83;
                      v87 = fault_handler(v83 + 24);
                      *((uint8_t *)off_124954 + 36) = 0;
                      v15 = off_12495C;
                      wlc_mmio_regs(v87);
                      v88 = **v11;
                      v89 = v129;
                      *((uint32_t *)v15 + 1) &= ~0x10u;
                      if ( v88 < 0 && *(uint32_t *)off_124978 << 28 )
                      {
                        call_shared_handler(dword_124980, dword_12497C, 472);
                        v89 = v129;
                      }
                      v90 = off_124984;
                      *(uint32_t *)off_124960 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                      v91 = off_124964;
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
                v100 = off_124954;
                if ( !*((uint32_t *)off_124954 + 8) )
                {
                  v101 = *((uint8_t **)off_124950 + 2);
                  if ( !v101 )
LABEL_169:
                    __und(0xFFu);
                  while ( v101[106] || !v101[108] || v31 == v101 || v101[1224] )
                  {
                    v101 = *(uint8_t **)v101;
                    if ( !v101 )
                      goto LABEL_169;
                  }
                  v102 = (int *)off_124974;
                  v131 = v101[1224];
                  v103 = *(uint32_t *)off_124974;
                  v104 = *(uint32_t *)(dword_124958 + 696 * v101[116] + 8);
                  *((uint32_t *)off_124954 + 8) = v101;
                  *v102 = (uint16_t)(v104 >> 10) | (HIWORD(v103) << 16);
                  v105 = fault_handler(v101 + 24);
                  v100[36] = v131;
                  v15 = off_12495C;
                  wlc_mmio_regs(v105);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
              else if ( v127 == 1 )
              {
                v106 = off_124954;
                if ( v31 == *((uint8_t **)off_124954 + 8) )
                {
                  *((uint32_t *)off_124954 + 8) = 0;
                  v106[36] = 0;
                  v15 = off_12495C;
                  wlc_mmio_clock_enable(v69);
                  v34 = a2[2];
                  goto LABEL_40;
                }
              }
LABEL_101:
              v34 = a2[2];
              v15 = off_124630;
            }
LABEL_40:
            llc_get_local_state_idx(v31, v34);
            if ( a2[2] )
            {
              v43 = *(uint32_t **)off_1242DC;
              v44 = **(uint32_t **)off_1242DC;
              if ( v44 )
                *(uint32_t *)off_1242E0 = v44;
              else
                *(uint32_t *)off_12464C = *(uint32_t *)(v30 + 1320 * v29 + 8);
              v45 = v43[1];
              if ( v45 )
              {
                if ( (v45 & 0xFFF) != 0 )
                  *(uint32_t *)off_124648 = v45;
                else
                  *(uint32_t *)off_1242E4 = v45 & 0xFFFFF000 | *(uint32_t *)(v30 + 1320 * v29 + 12) & 0xFFF;
              }
              else
              {
                *(uint32_t *)off_124648 = *(uint32_t *)(v30 + 1320 * v29 + 12);
              }
              v46 = v43[2];
              if ( v46 )
                *(uint32_t *)off_1242E8 = v46;
              else
                *(uint32_t *)off_124644 = *(uint32_t *)(v30 + 1320 * v29 + 16);
              v47 = v43[3];
              if ( v47 )
                *(uint32_t *)off_1242EC = v47;
              else
                *(uint32_t *)off_124658 = *(uint32_t *)(v30 + 1320 * v29 + 20);
              read_hw_register();
            }
            ke_msg_send_no_param(31, a4, a3);
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
            v15 = off_124630;
            goto LABEL_40;
          }
          v66 = *((uint8_t **)off_12465C + 2);
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
              v72 = off_12462C;
              if ( !*((uint32_t *)off_12462C + 8) && v66 )
              {
                *((uint32_t *)off_12462C + 8) = v66;
                v72[36] = 0;
                v128 = v66;
                v15 = off_124630;
                v73 = fault_handler(v66 + 24);
                wlc_mmio_regs(v73);
                v74 = **v11;
                v75 = v128;
                *((uint32_t *)v15 + 1) &= ~0x10u;
                if ( v74 < 0 && *(uint32_t *)off_124978 << 28 )
                {
                  call_shared_handler(dword_124980, dword_12497C, 472);
                  v75 = v128;
                }
                v76 = off_124670;
                v77 = *((uint32_t *)v75 + 16);
                *(uint32_t *)off_124660 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
                v78 = off_124664;
                v79 = *((uint16_t *)v75 + 34);
                *v76 = v77;
                v80 = off_124668;
                *v78 = v79;
                *v80 = dword_12466C;
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
          v67 = off_12462C;
          if ( v66 == *((uint8_t **)off_12462C + 8) )
          {
            *((uint32_t *)off_12462C + 8) = 0;
            v67[36] = 0;
            v15 = off_12495C;
            ((void (*)(void))wlc_mmio_clock_enable)();
            v96 = **v11;
            *((uint32_t *)v15 + 1) |= 0x10u;
            if ( v96 < 0 && *(uint32_t *)off_124978 << 28 )
              call_shared_handler(dword_124980, dword_12497C, 472);
            v97 = off_124960;
            v98 = off_12496C;
            *(uint32_t *)off_124960 = *(uint32_t *)v15 | *((uint32_t *)v15 + 1);
            v99 = dword_124970;
            *v98 = dword_124970;
            v97[8197] |= v99;
            v34 = a2[2];
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v15 = off_123F64;
          *(uint32_t *)off_123F88 = *a2 | (((uint8_t)*(uint32_t *)off_123F84 * *a2) << 8);
          ke_msg_send_no_param(33, a4, a3);
          v16 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v17 = *a2;
          if ( *a2 )
          {
            if ( tx_desc_release(dword_12463C + 696 * a2[1], a2[2], *((uint16_t *)a2 + 3)) )
            {
              *(uint32_t *)off_124640 |= 0x80u;
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
            v20 = *(uint32_t *)(dword_123F78 + 4 * *(uint8_t *)(dword_123F74 + v18));
            if ( (int)v19 >= v20 )
            {
              if ( v19 > 0x40 )
                LOWORD(v21) = *(uint32_t *)(dword_123F78 + 4 * *(uint8_t *)(dword_123F74 + v18));
              else
                LOWORD(v21) = v20 / 2;
            }
            else
            {
              v21 = v19 >> 1;
            }
            event_dispatch(dword_123F7C, v18, v19);
            v22 = *((uint16_t *)a2 + 2);
            v23 = 696 * a2[1];
            v24 = *(uint8_t *)(v23 + 12 * a2[2] + dword_123F8C + 453);
            v25 = *((uint16_t *)a2 + 3);
            v26 = v23 + 6 * a2[2] + dword_123F8C;
            v27 = dword_123F80 + 32 * v24;
            *(uint16_t *)(v26 + 354) = v21;
            *(uint16_t *)(v26 + 356) = v22;
            *(uint16_t *)(v27 + 12) = v25;
          }
          v28 = (uint8_t *)ke_msg_alloc(41, a4, a3, 3);
          *v28 = a2[1];
          v28[1] = a2[2];
          v28[2] = v17;
          ke_msg_send(v28);
          v15 = off_123F64;
          v16 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          bad_func_0x12f4b8(a2);
          v15 = off_123F64;
          v16 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          rx_parse_header(a2);
          ke_msg_send_no_param(60, a4, a3);
          v15 = off_123F64;
          v16 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v15 = off_123F64;
    mmio_clear_register(dword_123F70, dword_123F6C, 2552);
    v16 = 2;
LABEL_10:
    *(uint32_t *)off_123F60 = (uint8_t)(16 * v15[19]);
    rx_phy_status_parse(a3);
    return v16;
  }
  if ( (uint16_t)(value - 2) > 2u )
  {
    v13 = off_123F64;
    *((uint8_t *)off_123F64 + 19) = *(uint8_t *)off_123F60 & 0xF;
    v14 = rx_rate_field_parse(a3);
    v13[18] = v14;
    read_cal_trim(v14);
    rx_phy_status_parse(a3);
  }
  return 2;
}

