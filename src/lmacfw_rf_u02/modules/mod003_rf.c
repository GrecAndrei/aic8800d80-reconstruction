// heap_calloc @ 0x1047b8
unsigned int heap_calloc(volatile int *a1, int a2, unsigned int a3, int a4, volatile uint64_t *a5) {
  int v6; // r0
  float v7; // r0
  volatile unsigned int *v8; // r11
  uint64_t v9; // r2
  uint64_t v10; // d9
  uint64_t v11; // r0
  int v12; // r0
  uint64_t v13; // r2
  uint64_t v14; // d13
  int v15; // r6
  uint64_t v16; // r0
  int v17; // r0
  uint64_t v18; // r4
  uint64_t v19; // r2
  int v20; // r8
  uint64_t v21; // r0
  int v22; // r0
  uint64_t v23; // d8
  uint64_t v24; // r2
  uint64_t v25; // r0
  int v26; // r0
  uint64_t v27; // r2
  int v28; // r6
  uint64_t v29; // r0
  int v30; // r0
  int v31; // r7
  uint64_t v32; // r2
  int v33; // r6
  uint64_t v34; // r0
  int v35; // r0
  volatile unsigned int *v36; // r10
  uint64_t v37; // d11
  uint64_t v38; // r6
  uint64_t v39; // r0
  uint64_t v40; // r8
  uint64_t v41; // r6
  uint64_t v42; // r0
  uint64_t v43; // d10
  uint64_t v44; // r6
  uint64_t v45; // r0
  uint64_t v46; // r6
  uint64_t v47; // r0
  uint64_t v48; // r6
  uint64_t v49; // r0
  uint64_t v50; // d12
  uint64_t v51; // r6
  uint64_t v52; // r0
  uint64_t v53; // r6
  uint64_t v54; // r0
  uint64_t v55; // r0
  uint64_t v56; // r8
  uint64_t v57; // r0
  uint64_t v58; // r6
  uint64_t v59; // r0
  uint64_t v60; // r6
  uint64_t v61; // r0
  uint64_t v62; // r0
  uint64_t v63; // r2
  uint64_t v64; // r0
  uint64_t v65; // r0
  unsigned int result; // r0
  unsigned int v67; // t1
  uint64_t v68; // r8
  uint64_t v69; // [sp+0h] [bp-1Ch]
  uint64_t v70; // [sp+8h] [bp-14h]
  uint64_t v71; // [sp+10h] [bp-Ch]

  v6 = ((int (*)())double_to_float_1)(*(volatile uint64_t *)&a3);
  dispatch_event_handler_1("temp_delta=%d\n", v6);
  v7 = COERCE_FLOAT(gpio_port_init());
  v8 = (volatile unsigned int *)a1;
  dispatch_event_handler_1("tmp*100=%d\n", (int)(float)(v7 * flt_104A84));
  v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v10 = a5[2];
  v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())aeabi_dadd)(v10, v9);
  v12 = ((int (*)(uint64_t))double_to_float_1)(v11);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v14 = a5[1];
  v15 = v12;
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())aeabi_dadd)(v14, v13);
  v17 = ((int (*)(uint64_t))double_to_float_1)(v16);
  v18 = *a5;
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = v17;
  v21 = ((uint64_t (*)())aeabi_dadd)(*a5, v19);
  v22 = ((int (*)(uint64_t))double_to_float_1)(v21);
  v23 = a5[5];
  v71 = a5[4];
  v70 = a5[3];
  dispatch_event_handler_1("x[0]*1000=%3d,x[1]*1000=%3d,x[2]*1000=%3d\n", v22, v20, v15);
  v24 = (v24 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v24 = (v24 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v25 = ((uint64_t (*)())aeabi_dadd)(v23, v24);
  v26 = ((int (*)(uint64_t))double_to_float_1)(v25);
  v27 = (v27 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v28 = v26;
  v27 = (v27 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v29 = ((uint64_t (*)())aeabi_dadd)(v71, v27);
  v30 = ((int (*)(uint64_t))double_to_float_1)(v29);
  v31 = v28;
  v32 = (v32 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_104A8C) << 32);
  v32 = (v32 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v33 = v30;
  v34 = ((uint64_t (*)())aeabi_dadd)(v70, v32);
  v35 = ((int (*)(uint64_t))double_to_float_1)(v34);
  dispatch_event_handler_1("y[0]*1000=%3d,y[1]*1000=%3d,y[2]*1000=%3d\n", v35, v33, v31);
  v36 = v8 + 32;
  do
  {
    v67 = *v8++;
    v68 = ((uint64_t (*)())aeabi_d2f)(v67);
if ( ((int (*)())double_ge)(v18, v68) ) { v63 = v70;
    }
else if ( ((int (*)())double_eq)(v14, v68) ) { v63 = v71;
    }
else if ( ((int (*)())double_le)(v10, v68) ) { v63 = v23;
    }
    else
    {
      v37 = ((uint64_t (*)())double_subtract)(v68, v14);
      v38 = ((uint64_t (*)())double_subtract)(v68, v10);
      v39 = ((uint64_t (*)())double_subtract)(v68, v18);
      v40 = v38;
      v41 = v39;
      v42 = ((uint64_t (*)())aeabi_dadd)(v70, v37);
      v43 = v41;
      v44 = ((uint64_t (*)())aeabi_dadd)(v42, v40);
      v45 = ((uint64_t (*)())double_subtract)(v18, v14);
      v46 = ((uint64_t (*)())aeabi_dsub)(v44, v45);
      v47 = ((uint64_t (*)())double_subtract)(v18, v10);
      v48 = ((uint64_t (*)())aeabi_dsub)(v46, v47);
      v49 = ((uint64_t (*)())aeabi_dadd)(v71, v43);
      v50 = v48;
      v51 = ((uint64_t (*)())aeabi_dadd)(v49, v40);
      v52 = ((uint64_t (*)())double_subtract)(v14, v18);
      v53 = ((uint64_t (*)())aeabi_dsub)(v51, v52);
      v54 = ((uint64_t (*)())double_subtract)(v14, v10);
      v55 = ((uint64_t (*)())aeabi_dsub)(v53, v54);
      v56 = double_add(v50, v55);
      v57 = ((uint64_t (*)())aeabi_dadd)(v23, v43);
      v58 = ((uint64_t (*)())aeabi_dadd)(v57, v37);
      v59 = ((uint64_t (*)())double_subtract)(v10, v18);
      v60 = ((uint64_t (*)())aeabi_dsub)(v58, v59);
      v61 = ((uint64_t (*)())double_subtract)(v10, v14);
      v62 = ((uint64_t (*)())aeabi_dsub)(v60, v61);
      v63 = double_add(v56, v62);
    }
    v69 = v63;
    v64 = ((uint64_t (*)())aeabi_d2f)(v8[63]);
    v65 = ((uint64_t (*)())aeabi_dadd)(v64, v69);
    result = ((int (*)(uint64_t))aeabi_dmul)(v65);
    v8[31] = result;
  }
  while ( v8 != v36 );
  return result;
}


// prcm_set_mask @ 0x104a98
int prcm_set_mask(int a1, int a2, int a3, int a4) {
  volatile unsigned int *v4; // r4
  volatile int *v5; // r9
  int v6; // r5
  volatile uint32_t *v7; // r11
  volatile uint32_t *v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r0
  int result; // r0

  v4 = (volatile unsigned int *)off_104B44;
  v5 = (volatile int *)off_104B58;
  v6 = dword_104B48;
  v7 = (void *)(uintptr_t)(off_104B5C);
  *(volatile uint32_t *)off_104B44 &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  write_timer_reg(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  write_timer_reg(2);
  *v7 = 8;
  write_timer_reg(300);
  v12 = (void *)(uintptr_t)(off_104B4C);
  *v4 |= 0x40000000u;
  v13 = HIWORD(*v12) & 0x3FFF;
  v14 = *v4 & 0xBFFFFFFF;
  *(volatile uint16_t *)(a2 + 2 * (a3 + 16 * a4)) = v13;
  *v4 = v14;
  result = check_interrupt_flag(1, "amp=%x pwr_amp_back[%d][%x]=%6d\n", a1, a4, a3, v13);
  if ( v13 > 0x3E80 )
    return dispatch_event_handler_1(aWarningDataSat_0);
  return result;
}


// min_u32 @ 0x104b60
int min_u32(int a1, int a2, int a3) {
  float v6; // s14
  int v7; // r3
  uint64_t v9; // r8
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r0
  float v13; // r0
  float v14; // s14
  uint64_t v15; // r8
  uint64_t v16; // r0
  uint64_t v17; // r0
  unsigned int v18; // r0

  if ( a1 > a2 )
  {
    v15 = aeabi_i2d(a1);
    v16 = aeabi_i2d(a2);
    v17 = ((uint64_t (*)())aeabi_dsub)(v15, v16);
    v18 = ((int (*)(uint64_t))aeabi_dmul)(v17);
    v13 = COERCE_FLOAT(float_to_double(v18));
    v14 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v9 = aeabi_i2d(a2);
    v10 = aeabi_i2d(a1);
    v11 = ((uint64_t (*)())aeabi_dsub)(v9, v10);
    v12 = ((int (*)(uint64_t))aeabi_dmul)(v11);
    v13 = COERCE_FLOAT(float_to_double(v12));
    v14 = -20.0;
LABEL_6:
    v6 = v13 * v14;
    v7 = (int)(float)(v6 * flt_104C04);
    goto LABEL_4;
  }
  v6 = flt_104BFC;
  v7 = 0;
LABEL_4:
  *(volatile float *)(a3 + 96) = v6;
  return check_interrupt_flag(1, "am_back_cur=%d am_back_base=%d pwr_act_diff*100=%d\n", a1, a2, v7);
}


// scale_f32 @ 0x104c08
int scale_f32(float a1, int a2, int a3) {
  float v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  int v9; // r0
  uint64_t v10; // kr00_8
  uint64_t v12; // kr08_8

  v6 = COERCE_FLOAT(crc32_block(COERCE_INT(a1 / 20.0)));
  v7 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)a2 * v6));
  v8 = parse_data_field(v7);
  v9 = (uint16_t)((int (*)(uint64_t))double_to_float_1)(v8);
  if ( (uint16_t)v9 <= 232 )
  {
    if ( (uint16_t)v9 > 31 )
    {
      *(volatile uint8_t *)(a3 + 104) = v9;
    }
    else
    {
      v12 = *(volatile uint64_t *)(a3 + 112);
      v9 = 32;
      *(volatile uint8_t *)(a3 + 104) = 32;
      if ( SHIDWORD(v12) < (int)v12 )
      {
        dispatch_event_handler_1("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is smaller\n", HIDWORD(v12), (uint32_t)v12);
        v9 = *(volatile uint8_t *)(a3 + 104);
      }
    }
  }
  else
  {
    v10 = *(volatile uint64_t *)(a3 + 112);
    v9 = 232;
    *(volatile uint8_t *)(a3 + 104) = -24;
    if ( SHIDWORD(v10) < (int)v10 )
    {
      dispatch_event_handler_1("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is bigger\n", HIDWORD(v10), (uint32_t)v10);
      v9 = *(volatile uint8_t *)(a3 + 104);
    }
  }
  return check_interrupt_flag(1, "pwr_diff*100=%4d base_pwr=%x dig_pwr=%x ", (int)(float)(a1 * flt_104CB0), a2, v9);
}


// list_remove @ 0x104cc0
int list_remove(int a1, float a2, volatile int *a3, int a4, int a5) {
  int result; // r0
  int v7; // r3
  int v8; // r1
  float v9; // s14
  int v10; // r1
  int v11; // r3
  int v12; // r3
  int v13; // r1
  float v14; // s14

  result = a3[2];
  a3[1] = result;
  if ( a5 )
  {
    if ( result >= 0 )
    {
      v7 = a4 + 4 * (result + 33);
      v8 = result;
      while ( 1 )
      {
        v9 = *(volatile float *)(v7 - 4);
        v7 -= 4;
        --v8;
        if ( !(v9 >= a2) )
          break;
        a3[1] = v8;
        if ( v8 == -1 )
          goto LABEL_22;
      }
LABEL_6:
      v10 = a3[1];
      v11 = v10 + 1;
      goto LABEL_7;
    }
  }
  else if ( result >= 0 )
  {
    v12 = a4 + 4 * (result + 1);
    v13 = result;
    while ( 1 )
    {
      v14 = *(volatile float *)(v12 - 4);
      v12 -= 4;
      --v13;
      if ( !(v14 >= a2) )
        goto LABEL_6;
      a3[1] = v13;
      if ( v13 == -1 )
      {
LABEL_22:
        *a3 = 0;
        goto LABEL_23;
      }
    }
  }
  v11 = result + 1;
  v10 = result;
LABEL_7:
  if ( result >= v11 )
  {
    *a3 = v11;
  }
  else
  {
    v11 = result;
    *a3 = result;
  }
  if ( v11 < 0 )
    *a3 = 0;
  if ( result < v10 )
    a3[1] = result;
  else
    result = v10;
  if ( result < 0 )
LABEL_23:
    a3[1] = 0;
  return result;
}



// rx_packet_handler @ 0x104d60
int rx_packet_handler( int a1, int a2, int a3, int a4, uint8_t a5, char a6, uint8_t a7, int a8, int a9) {
  volatile float *v11; // r4
  int v12; // r9
  volatile float *v13; // r5
  float v14; // s15
  float v15; // s16
  uint64_t v16; // r6
  uint64_t v17; // r0
  uint64_t v18; // r0
  uint64_t v19; // r0
  float v20; // s17
  volatile float *v21; // r10
  volatile float *v22; // r9
  int v23; // r5
  volatile float *v24; // r4
  uint64_t v25; // r6
  uint64_t v26; // r0
  uint64_t v27; // r0
  float v28; // s13
  int v29; // r5
  volatile float *v30; // r2
  volatile float *v31; // r3
  float v32; // s15
  float v33; // s10
  float v34; // s11
  float v35; // s12
  float v36; // s18
  volatile float *v37; // r7
  volatile float *v38; // r6
  float v39; // s15
  float v40; // s16
  volatile float *v41; // r9
  float v42; // s19
  float v43; // s17
  uint64_t v44; // r0
  float v45; // s17
  float v46; // s19
  int v47; // r5
  int v48; // r10
  int v49; // r11
  volatile float *v50; // r7
  float v51; // s18
  float v52; // s16
  uint64_t v53; // r0
  float v54; // s15
  int v55; // zf
  float v56; // r9
  float v57; // s16
  volatile float *v58; // r5
  volatile int *v59; // r6
  volatile float *v60; // r8
  volatile int *v61; // r7
  int v62; // r9
  float v63; // s13
  float v64; // s15
  float v65; // s14
  int v66; // r2
  int v67; // s13
  int v68; // s15
  int v69; // r11
  int v70; // r7
  int v71; // r5
  int v72; // r8
  int v73; // r10
  int v74; // r9
  volatile int *v75; // r6
  int v76; // r3
  int v77; // r4
  int v78; // r5
  int v79; // r9
  volatile int *v80; // r7
  int v81; // r6
  int v82; // r11
  volatile int *v83; // r0
  volatile int *v84; // r12
  int v85; // t1
  volatile int *v87; // r6
  int v88; // r4
  int v89; // r5
  volatile uint32_t *v90; // r1
  int v91; // r2
  volatile int *v92; // r6
  int v93; // r1
  volatile int *v94; // r4
  int v95; // t1
  volatile uint32_t *v96; // r12
  int v97; // r2
  int v98; // r0
  volatile int *v99; // r2
  volatile int *v100; // r0
  volatile int *v101; // r1
  int v102; // t1
  struct __attribute__((packed)) { int v103; // [sp+2Ch] [bp-180h]
  union { int v104; // [sp+30h] [bp-17Ch]
  int v105; // [sp+30h] [bp-17Ch]
  int v106; }; // [sp+30h] [bp-17Ch]
  union { volatile float *v107; // [sp+34h] [bp-178h]
  volatile float *v108; // [sp+34h] [bp-178h]
  unsigned int v109; }; // [sp+34h] [bp-178h]
  union { int a4a; // [sp+38h] [bp-174h]
  int a4b; // [sp+38h] [bp-174h]
  int a4c; }; // [sp+38h] [bp-174h]
  int v113; // [sp+3Ch] [bp-170h]
  int v114; // [sp+40h] [bp-16Ch]
  int v115; // [sp+44h] [bp-168h]
  int v116; // [sp+48h] [bp-164h]
  char _pad8[16]; int a3a; // [sp+5Ch] [bp-150h] BYREF
  unsigned int v119; // [sp+60h] [bp-14Ch]
  int v120; // [sp+64h] [bp-148h]
  float v121[16]; // [sp+68h] [bp-144h] BYREF
  float v122[16]; // [sp+A8h] [bp-104h] BYREF
  uint8_t v123[64]; // [sp+E8h] [bp-C4h] BYREF
  int v124; // [sp+128h] [bp-84h] BYREF
  int v125; // [sp+12Ch] [bp-80h]
  int v126; // [sp+130h] [bp-7Ch]
  int v127; // [sp+134h] [bp-78h]
  int v128; // [sp+138h] [bp-74h]
  int v129; // [sp+13Ch] [bp-70h]
  int v130; // [sp+140h] [bp-6Ch]
  int v131; // [sp+144h] [bp-68h]
  int v132; // [sp+148h] [bp-64h]
  int v133; // [sp+14Ch] [bp-60h]
  int v134; // [sp+150h] [bp-5Ch]
  int v135; // [sp+154h] [bp-58h]
  int v136; // [sp+158h] [bp-54h]
  int v137; // [sp+15Ch] [bp-50h]
  int v138; // [sp+160h] [bp-4Ch]
  int v139; // [sp+164h] [bp-48h]
  uint32_t v140[8]; // [sp+168h] [bp-44h] BYREF
  int v141; // [sp+188h] [bp-24h]
  int v142; // [sp+18Ch] [bp-20h]
  int v143; // [sp+190h] [bp-1Ch]
  int v144; // [sp+194h] [bp-18h]
  int v145; // [sp+198h] [bp-14h]
  int v146; // [sp+19Ch] [bp-10h]
  int v147; // [sp+1A0h] [bp-Ch]
  int v148; // [sp+1A4h] [bp-8h]
  uint8_t v149[4]; // [sp+1A8h] [bp-4h] BYREF
  } _frame;
  v11 = (volatile float *)a3;
  _frame.v104 = a9 - 1;
  if ( a2 > 1 )
  {
    v12 = a3 + 128 + 4 * a2;
    v13 = (volatile float *)(a3 + 132);
    do
    {
      v14 = *v13++;
      v15 = *(v13 - 2);
      if ( v14 < v15 )
      {
        v16 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v14));
        v17 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v15));
        v18 = ((uint64_t (*)())aeabi_dadd)(v17, *(volatile uint64_t *)&dword_105040);
if ( ((int (*)())double_lt)(v16, v18) ) { check_interrupt_flag(1, aWarningAmIsNot);
          v15 = *(v13 - 2);
        }
        *(v13 - 1) = v15;
      }
    }
    while ( (volatile float *)v12 != v13 );
  }
  if ( a1 > 0 )
  {
    v19 = aeabi_i2d(a1);
    v20 = flt_105038;
    _frame.a4a = (int)v11;
    v21 = _frame.v122;
    v22 = (volatile float *)_frame.v123;
    v23 = 0;
    v24 = _frame.v121;
    v25 = v19;
    do
    {
      v26 = aeabi_i2d(++v23);
      v27 = ((uint64_t (*)())aeabi_dsub)(v26, v25);
      *(volatile uint32_t *)v24++ = ((int (*)(uint64_t))aeabi_dmul)(v27);
      *v21++ = 1.0;
      *v22++ = v20;
    }
    while ( v23 != a1 );
    v11 = (volatile float *)_frame.a4a;
  }
  v28 = _frame.v121[_frame.v104];
  v29 = 0;
  _frame.a4b = a2 - 1;
  _frame.v120 = a2 - 1;
  list_remove(a2, v28, &_frame.a3a, (int)v11, 0);
  v30 = &v11[_frame.v119];
  v31 = &v11[_frame.a3a];
  v32 = *v30;
  v33 = v30[32];
  v34 = v31[32] - v33;
  v35 = *v31 - *v30;
  _frame.v122[_frame.v104] = v28;
  v36 = (float)((float)((float)(v34 / v35) * (float)(v28 - v32)) + v33) / v28;
  if ( a1 <= 0 )
  {
    if ( a1 )
    {
      check_interrupt_flag(1, aIDpdOutDpdPmOu);
      goto LABEL_44;
    }
  }
  else
  {
    v37 = _frame.v122;
    v38 = _frame.v121;
    do
    {
      if ( v29 != _frame.v104 )
      {
        v40 = v36 * *v38;
        list_remove(a2, v40, &_frame.a3a, (int)v11, 1);
        if ( _frame.a3a )
        {
          v41 = &v11[_frame.a3a];
if ( _frame.a4b == _frame.v119 || (v42 = v11[_frame.v119 + 32], _frame.v107 = &v11[_frame.v119], v43 = v41[32] - v42, v44 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v43)), ((int (*)())double_lt)(v44, *(volatile uint64_t *)&dword_105030)) ) { v39 = 1.0;
          }
          else
          {
            v39 = (float)((float)((float)(*v41 - *_frame.v107) * (float)(v40 - v42)) / v43) + *_frame.v107;
          }
        }
        else
        {
          v39 = (float)(v40 * *v11) / v11[32];
        }
        *v37 = v39;
      }
      ++v29;
      ++v37;
      ++v38;
    }
    while ( a1 != v29 );
  }
  v45 = flt_105038;
  _frame.v105 = a1;
  v46 = flt_10503C;
  v47 = a9 - 1;
  v48 = -1;
  v49 = a9 - 1;
  while ( 1 )
  {
    v56 = _frame.v122[v47];
    list_remove(a2, v56, &_frame.a3a, (int)v11, 0);
    if ( _frame.a3a )
    {
      _frame.v108 = &v11[_frame.v119];
      v50 = &v11[_frame.a3a];
      if ( _frame.a4b == _frame.v119 )
      {
        v54 = v11[_frame.a4b + 96];
      }
      else
      {
        v51 = *_frame.v108;
        v52 = *v50 - *_frame.v108;
        v53 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v52));
if ( !((int (*)())double_gt)(v53, *(volatile uint64_t *)&dword_105030) ) v52 = v46;
        v54 = (float)((float)((float)(v50[96] - _frame.v108[96]) / v52) * (float)(v56 - v51)) + _frame.v108[96];
      }
    }
    else
    {
      v54 = v11[v49 + 96];
    }
    v55 = v47 == v49;
    if ( v47 != v49 )
    {
      v54 = v45 - v54;
      *(volatile float *)&_frame.v149[4 * v47 - 192] = v54;
    }
    v47 = v48 + 1;
    if ( v55 )
      v45 = v54;
    if ( _frame.v105 <= v47 )
      break;
    ++v48;
  }
  check_interrupt_flag(1, aIDpdOutDpdPmOu);
  if ( _frame.v105 > 0 )
  {
    v57 = flt_105300;
    v58 = _frame.v122;
    v59 = &_frame.v124;
    v60 = (volatile float *)_frame.v123;
    v61 = (void *)(_frame.v140);
    v62 = 0;
    do
    {
      v63 = *v60++;
      v64 = *v58++;
      v65 = v63 / v57;
      v66 = v62++;
      v67 = vcvts_n_s32_f32(v64, 0xAu);
      v68 = vcvts_n_s32_f32(v65, 9u);
      *v59++ = v67;
      if ( v67 >= 1024 )
        *(v59 - 1) = 1023;
      *v61++ = v68;
      if ( v68 < 0 )
        *(v61 - 1) = v68 + (v68 < 0 ? 0x400 : 0);
      check_interrupt_flag(1, a5d5d5d, v66);
    }
    while ( _frame.v105 != v62 );
  }
LABEL_44:
  v69 = (_frame.v127 << 10) + (_frame.v126 << 20) + _frame.v128;
  _frame.v103 = (_frame.v130 << 10) + (_frame.v129 << 20) + _frame.v131;
  _frame.v106 = (_frame.v133 << 10) + (_frame.v132 << 20) + _frame.v134;
  _frame.v109 = (_frame.v136 << 10) + (_frame.v135 << 20) + _frame.v137;
  _frame.v113 = _frame.v140[1] + 1049600 * _frame.v140[0];
  _frame.v114 = (_frame.v140[3] << 10) + (_frame.v140[2] << 20) + _frame.v140[4];
  _frame.v115 = (_frame.v140[6] << 10) + (_frame.v140[5] << 20) + _frame.v140[7];
  _frame.a4c = (_frame.v139 << 10) + (_frame.v138 << 20);
  v70 = (_frame.v142 << 10) + (_frame.v141 << 20) + _frame.v143;
  v71 = 15 - a8;
  v72 = (_frame.v145 << 10) + (_frame.v144 << 20) + _frame.v146;
  v73 = (_frame.v148 << 10) + (_frame.v147 << 20);
  v74 = _frame.v125 + (_frame.v124 << 10);
  if ( !a7 )
  {
    if ( a8 == 4 )
    {
      v71 = 1;
    }
    else if ( a8 == 7 )
    {
      v71 = 0;
    }
LABEL_48:
    v75 = (void *)(&((volatile uint32_t *)(uintptr_t)off_105308)[316 * a7 + 12 * v71]);
    _frame.v116 = v71 + 24;
    v76 = v71;
    v77 = a4 + 96 + 48 * v71;
    v78 = _frame.v125 + (_frame.v124 << 10);
    v79 = (_frame.v142 << 10) + (_frame.v141 << 20) + _frame.v143;
    v80 = v75;
    v81 = (_frame.v127 << 10) + (_frame.v126 << 20) + _frame.v128;
    v82 = v76;
    do
    {
      check_interrupt_flag(1, aDpdUseDTable, v82);
      *(volatile uint32_t *)(v77 - 40) = _frame.v103;
      *(volatile uint32_t *)(v77 - 36) = _frame.v106;
      *(volatile uint32_t *)(v77 - 32) = _frame.v109;
      *(volatile uint32_t *)(v77 - 28) = _frame.a4c;
      *(volatile uint32_t *)(v77 - 24) = _frame.v113;
      *(volatile uint32_t *)(v77 - 20) = _frame.v114;
      *(volatile uint32_t *)(v77 - 48) = v78;
      *(volatile uint32_t *)(v77 - 44) = v81;
      *(volatile uint32_t *)(v77 - 16) = _frame.v115;
      *(volatile uint32_t *)(v77 - 12) = v79;
      *(volatile uint32_t *)(v77 - 8) = v72;
      *(volatile uint32_t *)(v77 - 4) = v73;
      v83 = (volatile int *)(v77 - 48);
      v84 = v80;
      do
      {
        v85 = *v83++;
        v84[1] = v85;
        ++v84;
      }
      while ( (volatile int *)v77 != v83 );
      v82 += 8;
      v80 += 96;
      v77 += 384;
    }
    while ( _frame.v116 != v82 );
    v70 = v79;
    v69 = v81;
    v74 = v78;
    return check_interrupt_flag(
             1,
             " am1=%x\n"
             " am2=%x\n"
             " am3=%x\n"
             " am4=%x\n"
             " am5=%x\n"
             " am6=%x\n"
             " pm1=%x\n"
             " pm2=%x\n"
             " pm3=%x\n"
             " pm4=%x\n"
             " pm5=%x\n"
             " pm6=%x\n",
             v74,
             v69,
             _frame.v103,
             _frame.v106,
             _frame.v109,
             _frame.a4c,
             _frame.v113,
             _frame.v114,
             _frame.v115,
             v70,
             v72,
             v73);
  }
  if ( a8 == 7 )
    v71 = 5;
  if ( !a6 )
    goto LABEL_48;
  if ( a5 == 2 )
  {
    v87 = (volatile int *)off_1053B8;
    check_interrupt_flag(1, "dpd use %d table\n", v71);
    v96 = (volatile uint32_t *)(a4 + 48 * v71);
    v96[14] = _frame.v103;
    v96[15] = _frame.v106;
    v96[16] = _frame.v109;
    v96[17] = _frame.a4c;
    v96[18] = _frame.v113;
    v97 = 12 * v71 + 12;
    v96[19] = _frame.v114;
    v96[12] = v74;
    v96[13] = v69;
    v96[22] = v72;
    v96[23] = v73;
    v98 = 4 * v97 - 48;
    v88 = a4 + 96;
    v96[20] = _frame.v115;
    v96[21] = v70;
    v99 = (volatile int *)(a4 + 4 * v97);
    v100 = (volatile int *)(v98 + a4 + 96);
    v101 = &v87[316 * a7 + 3 + 12 * v71];
    do
    {
      v102 = *v99++;
      v101[1] = v102;
      ++v101;
    }
    while ( v100 != v99 );
  }
  else
  {
    v87 = (volatile int *)off_105314;
    v88 = a4 + 96;
  }
  v89 = v71 + 8 * a5;
  check_interrupt_flag(1, "dpd use %d table\n", v89);
  v89 *= 3;
  v90 = (volatile uint32_t *)(a4 + 16 * v89);
  v90[14] = _frame.v103;
  v90[15] = _frame.v106;
  v90[16] = _frame.v109;
  v90[17] = _frame.a4c;
  v90[18] = _frame.v113;
  v90[19] = _frame.v114;
  v91 = 4 * v89 + 12;
  v90[12] = v74;
  v90[13] = v69;
  v90[20] = _frame.v115;
  v90[21] = v70;
  v90[22] = v72;
  v90[23] = v73;
  v92 = &v87[316 * a7 + 3 + 4 * v89];
  v93 = v88 + 4 * v91 - 48;
  v94 = (volatile int *)(a4 + 4 * v91);
  do
  {
    v95 = *v94++;
    v92[1] = v95;
    ++v92;
  }
  while ( (volatile int *)v93 != v94 );
  return check_interrupt_flag(
           1,
           " am1=%x\n"
           " am2=%x\n"
           " am3=%x\n"
           " am4=%x\n"
           " am5=%x\n"
           " am6=%x\n"
           " pm1=%x\n"
           " pm2=%x\n"
           " pm3=%x\n"
           " pm4=%x\n"
           " pm5=%x\n"
           " pm6=%x\n",
           v74,
           v69,
           _frame.v103,
           _frame.v106,
           _frame.v109,
           _frame.a4c,
           _frame.v113,
           _frame.v114,
           _frame.v115,
           v70,
           v72,
           v73);
}


