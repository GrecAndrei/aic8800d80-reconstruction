// fwstruct annotate: 126e1c_sub_126E1C.c
// sub_126E1C @ 0x126e1c, size 484 bytes
int sub_126E1C()
{
  _DWORD *v0; // r5
  _DWORD *v1; // r6
  int v2; // r4
  _BYTE *v3; // r0
  int v4; // r3
  __int16 v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  unsigned int *v11; // r2
  _DWORD *v12; // r4
  int v13; // r1
  int v14; // r3
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  _DWORD *v19; // r3
  int v20; // r0
  int v21; // r2
  _WORD *v22; // r1

  v0 = off_127000;
  v1 = off_127004;
  v2 = *((_DWORD *)off_127000 + 11);
  sub_102A20((unsigned __int16 *)(v2 + 4), 0);
  sub_12C484(*(char *)(v2 + 12));
  *(_DWORD *)off_127008 = v1[*(unsigned __int8 *)(v2 + 4) + 5];
  if ( *(_BYTE *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(_BYTE *)(v2 + 16) = 4;
      if ( *((_BYTE *)v0 + 90) || !*((_BYTE *)off_12700C + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (_BYTE *)sub_12C92C(68, 13, 0, 4);
  v4 = *(unsigned __int8 *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(_WORD *)(v2 + 14);
    if ( v5 )
      LOBYTE(v5) = 1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(_BYTE *)(v2 + 26);
  sub_12C98C(v3);
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(_BYTE *)(v2 + 24) == 4
      && *(unsigned __int16 *)(v7 + 4) == *(unsigned __int16 *)(v2 + 4)
      && *(unsigned __int8 *)(v7 + 13) == *(unsigned __int8 *)(v2 + 13)
      && *(unsigned __int16 *)(v7 + 6) == *(unsigned __int16 *)(v2 + 6)
      && *(unsigned __int16 *)(v7 + 8) == *(unsigned __int16 *)(v2 + 8) )
    {
      v6 = *(unsigned __int16 *)(v7 + 10) == *(unsigned __int16 *)(v2 + 10);
    }
LABEL_7:
    *(_BYTE *)(v7 + 16) = 1;
    v8 = *(unsigned __int8 *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(unsigned __int8 *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(_BYTE *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((_BYTE *)v0 + 90) && !v6 || !*((_BYTE *)off_12700C + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((_BYTE *)off_12700C + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  sub_117AB8();
  v16 = *(unsigned __int8 *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(__int16 **)off_127020;
      v18 = v1[1] | 0x2200;
      *(_DWORD *)off_127024 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(_DWORD *)off_12703C << 28 )
      {
        sub_12F49C(dword_127044, dword_127040, 472);
        v18 = v1[1];
      }
      *(_DWORD *)off_127028 = v18 | *v1;
      sub_12CA10(141, 2, 255);
      if ( *((_BYTE *)off_12702C + 3851) == 1 && !*((_BYTE *)off_127030 + 10) )
      {
        v19 = *(_DWORD **)off_127034;
        if ( *(_DWORD *)off_127034 )
        {
          v20 = dword_127038;
          do
          {
            v21 = v19[15];
            if ( v21 >= 0 )
            {
              v22 = (_WORD *)v19[4];
              if ( v22 )
              {
                if ( (*v22 & 0xFC) == 0x40 )
                  v19[15] = v21 | v20;
              }
            }
            v19 = (_DWORD *)v19[1];
          }
          while ( v19 );
        }
      }
    }
LABEL_22:
    v11 = (unsigned int *)off_127018;
    v12 = off_12701C;
    v13 = *(_DWORD *)off_127018;
    v14 = *((_DWORD *)off_12701C + 1) | 2;
    *((_BYTE *)v0 + 92) = (*(_DWORD *)off_127018 & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return sub_1210E4();
  }
LABEL_10:
  sub_126C70();
  v9 = *((_DWORD *)off_127010 + 2);
  if ( v9 )
  {
    v10 = dword_127014;
    do
    {
      while ( *(_DWORD *)(v9 + 72) != v2 )
      {
        v9 = *(_DWORD *)v9;
        if ( !v9 )
          return sub_1210E4();
      }
      *(_BYTE *)(v10 + 32 * *(unsigned __int8 *)(v9 + 107) + 31) = 1;
      sub_120214(v9);
      v9 = *(_DWORD *)v9;
    }
    while ( v9 );
  }
  return sub_1210E4();
}

