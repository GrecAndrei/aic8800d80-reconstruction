// sub_123EC0 @ 0x123ec0, size 3268 bytes
int __fastcall sub_123EC0(unsigned int a1, unsigned int a2, unsigned __int8 *a3, int a4)
{
  int v4; // r9
  unsigned int v6; // r4
  int value; // r0
  __int16 **v11; // r8
  int v12; // r3
  _BYTE *v13; // r5
  _BYTE *v14; // r7
  int v15; // r6
  char v16; // r7
  unsigned int v17; // r2
  signed int v18; // r3
  unsigned int v19; // r8
  __int16 v20; // lr
  int v21; // r2
  int v22; // r3
  __int16 v23; // r1
  int v24; // r2
  int v25; // r3
  _BYTE *v26; // r0
  int v27; // r11
  int v28; // r10
  unsigned __int8 *v29; // r9
  int v30; // r0
  int v31; // r2
  int v32; // r1
  int v33; // r7
  int v34; // s16
  _DWORD *v35; // r1
  int v36; // r3
  int v37; // r12
  _DWORD *v38; // r0
  int v39; // r3
  _DWORD *v40; // r3
  int v41; // r2
  int v42; // r2
  int v43; // r2
  int v44; // r3
  _DWORD *v45; // r3
  int v46; // r2
  char *v47; // r3
  int v48; // r1
  int v49; // r0
  bool v50; // zf
  char *v51; // r5
  int v52; // r2
  unsigned int v53; // r1
  int v54; // r0
  _DWORD *v55; // r2
  int v56; // r0
  int v57; // r6
  int v58; // r2
  unsigned int v59; // r0
  _BYTE *v60; // r6
  int v61; // r0
  unsigned int v62; // r1
  unsigned int v63; // r7
  int v64; // r3
  unsigned __int8 *v65; // r3
  _BYTE *v66; // r2
  int v67; // r3
  int v68; // r1
  _BYTE *v69; // r2
  int v70; // r1
  unsigned __int8 *v71; // r3
  _DWORD *v72; // lr
  int v73; // r12
  _DWORD *v74; // r2
  int v75; // r0
  _DWORD *v76; // r3
  _BYTE *v77; // r3
  int v78; // r2
  unsigned __int8 *v79; // r3
  int v80; // r0
  int v81; // r7
  int *v82; // r12
  int v83; // r1
  unsigned __int8 *v84; // r3
  _DWORD *v85; // r12
  _DWORD *v86; // r2
  int v87; // r0
  int v88; // r3
  _BYTE *v89; // r8
  int v90; // r2
  _DWORD *v91; // r2
  _DWORD *v92; // r0
  int v93; // r1
  _BYTE *v94; // r8
  unsigned __int8 *v95; // r0
  int *v96; // r1
  unsigned int v97; // r12
  unsigned int v98; // r3
  _BYTE *v99; // r3
  int *v100; // r12
  unsigned int v101; // r3
  unsigned int v102; // r1
  int v103; // r7
  int v104; // r6
  unsigned int v105; // r2
  int v106; // r4
  int v107; // r4
  int v108; // r7
  int v109; // r3
  int v110; // r7
  int v111; // r5
  int v112; // r6
  int v113; // r2
  int v114; // r1
  int v115; // r6
  int v116; // r6
  _DWORD *v117; // r5
  int v118; // r7
  int v119; // r4
  unsigned int v120; // r6
  int v121; // r4
  int v122; // r3
  unsigned int v123; // r1
  int v124; // r4
  unsigned int v125; // r5
  void *v126; // r7
  int v127; // r0
  int v128; // r5
  int v129; // r4
  int v130; // r0
  int v131; // r3
  int v132; // r2
  _DWORD *v133; // r4
  int v134; // r0
  int v135; // r5
  int v136; // r4
  int v137; // r6
  int v138; // r7
  int v139; // r4
  int v140; // r4
  int v141; // r6
  int v142; // r7
  int v143; // r4
  int v144; // r4
  int v145; // r1
  _DWORD *v146; // r4
  unsigned int v147; // r4
  unsigned int v148; // r6
  int v149; // r1
  int v150; // r0
  unsigned int v151; // r4
  int v152; // r0
  int v153; // r0
  int v154; // r3
  int v155; // r1
  int v156; // r0
  int v157; // r0
  int v158; // r3
  int v159; // r0
  int v160; // [sp+Ch] [bp-18h]
  unsigned __int8 *v161; // [sp+Ch] [bp-18h]
  unsigned __int8 *v162; // [sp+Ch] [bp-18h]
  char v163; // [sp+Ch] [bp-18h]
  unsigned __int8 v164; // [sp+Ch] [bp-18h]
  int v165; // [sp+10h] [bp-14h]
  int v166; // [sp+10h] [bp-14h]
  int v167; // [sp+14h] [bp-10h]
  int v168; // [sp+14h] [bp-10h]
  unsigned __int8 *(_DWORD *)(v169 + 0x20); // [sp+1Ch] [bp-8h] BYREF

  v6 = (unsigned int)a3;
  value = msg_get_value((unsigned int)a3);
  if ( !value )
  {
    v11 = (__int16 **)off_1241C4;
    v12 = **(__int16 **)off_1241C4;
    if ( v12 >= 0 )
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
              v14 = off_124198;
              v15 = 2;
              goto LABEL_10;
          }
        }
        goto LABEL_24;
      }
      if ( a1 == 143 )
      {
LABEL_16:
        v14 = off_124198;
        *((_BYTE *)off_124198 + 48) = 0;
        v15 = sub_12BEE8(*(_DWORD *)a2);
        if ( v15 )
        {
          sub_121BE4(*(_DWORD *)a2);
          v15 = 0;
        }
        else if ( *(_DWORD *)(v14 + 0xc4) )
        {
          *(_DWORD *)(v14 + 0xc4) = 0;
          if ( sub_126664(v169) )
            bt_link_lookup_entry(
              *(unsigned __int8 *)(*(_DWORD *)v169 + 1225),
              dword_12419C + 38 * *(unsigned __int8 *)(*(_DWORD *)v169 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(_DWORD *)off_124194 << 28 )
    {
      v61 = sub_12F694(dword_12485C, dword_124858, 2493);
      if ( a1 > 0x3B )
      {
        if ( a1 == 143 )
          goto LABEL_16;
      }
      else if ( a1 > 5 )
      {
        v63 = a1 - 6;
        v64 = (int)jpt_124572;
        switch ( v63 )
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
            jpt_124572[9] = (_UNKNOWN *)v63;
            *(_BYTE *)(v6 + 13) = v62;
            v61 = *(_DWORD *)((v62 >> 8) + 0x74);
            goto LABEL_171;
          case 2u:
            goto LABEL_185;
          case 8u:
            goto LABEL_184;
          case 0xAu:
            a4 = v61 << 24;
            LOBYTE(v63) = 0;
            v64 = 0;
            LOBYTE(v61) = 0;
            *(_BYTE *)(v6 + 12) = 0;
            a2 = 0;
LABEL_184:
            *(_DWORD *)(a4 + 52) = v6;
            *(_BYTE *)(v64 + 13) = v63;
            *(_BYTE *)(a4 + 21) = v61;
            *(_BYTE *)(a2 + 21) = v63;
            v62 = *(_DWORD *)(a2 + 100);
            *(_DWORD *)(a4 + 52) = v6;
            *(_BYTE *)(2 * a4 + 0xD) = v63;
            *(_BYTE *)(a4 + 21) = v61;
            v132 = *(_DWORD *)(a4 + 20);
            *(_BYTE *)(a2 + 21) = v63;
            v64 = 2 * a4;
            *(_DWORD *)(v6 + 84) = v132;
            a4 = *(_DWORD *)(v6 + 116);
            *(_DWORD *)(a4 + 84) = v132;
            a2 = 32;
LABEL_185:
            *(_DWORD *)(v6 + 64) = a2;
            *(_DWORD *)(v6 + 52) = v6;
            v133 = (_DWORD *)(v6 + 37);
            *(_DWORD *)(v133 + 0x64) = v62;
            *(_DWORD *)(a4 + 84) = v133;
            *(_DWORD *)(v133 + 0x40) = 32;
            *(_DWORD *)(v133 + 0x34) = v133;
            goto LABEL_186;
          case 0xCu:
            v131 = *(_DWORD *)(v6 + 4);
            *(_DWORD *)(a2 + 84) = a4;
            *(_BYTE *)(a4 + 17) = v131;
            *(_BYTE *)(a2 + 1) = v63;
            JUMPOUT(0x144418);
          case 0xEu:
            v129 = *(unsigned __int8 *)(a4 + 1);
            *(_BYTE *)(a4 + 29) = v61;
            *(_DWORD *)(a2 + 84) = v129;
            *(_DWORD *)(a4 + 84) = a4;
            v130 = *(_DWORD *)(a4 + 4);
            *(_BYTE *)(a2 + 29) = v130;
            BYTE1(jpt_124572[3]) = v63;
            *(_BYTE *)(2 * a2 + 0x11) = a2;
            jpt_124572[13] = (_UNKNOWN *)v63;
            *(_DWORD *)(a2 + 20) = v130;
            JUMPOUT(0x1443E8);
          case 0x10u:
            v126 = (void *)(v63 - 240);
            v127 = *(_DWORD *)(a4 + 4);
            *(_BYTE *)(a2 + 29) = v127;
            BYTE1(jpt_124572[3]) = (_BYTE)v126;
            *(_BYTE *)(v6 + 17) = a2;
            jpt_124572[13] = v126;
            *(_DWORD *)(a2 + 20) = v127;
            v128 = *(_DWORD *)(v6 + 68);
            *(_DWORD *)(v128 + 68) = v128;
            *(_BYTE *)(*(__int16 *)(2 * v128) + 0x11) = *(_DWORD *)(*(__int16 *)(2 * v128) + 0x64);
            JUMPOUT(0x1443B0);
          case 0x12u:
            JUMPOUT(0x144380);
          case 0x16u:
LABEL_186:
            v134 = v64 >> 31;
            v6 = 0;
            v64 = v62 << 22;
            v62 <<= 18;
            v63 = v134 << 14;
LABEL_187:
            v135 = *(unsigned __int8 *)v6;
            *(_DWORD *)(v6 + 64) = v135;
            *(_DWORD *)(v135 + 68) = v135;
            v136 = *(_DWORD *)(v135 + 68);
            *(_DWORD *)(v136 + 64) = 77;
            *(_BYTE *)(a4 + 17) = v135;
            v137 = *(_DWORD *)(v136 + 68);
            *(_BYTE *)(v64 + 17) = v63;
            *(_BYTE *)(v63 + 1) = v63 >> 9;
            *(_BYTE *)(v137 + 9) = v63;
            v138 = *(_DWORD *)(v64 + 116);
            *(_BYTE *)(v136 + 13) = v137;
            v139 = *(__int16 *)(v137 + 32);
            *(_DWORD *)(v137 + 112) = v139;
            v140 = 2 * *(unsigned __int8 *)(v139 + 91);
            v141 = *(_DWORD *)(v140 + 68);
            *(_BYTE *)(v64 + 17) = v138;
            *(_BYTE *)(v138 + 1) = 32;
            *(_BYTE *)(v141 + 9) = v138;
            v142 = *(_DWORD *)(v64 + 116);
            *(_BYTE *)(v140 + 13) = v141;
            v143 = *(__int16 *)(v141 + 32);
            *(_DWORD *)(v141 + 112) = 32;
            *(_DWORD *)(v143 + 20) = v64;
            v144 = MEMORY[0x40];
            *(_DWORD *)(v141 + 84) = v141;
            *(_DWORD *)(v144 + 64) = -82;
            v145 = *(_DWORD *)(v62 + 100);
            MEMORY[0xFFFFFFBF] = v145;
            *(_BYTE *)(v144 + 32) = 32;
            *(_DWORD *)(v141 + 20) = *(_DWORD *)(v144 + 16);
            *(_BYTE *)(v64 + 17) = v142;
            *(_BYTE *)(v144 + 9) = v145;
            *(_DWORD *)(v144 + 84) = v142;
            *(_DWORD *)(v144 + 64) = -55;
            *(_DWORD *)(v144 + 20) = v64;
            v146 = (_DWORD *)MEMORY[0xFFFFFF92];
            MEMORY[0xFFFFFFCA] = v145;
            LOWORD(v145) = *(_WORD *)(MEMORY[0xFFFFFF92] - 55);
            *(_DWORD *)(v141 + 112) = -55;
            *(_DWORD *)(v146 + 0x64) = v141;
            *(_DWORD *)(v141 + 84) = v64;
            *(_DWORD *)(v146 + 0x40) = -171;
            *(_DWORD *)(v146 + 0x74) = v64;
            *(_DWORD *)(v146 + 0x40) = -280;
            *(_DWORD *)(v146 + 0x14) = v64;
            MEMORY[0xFFFFFEE9] = v145;
            v147 = MEMORY[0xFFFFFDD0] + 50;
            MEMORY[0xFFFFFF4C] = v142;
            *(_BYTE *)(v147 + 13) = v141;
            *(_BYTE *)(v147 + 17) = -24;
            v147 >>= 9;
            *(_DWORD *)(v141 + 100) = v142;
            *(_DWORD *)(v147 + 64) = 103;
            *(_DWORD *)(v147 + 84) = v141;
            *(_DWORD *)(v147 + 16) = 103;
            MEMORY[0x81] = v141;
            *(_BYTE *)(v147 + 8) = 103;
            MEMORY[0x4E] = *(_DWORD *)(v147 + 20);
            MEMORY[0xA74D9] = v142;
            *(_DWORD *)(v147 + 64) = 102;
            *(_DWORD *)(v147 + 84) = 685173;
            *(_DWORD *)(v147 + 16) = 102;
            MEMORY[0x81] = 685173;
            *(_BYTE *)(v147 + 8) = 102;
            v148 = *(_DWORD *)(v147 + 20);
            MEMORY[0x4E] = v148;
            *(_BYTE *)(v147 + 21) = v147;
            MEMORY[1] = 0;
            MEMORY[0x64] = v4;
            *(_BYTE *)(v148 + 29) = 116;
            v149 = MEMORY[0x64];
            v150 = *(_DWORD *)(v147 + 112);
            *(_BYTE *)(v148 + 17) = 0;
            *(_BYTE *)(v147 + 21) = v147;
            *(_DWORD *)(v147 + 64) = v150;
            *(_DWORD *)(v147 + 52) = v149;
            v150 += 53;
            *(_BYTE *)(v147 + 21) = v147;
            *(_DWORD *)(v147 + 64) = v150;
            *(_DWORD *)(v148 + 68) = v150;
            *(_BYTE *)(v147 + 16) = v150;
            *(_BYTE *)(v147 + 21) = v147;
            MEMORY[0x64] = v4;
            MEMORY[0x15] = v4;
            v151 = v148 >> 9;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_DWORD *)(v151 + 16) = 116;
            *(_DWORD *)(v151 + 52) = v151;
            v152 = *(_DWORD *)((v148 >> 9) + 0x10);
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_BYTE *)(v151 + 8) = v152;
            *(_DWORD *)(v151 + 20) = v151;
            MEMORY[0x14] = v148 >> 9;
            v153 = *(_DWORD *)((v148 >> 9) + 0x10);
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_BYTE *)(v151 + 8) = v153;
            v154 = *(__int16 *)(v148 >> 9);
            *(_DWORD *)(v151 + 68) = 0;
            MEMORY[5] = 0;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_DWORD *)(v151 + 64) = 99;
            *(_DWORD *)(v151 + 52) = v154;
            v155 = *(_DWORD *)((v148 >> 9) + 0x64);
            *(_DWORD *)(v151 + 84) = v154;
            MEMORY[0x15] = v4;
            MEMORY[5] = v155;
            *(_BYTE *)(v151 + 21) = v151;
            *(_BYTE *)v151 = 116;
            MEMORY[0x54] = v155;
            *(_DWORD *)(v151 + 64) = 116;
            *(_DWORD *)(v151 + 52) = v4;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            MEMORY[0x11] = 0;
            v156 = *(_DWORD *)((v148 >> 9) + 0x10);
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_BYTE *)(v151 + 8) = v156;
            v157 = *(_DWORD *)((v148 >> 9) + 0x10);
            *(_BYTE *)(v151 + 21) = v151;
            *(_BYTE *)(v151 + 8) = v157;
            MEMORY[0x15] = v4;
            MEMORY[5] = 0;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_BYTE *)(v151 + 8) = 116;
            v158 = *(__int16 *)(v148 >> 9);
            MEMORY[0x11] = *(_WORD *)(v148 >> 9);
            *(_BYTE *)(v151 + 17) = 0;
            MEMORY[0xD] = 0;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            MEMORY[0x64] = *(_DWORD *)((v148 >> 9) + 0x40);
            v159 = MEMORY[0x64];
            *(_DWORD *)(v158 + 36) = *(_DWORD *)(v158 + 116);
            MEMORY[0x64] = v159;
            MEMORY[0x11] = 0;
            *(_BYTE *)(v151 + 21) = v151;
            MEMORY[1] = 0;
            *(_DWORD *)(v151 + 112) = v159;
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
            *(_DWORD *)(a4 + 84) = v61;
            *(_DWORD *)(v6 + 16) = v61;
            v64 = *(__int16 *)(v6 + 61);
            *(_DWORD *)(a4 + 84) = a4;
