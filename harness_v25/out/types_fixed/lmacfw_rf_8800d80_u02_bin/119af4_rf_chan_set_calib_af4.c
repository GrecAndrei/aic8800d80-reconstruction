// rf_chan_set_calib_af4 @ 0x119af4, size 54 bytes
// Doc: rf_chan_set_calib_af4 [rf]: Sets RF channel with calibration, dispatches via callback
// rf_chan_set_calib_af4 [rf]: Sets RF channel with calibration, dispatches via callback
int __fastcall rf_chan_set_calib_af4(int a1, _BYTE *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  _BYTE *v10; // r0

  v7 = sub_11BBA4(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (_BYTE *)rf_setup_dispatch(71, a4, a3, 3);
    *v10 = *a2;
    *(_DWORD *)(v10 + 0x4) = v9;
    *(_DWORD *)(v10 + 0x8) = 4;
    sub_11DE50(v10);
  }
  return 0;
}

