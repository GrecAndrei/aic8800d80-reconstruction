// v23 annotated: sub_10B048 @ 0x10b048
// Original: 10b048_sub_10B048.c
// Primary struct: <unclustered>
//
// sub_10B048 @ 0x10b048, size 3748 bytes
int __fastcall sub_10B048(
        int *a1,
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
  float v26; // s18
  int v27; // r2
  int v28; // r3
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r3
  int v33; // r1
  int v34; // r7
  _DWORD *v35; // r3
  int v36; // r0
  int v37; // r5
  int v38; // r4
  int v39; // r7
  int v40; // r9
  int v41; // r0
  int *v42; // r10
  int k; // r1
  int v44; // r12
  unsigned int *v45; // r2
  unsigned int *v46; // r8
  int *v47; // r12
  int v48; // t1
  _DWORD *v49; // r0
  int v50; // r1
  unsigned int v51; // r3
  int v52; // r1
  int v54; // r8
  unsigned int *v55; // r2
  int *v56; // lr
  unsigned int *v57; // r8
  int v58; // t1
  int v59; // r5
  unsigned int *v60; // r2
  int *v61; // r4
  unsigned int *v62; // r5
  unsigned int v63; // r3
  unsigned int v64; // r4
  int v65; // r9
  int v66; // r11
  int v67; // s25
  int *v68; // r12
  int v69; // r0
  int v70; // r1
  int v71; // r2
  int v72; // r3
  int v73; // r1
  int v74; // r2
  int v75; // r1
  int v76; // r11
  int v77; // r2
  int v78; // r3
  unsigned int v79; // r5
  unsigned int *v80; // r11
  unsigned int v81; // t1
  int v82; // r6
  int v83; // r10
  int v84; // r4
  int v85; // r1
  int v86; // r5
  int v87; // r3
  int v88; // r3
  int v89; // r3
  int v90; // r1
  unsigned int v91; // t1
  float v92; // s22
  int v93; // s19
  int v94; // r3
  float *v95; // r3
  int v96; // r4
  int v97; // r1
  int v98; // r8
  unsigned int *v99; // r0
  int j; // r3
  unsigned int v101; // t1
  int v102; // r2
  unsigned int *v103; // r6
  unsigned int v104; // r11
  int v105; // lr
  float v106; // s20
  int v107; // r12
  int v108; // r5
  int v109; // r9
  int v110; // r0
  __int64 v111; // kr00_8
  unsigned int v112; // r3
  unsigned int *v113; // r8
  int v114; // r4
  int v115; // r1
  int v116; // r11
  __int64 v117; // r0
  int v118; // r0
  int v119; // r0
  float v120; // r0
  __int64 v121; // r0
  __int64 v122; // r0
  int v123; // r1
  int v124; // r4
  int v125; // r6
  float *v126; // r5
  float v127; // s15
  __int64 v128; // r4
  int v129; // s27
  int v130; // s17
  int v131; // r7
  float v132; // s21
  float v133; // s23
  int v134; // r11
  float *v135; // r6
  int v136; // t1
  int v137; // r3
  int v138; // r11
  float v139; // s24
  int v140; // r4
  float v141; // s15
  float v142; // s17
  int v143; // r2
  int v144; // r1
  int v145; // r2
  int v146; // r3
  int v147; // r5
  int v148; // r6
  float v149; // s16
  unsigned int *v150; // r7
  float v151; // s17
  float v152; // s14
  int v153; // r3
  bool v154; // zf
  __int16 v155; // r0
  int v156; // r3
  __int16 *v157; // r6
  int v158; // t1
  int v159; // r3
  float *v160; // r3
  float *v161; // r6
  int v162; // t1
  int v163; // r3
  int v164; // r4
  unsigned int v165; // r0
  unsigned int *v166; // r4
  unsigned int v167; // t1
  int v168; // r12
  int v169; // r10
  int v170; // r5
  unsigned int v171; // t1
  int v172; // r0
  int v173; // r10
  int v174; // r4
  unsigned int v175; // r0
  int v176; // [sp+Ch] [bp-588h]
  int v177; // [sp+24h] [bp-570h]
  int v178; // [sp+24h] [bp-570h]
  int v179; // [sp+28h] [bp-56Ch]
  int v180; // [sp+2Ch] [bp-568h]
  int v181; // [sp+30h] [bp-564h]
  int v182; // [sp+30h] [bp-564h]
  int *v183; // [sp+34h] [bp-560h]
  int v184; // [sp+34h] [bp-560h]
  int v185; // [sp+38h] [bp-55Ch]
  int v186; // [sp+38h] [bp-55Ch]
  int v187; // [sp+3Ch] [bp-558h]
  int v188; // [sp+40h] [bp-554h]
  int v189; // [sp+44h] [bp-550h]
  int v190; // [sp+48h] [bp-54Ch]
  int *v191; // [sp+4Ch] [bp-548h]
  unsigned __int16 *v192; // [sp+50h] [bp-544h]
  _BYTE *v193; // [sp+54h] [bp-540h]
  int v194; // [sp+58h] [bp-53Ch]
  int v195; // [sp+5Ch] [bp-538h]
  unsigned int *v196; // [sp+64h] [bp-530h]
  int v197; // [sp+68h] [bp-52Ch]
  int v198; // [sp+6Ch] [bp-528h]
  int v199; // [sp+70h] [bp-524h]
  __int64 v200; // [sp+70h] [bp-524h]
  int v202; // [sp+7Ch] [bp-518h]
  _DWORD *v204; // [sp+88h] [bp-50Ch]
  int v206; // [sp+94h] [bp-500h] BYREF
  __int16 v207; // [sp+98h] [bp-4FCh]
  _DWORD v208[6]; // [sp+9Ch] [bp-4F8h] BYREF
  int v209[48]; // [sp+B4h] [bp-4E0h] BYREF
  _BYTE v210[192]; // [sp+174h] [bp-420h] BYREF
  _WORD v211[48]; // [sp+234h] [bp-360h] BYREF
  float v212; // [sp+294h] [bp-300h]
  unsigned __int8 v213; // [sp+29Ch] [bp-2F8h]
  __int64 v214; // [sp+2A0h] [bp-2F4h]
  int v215; // [sp+2A8h] [bp-2ECh]
  __int64 v216; // [sp+2ACh] [bp-2E8h]
  int v217; // [sp+2B4h] [bp-2E0h]
  int v218; // [sp+2B8h] [bp-2DCh]
  float v219; // [sp+2BCh] [bp-2D8h]
  int v220; // [sp+2C8h] [bp-2CCh]
  int v221; // [sp+2CCh] [bp-2C8h]
  int v222; // [sp+2D0h] [bp-2C4h]
  int v223; // [sp+2D4h] [bp-2C0h]
  char v224; // [sp+2E4h] [bp-2B0h] BYREF
  float v225; // [sp+308h] [bp-28Ch] BYREF
  int v226; // [sp+30Ch] [bp-288h] BYREF
  __int16 v227; // [sp+310h] [bp-284h]
  int v228; // [sp+580h] [bp-14h]
  int v229; // [sp+584h] [bp-10h]

  msg_parse(dword_10B214, a2);
  v12 = dword_10B234;
  v13 = *(_DWORD *)off_10B218;
  v14 = dword_10B23C;
  v15 = dword_10B250;
  *(_DWORD *)off_10B218 &= ~1u;
  v202 = v13 & 1;
  v16 = (int *)v210;
  sub_102ADC(0);
  v17 = dword_10B238;
  v18 = dword_10B240;
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
      v59 = v15;
    }
    else
    {
      v20 = v12;
      v59 = v17;
    }
    v60 = (unsigned int *)(v59 + 4);
    v61 = &v209[16 * i + 16];
    v62 = (unsigned int *)(v59 + 516);
    do
    {
      v63 = *v60;
      *v60 = *v60 & 0xFFF1FFFF | 0x20000;
      v60 += 8;
      *v61++ = (v63 >> 17) & 7;
    }
    while ( v60 != v62 );
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
    while ( v23 != v21 );
    v16 += 16;
  }
  v25 = off_10B21C;
  v26 = flt_10B220;
  sub_102B40(0);
  sub_11F74C(1, dword_10B224, v27, v28);
  v29 = dword_10B228;
  *v25 |= 0x400u;
  *v25 &= ~0x400u;
  msg_parse(v29, v30);
  sub_11F74C(1, dword_10B22C, v31, v32);
  v192 = a5;
  v204 = v25;
  do
  {
    v34 = *((unsigned __int8 *)v192 + 4);
    if ( v34 != 1 )
      goto LABEL_10;
    v64 = *v192;
    sub_11F74C(1, dword_10B52C, v64, v192);
    if ( v64 <= 0x1388 )
    {
      v65 = dword_10B560;
      v66 = a2;
      v181 = 0;
      v67 = 0;
      v198 = 0;
      v177 = 0;
      v34 = 0;
      v179 = 0;
      v183 = v208;
      goto LABEL_29;
    }
    v172 = sub_102968(v64);
    v173 = dword_10BF24;
    v174 = 0;
    v179 = (unsigned __int8)(v172 + 1);
    v67 = v179;
    v65 = dword_10BF10 + 384 * v172;
    msg_parse(dword_10BF14, v172 + 1);
    while ( 1 )
    {
      v226 = 0;
      v227 = 0;
      v175 = v173 | (v174 << 12);
      if ( v174 != 1 )
        break;
      v221 = 3;
      LOWORD(v226) = 2048;
      sub_105FD0(v175, (int)v211, (__int16 *)&v226, 0, 1, 1, 1, v179);
LABEL_177:
      ++v174;
    }
    v221 = 3;
    LOWORD(v226) = 2048;
    sub_105FD0(v175, (int)v211, (__int16 *)&v226, 0, 1, v174, 1, v179);
    if ( v174 != 2 )
      goto LABEL_177;
    v198 = 1;
    v66 = a2 + 1264 * v179;
    v181 = 3 * v179;
    v177 = 3 * v179;
    v183 = &v208[v179];
LABEL_29:
    v68 = (int *)dword_10B564;
    *v204 |= 0x400u;
    v69 = *v68;
    v70 = v68[1];
    v71 = v68[2];
    v72 = v68[3];
    v68 += 4;
    *v204 &= ~0x400u;
    v208[0] = v69;
    v208[1] = v70;
    v208[2] = v71;
    v208[3] = v72;
    v73 = v68[1];
    v74 = v66 + 16;
    v208[4] = *v68;
    v208[5] = v73;
    v75 = v66;
    v76 = v66 - 4;
    rf_sub_1209D40(a1, v75, v74, v179, (int)v208, a6, a7, v176, a9, a10, a11);
    delay_us(0);
    v81 = *(_DWORD *)(v76 + 4);
    v80 = (unsigned int *)(v76 + 4);
    v79 = v81;
    v82 = 0;
    if ( v81 )
    {
LABEL_30:
      if ( v34 == 1 )
      {
        if ( v82 )
        {
          if ( v82 == 1 )
            v83 = 64;
          else
            v83 = 96;
          if ( v82 == 1 )
            v84 = 32;
          else
            v84 = 64;
        }
        else
        {
          v83 = 32;
          v84 = 0;
        }
      }
      else
      {
        if ( v82 == 1 )
        {
          sub_11F74C(1, dword_10BF18, v77, v78);
          v77 = (int)off_10BF1C;
          v78 = *(_DWORD *)off_10BF1C | 0x8000;
          *(_DWORD *)off_10BF1C = v78;
          goto LABEL_35;
        }
        v83 = 64;
        v84 = 32;
      }
      v85 = dword_10B530;
      v86 = HIWORD(v79) & 1;
      *(_BYTE *)(a3 + v177 + v82) = v86;
      sub_11F74C(1, v85, v82, v86);
      sub_105494(*v80, (int)&v226, v34, v87);
      sub_11F74C(1, dword_10B534, v228, v88);
      sub_11F74C(1, dword_10B538, v229, v89);
      if ( v86 && v84 < v83 )
      {
        v164 = v65 + 4 * (v84 + 0x3FFFFFFF);
        v167 = *(_DWORD *)(v164 + 4);
        v166 = (unsigned int *)(v164 + 4);
        v165 = v167;
        v168 = dword_10BF20;
        v77 = (v167 >> 8) & 0xF;
        v169 = v65 - 4 + 4 * v83;
        v78 = v86;
        v170 = 15 - v77;
        if ( !v34 )
          goto LABEL_152;
        while ( 1 )
        {
          if ( v77 == 7 )
            v170 = 5;
LABEL_155:
          v90 = v229;
          if ( v229 <= v77 )
          {
            v90 = v228;
            if ( v228 >= v77 )
            {
              if ( v77 > 8 || (v90 = *v183) != 0 || v82 != 1 )
              {
                *v166 = v165 & 0xFF3F7FFF | (v170 << 24);
              }
              else
              {
                *v166 = v165 | 0xC08000;
                v186 = v78;
                sub_11F74C(1, v168, v77, v78);
                v168 = dword_10BF20;
                v78 = v186;
              }
            }
          }
          if ( (unsigned int *)v169 == v166 )
            break;
          v171 = v166[1];
          ++v166;
          v165 = v171;
          v77 = (v171 >> 8) & 0xF;
          v170 = 15 - v77;
          if ( !v34 )
          {
LABEL_152:
            if ( v77 == 4 )
            {
              v170 = v78;
            }
            else if ( v77 == 7 )
            {
              v170 = 0;
            }
            goto LABEL_155;
          }
        }
      }
      if ( v82 != 2 )
        goto LABEL_35;
    }
    else
    {
      while ( 1 )
      {
        sub_11F74C(1, dword_10B53C, v82, v78);
        if ( v82 == 2 )
          break;
LABEL_35:
        v91 = v80[1];
        ++v80;
        v79 = v91;
        ++v82;
        if ( v91 )
          goto LABEL_30;
      }
    }
    v197 = dword_10B540;
    msg_parse(dword_10B544, v90);
    v92 = flt_10B550;
    v191 = (int *)(dword_10B548 + 4 * v67);
    v93 = 0;
    v94 = v65 + 64;
    v188 = 0;
    v193 = (_BYTE *)(v181 + dword_10B54C);
    v180 = 0;
    v196 = (unsigned int *)(v65 + 64);
    while ( 2 )
    {
      sub_11F74C(1, dword_10B554, v180, v94);
      sub_100200(v209, 0, 0x40u);
      v225 = 1.0;
      v219 = v92;
      v218 = 8;
      v214 = 15;
      v95 = (float *)&v224;
      do
        *v95++ = v92;
      while ( &v225 != v95 );
      if ( v179 )
      {
        v207 = 1792;
        HIWORD(v206) = 2048;
        if ( v180 )
        {
          if ( v180 == 1 )
          {
            LOWORD(v206) = 2048;
            v96 = 8;
            v221 = 4;
            v222 = 4;
            v97 = 12;
            v216 = 0x800000009LL;
            v217 = 12;
            v223 = 8;
            v194 = 4096;
          }
          else
          {
            v154 = (*(_BYTE *)off_10BB8C & 0xC0) == 192;
            v221 = 6;
            v222 = 6;
            if ( v154 )
              v155 = 768;
            else
              v155 = 960;
            v97 = 12;
            v223 = 6;
            v216 = 0x900000009LL;
            LOWORD(v206) = v155;
            v217 = 12;
            v194 = 0;
            v96 = 8;
          }
        }
        else
        {
          v97 = 14;
          v221 = 4;
          v222 = 4;
          v96 = 8;
          v216 = 0x90000000ELL;
          v217 = 14;
          LOWORD(v206) = 896;
          v223 = 8;
          v194 = 0x2000;
        }
      }
      else
      {
        v96 = 8;
        v216 = 0x80000000BLL;
        v97 = 12;
        v217 = 12;
        if ( v180 )
        {
          v206 = dword_10B558;
          v207 = 1280;
          if ( v180 == 2 )
            v206 = 83887360;
          v96 = 7;
          v97 = 11;
          v216 = 0x90000000ALL;
          v217 = 11;
          v218 = 7;
          v221 = 2;
          v222 = 2;
          v223 = 4;
          v194 = 0;
        }
        else
        {
          v221 = 0;
          v206 = dword_10BF00;
          v207 = 2431;
          v223 = 8;
          v222 = 6;
          v194 = 4096;
        }
      }
      v98 = -100;
      v99 = v196 - 17;
      for ( j = 0; j != 32; ++j )
      {
        v101 = v99[1];
        ++v99;
        if ( (int)((v101 >> 8) & 0xF) < v96 )
        {
          v102 = j <= 15 ? j : j - 32;
          if ( v98 < v102 )
            v98 = v102;
        }
      }
      v185 = 255;
      v184 = 255;
      v187 = 255;
      v199 = v65;
      v189 = 0;
      v190 = 0;
      v103 = v196;
      v104 = v197;
      v182 = v98 + 1;
      v105 = v11;
      v106 = v92;
      v107 = 0;
      v108 = -16;
      v195 = v98;
      v109 = v98 + 1;
      v110 = v97;
      v111 = 15;
      while ( 1 )
      {
        if ( v108 >= 0 )
        {
          v112 = *(v103 - 32);
          v178 = v108;
          v113 = v103 - 32;
          v114 = (v112 >> 8) & 0xF;
        }
        else
        {
          v112 = *v103;
          v178 = v108 + 32;
          v113 = v103;
          v114 = (*v103 >> 8) & 0xF;
        }
        if ( v114 > SHIDWORD(v111) )
          HIDWORD(v214) = v114;
        if ( v114 < (int)v111 )
          LODWORD(v214) = v114;
        if ( v114 == v110 && !v107 )
        {
          if ( *v193 )
          {
            sub_11F74C(1, dword_10B7D0, v180, v67);
          }
          else
          {
            v115 = dword_10B7C8;
            *v191 = (unsigned __int8)v112;
            *v193 = 1;
            sub_11F74C(1, v115, v67, v180);
          }
          v116 = *v191;
          v117 = sub_12754C(*v191);
          v118 = sub_127874(v117, HIDWORD(v117), 0, dword_10B7CC);
          v119 = sub_127BE4(v118);
          v106 = sub_11EAA0(v119) * 20.0;
          v187 = v178;
          v120 = sub_11E8E0((float)-v106 / 20.0);
          v121 = sub_127570((float)v116 * v120);
          v122 = math_round(v121, HIDWORD(v121));
          v105 = sub_127B54(v122, HIDWORD(v122));
          v104 = v105 | v194 | 0xFFC000;
          v107 = 1;
        }
        if ( (_DWORD)v216 == v114 && !v189 )
        {
          v184 = v178;
          v189 = 1;
        }
        if ( HIDWORD(v216) == v114 && !v190 )
        {
          v185 = v178;
          v190 = 1;
        }
        if ( v108 == v109 )
          *(_BYTE *)off_10B55C = *v113;
        ++v108;
        ++v103;
        if ( v108 == 16 )
          break;
        v111 = v214;
        v110 = v217;
      }
      v65 = v199;
      v197 = v104;
      v11 = v105;
      sub_11F74C(1, dword_10B7D8, HIDWORD(v214), v214);
      if ( v187 == 255 )
      {
        msg_parse(dword_10BF04, v123);
        msg_parse(dword_10BF08, 255);
        v11 = 100;
        v156 = v184;
        if ( v184 != 255 )
          goto LABEL_130;
LABEL_167:
        msg_parse(dword_10BF0C, v156);
        goto LABEL_130;
      }
      if ( v184 != 255 && v185 != 255 )
        goto LABEL_80;
      msg_parse(dword_10BB90, v123);
      v156 = v184;
      if ( v184 == 255 )
        goto LABEL_167;
LABEL_130:
      if ( v185 == 255 )
        msg_parse(dword_10BB94, 255);
LABEL_80:
      if ( v187 > 15 )
        v187 -= 32;
      if ( v184 > 15 )
        v184 -= 32;
      if ( v185 > 15 )
        v185 -= 32;
      sub_11F74C(1, dword_10B7DC, v187, v217);
      v124 = v218;
      if ( SHIDWORD(v214) >= v218 )
      {
        v125 = dword_10B7E0;
        v126 = (float *)&v211[2 * v218 + 74];
        do
        {
          v127 = (float)(v217 - v124) * v225;
          *v126++ = v127;
          sub_11F74C(1, v125, v124++, (int)(float)(v127 * v26));
        }
        while ( SHIDWORD(v214) >= v124 );
      }
      sub_105FD0(v104, (int)v211, (__int16 *)&v206, 0, v198, v180, 0, v67);
      v128 = v216;
      v129 = (__int16)v211[v217];
      v130 = (__int16)v211[(_DWORD)v216 + 16];
      v131 = (__int16)v211[HIDWORD(v216) + 32];
      if ( (int)v216 <= SHIDWORD(v214) )
      {
        HIDWORD(v128) = &v211[v216 - 1];
        v161 = (float *)&v209[v216];
        do
        {
          v162 = *(__int16 *)(HIDWORD(v128) + 2);
          HIDWORD(v128) += 2;
          sub_104B60(v162, v129, (int)v211);
          v163 = HIDWORD(v214);
          *v161++ = v212;
          LODWORD(v128) = v128 + 1;
        }
        while ( v163 >= (int)v128 );
        v132 = (float)(v184 - v187) - *(float *)&v209[v216];
        sub_11F74C(1, dword_10BEF4, (int)(float)(v132 * v26), v184 - v187);
        crypto_gain_clamp(v132, v11, (int)v211);
        sub_11F74C(1, dword_10BEF8, v187, v11);
        v128 = v216;
      }
      else
      {
        v132 = v92;
      }
      if ( SHIDWORD(v128) < (int)v128 )
      {
        v157 = &v211[HIDWORD(v128) + 16];
        LODWORD(v128) = &v209[HIDWORD(v128)];
        do
        {
          v158 = *v157++;
          sub_11F74C(1, dword_10BEEC, HIDWORD(v128), v158);
          sub_104B60(v158, v130, (int)v211);
          v159 = HIDWORD(v216);
          *(float *)v128 = v212;
          LODWORD(v128) = v128 + 4;
          v160 = (float *)&v209[v159];
          v133 = (float)(v185 - v184) - *v160;
          ++HIDWORD(v128);
          sub_11F74C(1, dword_10BEF0, (int)(float)(v133 * v26), v160);
        }
        while ( (int)v216 > SHIDWORD(v128) );
        HIDWORD(v128) = HIDWORD(v216);
      }
      else
      {
        v133 = v92;
      }
      LODWORD(v128) = v218;
      if ( v218 < SHIDWORD(v128) )
      {
        v134 = dword_10B7E4;
        HIDWORD(v128) = &v211[v218 + 32];
        v135 = (float *)&v209[v218];
        do
        {
          v136 = (__int16)*(_WORD *)HIDWORD(v128);
          HIDWORD(v128) += 2;
          sub_11F74C(1, v134, v128, v136);
          sub_104B60(v136, v131, (int)v211);
          v137 = HIDWORD(v216);
          *v135++ = v212;
          LODWORD(v128) = v128 + 1;
        }
        while ( v137 > (int)v128 );
      }
      v138 = dword_10B7E8;
      v139 = v92;
      v140 = 15;
      while ( 2 )
      {
        while ( 2 )
        {
          if ( v140 < 0 )
            v146 = v188 + 32;
          else
            v146 = v188;
          v147 = v146 + v140;
          v148 = (*(_DWORD *)(v65 + 4 * (v146 + v140)) >> 8) & 0xF;
          v149 = *(float *)&v209[v148];
          v215 = v148;
          v150 = (unsigned int *)(v65 + 4 * (v146 + v140));
          if ( v195 < v140 )
          {
            if ( v148 > 9 )
              v141 = v92;
            else
              v141 = v219;
            if ( (int)v216 <= v148 )
            {
              v93 = v140 - v187;
              v151 = (float)((float)((float)((float)(v140 - v187) - v149) + v106) + v141) + *((float *)&v220 + v148);
              sub_11F74C(1, dword_10BB74, v140, v187);
              sub_11F74C(1, dword_10BB78, -100 * v187 + 100 * v140, (int)(float)(v149 * v26));
              crypto_gain_clamp(v151, v11, (int)v211);
            }
            else
            {
              if ( SHIDWORD(v216) > v148 )
              {
                v93 = v140 - v185;
                v142 = (float)((float)((float)((float)((float)((float)(v140 - v185) - v149) + v133) + v132) + v106)
                             + v141)
                     + *((float *)&v220 + v148);
                sub_11F74C(1, dword_10BB6C, v140, v185);
                sub_11F74C(1, dword_10BB70, -100 * v185 + 100 * v140, (int)(float)(v149 * v26));
              }
              else
              {
                v93 = v140 - v184;
                v142 = (float)((float)((float)((float)((float)(v140 - v184) - v149) + v132) + v106) + v141)
                     + *((float *)&v220 + v148);
                sub_11F74C(1, dword_10BB60, v140, v184);
                sub_11F74C(1, dword_10BB64, -100 * v184 + 100 * v140, (int)(float)(v149 * v26));
              }
              crypto_gain_clamp(v142, v11, (int)v211);
            }
            sub_11F74C(1, v138, v147, v148);
            if ( v140 == v182 )
            {
              sub_11F74C(1, dword_10BB84, v143, v182);
              sub_104B60(v213, *(unsigned __int8 *)off_10BB88, (int)v211);
              v139 = v212;
            }
          }
          else
          {
            sub_11F74C(1, dword_10BB68, v140, v195);
            crypto_gain_clamp(v139, *(unsigned __int8 *)(v65 + 4 * v147), (int)v211);
          }
          sub_11F74C(1, v138, v147, v148);
          *(_BYTE *)v150 = v213;
          if ( v179 || v180 || v148 != 15 )
            goto LABEL_108;
          sub_11F74C(1, dword_10BB7C, v145, 0);
          sub_105FD0(*v150, (int)v211, (__int16 *)&v206, 1, v198, 0, 0, 0);
          sub_104B60(v211[15], v129, (int)v211);
          v152 = v212;
          sub_11F74C(1, dword_10BB78, 100 * v93, (int)(float)(v212 * v26));
          v200 = sub_127570((float)v93 - v152);
          if ( !sub_127B40(v200, HIDWORD(v200), dword_10BB50, dword_10BB54)
            && !sub_127B04(v200, HIDWORD(v200), dword_10BB58, dword_10BB5C) )
          {
            sub_11F74C(1, dword_10BEFC, (int)(float)((float)((float)v93 - v152) * v26), v153);
LABEL_108:
            if ( --v140 == -17 )
              goto LABEL_120;
            continue;
          }
          break;
        }
        crypto_gain_clamp((float)v93 - v152, v213, (int)v211);
        --v140;
        sub_11F74C(1, v138, v147, 15);
        *(_BYTE *)v150 = v213;
        if ( v140 != -17 )
          continue;
        break;
      }
LABEL_120:
      v188 += 32;
      v191 += 7;
      v196 += 32;
      v94 = v180 + 1;
      v154 = v180++ == 2;
      ++v193;
      if ( !v154 )
        continue;
      break;
    }
    msg_parse(dword_10BB80, v144);
LABEL_10:
    v192 += 4;
  }
  while ( v192 != a5 + 28 );
  v35 = off_10B21C;
  v36 = dword_10B230;
  v37 = dword_10B234;
  v38 = dword_10B238;
  v39 = dword_10B23C;
  v40 = dword_10B250;
  *(_DWORD *)off_10B21C |= 0x400u;
  *v35 &= ~0x400u;
  msg_parse(v36, v33);
  sub_102ADC(0);
  v41 = dword_10B240;
  v42 = (int *)v210;
  for ( k = 0; k != 3; ++k )
  {
    if ( k )
    {
      if ( k != 1 )
      {
        v44 = v41;
        goto LABEL_15;
      }
      v44 = v39;
      v54 = v40;
    }
    else
    {
      v44 = v37;
      v54 = v38;
    }
    v55 = (unsigned int *)(v54 + 4);
    v56 = &v209[16 * k + 16];
    v57 = (unsigned int *)(v54 + 484);
    do
    {
      v58 = *v56++;
      *v55 = *v55 & 0xFFF1FFFF | (v58 << 17);
      v55 += 8;
    }
    while ( v57 != v55 );
LABEL_15:
    v45 = (unsigned int *)(v44 + 4);
    v46 = (unsigned int *)(v44 + 484);
    v47 = v42;
    do
    {
      v48 = *v47++;
      *v45 = *v45 & 0xFFF1FFFF | (v48 << 17);
      v45 += 8;
    }
    while ( v46 != v45 );
    v42 += 16;
  }
  sub_102B40(0);
  v49 = off_10B244;
  v50 = dword_10B248;
  v51 = *(_DWORD *)off_10B218 & 0xFFFFFFFE | v202;
  *(_DWORD *)off_10B218 = v51;
  sub_11F74C(1, v50, (*v49 >> 21) & 7, v51);
  return msg_parse(dword_10B24C, v52);
}

