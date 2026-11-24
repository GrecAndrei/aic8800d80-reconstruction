// sub_12D1A8 @ 0x12d1a8, size 90 bytes
int __fastcall sub_12D1A8(int result, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r3

  v2 = result;
  if ( **(__int16 **)off_12D204 < 0 && !result )
    result = sub_12F32C(dword_12D20C, dword_12D208, 132);
  v4 = *(_DWORD **)v2;
  if ( *(_DWORD *)v2 )
  {
    if ( v4 == a2 )
    {
      v6 = *(_DWORD **)(v2 + 4);
      *(_DWORD *)v2 = *a2;
      if ( v6 == a2 )
        *(_DWORD *)(v2 + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 = (_DWORD *)*v4;
        if ( !v4 )
          break;
        if ( v4 == a2 )
        {
          if ( *(_DWORD **)(v2 + 4) == a2 )
            *(_DWORD *)(v2 + 4) = v5;
          *v5 = *a2;
          return result;
        }
      }
    }
  }
  return result;
}

