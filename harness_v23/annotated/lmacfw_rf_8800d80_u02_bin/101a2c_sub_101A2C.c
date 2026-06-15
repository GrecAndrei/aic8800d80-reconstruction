// v23 annotated: sub_101A2C @ 0x101a2c
// Original: 101a2c_sub_101A2C.c
// Primary struct: mmio_clock_gate (cluster 3, 10 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_101A2C @ 0x101a2c, size 10 bytes
int sub_101A2C()
{
  return (*(_DWORD *)off_101A38 >> 21) & 1;
}

