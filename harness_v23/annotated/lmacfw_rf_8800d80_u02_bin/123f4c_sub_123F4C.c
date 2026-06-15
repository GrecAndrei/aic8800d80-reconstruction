// v23 annotated: sub_123F4C @ 0x123f4c
// Original: 123f4c_sub_123F4C.c
// Primary struct: mmio_clock_gate (cluster 1, 25 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_123F4C @ 0x123f4c, size 18 bytes
int __fastcall sub_123F4C(unsigned int a1)
{
  if ( a1 <= 0x17 )
    return 1;
  *(_DWORD *)dword_123F60 = a1;
  return 0;
}

