// check_kernel_state @ 0x11e724
/* luna: Appends an entry to the tail of an intrusive kernel list, updating the list first/last pointers and initializing the entry's next pointer. */
int check_kernel_state(int result, volatile uint32_t *a2) {
  int list; // r5

  list = result;
  if ( **(volatile int16_t **)off_11E760 < 0 && !a2 )
    result = flash_ctrl_init((int)aListHdrNull, (int)aCoListPushBack, 72);
  if ( *(volatile uint32_t *)list )
    **(volatile uint32_t **)(list + 4) = (int)(uintptr_t)(a2);
  else
    *(volatile uint32_t *)list = (int)(uintptr_t)(a2);
  *(volatile uint32_t *)(list + 4) = (int)(uintptr_t)(a2);
  *a2 = 0;
  return result;
}


// check_kernel_state_alt @ 0x11e76c
/* luna: Pushes a node onto the front of a RivieraWaves co_list intrusive linked list header, updating node and list front/back links. */
int check_kernel_state_alt(int result, volatile uint32_t *a2) {
  volatile uint32_t *list_hdr; // r5

  list_hdr = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_11E7A0 < 0 && !a2 )
    result = flash_ctrl_init((int)aListHdrNull, (int)aCoListPushFron, 95);
  if ( *list_hdr )
  {
    *a2 = *list_hdr;
  }
  else
  {
    list_hdr[1] = (int)(uintptr_t)(a2);
    *a2 = 0;
  }
  *list_hdr = (int)(uintptr_t)(a2);
  return result;
}


// list_pop_front @ 0x11e7ac
/* luna: Removes and returns the first node from a head/tail intrusive linked list, updating the head to the next node and clearing the tail if the list become */
volatile uint32_t * list_pop_front(int a1) {
  volatile uint32_t *old_head; // r3
  volatile uint32_t *tail; // r2

  old_head = *(volatile uint32_t **)a1;
  if ( *(volatile uint32_t *)a1 )
  {
    tail = *(volatile uint32_t **)(a1 + 4);
    *(volatile uint32_t *)a1 = *old_head;
    if ( tail == old_head )
      *(volatile uint32_t *)(a1 + 4) = 0;
  }
  return old_head;
}



// check_kernel_state_alt2 @ 0x11e7c4
int check_kernel_state_alt2(int result, volatile uint32_t *a2) {
  int v2; // r5
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r3

  v2 = result;
  if ( **(volatile int16_t **)off_11E820 < 0 && !result )
    result = flash_ctrl_init(dword_11E828, dword_11E824, 132);
  v4 = *(volatile uint32_t **)v2;
  if ( *(volatile uint32_t *)v2 )
  {
    if ( v4 == a2 )
    {
      v6 = *(volatile uint32_t **)(v2 + 4);
      *(volatile uint32_t *)v2 = *a2;
      if ( v6 == a2 )
        *(volatile uint32_t *)(v2 + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        v5 = v4;
        v4 = (volatile uint32_t *)*v4;
        if ( !v4 )
          break;
        if ( v4 == a2 )
        {
          if ( *(volatile uint32_t **)(v2 + 4) == a2 )
            *(volatile uint32_t *)(v2 + 4) = (int)(uintptr_t)(v5);
          *v5 = *a2;
          return result;
        }
      }
    }
  }
  return result;
}



// list_count @ 0x11e82c
int list_count(volatile uint32_t **a1) {
  volatile uint32_t *v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    v1 = (volatile uint32_t *)*v1;
    ++result;
  }
  while ( v1 );
  return result;
}



// list_foreach @ 0x11e840
int list_foreach(int result, volatile uint32_t *a2, int ( *a3)(volatile uint32_t *, volatile uint32_t *)) {
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r7
  volatile uint32_t *v7; // r8

  v3 = *(volatile uint32_t **)result;
  v4 = (volatile uint32_t *)result;
  if ( *(volatile uint32_t *)result )
  {
    v7 = 0;
    for ( result = a3(a2, v3); !result; result = a3(a2, v3) )
    {
      v7 = v3;
      if ( !*v3 )
      {
        v4[1] = (int)(uintptr_t)(a2);
        *a2 = 0;
        goto LABEL_9;
      }
      v3 = (volatile uint32_t *)*v3;
    }
    *a2 = (int)(uintptr_t)(v3);
    if ( !v7 )
      goto LABEL_7;
LABEL_9:
    *v7 = (int)(uintptr_t)(a2);
  }
  else
  {
    *(volatile uint32_t *)(result + 4) = (int)(uintptr_t)(a2);
    *a2 = 0;
LABEL_7:
    *v4 = (int)(uintptr_t)(a2);
  }
  return result;
}



// list_find @ 0x11e888
volatile uint32_t * list_find(volatile uint32_t *result, volatile uint32_t *a2, volatile uint32_t *a3) {
  volatile uint32_t **v3; // r3

  if ( !a2 )
    return (volatile uint32_t *)check_kernel_state((int)result, a3);
  v3 = (volatile uint32_t **)*result;
  if ( (volatile uint32_t *)*result == a2 )
    return (volatile uint32_t *)check_kernel_state_alt((int)result, a3);
  if ( v3 )
  {
    while ( 1 )
    {
      result = *v3;
      if ( *v3 == a2 )
        break;
      v3 = (volatile uint32_t **)*v3;
      if ( !result )
        return result;
    }
    *a3 = (int)(uintptr_t)(a2);
    *v3 = a3;
  }
  return result;
}


