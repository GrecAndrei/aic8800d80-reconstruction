// ble_state_check_133820 @ 0x133820
int ble_state_check_133820() {
  int v0; // r0

  if ( **(volatile int16_t **)off_13387C < 0 && hci_cmd_handler(6u) != 4 && hci_cmd_handler(6u) && hci_cmd_handler(6u) != 10 )
    irq_disable_mmio_write(dword_133884, dword_133880, 636);
  v0 = hci_cmd_handler(6u);
  if ( v0 != 4 )
  {
    v0 = hci_cmd_handler(6u);
    if ( v0 != 10 )
      return 0;
  }
  ble_reset_controller(v0);
  return 0;
}



// ble_state_check_133888 @ 0x133888
int ble_state_check_133888(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_1338BC >= 0 || (a1 = hci_cmd_handler(6u), a1 == 4) )
  {
    ble_reset_controller(a1);
    return 0;
  }
  else
  {
    v2 = irq_disable_mmio_write(dword_1338C4, dword_1338C0, 670);
    ble_reset_controller(v2);
    return 0;
  }
}



// ipc_call_6_ret5 @ 0x1338c8
int ipc_call_6_ret5() {
  if ( hci_cmd_handler(6u) != 5 && hci_cmd_handler(6u) != 6 && hci_cmd_handler(6u) != 7 && hci_cmd_handler(6u) != 8 )
    return 0;
  if ( *((volatile uint8_t *)off_133910 + 34) )
  {
    *((volatile uint8_t *)off_133910 + 34) = 0;
    return 0;
  }
  assert_trace(1);
  return 0;
}



