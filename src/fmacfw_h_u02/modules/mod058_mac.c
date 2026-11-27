// ble_rx_process @ 0x134950
int ble_rx_process() {
  int v0; // r6
  int16_t v1; // r7
  int v2; // r8
  int v3; // r0
  int v4; // r0
  int v5; // r4
  int v6; // r5
  volatile uint16_t *v7; // r1
  int v8; // r3
  int16_t v9; // r2
  int v10; // t1
  int v11; // r0
  int v12; // r3
  int v13; // r6
  int v14; // r9
  int v15; // r0
  int v16; // r5
  volatile uint32_t *v17; // r1
  int result; // r0
  int v19; // r6

  v0 = *((volatile uint32_t *)off_134A80 + 2);
  v1 = *((volatile uint16_t *)off_134A80 + 6);
  v2 = *(volatile uint8_t *)(v0 + 116);
  if ( *(volatile uint8_t *)(v0 + 1224) )
  {
    v3 = 1;
  }
  else
  {
    v3 = *(volatile uint8_t *)(v0 + 412);
    if ( *(volatile uint8_t *)(v0 + 412) )
      v3 = 1;
  }
  v4 = (int)(uintptr_t)(lock_acquire(v3, 512));
  v5 = v4;
  if ( !v4 )
    return ble_load_defaults();
  get_status_flag_c5(v0, v4);
  v6 = *(volatile uint32_t *)(v5 + 72);
  v7 = (void *)(uintptr_t)(off_134A88);
  v8 = dword_134A84 + 696 * v2;
  v9 = *((volatile uint16_t *)off_134A88 + 254);
  v10 = *(volatile uint32_t *)(v8 + 38);
  v8 += 38;
  *(volatile uint32_t *)(v6 + 112) = v10;
  *(volatile uint8_t *)(v6 + 108) = -64;
  *(volatile uint16_t *)(v6 + 116) = *(volatile uint16_t *)(v8 + 4);
  *(volatile uint32_t *)(v6 + 118) = *(volatile uint32_t *)(v0 + 100);
  *(volatile uint16_t *)(v6 + 122) = *(volatile uint16_t *)(v0 + 104);
  v11 = *(volatile uint32_t *)v8;
  *(volatile uint16_t *)(v6 + 128) = *(volatile uint16_t *)(v8 + 4);
  ++v9;
  v12 = dword_134A8C;
  *(volatile uint32_t *)(v6 + 124) = v11;
  *(volatile uint8_t *)(v6 + 109) = 0;
  *(volatile uint8_t *)(v6 + 110) = 0;
  *(volatile uint8_t *)(v6 + 111) = 0;
  v7[254] = v9;
  *(volatile uint16_t *)(v6 + 130) = 16 * v9;
  *(volatile uint32_t *)(v5 + 88) = v12;
  *(volatile uint32_t *)(v5 + 92) = v0;
  *(volatile uint8_t *)(v5 + 28) = *(volatile uint8_t *)(v0 + 107);
  *(volatile uint8_t *)(v5 + 29) = *(volatile uint8_t *)(v0 + 116);
  *(volatile uint8_t *)(v5 + 51) = 0;
  *(volatile uint8_t *)(v5 + 53) = 0;
  v13 = bt_conn_is_active(v5, 192, 0);
  v14 = v6 + 108;
  if ( v13 == 1 )
  {
    get_config_flag(v5, (void *)(uintptr_t)(v6 + 108), 24);
    v19 = *(volatile uint8_t *)(v5 + 51) + 24;
    v16 = store_half_return_two((volatile uint16_t *)(v14 + v19), v1) + v19 + *(volatile uint8_t *)(v5 + 53);
  }
  else
  {
    v15 = store_half_return_two((volatile uint16_t *)(v6 + 132), v1);
    v16 = v15 + 24;
    if ( v13 == 2 )
      v16 += ((int (*)())bt_conn_is_connected)(v5, v14, v15 + 24, v2);
  }
  v17 = *(volatile uint32_t **)(v5 + 76);
  v17[8] = v17[7] - 1 + v16;
  v17[9] = v16 + 4;
  result = sec_check(v5, 3);
  if ( !result )
    return ble_load_defaults();
  return result;
}



