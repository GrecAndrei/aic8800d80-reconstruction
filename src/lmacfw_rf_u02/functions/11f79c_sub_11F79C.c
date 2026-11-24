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


extern uint32_t dword_11FCF0;
extern uint32_t dword_11FD10;
extern uint32_t dword_11FD24;
extern uint32_t dword_11FF90;
extern uint32_t dword_1202E4;
extern uint32_t dword_1202F0;
extern uint32_t dword_1202F4;
extern uint32_t dword_120668;
extern uint32_t dword_1206B0;
extern uint32_t dword_120D74;
extern uint32_t dword_120D7C;
extern uint32_t dword_12118C;
extern uint32_t dword_121190;
extern uint32_t dword_121194;
extern uint32_t dword_1212BC;
extern uint32_t dword_1212C8;
extern float flt_12069C;
extern float flt_1206A0;
extern uint32_t off_11FCD0;
extern uint32_t off_11FCD4;
extern uint32_t off_11FCD8;
extern uint32_t off_11FCE8;
extern uint32_t off_11FCF4;
extern uint32_t off_11FD08;
extern uint32_t off_11FD14;
extern uint32_t off_11FD28;
extern uint32_t off_11FD2C;
extern uint32_t off_11FF88;
extern uint32_t off_11FF8C;
extern uint32_t off_11FF98;
extern uint32_t off_11FFAC;
extern uint32_t off_11FFB0;
extern uint32_t off_11FFC0;
extern uint32_t off_11FFD4;
extern uint32_t off_11FFD8;
extern uint32_t off_11FFDC;
extern uint32_t off_11FFE0;
extern uint32_t off_1202C0;
extern uint32_t off_1202C4;
extern uint32_t off_1202C8;
extern uint32_t off_1202CC;
extern uint32_t off_1202D8;
extern uint32_t off_1202DC;
extern uint32_t off_1202E0;
extern uint32_t off_1202E8;
extern uint32_t off_1202EC;
extern uint32_t off_1202FC;
extern uint32_t off_120308;
extern uint32_t off_12030C;
extern uint32_t off_120318;
extern uint32_t off_120654;
extern uint32_t off_120658;
extern uint32_t off_12065C;
extern uint32_t off_120660;
extern uint32_t off_120664;
extern uint32_t off_120670;
extern uint32_t off_120674;
extern uint32_t off_120678;
extern uint32_t off_120688;
extern uint32_t off_12068C;
extern uint32_t off_120690;
extern uint32_t off_120694;
extern uint32_t off_120698;
extern uint32_t off_1206A8;
extern uint32_t off_1206AC;
extern uint32_t off_1206B4;
extern uint32_t off_1206B8;
extern uint32_t off_1206BC;
extern uint32_t off_1209C4;
extern uint32_t off_1209D0;
extern uint32_t off_1209D8;
extern uint32_t off_1209DC;
extern uint32_t off_120A00;
extern uint32_t off_120D64;
extern uint32_t off_120D6C;
extern uint32_t off_120D80;
extern uint32_t off_120DA4;
extern uint32_t off_120DBC;
extern uint32_t off_120DC8;
extern uint32_t off_121118;
extern uint32_t off_12111C;
extern uint32_t off_121120;
extern uint32_t off_12112C;
extern uint32_t off_121130;
extern uint32_t off_121134;
extern uint32_t off_121138;
extern uint32_t off_12113C;
extern uint32_t off_121148;
extern uint32_t off_121150;
extern uint32_t off_121154;
extern uint32_t off_12115C;
extern uint32_t off_121174;
extern uint32_t off_12119C;
extern uint32_t off_1212C0;

