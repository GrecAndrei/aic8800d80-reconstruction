// sub_135424 @ 0x135424, size 48 bytes
_DWORD *__fastcall sub_135424(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((_DWORD *)off_135454 + 4);
  v3 = sub_12C7EC(30, 0, 6, 4u);
  *(_WORD *)v3 = a1;
  *(_BYTE *)(v3 + 2) = 1;
  *(_BYTE *)(v3 + 3) = *(_BYTE *)(v2 + 61);
  sub_12C84C(v3);
  return sub_12CBF4(6u, 9);
}

