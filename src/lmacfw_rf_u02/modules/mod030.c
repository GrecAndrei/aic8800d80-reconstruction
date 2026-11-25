// tx_packet_pointer @ 0x126dd8
int tx_packet_pointer(int a1) {
  volatile uint8_t *v1; // r3
  int v2; // r2
  int v3; // r0
  char v4; // lr
  char v5; // r9
  char v6; // r8
  char v7; // r5
  volatile char *v8; // r7
  volatile char *v9; // r6
  char v10; // r4
  char v11; // r12
  char v12; // r1

  v1 = (void *)(uintptr_t)(off_126E44);
  v2 = *((volatile char *)off_126E44 + 2) + 7;
  v3 = a1 + 7;
  v4 = *((volatile uint8_t *)off_126E4C + v2);
  v5 = *((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126E48)[4] + v2);
  v6 = *((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126E48)[8] + v2);
  v7 = *((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126E48)[4] + v3);
  v8 = (volatile char *)off_126E4C + v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)off_126E48 + v3) - *((volatile uint8_t *)off_126E48 + v2)) & 0xFFu);
  v9 = (volatile char *)off_126E4C + v3;
  v10 = *((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126E48)[8] + v3);
  v3 = (v3 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)off_126E4C + v3)) & 0xFFu);
  v11 = v8[16];
  v12 = v9[16];
  v8 = (void *)(uintptr_t)(((uintptr_t)(v8) & ~0xFFu) | ((uint8_t)(v8[32]) & 0xFFu));
  *((volatile uint8_t *)off_126E44 + 8) = v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(v9[32] - (uint8_t)v8) & 0xFFu);
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return event_counter();
}


// jump_10de98 @ 0x126e50
int jump_10de98() {
  return sdio_core_reset_alt();
}



// mac_packet_dispatch @ 0x126e54
int mac_packet_dispatch() {
  if ( *((volatile uint8_t *)off_126E7C + 1) )
    return *((volatile char *)off_126E7C + 3);
  sdio_core_reset_alt();
  return (int)COERCE_FLOAT(wait_sdio_core_ready());
}


// rf_param_build @ 0x126e80
int rf_param_build() {
  volatile uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int a3; // [sp+14h] [bp-4h]

  v0 = (volatile uint8_t *)off_126EF8;
  dispatch_event_handler_1(
    "temp_comp: init=%d, en=%d, lvl_cal=%d, t_last=%d C\n",
    *(volatile char *)off_126EF8,
    *((volatile char *)off_126EF8 + 1),
    *((volatile char *)off_126EF8 + 2),
    *((volatile char *)off_126EF8 + 3));
  dispatch_event_handler_1("xtal_cap: cal=0x%x, tgt=0x%x, cur=0x%x\n", v0[4], v0[5], v0[6]);
  dispatch_event_handler_1(
    "ofst2x: 2G4=%d,%d,%d; 5G=%d,%d,%d\n",
    (char)v0[8],
    (char)v0[9],
    (char)v0[10],
    (char)v0[11],
    (char)v0[12],
    (char)v0[13]);
  v1 = *(volatile uint8_t *)(off_126F08 + 0x16B);
  a3 = *(volatile uint32_t *)(off_126F08 + 0x16C);
  v2 = ke_task_retrieve(1070, 1);
  return dispatch_event_handler_1("settings: en=%d, tmr=%d, act=%d\n", v1, a3, v2);
}


