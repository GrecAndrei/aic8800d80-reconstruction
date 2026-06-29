// mmio_write_status_n_3a4 @ 0x1370cc, size 82 bytes
// Doc: mmio_write_status_n_3a4 [mmio]: Write status/control value to MMIO offsets 0xf08/0xf0a
// mmio_write_status_n_3a4 [mmio]: Write status/control value to MMIO offsets 0xf08/0xf0a
int  mmio_write_status_n_3a4(int a1, int a2, int a3, int a4)
{
  uint16_t *v4; // r2
  uint64_t v6; // r0
  uint8_t *v8; // r0
  int v9; // r0

  v4 = off_137120;
  *((uint16_t *)off_137120 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(QWORD *)(a2 + 352);
  *(uint32_t *)v4 = a2;
  *((uint32_t *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_138668(v6);
    return 1;
  }
  else
  {
    v8 = (uint8_t *)sub_12C92C(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(uint8_t *)(a2 + 366);
    v9 = sdio_buffer_prepare_n_4e8((int)v8);
    sub_138668(v9);
    return 1;
  }
}

