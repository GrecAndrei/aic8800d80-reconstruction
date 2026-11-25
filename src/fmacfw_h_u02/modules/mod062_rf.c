// le_connection_update @ 0x136338
/* luna: Processes an AP-start request by validating radio parameters, updating the selected VIF context, and returning a failure status when validation fails. */
int le_connection_update(int a1, int a2, int a3, int a4) {
  int vif_context_base; // r8
  uint16_t v6; // r7
  uint16_t v7; // r9
  int vif_index; // r6
  int vif_context; // r5
  char status_code; // r5
  volatile char *response_pdu; // r0
  char v13; // r2
  int16_t v14; // r3
  int v15; // r3
  volatile uint8_t *v16; // r10
  int v17; // r2
  int v18; // r3
  int v19; // r1
  uint16_t v20; // r2
  int v21; // r9
  int v22; // r3
  unsigned int v23; // r2
  volatile uint32_t *v24; // r0
  unsigned int v25; // r0
  struct __attribute__((packed)) { uint8_t a2a; // [sp+3h] [bp-11h] BYREF
  int a1a; // [sp+4h] [bp-10h] BYREF
  int v28; // [sp+8h] [bp-Ch]
  uint16_t v29; // [sp+Ch] [bp-8h]
  } _frame;
  vif_context_base = dword_136520;
  v6 = a3;
  v7 = a4;
  check_feature_flag(256, "ap start:%d, radar=%d\r\n", *(volatile uint32_t *)(a2 + 20), BYTE1(((volatile uint32_t *)(uintptr_t)off_1364FC)[103]));
  vif_index = *(volatile uint8_t *)(a2 + 51);
  vif_context = vif_context_base + 1320 * vif_index;
  if ( *(volatile uint8_t *)(vif_context + 106) != 2 )
  {
    status_code = 4;
LABEL_3:
    response_pdu = (volatile char *)tx_send_pdu(7169, v7, v6, 4);
    *response_pdu = status_code;
    response_pdu[1] = *(volatile uint8_t *)(a2 + 51);
    rx_process_packet_1((int)response_pdu);
    return 0;
  }
  if ( hci_cmd_handler(7u) )
  {
    status_code = 8;
    goto LABEL_3;
  }
  if ( *(volatile uint8_t *)(vif_context + 108) )
  {
    status_code = 9;
    goto LABEL_3;
  }
  if ( **(volatile int16_t **)off_136504 < 0 && *(volatile uint32_t *)(vif_context + 72) )
    irq_disable_mmio_write((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(volatile uint8_t *)(a2 + 28);
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 16)) & 0xFFu);
  v14 = *(volatile uint16_t *)(a2 + 14);
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
  _frame.a1a = (_frame.a1a & ~0xFFFF0000u) | (((uint16_t)(v14) & 0xFFFFu) << 16);
  v15 = *(volatile uint32_t *)(a2 + 24);
  v16 = (void *)(uintptr_t)(off_136524);
  _frame.v28 = (_frame.v28 & ~0xFFFFu) | ((uint16_t)(*(volatile uint32_t *)(a2 + 20)) & 0xFFFFu);
  v17 = *(volatile uint8_t *)(a2 + 18);
  _frame.v28 = (_frame.v28 & ~0xFFFF0000u) | (((uint16_t)(v15) & 0xFFFFu) << 16);
  v18 = *(volatile uint8_t *)(a2 + 17);
  *(volatile uint32_t *)off_136524 = a2;
  _frame.v29 = (_frame.v29 & ~0xFFu) | ((uint8_t)(v17) & 0xFFu);
  _frame.v29 = (_frame.v29 & ~0xFF00u) | (((uint8_t)(v18) & 0xFFu) << 8);
