// sub_12DF70 @ 0x12df70, size 64 bytes
// Doc: sdio_buffer_prepare_n_3b6 [mmio]: Prepare/check SDIO transfer buffer before host exchange
// sdio_buffer_prepare_n_3b6 [mmio]: Prepare/check SDIO transfer buffer before host exchange
uint8_t * sub_12DF70(uint8_t *result, int a2)
{
  unsigned int v2; // r1
  unsigned int v3; // r3
  uint8_t *v4; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = (unsigned __int8)result[1] + 2;
    v4 = &result[v3];
    if ( *result == 71 )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v4 )
    return nullptr;
  if ( result )
  {
    if ( v3 < 6 )
      return nullptr;
  }
  return result;
}

