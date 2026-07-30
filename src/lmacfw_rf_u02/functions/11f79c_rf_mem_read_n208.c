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

extern uint32_t off_120670;
extern uint32_t off_12112C;
extern uint32_t off_120674;
extern uint32_t dword_12067C;
extern uint32_t off_120678;
extern uint32_t dword_120680;
extern uint32_t dword_120684;
extern uint32_t off_120688;
extern uint32_t dword_120DC4;
extern uint32_t dword_121108;
extern uint32_t off_120654;
extern uint32_t off_120658;
extern uint32_t off_120690;
extern uint32_t off_12068C;
extern uint32_t dword_120694;
extern uint32_t dword_120698;
extern uint32_t dword_120650;
extern uint32_t off_12065C;
extern uint32_t off_120660;
extern uint32_t off_120664;
extern uint32_t dword_120668;
extern uint32_t dword_12066C;
extern uint32_t dword_12118C;
extern uint32_t dword_121190;
extern uint32_t dword_121194;
extern uint32_t dword_1206A4;
extern uint32_t off_1206A8;
extern uint32_t off_1206AC;
extern uint32_t dword_1206B0;
extern uint32_t off_1206B4;
extern uint32_t off_1206B8;
extern uint32_t off_1206BC;
extern uint32_t dword_1209F0;
extern uint32_t dword_121110;
extern uint32_t dword_121114;
extern uint32_t off_12111C;
extern uint32_t off_121120;
extern uint32_t off_121118;
extern uint32_t dword_11FFD0;
extern uint32_t off_11FFD4;
extern uint32_t off_11FFD8;
extern uint32_t off_11FFDC;
extern uint32_t off_11FFE0;
extern uint32_t off_11FFE4;
extern uint32_t dword_12110C;
extern uint32_t off_1202C4;
extern uint32_t off_1202C0;
extern uint32_t off_1202C8;
extern uint32_t off_1202CC;
extern uint32_t dword_1202D0;
extern uint32_t dword_1202D4;
extern uint32_t dword_120DB0;
extern uint32_t off_1202DC;
extern uint32_t off_1202D8;
extern uint32_t off_1202E0;
extern uint32_t dword_1202E4;
extern uint32_t dword_120304;
extern uint32_t off_120308;
extern uint32_t off_12030C;
extern uint32_t dword_120310;
extern uint32_t dword_1202F8;
extern uint32_t off_1202FC;
extern uint32_t off_120300;
extern uint32_t dword_120D8C;
extern uint32_t dword_1209CC;
extern uint32_t dword_11FFA8;
extern uint32_t off_11FFB0;
extern uint32_t off_11FFAC;
extern uint32_t dword_11FFA0;
extern uint32_t dword_120DC0;
extern uint32_t off_120DBC;
extern uint32_t dword_11FFA4;
extern uint32_t off_11FF98;
extern uint32_t dword_11FF9C;
extern uint32_t dword_11FF94;
extern uint32_t dword_1209E4;
extern uint32_t dword_1209E8;
extern uint32_t off_1209C4;
extern uint32_t dword_121144;
extern uint32_t dword_1209EC;
extern uint32_t dword_1209C8;
extern uint32_t dword_11FFC8;
extern uint32_t off_11FFC0;
extern uint32_t dword_121124;
extern uint32_t dword_121128;
extern uint32_t dword_11FFCC;
extern uint32_t dword_11FFC4;
extern uint32_t dword_11FFB8;
extern uint32_t dword_11FFBC;
extern uint32_t dword_11FFB4;
extern uint32_t off_120D80;
extern uint32_t dword_120D84;
extern uint32_t off_1209DC;
extern uint32_t dword_1209E0;
extern uint32_t dword_1209D8;
extern uint32_t dword_120A08;
extern uint32_t dword_1209FC;
extern uint32_t dword_1209F8;
extern uint32_t dword_120A00;
extern uint32_t dword_1209D0;
extern uint32_t dword_120A04;
extern uint32_t dword_121148;
extern uint32_t dword_12114C;
extern uint32_t dword_1212CC;
extern uint32_t dword_1212C4;
extern uint32_t dword_1212C8;
extern uint32_t dword_1212C0;
extern uint32_t dword_121188;
extern uint32_t dword_121160;
extern uint32_t dword_1209D4;
extern uint32_t dword_121198;
extern uint32_t dword_1212B8;
extern uint32_t dword_1212BC;
extern uint32_t dword_121180;
extern uint32_t off_121150;
extern uint32_t off_12119C;
extern uint32_t off_121154;
extern uint32_t off_12115C;
extern uint32_t dword_121158;
extern uint32_t dword_121164;
extern uint32_t off_11FCD0;
extern uint32_t off_11FCD4;
extern uint32_t off_11FCD8;
extern uint32_t off_11FD2C;
extern uint32_t dword_11FCDC;
extern uint32_t dword_12116C;
extern uint32_t dword_121170;
extern uint32_t off_120DC8;
extern uint32_t dword_120DCC;
extern uint32_t dword_120DD0;
extern uint32_t dword_120D58;
extern uint32_t dword_120D5C;
extern uint32_t off_120D64;
extern uint32_t dword_120D60;
extern uint32_t dword_120D68;
extern uint32_t dword_120D6C;
extern uint32_t dword_121184;
extern uint32_t off_1202E8;
extern uint32_t off_1202EC;
extern uint32_t dword_1202F0;
extern uint32_t dword_1202F4;
extern uint32_t dword_120D9C;
extern uint32_t off_11FF88;
extern uint32_t dword_120DA8;
extern uint32_t off_120DA4;
extern uint32_t off_121130;
extern uint32_t off_121134;
extern uint32_t off_12113C;
extern uint32_t off_121138;
extern uint32_t off_11FF8C;
extern uint32_t dword_11FF90;
extern uint32_t dword_1209F4;
extern uint32_t dword_120D90;
extern uint32_t off_11FD28;
extern uint32_t dword_11FD20;
extern uint32_t dword_11FD24;
extern uint32_t dword_11FD10;
extern uint32_t dword_120D88;
extern uint32_t dword_11FD14;
extern uint32_t dword_11FD18;
extern uint32_t dword_121174;
extern uint32_t dword_121178;
extern uint32_t dword_11FD1C;
extern uint32_t off_11FCE8;
extern uint32_t dword_12117C;
extern uint32_t dword_120D78;
extern uint32_t dword_120D7C;
extern uint32_t off_11FD08;
extern uint32_t dword_120DB8;
extern uint32_t dword_11FD00;
extern uint32_t dword_11FD04;
extern uint32_t dword_120D94;
extern uint32_t dword_121100;
extern uint32_t dword_120DA0;
extern uint32_t dword_11FCF0;
extern uint32_t dword_11FCF4;
extern uint32_t dword_11FCF8;
extern uint32_t dword_11FCFC;
extern uint32_t dword_121168;
extern uint32_t dword_120D74;
extern uint32_t dword_11FCEC;
extern uint32_t dword_11FD0C;
extern uint32_t dword_11FCE0;
extern uint32_t dword_121104;
extern uint32_t dword_120D70;
extern uint32_t dword_11FCE4;
extern uint32_t dword_120DAC;
extern uint32_t off_120318;
extern uint32_t dword_120DB4;
extern uint32_t dword_120324;
extern uint32_t dword_120328;
extern uint32_t dword_121140;
extern uint32_t dword_120D98;
extern uint32_t dword_120314;
extern uint32_t dword_12031C;
extern uint32_t dword_120320;

