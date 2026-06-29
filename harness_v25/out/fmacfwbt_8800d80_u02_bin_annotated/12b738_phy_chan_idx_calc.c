// fwstruct annotate: 12b738_phy_chan_idx_calc.c
// phy_chan_idx_calc @ 0x12b738, size 16 bytes
// Doc: phy_chan_idx_calc [rf]: compute channel index/offset from PHY state struct
// phy_chan_idx_calc [rf]: compute channel index/offset from PHY state struct
int phy_chan_idx_calc()
{
  return *(_DWORD *)off_12B748 + 6 * *((unsigned __int8 *)off_12B748 + 10);
}

