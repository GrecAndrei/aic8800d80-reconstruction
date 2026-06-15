// v23 annotated: sub_12D62C @ 0x12d62c
// Original: 12d62c_sub_12D62C.c
// Primary struct: <unclustered>
//
// sub_12D62C @ 0x12d62c, size 42 bytes
_DWORD *__fastcall sub_12D62C(_DWORD *result, _DWORD *a2, _DWORD *a3)
{
  _DWORD **v3; // r3

  if ( !a2 )
    return (_DWORD *)list_push_tail((int)result, a3);
  v3 = (_DWORD **)*result;
  if ( (_DWORD *)*result == a2 )
    return (_DWORD *)bt_state_check_or_init((int)result, a3);
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

