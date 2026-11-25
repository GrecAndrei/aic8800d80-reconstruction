// strchr @ 0x12841c
/* luna: Searches a NUL-terminated byte string for the first occurrence of a specified byte, using an aligned word-at-a-time scan when the pointer is 4-byte al */
volatile uint8_t * strchr(volatile uint8_t *result, uint8_t a2) {
  volatile uint8_t *scan_ptr; // r3
  int char_word_pattern; // r6
  int word; // t1
  int byte; // r3
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
      char_word_pattern = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
      if ( ((((char_word_pattern ^ *(volatile uint32_t *)result) - 16843009) & ~(char_word_pattern ^ *(volatile uint32_t *)result)
           | (*(volatile uint32_t *)result - 16843009) & ~*(volatile uint32_t *)result)
          & 0x80808080) == 0 )
      {
        do
        {
          word = *((volatile uint32_t *)result + 1);
          result += 4;
        }
        while ( (((word - 16843009) & ~word | ((word ^ char_word_pattern) - 16843009) & ~(word ^ char_word_pattern)) & 0x80808080) == 0 );
      }
      byte = *result;
      if ( *result )
      {
        while ( a2 != byte )
        {
          v6 = *++result;
          byte = v6;
          if ( !v6 )
            return (volatile uint8_t *)byte;
        }
      }
      else
      {
        return (volatile uint8_t *)byte;
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



// strcmp @ 0x128508
/* luna: Compares two null-terminated strings, using aligned word-at-a-time loads and zero-byte detection to return negative, zero, or positive based on the fi */
int strcmp(unsigned int a1, volatile unsigned int *a2) {
uint32_t _R12;
uint64_t _R2;
uint64_t _R3;
uint32_t _R4;
uint32_t _R5;

  int v3; // r2
  int v4; // r3
  char s1_align_bits; // r4
  volatile uint64_t *s1_block_ptr; // r0
  volatile uint64_t *s2_block_ptr; // r1
  uint64_t s1_word64; // t1
  uint64_t s2_word64; // t1
  int align_shift_mask; // r4
  uint64_t s2_word_cmp; // r6
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
    s1_align_bits = a1 & 7;
    s1_block_ptr = (volatile uint64_t *)(a1 & 0xFFFFFFF8);
    s2_block_ptr = (volatile uint64_t *)((unsigned int)a2 & 0xFFFFFFF8);
    s1_word64 = *s1_block_ptr;
    a1 = (unsigned int)(s1_block_ptr + 2);
    _R2 = s1_word64;
    _ZF = (s1_align_bits & 4) == 0;
    s2_word64 = *s2_block_ptr;
    a2 = (volatile unsigned int *)(s2_block_ptr + 2);
    align_shift_mask = -1 << (8 * (s1_align_bits & 3));
    _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(_R2 | ~align_shift_mask) & 0xFFFFFFFFULL) << 0);
    s2_word_cmp = s2_word64 | (unsigned int)~align_shift_mask;
    if ( !_ZF )
    {
      _R2 = _R2 | (((uint64_t)(~align_shift_mask)) << 32);
      _R2 = (_R2 & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
      s2_word_cmp = s2_word_cmp | (((uint64_t)(~align_shift_mask)) << 32);
      s2_word_cmp = (s2_word_cmp & 0xFFFFFFFF00000000ULL) | (((unsigned long long)(-1) & 0xFFFFFFFFULL) << 0);
    }
    while ( 1 )
    {
      (void)0;

      _R4 = _R2 ^ s2_word_cmp;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      if ( _R4 )
        break;
      (void)0;

      _R5 = HIDWORD(_R2) ^ HIDWORD(s2_word_cmp);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      if ( _R5 )
        goto LABEL_14;
      _R2 = *(volatile uint64_t *)(a1 - 8);
      s2_word_cmp = *((volatile uint64_t *)a2 - 1);
      (void)0;

      _R4 = _R2 ^ s2_word_cmp;
      _R4 = (uint32_t)_R4 | __zmask32((uint32_t)_R2);

      _R5 = HIDWORD(_R2) ^ HIDWORD(s2_word_cmp);
      _R5 = (uint32_t)_R5 | __zmask32((uint32_t)(_R2 >> 32));

      _R5 = _R5 | _R4;
      if ( _R5 )
      {
        if ( !_R4 )
        {
LABEL_14:
          v30 = __clz(bswap32(_R5)) & 0xF8;
          return (uint8_t)(HIDWORD(_R2) >> v30) - (uint8_t)(HIDWORD(s2_word_cmp) >> v30);
        }
        break;
      }
LABEL_9:
      v15 = *(volatile uint64_t *)a1;
      a1 += 16;
      _R2 = v15;
      v16 = *(volatile uint64_t *)a2;
      a2 += 4;
      s2_word_cmp = v16;
    }
    v31 = __clz(bswap32(_R4)) & 0xF8;
    return (uint8_t)((unsigned int)_R2 >> v31) - (uint8_t)((unsigned int)s2_word_cmp >> v31);
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


// strcpy @ 0x1287dc
/* libmatch: 186 bytes identical to strcpy (libc.a:libc_a-strcpy.o); the library routine is linked */


// strlen @ 0x1288c0
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


// crc32 @ 0x12899c
int crc32(volatile uint8_t *a1, volatile uint8_t *a2, int a3) {
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
      v10 = *(volatile uint8_t *)(dword_1289EC + v9) & 3;
      if ( (*(volatile uint8_t *)(dword_1289EC + v6) & 3) == 1 )
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



// bt_reg_write @ 0x12f954
int bt_reg_write() {
  int v0; // r5
  int v1; // r6
  char v2; // r7

  *(volatile uint32_t *)(v1 + 20) = v1;
  *(volatile uint8_t *)(v0 + 9) = v2;
  return 45;
}



// noop_130DF4 @ 0x130df4
/* luna: Empty no-operation stub, likely an unused callback or linker placeholder. */
void noop_130DF4() {
  ;
}



// noop_130E00 @ 0x130e00
void noop_130E00() {
  ;
}



// sub_1383DC @ 0x1383dc
int sub_1383DC(char a1) {
  int v2; // r3
  int v3; // r3
  int result; // r0
  int v5; // r1
  volatile uint32_t *v6; // r3
  int v7; // r3
  int v8; // r3
  volatile int *v9; // r2
  int v10; // r3
  int v11; // r3
  volatile uint32_t *v12; // r4
  volatile uint32_t *v13; // r2
  volatile uint32_t *v14; // r0
  int v15; // r3
  int v16; // r3
  volatile uint32_t *v17; // r4
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r0
  int v20; // r3
  int v21; // r3

  *(volatile uint32_t *)off_138564 = 53;
  __dsb(0xFu);
  __isb(0xFu);
  do
  {
    v2 = 16;
    do
      --v2;
    while ( v2 );
  }
  while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
  v3 = *(volatile uint32_t *)off_13856C;
  result = (*(volatile uint32_t *)off_13856C >> 6) & 1;
  if ( (a1 & 2) == 0 )
  {
    v5 = (a1 & 1) != 0 ? (uint8_t)v3 | 0x40 : *(volatile uint32_t *)off_13856C & 0xBF;
    if ( v5 != (uint8_t)v3 )
    {
if ( *(volatile int *)off_138570 >= 0 ) { v6 = (void *)(uintptr_t)(off_138564);
        *(volatile uint32_t *)off_138574 = dword_138578;
        *v6 = 159;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v7 = 16;
          do
            --v7;
          while ( v7 );
        }
        while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
        *(volatile uint32_t *)off_138570 = (*(volatile uint32_t *)off_13856C << 16) & 0xFF0000
                              | (uint16_t)((uint16_t)*(volatile uint32_t *)off_13856C << 8)
                              | (uint8_t)*(volatile uint32_t *)off_13856C
                              | 0x80000000;
      }
      *(volatile uint32_t *)off_138564 = 5;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v8 = 16;
        do
          --v8;
        while ( v8 );
      }
      while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
      v9 = (volatile int *)off_138574;
      v10 = *(volatile uint32_t *)off_13856C;
      *(volatile uint32_t *)off_138574 = dword_13857C;
      __dsb(0xFu);
      *++v9 = (uint8_t)v10;
      __dsb(0xFu);
      __isb(0xFu);
      *v9 = v5;
      __dsb(0xFu);
      *(volatile uint32_t *)off_138564 = 6;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v11 = 16;
        do
          --v11;
        while ( v11 );
      }
      while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
      v12 = (void *)(uintptr_t)(off_138564);
      v13 = (void *)(uintptr_t)(off_138568);
      v14 = (void *)(uintptr_t)(off_13856C);
      do
      {
        *v12 = 5;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v15 = 16;
          do
            --v15;
          while ( v15 );
        }
        while ( (*v13 & 1) != 0 );
      }
      while ( (*v14 & 2) == 0 );
      *(volatile uint32_t *)off_138564 = 1;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v16 = 16;
        do
          --v16;
        while ( v16 );
      }
      while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
      v17 = (void *)(uintptr_t)(off_138564);
      v18 = (void *)(uintptr_t)(off_138568);
      v19 = (void *)(uintptr_t)(off_13856C);
      do
      {
        *v17 = 5;
        __dsb(0xFu);
        __isb(0xFu);
        do
        {
          v20 = 16;
          do
            --v20;
          while ( v20 );
        }
        while ( (*v18 & 1) != 0 );
      }
      while ( (*v19 & 1) != 0 );
      *(volatile uint32_t *)off_138564 = 53;
      __dsb(0xFu);
      __isb(0xFu);
      do
      {
        v21 = 16;
        do
          --v21;
        while ( v21 );
      }
      while ( (*(volatile uint32_t *)off_138568 & 1) != 0 );
      return (*(volatile uint32_t *)off_13856C >> 6) & 1;
    }
  }
  return result;
}


// nullsub_8 @ 0x138562
int nullsub_8(void) {
  return 0;
}


