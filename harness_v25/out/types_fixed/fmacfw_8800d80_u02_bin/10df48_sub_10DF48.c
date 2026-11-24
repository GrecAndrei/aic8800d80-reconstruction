// sub_10DF48 @ 0x10df48, size 128 bytes
int sub_10DF48()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DFE0;
  v1 = off_10DFE4;
  v2 = dword_10DFE8;
  v3 = dword_10DFEC;
  *(_DWORD *)off_10DFE4 = 0;
  *(_DWORD *)(v0 + 0x38) = 296;
  *(_DWORD *)(v1 + 0x8) = *(_DWORD *)(v1 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v1 + 0xc) = v2 & *(_DWORD *)(v1 + 0xc) | 0xA06A000;
  *(_DWORD *)(v1 + 0xc) = v3 & *(_DWORD *)(v1 + 0xc) | 0x100230;
  *(_DWORD *)(v1 + 0x4) = 1;
  while ( *(_DWORD *)(v1 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v1 + 0x1c) = 1;
  v4 = sub_1429B4(*(_DWORD *)(v1 + 0x10));
  v5 = sub_142AA8(v4, HIDWORD(v4), dword_10DFC8, dword_10DFCC);
  v6 = sub_142CFC(v5, HIDWORD(v5), dword_10DFD0, dword_10DFD4);
  v7 = sub_142738(v6, HIDWORD(v6), dword_10DFD8, dword_10DFDC);
  return sub_14306C(v7);
}

