// sub_10FF58 @ 0x10ff58, size 122 bytes
// Doc: sub_120FF58 [rf]: Read RF control/status halfwords from shared state
// sub_120FF58 [rf]: Read RF control/status halfwords from shared state
int sub_10FF58()
{
  void *v0; // r4
  int v1; // r3
  _DWORD *v2; // r0
  __int16 v3; // r2
  __int16 v4; // r1
  __int64 v5; // kr00_8
  _WORD *(_DWORD *)(v7 + 0x8); // [sp+4h] [bp-14h] BYREF
  _WORD *(_DWORD *)(v8 + 0x20); // [sp+8h] [bp-10h] BYREF

  v0 = off_10FFD4;
  v1 = *(_DWORD *)off_10FFD4;
  v2 = off_10FFDC;
  v3 = *((_WORD *)off_10FFD8 + 153);
  v4 = *((_WORD *)off_10FFD8 + 154) - 4;
  *(_DWORD *)(v7 + 0x4) = *(_WORD *)(*(_DWORD *)off_10FFD4 + 2);
  *(_DWORD *)(v8 + 0x4) = *(_WORD *)(v1 + 4);
  *(_DWORD *)(v8 + 0x14) = *(_WORD *)(v1 + 6);
  *(_DWORD *)(v8 + 0x1c) = *(_WORD *)(v1 + 8);
  v5 = *(_QWORD *)(v1 + 20);
  *(_DWORD *)off_10FFDC = v5;
  *(_DWORD *)(v2 + 0xc) = dword_10FFE0;
  *(_DWORD *)(v2 + 0x4) = HIDWORD(v5);
  *((_BYTE *)v2 + 8) = 1;
  *(_DWORD *)(v8 + 0x8) = v4;
  *(_DWORD *)(v8 + 0x18) = v3 - 4;
  *(_DWORD *)(v7 + 0x0) = 12;
  *(_DWORD *)(v8 + 0x10) = 1596;
  *(_DWORD *)(v8 + 0x0) = 124;
  *(_DWORD *)(v8 + 0xc) = 0;
  sub_10F77C(v2, (int)v7, 0x20u);
  return sub_10FDC4((int)v8, *(_DWORD *)(*(_DWORD *)v0 + 28), *(_DWORD *)(*(_DWORD *)v0 + 32));
}

