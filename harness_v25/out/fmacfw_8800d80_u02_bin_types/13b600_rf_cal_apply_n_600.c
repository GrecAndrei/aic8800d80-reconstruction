// rf_cal_apply_n_600 @ 0x13b600, size 42 bytes
// Doc: rf_cal_apply_n_600 [rf]: Applies RF calibration parameter via helper call
// rf_cal_apply_n_600 [rf]: Applies RF calibration parameter via helper call
int  rf_cal_apply_n_600(int a1, int a2, unsigned int a3)
{
  int v4; // r0

  if ( msg_get_value(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B634;
    else
      v4 = dword_13B630;
    list_push_tail(v4, (uint32_t *)(dword_13B62C + 32 * (a3 >> 8)));
  }
  return 0;
}

