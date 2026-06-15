// v23 annotated: sub_124E3C @ 0x124e3c
// Original: 124e3c_sub_124E3C.c
// Primary struct: <unclustered>
//
// sub_124E3C @ 0x124e3c, size 30 bytes
int __fastcall sub_124E3C(_DWORD *a1)
{
  _DWORD *v1; // r3

  v1 = *(_DWORD **)off_124E5C;
  if ( !*(_DWORD *)off_124E5C )
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

