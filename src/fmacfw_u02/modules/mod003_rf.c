// handle_tx_descriptor @ 0x104618
int handle_tx_descriptor(int a1, int a2, int a3) {
  unsigned int v3; // r3
  int v4; // r5
  int v5; // r0
  int v6; // r11
  int v7; // r10
  int v8; // r4
  int v9; // r0
  unsigned int v10; // s16
  uint64_t v11; // r8
  uint64_t v12; // r4
  uint64_t v13; // r6
  uint64_t v14; // r0
  uint64_t v15; // r0
  uint64_t v16; // r0
  uint64_t v17; // r0
  unsigned int v18; // r0
  uint64_t v19; // r0
  uint64_t v20; // r0
  int result; // r0
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // s16
  uint64_t v25; // r8
  uint64_t v26; // r4
  uint64_t v27; // r6
  uint64_t v28; // r0
  uint64_t v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r0
  uint64_t v32; // r0
  uint64_t v33; // r0

  v3 = *(volatile uint32_t *)(a3 + 4 * get_next_sequence(a1, a2, (volatile uint32_t *)a3));
  v4 = (uint16_t)v3 >> 4;
  if ( (v3 & 0x80000000) == 0 )
  {
    v5 = v3 >> 20;
    if ( ((v3 >> 4) & 0x800) != 0 )
    {
      v4 -= 4096;
      v6 = 1;
      v7 = -1;
    }
    else
    {
      v6 = 1;
      v7 = 1;
    }
LABEL_4:
    v8 = abs_i32(v5);
    v9 = abs_i32(v4);
    if ( v8 < v9 )
      goto LABEL_5;
    goto LABEL_11;
  }
  v5 = (v3 >> 20) - 4096;
  if ( ((v3 >> 4) & 0x800) == 0 )
  {
    v6 = -1;
    v7 = 1;
    goto LABEL_4;
  }
  v8 = abs_i32(v5);
  v9 = abs_i32(v4 - 4096);
  v6 = -1;
  v7 = -1;
  if ( v8 < v9 )
  {
LABEL_5:
    *(volatile float *)&v10 = (float)v8 / (float)v9;
    v11 = ((uint64_t (*)())float_to_double)(v10);
    v12 = ((uint64_t (*)())double_add_1)(v11, *(volatile uint64_t *)&dword_104800);
    v13 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT((float)(*(volatile float *)&v10 - 1.0) * *(volatile float *)&v10));
    v14 = ((uint64_t (*)())double_add_1)(v11, *(volatile uint64_t *)&dword_104808);
    v15 = double_compare(v14, *(volatile uint64_t *)&dword_104810);
    v16 = ((uint64_t (*)())double_add_1)(v13, v15);
    v17 = ((uint64_t (*)())double_compare_wrapper)(v12, v16);
    v18 = ((int (*)(uint64_t))double_to_uint)(v17);
    v19 = ((uint64_t (*)())float_to_double)(v18);
    v20 = ((uint64_t (*)())double_compare_wrapper)(*(volatile uint64_t *)&dword_104818, v19);
    result = ((int (*)(uint64_t))double_to_uint)(v20);
    if ( v7 != 1 )
      goto LABEL_16;
    goto LABEL_12;
  }
LABEL_11:
  *(volatile float *)&v24 = (float)v9 / (float)v8;
  v25 = ((uint64_t (*)())float_to_double)(v24);
  v26 = ((uint64_t (*)())double_add_1)(v25, *(volatile uint64_t *)&dword_104800);
  v27 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT((float)(*(volatile float *)&v24 - 1.0) * *(volatile float *)&v24));
  v28 = ((uint64_t (*)())double_add_1)(v25, *(volatile uint64_t *)&dword_104808);
  v29 = double_compare(v28, *(volatile uint64_t *)&dword_104810);
  v30 = ((uint64_t (*)())double_add_1)(v27, v29);
  v31 = ((uint64_t (*)())double_compare_wrapper)(v26, v30);
  result = ((int (*)(uint64_t))double_to_uint)(v31);
  if ( v7 != 1 )
  {
LABEL_16:
    if ( v6 == 1 )
      return result ^ 0x80000000;
    v22 = ((uint64_t (*)())float_to_double)(result);
    v23 = ((uint64_t (*)())double_compare_wrapper)(v22, *(volatile uint64_t *)&dword_104820);
    return ((int (*)(uint64_t))double_to_uint)(v23);
  }
LABEL_12:
  if ( v6 != 1 )
  {
    v32 = ((uint64_t (*)())float_to_double)(result ^ 0x80000000);
    v33 = double_compare(v32, *(volatile uint64_t *)&dword_104820);
    return ((int (*)(uint64_t))double_to_uint)(v33);
  }
  return result;
}


// alloc_buffer_by_flag @ 0x104828
int alloc_buffer_by_flag(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r3
  int v6; // r10
  int v7; // r6
  int v8; // r9
  float v9; // s14
  int v10; // r11
  int v11; // r10
  int v12; // r5
  int v13; // r4
  int v14; // r4
  int v15; // r3
  float v16; // s13
  volatile int *v17; // r11
  int v18; // r5
  int v19; // r6
  int v20; // r4
  int v21; // r0
  int v22; // r3
  float v23; // s13
  volatile float *v24; // r1
  int v25; // r0
  int v26; // r4
  float v27; // s15
  int result; // r0
  struct __attribute__((packed)) { union { int v29; // [sp+4h] [bp-A8h]
  int v30; }; // [sp+4h] [bp-A8h]
  int v31; // [sp+8h] [bp-A4h]
  int v32; // [sp+Ch] [bp-A0h]
  int v33; // [sp+10h] [bp-9Ch]
  int v34; // [sp+14h] [bp-98h]
  char _pad5[4]; int v35; // [sp+1Ch] [bp-90h]
  char _pad6[4]; int v36; // [sp+24h] [bp-88h]
  float v37; // [sp+28h] [bp-84h] BYREF
  float v38; // [sp+2Ch] [bp-80h]
  } _frame;
  if ( a1 )
    v3 = 2560;
  else
    v3 = 1280;
  if ( a1 )
    v6 = 528;
  else
    v6 = 256;
  _frame.v32 = v3;
  if ( a1 )
    v7 = 2624;
  else
    v7 = 1344;
  if ( a1 )
    v8 = 32;
  else
    v8 = 16;
  memset((volatile int *)&_frame.v37, 0, 0x80u);
  v9 = flt_1049FC;
  _frame.v29 = v6;
  v10 = 10;
  v11 = 0;
  do
  {
    v12 = v10;
    v10 += v8;
    v13 = lookup_rate_entry(v10, a2, a3);
    v14 = v13 - lookup_rate_entry(v12, a2, a3);
    if ( (float)v14 < v9 )
    {
      v9 = (float)v14;
      v11 = v12;
    }
  }
  while ( v10 < v7 );
  _frame.v35 = v11;
  v15 = v11 - _frame.v29;
  if ( v11 - _frame.v29 <= 0 )
  {
    _frame.v35 = v11 + _frame.v32;
    v15 = v11 + _frame.v32 - _frame.v29;
    _frame.v36 = 1;
  }
  else
  {
    _frame.v36 = 0;
  }
  _frame.v33 = v15 - 1;
  v16 = flt_1049FC;
  _frame.v34 = v15;
  v17 = (volatile int *)&_frame.v37;
  do
  {
    _frame.v31 = 9;
    *(volatile float *)v17++ = v16;
    _frame.v30 = _frame.v34;
    do
    {
      v18 = _frame.v30;
      v19 = 5;
      do
      {
        v20 = lookup_rate_entry(v18, a2, a3);
        v21 = lookup_rate_entry(_frame.v33 - _frame.v34 + v18, a2, a3);
        --v19;
        v18 += v8;
        *((volatile float *)v17 - 1) = *((volatile float *)v17 - 1) + (float)(v20 - v21);
      }
      while ( v19 );
      _frame.v30 += _frame.v32;
      --_frame.v31;
    }
    while ( _frame.v31 );
    ++_frame.v34;
    ++_frame.v33;
  }
  while ( v17 != (volatile int *)(&_frame.v37 + v8) );
  v22 = 0;
  v23 = flt_1049FC;
  v24 = &_frame.v37;
  v25 = 0;
LABEL_32:
  if ( (float)((float)(_frame.v37 + _frame.v38) * 0.5) > v23 )
  {
    v23 = (float)(_frame.v37 + _frame.v38) * 0.5;
    v25 = v22;
  }
  do
  {
    ++v22;
    ++v24;
    if ( !v22 )
      goto LABEL_32;
    if ( v8 - 1 == v22 )
    {
      v26 = v8;
      v27 = (float)(*v24 + *(v24 - 1)) * 0.5;
    }
    else
    {
      v26 = v22 + 1;
      v27 = (float)((float)(*(v24 - 1) + *v24) + v24[1]) / 3.0;
    }
    if ( v27 > v23 )
    {
      v23 = v27;
      v25 = v22;
    }
  }
  while ( v26 < v8 );
  result = _frame.v35 + v25 + 1;
  if ( _frame.v36 )
    result -= _frame.v32;
  return result;
}



