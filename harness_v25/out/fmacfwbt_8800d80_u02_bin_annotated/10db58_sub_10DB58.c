// fwstruct annotate: 10db58_sub_10DB58.c
// sub_10DB58 @ 0x10db58, size 16 bytes
int __fastcall sub_10DB58(char a1)
{
  int result; // r0

  result = (1 << a1) | *(_DWORD *)off_10DB68;
  *(_DWORD *)off_10DB68 = result;
  return result;
}

