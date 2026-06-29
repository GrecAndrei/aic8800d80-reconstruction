// sub_12B12C @ 0x12b12c, size 30 bytes
int  sub_12B12C(int a1, int a2, int a3)
{
  int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v3 = dword_12B14C;
  v4 = (unsigned int)(1967 * a2 * a3) >> 16;
  result = dword_12B14C + 32 * a1;
  if ( v4 )
    *(uint32_t *)(result + 24) = v4;
  else
    v3 = 1;
  if ( !v4 )
    *(uint32_t *)(result + 24) = v3;
  return result;
}

