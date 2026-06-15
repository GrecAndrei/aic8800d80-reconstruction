// v23 annotated: sub_11E7C4 @ 0x11e7c4
// Original: 11e7c4_sub_11E7C4.c
// Primary struct: <unclustered>
//
// sub_11E7C4 @ 0x11e7c4, size 90 bytes
int __fastcall sub_11E7C4(int result, _DWORD *a2)
{
  int v2; // r5
  _DWORD *v4; // r3
  _DWORD *v5; // r2
  _DWORD *v6; // r3

  v2 = result;
  if ( **(__int16 **)off_11E820 < 0 && !result )
    result = sub_1219C4(dword_11E828, dword_11E824, 132);
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

