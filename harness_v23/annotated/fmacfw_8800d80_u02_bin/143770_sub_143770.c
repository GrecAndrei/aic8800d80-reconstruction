// v23 annotated: sub_143770 @ 0x143770
// Original: 143770_sub_143770.c
// Primary struct: <unclustered>
//
// sub_143770 @ 0x143770, size 308 bytes
char *__fastcall sub_143770(char *a1, char *a2, unsigned int a3)
{
  char *v3; // r12
  bool v4; // cf
  unsigned int i; // r2
  int *v6; // r1
  int v7; // t1
  _DWORD *v8; // r0
  int v9; // t1
  int v10; // t1
  int v11; // t1
  int v12; // t1
  int v13; // t1
  int v14; // t1
  int v15; // t1
  int v16; // t1
  int v17; // t1
  int v18; // t1
  int v19; // t1
  int v20; // t1
  int v21; // t1
  int v22; // t1
  int v23; // t1
  unsigned int j; // r2
  int *v25; // r1
  int v26; // t1
  _DWORD *v27; // r0
  int v28; // t1
  int v29; // t1
  int v30; // t1
  unsigned int k; // r2
  int v32; // t1
  unsigned int v33; // r2
  char v34; // t1
  int v36; // r3
  char v37; // t1
  __int16 v38; // t1
  char v39; // t1

  v3 = a1;
  if ( (((unsigned __int8)a2 | (unsigned __int8)a1) & 3) == 0 )
  {
LABEL_2:
    v4 = a3 >= 0x40;
    for ( i = a3 - 64; v4; i -= 64 )
    {
      v7 = *(_DWORD *)a2;
      v6 = (int *)(a2 + 4);
      *(_DWORD *)a1 = v7;
      v8 = a1 + 4;
      v9 = *v6++;
      *v8++ = v9;
      v10 = *v6++;
      *v8++ = v10;
      v11 = *v6++;
      *v8++ = v11;
      v12 = *v6++;
      *v8++ = v12;
      v13 = *v6++;
      *v8++ = v13;
      v14 = *v6++;
      *v8++ = v14;
      v15 = *v6++;
      *v8++ = v15;
      v16 = *v6++;
      *v8++ = v16;
      v17 = *v6++;
      *v8++ = v17;
      v18 = *v6++;
      *v8++ = v18;
      v19 = *v6++;
      *v8++ = v19;
      v20 = *v6++;
      *v8++ = v20;
      v21 = *v6++;
      *v8++ = v21;
      v22 = *v6++;
      *v8++ = v22;
      v23 = *v6;
      a2 = (char *)(v6 + 1);
      *v8 = v23;
      a1 = (char *)(v8 + 1);
      v4 = i >= 0x40;
    }
    v4 = __CFADD__(i, 48);
    for ( j = i + 48; v4; j -= 16 )
    {
      v26 = *(_DWORD *)a2;
      v25 = (int *)(a2 + 4);
      *(_DWORD *)a1 = v26;
      v27 = a1 + 4;
      v28 = *v25++;
      *v27++ = v28;
      v29 = *v25++;
      *v27++ = v29;
      v30 = *v25;
      a2 = (char *)(v25 + 1);
      *v27 = v30;
      a1 = (char *)(v27 + 1);
      v4 = j >= 0x10;
    }
    v4 = __CFADD__(j, 12);
    for ( k = j + 12; v4; k -= 4 )
    {
      v32 = *(_DWORD *)a2;
      a2 += 4;
      *(_DWORD *)a1 = v32;
      a1 += 4;
      v4 = k >= 4;
    }
    goto LABEL_11;
  }
  if ( a3 >= 8 )
  {
    if ( (_DWORD)a2 << 30 && ((unsigned __int8)a1 & 3) != 0 )
    {
      v36 = 4 - ((unsigned __int8)a1 & 3);
      a3 -= v36;
      if ( v36 << 31 )
      {
        v37 = *a2++;
        *a1++ = v37;
      }
      if ( __CFSHL__(v36, 31) )
      {
        v38 = *(_WORD *)a2;
        a2 += 2;
        *(_WORD *)a1 = v38;
        a1 += 2;
      }
    }
    goto LABEL_2;
  }
  v4 = a3 >= 4;
  k = a3 - 4;
  if ( v4 )
  {
    do
    {
      v4 = k-- != 0;
      v39 = *a2++;
      *a1++ = v39;
    }
    while ( v4 );
    *a1 = *a2;
    a1[1] = a2[1];
    a1[2] = a2[2];
    return v3;
  }
LABEL_11:
  v33 = k + 4;
  if ( v33 )
  {
    if ( v33 << 31 )
    {
      v34 = *a2++;
      *a1++ = v34;
    }
    if ( __CFSHL__(v33, 31) )
      *(_WORD *)a1 = *(_WORD *)a2;
  }
  return v3;
}

