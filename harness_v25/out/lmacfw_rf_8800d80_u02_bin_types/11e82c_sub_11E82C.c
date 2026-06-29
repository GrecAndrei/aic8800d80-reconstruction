// sub_11E82C @ 0x11e82c, size 20 bytes
// Doc: sdio_buffer_prepare_n_382 [mmio]: Prepare SDIO DMA buffer descriptors for transfer
// sdio_buffer_prepare_n_382 [mmio]: Prepare SDIO DMA buffer descriptors for transfer
int  sub_11E82C(uint32_t **a1)
{
  uint32_t *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (uint32_t *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}

