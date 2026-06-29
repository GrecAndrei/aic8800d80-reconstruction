// sdio_buffer_prepare_6ec @ 0x11e6ec, size 40 bytes
// Doc: sdio_buffer_prepare_6ec [mmio]: Prepare SDIO buffer for transfer
// sdio_buffer_prepare_6ec [mmio]: Prepare SDIO buffer for transfer
int sdio_buffer_prepare_6ec()
{
  uint32_t *v0; // r0
  uint32_t *v1; // r3
  int v2; // r1

  v0 = rx_queue_head_init();
  v1 = off_11E714;
  v2 = sdio_buffer_prepare_n_49c;
  *((uint32_t *)off_11E714 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return sub_11E628(-1);
}