// mac_get_params @ 0x1053c0
int mac_get_params(unsigned int a1, volatile uint32_t *a2) {
  int result; // r0
  int v5; // r5
  int v6; // r2
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r2

  a2[14] = 0;
  a2[15] = 15;
  a2[16] = 8;
  result = check_interrupt_flag(1, "bit_mask=%x\n", a1);
  if ( a1 )
  {
    v5 = 20;
    while ( 1 )
    {
      while ( ((1 << v5) & a1) >> v5 != 1 )
      {
LABEL_3:
        if ( ++v5 == 28 )
          return result;
      }
      a2[a2[14] + 10] = v5 - 12;
      check_interrupt_flag(1, "you want to cal %x index\n", v5 - 12);
      v6 = a2[a2[14] + 10];
      if ( v6 <= 7 )
      {
        result = check_interrupt_flag(((1 << v5) & a1) >> v5, " %x ana_pwr_index dont need cal\n", v6);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v7 = ((1 << v5) & a1) >> v5;
      if ( v6 > 15 )
      {
        result = check_interrupt_flag(v7, " %x ana_pwr_index dont need cal\n", v6);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = check_interrupt_flag(v7, "need cal %x ana_pwr_index\n", v6);
      v8 = a2[14];
      ++v5;
      v9 = a2[v8 + 10];
      a2[14] = v8 + 1;
      a2[15] = v9;
      if ( v5 == 28 )
        return result;
    }
  }
  return check_interrupt_flag(1, aLoftDontNeedCa);
}


// phy_set_txpower @ 0x105494
int phy_set_txpower(unsigned int a1, int a2, int a3) {
  int v5; // r5
  int v6; // r7
  int v7; // r9
  int result; // r0
  unsigned int v9; // r0
  int v10; // r2
  int v11; // r2
  int v12; // r1

  v5 = 0;
  *(volatile uint64_t *)(a2 + 628) = 0x40000000FLL;
  *(volatile uint32_t *)(a2 + 624) = 0;
  if ( a3 )
    v6 = 7;
  else
    v6 = 4;
  if ( a3 )
    v7 = 15;
  else
    v7 = 13;
  result = check_interrupt_flag(1, aBitMaskX, a1);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(volatile uint32_t *)(a2 + 4 * (*(volatile uint32_t *)(a2 + 624) + 148)) = v5;
        check_interrupt_flag(1, "you want to cal %x index\n", v5);
        v9 = ((1 << v5) & a1) >> v5;
        v10 = *(volatile uint32_t *)(a2 + 4 * (*(volatile uint32_t *)(a2 + 624) + 148));
        if ( v10 < v6 )
        {
          result = check_interrupt_flag(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(volatile uint32_t *)(a2 + 624) )
            *(volatile uint32_t *)(a2 + 632) = *(volatile uint32_t *)(a2 + 592);
        }
        else if ( v10 > v7 )
        {
          result = check_interrupt_flag(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(volatile uint32_t *)(a2 + 624) )
            *(volatile uint32_t *)(a2 + 628) = *(volatile uint32_t *)(a2 + 592);
        }
        else
        {
          result = check_interrupt_flag(v9, "need cal %x ana_pwr_index\n", v10);
          v11 = *(volatile uint32_t *)(a2 + 624);
          v12 = *(volatile uint32_t *)(a2 + 4 * (v11 + 148));
          *(volatile uint32_t *)(a2 + 624) = v11 + 1;
          *(volatile uint32_t *)(a2 + 628) = v12;
        }
      }
    }
    else
    {
      result = dispatch_event_handler_1(aDpdDontNeedCal);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}


// prcm_stop @ 0x105578
volatile unsigned int * prcm_stop(int a1, int a2, int a3, unsigned int a4, uint8_t a5, int a6) {
  volatile uint32_t *v6; // lr
  volatile unsigned int *v7; // r4
  volatile unsigned int *v8; // r5
  volatile unsigned int *v9; // r12
  volatile unsigned int *v10; // r7
  volatile unsigned int *v11; // r9
  volatile unsigned int *v12; // r0
  unsigned int v13; // r11
  unsigned int v14; // r10
  unsigned int v15; // r8
  unsigned int v16; // lr
  volatile uint32_t *v19; // r2
  volatile uint32_t *v20; // r0
  volatile unsigned int *v21; // r11
  volatile unsigned int *v22; // r9
  volatile int *v23; // r8
  volatile uint32_t *v24; // r1
  unsigned int v25; // r10
  unsigned int v26; // r6
  unsigned int v27; // r5
  unsigned int v28; // r11
  unsigned int v29; // lr
  unsigned int v30; // r4
  unsigned int v31; // r9
  unsigned int v32; // r12
  int v33; // r10
  void *v34; // r3
  void *v35; // r3
  void *v36; // r3
  void *v37; // r3
  void *v38; // r3
  volatile char *v39; // r2
  volatile uint32_t *v40; // r4
  volatile unsigned int *v41; // r1
  volatile unsigned int *v42; // r0
  int v43; // r8
  int v44; // r2
  unsigned int v45; // r9
  int v46; // r8
  int v47; // r4
  volatile unsigned int *v48; // r6
  volatile unsigned int *v49; // r5
  volatile unsigned int *v50; // r11
  volatile unsigned int *v51; // r4
  volatile unsigned int *v52; // r7
  volatile unsigned int *v53; // r9
  volatile unsigned int *v54; // r8
  volatile uint32_t *v55; // r2
  volatile unsigned int *v56; // r2
  volatile unsigned int *v57; // r12
  volatile unsigned int *v58; // r1
  volatile unsigned int *v59; // r3
  volatile unsigned int *v60; // lr
  volatile unsigned int *result; // r0
  volatile unsigned int *v62; // r10
  volatile uint32_t *v63; // r6
  volatile unsigned int *v64; // r2
  int v65; // [sp+8h] [bp-8Ch]
  int v66; // [sp+Ch] [bp-88h]
  unsigned int v67; // [sp+10h] [bp-84h]
  int v68; // [sp+10h] [bp-84h]
  int v69; // [sp+14h] [bp-80h]
  int v70; // [sp+18h] [bp-7Ch]
  unsigned int v71; // [sp+1Ch] [bp-78h]
  int v72; // [sp+1Ch] [bp-78h]
  unsigned int v73; // [sp+20h] [bp-74h]
  int v74; // [sp+20h] [bp-74h]
  unsigned int v75; // [sp+24h] [bp-70h]
  int v76; // [sp+24h] [bp-70h]
  unsigned int v77; // [sp+28h] [bp-6Ch]
  int v78; // [sp+28h] [bp-6Ch]
  unsigned int v79; // [sp+2Ch] [bp-68h]
  int v80; // [sp+2Ch] [bp-68h]
  unsigned int v81; // [sp+30h] [bp-64h]
  int v82; // [sp+30h] [bp-64h]
  unsigned int v83; // [sp+34h] [bp-60h]
  int v84; // [sp+34h] [bp-60h]
  int v85; // [sp+38h] [bp-5Ch]
  unsigned int v86; // [sp+3Ch] [bp-58h]
  int v87; // [sp+3Ch] [bp-58h]
  unsigned int v88; // [sp+40h] [bp-54h]
  int v89; // [sp+40h] [bp-54h]
  unsigned int v90; // [sp+44h] [bp-50h]
  int v91; // [sp+44h] [bp-50h]
  unsigned int v92; // [sp+48h] [bp-4Ch]
  int v93; // [sp+48h] [bp-4Ch]
  unsigned int v94; // [sp+4Ch] [bp-48h]
  int v95; // [sp+4Ch] [bp-48h]
  unsigned int v96; // [sp+50h] [bp-44h]
  int v97; // [sp+50h] [bp-44h]
  int v98; // [sp+54h] [bp-40h]
  unsigned int v99; // [sp+58h] [bp-3Ch]
  int v100; // [sp+58h] [bp-3Ch]
  int v101; // [sp+5Ch] [bp-38h]
  int v102; // [sp+5Ch] [bp-38h]
  unsigned int v103; // [sp+60h] [bp-34h]
  int v104; // [sp+60h] [bp-34h]
  unsigned int v105; // [sp+64h] [bp-30h]
  int v106; // [sp+64h] [bp-30h]
  int v107; // [sp+68h] [bp-2Ch]
  int v108; // [sp+6Ch] [bp-28h]
  int v109; // [sp+70h] [bp-24h]
  int v110; // [sp+74h] [bp-20h]
  int v111; // [sp+78h] [bp-1Ch]
  int v112; // [sp+7Ch] [bp-18h]
  int v113; // [sp+80h] [bp-14h]
  int v114; // [sp+84h] [bp-10h]
  int v115; // [sp+88h] [bp-Ch]

  v6 = (void *)(uintptr_t)(off_105874);
  v7 = (volatile unsigned int *)off_105848;
  v8 = (volatile unsigned int *)off_10584C;
  v9 = (volatile unsigned int *)off_10585C;
  v10 = (volatile unsigned int *)off_105850;
  v11 = (volatile unsigned int *)off_105868;
  *(volatile uint32_t *)off_105874 |= 0x400u;
  v12 = (volatile unsigned int *)off_105854;
  *v6 &= ~0x400u;
  v13 = *v8;
  v14 = *v9;
  v67 = *v7;
  v15 = *v7;
  v16 = *v10;
  v71 = *v12;
  v73 = *v12;
  v75 = *v12;
  v77 = *v12;
  v79 = *v8;
  v83 = *(volatile uint32_t *)off_105858;
  v81 = *(volatile uint32_t *)off_105858;
  *v8 |= 0x20u;
  *v9 = *v9 & 0xF8FFFFFF | 0x2000000;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v10 = *v10 & 0xFFFFFF0F | 0xC0;
  *v11 = *v11 & 0xFFFFFFC7 | 0x20;
  v65 = (v13 >> 5) & 1;
  v66 = HIBYTE(v14) & 7;
  v68 = (v67 >> 21) & 1;
  v69 = (v15 >> 20) & 1;
  v70 = (uint8_t)v16 >> 4;
  v72 = (v71 >> 7) & 1;
  v74 = (v73 >> 4) & 7;
  v76 = (v75 >> 10) & 1;
  v78 = (v77 >> 8) & 3;
  v80 = (v79 >> 2) & 7;
  v112 = (v83 >> 22) & 1;
  v111 = (v81 >> 21) & 1;
  *v12 |= 0x400u;
  if ( a4 <= 8 )
  {
    *v12 = *v12 & 0xFFFFFCFF | 0x100;
    *v8 &= 0xFFFFFFE3;
    goto LABEL_3;
  }
  if ( a4 == 9 )
  {
    if ( a5 )
    {
      *v12 &= 0xFFFFFCFF;
      *v8 &= 0xFFFFFFE3;
      goto LABEL_3;
    }
    goto LABEL_26;
  }
  if ( a4 <= 0xB )
  {
LABEL_26:
    v64 = (volatile unsigned int *)off_105DC8;
    *(volatile uint32_t *)off_105DC4 &= 0xFFFFFCFF;
    *v64 = *v64 & 0xFFFFFFE3 | 8;
    goto LABEL_3;
  }
  if ( a5 )
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x20;
    *v8 = *v8 & 0xFFFFFFE3 | 8;
    *v12 &= 0xFFFFFCFF;
    if ( a4 == 15 && a5 == 1 )
    {
      *v11 &= 0xFFFFFFC7;
      *v12 &= 0xFFFFFCFF;
      *v8 |= 0x1Cu;
    }
  }
  else
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x10;
    *v8 |= 0x1Cu;
    *v12 &= 0xFFFFFCFF;
  }
