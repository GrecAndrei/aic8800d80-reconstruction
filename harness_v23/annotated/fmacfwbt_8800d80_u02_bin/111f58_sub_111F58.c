// v23 annotated: sub_111F58 @ 0x111f58
// Original: 111f58_sub_111F58.c
// Primary struct: <unclustered>
//
// sub_111F58 @ 0x111f58, size 32 bytes
int __fastcall sub_111F58(int a1)
{
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(_DWORD *)(result + 2816);
  if ( v2 < 0 )
    *(_DWORD *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}

