// is_bt_enabled @ 0x1360bc
int is_bt_enabled(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_1360F0 >= 0 || (a1 = hci_cmd_handler(7u), a1 == 3) )
  {
    acquire_lock_check_state(a1);
    return 0;
  }
  else
  {
    v2 = irq_disable_mmio_write(dword_1360F8, dword_1360F4, 415);
    acquire_lock_check_state(v2);
    return 0;
  }
}



// is_bt_initialized @ 0x1360fc
int is_bt_initialized() {
  if ( **(volatile int16_t **)off_136144 < 0 && hci_cmd_handler(7u) != 3 && hci_cmd_handler(7u) )
    irq_disable_mmio_write(dword_13614C, dword_136148, 442);
  if ( hci_cmd_handler(7u) == 3 )
    acquire_lock_check_state(3);
  return 0;
}



// is_tx_enabled @ 0x136150
int is_tx_enabled() {
  int v0; // r0

  if ( **(volatile int16_t **)off_1361AC < 0 && hci_cmd_handler(7u) != 1 && hci_cmd_handler(7u) && hci_cmd_handler(7u) != 3 )
    irq_disable_mmio_write(dword_1361B4, dword_1361B0, 274);
  v0 = hci_cmd_handler(7u);
  if ( v0 != 1 )
  {
    v0 = hci_cmd_handler(7u);
    if ( v0 != 3 )
      return 0;
  }
  acquire_lock_check_state(v0);
  return 0;
}



// is_rx_enabled @ 0x1361b8
int is_rx_enabled(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_1361EC >= 0 || (a1 = hci_cmd_handler(7u), a1 == 1) )
  {
    acquire_lock_check_state(a1);
    return 0;
  }
  else
  {
    v2 = irq_disable_mmio_write(dword_1361F4, dword_1361F0, 311);
    acquire_lock_check_state(v2);
    return 0;
  }
}



// is_scan_enabled @ 0x1361f8
int is_scan_enabled() {
  if ( **(volatile int16_t **)off_136230 >= 0 || hci_cmd_handler(7u) == 2 )
  {
    send_vendor_hci_command(0);
    return 0;
  }
  else
  {
    irq_disable_mmio_write(dword_136238, dword_136234, 388);
    send_vendor_hci_command(0);
    return 0;
  }
}



// is_link_active @ 0x13623c
/* luna: Handles the ME set-active confirmation path by validating the ME and link state and dispatching the corresponding follow-up message. */
int is_link_active() {
  volatile int16_t **v0; // r4

  v0 = (volatile int16_t **)off_1362C8;
  if ( **(volatile int16_t **)off_1362C8 < 0 && hci_cmd_handler(7u) != 1 && hci_cmd_handler(7u) && hci_cmd_handler(7u) != 3 )
    irq_disable_mmio_write((int)aKeStateGetTask_14, (int)aMeSetActiveCfm_0, 341);
  if ( hci_cmd_handler(7u) == 1 )
  {
    if ( **v0 < 0 && *((volatile uint32_t *)off_1362CC + 1) )
      irq_disable_mmio_write((int)aCoListIsEmptyA, (int)aMeSetActiveCfm_0, 349);
    send_hci_command();
  }
  else if ( hci_cmd_handler(7u) == 3 )
  {
    mac_write_header_word(7171, 13, 7);
    ke_state_set(7u, 0);
  }
  return 0;
}


// ble_encrypt_data @ 0x1362dc
int ble_encrypt_data(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r4

  check_feature_flag(256, aApStop);
  v7 = dword_136334 + 1320 * *a2;
  if ( *(volatile uint8_t *)(v7 + 106) == 2 && *(volatile uint8_t *)(v7 + 108) )
  {
    if ( hci_cmd_handler(7u) )
    {
      return 2;
    }
    else
    {
      send_ble_hci_command(v7);
      return 0;
    }
  }
  else
  {
    mac_write_header_word(7171, a4, a3);
    return 0;
  }
}


