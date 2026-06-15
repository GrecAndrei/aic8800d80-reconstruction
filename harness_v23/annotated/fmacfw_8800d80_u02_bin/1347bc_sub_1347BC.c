// v23 annotated: sub_1347BC @ 0x1347bc
// Original: 1347bc_sub_1347BC.c
// Primary struct: <unclustered>
//
// sub_1347BC @ 0x1347bc, size 52 bytes
int sub_1347BC()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r4

  v0 = rf_bus_mark_n100_d2d0(dword_1347F0);
  v1 = v0;
  if ( **(__int16 **)off_1347F4 < 0 && !v0 )
    sub_12F46C(dword_1347FC, dword_1347F8, 766);
  return sdio_buffer_prepare_n_4e8((int)(v1 + 3));
}

