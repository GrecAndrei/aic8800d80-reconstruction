// v23 annotated: sub_125C58 @ 0x125c58
// Original: 125c58_sub_125C58.c
// Primary struct: <unclustered>
//
// sub_125C58 @ 0x125c58, size 42 bytes
int __fastcall sub_125C58(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r2

  v2 = (_BYTE *)sub_12C7EC(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(_BYTE *)(a1 + 24);
  v3 = off_125C84;
  *v2 = *(_BYTE *)(a1 + 26);
  *v3 &= ~4u;
  return sub_12C84C(v2);
}

