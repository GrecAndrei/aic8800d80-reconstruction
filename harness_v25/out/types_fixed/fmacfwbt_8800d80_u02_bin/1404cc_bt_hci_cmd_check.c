// bt_hci_cmd_check @ 0x1404cc, size 50 bytes
// Doc: bt_hci_cmd_check [bt]: Check/issue HCI command with id 0xb and verify result
// bt_hci_cmd_check [bt]: Check/issue HCI command with id 0xb and verify result
int bt_hci_cmd_check()
{
  if ( msg_get_value(0xBu) == 1 )
  {
    sub_141688();
    return 0;
  }
  else
  {
    if ( **(__int16 **)off_140500 < 0 )
      sub_12F6C4(dword_140508, dword_140504, 157);
    return 0;
  }
}

