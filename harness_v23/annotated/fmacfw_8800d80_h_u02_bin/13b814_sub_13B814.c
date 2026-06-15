// v23 annotated: sub_13B814 @ 0x13b814
// Original: 13b814_sub_13B814.c
// Primary struct: <unclustered>
//
// sub_13B814 @ 0x13b814, size 24 bytes
int __fastcall sub_13B814(int a1, __int16 a2, char a3)
{
  int result; // r0

  result = (*(int (__fastcall **)(int, int))a1)(a1, (a2 - *(_WORD *)(a1 + 4)) & 0xFFF) + a1;
  *(_BYTE *)(result + 6) = a3;
  return result;
}