// lld_evt_get_current @ 0x134a90
int lld_evt_get_current() {
  int v0; // r10
  int v1; // r5
  volatile uint8_t *v2; // r9
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r11
  volatile uint8_t *v7; // r8
  int v8; // r0
  void *v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r6
  int v15; // r7
  volatile int *v16; // r10
  int v17; // r0
  int v18; // t1
  int v19; // r0
  int v20; // r0
  int v21; // r1
  volatile int *v23; // r6
  int v24; // [sp+0h] [bp-Ch]

  v0 = dword_134C48;
  v1 = *((volatile uint32_t *)off_134C3C + 4);
  v24 = *(volatile uint8_t *)(v1 + 61);
  v2 = (volatile uint8_t *)tx_send_pdu(5145, 5, 6, 2);
  v3 = tx_send_pdu(24, 0, 6, 8);
  v4 = 1320 * v24;
  v5 = tx_send_pdu(22, 0, 6, 8);
  v6 = tx_send_pdu(20, 0, 6, 4);
  v7 = (volatile uint8_t *)tx_send_pdu(5143, 5, 6, 2);
  controller_is_ready();
  *v2 = 1;
  v2[1] = *(volatile uint8_t *)(v1 + 61);
  co_list_push_back((int)off_134C3C + 24, (volatile uint32_t *)v2 - 3);
  v8 = *(volatile uint32_t *)(v0 + 1320 * v24 + 368);
  *(volatile uint16_t *)(v3 + 4) = *(volatile uint16_t *)(v0 + 1320 * v24 + 372);
  v9 = (void *)(uintptr_t)(off_134C3C);
  *(volatile uint32_t *)v3 = v8;
  *(volatile uint8_t *)(v3 + 6) = *(volatile uint8_t *)(v1 + 61);
  co_list_push_back((int)v9 + 24, (volatile uint32_t *)(v3 - 12));
  *(volatile uint8_t *)(v5 + 5) = *(volatile uint8_t *)(v0 + 1320 * v24 + 412);
  v10 = handle_rx_packet((volatile uint8_t *)(1320 * v24 + 424 + v0), 1);
  v11 = *(volatile uint8_t *)(v5 + 5);
  *(volatile uint32_t *)v5 = v10;
  *(volatile uint8_t *)(v5 + 4) = *(volatile uint8_t *)(v1 + 61);
  if ( !v11 )
  {
    if ( (v10 & 1) != 0 )
    {
      *((volatile uint32_t *)off_134C40 + 5) = 1024;
    }
    else if ( (v10 & 0x10) != 0 )
    {
      *((volatile uint32_t *)off_134C40 + 5) = 4;
    }
  }
  co_list_push_back(dword_134C44, (volatile uint32_t *)(v5 - 12));
  v12 = dword_134C44;
  v13 = v0 + 1320 * v24;
  *(volatile uint16_t *)v6 = *(volatile uint16_t *)(v13 + 422);
  *(volatile uint8_t *)(v6 + 2) = *(volatile uint8_t *)(v1 + 61);
  co_list_push_back(v12, (volatile uint32_t *)(v6 - 12));
  if ( (*(volatile uint32_t *)(v13 + 472) & 8) != 0 )
  {
    v23 = (volatile int *)tx_send_pdu(113, 0, 6, 4);
    *v23 = rf_read_status_flags(v0 + v4 + 248);
    co_list_push_back(dword_134C44, (void *)(v23 - 3));
  }
  v14 = 0;
  v15 = dword_134C44;
  v16 = (volatile int *)(v0 + v4 + 440);
  do
  {
    v17 = tx_send_pdu(26, 0, 6, 8);
    v18 = *v16++;
    *(volatile uint32_t *)v17 = v18;
    *(volatile uint8_t *)(v17 + 5) = v14;
    *(volatile uint8_t *)(v17 + 6) = *(volatile uint8_t *)(v1 + 61);
    *(volatile uint8_t *)(v17 + 4) = 0;
    ++v14;
    co_list_push_back(v15, (volatile uint32_t *)(v17 - 12));
  }
  while ( v14 != 4 );
  *v7 = 1;
  v19 = dword_134C44;
  v7[1] = *(volatile uint8_t *)(v1 + 61);
  v20 = co_list_push_back(v19, (volatile uint32_t *)v7 - 3);
  ble_reset_controller(v20, v21);
  return ke_state_set(6u, 4);
}


