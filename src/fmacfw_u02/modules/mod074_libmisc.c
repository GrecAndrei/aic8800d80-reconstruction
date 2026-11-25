// read_status_flag @ 0x1425d4
int read_status_flag(int a1, unsigned int a2) {
  if ( **(volatile int16_t **)off_142610 < 0 && *(volatile uint8_t *)(a2 + 8) == 255 )
    mmio_clear_register(dword_142618, dword_142614, 50);
  if ( (*(volatile uint16_t *)(a2 + 2) & 0xFC) == 0xD0 )
    adv_report_process(a2);
  return 0;
}



// double_add @ 0x14261c
uint64_t double_add(uint64_t a1) {
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
      return double_compare(a1, a1);
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
    if ( HIDWORD(a1) & (dword_1426AC >> (((HIDWORD(a1) >> 20) + 1) & 0xFF)) | (unsigned int)a1 )
    {
      v3 = (HIDWORD(a1) + (0x80000 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF))) & ~(dword_1426AC >> (((HIDWORD(a1) >> 20) + 1) & 0xFF));
      v5 = 0;
      return __PAIR64__(v3, v5);
    }
  }
  return v4;
}


// float_add @ 0x1426b0
/* luna: Returns the IEEE-754 single-precision value rounded down to the greatest integer not exceeding it, preserving signed zero and non-finite values. */
unsigned int float_add(unsigned int a1) {
  int unbiased_exponent; // r5
  unsigned int magnitude_bits; // r7
  unsigned int result_bits; // r6
  int fraction_mask; // r7
  unsigned int v6; // r0
  unsigned int v8; // r0

  unbiased_exponent = (uint8_t)(a1 >> 23) - 127;
  magnitude_bits = a1 & 0x7FFFFFFF;
  if ( unbiased_exponent > 22 )
  {
    if ( magnitude_bits >= 0x7F800000 )
      return ((int (*)())float_compare)(a1, a1);
    return a1;
  }
  result_bits = a1;
  if ( unbiased_exponent < 0 )
  {
    v8 = ((int (*)())float_compare)(a1, dword_142728);
    if ( call_helper_bool(v8, 0) )
    {
      if ( (a1 & 0x80000000) == 0 )
        return 0;
      if ( magnitude_bits )
        return dword_14272C;
    }
    return a1;
  }
  fraction_mask = dword_142724 >> unbiased_exponent;
  if ( (a1 & (dword_142724 >> unbiased_exponent)) == 0 )
    return a1;
  v6 = ((int (*)())float_compare)(a1, dword_142728);
  if ( !call_helper_bool(v6, 0) )
    return a1;
  if ( (a1 & 0x80000000) != 0 )
    result_bits += 0x800000 >> unbiased_exponent;
  return result_bits & ~fraction_mask;
}


// double_compare_wrapper @ 0x142738
/* libmatch: 634 bytes identical to __aeabi_dsub (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_compare @ 0x14273c
/* libmatch: 630 bytes identical to __aeabi_dadd (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// uint_to_double @ 0x1429b4
/* libmatch: 30 bytes identical to __aeabi_ui2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// int_to_double @ 0x1429d4
/* libmatch: 34 bytes identical to __aeabi_i2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// float_to_double @ 0x1429f8
/* libmatch: 66 bytes identical to __aeabi_f2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_to_float @ 0x142a3c
/* libmatch: 106 bytes identical to __aeabi_ul2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_add_1 @ 0x142aa8
/* libmatch: 596 bytes identical to __aeabi_dmul (libgcc.a:_arm_muldf3.o); the library routine is linked */


// double_multiply @ 0x142c84
/* libmatch: interior fragment of __aeabi_dmul @ 0x142aa8 (libgcc.a:_arm_muldf3.o); dropped */


// double_subtract @ 0x142cfc
/* libmatch: 464 bytes identical to __aeabi_ddiv (libgcc.a:_arm_muldivdf3.o); the library routine is linked */


// double_divide @ 0x142e6a
/* libmatch: interior fragment of __aeabi_ddiv @ 0x142cfc (libgcc.a:_arm_muldivdf3.o); dropped */


