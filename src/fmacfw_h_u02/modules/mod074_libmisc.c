// global_table_lookup @ 0x142494
int global_table_lookup(int a1, unsigned int a2) {
  if ( **(volatile int16_t **)off_1424D0 < 0 && *(volatile uint8_t *)(a2 + 8) == 255 )
    irq_disable_mmio_write(dword_1424D8, dword_1424D4, 50);
  if ( (*(volatile uint16_t *)(a2 + 2) & 0xFC) == 0xD0 )
    bt_data_process(a2);
  return 0;
}



// double_exp_check @ 0x1424dc
/* luna: Rounds a binary64 value to the nearest integral value, with halfway cases rounded away from zero. */
uint64_t double_exp_check(uint64_t a1) {
  int exponent_field; // r7
  int unbiased_exponent; // r4
  int result_high_word; // r5
  uint64_t original_value_bits; // r2
  int result_low_word; // r3
  unsigned int fractional_mask; // r7
  int rounding_increment; // r3
  int carry_flag; // cf
  int incremented_low_word; // r3

  exponent_field = (HIDWORD(a1) >> 20) & 0x7FF;
  unbiased_exponent = exponent_field - 1023;
  result_high_word = HIDWORD(a1);
  original_value_bits = a1;
  if ( exponent_field - 1023 > 19 )
  {
    if ( unbiased_exponent <= 51 )
    {
      fractional_mask = 0xFFFFFFFF >> (((HIDWORD(a1) >> 20) - 19) & 0xFF);
      if ( ((unsigned int)a1 & fractional_mask) != 0 )
      {
        rounding_increment = 1 << (51 - unbiased_exponent);
        carry_flag = __CFADD__((uint32_t)a1, rounding_increment);
        incremented_low_word = a1 + rounding_increment;
        if ( carry_flag )
          result_high_word = HIDWORD(a1) + 1;
        result_low_word = incremented_low_word & ~fractional_mask;
        return __PAIR64__(result_high_word, result_low_word);
      }
    }
    else if ( exponent_field == 2047 )
    {
      return double_add(a1, a1);
    }
  }
  else
  {
    if ( unbiased_exponent < 0 )
    {
      result_high_word = HIDWORD(a1) & 0x80000000;
      if ( exponent_field == 1022 )
        result_high_word |= 0x3FF00000u;
      result_low_word = 0;
      return __PAIR64__(result_high_word, result_low_word);
    }
    if ( HIDWORD(a1) & (dword_14256C >> (((HIDWORD(a1) >> 20) + 1) & 0xFF)) | (unsigned int)a1 )
    {
      result_high_word = (HIDWORD(a1) + (0x80000 >> (((HIDWORD(a1) >> 20) + 1) & 0xFF))) & ~(dword_14256C >> (((HIDWORD(a1) >> 20) + 1) & 0xFF));
      result_low_word = 0;
      return __PAIR64__(result_high_word, result_low_word);
    }
  }
  return original_value_bits;
}


// float_to_int_convert @ 0x142570
unsigned int float_to_int_convert(unsigned int a1) {
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
      return ((int (*)())float_add)(a1, a1);
    return a1;
  }
  v4 = a1;
  if ( v1 < 0 )
  {
    v8 = ((int (*)())float_add)(a1, dword_1425E8);
    if ( double_cmplt(v8, 0) )
    {
      if ( (a1 & 0x80000000) == 0 )
        return 0;
      if ( v3 )
        return dword_1425EC;
    }
    return a1;
  }
  v5 = dword_1425E4 >> v1;
  if ( (a1 & (dword_1425E4 >> v1)) == 0 )
    return a1;
  v6 = ((int (*)())float_add)(a1, dword_1425E8);
  if ( !double_cmplt(v6, 0) )
    return a1;
  if ( (a1 & 0x80000000) != 0 )
    v4 += 0x800000 >> v1;
  return v4 & ~v5;
}


