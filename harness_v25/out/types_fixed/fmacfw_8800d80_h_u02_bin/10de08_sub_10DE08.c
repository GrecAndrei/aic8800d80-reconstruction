// sub_10DE08 @ 0x10de08, size 128 bytes
int sub_10DE08()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DEA0;
  v1 = off_10DEA4;
  v2 = dword_10DEA8;
  v3 = dword_10DEAC;
  *(_DWORD *)off_10DEA4 = 0;
  *(_DWORD *)(v0 + 0x38) = 296;
  *(_DWORD *)(v1 + 0x8) = *(_DWORD *)(v1 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v1 + 0xc) = v2 & *(_DWORD *)(v1 + 0xc) | 0xA06A000;
  *(_DWORD *)(v1 + 0xc) = v3 & *(_DWORD *)(v1 + 0xc) | 0x100230;
  *(_DWORD *)(v1 + 0x4) = 1;
  while ( *(_DWORD *)(v1 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v1 + 0x1c) = 1;
  v4 = sub_142874(*(_DWORD *)(v1 + 0x10));
  v5 = sub_142968(v4, HIDWORD(v4), dword_10DE88, dword_10DE8C);
  v6 = sub_142BBC(v5, HIDWORD(v5), dword_10DE90, dword_10DE94);
  v7 = sub_1425F8(v6, HIDWORD(v6), dword_10DE98, dword_10DE9C);
  return sub_142F2C(v7);
}

