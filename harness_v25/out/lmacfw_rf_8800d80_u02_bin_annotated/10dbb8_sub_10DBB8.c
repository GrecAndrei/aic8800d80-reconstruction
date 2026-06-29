// fwstruct annotate: 10dbb8_sub_10DBB8.c
// sub_10DBB8 @ 0x10dbb8, size 18 bytes
int __fastcall sub_10DBB8(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DBCC &= ~result;
  return result;
}

