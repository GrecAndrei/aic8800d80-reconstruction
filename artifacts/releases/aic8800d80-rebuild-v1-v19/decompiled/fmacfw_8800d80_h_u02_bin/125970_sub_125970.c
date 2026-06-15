// sub_125970 @ 0x125970, size 496 bytes
int __fastcall sub_125970(int result)
{
  int *v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r5
  int v5; // r9
  unsigned __int8 *v6; // r4
  int v7; // r7
  _DWORD *v8; // r10
  int v9; // r8
  int v10; // r5
  unsigned int v11; // r3
  bool v12; // cc
  int v13; // r2
  int v14; // r2
  int v15; // r1
  _BYTE *v16; // r10
  int v17; // r7
  _BYTE *v18; // r11
  int v19; // r5
  int v20; // r0
  int v21; // r8
  int i; // r10
  int v23; // r0
  int v24; // r2
  _BYTE *v25; // r0
  int v26; // r8
  int v27; // r0
  int v28; // r2
  int v29; // r1
  int v30; // r2

  v1 = (int *)off_125B64;
  v2 = *((_DWORD *)off_125B64 + 1);
  v3 = result;
  if ( **(__int16 **)off_125B60 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *((_DWORD *)off_125B64 + 1) = v4;
    if ( !v4 )
    {
LABEL_20:
      v16 = off_125B90;
      sub_121B7C();
      v17 = *(unsigned __int8 *)(v3 + 107) + 32;
      if ( *v16 )
      {
        v25 = (_BYTE *)sub_12C7EC(74, 13, v4, 4);
        *v25 = v17;
        v25[1] = v4;
        v25[2] = v4;
        sub_12C84C(v25);
        v5 = dword_125B68;
        if ( *v16 )
        {
          v26 = dword_125B68 + 696 * v17;
          if ( (*(_BYTE *)(v26 + 53) & 2) != 0 )
          {
            *(_BYTE *)(v26 + 54) = 9;
            sub_11F28C(v3, v5 + 696 * v17, v4);
            *(_BYTE *)(v26 + 54) = v4;
          }
          *v16 = 0;
        }
      }
      else
      {
        v5 = dword_125B68;
      }
      v18 = off_125B94;
      if ( *(_BYTE *)off_125B94 )
      {
        v21 = v5 + 696 * v17;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(_DWORD *)(v21 + 584) )
          {
            v23 = sub_12D190(v21 + 584);
            sub_13AA68(v23, (unsigned __int8)i, v24);
          }
          if ( *(_DWORD *)(v21 + 624) )
          {
            v27 = sub_12D190(v5 + 8 * (87 * v17 + 78 + i));
            sub_13AA68(v27, (unsigned __int8)i, v28);
            sub_12E948(dword_125B84, v29, v30);
            while ( 1 )
              ;
          }
          v21 += 8;
        }
        *v18 = 0;
      }
      if ( *((_BYTE *)v1 + 10) )
        sub_125904(*v1);
      if ( v1[3] )
      {
        v19 = dword_125B80;
        do
        {
          v20 = sub_12D190(v19);
          sub_125184((unsigned __int16 *)(v20 + 12));
        }
        while ( v1[3] );
      }
      result = *(unsigned __int8 *)(v3 + 107);
      if ( *((_BYTE *)v1 + result + 20) && !v1[1] )
        result = sub_124EFC(result, *((unsigned __int8 *)v1 + result + 20));
      if ( *(_BYTE *)(v3 + 231) == 1 )
        result = sub_1201D4(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = sub_12F32C(dword_125B7C, dword_125B78, 764);
    v4 = v1[1] - 1;
    v1[1] = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125B68;
LABEL_4:
  v6 = (unsigned __int8 *)dword_125B68;
  v7 = dword_125B6C;
  v8 = off_125B88;
  v9 = dword_125B8C;
  v10 = dword_125B68 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[37] && v3 == v7 + 1320 * v6[34] )
      {
        v11 = v6[35];
        v12 = v11 > 0x23;
        if ( v11 > 0x23 )
        {
          v13 = 0;
        }
        else
        {
          v13 = 696;
          v11 = v5 + 696 * v11;
        }
        if ( !v12 )
          v13 = *(_DWORD *)(v11 + 664);
        if ( v9 - v8[4] + v13 < 0 )
        {
          result = sub_116DBC(v3);
          if ( result )
          {
            result = sub_118C84(v6[35], (int)off_125B70, (int)v6);
            if ( !result )
              break;
          }
        }
      }
      v6 += 696;
      if ( v6 == (unsigned __int8 *)v10 )
        return result;
    }
    v15 = v6[35];
    v6 += 696;
    result = sub_12E948(dword_125B74, v15, v14);
  }
  while ( v6 != (unsigned __int8 *)v10 );
  return result;
}

