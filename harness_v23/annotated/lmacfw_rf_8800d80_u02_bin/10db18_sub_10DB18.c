// v23 annotated: sub_10DB18 @ 0x10db18
// Original: 10db18_sub_10DB18.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// sub_10DB18 @ 0x10db18, size 18 bytes
int __fastcall sub_10DB18(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DB2C &= ~result;
  return result;
}

