// sub_137640 @ 0x137640, size 1714 bytes
int __fastcall sub_137640(int a1)
{
  _BYTE *v1; // r11
  char v3; // r3
  char v4; // r1
  char v5; // r2
  char v6; // r0
  char v7; // r1
  char v8; // r2
  unsigned __int16 v9; // r0
  int v10; // r4
  __int16 v11; // r3
  __int16 v12; // r2
  unsigned __int8 *v13; // r0
  unsigned __int8 *v14; // r6
  int v15; // r4
  unsigned __int8 *v16; // r10
  _BYTE *v17; // r0
  _BYTE *v18; // r7
  int v19; // r3
  int v20; // r5
  unsigned __int8 *v21; // r9
  unsigned __int8 *v22; // r0
  unsigned __int8 *v23; // r11
  int v24; // r8
  unsigned __int8 *v25; // r7
  unsigned __int8 *v26; // r0
  int v27; // r5
  int v28; // r6
  int v29; // r1
  char *v30; // r3
  char *v31; // r2
  char *v33; // r3
  char *v34; // r1
  int v35; // r3
  int v36; // r2
  _BYTE *v37; // r3
  __int16 v38; // r1
  int v39; // r0
  _BYTE *v40; // r0
  int v41; // r1
  int v42; // r0
  int v43; // r1
  char *v44; // r0
  int v45; // r5
  int v46; // r3
  int v47; // r0
  int v48; // r6
  char v49; // r9
  int v50; // r8
  unsigned __int16 *v51; // r7
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  char *v60; // r3
  int v61; // r1
  int v62; // r2
  int v63; // r3
  int v64; // r4
  int v65; // r5
  unsigned __int16 *v66; // r10
  _DWORD *v67; // r4
  __int16 v68; // lr
  unsigned int v69; // r7
  int v70; // r8
  int v71; // r12
  unsigned int v72; // r2
  unsigned __int16 *v73; // r3
  int v74; // r1
  int v75; // r2
  int v76; // r3
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  char *v82; // r3
  int v83; // r1
  int v84; // r2
  unsigned int v85; // r2
  _WORD *v86; // r1
  int v87; // r0
  int v88; // r12
  int v89; // r1
  int v90; // r2
  int v91; // r3
  int v92; // r1
  int v93; // r2
  int v94; // r3
  int v95; // r1
  int v96; // r2
  char *v97; // r3
  int v98; // r1
  int v99; // r2
  int v100; // r0
  int v101; // r1
  int v102; // r2
  int v103; // r3
  int v104; // r1
  int v105; // r2
  int v106; // r3
  int v107; // r1
  int v108; // r2
  int v109; // r3
  int v110; // r1
  int v111; // r2
  int v112; // r1
  int v113; // r8
  int v114; // r1
  int v115; // r3
  unsigned __int16 v116; // r1
  int v117; // r1
  char v118; // r2
  _WORD **v119; // r3
  int v120; // r1
  int v121; // r2
  int v122; // r3
  unsigned __int16 *v123; // lr
  int v124; // r1
  int v125; // r2
  int v126; // r3
  int v127; // r1
  int v128; // r2
  char *v129; // r3
  int v130; // r1
  int v131; // r2
  _BYTE *v132; // [sp+1Ch] [bp-98h]
  int v133; // [sp+20h] [bp-94h]
  _BYTE *v134; // [sp+24h] [bp-90h]
  _BYTE *v135; // [sp+28h] [bp-8Ch]
  int v136; // [sp+2Ch] [bp-88h]
  int v138; // [sp+34h] [bp-80h]
  int v139; // [sp+38h] [bp-7Ch]
  _BYTE *v140; // [sp+3Ch] [bp-78h]
  unsigned __int8 v141; // [sp+47h] [bp-6Dh] BYREF
  unsigned __int16 v142; // [sp+48h] [bp-6Ch] BYREF
  unsigned __int16 v143; // [sp+4Ah] [bp-6Ah]
  unsigned __int16 v144; // [sp+4Ch] [bp-68h]
  int v145; // [sp+50h] [bp-64h] BYREF
  __int16 v146; // [sp+54h] [bp-60h]
  int v147; // [sp+74h] [bp-40h] BYREF
  int v148; // [sp+78h] [bp-3Ch]
  int v149; // [sp+7Ch] [bp-38h] BYREF
  int v150; // [sp+80h] [bp-34h]
  int v151; // [sp+84h] [bp-30h]
  int v152; // [sp+88h] [bp-2Ch]
  int v153; // [sp+8Ch] [bp-28h]
  int v154; // [sp+90h] [bp-24h]
  int v155; // [sp+94h] [bp-20h]
  int v156; // [sp+98h] [bp-1Ch]
  int v157; // [sp+9Ch] [bp-18h]
  char *v158; // [sp+A0h] [bp-14h]
  int v159; // [sp+A4h] [bp-10h]
  int v160; // [sp+A8h] [bp-Ch]
  int v161; // [sp+ACh] [bp-8h]
  char v162; // [sp+B0h] [bp-4h] BYREF

  v1 = off_137A84;
  v3 = *((_BYTE *)off_137A84 + 3852);
  v4 = *(_BYTE *)(a1 + 29);
  v5 = *(_BYTE *)(a1 + 30);
  LOBYTE(v142) = *(_BYTE *)(a1 + 28);
  HIBYTE(v142) = v4;
  v6 = *(_BYTE *)(a1 + 31);
  v7 = *(_BYTE *)(a1 + 32);
  LOBYTE(v143) = v5;
  v8 = *(_BYTE *)(a1 + 33);
  LOBYTE(v144) = v7;
  HIBYTE(v143) = v6;
  HIBYTE(v144) = v8;
  v139 = v3 & 1;
  if ( (v3 & 1) != 0 )
  {
    v9 = v143;
    LOWORD(v10) = v144;
    v139 = 0;
  }
  else if ( *((unsigned __int16 *)off_137A84 + 1926) != v142
         || (v9 = v143, *((unsigned __int16 *)off_137A84 + 1927) != v143)
         || (v10 = *((unsigned __int16 *)off_137A84 + 1928), v144 != v10) )
  {
    if ( !*((_BYTE *)off_137A74 + 408) || *((_BYTE *)off_137A84 + 3850) )
      return 0;
    v9 = v143;
    LOWORD(v10) = v144;
    v139 = 1;
  }
  v11 = *(_WORD *)(a1 + 46);
  v12 = *(_WORD *)a1;
  HIWORD(v147) = v142;
  LOWORD(v148) = v9;
  v140 = (_BYTE *)(a1 + 48);
  v138 = (unsigned __int16)(v12 - 36);
  HIWORD(v148) = v10;
  HIWORD(v157) = 2 - (v11 & 1);
  v13 = sub_12D918((unsigned __int8 *)(a1 + 48), v138, &v141);
  if ( v13 )
  {
    LOBYTE(v149) = v141;
    if ( v141 )
    {
      v33 = (char *)&v149;
      v34 = (char *)&v149 + v141;
      do
      {
        v33[1] = v33[(_DWORD)v13 + 54 - (_DWORD)&v162];
        ++v33;
      }
      while ( v34 != v33 );
    }
  }
  else
  {
    LOBYTE(v149) = 0;
  }
  v14 = nullptr;
  v1[4029] = 0;
  if ( v138 )
  {
    v133 = v138;
    v132 = (_BYTE *)(a1 + 48);
    v15 = 0;
    v16 = nullptr;
    v134 = v1;
    while ( 1 )
    {
      v17 = sub_12DD48(v132, v133);
      v18 = v17;
      if ( !v17 )
        goto LABEL_18;
      v19 = (unsigned __int8)v17[1];
      v134[4028] = v17[2];
      v20 = (unsigned __int16)(v19 - 1);
      v136 = v19 + 2;
      v21 = v17 + 3;
      if ( (_WORD)v19 == 1 )
        goto LABEL_17;
      v135 = v17;
      while ( 1 )
      {
        v22 = sub_12DD88(v21, v20);
        v23 = v22;
        if ( !v22 )
          break;
        v24 = v22[1];
        v25 = v22 + 2;
        v20 = (unsigned __int16)(v20 - (v24 + 2));
        v21 += v24 + 2;
        if ( sub_12DDD0(v22 + 2, 4) )
        {
          v16 = v23 + 4;
          v15 = ((int (__fastcall *)(unsigned __int8 *, int))dword_12DE10[0])(v25, v24);
          goto LABEL_13;
        }
        if ( v16 )
        {
          if ( v15 )
          {
            if ( !v14 )
            {
              v14 = sub_12D918(v25, v24, &v145);
              if ( !v14 )
                goto LABEL_15;
            }
            goto LABEL_40;
          }
          v39 = ((int (__fastcall *)(unsigned __int8 *, int))dword_12DE10[0])(v25, v24);
          v15 = v39;
          if ( v14 )
          {
            if ( v39 )
              goto LABEL_40;
            if ( !v20 )
              break;
          }
          else
          {
LABEL_13:
            v26 = sub_12D918(v25, v24, &v145);
            v14 = v26;
            if ( !v15 || !v26 )
              goto LABEL_15;
LABEL_40:
            v35 = (unsigned __int8)v134[4029];
            v36 = (unsigned __int8)(v35 + 1);
            v37 = &v134[8 * v35];
            v38 = *v16 | (v16[1] << 8);
            v37[3906] = *(_BYTE *)(v15 + 2);
            *((_DWORD *)v37 + 975) = v14;
            *((_WORD *)v37 + 1952) = v38;
            v134[4029] = v36;
            if ( v36 == 16 )
              goto LABEL_18;
            v16 = nullptr;
            if ( !v20 )
              break;
          }
        }
        else
        {
LABEL_15:
          if ( !v20 )
            break;
        }
      }
      v18 = v135;
LABEL_17:
      v133 = (unsigned __int16)(v133 + (_WORD)v132 - (_WORD)v18 - v136);
      v132 = &v18[v136];
      if ( !v133 )
      {
LABEL_18:
        v1 = v134;
        break;
      }
    }
  }
  if ( !v139 && !sub_1371DC((unsigned __int8 *)&v149) )
  {
    if ( !v1[4029] )
      return 0;
    v27 = dword_137A70;
    v28 = 0;
    while ( 1 )
    {
      v29 = *(_DWORD *)(v27 + 8 * v28);
      LOBYTE(v145) = *(_BYTE *)(v29 + 1);
      if ( (_BYTE)v145 )
      {
        v30 = (char *)&v145;
        v31 = (char *)&v145 + (unsigned __int8)v145;
        do
        {
          v30[1] = v30[v29 + 98 - (_DWORD)&v162];
          ++v30;
        }
        while ( v31 != v30 );
      }
      if ( sub_1371DC((unsigned __int8 *)&v145) )
        break;
      if ( ++v28 >= (unsigned __int8)v1[4029] )
        return 0;
    }
  }
  v40 = sub_12DB60(v140, v138);
  if ( v40 )
  {
    v41 = (unsigned __int8)v40[2];
    v42 = *(unsigned __int8 *)(a1 + 6);
    if ( *(_BYTE *)(a1 + 6) )
    {
      if ( v42 == 1 && (unsigned __int8)(v41 - 1) <= 0xB0u )
      {
LABEL_53:
        v43 = 5 * v41 + 5000;
LABEL_56:
        v44 = sub_1321FC(v42, v43);
        v45 = 1;
        v158 = v44;
        goto LABEL_57;
      }
LABEL_55:
      v43 = 0;
      goto LABEL_56;
    }
LABEL_54:
    if ( (unsigned int)(v41 - 1) <= 0xD )
    {
      if ( v41 == 14 )
        v43 = 2484;
      else
        v43 = 5 * v41 + 2407;
      goto LABEL_56;
    }
    goto LABEL_55;
  }
  v45 = (int)sub_12DEB8(v140, v138);
  if ( v45 )
  {
    v42 = *(unsigned __int8 *)(a1 + 6);
    v41 = *(unsigned __int8 *)(v45 + 2);
    if ( *(_BYTE *)(a1 + 6) )
    {
      if ( v42 != 1 || (unsigned __int8)(v41 - 1) > 0xB0u )
      {
        v43 = 0;
        goto LABEL_56;
      }
      goto LABEL_53;
    }
    goto LABEL_54;
  }
  v44 = sub_1321FC(*(unsigned __int8 *)(a1 + 6), *(unsigned __int16 *)(a1 + 4));
  v158 = v44;
LABEL_57:
  v46 = *(unsigned __int16 *)v44;
  if ( *(unsigned __int16 *)(a1 + 4) != v46 )
    *(_WORD *)(a1 + 4) = v46;
  rx_status_init_n54(v140, v138, *(_WORD *)(a1 + 46), (int)&v147);
  v47 = rf_stream_start2_n_14(&v142, 1);
  v48 = v47;
  if ( !v47 )
    goto LABEL_78;
  v49 = *(_BYTE *)v47;
  v50 = *(char *)(a1 + 9);
  v51 = (unsigned __int16 *)v158;
  if ( *(_BYTE *)v47 )
  {
    if ( *(unsigned __int8 *)(v47 + 8) != (unsigned __int8)v149 )
    {
      if ( *(_BYTE *)(v47 + 8) && !(_BYTE)v149 )
      {
        LOBYTE(v50) = *(_BYTE *)(v47 + 56);
        v51 = *(unsigned __int16 **)(v47 + 44);
      }
      goto LABEL_63;
    }
    v87 = sub_143710(*(_DWORD *)(v47 + 44), v158, 6);
    if ( *(unsigned __int8 *)(v48 + 8) == (unsigned __int8)v149 )
    {
      v88 = *(char *)(v48 + 56);
      if ( v88 > v50 )
      {
LABEL_92:
        v51 = *(unsigned __int16 **)(v48 + 44);
        LOBYTE(v50) = v88;
        if ( !v87 )
        {
          v89 = v148;
          v90 = v149;
          v91 = v150;
          *(_DWORD *)v48 = v147;
          *(_DWORD *)(v48 + 4) = v89;
          *(_DWORD *)(v48 + 8) = v90;
          *(_DWORD *)(v48 + 12) = v91;
          v92 = v152;
          v93 = v153;
          v94 = v154;
          *(_DWORD *)(v48 + 16) = v151;
          *(_DWORD *)(v48 + 20) = v92;
          *(_DWORD *)(v48 + 24) = v93;
          *(_DWORD *)(v48 + 28) = v94;
          v95 = v156;
          v96 = v157;
          v97 = v158;
          *(_DWORD *)(v48 + 32) = v155;
          *(_DWORD *)(v48 + 36) = v95;
          *(_DWORD *)(v48 + 40) = v96;
          *(_DWORD *)(v48 + 44) = v97;
          v98 = v160;
          v99 = v161;
          *(_DWORD *)(v48 + 48) = v159;
          *(_DWORD *)(v48 + 52) = v98;
          *(_DWORD *)(v48 + 56) = v99;
          *(_BYTE *)(v48 + 56) = v88;
          *(_DWORD *)(v48 + 44) = v51;
          *(_BYTE *)v48 = v49;
          goto LABEL_68;
        }
        goto LABEL_63;
      }
    }
    if ( *(_BYTE *)(v48 + 8) && !(_BYTE)v149 )
    {
      LOBYTE(v88) = *(_BYTE *)(v48 + 56);
      goto LABEL_92;
    }
    if ( v87 )
    {
LABEL_63:
      v52 = v148;
      v53 = v149;
      v54 = v150;
      *(_DWORD *)v48 = v147;
      *(_DWORD *)(v48 + 4) = v52;
      *(_DWORD *)(v48 + 8) = v53;
      *(_DWORD *)(v48 + 12) = v54;
      v55 = v152;
      v56 = v153;
      v57 = v154;
      *(_DWORD *)(v48 + 16) = v151;
      *(_DWORD *)(v48 + 20) = v55;
      *(_DWORD *)(v48 + 24) = v56;
      *(_DWORD *)(v48 + 28) = v57;
      v58 = v156;
      v59 = v157;
      v60 = v158;
      *(_DWORD *)(v48 + 32) = v155;
      *(_DWORD *)(v48 + 36) = v58;
      *(_DWORD *)(v48 + 40) = v59;
      *(_DWORD *)(v48 + 44) = v60;
      v61 = v160;
      v62 = v161;
      *(_DWORD *)(v48 + 48) = v159;
      *(_DWORD *)(v48 + 52) = v61;
      *(_DWORD *)(v48 + 56) = v62;
      *(_BYTE *)(v48 + 56) = v50;
      *(_DWORD *)(v48 + 44) = v51;
      *(_BYTE *)v48 = v49;
      goto LABEL_64;
    }
    v120 = v148;
    v121 = v149;
    v122 = v150;
    v123 = *(unsigned __int16 **)(v48 + 44);
    *(_DWORD *)v48 = v147;
    *(_DWORD *)(v48 + 4) = v120;
    *(_DWORD *)(v48 + 8) = v121;
    *(_DWORD *)(v48 + 12) = v122;
    v124 = v152;
    v125 = v153;
    v126 = v154;
    *(_DWORD *)(v48 + 16) = v151;
    *(_DWORD *)(v48 + 20) = v124;
    *(_DWORD *)(v48 + 24) = v125;
    *(_DWORD *)(v48 + 28) = v126;
    v127 = v156;
    v128 = v157;
    v129 = v158;
    *(_DWORD *)(v48 + 32) = v155;
    *(_DWORD *)(v48 + 36) = v127;
    *(_DWORD *)(v48 + 40) = v128;
    *(_DWORD *)(v48 + 44) = v129;
    v130 = v160;
    v131 = v161;
    *(_DWORD *)(v48 + 48) = v159;
    *(_DWORD *)(v48 + 52) = v130;
    *(_DWORD *)(v48 + 56) = v131;
    *(_BYTE *)(v48 + 56) = v50;
    *(_DWORD *)(v48 + 44) = v51;
    *(_BYTE *)v48 = v49;
    if ( v123 == v51 )
      goto LABEL_68;
  }
  else
  {
    v74 = v148;
    v75 = v149;
    v76 = v150;
    *(_DWORD *)v47 = v147;
    *(_DWORD *)(v47 + 4) = v74;
    *(_DWORD *)(v47 + 8) = v75;
    *(_DWORD *)(v47 + 12) = v76;
    v77 = v152;
    v78 = v153;
    v79 = v154;
    *(_DWORD *)(v47 + 16) = v151;
    *(_DWORD *)(v47 + 20) = v77;
    *(_DWORD *)(v47 + 24) = v78;
    *(_DWORD *)(v47 + 28) = v79;
    v80 = v156;
    v81 = v157;
    v82 = v158;
    *(_DWORD *)(v47 + 32) = v155;
    *(_DWORD *)(v47 + 36) = v80;
    *(_DWORD *)(v47 + 40) = v81;
    *(_DWORD *)(v47 + 44) = v82;
    v83 = v160;
    v84 = v161;
    *(_DWORD *)(v47 + 48) = v159;
    *(_DWORD *)(v47 + 52) = v83;
    *(_DWORD *)(v47 + 56) = v84;
    *(_BYTE *)(v47 + 56) = v50;
    *(_DWORD *)(v47 + 44) = v51;
    ++*((_WORD *)v1 + 2);
    *(_BYTE *)v47 = 1;
    v85 = *((unsigned __int8 *)v51 + 2);
    if ( v85 <= 1 )
    {
      v63 = *(unsigned __int8 *)(v47 + 8);
      if ( !*(_BYTE *)(v47 + 8) )
      {
        if ( (**(_WORD **)off_137CF8 & 8) == 0 )
          goto LABEL_68;
        v64 = dword_137CFC;
        goto LABEL_67;
      }
      v86 = *(_WORD **)off_137CF8;
      ++*(_WORD *)(dword_137CF4 + 2 * v85 + 4);
      if ( (*v86 & 8) == 0 )
        goto LABEL_68;
      goto LABEL_83;
    }
  }
LABEL_64:
  if ( (**(_WORD **)off_137A78 & 8) != 0 )
  {
    v63 = *(unsigned __int8 *)(v48 + 8);
    if ( !*(_BYTE *)(v48 + 8) )
    {
      v51 = *(unsigned __int16 **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
      v64 = dword_137A7C;
LABEL_67:
      msg_parse(
        dword_137A80,
        *((unsigned __int16 *)v1 + 2),
        *v51,
        v45,
        *(unsigned __int8 *)(a1 + 12),
        *(unsigned __int16 *)(a1 + 34) >> 4,
        v50,
        v63,
        v64);
      goto LABEL_68;
    }
LABEL_83:
    v64 = v48 + 9;
    if ( sub_143E40(v48 + 9) )
    {
      v63 = *(unsigned __int8 *)(v48 + 8);
      *(_BYTE *)(v48 + v63 + 9) = 0;
      v51 = *(unsigned __int16 **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
    }
    else
    {
      v51 = *(unsigned __int16 **)(v48 + 44);
      v50 = *(char *)(a1 + 9);
      v64 = dword_137CFC;
      v63 = *(unsigned __int8 *)(v48 + 8);
    }
    goto LABEL_67;
  }
LABEL_68:
  v65 = 0;
  *(_BYTE *)(v48 + 57) = 0;
  *(_BYTE *)(v48 + 58) = 0;
  v66 = (unsigned __int16 *)off_137A84;
  if ( v1[4029] )
  {
    v67 = off_137A84;
    while ( 2 )
    {
      v68 = *((unsigned __int8 *)v67 + 3906);
      if ( *((_BYTE *)v67 + 3906) )
      {
        v69 = *((unsigned __int8 *)v66 + 4028);
        if ( v69 <= 8 )
        {
          v70 = *(unsigned __int8 *)(v67[975] + 1);
          v145 = *(_DWORD *)(v48 + 2);
          v146 = *(_WORD *)(v48 + 6);
          v71 = (1 << v69) - 1;
          v72 = (unsigned __int16)(v146 ^ ((*(_WORD *)(v48 + 6) + (v68 << 8)) ^ v146) & ((_WORD)v71 << 8));
          v146 ^= ((*(_WORD *)(v48 + 6) + (v68 << 8)) ^ v146) & (unsigned __int16)((_WORD)v71 << 8);
          v73 = v66;
          do
          {
            if ( *((_BYTE *)v73 + 8)
              && v73[5] == (unsigned __int16)v145
              && __PAIR64__(v73[7], v73[6]) == __PAIR64__(v72, HIWORD(v145)) )
            {
              goto LABEL_77;
            }
            v73 += 30;
          }
          while ( v66 + 1920 != v73 );
          v100 = rf_stream_start2_n_14((unsigned __int16 *)&v145, 1);
          if ( !v100 )
            break;
          v101 = *(_DWORD *)(v48 + 4);
          v102 = *(_DWORD *)(v48 + 8);
          v103 = *(_DWORD *)(v48 + 12);
          *(_DWORD *)v100 = *(_DWORD *)v48;
          *(_DWORD *)(v100 + 4) = v101;
          *(_DWORD *)(v100 + 8) = v102;
          *(_DWORD *)(v100 + 12) = v103;
          v104 = *(_DWORD *)(v48 + 20);
          v105 = *(_DWORD *)(v48 + 24);
          v106 = *(_DWORD *)(v48 + 28);
          *(_DWORD *)(v100 + 16) = *(_DWORD *)(v48 + 16);
          *(_DWORD *)(v100 + 20) = v104;
          *(_DWORD *)(v100 + 24) = v105;
          *(_DWORD *)(v100 + 28) = v106;
          v107 = *(_DWORD *)(v48 + 36);
          v108 = *(_DWORD *)(v48 + 40);
          v109 = *(_DWORD *)(v48 + 44);
          *(_DWORD *)(v100 + 32) = *(_DWORD *)(v48 + 32);
          *(_DWORD *)(v100 + 36) = v107;
          *(_DWORD *)(v100 + 40) = v108;
          *(_DWORD *)(v100 + 44) = v109;
          v110 = *(_DWORD *)(v48 + 52);
          v111 = *(_DWORD *)(v48 + 56);
          *(_DWORD *)(v100 + 48) = *(_DWORD *)(v48 + 48);
          *(_DWORD *)(v100 + 52) = v110;
          *(_DWORD *)(v100 + 56) = v111;
          *(_DWORD *)(v100 + 2) = v145;
          LOWORD(v109) = v146;
          *(_BYTE *)(v100 + 8) = v70;
          v112 = v67[975];
          *(_WORD *)(v100 + 6) = v109;
          if ( v70 )
          {
            v113 = v70 + 8 + v100;
            v114 = v112 - 6 - v100;
            v115 = v100 + 8;
            do
            {
              *(_BYTE *)(v115 + 1) = *(_BYTE *)(v114 + v115);
              ++v115;
            }
            while ( v115 != v113 );
          }
          v116 = v66[2];
          *(_BYTE *)(v100 + 58) = v69;
          v117 = (unsigned __int16)(v116 + 1);
          v118 = *((_BYTE *)v67 + 3906);
          v66[2] = v117;
          *(_BYTE *)v100 = 1;
          v119 = (_WORD **)off_137CF8;
          *(_BYTE *)(v100 + 57) = v118;
          if ( (**v119 & 8) == 0 )
          {
LABEL_77:
            ++v65;
            v67 += 2;
            if ( v65 < *((unsigned __int8 *)v66 + 4029) )
              continue;
            break;
          }
          *(_BYTE *)(*(unsigned __int8 *)(v48 + 8) + v100 + 9) = 0;
          msg_parse(dword_137D00, v117, **(unsigned __int16 **)(v100 + 44), *(unsigned __int8 *)(v100 + 8), v100 + 9);
          ++v65;
          v67 += 2;
          if ( v65 < *((unsigned __int8 *)v66 + 4029) )
            continue;
        }
      }
      break;
    }
  }
LABEL_78:
  if ( v139 )
    return 0;
  message_dispatch_n94(a1, 4100, 13, 4);
  return 1;
}

