// controller_is_ready @ 0x1342ac
/* luna: Clears the BLE statistics buffer and, when the signed status is negative and the associated flag is set, issues an interrupt-disable MMIO write first. */
volatile uint32_t *controller_is_ready() {
  if ( **(volatile int16_t **)off_1342E0 >= 0 || !*((volatile uint32_t *)off_1342E8 + 6) )
    return clear_stats_buf((volatile uint32_t *)dword_1342E4);
  irq_disable_mmio_write(dword_1342EC, dword_1342F0, 132);
  return clear_stats_buf((volatile uint32_t *)dword_1342E4);
}



// ble_clear_state @ 0x1342f4
/* luna: Clears the BLE state block, dispatches two stored pointers through `tx_process_jump` when the first is nonzero, then invokes HCI preprocessing with se */
int ble_clear_state() {
  volatile uint32_t *v0; // r4
  volatile uint16_t *v1; // r3
  int v2; // r0

  v0 = (void *)(uintptr_t)(off_13432C);
  v1 = (void *)(uintptr_t)(off_134330);
  v2 = *((volatile uint32_t *)off_13432C + 4);
  *((volatile uint8_t *)off_134330 + 13) = 0;
  v1[7] = 0;
  *((volatile uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    tx_process_jump((int)(uintptr_t)((volatile char *)(v2 - 12)));
    tx_process_jump((int)(uintptr_t)((volatile char *)(v0[5] - 12)));
  }
  memset((volatile int *)off_13432C, 0, 0x2Cu);
  return hci_cmd_preprocess(6u, 0);
}


// ble_get_addr_flag @ 0x134334
/* luna: Initializes two outputs, selects address-related field values from the BLE context or a looked-up state object, and returns the lookup result. */
int ble_get_addr_flag(volatile uint32_t *a1, volatile uint32_t *a2) {
  int v2; // r6
  int result; // r0

  v2 = *((volatile uint32_t *)off_13437C + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(volatile uint8_t *)(v2 + 34) & 1) != 0 )
  {
    result = (int)(uintptr_t)(get_object_state((void *)(uintptr_t)(v2)));
    if ( result )
    {
      *a1 = result + 2;
LABEL_4:
      *a2 = *(volatile uint32_t *)(result + 44);
      return result;
    }
  }
  else
  {
    *a1 = v2 + 34;
    result = ((int (*)())rf_check_status)();
    if ( result )
      goto LABEL_4;
  }
  if ( *(volatile uint16_t *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}



// hci_build_acl @ 0x134380
/* luna: Builds and dispatches a BLE packet containing configuration data and either a supplied address or eligible entries collected from two internal address */
int hci_build_acl(int a1, int a2) {
  volatile int *v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int16_t v15; // r3
  int v16; // r5
  int v17; // r0
  int v18; // r3
  int v19; // r0
  int v20; // r2
  uint32_t v21[2]; // [sp+8h] [bp-8h]

  v4 = *((volatile int **)off_134474 + 4);
  v5 = tx_send_pdu(4096, 4, 6, 376);
  *(volatile uint8_t *)(v5 + 366) = *((volatile uint8_t *)v4 + 61);
  v6 = v5;
  v7 = *v4;
  v8 = v4[1];
  v9 = v4[2];
  v10 = v4[3];
  v4 += 4;
  *(volatile uint32_t *)(v6 + 360) = 0;
  *(volatile uint16_t *)(v6 + 364) = 0;
  *(volatile uint32_t *)(v6 + 252) = v7;
  *(volatile uint32_t *)(v6 + 256) = v8;
  *(volatile uint32_t *)(v6 + 260) = v9;
  *(volatile uint32_t *)(v6 + 264) = v10;
  v11 = v4[1];
  v12 = v4[2];
  v13 = v4[3];
  *(volatile uint32_t *)(v6 + 268) = *v4;
  *(volatile uint32_t *)(v6 + 272) = v11;
  *(volatile uint32_t *)(v6 + 276) = v12;
  *(volatile uint32_t *)(v6 + 280) = v13;
  *(volatile uint8_t *)(v6 + 284) = v4[4];
  *(volatile uint8_t *)(v6 + 368) = 1;
  if ( a1 )
  {
    *(volatile uint32_t *)(v6 + 352) = *(volatile uint32_t *)a1;
    *(volatile uint16_t *)(v6 + 356) = *(volatile uint16_t *)(a1 + 4);
    if ( a2 )
    {
LABEL_3:
      *(volatile uint32_t *)v6 = *(volatile uint32_t *)a2;
      *(volatile uint16_t *)(v6 + 4) = *(volatile uint16_t *)(a2 + 4);
      *(volatile uint8_t *)(v6 + 367) = 1;
      goto LABEL_4;
    }
  }
  else
  {
    v15 = *((volatile uint16_t *)off_134478 + 2);
    *(volatile uint32_t *)(v6 + 352) = *(volatile uint32_t *)(uintptr_t)(off_134478);
    *(volatile uint16_t *)(v6 + 356) = v15;
    if ( a2 )
      goto LABEL_3;
  }
  v21[0] = off_13447C;
  v16 = *((volatile uint8_t *)off_13447C + 253);
  v17 = *((volatile uint8_t *)off_13447C + 252);
  v21[1] = (int)(uintptr_t)((volatile char *)off_13447C + 84);
  *(volatile uint8_t *)(v6 + 367) = a2;
  while ( 1 )
  {
    if ( v17 )
    {
      v18 = v21[a2];
      v19 = 6 * (int16_t)v17 + v18;
      do
      {
        if ( (*(volatile uint8_t *)(v18 + 3) & 2) == 0 )
        {
          v20 = *(volatile uint8_t *)(v6 + 367);
          *(volatile uint8_t *)(v6 + 367) = v20 + 1;
          v20 *= 3;
          *(volatile uint32_t *)(v6 + 2 * v20) = *(volatile uint32_t *)v18;
          *(volatile uint16_t *)(v6 + 2 * v20 + 4) = *(volatile uint16_t *)(v18 + 4);
        }
        v18 += 6;
      }
      while ( v18 != v19 );
    }
    if ( a2 )
      break;
    v17 = v16;
    a2 = 1;
  }
LABEL_4:
  rx_process_packet_1(v6);
  return hci_cmd_preprocess(6u, 1);
}


// ble_parse_event @ 0x134480
/* luna: Builds an internal receive message from the supplied buffers and BLE context, dispatches it to the packet processor, and handles a deferred clock/even */
int ble_parse_event(int a1, int a2, int a3) {
  volatile uint32_t *v4; // r3
  volatile uint8_t *v7; // r9
  volatile int *v8; // r10
  int v9; // r4
  int16_t v10; // lr
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int result; // r0
  volatile uint32_t *v19; // r6
  volatile uint32_t *v20; // r4
  unsigned int v21; // r2

  v4 = (void *)(uintptr_t)(off_134584);
  if ( !*(volatile uint8_t *)(a2 + 2)
    && *((volatile uint8_t *)off_134584 + 1)
    && *(volatile int *)off_134588 < 0
    && (*((volatile uint32_t *)off_13458C + 75) & 0x80) != 0 )
  {
    if ( *((volatile uint8_t *)off_134584 + 14) == 1 )
    {
      v19 = (void *)(uintptr_t)(off_134594);
      *(volatile uint32_t *)off_134590 = dword_134598;
      v20 = (void *)(uintptr_t)(off_13459C);
      *v19 &= 0xFFFFFFF0;
      *v20 &= ~0x80000000;
      v4[1] = a1;
      v4[2] = a2;
      *((volatile uint8_t *)v4 + 12) = a3;
      *((volatile uint8_t *)v4 + 13) = 1;
      *((volatile uint16_t *)v4 + 1) = 257;
      v21 = dword_1345A0;
      v19[35594] = 0;
      ke_event_handler(6155, 6, v21);
      enable_clock_2();
      return result;
    }
    *((volatile uint8_t *)off_134584 + 3) = 0;
  }
  else
  {
    *((volatile uint8_t *)off_134584 + 14) = 0;
    *((volatile uint8_t *)v4 + 13) = 0;
    *((volatile uint8_t *)v4 + 3) = 0;
  }
  v7 = (void *)(uintptr_t)(off_1345A4);
  v8 = *((volatile int **)off_1345A4 + 4);
  v9 = tx_send_pdu(4098, 4, 6, 376);
  *(volatile uint32_t *)v9 = *(volatile uint32_t *)a2;
  v10 = *(volatile uint16_t *)(a2 + 4);
  *(volatile uint8_t *)(v9 + 367) = 1;
  v11 = *v8;
  v12 = v8[1];
  v13 = v8[2];
  v14 = v8[3];
  *(volatile uint16_t *)(v9 + 4) = v10;
  *(volatile uint32_t *)(v9 + 252) = v11;
  *(volatile uint32_t *)(v9 + 256) = v12;
  *(volatile uint32_t *)(v9 + 260) = v13;
  *(volatile uint32_t *)(v9 + 264) = v14;
  v15 = v8[5];
  v16 = v8[6];
  v17 = v8[7];
  *(volatile uint32_t *)(v9 + 268) = v8[4];
  *(volatile uint32_t *)(v9 + 272) = v15;
  *(volatile uint32_t *)(v9 + 276) = v16;
  *(volatile uint32_t *)(v9 + 280) = v17;
  *(volatile uint8_t *)(v9 + 284) = v8[8];
  *(volatile uint8_t *)(v9 + 368) = 1;
  *(volatile uint16_t *)(v9 + 364) = 0;
  *(volatile uint32_t *)(v9 + 360) = 0;
  *(volatile uint8_t *)(v9 + 366) = *((volatile uint8_t *)v8 + 61);
  *(volatile uint32_t *)(v9 + 352) = *(volatile uint32_t *)a1;
  *(volatile uint16_t *)(v9 + 356) = *(volatile uint16_t *)(a1 + 4);
  if ( a3 )
    *(volatile uint8_t *)(v9 + 3) |= 1u;
  v7[32] = a3;
  rx_process_packet_1(v9);
  return hci_cmd_preprocess(6u, 2);
}


// ble_scan_config @ 0x1345a8
/* luna: Builds and submits a BLE scan configuration packet from stored state, then preprocesses the associated HCI command. */
int ble_scan_config() {
  volatile char *v0; // r5
  volatile uint8_t *v1; // r8
  int v2; // r9
  volatile int *v3; // r10
  int v4; // r4
  uint64_t v5; // r2
  int16_t v6; // lr
  int v7; // r0
  int v8; // r1
  uint64_t v9; // r2
  int v10; // r1
  uint64_t v11; // r2

  v0 = (volatile char *)off_134650;
  v1 = (void *)(uintptr_t)(off_134658);
  v2 = *((volatile uint8_t *)off_134650 + 12);
  v3 = *((volatile int **)off_134658 + 4);
  v4 = tx_send_pdu(4098, 4, 6, 376);
  alloc_tx_event(aTs1);
  invalid_handler_12c5fc((int)(uintptr_t)((volatile char *)0x180B), 6);
  v5 = *(volatile uint64_t *)(v0 + 4);
  v0[14] = 0;
  *(volatile uint32_t *)(v4 + 352) = *(volatile uint32_t *)v5;
  v0 = (void *)(uintptr_t)(((uintptr_t)(v0) & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)v4 = *(volatile uint32_t *)HIDWORD(v5);
  v6 = *(volatile uint16_t *)(HIDWORD(v5) + 4);
  *(volatile uint8_t *)(v4 + 367) = 1;
  v7 = *v3;
  v8 = v3[1];
  v9 = *((volatile uint64_t *)v3 + 1);
  *(volatile uint16_t *)(v4 + 356) = (uint16_t)v0;
  *(volatile uint16_t *)(v4 + 4) = v6;
  *(volatile uint32_t *)(v4 + 252) = v7;
  *(volatile uint32_t *)(v4 + 256) = v8;
  *(volatile uint64_t *)(v4 + 260) = v9;
  v10 = v3[5];
  v11 = *((volatile uint64_t *)v3 + 3);
  *(volatile uint32_t *)(v4 + 268) = v3[4];
  *(volatile uint32_t *)(v4 + 272) = v10;
  *(volatile uint64_t *)(v4 + 276) = v11;
  *(volatile uint8_t *)(v4 + 284) = v3[8];
  *(volatile uint8_t *)(v4 + 368) = 1;
  *(volatile uint16_t *)(v4 + 364) = 0;
  *(volatile uint32_t *)(v4 + 360) = 0;
  *(volatile uint8_t *)(v4 + 366) = *((volatile uint8_t *)v3 + 61);
  if ( v2 )
    *(volatile uint8_t *)(v4 + 3) |= 1u;
  v1[32] = v2;
  rx_process_packet_1(v4);
  return hci_cmd_preprocess(6u, 2);
}


// get_acl_conn_slot @ 0x13465c
/* luna: Checks the ACL connection entry selected by the current BLE connection index against the supplied argument and returns the helper result. */
int get_acl_conn_slot(volatile uint8_t *a1) {
  return cfm_radio_check(
           (volatile uint8_t *)(dword_134678 + 1320 * *(volatile uint8_t *)(*((volatile uint32_t *)off_134674 + 4) + 61)),
           a1);
}



// ble_reset_controller @ 0x13467c
/* luna: Pops one BLE receive-queue entry, disables the MMIO interrupt if the queue is empty and the controller state is negative, then passes the entry payloa */
int ble_reset_controller() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r4

  v0 = list_pop(dword_1346B0);
  v1 = v0;
  if ( **(volatile int16_t **)off_1346B4 < 0 && !v0 )
    irq_disable_mmio_write(dword_1346BC, dword_1346B8, 766);
  return (int)(uintptr_t)(rx_process_packet_1((int)(v1 + 3)));
}



// hci_send_cmd_1419 @ 0x1346c0
/* luna: Posts connection cleanup events, handles the associated scheduled event, and resets BLE controller state. */
int hci_send_cmd_1419(int a1) {
  int v1; // lr
  int v3; // r7
  volatile uint8_t *v4; // r6
  int v5; // r0
  volatile unsigned int *v6; // r3
  volatile uint8_t *v7; // r5
  volatile uint8_t *v8; // r0
  volatile uint8_t *v9; // r0
  int v10; // r0
  int v11; // r1
  int v13; // r0

  v3 = v1;
  v4 = (volatile uint8_t *)tx_send_pdu(5145, 5, 6, 2);
  v5 = tx_send_pdu(5143, 5, 6, 2);
  v6 = (volatile unsigned int *)off_1347C0;
  v7 = (volatile uint8_t *)v5;
  if ( (*(volatile uint32_t *)off_1347C0 & 0x4000000) != 0 )
  {
    *(volatile uint32_t *)off_1347C0 &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  *((volatile uint8_t *)off_1347C8 + 73) = *(volatile uint8_t *)off_1347C4;
  alloc_tx_event("delete reources: %x\n", v3);
  controller_is_ready();
  phy_sleep_prepare(a1);
  ke_event_schedule_1(*(volatile uint8_t *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(volatile uint8_t *)(a1 + 107);
  wlan_ioctl_handler_1(dword_1347D0, (volatile uint32_t *)v4 - 3);
  if ( *(volatile uint8_t *)(a1 + 108) )
  {
    v13 = tx_send_pdu(30, 0, 6, 4);
    *(volatile uint8_t *)(v13 + 2) = 0;
    *(volatile uint8_t *)(v13 + 3) = *(volatile uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1347D0, (volatile uint32_t *)(v13 - 12));
  }
  if ( *(volatile uint8_t *)(a1 + 116) != 255 )
  {
    v8 = (volatile uint8_t *)tx_send_pdu(12, 0, 6, 1);
    *v8 = *(volatile uint8_t *)(a1 + 116);
    wlan_ioctl_handler_1(dword_1347D0, (volatile uint32_t *)v8 - 3);
  }
  if ( *(volatile uint32_t *)(a1 + 72) )
  {
    v9 = (volatile uint8_t *)tx_send_pdu(57, 0, 6, 1);
    *v9 = *(volatile uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1347D0, (volatile uint32_t *)v9 - 3);
  }
  *v7 = 0;
  v7[1] = *(volatile uint8_t *)(a1 + 107);
  v10 = wlan_ioctl_handler_1(dword_1347D0, (volatile uint32_t *)v7 - 3);
  return ble_reset_controller(v10, v11);
}


// ble_load_defaults @ 0x1347d4
/* luna: Initializes BLE state, selects an address from an eligible connection entry when available, and submits the default HCI configuration. */
int ble_load_defaults() {
  volatile uint16_t *v0; // r6
  int v1; // r4
  int v2; // r5
  int16_t v3; // r7
  volatile int *v4; // r3
  int v5; // r1
  unsigned int v6; // r2
  int result; // r0
  volatile uint32_t *v8; // r1
  volatile int *v9; // r2
  volatile uint32_t *v10; // r12
  volatile int *v11; // r0

  v0 = (void *)(uintptr_t)(off_134910);
  v1 = *((volatile uint32_t *)off_134910 + 2);
  check_feature_flag(256, aSmDisconnectFi);
  v2 = tx_send_pdu(6149, 13, 6, 6);
  if ( *((volatile uint8_t *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(volatile uint8_t *)(v1 + 149) = 0;
  mem_set_util((int)(uintptr_t)((volatile uint32_t *)(v1 + 152)));
  v4 = *((volatile int **)off_134918 + 2);
  if ( !v4 )
  {
LABEL_14:
    bt_set_address(0);
    goto LABEL_15;
  }
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((volatile uint8_t *)v4 + 106) )
      {
        if ( !*((volatile uint8_t *)v4 + 108) )
          goto LABEL_8;
        ++v5;
        if ( (volatile int *)v1 == v4 )
          goto LABEL_8;
        break;
      }
      if ( (volatile int *)v1 == v4 )
        goto LABEL_8;
      if ( *((volatile uint8_t *)v4 + 108) )
        break;
      v4 = (volatile int *)*v4;
      if ( !v4 )
      {
LABEL_13:
        if ( *(volatile int *)off_13491C < 0 && v5 == 1 )
        {
          v8 = (void *)(uintptr_t)(off_134924);
          *((volatile uint8_t *)off_134920 + 2) = (uint8_t)v4;
          v9 = (volatile int *)off_134928;
          *v8 |= 0x80000000;
          *v9 = (HIWORD(*v9) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v6 = *((volatile uint16_t *)v4 + 208);
    if ( v6 <= 0x1387 )
      break;
LABEL_8:
    v4 = (volatile int *)*v4;
    if ( !v4 )
      goto LABEL_13;
  }
  if ( *(volatile int *)off_13491C < 0 && v5 == 1 )
  {
    v10 = (void *)(uintptr_t)(off_134924);
    *((volatile uint8_t *)off_134920 + 2) = 0;
    v11 = (volatile int *)off_134928;
    *v10 |= 0x80000000;
    *v11 = (HIWORD(*v11) << 16) | 0x5DC;
    bt_set_address(v6 | (*((volatile uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
  else
  {
    bt_set_address(v6 | (*((volatile uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
LABEL_15:
  check_non_null((volatile int *)v1, 0, 0);
  result = hci_send_cmd_1419(v1);
  *(volatile uint16_t *)v2 = v3;
  *(volatile uint8_t *)(v2 + 2) = *(volatile uint8_t *)(v1 + 107);
  *(volatile uint8_t *)(v2 + 4) = *((volatile uint8_t *)v0 + 33);
  *(volatile uint32_t *)v0 = v2 - 12;
  return result;
}


// log_startup @ 0x13492c
/* luna: Records the deauthentication-failure event when the startup flags match, then loads BLE defaults. */
int log_startup(int a1, int a2) {
  if ( (a2 & 0x810000) == 0x10000 )
    alloc_tx_event(aSendDeauthFail);
  return ble_load_defaults();
}


