// ke_send_msg_414 @ 0x11f79c
int ke_send_msg_414(int a1, int a2, int a3, int a4) {
  volatile int *v5; // r0
  int v6; // r2
  int v7; // r3
  volatile char *v8; // r5
  unsigned int v9; // r3
  int v10; // r2
  volatile uint8_t *v11; // r6
  unsigned int v12; // r9
  unsigned int v13; // r10
  int v14; // r8
  volatile char **v15; // r7
  volatile uint16_t *v16; // r0
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  volatile char **v21; // r10
  int v23; // r4
  int v24; // r4
  volatile char *v25; // r4
  int v26; // r1
  unsigned int v27; // r2
  int v28; // r7
  int v29; // r4
  int v30; // r4
  unsigned int v31; // r2
  volatile char *v32; // r1
  unsigned int v33; // r0
  int v34; // r0
  int v35; // r0
  unsigned int v36; // r0
  int v37; // r1
  unsigned int v38; // r0
  int v39; // r1
  volatile uint32_t *v40; // r2
  volatile char *v41; // r1
  volatile char *v42; // r3
  int v43; // r4
  volatile unsigned int *v44; // r6
  int v45; // r4
  uint8_t v46; // r0
  int v47; // r6
  int v48; // r4
  int v49; // r4
  int v50; // r7
  volatile uint32_t *v51; // r2
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
  volatile uint32_t *v67; // r1
  volatile int *v68; // r6
  volatile uint32_t *v69; // r7
  volatile unsigned int v70; // r9
  unsigned int v71; // r3
  int v72; // r3
  int v73; // r3
  int v74; // r2
  unsigned int v75; // r6
  int v76; // r4
  uint16_t v77; // r3
  uint16_t v78; // r3
  volatile uint32_t *v79; // r1
  int v80; // r4
  volatile uint32_t *v81; // r3
  unsigned int v82; // r0
  unsigned int v83; // r1
  unsigned int v84; // r2
  int v85; // r3
  volatile int *v86; // r6
  volatile uint32_t *v87; // r4
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
  volatile int *v110; // r4
  int v111; // r3
  int v112; // r2
  int v113; // r6
  volatile uint32_t *v114; // r3
  unsigned int v115; // r3
  unsigned int v116; // r8
  unsigned int v117; // r9
  int v118; // r10
  unsigned int v119; // r7
  int v120; // r6
  int v121; // r11
  int v122; // r4
  unsigned int v123; // r4
  volatile int *v124; // r8
  volatile int *v125; // r0
  volatile uint8_t *v126; // r1
  unsigned int v127; // r4
  volatile int *v128; // r3
  int v129; // r6
  volatile uint32_t *v130; // r3
  int v131; // r3
  int v132; // r1
  int v133; // r4
  uint64_t v134; // r0
  float v135; // r0
  uint64_t v136; // r0
  uint64_t v137; // r0
  unsigned int v138; // r8
  volatile unsigned int *v139; // r1
  volatile unsigned int *v140; // r4
  int v141; // r6
  volatile uint32_t *v142; // r2
  volatile uint32_t *v143; // r0
  volatile uint32_t *v144; // r6
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
  volatile uint8_t *v156; // r1
  const volatile char *v157; // r0
  volatile uint32_t *v158; // r4
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
  volatile char *v169; // r9
  int i; // r8
  volatile char *v171; // r10
  int j; // r4
  int v173; // r6
  int v174; // t1
  volatile char *v175; // r9
  int k; // r8
  volatile char *v177; // r10
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
  volatile uint32_t *v199; // r3
  volatile uint32_t *v200; // r1
  volatile uint8_t *v201; // r2
  volatile uint8_t *v202; // r2
  char v203; // r0
  unsigned int v204; // r1
  int v205; // r3
  volatile int *v206; // r4
  int v207; // r3
  int v208; // r1
  int v209; // r2
  BOOL v210; // r3
  volatile uint8_t *v211; // r6
  unsigned int v212; // r7
  unsigned int v213; // r8
  int v214; // r4
  volatile uint16_t *v215; // r0
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
  struct __attribute__((packed)) { char v236[72]; // [sp+3Ch] [bp-468h] BYREF
  int v237; // [sp+84h] [bp-420h]
  unsigned int a1a; // [sp+88h] [bp-41Ch]
  int v239; // [sp+8Ch] [bp-418h]
  int v240; // [sp+90h] [bp-414h] BYREF
  unsigned int a2a; // [sp+94h] [bp-410h] BYREF
  int16_t v242; // [sp+98h] [bp-40Ch]
  uint16_t v243; // [sp+9Ah] [bp-40Ah]
  char _pad8[2]; char v244; // [sp+9Eh] [bp-406h]
  char _pad9[1]; int result[2]; // [sp+A0h] [bp-404h] BYREF
  uint8_t v246; // [sp+A8h] [bp-3FCh]
  char _pad11[1]; char v247; // [sp+AAh] [bp-3FAh]
  } _frame;
  v5 = (volatile int *)ke_msg_send_1(1044, a4, a3, 72);
  v7 = *(volatile uint32_t *)a2;
  v8 = (volatile char *)v5;
  switch ( *(volatile uint32_t *)a2 )
  {
    case 0:
if ( *(volatile uint32_t *)(uintptr_t)(off_120670) == 1 ) { v202 = (void *)(uintptr_t)(off_12112C);
        *(volatile uint32_t *)(uintptr_t)(off_120670) = 0;
        *v202 = 0;
        ke_int_lock((int)(uintptr_t)((volatile char *)0x90), 0);
      }
      v113 = *(volatile uint32_t *)off_120674 & 0xF;
      if ( v113 == 3 )
        rf_cmd_wait();
      v114 = (volatile uint32_t *)off_120674;
      *(volatile uint32_t *)off_120678 = 0;
      *v114 = 16 * v113;
      dispatch_event_handler_1("rftest set tx: %d\r\n", *(volatile uint32_t *)(a2 + 4));
      v115 = *(volatile uint8_t *)(a2 + 10);
      v116 = *(volatile uint8_t *)(a2 + 9);
      v117 = *(volatile uint8_t *)(a2 + 8);
      v118 = *(volatile uint8_t *)(a2 + 11);
      v119 = (uint16_t)(*(volatile uint8_t *)(a2 + 12) + (*(volatile uint8_t *)(a2 + 13) << 8));
      v120 = (uint16_t)(*(volatile uint8_t *)(a2 + 14) + (*(volatile uint8_t *)(a2 + 15) << 8));
      v121 = *(volatile char *)(a2 + 16);
      v122 = *(volatile uint8_t *)(a2 + 16);
      _frame.a1a = v115;
      _frame.v239 = v122;
      dispatch_event_handler_1("param:%d,%d,%d,%d,%d,%d\r\n", v117, v116, v115, v118, v119, v120);
      dispatch_event_handler_1("max_pwr:%d\n", v121);
      v123 = v116;
      if ( (*(volatile uint8_t *)off_120688 & 8) == 0 && v116 > 1 )
      {
        dispatch_event_handler_1("invalid bw:%d\n", v116);
        goto LABEL_21;
      }
      configure_hw_regs(_frame.a1a, v118, 0);
      set_state_checked(v119);
      _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(v117 > 0x23) & 0xFFu);
      _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(v116) & 0xFFu);
      if ( v117 > 0x23 )
      {
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(5 * v117 + 5000) & 0xFFFFu);
      }
      else if ( v117 > 0xD )
      {
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(2484) & 0xFFFFu);
        if ( v117 != 14 )
        {
          dispatch_event_handler_1("Not supported chan: %d\n", v117);
          v116 = BYTE1(_frame.result[0]);
        }
      }
      else
      {
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(5 * v117 + 2407) & 0xFFFFu);
      }
      _frame.result[1] = (_frame.result[1] & ~0xFFFF0000u) | (((uint16_t)(0) & 0xFFFFu) << 16);
      _frame.v247 = 0;
      if ( v116 )
      {
        if ( v116 == 1 )
        {
          if ( v117 == 1 || v117 == 36 )
            _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(LOWORD(_frame.result[1]) + 10) & 0xFFFFu) << 16);
          else
            _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(LOWORD(_frame.result[1]) - 10) & 0xFFFFu) << 16);
        }
      }
      else
      {
        _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(_frame.result[1]) & 0xFFFFu) << 16);
      }
      v124 = (volatile int *)off_120654;
      if ( *(volatile uint32_t *)off_120654 )
        init_with_stack(0);
      v125 = (void *)(uintptr_t)(off_120658);
      v126 = (void *)(uintptr_t)(off_120690);
      v127 = *(volatile uint32_t *)off_12068C & 0xFFFFFE7F | (v123 << 7);
      v128 = (volatile int *)(v120 - 1);
      if ( (unsigned int)(v120 - 1) > 0x30 )
        v128 = (void *)(uintptr_t)(off_120694);
      *(volatile uint32_t *)off_12068C = v127;
      if ( (unsigned int)(v120 - 1) > 0x30 )
        *v128 = v120;
      if ( (unsigned int)(_frame.v239 - 1) <= 0x1E )
        *(volatile uint8_t *)off_120698 = v121;
      *v125 = 1;
      *v126 = 1;
      rx_process_pending(0, (int)_frame.result);
      if ( LOBYTE(_frame.result[0]) )
        mac_ctrl_clear(LOWORD(_frame.result[1]));
      else
        mac_ctrl_set(LOWORD(_frame.result[1]), BYTE1(_frame.result[0]));
      v35 = *v124;
      if ( !*v124 )
        goto LABEL_21;
      goto LABEL_59;
    case 1:
      dispatch_event_handler_1(aRftestSetTxsto);
      v108 = *(volatile uint32_t *)off_120654;
      *(volatile uint32_t *)(uintptr_t)(off_120658) = 0;
      if ( v108 )
        init_with_stack(0);
      v109 = *(volatile uint8_t *)off_12065C;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_120660 = 1;
      }
      v110 = (volatile int *)off_120664;
      _frame.a1a = v109;
      ++*(volatile uint32_t *)off_120664;
      mmio_irq_set(v109);
      wlan_hw_init(_frame.a1a, dword_120668 + 28 * (uint16_t)_frame.a1a + 12);
      if ( *v110 )
      {
        v111 = *v110 - 1;
        v112 = *(volatile uint32_t *)off_120660;
        *v110 = v111;
        if ( !v111 )
        {
          if ( v112 )
            __enable_irq();
        }
      }
      dispatch_event_handler_1(aStopDone);
      goto LABEL_21;
    case 2:
if ( *(volatile uint32_t *)(uintptr_t)(off_120670) == 1 ) { v201 = (void *)(uintptr_t)(off_12112C);
        *(volatile uint32_t *)(uintptr_t)(off_120670) = 0;
        *v201 = 0;
        ke_int_lock((int)(uintptr_t)((volatile char *)0x90), 0);
      }
      v129 = *(volatile uint32_t *)off_120674 & 0xF;
      if ( v129 == 3 )
        rf_cmd_wait();
      v130 = (volatile uint32_t *)off_120674;
      *(volatile uint32_t *)off_120678 = 0;
      *v130 = 16 * v129;
      v131 = *(volatile uint32_t *)(a2 + 4);
      if ( !v131 )
        goto LABEL_243;
      v132 = *(volatile uint8_t *)(a2 + 8);
      if ( *(volatile uint8_t *)(a2 + 8) )
      {
        if ( v132 == 1 )
        {
          if ( v131 == 2 )
          {
            v133 = *(volatile char *)(a2 + 9);
            v134 = aeabi_i2d(v133);
            v135 = COERCE_FLOAT(((int (*)(uint64_t))aeabi_dmul)(v134));
            if ( v133 <= 0 )
            {
              v220 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v135));
              v221 = (v221 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12118C) << 32);
              v221 = (v221 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
              v222 = double_add(v220, v221);
              v223 = (v223 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_121190) << 32);
              v223 = (v223 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
              v224 = ((uint64_t (*)())aeabi_dsub)(v222, v223);
              v225 = (v225 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_121194) << 32);
              v225 = (v225 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
              v136 = ((uint64_t (*)())aeabi_dadd)(v224, v225);
            }
            else
            {
              v136 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(v135 / flt_12069C) * flt_1206A0));
            }
            v137 = parse_data_field(v136);
            v138 = ((int (*)(uint64_t))aeabi_d2iz)(v137);
            dispatch_event_handler_1("user tone on, freq=%d, tone_freq_num=%d, amp=%x, txgain=%x\n", v133, v138, 1023, 1);
            v139 = (volatile unsigned int *)off_1206A8;
            v140 = (volatile unsigned int *)off_1206AC;
            v141 = dword_1206B0;
            v142 = (void *)(uintptr_t)(off_1206B4);
            v143 = (void *)(uintptr_t)(off_1206B8);
            *(volatile uint32_t *)off_1206A8 = ~(~((*(volatile uint32_t *)off_1206A8 & 0xFFFFF000) >> 10) << 10);
            *v140 = *v140 & 0xFFFFFFC0 | 1;
            *v140 |= 0x40u;
            *v140 |= 0x80u;
            *v139 = v141 & (v138 << 12) | *v139 & 0xFC000FFF;
            v144 = (void *)(uintptr_t)(off_1206BC);
            *v142 |= 0x1000000u;
            *v144 |= 0x10000u;
            *v139 |= 0x10000000u;
            *v143 |= 0x100u;
            get_elapsed_ticks(200);
            *v140 = *v140 & 0xFF87FFFF | 0x100000;
            get_elapsed_ticks(200);
            *v140 |= 0x400000u;
            get_elapsed_ticks(200);
            *v140 |= 0x200000u;
          }
          else
          {
LABEL_243:
            dispatch_event_handler_1(aWrongArgs);
          }
        }
        else
        {
          dispatch_event_handler_1("wrong func: %d\n", v132);
        }
      }
      else
      {
        dispatch_event_handler_1(aUserToneOff);
        v199 = (void *)(uintptr_t)(off_12111C);
        v200 = (void *)(uintptr_t)(off_121120);
        *(volatile uint32_t *)off_121118 &= ~0x10000000u;
        *v199 &= 0xFF87FFFF;
        *v200 &= ~0x10000u;
        *v199 &= 0xFFFFFFC0;
        *v199 &= ~0x40u;
        *v199 |= 0x80u;
      }
      goto LABEL_21;
    case 3:
      dispatch_event_handler_1(aRftestSetRx);
      if ( !*(volatile uint8_t *)off_11FFD4 )
      {
        v67 = (void *)(uintptr_t)(off_11FFD8);
        *(volatile uint8_t *)off_11FFD4 = 1;
        if ( *v67 << 28 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_11FFDC = 1;
          }
          v68 = (volatile int *)off_11FFE0;
          v69 = (void *)(uintptr_t)(off_11FFD8);
          ++*(volatile uint32_t *)off_11FFE0;
          *v69 = 0;
          v70 = (*(volatile uint32_t *)0x40501010u);
          while ( *v69 << 28 )
          {
            v71 = (*(volatile uint32_t *)0x40501010u) - v70;
            if ( v71 > 0x7530 )
              dispatch_event_handler_1(aIdleErr);
          }
          while ( (*(volatile uint32_t *)off_1202C4 & *(volatile uint32_t *)off_1202C0 & 4) == 0 )
            ;
          v72 = *v68;
          *(volatile uint32_t *)off_1202C8 = 4;
          if ( v72 )
          {
            v73 = v72 - 1;
            v74 = *(volatile uint32_t *)off_1202CC;
            *v68 = v73;
            if ( !v73 )
            {
              if ( v74 )
                __enable_irq();
            }
          }
          dispatch_event_handler_1(aForceIdled);
        }
      }
      v75 = *(volatile uint8_t *)(a2 + 8);
      v76 = *(volatile uint8_t *)(a2 + 9);
      dispatch_event_handler_1("chan=%x, bw=%x\r\n", v75, v76);
      _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(v75 > 0x23) & 0xFFu);
      _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(v76) & 0xFFu);
      if ( v75 > 0x23 )
      {
        v77 = 5 * v75 + 5000;
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(v77) & 0xFFFFu);
      }
      else
      {
        if ( v75 > 0xD )
        {
          _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(2484) & 0xFFFFu);
          if ( v75 == 14 )
          {
            _frame.result[1] = (_frame.result[1] & ~0xFFFF0000u) | (((uint16_t)(0) & 0xFFFFu) << 16);
            _frame.v247 = 0;
            if ( v76 == 1 )
              v78 = 2474;
            else
              v78 = 2514;
            goto LABEL_120;
          }
          dispatch_event_handler_1("Not supported chan: %d\n", v75);
          _frame.result[1] = (_frame.result[1] & ~0xFFFF0000u) | (((uint16_t)(0) & 0xFFFFu) << 16);
          _frame.v247 = 0;
          v77 = _frame.result[1];
          if ( BYTE1(_frame.result[0]) != 1 )
            goto LABEL_119;
          goto LABEL_322;
        }
        v77 = 5 * v75 + 2407;
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(v77) & 0xFFFFu);
      }
      _frame.result[1] = (_frame.result[1] & ~0xFFFF0000u) | (((uint16_t)(0) & 0xFFFFu) << 16);
      _frame.v247 = 0;
      if ( v76 != 1 )
      {
LABEL_119:
        v78 = v77 + 30;
LABEL_120:
        _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(v78) & 0xFFFFu) << 16);
        goto LABEL_121;
      }
      if ( v75 == 1 )
      {
LABEL_336:
        _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(v77 + 10) & 0xFFFFu) << 16);