// sub_11F79C @ 0x11f79c, size 6938 bytes
int  sub_11F79C(int a1, int a2, int a3, int a4)
{
  int *v5; // r0
  int v6; // r2
  int v7; // r3
  char *v8; // r5
  unsigned int v9; // r3
  int v10; // r2
  uint8_t *v11; // r6
  unsigned int v12; // r9
  unsigned int v13; // r10
  int v14; // r8
  char **v15; // r7
  uint16_t *v16; // r0
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  char **v21; // r10
  int v23; // r4
  int v24; // r4
  char *v25; // r4
  int v26; // r1
  unsigned int v27; // r2
  int v28; // r7
  int v29; // r4
  int v30; // r4
  unsigned int v31; // r2
  char *v32; // r1
  unsigned int v33; // r0
  int v34; // r0
  int v35; // r0
  unsigned int v36; // r0
  int v37; // r1
  unsigned int v38; // r0
  int v39; // r1
  uint32_t *v40; // r2
  char *v41; // r1
  char *v42; // r3
  int v43; // r4
  unsigned int *v44; // r6
  int v45; // r4
  uint8_t v46; // r0
  int v47; // r6
  int v48; // r4
  int v49; // r4
  int v50; // r7
  uint32_t *v51; // r2
  int v52; // r0
  int v53; // r1
  int v54; // r0
  int v55; // r1
  unsigned int v56; // r1
  unsigned int v57; // r2
  int v58; // r4
  int v59; // r3
  unsigned int v60; // r2
  unsigned int v61; // r6
  uint16_t v62; // r7
  unsigned int v63; // r8
  unsigned int v64; // r4
  int v65; // r3
  int v66; // r7
  uint32_t *v67; // r1
  int *v68; // r6
  uint32_t *v69; // r7
  volatile unsigned int v70; // r9
  unsigned int v71; // r3
  int v72; // r3
  int v73; // r3
  int v74; // r2
  unsigned int v75; // r6
  int v76; // r4
  uint16_t v77; // r3
  uint16_t v78; // r3
  uint32_t *v79; // r1
  int v80; // r4
  uint32_t *v81; // r3
  unsigned int v82; // r0
  unsigned int v83; // r1
  unsigned int v84; // r2
  int v85; // r3
  int *v86; // r6
  uint32_t *v87; // r4
  volatile unsigned int v88; // r8
  unsigned int v89; // r3
  int v90; // r3
  int v91; // r3
  int v92; // r2
  int v93; // r1
  int v94; // r2
  int v95; // r2
  int v96; // r8
  unsigned int v97; // r9
  int v98; // r11
  unsigned int v99; // r4
  int v100; // r1
  int v101; // r10
  int v102; // r7
  int v103; // r9
  int v104; // r8
  uint64_t v105; // kr00_8
  unsigned int v106; // r3
  uint16_t v107; // r2
  int v108; // r3
  unsigned int v109; // r0
  int *v110; // r4
  int v111; // r3
  int v112; // r2
  int v113; // r6
  uint32_t *v114; // r3
  unsigned int v115; // r3
  unsigned int v116; // r8
  unsigned int v117; // r9
  int v118; // r10
  unsigned int v119; // r7
  int v120; // r6
  int v121; // r11
  int v122; // r4
  unsigned int v123; // r4
  int *v124; // r8
  int *v125; // r0
  uint8_t *v126; // r1
  unsigned int v127; // r4
  int *v128; // r3
  int v129; // r6
  uint32_t *v130; // r3
  int v131; // r3
  int v132; // r1
  int v133; // r4
  uint64_t v134; // r0
  float v135; // r0
  uint64_t v136; // r0
  uint64_t v137; // r0
  unsigned int v138; // r8
  unsigned int *v139; // r1
  unsigned int *v140; // r4
  int v141; // r6
  uint32_t *v142; // r2
  uint32_t *v143; // r0
  uint32_t *v144; // r6
  unsigned int v145; // r4
  unsigned int v146; // r0
  unsigned int v147; // r0
  unsigned int v148; // r0
  int v149; // r1
  unsigned int v150; // r3
  int v151; // r2
  unsigned int v152; // r7
  int v153; // r2
  BOOL v154; // r3
  int v155; // r3
  uint8_t *v156; // r1
  const char *v157; // r0
  uint32_t *v158; // r4
  int v159; // r0
  unsigned int v160; // r1
  unsigned int v161; // r3
  unsigned int v162; // r8
  int v163; // r4
  int v164; // r6
  uint16_t v165; // r3
  uint16_t v166; // r1
  int v167; // r6
  int v168; // r7
  char *v169; // r9
  int i; // r8
  char *v171; // r10
  int j; // r4
  int v173; // r6
  int v174; // t1
  char *v175; // r9
  int k; // r8
  char *v177; // r10
  int m; // r4
  int v179; // r6
  int v180; // t1
  int jj; // r6
  int kk; // r4
  int v183; // r1
  int mm; // r9
  int nn; // r4
  int v186; // r1
  int v187; // r0
  int v188; // r0
  int v189; // r0
  int v190; // r1
  BOOL v191; // r1
  int v192; // r0
  int v193; // r4
  uint64_t v194; // r2
  uint64_t v195; // r0
  int v196; // r4
  uint64_t v197; // r2
  unsigned int v198; // r4
  uint32_t *v199; // r3
  uint32_t *v200; // r1
  uint8_t *v201; // r2
  uint8_t *v202; // r2
  char v203; // r0
  unsigned int v204; // r1
  int v205; // r3
  int *v206; // r4
  int v207; // r3
  int v208; // r1
  int v209; // r2
  BOOL v210; // r3
  uint8_t *v211; // r6
  unsigned int v212; // r7
  unsigned int v213; // r8
  int v214; // r4
  uint16_t *v215; // r0
  unsigned int v216; // r1
  int v217; // r0
  int v218; // r3
  unsigned int v219; // r1
  uint64_t v220; // r0
  uint64_t v221; // r2
  uint64_t v222; // r0
  uint64_t v223; // r2
  uint64_t v224; // r0
  uint64_t v225; // r2
  int v226; // r10
  int v227; // r8
  unsigned int ii; // r4
  int v229; // r6
  int v230; // t1
  int v231; // r10
  int v232; // r8
  unsigned int n; // r4
  int v234; // r6
  int v235; // t1
  char v236[72]; // [sp+3Ch] [bp-468h] BYREF
  int v237; // [sp+84h] [bp-420h]
  unsigned int a1a; // [sp+88h] [bp-41Ch]
  int v239; // [sp+8Ch] [bp-418h]
  int v240; // [sp+90h] [bp-414h] BYREF
  unsigned int a2a; // [sp+94h] [bp-410h] BYREF
  uint16_t v242; // [sp+98h] [bp-40Ch]
  uint16_t v243; // [sp+9Ah] [bp-40Ah]
  char v244; // [sp+9Eh] [bp-406h]
  int result[2]; // [sp+A0h] [bp-404h] BYREF
  uint8_t v246; // [sp+A8h] [bp-3FCh]
  char v247; // [sp+AAh] [bp-3FAh]

  v5 = (int *)sub_11DDF0(1044, a4, a3, 72);
  v7 = *(uint32_t *)a2;
  v8 = (char *)v5;
  switch ( *(uint32_t *)a2 )
  {
    case 0:
      if ( *off_120670 == 1 )
      {
        v202 = off_12112C;
        *off_120670 = 0;
        *v202 = 0;
        sub_11DC54((char *)0x90, 0);
      }
      v113 = *(uint32_t *)off_120674 & 0xF;
      if ( v113 == 3 )
        sub_11D348();
      v114 = (uint32_t *)off_120674;
      *(uint32_t *)off_120678 = 0;
      *v114 = 16 * v113;
      sub_11F504("rftest set tx: %d\r\n", *(uint32_t *)(a2 + 4));
      v115 = *(uint8_t *)(a2 + 10);
      v116 = *(uint8_t *)(a2 + 9);
      v117 = *(uint8_t *)(a2 + 8);
      v118 = *(uint8_t *)(a2 + 11);
      v119 = (uint16_t)(*(uint8_t *)(a2 + 12) + (*(uint8_t *)(a2 + 13) << 8));
      v120 = (uint16_t)(*(uint8_t *)(a2 + 14) + (*(uint8_t *)(a2 + 15) << 8));
      v121 = *(char *)(a2 + 16);
      v122 = *(uint8_t *)(a2 + 16);
      a1a = v115;
      v239 = v122;
      sub_11F504("param:%d,%d,%d,%d,%d,%d\r\n", v117, v116, v115, v118, v119, v120);
      sub_11F504("max_pwr:%d\n", v121);
      v123 = v116;
      if ( (*(uint8_t *)off_120688 & 8) == 0 && v116 > 1 )
      {
        sub_11F504("invalid bw:%d\n", v116);
        goto LABEL_21;
      }
      sub_123FF0(a1a, v118, 0);
      sub_123F4C(v119);
      LOBYTE(result[0]) = v117 > 0x23;
      BYTE1(result[0]) = v116;
      if ( v117 > 0x23 )
      {
        LOWORD(result[1]) = 5 * v117 + 5000;
      }
      else if ( v117 > 0xD )
      {
        LOWORD(result[1]) = 2484;
        if ( v117 != 14 )
        {
          sub_11F504("Not supported chan: %d\n", v117);
          v116 = BYTE1(result[0]);
        }
      }
      else
      {
        LOWORD(result[1]) = 5 * v117 + 2407;
      }
      HIWORD(result[1]) = 0;
      v247 = 0;
      if ( v116 )
      {
        if ( v116 == 1 )
        {
          if ( v117 == 1 || v117 == 36 )
            HIWORD(result[0]) = LOWORD(result[1]) + 10;
          else
            HIWORD(result[0]) = LOWORD(result[1]) - 10;
        }
      }
      else
      {
        HIWORD(result[0]) = result[1];
      }
      v124 = (int *)off_120654;
      if ( *(uint32_t *)off_120654 )
        sub_1268EC(0);
      v125 = off_120658;
      v126 = off_120690;
      v127 = *(uint32_t *)off_12068C & 0xFFFFFE7F | (v123 << 7);
      v128 = (int *)(v120 - 1);
      if ( (unsigned int)(v120 - 1) > 0x30 )
        v128 = off_120694;
      *(uint32_t *)off_12068C = v127;
      if ( (unsigned int)(v120 - 1) > 0x30 )
        *v128 = v120;
      if ( (unsigned int)(v239 - 1) <= 0x1E )
        *(uint8_t *)off_120698 = v121;
      *v125 = 1;
      *v126 = 1;
      sub_1246F0(0, (int)result);
      if ( LOBYTE(result[0]) )
        sub_1010D4(LOWORD(result[1]));
      else
        sub_100E00(LOWORD(result[1]), BYTE1(result[0]));
      v35 = *v124;
      if ( !*v124 )
        goto LABEL_21;
      goto LABEL_59;
    case 1:
      sub_11F504(aRftestSetTxsto);
      v108 = *(uint32_t *)off_120654;
      *off_120658 = 0;
      if ( v108 )
        sub_1268EC(0);
      v109 = *(uint8_t *)off_12065C;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_120660 = 1;
      }
      v110 = (int *)off_120664;
      a1a = v109;
      ++*(uint32_t *)off_120664;
      sub_1158A4(v109);
      sub_1160FC(a1a, dword_120668 + 28 * (uint16_t)a1a + 12);
      if ( *v110 )
      {
        v111 = *v110 - 1;
        v112 = *(uint32_t *)off_120660;
        *v110 = v111;
        if ( !v111 )
        {
          if ( v112 )
            __enable_irq();
        }
      }
      sub_11F504(aStopDone);
      goto LABEL_21;
    case 2:
      if ( *off_120670 == 1 )
      {
        v201 = off_12112C;
        *off_120670 = 0;
        *v201 = 0;
        sub_11DC54((char *)0x90, 0);
      }
      v129 = *(uint32_t *)off_120674 & 0xF;
      if ( v129 == 3 )
        sub_11D348();
      v130 = (uint32_t *)off_120674;
      *(uint32_t *)off_120678 = 0;
      *v130 = 16 * v129;
      v131 = *(uint32_t *)(a2 + 4);
      if ( !v131 )
        goto LABEL_243;
      v132 = *(uint8_t *)(a2 + 8);
      if ( *(uint8_t *)(a2 + 8) )
      {
        if ( v132 == 1 )
        {
          if ( v131 == 2 )
          {
            v133 = *(char *)(a2 + 9);
            v134 = sub_12754C(v133);
            v135 = COERCE_FLOAT(sub_127BE4(v134));
            if ( v133 <= 0 )
            {
              v220 = sub_127570(LODWORD(v135));
              HIDWORD(v221) = dword_12118C;
              LODWORD(v221) = 0;
              v222 = sub_1272B4(v220, v221);
              HIDWORD(v223) = dword_121190;
              LODWORD(v223) = 0;
              v224 = sub_127874(v222, v223);
              HIDWORD(v225) = dword_121194;
              LODWORD(v225) = 0;
              v136 = sub_127620(v224, v225);
            }
            else
            {
              v136 = sub_127570(COERCE_UNSIGNED_INT((float)(v135 / flt_12069C) * flt_1206A0));
            }
            v137 = sub_127194(v136);
            v138 = sub_127BA4(v137);
            sub_11F504("user tone on, freq=%d, tone_freq_num=%d, amp=%x, txgain=%x\n", v133, v138, 1023, 1);
            v139 = (unsigned int *)off_1206A8;
            v140 = (unsigned int *)off_1206AC;
            v141 = dword_1206B0;
            v142 = off_1206B4;
            v143 = off_1206B8;
            *(uint32_t *)off_1206A8 = ~(~((*(uint32_t *)off_1206A8 & 0xFFFFF000) >> 10) << 10);
            *v140 = *v140 & 0xFFFFFFC0 | 1;
            *v140 |= 0x40u;
            *v140 |= 0x80u;
            *v139 = v141 & (v138 << 12) | *v139 & 0xFC000FFF;
            v144 = off_1206BC;
            *v142 |= 0x1000000u;
            *v144 |= 0x10000u;
            *v139 |= 0x10000000u;
            *v143 |= 0x100u;
            sub_12266C(200);
            *v140 = *v140 & 0xFF87FFFF | 0x100000;
            sub_12266C(200);
            *v140 |= 0x400000u;
            sub_12266C(200);
            *v140 |= 0x200000u;
          }
          else
          {
LABEL_243:
            sub_11F504(aWrongArgs);
          }
        }
        else
        {
          sub_11F504("wrong func: %d\n", v132);
        }
      }
      else
      {
        sub_11F504(aUserToneOff);
        v199 = off_12111C;
        v200 = off_121120;
        *(uint32_t *)off_121118 &= ~0x10000000u;
        *v199 &= 0xFF87FFFF;
        *v200 &= ~0x10000u;
        *v199 &= 0xFFFFFFC0;
        *v199 &= ~0x40u;
        *v199 |= 0x80u;
      }
      goto LABEL_21;
    case 3:
      sub_11F504(aRftestSetRx);
      if ( !*(uint8_t *)off_11FFD4 )
      {
        v67 = off_11FFD8;
        *(uint8_t *)off_11FFD4 = 1;
        if ( *v67 << 28 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_11FFDC = 1;
          }
          v68 = (int *)off_11FFE0;
          v69 = off_11FFD8;
          ++*(uint32_t *)off_11FFE0;
          *v69 = 0;
          v70 = (*(volatile uint32_t *)0x40501010u);
          while ( *v69 << 28 )
          {
            v71 = (*(volatile uint32_t *)0x40501010u) - v70;
            if ( v71 > 0x7530 )
              sub_11F504(aIdleErr);
          }
          while ( (*(uint32_t *)off_1202C4 & *(uint32_t *)off_1202C0 & 4) == 0 )
            ;
          v72 = *v68;
          *(uint32_t *)off_1202C8 = 4;
          if ( v72 )
          {
            v73 = v72 - 1;
            v74 = *(uint32_t *)off_1202CC;
            *v68 = v73;
            if ( !v73 )
            {
              if ( v74 )
                __enable_irq();
            }
          }
          sub_11F504(aForceIdled);
        }
      }
      v75 = *(uint8_t *)(a2 + 8);
      v76 = *(uint8_t *)(a2 + 9);
      sub_11F504("chan=%x, bw=%x\r\n", v75, v76);
      LOBYTE(result[0]) = v75 > 0x23;
      BYTE1(result[0]) = v76;
      if ( v75 > 0x23 )
      {
        v77 = 5 * v75 + 5000;
        LOWORD(result[1]) = v77;
      }
      else
      {
        if ( v75 > 0xD )
        {
          LOWORD(result[1]) = 2484;
          if ( v75 == 14 )
          {
            HIWORD(result[1]) = 0;
            v247 = 0;
            if ( v76 == 1 )
              v78 = 2474;
            else
              v78 = 2514;
            goto LABEL_120;
          }
          sub_11F504("Not supported chan: %d\n", v75);
          HIWORD(result[1]) = 0;
          v247 = 0;
          v77 = result[1];
          if ( BYTE1(result[0]) != 1 )
            goto LABEL_119;
          goto LABEL_322;
        }
        v77 = 5 * v75 + 2407;
        LOWORD(result[1]) = v77;
      }
      HIWORD(result[1]) = 0;
      v247 = 0;
      if ( v76 != 1 )
      {
LABEL_119:
        v78 = v77 + 30;
LABEL_120:
        HIWORD(result[0]) = v78;
        goto LABEL_121;
      }
      if ( v75 == 1 )
      {
LABEL_336:
        HIWORD(result[0]) = v77 + 10;
LABEL_121:
        sub_1246F0(0, (int)result);
        v79 = off_1202DC;
        *(uint32_t *)off_1202D8 |= 0x10u;
        v80 = *v79 & 0xF;
        if ( v80 == 3 )
          sub_11D348();
        v81 = off_1202DC;
        *(uint32_t *)off_1202E0 = dword_1202E4;
        *v81 = 16 * v80;
        sub_1188F4();
        goto LABEL_21;
      }
