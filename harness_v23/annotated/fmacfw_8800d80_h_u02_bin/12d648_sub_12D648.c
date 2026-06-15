// v23 annotated: sub_12D648 @ 0x12d648
// Original: 12d648_sub_12D648.c
// Primary struct: <unclustered>
//
// sub_12D648 @ 0x12d648, size 150 bytes
unsigned __int8 *__fastcall sub_12D648(unsigned __int8 *a1, int a2, unsigned __int8 *a3, int a4, _WORD *a5)
{
  unsigned int v5; // r9
  unsigned int v6; // r7
  int v7; // lr
  unsigned __int8 *v8; // r5
  int v9; // r4
  int v10; // r3
  unsigned __int8 *v11; // r8
  unsigned __int8 *v13; // r4
  unsigned __int8 *v14; // r9
  int v15; // t1

  v5 = (unsigned int)&a1[a2];
  v6 = (unsigned int)&a1[a2];
  if ( a1 >= &a1[a2] )
  {
LABEL_15:
    if ( **(__int16 **)off_12D6E0 < 0 && (unsigned __int8 *)v6 != a1 )
      sub_12F32C(dword_12D6E8, dword_12D6E4, 180);
  }
  else
  {
    v7 = a4 + 2;
    v8 = &a3[a4];
    while ( 1 )
    {
      v11 = a1;
      if ( v5 <= (unsigned int)(a1 + 1) )
        break;
      v9 = *a1;
      v10 = a1[1] + 2;
      a1 += v10;
      if ( v9 == 221 )
      {
        if ( v5 < (unsigned int)a1 )
          return nullptr;
        *a5 = v10;
        if ( !v11 || (unsigned int)&v11[v7] > v6 )
          return nullptr;
        v13 = a3;
        while ( 1 )
        {
          v14 = &v11[(_DWORD)v13];
          v15 = *v13++;
          if ( v15 != v14[2 - (_DWORD)a3] )
            break;
          if ( v13 == v8 )
            return v11;
        }
        a2 = (unsigned __int16)(a2 - v10);
        if ( v6 <= (unsigned int)a1 )
          goto LABEL_15;
        v5 = (unsigned int)&a1[a2];
      }
    }
  }
  return nullptr;
}

