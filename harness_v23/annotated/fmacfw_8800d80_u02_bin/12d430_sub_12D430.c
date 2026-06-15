// v23 annotated: sub_12D430 @ 0x12d430
// Original: 12d430_sub_12D430.c
// Primary struct: <unclustered>
//
// sub_12D430 @ 0x12d430, size 48 bytes
_DWORD *__fastcall sub_12D430(_DWORD *result, _DWORD *a2)
{
  _DWORD *v3; // r1
  _DWORD *v4; // r2
  int v5; // r1

  v3 = (_DWORD *)*a2;
  if ( v3 )
  {
    v4 = result;
    if ( *result )
    {
      result = (_DWORD *)a2[1];
      *(_DWORD *)v4[1] = v3;
      v4[1] = result;
    }
    else
    {
      result = (_DWORD *)*a2;
      v5 = a2[1];
      *v4 = *a2;
      v4[1] = v5;
    }
    *a2 = 0;
  }
  return result;
}

