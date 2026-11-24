// sub_10DE48 @ 0x10de48, size 72 bytes
int sub_10DE48()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r0
  int v2; // r1
  int v3; // r2
  int result; // r0

  v0 = off_10DE90;
  v1 = off_10DE94;
  v2 = dword_10DE98;
  v3 = dword_10DE9C;
  *(_DWORD *)off_10DE90 = 0;
  *(_DWORD *)(v1 + 0x38) = 296;
  *(_DWORD *)(v0 + 0x8) = *(_DWORD *)(v0 + 0x8) & 0xF000FFFF | 0x2000000;
  result = *(_DWORD *)(v0 + 0xc);
  *(_DWORD *)(v0 + 0xc) = v2 & result | 0xA06A000;
  *(_DWORD *)(v0 + 0xc) = v3 & *(_DWORD *)(v0 + 0xc) | 0x100230;
  *(_DWORD *)(v0 + 0x4) = 1;
  return result;
}