LABEL_3:
  v19 = (void *)(uintptr_t)(off_105858);
  v20 = (void *)(uintptr_t)(off_10585C);
  v21 = (volatile unsigned int *)off_105878;
  v22 = (volatile unsigned int *)off_10587C;
  v23 = (volatile int *)off_105880;
  *(volatile uint32_t *)off_105858 = *(volatile uint32_t *)off_105858 & 0xFFFE00FF | 0x100;
  *v19 |= 0x20000u;
  *v19 |= 0x40000u;
  check_interrupt_flag(1, "tia_aux_gbit_use=%d\n", (*v20 >> 21) & 7);
  v34 = (void *)(uintptr_t)(off_105864);
  v24 = (void *)(uintptr_t)(off_10586C);
  v25 = *(volatile uint32_t *)off_105868;
  v26 = *(volatile uint32_t *)off_10586C;
  v27 = *(volatile uint32_t *)off_105864;
  v86 = *(volatile uint32_t *)off_105864;
  v88 = *(volatile uint32_t *)off_105864;
  v90 = *(volatile uint32_t *)off_105848;
  v92 = *(volatile uint32_t *)off_105848;
  v94 = *(volatile uint32_t *)off_105848;
  v96 = *(volatile uint32_t *)off_105848;
  v28 = *v21;
  v99 = *(volatile uint32_t *)off_105870;
  v101 = *(volatile uint32_t *)off_105850;
  v103 = *v22;
  v105 = *(volatile uint32_t *)off_105850;
  v115 = *v23;
  v114 = *(volatile uint32_t *)off_105884;
  v29 = *(volatile uint32_t *)off_105848;
  v30 = *(volatile uint32_t *)off_105848;
  v31 = *(volatile uint32_t *)off_105848;
  v32 = *(volatile uint32_t *)off_105888;
  *(volatile uint32_t *)off_105868 |= 0x40u;
  *v24 &= 0xFFFF8FFF;
  *(volatile uint32_t *)v34 |= 0x800000u;
  v82 = (v26 >> 12) & 7;
  v84 = (v27 >> 23) & 1;
  v85 = (v27 >> 22) & 1;
  v87 = (v86 >> 20) & 1;
  v89 = (v88 >> 21) & 1;
  v91 = (v90 >> 17) & 1;
  v93 = HIWORD(v92) & 1;
  v95 = (v94 >> 15) & 1;
  v97 = (v96 >> 14) & 1;
  v98 = (v28 >> 18) & 1;
  v100 = (v99 >> 12) & 3;
  v102 = v101 & 3;
  v104 = (v103 >> 18) & 7;
  v106 = (v105 >> 2) & 1;
  v107 = (v29 >> 23) & 1;
  v108 = (v29 >> 22) & 1;
  v109 = (v30 >> 19) & 1;
  v110 = (v31 >> 18) & 1;
  v113 = (v32 >> 8) & 1;
  v33 = (v25 >> 6) & 1;
  *(volatile uint32_t *)v34 |= 0x400000u;
  v34 = (void *)(uintptr_t)(((uintptr_t)(v34) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v34 = (void *)(uint8_t)((uint8_t)v34 - 1);
  while ( v34 );
  v35 = (void *)(uintptr_t)(off_105864);
  *(volatile uint32_t *)off_105864 &= ~0x100000u;
  *(volatile uint32_t *)v35 |= 0x200000u;
  v35 = (void *)(uintptr_t)(((uintptr_t)(v35) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v35 = (void *)(uint8_t)((uint8_t)v35 - 1);
  while ( v35 );
  v36 = (void *)(uintptr_t)(off_105848);
  *(volatile uint32_t *)off_105864 |= 0x100000u;
  *(volatile uint32_t *)v36 |= 0x20000u;
  *(volatile uint32_t *)v36 |= 0x10000u;
  v36 = (void *)(uintptr_t)(((uintptr_t)(v36) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v36 = (void *)(uint8_t)((uint8_t)v36 - 1);
  while ( v36 );
  v37 = (void *)(uintptr_t)(off_105B9C);
  *(volatile uint32_t *)off_105B9C &= ~0x40000u;
  *(volatile uint32_t *)v37 |= 0x80000u;
  v37 = (void *)(uintptr_t)(((uintptr_t)(v37) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v37 = (void *)(uint8_t)((uint8_t)v37 - 1);
  while ( v37 );
  v38 = (void *)(uintptr_t)(off_105B9C);
  *(volatile uint32_t *)off_105B9C |= 0x40000u;
  *(volatile uint32_t *)v38 |= 0x8000u;
  *(volatile uint32_t *)v38 |= 0x4000u;
  v38 = (void *)(uintptr_t)(((uintptr_t)(v38) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v38 = (void *)(uint8_t)((uint8_t)v38 - 1);
  while ( v38 );
  v39 = (volatile char *)off_105BA0;
  v40 = (void *)(uintptr_t)(off_105BA4);
  v41 = (volatile unsigned int *)off_105BA8;
  v42 = (volatile unsigned int *)off_105BAC;
  *(volatile uint32_t *)off_105BA0 |= 0x40000u;
  *v40 |= 0x3000u;
  *v41 = *v41 & 0xFFFFFFFC | 1;
  *v42 = *v42 & 0xFFE3FFFF | 0xC0000;
  *v41 |= 4u;
  *(volatile uint32_t *)&v39[-28] |= 0x800000u;
  v40 -= 465770;
  *(volatile uint32_t *)&v39[-28] |= 0x400000u;
  *v40 &= ~0x100u;
  disable_bb_timer_irq();
  check_interrupt_flag(1, aStDpdDump);
  rf_reg_init((int)((uintptr_t)off_105BB4 + 0x4F0u * a5 + 0x10u), (int)((uintptr_t)off_105BB4 + 0x4F0u * a5 + 0x490u));
  *v40 &= ~0x200u;
  *v40 |= 0x200u;
  *v40 &= ~0x200u;
  if ( a5 )
  {
    v43 = a3 == 1;
    if ( a4 == 7 )
    {
      v44 = 8 * v43 + 5;
      v46 = v43 << 12;
      v47 = v44;
      v45 = 83886080;
    }
    else
    {
      v44 = 15 - a4 + 8 * v43;
      v45 = (15 - a4) << 24;
      v46 = v43 << 12;
      v47 = v44;
    }
  }
  else if ( a4 == 4 )
  {
    v44 = 1;
    v46 = 0;
    v47 = 1;
    v45 = 0x1000000;
  }
  else if ( a4 == 7 )
  {
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
  }
  else
  {
    v44 = 15 - a4;
    v46 = 0;
    v47 = 15 - a4;
    v45 = (15 - a4) << 24;
  }
  v48 = (volatile unsigned int *)off_105BB8;
  v49 = (volatile unsigned int *)off_105BC0;
  v50 = (volatile unsigned int *)off_105BA0;
  check_interrupt_flag(1, "dpd use %d table\n", v44);
  configure_bb_winsize(a2, v47, a6);
  v51 = (volatile unsigned int *)off_105BC8;
  check_interrupt_flag(1, "tx_gain_map_ini=%x\n", *v48);
  *v48 = v45 | v46 | (a4 << 8) | 0x3F4080;
  bb_hw_init();
  v52 = (volatile unsigned int *)off_105BD0;
  v53 = (volatile unsigned int *)off_105BA4;
  v54 = (volatile unsigned int *)off_105BAC;
  check_interrupt_flag(1, "tx_gain_map_ini00=%x\n", *v48);
  v55 = (void *)(uintptr_t)(off_105BD4);
  *v49 &= ~0x200u;
  *v49 |= 0x200u;
  *v49 &= ~0x200u;
  *v55 |= 0x10000000u;
  write_timer_reg(6500);
  load_patch_data();
  *v51 = *v51 & 0xFFBFFFFF | (v112 << 22);
  *v51 = *v51 & 0xFFDFFFFF | (v111 << 21);
  disable_rx_path();
  v56 = (volatile unsigned int *)off_105BD8;
  v57 = (volatile unsigned int *)off_105BE0;
  v58 = (volatile unsigned int *)off_105BDC;
  v59 = (volatile unsigned int *)off_105B9C;
  v60 = (volatile unsigned int *)off_105BE4;
  *v52 = *v52 & 0xF8FFFFFF | (v66 << 24);
  result = (volatile unsigned int *)off_105BA8;
  *v56 = *v56 & 0xFFFFFFBF | (v33 << 6);
  v62 = (volatile unsigned int *)off_105BE8;
  *v57 = *v57 & 0xFFFF8FFF | (v82 << 12);
  *v58 = *v58 & 0xFF7FFFFF | (v84 << 23);
  *v58 = *v58 & 0xFFBFFFFF | (v85 << 22);
  *v58 = *v58 & 0xFFEFFFFF | (v87 << 20);
  *v58 = *v58 & 0xFFDFFFFF | (v89 << 21);
  *v59 = *v59 & 0xFFFBFFFF | (v110 << 18);
  *v59 = *v59 & 0xFFF7FFFF | (v109 << 19);
  *v59 = *v59 & 0xFFFDFFFF | (v91 << 17);
  *v59 = *v59 & 0xFFFEFFFF | (v93 << 16);
  *v59 = *v59 & 0xFFFF7FFF | (v95 << 15);
  *v59 = *v59 & 0xFFFFBFFF | (v97 << 14);
  *v50 = *v50 & 0xFFFBFFFF | (v98 << 18);
  *v53 = *v53 & 0xFFFFCFFF | (v100 << 12);
  *result = *result & 0xFFFFFFFC | v102;
  *v54 = *v54 & 0xFFE3FFFF | (v104 << 18);
  *result = *result & 0xFFFFFFFB | (4 * v106);
  *v59 = *v59 & 0xFF7FFFFF | (v107 << 23);
  *v59 = *v59 & 0xFFBFFFFF | (v108 << 22);
  *v62 = *v62 & 0xFFFFFFDF | (32 * v65);
  *v59 = *v59 & 0xFFDFFFFF | (v68 << 21);
  *v59 = *v59 & 0xFFEFFFFF | (v69 << 20);
  v63 = (void *)(uintptr_t)(off_105DC0);
  *result = *result & 0xFFFFFF0F | (16 * v70);
  v56[20] = v56[20] & 0xFFFFFF7F | (v72 << 7);
  v56[20] = v56[20] & 0xFFFFFF8F | (16 * v74);
  v56[20] = v56[20] & 0xFFFFFBFF | (v76 << 10);
  v56[20] = v56[20] & 0xFFFFFCFF | (v78 << 8);
  *v62 = *v62 & 0xFFFFFFE3 | (4 * v80);
  *v51 &= 0xFFFE00FF;
  *v51 &= ~0x20000u;
  *v51 |= 0x40000u;
  *v60 = *v60 & 0x7FFFFFFF | v115 & 0x80000000;
  *v63 = v114;
  v57 -= 8848;
  *v49 = *v49 & 0xFFFFFEFF | (v113 << 8);
  *v57 |= 0x400u;
  *v57 &= ~0x400u;
  return result;
}


// validate_handle @ 0x105dcc
int validate_handle(int a1, int a2, int a3, int a4, int a5) {
  int v9; // r4
  unsigned int v10; // r4
  int v11; // r8
  volatile uint32_t *v12; // r3

  if ( (int)*(volatile uint32_t *)(a4 + 132) <= a2 )
  {
    scale_f32(*(volatile float *)(a4 + 4 * a2 + 148), (uint8_t)a1, a4);
    v9 = *(volatile uint8_t *)(a4 + 104);
  }
  else
  {
    v9 = (uint8_t)a1;
  }
  v10 = v9 | a1 & 0xFFFFF000 | (a2 << 8);
  if ( a3 )
  {
    if ( a2 == 7 )
    {
      v11 = 83886080;
      goto LABEL_8;
    }
    goto LABEL_11;
  }
  if ( a2 != 4 )
  {
    if ( a2 == 7 )
      goto LABEL_6;
LABEL_11:
    if ( (unsigned int)(a2 - 4) > 0xB )
      goto LABEL_9;
    if ( a2 > 6 )
    {
      if ( a3 )
      {
        v11 = (15 - a2) << 24;
        goto LABEL_8;
      }
    }
    else if ( a3 )
    {
      goto LABEL_14;
    }
    a3 = 15 - a2;
    goto LABEL_6;
  }
  a3 = 1;
LABEL_6:
  if ( (a5 & 0xFFFFFFFD) == 0 )
  {
LABEL_14:
    v10 |= 0xC08000u;
    check_interrupt_flag(1, "table %d index %d bypass\n", a5, a2);
    goto LABEL_9;
  }
  v11 = a3 << 24;
LABEL_8:
  v10 = v10 & 0xFF3F7FFF | v11;
LABEL_9:
  v12 = (void *)(uintptr_t)(off_105E88);
  *(volatile uint32_t *)off_105E88 = v10;
  return check_interrupt_flag(1, "tx_gain_map=%x ", *v12);
}


// load_device_desc @ 0x105e94
int load_device_desc(int a1, int a2) {
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  volatile int *v13; // r4
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r6
  int v26; // r2
  volatile int *v27; // r3
  int v28; // r1
  volatile unsigned int *v29; // r4
  int v30; // r3
  int tbl[27]; // [sp+0h] [bp-6Ch] BYREF

  v4 = ((volatile uint32_t *)(uintptr_t)off_105F28)[1];
  v5 = ((volatile uint32_t *)(uintptr_t)off_105F28)[2];
  v6 = ((volatile uint32_t *)(uintptr_t)off_105F28)[3];
  tbl[0] = ((volatile uint32_t *)(uintptr_t)off_105F28)[0];
  tbl[1] = v4;
  tbl[2] = v5;
  tbl[3] = v6;
  v7 = ((volatile uint32_t *)(uintptr_t)off_105F28)[5];
  v8 = ((volatile uint32_t *)(uintptr_t)off_105F28)[6];
  v9 = ((volatile uint32_t *)(uintptr_t)off_105F28)[7];
  tbl[4] = ((volatile uint32_t *)(uintptr_t)off_105F28)[4];
  tbl[5] = v7;
  tbl[6] = v8;
  tbl[7] = v9;
  v10 = ((volatile uint32_t *)(uintptr_t)off_105F28)[9];
  v11 = ((volatile uint32_t *)(uintptr_t)off_105F28)[10];
  v12 = ((volatile uint32_t *)(uintptr_t)off_105F28)[11];
  tbl[8] = ((volatile uint32_t *)(uintptr_t)off_105F28)[8];
  tbl[9] = v10;
  tbl[10] = v11;
  tbl[11] = v12;
  v13 = (void *)(&((volatile uint32_t *)(uintptr_t)off_105F28)[13]);
  tbl[12] = ((volatile uint32_t *)(uintptr_t)off_105F28)[12];
  v14 = *v13;
  v15 = v13[1];
  v16 = v13[2];
  v17 = v13[3];
  v13 += 4;
  tbl[13] = v14;
  tbl[14] = v15;
  tbl[15] = v16;
  tbl[16] = v17;
  v18 = *v13;
  v19 = v13[1];
  v20 = v13[2];
  v21 = v13[3];
  v13 += 4;
  tbl[17] = v18;
  tbl[18] = v19;
  tbl[19] = v20;
  tbl[20] = v21;
  v22 = v13[1];
  v23 = v13[2];
  v24 = v13[3];
  tbl[21] = *v13;
  tbl[22] = v22;
  tbl[23] = v23;
  tbl[24] = v24;
  v25 = *(volatile uint32_t *)(a1 + 4 * a2 + 140);
  tbl[25] = v13[4];
  check_interrupt_flag(1, "shift_idx=%d ", v25);
  if ( v25 > 25 )
    v26 = 12;
  else
    v26 = (v25 / 2) & ~((v25 / 2) >> 31);
  v27 = &tbl[v26 + 26];
  v28 = *(v27 - 26);
  v29 = (volatile unsigned int *)off_105F34;
  v30 = *(v27 - 13);
  *(volatile uint32_t *)off_105F30 = (8 * v28) & 0x38 | *(volatile uint32_t *)off_105F30 & 0xFFFFFFC7;
  *v29 = (4 * v30) & 0x1C | *v29 & 0xFFFFFFE3;
  return check_interrupt_flag(1, "index=%d\n", v26);
}


// malloc_wrapper @ 0x105f40
int malloc_wrapper(int a1, int a2, int a3) {
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r9
  unsigned int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5
  int v13; // r2

  v5 = aeabi_i2d(a2);
  v6 = ((uint64_t (*)())aeabi_dsub)(v5, *(volatile uint64_t *)&dword_105FC8);
  v7 = a1 + 4 * a3;
  v8 = ((int (*)(uint64_t))aeabi_dmul)(v6);
  v9 = *(volatile uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(float_to_double(v8));
  v11 = *(volatile uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    check_interrupt_flag(1, "sat> %d \n", HIDWORD(v11));
    v13 = *(volatile uint32_t *)(a1 + 172);
    if ( v13 <= v12 )
      goto LABEL_3;
LABEL_5:
    check_interrupt_flag(1, "sma %d\n", v13);
    goto LABEL_3;
  }
  v13 = *(volatile uint32_t *)(a1 + 172);
  if ( v13 > v12 )
    goto LABEL_5;
LABEL_3:
  *(volatile uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return load_device_desc(a1, a3);
}


// prcm_start @ 0x105fd0
int prcm_start(unsigned int a1, int a2, volatile uint16_t *a3, int a4, int a5, int a6, int a7, int a8) {
  volatile uint32_t *v8; // r9
  volatile unsigned int *v9; // r8
  volatile unsigned int *v10; // r10
  volatile unsigned int *v11; // r4
  volatile unsigned int *v12; // lr
  volatile unsigned int *v13; // r7
  volatile unsigned int *v14; // r12
  volatile unsigned int *v15; // r5
  volatile unsigned int *v16; // r6
  unsigned int v17; // r9
  unsigned int v18; // r8
  unsigned int v19; // r7
  int v20; // r6
  void *v24; // r3
  void *v25; // r3
  void *v26; // r3
  volatile uint32_t *v27; // r3
  int v28; // r7
  volatile uint32_t *v29; // r0
  volatile uint32_t *v30; // r2
  volatile unsigned int *v31; // r1
  volatile uint32_t *v32; // r5
  volatile uint32_t *v33; // r2
  volatile uint32_t *v34; // r2
  volatile uint16_t *v35; // r9
  volatile uint32_t *v36; // r8
  int v37; // r7
  int v38; // r3
  int v39; // t1
  int v40; // r2
  int v41; // r1
  int v42; // r5
  volatile uint32_t *v43; // r6
  volatile uint32_t *v44; // r9
  int v45; // r2
  volatile unsigned int *v46; // r4
  volatile unsigned int *v47; // r5
  volatile unsigned int *v48; // r9
  volatile unsigned int *v49; // r11
  volatile uint32_t *v50; // r8
  volatile uint32_t *v51; // r1
  volatile unsigned int *v52; // r2
  volatile unsigned int *v53; // r12
  volatile unsigned int *v54; // r3
  volatile unsigned int *v55; // r6
  volatile unsigned int *v56; // r0
  volatile unsigned int *v57; // r7
  volatile unsigned int *v58; // r2
  volatile uint32_t *v59; // r10
  int v61; // r8
  int v62; // r9
  int v63; // r10
  int v64; // r7
  int v65; // r6
  unsigned int v66; // r5
  int v67; // r3
  int v68; // r7
  volatile int *v69; // r6
  volatile uint32_t *v70; // r7
  int v71; // r9
  int v72; // r10
  int v73; // r8
  volatile unsigned int *v74; // r6
  unsigned int v75; // r5
  int v76; // r5
  char v77; // r3
  int v78; // r6
  volatile int *v79; // r3
  volatile int *v80; // r12
  volatile int *v81; // r2
  int v82; // r0
  volatile int *v83; // r1
  int v84; // r3
  unsigned int v85; // r3
  unsigned int v86; // [sp+8h] [bp-CCh]
  char v87; // [sp+8h] [bp-CCh]
  int v88; // [sp+8h] [bp-CCh]
  unsigned int v89; // [sp+Ch] [bp-C8h]
  int v90; // [sp+Ch] [bp-C8h]
  unsigned int v91; // [sp+10h] [bp-C4h]
  int v92; // [sp+10h] [bp-C4h]
  unsigned int v93; // [sp+14h] [bp-C0h]
  int v94; // [sp+14h] [bp-C0h]
  unsigned int v95; // [sp+18h] [bp-BCh]
  int v96; // [sp+18h] [bp-BCh]
  unsigned int v97; // [sp+1Ch] [bp-B8h]
  int v98; // [sp+1Ch] [bp-B8h]
  unsigned int v99; // [sp+20h] [bp-B4h]
  int v100; // [sp+20h] [bp-B4h]
  unsigned int v101; // [sp+24h] [bp-B0h]
  int v102; // [sp+24h] [bp-B0h]
  unsigned int v103; // [sp+28h] [bp-ACh]
  int v104; // [sp+28h] [bp-ACh]
  unsigned int v105; // [sp+2Ch] [bp-A8h]
  int v106; // [sp+2Ch] [bp-A8h]
  unsigned int v107; // [sp+30h] [bp-A4h]
  int v108; // [sp+30h] [bp-A4h]
  unsigned int v109; // [sp+34h] [bp-A0h]
  int v110; // [sp+34h] [bp-A0h]
  unsigned int v111; // [sp+38h] [bp-9Ch]
  int v112; // [sp+38h] [bp-9Ch]
  unsigned int v113; // [sp+3Ch] [bp-98h]
  int v114; // [sp+3Ch] [bp-98h]
  unsigned int v115; // [sp+40h] [bp-94h]
  int v116; // [sp+40h] [bp-94h]
  unsigned int v117; // [sp+44h] [bp-90h]
  int v118; // [sp+44h] [bp-90h]
  unsigned int v119; // [sp+48h] [bp-8Ch]
  int v120; // [sp+48h] [bp-8Ch]
  unsigned int v121; // [sp+4Ch] [bp-88h]
  int v122; // [sp+4Ch] [bp-88h]
  unsigned int v123; // [sp+50h] [bp-84h]
  int v124; // [sp+50h] [bp-84h]
  unsigned int v125; // [sp+54h] [bp-80h]
  int v126; // [sp+54h] [bp-80h]
  unsigned int v127; // [sp+58h] [bp-7Ch]
  int v128; // [sp+58h] [bp-7Ch]
  unsigned int v129; // [sp+5Ch] [bp-78h]
  int v130; // [sp+5Ch] [bp-78h]
  unsigned int v131; // [sp+60h] [bp-74h]
  int v132; // [sp+60h] [bp-74h]
  unsigned int v133; // [sp+64h] [bp-70h]
  int v134; // [sp+64h] [bp-70h]
  unsigned int v135; // [sp+68h] [bp-6Ch]
  int v136; // [sp+68h] [bp-6Ch]
  unsigned int v137; // [sp+6Ch] [bp-68h]
  int v138; // [sp+6Ch] [bp-68h]
  unsigned int v139; // [sp+70h] [bp-64h]
  int v140; // [sp+70h] [bp-64h]
  unsigned int v141; // [sp+74h] [bp-60h]
  int v142; // [sp+74h] [bp-60h]
  int v143; // [sp+78h] [bp-5Ch]
  int v144; // [sp+7Ch] [bp-58h]
  int v145; // [sp+80h] [bp-54h]
  int v146; // [sp+84h] [bp-50h]
  int v147; // [sp+88h] [bp-4Ch]
  int v148; // [sp+8Ch] [bp-48h]
  int v149; // [sp+90h] [bp-44h]
  char v150; // [sp+94h] [bp-40h]
  int v151; // [sp+94h] [bp-40h]
  int v152; // [sp+98h] [bp-3Ch]
  int v153; // [sp+9Ch] [bp-38h]
  int v154; // [sp+A0h] [bp-34h]
  int v155; // [sp+A4h] [bp-30h]
  int v156; // [sp+A8h] [bp-2Ch]
  int v157; // [sp+ACh] [bp-28h]
  int v158; // [sp+B0h] [bp-24h]
  unsigned int v159; // [sp+B4h] [bp-20h]
  int v160; // [sp+B8h] [bp-1Ch]
  unsigned int v161; // [sp+BCh] [bp-18h]
  int v162; // [sp+C0h] [bp-14h]
  int v163; // [sp+C4h] [bp-10h]
  int v164; // [sp+C8h] [bp-Ch]
  int v165; // [sp+CCh] [bp-8h]

  v8 = (void *)(uintptr_t)(off_1062D8);
  v9 = (volatile unsigned int *)off_1062DC;
  v10 = (volatile unsigned int *)off_1062E0;
  v11 = (volatile unsigned int *)off_1062B0;
  v12 = (volatile unsigned int *)off_1062E4;
  v13 = (volatile unsigned int *)off_1062B4;
  v14 = (volatile unsigned int *)off_1062E8;
  v15 = (volatile unsigned int *)off_1062B8;
  *(volatile uint32_t *)off_1062D8 |= 0x400u;
  *v8 &= ~0x400u;
  v89 = *v9;
  v91 = *v10;
  v93 = *v11;
  v95 = *v11;
  v97 = *v12;
  v99 = *v13;
  v101 = *v13;
  v103 = *v13;
  v105 = *v13;
  v107 = *v9;
  v141 = *(volatile uint32_t *)off_1062BC;
  v139 = *(volatile uint32_t *)off_1062BC;
  *v9 |= 0x20u;
  v16 = (volatile unsigned int *)off_1062BC;
  *v10 = *v10 & 0xF8FFFFFF | 0x2000000;
  *v11 |= 0x100000u;
  *v11 |= 0x200000u;
  *v12 = *v12 & 0xFFFFFF0F | 0xC0;
  *v14 = *v14 & 0xFFFFFFC7 | 0x20;
  *v13 |= 0x400u;
  *v13 = *v13 & 0xFFFFFCFF | 0x100;
  *v16 = *v16 & 0xFFFE00FF | 0x100;
  *v16 |= 0x20000u;
  *v16 |= 0x40000u;
  v109 = *v14;
  v111 = *(volatile unsigned int *)((volatile char *)v16 + 0xFFFFFFC8);
  v113 = *v15;
  v115 = *v15;
  v117 = *v15;
  v119 = *v15;
  v121 = *v11;
  v123 = *v11;
  v125 = *v11;
  v127 = *v11;
  v129 = *(volatile uint32_t *)off_1062C0;
  v131 = *(volatile uint32_t *)off_1062C4;
  v133 = *v12;
  v135 = *(volatile uint32_t *)off_1062C8;
  v137 = *v12;
  v147 = *(volatile uint32_t *)off_1062CC;
  v86 = *v11;
  v18 = *v11;
  v17 = *v11;
  v146 = *(volatile uint32_t *)off_1062D0;
  v19 = *(volatile uint32_t *)off_1062D4;
  *v14 |= 0x40u;
  *(volatile unsigned int *)((volatile char *)v16 + 0xFFFFFFC8) &= 0xFFFF8FFF;
  *v15 |= 0x800000u;
  v20 = a4;
  v90 = (v89 >> 5) & 1;
  v92 = HIBYTE(v91) & 7;
  v94 = (v93 >> 21) & 1;
  v96 = (v95 >> 20) & 1;
  v98 = (uint8_t)v97 >> 4;
  v100 = (v99 >> 7) & 1;
  v102 = (v101 >> 4) & 7;
  v104 = (v103 >> 10) & 1;
  v106 = (v105 >> 8) & 3;
  v108 = (v107 >> 2) & 7;
  v149 = (v141 >> 22) & 1;
  v148 = (v139 >> 21) & 1;
  v110 = (v109 >> 6) & 1;
  v112 = (v111 >> 12) & 7;
  v114 = (v113 >> 23) & 1;
  v116 = (v115 >> 22) & 1;
  v118 = (v117 >> 20) & 1;
  v120 = (v119 >> 21) & 1;
  v122 = (v121 >> 17) & 1;
  v124 = HIWORD(v123) & 1;
  v126 = (v125 >> 15) & 1;
  v128 = (v127 >> 14) & 1;
  v130 = (v129 >> 18) & 1;
  v132 = (v131 >> 12) & 3;
  v134 = v133 & 3;
  v136 = (v135 >> 18) & 7;
  v138 = (v137 >> 2) & 1;
  v140 = (v17 >> 23) & 1;
  v142 = (v18 >> 22) & 1;
  v144 = (v86 >> 18) & 1;
  v145 = (v19 >> 8) & 1;
  v143 = (v86 >> 19) & 1;
  *v15 |= 0x400000u;
  a4 = (a4 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    a4 = (uint8_t)(a4 - 1);
  while ( a4 );
  v24 = (void *)(uintptr_t)(off_1062B8);
  *(volatile uint32_t *)off_1062B8 &= ~0x100000u;
  *(volatile uint32_t *)v24 |= 0x200000u;
  v24 = (void *)(uintptr_t)(((uintptr_t)(v24) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v24 = (void *)(uint8_t)((uint8_t)v24 - 1);
  while ( v24 );
  v25 = (void *)(uintptr_t)(off_1062B0);
  *(volatile uint32_t *)off_1062B8 |= 0x100000u;
  *(volatile uint32_t *)v25 |= 0x20000u;
  *(volatile uint32_t *)v25 |= 0x10000u;
  v25 = (void *)(uintptr_t)(((uintptr_t)(v25) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v25 = (void *)(uint8_t)((uint8_t)v25 - 1);
  while ( v25 );
  v26 = (void *)(uintptr_t)(off_106470);
  *(volatile uint32_t *)off_106470 &= ~0x40000u;
  *(volatile uint32_t *)v26 |= 0x80000u;
  v26 = (void *)(uintptr_t)(((uintptr_t)(v26) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v26 = (void *)(uint8_t)((uint8_t)v26 - 1);
  while ( v26 );
  v27 = (void *)(uintptr_t)(off_106470);
  *(volatile uint32_t *)off_106470 |= 0x40000u;
  *v27 |= 0x8000u;
  *v27 |= 0x4000u;
  v28 = (v28 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    v28 = (uint8_t)(v28 - 1);
  while ( v28 );
  v29 = (void *)(uintptr_t)(off_106474);
  v30 = (void *)(uintptr_t)(off_106478);
  v31 = (volatile unsigned int *)off_10647C;
  v32 = (void *)(uintptr_t)(off_106480);
  *(volatile uint32_t *)off_106474 |= 0x40000u;
  *v30 |= 0x3000u;
  v33 = (void *)(uintptr_t)(off_106470);
  *v31 = *v31 & 0xFFFFFFFC | 1;
  v29[16] = v29[16] & 0xFFE3FFFF | 0xC0000;
  *v31 |= 4u;
  *v33 |= 0x800000u;
  *v33 |= 0x400000u;
  *v32 &= ~0x100u;
  disable_bb_timer_irq();
  bb_hw_init();
  v34 = (void *)(uintptr_t)(off_106488);
  *(volatile uint32_t *)off_106484 |= 0x10000000u;
  *v34 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v161 = (a1 >> 12) & 3;
      *(volatile uint32_t *)off_106A60 = a1;
      if ( v161 == 1 )
      {
        v162 = 0;
        v163 = *(volatile uint32_t *)off_106BA4;
        v157 = -2;
        v87 = 31;
        v156 = 1;
        v152 = 1;
        v61 = 4;
        v63 = 0x7FFFFFFF;
        v160 = 3;
        v150 = 1;
        v154 = 0x7FFFFFFF;
        v155 = 4;
        v62 = 0;
      }
      else
      {
        if ( v161 == 2 )
        {
          v163 = *(volatile uint32_t *)(uintptr_t)(off_106BA8);
          v156 = dword_106BB0;
          v157 = dword_106BAC;
        }
        else
        {
          v163 = *(volatile uint32_t *)(uintptr_t)(off_106A64);
          v156 = dword_106A6C;
          v157 = dword_106A68;
        }
        v61 = 8;
        a7 = 2;
        v62 = 2;
        v87 = 13;
        v152 = -1;
        v154 = -122881;
        v160 = 15;
        v150 = -13;
        v162 = 8;
        v63 = 0x1FFF;
        v155 = 16;
      }
      v64 = (*(volatile uint32_t *)off_106A60 >> 8) & 0xF;
      v65 = (v161 << 8) + dword_106A70;
      v164 = v65;
      check_interrupt_flag(1, "tx_gain_reg=%x,apc_table=%d,ampm_index=%x\n", *(volatile uint32_t *)off_106A60, v161, v64);
      *(volatile uint32_t *)(a2 + 140) = *(volatile uint32_t *)(a2 + 152);
      load_device_desc(a2, 0);
      v66 = 0;
      check_interrupt_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d \n", *(volatile uint32_t *)off_106A60, v64, 0);
      v153 = v62;
      v67 = v64;
      v68 = v65 + 16 * v64;
      v69 = (volatile int *)(v68 + v162);
      v70 = (volatile uint32_t *)(v68 + v61);
      v158 = v63;
      v165 = v61;
      v159 = 0;
      v71 = 0;
      v72 = v67;
      v73 = 2 * v67;
      do
      {
        gpio_set_pin(1);
        if ( a7 == v153 )
        {
          *v69 = *v69 & v154 | ((v160 & v66) << v87);
        }
        else
        {
          *v69 &= v158;
          *v70 &= v157;
          *v69 |= (v152 & v66) << v87;
          *v70 |= (v66 >> v150) & v156;
        }
        gpio_clear_pin(1);
        prcm_set_mask((uint16_t)*a3, a2, v72, 0);
        check_interrupt_flag(1, "tone_amp[0]=%x,pwr_back[%2d]=%d ", *a3, v66, *(volatile uint16_t *)(a2 + v73));
        check_interrupt_flag(1, "wf_pa_5g_input_2_cbit=%d  ", (*(volatile uint32_t *)off_106A80 >> 21) & 3);
        check_interrupt_flag(1, "wf_dtmx_tuning_cbit=%d\n", (*(volatile uint32_t *)off_106A88 >> 15) & 0xF);
        if ( *(volatile uint16_t *)(a2 + v73) > v71 )
        {
          v71 = *(volatile uint16_t *)(a2 + v73);
          v159 = v66;
        }
        ++v66;
      }
      while ( v155 != v66 );
      if ( (*(volatile uint8_t *)off_106A94 & 0xC0) != 0xC0 && a8 > 2 && v161 == 1 )
      {
        if ( a8 == 6 )
          v84 = 1;
        else
          v84 = 2;
        v85 = v159 + v84;
        if ( v85 >= 3 )
          v85 = 3;
        v159 = v85;
      }
      check_interrupt_flag(1, "cbit_val=%d\n", v159);
      gpio_set_pin(1);
      v77 = v87;
      v88 = (v159 >> v150) & v156;
      v78 = (v152 & v159) << v77;
      v151 = (v159 & v160) << v77;
      v79 = (volatile int *)(v164 + v162);
      v80 = (volatile int *)(v162 + 192 + v163);
      v81 = (volatile int *)(v163 + v162);
      v82 = v165 - v162;
      do
      {
        while ( 1 )
        {
          v83 = &v81[v162 / 0xFFFFFFFC];
          if ( a7 == v153 )
            break;
          *v79 &= v158;
          *(volatile int *)((volatile char *)v79 + v82) &= v157;
          *v79 |= v78;
          *(volatile int *)((volatile char *)v79 + v82) |= v88;
          *v81 &= v158;
          *(volatile int *)((volatile char *)v83 + v165) &= v157;
          *v81 |= v78;
          v81 += 3;
          *(volatile int *)((volatile char *)v83 + v165) |= v88;
          v79 += 4;
          if ( v81 == v80 )
            goto LABEL_53;
        }
        *v79 = *v79 & v154 | v151;
        *v81 = *v81 & v154 | v151;
        v81 += 3;
        v79 += 4;
      }
      while ( v81 != v80 );
LABEL_53:
      gpio_clear_pin(1);
      check_interrupt_flag(1, "use wf_pa_5g_input_2_cbit=%d  ", (*(volatile uint32_t *)off_106B94 >> 21) & 3);
      check_interrupt_flag(1, "use wf_dtmx_tuning_cbit=%d\n", (*(volatile uint32_t *)off_106B9C >> 15) & 0xF);
    }
    goto LABEL_28;
  }
  if ( v20 )
  {
    v74 = (volatile unsigned int *)off_106A60;
    *(volatile uint32_t *)off_106A60 = a1;
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    v75 = *v74;
    load_device_desc(a2, 0);
    v76 = (v75 >> 8) & 0xF;
    check_interrupt_flag(1, "tx_gain_map_reg=%x  ana_index=%x base=%d ", *v74, v76, 0);
    prcm_set_mask((uint16_t)*a3, a2, v76, 0);
    goto LABEL_28;
  }
  *(volatile uint64_t *)(a2 + 168) = 0xFFFFFFECFFFFFFFELL;
  v35 = a3 - 1;
  v36 = (volatile uint32_t *)(a2 + 140);
  do
  {
    if ( v20 == 2 )
    {
      v37 = *(volatile uint32_t *)(a2 + 124);
LABEL_18:
      v38 = -5;
      goto LABEL_19;
    }
    if ( v20 == 1 )
    {
      v37 = *(volatile uint32_t *)(a2 + 120);
      goto LABEL_18;
    }
    v37 = *(volatile uint32_t *)(a2 + 112);
    if ( a5 || v37 <= 12 )
      goto LABEL_18;
    v38 = -10;
LABEL_19:
    *(volatile uint32_t *)(a2 + 164) = v38;
    *v36 = v36[3];
    ++v36;
    validate_handle(a1, v37, a5, a2, a6);
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    load_device_desc(a2, v20);
    v39 = (uint16_t)v35[1];
    ++v35;
    prcm_set_mask(v39, a2, v37, v20);
    v40 = v20;
    v41 = *(volatile uint16_t *)(a2 + 2 * (v37 + 16 * v20++));
    malloc_wrapper(a2, v41, v40);
  }
  while ( v20 != 3 );
  v42 = *(volatile uint32_t *)(a2 + 132);
  if ( v42 <= (int)*(volatile uint32_t *)(a2 + 112) )
  {
    v43 = (void *)(uintptr_t)(off_106480);
    v44 = (void *)(uintptr_t)(off_10648C);
    do
    {
      while ( 1 )
      {
        validate_handle(a1, v42, a5, a2, a6);
        v45 = *(volatile uint32_t *)(a2 + 124);
        *v43 &= ~0x200u;
        *v43 |= 0x200u;
        *v43 &= ~0x200u;
        if ( v45 < v42 )
          break;
        load_device_desc(a2, 2);
        check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 2);
        prcm_set_mask((uint16_t)a3[2], a2, v42, 2);
        if ( (int)*(volatile uint32_t *)(a2 + 124) <= v42 )
          break;
LABEL_26:
        if ( (int)*(volatile uint32_t *)(a2 + 120) <= v42 )
          goto LABEL_23;
        if ( *(volatile uint32_t *)(a2 + 112) < ++v42 )
          goto LABEL_28;
      }
      if ( (int)*(volatile uint32_t *)(a2 + 120) >= v42 )
      {
        load_device_desc(a2, 1);
        check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 1);
        prcm_set_mask((uint16_t)a3[1], a2, v42, 1);
        goto LABEL_26;
      }
LABEL_23:
      load_device_desc(a2, 0);
      check_interrupt_flag(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 0);
      prcm_set_mask((uint16_t)*a3, a2, v42++, 0);
    }
    while ( (int)*(volatile uint32_t *)(a2 + 112) >= v42 );
  }
LABEL_28:
  v46 = (volatile unsigned int *)off_1067B0;
  v47 = (volatile unsigned int *)off_1067B4;
  v48 = (volatile unsigned int *)off_1067D8;
  v49 = (volatile unsigned int *)off_1067DC;
  v50 = (void *)(uintptr_t)(off_1067D4);
  *(volatile uint32_t *)off_1067B0 = *(volatile uint32_t *)off_1067B0 & 0xFFBFFFFF | (v149 << 22);
  *v46 = *v46 & 0xFFDFFFFF | (v148 << 21);
  disable_rx_path();
  v51 = (void *)(uintptr_t)(off_1067B8);
  v52 = (volatile unsigned int *)off_1067BC;
  v53 = (volatile unsigned int *)off_1067E0;
  *(volatile uint32_t *)off_1067B8 = *(volatile uint32_t *)off_1067B8 & 0xF8FFFFFF | (v92 << 24);
  v54 = (volatile unsigned int *)off_1067C0;
  *v47 = *v47 & 0xFFFFFFBF | (v110 << 6);
  v55 = (volatile unsigned int *)off_1067C4;
  *v52 = *v52 & 0xFFFF8FFF | (v112 << 12);
  v56 = (volatile unsigned int *)off_1067C8;
  v57 = (volatile unsigned int *)off_1067CC;
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFF7FFFFF | (v114 << 23);
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFBFFFFF | (v116 << 22);
  v58 = (volatile unsigned int *)off_1067D0;
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFEFFFFF | (v118 << 20);
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFDFFFFF | (v120 << 21);
  *v54 = *v54 & 0xFFFBFFFF | (v144 << 18);
  v59 = (void *)(uintptr_t)(off_1067E4);
  *v54 = *v54 & 0xFFF7FFFF | (v143 << 19);
  *v54 = *v54 & 0xFFFDFFFF | (v122 << 17);
  *v54 = *v54 & 0xFFFEFFFF | (v124 << 16);
  *v54 = *v54 & 0xFFFF7FFF | (v126 << 15);
  *v54 = *v54 & 0xFFFFBFFF | (v128 << 14);
  *v55 = *v55 & 0xFFFBFFFF | (v130 << 18);
  *v48 = *v48 & 0xFFFFCFFF | (v132 << 12);
  *v56 = *v56 & 0xFFFFFFFC | v134;
  *v57 = *v57 & 0xFFE3FFFF | (v136 << 18);
  *v56 = *v56 & 0xFFFFFFFB | (4 * v138);
  *v54 = *v54 & 0xFF7FFFFF | (v140 << 23);
  *v54 = *v54 & 0xFFBFFFFF | (v142 << 22);
  *v53 = *v53 & 0xFFFFFFDF | (32 * v90);
  *v54 = *v54 & 0xFFDFFFFF | (v94 << 21);
  *v54 = *v54 & 0xFFEFFFFF | (v96 << 20);
  *v56 = *v56 & 0xFFFFFF0F | (16 * v98);
  *v58 = *v58 & 0xFFFFFF7F | (v100 << 7);
  *v58 = *v58 & 0xFFFFFF8F | (16 * v102);
  *v58 = *v58 & 0xFFFFFBFF | (v104 << 10);
  *v58 = *v58 & 0xFFFFFCFF | (v106 << 8);
  *v53 = *v53 & 0xFFFFFFE3 | (4 * v108);
  *v46 &= 0xFFFE00FF;
  *v46 &= ~0x20000u;
  *v46 |= 0x40000u;
  *v49 = *v49 & 0x7FFFFFFF | v147 & 0x80000000;
  *v50 = v146;
  *(v51 - 1902) = *(v51 - 1902) & 0xFFFFFEFF | (v145 << 8);
  *v59 |= 0x400u;
  *v59 &= ~0x400u;
  return v106;
}


// clk_enable @ 0x106bb4
volatile int *clk_enable() {
  volatile unsigned int *v0; // r4
  volatile uint32_t *v1; // r6
  volatile unsigned int *v2; // r5
  volatile uint32_t *v3; // r2
  int v4; // r1
  int v5; // r4
  volatile unsigned int *v6; // r3
  volatile uint32_t *v7; // r1
  volatile int *result; // r0
  int v9; // r2
  volatile int *v10; // r1
  volatile unsigned int *v11; // r3

  v0 = (volatile unsigned int *)off_106D8C;
  *(volatile uint32_t *)off_106D88 |= 0x2000000u;
  v1 = (void *)(uintptr_t)(off_106D90);
  v2 = (volatile unsigned int *)off_106D94;
  *v0 &= ~0x20000u;
  write_timer_reg(2);
  v3 = (void *)(uintptr_t)(off_106D98);
  v4 = dword_106D9C;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v1 |= 0x80000000;
  *v3 = v4;
  *v0 |= 0x80000u;
  *v0 &= ~0x40000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  v5 = dword_106DA0;
  *v2 &= ~0x40u;
  v3 -= 129;
  *v2 &= ~0x80u;
  *v3 |= 0x10000000u;
  *v3 = *v3 & 0xFC000FFF | 0x666000;
  *v3 = *v3 & 0xFFFFF000 | 0xC0;
  write_timer_reg(10);
  v6 = (volatile unsigned int *)off_106DA4;
  v7 = (void *)(uintptr_t)(off_106DA8);
  result = (volatile int *)off_106DAC;
  *(volatile uint32_t *)off_106DA4 &= ~2u;
  *v7 |= 0x1000000u;
  v9 = dword_106DB0;
  *v6 = *v6 & 0x8FFFFFFF | 0x20000000;
  *v6 &= 0xF8FFFFFF;
  *v6 = *v6 & 0xFFFFFF8F | 0x40;
  v10 = (volatile int *)off_106DB4;
  *v2 = *v2 & 0xFFF8FFFF | 0x20000;
  *v2 = *v2 & 0xFFFF8FFF | 0x2000;
  *v2 = *v2 & 0xFFFFF0FF | 0x600;
  *result = *result & v9 | 0x351D;
  *result = *result & v5 | 0xF9F0000;
  *v10 = *v10 & v9 | 0x375C;
  *v10 = *v10 & v5 | 0xF9D0000;
  result[2] = result[2] & v9 | 0x35BB;
  result[2] = result[2] & v5 | 0xF060000;
  v10[2] = v10[2] & v9 | 0x3719;
  v10[2] = v10[2] & v5 | 0xF020000;
  v11 = (volatile unsigned int *)off_106DB8;
  result[4] = result[4] & v9 | 0x367A;
  result[4] = result[4] & v5 | 0xECA0000;
  *v11 = *v11 & 0xFFF0FFFF | 0x10000;
  *v11 = *v11 & 0xFFFF0FFF | 0x1000;
  *v11 = *v11 & 0xFFFFF0FF | 0x100;
  *v11 = *v11 & 0xFFFFFF0F | 0x10;
  *v11 = *v11 & 0xFFFFFFF0 | 1;
  *v1 &= ~0x4000u;
  return result;
}



// clk_disable @ 0x106dbc
volatile uint32_t *clk_disable() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2
  volatile uint32_t *v2; // r3
  volatile unsigned int *v3; // r4
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r1
  volatile uint32_t *v7; // r2

  result = (void *)(uintptr_t)(off_106EE8);
  v1 = (volatile unsigned int *)off_106EEC;
  v2 = (void *)(uintptr_t)(off_106EF0);
  *(volatile uint32_t *)off_106EE8 &= ~0x80000000;
  v3 = (volatile unsigned int *)off_106EF4;
  v4 = (void *)(uintptr_t)(off_106EF8);
  v5 = (void *)(uintptr_t)(off_106EFC);
  *v1 = *v1 & 0xFFFF0FFF | 0xA000;
  *v2 &= 0xCFFFFFFF;
  *v2 &= ~0x40000000u;
  *v3 = *v3 & 0xF8FFFFFF | 0x5000000;
  *v3 = *v3 & 0xFFFFFF8F | 0x50;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v1 &= ~0x20000u;
  *v1 &= ~0x10000u;
  v6 = (void *)(uintptr_t)(off_106F00);
  *v4 &= ~0x10000000u;
  *v2 |= 0x400000u;
  *v2 |= 0x800000u;
  *v2 |= 0x200000u;
  *v2 |= 0x100000u;
  *v2 &= ~0x40u;
  *v5 &= ~0x1000000u;
  *v6 &= ~0x2000000u;
  *(volatile unsigned int *)((volatile char *)v3 + 0xFFFFFF5C) &= ~0x20000000u;
  v7 = (void *)(uintptr_t)(off_106F04);
  v4[128] &= ~0x200u;
  v6[49] &= 0xC0FFFFFF;
  v6[49] &= 0xFFC0FFFF;
  v6[49] &= 0xFFFFC0FF;
  v6[49] &= 0xFFFFFFC0;
  *v7 &= 0xC0FFFFFF;
  *v7 &= 0xFFC0FFFF;
  *v7 &= 0xFFFFC0FF;
  *v7 &= 0xFFFFFFC0;
  *v2 &= 0xFFFFFFC0;
  *result |= 0x4000u;
  return result;
}



// clk_set_divider @ 0x106f08
volatile uint32_t *clk_set_divider() {
  volatile unsigned int *v0; // r2
  volatile uint32_t *v1; // r3
  volatile uint32_t *result; // r0

  v0 = (volatile unsigned int *)off_106F68;
  v1 = (void *)(uintptr_t)(off_106F6C);
  result = (void *)(uintptr_t)(off_106F70);
  *(volatile uint32_t *)off_106F68 = *(volatile uint32_t *)off_106F68 & 0xC0FFFFFF | 0x3000000;
  *v0 = *v0 & 0xFFC0FFFF | 0x30000;
  *v0 = *v0 & 0xFFFFC0FF | 0x300;
  *v0 = *v0 & 0xFFFFFFC0 | 3;
  *v1 &= 0xC0FFFFFF;
  *v1 &= 0xFFC0FFFF;
  *v1 &= 0xFFFFC0FF;
  *v1 &= 0xFFFFFFC0;
  *result &= 0xFFFFFFC0;
  return result;
}



// pinmux_config @ 0x106f74
int pinmux_config(int a1, int a2) {
  volatile unsigned int *v2; // r5
  volatile unsigned int *v3; // r4
  volatile uint32_t *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (volatile unsigned int *)off_107054;
  v3 = (volatile unsigned int *)off_107058;
  *(volatile uint32_t *)off_107054 = *(volatile uint32_t *)off_107054 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  clk_set_divider();
  *v2 &= ~1u;
  write_timer_reg(140);
  v5 = (void *)(uintptr_t)(off_10705C);
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(volatile uint32_t *)(a1 + 44) = v6;
  write_timer_reg(5);
  check_interrupt_flag(1, "rd_pwr=%4d  ", *(volatile uint32_t *)(a1 + 44));
  result = check_interrupt_flag(1, (const volatile char *)off_107064);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}


// gpio_output @ 0x107068
int gpio_output(int a1, int a2) {
  volatile uint32_t *v2; // r5
  volatile unsigned int *v3; // r4
  volatile uint32_t *v5; // r2
  int v6; // r2
  int result; // r0

  v2 = (void *)(uintptr_t)(off_10713C);
  v3 = (volatile unsigned int *)off_107140;
  *(volatile uint32_t *)off_10713C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  clk_set_divider();
  *v2 &= ~1u;
  write_timer_reg(100);
  v5 = (void *)(uintptr_t)(off_107144);
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(volatile uint32_t *)(a1 + 44) = v6;
  check_interrupt_flag(1, "lpf_bypass_pwr=%4d   ", v6);
  write_timer_reg(5);
  result = check_interrupt_flag(1, (const volatile char *)off_10714C);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  return result;
}


// load_patch_bundle @ 0x107150
int load_patch_bundle(int a1) {
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r8
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r6
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r6
  volatile int *v23; // r7
  volatile unsigned int *v24; // lr
  int v25; // r4
  int v26; // r8
  volatile unsigned int *v27; // r5
  int v28; // r0
  struct __attribute__((packed)) { int v30; // [sp+0h] [bp-60h]
  int v31; // [sp+4h] [bp-5Ch]
  int v32; // [sp+8h] [bp-58h]
  int v33; // [sp+Ch] [bp-54h]
  int v34; // [sp+10h] [bp-50h]
  int v35; // [sp+14h] [bp-4Ch]
  int v36; // [sp+18h] [bp-48h]
  int v37; // [sp+1Ch] [bp-44h]
  int v38; // [sp+20h] [bp-40h]
  int v39; // [sp+24h] [bp-3Ch]
  int v40; // [sp+28h] [bp-38h]
  int v41; // [sp+2Ch] [bp-34h]
  int v42; // [sp+30h] [bp-30h]
  int v43; // [sp+34h] [bp-2Ch]
  int v44; // [sp+38h] [bp-28h]
  int v45; // [sp+3Ch] [bp-24h]
  int v46; // [sp+40h] [bp-20h]
  int v47; // [sp+44h] [bp-1Ch]
  int v48; // [sp+48h] [bp-18h]
  int v49; // [sp+4Ch] [bp-14h]
  int v50; // [sp+50h] [bp-10h]
  int v51; // [sp+54h] [bp-Ch]
  int v52; // [sp+58h] [bp-8h]
  int v53; // [sp+5Ch] [bp-4h]
  int v54; // [sp+60h] [bp+0h] BYREF
  } _frame;
  v2 = ((volatile uint32_t *)(uintptr_t)off_107200)[99];
  v3 = ((volatile uint32_t *)(uintptr_t)off_107200)[100];
  v4 = ((volatile uint32_t *)(uintptr_t)off_107200)[101];
  _frame.v30 = ((volatile uint32_t *)(uintptr_t)off_107200)[98];
  _frame.v31 = v2;
  _frame.v32 = v3;
  _frame.v33 = v4;
  v5 = ((volatile uint32_t *)(uintptr_t)off_107200)[103];
  v6 = ((volatile uint32_t *)(uintptr_t)off_107200)[104];
  v7 = ((volatile uint32_t *)(uintptr_t)off_107200)[105];
  _frame.v34 = ((volatile uint32_t *)(uintptr_t)off_107200)[102];
  _frame.v35 = v5;
  _frame.v36 = v6;
  _frame.v37 = v7;
  v8 = ((volatile uint32_t *)(uintptr_t)off_107200)[107];
  v9 = ((volatile uint32_t *)(uintptr_t)off_107200)[108];
  v10 = ((volatile uint32_t *)(uintptr_t)off_107200)[109];
  _frame.v38 = ((volatile uint32_t *)(uintptr_t)off_107200)[106];
  _frame.v39 = v8;
  _frame.v40 = v9;
  _frame.v41 = v10;
  v11 = ((volatile uint32_t *)(uintptr_t)off_107200)[111];
  v12 = ((volatile uint32_t *)(uintptr_t)off_107200)[112];
  v13 = ((volatile uint32_t *)(uintptr_t)off_107200)[113];
  _frame.v42 = ((volatile uint32_t *)(uintptr_t)off_107200)[110];
  _frame.v43 = v11;
  _frame.v44 = v12;
  _frame.v45 = v13;
  v14 = *(volatile uint32_t *)(a1 + 8);
  v15 = ((volatile uint32_t *)(uintptr_t)off_107200)[115];
  v16 = ((volatile uint32_t *)(uintptr_t)off_107200)[116];
  v17 = ((volatile uint32_t *)(uintptr_t)off_107200)[117];
  v18 = ((uint64_t)((int32_t)dword_107204 * (int64_t)(int32_t)(*(volatile int *)(a1 + 4))) >> 32) - (*(volatile int *)(a1 + 4) >> 31);
  _frame.v46 = ((volatile uint32_t *)(uintptr_t)off_107200)[114];
  _frame.v47 = v15;
  _frame.v48 = v16;
  _frame.v49 = v17;
  if ( v18 >= (int)(((uint64_t)((int32_t)dword_107204 * (int64_t)(int32_t)(v14)) >> 32) - (v14 >> 31)) )
    v18 = ((uint64_t)((int32_t)dword_107204 * (int64_t)(int32_t)(v14)) >> 32) - (v14 >> 31);
  v19 = ((volatile uint32_t *)(uintptr_t)off_107200)[119];
  v20 = ((volatile uint32_t *)(uintptr_t)off_107200)[120];
  v21 = ((volatile uint32_t *)(uintptr_t)off_107200)[121];
  v22 = v18 & ~(v18 >> 31);
  v23 = &_frame.v54 + v22;
  v24 = (volatile unsigned int *)off_107210;
  v25 = *(v23 - 24);
  v26 = *(volatile uint32_t *)off_107210;
  _frame.v50 = ((volatile uint32_t *)(uintptr_t)off_107200)[118];
  _frame.v51 = v19;
  _frame.v52 = v20;
  _frame.v53 = v21;
  v27 = (volatile unsigned int *)off_107208;
  v28 = *(v23 - 12);
  *(volatile uint32_t *)(a1 + 8) = 3 * v22;
  *v24 = (v25 << 12) & 0x7000 | v26 & 0xFFFF8FFF;
  *v27 |= 0x400u;
  *v27 = (v28 << 8) & 0x300 | *v27 & 0xFFFFFCFF;
  return check_interrupt_flag(1, "index=%d shift_idx=%d\n", v22, 3 * v22);
}


// rf_core_cmd_post @ 0x107214
int rf_core_cmd_post(int a1, volatile uint32_t *a2, int a3) {
  int v3; // r8
  int v7; // s15
  int v8; // r2
  int v9; // r2

  v3 = *(volatile uint32_t *)(a3 + 8);
  check_interrupt_flag(1, "gain_base=%d\n", v3);
  check_interrupt_flag(1, "pwr_hih=%d\n", a1);
  v7 = (int)(float)(COERCE_FLOAT(float_to_double(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(a1, 0xEu)))) * 10.0);
  check_interrupt_flag(1, "pwr_db=%d\n", v7);
  v8 = a2[8];
  if ( v8 < v7 )
  {
    check_interrupt_flag(1, "sat> %d \n", v8);
    v9 = a2[9];
    if ( v9 <= v7 )
      goto LABEL_3;
LABEL_5:
    check_interrupt_flag(1, "sma %d\n", v9);
    goto LABEL_3;
  }
  v9 = a2[9];
  if ( v9 > v7 )
    goto LABEL_5;
LABEL_3:
  *(volatile uint32_t *)(a3 + 8) = (int)COERCE_FLOAT(branch_to_127228(COERCE_INT((float)(unsigned int)(a2[7] - v7 + v3))));
  return load_patch_bundle(a3);
}


// rf_core_irq_clear @ 0x1072cc
int rf_core_irq_clear(int a1, volatile uint32_t *a2, int a3) {
  volatile uint32_t *v3; // r5
  volatile unsigned int *v4; // r4
  volatile int *v5; // r6
  int v6; // r8
  int v7; // r7
  uint64_t v8; // kr00_8
  int v9; // r3
  volatile int *v10; // r0
  int v11; // r0
  unsigned int v12; // r3
  int result; // r0

  v3 = (void *)(uintptr_t)(off_1073A0);
  v4 = (volatile unsigned int *)off_1073A4;
  v5 = (volatile int *)off_1073A8;
  v6 = dword_1073B8;
  v7 = dword_1073AC;
  v8 = *(volatile uint64_t *)(a1 + 8);
  clk_set_divider();
  *v3 &= ~1u;
  write_timer_reg(20);
  v9 = dword_1073B0;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  write_timer_reg(40);
  v10 = (volatile int *)off_1073B4;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  v12 = *v4 & 0xFFDFFFFF;
  *v4 = v12;
  result = ((int (*)())rf_core_cmd_post)(v11 & 0x7FFF, a2, a3, v12);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}



// timer_delta_compare @ 0x1073bc
int timer_delta_compare(volatile unsigned int *a1, int a2) {
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15

  v2 = *a1;
  if ( *a1 < a1[1] )
    v2 = a1[1];
  v3 = a1[3];
  if ( !v2 )
    v2 = 1;
  if ( v2 < a1[2] )
    v2 = a1[2];
  if ( v3 < v2 )
    v3 = v2;
  v5 = *(volatile uint32_t *)(a2 + 8);
  check_interrupt_flag(1, "pwr_hih=%d\n", v3);
  v6 = (int)(float)(COERCE_FLOAT(float_to_double(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(v3, 0xFu)))) * 10.0);
  check_interrupt_flag(1, "pwr_db=%d\n", v6);
  if ( v6 >= -1 )
  {
    check_interrupt_flag(1, "sat> %d \n", -2);
  }
  else if ( v6 < -30 )
  {
    check_interrupt_flag(1, "sma %d\n", -30);
  }
  *(volatile uint32_t *)(a2 + 8) = (int)COERCE_FLOAT(branch_to_127228(COERCE_INT((float)(~v6 + v5))));
  return load_patch_bundle(a2);
}


// rf_core_irq_poll @ 0x10747c
int rf_core_irq_poll(int a1) {
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r6
  volatile int *v3; // r5
  int v4; // r7
  volatile uint32_t *v5; // r11
  unsigned int v7; // r3
  int v8; // cc
  int v9; // r2
  int v10; // r3
  int v11; // r9
  int v12; // r10
  int result; // r0
  struct __attribute__((packed)) { int v14; // [sp+1Ch] [bp-18h]
  unsigned int a1a; // [sp+20h] [bp-14h] BYREF
  unsigned int v16; // [sp+24h] [bp-10h]
  int v17; // [sp+28h] [bp-Ch]
  int v18; // [sp+2Ch] [bp-8h]
  } _frame;
  v1 = (void *)(uintptr_t)(off_10761C);
  v2 = (void *)(uintptr_t)(off_107620);
  v3 = (volatile int *)off_107624;
  v4 = dword_107628;
  v5 = (void *)(uintptr_t)(off_107634);
  load_patch_bundle(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  check_interrupt_flag(1, aAdjI);
  clk_set_divider();
  *v2 &= ~1u;
  write_timer_reg(20);
  *v2 |= 4u;
  *v2 |= 8u;
  write_timer_reg(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  _frame.a1a = v7;
  *v3 = *v3 & v4 | 0x4000000;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  _frame.v16 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v8 = _frame.a1a > _frame.v16;
  if ( _frame.a1a <= _frame.v16 )
    v9 = 234881024;
  else
    v9 = 100663296;
  *v3 = *v3 & v4 | v9;
  if ( v8 )
    v10 = 1536;
  else
    v10 = 3584;
  if ( v8 )
    v11 = 0x2000000;
  else
    v11 = 167772160;
  if ( v8 )
    v12 = 512;
  else
    v12 = 2560;
  _frame.v14 = v10;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  _frame.v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v11;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  _frame.v18 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  check_interrupt_flag(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, _frame.a1a, 1024, _frame.v16, _frame.v14, _frame.v17, v12, _frame.v18);
  result = timer_delta_compare(&_frame.a1a, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}


// rf_core_irq_dispatch @ 0x107638
int rf_core_irq_dispatch(int a1) {
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r5
  volatile int *v3; // r8
  int v4; // r9
  volatile int *v5; // r6
  volatile uint32_t *v6; // r10
  volatile int *v8; // r5
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r6
  int v12; // cc
  volatile uint32_t *v13; // r4
  int v14; // r3
  int v15; // r11
  int v16; // r8
  int result; // r0
  volatile uint32_t *v18; // r3
  struct __attribute__((packed)) { unsigned int a1a; // [sp+18h] [bp-14h] BYREF
  unsigned int v20; // [sp+1Ch] [bp-10h]
  int v21; // [sp+20h] [bp-Ch]
  int v22; // [sp+24h] [bp-8h]
  } _frame;
  v1 = (void *)(uintptr_t)(off_1077DC);
  v2 = (void *)(uintptr_t)(off_1077E0);
  v3 = (volatile int *)off_1077EC;
  v4 = dword_1077F0;
  v5 = (volatile int *)off_1077E4;
  v6 = (void *)(uintptr_t)(off_1077E4);
  load_patch_bundle(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  check_interrupt_flag(1, aAdjQ);
  clk_set_divider();
  *v2 &= ~1u;
  write_timer_reg(20);
  *v2 |= 4u;
  *v2 |= 8u;
  write_timer_reg(20);
  v8 = (volatile int *)off_1077EC;
  *v1 |= 0x400000u;
  *v3 = *v3 & v4 | 0xC00;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v9 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  _frame.a1a = v9;
  *v3 = *v3 & v4 | 0x400;
  write_timer_reg(20);
  *v1 |= 0x4000000u;
  v10 = *v5;
  v11 = dword_1077F0;
  _frame.v20 = v10 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v12 = _frame.a1a > _frame.v20;
  v13 = (void *)(uintptr_t)(off_1077DC);
  if ( _frame.a1a > _frame.v20 )
    v14 = 1536;
  else
    v14 = 3584;
  *v8 = *v8 & v11 | v14;
  if ( v12 )
    v15 = 512;
  else
    v15 = 2560;
  v16 = v14;
  write_timer_reg(20);
  *v13 |= 0x4000000u;
  _frame.v21 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v8 = *v8 & v11 | v15;
  write_timer_reg(20);
  *v13 |= 0x4000000u;
  _frame.v22 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v13 &= ~0x400000u;
  check_interrupt_flag(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, _frame.a1a, 1024, _frame.v20, v16, _frame.v21, v15, _frame.v22);
  result = timer_delta_compare(&_frame.a1a, a1);
  v18 = (void *)(uintptr_t)(off_1077E0);
  *(volatile uint32_t *)off_1077E0 &= ~4u;
  *v18 &= ~8u;
  *v8 &= v11;
  *v13 &= ~0x1000000u;
  *v13 &= ~0x2000000u;
  return result;
}


// rf_clear_irq_flag @ 0x1077f8
int rf_clear_irq_flag() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r2
  int v4; // r3

  v0 = (void *)(uintptr_t)(off_107854);
  clk_set_divider();
  *v0 &= ~1u;
  write_timer_reg(1);
  v1 = (void *)(uintptr_t)(off_107858);
  *(volatile uint32_t *)off_107858 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = write_timer_reg(1);
  v3 = (void *)(uintptr_t)(off_10785C);
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(volatile uint32_t *)off_107854 &= ~1u;
  return result;
}



// rf_clear_irq_flag_alt @ 0x107860
int rf_clear_irq_flag_alt() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r2
  int result; // r0
  volatile uint32_t *v3; // r2
  int v4; // r3

  v0 = (void *)(uintptr_t)(off_1078C8);
  clk_set_divider();
  *v0 &= ~1u;
  write_timer_reg(1);
  v1 = (void *)(uintptr_t)(off_1078CC);
  *(volatile uint32_t *)off_1078CC = *(volatile uint32_t *)off_1078CC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = write_timer_reg(1);
  v3 = (void *)(uintptr_t)(off_1078D0);
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(volatile uint32_t *)off_1078C8 &= ~1u;
  return result;
}



// timer_ticks_to_micros @ 0x1078d4
volatile int * timer_ticks_to_micros(volatile int *a1) {
  int v1; // r2
  int v2; // r7
  int v3; // r1
  int v4; // r12
  int v5; // r5
  int v6; // r6
  volatile int *result; // r0
  int i; // r4
  int v9; // r2
  volatile int *v10; // r3

  v1 = a1[1];
  v2 = ((uint64_t)((int32_t)dword_107940 * (int64_t)(int32_t)(v1)) >> 32) - (v1 >> 31);
  v3 = a1[3] - v1 / 2 + v2 + (v1 >> 31) - ((uint64_t)((int32_t)dword_10793C * (int64_t)(int32_t)(v1)) >> 32);
  v4 = ((uint64_t)((int32_t)dword_107940 * (int64_t)(int32_t)(*a1)) >> 32) - (*a1 >> 31);
  v5 = (*a1 >> 31) - ((uint64_t)((int32_t)dword_10793C * (int64_t)(int32_t)(*a1)) >> 32);
  v6 = a1[2] - *a1 / 2 + v4;
  result = a1 + 7;
  for ( i = 0; i != 9; i += 3 )
  {
    v9 = v6 + v5;
    v10 = result - 3;
    do
    {
      *v10++ = v9;
      v9 += v4;
      v10[8] = v3;
    }
    while ( v10 != result );
    v3 += v2;
    result = v10 + 3;
  }
  return result;
}



// rf_core_set_clock_override @ 0x107944
int rf_core_set_clock_override(int a1, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r6
  volatile unsigned int *v3; // r8
  int v4; // r7
  int v6; // r9
  volatile int *v7; // r4
  int v8; // r11
  int v9; // r10
  int v10; // r0
  int v11; // t1
  int v12; // r3
  int v13; // r2
  int v14; // r5
  volatile unsigned int *v15; // r3
  int v16; // r2
  int v18; // [sp+8h] [bp-1Ch]
  int v19; // [sp+Ch] [bp-18h]
  int v20; // [sp+10h] [bp-14h]
  int v21; // [sp+14h] [bp-10h]
  int v22; // [sp+18h] [bp-Ch]

  v2 = (void *)(uintptr_t)(off_107A58);
  v3 = (volatile unsigned int *)off_107A6C;
  *(volatile uint32_t *)off_107A58 |= 0x1000000u;
  v4 = 1;
  *v2 &= ~0x2000000u;
  v6 = 1000;
  check_interrupt_flag(1, &aAdjPwr[4]);
  v7 = (volatile int *)(a1 + 12);
  v21 = 1;
  v22 = 1;
  v19 = 1;
  v18 = 1;
  v20 = 1;
  v8 = 1;
  v9 = 1000;
  do
  {
    while ( 1 )
    {
      v10 = v7[10];
      v11 = v7[1];
      ++v7;
      *v3 = dword_107A60 & (v10 << 16) | *v3 & 0xF000FFFF;
      *v3 = v11 & 0xFFF | *v3 & 0xFFFFF000;
      write_timer_reg(40);
      v12 = v7[9];
      v13 = *v7;
      *v2 |= 0x4000000u;
      v14 = *(volatile uint32_t *)off_107A68 & 0x7FFF;
      *v2 &= ~0x4000000u;
      check_interrupt_flag(1, "am=%4d,ph=%4d,%d\n", v13, v12, v14);
      if ( v14 >= v6 )
        break;
      v21 = v19;
      v22 = v18;
      v19 = v7[9];
      v20 = v8;
      v9 = v6;
      v18 = *v7;
      v6 = v14;
      v8 = v4;
LABEL_3:
      if ( ++v4 == 10 )
        goto LABEL_7;
    }
    if ( v14 >= v9 )
      goto LABEL_3;
    v20 = v4++;
    v22 = *v7;
    v21 = v7[9];
    v9 = v14;
  }
  while ( v4 != 10 );
LABEL_7:
  v15 = (volatile unsigned int *)off_107A58;
  v16 = *(volatile uint32_t *)off_107A58;
  a2[5] = v18;
  a2[6] = v19;
  a2[7] = v22;
  a2[3] = v6;
  a2[8] = v21;
  a2[9] = v8;
  a2[4] = v9;
  a2[10] = v20;
  *v15 = v16 & 0xFEFFFFFF;
  *v15 &= ~0x2000000u;
  return v20;
}


// rx_queue_pop_packet @ 0x107a70
int rx_queue_pop_packet(int a1, volatile int *a2, int a3) {
  int v4; // r3
  uint64_t v5; // kr08_8
  int v6; // r2
  int v9; // r8
  int v10; // r7
  uint64_t v11; // r2
  int v12; // kr00_4
  int v13; // kr04_4
  uint64_t v14; // kr18_8
  int v16; // r12
  unsigned int v17; // r1
  int v18; // r4
  uint64_t v19; // kr20_8
  int v20; // r6
  int v21; // r12
  unsigned int v22; // r4
  int v23; // r6
  int v24; // r7

  v4 = *(volatile uint32_t *)(a3 + 4) - 1;
  v5 = *(volatile uint64_t *)(a1 + 36);
  v6 = *(volatile uint32_t *)(a1 + 12);
  if ( (int)*(volatile uint32_t *)a1 < v4 && v6 <= 49 )
  {
    check_interrupt_flag(1, aAdjPwr);
    rf_core_irq_clear((int)a2, (void *)(uintptr_t)(a3), a1);
    v6 = *(volatile uint32_t *)(a1 + 12);
  }
  if ( *(volatile uint32_t *)(a1 + 16) - v6 >= *(volatile uint32_t *)(a3 + 24) )
  {
LABEL_8:
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31)) << 32);
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31)) & 0xFFFFFFFFu);
    v14 = *(volatile uint64_t *)(a1 + 20);
    *(volatile uint64_t *)a2 = v11;
    goto LABEL_9;
  }
  v9 = ((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)((int)v5)) >> 32) - ((int)v5 >> 31);
  v10 = ((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(SHIDWORD(v5))) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v16 = *(volatile uint32_t *)(a1 + 32);
      v17 = *(volatile uint32_t *)(a1 + 20);
      v18 = ((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(2 * *(volatile uint32_t *)(a1 + 24))) >> 32)
          - ((2 * *(volatile uint32_t *)(a1 + 24)) >> 31);
      v19 = (int32_t)dword_107BCC * (int64_t)(int32_t)(v16);
      v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(2 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31))) << 32);
      v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31)) & 0xFFFFFFFFu);
      *(volatile uint64_t *)a2 = v11;
      v14 = __PAIR64__(v18 + HIDWORD(v19) - (v16 >> 31), v17);
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( v9 == v10 )
  {
    v20 = *(volatile uint32_t *)(a1 + 20);
    v21 = *(volatile uint32_t *)(a1 + 28);
    v22 = *(volatile uint32_t *)(a1 + 24);
    v23 = ((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(2 * v20)) >> 32) - ((2 * v20) >> 31);
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(2 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31))) & 0xFFFFFFFFu);
    v24 = ((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(v21)) >> 32) - (v21 >> 31);
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31)) << 32);
    *(volatile uint64_t *)a2 = v11;
    v14 = __PAIR64__(v22, v23 + v24);
  }
  else
  {
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(2 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31))) & 0xFFFFFFFFu);
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(2 * (((uint64_t)((int32_t)dword_107BCC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31))) << 32);
    v12 = *(volatile uint32_t *)(a1 + 20) + *(volatile uint32_t *)(a1 + 28);
    v13 = *(volatile uint32_t *)(a1 + 32) + *(volatile uint32_t *)(a1 + 24);
    *(volatile uint64_t *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((volatile uint64_t *)a2 + 1) = v14;
  return check_interrupt_flag(
           1,
           " update\n w=%4d\n l=%4d\n am=%5d\n ph=%5d\n",
           (uint32_t)v11,
           HIDWORD(v11),
           (uint32_t)v14,
           HIDWORD(v14));
}


