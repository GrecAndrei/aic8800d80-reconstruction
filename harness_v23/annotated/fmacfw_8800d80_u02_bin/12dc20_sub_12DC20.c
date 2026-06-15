// v23 annotated: sub_12DC20 @ 0x12dc20
// Original: 12dc20_sub_12DC20.c
// Primary struct: bt_hci_cmd (cluster 5, 21 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DC20 @ 0x12dc20, size 64 bytes
// Doc: sdio_buffer_prepare_n_4ce_dc4e [mac]: Prepare SDIO buffer (trampoline/leaf stub)
// sdio_buffer_prepare_n_4ce_dc4e [mac]: Prepare SDIO buffer (trampoline/leaf stub)
unsigned __int8 *__fastcall sub_12DC20(unsigned __int8 *result, int a2)
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

