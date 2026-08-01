// check_hw_state @ 0x121cbc, size 26 bytes
// Doc: check_hw_state [ipc]: unknown message dispatch
// check_hw_state [ipc]: unknown message dispatch
int check_hw_state()
{
  int result; // r0

  result = rx_rate_field_parse(0);
  if ( result == 4 )
    return rx_phy_status_parse(0);
  return result;
}

