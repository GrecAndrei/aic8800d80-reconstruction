// fwstruct annotate: 136820_sub_136820.c
// sub_136820 @ 0x136820, size 50 bytes
int sub_136820()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4

  v0 = rf_bus_mark_n100_d2d0(dword_136854);
  v1 = v0;
  if ( **(__int16 **)off_136858 < 0 && !v0 )
    sub_12F46C(dword_136860, dword_13685C, 210);
  return sdio_buffer_prepare_n_4e8((int)(v1 + 3));
}

