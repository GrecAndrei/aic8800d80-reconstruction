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

extern uint32_t off_1241C4;
extern uint32_t off_124198;
extern uint32_t dword_12419C;
extern uint32_t off_124194;
extern uint32_t dword_12485C;
extern uint32_t dword_124858;
extern uint32_t off_144344;
extern uint32_t off_124508;
extern uint32_t off_124544;
extern uint32_t off_124868;
extern uint32_t dword_12486C;
extern uint32_t off_124540;
extern uint32_t off_12453C;
extern uint32_t dword_124538;
extern uint32_t dword_1244F4;
extern uint32_t off_124530;
extern uint32_t off_124534;
extern uint32_t dword_124524;
extern uint32_t off_12452C;
extern uint32_t off_124528;
extern uint32_t off_124548;
extern uint32_t off_1244F8;
extern uint32_t dword_1244FC;
extern uint32_t off_124504;
extern uint32_t off_124500;
extern uint32_t dword_124B9C;
extern uint32_t dword_12454C;
extern uint32_t off_124860;
extern uint32_t off_124BAC;
extern uint32_t dword_124BB4;
extern uint32_t dword_124BB0;
extern uint32_t off_124894;
extern uint32_t off_124B88;
extern uint32_t off_12450C;
extern uint32_t off_124BA8;
extern uint32_t dword_124884;
extern uint32_t off_124888;
extern uint32_t dword_124B8C;
extern uint32_t off_124B84;
extern uint32_t off_124B90;
extern uint32_t off_124BB8;
extern uint32_t off_124B94;
extern uint32_t off_124B98;
extern uint32_t off_124864;
extern uint32_t off_124510;
extern uint32_t off_124514;
extern uint32_t off_124880;
extern uint32_t off_12487C;
extern uint32_t off_124518;
extern uint32_t off_12451C;
extern uint32_t off_124878;
extern uint32_t off_124520;
extern uint32_t off_12488C;
extern uint32_t off_124890;
extern uint32_t off_1248A4;
extern uint32_t off_124898;
extern uint32_t off_12489C;
extern uint32_t dword_1248A0;
extern uint32_t off_124BA0;
extern uint32_t dword_124BA4;
extern uint32_t off_1241B8;
extern uint32_t off_1241BC;
extern uint32_t dword_124870;
extern uint32_t off_124874;
extern uint32_t dword_1241AC;
extern uint32_t dword_1241A8;
extern uint32_t dword_1241B0;
extern uint32_t dword_1241C0;
extern uint32_t dword_1241B4;
extern uint32_t dword_1241A4;
extern uint32_t dword_1241A0;

// sub_123EC0 @ 0x123ec0, size 3268 bytes
int  sub_123EC0(unsigned int a1, int a2, uint8_t *a3, int a4)
{
  int v4; // r9
  unsigned int v6; // r4
  int value; // r0
  int v10; // r1
  int16_t **v12; // r8
  int v13; // r3
  uint8_t *v14; // r5
  int v15; // r0
  uint8_t *v16; // r7
  int v17; // r6
  int v18; // r3
  char v19; // r7
  int v20; // r1
  unsigned int v21; // r2
  signed int v22; // r3
  unsigned int v23; // r8
  int16_t v24; // lr
  int v25; // r2
  int v26; // r3
  int16_t v27; // r1
  int v28; // r2
  int v29; // r3
  uint8_t *v30; // r0
  int v31; // r3
  int v32; // r11
  int v33; // r10
  uint8_t *v34; // r9
  int v35; // r0
  int v36; // r2
  int v37; // r1
  int v38; // r7
  int v39; // s16
  uint32_t *v40; // r1
  int v41; // r3
  int v42; // r12
  uint32_t *v43; // r0
  int v44; // r0
  int v45; // r3
  int v46; // r3
  uint32_t *v47; // r3
  int v48; // r2
  int v49; // r2
  int v50; // r2
  int v51; // r3
  uint32_t *v52; // r3
  int v53; // r2
  int v54; // r3
  int v55; // r1
  int v56; // r0
  int v57; // zf
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
  uint8_t *v72; // r6
  int v73; // r0
  unsigned int v74; // r1
  unsigned int v75; // r7
  int v76; // r3
  uint8_t *v77; // r3
  uint8_t *v78; // r2
  int v79; // r0
  int v80; // r0
  int v81; // r3
  int v82; // r1
  uint8_t *v83; // r2
  int v84; // r0
  int v85; // r1
  uint8_t *v86; // r3
  uint32_t *v87; // lr
  int v88; // r12
  uint32_t *v89; // r2
  int v90; // r0
  uint32_t *v91; // r3
  uint8_t *v92; // r3
  int v93; // r2
  uint8_t *v94; // r3
  int v95; // r0
  int v96; // r7
  int *v97; // r12
  int v98; // r0
  int v99; // r1
  uint8_t *v100; // r3
  uint32_t *v101; // r12
  uint32_t *v102; // r2
  int v103; // r0
  int v104; // r3
  uint8_t *v105; // r8
  int v106; // r0
  int v107; // r2
  uint32_t *v108; // r2
  uint32_t *v109; // r0
  int v110; // r1
  uint8_t *v111; // r8
  uint8_t *v112; // r0
  int *v113; // r1
  unsigned int v114; // r12
  unsigned int v115; // r3
  int v116; // r0
  uint8_t *v117; // r3
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
  uint32_t *v136; // r5
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
  uint32_t *v152; // r4
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
  uint32_t *v165; // r4
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
  uint8_t *v180; // [sp+Ch] [bp-18h]
  uint8_t *v181; // [sp+Ch] [bp-18h]
  char v182; // [sp+Ch] [bp-18h]
  uint8_t v183; // [sp+Ch] [bp-18h]
  int v184; // [sp+10h] [bp-14h]
  int v185; // [sp+10h] [bp-14h]
  int v186; // [sp+14h] [bp-10h]
  int v187; // [sp+14h] [bp-10h]
  uint8_t v188[8]; // [sp+1Ch] [bp-8h] BYREF

  v6 = (unsigned int)a3;
  value = msg_get_value(a3);
  if ( !value )
  {
    v12 = (int16_t **)off_1241C4;
    v13 = **(int16_t **)off_1241C4;
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
        *((uint8_t *)off_124198 + 48) = 0;
        v17 = sub_12BEE8(*(uint32_t *)a2);
        if ( v17 )
        {
          sub_121BE4(*(uint32_t *)a2);
          v17 = 0;
        }
        else if ( v16[49] )
        {
          v16[49] = 0;
          if ( sub_126664(v188) )
            bt_link_lookup_entry(
              *(uint8_t *)(*(uint32_t *)v188 + 1225),
              dword_12419C + 38 * *(uint8_t *)(*(uint32_t *)v188 + 107));
        }
        goto LABEL_10;
      }
      goto LABEL_24;
    }
    if ( *(uint32_t *)off_124194 << 28 )
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
            *(uint8_t *)(a4 + 17) = (uint8_t)jpt_124572;
            jpt_124572[9] = (_UNKNOWN *)v75;
            *(uint8_t *)(v6 + 13) = v74;
            v73 = *(uint32_t *)((v74 >> 8) + 0x74);
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
            *(uint8_t *)(v6 + 12) = 0;
            a2 = 0;
