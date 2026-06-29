// sub_101904 @ 0x101904, size 44 bytes
int  sub_101904(__int16 a1)
{
  int v1; // r4
  uint32_t *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101934;
  v2 = off_101938;
  v3 = (int *)off_10193C;
  result = a1 & 0x7FF;
  *(uint32_t *)off_101930 = *(uint32_t *)off_101930 & dword_101934 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

