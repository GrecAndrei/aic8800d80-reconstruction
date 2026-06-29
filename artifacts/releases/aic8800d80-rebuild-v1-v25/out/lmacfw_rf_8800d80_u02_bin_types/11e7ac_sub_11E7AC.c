// sub_11E7AC @ 0x11e7ac, size 22 bytes
// Doc: sdio_buffer_prepare_n_402 [mac]: Copy and clear SDIO buffer descriptor
// sdio_buffer_prepare_n_402 [mac]: Copy and clear SDIO buffer descriptor
uint32_t * sub_11E7AC(int a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r2

  v1 = *(uint32_t **)a1;
  if ( *(uint32_t *)a1 )
  {
    v2 = *(uint32_t **)(a1 + 4);
    *(uint32_t *)a1 = *v1;
    if ( v2 == v1 )
      *(uint32_t *)(a1 + 4) = 0;
  }
  return v1;
}

