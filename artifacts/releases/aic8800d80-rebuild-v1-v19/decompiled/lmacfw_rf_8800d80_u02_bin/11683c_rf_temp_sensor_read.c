// rf_temp_sensor_read @ 0x11683c, size 24 bytes
// Doc: rf_temp_sensor_read [rf]: Read RF temperature sensor value
// rf_temp_sensor_read [rf]: Read RF temperature sensor value
int rf_temp_sensor_read()
{
  _BYTE *v0; // r4
  int v1; // r0
  int result; // r0

  v0 = off_116854;
  v1 = sub_11E71C(off_116854);
  result = (unsigned __int8)(sub_121A60(v1) - 1);
  v0[11] = result;
  v0[10] = result;
  return result;
}

