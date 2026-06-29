// fwstruct annotate: 10dad8_sub_10DAD8.c
// sub_10DAD8 @ 0x10dad8, size 18 bytes
int __fastcall sub_10DAD8(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((_DWORD *)off_10DAEC + 2) &= ~result;
  return result;
}

