// sub_1164E0 @ 0x1164e0, size 34 bytes
int  sub_1164E0(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_116504;
  result = a1 + 22;
  v4 = dword_116504 + 8 * result;
  if ( *(uint32_t *)(v4 + 4) )
    v4 = *(uint32_t *)(v4 + 8);
  *(uint32_t *)(v4 + 4) = a2;
  *(uint32_t *)(v2 + 8 * result + 8) = a2;
  *(uint32_t *)(a2 + 4) = 0;
  return result;
}

