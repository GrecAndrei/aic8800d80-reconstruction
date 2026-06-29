// fwstruct annotate: 13ade4_sub_13ADE4.c
// sub_13ADE4 @ 0x13ade4, size 24 bytes
int __fastcall sub_13ADE4(int a1, int a2)
{
  __int16 v2; // r2

  v2 = *(_WORD *)(a1 + 30) | 1;
  *(_DWORD *)(a1 + 68) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  *(_WORD *)(a1 + 30) = v2;
  return sub_13AA68(a1, a2);
}

