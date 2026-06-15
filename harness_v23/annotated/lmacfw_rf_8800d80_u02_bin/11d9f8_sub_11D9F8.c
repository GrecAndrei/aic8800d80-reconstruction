// v23 annotated: sub_11D9F8 @ 0x11d9f8
// Original: 11d9f8_sub_11D9F8.c
// Primary struct: group_18 (cluster 18)
//
// sub_11D9F8 @ 0x11d9f8, size 64 bytes
int __fastcall sub_11D9F8(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  _BYTE v3[7]; // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  _BYTE v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = rf_calibration_init((int)v3, &v4, v5);
  v2 = (unsigned int *)off_11DA38;
  *(_DWORD *)off_11DA38 = *(_DWORD *)off_11DA38 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

