// sub_120A58 @ 0x120a58, size 88 bytes
_DWORD *sub_120A58()
{
  _BYTE *v0; // r4
  int *v1; // r0
  int inited; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = off_120AB0;
  if ( !*((_BYTE *)off_120AB0 + 2) )
    sub_12BAE4();
  sub_120880();
  sub_11FA5C();
  v1 = sub_11F16C();
  inited = bt_chan_init_all(v1);
  v3 = mm_state_init_check(inited);
  sub_12A168(v3);
  v4 = sub_1172BC();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = sub_11DC3C();
  v6 = sub_124F54(v5);
  v7 = sub_12B394(v6);
  v8 = bt_hci_reset_init(v7);
  v9 = rf_bus_setup_n_39c(v8);
  sub_125958(v9);
  util_sub_f0b4();
  return sub_1208F4();
}

