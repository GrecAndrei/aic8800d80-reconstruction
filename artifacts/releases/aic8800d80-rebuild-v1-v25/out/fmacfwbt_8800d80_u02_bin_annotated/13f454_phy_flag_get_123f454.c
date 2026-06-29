// fwstruct annotate: 13f454_phy_flag_get_123f454.c
// phy_flag_get_123f454 @ 0x13f454, size 44 bytes
// Doc: phy_flag_get_123f454 [mac]: Get PHY capability flag from offset 0x15c, branch on mode
// phy_flag_get_123f454 [mac]: Get PHY capability flag from offset 0x15c, branch on mode
int __fastcall phy_flag_get_123f454(int result, unsigned int a2)
{
  int v2; // r2
  _DWORD *v3; // r4
  int v4; // r3

  if ( a2 > 3 )
    v2 = 0;
  else
    v2 = *(_WORD *)(result + 348) & 0x400;
  v3 = *(_DWORD **)(result + 336);
  v4 = v2 | a2 | 0x20000000;
  v3[5] = v4;
  v3[6] = v4;
  v3[7] = v4;
  v3[8] = v4;
  return result;
}

