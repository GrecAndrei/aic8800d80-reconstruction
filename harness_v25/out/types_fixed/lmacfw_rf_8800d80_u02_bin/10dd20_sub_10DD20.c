// sub_10DD20 @ 0x10dd20, size 128 bytes
int sub_10DD20()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DDB8;
  v1 = off_10DDBC;
  v2 = dword_10DDC0;
  v3 = dword_10DDC4;
  *(_DWORD *)off_10DDBC = 0;
  *(_DWORD *)(v0 + 0x38) = 296;
  *(_DWORD *)(v1 + 0x8) = *(_DWORD *)(v1 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v1 + 0xc) = v2 & *(_DWORD *)(v1 + 0xc) | 0xA06A000;
  *(_DWORD *)(v1 + 0xc) = v3 & *(_DWORD *)(v1 + 0xc) | 0x100230;
  *(_DWORD *)(v1 + 0x4) = 1;
  while ( *(_DWORD *)(v1 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v1 + 0x1c) = 1;
  v4 = sub_12752C(*(_DWORD *)(v1 + 0x10));
  v5 = sub_127620(v4, HIDWORD(v4), dword_10DDA0, dword_10DDA4);
  v6 = sub_127874(v5, HIDWORD(v5), dword_10DDA8, dword_10DDAC);
  v7 = sub_1272B0(v6, HIDWORD(v6), dword_10DDB0, dword_10DDB4);
  return sub_127BE4(v7);
}

