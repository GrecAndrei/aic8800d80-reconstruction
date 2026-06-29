// fwstruct annotate: 1120fc_sub_1120FC.c
// sub_1120FC @ 0x1120fc, size 32 bytes
int __fastcall sub_1120FC(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

