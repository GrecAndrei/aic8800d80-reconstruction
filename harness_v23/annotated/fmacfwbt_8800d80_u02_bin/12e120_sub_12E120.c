// v23 annotated: sub_12E120 @ 0x12e120
// Original: 12e120_sub_12E120.c
// Primary struct: <unclustered>
//
// sub_12E120 @ 0x12e120, size 64 bytes
// Doc: sdio_buffer_prepare_n_20a [mmio]: Prepares SDIO buffer by validating length/offset fields
// sdio_buffer_prepare_n_20a [mmio]: Prepares SDIO buffer by validating length/offset fields
unsigned __int8 *__fastcall sub_12E120(unsigned __int8 *result, int a2)
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