LABEL_184:
            *(uint32_t *)(a4 + 52) = v6;
            *(uint8_t *)(v76 + 13) = v75;
            *(uint8_t *)(a4 + 21) = v73;
            *(uint8_t *)(a2 + 21) = v75;
            v74 = *(uint32_t *)(a2 + 100);
            *(uint32_t *)(a4 + 52) = v6;
            *(uint8_t *)(2 * a4 + 0xD) = v75;
            *(uint8_t *)(a4 + 21) = v73;
            v151 = *(uint32_t *)(a4 + 20);
            *(uint8_t *)(a2 + 21) = v75;
            v76 = 2 * a4;
            *(uint32_t *)(v6 + 84) = v151;
            a4 = *(uint32_t *)(v6 + 116);
            *(uint32_t *)(a4 + 84) = v151;
            a2 = 32;
LABEL_185:
            *(uint32_t *)(v6 + 64) = a2;
            *(uint32_t *)(v6 + 52) = v6;
            v152 = (uint32_t *)(v6 + 37);
            v152[25] = v74;
            *(uint32_t *)(a4 + 84) = v152;
            v152[16] = 32;
            v152[13] = v152;
            goto LABEL_186;
          case 0xCu:
            v150 = *(uint32_t *)(v6 + 4);
            *(uint32_t *)(a2 + 84) = a4;
            *(uint8_t *)(a4 + 17) = v150;
            *(uint8_t *)(a2 + 1) = v75;
            JUMPOUT(0x144418);
          case 0xEu:
            v148 = *(uint8_t *)(a4 + 1);
            *(uint8_t *)(a4 + 29) = v73;
            *(uint32_t *)(a2 + 84) = v148;
            *(uint32_t *)(a4 + 84) = a4;
            v149 = *(uint32_t *)(a4 + 4);
            *(uint8_t *)(a2 + 29) = v149;
            BYTE1(jpt_124572[3]) = v75;
            *(uint8_t *)(2 * a2 + 0x11) = a2;
            jpt_124572[13] = (_UNKNOWN *)v75;
            *(uint32_t *)(a2 + 20) = v149;
            JUMPOUT(0x1443E8);
          case 0x10u:
            v145 = (void *)(v75 - 240);
            v146 = *(uint32_t *)(a4 + 4);
            *(uint8_t *)(a2 + 29) = v146;
            BYTE1(jpt_124572[3]) = (uint8_t)v145;
            *(uint8_t *)(v6 + 17) = a2;
            jpt_124572[13] = v145;
            *(uint32_t *)(a2 + 20) = v146;
            v147 = *(uint32_t *)(v6 + 68);
            *(uint32_t *)(v147 + 68) = v147;
            *(uint8_t *)(*(int16_t *)(2 * v147) + 0x11) = *(uint32_t *)(*(int16_t *)(2 * v147) + 0x64);
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
            v154 = *(uint8_t *)v6;
            *(uint32_t *)(v6 + 64) = v154;
            *(uint32_t *)(v154 + 68) = v154;
            v155 = *(uint32_t *)(v154 + 68);
            *(uint32_t *)(v155 + 64) = 77;
            *(uint8_t *)(a4 + 17) = v154;
            v156 = *(uint32_t *)(v155 + 68);
            *(uint8_t *)(v76 + 17) = v75;
            *(uint8_t *)(v75 + 1) = v75 >> 9;
            *(uint8_t *)(v156 + 9) = v75;
            v157 = *(uint32_t *)(v76 + 116);
            *(uint8_t *)(v155 + 13) = v156;
            v158 = *(int16_t *)(v156 + 32);
            *(uint32_t *)(v156 + 112) = v158;
            v159 = 2 * *(uint8_t *)(v158 + 91);
            v160 = *(uint32_t *)(v159 + 68);
            *(uint8_t *)(v76 + 17) = v157;
            *(uint8_t *)(v157 + 1) = 32;
            *(uint8_t *)(v160 + 9) = v157;
            v161 = *(uint32_t *)(v76 + 116);
            *(uint8_t *)(v159 + 13) = v160;
            v162 = *(int16_t *)(v160 + 32);
            *(uint32_t *)(v160 + 112) = 32;
            *(uint32_t *)(v162 + 20) = v76;
            v163 = MEMORY[0x40];
            *(uint32_t *)(v160 + 84) = v160;
            *(uint32_t *)(v163 + 64) = -82;
            v164 = *(uint32_t *)(v74 + 100);
            MEMORY[0xFFFFFFBF] = v164;
            *(uint8_t *)(v163 + 32) = 32;
            *(uint32_t *)(v160 + 20) = *(uint32_t *)(v163 + 16);
            *(uint8_t *)(v76 + 17) = v161;
            *(uint8_t *)(v163 + 9) = v164;
            *(uint32_t *)(v163 + 84) = v161;
            *(uint32_t *)(v163 + 64) = -55;
            *(uint32_t *)(v163 + 20) = v76;
            v165 = (uint32_t *)MEMORY[0xFFFFFF92];
            MEMORY[0xFFFFFFCA] = v164;
            LOWORD(v164) = *(uint16_t *)(MEMORY[0xFFFFFF92] - 55);
            *(uint32_t *)(v160 + 112) = -55;
            v165[25] = v160;
            *(uint32_t *)(v160 + 84) = v76;
            v165[16] = -171;
            v165[29] = v76;
            v165[16] = -280;
            v165[5] = v76;
            MEMORY[0xFFFFFEE9] = v164;
            v166 = MEMORY[0xFFFFFDD0] + 50;
            MEMORY[0xFFFFFF4C] = v161;
            *(uint8_t *)(v166 + 13) = v160;
            *(uint8_t *)(v166 + 17) = -24;
            v166 >>= 9;
            *(uint32_t *)(v160 + 100) = v161;
            *(uint32_t *)(v166 + 64) = 103;
            *(uint32_t *)(v166 + 84) = v160;
            *(uint32_t *)(v166 + 16) = 103;
            MEMORY[0x81] = v160;
            *(uint8_t *)(v166 + 8) = 103;
            MEMORY[0x4E] = *(uint32_t *)(v166 + 20);
            MEMORY[0xA74D9] = v161;
            *(uint32_t *)(v166 + 64) = 102;
            *(uint32_t *)(v166 + 84) = 685173;
            *(uint32_t *)(v166 + 16) = 102;
            MEMORY[0x81] = 685173;
            *(uint8_t *)(v166 + 8) = 102;
            v167 = *(uint32_t *)(v166 + 20);
            MEMORY[0x4E] = v167;
            *(uint8_t *)(v166 + 21) = v166;
            MEMORY[1] = 0;
            MEMORY[0x64] = v4;
            *(uint8_t *)(v167 + 29) = 116;
            v168 = MEMORY[0x64];
            v169 = *(uint32_t *)(v166 + 112);
            *(uint8_t *)(v167 + 17) = 0;
            *(uint8_t *)(v166 + 21) = v166;
            *(uint32_t *)(v166 + 64) = v169;
            *(uint32_t *)(v166 + 52) = v168;
            v169 += 53;
            *(uint8_t *)(v166 + 21) = v166;
            *(uint32_t *)(v166 + 64) = v169;
            *(uint32_t *)(v167 + 68) = v169;
            *(uint8_t *)(v166 + 16) = v169;
            *(uint8_t *)(v166 + 21) = v166;
            MEMORY[0x64] = v4;
            MEMORY[0x15] = v4;
            v170 = v167 >> 9;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint32_t *)(v170 + 16) = 116;
            *(uint32_t *)(v170 + 52) = v170;
            v171 = *(uint32_t *)((v167 >> 9) + 0x10);
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint8_t *)(v170 + 8) = v171;
            *(uint32_t *)(v170 + 20) = v170;
            MEMORY[0x14] = v167 >> 9;
            v172 = *(uint32_t *)((v167 >> 9) + 0x10);
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint8_t *)(v170 + 8) = v172;
            v173 = *(int16_t *)(v167 >> 9);
            *(uint32_t *)(v170 + 68) = 0;
            MEMORY[5] = 0;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint32_t *)(v170 + 64) = 99;
            *(uint32_t *)(v170 + 52) = v173;
            v174 = *(uint32_t *)((v167 >> 9) + 0x64);
            *(uint32_t *)(v170 + 84) = v173;
            MEMORY[0x15] = v4;
            MEMORY[5] = v174;
            *(uint8_t *)(v170 + 21) = v170;
            *(uint8_t *)v170 = 116;
            MEMORY[0x54] = v174;
            *(uint32_t *)(v170 + 64) = 116;
            *(uint32_t *)(v170 + 52) = v4;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            MEMORY[0x11] = 0;
            v175 = *(uint32_t *)((v167 >> 9) + 0x10);
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint8_t *)(v170 + 8) = v175;
            v176 = *(uint32_t *)((v167 >> 9) + 0x10);
            *(uint8_t *)(v170 + 21) = v170;
            *(uint8_t *)(v170 + 8) = v176;
            MEMORY[0x15] = v4;
            MEMORY[5] = 0;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint8_t *)(v170 + 8) = 116;
            v177 = *(int16_t *)(v167 >> 9);
            MEMORY[0x11] = *(uint16_t *)(v167 >> 9);
            *(uint8_t *)(v170 + 17) = 0;
            MEMORY[0xD] = 0;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            MEMORY[0x64] = *(uint32_t *)((v167 >> 9) + 0x40);
            v178 = MEMORY[0x64];
            *(uint32_t *)(v177 + 36) = *(uint32_t *)(v177 + 116);
            MEMORY[0x64] = v178;
            MEMORY[0x11] = 0;
            *(uint8_t *)(v170 + 21) = v170;
            MEMORY[1] = 0;
            *(uint32_t *)(v170 + 112) = v178;
            *(uint8_t *)(MEMORY[0x74] + 17) = MEMORY[0];
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
            *(uint8_t *)(a4 + 17) = (uint8_t)jpt_124572;
            v6 = *(uint8_t *)(a4 + 5);
            *(uint32_t *)(a4 + 84) = v73;
            *(uint32_t *)(v6 + 16) = v73;
            v76 = *(int16_t *)(v6 + 61);
            *(uint32_t *)(a4 + 84) = a4;
