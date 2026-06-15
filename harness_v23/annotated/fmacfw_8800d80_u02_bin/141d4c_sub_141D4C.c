// v23 annotated: sub_141D4C @ 0x141d4c
// Original: 141d4c_sub_141D4C.c
// Primary struct: <unclustered>
//
// sub_141D4C @ 0x141d4c, size 66 bytes
int __fastcall sub_141D4C(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(_DWORD *)(a1 + 24)
     - 400
     - *(_DWORD *)(a1 + 48) * a2
     - *(_DWORD *)(dword_141D90 + 1320 * *(unsigned __int8 *)(a1 + 47) + 40);
  v4 = sub_12BE40();
  v5 = *((_DWORD *)off_141D94 + 4);
  *(_DWORD *)(a1 + 56) = dword_141D98;
  return sub_124D3C(a1 + 52, v5 + v3 - v4);
}

