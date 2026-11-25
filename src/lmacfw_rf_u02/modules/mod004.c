// apply_dsp_transform @ 0x10b048
int apply_dsp_transform(int a1, int a2, int a3, int a4, volatile uint16_t *a5, int a6, int a7) {
  int v7; // s26
  int v8; // r8
  int v9; // r1
  int v10; // r10
  int v11; // r9
  volatile int *v12; // r7
  int v13; // lr
  int v14; // r12
  int i; // r6
  int v16; // r0
  volatile unsigned int *v17; // r2
  volatile int *v18; // r4
  volatile unsigned int *v19; // r0
  unsigned int v20; // r3
  volatile uint32_t *v21; // r4
  float v22; // s18
  int v23; // r7
  volatile uint32_t *v24; // r3
  int v25; // r5
  int v26; // r4
  int v27; // r7
  int v28; // r9
  int v29; // r0
  volatile int *v30; // r10
  int k; // r1
  int v32; // r12
  volatile unsigned int *v33; // r2
  volatile unsigned int *v34; // r8
  volatile int *v35; // r12
  int v36; // t1
  volatile uint32_t *v37; // r0
  int v39; // r8
  volatile unsigned int *v40; // r2
  volatile int *v41; // lr
  volatile unsigned int *v42; // r8
  int v43; // t1
  int v44; // r5
  volatile unsigned int *v45; // r2
  volatile int *v46; // r4
  volatile unsigned int *v47; // r5
  unsigned int v48; // r3
  unsigned int v49; // r4
  volatile int *v50; // r9
  int v51; // r11
  int v52; // s25
  volatile int *v53; // r12
  int v54; // r0
  int v55; // r1
  int v56; // r2
  int v57; // r3
  int v58; // r1
  int v59; // r2
  int v60; // r1
  int v61; // r11
  unsigned int v62; // r5
  volatile unsigned int *v63; // r11
  unsigned int v64; // t1
  int v65; // r6
  int v66; // r10
  int v67; // r4
  int v68; // r5
  unsigned int v69; // t1
  float v70; // s22
  int v71; // s19
  volatile float *v72; // r3
  int v73; // r4
  int v74; // r1
  int v75; // r8
  volatile int *v76; // r0
  int j; // r3
  unsigned int v78; // t1
  int v79; // r2
  volatile int *v80; // r6
  unsigned int v81; // r11
  int v82; // lr
  float v83; // s20
  int v84; // r12
  int v85; // r5
  int v86; // r9
  int v87; // r0
  uint64_t v88; // kr00_8
  unsigned int v89; // r3
  volatile int *v90; // r8
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
  volatile float *v101; // r5
  float v102; // s15
  uint64_t v103; // r4
  int v104; // s27
  int v105; // s17
  int v106; // r7
  float v107; // s21
  float v108; // s23
  volatile float *v109; // r6
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
  volatile unsigned int *v120; // r7
  float v121; // s17
  float v122; // s14
  int v123; // zf
  uint16_t v124; // r0
  int v125; // r3
  volatile uint16_t *v126; // r6
  int v127; // t1
  int v128; // r3
  volatile float *v129; // r6
  int v130; // t1
  int v131; // r3
  volatile int *v132; // r4
  unsigned int v133; // r0
  volatile unsigned int *v134; // r4
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
  struct __attribute__((packed)) { int a8; // [sp+Ch] [bp-588h]
  char _pad1[20]; union { int v146; // [sp+24h] [bp-570h]
  int v147; }; // [sp+24h] [bp-570h]
  int a4a; // [sp+28h] [bp-56Ch]
  int v149; // [sp+2Ch] [bp-568h]
  union { int v150; // [sp+30h] [bp-564h]
  int v151; }; // [sp+30h] [bp-564h]
  union { volatile uint32_t *v152; // [sp+34h] [bp-560h]
  int v153; }; // [sp+34h] [bp-560h]
  union { int v154; // [sp+38h] [bp-55Ch]
  int v155; }; // [sp+38h] [bp-55Ch]
  int v156; // [sp+3Ch] [bp-558h]
  int v157; // [sp+40h] [bp-554h]
  int v158; // [sp+44h] [bp-550h]
  int v159; // [sp+48h] [bp-54Ch]
  volatile int *v160; // [sp+4Ch] [bp-548h]
  volatile uint16_t *v161; // [sp+50h] [bp-544h]
  volatile uint8_t *v162; // [sp+54h] [bp-540h]
  int v163; // [sp+58h] [bp-53Ch]
  int v164; // [sp+5Ch] [bp-538h]
  char _pad16[4]; volatile int *v165; // [sp+64h] [bp-530h]
  unsigned int v166; // [sp+68h] [bp-52Ch]
  int v167; // [sp+6Ch] [bp-528h]
  union { volatile int *v168; // [sp+70h] [bp-524h]
  uint64_t v169; }; // [sp+70h] [bp-524h]
  char _pad20[4]; int v171; // [sp+7Ch] [bp-518h]
  char _pad21[8]; volatile uint32_t *v173; // [sp+88h] [bp-50Ch]
  char _pad22[8]; uint16_t a3a[2]; // [sp+94h] [bp-500h] BYREF
  uint16_t v176; // [sp+98h] [bp-4FCh]
  char _pad24[2]; uint32_t v177[6]; // [sp+9Ch] [bp-4F8h] BYREF
  int result[48]; // [sp+B4h] [bp-4E0h] BYREF
  uint8_t v179[192]; // [sp+174h] [bp-420h] BYREF
  uint16_t v180[48]; // [sp+234h] [bp-360h] BYREF
  float v181; // [sp+294h] [bp-300h]
  char _pad29[4]; uint8_t v182; // [sp+29Ch] [bp-2F8h]
  char _pad30[3]; uint64_t v183; // [sp+2A0h] [bp-2F4h]
  int v184; // [sp+2A8h] [bp-2ECh]
  uint64_t v185; // [sp+2ACh] [bp-2E8h]
  int v186; // [sp+2B4h] [bp-2E0h]
  int v187; // [sp+2B8h] [bp-2DCh]
  float v188; // [sp+2BCh] [bp-2D8h]
  char _pad36[8]; int v189; // [sp+2C8h] [bp-2CCh]
  int v190; // [sp+2CCh] [bp-2C8h]
  int v191; // [sp+2D0h] [bp-2C4h]
  int v192; // [sp+2D4h] [bp-2C0h]
  char _pad40[12]; char v193; // [sp+2E4h] [bp-2B0h] BYREF
  char _pad41[35]; float v194; // [sp+308h] [bp-28Ch] BYREF
  uint16_t v195[2]; // [sp+30Ch] [bp-288h] BYREF
  uint16_t v196; // [sp+310h] [bp-284h]
  char _pad44[622]; int v197; // [sp+580h] [bp-14h]
  int v198; // [sp+584h] [bp-10h]
  char _pad46[112]; int v199; // [sp+5F8h] [bp+64h]
  int v200; // [sp+5FCh] [bp+68h]
  int a11; // [sp+600h] [bp+6Ch]
  } _frame;
  dispatch_event_handler_1(aMiscDpdCalibSi);
  v8 = dword_10B234;
  v9 = *(volatile uint32_t *)off_10B218;
  v10 = dword_10B23C;
  v11 = dword_10B250;
  *(volatile uint32_t *)off_10B218 &= ~1u;
  _frame.v171 = v9 & 1;
  v12 = (volatile int *)_frame.v179;
  gpio_set_pin(0);
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
    v45 = (volatile unsigned int *)(v44 + 4);
    v46 = &_frame.result[16 * i + 16];
    v47 = (volatile unsigned int *)(v44 + 516);
    do
    {
      v48 = *v45;
      *v45 = *v45 & 0xFFF1FFFF | 0x20000;
      v45 += 8;
      *v46++ = (v48 >> 17) & 7;
    }
    while ( v45 != v47 );
LABEL_5:
    v17 = (volatile unsigned int *)(v16 + 4);
    v18 = v12;
    v19 = (volatile unsigned int *)(v16 + 516);
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
  v21 = (volatile uint32_t *)off_10B21C;
  v22 = flt_10B220;
  gpio_clear_pin(0);
  check_interrupt_flag(1, aTrigger);
  *v21 |= 0x400u;
  *v21 &= ~0x400u;
  dispatch_event_handler_1(aDpdStart);
  check_interrupt_flag(1, aDpdCal);
  _frame.v161 = a5;
  _frame.v173 = v21;
  do
  {
    v23 = *((volatile uint8_t *)_frame.v161 + 4);
    if ( v23 != 1 )
      goto LABEL_10;
    v49 = *_frame.v161;
    check_interrupt_flag(1, "*********************dpd  freq= [%d] *********************\n", v49);
    if ( v49 <= 0x1388 )
    {
      v50 = (volatile int *)off_10B560;
      v51 = a2;
      _frame.v150 = 0;
      v52 = 0;
      _frame.v167 = 0;
      _frame.v146 = 0;
      v23 = 0;
      _frame.a4a = 0;
      _frame.v152 = _frame.v177;
      goto LABEL_29;
    }
    v141 = rf_check_freq(v49);
    v142 = dword_10BF24;
    v143 = 0;
    _frame.a4a = (uint8_t)(v141 + 1);
    v52 = _frame.a4a;
    v50 = (volatile int *)(off_10BF10 + 384 * v141);
    dispatch_event_handler_1(aCapacitanceCal);
    while ( 1 )
    {
      *(volatile uint32_t *)_frame.v195 = 0;
      _frame.v196 = 0;
      v144 = v142 | (v143 << 12);
      if ( v143 != 1 )
        break;
      _frame.v190 = 3;
      _frame.v195[0] = 2048;
      prcm_start(v144, (int)_frame.v180, _frame.v195, 0, 1, 1, 1, _frame.a4a);
LABEL_177:
      ++v143;
    }
    _frame.v190 = 3;
    _frame.v195[0] = 2048;
    prcm_start(v144, (int)_frame.v180, _frame.v195, 0, 1, v143, 1, _frame.a4a);
    if ( v143 != 2 )
      goto LABEL_177;
    _frame.v167 = 1;
    v51 = a2 + 1264 * _frame.a4a;
    _frame.v150 = 3 * _frame.a4a;
    _frame.v146 = 3 * _frame.a4a;
    _frame.v152 = &_frame.v177[_frame.a4a];
LABEL_29:
    v53 = (volatile int *)off_10B564;
    *_frame.v173 |= 0x400u;
    v54 = *v53;
    v55 = v53[1];
    v56 = v53[2];
    v57 = v53[3];
    v53 += 4;
    *_frame.v173 &= ~0x400u;
    _frame.v177[0] = v54;
    _frame.v177[1] = v55;
    _frame.v177[2] = v56;
    _frame.v177[3] = v57;
    v58 = v53[1];
    v59 = v51 + 16;
    _frame.v177[4] = *v53;
    _frame.v177[5] = v58;
    v60 = v51;
    v61 = v51 - 4;
    process_signal_buffer((volatile uint32_t *)a1, v60, v59, _frame.a4a, (int)_frame.v177, a6, a7, _frame.a8, _frame.v199, _frame.v200, _frame.a11);
    write_timer_reg(0);
    v64 = *(volatile uint32_t *)(v61 + 4);
    v63 = (volatile unsigned int *)(v61 + 4);
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
          check_interrupt_flag(1, a24gTable1DontN_0);
          *(volatile uint32_t *)off_10BF1C |= 0x8000u;
          goto LABEL_35;
        }
        v66 = 64;
        v67 = 32;
      }
      v68 = HIWORD(v62) & 1;
      *(volatile uint8_t *)(a3 + _frame.v146 + v65) = v68;
      check_interrupt_flag(1, "table [%d] dpd_ok=%d\n", v65, v68);
      phy_set_txpower(*v63, (int)_frame.v195, v23);
      check_interrupt_flag(1, "ana_pwr_max=%x\n", _frame.v197);
      check_interrupt_flag(1, "ana_pwr_min=%x\n", _frame.v198);
      if ( v68 && v67 < v66 )
      {
        v132 = &v50[v67 - 1];
        v135 = v132[1];
        v134 = (volatile unsigned int *)(v132 + 1);
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
          if ( _frame.v198 <= v136 && _frame.v197 >= v136 )
          {
            if ( v136 > 8 || *_frame.v152 || v65 != 1 )
            {
              *v134 = v133 & 0xFF3F7FFF | (v139 << 24);
            }
            else
            {
              *v134 = v133 | 0xC08000;
              _frame.v155 = v138;
              check_interrupt_flag(1, "table 1 index %d bypass\n", v136);
              v138 = _frame.v155;
            }
          }
          if ( (volatile unsigned int *)v137 == v134 )
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
        check_interrupt_flag(1, "table [%d] dont need change\n", v65);
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
    _frame.v166 = dword_10B540;
    dispatch_event_handler_1(aPwrCalStart);
    v70 = flt_10B550;
    _frame.v160 = (volatile int *)(dword_10B548 + 4 * v52);
    v71 = 0;
    _frame.v157 = 0;
    _frame.v162 = (volatile uint8_t *)(_frame.v150 + dword_10B54C);
    _frame.v149 = 0;
    _frame.v165 = v50 + 16;
    while ( 2 )
    {
      check_interrupt_flag(
        1,
        "/***************************************cal tx_gain_table=%d********************************/\n",
        _frame.v149);
      memset(_frame.result, 0, 0x40u);
      _frame.v194 = 1.0;
      _frame.v188 = v70;
      _frame.v187 = 8;
      _frame.v183 = 15;
      v72 = (volatile float *)&_frame.v193;
      do
        *v72++ = v70;
      while ( &_frame.v194 != v72 );
      if ( _frame.a4a )
      {
        _frame.v176 = 1792;
        _frame.a3a[1] = 2048;
        if ( _frame.v149 )
        {
          if ( _frame.v149 == 1 )
          {
            _frame.a3a[0] = 2048;
            v73 = 8;
            _frame.v190 = 4;
            _frame.v191 = 4;
            v74 = 12;
            _frame.v185 = 0x800000009LL;
            _frame.v186 = 12;
            _frame.v192 = 8;
            _frame.v163 = 4096;
          }
          else
          {
            v123 = (*(volatile uint8_t *)off_10BB8C & 0xC0) == 192;
            _frame.v190 = 6;
            _frame.v191 = 6;
            if ( v123 )
              v124 = 768;
            else
              v124 = 960;
            v74 = 12;
            _frame.v192 = 6;
            _frame.v185 = 0x900000009LL;
            _frame.a3a[0] = v124;
            _frame.v186 = 12;
            _frame.v163 = 0;
            v73 = 8;
          }
        }
        else
        {
          v74 = 14;
          _frame.v190 = 4;
          _frame.v191 = 4;
          v73 = 8;
          _frame.v185 = 0x90000000ELL;
          _frame.v186 = 14;
          _frame.a3a[0] = 896;
          _frame.v192 = 8;
          _frame.v163 = 0x2000;
        }
      }
      else
      {
        v73 = 8;
        _frame.v185 = 0x80000000BLL;
        v74 = 12;
        _frame.v186 = 12;
        if ( _frame.v149 )
        {
          *(volatile uint32_t *)_frame.a3a = dword_10B558;
          _frame.v176 = 1280;
          if ( _frame.v149 == 2 )
            *(volatile uint32_t *)_frame.a3a = 83887360;
          v73 = 7;
          v74 = 11;
          _frame.v185 = 0x90000000ALL;
          _frame.v186 = 11;
          _frame.v187 = 7;
          _frame.v190 = 2;
          _frame.v191 = 2;
          _frame.v192 = 4;
          _frame.v163 = 0;
        }
        else
        {
          _frame.v190 = 0;
          *(volatile uint32_t *)_frame.a3a = dword_10BF00;
          _frame.v176 = 2431;
          _frame.v192 = 8;
          _frame.v191 = 6;
          _frame.v163 = 4096;
        }
      }
      v75 = -100;
      v76 = _frame.v165 - 17;
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
      _frame.v154 = 255;
      _frame.v153 = 255;
      _frame.v156 = 255;
      _frame.v168 = v50;
      _frame.v158 = 0;
      _frame.v159 = 0;
      v80 = _frame.v165;
      v81 = _frame.v166;
      _frame.v151 = v75 + 1;
      v82 = v7;
      v83 = v70;
      v84 = 0;
      v85 = -16;
      _frame.v164 = v75;
      v86 = v75 + 1;
      v87 = v74;
      v88 = 15;
      while ( 1 )
      {
        if ( v85 >= 0 )
        {
          v89 = *(v80 - 32);
          _frame.v147 = v85;
          v90 = v80 - 32;
          v91 = (v89 >> 8) & 0xF;
        }
        else
        {
          v89 = *v80;
          _frame.v147 = v85 + 32;
          v90 = v80;
          v91 = ((unsigned int)*v80 >> 8) & 0xF;
        }
        if ( v91 > SHIDWORD(v88) )
          _frame.v183 = (_frame.v183 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v91) << 32);
        if ( v91 < (int)v88 )
          _frame.v183 = (_frame.v183 & ~0xFFFFFFFFull) | ((uint32_t)(v91) & 0xFFFFFFFFu);
        if ( v91 == v87 && !v84 )
        {
          if ( *_frame.v162 )
          {
            check_interrupt_flag(1, "dig_pwr_ini[%d][%d]=%x ", _frame.v149, v52, *_frame.v160);
          }
          else
          {
            *_frame.v160 = (uint8_t)v89;
            *_frame.v162 = 1;
            check_interrupt_flag(1, "ch[%d] table[%d] first_value=%x ", v52, _frame.v149, (uint8_t)v89);
          }
          v92 = *_frame.v160;
          v93 = aeabi_i2d(*_frame.v160);
          v94 = (v94 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
          v94 = (v94 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10B7CC) << 32);
          v95 = ((uint64_t (*)())aeabi_dsub)(v93, v94);
          v96 = ((int (*)(uint64_t))aeabi_dmul)(v95);
          v83 = COERCE_FLOAT(float_to_double(v96)) * 20.0;
          _frame.v156 = _frame.v147;
          v97 = COERCE_FLOAT(crc32_block(COERCE_INT((float)-v83 / 20.0)));
          v98 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)v92 * v97));
          v99 = parse_data_field(v98);
          v82 = ((int (*)(uint64_t))double_to_float_1)(v99);
          v81 = v82 | _frame.v163 | 0xFFC000;
          v84 = 1;
        }
        if ( (uint32_t)_frame.v185 == v91 && !_frame.v158 )
        {
          _frame.v153 = _frame.v147;
          _frame.v158 = 1;
        }
        if ( HIDWORD(_frame.v185) == v91 && !_frame.v159 )
        {
          _frame.v154 = _frame.v147;
          _frame.v159 = 1;
        }
        if ( v85 == v86 )
          *(volatile uint8_t *)off_10B55C = *v90;
        ++v85;
        ++v80;
        if ( v85 == 16 )
          break;
        v88 = _frame.v183;
        v87 = _frame.v186;
      }
      v50 = _frame.v168;
      _frame.v166 = v81;
      v7 = v82;
      check_interrupt_flag(1, aAnaMaxIndexXAn, HIDWORD(_frame.v183), (uint32_t)_frame.v183, _frame.v164, *(volatile uint8_t *)off_10B7D4);
      if ( _frame.v156 == 255 )
      {
        dispatch_event_handler_1(aWarningNeedCha);
        dispatch_event_handler_1("base_index=%d\n", 255);
        v7 = 100;
        v125 = _frame.v153;
        if ( _frame.v153 != 255 )
          goto LABEL_130;
LABEL_167:
        dispatch_event_handler_1("base_second_index=%d\n", v125);
        goto LABEL_130;
      }
      if ( _frame.v153 != 255 && _frame.v154 != 255 )
        goto LABEL_80;
      dispatch_event_handler_1(aWarningNeedCha);
      v125 = _frame.v153;
      if ( _frame.v153 == 255 )
        goto LABEL_167;
