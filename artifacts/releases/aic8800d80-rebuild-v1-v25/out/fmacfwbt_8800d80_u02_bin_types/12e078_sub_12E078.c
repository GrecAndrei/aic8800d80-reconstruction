// sub_12E078 @ 0x12e078, size 64 bytes
// Doc: sdio_buffer_prepare_n_2b0 [tx]: Prepare SDIO buffer for transfer (variant n_2b0)
// sdio_buffer_prepare_n_2b0 [tx]: Prepare SDIO buffer for transfer (variant n_2b0)
unsigned __int8 * sub_12E078(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r1
  unsigned __int8 *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[result[1] + 2];
    if ( *result == 191 )
      break;
    result += result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 12 )
      return nullptr;
  }
  return result;
}

