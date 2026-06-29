// fwstruct annotate: 12de50_sub_12DE50.c
// sub_12DE50 @ 0x12de50, size 64 bytes
// Doc: sdio_buffer_prepare_n_2a0 [mmio]: Prepare SDIO transfer buffer for host IO
// sdio_buffer_prepare_n_2a0 [mmio]: Prepare SDIO transfer buffer for host IO
unsigned __int8 *__fastcall sub_12DE50(unsigned __int8 *result, int a2)
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

