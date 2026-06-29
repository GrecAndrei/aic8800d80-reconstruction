// fwstruct annotate: 11b80c_sub_11B80C.c
// sub_11B80C @ 0x11b80c, size 420 bytes
int sub_11B80C()
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
  int v11; // r1
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r3

  v0 = off_11B9B0;
  v1 = off_11B9B4;
  v2 = *((_DWORD *)off_11B9B0 + 11);
  sub_102908((unsigned __int8 *)(v2 + 4), 0);
  sub_11D9F8(*(char *)(v2 + 12));
  *(_DWORD *)off_11B9B8 = v1[*(unsigned __int8 *)(v2 + 4) + 5];
  if ( *(_BYTE *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(_BYTE *)(v2 + 16) = 4;
      if ( *((_BYTE *)v0 + 90) || !*((_BYTE *)off_11B9BC + 143) )
        goto LABEL_31;
      goto LABEL_29;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (_BYTE *)sub_11DDF0(68, 4, 0, 4);
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
  sub_11DE50(v3);
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
    if ( *((_BYTE *)v0 + 90) && !v6 || !*((_BYTE *)off_11B9BC + 143) )
    {
      if ( v8 != 3 )
        return sub_1188F4();
      goto LABEL_31;
    }
    goto LABEL_29;
  }
  if ( *((_BYTE *)off_11B9BC + 143) )
  {
LABEL_29:
    sub_115DBC();
    v13 = *(unsigned __int8 *)(v2 + 24);
    if ( v13 <= 2 )
      goto LABEL_10;
    if ( v13 != 3 )
      return sub_1188F4();
LABEL_31:
    v14 = **(__int16 **)off_11B9C8;
    v15 = v1[1] | 0x2200;
    *(_DWORD *)off_11B9CC = 0;
    v1[1] = v15;
    if ( v14 < 0 && *(_DWORD *)off_11B9D4 << 28 )
    {
      sub_1219F4(dword_11B9DC, dword_11B9D8, 472);
      v15 = v1[1];
    }
    *(_DWORD *)off_11B9D0 = v15 | *v1;
    sub_11DED8(141, 2, 255);
    return sub_1188F4();
  }
LABEL_10:
  sub_11B6F0();
  v9 = *((_DWORD *)off_11B9C0 + 2);
  if ( v9 )
  {
    v10 = dword_11B9C4;
    do
    {
      while ( *(_DWORD *)(v9 + 72) != v2 )
      {
        v9 = *(_DWORD *)v9;
        if ( !v9 )
          goto LABEL_15;
      }
      *(_BYTE *)(v10 + 32 * *(unsigned __int8 *)(v9 + 95) + 31) = 1;
      sub_1182C8(v9);
      v9 = *(_DWORD *)v9;
    }
    while ( v9 );
  }
LABEL_15:
  v11 = *(unsigned __int16 *)(v2 + 14);
  if ( v11 != 255 )
  {
    sub_11DED8(62, v11, 0);
    *(_WORD *)(v2 + 14) = 255;
  }
  return sub_1188F4();
}

