// sub_105FD0 @ 0x105fd0, size 3010 bytes
// Doc: sub_1205FD0 [rf]: Initializes RF calibration/lookup tables from constant pool
// sub_1205FD0 [rf]: Initializes RF calibration/lookup tables from constant pool
int __fastcall sub_105FD0(unsigned int a1, int a2, __int16 *a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v8; // r9
  unsigned int *v9; // r8
  unsigned int *v10; // r10
  unsigned int *v11; // r4
  unsigned int *v12; // lr
  unsigned int *v13; // r7
  unsigned int *v14; // r12
  unsigned int *v15; // r5
  unsigned int *v16; // r6
  unsigned int v17; // r9
  unsigned int v18; // r8
  unsigned int v19; // r7
  int v20; // r6
  void *v24; // r3
  void *v25; // r3
  void *v26; // r3
  _DWORD *v27; // r3
  int v28; // r7
  _DWORD *v29; // r0
  _DWORD *v30; // r2
  unsigned int *v31; // r1
  _DWORD *v32; // r5
  _DWORD *v33; // r2
  _DWORD *v34; // r2
  unsigned __int16 *v35; // r9
  _DWORD *v36; // r8
  int v37; // r7
  int v38; // r3
  int v39; // t1
  int v40; // r2
  int v41; // r1
  int v42; // r5
  _DWORD *v43; // r6
  _DWORD *v44; // r9
  int v45; // r8
  int v46; // r2
  unsigned int *v47; // r4
  unsigned int *v48; // r5
  unsigned int *v49; // r9
  unsigned int *v50; // r11
  _DWORD *v51; // r8
  _DWORD *v52; // r1
  unsigned int *v53; // r2
  unsigned int *v54; // r12
  unsigned int *v55; // r3
  unsigned int *v56; // r6
  unsigned int *v57; // r0
  unsigned int *v58; // r7
  unsigned int *v59; // r2
  _DWORD *v60; // r10
  int v62; // r8
  int v63; // r9
  int v64; // r10
  int v65; // r7
  int v66; // r6
  unsigned int v67; // r5
  int v68; // r3
  int v69; // r7
  int *v70; // r6
  _DWORD *v71; // r7
  int v72; // r9
  int v73; // r10
  int v74; // r8
  unsigned int *v75; // r6
  unsigned int v76; // r5
  int v77; // r5
  unsigned int v78; // r3
  char v79; // r3
  int v80; // r6
  int *v81; // r3
  int *v82; // r12
  int *v83; // r2
  int v84; // r0
  int *v85; // r1
  int v86; // r3
  unsigned int v87; // [sp+8h] [bp-CCh]
  char v88; // [sp+8h] [bp-CCh]
  int v89; // [sp+8h] [bp-CCh]
  unsigned int v90; // [sp+Ch] [bp-C8h]
  int v91; // [sp+Ch] [bp-C8h]
  unsigned int v92; // [sp+10h] [bp-C4h]
  int v93; // [sp+10h] [bp-C4h]
  unsigned int v94; // [sp+14h] [bp-C0h]
  int v95; // [sp+14h] [bp-C0h]
  unsigned int v96; // [sp+18h] [bp-BCh]
  int v97; // [sp+18h] [bp-BCh]
  unsigned int v98; // [sp+1Ch] [bp-B8h]
  int v99; // [sp+1Ch] [bp-B8h]
  unsigned int v100; // [sp+20h] [bp-B4h]
  int v101; // [sp+20h] [bp-B4h]
  unsigned int v102; // [sp+24h] [bp-B0h]
  int v103; // [sp+24h] [bp-B0h]
  unsigned int v104; // [sp+28h] [bp-ACh]
  int v105; // [sp+28h] [bp-ACh]
  unsigned int v106; // [sp+2Ch] [bp-A8h]
  int v107; // [sp+2Ch] [bp-A8h]
  unsigned int v108; // [sp+30h] [bp-A4h]
  int v109; // [sp+30h] [bp-A4h]
  unsigned int v110; // [sp+34h] [bp-A0h]
  int v111; // [sp+34h] [bp-A0h]
  unsigned int v112; // [sp+38h] [bp-9Ch]
  int v113; // [sp+38h] [bp-9Ch]
  unsigned int v114; // [sp+3Ch] [bp-98h]
  int v115; // [sp+3Ch] [bp-98h]
  unsigned int v116; // [sp+40h] [bp-94h]
  int v117; // [sp+40h] [bp-94h]
  unsigned int v118; // [sp+44h] [bp-90h]
  int v119; // [sp+44h] [bp-90h]
  unsigned int v120; // [sp+48h] [bp-8Ch]
  int v121; // [sp+48h] [bp-8Ch]
  unsigned int v122; // [sp+4Ch] [bp-88h]
  int v123; // [sp+4Ch] [bp-88h]
  unsigned int v124; // [sp+50h] [bp-84h]
  int v125; // [sp+50h] [bp-84h]
  unsigned int v126; // [sp+54h] [bp-80h]
  int v127; // [sp+54h] [bp-80h]
  unsigned int v128; // [sp+58h] [bp-7Ch]
  int v129; // [sp+58h] [bp-7Ch]
  unsigned int v130; // [sp+5Ch] [bp-78h]
  int v131; // [sp+5Ch] [bp-78h]
  unsigned int v132; // [sp+60h] [bp-74h]
  int v133; // [sp+60h] [bp-74h]
  unsigned int v134; // [sp+64h] [bp-70h]
  int v135; // [sp+64h] [bp-70h]
  unsigned int v136; // [sp+68h] [bp-6Ch]
  int v137; // [sp+68h] [bp-6Ch]
  unsigned int v138; // [sp+6Ch] [bp-68h]
  int v139; // [sp+6Ch] [bp-68h]
  unsigned int v140; // [sp+70h] [bp-64h]
  int v141; // [sp+70h] [bp-64h]
  unsigned int v142; // [sp+74h] [bp-60h]
  int v143; // [sp+74h] [bp-60h]
  int v144; // [sp+78h] [bp-5Ch]
  int v145; // [sp+7Ch] [bp-58h]
  int v146; // [sp+80h] [bp-54h]
  int v147; // [sp+84h] [bp-50h]
  int v148; // [sp+88h] [bp-4Ch]
  int v149; // [sp+8Ch] [bp-48h]
  int v150; // [sp+90h] [bp-44h]
  char v151; // [sp+94h] [bp-40h]
  int v152; // [sp+94h] [bp-40h]
  int v153; // [sp+98h] [bp-3Ch]
  int v154; // [sp+9Ch] [bp-38h]
  int v155; // [sp+A0h] [bp-34h]
  int v156; // [sp+A4h] [bp-30h]
  int v157; // [sp+A8h] [bp-2Ch]
  int v158; // [sp+ACh] [bp-28h]
  int v159; // [sp+B0h] [bp-24h]
  unsigned int v160; // [sp+B4h] [bp-20h]
  int v161; // [sp+B8h] [bp-1Ch]
  int v162; // [sp+BCh] [bp-18h]
  int v163; // [sp+C0h] [bp-14h]
  int v164; // [sp+C4h] [bp-10h]
  int v165; // [sp+C8h] [bp-Ch]
  int v166; // [sp+CCh] [bp-8h]

  v8 = off_1062D8;
  v9 = (unsigned int *)off_1062DC;
  v10 = (unsigned int *)off_1062E0;
  v11 = (unsigned int *)off_1062B0;
  v12 = (unsigned int *)off_1062E4;
  v13 = (unsigned int *)off_1062B4;
  v14 = (unsigned int *)off_1062E8;
  v15 = (unsigned int *)off_1062B8;
  *(_DWORD *)off_1062D8 |= 0x400u;
  *v8 &= ~0x400u;
  v90 = *v9;
  v92 = *v10;
  v94 = *v11;
  v96 = *v11;
  v98 = *v12;
  v100 = *v13;
  v102 = *v13;
  v104 = *v13;
  v106 = *v13;
  v108 = *v9;
  v142 = *(_DWORD *)off_1062BC;
  v140 = *(_DWORD *)off_1062BC;
  *v9 |= 0x20u;
  v16 = (unsigned int *)off_1062BC;
  *v10 = *v10 & 0xF8FFFFFF | 0x2000000;
  *v11 |= 0x100000u;
  *v11 |= 0x200000u;
  *v12 = *v12 & 0xFFFFFF0F | 0xC0;
  *v14 = *v14 & 0xFFFFFFC7 | 0x20;
  *v13 |= 0x400u;
  *v13 = *v13 & 0xFFFFFCFF | 0x100;
  *v16 = *v16 & 0xFFFE00FF | 0x100;
  *v16 |= 0x20000u;
  *v16 |= 0x40000u;
  v110 = *v14;
  v112 = *(unsigned int *)((char *)v16 + 0xFFFFFFC8);
  v114 = *v15;
  v116 = *v15;
  v118 = *v15;
  v120 = *v15;
  v122 = *v11;
  v124 = *v11;
  v126 = *v11;
  v128 = *v11;
  v130 = *(_DWORD *)off_1062C0;
  v132 = *(_DWORD *)off_1062C4;
  v134 = *v12;
  v136 = *(_DWORD *)off_1062C8;
  v138 = *v12;
  v148 = *(_DWORD *)off_1062CC;
  v87 = *v11;
  v18 = *v11;
  v17 = *v11;
  v147 = *(_DWORD *)off_1062D0;
  v19 = *(_DWORD *)off_1062D4;
  *v14 |= 0x40u;
  *(unsigned int *)((char *)v16 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v15 |= 0x800000u;
  v20 = a4;
  v91 = (v90 >> 5) & 1;
  v93 = HIBYTE(v92) & 7;
  v95 = (v94 >> 21) & 1;
  v97 = (v96 >> 20) & 1;
  v99 = (unsigned __int8)v98 >> 4;
  v101 = (v100 >> 7) & 1;
  v103 = (v102 >> 4) & 7;
  v105 = (v104 >> 10) & 1;
  v107 = (v106 >> 8) & 3;
  v109 = (v108 >> 2) & 7;
  v150 = (v142 >> 22) & 1;
  v149 = (v140 >> 21) & 1;
  v111 = (v110 >> 6) & 1;
  v113 = (v112 >> 12) & 7;
  v115 = (v114 >> 23) & 1;
  v117 = (v116 >> 22) & 1;
  v119 = (v118 >> 20) & 1;
  v121 = (v120 >> 21) & 1;
  v123 = (v122 >> 17) & 1;
  v125 = HIWORD(v124) & 1;
  v127 = (v126 >> 15) & 1;
  v129 = (v128 >> 14) & 1;
  v131 = (v130 >> 18) & 1;
  v133 = (v132 >> 12) & 3;
  v135 = v134 & 3;
  v137 = (v136 >> 18) & 7;
  v139 = (v138 >> 2) & 1;
  v141 = (v17 >> 23) & 1;
  v143 = (v18 >> 22) & 1;
  v145 = (v87 >> 18) & 1;
  v146 = (v19 >> 8) & 1;
  v144 = (v87 >> 19) & 1;
  *v15 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (unsigned __int8)(a4 - 1);
  while ( a4 );
  v24 = off_1062B8;
  *(_DWORD *)off_1062B8 &= ~0x100000u;
  *(_DWORD *)v24 |= 0x200000u;
  LOBYTE(v24) = 60;
  do
    v24 = (void *)(unsigned __int8)((_BYTE)v24 - 1);
  while ( v24 );
  v25 = off_1062B0;
  *(_DWORD *)off_1062B8 |= 0x100000u;
  *(_DWORD *)v25 |= 0x20000u;
  *(_DWORD *)v25 |= 0x10000u;
  LOBYTE(v25) = 90;
  do
    v25 = (void *)(unsigned __int8)((_BYTE)v25 - 1);
  while ( v25 );
  v26 = off_106470;
  *(_DWORD *)off_106470 &= ~0x40000u;
  *(_DWORD *)v26 |= 0x80000u;
  LOBYTE(v26) = 60;
  do
    v26 = (void *)(unsigned __int8)((_BYTE)v26 - 1);
  while ( v26 );
  v27 = off_106470;
  *(_DWORD *)off_106470 |= 0x40000u;
  *v27 |= 0x8000u;
  *v27 |= 0x4000u;
  LOBYTE(v28) = 90;
  do
    v28 = (unsigned __int8)(v28 - 1);
  while ( v28 );
  v29 = off_106474;
  v30 = off_106478;
  v31 = (unsigned int *)off_10647C;
  v32 = off_106480;
  *(_DWORD *)off_106474 |= 0x40000u;
  *v30 |= 0x3000u;
  v33 = off_106470;
  *v31 = *v31 & 0xFFFFFFFC | 1;
  v29[16] = v29[16] & 0xFFE3FFFF | 0xC0000;
  *v31 |= 4u;
  *v33 |= 0x800000u;
  *v33 |= 0x400000u;
  *v32 &= ~0x100u;
  sub_103640();
  crypto_hw_reset_seq();
  v34 = off_106488;
  *(_DWORD *)off_106484 |= 0x10000000u;
  *v34 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v162 = (a1 >> 12) & 3;
      *(_DWORD *)off_106A60 = a1;
      if ( v162 == 1 )
      {
        v163 = 0;
        v164 = *(_DWORD *)off_106BA4;
        v158 = -2;
        v88 = 31;
        v157 = 1;
        v153 = 1;
        v62 = 4;
        v64 = 0x7FFFFFFF;
        v161 = 3;
        v151 = 1;
        v155 = 0x7FFFFFFF;
        v156 = 4;
        v63 = 0;
      }
      else
      {
        if ( v162 == 2 )
        {
          v164 = *(_DWORD *)off_106BA8;
          v157 = dword_106BB0;
          v158 = dword_106BAC;
        }
        else
        {
          v164 = *(_DWORD *)off_106A64;
          v157 = dword_106A6C;
          v158 = dword_106A68;
        }
        v62 = 8;
        a7 = 2;
        v63 = 2;
        v88 = 13;
        v153 = -1;
        v155 = -122881;
        v161 = 15;
        v151 = -13;
        v163 = 8;
        v64 = 0x1FFF;
        v156 = 16;
      }
      v65 = (*(_DWORD *)off_106A60 >> 8) & 0xF;
      v66 = (v162 << 8) + dword_106A70;
      v165 = v66;
      sub_11F74C(1, dword_106A74, *(_DWORD *)off_106A60, v162);
      *(_DWORD *)(a2 + 140) = *(_DWORD *)(a2 + 152);
      crypto_table_copy_165d00(a2, 0);
      v67 = 0;
      sub_11F74C(1, dword_106A78, *(_DWORD *)off_106A60, v65);
      v154 = v63;
      v68 = v65;
      v69 = v66 + 16 * v65;
      v70 = (int *)(v69 + v163);
      v71 = (_DWORD *)(v69 + v62);
      v159 = v64;
      v166 = v62;
      v160 = 0;
      v72 = 0;
      v73 = v68;
      v74 = 2 * v68;
      do
      {
        sub_102ADC(1);
        if ( a7 == v154 )
        {
          *v70 = *v70 & v155 | ((v161 & v67) << v88);
        }
        else
        {
          *v70 &= v159;
          *v71 &= v158;
          *v70 |= (v153 & v67) << v88;
          *v71 |= (v67 >> v151) & v157;
        }
        sub_102B40(1);
        rf_adc_capture_n_a98((unsigned __int16)*a3, a2, v73, 0);
        sub_11F74C(1, dword_106A7C, *a3, v67);
        sub_11F74C(1, dword_106A84, (*(_DWORD *)off_106A80 >> 21) & 3, off_106A80);
        sub_11F74C(1, dword_106A8C, (*(_DWORD *)off_106A88 >> 15) & 0xF, off_106A88);
        if ( *(__int16 *)(a2 + v74) > v72 )
        {
          v72 = *(__int16 *)(a2 + v74);
          v160 = v67;
        }
        ++v67;
      }
      while ( v156 != v67 );
      v78 = *(_BYTE *)off_106A94 & 0xC0;
      if ( v78 != 192 )
      {
        v78 = a8;
        if ( a8 > 2 )
        {
          v78 = v162;
          if ( v162 == 1 )
          {
            if ( a8 == 6 )
              v86 = 1;
            else
              v86 = 2;
            v78 = v160 + v86;
            if ( v78 >= 3 )
              v78 = 3;
            v160 = v78;
          }
        }
      }
      sub_11F74C(1, dword_106A98, v160, v78);
      sub_102ADC(1);
      v79 = v88;
      v89 = (v160 >> v151) & v157;
      v80 = (v153 & v160) << v79;
      v152 = (v160 & v161) << v79;
      v81 = (int *)(v165 + v163);
      v82 = (int *)(v163 + 192 + v164);
      v83 = (int *)(v164 + v163);
      v84 = v166 - v163;
      do
      {
        while ( 1 )
        {
          v85 = &v83[v163 / 0xFFFFFFFC];
          if ( a7 == v154 )
            break;
          *v81 &= v159;
          *(int *)((char *)v81 + v84) &= v158;
          *v81 |= v80;
          *(int *)((char *)v81 + v84) |= v89;
          *v83 &= v159;
          *(int *)((char *)v85 + v166) &= v158;
          *v83 |= v80;
          v83 += 3;
          *(int *)((char *)v85 + v166) |= v89;
          v81 += 4;
          if ( v83 == v82 )
            goto LABEL_53;
        }
        *v81 = *v81 & v155 | v152;
        *v83 = *v83 & v155 | v152;
        v83 += 3;
        v81 += 4;
      }
      while ( v83 != v82 );
LABEL_53:
      sub_102B40(1);
      sub_11F74C(1, dword_106B98, (*(_DWORD *)off_106B94 >> 21) & 3, off_106B94);
      sub_11F74C(1, dword_106BA0, (*(_DWORD *)off_106B9C >> 15) & 0xF, off_106B9C);
    }
    goto LABEL_28;
  }
  if ( v20 )
  {
    v75 = (unsigned int *)off_106A60;
    *(_DWORD *)off_106A60 = a1;
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    v76 = *v75;
    crypto_table_copy_165d00(a2, 0);
    v77 = (v76 >> 8) & 0xF;
    sub_11F74C(1, dword_106A90, *v75, v77);
    rf_adc_capture_n_a98((unsigned __int16)*a3, a2, v77, 0);
    goto LABEL_28;
  }
  *(_QWORD *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v35 = (unsigned __int16 *)(a3 - 1);
  v36 = (_DWORD *)(a2 + 140);
  do
  {
    if ( v20 == 2 )
    {
      v37 = *(_DWORD *)(a2 + 124);
LABEL_18:
      v38 = -5;
      goto LABEL_19;
    }
    if ( v20 == 1 )
    {
      v37 = *(_DWORD *)(a2 + 120);
      goto LABEL_18;
    }
    v37 = *(_DWORD *)(a2 + 112);
    if ( a5 || v37 <= 12 )
      goto LABEL_18;
    v38 = -10;
LABEL_19:
    *(_DWORD *)(a2 + 164) = v38;
    *v36 = v36[3];
    ++v36;
    sub_105DCC(a1, v37, a5, a2, a6);
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    crypto_table_copy_165d00(a2, v20);
    v39 = v35[1];
    ++v35;
    rf_adc_capture_n_a98(v39, a2, v37, v20);
    v40 = v20;
    v41 = *(unsigned __int16 *)(a2 + 2 * (v37 + 16 * v20++));
    sub_105F40((_DWORD *)a2, v41, v40);
  }
  while ( v20 != 3 );
  v42 = *(_DWORD *)(a2 + 132);
  if ( v42 <= *(_DWORD *)(a2 + 112) )
  {
    v43 = off_106480;
    v44 = off_10648C;
    v45 = dword_106490;
    do
    {
      while ( 1 )
      {
        sub_105DCC(a1, v42, a5, a2, a6);
        v46 = *(_DWORD *)(a2 + 124);
        *v43 &= ~0x200u;
        *v43 |= 0x200u;
        *v43 &= ~0x200u;
        if ( v46 < v42 )
          break;
        crypto_table_copy_165d00(a2, 2);
        sub_11F74C(1, v45, *v44, v42);
        rf_adc_capture_n_a98((unsigned __int16)a3[2], a2, v42, 2);
        if ( *(_DWORD *)(a2 + 124) <= v42 )
          break;
LABEL_26:
        if ( *(_DWORD *)(a2 + 120) <= v42 )
          goto LABEL_23;
        if ( *(_DWORD *)(a2 + 112) < ++v42 )
          goto LABEL_28;
      }
      if ( *(_DWORD *)(a2 + 120) >= v42 )
      {
        crypto_table_copy_165d00(a2, 1);
        sub_11F74C(1, v45, *v44, v42);
        rf_adc_capture_n_a98((unsigned __int16)a3[1], a2, v42, 1);
        goto LABEL_26;
      }
LABEL_23:
      crypto_table_copy_165d00(a2, 0);
      sub_11F74C(1, v45, *v44, v42);
      rf_adc_capture_n_a98((unsigned __int16)*a3, a2, v42++, 0);
    }
    while ( *(_DWORD *)(a2 + 112) >= v42 );
  }
LABEL_28:
  v47 = (unsigned int *)off_1067B0;
  v48 = (unsigned int *)off_1067B4;
  v49 = (unsigned int *)off_1067D8;
  v50 = (unsigned int *)off_1067DC;
  v51 = off_1067D4;
  *(_DWORD *)off_1067B0 = *(_DWORD *)off_1067B0 & 0xFFBFFFFF | (v150 << 22);
  *v47 = *v47 & 0xFFDFFFFF | (v149 << 21);
  sub_103C6C();
  v52 = off_1067B8;
  v53 = (unsigned int *)off_1067BC;
  v54 = (unsigned int *)off_1067E0;
  *(_DWORD *)off_1067B8 = *(_DWORD *)off_1067B8 & 0xF8FFFFFF | (v93 << 24);
  v55 = (unsigned int *)off_1067C0;
  *v48 = *v48 & 0xFFFFFFBF | (v111 << 6);
  v56 = (unsigned int *)off_1067C4;
  *v53 = *v53 & 0xFFFF8FFF | (v113 << 12);
  v57 = (unsigned int *)off_1067C8;
  v58 = (unsigned int *)off_1067CC;
  *(_DWORD *)((char *)v52 + 0xFFFFFFDC) = *(_DWORD *)((char *)v52 + 0xFFFFFFDC) & 0xFF7FFFFF | (v115 << 23);
  *(_DWORD *)((char *)v52 + 0xFFFFFFDC) = *(_DWORD *)((char *)v52 + 0xFFFFFFDC) & 0xFFBFFFFF | (v117 << 22);
  v59 = (unsigned int *)off_1067D0;
  *(_DWORD *)((char *)v52 + 0xFFFFFFDC) = *(_DWORD *)((char *)v52 + 0xFFFFFFDC) & 0xFFEFFFFF | (v119 << 20);
  *(_DWORD *)((char *)v52 + 0xFFFFFFDC) = *(_DWORD *)((char *)v52 + 0xFFFFFFDC) & 0xFFDFFFFF | (v121 << 21);
  *v55 = *v55 & 0xFFFBFFFF | (v145 << 18);
  v60 = off_1067E4;
  *v55 = *v55 & 0xFFF7FFFF | (v144 << 19);
  *v55 = *v55 & 0xFFFDFFFF | (v123 << 17);
  *v55 = *v55 & 0xFFFEFFFF | (v125 << 16);
  *v55 = *v55 & 0xFFFF7FFF | (v127 << 15);
  *v55 = *v55 & 0xFFFFBFFF | (v129 << 14);
  *v56 = *v56 & 0xFFFBFFFF | (v131 << 18);
  *v49 = *v49 & 0xFFFFCFFF | (v133 << 12);
  *v57 = *v57 & 0xFFFFFFFC | v135;
  *v58 = *v58 & 0xFFE3FFFF | (v137 << 18);
  *v57 = *v57 & 0xFFFFFFFB | (4 * v139);
  *v55 = *v55 & 0xFF7FFFFF | (v141 << 23);
  *v55 = *v55 & 0xFFBFFFFF | (v143 << 22);
  *v54 = *v54 & 0xFFFFFFDF | (32 * v91);
  *v55 = *v55 & 0xFFDFFFFF | (v95 << 21);
  *v55 = *v55 & 0xFFEFFFFF | (v97 << 20);
  *v57 = *v57 & 0xFFFFFF0F | (16 * v99);
  *v59 = *v59 & 0xFFFFFF7F | (v101 << 7);
  *v59 = *v59 & 0xFFFFFF8F | (16 * v103);
  *v59 = *v59 & 0xFFFFFBFF | (v105 << 10);
  *v59 = *v59 & 0xFFFFFCFF | (v107 << 8);
  *v54 = *v54 & 0xFFFFFFE3 | (4 * v109);
  *v47 &= 0xFFFE00FF;
  *v47 &= ~0x20000u;
  *v47 |= 0x40000u;
  *v50 = *v50 & 0x7FFFFFFF | v148 & 0x80000000;
  *v51 = v147;
  *(v52 - 1902) = *(v52 - 1902) & 0xFFFFFEFF | (v146 << 8);
  *v60 |= 0x400u;
  *v60 &= ~0x400u;
  return v107;
}

