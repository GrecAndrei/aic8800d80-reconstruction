// sub_1033F8 @ 0x1033f8, size 1580 bytes
int sub_1033F8()
{
  _BYTE *v0; // r4
  int *v1; // r2
  _DWORD *v2; // r0
  int v3; // r1
  _DWORD *v4; // r5
  _BYTE **v5; // r5
  _DWORD *v6; // r1
  int v7; // r6
  _DWORD *v8; // r0
  _DWORD *v9; // r8
  int v10; // r2
  _DWORD *v11; // r3
  _DWORD *v12; // r1
  int v13; // r0
  _DWORD *v14; // r3
  _DWORD *v15; // r1
  _DWORD *v16; // r4
  _DWORD *v17; // r5
  char *v18; // r6
  int v19; // r9
  int i; // r4
  int v21; // r0
  _DWORD *v22; // r4
  int v23; // r9
  int v24; // r10
  int k; // r5
  int v26; // r0
  int v27; // r5
  int v28; // r10
  int v29; // r0
  int v30; // r9
  unsigned __int64 v31; // kr00_8
  bool v32; // zf
  unsigned __int8 v33; // r2
  int v34; // r3
  int v35; // r3
  int *v36; // r4
  _WORD *v37; // r5
  int v38; // r0
  __int16 v39; // r2
  int v40; // r1
  int v41; // r0
  int v42; // r0
  unsigned int *v43; // r2
  int v44; // r0
  int j; // r4
  unsigned __int8 v47; // r2
  int *v48; // r2
  int v49; // r3
  int v50; // r6
  int v51; // r0
  int v52; // r5
  _BYTE *v53; // r4
  _DWORD *v54; // r3
  _DWORD *v55; // r1
  _BYTE *v56; // r3
  char v57; // r1
  char v58; // r2
  _DWORD *v59; // r4
  int v60; // r10
  int v61; // r11
  _DWORD *v62; // r6
  unsigned __int8 *v63; // r4
  unsigned __int8 *v64; // r7
  int n; // r5
  char v66; // t1
  int v67; // r3
  _DWORD *v68; // r5
  int v69; // r9
  _DWORD *v70; // r7
  int v71; // r11
  char *v72; // r10
  int m; // r4
  char v74; // t1
  int v75; // r1
  char *v76; // [sp+4h] [bp-30h]
  _BYTE *(_DWORD *)(v77 + 0x10); // [sp+Ch] [bp-28h] BYREF
  _DWORD *(_DWORD *)(v78 + 0xc); // [sp+10h] [bp-24h] BYREF
  unsigned __int8 *(_DWORD *)(v79 + 0x60); // [sp+1Ch] [bp-18h] BYREF

  v0 = off_103560;
  *((_DWORD *)off_10355C + 64) = 8;
  if ( !*(_DWORD *)(v0 + 0x8) )
    *((_DWORD *)off_103564 + 2) = *((_DWORD *)off_103564 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_103564;
  while ( (*((_DWORD *)off_103564 + 12) & 0x22) != 2 )
    ;
  v2 = off_103568;
  v3 = dword_10356C;
  v4 = off_10355C;
  *((_DWORD *)off_103564 + 2) = *((_DWORD *)off_103564 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  *(_DWORD *)(v1 + 0x54) = *(_DWORD *)(v1 + 0x54) & 0x37F | 0x80 | *(_DWORD *)(v1 + 0x54) & v3;
  *(_DWORD *)(v4 + 0x144) = 16;
  v5 = (_BYTE **)off_103570;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    *(_DWORD *)(v1 + 0x54) = v3 & *(_DWORD *)(v1 + 0x54) | *(_DWORD *)(v1 + 0x54) & 0x3F7 | 8;
  }
  sub_10DD54();
  v6 = off_103564;
  v7 = dword_10356C;
  v8 = off_10355C;
  v9 = off_103580;
  *(_DWORD *)off_103564 = *(_DWORD *)off_103564 & 0x3EF | 0x10 | *(_DWORD *)off_103564 & dword_10356C;
  *(_DWORD *)(v6 + 0x54) = *(_DWORD *)(v6 + 0x54) & 0x3EF | 0x10 | *(_DWORD *)(v6 + 0x54) & v7;
  *(_DWORD *)(v8 + 0x58) &= 0xFFFFFFC1;
  v10 = *((unsigned __int8 *)v9 + 177);
  *(_DWORD *)(v8 + 0x58) |= 0x26u;
  if ( v10 && (*(_DWORD *)(v6 + 0x30) & 0x40) == 0 && (*(_DWORD *)(v6 + 0x30) & 4) != 0 )
  {
    v48 = (int *)off_1038F0;
    v49 = *(_DWORD *)(v9 + 0xa8) | 0x2000000;
    *(_BYTE *)off_1038EC = 1;
    *v48 = v49;
    *(_DWORD *)(v8 + 0x38) |= 0x10u;
  }
  else
  {
    *(_DWORD *)off_103574 = *(_DWORD *)(v9 + 0xa8);
  }
  if ( *(_DWORD *)(v0 + 0x8) )
  {
    if ( **(_BYTE **)off_103578 == 2 )
    {
      v54 = off_103A24;
      v55 = off_103A28;
      *((_DWORD *)off_103A24 + 20) |= 0x40000u;
      *(_DWORD *)(v55 + 0x1c) &= ~0x100u;
      *(_DWORD *)(v54 + 0x24) = *(_DWORD *)(v54 + 0x24) & 0xFFFFFF00 | 0x60;
      *(_DWORD *)(v54 + 0x24) = *(_DWORD *)(v54 + 0x24) & 0xFFFF00FF | 0xDF00;
LABEL_13:
      sub_10D4E8();
      sub_10D0E4();
      if ( !*(_DWORD *)off_10357C )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_103564;
    **(_BYTE **)off_103578 = 2;
    v12 = off_10355C;
    v13 = (unsigned __int8)*(_DWORD *)(v0 + 0x8);
    *(_DWORD *)(v11 + 0x50) |= 0x40000u;
    *(_DWORD *)(v12 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v11 + 0x24) = *(_DWORD *)(v11 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v11 + 0x24) = *(_DWORD *)(v11 + 0x24) & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v14 = off_103898;
    v15 = off_10389C;
    *((_DWORD *)off_103898 + 20) |= 0x40000u;
    *(_DWORD *)(v15 + 0x1c) &= ~0x100u;
    *(_DWORD *)(v14 + 0x24) = *(_DWORD *)(v14 + 0x24) & 0xFFFFFF00 | 0x60;
    *(_DWORD *)(v14 + 0x24) = *(_DWORD *)(v14 + 0x24) & 0xFFFF00FF | 0xDF00;
  }
  sub_10D494();
  sub_10D0E4();
  if ( *(_DWORD *)off_1038A0 )
  {
LABEL_14:
    sub_10EE10();
    sub_10E420();
    sub_10E160();
  }
LABEL_17:
  v16 = off_10389C;
  sub_102ED0();
  *(_DWORD *)(v16 + 0x10) |= 2u;
  sub_1031D8();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = off_1038A4;
    v18 = (char *)off_1038A8;
    v19 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v21 = sub_1147E0(i, *v17 + 3 * i);
      if ( v21 != 546 )
      {
        *(_DWORD *)(v18 + 0x4) |= 1u;
        v19 = 0;
      }
    }
    if ( v19 )
    {
      for ( j = 0; j != 3; ++j )
      {
        *(_DWORD *)(v79 + 0x0) = 0;
        if ( sub_1148FC(j, v79) <= 1 )
        {
          v47 = *(_DWORD *)(v79 + 0x0);
          *(_BYTE *)(*v17 + j) = *(_DWORD *)(v79 + 0x0);
          *(_BYTE *)(*v17 + j + 3) = v47;
          *(_BYTE *)(*v17 + j + 6) = v47;
        }
      }
    }
    v22 = off_1038AC;
    v23 = dword_1038FC;
    v24 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v26 = sub_11485C(k, *v22 + 6 * k);
      if ( v26 != v23 )
      {
        *(_DWORD *)(v18 + 0x4) |= 1u;
        v24 = 0;
      }
    }
    if ( v24 )
    {
      v27 = 0;
      v28 = dword_103900;
      *(_DWORD *)(v79 + 0x0) = 0;
      v29 = 2;
      v30 = 4;
      do
      {
        v31 = (unsigned int)v28 * (unsigned __int64)(unsigned int)(2 * v27);
        v32 = v30 == HIDWORD(v31) >> 1;
        v30 = HIDWORD(v31) >> 1;
        if ( !v32 )
          v29 = sub_114944(HIDWORD(v31) >> 1, v79);
        if ( v29 <= 1 )
        {
          v33 = *(_DWORD *)(v79 + 0x0);
          *(_BYTE *)(*v22 + v27) = *(_DWORD *)(v79 + 0x0);
          v34 = *v22 + v27;
          *(_BYTE *)(v34 + 6) = v33;
          *(_BYTE *)(v34 + 12) = v33;
        }
        ++v27;
      }
      while ( v27 != 6 );
    }
    *v18 = 31 - __clz(sub_114A6C());
  }
  else
  {
    memset(v78, 0, sizeof(v78));
    v50 = sub_114C00((int)v78);
    if ( v50 )
    {
      v18 = (char *)off_1038A8;
    }
    else
    {
      v68 = off_103A48;
      v69 = dword_103A50;
      sub_10DAE4(dword_103A44);
      v70 = v78;
      do
      {
        sub_10DAE4(dword_103A3C, v50);
        v71 = 3 * v50;
        v72 = (char *)v70;
        for ( m = 0; m != 3; ++m )
        {
          v74 = *v72++;
          *(_BYTE *)(*v68 + v71 + m) = v74;
          v75 = *(char *)(*v68 + v71 + m);
          sub_10DAE4(v69, v75);
        }
        ++v50;
        v70 = (_DWORD *)((char *)v70 + 3);
      }
      while ( v50 != 3 );
      v18 = (char *)off_103A4C;
      sub_10DAE4(dword_103A40);
      *(_DWORD *)(v18 + 0x4) |= 1u;
    }
    memset(v79, 0, 20);
    if ( !sub_114C0C((int)v79) )
    {
      v59 = off_103A34;
      v60 = dword_103A50;
      sub_10DAE4(dword_103A38);
      v61 = 0;
      v76 = v18;
      v62 = v59;
      v63 = v79;
      do
      {
        sub_10DAE4(dword_103A3C, v61);
        v64 = v63;
        for ( n = 0; n != 6; ++n )
        {
          v66 = *v64++;
          *(_BYTE *)(*v62 + n + 6 * v61) = v66;
          v67 = *v62 + n;
          sub_10DAE4(v60, *(char *)(v67 + 6 * v61));
        }
        ++v61;
        v63 += 6;
      }
      while ( v61 != 3 );
      v18 = v76;
      sub_10DAE4(dword_103A40);
      *(_DWORD *)(v76 + 0x4) |= 1u;
    }
    if ( sub_114C30((int)v77) )
      *v18 = -1;
    else
      *v18 = *(_DWORD *)(v77 + 0x0);
  }
  sub_10DAE4(dword_1038B0);
  if ( *((_BYTE *)v9 + 372) )
  {
    if ( (*(_DWORD *)off_10389C & 0x2000000) != 0 )
    {
      if ( sub_114A30() )
      {
        v51 = sub_1149C8();
        v52 = dword_1038F4;
        v53 = off_1038F8;
        *(_BYTE *)off_1038F8 = *(_BYTE *)(dword_1038F4 + v51);
        *(_DWORD *)(v53 + 0x4) = *(_BYTE *)(v52 + sub_1149DC());
        *(_DWORD *)(v53 + 0x8) = *(_BYTE *)(v52 + sub_1149F0());
      }
    }
    else
    {
      *(_DWORD *)v79 = 0;
      if ( !sub_114C18((int)v79) )
      {
        v56 = off_103A30;
        v57 = *(_BYTE *)(dword_103A2C + *(_DWORD *)(v79 + 0x4));
        v58 = *(_BYTE *)(dword_103A2C + *(_DWORD *)(v79 + 0x8));
        *(_BYTE *)off_103A30 = *(_BYTE *)(dword_103A2C + *(_DWORD *)(v79 + 0x0));
        *(_DWORD *)(v56 + 0x4) = v57;
        *(_DWORD *)(v56 + 0x8) = v58;
      }
    }
  }
  v35 = dword_1038B8;
  v36 = (int *)off_1038BC;
  v37 = off_1038C0;
  *(_DWORD *)off_1038B4 &= 0xFFFFFFC7;
  sub_102E08(0, 0, 0x10u, v35);
  sub_102E08(0, 16, 0x10u, dword_1038C4);
  sub_102E08(0, 32, 0x10u, *(_DWORD *)(v36 + 0x8));
  sub_102E08(0, 48, 0x10u, *(_DWORD *)(v36 + 0x4));
  sub_102E08(0, 64, 0x10u, *v36);
  sub_102E08(1, 0, 0x10u, *(_DWORD *)off_1038C8);
  sub_102E08(1, 16, 0x10u, *(_DWORD *)off_1038CC);
  sub_100EE8();
  sub_10327C();
  sub_100E24(0);
  sub_10327C();
  *(_DWORD *)off_1038D0 |= 0x8000000u;
  v38 = sub_130234();
  v39 = ((int)(((unsigned __int64)(dword_1038D4 * (__int64)(4 * (v38 - 35))) >> 32) + 4 * (v38 - 35)) >> 2)
      - ((__int16)((unsigned int)(v38 - 35) >> 14) >> 15)
      + 120;
  v40 = v38;
  v41 = dword_1038D8;
  *(_WORD *)off_103904 = v39;
  *v37 = v39;
  sub_12E948(v41, v40);
  v42 = sub_10E9D8((unsigned int *)v79);
  sub_10DAE4(dword_1038DC, v42, *(_DWORD *)v79);
  if ( (*(_DWORD *)(v18 + 0x4) & 1) != 0 && *v18 < 0 )
  {
    v43 = (unsigned int *)off_1038E4;
    *(_DWORD *)off_1038E0 = *(_DWORD *)off_1038E0 & 0xFFFFFF87 | 0x40;
    *v43 = *v43 & 0xFFF87FFF | 0x40000;
  }
  v44 = sub_10EB04();
  return sub_10DAE4(dword_1038E8, v44);
}