// rf_scan_init @ 0x104a00
int rf_scan_init(int a1, int a2, int a3, int a4, int a5, int a6) {
  volatile int *v7; // r6
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r6
  int v20; // r2
  int v21; // r5
  int v22; // r3
  volatile uint32_t *v23; // r3
  float v24; // s23
  float v25; // s20
  float v26; // s19
  float v27; // s18
  float v28; // s21
  float v29; // s22
  int v30; // r8
  int v31; // r9
  int v32; // r3
  float v33; // s14
  int v34; // r7
  int v35; // r0
  float v36; // s17
  int i; // r5
  float v38; // s16
  float v39; // s15
  float v40; // s17
  float v41; // s17
  float v42; // s18
  float v43; // s17
  float v44; // s16
  volatile float *v45; // r4
  int j; // r5
  float v47; // s15
  float v48; // r0
  volatile char *v49; // r2
  float v50; // s15
  float v51; // s16
  volatile float *v52; // r5
  float v53; // s14
  int result; // r0
  int v55; // r0
  struct __attribute__((packed)) { int v56; // [sp+8h] [bp-14Ch]
  int v57; // [sp+Ch] [bp-148h]
  int v58; // [sp+10h] [bp-144h]
  char _pad3[4]; int v59; // [sp+18h] [bp-13Ch]
  int v60; // [sp+1Ch] [bp-138h]
  char _pad5[4]; int v61; // [sp+24h] [bp-130h]
  char _pad6[8]; uint32_t v63[8]; // [sp+30h] [bp-124h]
  char a1a[128]; // [sp+50h] [bp-104h] BYREF
  char v65[132]; // [sp+D0h] [bp-84h] BYREF
  } _frame;
  v7 = (volatile int *)off_104D2C;
  check_status_bits(1, aRunparescore);
  memcpy(_frame.a1a, (volatile char *)off_104D30, 0x80u);
  v11 = *v7;
  v12 = v7[1];
  v13 = v7[2];
  v14 = v7[3];
  v7 += 4;
  _frame.v63[0] = v11;
  _frame.v63[1] = v12;
  _frame.v63[2] = v13;
  _frame.v63[3] = v14;
  v15 = v7[1];
  v16 = v7[2];
  v17 = v7[3];
  _frame.v63[4] = *v7;
  _frame.v63[5] = v15;
  _frame.v63[6] = v16;
  _frame.v63[7] = v17;
  memcpy(_frame.v65, (volatile char *)v7 + 16, 0x80u);
  v18 = alloc_buffer_by_flag(0, 0, (void *)(uintptr_t)(a3));
  v19 = v18;
  _frame.v58 = a1 + 128;
  _frame.v59 = a1 + 384;
  if ( a2 == 1 )
  {
    v55 = alloc_buffer_by_flag(0, 1, (void *)(uintptr_t)(a4));
    if ( v19 < v55 )
      v19 += 1280;
    v21 = v55;
    v20 = v19 - v55;
  }
  else
  {
    v20 = v18;
    v21 = 0;
  }
  v22 = ((int)((uint64_t)((int32_t)dword_104D34 * (int64_t)(int32_t)(0x2000 - v19)) >> 32) >> 9) - ((0x2000 - v19) >> 31);
  if ( a6 )
  {
    if ( v22 >= 5 )
      v22 = 5;
  }
  else if ( v22 >= 10 )
  {
    v22 = 10;
  }
  _frame.v60 = v22;
  check_status_bits(1, " est tx start = %4d, est rx start = %4d, dly = %d, total seg = %d, \n", v21, v19, v20, v22);
  v23 = (volatile uint32_t *)(a1 + 128);
  do
  {
    *v23++ = 0;
    v23[63] = 0;
  }
  while ( v23 != (volatile uint32_t *)(a1 + 256) );
  if ( _frame.v60 > 0 )
  {
    v24 = flt_104D3C;
    v25 = flt_104D40;
    v26 = flt_104D44;
    v27 = flt_104D48;
    _frame.v57 = v19;
    v28 = flt_104D3C;
    _frame.v61 = v21 - v19;
    do
    {
      v29 = flt_104D4C;
      v30 = 0;
      v31 = 2;
      while ( 1 )
      {
        if ( a6 == 1 && !*((volatile uint8_t *)_frame.v63 + v31) )
          goto LABEL_12;
        v33 = flt_104D3C;
        _frame.v56 = *(volatile uint32_t *)&_frame.v65[4 * v31];
        v34 = _frame.v56 + _frame.v57;
        do
        {
          v35 = lookup_rate_entry(v34++, 0, (void *)(uintptr_t)(a3));
          v33 = v33 + (float)v35;
        }
        while ( v34 != _frame.v56 + _frame.v57 + 12 );
        *(volatile float *)(_frame.v58 + 4 * v31) = *(volatile float *)(_frame.v58 + 4 * v31) + v33;
        if ( v31 <= 1 )
        {
LABEL_12:
          v32 = v30 + 1;
          if ( v30 == 31 )
            break;
          goto LABEL_13;
        }
        v36 = flt_104D3C;
        for ( i = 1; ; ++i )
        {
          v38 = COERCE_FLOAT(handle_tx_descriptor(_frame.v56 + _frame.v57 - 1 + i, 0, a3));
          v39 = v38 - COERCE_FLOAT(handle_tx_descriptor(_frame.v56 + _frame.v61 + _frame.v57 - 1 + i, 1, a4));
          if ( v39 < v25 )
            v39 = v39 + v26;
          if ( v39 > v27 )
            v39 = v39 - v26;
          if ( i == 1 )
          {
            v36 = v36 + v39;
            v28 = v39;
            continue;
          }
          if ( (float)(v39 - v28) <= v27 )
            break;
          v36 = v36 + (float)(v39 - v26);
          if ( i == 12 )
            goto LABEL_34;
LABEL_24:
          ;
        }
        if ( (float)(v39 - v28) < v25 )
          v39 = v39 + v26;
        v36 = v36 + v39;
        if ( i != 12 )
          goto LABEL_24;
LABEL_34:
        v40 = v36 * v29;
        if ( v40 <= 1.0 )
        {
          if ( v40 < -1.0 )
            v40 = v40 + 2.0;
          if ( v31 == 2 )
            goto LABEL_48;
LABEL_36:
          v41 = v40 - v24;
          if ( v41 <= 1.0 )
          {
            if ( v41 < -1.0 )
              v41 = v41 + 2.0;
          }
          else
          {
            v41 = v41 - 2.0;
          }
        }
        else
        {
          v40 = v40 - 2.0;
          if ( v31 != 2 )
            goto LABEL_36;
LABEL_48:
          v24 = v40;
          v41 = flt_104D3C;
        }
        *(volatile float *)(4 * v31 + _frame.v59) = *(volatile float *)(4 * v31 + _frame.v59) + v41;
        v32 = v30 + 1;
        if ( v30 == 31 )
          break;
LABEL_13:
        if ( v32 <= 2 )
          v31 = v30;
        else
          v31 = v32;
        v30 = v32;
      }
      _frame.v57 += 1280;
    }
    while ( _frame.v57 != v19 + 1280 * _frame.v60 );
  }
  v42 = flt_104D50;
  v43 = flt_104D54;
  v44 = (float)_frame.v60;
  v45 = (volatile float *)a1;
  for ( j = 1; ; ++j )
  {
    v48 = apply_patch_block((float)(v45[32] / v44) / 12.0);
    v49 = &_frame.a1a[4 * j];
    v45[32] = v48;
    if ( (unsigned int)(j - 1) > 1 )
      break;
    v50 = (float)*((volatile int *)v49 - 1) * v42;
    v45[96] = (float)(*(volatile float *)(a1 + 392) / v44) * v43;
    *v45 = v50;
LABEL_42:
    ++v45;
  }
  v47 = (float)*((volatile int *)v49 - 1) * v42;
  v45[96] = (float)(v45[96] / v44) * v43;
  *v45 = v47;
  if ( j != 32 )
    goto LABEL_42;
  v51 = flt_104DD8;
  check_status_bits(1, aAmBeginAmBackP);
  v52 = (volatile float *)a1;
  do
  {
    v53 = *v52++;
    result = check_status_bits(
               1,
               "%10d %10d %10d\n",
               (int)(float)(v53 * v51),
               (int)(float)(v52[31] * v51),
               (int)(float)(v52[95] * v51));
  }
  while ( (volatile float *)_frame.v58 != v52 );
  return result;
}


