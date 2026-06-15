// v23 annotated: sub_12D404 @ 0x12d404
// Original: 12d404_sub_12D404.c
// Primary struct: <unclustered>
//
// sub_12D404 @ 0x12d404, size 42 bytes
_DWORD *__fastcall sub_12D404(_DWORD *result, _DWORD *a2, _DWORD *a3)
{
  _DWORD **v3; // r3

  if ( !a2 )
    return (_DWORD *)list_push_tail((int)result, a3);
  v3 = (_DWORD **)*result;
  if ( (_DWORD *)*result == a2 )
    return (_DWORD *)sub_12D290((int)result, a3);
  if ( v3 )
  {
    while ( 1 )
    {
      result = *v3;
      if ( *v3 == a2 )
        break;
      v3 = (_DWORD **)*v3;
      if ( !result )
        return result;
    }
    *a3 = a2;
    *v3 = a3;
  }
  return result;
}

