// v23 annotated: sub_12D288 @ 0x12d288
// Original: 12d288_sub_12D288.c
// Primary struct: <unclustered>
//
// sub_12D288 @ 0x12d288, size 60 bytes
_DWORD *__fastcall sub_12D288(_DWORD *result, _DWORD **a2, _DWORD *a3)
{
  _DWORD *v3; // r3
  _DWORD *v4; // r4
  _DWORD **v5; // r3

  v3 = (_DWORD *)*result;
  if ( !a2 )
    return (_DWORD *)sub_12D150((int)result, a3);
  if ( v3 )
  {
    v4 = result;
    if ( v3 == a2 )
    {
LABEL_8:
      v5 = (_DWORD **)result[1];
      result = *a2;
      *a3 = *a2;
      *a2 = a3;
      if ( v5 == a2 )
        v4[1] = a3;
    }
    else
    {
      while ( 1 )
      {
        v3 = (_DWORD *)*v3;
        if ( !v3 )
          break;
        if ( a2 == v3 )
          goto LABEL_8;
      }
    }
  }
  return result;
}