// double_compare_neg @ 0x1425f8
/* libmatch: 634 bytes identical to __aeabi_dsub (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_add @ 0x1425fc
/* libmatch: 630 bytes identical to __aeabi_dadd (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// unsigned_int_to_double @ 0x142874
/* libmatch: 30 bytes identical to __aeabi_ui2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// signed_int_to_double @ 0x142894
/* libmatch: 34 bytes identical to __aeabi_i2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// float_to_double @ 0x1428b8
/* libmatch: 66 bytes identical to __aeabi_f2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// uint64_to_double @ 0x1428fc
/* libmatch: 106 bytes identical to __aeabi_ul2d (libgcc.a:_arm_addsubdf3.o); the library routine is linked */


// double_multiply @ 0x142968
/* libmatch: 596 bytes identical to __aeabi_dmul (libgcc.a:_arm_muldf3.o); the library routine is linked */


// double_compare_nan @ 0x142b44
/* libmatch: interior fragment of __aeabi_dmul @ 0x142968 (libgcc.a:_arm_muldf3.o); dropped */


// double_divide @ 0x142bbc
/* libmatch: 464 bytes identical to __aeabi_ddiv (libgcc.a:_arm_muldivdf3.o); the library routine is linked */


// double_compare_ord @ 0x142d2a
/* libmatch: interior fragment of __aeabi_ddiv @ 0x142bbc (libgcc.a:_arm_muldivdf3.o); dropped */


// double_compare_flags @ 0x142d9c
/* libmatch: 122 bytes identical to __cmpdf2 (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// swap_double_operands @ 0x142e18
/* libmatch: 32 bytes identical to __aeabi_cdrcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_compare_condition @ 0x142e28
/* libmatch: 16 bytes identical to __aeabi_cdcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_equals @ 0x142e38
/* libmatch: 18 bytes identical to __aeabi_dcmpeq (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_less_than @ 0x142e4c
/* libmatch: 18 bytes identical to __aeabi_dcmplt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_less_equal @ 0x142e60
/* libmatch: 18 bytes identical to __aeabi_dcmple (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_greater_equal @ 0x142e74
/* libmatch: 18 bytes identical to __aeabi_dcmpge (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_greater_than @ 0x142e88
/* libmatch: 18 bytes identical to __aeabi_dcmpgt (libgcc.a:_arm_cmpdf2.o); the library routine is linked */


// double_to_float_1 @ 0x142e9c
/* libmatch: 78 bytes identical to __aeabi_d2iz (libgcc.a:_arm_fixdfsi.o); the library routine is linked */


// double_to_uint32 @ 0x142eec
/* libmatch: 64 bytes identical to __aeabi_d2uiz (libgcc.a:_arm_fixunsdfsi.o); the library routine is linked */


// double_to_int @ 0x142f2c
/* libmatch: 158 bytes identical to __aeabi_d2f (libgcc.a:_arm_truncdfsf2.o); the library routine is linked */


// float_add @ 0x142fd8
/* libmatch: 352 bytes identical to __aeabi_fadd (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// double_is_zero @ 0x14315c
/* libmatch: 140 bytes identical to __aeabi_ul2f (libgcc.a:_arm_addsubsf3.o); the library routine is linked */


// double_compare @ 0x1431f8
/* libmatch: 94 bytes identical to __cmpsf2 (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// float_compare_reverse_less_equal @ 0x143258
/* libmatch: 24 bytes identical to __aeabi_cfrcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_not_equal @ 0x143270
/* libmatch: 18 bytes identical to __aeabi_fcmpeq (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_greater_equal @ 0x143284
/* libmatch: 18 bytes identical to __aeabi_fcmplt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// is_less_equal @ 0x143298
/* libmatch: 18 bytes identical to __aeabi_fcmple (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// double_cmple @ 0x1432ac
/* libmatch: 18 bytes identical to __aeabi_fcmpge (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// double_cmplt @ 0x1432c0
/* libmatch: 18 bytes identical to __aeabi_fcmpgt (libgcc.a:_arm_cmpsf2.o); the library routine is linked */


// double_cmp @ 0x1432d4
/* luna: Returns the unsigned 64-bit quotient, yielding UINT64_MAX for a nonzero dividend divided by zero and zero for 0 divided by 0. */
uint64_t double_cmp(uint64_t a1, uint64_t a2) {
  uint64_t remainder; // [sp+8h] [bp-8h] BYREF

  if ( a2 )
    return uint64_divmod(a1, a2, &remainder);
  if ( a1 )
    return -1;
  return a1;
}


