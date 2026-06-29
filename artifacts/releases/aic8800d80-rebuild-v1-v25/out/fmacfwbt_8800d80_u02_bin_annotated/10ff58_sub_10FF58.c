// fwstruct annotate: 10ff58_sub_10FF58.c
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
  _WORD v7[2]; // [sp+4h] [bp-14h] BYREF
  _WORD v8[8]; // [sp+8h] [bp-10h] BYREF

  v0 = off_10FFD4;
  v1 = *(_DWORD *)off_10FFD4;
  v2 = off_10FFDC;
  v3 = *((_WORD *)off_10FFD8 + 153);
  v4 = *((_WORD *)off_10FFD8 + 154) - 4;
  v7[1] = *(_WORD *)(*(_DWORD *)off_10FFD4 + 2);
  v8[1] = *(_WORD *)(v1 + 4);
  v8[5] = *(_WORD *)(v1 + 6);
  v8[7] = *(_WORD *)(v1 + 8);
  v5 = *(_QWORD *)(v1 + 20);
  *(_DWORD *)off_10FFDC = v5;
  v2[3] = dword_10FFE0;
  v2[1] = HIDWORD(v5);
  *((_BYTE *)v2 + 8) = 1;
  v8[2] = v4;
  v8[6] = v3 - 4;
  v7[0] = 12;
  v8[4] = 1596;
  v8[0] = 124;
  v8[3] = 0;
  sub_10F77C(v2, (int)v7, 0x20u);
  return sub_10FDC4((int)v8, *(_DWORD *)(*(_DWORD *)v0 + 28), *(_DWORD *)(*(_DWORD *)v0 + 32));
}

