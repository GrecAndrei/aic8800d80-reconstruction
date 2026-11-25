// scan_trigger @ 0x133b7c
int scan_trigger() {
  int v0; // r0

  if ( **(volatile int16_t **)off_133BD8 < 0 && hci_cmd_send_short(6u) != 4 && hci_cmd_send_short(6u) && hci_cmd_send_short(6u) != 10 )
    mmio_irq_clear(dword_133BE0, dword_133BDC, 636);
  v0 = hci_cmd_send_short(6u);
  if ( v0 != 4 )
  {
    v0 = hci_cmd_send_short(6u);
    if ( v0 != 10 )
      return 0;
  }
  check_hw_ready_status(v0);
  return 0;
}



// patch_stop @ 0x133be4
int patch_stop(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_133C18 >= 0 || (value = hci_cmd_send_short(6u), value == 4) )
  {
    check_hw_ready_status(value);
    return 0;
  }
  else
  {
    v2 = mmio_irq_clear(dword_133C20, dword_133C1C, 670);
    check_hw_ready_status(v2);
    return 0;
  }
}



// ke_wait_event @ 0x133c24
int ke_wait_event() {
  if ( hci_cmd_send_short(6u) != 5 && hci_cmd_send_short(6u) != 6 && hci_cmd_send_short(6u) != 7 && hci_cmd_send_short(6u) != 8 )
    return 0;
  if ( *((volatile uint8_t *)off_133C6C + 34) )
  {
    *((volatile uint8_t *)off_133C6C + 34) = 0;
    return 0;
  }
  event_dispatch_1(1);
  return 0;
}



