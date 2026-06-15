// v23 annotated: sub_101904 @ 0x101904
// Original: 101904_sub_101904.c
// Primary struct: <unclustered>
//
// sub_101904 @ 0x101904, size 44 bytes
int __fastcall sub_101904(__int16 a1)
{
  int v1; // r4
  _DWORD *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101934;
  v2 = off_101938;
  v3 = (int *)off_10193C;
  result = a1 & 0x7FF;
  *(_DWORD *)off_101930 = *(_DWORD *)off_101930 & dword_101934 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

