// fwstruct annotate: 120568_mmio_reg_write_helper.c
// mmio_reg_write_helper @ 0x120568, size 16 bytes
// Doc: mmio_reg_write_helper [mmio]: Writes to MMIO register window at 0x40501000 with computed offset and value
// mmio_reg_write_helper [mmio]: Writes to MMIO register window at 0x40501000 with computed offset and value
int __fastcall mmio_reg_write_helper(int a1)
{
  return timestamp_update_4f60(a1 + 48, *((_DWORD *)off_120578 + 4) + 10000);
}

