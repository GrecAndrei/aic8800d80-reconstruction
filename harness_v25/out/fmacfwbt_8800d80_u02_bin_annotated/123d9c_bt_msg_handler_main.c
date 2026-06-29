// fwstruct annotate: 123d9c_bt_msg_handler_main.c
// bt_msg_handler_main @ 0x123d9c, size 118 bytes
// Doc: bt_msg_handler_main [bt]: BT main message handler dispatch entry; checks a global flag and forwards args
// bt_msg_handler_main [bt]: BT main message handler dispatch entry; checks a global flag and forwards args
int __fastcall bt_msg_handler_main(int a1, void (__fastcall **a2)(int), int a3)
{
  __int16 **v3; // r5
  int result; // r0
  int v7; // r0

  v3 = (__int16 **)off_123E14;
  if ( **(__int16 **)off_123E14 < 0 && msg_get_value(a3) == 4 )
    sub_12F694(dword_123E1C, dword_123E18, 1587);
  result = msg_get_value(a3);
  if ( result )
  {
    if ( result != 2 )
    {
      sub_12BA2C(result);
      rf_bus_mark_n_3b7(a3);
      return 2;
    }
  }
  else
  {
    if ( **v3 < 0 && *(_DWORD *)off_123E20 << 28 )
      sub_12F694(dword_123E24, dword_123E18, 1594);
    v7 = rf_bus_mark_n_3b7(a3);
    (*a2)(v7);
    return 0;
  }
  return result;
}

