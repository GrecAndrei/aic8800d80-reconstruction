// sub_131144 @ 0x131144, size 40 bytes
unsigned __int8 * sub_131144(uint8_t *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0

  result = sub_12DEC8(a1, a2);
  if ( result )
  {
    *(uint16_t *)(a3 + 228) = result[2] | (result[3] << 8);
    *(uint8_t *)(a3 + 230) = result[4];
  }
  else
  {
    *(uint8_t *)(a3 + 230) = 0;
    *(uint16_t *)(a3 + 228) = 0;
  }
  return result;
}