// rf_calibrate_power @ 0x104de0
unsigned int rf_calibrate_power(volatile int *a1, int a2, unsigned int a3, int a4, volatile uint64_t *a5) {
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
  event_dispatch("temp_delta=%d\n", v6);
  v7 = COERCE_FLOAT(rf_core_reset());
  v8 = (volatile unsigned int *)a1;
  event_dispatch("tmp*100=%d\n", (int)(float)(v7 * flt_1050AC));
  v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v10 = a5[2];
  v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v11 = ((uint64_t (*)())double_add_1)(v10, v9);
  v12 = ((int (*)(uint64_t))double_to_float_1)(v11);
  v13 = (v13 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v14 = a5[1];
  v15 = v12;
  v13 = (v13 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v16 = ((uint64_t (*)())double_add_1)(v14, v13);
  v17 = ((int (*)(uint64_t))double_to_float_1)(v16);
  v18 = *a5;
  v19 = (v19 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v19 = (v19 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v20 = v17;
  v21 = ((uint64_t (*)())double_add_1)(*a5, v19);
  v22 = ((int (*)(uint64_t))double_to_float_1)(v21);
  v23 = a5[5];
  v71 = a5[4];
  v70 = a5[3];
  event_dispatch("x[0]*1000=%3d,x[1]*1000=%3d,x[2]*1000=%3d\n", v22, v20, v15);
  v24 = (v24 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v24 = (v24 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v25 = ((uint64_t (*)())double_add_1)(v23, v24);
  v26 = ((int (*)(uint64_t))double_to_float_1)(v25);
  v27 = (v27 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v28 = v26;
  v27 = (v27 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v29 = ((uint64_t (*)())double_add_1)(v71, v27);
  v30 = ((int (*)(uint64_t))double_to_float_1)(v29);
  v31 = v28;
  v32 = (v32 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_1050B4) << 32);
  v32 = (v32 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v33 = v30;
  v34 = ((uint64_t (*)())double_add_1)(v70, v32);
  v35 = ((int (*)(uint64_t))double_to_float_1)(v34);
  event_dispatch("y[0]*1000=%3d,y[1]*1000=%3d,y[2]*1000=%3d\n", v35, v33, v31);
  v36 = v8 + 32;
  do
  {
    v67 = *v8++;
    v68 = ((uint64_t (*)())float_to_double)(v67);
if ( ((int (*)())double_ge)(v18, v68) ) { v63 = v70;
    }
else if ( ((int (*)())double_eq)(v14, v68) ) { v63 = v71;
    }
else if ( ((int (*)())double_le)(v10, v68) ) { v63 = v23;
    }
    else
    {
      v37 = ((uint64_t (*)())double_compare_wrapper)(v68, v14);
      v38 = ((uint64_t (*)())double_compare_wrapper)(v68, v10);
      v39 = ((uint64_t (*)())double_compare_wrapper)(v68, v18);
      v40 = v38;
      v41 = v39;
      v42 = ((uint64_t (*)())double_add_1)(v70, v37);
      v43 = v41;
      v44 = ((uint64_t (*)())double_add_1)(v42, v40);
      v45 = ((uint64_t (*)())double_compare_wrapper)(v18, v14);
      v46 = ((uint64_t (*)())double_subtract)(v44, v45);
      v47 = ((uint64_t (*)())double_compare_wrapper)(v18, v10);
      v48 = ((uint64_t (*)())double_subtract)(v46, v47);
      v49 = ((uint64_t (*)())double_add_1)(v71, v43);
      v50 = v48;
      v51 = ((uint64_t (*)())double_add_1)(v49, v40);
      v52 = ((uint64_t (*)())double_compare_wrapper)(v14, v18);
      v53 = ((uint64_t (*)())double_subtract)(v51, v52);
      v54 = ((uint64_t (*)())double_compare_wrapper)(v14, v10);
      v55 = ((uint64_t (*)())double_subtract)(v53, v54);
      v56 = double_compare(v50, v55);
      v57 = ((uint64_t (*)())double_add_1)(v23, v43);
      v58 = ((uint64_t (*)())double_add_1)(v57, v37);
      v59 = ((uint64_t (*)())double_compare_wrapper)(v10, v18);
      v60 = ((uint64_t (*)())double_subtract)(v58, v59);
      v61 = ((uint64_t (*)())double_compare_wrapper)(v10, v14);
      v62 = ((uint64_t (*)())double_subtract)(v60, v61);
      v63 = double_compare(v56, v62);
    }
    v69 = v63;
    v64 = ((uint64_t (*)())float_to_double)(v8[63]);
    v65 = ((uint64_t (*)())double_add_1)(v64, v69);
    result = ((int (*)(uint64_t))double_to_uint)(v65);
    v8[31] = result;
  }
  while ( v8 != v36 );
  return result;
}


// mac_reset_disable @ 0x1050c0
int mac_reset_disable(int a1, int a2, int a3, int a4) {
  volatile unsigned int *v4; // r4
  volatile int *v5; // r9
  int v6; // r5
  volatile uint32_t *v7; // r11
  volatile uint32_t *v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r0
  int result; // r0

  v4 = (volatile unsigned int *)off_10516C;
  v5 = (volatile int *)off_105180;
  v6 = dword_105170;
  v7 = (void *)(uintptr_t)(off_105184);
  *(volatile uint32_t *)off_10516C &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  timer_delay(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  timer_delay(2);
  *v7 = 8;
  timer_delay(300);
  v12 = (void *)(uintptr_t)(off_105174);
  *v4 |= 0x40000000u;
  v13 = HIWORD(*v12) & 0x3FFF;
  v14 = *v4 & 0xBFFFFFFF;
  *(volatile uint16_t *)(a2 + 2 * (a3 + 16 * a4)) = v13;
  *v4 = v14;
  result = check_status_bits(1, "amp=%x pwr_amp_back[%d][%x]=%6d\n", a1, a4, a3, v13);
  if ( v13 > 0x3E80 )
    return event_dispatch(aWarningDataSat_0);
  return result;
}


// rf_update_am_back_power_diff @ 0x105188
/* luna: Computes 20 times the signed difference between current and base AM backoff values, stores it at offset 96, and reports the scaled difference. */
int rf_update_am_back_power_diff(int a1, int a2, int a3) {
  float power_difference; // s14
  int scaled_difference_for_log; // r3
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
    v15 = int_to_double(a1);
    v16 = int_to_double(a2);
    v17 = ((uint64_t (*)())double_subtract)(v15, v16);
    v18 = ((int (*)(uint64_t))double_to_uint)(v17);
    v13 = COERCE_FLOAT(free_msg(v18));
    v14 = 20.0;
    goto LABEL_6;
  }
  if ( a1 < a2 )
  {
    v9 = int_to_double(a2);
    v10 = int_to_double(a1);
    v11 = ((uint64_t (*)())double_subtract)(v9, v10);
    v12 = ((int (*)(uint64_t))double_to_uint)(v11);
    v13 = COERCE_FLOAT(free_msg(v12));
    v14 = -20.0;
LABEL_6:
    power_difference = v13 * v14;
    scaled_difference_for_log = (int)(float)(power_difference * flt_10522C);
    goto LABEL_4;
  }
  power_difference = flt_105224;
  scaled_difference_for_log = 0;
LABEL_4:
  *(volatile float *)(a3 + 96) = power_difference;
  return check_status_bits(1, "am_back_cur=%d am_back_base=%d pwr_act_diff*100=%d\n", a1, a2, scaled_difference_for_log);
}


// adc_to_temp_scale @ 0x105230
int adc_to_temp_scale(float a1, int a2, int a3) {
  float v6; // r0
  uint64_t v7; // r0
  uint64_t v8; // r0
  int v9; // r0
  uint64_t v10; // kr00_8
  uint64_t v12; // kr08_8

  v6 = COERCE_FLOAT(load_bt_config(COERCE_INT(a1 / 20.0)));
  v7 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT((float)a2 * v6));
  v8 = double_add(v7);
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
        event_dispatch("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is smaller\n", HIDWORD(v12), (uint32_t)v12);
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
      event_dispatch("ana_cur_index=%x ana_max_index=%x warning:dig_pwr is bigger\n", HIDWORD(v10), (uint32_t)v10);
      v9 = *(volatile uint8_t *)(a3 + 104);
    }
  }
  return check_status_bits(1, "pwr_diff*100=%4d base_pwr=%x dig_pwr=%x ", (int)(float)(a1 * flt_1052D8), a2, v9);
}


// rx_status_shift @ 0x1052e8
int rx_status_shift(int a1, float a2, volatile int *a3, int a4, int a5) {
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



// rx_packet_process @ 0x105388
int rx_packet_process( int a1, int a2, int a3, int a4, uint8_t a5, char a6, uint8_t a7, int a8, int a9) {
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
        v16 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT(v14));
        v17 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT(v15));
        v18 = ((uint64_t (*)())double_add_1)(v17, *(volatile uint64_t *)&dword_105668);
if ( ((int (*)())double_lt)(v16, v18) ) { check_status_bits(1, aWarningAmIsNot);
          v15 = *(v13 - 2);
        }
        *(v13 - 1) = v15;
      }
    }
    while ( (volatile float *)v12 != v13 );
  }
  if ( a1 > 0 )
  {
    v19 = int_to_double(a1);
    v20 = flt_105660;
    _frame.a4a = (int)v11;
    v21 = _frame.v122;
    v22 = (volatile float *)_frame.v123;
    v23 = 0;
    v24 = _frame.v121;
    v25 = v19;
    do
    {
      v26 = int_to_double(++v23);
      v27 = ((uint64_t (*)())double_subtract)(v26, v25);
      *(volatile uint32_t *)v24++ = ((int (*)(uint64_t))double_to_uint)(v27);
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
  rx_status_shift(a2, v28, &_frame.a3a, (int)v11, 0);
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
      check_status_bits(1, aIDpdOutDpdPmOu);
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
        rx_status_shift(a2, v40, &_frame.a3a, (int)v11, 1);
        if ( _frame.a3a )
        {
          v41 = &v11[_frame.a3a];
if ( _frame.a4b == _frame.v119 || (v42 = v11[_frame.v119 + 32], _frame.v107 = &v11[_frame.v119], v43 = v41[32] - v42, v44 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT(v43)), ((int (*)())double_lt)(v44, *(volatile uint64_t *)&dword_105658)) ) { v39 = 1.0;
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
  v45 = flt_105660;
  _frame.v105 = a1;
  v46 = flt_105664;
  v47 = a9 - 1;
  v48 = -1;
  v49 = a9 - 1;
  while ( 1 )
  {
    v56 = _frame.v122[v47];
    rx_status_shift(a2, v56, &_frame.a3a, (int)v11, 0);
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
        v53 = ((uint64_t (*)())float_to_double)(COERCE_UNSIGNED_INT(v52));
if ( !((int (*)())double_gt)(v53, *(volatile uint64_t *)&dword_105658) ) v52 = v46;
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
  check_status_bits(1, aIDpdOutDpdPmOu);
  if ( _frame.v105 > 0 )
  {
    v57 = flt_105928;
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
      check_status_bits(1, a5d5d5d, v66);
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
    v75 = (void *)(&((volatile uint32_t *)(uintptr_t)off_105930)[316 * a7 + 12 * v71]);
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
      check_status_bits(1, aDpdUseDTable, v82);
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
    return check_status_bits(
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
    v87 = (volatile int *)off_1059E0;
    check_status_bits(1, "dpd use %d table\n", v71);
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
    v87 = (volatile int *)off_10593C;
    v88 = a4 + 96;
  }
  v89 = v71 + 8 * a5;
  check_status_bits(1, "dpd use %d table\n", v89);
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
  return check_status_bits(
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


// mac_event_init @ 0x1059e8
/* luna: Initializes the analog-power calibration index list from the corresponding bits in the mask. */
int mac_event_init(unsigned int a1, volatile uint32_t *a2) {
  int result; // r0
  int bit_position; // r5
  int ana_power_index; // r2
  unsigned int v7; // r0
  int previous_count; // r3
  int selected_power_index; // r2

  a2[14] = 0;
  a2[15] = 15;
  a2[16] = 8;
  result = check_status_bits(1, "bit_mask=%x\n", a1);
  if ( a1 )
  {
    bit_position = 20;
    while ( 1 )
    {
      while ( ((1 << bit_position) & a1) >> bit_position != 1 )
      {
LABEL_3:
        if ( ++bit_position == 28 )
          return result;
      }
      a2[a2[14] + 10] = bit_position - 12;
      check_status_bits(1, "you want to cal %x index\n", bit_position - 12);
      ana_power_index = a2[a2[14] + 10];
      if ( ana_power_index <= 7 )
      {
        result = check_status_bits(((1 << bit_position) & a1) >> bit_position, " %x ana_pwr_index dont need cal\n", ana_power_index);
        if ( !a2[14] )
          a2[16] = a2[10];
        goto LABEL_3;
      }
      v7 = ((1 << bit_position) & a1) >> bit_position;
      if ( ana_power_index > 15 )
      {
        result = check_status_bits(v7, " %x ana_pwr_index dont need cal\n", ana_power_index);
        if ( !a2[14] )
          a2[15] = a2[10];
        goto LABEL_3;
      }
      result = check_status_bits(v7, "need cal %x ana_pwr_index\n", ana_power_index);
      previous_count = a2[14];
      ++bit_position;
      selected_power_index = a2[previous_count + 10];
      a2[14] = previous_count + 1;
      a2[15] = selected_power_index;
      if ( bit_position == 28 )
        return result;
    }
  }
  return check_status_bits(1, aLoftDontNeedCa);
}


// mac_conn_event_init @ 0x105abc
int mac_conn_event_init(unsigned int a1, int a2, int a3) {
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
  result = check_status_bits(1, aBitMaskX, a1);
  do
  {
    if ( a1 )
    {
      if ( ((1 << v5) & a1) >> v5 == 1 )
      {
        *(volatile uint32_t *)(a2 + 4 * (*(volatile uint32_t *)(a2 + 624) + 148)) = v5;
        check_status_bits(1, "you want to cal %x index\n", v5);
        v9 = ((1 << v5) & a1) >> v5;
        v10 = *(volatile uint32_t *)(a2 + 4 * (*(volatile uint32_t *)(a2 + 624) + 148));
        if ( v10 < v6 )
        {
          result = check_status_bits(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(volatile uint32_t *)(a2 + 624) )
            *(volatile uint32_t *)(a2 + 632) = *(volatile uint32_t *)(a2 + 592);
        }
        else if ( v10 > v7 )
        {
          result = check_status_bits(v9, " %x ana_pwr_index dont need cal\n", v10);
          if ( !*(volatile uint32_t *)(a2 + 624) )
            *(volatile uint32_t *)(a2 + 628) = *(volatile uint32_t *)(a2 + 592);
        }
        else
        {
          result = check_status_bits(v9, "need cal %x ana_pwr_index\n", v10);
          v11 = *(volatile uint32_t *)(a2 + 624);
          v12 = *(volatile uint32_t *)(a2 + 4 * (v11 + 148));
          *(volatile uint32_t *)(a2 + 624) = v11 + 1;
          *(volatile uint32_t *)(a2 + 628) = v12;
        }
      }
    }
    else
    {
      result = event_dispatch(aDpdDontNeedCal);
    }
    ++v5;
  }
  while ( v5 != 16 );
  return result;
}


// rf_phy_regs_snapshot @ 0x105ba0
volatile unsigned int * rf_phy_regs_snapshot(int a1, int a2, int a3, unsigned int a4, uint8_t a5, int a6) {
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

  v6 = (void *)(uintptr_t)(off_105E9C);
  v7 = (volatile unsigned int *)off_105E70;
  v8 = (volatile unsigned int *)off_105E74;
  v9 = (volatile unsigned int *)off_105E84;
  v10 = (volatile unsigned int *)off_105E78;
  v11 = (volatile unsigned int *)off_105E90;
  *(volatile uint32_t *)off_105E9C |= 0x400u;
  v12 = (volatile unsigned int *)off_105E7C;
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
  v83 = *(volatile uint32_t *)off_105E80;
  v81 = *(volatile uint32_t *)off_105E80;
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
    v64 = (volatile unsigned int *)off_1063F0;
    *(volatile uint32_t *)off_1063EC &= 0xFFFFFCFF;
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
  v19 = (void *)(uintptr_t)(off_105E80);
  v20 = (void *)(uintptr_t)(off_105E84);
  v21 = (volatile unsigned int *)off_105EA0;
  v22 = (volatile unsigned int *)off_105EA4;
  v23 = (volatile int *)off_105EA8;
  *(volatile uint32_t *)off_105E80 = *(volatile uint32_t *)off_105E80 & 0xFFFE00FF | 0x100;
  *v19 |= 0x20000u;
  *v19 |= 0x40000u;
  check_status_bits(1, "tia_aux_gbit_use=%d\n", (*v20 >> 21) & 7);
  v34 = (void *)(uintptr_t)(off_105E8C);
  v24 = (void *)(uintptr_t)(off_105E94);
  v25 = *(volatile uint32_t *)off_105E90;
  v26 = *(volatile uint32_t *)off_105E94;
  v27 = *(volatile uint32_t *)off_105E8C;
  v86 = *(volatile uint32_t *)off_105E8C;
  v88 = *(volatile uint32_t *)off_105E8C;
  v90 = *(volatile uint32_t *)off_105E70;
  v92 = *(volatile uint32_t *)off_105E70;
  v94 = *(volatile uint32_t *)off_105E70;
  v96 = *(volatile uint32_t *)off_105E70;
  v28 = *v21;
  v99 = *(volatile uint32_t *)off_105E98;
  v101 = *(volatile uint32_t *)off_105E78;
  v103 = *v22;
  v105 = *(volatile uint32_t *)off_105E78;
  v115 = *v23;
  v114 = *(volatile uint32_t *)off_105EAC;
  v29 = *(volatile uint32_t *)off_105E70;
  v30 = *(volatile uint32_t *)off_105E70;
  v31 = *(volatile uint32_t *)off_105E70;
  v32 = *(volatile uint32_t *)off_105EB0;
  *(volatile uint32_t *)off_105E90 |= 0x40u;
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
  v35 = (void *)(uintptr_t)(off_105E8C);
  *(volatile uint32_t *)off_105E8C &= ~0x100000u;
  *(volatile uint32_t *)v35 |= 0x200000u;
  v35 = (void *)(uintptr_t)(((uintptr_t)(v35) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v35 = (void *)(uint8_t)((uint8_t)v35 - 1);
  while ( v35 );
  v36 = (void *)(uintptr_t)(off_105E70);
  *(volatile uint32_t *)off_105E8C |= 0x100000u;
  *(volatile uint32_t *)v36 |= 0x20000u;
  *(volatile uint32_t *)v36 |= 0x10000u;
  v36 = (void *)(uintptr_t)(((uintptr_t)(v36) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v36 = (void *)(uint8_t)((uint8_t)v36 - 1);
  while ( v36 );
  v37 = (void *)(uintptr_t)(off_1061C4);
  *(volatile uint32_t *)off_1061C4 &= ~0x40000u;
  *(volatile uint32_t *)v37 |= 0x80000u;
  v37 = (void *)(uintptr_t)(((uintptr_t)(v37) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v37 = (void *)(uint8_t)((uint8_t)v37 - 1);
  while ( v37 );
  v38 = (void *)(uintptr_t)(off_1061C4);
  *(volatile uint32_t *)off_1061C4 |= 0x40000u;
  *(volatile uint32_t *)v38 |= 0x8000u;
  *(volatile uint32_t *)v38 |= 0x4000u;
  v38 = (void *)(uintptr_t)(((uintptr_t)(v38) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v38 = (void *)(uint8_t)((uint8_t)v38 - 1);
  while ( v38 );
  v39 = (volatile char *)off_1061C8;
  v40 = (void *)(uintptr_t)(off_1061CC);
  v41 = (volatile unsigned int *)off_1061D0;
  v42 = (volatile unsigned int *)off_1061D4;
  *(volatile uint32_t *)off_1061C8 |= 0x40000u;
  *v40 |= 0x3000u;
  *v41 = *v41 & 0xFFFFFFFC | 1;
  *v42 = *v42 & 0xFFE3FFFF | 0xC0000;
  *v41 |= 4u;
  *(volatile uint32_t *)&v39[-28] |= 0x800000u;
  v40 -= 465770;
  *(volatile uint32_t *)&v39[-28] |= 0x400000u;
  *v40 &= ~0x100u;
  clear_chip_ctrl_clk();
  check_status_bits(1, aStDpdDump);
  bt_control_set((int)((volatile uint32_t *)(uintptr_t)off_1061DC)[158 * a5 + 2], (int)((volatile uint32_t *)(uintptr_t)off_1061DC)[158 * a5 + 146]);
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
  v48 = (volatile unsigned int *)off_1061E0;
  v49 = (volatile unsigned int *)off_1061E8;
  v50 = (volatile unsigned int *)off_1061C8;
  check_status_bits(1, "dpd use %d table\n", v44);
  parse_table_entry(a2, v47, a6);
  v51 = (volatile unsigned int *)off_1061F0;
  check_status_bits(1, "tx_gain_map_ini=%x\n", *v48);
  *v48 = v45 | v46 | (a4 << 8) | 0x3F4080;
  mac_hw_init();
  v52 = (volatile unsigned int *)off_1061F8;
  v53 = (volatile unsigned int *)off_1061CC;
  v54 = (volatile unsigned int *)off_1061D4;
  check_status_bits(1, "tx_gain_map_ini00=%x\n", *v48);
  v55 = (void *)(uintptr_t)(off_1061FC);
  *v49 &= ~0x200u;
  *v49 |= 0x200u;
  *v49 &= ~0x200u;
  *v55 |= 0x10000000u;
  timer_delay(6500);
  dump_tone_type3();
  *v51 = *v51 & 0xFFBFFFFF | (v112 << 22);
  *v51 = *v51 & 0xFFDFFFFF | (v111 << 21);
  mac_irq_disable();
  v56 = (volatile unsigned int *)off_106200;
  v57 = (volatile unsigned int *)off_106208;
  v58 = (volatile unsigned int *)off_106204;
  v59 = (volatile unsigned int *)off_1061C4;
  v60 = (volatile unsigned int *)off_10620C;
  *v52 = *v52 & 0xF8FFFFFF | (v66 << 24);
  result = (volatile unsigned int *)off_1061D0;
  *v56 = *v56 & 0xFFFFFFBF | (v33 << 6);
  v62 = (volatile unsigned int *)off_106210;
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
  v63 = (void *)(uintptr_t)(off_1063E8);
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


// rf_tx_gain_map_write @ 0x1063f4
/* luna: Builds and writes the TX gain-map register value, applying optional per-index temperature scaling and table/index bypass encoding. */
int rf_tx_gain_map_write(int a1, int a2, int a3, int a4, int a5) {
  int scaled_gain_byte; // r4
  unsigned int tx_gain_map_word; // r4
  int gain_map_control_field; // r8
  volatile uint32_t *tx_gain_map_register; // r3

  if ( (int)*(volatile uint32_t *)(a4 + 132) <= a2 )
  {
    adc_to_temp_scale(*(volatile float *)(a4 + 4 * a2 + 148), (uint8_t)a1, a4);
    scaled_gain_byte = *(volatile uint8_t *)(a4 + 104);
  }
  else
  {
    scaled_gain_byte = (uint8_t)a1;
  }
  tx_gain_map_word = scaled_gain_byte | a1 & 0xFFFFF000 | (a2 << 8);
  if ( a3 )
  {
    if ( a2 == 7 )
    {
      gain_map_control_field = 83886080;
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
        gain_map_control_field = (15 - a2) << 24;
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
    tx_gain_map_word |= 0xC08000u;
    check_status_bits(1, "table %d index %d bypass\n", a5, a2);
    goto LABEL_9;
  }
  gain_map_control_field = a3 << 24;
LABEL_8:
  tx_gain_map_word = tx_gain_map_word & 0xFF3F7FFF | gain_map_control_field;
LABEL_9:
  tx_gain_map_register = (void *)(uintptr_t)(off_1064B0);
  *(volatile uint32_t *)off_1064B0 = tx_gain_map_word;
  return check_status_bits(1, "tx_gain_map=%x ", *tx_gain_map_register);
}


// memcpy_from_rodata @ 0x1064bc
int memcpy_from_rodata(int a1, int a2) {
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

  v4 = ((volatile uint32_t *)(uintptr_t)off_106550)[1];
  v5 = ((volatile uint32_t *)(uintptr_t)off_106550)[2];
  v6 = ((volatile uint32_t *)(uintptr_t)off_106550)[3];
  tbl[0] = ((volatile uint32_t *)(uintptr_t)off_106550)[0];
  tbl[1] = v4;
  tbl[2] = v5;
  tbl[3] = v6;
  v7 = ((volatile uint32_t *)(uintptr_t)off_106550)[5];
  v8 = ((volatile uint32_t *)(uintptr_t)off_106550)[6];
  v9 = ((volatile uint32_t *)(uintptr_t)off_106550)[7];
  tbl[4] = ((volatile uint32_t *)(uintptr_t)off_106550)[4];
  tbl[5] = v7;
  tbl[6] = v8;
  tbl[7] = v9;
  v10 = ((volatile uint32_t *)(uintptr_t)off_106550)[9];
  v11 = ((volatile uint32_t *)(uintptr_t)off_106550)[10];
  v12 = ((volatile uint32_t *)(uintptr_t)off_106550)[11];
  tbl[8] = ((volatile uint32_t *)(uintptr_t)off_106550)[8];
  tbl[9] = v10;
  tbl[10] = v11;
  tbl[11] = v12;
  v13 = (void *)(&((volatile uint32_t *)(uintptr_t)off_106550)[13]);
  tbl[12] = ((volatile uint32_t *)(uintptr_t)off_106550)[12];
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
  check_status_bits(1, "shift_idx=%d ", v25);
  if ( v25 > 25 )
    v26 = 12;
  else
    v26 = (v25 / 2) & ~((v25 / 2) >> 31);
  v27 = &tbl[v26 + 26];
  v28 = *(v27 - 26);
  v29 = (volatile unsigned int *)off_10655C;
  v30 = *(v27 - 13);
  *(volatile uint32_t *)off_106558 = (8 * v28) & 0x38 | *(volatile uint32_t *)off_106558 & 0xFFFFFFC7;
  *v29 = (4 * v30) & 0x1C | *v29 & 0xFFFFFFE3;
  return check_status_bits(1, "index=%d\n", v26);
}


// runtime_helper_div @ 0x106568
int runtime_helper_div(int a1, int a2, int a3) {
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r9
  unsigned int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5
  int v13; // r2

  v5 = int_to_double(a2);
  v6 = ((uint64_t (*)())double_subtract)(v5, *(volatile uint64_t *)&dword_1065F0);
  v7 = a1 + 4 * a3;
  v8 = ((int (*)(uint64_t))double_to_uint)(v6);
  v9 = *(volatile uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(free_msg(v8));
  v11 = *(volatile uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    check_status_bits(1, "sat> %d \n", HIDWORD(v11));
    v13 = *(volatile uint32_t *)(a1 + 172);
    if ( v13 <= v12 )
      goto LABEL_3;
LABEL_5:
    check_status_bits(1, "sma %d\n", v13);
    goto LABEL_3;
  }
  v13 = *(volatile uint32_t *)(a1 + 172);
  if ( v13 > v12 )
    goto LABEL_5;
LABEL_3:
  *(volatile uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return memcpy_from_rodata(a1, a3);
}


// rf_phy_regs_read_cal @ 0x1065f8
int rf_phy_regs_read_cal(unsigned int a1, int a2, volatile uint16_t *a3, int a4, int a5, int a6, int a7, int a8) {
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
  volatile int16_t *v35; // r9
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
  int v77; // r3
  unsigned int v78; // r3
  char v79; // r3
  int v80; // r6
  volatile int *v81; // r3
  volatile int *v82; // r12
  volatile int *v83; // r2
  int v84; // r0
  volatile int *v85; // r1
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

  v8 = (void *)(uintptr_t)(off_106900);
  v9 = (volatile unsigned int *)off_106904;
  v10 = (volatile unsigned int *)off_106908;
  v11 = (volatile unsigned int *)off_1068D8;
  v12 = (volatile unsigned int *)off_10690C;
  v13 = (volatile unsigned int *)off_1068DC;
  v14 = (volatile unsigned int *)off_106910;
  v15 = (volatile unsigned int *)off_1068E0;
  *(volatile uint32_t *)off_106900 |= 0x400u;
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
  v141 = *(volatile uint32_t *)off_1068E4;
  v139 = *(volatile uint32_t *)off_1068E4;
  *v9 |= 0x20u;
  v16 = (volatile unsigned int *)off_1068E4;
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
  v129 = *(volatile uint32_t *)off_1068E8;
  v131 = *(volatile uint32_t *)off_1068EC;
  v133 = *v12;
  v135 = *(volatile uint32_t *)off_1068F0;
  v137 = *v12;
  v147 = *(volatile uint32_t *)off_1068F4;
  v86 = *v11;
  v18 = *v11;
  v17 = *v11;
  v146 = *(volatile uint32_t *)off_1068F8;
  v19 = *(volatile uint32_t *)off_1068FC;
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
  v24 = (void *)(uintptr_t)(off_1068E0);
  *(volatile uint32_t *)off_1068E0 &= ~0x100000u;
  *(volatile uint32_t *)v24 |= 0x200000u;
  v24 = (void *)(uintptr_t)(((uintptr_t)(v24) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v24 = (void *)(uint8_t)((uint8_t)v24 - 1);
  while ( v24 );
  v25 = (void *)(uintptr_t)(off_1068D8);
  *(volatile uint32_t *)off_1068E0 |= 0x100000u;
  *(volatile uint32_t *)v25 |= 0x20000u;
  *(volatile uint32_t *)v25 |= 0x10000u;
  v25 = (void *)(uintptr_t)(((uintptr_t)(v25) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v25 = (void *)(uint8_t)((uint8_t)v25 - 1);
  while ( v25 );
  v26 = (void *)(uintptr_t)(off_106A98);
  *(volatile uint32_t *)off_106A98 &= ~0x40000u;
  *(volatile uint32_t *)v26 |= 0x80000u;
  v26 = (void *)(uintptr_t)(((uintptr_t)(v26) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v26 = (void *)(uint8_t)((uint8_t)v26 - 1);
  while ( v26 );
  v27 = (void *)(uintptr_t)(off_106A98);
  *(volatile uint32_t *)off_106A98 |= 0x40000u;
  *v27 |= 0x8000u;
  *v27 |= 0x4000u;
  v28 = (v28 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    v28 = (uint8_t)(v28 - 1);
  while ( v28 );
  v29 = (void *)(uintptr_t)(off_106A9C);
  v30 = (void *)(uintptr_t)(off_106AA0);
  v31 = (volatile unsigned int *)off_106AA4;
  v32 = (void *)(uintptr_t)(off_106AA8);
  *(volatile uint32_t *)off_106A9C |= 0x40000u;
  *v30 |= 0x3000u;
  v33 = (void *)(uintptr_t)(off_106A98);
  *v31 = *v31 & 0xFFFFFFFC | 1;
  v29[16] = v29[16] & 0xFFE3FFFF | 0xC0000;
  *v31 |= 4u;
  *v33 |= 0x800000u;
  *v33 |= 0x400000u;
  *v32 &= ~0x100u;
  clear_chip_ctrl_clk();
  mac_hw_init();
  v34 = (void *)(uintptr_t)(off_106AB0);
  *(volatile uint32_t *)off_106AAC |= 0x10000000u;
  *v34 |= 0x18000000u;
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      v161 = (a1 >> 12) & 3;
      *(volatile uint32_t *)off_107090 = a1;
      if ( v161 == 1 )
      {
        v162 = 0;
        v163 = *(volatile uint32_t *)off_1071B4;
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
          v163 = *(volatile uint32_t *)off_1071B8;
          v156 = dword_1071C0;
          v157 = dword_1071BC;
        }
        else
        {
          v163 = *(volatile uint32_t *)(uintptr_t)(off_107094);
          v156 = dword_10709C;
          v157 = dword_107098;
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
      v64 = (*(volatile uint32_t *)off_107090 >> 8) & 0xF;
      v65 = (v161 << 8) + dword_1070A0;
      v164 = v65;
      check_status_bits(1, "tx_gain_reg=%x,apc_table=%d,ampm_index=%x\n", *(volatile uint32_t *)off_107090, v161, v64);
      *(volatile uint32_t *)(a2 + 140) = *(volatile uint32_t *)(a2 + 152);
      memcpy_from_rodata(a2, 0);
      v66 = 0;
      check_status_bits(1, "tx_gain_map_reg=%x  ana_index=%x base=%d \n", *(volatile uint32_t *)off_107090, v64, 0);
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
        set_wakeup_trigger(1);
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
        set_wakeup_polarity(1);
        mac_reset_disable((uint16_t)*a3, a2, v72, 0);
        check_status_bits(1, "tone_amp[0]=%x,pwr_back[%2d]=%d ", *a3, v66, *(volatile uint16_t *)(a2 + v73));
        check_status_bits(1, "wf_pa_5g_input_2_cbit=%d  ", (*(volatile uint32_t *)off_1070B0 >> 21) & 3);
        check_status_bits(1, "wf_dtmx_tuning_cbit=%d\n", (*(volatile uint32_t *)off_1070B8 >> 15) & 0xF);
        if ( *(volatile uint16_t *)(a2 + v73) > v71 )
        {
          v71 = *(volatile uint16_t *)(a2 + v73);
          v159 = v66;
        }
        ++v66;
      }
      while ( v155 != v66 );
      if ( a8 > 2 && v161 == 1 )
      {
        if ( a8 == 6 )
          v77 = 1;
        else
          v77 = 2;
        v78 = v159 + v77;
        if ( v78 >= 3 )
          v78 = 3;
        v159 = v78;
      }
      check_status_bits(1, "cbit_val=%d\n", v159);
      set_wakeup_trigger(1);
      v79 = v87;
      v88 = (v159 >> v150) & v156;
      v80 = (v152 & v159) << v79;
      v151 = (v159 & v160) << v79;
      v81 = (volatile int *)(v164 + v162);
      v82 = (volatile int *)(v162 + 192 + v163);
      v83 = (volatile int *)(v163 + v162);
      v84 = v165 - v162;
      do
      {
        while ( 1 )
        {
          v85 = &v83[v162 / 0xFFFFFFFC];
          if ( a7 == v153 )
            break;
          *v81 &= v158;
          *(volatile int *)((volatile char *)v81 + v84) &= v157;
          *v81 |= v80;
          *(volatile int *)((volatile char *)v81 + v84) |= v88;
          *v83 &= v158;
          *(volatile int *)((volatile char *)v85 + v165) &= v157;
          *v83 |= v80;
          v83 += 3;
          *(volatile int *)((volatile char *)v85 + v165) |= v88;
          v81 += 4;
          if ( v83 == v82 )
            goto LABEL_58;
        }
        *v81 = *v81 & v154 | v151;
        *v83 = *v83 & v154 | v151;
        v83 += 3;
        v81 += 4;
      }
      while ( v83 != v82 );
LABEL_58:
      set_wakeup_polarity(1);
      check_status_bits(1, "use wf_pa_5g_input_2_cbit=%d  ", (*(volatile uint32_t *)off_1071A4 >> 21) & 3);
      check_status_bits(1, "use wf_dtmx_tuning_cbit=%d\n", (*(volatile uint32_t *)off_1071AC >> 15) & 0xF);
    }
    goto LABEL_28;
  }
  if ( v20 )
  {
    v74 = (volatile unsigned int *)off_107090;
    *(volatile uint32_t *)off_107090 = a1;
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    v75 = *v74;
    memcpy_from_rodata(a2, 0);
    v76 = (v75 >> 8) & 0xF;
    check_status_bits(1, "tx_gain_map_reg=%x  ana_index=%x base=%d ", *v74, v76, 0);
    mac_reset_disable((uint16_t)*a3, a2, v76, 0);
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
    rf_tx_gain_map_write(a1, v37, a5, a2, a6);
    *v32 &= ~0x200u;
    *v32 |= 0x200u;
    *v32 &= ~0x200u;
    memcpy_from_rodata(a2, v20);
    v39 = (uint16_t)v35[1];
    ++v35;
    mac_reset_disable(v39, a2, v37, v20);
    v40 = v20;
    v41 = *(volatile uint16_t *)(a2 + 2 * (v37 + 16 * v20++));
    runtime_helper_div(a2, v41, v40);
  }
  while ( v20 != 3 );
  v42 = *(volatile uint32_t *)(a2 + 132);
  if ( v42 <= (int)*(volatile uint32_t *)(a2 + 112) )
  {
    v43 = (void *)(uintptr_t)(off_106AA8);
    v44 = (void *)(uintptr_t)(off_106AB4);
    do
    {
      while ( 1 )
      {
        rf_tx_gain_map_write(a1, v42, a5, a2, a6);
        v45 = *(volatile uint32_t *)(a2 + 124);
        *v43 &= ~0x200u;
        *v43 |= 0x200u;
        *v43 &= ~0x200u;
        if ( v45 < v42 )
          break;
        memcpy_from_rodata(a2, 2);
        check_status_bits(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 2);
        mac_reset_disable((uint16_t)a3[2], a2, v42, 2);
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
        memcpy_from_rodata(a2, 1);
        check_status_bits(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 1);
        mac_reset_disable((uint16_t)a3[1], a2, v42, 1);
        goto LABEL_26;
      }
LABEL_23:
      memcpy_from_rodata(a2, 0);
      check_status_bits(1, "tx_gain_map_reg=%8x ana_index=%x base=%d ", *v44, v42, 0);
      mac_reset_disable((uint16_t)*a3, a2, v42++, 0);
    }
    while ( (int)*(volatile uint32_t *)(a2 + 112) >= v42 );
  }
LABEL_28:
  v46 = (volatile unsigned int *)off_106DD8;
  v47 = (volatile unsigned int *)off_106DDC;
  v48 = (volatile unsigned int *)off_106E00;
  v49 = (volatile unsigned int *)off_106E04;
  v50 = (void *)(uintptr_t)(off_106DFC);
  *(volatile uint32_t *)off_106DD8 = *(volatile uint32_t *)off_106DD8 & 0xFFBFFFFF | (v149 << 22);
  *v46 = *v46 & 0xFFDFFFFF | (v148 << 21);
  mac_irq_disable();
  v51 = (void *)(uintptr_t)(off_106DE0);
  v52 = (volatile unsigned int *)off_106DE4;
  v53 = (volatile unsigned int *)off_106E08;
  *(volatile uint32_t *)off_106DE0 = *(volatile uint32_t *)off_106DE0 & 0xF8FFFFFF | (v92 << 24);
  v54 = (volatile unsigned int *)off_106DE8;
  *v47 = *v47 & 0xFFFFFFBF | (v110 << 6);
  v55 = (volatile unsigned int *)off_106DEC;
  *v52 = *v52 & 0xFFFF8FFF | (v112 << 12);
  v56 = (volatile unsigned int *)off_106DF0;
  v57 = (volatile unsigned int *)off_106DF4;
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFF7FFFFF | (v114 << 23);
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFBFFFFF | (v116 << 22);
  v58 = (volatile unsigned int *)off_106DF8;
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFEFFFFF | (v118 << 20);
  *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) = *(volatile uint32_t *)((volatile char *)v51 + 0xFFFFFFDC) & 0xFFDFFFFF | (v120 << 21);
  *v54 = *v54 & 0xFFFBFFFF | (v144 << 18);
  v59 = (void *)(uintptr_t)(off_106E0C);
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


// rf_radio_enable @ 0x1071c4
/* luna: Powers up the RF radio and initializes its analog and synthesizer control registers. */
volatile int *rf_radio_enable() {
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

  v0 = (volatile unsigned int *)off_10739C;
  *(volatile uint32_t *)off_107398 |= 0x2000000u;
  v1 = (void *)(uintptr_t)(off_1073A0);
  v2 = (volatile unsigned int *)off_1073A4;
  *v0 &= ~0x20000u;
  timer_delay(2);
  v3 = (void *)(uintptr_t)(off_1073A8);
  v4 = dword_1073AC;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v1 |= 0x80000000;
  *v3 = v4;
  *v0 |= 0x80000u;
  *v0 &= ~0x40000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  v5 = dword_1073B0;
  *v2 &= ~0x40u;
  v3 -= 129;
  *v2 &= ~0x80u;
  *v3 |= 0x10000000u;
  *v3 = *v3 & 0xFC000FFF | 0x666000;
  *v3 = *v3 & 0xFFFFF000 | 0xC0;
  timer_delay(10);
  v6 = (volatile unsigned int *)off_1073B4;
  v7 = (void *)(uintptr_t)(off_1073B8);
  result = (volatile int *)off_1073BC;
  *(volatile uint32_t *)off_1073B4 &= ~2u;
  *v7 |= 0x1000000u;
  v9 = dword_1073C0;
  *v6 = *v6 & 0x8FFFFFFF | 0x20000000;
  *v6 &= 0xF8FFFFFF;
  *v6 = *v6 & 0xFFFFFF8F | 0x40;
  v10 = (volatile int *)off_1073C4;
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
  v11 = (volatile unsigned int *)off_1073C8;
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



// rf_radio_disable @ 0x1073cc
/* luna: Programs RF control and power registers into the radio-disabled state. */
volatile uint32_t *rf_radio_disable() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2
  volatile uint32_t *v2; // r3
  volatile unsigned int *v3; // r4
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r1
  volatile uint32_t *v7; // r2

  result = (void *)(uintptr_t)(off_1074F8);
  v1 = (volatile unsigned int *)off_1074FC;
  v2 = (void *)(uintptr_t)(off_107500);
  *(volatile uint32_t *)off_1074F8 &= ~0x80000000;
  v3 = (volatile unsigned int *)off_107504;
  v4 = (void *)(uintptr_t)(off_107508);
  v5 = (void *)(uintptr_t)(off_10750C);
  *v1 = *v1 & 0xFFFF0FFF | 0xA000;
  *v2 &= 0xCFFFFFFF;
  *v2 &= ~0x40000000u;
  *v3 = *v3 & 0xF8FFFFFF | 0x5000000;
  *v3 = *v3 & 0xFFFFFF8F | 0x50;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v1 &= ~0x20000u;
  *v1 &= ~0x10000u;
  v6 = (void *)(uintptr_t)(off_107510);
  *v4 &= ~0x10000000u;
  *v2 |= 0x400000u;
  *v2 |= 0x800000u;
  *v2 |= 0x200000u;
  *v2 |= 0x100000u;
  *v2 &= ~0x40u;
  *v5 &= ~0x1000000u;
  *v6 &= ~0x2000000u;
  *(volatile unsigned int *)((volatile char *)v3 + 0xFFFFFF5C) &= ~0x20000000u;
  v7 = (void *)(uintptr_t)(off_107514);
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



// rf_synth_set_freq @ 0x107518
volatile uint32_t *rf_synth_set_freq() {
  volatile unsigned int *v0; // r2
  volatile uint32_t *v1; // r3
  volatile uint32_t *result; // r0

  v0 = (volatile unsigned int *)off_107578;
  v1 = (void *)(uintptr_t)(off_10757C);
  result = (void *)(uintptr_t)(off_107580);
  *(volatile uint32_t *)off_107578 = *(volatile uint32_t *)off_107578 & 0xC0FFFFFF | 0x3000000;
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



// rf_mode_select @ 0x107584
int rf_mode_select(int a1, int a2) {
  volatile unsigned int *v2; // r5
  volatile unsigned int *v3; // r4
  volatile uint32_t *v5; // r2
  int v6; // r3
  int result; // r0

  v2 = (volatile unsigned int *)off_107664;
  v3 = (volatile unsigned int *)off_107668;
  *(volatile uint32_t *)off_107664 = *(volatile uint32_t *)off_107664 & 0xFFFFFF8F | 0x50;
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  rf_synth_set_freq();
  *v2 &= ~1u;
  timer_delay(140);
  v5 = (void *)(uintptr_t)(off_10766C);
  *v3 |= 0x4000000u;
  v6 = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(volatile uint32_t *)(a1 + 44) = v6;
  timer_delay(5);
  check_status_bits(1, "rd_pwr=%4d  ", *(volatile uint32_t *)(a1 + 44));
  result = check_status_bits(1, (const volatile char *)off_107674);
  *v3 &= ~0x1000000u;
  *v3 &= ~0x2000000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x800000u;
  *v3 &= ~0x200000u;
  *v3 &= ~0x100000u;
  *v2 = *v2 & 0xFFFFFF8F | 0x40;
  return result;
}


// rf_txrx_path_enable @ 0x107678
/* luna: Temporarily configures the RF path, samples the 15-bit LPF-bypass power value into the context, and returns the subsequent status-check result. */
int rf_txrx_path_enable(int a1, int a2) {
  volatile uint32_t *v2; // r5
  volatile unsigned int *v3; // r4
  volatile uint32_t *v5; // r2
  int lpf_bypass_power; // r2
  int result; // r0

  v2 = (void *)(uintptr_t)(off_10774C);
  v3 = (volatile unsigned int *)off_107750;
  *(volatile uint32_t *)off_10774C |= 4u;
  *v2 |= 8u;
  *v3 |= 0x1000000u;
  *v3 = (a2 << 25) & 0x2000000 | *v3 & 0xFDFFFFFF;
  *v3 |= 0x400000u;
  *v3 |= 0x800000u;
  *v3 |= 0x200000u;
  *v3 |= 0x100000u;
  rf_synth_set_freq();
  *v2 &= ~1u;
  timer_delay(100);
  v5 = (void *)(uintptr_t)(off_107754);
  *v3 |= 0x4000000u;
  lpf_bypass_power = *v5 & 0x7FFF;
  *v3 &= ~0x4000000u;
  *(volatile uint32_t *)(a1 + 44) = lpf_bypass_power;
  check_status_bits(1, "lpf_bypass_pwr=%4d   ", lpf_bypass_power);
  timer_delay(5);
  result = check_status_bits(1, (const volatile char *)off_10775C);
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


// timer_ticks_to_usec @ 0x107760
int timer_ticks_to_usec(int a1) {
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
  v2 = ((volatile uint32_t *)(uintptr_t)off_107810)[99];
  v3 = ((volatile uint32_t *)(uintptr_t)off_107810)[100];
  v4 = ((volatile uint32_t *)(uintptr_t)off_107810)[101];
  _frame.v30 = ((volatile uint32_t *)(uintptr_t)off_107810)[98];
  _frame.v31 = v2;
  _frame.v32 = v3;
  _frame.v33 = v4;
  v5 = ((volatile uint32_t *)(uintptr_t)off_107810)[103];
  v6 = ((volatile uint32_t *)(uintptr_t)off_107810)[104];
  v7 = ((volatile uint32_t *)(uintptr_t)off_107810)[105];
  _frame.v34 = ((volatile uint32_t *)(uintptr_t)off_107810)[102];
  _frame.v35 = v5;
  _frame.v36 = v6;
  _frame.v37 = v7;
  v8 = ((volatile uint32_t *)(uintptr_t)off_107810)[107];
  v9 = ((volatile uint32_t *)(uintptr_t)off_107810)[108];
  v10 = ((volatile uint32_t *)(uintptr_t)off_107810)[109];
  _frame.v38 = ((volatile uint32_t *)(uintptr_t)off_107810)[106];
  _frame.v39 = v8;
  _frame.v40 = v9;
  _frame.v41 = v10;
  v11 = ((volatile uint32_t *)(uintptr_t)off_107810)[111];
  v12 = ((volatile uint32_t *)(uintptr_t)off_107810)[112];
  v13 = ((volatile uint32_t *)(uintptr_t)off_107810)[113];
  _frame.v42 = ((volatile uint32_t *)(uintptr_t)off_107810)[110];
  _frame.v43 = v11;
  _frame.v44 = v12;
  _frame.v45 = v13;
  v14 = *(volatile uint32_t *)(a1 + 8);
  v15 = ((volatile uint32_t *)(uintptr_t)off_107810)[115];
  v16 = ((volatile uint32_t *)(uintptr_t)off_107810)[116];
  v17 = ((volatile uint32_t *)(uintptr_t)off_107810)[117];
  v18 = ((uint64_t)((int32_t)dword_107814 * (int64_t)(int32_t)(*(volatile int *)(a1 + 4))) >> 32) - (*(volatile int *)(a1 + 4) >> 31);
  _frame.v46 = ((volatile uint32_t *)(uintptr_t)off_107810)[114];
  _frame.v47 = v15;
  _frame.v48 = v16;
  _frame.v49 = v17;
  if ( v18 >= (int)(((uint64_t)((int32_t)dword_107814 * (int64_t)(int32_t)(v14)) >> 32) - (v14 >> 31)) )
    v18 = ((uint64_t)((int32_t)dword_107814 * (int64_t)(int32_t)(v14)) >> 32) - (v14 >> 31);
  v19 = ((volatile uint32_t *)(uintptr_t)off_107810)[119];
  v20 = ((volatile uint32_t *)(uintptr_t)off_107810)[120];
  v21 = ((volatile uint32_t *)(uintptr_t)off_107810)[121];
  v22 = v18 & ~(v18 >> 31);
  v23 = &_frame.v54 + v22;
  v24 = (volatile unsigned int *)off_107820;
  v25 = *(v23 - 24);
  v26 = *(volatile uint32_t *)off_107820;
  _frame.v50 = ((volatile uint32_t *)(uintptr_t)off_107810)[118];
  _frame.v51 = v19;
  _frame.v52 = v20;
  _frame.v53 = v21;
  v27 = (volatile unsigned int *)off_107818;
  v28 = *(v23 - 12);
  *(volatile uint32_t *)(a1 + 8) = 3 * v22;
  *v24 = (v25 << 12) & 0x7000 | v26 & 0xFFFF8FFF;
  *v27 |= 0x400u;
  *v27 = (v28 << 8) & 0x300 | *v27 & 0xFFFFFCFF;
  return check_status_bits(1, "index=%d shift_idx=%d\n", v22, 3 * v22);
}


// ke_event_post @ 0x107824
int ke_event_post(int a1, volatile uint32_t *a2, int a3) {
  int v3; // r8
  int v7; // s15
  int v8; // r2
  int v9; // r2

  v3 = *(volatile uint32_t *)(a3 + 8);
  check_status_bits(1, "gain_base=%d\n", v3);
  check_status_bits(1, "pwr_hih=%d\n", a1);
  v7 = (int)(float)(COERCE_FLOAT(free_msg(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(a1, 0xEu)))) * 10.0);
  check_status_bits(1, "pwr_db=%d\n", v7);
  v8 = a2[8];
  if ( v8 < v7 )
  {
    check_status_bits(1, "sat> %d \n", v8);
    v9 = a2[9];
    if ( v9 <= v7 )
      goto LABEL_3;
LABEL_5:
    check_status_bits(1, "sma %d\n", v9);
    goto LABEL_3;
  }
  v9 = a2[9];
  if ( v9 > v7 )
    goto LABEL_5;
LABEL_3:
  *(volatile uint32_t *)(a3 + 8) = (int)COERCE_FLOAT(branch_to_1426b0(COERCE_INT((float)(unsigned int)(a2[7] - v7 + v3))));
  return timer_ticks_to_usec(a3);
}


// rf_tx_power_set @ 0x1078dc
int rf_tx_power_set(int a1, volatile uint32_t *a2, int a3) {
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r4
  volatile int *v5; // r6
  int v6; // r8
  int v7; // r7
  uint64_t v8; // kr00_8
  int v9; // r3
  volatile int *v10; // r0
  int v11; // r0
  int result; // r0

  v3 = (void *)(uintptr_t)(off_1079B0);
  v4 = (void *)(uintptr_t)(off_1079B4);
  v5 = (volatile int *)off_1079B8;
  v6 = dword_1079C8;
  v7 = dword_1079BC;
  v8 = *(volatile uint64_t *)(a1 + 8);
  rf_synth_set_freq();
  *v3 &= ~1u;
  timer_delay(20);
  v9 = dword_1079C0;
  *v3 |= 4u;
  *v3 |= 8u;
  *v4 |= 0x100000u;
  *v4 |= 0x200000u;
  *v5 = v9 & (HIDWORD(v8) << 16) | *v5 & v6;
  *v5 = *v5 & v7 | v8 & 0xFFF;
  timer_delay(40);
  v10 = (volatile int *)off_1079C4;
  *v4 |= 0x4000000u;
  v11 = *v10;
  *v4 &= ~0x4000000u;
  *v4 &= ~0x100000u;
  *v4 &= ~0x200000u;
  result = ke_event_post(v11 & 0x7FFF, a2, a3);
  *v3 &= ~4u;
  *v3 &= ~8u;
  *v5 &= v6;
  *v5 &= v7;
  *v4 &= ~0x1000000u;
  *v4 &= ~0x2000000u;
  return result;
}



// sched_min_delta @ 0x1079cc
int sched_min_delta(volatile unsigned int *a1, int a2) {
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
  check_status_bits(1, "pwr_hih=%d\n", v3);
  v6 = (int)(float)(COERCE_FLOAT(free_msg(COERCE_UNSIGNED_INT(vcvts_n_f32_u32(v3, 0xFu)))) * 10.0);
  check_status_bits(1, "pwr_db=%d\n", v6);
  if ( v6 >= -1 )
  {
    check_status_bits(1, "sat> %d \n", -2);
  }
  else if ( v6 < -30 )
  {
    check_status_bits(1, "sma %d\n", -30);
  }
  *(volatile uint32_t *)(a2 + 8) = (int)COERCE_FLOAT(branch_to_1426b0(COERCE_INT((float)(~v6 + v5))));
  return timer_ticks_to_usec(a2);
}


// rf_rx_cfg_write @ 0x107a8c
int rf_rx_cfg_write(int a1) {
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
  v1 = (void *)(uintptr_t)(off_107C2C);
  v2 = (void *)(uintptr_t)(off_107C30);
  v3 = (volatile int *)off_107C34;
  v4 = dword_107C38;
  v5 = (void *)(uintptr_t)(off_107C44);
  timer_ticks_to_usec(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  check_status_bits(1, aAdjI);
  rf_synth_set_freq();
  *v2 &= ~1u;
  timer_delay(20);
  *v2 |= 4u;
  *v2 |= 8u;
  timer_delay(20);
  *v1 |= 0x800000u;
  *v3 = *v3 & v4 | 0xC000000;
  timer_delay(20);
  *v1 |= 0x4000000u;
  v7 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  _frame.a1a = v7;
  *v3 = *v3 & v4 | 0x4000000;
  timer_delay(20);
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
  timer_delay(20);
  *v1 |= 0x4000000u;
  _frame.v17 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v3 = *v3 & v4 | v11;
  timer_delay(20);
  *v1 |= 0x4000000u;
  _frame.v18 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  *v1 &= ~0x800000u;
  check_status_bits(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, _frame.a1a, 1024, _frame.v16, _frame.v14, _frame.v17, v12, _frame.v18);
  result = sched_min_delta(&_frame.a1a, a1);
  *v2 &= ~4u;
  *v2 &= ~8u;
  *v3 &= v4;
  *v1 &= ~0x1000000u;
  *v1 &= ~0x2000000u;
  return result;
}


// rf_tx_cfg_write @ 0x107c48
int rf_tx_cfg_write(int a1) {
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
  v1 = (void *)(uintptr_t)(off_107DEC);
  v2 = (void *)(uintptr_t)(off_107DF0);
  v3 = (volatile int *)off_107DFC;
  v4 = dword_107E00;
  v5 = (volatile int *)off_107DF4;
  v6 = (void *)(uintptr_t)(off_107DF4);
  timer_ticks_to_usec(a1);
  *v1 |= 0x1000000u;
  *v1 |= 0x2000000u;
  check_status_bits(1, aAdjQ);
  rf_synth_set_freq();
  *v2 &= ~1u;
  timer_delay(20);
  *v2 |= 4u;
  *v2 |= 8u;
  timer_delay(20);
  v8 = (volatile int *)off_107DFC;
  *v1 |= 0x400000u;
  *v3 = *v3 & v4 | 0xC00;
  timer_delay(20);
  *v1 |= 0x4000000u;
  v9 = *v5 & 0x7FFF;
  *v1 &= ~0x4000000u;
  _frame.a1a = v9;
  *v3 = *v3 & v4 | 0x400;
  timer_delay(20);
  *v1 |= 0x4000000u;
  v10 = *v5;
  v11 = dword_107E00;
  _frame.v20 = v10 & 0x7FFF;
  *v1 &= ~0x4000000u;
  v12 = _frame.a1a > _frame.v20;
  v13 = (void *)(uintptr_t)(off_107DEC);
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
  timer_delay(20);
  *v13 |= 0x4000000u;
  _frame.v21 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v8 = *v8 & v11 | v15;
  timer_delay(20);
  *v13 |= 0x4000000u;
  _frame.v22 = *v6 & 0x7FFF;
  *v13 &= ~0x4000000u;
  *v13 &= ~0x400000u;
  check_status_bits(1, " [1]=%x %d\n [2]=%x %d\n [3]=%x %d\n[4]=%x %d\n", 3072, _frame.a1a, 1024, _frame.v20, v16, _frame.v21, v15, _frame.v22);
  result = sched_min_delta(&_frame.a1a, a1);
  v18 = (void *)(uintptr_t)(off_107DF0);
  *(volatile uint32_t *)off_107DF0 &= ~4u;
  *v18 &= ~8u;
  *v8 &= v11;
  *v13 &= ~0x1000000u;
  *v13 &= ~0x2000000u;
  return result;
}


// rf_power_off @ 0x107e08
int rf_power_off() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r3
  int result; // r0
  volatile uint32_t *v3; // r2
  int v4; // r3

  v0 = (void *)(uintptr_t)(off_107E64);
  rf_synth_set_freq();
  *v0 &= ~1u;
  timer_delay(1);
  v1 = (void *)(uintptr_t)(off_107E68);
  *(volatile uint32_t *)off_107E68 &= 0xCFFFFFFF;
  *v1 |= 0x40000000u;
  result = timer_delay(1);
  v3 = (void *)(uintptr_t)(off_107E6C);
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(volatile uint32_t *)off_107E64 &= ~1u;
  return result;
}



// clear_flag_and_invoke @ 0x107e70
int clear_flag_and_invoke() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r2
  int result; // r0
  volatile uint32_t *v3; // r2
  int v4; // r3

  v0 = (void *)(uintptr_t)(off_107ED8);
  rf_synth_set_freq();
  *v0 &= ~1u;
  timer_delay(1);
  v1 = (void *)(uintptr_t)(off_107EDC);
  *(volatile uint32_t *)off_107EDC = *(volatile uint32_t *)off_107EDC & 0xCFFFFFFF | 0x10000000;
  *v1 |= 0x40000000u;
  result = timer_delay(1);
  v3 = (void *)(uintptr_t)(off_107EE0);
  *v0 |= 1u;
  *v0 |= 1u;
  while ( (*v3 & 1) == 0 )
  {
    v4 = (v4 & ~0xFFFFu) | ((uint16_t)(50) & 0xFFFFu);
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  *(volatile uint32_t *)off_107ED8 &= ~1u;
  return result;
}



// div3_compute @ 0x107ee4
volatile int * div3_compute(volatile int *a1) {
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
  v2 = ((uint64_t)((int32_t)dword_107F50 * (int64_t)(int32_t)(v1)) >> 32) - (v1 >> 31);
  v3 = a1[3] - v1 / 2 + v2 + (v1 >> 31) - ((uint64_t)((int32_t)dword_107F4C * (int64_t)(int32_t)(v1)) >> 32);
  v4 = ((uint64_t)((int32_t)dword_107F50 * (int64_t)(int32_t)(*a1)) >> 32) - (*a1 >> 31);
  v5 = (*a1 >> 31) - ((uint64_t)((int32_t)dword_107F4C * (int64_t)(int32_t)(*a1)) >> 32);
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



// periph_clock_enable @ 0x107f54
int periph_clock_enable(int a1, volatile uint32_t *a2) {
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

  v2 = (void *)(uintptr_t)(off_108068);
  v3 = (volatile unsigned int *)off_10807C;
  *(volatile uint32_t *)off_108068 |= 0x1000000u;
  v4 = 1;
  *v2 &= ~0x2000000u;
  v6 = 1000;
  check_status_bits(1, &aAdjPwr[4]);
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
      *v3 = dword_108070 & (v10 << 16) | *v3 & 0xF000FFFF;
      *v3 = v11 & 0xFFF | *v3 & 0xFFFFF000;
      timer_delay(40);
      v12 = v7[9];
      v13 = *v7;
      *v2 |= 0x4000000u;
      v14 = *(volatile uint32_t *)off_108078 & 0x7FFF;
      *v2 &= ~0x4000000u;
      check_status_bits(1, "am=%4d,ph=%4d,%d\n", v13, v12, v14);
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
  v15 = (volatile unsigned int *)off_108068;
  v16 = *(volatile uint32_t *)off_108068;
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


// list_get_at @ 0x108080
int list_get_at(int a1, volatile int *a2, int a3) {
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
    check_status_bits(1, aAdjPwr);
    rf_tx_power_set((int)a2, (void *)(uintptr_t)(a3), a1);
    v6 = *(volatile uint32_t *)(a1 + 12);
  }
  if ( *(volatile uint32_t *)(a1 + 16) - v6 >= *(volatile uint32_t *)(a3 + 24) )
  {
LABEL_8:
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31)) << 32);
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31)) & 0xFFFFFFFFu);
    v14 = *(volatile uint64_t *)(a1 + 20);
    *(volatile uint64_t *)a2 = v11;
    goto LABEL_9;
  }
  v9 = ((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)((int)v5)) >> 32) - ((int)v5 >> 31);
  v10 = ((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(SHIDWORD(v5))) >> 32) - (SHIDWORD(v5) >> 31);
  if ( (int)v5 - 1 - 3 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)((int)v5 - 1)) >> 32) - (((int)v5 - 1) >> 31)) == HIDWORD(v5) - 1 - 3 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(HIDWORD(v5) - 1)) >> 32) - ((HIDWORD(v5) - 1) >> 31)) )
  {
    if ( v9 != v10 )
    {
      v16 = *(volatile uint32_t *)(a1 + 32);
      v17 = *(volatile uint32_t *)(a1 + 20);
      v18 = ((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(2 * *(volatile uint32_t *)(a1 + 24))) >> 32)
          - ((2 * *(volatile uint32_t *)(a1 + 24)) >> 31);
      v19 = (int32_t)dword_1081DC * (int64_t)(int32_t)(v16);
      v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(2 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31))) << 32);
      v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31)) & 0xFFFFFFFFu);
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
    v23 = ((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(2 * v20)) >> 32) - ((2 * v20) >> 31);
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(2 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31))) & 0xFFFFFFFFu);
    v24 = ((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(v21)) >> 32) - (v21 >> 31);
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31)) << 32);
    *(volatile uint64_t *)a2 = v11;
    v14 = __PAIR64__(v22, v23 + v24);
  }
  else
  {
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(2 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(*a2)) >> 32) - (*a2 >> 31))) & 0xFFFFFFFFu);
    v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(2 * (((uint64_t)((int32_t)dword_1081DC * (int64_t)(int32_t)(a2[1])) >> 32) - (a2[1] >> 31))) << 32);
    v12 = *(volatile uint32_t *)(a1 + 20) + *(volatile uint32_t *)(a1 + 28);
    v13 = *(volatile uint32_t *)(a1 + 32) + *(volatile uint32_t *)(a1 + 24);
    *(volatile uint64_t *)a2 = v11;
    v14 = __PAIR64__(v13 / 2, v12 / 2);
  }
