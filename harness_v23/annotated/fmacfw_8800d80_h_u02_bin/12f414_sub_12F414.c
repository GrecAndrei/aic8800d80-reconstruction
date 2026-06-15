// v23 annotated: sub_12F414 @ 0x12f414
// Original: 12f414_sub_12F414.c
// Primary struct: <unclustered>
//
// sub_12F414 @ 0x12f414, size 48 bytes
_DWORD **__fastcall sub_12F414(_DWORD **result)
{
  _DWORD *v1; // r4
  int v2; // r6
  _DWORD *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F444;
    v3 = result;
    do
    {
      while ( 1 )
      {
        sub_12D190((int)v3);
        result = (_DWORD **)v2;
        if ( !v1[3] )
          break;
        result = (_DWORD **)sub_12D108(v2, v1);
        v1 = (_DWORD *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = v1[2];
      v1 = (_DWORD *)*v3;
      *(_WORD *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