LABEL_172:
            a2 = v62 >> 8;
            *(_DWORD *)(a4 + 20) = v63;
            *(_DWORD *)((v62 >> 8) + 0x54) = v64;
LABEL_173:
            *(_BYTE *)(a4 + 1) = a2;
            v103 = *(_DWORD *)(a4 + 20);
            v104 = *(_DWORD *)(v6 + 20);
            *(_DWORD *)(a2 + 20) = a2;
            v105 = v6 >> 20;
            *(_BYTE *)(v104 + 17) = v64;
            *(_DWORD *)(a2 + 84) = v104;
            *(_BYTE *)(*(__int16 *)(v6 + a2) + 9) = v6 >> 20;
            *(_DWORD *)(v104 + 20) = v6 >> 20;
            *(_BYTE *)(v103 + 13) = v6 >> 20;
            *(_DWORD *)(v64 + 20) = v103;
            v106 = *(_DWORD *)(a2 + 68);
            *(_DWORD *)(a2 + 52) = v103;
            *(_BYTE *)(v106 + 17) = v105;
            v63 = 2 * v106;
            *(_BYTE *)(v106 + 9) = v64;
            a2 = *(__int16 *)(2 * a2);
            v64 = *(_DWORD *)(v106 + 116);
            *(_DWORD *)(a2 + 100) = v104;
            a4 = v64;
