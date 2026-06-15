// v23 annotated: sub_1096D0 @ 0x1096d0
// Original: 1096d0_sub_1096D0.c
// Primary struct: <unclustered>
//
// sub_1096D0 @ 0x1096d0, size 690 bytes
int __fastcall sub_1096D0(int a1, __int16 *a2)
{
  unsigned int v2; // r2
  __int16 *v3; // r8
  __int16 *v4; // r4
  unsigned int v5; // r7
  int v6; // r12
  int result; // r0
  int v8; // t1
  char v9; // r6
  int v10; // r3
  int v11; // r2
  char v12; // r4
  char v13; // r5
  int v14; // r9
  int v15; // r7
  char v16; // lr
  int v17; // r8
  int v18; // r2
  int v19; // r3
  int v20; // r7
  int v21; // r10
  char v22; // r2
  int v23; // r2
  int v24; // r8
  int v25; // r7
  int v26; // r3
  int v27; // r3
  int v28; // r4
  int v29; // r2
  int v30; // r2
  int j; // r3
  __int16 *v32; // r3
  __int16 *v33; // r1
  int v34; // t1
  int v35; // r4
  int v36; // r2
  int i; // r3
  unsigned int v38; // r3
  int v39; // r4
  __int16 *v40; // r1
  unsigned __int8 v41; // [sp+1h] [bp-27h]
  __int16 v42; // [sp+2h] [bp-26h]

  if ( !a1 )
  {
    v32 = a2 - 1;
    result = 128;
    v33 = a2 + 5;
    do
    {
      v34 = v32[1];
      ++v32;
      if ( v34 < 0 )
        *v32 = 128;
    }
    while ( v33 != v32 );
    return result;
  }
  v2 = 0;
  v3 = a2 - 1;
  v4 = a2 - 1;
  v5 = 0;
  v6 = 0;
  result = 0;
  while ( 1 )
  {
    v8 = v4[1];
    ++v4;
    v9 = v2;
    if ( v8 < 0 )
      break;
    if ( (unsigned __int8)v2 == 5 )
      goto LABEL_8;
LABEL_4:
    ++v2;
  }
  result = (unsigned __int8)((1 << v2) | result);
  if ( v2 <= 1 )
  {
    v6 = (unsigned __int8)(v6 + 1);
    goto LABEL_4;
  }
  v5 = (unsigned __int8)(v5 + 1);
  if ( (unsigned __int8)v2 != 5 )
    goto LABEL_4;
LABEL_8:
  if ( v5 == 4 )
  {
    if ( v6 == 2 )
    {
      v40 = a2 + 5;
      do
      {
        v3[1] = 128;
        ++v3;
      }
      while ( v3 != v40 );
      return result;
    }
  }
  else if ( v5 <= 2 )
  {
    if ( !v6 )
    {
      v10 = a2[1];
      v11 = *a2;
      if ( v10 + 9 < v11 || v11 < v10 - 9 )
        a2[1] = v11;
    }
    v12 = 3;
    v41 = 3;
    v42 = 1284;
    if ( a2[2] < a2[3] )
    {
      v13 = 2;
      v41 = 2;
      v14 = 2;
      v15 = 3;
      if ( a2[4] >= a2[5] )
        goto LABEL_48;
LABEL_16:
      v42 = 1029;
      v16 = 5;
      v17 = 4;
      v9 = 4;
      v18 = 5;
    }
    else
    {
      v13 = 3;
      v14 = 3;
      v15 = 2;
      v12 = 2;
      if ( a2[4] < a2[5] )
        goto LABEL_16;
LABEL_48:
      v17 = 5;
      v18 = 4;
      v16 = 4;
    }
    v19 = a2[v15];
    v20 = a2[v18];
    if ( v19 < v20 )
    {
      v21 = a2[v18];
      v22 = v16;
      LOBYTE(v42) = v12;
      v20 = v19;
      v16 = v12;
      v19 = v21;
      v12 = v22;
    }
    v23 = a2[v14];
    v24 = a2[v17];
    if ( v23 < v24 )
    {
      HIBYTE(v42) = v13;
      v41 = v9;
      v23 = v24;
      v13 = v9;
    }
    if ( v20 > v23 )
    {
      LOBYTE(v42) = v13;
      v41 = v16;
      v23 = v20;
      v13 = v16;
    }
    v25 = a2[(unsigned __int8)v42];
    if ( v19 > v23 + 7 )
      v26 = 0;
    else
      v26 = 4;
    if ( a2[v41] <= v25 + 7 )
      v26 |= 2u;
    if ( a2[HIBYTE(v42)] + 7 >= v25 )
      v26 |= 1u;
    switch ( v26 )
    {
      case 0:
      case 5:
        if ( !v6 )
          result |= 0x3Cu;
        break;
      case 1:
        result = (unsigned __int8)(result | (1 << v12) | (1 << v13));
        break;
      case 2:
        result = (unsigned __int8)(result | (1 << SHIBYTE(v42)) | (1 << v12));
        break;
      case 3:
        result = (unsigned __int8)(result | (1 << v12));
        break;
      case 4:
        result = (unsigned __int8)(result | (1 << v42) | (1 << SHIBYTE(v42)));
        break;
      case 6:
        result = (unsigned __int8)(result | (1 << SHIBYTE(v42)));
        break;
      default:
        break;
    }
    v35 = 0;
    v36 = 0;
    for ( i = 2; i != 6; ++i )
    {
      if ( ((result >> i) & 1) == 0 )
      {
        v35 = (unsigned __int8)(v35 + 1);
        v36 = (__int16)(v36 + a2[i]);
      }
    }
    if ( !v35 )
    {
      if ( (result & 1) == 0 )
      {
        v36 = (__int16)(v36 + *a2);
        v35 = 1;
      }
      if ( (result & 2) == 0 )
      {
        v35 = (unsigned __int8)(v35 + 1);
        v36 = (__int16)(a2[1] + v36);
      }
    }
    v38 = 0;
    v39 = v36 / v35;
    while ( 2 )
    {
      if ( ((result >> v38) & 1) != 0 )
      {
        if ( v38 > 1 || v6 == 2 )
        {
          a2[v38] = v39;
          goto LABEL_65;
        }
      }
      else
      {
LABEL_65:
        if ( (unsigned __int8)v38 == 5 )
        {
          if ( v6 == 1 )
          {
            if ( (result & 1) != 0 )
            {
              *a2 = a2[1];
            }
            else if ( (result & 2) != 0 )
            {
              a2[1] = *a2;
            }
          }
          return result;
        }
      }
      ++v38;
      continue;
    }
  }
  v27 = 0;
  v28 = 0;
  v29 = 0;
  do
  {
    if ( ((result >> v27) & 1) == 0 )
    {
      v28 = (unsigned __int8)(v28 + 1);
      v29 = (__int16)(v29 + a2[v27]);
    }
    ++v27;
  }
  while ( v27 != 6 );
  v30 = v29 / v28;
  for ( j = 0; j != 6; ++j )
  {
    if ( ((result >> j) & 1) != 0 )
      a2[j] = v30;
  }
  return result;
}