LABEL_322:
      if ( v75 != 36 )
      {
        v78 = v77 - 10;
        goto LABEL_120;
      }
      goto LABEL_336;
    case 4:
      sub_11F504(aRftestGetRxRes);
      v93 = *(uint32_t *)off_120308;
      v94 = *(uint32_t *)off_12030C;
      *(uint32_t *)v8 = *(uint32_t *)off_120308;
      v95 = v94 + v93;
      *((uint32_t *)v8 + 1) = v95;
      sub_11F504("rx fcsok=%d, total:%d\r\n", v93, v95);
      goto LABEL_21;
    case 5:
      sub_11F504(aRftestSetRxsto);
      if ( *(uint32_t *)off_1202DC << 28 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_1202CC = 1;
        }
        v86 = (int *)off_1202FC;
        v87 = off_1202DC;
        ++*(uint32_t *)off_1202FC;
        *v87 = 0;
        v88 = (*(volatile uint32_t *)0x40501010u);
        while ( *v87 << 28 )
        {
          v89 = (*(volatile uint32_t *)0x40501010u) - v88;
          if ( v89 > 0x7530 )
            sub_11F504(aIdleErr, *v87 << 28, 30000);
        }
        while ( (*(uint32_t *)off_1202C4 & *(uint32_t *)off_1202C0 & 4) == 0 )
          ;
        v90 = *v86;
        *(uint32_t *)off_1202C8 = 4;
        if ( v90 )
        {
          v91 = v90 - 1;
          v92 = *(uint32_t *)off_1202CC;
          *v86 = v91;
          if ( !v91 )
          {
            if ( v92 )
              __enable_irq();
          }
        }
        sub_11F504(aForceIdled);
      }
      goto LABEL_21;
    case 6:
      sub_11F504(aRftestRxMeterN);
      goto LABEL_21;
    case 7:
      sub_11F504("set power: %x\r\n", *(uint8_t *)(a2 + 8));
      v51 = off_11FFB0;
      *off_11FFAC = *(uint8_t *)(a2 + 8) | (*(uint8_t *)(a2 + 8) << 8);
      *v51 = 1;
      goto LABEL_21;
    case 8:
      v46 = sub_10F15C();
      v47 = *(uint8_t *)(a2 + 8);
      v48 = (char)(v47 + v46);
      if ( v48 < 1 )
        v48 = 1;
      if ( v48 >= 31 )
        v48 = 31;
      sub_11F504("set xtal cap: %x -> %x\r\n", v46, v48);
      sub_10F170(v48);
      v49 = (uint8_t)sub_10F15C();
      v50 = sub_126E54();
      sub_126FD8(v49);
      if ( !v47 )
        sub_11F504(
          "calibed_cap:0x%x, templvl:%d\n",
          *(uint8_t *)(off_120DBC + 4),
          *(char *)(off_120DBC + 2));
      *(uint32_t *)v8 = v49;
      sub_11F504("read: %8x, temp=%d C\n", v49, v50);
      goto LABEL_21;
    case 9:
      v44 = (unsigned int *)off_11FF98;
      v45 = (char)(*(uint8_t *)(a2 + 8) + ((*(uint32_t *)off_11FF98 >> 18) & 0x3F));
      if ( v45 < 1 )
        v45 = 1;
      if ( v45 >= 63 )
        v45 = 63;
      sub_11F504(aSetXtalCapFine_0);
      *v44 = *v44 & 0xFF03FFFF | (v45 << 18);
      *(uint32_t *)v8 = (*v44 >> 18) & 0x3F;
      goto LABEL_21;
    case 0xA:
      a1a = *(uint8_t *)(a2 + 8);
      v43 = sub_113A44(a1a);
      sub_11F504("get_efuse: block=%x,val=%x\r\n", a1a, v43);
      *(uint32_t *)v8 = v43;
      goto LABEL_21;
    case 0xB:
      *v5 = sub_122DB8(1, *(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xC:
      *v5 = sub_122DB8(2, *(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xD:
      v159 = sub_122DB8(0, 0);
      *(uint32_t *)v8 = v159;
      sub_11F504("get freq_cal: %x\r\n", v159);
      goto LABEL_21;
    case 0xE:
      sub_11F504(
        "set_mac_addr: %x, %x, %x, %x, %x, %x\r\n",
        *(uint8_t *)(a2 + 13),
        *(uint8_t *)(a2 + 12),
        *(uint8_t *)(a2 + 11),
        *(uint8_t *)(a2 + 10),
        *(uint8_t *)(a2 + 9),
        *(uint8_t *)(a2 + 8));
      v160 = *(uint16_t *)(a2 + 12);
      v161 = *(uint16_t *)(a2 + 8);
      v162 = *(uint32_t *)(a2 + 8);
      v163 = HIBYTE(*(uint32_t *)off_1209C4) & 2;
      v164 = v160;
      v165 = __rev16(v161);
      v166 = __rev16(v160);
      if ( v163 )
      {
        v192 = sub_113C98(v162, v164);
        v168 = v192;
        if ( v192 < 0 )
        {
          sub_11F504("no room %d\n", v192);
          v163 = v162;
          v167 = v164 | (v168 << 16);
        }
        else
        {
          v167 = v164 | (v192 << 16);
          v163 = v162;
        }
      }
      else
      {
        LOWORD(result[0]) = v166;
        LOWORD(result[1]) = v165;
        BYTE2(result[0]) = HIBYTE(v162);
        HIBYTE(result[0]) = BYTE2(v162);
        sub_11482C((int)result);
        sub_100200(result, 0, 6u);
        if ( sub_114820((int)result) )
        {
          v167 = 917504;
          v168 = 14;
        }
        else
        {
          v167 = (uint16_t)__rev16(LOWORD(result[0])) | 0xF0000;
          v163 = bswap32(*(unsigned int *)((char *)result + 2));
          v168 = 15;
        }
      }
      *(uint32_t *)v8 = v163;
      *((uint32_t *)v8 + 1) = v167;
      v237 = v168;
      sub_1282E8(v236, v8 + 72, 0x48u);
      sub_11F504("set_mac_addr:%x,%x, %d\r\n", *(uint32_t *)v8, *((uint32_t *)v8 + 1), *((uint32_t *)v8 + 2));
      goto LABEL_21;
    case 0xF:
      v145 = HIBYTE(*(uint32_t *)off_1209C4) & 2;
      if ( v145 )
      {
        v189 = sub_113C48(&v240, &a2a);
        v145 = v240;
        v146 = a2a | (v189 << 16);
      }
      else
      {
        result[0] = 0;
        LOWORD(result[1]) = 0;
        if ( sub_114820((int)result) )
        {
          v240 = 0;
          a2a = 0;
          v146 = 917504;
        }
        else
        {
          v145 = bswap32(*(unsigned int *)((char *)result + 2));
          a2a = (uint16_t)__rev16(LOWORD(result[0]));
          v240 = v145;
          v146 = a2a | 0xF0000;
        }
      }
      *(uint32_t *)v8 = v145;
      *((uint32_t *)v8 + 1) = v146;
      sub_1282E8(v236, v8 + 72, 0x48u);
      sub_11F504("get_mac_addr:%x,%x\r\n", *(uint32_t *)v8, *((uint32_t *)v8 + 1));
      goto LABEL_21;
    case 0x10:
      sub_11F504(
        "set_bt_mac_addr: %x, %x, %x, %x, %x, %x\r\n",
        *(uint8_t *)(a2 + 13),
        *(uint8_t *)(a2 + 12),
        *(uint8_t *)(a2 + 11),
        *(uint8_t *)(a2 + 10),
        *(uint8_t *)(a2 + 9),
        *(uint8_t *)(a2 + 8));
      v60 = *(uint32_t *)(a2 + 8);
      v61 = *(uint16_t *)(a2 + 12);
      v62 = __rev16(v61);
      v63 = bswap32(v60);
      v64 = v60;
      if ( (*(uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        v188 = sub_113D80(v60, v61);
        v66 = v188;
        if ( v188 < 0 )
        {
          if ( v188 != -1 )
            sub_11F504(aSameSourceWith);
          sub_11F504(aNoRoom);
        }
        v65 = v66 << 16;
      }
      else
      {
        sub_100200(result, 0, 0x40u);
        sub_1149A4((int)result);
        HIWORD(result[0]) = v62;
        result[1] = v63;
        sub_1149B0((int)result);
        sub_1149A4((int)result);
        v61 = (uint16_t)__rev16(HIWORD(result[0]));
        v64 = bswap32(result[1]);
        v65 = 983040;
        v66 = 15;
      }
      *(uint32_t *)v8 = v64;
      *((uint32_t *)v8 + 1) = v65 | v61;
      sub_11F504("set_bt_mac_addr:%04x%08x (remain:%d)\n", v61, v64, v66);
      goto LABEL_21;
    case 0x11:
      if ( (*(uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        v187 = sub_113D00(&v240, &a2a);
        v57 = v240;
        v56 = a2a;
        v59 = v187;
        v58 = v187 << 16;
      }
      else
      {
        sub_100200(result, 0, 0x40u);
        sub_1149A4((int)result);
        v56 = (uint16_t)__rev16(HIWORD(result[0]));
        v57 = bswap32(result[1]);
        v240 = v57;
        a2a = (uint16_t)v56;
        v58 = 983040;
        v59 = 15;
      }
      *(uint32_t *)v8 = v57;
      *((uint32_t *)v8 + 1) = v58 | v56;
      sub_11F504("get_bt_mac_addr:%04x%08x (remain:%x)\n", v56, v57, v59);
      goto LABEL_21;
    case 0x12:
      sub_11F504("set vendor info:%x\r\n", *(uint8_t *)(a2 + 8));
      LOBYTE(result[0]) = *(uint8_t *)(a2 + 8);
      sub_114194(LOBYTE(result[0]));
      v54 = sub_11416C(result);
      v55 = LOBYTE(result[0]);
      *(uint32_t *)v8 = LOBYTE(result[0]);
      sub_11F504("after set rd=%x(rem:%x)\n", v55, v54);
      goto LABEL_21;
    case 0x13:
      v52 = sub_11416C(result);
      v53 = LOBYTE(result[0]);
      *(uint32_t *)v8 = LOBYTE(result[0]);
      sub_11F504("get vendor info: %x(rem:%x)\n", v53, v52);
      goto LABEL_21;
    case 0x14:
      if ( *(uint32_t *)(a2 + 4) )
      {
        v190 = *(uint8_t *)(a2 + 8);
        v158 = off_120D80;
        v191 = v190 != 0;
        *(uint32_t *)off_120D80 = v191;
        sub_11F504("set txpwr_manual_mode: %x\r\n", v191);
      }
      else
      {
        v158 = off_1209DC;
        sub_11F504("txpwr_manual_mode: %x\r\n", *(uint32_t *)off_1209DC);
      }
      *(uint32_t *)v8 = *v158;
      goto LABEL_21;
    case 0x15:
      v150 = *(uint32_t *)(a2 + 4);
      if ( !v150 || (v151 = *(uint8_t *)(a2 + 8), !*(uint8_t *)(a2 + 8)) )
      {
        v169 = (char *)off_1209D8;
        sub_11F504(aTxpwrLevel24g0);
        for ( i = 0; i != 3; ++i )
        {
          sub_11F504("  [%x] =", i);
          v171 = v169;
          for ( j = 0; j != 12; ++j )
          {
            v174 = *v171++;
            v173 = v174;
            if ( v174 != -128 )
            {
              if ( j && !(j << 30) )
                sub_10D63C(32);
              sub_11F504(" %2d", v173);
            }
          }
          sub_10D654(off_120A00);
          v169 += 12;
        }
        v175 = (char *)off_1209D0;
        sub_11F504(aTxpwrLevel5g01);
        for ( k = 0; k != 3; ++k )
        {
          sub_11F504("  [%x] =", k);
          v177 = v175;
          for ( m = 0; m != 12; ++m )
          {
            v180 = *v177++;
            v179 = v180;
            if ( v180 != -128 )
            {
              if ( m && !(m << 30) )
                sub_10D63C(32);
              sub_11F504(" %2d", v179);
            }
          }
          sub_10D654(off_120A00);
          v175 += 12;
        }
        goto LABEL_233;
      }
      if ( v151 == 1 )
      {
        if ( v150 > 3 )
        {
          v152 = *(uint8_t *)(a2 + 9);
          if ( v152 <= 2 )
          {
            if ( v150 <= 0xB )
            {
              v153 = *(uint8_t *)(a2 + 10);
              if ( v152 == 1 )
                v210 = *(uint8_t *)(a2 + 10) <= 9u;
              else
                v210 = *(uint8_t *)(a2 + 10) <= 0xBu;
              if ( v210 )
              {
                v155 = *(char *)(a2 + 11);
                v156 = off_121148;
                v157 = aSetTxpwrLevel2;
                goto LABEL_230;
              }
              goto LABEL_385;
            }
            sub_11F504("set txpwr_level_2.4g:\n  [%d] =", *(uint8_t *)(a2 + 9));
            v231 = a2 + 9;
            v232 = dword_1212C8 + 12 * v152;
            for ( n = 0; v152 != 1 || n <= 9; ++n )
            {
              v235 = *(char *)++v231;
              v234 = v235;
              if ( v235 >= 32 )
                v234 = 32;
              *(uint8_t *)++v232 = v234;
              if ( n )
              {
                if ( !(n << 30) )
                  sub_10D63C(32);
                sub_11F504(" %2d", v234);
                if ( n == 11 )
                  break;
              }
              else
              {
                sub_11F504(" %2d", v234);
              }
            }
LABEL_397:
            sub_10D654(off_1212C0);
            goto LABEL_233;
          }
LABEL_383:
          sub_11F504("wrong lvl grp:%d\n", v152);
LABEL_233:
          sub_1282E8(v8, (char *)off_1209D8, 0x24u);
          sub_1282E8(v8 + 36, (char *)off_1209D0, 0x24u);
          goto LABEL_21;
        }
      }
      else
      {
        if ( v151 != 2 )
        {
          sub_11F504(aWrongFunc);
          goto LABEL_233;
        }
        if ( v150 > 3 )
        {
          v152 = *(uint8_t *)(a2 + 9);
          if ( v152 <= 2 )
          {
            if ( v150 <= 0xB )
            {
              v153 = *(uint8_t *)(a2 + 10);
              if ( v152 == 1 )
                v154 = *(uint8_t *)(a2 + 10) <= 9u;
              else
                v154 = *(uint8_t *)(a2 + 10) <= 0xBu;
              if ( v154 )
              {
                v155 = *(char *)(a2 + 11);
                v156 = off_1209D0;
                v157 = aSetTxpwrLevel5;
LABEL_230:
                if ( v155 >= 32 )
                  LOBYTE(v155) = 32;
                v156[12 * v152 + v153] = v155;
                sub_11F504(v157, v152);
                goto LABEL_233;
              }
LABEL_385:
              sub_11F504("wrong grp idx:%d\n", v153);
              goto LABEL_233;
            }
            sub_11F504("set txpwr_level_5g:\n  [%d] =", *(uint8_t *)(a2 + 9));
            v226 = a2 + 9;
            v227 = dword_1212BC + 12 * v152;
            for ( ii = 0; v152 != 1 || ii <= 9; ++ii )
            {
              v230 = *(char *)++v226;
              v229 = v230;
              if ( v230 >= 32 )
                v229 = 32;
              *(uint8_t *)++v227 = v229;
              if ( ii )
              {
                if ( !(ii << 30) )
                  sub_10D63C(32);
                sub_11F504(" %2d", v229);
                if ( ii == 11 )
                  goto LABEL_397;
              }
              else
              {
                sub_11F504(" %2d", v229);
              }
            }
            goto LABEL_397;
          }
          goto LABEL_383;
        }
      }
      sub_11F504(aWrongArgs_0);
      goto LABEL_233;
    case 0x16:
      v9 = *(uint32_t *)(a2 + 4);
      if ( v9 && (v10 = *(uint8_t *)(a2 + 8), *(uint8_t *)(a2 + 8)) )
      {
        if ( v10 == 1 )
        {
          v211 = (uint8_t *)off_121150;
          ++*(uint8_t *)off_121150;
          if ( v9 > 3 )
          {
            v212 = *(uint8_t *)(a2 + 9);
            if ( v212 <= 2 )
            {
              v213 = *(uint8_t *)(a2 + 10);
              if ( v213 <= 2 )
              {
                v214 = *(char *)(a2 + 11);
                v21 = (char **)off_12119C;
                v215 = (uint16_t *)off_121154;
                if ( v214 < -7 )
                  v214 = -7;
                if ( v214 >= 7 )
                  v214 = 7;
                *(uint8_t *)(*(uint32_t *)off_12119C + v213 + 3 * v212) = v214;
                v216 = v215[20];
                v217 = *((uint8_t *)v215 + 36);
                if ( v216 <= 0x97B )
                {
                  v218 = 0;
                }
                else if ( v216 > 0x994 )
                {
                  v218 = 2;
                }
                else
                {
                  v218 = 1;
                }
                if ( !v217 && v218 == v213 )
                {
                  sub_10090C(0, v216);
                  ++*v211;
                }
                v219 = v212;
                v15 = (char **)off_12115C;
                sub_11F504("set pwrofst2x_2.4g:\n  [%d][%d]=%d\n", v219, v213, v214);
                goto LABEL_20;
              }
            }
            goto LABEL_373;
          }
        }
        else
        {
          if ( v10 != 2 )
          {
            v21 = (char **)off_12119C;
            v15 = (char **)off_12115C;
            sub_11F504(aWrongFunc_0);
            goto LABEL_20;
          }
          v11 = (uint8_t *)off_11FCD0;
          ++*(uint8_t *)off_11FCD0;
          if ( v9 > 3 )
          {
            v12 = *(uint8_t *)(a2 + 9);
            if ( v12 <= 2 )
            {
              v13 = *(uint8_t *)(a2 + 10);
              if ( v13 <= 5 )
              {
                v14 = *(char *)(a2 + 11);
                v15 = (char **)off_11FCD4;
                v16 = (uint16_t *)off_11FCD8;
                if ( v14 < -7 )
                  v14 = -7;
                if ( v14 >= 7 )
                  v14 = 7;
                *(uint8_t *)(*(uint32_t *)off_11FCD4 + v13 + 6 * v12) = v14;
                v17 = v16[20];
                v18 = *((uint8_t *)v16 + 36);
                if ( v17 > 0x1666 )
                {
                  v19 = 5;
                }
                else if ( v17 > 0x1616 )
                {
                  v19 = 4;
                }
                else if ( v17 > 0x15C6 )
                {
                  v19 = 3;
                }
                else if ( v17 > 0x1571 )
                {
                  v19 = 2;
                }
                else
                {
                  v19 = v17 > 0x1486;
                }
                if ( v18 == 1 && v19 == v13 )
                {
                  sub_10090C(1, v17);
                  ++*v11;
                }
                v20 = v13;
                v21 = (char **)off_11FD2C;
                sub_11F504("set pwrofst2x_5g:\n  [%d][%d]=%d\n", v12, v20, v14);
                goto LABEL_20;
              }
            }
LABEL_373:
            v21 = (char **)off_12119C;
            v15 = (char **)off_12115C;
            sub_11F504(aWrongTypeChgrp);
            goto LABEL_20;
          }
        }
        v21 = (char **)off_12119C;
        v15 = (char **)off_12115C;
        sub_11F504(aWrongArgs);
      }
      else
      {
        v21 = (char **)off_120DC8;
        sub_11F504(aPwrofst2x24g01);
        sub_11F504(aChan14591013);
        for ( jj = 0; jj != 3; ++jj )
        {
          sub_11F504("\n  [%d] =", jj);
          for ( kk = 0; kk != 3; ++kk )
          {
            v183 = (*v21)[3 * jj + kk];
            sub_11F504("\t%d", v183);
          }
        }
        v15 = (char **)off_120D64;
        sub_11F504(aPwrofst2x5g0Of);
        sub_11F504(aChan3650516498);
        for ( mm = 0; mm != 3; ++mm )
        {
          sub_11F504("\n  [%d] =", mm);
          for ( nn = 0; nn != 6; ++nn )
          {
            v186 = (*v15)[6 * mm + nn];
            sub_11F504("\t%d", v186);
          }
        }
        sub_11F504((const char *)off_120D6C);
      }
LABEL_20:
      sub_1282E8(v8, *v21, 9u);
      sub_1282E8(v8 + 9, *v15, 0x12u);
LABEL_21:
      sub_11DE50((int)v8);
      return 0;
    case 0x18:
      v82 = *(uint32_t *)(a2 + 4);
      if ( v82 )
      {
        v83 = *(uint8_t *)(a2 + 8);
        if ( !*(uint8_t *)(a2 + 8) )
        {
          v84 = *(uint8_t *)(a2 + 8);
          v82 = v84;
          v85 = v84;
          goto LABEL_129;
        }
        if ( v82 <= 3 )
        {
          sub_11F504(aWrongArgs);
        }
        else
        {
          v84 = *(uint8_t *)(a2 + 10);
          v85 = *(char *)(a2 + 11);
          if ( (uint8_t)(*(uint8_t *)(a2 + 11) + 7) <= 0xEu )
          {
            v82 = *(uint8_t *)(a2 + 8);
            v83 = *(uint8_t *)(a2 + 9);
LABEL_129:
            sub_122728(v82, v83, v84, v85);
            goto LABEL_130;
          }
          sub_11F504("wrong ofst val: %d\n", *(char *)(a2 + 11));
        }
LABEL_130:
        sub_1282E8(v8, *(char **)off_1202E8[0], 9u);
        sub_1282E8(v8 + 9, *(char **)off_1202EC, 0x12u);
        sub_1282E8(v8 + 27, (char *)dword_1202F0, 9u);
        sub_1282E8(v8 + 36, (char *)dword_1202F4, 0x12u);
        goto LABEL_21;
      }
      v84 = 0;
      v83 = 0;
      v85 = 0;
      goto LABEL_129;
    case 0x19:
      v148 = *(uint32_t *)(a2 + 4);
      if ( !v148 )
        goto LABEL_269;
      if ( v148 > 1 )
      {
        v149 = *(uint8_t *)(a2 + 9);
        v148 = *(uint8_t *)(a2 + 8);
LABEL_218:
        v34 = sub_122688(v148, v149);
        goto LABEL_54;
      }
      if ( *(uint8_t *)(a2 + 8) != 1 )
      {
        v148 = *(uint8_t *)(a2 + 8);
LABEL_269:
        v149 = 0;
        goto LABEL_218;
      }
      goto LABEL_295;
    case 0x1A:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_244;
      v147 = *(uint8_t *)(a2 + 8);
      if ( v147 > 2 )
        sub_11F504(aWrongFunc);
      else
        sub_125AD8(v147);
      goto LABEL_21;
    case 0x1D:
      sub_126258(*(uint8_t *)(a2 + 8), *(uint8_t *)(a2 + 9), *(uint8_t *)(a2 + 10));
      *(uint32_t *)v8 = *(uint8_t *)off_11FF88;
      goto LABEL_21;
    case 0x1E:
      if ( sub_12645C() )
        sub_11F504("curr cob state is %d\n", *(uint8_t *)off_120DA4);
      if ( *(uint8_t *)off_11FF88 == 1 )
      {
        v203 = sub_10F15C();
        v204 = *(uint32_t *)off_121130;
        v205 = *(uint8_t *)off_121134;
        v206 = (int *)off_12113C;
        *((uint32_t *)v8 + 1) = *off_121138;
        v207 = (v205 << 16) | (((v204 >> 18) & 0x3F) << 8) | v203;
        v208 = *v206;
        v209 = v206[1];
        *(uint32_t *)v8 = v207;
        *((uint32_t *)v8 + 2) = v208;
        *((uint32_t *)v8 + 3) = v209;
      }
      else if ( *(uint8_t *)off_11FF8C )
      {
        v40 = (uint32_t *)dword_11FF90;
        v41 = &v8[4 * (uint8_t)(*(uint8_t *)off_11FF8C - 1) + 4];
        v42 = v8;
        do
        {
          *(uint32_t *)v42 = *v40;
          *((uint32_t *)v42 + 1) = v40[1];
          v42 += 4;
          v40 += 2;
        }
        while ( v42 != v41 );
      }
      goto LABEL_21;
    case 0x20:
      if ( *(uint32_t *)(a2 + 4) )
        sub_126764(*(uint8_t *)(a2 + 8));
      else
LABEL_244:
        sub_11F504(aWrongArgs_0);
      goto LABEL_21;
    case 0x23:
      v36 = *(uint32_t *)(a2 + 4);
      if ( !v36 )
        goto LABEL_281;
      v7 = *(uint8_t *)(a2 + 8);
      if ( v36 > 1 )
      {
        v37 = *(uint8_t *)(a2 + 9);
        v36 = *(uint8_t *)(a2 + 8);
LABEL_63:
        v34 = sub_122F3C(v36, v37, v6, v7);
        goto LABEL_54;
      }
      if ( v7 != 1 )
      {
        v36 = *(uint8_t *)(a2 + 8);
LABEL_281:
        v37 = 0;
        goto LABEL_63;
      }
      goto LABEL_295;
    case 0x24:
      v38 = *(uint32_t *)(a2 + 4);
      if ( !v38 )
        goto LABEL_247;
      if ( v38 <= 4 )
      {
        if ( *(uint8_t *)(a2 + 8) == 1 )
        {
LABEL_295:
          sub_11F504(aWrongArgs_0);
          v34 = -4;
LABEL_54:
          *(uint32_t *)v8 = v34;
          goto LABEL_21;
        }
        v38 = *(uint8_t *)(a2 + 8);
LABEL_247:
        v39 = 0;
      }
      else
      {
        v39 = *(uint32_t *)(a2 + 9);
        v38 = *(uint8_t *)(a2 + 8);
      }
      v34 = sub_122FA4(v38, v39);
      goto LABEL_54;
    case 0x25:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_243;
      v35 = *(uint8_t *)(a2 + 8);
      *(uint32_t *)off_11FD28 = v35;
LABEL_59:
      sub_1268EC(v35);
      goto LABEL_21;
    case 0x26:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_243;
      sub_126D60(*(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0x27:
      v33 = *(uint32_t *)(a2 + 4);
      if ( v33 )
      {
        v33 = *(uint8_t *)(a2 + 8);
        if ( v33 > 1 )
          goto LABEL_295;
      }
      v34 = sub_123020(v33);
      goto LABEL_54;
    case 0x28:
      sub_11F504(aSetUsbOff);
      sub_11DAFC(1071, 1, dword_11FD24);
      goto LABEL_21;
    case 0x50:
      sub_100200((int *)dword_11FD10, 0, 2u);
      if ( *(uint32_t *)(a2 + 4) != 2 )
      {
        sub_11F504("argc err %d, countrycode error, setcc fail\n", *(uint32_t *)(a2 + 4));
        goto LABEL_21;
      }
      if ( !*(uint8_t *)(a2 + 8) )
        goto LABEL_21;
      if ( *(uint8_t *)(a2 + 9) )
      {
        v30 = a2 + 8;
        if ( sub_125E0C(off_11FD14, v30) )
        {
          sub_11F504(aSetccSuccess);
          v31 = 2;
          v32 = (char *)v30;
          goto LABEL_48;
        }
      }
      else
      {
        a1a = a2 + 8;
        if ( sub_125E0C(off_121174, a2 + 8) )
        {
          sub_11F504(aSetccSuccess);
          v32 = (char *)a1a;
          v31 = 1;
LABEL_48:
          sub_1282E8((char *)dword_11FD10, v32, v31);
          sub_11F504("country code: %s\n", (const char *)dword_11FD10);
          if ( (*(uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            sub_114844(dword_11FD10);
          goto LABEL_21;
        }
      }
      sub_11F504(aCountrycodeErr);
      goto LABEL_21;
    case 0x51:
      LOWORD(result[0]) = 0;
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        sub_11F504("getcc: %s\r\n", (const char *)dword_120D7C);
        sub_1282E8((char *)result, (char *)dword_120D7C, 2u);
        goto LABEL_30;
      }
      sub_114838((int)result);
      if ( LOBYTE(result[0]) != 255 )
        goto LABEL_28;
      goto LABEL_42;
    case 0x52:
      *v5 = *(char *)off_11FD08;
      goto LABEL_21;
    case 0x5B:
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        sub_11F504(aRdwrFlashUsbvi);
      }
      else
      {
        v26 = *(uint32_t *)(a2 + 4);
        if ( v26 )
        {
          sub_11F504("argc %d\n", v26);
          v27 = *(uint32_t *)(a2 + 4);
          *(uint32_t *)v8 = 0xFFFF;
          *((uint32_t *)v8 + 1) = 0xFFFF;
          if ( v27 > 3 )
          {
            v28 = *(uint16_t *)(a2 + 8);
            v29 = *(uint16_t *)(a2 + 10);
            sub_11F504("set vid 0x%04x, pid 0x%04x\n", v28, v29);
            sub_100200(result, 0, 4u);
            LOWORD(result[0]) = v28;
            HIWORD(result[0]) = v29;
            sub_11485C((int)result);
            *(uint32_t *)v8 = v28;
            *((uint32_t *)v8 + 1) = v29;
          }
        }
        else
        {
          sub_100200(result, 0, 4u);
          v196 = sub_114850((int)result);
          sub_11F504("ret %d\n", v196);
          if ( v196 || HIWORD(result[0]) == 0xFFFF || LOWORD(result[0]) == 0xFFFF )
          {
            sub_11F504(aNoUsbInfoInFla);
          }
          else
          {
            sub_11F504("get vid 0x%04x, pid 0x%04x\r\n", LOWORD(result[0]), HIWORD(result[0]));
            LODWORD(v197) = LOWORD(result[0]);
            HIDWORD(v197) = HIWORD(result[0]);
            *(uint64_t *)v8 = v197;
          }
        }
      }
      goto LABEL_21;
    case 0x5C:
      sub_100200((int *)dword_11FCF0, 0, 2u);
      if ( *(uint32_t *)(a2 + 4) == 2 )
      {
        v25 = (char *)(a2 + 8);
        if ( sub_125E0C(off_11FCF4, (int)v25) )
        {
          sub_11F504(aSetchSuccess);
          sub_1282E8((char *)dword_11FCF0, v25, 2u);
          sub_11F504("channel country code: %s\n", (const char *)dword_11FCF0);
          if ( (*(uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            sub_114874(dword_11FCF0);
        }
        else
        {
          sub_11F504(aChannelCountry);
        }
      }
      goto LABEL_21;
    case 0x5D:
      LOWORD(result[0]) = 0;
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        sub_11F504("getcc: %s\r\n", (const char *)dword_120D74);
        sub_1282E8((char *)result, (char *)dword_120D74, 2u);
      }
      else
      {
        sub_114868((int)result);
        if ( LOBYTE(result[0]) != 255 )
        {
LABEL_28:
          if ( BYTE1(result[0]) != 255 )
          {
            sub_11F504("getcc: %s\r\n", (const char *)result);
            goto LABEL_30;
          }
        }
LABEL_42:
        sub_11F504(aNoCountrycodeI);
      }
LABEL_30:
      *(uint32_t *)v8 = LOWORD(result[0]);
      goto LABEL_21;
    case 0x5E:
      goto LABEL_25;
    case 0x5F:
      if ( *(uint32_t *)(a2 + 4) )
      {
        v23 = *(uint8_t *)(a2 + 8);
        sub_1149FC(v23);
        if ( v23 )
          sub_11F504(aEnableBlockPro);
        else
          sub_11F504(aDisableBlockPr);
      }
      else
      {
        sub_11F504(aWrongArgs);
      }
LABEL_25:
      v24 = sub_1149BC();
      sub_11F504("get block protect: %d\n", v24);
      *(uint32_t *)v8 = v24;
      goto LABEL_21;
    case 0x60:
      sub_100200(result, 0, 0x40u);
      sub_100200(result, 0, 0x40u);
      if ( !*(uint32_t *)(a2 + 4) )
      {
        LOWORD(a2a) = 0;
        goto LABEL_162;
      }
      v198 = *(uint8_t *)(a2 + 8);
      sub_11F504("channel_num %d\n", v198);
      if ( v198 > 0x23 )
      {
        v107 = 5 * v198 + 5000;
        v242 = v107;
        LOWORD(a2a) = 1;
        goto LABEL_163;
      }
      LOWORD(a2a) = 0;
      if ( v198 <= 0xD )
      {
        v107 = 5 * v198 + 2407;
        v242 = v107;
        goto LABEL_163;
      }
      if ( v198 == 14 )
      {
LABEL_162:
        v107 = 2484;
        v242 = 2484;
LABEL_163:
        HIWORD(a2a) = v107;
        v243 = 0;
        v244 = 0;
        sub_1246F0(0, (int)&a2a);
        sub_108D34(0xFFFF, (int)result);
        sub_1282E8(v8, (char *)result, 0x40u);
        goto LABEL_21;
      }
      sub_11F504("Not supported chan: %d\n", v198);
      return -2;
    case 0x61:
      if ( (*(uint32_t *)off_120318 & 0x2000000) != 0 )
      {
        sub_11F504(aRdwrFlashPcieI, *(uint32_t *)off_120318 << 6);
      }
      else
      {
        v100 = *(uint32_t *)(a2 + 4);
        *v5 = 0xFFFF;
        v5[1] = 0xFFFF;
        v5[2] = 0xFFFF;
        v5[3] = 0xFFFF;
        v5[4] = 255;
        if ( v100 )
        {
          sub_11F504("argc %d\n", v100);
          if ( *(uint32_t *)(a2 + 4) > 8u )
          {
            v101 = *(uint8_t *)(a2 + 16);
            v102 = *(uint8_t *)(a2 + 14) | (*(uint8_t *)(a2 + 15) << 8);
            v103 = *(uint8_t *)(a2 + 8) | (*(uint8_t *)(a2 + 9) << 8);
            v104 = *(uint8_t *)(a2 + 10) | (*(uint8_t *)(a2 + 11) << 8);
            v105 = *(uint64_t *)(a2 + 8);
            a1a = *(uint8_t *)(a2 + 12) | (*(uint8_t *)(a2 + 13) << 8);
            sub_11F504(
              "set vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\n",
              v103,
              v104,
              a1a,
              v102,
              v101);
            sub_100200(result, 0xFFu, 0xAu);
            *(uint64_t *)result = v105;
            v246 = v101;
            sub_11488C((int)result);
            v106 = a1a;
            *((uint32_t *)v8 + 4) = v101;
            *(uint32_t *)v8 = v103;
            *((uint32_t *)v8 + 1) = v104;
            *((uint32_t *)v8 + 2) = v106;
            *((uint32_t *)v8 + 3) = v102;
          }
        }
        else
        {
          sub_100200(result, 0xFFu, 0xAu);
          v193 = sub_114880((int)result);
          sub_11F504("ret %d\n", v193);
          if ( v193 )
          {
            sub_11F504(aNoPcieInfoInFl);
          }
          else
          {
            sub_11F504(
              "get vid %x, did %x, subsys_vid %x, subsys_id %x, rev_id %x\r\n",
              LOWORD(result[0]),
              HIWORD(result[0]),
              LOWORD(result[1]),
              HIWORD(result[1]),
              v246);
            HIDWORD(v194) = HIWORD(result[1]);
            LODWORD(v195) = LOWORD(result[0]);
            HIDWORD(v195) = HIWORD(result[0]);
            LODWORD(v194) = LOWORD(result[1]);
            *(uint64_t *)v8 = v195;
            *((uint64_t *)v8 + 1) = v194;
            *((uint32_t *)v8 + 4) = v246;
          }
        }
      }
      goto LABEL_21;
    case 0x108:
      sub_11F504(aCheckFlash);
      result[0] = 0;
      sub_100200(&result[1], 0, 0x3FCu);
      if ( *(uint32_t *)(a2 + 4) == 8 )
      {
        v96 = *(uint32_t *)(a2 + 8);
        if ( !v96 )
          v96 = 0x4000000;
        if ( (*(uint32_t *)off_120318 & 0x2000000) == 0 )
        {
          v97 = *(uint32_t *)(a2 + 12);
          if ( v97 )
          {
LABEL_149:
            sub_11F504("crc begin 0x%x 0x%x\n", v96, v97);
            if ( v97 >> 10 )
            {
              v98 = v96;
              v99 = -1;
              do
              {
                sub_1142D8(v98, 1024, (int)result);
                v98 += 1024;
                v99 = sub_11EB48((uint8_t *)result, 1024, v99);
              }
              while ( v98 != v96 + (v97 >> 10 << 10) );
            }
            else
            {
              v99 = -1;
            }
            if ( (v97 & 0x3FF) != 0 )
            {
              sub_1142D8((v97 & 0xFFFFFC00) + v96, v97 & 0x3FF, (int)result);
              v99 = sub_11EB48((uint8_t *)result, v97 & 0x3FF, v99);
            }
            sub_11F504("crc_res 0x%x\n", v99);
LABEL_155:
            *(uint32_t *)v8 = v99;
            goto LABEL_21;
          }
LABEL_148:
          v97 = sub_114218();
          goto LABEL_149;
        }
      }
      else if ( (*(uint32_t *)off_120318 & 0x2000000) == 0 )
      {
        v96 = 0x4000000;
        goto LABEL_148;
      }
      v99 = -1;
      goto LABEL_155;
    default:
      goto LABEL_21;
  }
}
