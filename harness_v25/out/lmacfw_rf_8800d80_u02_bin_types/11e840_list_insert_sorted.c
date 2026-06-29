// list_insert_sorted @ 0x11e840, size 70 bytes
// Doc: sdio_buffer_prepare_n_336 [mmio]: SDIO buffer preparation stub
// sdio_buffer_prepare_n_336 [mmio]: SDIO buffer preparation stub
int  list_insert_sorted(int result, uint32_t *a2, int ( *a3)(uint32_t *, uint32_t *))
{
  uint32_t *v3; // r4
  uint32_t *v4; // r7
  uint32_t *v7; // r8

  v3 = *(uint32_t **)result;
  v4 = (uint32_t *)result;
  if ( *(uint32_t *)result )
  {
    v7 = nullptr;
    for ( result = a3(a2, v3); !result; result = a3(a2, v3) )
    {
      v7 = v3;
      if ( !*v3 )
      {
        v4[1] = a2;
        *a2 = 0;
        goto sdio_buffer_prepare_n_33c;
      }
      v3 = (uint32_t *)*v3;
    }
    *a2 = v3;
    if ( !v7 )
      goto sdio_buffer_prepare_n_346;
sdio_buffer_prepare_n_33c:
    *v7 = a2;
  }
  else
  {
    *(uint32_t *)(result + 4) = a2;
    *a2 = 0;
sdio_buffer_prepare_n_346:
    *v4 = a2;
  }
  return result;
}

