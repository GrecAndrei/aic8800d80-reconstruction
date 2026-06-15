// v23 annotated: sub_127BF4 @ 0x127bf4
// Original: 127bf4_sub_127BF4.c
// Primary struct: <unclustered>
//
// sub_127BF4 @ 0x127bf4, size 190 bytes
int __fastcall sub_127BF4(unsigned __int8 *a1, _BYTE *a2)
{
  int v2; // r6
  int v5; // r3
  int i; // r5
  int v7; // r0
  char v8; // r6
  int v9; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  int v13; // r0
  _DWORD *v14; // r1
  __int16 v15; // lr
  int v16; // r2

  v2 = dword_127CB4;
  v5 = dword_127CB4;
  for ( i = 0; i != 3; ++i )
  {
    if ( *(unsigned __int8 *)(v5 + 24) != 255
      && *(unsigned __int8 *)(v5 + 4) == *a1
      && *(unsigned __int16 *)(v5 + 6) == *((unsigned __int16 *)a1 + 1) )
    {
      v11 = *(unsigned __int8 *)(v5 + 5);
      v12 = a1[1];
      if ( v11 == v12 )
      {
        if ( *(unsigned __int16 *)(v5 + 8) == *((unsigned __int16 *)a1 + 2)
          && *(unsigned __int16 *)(v5 + 10) == *((unsigned __int16 *)a1 + 3) )
        {
          goto LABEL_16;
        }
      }
      else
      {
        if ( v11 < v12 && v11 != 3 )
        {
          v13 = dword_127CB4 + 28 * i;
          v14 = off_127CB8;
          *(_BYTE *)(v13 + 5) = v12;
          v15 = *((_WORD *)a1 + 2);
          *(_WORD *)(v13 + 10) = *((_WORD *)a1 + 3);
          v16 = v14[10];
          *(_WORD *)(v13 + 8) = v15;
          if ( v16 == v13 && *((_BYTE *)v14 + 90) == 1 )
            sub_102970((unsigned __int16 *)(v2 + 28 * i + 4), 0);
LABEL_16:
          *a2 = i;
          return 0;
        }
        if ( v11 > v12 && v12 != 3 )
          goto LABEL_16;
      }
    }
    v5 += 28;
  }
  v7 = sub_12D190(off_127CB8);
  if ( !v7 )
    return 1;
  v8 = dword_127CBC * ((v7 - v2) >> 2);
  *(_BYTE *)(v7 + 24) = v8;
  *a2 = v8;
  v9 = *((_DWORD *)a1 + 1);
  *(_DWORD *)(v7 + 4) = *(_DWORD *)a1;
  *(_DWORD *)(v7 + 8) = v9;
  *(_WORD *)(v7 + 12) = *((_WORD *)a1 + 4);
  return 0;
}

