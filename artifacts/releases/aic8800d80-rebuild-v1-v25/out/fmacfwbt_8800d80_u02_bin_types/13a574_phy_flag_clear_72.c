// phy_flag_clear_72 @ 0x13a574, size 14 bytes
// Doc: phy_flag_clear_72 [mac]: Clear 16-bit flag at offset 0x72 in PHY struct
// phy_flag_clear_72 [mac]: Clear 16-bit flag at offset 0x72 in PHY struct
int phy_flag_clear_72()
{
  int result; // r0

  result = *((unsigned __int8 *)off_13A584 + 114);
  *((uint16_t *)off_13A584 + 57) = 0;
  return result;
}

