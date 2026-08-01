// check_clock_state @ 0x121f1c, size 26 bytes
// Doc: check_clock_state [util]: Initialize subsystem and check return value equals 4
// check_clock_state [util]: Initialize subsystem and check return value equals 4
int check_clock_state()
{
  int result; // r0

  result = hci_cmd_send_short(0);
  if ( result == 4 )
    return hci_cmd_send(0);
  return result;
}

