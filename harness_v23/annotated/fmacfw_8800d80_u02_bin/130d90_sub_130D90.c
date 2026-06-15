// v23 annotated: sub_130D90 @ 0x130d90
// Original: 130d90_sub_130D90.c
// Primary struct: <unclustered>
//
// sub_130D90 @ 0x130d90, size 38 bytes
int __fastcall sub_130D90(int a1, int a2, __int16 a3)
{
  __int16 v3; // r3
  int v4; // r1
  __int16 v5; // r3

  *(_BYTE *)a1 = 3;
  *(_BYTE *)(a1 + 1) = 2;
  v3 = *(unsigned __int8 *)(a2 + 22);
  v4 = *(unsigned __int8 *)(a2 + 17);
  *(_WORD *)(a1 + 4) = a3;
  v5 = v3 << 12;
  if ( v4 == 1 )
    v5 |= 0x800u;
  *(_WORD *)(a1 + 2) = v5;
  return 6;
}

