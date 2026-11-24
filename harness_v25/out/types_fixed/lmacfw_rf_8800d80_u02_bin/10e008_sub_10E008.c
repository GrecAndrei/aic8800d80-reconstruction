// sub_10E008 @ 0x10e008, size 142 bytes
float sub_10E008()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E098;
  v1 = off_10E09C;
  v2 = dword_10E0A0;
  v3 = dword_10E0A4;
  v4 = dword_10E0A8;
  *(_DWORD *)off_10E098 = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v0 + 0xc) = v2 & *(_DWORD *)(v0 + 0xc) | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v4 | v3 & *(_DWORD *)(v0 + 0xc);
  sub_10DC40();
  *(_DWORD *)(v0 + 0x4) = 1;
  while ( *(_DWORD *)(v0 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v0 + 0x1c) = 1;
  v5 = *(_DWORD *)(v0 + 0x10);
  sub_10EFB4(dword_10E0AC, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4)
       + (float)((float)((float)((float)v5 / flt_10E0B0) - 1.0) * flt_10E0B4);
}

