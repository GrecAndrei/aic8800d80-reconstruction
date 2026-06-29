// fwstruct annotate: 11bff4_sub_11BFF4.c
// sub_11BFF4 @ 0x11bff4, size 68 bytes
int __fastcall sub_11BFF4(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11C03C;
  v3 = *((unsigned __int8 *)off_11C038 + 190);
  sub_12D4F8(dword_11C03C + 84 * v3 + 12);
  result = sub_118358(a1, a2, v3);
  if ( (*(_DWORD *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(_DWORD *)(v6 + 36) = *(_DWORD *)(a1 + 68);
    *(_BYTE *)(v6 + 26) = 2;
  }
  return result;
}

