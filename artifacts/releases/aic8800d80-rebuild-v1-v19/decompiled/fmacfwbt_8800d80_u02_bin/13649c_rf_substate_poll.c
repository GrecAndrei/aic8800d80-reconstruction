// rf_substate_poll @ 0x13649c, size 90 bytes
// Doc: rf_substate_poll [rf]: Poll signed halfword RF sub-state and branch
// rf_substate_poll [rf]: Poll signed halfword RF sub-state and branch
int rf_substate_poll()
{
  int value; // r0

  if ( **(__int16 **)off_1364F8 < 0 && msg_get_value(7u) != 1 && msg_get_value(7u) && msg_get_value(7u) != 3 )
    sub_12F694(dword_136500, dword_1364FC, 274);
  value = msg_get_value(7u);
  if ( value != 1 )
  {
    value = msg_get_value(7u);
    if ( value != 3 )
      return 0;
  }
  sub_13697C(value);
  return 0;
}