LABEL_172:
            a2 = v74 >> 8;
            *(uint32_t *)(a4 + 20) = v75;
            *(uint32_t *)((v74 >> 8) + 0x54) = v76;
LABEL_173:
            *(uint8_t *)(a4 + 1) = a2;
            v122 = *(uint32_t *)(a4 + 20);
            v123 = *(uint32_t *)(v6 + 20);
            *(uint32_t *)(a2 + 20) = a2;
            v124 = v6 >> 20;
            *(uint8_t *)(v123 + 17) = v76;
            *(uint32_t *)(a2 + 84) = v123;
            *(uint8_t *)(*(int16_t *)(v6 + a2) + 9) = v6 >> 20;
            *(uint32_t *)(v123 + 20) = v6 >> 20;
            *(uint8_t *)(v122 + 13) = v6 >> 20;
            *(uint32_t *)(v76 + 20) = v122;
            v125 = *(uint32_t *)(a2 + 68);
            *(uint32_t *)(a2 + 52) = v122;
            *(uint8_t *)(v125 + 17) = v124;
            v75 = 2 * v125;
            *(uint8_t *)(v125 + 9) = v76;
            a2 = *(int16_t *)(2 * a2);
            v76 = *(uint32_t *)(v125 + 116);
            *(uint32_t *)(a2 + 100) = v123;
            a4 = v76;