LABEL_9:
  *((volatile uint64_t *)a2 + 1) = v14;
  return check_status_bits(
           1,
           " update\n w=%4d\n l=%4d\n am=%5d\n ph=%5d\n",
           (uint32_t)v11,
           HIDWORD(v11),
           (uint32_t)v14,
           HIDWORD(v14));
}


// read_status_high @ 0x1081e8
int read_status_high() {
  volatile unsigned int *v0; // r5
  unsigned int v1; // r4
  int v2; // r6
  int result; // r0
  volatile uint32_t *v4; // r2

  v0 = (volatile unsigned int *)off_108228;
  v1 = *(volatile uint32_t *)off_108228;
  v2 = *(volatile uint32_t *)off_108224 >> 20;
  result = check_status_bits(1, "calib_loft_i=%x\n", v2);
  v4 = (void *)(uintptr_t)(off_108234);
  *v0 = dword_108230 & (((HIWORD(v1) & 0xFFF) + v2) << 16) | *v0 & 0xF000FFFF;
  *v4 |= 0x800000u;
  return result;
}


// rf_apply_loft_q_calibration @ 0x108238
/* luna: Reads the LOFT-Q calibration value, adds it to the RF register’s low 12 bits, and sets the calibration update bit. */
int rf_apply_loft_q_calibration() {
  volatile unsigned int *v0; // r5
  int loft_q_register_value; // r6
  int16_t loft_q_calibration_value; // r4
  int result; // r0
  volatile uint32_t *v4; // r1

  v0 = (volatile unsigned int *)off_108274;
  loft_q_register_value = *(volatile uint32_t *)off_108274;
  loft_q_calibration_value = (uint16_t)*(volatile uint32_t *)off_108270 >> 4;
  result = check_status_bits(1, "calib_loft_q=%x\n", loft_q_calibration_value);
  v4 = (void *)(uintptr_t)(off_10827C);
  *v0 = (loft_q_calibration_value + (uint16_t)loft_q_register_value) & 0xFFF | *v0 & 0xFFFFF000;
  *v4 |= 0x400000u;
  return result;
}


