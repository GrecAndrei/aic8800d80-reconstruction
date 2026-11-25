// patch_check_loaded @ 0x1361fc
int patch_check_loaded(int a1) {
  int v2; // r0

  if ( **(volatile int16_t **)off_136230 >= 0 || (a1 = rx_rate_field_parse(7u), a1 == 3) )
  {
    bt_ready_check(a1);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_136238, dword_136234, 415);
    bt_ready_check(v2);
    return 0;
  }
}



// patch_set_enabled @ 0x13623c
int patch_set_enabled() {
  if ( **(volatile int16_t **)off_136284 < 0 && rx_rate_field_parse(7u) != 3 && rx_rate_field_parse(7u) )
    mmio_clear_register(dword_13628C, dword_136288, 442);
  if ( rx_rate_field_parse(7u) == 3 )
    bt_ready_check(3);
  return 0;
}



// bt_cmd_guard @ 0x136290
int bt_cmd_guard() {
  int v0; // r0

  if ( **(volatile int16_t **)off_1362EC < 0 && rx_rate_field_parse(7u) != 1 && rx_rate_field_parse(7u) && rx_rate_field_parse(7u) != 3 )
    mmio_clear_register(dword_1362F4, dword_1362F0, 274);
  v0 = rx_rate_field_parse(7u);
  if ( v0 != 1 )
  {
    v0 = rx_rate_field_parse(7u);
    if ( v0 != 3 )
      return 0;
  }
  bt_ready_check(v0);
  return 0;
}



// bt_hci_reset @ 0x1362f8
int bt_hci_reset(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_13632C >= 0 || (value = rx_rate_field_parse(7u), value == 1) )
  {
    bt_ready_check(value);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_136334, dword_136330, 311);
    bt_ready_check(v2);
    return 0;
  }
}



// bt_vendor_cmd_guard @ 0x136338
int bt_vendor_cmd_guard() {
  if ( **(volatile int16_t **)off_136370 >= 0 || rx_rate_field_parse(7u) == 2 )
  {
    bt_vendor_send(0);
    return 0;
  }
  else
  {
    mmio_clear_register(dword_136378, dword_136374, 388);
    bt_vendor_send(0);
    return 0;
  }
}



// bt_cmd_guard_alt @ 0x13637c
int bt_cmd_guard_alt() {
  volatile int16_t **v0; // r4

  v0 = (volatile int16_t **)off_136408;
  if ( **(volatile int16_t **)off_136408 < 0 && rx_rate_field_parse(7u) != 1 && rx_rate_field_parse(7u) && rx_rate_field_parse(7u) != 3 )
    mmio_clear_register((int)aKeStateGetTask_14, (int)aMeSetActiveCfm_0, 341);
  if ( rx_rate_field_parse(7u) == 1 )
  {
    if ( **v0 < 0 && *((volatile uint32_t *)off_13640C + 1) )
      mmio_clear_register((int)aCoListIsEmptyA, (int)aMeSetActiveCfm_0, 349);
    ke_send_event_0x3f();
  }
  else if ( rx_rate_field_parse(7u) == 3 )
  {
    ke_msg_send_no_param(7171, 13, 7);
    ke_state_set(7u, 0);
  }
  return 0;
}


// bt_read_version @ 0x13641c
int bt_read_version(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r4

  check_status_bits(256, aApStop);
  v7 = dword_136474 + 1320 * *a2;
  if ( *(volatile uint8_t *)(v7 + 106) == 2 && *(volatile uint8_t *)(v7 + 108) )
  {
    if ( rx_rate_field_parse(7u) )
    {
      return 2;
    }
    else
    {
      rf_send_command_0x1419(v7);
      return 0;
    }
  }
  else
  {
    ke_msg_send_no_param(7171, a4, a3);
    return 0;
  }
}


