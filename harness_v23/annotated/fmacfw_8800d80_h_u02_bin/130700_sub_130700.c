// v23 annotated: sub_130700 @ 0x130700
// Original: 130700_sub_130700.c
// Primary struct: <unclustered>
//
// sub_130700 @ 0x130700, size 1230 bytes
int __fastcall sub_130700(int a1, int a2, _WORD *a3, int a4, _DWORD *a5, _WORD *a6, int a7)
{
  int v8; // r5
  __int16 v9; // r7
  int v10; // r6
  int v12; // r0
  _WORD *v13; // r3
  int v14; // r0
  _BYTE *v15; // r7
  int v16; // r2
  __int16 v17; // r9
  int v18; // r0
  int v19; // lr
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r12
  int v23; // r3
  int v24; // r8
  char *v25; // r2
  char *v26; // r12
  char v27; // t1
  unsigned int v28; // r12
  int v29; // r3
  char *v30; // lr
  unsigned int v31; // r12
  char *v32; // r2
  char v33; // t1
  __int16 v34; // r0
  int v35; // r3
  char *v36; // r2
  char v37; // t1
  int v38; // r5
  int v39; // r3
  int v40; // r9
  int v41; // r2
  int v42; // r1
  int v43; // r2
  int v44; // r3
  _BYTE *v45; // r2
  char i; // r1
  char v47; // t1
  unsigned __int16 *v48; // r10
  int v49; // r3
  _BYTE *v50; // r5
  int v51; // r2
  int v52; // r3
  __int16 v53; // r3
  char *v55; // r0
  char *v56; // r2
  char v57; // t1
  int v58; // r5
  __int16 v59; // r9
  char v60; // r0
  _BYTE *v61; // r3
  _BYTE *v62; // r3
  _BYTE *v63; // r3
  _BYTE *v64; // r3
  _BYTE *v65; // r3
  _BYTE *v66; // r10
  unsigned int v67; // r9
  char *v68; // r2
  int v69; // r1
  int v70; // r0
  int v71; // lr
  char v72; // r4
  int v73; // r3
  int v74; // r12
  unsigned int v75; // r11
  char v76; // r1
  char v77; // r3
  __int16 v78; // lr
  _BYTE *v79; // r2
  int v80; // r12
  _BYTE *v81; // r12
  __int16 v82; // r0
  __int16 v83; // [sp+4h] [bp-60h]
  int v84; // [sp+8h] [bp-5Ch]
  char v85; // [sp+Ch] [bp-58h]
  char *v86; // [sp+10h] [bp-54h]
  int v87; // [sp+14h] [bp-50h]
  int v88; // [sp+18h] [bp-4Ch]
  _BYTE *v89; // [sp+1Ch] [bp-48h] BYREF
  char v90; // [sp+23h] [bp-41h] BYREF
  _DWORD v91[2]; // [sp+24h] [bp-40h] BYREF
  _BYTE v92[2]; // [sp+2Ch] [bp-38h] BYREF
  int v93; // [sp+2Eh] [bp-36h]
  __int16 v94; // [sp+32h] [bp-32h]
  int v95; // [sp+54h] [bp-10h]

  v8 = a7;
  v9 = *(_WORD *)(a7 + 56);
  v10 = *(unsigned __int16 *)(a7 + 54);
  if ( !v9 )
    v9 = 5;
  v89 = (_BYTE *)a1;
  v12 = sub_132720(a4);
  v13 = v89;
  v14 = v12 | (*(_DWORD *)(a2 + 224) >> 1) & 0x10;
  *((_WORD *)v89 + 1) = v9;
  *v13 = v14;
  v84 = (unsigned __int16)v14;
  v15 = (_BYTE *)(a7 + 64);
  if ( a3 )
  {
    v13[2] = *a3;
    v13[3] = a3[1];
    v13[4] = a3[2];
    v16 = 5;
    v17 = 10;
  }
  else
  {
    v16 = 2;
    v17 = 4;
  }
  *a5 = &v13[v16];
  v18 = *(unsigned __int8 *)(a2 + 126);
  v89 = &v13[v16];
  LOBYTE(v13[v16]) = 0;
  v19 = v18 + 2;
  v89[1] = v18;
  if ( v18 )
  {
    v20 = (int)v89;
    v55 = (char *)(v18 + 127 + a2);
    v56 = (char *)(a2 + 127);
    do
    {
      v57 = *v56++;
      v56[v20 - a2 - 126] = v57;
    }
    while ( v55 != v56 );
  }
  else
  {
    v20 = (int)v89;
  }
  v21 = *(unsigned __int8 *)(a2 + 176);
  v89 = (_BYTE *)(v19 + v20);
  *(_BYTE *)(v19 + v20) = 1;
  v22 = v21;
  if ( v21 >= 8 )
    v22 = 8;
  v89[1] = v22;
  v23 = (int)v89;
  v24 = v22 + 2;
  v25 = (char *)(a2 + 177);
  if ( v21 )
  {
    v26 = (char *)(v22 + 177 + a2);
    do
    {
      v27 = *v25++;
      v25[v23 - a2 - 176] = v27;
    }
    while ( v25 != v26 );
  }
  v28 = *(unsigned __int8 *)(a2 + 176);
  v83 = v17 + v19 + v24;
  v89 = (_BYTE *)(v24 + v23);
  if ( v28 > 8 )
  {
    *(_BYTE *)(v24 + v23) = 50;
    v89[1] = v28 - 8;
    v29 = (int)v89;
    v30 = (char *)(v28 + 177 + a2);
    v31 = v28 - 6;
    v32 = (char *)(a2 + 185);
    do
    {
      v33 = *v32++;
      v32[v29 - a2 - 184] = v33;
    }
    while ( v32 != v30 );
    v89 = (_BYTE *)(v29 + v31);
    v83 += v31;
  }
  if ( (v84 & 0x100) == 0 )
    goto LABEL_17;
  v61 = v89++;
  *v61 = 33;
  v62 = v89++;
  *v62 = 2;
  sub_102A9C(v91, &v90);
  if ( SLOBYTE(v91[0]) > *(char *)(a2 + 172) )
    LOBYTE(v91[0]) = *(_BYTE *)(a2 + 172);
  v63 = v89++;
  *v63 = v90;
  v64 = v89++;
  *v64 = v91[0];
  v65 = v89++;
  *v65 = 36;
  v86 = v89;
  v66 = v89 + 1;
  if ( *(_BYTE *)(a2 + 164) )
  {
    v67 = *((unsigned __int8 *)off_130B68 + 371);
    v87 = 4;
    v68 = (char *)off_130B68 + 202;
  }
  else
  {
    v67 = *((unsigned __int8 *)off_130B68 + 370);
    v87 = 1;
    v68 = (char *)off_130B68 + 118;
  }
  if ( v67 )
  {
    v69 = 0;
    v88 = a2;
    v85 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    while ( 1 )
    {
      v73 = v68[3] & 2;
      if ( (v68[3] & 2) == 0 )
        break;
LABEL_62:
      if ( v67 <= (unsigned __int8)++v69 )
      {
        v8 = a7;
        v76 = v72;
        v77 = v85 + 2;
        a2 = v88;
        v78 = (unsigned __int8)(v85 + 2);
        goto LABEL_64;
      }
    }
    v74 = *(unsigned __int16 *)v68;
    if ( v68[2] )
    {
      if ( v68[2] == 1 )
      {
        v80 = v74 - 4992;
        if ( (unsigned __int16)(v80 - 13) <= 0x370u )
        {
          v75 = (unsigned int)(((unsigned int)dword_130B78 * (unsigned __int64)(unsigned int)(v80 - 8)) >> 32) >> 2;
          v73 = (unsigned __int8)v75;
          goto LABEL_58;
        }
      }
    }
    else if ( (unsigned int)(v74 - 2412) <= 0x48 )
    {
      if ( v74 == 2484 )
      {
        v73 = 14;
        v75 = 14;
      }
      else
      {
        v75 = (unsigned int)(((unsigned int)dword_130B78 * (unsigned __int64)(unsigned int)(v74 - 2407)) >> 32) >> 2;
        v73 = (unsigned __int8)v75;
      }
LABEL_58:
      if ( !v70 )
      {
        v71 = v73;
        v72 = v73;
        v70 = 1;
        goto LABEL_61;
      }
      if ( v75 - v71 == v87 )
      {
        v70 = (unsigned __int8)(v70 + 1);
        v71 = v73;
LABEL_61:
        v68 += 6;
        goto LABEL_62;
      }
      goto LABEL_71;
    }
    if ( !v70 )
    {
      v71 = 0;
      v72 = 0;
      v70 = 1;
      goto LABEL_61;
    }
LABEL_71:
    v89 = v66 + 1;
    *v66 = v72;
    v81 = v89++;
    *v81 = v70;
    v85 += 2;
    v71 = v73;
    v70 = (unsigned __int8)(v70 + 2);
    v66 = v89;
    goto LABEL_61;
  }
  v77 = 2;
  LOBYTE(v70) = 0;
  v76 = 0;
  v78 = 2;
LABEL_64:
  v89 = v66 + 1;
  *v66 = v76;
  v79 = v89++;
  *v79 = v70;
  v83 += v78 + 6;
  *v86 = v77;
LABEL_17:
  v34 = sub_130694((int)&v89);
  v35 = (int)v89;
  if ( v10 )
  {
    v36 = (char *)(a7 + 64);
    do
    {
      v37 = *v36++;
      v36[v35 - v8 - 65] = v37;
    }
    while ( v36 != &v15[v10] );
  }
  v38 = *(_DWORD *)(a2 + 224);
  v39 = v35 + v10;
  v40 = (unsigned __int16)(v83 + v10 + v34);
  v89 = (_BYTE *)v39;
  LOBYTE(v41) = v38;
  if ( (v38 & 1) != 0 )
  {
    v42 = *(_DWORD *)(dword_130B64 + 4);
    v43 = *(_DWORD *)(dword_130B64 + 8);
    v91[0] = *(_DWORD *)dword_130B64;
    v91[1] = v42;
    v92[1] = BYTE1(v43);
    v94 = 0;
    v93 = 0;
    v92[0] = 0;
    v44 = v39 - (_DWORD)v91;
    v45 = v91;
    for ( i = -35; ; i = v47 )
    {
      v45[v44] = i;
      if ( v45 == v92 )
        break;
      v47 = *++v45;
    }
    v40 = (unsigned __int16)(v40 + 9);
    v89 += 9;
    LOBYTE(v41) = v38;
  }
  if ( (v38 & 2) != 0 && (*((_BYTE *)off_130B68 + 374) & 1) != 0 )
  {
    v82 = sub_130500((int *)&v89);
    v41 = *(_DWORD *)(a2 + 224);
    v40 = (unsigned __int16)(v82 + v40);
  }
  if ( (v41 & 4) != 0 )
  {
    v48 = (unsigned __int16 *)off_130B68;
    v49 = *((unsigned __int8 *)off_130B68 + 374);
    if ( (v49 & 2) != 0 )
    {
      v58 = *((unsigned __int8 *)off_130B68 + 373);
      if ( (*(_BYTE *)off_130B74 & 8) != 0
        || (sub_12E948(dword_130BD0, v49 << 30), *((unsigned __int8 *)v48 + 373) <= 1u) )
      {
        v59 = v40 + sub_130658((int)&v89);
        v60 = sub_13248C(v48[28]);
        if ( v58 == 4 )
          LOBYTE(v58) = 3;
      }
      else
      {
        v59 = v40 + sub_130658((int)&v89);
        v60 = sub_13248C(v48[28]);
        LOBYTE(v58) = 1;
      }
      *v89 = -57;
      v89[1] = 1;
      v89[2] = v58 | (16 * v60);
      v41 = *(_DWORD *)(a2 + 224);
      v40 = (unsigned __int16)(v59 + 3);
      v89 += 3;
    }
  }
  if ( (v41 & 8) != 0 && (*((_BYTE *)off_130B68 + 374) & 4) != 0 )
    v40 = (unsigned __int16)((unsigned __int16)sub_130580((int)&v89) + v40);
  v50 = sub_12DB60(v15, v10);
  sub_137114(v15, v10, v84, v91);
  if ( *(_WORD *)(a2 + 228)
    && (!v50 && (v51 = v95 << 26, (v95 & 0x20) != 0) || (*(_DWORD *)(*((_DWORD *)off_130B70 + 4) + 48) & 0x40) != 0) )
  {
    sub_12EB90(256, dword_130B6C, v51);
    *v89 = 54;
    v89[1] = 3;
    v52 = (int)v89;
    *((_WORD *)v89 + 1) = *(_WORD *)(a2 + 228);
    *(_BYTE *)(v52 + 4) = *(_BYTE *)(a2 + 230);
    v40 = (unsigned __int16)(v40 + 5);
    v53 = (_WORD)v89 + 5;
  }
  else
  {
    v53 = (__int16)v89;
  }
  *a6 = v53 - *(_WORD *)a5;
  return v40;
}

