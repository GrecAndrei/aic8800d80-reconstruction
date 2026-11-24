// sub_130DB8 @ 0x130db8, size 140 bytes
_BYTE *__fastcall sub_130DB8(_BYTE *a1, int a2, _BYTE *a3)
{
  _BYTE *result; // r0
  int v7; // r4
  unsigned __int8 *v8; // r3
  unsigned __int8 *v9; // r0
  int v10; // r5
  unsigned __int8 *v11; // r1
  unsigned __int8 *v12; // r7
  int v13; // r2
  unsigned int v14; // r3
  unsigned __int8 v15; // [sp+7h] [bp-1h] BYREF

  result = sub_12D89C(a1, a2, &v15);
  if ( result )
  {
    v7 = v15;
    v8 = result + 2;
    if ( v15 )
    {
      v9 = &result[v15 + 2];
      v7 = 0;
      do
      {
        v10 = *v8++;
        if ( (v10 & 0xFFFFFF7E) != 0x7E )
        {
          a3[v7 + 1] = v10;
          v7 = (unsigned __int8)(v7 + 1);
        }
      }
      while ( v9 != v8 );
    }
    result = sub_12D8DC(a1, a2, &v15);
    if ( result )
    {
      v11 = result + 2;
      if ( v15 )
      {
        v12 = &result[v15 + 2];
        do
        {
          v13 = *v11;
          result = (_BYTE *)(v13 & 0xFFFFFF7E);
          ++v11;
          v14 = (unsigned __int8)(v7 + 1);
          if ( (v13 & 0xFFFFFF7E) != 0x7E )
          {
            a3[v7 + 1] = v13;
            v7 = (unsigned __int8)(v7 + 1);
            if ( v14 > 0xB )
              break;
          }
        }
        while ( v12 != v11 );
      }
    }
    *a3 = v7;
  }
  else
  {
    *a3 = 0;
  }
  return result;
}

