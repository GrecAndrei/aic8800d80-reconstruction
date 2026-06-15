// list_insert_sorted @ 0x11e840, size 70 bytes
// Doc: sdio_buffer_prepare_n_336 [mmio]: SDIO buffer preparation stub
// sdio_buffer_prepare_n_336 [mmio]: SDIO buffer preparation stub
int __fastcall list_insert_sorted(int result, _DWORD *a2, int (__fastcall *a3)(_DWORD *, _DWORD *))
{
  _DWORD *v3; // r4
  _DWORD *v4; // r7
  _DWORD *v7; // r8

  v3 = *(_DWORD **)result;
  v4 = (_DWORD *)result;
  if ( *(_DWORD *)result )
  {
    v7 = nullptr;
    for ( result = a3(a2, v3); !result; result = a3(a2, v3) )
    {
      v7 = v3;
      if ( !*v3 )
      {
        v4[1] = a2;
        *a2 = 0;
        goto sdio_buffer_prepare_n_33c;
      }
      v3 = (_DWORD *)*v3;
    }
    *a2 = v3;
    if ( !v7 )
      goto sdio_buffer_prepare_n_346;
sdio_buffer_prepare_n_33c:
    *v7 = a2;
  }
  else
  {
    *(_DWORD *)(result + 4) = a2;
    *a2 = 0;
sdio_buffer_prepare_n_346:
    *v4 = a2;
  }
  return result;
}

