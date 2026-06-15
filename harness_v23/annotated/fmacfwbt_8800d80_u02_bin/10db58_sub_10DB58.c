// v23 annotated: sub_10DB58 @ 0x10db58
// Original: 10db58_sub_10DB58.c
// Primary struct: <unclustered>
//
// sub_10DB58 @ 0x10db58, size 16 bytes
int __fastcall sub_10DB58(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DB68;
  *(_DWORD *)off_10DB68 = result;
  return result;
}

