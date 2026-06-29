// sub_122180 @ 0x122180, size 42 bytes
int sub_122180()
{
  uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = off_1221AC;
  result = dword_1221B0;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}