if ( ((int (*)())cfm_radio_check)((volatile uint8_t *)&_frame.a1a, &_frame.a2a, v17, v18) ) { status_code = 1;
    goto LABEL_3;
  }
  v19 = _frame.v28;
  v20 = _frame.v29;
  v21 = vif_context_base + 1320 * vif_index;
  *(volatile uint32_t *)(v21 + 412) = _frame.a1a;
  *(volatile uint32_t *)(v21 + 416) = v19;
  *(volatile uint8_t *)(v21 + 464) = 0;
  *(volatile uint16_t *)(v21 + 420) = v20;
  compute_byte_delta(v21);
  if ( BYTE1(_frame.a1a) == 2 )
    check_non_null((volatile int *)(vif_context_base + 1320 * vif_index), 1, 0);
  bsscfg_index(*(volatile uint8_t *)(a2 + 51), _frame.a2a);
  if ( *((volatile uint8_t *)off_136510 + 18) + *((volatile uint8_t *)off_136510 + 17) == 1
    && !*(volatile uint8_t *)(vif_context_base + 1320 * vif_index + 1224) )
  {
    *(volatile uint8_t *)off_13651C = 0;
    rf_rate_code_check();
  }
  if ( !*(volatile uint8_t *)(a2 + 16) )
  {
    v25 = handle_rx_packet((volatile uint8_t *)(1320 * vif_index + 424 + vif_context_base), 1) & 0xF;
    if ( v25 )
      *(volatile uint8_t *)(vif_context_base + 1320 * vif_index + 461) = 31 - __clz(v25);
    else
      *(volatile uint8_t *)(vif_context_base + 1320 * vif_index + 461) = 1;
  }
  send_hci_event_1();
  if ( !*(volatile uint32_t *)off_136514 )
  {
    v22 = vif_context_base + 1320 * vif_index;
    v23 = *(volatile uint16_t *)(v22 + 416);
    if ( v23 <= 0x1387 )
      bt_set_address(v23 | (*(volatile uint8_t *)(v22 + 413) << 16) | 0x80000000);
  }
  v24 = (volatile uint32_t *)dword_136518;
  v16[14] = v16[15];
  v16[13] = 0;
  mem_set_util((int)(uintptr_t)(v24));
  return 1;
}


// is_hci_ready @ 0x136528
/* luna: When the referenced signed state is negative and the control flag is set, performs a guarded MMIO write, then returns the stats-buffer pointer. */
volatile uint32_t *is_hci_ready() {
  if ( **(volatile int16_t **)off_13655C >= 0 || !*((volatile uint32_t *)off_136564 + 1) )
    return clear_stats_buf((volatile uint32_t *)dword_136560);
  irq_disable_mmio_write(dword_136568, dword_13656C, 46);
  return clear_stats_buf((volatile uint32_t *)dword_136560);
}



// is_ble_connected @ 0x136570
/* luna: When the request guard fields match, toggles the shared RF power state, initializing the PMU and recording the request on activation or disabling the  */
volatile uint32_t * is_ble_connected(volatile uint32_t *result) {
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r6
  int v3; // r3
  int v4; // r1

  if ( *((volatile uint8_t *)result + 108) )
  {
    v1 = result;
    if ( *((volatile uint8_t *)result + 412) == 1 )
    {
      v2 = (void *)(uintptr_t)(off_1365B8);
      if ( *((volatile uint8_t *)off_1365B8 + 13) )
      {
        *((volatile uint8_t *)off_1365B8 + 13) = 0;
        return radio_clock_disable();
      }
      else
      {
        ((int (*)())pmu_init)();
        v3 = v2[4];
        v4 = *((volatile uint32_t *)off_1365BC + 4);
        *((volatile uint8_t *)v2 + 13) = 1;
        v2[7] = (int)(uintptr_t)(v1);
        return (volatile uint32_t *)mem_copy_util((void *)(uintptr_t)((int)(v2 + 5)), v4 + v3);
      }
    }
  }
  return result;
}



// reset_hci_control_block @ 0x1365c0
/* luna: Clears and reinitializes the global HCI control block, then preprocesses HCI command 7. */
int reset_hci_control_block() {
  volatile uint8_t *hci_control_block; // r4
  void *v1; // r3

  hci_control_block = (void *)(uintptr_t)(off_1365EC);
  memset((volatile int *)off_1365EC, 0, 0x24u);
  v1 = (void *)(uintptr_t)(off_1365F0);
  hci_control_block[15] = 3;
  *((volatile uint32_t *)hci_control_block + 4) = 20000;
  *((volatile uint32_t *)hci_control_block + 6) = (int)(uintptr_t)(v1);
  hci_control_block[12] = 0;
  return hci_cmd_preprocess(7u, 0);
}


