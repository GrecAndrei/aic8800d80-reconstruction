// v23 annotated: sub_13E328 @ 0x13e328
// Original: 13e328_sub_13E328.c
// Primary struct: <unclustered>
//
// sub_13E328 @ 0x13e328, size 440 bytes
int __fastcall sub_13E328(int a1)
{
  int v1; // r4
  int v3; // r8
  int v4; // r3
  int v5; // r9
  int result; // r0
  int v7; // r2
  int v8; // r3
  unsigned __int16 v9; // r7
  unsigned int v10; // r3
  int v11; // r6
  int v12; // r1
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r6
  int v16; // r10
  __int16 v17; // r10
  int v18; // r11
  __int16 v19; // r10
  __int16 v20; // r11
  __int16 v21; // r6

  v1 = *(unsigned __int16 *)(a1 + 184);
  if ( *(_WORD *)(a1 + 184) )
  {
    v3 = v1 - 1;
    v4 = a1;
    do
    {
      *(_WORD *)(v4 + 10) = -1;
      *(_WORD *)(v4 + 4) = 0;
      *(_WORD *)(v4 + 6) = 0;
      *(_WORD *)(v4 + 8) = 0;
      *(_BYTE *)(v4 + 12) = 0;
      *(_BYTE *)(v4 + 13) = 0;
      *(_BYTE *)(v4 + 14) = 1;
      v4 += 12;
    }
    while ( v4 != a1 + 12 + 12 * (unsigned __int16)(v1 - 1) );
    v5 = v1 - 1;
  }
  else
  {
    v5 = -1;
    v3 = -1;
  }
  result = sub_13E2C0((unsigned __int8 *)a1);
  v8 = *(unsigned __int8 *)(a1 + 169);
  *(_WORD *)(a1 + 10) = result;
  switch ( v8 )
  {
    case 0:
    case 1:
      v7 = *(unsigned __int8 *)(a1 + 182);
      v9 = ((_WORD)v8 << 11) | ((_WORD)v7 << 10) | *(unsigned __int8 *)(a1 + 178);
      break;
    case 2:
    case 3:
      v7 = *(unsigned __int8 *)(a1 + 180);
      result = *(unsigned __int8 *)(a1 + 181);
      v9 = ((_WORD)v8 << 11)
         | ((_WORD)result << 9)
         | (*(unsigned __int8 *)(a1 + 179) << 7)
         | (8 * v7)
         | (unsigned __int8)(31 - __clz(*(unsigned __int8 *)(a1 + v7 + 170)));
      break;
    case 4:
      v17 = *(unsigned __int8 *)(a1 + 180);
      v18 = ((int)*(unsigned __int16 *)(a1 + 170) >> (2 * v17)) & 3;
      v19 = 16 * v17;
      v20 = v18 + 7;
      v21 = (*(unsigned __int8 *)(a1 + 179) << 7) | (*(unsigned __int8 *)(a1 + 181) << 9);
      do
      {
        v9 = v19 | v20 | v21 | 0x2000;
        result = sub_13D25C(a1, v9);
        --v20;
      }
      while ( !result && (unsigned __int8)v20 != 6 );
      break;
    case 5:
      v14 = *(unsigned __int8 *)(a1 + 180);
      v15 = 2 * (((int)*(unsigned __int16 *)(a1 + 170) >> (2 * v14)) & 3) + 7;
      v16 = (16 * v14) | (*(unsigned __int8 *)(a1 + 179) << 7);
      do
      {
        v9 = v16 | v15 | 0x2800;
        result = sub_13D25C(a1, v16 | v15 | 0x2800);
        v15 = (unsigned __int16)(v15 - 1);
      }
      while ( !result && (unsigned __int8)v15 != 6 );
      break;
    default:
      v9 = 0;
      break;
  }
  v10 = a1 + 12 * v5;
  v11 = 1;
  *(_WORD *)(v10 + 10) = v9;
  if ( v3 <= 1 )
  {
LABEL_26:
    if ( !v1 )
      return result;
  }
  else
  {
    do
    {
      while ( 1 )
      {
        result = sub_13D694(a1);
        v1 = *(unsigned __int16 *)(a1 + 184);
        if ( *(_WORD *)(a1 + 184) )
          break;
LABEL_25:
        v10 = a1 + 12 * v11;
        v11 = (unsigned __int16)(v11 + 1);
        *(_WORD *)(v10 + 10) = result;
        if ( v11 >= v1 - 1 )
          goto LABEL_26;
      }
      v10 = a1;
      v7 = 0;
      while ( 1 )
      {
        v12 = *(unsigned __int16 *)(v10 + 10);
        ++v7;
        v10 += 12;
        if ( v12 == result )
          break;
        if ( v7 == v1 )
          goto LABEL_25;
      }
    }
    while ( v11 < v1 - 1 );
  }
  v13 = 0;
  do
  {
    result = rate_parse_ht_mcs_n_490(a1, (unsigned __int16)v13, v7, v10);
    v10 = *(unsigned __int16 *)(a1 + 184);
    ++v13;
  }
  while ( v13 < v10 );
  return result;
}

