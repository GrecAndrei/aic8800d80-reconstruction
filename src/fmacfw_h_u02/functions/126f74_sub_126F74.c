// bt_event_handler @ 0x126f74, size 22 bytes
int bt_event_handler()
{
  int v0; // r0
  int result; // r0

  v0 = ke_evt_handler();
  result = llc_rx_complete(v0);
  if ( !result )
    return llc_flag_test_bit3();
  return result;
}

