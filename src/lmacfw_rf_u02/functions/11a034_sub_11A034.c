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


extern uint32_t dword_11A2F8;
extern uint32_t dword_11A2FC;
extern uint32_t dword_11A63C;
extern uint32_t dword_11A66C;
extern uint32_t off_11A2E4;
extern uint32_t off_11A2E8;
extern uint32_t off_11A2EC;
extern uint32_t off_11A2F0;
extern uint32_t off_11A2F4;
extern uint32_t off_11A300;
extern uint32_t off_11A304;
extern uint32_t off_11A308;
extern uint32_t off_11A648;
extern uint32_t off_11A64C;
extern uint32_t off_11A650;
extern uint32_t off_11A654;
extern uint32_t off_11A658;
extern uint32_t off_11A65C;
extern uint32_t off_11A660;
extern uint32_t off_11A664;
extern uint32_t off_11A668;
extern uint32_t off_11A670;
extern uint32_t off_11A674;
extern uint32_t off_11A678;
extern uint32_t off_11A67C;
extern uint32_t off_11A684;
extern uint32_t off_11A68C;
extern uint32_t off_11A718;
extern uint32_t off_11A71C;
extern uint32_t off_11A720;
extern uint32_t off_11A724;

// process_cmd_extended @ 0x11a034, size 1760 bytes
int  process_cmd_extended(int a1, char *a2, unsigned int a3, int a4)
{
  int v8; // r0
  uint16_t **v10; // r8
  int v11; // r3
  int *v12; // r7
  int v13; // r5
  unsigned int v14; // r5
  uint8_t *v15; // r0
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r0
  int v19; // r6
  uint32_t *v20; // r2
  int v21; // r2
  int v22; // r1
  int v23; // r3
  int v24; // r2
  unsigned int v25; // r3
  int v26; // r1
  int v27; // r0
  int v28; // zf
  unsigned int v29; // r5
  int v30; // r2
  int v31; // r7
  int v32; // r9
  int v33; // r8
  int v34; // r0
  int v35; // r11
  int v36; // r1
  volatile unsigned int v37; // r1
  volatile unsigned int v38; // r3
  uint32_t *v39; // r3
  int v40; // r2
  int v41; // r2
  int v42; // r2
  int v43; // r3
  uint32_t *v44; // r3
  int v45; // r2
  char v46; // r7
  uint8_t *v47; // r0
  int v48; // r3
  int v49; // [sp+Ch] [bp-18h]
  int v50; // [sp+10h] [bp-14h]
  int v51; // [sp+10h] [bp-14h]
  int v52; // [sp+14h] [bp-10h]
  uint8_t a1a[5]; // [sp+1Fh] [bp-5h] BYREF

  v8 = flash_write_byte(a3);
  if ( v8 )
  {
    if ( (uint16_t)(v8 - 2) > 2u )
    {
      v14 = off_11A2E4;
      *(uint8_t *)(off_11A2E4 + 0x11) = *(uint8_t *)off_11A2E8 & 0xF;
      *(uint8_t *)(v14 + 0x10) = flash_write_byte(a3);
      rf_cal_trim_check();
      flash_erase_sector(a3, 2);
    }
    return 2;
  }
  else
  {
    v10 = (uint16_t **)off_11A308;
    v11 = **(uint16_t **)off_11A308;
    if ( v11 < 0 )
    {
      if ( !(*(uint32_t *)off_11A2E8 << 28) )
      {
        switch ( a1 )
        {
          case 6:
            goto LABEL_12;
          case 8:
            goto LABEL_13;
          case 14:
            goto LABEL_19;
          case 16:
            goto LABEL_21;
          case 18:
            goto LABEL_22;
          case 20:
            goto LABEL_23;
          case 22:
            goto LABEL_27;
          case 24:
            goto LABEL_53;
          case 28:
            goto LABEL_54;
          case 30:
            goto LABEL_37;
          case 32:
            goto LABEL_52;
          case 40:
            goto LABEL_55;
          case 48:
            goto LABEL_58;
          case 59:
            goto LABEL_11;
          default:
            goto LABEL_59;
        }
      }
      flash_ctrl_init((int)aNxmacCurrentSt, (int)aMmHwConfigHand, 2493);
      switch ( a1 )
      {
        case 6:
LABEL_12:
          v15 = (uint8_t *)ke_msg_send_1(7, a4, a3, 2);
          v13 = 0;
          *v15 = 0;
          rx_irq_handler_1((int)v15);
          v12 = (int *)off_11A2E4;
          break;
        case 8:
LABEL_13:
          v16 = (uint8_t)*a2;
          if ( v16 <= 3 )
            link_context_by_index(v16);
          if ( !off_11A2EC[2] )
            rf_shutdown();
          ke_evt_handler(9, a4, a3);
          v12 = (int *)off_11A2E4;
          v13 = 0;
          break;
        case 14:
          v11 = **v10;
LABEL_19:
          v12 = (int *)off_11A2E4;
          v17 = *(uint32_t *)a2;
          *(uint32_t *)off_11A2E4 = *(uint32_t *)a2;
          if ( v11 < 0 && *(uint32_t *)off_11A68C << 28 )
          {
            flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet_3, 472);
            v17 = *v12;
          }
          *(uint32_t *)off_11A2F0 = v17 | v12[1];
          ke_evt_handler(15, a4, a3);
          v13 = 0;
          break;
        case 16:
LABEL_21:
          v18 = ke_msg_send_1(17, a4, a3, 2);
          v12 = (int *)off_11A2E4;
          v19 = v18;
          tx_set_power((uint8_t *)a2, (uint8_t)a2[10]);
          rx_irq_handler_1(v19);
          v13 = 0;
          break;
        case 18:
LABEL_22:
          v20 = off_11A2F4;
          v12 = (int *)off_11A2E4;
          *(uint32_t *)off_11A2F4 = *(uint32_t *)off_11A2F4 & 0xFFFFFF00 | (uint8_t)*a2;
          *v20 |= 0x80000000;
          ke_evt_handler(19, a4, a3);
          v13 = 0;
          break;
        case 20:
LABEL_23:
          v21 = (uint8_t)a2[2];
          v22 = *(uint16_t *)a2;
          v23 = dword_11A2F8 + 224 * v21;
          if ( *(uint8_t *)(v23 + 94) )
          {
            write_register_low16(dword_11A2F8 + 224 * v21, v22);
          }
          else
          {
            v24 = *(uint8_t *)(v23 + 102);
            if ( v24 == 255 )
              *(uint16_t *)(v23 + 100) = v22;
            else
              *(uint32_t *)(dword_11A2FC + 152 * v24 + 8) = v22 << 10;
          }
          ke_evt_handler(21, a4, a3);
          v12 = (int *)off_11A2E4;
          v13 = 0;
          break;
        case 22:
LABEL_27:
          v25 = *(uint32_t *)a2;
          v26 = (uint8_t)a2[5];
          v12 = (int *)off_11A2E4;
          v27 = off_11A300[10];
          v29 = *(uint32_t *)a2 & 0xFFFFF1FF;
          v28 = v29 == 0;
          v30 = v26 + 4;
          if ( v29 )
            v25 = off_11A2E4 + 4 * v30;
          else
            v29 = off_11A2E4 + 4 * v30;
          if ( v28 )
            *(uint32_t *)(v29 + 4) = v25;
          else
            *(uint32_t *)(v25 + 4) = v29;
          if ( v27 && *(uint8_t *)(v27 + 4) == v26 )
            *(uint32_t *)off_11A304 = v12[v30 + 1];
          ke_evt_handler(23, a4, a3);
          v13 = 0;
          break;
        case 24:
LABEL_53:
          v12 = off_11A660;
          memcpy_large((char *)(dword_11A66C + 224 * (uint8_t)a2[6] + 64), a2, 6u);
          v44 = off_11A674;
          v45 = *((uint16_t *)a2 + 2);
          *(uint32_t *)off_11A670 = *(uint32_t *)a2;
          *v44 = v45;
          ke_evt_handler(25, a4, a3);
          v13 = 0;
          break;
        case 28:
LABEL_54:
          v12 = off_11A660;
          *(uint32_t *)off_11A678 = ((uint8_t)*a2 << 14) & 0x1C000 | *(uint32_t *)off_11A678 & 0xFFFE3FFF;
          ke_evt_handler(29, a4, a3);
          v13 = 0;
          break;
        case 30:
LABEL_37:
          v31 = (uint8_t)a2[3];
          v32 = dword_11A66C;
          v33 = dword_11A66C + 224 * v31;
          a1a[0] = 0;
          v34 = reset_link_status(a1a);
          v35 = *(uint8_t *)(v33 + 94);
          v36 = (uint8_t)a2[2];
          *(uint8_t *)(v33 + 96) = v36;
          if ( !v35 )
          {
            v49 = 224 * v31;
            if ( v36 )
            {
              v52 = v34;
              v37 = (*(volatile uint32_t *)0x40501010u);
              v50 = dword_11A63C + 152 * *(uint8_t *)(v33 + 102);
              ke_enter_critical((uint32_t *)(v49 + 24 + v32), v37 + *(uint32_t *)(v50 + 8));
              *(uint16_t *)(v50 + 30) = *(uint16_t *)a2;
              clear_bb_irq();
              check_interrupt_flag(
                256,
                "vif state active:%d,%d,%d\r\n",
                *(uint8_t *)(v50 + 33),
                *(uint16_t *)(v50 + 30),
                v52);
              *(uint32_t *)off_11A648 = (uint16_t)*(uint32_t *)off_11A648 | (*(uint16_t *)a2 << 16);
              *(uint8_t *)(v33 + 116) = 0;
              *(uint32_t *)(v33 + 112) = 0;
              v38 = (*(volatile uint32_t *)0x40501010u);
              *(uint32_t *)(v33 + 108) = v38;
              rf_get_status_1((uint32_t *)(v32 + v49));
              v36 = (uint8_t)a2[2];
            }
            else
            {
              v51 = v34;
              ke_exit_critical((uint32_t *)(v49 + 24 + v32));
              check_interrupt_flag(256, "vif state inactive:%d\r\n", v51);
              if ( (*(uint32_t *)off_11A718 & 0x8000) != 0 )
                sys_status_bit21_get();
              v48 = v32 + 224 * v31;
              *(uint8_t *)(v48 + 140) = 0;
              *(uint32_t *)(v48 + 144) = 0;
              v36 = (uint8_t)a2[2];
            }
          }
          if ( v36 )
          {
            v39 = *(uint32_t **)off_11A64C;
            v40 = **(uint32_t **)off_11A64C;
            if ( v40 )
              *(uint32_t *)off_11A650 = v40;
            else
              *(uint32_t *)off_11A724 = *(uint32_t *)(v32 + 224 * v31 + 8);
            v41 = v39[1];
            if ( v41 )
            {
              if ( (v41 & 0xFFF) != 0 )
                *(uint32_t *)off_11A720 = v41;
              else
                *(uint32_t *)off_11A654 = v41 & 0xFFFFF000 | *(uint32_t *)(v32 + 224 * v31 + 12) & 0xFFF;
            }
            else
            {
              *(uint32_t *)off_11A720 = *(uint32_t *)(v32 + 224 * v31 + 12);
            }
            v42 = v39[2];
            if ( v42 )
              *(uint32_t *)off_11A658 = v42;
            else
              *(uint32_t *)off_11A71C = *(uint32_t *)(v32 + 224 * v31 + 16);
            v43 = v39[3];
            if ( v43 )
              *(uint32_t *)off_11A65C = v43;
            else
              *(uint32_t *)off_11A65C = *(uint32_t *)(v32 + 224 * v31 + 20);
            poll_hw_status_1();
          }
          ke_evt_handler(31, a4, a3);
          v12 = off_11A660;
          v13 = 0;
          break;
        case 32:
LABEL_52:
          v12 = off_11A660;
          *(uint32_t *)off_11A668 = (uint8_t)*a2
                                | (((uint8_t)*(uint32_t *)off_11A664 * (uint8_t)*a2) << 8);
          ke_evt_handler(33, a4, a3);
          v13 = 0;
          break;
        case 40:
LABEL_55:
          if ( *a2 )
          {
            *(uint32_t *)off_11A67C |= 0x80u;
            v46 = 0;
          }
          else
          {
            v46 = 5;
          }
          v47 = (uint8_t *)ke_msg_send_1(41, a4, a3, 3);
          *v47 = a2[1];
          v47[1] = a2[2];
          v47[2] = v46;
          rx_irq_handler_1((int)v47);
          v12 = off_11A660;
          v13 = 0;
          break;
        case 48:
LABEL_58:
          ke_int_unlock();
          v12 = off_11A660;
          v13 = 0;
          break;
        case 59:
LABEL_11:
          rx_desc_parse((uint8_t *)a2);
          ke_evt_handler(60, a4, a3);
          v12 = (int *)off_11A2E4;
          v13 = 0;
          break;
        default:
          if ( **v10 < 0 )
          {
LABEL_59:
            v12 = off_11A660;
            flash_ctrl_init(off_11A684, (int)aMmHwConfigHand, 2552);
            v13 = 2;
          }
          else
          {
            v12 = off_11A660;
            v13 = 2;
          }
          break;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 6:
          goto LABEL_12;
        case 8:
          goto LABEL_13;
        case 14:
          goto LABEL_19;
        case 16:
          goto LABEL_21;
        case 18:
          goto LABEL_22;
        case 20:
          goto LABEL_23;
        case 22:
          goto LABEL_27;
        case 24:
          goto LABEL_53;
        case 28:
          goto LABEL_54;
        case 30:
          goto LABEL_37;
        case 32:
          goto LABEL_52;
        case 40:
          goto LABEL_55;
        case 48:
          goto LABEL_58;
        case 59:
          goto LABEL_11;
        default:
          v12 = (int *)off_11A2E4;
          v13 = 2;
          break;
      }
    }
    *(uint32_t *)off_11A2E8 = (uint8_t)(16 * *((uint8_t *)v12 + 17));
    flash_erase_sector(a3, *((uint8_t *)v12 + 16));
    return v13;
  }
}