// uint64_divmod @ 0x143304
/* luna: Returns the unsigned 64-bit quotient of dividend divided by divisor and optionally stores the remainder through remainder_out. */
uint64_t uint64_divmod(uint64_t a1, uint64_t a2, volatile uint64_t *a4) {
  uint64_t dividend_copy; // r4
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

  dividend_copy = a1;
  v4 = HIDWORD(a1);
  if ( HIDWORD(a2) )
  {
    if ( HIDWORD(a2) <= HIDWORD(a1) )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(__clz(HIDWORD(a2))) << 32);
      if ( HIDWORD(a1) )
      {
        v32 = ((unsigned int)a2 >> (32 - BYTE4(a1))) | (HIDWORD(a2) << SBYTE4(a1));
        a2 = (a2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(HIDWORD(dividend_copy) << SBYTE4(a1)) << 32);
        v33 = HIWORD(v32);
        v34 = HIDWORD(dividend_copy) >> (32 - BYTE4(a1));
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
if ( HIDWORD(a2) >= HIDWORD(dividend_copy) && (unsigned int)a2 > (unsigned int)a1 ) { a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
        }
        else
        {
          v25 = __PAIR64__(HIDWORD(dividend_copy), a1) - a2;
          v24 = (__PAIR64__(HIDWORD(dividend_copy), a1) - a2) >> 32;
          dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)(v25) & 0xFFFFFFFFu);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(1) & 0xFFFFFFFFu);
          v4 = v24;
        }
        if ( a4 )
        {
          *(volatile uint32_t *)a4 = dividend_copy;
          *((volatile uint32_t *)a4 + 1) = v4;
        }
      }
    }
