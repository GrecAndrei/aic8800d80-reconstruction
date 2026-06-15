// v23 annotated: phy_reg_mask_check @ 0x117e34
// Original: 117e34_phy_reg_mask_check.c
// Primary struct: <unclustered>
//
// phy_reg_mask_check @ 0x117e34, size 38 bytes
// Doc: phy_reg_mask_check [patch]: Check masked bits of PHY control register 0x40328078
// phy_reg_mask_check [patch]: Check masked bits of PHY control register 0x40328078
int phy_reg_mask_check()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(_DWORD *)off_117E5C & 0xF00000;
  if ( v0 )
  {
    result = sub_11B0B4((unsigned __int8)(11 - __clz(v0)));
    *(_DWORD *)off_117E60 = v0;
  }
  else
  {
    *(_DWORD *)off_117E60 = 0;
  }
  return result;
}

