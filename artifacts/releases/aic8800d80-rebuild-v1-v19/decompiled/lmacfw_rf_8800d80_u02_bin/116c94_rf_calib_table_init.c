// rf_calib_table_init @ 0x116c94, size 14 bytes
// Doc: rf_calib_table_init [rf]: Initializes RF calibration table pointers
// rf_calib_table_init [rf]: Initializes RF calibration table pointers
int rf_calib_table_init()
{
  sub_117410();
  return rf_temp_sensor_read();
}

