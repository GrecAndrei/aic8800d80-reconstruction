// sub_12C344 @ 0x12c344, size 64 bytes
int  sub_12C344(char a1)
{
  int result; // r0
  unsigned int *v2; // r2
  uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  unsigned __int8 v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF

  v3[0] = a1;
  result = sub_101A54((int)v3, &v4, v5);
  v2 = (unsigned int *)off_12C384;
  *(uint32_t *)off_12C384 = *(uint32_t *)off_12C384 & 0xFFFF00FF | (v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | v5[0];
  return result;
}

