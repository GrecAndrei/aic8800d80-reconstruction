// rf_chan_mask_get @ 0x102b60, size 26 bytes
// Doc: rf_chan_mask_get [mmio]: Read RF channel count from MMIO and build 1<<n mask
// rf_chan_mask_get [mmio]: Read RF channel count from MMIO and build 1<<n mask
int rf_chan_mask_get()
{
  return (unsigned __int8)((1 << ((unsigned __int8)*(_DWORD *)off_102B7C >> 4)) - 1);
}

