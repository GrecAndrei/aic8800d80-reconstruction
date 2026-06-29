// fwstruct annotate: 101a88_sub_101A88.c
// sub_101A88 @ 0x101a88, size 44 bytes
int __fastcall sub_101A88(__int16 a1)
{
  int v1; // r4
  _DWORD *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101AB8;
  v2 = off_101ABC;
  v3 = (int *)off_101AC0;
  result = a1 & 0x7FF;
  *(_DWORD *)off_101AB4 = *(_DWORD *)off_101AB4 & dword_101AB8 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

