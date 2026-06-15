// v23 annotated: sub_10DAF0 @ 0x10daf0
// Original: 10daf0_sub_10DAF0.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// sub_10DAF0 @ 0x10daf0, size 16 bytes
int __fastcall sub_10DAF0(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DB00 + 2);
  *((_DWORD *)off_10DB00 + 2) = result;
  return result;
}

