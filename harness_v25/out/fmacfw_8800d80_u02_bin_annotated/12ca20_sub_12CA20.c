// fwstruct annotate: 12ca20_sub_12CA20.c
// sub_12CA20 @ 0x12ca20, size 22 bytes
int __fastcall sub_12CA20(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(_WORD *)(a1 - 8) = a2;
  *(_WORD *)(a1 - 6) = a3;
  *(_WORD *)(a1 - 4) = a4;
  return sub_12C98C(a1);
}

