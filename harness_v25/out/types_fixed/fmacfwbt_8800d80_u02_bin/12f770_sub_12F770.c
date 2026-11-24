// sub_12F770 @ 0x12f770, size 48 bytes
_DWORD **__fastcall sub_12F770(_DWORD **result)
{
  _DWORD *v1; // r4
  int v2; // r6
  _DWORD *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F7A0;
    v3 = result;
    do
    {
      while ( 1 )
      {
        sub_12D4F8((int)v3);
        result = (_DWORD **)v2;
        if ( !*(_DWORD *)(v1 + 0xc) )
          break;
        result = (_DWORD **)list_push_tail(v2, v1);
        v1 = (_DWORD *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = *(_DWORD *)(v1 + 0x8);
      v1 = (_DWORD *)*v3;
      *(_WORD *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

