// sub_10E21C @ 0x10e21c, size 170 bytes
float sub_10E21C()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r4

  v0 = off_10E2C8;
  v1 = off_10E2CC;
  v2 = dword_10E2D0;
  *(_DWORD *)off_10E2C8 = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  v3 = dword_10E2D4;
  v4 = dword_10E2D8;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v0 + 0xc) = v2 & *(_DWORD *)(v0 + 0xc) | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v4 | v3 & *(_DWORD *)(v0 + 0xc);
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xEFFFFFF0 | 0xB;
  *(_DWORD *)(v0 + 0xc) = *(_DWORD *)(v0 + 0xc) & 0xFFFFF7FE | 1;
  *(_DWORD *)(v0 + 0x8) &= ~0x10000000u;
  *(_DWORD *)(v0 + 0xc) = *(_DWORD *)(v0 + 0xc) & 0xFFFFF7FE | 1;
  *(_DWORD *)(v0 + 0x4) = 1;
  while ( *(_DWORD *)(v0 + 0x1c) != 1 )
    ;
  *(_DWORD *)(v0 + 0x1c) = 1;
  return (float)((float)((float)(unsigned int)*(_DWORD *)(v0 + 0x10) / flt_10E2DC) - 1.0) * flt_10E2E0;
}

