// v23 annotated: sub_12DE48 @ 0x12de48
// Original: 12de48_sub_12DE48.c
// Primary struct: bt_hci_cmd (cluster 4, 22 funcs)
// Fields: ogf=0x0, ocf=0x1
//
// sub_12DE48 @ 0x12de48, size 64 bytes
// Doc: sdio_buffer_prepare_n_4ee_de56 [mmio]: Prepare SDIO buffer for DMA transfer
// sdio_buffer_prepare_n_4ee_de56 [mmio]: Prepare SDIO buffer for DMA transfer
unsigned __int8 *__fastcall sub_12DE48(unsigned __int8 *result, int a2)
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