LABEL_130:
      if ( _frame.v154 == 255 )
        dispatch_event_handler_1("base_third_index=%d\n", 255);
LABEL_80:
      if ( _frame.v156 > 15 )
        _frame.v156 -= 32;
      if ( _frame.v153 > 15 )
        _frame.v153 -= 32;
      if ( _frame.v154 > 15 )
        _frame.v154 -= 32;
      check_interrupt_flag(
        1,
        "base_index=%d ana_index=%x dig_pwr=%x pwr_stage_coin_index0=%x base_second_index=%2d pwr_stage_coin_index1=%x ba"
        "se_third_index=%2d\n",
        _frame.v156,
        _frame.v186,
        v7,
        (uint32_t)_frame.v185,
        _frame.v153,
        HIDWORD(_frame.v185),
        _frame.v154);
      v100 = _frame.v187;
      if ( SHIDWORD(_frame.v183) >= _frame.v187 )
      {
        v101 = (volatile float *)&_frame.v180[2 * _frame.v187 + 74];
        do
        {
          v102 = (float)(_frame.v186 - v100) * _frame.v194;
          *v101++ = v102;
          check_interrupt_flag(1, "ana_index[%x] reduce_dig_i*100=%d \n", v100++, (int)(float)(v102 * v22));
        }
        while ( SHIDWORD(_frame.v183) >= v100 );
      }
      prcm_start(v81, (int)_frame.v180, _frame.a3a, 0, _frame.v167, _frame.v149, 0, v52);
      v103 = _frame.v185;
      v104 = (int16_t)_frame.v180[_frame.v186];
      v105 = (int16_t)_frame.v180[(uint32_t)_frame.v185 + 16];
      v106 = (int16_t)_frame.v180[HIDWORD(_frame.v185) + 32];
      if ( (int)_frame.v185 <= SHIDWORD(_frame.v183) )
      {
        v103 = (v103 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(&_frame.v180[_frame.v185 - 1]) << 32);
        v129 = (volatile float *)&_frame.result[_frame.v185];
        do
        {
          v130 = *(volatile uint16_t *)(HIDWORD(v103) + 2);
          v103 = (v103 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v103 >> 32) & 0xFFFFFFFFu) + (uint32_t)(2))) << 32;;
          min_u32(v130, v104, (int)_frame.v180);
          v131 = HIDWORD(_frame.v183);
          *v129++ = _frame.v181;
          v103 = (v103 & ~0xFFFFFFFFull) | ((uint32_t)(v103 + 1) & 0xFFFFFFFFu);
        }
        while ( v131 >= (int)v103 );
        v107 = (float)(_frame.v153 - _frame.v156) - *(volatile float *)&_frame.result[_frame.v185];
        check_interrupt_flag(1, "stage_pwr_diff0*100= %d\n", (int)(float)(v107 * v22));
        scale_f32(v107, v7, (int)_frame.v180);
        check_interrupt_flag(1, "base_index=%d dig_pwr=%x base_second_index=%d\n", _frame.v156, v7, _frame.v153);
        v103 = _frame.v185;
      }
      else
      {
        v107 = v70;
      }
      if ( SHIDWORD(v103) < (int)v103 )
      {
        v126 = &_frame.v180[HIDWORD(v103) + 16];
        v103 = (v103 & ~0xFFFFFFFFull) | ((uint32_t)(&_frame.result[HIDWORD(v103)]) & 0xFFFFFFFFu);
        do
        {
          v127 = *v126++;
          check_interrupt_flag(1, "pwr_amp_back[1][%d]=%d ", HIDWORD(v103), v127);
          min_u32(v127, v105, (int)_frame.v180);
          v128 = HIDWORD(_frame.v185);
          *(volatile float *)v103 = _frame.v181;
          v103 = (v103 & ~0xFFFFFFFFull) | ((uint32_t)(v103 + 4) & 0xFFFFFFFFu);
          v108 = (float)(_frame.v154 - _frame.v153) - *(volatile float *)&_frame.result[v128];
          v103 = (v103 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v103 >> 32) & 0xFFFFFFFFu) + (uint32_t)(1))) << 32;;
          check_interrupt_flag(1, "stage_pwr_diff1*100= %d\n", (int)(float)(v108 * v22));
        }
        while ( (int)_frame.v185 > SHIDWORD(v103) );
        v103 = (v103 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIDWORD(_frame.v185)) << 32);
      }
      else
      {
        v108 = v70;
      }
      v103 = (v103 & ~0xFFFFFFFFull) | ((uint32_t)(_frame.v187) & 0xFFFFFFFFu);
      if ( _frame.v187 < SHIDWORD(v103) )
      {
        v103 = (v103 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(&_frame.v180[_frame.v187 + 32]) << 32);
        v109 = (volatile float *)&_frame.result[_frame.v187];
        do
        {
          v110 = (int16_t)*(volatile uint16_t *)HIDWORD(v103);
          v103 = (v103 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v103 >> 32) & 0xFFFFFFFFu) + (uint32_t)(2))) << 32;;
          check_interrupt_flag(1, "pwr_amp_back[2][%d]=%d ", (uint32_t)v103, v110);
          min_u32(v110, v106, (int)_frame.v180);
          v111 = HIDWORD(_frame.v185);
          *v109++ = _frame.v181;
          v103 = (v103 & ~0xFFFFFFFFull) | ((uint32_t)(v103 + 1) & 0xFFFFFFFFu);
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
            v116 = _frame.v157 + 32;
          else
            v116 = _frame.v157;
          v117 = v116 + v113;
          v118 = ((unsigned int)v50[v116 + v113] >> 8) & 0xF;
          v119 = *(volatile float *)&_frame.result[v118];
          _frame.v184 = v118;
          v120 = (volatile unsigned int *)&v50[v116 + v113];
          if ( _frame.v164 < v113 )
          {
            if ( v118 > 9 )
              v114 = v70;
            else
              v114 = _frame.v188;
            if ( (int)_frame.v185 <= v118 )
            {
              v71 = v113 - _frame.v156;
              v121 = (float)((float)((float)((float)(v113 - _frame.v156) - v119) + v83) + v114) + *((volatile float *)&_frame.v189 + v118);
              check_interrupt_flag(1, "tx_gain_map_idx=%d base_index=%d ", v113, _frame.v156);
              check_interrupt_flag(
                1,
                "pwr_th*100=%-5d pwr_act*100=%-5d ",
                -100 * _frame.v156 + 100 * v113,
                (int)(float)(v119 * v22));
              scale_f32(v121, v7, (int)_frame.v180);
            }
            else
            {
              if ( SHIDWORD(_frame.v185) > v118 )
              {
                v71 = v113 - _frame.v154;
                v115 = (float)((float)((float)((float)((float)((float)(v113 - _frame.v154) - v119) + v108) + v107) + v83) + v114)
                     + *((volatile float *)&_frame.v189 + v118);
                check_interrupt_flag(1, "tx_gain_map_idx=%d base_third_index=%d ", v113, _frame.v154);
                check_interrupt_flag(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d stage_pwr_diff1*100=%-2d ",
                  -100 * _frame.v154 + 100 * v113,
                  (int)(float)(v119 * v22),
                  (int)(float)(v107 * v22),
                  (int)(float)(v108 * v22));
              }
              else
              {
                v71 = v113 - _frame.v153;
                v115 = (float)((float)((float)((float)((float)(v113 - _frame.v153) - v119) + v107) + v83) + v114)
                     + *((volatile float *)&_frame.v189 + v118);
                check_interrupt_flag(1, "tx_gain_map_idx=%d base_second_index=%d ", v113, _frame.v153);
                check_interrupt_flag(
                  1,
                  "pwr_th*100=%-5d pwr_act*100=%-5d stage_pwr_diff0*100=%-2d ",
                  -100 * _frame.v153 + 100 * v113,
                  (int)(float)(v119 * v22),
                  (int)(float)(v107 * v22));
              }
              scale_f32(v115, v7, (int)_frame.v180);
            }
            check_interrupt_flag(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, v118, _frame.v182);
            if ( v113 == _frame.v151 )
            {
              check_interrupt_flag(1, aMinDiffCal);
              min_u32(_frame.v182, *(volatile uint8_t *)off_10BB88, (int)_frame.v180);
              v112 = _frame.v181;
            }
          }
          else
          {
            check_interrupt_flag(1, "tx_gain_map_idx=%d ", v113);
            scale_f32(v112, LOBYTE(v50[v117]), (int)_frame.v180);
          }
          check_interrupt_flag(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, v118, _frame.v182);
          *(volatile uint8_t *)v120 = _frame.v182;
          if ( _frame.a4a || _frame.v149 || v118 != 15 )
            goto LABEL_108;
          check_interrupt_flag(1, aPwrReCal);
          prcm_start(*v120, (int)_frame.v180, _frame.a3a, 1, _frame.v167, 0, 0, 0);
          min_u32(_frame.v180[15], v104, (int)_frame.v180);
          v122 = _frame.v181;
          check_interrupt_flag(1, "pwr_th*100=%-5d pwr_act*100=%-5d ", 100 * v71, (int)(float)(_frame.v181 * v22));
          _frame.v169 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)v71 - v122));
