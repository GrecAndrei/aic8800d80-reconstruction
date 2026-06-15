// v23 annotated: timestamp_list_contains_51a0 @ 0x1251a0
// Original: 1251a0_timestamp_list_contains_51a0.c
// Primary struct: <unclustered>
//
// timestamp_list_contains_51a0 @ 0x1251a0, size 30 bytes
// Doc: timestamp_list_contains_51a0 [util]: Check if a timestamp value exists in a list
// timestamp_list_contains_51a0 [util]: Check if a timestamp value exists in a list
int __fastcall timestamp_list_contains_51a0(_DWORD *a1)
{
  _DWORD *v1; // r3

  v1 = *(_DWORD **)off_1251C0;
  if ( !*(_DWORD *)off_1251C0 )
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

