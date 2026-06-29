// fwstruct annotate: 10db18_sub_10DB18.c
// sub_10DB18 @ 0x10db18, size 18 bytes
int __fastcall sub_10DB18(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DB2C &= ~result;
  return result;
}

