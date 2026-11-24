// sub_133960 @ 0x133960, size 90 bytes
int sub_133960()
{
  int value; // r0

  if ( **(__int16 **)off_1339BC < 0 && msg_get_value(6u) != 4 && msg_get_value(6u) && msg_get_value(6u) != 10 )
    sub_12F46C(dword_1339C4, dword_1339C0, 636);
  value = msg_get_value(6u);
  if ( value != 4 )
  {
    value = msg_get_value(6u);
    if ( value != 10 )
      return 0;
  }
  sub_1347BC(value);
  return 0;
}

