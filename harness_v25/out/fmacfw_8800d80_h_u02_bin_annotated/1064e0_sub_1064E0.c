// fwstruct annotate: 1064e0_sub_1064E0.c
// sub_1064E0 @ 0x1064e0, size 2964 bytes
int __fastcall sub_1064E0(unsigned int a1, int a2, __int16 *a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // r9
  unsigned int *v8; // r8
  unsigned int *v9; // r10
  unsigned int *v10; // r4
  unsigned int *v11; // lr
  unsigned int *v12; // r7
  unsigned int *v13; // r12
  unsigned int *v14; // r5
  unsigned int *v15; // r6
  unsigned int v16; // r9
  unsigned int v17; // r8
  unsigned int v18; // r7
  int v19; // r6
  void *v23; // r3
  void *v24; // r3
  void *v25; // r3
  _DWORD *v26; // r3
  int v27; // r7
  _DWORD *v28; // r0
  _DWORD *v29; // r2
  unsigned int *v30; // r1
  _DWORD *v31; // r5
  _DWORD *v32; // r2
  _DWORD *v33; // r2
  __int16 *v34; // r9
  _DWORD *v35; // r8
  int v36; // r7
  int v37; // r3
  __int16 v38; // t1
  int v39; // r2
  int v40; // r1
  int v41; // r5
  _DWORD *v42; // r6
  int v43; // r8
  int v44; // r2
  unsigned int *v45; // r4
  unsigned int *v46; // r5
  unsigned int *v47; // r9
  unsigned int *v48; // r11
  _DWORD *v49; // r8
  _DWORD *v50; // r1
  unsigned int *v51; // r2
  unsigned int *v52; // r12
  unsigned int *v53; // r3
  unsigned int *v54; // r6
  unsigned int *v55; // r0
  unsigned int *v56; // r7
  unsigned int *v57; // r2
  _DWORD *v58; // r10
  int v60; // r3
  int v61; // r8
  int v62; // r9
  int v63; // r11
  int v64; // r7
  int v65; // r6
  unsigned int v66; // r5
  int v67; // r3
  int v68; // r7
  int *v69; // r6
  _DWORD *v70; // r7
  int v71; // r9
  int v72; // r11
  int v73; // r8
  unsigned int *v74; // r6
  unsigned int v75; // r5
  char v76; // r3
  int v77; // r6
  int *v78; // r3
  int *v79; // r12
  int *v80; // r2
  int v81; // r0
  int *v82; // r1
  unsigned int v83; // [sp+Ch] [bp-C8h]
  char v84; // [sp+Ch] [bp-C8h]
  int v85; // [sp+Ch] [bp-C8h]
  unsigned int v86; // [sp+10h] [bp-C4h]
  int v87; // [sp+10h] [bp-C4h]
  unsigned int v88; // [sp+14h] [bp-C0h]
  int v89; // [sp+14h] [bp-C0h]
  unsigned int v90; // [sp+18h] [bp-BCh]
  int v91; // [sp+18h] [bp-BCh]
  unsigned int v92; // [sp+1Ch] [bp-B8h]
  int v93; // [sp+1Ch] [bp-B8h]
  unsigned int v94; // [sp+20h] [bp-B4h]
  int v95; // [sp+20h] [bp-B4h]
  unsigned int v96; // [sp+24h] [bp-B0h]
  int v97; // [sp+24h] [bp-B0h]
  unsigned int v98; // [sp+28h] [bp-ACh]
  int v99; // [sp+28h] [bp-ACh]
  unsigned int v100; // [sp+2Ch] [bp-A8h]
  int v101; // [sp+2Ch] [bp-A8h]
  unsigned int v102; // [sp+30h] [bp-A4h]
  int v103; // [sp+30h] [bp-A4h]
  unsigned int v104; // [sp+34h] [bp-A0h]
  int v105; // [sp+34h] [bp-A0h]
  unsigned int v106; // [sp+38h] [bp-9Ch]
  int v107; // [sp+38h] [bp-9Ch]
  unsigned int v108; // [sp+3Ch] [bp-98h]
  int v109; // [sp+3Ch] [bp-98h]
  unsigned int v110; // [sp+40h] [bp-94h]
  int v111; // [sp+40h] [bp-94h]
  unsigned int v112; // [sp+44h] [bp-90h]
  int v113; // [sp+44h] [bp-90h]
  unsigned int v114; // [sp+48h] [bp-8Ch]
  int v115; // [sp+48h] [bp-8Ch]
  unsigned int v116; // [sp+4Ch] [bp-88h]
  int v117; // [sp+4Ch] [bp-88h]
  unsigned int v118; // [sp+50h] [bp-84h]
  int v119; // [sp+50h] [bp-84h]
  unsigned int v120; // [sp+54h] [bp-80h]
  int v121; // [sp+54h] [bp-80h]
  unsigned int v122; // [sp+58h] [bp-7Ch]
  int v123; // [sp+58h] [bp-7Ch]
  unsigned int v124; // [sp+5Ch] [bp-78h]
  int v125; // [sp+5Ch] [bp-78h]
  unsigned int v126; // [sp+60h] [bp-74h]
  int v127; // [sp+60h] [bp-74h]
  unsigned int v128; // [sp+64h] [bp-70h]
  int v129; // [sp+64h] [bp-70h]
  unsigned int v130; // [sp+68h] [bp-6Ch]
  int v131; // [sp+68h] [bp-6Ch]
  unsigned int v132; // [sp+6Ch] [bp-68h]
  int v133; // [sp+6Ch] [bp-68h]
  unsigned int v134; // [sp+70h] [bp-64h]
  int v135; // [sp+70h] [bp-64h]
  unsigned int v136; // [sp+74h] [bp-60h]
  int v137; // [sp+74h] [bp-60h]
  unsigned int v138; // [sp+78h] [bp-5Ch]
  int v139; // [sp+78h] [bp-5Ch]
  int v140; // [sp+7Ch] [bp-58h]
  int v141; // [sp+80h] [bp-54h]
  int v142; // [sp+84h] [bp-50h]
  int v143; // [sp+88h] [bp-4Ch]
  int v144; // [sp+8Ch] [bp-48h]
  int v145; // [sp+90h] [bp-44h]
  int v146; // [sp+94h] [bp-40h]
  int v147; // [sp+98h] [bp-3Ch]
  int v148; // [sp+98h] [bp-3Ch]
  char v149; // [sp+9Ch] [bp-38h]
  int v150; // [sp+A0h] [bp-34h]
  int v151; // [sp+A4h] [bp-30h]
  int v152; // [sp+A8h] [bp-2Ch]
  int v153; // [sp+ACh] [bp-28h]
  int v154; // [sp+B0h] [bp-24h]
  int v155; // [sp+B4h] [bp-20h]
  unsigned int v156; // [sp+B8h] [bp-1Ch]
  int v157; // [sp+BCh] [bp-18h]
  int v158; // [sp+C0h] [bp-14h]
  int v159; // [sp+C4h] [bp-10h]
  int v160; // [sp+C8h] [bp-Ch]
  int v161; // [sp+CCh] [bp-8h]

  v7 = off_1067E8;
  v8 = (unsigned int *)off_1067EC;
  v9 = (unsigned int *)off_1067F0;
  v10 = (unsigned int *)off_1067C0;
  v11 = (unsigned int *)off_1067F4;
  v12 = (unsigned int *)off_1067C4;
  v13 = (unsigned int *)off_1067F8;
  v14 = (unsigned int *)off_1067C8;
  *(_DWORD *)off_1067E8 |= 0x400u;
  *v7 &= ~0x400u;
  v86 = *v8;
  v88 = *v9;
  v90 = *v10;
  v92 = *v10;
  v94 = *v11;
  v96 = *v12;
  v98 = *v12;
  v100 = *v12;
  v102 = *v12;
  v104 = *v8;
  v138 = *(_DWORD *)off_1067CC;
  v136 = *(_DWORD *)off_1067CC;
  *v8 |= 0x20u;
  v15 = (unsigned int *)off_1067CC;
  *v9 = *v9 & 0xF8FFFFFF | 0x2000000;
  *v10 |= 0x100000u;
  *v10 |= 0x200000u;
  *v11 = *v11 & 0xFFFFFF0F | 0xC0;
  *v13 = *v13 & 0xFFFFFFC7 | 0x20;
  *v12 |= 0x400u;
  *v12 = *v12 & 0xFFFFFCFF | 0x100;
  *v15 = *v15 & 0xFFFE00FF | 0x100;
  *v15 |= 0x20000u;
  *v15 |= 0x40000u;
  v106 = *v13;
  v108 = *(unsigned int *)((char *)v15 + 0xFFFFFFC8);
  v110 = *v14;
  v112 = *v14;
  v114 = *v14;
  v116 = *v14;
  v118 = *v10;
  v120 = *v10;
  v122 = *v10;
  v124 = *v10;
  v126 = *(_DWORD *)off_1067D0;
  v128 = *(_DWORD *)off_1067D4;
  v130 = *v11;
  v132 = *(_DWORD *)off_1067D8;
  v134 = *v11;
  v144 = *(_DWORD *)off_1067DC;
  v83 = *v10;
  v17 = *v10;
  v16 = *v10;
  v143 = *(_DWORD *)off_1067E0;
  v18 = *(_DWORD *)off_1067E4;
  *v13 |= 0x40u;
  *(unsigned int *)((char *)v15 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v14 |= 0x800000u;
  v19 = a4;
  v87 = (v86 >> 5) & 1;
  v89 = HIBYTE(v88) & 7;
  v91 = (v90 >> 21) & 1;
  v93 = (v92 >> 20) & 1;
  v95 = (unsigned __int8)v94 >> 4;
  v97 = (v96 >> 7) & 1;
  v99 = (v98 >> 4) & 7;
  v101 = (v100 >> 10) & 1;
  v103 = (v102 >> 8) & 3;
  v105 = (v104 >> 2) & 7;
  v146 = (v138 >> 22) & 1;
  v145 = (v136 >> 21) & 1;
  v107 = (v106 >> 6) & 1;
  v109 = (v108 >> 12) & 7;
  v111 = (v110 >> 23) & 1;
  v113 = (v112 >> 22) & 1;
  v115 = (v114 >> 20) & 1;
  v117 = (v116 >> 21) & 1;
  v119 = (v118 >> 17) & 1;
  v121 = HIWORD(v120) & 1;
  v123 = (v122 >> 15) & 1;
  v125 = (v124 >> 14) & 1;
  v127 = (v126 >> 18) & 1;
  v129 = (v128 >> 12) & 3;
  v131 = v130 & 3;
  v133 = (v132 >> 18) & 7;
  v135 = (v134 >> 2) & 1;
  v137 = (v16 >> 23) & 1;
  v139 = (v17 >> 22) & 1;
  v141 = (v83 >> 18) & 1;
  v142 = (v18 >> 8) & 1;
  v140 = (v83 >> 19) & 1;
  *v14 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (unsigned __int8)(a4 - 1);
  while ( a4 );
  v23 = off_1067C8;
  *(_DWORD *)off_1067C8 &= ~0x100000u;
  *(_DWORD *)v23 |= 0x200000u;
  LOBYTE(v23) = 60;
  do
    v23 = (void *)(unsigned __int8)((_BYTE)v23 - 1);
  while ( v23 );
  v24 = off_1067C0;
  *(_DWORD *)off_1067C8 |= 0x100000u;
  *(_DWORD *)v24 |= 0x20000u;
  *(_DWORD *)v24 |= 0x10000u;
  LOBYTE(v24) = 90;
  do
    v24 = (void *)(unsigned __int8)((_BYTE)v24 - 1);
  while ( v24 );
  v25 = off_106980;
  *(_DWORD *)off_106980 &= ~0x40000u;
  *(_DWORD *)v25 |= 0x80000u;
  LOBYTE(v25) = 60;
  do
    v25 = (void *)(unsigned __int8)((_BYTE)v25 - 1);
  while ( v25 );
  v26 = off_106980;
  *(_DWORD *)off_106980 |= 0x40000u;
  *v26 |= 0x8000u;
  *v26 |= 0x4000u;
  LOBYTE(v27) = 90;
  do
    v27 = (unsigned __int8)(v27 - 1);
  while ( v27 );
  v28 = off_106984;
  v29 = off_106988;
  v30 = (unsigned int *)off_10698C;
  v31 = off_106990;
  *(_DWORD *)off_106984 |= 0x40000u;
  *v29 |= 0x3000u;
  v32 = off_106980;
  *v30 = *v30 & 0xFFFFFFFC | 1;
  v28[16] = v28[16] & 0xFFE3FFFF | 0xC0000;
  *v30 |= 4u;
  *v32 |= 0x800000u;
  *v32 |= 0x400000u;
  *v31 &= ~0x100u;
  sub_103B54();
  sub_104080();
  v33 = off_106998;
  *(_DWORD *)off_106994 |= 0x10000000u;
  *v33 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v60 = (a1 >> 12) & 3;
      *(_DWORD *)off_106FE8 = a1;
      if ( v60 == 1 )
      {
        v158 = 0;
        v159 = *(_DWORD *)off_107074;
        v154 = -2;
        v84 = 31;
        v153 = 1;
        v147 = 1;
        v61 = 4;
        v63 = 0x7FFFFFFF;
        v157 = 3;
        v149 = 1;
        v151 = 0x7FFFFFFF;
        v152 = 4;
        v62 = 0;
      }
      else
      {
        if ( v60 == 2 )
        {
          v159 = *(_DWORD *)off_107078;
          v61 = 8;
          v154 = dword_10707C;
          v153 = dword_107080;
        }
        else
        {
          v159 = *(_DWORD *)off_106FEC;
          v153 = dword_106FF4;
          v61 = 8;
          v154 = dword_106FF0;
        }
        a7 = 2;
        v158 = 8;
        v62 = 2;
        v84 = 13;
        v147 = -1;
        v151 = -122881;
        v157 = 15;
        v149 = -13;
        v63 = 0x1FFF;
        v152 = 16;
      }
      v64 = (*(_DWORD *)(dword_106FF8 - 18832) >> 8) & 0xF;
      v65 = (v60 << 8) + dword_106FF8;
      v160 = v65;
      sub_12EB90(1, dword_106FFC);
      *(_DWORD *)(a2 + 140) = *(_DWORD *)(a2 + 152);
      sub_1063A4(a2, 0);
      v66 = 0;
      sub_12EB90(1, dword_107000);
      v150 = v62;
      v67 = v64;
      v68 = v65 + 16 * v64;
      v69 = (int *)(v68 + v158);
      v70 = (_DWORD *)(v68 + v61);
      v161 = v61;
      v155 = v63;
      v156 = 0;
      v71 = 0;
      v72 = v67;
      v73 = 2 * v67;
      do
      {
        sub_102BF8(1);
        if ( v150 == a7 )
        {
          *v69 = *v69 & v151 | ((v157 & v66) << v84);
        }
        else
        {
          *v69 &= v155;
          *v70 &= v154;
          *v69 |= (v147 & v66) << v84;
          *v70 |= (v66 >> v149) & v153;
        }
        sub_102C5C(1);
        sub_104FA8(*a3, a2, v72, 0);
        sub_12EB90(1, dword_107004);
        sub_12EB90(1, dword_10700C);
        sub_12EB90(1, dword_107014);
        if ( *(__int16 *)(a2 + v73) > v71 )
        {
          v71 = *(__int16 *)(a2 + v73);
          v156 = v66;
        }
        ++v66;
      }
      while ( v152 != v66 );
      sub_12EB90(1, dword_10701C);
      sub_102BF8(1);
      v76 = v84;
      v85 = (v156 >> v149) & v153;
      v77 = (v147 & v156) << v76;
      v148 = (v156 & v157) << v76;
      v78 = (int *)(v160 + v158);
      v79 = (int *)(v158 + 192 + v159);
      v80 = (int *)(v159 + v158);
      v81 = v161 - v158;
      do
      {
        while ( 1 )
        {
          v82 = &v80[v158 / 0xFFFFFFFC];
          if ( v150 == a7 )
            break;
          *v78 &= v155;
          *(int *)((char *)v78 + v81) &= v154;
          *v78 |= v77;
          *(int *)((char *)v78 + v81) |= v85;
          *v80 &= v155;
          *(int *)((char *)v82 + v161) &= v154;
          *v80 |= v77;
          v80 += 3;
          *(int *)((char *)v82 + v161) |= v85;
          v78 += 4;
          if ( v79 == v80 )
            goto LABEL_50;
        }
        *v78 = *v78 & v151 | v148;
        *v80 = *v80 & v151 | v148;
        v80 += 3;
        v78 += 4;
      }
      while ( v79 != v80 );
LABEL_50:
      sub_102C5C(1);
      sub_12EB90(1, dword_107020);
      sub_12EB90(1, dword_107024);
    }
    goto LABEL_28;
  }
  if ( v19 )
  {
    v74 = (unsigned int *)off_106FE8;
    *(_DWORD *)off_106FE8 = a1;
    *v31 &= ~0x200u;
    *v31 |= 0x200u;
    *v31 &= ~0x200u;
    v75 = *v74;
    sub_1063A4(a2, 0);
    sub_12EB90(1, dword_107018);
    sub_104FA8(*a3, a2, (v75 >> 8) & 0xF, 0);
    goto LABEL_28;
  }
  *(_QWORD *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v34 = a3 - 1;
  v35 = (_DWORD *)(a2 + 140);
  do
  {
    if ( v19 == 2 )
    {
      v36 = *(_DWORD *)(a2 + 124);
LABEL_18:
      v37 = -5;
      goto LABEL_19;
    }
    if ( v19 == 1 )
    {
      v36 = *(_DWORD *)(a2 + 120);
      goto LABEL_18;
    }
    v36 = *(_DWORD *)(a2 + 112);
    if ( a5 || v36 <= 12 )
      goto LABEL_18;
    v37 = -10;
LABEL_19:
    *(_DWORD *)(a2 + 164) = v37;
    *v35 = v35[3];
    ++v35;
    sub_1062DC(a1, v36, a5, a2, a6);
    *v31 &= ~0x200u;
    *v31 |= 0x200u;
    *v31 &= ~0x200u;
    sub_1063A4(a2, v19);
    v38 = v34[1];
    ++v34;
    sub_104FA8(v38, a2, v36, v19);
    v39 = v19;
    v40 = *(unsigned __int16 *)(a2 + 2 * (v36 + 16 * v19++));
    sub_106450(a2, v40, v39);
  }
  while ( v19 != 3 );
  v41 = *(_DWORD *)(a2 + 132);
  if ( v41 <= *(_DWORD *)(a2 + 112) )
  {
    v42 = off_106990;
    v43 = dword_1069A0;
    do
    {
      while ( 1 )
      {
        sub_1062DC(a1, v41, a5, a2, a6);
        v44 = *(_DWORD *)(a2 + 124);
        *v42 &= ~0x200u;
        *v42 |= 0x200u;
        *v42 &= ~0x200u;
        if ( v44 < v41 )
          break;
        sub_1063A4(a2, 2);
        sub_12EB90(1, v43);
        sub_104FA8(a3[2], a2, v41, 2);
        if ( *(_DWORD *)(a2 + 124) <= v41 )
          break;
LABEL_26:
        if ( *(_DWORD *)(a2 + 120) <= v41 )
          goto LABEL_23;
        if ( *(_DWORD *)(a2 + 112) < ++v41 )
          goto LABEL_28;
      }
      if ( *(_DWORD *)(a2 + 120) >= v41 )
      {
        sub_1063A4(a2, 1);
        sub_12EB90(1, v43);
        sub_104FA8(a3[1], a2, v41, 1);
        goto LABEL_26;
      }
LABEL_23:
      sub_1063A4(a2, 0);
      sub_12EB90(1, v43);
      sub_104FA8(*a3, a2, v41++, 0);
    }
    while ( *(_DWORD *)(a2 + 112) >= v41 );
  }
LABEL_28:
  v45 = (unsigned int *)off_106CC0;
  v46 = (unsigned int *)off_106CC4;
  v47 = (unsigned int *)off_106CE8;
  v48 = (unsigned int *)off_106CEC;
  v49 = off_106CE4;
  *(_DWORD *)off_106CC0 = *(_DWORD *)off_106CC0 & 0xFFBFFFFF | (v146 << 22);
  *v45 = *v45 & 0xFFDFFFFF | (v145 << 21);
  sub_104180();
  v50 = off_106CC8;
  v51 = (unsigned int *)off_106CCC;
  v52 = (unsigned int *)off_106CF0;
  *(_DWORD *)off_106CC8 = *(_DWORD *)off_106CC8 & 0xF8FFFFFF | (v89 << 24);
  v53 = (unsigned int *)off_106CD0;
  *v46 = *v46 & 0xFFFFFFBF | (v107 << 6);
  v54 = (unsigned int *)off_106CD4;
  *v51 = *v51 & 0xFFFF8FFF | (v109 << 12);
  v55 = (unsigned int *)off_106CD8;
  v56 = (unsigned int *)off_106CDC;
  *(_DWORD *)((char *)v50 + 0xFFFFFFDC) = *(_DWORD *)((char *)v50 + 0xFFFFFFDC) & 0xFF7FFFFF | (v111 << 23);
  *(_DWORD *)((char *)v50 + 0xFFFFFFDC) = *(_DWORD *)((char *)v50 + 0xFFFFFFDC) & 0xFFBFFFFF | (v113 << 22);
  v57 = (unsigned int *)off_106CE0;
  *(_DWORD *)((char *)v50 + 0xFFFFFFDC) = *(_DWORD *)((char *)v50 + 0xFFFFFFDC) & 0xFFEFFFFF | (v115 << 20);
  *(_DWORD *)((char *)v50 + 0xFFFFFFDC) = *(_DWORD *)((char *)v50 + 0xFFFFFFDC) & 0xFFDFFFFF | (v117 << 21);
  *v53 = *v53 & 0xFFFBFFFF | (v141 << 18);
  v58 = off_106CF4;
  *v53 = *v53 & 0xFFF7FFFF | (v140 << 19);
  *v53 = *v53 & 0xFFFDFFFF | (v119 << 17);
  *v53 = *v53 & 0xFFFEFFFF | (v121 << 16);
  *v53 = *v53 & 0xFFFF7FFF | (v123 << 15);
  *v53 = *v53 & 0xFFFFBFFF | (v125 << 14);
  *v54 = *v54 & 0xFFFBFFFF | (v127 << 18);
  *v47 = *v47 & 0xFFFFCFFF | (v129 << 12);
  *v55 = *v55 & 0xFFFFFFFC | v131;
  *v56 = *v56 & 0xFFE3FFFF | (v133 << 18);
  *v55 = *v55 & 0xFFFFFFFB | (4 * v135);
  *v53 = *v53 & 0xFF7FFFFF | (v137 << 23);
  *v53 = *v53 & 0xFFBFFFFF | (v139 << 22);
  *v52 = *v52 & 0xFFFFFFDF | (32 * v87);
  *v53 = *v53 & 0xFFDFFFFF | (v91 << 21);
  *v53 = *v53 & 0xFFEFFFFF | (v93 << 20);
  *v55 = *v55 & 0xFFFFFF0F | (16 * v95);
  *v57 = *v57 & 0xFFFFFF7F | (v97 << 7);
  *v57 = *v57 & 0xFFFFFF8F | (16 * v99);
  *v57 = *v57 & 0xFFFFFBFF | (v101 << 10);
  *v57 = *v57 & 0xFFFFFCFF | (v103 << 8);
  *v52 = *v52 & 0xFFFFFFE3 | (4 * v105);
  *v45 &= 0xFFFE00FF;
  *v45 &= ~0x20000u;
  *v45 |= 0x40000u;
  *v48 = *v48 & 0x7FFFFFFF | v144 & 0x80000000;
  *v49 = v143;
  *(v50 - 1902) = *(v50 - 1902) & 0xFFFFFEFF | (v142 << 8);
  *v58 |= 0x400u;
  *v58 &= ~0x400u;
  return v103;
}

