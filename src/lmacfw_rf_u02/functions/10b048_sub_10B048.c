#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))


extern uint32_t dword_10B234;
extern uint32_t dword_10B238;
extern uint32_t dword_10B23C;
extern uint32_t dword_10B240;
extern uint32_t dword_10B250;
extern uint32_t dword_10B540;
extern uint32_t dword_10B548;
extern uint32_t dword_10B54C;
extern uint32_t dword_10B558;
extern uint32_t dword_10B7CC;
extern uint32_t dword_10BB50;
extern uint32_t dword_10BB58;
extern uint32_t dword_10BF00;
extern uint32_t dword_10BF24;
extern float flt_10B220;
extern float flt_10B550;
extern uint32_t off_10B218;
extern uint32_t off_10B21C;
extern uint32_t off_10B244;
extern uint32_t off_10B55C;
extern uint32_t off_10B560;
extern uint32_t off_10B564;
extern uint32_t off_10B7D4;
extern uint32_t off_10BB88;
extern uint32_t off_10BB8C;
extern uint32_t off_10BF10;
extern uint32_t off_10BF1C;

// sub_10B048 @ 0x10b048, size 3748 bytes
int  sub_10B048(int a1, int a2, int a3, int a4, uint16_t *a5, int a6, int a7)
{
  int v7; // s26
  int v8; // r8
  int v9; // r1
  int v10; // r10
  int v11; // r9
  int *v12; // r7
  int v13; // lr
  int v14; // r12
  int i; // r6
  int v16; // r0
  unsigned int *v17; // r2
  int *v18; // r4
  unsigned int *v19; // r0
  unsigned int v20; // r3
  uint32_t *v21; // r4
  float v22; // s18
  int v23; // r7
  uint32_t *v24; // r3
  int v25; // r5
  int v26; // r4
  int v27; // r7
  int v28; // r9
  int v29; // r0
  int *v30; // r10
  int k; // r1
  int v32; // r12
  unsigned int *v33; // r2
  unsigned int *v34; // r8
  int *v35; // r12
  int v36; // t1
  uint32_t *v37; // r0
  int v39; // r8
  unsigned int *v40; // r2
  int *v41; // lr
  unsigned int *v42; // r8
  int v43; // t1
  int v44; // r5
  unsigned int *v45; // r2
  int *v46; // r4
  unsigned int *v47; // r5
  unsigned int v48; // r3
  unsigned int v49; // r4
  int *v50; // r9
  int v51; // r11
  int v52; // s25
  int *v53; // r12
  int v54; // r0
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  int v60; // r1
  int v61; // r11
  unsigned int v62; // r5
  unsigned int *v63; // r11
  unsigned int v64; // t1
  int v65; // r6
  int v66; // r10
  int v67; // r4
  int v68; // r5
  unsigned int v69; // t1
  float v70; // s22
  int v71; // s19
  float *v72; // r3
  int v73; // r4
  int v74; // r1
  int v75; // r8
  int *v76; // r0
  int j; // r3
  unsigned int v78; // t1
  int v79; // r2
  int *v80; // r6
  unsigned int v81; // r11
  int v82; // lr
  float v83; // s20
  int v84; // r12
  int v85; // r5
  int v86; // r9
  int v87; // r0
  uint64_t v88; // kr00_8
  unsigned int v89; // r3
  int *v90; // r8
  int v91; // r4
  int v92; // r11
  uint64_t v93; // r0
  uint64_t v94; // r2
  uint64_t v95; // r0
  unsigned int v96; // r0
  float v97; // r0
  uint64_t v98; // r0
  uint64_t v99; // r0
  int v100; // r4
  float *v101; // r5
  float v102; // s15
  uint64_t v103; // r4
  int v104; // s27
  int v105; // s17
  int v106; // r7
  float v107; // s21
  float v108; // s23
  float *v109; // r6
  int v110; // t1
  int v111; // r3
  float v112; // s24
  int v113; // r4
  float v114; // s15
  float v115; // s17
  int v116; // r3
  int v117; // r5
  int v118; // r6
  float v119; // s16
  unsigned int *v120; // r7
  float v121; // s17
  float v122; // s14
  int v123; // zf
  uint16_t v124; // r0
  int v125; // r3
  uint16_t *v126; // r6
  int v127; // t1
  int v128; // r3
  float *v129; // r6
  int v130; // t1
  int v131; // r3
  int *v132; // r4
  unsigned int v133; // r0
  unsigned int *v134; // r4
  unsigned int v135; // t1
  int v136; // r2
  int v137; // r10
  int v138; // r3
  int v139; // r5
  unsigned int v140; // t1
  int v141; // r0
  int v142; // r10
  int v143; // r4
  unsigned int v144; // r0
  int a8; // [sp+Ch] [bp-588h]
  int v146; // [sp+24h] [bp-570h]
  int v147; // [sp+24h] [bp-570h]
  int a4a; // [sp+28h] [bp-56Ch]
  int v149; // [sp+2Ch] [bp-568h]
  int v150; // [sp+30h] [bp-564h]
  int v151; // [sp+30h] [bp-564h]
  uint32_t *v152; // [sp+34h] [bp-560h]
  int v153; // [sp+34h] [bp-560h]
  int v154; // [sp+38h] [bp-55Ch]
  int v155; // [sp+38h] [bp-55Ch]
  int v156; // [sp+3Ch] [bp-558h]
  int v157; // [sp+40h] [bp-554h]
  int v158; // [sp+44h] [bp-550h]
  int v159; // [sp+48h] [bp-54Ch]
  int *v160; // [sp+4Ch] [bp-548h]
  uint16_t *v161; // [sp+50h] [bp-544h]
  uint8_t *v162; // [sp+54h] [bp-540h]
  int v163; // [sp+58h] [bp-53Ch]
  int v164; // [sp+5Ch] [bp-538h]
  int *v165; // [sp+64h] [bp-530h]
  unsigned int v166; // [sp+68h] [bp-52Ch]
  int v167; // [sp+6Ch] [bp-528h]
  int *v168; // [sp+70h] [bp-524h]
  uint64_t v169; // [sp+70h] [bp-524h]
  int v171; // [sp+7Ch] [bp-518h]
  uint32_t *v173; // [sp+88h] [bp-50Ch]
  uint16_t a3a[2]; // [sp+94h] [bp-500h] BYREF
  uint16_t v176; // [sp+98h] [bp-4FCh]
  uint32_t v177[6]; // [sp+9Ch] [bp-4F8h] BYREF
  int result[48]; // [sp+B4h] [bp-4E0h] BYREF
  uint8_t v179[192]; // [sp+174h] [bp-420h] BYREF
  uint16_t v180[48]; // [sp+234h] [bp-360h] BYREF
  float v181; // [sp+294h] [bp-300h]
  uint8_t v182; // [sp+29Ch] [bp-2F8h]
  uint64_t v183; // [sp+2A0h] [bp-2F4h]
  int v184; // [sp+2A8h] [bp-2ECh]
  uint64_t v185; // [sp+2ACh] [bp-2E8h]
  int v186; // [sp+2B4h] [bp-2E0h]
  int v187; // [sp+2B8h] [bp-2DCh]
  float v188; // [sp+2BCh] [bp-2D8h]
  int v189; // [sp+2C8h] [bp-2CCh]
  int v190; // [sp+2CCh] [bp-2C8h]
  int v191; // [sp+2D0h] [bp-2C4h]
  int v192; // [sp+2D4h] [bp-2C0h]
  char v193; // [sp+2E4h] [bp-2B0h] BYREF
  float v194; // [sp+308h] [bp-28Ch] BYREF
  uint16_t v195[2]; // [sp+30Ch] [bp-288h] BYREF
  uint16_t v196; // [sp+310h] [bp-284h]
  int v197; // [sp+580h] [bp-14h]
  int v198; // [sp+584h] [bp-10h]
  int v199; // [sp+5F8h] [bp+64h]
  int v200; // [sp+5FCh] [bp+68h]
  int a11; // [sp+600h] [bp+6Ch]

  sub_11F504(aMiscDpdCalibSi);
  v8 = dword_10B234;
  v9 = *(uint32_t *)off_10B218;
  v10 = dword_10B23C;
  v11 = dword_10B250;
  *(uint32_t *)off_10B218 &= ~1u;
  v171 = v9 & 1;
  v12 = (int *)v179;
  sub_102ADC(0);
  v13 = dword_10B238;
  v14 = dword_10B240;
  for ( i = 0; i != 3; ++i )
  {
    if ( i )
    {
      if ( i != 1 )
      {
        v16 = v14;
        goto LABEL_5;
      }
      v16 = v10;
      v44 = v11;
    }
    else
    {
      v16 = v8;
      v44 = v13;
    }
    v45 = (unsigned int *)(v44 + 4);
    v46 = &result[16 * i + 16];
    v47 = (unsigned int *)(v44 + 516);
    do
    {
      v48 = *v45;
      *v45 = *v45 & 0xFFF1FFFF | 0x20000;
      v45 += 8;
      *v46++ = (v48 >> 17) & 7;
    }
    while ( v45 != v47 );
LABEL_5:
    v17 = (unsigned int *)(v16 + 4);
    v18 = v12;
    v19 = (unsigned int *)(v16 + 516);
    do
    {
      v20 = *v17;
      *v17 = *v17 & 0xFFF1FFFF | 0x20000;
      v17 += 8;
      *v18++ = (v20 >> 17) & 7;
    }
    while ( v19 != v17 );
    v12 += 16;
  }
  v21 = (uint32_t *)off_10B21C;
  v22 = flt_10B220;
  sub_102B40(0);
  sub_11F74C(1, aTrigger);
  *v21 |= 0x400u;
  *v21 &= ~0x400u;
  sub_11F504(aDpdStart);
  sub_11F74C(1, aDpdCal);
  v161 = a5;
  v173 = v21;
  do
  {
    v23 = *((uint8_t *)v161 + 4);
    if ( v23 != 1 )
      goto LABEL_10;
    v49 = *v161;
    sub_11F74C(1, "*********************dpd  freq= [%d] *********************\n", v49);
    if ( v49 <= 0x1388 )
    {
      v50 = (int *)off_10B560;
      v51 = a2;
      v150 = 0;
      v52 = 0;
      v167 = 0;
      v146 = 0;
      v23 = 0;
      a4a = 0;
      v152 = v177;
      goto LABEL_29;
    }
    v141 = sub_102968(v49);
    v142 = dword_10BF24;
    v143 = 0;
    a4a = (uint8_t)(v141 + 1);
    v52 = a4a;
    v50 = (int *)(off_10BF10 + 384 * v141);
    sub_11F504(aCapacitanceCal);
    while ( 1 )
    {
      *(uint32_t *)v195 = 0;
      v196 = 0;
      v144 = v142 | (v143 << 12);
      if ( v143 != 1 )
        break;
      v190 = 3;
      v195[0] = 2048;
      sub_105FD0(v144, (int)v180, v195, 0, 1, 1, 1, a4a);
LABEL_177:
      ++v143;
    }
    v190 = 3;
    v195[0] = 2048;
    sub_105FD0(v144, (int)v180, v195, 0, 1, v143, 1, a4a);
    if ( v143 != 2 )
      goto LABEL_177;
    v167 = 1;
    v51 = a2 + 1264 * a4a;
    v150 = 3 * a4a;
    v146 = 3 * a4a;
    v152 = &v177[a4a];
LABEL_29:
    v53 = (int *)off_10B564;
    *v173 |= 0x400u;
    v54 = *v53;
    v55 = v53[1];
    v56 = v53[2];
    v57 = v53[3];
    v53 += 4;
    *v173 &= ~0x400u;
    v177[0] = v54;
    v177[1] = v55;
    v177[2] = v56;
    v177[3] = v57;
    v58 = v53[1];
    v59 = v51 + 16;
    v177[4] = *v53;
    v177[5] = v58;
    v60 = v51;
    v61 = v51 - 4;
    sub_109D40((uint32_t *)a1, v60, v59, a4a, (int)v177, a6, a7, a8, v199, v200, a11);
    sub_100560(0);
    v64 = *(uint32_t *)(v61 + 4);
    v63 = (unsigned int *)(v61 + 4);
    v62 = v64;
    v65 = 0;
    if ( v64 )
    {
LABEL_30:
      if ( v23 == 1 )
      {
        if ( v65 )
        {
          if ( v65 == 1 )
            v66 = 64;
          else
            v66 = 96;
          if ( v65 == 1 )
            v67 = 32;
          else
            v67 = 64;
        }
        else
        {
          v66 = 32;
          v67 = 0;
        }
      }
      else
      {
        if ( v65 == 1 )
        {
          sub_11F74C(1, a24gTable1DontN_0);
          *(uint32_t *)off_10BF1C |= 0x8000u;
          goto LABEL_35;
        }
        v66 = 64;
        v67 = 32;
      }
      v68 = HIWORD(v62) & 1;
      *(uint8_t *)(a3 + v146 + v65) = v68;
      sub_11F74C(1, "table [%d] dpd_ok=%d\n", v65, v68);
      sub_105494(*v63, (int)v195, v23);
      sub_11F74C(1, "ana_pwr_max=%x\n", v197);
      sub_11F74C(1, "ana_pwr_min=%x\n", v198);
      if ( v68 && v67 < v66 )
      {
        v132 = &v50[v67 - 1];
        v135 = v132[1];
        v134 = (unsigned int *)(v132 + 1);
        v133 = v135;
        v136 = (v135 >> 8) & 0xF;
        v137 = (int)&v50[v66 - 1];
        v138 = v68;
        v139 = 15 - v136;
        if ( !v23 )
          goto LABEL_152;
        while ( 1 )
        {
          if ( v136 == 7 )
            v139 = 5;
LABEL_155:
          if ( v198 <= v136 && v197 >= v136 )
          {
            if ( v136 > 8 || *v152 || v65 != 1 )
            {
              *v134 = v133 & 0xFF3F7FFF | (v139 << 24);
            }
            else
            {
              *v134 = v133 | 0xC08000;
              v155 = v138;
              sub_11F74C(1, "table 1 index %d bypass\n", v136);
              v138 = v155;
            }
          }
          if ( (unsigned int *)v137 == v134 )
            break;
          v140 = v134[1];
          ++v134;
          v133 = v140;
          v136 = (v140 >> 8) & 0xF;
          v139 = 15 - v136;
          if ( !v23 )
          {
LABEL_152:
            if ( v136 == 4 )
            {
              v139 = v138;
            }
            else if ( v136 == 7 )
            {
              v139 = 0;
            }
            goto LABEL_155;
          }
        }
      }
      if ( v65 != 2 )
        goto LABEL_35;
    }
    else
    {
      while ( 1 )
      {
        sub_11F74C(1, "table [%d] dont need change\n", v65);
        if ( v65 == 2 )
          break;
LABEL_35:
        v69 = v63[1];
        ++v63;
        v62 = v69;
        ++v65;
        if ( v69 )
          goto LABEL_30;
      }
    }
    v166 = dword_10B540;
    sub_11F504(aPwrCalStart);
    v70 = flt_10B550;
    v160 = (int *)(dword_10B548 + 4 * v52);
    v71 = 0;
    v157 = 0;
    v162 = (uint8_t *)(v150 + dword_10B54C);
    v149 = 0;
    v165 = v50 + 16;
    while ( 2 )
    {
      sub_11F74C(
        1,
        "/***************************************cal tx_gain_table=%d********************************/\n",
        v149);
      sub_100200(result, 0, 0x40u);
      v194 = 1.0;
      v188 = v70;
      v187 = 8;
      v183 = 15;
      v72 = (float *)&v193;
      do
        *v72++ = v70;
      while ( &v194 != v72 );
      if ( a4a )
      {
        v176 = 1792;
        a3a[1] = 2048;
        if ( v149 )
        {
          if ( v149 == 1 )
          {
            a3a[0] = 2048;
            v73 = 8;
            v190 = 4;
            v191 = 4;
            v74 = 12;
            v185 = 0x800000009LL;
            v186 = 12;
            v192 = 8;
            v163 = 4096;
          }
          else
          {
            v123 = (*(uint8_t *)off_10BB8C & 0xC0) == 192;
            v190 = 6;
            v191 = 6;
            if ( v123 )
              v124 = 768;
            else
              v124 = 960;
            v74 = 12;
            v192 = 6;
            v185 = 0x900000009LL;
            a3a[0] = v124;
            v186 = 12;
            v163 = 0;
            v73 = 8;
          }
        }
        else
        {
          v74 = 14;
          v190 = 4;
          v191 = 4;
          v73 = 8;
          v185 = 0x90000000ELL;
          v186 = 14;
          a3a[0] = 896;
          v192 = 8;
          v163 = 0x2000;
        }
      }
      else
      {
        v73 = 8;
        v185 = 0x80000000BLL;
        v74 = 12;
        v186 = 12;
        if ( v149 )
        {
          *(uint32_t *)a3a = dword_10B558;
          v176 = 1280;
          if ( v149 == 2 )
            *(uint32_t *)a3a = 83887360;
          v73 = 7;
          v74 = 11;
          v185 = 0x90000000ALL;
          v186 = 11;
          v187 = 7;
          v190 = 2;
          v191 = 2;
          v192 = 4;
          v163 = 0;
        }
        else
        {
          v190 = 0;
          *(uint32_t *)a3a = dword_10BF00;
          v176 = 2431;
          v192 = 8;
          v191 = 6;
          v163 = 4096;
        }
      }
      v75 = -100;
      v76 = v165 - 17;
      for ( j = 0; j != 32; ++j )
      {
        v78 = v76[1];
        ++v76;
        if ( (int)((v78 >> 8) & 0xF) < v73 )
        {
          v79 = j <= 15 ? j : j - 32;
          if ( v75 < v79 )
            v75 = v79;
        }
      }
      v154 = 255;
      v153 = 255;
      v156 = 255;
      v168 = v50;
      v158 = 0;
      v159 = 0;
      v80 = v165;
      v81 = v166;
      v151 = v75 + 1;
      v82 = v7;
      v83 = v70;
      v84 = 0;
      v85 = -16;
      v164 = v75;
      v86 = v75 + 1;
      v87 = v74;
      v88 = 15;
      while ( 1 )
      {
        if ( v85 >= 0 )
        {
          v89 = *(v80 - 32);
          v147 = v85;
          v90 = v80 - 32;
          v91 = (v89 >> 8) & 0xF;
        }
        else
        {
          v89 = *v80;
          v147 = v85 + 32;
          v90 = v80;
          v91 = ((unsigned int)*v80 >> 8) & 0xF;
        }
        if ( v91 > SHIDWORD(v88) )
          HIDWORD(v183) = v91;
        if ( v91 < (int)v88 )
          LODWORD(v183) = v91;
        if ( v91 == v87 && !v84 )
        {
          if ( *v162 )
          {
            sub_11F74C(1, "dig_pwr_ini[%d][%d]=%x ", v149, v52, *v160);
          }
          else
          {
            *v160 = (uint8_t)v89;
            *v162 = 1;
            sub_11F74C(1, "ch[%d] table[%d] first_value=%x ", v52, v149, (uint8_t)v89);
          }
          v92 = *v160;
          v93 = sub_12754C(*v160);
          LODWORD(v94) = 0;
          HIDWORD(v94) = dword_10B7CC;
          v95 = sub_127874(v93, v94);
          v96 = sub_127BE4(v95);
          v83 = COERCE_FLOAT(sub_11EAA0(v96)) * 20.0;
          v156 = v147;
          v97 = COERCE_FLOAT(sub_11E8E0(COERCE_INT((float)-v83 / 20.0)));
          v98 = sub_127570(COERCE_UNSIGNED_INT((float)v92 * v97));
          v99 = sub_127194(v98);
          v82 = sub_127B54(v99);
          v81 = v82 | v163 | 0xFFC000;
          v84 = 1;
        }
        if ( (uint32_t)v185 == v91 && !v158 )
        {
          v153 = v147;
          v158 = 1;
        }
        if ( HIDWORD(v185) == v91 && !v159 )
        {
          v154 = v147;
          v159 = 1;
        }
        if ( v85 == v86 )
          *(uint8_t *)off_10B55C = *v90;
        ++v85;
        ++v80;
        if ( v85 == 16 )
          break;
        v88 = v183;
        v87 = v186;
      }
      v50 = v168;
      v166 = v81;
      v7 = v82;
      sub_11F74C(1, aAnaMaxIndexXAn, HIDWORD(v183), (uint32_t)v183, v164, *(uint8_t *)off_10B7D4);
      if ( v156 == 255 )
      {
        sub_11F504(aWarningNeedCha);
        sub_11F504("base_index=%d\n", 255);
        v7 = 100;
        v125 = v153;
        if ( v153 != 255 )
          goto LABEL_130;
LABEL_167:
        sub_11F504("base_second_index=%d\n", v125);
        goto LABEL_130;
      }
      if ( v153 != 255 && v154 != 255 )
        goto LABEL_80;
      sub_11F504(aWarningNeedCha);
      v125 = v153;
      if ( v153 == 255 )
        goto LABEL_167;
LABEL_130:
      if ( v154 == 255 )
        sub_11F504("base_third_index=%d\n", 255);
LABEL_80:
      if ( v156 > 15 )
        v156 -= 32;
      if ( v153 > 15 )
        v153 -= 32;
      if ( v154 > 15 )
        v154 -= 32;
      sub_11F74C(
        1,
        "base_index=%d ana_index=%x dig_pwr=%x pwr_stage_coin_index0=%x base_second_index=%2d pwr_stage_coin_index1=%x ba"
        "se_third_index=%2d\n",
        v156,
        v186,
        v7,
        (uint32_t)v185,
        v153,
        HIDWORD(v185),
        v154);
      v100 = v187;
      if ( SHIDWORD(v183) >= v187 )
      {
        v101 = (float *)&v180[2 * v187 + 74];
        do
        {
          v102 = (float)(v186 - v100) * v194;
          *v101++ = v102;
          sub_11F74C(1, "ana_index[%x] reduce_dig_i*100=%d \n", v100++, (int)(float)(v102 * v22));
        }
        while ( SHIDWORD(v183) >= v100 );
      }
      sub_105FD0(v81, (int)v180, a3a, 0, v167, v149, 0, v52);
      v103 = v185;
      v104 = (uint16_t)v180[v186];
      v105 = (uint16_t)v180[(uint32_t)v185 + 16];
      v106 = (uint16_t)v180[HIDWORD(v185) + 32];
      if ( (int)v185 <= SHIDWORD(v183) )
      {
        HIDWORD(v103) = &v180[v185 - 1];
        v129 = (float *)&result[v185];
        do
        {
          v130 = *(uint16_t *)(HIDWORD(v103) + 2);
          HIDWORD(v103) += 2;
          sub_104B60(v130, v104, (int)v180);
          v131 = HIDWORD(v183);
          *v129++ = v181;
          LODWORD(v103) = v103 + 1;
        }
        while ( v131 >= (int)v103 );
        v107 = (float)(v153 - v156) - *(float *)&result[v185];
        sub_11F74C(1, "stage_pwr_diff0*100= %d\n", (int)(float)(v107 * v22));
        sub_104C08(v107, v7, (int)v180);
        sub_11F74C(1, "base_index=%d dig_pwr=%x base_second_index=%d\n", v156, v7, v153);
        v103 = v185;
      }
      else
      {
        v107 = v70;
      }
      if ( SHIDWORD(v103) < (int)v103 )
      {
        v126 = &v180[HIDWORD(v103) + 16];
        LODWORD(v103) = &result[HIDWORD(v103)];
        do
        {
          v127 = *v126++;
          sub_11F74C(1, "pwr_amp_back[1][%d]=%d ", HIDWORD(v103), v127);
          sub_104B60(v127, v105, (int)v180);
          v128 = HIDWORD(v185);
          *(float *)v103 = v181;
          LODWORD(v103) = v103 + 4;
          v108 = (float)(v154 - v153) - *(float *)&result[v128];
          ++HIDWORD(v103);
          sub_11F74C(1, "stage_pwr_diff1*100= %d\n", (int)(float)(v108 * v22));
        }
        while ( (int)v185 > SHIDWORD(v103) );
        HIDWORD(v103) = HIDWORD(v185);
      }
      else
      {
        v108 = v70;
      }
      LODWORD(v103) = v187;
      if ( v187 < SHIDWORD(v103) )
      {
        HIDWORD(v103) = &v180[v187 + 32];
        v109 = (float *)&result[v187];
        do
        {
          v110 = (uint16_t)*(uint16_t *)HIDWORD(v103);
          HIDWORD(v103) += 2;
          sub_11F74C(1, "pwr_amp_back[2][%d]=%d ", (uint32_t)v103, v110);
          sub_104B60(v110, v106, (int)v180);
          v111 = HIDWORD(v185);
          *v109++ = v181;
          LODWORD(v103) = v103 + 1;
        }
        while ( v111 > (int)v103 );
      }
      v112 = v70;
      v113 = 15;
      while ( 2 )
      {
        while ( 2 )
        {
          if ( v113 < 0 )
            v116 = v157 + 32;
          else
            v116 = v157;
          v117 = v116 + v113;
          v118 = ((unsigned int)v50[v116 + v113] >> 8) & 0xF;
          v119 = *(float *)&result[v118];
          v184 = v118;
          v120 = (unsigned int *)&v50[v116 + v113];
          if ( v164 < v113 )
          {
            if ( v118 > 9 )
              v114 = v70;
            else
              v114 = v188;
            if ( (int)v185 <= v118 )
            {
              v71 = v113 - v156;
              v121 = (float)((float)((float)((float)(v113 - v156) - v119) + v83) + v114) + *((float *)&v189 + v118);
              sub_11F74C(1, "tx_gain_map_idx=%d base_index=%d ", v113, v156);
              sub_11F74C(
                1,
                "pwr_th*100=%-5d pwr_act*100=%-5d ",
                -100 * v156 + 100 * v113,
                (int)(float)(v119 * v22));
              sub_104C08(v121, v7, (int)v180);
            }
            else
            {
              if ( SHIDWORD(v185) > v118 )
              {
                v71 = v113 - v154;
                v115 = (float)((float)((float)((float)((float)((float)(v113 - v154) - v119) + v108) + v107) + v83) + v114)
                     + *((float *)&v189 + v118);
                sub_11F74C(1, "tx_gain_map_idx=%d base_third_index=%d ", v113, v154);
                sub_11F74C(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d stage_pwr_diff1*100=%-2d ",
                  -100 * v154 + 100 * v113,
                  (int)(float)(v119 * v22),
                  (int)(float)(v107 * v22),
                  (int)(float)(v108 * v22));
              }
              else
              {
                v71 = v113 - v153;
                v115 = (float)((float)((float)((float)((float)(v113 - v153) - v119) + v107) + v83) + v114)
                     + *((float *)&v189 + v118);
                sub_11F74C(1, "tx_gain_map_idx=%d base_second_index=%d ", v113, v153);
                sub_11F74C(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d ",
                  -100 * v153 + 100 * v113,
                  (int)(float)(v119 * v22),
                  (int)(float)(v107 * v22));
              }
              sub_104C08(v115, v7, (int)v180);
            }
            sub_11F74C(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, v118, v182);
            if ( v113 == v151 )
            {
              sub_11F74C(1, aMinDiffCal);
              sub_104B60(v182, *(uint8_t *)off_10BB88, (int)v180);
              v112 = v181;
            }
          }
          else
          {
            sub_11F74C(1, "tx_gain_map_idx=%d ", v113);
            sub_104C08(v112, LOBYTE(v50[v117]), (int)v180);
          }
          sub_11F74C(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, v118, v182);
          *(uint8_t *)v120 = v182;
          if ( a4a || v149 || v118 != 15 )
            goto LABEL_108;
          sub_11F74C(1, aPwrReCal);
          sub_105FD0(*v120, (int)v180, a3a, 1, v167, 0, 0, 0);
          sub_104B60(v180[15], v104, (int)v180);
          v122 = v181;
          sub_11F74C(1, "pwr_th*100=%-5d pwr_act*100=%-5d ", 100 * v71, (int)(float)(v181 * v22));
          v169 = sub_127570(COERCE_UNSIGNED_INT((float)v71 - v122));
          if ( !sub_127B40(v169, *(uint64_t *)&dword_10BB50)
            && !sub_127B04(v169, *(uint64_t *)&dword_10BB58) )
          {
            sub_11F74C(1, "pwr_diff*100=%d,dont need change\n", (int)(float)((float)((float)v71 - v122) * v22));
LABEL_108:
            if ( --v113 == -17 )
              goto LABEL_120;
            continue;
          }
          break;
        }
        sub_104C08((float)v71 - v122, v182, (int)v180);
        --v113;
        sub_11F74C(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, 15, v182);
        *(uint8_t *)v120 = v182;
        if ( v113 != -17 )
          continue;
        break;
      }
LABEL_120:
      v157 += 32;
      v160 += 7;
      v165 += 32;
      v123 = v149++ == 2;
      ++v162;
      if ( !v123 )
        continue;
      break;
    }
    sub_11F504(aPwrCalEnd);
LABEL_10:
    v161 += 4;
  }
  while ( v161 != a5 + 28 );
  v24 = (uint32_t *)off_10B21C;
  v25 = dword_10B234;
  v26 = dword_10B238;
  v27 = dword_10B23C;
  v28 = dword_10B250;
  *(uint32_t *)off_10B21C |= 0x400u;
  *v24 &= ~0x400u;
  sub_11F504(aDpdEnd);
  sub_102ADC(0);
  v29 = dword_10B240;
  v30 = (int *)v179;
  for ( k = 0; k != 3; ++k )
  {
    if ( k )
    {
      if ( k != 1 )
      {
        v32 = v29;
        goto LABEL_15;
      }
      v32 = v27;
      v39 = v28;
    }
    else
    {
      v32 = v25;
      v39 = v26;
    }
    v40 = (unsigned int *)(v39 + 4);
    v41 = &result[16 * k + 16];
    v42 = (unsigned int *)(v39 + 484);
    do
    {
      v43 = *v41++;
      *v40 = *v40 & 0xFFF1FFFF | (v43 << 17);
      v40 += 8;
    }
    while ( v42 != v40 );
LABEL_15:
    v33 = (unsigned int *)(v32 + 4);
    v34 = (unsigned int *)(v32 + 484);
    v35 = v30;
    do
    {
      v36 = *v35++;
      *v33 = *v33 & 0xFFF1FFFF | (v36 << 17);
      v33 += 8;
    }
    while ( v34 != v33 );
    v30 += 16;
  }
  sub_102B40(0);
  v37 = off_10B244;
  *(uint32_t *)off_10B218 = *(uint32_t *)off_10B218 & 0xFFFFFFFE | v171;
  sub_11F74C(1, "tia_aux_gbit000=%d\n", (*v37 >> 21) & 7);
  return sub_11F504(aMiscDpdCalibSi_0);
}
