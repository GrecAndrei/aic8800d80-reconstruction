// sub_10E0B8 @ 0x10e0b8, size 146 bytes
float sub_10E0B8()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r2
  int v2; // r3
  int v3; // r0
  int v4; // r1
  unsigned int v5; // r4

  v0 = off_10E14C;
  v1 = off_10E150;
  v2 = dword_10E154;
  v3 = dword_10E158;
  v4 = dword_10E15C;
  *(_DWORD *)off_10E14C = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v0 + 0xc) = v2 & *(_DWORD *)(v0 + 0xc) | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v4 | v3 & *(_DWORD *)(v0 + 0xc);
  sub_10DC78();
  *(_DWORD *)(v0 + 0x4) = 1;
  while ( *(_DWORD *)(v0 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v0 + 0x1c) = 1;
  v5 = *(_DWORD *)(v0 + 0x10);
  sub_10EFB4(dword_10E160, 0, 15360);
  return (float)((float)((float)((float)v5 / flt_10E164) - 1.0) * flt_10E168) * flt_10E16C;
}

