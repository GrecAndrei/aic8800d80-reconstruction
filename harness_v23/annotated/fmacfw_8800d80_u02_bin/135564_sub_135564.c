// v23 annotated: sub_135564 @ 0x135564
// Original: 135564_sub_135564.c
// Primary struct: <unclustered>
//
// sub_135564 @ 0x135564, size 48 bytes
_DWORD *__fastcall sub_135564(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((_DWORD *)off_135594 + 4);
  v3 = sub_12C92C(30, 0, 6, 4u);
  *(_WORD *)v3 = a1;
  *(_BYTE *)(v3 + 2) = 1;
  *(_BYTE *)(v3 + 3) = *(_BYTE *)(v2 + 61);
  sub_12C98C(v3);
  return sub_12CD34(6u, 9);
}

