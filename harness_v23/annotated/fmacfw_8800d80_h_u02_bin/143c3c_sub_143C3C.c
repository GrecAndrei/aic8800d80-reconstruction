// v23 annotated: sub_143C3C @ 0x143c3c
// Original: 143c3c_sub_143C3C.c
// Primary struct: <unclustered>
//
// sub_143C3C @ 0x143c3c, size 186 bytes
unsigned int __fastcall sub_143C3C(unsigned int result, unsigned int a2)
{
  _BYTE *v2; // r12
  int *v3; // r1
  int v4; // r3
  int v5; // t1
  int v6; // t1
  int *v7; // r1
  int v8; // r4
  int v9; // t1
  int v10; // r2
  int v11; // t1
  int v12; // t1
  __int16 v13; // r2
  __int16 v14; // t1
  bool v15; // zf
  int v16; // t1

  v2 = (_BYTE *)result;
  if ( ((result ^ a2) & 3) != 0 )
  {
    do
    {
      v16 = *(unsigned __int8 *)a2++;
      *v2++ = v16;
    }
    while ( v16 );
  }
  else
  {
    if ( (a2 & 3) == 0 )
      goto LABEL_3;
    if ( (a2 & 1) == 0 || (v12 = *(unsigned __int8 *)a2, ++a2, *(_BYTE *)result = v12, v2 = (_BYTE *)(result + 1), v12) )
    {
      if ( (a2 & 2) == 0
        || ((v14 = *(_WORD *)a2, a2 += 2, v13 = v14, v15 = (unsigned __int8)v14 == 0, !(_BYTE)v14)
          ? (_BYTE *)(*v2 = v13)
          : (*(_WORD *)v2 = v13, v2 += 2),
            !v15 && (v13 & 0xFF00) != 0) )
      {
LABEL_3:
        v15 = (a2 & 4) == 0;
        v5 = *(_DWORD *)a2;
        v3 = (int *)(a2 + 4);
        v4 = v5;
        if ( v15 )
          goto LABEL_7;
        if ( ((v4 - 16843009) & ~v4 & 0x80808080) == 0 )
        {
          *(_DWORD *)v2 = v4;
          v2 += 4;
          v6 = *v3++;
          v4 = v6;
LABEL_7:
          while ( 1 )
          {
            v9 = *v3;
            v7 = v3 + 1;
            v8 = v9;
            v10 = v9 - 16843009;
            if ( ((v4 - 16843009) & ~v4 & 0x80808080) != 0 )
              break;
            *(_DWORD *)v2 = v4;
            v2 += 4;
            if ( (v10 & ~v8 & 0x80808080) != 0 )
            {
              v4 = v8;
              goto LABEL_11;
            }
            v11 = *v7;
            v3 = v7 + 1;
            v4 = v11;
            *(_DWORD *)v2 = v8;
            v2 += 4;
          }
        }
        do
        {
LABEL_11:
          *v2++ = v4;
          v15 = (unsigned __int8)v4 == 0;
          v4 = __ROR4__(v4, 8);
        }
        while ( !v15 );
      }
    }
  }
  return result;
}

