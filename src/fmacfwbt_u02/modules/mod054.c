// mmio_init @ 0x133c70
int mmio_init() {
  int v0; // r2
  struct __attribute__((packed)) { int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF
  } _frame;
  v0 = **(volatile int16_t **)off_133CCC;
  _frame.v2 = 0;
  _frame.v3 = 0;
  if ( v0 < 0 && hci_cmd_send_short(6u) != 1 )
    mmio_irq_clear(dword_133CD4, dword_133CD0, 303);
  ull_scan_event_start((void *)(&_frame.v2), (void *)(&_frame.v3));
  if ( _frame.v2 && _frame.v3 )
  {
    ((int (*)())rx_security_check)();
    return 0;
  }
  else
  {
    event_dispatch_1(1);
    return 0;
  }
}



// util_reset @ 0x133cd8
int util_reset() {
  int v0; // r2
  unsigned int v1; // r3
  volatile uint8_t *v2; // r3
  volatile uint8_t *v4; // r4
  int v5; // r3
  int v6; // r1
  struct __attribute__((packed)) { int v7; // [sp+0h] [bp-Ch] BYREF
  int a2; // [sp+4h] [bp-8h] BYREF
  } _frame;
  if ( **(volatile int16_t **)off_133DE4 < 0 && hci_cmd_send_short(6u) != 4 && hci_cmd_send_short(6u) != 10 )
    mmio_irq_clear((int)aKeStateGetTask_9, (int)aMeSetActiveCfm, 697);
  if ( hci_cmd_send_short(6u) == 10 )
  {
    v4 = (void *)(uintptr_t)(off_133DE8);
    v5 = *((volatile uint8_t *)off_133DE8 + 4);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_133DE8 + 2) + 472) = 0;
    if ( v5 )
    {
      hci_evt_alloc_send(6148, 13, 6);
      v4[4] = 0;
    }
    hci_evt_send(*(volatile uint32_t *)v4 + 12);
    v6 = (uint8_t)v4[33];
    *(volatile uint32_t *)v4 = 0;
    if ( v6 )
    {
      _frame.v7 = 0;
      _frame.a2 = 0;
      ull_scan_event_start((void *)(&_frame.v7), (void *)(&_frame.a2));
      rx_security_check(_frame.v7, _frame.a2, 0);
    }
    else
    {
      hci_cmd_send(6u, 0);
    }
    return 0;
  }
  else
  {
    v0 = *((volatile uint32_t *)off_133DE8 + 4);
    v1 = *(volatile uint8_t *)(v0 + 59);
    if ( v1 == 2 )
    {
      if ( (*(volatile uint32_t *)(v0 + 48) & 0x40) != 0 )
      {
        rf_lookup_alt_by_index();
        v2 = (void *)(uintptr_t)(off_133DEC);
        if ( *((volatile uint8_t *)off_133DEC + 13) )
        {
LABEL_6:
          if ( (v2[15] & 1) != 0 )
          {
            patch_aware_dispatch(6155, 6, dword_133DF0);
            clock_disable();
          }
        }
        return 0;
      }
LABEL_5:
      rf_lookup_by_index(1, 0);
      v2 = (void *)(uintptr_t)(off_133DEC);
      if ( *((volatile uint8_t *)off_133DEC + 13) )
        goto LABEL_6;
      return 0;
    }
    if ( v1 <= 2 )
      goto LABEL_5;
    if ( v1 == 3 )
    {
      rf_check_status_1(dword_133DF4);
      if ( *((volatile uint8_t *)off_133DEC + 13) )
        *((volatile uint8_t *)off_133DEC + 15) |= 2u;
      return 0;
    }
    event_dispatch_1(1);
    return 0;
  }
}


// ll_event_prepare @ 0x133e00
int ll_event_prepare(int a1, volatile uint8_t *a2) {
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  state_check_feature(256, aConnLossInd);
  result = hci_cmd_send_short(6u);
  if ( result )
    return 2;
  v4 = dword_133E48 + 1320 * v2;
  v5 = *(volatile uint8_t *)(v4 + 106);
  if ( !*(volatile uint8_t *)(v4 + 106) )
  {
    result = *(volatile uint8_t *)(v4 + 108);
    if ( *(volatile uint8_t *)(v4 + 108) )
    {
      init_rf_config(v4, 1, *(volatile uint8_t *)(v4 + 106));
      return v5;
    }
  }
  return result;
}


