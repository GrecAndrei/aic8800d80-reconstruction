// sub_10DF54 @ 0x10df54, size 146 bytes
float sub_10DF54()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10DFE8;
  v1 = off_10DFEC;
  v2 = dword_10DFF0;
  v3 = dword_10DFF4;
  v4 = dword_10DFF8;
  *(_DWORD *)off_10DFE8 = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v0 + 0xc) = v2 & *(_DWORD *)(v0 + 0xc) | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v4 | v3 & *(_DWORD *)(v0 + 0xc);
  sub_10DCB0();
  *(_DWORD *)(v0 + 0x4) = 1;
  while ( *(_DWORD *)(v0 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v0 + 0x1c) = 1;
  v5 = *(_DWORD *)(v0 + 0x10);
  sub_10EFB4(dword_10DFFC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E000) - 1.0) * flt_10E004) * 5.5;
}