// crc32_update_msb @ 0x11e8b4
/* luna: Updates a 32-bit CRC32 over a byte buffer by processing each byte through a high-byte-indexed, MSB-first table and returning the new CRC. */
unsigned int crc32_update_msb(volatile uint8_t *a1, int a2, unsigned int a3) {
  volatile uint8_t *end; // r1
  int byte; // t1

  if ( !a2 )
    return a3;
  end = &a1[a2];
  do
  {
    byte = *a1++;
    a3 = *(volatile uint32_t *)(dword_11E8DC + 4 * (byte ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( end != a1 );
  return a3;
}



// crc32_block @ 0x11e8e0
int crc32_block(int a1) {
  volatile int *v1; // r5
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r2
  uint64_t v6; // r0
  uint64_t v7; // r2
  uint64_t v8; // r0
  unsigned int v9; // r0
  struct __attribute__((packed)) { uint32_t v11[32]; // [sp+0h] [bp-104h] BYREF
  char v12[132]; // [sp+80h] [bp-84h] BYREF
  } _frame;
  v1 = (volatile int *)off_11E958;
  memcpy((volatile char *)_frame.v11, (volatile char *)off_11E958, 0x80u);
  memcpy(_frame.v12, (volatile char *)v1 + 128, 0x80u);
  v3 = ((uint64_t (*)())aeabi_d2f)(a1);
  v4 = ((uint64_t (*)())aeabi_dadd)(v3, *(volatile uint64_t *)&dword_11E950);
  v5 = (v5 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_11E95C) << 32);
  v5 = (v5 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v6 = ((uint64_t (*)())aeabi_dadd)(v4, v5);
  v7 = (v7 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_11E960) << 32);
  v7 = (v7 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v8 = double_add(v6, v7);
  v9 = ((int (*)(uint64_t))double_to_float_1)(v8);
  return v9 & 0x7F800000
       | ((((int64_t)(int32_t)(v9 & 0x7FFFFF) * (int64_t)(int32_t)(_frame.v11[(v9 >> 18) & 0x1F])) >> 23) + *(volatile uint32_t *)&_frame.v12[4 * ((v9 >> 18) & 0x1F)]);
}


// float_extract_parts @ 0x11e964
unsigned int float_extract_parts(unsigned int a1) {
  unsigned int v1; // r3
  int v2; // s15
  int v3; // r0
  float v4; // s15
  unsigned int result; // r0
  float v6; // s15
  float v7; // s13
  float v8; // s14

  v1 = a1 & 0x7FFFFF;
  v2 = a1 & 0x7FFFFF;
  v3 = (uint8_t)(a1 >> 23);
  if ( (a1 & 0x7FFFFFu) >= 0x100000 )
  {
    if ( v1 >= 0x200000 )
    {
      if ( v1 < 0x300000 )
      {
        v4 = (float)((float)v2 * flt_11EA74) + flt_11EA78;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * flt_11EA84) + flt_11EA88;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = flt_11EA90;
          else
            v7 = flt_11EA8C;
          if ( v1 >= 0x700000 )
            v8 = flt_11EA98;
          else
            v8 = flt_11EA94;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_11EA7C) + flt_11EA80;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_11EA6C) + flt_11EA70;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_11EA64) + flt_11EA68;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_11EA58) + flt_11EA5C;
  }
  *(volatile float *)&result = (float)(v3 - 127) + (float)(v4 * flt_11EA60);
  return result;
}


// float_to_double @ 0x11eaa0
unsigned int float_to_double(unsigned int a1) {
  unsigned int v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0

  v1 = float_extract_parts(a1);
  v2 = ((uint64_t (*)())aeabi_d2f)(v1);
  v3 = ((uint64_t (*)())aeabi_dadd)(v2, *(volatile uint64_t *)&dword_11EAC0);
  return ((int (*)(uint64_t))aeabi_dmul)(v3);
}


// branch_to_127228 @ 0x11eac8
int branch_to_127228(int a1) {
  return float_to_i24(a1);
}