// freq_offset_to_channel @ 0x126f10
int freq_offset_to_channel(int a1) {
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_126F8C * (uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((uint64_t)((int32_t)dword_126F80 * (int64_t)(int32_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((volatile uint8_t *)off_126F84 + 4)
     + (char)(*((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126F88)[1] + v1 + 3) - *((volatile uint8_t *)&((volatile uint32_t *)(uintptr_t)off_126F88)[1] + *((volatile char *)off_126F84 + 2) + 3));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  *((volatile uint8_t *)off_126F84 + 5) = v2;
  tx_packet_pointer(v1);
  result = test_event_flag(9u, 4u);
  if ( result )
    return rf_param_build();
  return result;
}


// rf_set_frequency_2 @ 0x126f90
int rf_set_frequency_2(int a1) {
  int v1; // s15
  int v2; // r3

  v1 = (int)COERCE_FLOAT(wait_sdio_core_ready());
  dispatch_event_handler_1("\x9D\x89t=%d C\n", v1);
  v2 = (char)v1 - *((volatile char *)off_126FD4 + 3);
  if ( v2 < 0 )
    v2 = *((volatile char *)off_126FD4 + 3) - (char)v1;
  if ( v2 > 4 )
  {
    *((volatile uint8_t *)off_126FD4 + 3) = v1;
    freq_offset_to_channel((char)v1);
  }
  return rx_index_update();
}


// rf_cmd_check @ 0x126fd8
int rf_cmd_check(char a1) {
  volatile uint8_t *v1; // r4
  int v3; // r0
  int v4; // r2
  signed int v5; // r3

  v1 = (void *)(uintptr_t)(off_127040);
  if ( *((volatile uint8_t *)off_127040 + 1) )
  {
    v3 = *((volatile char *)off_127040 + 3);
    v4 = v3;
  }
  else
  {
    sdio_core_reset_alt();
    v4 = (int)COERCE_FLOAT(wait_sdio_core_ready());
    v3 = (char)v4;
  }
  v1[4] = a1;
  v1[6] = a1;
  if ( v4 > 29 )
    v5 = (unsigned int)(((unsigned int)dword_127048 * (uint64_t)(unsigned int)(v4 - 30)) >> 32) >> 3;
  else
    v5 = ((int)((uint64_t)((int32_t)dword_127044 * (int64_t)(int32_t)(v4 - 40)) >> 32) >> 2) - ((v4 - 40) >> 31);
  if ( v5 >= 8 )
    v5 = 8;
  if ( v5 < -7 )
    v5 = (v5 & ~0xFFu) | ((uint8_t)(-7) & 0xFFu);
  v1[2] = v5;
  return freq_offset_to_channel(v3);
}


// rf_read_trim @ 0x12704c
void rf_read_trim() {
  volatile uint8_t *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  struct __attribute__((packed)) { uint8_t a1; // [sp+3h] [bp-Dh] BYREF
  int v8; // [sp+4h] [bp-Ch] BYREF
  int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_1270FC);
  v1 = *(volatile char *)off_1270FC;
  if ( *(volatile uint8_t *)off_1270FC )
    return;
  _frame.a1 = *(volatile uint8_t *)off_1270FC;
  v2 = *(volatile uint32_t *)off_127100;
  _frame.v8 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    mmio_read_status(&_frame.a1);
    rf_reg10_status(&_frame.v8);
    goto LABEL_4;
  }
  _frame.v9 = 0;
  _frame.v10 = 0;
  if ( !bus_read32((int)&_frame.v9) )
    _frame.a1 = _frame.v9;
  if ( mmio_read_64((int)&_frame.v10) )
  {
LABEL_4:
    v3 = _frame.a1;
    if ( _frame.a1 )
      goto LABEL_5;
    goto LABEL_19;
  }
  _frame.v8 = (char)_frame.v10;
  v3 = _frame.a1;
  if ( _frame.a1 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      v3 = (v3 & ~0xFFu) | ((uint8_t)(31) & 0xFFu);
      _frame.a1 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  v3 = (v3 & ~0xFFu) | ((uint8_t)(15) & 0xFFu);
LABEL_7:
  v0[4] = v3;
  v4 = get_xtal_ftune();
  v5 = _frame.v8;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      _frame.v8 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      _frame.v8 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v0[2] = v6;
    dispatch_event_handler_1("\x9D\x89temp_lvl_calibed=%d\n", v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}


// rf_enable_2 @ 0x127108
int rf_enable_2() {
  volatile uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r2

  v0 = (void *)(uintptr_t)(off_127160);
  *((volatile uint8_t *)off_127160 + 1) = 1;
  result = ke_task_retrieve(1070, 1);
  if ( !result )
  {
    sdio_core_reset_alt();
    v2 = get_xtal_ftune();
    v0[6] = v2;
    rf_set_frequency_2(v2);
    v3 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v3 )
    {
      set_xtal_ftune(v3);
      v4 = (uint8_t)v0[5];
      v0[6] = v4;
      dispatch_event_handler_1("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v4, v4);
    }
    return ke_event_loop(1070, 1, 1000 * *(volatile uint32_t *)(off_127164 + 0x16C));
  }
  return result;
}


// rf_disable_2 @ 0x12716c
int rf_disable_2() {
  int result; // r0

  *((volatile uint8_t *)off_127190 + 1) = 0;
  result = ke_task_retrieve(1070, 1);
  if ( result )
    return ke_int_lock(1070, 1);
  return result;
}



// parse_data_field @ 0x127194
uint64_t parse_data_field(uint64_t a1) {
  int v1; // r7
  int v2; // r4
  int v3; // r5
  uint64_t v4; // r2
  int v5; // r3
  unsigned int v6; // r7
  int v7; // r3
  int v8; // cf
  int v9; // r3

  v1 = (HIDWORD(a1) >> 20) & 0x7FF;
  v2 = v1 - 1023;
  v3 = HIDWORD(a1);
  v4 = a1;
  if ( v1 - 1023 > 19 )
  {
    if ( v2 <= 51 )
    {
      v6 = 0xFFFFFFFF >> (((HIDWORD(a1) >> 20) - 19) & 0xFF);
      if ( ((unsigned int)a1 & v6) != 0 )
      {
        v7 = 1 << (51 - v2);
        v8 = __CFADD__((uint32_t)a1, v7);
        v9 = a1 + v7;
        if ( v8 )
          v3 = HIDWORD(a1) + 1;
        v5 = v9 & ~v6;
        return __PAIR64__(v3, v5);
      }
    }
    else if ( v1 == 2047 )
    {
      return double_add(a1, a1);
    }
  }
  else
  {
    if ( v2 < 0 )
    {
      v3 = HIDWORD(a1) & 0x80000000;
      if ( v1 == 1022 )
        v3 |= 0x3FF00000u;
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
    if ( HIDWORD(a1) & (dword_127224 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF)) | (unsigned int)a1 )
    {
      v3 = (HIDWORD(a1) + (0x80000 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF))) & ~(dword_127224 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF));
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
  }
  return v4;
}


// float_to_i24 @ 0x127228
unsigned int float_to_i24(unsigned int a1) {
  int v1; // r5
  unsigned int v3; // r7
  unsigned int v4; // r6
  int v5; // r7
  unsigned int v6; // r0
  unsigned int v8; // r0

  v1 = (uint8_t)(a1 >> 23) - 127;
  v3 = a1 & 0x7FFFFFFF;
  if ( v1 > 22 )
  {
    if ( v3 >= 0x7F800000 )
      return ((int (*)())aeabi_ddiv)(a1, a1);
    return a1;
  }
  v4 = a1;
  if ( v1 < 0 )
  {
    v8 = ((int (*)())aeabi_ddiv)(a1, dword_1272A0);
    if ( util_cmp_ge(v8, 0) )
    {
      if ( (a1 & 0x80000000) == 0 )
        return 0;
      if ( v3 )
        return dword_1272A4;
    }
    return a1;
  }
  v5 = dword_12729C >> v1;
  if ( (a1 & (dword_12729C >> v1)) == 0 )
    return a1;
  v6 = ((int (*)())aeabi_ddiv)(a1, dword_1272A0);
  if ( !util_cmp_ge(v6, 0) )
    return a1;
  if ( (a1 & 0x80000000) != 0 )
    v4 += 0x800000 >> v1;
  return v4 & ~v5;
}


// double_subtract @ 0x1272b0
/* libmatch: 634 bytes identical to __aeabi_dsub (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_add @ 0x1272b4
/* libmatch: 630 bytes identical to __aeabi_dadd (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_to_float @ 0x12752c
/* libmatch: 30 bytes identical to __aeabi_ui2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// aeabi_i2d @ 0x12754c
/* libmatch: 34 bytes identical to __aeabi_i2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// aeabi_d2f @ 0x127570
/* libmatch: 66 bytes identical to __aeabi_f2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// aeabi_d2uiz @ 0x1275b4
/* libmatch: 106 bytes identical to __aeabi_ul2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// aeabi_dadd @ 0x127620
/* libmatch: 596 bytes identical to __aeabi_dmul (libgcc.a:_arm_muldf3.o); the library routine is linked */


// aeabi_dadd_internal @ 0x1277fc
/* libmatch: interior fragment of __aeabi_dmul @ 0x127620 (libgcc.a:_arm_muldf3.o); dropped */


// aeabi_dsub @ 0x127874
/* libmatch: 464 bytes identical to __aeabi_ddiv (libgcc.a:_arm_muldivdf3.o); the library routine is linked */


// double_unordered @ 0x1279e2
/* libmatch: interior fragment of __aeabi_ddiv @ 0x127874 (libgcc.a:_arm_muldivdf3.o); dropped */


// double_compare @ 0x127a54
/* libmatch: 122 bytes identical to __cmpdf2 (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_reverse_compare @ 0x127ad0
/* libmatch: 32 bytes identical to __aeabi_cdrcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_compare_flags @ 0x127ae0
/* libmatch: 16 bytes identical to __aeabi_cdcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_eq @ 0x127af0
/* libmatch: 18 bytes identical to __aeabi_dcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_lt @ 0x127b04
/* libmatch: 18 bytes identical to __aeabi_dcmplt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_le @ 0x127b18
/* libmatch: 18 bytes identical to __aeabi_dcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_ge @ 0x127b2c
/* libmatch: 18 bytes identical to __aeabi_dcmpge (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_gt @ 0x127b40
/* libmatch: 18 bytes identical to __aeabi_dcmpgt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_to_float_1 @ 0x127b54
/* libmatch: 78 bytes identical to __aeabi_d2iz (libgcc.a:_arm_fixdfsi.o); the library routine is linked */


// aeabi_d2iz @ 0x127ba4
/* libmatch: 64 bytes identical to __aeabi_d2uiz (libgcc.a:_arm_fixunsdfsi.o); the library routine is linked */


// aeabi_dmul @ 0x127be4
/* libmatch: 158 bytes identical to __aeabi_d2f (libgcc.a:_arm_truncdfsf2.o); the library routine is linked */


// aeabi_ddiv @ 0x127c90
/* libmatch: 352 bytes identical to __aeabi_fadd (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// aeabi_dcmp @ 0x127e14
/* libmatch: 140 bytes identical to __aeabi_ul2f (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// util_cmp_core @ 0x127eb0
/* libmatch: 94 bytes identical to __cmpsf2 (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// util_cmp_rev @ 0x127f10
/* libmatch: 24 bytes identical to __aeabi_cfrcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_equal @ 0x127f28
/* libmatch: 18 bytes identical to __aeabi_fcmpeq (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_lower_unsigned @ 0x127f3c
/* libmatch: 18 bytes identical to __aeabi_fcmplt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_lower_or_equal_unsigned @ 0x127f50
/* libmatch: 18 bytes identical to __aeabi_fcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// util_cmp_gt @ 0x127f64
/* libmatch: 18 bytes identical to __aeabi_fcmpge (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// util_cmp_ge @ 0x127f78
/* libmatch: 18 bytes identical to __aeabi_fcmpgt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// util_is_zero @ 0x127f8c
uint64_t util_is_zero(uint64_t a1, uint64_t a2) {
  uint64_t v2; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return util_memcpy(a1, a2, &v2);
  if ( a1 )
    return -1;
  return a1;
}


// util_memcpy @ 0x127fbc
uint64_t util_memcpy(uint64_t a1, uint64_t a2, volatile uint64_t *a4) {
  uint64_t v3; // r4
  unsigned int v4; // lr
  unsigned int v5; // r7
  unsigned int v6; // r2
  unsigned int v7; // r8
  int v8; // r12
  unsigned int v9; // r3
  unsigned int v10; // r0
  int v11; // cf
  unsigned int v12; // r3
  int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r1
  unsigned int v16; // r4
  unsigned int v17; // r3
  unsigned int v18; // lr
  int v19; // r8
  int v20; // r12
  unsigned int v21; // r3
  int v22; // r0
  unsigned int v23; // r8
  unsigned int v24; // r3
  uint64_t v25; // kr00_8
  unsigned int v26; // r12
  unsigned int v27; // r3
  unsigned int v28; // r3
  int v29; // r5
  unsigned int v30; // r5
  unsigned int v31; // r3
  unsigned int v32; // r7
  unsigned int v33; // lr
  unsigned int v34; // r5
  unsigned int v35; // r4
  int v36; // r9
  unsigned int v37; // r5
  unsigned int v38; // r10
  unsigned int v39; // r2
  unsigned int v40; // r3
  unsigned int v41; // r5
  int v42; // r0
  unsigned int v43; // r4
  unsigned int v44; // r8
  unsigned int v45; // r4
  uint64_t v46; // r8
  uint64_t v47; // kr08_8

  v3 = a1;
  v4 = HIDWORD(a1);
  if ( HIDWORD(a2) )
  {
    if ( HIDWORD(a2) <= HIDWORD(a1) )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(__clz(HIDWORD(a2))) << 32);
      if ( HIDWORD(a1) )
      {
        v32 = ((unsigned int)a2 >> (32 - BYTE4(a1))) | (HIDWORD(a2) << SBYTE4(a1));
        a2 = (a2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIDWORD(v3) << SBYTE4(a1)) << 32);
        v33 = HIWORD(v32);
        v34 = HIDWORD(v3) >> (32 - BYTE4(a1));
        v35 = ((unsigned int)a1 >> (32 - BYTE4(a1))) | HIDWORD(a2);
        v36 = v34 / HIWORD(v32);
        v37 = HIWORD(v35) | ((v34 % HIWORD(v32)) << 16);
        v38 = v36 * (uint16_t)v32;
        v39 = (uint32_t)a2 << SBYTE4(a1);
        v40 = (uint32_t)a1 << SBYTE4(a1);
        if ( v38 > v37 )
        {
          v11 = __CFADD__(v32, v37);
          v37 += v32;
          if ( v11 || v38 <= v37 )
          {
            --v36;
          }
          else
          {
            v36 -= 2;
            v37 += v32;
          }
        }
        v41 = v37 - v38;
        v42 = v41 / v33;
        v43 = (uint16_t)v35 | ((v41 % v33) << 16);
        v44 = v41 / v33 * (uint16_t)v32;
        if ( v44 > v43 )
        {
          v11 = __CFADD__(v32, v43);
          v43 += v32;
          if ( v11 || v44 <= v43 )
          {
            --v42;
          }
          else
          {
            v42 -= 2;
            v43 += v32;
} } a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v42 | (v36 << 16)) & 0xFFFFFFFFu);
        v45 = v43 - v44;
        v46 = (unsigned int)a1 * (uint64_t)v39;
        v47 = v46;
if ( __PAIR64__(v45, v40) < v46 ) { a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(a1 - 1) & 0xFFFFFFFFu);
          v47 = v46 - __PAIR64__(v32, v39);
        }
        if ( a4 )
        {
          *(volatile uint32_t *)a4 = ((__PAIR64__(v45, v40) - v47) >> 32 << (32 - BYTE4(a1)))
                        | ((v40 - (unsigned int)v47) >> SBYTE4(a1));
          *((volatile uint32_t *)a4 + 1) = (unsigned int)((__PAIR64__(v45, v40) - v47) >> 32) >> SBYTE4(a1);
        }
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
      }
      else
      {
if ( HIDWORD(a2) >= HIDWORD(v3) && (unsigned int)a2 > (unsigned int)a1 ) { a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
        }
        else
        {
          v25 = __PAIR64__(HIDWORD(v3), a1) - a2;
          v24 = (__PAIR64__(HIDWORD(v3), a1) - a2) >> 32;
          v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v25) & 0xFFFFFFFFu);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(1) & 0xFFFFFFFFu);
          v4 = v24;
        }
        if ( a4 )
        {
          *(volatile uint32_t *)a4 = v3;
          *((volatile uint32_t *)a4 + 1) = v4;
        }
      }
    }
else { a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
      if ( a4 )
      {
        *(volatile uint32_t *)a4 = a1;
        *((volatile uint32_t *)a4 + 1) = HIDWORD(v3);
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    }
  }
  else
  {
    v5 = a2;
    if ( (unsigned int)a2 <= HIDWORD(a1) )
    {
      if ( !(uint32_t)a2 )
        __und(0xFFu);
      v6 = __clz(a2);
      if ( v6 )
      {
        v5 <<= v6;
        v18 = HIWORD(v5);
        v26 = HIDWORD(a1) >> (32 - v6);
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(((unsigned int)a1 >> (32 - v6)) | (HIDWORD(a1) << v6)) & 0xFFFFFFFFu);
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v26 / HIWORD(v5)) << 32);
        v19 = (uint16_t)v5;
        v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(WORD1(a1) | ((v26 % HIWORD(v5)) << 16)) << 32);
        v27 = HIDWORD(a1) * (uint16_t)v5;
        v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)((uint32_t)v3 << v6) & 0xFFFFFFFFu);
        if ( v27 > HIDWORD(v3) )
        {
          v11 = __CFADD__(v5, HIDWORD(v3));
          v3 = (v3 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v3 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
          if ( v11 || v27 <= HIDWORD(v3) )
          {
            a1 = (a1 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(a1 >> 32) & 0xFFFFFFFFu) - (uint32_t)(1))) << 32;;
          }
          else
          {
            a1 = (a1 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(a1 >> 32) & 0xFFFFFFFFu) - (uint32_t)(2))) << 32;;
            v3 = (v3 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v3 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
          }
        }
        v28 = HIDWORD(v3) - v27;
        v29 = (uint16_t)a1;
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v28 / v18) & 0xFFFFFFFFu);
        v30 = v29 | ((v28 % v18) << 16);
        v31 = v28 / v18 * (uint16_t)v5;
        if ( v31 > v30 )
        {
          v11 = __CFADD__(v5, v30);
          v30 += v5;
if ( v11 || v31 <= v30 ) { a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(a1 - 1) & 0xFFFFFFFFu);
          }
else { a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(a1 - 2) & 0xFFFFFFFFu);
            v30 += v5;
          }
        }
        v17 = v30 - v31;
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a1 | (HIDWORD(a1) << 16)) << 32);
      }
      else
      {
        v17 = HIDWORD(a1) - v5;
        v18 = HIWORD(v5);
        v19 = (uint16_t)v5;
        a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1) << 32);
      }
      v20 = v17 / v18;
      v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(WORD1(v3) | ((v17 % v18) << 16)) << 32);
      v21 = v19 * (v17 / v18);
      if ( v21 > HIDWORD(v3) )
      {
        v11 = __CFADD__(v5, HIDWORD(v3));
        v3 = (v3 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v3 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
        if ( v11 || v21 <= HIDWORD(v3) )
        {
          --v20;
        }
        else
        {
          v20 -= 2;
          v3 = (v3 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v3 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
        }
      }
      v3 = (v3 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v3 >> 32) & 0xFFFFFFFFu) - (uint32_t)(v21))) << 32;;
      v22 = HIDWORD(v3) / v18;
      v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)((uint16_t)v3 | ((HIDWORD(v3) % v18) << 16)) & 0xFFFFFFFFu);
      v23 = v19 * (HIDWORD(v3) / v18);
      if ( v23 > (unsigned int)v3 )
      {
        v11 = __CFADD__(v5, (uint32_t)v3);
        v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v5 + v3) & 0xFFFFFFFFu);
        if ( v11 || v23 <= (unsigned int)v3 )
        {
          --v22;
        }
        else
        {
          v22 -= 2;
          v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v3 + v5) & 0xFFFFFFFFu);
        }
      }
      v16 = v3 - v23;
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v22 | (v20 << 16)) & 0xFFFFFFFFu);
    }
    else
    {
      v6 = __clz(a2);
      if ( v6 )
      {
        v5 <<= v6;
        v4 = ((unsigned int)a1 >> (32 - v6)) | (HIDWORD(a1) << v6);
        v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)((uint32_t)a1 << v6) & 0xFFFFFFFFu);
      }
      v7 = HIWORD(v5);
      v8 = v4 / HIWORD(v5);
      v9 = WORD1(v3) | ((v4 % HIWORD(v5)) << 16);
      v10 = v8 * (uint16_t)v5;
      if ( v10 > v9 )
      {
        v11 = __CFADD__(v5, v9);
        v9 += v5;
        if ( v11 || v10 <= v9 )
        {
          --v8;
        }
        else
        {
          v8 -= 2;
          v9 += v5;
        }
      }
      v12 = v9 - v10;
      v13 = v12 / v7;
      v14 = (uint16_t)v3 | ((v12 % v7) << 16);
      v15 = v12 / v7 * (uint16_t)v5;
      if ( v15 > v14 )
      {
        v11 = __CFADD__(v5, v14);
        v14 += v5;
        if ( v11 || v15 <= v14 )
        {
          --v13;
        }
        else
        {
          v13 -= 2;
          v14 += v5;
        }
      }
      v16 = v14 - v15;
      a1 = (unsigned int)v13 | (uint64_t)(unsigned int)(v8 << 16);
    }
    if ( a4 )
      *a4 = v16 >> v6;
  }
  return a1;
}


// i32_abs @ 0x128280
int i32_abs(int result) {
  if ( result < 0 )
    return -result;
  return result;
}



// memcmp @ 0x128288
int memcmp(unsigned int a1, unsigned int a2, unsigned int a3) {
  volatile int *v3; // r4
  volatile int *v4; // r3
  int v5; // r5
  int v6; // t1
  int v7; // t1
  unsigned int v8; // r6
  volatile char *v9; // r1
  volatile char *v10; // r4
  int v11; // r5
  int v12; // t1
  int v13; // r2
  int v14; // t1

  if ( a3 <= 3 )
  {
LABEL_5:
    v8 = a3 - 1;
    if ( !a3 )
      return 0;
  }
  else
  {
    v3 = (volatile int *)a1;
    v4 = (volatile int *)a2;
    if ( !((a1 | a2) << 30) )
    {
      while ( 1 )
      {
        a2 = (unsigned int)v4;
        a1 = (unsigned int)v3;
        v6 = *v4++;
        v5 = v6;
        v7 = *v3++;
        if ( v7 != v5 )
          break;
        a3 -= 4;
        a1 = (unsigned int)v3;
        a2 = (unsigned int)v4;
        if ( a3 <= 3 )
          goto LABEL_5;
      }
    }
    v8 = a3 - 1;
  }
  v9 = (volatile char *)(a2 - 1);
  v10 = (volatile char *)(a1 - 1);
  do
  {
    v12 = (uint8_t)*++v10;
    v11 = v12;
    v14 = (uint8_t)*++v9;
    v13 = v14;
    if ( v11 != v14 )
      return v11 - v13;
  }
  while ( a1 + v8 - (uint32_t)v10 );
  return 0;
}



// memcpy @ 0x1282e8
/* libmatch: 308 bytes identical to memcpy (libc.a:libc_a-memcpy.o); the library routine is linked */


