// sub_12DCA0 @ 0x12dca0, size 64 bytes
// Doc: sdio_buffer_prepare_n_45e [ipc]: Prepare SDIO buffer descriptor compare
// sdio_buffer_prepare_n_45e [ipc]: Prepare SDIO buffer descriptor compare
uint8_t * sub_12DCA0(uint8_t *result, int a2)
{
  unsigned int v2; // r1
  uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(unsigned __int8)result[1] + 2];
    if ( *result == 54 )
      break;
    result += (unsigned __int8)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 3 )
      return nullptr;
  }
  return result;
}

