// sub_13B8E4 @ 0x13b8e4, size 76 bytes
unsigned __int8 * sub_13B8E4(int a1)
{
  unsigned __int8 *result; // r0
  int v2; // r1
  int v3; // r3

  result = (unsigned __int8 *)(dword_13B930 + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(uint8_t *)(696 * v2 + 12 * v3 + dword_13B934 + 453) = 33;
  }
  else
  {
    *(uint8_t *)(696 * v2 + 12 * v3 + dword_13B934 + 452) = 33;
  }
  return result;
}

