// sub_128F1C @ 0x128f1c, size 50 bytes
int sub_128F1C()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3

  v0 = off_128F50;
  if ( !*(_BYTE *)off_128F50 && !rf_bus_setup_nd0() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((_DWORD **)off_128F54 + 2);
  if ( v1 )
  {
    while ( !v1[1] )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

