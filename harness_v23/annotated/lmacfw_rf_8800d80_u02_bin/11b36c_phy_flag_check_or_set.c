// v23 annotated: phy_flag_check_or_set @ 0x11b36c
// Original: 11b36c_phy_flag_check_or_set.c
// Primary struct: <unclustered>
//
// phy_flag_check_or_set @ 0x11b36c, size 48 bytes
// Doc: phy_flag_check_or_set [rx]: Check/set a packed PHY status flag bit
// phy_flag_check_or_set [rx]: Check/set a packed PHY status flag bit
int phy_flag_check_or_set()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_11B39C;
  if ( (*((_BYTE *)off_11B39C + 88) & 0x10) == 0 )
  {
    v1 = *((unsigned __int8 *)off_11B39C + 90);
    *((_BYTE *)off_11B39C + 88) |= 0x10u;
    if ( v1 )
      return sub_11AB18((int)v0 + 48, *((_DWORD *)off_11B3A0 + 4) + 30000);
    else
      return sub_11B2C8();
  }
  return result;
}