if ( !((int (*)())double_gt)(_frame.v169, *(volatile uint64_t *)&dword_10BB50) && !((int (*)())double_lt)(_frame.v169, *(volatile uint64_t *)&dword_10BB58) ) { check_interrupt_flag(1, "pwr_diff*100=%d,dont need change\n", (int)(float)((float)((float)v71 - v122) * v22));
LABEL_108:
            if ( --v113 == -17 )
              goto LABEL_120;
            continue;
          }
          break;
        }
        scale_f32((float)v71 - v122, _frame.v182, (int)_frame.v180);
        --v113;
        check_interrupt_flag(1, "i=%2d ana_index=%x dig_pwr=%x \n", v117, 15, _frame.v182);
        *(volatile uint8_t *)v120 = _frame.v182;
        if ( v113 != -17 )
          continue;
        break;
      }
LABEL_120:
      _frame.v157 += 32;
      _frame.v160 += 7;
      _frame.v165 += 32;
      v123 = _frame.v149++ == 2;
      ++_frame.v162;
      if ( !v123 )
        continue;
      break;
    }
    dispatch_event_handler_1(aPwrCalEnd);
LABEL_10:
    _frame.v161 += 4;
  }
  while ( _frame.v161 != a5 + 28 );
  v24 = (volatile uint32_t *)off_10B21C;
  v25 = dword_10B234;
  v26 = dword_10B238;
  v27 = dword_10B23C;
  v28 = dword_10B250;
  *(volatile uint32_t *)off_10B21C |= 0x400u;
  *v24 &= ~0x400u;
  dispatch_event_handler_1(aDpdEnd);
  gpio_set_pin(0);
  v29 = dword_10B240;
  v30 = (volatile int *)_frame.v179;
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
    v40 = (volatile unsigned int *)(v39 + 4);
    v41 = &_frame.result[16 * k + 16];
    v42 = (volatile unsigned int *)(v39 + 484);
    do
    {
      v43 = *v41++;
      *v40 = *v40 & 0xFFF1FFFF | (v43 << 17);
      v40 += 8;
    }
    while ( v42 != v40 );
LABEL_15:
    v33 = (volatile unsigned int *)(v32 + 4);
    v34 = (volatile unsigned int *)(v32 + 484);
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
  gpio_clear_pin(0);
  v37 = (void *)(uintptr_t)(off_10B244);
  *(volatile uint32_t *)off_10B218 = *(volatile uint32_t *)off_10B218 & 0xFFFFFFFE | _frame.v171;
  check_interrupt_flag(1, "tia_aux_gbit000=%d\n", (*v37 >> 21) & 7);
  return dispatch_event_handler_1(aMiscDpdCalibSi_0);
}


// parse_packet_control @ 0x10bf28
volatile unsigned int * parse_packet_control(volatile unsigned int *result, int a2, int a3, int a4) {
  unsigned int v4; // r6
  int v7; // r7
  int v8; // r10
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r0
  uint64_t v13; // r8
  double v14; // d8
  uint64_t v15; // r0
  uint64_t v16; // r2
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r2
  uint64_t v20; // r0
  uint64_t v21; // r0
  uint64_t v22; // r2
  uint64_t v23; // r8
  uint64_t v24; // r0
  uint64_t v25; // r2
  uint64_t v26; // r0
  uint64_t v27; // r8
  int a5; // r6
  int v29; // r1
  int v30; // r2
  volatile int *v31; // r5
  int v32; // r0
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r0
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r0
  uint32_t v44[16]; // [sp+24h] [bp-40h] BYREF

  v4 = *result;
  v7 = (uint8_t)*result >> 6;
  if ( !a3 )
  {
    if ( !a4 )
      return result;
    goto LABEL_3;
  }
  v8 = result[1];
  check_interrupt_flag(0x2000, "cal_cfg:%x, alpha=%x\r\n", *result, v8);
  v9 = a2 - 2;
  do
  {
    *(volatile uint16_t *)(v9 + 2) = -32640;
    v9 += 2;
  }
  while ( a2 + 30 != v9 );
  *(volatile uint32_t *)(a2 + 32) = 0;
  *(volatile uint32_t *)(a2 + 36) = 0;
  v10 = a2 + 36;
  do
  {
    *(volatile uint32_t *)(v10 + 4) = 0;
    v10 += 4;
  }
  while ( a2 + 100 != v10 );
  while ( !*(volatile uint32_t *)off_10C17C )
    ;
  if ( v7 )
  {
    v11 = (*(volatile uint32_t *)off_10C180 >> 5) & 0x1F;
    if ( (*(volatile uint32_t *)off_10C180 & 0x400) != 0 )
      v11 *= 2;
    if ( (*(volatile uint32_t *)off_10C184 & 0x80000) != 0 && (*(volatile uint32_t *)off_10C184 & 0x40000) != 0 )
      v11 >>= 1;
    v12 = *(volatile uint8_t *)off_10C18C * v11;
    *(volatile uint32_t *)off_10C188 &= ~1u;
    if ( (uint8_t)v4 >> 7 )
    {
      v13 = *(volatile uint64_t *)&dword_10C168;
      v14 = dbl_10C160;
    }
    else
    {
      v13 = *(volatile uint64_t *)&dword_10C158;
      v14 = dbl_10C150;
    }
    v15 = aeabi_i2d(v12);
    v16 = (v16 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C190) << 32);
    v16 = (v16 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v17 = ((uint64_t (*)())aeabi_dadd)(v15, v16);
    v18 = ((uint64_t (*)())aeabi_dsub)(v13, v17);
    v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C194) << 32);
    v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v20 = ((uint64_t (*)())aeabi_dadd)(v18, v19);
    v21 = parse_data_field(v20);
    v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_10C190) << 32);
    v23 = v21;
    v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    v24 = ((uint64_t (*)())aeabi_dsub)(*(volatile uint64_t *)&v14, v22);
    v25 = parse_data_field(v24);
    v26 = v23;
    v27 = v25;
    *(volatile uint32_t *)off_10C1B0 = ((int (*)(uint64_t))aeabi_d2iz)(v26) & 0x7FFFFFFF;
    *(volatile uint32_t *)off_10C198 = dword_10C19C & (((int (*)(uint64_t))aeabi_d2iz)(v27) << 13) | *(volatile uint32_t *)off_10C198 & dword_10C1A0;
  }
  poll_rf_status();
  read_radio_status((uint8_t)v4, a2, v8, (uint16_t)v4 >> 12, BYTE1(v4) & 0xF, 0);
  result = (volatile unsigned int *)configure_bb_clock();
  *(volatile uint32_t *)off_10C17C = 1;
  if ( a4 )
  {
LABEL_3:
    if ( ((*(volatile uint32_t *)off_10C170 & 0x8000000) == 0 || (*(volatile uint32_t *)off_10C174 & 0x400) != 0) && !v7 )
    {
      a5 = off_10C1A8;
      v29 = ((volatile uint32_t *)(uintptr_t)off_10C1A4)[1];
      v30 = ((volatile uint32_t *)(uintptr_t)off_10C1A4)[2];
      v31 = (void *)(&((volatile uint32_t *)(uintptr_t)off_10C1A4)[18]);
      v44[0] = ((volatile uint32_t *)(uintptr_t)off_10C1A4)[0];
      v44[1] = v29;
      v44[2] = v30;
      poll_rf_status();
      v32 = *v31;
      v33 = v31[1];
      v34 = v31[2];
      v35 = v31[3];
      v31 += 4;
      v44[3] = v32;
      v44[4] = v33;
      v44[5] = v34;
      v44[6] = v35;
      v36 = *v31;
      v37 = v31[1];
      v38 = v31[2];
      v39 = v31[3];
      v31 += 4;
      v44[7] = v36;
      v44[8] = v37;
      v44[9] = v38;
      v44[10] = v39;
      v40 = v31[1];
      v41 = v31[2];
      v42 = v31[3];
      v44[11] = *v31;
      v44[12] = v40;
      v44[13] = v41;
      v44[14] = v42;
      *(volatile uint8_t *)(a5 + 4) = 0;
      v43 = off_10C1AC;
      *(volatile uint8_t *)(a5 + 0xC) = 0;
      *(volatile uint8_t *)(a5 + 0x14) = 0;
      *(volatile uint8_t *)(a5 + 0x1C) = 0;
      *(volatile uint8_t *)(a5 + 0x24) = 0;
      *(volatile uint8_t *)(a5 + 0x2C) = 0;
      *(volatile uint8_t *)(a5 + 0x34) = 0;
      configure_dma_regs(v43, (volatile uint8_t *)(a2 + 125), a5);
      apply_dsp_transform((int)v44, off_10C1AC, a2 + 104, a2 + 125, (volatile uint16_t *)a5, 6, 1);
      *(volatile uint8_t *)(a5 + 4) = 0;
      *(volatile uint8_t *)(a5 + 0xC) = 0;
      *(volatile uint8_t *)(a5 + 0x14) = 0;
      *(volatile uint8_t *)(a5 + 0x1C) = 0;
      *(volatile uint8_t *)(a5 + 0x24) = 0;
      *(volatile uint8_t *)(a5 + 0x2C) = 0;
      *(volatile uint8_t *)(a5 + 0x34) = 0;
      return (volatile unsigned int *)configure_bb_clock();
    }
  }
  return result;
}


// call_tx_function @ 0x10c1b4
int call_tx_function(int a1, int a2, int a3, int a4) {
  int v7; // r0

  rf_calibrate(a1, a2, a2, 0, 0, 0);
  parse_packet_control((volatile unsigned int *)a3, a4, 1, 0);
  if ( a1 == 1 )
    v7 = 132;
  else
    v7 = 129;
  return periph_wait_status(v7, (volatile uint16_t *)a4);
}


