// fwstruct annotate: 11e7ac_sub_11E7AC.c
// sub_11E7AC @ 0x11e7ac, size 22 bytes
// Doc: sdio_buffer_prepare_n_402 [mac]: Copy and clear SDIO buffer descriptor
// sdio_buffer_prepare_n_402 [mac]: Copy and clear SDIO buffer descriptor
_DWORD *__fastcall sub_11E7AC(int a1)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r2

  v1 = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 )
  {
    v2 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)a1 = *v1;
    if ( v2 == v1 )
      *(_DWORD *)(a1 + 4) = 0;
  }
  return v1;
}

