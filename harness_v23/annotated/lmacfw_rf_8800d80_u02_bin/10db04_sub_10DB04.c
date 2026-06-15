// v23 annotated: sub_10DB04 @ 0x10db04
// Original: 10db04_sub_10DB04.c
// Primary struct: bitmask_state (cluster 5, 7 funcs)
// Fields: prev_base=0x-c, mask0=0x0, mask1=0x4, mask2=0x8
//
// sub_10DB04 @ 0x10db04, size 16 bytes
// Doc: sub_120DB04 [rf]: Unknown LMAC RF helper function
// sub_120DB04 [rf]: Unknown LMAC RF helper function
int __fastcall sub_10DB04(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DB14;
  *(_DWORD *)off_10DB14 = result;
  return result;
}

