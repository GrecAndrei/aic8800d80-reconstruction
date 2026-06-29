// fwstruct annotate: 11e76c_sub_11E76C.c
// sub_11E76C @ 0x11e76c, size 52 bytes
// Doc: sdio_buffer_prepare_776 [mmio]: Prepare SDIO buffer for DMA transfer
// sdio_buffer_prepare_776 [mmio]: Prepare SDIO buffer for DMA transfer
int __fastcall sub_11E76C(int result, _DWORD *a2)
{
  _DWORD *v2; // r5

  v2 = (_DWORD *)result;
  if ( **(__int16 **)sdio_buffer_prepare_e7a0 < 0 && !a2 )
    result = rf_cmd_send_n264(dword_11E7A8, dword_11E7A4, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

