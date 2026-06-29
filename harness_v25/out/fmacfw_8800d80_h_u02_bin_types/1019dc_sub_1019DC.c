// sub_1019DC @ 0x1019dc, size 44 bytes
int  sub_1019DC(__int16 a1)
{
  int v1; // r4
  uint32_t *v2; // r1
  int *v3; // r2
  int result; // r0

  v1 = dword_101A0C;
  v2 = off_101A10;
  v3 = (int *)off_101A14;
  result = a1 & 0x7FF;
  *(uint32_t *)off_101A08 = *(uint32_t *)off_101A08 & dword_101A0C | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}

