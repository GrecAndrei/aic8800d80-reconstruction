// v23 annotated: sub_10DD00 @ 0x10dd00
// Original: 10dd00_sub_10DD00.c
// Primary struct: group_15 (cluster 15)
//
// sub_10DD00 @ 0x10dd00, size 16 bytes
int __fastcall sub_10DD00(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DD10;
  *(_DWORD *)off_10DD10 = result;
  return result;
}

