// ble_state_check_133914 @ 0x133914
/* luna: Checks BLE address flags and invokes the BLE event parser when both are set, disabling an IRQ in the specified HCI state. */
int ble_state_check_133914() {
  int v0; // r2
  struct __attribute__((packed)) { int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF
  } _frame;
  v0 = **(volatile int16_t **)off_133970;
  _frame.v2 = 0;
  _frame.v3 = 0;
  if ( v0 < 0 && hci_cmd_handler(6u) != 1 )
    irq_disable_mmio_write(dword_133978, dword_133974, 303);
  ble_get_addr_flag((void *)(&_frame.v2), (void *)(&_frame.v3));
  if ( _frame.v2 && _frame.v3 )
  {
    ((int (*)())ble_parse_event)();
    return 0;
  }
  else
  {
    assert_trace(1);
    return 0;
  }
}



// ble_state_check_13397c @ 0x13397c
/* luna: Dispatches BLE state-dependent link-layer work, including DMA/RF handling and completion of pending HCI or received-event processing. */
int ble_state_check_13397c() {
  int v0; // r2
  unsigned int v1; // r3
  volatile uint8_t *v2; // r3
  volatile uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  struct __attribute__((packed)) { int v7; // [sp+0h] [bp-Ch] BYREF
  int a2; // [sp+4h] [bp-8h] BYREF
  } _frame;
  if ( **(volatile int16_t **)off_133A88 < 0 && hci_cmd_handler(6u) != 4 && hci_cmd_handler(6u) != 10 )
    irq_disable_mmio_write((int)aKeStateGetTask_9, (int)aMeSetActiveCfm, 697);
  if ( hci_cmd_handler(6u) == 10 )
  {
    v4 = (void *)(uintptr_t)(off_133A8C);
    v5 = *((volatile uint8_t *)off_133A8C + 4);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_133A8C + 2) + 472) = 0;
    if ( v5 )
    {
      mac_write_header_word(6148, 13, 6);
      v4[4] = 0;
    }
    rx_process_packet_1(*(volatile uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(volatile uint32_t *)v4 = 0;
    if ( v6 )
    {
      _frame.v7 = 0;
      _frame.a2 = 0;
      ble_get_addr_flag((void *)(&_frame.v7), (void *)(&_frame.a2));
      ble_parse_event(_frame.v7, _frame.a2, 0);
    }
    else
    {
      hci_cmd_preprocess(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((volatile uint32_t *)off_133A8C + 4);
    v1 = *(volatile uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(volatile uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        mac_dma_setup();
        v2 = (void *)(uintptr_t)(off_133A90);
        if ( *((volatile uint8_t *)off_133A90 + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            ke_event_handler(6155, 6, dword_133A94);
            enable_clock_2();
          }
        }
        return 0;
      }
LABEL_5:
      ll_evt_schedule(1, 0);
      v2 = (void *)(uintptr_t)(off_133A90);
      if ( *((volatile uint8_t *)off_133A90 + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      rf_chan_state_get(dword_133A98);
      if ( *((volatile uint8_t *)off_133A90 + 13) )
        *((volatile uint8_t *)off_133A90 + 15) |= 2u;
      return 0;
    }
    assert_trace(1);
    return 0;
  }
}


// hci_apply_defaults @ 0x133aa4
/* luna: Checks connection-loss handling for the indexed BLE link and schedules its timer when offset 106 is zero and offset 108 is nonzero. */
int hci_apply_defaults(int a1, volatile uint8_t *a2) {
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  check_feature_flag(256, aConnLossInd);
  result = hci_cmd_handler(6u);
  if ( result )
    return 2;
  v4 = dword_133AEC + 1320 * v2;
  v5 = *(volatile uint8_t *)(v4 + 106);
  if ( !*(volatile uint8_t *)(v4 + 106) )
  {
    result = *(volatile uint8_t *)(v4 + 108);
    if ( *(volatile uint8_t *)(v4 + 108) )
    {
      ke_timer_set(v4, 1, *(volatile uint8_t *)(v4 + 106));
      return v5;
    }
  }
  return result;
}