LABEL_174:
            v126 = *(uint32_t *)(v75 + 84);
            v127 = *(uint32_t *)(v76 + 84);
            *(uint8_t *)(a2 + 9) = v127;
            *(uint8_t *)(v76 + 25) = v127;
            *(uint8_t *)(v126 + 9) = a2;
            v128 = *(uint32_t *)(a4 + 20);
            v129 = *(uint32_t *)(a2 + 100);
            *(uint32_t *)(v128 + 116) = v129;
            *(uint8_t *)(v126 + 17) = a2;
            *(uint32_t *)(a2 + 68) = a2;
            v130 = *(uint32_t *)(*(int16_t *)(2 * a2) + 0x14);
            v131 = *(uint32_t *)(v130 + 116);
            v132 = *(int16_t *)(v131 + v130);
            *(uint32_t *)(v131 + 84) = v131;
            *(uint8_t *)(v131 + 13) = v132;
            v133 = *(uint32_t *)(v130 + 116);
            v134 = *(int16_t *)(2 * v130);
            *(uint32_t *)(v126 + 84) = v129;
            *(uint32_t *)(v134 + 100) = v126;
            v135 = *(uint32_t *)(2 * v133);
            v136 = off_144344;
            v137 = *(char *)(v128 + v133);
            *(uint16_t *)(v133 + 61) = (uint16_t)off_144344;
            *(uint16_t *)(v128 + 60) = v128;
            *(uint8_t *)(v126 + 12) = (uint8_t)v136;
            *(uint32_t *)(v135 + 20) = v132;
            v138 = *(uint32_t *)(v126 + 20);
            *(uint32_t *)(v138 + 64) = v136;
            *(uint32_t *)(v138 + 64) = 111;
            v136[21] = v137;
            v139 = v136[29];
            *(uint8_t *)(*(uint8_t *)(v138 + 1) + 0xD) = v133;
            *(uint8_t *)(v139 + 17) = v128;
            *(uint8_t *)((v139 >> 9) + 0x11) = v133;
            *(uint32_t *)(v139 + 20) = v139;
            v140 = MEMORY[0x14];
            v141 = *(uint32_t *)(MEMORY[0x14] + 4);
            v142 = *(uint32_t *)(MEMORY[0x14] + 100);
            *(uint32_t *)(MEMORY[0x14] + 20) = v132;
            MEMORY[0x44] = v139;
            *(uint32_t *)(v140 + 96) = 44;
            *(uint32_t *)(v139 + 84) = v132;
            *(uint32_t *)(v140 + 64) = -52;
            *(uint16_t *)(v141 + 60) = -52;
            *(uint8_t *)(v140 + 12) = -52;
            *(uint32_t *)(v140 + 20) = v142;
            MEMORY[0x10] = v139;
            *(uint8_t *)(v140 + 9) = v139;
            *(uint8_t *)(v140 + 5) = 61;
            *(uint8_t *)(v140 + 9) = v139;
            *(uint8_t *)(v140 + 5) = 61;
            *(uint32_t *)(v140 + 64) = 12;
            *(uint32_t *)(v140 + 48) = 100;
            MEMORY[0x20] = 100;
            MEMORY[0x1D] = v139;
            *(uint8_t *)(v137 + 1) = v142;
            *(uint32_t *)(v140 + 64) = -89;
            *(uint8_t *)(v140 + 12) = 100;
            *(uint32_t *)(v140 + 64) = -209;
            *(uint32_t *)(v139 + 84) = v141;
            *(uint32_t *)(v139 + 52) = v140;
            *(uint32_t *)(v140 + 64) = -209;
            *(uint32_t *)(v140 + 20) = v142 - 104;
            *(uint32_t *)((v142 >> 8) + 0x44) = v139;
            *(uint32_t *)(v140 + 68) = 100;
            v143 = *(int16_t *)(*(uint32_t *)(v142 + (v142 >> 8)) + (v142 >> 8));
            v144 = v142 + (v141 == 0) + (v142 >> 8);
            MEMORY[0x6C6E] = 2 * v141;
            *(uint32_t *)(v144 + 52) = -v141;
            *(uint8_t *)(v143 + 13) = v144;
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
          v72 = (uint8_t *)rf_bus_setup_n3a8(7, a4, v6, 2);
          v16 = off_124508;
          *v72 = sub_11FAF8((int *)(a2 + 2), *(uint8_t *)a2, *(uint8_t *)(a2 + 8), v72 + 1);
          sub_12CBB4(v72);
          v17 = 0;
          goto LABEL_10;
        case 8u:
