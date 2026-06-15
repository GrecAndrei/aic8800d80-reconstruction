// v23 annotated: rf_calib_table_init @ 0x116c94
// Original: 116c94_rf_calib_table_init.c
// Primary struct: rf_calib_tbl (cluster 10, 5 funcs)
// Fields: base=0x0, idx=0xa, count=0xb
//
// rf_calib_table_init @ 0x116c94, size 14 bytes
// Doc: rf_calib_table_init [rf]: Initializes RF calibration table pointers
// rf_calib_table_init [rf]: Initializes RF calibration table pointers
int rf_calib_table_init()
{
  sub_117410();
  return rf_temp_sensor_read();
}

