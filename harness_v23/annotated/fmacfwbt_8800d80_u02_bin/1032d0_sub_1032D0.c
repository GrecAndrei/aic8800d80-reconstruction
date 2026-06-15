// v23 annotated: sub_1032D0 @ 0x1032d0
// Original: 1032d0_sub_1032D0.c
// Primary struct: <unclustered>
//
// sub_1032D0 @ 0x1032d0, size 1722 bytes
void __noreturn sub_1032D0()
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
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int v17; // r0
  _DWORD *v18; // r3
  _DWORD *v19; // r1
  int v20; // r0
  _DWORD *v21; // r4
  _DWORD *v22; // r5
  _BYTE *v23; // r6
  int v24; // r9
  int i; // r4
  int v26; // r0
  _DWORD *v27; // r4
  int v28; // r9
  int v29; // r10
  int k; // r5
  int v31; // r0
  int v32; // r5
  int v33; // r10
  int v34; // r0
  int v35; // r9
  unsigned __int64 v36; // kr00_8
  bool v37; // zf
  unsigned __int8 v38; // r2
  int v39; // r3
  unsigned int v40; // r1
  int v41; // r2
  int v42; // r0
  int v43; // r3
  int *v44; // r4
  int j; // r4
  unsigned __int8 v46; // r2
  int *v47; // r2
  int v48; // r3
  int v49; // r1
  int v50; // r2
  int v51; // r6
  _BYTE *v52; // r6
  int v53; // r1
  int v54; // r2
  unsigned int v55; // r3
  int v56; // r0
  int v57; // r5
  _BYTE *v58; // r4
  _DWORD *v59; // r3
  _DWORD *v60; // r1
  _BYTE *v61; // r3
  char v62; // r1
  char v63; // r2
  _DWORD *v64; // r4
  int v65; // r10
  int v66; // r2
  int v67; // r11
  _DWORD *v68; // r6
  unsigned __int8 *v69; // r4
  char *v70; // r7
  int n; // r5
  int v72; // t1
  int v73; // r3
  int v74; // r1
  _DWORD *v75; // r5
  int v76; // r9
  int v77; // r2
  _DWORD *v78; // r7
  int v79; // r11
  char *v80; // r10
  int m; // r4
  int v82; // t1
  int v83; // r1
  int v84; // r1
  _BYTE *v85; // [sp+4h] [bp-30h]
  _BYTE v86[4]; // [sp+Ch] [bp-28h] BYREF
  _DWORD v87[3]; // [sp+10h] [bp-24h] BYREF
  unsigned __int8 v88[24]; // [sp+1Ch] [bp-18h] BYREF

  v0 = off_103438;
  *((_DWORD *)off_103434 + 64) = 8;
  if ( !v0[2] )
    *((_DWORD *)off_10343C + 2) = *((_DWORD *)off_10343C + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_10343C;
  while ( (*((_DWORD *)off_10343C + 12) & 0x22) != 2 )
    ;
  v2 = off_103440;
  v3 = dword_103444;
  v4 = off_103434;
  *((_DWORD *)off_10343C + 2) = *((_DWORD *)off_10343C + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (_BYTE **)off_103448;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  sub_10DCEC();
  v6 = off_10343C;
  v7 = dword_103444;
  v8 = off_103434;
  v9 = off_103458;
  *(_DWORD *)off_10343C = *(_DWORD *)off_10343C & 0x3EF | 0x10 | *(_DWORD *)off_10343C & dword_103444;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((unsigned __int8 *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v47 = (int *)off_103990;
    v48 = v9[42] | 0x2000000;
    *(_BYTE *)off_10398C = 1;
    *v47 = v48;
    v8[14] |= 0x10u;
  }
  else
  {
    *(_DWORD *)off_10344C = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(_BYTE **)off_103450 == 2 )
    {
      v59 = off_1039A0;
      v60 = off_1039A4;
      *((_DWORD *)off_1039A0 + 20) |= 0x40000u;
      v60[7] &= ~0x100u;
      v59[9] = v59[9] & 0xFFFFFF00 | 0x60;
      v59[9] = v59[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      v14 = sub_10D480();
      v15 = sub_10D07C(v14);
      if ( !*(_DWORD *)off_103454 )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_10343C;
    **(_BYTE **)off_103450 = 2;
    v12 = off_103434;
    v13 = (unsigned __int8)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v18 = off_10376C;
    v19 = off_103770;
    *((_DWORD *)off_10376C + 20) |= 0x40000u;
    v19[7] &= ~0x100u;
    v18[9] = v18[9] & 0xFFFFFF00 | 0x60;
    v18[9] = v18[9] & 0xFFFF00FF | 0xDF00;
  }
  v20 = sub_10D42C();
  v15 = sub_10D07C(v20);
  if ( !*(_DWORD *)off_103774 )
  {
LABEL_17:
    v21 = off_103770;
    sub_102DD8();
    v21[4] |= 2u;
    sub_1030B0();
    if ( (*v21 & 0x2000000) != 0 )
    {
      v22 = off_103778;
      v23 = off_10377C;
      v24 = 1;
      for ( i = 0; i != 3; ++i )
      {
        v26 = sub_114F5C(i, *v22 + 3 * i);
        if ( v26 != 546 )
        {
          v23[1] |= 1u;
          v24 = 0;
        }
      }
      if ( v24 )
      {
        for ( j = 0; j != 3; ++j )
        {
          v88[0] = 0;
          if ( sub_115078(j, v88) <= 1 )
          {
            v46 = v88[0];
            *(_BYTE *)(*v22 + j) = v88[0];
            *(_BYTE *)(*v22 + j + 3) = v46;
            *(_BYTE *)(*v22 + j + 6) = v46;
          }
        }
      }
      v27 = off_103780;
      v28 = dword_1037D4;
      v29 = 1;
      for ( k = 0; k != 3; ++k )
      {
        v31 = sub_114FD8(k, *v27 + 6 * k);
        if ( v31 != v28 )
        {
          v23[1] |= 1u;
          v29 = 0;
        }
      }
      if ( v29 )
      {
        v32 = 0;
        v33 = dword_1037D8;
        v88[0] = 0;
        v34 = 2;
        v35 = 4;
        do
        {
          v36 = (unsigned int)v33 * (unsigned __int64)(unsigned int)(2 * v32);
          v37 = v35 == HIDWORD(v36) >> 1;
          v35 = HIDWORD(v36) >> 1;
          if ( !v37 )
            v34 = sub_1150C0(HIDWORD(v36) >> 1, v88);
          if ( v34 <= 1 )
          {
            v38 = v88[0];
            *(_BYTE *)(*v27 + v32) = v88[0];
            v39 = *v27 + v32;
            *(_BYTE *)(v39 + 6) = v38;
            *(_BYTE *)(v39 + 12) = v38;
          }
          ++v32;
        }
        while ( v32 != 6 );
      }
      v40 = 31 - __clz(sub_1151E8());
      *v23 = v40;
    }
    else
    {
      memset(v87, 0, sizeof(v87));
      v51 = sub_11537C(v87);
      if ( v51 )
      {
        v52 = off_103994;
      }
      else
      {
        v75 = off_1039BC;
        v76 = dword_1039C0;
        sub_10DA7C(dword_1039B8, v49, v50);
        v78 = v87;
        do
        {
          sub_10DA7C(dword_1039B0, v51, v77);
          v79 = 3 * v51;
          v80 = (char *)v78;
          for ( m = 0; m != 3; ++m )
          {
            v82 = *v80++;
            *(_BYTE *)(*v75 + v79 + m) = v82;
            v83 = *(char *)(*v75 + v79 + m);
            sub_10DA7C(v76, v83, v82);
          }
          ++v51;
          v78 = (_DWORD *)((char *)v78 + 3);
        }
        while ( v51 != 3 );
        v52 = off_103994;
        sub_10DA7C(dword_1039B4, v84, v77);
        v52[1] |= 1u;
      }
      memset(v88, 0, 20);
      if ( !sub_115388(v88) )
      {
        v64 = off_1039A8;
        v65 = dword_1039C0;
        sub_10DA7C(dword_1039AC, v53, v54);
        v67 = 0;
        v85 = v52;
        v68 = v64;
        v69 = v88;
        do
        {
          sub_10DA7C(dword_1039B0, v67, v66);
          v70 = (char *)v69;
          for ( n = 0; n != 6; ++n )
          {
            v72 = *v70++;
            *(_BYTE *)(*v68 + n + 6 * v67) = v72;
            v73 = *v68 + n;
            sub_10DA7C(v65, *(char *)(v73 + 6 * v67), v72);
          }
          ++v67;
          v69 += 6;
        }
        while ( v67 != 3 );
        v52 = v85;
        sub_10DA7C(dword_1039B4, v74, v66);
        v85[1] |= 1u;
      }
      if ( sub_1153AC(v86) )
      {
        v40 = -1;
        *v52 = -1;
      }
      else
      {
        v55 = v86[0];
        *v52 = v86[0];
        v40 = v55;
      }
    }
    v42 = sub_10DA7C(dword_103784, v40, v41);
    if ( *((_BYTE *)v9 + 372) )
    {
      if ( (*(_DWORD *)off_103770 & 0x2000000) != 0 )
      {
        if ( sub_1151AC(v42) )
        {
          v56 = sub_115144();
          v57 = dword_103998;
          v58 = off_10399C;
          *(_BYTE *)off_10399C = *(_BYTE *)(dword_103998 + v56);
          v58[1] = *(_BYTE *)(v57 + sub_115158());
          v58[2] = *(_BYTE *)(v57 + sub_11516C());
        }
      }
      else
      {
        *(_DWORD *)v88 = 0;
        if ( !sub_115394(v88) )
        {
          v61 = off_10399C;
          v62 = *(_BYTE *)(dword_103998 + v88[1]);
          v63 = *(_BYTE *)(dword_103998 + v88[2]);
          *(_BYTE *)off_10399C = *(_BYTE *)(dword_103998 + v88[0]);
          v61[1] = v62;
          v61[2] = v63;
        }
      }
    }
    v43 = dword_10378C;
    v44 = (int *)off_103790;
    *(_DWORD *)off_103788 &= 0xFFFFFFC7;
    sub_102D10(0, 0, 0x10u, v43);
    sub_102D10(0, 16, 0x10u, dword_103794);
    sub_102D10(0, 32, 0x10u, v44[2]);
    sub_102D10(0, 48, 0x10u, v44[1]);
    sub_102D10(0, 64, 0x10u, *v44);
    sub_102D10(1, 0, 0x10u, *(_DWORD *)off_103798);
    sub_102D10(1, 16, 0x10u, *(_DWORD *)off_10379C);
    sub_100D94();
    sub_103154();
  }
LABEL_14:
  v16 = sub_10EDA8(v15);
  v17 = sub_10E3B8(v16);
  sub_10E0F8(v17);
  goto LABEL_17;
}