// ke_timer_set @ 0x134c4c
int ke_timer_set(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r5

  v3 = (void *)(uintptr_t)(off_134CA4);
  *((volatile uint8_t *)off_134CA4 + 4) = a3;
  v3[2] = a1;
  *((volatile uint16_t *)v3 + 6) = a2;
  ke_state_set(6u, 10);
  check_feature_flag(
    256,
    "disconnct:%d,%d, sta_tx_cnt=%d, host_init=%d\r\n",
    *(volatile uint8_t *)(a1 + 107),
    a2,
    *(volatile uint16_t *)(dword_134CA8 + 696 * *(volatile uint8_t *)(a1 + 116) + 50),
    a3);
  if ( *((volatile uint8_t *)v3 + 4) )
    return ble_rx_process();
  else
    return ble_load_defaults();
}


// ctrl_isr_dispatch @ 0x134cb0
int ctrl_isr_dispatch() {
  if ( *((volatile uint8_t *)off_134CC0 + 4) )
    return ble_rx_process();
  else
    return ble_load_defaults();
}



// assert_trace @ 0x134cc4
int assert_trace(int a1) {
  int v1; // lr
  volatile uint32_t *v3; // r5
  int v4; // r11
  int v5; // r1
  int v6; // r7
  int v7; // r4
  int v8; // r9
  int v9; // r10
  int result; // r0
  int v11; // r12
  volatile uint8_t *v12; // r0
  volatile unsigned int *v13; // r1
  unsigned int v14; // r2
  volatile int *v15; // r3
  int v16; // r1
  volatile int *v17; // r3
  int v18; // r3
  int v19; // r2
  char v20; // lr
  uint16_t v21; // r0
  int v22; // lr
  int v23; // r2
  int v24; // lr
  unsigned int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r3
  int v31; // r3
  volatile uint16_t *v32; // r3
  int v33; // r3
  unsigned int v34; // r0
  volatile unsigned int v35; // r3
  volatile uint32_t *v36; // r2
  volatile int *v37; // r1
  int v38; // r0
  int v39; // [sp+Ch] [bp-8h]
  int v40; // [sp+Ch] [bp-8h]

  v3 = (void *)(uintptr_t)(off_134F44);
  v4 = dword_134F8C;
  v5 = *((volatile uint32_t *)off_134F44 + 4);
  v6 = *(volatile uint8_t *)(v5 + 61);
  v7 = *((volatile uint32_t *)off_134F44 + 5);
  v39 = v5;
  v8 = dword_134F8C + 1320 * v6;
  v9 = *(volatile uint8_t *)(v8 + 116);
  result = alloc_tx_event("connect ind:%x, %x\n", v5, v1);
  v11 = v3[4];
  if ( v11 )
  {
    v12 = (void *)(uintptr_t)(off_134F4C);
    v13 = (volatile unsigned int *)off_134F50;
    *(volatile uint8_t *)(v7 + 9) = *(volatile uint8_t *)(v39 + 61);
    v14 = *v13 & 0xFFFFFFEF;
    v15 = *((volatile int **)off_134F54 + 2);
    *(volatile uint16_t *)v7 = a1;
    *v13 = v14;
    v16 = 0;
    v12[13] = 0;
    if ( v15 )
    {
      do
      {
        if ( !*((volatile uint8_t *)v15 + 106) && *((volatile uint8_t *)v15 + 108) )
          ++v16;
        v15 = (volatile int *)*v15;
      }
      while ( v15 );
      if ( a1 )
        goto LABEL_8;
    }
    else
    {
      v16 = 0;
      if ( a1 )
      {
LABEL_8:
        v17 = (volatile int *)off_134F58;
        *(volatile uint8_t *)(v7 + 8) = (*(volatile uint32_t *)(v11 + 48) & 0x60) != 0;
        if ( *v17 < 0 && !v16 )
        {
          v36 = (void *)(uintptr_t)(off_134F84);
          v12[2] = 0;
          v37 = (volatile int *)off_134F74;
          v38 = dword_134F88;
          *v36 |= 0x80000000;
          *v37 = v38;
        }
        ke_state_set(6u, 10);
        v3[2] = v8;
        *v3 = v7 - 12;
        hci_send_cmd_1419(v8);
LABEL_10:
        check_feature_flag(
          256,
          "connect:%d,%d,aid=%d\r\n",
          *(volatile uint8_t *)(v7 + 9),
          a1,
          *(volatile uint16_t *)(v7 + 820));
        result = (int)tx_process_jump((int)(uintptr_t)((volatile char *)(v3[4] - 12)));
        v3[4] = 0;
        *((volatile uint8_t *)v3 + 33) = 0;
        return result;
      }
    }
    v18 = v4 + 1320 * v6;
    v19 = dword_134F60;
    v20 = *(volatile uint8_t *)(v18 + 116);
    *(volatile uint32_t *)(v7 + 2) = *(volatile uint32_t *)(v18 + 368);
    v21 = *(volatile uint16_t *)(v18 + 372);
    *(volatile uint8_t *)(v7 + 10) = v20;
    v22 = *(volatile uint32_t *)(v18 + 72);
    *(volatile uint16_t *)(v7 + 6) = v21;
    *(volatile uint8_t *)(v7 + 11) = *(volatile uint8_t *)(v22 + 24);
    v23 = *(volatile uint8_t *)(v19 + 696 * v9 + 309);
    *(volatile uint8_t *)(v7 + 826) = v23;
    *(volatile uint8_t *)(v7 + 822) = *(volatile uint8_t *)(v18 + 412);
    v24 = *(volatile uint8_t *)(v18 + 413);
    v25 = *(volatile uint16_t *)(v18 + 414);
    *(volatile uint16_t *)(v7 + 824) = v25;
    if ( v24 == v23 )
    {
      *(volatile uint32_t *)(v7 + 828) = *(volatile uint16_t *)(v18 + 416);
    }
    else if ( v23 )
    {
      v26 = *(volatile uint16_t *)(v18 + 416);
      if ( v25 >= v26 )
        v27 = v26 + 20;
      else
        v27 = v26 - 20;
      *(volatile uint32_t *)(v7 + 828) = v27;
    }
    else
    {
      *(volatile uint32_t *)(v7 + 828) = v25;
    }
    v28 = v4 + 1320 * v6;
    v29 = *(volatile uint32_t *)(v28 + 472);
    *(volatile uint32_t *)(v7 + 832) = *(volatile uint16_t *)(v28 + 418);
    v30 = v29 & 1;
    *(volatile uint8_t *)(v7 + 12) = v30;
    if ( v30 )
      v30 = (v30 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v28 + 457)) & 0xFFu);
    *(volatile uint8_t *)(v7 + 13) = v30;
    v31 = v4 + 1320 * v6;
    *(volatile uint8_t *)(v7 + 8) = (*(volatile uint32_t *)(v11 + 48) & 0x60) != 0;
    if ( *(volatile uint8_t *)(v31 + 1224) )
    {
      *(volatile uint32_t *)off_134F64 = *(volatile uint16_t *)(v31 + 100) | (*(volatile uint16_t *)(v31 + 102) << 16);
      *(volatile uint32_t *)off_134F68 = *(volatile uint16_t *)(v31 + 104);
      *(volatile uint32_t *)off_134F6C = *(volatile uint16_t *)(v31 + 64) | (*(volatile uint16_t *)(v31 + 66) << 16);
      *(volatile uint32_t *)off_134F70 = *(volatile uint16_t *)(v31 + 68);
    }
    v40 = v16;
    rx_process_packet_1(v7);
    *(volatile uint32_t *)off_134F74 = dword_134F78;
    if ( v40 == 1 )
    {
      v32 = (volatile uint16_t *)(v4 + 1320 * v6);
      *(volatile uint32_t *)off_134F64 = v32[50] | (v32[51] << 16);
      *(volatile uint32_t *)off_134F68 = v32[52];
    }
    if ( *(volatile uint8_t *)(v4 + 1320 * v6 + 413) == 2 )
      check_non_null((volatile int *)v8, 0, 1);
    v33 = v4 + 1320 * v6;
    v34 = *(volatile uint16_t *)(v33 + 416);
    if ( v34 <= 0x1387 )
      bt_set_address(v34 | (*(volatile uint8_t *)(v33 + 413) << 16) | 0x80000000);
    *(volatile uint8_t *)(v4 + 1320 * v6 + 149) = 1;
    v35 = (*(volatile uint32_t *)0x40501010u);
    mm_timer_set((volatile uint32_t *)(1320 * v6 + 152 + v4), dword_134F80 + v35);
    ke_state_set(6u, 0);
    goto LABEL_10;
  }
  return result;
}


