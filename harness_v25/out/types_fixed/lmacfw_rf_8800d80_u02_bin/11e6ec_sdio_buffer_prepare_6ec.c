// sdio_buffer_prepare_6ec @ 0x11e6ec, size 40 bytes
// Doc: sdio_buffer_prepare_6ec [mmio]: Prepare SDIO buffer for transfer
// sdio_buffer_prepare_6ec [mmio]: Prepare SDIO buffer for transfer
int sdio_buffer_prepare_6ec()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1

  v0 = rx_queue_head_init();
  v1 = off_11E714;
  v2 = sdio_buffer_prepare_n_49c;
  *((_DWORD *)off_11E714 + 7) = v0;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *(_DWORD *)(v1 + 0x18) = 0;
  *(_DWORD *)(v1 + 0x24) = v2;
  return sub_11E628(-1);
}

