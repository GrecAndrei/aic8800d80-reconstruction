// tx_slot_counter_inc @ 0x12b098
int tx_slot_counter_inc(int a1, unsigned int a2, int a3) {
  int result; // r0
  int v4; // r1
  unsigned int v5; // r3
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r2

  if ( a2 <= 0x1F )
  {
    if ( a3 )
    {
      result = dword_12B118 + 32 * a1;
      v4 = 3 * a2 + dword_12B11C;
      v5 = *(volatile uint8_t *)(v4 + 2);
      ++*(volatile uint32_t *)(result + 20);
      if ( v5 <= 2 )
        *(volatile uint8_t *)(v4 + 2) = v5 + 1;
    }
    else
    {
      result = dword_12B118 + 32 * a1;
      v6 = 3 * a2 + dword_12B11C;
      v7 = *(volatile uint8_t *)(v6 + 1);
      ++*(volatile uint32_t *)(result + 16);
      if ( v7 <= 2 )
        *(volatile uint8_t *)(v6 + 1) = v7 + 1;
    }
  }
  else
  {
    if ( a3 )
    {
      v8 = **(volatile int16_t **)off_12B120;
      ++*(volatile uint32_t *)(dword_12B118 + 32 * a1 + 20);
      if ( v8 < 0 )
        mmio_irq_clear(dword_12B128, dword_12B124, 365);
      __und(0xFFu);
    }
    result = dword_12B118 + 32 * a1;
    ++*(volatile uint32_t *)(result + 16);
  }
  return result;
}



// mac_duration_calc @ 0x12b12c
int mac_duration_calc(int a1, int a2, int a3) {
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12B14C;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12B14C + 32 * a1;
  if ( v4 )
    *(volatile uint32_t *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(volatile uint32_t *)(result + 24) = v3;
  return result;
}



// ke_timer_schedule @ 0x12b150
int ke_timer_schedule(int a1, int a2, int a3, uint16_t a4) {
  int v5; // r4

  v5 = hci_cmd_send_short(2u);
  state_check_feature(4, "%s:%d\r\n", aScanCancelReqH, v5);
  if ( v5 )
    *((volatile uint8_t *)off_12B188 + 11) = 1;
  else
    bt_send_hci_804(1, a4);
  return 0;
}


// ke_timer_wait @ 0x12b18c
int ke_timer_wait() {
  int v0; // r0
  volatile uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( hci_cmd_send_short(2u) != 3 )
  {
    v0 = hci_cmd_send_short(2u);
    ke_event_schedule_1("end st=%d\n", v0);
  }
  if ( **(volatile int16_t **)off_12B21C < 0 && hci_cmd_send_short(2u) != 3 )
    mmio_irq_clear((int)aKeStateGetTask_2, (int)aMmScanChannelE, 201);
  v1 = (void *)(uintptr_t)(off_12B220);
  v2 = *(volatile uint32_t *)off_12B220;
  v3 = *(volatile uint8_t *)(*(volatile uint32_t *)off_12B220 + 367);
  v4 = (uint8_t)(*((volatile uint8_t *)off_12B220 + 10) + 1);
  *((volatile uint8_t *)off_12B220 + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    jump_to_tx_entry((int)(uintptr_t)((volatile char *)(v2 - 12)));
    v5 = *((volatile uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      bt_send_hci_804(0, v5);
      v1[11] = 0;
    }
    else
    {
      hci_evt_alloc_send(2050, v5, 2);
    }
    hci_cmd_send(2u, 0);
    return 0;
  }
  else
  {
    bt_get_link_state();
    return 0;
  }
}