LABEL_121:
        rx_process_pending(0, (int)_frame.result);
        v79 = (void *)(uintptr_t)(off_1202DC);
        *(volatile uint32_t *)off_1202D8 |= 0x10u;
        v80 = *v79 & 0xF;
        if ( v80 == 3 )
          rf_cmd_wait();
        v81 = (void *)(uintptr_t)(off_1202DC);
        *(volatile uint32_t *)off_1202E0 = dword_1202E4;
        *v81 = 16 * v80;
        write_bb_control();
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
      dispatch_event_handler_1(aRftestGetRxRes);
      v93 = *(volatile uint32_t *)off_120308;
      v94 = *(volatile uint32_t *)off_12030C;
      *(volatile uint32_t *)v8 = *(volatile uint32_t *)off_120308;
      v95 = v94 + v93;
      *((volatile uint32_t *)v8 + 1) = v95;
      dispatch_event_handler_1("rx fcsok=%d, total:%d\r\n", v93, v95);
      goto LABEL_21;
    case 5:
      dispatch_event_handler_1(aRftestSetRxsto);
      if ( *(volatile uint32_t *)off_1202DC << 28 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_1202CC = 1;
        }
        v86 = (volatile int *)off_1202FC;
        v87 = (void *)(uintptr_t)(off_1202DC);
        ++*(volatile uint32_t *)off_1202FC;
        *v87 = 0;
        v88 = (*(volatile uint32_t *)0x40501010u);
        while ( *v87 << 28 )
        {
          v89 = (*(volatile uint32_t *)0x40501010u) - v88;
          if ( v89 > 0x7530 )
            dispatch_event_handler_1(aIdleErr, *v87 << 28, 30000);
        }
        while ( (*(volatile uint32_t *)off_1202C4 & *(volatile uint32_t *)off_1202C0 & 4) == 0 )
          ;
        v90 = *v86;
        *(volatile uint32_t *)off_1202C8 = 4;
        if ( v90 )
        {
          v91 = v90 - 1;
          v92 = *(volatile uint32_t *)off_1202CC;
          *v86 = v91;
          if ( !v91 )
          {
            if ( v92 )
              __enable_irq();
          }
        }
        dispatch_event_handler_1(aForceIdled);
      }
      goto LABEL_21;
    case 6:
      dispatch_event_handler_1(aRftestRxMeterN);
      goto LABEL_21;
    case 7:
      dispatch_event_handler_1("set power: %x\r\n", *(volatile uint8_t *)(a2 + 8));
      v51 = (void *)(uintptr_t)(off_11FFB0);
      *(volatile uint32_t *)(uintptr_t)(off_11FFAC) = *(volatile uint8_t *)(a2 + 8) | (*(volatile uint8_t *)(a2 + 8) << 8);
      *v51 = 1;
      goto LABEL_21;
    case 8:
      v46 = get_xtal_ftune();
      v47 = *(volatile uint8_t *)(a2 + 8);
      v48 = (char)(v47 + v46);
      if ( v48 < 1 )
        v48 = 1;
      if ( v48 >= 31 )
        v48 = 31;
      dispatch_event_handler_1("set xtal cap: %x -> %x\r\n", v46, v48);
      set_xtal_ftune(v48);
      v49 = (uint8_t)get_xtal_ftune();
      v50 = mac_packet_dispatch();
      rf_cmd_check(v49);
      if ( !v47 )
        dispatch_event_handler_1(
          "calibed_cap:0x%x, templvl:%d\n",
          *(volatile uint8_t *)(off_120DBC + 4),
          *(volatile char *)(off_120DBC + 2));
      *(volatile uint32_t *)v8 = v49;
      dispatch_event_handler_1("read: %8x, temp=%d C\n", v49, v50);
      goto LABEL_21;
    case 9:
      v44 = (volatile unsigned int *)off_11FF98;
      v45 = (char)(*(volatile uint8_t *)(a2 + 8) + ((*(volatile uint32_t *)off_11FF98 >> 18) & 0x3F));
      if ( v45 < 1 )
        v45 = 1;
      if ( v45 >= 63 )
        v45 = 63;
      dispatch_event_handler_1(aSetXtalCapFine_0);
      *v44 = *v44 & 0xFF03FFFF | (v45 << 18);
      *(volatile uint32_t *)v8 = (*v44 >> 18) & 0x3F;
      goto LABEL_21;
    case 0xA:
      _frame.a1a = *(volatile uint8_t *)(a2 + 8);
      v43 = mmio_read32(_frame.a1a);
      dispatch_event_handler_1("get_efuse: block=%x,val=%x\r\n", _frame.a1a, v43);
      *(volatile uint32_t *)v8 = v43;
      goto LABEL_21;
    case 0xB:
      *v5 = pack_control_data(1, *(volatile uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xC:
      *v5 = pack_control_data(2, *(volatile uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0xD:
      v159 = pack_control_data(0, 0);
      *(volatile uint32_t *)v8 = v159;
      dispatch_event_handler_1("get freq_cal: %x\r\n", v159);
      goto LABEL_21;
    case 0xE:
      dispatch_event_handler_1(
        "set_mac_addr: %x, %x, %x, %x, %x, %x\r\n",
        *(volatile uint8_t *)(a2 + 13),
        *(volatile uint8_t *)(a2 + 12),
        *(volatile uint8_t *)(a2 + 11),
        *(volatile uint8_t *)(a2 + 10),
        *(volatile uint8_t *)(a2 + 9),
        *(volatile uint8_t *)(a2 + 8));
      v160 = *(volatile uint16_t *)(a2 + 12);
      v161 = *(volatile uint16_t *)(a2 + 8);
      v162 = *(volatile uint32_t *)(a2 + 8);
      v163 = HIBYTE(*(volatile uint32_t *)off_1209C4) & 2;
      v164 = v160;
      v165 = __rev16(v161);
      v166 = __rev16(v160);
      if ( v163 )
      {
        v192 = rf_status_check(v162, v164);
        v168 = v192;
        if ( v192 < 0 )
        {
          dispatch_event_handler_1("no room %d\n", v192);
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
        _frame.result[0] = (_frame.result[0] & ~0xFFFFu) | ((uint16_t)(v166) & 0xFFFFu);
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(v165) & 0xFFFFu);
        _frame.result[0] = (_frame.result[0] & ~0xFF00u) | (((uint8_t)(HIBYTE(v162)) & 0xFFu) << 8);
        _frame.result[0] = (_frame.result[0] & ~0xFF00u) | (((uint8_t)(BYTE2(v162)) & 0xFFu) << 8);
        bus_write_6((int)_frame.result);
        memset(_frame.result, 0, 6u);
        if ( bus_read_6((int)_frame.result) )
        {
          v167 = 917504;
          v168 = 14;
        }
        else
        {
          v167 = (uint16_t)__rev16(LOWORD(_frame.result[0])) | 0xF0000;
          v163 = bswap32(*(volatile unsigned int *)((volatile char *)_frame.result + 2));
          v168 = 15;
        }
      }
      *(volatile uint32_t *)v8 = v163;
      *((volatile uint32_t *)v8 + 1) = v167;
      _frame.v237 = v168;
      memcpy(_frame.v236, v8 + 72, 0x48u);
      dispatch_event_handler_1("set_mac_addr:%x,%x, %d\r\n", *(volatile uint32_t *)v8, *((volatile uint32_t *)v8 + 1), *((volatile uint32_t *)v8 + 2));
      goto LABEL_21;
    case 0xF:
      v145 = HIBYTE(*(volatile uint32_t *)off_1209C4) & 2;
      if ( v145 )
      {
        v189 = mmio_read_pair(&_frame.v240, &_frame.a2a);
        v145 = _frame.v240;
        v146 = _frame.a2a | (v189 << 16);
      }
      else
      {
        _frame.result[0] = 0;
        _frame.result[1] = (_frame.result[1] & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        if ( bus_read_6((int)_frame.result) )
        {
          _frame.v240 = 0;
          _frame.a2a = 0;
          v146 = 917504;
        }
        else
        {
          v145 = bswap32(*(volatile unsigned int *)((volatile char *)_frame.result + 2));
          _frame.a2a = (uint16_t)__rev16(LOWORD(_frame.result[0]));
          _frame.v240 = v145;
          v146 = _frame.a2a | 0xF0000;
        }
      }
      *(volatile uint32_t *)v8 = v145;
      *((volatile uint32_t *)v8 + 1) = v146;
      memcpy(_frame.v236, v8 + 72, 0x48u);
      dispatch_event_handler_1("get_mac_addr:%x,%x\r\n", *(volatile uint32_t *)v8, *((volatile uint32_t *)v8 + 1));
      goto LABEL_21;
    case 0x10:
      dispatch_event_handler_1(
        "set_bt_mac_addr: %x, %x, %x, %x, %x, %x\r\n",
        *(volatile uint8_t *)(a2 + 13),
        *(volatile uint8_t *)(a2 + 12),
        *(volatile uint8_t *)(a2 + 11),
        *(volatile uint8_t *)(a2 + 10),
        *(volatile uint8_t *)(a2 + 9),
        *(volatile uint8_t *)(a2 + 8));
      v60 = *(volatile uint32_t *)(a2 + 8);
      v61 = *(volatile uint16_t *)(a2 + 12);
      v62 = __rev16(v61);
      v63 = bswap32(v60);
      v64 = v60;
      if ( (*(volatile uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        v188 = rf_irq_handle(v60, v61);
        v66 = v188;
        if ( v188 < 0 )
        {
          if ( v188 != -1 )
            dispatch_event_handler_1(aSameSourceWith);
          dispatch_event_handler_1(aNoRoom);
        }
        v65 = v66 << 16;
      }
      else
      {
        memset(_frame.result, 0, 0x40u);
        hci_tx_packet((int)_frame.result);
        _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(v62) & 0xFFFFu) << 16);
        _frame.result[1] = v63;
        hci_rx_packet((int)_frame.result);
        hci_tx_packet((int)_frame.result);
        v61 = (uint16_t)__rev16(HIWORD(_frame.result[0]));
        v64 = bswap32(_frame.result[1]);
        v65 = 983040;
        v66 = 15;
      }
      *(volatile uint32_t *)v8 = v64;
      *((volatile uint32_t *)v8 + 1) = v65 | v61;
      dispatch_event_handler_1("set_bt_mac_addr:%04x%08x (remain:%d)\n", v61, v64, v66);
      goto LABEL_21;
    case 0x11:
      if ( (*(volatile uint32_t *)off_11FFC0 & 0x2000000) != 0 )
      {
        v187 = rf_irq_bit16_check(&_frame.v240, &_frame.a2a);
        v57 = _frame.v240;
        v56 = _frame.a2a;
        v59 = v187;
        v58 = v187 << 16;
      }
      else
      {
        memset(_frame.result, 0, 0x40u);
        hci_tx_packet((int)_frame.result);
        v56 = (uint16_t)__rev16(HIWORD(_frame.result[0]));
        v57 = bswap32(_frame.result[1]);
        _frame.v240 = v57;
        _frame.a2a = (uint16_t)v56;
        v58 = 983040;
        v59 = 15;
      }
      *(volatile uint32_t *)v8 = v57;
      *((volatile uint32_t *)v8 + 1) = v58 | v56;
      dispatch_event_handler_1("get_bt_mac_addr:%04x%08x (remain:%x)\n", v56, v57, v59);
      goto LABEL_21;
    case 0x12:
      dispatch_event_handler_1("set vendor info:%x\r\n", *(volatile uint8_t *)(a2 + 8));
      _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 8)) & 0xFFu);
      rf_regf_mask_shift(LOBYTE(_frame.result[0]));
      v54 = rf_regf_high_check((void *)(_frame.result));
      v55 = LOBYTE(_frame.result[0]);
      *(volatile uint32_t *)v8 = LOBYTE(_frame.result[0]);
      dispatch_event_handler_1("after set rd=%x(rem:%x)\n", v55, v54);
      goto LABEL_21;
    case 0x13:
      v52 = rf_regf_high_check((void *)(_frame.result));
      v53 = LOBYTE(_frame.result[0]);
      *(volatile uint32_t *)v8 = LOBYTE(_frame.result[0]);
      dispatch_event_handler_1("get vendor info: %x(rem:%x)\n", v53, v52);
      goto LABEL_21;
    case 0x14:
      if ( *(volatile uint32_t *)(a2 + 4) )
      {
        v190 = *(volatile uint8_t *)(a2 + 8);
        v158 = (void *)(uintptr_t)(off_120D80);
        v191 = v190 != 0;
        *(volatile uint32_t *)off_120D80 = v191;
        dispatch_event_handler_1("set txpwr_manual_mode: %x\r\n", v191);
      }
      else
      {
        v158 = (void *)(uintptr_t)(off_1209DC);
        dispatch_event_handler_1("txpwr_manual_mode: %x\r\n", *(volatile uint32_t *)off_1209DC);
      }
      *(volatile uint32_t *)v8 = *v158;
      goto LABEL_21;
    case 0x15:
      v150 = *(volatile uint32_t *)(a2 + 4);
      if ( !v150 || (v151 = *(volatile uint8_t *)(a2 + 8), !*(volatile uint8_t *)(a2 + 8)) )
      {
        v169 = (volatile char *)off_1209D8;
        dispatch_event_handler_1(aTxpwrLevel24g0);
        for ( i = 0; i != 3; ++i )
        {
          dispatch_event_handler_1("  [%x] =", i);
          v171 = v169;
          for ( j = 0; j != 12; ++j )
          {
            v174 = *v171++;
            v173 = v174;
            if ( v174 != -128 )
            {
              if ( j && !(j << 30) )
                uart_tx_byte(32);
              dispatch_event_handler_1(" %2d", v173);
            }
          }
          uart_tx_string((void *)(uintptr_t)(off_120A00));
          v169 += 12;
        }
        v175 = (volatile char *)off_1209D0;
        dispatch_event_handler_1(aTxpwrLevel5g01);
        for ( k = 0; k != 3; ++k )
        {
          dispatch_event_handler_1("  [%x] =", k);
          v177 = v175;
          for ( m = 0; m != 12; ++m )
          {
            v180 = *v177++;
            v179 = v180;
            if ( v180 != -128 )
            {
              if ( m && !(m << 30) )
                uart_tx_byte(32);
              dispatch_event_handler_1(" %2d", v179);
            }
          }
          uart_tx_string((void *)(uintptr_t)(off_120A00));
          v175 += 12;
        }
        goto LABEL_233;
      }
      if ( v151 == 1 )
      {
        if ( v150 > 3 )
        {
          v152 = *(volatile uint8_t *)(a2 + 9);
          if ( v152 <= 2 )
          {
            if ( v150 <= 0xB )
            {
              v153 = *(volatile uint8_t *)(a2 + 10);
              if ( v152 == 1 )
                v210 = *(volatile uint8_t *)(a2 + 10) <= 9u;
              else
                v210 = *(volatile uint8_t *)(a2 + 10) <= 0xBu;
              if ( v210 )
              {
                v155 = *(volatile char *)(a2 + 11);
                v156 = (void *)(uintptr_t)(off_121148);
                v157 = aSetTxpwrLevel2;
                goto LABEL_230;
              }
              goto LABEL_385;
            }
            dispatch_event_handler_1("set txpwr_level_2.4g:\n  [%d] =", *(volatile uint8_t *)(a2 + 9));
            v231 = a2 + 9;
            v232 = dword_1212C8 + 12 * v152;
            for ( n = 0; v152 != 1 || n <= 9; ++n )
            {
              v235 = *(volatile char *)++v231;
              v234 = v235;
              if ( v235 >= 32 )
                v234 = 32;
              *(volatile uint8_t *)++v232 = v234;
              if ( n )
              {
                if ( !(n << 30) )
                  uart_tx_byte(32);
                dispatch_event_handler_1(" %2d", v234);
                if ( n == 11 )
                  break;
              }
              else
              {
                dispatch_event_handler_1(" %2d", v234);
              }
            }
LABEL_397:
            uart_tx_string((void *)(uintptr_t)(off_1212C0));
            goto LABEL_233;
          }
LABEL_383:
          dispatch_event_handler_1("wrong lvl grp:%d\n", v152);
LABEL_233:
          memcpy(v8, (volatile char *)off_1209D8, 0x24u);
          memcpy(v8 + 36, (volatile char *)off_1209D0, 0x24u);
          goto LABEL_21;
        }
      }
      else
      {
        if ( v151 != 2 )
        {
          dispatch_event_handler_1(aWrongFunc);
          goto LABEL_233;
        }
        if ( v150 > 3 )
        {
          v152 = *(volatile uint8_t *)(a2 + 9);
          if ( v152 <= 2 )
          {
            if ( v150 <= 0xB )
            {
              v153 = *(volatile uint8_t *)(a2 + 10);
              if ( v152 == 1 )
                v154 = *(volatile uint8_t *)(a2 + 10) <= 9u;
              else
                v154 = *(volatile uint8_t *)(a2 + 10) <= 0xBu;
              if ( v154 )
              {
                v155 = *(volatile char *)(a2 + 11);
                v156 = (void *)(uintptr_t)(off_1209D0);
                v157 = aSetTxpwrLevel5;
LABEL_230:
                if ( v155 >= 32 )
                  v155 = (v155 & ~0xFFu) | ((uint8_t)(32) & 0xFFu);
                v156[12 * v152 + v153] = v155;
                dispatch_event_handler_1(v157, v152);
                goto LABEL_233;
              }
LABEL_385:
              dispatch_event_handler_1("wrong grp idx:%d\n", v153);
              goto LABEL_233;
            }
            dispatch_event_handler_1("set txpwr_level_5g:\n  [%d] =", *(volatile uint8_t *)(a2 + 9));
            v226 = a2 + 9;
            v227 = dword_1212BC + 12 * v152;
            for ( ii = 0; v152 != 1 || ii <= 9; ++ii )
            {
              v230 = *(volatile char *)++v226;
              v229 = v230;
              if ( v230 >= 32 )
                v229 = 32;
              *(volatile uint8_t *)++v227 = v229;
              if ( ii )
              {
                if ( !(ii << 30) )
                  uart_tx_byte(32);
                dispatch_event_handler_1(" %2d", v229);
                if ( ii == 11 )
                  goto LABEL_397;
              }
              else
              {
                dispatch_event_handler_1(" %2d", v229);
              }
            }
            goto LABEL_397;
          }
          goto LABEL_383;
        }
      }
      dispatch_event_handler_1(aWrongArgs_0);
      goto LABEL_233;
    case 0x16:
      v9 = *(volatile uint32_t *)(a2 + 4);
      if ( v9 && (v10 = *(volatile uint8_t *)(a2 + 8), *(volatile uint8_t *)(a2 + 8)) )
      {
        if ( v10 == 1 )
        {
          v211 = (volatile uint8_t *)off_121150;
          ++*(volatile uint8_t *)off_121150;
          if ( v9 > 3 )
          {
            v212 = *(volatile uint8_t *)(a2 + 9);
            if ( v212 <= 2 )
            {
              v213 = *(volatile uint8_t *)(a2 + 10);
              if ( v213 <= 2 )
              {
                v214 = *(volatile char *)(a2 + 11);
                v21 = (volatile char **)off_12119C;
                v215 = (volatile uint16_t *)off_121154;
                if ( v214 < -7 )
                  v214 = -7;
                if ( v214 >= 7 )
                  v214 = 7;
                *(volatile uint8_t *)(*(volatile uint32_t *)off_12119C + v213 + 3 * v212) = v214;
                v216 = v215[20];
                v217 = *((volatile uint8_t *)v215 + 36);
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
                  rf_ctrl_set(0, v216);
                  ++*v211;
                }
                v219 = v212;
                v15 = (volatile char **)off_12115C;
                dispatch_event_handler_1("set pwrofst2x_2.4g:\n  [%d][%d]=%d\n", v219, v213, v214);
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
            v21 = (volatile char **)off_12119C;
            v15 = (volatile char **)off_12115C;
            dispatch_event_handler_1(aWrongFunc_0);
            goto LABEL_20;
          }
          v11 = (volatile uint8_t *)off_11FCD0;
          ++*(volatile uint8_t *)off_11FCD0;
          if ( v9 > 3 )
          {
            v12 = *(volatile uint8_t *)(a2 + 9);
            if ( v12 <= 2 )
            {
              v13 = *(volatile uint8_t *)(a2 + 10);
              if ( v13 <= 5 )
              {
                v14 = *(volatile char *)(a2 + 11);
                v15 = (volatile char **)off_11FCD4;
                v16 = (volatile uint16_t *)off_11FCD8;
                if ( v14 < -7 )
                  v14 = -7;
                if ( v14 >= 7 )
                  v14 = 7;
                *(volatile uint8_t *)(*(volatile uint32_t *)off_11FCD4 + v13 + 6 * v12) = v14;
                v17 = v16[20];
                v18 = *((volatile uint8_t *)v16 + 36);
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
                  rf_ctrl_set(1, v17);
                  ++*v11;
                }
                v20 = v13;
                v21 = (volatile char **)off_11FD2C;
                dispatch_event_handler_1("set pwrofst2x_5g:\n  [%d][%d]=%d\n", v12, v20, v14);
                goto LABEL_20;
              }
            }
LABEL_373:
            v21 = (volatile char **)off_12119C;
            v15 = (volatile char **)off_12115C;
            dispatch_event_handler_1(aWrongTypeChgrp);
            goto LABEL_20;
          }
        }
        v21 = (volatile char **)off_12119C;
        v15 = (volatile char **)off_12115C;
        dispatch_event_handler_1(aWrongArgs);
      }
      else
      {
        v21 = (volatile char **)off_120DC8;
        dispatch_event_handler_1(aPwrofst2x24g01);
        dispatch_event_handler_1(aChan14591013);
        for ( jj = 0; jj != 3; ++jj )
        {
          dispatch_event_handler_1("\n  [%d] =", jj);
          for ( kk = 0; kk != 3; ++kk )
          {
            v183 = (*v21)[3 * jj + kk];
            dispatch_event_handler_1("\t%d", v183);
          }
        }
        v15 = (volatile char **)off_120D64;
        dispatch_event_handler_1(aPwrofst2x5g0Of);
        dispatch_event_handler_1(aChan3650516498);
        for ( mm = 0; mm != 3; ++mm )
        {
          dispatch_event_handler_1("\n  [%d] =", mm);
          for ( nn = 0; nn != 6; ++nn )
          {
            v186 = (*v15)[6 * mm + nn];
            dispatch_event_handler_1("\t%d", v186);
          }
        }
        dispatch_event_handler_1((const volatile char *)off_120D6C);
      }
LABEL_20:
      memcpy(v8, *v21, 9u);
      memcpy(v8 + 9, *v15, 0x12u);
LABEL_21:
      rx_irq_handler_1((int)v8);
      return 0;
    case 0x18:
      v82 = *(volatile uint32_t *)(a2 + 4);
      if ( v82 )
      {
        v83 = *(volatile uint8_t *)(a2 + 8);
        if ( !*(volatile uint8_t *)(a2 + 8) )
        {
          v84 = *(volatile uint8_t *)(a2 + 8);
          v82 = v84;
          v85 = v84;
          goto LABEL_129;
        }
        if ( v82 <= 3 )
        {
          dispatch_event_handler_1(aWrongArgs);
        }
        else
        {
          v84 = *(volatile uint8_t *)(a2 + 10);
          v85 = *(volatile char *)(a2 + 11);
          if ( (uint8_t)(*(volatile uint8_t *)(a2 + 11) + 7) <= 0xEu )
          {
            v82 = *(volatile uint8_t *)(a2 + 8);
            v83 = *(volatile uint8_t *)(a2 + 9);
LABEL_129:
            init_system(v82, v83, v84, v85);
            goto LABEL_130;
          }
          dispatch_event_handler_1("wrong ofst val: %d\n", *(volatile char *)(a2 + 11));
        }
LABEL_130:
        memcpy(v8, *(volatile char **)((volatile uint32_t *)(uintptr_t)&off_1202E8)[0], 9u);
        memcpy(v8 + 9, *(volatile char **)off_1202EC, 0x12u);
        memcpy(v8 + 27, (volatile char *)dword_1202F0, 9u);
        memcpy(v8 + 36, (volatile char *)dword_1202F4, 0x12u);
        goto LABEL_21;
      }
      v84 = 0;
      v83 = 0;
      v85 = 0;
      goto LABEL_129;
    case 0x19:
      v148 = *(volatile uint32_t *)(a2 + 4);
      if ( !v148 )
        goto LABEL_269;
      if ( v148 > 1 )
      {
        v149 = *(volatile uint8_t *)(a2 + 9);
        v148 = *(volatile uint8_t *)(a2 + 8);
LABEL_218:
        v34 = check_system_flag(v148, v149);
        goto LABEL_54;
      }
      if ( *(volatile uint8_t *)(a2 + 8) != 1 )
      {
        v148 = *(volatile uint8_t *)(a2 + 8);
LABEL_269:
        v149 = 0;
        goto LABEL_218;
      }
      goto LABEL_295;
    case 0x1A:
      if ( !*(volatile uint32_t *)(a2 + 4) )
        goto LABEL_244;
      v147 = *(volatile uint8_t *)(a2 + 8);
      if ( v147 > 2 )
        dispatch_event_handler_1(aWrongFunc);
      else
        bt_state_machine_dispatch(v147);
      goto LABEL_21;
    case 0x1D:
      ll_state_process(*(volatile uint8_t *)(a2 + 8), *(volatile uint8_t *)(a2 + 9), *(volatile uint8_t *)(a2 + 10));
      *(volatile uint32_t *)v8 = *(volatile uint8_t *)off_11FF88;
      goto LABEL_21;
    case 0x1E:
      if ( rf_flag_is_set() )
        dispatch_event_handler_1("curr cob state is %d\n", *(volatile uint8_t *)off_120DA4);
      if ( *(volatile uint8_t *)off_11FF88 == 1 )
      {
        v203 = get_xtal_ftune();
        v204 = *(volatile uint32_t *)off_121130;
        v205 = *(volatile uint8_t *)off_121134;
        v206 = (volatile int *)off_12113C;
        *((volatile uint32_t *)v8 + 1) = *(volatile uint32_t *)(uintptr_t)(off_121138);
        v207 = (v205 << 16) | (((v204 >> 18) & 0x3F) << 8) | v203;
        v208 = *v206;
        v209 = v206[1];
        *(volatile uint32_t *)v8 = v207;
        *((volatile uint32_t *)v8 + 2) = v208;
        *((volatile uint32_t *)v8 + 3) = v209;
      }
      else if ( *(volatile uint8_t *)off_11FF8C )
      {
        v40 = (volatile uint32_t *)dword_11FF90;
        v41 = &v8[4 * (uint8_t)(*(volatile uint8_t *)off_11FF8C - 1) + 4];
        v42 = v8;
        do
        {
          *(volatile uint32_t *)v42 = *v40;
          *((volatile uint32_t *)v42 + 1) = v40[1];
          v42 += 4;
          v40 += 2;
        }
        while ( v42 != v41 );
      }
      goto LABEL_21;
    case 0x20:
      if ( *(volatile uint32_t *)(a2 + 4) )
        rf_config_load(*(volatile uint8_t *)(a2 + 8));
      else
LABEL_244:
        dispatch_event_handler_1(aWrongArgs_0);
      goto LABEL_21;
    case 0x23:
      v36 = *(volatile uint32_t *)(a2 + 4);
      if ( !v36 )
        goto LABEL_281;
      v7 = *(volatile uint8_t *)(a2 + 8);
      if ( v36 > 1 )
      {
        v37 = *(volatile uint8_t *)(a2 + 9);
        v36 = *(volatile uint8_t *)(a2 + 8);
LABEL_63:
        v34 = check_address_alignment(v36, v37, v6, v7);
        goto LABEL_54;
      }
      if ( v7 != 1 )
      {
        v36 = *(volatile uint8_t *)(a2 + 8);
LABEL_281:
        v37 = 0;
        goto LABEL_63;
      }
      goto LABEL_295;
    case 0x24:
      v38 = *(volatile uint32_t *)(a2 + 4);
      if ( !v38 )
        goto LABEL_247;
      if ( v38 <= 4 )
      {
        if ( *(volatile uint8_t *)(a2 + 8) == 1 )
        {
LABEL_295:
          dispatch_event_handler_1(aWrongArgs_0);
          v34 = -4;
LABEL_54:
          *(volatile uint32_t *)v8 = v34;
          goto LABEL_21;
        }
        v38 = *(volatile uint8_t *)(a2 + 8);
LABEL_247:
        v39 = 0;
      }
      else
      {
        v39 = *(volatile uint32_t *)(a2 + 9);
        v38 = *(volatile uint8_t *)(a2 + 8);
      }
      v34 = lookup_entry(v38, v39);
      goto LABEL_54;
    case 0x25:
      if ( !*(volatile uint32_t *)(a2 + 4) )
        goto LABEL_243;
      v35 = *(volatile uint8_t *)(a2 + 8);
      *(volatile uint32_t *)off_11FD28 = v35;
LABEL_59:
      init_with_stack(v35);
      goto LABEL_21;
    case 0x26:
      if ( !*(volatile uint32_t *)(a2 + 4) )
        goto LABEL_243;
      mmio_bit_set(*(volatile uint8_t *)(a2 + 8));
      goto LABEL_21;
    case 0x27:
      v33 = *(volatile uint32_t *)(a2 + 4);
      if ( v33 )
      {
        v33 = *(volatile uint8_t *)(a2 + 8);
        if ( v33 > 1 )
          goto LABEL_295;
      }
      v34 = handle_state_change(v33);
      goto LABEL_54;
    case 0x28:
      dispatch_event_handler_1(aSetUsbOff);
      ke_event_loop(1071, 1, dword_11FD24);
      goto LABEL_21;
    case 0x50:
      memset((volatile int *)dword_11FD10, 0, 2u);
      if ( *(volatile uint32_t *)(a2 + 4) != 2 )
      {
        dispatch_event_handler_1("argc err %d, countrycode error, setcc fail\n", *(volatile uint32_t *)(a2 + 4));
        goto LABEL_21;
      }
      if ( !*(volatile uint8_t *)(a2 + 8) )
        goto LABEL_21;
      if ( *(volatile uint8_t *)(a2 + 9) )
      {
        v30 = a2 + 8;
if ( bt_msg_send_if_allocated((void *)(uintptr_t)(off_11FD14), (void *)(uintptr_t)(v30)) ) { dispatch_event_handler_1(aSetccSuccess);
          v31 = 2;
          v32 = (volatile char *)v30;
          goto LABEL_48;
        }
      }
      else
      {
        _frame.a1a = a2 + 8;
if ( bt_msg_send_if_allocated((void *)(uintptr_t)(off_121174), (void *)(uintptr_t)(a2 + 8)) ) { dispatch_event_handler_1(aSetccSuccess);
          v32 = (volatile char *)_frame.a1a;
          v31 = 1;
LABEL_48:
          memcpy((volatile char *)dword_11FD10, v32, v31);
          dispatch_event_handler_1("country code: %s\n", (const volatile char *)dword_11FD10);
          if ( (*(volatile uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            mmio_write_100000_2(dword_11FD10);
          goto LABEL_21;
        }
      }
      dispatch_event_handler_1(aCountrycodeErr);
      goto LABEL_21;
    case 0x51:
      _frame.result[0] = (_frame.result[0] & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      if ( (*(volatile uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)dword_120D7C);
        memcpy((volatile char *)_frame.result, (volatile char *)dword_120D7C, 2u);
        goto LABEL_30;
      }
      bus_read_2((int)_frame.result);
      if ( LOBYTE(_frame.result[0]) != 255 )
        goto LABEL_28;
      goto LABEL_42;
    case 0x52:
      *v5 = *(volatile char *)off_11FD08;
      goto LABEL_21;
    case 0x5B:
      if ( (*(volatile uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        dispatch_event_handler_1(aRdwrFlashUsbvi);
      }
      else
      {
        v26 = *(volatile uint32_t *)(a2 + 4);
        if ( v26 )
        {
          dispatch_event_handler_1("argc %d\n", v26);
          v27 = *(volatile uint32_t *)(a2 + 4);
          *(volatile uint32_t *)v8 = 0xFFFF;
          *((volatile uint32_t *)v8 + 1) = 0xFFFF;
          if ( v27 > 3 )
          {
            v28 = *(volatile uint16_t *)(a2 + 8);
            v29 = *(volatile uint16_t *)(a2 + 10);
            dispatch_event_handler_1("set vid 0x%04x, pid 0x%04x\n", v28, v29);
            memset(_frame.result, 0, 4u);
            _frame.result[0] = (_frame.result[0] & ~0xFFFFu) | ((uint16_t)(v28) & 0xFFFFu);
            _frame.result[0] = (_frame.result[0] & ~0xFFFF0000u) | (((uint16_t)(v29) & 0xFFFFu) << 16);
            mmio_write_400000_4_alt((int)_frame.result);
            *(volatile uint32_t *)v8 = v28;
            *((volatile uint32_t *)v8 + 1) = v29;
          }
        }
        else
        {
          memset(_frame.result, 0, 4u);
          v196 = mmio_write_400000_4((int)_frame.result);
          dispatch_event_handler_1("ret %d\n", v196);
          if ( v196 || HIWORD(_frame.result[0]) == 0xFFFF || LOWORD(_frame.result[0]) == 0xFFFF )
          {
            dispatch_event_handler_1(aNoUsbInfoInFla);
          }
          else
          {
            dispatch_event_handler_1("get vid 0x%04x, pid 0x%04x\r\n", LOWORD(_frame.result[0]), HIWORD(_frame.result[0]));
            v197 = (v197 & ~0xFFFFFFFFull) | ((uint32_t)(LOWORD(_frame.result[0])) & 0xFFFFFFFFu);
            v197 = (v197 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIWORD(_frame.result[0])) << 32);
            *(volatile uint64_t *)v8 = v197;
          }
        }
      }
      goto LABEL_21;
    case 0x5C:
      memset((volatile int *)dword_11FCF0, 0, 2u);
      if ( *(volatile uint32_t *)(a2 + 4) == 2 )
      {
        v25 = (volatile char *)(a2 + 8);
if ( bt_msg_send_if_allocated((void *)(uintptr_t)(off_11FCF4), (void *)(uintptr_t)((int)v25)) ) { dispatch_event_handler_1(aSetchSuccess);
          memcpy((volatile char *)dword_11FCF0, v25, 2u);
          dispatch_event_handler_1("channel country code: %s\n", (const volatile char *)dword_11FCF0);
          if ( (*(volatile uint32_t *)off_11FCE8 & 0x2000000) == 0 )
            mmio_write_800000_2(dword_11FCF0);
        }
        else
        {
          dispatch_event_handler_1(aChannelCountry);
        }
      }
      goto LABEL_21;
    case 0x5D:
      _frame.result[0] = (_frame.result[0] & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      if ( (*(volatile uint32_t *)off_11FCE8 & 0x2000000) != 0 )
      {
        dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)dword_120D74);
        memcpy((volatile char *)_frame.result, (volatile char *)dword_120D74, 2u);
      }
      else
      {
        rf_cmd_wait_n_7e((int)_frame.result);
        if ( LOBYTE(_frame.result[0]) != 255 )
        {
LABEL_28:
          if ( BYTE1(_frame.result[0]) != 255 )
          {
            dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)_frame.result);
            goto LABEL_30;
          }
        }
LABEL_42:
        dispatch_event_handler_1(aNoCountrycodeI);
      }
LABEL_30:
      *(volatile uint32_t *)v8 = LOWORD(_frame.result[0]);
      goto LABEL_21;
    case 0x5E:
      goto LABEL_25;
    case 0x5F:
      if ( *(volatile uint32_t *)(a2 + 4) )
      {
        v23 = *(volatile uint8_t *)(a2 + 8);
        osal_int_exit(v23);
        if ( v23 )
          dispatch_event_handler_1(aEnableBlockPro);
        else
          dispatch_event_handler_1(aDisableBlockPr);
      }
      else
      {
        dispatch_event_handler_1(aWrongArgs);
      }
LABEL_25:
      v24 = osal_int_enter();
      dispatch_event_handler_1("get block protect: %d\n", v24);
      *(volatile uint32_t *)v8 = v24;
      goto LABEL_21;
    case 0x60:
      memset(_frame.result, 0, 0x40u);
      memset(_frame.result, 0, 0x40u);
      if ( !*(volatile uint32_t *)(a2 + 4) )
      {
        _frame.a2a = (_frame.a2a & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        goto LABEL_162;
      }
      v198 = *(volatile uint8_t *)(a2 + 8);
      dispatch_event_handler_1("channel_num %d\n", v198);
      if ( v198 > 0x23 )
      {
        v107 = 5 * v198 + 5000;
        _frame.v242 = v107;
        _frame.a2a = (_frame.a2a & ~0xFFFFu) | ((uint16_t)(1) & 0xFFFFu);
        goto LABEL_163;
      }
      _frame.a2a = (_frame.a2a & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      if ( v198 <= 0xD )
      {
        v107 = 5 * v198 + 2407;
        _frame.v242 = v107;
        goto LABEL_163;
      }
      if ( v198 == 14 )
      {
LABEL_162:
        v107 = 2484;
        _frame.v242 = 2484;
LABEL_163:
        _frame.a2a = (_frame.a2a & ~0xFFFF0000u) | (((uint16_t)(v107) & 0xFFFFu) << 16);
        _frame.v243 = 0;
        _frame.v244 = 0;
        rx_process_pending(0, (int)&_frame.a2a);
        rf_core_init(0xFFFF, (int)_frame.result);
        memcpy(v8, (volatile char *)_frame.result, 0x40u);
        goto LABEL_21;
      }
      dispatch_event_handler_1("Not supported chan: %d\n", v198);
      return -2;
    case 0x61:
      if ( (*(volatile uint32_t *)off_120318 & 0x2000000) != 0 )
      {
        dispatch_event_handler_1(aRdwrFlashPcieI, *(volatile uint32_t *)off_120318 << 6);
      }
      else
      {
        v100 = *(volatile uint32_t *)(a2 + 4);
        *v5 = 0xFFFF;
        v5[1] = 0xFFFF;
        v5[2] = 0xFFFF;
        v5[3] = 0xFFFF;
        v5[4] = 255;
        if ( v100 )
        {
          dispatch_event_handler_1("argc %d\n", v100);
          if ( *(volatile uint32_t *)(a2 + 4) > 8u )
          {
            v101 = *(volatile uint8_t *)(a2 + 16);
            v102 = *(volatile uint8_t *)(a2 + 14) | (*(volatile uint8_t *)(a2 + 15) << 8);
            v103 = *(volatile uint8_t *)(a2 + 8) | (*(volatile uint8_t *)(a2 + 9) << 8);
            v104 = *(volatile uint8_t *)(a2 + 10) | (*(volatile uint8_t *)(a2 + 11) << 8);
            v105 = *(volatile uint64_t *)(a2 + 8);
            _frame.a1a = *(volatile uint8_t *)(a2 + 12) | (*(volatile uint8_t *)(a2 + 13) << 8);
            dispatch_event_handler_1(
              "set vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\n",
              v103,
              v104,
              _frame.a1a,
              v102,
              v101);
            memset(_frame.result, 0xFFu, 0xAu);
            *(volatile uint64_t *)_frame.result = v105;
            _frame.v246 = v101;
            send_cmd_short((int)_frame.result);
            v106 = _frame.a1a;
            *((volatile uint32_t *)v8 + 4) = v101;
            *(volatile uint32_t *)v8 = v103;
            *((volatile uint32_t *)v8 + 1) = v104;
            *((volatile uint32_t *)v8 + 2) = v106;
            *((volatile uint32_t *)v8 + 3) = v102;
          }
        }
        else
        {
          memset(_frame.result, 0xFFu, 0xAu);
          v193 = mmio_write_1000000_10((int)_frame.result);
          dispatch_event_handler_1("ret %d\n", v193);
          if ( v193 )
          {
            dispatch_event_handler_1(aNoPcieInfoInFl);
          }
          else
          {
            dispatch_event_handler_1(
              "get vid %x, did %x, subsys_vid %x, subsys_id %x, rev_id %x\r\n",
              LOWORD(_frame.result[0]),
              HIWORD(_frame.result[0]),
              LOWORD(_frame.result[1]),
              HIWORD(_frame.result[1]),
              _frame.v246);
            v194 = (v194 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIWORD(_frame.result[1])) << 32);
            v195 = (v195 & ~0xFFFFFFFFull) | ((uint32_t)(LOWORD(_frame.result[0])) & 0xFFFFFFFFu);
            v195 = (v195 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIWORD(_frame.result[0])) << 32);
            v194 = (v194 & ~0xFFFFFFFFull) | ((uint32_t)(LOWORD(_frame.result[1])) & 0xFFFFFFFFu);
            *(volatile uint64_t *)v8 = v195;
            *((volatile uint64_t *)v8 + 1) = v194;
            *((volatile uint32_t *)v8 + 4) = _frame.v246;
          }
        }
      }
      goto LABEL_21;
    case 0x108:
      dispatch_event_handler_1(aCheckFlash);
      _frame.result[0] = 0;
      memset(&_frame.result[1], 0, 0x3FCu);
      if ( *(volatile uint32_t *)(a2 + 4) == 8 )
      {
        v96 = *(volatile uint32_t *)(a2 + 8);
        if ( !v96 )
          v96 = 0x4000000;
        if ( (*(volatile uint32_t *)off_120318 & 0x2000000) == 0 )
        {
          v97 = *(volatile uint32_t *)(a2 + 12);
          if ( v97 )
          {
LABEL_149:
            dispatch_event_handler_1("crc begin 0x%x 0x%x\n", v96, v97);
            if ( v97 >> 10 )
            {
              v98 = v96;
              v99 = -1;
              do
              {
                call_slot_0x1d8(v98, 1024, (int)_frame.result);
                v98 += 1024;
                v99 = crc32_update_lsb((volatile uint8_t *)_frame.result, 1024, v99);
              }
              while ( v98 != v96 + (v97 >> 10 << 10) );
            }
            else
            {
              v99 = -1;
            }
            if ( (v97 & 0x3FF) != 0 )
            {
              call_slot_0x1d8((v97 & 0xFFFFFC00) + v96, v97 & 0x3FF, (int)_frame.result);
              v99 = crc32_update_lsb((volatile uint8_t *)_frame.result, v97 & 0x3FF, v99);
            }
            dispatch_event_handler_1("crc_res 0x%x\n", v99);
LABEL_155:
            *(volatile uint32_t *)v8 = v99;
            goto LABEL_21;
          }
LABEL_148:
          v97 = ke_event_schedule();
          goto LABEL_149;
        }
      }
      else if ( (*(volatile uint32_t *)off_120318 & 0x2000000) == 0 )
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


// ke_send_msg_410 @ 0x1212d0
int ke_send_msg_410(int a1, int a2, int a3, int a4) {
  int v5; // r0
  int v6; // r1
  volatile uint32_t *v7; // r4
  volatile uint32_t *v9; // r2
  volatile uint8_t *v10; // r0
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r3

  v5 = ke_msg_send_1(1040, a4, a3, 4);
  v6 = *(volatile uint16_t *)(a2 + 4);
  v7 = (volatile uint32_t *)v5;
  if ( *(volatile uint8_t *)(off_121348 + 0xB1) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v9 = (void *)(uintptr_t)(off_121354);
    *(volatile uint32_t *)off_121350 |= 0x2000000u;
    v10 = (void *)(uintptr_t)(off_121358);
    v9[14] |= 0x10u;
    *v10 = 1;
  }
  if ( v6 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_121354);
    *((volatile uint32_t *)off_121354 + 18) = *(volatile uint32_t *)a2;
    v11[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v12 = (void *)(uintptr_t)(off_121354);
    *((volatile uint32_t *)off_121354 + 19) = *(volatile uint32_t *)a2;
    v12[75] = 128;
  }
LABEL_5:
  *v7 = 0;
  dispatch_event_handler_1("\x9D\x81""DBG: Boot NPC %d\n", v6);
  rx_irq_handler_1((int)v7);
  return 0;
}


// patch_ram_download @ 0x12135c
int patch_ram_download(int a1, volatile char **a2, int a3, int a4) {
  int v5; // r0
  volatile char *v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = ke_msg_send_1(1060, a4, a3, 1032);
  v7 = (unsigned int)a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v6);
  *(volatile uint32_t *)(v5 + 4) = v7;
  v8 = v5;
  memcpy((volatile char *)(v5 + 8), v6, v7);
  dispatch_event_handler_1(asc_12E8F8, *a2, &(*a2)[*(volatile uint32_t *)(v8 + 4)], *(volatile uint32_t *)(v8 + 8));
  rx_irq_handler_1(v8);
  return 0;
}


// rf_write_0x40c @ 0x1213a4
int rf_write_0x40c(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint32_t *v5; // r5
  volatile char *v6; // r0
  int v7; // zf
  unsigned int v8; // r2

  v5 = (volatile uint32_t *)ke_msg_send_1(1036, a4, a3, 4);
  v6 = (volatile char *)*a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  memcpy(v6, (volatile char *)a2 + 8, v8);
  dispatch_event_handler_1(asc_12E93C, *a2, a2[1] + *a2, a2[2], *v5);
  rx_irq_handler_1((int)v5);
  return 0;
}


// rf_clear_buf_0x40a @ 0x1213fc
int rf_clear_buf_0x40a(int a1, int a2, int16_t a3, int16_t a4) {
  volatile uint32_t *v4; // r0

  v4 = (volatile uint32_t *)ke_msg_send_1(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  rx_irq_handler_1((int)v4);
  return 0;
}



// rf_write_0x412 @ 0x12141c
int rf_write_0x412(int a1, volatile int *a2, int a3, int a4) {
  volatile int *v5; // r5
  int v6; // r2
  int v7; // r0
  int v8; // r3
  int v9; // r1

  v5 = (volatile int *)ke_msg_send_1(1042, a4, a3, 8);
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    critical_enter3(*a2, a2[2], a2[1], 1);
    v7 = critical_enter(*a2, 1);
    v6 = *a2;
  }
  else
  {
    *(volatile uint32_t *)*a2 ^= (a2[2] ^ *(volatile uint32_t *)*a2) & a2[1];
    v6 = *a2;
    v7 = *(volatile uint32_t *)*a2;
  }
  v5[1] = v7;
  v8 = a2[2];
  v9 = a2[1];
  *v5 = v6;
  dispatch_event_handler_1(
    "\x9D\x81""DBG: Writing memory with mask:0x%08x, data:0x%08x / %d: [0x%08x] = 0x%08x / %d\n",
    v9,
    v8,
    v8,
    v6,
    v7,
    v7);
  rx_irq_handler_1((int)v5);
  return 0;
}


// rf_write_0x401 @ 0x121490
int rf_write_0x401(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v5; // r0
  volatile int *v6; // r1
  volatile int **v7; // r4
  int v8; // r3
  int v10; // r0

  v5 = ke_msg_send_1(1025, a4, a3, 8);
  v6 = (volatile int *)*a2;
  v7 = (volatile int **)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v10 = critical_enter(*a2, 1);
    v6 = (volatile int *)*a2;
    v7[1] = (volatile int *)v10;
    v8 = v10;
  }
  else
  {
    v8 = *v6;
    *(volatile uint32_t *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  dispatch_event_handler_1("\x9D\x81""DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", v6, v8, v8);
  rx_irq_handler_1((int)v7);
  return 0;
}


// bt_post_event_14ea14 @ 0x1214dc
int bt_post_event_14ea14(int a1, volatile uint32_t *a2, int a3, int a4) {
  dispatch_event_handler_1("\x9D\x81""DBG: Setting severity filter: 0x%08x\n", *a2);
  ((volatile uint32_t *)(uintptr_t)off_12150C)[1] = *a2;
  ke_evt_handler(1031, a4, a3);
  return 0;
}


// bt_post_event_14ea3c @ 0x121510
int bt_post_event_14ea3c(int a1, volatile uint32_t *a2, int a3, int a4) {
  dispatch_event_handler_1("\x9D\x81""DBG: Setting module filter: 0x%08x\n", *a2);
  *(volatile uint32_t *)(uintptr_t)(off_121540) = *a2;
  ke_evt_handler(1029, a4, a3);
  return 0;
}


// rf_write_0x403 @ 0x121544
int rf_write_0x403(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v5; // r0
  volatile uint32_t *v6; // r2
  volatile int *v7; // r5
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = ke_msg_send_1(1027, a4, a3, 8);
  v6 = (volatile uint32_t *)*a2;
  v7 = (volatile int *)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    critical_enter2((int)v6, a2[1], 1);
    v9 = critical_enter(*a2, 1);
    v8 = *a2;
  }
  else
  {
    *v6 = a2[1];
    v8 = *a2;
    v9 = *(volatile uint32_t *)*a2;
  }
  v7[1] = v9;
  v10 = a2[1];
  *v7 = v8;
  dispatch_event_handler_1("\x9D\x81""DBG: Writing memory with 0x%08x / %d: [0x%08x] = 0x%08x / %d\n", v10, v10, v8, v9, v9);
  rx_irq_handler_1((int)v7);
  return 0;
}


// bt_set_reg_0x42e @ 0x1215a8
int bt_set_reg_0x42e() {
  volatile uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = (void *)(uintptr_t)(off_121604);
  v1 = ke_int_lock(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    jump_10de98();
    ke_event_loop(1070, 1, dword_121608);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_set_frequency_2(v1);
      ke_event_loop(1070, 1, 1000 * *((volatile uint32_t *)off_12160C + 91));
      v0[1] = 1;
    }
    return 0;
  }
}



// schedule_callbacks @ 0x121610
void schedule_callbacks() {
  int v0; // r0

  v0 = wait_hw_ready();
  ke_event_set(v0);
  while ( 1 )
    ;
}



// send_event_42d @ 0x12161c
void send_event_42d() {
  volatile char *v0; // r0

  dispatch_event_handler_1(aErrWlanFcTimeo);
  v0 = (void *)(uintptr_t)(ke_int_lock((int)(uintptr_t)((volatile char *)0x42D), 1));
  schedule_callbacks((int)v0);
}


// send_event_42c @ 0x121638
void send_event_42c() {
  volatile char *v0; // r0

  dispatch_event_handler_1(aReboot);
  v0 = (void *)(uintptr_t)(ke_int_lock((int)(uintptr_t)((volatile char *)0x42C), 1));
  schedule_callbacks((int)v0);
}


// rf_write_0x40e @ 0x121654
int rf_write_0x40e(int a1, volatile int *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  volatile uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = ke_msg_send_1(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (volatile uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      dispatch_event_handler_1("\x9D\x81""Auto boot to 0x%08x\r\n", *(volatile uint32_t *)(*a2 + 4));
      break;
    case 2:
      dispatch_event_handler_1("\x9D\x81""Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = dispatch_event_handler_1("delay %d\r\n", v9);
      if ( !v9 )
        schedule_callbacks(v10);
      ke_event_loop(1068, 1, v9 << 10);
      break;
    default:
      dispatch_event_handler_1(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)mmio_read32(0xFu);
  dispatch_event_handler_1(asc_12EB1C);
  rx_irq_handler_1((int)v7);
  return 0;
}


// process_event_lock @ 0x1216dc
void process_event_lock() {
  int v0; // r0

  v0 = dispatch_event_handler_1(aReboot);
  schedule_callbacks(v0);
}


// rf_init_phy @ 0x1216ec
int rf_init_phy() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r10
  volatile uint32_t *v2; // r6
  volatile uint32_t *v3; // r7
  volatile uint32_t *v4; // r8
  volatile uint32_t *v5; // r9
  volatile uint32_t *v6; // r5
  int v7; // r0
  int v8; // r3
  volatile uint32_t *v9; // r7
  volatile uint32_t *v10; // r5
  int v11; // r4
  int v13; // nf
  volatile uint32_t **v14; // r3

  v0 = (void *)(uintptr_t)(off_1218B4);
  v1 = (void *)(uintptr_t)(off_121950);
  v2 = (void *)(uintptr_t)(off_1218B8);
  v3 = (void *)(uintptr_t)(off_1218BC);
  v4 = (void *)(uintptr_t)(off_121954);
  v5 = (void *)(uintptr_t)(off_121958);
  v6 = (void *)(uintptr_t)(off_1218C0);
  dispatch_event_handler_1("\x9B""current state is %d\r\n", *(volatile uint32_t *)off_1218AC & 0xF);
  dispatch_event_handler_1("\x9B""40328188=%08x, 4032818c=%x\r\n", *v0, *(volatile uint32_t *)off_1218C4);
  dispatch_event_handler_1("txlist cptr 40128540=%08x \r\n", *v1);
  dispatch_event_handler_1("ac0 sptr 40328528=%08x \r\n", *v2);
  dispatch_event_handler_1("ac1 sptr 4032852c=%08x \r\n", *v3);
  dispatch_event_handler_1("ac2 sptr 40328530=%08x \r\n", *v4);
  dispatch_event_handler_1("ac3 sptr 40328534=%08x \r\n", *v5);
  dispatch_event_handler_1("hiq sptr 4032853c=%08x \r\n", *v6);
  dispatch_event_handler_1(
    "\x9B""ac0header=%08x, ac1header=%08x, ac2header=%08x, ac3header=%08x, hiqheader=%x\r\n",
    *(volatile uint32_t *)off_1218E4,
    *(volatile uint32_t *)off_1218E8,
    *(volatile uint32_t *)off_1218EC,
    *(volatile uint32_t *)off_1218F0,
    *(volatile uint32_t *)off_12195C);
  dispatch_event_handler_1("\x9Bstatus of 0x40328528=%08x\r\n", *(volatile uint32_t *)(*v2 + 60));
  dispatch_event_handler_1("\x9Bstatus of 0x4032852c=%08x\r\n", *(volatile uint32_t *)(*v3 + 60));
  dispatch_event_handler_1("\x9Bstatus of 0x40328530=%08x\r\n", *(volatile uint32_t *)(*v4 + 60));
  dispatch_event_handler_1("\x9Bstatus of 0x40328534=%08x\r\n", *(volatile uint32_t *)(*v5 + 60));
  dispatch_event_handler_1("\x9Bstatus of 0x4032853c=%08x\r\n", *(volatile uint32_t *)(*v6 + 60));
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (volatile uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(volatile uint32_t **)off_121948;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (volatile uint32_t *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (volatile uint32_t *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (volatile uint32_t *)*v4;
  }
  else if ( (*v0 & 0x20000) != 0 )
  {
    v0 = (volatile uint32_t *)*v5;
  }
  else
  {
    v14 = (volatile uint32_t **)(*v0 << 30);
    v13 = (*v0 & 2) != 0;
    if ( (*v0 & 2) != 0 )
      v14 = (volatile uint32_t **)dword_12194C;
    else
      v0 = (volatile uint32_t *)*v1;
    if ( v13 )
      v0 = *v14;
  }
  if ( v0 )
  {
    handle_ipc_request((int)v0, 68, 1, 0);
    handle_ipc_request(v0[9], 52, 1, 0);
    dispatch_event_handler_1("\x9B""frmlen=%x\r\n", v0[6]);
    v7 = v0[4];
    if ( v7 )
    {
      handle_ipc_request(v7, v0[5] + 1 - v7, 1, 0);
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    else
    {
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    handle_ipc_request(*(volatile uint32_t *)(v8 + 8), *(volatile uint32_t *)(v8 + 12) + 1 - *(volatile uint32_t *)(v8 + 8), 1, 0);
  }
LABEL_6:
  v9 = (void *)(uintptr_t)(off_121910);
  v10 = (void *)(uintptr_t)(off_121918);
  v11 = (v11 & ~0xFFu) | ((uint8_t)(8) & 0xFFu);
  do
  {
    dispatch_event_handler_1("\x9B""0x40320500=%08x\r\n", *v9);
    dispatch_event_handler_1("\x9B""0x40320504=%08x\r\n", *v10);
    v11 = (uint8_t)(v11 - 1);
  }
  while ( v11 );
  dispatch_event_handler_1("\x9B""0x40320514=%08x\r\n", *(volatile uint32_t *)off_121920);
  dispatch_event_handler_1("\x9B""0x40320518=%08x\r\n", *(volatile uint32_t *)off_121928);
  dispatch_event_handler_1("\x9B""0x4032051c=%08x\r\n", *(volatile uint32_t *)off_121930);
  dispatch_event_handler_1("\x9B""0x40320520=%08x\r\n", *(volatile uint32_t *)off_121938);
  return dispatch_event_handler_1("\x9B""0x40320560=%08x\r\n", *(volatile uint32_t *)off_121940);
}


// ke_int_lock_1 @ 0x121960
int ke_int_lock_1(int a1, int a2, int a3) {
  volatile int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1219B4 = 1;
  }
  v3 = (volatile int *)off_1219B8;
  ++*(volatile uint32_t *)off_1219B8;
  result = dispatch_event_handler_1("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
  if ( *(volatile int *)off_1219C0 >= 0 )
  {
    rf_cmd_cancel();
    result = set_busy_flag_alt(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_1219B4;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// flash_ctrl_init @ 0x1219c4
int flash_ctrl_init(int a1, int a2, int a3) {
  int result; // r0

  __disable_irq();
  *(volatile uint32_t *)off_1219E8 = 0;
  result = dispatch_event_handler_1("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
while ( *(volatile uint32_t *)(uintptr_t)(off_1219F0) ) ;
  return result;
}


// flash_cmd_exec @ 0x1219f4
int flash_cmd_exec(int a1, int a2, int a3) {
  return dispatch_event_handler_1("\x9BWARNING (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
}


// ke_int_unlock @ 0x121a10
void ke_int_unlock() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_121A38 = 1;
  }
  v0 = (void *)(uintptr_t)(off_121A3C);
  v1 = *(volatile uint32_t *)off_121A3C;
  v2 = *(volatile uint32_t *)off_121A3C + 1;
  *(volatile uint32_t *)off_121A3C = v2;
  if ( v2 )
  {
    v3 = (void *)(uintptr_t)(off_121A38);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}



// nullsub_5 @ 0x121a40
int nullsub_5(void) {
  return 0;
}


// clear_global_187218 @ 0x121a44
int clear_global_187218() {
  memset((volatile int *)dword_121A54, 0, 8u);
  return 0;
}



// jump_10d02c @ 0x121a58
int jump_10d02c() {
  return rf_irq_handler();
}



// patch_trampoline @ 0x121a5c
int patch_trampoline(volatile uint16_t *a1) {
  return (int)(uintptr_t)(mac_ll_scheduler((int)(uintptr_t)(a1)));
}



// return_2 @ 0x121a60
int return_2() {
  return 2;
}



// j_nullsub_6 @ 0x121a64
/* luna: Tail-call thunk that invokes nullsub_6 and returns its value. */
int j_nullsub_6(void) {
  return nullsub_6();
}



// patch_check_enabled @ 0x121a68
int patch_check_enabled() {
  if ( **(volatile uint8_t **)off_121A7C == 3 )
    return lookup_mac_descriptor();
  else
    return 1;
}



// return_0 @ 0x121a80
int return_0() {
  return 0;
}



// patch_check_enabled_ctx @ 0x121a84
int patch_check_enabled_ctx(int result) {
  int v1; // r4
  volatile char *v2; // r0
  volatile char *v3; // r5
  volatile uint32_t *v4; // r4

  if ( **(volatile uint8_t **)off_121AD8 == 3 )
  {
    v1 = result;
    v2 = (volatile char *)poll_hw_status();
    v3 = v2;
    if ( v2 )
    {
      *(volatile uint32_t *)(v1 + 24) = 49374;
      memcpy(v2, (volatile char *)v1, 0x1Cu);
      v4 = (void *)(uintptr_t)(off_121ADC);
      while ( !*(volatile uint32_t *)off_121ADC )
        ;
      check_kernel_state(*(volatile uint32_t *)off_121AE0 + 540, (volatile uint32_t *)v3 - 1);
      *v4 = 1;
      rf_enable();
    }
    else
    {
      return dispatch_event_handler_1(aErrUfHostRxBuf);
    }
  }
  return result;
}


// return_0_tail @ 0x121ae8
int return_0_tail() {
  return handle_interrupt_save(0);
}



// ke_int_lock_mode @ 0x121af0
int ke_int_lock_mode(unsigned int a1, int a2) {
  volatile int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_121B34 = 1;
  }
  v3 = (volatile int *)off_121B38;
  ++*(volatile uint32_t *)off_121B38;
  result = log_u32_value((volatile uint32_t *)a2);
  if ( a1 <= 3 )
    --*(volatile uint8_t *)(dword_121B3C + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_121B34;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// tlv_find @ 0x121b40
unsigned int tlv_find(unsigned int a1, int a2, int a3) {
  unsigned int v3; // r7
  volatile int *v4; // r5
  volatile uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  volatile uint8_t *v11; // r4
  volatile uint8_t *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(volatile uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (volatile int *)off_121BD0;
    if ( a3 < (int)*(volatile uint32_t *)off_121BD0 )
    {
      v8 = (volatile uint8_t *)dword_121BD8;
      do
      {
        uart_tx_string(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_121BDC;
      v11 = (volatile uint8_t *)(a1 - 1);
      v12 = (volatile uint8_t *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          uart_tx_byte(*v11);
          if ( v11 == v12 )
            goto rf_cmd_dispatch_n_392;
        }
        uart_tx_string((volatile uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    uart_tx_string((volatile uint8_t *)dword_121BD8);
    --*(volatile uint32_t *)off_121BD0;
  }
rf_cmd_dispatch_n_392:
  --*(volatile uint32_t *)off_121BD4;
  return v3;
}