// rf_mem_read_n208 @ 0x11f79c, size 6938 bytes
// Doc: rf_mem_read_n4a0 [rf]: Read RF memory entry and validate against expected value 0x1666
// rf_mem_read_n4a0 [rf]: Read RF memory entry and validate against expected value 0x1666
int  rf_mem_read_n208(int a1, int a2, int16_t a3, int16_t a4)
{
  uint32_t *v5; // r0
  uint32_t *v6; // r5
  unsigned int v7; // r3
  int v8; // r2
  uint8_t *v9; // r6
  unsigned int v10; // r9
  unsigned int v11; // r10
  int v12; // r8
  uint32_t *v13; // r7
  uint16_t *v14; // r0
  unsigned int v15; // r1
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  uint32_t *v19; // r10
  int v21; // r4
  int v22; // r4
  int v23; // r4
  unsigned int v24; // r2
  int v25; // r7
  int v26; // r4
  int v27; // r4
  int v28; // r2
  int v29; // r1
  int v30; // r0
  int v31; // r0
  unsigned int v32; // r0
  int v33; // r1
  unsigned int v34; // r0
  int v35; // r1
  uint32_t *v36; // r2
  uint32_t *v37; // r1
  uint32_t *v38; // r3
  int v39; // r4
  unsigned int *v40; // r6
  int v41; // r4
  uint8_t n; // r0
  int v43; // r6
  int v44; // r4
  int v45; // r4
  int v46; // r7
  int v47; // r0
  uint32_t *v48; // r2
  unsigned int v49; // r1
  unsigned int v50; // r2
  int v51; // r4
  unsigned int v52; // r2
  unsigned int v53; // r6
  int16_t v54; // r7
  unsigned int v55; // r8
  unsigned int v56; // r4
  int v57; // r3
  int v58; // r7
  uint32_t *v59; // r1
  int *v60; // r6
  uint32_t *v61; // r7
  uint32_t *v62; // r3
  int v63; // r9
  uint32_t *v64; // r8
  int v65; // r3
  int v66; // r3
  int v67; // r2
  unsigned int v68; // r6
  int v69; // r4
  int16_t v70; // r3
  int16_t v71; // r3
  uint32_t *v72; // r1
  int v73; // r4
  uint32_t *v74; // r3
  unsigned int v75; // r0
  int v76; // r1
  unsigned int v77; // r2
  unsigned int v78; // r3
  int *v79; // r6
  uint32_t *v80; // r4
  uint32_t *v81; // r7
  int v82; // r8
  int v83; // r3
  int v84; // r3
  int v85; // r2
  int v86; // r1
  int v87; // r2
  int v88; // r0
  int v89; // r8
  unsigned int v90; // r9
  int v91; // r11
  unsigned int v92; // r4
  int v93; // r1
  int v94; // r10
  int v95; // r7
  int v96; // r9
  int v97; // r8
  uint64_t v98; // kr00_8
  int v99; // r3
  int16_t v100; // r2
  int v101; // r3
  int v102; // r0
  int *v103; // r4
  int v104; // r3
  int v105; // r2
  int v106; // r6
  uint32_t *v107; // r3
  int v108; // r0
  int v109; // r3
  unsigned int v110; // r8
  unsigned int v111; // r9
  int v112; // r10
  int v113; // r7
  int v114; // r6
  int v115; // r11
  int v116; // r4
  unsigned int v117; // r4
  int *v118; // r8
  uint32_t *v119; // r0
  uint8_t *v120; // r1
  unsigned int v121; // r4
  int *v122; // r3
  int v123; // r6
  uint32_t *v124; // r3
  int v125; // r3
  int v126; // r4
  int v127; // r0
  float v128; // r0
  uint64_t v129; // r0
  int v130; // r0
  int v131; // r8
  unsigned int *v132; // r1
  unsigned int *v133; // r4
  int v134; // r6
  uint32_t *v135; // r2
  uint32_t *v136; // r0
  uint32_t *v137; // r6
  int v138; // r4
  unsigned int v139; // r0
  unsigned int v140; // r0
  int v141; // r1
  unsigned int v142; // r3
  int v143; // r2
  unsigned int v144; // r7
  int v145; // r2
  BOOL v146; // r3
  int v147; // r3
  int v148; // r1
  int v149; // r0
  uint32_t *v150; // r4
  int v151; // r0
  unsigned int v152; // r1
  unsigned int v153; // r3
  unsigned int v154; // r8
  int v155; // r4
  int v156; // r6
  int16_t v157; // r3
  int16_t v158; // r1
  int v159; // r6
  int v160; // r7
  int v161; // r9
  int v162; // r11
  int v163; // r7
  int i; // r8
  char *v165; // r10
  int j; // r4
  int v167; // r6
  int v168; // t1
  int v169; // r9
  int v170; // r11
  int v171; // r7
  int k; // r8
  char *v173; // r10
  int m; // r4
  int v175; // r6
  int v176; // t1
  int v177; // r9
  int v178; // r8
  int kk; // r6
  int mm; // r4
  int v181; // r1
  int v182; // r11
  int v183; // r8
  int nn; // r9
  int i1; // r4
  int v186; // r1
  int v187; // r0
  int inited; // r0
  int v189; // r0
  int v190; // r1
  int v191; // r0
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
  uint64_t v221; // r0
  uint64_t v222; // r0
  int v223; // r9
  int v224; // r10
  int v225; // r8
  unsigned int jj; // r4
  int v227; // r6
  int v228; // t1
  int v229; // r9
  int v230; // r10
  int v231; // r8
  unsigned int ii; // r4
  int v233; // r6
  int v234; // t1
  uint8_t v235[72]; // [sp+3Ch] [bp-468h] BYREF
  int v236; // [sp+84h] [bp-420h]
  int v237; // [sp+88h] [bp-41Ch]
  int v238; // [sp+8Ch] [bp-418h]
  unsigned int v239; // [sp+90h] [bp-414h] BYREF
  unsigned int v240; // [sp+94h] [bp-410h] BYREF
  int16_t v241; // [sp+98h] [bp-40Ch]
  int16_t v242; // [sp+9Ah] [bp-40Ah]
  char v243; // [sp+9Eh] [bp-406h]
  uint64_t v244; // [sp+A0h] [bp-404h] BYREF
  uint8_t v245; // [sp+A8h] [bp-3FCh]
  char v246; // [sp+AAh] [bp-3FAh]

  v5 = (uint32_t *)rf_setup_dispatch(1044, a4, a3, 0x48u);
  v6 = v5;
  switch ( *(uint32_t *)a2 )
  {
    case 0:
      if ( *(uint8_t *)off_120670 == 1 )
      {
        v202 = off_12112C;
        *(uint8_t *)off_120670 = 0;
        *v202 = 0;
        event_queue_push(144, 0);
      }
      v106 = *(uint32_t *)off_120674 & 0xF;
      if ( v106 == 3 )
        message_dispatch_n2fe();
      v107 = off_120674;
      v108 = dword_12067C;
      *(uint32_t *)off_120678 = 0;
      *v107 = 16 * v106;
      msg_parse(v108, *(uint32_t *)(a2 + 4));
      v109 = *(uint8_t *)(a2 + 10);
      v110 = *(uint8_t *)(a2 + 9);
      v111 = *(uint8_t *)(a2 + 8);
      v112 = *(uint8_t *)(a2 + 11);
      v113 = (uint16_t)(*(uint8_t *)(a2 + 12) + (*(uint8_t *)(a2 + 13) << 8));
      v114 = (uint16_t)(*(uint8_t *)(a2 + 14) + (*(uint8_t *)(a2 + 15) << 8));
      v115 = *(char *)(a2 + 16);
      v116 = *(uint8_t *)(a2 + 16);
      v237 = v109;
      v238 = v116;
      msg_parse(dword_120680, v111, v110, v109, v112, v113, v114);
      msg_parse(dword_120684, v115);
      v117 = v110;
      if ( (*(uint8_t *)off_120688 & 8) == 0 && v110 > 1 )
      {
        msg_parse(dword_120DC4, v110);
        goto LABEL_21;
      }
      sub_123FF0(v237, v112, 0);
      sub_123F4C(v113);
      LOBYTE(v244) = v111 > 0x23;
      BYTE1(v244) = v110;
      if ( v111 > 0x23 )
      {
        WORD2(v244) = 5 * v111 + 5000;
      }
      else if ( v111 > 0xD )
      {
        WORD2(v244) = 2484;
        if ( v111 != 14 )
        {
          msg_parse(dword_121108, v111);
          v110 = BYTE1(v244);
        }
      }
      else
      {
        WORD2(v244) = 5 * v111 + 2407;
      }
      HIWORD(v244) = 0;
      v246 = 0;
      if ( v110 )
      {
        if ( v110 == 1 )
        {
          if ( v111 == 1 || v111 == 36 )
            WORD1(v244) = WORD2(v244) + 10;
          else
            WORD1(v244) = WORD2(v244) - 10;
        }
      }
      else
      {
        WORD1(v244) = WORD2(v244);
      }
      v118 = (int *)off_120654;
      if ( *(uint32_t *)off_120654 )
        rf_level_apply_n_4ec(0);
      v119 = off_120658;
      v120 = off_120690;
      v121 = *(uint32_t *)off_12068C & 0xFFFFFE7F | (v117 << 7);
      v122 = (int *)(v114 - 1);
      if ( (unsigned int)(v114 - 1) > 0x30 )
        v122 = (int *)dword_120694;
      *(uint32_t *)off_12068C = v121;
      if ( (unsigned int)(v114 - 1) > 0x30 )
        *v122 = v114;
      if ( (unsigned int)(v238 - 1) <= 0x1E )
        *(uint8_t *)dword_120698 = v115;
      *v119 = 1;
      *v120 = 1;
      rf_state_get_n246(0, &v244, 0);
      if ( (uint8_t)v244 )
        rf_init_hw_setup(WORD2(v244));
      else
        mmio_clock_setup(WORD2(v244), BYTE1(v244));
      v31 = *v118;
      if ( !*v118 )
        goto LABEL_21;
      goto LABEL_59;
    case 1:
      msg_parse(dword_120650);
      v101 = *(uint32_t *)off_120654;
      *(uint32_t *)off_120658 = 0;
      if ( v101 )
        rf_level_apply_n_4ec(0);
      v102 = *(uint8_t *)off_12065C;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_120660 = 1;
      }
      v103 = (int *)off_120664;
      v237 = v102;
      ++*(uint32_t *)off_120664;
      rf_event_handler_8a4(v102);
      rf_bus_write_60fc(v237, dword_120668 + 28 * (int16_t)v237 + 12);
      if ( *v103 )
      {
        v104 = *v103 - 1;
        v105 = *(uint32_t *)off_120660;
        *v103 = v104;
        if ( !v104 )
        {
          if ( v105 )
            __enable_irq();
        }
      }
      msg_parse(dword_12066C);
      goto LABEL_21;
    case 2:
      if ( *(uint8_t *)off_120670 == 1 )
      {
        v201 = off_12112C;
        *(uint8_t *)off_120670 = 0;
        *v201 = 0;
        event_queue_push(144, 0);
      }
      v123 = *(uint32_t *)off_120674 & 0xF;
      if ( v123 == 3 )
        message_dispatch_n2fe();
      v124 = off_120674;
      *(uint32_t *)off_120678 = 0;
      *v124 = 16 * v123;
      v125 = *(uint32_t *)(a2 + 4);
      if ( !v125 )
        goto LABEL_243;
      if ( *(uint8_t *)(a2 + 8) )
      {
        if ( *(uint8_t *)(a2 + 8) == 1 )
        {
          if ( v125 == 2 )
          {
            v126 = *(char *)(a2 + 9);
            v127 = sub_12754C(v126);
            v128 = sub_127BE4(v127);
            if ( v126 <= 0 )
            {
              v220 = sub_127570(LODWORD(v128));
              v221 = sub_1272B4(v220, HIDWORD(v220), 0, dword_12118C);
              v222 = sub_127874(v221, HIDWORD(v221), 0, dword_121190);
              v129 = sub_127620(v222, HIDWORD(v222), 0, dword_121194);
            }
            else
            {
              v129 = sub_127570((float)(v128 / flt_12069C) * flt_1206A0);
            }
            v130 = math_round(v129, HIDWORD(v129));
            v131 = sub_127BA4(v130);
            msg_parse(dword_1206A4, v126, v131, 1023, 1);
            v132 = (unsigned int *)off_1206A8;
            v133 = (unsigned int *)off_1206AC;
            v134 = dword_1206B0;
            v135 = off_1206B4;
            v136 = off_1206B8;
            *(uint32_t *)off_1206A8 = ~(~((*(uint32_t *)off_1206A8 & 0xFFFFF000) >> 10) << 10);
            *v133 = *v133 & 0xFFFFFFC0 | 1;
            *v133 |= 0x40u;
            *v133 |= 0x80u;
            *v132 = v134 & (v131 << 12) | *v132 & 0xFC000FFF;
            v137 = off_1206BC;
            *v135 |= 0x1000000u;
            *v137 |= 0x10000u;
            *v132 |= 0x10000000u;
            *v136 |= 0x100u;
            sub_12266C(200);
            *v133 = *v133 & 0xFF87FFFF | 0x100000;
            sub_12266C(200);
            *v133 |= 0x400000u;
            sub_12266C(200);
            *v133 |= 0x200000u;
          }
          else
          {
LABEL_243:
            msg_parse(dword_1209F0);
          }
        }
        else
        {
          msg_parse(dword_121110);
        }
      }
      else
      {
        msg_parse(dword_121114);
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
      msg_parse(dword_11FFD0);
      if ( !*(uint8_t *)off_11FFD4 )
      {
        v59 = off_11FFD8;
        *(uint8_t *)off_11FFD4 = 1;
        if ( *v59 << 28 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_11FFDC = 1;
          }
          v60 = (int *)off_11FFE0;
          v61 = off_11FFD8;
          v62 = off_11FFE4;
          ++*(uint32_t *)off_11FFE0;
          *v61 = 0;
          v63 = v62[4];
          v64 = v62;
          while ( *v61 << 28 )
          {
            if ( (unsigned int)(v64[4] - v63) > 0x7530 )
              msg_parse(dword_12110C);
          }
          while ( (*(uint32_t *)off_1202C4 & *(uint32_t *)off_1202C0 & 4) == 0 )
            ;
          v65 = *v60;
          *(uint32_t *)off_1202C8 = 4;
          if ( v65 )
          {
            v66 = v65 - 1;
            v67 = *(uint32_t *)off_1202CC;
            *v60 = v66;
            if ( !v66 )
            {
              if ( v67 )
                __enable_irq();
            }
          }
          msg_parse(dword_1202D0);
        }
      }
      v68 = *(uint8_t *)(a2 + 8);
      v69 = *(uint8_t *)(a2 + 9);
      msg_parse(dword_1202D4, v68, v69);
      LOBYTE(v244) = v68 > 0x23;
      BYTE1(v244) = v69;
      if ( v68 > 0x23 )
      {
        v70 = 5 * v68 + 5000;
        WORD2(v244) = v70;
      }
      else
      {
        if ( v68 > 0xD )
        {
          WORD2(v244) = 2484;
          if ( v68 == 14 )
          {
            HIWORD(v244) = 0;
            v246 = 0;
            if ( v69 == 1 )
              v71 = 2474;
            else
              v71 = 2514;
            goto LABEL_120;
          }
          msg_parse(dword_120DB0, v68);
          HIWORD(v244) = 0;
          v246 = 0;
          v70 = WORD2(v244);
          if ( BYTE1(v244) != 1 )
            goto LABEL_119;
          goto LABEL_322;
        }
        v70 = 5 * v68 + 2407;
        WORD2(v244) = v70;
      }
      HIWORD(v244) = 0;
      v246 = 0;
      if ( v69 != 1 )
      {
LABEL_119:
        v71 = v70 + 30;
LABEL_120:
        WORD1(v244) = v71;
        goto LABEL_121;
      }
      if ( v68 == 1 )
      {
LABEL_336:
        WORD1(v244) = v70 + 10;
LABEL_121:
        rf_state_get_n246(0, &v244, 0);
        v72 = off_1202DC;
        *(uint32_t *)off_1202D8 |= 0x10u;
        v73 = *v72 & 0xF;
        if ( v73 == 3 )
          message_dispatch_n2fe();
        v74 = off_1202DC;
        *(uint32_t *)off_1202E0 = dword_1202E4;
        *v74 = 16 * v73;
        mmio_init_clock_gate_n121();
        goto LABEL_21;
      }
LABEL_322:
      if ( v68 != 36 )
      {
        v71 = v70 - 10;
        goto LABEL_120;
      }
      goto LABEL_336;
    case 4:
      msg_parse(dword_120304);
      v86 = *(uint32_t *)off_120308;
      v87 = *(uint32_t *)off_12030C;
      v88 = dword_120310;
      *v6 = *(uint32_t *)off_120308;
      v6[1] = v87 + v86;
      msg_parse(v88);
      goto LABEL_21;
    case 5:
      msg_parse(dword_1202F8);
      if ( *(uint32_t *)off_1202DC << 28 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_1202CC = 1;
        }
        v79 = (int *)off_1202FC;
        v80 = off_1202DC;
        v81 = off_120300;
        ++*(uint32_t *)off_1202FC;
        *v80 = 0;
        v82 = v81[4];
        while ( *v80 << 28 )
        {
          if ( (unsigned int)(v81[4] - v82) > 0x7530 )
            msg_parse(dword_120D8C, *v80 << 28, 30000);
        }
        while ( (*(uint32_t *)off_1202C4 & *(uint32_t *)off_1202C0 & 4) == 0 )
          ;
        v83 = *v79;
        *(uint32_t *)off_1202C8 = 4;
        if ( v83 )
        {
          v84 = v83 - 1;
          v85 = *(uint32_t *)off_1202CC;
          *v79 = v84;
          if ( !v84 )
          {
            if ( v85 )
              __enable_irq();
          }
        }
        msg_parse(dword_1202D0);
      }
      goto LABEL_21;
    case 6:
      msg_parse(dword_1209CC);
      goto LABEL_21;
    case 7:
      msg_parse(dword_11FFA8, *(uint8_t *)(a2 + 8));
      v48 = off_11FFB0;
      *(uint32_t *)off_11FFAC = *(uint8_t *)(a2 + 8) | (*(uint8_t *)(a2 + 8) << 8);
      *v48 = 1;
      goto LABEL_21;
    case 8:
      n = mmio_bit_extract_n();
      v43 = *(uint8_t *)(a2 + 8);
      v44 = (char)(v43 + n);
      if ( v44 < 1 )
        v44 = 1;
      if ( v44 >= 31 )
        v44 = 31;
      msg_parse(dword_11FFA0, n, v44);
      sub_10F170(v44);
      v45 = (uint8_t)mmio_bit_extract_n();
      v46 = sub_126E54();
      rf_level_apply_n200(v45);
      if ( !v43 )
        msg_parse(dword_120DC0, *((uint8_t *)off_120DBC + 4), *((char *)off_120DBC + 2));
      v47 = dword_11FFA4;
      *v6 = v45;
      msg_parse(v47, v45, v46);
      goto LABEL_21;
    case 9:
      v40 = (unsigned int *)off_11FF98;
      v41 = (char)(*(uint8_t *)(a2 + 8) + ((*(uint32_t *)off_11FF98 >> 18) & 0x3F));
      if ( v41 < 1 )
        v41 = 1;
      if ( v41 >= 63 )
        v41 = 63;
      msg_parse(dword_11FF9C);
      *v40 = *v40 & 0xFF03FFFF | (v41 << 18);
      *v6 = (*v40 >> 18) & 0x3F;
      goto LABEL_21;
    case 0xA:
      v237 = *(uint8_t *)(a2 + 8);
      v39 = sub_113A44(v237);
      msg_parse(dword_11FF94, v237, v39);
      *v6 = v39;
      goto LABEL_21;
    case 0xB:
      *v5 = sub_122DB8(1, *(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xC:
      *v5 = sub_122DB8(2, *(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xD:
      v151 = sub_122DB8(0, 0);
      *v6 = v151;
      msg_parse(dword_1209E4, v151);
      goto LABEL_21;
    case 0xE:
      msg_parse(
        dword_1209E8,
        *(uint8_t *)(a2 + 13),
        *(uint8_t *)(a2 + 12),
        *(uint8_t *)(a2 + 11),
        *(uint8_t *)(a2 + 10),
        *(uint8_t *)(a2 + 9),
        *(uint8_t *)(a2 + 8));
      v152 = *(uint16_t *)(a2 + 12);
      v153 = *(uint16_t *)(a2 + 8);
      v154 = *(uint32_t *)(a2 + 8);
      v155 = HIBYTE(*(uint32_t *)off_1209C4) & 2;
      v156 = v152;
      v157 = __rev16(v153);
      v158 = __rev16(v152);
      if ( v155 )
      {
        v192 = rf_status_poll(v154, v156);
        v160 = v192;
        if ( v192 < 0 )
        {
          msg_parse(dword_121144, v192);
          v155 = v154;
          v159 = v156 | (v160 << 16);
        }
        else
        {
          v159 = v156 | (v192 << 16);
          v155 = v154;
        }
      }
      else
      {
        LOWORD(v244) = v158;
        WORD2(v244) = v157;
        BYTE2(v244) = HIBYTE(v154);
        BYTE3(v244) = BYTE2(v154);
        sub_11482C((int)&v244);
        sub_100200((int *)&v244, 0, 6u);
        if ( rf_reg_write_setup_n4820((int)&v244) )
        {
          v159 = 917504;
          v160 = 14;
        }
        else
        {
          v159 = (uint16_t)__rev16((uint16_t)v244) | 0xF0000;
          v155 = bswap32(*(unsigned int *)((char *)&v244 + 2));
          v160 = 15;
        }
      }
      *v6 = v155;
      v6[1] = v159;
      v236 = v160;
      sub_1282E8(v235, v6 + 18, 72);
      msg_parse(
        dword_1209EC,
        *v6,
        v6[1],
        v6[2],
        v6[3],
        v6[4],
        v6[5],
        v6[6],
        v6[7],
        v6[8],
        v6[9],
        v6[10],
        v6[11],
        v6[12],
        v6[13],
        v6[14],
        v6[15],
        v6[16],
        v6[17]);
      goto LABEL_21;
    case 0xF:
      v138 = HIBYTE(*(uint32_t *)off_1209C4) & 2;
      if ( v138 )
      {
        v189 = sub_113C48((int *)&v239, &v240);
        v138 = v239;
        v139 = v240 | (v189 << 16);
      }
      else
      {
        LODWORD(v244) = 0;
        WORD2(v244) = 0;
        if ( rf_reg_write_setup_n4820((int)&v244) )
        {
          v239 = 0;
          v240 = 0;
          v139 = 917504;
        }
        else
        {
          v138 = bswap32(*(unsigned int *)((char *)&v244 + 2));
          v240 = (uint16_t)__rev16((uint16_t)v244);
          v239 = v138;
          v139 = v240 | 0xF0000;
        }
      }
      *v6 = v138;
      v6[1] = v139;
      sub_1282E8(v235, v6 + 18, 72);
      msg_parse(
        dword_1209C8,
        *v6,
        v6[1],
        v6[2],
        v6[3],
        v6[4],
        v6[5],
        v6[6],
        v6[7],
        v6[8],
        v6[9],
        v6[10],
        v6[11],
        v6[12],
        v6[13],
        v6[14],
        v6[15],
        v6[16],
        v6[17]);
      goto LABEL_21;
    case 0x10:
      msg_parse(
        dword_11FFC8,
        *(uint8_t *)(a2 + 13),
        *(uint8_t *)(a2 + 12),
        *(uint8_t *)(a2 + 11),
        *(uint8_t *)(a2 + 10),
        *(uint8_t *)(a2 + 9),
        *(uint8_t *)(a2 + 8));
      v52 = *(uint32_t *)(a2 + 8);
      v53 = *(uint16_t *)(a2 + 12);
      v54 = __rev16(v53);
      v55 = bswap32(v52);
      v56 = v52;
      if ( (*(uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        inited = rf_init_n_d80(v52, v53);
        v58 = inited;
        if ( inited < 0 )
        {
          if ( inited != -1 )
            msg_parse(dword_121124);
          msg_parse(dword_121128);
        }
        v57 = v58 << 16;
      }
      else
      {
        sub_100200((int *)&v244, 0, 0x40u);
        sub_1149A4((int)&v244);
        WORD1(v244) = v54;
        HIDWORD(v244) = v55;
        sub_1149B0((int)&v244);
        sub_1149A4((int)&v244);
        v53 = (uint16_t)__rev16(WORD1(v244));
        v56 = bswap32(HIDWORD(v244));
        v57 = 983040;
        v58 = 15;
      }
      *v6 = v56;
      v6[1] = v57 | v53;
      msg_parse(dword_11FFCC, v53, v56, v58);
      goto LABEL_21;
    case 0x11:
      if ( (*(uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        v187 = rf_init_param_load((int *)&v239, &v240);
        v50 = v239;
        v49 = v240;
        v51 = v187 << 16;
      }
      else
      {
        sub_100200((int *)&v244, 0, 0x40u);
        sub_1149A4((int)&v244);
        v49 = (uint16_t)__rev16(WORD1(v244));
        v50 = bswap32(HIDWORD(v244));
        v239 = v50;
        v240 = (uint16_t)v49;
        v51 = 983040;
      }
      *v6 = v50;
      v6[1] = v51 | v49;
      msg_parse(dword_11FFC4);
      goto LABEL_21;
    case 0x12:
      msg_parse(dword_11FFB8, *(uint8_t *)(a2 + 8));
      LOBYTE(v244) = *(uint8_t *)(a2 + 8);
      sub_114194((uint8_t)v244);
      rf_bus_handler_16c(&v244);
      *v6 = (uint8_t)v244;
      msg_parse(dword_11FFBC);
      goto LABEL_21;
    case 0x13:
      rf_bus_handler_16c(&v244);
      *v6 = (uint8_t)v244;
      msg_parse(dword_11FFB4);
      goto LABEL_21;
    case 0x14:
      if ( *(uint32_t *)(a2 + 4) )
      {
        v190 = *(uint8_t *)(a2 + 8);
        v150 = off_120D80;
        v191 = dword_120D84;
        *(uint32_t *)off_120D80 = v190 != 0;
        msg_parse(v191);
      }
      else
      {
        v150 = off_1209DC;
        msg_parse(dword_1209E0, *(uint32_t *)off_1209DC);
      }
      *v6 = *v150;
      goto LABEL_21;
    case 0x15:
      v142 = *(uint32_t *)(a2 + 4);
      if ( !v142 || (v143 = *(uint8_t *)(a2 + 8), !*(uint8_t *)(a2 + 8)) )
      {
        v161 = dword_1209D8;
        v162 = dword_120A08;
        v163 = dword_1209FC;
        msg_parse(dword_1209F8);
        for ( i = 0; i != 3; ++i )
        {
          msg_parse(v162, i);
          v165 = (char *)v161;
          for ( j = 0; j != 12; ++j )
          {
            v168 = *v165++;
            v167 = v168;
            if ( v168 != -128 )
            {
              if ( j && !(j << 30) )
                uart_putc(32);
              msg_parse(v163, v167);
            }
          }
          uart_puts((uint8_t *)dword_120A00);
          v161 += 12;
        }
        v169 = dword_1209D0;
        v170 = dword_120A08;
        v171 = dword_1209FC;
        msg_parse(dword_120A04);
        for ( k = 0; k != 3; ++k )
        {
          msg_parse(v170, k);
          v173 = (char *)v169;
          for ( m = 0; m != 12; ++m )
          {
            v176 = *v173++;
            v175 = v176;
            if ( v176 != -128 )
            {
              if ( m && !(m << 30) )
                uart_putc(32);
              msg_parse(v171, v175);
            }
          }
          uart_puts((uint8_t *)dword_120A00);
          v169 += 12;
        }
        goto LABEL_233;
      }
      if ( v143 == 1 )
      {
        if ( v142 > 3 )
        {
          v144 = *(uint8_t *)(a2 + 9);
          if ( v144 <= 2 )
          {
            if ( v142 <= 0xB )
            {
              v145 = *(uint8_t *)(a2 + 10);
              if ( v144 == 1 )
                v210 = *(uint8_t *)(a2 + 10) <= 9u;
              else
                v210 = *(uint8_t *)(a2 + 10) <= 0xBu;
              if ( v210 )
              {
                v147 = *(char *)(a2 + 11);
                v148 = dword_121148;
                v149 = dword_12114C;
                goto LABEL_230;
              }
              goto LABEL_385;
            }
            v229 = dword_1212CC;
            msg_parse(dword_1212C4, *(uint8_t *)(a2 + 9));
            v230 = a2 + 9;
            v231 = dword_1212C8 + 12 * v144;
            for ( ii = 0; v144 != 1 || ii <= 9; ++ii )
            {
              v234 = *(char *)++v230;
              v233 = v234;
              if ( v234 >= 32 )
                v233 = 32;
              *(uint8_t *)++v231 = v233;
              if ( ii )
              {
                if ( !(ii << 30) )
                  uart_putc(32);
                msg_parse(v229, v233);
                if ( ii == 11 )
                  break;
              }
              else
              {
                msg_parse(v229, v233);
              }
            }
LABEL_397:
            uart_puts((uint8_t *)dword_1212C0);
            goto LABEL_233;
          }
LABEL_383:
          msg_parse(dword_121188, v144);
LABEL_233:
          sub_1282E8(v6, dword_1209D8, 36);
          sub_1282E8(v6 + 9, dword_1209D0, 36);
          goto LABEL_21;
        }
      }
      else
      {
        if ( v143 != 2 )
        {
          msg_parse(dword_121160);
          goto LABEL_233;
        }
        if ( v142 > 3 )
        {
          v144 = *(uint8_t *)(a2 + 9);
          if ( v144 <= 2 )
          {
            if ( v142 <= 0xB )
            {
              v145 = *(uint8_t *)(a2 + 10);
              if ( v144 == 1 )
                v146 = *(uint8_t *)(a2 + 10) <= 9u;
              else
                v146 = *(uint8_t *)(a2 + 10) <= 0xBu;
              if ( v146 )
              {
                v147 = *(char *)(a2 + 11);
                v148 = dword_1209D0;
                v149 = dword_1209D4;
LABEL_230:
                if ( v147 >= 32 )
                  LOBYTE(v147) = 32;
                *(uint8_t *)(v148 + 12 * v144 + v145) = v147;
                msg_parse(v149, v144);
                goto LABEL_233;
              }
LABEL_385:
              msg_parse(dword_121198, v145);
              goto LABEL_233;
            }
            v223 = dword_1212CC;
            msg_parse(dword_1212B8, *(uint8_t *)(a2 + 9));
            v224 = a2 + 9;
            v225 = dword_1212BC + 12 * v144;
            for ( jj = 0; v144 != 1 || jj <= 9; ++jj )
            {
              v228 = *(char *)++v224;
              v227 = v228;
              if ( v228 >= 32 )
                v227 = 32;
              *(uint8_t *)++v225 = v227;
              if ( jj )
              {
                if ( !(jj << 30) )
                  uart_putc(32);
                msg_parse(v223, v227);
                if ( jj == 11 )
                  goto LABEL_397;
              }
              else
              {
                msg_parse(v223, v227);
              }
            }
            goto LABEL_397;
          }
          goto LABEL_383;
        }
      }
      msg_parse(dword_121180);
      goto LABEL_233;
    case 0x16:
      v7 = *(uint32_t *)(a2 + 4);
      if ( v7 && (v8 = *(uint8_t *)(a2 + 8), *(uint8_t *)(a2 + 8)) )
      {
        if ( v8 == 1 )
        {
          v211 = off_121150;
          ++*(uint8_t *)off_121150;
          if ( v7 > 3 )
          {
            v212 = *(uint8_t *)(a2 + 9);
            if ( v212 <= 2 )
            {
              v213 = *(uint8_t *)(a2 + 10);
              if ( v213 <= 2 )
              {
                v214 = *(char *)(a2 + 11);
                v19 = off_12119C;
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
                  mmio_set_bit_120090C(0, v216);
                  ++*v211;
                }
                v219 = v212;
                v13 = off_12115C;
                msg_parse(dword_121158, v219, v213, v214);
                goto LABEL_20;
              }
            }
            goto LABEL_373;
          }
        }
        else
        {
          if ( v8 != 2 )
          {
            v19 = off_12119C;
            v13 = off_12115C;
            msg_parse(dword_121164);
            goto LABEL_20;
          }
          v9 = off_11FCD0;
          ++*(uint8_t *)off_11FCD0;
          if ( v7 > 3 )
          {
            v10 = *(uint8_t *)(a2 + 9);
            if ( v10 <= 2 )
            {
              v11 = *(uint8_t *)(a2 + 10);
              if ( v11 <= 5 )
              {
                v12 = *(char *)(a2 + 11);
                v13 = off_11FCD4;
                v14 = (uint16_t *)off_11FCD8;
                if ( v12 < -7 )
                  v12 = -7;
                if ( v12 >= 7 )
                  v12 = 7;
                *(uint8_t *)(*(uint32_t *)off_11FCD4 + v11 + 6 * v10) = v12;
                v15 = v14[20];
                v16 = *((uint8_t *)v14 + 36);
                if ( v15 > 0x1666 )
                {
                  v17 = 5;
                }
                else if ( v15 > 0x1616 )
                {
                  v17 = 4;
                }
                else if ( v15 > 0x15C6 )
                {
                  v17 = 3;
                }
                else if ( v15 > 0x1571 )
                {
                  v17 = 2;
                }
                else
                {
                  v17 = v15 > 0x1486;
                }
                if ( v16 == 1 && v17 == v11 )
                {
                  mmio_set_bit_120090C(1, v15);
                  ++*v9;
                }
                v18 = v11;
                v19 = off_11FD2C;
                msg_parse(dword_11FCDC, v10, v18, v12);
                goto LABEL_20;
              }
            }
LABEL_373:
            v19 = off_12119C;
            v13 = off_12115C;
            msg_parse(dword_12116C);
            goto LABEL_20;
          }
        }
        v19 = off_12119C;
        v13 = off_12115C;
        msg_parse(dword_121170);
      }
      else
      {
        v19 = off_120DC8;
        v177 = dword_120DCC;
        v178 = dword_120DD0;
        msg_parse(dword_120D58);
        msg_parse(dword_120D5C);
        for ( kk = 0; kk != 3; ++kk )
        {
          msg_parse(v177, kk);
          for ( mm = 0; mm != 3; ++mm )
          {
            v181 = *(char *)(*v19 + 3 * kk + mm);
            msg_parse(v178, v181);
          }
        }
        v13 = off_120D64;
        v182 = dword_120DCC;
        v183 = dword_120DD0;
        msg_parse(dword_120D60);
        msg_parse(dword_120D68);
        for ( nn = 0; nn != 3; ++nn )
        {
          msg_parse(v182, nn);
          for ( i1 = 0; i1 != 6; ++i1 )
          {
            v186 = *(char *)(*v13 + 6 * nn + i1);
            msg_parse(v183, v186);
          }
        }
        msg_parse(dword_120D6C);
      }
LABEL_20:
      sub_1282E8(v6, *v19, 9);
      sub_1282E8((char *)v6 + 9, *v13, 18);
LABEL_21:
      sub_11DE50((int)v6);
      return 0;
    case 0x18:
      v75 = *(uint32_t *)(a2 + 4);
      if ( v75 )
      {
        v76 = *(uint8_t *)(a2 + 8);
        if ( !*(uint8_t *)(a2 + 8) )
        {
          v77 = *(uint8_t *)(a2 + 8);
          v75 = v77;
          v78 = v77;
          goto LABEL_129;
        }
        if ( v75 <= 3 )
        {
          msg_parse(dword_121170);
        }
        else
        {
          v77 = *(uint8_t *)(a2 + 10);
          v78 = *(char *)(a2 + 11);
          if ( (uint8_t)(*(uint8_t *)(a2 + 11) + 7) <= 0xEu )
          {
            v75 = *(uint8_t *)(a2 + 8);
            v76 = *(uint8_t *)(a2 + 9);
LABEL_129:
            sub_122728(v75, v76, v77, v78);
            goto LABEL_130;
          }
          msg_parse(dword_121184, *(char *)(a2 + 11), v77);
        }
LABEL_130:
        sub_1282E8(v6, *(uint32_t *)off_1202E8, 9);
        sub_1282E8((char *)v6 + 9, *(uint32_t *)off_1202EC, 18);
        sub_1282E8((char *)v6 + 27, dword_1202F0, 9);
        sub_1282E8(v6 + 9, dword_1202F4, 18);
        goto LABEL_21;
      }
      v77 = 0;
      v76 = 0;
      v78 = 0;
      goto LABEL_129;
    case 0x19:
      v140 = *(uint32_t *)(a2 + 4);
      if ( !v140 )
        goto LABEL_269;
      if ( v140 > 1 )
      {
        v141 = *(uint8_t *)(a2 + 9);
        v140 = *(uint8_t *)(a2 + 8);
LABEL_218:
        v30 = sub_122688(v140, v141);
        goto LABEL_54;
      }
      if ( *(uint8_t *)(a2 + 8) != 1 )
      {
        v140 = *(uint8_t *)(a2 + 8);
LABEL_269:
        v141 = 0;
        goto LABEL_218;
      }
      goto LABEL_295;
    case 0x1A:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_244;
      if ( *(uint8_t *)(a2 + 8) > 2u )
        msg_parse(dword_120D9C);
      else
        sub_125AD8();
      goto LABEL_21;
    case 0x1D:
      sub_126258(*(uint8_t *)(a2 + 8), *(uint8_t *)(a2 + 9), *(uint8_t *)(a2 + 10));
      *v6 = *(uint8_t *)off_11FF88;
      goto LABEL_21;
    case 0x1E:
      if ( is_flag_set_n645c() )
        msg_parse(dword_120DA8, *(uint8_t *)off_120DA4);
      if ( *(uint8_t *)off_11FF88 == 1 )
      {
        v203 = mmio_bit_extract_n();
        v204 = *(uint32_t *)off_121130;
        v205 = *(uint8_t *)off_121134;
        v206 = (int *)off_12113C;
        v6[1] = *(uint32_t *)off_121138;
        v207 = (v205 << 16) | (((v204 >> 18) & 0x3F) << 8) | v203;
        v208 = *v206;
        v209 = v206[1];
        *v6 = v207;
        v6[2] = v208;
        v6[3] = v209;
      }
      else if ( *(uint8_t *)off_11FF8C )
      {
        v36 = (uint32_t *)dword_11FF90;
        v37 = &v6[(uint8_t)(*(uint8_t *)off_11FF8C - 1) + 1];
        v38 = v6;
        do
        {
          *v38 = *v36;
          v38[1] = v36[1];
          ++v38;
          v36 += 2;
        }
        while ( v38 != v37 );
      }
      goto LABEL_21;
    case 0x20:
      if ( *(uint32_t *)(a2 + 4) )
        sub_126764(*(uint8_t *)(a2 + 8));
      else
LABEL_244:
        msg_parse(dword_1209F4);
      goto LABEL_21;
    case 0x23:
      v32 = *(uint32_t *)(a2 + 4);
      if ( !v32 )
        goto LABEL_281;
      if ( v32 > 1 )
      {
        v33 = *(uint8_t *)(a2 + 9);
        v32 = *(uint8_t *)(a2 + 8);
LABEL_63:
        v30 = sub_122F3C(v32, v33);
        goto LABEL_54;
      }
      if ( *(uint8_t *)(a2 + 8) != 1 )
      {
        v32 = *(uint8_t *)(a2 + 8);
LABEL_281:
        v33 = 0;
        goto LABEL_63;
      }
      goto LABEL_295;
    case 0x24:
      v34 = *(uint32_t *)(a2 + 4);
      if ( !v34 )
        goto LABEL_247;
      if ( v34 <= 4 )
      {
        if ( *(uint8_t *)(a2 + 8) == 1 )
        {
LABEL_295:
          msg_parse(dword_120D90);
          v30 = -4;
LABEL_54:
          *v6 = v30;
          goto LABEL_21;
        }
        v34 = *(uint8_t *)(a2 + 8);
LABEL_247:
        v35 = 0;
      }
      else
      {
        v35 = *(uint32_t *)(a2 + 9);
        v34 = *(uint8_t *)(a2 + 8);
      }
      v30 = rf_init_handler_0(v34, v35);
      goto LABEL_54;
    case 0x25:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_243;
      v31 = *(uint8_t *)(a2 + 8);
      *(uint32_t *)off_11FD28 = v31;
LABEL_59:
      rf_level_apply_n_4ec(v31);
      goto LABEL_21;
    case 0x26:
      if ( !*(uint32_t *)(a2 + 4) )
        goto LABEL_243;
      rf_level_apply_6d60(*(uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0x27:
      if ( *(uint32_t *)(a2 + 4) && *(uint8_t *)(a2 + 8) > 1u )
        goto LABEL_295;
      v30 = sub_123020();
      goto LABEL_54;
    case 0x28:
      msg_parse(dword_11FD20);
      timer_set_relative(1071, 1, dword_11FD24);
      goto LABEL_21;
    case 0x50:
      sub_100200((int *)dword_11FD10, 0, 2u);
      if ( *(uint32_t *)(a2 + 4) != 2 )
      {
        msg_parse(dword_120D88, *(uint32_t *)(a2 + 4));
        goto LABEL_21;
      }
      if ( !*(uint8_t *)(a2 + 8) )
        goto LABEL_21;
      if ( *(uint8_t *)(a2 + 9) )
      {
        v27 = a2 + 8;
        if ( sub_125E0C(dword_11FD14) )
        {
          msg_parse(dword_11FD18);
          v28 = 2;
          v29 = v27;
          goto LABEL_48;
        }
      }
      else
      {
        v237 = a2 + 8;
        if ( sub_125E0C(dword_121174) )
        {
          msg_parse(dword_121178);
          v29 = v237;
          v28 = 1;
LABEL_48:
          sub_1282E8(dword_11FD10, v29, v28);
          msg_parse(dword_11FD1C, dword_11FD10);
          if ( (*(uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            sub_114844(dword_11FD10);
          goto LABEL_21;
        }
      }
      msg_parse(dword_12117C);
      goto LABEL_21;
    case 0x51:
      LOWORD(v244) = 0;
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        msg_parse(dword_120D78, dword_120D7C);
        sub_1282E8(&v244, dword_120D7C, 2);
        goto LABEL_30;
      }
      sub_114838((int)&v244);
      if ( (uint8_t)v244 != 255 )
        goto LABEL_28;
      goto LABEL_42;
    case 0x52:
      *v5 = *(char *)off_11FD08;
      goto LABEL_21;
    case 0x5B:
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        msg_parse(dword_120DB8);
      }
      else if ( *(uint32_t *)(a2 + 4) )
      {
        msg_parse(dword_11FD00);
        v24 = *(uint32_t *)(a2 + 4);
        *v6 = 0xFFFF;
        v6[1] = 0xFFFF;
        if ( v24 > 3 )
        {
          v25 = *(uint16_t *)(a2 + 8);
          v26 = *(uint16_t *)(a2 + 10);
          msg_parse(dword_11FD04, v25, v26);
          sub_100200((int *)&v244, 0, 4u);
          LOWORD(v244) = v25;
          WORD1(v244) = v26;
          sub_11485C((int)&v244);
          *v6 = v25;
          v6[1] = v26;
        }
      }
      else
      {
        sub_100200((int *)&v244, 0, 4u);
        v196 = sub_114850((int)&v244);
        msg_parse(dword_120D94, v196);
        if ( v196 || WORD1(v244) == 0xFFFF || (uint16_t)v244 == 0xFFFF )
        {
          msg_parse(dword_121100);
        }
        else
        {
          msg_parse(dword_120DA0);
          LODWORD(v197) = (uint16_t)v244;
          HIDWORD(v197) = WORD1(v244);
          *(uint64_t *)v6 = v197;
        }
      }
      goto LABEL_21;
    case 0x5C:
      sub_100200((int *)dword_11FCF0, 0, 2u);
      if ( *(uint32_t *)(a2 + 4) == 2 )
      {
        v23 = a2 + 8;
        if ( sub_125E0C(dword_11FCF4) )
        {
          msg_parse(dword_11FCF8);
          sub_1282E8(dword_11FCF0, v23, 2);
          msg_parse(dword_11FCFC, dword_11FCF0);
          if ( (*(uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            sub_114874(dword_11FCF0);
        }
        else
        {
          msg_parse(dword_121168);
        }
      }
      goto LABEL_21;
    case 0x5D:
      LOWORD(v244) = 0;
      if ( (*(uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        msg_parse(dword_120D78, dword_120D74);
        sub_1282E8(&v244, dword_120D74, 2);
      }
      else
      {
        sub_114868((int)&v244);
        if ( (uint8_t)v244 != 255 )
        {
LABEL_28:
          if ( BYTE1(v244) != 255 )
          {
            msg_parse(dword_11FCEC, &v244);
            goto LABEL_30;
          }
        }
LABEL_42:
        msg_parse(dword_11FD0C);
      }
LABEL_30:
      *v6 = (uint16_t)v244;
      goto LABEL_21;
    case 0x5E:
      goto LABEL_25;
    case 0x5F:
      if ( *(uint32_t *)(a2 + 4) )
      {
        v21 = *(uint8_t *)(a2 + 8);
        sub_1149FC(v21);
        if ( v21 )
          msg_parse(dword_11FCE0);
        else
          msg_parse(dword_121104);
      }
      else
      {
        msg_parse(dword_120D70);
      }
LABEL_25:
      v22 = rf_init_or_reset_helper();
      msg_parse(dword_11FCE4, v22);
      *v6 = v22;
      goto LABEL_21;
    case 0x60:
      sub_100200((int *)&v244, 0, 0x40u);
      sub_100200((int *)&v244, 0, 0x40u);
      if ( !*(uint32_t *)(a2 + 4) )
      {
        LOWORD(v240) = 0;
        goto LABEL_162;
      }
      v198 = *(uint8_t *)(a2 + 8);
      msg_parse(dword_120DAC, v198);
      if ( v198 > 0x23 )
      {
        v100 = 5 * v198 + 5000;
        v241 = v100;
        LOWORD(v240) = 1;
        goto LABEL_163;
      }
      LOWORD(v240) = 0;
      if ( v198 <= 0xD )
      {
        v100 = 5 * v198 + 2407;
        v241 = v100;
        goto LABEL_163;
      }
      if ( v198 == 14 )
      {
LABEL_162:
        v100 = 2484;
        v241 = 2484;
LABEL_163:
        HIWORD(v240) = v100;
        v242 = 0;
        v243 = 0;
        rf_state_get_n246(0, &v240, 0);
        sub_108D34(0xFFFF, (int)&v244);
        sub_1282E8(v6, &v244, 64);
        goto LABEL_21;
      }
      msg_parse(dword_120DB0, v198);
      return -2;
    case 0x61:
      if ( (*(uint32_t *)off_120318 & 0x2000000) != 0 )
      {
        msg_parse(dword_120DB4, *(uint32_t *)off_120318 << 6);
      }
      else
      {
        v93 = *(uint32_t *)(a2 + 4);
        *v5 = 0xFFFF;
        v5[1] = 0xFFFF;
        v5[2] = 0xFFFF;
        v5[3] = 0xFFFF;
        v5[4] = 255;
        if ( v93 )
        {
          msg_parse(dword_120324);
          if ( *(uint32_t *)(a2 + 4) > 8u )
          {
            v94 = *(uint8_t *)(a2 + 16);
            v95 = *(uint8_t *)(a2 + 14) | (*(uint8_t *)(a2 + 15) << 8);
            v96 = *(uint8_t *)(a2 + 8) | (*(uint8_t *)(a2 + 9) << 8);
            v97 = *(uint8_t *)(a2 + 10) | (*(uint8_t *)(a2 + 11) << 8);
            v98 = *(uint64_t *)(a2 + 8);
            v237 = *(uint8_t *)(a2 + 12) | (*(uint8_t *)(a2 + 13) << 8);
            msg_parse(dword_120328, v96, v97, v237, v95, v94);
            sub_100200((int *)&v244, 0xFFu, 0xAu);
            v244 = v98;
            v245 = v94;
            sub_11488C((int)&v244);
            v99 = v237;
            v6[4] = v94;
            *v6 = v96;
            v6[1] = v97;
            v6[2] = v99;
            v6[3] = v95;
          }
        }
        else
        {
          sub_100200((int *)&v244, 0xFFu, 0xAu);
          v193 = sub_114880((int)&v244);
          msg_parse(dword_120D94, v193);
          if ( v193 )
          {
            msg_parse(dword_121140);
          }
          else
          {
            msg_parse(dword_120D98, (uint16_t)v244, WORD1(v244), WORD2(v244), HIWORD(v244), v245);
            HIDWORD(v194) = HIWORD(v244);
            LODWORD(v195) = (uint16_t)v244;
            HIDWORD(v195) = WORD1(v244);
            LODWORD(v194) = WORD2(v244);
            *(uint64_t *)v6 = v195;
            *((uint64_t *)v6 + 1) = v194;
            v6[4] = v245;
          }
        }
      }
      goto LABEL_21;
    case 0x108:
      msg_parse(dword_120314);
      LODWORD(v244) = 0;
      sub_100200((int *)&v244 + 1, 0, 0x3FCu);
      if ( *(uint32_t *)(a2 + 4) == 8 )
      {
        v89 = *(uint32_t *)(a2 + 8);
        if ( !v89 )
          v89 = 0x4000000;
        if ( (*(uint32_t *)off_120318 & 0x2000000) == 0 )
        {
          v90 = *(uint32_t *)(a2 + 12);
          if ( v90 )
          {
LABEL_149:
            msg_parse(dword_12031C, v89, v90);
            if ( v90 >> 10 )
            {
              v91 = v89;
              v92 = -1;
              do
              {
                sub_1142D8();
                v91 += 1024;
                v92 = sub_11EB48((uint8_t *)&v244, 1024, v92);
              }
              while ( v91 != v89 + (v90 >> 10 << 10) );
            }
            else
            {
              v92 = -1;
            }
            if ( (v90 & 0x3FF) != 0 )
            {
              sub_1142D8();
              v92 = sub_11EB48((uint8_t *)&v244, v90 & 0x3FF, v92);
            }
            msg_parse(dword_120320, v92);
LABEL_155:
            *v6 = v92;
            goto LABEL_21;
          }
LABEL_148:
          v90 = sub_114218();
          goto LABEL_149;
        }
      }
      else if ( (*(uint32_t *)off_120318 & 0x2000000) == 0 )
      {
        v89 = 0x4000000;
        goto LABEL_148;
      }
      v92 = -1;
      goto LABEL_155;
    default:
      goto LABEL_21;
  }
}

