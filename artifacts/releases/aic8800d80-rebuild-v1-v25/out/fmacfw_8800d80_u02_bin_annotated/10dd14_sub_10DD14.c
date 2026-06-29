// fwstruct annotate: 10dd14_sub_10DD14.c
// sub_10DD14 @ 0x10dd14, size 18 bytes
int __fastcall sub_10DD14(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(_DWORD *)off_10DD28 &= ~result;
  return result;
}