// call_rx_function @ 0x10c1ec
int call_rx_function(int a1, int a2, int a3, int a4, uint8_t a5, uint8_t a6) {
  int result; // r0
  volatile uint32_t *v10; // r10
  volatile uint32_t *v11; // r11

  rf_calibrate(a1, a2, a2, 0, 0, 0);
  if ( a1 == 1 )
  {
    v10 = (void *)(uintptr_t)(off_10C2DC);
    v11 = (void *)(uintptr_t)(off_10C2E0);
    *(volatile uint32_t *)off_10C2DC &= ~0x400u;
    *v11 |= 0x8000000u;
    dma_init(1);
    parse_packet_control((volatile unsigned int *)a3, a4, a5, a6);
    if ( a5 )
    {
      periph_wait_status(28, (volatile uint16_t *)a4);
      *v11 &= ~0x8000000u;
      *v10 |= 0x400u;
      dma_init(0);
      parse_packet_control((volatile unsigned int *)a3, a4, a5, a6);
      return periph_wait_status(28, (volatile uint16_t *)a4);
    }
    else
    {
      *v11 &= ~0x8000000u;
      *v10 |= 0x400u;
      dma_init(0);
      return (int)parse_packet_control((volatile unsigned int *)a3, a4, 0, a6);
    }
  }
  else
  {
    result = (int)parse_packet_control((volatile unsigned int *)a3, a4, a5, a6);
    if ( a5 )
      return periph_wait_status(3, (volatile uint16_t *)a4);
  }
  return result;
}


// configure_dma_engine @ 0x10c2e4
int configure_dma_engine() {
  volatile uint8_t *v0; // r0
  volatile int *v1; // r2
  volatile uint32_t *v2; // r3
  int v3; // r5
  volatile uint32_t *v4; // r4
  volatile int *v5; // r10
  int v6; // r1
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r1
  int v9; // r0
  volatile uint32_t *v10; // r3
  volatile uint32_t *v11; // r1
  volatile uint32_t *v12; // r4
  unsigned int v13; // r0
  int v14; // r1
  int v15; // r4
  int v16; // r3
  int v17; // r4
  volatile uint8_t *v18; // r8
  volatile uint32_t *v19; // r9
  volatile uint8_t *v20; // r7
  int v21; // r5
  int v22; // r0
  int v23; // r8
  volatile uint32_t *v24; // r9
  int v25; // r4
  int i; // r5
  int v27; // r0
  volatile uint8_t *v28; // r1
  int j; // r3
  int v30; // r2
  unsigned int v31; // r1
  unsigned int v32; // r0
  volatile uint32_t *v33; // r4
  volatile uint32_t *v34; // r3
  volatile uint32_t *v35; // r2
  volatile int *v36; // r3
  volatile int *v37; // r1
  volatile int *v38; // r2
  volatile uint8_t *v39; // r10
  int v40; // r5
  int v41; // r0
  volatile uint16_t *v42; // r7
  int v43; // r2
  int v44; // r0
  int result; // r0
  volatile uint32_t *v46; // r3
  volatile uint32_t *v47; // r1
  volatile int *v48; // r2
  int v49; // r1
  volatile int *v50; // r3
  volatile int *v51; // r1
  volatile int *v52; // r2
  int v53; // r3
  int v54; // r0
  volatile int *v55; // r5
  volatile uint8_t *v56; // r4
  unsigned int v57; // r0
  volatile uint8_t *v58; // r7
  unsigned int v59; // r3
  volatile int *v60; // r7
  int v61; // r0
  volatile uint8_t *v62; // r10
  volatile uint32_t *v63; // r3
  volatile uint32_t *v64; // r1
  volatile uint8_t *v65; // r3
  char v66; // r1
  char v67; // r2
  _UNKNOWN **v68; // r9
  int v69; // r7
  volatile uint32_t *v70; // r6
  int v71; // r9
  volatile uint8_t *v72; // r11
  volatile uint8_t *v73; // r8
  int v74; // r5
  char v75; // t1
  int v76; // r1
  int v77; // r5
  _UNKNOWN **v78; // r9
  int v79; // r11
  volatile uint8_t *v80; // r6
  volatile uint32_t *v81; // r4
  volatile int *v82; // r7
  volatile uint8_t *v83; // r9
  int v84; // r5
  char v85; // t1
  int v86; // r3
  struct __attribute__((packed)) { union { volatile uint8_t *v87; // [sp+8h] [bp-A4h]
  volatile int *v88; }; // [sp+8h] [bp-A4h]
  volatile uint8_t *v89; // [sp+Ch] [bp-A0h]
  char _pad2[2]; uint8_t a1[2]; // [sp+12h] [bp-9Ah] BYREF
  int v91; // [sp+14h] [bp-98h] BYREF
  int v92; // [sp+18h] [bp-94h] BYREF
  int v93; // [sp+1Ch] [bp-90h]
  int v94; // [sp+20h] [bp-8Ch]
  uint8_t v95[136]; // [sp+24h] [bp-88h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_10C3DC);
  *((volatile uint32_t *)off_10C3D8 + 64) = 8;
  if ( !v0[2] )
    *((volatile uint32_t *)off_10C3E0 + 2) = *((volatile uint32_t *)off_10C3E0 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (volatile int *)off_10C3E0;
  while ( (*((volatile uint32_t *)off_10C3E0 + 12) & 0x22) != 2 )
    ;
  v2 = (void *)(uintptr_t)(off_10C3E4);
  v3 = dword_10C3E8;
  v4 = (void *)(uintptr_t)(off_10C3D8);
  v5 = (void *)(uintptr_t)(off_10C3F8);
  *((volatile uint32_t *)off_10C3E0 + 2) = *((volatile uint32_t *)off_10C3E0 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v6 = *((volatile uint8_t *)v5 + 177);
  *v1 = *v1 & 0x37F | 0x80 | v3 & *v1;
  if ( v6 && (v1[12] & 0x40) == 0 && (v1[12] & 4) != 0 )
  {
    v52 = (volatile int *)off_10CA80;
    v53 = v5[42] | 0x2000000;
    *(volatile uint8_t *)off_10CA7C = 1;
    *v52 = v53;
    v4[14] |= 0x10u;
  }
  else
  {
    *(volatile uint32_t *)off_10C3EC = v5[42];
  }
  if ( v0[2] )
  {
    if ( **(volatile uint8_t **)off_10C3F0 == 2 )
    {
      v63 = (void *)(uintptr_t)(off_10CAA4);
      v64 = (void *)(uintptr_t)(off_10CAA8);
      *((volatile uint32_t *)off_10CAA4 + 20) |= 0x40000u;
      v64[7] &= ~0x100u;
      v63[9] = v63[9] & 0xFFFFFF00 | 0x60;
      v63[9] = v63[9] & 0xFFFF00FF | 0xDF00;
LABEL_11:
      panic_fatal();
      if ( !*(volatile uint32_t *)off_10C3F4 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v7 = (void *)(uintptr_t)(off_10C3E0);
    **(volatile uint8_t **)off_10C3F0 = 2;
    v8 = (void *)(uintptr_t)(off_10C3D8);
    v9 = (uint8_t)v0[2];
    v7[20] |= 0x40000u;
    v8[7] &= ~0x100u;
    v7[9] = v7[9] & 0xFFFFFF00 | 0x60;
    v7[9] = v7[9] & 0xFFFF00FF | 0xDF00;
    if ( v9 )
      goto LABEL_11;
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_10C71C);
    v11 = (void *)(uintptr_t)(off_10C720);
    *((volatile uint32_t *)off_10C71C + 20) |= 0x40000u;
    v11[7] &= ~0x100u;
    v10[9] = v10[9] & 0xFFFFFF00 | 0x60;
    v10[9] = v10[9] & 0xFFFF00FF | 0xDF00;
  }
  rf_phy_init();
  if ( *(volatile uint32_t *)off_10C724 )
  {
LABEL_12:
    chip_common_write();
    periph_cmd_poll();
    periph_cmd_write();
  }
LABEL_15:
  v12 = (void *)(uintptr_t)(off_10C720);
  check_chip_flag();
  v12[4] |= 2u;
  save_rf_context();
  _frame.a1[0] = 0;
  _frame.a1[1] = 0;
  if ( (*v12 & 0x2000000) == 0 )
  {
    *(volatile uint32_t *)_frame.v95 = 0;
    if ( bus_read32((int)_frame.v95) )
    {
      v13 = _frame.a1[0];
    }
    else
    {
      v13 = _frame.v95[0];
      _frame.a1[0] = _frame.v95[0];
      _frame.a1[1] = _frame.v95[1];
    }
    if ( v13 )
      goto LABEL_19;
LABEL_60:
    set_xtal_ftune(15);
    goto LABEL_22;
  }
  mmio_read_status(_frame.a1);
  mmio_read_byte(&_frame.a1[1]);
  v13 = _frame.a1[0];
  if ( !_frame.a1[0] )
    goto LABEL_60;
LABEL_19:
  if ( v13 > 0x1F )
  {
    v13 = 31;
    _frame.a1[0] = 31;
  }
  set_xtal_ftune(v13);
  log_printf("set xtal_cap 0x%x\n", _frame.a1[0]);
LABEL_22:
  v14 = _frame.a1[1];
  if ( _frame.a1[1] )
  {
    if ( _frame.a1[1] <= 0x3Fu )
    {
      v15 = (_frame.a1[1] << 18) & 0xFC0000;
    }
    else
    {
      v14 = 63;
      _frame.a1[1] = 63;
      v15 = 16515072;
    }
    *(volatile uint32_t *)off_10C72C = *(volatile uint32_t *)off_10C72C & 0xFF03FFFF | v15;
    log_printf("set xtal_cap_fine 0x%x\n", v14);
  }
  v16 = *(volatile uint8_t *)off_10C734;
  if ( (v16 == 7 || v16 == 193) && !rf_get_reg1_bits13_16() )
  {
    v57 = mmio_rmw_field(3);
    if ( v57 != 3 )
      log_printf("sdio_cfg error: %x\n", v57);
  }
  v17 = HIBYTE(*(volatile uint32_t *)off_10C720) & 2;
  if ( v17 )
  {
    v18 = (volatile uint8_t *)dword_10C790;
    v19 = (void *)(uintptr_t)(off_10C794);
    v20 = (void *)(uintptr_t)(off_10C738);
    v21 = 0;
    do
    {
      v22 = tx_desc_init(v21, *v19 + 3 * v21);
      ++v21;
      if ( v22 != 546 )
        v20[1] |= 1u;
      *v18 = v22 & 0xF;
      v18[1] = (uint8_t)v22 >> 4;
      v18[2] = BYTE1(v22) & 0xF;
      v18 += 3;
    }
    while ( v21 != 3 );
    v23 = dword_10C798;
    v24 = (void *)(uintptr_t)(off_10C79C);
    v25 = dword_10C73C;
    for ( i = 0; i != 3; ++i )
    {
      v27 = rx_desc_init(i, *v24 + 6 * i);
      if ( v27 != v25 )
        v20[1] |= 1u;
      v28 = (volatile uint8_t *)v23;
      for ( j = 0; j != 24; j += 4 )
      {
        v30 = v27 >> j;
        *v28++ = v30 & 0xF;
      }
      v23 += 6;
    }
    v31 = 31 - __clz(rf_get_reg0x1b());
    *v20 = v31;
  }
  else
  {
    _frame.v93 = 0;
    _frame.v94 = 0;
    _frame.v92 = 0;
    if ( bus_read_12((int)&_frame.v92) )
    {
      v58 = (void *)(uintptr_t)(off_10CA90);
    }
    else
    {
      v77 = dword_10CBCC;
      v78 = (void *)(uintptr_t)(off_10CBDC);
      log_printf(aFlTxpwrOfst24g);
      v79 = 0;
      _frame.v88 = &_frame.v92;
      v80 = (volatile uint8_t *)v77;
      v81 = (void *)(v78);
      do
      {
        log_printf("\r\n  [%d] =", v79);
        v82 = _frame.v88;
        v83 = v80;
        v84 = 0;
        do
        {
          v85 = *(volatile uint8_t *)v82;
          v82 = (volatile int *)((volatile char *)v82 + 1);
          *(volatile uint8_t *)(*v81 + v84 + 3 * v79) = v85;
          v86 = *v81 + v84++;
          log_printf(" %d", *(volatile char *)(v86 + 3 * v79));
          *v83++ = 15;
        }
        while ( v84 != 3 );
        ++v79;
        _frame.v88 = (volatile int *)((volatile char *)_frame.v88 + 3);
        v80 += 3;
      }
      while ( v79 != 3 );
      v58 = (void *)(uintptr_t)(off_10CBD4);
      v17 = 0;
      log_printf((const volatile char *)off_10CBC8);
      v58[1] |= 1u;
    }
    memset(_frame.v95, 0, 20);
    if ( !mmio_read_4((int)_frame.v95) )
    {
      v68 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_10CBD8)[0]);
      log_printf(aFlTxpwrOfst5g);
      _frame.v89 = v58;
      v69 = dword_10CBBC;
      _frame.v87 = _frame.v95;
      v70 = (void *)(v68);
      v71 = 0;
      do
      {
        log_printf("\r\n  [%d] =", v71);
        v72 = _frame.v87;
        v73 = (volatile uint8_t *)v69;
        v74 = 0;
        do
        {
          v75 = *v72++;
          *(volatile uint8_t *)(*v70 + v17 + v74) = v75;
          v76 = *(volatile char *)(*v70 + v17 + v74++);
          log_printf(" %d", v76);
          *v73++ = 15;
        }
        while ( v74 != 6 );
        v17 += 6;
        ++v71;
        _frame.v87 += 6;
        v69 += 6;
      }
      while ( v17 != 18 );
      v58 = _frame.v89;
      log_printf((const volatile char *)off_10CBC8);
      _frame.v89[1] |= 1u;
    }
    if ( mmio_read_128((int)&_frame.v91) )
    {
      v31 = -1;
      *v58 = -1;
    }
    else
    {
      v59 = (char)_frame.v91;
      *v58 = _frame.v91;
      v31 = v59;
    }
  }
  log_printf("cal_ver=%d\n", v31);
  if ( *((volatile uint8_t *)v5 + 372) )
  {
    if ( (*(volatile uint32_t *)off_10C720 & 0x2000000) != 0 )
    {
      if ( rf_get_reg0xf_bit18() )
      {
        v54 = rf_get_reg0x11_bits0_2();
        v55 = (volatile int *)off_10CA84;
        v56 = (void *)(uintptr_t)(off_10CA88);
        *(volatile uint8_t *)off_10CA88 = *((volatile uint8_t *)off_10CA84 + v54);
        v56[1] = *((volatile uint8_t *)v55 + rf_get_reg0x11_bits3_5());
        v56[2] = *((volatile uint8_t *)v55 + rf_get_reg0x11_bits6_8());
      }
    }
    else
    {
      *(volatile uint32_t *)_frame.v95 = 0;
      if ( !mmio_read_32((int)_frame.v95) )
      {
        v65 = (void *)(uintptr_t)(off_10CA88);
        v66 = *((volatile uint8_t *)off_10CA84 + _frame.v95[1]);
        v67 = *((volatile uint8_t *)off_10CA84 + _frame.v95[2]);
        *(volatile uint8_t *)off_10CA88 = *((volatile uint8_t *)off_10CA84 + _frame.v95[0]);
        v65[1] = v66;
        v65[2] = v67;
      }
    }
  }
  v32 = rf_get_reg0xf_bit19();
  v33 = (void *)(uintptr_t)(off_10C744);
  if ( v32 )
    *(volatile uint32_t *)off_10C744 |= 1u;
  if ( rf_get_reg0xf_bit20() )
    *v33 |= 2u;
  *(volatile uint32_t *)off_10C748 &= 0xFFFFFFC7;
  if ( (*(volatile uint8_t *)off_10C734 & 0xC0) == 0xC0 )
  {
    v34 = (void *)(uintptr_t)(off_10C750);
    *(volatile uint32_t *)(uintptr_t)(off_10C74C) = off_10C754;
    v35 = (volatile uint32_t *)off_10C758;
    *v34 = off_10C75C;
    v36 = (volatile int *)off_10C760;
    v37 = (void *)(uintptr_t)(off_10C764);
    *v35 = off_10C760;
    v38 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_10C768)[0];
    *v37 = (int)v36;
    *v38 = (int)off_10C76C;
  }
  memcpy_advance(0, 0, 0x10u, off_10C770);
  memcpy_advance(0, 16, 0x10u, off_10C774);
  if ( (*v33 & 2) == 0 )
  {
    v60 = (volatile int *)off_10CA94;
    memcpy_advance(0, 32, 0x10u, (int)((volatile uint32_t *)(uintptr_t)off_10CA94)[2]);
    memcpy_advance(0, 48, 0x10u, v60[1]);
    memcpy_advance(0, 64, 0x10u, *v60);
    memcpy_advance(1, 0, 0x10u, *(volatile uint32_t *)off_10CA98);
    memcpy_advance(1, 16, 0x10u, *(volatile uint32_t *)off_10CA9C);
  }
  rf_cal_read_1();
  rf_init_regs(1);
  rf_cal_read_0(0);
  rf_init_regs(0);
  if ( (*(volatile uint8_t *)off_10C734 & 0xC0) != 0xC0 && (v5[98] & 4) != 0 )
  {
    v48 = (volatile int *)off_10CA70;
    v49 = dword_10CA74;
    ((volatile uint32_t *)(uintptr_t)off_10CA70)[13] = dword_10CA74;
    v49 += 36;
    v48[14] = v49;
    v49 -= 37;
    v48[109] = v49;
    v49 += 27;
    v48[110] = v49;
    v49 -= 25;
    v48[204] = v49;
    v49 += 17;
    v48[205] = v49;
    v49 += 16;
    v48[206] = v49;
    v49 += 25;
    v48[15] = v49;
    v48[111] = v49;
    v48[207] = v49;
    v48[303] = v49;
    v48[399] = v49;
    v48[495] = v49;
    v49 -= 48;
    v50 = (volatile int *)off_10CA78;
    v48[300] = v49;
    v48[396] = v49;
    v48[492] = v49;
    v49 += 16;
    v48[301] = v49;
    v48[397] = v49;
    v48[493] = v49;
    v49 += 16;
    v48[302] = v49;
    v48[398] = v49;
    v48[494] = v49;
    v51 = v50 + 1896;
    do
    {
      v50[318] |= 0x8000u;
      v50 += 316;
    }
    while ( v51 != v50 );
  }
  v39 = (void *)(uintptr_t)(off_10C7A0);
  v40 = dword_10C77C;
  *(volatile uint32_t *)off_10C778 |= 0x8000000u;
  _frame.v92 = 3983;
  _frame.v93 = v40;
  *v39 = 2;
  call_tx_function(0, 2437, (int)&_frame.v92, (int)_frame.v95);
  *v39 = 0;
  clock_set_source(0, 0, 0);
  call_rx_function(0, 2437, (int)&_frame.v92, (int)_frame.v95, 1u, 0);
  if ( (*v33 & 2) == 0 )
  {
    v62 = (void *)(uintptr_t)(off_10CAAC);
    _frame.v92 = 3855;
    *(volatile uint8_t *)off_10CAAC = 2;
    call_tx_function(1, 5250, (int)&_frame.v92, (int)_frame.v95);
    call_tx_function(1, 5500, (int)&_frame.v92, (int)_frame.v95);
    call_tx_function(1, 5700, (int)&_frame.v92, (int)_frame.v95);
    *v62 = 0;
    clock_set_source(1, 0, 0);
    call_rx_function(1, 5700, (int)&_frame.v92, (int)_frame.v95, 1u, 0);
    call_rx_function(1, 5250, (int)&_frame.v92, (int)_frame.v95, 1u, 0);
    call_rx_function(1, 5500, (int)&_frame.v92, (int)_frame.v95, 1u, 0);
  }
  v41 = mac_packet_dispatch();
  v42 = (void *)(uintptr_t)(off_10C784);
  v43 = ((int)(((uint64_t)((int32_t)dword_10C780 * (int64_t)(int32_t)(4 * (v41 - 35))) >> 32) + 4 * (v41 - 35)) >> 2)
      - ((4 * (v41 - 35)) >> 31)
      + 120;
  *(volatile uint16_t *)off_10C7A4 = v43;
  *v42 = v43;
  dispatch_event_handler_1("Init T=%d C, ipa_target=%d\n", v41, v43);
  if ( (*v33 & 2) == 0 )
  {
    v61 = gpio_bank_init((int)&_frame.v91);
    log_printf("cal_ipa_5g offset=%d, cgm=%d\n", v61, _frame.v91);
  }
  v44 = gpio_bank_init2();
  log_printf("cal_ipa_24g offset=%d\n", v44);
  call_rx_function(1, 5500, (int)&_frame.v92, (int)_frame.v95, 0, 1u);
  result = rf_calibrate(0, 2437, 0x985u, 0, 0, 0);
  v46 = (void *)(uintptr_t)(off_10CA68);
  v47 = (void *)(uintptr_t)(off_10CA6C);
  *(volatile uint32_t *)off_10CA68 |= 0x20000u;
  *v46 |= 0x10000u;
  *v47 |= 1u;
  return result;
}


// config_uart_control @ 0x10cbe0
volatile int *config_uart_control() {
  volatile unsigned int *v0; // r3
  volatile unsigned int *v1; // r2
  volatile int *result; // r0
  int v3; // r4

  v0 = (volatile unsigned int *)off_10CC88;
  v1 = (volatile unsigned int *)off_10CC8C;
  result = (volatile int *)off_10CC90;
  *(volatile uint32_t *)off_10CC88 = *(volatile uint32_t *)off_10CC88 & 0xFFFFFFFC | 2;
  v3 = dword_10CC94;
  *v0 = *v0 & 0xFFFFFFF3 | 8;
  *v0 = *v0 & 0xFFFFFCFF | 0x200;
  *v0 = *v0 & 0xFFFFF3FF | 0x800;
  *v0 = *v0 & 0xFFFFCFFF | 0x2000;
  *v1 = *v1 & 0xFCFFFFFF | 0x2000000;
  *v1 = *v1 & 0xF3FFFFFF | 0x8000000;
  *v1 = *v1 & 0xCFFFFFFF | 0x20000000;
  *v1 = *v1 & 0x3FFFFFFF | 0x80000000;
  *v0 |= 0x30000u;
  *v0 |= 0xC0000u;
  *v0 |= 0x300000u;
  *v0 |= 0xC00000u;
  *v0 |= 0x3000000u;
  *result = v3;
  return result;
}



// clear_buffer_180a0c @ 0x10cc98
volatile int *clear_buffer_180a0c() {
  int v0; // r4
  int v1; // zf
  uint8_t v2; // r1
  volatile int **v3; // r4

  v0 = *((volatile uint32_t *)off_10CD0C + 23);
  memset((volatile int *)dword_10CD10, 0, 0x28u);
  memset((volatile int *)dword_10CD14, 0, 0x17C4u);
  if ( (*(volatile uint32_t *)off_10CD18 & 8) != 0 )
  {
    while ( (*(volatile uint32_t *)off_10CD18 & 0x10) == 0 )
      ;
    v3 = (volatile int **)off_10CD1C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (volatile int **)off_10CD1C;
    *(volatile uint32_t *)off_10CD18 |= 8u;
    if ( v1 )
      memset(*v3, v2, 0x258u);
    *(volatile uint32_t *)off_10CD18 |= 0x10u;
  }
  (*v3)[149] = *(volatile uint32_t *)off_10CD20;
  return config_uart_control();
}



// wait_for_uart_event @ 0x10cd24
int wait_for_uart_event() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r2
  volatile uint8_t *v3; // r3
  volatile uint32_t *v4; // r2

  v0 = *(volatile uint32_t *)off_10CD58 & 0xF00;
  if ( v0 )
  {
    result = set_busy_flag_alt(0x10000);
    v2 = (volatile int *)off_10CD5C;
    v3 = (void *)(uintptr_t)(off_10CD64);
    *(volatile uint32_t *)off_10CD60 = v0;
    *v2 = v0;
    if ( *v3 )
    {
      v4 = (void *)(uintptr_t)(off_10CD68);
      v3[1] = 1;
      *v4 |= 1u;
    }
  }
  return result;
}