// acl_rx_process @ 0x134f90
int acl_rx_process(int a1, int a2) {
  int v2; // r5
  volatile uint8_t *v3; // r7
  int result; // r0
  uint16_t v7; // r5

  v2 = *(volatile uint32_t *)(a1 + 72);
  v3 = (void *)(uintptr_t)(off_135020);
  check_feature_flag(
    256,
    "tx cfm:%d,%x,%x\r\n",
    *((volatile uint8_t *)off_135020 + 34),
    a2,
    (uint8_t)*(volatile uint16_t *)(v2 + 108));
  if ( !v3[34] )
    return assert_trace(1);
  v7 = *(volatile uint16_t *)(v2 + 108);
  if ( hci_cmd_handler(6u) != 5 )
  {
    result = hci_cmd_handler(6u);
    if ( result != 8 )
    {
LABEL_5:
      v3[34] = 0;
      return result;
    }
  }
  result = hci_cmd_handler(6u);
  if ( result == 5 && (v7 & 0xFC) == 0xB0 || (result = hci_cmd_handler(6u), result == 8) && (v7 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      result = sec_check(a1, 5);
      *(volatile uint8_t *)(a1 + 98) = 1;
      return result;
    }
    goto LABEL_5;
  }
  return result;
}


// ll_evt_schedule @ 0x135028
int ll_evt_schedule(int a1, int a2) {
  volatile uint8_t *v2; // r7
  int v3; // r5
  int v4; // r6
  int v5; // r11
  volatile uint8_t *v6; // r4
  int v9; // r10
  int v10; // r0
  volatile uint32_t *v11; // r4
  int v12; // r5
  int v13; // r3
  volatile uint16_t *v14; // r12
  int v15; // r2
  uint16_t v16; // r1
  int v17; // t1
  int v18; // lr
  uint16_t v19; // r0
  int v20; // r1
  int v21; // r10
  int v22; // r11
  int v23; // r11
  volatile uint32_t *v24; // r1
  void *v25; // r5
  int v26; // r0
  unsigned int v28; // r0
  volatile char *v29; // r1
  volatile char *v30; // r0
  volatile char *v31; // r2
  char v32; // t1
  unsigned int a3; // [sp+Ch] [bp-8h]

  v2 = (void *)(uintptr_t)(off_1351F8);
  v3 = dword_1351FC;
  v4 = *((volatile uint32_t *)off_1351F8 + 4);
  v5 = *(volatile uint8_t *)(v4 + 61);
  v6 = (volatile uint8_t *)(dword_1351FC + 1320 * v5);
  v9 = v6[116];
  check_feature_flag(256, "%s\r\n", aSmAuthSend);
  if ( !v6[1224] )
  {
    v10 = v6[412];
    if ( v6[412] )
      v10 = 1;
    v11 = lock_acquire(v10, 512);
    if ( v11 )
      goto LABEL_5;
    return assert_trace(1);
  }
  v11 = lock_acquire(1, 512);
  if ( !v11 )
    return assert_trace(1);
LABEL_5:
  v12 = v3 + 1320 * v5;
  get_status_flag_c5(v12, (int)v11);
  v13 = v11[18];
  v14 = (void *)(uintptr_t)(off_135220);
  v15 = dword_135208 + 696 * v9;
  v16 = *((volatile uint16_t *)off_135220 + 254);
  v17 = *(volatile uint32_t *)(v15 + 38);
  v15 += 38;
  *(volatile uint32_t *)(v13 + 112) = v17;
  *(volatile uint8_t *)(v13 + 108) = -80;
  *(volatile uint16_t *)(v13 + 116) = *(volatile uint16_t *)(v15 + 4);
  *(volatile uint32_t *)(v13 + 118) = *(volatile uint32_t *)(v12 + 100);
  v18 = *(volatile uint32_t *)v15;
  *(volatile uint16_t *)(v13 + 122) = *(volatile uint16_t *)(v12 + 104);
  ++v16;
  *(volatile uint16_t *)(v13 + 128) = *(volatile uint16_t *)(v15 + 4);
  *(volatile uint32_t *)(v13 + 124) = v18;
  *(volatile uint8_t *)(v13 + 109) = 0;
  *(volatile uint8_t *)(v13 + 110) = 0;
  *(volatile uint8_t *)(v13 + 111) = 0;
  v19 = 16 * v16;
  v14[254] = v16;
  v16 = (v16 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v12 + 107)) & 0xFFu);
  *(volatile uint16_t *)(v13 + 130) = v19;
  *((volatile uint8_t *)v11 + 28) = v16;
  *((volatile uint8_t *)v11 + 29) = *(volatile uint8_t *)(v12 + 116);
  *((volatile uint8_t *)v11 + 51) = 0;
  *((volatile uint8_t *)v11 + 53) = 0;
  v20 = *(volatile uint8_t *)(v4 + 59);
  v21 = v13 + 108;
  if ( v20 == 1 && a1 == 3 )
  {
    get_config_flag((int)v11, (volatile uint16_t *)(v13 + 108), 24);
    v20 = (v20 & ~0xFFFFu) | ((uint16_t)(*(volatile uint8_t *)(v4 + 59)) & 0xFFFFu);
    v22 = *((volatile uint8_t *)v11 + 51) + 24;
  }
  else
  {
    v22 = 24;
  }
  v23 = v22 + store_four_halfwords(v21 + v22, v20, a1, 0, (volatile char *)a2);
  if ( *(volatile uint8_t *)(v4 + 59) == 2 )
  {
    v28 = *(volatile uint16_t *)(v4 + 54);
    if ( 512 - v23 < v28 )
    {
      if ( **(volatile int16_t **)off_135214 < 0 )
        log_warning(off_13521C, (int)aSmAuthSend_0, 1015);
    }
    else
    {
      v29 = (volatile char *)(v4 + 64);
      if ( *(volatile uint16_t *)(v4 + 54) )
      {
        v30 = &v29[v28];
        do
        {
          v31 = v29 - 64;
          v32 = *v29++;
          v31[v21 + v23 - v4] = v32;
        }
        while ( v29 != v30 );
        v28 = *(volatile uint16_t *)(v4 + 54);
      }
      v23 += v28;
    }
  }
  v24 = (volatile uint32_t *)v11[19];
  v25 = (void *)(uintptr_t)(off_135210);
  v26 = *((volatile uint8_t *)v11 + 53) + v23;
  a3 = *(volatile uint32_t *)(*(volatile uint32_t *)off_13520C + 12);
  v24[8] = v24[7] - 1 + v26;
  v24[9] = v26 + 4;
  v11[22] = (int)(uintptr_t)(v25);
  v11[23] = (int)(uintptr_t)(v11);
  sec_check((int)v11, 5);
  v2[34] = 1;
  ke_event_handler(6154, 6, a3);
  return ke_state_set(6u, 5);
}


