// v23 annotated: sub_141C0C @ 0x141c0c
// Original: 141c0c_sub_141C0C.c
// Primary struct: <unclustered>
//
// sub_141C0C @ 0x141c0c, size 66 bytes
int __fastcall sub_141C0C(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(_DWORD *)(a1 + 24)
     - 400
     - *(_DWORD *)(a1 + 48) * a2
     - *(_DWORD *)(dword_141C50 + 1320 * *(unsigned __int8 *)(a1 + 47) + 40);
  v4 = sub_12BD00();
  v5 = *((_DWORD *)off_141C54 + 4);
  *(_DWORD *)(a1 + 56) = dword_141C58;
  return sub_124BFC(a1 + 52, v5 + v3 - v4);
}

