// sub_12DEF8 @ 0x12def8, size 64 bytes
// Doc: sdio_buffer_prepare_n_1f0 [util]: SDIO buffer prepare variant N_1F0
// sdio_buffer_prepare_n_1f0 [util]: SDIO buffer prepare variant N_1F0
unsigned __int8 *__fastcall sub_12DEF8(unsigned __int8 *result, int a2)
{
  unsigned int v2; // r1
  unsigned __int8 *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[result[1] + 2];
    if ( *result == 192 )
      break;
    result += result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return nullptr;
  }
  if ( v2 < (unsigned int)v3 )
    return nullptr;
  if ( result )
  {
    if ( result[1] != 5 )
      return nullptr;
  }
  return result;
}

