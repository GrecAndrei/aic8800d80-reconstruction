// sub_10B288 @ 0x10b288, size 3884 bytes
int __fastcall sub_10B288(
        _DWORD *a1,
        int a2,
        int a3,
        int a4,
        unsigned __int16 *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        __int64 *a11)
{
  int v11; // s26
  int v12; // r8
  int v13; // r1
  int v14; // r10
  int v15; // r9
  int *v16; // r7
  int v17; // lr
  int v18; // r12
  int i; // r6
  int v20; // r0
  unsigned int *v21; // r2
  int *v22; // r4
  unsigned int *v23; // r0
  unsigned int v24; // r3
  _DWORD *v25; // r4
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r1
  int v30; // r7
  unsigned int *v31; // r3
  int v32; // r0
  int v33; // r5
  int v34; // r4
  int v35; // r7
  int v36; // r9
  unsigned int v37; // r2
  int v38; // r0
  int *v39; // r10
  int v40; // r1
  int v41; // r12
  unsigned int *v42; // r2
  unsigned int *v43; // r8
  int *v44; // r12
  int v45; // t1
  int v46; // r1
  int v47; // r1
  int v48; // r2
  int v50; // r8
  unsigned int *v51; // r2
  int *v52; // lr
  unsigned int *v53; // r8
  int v54; // t1
  int v55; // r5
  unsigned int *v56; // r2
  int *v57; // r4
  unsigned int *v58; // r5
  unsigned int v59; // r3
  unsigned int v60; // r4
  int v61; // r9
  int v62; // r11
  int v63; // s25
  int *v64; // r12
  int v65; // r0
  int v66; // r1
  int v67; // r2
  int v68; // r3
  int v69; // r1
  int v70; // r2
  int v71; // r1
  int v72; // r11
  unsigned int v73; // r5
  unsigned int *v74; // r11
  unsigned int v75; // t1
  int v76; // r6
  int v77; // r10
  int v78; // r4
  int v79; // r1
  int v80; // r5
  int v81; // r1
  int v82; // r2
  unsigned int v83; // t1
  float v84; // s22
  int v85; // s19
  float *v86; // r3
  int v87; // r4
  int v88; // r1
  int v89; // r8
  unsigned int *v90; // r0
  int j; // r3
  unsigned int v92; // t1
  int v93; // r2
  unsigned int *v94; // r6
  unsigned int v95; // r11
  int v96; // lr
  float v97; // s20
  int v98; // r12
  int v99; // r5
  int v100; // r9
  __int64 v101; // kr00_8
  unsigned int v102; // r3
  unsigned int *v103; // r8
  int v104; // r4
  int v105; // r1
  int v106; // r11
  __int64 v107; // r0
  int v108; // r0
  int v109; // r0
  float v110; // r0
  __int64 v111; // r0
  __int64 v112; // r0
  int v113; // r1
  int v114; // r2
  int v115; // r4
  int v116; // r6
  float *v117; // r5
  __int64 v118; // r4
  int v119; // s27
  int v120; // s17
  int v121; // r7
  float v122; // s21
  float v123; // s23
  int v124; // r11
  int *v125; // r6
  int v126; // t1
  int v127; // r3
  int v128; // r11
  float v129; // s24
  int v130; // r4
  float v131; // s15
  float v132; // s17
  int v133; // r1
  int v134; // r3
  int v135; // r5
  int v136; // r6
  float v137; // s16
  unsigned int *v138; // r7
  float v139; // s17
  float v140; // s14
  _BYTE *v141; // r2
  bool v142; // zf
  __int16 v143; // r0
  int v144; // r2
  int v145; // r3
  __int16 *v146; // r6
  int v147; // t1
  int v148; // r3
  int *v149; // r6
  int v150; // t1
  int v151; // r3
  int v152; // r4
  unsigned int v153; // r0
  unsigned int *v154; // r4
  unsigned int v155; // t1
  int v156; // r12
  int v157; // r10
  int v158; // r3
  int v159; // r5
  unsigned int v160; // t1
  int v161; // r2
  int v162; // r0
  int v163; // r2
  int v164; // r10
  int v165; // r4
  unsigned int v166; // r0
  int v167; // [sp+Ch] [bp-588h]
  int v168; // [sp+24h] [bp-570h]
  int v169; // [sp+24h] [bp-570h]
  int v170; // [sp+28h] [bp-56Ch]
  int v171; // [sp+2Ch] [bp-568h]
  int v172; // [sp+30h] [bp-564h]
  int v173; // [sp+30h] [bp-564h]
  int *v174; // [sp+34h] [bp-560h]
  int v175; // [sp+34h] [bp-560h]
  int v176; // [sp+38h] [bp-55Ch]
  int v177; // [sp+38h] [bp-55Ch]
  int v178; // [sp+3Ch] [bp-558h]
  int v179; // [sp+40h] [bp-554h]
  int v180; // [sp+44h] [bp-550h]
  int v181; // [sp+48h] [bp-54Ch]
  int *v182; // [sp+4Ch] [bp-548h]
  unsigned __int16 *v183; // [sp+50h] [bp-544h]
  _BYTE *v184; // [sp+54h] [bp-540h]
  int v185; // [sp+58h] [bp-53Ch]
  int v186; // [sp+5Ch] [bp-538h]
  unsigned int *v187; // [sp+64h] [bp-530h]
  int v188; // [sp+68h] [bp-52Ch]
  int v189; // [sp+6Ch] [bp-528h]
  int v190; // [sp+70h] [bp-524h]
  __int64 v191; // [sp+70h] [bp-524h]
  int v193; // [sp+7Ch] [bp-518h]
  _DWORD *v195; // [sp+88h] [bp-50Ch]
  int v197; // [sp+94h] [bp-500h] BYREF
  __int16 v198; // [sp+98h] [bp-4FCh]
  _DWORD v199[6]; // [sp+9Ch] [bp-4F8h] BYREF
  int v200[48]; // [sp+B4h] [bp-4E0h] BYREF
  _BYTE v201[192]; // [sp+174h] [bp-420h] BYREF
  _WORD v202[48]; // [sp+234h] [bp-360h] BYREF
  float v203; // [sp+294h] [bp-300h]
  unsigned __int8 v204; // [sp+29Ch] [bp-2F8h]
  __int64 v205; // [sp+2A0h] [bp-2F4h]
  int v206; // [sp+2A8h] [bp-2ECh]
  __int64 v207; // [sp+2ACh] [bp-2E8h]
  int v208; // [sp+2B4h] [bp-2E0h]
  int v209; // [sp+2B8h] [bp-2DCh]
  float v210; // [sp+2BCh] [bp-2D8h]
  int v211; // [sp+2C8h] [bp-2CCh]
  int v212; // [sp+2CCh] [bp-2C8h]
  int v213; // [sp+2D0h] [bp-2C4h]
  int v214; // [sp+2D4h] [bp-2C0h]
  char v215; // [sp+2E4h] [bp-2B0h] BYREF
  float v216; // [sp+308h] [bp-28Ch] BYREF
  int v217; // [sp+30Ch] [bp-288h] BYREF
  __int16 v218; // [sp+310h] [bp-284h]
  int v219; // [sp+580h] [bp-14h]
  int v220; // [sp+584h] [bp-10h]

  sub_12ECB0(dword_10B454, a2, a3);
  v12 = dword_10B478;
  v13 = *(_DWORD *)off_10B458;
  v14 = dword_10B490;
  v15 = dword_10B47C;
  *(_DWORD *)off_10B458 &= ~1u;
  v193 = v13 & 1;
  v16 = (int *)v201;
  crypto_hw_enable(0);
  v17 = dword_10B474;
  v18 = dword_10B480;
  for ( i = 0; i != 3; ++i )
  {
    if ( i )
    {
      if ( i != 1 )
      {
        v20 = v18;
        goto LABEL_5;
      }
      v20 = v14;
      v55 = v15;
    }
    else
    {
      v20 = v12;
      v55 = v17;
    }
    v56 = (unsigned int *)(v55 + 4);
    v57 = &v200[16 * i + 16];
    v58 = (unsigned int *)(v55 + 516);
    do
    {
      v59 = *v56;
      *v56 = *v56 & 0xFFF1FFFF | 0x20000;
      v56 += 8;
      *v57++ = (v59 >> 17) & 7;
    }
    while ( v56 != v58 );
LABEL_5:
    v21 = (unsigned int *)(v20 + 4);
    v22 = v16;
    v23 = (unsigned int *)(v20 + 516);
    do
    {
      v24 = *v21;
      *v21 = *v21 & 0xFFF1FFFF | 0x20000;
      v21 += 8;
      *v22++ = (v24 >> 17) & 7;
    }
    while ( v21 != v23 );
    v16 += 16;
  }
  v25 = off_10B45C;
  crypto_hw_disable(0);
  feature_guard_sdio(1, dword_10B464);
  v26 = dword_10B468;
  *v25 |= 0x400u;
  *v25 &= ~0x400u;
  sub_12ECB0(v26, v27, v28);
  feature_guard_sdio(1, dword_10B46C);
  v183 = a5;
  v195 = v25;
  while ( 2 )
  {
    v30 = *((unsigned __int8 *)v183 + 4);
    if ( v30 != 1 )
      goto LABEL_10;
    v60 = *v183;
    feature_guard_sdio(1, dword_10B768);
    if ( v60 <= 0x1388 )
    {
      v61 = dword_10B79C;
      v62 = a2;
      v172 = 0;
      v63 = 0;
      v189 = 0;
      v168 = 0;
      v30 = 0;
      v170 = 0;
      v174 = v199;
      goto LABEL_29;
    }
    v162 = sub_102984(v60);
    v163 = (int)off_10C14C;
    v170 = (unsigned __int8)(v162 + 1);
    v61 = dword_10C150 + 384 * v162;
    if ( (*((_BYTE *)off_10C14C + 1) & 1) == 0 || (v163 = *(char *)off_10C14C, v163 >= 0) )
    {
      v164 = dword_10C164;
      sub_12ECB0(dword_10C154, dword_10C150, v163);
      v165 = 0;
      v63 = v170;
      while ( 1 )
      {
        v217 = 0;
        v218 = 0;
        v166 = v164 | (v165 << 12);
        if ( v165 == 1 )
        {
          v212 = 3;
          LOWORD(v217) = 2048;
          sub_106450(v166, (int)v202, (__int16 *)&v217, 0, 1, 1, 1, v170);
        }
        else
        {
          v212 = 3;
          LOWORD(v217) = 2048;
          sub_106450(v166, (int)v202, (__int16 *)&v217, 0, 1, v165, 1, v170);
          if ( v165 == 2 )
          {
            v189 = 1;
            v62 = a2 + 1264 * v170;
            v172 = 3 * v170;
            v168 = 3 * v170;
            v174 = &v199[v170];
            goto LABEL_29;
          }
        }
        ++v165;
      }
    }
    v30 = *((_BYTE *)off_10C14C + 1) & 1;
    v63 = (unsigned __int8)(v162 + 1);
    v62 = a2 + 1264 * v170;
    v172 = 3 * v170;
    v168 = 3 * v170;
    v174 = &v199[v170];
    v189 = 1;
LABEL_29:
    v64 = (int *)dword_10B7A0;
    *v195 |= 0x400u;
    v65 = *v64;
    v66 = v64[1];
    v67 = v64[2];
    v68 = v64[3];
    v64 += 4;
    *v195 &= ~0x400u;
    v199[0] = v65;
    v199[1] = v66;
    v199[2] = v67;
    v199[3] = v68;
    v69 = v64[1];
    v70 = v62 + 16;
    v199[4] = *v64;
    v199[5] = v69;
    v71 = v62;
    v72 = v62 - 4;
    sub_109F90(a1, v71, v70, v170, (int)v199, a6, a7, v167, a9, a10, a11);
    delay_us(0);
    v75 = *(_DWORD *)(v72 + 4);
    v74 = (unsigned int *)(v72 + 4);
    v73 = v75;
    v76 = 0;
    if ( !v75 )
      goto LABEL_36;
    while ( 1 )
    {
      if ( v30 == 1 )
      {
        if ( v76 )
        {
          if ( v76 == 1 )
            v77 = 64;
          else
            v77 = 96;
          if ( v76 == 1 )
            v78 = 32;
          else
            v78 = 64;
        }
        else
        {
          v77 = 32;
          v78 = 0;
        }
      }
      else
      {
        if ( v76 == 1 )
        {
          feature_guard_sdio(1, dword_10C158);
          *(_DWORD *)off_10C15C |= 0x8000u;
          goto LABEL_35;
        }
        v77 = 64;
        v78 = 32;
      }
      v79 = dword_10B76C;
      v80 = HIWORD(v73) & 1;
      *(_BYTE *)(a3 + v168 + v76) = v80;
      feature_guard_sdio(1, v79);
      rf_xo_pll_config(*v74, (int)&v217, v30);
      feature_guard_sdio(1, dword_10B770);
      feature_guard_sdio(1, dword_10B774);
      if ( v80 && v78 < v77 )
      {
        v152 = v61 + 4 * (v78 + 0x3FFFFFFF);
        v155 = *(_DWORD *)(v152 + 4);
        v154 = (unsigned int *)(v152 + 4);
        v153 = v155;
        v156 = dword_10C160;
        v82 = (v155 >> 8) & 0xF;
        v157 = v61 - 4 + 4 * v77;
        v158 = v80;
        v159 = 15 - v82;
        if ( !v30 )
          goto LABEL_152;
        while ( 1 )
        {
          if ( v82 == 7 )
            v159 = 5;
LABEL_155:
          v81 = v220;
          if ( v220 <= v82 )
          {
            v81 = v219;
            if ( v219 >= v82 )
            {
              if ( v82 > 8 || (v81 = *v174) != 0 || v76 != 1 )
              {
                *v154 = v153 & 0xFF3F7FFF | (v159 << 24);
              }
              else
              {
                *v154 = v153 | 0xC08000;
                v177 = v158;
                feature_guard_sdio(1, v156);
                v156 = dword_10C160;
                v158 = v177;
              }
            }
          }
          if ( (unsigned int *)v157 == v154 )
            break;
          v160 = v154[1];
          ++v154;
          v153 = v160;
          v82 = (v160 >> 8) & 0xF;
          v159 = 15 - v82;
          if ( !v30 )
          {
LABEL_152:
            if ( v82 == 4 )
            {
              v159 = v158;
            }
            else if ( v82 == 7 )
            {
              v159 = 0;
            }
            goto LABEL_155;
          }
        }
      }
      if ( v76 == 2 )
        break;
LABEL_35:
      while ( 1 )
      {
        v83 = v74[1];
        ++v74;
        v73 = v83;
        ++v76;
        if ( v83 )
          break;
LABEL_36:
        feature_guard_sdio(1, dword_10B778);
        if ( v76 == 2 )
          goto LABEL_37;
      }
    }
LABEL_37:
    v188 = dword_10B77C;
    sub_12ECB0(dword_10B780, v81, v82);
    v84 = flt_10B78C;
    v182 = (int *)(dword_10B784 + 4 * v63);
    v85 = 0;
    v179 = 0;
    v184 = (_BYTE *)(v172 + dword_10B788);
    v171 = 0;
    v187 = (unsigned int *)(v61 + 64);
    while ( 2 )
    {
      feature_guard_sdio(1, dword_10B790);
      memset_thunk(v200, 0, 0x40u);
      v216 = 1.0;
      v210 = v84;
      v209 = 8;
      v205 = 15;
      v86 = (float *)&v215;
      do
        *v86++ = v84;
      while ( &v216 != v86 );
      if ( v170 )
      {
        v198 = 1792;
        HIWORD(v197) = 2048;
        if ( v171 )
        {
          if ( v171 == 1 )
          {
            LOWORD(v197) = 2048;
            v87 = 8;
            v212 = 4;
            v213 = 4;
            v88 = 12;
            v207 = 0x800000009LL;
            v208 = 12;
            v214 = 8;
            v185 = 4096;
          }
          else
          {
            v142 = (*(_BYTE *)off_10BDCC & 0xC0) == 192;
            v212 = 6;
            v213 = 6;
            if ( v142 )
              v143 = 768;
            else
              v143 = 960;
            v88 = 12;
            v214 = 6;
            v207 = 0x900000009LL;
            LOWORD(v197) = v143;
            v208 = 12;
            v185 = 0;
            v87 = 8;
          }
        }
        else
        {
          v88 = 14;
          v212 = 4;
          v213 = 4;
          v87 = 8;
          v207 = 0x90000000ELL;
          v208 = 14;
          LOWORD(v197) = 896;
          v214 = 8;
          v185 = 0x2000;
        }
      }
      else
      {
        v87 = 8;
        v207 = 0x80000000BLL;
        v88 = 12;
        v208 = 12;
        if ( v171 )
        {
          v197 = dword_10B794;
          v198 = 1280;
          if ( v171 == 2 )
            v197 = 83887360;
          v87 = 7;
          v88 = 11;
          v207 = 0x90000000ALL;
          v208 = 11;
          v209 = 7;
          v212 = 2;
          v213 = 2;
          v214 = 4;
          v185 = 0;
        }
        else
        {
          v212 = 0;
          v197 = dword_10C13C;
          v198 = 2431;
          v214 = 8;
          v213 = 6;
          v185 = 4096;
        }
      }
      v89 = -100;
      v90 = v187 - 17;
      for ( j = 0; j != 32; ++j )
      {
        v92 = v90[1];
        ++v90;
        if ( (int)((v92 >> 8) & 0xF) < v87 )
        {
          v93 = j <= 15 ? j : j - 32;
          if ( v89 < v93 )
            v89 = v93;
        }
      }
      v176 = 255;
      v175 = 255;
      v178 = 255;
      v190 = v61;
      v180 = 0;
      v181 = 0;
      v94 = v187;
      v95 = v188;
      v173 = v89 + 1;
      v96 = v11;
      v97 = v84;
      v98 = 0;
      v99 = -16;
      v186 = v89;
      v100 = v89 + 1;
      v101 = 15;
      while ( 1 )
      {
        if ( v99 >= 0 )
        {
          v102 = *(v94 - 32);
          v169 = v99;
          v103 = v94 - 32;
          v104 = (v102 >> 8) & 0xF;
        }
        else
        {
          v102 = *v94;
          v169 = v99 + 32;
          v103 = v94;
          v104 = (*v94 >> 8) & 0xF;
        }
        if ( SHIDWORD(v101) < v104 )
          HIDWORD(v205) = v104;
        if ( (int)v101 > v104 )
          LODWORD(v205) = v104;
        if ( v88 == v104 && !v98 )
        {
          if ( *v184 )
          {
            feature_guard_sdio(1, dword_10BA0C);
          }
          else
          {
            v105 = dword_10BA04;
            *v182 = (unsigned __int8)v102;
            *v184 = 1;
            feature_guard_sdio(1, v105);
          }
          v106 = *v182;
          v107 = sub_142A70(*v182);
          v108 = sub_142D98(v107, HIDWORD(v107), 0, dword_10BA08);
          v109 = sub_143108(v108);
          v97 = rf_state_check_n3ea_d908(v109) * 20.0;
          v178 = v169;
          v110 = sub_12D748((float)-v97 / 20.0);
          v111 = sub_142A94((float)v106 * v110);
          v112 = sub_1426B8(v111, HIDWORD(v111));
          v96 = sub_143078(v112, HIDWORD(v112));
          v95 = v96 | v185 | 0xFFC000;
          v98 = 1;
        }
        if ( (_DWORD)v207 == v104 && !v180 )
        {
          v175 = v169;
          v180 = 1;
        }
        if ( HIDWORD(v207) == v104 && !v181 )
        {
          v176 = v169;
          v181 = 1;
        }
        if ( v100 == v99 )
          *(_BYTE *)off_10B798 = *v103;
        ++v99;
        ++v94;
        if ( v99 == 16 )
          break;
        v101 = v205;
        v88 = v208;
      }
      v61 = v190;
      v188 = v95;
      v11 = v96;
      feature_guard_sdio(1, dword_10BA14);
      if ( v178 == 255 )
      {
        sub_12ECB0(dword_10C140, v113, v114);
        sub_12ECB0(dword_10C144, 255, v161);
        v11 = 100;
        v145 = v175;
        if ( v175 != 255 )
          goto LABEL_130;
        goto LABEL_167;
      }
      if ( v175 != 255 && v176 != 255 )
        goto LABEL_80;
      sub_12ECB0(dword_10BDD0, v113, v114);
      v145 = v175;
      if ( v175 == 255 )
LABEL_167:
        sub_12ECB0(dword_10C148, v145, v144);
LABEL_130:
      if ( v176 == 255 )
        sub_12ECB0(dword_10BDD4, 255, v144);
LABEL_80:
      if ( v178 > 15 )
        v178 -= 32;
      if ( v175 > 15 )
        v175 -= 32;
      if ( v176 > 15 )
        v176 -= 32;
      feature_guard_sdio(1, dword_10BA18);
      v115 = v209;
      if ( v209 <= SHIDWORD(v205) )
      {
        v116 = dword_10BA1C;
        v117 = (float *)&v202[2 * v209 + 74];
        do
        {
          *v117++ = (float)(v208 - v115) * v216;
          feature_guard_sdio(1, v116);
          ++v115;
        }
        while ( SHIDWORD(v205) >= v115 );
      }
      sub_106450(v95, (int)v202, (__int16 *)&v197, 0, v189, v171, 0, v63);
      v118 = v207;
      v119 = (__int16)v202[v208];
      v120 = (__int16)v202[(_DWORD)v207 + 16];
      v121 = (__int16)v202[HIDWORD(v207) + 32];
      if ( (int)v207 <= SHIDWORD(v205) )
      {
        HIDWORD(v118) = &v202[v207 - 1];
        v149 = &v200[v207];
        do
        {
          v150 = *(__int16 *)(HIDWORD(v118) + 2);
          HIDWORD(v118) += 2;
          sub_104FE0(v150, v119, (int)v202);
          v151 = HIDWORD(v205);
          *(float *)v149++ = v203;
          LODWORD(v118) = v118 + 1;
        }
        while ( v151 >= (int)v118 );
        v122 = (float)(v175 - v178) - *(float *)&v200[v207];
        feature_guard_sdio(1, dword_10C130);
        sub_105088(v122, v11, (int)v202);
        feature_guard_sdio(1, dword_10C134);
        v118 = v207;
      }
      else
      {
        v122 = v84;
      }
      if ( SHIDWORD(v118) < (int)v118 )
      {
        v146 = &v202[HIDWORD(v118) + 16];
        LODWORD(v118) = &v200[HIDWORD(v118)];
        do
        {
          v147 = *v146++;
          feature_guard_sdio(1, dword_10C128);
          sub_104FE0(v147, v120, (int)v202);
          v148 = HIDWORD(v207);
          *(float *)v118 = v203;
          LODWORD(v118) = v118 + 4;
          v123 = (float)(v176 - v175) - *(float *)&v200[v148];
          ++HIDWORD(v118);
          feature_guard_sdio(1, dword_10C12C);
        }
        while ( (int)v207 > SHIDWORD(v118) );
        HIDWORD(v118) = HIDWORD(v207);
      }
      else
      {
        v123 = v84;
      }
      LODWORD(v118) = v209;
      if ( v209 < SHIDWORD(v118) )
      {
        v124 = dword_10BA20;
        HIDWORD(v118) = &v202[v209 + 32];
        v125 = &v200[v209];
        do
        {
          v126 = (__int16)*(_WORD *)HIDWORD(v118);
          HIDWORD(v118) += 2;
          feature_guard_sdio(1, v124);
          sub_104FE0(v126, v121, (int)v202);
          v127 = HIDWORD(v207);
          *(float *)v125++ = v203;
          LODWORD(v118) = v118 + 1;
        }
        while ( v127 > (int)v118 );
      }
      v128 = dword_10BA24;
      v129 = v84;
      v130 = 15;
      while ( 2 )
      {
        while ( 2 )
        {
          if ( v130 < 0 )
            v134 = v179 + 32;
          else
            v134 = v179;
          v135 = v134 + v130;
          v136 = (*(_DWORD *)(v61 + 4 * (v134 + v130)) >> 8) & 0xF;
          v137 = *(float *)&v200[v136];
          v206 = v136;
          v138 = (unsigned int *)(v61 + 4 * (v134 + v130));
          if ( v186 < v130 )
          {
            if ( v136 > 9 )
              v131 = v84;
            else
              v131 = v210;
            if ( (int)v207 <= v136 )
            {
              v85 = v130 - v178;
              v139 = (float)((float)((float)((float)(v130 - v178) - v137) + v97) + v131) + *((float *)&v211 + v136);
              feature_guard_sdio(1, dword_10BDB4);
              feature_guard_sdio(1, dword_10BDB8);
              sub_105088(v139, v11, (int)v202);
            }
            else
            {
              if ( SHIDWORD(v207) > v136 )
              {
                v85 = v130 - v176;
                v132 = (float)((float)((float)((float)((float)((float)(v130 - v176) - v137) + v123) + v122) + v97) + v131)
                     + *((float *)&v211 + v136);
                feature_guard_sdio(1, dword_10BDAC);
                feature_guard_sdio(1, dword_10BDB0);
              }
              else
              {
                v85 = v130 - v175;
                v132 = (float)((float)((float)((float)((float)(v130 - v175) - v137) + v122) + v97) + v131)
                     + *((float *)&v211 + v136);
                feature_guard_sdio(1, dword_10BDA0);
                feature_guard_sdio(1, dword_10BDA4);
              }
              sub_105088(v132, v11, (int)v202);
            }
            feature_guard_sdio(1, v128);
            if ( v173 == v130 )
            {
              feature_guard_sdio(1, dword_10BDC4);
              sub_104FE0(v204, *(unsigned __int8 *)off_10BDC8, (int)v202);
              v129 = v203;
            }
          }
          else
          {
            feature_guard_sdio(1, dword_10BDA8);
            sub_105088(v129, *(unsigned __int8 *)(v61 + 4 * v135), (int)v202);
          }
          feature_guard_sdio(1, v128);
          *(_BYTE *)v138 = v204;
          if ( v170 || v171 || v136 != 15 )
          {
LABEL_108:
            if ( --v130 == -17 )
              goto LABEL_120;
            continue;
          }
          break;
        }
        feature_guard_sdio(1, dword_10BDBC);
        sub_106450(*v138, (int)v202, (__int16 *)&v197, 1, v189, 0, 0, 0);
        sub_104FE0(v202[15], v119, (int)v202);
        v140 = v203;
        feature_guard_sdio(1, dword_10BDB8);
        v191 = sub_142A94((float)v85 - v140);
        if ( !sub_143064(v191, HIDWORD(v191), dword_10BD90, dword_10BD94)
          && !sub_143028(v191, HIDWORD(v191), dword_10BD98, dword_10BD9C) )
        {
          feature_guard_sdio(1, dword_10C138);
          goto LABEL_108;
        }
        sub_105088((float)v85 - v140, v204, (int)v202);
        --v130;
        feature_guard_sdio(1, v128);
        *(_BYTE *)v138 = v204;
        if ( v130 != -17 )
          continue;
        break;
      }
LABEL_120:
      v179 += 32;
      v182 += 7;
      v187 += 32;
      v141 = v184 + 1;
      v142 = v171++ == 2;
      ++v184;
      if ( !v142 )
        continue;
      break;
    }
    sub_12ECB0(dword_10BDC0, v133, v141);
LABEL_10:
    v183 += 4;
    if ( v183 != a5 + 28 )
      continue;
    break;
  }
  v31 = (unsigned int *)off_10B45C;
  v32 = dword_10B470;
  v33 = dword_10B474;
  v34 = dword_10B478;
  v35 = dword_10B47C;
  v36 = dword_10B490;
  *(_DWORD *)off_10B45C |= 0x400u;
  v37 = *v31 & 0xFFFFFBFF;
  *v31 = v37;
  sub_12ECB0(v32, v29, v37);
  crypto_hw_enable(0);
  v38 = dword_10B480;
  v39 = (int *)v201;
  v40 = 0;
  while ( 2 )
  {
    if ( v40 )
    {
      if ( v40 != 1 )
      {
        v41 = v38;
        goto LABEL_15;
      }
      v50 = v35;
      v41 = v36;
    }
    else
    {
      v50 = v33;
      v41 = v34;
    }
    v51 = (unsigned int *)(v50 + 4);
    v52 = &v200[16 * v40 + 16];
    v53 = (unsigned int *)(v50 + 484);
    do
    {
      v54 = *v52++;
      *v51 = *v51 & 0xFFF1FFFF | (v54 << 17);
      v51 += 8;
    }
    while ( v53 != v51 );
LABEL_15:
    v42 = (unsigned int *)(v41 + 4);
    v43 = (unsigned int *)(v41 + 484);
    v44 = v39;
    do
    {
      v45 = *v44++;
      *v42 = *v42 & 0xFFF1FFFF | (v45 << 17);
      v42 += 8;
    }
    while ( v43 != v42 );
    ++v40;
    v39 += 16;
    if ( v40 != 3 )
      continue;
    break;
  }
  crypto_hw_disable(0);
  v46 = dword_10B488;
  *(_DWORD *)off_10B458 = *(_DWORD *)off_10B458 & 0xFFFFFFFE | v193;
  feature_guard_sdio(1, v46);
  return sub_12ECB0(dword_10B48C, v47, v48);
}

