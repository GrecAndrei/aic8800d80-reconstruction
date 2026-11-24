// sub_12F648 @ 0x12f648, size 136 bytes
_DWORD *__fastcall sub_12F648(int a1, _DWORD *a2, int a3)
{
  int v5; // r0
  int v6; // r11
  int v7; // r9
  _DWORD *v8; // r4
  int v9; // r5
  int v10; // r6
  _DWORD *v11; // r10

  v5 = sub_143878(a1, 46);
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = sub_143D00(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
        if ( !sub_143DDC(a1, *v8, v6) )
          break;
        v8 += 4;
        if ( a3 == v9 )
          goto LABEL_9;
      }
      if ( sub_143D00(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
LABEL_9:
    if ( v7 == 1 )
      return a2;
  }
  return nullptr;
}

