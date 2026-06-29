// fwstruct annotate: 11e724_list_push_tail.c
// list_push_tail @ 0x11e724, size 60 bytes
// Doc: sdio_buffer_prepare_n_46e [mmio]: Prepares an SDIO buffer descriptor for host data transfer
// sdio_buffer_prepare_n_46e [mmio]: Prepares an SDIO buffer descriptor for host data transfer
int __fastcall list_push_tail(int result, _DWORD *a2)
{
  int v2; // r5

  v2 = result;
  if ( **(__int16 **)off_11E760 < 0 && !a2 )
    result = rf_cmd_send_n264(dword_11E768, sdio_buffer_prepare_n_450, 72);
  if ( *(_DWORD *)v2 )
    **(_DWORD **)(v2 + 4) = a2;
  else
    *(_DWORD *)v2 = a2;
  *(_DWORD *)(v2 + 4) = a2;
  *a2 = 0;
  return result;
}