// handle_interrupt_save @ 0x10cd6c
int handle_interrupt_save(char a1) {
  int v1; // r5
  volatile uint8_t *v2; // r11
  int v3; // r8
  volatile int *v4; // r7
  volatile uint32_t *v5; // r10
  unsigned int v6; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  volatile int *v9; // r9
  volatile uint32_t *v10; // r0
  int v11; // r1
  volatile uint32_t *v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  volatile uint8_t *v16; // r1
  int result; // r0

  enter_critical_section_1(0x10000);
  v1 = *(volatile uint32_t *)off_10CE58;
  if ( *(volatile uint32_t *)(*(volatile uint32_t *)off_10CE58 + 588) )
  {
    v2 = (volatile uint8_t *)off_10CE70;
    v3 = dword_10CE74;
    v4 = (volatile int *)off_10CE5C;
    v5 = (void *)(uintptr_t)(off_10CE78);
    while ( 1 )
    {
      v6 = v2[1621];
      v7 = v2[1622];
      if ( v6 >= v7 )
        break;
      v8 = v2[1620]
         + 1
         - 81 * ((unsigned int)(((unsigned int)v3 * (uint64_t)((unsigned int)v2[1620] + 1)) >> 32) >> 6);
      v2[1621] = v6 + 1;
      v2[1620] = v8;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v9 = (volatile int *)off_10CE7C;
      ++*(volatile uint32_t *)off_10CE7C;
      while ( !*v5 )
        ;
      v10 = list_pop_front(v1 + 588);
      v11 = *v9;
      *v5 = 1;
      v12 = v10;
      if ( v11 )
      {
        v13 = v11 - 1;
        v14 = *v4;
        *v9 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      v15 = dword_10CE64;
      v16 = &v2[20 * v8];
      *((volatile uint32_t *)v16 + 1) = (int)(uintptr_t)((volatile char *)v12 + *(volatile uint32_t *)(uintptr_t)(off_10CE60));
      check_kernel_state(v15, (void *)(v16));
      if ( !*(volatile uint32_t *)(v1 + 588) )
        goto LABEL_13;
    }
    log_printf("rxused=%d, total=%d\r\n", v6, v7);
  }
LABEL_13:
  result = set_busy_flag_alt(2048);
  *(volatile uint32_t *)off_10CE68 = (1 << (a1 + 8)) & 0xF00;
  return result;
}


// check_uart_flags @ 0x10ce80
int check_uart_flags() {
  int v0; // r4
  volatile uint32_t *v1; // r2
  int result; // r0

  v0 = *(volatile uint32_t *)off_10CEB4;
  if ( (*(volatile uint32_t *)off_10CEB4 & 0x20) != 0 )
  {
    v1 = (void *)(uintptr_t)(off_10CEBC);
    *(volatile uint32_t *)off_10CEB8 = 32;
    *v1 = 32;
    result = set_busy_flag_alt(0x400000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = set_busy_flag_alt(0x8000000);
    *(volatile uint32_t *)off_10CEB8 = 2;
  }
  return result;
}



// lookup_mac_descriptor @ 0x10cec0
int lookup_mac_descriptor() {
  int v0; // r3
  int result; // r0

  v0 = *(volatile uint32_t *)off_10CEE8 + 4 * (*((volatile uint8_t *)off_10CEE4 + 16) + 136);
  *(volatile uint32_t *)off_10CEEC = 32;
  result = *(volatile uint32_t *)(v0 + 4);
  if ( result )
    return 1;
  *(volatile uint32_t *)off_10CEF0 = 32;
  return result;
}



// poll_hw_status @ 0x10cef4
int poll_hw_status() {
  volatile uint32_t *v0; // r4
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10CF20);
  while ( !*(volatile uint32_t *)off_10CF20 )
    ;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_10CF24 + 532);
  if ( result )
  {
    result = (int)(uintptr_t)(list_pop_front(*(volatile uint32_t *)off_10CF24 + 532));
    *v0 = 1;
    if ( result )
      result += 4;
  }
  else
  {
    *(volatile uint32_t *)off_10CF20 = 1;
  }
  return result;
}