// rf_get_cca_status @ 0x107bd8
int rf_get_cca_status() {
  volatile unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  volatile uint32_t *v4; // r2

  v0 = (volatile unsigned int *)off_107C18;
  v1 = *(volatile uint32_t *)off_107C18;
  v2 = *(volatile uint32_t *)off_107C14 >> 20;
  result = check_interrupt_flag(1, "calib_loft_i=%x\n", v2);
  v4 = (void *)(uintptr_t)(off_107C24);
  *v0 = dword_107C20 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}


// rf_get_rx_rssi @ 0x107c28
int rf_get_rx_rssi() {
  volatile unsigned int *v0; // r5
  int v1; // r6
  uint16_t v2; // r4
  int result; // r0
  volatile uint32_t *v4; // r1

  v0 = (volatile unsigned int *)off_107C64;
  v1 = *(volatile uint32_t *)off_107C64;
  v2 = (uint16_t)*(volatile uint32_t *)off_107C60 >> 4;
  result = check_interrupt_flag(1, "calib_loft_q=%x\n", v2);
  v4 = (void *)(uintptr_t)(off_107C6C);
  *v0 = (v2 + (uint16_t)v1) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}


// rf_transmit_packet @ 0x107c70
volatile uint32_t * rf_transmit_packet( int a1, volatile unsigned int *a2, int a3, unsigned int a4, unsigned int a5, int a6, uint16_t a7) {
  volatile int *v7; // r4
  volatile unsigned int *v8; // lr
  volatile unsigned int *v9; // r5
  volatile uint32_t *v10; // r12
  volatile int *v11; // r6
  volatile unsigned int *v12; // r11
  volatile int *v13; // r8
  volatile int *v14; // r7
  unsigned int v15; // r5
  void *v17; // r3
  void *v18; // r3
  void *v19; // r3
  volatile uint32_t *v20; // r3
  int v21; // r6
  volatile uint32_t *v22; // r0
  volatile uint32_t *v23; // r2
  volatile unsigned int *v24; // r1
  volatile uint32_t *v25; // r2
  int v26; // r0
  volatile uint32_t *v27; // r3
  volatile unsigned int *v28; // r9
  volatile int *v29; // r11
  volatile int *v30; // r10
  int v31; // r1
  int v32; // r2
  int v33; // s16
  int v34; // r4
  int v35; // r7
  int v36; // r8
  int v37; // r4
  int v38; // r3
  int v39; // r4
  int i; // r6
  int v41; // r5
  int v42; // r3
  int v43; // r2
  int v44; // r6
  int v45; // r6
  int v46; // r5
  int v47; // r3
  int v48; // r3
  signed int v49; // r6
  signed int v50; // r5
  unsigned int v51; // r6
  unsigned int v52; // r5
  int v53; // r2
  volatile int *v54; // r0
  volatile unsigned int *v55; // r1
  volatile unsigned int *v56; // r3
  int v57; // r2
  int v58; // r5
  int v59; // r4
  int v60; // r2
  int v61; // r2
  int v62; // r7
  int v63; // r6
  int v64; // r10
  int v65; // r9
  unsigned int v66; // r8
  int v67; // r5
  volatile unsigned int *v68; // r1
  volatile int *v69; // r2
  int v70; // r0
  volatile unsigned int *v71; // r4
  volatile uint32_t *result; // r0
  int v73; // r2
  int v74; // r4
  int v75; // r3
  int v76; // r5
  signed int v77; // r6
  signed int v78; // r4
  volatile unsigned int *v79; // r1
  volatile unsigned int *v80; // r3
  int v81; // cc
  volatile unsigned int *v82; // r1
  volatile unsigned int *v83; // r0
  volatile unsigned int *v84; // r11
  volatile unsigned int *v85; // r12
  volatile uint32_t *v86; // r10
  volatile uint32_t *v87; // r9
  volatile unsigned int *v88; // r3
  volatile unsigned int *v89; // r2
  volatile unsigned int *v90; // r4
  volatile unsigned int *v91; // r0
  volatile unsigned int *v92; // r1
  int v93; // r6
  volatile uint32_t *v94; // r7
  volatile unsigned int *v95; // r2
  volatile uint32_t *v96; // r5
  volatile uint32_t *v97; // r5
  volatile unsigned int *v98; // r1
  int v99; // r2
  struct __attribute__((packed)) { int v100; // [sp+0h] [bp-1F4h]
  char _pad1[4]; union { int v101; // [sp+8h] [bp-1ECh]
  unsigned int v102; // [sp+8h] [bp-1ECh]
  int v103; }; // [sp+8h] [bp-1ECh]
  int v104; // [sp+Ch] [bp-1E8h]
  int v105; // [sp+10h] [bp-1E4h]
  int v106; // [sp+14h] [bp-1E0h]
  int v107; // [sp+18h] [bp-1DCh]
  int v108; // [sp+1Ch] [bp-1D8h]
  volatile int *v109; // [sp+20h] [bp-1D4h]
  int v110; // [sp+24h] [bp-1D0h]
  int v111; // [sp+28h] [bp-1CCh]
  int v112; // [sp+2Ch] [bp-1C8h]
  int v113; // [sp+30h] [bp-1C4h]
  int v114; // [sp+34h] [bp-1C0h]
  int v115; // [sp+38h] [bp-1BCh]
  int v116; // [sp+3Ch] [bp-1B8h]
  int v117; // [sp+40h] [bp-1B4h]
  int v118; // [sp+44h] [bp-1B0h]
  unsigned int v119; // [sp+48h] [bp-1ACh]
  int v120; // [sp+4Ch] [bp-1A8h]
  unsigned int v121; // [sp+50h] [bp-1A4h]
  int v122; // [sp+54h] [bp-1A0h]
  int v123; // [sp+58h] [bp-19Ch]
  int v124; // [sp+5Ch] [bp-198h]
  int v125; // [sp+60h] [bp-194h]
  int v126; // [sp+64h] [bp-190h]
  int v127; // [sp+68h] [bp-18Ch]
  int v128; // [sp+6Ch] [bp-188h]
  int v129; // [sp+70h] [bp-184h]
  int v130; // [sp+74h] [bp-180h]
  int v131; // [sp+78h] [bp-17Ch]
  int v132; // [sp+7Ch] [bp-178h]
  int v133; // [sp+80h] [bp-174h]
  int v134; // [sp+84h] [bp-170h]
  int v135; // [sp+88h] [bp-16Ch]
  int v136; // [sp+8Ch] [bp-168h]
  int v137; // [sp+90h] [bp-164h]
  int v138; // [sp+94h] [bp-160h]
  unsigned int v139; // [sp+98h] [bp-15Ch]
  int v140; // [sp+9Ch] [bp-158h]
  unsigned int v141; // [sp+A0h] [bp-154h]
  int v142; // [sp+A4h] [bp-150h]
  unsigned int v143; // [sp+A8h] [bp-14Ch]
  int v144; // [sp+ACh] [bp-148h]
  unsigned int v145; // [sp+B0h] [bp-144h]
  int v146; // [sp+B4h] [bp-140h]
  unsigned int v147; // [sp+B8h] [bp-13Ch]
  unsigned int v148; // [sp+BCh] [bp-138h]
  int v149; // [sp+C0h] [bp-134h]
  int v150; // [sp+C4h] [bp-130h]
  int v151; // [sp+C8h] [bp-12Ch]
  int v152; // [sp+CCh] [bp-128h]
  int v153; // [sp+D0h] [bp-124h]
  int v154; // [sp+D4h] [bp-120h]
  int v155; // [sp+D8h] [bp-11Ch]
  int v156; // [sp+DCh] [bp-118h]
  int v157; // [sp+E0h] [bp-114h]
  int v158; // [sp+E4h] [bp-110h]
  int v159; // [sp+E8h] [bp-10Ch]
  int v160; // [sp+ECh] [bp-108h]
  int v161; // [sp+F0h] [bp-104h]
  char _pad60[4]; int v163; // [sp+F8h] [bp-FCh]
  int v164; // [sp+FCh] [bp-F8h]
  char _pad62[4]; volatile unsigned int *v166; // [sp+104h] [bp-F0h]
  uint32_t v167[3]; // [sp+108h] [bp-ECh]
  unsigned int a1a[4]; // [sp+114h] [bp-E0h] BYREF
  int v169; // [sp+124h] [bp-D0h] BYREF
  int v170; // [sp+128h] [bp-CCh]
  int v171; // [sp+12Ch] [bp-C8h]
  uint64_t v172; // [sp+130h] [bp-C4h]
  char _pad69[24]; unsigned int v173; // [sp+150h] [bp-A4h]
  uint32_t a2a[10]; // [sp+154h] [bp-A0h] BYREF
  char v175; // [sp+17Ch] [bp-78h] BYREF
  char _pad72[15]; int v176; // [sp+18Ch] [bp-68h]
  char _pad73[8]; int v177; // [sp+198h] [bp-5Ch] BYREF
  int v178; // [sp+19Ch] [bp-58h]
  int v179; // [sp+1A0h] [bp-54h]
  int v180; // [sp+1A4h] [bp-50h]
  } _frame;
  v7 = (volatile int *)off_107F30;
  v8 = (volatile unsigned int *)off_107F64;
  v9 = (volatile unsigned int *)off_107F34;
  v10 = (void *)(uintptr_t)(off_107F6C);
  v11 = (volatile int *)off_107F38;
  v12 = (volatile unsigned int *)off_107F70;
  v13 = (volatile int *)off_107F74;
  _frame.v161 = *(volatile uint32_t *)off_107F68;
  _frame.v160 = *(volatile uint32_t *)off_107F30;
  _frame.v159 = *(volatile uint32_t *)off_107F30;
  _frame.v158 = *(volatile uint32_t *)off_107F64;
  _frame.v157 = *(volatile uint32_t *)off_107F34;
  _frame.v156 = *(volatile uint32_t *)off_107F34;
  _frame.v155 = *(volatile uint32_t *)off_107F34;
  _frame.v154 = *(volatile uint32_t *)off_107F34;
  _frame.v153 = *(volatile uint32_t *)off_107F6C;
  _frame.v152 = *(volatile uint32_t *)off_107F6C;
  _frame.v151 = *(volatile uint32_t *)off_107F38;
  _frame.v150 = *(volatile uint32_t *)off_107F30;
  _frame.v149 = *(volatile uint32_t *)off_107F30;
  *(volatile uint32_t *)off_107F68 = *(volatile uint32_t *)off_107F68 & 0xF8FFFFFF | 0x1000000;
  v14 = (volatile int *)off_107F3C;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v8 = *v8 & 0xFFFFFF0F | 0xC0;
  *v9 |= 0x80u;
  *v9 &= 0xFFFFFF8F;
  *v9 |= 0x400u;
  *v9 = *v9 & 0xFFFFFCFF | 0x100;
  *v10 &= 0xFFFE00FF;
  *v10 |= 0x20000u;
  *v10 |= 0x40000u;
  _frame.v148 = *v12;
  _frame.v147 = *v12;
  _frame.v146 = *(volatile uint32_t *)off_107F40;
  _frame.v145 = *(volatile uint32_t *)off_107F40;
  _frame.v144 = *(volatile uint32_t *)off_107F44;
  _frame.v143 = *(volatile uint32_t *)off_107F44;
  _frame.v142 = *(volatile uint32_t *)off_107F48;
  _frame.v141 = *(volatile uint32_t *)off_107F48;
  _frame.v140 = *(volatile uint32_t *)off_107F4C;
  _frame.v139 = *(volatile uint32_t *)off_107F4C;
  _frame.v138 = *v13;
  _frame.v137 = *v13;
  _frame.v136 = *v13;
  _frame.v135 = *v13;
  _frame.v134 = *v13;
  _frame.v133 = *v11;
  _frame.v132 = *v11;
  _frame.v131 = *v14;
  _frame.v130 = *v14;
  _frame.v129 = *v14;
  _frame.v128 = *v14;
  _frame.v127 = *v7;
  _frame.v126 = *v7;
  _frame.v125 = *v7;
  _frame.v124 = *v7;
  _frame.v123 = *(volatile uint32_t *)off_107F50;
  _frame.v122 = *(volatile uint32_t *)off_107F54;
  _frame.v121 = *v8;
  _frame.v120 = *(volatile uint32_t *)off_107F58;
  _frame.v119 = *v8;
  _frame.v118 = *(volatile uint32_t *)off_107F5C;
  _frame.v117 = *(volatile uint32_t *)off_107F60;
  _frame.v115 = *v7;
  _frame.v116 = *v7;
  *v11 |= 0x8000u;
  *v11 &= 0xFFFF8FFF;
  *v11 &= ~0x800u;
  *v14 |= 0x800000u;
  v15 = a4;
  *v14 |= 0x400000u;
  a4 = (a4 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    a4 = (uint8_t)(a4 - 1);
  while ( a4 );
  v17 = (void *)(uintptr_t)(off_107F3C);
  *(volatile uint32_t *)off_107F3C &= ~0x100000u;
  *(volatile uint32_t *)v17 |= 0x200000u;
  v17 = (void *)(uintptr_t)(((uintptr_t)(v17) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v17 = (void *)(uint8_t)((uint8_t)v17 - 1);
  while ( v17 );
  v18 = (void *)(uintptr_t)(off_107F30);
  *(volatile uint32_t *)off_107F3C |= 0x100000u;
  *(volatile uint32_t *)v18 |= 0x20000u;
  *(volatile uint32_t *)v18 |= 0x10000u;
  v18 = (void *)(uintptr_t)(((uintptr_t)(v18) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v18 = (void *)(uint8_t)((uint8_t)v18 - 1);
  while ( v18 );
  v19 = (void *)(uintptr_t)(off_107F30);
  *(volatile uint32_t *)off_107F30 &= ~0x40000u;
  *(volatile uint32_t *)v19 |= 0x80000u;
  v19 = (void *)(uintptr_t)(((uintptr_t)(v19) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v19 = (void *)(uint8_t)((uint8_t)v19 - 1);
  while ( v19 );
  v20 = (void *)(uintptr_t)(off_107F30);
  *(volatile uint32_t *)off_107F30 |= 0x40000u;
  *v20 |= 0x8000u;
  *v20 |= 0x4000u;
  v21 = (v21 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    v21 = (uint8_t)(v21 - 1);
  while ( v21 );
  v22 = (void *)(uintptr_t)(off_107F50);
  v23 = (void *)(uintptr_t)(off_107F54);
  v24 = (volatile unsigned int *)off_107F64;
  *(volatile uint32_t *)off_107F50 |= 0x40000u;
  *v23 |= 0x3000u;
  v25 = (void *)(uintptr_t)(off_107F30);
  *v24 = *v24 & 0xFFFFFFFC | 1;
  v22[16] = v22[16] & 0xFFE3FFFF | 0xC0000;
  *v24 |= 4u;
  *v25 |= 0x800000u;
  *v25 |= 0x400000u;
  disable_bb_timer_irq();
  check_interrupt_flag(1, aStLoft);
  _frame.v114 = *(volatile uint32_t *)off_1082A0;
  *(volatile uint32_t *)off_1082A0 = *(volatile uint32_t *)off_1082A0 & 0xFFFFFFF | 0x10000000;
  do
  {
    enable_rf_dll(v21, 0);
    v26 = (uint8_t)(v21 + 1);
    v21 = (uint8_t)(v21 + 2);
    enable_rf_dll(v26, 0);
  }
  while ( v21 != 32 );
  v27 = (void *)(uintptr_t)(off_1082A4);
  *(volatile uint32_t *)off_1082A4 &= ~0x200u;
  *v27 |= 0x200u;
  *v27 &= ~0x200u;
  clk_enable();
  if ( a3 == 255 )
  {
    v28 = (volatile unsigned int *)off_1082E4;
    v29 = (volatile int *)off_1082E8;
    v30 = (volatile int *)off_1082EC;
    v31 = ((volatile uint32_t *)(uintptr_t)off_1082A8)[1];
    v32 = ((volatile uint32_t *)(uintptr_t)off_1082A8)[2];
    _frame.v167[0] = ((volatile uint32_t *)(uintptr_t)off_1082A8)[0];
    _frame.v167[1] = v31;
    _frame.v167[2] = v32;
    memset((void *)(_frame.a1a), 0, sizeof(_frame.a1a));
    v33 = 0;
    _frame.v110 = 6;
    do
    {
      if ( v33 )
      {
        if ( v33 == 1 )
        {
          _frame.v170 = 24;
          v34 = 1;
          _frame.v166 = a2 + 1;
        }
        else
        {
          _frame.v170 = 15;
          _frame.v166 = a2;
          v34 = 0;
        }
      }
      else
      {
        _frame.v170 = 15;
        _frame.v166 = a2 + 2;
        v34 = 2;
      }
      check_interrupt_flag(1, "===========table[%d]===========\n", v33);
      mac_get_params(a2[v33], _frame.a2a);
      check_interrupt_flag(1, "cal_all_times=%d\n", _frame.v176);
      if ( _frame.v176 <= 0 )
      {
        _frame.v107 = _frame.v167[v34];
      }
      else
      {
        _frame.v164 = v34;
        _frame.v108 = 2 * (4 * v34 + 1);
        _frame.v163 = v34 << 12;
        v35 = dword_1082B4;
        v36 = dword_1082F0;
        _frame.v107 = _frame.v167[v34];
        _frame.v106 = a1 + 32 * v34;
        _frame.v109 = (volatile int *)&_frame.v175;
        _frame.v112 = 0;
        _frame.v113 = _frame.v110 << 8;
        do
        {
          v37 = dword_1082B8 | _frame.v163 | (*_frame.v109 << 8);
          *(volatile uint32_t *)off_1082C0 = v37;
          v38 = *_frame.v109++;
          check_interrupt_flag(1, "****************table[%d] cal [%x] index.********************\n", v33, v38);
          check_interrupt_flag(1, "tx_gain_map=%x\n", v37);
          _frame.v171 = 0;
          load_patch_bundle((int)&_frame.v169);
          v39 = _frame.v110;
          for ( i = _frame.v113; ; i = v39 << 8 )
          {
            *v28 = i & 0xF00 | *v28 & 0xFFFFF0FF;
            *v29 &= v35;
            *v29 &= v36;
            *v30 &= v35;
            *v30 &= v36;
            rf_core_irq_poll((int)&_frame.v169);
            rf_clear_irq_flag();
            rf_get_cca_status();
            rf_core_irq_dispatch((int)&_frame.v169);
            rf_clear_irq_flag_alt();
            rf_get_rx_rssi();
            v41 = *v30 & 0xFFF;
            v42 = (*v30 & 0x8000000) != 0 ? (HIWORD(*v30) & 0xFFF) - 4096 : HIWORD(*v30) & 0xFFF;
            v43 = (*v30 & 0x800) != 0 ? v41 - 4096 : *v30 & 0xFFF;
            if ( v42 <= 1024 && v43 <= 1024 )
              break;
            _frame.v100 = v43;
            v99 = v39;
            v39 = (uint8_t)(v39 - 1);
            check_interrupt_flag(1, "loft_bit_ctrl_ini=%d loft_i=%d loft_q=%d loft i/q too big,re cal\n", v99, v42, _frame.v100);
          }
          _frame.v110 = v39;
          _frame.v113 = i;
          v44 = HIWORD(*v30) & 0xFFF;
          *v28 = ((v39 + 1) << 8) & 0xF00 | *v28 & 0xFFFFF0FF;
          check_interrupt_flag(1, aReCalI);
          *v30 = dword_1082CC & (v44 << 17) | *v30 & v35;
          rf_core_irq_poll((int)&_frame.v169);
          rf_clear_irq_flag();
          rf_get_cca_status();
          check_interrupt_flag(1, aReCalQ);
          *v30 = (2 * v41) & 0xFFF | *v30 & v36;
          rf_core_irq_dispatch((int)&_frame.v169);
          rf_clear_irq_flag_alt();
          rf_get_rx_rssi();
          v45 = HIWORD(*v30) & 0xFFF;
          v46 = *v30 & 0xFFF;
          v47 = v46 + (v45 << 16);
          *(volatile uint32_t *)(_frame.v106 + 8) = v47;
          v48 = v47 | (*v28 >> 8 << 28);
          *(volatile uint32_t *)(_frame.v106 + 8) = v48;
          _frame.v101 = v45 << 16;
          check_interrupt_flag(1, "loft_res[%d]=%x\n", _frame.v108, v48);
          *v30 &= v35;
          *v30 &= v36;
          gpio_output((int)&_frame.v169, 1);
          _frame.a1a[0] = _frame.v173;
          timer_delta_compare(_frame.a1a, (int)&_frame.v169);
          pinmux_config((int)&_frame.v169, 1);
          v49 = _frame.v173;
          check_interrupt_flag(1, "din_i=%4x,  din_q=%4x,  pwr_bypass=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, _frame.v173);
          *v30 = *v30 & v35 | _frame.v101;
          *v30 = v46 | *v30 & v36;
          pinmux_config((int)&_frame.v169, 1);
          v50 = _frame.v173;
          check_interrupt_flag(1, "din_i=%4x,  din_q=%4x,  pwr_use=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, _frame.v173);
          if ( v49 <= v50 )
          {
            check_interrupt_flag(1, aLoftCalCantBeU);
            _frame.v107 = 0;
            *(volatile uint32_t *)(_frame.v106 + 8) = 0;
          }
          else
          {
            _frame.v107 &= 1u;
            check_interrupt_flag(1, aLoftCanBeUsed);
          }
          v51 = *v28;
          _frame.v102 = *v30;
          v52 = *v30;
          v53 = *(_frame.v109 - 1);
          _frame.v167[_frame.v164] = _frame.v107;
          check_interrupt_flag(1, "ana_index[%x] loft_ok[%d]=%d\n", v53, v33, _frame.v107);
          check_interrupt_flag(1, "wdata=%x\n", (v52 & 0xFFF) + ((HIWORD(_frame.v102) & 0xFFF) << 16) + (v51 >> 8 << 28));
          *v30 = *v30 & v35 | ((*(volatile uint16_t *)(_frame.v106 + 10) & 0xFFF) << 16);
          *v30 = *(volatile uint32_t *)(_frame.v106 + 8) & 0xFFF | *v30 & v36;
          check_interrupt_flag(1, "use loft_i_offset=%x  loft_q_offset=%x \n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF);
          check_interrupt_flag(1, aLoftAmPhCal);
          v54 = (volatile int *)off_1085F0;
          v55 = (volatile unsigned int *)off_1085F4;
          v56 = (volatile unsigned int *)off_1085F8;
          *v28 &= ~0x40000000u;
          *v28 &= 0xCFFFFFFF;
          v57 = *v54 & v36;
          _frame.a2a[6] = 1;
          _frame.v177 = 600;
          _frame.v178 = 600;
          _frame.v179 = 0;
          _frame.v180 = 0;
          _frame.v169 = 0;
          *v54 = v57 | 0x300;
          *v55 = *v55 & 0xFFFFFF8F | 0x50;
          *v56 = *v56 & 0xFFF0FFFF | 0x10000;
          *v56 = *v56 & 0xFFFF0FFF | 0x1000;
          *v56 = *v56 & 0xFFFFF0FF | 0x100;
          *v56 = *v56 & 0xFFFFFF0F | 0x20;
          *v56 = *v56 & 0xFFFFFFF0 | 3;
          _frame.v171 = 10;
          v58 = 0;
          load_patch_bundle((int)&_frame.v169);
          _frame.v111 = 0;
          do
          {
            while ( 1 )
            {
              _frame.v104 = _frame.v177;
              _frame.v105 = _frame.v178;
              v59 = _frame.v179;
              _frame.v103 = _frame.v180;
              _frame.v169 = v58;
              timer_ticks_to_micros(&_frame.v177);
              rf_core_set_clock_override((int)&_frame.v177, (void *)(&_frame.v169));
              rx_queue_pop_packet((int)&_frame.v169, &_frame.v177, (int)_frame.a2a);
              v60 = v58;
              if ( v58 )
                break;
              if ( _frame.v172 )
              {
                v59 = _frame.v179;
                _frame.v103 = _frame.v180;
                v61 = 0;
                v58 = 1;
              }
              else
              {
                check_interrupt_flag(1, aEnterReLoftCal, HIDWORD(_frame.v172), (unsigned int)_frame.v172 | HIDWORD(_frame.v172));
                ++_frame.v111;
                _frame.v171 += 6;
                load_patch_bundle((int)&_frame.v169);
                _frame.v177 = _frame.v104;
                _frame.v178 = _frame.v105;
                _frame.v179 = v59;
                _frame.v180 = _frame.v103;
                v61 = -(_frame.v111 <= 2);
                v58 = _frame.v111 > 2;
              }
              check_interrupt_flag(1, "time[%d] am=%d,ph=%d\n", v61, v59, _frame.v103);
            }
            ++v58;
            check_interrupt_flag(1, "time[%d] am=%d,ph=%d\n", v60, _frame.v179, _frame.v180);
          }
          while ( v58 != 5 );
          v73 = (*v28 >> 12) & 7;
          v74 = dword_108968 & (_frame.v180 << 16);
          v75 = HIWORD(*v28) & 7;
          v76 = _frame.v179 & 0xFFF;
          *(volatile uint32_t *)(_frame.v106 + 12) = v74 + (v73 << 28) + (v75 << 12) + v76;
          check_interrupt_flag(1, "phase_bit=%d,am_bit=%d\n", v73, v75);
          check_interrupt_flag(1, "loft_res[%d]=%x\n", _frame.v108 + 1, *(volatile uint32_t *)(_frame.v106 + 12));
          *v29 &= v35;
          *v29 &= v36;
          gpio_output((int)&_frame.v169, 0);
          _frame.a1a[0] = _frame.v173;
          timer_delta_compare(_frame.a1a, (int)&_frame.v169);
          pinmux_config((int)&_frame.v169, 0);
          v77 = _frame.v173;
          check_interrupt_flag(1, "am=%4x, ph=%4x, pwr_am0_ph0=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, _frame.v173);
          *v29 = v74 | *v29 & v35;
          *v29 = v76 | *v29 & v36;
          pinmux_config((int)&_frame.v169, 0);
          v78 = _frame.v173;
          check_interrupt_flag(1, "am=%4x, ph=%4x,  pwr_am_ph=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, _frame.v173);
          v79 = (volatile unsigned int *)off_108980;
          v80 = (volatile unsigned int *)off_108984;
          *(volatile uint32_t *)off_10897C = *(volatile uint32_t *)off_10897C & v36 | 0xC0;
          *v79 = *v79 & 0xFFFFFF8F | 0x40;
          *v80 = *v80 & 0xFFF0FFFF | 0x10000;
          *v80 = *v80 & 0xFFFF0FFF | 0x1000;
          *v80 = *v80 & 0xFFFFF0FF | 0x100;
          *v80 = *v80 & 0xFFFFFF0F | 0x10;
          *v80 = *v80 & 0xFFFFFFF0 | 1;
          if ( v77 <= v78 )
          {
            check_interrupt_flag(1, aLoftAmPhCantBe);
            *(volatile uint32_t *)(_frame.v106 + 12) = 0;
          }
          else
          {
            check_interrupt_flag(1, aLoftAmPhCanBeU);
          }
          _frame.v106 += 8;
          v81 = _frame.v176 <= ++_frame.v112;
          _frame.v108 += 2;
        }
        while ( !v81 );
      }
      *_frame.v166 = *_frame.v166 & 0xFFFDFFFF | (_frame.v107 << 17);
      check_interrupt_flag(1, "loft_ok[%d]=%d\n", v33, _frame.v107);
      check_interrupt_flag(1, "loft_dpd_bit_mask=%x\n", *_frame.v166);
      ++v33;
    }
    while ( v33 != 3 );
    clk_disable();
    v82 = (volatile unsigned int *)off_108994;
    v83 = (volatile unsigned int *)off_108998;
    v84 = (volatile unsigned int *)off_1089C0;
    v85 = (volatile unsigned int *)off_1089C4;
    v86 = (void *)(uintptr_t)(off_1089C8);
    v87 = (void *)(uintptr_t)(off_1089CC);
    *(volatile uint32_t *)off_108994 = _frame.v133 & 0x8000 | *(volatile uint32_t *)off_108994 & 0xFFFF7FFF;
    v88 = (volatile unsigned int *)off_10899C;
    *v82 = _frame.v132 & 0x7000 | *v82 & 0xFFFF8FFF;
    v89 = (volatile unsigned int *)off_1089A0;
    *v83 = _frame.v161 & 0x7000000 | *v83 & 0xF8FFFFFF;
    *v82 = *v82 & 0xFFFFF7FF | _frame.v151 & 0x800;
    v90 = (volatile unsigned int *)off_1089A4;
    *v88 = *v88 & 0xFFFBFFFF | _frame.v149 & 0x40000;
    v91 = (volatile unsigned int *)off_1089A8;
    *v88 = *v88 & 0xFFF7FFFF | _frame.v150 & 0x80000;
    v92 = (volatile unsigned int *)off_1089AC;
    *v89 = *v89 & 0xFF7FFFFF | _frame.v131 & 0x800000;
    *v89 = *v89 & 0xFFBFFFFF | _frame.v130 & 0x400000;
    v93 = dword_1089B0;
    *v89 = *v89 & 0xFFEFFFFF | _frame.v129 & 0x100000;
    *v89 = _frame.v128 & 0x200000 | *v89 & 0xFFDFFFFF;
    v94 = (void *)(uintptr_t)(off_1089B4);
    *v88 = _frame.v127 & 0x20000 | *v88 & 0xFFFDFFFF;
    *v88 = _frame.v126 & 0x10000 | *v88 & 0xFFFEFFFF;
    *v88 = _frame.v125 & 0x8000 | *v88 & 0xFFFF7FFF;
    v95 = (volatile unsigned int *)off_108984;
    *v88 = _frame.v124 & 0x4000 | *v88 & 0xFFFFBFFF;
    v96 = (void *)(uintptr_t)(off_1089B8);
    *v84 = _frame.v123 & 0x40000 | *v84 & 0xFFFBFFFF;
    *(volatile uint32_t *)off_1089B8 = _frame.v122 & 0x3000 | *v96 & 0xFFFFCFFF;
    v97 = (void *)(uintptr_t)(off_1089BC);
    *v90 = _frame.v121 & 3 | *v90 & 0xFFFFFFFC;
    *(volatile uint32_t *)off_1089BC = _frame.v120 & 0x1C0000 | *v97 & 0xFFE3FFFF;
    *v90 = _frame.v119 & 4 | *v90 & 0xFFFFFFFB;
    *v88 = _frame.v116 & 0x800000 | *v88 & 0xFF7FFFFF;
    *v88 = _frame.v115 & 0x400000 | *v88 & 0xFFBFFFFF;
    *v88 = _frame.v160 & 0x200000 | *v88 & 0xFFDFFFFF;
    *v88 = _frame.v159 & 0x100000 | *v88 & 0xFFEFFFFF;
    *v90 = _frame.v158 & 0xF0 | *v90 & 0xFFFFFF0F;
    *v91 = _frame.v157 & 0x80 | *v91 & 0xFFFFFF7F;
    *v91 = _frame.v156 & 0x70 | *v91 & 0xFFFFFF8F;
    *v91 = _frame.v155 & 0x400 | *v91 & 0xFFFFFBFF;
    *v91 = _frame.v154 & 0x300 | *v91 & 0xFFFFFCFF;
    *v92 = *v92 & 0xFFBFFFFF | _frame.v153 & 0x400000;
    *v92 = *v92 & 0xFFDFFFFF | _frame.v152 & 0x200000;
    result = (void *)(uintptr_t)(off_108C9C);
    *v92 &= 0xFFFE00FF;
    *v92 &= ~0x20000u;
    *v92 |= 0x40000u;
    *v85 = *v85 & v93 | _frame.v148 & 0x3FFF;
    *v85 = *v85 & 0xC000FFFF | ((HIWORD(_frame.v147) & 0x3FFF) << 16);
    *v94 = *v94 & v93 | _frame.v146 & 0x3FFF;
    *v94 = *v94 & 0xC000FFFF | ((HIWORD(_frame.v145) & 0x3FFF) << 16);
    *result = *result & v93 | _frame.v144 & 0x3FFF;
    *result = *result & 0xC000FFFF | ((HIWORD(_frame.v143) & 0x3FFF) << 16);
    *v86 = *v86 & v93 | _frame.v142 & 0x3FFF;
    *v86 = *v86 & 0xC000FFFF | ((HIWORD(_frame.v141) & 0x3FFF) << 16);
    *v87 = v93 & *v87 | _frame.v140 & 0x3FFF;
    *v87 = *v87 & 0xC000FFFF | ((HIWORD(_frame.v139) & 0x3FFF) << 16);
    *v95 = _frame.v138 & 0xF0000 | *v95 & 0xFFF0FFFF;
    *v95 = _frame.v137 & 0xF000 | *v95 & 0xFFFF0FFF;
    *v95 = _frame.v136 & 0xF00 | *v95 & 0xFFFFF0FF;
    *v95 = _frame.v135 & 0xF0 | *v95 & 0xFFFFFF0F;
    v98 = (volatile unsigned int *)off_108CA0;
    *v95 = *v95 & 0xFFFFFFF0 | _frame.v134 & 0xF;
    *v98 = *v98 & 0x7FFFFFFF | _frame.v118 & 0x80000000;
    *(volatile uint32_t *)off_108CA4 = _frame.v117;
    *(v84 - 19976) = *(volatile unsigned int *)((volatile char *)v84 + 0xFFFFFFE0 - 79872) & 0xFFFFFFF | _frame.v114 & 0xF0000000;
  }
  else
  {
    v62 = dword_108600;
    v63 = ((int)((uint64_t)((int32_t)dword_1085FC * (int64_t)(int32_t)(a3)) >> 32) >> 5) - (a3 >> 31);
    v64 = a3 - 100 * v63;
    poll_rf_status();
    *(volatile uint32_t *)off_108604 &= ~1u;
    _frame.v170 = 30;
    _frame.v171 = v63;
    dispatch_event_handler_1("pwr=%d\n", v63);
    v65 = HIWORD(v15) & 0xFFF;
    v66 = HIWORD(a5) & 0xFFF;
    v67 = v15 & 0xFFF;
    dispatch_event_handler_1("index=%d\n", v64);
    dispatch_event_handler_1("din_i=%x din_q=%x ph=%x am=%x\n", v65, v67, v66, a5 & 0xFFF);
    *(volatile uint32_t *)off_108614 = a6;
    dispatch_event_handler_1("dump_tx_gain_map=%x\n", a6);
    *(volatile uint32_t *)off_1085F0 = *(volatile uint32_t *)off_1085F0 & v62 | a7 & 0xFFF;
    dispatch_event_handler_1("dump_amp_tone=%x\n", a7);
    set_system_mode(v64);
    v68 = (volatile unsigned int *)off_1085F8;
    v69 = (volatile int *)off_108620;
    v70 = dword_108624;
    v71 = (volatile unsigned int *)off_108628;
    *(volatile uint32_t *)off_1085F8 = *(volatile uint32_t *)off_1085F8 & 0xFFF0FFFF | 0x10000;
    *v68 = *v68 & 0xFFFF0FFF | 0x1000;
    *v68 = *v68 & 0xFFFFF0FF | 0x100;
    *v68 = *v68 & 0xFFFFFF0F | 0x20;
    *v68 = *v68 & 0xFFFFFFF0 | 3;
    *v69 = *v69 & v70 | (v65 << 16);
    *v69 = v67 | *v69 & v62;
    *v71 = *v71 & v70 | (v66 << 16);
    *v71 = a5 & 0xFFF | *v71 & v62;
    clk_set_divider();
    load_patch_bundle((int)&_frame.v169);
    pinmux_config((int)&_frame.v169, 0);
    check_interrupt_flag(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, _frame.v173);
    pinmux_config((int)&_frame.v169, 0);
    check_interrupt_flag(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, _frame.v173);
    write_timer_reg(500);
    return (volatile uint32_t *)enable_bb_clock();
  }
  return result;
}


// rf_wait_for_command @ 0x108cb8
volatile uint32_t * rf_wait_for_command(volatile uint32_t *result, volatile unsigned int *a2) {
  int v2; // r3
  int v3; // r3
  int v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r3

  v2 = (v2 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
  do
    v2 = (uint16_t)(v2 - 1);
  while ( v2 );
  *(volatile uint32_t *)off_108D2C = 2;
  v3 = (v3 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
  do
    v3 = (uint16_t)(v3 - 1);
  while ( v3 );
  if ( (*(volatile uint32_t *)off_108D30 & 1) == 0 )
  {
    while ( 1 )
    {
      v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
      do
        v4 = (uint16_t)(v4 - 1);
      while ( v4 );
      if ( (*(volatile uint32_t *)off_108D30 & 1) != 0 )
      {
        v5 = (v5 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
        do
          v5 = (uint16_t)(v5 - 1);
        while ( v5 );
        if ( (*(volatile uint32_t *)off_108D30 & 1) != 0 )
          break;
      }
    }
  }
  v6 = *(volatile uint32_t *)off_108D30;
  v7 = *(volatile uint32_t *)off_108D30 >> 17;
  if ( *(volatile int *)off_108D30 < 0 )
    v7 = ~((unsigned int)~(v7 << 17) >> 17);
  *result = v7;
  v8 = (uint16_t)v6 >> 1;
  if ( (v6 & 0x8000) != 0 )
    v8 = ~(~(v8 << 17) >> 17);
  *a2 = v8;
  return result;
}



// rf_core_init @ 0x108d34
volatile uint32_t * rf_core_init(int a1, int a2) {
  volatile uint32_t *v2; // r2
  volatile unsigned int *v3; // r3
  volatile uint32_t *v4; // r12
  volatile uint32_t *v5; // r6
  volatile unsigned int *v6; // r7
  volatile unsigned int *v7; // r4
  volatile uint32_t *v8; // lr
  int v9; // r11
  int v10; // r6
  volatile int *v11; // r5
  int v14; // r9
  int i; // r4
  int v16; // lr
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r12
  volatile unsigned int *v21; // r3
  volatile uint32_t *result; // r0
  volatile uint32_t *v23; // r2
  struct __attribute__((packed)) { int v24; // [sp+0h] [bp-Ch] BYREF
  unsigned int a2a; // [sp+4h] [bp-8h] BYREF
  } _frame;
  v2 = (void *)(uintptr_t)(off_108F20);
  v3 = (volatile unsigned int *)off_108F24;
  v4 = (void *)(uintptr_t)(off_108F40);
  v5 = (void *)(uintptr_t)(off_108F28);
  v6 = (volatile unsigned int *)off_108F2C;
  v7 = (volatile unsigned int *)off_108F30;
  v8 = (void *)(uintptr_t)(off_108F38);
  v9 = dword_108F44;
  *(volatile uint32_t *)off_108F20 &= ~4u;
  *v5 &= 0xFFFF0FFF;
  v10 = 0;
  *v6 = 0;
  *v3 |= 0x80u;
  *v7 |= 0x80000000;
  *v2 |= 4u;
  v6 -= 6154;
  *v4 = HIWORD(*v4) << 16;
  *v6 = *v6 & 0xCFFFFFFF | 0x10000000;
  *v2 &= ~4u;
  *v7 &= ~0x80000000;
  *v3 &= ~0x80u;
  *v2 |= 4u;
  v11 = (volatile int *)off_108F34;
  *v8 |= 2u;
  *v3 = *v3 & 0xFFFF8FFF | 0x4000;
  *v3 = *v3 & 0xF8FFFFFF | 0x6000000;
  *v3 = *v3 & 0xFFFFF8FF | 0x100;
  *v3 &= ~4u;
  *v3 |= 1u;
  *v3 |= 8u;
  *v7 = ((unsigned int)v6 + 1059082178) | *v7 & 0x80000000;
  v14 = ((v4[8208] >> 3) & 7) << 6;
  for ( i = 0; i != 16; ++i )
  {
    while ( ((a1 >> i) & 1) == 0 )
    {
      if ( ++i == 16 )
        goto LABEL_7;
    }
    *v11 = *v11 & v9 | ((int16_t)(v14 | (4 * i)) << 8);
    *v11 |= 0x20000u;
    *v11 |= 0x40000u;
    write_timer_reg(1);
    rf_wait_for_command((void *)(&_frame.v24), &_frame.a2a);
    v16 = (int)_frame.a2a / 8;
    v17 = i;
    v18 = _frame.v24 / 8;
    v19 = (int)_frame.a2a / 8;
    if ( a2 )
    {
      *(volatile uint16_t *)(a2 + 4 * v10) = _frame.v24 / 8;
      v20 = a2 + 4 * v10++;
      *(volatile uint16_t *)(v20 + 2) = v16;
    }
    dispatch_event_handler_1(aDc0xXIDQD, v17, v18, v19);
  }
LABEL_7:
  v21 = (volatile unsigned int *)off_108F24;
  result = (void *)(uintptr_t)(off_108F3C);
  v23 = (void *)(uintptr_t)(off_108F34);
  *(volatile uint32_t *)off_108F38 &= ~2u;
  *v21 |= 4u;
  *v21 = *v21 & 0xFFFF8FFF | 0x3000;
  *v21 = *v21 & 0xFFFFF8FF | 0x600;
  *v21 &= ~8u;
  *v21 &= ~1u;
  *result &= 0xCFFFFFFF;
  *v23 &= 0xFFFE00FF;
  *v23 &= ~0x20000u;
  *v23 |= 0x40000u;
  return result;
}


// mac_frame_parse_fcf @ 0x109100
int mac_frame_parse_fcf(int result, int a2, volatile uint8_t *a3, volatile char *a4, volatile int *a5) {
  unsigned int v5; // r3
  uint64_t v6; // kr00_8
  char v7; // r3
  char v8; // r3
  int v9; // r3
  char v10; // r3
  char v11; // r3
  char v12; // r3
  int v13; // r4
  char v14; // r3
  int v15; // r3
  char v16; // r3
  int savedregs; // [sp+0h] [bp+0h]
  int savedregs_4; // [sp+4h] [bp+4h]

  if ( a2 == 15 )
  {
    if ( result == 1 )
    {
      v15 = *a5;
      if ( *a5 >= 0x2000 )
      {
        *a4 = 48;
      }
      else if ( v15 <= 0 )
      {
        if ( v15 > -8192 )
          v16 = -80;
        else
          v16 = -48;
        *a4 = v16;
      }
      else
      {
        *a4 = 80;
      }
    }
    else if ( result == 2 )
    {
      savedregs_4 = savedregs;
      v13 = *a5;
      if ( *a5 >= 0x2000 )
      {
        a4[1] = *a4 + 16;
        *a3 = 1;
        return 1;
      }
      else if ( v13 <= 0 )
      {
        if ( v13 > -8192 )
        {
          if ( a5[1] <= 0 )
            result = 6;
          else
            result = 5;
          a4[1] = *a4 - 16;
          *a3 = result;
        }
        else
        {
          a4[1] = *a4 - 16;
          *a3 = 4;
          return 4;
        }
      }
      else
      {
        v14 = *a4;
        if ( a5[1] < 0 )
          v14 += 16;
        else
          result = 3;
        if ( a5[1] >= 0 )
          v14 -= 16;
        a4[1] = v14;
        *a3 = result;
      }
    }
    else
    {
      switch ( *a3 )
      {
        case 1:
          if ( a5[2] <= 0 )
            goto LABEL_62;
          a4[2] = 32;
          break;
        case 2:
          if ( a5[2] <= 0 )
            goto LABEL_64;
          a4[2] = 64;
          break;
        case 3:
          a4[2] = 56;
          break;
        case 4:
          if ( a5[2] <= 0 )
            a4[2] = -32;
          else
LABEL_64:
            a4[2] = -112;
          break;
        case 5:
          if ( a5[2] <= 0 )
            a4[2] = -64;
          else
LABEL_62:
            a4[2] = 112;
          break;
        case 6:
          a4[2] = -56;
          break;
        default:
          a4[2] = -120;
          break;
      }
    }
  }
  else if ( result == 1 )
  {
    v9 = *a5;
    if ( *a5 >= 0x2000 )
    {
      *a4 = 32;
    }
    else if ( v9 <= 0 )
    {
      if ( v9 > -8192 )
        v10 = -64;
      else
        v10 = -32;
      *a4 = v10;
    }
    else
    {
      *a4 = 64;
    }
  }
  else if ( result == 2 )
  {
    v6 = *(volatile uint64_t *)a5;
    if ( *a5 <= 0 )
    {
      if ( SHIDWORD(v6) <= 0 )
      {
        v11 = *a4;
        if ( (int)v6 >= 2 * HIDWORD(v6) )
          v12 = v11 + 24;
        else
          v12 = v11 + 16;
        a4[1] = v12;
      }
      else
      {
        a4[1] = *a4 - 32;
      }
    }
    else if ( v6 < 0 )
    {
      a4[1] = *a4 + 32;
    }
    else
    {
      v7 = *a4;
      if ( (int)v6 <= 2 * HIDWORD(v6) )
        v8 = v7 - 24;
      else
        v8 = v7 - 16;
      a4[1] = v8;
    }
  }
  else
  {
    v5 = (uint8_t)a4[1];
    if ( v5 <= 0x10 )
    {
LABEL_7:
      a4[2] = 48;
      return result;
    }
    if ( v5 <= 0x30 )
    {
      a4[2] = 24;
      return result;
    }
    if ( v5 > 0x60 )
    {
      if ( v5 > 0xC0 )
      {
        if ( v5 <= 0xD8 )
        {
          a4[2] = -24;
          return result;
        }
      }
      else
      {
        if ( a5[2] > 0 )
        {
          a4[2] = 96;
          return result;
        }
        if ( v5 == 160 )
        {
          a4[2] = -32;
          return result;
        }
      }
      a4[2] = -48;
      return result;
    }
    if ( a5[2] < 0 )
    {
      a4[2] = -96;
    }
    else
    {
      if ( v5 != 96 )
        goto LABEL_7;
      a4[2] = 32;
    }
  }
  return result;
}



// atomic_write_if_zero @ 0x109120
int atomic_write_if_zero(uint64_t a1, int a2, volatile uint32_t *a3) {
  uint8_t v3; // r5
  volatile uint32_t *v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r3

  if ( a1 )
  {
    a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(HIDWORD(a1) + a1) & 0xFFFFFFFFu);
    if ( (uint32_t)a1 )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
      while ( 1 )
      {
        v3 = BYTE4(a1) + 1;
        v4 = &a3[HIDWORD(a1)];
        if ( *v4 <= a2 )
          break;
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v3) << 32);
        if ( v3 >= (int)a1 )
          goto LABEL_12;
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)((uint8_t)a1) & 0xFFFFFFFFu);
      if ( (unsigned int)(uint8_t)a1 > HIDWORD(a1) )
      {
        v5 = (int)&a3[(uint8_t)a1 - 1 - (uint8_t)(a1 - 1 - BYTE4(a1))];
        v6 = &a3[(uint8_t)a1];
        do
        {
          *v6 = *(v6 - 1);
          --v6;
        }
        while ( v6 != (volatile uint32_t *)v5 );
      }
      *v4 = a2;
    }
    else
    {
LABEL_12:
      a3[(uint32_t)a1] = a2;
    }
  }
  else
  {
    *a3 = a2;
  }
  return a1;
}



// swar_bit_count @ 0x109184
int swar_bit_count(unsigned int a1, int a2, volatile int *a3) {
  int v3; // r12
  int v4; // r4
  volatile int *v5; // r6
  unsigned int v6; // r5
  int v7; // r3
  int v9; // r7
  int v10; // t1
  int v11; // r1
  int v12; // r8
  unsigned int v13; // r0
  volatile int *v14; // r5
  int v15; // r7
  unsigned int v16; // r4
  int v17; // r6
  int v18; // lr
  int v19; // r8
  signed int v20; // r1
  int v22; // r11
  volatile uint8_t *v23; // r7
  volatile uint8_t *v24; // r1
  int v25; // r5
  int v26; // r3
  int v27; // r0
  int v28; // r1
  int v29; // r4
  volatile uint8_t *v30; // r5
  struct __attribute__((packed)) { int v31; // [sp+4h] [bp-10h]
  int v32; // [sp+8h] [bp-Ch] BYREF
  int16_t v33; // [sp+Ch] [bp-8h]
  char _pad3[2]; uint8_t v34[4]; // [sp+10h] [bp-4h] BYREF
  } _frame;
  v3 = (uint8_t)((a1 - 1) >> 1);
  _frame.v31 = v3;
  _frame.v32 = -2139062144;
  _frame.v33 = -32640;
  if ( a1 <= 1 )
    return a3[_frame.v31];
  v4 = 128;
  v5 = a3;
  v6 = 0;
  v7 = (v7 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  while ( 1 )
  {
    v9 = *v5;
    v10 = v5[1];
    ++v5;
    if ( v9 - v10 > a2 )
      break;
    if ( v4 == 128 )
      *((volatile uint8_t *)&_frame.v32 + 2 * v6) = v7 - 1;
    _frame.v34[2 * v6 - 7] = v7;
LABEL_6:
    v7 = (uint8_t)(v7 + 1);
    if ( a1 == v7 )
      goto LABEL_14;
LABEL_7:
    v4 = *((volatile uint8_t *)&_frame.v32 + 2 * v6);
  }
  if ( v4 == 128 )
    goto LABEL_6;
  v11 = a3[v4];
  if ( v11 > 14000 )
  {
    v12 = *((volatile uint8_t *)&_frame.v32 + 2 * v6 + 1);
    goto LABEL_12;
  }
  v12 = *((volatile uint8_t *)&_frame.v32 + 2 * v6 + 1);
  v22 = a3[v12];
  if ( v22 < dword_109360 || v11 < 1000 && v22 >= dword_109364 )
  {
LABEL_12:
    if ( v12 >= v4 + v3 )
      goto LABEL_13;
    goto LABEL_27;
  }
  if ( v12 < v4 + 2 )
  {
LABEL_27:
    v23 = &_frame.v34[2 * v6];
    *(v23 - 8) = 0x80;
    *(v23 - 7) = 0x80;
    goto LABEL_6;
  }
LABEL_13:
  v7 = (uint8_t)(v7 + 1);
  v6 = (uint8_t)(v6 + 1);
  if ( a1 != v7 )
    goto LABEL_7;
LABEL_14:
  if ( v6 <= 2 )
  {
    v24 = &_frame.v34[2 * v6];
    v25 = 2 * v6;
    v26 = (uint8_t)*(v24 - 8);
    if ( v26 != 128 )
    {
      v27 = a3[v26];
      v28 = (uint8_t)*(v24 - 7);
      if ( v27 <= 14000 )
      {
        v29 = a3[v28];
        if ( v29 >= dword_109360 && (v27 >= 1000 || v29 <= -1000) )
          v3 = 2;
      }
      if ( v28 < v3 + v26 )
      {
        v30 = &_frame.v34[v25];
        *(v30 - 8) = 0x80;
        *(v30 - 7) = 0x80;
      }
    }
  }
  if ( (uint8_t)_frame.v32 != 128 )
  {
    v13 = (uint8_t)(BYTE1(_frame.v32) + 1 - _frame.v32);
    v14 = &_frame.v32;
    v15 = 1;
    v16 = (uint16_t)((a3[(uint8_t)_frame.v32] - a3[BYTE1(_frame.v32)]) / (int)v13);
    v17 = 0;
    while ( 1 )
    {
      v18 = *((volatile uint8_t *)v14 + 2);
      if ( v18 == 128 )
        break;
      v19 = *((volatile uint8_t *)v14 + 3);
      v20 = (uint8_t)(v19 + 1 - v18);
      if ( v20 > v13 )
      {
        v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
        v13 = (uint8_t)(v19 + 1 - v18);
        v17 = (uint8_t)v15;
        v14 = (volatile int *)((volatile char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      else
      {
        if ( v20 == v13 && (uint16_t)((a3[v18] - a3[v19]) / v20) < v16 )
        {
          v16 = (uint16_t)((a3[v18] - a3[v19]) / v20);
          v17 = (uint8_t)v15;
        }
        v14 = (volatile int *)((volatile char *)v14 + 2);
        if ( v15 == 2 )
          break;
      }
      v15 = 2;
    }
    _frame.v31 = (uint8_t)(*((volatile uint8_t *)&_frame.v32 + 2 * v17)
                          + ((*((volatile uint8_t *)&_frame.v32 + 2 * v17 + 1) - *((volatile uint8_t *)&_frame.v32 + 2 * v17) + 1) >> 1));
  }
  return a3[_frame.v31];
}



// float_compare @ 0x109368
int float_compare(volatile float *a1, volatile float *a2) {
  float v2; // s15
  float v3; // s14
  float v4; // s13

  v2 = *a1;
  v3 = a1[1];
  if ( *a1 < v3 && *a2 >= a2[1] )
    return 2;
  if ( v2 > v3 && *a2 <= a2[1] )
    return 2;
  v4 = a1[2];
  if ( v2 < v4 && *a2 >= a2[2] )
    return 2;
  if ( v2 > v4 && *a2 <= a2[2] || v3 < v4 && a2[1] >= a2[2] || v3 > v4 && a2[1] <= a2[2] )
    return 2;
  if ( *a2 > 0.0 && a2[1] > 0.0 && a2[2] > 0.0 )
    return 1;
  if ( *a2 >= 0.0 || a2[1] >= 0.0 )
    return 0;
  return a2[2] < 0.0;
}



// memzero_words @ 0x109480
int memzero_words(int a1, volatile int16_t *a2) {
  unsigned int v2; // r2
  volatile int16_t *v3; // r8
  volatile int16_t *v4; // r4
  unsigned int v5; // r7
  int v6; // r12
  int result; // r0
  int v8; // t1
  char v9; // r6
  int v10; // r3
  int v11; // r2
  char v12; // r4
  char v13; // r5
  int v14; // r9
  int v15; // r7
  char v16; // lr
  int v17; // r8
  int v18; // r2
  int v19; // r3
  int v20; // r7
  int v21; // r10
  char v22; // r2
  int v23; // r2
  int v24; // r8
  int v25; // r7
  int v26; // r3
  int v27; // r3
  int v28; // r4
  int v29; // r2
  int v30; // r2
  int j; // r3
  volatile int16_t *v32; // r3
  volatile int16_t *v33; // r1
  int v34; // t1
  int v35; // r4
  int v36; // r2
  int i; // r3
  unsigned int v38; // r3
  int v39; // r4
  volatile int16_t *v40; // r1
  uint8_t v41; // [sp+1h] [bp-27h]
  int16_t v42; // [sp+2h] [bp-26h]

  if ( !a1 )
  {
    v32 = a2 - 1;
    result = 128;
    v33 = a2 + 5;
    do
    {
      v34 = v32[1];
      ++v32;
      if ( v34 < 0 )
        *v32 = 128;
    }
    while ( v33 != v32 );
    return result;
  }
  v2 = 0;
  v3 = a2 - 1;
  v4 = a2 - 1;
  v5 = 0;
  v6 = 0;
  result = 0;
  while ( 1 )
  {
    v8 = v4[1];
    ++v4;
    v9 = v2;
    if ( v8 < 0 )
      break;
    if ( (uint8_t)v2 == 5 )
      goto LABEL_8;
LABEL_4:
    ++v2;
  }
  result = (uint8_t)((1 << v2) | result);
  if ( v2 <= 1 )
  {
    v6 = (uint8_t)(v6 + 1);
    goto LABEL_4;
  }
  v5 = (uint8_t)(v5 + 1);
  if ( (uint8_t)v2 != 5 )
    goto LABEL_4;
LABEL_8:
  if ( v5 == 4 )
  {
    if ( v6 == 2 )
    {
      v40 = a2 + 5;
      do
      {
        v3[1] = 128;
        ++v3;
      }
      while ( v3 != v40 );
      return result;
    }
  }
  else if ( v5 <= 2 )
  {
    if ( !v6 )
    {
      v10 = a2[1];
      v11 = *a2;
      if ( v10 + 9 < v11 || v11 < v10 - 9 )
        a2[1] = v11;
    }
    v12 = 3;
    v41 = 3;
    v42 = 1284;
    if ( a2[2] < a2[3] )
    {
      v13 = 2;
      v41 = 2;
      v14 = 2;
      v15 = 3;
      if ( a2[4] >= a2[5] )
        goto LABEL_48;
LABEL_16:
      v42 = 1029;
      v16 = 5;
      v17 = 4;
      v9 = 4;
      v18 = 5;
    }
    else
    {
      v13 = 3;
      v14 = 3;
      v15 = 2;
      v12 = 2;
      if ( a2[4] < a2[5] )
        goto LABEL_16;
LABEL_48:
      v17 = 5;
      v18 = 4;
      v16 = 4;
    }
    v19 = a2[v15];
    v20 = a2[v18];
    if ( v19 < v20 )
    {
      v21 = a2[v18];
      v22 = v16;
      v42 = (v42 & ~0xFFu) | ((uint8_t)(v12) & 0xFFu);
      v20 = v19;
      v16 = v12;
      v19 = v21;
      v12 = v22;
    }
    v23 = a2[v14];
    v24 = a2[v17];
    if ( v23 < v24 )
    {
      v42 = (v42 & ~0xFF00u) | (((uint8_t)(v13) & 0xFFu) << 8);
      v41 = v9;
      v23 = v24;
      v13 = v9;
    }
    if ( v20 > v23 )
    {
      v42 = (v42 & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
      v41 = v16;
      v23 = v20;
      v13 = v16;
    }
    v25 = a2[(uint8_t)v42];
    if ( v19 > v23 + 7 )
      v26 = 0;
    else
      v26 = 4;
    if ( a2[v41] <= v25 + 7 )
      v26 |= 2u;
    if ( a2[HIBYTE(v42)] + 7 >= v25 )
      v26 |= 1u;
    switch ( v26 )
    {
      case 0:
      case 5:
        if ( !v6 )
          result |= 0x3Cu;
        break;
      case 1:
        result = (uint8_t)(result | (1 << v12) | (1 << v13));
        break;
      case 2:
        result = (uint8_t)(result | (1 << SHIBYTE(v42)) | (1 << v12));
        break;
      case 3:
        result = (uint8_t)(result | (1 << v12));
        break;
      case 4:
        result = (uint8_t)(result | (1 << v42) | (1 << SHIBYTE(v42)));
        break;
      case 6:
        result = (uint8_t)(result | (1 << SHIBYTE(v42)));
        break;
      default:
        break;
    }
    v35 = 0;
    v36 = 0;
    for ( i = 2; i != 6; ++i )
    {
      if ( ((result >> i) & 1) == 0 )
      {
        v35 = (uint8_t)(v35 + 1);
        v36 = (int16_t)(v36 + a2[i]);
      }
    }
    if ( !v35 )
    {
      if ( (result & 1) == 0 )
      {
        v36 = (int16_t)(v36 + *a2);
        v35 = 1;
      }
      if ( (result & 2) == 0 )
      {
        v35 = (uint8_t)(v35 + 1);
        v36 = (int16_t)(a2[1] + v36);
      }
    }
    v38 = 0;
    v39 = v36 / v35;
    while ( 2 )
    {
      if ( ((result >> v38) & 1) != 0 )
      {
        if ( v38 > 1 || v6 == 2 )
        {
          a2[v38] = v39;
          goto LABEL_65;
        }
      }
      else
      {
LABEL_65:
        if ( (uint8_t)v38 == 5 )
        {
          if ( v6 == 1 )
          {
            if ( (result & 1) != 0 )
            {
              *a2 = a2[1];
            }
            else if ( (result & 2) != 0 )
            {
              a2[1] = *a2;
            }
          }
          return result;
        }
      }
      ++v38;
      continue;
    }
  }
  v27 = 0;
  v28 = 0;
  v29 = 0;
  do
  {
    if ( ((result >> v27) & 1) == 0 )
    {
      v28 = (uint8_t)(v28 + 1);
      v29 = (int16_t)(v29 + a2[v27]);
    }
    ++v27;
  }
  while ( v27 != 6 );
  v30 = v29 / v28;
  for ( j = 0; j != 6; ++j )
  {
    if ( ((result >> j) & 1) != 0 )
      a2[j] = v30;
  }
  return result;
}



// compare_float_samples @ 0x109738
int compare_float_samples(unsigned int a1, volatile float *a2, volatile float *a3, int a4) {
  float v4; // s13
  float v5; // s14
  float v10; // s15
  float v11; // s16
  float v12; // s19
  float v13; // s18
  float v14; // s20
  float v15; // s17
  float v16; // s21
  uint64_t v17; // r0
  float v18; // s10
  float v19; // s11
  float v20; // s15
  float v21; // s17
  float v22; // s16
  int result; // r0
  float v24; // s12
  float v25; // s15
  char v26; // r3
  uint64_t v27; // r0
  float v28; // s15
  float v29; // s13
  float v30; // s14
  float v31; // s9
  float v32; // s10
  float v33; // s11
  uint64_t v34; // r0

  v4 = a2[1];
  v5 = *a2;
  if ( v4 <= *a2 )
  {
    v4 = *a2;
    v5 = a2[1];
  }
  v10 = a2[2];
  if ( v10 <= v4 )
  {
    if ( v10 < v5 )
      v5 = a2[2];
    v10 = v4;
  }
  *(volatile uint8_t *)(a4 + 2) = (unsigned int)(float)(v10 - v5);
  v11 = *a2;
  v12 = a2[1];
  v13 = a2[2];
  v14 = (float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13);
  v15 = (float)(*a2 + v12) + v13;
  v16 = (float)(v14 * 3.0) - (float)(v15 * v15);
  if ( v16 > 0.0 )
  {
    v17 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(v14 * 3.0) - (float)(v15 * v15)));
if ( !((int (*)())double_lt)(v17, *(volatile uint64_t *)&dword_1099A0) ) goto LABEL_11;
    v16 = flt_1099A8;
    goto LABEL_10;
  }
  v34 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(-v16));
if ( ((int (*)())double_lt)(v34, *(volatile uint64_t *)&dword_1099A0) ) { v16 = flt_1099B8;
LABEL_10:
    *(volatile uint8_t *)a4 |= 4u;
    log_printf(aDetectDivision);
    v11 = *a2;
    v12 = a2[1];
    v13 = a2[2];
  }
LABEL_11:
  v18 = a3[1];
  v19 = a3[2];
  v20 = -(float)((float)(1.0 / v16) * v15);
  v21 = (float)((float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v11) - (float)((float)(1.0 / v16) * v15))
                      * *a3)
              + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v12) - (float)((float)(1.0 / v16) * v15))
                      * v18))
      + (float)((float)((float)((float)((float)(1.0 / v16) * 3.0) * v13) - (float)((float)(1.0 / v16) * v15)) * v19);
  v22 = (float)((float)((float)((float)(v20 * v11) + (float)(v14 * (float)(1.0 / v16))) * *a3)
              + (float)((float)((float)(v20 * v12) + (float)(v14 * (float)(1.0 / v16))) * v18))
      + (float)((float)((float)(v20 * v13) + (float)(v14 * (float)(1.0 / v16))) * v19);
  if ( a1 > 0xD && v21 < 20.0
    || (v27 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v21)), (result = ((int (*)())double_lt)(v27, *(volatile uint64_t *)&dword_1099A0)) != 0) )
  {
    *(volatile uint8_t *)a4 |= 8u;
    result = log_printf(aSlopeTooSmall);
    v21 = 1.0;
    v24 = 2.0;
  }
  else
  {
    v24 = (float)(v21 * v21) + 1.0;
  }
  v25 = (float)-v22 / v21;
  if ( v25 > flt_1099B4 )
  {
    v26 = -1;
  }
  else if ( v25 < 0.0 )
  {
    v26 = 0;
  }
  else
  {
    v26 = (unsigned int)(float)(v25 + 0.5);
  }
  *(volatile uint8_t *)(a4 + 1) = v26;
  v28 = *a2;
  v29 = a2[1];
  v30 = a2[2];
  v31 = *a3;
  v32 = a3[1];
  v33 = a3[2];
  *(volatile float *)(a4 + 12) = v22;
  *(volatile float *)(a4 + 8) = v21;
  *(volatile float *)(a4 + 4) = (float)((float)((float)((float)((float)((float)(v21 * v28) + v22) - v31)
                                             * (float)((float)((float)(v21 * v28) + v22) - v31))
                                     + (float)((float)((float)((float)(v21 * v29) + v22) - v32)
                                             * (float)((float)((float)(v21 * v29) + v22) - v32)))
                             + (float)((float)((float)((float)(v21 * v30) + v22) - v33)
                                     * (float)((float)((float)(v21 * v30) + v22) - v33)))
                     / v24;
  return result;
}


// invoke_handler_14a99c @ 0x1099bc
int invoke_handler_14a99c(int a1, volatile float *a2, int a3, int a4) {
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  float v14; // r1
  float v15; // r0
  float v16; // r12
  float v17; // r4
  float v18; // r11
  int v19; // r8
  float v20; // r6
  volatile uint32_t *v21; // r6
  volatile float *v22; // r4
  volatile float *v23; // r7
  int v24; // t1
  float v25; // s16
  float v26; // s13
  float v27; // s15
  uint64_t v28; // r0
  uint64_t v29; // r8
  uint64_t v30; // r0
  uint64_t v31; // r8
  uint64_t v32; // r0
  uint64_t v33; // r0
  int v34; // r3
  int v35; // r7
  volatile uint32_t *v36; // r6
  volatile float *v37; // r4
  float v38; // s15
  volatile float *v39; // r12
  volatile uint32_t *v40; // r2
  volatile float *v41; // r3
  int v42; // r0
  int v43; // t1
  float v44; // s14
  float v45; // s17
  float v46; // s18
  float v47; // s19
  volatile float *v48; // r7
  int v49; // r8
  volatile float *v50; // r9
  int v51; // t1
  float v52; // s16
  volatile float *v53; // r5
  float v54; // s13
  struct __attribute__((packed)) { int v56; // [sp+0h] [bp-44h]
  int v57; // [sp+4h] [bp-40h]
  float a2a[3]; // [sp+8h] [bp-3Ch] BYREF
  float a3a[3]; // [sp+14h] [bp-30h] BYREF
  uint32_t v60[9]; // [sp+20h] [bp-24h] BYREF
  } _frame;
  v8 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[1];
  v9 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[2];
  v10 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[3];
  _frame.v60[0] = ((volatile uint32_t *)(uintptr_t)off_109BE0)[0];
  _frame.v60[1] = v8;
  _frame.v60[2] = v9;
  _frame.v60[3] = v10;
  v11 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[5];
  v12 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[6];
  v13 = ((volatile uint32_t *)(uintptr_t)off_109BE0)[7];
  _frame.v60[4] = ((volatile uint32_t *)(uintptr_t)off_109BE0)[4];
  _frame.v60[5] = v11;
  _frame.v60[6] = v12;
  _frame.v60[7] = v13;
  v14 = a2[4];
  v15 = a2[34];
  v16 = a2[2];
  v17 = a2[36];
  _frame.a2a[1] = a2[3];
  v18 = 0.0;
  v19 = a1;
  _frame.a2a[2] = v14;
  _frame.a3a[0] = v15;
  v20 = a2[35];
  _frame.v57 = a1;
  _frame.a2a[0] = v16;
  a2[159] = 0.0;
  a2[160] = 0.0;
  _frame.v56 = a3;
  _frame.a3a[1] = v20;
  _frame.a3a[2] = v17;
  compare_float_samples(0, _frame.a2a, _frame.a3a, a4);
  if ( v19 > 0 )
  {
    v21 = _frame.v60;
    v22 = a2;
    v23 = &a2[v19];
    while ( ++v22 != v23 )
    {
      while ( 1 )
      {
        v24 = *((volatile uint8_t *)v21 + 1);
        v21 = (volatile uint32_t *)((volatile char *)v21 + 1);
        if ( v24 != 1 )
          break;
        v25 = *(volatile float *)(a4 + 8);
        v26 = v22[32];
        v27 = v25 * *v22++;
        v28 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(v27 - v26) + *(volatile float *)(a4 + 12)));
        v29 = ((uint64_t (*)())aeabi_dadd)(v28, v28);
        v30 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT((float)(v25 * v25) + 1.0));
        v31 = ((uint64_t (*)())aeabi_dsub)(v29, v30);
        v32 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v18));
        v33 = double_add(v31, v32);
        v18 = COERCE_FLOAT(((int (*)(uint64_t))aeabi_dmul)(v33));
        if ( v22 == v23 )
          goto LABEL_6;
      }
    }
  }
LABEL_6:
  if ( !_frame.v56 )
  {
    check_interrupt_flag(1, aDpdBypassStatu);
    v34 = _frame.v57;
    if ( _frame.v57 > 0 )
      goto LABEL_8;
LABEL_20:
    v45 = flt_109BE8;
    v46 = flt_109BE8;
    v49 = _frame.v56;
    goto LABEL_18;
  }
  check_interrupt_flag(1, aDbdCalAmpmTabl);
  v34 = _frame.v57;
  if ( _frame.v57 <= 0 )
    goto LABEL_20;
LABEL_8:
  v35 = 4 * v34 + 384;
  v36 = _frame.v60;
  v37 = a2 + 96;
  v38 = flt_109BE8;
  v39 = (volatile float *)((volatile char *)a2 + v35);
  v40 = _frame.v60;
  v41 = a2 + 96;
  v42 = 0;
  while ( ++v41 != v39 )
  {
    while ( 1 )
    {
      v43 = *((volatile uint8_t *)v40 + 1);
      v40 = (volatile uint32_t *)((volatile char *)v40 + 1);
      if ( v43 != 1 )
        break;
      v44 = *v41++;
      v38 = v38 + v44;
      ++v42;
      if ( v41 == v39 )
        goto LABEL_12;
    }
  }
LABEL_12:
  v45 = (float)v42;
  v46 = flt_109BE8;
  v47 = v38 / (float)v42;
  v48 = (volatile float *)((volatile char *)a2 + v35);
  v49 = _frame.v56;
  v50 = &a2[_frame.v56];
  while ( v48 != ++v37 )
  {
    while ( 1 )
    {
      v51 = *((volatile uint8_t *)v36 + 1);
      v36 = (volatile uint32_t *)((volatile char *)v36 + 1);
      if ( v51 != 1 )
        break;
      v52 = *v37 - v47;
      if ( (float)i32_abs((int)v52) > v50[159] )
        v50[159] = (float)i32_abs((int)v52);
      ++v37;
      v46 = v46 + (float)(v52 * v52);
      if ( v48 == v37 )
        goto LABEL_18;
    }
  }
LABEL_18:
  v53 = &a2[v49];
  v54 = flt_109BF0;
  v53[128] = v18 / v45;
  v53[130] = v46 / v45;
  return check_interrupt_flag(
           1,
           "am_var*1000000=%10d ph_var*1000000=%10d\n",
           (int)(float)((float)(v18 / v45) * v54),
           (int)(float)((float)(v46 / v45) * v54));
}


// mmio_set_flag @ 0x109bf8
int mmio_set_flag( int a1, volatile int *a2, int a3, int a4, int a5, uint8_t a6, int a7, int a8, int a9, int a10, int a11) {
  volatile uint32_t *v11; // r4
  uint8_t v15; // r10
  volatile int *v16; // r5
  volatile int *v17; // r2
  volatile int *v18; // r3
  int v19; // r0
  volatile int *v20; // r4
  int v21; // t1
  int v22; // r6
  int v23; // t1
  int v24; // r1
  int v25; // t1
  int result; // r0
  volatile uint32_t *v27; // r3
  int v28; // r1
  volatile uint32_t *v29; // r2
  volatile uint32_t *v30; // r0
  volatile uint32_t *v31; // r1
  int v32; // r5
  volatile int *v33; // r3
  int v34; // t1
  uint8_t v35[20]; // [sp+18h] [bp-14h] BYREF

  v11 = (void *)(uintptr_t)(off_109D24);
  *(volatile uint32_t *)off_109D24 |= 0x400u;
  *v11 &= ~0x400u;
  v15 = a4;
  check_interrupt_flag(1, "cal %x index\n", a1);
  if ( a5 )
  {
    wlan_init_globals((int)a2, 1, 0x100000, 0x100000, 0, 1);
    return invoke_handler_14a99c(24, (volatile float *)a2, 1, (int)v35);
  }
  else
  {
    if ( a8 == 1 )
    {
      wlan_init_globals((int)a2, 1, 0x100000, 0x100000, 0, 0);
      invoke_handler_14a99c(24, (volatile float *)a2, 0, (int)v35);
      v29 = (volatile uint32_t *)dword_109D2C;
      v30 = (volatile uint32_t *)dword_109D30;
      v31 = (volatile uint32_t *)dword_109D34;
      v32 = dword_109D2C + 128;
      v33 = a2;
      do
      {
        v34 = *v33++;
        *v29++ = v34;
        *v30++ = v33[31];
        *v31++ = v33[95];
      }
      while ( v29 != (volatile uint32_t *)v32 );
    }
    else
    {
      v16 = (volatile int *)dword_109D2C;
      v17 = (volatile int *)dword_109D30;
      v18 = (volatile int *)dword_109D34;
      v19 = dword_109D2C + 128;
      v20 = a2;
      do
      {
        v21 = *v16++;
        *v20++ = v21;
        v23 = *v17++;
        v22 = v23;
        v20[31] = v23;
        v25 = *v18++;
        v24 = v25;
        v20[95] = v25;
        v20[63] = v22;
      }
      while ( v16 != (volatile int *)v19 );
      heap_calloc(a2, v24, a9, a10, (volatile uint64_t *)a11);
    }
    rx_packet_handler(16, 32, (int)a2, a3, v15, 1, a6, a1, a7);
    result = (int)bb_reset(a3);
    v27 = (void *)(uintptr_t)(off_109D38);
    v28 = dword_109D3C;
    *(volatile uint32_t *)off_109D38 &= ~0x200u;
    *v27 |= 0x200u;
    *v27 &= ~0x200u;
    a2[129] = v28;
    a2[131] = v28;
  }
  return result;
}


// process_signal_buffer @ 0x109d40
int process_signal_buffer( volatile uint32_t *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) {
  volatile uint32_t *v11; // r10
  int v13; // r1
  int v14; // r2
  float v15; // s20
  int v17; // r7
  unsigned int v19; // r3
  int v20; // r11
  unsigned int v21; // r0
  volatile char *v22; // r7
  int v23; // r4
  float v24; // s16
  float v25; // s21
  float v26; // s22
  float v27; // s17
  int v28; // r8
  float v29; // s23
  float v30; // s16
  int v31; // s25
  unsigned int v32; // s15
  uint64_t v33; // r0
  int v34; // r3
  int v35; // cc
  int result; // r0
  volatile uint32_t *v37; // r3
  struct __attribute__((packed)) { int v38; // [sp+20h] [bp-20h]
  int v39; // [sp+24h] [bp-1Ch]
  char _pad2[4]; int v40; // [sp+2Ch] [bp-14h]
  int a1a; // [sp+30h] [bp-10h]
  volatile int *v42; // [sp+34h] [bp-Ch]
  volatile int *v43; // [sp+38h] [bp-8h]
  volatile unsigned int *v44; // [sp+3Ch] [bp-4h]
  uint32_t v45[3]; // [sp+40h] [bp+0h] BYREF
  int a2a[5]; // [sp+4Ch] [bp+Ch] BYREF
  char _pad9[492]; float v47; // [sp+24Ch] [bp+20Ch]
  float v48; // [sp+250h] [bp+210h]
  float v49; // [sp+254h] [bp+214h]
  float v50; // [sp+258h] [bp+218h]
  char v51; // [sp+25Ch] [bp+21Ch] BYREF
  char _pad14[95]; int v52; // [sp+2BCh] [bp+27Ch]
  char _pad15[12]; unsigned int v53; // [sp+2CCh] [bp+28Ch]
  uint8_t v54[1204]; // [sp+2D0h] [bp+290h] BYREF
  } _frame;
  v11 = (void *)(uintptr_t)(off_10A0BC);
  v13 = ((volatile uint32_t *)(uintptr_t)off_10A070)[1];
  v14 = ((volatile uint32_t *)(uintptr_t)off_10A070)[2];
  _frame.v45[0] = ((volatile uint32_t *)(uintptr_t)off_10A070)[0];
  _frame.v45[1] = v13;
  _frame.v45[2] = v14;
  v15 = flt_10A074;
  _frame.v42 = (void *)(_frame.v45);
  *(volatile uint32_t *)(a5 + 4 * a4) = 1;
  _frame.v44 = (volatile unsigned int *)(a2 - 4);
  _frame.v40 = 1;
  _frame.v43 = (volatile int *)(a5 + 4 * a4);
  v17 = 0;
  while ( 2 )
  {
    v19 = _frame.v44[1];
    ++_frame.v44;
    v20 = (uint8_t)v17;
    if ( !v19 )
    {
      check_interrupt_flag(1, "===========table[%d]===========\n", v17);
      check_interrupt_flag(1, "table %d dont need cal.\n", v17);
      goto LABEL_28;
    }
    if ( !a4 && v17 == 1 )
    {
      check_interrupt_flag(1, a24gTable1DontN);
      goto LABEL_29;
    }
    check_interrupt_flag(1, "===========table[%d]===========\n", v17);
    v21 = *_frame.v44;
    _frame.v52 = 0;
    phy_set_txpower(v21, (int)_frame.a2a, a4);
    check_interrupt_flag(1, "table %d cal %d times.\n", v17, _frame.v52);
    _frame.v38 = *_frame.v42;
    if ( _frame.v52 <= 0 )
      goto LABEL_27;
    _frame.a1a = v17;
    _frame.v39 = 0;
    v22 = &_frame.v51;
    do
    {
      v23 = *((volatile uint32_t *)v22 + 16);
      while ( !*a1 )
        write_timer_reg(1);
      check_interrupt_flag(1, aStDpdCal);
      prcm_stop((int)_frame.a2a, (int)_frame.v54, v20, v23, a4, 0);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      mmio_set_flag(v23, _frame.a2a, (int)_frame.v54, v20, 0, a4, a6, a7, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      check_interrupt_flag(1, aDpdCalEnd);
      while ( !a1[1] )
        write_timer_reg(1);
      v24 = flt_10A08C;
      check_interrupt_flag(1, aStDpdVerify);
      prcm_stop((int)_frame.a2a, (int)_frame.v54, v20, v23, a4, 1);
      *v11 &= ~0x8000u;
      *v11 &= ~0x2000u;
      mmio_set_flag(v23, _frame.a2a, (int)_frame.v54, v20, 1, a4, a6, 0, a9, a10, a11);
      *v11 |= 0x8000u;
      *v11 |= 0x2000u;
      check_interrupt_flag(1, aDpdCalEnd);
      check_interrupt_flag(1, aDefaultDpdCal);
      check_interrupt_flag(1, "am*1000000:%6d  %d\n", (int)(float)(_frame.v47 * v24), (int)(float)(_frame.v48 * v24));
      check_interrupt_flag(1, "ph*1000000:%6d  %d\n", (int)(float)(_frame.v49 * v24), (int)(float)(_frame.v50 * v24));
      v25 = _frame.v47 / _frame.v48;
      v26 = _frame.v49 / _frame.v50;
      if ( v23 == 11 )
      {
        v27 = 3.0;
        v29 = 3.0;
        v28 = 30000;
      }
      else if ( (unsigned int)(v23 - 12) <= 1 )
      {
        v29 = flt_10A344;
        v28 = 11000;
        v27 = 3.0;
      }
      else if ( v23 == 14 )
      {
        v29 = flt_10A348;
        v28 = 13000;
        v27 = 3.0;
      }
      else if ( v23 <= 7 )
      {
        v27 = v15;
        v29 = v15;
        v28 = 10010;
      }
      else
      {
        v27 = flt_10A09C;
        v28 = 11000;
        v29 = flt_10A09C;
      }
      v30 = flt_10A0A0;
      check_interrupt_flag(1, "am_compare_thr * 10000 = %6d  ", v28);
      check_interrupt_flag(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
      v31 = (int)(float)(v25 * v30);
      check_interrupt_flag(1, "am_compare     * 10000 = %6d  ", v31);
      check_interrupt_flag(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
      check_interrupt_flag(1, "verify_ph_var_sum * 10000 = %6d\n", (int)(float)(_frame.v49 * v30));
      if ( v29 >= v25 )
      {
        v32 = _frame.v53;
        if ( *(volatile float *)&_frame.v53 < 2.0 )
          goto LABEL_19;
        *(volatile uint32_t *)v22 = 0;
        *((volatile uint32_t *)v22 + 8) = 0;
        check_interrupt_flag(1, "am_compare_thr * 10000 = %6d  ", v28);
        check_interrupt_flag(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
        check_interrupt_flag(1, "am_compare     * 10000 = %6d  ", (int)(float)(v25 * v30));
        check_interrupt_flag(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
        check_interrupt_flag(1, "table[%d] dpd cal is not good, ana_index %x use default.\n", _frame.a1a, v23);
        if ( v23 <= 10 && _frame.a1a == 1 )
        {
          _frame.v40 = 0;
          dispatch_event_handler_1("table 1 index %x dont use dpd\n", v23);
          *(volatile uint32_t *)v22 = 1;
          *((volatile uint32_t *)v22 + 8) = 1;
        }
      }
      else
      {
        if ( v27 < v26 )
        {
          v32 = _frame.v53;
LABEL_19:
          *(volatile uint32_t *)v22 = 1;
          *((volatile uint32_t *)v22 + 8) = 1;
if ( v23 <= 8 && v27 > v26 && (v33 = ((uint64_t (*)())aeabi_d2f)(v32), ((int (*)())double_gt)(v33, *(volatile uint64_t *)&dword_10A068)) && _frame.a1a == 1 ) { check_interrupt_flag(1, "am_compare_thr * 10000 = %6d  ", v28);
            check_interrupt_flag(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            check_interrupt_flag(1, "am_compare     * 10000 = %6d  ", v31);
            check_interrupt_flag(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            check_interrupt_flag(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(volatile float *)&_frame.v53 * flt_10A360));
            check_interrupt_flag(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            _frame.v40 = 0;
          }
          else
          {
            check_interrupt_flag(1, "table[%d] dpd cal success, ana_index %x can be used.\n", _frame.a1a, v23);
            _frame.v40 = 1;
          }
          goto LABEL_24;
        }
        v32 = _frame.v53;
        if ( *(volatile float *)&_frame.v53 < 2.0 )
          goto LABEL_19;
        *(volatile uint32_t *)v22 = 1;
        *((volatile uint32_t *)v22 + 8) = 0;
        check_interrupt_flag(1, "table[%d] dpd cal success, ph deviation is small, ana_index %x can be used.\n", _frame.a1a, v23);
        if ( v23 <= 8 && _frame.a1a == 1 )
        {
          if ( *(volatile float *)&_frame.v53 > 2.0 )
          {
            check_interrupt_flag(1, "am_compare_thr * 10000 = %6d  ", v28);
            check_interrupt_flag(1, "ph_compare_thr * 10000 = %6d\n", (int)(float)(v27 * v30));
            check_interrupt_flag(1, "am_compare     * 10000 = %6d  ", v31);
            check_interrupt_flag(1, "ph_compare     * 10000 = %6d\n", (int)(float)(v26 * v30));
            check_interrupt_flag(1, "dpd_ampm.degree_max[1]     * 10000 = %6d\n", (int)(float)(*(volatile float *)&_frame.v53 * v30));
            check_interrupt_flag(1, "verify ph is larger, table 1 index %x dont use dpd\n", v23);
            _frame.v40 = 0;
            check_interrupt_flag(1, "table 1 index %x dont use dpd\n", v23);
          }
          else
          {
            _frame.v40 = 1;
          }
        }
        else
        {
          _frame.v40 = 1;
        }
      }
LABEL_24:
      _frame.v38 &= *(volatile uint32_t *)v22;
      v34 = *_frame.v43 & _frame.v40;
      v35 = _frame.v52 <= ++_frame.v39;
      *_frame.v42 = _frame.v38;
      v22 += 4;
      *_frame.v43 = v34;
    }
    while ( !v35 );
    v17 = _frame.a1a;
LABEL_27:
    *_frame.v44 = *_frame.v44 & 0xFFFEFFFF | (_frame.v38 << 16);
LABEL_28:
    if ( v20 != 2 )
    {
LABEL_29:
      ++v17;
      ++_frame.v42;
      continue;
    }
    break;
  }
  while ( !a1[2] )
    write_timer_reg(1);
  result = check_interrupt_flag(1, aDpdUse);
  v37 = (void *)(uintptr_t)(off_10A350);
  *(volatile uint32_t *)off_10A350 &= ~0x200u;
  *v37 |= 0x200u;
  *v37 &= ~0x200u;
  return result;
}


// validate_packet_length @ 0x10a36c
int validate_packet_length(int a1, unsigned int a2, volatile uint8_t *a3, volatile int *a4) {
  volatile uint8_t *v6; // r6
  volatile uint8_t *v7; // r9
  int i; // r8
  int v9; // r2
  int v10; // r0
  int v11; // r4
  char v12; // r0
  volatile float *v13; // r5
  int v14; // r4
  volatile float *v15; // r2
  int v16; // r3
  int v17; // r1
  int v18; // r0
  volatile uint8_t *v19; // r1
  int v20; // r2
  int v21; // r4
  float v23; // s12
  float v24; // s13
  float v25; // s14
  float v26; // s15
  int v27; // r3
  int v28; // r0
  int v29; // r3
  struct __attribute__((packed)) { float v30[3]; // [sp+0h] [bp-58h] BYREF
  float a2a[3]; // [sp+Ch] [bp-4Ch] BYREF
  uint8_t v32[4]; // [sp+18h] [bp-40h] BYREF
  uint8_t var3C[92]; // [sp+1Ch] [bp-3Ch] BYREF
  } _frame;
  if ( a2 > 9 && a1 != 3 )
  {
    v6 = a3 - 1;
    v7 = _frame.v32;
    for ( i = 0; i != 4; ++i )
    {
      v9 = 0;
      v10 = 0;
      do
      {
        if ( (uint8_t)i != (uint8_t)v9 )
        {
          if ( (uint8_t)v9 )
          {
            _frame.v30[v10] = (float)v6[v9];
            v11 = 4 * v10;
          }
          else
          {
            v11 = 4 * v10;
            _frame.v30[v10] = 128.0;
          }
          v10 = (uint8_t)(v10 + 1);
          *(volatile float *)&_frame.var3C[v11 - 16] = (float)a4[v9];
        }
        ++v9;
      }
      while ( v9 != 4 );
      *v7 = 0;
      v12 = float_compare(_frame.v30, _frame.a2a);
      *v7 = v12;
      if ( (v12 & 0xE) == 0 )
        compare_float_samples(a2, _frame.v30, _frame.a2a, (int)v7);
      v7 += 16;
    }
    v13 = (volatile float *)_frame.var3C;
    v14 = 0;
    v15 = (volatile float *)_frame.var3C;
    v16 = 0;
    v17 = 128;
    do
    {
      v18 = *((volatile uint8_t *)v15 - 4);
      if ( *((volatile uint8_t *)v15 - 4) )
      {
        if ( (v18 & 8) != 0 )
          goto LABEL_42;
        if ( v18 == 1 )
          v14 = 1;
      }
      else if ( v17 == 128 )
      {
        v17 = v16;
      }
      else if ( *v15 <= *(volatile float *)&_frame.var3C[16 * v17] )
      {
        v17 = v16;
      }
      v16 = (uint8_t)(v16 + 1);
      v15 += 4;
    }
    while ( v16 != 4 );
    if ( v14 )
    {
      if ( v17 != 128 )
      {
LABEL_21:
        v19 = &_frame.var3C[16 * v17 + 60];
        v20 = (uint8_t)*(v19 - 64);
        v21 = (uint8_t)*(v19 - 63);
        if ( !*(v19 - 64) )
          return v21;
        goto LABEL_22;
      }
      v29 = 0;
      do
      {
        if ( *((volatile uint8_t *)v13 - 4) == 1 )
        {
          if ( v17 == 128 )
          {
            v17 = v29;
          }
          else if ( *v13 <= *(volatile float *)&_frame.var3C[16 * v17] )
          {
            v17 = v29;
          }
        }
        v29 = (uint8_t)(v29 + 1);
        v13 += 4;
      }
      while ( v29 != 4 );
    }
    if ( v17 == 128 )
    {
LABEL_42:
      v21 = 32 * (9 - a2);
      log_printf("gain %x : fit_failed!\r\n", a2);
      return v21;
    }
    goto LABEL_21;
  }
  v23 = (float)a3[1];
  v24 = (float)*a4;
  v25 = (float)a4[1];
  v26 = (float)a4[2];
  _frame.v30[1] = (float)*a3;
  _frame.v30[2] = v23;
  _frame.a2a[0] = v24;
  _frame.a2a[1] = v25;
  _frame.a2a[2] = v26;
  _frame.v30[0] = 128.0;
  _frame.v32[0] = 0;
  if ( a2 > 9 )
  {
    v28 = float_compare(_frame.v30, _frame.a2a);
    _frame.v32[0] = v28;
    if ( (v28 & 0xE) != 0 )
    {
      v20 = v28;
    }
    else
    {
      compare_float_samples(a2, _frame.v30, _frame.a2a, (int)_frame.v32);
      v27 = _frame.v32[0];
      v20 = _frame.v32[0];
      if ( (_frame.v32[0] & 0xE) == 0 )
        goto LABEL_26;
    }
    v21 = 32 * (9 - a2);
    log_printf("gain %x : fit_status %d\r\n", a2, v20);
    return v21;
  }
  compare_float_samples(a2, _frame.v30, _frame.a2a, (int)_frame.v32);
  v20 = _frame.v32[0];
  v27 = _frame.v32[0];
  if ( (_frame.v32[0] & 0xE) != 0 )
  {
    v21 = 128;
    log_printf("gain %x : fit_status %d\r\n", a2, _frame.v32[0]);
    return v21;
  }
LABEL_26:
  v21 = _frame.v32[1];
  if ( v27 )
  {
LABEL_22:
    log_printf("gain %x : fit_status %d\r\n", a2, v20);
    return v21;
  }
  return v21;
}


// read_radio_status @ 0x10a5b0
int read_radio_status(unsigned int a1, unsigned int a2, int a3, unsigned int a4, uint8_t a5, char a6) {
  unsigned int v8; // s17
  int v9; // r3
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r5
  volatile uint32_t *v12; // r7
  volatile unsigned int *v13; // r3
  volatile unsigned int *v14; // r1
  volatile uint32_t *v15; // r6
  volatile unsigned int *v16; // r11
  volatile unsigned int *v17; // r0
  int v18; // s16
  volatile unsigned int *v19; // r10
  unsigned int v20; // r8
  int v21; // r6
  int v22; // r5
  int v23; // r4
  int v24; // zf
  unsigned int v25; // r4
  int v26; // r1
  int v27; // r6
  unsigned int v28; // r7
  int16_t v29; // r4
  int16_t v30; // r0
  unsigned int v31; // r2
  uint8_t v32; // r1
  unsigned int i; // r3
  unsigned int v34; // r4
  unsigned int v35; // r9
  volatile uint32_t *v36; // r1
  volatile unsigned int *v37; // r3
  volatile unsigned int *v38; // r1
  int16_t v39; // r3
  volatile uint32_t *v40; // r3
  volatile unsigned int *v42; // r3
  struct __attribute__((packed)) { int v43; // [sp+24h] [bp-7C0h]
  int v44; // [sp+28h] [bp-7BCh]
  char _pad2[8]; int v45; // [sp+34h] [bp-7B0h]
  int v46; // [sp+38h] [bp-7ACh]
  char _pad4[8]; unsigned int a1a; // [sp+44h] [bp-7A0h]
  int v49; // [sp+48h] [bp-79Ch]
  char _pad6[14]; char a3a; // [sp+5Ah] [bp-78Ah] BYREF
  char v53; // [sp+5Bh] [bp-789h] BYREF
  char v54[4]; // [sp+5Ch] [bp-788h] BYREF
  int result; // [sp+60h] [bp-784h] BYREF
  unsigned int a2a; // [sp+64h] [bp-780h] BYREF
  uint16_t v57[6]; // [sp+68h] [bp-77Ch] BYREF
  uint16_t v58[952]; // [sp+74h] [bp-770h] BYREF
  } _frame;
  check_interrupt_flag(
    0x2000,
    "page %x,sdm %x,freq %x,lock %x,rfen %x\n",
    (*(volatile uint32_t *)off_10A8E4 >> 3) & 7,
    *(volatile uint32_t *)off_10A8B0,
    *(volatile uint32_t *)off_10A8B4,
    *(volatile uint32_t *)off_10A8B8,
    *(volatile uint32_t *)off_10A8BC);
  v8 = ((a1 >> 1) & 1) + 3;
  if ( (a1 & 0xC) != 0 )
  {
    if ( ((a1 >> 2) & 3) == 1 )
      v9 = 5;
    else
      v9 = 10;
    _frame.a1a = v9;
  }
  else
  {
    _frame.a1a = 1;
  }
  v10 = (void *)(uintptr_t)(off_10A8C4);
  v11 = (void *)(uintptr_t)(off_10A8C8);
  v12 = (void *)(uintptr_t)(off_10A8CC);
  v13 = (volatile unsigned int *)off_10A8D0;
  v14 = (volatile unsigned int *)off_10A8D4;
  v15 = (void *)(uintptr_t)(off_10A8D8);
  v16 = (volatile unsigned int *)off_10A8E8;
  *(volatile uint32_t *)off_10A8C4 &= ~4u;
  *v11 &= 0xFFFF0FFF;
  *v12 = 0;
  *v13 |= 0x80u;
  *v14 |= 0x80000000;
  *v10 |= 4u;
  *v15 = HIWORD(*v15) << 16;
  *(v12 - 6154) = *(v12 - 6154) & 0xCFFFFFFF | 0x10000000;
  v17 = (volatile unsigned int *)off_10A8DC;
  *v10 &= ~4u;
  *v14 &= ~0x80000000;
  *v13 &= ~0x80u;
  *v10 |= 4u;
  v15[6223] |= 2u;
  *v13 = *v13 & 0xFFFF8FFF | 0x4000;
  *v13 = *v13 & 0xF8FFFFFF | 0x6000000;
  *v13 = *v13 & 0xFFFFF8FF | 0x100;
  *v13 &= ~4u;
  *v13 |= 1u;
  *v13 |= 8u;
  *v14 = a3 | *v14 & 0x80000000;
  *v17 |= 0x2000000u;
  *v17 |= 0x10000u;
  _frame.v43 = 0;
  _frame.v49 = ((v10[2069] >> 3) & 7) << 6;
  v18 = 0;
  v19 = v17;
  _frame.v46 = -1;
  do
  {
    _frame.v45 = 0;
    do
    {
      if ( a4 <= a5 )
      {
        v20 = a4;
        do
        {
          *v16 = dword_10A8E0 & (((uint16_t)_frame.v49 | (4 * v20) | 1) << 8) | *v16 & 0xFFFE00FF;
          *v16 |= 0x20000u;
          *v16 |= 0x40000u;
          write_timer_reg(1);
          if ( _frame.v43 )
          {
            if ( _frame.v45 )
            {
              v21 = (uint16_t)v20;
            }
            else
            {
              mac_frame_parse_fcf(v18, v20, &_frame.a3a, (volatile char *)&_frame.v58[6] + 3 * v20, (volatile int *)&_frame.v58[8 * v20 + 54]);
              v21 = (uint16_t)v20;
              mac_frame_parse_fcf(v18, v20, &_frame.v53, (volatile char *)&_frame.v58[30] + 3 * v20, (volatile int *)&_frame.v58[8 * v20 + 182]);
            }
            v22 = *((volatile uint8_t *)&_frame.v58[6] + 3 * v20 + _frame.v46);
            v23 = *((volatile uint8_t *)&_frame.v58[30] + 3 * v20 + _frame.v46);
            *v19 = *v19 & 0xFE01FFFF | (v22 << 17);
            *v19 = *v19 & 0xFFFF00FF | (v22 << 8);
            rf_wait_for_command((void *)(&_frame.result), &_frame.a2a);
            if ( v22 != v23 )
            {
              *v19 = *v19 & 0xFE01FFFF | (v23 << 17);
              *v19 = *v19 & 0xFFFF00FF | (v23 << 8);
              rf_wait_for_command((void *)(_frame.v54), &_frame.a2a);
            }
          }
          else
          {
            *v19 = *v19 & 0xFE01FFFF | 0x1000000;
            *v19 = *v19 & 0xFFFF00FF | 0x8000;
            rf_wait_for_command((void *)(&_frame.result), &_frame.a2a);
            v21 = (uint16_t)v20;
          }
          atomic_write_if_zero((uint8_t)_frame.v45, _frame.result, (void *)(&_frame.v58[20 * v21 + 310]));
          atomic_write_if_zero((uint8_t)_frame.v45, _frame.a2a, (void *)(&_frame.v58[20 * v20 + 630]));
          v20 = (uint8_t)(v20 + 1);
        }
        while ( a5 >= v20 );
      }
      v24 = _frame.a1a == ++_frame.v45;
    }
    while ( !v24 );
    if ( a4 <= a5 )
    {
      v25 = a4;
      do
      {
        while ( 1 )
        {
          v27 = _frame.v43 + 4 * v25;
          if ( _frame.a1a != 1 )
            break;
          *(volatile uint32_t *)&_frame.v58[2 * v27 + 54] = *(volatile uint32_t *)&_frame.v58[20 * v25 + 310];
          *(volatile uint32_t *)&_frame.v58[2 * v27 + 182] = *(volatile uint32_t *)&_frame.v58[20 * v25 + 630];
          v25 = (uint8_t)(v25 + 1);
          if ( a5 < v25 )
            goto LABEL_28;
        }
        if ( v25 >= 6 )
          v26 = 100;
        else
          v26 = 50;
        _frame.v44 = v26;
        *(volatile uint32_t *)&_frame.v58[2 * v27 + 54] = swar_bit_count(_frame.a1a, v26, (volatile int *)&_frame.v58[20 * v25 + 310]);
        *(volatile uint32_t *)&_frame.v58[2 * v27 + 182] = swar_bit_count(_frame.a1a, _frame.v44, (volatile int *)&_frame.v58[20 * v25 + 630]);
        v25 = (uint8_t)(v25 + 1);
      }
      while ( a5 >= v25 );
    }
LABEL_28:
    ++_frame.v46;
    v18 = (uint8_t)++_frame.v43;
  }
  while ( v8 > (uint8_t)_frame.v43 );
  if ( a4 > a5 )
  {
    memzero_words((a1 >> 5) & 1, _frame.v57);
    memzero_words((a1 >> 5) & 1, _frame.v58);
  }
  else
  {
    v28 = a4;
    do
    {
      v29 = validate_packet_length(v8, v28, (volatile uint8_t *)&_frame.v58[6] + 3 * v28, (volatile int *)&_frame.v58[8 * v28 + 54]);
      v30 = validate_packet_length(v8, v28, (volatile uint8_t *)&_frame.v58[30] + 3 * v28, (volatile int *)&_frame.v58[8 * v28 + 182]);
      v31 = v28 - 10;
      if ( v28 > 9 )
        _frame.v57[v31] = v29;
      else
        v31 = a2;
      if ( v28 <= 9 )
        *(volatile uint16_t *)(v31 + 2 * (uint16_t)v28) = (uint8_t)v29 | (uint16_t)(v30 << 8);
      v32 = v28 + 1;
      if ( v28 > 9 )
        _frame.v58[v31] = v30;
      v28 = v32;
    }
    while ( a5 >= (unsigned int)v32 );
    memzero_words((a1 >> 5) & 1, _frame.v57);
    memzero_words((a1 >> 5) & 1, _frame.v58);
    for ( i = a4; ; i = (uint8_t)(i + 1) )
    {
      if ( i > 9 )
        *(volatile uint16_t *)(a2 + 2 * (uint16_t)i) = LOBYTE(_frame.v57[i - 10]) | (uint16_t)(_frame.v58[i - 10] << 8);
      if ( a5 == i )
        break;
    }
    v34 = a4;
    do
    {
      v35 = *(volatile uint16_t *)(a2 + 2 * v34);
      check_interrupt_flag(
        0x2000,
        "fit-in-I %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        (uint8_t)v35,
        128,
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 54],
        *((volatile uint8_t *)&_frame.v58[6] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 56],
        *((volatile uint8_t *)&_frame.v58[6] + 3 * v34 + 1),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 58],
        *((volatile uint8_t *)&_frame.v58[7] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 60]);
      check_interrupt_flag(
        0x2000,
        "fit-in-Q %x %x: [%d,%d;%d,%d;%d,%d;%d,%d]\r\n",
        v34,
        v35 >> 8,
        128,
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 182],
        *((volatile uint8_t *)&_frame.v58[30] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 184],
        *((volatile uint8_t *)&_frame.v58[30] + 3 * v34 + 1),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 186],
        *((volatile uint8_t *)&_frame.v58[31] + 3 * v34),
        *(volatile uint32_t *)&_frame.v58[8 * v34 + 188]);
      v24 = a5 == v34;
      v34 = (uint8_t)(v34 + 1);
    }
    while ( !v24 );
  }
  v36 = (void *)(uintptr_t)(off_10AC04);
  v37 = (volatile unsigned int *)off_10AC08;
  *(volatile uint32_t *)off_10AC04 &= ~2u;
  *v37 |= 4u;
  *v37 = *v37 & 0xFFFF8FFF | 0x3000;
  *v37 = *v37 & 0xFFFFF8FF | 0x600;
  *v37 &= ~8u;
  *v37 &= ~1u;
  *(v36 - 6224) &= 0xCFFFFFFF;
  if ( a6 )
  {
    v38 = (volatile unsigned int *)off_10AC0C;
    v39 = *(volatile uint16_t *)(a2 + 2 * a4);
    *(volatile uint32_t *)off_10AC0C = *(volatile uint32_t *)off_10AC0C & 0xFE01FFFF | ((uint8_t)v39 << 17);
    *v38 = v39 & 0xFF00 | *v38 & 0xFFFF00FF;
  }
  else
  {
    v42 = (volatile unsigned int *)off_10AC0C;
    *(volatile uint32_t *)off_10AC0C &= ~0x2000000u;
    *v42 &= ~0x10000u;
    *v42 = *v42 & 0xFE01FFFF | 0x1000000;
    *v42 = *v42 & 0xFFFF00FF | 0x8000;
  }
  v40 = (void *)(uintptr_t)(off_10AC10);
  *(volatile uint32_t *)off_10AC10 &= 0xFFFE00FF;
  *v40 &= ~0x20000u;
  *v40 |= 0x40000u;
  return check_interrupt_flag(0x2000, aWfDccalibEnd);
}


// configure_dma_regs @ 0x10ac18
int configure_dma_regs(int a1, volatile uint8_t *a2, int a3) {
  int v3; // r9
  int v4; // r10
  int v5; // r11
  int v7; // r1
  unsigned int v8; // r2
  int v9; // lr
  int v10; // r12
  int v11; // r0
  volatile int *v12; // r2
  int v13; // r4
  volatile unsigned int *v14; // r1
  volatile unsigned int *v15; // r6
  volatile int *v16; // r4
  unsigned int v17; // r3
  volatile uint32_t *v18; // r4
  int v19; // r3
  volatile uint32_t *v20; // r9
  int v21; // r10
  unsigned int v22; // r4
  int v23; // r5
  int v24; // r4
  int v25; // r7
  int v26; // r9
  int v27; // r0
  volatile int *v28; // r10
  int v29; // r1
  int v30; // r12
  volatile unsigned int *v31; // r2
  volatile unsigned int *v32; // r8
  volatile int *v33; // r12
  int v34; // t1
  volatile uint32_t *v35; // r0
  int v37; // r8
  volatile unsigned int *v38; // r2
  volatile int *v39; // lr
  volatile unsigned int *v40; // r8
  int v41; // t1
  int v42; // r6
  volatile unsigned int *v43; // r1
  volatile int *v44; // r5
  volatile unsigned int *v45; // r6
  unsigned int v46; // r3
  int v47; // s16
  int i; // r8
  int v49; // r10
  int v50; // r7
  int v51; // r5
  int v52; // r6
  int v53; // lr
  int v54; // r10
  int v55; // r3
  volatile unsigned int *v56; // r1
  int v57; // r12
  int v58; // r5
  volatile unsigned int *v59; // r11
  unsigned int v60; // r2
  unsigned int v61; // t1
  int v62; // r6
  volatile uint32_t *v63; // r0
  int v64; // r3
  int v65; // r0
  int v66; // cc
  int v67; // r3
  int v68; // r0
  struct __attribute__((packed)) { unsigned int a5; // [sp+0h] [bp-1CCh]
  char _pad1[12]; int a4; // [sp+10h] [bp-1BCh]
  int v71; // [sp+14h] [bp-1B8h]
  volatile unsigned int *a2a; // [sp+18h] [bp-1B4h]
  volatile uint8_t *v73; // [sp+1Ch] [bp-1B0h]
  volatile int *v74; // [sp+20h] [bp-1ACh]
  int v75; // [sp+24h] [bp-1A8h]
  char _pad7[12]; int v78; // [sp+34h] [bp-198h]
  uint8_t a1a[4]; // [sp+38h] [bp-194h] BYREF
  int v80; // [sp+3Ch] [bp-190h]
  uint16_t v81; // [sp+40h] [bp-18Ch]
  char _pad11[2]; uint32_t v82[14]; // [sp+44h] [bp-188h] BYREF
  int v83; // [sp+7Ch] [bp-150h]
  char _pad13[8]; uint8_t v84[128]; // [sp+88h] [bp-144h] BYREF
  uint8_t v85[196]; // [sp+108h] [bp-C4h] BYREF
  } _frame;
  v3 = dword_10AF6C;
  v4 = dword_10AF74;
  v5 = dword_10AF98;
  dispatch_event_handler_1(aMiscCalibLoftC);
  v7 = *(volatile uint32_t *)off_10AF50;
  v8 = *(volatile uint32_t *)off_10AF50 & 0xFFFFFFFE;
  *(volatile uint32_t *)_frame.a1a = 0;
  _frame.v80 = 0;
  _frame.v81 = 0;
  *(volatile uint32_t *)off_10AF50 = v8;
  _frame.v75 = v7 & 1;
  gpio_set_pin(0);
  v9 = dword_10AF70;
  v10 = dword_10AF78;
  v11 = 0;
  v12 = (volatile int *)_frame.v85;
  do
  {
    if ( v11 )
    {
      if ( v11 != 1 )
      {
        v13 = v10;
        goto LABEL_5;
      }
      v13 = v4;
      v42 = v5;
    }
    else
    {
      v13 = v3;
      v42 = v9;
    }
    v43 = (volatile unsigned int *)(v42 + 4);
    v44 = (volatile int *)&_frame.v84[64 * v11];
    v45 = (volatile unsigned int *)(v42 + 516);
    do
    {
      v46 = *v43;
      *v43 &= 0xFFF1FFFF;
      v43 += 8;
      *v44++ = (v46 >> 17) & 7;
    }
    while ( v43 != v45 );
LABEL_5:
    v14 = (volatile unsigned int *)(v13 + 4);
    v15 = (volatile unsigned int *)(v13 + 516);
    v16 = v12;
    do
    {
      v17 = *v14;
      *v14 &= 0xFFF1FFFF;
      v14 += 8;
      *v16++ = (v17 >> 17) & 7;
    }
    while ( v15 != v14 );
    ++v11;
    v12 += 16;
  }
  while ( v11 != 3 );
  v18 = (void *)(uintptr_t)(off_10AF54);
  gpio_clear_pin(0);
  check_interrupt_flag(1, aTrigger);
  *v18 |= 0x400u;
  *v18 &= ~0x400u;
  dispatch_event_handler_1(aLoftStart);
  check_interrupt_flag(1, aLoftCal);
  if ( (*(volatile uint32_t *)off_10AF64 & 2) != 0 )
    v19 = 8;
  else
    v19 = 56;
  v20 = v18;
  _frame.a4 = v19 + a3;
  do
  {
    v21 = *(volatile uint8_t *)(a3 + 5);
    v22 = *(volatile uint16_t *)(a3 + 2);
    *v20 |= 0x400u;
    *v20 &= ~0x400u;
    if ( v21 == 1 )
    {
      check_interrupt_flag(1, "**************************loft  freq= [%d] **************************\n", v22);
      if ( v22 > 0x1388 )
      {
        _frame.v81 = (_frame.v81 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        _frame.a1a[0] = 1;
        *(volatile uint16_t *)&_frame.a1a[2] = v22;
        _frame.v80 = (_frame.v80 & ~0xFFFFu) | ((uint16_t)(v22) & 0xFFFFu);
        _frame.v80 = (_frame.v80 & ~0xFFFF0000u) | (((uint16_t)(v22) & 0xFFFFu) << 16);
        tx_set_power(_frame.a1a, 0);
        v68 = rf_check_freq(v22);
        _frame.v74 = (void *)(&((volatile uint32_t *)(uintptr_t)off_10B040)[96 * v68]);
        _frame.a2a = (volatile unsigned int *)(a1 + 1264 * (uint8_t)(v68 + 1));
        v47 = (uint8_t)(v68 + 1);
        _frame.v73 = &a2[v47];
      }
      else
      {
        _frame.v80 = (_frame.v80 & ~0xFFFFu) | ((uint16_t)(v22) & 0xFFFFu);
        _frame.a1a[0] = 0;
        _frame.v81 = (_frame.v81 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
        tx_set_power(_frame.a1a, 0);
        _frame.v74 = (volatile int *)off_10AF8C;
        _frame.v73 = a2;
        v47 = 0;
        _frame.a2a = (volatile unsigned int *)a1;
        v21 = 0;
      }
      rf_transmit_packet((int)(_frame.a2a + 292), _frame.a2a, 255, 0, 0, dword_10AF90, 0);
      write_timer_reg(10000);
      _frame.v78 = a3;
      *_frame.v73 = 1;
      _frame.v71 = v21;
      for ( i = 0; i != 3; ++i )
      {
        if ( !_frame.a2a[i] )
          check_interrupt_flag(1, "table [%d] dont need change\n", i);
        if ( _frame.v71 == 1 )
        {
          if ( i )
          {
            if ( i == 1 )
              v49 = 1;
            else
              v49 = 2;
            if ( i == 1 )
              v50 = 8;
            else
              v50 = 9;
            if ( i == 1 )
              v51 = 64;
            else
              v51 = 96;
            if ( i == 1 )
              v52 = 32;
            else
              v52 = 64;
          }
          else
          {
            v49 = 0;
            v52 = 0;
            v50 = 9;
            v51 = 32;
          }
        }
        else
        {
          v49 = 2;
          v50 = 0;
          v51 = 96;
          v52 = 32;
        }
        _frame.a5 = (_frame.a2a[v49] >> 17) & 1;
        *_frame.v73 &= (_frame.a2a[v49] & 0x20000) != 0;
        check_interrupt_flag(1, "ch[%d] loft_ok[%d]=%d\n", v47, i, _frame.a5);
        mac_get_params(_frame.a2a[v49], _frame.v82);
        if ( v52 < v51 )
        {
          v53 = _frame.v83;
          v54 = _frame.v82[10];
          v55 = (int)&_frame.v74[v51 - 1];
          v56 = (volatile unsigned int *)&_frame.v74[v52 - 1];
          v57 = _frame.v83 - 1;
          v58 = 0;
          v59 = (volatile unsigned int *)v55;
          do
          {
            v61 = v56[1];
            ++v56;
            v60 = v61;
            v62 = (v61 >> 8) & 0xF;
            if ( v50 <= v62 )
            {
              if ( v53 == 1 )
              {
                v58 = v54 == v62;
              }
              else if ( v57 > 0 )
              {
                v58 = 0;
                v63 = _frame.v82;
                v64 = 1;
                if ( v62 < v54 )
                {
LABEL_46:
                  v64 = v58 + 1;
                  if ( _frame.v71 != 1 )
                    v58 = 1;
                  goto LABEL_48;
                }
                while ( 1 )
                {
                  if ( v63[11] > v62 )
                    v58 = v64;
                  else
                    v58 += 2;
LABEL_48:
                  v65 = v64;
                  v66 = v57 <= v64;
                  v67 = v64 + 10;
                  if ( v66 )
                    break;
                  v58 = v65;
                  v66 = v62 < _frame.v82[v67];
                  v63 = &_frame.v82[v65];
                  v64 = v58 + 1;
                  if ( v66 )
                    goto LABEL_46;
                }
              }
              *v56 = v60 & 0xE7FFFFFF | (v58 << 27);
            }
          }
          while ( v59 != v56 );
        }
      }
      a3 = _frame.v78;
    }
    a3 += 8;
  }
  while ( _frame.a4 != a3 );
  v23 = dword_10AF6C;
  v24 = dword_10AF70;
  v25 = dword_10AF74;
  v26 = dword_10AF98;
  dispatch_event_handler_1(aLoftEnd);
  gpio_set_pin(0);
  v27 = dword_10AF78;
  v28 = (volatile int *)_frame.v85;
  v29 = 0;
  while ( 2 )
  {
    if ( v29 )
    {
      if ( v29 != 1 )
      {
        v30 = v27;
        goto LABEL_18;
      }
      v30 = v25;
      v37 = v26;
    }
    else
    {
      v30 = v23;
      v37 = v24;
    }
    v38 = (volatile unsigned int *)(v37 + 4);
    v39 = (volatile int *)&_frame.v84[64 * v29];
    v40 = (volatile unsigned int *)(v37 + 484);
    do
    {
      v41 = *v39++;
      *v38 = *v38 & 0xFFF1FFFF | (v41 << 17);
      v38 += 8;
    }
    while ( v40 != v38 );
LABEL_18:
    v31 = (volatile unsigned int *)(v30 + 4);
    v32 = (volatile unsigned int *)(v30 + 484);
    v33 = v28;
    do
    {
      v34 = *v33++;
      *v31 = *v31 & 0xFFF1FFFF | (v34 << 17);
      v31 += 8;
    }
    while ( v32 != v31 );
    ++v29;
    v28 += 16;
    if ( v29 != 3 )
      continue;
    break;
  }
  gpio_clear_pin(0);
  v35 = (void *)(uintptr_t)(off_10AF7C);
  *(volatile uint32_t *)off_10AF50 = *(volatile uint32_t *)off_10AF50 & 0xFFFFFFFE | _frame.v75;
  check_interrupt_flag(1, "tia_aux_gbit000=%d\n", (*v35 >> 21) & 7);
  return dispatch_event_handler_1(aMiscLoftCalibS);
}


