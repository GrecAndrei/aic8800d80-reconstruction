// v23 annotated: sub_101A78 @ 0x101a78
// Original: 101a78_sub_101A78.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101A78 @ 0x101a78, size 10 bytes
int sub_101A78()
{
  return (*(_DWORD *)off_101A84 >> 30) & 1;
}

