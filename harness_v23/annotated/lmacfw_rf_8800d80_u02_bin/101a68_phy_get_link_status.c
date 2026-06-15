// v23 annotated: phy_get_link_status @ 0x101a68
// Original: 101a68_phy_get_link_status.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// phy_get_link_status @ 0x101a68, size 10 bytes
// Doc: phy_get_link_status [mac]: Read PHY status bit 28 from 0x40330000 register
// phy_get_link_status [mac]: Read PHY status bit 28 from 0x40330000 register
int phy_get_link_status()
{
  return (*(_DWORD *)off_101A74 >> 28) & 1;
}

