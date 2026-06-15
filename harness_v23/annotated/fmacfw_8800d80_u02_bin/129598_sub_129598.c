// v23 annotated: sub_129598 @ 0x129598
// Original: 129598_sub_129598.c
// Primary struct: <unclustered>
//
// sub_129598 @ 0x129598, size 606 bytes
int __fastcall sub_129598(int result)
{
  int v1; // r12
  int v2; // r6
  int v3; // r5
  int v4; // r3
  int v5; // r7
  int v6; // r1
  int v7; // r2
  int v8; // lr
  int v9; // r3
  int v10; // r9
  int v11; // r8
  unsigned int v12; // r1
  int v13; // r4
  int v14; // r2
  int v15; // r4
  int v16; // r6
  int v17; // r2
  bool v18; // cf
  int v19; // r3
  int v20; // r1
  unsigned int v21; // r1
  int v22; // r12
  int v23; // r10
  int v24; // r8
  int v25; // r10
  int v26; // [sp+0h] [bp-Ch]
  int v27; // [sp+4h] [bp-8h]

  v1 = 0;
  v2 = result;
  v3 = result + 96;
  v4 = result;
  v5 = 0;
  v6 = 1;
  do
  {
    if ( *(_BYTE *)(v4 + 16) == 2
      && *(unsigned __int8 *)(v4 + 19) <= 1u
      && (!*(_BYTE *)(result + 135) || !*(_BYTE *)(v4 + 33) || *(_BYTE *)(v4 + 32) != 1) )
    {
      v7 = *(_DWORD *)(v4 + 12);
      if ( !v6 )
      {
        v18 = v1 - v7 < 0;
        v7 &= (v1 - v7) >> 31;
        if ( !v18 )
          v7 = v1;
      }
      ++v5;
      v1 = v7;
      v6 = 0;
    }
    v4 += 48;
  }
  while ( v3 != v4 );
  v8 = v6;
  v9 = result;
  v10 = 0;
  v26 = 1;
  v11 = result;
  do
  {
    if ( *(_BYTE *)(v9 + 16) == 2 )
    {
      v12 = *(unsigned __int8 *)(v9 + 19);
      if ( v12 > 1 && (!*(_BYTE *)(v2 + 135) || !*(_BYTE *)(v9 + 33) || *(_BYTE *)(v9 + 32) != 1) )
      {
        v13 = *(_DWORD *)(v9 + 28);
        v14 = *(_DWORD *)(v9 + 12);
        result = v13 + v14 - *(_DWORD *)(v9 + 24);
        if ( !v8 )
        {
          if ( result - v1 >= 0 )
          {
            v18 = v1 - v14 < 0;
            v14 &= (v1 - v14) >> 31;
            if ( !v18 )
              v14 = v1;
          }
          else
          {
            v21 = v12 - 1;
            while ( 1 )
            {
              result = v13 + v13 - *(_DWORD *)(v9 + 24) + v14;
              v14 += v13;
              if ( v13 - *(_DWORD *)(v9 + 24) - v1 + v14 >= 0 )
                break;
              if ( !--v21 )
                goto LABEL_19;
            }
            v18 = v1 - v14 < 0;
            v22 = v1 & ~((v1 - v14) >> 31);
            if ( v18 )
              v22 = v14;
            if ( v21 == 1 )
            {
              result = v10;
              v14 = v22;
              goto LABEL_18;
            }
            v14 = v22;
          }
          if ( !v26 )
          {
            v18 = result - v10 < 0;
            result &= (result - v10) >> 31;
            if ( !v18 )
              result = v10;
            goto LABEL_18;
          }
        }
        v26 = 0;
LABEL_18:
        ++v5;
        v10 = result;
        v1 = v14;
        v8 = 0;
      }
    }
LABEL_19:
    v9 += 48;
  }
  while ( v3 != v9 );
  v27 = v2;
  v15 = v11;
  v16 = v26;
  do
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(v15 + 16) != 1 )
        goto LABEL_28;
      v19 = *(_DWORD *)(v15 + 12);
      v20 = *(_DWORD *)(v15 + 24) + v19;
      if ( v8 )
        break;
      if ( !v5 )
      {
        if ( v20 - v10 < 0 )
        {
          v10 = *(_DWORD *)(v15 + 12);
          v1 = *(_DWORD *)(v15 + 24) + v19;
        }
        else if ( v1 - v19 >= 0 )
        {
          result = v19 - v10;
          v17 = v1 - v20;
          v18 = v19 - v10 < 0;
          v10 &= ~((v19 - v10) >> 31);
          if ( v18 )
            v10 = *(_DWORD *)(v15 + 12);
          v1 &= ~(v17 >> 31);
          if ( v17 < 0 )
            v1 = *(_DWORD *)(v15 + 24) + v19;
        }
        goto LABEL_28;
      }
      if ( v20 - v1 >= 0 )
      {
        result = *(unsigned __int8 *)(v15 + 19);
        v23 = *(_DWORD *)(v15 + 12);
        v24 = *(_DWORD *)(v15 + 24) + v19;
      }
      else
      {
        result = *(unsigned __int8 *)(v15 + 19) - 1;
        if ( !*(_BYTE *)(v15 + 19) )
          goto LABEL_28;
        v23 = *(_DWORD *)(v15 + 12);
        while ( 1 )
        {
          v23 += *(_DWORD *)(v15 + 28);
          v24 = *(_DWORD *)(v15 + 24) + v23;
          if ( v24 - v1 >= 0 )
            break;
          if ( !result )
            goto LABEL_28;
          --result;
        }
      }
      if ( v16 )
      {
        if ( v1 - v23 < 0 )
        {
          v10 = v23;
          v16 = 0;
        }
        else
        {
          v1 = v24;
          if ( result )
          {
            v10 = v23 + *(_DWORD *)(v15 + 28);
            v16 = 0;
          }
        }
        goto LABEL_28;
      }
      if ( v10 - v23 >= 0 )
      {
        if ( v1 - v23 < 0 )
        {
          v10 = v23;
          v8 = 0;
          goto LABEL_28;
        }
        if ( v24 - v10 < 0 )
        {
          if ( result <= 1 )
          {
            v1 = v24;
            v8 = 0;
          }
          else
          {
            v25 = v23 + *(_DWORD *)(v15 + 28);
            v1 = v24;
            v18 = v25 - v10 < 0;
            v10 &= ~((v25 - v10) >> 31);
            if ( v18 )
              v10 = v25;
            v8 = 0;
          }
          goto LABEL_28;
        }
        if ( **(__int16 **)off_1297F8 < 0 )
          result = sub_12F49C(dword_129800, dword_1297FC, 347);
        v1 = v24;
        v10 = v23 + *(_DWORD *)(v15 + 28);
      }
      v8 = 0;
LABEL_28:
      v15 += 48;
      if ( v3 == v15 )
        goto LABEL_32;
    }
    v15 += 48;
    v16 = 0;
    v10 = v19;
    v1 = v20;
    v8 = 0;
  }
  while ( v3 != v15 );
LABEL_32:
  *(_DWORD *)(v27 + 128) = v1;
  if ( v16 )
    v10 = v1 + 10;
  *(_DWORD *)(v27 + 124) = v10;
  return result;
}

