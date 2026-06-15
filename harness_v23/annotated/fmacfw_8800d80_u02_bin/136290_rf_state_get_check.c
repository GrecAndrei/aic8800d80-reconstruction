// v23 annotated: rf_state_get_check @ 0x136290
// Original: 136290_rf_state_get_check.c
// Primary struct: <unclustered>
//
// rf_state_get_check @ 0x136290, size 90 bytes
// Doc: rf_state_get_check [rf]: Read shared RF state word and branch on sign
// rf_state_get_check [rf]: Read shared RF state word and branch on sign
int rf_state_get_check()
{
  int value; // r0

  if ( **(__int16 **)off_1362EC < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F46C(dword_1362F4, dword_1362F0, 274);
  value = msg_get_value(7u);
  if ( value != 1 )
  {
    value = msg_get_value(7u);
    if ( value != 3 )
      return 0;
  }
  sub_136820(value);
  return 0;
}