// double_compare_core @ 0x142edc
/* libmatch: 122 bytes identical to __cmpdf2 (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_swap_compare @ 0x142f58
/* libmatch: 32 bytes identical to __aeabi_cdrcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_compare_flags @ 0x142f68
/* libmatch: 16 bytes identical to __aeabi_cdcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_eq @ 0x142f78
/* libmatch: 18 bytes identical to __aeabi_dcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_lt @ 0x142f8c
/* libmatch: 18 bytes identical to __aeabi_dcmplt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_le @ 0x142fa0
/* libmatch: 18 bytes identical to __aeabi_dcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_ge @ 0x142fb4
/* libmatch: 18 bytes identical to __aeabi_dcmpge (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_gt @ 0x142fc8
/* libmatch: 18 bytes identical to __aeabi_dcmpgt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_to_float_1 @ 0x142fdc
/* libmatch: 78 bytes identical to __aeabi_d2iz (libgcc.a:_arm_fixdfsi.o); the library routine is linked */


// double_to_int @ 0x14302c
/* libmatch: 64 bytes identical to __aeabi_d2uiz (libgcc.a:_arm_fixunsdfsi.o); the library routine is linked */


// double_to_uint @ 0x14306c
/* libmatch: 158 bytes identical to __aeabi_d2f (libgcc.a:_arm_truncdfsf2.o); the library routine is linked */


// float_compare @ 0x143118
/* libmatch: 352 bytes identical to __aeabi_fadd (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// float_zero_common @ 0x14329c
/* libmatch: 140 bytes identical to __aeabi_ul2f (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// float_compare_core @ 0x143338
/* libmatch: 94 bytes identical to __cmpsf2 (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// float_swap_compare @ 0x143398
/* libmatch: 24 bytes identical to __aeabi_cfrcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// cmp_eq @ 0x1433b0
/* libmatch: 18 bytes identical to __aeabi_fcmpeq (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// cmp_lo @ 0x1433c4
/* libmatch: 18 bytes identical to __aeabi_fcmplt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// cmp_ls @ 0x1433d8
/* libmatch: 18 bytes identical to __aeabi_fcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// float_ge @ 0x1433ec
/* libmatch: 18 bytes identical to __aeabi_fcmpge (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// call_helper_bool @ 0x143400
/* libmatch: 18 bytes identical to __aeabi_fcmpgt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// validate_args @ 0x143414
uint64_t validate_args(uint64_t a1, uint64_t a2) {
  uint64_t v2; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return memcpy_chk(a1, a2, &v2);
  if ( a1 )
    return -1;
  return a1;
}


// memcpy_chk @ 0x143444
uint64_t memcpy_chk(uint64_t a1, uint64_t a2, volatile uint64_t *a4) {
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


// abs_i32 @ 0x143708
/* luna: Returns the absolute value of an integer. */
int abs_i32(int result) {
  if ( result < 0 )
    return -result;
  return result;
}



// memcmp @ 0x143710
/* luna: Compares two byte ranges, using aligned 32-bit loads where possible, and returns the first unsigned-byte difference or zero if they match. */
int memcmp(unsigned int a1, unsigned int a2, unsigned int a3) {
  volatile int *first_word_ptr; // r4
  volatile int *second_word_ptr; // r3
  int second_word; // r5
  int v6; // t1
  int v7; // t1
  unsigned int tail_length_minus_one; // r6
  volatile char *second_byte_ptr; // r1
  volatile char *first_byte_ptr; // r4
  int first_byte; // r5
  int v12; // t1
  int second_byte; // r2
  int v14; // t1

  if ( a3 <= 3 )
  {
LABEL_5:
    tail_length_minus_one = a3 - 1;
    if ( !a3 )
      return 0;
  }
  else
  {
    first_word_ptr = (volatile int *)a1;
    second_word_ptr = (volatile int *)a2;
    if ( !((a1 | a2) << 30) )
    {
      while ( 1 )
      {
        a2 = (unsigned int)second_word_ptr;
        a1 = (unsigned int)first_word_ptr;
        v6 = *second_word_ptr++;
        second_word = v6;
        v7 = *first_word_ptr++;
        if ( v7 != second_word )
          break;
        a3 -= 4;
        a1 = (unsigned int)first_word_ptr;
        a2 = (unsigned int)second_word_ptr;
        if ( a3 <= 3 )
          goto LABEL_5;
      }
    }
    tail_length_minus_one = a3 - 1;
  }
  second_byte_ptr = (volatile char *)(a2 - 1);
  first_byte_ptr = (volatile char *)(a1 - 1);
  do
  {
    v12 = (uint8_t)*++first_byte_ptr;
    first_byte = v12;
    v14 = (uint8_t)*++second_byte_ptr;
    second_byte = v14;
    if ( first_byte != v14 )
      return first_byte - second_byte;
  }
  while ( a1 + tail_length_minus_one - (uint32_t)first_byte_ptr );
  return 0;
}