LABEL_70:
          v69 = *(uint8_t *)a2;
          if ( v69 <= 3 )
            v69 = sub_11FEF0(v69);
          v70 = *((uint32_t *)off_124544 + 2);
          if ( !v70 )
            sub_12BE54(v69, v10);
          message_dispatch_n84(9, a4, v6, v70);
          v16 = off_124508;
          v17 = 0;
          goto LABEL_10;
        case 0xEu:
LABEL_68:
          v16 = off_124508;
          v67 = *(uint32_t *)a2;
          *(uint32_t *)off_124508 = *(uint32_t *)a2;
          if ( v13 < 0 && *(uint32_t *)off_124868 << 28 )
          {
            sub_12F6C4(dword_12485C, dword_12486C, 472);
            v67 = *(uint32_t *)v16;
          }
          v68 = off_124540;
          *(uint32_t *)off_124540 = v67 | *((uint32_t *)v16 + 1);
          message_dispatch_n84(15, a4, v6, v68);
          v17 = 0;
          goto LABEL_10;
        case 0x10u:
LABEL_67:
          v65 = rf_bus_setup_n3a8(17, a4, v6, 2);
          v16 = off_124508;
          v66 = v65;
          sub_102898((uint16_t *)a2, *(uint8_t *)(a2 + 10));
          sub_12CBB4(v66);
          v17 = 0;
          goto LABEL_10;
        case 0x12u:
LABEL_66:
          v63 = (unsigned int *)off_12453C;
          v16 = off_124508;
          *(uint32_t *)off_12453C = *(uint32_t *)off_12453C & 0xFFFFFF00 | *(uint8_t *)a2;
          v64 = *v63 | 0x80000000;
          *v63 = v64;
          message_dispatch_n84(19, a4, v6, v64);
          v17 = 0;
          goto LABEL_10;
        case 0x14u:
LABEL_63:
          v60 = *(uint16_t *)a2;
          v61 = dword_124538 + 1320 * *(uint8_t *)(a2 + 2);
          if ( *(uint8_t *)(v61 + 106) )
          {
            sub_1205A8(v61, v60);
          }
          else
          {
            v62 = dword_1244F4 + 696 * *(uint8_t *)(v61 + 116);
            *(uint32_t *)(v62 + 8) = v60 << 10;
          }
          message_dispatch_n84(21, a4, v6, v62);
          v16 = off_124508;
          v17 = 0;
          goto LABEL_10;
        case 0x16u:
LABEL_53:
          v54 = *(uint32_t *)a2;
          v55 = *(uint8_t *)(a2 + 5);
          v16 = off_124508;
          v56 = *((uint32_t *)off_124530 + 10);
          v58 = (char *)(*(uint32_t *)a2 & 0xFFFFF1FF);
          v57 = v58 == 0;
          v59 = v55 + 4;
          if ( v58 )
            v54 = (int)off_124508 + 4 * v59;
          else
            v58 = (char *)off_124508 + 4 * v59;
          if ( v57 )
            *((uint32_t *)v58 + 1) = v54;
          else
            *(uint32_t *)(v54 + 4) = v58;
          if ( v56 )
          {
            v54 = *(uint8_t *)(v56 + 4);
            if ( v54 == v55 )
            {
              v54 = (int)off_124534;
              *(uint32_t *)off_124534 = *(uint32_t *)&v16[4 * v59 + 4];
            }
          }
          message_dispatch_n84(23, a4, v6, v54);
          v17 = 0;
          goto LABEL_10;
        case 0x18u:
