// rf_chan_set_calib_af4 @ 0x119af4, size 54 bytes
// Doc: rf_chan_set_calib_af4 [rf]: Sets RF channel with calibration, dispatches via callback
// rf_chan_set_calib_af4 [rf]: Sets RF channel with calibration, dispatches via callback
int  rf_chan_set_calib_af4(int a1, uint8_t *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  uint8_t *v10; // r0

  v7 = sub_11BBA4(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (uint8_t *)rf_setup_dispatch(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    sub_11DE50(v10);
  }
  return 0;
}

