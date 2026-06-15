// v23 annotated: sub_13B9F0 @ 0x13b9f0
// Original: 13b9f0_sub_13B9F0.c
// Primary struct: <unclustered>
//
// sub_13B9F0 @ 0x13b9f0, size 24 bytes
int __fastcall sub_13B9F0(int a1, __int16 a2, char a3)
{
  int result; // r0

  result = (*(int (__fastcall **)(int, int))a1)(a1, (a2 - *(_WORD *)(a1 + 4)) & 0xFFF) + a1;
  *(_BYTE *)(result + 6) = a3;
  return result;
}