// hash_const_init @ 0x11eacc
float hash_const_init(float a1) {
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r2
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r1
  int v23; // r2
  int v24; // r3
  float v25; // s15
  uint32_t v27[16]; // [sp+0h] [bp-80h]
  uint32_t v28[16]; // [sp+40h] [bp-40h]

  v1 = *(volatile uint32_t *)(dword_11EB44 + 260);
  v2 = *(volatile uint32_t *)(dword_11EB44 + 264);
  v3 = *(volatile uint32_t *)(dword_11EB44 + 268);
  v27[0] = *(volatile uint32_t *)(dword_11EB44 + 256);
  v27[1] = v1;
  v27[2] = v2;
  v27[3] = v3;
  v4 = *(volatile uint32_t *)(dword_11EB44 + 276);
  v5 = *(volatile uint32_t *)(dword_11EB44 + 280);
  v6 = *(volatile uint32_t *)(dword_11EB44 + 284);
  v27[4] = *(volatile uint32_t *)(dword_11EB44 + 272);
  v27[5] = v4;
  v27[6] = v5;
  v27[7] = v6;
  v7 = *(volatile uint32_t *)(dword_11EB44 + 292);
  v8 = *(volatile uint32_t *)(dword_11EB44 + 296);
  v9 = *(volatile uint32_t *)(dword_11EB44 + 300);
  v27[8] = *(volatile uint32_t *)(dword_11EB44 + 288);
  v27[9] = v7;
  v27[10] = v8;
  v27[11] = v9;
  v10 = *(volatile uint32_t *)(dword_11EB44 + 308);
  v11 = *(volatile uint32_t *)(dword_11EB44 + 312);
  v12 = *(volatile uint32_t *)(dword_11EB44 + 316);
  v27[12] = *(volatile uint32_t *)(dword_11EB44 + 304);
  v27[13] = v10;
  v27[14] = v11;
  v27[15] = v12;
  v13 = *(volatile uint32_t *)(dword_11EB44 + 324);
  v14 = *(volatile uint32_t *)(dword_11EB44 + 328);
  v15 = *(volatile uint32_t *)(dword_11EB44 + 332);
  v28[0] = *(volatile uint32_t *)(dword_11EB44 + 320);
  v28[1] = v13;
  v28[2] = v14;
  v28[3] = v15;
  v16 = *(volatile uint32_t *)(dword_11EB44 + 340);
  v17 = *(volatile uint32_t *)(dword_11EB44 + 344);
  v18 = *(volatile uint32_t *)(dword_11EB44 + 348);
  v28[4] = *(volatile uint32_t *)(dword_11EB44 + 336);
  v28[5] = v16;
  v28[6] = v17;
  v28[7] = v18;
  v19 = *(volatile uint32_t *)(dword_11EB44 + 356);
  v20 = *(volatile uint32_t *)(dword_11EB44 + 360);
  v21 = *(volatile uint32_t *)(dword_11EB44 + 364);
  v28[8] = *(volatile uint32_t *)(dword_11EB44 + 352);
  v28[9] = v19;
  v28[10] = v20;
  v28[11] = v21;
  v22 = *(volatile uint32_t *)(dword_11EB44 + 372);
  v23 = *(volatile uint32_t *)(dword_11EB44 + 376);
  v24 = *(volatile uint32_t *)(dword_11EB44 + 380);
  v28[12] = *(volatile uint32_t *)(dword_11EB44 + 368);
  v28[13] = v22;
  v28[14] = v23;
  v28[15] = v24;
  v25 = COERCE_FLOAT(v28[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF] + (COERCE_UNSIGNED_INT(a1) >> 1)) * *(volatile float *)&v27[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}



// crc32_update_lsb @ 0x11eb48
/* luna: Update a reflected CRC-32 accumulator by processing each byte of a buffer through a 256-entry table. */
unsigned int crc32_update_lsb(volatile uint8_t *a1, int a2, unsigned int a3) {
  volatile uint8_t *end; // r4
  int byte; // t1

  if ( !a2 )
    return a3;
  end = &a1[a2];
  do
  {
    byte = *a1++;
    a3 = *(volatile uint32_t *)(dword_11EB70 + 4 * ((uint8_t)a3 ^ byte)) ^ (a3 >> 8);
  }
  while ( a1 != end );
  return a3;
}



// memchr @ 0x11eb74
volatile uint8_t * memchr(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  volatile uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 3 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 1 )
      return 0;
  }
  return result;
}



