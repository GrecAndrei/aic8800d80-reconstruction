// sub_10E048 @ 0x10e048, size 72 bytes
int sub_10E048()
{
  _DWORD *v0; // r3
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0

  while ( *((_DWORD *)off_10E0A8 + 7) != 1 )
    ;
  v0 = off_10E0A8;
  *((_DWORD *)off_10E0A8 + 7) = 1;
  v1 = sub_1429B4(v0[4]);
  v2 = sub_142AA8(v1, HIDWORD(v1), dword_10E090, dword_10E094);
  v3 = sub_142CFC(v2, HIDWORD(v2), dword_10E098, dword_10E09C);
  v4 = sub_142738(v3, HIDWORD(v3), dword_10E0A0, dword_10E0A4);
  return sub_14306C(v4);
}

