// sub_11D9F8 @ 0x11d9f8, size 64 bytes
int __fastcall sub_11D9F8(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  _BYTE *(_DWORD *)(v3 + 0x1c); // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  _BYTE *(_DWORD *)(v5 + 0x14); // [sp+Fh] [bp-5h] BYREF

  *(_DWORD *)(v3 + 0x0) = a1;
  result = rf_calibration_init((int)v3, &v4, v5);
  v2 = (unsigned int *)off_11DA38;
  *(_DWORD *)off_11DA38 = *(_DWORD *)off_11DA38 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | *(_DWORD *)(v5 + 0x0);
  return result;
}

