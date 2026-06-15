// sub_106450 @ 0x106450, size 2988 bytes
int __fastcall sub_106450(unsigned int a1, int a2, __int16 *a3, int a4, int a5, int a6, int a7, int a8)
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
  __int16 *v35; // r9
  _DWORD *v36; // r8
  int v37; // r7
  int v38; // r3
  __int16 v39; // t1
  int v40; // r2
  int v41; // r1
  int v42; // r5
  _DWORD *v43; // r6
  int v44; // r8
  int v45; // r2
  unsigned int *v46; // r4
  unsigned int *v47; // r5
  unsigned int *v48; // r9
  unsigned int *v49; // r11
  _DWORD *v50; // r8
  _DWORD *v51; // r1
  unsigned int *v52; // r2
  unsigned int *v53; // r12
  unsigned int *v54; // r3
  unsigned int *v55; // r6
  unsigned int *v56; // r0
  unsigned int *v57; // r7
  unsigned int *v58; // r2
  _DWORD *v59; // r10
  int v61; // r8
  int v62; // r9
  int v63; // r10
  int v64; // r7
  int v65; // r6
  unsigned int v66; // r5
  int v67; // r3
  int v68; // r7
  int *v69; // r6
  _DWORD *v70; // r7
  int v71; // r9
  int v72; // r10
  int v73; // r8
  unsigned int *v74; // r6
  unsigned int v75; // r5
  int v76; // r3
  unsigned int v77; // r3
  char v78; // r3
  int v79; // r6
  int *v80; // r3
  int *v81; // r12
  int *v82; // r2
  int v83; // r0
  int *v84; // r1
  unsigned int v85; // [sp+8h] [bp-CCh]
  char v86; // [sp+8h] [bp-CCh]
  int v87; // [sp+8h] [bp-CCh]
  unsigned int v88; // [sp+Ch] [bp-C8h]
  int v89; // [sp+Ch] [bp-C8h]
  unsigned int v90; // [sp+10h] [bp-C4h]
  int v91; // [sp+10h] [bp-C4h]
  unsigned int v92; // [sp+14h] [bp-C0h]
  int v93; // [sp+14h] [bp-C0h]
  unsigned int v94; // [sp+18h] [bp-BCh]
  int v95; // [sp+18h] [bp-BCh]
  unsigned int v96; // [sp+1Ch] [bp-B8h]
  int v97; // [sp+1Ch] [bp-B8h]
  unsigned int v98; // [sp+20h] [bp-B4h]
  int v99; // [sp+20h] [bp-B4h]
  unsigned int v100; // [sp+24h] [bp-B0h]
  int v101; // [sp+24h] [bp-B0h]
  unsigned int v102; // [sp+28h] [bp-ACh]
  int v103; // [sp+28h] [bp-ACh]
  unsigned int v104; // [sp+2Ch] [bp-A8h]
  int v105; // [sp+2Ch] [bp-A8h]
  unsigned int v106; // [sp+30h] [bp-A4h]
  int v107; // [sp+30h] [bp-A4h]
  unsigned int v108; // [sp+34h] [bp-A0h]
  int v109; // [sp+34h] [bp-A0h]
  unsigned int v110; // [sp+38h] [bp-9Ch]
  int v111; // [sp+38h] [bp-9Ch]
  unsigned int v112; // [sp+3Ch] [bp-98h]
  int v113; // [sp+3Ch] [bp-98h]
  unsigned int v114; // [sp+40h] [bp-94h]
  int v115; // [sp+40h] [bp-94h]
  unsigned int v116; // [sp+44h] [bp-90h]
  int v117; // [sp+44h] [bp-90h]
  unsigned int v118; // [sp+48h] [bp-8Ch]
  int v119; // [sp+48h] [bp-8Ch]
  unsigned int v120; // [sp+4Ch] [bp-88h]
  int v121; // [sp+4Ch] [bp-88h]
  unsigned int v122; // [sp+50h] [bp-84h]
  int v123; // [sp+50h] [bp-84h]
  unsigned int v124; // [sp+54h] [bp-80h]
  int v125; // [sp+54h] [bp-80h]
  unsigned int v126; // [sp+58h] [bp-7Ch]
  int v127; // [sp+58h] [bp-7Ch]
  unsigned int v128; // [sp+5Ch] [bp-78h]
  int v129; // [sp+5Ch] [bp-78h]
  unsigned int v130; // [sp+60h] [bp-74h]
  int v131; // [sp+60h] [bp-74h]
  unsigned int v132; // [sp+64h] [bp-70h]
  int v133; // [sp+64h] [bp-70h]
  unsigned int v134; // [sp+68h] [bp-6Ch]
  int v135; // [sp+68h] [bp-6Ch]
  unsigned int v136; // [sp+6Ch] [bp-68h]
  int v137; // [sp+6Ch] [bp-68h]
  unsigned int v138; // [sp+70h] [bp-64h]
  int v139; // [sp+70h] [bp-64h]
  unsigned int v140; // [sp+74h] [bp-60h]
  int v141; // [sp+74h] [bp-60h]
  int v142; // [sp+78h] [bp-5Ch]
  int v143; // [sp+7Ch] [bp-58h]
  int v144; // [sp+80h] [bp-54h]
  int v145; // [sp+84h] [bp-50h]
  int v146; // [sp+88h] [bp-4Ch]
  int v147; // [sp+8Ch] [bp-48h]
  int v148; // [sp+90h] [bp-44h]
  char v149; // [sp+94h] [bp-40h]
  int v150; // [sp+94h] [bp-40h]
  int v151; // [sp+98h] [bp-3Ch]
  int v152; // [sp+9Ch] [bp-38h]
  int v153; // [sp+A0h] [bp-34h]
  int v154; // [sp+A4h] [bp-30h]
  int v155; // [sp+A8h] [bp-2Ch]
  int v156; // [sp+ACh] [bp-28h]
  int v157; // [sp+B0h] [bp-24h]
  unsigned int v158; // [sp+B4h] [bp-20h]
  int v159; // [sp+B8h] [bp-1Ch]
  int v160; // [sp+BCh] [bp-18h]
  int v161; // [sp+C0h] [bp-14h]
  int v162; // [sp+C4h] [bp-10h]
  int v163; // [sp+C8h] [bp-Ch]
  int v164; // [sp+CCh] [bp-8h]

  v8 = off_106758;
  v9 = (unsigned int *)off_10675C;
  v10 = (unsigned int *)off_106760;
  v11 = (unsigned int *)off_106730;
  v12 = (unsigned int *)off_106764;
  v13 = (unsigned int *)off_106734;
  v14 = (unsigned int *)off_106768;
  v15 = (unsigned int *)off_106738;
  *(_DWORD *)off_106758 |= 0x400u;
  *v8 &= ~0x400u;
  v88 = *v9;
  v90 = *v10;
  v92 = *v11;
  v94 = *v11;
  v96 = *v12;
  v98 = *v13;
  v100 = *v13;
  v102 = *v13;
  v104 = *v13;
  v106 = *v9;
  v140 = *(_DWORD *)off_10673C;
  v138 = *(_DWORD *)off_10673C;
  *v9 |= 0x20u;
  v16 = (unsigned int *)off_10673C;
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
  v108 = *v14;
  v110 = *(unsigned int *)((char *)v16 + 0xFFFFFFC8);
  v112 = *v15;
  v114 = *v15;
  v116 = *v15;
  v118 = *v15;
  v120 = *v11;
  v122 = *v11;
  v124 = *v11;
  v126 = *v11;
  v128 = *(_DWORD *)off_106740;
  v130 = *(_DWORD *)off_106744;
  v132 = *v12;
  v134 = *(_DWORD *)off_106748;
  v136 = *v12;
  v146 = *(_DWORD *)off_10674C;
  v85 = *v11;
  v18 = *v11;
  v17 = *v11;
  v145 = *(_DWORD *)off_106750;
  v19 = *(_DWORD *)off_106754;
  *v14 |= 0x40u;
  *(unsigned int *)((char *)v16 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v15 |= 0x800000u;
  v20 = a4;
  v89 = (v88 >> 5) & 1;
  v91 = HIBYTE(v90) & 7;
  v93 = (v92 >> 21) & 1;
  v95 = (v94 >> 20) & 1;
  v97 = (unsigned __int8)v96 >> 4;
  v99 = (v98 >> 7) & 1;
  v101 = (v100 >> 4) & 7;
  v103 = (v102 >> 10) & 1;
  v105 = (v104 >> 8) & 3;
  v107 = (v106 >> 2) & 7;
  v148 = (v140 >> 22) & 1;
  v147 = (v138 >> 21) & 1;
  v109 = (v108 >> 6) & 1;
  v111 = (v110 >> 12) & 7;
  v113 = (v112 >> 23) & 1;
  v115 = (v114 >> 22) & 1;
  v117 = (v116 >> 20) & 1;
  v119 = (v118 >> 21) & 1;
  v121 = (v120 >> 17) & 1;
  v123 = HIWORD(v122) & 1;
  v125 = (v124 >> 15) & 1;
  v127 = (v126 >> 14) & 1;
  v129 = (v128 >> 18) & 1;
  v131 = (v130 >> 12) & 3;
  v133 = v132 & 3;
  v135 = (v134 >> 18) & 7;
  v137 = (v136 >> 2) & 1;
  v139 = (v17 >> 23) & 1;
  v141 = (v18 >> 22) & 1;
  v143 = (v85 >> 18) & 1;
  v144 = (v19 >> 8) & 1;
  v142 = (v85 >> 19) & 1;
  *v15 |= 0x400000u;
  LOBYTE(a4) = 90;
  do
    a4 = (unsigned __int8)(a4 - 1);
  while ( a4 );
  v24 = off_106738;
  *(_DWORD *)off_106738 &= ~0x100000u;
  *(_DWORD *)v24 |= 0x200000u;
  LOBYTE(v24) = 60;
  do
    v24 = (void *)(unsigned __int8)((_BYTE)v24 - 1);
  while ( v24 );
  v25 = off_106730;
  *(_DWORD *)off_106738 |= 0x100000u;
  *(_DWORD *)v25 |= 0x20000u;
  *(_DWORD *)v25 |= 0x10000u;
  LOBYTE(v25) = 90;
  do
    v25 = (void *)(unsigned __int8)((_BYTE)v25 - 1);
  while ( v25 );
  v26 = off_1068F0;
  *(_DWORD *)off_1068F0 &= ~0x40000u;
  *(_DWORD *)v26 |= 0x80000u;
  LOBYTE(v26) = 60;
  do
    v26 = (void *)(unsigned __int8)((_BYTE)v26 - 1);
  while ( v26 );
  v27 = off_1068F0;
  *(_DWORD *)off_1068F0 |= 0x40000u;
  *v27 |= 0x8000u;
  *v27 |= 0x4000u;
  LOBYTE(v28) = 90;
  do
    v28 = (unsigned __int8)(v28 - 1);
  while ( v28 );
  v29 = off_1068F4;
  v30 = off_1068F8;
  v31 = (unsigned int *)off_1068FC;
  v32 = off_106900;
  *(_DWORD *)off_1068F4 |= 0x40000u;
  *v30 |= 0x3000u;
  v33 = off_1068F0;
  *v31 = *v31 & 0xFFFFFFFC | 1;
  v29[16] = v29[16] & 0xFFE3FFFF | 0xC0000;
  *v31 |= 4u;
  *v33 |= 0x800000u;
  *v33 |= 0x400000u;
  *v32 &= ~0x100u;
  crypto_hw_clk_toggle();
  crypto_hw_reset_seq();
  v34 = off_106908;
  *(_DWORD *)off_106904 |= 0x10000000u;
  *v34 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v160 = (a1 >> 12) & 3;
      *(_DWORD *)off_106EE8 = a1;
      if ( v160 == 1 )
      {
        v161 = 0;
        v162 = *(_DWORD *)off_10700C;
        v156 = -2;
        v86 = 31;
        v155 = 1;
        v151 = 1;
        v61 = 4;
        v63 = 0x7FFFFFFF;
        v159 = 3;
        v149 = 1;
        v153 = 0x7FFFFFFF;
        v154 = 4;
        v62 = 0;
      }
      else
      {
        if ( v160 == 2 )
        {
          v162 = *(_DWORD *)off_107010;
          v155 = dword_107018;
          v156 = dword_107014;
        }
        else
        {
          v162 = *(_DWORD *)off_106EEC;
          v155 = dword_106EF4;
          v156 = dword_106EF0;
        }
        v61 = 8;
        a7 = 2;
        v62 = 2;
        v86 = 13;
        v151 = -1;
        v153 = -122881;
        v159 = 15;
        v149 = -13;
        v161 = 8;
        v63 = 0x1FFF;
        v154 = 16;
      }
      v64 = (*(_DWORD *)off_106EE8 >> 8) & 0xF;
      v65 = (v160 << 8) + dword_106EF8;
      v163 = v65;
      feature_guard_sdio(1, dword_106EFC);
      *(_DWORD *)(a2 + 140) = *(_DWORD *)(a2 + 152);
      log_free_pool_dispatch2_n4e6(a2, 0);
      v66 = 0;
      feature_guard_sdio(1, dword_106F00);
      v152 = v62;
      v67 = v64;
      v68 = v65 + 16 * v64;
      v69 = (int *)(v68 + v161);
      v70 = (_DWORD *)(v68 + v61);
      v157 = v63;
      v164 = v61;
      v158 = 0;
      v71 = 0;
      v72 = v67;
      v73 = 2 * v67;
      do
      {
        crypto_hw_enable(1);
        if ( a7 == v152 )
        {
          *v69 = *v69 & v153 | ((v159 & v66) << v86);
        }
        else
        {
          *v69 &= v157;
          *v70 &= v156;
          *v69 |= (v151 & v66) << v86;
          *v70 |= (v66 >> v149) & v155;
        }
        crypto_hw_disable(1);
        crypto_adc_capture(*a3, a2, v72, 0);
        feature_guard_sdio(1, dword_106F04);
        feature_guard_sdio(1, dword_106F0C);
        feature_guard_sdio(1, dword_106F14);
        if ( *(__int16 *)(a2 + v73) > v71 )
        {
          v71 = *(__int16 *)(a2 + v73);
          v158 = v66;
        }
        ++v66;
      }
      while ( v154 != v66 );
      if ( a8 > 2 && v160 == 1 )
      {
        if ( a8 == 6 )
          v76 = 1;
        else
          v76 = 2;
        v77 = v158 + v76;
        if ( v77 >= 3 )
          v77 = 3;
        v158 = v77;
      }
      feature_guard_sdio(1, dword_106F1C);
      crypto_hw_enable(1);
      v78 = v86;
      v87 = (v158 >> v149) & v155;
      v79 = (v151 & v158) << v78;
      v150 = (v158 & v159) << v78;
      v80 = (int *)(v163 + v161);
      v81 = (int *)(v161 + 192 + v162);
      v82 = (int *)(v162 + v161);
      v83 = v164 - v161;
      do
      {
        while ( 1 )
        {
          v84 = &v82[v161 / 0xFFFFFFFC];
          if ( a7 == v152 )
            break;
          *v80 &= v157;
          *(int *)((char *)v80 + v83) &= v156;
          *v80 |= v79;
          *(int *)((char *)v80 + v83) |= v87;
          *v82 &= v157;
          *(int *)((char *)v84 + v164) &= v156;
          *v82 |= v79;
          v82 += 3;
          *(int *)((char *)v84 + v164) |= v87;
          v80 += 4;
          if ( v82 == v81 )
            goto LABEL_58;
        }
        *v80 = *v80 & v153 | v150;
        *v82 = *v82 & v153 | v150;
        v82 += 3;
        v80 += 4;
      }
      while ( v82 != v81 );
LABEL_58:
      crypto_hw_disable(1);
      feature_guard_sdio(1, dword_107000);
      feature_guard_sdio(1, dword_107008);
    }
    goto LABEL_28;
  }
  if ( v20 )
  {
    v74 = (unsigned int *)off_106EE8;
    *(_DWORD *)off_106EE8 = a1;
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    v75 = *v74;
    log_free_pool_dispatch2_n4e6(a2, 0);
    feature_guard_sdio(1, dword_106F18);
    crypto_adc_capture(*a3, a2, (v75 >> 8) & 0xF, 0);
    goto LABEL_28;
  }
  *(_QWORD *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v35 = a3 - 1;
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
    sub_10624C(a1, v37, a5, a2, a6);
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    log_free_pool_dispatch2_n4e6(a2, v20);
    v39 = v35[1];
    ++v35;
    crypto_adc_capture(v39, a2, v37, v20);
    v40 = v20;
    v41 = *(unsigned __int16 *)(a2 + 2 * (v37 + 16 * v20++));
    sub_1063C0(a2, v41, v40);
  }
  while ( v20 != 3 );
  v42 = *(_DWORD *)(a2 + 132);
  if ( v42 <= *(_DWORD *)(a2 + 112) )
  {
    v43 = off_106900;
    v44 = dword_106910;
    do
    {
      while ( 1 )
      {
        sub_10624C(a1, v42, a5, a2, a6);
        v45 = *(_DWORD *)(a2 + 124);
        *v43 &= ~0x200u;
        *v43 |= 0x200u;
        *v43 &= ~0x200u;
        if ( v45 < v42 )
          break;
        log_free_pool_dispatch2_n4e6(a2, 2);
        feature_guard_sdio(1, v44);
        crypto_adc_capture(a3[2], a2, v42, 2);
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
        log_free_pool_dispatch2_n4e6(a2, 1);
        feature_guard_sdio(1, v44);
        crypto_adc_capture(a3[1], a2, v42, 1);
        goto LABEL_26;
      }
LABEL_23:
      log_free_pool_dispatch2_n4e6(a2, 0);
      feature_guard_sdio(1, v44);
      crypto_adc_capture(*a3, a2, v42++, 0);
    }
    while ( *(_DWORD *)(a2 + 112) >= v42 );
  }
