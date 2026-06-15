// v23 annotated: sub_130F30 @ 0x130f30
// Original: 130f30_sub_130F30.c
// Primary struct: <unclustered>
//
// sub_130F30 @ 0x130f30, size 54 bytes
int __fastcall sub_130F30(int a1, int a2)
{
  __int16 v2; // r3
  __int16 v3; // r4
  __int16 v4; // r2

  *(_BYTE *)a1 = 3;
  *(_BYTE *)(a1 + 1) = 0;
  *(_BYTE *)(a1 + 2) = *(_BYTE *)(a2 + 23);
  v2 = *(unsigned __int8 *)(a2 + 22);
  v3 = *(unsigned __int8 *)(a2 + 18);
  v4 = *(_WORD *)(a2 + 20);
  *(_WORD *)(a1 + 5) = *(_WORD *)(a2 + 14);
  *(_WORD *)(a1 + 3) = (4 * v2) | (2 * v3) | (v4 << 6);
  *(_WORD *)(a1 + 7) = 16 * *(_WORD *)(a2 + 12);
  return 9;
}

