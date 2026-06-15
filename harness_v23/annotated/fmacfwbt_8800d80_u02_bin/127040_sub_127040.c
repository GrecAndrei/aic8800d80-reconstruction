// v23 annotated: sub_127040 @ 0x127040
// Original: 127040_sub_127040.c
// Primary struct: <unclustered>
//
// sub_127040 @ 0x127040, size 484 bytes
int sub_127040()
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
  int v19; // r3
  _DWORD *v20; // r3
  int v21; // r0
  int v22; // r2
  _WORD *v23; // r1

  v0 = off_127224;
  v1 = off_127228;
  v2 = *((_DWORD *)off_127224 + 11);
  sub_102898((unsigned __int16 *)(v2 + 4), 0);
  sub_12C6AC(*(char *)(v2 + 12));
  *(_DWORD *)off_12722C = v1[*(unsigned __int8 *)(v2 + 4) + 5];
  if ( *(_BYTE *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(_BYTE *)(v2 + 16) = 4;
      if ( *((_BYTE *)v0 + 90) || !*((_BYTE *)off_127230 + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (_BYTE *)sub_12CB54(68, 13, 0, 4);
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
  sub_12CBB4(v3);
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
    if ( *((_BYTE *)v0 + 90) && !v6 || !*((_BYTE *)off_127230 + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((_BYTE *)off_127230 + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  sub_117EF8();
  v16 = *(unsigned __int8 *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(__int16 **)off_127244;
      v18 = v1[1] | 0x2200;
      *(_DWORD *)off_127248 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(_DWORD *)off_127260 << 28 )
      {
        sub_12F6C4(dword_127268, dword_127264, 472);
        v18 = v1[1];
      }
      v19 = v18 | *v1;
      *(_DWORD *)off_12724C = v19;
      sub_12CC38(141, 2, 255, v19);
      if ( *((_BYTE *)off_127250 + 3851) == 1 && !*((_BYTE *)off_127254 + 10) )
      {
        v20 = *(_DWORD **)off_127258;
        if ( *(_DWORD *)off_127258 )
        {
          v21 = dword_12725C;
          do
          {
            v22 = v20[15];
            if ( v22 >= 0 )
            {
              v23 = (_WORD *)v20[4];
              if ( v23 )
              {
                if ( (*v23 & 0xFC) == 0x40 )
                  v20[15] = v22 | v21;
              }
            }
            v20 = (_DWORD *)v20[1];
          }
          while ( v20 );
        }
      }
    }
LABEL_22:
    v11 = (unsigned int *)off_12723C;
    v12 = off_127240;
    v13 = *(_DWORD *)off_12723C;
    v14 = *((_DWORD *)off_127240 + 1) | 2;
    *((_BYTE *)v0 + 92) = (*(_DWORD *)off_12723C & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return sub_12141C();
  }
LABEL_10:
  sub_126E94();
  v9 = *((_DWORD *)off_127234 + 2);
  if ( v9 )
  {
    v10 = dword_127238;
    do
    {
      while ( *(_DWORD *)(v9 + 72) != v2 )
      {
        v9 = *(_DWORD *)v9;
        if ( !v9 )
          return sub_12141C();
      }
      *(_BYTE *)(v10 + 32 * *(unsigned __int8 *)(v9 + 107) + 31) = 1;
      sub_12054C(v9);
      v9 = *(_DWORD *)v9;
    }
    while ( v9 );
  }
  return sub_12141C();
}

