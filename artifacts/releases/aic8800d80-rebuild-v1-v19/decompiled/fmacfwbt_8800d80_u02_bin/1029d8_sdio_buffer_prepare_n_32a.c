// sdio_buffer_prepare_n_32a @ 0x1029d8, size 26 bytes
// Doc: sdio_buffer_prepare_n_32a [util]: Validate/prepare SDIO buffer length against limit
// sdio_buffer_prepare_n_32a [util]: Validate/prepare SDIO buffer length against limit
int sdio_buffer_prepare_n_32a()
{
  return (unsigned __int8)((1 << ((unsigned __int8)*(_DWORD *)off_1029F4 >> 4)) - 1);
}

