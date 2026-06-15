// v23 annotated: sub_101A50 @ 0x101a50
// Original: 101a50_sub_101A50.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101A50 @ 0x101a50, size 20 bytes
unsigned int __fastcall sub_101A50(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_101A64 & 0xFFFFFFF7;
  *(_DWORD *)off_101A64 = result;
  return result;
}

