// v23 annotated: sub_1019DC @ 0x1019dc
// Original: 1019dc_sub_1019DC.c
// Primary struct: <unclustered>
//
// sub_1019DC @ 0x1019dc, size 44 bytes
int __fastcall sub_1019DC(__int16 a1)
{
  int v1; // r4
  _DWORD *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101A0C;
  v2 = off_101A10;
  v3 = (int *)off_101A14;
  result = a1 & 0x7FF;
  *(_DWORD *)off_101A08 = *(_DWORD *)off_101A08 & dword_101A0C | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

