// sub_11EAA0 @ 0x11eaa0, size 26 bytes
// Doc: sdio_buffer_prepare_n_108 [mac]: Prepares SDIO host buffer for transfer
// sdio_buffer_prepare_n_108 [mac]: Prepares SDIO host buffer for transfer
float  sub_11EAA0(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = sub_11E964(a1);
  v2 = sub_127570(LODWORD(v1));
  v3 = sub_127620(v2, HIDWORD(v2), sdio_buffer_prepare_n_f4, dword_11EAC4);
  return sub_127BE4(v3);
}

