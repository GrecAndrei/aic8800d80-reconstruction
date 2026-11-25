// mmio_write_dword @ 0x119d70
int mmio_write_dword(int a1, int a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r3
  int v7; // r4
  BOOL v8; // r0
  int v9; // r3

  v4 = ke_msg_send_1(5, a4, a3, 28);
  v5 = (void *)(uintptr_t)(off_119E30);
  *(volatile uint32_t *)v4 = dword_119E34;
  v6 = (void *)(uintptr_t)(off_119E38);
  *(volatile uint32_t *)(v4 + 4) = *v5;
  *(volatile uint32_t *)(v4 + 8) = *v6;
  *(volatile uint16_t *)(v4 + 24) = 4;
  *(volatile uint8_t *)(v4 + 26) = 4;
  v7 = v4;
  chip_id_get((volatile uint32_t *)(v4 + 12), (volatile uint32_t *)(v4 + 16));
  *(volatile uint32_t *)(v7 + 20) = 0;
  if ( (*v5 & 0x20000) != 0 && sys_status_bit28_get() )
  {
    *(volatile uint32_t *)(v7 + 20) |= 0x400u;
    if ( (*(volatile uint32_t *)off_119E30 & 0x20000) == 0 )
      goto LABEL_3;
  }
  else if ( (*(volatile uint32_t *)off_119E30 & 0x20000) == 0 )
  {
    goto LABEL_3;
  }
  if ( sys_status_bit30_get() )
    *(volatile uint32_t *)(v7 + 20) |= 0x4000u;
LABEL_3:
  if ( (*(volatile uint32_t *)off_119E30 & 0x2000) != 0 )
    *(volatile uint32_t *)(v7 + 20) |= 0x1000u;
  if ( is_initialized() )
    *(volatile uint32_t *)(v7 + 20) |= 0x200u;
  if ( (*(volatile uint32_t *)off_119E30 & 0x8000) != 0 && sys_status_bit21_get() )
    *(volatile uint32_t *)(v7 + 20) |= 0x800000u;
  v8 = sys_ready_check();
  v9 = *(volatile uint32_t *)(v7 + 20);
  if ( v8 )
    v9 |= 0x80000u;
  *(volatile uint32_t *)(v7 + 20) = v9 | 0x200000;
  rx_irq_handler_1(v7);
  return 0;
}



