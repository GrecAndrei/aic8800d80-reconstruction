// fwstruct annotate: 123ec0_sub_123EC0.c
// sub_123EC0 @ 0x123ec0, size 3268 bytes
int __fastcall sub_123EC0(unsigned int a1, int a2, unsigned __int8 *a3, int a4)
{
  int v4; // r9
  unsigned int v6; // r4
  int value; // r0
  int v10; // r1
  __int16 **v12; // r8
  int v13; // r3
  _BYTE *v14; // r5
  int v15; // r0
  _BYTE *v16; // r7
  int v17; // r6
  int v18; // r3
  char v19; // r7
  int v20; // r1
  unsigned int v21; // r2
  signed int v22; // r3
  unsigned int v23; // r8
  __int16 v24; // lr
  int v25; // r2
  int v26; // r3
  __int16 v27; // r1
  int v28; // r2
  int v29; // r3
  _BYTE *v30; // r0
  int v31; // r3
  int v32; // r11
  int v33; // r10
  unsigned __int8 *v34; // r9
  int v35; // r0
  int v36; // r2
  int v37; // r1
  int v38; // r7
  int v39; // s16
  _DWORD *v40; // r1
  int v41; // r3
  int v42; // r12
  _DWORD *v43; // r0
  int v44; // r0
  int v45; // r3
  int v46; // r3
  _DWORD *v47; // r3
  int v48; // r2
  int v49; // r2
  int v50; // r2
  int v51; // r3
  _DWORD *v52; // r3
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r0
  bool v57; // zf
  char *v58; // r5
  int v59; // r2
  unsigned int v60; // r1
  int v61; // r0
  int v62; // r3
  unsigned int *v63; // r2
  unsigned int v64; // r3
  int v65; // r0
  int v66; // r6
  int v67; // r2
  void *v68; // r3
  unsigned int v69; // r0
  int v70; // r3
  unsigned int v71; // r3
  _BYTE *v72; // r6
  int v73; // r0
  unsigned int v74; // r1
  unsigned int v75; // r7
  int v76; // r3
  unsigned __int8 *v77; // r3
  _BYTE *v78; // r2
  int v79; // r0
  int v80; // r0
  int v81; // r3
  int v82; // r1
  _BYTE *v83; // r2
  int v84; // r0
  int v85; // r1
  unsigned __int8 *v86; // r3
  _DWORD *v87; // lr
  int v88; // r12
  _DWORD *v89; // r2
  int v90; // r0
  _DWORD *v91; // r3
  _BYTE *v92; // r3
  int v93; // r2
  unsigned __int8 *v94; // r3
  int v95; // r0
  int v96; // r7
  int *v97; // r12
  int v98; // r0
  int v99; // r1
  unsigned __int8 *v100; // r3
  _DWORD *v101; // r12
  _DWORD *v102; // r2
  int v103; // r0
  int v104; // r3
  _BYTE *v105; // r8
  int v106; // r0
  int v107; // r2
  _DWORD *v108; // r2
  _DWORD *v109; // r0
  int v110; // r1
  _BYTE *v111; // r8
  unsigned __int8 *v112; // r0
  int *v113; // r1
  unsigned int v114; // r12
  unsigned int v115; // r3
  int v116; // r0
  _BYTE *v117; // r3
  int *v118; // r12
  unsigned int v119; // r3
  unsigned int v120; // r1
  int v121; // r0
  int v122; // r7
  int v123; // r6
  unsigned int v124; // r2
  int v125; // r4
  int v126; // r4
  int v127; // r7
  int v128; // r3
  int v129; // r7
  int v130; // r5
  int v131; // r6
  int v132; // r2
  int v133; // r1
  int v134; // r6
  int v135; // r6
  _DWORD *v136; // r5
  int v137; // r7
  int v138; // r4
  unsigned int v139; // r6
  int v140; // r4
  int v141; // r3
  unsigned int v142; // r1
  int v143; // r4
  unsigned int v144; // r5
  void *v145; // r7
  int v146; // r0
  int v147; // r5
  int v148; // r4
  int v149; // r0
  int v150; // r3
  int v151; // r2
  _DWORD *v152; // r4
  int v153; // r0
  int v154; // r5
  int v155; // r4
  int v156; // r6
  int v157; // r7
  int v158; // r4
  int v159; // r4
  int v160; // r6
  int v161; // r7
  int v162; // r4
  int v163; // r4
  int v164; // r1
  _DWORD *v165; // r4
  unsigned int v166; // r4
  unsigned int v167; // r6
  int v168; // r1
  int v169; // r0
  unsigned int v170; // r4
  int v171; // r0
  int v172; // r0
  int v173; // r3
  int v174; // r1
  int v175; // r0
  int v176; // r0
  int v177; // r3
  int v178; // r0
  int v179; // [sp+Ch] [bp-18h]
  unsigned __int8 *v180; // [sp+Ch] [bp-18h]
  unsigned __int8 *v181; // [sp+Ch] [bp-18h]
  char v182; // [sp+Ch] [bp-18h]
  unsigned __int8 v183; // [sp+Ch] [bp-18h]
  int v184; // [sp+10h] [bp-14h]
  int v185; // [sp+10h] [bp-14h]
  int v186; // [sp+14h] [bp-10h]
  int v187; // [sp+14h] [bp-10h]
  unsigned __int8 v188[8]; // [sp+1Ch] [bp-8h] BYREF

  v6 = (unsigned int)a3;
  value = msg_get_value(a3);
  if ( !value )
  {
    v12 = (__int16 **)off_1241C4;
    v13 = **(__int16 **)off_1241C4;
    if ( v13 >= 0 )
    {
      if ( a1 <= 0x3B )
      {
        if ( a1 > 5 )
        {
          switch ( a1 )
          {
            case 6u:
              goto LABEL_76;
            case 8u:
              goto LABEL_70;
            case 0xEu:
              goto LABEL_68;
            case 0x10u:
              goto LABEL_67;
            case 0x12u:
              goto LABEL_66;
            case 0x14u:
              goto LABEL_63;
            case 0x16u:
              goto LABEL_53;
            case 0x18u:
              goto LABEL_52;
            case 0x1Cu:
              goto LABEL_75;
            case 0x1Eu:
              goto LABEL_33;
            case 0x20u:
              goto LABEL_32;
            case 0x28u:
              goto LABEL_27;
            case 0x30u:
              goto LABEL_26;
            case 0x3Bu:
              goto LABEL_25;
            default:
              v16 = off_124198;
              v17 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v16 = off_124198;
        *((_BYTE *)off_124198 + 48) = 0;
        v17 = sub_12BEE8(*(_DWORD *)a2);
        if ( v17 )
        {
          sub_121BE4(*(_DWORD *)a2);
          v17 = 0;
        }
        else if ( v16[49] )
        {
          v16[49] = 0;
          if ( sub_126664(v188) )
            bt_link_lookup_entry(
              *(unsigned __int8 *)(*(_DWORD *)v188 + 1225),
              dword_12419C + 38 * *(unsigned __int8 *)(*(_DWORD *)v188 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(_DWORD *)off_124194 << 28 )
    {
      v73 = sub_12F694(dword_12485C, dword_124858, 2493);
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        v75 = a1 - 6;
        v76 = (int)jpt_124572;
        switch ( v75 )
        {
          case 0u:
            goto LABEL_187;
          case 1u:
          case 3u:
          case 4u:
          case 5u:
          case 6u:
          case 7u:
          case 9u:
          case 0xBu:
          case 0xDu:
          case 0xFu:
          case 0x11u:
          case 0x13u:
          case 0x14u:
          case 0x15u:
          case 0x17u:
          case 0x19u:
          case 0x1Bu:
          case 0x1Cu:
          case 0x1Du:
          case 0x1Eu:
          case 0x1Fu:
          case 0x20u:
          case 0x21u:
          case 0x23u:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x27u:
          case 0x28u:
          case 0x29u:
          case 0x2Bu:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x30u:
          case 0x31u:
          case 0x32u:
          case 0x33u:
          case 0x34u:
            *(_BYTE *)(a4 + 17) = (unsigned __int8)jpt_124572;
            jpt_124572[9] = (_UNKNOWN *)v75;
            *(_BYTE *)(v6 + 13) = v74;
            v73 = *(_DWORD *)((v74 >> 8) + 0x74);
            goto LABEL_171;
          case 2u:
            goto LABEL_185;
          case 8u:
            goto LABEL_184;
          case 0xAu:
            a4 = v73 << 24;
            LOBYTE(v75) = 0;
            v76 = 0;
            LOBYTE(v73) = 0;
            *(_BYTE *)(v6 + 12) = 0;
            a2 = 0;
LABEL_184:
            *(_DWORD *)(a4 + 52) = v6;
            *(_BYTE *)(v76 + 13) = v75;
            *(_BYTE *)(a4 + 21) = v73;
            *(_BYTE *)(a2 + 21) = v75;
            v74 = *(_DWORD *)(a2 + 100);
            *(_DWORD *)(a4 + 52) = v6;
            *(_BYTE *)(2 * a4 + 0xD) = v75;
            *(_BYTE *)(a4 + 21) = v73;
            v151 = *(_DWORD *)(a4 + 20);
            *(_BYTE *)(a2 + 21) = v75;
            v76 = 2 * a4;
            *(_DWORD *)(v6 + 84) = v151;
            a4 = *(_DWORD *)(v6 + 116);
            *(_DWORD *)(a4 + 84) = v151;
            a2 = 32;
LABEL_185:
            *(_DWORD *)(v6 + 64) = a2;
            *(_DWORD *)(v6 + 52) = v6;
            v152 = (_DWORD *)(v6 + 37);
            v152[25] = v74;
            *(_DWORD *)(a4 + 84) = v152;
            v152[16] = 32;
            v152[13] = v152;
            goto LABEL_186;
          case 0xCu:
            v150 = *(_DWORD *)(v6 + 4);
            *(_DWORD *)(a2 + 84) = a4;
            *(_BYTE *)(a4 + 17) = v150;
            *(_BYTE *)(a2 + 1) = v75;
            JUMPOUT(0x144418);
          case 0xEu:
            v148 = *(unsigned __int8 *)(a4 + 1);
            *(_BYTE *)(a4 + 29) = v73;
            *(_DWORD *)(a2 + 84) = v148;
            *(_DWORD *)(a4 + 84) = a4;
            v149 = *(_DWORD *)(a4 + 4);
            *(_BYTE *)(a2 + 29) = v149;
            BYTE1(jpt_124572[3]) = v75;
            *(_BYTE *)(2 * a2 + 0x11) = a2;
            jpt_124572[13] = (_UNKNOWN *)v75;
            *(_DWORD *)(a2 + 20) = v149;
            JUMPOUT(0x1443E8);
          case 0x10u:
            v145 = (void *)(v75 - 240);
            v146 = *(_DWORD *)(a4 + 4);
            *(_BYTE *)(a2 + 29) = v146;
            BYTE1(jpt_124572[3]) = (_BYTE)v145;
            *(_BYTE *)(v6 + 17) = a2;
            jpt_124572[13] = v145;
            *(_DWORD *)(a2 + 20) = v146;
            v147 = *(_DWORD *)(v6 + 68);
            *(_DWORD *)(v147 + 68) = v147;
            *(_BYTE *)(*(__int16 *)(2 * v147) + 0x11) = *(_DWORD *)(*(__int16 *)(2 * v147) + 0x64);
            JUMPOUT(0x1443B0);
          case 0x12u:
            JUMPOUT(0x144380);
          case 0x16u:
LABEL_186:
            v153 = v76 >> 31;
            v6 = 0;
            v76 = v74 << 22;
            v74 <<= 18;
            v75 = v153 << 14;
LABEL_187:
            v154 = *(unsigned __int8 *)v6;
            *(_DWORD *)(v6 + 64) = v154;
            *(_DWORD *)(v154 + 68) = v154;
            v155 = *(_DWORD *)(v154 + 68);
            *(_DWORD *)(v155 + 64) = 77;
            *(_BYTE *)(a4 + 17) = v154;
            v156 = *(_DWORD *)(v155 + 68);
            *(_BYTE *)(v76 + 17) = v75;
            *(_BYTE *)(v75 + 1) = v75 >> 9;
            *(_BYTE *)(v156 + 9) = v75;
            v157 = *(_DWORD *)(v76 + 116);
            *(_BYTE *)(v155 + 13) = v156;
            v158 = *(__int16 *)(v156 + 32);
            *(_DWORD *)(v156 + 112) = v158;
            v159 = 2 * *(unsigned __int8 *)(v158 + 91);
            v160 = *(_DWORD *)(v159 + 68);
            *(_BYTE *)(v76 + 17) = v157;
            *(_BYTE *)(v157 + 1) = 32;
            *(_BYTE *)(v160 + 9) = v157;
            v161 = *(_DWORD *)(v76 + 116);
            *(_BYTE *)(v159 + 13) = v160;
            v162 = *(__int16 *)(v160 + 32);
            *(_DWORD *)(v160 + 112) = 32;
            *(_DWORD *)(v162 + 20) = v76;
            v163 = MEMORY[0x40];
            *(_DWORD *)(v160 + 84) = v160;
            *(_DWORD *)(v163 + 64) = -82;
            v164 = *(_DWORD *)(v74 + 100);
            MEMORY[0xFFFFFFBF] = v164;
            *(_BYTE *)(v163 + 32) = 32;
            *(_DWORD *)(v160 + 20) = *(_DWORD *)(v163 + 16);
            *(_BYTE *)(v76 + 17) = v161;
            *(_BYTE *)(v163 + 9) = v164;
            *(_DWORD *)(v163 + 84) = v161;
            *(_DWORD *)(v163 + 64) = -55;
            *(_DWORD *)(v163 + 20) = v76;
            v165 = (_DWORD *)MEMORY[0xFFFFFF92];
            MEMORY[0xFFFFFFCA] = v164;
            LOWORD(v164) = *(_WORD *)(MEMORY[0xFFFFFF92] - 55);
            *(_DWORD *)(v160 + 112) = -55;
            v165[25] = v160;
            *(_DWORD *)(v160 + 84) = v76;
            v165[16] = -171;
            v165[29] = v76;
            v165[16] = -280;
            v165[5] = v76;
            MEMORY[0xFFFFFEE9] = v164;
            v166 = MEMORY[0xFFFFFDD0] + 50;
            MEMORY[0xFFFFFF4C] = v161;
            *(_BYTE *)(v166 + 13) = v160;
            *(_BYTE *)(v166 + 17) = -24;
            v166 >>= 9;
            *(_DWORD *)(v160 + 100) = v161;
            *(_DWORD *)(v166 + 64) = 103;
            *(_DWORD *)(v166 + 84) = v160;
            *(_DWORD *)(v166 + 16) = 103;
            MEMORY[0x81] = v160;
            *(_BYTE *)(v166 + 8) = 103;
            MEMORY[0x4E] = *(_DWORD *)(v166 + 20);
            MEMORY[0xA74D9] = v161;
            *(_DWORD *)(v166 + 64) = 102;
            *(_DWORD *)(v166 + 84) = 685173;
            *(_DWORD *)(v166 + 16) = 102;
            MEMORY[0x81] = 685173;
            *(_BYTE *)(v166 + 8) = 102;
            v167 = *(_DWORD *)(v166 + 20);
            MEMORY[0x4E] = v167;
            *(_BYTE *)(v166 + 21) = v166;
            MEMORY[1] = 0;
            MEMORY[0x64] = v4;
            *(_BYTE *)(v167 + 29) = 116;
            v168 = MEMORY[0x64];
            v169 = *(_DWORD *)(v166 + 112);
            *(_BYTE *)(v167 + 17) = 0;
            *(_BYTE *)(v166 + 21) = v166;
            *(_DWORD *)(v166 + 64) = v169;
            *(_DWORD *)(v166 + 52) = v168;
            v169 += 53;
            *(_BYTE *)(v166 + 21) = v166;
            *(_DWORD *)(v166 + 64) = v169;
            *(_DWORD *)(v167 + 68) = v169;
            *(_BYTE *)(v166 + 16) = v169;
            *(_BYTE *)(v166 + 21) = v166;
            MEMORY[0x64] = v4;
            MEMORY[0x15] = v4;
            v170 = v167 >> 9;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_DWORD *)(v170 + 16) = 116;
            *(_DWORD *)(v170 + 52) = v170;
            v171 = *(_DWORD *)((v167 >> 9) + 0x10);
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_BYTE *)(v170 + 8) = v171;
            *(_DWORD *)(v170 + 20) = v170;
            MEMORY[0x14] = v167 >> 9;
            v172 = *(_DWORD *)((v167 >> 9) + 0x10);
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_BYTE *)(v170 + 8) = v172;
            v173 = *(__int16 *)(v167 >> 9);
            *(_DWORD *)(v170 + 68) = 0;
            MEMORY[5] = 0;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_DWORD *)(v170 + 64) = 99;
            *(_DWORD *)(v170 + 52) = v173;
            v174 = *(_DWORD *)((v167 >> 9) + 0x64);
            *(_DWORD *)(v170 + 84) = v173;
            MEMORY[0x15] = v4;
            MEMORY[5] = v174;
            *(_BYTE *)(v170 + 21) = v170;
            *(_BYTE *)v170 = 116;
            MEMORY[0x54] = v174;
            *(_DWORD *)(v170 + 64) = 116;
            *(_DWORD *)(v170 + 52) = v4;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            MEMORY[0x11] = 0;
            v175 = *(_DWORD *)((v167 >> 9) + 0x10);
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_BYTE *)(v170 + 8) = v175;
            v176 = *(_DWORD *)((v167 >> 9) + 0x10);
            *(_BYTE *)(v170 + 21) = v170;
            *(_BYTE *)(v170 + 8) = v176;
            MEMORY[0x15] = v4;
            MEMORY[5] = 0;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_BYTE *)(v170 + 8) = 116;
            v177 = *(__int16 *)(v167 >> 9);
            MEMORY[0x11] = *(_WORD *)(v167 >> 9);
            *(_BYTE *)(v170 + 17) = 0;
            MEMORY[0xD] = 0;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            MEMORY[0x64] = *(_DWORD *)((v167 >> 9) + 0x40);
            v178 = MEMORY[0x64];
            *(_DWORD *)(v177 + 36) = *(_DWORD *)(v177 + 116);
            MEMORY[0x64] = v178;
            MEMORY[0x11] = 0;
            *(_BYTE *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(_DWORD *)(v170 + 112) = v178;
            *(_BYTE *)(MEMORY[0x74] + 17) = MEMORY[0];
            JUMPOUT(0x1446C4);
          case 0x18u:
          case 0x1Au:
            goto LABEL_174;
          case 0x22u:
            goto LABEL_173;
          case 0x2Au:
            goto LABEL_172;
          case 0x35u:
LABEL_171:
            *(_BYTE *)(a4 + 17) = (unsigned __int8)jpt_124572;
            v6 = *(unsigned __int8 *)(a4 + 5);
            *(_DWORD *)(a4 + 84) = v73;
            *(_DWORD *)(v6 + 16) = v73;
            v76 = *(__int16 *)(v6 + 61);
            *(_DWORD *)(a4 + 84) = a4;
LABEL_172:
            a2 = v74 >> 8;
            *(_DWORD *)(a4 + 20) = v75;
            *(_DWORD *)((v74 >> 8) + 0x54) = v76;
LABEL_173:
            *(_BYTE *)(a4 + 1) = a2;
            v122 = *(_DWORD *)(a4 + 20);
            v123 = *(_DWORD *)(v6 + 20);
            *(_DWORD *)(a2 + 20) = a2;
            v124 = v6 >> 20;
            *(_BYTE *)(v123 + 17) = v76;
            *(_DWORD *)(a2 + 84) = v123;
            *(_BYTE *)(*(__int16 *)(v6 + a2) + 9) = v6 >> 20;
            *(_DWORD *)(v123 + 20) = v6 >> 20;
            *(_BYTE *)(v122 + 13) = v6 >> 20;
            *(_DWORD *)(v76 + 20) = v122;
            v125 = *(_DWORD *)(a2 + 68);
            *(_DWORD *)(a2 + 52) = v122;
            *(_BYTE *)(v125 + 17) = v124;
            v75 = 2 * v125;
            *(_BYTE *)(v125 + 9) = v76;
            a2 = *(__int16 *)(2 * a2);
            v76 = *(_DWORD *)(v125 + 116);
            *(_DWORD *)(a2 + 100) = v123;
            a4 = v76;
LABEL_174:
            v126 = *(_DWORD *)(v75 + 84);
            v127 = *(_DWORD *)(v76 + 84);
            *(_BYTE *)(a2 + 9) = v127;
            *(_BYTE *)(v76 + 25) = v127;
            *(_BYTE *)(v126 + 9) = a2;
            v128 = *(_DWORD *)(a4 + 20);
            v129 = *(_DWORD *)(a2 + 100);
            *(_DWORD *)(v128 + 116) = v129;
            *(_BYTE *)(v126 + 17) = a2;
            *(_DWORD *)(a2 + 68) = a2;
            v130 = *(_DWORD *)(*(__int16 *)(2 * a2) + 0x14);
            v131 = *(_DWORD *)(v130 + 116);
            v132 = *(__int16 *)(v131 + v130);
            *(_DWORD *)(v131 + 84) = v131;
            *(_BYTE *)(v131 + 13) = v132;
            v133 = *(_DWORD *)(v130 + 116);
            v134 = *(__int16 *)(2 * v130);
            *(_DWORD *)(v126 + 84) = v129;
            *(_DWORD *)(v134 + 100) = v126;
            v135 = *(_DWORD *)(2 * v133);
            v136 = off_144344;
            v137 = *(char *)(v128 + v133);
            *(_WORD *)(v133 + 61) = (_WORD)off_144344;
            *(_WORD *)(v128 + 60) = v128;
            *(_BYTE *)(v126 + 12) = (_BYTE)v136;
            *(_DWORD *)(v135 + 20) = v132;
            v138 = *(_DWORD *)(v126 + 20);
            *(_DWORD *)(v138 + 64) = v136;
            *(_DWORD *)(v138 + 64) = 111;
            v136[21] = v137;
            v139 = v136[29];
            *(_BYTE *)(*(unsigned __int8 *)(v138 + 1) + 0xD) = v133;
            *(_BYTE *)(v139 + 17) = v128;
            *(_BYTE *)((v139 >> 9) + 0x11) = v133;
            *(_DWORD *)(v139 + 20) = v139;
            v140 = MEMORY[0x14];
            v141 = *(_DWORD *)(MEMORY[0x14] + 4);
            v142 = *(_DWORD *)(MEMORY[0x14] + 100);
            *(_DWORD *)(MEMORY[0x14] + 20) = v132;
            MEMORY[0x44] = v139;
            *(_DWORD *)(v140 + 96) = 44;
            *(_DWORD *)(v139 + 84) = v132;
            *(_DWORD *)(v140 + 64) = -52;
            *(_WORD *)(v141 + 60) = -52;
            *(_BYTE *)(v140 + 12) = -52;
            *(_DWORD *)(v140 + 20) = v142;
            MEMORY[0x10] = v139;
            *(_BYTE *)(v140 + 9) = v139;
            *(_BYTE *)(v140 + 5) = 61;
            *(_BYTE *)(v140 + 9) = v139;
            *(_BYTE *)(v140 + 5) = 61;
            *(_DWORD *)(v140 + 64) = 12;
            *(_DWORD *)(v140 + 48) = 100;
            MEMORY[0x20] = 100;
            MEMORY[0x1D] = v139;
            *(_BYTE *)(v137 + 1) = v142;
            *(_DWORD *)(v140 + 64) = -89;
            *(_BYTE *)(v140 + 12) = 100;
            *(_DWORD *)(v140 + 64) = -209;
            *(_DWORD *)(v139 + 84) = v141;
            *(_DWORD *)(v139 + 52) = v140;
            *(_DWORD *)(v140 + 64) = -209;
            *(_DWORD *)(v140 + 20) = v142 - 104;
            *(_DWORD *)((v142 >> 8) + 0x44) = v139;
            *(_DWORD *)(v140 + 68) = 100;
            v143 = *(__int16 *)(*(_DWORD *)(v142 + (v142 >> 8)) + (v142 >> 8));
            v144 = v142 + (v141 == 0) + (v142 >> 8);
            MEMORY[0x6C6E] = 2 * v141;
            *(_DWORD *)(v144 + 52) = -v141;
            *(_BYTE *)(v143 + 13) = v144;
            JUMPOUT(0x1442F0);
          default:
            break;
        }
      }
      if ( **v12 >= 0 )
      {
LABEL_24:
        v16 = off_124198;
        v17 = 2;
        goto LABEL_10;
      }
    }
    else if ( a1 > 0x3B )
    {
      if ( a1 == 143 )
        goto LABEL_16;
    }
    else if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6u:
LABEL_76:
          v72 = (_BYTE *)rf_bus_setup_n3a8(7, a4, v6, 2);
          v16 = off_124508;
          *v72 = sub_11FAF8((int *)(a2 + 2), *(unsigned __int8 *)a2, *(unsigned __int8 *)(a2 + 8), v72 + 1);
          sub_12CBB4(v72);
          v17 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v69 = *(unsigned __int8 *)a2;
          if ( v69 <= 3 )
            v69 = sub_11FEF0(v69);
          v70 = *((_DWORD *)off_124544 + 2);
          if ( !v70 )
            sub_12BE54(v69, v10);
          message_dispatch_n84(9, a4, v6, v70);
          v16 = off_124508;
          v17 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v16 = off_124508;
          v67 = *(_DWORD *)a2;
          *(_DWORD *)off_124508 = *(_DWORD *)a2;
          if ( v13 < 0 && *(_DWORD *)off_124868 << 28 )
          {
            sub_12F6C4(dword_12485C, dword_12486C, 472);
            v67 = *(_DWORD *)v16;
          }
          v68 = off_124540;
          *(_DWORD *)off_124540 = v67 | *((_DWORD *)v16 + 1);
          message_dispatch_n84(15, a4, v6, v68);
          v17 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v65 = rf_bus_setup_n3a8(17, a4, v6, 2);
          v16 = off_124508;
          v66 = v65;
          sub_102898((unsigned __int16 *)a2, *(unsigned __int8 *)(a2 + 10));
          sub_12CBB4(v66);
          v17 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v63 = (unsigned int *)off_12453C;
          v16 = off_124508;
          *(_DWORD *)off_12453C = *(_DWORD *)off_12453C & 0xFFFFFF00 | *(unsigned __int8 *)a2;
          v64 = *v63 | 0x80000000;
          *v63 = v64;
          message_dispatch_n84(19, a4, v6, v64);
          v17 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v60 = *(unsigned __int16 *)a2;
          v61 = dword_124538 + 1320 * *(unsigned __int8 *)(a2 + 2);
          if ( *(_BYTE *)(v61 + 106) )
          {
            sub_1205A8(v61, v60);
          }
          else
          {
            v62 = dword_1244F4 + 696 * *(unsigned __int8 *)(v61 + 116);
            *(_DWORD *)(v62 + 8) = v60 << 10;
          }
          message_dispatch_n84(21, a4, v6, v62);
          v16 = off_124508;
          v17 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v54 = *(_DWORD *)a2;
          v55 = *(unsigned __int8 *)(a2 + 5);
          v16 = off_124508;
          v56 = *((_DWORD *)off_124530 + 10);
          v58 = (char *)(*(_DWORD *)a2 & 0xFFFFF1FF);
          v57 = v58 == nullptr;
          v59 = v55 + 4;
          if ( v58 )
            v54 = (int)off_124508 + 4 * v59;
          else
            v58 = (char *)off_124508 + 4 * v59;
          if ( v57 )
            *((_DWORD *)v58 + 1) = v54;
          else
            *(_DWORD *)(v54 + 4) = v58;
          if ( v56 )
          {
            v54 = *(unsigned __int8 *)(v56 + 4);
            if ( v54 == v55 )
            {
              v54 = (int)off_124534;
              *(_DWORD *)off_124534 = *(_DWORD *)&v16[4 * v59 + 4];
            }
          }
          message_dispatch_n84(23, a4, v6, v54);
          v17 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v16 = off_124508;
          sub_14380C(dword_124524 + 1320 * *(unsigned __int8 *)(a2 + 6), a2, 6);
          v52 = off_12452C;
          v53 = *(unsigned __int16 *)(a2 + 4);
          *(_DWORD *)off_124528 = *(_DWORD *)a2;
          *v52 = v53;
          message_dispatch_n84(25, a4, v6, v52);
          v17 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v16 = off_124508;
          v71 = (*(unsigned __int8 *)a2 << 14) & 0x1C000 | *(_DWORD *)off_124548 & 0xFFFE3FFF;
          *(_DWORD *)off_124548 = v71;
          message_dispatch_n84(29, a4, v6, v71);
          v17 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v32 = *(unsigned __int8 *)(a2 + 3);
          v33 = dword_124538;
          v34 = (unsigned __int8 *)(dword_124538 + 1320 * v32);
          v188[0] = 0;
          v184 = 1320 * v32;
          v35 = sub_120770(v188);
          v36 = v34[106];
          v37 = *(unsigned __int8 *)(a2 + 2);
          v34[108] = v37;
          v179 = v35;
          if ( !v36 )
          {
            v186 = v34[116];
            if ( v37 )
            {
              v38 = dword_1244F4 + 696 * v34[116];
              v39 = v184 + 24 + v33;
              timestamp_update_4f60(v39, *((_DWORD *)off_1244F8 + 4) + *(_DWORD *)(v38 + 8));
              *(_WORD *)(v38 + 32) = *(_WORD *)a2;
              sub_120750();
              feature_guard_sdio(256, dword_1244FC);
              v40 = off_124504;
              *(_DWORD *)off_124500 = (unsigned __int16)*(_DWORD *)off_124500 | (*(unsigned __int16 *)a2 << 16);
              if ( (*v40 & 0x8000) != 0 && chip_feature_check() && (*(_DWORD *)(v38 + 4) & 0x20) != 0 )
              {
                sub_101904(*(_WORD *)a2);
                sub_11C750();
                feature_guard_sdio(256, dword_124B9C);
                mmio_set_bit7();
              }
              v16 = off_124508;
              v187 = dword_1244F4 + 696 * v186;
              v41 = v33 + 1320 * v32;
              v42 = *(_DWORD *)(v41 + 4) | 1;
              *(_WORD *)(v187 + 30) = (unsigned int)(((unsigned int)dword_12454C
                                                    * (unsigned __int64)(*(_DWORD *)(v187 + 8)
                                                                       * ((unsigned int)*((unsigned __int16 *)off_124508
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v43 = off_1244F8;
              *(_WORD *)(v41 + 112) = 0;
              *(_BYTE *)(v41 + 114) = 0;
              *(_BYTE *)(v41 + 148) = 0;
              *(_BYTE *)(v41 + 128) = 0;
              *(_DWORD *)(v41 + 124) = 0;
              *(_DWORD *)(v41 + 4) = v42;
              *(_DWORD *)(v41 + 120) = v43[4];
              v185 = v41;
              v44 = bt_hci_cmd_dispatch(v34);
              v45 = *(unsigned __int8 *)(v185 + 1224);
              if ( *(_BYTE *)(v185 + 1224) )
              {
                if ( !v179 )
                  goto LABEL_39;
                v92 = off_124860;
                if ( !*((_DWORD *)off_124860 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124860 + 8) = 0;
                v92[36] = 0;
                sub_1296EC(v44);
LABEL_119:
                v93 = **v12;
                *((_DWORD *)v16 + 1) |= 0x10u;
                if ( v93 < 0 && *(_DWORD *)off_124BAC << 28 )
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                *(_DWORD *)off_124894 = *(_DWORD *)v16 | *((_DWORD *)v16 + 1);
                v37 = *(unsigned __int8 *)(a2 + 2);
                goto LABEL_40;
              }
              if ( v179 )
              {
                if ( v179 != 1 )
                  goto LABEL_39;
                v105 = off_124B88;
                if ( v34 == *((unsigned __int8 **)off_124B88 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124B88 + 8) = v45;
                v182 = v45;
                v106 = timestamp_remove_058(v39);
                v105[36] = v182;
                sub_1296EC(v106);
                v37 = *(unsigned __int8 *)(a2 + 2);
              }
              else
              {
                if ( *((_DWORD *)off_12450C + 8) )
                {
LABEL_39:
                  v37 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
                if ( v188[0] )
                {
                  if ( v188[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v118 = (int *)off_124BA8;
                v119 = *(_DWORD *)(v187 + 8);
                v120 = *(_DWORD *)off_124BA8;
                *((_DWORD *)off_12450C + 8) = v34;
                *v118 = (unsigned __int16)(v119 >> 10) | (HIWORD(v120) << 16);
                v121 = timestamp_remove_058(v39);
                *((_BYTE *)off_124B88 + 36) = 0;
                sub_1295B8(v121);
                v37 = *(unsigned __int8 *)(a2 + 2);
              }
            }
            else
            {
              v79 = timestamp_remove_058(v184 + 24 + v33);
              nullsub_8(v79);
              v80 = feature_guard_sdio(256, dword_124884);
              if ( (*(_DWORD *)off_124888 & 0x8000) != 0 )
              {
                v80 = chip_feature_check();
                if ( v80 )
                {
                  if ( (*(_DWORD *)(dword_124B8C + 696 * v186 + 4) & 0x20) != 0 && v34[106] != 4 )
                    v80 = phy_tbl_lookup_by_idx(v34[107]);
                }
              }
              v81 = v33 + 1320 * v32;
              v82 = *(unsigned __int8 *)(v81 + 1224);
              *(_BYTE *)(v81 + 1227) = 0;
              *(_DWORD *)(v81 + 1228) = 0;
              if ( v82 )
              {
                if ( v179 )
                {
                  v94 = *((unsigned __int8 **)off_124B84 + 2);
                  if ( v94 )
                  {
                    while ( v94[106] || !v94[108] || v34 == v94 || v94[1224] )
                    {
                      v94 = *(unsigned __int8 **)v94;
                      if ( !v94 )
                        goto LABEL_101;
                    }
                    if ( !*((_DWORD *)off_124B88 + 8) )
                    {
                      v95 = v94[116];
                      v96 = dword_124B8C;
                      v97 = (int *)off_124BA8;
                      *((_DWORD *)off_124B88 + 8) = v94;
                      *v97 = (unsigned __int16)(*(_DWORD *)(v96 + 696 * v95 + 8) >> 10) | (HIWORD(*v97) << 16);
                      v181 = v94;
                      v98 = timestamp_remove_058(v94 + 24);
                      *((_BYTE *)off_124B88 + 36) = 0;
                      v16 = off_124B90;
                      sub_1295B8(v98);
                      v99 = **v12;
                      v100 = v181;
                      *((_DWORD *)v16 + 1) &= ~0x10u;
                      if ( v99 < 0 && *(_DWORD *)off_124BAC << 28 )
                      {
                        sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                        v100 = v181;
                      }
                      v101 = off_124BB8;
                      *(_DWORD *)off_124B94 = *(_DWORD *)v16 | *((_DWORD *)v16 + 1);
                      v102 = off_124B98;
                      v103 = *((_DWORD *)v100 + 16);
                      v104 = *((unsigned __int16 *)v100 + 34);
                      *v101 = v103;
                      *v102 = v104;
                      v37 = *(unsigned __int8 *)(a2 + 2);
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v179 == 2 )
              {
                v111 = off_124B88;
                if ( !*((_DWORD *)off_124B88 + 8) )
                {
                  v112 = *((unsigned __int8 **)off_124B84 + 2);
                  if ( !v112 )
LABEL_169:
                    __und(0xFFu);
                  while ( v112[106] || !v112[108] || v34 == v112 || v112[1224] )
                  {
                    v112 = *(unsigned __int8 **)v112;
                    if ( !v112 )
                      goto LABEL_169;
                  }
                  v113 = (int *)off_124BA8;
                  v183 = v112[1224];
                  v114 = *(_DWORD *)off_124BA8;
                  v115 = *(_DWORD *)(dword_124B8C + 696 * v112[116] + 8);
                  *((_DWORD *)off_124B88 + 8) = v112;
                  *v113 = (unsigned __int16)(v115 >> 10) | (HIWORD(v114) << 16);
                  v116 = timestamp_remove_058(v112 + 24);
                  v111[36] = v183;
                  v16 = off_124B90;
                  sub_1295B8(v116);
                  v37 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
              }
              else if ( v179 == 1 )
              {
                v117 = off_124B88;
                if ( v34 == *((unsigned __int8 **)off_124B88 + 8) )
                {
                  *((_DWORD *)off_124B88 + 8) = 0;
                  v117[36] = 0;
                  v16 = off_124B90;
                  sub_1296EC(v80);
                  v37 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
              }
LABEL_101:
              v37 = *(unsigned __int8 *)(a2 + 2);
              v16 = off_124864;
            }
LABEL_40:
            sub_12A2B4(v34, v37);
            v46 = *(unsigned __int8 *)(a2 + 2);
            if ( *(_BYTE *)(a2 + 2) )
            {
              v47 = *(_DWORD **)off_124510;
              v48 = **(_DWORD **)off_124510;
              if ( v48 )
                *(_DWORD *)off_124514 = v48;
              else
                *(_DWORD *)off_124880 = *(_DWORD *)(v33 + 1320 * v32 + 8);
              v49 = v47[1];
              if ( v49 )
              {
                if ( (v49 & 0xFFF) != 0 )
                  *(_DWORD *)off_12487C = v49;
                else
                  *(_DWORD *)off_124518 = v49 & 0xFFFFF000 | *(_DWORD *)(v33 + 1320 * v32 + 12) & 0xFFF;
              }
              else
              {
                *(_DWORD *)off_12487C = *(_DWORD *)(v33 + 1320 * v32 + 12);
              }
              v50 = v47[2];
              if ( v50 )
                *(_DWORD *)off_12451C = v50;
              else
                *(_DWORD *)off_124878 = *(_DWORD *)(v33 + 1320 * v32 + 16);
              v51 = v47[3];
              if ( v51 )
                *(_DWORD *)off_124520 = v51;
              else
                *(_DWORD *)off_12488C = *(_DWORD *)(v33 + 1320 * v32 + 20);
              chip_version_read_12207E0();
            }
            message_dispatch_n84(31, a4, v6, v46);
            v17 = 0;
            goto LABEL_10;
          }
          if ( !v35 )
          {
            if ( v37 )
            {
              v77 = nullptr;
              goto LABEL_84;
            }
LABEL_85:
            v16 = off_124864;
            goto LABEL_40;
          }
          v77 = *((unsigned __int8 **)off_124890 + 2);
          if ( v77 )
          {
            do
            {
              if ( !v77[106] && v77[108] && v34 != v77 && !v77[1224] )
                break;
              v77 = *(unsigned __int8 **)v77;
            }
            while ( v77 );
            if ( !v37 )
            {
              v83 = off_124860;
              if ( !*((_DWORD *)off_124860 + 8) && v77 )
              {
                *((_DWORD *)off_124860 + 8) = v77;
                v83[36] = 0;
                v180 = v77;
                v16 = off_124864;
                v84 = timestamp_remove_058(v77 + 24);
                sub_1295B8(v84);
                v85 = **v12;
                v86 = v180;
                *((_DWORD *)v16 + 1) &= ~0x10u;
                if ( v85 < 0 && *(_DWORD *)off_124BAC << 28 )
                {
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                  v86 = v180;
                }
                v87 = off_1248A4;
                v88 = *((_DWORD *)v86 + 16);
                *(_DWORD *)off_124894 = *(_DWORD *)v16 | *((_DWORD *)v16 + 1);
                v89 = off_124898;
                v90 = *((unsigned __int16 *)v86 + 34);
                *v87 = v88;
                v91 = off_12489C;
                *v89 = v90;
                *v91 = dword_1248A0;
                v89[8212] &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_85;
            }
          }
          else if ( !v37 )
          {
            goto LABEL_85;
          }
LABEL_84:
          v78 = off_124860;
          if ( v77 == *((unsigned __int8 **)off_124860 + 8) )
          {
            *((_DWORD *)off_124860 + 8) = 0;
            v78[36] = 0;
            v16 = off_124B90;
            ((void (*)(void))sub_1296EC)();
            v107 = **v12;
            *((_DWORD *)v16 + 1) |= 0x10u;
            if ( v107 < 0 && *(_DWORD *)off_124BAC << 28 )
              sub_12F6C4(dword_124BB4, dword_124BB0, 472);
            v108 = off_124B94;
            v109 = off_124BA0;
            *(_DWORD *)off_124B94 = *(_DWORD *)v16 | *((_DWORD *)v16 + 1);
            v110 = dword_124BA4;
            *v109 = dword_124BA4;
            v108[8197] |= v110;
            v37 = *(unsigned __int8 *)(a2 + 2);
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v16 = off_124198;
          v31 = *(unsigned __int8 *)a2 | (((unsigned __int8)*(_DWORD *)off_1241B8 * *(unsigned __int8 *)a2) << 8);
          *(_DWORD *)off_1241BC = v31;
          message_dispatch_n84(33, a4, v6, v31);
          v17 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v19 = *(_BYTE *)a2;
          if ( *(_BYTE *)a2 )
          {
            if ( sub_13A490(
                   dword_124870 + 696 * *(unsigned __int8 *)(a2 + 1),
                   *(unsigned __int8 *)(a2 + 2),
                   *(unsigned __int16 *)(a2 + 6)) )
            {
              *(_DWORD *)off_124874 |= 0x80u;
              v19 = 0;
            }
            else
            {
              v19 = 4;
            }
          }
          else
          {
            v20 = *(unsigned __int8 *)(a2 + 2);
            v21 = *(unsigned __int16 *)(a2 + 4);
            v22 = *(_DWORD *)(dword_1241AC + 4 * *(unsigned __int8 *)(dword_1241A8 + v20));
            if ( (int)v21 >= v22 )
            {
              if ( v21 > 0x40 )
                LOWORD(v23) = *(_DWORD *)(dword_1241AC + 4 * *(unsigned __int8 *)(dword_1241A8 + v20));
              else
                LOWORD(v23) = v22 / 2;
            }
            else
            {
              v23 = v21 >> 1;
            }
            sub_12ECB0(dword_1241B0, v20, v21);
            v24 = *(_WORD *)(a2 + 4);
            v25 = 696 * *(unsigned __int8 *)(a2 + 1);
            v26 = *(unsigned __int8 *)(v25 + 12 * *(unsigned __int8 *)(a2 + 2) + dword_1241C0 + 453);
            v27 = *(_WORD *)(a2 + 6);
            v28 = v25 + 6 * *(unsigned __int8 *)(a2 + 2) + dword_1241C0;
            v29 = dword_1241B4 + 32 * v26;
            *(_WORD *)(v28 + 354) = v23;
            *(_WORD *)(v28 + 356) = v24;
            *(_WORD *)(v29 + 12) = v27;
          }
          v30 = (_BYTE *)rf_bus_setup_n3a8(41, a4, v6, 3);
          *v30 = *(_BYTE *)(a2 + 1);
          v30[1] = *(_BYTE *)(a2 + 2);
          v30[2] = v19;
          sub_12CBB4(v30);
          v16 = off_124198;
          v17 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          sub_12F6E0(a2);
          v16 = off_124198;
          v17 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          sub_1280C8(a2);
          message_dispatch_n84(60, a4, v6, v18);
          v16 = off_124198;
          v17 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v16 = off_124198;
    sub_12F694(dword_1241A4, dword_1241A0, 2552);
    v17 = 2;
LABEL_10:
    *(_DWORD *)off_124194 = (unsigned __int8)(16 * v16[19]);
    rf_bus_mark_n_3b7(v6);
    return v17;
  }
  if ( (unsigned __int16)(value - 2) > 2u )
  {
    v14 = off_124198;
    *((_BYTE *)off_124198 + 19) = *(_BYTE *)off_124194 & 0xF;
    v15 = msg_get_value(v6);
    v14[18] = v15;
    sub_12BA2C(v15);
    rf_bus_mark_n_3b7(v6);
  }
  return 2;
}

