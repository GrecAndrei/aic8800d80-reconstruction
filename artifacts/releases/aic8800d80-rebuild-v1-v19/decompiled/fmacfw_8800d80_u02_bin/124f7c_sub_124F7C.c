// sub_124F7C @ 0x124f7c, size 30 bytes
int __fastcall sub_124F7C(_DWORD *a1)
{
  _DWORD *v1; // r3

  v1 = *(_DWORD **)off_124F9C;
  if ( !*(_DWORD *)off_124F9C )
    return (int)v1;
  if ( v1 != a1 )
  {
    while ( 1 )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        break;
      if ( a1 == v1 )
        return 1;
    }
    return (int)v1;
  }
  return 1;
}

