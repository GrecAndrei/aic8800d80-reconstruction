// fwstruct annotate: 133afc_chip_feature_check_3afc.c
// chip_feature_check_3afc @ 0x133afc, size 52 bytes
// Doc: chip_feature_check_3afc [util]: Read global config word and test signed halfword flag
// chip_feature_check_3afc [util]: Read global config word and test signed halfword flag
int __fastcall chip_feature_check_3afc(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_133B30 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1349D8(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133B38, dword_133B34, 898);
    sub_1349D8(v2);
    return 0;
  }
}