LABEL_174:
            v107 = *(_DWORD *)(v63 + 84);
            v108 = *(_DWORD *)(v64 + 84);
            *(_BYTE *)(a2 + 9) = v108;
            *(_BYTE *)(v64 + 25) = v108;
            *(_BYTE *)(v107 + 9) = a2;
            v109 = *(_DWORD *)(a4 + 20);
            v110 = *(_DWORD *)(a2 + 100);
            *(_DWORD *)(v109 + 116) = v110;
            *(_BYTE *)(v107 + 17) = a2;
            *(_DWORD *)(a2 + 68) = a2;
            v111 = *(_DWORD *)(*(__int16 *)(2 * a2) + 0x14);
            v112 = *(_DWORD *)(v111 + 116);
            v113 = *(__int16 *)(v112 + v111);
            *(_DWORD *)(v112 + 84) = v112;
            *(_BYTE *)(v112 + 13) = v113;
            v114 = *(_DWORD *)(v111 + 116);
            v115 = *(__int16 *)(2 * v111);
            *(_DWORD *)(v107 + 84) = v110;
            *(_DWORD *)(v115 + 100) = v107;
            v116 = *(_DWORD *)(2 * v114);
            v117 = off_144344;
            v118 = *(char *)(v109 + v114);
            *(_WORD *)(v114 + 61) = (_WORD)off_144344;
            *(_WORD *)(v109 + 60) = v109;
            *(_BYTE *)(v107 + 12) = (_BYTE)v117;
            *(_DWORD *)(v116 + 20) = v113;
            v119 = *(_DWORD *)(v107 + 20);
            *(_DWORD *)(v119 + 64) = v117;
            *(_DWORD *)(v119 + 64) = 111;
            *(_DWORD *)(v117 + 0x54) = v118;
            v120 = *(_DWORD *)(v117 + 0x74);
            *(_BYTE *)(*(unsigned __int8 *)(v119 + 1) + 0xD) = v114;
            *(_BYTE *)(v120 + 17) = v109;
            *(_BYTE *)((v120 >> 9) + 0x11) = v114;
            *(_DWORD *)(v120 + 20) = v120;
            v121 = MEMORY[0x14];
            v122 = *(_DWORD *)(MEMORY[0x14] + 4);
            v123 = *(_DWORD *)(MEMORY[0x14] + 100);
            *(_DWORD *)(MEMORY[0x14] + 20) = v113;
            MEMORY[0x44] = v120;
            *(_DWORD *)(v121 + 96) = 44;
            *(_DWORD *)(v120 + 84) = v113;
            *(_DWORD *)(v121 + 64) = -52;
            *(_WORD *)(v122 + 60) = -52;
            *(_BYTE *)(v121 + 12) = -52;
            *(_DWORD *)(v121 + 20) = v123;
            MEMORY[0x10] = v120;
            *(_BYTE *)(v121 + 9) = v120;
            *(_BYTE *)(v121 + 5) = 61;
            *(_BYTE *)(v121 + 9) = v120;
            *(_BYTE *)(v121 + 5) = 61;
            *(_DWORD *)(v121 + 64) = 12;
            *(_DWORD *)(v121 + 48) = 100;
            MEMORY[0x20] = 100;
            MEMORY[0x1D] = v120;
            *(_BYTE *)(v118 + 1) = v123;
            *(_DWORD *)(v121 + 64) = -89;
            *(_BYTE *)(v121 + 12) = 100;
            *(_DWORD *)(v121 + 64) = -209;
            *(_DWORD *)(v120 + 84) = v122;
            *(_DWORD *)(v120 + 52) = v121;
            *(_DWORD *)(v121 + 64) = -209;
            *(_DWORD *)(v121 + 20) = v123 - 104;
            *(_DWORD *)((v123 >> 8) + 0x44) = v120;
            *(_DWORD *)(v121 + 68) = 100;
            v124 = *(__int16 *)(*(_DWORD *)(v123 + (v123 >> 8)) + (v123 >> 8));
            v125 = v123 + (v122 == 0) + (v123 >> 8);
            MEMORY[0x6C6E] = 2 * v122;
            *(_DWORD *)(v125 + 52) = -v122;
            *(_BYTE *)(v124 + 13) = v125;
            JUMPOUT(0x1442F0);
          default:
            break;
        }
      }
      if ( **v11 >= 0 )
      {
LABEL_24:
        v14 = off_124198;
        v15 = 2;
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
          v60 = (_BYTE *)rf_bus_setup_n3a8(7, a4, v6, 2u);
          v14 = off_124508;
          *v60 = sub_11FAF8((int *)(a2 + 2), *(unsigned __int8 *)a2, *(unsigned __int8 *)(a2 + 8), v60 + 1);
          sub_12CBB4((int)v60);
          v15 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v59 = *(unsigned __int8 *)a2;
          if ( v59 <= 3 )
            sub_11FEF0(v59);
          if ( !*((_DWORD *)off_124544 + 2) )
            sub_12BE54();
          message_dispatch_n84(9, a4, v6);
          v14 = off_124508;
          v15 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v14 = off_124508;
          v58 = *(_DWORD *)a2;
          *(_DWORD *)off_124508 = *(_DWORD *)a2;
          if ( v12 < 0 && *(_DWORD *)off_124868 << 28 )
          {
            sub_12F6C4(dword_12485C, dword_12486C, 472);
            v58 = *(_DWORD *)v14;
          }
          *(_DWORD *)off_124540 = v58 | *((_DWORD *)v14 + 1);
          message_dispatch_n84(15, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v56 = rf_bus_setup_n3a8(17, a4, v6, 2u);
          v14 = off_124508;
          v57 = v56;
          sub_102898((unsigned __int16 *)a2, *(unsigned __int8 *)(a2 + 10));
          sub_12CBB4(v57);
          v15 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v55 = off_12453C;
          v14 = off_124508;
          *(_DWORD *)off_12453C = *(_DWORD *)off_12453C & 0xFFFFFF00 | *(unsigned __int8 *)a2;
          *v55 |= 0x80000000;
          message_dispatch_n84(19, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v53 = *(unsigned __int16 *)a2;
          v54 = dword_124538 + 1320 * *(unsigned __int8 *)(a2 + 2);
          if ( *(_BYTE *)(v54 + 106) )
            sub_1205A8(v54, v53);
          else
            *(_DWORD *)(dword_1244F4 + 696 * *(unsigned __int8 *)(v54 + 116) + 8) = v53 << 10;
          message_dispatch_n84(21, a4, v6);
          v14 = off_124508;
          v15 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v47 = *(char **)a2;
          v48 = *(unsigned __int8 *)(a2 + 5);
          v14 = off_124508;
          v49 = *((_DWORD *)off_124530 + 10);
          v51 = (char *)(*(_DWORD *)a2 & 0xFFFFF1FF);
          v50 = v51 == nullptr;
          v52 = v48 + 4;
          if ( v51 )
            v47 = (char *)off_124508 + 4 * v52;
          else
            v51 = (char *)off_124508 + 4 * v52;
          if ( v50 )
            *((_DWORD *)v51 + 1) = v47;
          else
            *((_DWORD *)v47 + 1) = v51;
          if ( v49 && *(unsigned __int8 *)(v49 + 4) == v48 )
            *(_DWORD *)off_124534 = *(_DWORD *)&v14[4 * v52 + 4];
          message_dispatch_n84(23, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v14 = off_124508;
          sub_14380C((char *)(dword_124524 + 1320 * *(unsigned __int8 *)(a2 + 6)), (char *)a2, 6u);
          v45 = off_12452C;
          v46 = *(unsigned __int16 *)(a2 + 4);
          *(_DWORD *)off_124528 = *(_DWORD *)a2;
          *v45 = v46;
          message_dispatch_n84(25, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v14 = off_124508;
          *(_DWORD *)off_124548 = (*(unsigned __int8 *)a2 << 14) & 0x1C000 | *(_DWORD *)off_124548 & 0xFFFE3FFF;
          message_dispatch_n84(29, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v27 = *(unsigned __int8 *)(a2 + 3);
          v28 = dword_124538;
          v29 = (unsigned __int8 *)(dword_124538 + 1320 * v27);
          *(_DWORD *)(v169 + 0x0) = 0;
          v165 = 1320 * v27;
          v30 = sub_120770(v169);
          v31 = *(_DWORD *)(v29 + 0x1a8);
          v32 = *(unsigned __int8 *)(a2 + 2);
          *(_DWORD *)(v29 + 0x1b0) = v32;
          v160 = v30;
          if ( !v31 )
          {
            v167 = *(_DWORD *)(v29 + 0x1d0);
            if ( v32 )
            {
              v33 = dword_1244F4 + 696 * *(_DWORD *)(v29 + 0x1d0);
              v34 = v165 + 24 + v28;
              timestamp_update_4f60(v34, *((_DWORD *)off_1244F8 + 4) + *(_DWORD *)(v33 + 8));
              *(_WORD *)(v33 + 32) = *(_WORD *)a2;
              sub_120750();
              feature_guard_sdio(
                256,
                dword_1244FC,
                *(unsigned __int8 *)(v33 + 35),
                *(unsigned __int16 *)(v33 + 32),
                *(_DWORD *)(v29 + 0x1320),
                v160);
              v35 = off_124504;
              *(_DWORD *)off_124500 = (unsigned __int16)*(_DWORD *)off_124500 | (*(unsigned __int16 *)a2 << 16);
              if ( (*v35 & 0x8000) != 0 && chip_feature_check() && (*(_DWORD *)(v33 + 4) & 0x20) != 0 )
              {
                sub_101904(*(_WORD *)a2);
                sub_11C750();
                feature_guard_sdio(256, dword_124B9C);
                mmio_set_bit7();
              }
              v14 = off_124508;
              v168 = dword_1244F4 + 696 * v167;
              v36 = v28 + 1320 * v27;
              v37 = *(_DWORD *)(v36 + 4) | 1;
              *(_WORD *)(v168 + 30) = (unsigned int)(((unsigned int)dword_12454C
                                                    * (unsigned __int64)(*(_DWORD *)(v168 + 8)
                                                                       * ((unsigned int)*((unsigned __int16 *)off_124508
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v38 = off_1244F8;
              *(_WORD *)(v36 + 112) = 0;
              *(_BYTE *)(v36 + 114) = 0;
              *(_BYTE *)(v36 + 148) = 0;
              *(_BYTE *)(v36 + 128) = 0;
              *(_DWORD *)(v36 + 124) = 0;
              *(_DWORD *)(v36 + 4) = v37;
              *(_DWORD *)(v36 + 120) = *(_DWORD *)(v38 + 0x10);
              v166 = v36;
              bt_hci_cmd_dispatch((int)v29);
              v39 = *(unsigned __int8 *)(v166 + 1224);
              if ( *(_BYTE *)(v166 + 1224) )
              {
                if ( !v160 )
                  goto LABEL_39;
                v77 = off_124860;
                if ( !*((_DWORD *)off_124860 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124860 + 8) = 0;
                *(_DWORD *)(v77 + 0x90) = 0;
                sub_1296EC();
LABEL_119:
                v78 = **v11;
                *((_DWORD *)v14 + 1) |= 0x10u;
                if ( v78 < 0 && *(_DWORD *)off_124BAC << 28 )
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                *(_DWORD *)off_124894 = *(_DWORD *)v14 | *((_DWORD *)v14 + 1);
                v32 = *(unsigned __int8 *)(a2 + 2);
                goto LABEL_40;
              }
              if ( v160 )
              {
                if ( v160 != 1 )
                  goto LABEL_39;
                v89 = off_124B88;
                if ( v29 == *((unsigned __int8 **)off_124B88 + 8) )
                  goto LABEL_39;
                *((_DWORD *)off_124B88 + 8) = v39;
                v163 = v39;
                timestamp_remove_058(v34);
                *(_DWORD *)(v89 + 0x90) = v163;
                sub_1296EC();
                v32 = *(unsigned __int8 *)(a2 + 2);
              }
              else
              {
                if ( *((_DWORD *)off_12450C + 8) )
                {
LABEL_39:
                  v32 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
                if ( *(_DWORD *)(v169 + 0x0) )
                {
                  if ( *(_DWORD *)(v169 + 0x0) != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v100 = (int *)off_124BA8;
                v101 = *(_DWORD *)(v168 + 8);
                v102 = *(_DWORD *)off_124BA8;
                *((_DWORD *)off_12450C + 8) = v29;
                *v100 = (unsigned __int16)(v101 >> 10) | (HIWORD(v102) << 16);
                timestamp_remove_058(v34);
                *((_BYTE *)off_124B88 + 36) = 0;
                sub_1295B8();
                v32 = *(unsigned __int8 *)(a2 + 2);
              }
            }
            else
            {
              timestamp_remove_058(v165 + 24 + v28);
              nullsub_8();
              feature_guard_sdio(256, dword_124884, *(_DWORD *)(v29 + 0x1320), v160);
              if ( (*(_DWORD *)off_124888 & 0x8000) != 0
                && chip_feature_check()
                && (*(_DWORD *)(dword_124B8C + 696 * v167 + 4) & 0x20) != 0
                && *(_DWORD *)(v29 + 0x1a8) != 4 )
              {
                phy_tbl_lookup_by_idx(*(_DWORD *)(v29 + 0x1ac));
              }
              v67 = v28 + 1320 * v27;
              v68 = *(unsigned __int8 *)(v67 + 1224);
              *(_BYTE *)(v67 + 1227) = 0;
              *(_DWORD *)(v67 + 1228) = 0;
              if ( v68 )
              {
                if ( v160 )
                {
                  v79 = *((unsigned __int8 **)off_124B84 + 2);
                  if ( v79 )
                  {
                    while ( *(_DWORD *)(v79 + 0x1a8) || !*(_DWORD *)(v79 + 0x1b0) || v29 == v79 || *(_DWORD *)(v79 + 0x1320) )
                    {
                      v79 = *(unsigned __int8 **)v79;
                      if ( !v79 )
                        goto LABEL_101;
                    }
                    if ( !*((_DWORD *)off_124B88 + 8) )
                    {
                      v80 = *(_DWORD *)(v79 + 0x1d0);
                      v81 = dword_124B8C;
                      v82 = (int *)off_124BA8;
                      *((_DWORD *)off_124B88 + 8) = v79;
                      *v82 = (unsigned __int16)(*(_DWORD *)(v81 + 696 * v80 + 8) >> 10) | (HIWORD(*v82) << 16);
                      v162 = v79;
                      timestamp_remove_058((int)(v79 + 24));
                      *((_BYTE *)off_124B88 + 36) = 0;
                      v14 = off_124B90;
                      sub_1295B8();
                      v83 = **v11;
                      v84 = v162;
                      *((_DWORD *)v14 + 1) &= ~0x10u;
                      if ( v83 < 0 && *(_DWORD *)off_124BAC << 28 )
                      {
                        sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                        v84 = v162;
                      }
                      v85 = off_124BB8;
                      *(_DWORD *)off_124B94 = *(_DWORD *)v14 | *((_DWORD *)v14 + 1);
                      v86 = off_124B98;
                      v87 = *((_DWORD *)v84 + 16);
                      v88 = *((unsigned __int16 *)v84 + 34);
                      *v85 = v87;
                      *v86 = v88;
                      v32 = *(unsigned __int8 *)(a2 + 2);
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v160 == 2 )
              {
                v94 = off_124B88;
                if ( !*((_DWORD *)off_124B88 + 8) )
                {
                  v95 = *((unsigned __int8 **)off_124B84 + 2);
                  if ( !v95 )
LABEL_169:
                    __und(0xFFu);
                  while ( *(_DWORD *)(v95 + 0x1a8) || !*(_DWORD *)(v95 + 0x1b0) || v29 == v95 || *(_DWORD *)(v95 + 0x1320) )
                  {
                    v95 = *(unsigned __int8 **)v95;
                    if ( !v95 )
                      goto LABEL_169;
                  }
                  v96 = (int *)off_124BA8;
                  v164 = *(_DWORD *)(v95 + 0x1320);
                  v97 = *(_DWORD *)off_124BA8;
                  v98 = *(_DWORD *)(dword_124B8C + 696 * *(_DWORD *)(v95 + 0x1d0) + 8);
                  *((_DWORD *)off_124B88 + 8) = v95;
                  *v96 = (unsigned __int16)(v98 >> 10) | (HIWORD(v97) << 16);
                  timestamp_remove_058((int)(v95 + 24));
                  *(_DWORD *)(v94 + 0x90) = v164;
                  v14 = off_124B90;
                  sub_1295B8();
                  v32 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
              }
              else if ( v160 == 1 )
              {
                v99 = off_124B88;
                if ( v29 == *((unsigned __int8 **)off_124B88 + 8) )
                {
                  *((_DWORD *)off_124B88 + 8) = 0;
                  *(_DWORD *)(v99 + 0x90) = 0;
                  v14 = off_124B90;
                  sub_1296EC();
                  v32 = *(unsigned __int8 *)(a2 + 2);
                  goto LABEL_40;
                }
              }
LABEL_101:
              v32 = *(unsigned __int8 *)(a2 + 2);
              v14 = off_124864;
            }
LABEL_40:
            sub_12A2B4(v29, v32);
            if ( *(_BYTE *)(a2 + 2) )
            {
              v40 = *(_DWORD **)off_124510;
              v41 = **(_DWORD **)off_124510;
              if ( v41 )
                *(_DWORD *)off_124514 = v41;
              else
                *(_DWORD *)off_124880 = *(_DWORD *)(v28 + 1320 * v27 + 8);
              v42 = *(_DWORD *)(v40 + 0x4);
              if ( v42 )
              {
                if ( (v42 & 0xFFF) != 0 )
                  *(_DWORD *)off_12487C = v42;
                else
                  *(_DWORD *)off_124518 = v42 & 0xFFFFF000 | *(_DWORD *)(v28 + 1320 * v27 + 12) & 0xFFF;
              }
              else
              {
                *(_DWORD *)off_12487C = *(_DWORD *)(v28 + 1320 * v27 + 12);
              }
              v43 = *(_DWORD *)(v40 + 0x8);
              if ( v43 )
                *(_DWORD *)off_12451C = v43;
              else
                *(_DWORD *)off_124878 = *(_DWORD *)(v28 + 1320 * v27 + 16);
              v44 = *(_DWORD *)(v40 + 0xc);
              if ( v44 )
                *(_DWORD *)off_124520 = v44;
              else
                *(_DWORD *)off_12488C = *(_DWORD *)(v28 + 1320 * v27 + 20);
              chip_version_read_12207E0();
            }
            message_dispatch_n84(31, a4, v6);
            v15 = 0;
            goto LABEL_10;
          }
          if ( !v30 )
          {
            if ( v32 )
            {
              v65 = nullptr;
              goto LABEL_84;
            }
LABEL_85:
            v14 = off_124864;
            goto LABEL_40;
          }
          v65 = *((unsigned __int8 **)off_124890 + 2);
          if ( v65 )
          {
            do
            {
              if ( !*(_DWORD *)(v65 + 0x1a8) && *(_DWORD *)(v65 + 0x1b0) && v29 != v65 && !*(_DWORD *)(v65 + 0x1320) )
                break;
              v65 = *(unsigned __int8 **)v65;
            }
            while ( v65 );
            if ( !v32 )
            {
              v69 = off_124860;
              if ( !*((_DWORD *)off_124860 + 8) && v65 )
              {
                *((_DWORD *)off_124860 + 8) = v65;
                *(_DWORD *)(v69 + 0x90) = 0;
                v161 = v65;
                v14 = off_124864;
                timestamp_remove_058((int)(v65 + 24));
                sub_1295B8();
                v70 = **v11;
                v71 = v161;
                *((_DWORD *)v14 + 1) &= ~0x10u;
                if ( v70 < 0 && *(_DWORD *)off_124BAC << 28 )
                {
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                  v71 = v161;
                }
                v72 = off_1248A4;
                v73 = *((_DWORD *)v71 + 16);
                *(_DWORD *)off_124894 = *(_DWORD *)v14 | *((_DWORD *)v14 + 1);
                v74 = off_124898;
                v75 = *((unsigned __int16 *)v71 + 34);
                *v72 = v73;
                v76 = off_12489C;
                *v74 = v75;
                *v76 = dword_1248A0;
                *(_DWORD *)(v74 + 0x8050) &= 0xFFFBFFFE;
                goto LABEL_39;
              }
              goto LABEL_85;
            }
          }
          else if ( !v32 )
          {
            goto LABEL_85;
          }
LABEL_84:
          v66 = off_124860;
          if ( v65 == *((unsigned __int8 **)off_124860 + 8) )
          {
            *((_DWORD *)off_124860 + 8) = 0;
            *(_DWORD *)(v66 + 0x90) = 0;
            v14 = off_124B90;
            sub_1296EC();
            v90 = **v11;
            *((_DWORD *)v14 + 1) |= 0x10u;
            if ( v90 < 0 && *(_DWORD *)off_124BAC << 28 )
              sub_12F6C4(dword_124BB4, dword_124BB0, 472);
            v91 = off_124B94;
            v92 = off_124BA0;
            *(_DWORD *)off_124B94 = *(_DWORD *)v14 | *((_DWORD *)v14 + 1);
            v93 = dword_124BA4;
            *v92 = dword_124BA4;
            *(_DWORD *)(v91 + 0x8014) |= v93;
            v32 = *(unsigned __int8 *)(a2 + 2);
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v14 = off_124198;
          *(_DWORD *)off_1241BC = *(unsigned __int8 *)a2
                                | (((unsigned __int8)*(_DWORD *)off_1241B8 * *(unsigned __int8 *)a2) << 8);
          message_dispatch_n84(33, a4, v6);
          v15 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v16 = *(_BYTE *)a2;
          if ( *(_BYTE *)a2 )
          {
            if ( sub_13A490(
                   dword_124870 + 696 * *(unsigned __int8 *)(a2 + 1),
                   *(unsigned __int8 *)(a2 + 2),
                   *(_WORD *)(a2 + 6)) )
            {
              *(_DWORD *)off_124874 |= 0x80u;
              v16 = 0;
            }
            else
            {
              v16 = 4;
            }
          }
          else
          {
            v17 = *(unsigned __int16 *)(a2 + 4);
            v18 = *(_DWORD *)(dword_1241AC + 4 * *(unsigned __int8 *)(dword_1241A8 + *(unsigned __int8 *)(a2 + 2)));
            if ( (int)v17 >= v18 )
            {
              if ( v17 > 0x40 )
                LOWORD(v19) = *(_DWORD *)(dword_1241AC
                                        + 4 * *(unsigned __int8 *)(dword_1241A8 + *(unsigned __int8 *)(a2 + 2)));
              else
                LOWORD(v19) = v18 / 2;
            }
            else
            {
              v19 = v17 >> 1;
            }
            sub_12ECB0(dword_1241B0);
            v20 = *(_WORD *)(a2 + 4);
            v21 = 696 * *(unsigned __int8 *)(a2 + 1);
            v22 = *(unsigned __int8 *)(v21 + 12 * *(unsigned __int8 *)(a2 + 2) + dword_1241C0 + 453);
            v23 = *(_WORD *)(a2 + 6);
            v24 = v21 + 6 * *(unsigned __int8 *)(a2 + 2) + dword_1241C0;
            v25 = dword_1241B4 + 32 * v22;
            *(_WORD *)(v24 + 354) = v19;
            *(_WORD *)(v24 + 356) = v20;
            *(_WORD *)(v25 + 12) = v23;
          }
          v26 = (_BYTE *)rf_bus_setup_n3a8(41, a4, v6, 3u);
          *v26 = *(_BYTE *)(a2 + 1);
          *(_DWORD *)(v26 + 0x4) = *(_BYTE *)(a2 + 2);
          *(_DWORD *)(v26 + 0x8) = v16;
          sub_12CBB4((int)v26);
          v14 = off_124198;
          v15 = 0;
          goto LABEL_10;
        case 0x30u:
LABEL_26:
          sub_12F6E0();
          v14 = off_124198;
          v15 = 0;
          goto LABEL_10;
        case 0x3Bu:
LABEL_25:
          sub_1280C8((unsigned __int8 *)a2);
          message_dispatch_n84(60, a4, v6);
          v14 = off_124198;
          v15 = 0;
          goto LABEL_10;
        default:
          break;
      }
    }
    v14 = off_124198;
    sub_12F694(dword_1241A4, dword_1241A0, 2552);
    v15 = 2;
LABEL_10:
    *(_DWORD *)off_124194 = (unsigned __int8)(16 * *(_DWORD *)(v14 + 0x4c));
    rf_bus_mark_n_3b7(v6, (unsigned __int8)*(_DWORD *)(v14 + 0x48));
    return v15;
  }
  if ( (unsigned __int16)(value - 2) > 2u )
  {
    v13 = off_124198;
    *((_BYTE *)off_124198 + 19) = *(_BYTE *)off_124194 & 0xF;
    *(_DWORD *)(v13 + 0x48) = msg_get_value(v6);
    sub_12BA2C();
    rf_bus_mark_n_3b7(v6, 2);
  }
  return 2;
}
