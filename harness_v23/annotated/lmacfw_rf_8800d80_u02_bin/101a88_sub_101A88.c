// v23 annotated: sub_101A88 @ 0x101a88
// Original: 101a88_sub_101A88.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101A88 @ 0x101a88, size 14 bytes
int sub_101A88()
{
  return (unsigned __int8)((BYTE1(*(_DWORD *)off_101A98) & 0xF) - 1);
}