// nullsub_6 @ 0x10cf28
int nullsub_6(void) {
  return 0;
}


// enable_uart @ 0x10cf2c
void enable_uart() {
  *(volatile uint32_t *)off_10CF38 = 256;
}



// rf_enable @ 0x10cf3c
void rf_enable() {
  *(volatile uint32_t *)off_10CF44 = 128;
}



// bt_event_process @ 0x10cf48
int bt_event_process(volatile uint16_t *a1) {
  volatile int16_t **v2; // r7
  int v3; // r0
  volatile int16_t *v4; // r6
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r7
  volatile int *v8; // r3
  volatile int *v9; // r2
  int v10; // r1
  int v11; // t1
  volatile uint32_t *v12; // r1
  int16_t v13; // r3

  v2 = (volatile int16_t **)off_10D008;
  v3 = align_size_plus4((uint16_t)a1[5] + 16);
  v4 = *v2;
  v5 = v3;
  if ( **v2 < 0 && !v3 )
  {
    flash_ctrl_init(dword_10D020, dword_10D018, 1358);
    v4 = *v2;
  }
  v6 = (uint16_t)a1[5];
  v7 = (uint16_t)a1[3];
  *(volatile uint16_t *)(v5 + 4) = a1[2];
  *(volatile uint16_t *)(v5 + 8) = 4;
  *(volatile uint16_t *)(v5 + 10) = v6;
  *(volatile uint16_t *)(v5 + 6) = v7;
  *(volatile uint32_t *)v5 = 0;
  v8 = (volatile int *)(a1 + 6);
  if ( v6 )
  {
    v9 = (volatile int *)((volatile char *)a1 + ((v6 - 1) & 0xFFFFFFFC) + 16);
    v10 = v5 + 8;
    do
    {
      v11 = *v8++;
      *(volatile uint32_t *)(v10 + 4) = v11;
      v10 += 4;
    }
    while ( v8 != v9 );
  }
  if ( *v4 < 0 )
  {
    if ( v7 > 5 )
    {
      flash_ctrl_init(dword_10D028, dword_10D024, 183);
      flash_ctrl_init(dword_10D01C, dword_10D018, 1375);
    }
    else if ( v7 > 3 )
    {
      flash_ctrl_init(dword_10D01C, dword_10D018, 1375);
    }
  }
  if ( **(volatile uint8_t **)off_10D00C == 3 )
  {
    v12 = (void *)(uintptr_t)(off_10D014);
    v13 = *((volatile uint8_t *)off_10D010 + 20);
    *((volatile uint8_t *)off_10D010 + 20) = v13 + 1;
    a1[4] = v13;
    *v12 = 4;
  }
  return (int)(uintptr_t)(rx_irq_handler_1(v5 + 12));
}



// rf_irq_handler @ 0x10d02c
int rf_irq_handler() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r7
  volatile uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_10D05C);
  if ( (*(volatile uint32_t *)off_10D05C & 2) != 0 )
  {
    v1 = (volatile int *)off_10D060;
    v2 = (void *)(uintptr_t)(off_10D064);
    do
    {
      v3 = *v1;
      *v2 = 2;
      bt_event_process((volatile uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = enter_critical_section_1(0x8000000);
  *(volatile uint32_t *)off_10D068 = 2;
  return result;
}



// mac_ll_scheduler @ 0x10d06c
volatile uint32_t * mac_ll_scheduler(int a1) {
  volatile uint8_t **v1; // r7
  volatile uint8_t *v2; // r2
  int v3; // r3
  int v5; // r8
  int v6; // r6
  volatile uint32_t *v7; // r5
  volatile uint32_t *v8; // r9
  unsigned int v9; // r2
  int v10; // r3
  volatile uint32_t *v11; // r6
  volatile uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  uint16_t v15; // lr
  volatile uint8_t *v16; // r6
  unsigned int v17; // r2
  uint16_t v18; // r12
  int v19; // r8
  volatile int *v20; // r3
  int v21; // r10
  int v22; // r3
  int v23; // r0
  char v24; // r2
  volatile int *v25; // r6
  int v26; // r0
  int v27; // r3
  int v28; // r2
  volatile uint32_t *v29; // r0
  uint16_t v30; // r2
  uint16_t v32; // r1
  uint16_t v33; // r2
  volatile uint8_t *v34; // r3
  volatile int *v35; // r6
  int v36; // r0
  int v37; // r3
  int v38; // r2
  volatile uint32_t *v39; // r5
  volatile uint32_t *v40; // r0
  int v41; // r3
  int v42; // r3
  volatile int *v43; // r5
  int v44; // r0
  int v45; // r2
  int v46; // r1
  int v47; // r0
  int v48; // [sp+0h] [bp-8h]
  int v49; // [sp+4h] [bp-4h]

  v1 = (volatile uint8_t **)off_10D338;
  v2 = *(volatile uint8_t **)off_10D338;
  v3 = **(volatile uint8_t **)off_10D338;
  if ( v3 != 3 )
  {
    v5 = 0;
    v6 = 0;
    goto LABEL_3;
  }
  v39 = (void *)(uintptr_t)(off_10D340);
  while ( !*(volatile uint32_t *)off_10D340 )
    ;
  if ( !*(volatile uint32_t *)(*(volatile uint32_t *)off_10D344 + 516) )
  {
    v42 = **(volatile int16_t **)off_10D33C;
    *(volatile uint32_t *)off_10D340 = 1;
    if ( v42 >= 0 )
    {
      v6 = 4;
      v5 = 4;
      goto LABEL_50;
    }
    goto LABEL_71;
  }
  v40 = list_pop_front(*(volatile uint32_t *)off_10D344 + 516);
  v41 = **(volatile int16_t **)off_10D33C;
  *v39 = 1;
  if ( v41 < 0 )
  {
    if ( v40 )
    {
      v5 = (int)(v40 + 1);
      if ( v40 == (volatile uint32_t *)-4 )
      {
        flash_ctrl_init((int)aHostMsgBuf0, (int)aIpcEmbKmsgFwd, 1567);
        v6 = v5;
        v2 = *v1;
        goto LABEL_50;
      }
      goto LABEL_49;
    }
LABEL_71:
    v6 = 4;
    flash_ctrl_init((int)aHostmsgbuf0, (int)aIpcEmbHostmsgb, 973);
    v5 = 4;
    v2 = *v1;
    goto LABEL_50;
  }
  v5 = (int)(v40 + 1);
LABEL_49:
  v2 = *v1;
  v6 = v5;
LABEL_50:
  *(volatile uint32_t *)(v6 + 8) = dword_10D364;
  v3 = *v2;
LABEL_3:
  if ( v3 == 1 )
  {
    if ( *(volatile uint16_t *)(a1 + 10) <= 0x6Cu )
      v7 = (void *)(uintptr_t)(irq_disable_set_flag_2());
    else
      v7 = (volatile uint32_t *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10D360 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10D360 + 4));
    if ( !v7 )
      goto LABEL_59;
    v32 = *(volatile uint16_t *)(a1 + 6);
    v33 = *(volatile uint16_t *)(a1 + 8);
    v7[3] = dword_10D364;
    v34 = *v1;
    *((volatile uint16_t *)v7 + 3) = v32;
    *((volatile uint16_t *)v7 + 4) = v33;
    v6 = (int)(v7 + 1);
    if ( *v34 != 2 )
      goto LABEL_5;
  }
  else
  {
    v7 = nullptr;
    if ( v3 != 2 )
    {
LABEL_5:
      v8 = nullptr;
      goto LABEL_6;
    }
  }
  if ( *(volatile uint16_t *)(a1 + 10) <= 0x6Cu )
    v7 = (void *)(uintptr_t)(disable_interrupts());
  else
    v7 = (volatile uint32_t *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10D360 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10D360 + 4));
  if ( !v7 )
  {
LABEL_59:
    log_printf(
      "ipc_emb_kmsg_fwd: no buffer msgid=%x,srcid=%x,dstid=%x\r\n",
      *(volatile uint16_t *)(a1 + 4),
      *(volatile uint16_t *)(a1 + 8),
      *(volatile uint16_t *)(a1 + 6));
    return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
  }
  if ( !*((volatile uint32_t *)off_10D34C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_10D414 = 1;
    }
    v43 = (volatile int *)off_10D418;
    ++*(volatile uint32_t *)off_10D418;
    v44 = ((int (*)())process_event)();
    if ( *v43 )
    {
      v45 = *v43 - 1;
      v46 = *(volatile uint32_t *)off_10D414;
      *v43 = v45;
      if ( !v45 )
      {
        if ( v46 )
          __enable_irq();
      }
    }
    v49 = v44;
    v48 = list_count((volatile uint32_t **)dword_10D41C);
    v47 = list_count((volatile uint32_t **)dword_10D420);
    log_printf("err!!! ipc msg no buffer for usb in %d, free %d, %d\r\n", v48, v47, v49);
    return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10D354 = 1;
  }
  v35 = (volatile int *)off_10D358;
  v36 = dword_10D368;
  ++*(volatile uint32_t *)off_10D358;
  v8 = list_pop_front(v36);
  if ( *v35 )
  {
    v37 = *v35 - 1;
    v38 = *(volatile uint32_t *)off_10D354;
    *v35 = v37;
    if ( !v37 )
    {
      if ( v38 )
        __enable_irq();
    }
  }
  *(volatile uint16_t *)v7 = *(volatile uint16_t *)(a1 + 10) + 12;
  *((volatile uint8_t *)v7 + 2) = 17;
  *((volatile uint8_t *)v7 + 3) = 0;
  v6 = (int)(v7 + 1);
LABEL_6:
  v9 = *(volatile uint16_t *)(a1 + 10);
  *(volatile uint16_t *)v6 = *(volatile uint16_t *)(a1 + 4);
  *(volatile uint16_t *)(v6 + 6) = v9;
  if ( v9 )
  {
    if ( **(volatile int16_t **)off_10D33C < 0 && v9 > 0x80 )
    {
      flash_ctrl_init((int)aKmsgSrcParamLe, (int)aIpcEmbKmsgFwd, 1671);
      v9 = *(volatile uint16_t *)(a1 + 10);
    }
    memcpy((volatile char *)(v6 + 12), (volatile char *)(a1 + 12), v9);
    v10 = **v1;
    if ( v10 != 3 )
    {
LABEL_8:
      if ( v10 != 2 )
        goto LABEL_9;
LABEL_16:
      v13 = *(volatile uint16_t *)(a1 + 10);
      if ( (v13 & 3) != 0 )
      {
        v15 = (uint8_t)(4 - (v13 & 3));
        v14 = (uint8_t)(4 - (v13 & 3));
      }
      else
      {
        v14 = 0;
        v15 = 0;
      }
      v16 = (void *)(uintptr_t)(off_10D34C);
      v17 = *((volatile uint16_t *)off_10D34C + 4122);
      if ( v17 > 0x186 )
      {
        v19 = 0;
        v17 = (v17 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
        v18 = 1;
      }
      else
      {
        v18 = v17 + 1;
        v19 = 8 * v17;
      }
      v20 = (volatile int *)off_10D350;
      *((volatile uint16_t *)v8 + 6) = v17;
      v21 = *v20;
      v22 = v13 + 16;
      v23 = v21 + v19;
      *(volatile uint32_t *)(v23 + 4) = (int)(uintptr_t)(v7);
      *(volatile uint16_t *)(v21 + v19) = v15 + v22;
      *(volatile uint8_t *)(v23 + 3) = *(volatile uint8_t *)(v21 + v19 + 3) & 0x31 | 4;
      v24 = v16[3074];
      *((volatile uint16_t *)v16 + 4122) = v18;
      v16[3074] = v24 + 1;
      v8[1] = v21 + v19;
      v8[2] = v22 + v14;
      *((volatile uint8_t *)v8 + 14) = 1;
      *v8 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_10D354 = 1;
      }
      v25 = (volatile int *)off_10D358;
      v26 = dword_10D35C;
      ++*(volatile uint32_t *)off_10D358;
      check_kernel_state(v26, v8);
      ((int (*)())process_event)();
      if ( *v25 )
      {
        v27 = *v25 - 1;
        v28 = *(volatile uint32_t *)off_10D354;
        *v25 = v27;
        if ( !v27 )
        {
          if ( v28 )
            __enable_irq();
        }
      }
      if ( **v1 != 1 )
        return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
      goto LABEL_27;
    }
  }
  else
  {
    v10 = **v1;
    if ( v10 != 3 )
      goto LABEL_8;
  }
  v11 = (void *)(uintptr_t)(off_10D340);
  while ( !*(volatile uint32_t *)off_10D340 )
    ;
  check_kernel_state(*(volatile uint32_t *)off_10D344 + 524, (volatile uint32_t *)(v5 - 4));
  v12 = (void *)(uintptr_t)(off_10D348);
  *v11 = 1;
  *v12 = 2;
  v10 = **v1;
  if ( v10 == 2 )
    goto LABEL_16;
LABEL_9:
  if ( v10 != 1 )
    return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
LABEL_27:
  v29 = (void *)(uintptr_t)(irq_disable());
  if ( !v29 )
  {
    log_printf(aSendMsgCfgToHo);
    return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
  }
  *(volatile uint16_t *)v7 = *(volatile uint16_t *)(a1 + 10) + 12;
  *((volatile uint8_t *)v7 + 2) = 17;
  *((volatile uint8_t *)v7 + 3) = 0;
  v30 = *(volatile uint16_t *)(a1 + 10);
  v29[1] = 0;
  *v29 = (int)(uintptr_t)(v7);
  v29[2] = (uint16_t)(v30 + 16) | 0x80000000;
  irq_disable_set_flag_4((int)v29);
  return (void *)(uintptr_t)(isr_forward((int)(uintptr_t)((volatile char *)a1)));
}


// clear_mac_info @ 0x10d43c
volatile int *clear_mac_info() {
  return memset((volatile int *)dword_10D448, 0, 0x38u);
}



// rf_phy_irq @ 0x10d44c
int rf_phy_irq() {
  int v0; // r3
  int result; // r0

  v0 = *((volatile uint32_t *)off_10D470 + 3);
  if ( (v0 & 0x8000) != 0 )
    *((volatile uint32_t *)off_10D470 + 2) = 0x800000;
  if ( (v0 & 0x400) != 0 )
  {
    *((volatile uint32_t *)off_10D470 + 2) = 0x40000;
    return set_busy_flag_alt(0x20000000);
  }
  return result;
}



// rf_phy_init @ 0x10d474
int rf_phy_init() {
  volatile unsigned int *v0; // r2
  unsigned int v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r3

  v0 = (volatile unsigned int *)off_10D4B8;
  v1 = *(volatile uint32_t *)off_10D4B8;
  if ( (*(volatile uint32_t *)off_10D4B8 & 1) == 0 )
  {
    v1 = v1 & 0xFFFFFCFE | 0x101;
    result = 17;
    *((volatile uint32_t *)off_10D4B8 + 4) = 0;
    v0[5] = 0;
    v0[1] = 17;
    *v0 = v1;
  }
  if ( (v1 & 0x4000) == 0 )
    *(volatile uint32_t *)off_10D4B8 = v1 | 0x4040;
  v3 = (void *)(uintptr_t)(off_10D4C0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D4BC + 2) + 148) = off_10D4C4;
  *v3 = 0x200000;
  return result;
}



