// sub_1222C0 @ 0x1222c0, size 42 bytes
int sub_1222C0()
{
  uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = off_1222EC;
  result = dword_1222F0;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}

