// fwstruct annotate: 11facc_bt_fmac_phy_config.c
// bt_fmac_phy_config @ 0x11facc, size 38 bytes
// Doc: bt_fmac_phy_config [bt]: Configures Bluetooth PHY parameters via FMAC
// bt_fmac_phy_config [bt]: Configures Bluetooth PHY parameters via FMAC
int bt_fmac_phy_config()
{
  _DWORD *i; // r5
  _DWORD *j; // r4
  int result; // r0

  for ( i = *((_DWORD **)off_11FAF4 + 2); i; i = (_DWORD *)*i )
  {
    for ( j = (_DWORD *)i[60]; j; j = (_DWORD *)*j )
      result = sub_11F704((int)i, (int)j, 0);
  }
  return result;
}

