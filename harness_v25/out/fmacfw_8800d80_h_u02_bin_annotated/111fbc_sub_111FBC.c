// fwstruct annotate: 111fbc_sub_111FBC.c
// sub_111FBC @ 0x111fbc, size 32 bytes
int __fastcall sub_111FBC(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