else { a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(0) << 32);
      if ( a4 )
      {
        *(volatile uint32_t *)a4 = a1;
        *((volatile uint32_t *)a4 + 1) = HIDWORD(dividend_copy);
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
        dividend_copy = (dividend_copy & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(WORD1(a1) | ((v26 % HIWORD(v5)) << 16)) << 32);
        v27 = HIDWORD(a1) * (uint16_t)v5;
        dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)((uint32_t)dividend_copy << v6) & 0xFFFFFFFFu);
        if ( v27 > HIDWORD(dividend_copy) )
        {
          v11 = __CFADD__(v5, HIDWORD(dividend_copy));
          dividend_copy = (dividend_copy & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(dividend_copy >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
          if ( v11 || v27 <= HIDWORD(dividend_copy) )
          {
            a1 = (a1 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(a1 >> 32) & 0xFFFFFFFFu) - (uint32_t)(1))) << 32;;
          }
          else
          {
            a1 = (a1 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(a1 >> 32) & 0xFFFFFFFFu) - (uint32_t)(2))) << 32;;
            dividend_copy = (dividend_copy & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(dividend_copy >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
          }
        }
        v28 = HIDWORD(dividend_copy) - v27;
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
      dividend_copy = (dividend_copy & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(WORD1(dividend_copy) | ((v17 % v18) << 16)) << 32);
      v21 = v19 * (v17 / v18);
      if ( v21 > HIDWORD(dividend_copy) )
      {
        v11 = __CFADD__(v5, HIDWORD(dividend_copy));
        dividend_copy = (dividend_copy & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(dividend_copy >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
        if ( v11 || v21 <= HIDWORD(dividend_copy) )
        {
          --v20;
        }
        else
        {
          v20 -= 2;
          dividend_copy = (dividend_copy & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(dividend_copy >> 32) & 0xFFFFFFFFu) + (uint32_t)(v5))) << 32;;
        }
      }
      dividend_copy = (dividend_copy & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(dividend_copy >> 32) & 0xFFFFFFFFu) - (uint32_t)(v21))) << 32;;
      v22 = HIDWORD(dividend_copy) / v18;
      dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)((uint16_t)dividend_copy | ((HIDWORD(dividend_copy) % v18) << 16)) & 0xFFFFFFFFu);
      v23 = v19 * (HIDWORD(dividend_copy) / v18);
      if ( v23 > (unsigned int)dividend_copy )
      {
        v11 = __CFADD__(v5, (uint32_t)dividend_copy);
        dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)(v5 + dividend_copy) & 0xFFFFFFFFu);
        if ( v11 || v23 <= (unsigned int)dividend_copy )
        {
          --v22;
        }
        else
        {
          v22 -= 2;
          dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)(dividend_copy + v5) & 0xFFFFFFFFu);
        }
      }
      v16 = dividend_copy - v23;
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v22 | (v20 << 16)) & 0xFFFFFFFFu);
    }
    else
    {
      v6 = __clz(a2);
      if ( v6 )
      {
        v5 <<= v6;
        v4 = ((unsigned int)a1 >> (32 - v6)) | (HIDWORD(a1) << v6);
        dividend_copy = (dividend_copy & ~0xFFFFFFFFull) | ((uint32_t)((uint32_t)a1 << v6) & 0xFFFFFFFFu);
      }
      v7 = HIWORD(v5);
      v8 = v4 / HIWORD(v5);
      v9 = WORD1(dividend_copy) | ((v4 % HIWORD(v5)) << 16);
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
      v14 = (uint16_t)dividend_copy | ((v12 % v7) << 16);
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


// int_abs @ 0x1435c8
/* luna: Returns the absolute value of an integer. */
int int_abs(int result) {
  if ( result < 0 )
    return -result;
  return result;
}



// memcmp @ 0x1435d0
/* luna: Compares two byte sequences lexicographically, using aligned 32-bit loads when possible, and returns the first differing unsigned-byte difference. */
int memcmp(unsigned int a1, unsigned int a2, unsigned int a3) {
  volatile int *lhs_word_ptr; // r4
  volatile int *rhs_word_ptr; // r3
  int v5; // r5
  int v6; // t1
  int v7; // t1
  unsigned int v8; // r6
  volatile char *rhs_byte_ptr; // r1
  volatile char *lhs_byte_ptr; // r4
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
    lhs_word_ptr = (volatile int *)a1;
    rhs_word_ptr = (volatile int *)a2;
    if ( !((a1 | a2) << 30) )
    {
      while ( 1 )
      {
        a2 = (unsigned int)rhs_word_ptr;
        a1 = (unsigned int)lhs_word_ptr;
        v6 = *rhs_word_ptr++;
        v5 = v6;
        v7 = *lhs_word_ptr++;
        if ( v7 != v5 )
          break;
        a3 -= 4;
        a1 = (unsigned int)lhs_word_ptr;
        a2 = (unsigned int)rhs_word_ptr;
        if ( a3 <= 3 )
          goto LABEL_5;
      }
    }
    v8 = a3 - 1;
  }
  rhs_byte_ptr = (volatile char *)(a2 - 1);
  lhs_byte_ptr = (volatile char *)(a1 - 1);
  do
  {
    v12 = (uint8_t)*++lhs_byte_ptr;
    v11 = v12;
    v14 = (uint8_t)*++rhs_byte_ptr;
    v13 = v14;
    if ( v11 != v14 )
      return v11 - v13;
  }
  while ( a1 + v8 - (uint32_t)lhs_byte_ptr );
  return 0;
}



// memcpy @ 0x143630
/* libmatch: 308 bytes identical to memcpy (libc.a:libc_a-memcpy.o); the library routine is linked */


