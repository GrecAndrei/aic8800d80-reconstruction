// fwstruct annotate: 120720_mac_phy_init.c
// mac_phy_init @ 0x120720, size 88 bytes
// Doc: mac_phy_init [mac]: Initialize MAC/PHY from config table at 0x182b64
// mac_phy_init [mac]: Initialize MAC/PHY from config table at 0x182b64
_DWORD *mac_phy_init()
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

  v0 = off_120778;
  if ( !*((_BYTE *)off_120778 + 2) )
    mmio_set_flag_122b8bc();
  sub_120548();
  ipc_init_n724();
  v1 = sub_11EDF0();
  inited = rf_channel_seq_init_ae40(v1);
  v3 = key_mfp_table_init(inited);
  sub_129F44(v3);
  v4 = mac_post_patch_init();
  if ( v0[2] )
    v5 = nullsub_4(v4);
  else
    v5 = fm_module_init();
  v6 = sub_124D30(v5);
  v7 = sub_12B170(v6);
  v8 = init_data_table_n1c(v7);
  v9 = sub_12C33C(v8);
  sub_125734(v9);
  sub_10F25C();
  return wifi_mac_init_n_05bc();
}