// sm_assoc_req_send @ 0x135224
int sm_assoc_req_send() {
  int v0; // r8
  int v1; // r9
  int v2; // r6
  volatile uint8_t *v3; // r4
  int v4; // r11
  int v5; // r0
  volatile uint32_t *v6; // r4
  volatile uint8_t *v7; // r7
  int v8; // r10
  int v9; // r5
  uint16_t v10; // r3
  volatile uint16_t *v11; // r2
  int v12; // r1
  int v13; // r11
  int v14; // t1
  int v15; // lr
  uint16_t v16; // r3
  int v17; // r6
  uint16_t v18; // r12
  volatile uint16_t *v19; // r7
  int v20; // r3
  int v21; // r0
  volatile uint32_t *v22; // r1
  int v23; // r2
  int v24; // cc
  int v25; // r2
  int v26; // r0
  int v27; // r3
  int v28; // r0
  volatile uint8_t *v29; // r4
  struct __attribute__((packed)) { union { unsigned int a3; // [sp+14h] [bp-10h]
  unsigned int a3a; }; // [sp+14h] [bp-10h]
  char _pad1[2]; uint16_t a6; // [sp+1Ah] [bp-Ah] BYREF
  int a5; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  v0 = dword_135420;
  v1 = *((volatile uint32_t *)off_1353F4 + 4);
  v2 = *(volatile uint8_t *)(v1 + 61);
  v3 = (volatile uint8_t *)(dword_135420 + 1320 * v2);
  v4 = v3[116];
  check_feature_flag(256, "%s\r\n", aSmAssocReqSend);
  if ( !v3[1224] )
  {
    v5 = v3[412];
    if ( v3[412] )
      v5 = 1;
    v6 = lock_acquire(v5, 512);
    if ( v6 )
      goto LABEL_5;
    return assert_trace(1);
  }
  v6 = lock_acquire(1, 512);
  if ( !v6 )
    return assert_trace(1);
LABEL_5:
  v7 = (void *)(uintptr_t)(off_1353F4);
  _frame.a3 = 1320 * v2;
  v8 = *((volatile uint32_t *)off_1353F4 + 5);
  get_status_flag_c5(v0 + 1320 * v2, (int)v6);
  v9 = v6[18];
  v10 = (uint8_t)v7[33];
  if ( v7[33] )
  {
    v11 = (volatile uint16_t *)dword_135410;
    v10 = 32;
  }
  else
  {
    v11 = nullptr;
  }
  v12 = dword_135400;
  *(volatile uint16_t *)(v9 + 108) = v10;
  v13 = v12 + 696 * v4;
  v14 = *(volatile uint32_t *)(v13 + 38);
  v13 += 38;
  v15 = *(volatile uint32_t *)v13;
  v16 = *((volatile uint16_t *)off_135404 + 254);
  *(volatile uint32_t *)(v9 + 112) = v14;
  v17 = v0 + 1320 * v2;
  *(volatile uint16_t *)(v9 + 116) = *(volatile uint16_t *)(v13 + 4);
  v18 = *(volatile uint16_t *)(v13 + 4);
  *(volatile uint32_t *)(v9 + 118) = *(volatile uint32_t *)(v17 + 100);
  *(volatile uint16_t *)(v9 + 122) = *(volatile uint16_t *)(v17 + 104);
  ++v16;
  v19 = (void *)(uintptr_t)(off_135404);
  *(volatile uint32_t *)(v9 + 124) = v15;
  *(volatile uint16_t *)(v9 + 128) = v18;
  *(volatile uint8_t *)(v9 + 110) = 0;
  *(volatile uint8_t *)(v9 + 111) = 0;
  v15 = (v15 & ~0xFFFFu) | ((uint16_t)(16 * v16) & 0xFFFFu);
  v19[254] = v16;
  v20 = *(volatile uint8_t *)(v17 + 107);
  *(volatile uint16_t *)(v9 + 130) = v15;
  v21 = ampdu_negotiate_params((volatile uint8_t *)(v9 + 132), _frame.a3 + 248 + v0, v11, v20, (void *)(&_frame.a5), &_frame.a6, v1);
  *((volatile uint8_t *)v6 + 28) = *(volatile uint8_t *)(v17 + 107);
  v22 = (volatile uint32_t *)v6[19];
  *((volatile uint8_t *)v6 + 29) = *(volatile uint8_t *)(v17 + 116);
  v23 = _frame.a6;
  v24 = _frame.a6 > 0x320u;
  v22[8] = v22[7] + 23 + v21;
  v22[9] = v21 + 28;
  if ( v24 )
  {
    if ( **(volatile uint16_t **)off_135414 < 0 )
      log_warning(off_13541C, (int)aSmAssocReqSend_0, 1115);
    *(volatile uint16_t *)(v8 + 14) = 0;
  }
  else
  {
    if ( v23 )
    {
      v25 = v23 + v8 + 19;
      v26 = _frame.a5 - 19 - v8;
      v27 = v8 + 19;
      do
      {
        *(volatile uint8_t *)(v27 + 1) = *(volatile uint8_t *)(v26 + v27);
        ++v27;
      }
      while ( v27 != v25 );
      v23 = (v23 & ~0xFFFFu) | ((uint16_t)(_frame.a6) & 0xFFFFu);
    }
    *(volatile uint16_t *)(v8 + 14) = v23;
  }
  v28 = (int)v6;
  _frame.a3a = *(volatile uint32_t *)(*(volatile uint32_t *)off_135408 + 8);
  v6[22] = off_13540C;
  v6[23] = (int)(uintptr_t)(v6);
  v29 = (void *)(uintptr_t)(off_1353F4);
  sec_check(v28, 5);
  v29[34] = 1;
  ke_event_handler(6154, 6, _frame.a3a);
  return ke_state_set(6u, 8);
}


// mmio_write_sequence @ 0x135424
int mmio_write_sequence(uint16_t a1) {
  int v2; // r5
  int v3; // r0

  v2 = *((volatile uint32_t *)off_135454 + 4);
  v3 = tx_send_pdu(30, 0, 6, 4);
  *(volatile uint16_t *)v3 = a1;
  *(volatile uint8_t *)(v3 + 2) = 1;
  *(volatile uint8_t *)(v3 + 3) = *(volatile uint8_t *)(v2 + 61);
  rx_process_packet_1(v3);
  return ke_state_set(6u, 9);
}


// mac_assoc_rsp_handler @ 0x135458
int mac_assoc_rsp_handler(volatile char *a1) {
  int v2; // r8
  unsigned int v3; // r1
  int v4; // r6
  int v5; // r3
  int v6; // r1
  volatile char *v7; // r4
  int v8; // r12
  volatile char *v9; // r3
  char v10; // t1

  v2 = *((volatile uint32_t *)off_135514 + 5);
  invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x180A), 6);
  v3 = *(volatile uint16_t *)a1;
  v4 = *((volatile uint16_t *)a1 + 7);
  if ( v3 <= 5 )
  {
    *(volatile uint16_t *)(v2 + 16) = 0;
    check_feature_flag(256, "assoc_rsp_handler:%d\r\n", v4);
    if ( !v4 )
      return mmio_write_sequence(*((volatile uint16_t *)a1 + 8) & 0x3FFF);
  }
  else
  {
    v5 = *(volatile uint16_t *)(v2 + 14);
    v6 = (uint16_t)(v3 - 6);
    v7 = a1 + 18;
    if ( v6 + v5 > 800 )
    {
      if ( **(volatile int16_t **)off_135518 < 0 )
      {
        log_warning(off_135524, (int)aSmAssocRspHand, 1236);
        v5 = *(volatile uint16_t *)(v2 + 14);
      }
      v6 = (uint16_t)(800 - v5);
    }
    v8 = v2 + 20 + v5;
    if ( v6 )
    {
      do
      {
        v9 = v7 - 18;
        v10 = *v7++;
        *(volatile uint8_t *)(v9 - a1 + v8) = v10;
      }
      while ( v7 != &a1[v6 + 18] );
    }
    *(volatile uint16_t *)(v2 + 16) = v6;
    check_feature_flag(256, "assoc_rsp_handler:%d\r\n", v4);
    if ( !v4 )
      return mmio_write_sequence(*((volatile uint16_t *)a1 + 8) & 0x3FFF);
  }
  return assert_trace(v4);
}


// mac_proc_bss_color_change @ 0x135528
int mac_proc_bss_color_change(int a1) {
  int v2; // r6
  int result; // r0
  int v4; // r6
  int v5; // r4

  v2 = *(volatile uint8_t *)(a1 + 8);
  if ( hci_cmd_handler(6u) == 10 || hci_cmd_handler(6u) == 9 )
    return 2;
  if ( hci_cmd_handler(6u) )
  {
    if ( *(volatile uint8_t *)(*((volatile uint32_t *)off_1355B8 + 4) + 61) != *(volatile uint8_t *)(a1 + 8) )
      return 2;
    check_feature_flag(256, aDeauthHandlerI);
    if ( rf_get_state_1(6154, 6) )
      invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x180A), 6);
    assert_trace(1);
    return 0;
  }
  else
  {
    v4 = dword_1355BC + 1320 * v2;
    result = *(volatile uint8_t *)(v4 + 108);
    if ( *(volatile uint8_t *)(v4 + 108) )
    {
      v5 = *(volatile uint16_t *)(a1 + 12);
      check_feature_flag(256, "deauth_handler: reason code =%d\r\n", v5);
      ke_timer_set(v4, v5, 0);
      return 0;
    }
  }
  return result;
}


