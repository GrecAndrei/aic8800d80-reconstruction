// v23 annotated: sub_102984 @ 0x102984
// Original: 102984_sub_102984.c
// Primary struct: mmio_clock_gate (cluster 1, 23 funcs)
// Fields: reg_addr=0x0, bit_idx=0x0, mask=0x18, value=0x1c
//
// sub_102984 @ 0x102984, size 62 bytes
int __fastcall sub_102984(unsigned int a1)
{
  if ( a1 > 0x1666 )
    return 5;
  if ( a1 > 0x1616 )
    return 4;
  if ( a1 > 0x15C6 )
    return 3;
  if ( a1 > 0x1571 )
    return 2;
  return a1 > 0x1486;
}

