// sub_12DC20 @ 0x12dc20, size 64 bytes
// Doc: sdio_buffer_prepare_n_4ce_dc4e [mac]: Prepare SDIO buffer (trampoline/leaf stub)
// sdio_buffer_prepare_n_4ce_dc4e [mac]: Prepare SDIO buffer (trampoline/leaf stub)
unsigned __int8 * sub_12DC20(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r1
  unsigned __int8 *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[result[1] + 2];
    if ( *result == 199 )
      break;
    result += result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 1 )
      return nullptr;
  }
  return result;
}

