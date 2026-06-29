// fw_feature_check_n370 @ 0x133b3c, size 52 bytes
// Doc: fw_feature_check_n370 [util]: Check firmware feature/flag word at shared address
// fw_feature_check_n370 [util]: Check firmware feature/flag word at shared address
int  fw_feature_check_n370(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_133B70 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1349D8(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133B78, dword_133B74, 871);
    sub_1349D8(v2);
    return 0;
  }
}