// send_vendor_hci_command @ 0x1365f4
/* luna: Queues a vendor HCI PDU for the selected link, initializing additional per-link RF state when the command selector is zero. */
int send_vendor_hci_command(int a1) {
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

  v1 = (void *)(uintptr_t)(off_1366D8);
  v3 = *(volatile uint32_t *)off_1366D8;
  v4 = (volatile uint8_t *)tx_send_pdu(7169, 13, 7, 4);
  if ( a1 )
  {
    v5 = *(volatile uint8_t *)(v3 + 51);
  }
  else
  {
    v7 = *(volatile uint8_t *)(v3 + 51);
    v8 = tx_send_pdu(30, 0, 7, 4);
    v9 = dword_1366D4 + 1320 * v7;
    *(volatile uint8_t *)(v8 + 2) = 1;
    *(volatile uint8_t *)(v8 + 3) = *(volatile uint8_t *)(v9 + 107);
    rx_process_packet_1(v8);
    v10 = *(volatile uint16_t *)(v3 + 48);
    v11 = *(volatile uint32_t *)(v9 + 72);
    *(volatile uint32_t *)(v9 + 1208) = *(volatile uint32_t *)(v3 + 44);
    *(volatile uint16_t *)(v9 + 236) = v10;
    *(volatile uint8_t *)(v9 + 234) = 0;
    v4[2] = *(volatile uint8_t *)(v11 + 24);
    v12 = dword_1366DC;
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
    get_phy_status_byte(v16);
    v17 = *(volatile uint8_t *)(v16 + 350);
    *(volatile uint16_t *)(v16 + 38) = 1;
    *(volatile uint8_t *)(v16 + 350) = v17 | 0x10;
    v5 = *(volatile uint8_t *)(v3 + 51);
    *(volatile uint8_t *)(v16 + 37) = 1;
    *(volatile uint8_t *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  rx_process_packet_1((int)v4);
  tx_process_jump((int)(uintptr_t)((volatile char *)(v3 - 12)));
  *v1 = 0;
  return hci_cmd_preprocess(7u, 0);
}


// acquire_lock_check_state @ 0x1366e0
/* luna: Pops an RX buffer, conditionally disables an MMIO interrupt when the state is negative and no buffer is available, then passes the buffer payload to t */
int acquire_lock_check_state() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r4

  v0 = list_pop(dword_136714);
  v1 = v0;
  if ( **(volatile int16_t **)off_136718 < 0 && !v0 )
    irq_disable_mmio_write(dword_136720, dword_13671C, 210);
  return (int)(uintptr_t)(rx_process_packet_1((int)(v1 + 3)));
}



// send_hci_event_1 @ 0x136724
/* luna: Queues several HCI notifications for the current connection, updates its state flags, and preprocesses the pending HCI command. */
int send_hci_event_1() {
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

  v0 = dword_136848;
  v1 = *(volatile uint32_t *)off_13683C;
  v2 = *(volatile uint8_t *)(*(volatile uint32_t *)off_13683C + 51);
  v3 = tx_send_pdu(24, 0, 7, 8);
  v4 = tx_send_pdu(22, 0, 7, 8);
  v5 = tx_send_pdu(20, 0, 7, 4);
  v6 = v0 + 1320 * v2;
  v7 = (volatile uint8_t *)tx_send_pdu(5143, 5, 7, 2);
  is_hci_ready();
  if ( *(volatile uint8_t *)(v6 + 1224) )
  {
    *(volatile uint32_t *)off_136840 &= ~4u;
    *(volatile uint32_t *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v14 = (volatile uint8_t *)tx_send_pdu(5145, 5, 7, 2);
    *v14 = 1;
    v14[1] = *(volatile uint8_t *)(v6 + 107);
    wlan_ioctl_handler_1((int)off_13683C + 4, (volatile uint32_t *)v14 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(volatile uint32_t *)(v8 + 100);
  *(volatile uint16_t *)(v3 + 4) = *(volatile uint16_t *)(v8 + 104);
  *(volatile uint32_t *)v3 = v9;
  *(volatile uint8_t *)(v3 + 6) = *(volatile uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (volatile uint32_t *)(v3 - 12));
  *(volatile uint8_t *)(v4 + 5) = *(volatile uint8_t *)(v1 + 16);
  *(volatile uint32_t *)v4 = handle_rx_packet((volatile uint8_t *)v1, 1);
  *(volatile uint8_t *)(v4 + 4) = *(volatile uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (volatile uint32_t *)(v4 - 12));
  *(volatile uint16_t *)v5 = *(volatile uint16_t *)(v1 + 40);
  *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (volatile uint32_t *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136844;
  v7[1] = *(volatile uint8_t *)(v1 + 51);
  v11 = wlan_ioctl_handler_1(v10, (volatile uint32_t *)v7 - 3);
  acquire_lock_check_state(v11, v12);
  return hci_cmd_preprocess(7u, 1);
}


// send_hci_command @ 0x13684c
/* luna: Builds an HCI PDU from the saved command data, passes it through the packet processor, and invokes preprocessing for command 7, subcommand 2. */
int send_hci_command() {
  int v0; // r4
  int v1; // r0
  int16_t v2; // r1
  int16_t v3; // r2

  v0 = *(volatile uint32_t *)off_136888;
  v1 = tx_send_pdu(63, 0, 7, 12);
  v2 = *(volatile uint16_t *)(v0 + 36);
  v3 = *(volatile uint16_t *)(v0 + 38);
  *(volatile uint32_t *)v1 = *(volatile uint32_t *)(v0 + 32);
  *(volatile uint16_t *)(v1 + 4) = v2;
  *(volatile uint16_t *)(v1 + 6) = v3;
  *(volatile uint8_t *)(v1 + 8) = *(volatile uint8_t *)(v0 + 50);
  *(volatile uint8_t *)(v1 + 9) = *(volatile uint8_t *)(v0 + 51);
  rx_process_packet_1(v1);
  return hci_cmd_preprocess(7u, 2);
}


// send_ble_hci_command @ 0x13688c
/* luna: Sends per-link control messages, selects radio parameters from another eligible link, and performs link-specific low-power cleanup. */
int send_ble_hci_command(int a1) {
  volatile uint8_t *v2; // r6
  int v3; // r0
  volatile uint8_t *v4; // r5
  volatile int *v5; // r3
  unsigned int v6; // r2
  volatile uint8_t *v7; // r0
  int v8; // r0
  int v9; // r1
  volatile uint8_t *v10; // r3
  volatile uint32_t *v11; // r0
  int v13; // r0

  v2 = (volatile uint8_t *)tx_send_pdu(5145, 5, 7, 2);
  v3 = tx_send_pdu(5143, 5, 7, 2);
  *(volatile uint8_t *)(dword_1369B0 + 696 * (*(volatile uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (volatile uint8_t *)v3;
  is_hci_ready();
  *v2 = 0;
  v2[1] = *(volatile uint8_t *)(a1 + 107);
  wlan_ioctl_handler_1(dword_1369B4, (volatile uint32_t *)v2 - 3);
  v5 = *((volatile int **)off_1369B8 + 2);
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
    bt_set_address(v6 | (*((volatile uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    bt_set_address(0);
  }
  check_non_null((volatile int *)a1, 0, 0);
  if ( *(volatile uint8_t *)(a1 + 108) )
  {
    v13 = tx_send_pdu(30, 0, 7, 4);
    *(volatile uint8_t *)(v13 + 2) = 0;
    *(volatile uint8_t *)(v13 + 3) = *(volatile uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (volatile uint32_t *)(v13 - 12));
  }
  if ( *(volatile uint32_t *)(a1 + 72) )
  {
    v7 = (volatile uint8_t *)tx_send_pdu(57, 0, 7, 1);
    *v7 = *(volatile uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (volatile uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v4[1] = *(volatile uint8_t *)(a1 + 107);
  v8 = wlan_ioctl_handler_1(dword_1369B4, (volatile uint32_t *)v4 - 3);
  acquire_lock_check_state(v8, v9);
  if ( !*(volatile uint8_t *)(a1 + 1224) )
  {
    *(volatile uint8_t *)off_1369C0 = 0;
    alloc_tx_event(aApLpExit);
  }
  v10 = (void *)(uintptr_t)(off_1369BC);
  v11 = (volatile uint32_t *)((volatile char *)off_1369BC + 20);
  *((volatile uint8_t *)off_1369BC + 13) = 0;
  v10[14] = 0;
  mem_set_util((int)(uintptr_t)(v11));
  return hci_cmd_preprocess(7u, 3);
}


// get_connection_state @ 0x1369c8
/* luna: Returns 0 only when the indexed context and connection records meet their state checks and the connection record’s low two flag bits are clear, settin */
int get_connection_state(int a1) {
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(volatile uint8_t *)(dword_136A20 + 1320 * *(volatile uint8_t *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(volatile uint8_t *)(a1 + 29);
  if ( v1 > 0x23 || !*(volatile uint16_t *)(a1 + 4) && *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136A24 + 696 * v1;
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



// lookup_conn_params @ 0x136a28
/* luna: Checks the input record against per-connection parameter bits, records one-time handling flags, and submits a connection-related PDU when the selected */
int lookup_conn_params(int result, int a2) {
  int v3; // r3
  int v4; // r0

  if ( (*(volatile uint16_t *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(volatile uint8_t *)(a2 + 310);
    if ( ((uint8_t)v3 & *(volatile uint8_t *)(dword_136A8C + *(volatile uint8_t *)(result + 27))) != 0 )
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
      v4 = tx_send_pdu(65, 0, 5, 4u);
      *(volatile uint16_t *)v4 = *(volatile uint16_t *)(a2 + 32);
      *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(a2 + 34);
      *(volatile uint8_t *)(v4 + 2) = 1;
      return (int)(uintptr_t)(rx_process_packet_1(v4));
    }
  }
  return result;
}



// handle_acl_packet @ 0x136a90
/* luna: Selects and removes an eligible ACL queue entry, updates queue bookkeeping, and signals when no further eligible entry remains. */
volatile int ** handle_acl_packet(int a1, int a2, volatile uint32_t *a3) {
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
    if ( **(volatile int16_t **)off_136BC8 < 0 )
      mmio_write_field(dword_136BD0, dword_136BCC, 441);
LABEL_26:
    *a3 = 1;
    return 0;
  }
  v9 = *(volatile uint8_t *)(a2 + 310);
  v10 = dword_136BC4;
  v11 = v5 == 2;
  v12 = 0;
  while ( ((uint8_t)(v9 & *(volatile uint8_t *)(dword_136BC4 + *((volatile uint8_t *)v8 + 27))) == 0) == v11 )
  {
    v12 = (volatile int ***)v8;
    if ( !*v8 )
      goto LABEL_24;
    v8 = (volatile int **)*v8;
  }
  is_global_flag_set(a2 + 572, (void *)(v12), (void *)(v8));
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
  v19 = tx_send_pdu(65, 0, 5, 4u);
  *(volatile uint16_t *)v19 = *(volatile uint16_t *)(a2 + 32);
  *(volatile uint8_t *)(v19 + 3) = *(volatile uint8_t *)(a2 + 34);
  *(volatile uint8_t *)(v19 + 2) = 0;
  rx_process_packet_1(v19);
  return v8;
}



// rf_get_rate_table_index @ 0x136bd4
/* luna: Checks a connection’s pending rate-event flags and emits a control PDU when the handled flags leave none pending. */
int rf_get_rate_table_index(int result, int a2) {
  int v2; // r4
  char v3; // r1
  int v4; // r0
  int16_t v5; // r1

  if ( *(volatile uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136C28 + 696 * a2;
    result = is_ll_event_pending(result, v2, 0);
    v3 = *(volatile uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(volatile uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = tx_send_pdu(65, 0, 5, 4u);
        v5 = *(volatile uint16_t *)(v2 + 32);
        *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(v2 + 34);
        *(volatile uint8_t *)(v4 + 2) = 0;
        *(volatile uint16_t *)v4 = v5;
        return (int)(uintptr_t)(rx_process_packet_1(v4));
      }
    }
  }
  return result;
}



// rf_config_lookup @ 0x136c2c
/* luna: Builds and submits an 802.11 deauthentication frame to the specified peer using reason code 7 and the interface MAC as the source and BSSID. */
int rf_config_lookup(int a1, int a2) {
  int v2; // r3
  int v5; // r3
  int result; // r0
  int tx_packet; // r5
  int frame_buffer; // r6
  volatile uint16_t *v9; // r2
  int16_t sequence_number; // r3
  int16_t v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r1
  uint64_t v15; // r2

  v2 = *(volatile uint32_t *)(a1 + 72);
  if ( v2 )
  {
    v5 = *(volatile uint8_t *)(v2 + 4);
    if ( **(volatile int16_t **)off_136D24 >= 0 || v5 != 2 )
    {
      result = (int)(uintptr_t)(lock_acquire((v5 | *(volatile uint8_t *)(a1 + 1224)) != 0, 512));
      tx_packet = result;
      if ( !result )
        return result;
LABEL_4:
      get_status_flag_c5(a1, result);
      frame_buffer = *(volatile uint32_t *)(tx_packet + 72);
      *(volatile uint8_t *)(frame_buffer + 108) = -64;
      *(volatile uint8_t *)(frame_buffer + 109) = 0;
      *(volatile uint8_t *)(frame_buffer + 110) = 0;
      *(volatile uint8_t *)(frame_buffer + 111) = 0;
      memcpy((void *)(uintptr_t)(frame_buffer + 112), (void *)(uintptr_t)(a2), 6);
      v9 = (void *)(uintptr_t)(off_136D28);
      sequence_number = *((volatile uint16_t *)off_136D28 + 254);
      v11 = *(volatile uint16_t *)(a1 + 104);
      *(volatile uint32_t *)(frame_buffer + 118) = *(volatile uint32_t *)(a1 + 100);
      ++sequence_number;
      v12 = *(volatile uint32_t *)(a1 + 100);
      *(volatile uint16_t *)(frame_buffer + 122) = v11;
      *(volatile uint32_t *)(frame_buffer + 124) = v12;
      *(volatile uint16_t *)(frame_buffer + 128) = v11;
      v9[254] = sequence_number;
      *(volatile uint16_t *)(frame_buffer + 130) = 16 * sequence_number;
      *(volatile uint32_t *)(tx_packet + 88) = 0;
      *(volatile uint32_t *)(tx_packet + 92) = a1;
      *(volatile uint8_t *)(tx_packet + 28) = *(volatile uint8_t *)(a1 + 107);
      *(volatile uint8_t *)(tx_packet + 29) = -1;
      v13 = store_half_return_two((volatile uint16_t *)(frame_buffer + 132), 7);
      v14 = *(volatile uint32_t *)(tx_packet + 76);
      v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v14 + 28) + 23 + v13) & 0xFFFFFFFFu);
      v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v13 + 28) << 32);
      *(volatile uint64_t *)(v14 + 32) = v15;
      return sec_check(tx_packet, 5);
    }
    goto LABEL_6;
  }
  if ( **(volatile int16_t **)off_136D24 < 0 )
LABEL_6:
    irq_disable_mmio_write(dword_136D30, dword_136D2C, 520);
  result = (int)(uintptr_t)(lock_acquire(1, 512));
  tx_packet = result;
  if ( result )
    goto LABEL_4;
  return result;
}



// rf_rate_code_check @ 0x136d34
/* luna: Marks AP low-power entry and allocates the corresponding AP_LP_ENTER transmit event. */
int rf_rate_code_check() {
  *(volatile uint8_t *)off_136D40 = 1;
  return alloc_tx_event(aApLpEnter);
}


// rf_rate_code_check_alt @ 0x136d48
/* luna: Clears a byte-sized state flag and allocates a TX event for AP low-power exit. */
int rf_rate_code_check_alt() {
  *(volatile uint8_t *)off_136D54 = 0;
  return alloc_tx_event(aApLpExit);
}


// rf_trace_tx_power @ 0x136d5c
/* luna: Sends the 60-byte transmit-power trace record selected by the first byte of `a2`, or an empty trace packet when that index is out of range. */
int rf_trace_tx_power(int a1, volatile uint8_t *a2, int a3, int16_t a4) {
  volatile uint16_t *trace_table; // r4
  volatile uint8_t *trace_packet; // r0
  volatile uint32_t *trace_payload; // r6
  unsigned int record_index; // r2
  volatile int *record_words; // r4
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

  trace_table = (void *)(uintptr_t)(off_136DB8);
  trace_packet = (volatile uint8_t *)tx_send_pdu(4102, a4, 4, 0x3Cu);
  trace_payload = (void *)(trace_packet);
  if ( trace_table[2] && (record_index = *a2, (uint16_t)trace_table[2] > record_index) )
  {
    record_words = (volatile int *)&trace_table[30 * record_index + 4];
    v11 = *record_words;
    v12 = record_words[1];
    v13 = record_words[2];
    v14 = record_words[3];
    record_words += 4;
    *trace_payload = v11;
    trace_payload[1] = v12;
    trace_payload[2] = v13;
    trace_payload[3] = v14;
    v15 = *record_words;
    v16 = record_words[1];
    v17 = record_words[2];
    v18 = record_words[3];
    record_words += 4;
    trace_payload[4] = v15;
    trace_payload[5] = v16;
    trace_payload[6] = v17;
    trace_payload[7] = v18;
    v19 = *record_words;
    v20 = record_words[1];
    v21 = record_words[2];
    v22 = record_words[3];
    record_words += 4;
    trace_payload[8] = v19;
    trace_payload[9] = v20;
    trace_payload[10] = v21;
    trace_payload[11] = v22;
    v23 = record_words[1];
    v24 = record_words[2];
    trace_payload[12] = *record_words;
    trace_payload[13] = v23;
    trace_payload[14] = v24;
    rx_process_packet_1((int)trace_payload);
    return 0;
  }
  else
  {
    *trace_packet = 0;
    rx_process_packet_1((int)trace_packet);
    return 0;
  }
}



// rf_trace_lo_offset @ 0x136dbc
/* luna: Sends a four-byte RF trace payload for the LO offset and processes the resulting packet. */
int rf_trace_lo_offset(int a1, int a2, int a3, int a4) {
  int v4; // r0

  v4 = tx_send_pdu(4107, a4, 4, 1);
  rx_process_packet_1(v4);
  check_feature_flag(8, aScanuIdleCance);
  return 0;
}


// rf_trace_channel @ 0x136de0
/* luna: Sends a scan-idle-cancel confirmation containing the stored status and emits a feature-gated status trace. */
int rf_trace_channel() {
  volatile uint16_t *v0; // r4
  int pdu; // r0

  v0 = (volatile uint16_t *)off_136E08;
  pdu = tx_send_pdu(4107, *((volatile uint16_t *)off_136E08 + 1924), 4, 1);
  rx_process_packet_1(pdu);
  check_feature_flag(8, "scan idle cancel cfm %d\r\n", v0[1924]);
  return 0;
}


// rf_trace_rate_set @ 0x136e10
/* luna: Builds and submits an RF trace rate-set message using the rate code from the supplied configuration. */
int rf_trace_rate_set(int a1, int a2, int a3, int a4) {
  volatile uint8_t *trace_message; // r4

  trace_message = (volatile uint8_t *)tx_send_pdu(4104, a4, 4, 2);
  check_feature_flag(8, aScanuScanningV);
  *trace_message = 1;
  trace_message[1] = *(volatile uint8_t *)(a2 + 2);
  rx_process_packet_1((int)trace_message);
  return 0;
}


// rf_calibration_meas @ 0x136e44
/* luna: Emits a feature-flagged SCANU request trace using the supplied value and a 16-bit global value, then returns 2. */
int rf_calibration_meas(int a1, int a2, int a3, int a4) {
  check_feature_flag(8, "scanning scanu req:%d,%d\n", a4, *((volatile uint16_t *)off_136E5C + 1924));
  return 2;
}


// rf_trace_rate_set2 @ 0x136e64
/* luna: Copies the supplied trace-rate payload into the shared buffer, builds a response PDU, and submits it for processing. */
int rf_trace_rate_set2(int a1, volatile char *a2, int a3, int a4) {
  volatile uint8_t *v5; // r4
  volatile char *v6; // r0
  unsigned int v7; // r2

  v5 = (volatile uint8_t *)tx_send_pdu(4104, a4, 4, 2);
  check_feature_flag(8, aScanuVndrIe);
  v6 = (volatile char *)off_136EA8;
  v7 = *(volatile uint16_t *)a2;
  *(volatile uint16_t *)off_136EA8 = v7;
  memcpy(v6 + 3, a2 + 3, v7);
  *v5 = 1;
  v5[1] = a2[2];
  rx_process_packet_1((int)v5);
  return 0;
}