// rf_get_rssi_1 @ 0x119e3c
int rf_get_rssi_1(int a1, int a2, unsigned int a3, int a4) {
  volatile int16_t **v4; // r8
  int v5; // r0
  int v9; // r2
  struct __attribute__((packed)) { uint32_t v11[2]; // [sp+0h] [bp-20h] BYREF
  char _pad1[1]; char v12; // [sp+9h] [bp-17h]
  char _pad2[2]; uint32_t v13[5]; // [sp+Ch] [bp-14h] BYREF
  } _frame;
  v4 = (volatile int16_t **)off_119F0C;
  v5 = **(volatile int16_t **)off_119F0C;
  memset((void *)(_frame.v13), 0, sizeof(_frame.v13));
  if ( v5 < 0 && flash_write_byte(a3) )
    flash_ctrl_init((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  wifi_set_channel((volatile int *)a2);
  v9 = dword_119EF8;
  *(volatile uint8_t *)off_119EF4 = 1;
  _frame.v11[0] = v9;
  _frame.v11[1] = 2412;
  _frame.v12 = 0;
  tx_set_power((volatile uint8_t *)_frame.v11, 0);
  util_byte_to_hex(15);
  rf_wait_timeout((int)_frame.v13);
  if ( **v4 < 0 && (uint8_t)a4 > 5u )
  {
    flash_ctrl_init((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    if ( (a4 & 0xFC) != 0 )
      goto LABEL_7;
LABEL_4:
    write_bb_control();
    return 0;
  }
  if ( (a4 & 0xFC) == 0 )
    goto LABEL_4;
LABEL_7:
  ke_evt_handler(3, a4, a3);
  write_bb_control();
  return 0;
}


// rf_check_rssi @ 0x119f10
int rf_check_rssi(int a1, void ( **a2)(int), unsigned int a3) {
  volatile int16_t **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (volatile int16_t **)off_119F88;
  if ( **(volatile int16_t **)off_119F88 < 0 && flash_write_byte(a3) == 4 )
    flash_ctrl_init((int)aKeStateGetDest_0, (int)aMmForceIdleReq_0, 1587);
  result = flash_write_byte(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      rf_cal_trim_check();
      flash_erase_sector(a3, 2);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(volatile uint32_t *)off_119F94 << 28 )
      flash_ctrl_init((int)aNxmacCurrentSt, (int)aMmForceIdleReq_0, 1594);
    v7 = flash_erase_sector(a3, 3);
    (*a2)(v7);
    return 0;
  }
  return result;
}


// process_cmd_result @ 0x119f9c
int process_cmd_result(int a1, volatile uint8_t *a2, unsigned int a3, int a4) {
  int v7; // r2
  volatile int *v8; // r5
  int result; // r0

  if ( flash_write_byte(a3) == 3 || flash_write_byte(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = (void *)(uintptr_t)(off_11A020);
  *((volatile uint8_t *)off_11A020 + 28) = v7;
  if ( !v7 )
  {
    if ( flash_write_byte(a3) != 2 )
    {
      write_bb_control();
LABEL_6:
      ke_evt_handler(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = flash_write_byte(a3);
  if ( !result )
  {
    if ( **(volatile int16_t **)off_11A024 < 0 )
    {
      if ( *(volatile uint32_t *)off_11A028 << 28 )
        flash_ctrl_init((int)aNxmacCurrentSt, (int)aMmSetIdleReqHa, 1522);
    }
    *((volatile uint16_t *)v8 + 8) = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    rf_cal_trim_check();
    flash_erase_sector(a3, 2);
    return 2;
  }
  return result;
}


// process_cmd_extended @ 0x11a034
int process_cmd_extended(int a1, volatile char *a2, unsigned int a3, int a4) {
  int v8; // r0
  volatile int16_t **v10; // r8
  int v11; // r3
  volatile int *v12; // r7
  int v13; // r5
  unsigned int v14; // r5
  volatile uint8_t *v15; // r0
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r0
  int v19; // r6
  volatile uint32_t *v20; // r2
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
  volatile uint32_t *v39; // r3
  int v40; // r2
  int v41; // r2
  int v42; // r2
  int v43; // r3
  volatile uint32_t *v44; // r3
  int v45; // r2
  char v46; // r7
  volatile uint8_t *v47; // r0
  int v48; // r3
  struct __attribute__((packed)) { int v49; // [sp+Ch] [bp-18h]
  union { int v50; // [sp+10h] [bp-14h]
  int v51; }; // [sp+10h] [bp-14h]
  int v52; // [sp+14h] [bp-10h]
  char _pad3[7]; uint8_t a1a[5]; // [sp+1Fh] [bp-5h] BYREF
  } _frame;
  v8 = flash_write_byte(a3);
  if ( v8 )
  {
    if ( (uint16_t)(v8 - 2) > 2u )
    {
      v14 = off_11A2E4;
      *(volatile uint8_t *)(off_11A2E4 + 0x11) = *(volatile uint8_t *)off_11A2E8 & 0xF;
      *(volatile uint8_t *)(v14 + 0x10) = flash_write_byte(a3);
      rf_cal_trim_check();
      flash_erase_sector(a3, 2);
    }
    return 2;
  }
  else
  {
    v10 = (volatile int16_t **)off_11A308;
    v11 = **(volatile int16_t **)off_11A308;
    if ( v11 < 0 )
    {
      if ( !(*(volatile uint32_t *)off_11A2E8 << 28) )
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
          v15 = (volatile uint8_t *)ke_msg_send_1(7, a4, a3, 2);
          v13 = 0;
          *v15 = 0;
          rx_irq_handler_1((int)v15);
          v12 = (volatile int *)off_11A2E4;
          break;
        case 8:
LABEL_13:
          v16 = (uint8_t)*a2;
          if ( v16 <= 3 )
            link_context_by_index(v16);
if ( !((volatile uint32_t *)(uintptr_t)off_11A2EC)[2] ) rf_shutdown();
          ke_evt_handler(9, a4, a3);
          v12 = (volatile int *)off_11A2E4;
          v13 = 0;
          break;
        case 14:
          v11 = **v10;
LABEL_19:
          v12 = (volatile int *)off_11A2E4;
          v17 = *(volatile uint32_t *)a2;
          *(volatile uint32_t *)off_11A2E4 = *(volatile uint32_t *)a2;
          if ( v11 < 0 && *(volatile uint32_t *)off_11A68C << 28 )
          {
            flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet_3, 472);
            v17 = *v12;
          }
          *(volatile uint32_t *)off_11A2F0 = v17 | v12[1];
          ke_evt_handler(15, a4, a3);
          v13 = 0;
          break;
        case 16:
LABEL_21:
          v18 = ke_msg_send_1(17, a4, a3, 2);
          v12 = (volatile int *)off_11A2E4;
          v19 = v18;
          tx_set_power((volatile uint8_t *)a2, (uint8_t)a2[10]);
          rx_irq_handler_1(v19);
          v13 = 0;
          break;
        case 18:
LABEL_22:
          v20 = (void *)(uintptr_t)(off_11A2F4);
          v12 = (volatile int *)off_11A2E4;
          *(volatile uint32_t *)off_11A2F4 = *(volatile uint32_t *)off_11A2F4 & 0xFFFFFF00 | (uint8_t)*a2;
          *v20 |= 0x80000000;
          ke_evt_handler(19, a4, a3);
          v13 = 0;
          break;
        case 20:
LABEL_23:
          v21 = (uint8_t)a2[2];
          v22 = *(volatile uint16_t *)a2;
          v23 = dword_11A2F8 + 224 * v21;
          if ( *(volatile uint8_t *)(v23 + 94) )
          {
            write_register_low16(dword_11A2F8 + 224 * v21, v22);
          }
          else
          {
            v24 = *(volatile uint8_t *)(v23 + 102);
            if ( v24 == 255 )
              *(volatile uint16_t *)(v23 + 100) = v22;
            else
              *(volatile uint32_t *)(dword_11A2FC + 152 * v24 + 8) = v22 << 10;
          }
          ke_evt_handler(21, a4, a3);
          v12 = (volatile int *)off_11A2E4;
          v13 = 0;
          break;
        case 22:
LABEL_27:
          v25 = *(volatile uint32_t *)a2;
          v26 = (uint8_t)a2[5];
          v12 = (volatile int *)off_11A2E4;
          v27 = ((volatile uint32_t *)(uintptr_t)off_11A300)[10];
          v29 = *(volatile uint32_t *)a2 & 0xFFFFF1FF;
          v28 = v29 == 0;
          v30 = v26 + 4;
          if ( v29 )
            v25 = off_11A2E4 + 4 * v30;
          else
            v29 = off_11A2E4 + 4 * v30;
          if ( v28 )
            *(volatile uint32_t *)(v29 + 4) = v25;
          else
            *(volatile uint32_t *)(v25 + 4) = v29;
          if ( v27 && *(volatile uint8_t *)(v27 + 4) == v26 )
            *(volatile uint32_t *)off_11A304 = v12[v30 + 1];
          ke_evt_handler(23, a4, a3);
          v13 = 0;
          break;
        case 24:
LABEL_53:
          v12 = (void *)(uintptr_t)(off_11A660);
          memcpy((volatile char *)(dword_11A66C + 224 * (uint8_t)a2[6] + 64), a2, 6u);
          v44 = (void *)(uintptr_t)(off_11A674);
          v45 = *((volatile uint16_t *)a2 + 2);
          *(volatile uint32_t *)off_11A670 = *(volatile uint32_t *)a2;
          *v44 = v45;
          ke_evt_handler(25, a4, a3);
          v13 = 0;
          break;
        case 28:
LABEL_54:
          v12 = (void *)(uintptr_t)(off_11A660);
          *(volatile uint32_t *)off_11A678 = ((uint8_t)*a2 << 14) & 0x1C000 | *(volatile uint32_t *)off_11A678 & 0xFFFE3FFF;
          ke_evt_handler(29, a4, a3);
          v13 = 0;
          break;
        case 30:
LABEL_37:
          v31 = (uint8_t)a2[3];
          v32 = dword_11A66C;
          v33 = dword_11A66C + 224 * v31;
          _frame.a1a[0] = 0;
          v34 = reset_link_status(_frame.a1a);
          v35 = *(volatile uint8_t *)(v33 + 94);
          v36 = (uint8_t)a2[2];
          *(volatile uint8_t *)(v33 + 96) = v36;
          if ( !v35 )
          {
            _frame.v49 = 224 * v31;
            if ( v36 )
            {
              _frame.v52 = v34;
              v37 = (*(volatile uint32_t *)0x40501010u);
              _frame.v50 = dword_11A63C + 152 * *(volatile uint8_t *)(v33 + 102);
              ke_enter_critical((volatile uint32_t *)(_frame.v49 + 24 + v32), v37 + *(volatile uint32_t *)(_frame.v50 + 8));
              *(volatile uint16_t *)(_frame.v50 + 30) = *(volatile uint16_t *)a2;
              clear_bb_irq();
              check_interrupt_flag(
                256,
                "vif state active:%d,%d,%d\r\n",
                *(volatile uint8_t *)(_frame.v50 + 33),
                *(volatile uint16_t *)(_frame.v50 + 30),
                _frame.v52);
              *(volatile uint32_t *)off_11A648 = (uint16_t)*(volatile uint32_t *)off_11A648 | (*(volatile uint16_t *)a2 << 16);
              *(volatile uint8_t *)(v33 + 116) = 0;
              *(volatile uint32_t *)(v33 + 112) = 0;
              v38 = (*(volatile uint32_t *)0x40501010u);
              *(volatile uint32_t *)(v33 + 108) = v38;
              rf_get_status_1((int)(uintptr_t)((volatile uint32_t *)(v32 + _frame.v49)));
              v36 = (uint8_t)a2[2];
            }
            else
            {
              _frame.v51 = v34;
              ke_exit_critical((int)(uintptr_t)((volatile uint32_t *)(_frame.v49 + 24 + v32)));
              check_interrupt_flag(256, "vif state inactive:%d\r\n", _frame.v51);
              if ( (*(volatile uint32_t *)off_11A718 & 0x8000) != 0 )
                sys_status_bit21_get();
              v48 = v32 + 224 * v31;
              *(volatile uint8_t *)(v48 + 140) = 0;
              *(volatile uint32_t *)(v48 + 144) = 0;
              v36 = (uint8_t)a2[2];
            }
          }
          if ( v36 )
          {
            v39 = *(volatile uint32_t **)off_11A64C;
            v40 = **(volatile uint32_t **)off_11A64C;
            if ( v40 )
              *(volatile uint32_t *)off_11A650 = v40;
            else
              *(volatile uint32_t *)off_11A724 = *(volatile uint32_t *)(v32 + 224 * v31 + 8);
            v41 = v39[1];
            if ( v41 )
            {
              if ( (v41 & 0xFFF) != 0 )
                *(volatile uint32_t *)off_11A720 = v41;
              else
                *(volatile uint32_t *)off_11A654 = v41 & 0xFFFFF000 | *(volatile uint32_t *)(v32 + 224 * v31 + 12) & 0xFFF;
            }
            else
            {
              *(volatile uint32_t *)off_11A720 = *(volatile uint32_t *)(v32 + 224 * v31 + 12);
            }
            v42 = v39[2];
            if ( v42 )
              *(volatile uint32_t *)off_11A658 = v42;
            else
              *(volatile uint32_t *)off_11A71C = *(volatile uint32_t *)(v32 + 224 * v31 + 16);
            v43 = v39[3];
            if ( v43 )
              *(volatile uint32_t *)off_11A65C = v43;
            else
              *(volatile uint32_t *)off_11A65C = *(volatile uint32_t *)(v32 + 224 * v31 + 20);
            poll_hw_status_1();
          }
          ke_evt_handler(31, a4, a3);
          v12 = (void *)(uintptr_t)(off_11A660);
          v13 = 0;
          break;
        case 32:
LABEL_52:
          v12 = (void *)(uintptr_t)(off_11A660);
          *(volatile uint32_t *)off_11A668 = (uint8_t)*a2
                                | (((uint8_t)*(volatile uint32_t *)off_11A664 * (uint8_t)*a2) << 8);
          ke_evt_handler(33, a4, a3);
          v13 = 0;
          break;
        case 40:
LABEL_55:
          if ( *a2 )
          {
            *(volatile uint32_t *)off_11A67C |= 0x80u;
            v46 = 0;
          }
          else
          {
            v46 = 5;
          }
          v47 = (volatile uint8_t *)ke_msg_send_1(41, a4, a3, 3);
          *v47 = a2[1];
          v47[1] = a2[2];
          v47[2] = v46;
          rx_irq_handler_1((int)v47);
          v12 = (void *)(uintptr_t)(off_11A660);
          v13 = 0;
          break;
        case 48:
LABEL_58:
          ke_int_unlock();
          v12 = (void *)(uintptr_t)(off_11A660);
          v13 = 0;
          break;
        case 59:
LABEL_11:
          rx_desc_parse((volatile uint8_t *)a2);
          ke_evt_handler(60, a4, a3);
          v12 = (volatile int *)off_11A2E4;
          v13 = 0;
          break;
        default:
          if ( **v10 < 0 )
          {
LABEL_59:
            v12 = (void *)(uintptr_t)(off_11A660);
            flash_ctrl_init(off_11A684, (int)aMmHwConfigHand, 2552);
            v13 = 2;
          }
          else
          {
            v12 = (void *)(uintptr_t)(off_11A660);
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
          v12 = (volatile int *)off_11A2E4;
          v13 = 2;
          break;
      }
    }
    *(volatile uint32_t *)off_11A2E8 = (uint8_t)(16 * *((volatile uint8_t *)v12 + 17));
    flash_erase_sector(a3, *((volatile uint8_t *)v12 + 16));
    return v13;
  }
}


// return_zero_2 @ 0x11a728
int return_zero_2() {
  return 0;
}



// mmio_clear_bits @ 0x11a72c
int mmio_clear_bits(volatile uint16_t *a1) {
  int v1; // r3
  volatile int *v2; // r2
  int v4; // r0
  volatile int *v5; // r5
  volatile int *v6; // r7
  int v7; // r6
  int v8; // r1
  int v9; // r5
  volatile int *v10; // r0

  v1 = dword_11A7B4;
  v2 = *(volatile int **)off_11A7B0;
  v4 = *a1;
  v5 = (volatile int *)off_11A7B8;
  v6 = (volatile int *)off_11A7BC;
  v7 = a1[2];
  *v2 = **(volatile uint32_t **)off_11A7B0 & dword_11A7B4 | (v4 << 12);
  *v5 = *v5 & v1 | (v4 << 12);
  v8 = a1[1];
  v2[1] = v2[1] & v1 | (v8 << 12);
  v9 = a1[3];
  *v6 = *v6 & v1 | (v8 << 12);
  v2[2] = v2[2] & v1 | (v7 << 12);
  v10 = (volatile int *)off_11A7C0;
  v6[1] = v6[1] & v1 | (v7 << 12);
  v2[3] = v2[3] & v1 | (v9 << 12);
  *v10 = v1 & *v10 | (v9 << 12);
  poll_hw_status_1();
  dispatch_event_handler_1("set txop: bk:%x,be:%x,vi:%x,vo:%x\n", *a1, a1[1], a1[2], a1[3]);
  return 0;
}


// rx_update_meta @ 0x11a7c8
int rx_update_meta(volatile uint8_t *a1) {
  volatile int *v1; // r2
  int v2; // r3
  uint8_t v4; // r0
  uint8_t v5; // r4
  uint8_t v6; // r1
  void *v7; // r1
  int v8; // r11
  volatile uint32_t *v9; // r10
  volatile uint32_t *v10; // r9
  int v11; // r8
  int v12; // r7
  volatile uint8_t *v13; // r6
  int i; // r4
  int v15; // r3
  int v16; // t1
  int v17; // r2

  v1 = (void *)(uintptr_t)(off_11A8BC);
  v2 = a1[16];
  *((volatile uint8_t *)off_11A8BC + 360) = a1[17];
  *((volatile uint8_t *)v1 + 361) = a1[18];
  v4 = a1[21];
  *((volatile uint8_t *)v1 + 356) = v4;
  v5 = a1[22];
  *((volatile uint8_t *)v1 + 357) = v5;
  v6 = a1[23];
  *((volatile uint8_t *)v1 + 358) = v6;
  *((volatile uint8_t *)v1 + 359) = v6 + v4 + v5;
  if ( a1[19] )
    *(volatile uint32_t *)off_11A8C0 |= 0x10u;
  else
    *(volatile uint32_t *)off_11A8C0 &= ~0x10u;
  v7 = (void *)(uintptr_t)(off_11A8C0);
  if ( a1[20] )
    *(volatile uint32_t *)off_11A8C0 |= 2u;
  else
    *(volatile uint32_t *)off_11A8C0 &= ~2u;
  v8 = dword_11A8D8;
  v9 = (void *)(uintptr_t)(off_11A8DC);
  v10 = (void *)(uintptr_t)(off_11A8E0);
  v11 = 224 * v2;
  v12 = 224 * v2 + 8 + dword_11A8D8;
  v13 = a1 - 4;
  for ( i = 0; i != 4; ++i )
  {
    v16 = *((volatile uint32_t *)v13 + 1);
    v13 += 4;
    v15 = v16;
    if ( v16 )
    {
      *(volatile uint32_t *)(v12 + 4 * i) = v15;
      v7 = *(void **)off_11A8C4;
      v17 = *(volatile uint8_t *)(v8 + v11 + 96);
      *(volatile uint32_t *)(*(volatile uint32_t *)off_11A8C4 + 4 * i) = v15;
      if ( v17 )
      {
        if ( i == 1 )
        {
          *v9 = v15;
        }
        else if ( (uint8_t)i == 2 )
        {
          *v10 = v15;
        }
        else if ( (uint8_t)i )
        {
          *(volatile uint32_t *)off_11A8C8 = v15;
        }
        else
        {
          *(volatile uint32_t *)off_11A8D4 = v15;
        }
        poll_hw_status_1();
      }
    }
  }
  if ( a1[24] )
    *(volatile uint8_t *)off_11A8CC = a1[24];
  dispatch_event_handler_1(aSetVendorCa, v7);
  return handle_ipc_request((int)a1, 28, 1, 0);
}


// mmio_select_port @ 0x11a8e4
int mmio_select_port(volatile uint8_t *a1) {
  int v1; // r1
  int v3; // r3
  volatile unsigned int *v4; // r0
  int v5; // r1
  volatile unsigned int *v6; // r0
  int v7; // r1
  volatile unsigned int *v8; // r0

  v1 = *a1;
  v3 = (uint8_t)*(volatile uint32_t *)off_11A9A4;
  if ( *a1 )
  {
    v4 = (volatile unsigned int *)off_11A9A8;
    *(volatile uint32_t *)off_11A9A8 = *(volatile uint32_t *)off_11A9A8 & 0xFFFFFF00 | v1;
    *v4 = *v4 & 0xFF0000FF | ((v3 * v1) << 8);
  }
  v5 = a1[1];
  if ( a1[1] )
  {
    v6 = (volatile unsigned int *)off_11A9AC;
    *(volatile uint32_t *)off_11A9AC = *(volatile uint32_t *)off_11A9AC & 0xFFFFFF00 | v5;
    *v6 = *v6 & 0xFF0000FF | ((v3 * v5) << 8);
  }
  v7 = a1[2];
  if ( a1[2] )
  {
    v8 = (volatile unsigned int *)off_11A9B0;
    *(volatile uint32_t *)off_11A9B0 = *(volatile uint32_t *)off_11A9B0 & 0xFFFFFF00 | v7;
    *v8 = *v8 & 0xFF0000FF | ((v3 * v7) << 8);
  }
  if ( a1[3] )
    *(volatile uint32_t *)off_11A9B4 = *(volatile uint32_t *)off_11A9B4 & 0xFFFFFF00 | a1[3];
  if ( a1[4] )
    *(volatile uint32_t *)off_11A9B4 = *(volatile uint32_t *)off_11A9B4 & 0xFFFF00FF | (a1[4] << 8);
  if ( a1[5] )
    *(volatile uint32_t *)off_11A9B4 = *(volatile uint32_t *)off_11A9B4 & 0xFF00FFFF | (a1[5] << 16);
  dispatch_event_handler_1(aSetVendorTs);
  return handle_ipc_request((int)a1, 6, 1, 0);
}


// flag_update @ 0x11a9bc
int flag_update(volatile uint8_t *a1) {
  int v1; // r3

  v1 = *a1;
  if ( v1 << 28 )
    *(volatile uint8_t *)off_11AA48 = v1 & 1;
  if ( (v1 & 0xF0) != 0 )
    *((volatile uint8_t *)off_11AA4C + 408) = v1 & 0x10;
  if ( a1[1] )
    *(volatile uint32_t *)off_11AA50 = a1[1] | *(volatile uint32_t *)off_11AA50 & 0xFFFFFF00;
  if ( a1[2] )
    *(volatile uint32_t *)off_11AA54 = a1[2] | *(volatile uint32_t *)off_11AA54 & 0xFFFFFF00;
  if ( a1[3] )
    *(volatile uint32_t *)off_11AA50 = *(volatile uint32_t *)off_11AA50 & 0xFFF00FFF | (a1[3] << 12);
  if ( a1[4] )
    *(volatile uint32_t *)off_11AA54 = *(volatile uint32_t *)off_11AA54 & 0xFFF00FFF | (a1[4] << 12);
  dispatch_event_handler_1(aSetVendorCca);
  return handle_ipc_request((int)a1, 5, 1, 0);
}


// patch_load_cal @ 0x11aa5c
volatile uint8_t * patch_load_cal(volatile uint8_t *result) {
  unsigned int v1; // r2
  volatile uint8_t *v2; // r3
  volatile uint8_t *v3; // r4

  v1 = *result;
  if ( v1 <= 2 )
  {
    v2 = (volatile uint8_t *)off_11AA80;
    v3 = (void *)(uintptr_t)(off_11AA88);
    *(volatile uint8_t *)off_11AA84 = v1;
    *v3 = v1;
    return (volatile uint8_t *)clock_set_source(v2[36], v2[37], v1);
  }
  return result;
}



// ipc_dispatch @ 0x11aa8c
int ipc_dispatch(int a1, volatile int *a2, int a3, int a4) {
  int v4; // r4
  int v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]
  int v12; // [sp+0h] [bp-8h]

  v4 = *a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      mmio_clear_bits((volatile uint16_t *)a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      rx_update_meta((volatile uint8_t *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      mmio_select_port((volatile uint8_t *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v12 = a3;
      flag_update((volatile uint8_t *)a2 + 4);
      a3 = v12;
      v6 = a4;
      break;
    case 4:
      v9 = a3;
      patch_load_cal((volatile uint8_t *)a2 + 4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  ke_evt_handler(127, v6, a3);
  return 0;
}


// cmp_before @ 0x11ab00
unsigned int cmp_before(int a1, int a2) {
  return (unsigned int)(*(volatile uint32_t *)(a1 + 12) - *(volatile uint32_t *)(a2 + 12)) >> 31;
}



// log_18630c @ 0x11ab0c
int log_18630c() {
  return (int)(uintptr_t)(list_init_1((void *)(uintptr_t)(dword_11AB14)));
}



