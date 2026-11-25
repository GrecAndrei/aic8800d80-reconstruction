// patch_critical_enter @ 0x133e4c
int patch_critical_enter() {
  volatile uint8_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r8
  int v4; // r4
  int v5; // r9
  int v6; // r3
  unsigned int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r6
  int v12; // r0
  int16_t v13; // r2
  int v14; // r3
  int v15; // r10
  volatile uint32_t *v16; // r1
  int v17; // r2
  int v18; // r0
  struct __attribute__((packed)) { int a1; // [sp+18h] [bp-Ch] BYREF
  int a2[2]; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_133FF0);
  v1 = *((volatile uint32_t *)off_133FF0 + 4);
  if ( **(volatile int16_t **)off_133FEC < 0 && hci_cmd_send_short(6u) != 2 )
    mmio_irq_clear((int)aKeStateGetTask_10, (int)aScanuJoinCfmHa, 344);
  v2 = *(volatile uint8_t *)(v1 + 61);
  v3 = dword_134004;
  v4 = 1320 * v2;
  v5 = dword_134004 + 1320 * v2;
  if ( *(volatile int *)(v5 + 472) < 0 )
  {
if ( phy_channel_index_lookup((void *)(uintptr_t)((int)_frame.a2)) ) { event_dispatch_1(1);
    }
    else
    {
      v11 = bt_buf_alloc(10, 0, 6, 32);
      update_entries_from_config(*(volatile uint8_t *)(v1 + 61), LOBYTE(_frame.a2[0]));
      *(volatile uint32_t *)v11 = 0;
      *(volatile uint8_t *)(v11 + 25) = *(volatile uint8_t *)(v1 + 61);
      v12 = *(volatile uint32_t *)(v5 + 368);
      v13 = *(volatile uint16_t *)(v5 + 372);
      *(volatile uint8_t *)(v11 + 26) = 0;
      *(volatile uint8_t *)(v11 + 29) = *(volatile uint8_t *)(v5 + 407);
      *(volatile uint8_t *)(v11 + 30) = *(volatile uint8_t *)(v5 + 408);
      v14 = *(volatile uint32_t *)(v5 + 472);
      *(volatile uint32_t *)(v11 + 18) = v12;
      v15 = v14 & 2;
      *(volatile uint16_t *)(v11 + 22) = v13;
      if ( (v14 & 2) != 0 )
      {
        v15 = v14 & 4;
        if ( (v14 & 4) != 0 )
        {
          v18 = extract_chan_bits(v4 + 368 + v3);
          v14 = *(volatile uint32_t *)(v5 + 472);
          v16 = (volatile uint32_t *)(v4 + 280 + v3);
          v15 = v18;
        }
        else
        {
          v16 = nullptr;
        }
        v17 = v14 & 8;
        if ( (v14 & 8) != 0 )
          v17 = v4 + 292 + v3;
        llm_parse_adv_pdu(
          v4 + 248 + v3,
          v16,
          v17,
          (volatile uint16_t *)(v11 + 16),
          (volatile int *)(v11 + 8),
          (volatile int *)(v11 + 4),
          (volatile char *)(v11 + 24));
      }
      *(volatile uint32_t *)(v11 + 12) = v15;
      hci_evt_send(v11);
      hci_cmd_send(6u, 3);
    }
    v9 = *(volatile uint32_t *)(v1 + 48);
    v10 = v3 + 1320 * v2;
    *(volatile uint32_t *)(v10 + 1208) = v9;
    if ( (v9 & 4) != 0 )
    {
      *(volatile uint32_t *)(v10 + 472) &= 0xFFFFFFF1;
      return 0;
    }
    return 0;
  }
  v6 = (uint8_t)v0[32];
  if ( v0[32] )
  {
    event_dispatch_1(1);
    return 0;
  }
  _frame.a1 = (uint8_t)v0[32];
  _frame.a2[0] = v6;
  ull_scan_event_start((void *)(&_frame.a1), (void *)(_frame.a2));
  if ( *(volatile uint8_t *)off_133FF4 != 1 && *((volatile uint8_t *)off_133FF8 + 3) != 1 )
  {
    *((volatile uint8_t *)off_133FF8 + 32) = 2;
LABEL_7:
    rx_security_check(_frame.a1, _frame.a2[0], 1);
    return 0;
  }
  v8 = (uint8_t)(*((volatile uint8_t *)off_133FF8 + 32) + 1);
  *((volatile uint8_t *)off_133FF8 + 32) = v8;
  if ( v8 > 1 )
    goto LABEL_7;
  rx_security_check(_frame.a1, _frame.a2[0], 0);
  return 0;
}