// panic_fatal @ 0x10d4c8
void panic_fatal() {
  volatile uint32_t *v0; // r3

  v0 = (void *)(uintptr_t)(off_10D4E0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_10D4DC + 2) + 148) = off_10D4E4;
  *v0 = 0x200000;
}



// mac_tx_work @ 0x10d4e8
void mac_tx_work() {
  int v0; // r3
  volatile uint32_t *v1; // r5
  volatile uint32_t *v2; // r0
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r4
  volatile uint32_t *v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r7
  int v10; // r0
  int v11; // r3
  volatile uint32_t *v12; // r2
  volatile uint32_t *v13; // r4
  volatile int *v14; // r5
  volatile int *v15; // r6
  volatile uint32_t *v16; // r0
  volatile unsigned int *v17; // r1
  volatile uint32_t *v18; // r5
  volatile uint32_t *v19; // r2
  int v20; // r0
  volatile uint32_t *v21; // r2
  volatile uint32_t *v22; // r3
  int v23; // r0

  v0 = *((volatile uint32_t *)off_10D5D4 + 43);
  if ( v0 >= 0 )
  {
    if ( *(volatile uint32_t *)off_10D5D8 )
    {
      v21 = (void *)(uintptr_t)(off_10D600);
      v22 = (void *)(uintptr_t)(off_10D604);
      v23 = dword_10D608;
      *(volatile uint32_t *)off_10D5E0 = 1;
      *(volatile uint32_t *)(v21[2] + 124) = v23;
      *v22 = 0x8000;
    }
  }
  else if ( *(volatile uint32_t *)off_10D5D8 )
  {
    v1 = (void *)(uintptr_t)(off_10D5E0);
    v2 = (void *)(uintptr_t)(off_10D5E4);
    v3 = (void *)(uintptr_t)(off_10D5E8);
    *(volatile uint32_t *)off_10D5DC = 0;
    *v1 = 0;
    *v2 = 1;
    v4 = (void *)(uintptr_t)(off_10D5EC);
    v5 = (void *)(uintptr_t)(off_10D5F0);
    *v3 |= 0x100u;
    *v4 = 3;
    v6 = v0 & 0x7FFFFFFF;
    if ( (v5[20] & 0x20) != 0 )
    {
      v7 = *(volatile uint32_t *)off_10D610;
      if ( v6 < *(volatile uint32_t *)off_10D610 >> 4 )
        goto LABEL_5;
    }
    else
    {
      v7 = 2 * *(volatile uint32_t *)off_10D5F4;
      if ( v6 < v7 >> 4 )
      {
LABEL_5:
        v8 = v7 / v6;
        v9 = (uint8_t)(v8 >> 4);
        v10 = ((v8 >> 1) & 7) + 16 * ((v8 & 0xF) - ((v8 >> 1) & 7));
        v11 = (uint8_t)(v8 >> 12);
LABEL_6:
        v12 = (void *)(uintptr_t)(off_10D5EC);
        v13 = (void *)(uintptr_t)(off_10D5E0);
        v14 = (volatile int *)off_10D5F8;
        v15 = (volatile int *)off_10D5FC;
        *(volatile uint32_t *)off_10D5EC |= 0x80u;
        *v15 = v9;
        *v13 = v11;
        *v14 = v10;
        v16 = (void *)(uintptr_t)(off_10D5DC);
        v17 = (volatile unsigned int *)off_10D5E4;
        v18 = (void *)(uintptr_t)(off_10D600);
        *v12 &= ~0x80u;
        *v16 = 7;
        v19 = (void *)(uintptr_t)(off_10D604);
        v20 = dword_10D608;
        *v17 = *v17 & 0xFFFFFE00 | 1;
        *v13 = 1;
        *(volatile uint32_t *)(v18[2] + 124) = v20;
        *v19 = 0x8000;
        goto LABEL_7;
      }
    }
    v10 = 0;
    v11 = 0;
    v9 = 1;
    goto LABEL_6;
  }
LABEL_7:
  *(volatile uint32_t *)off_10D60C = 1;
}



// mac_tx_irq @ 0x10d614
void mac_tx_irq() {
  if ( !*(volatile uint32_t *)off_10D620 )
    mac_tx_work();
}



// trace_sync @ 0x10d624
void trace_sync() {
  *((volatile uint32_t *)off_10D638 + 32) = 0x8000;
  __dsb(0xFu);
  __isb(0xFu);
}



// uart_tx_byte @ 0x10d63c
int uart_tx_byte(int result) {
  while ( (*(volatile uint32_t *)off_10D64C & 0x80000) != 0 )
    ;
  *(volatile uint32_t *)off_10D650 = result;
  return result;
}



// uart_tx_string @ 0x10d654
volatile uint8_t * uart_tx_string(volatile uint8_t *result) {
  int v1; // r1
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r4
  int v4; // t1

  v1 = (uint8_t)*result;
  if ( *result )
  {
    v2 = (void *)(uintptr_t)(off_10D678);
    v3 = (void *)(uintptr_t)(off_10D67C);
    do
    {
      while ( (*v2 & 0x80000) != 0 )
        ;
      *v3 = v1;
      v4 = (uint8_t)*++result;
      v1 = v4;
    }
    while ( v4 );
  }
  return result;
}



// uart_rx_byte @ 0x10d680
int uart_rx_byte() {
  while ( (*(volatile uint32_t *)off_10D690 & 1) == 0 )
    ;
  return (uint8_t)*(volatile uint32_t *)off_10D694;
}



// uart_rx_ready @ 0x10d698
int uart_rx_ready() {
  return *(volatile uint32_t *)off_10D6A4 & 1;
}