LABEL_52:
          v16 = off_124508;
          sub_14380C(dword_124524 + 1320 * *(uint8_t *)(a2 + 6), a2, 6);
          v52 = off_12452C;
          v53 = *(uint16_t *)(a2 + 4);
          *(uint32_t *)off_124528 = *(uint32_t *)a2;
          *v52 = v53;
          message_dispatch_n84(25, a4, v6, v52);
          v17 = 0;
          goto LABEL_10;
        case 0x1Cu:
LABEL_75:
          v16 = off_124508;
          v71 = (*(uint8_t *)a2 << 14) & 0x1C000 | *(uint32_t *)off_124548 & 0xFFFE3FFF;
          *(uint32_t *)off_124548 = v71;
          message_dispatch_n84(29, a4, v6, v71);
          v17 = 0;
          goto LABEL_10;
        case 0x1Eu:
LABEL_33:
          v32 = *(uint8_t *)(a2 + 3);
          v33 = dword_124538;
          v34 = (uint8_t *)(dword_124538 + 1320 * v32);
          v188[0] = 0;
          v184 = 1320 * v32;
          v35 = sub_120770(v188);
          v36 = v34[106];
          v37 = *(uint8_t *)(a2 + 2);
          v34[108] = v37;
          v179 = v35;
          if ( !v36 )
          {
            v186 = v34[116];
            if ( v37 )
            {
              v38 = dword_1244F4 + 696 * v34[116];
              v39 = v184 + 24 + v33;
              timestamp_update_4f60(v39, *((uint32_t *)off_1244F8 + 4) + *(uint32_t *)(v38 + 8));
              *(uint16_t *)(v38 + 32) = *(uint16_t *)a2;
              sub_120750();
              feature_guard_sdio(256, dword_1244FC);
              v40 = off_124504;
              *(uint32_t *)off_124500 = (uint16_t)*(uint32_t *)off_124500 | (*(uint16_t *)a2 << 16);
              if ( (*v40 & 0x8000) != 0 && chip_feature_check() && (*(uint32_t *)(v38 + 4) & 0x20) != 0 )
              {
                sub_101904(*(uint16_t *)a2);
                sub_11C750();
                feature_guard_sdio(256, dword_124B9C);
                mmio_set_bit7();
              }
              v16 = off_124508;
              v187 = dword_1244F4 + 696 * v186;
              v41 = v33 + 1320 * v32;
              v42 = *(uint32_t *)(v41 + 4) | 1;
              *(uint16_t *)(v187 + 30) = (unsigned int)(((unsigned int)dword_12454C
                                                    * (unsigned uint64_t)(*(uint32_t *)(v187 + 8)
                                                                       * ((unsigned int)*((uint16_t *)off_124508
                                                                                        + 14)
                                                                        + 20))) >> 32) >> 18;
              v43 = off_1244F8;
              *(uint16_t *)(v41 + 112) = 0;
              *(uint8_t *)(v41 + 114) = 0;
              *(uint8_t *)(v41 + 148) = 0;
              *(uint8_t *)(v41 + 128) = 0;
              *(uint32_t *)(v41 + 124) = 0;
              *(uint32_t *)(v41 + 4) = v42;
              *(uint32_t *)(v41 + 120) = v43[4];
              v185 = v41;
              v44 = bt_hci_cmd_dispatch(v34);
              v45 = *(uint8_t *)(v185 + 1224);
              if ( *(uint8_t *)(v185 + 1224) )
              {
                if ( !v179 )
                  goto LABEL_39;
                v92 = off_124860;
                if ( !*((uint32_t *)off_124860 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124860 + 8) = 0;
                v92[36] = 0;
                sub_1296EC(v44);
LABEL_119:
                v93 = **v12;
                *((uint32_t *)v16 + 1) |= 0x10u;
                if ( v93 < 0 && *(uint32_t *)off_124BAC << 28 )
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                *(uint32_t *)off_124894 = *(uint32_t *)v16 | *((uint32_t *)v16 + 1);
                v37 = *(uint8_t *)(a2 + 2);
                goto LABEL_40;
              }
              if ( v179 )
              {
                if ( v179 != 1 )
                  goto LABEL_39;
                v105 = off_124B88;
                if ( v34 == *((uint8_t **)off_124B88 + 8) )
                  goto LABEL_39;
                *((uint32_t *)off_124B88 + 8) = v45;
                v182 = v45;
                v106 = timestamp_remove_058(v39);
                v105[36] = v182;
                sub_1296EC(v106);
                v37 = *(uint8_t *)(a2 + 2);
              }
              else
              {
                if ( *((uint32_t *)off_12450C + 8) )
                {
LABEL_39:
                  v37 = *(uint8_t *)(a2 + 2);
                  goto LABEL_40;
                }
                if ( v188[0] )
                {
                  if ( v188[0] != 1 )
                    goto LABEL_39;
                  goto LABEL_119;
                }
                v118 = (int *)off_124BA8;
                v119 = *(uint32_t *)(v187 + 8);
                v120 = *(uint32_t *)off_124BA8;
                *((uint32_t *)off_12450C + 8) = v34;
                *v118 = (uint16_t)(v119 >> 10) | (HIWORD(v120) << 16);
                v121 = timestamp_remove_058(v39);
                *((uint8_t *)off_124B88 + 36) = 0;
                sub_1295B8(v121);
                v37 = *(uint8_t *)(a2 + 2);
              }
            }
            else
            {
              v79 = timestamp_remove_058(v184 + 24 + v33);
              nullsub_8(v79);
              v80 = feature_guard_sdio(256, dword_124884);
              if ( (*(uint32_t *)off_124888 & 0x8000) != 0 )
              {
                v80 = chip_feature_check();
                if ( v80 )
                {
                  if ( (*(uint32_t *)(dword_124B8C + 696 * v186 + 4) & 0x20) != 0 && v34[106] != 4 )
                    v80 = phy_tbl_lookup_by_idx(v34[107]);
                }
              }
              v81 = v33 + 1320 * v32;
              v82 = *(uint8_t *)(v81 + 1224);
              *(uint8_t *)(v81 + 1227) = 0;
              *(uint32_t *)(v81 + 1228) = 0;
              if ( v82 )
              {
                if ( v179 )
                {
                  v94 = *((uint8_t **)off_124B84 + 2);
                  if ( v94 )
                  {
                    while ( v94[106] || !v94[108] || v34 == v94 || v94[1224] )
                    {
                      v94 = *(uint8_t **)v94;
                      if ( !v94 )
                        goto LABEL_101;
                    }
                    if ( !*((uint32_t *)off_124B88 + 8) )
                    {
                      v95 = v94[116];
                      v96 = dword_124B8C;
                      v97 = (int *)off_124BA8;
                      *((uint32_t *)off_124B88 + 8) = v94;
                      *v97 = (uint16_t)(*(uint32_t *)(v96 + 696 * v95 + 8) >> 10) | (HIWORD(*v97) << 16);
                      v181 = v94;
                      v98 = timestamp_remove_058(v94 + 24);
                      *((uint8_t *)off_124B88 + 36) = 0;
                      v16 = off_124B90;
                      sub_1295B8(v98);
                      v99 = **v12;
                      v100 = v181;
                      *((uint32_t *)v16 + 1) &= ~0x10u;
                      if ( v99 < 0 && *(uint32_t *)off_124BAC << 28 )
                      {
                        sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                        v100 = v181;
                      }
                      v101 = off_124BB8;
                      *(uint32_t *)off_124B94 = *(uint32_t *)v16 | *((uint32_t *)v16 + 1);
                      v102 = off_124B98;
                      v103 = *((uint32_t *)v100 + 16);
                      v104 = *((uint16_t *)v100 + 34);
                      *v101 = v103;
                      *v102 = v104;
                      v37 = *(uint8_t *)(a2 + 2);
                      goto LABEL_40;
                    }
                  }
                }
              }
              else if ( v179 == 2 )
              {
                v111 = off_124B88;
                if ( !*((uint32_t *)off_124B88 + 8) )
                {
                  v112 = *((uint8_t **)off_124B84 + 2);
                  if ( !v112 )
LABEL_169:
                    __und(0xFFu);
                  while ( v112[106] || !v112[108] || v34 == v112 || v112[1224] )
                  {
                    v112 = *(uint8_t **)v112;
                    if ( !v112 )
                      goto LABEL_169;
                  }
                  v113 = (int *)off_124BA8;
                  v183 = v112[1224];
                  v114 = *(uint32_t *)off_124BA8;
                  v115 = *(uint32_t *)(dword_124B8C + 696 * v112[116] + 8);
                  *((uint32_t *)off_124B88 + 8) = v112;
                  *v113 = (uint16_t)(v115 >> 10) | (HIWORD(v114) << 16);
                  v116 = timestamp_remove_058(v112 + 24);
                  v111[36] = v183;
                  v16 = off_124B90;
                  sub_1295B8(v116);
                  v37 = *(uint8_t *)(a2 + 2);
                  goto LABEL_40;
                }
              }
              else if ( v179 == 1 )
              {
                v117 = off_124B88;
                if ( v34 == *((uint8_t **)off_124B88 + 8) )
                {
                  *((uint32_t *)off_124B88 + 8) = 0;
                  v117[36] = 0;
                  v16 = off_124B90;
                  sub_1296EC(v80);
                  v37 = *(uint8_t *)(a2 + 2);
                  goto LABEL_40;
                }
              }
LABEL_101:
              v37 = *(uint8_t *)(a2 + 2);
              v16 = off_124864;
            }
LABEL_40:
            sub_12A2B4(v34, v37);
            v46 = *(uint8_t *)(a2 + 2);
            if ( *(uint8_t *)(a2 + 2) )
            {
              v47 = *(uint32_t **)off_124510;
              v48 = **(uint32_t **)off_124510;
              if ( v48 )
                *(uint32_t *)off_124514 = v48;
              else
                *(uint32_t *)off_124880 = *(uint32_t *)(v33 + 1320 * v32 + 8);
              v49 = v47[1];
              if ( v49 )
              {
                if ( (v49 & 0xFFF) != 0 )
                  *(uint32_t *)off_12487C = v49;
                else
                  *(uint32_t *)off_124518 = v49 & 0xFFFFF000 | *(uint32_t *)(v33 + 1320 * v32 + 12) & 0xFFF;
              }
              else
              {
                *(uint32_t *)off_12487C = *(uint32_t *)(v33 + 1320 * v32 + 12);
              }
              v50 = v47[2];
              if ( v50 )
                *(uint32_t *)off_12451C = v50;
              else
                *(uint32_t *)off_124878 = *(uint32_t *)(v33 + 1320 * v32 + 16);
              v51 = v47[3];
              if ( v51 )
                *(uint32_t *)off_124520 = v51;
              else
                *(uint32_t *)off_12488C = *(uint32_t *)(v33 + 1320 * v32 + 20);
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
              v77 = 0;
              goto LABEL_84;
            }
LABEL_85:
            v16 = off_124864;
            goto LABEL_40;
          }
          v77 = *((uint8_t **)off_124890 + 2);
          if ( v77 )
          {
            do
            {
              if ( !v77[106] && v77[108] && v34 != v77 && !v77[1224] )
                break;
              v77 = *(uint8_t **)v77;
            }
            while ( v77 );
            if ( !v37 )
            {
              v83 = off_124860;
              if ( !*((uint32_t *)off_124860 + 8) && v77 )
              {
                *((uint32_t *)off_124860 + 8) = v77;
                v83[36] = 0;
                v180 = v77;
                v16 = off_124864;
                v84 = timestamp_remove_058(v77 + 24);
                sub_1295B8(v84);
                v85 = **v12;
                v86 = v180;
                *((uint32_t *)v16 + 1) &= ~0x10u;
                if ( v85 < 0 && *(uint32_t *)off_124BAC << 28 )
                {
                  sub_12F6C4(dword_124BB4, dword_124BB0, 472);
                  v86 = v180;
                }
                v87 = off_1248A4;
                v88 = *((uint32_t *)v86 + 16);
                *(uint32_t *)off_124894 = *(uint32_t *)v16 | *((uint32_t *)v16 + 1);
                v89 = off_124898;
                v90 = *((uint16_t *)v86 + 34);
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
          if ( v77 == *((uint8_t **)off_124860 + 8) )
          {
            *((uint32_t *)off_124860 + 8) = 0;
            v78[36] = 0;
            v16 = off_124B90;
            ((void (*)(void))sub_1296EC)();
            v107 = **v12;
            *((uint32_t *)v16 + 1) |= 0x10u;
            if ( v107 < 0 && *(uint32_t *)off_124BAC << 28 )
              sub_12F6C4(dword_124BB4, dword_124BB0, 472);
            v108 = off_124B94;
            v109 = off_124BA0;
            *(uint32_t *)off_124B94 = *(uint32_t *)v16 | *((uint32_t *)v16 + 1);
            v110 = dword_124BA4;
            *v109 = dword_124BA4;
            v108[8197] |= v110;
            v37 = *(uint8_t *)(a2 + 2);
            goto LABEL_40;
          }
          goto LABEL_85;
        case 0x20u:
LABEL_32:
          v16 = off_124198;
          v31 = *(uint8_t *)a2 | (((uint8_t)*(uint32_t *)off_1241B8 * *(uint8_t *)a2) << 8);
          *(uint32_t *)off_1241BC = v31;
          message_dispatch_n84(33, a4, v6, v31);
          v17 = 0;
          goto LABEL_10;
        case 0x28u:
LABEL_27:
          v19 = *(uint8_t *)a2;
          if ( *(uint8_t *)a2 )
          {
            if ( sub_13A490(
                   dword_124870 + 696 * *(uint8_t *)(a2 + 1),
                   *(uint8_t *)(a2 + 2),
                   *(uint16_t *)(a2 + 6)) )
            {
              *(uint32_t *)off_124874 |= 0x80u;
              v19 = 0;
            }
            else
            {
              v19 = 4;
            }
          }
          else
          {
            v20 = *(uint8_t *)(a2 + 2);
            v21 = *(uint16_t *)(a2 + 4);
            v22 = *(uint32_t *)(dword_1241AC + 4 * *(uint8_t *)(dword_1241A8 + v20));
            if ( (int)v21 >= v22 )
            {
              if ( v21 > 0x40 )
                LOWORD(v23) = *(uint32_t *)(dword_1241AC + 4 * *(uint8_t *)(dword_1241A8 + v20));
              else
                LOWORD(v23) = v22 / 2;
            }
            else
            {
              v23 = v21 >> 1;
            }
            sub_12ECB0(dword_1241B0, v20, v21);
            v24 = *(uint16_t *)(a2 + 4);
            v25 = 696 * *(uint8_t *)(a2 + 1);
            v26 = *(uint8_t *)(v25 + 12 * *(uint8_t *)(a2 + 2) + dword_1241C0 + 453);
            v27 = *(uint16_t *)(a2 + 6);
            v28 = v25 + 6 * *(uint8_t *)(a2 + 2) + dword_1241C0;
            v29 = dword_1241B4 + 32 * v26;
            *(uint16_t *)(v28 + 354) = v23;
            *(uint16_t *)(v28 + 356) = v24;
            *(uint16_t *)(v29 + 12) = v27;
          }
          v30 = (uint8_t *)rf_bus_setup_n3a8(41, a4, v6, 3);
          *v30 = *(uint8_t *)(a2 + 1);
          v30[1] = *(uint8_t *)(a2 + 2);
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
    *(uint32_t *)off_124194 = (uint8_t)(16 * v16[19]);
    rf_bus_mark_n_3b7(v6);
    return v17;
  }
  if ( (uint16_t)(value - 2) > 2u )
  {
    v14 = off_124198;
    *((uint8_t *)off_124198 + 19) = *(uint8_t *)off_124194 & 0xF;
    v15 = msg_get_value(v6);
    v14[18] = v15;
    sub_12BA2C(v15);
    rf_bus_mark_n_3b7(v6);
  }
  return 2;
}