// memcpy @ 0x143770
/* libmatch: 308 bytes identical to memcpy (libc.a:libc_a-memcpy.o); the library routine is linked */


// memmove @ 0x1438a4
/* luna: Copies a byte range from source to destination while preserving correctness when the ranges overlap, using aligned word copies when possible. */
unsigned int memmove(unsigned int result, unsigned int a2, unsigned int a3) {
  volatile uint8_t *source_end; // r3
  unsigned int v4; // r2
  char v5; // t1
  unsigned int v6; // r3
  unsigned int v7; // r4
  volatile uint8_t *v8; // r4
  unsigned int destination_cursor; // r3
  char copied_byte; // t1
  volatile uint8_t *source_cursor; // r4
  unsigned int v12; // r5
  unsigned int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r12
  unsigned int v17; // r4
  volatile int *source_word_cursor; // r6
  int v19; // t1

  if ( result <= a2 || (source_end = (volatile uint8_t *)(a2 + a3), a2 + a3 <= result) )
  {
    if ( a3 > 0xF )
    {
      if ( (result | a2) << 30 )
      {
        v7 = a3 - 1;
        v6 = result;
LABEL_10:
        v8 = (volatile uint8_t *)(v7 + 1 + a2);
        destination_cursor = v6 - 1;
        do
        {
          copied_byte = *(volatile uint8_t *)a2++;
          *(volatile uint8_t *)++destination_cursor = copied_byte;
        }
        while ( (volatile uint8_t *)a2 != v8 );
        return result;
      }
      source_cursor = (volatile uint8_t *)(a2 + 16);
      v12 = result + 16;
      do
      {
        *(volatile uint32_t *)(v12 - 16) = *((volatile uint32_t *)source_cursor - 4);
        *(volatile uint32_t *)(v12 - 12) = *((volatile uint32_t *)source_cursor - 3);
        *(volatile uint32_t *)(v12 - 8) = *((volatile uint32_t *)source_cursor - 2);
        *(volatile uint32_t *)(v12 - 4) = *((volatile uint32_t *)source_cursor - 1);
        source_cursor += 16;
        v12 += 16;
      }
      while ( source_cursor != (volatile uint8_t *)(a2 + 32 + ((a3 - 16) & 0xFFFFFFF0)) );
      v13 = ((a3 - 16) >> 4) + 1;
      a2 += 16 * v13;
      v6 = result + 16 * v13;
      if ( (a3 & 0xC) != 0 )
      {
        v14 = (a3 & 0xF) - 4;
        v15 = v14 >> 2;
        v16 = (v14 & 0xFFFFFFFC) + v6;
        v17 = v6 - 4;
        source_word_cursor = (volatile int *)a2;
        do
        {
          v19 = *source_word_cursor++;
          *(volatile uint32_t *)(v17 + 4) = v19;
          v17 += 4;
        }
        while ( v17 != v16 );
        v6 += 4 * (v15 + 1);
        a2 += 4 * (v15 + 1);
        a3 &= 3u;
      }
      else
      {
        a3 &= 0xFu;
      }
    }
    else
    {
      v6 = result;
    }
    v7 = a3 - 1;
    if ( !a3 )
      return result;
    goto LABEL_10;
  }
  if ( a3 )
  {
    v4 = result + a3;
    do
    {
      v5 = *--source_end;
      *(volatile uint8_t *)--v4 = v5;
    }
    while ( (volatile uint8_t *)a2 != source_end );
  }
  return result;
}



