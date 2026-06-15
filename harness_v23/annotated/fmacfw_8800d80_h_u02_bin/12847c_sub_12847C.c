// v23 annotated: sub_12847C @ 0x12847c
// Original: 12847c_sub_12847C.c
// Primary struct: <unclustered>
//
// sub_12847C @ 0x12847c, size 664 bytes
int __fastcall sub_12847C(int a1)
{
  __int16 **v1; // r9
  int v2; // r8
  int v3; // r10
  unsigned __int8 *v4; // r6
  int v6; // r5
  char *v7; // r7
  int v8; // r1
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r3
  int v14; // r5
  unsigned __int8 *v15; // r3
  int v16; // r0
  int v17; // r3
  char *v18; // r4
  int v19; // r2
  int v20; // r3
  int v22; // r1
  __int16 *v23; // r2
  unsigned int v24; // r3
  int v25; // r3
  _DWORD *v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r2
  char *v30; // r1
  int v31; // r0

  v1 = (__int16 **)off_128744;
  v2 = dword_12873C;
  v3 = 1320 * a1;
  v4 = *(unsigned __int8 **)(dword_12873C + 1320 * a1 + 72);
  if ( **(__int16 **)off_128744 < 0 && !v4 )
    sub_12F32C(dword_12872C, dword_128728, 3149);
  v6 = v2 + 1320 * a1;
  v7 = (char *)off_128714;
  sub_12EB90(256, dword_128718);
  sub_12D1A8(v7 + 16, v3 + 76 + v2);
  v9 = *(unsigned __int8 *)(v6 + 85);
  *(_BYTE *)(v6 + 85) = v9 & 0xFE;
  v10 = v9 << 30;
  if ( (v9 & 2) != 0 )
  {
    v11 = (unsigned __int8)(v7[91] - 1);
    v7[91] = v11;
    if ( !v11 && (v7[88] & 0x40) != 0 )
    {
      sub_12E948(dword_128724, v8, v10);
      sub_127030(*((_DWORD *)v7 + 20));
    }
  }
  v12 = v2 + 1320 * a1;
  *(_BYTE *)(v12 + 85) = 0;
  *(_DWORD *)(v12 + 72) = 0;
  v13 = v4[16];
  v14 = (unsigned __int8)(v4[25] - 1);
  v4[25] = v14;
  if ( v13 )
  {
    if ( v4[27] == *(unsigned __int8 *)(v12 + 107) )
    {
      sub_125CD0(v2 + v3);
      v14 = v4[25];
      v4[27] = -1;
      if ( v14 )
        return sub_128408((int)v4);
    }
    else
    {
      v15 = (unsigned __int8 *)off_12871C;
      while ( 1 )
      {
        if ( v15[24] != 255 )
        {
          v16 = v15[27];
          if ( v16 != 255 )
            break;
        }
        v15 += 28;
        if ( (unsigned __int8 *)((char *)off_12871C + 84) == v15 )
          goto LABEL_10;
      }
      v26 = (_DWORD *)(v2 + 1320 * v16);
      if ( (unsigned __int8 *)v26[18] == v4 )
      {
LABEL_10:
        if ( !v14 )
          goto LABEL_26;
        return sub_128408((int)v4);
      }
      if ( v14 )
      {
        sub_125D38(v26);
        LOBYTE(v14) = v4[25];
        if ( (_BYTE)v14 )
          return sub_128408((int)v4);
      }
      else
      {
        sub_125CD0((int)v26);
        v14 = v4[25];
        if ( v4[25] )
          return sub_128408((int)v4);
      }
    }
LABEL_26:
    sub_12D1A8(dword_128730, v4);
    v4[16] = v14;
    v23 = *v1;
    v24 = (unsigned __int8)(v7[90] - 1);
    v7[90] = v24;
    if ( *v23 < 0 && v24 > 1 )
    {
      sub_12F32C(dword_128734, dword_128728, 3210);
      v24 = (unsigned __int8)v7[90];
    }
    if ( v24 )
    {
      sub_12D100(dword_128738);
      v25 = dword_12873C;
      v22 = dword_12873C + 5280;
      do
      {
        *(_BYTE *)(v25 + 85) &= ~1u;
        v25 += 1320;
      }
      while ( v22 != v25 );
      if ( !*((_DWORD *)v7 + 20) )
        sub_1266A0();
    }
    if ( *((unsigned __int8 **)v7 + 10) != v4 )
    {
      if ( *((unsigned __int8 **)v7 + 11) != v4 )
        goto LABEL_30;
      v27 = v4[24];
      v28 = v27 + 1;
      if ( v27 == 2 )
      {
        if ( *((unsigned __int8 *)off_12871C + 24) != 255 )
        {
          v28 = 0;
          v29 = 0;
          goto LABEL_57;
        }
        v28 = 1;
      }
      else
      {
        v29 = 8 * v28;
        if ( *((unsigned __int8 *)off_12871C + 28 * v28 + 24) != 255 )
          goto LABEL_57;
        v28 = v27 + 2;
        if ( v27 == 1 )
          v28 = 0;
      }
      v29 = 8 * v28;
      if ( *((unsigned __int8 *)off_12871C + 28 * v28 + 24) == 255 )
      {
        v30 = nullptr;
LABEL_51:
        v31 = dword_128740;
        *((_DWORD *)v7 + 11) = v30;
        sub_12E948(v31, v30, v29);
        goto LABEL_30;
      }
LABEL_57:
      v30 = (char *)off_12871C + 4 * (v29 - v28);
      goto LABEL_51;
    }
    v17 = (unsigned __int8)v7[90];
    *((_DWORD *)v7 + 10) = 0;
    if ( !v17 || (v18 = *((char **)v7 + 11)) != nullptr )
    {
LABEL_30:
      if ( !v4[25] )
        goto LABEL_21;
      return sub_128408((int)v4);
    }
    sub_12E948(dword_128720, v22, 0);
    v19 = v4[24];
    v20 = v19 + 1;
    if ( v19 == 2 )
    {
      if ( *((unsigned __int8 *)off_12871C + 24) != 255 )
      {
        v20 = 0;
        goto LABEL_61;
      }
      v20 = 1;
    }
    else
    {
      if ( *((unsigned __int8 *)off_12871C + 28 * v20 + 24) != 255 )
        goto LABEL_61;
      v20 = v19 + 2;
      if ( v19 == 1 )
        v20 = 0;
    }
    if ( *((unsigned __int8 *)off_12871C + 28 * v20 + 24) == 255 )
    {
LABEL_19:
      sub_126F8C((int)v18);
      v14 = v4[25];
      goto LABEL_20;
    }
LABEL_61:
    v18 = (char *)off_12871C + 28 * v20;
    goto LABEL_19;
  }
LABEL_20:
  if ( v14 )
    return sub_128408((int)v4);
LABEL_21:
  sub_127CC0(v4[24]);
  return sub_128408((int)v4);
}

