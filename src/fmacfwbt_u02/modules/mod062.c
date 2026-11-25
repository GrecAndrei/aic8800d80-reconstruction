// rf_cal_configure @ 0x136684
int rf_cal_configure(int a1, int a2, int a3, int a4) {
  int v4; // r8
  uint16_t v6; // r7
  uint16_t v7; // r9
  int v8; // r6
  int v9; // r5
  char v10; // r5
  volatile char *v11; // r0
  char v13; // r3
  int16_t v14; // r3
  int v15; // r3
  char v16; // r2
  int v17; // r1
  int16_t v18; // r2
  int v19; // r9
  int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r0
  struct __attribute__((packed)) { uint8_t a2a; // [sp+3h] [bp-Dh] BYREF
  int a1a; // [sp+4h] [bp-Ch] BYREF
  int v25; // [sp+8h] [bp-8h]
  uint16_t v26; // [sp+Ch] [bp-4h]
  } _frame;
  v4 = dword_136824;
  v6 = a3;
  v7 = a4;
  state_check_feature(256, "ap start:%d, radar=%d\r\n", *(volatile uint32_t *)(a2 + 20), BYTE1(((volatile uint32_t *)(uintptr_t)off_136808)[103]));
  v8 = *(volatile uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(volatile uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (volatile char *)bt_buf_alloc(7169, v7, v6, 4);
    *v11 = v10;
    v11[1] = *(volatile uint8_t *)(a2 + 51);
    hci_evt_send((int)v11);
    return 0;
  }
  if ( hci_cmd_send_short(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(volatile uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(volatile int16_t **)off_136810 < 0 && *(volatile uint32_t *)(v9 + 72) )
    mmio_irq_clear((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(volatile uint8_t *)(a2 + 16);
  *(volatile uint32_t *)off_136814 = a2;
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
  v14 = *(volatile uint16_t *)(a2 + 14);
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 28)) & 0xFFu);
  _frame.a1a = (_frame.a1a & ~0xFFFF0000u) | (((uint16_t)(v14) & 0xFFFFu) << 16);
  v15 = *(volatile uint32_t *)(a2 + 24);
  _frame.v25 = (_frame.v25 & ~0xFFFFu) | ((uint16_t)(*(volatile uint32_t *)(a2 + 20)) & 0xFFFFu);
  v16 = *(volatile uint8_t *)(a2 + 18);
  _frame.v25 = (_frame.v25 & ~0xFFFF0000u) | (((uint16_t)(v15) & 0xFFFFu) << 16);
  v15 = (v15 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 17)) & 0xFFu);
  _frame.v26 = (_frame.v26 & ~0xFFu) | ((uint8_t)(v16) & 0xFFu);
  _frame.v26 = (_frame.v26 & ~0xFF00u) | (((uint8_t)(v15) & 0xFFu) << 8);
  if ( find_free_conn((volatile uint8_t *)&_frame.a1a, &_frame.a2a) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v17 = _frame.v25;
  v18 = _frame.v26;
  v19 = v4 + 1320 * v8;
  *(volatile uint32_t *)(v19 + 412) = _frame.a1a;
  *(volatile uint32_t *)(v19 + 416) = v17;
  *(volatile uint8_t *)(v19 + 464) = 0;
  *(volatile uint16_t *)(v19 + 420) = v18;
  scan_rssi_compare(v19);
  if ( BYTE1(_frame.a1a) == 2 )
    bt_coex_control((volatile int *)(v4 + 1320 * v8), 1, 0);
  update_entries_from_config(*(volatile uint8_t *)(a2 + 51), _frame.a2a);
  if ( !*(volatile uint8_t *)(a2 + 16) )
  {
    v22 = llm_decrypt_adv_payload((volatile uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v22 )
      *(volatile uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v22);
    else
      *(volatile uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  rf_cal_init();
  if ( !*(volatile uint32_t *)off_136820 )
  {
    v20 = v4 + 1320 * v8;
    v21 = *(volatile uint16_t *)(v20 + 416);
    if ( v21 <= 0x1387 )
      hw_reg_write(v21 | (*(volatile uint8_t *)(v20 + 413) << 16) | 0x80000000);
  }
  return 1;
}


// txpwr_get_context @ 0x136828
volatile uint32_t *txpwr_get_context() {
  if ( **(volatile int16_t **)off_13685C >= 0 || !*((volatile uint32_t *)off_136864 + 1) )
    return zero_struct((volatile uint32_t *)dword_136860);
  mmio_irq_clear(dword_136868, dword_13686C, 46);
  return zero_struct((volatile uint32_t *)dword_136860);
}



// txpwr_reset_state @ 0x136870
int txpwr_reset_state() {
  volatile uint8_t *v0; // r4

  v0 = (void *)(uintptr_t)(off_13688C);
  memset((volatile int *)off_13688C, 0, 0x10u);
  v0[12] = 0;
  return hci_cmd_send(7u, 0);
}


// txpwr_send_cmd @ 0x136890
int txpwr_send_cmd(int a1) {
  volatile uint32_t *v1; // r8
  int v3; // r6
  volatile uint8_t *v4; // r4
  char v5; // r3
  int v7; // r7
  int v8; // r0
  int v9; // r9
  int16_t v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r7
  char v17; // r3

  v1 = (void *)(uintptr_t)(off_136974);
  v3 = *(volatile uint32_t *)off_136974;
  v4 = (volatile uint8_t *)bt_buf_alloc(7169, 13, 7, 4);
  if ( a1 )
  {
    v5 = *(volatile uint8_t *)(v3 + 51);
  }
  else
  {
    v7 = *(volatile uint8_t *)(v3 + 51);
    v8 = bt_buf_alloc(30, 0, 7, 4);
    v9 = dword_136970 + 1320 * v7;
    *(volatile uint8_t *)(v8 + 2) = 1;
    *(volatile uint8_t *)(v8 + 3) = *(volatile uint8_t *)(v9 + 107);
    hci_evt_send(v8);
    v10 = *(volatile uint16_t *)(v3 + 48);
    v11 = *(volatile uint32_t *)(v9 + 72);
    *(volatile uint32_t *)(v9 + 1208) = *(volatile uint32_t *)(v3 + 44);
    *(volatile uint16_t *)(v9 + 236) = v10;
    *(volatile uint8_t *)(v9 + 234) = 0;
    v4[2] = *(volatile uint8_t *)(v11 + 24);
    v12 = dword_136978;
    v4[3] = *(volatile uint8_t *)(v3 + 51) + 32;
    v13 = *(volatile uint32_t *)(v3 + 4);
    v14 = *(volatile uint32_t *)(v3 + 8);
    v15 = *(volatile uint32_t *)(v3 + 12);
    v16 = v12 + 696 * (v7 + 32);
    *(volatile uint32_t *)(v16 + 192) = *(volatile uint32_t *)v3;
    *(volatile uint32_t *)(v16 + 196) = v13;
    *(volatile uint32_t *)(v16 + 200) = v14;
    *(volatile uint8_t *)(v16 + 52) = 2;
    *(volatile uint8_t *)(v16 + 204) = v15;
    bt_get_local_addr_type(v16);
    v17 = *(volatile uint8_t *)(v16 + 350);
    *(volatile uint16_t *)(v16 + 38) = 1;
    *(volatile uint8_t *)(v16 + 350) = v17 | 0x10;
    v5 = *(volatile uint8_t *)(v3 + 51);
    *(volatile uint8_t *)(v16 + 37) = 1;
    *(volatile uint8_t *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  hci_evt_send((int)v4);
  jump_to_tx_entry((int)(uintptr_t)((volatile char *)(v3 - 12)));
  *v1 = 0;
  return hci_cmd_send(7u, 0);
}


// txpwr_get_state @ 0x13697c
int txpwr_get_state() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r4

  v0 = list_pop_front(dword_1369B0);
  v1 = v0;
  if ( **(volatile int16_t **)off_1369B4 < 0 && !v0 )
    mmio_irq_clear(dword_1369BC, dword_1369B8, 210);
  return (int)(uintptr_t)(hci_evt_send((int)(v1 + 3)));
}



// rf_cal_init @ 0x1369c0
int rf_cal_init() {
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  volatile uint8_t *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r1
  volatile uint8_t *v14; // r0

  v0 = dword_136AE4;
  v1 = *(volatile uint32_t *)off_136AD8;
  v2 = *(volatile uint8_t *)(*(volatile uint32_t *)off_136AD8 + 51);
  v3 = bt_buf_alloc(24, 0, 7, 8);
  v4 = bt_buf_alloc(22, 0, 7, 8);
  v5 = bt_buf_alloc(20, 0, 7, 4);
  v6 = v0 + 1320 * v2;
  v7 = (volatile uint8_t *)bt_buf_alloc(5143, 5, 7, 2);
  txpwr_get_context();
  if ( *(volatile uint8_t *)(v6 + 1224) )
  {
    *(volatile uint32_t *)off_136ADC &= ~4u;
    *(volatile uint32_t *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v14 = (volatile uint8_t *)bt_buf_alloc(5145, 5, 7, 2);
    *v14 = 1;
    v14[1] = *(volatile uint8_t *)(v6 + 107);
    check_abort_flag((int)off_136AD8 + 4, (volatile uint32_t *)v14 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(volatile uint32_t *)(v8 + 100);
  *(volatile uint16_t *)(v3 + 4) = *(volatile uint16_t *)(v8 + 104);
  *(volatile uint32_t *)v3 = v9;
  *(volatile uint8_t *)(v3 + 6) = *(volatile uint8_t *)(v1 + 51);
  check_abort_flag(dword_136AE0, (volatile uint32_t *)(v3 - 12));
  *(volatile uint8_t *)(v4 + 5) = *(volatile uint8_t *)(v1 + 16);
  *(volatile uint32_t *)v4 = llm_decrypt_adv_payload((volatile uint8_t *)v1, 1);
  *(volatile uint8_t *)(v4 + 4) = *(volatile uint8_t *)(v1 + 51);
  check_abort_flag(dword_136AE0, (volatile uint32_t *)(v4 - 12));
  *(volatile uint16_t *)v5 = *(volatile uint16_t *)(v1 + 40);
  *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 51);
  check_abort_flag(dword_136AE0, (volatile uint32_t *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136AE0;
  v7[1] = *(volatile uint8_t *)(v1 + 51);
  v11 = check_abort_flag(v10, (volatile uint32_t *)v7 - 3);
  txpwr_get_state(v11, v12);
  return hci_cmd_send(7u, 1);
}


// rf_core_enable @ 0x136ae8
int rf_core_enable() {
  int v0; // r4
  int v1; // r0
  int16_t v2; // r1
  int16_t v3; // r2

  v0 = *(volatile uint32_t *)off_136B24;
  v1 = bt_buf_alloc(63, 0, 7, 12);
  v2 = *(volatile uint16_t *)(v0 + 36);
  v3 = *(volatile uint16_t *)(v0 + 38);
  *(volatile uint32_t *)v1 = *(volatile uint32_t *)(v0 + 32);
  *(volatile uint16_t *)(v1 + 4) = v2;
  *(volatile uint16_t *)(v1 + 6) = v3;
  *(volatile uint8_t *)(v1 + 8) = *(volatile uint8_t *)(v0 + 50);
  *(volatile uint8_t *)(v1 + 9) = *(volatile uint8_t *)(v0 + 51);
  hci_evt_send(v1);
  return hci_cmd_send(7u, 2);
}


// rf_path_config @ 0x136b28
int rf_path_config(int a1) {
  volatile uint8_t *v2; // r6
  int v3; // r0
  volatile uint8_t *v4; // r5
  volatile int *v5; // r3
  unsigned int v6; // r2
  volatile uint8_t *v7; // r0
  int v8; // r0
  int v9; // r0
  int v10; // r1
  int v12; // r0

  v2 = (volatile uint8_t *)bt_buf_alloc(5145, 5, 7, 2);
  v3 = bt_buf_alloc(5143, 5, 7, 2);
  *(volatile uint8_t *)(dword_136C28 + 696 * (*(volatile uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (volatile uint8_t *)v3;
  txpwr_get_context();
  *v2 = 0;
  v2[1] = *(volatile uint8_t *)(a1 + 107);
  check_abort_flag(dword_136C2C, (volatile uint32_t *)v2 - 3);
  v5 = *((volatile int **)off_136C30 + 2);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( (volatile int *)a1 != v5 )
      {
        if ( *((volatile uint8_t *)v5 + 108) )
        {
          v6 = *((volatile uint16_t *)v5 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v5 = (volatile int *)*v5;
      if ( !v5 )
        goto LABEL_6;
    }
    hw_reg_write(v6 | (*((volatile uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    hw_reg_write(0);
  }
  bt_coex_control((volatile int *)a1, 0, 0);
  if ( *(volatile uint8_t *)(a1 + 108) )
  {
    v12 = bt_buf_alloc(30, 0, 7, 4);
    *(volatile uint8_t *)(v12 + 2) = 0;
    *(volatile uint8_t *)(v12 + 3) = *(volatile uint8_t *)(a1 + 107);
    check_abort_flag(dword_136C2C, (volatile uint32_t *)(v12 - 12));
  }
  if ( *(volatile uint32_t *)(a1 + 72) )
  {
    v7 = (volatile uint8_t *)bt_buf_alloc(57, 0, 7, 1);
    *v7 = *(volatile uint8_t *)(a1 + 107);
    check_abort_flag(dword_136C2C, (volatile uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v8 = dword_136C2C;
  v4[1] = *(volatile uint8_t *)(a1 + 107);
  v9 = check_abort_flag(v8, (volatile uint32_t *)v4 - 3);
  txpwr_get_state(v9, v10);
  return hci_cmd_send(7u, 3);
}


// phy_check_core_mode @ 0x136c34
int phy_check_core_mode(int a1) {
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(volatile uint8_t *)(dword_136C8C + 1320 * *(volatile uint8_t *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(volatile uint8_t *)(a1 + 29);
  if ( v1 > 0x23 || !*(volatile uint16_t *)(a1 + 4) && *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136C90 + 696 * v1;
  v3 = *(volatile uint8_t *)(v2 + 36);
  if ( v3 != 1 )
    return 1;
  if ( (*(volatile uint8_t *)(v2 + 54) & 3) == 0 )
  {
    v3 = 0;
    *(volatile uint16_t *)(a1 + 30) |= 0x1000u;
  }
  return v3;
}



// txpwr_limit_apply @ 0x136c94
int txpwr_limit_apply(int result, int a2) {
  int v3; // r3
  int v4; // r0

  if ( (*(volatile uint16_t *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(volatile uint8_t *)(a2 + 310);
    if ( ((uint8_t)v3 & *(volatile uint8_t *)(dword_136CF8 + *(volatile uint8_t *)(result + 27))) != 0 )
    {
      if ( (*(volatile uint8_t *)(a2 + 53) & 8) == 0 )
      {
        *(volatile uint8_t *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(volatile uint8_t *)(a2 + 53) & 2) == 0 )
    {
      *(volatile uint8_t *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = bt_buf_alloc(65, 0, 5, 4u);
      *(volatile uint16_t *)v4 = *(volatile uint16_t *)(a2 + 32);
      *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(a2 + 34);
      *(volatile uint8_t *)(v4 + 2) = 1;
      return (int)(uintptr_t)(hci_evt_send(v4));
    }
  }
  return result;
}



// txpwr_process_config @ 0x136cfc
volatile int ** txpwr_process_config(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r7
  int v5; // r2
  int v7; // r8
  volatile int **v8; // r4
  char v9; // r1
  int v10; // r5
  BOOL v11; // r2
  volatile int ***v12; // r10
  int v13; // r1
  char v14; // r3
  volatile int **v15; // r3
  BOOL v16; // r1
  int v18; // r7
  int v19; // r0

  v3 = *(volatile uint8_t *)(a1 + 106);
  if ( v3 != 2 || (v5 = *(volatile uint8_t *)(a2 + 54), !*(volatile uint8_t *)(a2 + 54)) )
  {
    *a3 = 0;
    return 0;
  }
  v7 = v5 & 1;
  if ( (v5 & 1) == 0 )
  {
    v3 = 8;
    v7 = 4;
  }
  if ( ((uint8_t)v3 & *(volatile uint8_t *)(a2 + 53)) == 0 )
    goto LABEL_26;
  v8 = *(volatile int ***)(a2 + 572);
  if ( !v8 )
  {
LABEL_24:
    if ( **(volatile int16_t **)off_136E34 < 0 )
      mmio_field_update(dword_136E3C, dword_136E38, 441);
LABEL_26:
    *a3 = 1;
    return 0;
  }
  v9 = *(volatile uint8_t *)(a2 + 310);
  v10 = dword_136E30;
  v11 = v5 == 2;
  v12 = 0;
  while ( ((uint8_t)(v9 & *(volatile uint8_t *)(dword_136E30 + *((volatile uint8_t *)v8 + 27))) == 0) == v11 )
  {
    v12 = (volatile int ***)v8;
    if ( !*v8 )
      goto LABEL_24;
    v8 = (volatile int **)*v8;
  }
  check_abort_flag_4(a2 + 572, (void *)(v12), (void *)(v8));
  v13 = *(volatile uint8_t *)(a2 + 54);
  if ( (v13 & 8) != 0 )
    v14 = 4;
  else
    v14 = 3;
  *((volatile uint8_t *)v8 + 27) = v14;
  if ( v12 )
    v15 = *v12;
  else
    v15 = *(volatile int ***)(a2 + 572);
  if ( v15 )
  {
    v16 = v13 == 2;
    while ( ((uint8_t)(*(volatile uint8_t *)(a2 + 310) & *(volatile uint8_t *)(v10 + *((volatile uint8_t *)v15 + 27))) == 0) == v16 )
    {
      v15 = (volatile int **)*v15;
      if ( !v15 )
        goto LABEL_22;
    }
    goto LABEL_20;
  }
LABEL_22:
  v18 = *(volatile uint8_t *)(a2 + 53) & ~v3;
  *(volatile uint8_t *)(a2 + 53) = v18;
  if ( (v18 & v7) != 0 )
  {
LABEL_20:
    *((volatile uint16_t *)v8[18] + 54) |= 0x2000u;
    return v8;
  }
  v19 = bt_buf_alloc(65, 0, 5, 4u);
  *(volatile uint16_t *)v19 = *(volatile uint16_t *)(a2 + 32);
  *(volatile uint8_t *)(v19 + 3) = *(volatile uint8_t *)(a2 + 34);
  *(volatile uint8_t *)(v19 + 2) = 0;
  hci_evt_send(v19);
  return v8;
}



// txpwr_cal_entry_get @ 0x136e40
int txpwr_cal_entry_get(int result, int a2) {
  int v2; // r4
  char v3; // r1
  int v4; // r0
  int16_t v5; // r1

  if ( *(volatile uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136E94 + 696 * a2;
    result = wlc_bsscfg_down(result, v2, 0);
    v3 = *(volatile uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(volatile uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = bt_buf_alloc(65, 0, 5, 4u);
        v5 = *(volatile uint16_t *)(v2 + 32);
        *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(v2 + 34);
        *(volatile uint8_t *)(v4 + 2) = 0;
        *(volatile uint16_t *)v4 = v5;
        return (int)(uintptr_t)(hci_evt_send(v4));
      }
    }
  }
  return result;
}



// txpwr_event_handler @ 0x136e98
int txpwr_event_handler(int a1, int a2) {
  int v2; // r3
  int v5; // r3
  int result; // r0
  int v7; // r5
  int v8; // r6
  volatile uint16_t *v9; // r2
  int16_t v10; // r3
  int16_t v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r1
  uint64_t v15; // r2

  v2 = *(volatile uint32_t *)(a1 + 72);
  if ( v2 )
  {
    v5 = *(volatile uint8_t *)(v2 + 4);
    if ( **(volatile int16_t **)off_136F90 >= 0 || v5 != 2 )
    {
      result = (int)(uintptr_t)(event_notify((v5 | *(volatile uint8_t *)(a1 + 1224)) != 0, 512));
      v7 = result;
      if ( !result )
        return result;
LABEL_4:
      scan_done_check(a1, result);
      v8 = *(volatile uint32_t *)(v7 + 72);
      *(volatile uint8_t *)(v8 + 108) = -64;
      *(volatile uint8_t *)(v8 + 109) = 0;
      *(volatile uint8_t *)(v8 + 110) = 0;
      *(volatile uint8_t *)(v8 + 111) = 0;
      memcpy((void *)(uintptr_t)(v8 + 112), (void *)(uintptr_t)(a2), 6);
      v9 = (void *)(uintptr_t)(off_136F94);
      v10 = *((volatile uint16_t *)off_136F94 + 254);
      v11 = *(volatile uint16_t *)(a1 + 104);
      *(volatile uint32_t *)(v8 + 118) = *(volatile uint32_t *)(a1 + 100);
      ++v10;
      v12 = *(volatile uint32_t *)(a1 + 100);
      *(volatile uint16_t *)(v8 + 122) = v11;
      *(volatile uint32_t *)(v8 + 124) = v12;
      *(volatile uint16_t *)(v8 + 128) = v11;
      v9[254] = v10;
      *(volatile uint16_t *)(v8 + 130) = 16 * v10;
      *(volatile uint32_t *)(v7 + 88) = 0;
      *(volatile uint32_t *)(v7 + 92) = a1;
      *(volatile uint8_t *)(v7 + 28) = *(volatile uint8_t *)(a1 + 107);
      *(volatile uint8_t *)(v7 + 29) = -1;
      v13 = util_store_u16_return_2((volatile uint16_t *)(v8 + 132), 7);
      v14 = *(volatile uint32_t *)(v7 + 76);
      v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v14 + 28) + 23 + v13) & 0xFFFFFFFFu);
      v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v13 + 28) << 32);
      *(volatile uint64_t *)(v14 + 32) = v15;
      return ble_event_dispatch(v7, 5);
    }
    goto LABEL_6;
  }
  if ( **(volatile int16_t **)off_136F90 < 0 )
LABEL_6:
    mmio_irq_clear(dword_136F9C, dword_136F98, 520);
  result = (int)(uintptr_t)(event_notify(1, 512));
  v7 = result;
  if ( result )
    goto LABEL_4;
  return result;
}



// rf_cmd_txpwr_query @ 0x136fa0
int rf_cmd_txpwr_query(int a1, volatile uint8_t *a2, int a3, int16_t a4) {
  volatile uint16_t *v4; // r4
  volatile uint8_t *v6; // r0
  volatile uint32_t *v7; // r6
  unsigned int v8; // r2
  volatile int *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2

  v4 = (void *)(uintptr_t)(off_136FFC);
  v6 = (volatile uint8_t *)bt_buf_alloc(4102, a4, 4, 0x3Cu);
  v7 = (void *)(v6);
  if ( v4[2] && (v8 = *a2, (uint16_t)v4[2] > v8) )
  {
    v10 = (volatile int *)&v4[30 * v8 + 4];
    v11 = *v10;
    v12 = v10[1];
    v13 = v10[2];
    v14 = v10[3];
    v10 += 4;
    *v7 = v11;
    v7[1] = v12;
    v7[2] = v13;
    v7[3] = v14;
    v15 = *v10;
    v16 = v10[1];
    v17 = v10[2];
    v18 = v10[3];
    v10 += 4;
    v7[4] = v15;
    v7[5] = v16;
    v7[6] = v17;
    v7[7] = v18;
    v19 = *v10;
    v20 = v10[1];
    v21 = v10[2];
    v22 = v10[3];
    v10 += 4;
    v7[8] = v19;
    v7[9] = v20;
    v7[10] = v21;
    v7[11] = v22;
    v23 = v10[1];
    v24 = v10[2];
    v7[12] = *v10;
    v7[13] = v23;
    v7[14] = v24;
    hci_evt_send((int)v7);
    return 0;
  }
  else
  {
    *v6 = 0;
    hci_evt_send((int)v6);
    return 0;
  }
}



// rf_cmd_txpwr_set @ 0x137000
int rf_cmd_txpwr_set(int a1, int a2, int a3, int a4) {
  int v4; // r0

  v4 = bt_buf_alloc(4107, a4, 4, 1);
  hci_evt_send(v4);
  state_check_feature(8, aScanuIdleCance);
  return 0;
}


// rf_cmd_set @ 0x137024
int rf_cmd_set() {
  volatile uint16_t *v0; // r4
  int v1; // r0

  v0 = (volatile uint16_t *)off_13704C;
  v1 = bt_buf_alloc(4107, *((volatile uint16_t *)off_13704C + 1924), 4, 1);
  hci_evt_send(v1);
  state_check_feature(8, "scan idle cancel cfm %d\r\n", v0[1924]);
  return 0;
}


// rf_cmd_write @ 0x137054
int rf_cmd_write(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)bt_buf_alloc(4104, a4, 4, 2);
  state_check_feature(8, aScanuScanningV);
  *v5 = 1;
  v5[1] = *(volatile uint8_t *)(a2 + 2);
  hci_evt_send((int)v5);
  return 0;
}


// rf_state_update @ 0x137088
int rf_state_update(int a1, int a2, int a3, int a4) {
  state_check_feature(8, "scanning scanu req:%d,%d\n", a4, *((volatile uint16_t *)off_1370A0 + 1924));
  return 2;
}


// rf_cmd_write2 @ 0x1370a8
int rf_cmd_write2(int a1, volatile char *a2, int a3, int a4) {
  volatile uint8_t *v5; // r4
  volatile char *v6; // r0
  unsigned int v7; // r2

  v5 = (volatile uint8_t *)bt_buf_alloc(4104, a4, 4, 2);
  state_check_feature(8, aScanuVndrIe);
  v6 = (volatile char *)off_1370EC;
  v7 = *(volatile uint16_t *)a2;
  *(volatile uint16_t *)off_1370EC = v7;
  memcpy(v6 + 3, a2 + 3, v7);
  *v5 = 1;
  v5[1] = a2[2];
  hci_evt_send((int)v5);
  return 0;
}


