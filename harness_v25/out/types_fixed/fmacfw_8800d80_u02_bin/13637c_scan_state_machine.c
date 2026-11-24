// scan_state_machine @ 0x13637c, size 140 bytes
// Doc: scan_state_machine [scan]: Scanning state machine handler
// scan_state_machine [scan]: Scanning state machine handler
int scan_state_machine()
{
  __int16 **v0; // r4

  v0 = (__int16 **)off_136408;
  if ( **(__int16 **)off_136408 < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F46C(dword_136418, dword_136410, 341);
  if ( msg_get_value(7u) == 1 )
  {
    if ( **v0 < 0 && *((_DWORD *)off_13640C + 1) )
      sub_12F46C(dword_136414, dword_136410, 349);
    sub_13698C();
  }
  else if ( msg_get_value(7u) == 3 )
  {
    sub_12CA10(7171, 13, 7);
    sub_12CD34(7u, 0);
  }
  return 0;
}