// scale_timer_value @ 0x14397c
int scale_timer_value() {
  uint64_t v0; // kr00_8

  v0 = *(volatile uint64_t *)(*(volatile uint32_t *)off_1439AC + 168) * __PAIR64__(dword_1439B0, dword_1439B4) + 1;
  *(volatile uint64_t *)(*(volatile uint32_t *)off_1439AC + 168) = v0;
  return HIDWORD(v0) & 0x7FFFFFFF;
}



// strchr @ 0x1439b8
/* luna: Returns a pointer to the first occurrence of the target byte in the string, or null if a nonzero target is absent. */
volatile uint8_t * strchr(volatile uint8_t *result, uint8_t a2) {
  volatile uint8_t *scan_cursor; // r3
  int target_byte_splat; // r6
  int v4; // t1
  int current_byte; // r3
  int v6; // t1
  int loaded_byte; // r2
  int v8; // t1
  int v9; // t1

  scan_cursor = result;
  if ( a2 )
  {
    if ( (uint32_t)result << 30 )
    {
      while ( 1 )
      {
        result = scan_cursor;
        v8 = *scan_cursor++;
        loaded_byte = v8;
        if ( !v8 )
          return 0;
        if ( loaded_byte == a2 )
          return result;
        result = scan_cursor;
        if ( !((uint32_t)scan_cursor << 30) )
          goto LABEL_3;
      }
    }
    else
    {
LABEL_3:
      target_byte_splat = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
      if ( ((((target_byte_splat ^ *(volatile uint32_t *)result) - 16843009) & ~(target_byte_splat ^ *(volatile uint32_t *)result)
           | (*(volatile uint32_t *)result - 16843009) & ~*(volatile uint32_t *)result)
          & 0x80808080) == 0 )
      {
        do
        {
          v4 = *((volatile uint32_t *)result + 1);
          result += 4;
        }
        while ( (((v4 - 16843009) & ~v4 | ((v4 ^ target_byte_splat) - 16843009) & ~(v4 ^ target_byte_splat)) & 0x80808080) == 0 );
      }
      current_byte = *result;
      if ( *result )
      {
        while ( a2 != current_byte )
        {
          v6 = *++result;
          current_byte = v6;
          if ( !v6 )
            return (volatile uint8_t *)current_byte;
        }
      }
      else
      {
        return (volatile uint8_t *)current_byte;
      }
    }
  }
  else if ( (uint32_t)result << 30 )
  {
    while ( 1 )
    {
      result = scan_cursor++;
      if ( !*result )
        break;
      result = scan_cursor;
      if ( !((uint32_t)scan_cursor << 30) )
        goto LABEL_18;
    }
  }
  else
  {
LABEL_18:
    if ( ((*(volatile uint32_t *)result - 16843009) & ~*(volatile uint32_t *)result & 0x80808080) == 0 )
    {
      do
      {
        v9 = *((volatile uint32_t *)result + 1);
        result += 4;
      }
      while ( ((v9 - 16843009) & ~v9 & 0x80808080) == 0 );
    }
    if ( *result )
    {
      while ( *++result )
        ;
    }
  }
  return result;
}



