// check_state_flag @ 0x133960
int check_state_flag() {
  int value; // r0

  if ( **(volatile int16_t **)off_1339BC < 0 && rx_rate_field_parse(6u) != 4 && rx_rate_field_parse(6u) && rx_rate_field_parse(6u) != 10 )
    mmio_clear_register(dword_1339C4, dword_1339C0, 636);
  value = rx_rate_field_parse(6u);
  if ( value != 4 )
  {
    value = rx_rate_field_parse(6u);
    if ( value != 10 )
      return 0;
  }
  bt_is_controller_ready(value);
  return 0;
}



// check_state_and_call @ 0x1339c8
int check_state_and_call(int value) {
  int v2; // r0

  if ( **(volatile int16_t **)off_1339FC >= 0 || (value = rx_rate_field_parse(6u), value == 4) )
  {
    bt_is_controller_ready(value);
    return 0;
  }
  else
  {
    v2 = mmio_clear_register(dword_133A04, dword_133A00, 670);
    bt_is_controller_ready(v2);
    return 0;
  }
}



// handle_state_five @ 0x133a08
int handle_state_five() {
  if ( rx_rate_field_parse(6u) != 5 && rx_rate_field_parse(6u) != 6 && rx_rate_field_parse(6u) != 7 && rx_rate_field_parse(6u) != 8 )
    return 0;
  if ( *((volatile uint8_t *)off_133A50 + 34) )
  {
    *((volatile uint8_t *)off_133A50 + 34) = 0;
    return 0;
  }
  bt_setup_conn_profile(1);
  return 0;
}



