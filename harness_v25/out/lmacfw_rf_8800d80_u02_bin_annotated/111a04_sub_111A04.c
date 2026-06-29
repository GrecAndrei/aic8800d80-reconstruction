// fwstruct annotate: 111a04_sub_111A04.c
// sub_111A04 @ 0x111a04, size 32 bytes
int __fastcall sub_111A04(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