// memmove @ 0x143764
/* luna: Copies len bytes from src to dest while preserving correct behavior when the ranges overlap. */
unsigned int memmove(unsigned int result, unsigned int a2, unsigned int a3) {
  volatile uint8_t *v3; // r3
  unsigned int v4; // r2
  char v5; // t1
  unsigned int v6; // r3
  unsigned int v7; // r4
  volatile uint8_t *v8; // r4
  unsigned int v9; // r3
  char v10; // t1
  volatile uint8_t *v11; // r4
  unsigned int v12; // r5
  unsigned int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r5
  unsigned int v16; // r12
  unsigned int v17; // r4
  volatile int *v18; // r6
  int v19; // t1

  if ( result <= a2 || (v3 = (volatile uint8_t *)(a2 + a3), a2 + a3 <= result) )
  {
    if ( a3 > 0xF )
    {
      if ( (result | a2) << 30 )
      {
        v7 = a3 - 1;
        v6 = result;
LABEL_10:
        v8 = (volatile uint8_t *)(v7 + 1 + a2);
        v9 = v6 - 1;
        do
        {
          v10 = *(volatile uint8_t *)a2++;
          *(volatile uint8_t *)++v9 = v10;
        }
        while ( (volatile uint8_t *)a2 != v8 );
        return result;
      }
      v11 = (volatile uint8_t *)(a2 + 16);
      v12 = result + 16;
      do
      {
        *(volatile uint32_t *)(v12 - 16) = *((volatile uint32_t *)v11 - 4);
        *(volatile uint32_t *)(v12 - 12) = *((volatile uint32_t *)v11 - 3);
        *(volatile uint32_t *)(v12 - 8) = *((volatile uint32_t *)v11 - 2);
        *(volatile uint32_t *)(v12 - 4) = *((volatile uint32_t *)v11 - 1);
        v11 += 16;
        v12 += 16;
      }
      while ( v11 != (volatile uint8_t *)(a2 + 32 + ((a3 - 16) & 0xFFFFFFF0)) );
      v13 = ((a3 - 16) >> 4) + 1;
      a2 += 16 * v13;
      v6 = result + 16 * v13;
      if ( (a3 & 0xC) != 0 )
      {
        v14 = (a3 & 0xF) - 4;
        v15 = v14 >> 2;
        v16 = (v14 & 0xFFFFFFFC) + v6;
        v17 = v6 - 4;
        v18 = (volatile int *)a2;
        do
        {
          v19 = *v18++;
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
      v5 = *--v3;
      *(volatile uint8_t *)--v4 = v5;
    }
    while ( (volatile uint8_t *)a2 != v3 );
  }
  return result;
}



// hash32 @ 0x14383c
/* luna: Advances the global 64-bit linear-congruential PRNG state and returns its upper 31 bits. */
int hash32() {
  uint64_t next_rng_state; // kr00_8

  next_rng_state = *(volatile uint64_t *)(*(volatile uint32_t *)off_14386C + 168) * __PAIR64__(dword_143870, dword_143874) + 1;
  *(volatile uint64_t *)(*(volatile uint32_t *)off_14386C + 168) = next_rng_state;
  return HIDWORD(next_rng_state) & 0x7FFFFFFF;
}



// strchr @ 0x143878
/* luna: Returns a pointer to the first occurrence of the byte in the NUL-terminated string, including the terminator when searching for '\0', or NULL if it is */
volatile uint8_t * strchr(volatile uint8_t *result, uint8_t a2) {
  volatile uint8_t *scan_ptr; // r3
  int v3; // r6
  int v4; // t1
  int v5; // r3
  int v6; // t1
  int v7; // r2
  int v8; // t1
  int v9; // t1

  scan_ptr = result;
  if ( a2 )
  {
    if ( (uint32_t)result << 30 )
    {
      while ( 1 )
      {
        result = scan_ptr;
        v8 = *scan_ptr++;
        v7 = v8;
        if ( !v8 )
          return 0;
        if ( v7 == a2 )
          return result;
        result = scan_ptr;
        if ( !((uint32_t)scan_ptr << 30) )
          goto LABEL_3;
      }
    }
    else
    {
LABEL_3:
      v3 = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
      if ( ((((v3 ^ *(volatile uint32_t *)result) - 16843009) & ~(v3 ^ *(volatile uint32_t *)result)
           | (*(volatile uint32_t *)result - 16843009) & ~*(volatile uint32_t *)result)
          & 0x80808080) == 0 )
      {
        do
        {
          v4 = *((volatile uint32_t *)result + 1);
          result += 4;
        }
        while ( (((v4 - 16843009) & ~v4 | ((v4 ^ v3) - 16843009) & ~(v4 ^ v3)) & 0x80808080) == 0 );
      }
      v5 = *result;
      if ( *result )
      {
        while ( a2 != v5 )
        {
          v6 = *++result;
          v5 = v6;
          if ( !v6 )
            return (volatile uint8_t *)v5;
        }
      }
      else
      {
        return (volatile uint8_t *)v5;
      }
    }
  }
  else if ( (uint32_t)result << 30 )
  {
    while ( 1 )
    {
      result = scan_ptr++;
      if ( !*result )
        break;
      result = scan_ptr;
      if ( !((uint32_t)scan_ptr << 30) )
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



// strcmp @ 0x143968
/* luna: Compares two NUL-terminated byte strings lexicographically and returns the difference between the first differing bytes. */
int strcmp(unsigned int a1, volatile unsigned int *a2) {
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;
uint32_t _R5;

  int v3; // r2
  int v4; // r3
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

  v3 = *(volatile uint8_t *)a1;
  v4 = *(volatile uint8_t *)a2;
  _ZF = v3 == 1;
  if ( *(volatile uint8_t *)a1 )
    _ZF = v3 == v4;
  if ( !_ZF )
    return v3 - v4;
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


// strcpy @ 0x143c3c
/* libmatch: 186 bytes identical to strcpy (libc.a:libc_a-strcpy.o); the library routine is linked */


// strlen @ 0x143d00
unsigned int strlen(unsigned int a1) {
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;

  volatile uint64_t *v1; // r1
  int v3; // r4
  int v5; // r0
  int v15; // r5

  __pld((void *)a1);
  v1 = (volatile uint64_t *)(a1 & 0xFFFFFFF8);
  _R12 = -1;
  v3 = a1 & 7;
  __pld((void *)((a1 & 0xFFFFFFF8) + 32));
  if ( (a1 & 7) != 0 )
  {
    _R2 = *v1;
    v5 = -v3;
    __pld(v1 + 8);
    v15 = -1 << (8 * (v3 & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~v15) & 0xFFFFFFFFULL) << 0);
    if ( (v3 & 4) != 0 )
    {
      _R2 = _R2 | (((uint64_t)(~v15)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    _R4 = 0;
    goto LABEL_4;
  }
  _R4 = 0;
  v5 = -8;
  do
  {
    _R2 = *v1;
    __pld(v1 + 8);
    v5 += 8;
LABEL_4:
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[1];
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[2];
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

    if ( HIDWORD(_R2) )
      break;
    _R2 = v1[3];
    v1 += 4;
    (void)0;

    v5 += 8;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | ((uint32_t)_R4 | __zmask32((uint32_t)_R2));
_R2 = (_R2 & 0xFFFFFFFFULL) | (((uint64_t)((uint32_t)_R2 | __zmask32((uint32_t)(_R2 >> 32)))) << 32);

  }
  while ( !HIDWORD(_R2) );
  if ( !(uint32_t)_R2 )
  {
    v5 += 4;
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(HIDWORD(_R2)) & 0xFFFFFFFFULL) << 0);
  }
  return v5 + (__clz(bswap32(_R2)) >> 3);
}


// strncasecmp @ 0x143ddc
int strncasecmp(volatile uint8_t *a1, volatile uint8_t *a2, int a3) {
  volatile uint8_t *v3; // r5
  volatile uint8_t *v4; // r7
  int v5; // r3
  int v6; // r3
  int v7; // t1
  int v8; // r2
  int v9; // t1
  int v10; // r4
  int result; // r0
  int v12; // r2

  if ( a3 )
  {
    v3 = a1;
    v4 = &a1[a3];
    while ( 1 )
    {
      v7 = *v3++;
      v6 = v7;
      v9 = *a2++;
      v8 = v9;
      v10 = *(volatile uint8_t *)(dword_143E2C + v9) & 3;
      if ( (*(volatile uint8_t *)(dword_143E2C + v6) & 3) == 1 )
        v6 += 32;
      result = v8;
      if ( v10 == 1 )
      {
        v12 = v8 + 32;
        result = v6 - v12;
        if ( v6 != v12 )
          return result;
      }
      else
      {
        v5 = v6 - v8;
        if ( v5 )
          return v5;
        if ( !v8 )
          return result;
      }
      if ( v3 == v4 )
        return 0;
    }
  }
  return 0;
}



// empty_stub_0 @ 0x14dee8
/* luna: An empty stub that performs no operation. */
void empty_stub_0() {
  ;
}



// empty_stub_1 @ 0x14def4
void empty_stub_1() {
  ;
}



