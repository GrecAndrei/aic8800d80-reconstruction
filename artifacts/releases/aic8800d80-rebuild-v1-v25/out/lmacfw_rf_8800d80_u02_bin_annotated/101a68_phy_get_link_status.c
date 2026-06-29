// fwstruct annotate: 101a68_phy_get_link_status.c
// phy_get_link_status @ 0x101a68, size 10 bytes
// Doc: phy_get_link_status [mac]: Read PHY status bit 28 from 0x40330000 register
// phy_get_link_status [mac]: Read PHY status bit 28 from 0x40330000 register
int phy_get_link_status()
{
  return (*(_DWORD *)off_101A74 >> 28) & 1;
}