// hci_cmd_init @ 0x10d6a8
int hci_cmd_init(volatile uint8_t *a1, volatile unsigned int *a2) {
  volatile uint32_t *v2; // r4
  signed int v3; // r0
  int v4; // r6
  signed int v5; // r5
  int v6; // r3
  volatile char *v7; // r4
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r0
  volatile char *v10; // r5
  int v11; // r2
  int v12; // t1
  volatile uint8_t **v14; // r7
  int v15; // r3
  volatile uint8_t **v16; // r8
  volatile char *v17; // r0
  volatile uint32_t *v18; // r2
  volatile int *v19; // r4
  int v20; // r1
  int v21; // t1
  int v22; // r3
  volatile char *v23; // r7
  unsigned int v24; // r0
  volatile uint8_t *v25; // r7
  volatile uint8_t *v26; // r8
  volatile char *v27; // r0
  volatile uint32_t *v28; // r2
  volatile int *v29; // r12
  int v30; // r1
  int v31; // t1
  volatile uint16_t *v32; // r9
  int v33; // r10
  volatile char *v34; // r0
  volatile uint32_t *v35; // r2
  volatile int *v36; // r5
  int v37; // r1
  int v38; // t1
  volatile char **v39; // r11
  int v40; // r0
  volatile char *v41; // r7
  int v42; // r3
  volatile uint8_t *v43; // r1
  unsigned int v44; // r2
  uint16_t v45; // r0
  volatile uint32_t *v46; // r5
  int v47; // r2
  volatile int *v48; // r5
  int v49; // r0
  int v50; // r3
  int v51; // r2
  volatile char *v52; // r0
  volatile uint32_t *v53; // r2
  volatile int *v54; // r4
  int v55; // r1
  int v56; // t1
  volatile char *v57; // r0
  volatile uint32_t *v58; // r2
  volatile int *v59; // r4
  int v60; // r1
  int v61; // t1
  volatile char *v62; // r0
  volatile uint32_t *v63; // r2
  volatile int *v64; // r7
  int v65; // r1
  int v66; // t1
  volatile int *v67; // r11
  uint64_t v68; // kr00_8
  int ( *v69)(uint32_t); // r3
  int v70; // r0
  volatile uint16_t *v71; // r3
  int v72; // r3
  uint16_t v73; // r5
  volatile char *v74; // r1
  volatile uint32_t *v75; // r2
  volatile int *v76; // r0
  int v77; // t1
  char a1a[260]; // [sp+8h] [bp-104h] BYREF

  v3 = rf_parse_cal_cmd(a1a, 256, 0, a1, a2);
  v4 = v3;
  if ( v3 <= 0 )
    return v4;
  v5 = v3;
  if ( *(volatile uint32_t *)off_10D970 )
  {
    v6 = *((volatile uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((volatile uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
      goto LABEL_4;
  }
  else
  {
    mac_tx_work();
    v6 = *((volatile uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((volatile uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
    {
LABEL_4:
      v7 = a1a;
      v8 = (void *)(uintptr_t)(off_10D978);
      v9 = (void *)(uintptr_t)(off_10D97C);
      v10 = &a1a[v5];
      do
      {
        v12 = (uint8_t)*v7++;
        v11 = v12;
        if ( v12 == 10 && v6 != 13 )
        {
          while ( (*v8 & 0x80000) != 0 )
            ;
          *v9 = 13;
          v11 = (uint8_t)*(v7 - 1);
        }
        while ( (*v8 & 0x80000) != 0 )
          ;
        *v9 = v11;
        v6 = (uint8_t)*(v7 - 1);
      }
      while ( v7 != v10 );
      return v4;
    }
  }
  v14 = (volatile uint8_t **)off_10D980;
  v15 = **(volatile uint8_t **)off_10D980;
  if ( v15 == 1 )
  {
    v22 = **(volatile uint8_t **)off_10D988;
    if ( v22 != 3 )
    {
      if ( v5 >= 124 )
        v5 = (v5 & ~0xFFFFu) | ((uint16_t)(124) & 0xFFFFu);
      ke_alloc_node(19, a1a, (uint16_t)v5, v22);
    }
  }
  else
  {
    if ( v15 != 2 )
      return v4;
    v16 = (volatile uint8_t **)off_10D988;
    if ( **(volatile uint8_t **)off_10D988 == 3 )
      goto LABEL_12;
    if ( (unsigned int)list_count((volatile uint32_t **)dword_10D98C) <= 4 )
    {
      if ( **v14 != 2 )
        return v4;
      if ( **v16 != 3 )
      {
        if ( (unsigned int)list_count((volatile uint32_t **)dword_10D98C) > 4 )
        {
          v57 = aOtherErr;
          v58 = (void *)(uintptr_t)(off_10D978);
          v59 = (volatile int *)off_10D97C;
          v60 = 111;
          do
          {
            while ( (*v58 & 0x80000) != 0 )
              ;
            *v59 = v60;
            v61 = (uint8_t)*++v57;
            v60 = v61;
          }
          while ( v61 );
        }
        else
        {
          v52 = aFree5;
          v53 = (void *)(uintptr_t)(off_10D978);
          v54 = (volatile int *)off_10D97C;
          v55 = 102;
          do
          {
            while ( (*v53 & 0x80000) != 0 )
              ;
            *v54 = v55;
            v56 = (uint8_t)*++v52;
            v55 = v56;
          }
          while ( v56 );
        }
        return v4;
      }
LABEL_12:
      v17 = aNoActive;
      v18 = (void *)(uintptr_t)(off_10D978);
      v19 = (volatile int *)off_10D97C;
      v20 = 110;
      do
      {
        while ( (*v18 & 0x80000) != 0 )
          ;
        *v19 = v20;
        v21 = (uint8_t)*++v17;
        v20 = v21;
      }
      while ( v21 );
      return v4;
    }
    v23 = a1a;
    while ( 1 )
    {
      v24 = (unsigned int)v23++;
      if ( !memcmp(v24, (unsigned int)aCm4FaultHandle, 0x14u) )
        break;
      if ( &a1a[v5] == v23 )
      {
        v25 = (void *)(uintptr_t)(off_10D990);
        goto LABEL_30;
      }
    }
    v62 = aFoundPanic;
    v63 = (void *)(uintptr_t)(off_10D978);
    v64 = (volatile int *)off_10D97C;
    v65 = 70;
    do
    {
      while ( (*v63 & 0x80000) != 0 )
        ;
      *v64 = v65;
      v66 = (uint8_t)*++v62;
      v65 = v66;
    }
    while ( v66 );
    v25 = (void *)(uintptr_t)(off_10D990);
    v67 = (volatile int *)off_10D9D0;
    v68 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10D9C0 + 4);
    v69 = *(int ( **)(uint32_t))(HIDWORD(v68) + 16);
    *(volatile uint8_t *)off_10D990 = 1;
    v70 = v69(v68);
    v71 = (volatile uint16_t *)off_10D9C4;
    *v67 = v70;
    *v71 = 4;
LABEL_30:
    if ( *v25 )
    {
      v26 = (void *)(uintptr_t)(off_10D9CC);
      if ( !memcmp((unsigned int)a1a, (unsigned int)aPanic, 5u) )
      {
        v27 = aPanicEnd;
        v28 = (void *)(uintptr_t)(off_10D978);
        v29 = (volatile int *)off_10D97C;
        *v26 = 1;
        v30 = 80;
        do
        {
          while ( (*v28 & 0x80000) != 0 )
            ;
          *v29 = v30;
          v31 = (uint8_t)*++v27;
          v30 = v31;
        }
        while ( v31 );
      }
      v32 = (volatile uint16_t *)off_10D9C4;
      v33 = *(volatile uint16_t *)off_10D9C4;
      if ( v33 + v5 <= 1720 )
      {
        v39 = (volatile char **)off_10DA68;
        memcpy((volatile char *)(*(volatile uint32_t *)off_10DA68 + v33), a1a, v5);
        v72 = (uint8_t)*v26;
        v73 = v5 + *v32;
        v33 = v73;
        *v32 = v73;
        if ( !v72 )
          return v4;
      }
      else
      {
        v34 = aBufFull;
        v35 = (void *)(uintptr_t)(off_10D978);
        v36 = (volatile int *)off_10D97C;
        v37 = 66;
        do
        {
          while ( (*v35 & 0x80000) != 0 )
            ;
          *v36 = v37;
          v38 = (uint8_t)*++v34;
          v37 = v38;
        }
        while ( v38 );
        v39 = (volatile char **)off_10D9D0;
      }
      v40 = dword_10D98C;
      *v25 = 0;
      *v26 = 0;
      v41 = *v39;
      *v32 = 4;
      *v39 = nullptr;
      v4 = v33;
      list_pop_front(v40);
    }
    else
    {
      v2 = list_pop_front(dword_10DA54);
      if ( v5 <= 122 )
        v41 = (volatile char *)disable_interrupts();
      else
        v41 = (volatile char *)(*(int ( **)(uint32_t))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DA58 + 8) + 16))(*(volatile uint32_t *)(*(volatile uint32_t *)off_10DA58 + 4));
      if ( !v41 )
      {
        v74 = aNoTxBuffer;
        v75 = (void *)(uintptr_t)(off_10DA60);
        v76 = (volatile int *)off_10DA64;
        v4 = 110;
        do
        {
          while ( (*v75 & 0x80000) != 0 )
            ;
          *v76 = v4;
          v77 = (uint8_t)*++v74;
          v4 = v77;
        }
        while ( v77 );
        return v4;
      }
      memcpy(v41 + 4, a1a, v5);
      v33 = (v33 & ~0xFFFFu) | ((uint16_t)(v5) & 0xFFFFu);
    }
    *(volatile uint16_t *)v41 = v4 + 1;
    v41[2] = 19;
    v42 = 0;
    v43 = (void *)(uintptr_t)(off_10D9A0);
    v41[3] = 0;
    v41[v4 + 4] = 0;
    v44 = *((volatile uint16_t *)v43 + 4122);
    if ( v44 > 0x186 )
    {
      v44 = (v44 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
      v45 = 1;
    }
    else
    {
      v45 = v44 + 1;
      v42 = 8 * v44;
    }
    v46 = (void *)(uintptr_t)(off_10D9A4);
    *((volatile uint16_t *)v2 + 6) = v44;
    v47 = *v46 + v42;
    *(volatile uint32_t *)(v47 + 4) = (int)(uintptr_t)(v41);
    *(volatile uint16_t *)v47 = v33 + 5;
    *(volatile uint8_t *)(v47 + 3) = *(volatile uint8_t *)(v47 + 3) & 0x31 | 4;
    v46 = (void *)(uintptr_t)(((uintptr_t)(v46) & ~0xFFu) | ((uint8_t)(v43[3074] + 1) & 0xFFu));
    *((volatile uint16_t *)v43 + 4122) = v45;
    v43[3074] = (uint8_t)v46;
    v2[1] = v47;
    *((volatile uint8_t *)v2 + 14) = 1;
    *v2 = 0;
    v2[2] = v4 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_10D9A8 = 1;
    }
    v48 = (volatile int *)off_10D9AC;
    v49 = dword_10D9B0;
    ++*(volatile uint32_t *)off_10D9AC;
    check_kernel_state(v49, v2);
    ((int (*)())process_event)();
    if ( *v48 )
    {
      v50 = *v48 - 1;
      v51 = *(volatile uint32_t *)off_10D9A8;
      *v48 = v50;
      if ( !v50 )
      {
        if ( v51 )
          __enable_irq();
      }
    }
  }
  return v4;
}


// log_printf @ 0x10da6c
int log_printf(const volatile char *fmt, ...) {
  va_list varg_r1; // [sp+14h] [bp+8h] BYREF

  va_start(varg_r1, fmt);
  return hci_cmd_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
}


// rf_channel_valid @ 0x10da88
int rf_channel_valid(int result) {
  int v1; // r2

  v1 = 1 << result;
  if ( result <= 1 || (unsigned int)(result - 8) <= 1 )
  {
    result = 4 * result + 1079001088;
    *(volatile uint32_t *)result = *(volatile uint32_t *)result & 0xFFFFFFF0 | 1;
  }
  else if ( result <= 15 )
  {
    result = 4 * result + 1079001088;
    *(volatile uint32_t *)result &= 0xFFFFFFF0;
  }
  *((volatile uint32_t *)off_10DAD4 + 1) |= v1;
  return result;
}



// gpio_cfg_clear @ 0x10dad8
int gpio_cfg_clear(char a1) {
  int result; // r0

  result = 1 << a1;
  *((volatile uint32_t *)off_10DAEC + 2) &= ~result;
  return result;
}



// gpio_cfg_set @ 0x10daf0
int gpio_cfg_set(char a1) {
  int result; // r0

  result = (1 << a1) | *((volatile uint32_t *)off_10DB00 + 2);
  *((volatile uint32_t *)off_10DB00 + 2) = result;
  return result;
}



// gpio_out_set @ 0x10db04
int gpio_out_set(char a1) {
  int result; // r0

  result = (1 << a1) | *(volatile uint32_t *)off_10DB14;
  *(volatile uint32_t *)off_10DB14 = result;
  return result;
}



// gpio_out_clear @ 0x10db18
int gpio_out_clear(char a1) {
  int result; // r0

  result = 1 << a1;
  *(volatile uint32_t *)off_10DB2C &= ~result;
  return result;
}



// gpio_read_pin @ 0x10db30
BOOL gpio_read_pin(char a1) {
  return ((1 << a1) & *(volatile uint32_t *)off_10DB44) != 0;
}



// pinmux_config_1 @ 0x10db48
int pinmux_config_1(int result) {
  volatile uint32_t *v1; // r1

  if ( result <= 7 )
  {
    v1 = (void *)(uintptr_t)(off_10DB74);
    ((volatile uint32_t *)(uintptr_t)0x40504080u)[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}



// gpio_disable_interrupt @ 0x10db78
int gpio_disable_interrupt(char a1) {
  int result; // r0

  result = 1 << a1;
  *((volatile uint32_t *)off_10DB8C + 2) &= ~result;
  return result;
}



// gpio_set_pin_1 @ 0x10db90
int gpio_set_pin_1(char a1) {
  int result; // r0

  result = (1 << a1) | *((volatile uint32_t *)off_10DBA0 + 2);
  *((volatile uint32_t *)off_10DBA0 + 2) = result;
  return result;
}



// gpio_set_pin_out @ 0x10dba4
int gpio_set_pin_out(char a1) {
  int result; // r0

  result = (1 << a1) | *(volatile uint32_t *)off_10DBB4;
  *(volatile uint32_t *)off_10DBB4 = result;
  return result;
}



// gpio_clear_pin_1 @ 0x10dbb8
int gpio_clear_pin_1(char a1) {
  int result; // r0

  result = 1 << a1;
  *(volatile uint32_t *)off_10DBCC &= ~result;
  return result;
}



// gpio_get_pin @ 0x10dbd0
BOOL gpio_get_pin(char a1) {
  return ((1 << a1) & *(volatile uint32_t *)off_10DBE4) != 0;
}



// nullsub_1 @ 0x10dbe8
int nullsub_1(void) {
  return 0;
}


// nullsub_2 @ 0x10dbec
int nullsub_2(void) {
  return 0;
}


// nullsub_3 @ 0x10dbf0
int nullsub_3(void) {
  return 0;
}


// check_hw_status @ 0x10dbf4
int check_hw_status(int a1) {
  int v1; // r3
  int v2; // r0
  int v3; // r1

  v1 = dword_10DC3C;
  if ( (*(volatile uint8_t *)off_10DC34 & 0xC0) == 0xC0 )
    v1 = dword_10DC38;
  v2 = 4 * a1;
  v3 = v1 + 16;
  do
  {
    *(volatile uint32_t *)(v3 - 12) = *(volatile uint32_t *)(v3 - 12) & 0xFFFFFFF3 | v2;
    v3 += 12;
  }
  while ( v1 + 208 != v3 );
  return memcpy_advance(1, 16, 0x10u, v1);
}



// gpio_init_pin_11 @ 0x10dc40
int gpio_init_pin_11() {
  int result; // r0
  volatile uint32_t *v1; // r3

  result = call_slot_0x1b8(dword_10DC70, 2048, 15360);
  v1 = (void *)(uintptr_t)(off_10DC74);
  *((volatile uint32_t *)off_10DC74 + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}



