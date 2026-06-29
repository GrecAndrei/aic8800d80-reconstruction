// fwstruct annotate: 10db44_sub_10DB44.c
// sub_10DB44 @ 0x10db44, size 16 bytes
int __fastcall sub_10DB44(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DB54 + 2);
  *((_DWORD *)off_10DB54 + 2) = result;
  return result;
}

