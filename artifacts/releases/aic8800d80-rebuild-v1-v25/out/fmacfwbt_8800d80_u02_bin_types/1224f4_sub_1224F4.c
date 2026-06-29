// sub_1224F4 @ 0x1224f4, size 42 bytes
int sub_1224F4()
{
  uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = off_122520;
  result = dword_122524;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}

