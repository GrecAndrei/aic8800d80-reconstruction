// v23 annotated: sub_1438A4 @ 0x1438a4
// Original: 1438a4_sub_1438A4.c
// Primary struct: <unclustered>
//
// sub_1438A4 @ 0x1438a4, size 214 bytes
unsigned int __fastcall sub_1438A4(unsigned int result, unsigned int a2, unsigned int a3)
{
  _BYTE *v3; // r3
  unsigned int v4; // r2
  char v5; // t1
  unsigned int v6; // r3
  unsigned int v7; // r4
  _BYTE *v8; // r4
  unsigned int v9; // r3
  char v10; // t1
  _BYTE *v11; // r4
  unsigned int v12; // r5
  unsigned int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r12
  unsigned int v17; // r4
  int *v18; // r6
  int v19; // t1

  if ( result <= a2 || (v3 = (_BYTE *)(a2 + a3), a2 + a3 <= result) )
  {
    if ( a3 > 0xF )
    {
      if ( (result | a2) << 30 )
      {
        v7 = a3 - 1;
        v6 = result;
LABEL_10:
        v8 = (_BYTE *)(v7 + 1 + a2);
        v9 = v6 - 1;
        do
        {
          v10 = *(_BYTE *)a2++;
          *(_BYTE *)++v9 = v10;
        }
        while ( (_BYTE *)a2 != v8 );
        return result;
      }
      v11 = (_BYTE *)(a2 + 16);
      v12 = result + 16;
      do
      {
        *(_DWORD *)(v12 - 16) = *((_DWORD *)v11 - 4);
        *(_DWORD *)(v12 - 12) = *((_DWORD *)v11 - 3);
        *(_DWORD *)(v12 - 8) = *((_DWORD *)v11 - 2);
        *(_DWORD *)(v12 - 4) = *((_DWORD *)v11 - 1);
        v11 += 16;
        v12 += 16;
      }
      while ( v11 != (_BYTE *)(a2 + 32 + ((a3 - 16) & 0xFFFFFFF0)) );
      v13 = ((a3 - 16) >> 4) + 1;
      a2 += 16 * v13;
      v6 = result + 16 * v13;
      if ( (a3 & 0xC) != 0 )
      {
        v14 = (a3 & 0xF) - 4;
        v15 = v14 >> 2;
        v16 = (v14 & 0xFFFFFFFC) + v6;
        v17 = v6 - 4;
        v18 = (int *)a2;
        do
        {
          v19 = *v18++;
          *(_DWORD *)(v17 + 4) = v19;
          v17 += 4;
        }
        while ( v17 != v16 );
        v6 += 4 * (v15 + 1);
        a2 += 4 * (v15 + 1);
        a3 &= 3u;
      }
      else
      {
        a3 &= 0xFu;
      }
    }
    else
    {
      v6 = result;
    }
    v7 = a3 - 1;
    if ( !a3 )
      return result;
    goto LABEL_10;
  }
  if ( a3 )
  {
    v4 = result + a3;
    do
    {
      v5 = *--v3;
      *(_BYTE *)--v4 = v5;
    }
    while ( (_BYTE *)a2 != v3 );
  }
  return result;
}