// rf_parse_cal_cmd @ 0x11ebb4
__attribute__((target("general-regs-only"))) unsigned int rf_parse_cal_cmd(volatile char *a1, int a2, unsigned int a3, volatile uint8_t *a4, volatile unsigned int *a5) {
  int v7; // r2
  volatile uint8_t *v8; // r5
  volatile char *v9; // r7
  unsigned int v10; // r4
  int v11; // r6
  volatile char *v12; // r9
  int v13; // r10
  int v14; // r1
  int v15; // t1
  int v17; // t1
  unsigned int v18; // t1
  int v19; // t1
  unsigned int v20; // r1
  int v21; // r1
  int v22; // t1
  volatile char *v23; // r2
  int v24; // r0
  int v25; // r3
  volatile char *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // t1
  unsigned int v29; // r10
  volatile uint8_t *v30; // lr
  char v31; // r0
  int v32; // cc
  volatile uint8_t *v33; // r2
  int v34; // r0
  char v35; // r0
  volatile char *v36; // t1
  volatile uint8_t *v37; // t1
  int v38; // r2
  unsigned int v39; // lr
  int v40; // r3
  volatile uint8_t *v41; // r12
  char v42; // r1
  char v43; // r3
  int v44; // r1
  int v45; // r2
  volatile uint8_t *v46; // r10
  volatile char *v47; // r2
  int v48; // zf
  int v49; // t1
  char v50; // r9
  volatile uint8_t *v51; // t1
  unsigned int v52; // lr
  int v53; // r3
  volatile uint8_t *v54; // r12
  char v55; // r2
  volatile uint8_t *v56; // r1
  volatile char *v57; // r3
  int v58; // t1
  char v59; // r2
  unsigned int v60; // r1
  int v61; // r3
  unsigned int v62; // t1
  int v63; // r2
  char v64; // r3
  int v65; // r3
  volatile char *v66; // r1
  int v67; // r0
  int v68; // r12
  int v69; // t1
  int v71; // t1
  unsigned int v72; // r12
  int v73; // r3
  unsigned int v74; // lr
  int v75; // r3
  struct __attribute__((packed)) { int v76; // [sp+0h] [bp-54h]
  int v77; // [sp+4h] [bp-50h]
  unsigned int v78; // [sp+8h] [bp-4Ch]
  int v79; // [sp+Ch] [bp-48h]
  char v80_scratch[68]; // [sp+10h] [bp-44h] BYREF — merged scratch: the original uses
  // sp+0x10..sp+0x53 as ONE raw stack region (digit generation grows backward from
  // sp+0x50, %A/%M grow forward from sp+0x10/0x13); merged into one object so the
  // cross-field pointer arithmetic stays in bounds under any correct compilation.
  // offsets: v80=[0] v81=[1] pad=[2] v82=[3] v83 anchor=[64]
  } _frame;
  v8 = a4 + 1;
  v7 = (uint8_t)*a4;
  _frame.v79 = a2;
  v9 = a1;
  if ( !a1 )
  {
    v10 = (uint8_t)*a4;
    if ( *a4 )
    {
      _frame.v79 = 0;
LABEL_3:
      v10 = 0;
      _frame.v76 = 0;
      _frame.v77 = 0;
      v11 = _frame.v79;
      _frame.v78 = 0;
      v12 = nullptr;
      v13 = 0;
      while ( 2 )
      {
        switch ( v7 )
        {
          case ' ':
          case '+':
          case '-':
            v14 = 5;
            goto LABEL_7;
          case '%':
            v61 = 1;
            goto LABEL_124;
          case '*':
            v61 = 4;
LABEL_124:
            v13 = *(volatile uint8_t *)(dword_11F48C + 8 * v13 + v61);
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_44:
                if ( **(volatile uint16_t **)dword_11EF2C < 0 )
                  flash_ctrl_init(dword_11F494, dword_11F490, 283);
                v13 = 2;
                goto LABEL_12;
              case 3:
                goto LABEL_29;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
          case '.':
            v14 = 2;
            goto LABEL_7;
          case '0':
            v13 = *(volatile uint8_t *)(dword_11EF28 + 8 * v13 + 3);
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_43:
                _frame.v76 |= 0x40u;
                v13 = 2;
                goto LABEL_12;
              case 3:
LABEL_29:
                if ( v7 != 42 )
                  goto LABEL_30;
                v18 = *a5++;
                _frame.v78 = v18;
                v13 = 3;
                break;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
            goto LABEL_12;
          case 'A':
          case 'M':
          case 'X':
          case 'a':
          case 'b':
          case 'c':
          case 'd':
          case 'i':
          case 'm':
          case 'p':
          case 's':
          case 'u':
          case 'x':
            v14 = 7;
            goto LABEL_7;
          case 'h':
          case 'l':
            v14 = 6;
            goto LABEL_7;
          default:
            if ( (unsigned int)(v7 - 49) > 8 )
            {
              v14 = 0;
LABEL_7:
              v13 = *(volatile uint8_t *)(dword_11EF28 + 8 * v13 + v14);
              switch ( v13 )
              {
                case 0:
                  goto LABEL_17;
                case 1:
                  goto LABEL_11;
                case 2:
                  goto LABEL_10;
                case 3:
                  goto LABEL_29;
                case 4:
                  goto LABEL_16;
                case 5:
                  goto LABEL_26;
                case 6:
                  goto LABEL_21;
                case 7:
                  goto LABEL_9;
                default:
                  goto LABEL_161;
              }
            }
            v13 = *(volatile uint8_t *)(dword_11EF28 + 8 * v13 + 4);
            switch ( v13 )
            {
              case 0:
LABEL_17:
                if ( v11 )
                {
                  if ( a3 <= v10 )
                  {
                    *v9++ = v7;
                    --v11;
                  }
                }
                ++v10;
                v13 = 0;
                goto LABEL_12;
              case 1:
LABEL_11:
                _frame.v76 = 0;
                _frame.v78 = 0;
                _frame.v77 = -1;
                v13 = 1;
                goto LABEL_12;
              case 2:
LABEL_10:
                switch ( v7 )
                {
                  case ' ':
                    _frame.v76 |= 0x10u;
                    v13 = 2;
                    break;
                  case '+':
                    _frame.v76 |= 8u;
                    v13 = 2;
                    break;
                  case '-':
                    _frame.v76 |= 0x20u;
                    v13 = 2;
                    break;
                  case '0':
                    goto LABEL_43;
                  default:
                    goto LABEL_44;
                }
                goto LABEL_12;
              case 3:
LABEL_30:
                _frame.v78 = v7 - 48 + 10 * _frame.v78;
                v13 = 3;
                goto LABEL_12;
              case 4:
LABEL_16:
                _frame.v77 = 0;
                v13 = 4;
                goto LABEL_12;
              case 5:
LABEL_26:
                if ( v7 == 42 )
                {
                  v17 = *a5++;
                  _frame.v77 = v17;
                }
                else
                {
                  _frame.v77 = v7 - 48 + 10 * _frame.v77;
                }
                v13 = 5;
                goto LABEL_12;
              case 6:
LABEL_21:
                if ( v7 == 104 )
                {
                  _frame.v76 |= 1u;
                  v13 = 6;
                }
                else if ( v7 == 108 )
                {
                  _frame.v76 |= 2u;
                  v13 = 6;
                }
                else
                {
                  if ( **(volatile uint16_t **)dword_11EF2C < 0 )
                    flash_ctrl_init(dword_11F494, dword_11F490, 334);
                  v13 = 6;
                }
                goto LABEL_12;
              case 7:
                goto LABEL_9;
              default:
LABEL_161:
                if ( **(volatile uint16_t **)dword_11F498 < 0 )
                  flash_ctrl_init(dword_11F494, dword_11F490, 594);
                goto LABEL_12;
            }
        }
LABEL_9:
        switch ( v7 )
        {
          case 'A':
          case 'a':
            v37 = (volatile uint8_t *)*a5++;
            v38 = _frame.v78;
            v39 = dword_11F4A0;
            v41 = v37 + 1;
            v40 = *v37;
            if ( _frame.v78 )
            {
              v42 = *(volatile uint8_t *)(dword_11F4A0 + (v40 >> 4));
              v43 = *(volatile uint8_t *)(dword_11F4A0 + (v40 & 0xF));
              _frame.v80_scratch[0] = v42;
              if ( _frame.v78 >= 0x15 )
                v38 = 21;
              v44 = 3 * v38;
              v45 = v38 - 1;
              _frame.v80_scratch[1] = v43;
              v25 = v44 - 1;
              v21 = 1 - v44;
              if ( !v45 )
              {
LABEL_106:
                if ( (_frame.v76 & 0x40) != 0 )
                {
                  _frame.v78 = 0;
                  v23 = (&_frame.v80_scratch[0]);
                  goto LABEL_58;
                }
                _frame.v78 = _frame.v76 & 0x40;
                v23 = (&_frame.v80_scratch[0]);
                if ( (_frame.v76 & 0x20) != 0 )
                  goto LABEL_57;
                if ( v25 )
                  goto LABEL_58;
                goto LABEL_93;
              }
            }
            else
            {
              v63 = v40 >> 4;
              v64 = *(volatile uint8_t *)(dword_11F4A0 + (v40 & 0xF));
              _frame.v80_scratch[0] = *(volatile uint8_t *)(dword_11F4A0 + v63);
              _frame.v80_scratch[1] = v64;
              v21 = -47;
              v25 = 47;
              v45 = 15;
            }
            v46 = &v41[v45];
            v47 = (&_frame.v80_scratch[3]);
            do
            {
              v48 = ((uint8_t)v41 & 3) == 0;
              v49 = *v41++;
              *v47 = *(volatile uint8_t *)(v39 + (v49 >> 4));
              v47[1] = *(volatile uint8_t *)(v39 + (v49 & 0xF));
              if ( v48 )
                v50 = 58;
              else
                v50 = 46;
              *(v47 - 1) = v50;
              v47 += 3;
            }
            while ( v46 != v41 );
            goto LABEL_106;
          case 'M':
          case 'm':
            v51 = (volatile uint8_t *)*a5++;
            v52 = dword_11F4A0;
            v54 = v51 + 6;
            v53 = *v51;
            v55 = *(volatile uint8_t *)(dword_11F4A0 + (v53 >> 4));
            _frame.v80_scratch[1] = *(volatile uint8_t *)(dword_11F4A0 + (v53 & 0xF));
            _frame.v80_scratch[0] = v55;
            v56 = v51 + 1;
            v57 = (&_frame.v80_scratch[0]);
            do
            {
              v58 = *v56++;
              v57[2] = 58;
              v59 = *(volatile uint8_t *)(v52 + (v58 & 0xF));
              v57[3] = *(volatile uint8_t *)(v52 + (v58 >> 4));
              v57[4] = v59;
              v57 += 3;
            }
            while ( v54 != v56 );
            v21 = _frame.v78 - 17;
            v23 = (&_frame.v80_scratch[0]);
            v24 = _frame.v76 & 0x40;
            v25 = 17;
            goto LABEL_55;
          case 'X':
          case 'b':
          case 'd':
          case 'p':
          case 'u':
          case 'x':
            if ( (_frame.v76 & 2) != 0 || (_frame.v76 & 1) == 0 )
            {
              v62 = *a5++;
              v20 = v62;
              switch ( v7 )
              {
                case 'X':
LABEL_152:
                  v74 = dword_11F4A0;
                  v23 = (&_frame.v80_scratch[64]);
                  do
                  {
                    v75 = v20 & 0xF;
                    v20 >>= 4;
                    *--v23 = *(volatile uint8_t *)(v74 + v75);
                    v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'b':
LABEL_149:
                  v23 = (&_frame.v80_scratch[64]);
                  do
                  {
                    *--v23 = (v20 & 1) + 48;
                    v20 >>= 1;
                    v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'd':
                  goto LABEL_76;
                case 'p':
LABEL_145:
                  _frame.v76 |= 0x40u;
                  v24 = 64;
                  _frame.v78 = 8;
                  break;
                case 'u':
                  goto LABEL_78;
                case 'x':
LABEL_155:
                  v24 = _frame.v76 & 0x40;
                  break;
                default:
LABEL_142:
                  v21 = _frame.v78;
                  v24 = _frame.v76 & 0x40;
                  v23 = (&_frame.v80_scratch[64]);
                  v25 = 0;
                  goto LABEL_55;
              }
              v72 = dword_11F4A4;
              v23 = (&_frame.v80_scratch[64]);
              do
              {
                v73 = v20 & 0xF;
                v20 >>= 4;
                *--v23 = *(volatile uint8_t *)(v72 + v73);
                v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
              }
              while ( v20 );
              v21 = _frame.v78 - v25;
              goto LABEL_55;
            }
            if ( v7 != 100 )
            {
              v19 = *a5++;
              v20 = (uint16_t)v19;
              switch ( v7 )
              {
                case 'X':
                  goto LABEL_152;
                case 'b':
                  goto LABEL_149;
                case 'p':
                  goto LABEL_145;
                case 'u':
                  goto LABEL_78;
                case 'x':
                  goto LABEL_155;
                default:
                  goto LABEL_142;
              }
            }
LABEL_143:
            v71 = *a5++;
            v20 = (int16_t)v71;
LABEL_76:
            if ( (v20 & 0x80000000) != 0 )
            {
              v20 = -v20;
              _frame.v76 |= 0x80u;
            }
LABEL_78:
            v29 = dword_11F49C;
            v25 = 0;
            v30 = (&_frame.v80_scratch[64]);
            do
            {
              v31 = v20 - 10 * ((unsigned int)((v29 * (uint64_t)v20) >> 32) >> 3) + 48;
              v32 = v20 > 9;
              v33 = v30;
              v20 = (unsigned int)((v29 * (uint64_t)v20) >> 32) >> 3;
              *--v30 = v31;
              v34 = v25++;
            }
            while ( v32 );
            if ( (_frame.v76 & 0x80) != 0 )
            {
              v25 = v34 + 2;
              v35 = 45;
            }
            else if ( (_frame.v76 & 8) != 0 )
            {
              v25 = v34 + 2;
              v35 = 43;
            }
            else
            {
              if ( (_frame.v76 & 0x10) == 0 )
              {
                v21 = _frame.v78 - v25;
                v23 = v30;
                v24 = _frame.v76 & 0x40;
                goto LABEL_55;
              }
              v25 = v34 + 2;
              v35 = 32;
            }
            *(v30 - 1) = v35;
            v23 = v33 - 2;
            v21 = _frame.v78 - v25;
            if ( (_frame.v76 & 0x40) == 0 )
              goto LABEL_56;
            goto LABEL_84;
          case 'c':
            v21 = _frame.v78 - 1;
            v22 = *a5++;
            _frame.v80_scratch[0] = v22;
            v23 = (&_frame.v80_scratch[0]);
            v24 = _frame.v76 & 0x40;
            v25 = 1;
            goto LABEL_55;
          case 'i':
            if ( (_frame.v76 & 2) == 0 && (_frame.v76 & 1) != 0 )
              goto LABEL_143;
            v28 = *a5++;
            v20 = v28;
            goto LABEL_76;
          case 's':
            v36 = (volatile char *)*a5++;
            v23 = v36;
            if ( !v36 )
              goto LABEL_95;
            v25 = (uint8_t)*v23;
            if ( !*v23 )
            {
              v24 = _frame.v76 & 0x40;
              v21 = _frame.v78;
              goto LABEL_55;
            }
            if ( !_frame.v77 )
            {
LABEL_95:
              v21 = _frame.v78;
              v24 = _frame.v76 & 0x40;
              v25 = 0;
              goto LABEL_55;
            }
            v65 = _frame.v77;
            v66 = v23;
            v67 = 1 - (uint32_t)v23;
            while ( 2 )
            {
              while ( 1 )
              {
                v68 = (int)&v66[v67];
                if ( v65 > 0 )
                  break;
                v68 = (int)&v66[v67];
                if ( !*++v66 )
                  goto LABEL_138;
              }
              v69 = (uint8_t)*++v66;
              --v65;
              if ( v69 )
              {
                if ( !v65 )
                {
                  _frame.v77 = 0;
                  v25 = v68;
                  v21 = _frame.v78 - v68;
                  v24 = _frame.v76 & 0x40;
                  goto LABEL_55;
                }
                continue;
              }
              break;
            }
LABEL_138:
            _frame.v77 = v65;
            v25 = v68;
LABEL_139:
            v21 = _frame.v78 - v25;
            v24 = _frame.v76 & 0x40;
LABEL_55:
            if ( v24 )
            {
LABEL_84:
              if ( v21 <= 0 )
                goto LABEL_92;
              v10 += v21;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v10 - v21 )
                  {
                    *v9 = 48;
                    --v11;
                    ++v9;
                  }
                }
                else if ( !--v21 )
                {
                  v21 = 0;
                  goto LABEL_92;
                }
                if ( !--v21 )
                  goto LABEL_121;
              }
            }
LABEL_56:
            if ( (_frame.v76 & 0x20) == 0 )
            {
              if ( v21 > 0 )
              {
                v60 = v21 + v10;
                while ( 1 )
                {
                  if ( v11 )
                  {
                    if ( a3 <= v10 )
                    {
                      *v9 = 32;
                      --v11;
                      ++v9;
                    }
                  }
                  else if ( v60 == ++v10 )
                  {
LABEL_120:
                    v10 = v60;
LABEL_121:
                    v21 = 0;
                    if ( !v25 )
                    {
LABEL_93:
                      v12 = v23;
LABEL_72:
                      v13 = 7;
                      goto LABEL_12;
                    }
LABEL_58:
                    v26 = v23;
                    v12 = &v23[v25];
                    while ( 1 )
                    {
                      if ( v11 )
                      {
                        if ( a3 <= (unsigned int)&v26[v10 - (uint32_t)v23] )
                        {
                          *v9 = *v26;
                          --v11;
                          ++v9;
                        }
                      }
                      else if ( ++v26 == v12 )
                      {
LABEL_64:
                        v27 = v25 + v10;
                        goto LABEL_65;
                      }
                      if ( ++v26 == v12 )
                        goto LABEL_64;
                    }
                  }
                  if ( v60 == ++v10 )
                    goto LABEL_120;
                }
              }
LABEL_92:
              if ( !v25 )
                goto LABEL_93;
              goto LABEL_58;
            }
LABEL_57:
            if ( v25 )
              goto LABEL_58;
            v27 = v10;
            v12 = v23;
LABEL_65:
            if ( v21 > 0 )
            {
              v10 = v21 + v27;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v27 )
                  {
                    *v9 = 32;
                    --v11;
                    ++v9;
                  }
                }
                else if ( ++v27 == v10 )
                {
                  goto LABEL_72;
                }
                if ( ++v27 == v10 )
                  goto LABEL_72;
              }
            }
            v10 = v27;
            v13 = 7;
LABEL_12:
            v15 = (uint8_t)*v8++;
            v7 = v15;
            if ( !v15 )
              goto LABEL_13;
            continue;
          default:
            v23 = v12;
            goto LABEL_95;
        }
      }
    }
    return v10;
  }
  if ( *a4 )
    goto LABEL_3;
  v11 = a2;
  v10 = 0;
