// v23 annotated: sub_13AFC0 @ 0x13afc0
// Original: 13afc0_sub_13AFC0.c
// Primary struct: <unclustered>
//
// sub_13AFC0 @ 0x13afc0, size 24 bytes
int __fastcall sub_13AFC0(int a1, int a2)
{
  __int16 v2; // r2

  v2 = *(_WORD *)(a1 + 30) | 1;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_WORD *)(a1 + 30) = v2;
  return sub_13AC44(a1, a2);
}