LABEL_28:
  v46 = (unsigned int *)off_106C30;
  v47 = (unsigned int *)off_106C34;
  v48 = (unsigned int *)off_106C58;
  v49 = (unsigned int *)off_106C5C;
  v50 = off_106C54;
  *(_DWORD *)off_106C30 = *(_DWORD *)off_106C30 & 0xFFBFFFFF | (v148 << 22);
  *v46 = *v46 & 0xFFDFFFFF | (v147 << 21);
  mmio_config_clear_bits_n_0f0();
  v51 = off_106C38;
  v52 = (unsigned int *)off_106C3C;
  v53 = (unsigned int *)off_106C60;
  *(_DWORD *)off_106C38 = *(_DWORD *)off_106C38 & 0xF8FFFFFF | (v91 << 24);
  v54 = (unsigned int *)off_106C40;
  *v47 = *v47 & 0xFFFFFFBF | (v109 << 6);
  v55 = (unsigned int *)off_106C44;
  *v52 = *v52 & 0xFFFF8FFF | (v111 << 12);
  v56 = (unsigned int *)off_106C48;
  v57 = (unsigned int *)off_106C4C;
  *(_DWORD *)((char *)v51 + 0xFFFFFFDC) = *(_DWORD *)((char *)v51 + 0xFFFFFFDC) & 0xFF7FFFFF | (v113 << 23);
  *(_DWORD *)((char *)v51 + 0xFFFFFFDC) = *(_DWORD *)((char *)v51 + 0xFFFFFFDC) & 0xFFBFFFFF | (v115 << 22);
  v58 = (unsigned int *)off_106C50;
  *(_DWORD *)((char *)v51 + 0xFFFFFFDC) = *(_DWORD *)((char *)v51 + 0xFFFFFFDC) & 0xFFEFFFFF | (v117 << 20);
  *(_DWORD *)((char *)v51 + 0xFFFFFFDC) = *(_DWORD *)((char *)v51 + 0xFFFFFFDC) & 0xFFDFFFFF | (v119 << 21);
  *v54 = *v54 & 0xFFFBFFFF | (v143 << 18);
  v59 = off_106C64;
  *v54 = *v54 & 0xFFF7FFFF | (v142 << 19);
  *v54 = *v54 & 0xFFFDFFFF | (v121 << 17);
  *v54 = *v54 & 0xFFFEFFFF | (v123 << 16);
  *v54 = *v54 & 0xFFFF7FFF | (v125 << 15);
  *v54 = *v54 & 0xFFFFBFFF | (v127 << 14);
  *v55 = *v55 & 0xFFFBFFFF | (v129 << 18);
  *v48 = *v48 & 0xFFFFCFFF | (v131 << 12);
  *v56 = *v56 & 0xFFFFFFFC | v133;
  *v57 = *v57 & 0xFFE3FFFF | (v135 << 18);
  *v56 = *v56 & 0xFFFFFFFB | (4 * v137);
  *v54 = *v54 & 0xFF7FFFFF | (v139 << 23);
  *v54 = *v54 & 0xFFBFFFFF | (v141 << 22);
  *v53 = *v53 & 0xFFFFFFDF | (32 * v89);
  *v54 = *v54 & 0xFFDFFFFF | (v93 << 21);
  *v54 = *v54 & 0xFFEFFFFF | (v95 << 20);
  *v56 = *v56 & 0xFFFFFF0F | (16 * v97);
  *v58 = *v58 & 0xFFFFFF7F | (v99 << 7);
  *v58 = *v58 & 0xFFFFFF8F | (16 * v101);
  *v58 = *v58 & 0xFFFFFBFF | (v103 << 10);
  *v58 = *v58 & 0xFFFFFCFF | (v105 << 8);
  *v53 = *v53 & 0xFFFFFFE3 | (4 * v107);
  *v46 &= 0xFFFE00FF;
  *v46 &= ~0x20000u;
  *v46 |= 0x40000u;
  *v49 = *v49 & 0x7FFFFFFF | v146 & 0x80000000;
  *v50 = v145;
  *(v51 - 1902) = *(v51 - 1902) & 0xFFFFFEFF | (v144 << 8);
  *v59 |= 0x400u;
  *v59 &= ~0x400u;
  return v105;
}