LABEL_13:
  if ( v11 )
  {
    *v9 = 0;
    return v10;
  }
  if ( !_frame.v79 )
    return v10;
  *(v9 - 1) = 0;
  return v10;
}


// set_global_ptr @ 0x11f4a8
int set_global_ptr(int result) {
  *(volatile uint32_t *)off_11F4B0 = result;
  return result;
}



// set_global_variable @ 0x11f4b4
int set_global_variable(int result) {
  *((volatile uint32_t *)off_11F4BC + 1) = result;
  return result;
}



// get_event_flags @ 0x11f4c0
/* luna: Returns the current value of the global 32-bit event flag mask. */
int get_event_flags() {
  return *(volatile uint32_t *)off_11F4C8;
}



// get_event_handler @ 0x11f4cc
int get_event_handler() {
  return *((volatile uint32_t *)off_11F4D4 + 1);
}



// test_event_flag @ 0x11f4d8
BOOL test_event_flag(unsigned int a1, unsigned int a2) {
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(volatile uint32_t *)off_11F500 >> a1) & 1;
  if ( result )
    return *((volatile uint32_t *)off_11F500 + 1) >= a2;
  return result;
}



// dispatch_event_handler_1 @ 0x11f504
int dispatch_event_handler_1(const volatile char *fmt, ...) {
  volatile int *v1; // r6
  const volatile char *v2; // r4
  volatile int16_t **v3; // r8
  unsigned int v4; // r5
  unsigned int v5; // t1
  char v6; // r2
  const volatile char *varg_r0; // [sp+28h] [bp+20h]
  va_list varg_r1; // [sp+2Ch] [bp+24h] BYREF

  va_start(varg_r1, fmt);
  varg_r0 = fmt;
  v1 = (void *)(uintptr_t)(off_11F584);
if ( ((volatile uint32_t *)(uintptr_t)off_11F584)[1] ) { v2 = fmt;
    v3 = (volatile int16_t **)off_11F588;
    do
    {
      fmt = v2;
      v5 = *(volatile uint8_t *)v2++;
      v4 = v5;
      v6 = v5 + 0x80;
      if ( (v5 & 0x80) == 0 )
        break;
      if ( v4 > 0x89 )
      {
        if ( **v3 < 0 && (uint8_t)(v4 + 102) > 5u )
          fmt = (const volatile char *)flash_ctrl_init((int)aDbgSevMinPrefi, (int)aDbgTestPrint, 812);
        if ( v1[1] <= v4 - 154 )
          return (int)fmt;
      }
      else if ( (((unsigned int)~*v1 >> v6) & 1) != 0 )
      {
        return (int)fmt;
      }
      fmt = v2;
    }
    while ( varg_r0 + 2 != v2 );
    return hci_cmd_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
  }
  return (int)fmt;
}


