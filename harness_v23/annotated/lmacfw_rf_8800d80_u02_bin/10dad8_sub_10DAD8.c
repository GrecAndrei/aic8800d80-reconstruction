// v23 annotated: sub_10DAD8 @ 0x10dad8
// Original: 10dad8_sub_10DAD8.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// sub_10DAD8 @ 0x10dad8, size 18 bytes
int __fastcall sub_10DAD8(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DAEC + 2) &= ~result;
  return result;
}

