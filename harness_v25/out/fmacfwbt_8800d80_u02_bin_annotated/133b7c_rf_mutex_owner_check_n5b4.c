// fwstruct annotate: 133b7c_rf_mutex_owner_check_n5b4.c
// rf_mutex_owner_check_n5b4 @ 0x133b7c, size 90 bytes
// Doc: rf_mutex_owner_check_n5b4 [rf]: Check current mutex/bus owner field before access
// rf_mutex_owner_check_n5b4 [rf]: Check current mutex/bus owner field before access
int rf_mutex_owner_check_n5b4()
{
  int value; // r0

  if ( **(__int16 **)off_133BD8 < 0 && msg_get_value(6u) != 4 && msg_get_value(6u) && msg_get_value(6u) != 10 )
    sub_12F694(dword_133BE0, dword_133BDC, 636);
  value = msg_get_value(6u);
  if ( value != 4 )
  {
    value = msg_get_value(6u);
    if ( value != 10 )
      return 0;
  }
  sub_1349D8(value);
  return 0;
}