// handle_ipc_request @ 0x11f594
int handle_ipc_request(int result, int a2, int a3, int a4) {
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  volatile uint16_t *v7; // r6
  unsigned int v8; // r11
  int v9; // r1
  const volatile char *v10; // r0
  int v11; // r10
  volatile uint8_t *v12; // r11
  int v13; // r4
  unsigned int v14; // r8
  unsigned int v16; // r8
  int v17; // r0
  unsigned int v18; // r8
  unsigned int v19; // r6
  unsigned int v20; // [sp+Ch] [bp-10h]
  int v22; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v20 = a2 * a3;
  v5 = -a3 & result;
  while ( 1 )
  {
    dispatch_event_handler_1("%08x:", v5);
    v6 = v20;
    if ( v20 >= 0x10 )
      v6 = 16;
    if ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v20 )
        return (int)uart_tx_string((void *)(uintptr_t)(off_11F734));
      v18 = 0;
      while ( 1 )
      {
        v19 = call_indirect_table();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v18 += 4;
          dispatch_event_handler_1(" %04X %04X", (uint16_t)v19, HIWORD(v19));
          v5 += 4;
          if ( v6 <= v18 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          dispatch_event_handler_1(" %02X %02X %02X %02X", (uint8_t)v19, BYTE1(v19), BYTE2(v19), HIBYTE(v19));
LABEL_36:
          v18 += 4;
          v5 += 4;
          if ( v6 <= v18 )
            goto LABEL_40;
        }
      }
      dispatch_event_handler_1(" %08X", v19);
      goto LABEL_36;
    }
    if ( v20 )
      break;
    if ( a4 )
    {
      v7 = (volatile uint16_t *)v5;
      goto LABEL_20;
    }
