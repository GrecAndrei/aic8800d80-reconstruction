// fwstruct annotate: 1251a0_sub_1251A0.c
// sub_1251A0 @ 0x1251a0, size 30 bytes
int __fastcall sub_1251A0(_DWORD *a1)
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

