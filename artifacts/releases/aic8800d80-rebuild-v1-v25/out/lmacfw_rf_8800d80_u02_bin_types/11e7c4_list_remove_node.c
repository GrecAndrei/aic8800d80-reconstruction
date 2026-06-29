// list_remove_node @ 0x11e7c4, size 90 bytes
// Doc: sdio_buffer_prepare_n_3a0 [mmio]: Prepares SDIO buffer descriptor (shift/align field extraction)
// sdio_buffer_prepare_n_3a0 [mmio]: Prepares SDIO buffer descriptor (shift/align field extraction)
int  list_remove_node(int result, uint32_t *a2)
{
  int v2; // r5
  uint32_t *v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r3

  v2 = result;
  if ( **(__int16 **)off_11E820 < 0 && !result )
    result = rf_cmd_send_n264(sdio_buffer_prepare_n_38c, dword_11E824, 132);
  v4 = *(uint32_t **)v2;
  if ( *(uint32_t *)v2 )
  {
    if ( v4 == a2 )
    {
      v6 = *(uint32_t **)(v2 + 4);
      *(uint32_t *)v2 = *a2;
      if ( v6 == a2 )
        *(uint32_t *)(v2 + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 = (uint32_t *)*v4;
        if ( !v4 )
          break;
        if ( v4 == a2 )
        {
          if ( *(uint32_t **)(v2 + 4) == a2 )
            *(uint32_t *)(v2 + 4) = v5;
          *v5 = *a2;
          return result;
        }
      }
    }
  }
  return result;
}