LABEL_31:
    result = (int)uart_tx_string((void *)(uintptr_t)(off_11F734));
    v20 -= v6;
    if ( !v20 )
      return result;
  }
  v7 = (volatile uint16_t *)v5;
  v8 = 0;
  do
  {
    while ( 1 )
    {
      v10 = a02x;
      if ( v4 != 4 )
        break;
      v8 += 4;
      dispatch_event_handler_1(" %08X", *(volatile uint32_t *)v7);
      v7 += 2;
      if ( v6 <= v8 )
        goto LABEL_18;
    }
    if ( v4 == 2 )
      v9 = *v7;
    else
      v9 = *(volatile uint8_t *)v7;
    if ( v4 == 2 )
      v10 = a04x;
    v8 += v4;
    dispatch_event_handler_1(v10, v9);
    v7 = (volatile uint16_t *)((volatile char *)v7 + v4);
  }
  while ( v6 > v8 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v20 > 0xF )
  {
    uart_tx_string(asc_12DEC8);
    goto LABEL_26;
  }
LABEL_20:
  v11 = v4 - 1;
  v22 = v4;
  v12 = (void *)(uintptr_t)(off_11F748);
  v13 = 0;
  v14 = 16 - v6;
  do
  {
    while ( (v11 & v13++) != 0 )
    {
      uart_tx_string(v12);
      if ( v14 == v13 )
        goto LABEL_25;
    }
    uart_tx_byte(32);
    uart_tx_string(v12);
  }
  while ( v14 != v13 );
LABEL_25:
  v4 = v22;
  uart_tx_string(asc_12DEC8);
  if ( v20 )
  {
LABEL_26:
    v16 = 0;
    do
    {
      v17 = *(volatile uint8_t *)(v5 + v16);
      if ( (unsigned int)(v17 - 31) > 0x5F )
        v17 = 46;
      ++v16;
      uart_tx_byte(v17);
    }
    while ( v6 > v16 );
LABEL_30:
    v5 = (unsigned int)v7;
    goto LABEL_31;
  }
  return (int)uart_tx_string((void *)(uintptr_t)(off_11F734));
}


// check_interrupt_flag @ 0x11f74c
int check_interrupt_flag(int a1, const volatile char *fmt, ...) {
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, fmt);
  if ( ((uint16_t)a1 & **(volatile uint16_t **)off_11F770) != 0 )
    return hci_cmd_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r2)));
  return a1;
}


// enable_radio @ 0x11f774
int enable_radio() {
  dispatch_event_handler_1(aUsbOff);
  ke_int_lock((int)(uintptr_t)((volatile char *)0x42F), 1);
  *((volatile uint32_t *)off_11F798 + 20) &= ~2u;
  return 0;
}


