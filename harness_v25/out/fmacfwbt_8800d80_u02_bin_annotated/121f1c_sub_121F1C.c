// fwstruct annotate: 121f1c_sub_121F1C.c
// sub_121F1C @ 0x121f1c, size 26 bytes
// Doc: sub_1221F1C [util]: Initialize subsystem and check return value equals 4
// sub_1221F1C [util]: Initialize subsystem and check return value equals 4
int sub_121F1C()
{
  int result; // r0

  result = msg_get_value(0);
  if ( result == 4 )
    return rf_bus_mark_n_3b7(0);
  return result;
}

