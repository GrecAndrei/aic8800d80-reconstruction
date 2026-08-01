// check_config_flag @ 0x121b7c, size 26 bytes
int check_config_flag()
{
  int result; // r0

  result = hci_cmd_handler(0);
  if ( result == 4 )
    return hci_cmd_preprocess(0);
  return result;
}

