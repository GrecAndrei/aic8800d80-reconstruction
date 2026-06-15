// v23 annotated: sub_1044D0 @ 0x1044d0
// Original: 1044d0_sub_1044D0.c
// Primary struct: <unclustered>
//
// sub_1044D0 @ 0x1044d0, size 48 bytes
int __fastcall sub_1044D0(int a1, int a2, _DWORD *a3)
{
  int v3; // r2
  unsigned int v4; // r0
  int v5; // r3

  v3 = a3[sub_104274(a1, a2, a3)];
  v4 = (unsigned int)v3 >> 20;
  v5 = (unsigned __int16)v3 >> 4;
  if ( v3 < 0 )
    v4 -= 4096;
  if ( (((unsigned int)v3 >> 4) & 0x800) != 0 )
    v5 -= 4096;
  return v5 * v5 + v4 * v4;
}

