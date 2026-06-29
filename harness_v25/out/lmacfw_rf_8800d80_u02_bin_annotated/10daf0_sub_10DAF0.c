// fwstruct annotate: 10daf0_sub_10DAF0.c
// sub_10DAF0 @ 0x10daf0, size 16 bytes
int __fastcall sub_10DAF0(char a1)
{
  int result; // r0

  result = (1 << a1) | *((_DWORD *)off_10DB00 + 2);
  *((_DWORD *)off_10DB00 + 2) = result;
  return result;
}

