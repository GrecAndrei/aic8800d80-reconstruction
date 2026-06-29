// sub_11D9F8 @ 0x11d9f8, size 64 bytes
int  sub_11D9F8(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = rf_calibration_init((int)v3, &v4, v5);
  v2 = (unsigned int *)off_11DA38;
  *(uint32_t *)off_11DA38 = *(uint32_t *)off_11DA38 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

