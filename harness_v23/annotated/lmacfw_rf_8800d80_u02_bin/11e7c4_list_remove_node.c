// v23 annotated: list_remove_node @ 0x11e7c4
// Original: 11e7c4_list_remove_node.c
// Primary struct: <unclustered>
//
// list_remove_node @ 0x11e7c4, size 90 bytes
// Doc: sdio_buffer_prepare_n_3a0 [mmio]: Prepares SDIO buffer descriptor (shift/align field extraction)
// sdio_buffer_prepare_n_3a0 [mmio]: Prepares SDIO buffer descriptor (shift/align field extraction)
int __fastcall list_remove_node(int result, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r3

  v2 = result;
  if ( **(__int16 **)off_11E820 < 0 && !result )
    result = rf_cmd_send_n264(sdio_buffer_prepare_n_38c, dword_11E824, 132);
  v4 = *(_DWORD **)v2;
  if ( *(_DWORD *)v2 )
  {
    if ( v4 == a2 )
    {
      v6 = *(_DWORD **)(v2 + 4);
      *(_DWORD *)v2 = *a2;
      if ( v6 == a2 )
        *(_DWORD *)(v2 + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 = (_DWORD *)*v4;
        if ( !v4 )
          break;
        if ( v4 == a2 )
        {
          if ( *(_DWORD **)(v2 + 4) == a2 )
            *(_DWORD *)(v2 + 4) = v5;
          *v5 = *a2;
          return result;
        }
      }
    }
  }
  return result;
}

