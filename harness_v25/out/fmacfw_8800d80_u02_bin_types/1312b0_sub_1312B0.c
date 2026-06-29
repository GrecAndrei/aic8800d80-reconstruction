// sub_1312B0 @ 0x1312b0, size 38 bytes
unsigned __int8 * sub_1312B0(unsigned __int8 *a1, int a2, uint8_t *a3)
{
  unsigned __int8 *result; // r0
  unsigned int v5; // r3

  result = sdio_buffer_prepare_n_19c(a1, a2);
  if ( result )
  {
    v5 = result[3];
    *a3 = v5 & 7;
    a3[1] = (v5 >> 3) & 7;
    return (unsigned __int8 *)1;
  }
  else
  {
    *a3 = 3;
    a3[1] = 5;
  }
  return result;
}

