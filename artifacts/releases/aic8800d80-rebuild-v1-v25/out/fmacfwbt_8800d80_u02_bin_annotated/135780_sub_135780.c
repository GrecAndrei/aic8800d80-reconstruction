// fwstruct annotate: 135780_sub_135780.c
// sub_135780 @ 0x135780, size 48 bytes
_DWORD *__fastcall sub_135780(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((_DWORD *)off_1357B0 + 4);
  v3 = sub_12CB54(30, 0, 6, 4u);
  *(_WORD *)v3 = a1;
  *(_BYTE *)(v3 + 2) = 1;
  *(_BYTE *)(v3 + 3) = *(_BYTE *)(v2 + 61);
  sub_12CBB4(v3);
  return sub_12CF5C(6u, 9);
}

