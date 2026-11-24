// sub_129140 @ 0x129140, size 50 bytes
int sub_129140()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3

  v0 = off_129174;
  if ( !*(_BYTE *)off_129174 && !sub_12A690() )
    return 0;
  if ( *(_DWORD *)(v0 + 0x4) )
    return 0;
  v1 = *((_DWORD **)off_129178 + 2);
  if ( v1 )
  {
    while ( !*(_DWORD *)(v1 + 0x4) )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

