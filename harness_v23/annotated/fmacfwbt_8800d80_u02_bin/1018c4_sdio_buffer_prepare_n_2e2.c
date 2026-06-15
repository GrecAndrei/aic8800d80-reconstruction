// v23 annotated: sdio_buffer_prepare_n_2e2 @ 0x1018c4
// Original: 1018c4_sdio_buffer_prepare_n_2e2.c
// Primary struct: <unclustered>
//
// sdio_buffer_prepare_n_2e2 @ 0x1018c4, size 10 bytes
// Doc: sdio_buffer_prepare_n_2e2 [mac]: SDIO buffer prepare trampoline returning arg2
// sdio_buffer_prepare_n_2e2 [mac]: SDIO buffer prepare trampoline returning arg2
int sdio_buffer_prepare_n_2e2()
{
  return (*(_DWORD *)off_1018D0 >> 28) & 1;
}

