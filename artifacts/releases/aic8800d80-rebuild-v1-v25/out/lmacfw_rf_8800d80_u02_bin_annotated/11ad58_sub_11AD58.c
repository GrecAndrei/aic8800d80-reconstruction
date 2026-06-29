// fwstruct annotate: 11ad58_sub_11AD58.c
// sub_11AD58 @ 0x11ad58, size 42 bytes
int __fastcall sub_11AD58(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r2

  v2 = (_BYTE *)sub_11DDF0(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(_BYTE *)(a1 + 24);
  v3 = off_11AD84;
  *v2 = *(_BYTE *)(a1 + 26);
  *v3 &= ~4u;
  return sub_11DE50(v2);
}