// periph_init_multi @ 0x108280
volatile uint32_t * periph_init_multi( int a1, volatile unsigned int *a2, int a3, unsigned int a4, unsigned int a5, int a6, uint16_t a7) {
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
  int v52; // r5
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
  v7 = (volatile int *)off_108540;
  v8 = (volatile unsigned int *)off_108574;
  v9 = (volatile unsigned int *)off_108544;
  v10 = (void *)(uintptr_t)(off_10857C);
  v11 = (volatile int *)off_108548;
  v12 = (volatile unsigned int *)off_108580;
  v13 = (volatile int *)off_108584;
  _frame.v161 = *(volatile uint32_t *)off_108578;
  _frame.v160 = *(volatile uint32_t *)off_108540;
  _frame.v159 = *(volatile uint32_t *)off_108540;
  _frame.v158 = *(volatile uint32_t *)off_108574;
  _frame.v157 = *(volatile uint32_t *)off_108544;
  _frame.v156 = *(volatile uint32_t *)off_108544;
  _frame.v155 = *(volatile uint32_t *)off_108544;
  _frame.v154 = *(volatile uint32_t *)off_108544;
  _frame.v153 = *(volatile uint32_t *)off_10857C;
  _frame.v152 = *(volatile uint32_t *)off_10857C;
  _frame.v151 = *(volatile uint32_t *)off_108548;
  _frame.v150 = *(volatile uint32_t *)off_108540;
  _frame.v149 = *(volatile uint32_t *)off_108540;
  *(volatile uint32_t *)off_108578 = *(volatile uint32_t *)off_108578 & 0xF8FFFFFF | 0x1000000;
  v14 = (volatile int *)off_10854C;
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
  _frame.v146 = *(volatile uint32_t *)off_108550;
  _frame.v145 = *(volatile uint32_t *)off_108550;
  _frame.v144 = *(volatile uint32_t *)off_108554;
  _frame.v143 = *(volatile uint32_t *)off_108554;
  _frame.v142 = *(volatile uint32_t *)off_108558;
  _frame.v141 = *(volatile uint32_t *)off_108558;
  _frame.v140 = *(volatile uint32_t *)off_10855C;
  _frame.v139 = *(volatile uint32_t *)off_10855C;
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
  _frame.v123 = *(volatile uint32_t *)off_108560;
  _frame.v122 = *(volatile uint32_t *)off_108564;
  _frame.v121 = *v8;
  _frame.v120 = *(volatile uint32_t *)off_108568;
  _frame.v119 = *v8;
  _frame.v118 = *(volatile uint32_t *)off_10856C;
  _frame.v117 = *(volatile uint32_t *)off_108570;
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
  v17 = (void *)(uintptr_t)(off_10854C);
  *(volatile uint32_t *)off_10854C &= ~0x100000u;
  *(volatile uint32_t *)v17 |= 0x200000u;
  v17 = (void *)(uintptr_t)(((uintptr_t)(v17) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v17 = (void *)(uint8_t)((uint8_t)v17 - 1);
  while ( v17 );
  v18 = (void *)(uintptr_t)(off_108540);
  *(volatile uint32_t *)off_10854C |= 0x100000u;
  *(volatile uint32_t *)v18 |= 0x20000u;
  *(volatile uint32_t *)v18 |= 0x10000u;
  v18 = (void *)(uintptr_t)(((uintptr_t)(v18) & ~0xFFu) | ((uint8_t)(90) & 0xFFu));
  do
    v18 = (void *)(uint8_t)((uint8_t)v18 - 1);
  while ( v18 );
  v19 = (void *)(uintptr_t)(off_108540);
  *(volatile uint32_t *)off_108540 &= ~0x40000u;
  *(volatile uint32_t *)v19 |= 0x80000u;
  v19 = (void *)(uintptr_t)(((uintptr_t)(v19) & ~0xFFu) | ((uint8_t)(60) & 0xFFu));
  do
    v19 = (void *)(uint8_t)((uint8_t)v19 - 1);
  while ( v19 );
  v20 = (void *)(uintptr_t)(off_108540);
  *(volatile uint32_t *)off_108540 |= 0x40000u;
  *v20 |= 0x8000u;
  *v20 |= 0x4000u;
  v21 = (v21 & ~0xFFu) | ((uint8_t)(90) & 0xFFu);
  do
    v21 = (uint8_t)(v21 - 1);
  while ( v21 );
  v22 = (void *)(uintptr_t)(off_108560);
  v23 = (void *)(uintptr_t)(off_108564);
  v24 = (volatile unsigned int *)off_108574;
  *(volatile uint32_t *)off_108560 |= 0x40000u;
  *v23 |= 0x3000u;
  v25 = (void *)(uintptr_t)(off_108540);
  *v24 = *v24 & 0xFFFFFFFC | 1;
  v22[16] = v22[16] & 0xFFE3FFFF | 0xC0000;
  *v24 |= 4u;
  *v25 |= 0x800000u;
  *v25 |= 0x400000u;
  clear_chip_ctrl_clk();
  check_status_bits(1, aStLoft);
  _frame.v114 = *(volatile uint32_t *)off_1088B0;
  *(volatile uint32_t *)off_1088B0 = *(volatile uint32_t *)off_1088B0 & 0xFFFFFFF | 0x10000000;
  do
  {
    mac_reset_control(v21, 0);
    v26 = (uint8_t)(v21 + 1);
    v21 = (uint8_t)(v21 + 2);
    mac_reset_control(v26, 0);
  }
  while ( v21 != 32 );
  v27 = (void *)(uintptr_t)(off_1088B4);
  *(volatile uint32_t *)off_1088B4 &= ~0x200u;
  *v27 |= 0x200u;
  *v27 &= ~0x200u;
  rf_radio_enable();
  if ( a3 == 255 )
  {
    v28 = (volatile unsigned int *)off_1088F4;
    v29 = (volatile int *)off_1088F8;
    v30 = (volatile int *)off_1088FC;
    v31 = ((volatile uint32_t *)(uintptr_t)off_1088B8)[1];
    v32 = ((volatile uint32_t *)(uintptr_t)off_1088B8)[2];
    _frame.v167[0] = ((volatile uint32_t *)(uintptr_t)off_1088B8)[0];
    _frame.v167[1] = v31;
    _frame.v167[2] = v32;
    memset(_frame.a1a, 0, sizeof(_frame.a1a));
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
      check_status_bits(1, "===========table[%d]===========\n", v33);
      mac_event_init(a2[v33], _frame.a2a);
      check_status_bits(1, "cal_all_times=%d\n", _frame.v176);
      if ( _frame.v176 <= 0 )
      {
        _frame.v107 = _frame.v167[v34];
      }
      else
      {
        _frame.v164 = v34;
        _frame.v108 = 2 * (4 * v34 + 1);
        _frame.v163 = v34 << 12;
        v35 = dword_1088C4;
        v36 = dword_108900;
        _frame.v107 = _frame.v167[v34];
        _frame.v106 = a1 + 32 * v34;
        _frame.v109 = (volatile int *)&_frame.v175;
        _frame.v112 = 0;
        _frame.v113 = _frame.v110 << 8;
        do
        {
          v37 = dword_1088C8 | _frame.v163 | (*_frame.v109 << 8);
          *(volatile uint32_t *)off_1088D0 = v37;
          v38 = *_frame.v109++;
          check_status_bits(1, "****************table[%d] cal [%x] index.********************\n", v33, v38);
          check_status_bits(1, "tx_gain_map=%x\n", v37);
          _frame.v171 = 0;
          timer_ticks_to_usec((int)&_frame.v169);
          v39 = _frame.v110;
          for ( i = _frame.v113; ; i = v39 << 8 )
          {
            *v28 = i & 0xF00 | *v28 & 0xFFFFF0FF;
            *v29 &= v35;
            *v29 &= v36;
            *v30 &= v35;
            *v30 &= v36;
            rf_rx_cfg_write((int)&_frame.v169);
            rf_power_off();
            read_status_high();
            rf_tx_cfg_write((int)&_frame.v169);
            clear_flag_and_invoke();
            rf_apply_loft_q_calibration();
            v41 = *v30 & 0xFFF;
            v42 = (*v30 & 0x8000000) != 0 ? (HIWORD(*v30) & 0xFFF) - 4096 : HIWORD(*v30) & 0xFFF;
            v43 = (*v30 & 0x800) != 0 ? v41 - 4096 : *v30 & 0xFFF;
            if ( v42 <= 1024 && v43 <= 1024 )
              break;
            _frame.v100 = v43;
            v99 = v39;
            v39 = (uint8_t)(v39 - 1);
            check_status_bits(1, "loft_bit_ctrl_ini=%d loft_i=%d loft_q=%d loft i/q too big,re cal\n", v99, v42, _frame.v100);
          }
          _frame.v110 = v39;
          _frame.v113 = i;
          v44 = HIWORD(*v30) & 0xFFF;
          *v28 = ((v39 + 1) << 8) & 0xF00 | *v28 & 0xFFFFF0FF;
          check_status_bits(1, aReCalI);
          *v30 = dword_1088DC & (v44 << 17) | *v30 & v35;
          rf_rx_cfg_write((int)&_frame.v169);
          rf_power_off();
          read_status_high();
          check_status_bits(1, aReCalQ);
          *v30 = (2 * v41) & 0xFFF | *v30 & v36;
          rf_tx_cfg_write((int)&_frame.v169);
          clear_flag_and_invoke();
          rf_apply_loft_q_calibration();
          v45 = HIWORD(*v30) & 0xFFF;
          v46 = *v30 & 0xFFF;
          v47 = v46 + (v45 << 16);
          *(volatile uint32_t *)(_frame.v106 + 8) = v47;
          v48 = v47 | (*v28 >> 8 << 28);
          *(volatile uint32_t *)(_frame.v106 + 8) = v48;
          _frame.v101 = v45 << 16;
          check_status_bits(1, "loft_res[%d]=%x\n", _frame.v108, v48);
          *v30 &= v35;
          *v30 &= v36;
          rf_txrx_path_enable((int)&_frame.v169, 1);
          _frame.a1a[0] = _frame.v173;
          sched_min_delta(_frame.a1a, (int)&_frame.v169);
          rf_mode_select((int)&_frame.v169, 1);
          v49 = _frame.v173;
          check_status_bits(1, "din_i=%4x,  din_q=%4x,  pwr_bypass=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, _frame.v173);
          *v30 = *v30 & v35 | _frame.v101;
          *v30 = v46 | *v30 & v36;
          rf_mode_select((int)&_frame.v169, 1);
          v50 = _frame.v173;
          check_status_bits(1, "din_i=%4x,  din_q=%4x,  pwr_use=%4d\n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF, _frame.v173);
          if ( v49 <= v50 )
          {
            check_status_bits(1, aLoftCalCantBeU);
            _frame.v107 = 0;
            *(volatile uint32_t *)(_frame.v106 + 8) = 0;
          }
          else
          {
            _frame.v107 &= 1u;
            check_status_bits(1, aLoftCanBeUsed);
          }
          v51 = *v28;
          _frame.v102 = *v30;
          v52 = *v30;
          v53 = *(_frame.v109 - 1);
          _frame.v167[_frame.v164] = _frame.v107;
          check_status_bits(1, "ana_index[%x] loft_ok[%d]=%d\n", v53, v33, _frame.v107);
          check_status_bits(1, "wdata=%x\n", (v52 & 0xFFF) + ((HIWORD(_frame.v102) & 0xFFF) << 16) + (v51 >> 8 << 28));
          *v30 = *v30 & v35 | ((*(volatile uint16_t *)(_frame.v106 + 10) & 0xFFF) << 16);
          *v30 = *(volatile uint32_t *)(_frame.v106 + 8) & 0xFFF | *v30 & v36;
          check_status_bits(1, "use loft_i_offset=%x  loft_q_offset=%x \n", HIWORD(*v30) & 0xFFF, *v30 & 0xFFF);
          check_status_bits(1, aLoftAmPhCal);
          v54 = (volatile int *)off_108C00;
          v55 = (volatile unsigned int *)off_108C04;
          v56 = (volatile unsigned int *)off_108C08;
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
          timer_ticks_to_usec((int)&_frame.v169);
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
              div3_compute(&_frame.v177);
              periph_clock_enable((int)&_frame.v177, (void *)(&_frame.v169));
              list_get_at((int)&_frame.v169, &_frame.v177, (int)_frame.a2a);
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
                check_status_bits(1, aEnterReLoftCal, HIDWORD(_frame.v172), (unsigned int)_frame.v172 | HIDWORD(_frame.v172));
                ++_frame.v111;
                _frame.v171 += 6;
                timer_ticks_to_usec((int)&_frame.v169);
                _frame.v177 = _frame.v104;
                _frame.v178 = _frame.v105;
                _frame.v179 = v59;
                _frame.v180 = _frame.v103;
                v61 = -(_frame.v111 <= 2);
                v58 = _frame.v111 > 2;
              }
              check_status_bits(1, "time[%d] am=%d,ph=%d\n", v61, v59, _frame.v103);
            }
            ++v58;
            check_status_bits(1, "time[%d] am=%d,ph=%d\n", v60, _frame.v179, _frame.v180);
          }
          while ( v58 != 5 );
          v73 = (*v28 >> 12) & 7;
          v74 = dword_108F78 & (_frame.v180 << 16);
          v75 = HIWORD(*v28) & 7;
          v76 = _frame.v179 & 0xFFF;
          *(volatile uint32_t *)(_frame.v106 + 12) = v74 + (v73 << 28) + (v75 << 12) + v76;
          check_status_bits(1, "phase_bit=%d,am_bit=%d\n", v73, v75);
          check_status_bits(1, "loft_res[%d]=%x\n", _frame.v108 + 1, *(volatile uint32_t *)(_frame.v106 + 12));
          *v29 &= v35;
          *v29 &= v36;
          rf_txrx_path_enable((int)&_frame.v169, 0);
          _frame.a1a[0] = _frame.v173;
          sched_min_delta(_frame.a1a, (int)&_frame.v169);
          rf_mode_select((int)&_frame.v169, 0);
          v77 = _frame.v173;
          check_status_bits(1, "am=%4x, ph=%4x, pwr_am0_ph0=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, _frame.v173);
          *v29 = v74 | *v29 & v35;
          *v29 = v76 | *v29 & v36;
          rf_mode_select((int)&_frame.v169, 0);
          v78 = _frame.v173;
          check_status_bits(1, "am=%4x, ph=%4x,  pwr_am_ph=%4d\n", *v29 & 0xFFF, HIWORD(*v29) & 0xFFF, _frame.v173);
          v79 = (volatile unsigned int *)off_108F90;
          v80 = (volatile unsigned int *)off_108F94;
          *(volatile uint32_t *)off_108F8C = *(volatile uint32_t *)off_108F8C & v36 | 0xC0;
          *v79 = *v79 & 0xFFFFFF8F | 0x40;
          *v80 = *v80 & 0xFFF0FFFF | 0x10000;
          *v80 = *v80 & 0xFFFF0FFF | 0x1000;
          *v80 = *v80 & 0xFFFFF0FF | 0x100;
          *v80 = *v80 & 0xFFFFFF0F | 0x10;
          *v80 = *v80 & 0xFFFFFFF0 | 1;
          if ( v77 <= v78 )
          {
            check_status_bits(1, aLoftAmPhCantBe);
            *(volatile uint32_t *)(_frame.v106 + 12) = 0;
          }
          else
          {
            check_status_bits(1, aLoftAmPhCanBeU);
          }
          _frame.v106 += 8;
          v81 = _frame.v176 <= ++_frame.v112;
          _frame.v108 += 2;
        }
        while ( !v81 );
      }
      *_frame.v166 = *_frame.v166 & 0xFFFDFFFF | (_frame.v107 << 17);
      check_status_bits(1, "loft_ok[%d]=%d\n", v33, _frame.v107);
      check_status_bits(1, "loft_dpd_bit_mask=%x\n", *_frame.v166);
      ++v33;
    }
    while ( v33 != 3 );
    rf_radio_disable();
    v82 = (volatile unsigned int *)off_108FA4;
    v83 = (volatile unsigned int *)off_108FA8;
    v84 = (volatile unsigned int *)off_108FD0;
    v85 = (volatile unsigned int *)off_108FD4;
    v86 = (void *)(uintptr_t)(off_108FD8);
    v87 = (void *)(uintptr_t)(off_108FDC);
    *(volatile uint32_t *)off_108FA4 = _frame.v133 & 0x8000 | *(volatile uint32_t *)off_108FA4 & 0xFFFF7FFF;
    v88 = (volatile unsigned int *)off_108FAC;
    *v82 = _frame.v132 & 0x7000 | *v82 & 0xFFFF8FFF;
    v89 = (volatile unsigned int *)off_108FB0;
    *v83 = _frame.v161 & 0x7000000 | *v83 & 0xF8FFFFFF;
    *v82 = *v82 & 0xFFFFF7FF | _frame.v151 & 0x800;
    v90 = (volatile unsigned int *)off_108FB4;
    *v88 = *v88 & 0xFFFBFFFF | _frame.v149 & 0x40000;
    v91 = (volatile unsigned int *)off_108FB8;
    *v88 = *v88 & 0xFFF7FFFF | _frame.v150 & 0x80000;
    v92 = (volatile unsigned int *)off_108FBC;
    *v89 = *v89 & 0xFF7FFFFF | _frame.v131 & 0x800000;
    *v89 = *v89 & 0xFFBFFFFF | _frame.v130 & 0x400000;
    v93 = dword_108FC0;
    *v89 = *v89 & 0xFFEFFFFF | _frame.v129 & 0x100000;
    *v89 = _frame.v128 & 0x200000 | *v89 & 0xFFDFFFFF;
    v94 = (void *)(uintptr_t)(off_108FC4);
    *v88 = _frame.v127 & 0x20000 | *v88 & 0xFFFDFFFF;
    *v88 = _frame.v126 & 0x10000 | *v88 & 0xFFFEFFFF;
    *v88 = _frame.v125 & 0x8000 | *v88 & 0xFFFF7FFF;
    v95 = (volatile unsigned int *)off_108F94;
    *v88 = _frame.v124 & 0x4000 | *v88 & 0xFFFFBFFF;
    v96 = (void *)(uintptr_t)(off_108FC8);
    *v84 = _frame.v123 & 0x40000 | *v84 & 0xFFFBFFFF;
    *(volatile uint32_t *)off_108FC8 = _frame.v122 & 0x3000 | *v96 & 0xFFFFCFFF;
    v97 = (void *)(uintptr_t)(off_108FCC);
    *v90 = _frame.v121 & 3 | *v90 & 0xFFFFFFFC;
    *(volatile uint32_t *)off_108FCC = _frame.v120 & 0x1C0000 | *v97 & 0xFFE3FFFF;
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
    result = (void *)(uintptr_t)(off_1092AC);
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
    v98 = (volatile unsigned int *)off_1092B0;
    *v95 = *v95 & 0xFFFFFFF0 | _frame.v134 & 0xF;
    *v98 = *v98 & 0x7FFFFFFF | _frame.v118 & 0x80000000;
    *(volatile uint32_t *)off_1092B4 = _frame.v117;
    *(v84 - 19976) = *(volatile unsigned int *)((volatile char *)v84 + 0xFFFFFFE0 - 79872) & 0xFFFFFFF | _frame.v114 & 0xF0000000;
  }
  else
  {
    v62 = dword_108C10;
    v63 = ((int)((uint64_t)((int32_t)dword_108C0C * (int64_t)(int32_t)(a3)) >> 32) >> 5) - (a3 >> 31);
    v64 = a3 - 100 * v63;
    enable_pa();
    *(volatile uint32_t *)off_108C14 &= ~1u;
    _frame.v170 = 30;
    _frame.v171 = v63;
    event_dispatch("pwr=%d\n", v63);
    v65 = HIWORD(v15) & 0xFFF;
    v66 = HIWORD(a5) & 0xFFF;
    v67 = v15 & 0xFFF;
    event_dispatch("index=%d\n", v64);
    event_dispatch("din_i=%x din_q=%x ph=%x am=%x\n", v65, v67, v66, a5 & 0xFFF);
    *(volatile uint32_t *)off_108C24 = a6;
    event_dispatch("dump_tx_gain_map=%x\n", a6);
    *(volatile uint32_t *)off_108C00 = *(volatile uint32_t *)off_108C00 & v62 | a7 & 0xFFF;
    event_dispatch("dump_amp_tone=%x\n", a7);
    pmu_write_control(v64);
    v68 = (volatile unsigned int *)off_108C08;
    v69 = (volatile int *)off_108C30;
    v70 = dword_108C34;
    v71 = (volatile unsigned int *)off_108C38;
    *(volatile uint32_t *)off_108C08 = *(volatile uint32_t *)off_108C08 & 0xFFF0FFFF | 0x10000;
    *v68 = *v68 & 0xFFFF0FFF | 0x1000;
    *v68 = *v68 & 0xFFFFF0FF | 0x100;
    *v68 = *v68 & 0xFFFFFF0F | 0x20;
    *v68 = *v68 & 0xFFFFFFF0 | 3;
    *v69 = *v69 & v70 | (v65 << 16);
    *v69 = v67 | *v69 & v62;
    *v71 = *v71 & v70 | (v66 << 16);
    *v71 = a5 & 0xFFF | *v71 & v62;
    rf_synth_set_freq();
    timer_ticks_to_usec((int)&_frame.v169);
    rf_mode_select((int)&_frame.v169, 0);
    check_status_bits(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, _frame.v173);
    rf_mode_select((int)&_frame.v169, 0);
    check_status_bits(1, "am=%4x, ph=%4x,  dump_pwr=%4d\n", *v71 & 0xFFF, HIWORD(*v71) & 0xFFF, _frame.v173);
    timer_delay(500);
    return (volatile uint32_t *)mac_phy_config();
  }
  return result;
}