// strcmp @ 0x143aa8
/* luna: Compares two NUL-terminated byte strings lexicographically, using wide-word loads for the fast path. */
int strcmp(unsigned int a1, volatile unsigned int *a2) {
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;
uint32_t _R5;

  int first_string_byte; // r2
  int second_string_byte; // r3
  char v7; // r4
  volatile uint64_t *v8; // r0
  volatile uint64_t *v9; // r1
  uint64_t v10; // t1
  uint64_t v11; // t1
  int v12; // r4
  uint64_t v14; // r6
  uint64_t v15; // t1
  uint64_t v16; // t1
  char v30; // r4
  char v31; // r4
  char v32; // r4
  unsigned int v34; // t1
  unsigned int v35; // r3
  unsigned int v36; // t1
  char v42; // r4
  volatile int *v43; // r0
  int v44; // r2
  int v45; // t1
  volatile uint32_t *v46; // r1
  int v47; // t1
  int v48; // r4
  int v49; // r4
  volatile char *v50; // r1
  volatile int *v51; // r0
  int v52; // r2
  int v53; // t1
  int v54; // r3
  uint8_t v55; // t2
  int v56; // r4
  int v57; // r3
  uint8_t v58; // t2
  volatile unsigned int *v59; // r0
  unsigned int v61; // t1
  char v63; // cc
  volatile uint32_t *v64; // r1
  volatile uint16_t *v65; // r1
  unsigned int v66; // r3
  unsigned int v67; // t1
  unsigned int v71; // t1
  unsigned int v72; // t1
  unsigned int v76; // t1
  unsigned int v77; // t1
  unsigned int v81; // t1
  unsigned int v82; // t1
  unsigned int v84; // r3

  first_string_byte = *(volatile uint8_t *)a1;
  second_string_byte = *(volatile uint8_t *)a2;
  _ZF = first_string_byte == 1;
  if ( *(volatile uint8_t *)a1 )
    _ZF = first_string_byte == second_string_byte;
  if ( !_ZF )
    return first_string_byte - second_string_byte;
  _R12 = -1;
  if ( !((a1 | (unsigned int)a2) << 29) )
    goto LABEL_9;
  if ( ((a1 ^ (unsigned int)a2) & 7) == 0 )
  {
    v7 = a1 & 7;
    v8 = (volatile uint64_t *)(a1 & 0xFFFFFFF8);
    v9 = (volatile uint64_t *)((unsigned int)a2 & 0xFFFFFFF8);
    v10 = *v8;
    a1 = (unsigned int)(v8 + 2);
    _R2 = v10;
    _ZF = (v7 & 4) == 0;
    v11 = *v9;
    a2 = (volatile unsigned int *)(v9 + 2);
    v12 = -1 << (8 * (v7 & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~v12) & 0xFFFFFFFFULL) << 0);
    v14 = v11 | (unsigned int)~v12;
    if ( !_ZF )
    {
      _R2 = _R2 | (((uint64_t)(~v12)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
      v14 = v14 | (((uint64_t)(~v12)) << 32);
      v14 = (v14 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    while ( 1 )
    {
      (void)0;

      _R4 = _R2 ^ v14;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      if ( _R4 )
        break;
      (void)0;

      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      if ( _R5 )
        goto LABEL_14;
      _R2 = *(volatile uint64_t *)(a1 - 8);
      v14 = *((volatile uint64_t *)a2 - 1);
      (void)0;

      _R4 = _R2 ^ v14;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      _R5 = HIDWORD(_R2) ^ HIDWORD(v14);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      _R5 = _R5 | _R4;
      if ( _R5 )
      {
        if ( !_R4 )
        {
LABEL_14:
          v30 = __clz(bswap32(_R5)) & 0xF8;
          return (uint8_t)(HIDWORD(_R2) >> v30) - (uint8_t)(HIDWORD(v14) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(volatile uint64_t *)a1;
      a1 += 16;
      _R2 = v15;
      v16 = *(volatile uint64_t *)a2;
      a2 += 4;
      v14 = v16;
    }
    v31 = __clz(bswap32(_R4)) & 0xF8;
    return (uint8_t)((unsigned int)_R2 >> v31) - (uint8_t)((unsigned int)v14 >> v31);
  }
  if ( (((uint8_t)a1 ^ (uint8_t)a2) & 3) == 0 )
  {
    v32 = a1 & 3;
    if ( (a1 & 3) != 0 )
    {
      v43 = (volatile int *)(a1 & 0xFFFFFFFC);
      v45 = *v43;
      a1 = (unsigned int)(v43 + 2);
      v44 = v45;
      v46 = (void *)((volatile uint32_t *)((unsigned int)a2 & 0xFFFFFFFC));
      v47 = *v46;
      a2 = (void *)(v46 + 2);
      v48 = -1 << (8 * v32);
      _R2 = v44 | ~v48;
      v35 = v47 | ~v48;
      goto LABEL_19;
    }
    do
    {
      v34 = *(volatile uint32_t *)a1;
      a1 += 8;
      _R2 = v34;
      v36 = *a2;
      a2 += 2;
      v35 = v36;
LABEL_19:
      (void)0;

      _R5 = _R2 ^ v35;
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);

      if ( _R5 )
        break;
      _R2 = *(volatile uint32_t *)(a1 - 4);
      v35 = *(a2 - 1);
      (void)0;

      _R5 = _R2 ^ v35;
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);

    }
    while ( !_R5 );
    v42 = __clz(bswap32(_R5)) & 0xF8;
    return (uint8_t)(_R2 >> v42) - (uint8_t)(v35 >> v42);
  }
  v49 = a1 & 3;
  if ( (a1 & 3) != 0 )
  {
    v50 = (volatile char *)a2 - v49;
    v51 = (volatile int *)(a1 & 0xFFFFFFFC);
    v53 = *v51;
    a1 = (unsigned int)(v51 + 1);
    v52 = v53;
    if ( v49 << 31 )
    {
      if ( __CFSHL__(v49, 31) )
      {
LABEL_31:
        a2 = (volatile unsigned int *)(v50 + 4);
        goto LABEL_32;
      }
      v54 = (uint8_t)v50[2];
      v55 = __ROR4__(v52, 16);
      v56 = v55 - v54;
      if ( v55 != v54 || !v50[2] )
        return v56;
    }
    v57 = (uint8_t)v50[3];
    v58 = __ROR4__(v52, 24);
    v56 = v58 - v57;
    if ( v58 != v57 || !v50[3] )
      return v56;
    goto LABEL_31;
  }
LABEL_32:
  v61 = *(volatile uint32_t *)a1;
  v59 = (volatile unsigned int *)(a1 + 4);
  _R2 = v61;
  _CF = __CFSHL__(a2, 31);
  v63 = ((uint32_t)a2 << 31 != 0) & __CFSHL__(a2, 31);
  v64 = (volatile uint32_t *)((unsigned int)a2 & 0xFFFFFFFC);
  v67 = *v64;
  v65 = (volatile uint16_t *)(v64 + 1);
  v66 = v67;
  if ( v63 )
  {
    while ( 1 )
    {
      (void)0;

      _R5 = (uint8_t)_R2 ^ (uint8_t)(v66 >> 24);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 24;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v81 = *(volatile uint32_t *)v65;
      v65 += 2;
      v66 = v81;
      if ( ((uint8_t)_R2 ^ _R2) != v81 << 8 )
        goto LABEL_57;
      v82 = *v59++;
      _R2 = v82;
    }
    if ( !(uint8_t)_R5 )
    {
      v66 = *(volatile uint32_t *)v65;
LABEL_57:
      _R2 >>= 8;
      v66 &= 0xFFFFFFu;
      goto LABEL_59;
    }
    return 0;
  }
  else if ( _CF )
  {
    while ( 1 )
    {
      (void)0;

      _R5 = (uint16_t)_R2 ^ HIWORD(v66);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 16;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v76 = *(volatile uint32_t *)v65;
      v65 += 2;
      v66 = v76;
      if ( ((uint16_t)_R2 ^ _R2) != v76 << 16 )
      {
        _R2 >>= 16;
        v66 = (uint16_t)v66;
        goto LABEL_59;
      }
      v77 = *v59++;
      _R2 = v77;
    }
    if ( (uint16_t)_R5 )
      return 0;
    v66 = *v65;
    _R2 >>= 16;
LABEL_59:
    _R2 = bswap32(_R2);
    v84 = bswap32(v66);
    (void)0;

    _R4 = _R2 ^ v84;
    _R5 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

    _R4 = ((unsigned)(_R4) & 0xFFFFFF00U) | (((unsigned)(__clz(_R5)) & 0xFFU) << 0);
    return ((uint32_t)_R2 << _R4 >> 24) - (v84 << _R4 >> 24);
  }
  else
  {
    while ( 1 )
    {
      (void)0;

      _R5 = _R2 & 0xFFFFFF ^ (v66 >> 8);
      if ( (uint32_t)_R5 )
      {
        v66 >>= 8;
        goto LABEL_59;
      }
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)_R2);
      if ( _R5 )
        break;
      v71 = *(volatile uint32_t *)v65;
      v65 += 2;
      v66 = v71;
      if ( (_R2 & 0xFFFFFF ^ _R2) != v71 << 24 )
      {
        _R2 >>= 24;
        v66 = (uint8_t)v66;
        goto LABEL_59;
      }
      v72 = *v59++;
      _R2 = v72;
    }
    if ( (_R5 & 0xFFFFFF) != 0 )
      return 0;
    return -*(volatile uint8_t *)v65;
  }
}


// strcpy @ 0x143d7c
/* libmatch: 186 bytes identical to strcpy (libc.a:libc_a-strcpy.o); the library routine is linked */


// strlen @ 0x143e40
/* luna: Returns the number of bytes before the terminating NUL using aligned word-at-a-time scanning. */
unsigned int strlen(unsigned int a1) {
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;

  volatile uint64_t *aligned_scan_ptr; // r1
  int initial_alignment_offset; // r4
  int length_offset; // r0
  int prefix_byte_mask; // r5

  __pld((void *)a1);
  aligned_scan_ptr = (volatile uint64_t *)(a1 & 0xFFFFFFF8);
  _R12 = -1;
  initial_alignment_offset = a1 & 7;
  __pld((void *)((a1 & 0xFFFFFFF8) + 32));
  if ( (a1 & 7) != 0 )
  {
    _R2 = *aligned_scan_ptr;
    length_offset = -initial_alignment_offset;
    __pld(aligned_scan_ptr + 8);
    prefix_byte_mask = -1 << (8 * (initial_alignment_offset & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~prefix_byte_mask) & 0xFFFFFFFFULL) << 0);
    if ( (initial_alignment_offset & 4) != 0 )
    {
      _R2 = _R2 | (((uint64_t)(~prefix_byte_mask)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    _R4 = 0;
    goto LABEL_4;
  }
  _R4 = 0;
  length_offset = -8;
  do
  {
    _R2 = *aligned_scan_ptr;
    __pld(aligned_scan_ptr + 8);
    length_offset += 8;
LABEL_4:
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = aligned_scan_ptr[1];
    (void)0;

    length_offset += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = aligned_scan_ptr[2];
    (void)0;

    length_offset += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = aligned_scan_ptr[3];
    aligned_scan_ptr += 4;
    (void)0;

    length_offset += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

  }
  while ( !HIDWORD(_R2) );
  if ( !(uint32_t)_R2 )
  {
    length_offset += 4;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(HIDWORD(_R2)) & 0xFFFFFFFFULL) << 0);
  }
  return length_offset + (__clz(bswap32(_R2)) >> 3);
}


// strncasecmp @ 0x143f1c
/* luna: Compares up to the specified number of bytes in two strings without regard to uppercase or lowercase, returning the difference at the first mismatch. */
int strncasecmp(volatile uint8_t *a1, volatile uint8_t *a2, int a3) {
  volatile uint8_t *first_cursor; // r5
  volatile uint8_t *first_end; // r7
  int comparison_difference; // r3
  int first_normalized_char; // r3
  int first_char; // t1
  int second_char; // r2
  int second_char_raw; // t1
  int second_char_case_class; // r4
  int result; // r0
  int second_normalized_char; // r2

  if ( a3 )
  {
    first_cursor = a1;
    first_end = &a1[a3];
    while ( 1 )
    {
      first_char = *first_cursor++;
      first_normalized_char = first_char;
      second_char_raw = *a2++;
      second_char = second_char_raw;
      second_char_case_class = *(volatile uint8_t *)(dword_143F6C + second_char_raw) & 3;
      if ( (*(volatile uint8_t *)(dword_143F6C + first_normalized_char) & 3) == 1 )
        first_normalized_char += 32;
      result = second_char;
      if ( second_char_case_class == 1 )
      {
        second_normalized_char = second_char + 32;
        result = first_normalized_char - second_normalized_char;
        if ( first_normalized_char != second_normalized_char )
          return result;
      }
      else
      {
        comparison_difference = first_normalized_char - second_char;
        if ( comparison_difference )
          return comparison_difference;
        if ( !second_char )
          return result;
      }
      if ( first_cursor == first_end )
        return 0;
    }
  }
  return 0;
}



// nop_return @ 0x14e038
void nop_return() {
  ;
}



// nop_return2 @ 0x14e044
/* luna: Performs no operation and returns immediately. */
void nop_return2() {
  ;
}