// llm_le_set_scan_enable @ 0x134008
int llm_le_set_scan_enable(int a1, volatile uint16_t *a2) {
  int v3; // r6
  volatile int *v4; // r4
  int v5; // r0
  int v6; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2

  v3 = *((volatile uint8_t *)a2 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1340A4 = 1;
  }
  v4 = (volatile int *)off_1340A8;
  ++*(volatile uint32_t *)off_1340A8;
  if ( hci_cmd_send_short(6u) || *((volatile uint8_t *)off_1340AC + 14) && find_hci_conn_by_handle(6155, 6) )
  {
    if ( *v4 )
    {
      v10 = *v4 - 1;
      v11 = *(volatile uint32_t *)off_1340A4;
      *v4 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    return 2;
  }
  else
  {
    if ( *v4 )
    {
      v8 = *v4 - 1;
      v9 = *(volatile uint32_t *)off_1340A4;
      *v4 = v8;
      if ( !v8 )
      {
        if ( v9 )
          __enable_irq();
      }
    }
    v5 = dword_1340B0 + 1320 * v3;
    v6 = *(volatile uint8_t *)(v5 + 106);
    if ( !*(volatile uint8_t *)(v5 + 106) && *(volatile uint8_t *)(v5 + 108) )
    {
      init_rf_config(v5, *a2, 1);
      return v6;
    }
    else
    {
      hci_evt_alloc_send(6148, 13, 6);
      return 0;
    }
  }
}



// llm_state_check_ready @ 0x1340b4
int llm_state_check_ready(int a1, int a2, int a3, int a4) {
  int v4; // r9
  uint16_t v6; // r7
  uint16_t v7; // r6
  volatile uint8_t *v8; // r5
  int v9; // r8
  volatile uint8_t *v10; // r3
  volatile int16_t **v11; // r10
  volatile uint32_t *v12; // r9
  volatile int *v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r6
  int v19; // r4
  int v21; // r1
  struct __attribute__((packed)) { int v22; // [sp+0h] [bp-8h] BYREF
  int a2a; // [sp+4h] [bp-4h] BYREF
  } _frame;
  v4 = *(volatile uint8_t *)(a2 + 61);
  v6 = a3;
  v7 = a4;
  if ( hci_cmd_send_short(6u) != 10 )
  {
    v8 = (volatile uint8_t *)bt_buf_alloc(6145, v7, v6, 1);
    if ( hci_cmd_send_short(6u) )
    {
      *v8 = 8;
      v19 = 0;
    }
    else if ( *(volatile uint8_t *)(a2 + 61) > 3u
           || (v9 = dword_134274, v10 = (volatile uint8_t *)(dword_134274 + 1320 * v4), v10[106]) )
    {
      *v8 = 4;
      v19 = 0;
    }
    else
    {
      if ( !v10[108] )
      {
        v11 = (volatile int16_t **)off_134278;
        if ( **(volatile int16_t **)off_134278 < 0 )
        {
          if ( (uint8_t)v10[116] == 255
            || (mmio_irq_clear((int)aVifUStaApIdInv, (int)aSmConnectReqHa, 102), **v11 < 0) )
          {
            if ( *(volatile uint32_t *)(v9 + 1320 * v4 + 72) )
              mmio_irq_clear((int)aVifChanCtxtNul_0, (int)aSmConnectReqHa, 103);
          }
        }
        v12 = (void *)(uintptr_t)(off_13427C);
        *((volatile uint8_t *)off_13427C + 33) = 0;
        goto LABEL_8;
      }
      v21 = *(volatile uint32_t *)(a2 + 48) & 0x20;
      if ( v21 )
      {
        v12 = (void *)(uintptr_t)(off_13427C);
        *((volatile uint8_t *)off_13427C + 33) = 1;
        ke_event_schedule_1(aReassoc, v21);
LABEL_8:
        v13 = (volatile int *)off_134258;
        v14 = off_13425C;
        *(volatile uint8_t *)off_134254 = 0;
        v15 = *v13;
        *(volatile uint8_t *)(v14 + 0x20) = 0;
        *v13 = v15 | 0x10;
        v16 = *(volatile uint8_t *)(a2 + 59);
        *(volatile uint8_t *)(v14 + 0xE) = 1;
if ( v16 == 3 && ((int (*)())hci_event_parse)((void *)(uintptr_t)(a2 + 64), *(volatile uint16_t *)(a2 + 54), v14, 3) > 0 ) *(volatile uint8_t *)(a2 + 59) = 0;
        v12[4] = a2;
        v17 = bt_buf_alloc(6146, v7, v6, 852);
        v18 = *((volatile uint8_t *)v12 + 33);
        v12[5] = v17;
        if ( v18 )
        {
          memcpy((volatile char *)dword_134260, (volatile char *)(v9 + 1320 * *(volatile uint8_t *)(a2 + 61) + 64), 6u);
          init_rf_config(v9 + 1320 * *(volatile uint8_t *)(a2 + 61), 0, 0);
        }
        else
        {
          _frame.v22 = 0;
          _frame.a2a = 0;
          ull_scan_event_start((void *)(&_frame.v22), (void *)(&_frame.a2a));
          if ( _frame.v22 && _frame.a2a )
            rx_security_check(_frame.v22, _frame.a2a, 0);
          else
            wlan_hw_init(_frame.v22, _frame.a2a);
        }
        *v8 = 0;
        v19 = 1;
        goto LABEL_13;
      }
      v19 = 0;
      *v8 = 9;
    }
LABEL_13:
    hci_evt_send((int)v8);
    return v19;
  }
  return 2;
}


// ll_event_process @ 0x134280
int ll_event_process() {
  int v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int v5; // r2
  int v6; // r3
  int16_t v7; // r1
  volatile uint8_t *v8; // r0

  if ( hci_cmd_send_short(6u) == 9 )
  {
    v1 = *((volatile uint32_t *)off_134324 + 4);
    v2 = dword_134328 + 1320 * *(volatile uint8_t *)(v1 + 61);
    v3 = *(volatile uint8_t *)(v2 + 116);
    v4 = bt_buf_alloc(75, 0, 6, 6u);
    *(volatile uint8_t *)(v4 + 4) = *(volatile uint8_t *)(v1 + 58);
    *(volatile uint16_t *)(v4 + 2) = *(volatile uint16_t *)(v1 + 56);
    *(volatile uint8_t *)v4 = *(volatile uint8_t *)(v1 + 61);
    hci_evt_send(v4);
    v5 = dword_13432C + 696 * v3;
    v6 = 2 - (*(volatile uint32_t *)(v2 + 1208) & 1);
    v7 = __rev16(*(volatile uint16_t *)(v1 + 52));
    *(volatile uint8_t *)(v5 + 52) = v6;
    *(volatile uint16_t *)(v5 + 56) = v7;
    if ( v6 == 2 )
    {
      v8 = (volatile uint8_t *)bt_buf_alloc(5145, 5, 6, 2u);
      *v8 = 0;
      v8[1] = *(volatile uint8_t *)(v1 + 61);
      hci_evt_send((int)v8);
    }
    event_dispatch_1(0);
    return 0;
  }
  else
  {
    if ( hci_cmd_send_short(6u) == 10 )
      check_hw_ready_status(10);
    return 0;
  }
}



