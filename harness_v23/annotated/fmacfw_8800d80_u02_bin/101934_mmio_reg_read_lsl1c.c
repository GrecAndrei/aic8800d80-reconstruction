// v23 annotated: mmio_reg_read_lsl1c @ 0x101934
// Original: 101934_mmio_reg_read_lsl1c.c
// Primary struct: <unclustered>
//
// mmio_reg_read_lsl1c @ 0x101934, size 24 bytes
// Doc: mmio_reg_read_lsl1c [util]: Reads MMIO register and applies left-shift by 0x1c on value
// mmio_reg_read_lsl1c [util]: Reads MMIO register and applies left-shift by 0x1c on value
int __fastcall mmio_reg_read_lsl1c(int result, int a2, int a3)
{
  if ( (*(_DWORD *)off_10194C & 8) != 0 )
  {
    result = sub_11ED58(result, a2, a3, *(_DWORD *)off_10194C << 28);
    *(_DWORD *)off_101950 = 8;
  }
  return result;
}

