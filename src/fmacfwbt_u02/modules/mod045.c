// check_abort_flag @ 0x12d470
/* luna: Appends a node to the tail of a RivieraWaves co_list by updating the list first/last pointers and clearing the node's next link, with optional debug l */
int check_abort_flag(int result, volatile uint32_t *a2) {
  int list; // r5

  list = result;
  if ( **(volatile int16_t **)off_12D4AC < 0 && !a2 )
    result = mmio_irq_clear((int)aListHdrNull, (int)aCoListPushBack, 72);
  if ( *(volatile uint32_t *)list )
    **(volatile uint32_t **)(list + 4) = (int)(uintptr_t)(a2);
  else
    *(volatile uint32_t *)list = (int)(uintptr_t)(a2);
  *(volatile uint32_t *)(list + 4) = (int)(uintptr_t)(a2);
  *a2 = 0;
  return result;
}


// check_abort_flag_2 @ 0x12d4b8
int check_abort_flag_2(int result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r5

  v2 = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_12D4EC < 0 && !a2 )
    result = mmio_irq_clear(dword_12D4F4, dword_12D4F0, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = (int)(uintptr_t)(a2);
    *a2 = 0;
  }
  *v2 = (int)(uintptr_t)(a2);
  return result;
}



// list_pop_front @ 0x12d4f8
/* luna: Remove and return the first node from a singly linked list whose head and tail are stored in the provided list control block. */
volatile uint32_t * list_pop_front(int a1) {
  volatile uint32_t *popped_node; // r3
  volatile uint32_t *tail; // r2

  popped_node = *(volatile uint32_t **)a1;
  if ( *(volatile uint32_t *)a1 )
  {
    tail = *(volatile uint32_t **)(a1 + 4);
    *(volatile uint32_t *)a1 = *popped_node;
    if ( tail == popped_node )
      *(volatile uint32_t *)(a1 + 4) = 0;
  }
  return popped_node;
}



// check_abort_flag_3 @ 0x12d510
int check_abort_flag_3(int result, volatile uint32_t *a2) {
  int v2; // r5
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r3

  v2 = result;
  if ( **(volatile int16_t **)off_12D56C < 0 && !result )
    result = mmio_irq_clear(dword_12D574, dword_12D570, 132);
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



// list_contains @ 0x12d578
/* luna: Checks whether a node pointer appears in a singly linked list by following first-field next pointers, returning TRUE if found or if the queried node i */
BOOL list_contains(volatile uint32_t **a1, volatile uint32_t *a2) {
  volatile uint32_t *current; // r3

  current = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( current )
  {
    current = (volatile uint32_t *)*current;
    if ( a2 == current )
      return 1;
  }
  return a2 == 0;
}



// list_length @ 0x12d594
/* luna: Counts the nodes in a singly linked list by following the next-pointer field at offset 0 until null. */
int list_length(volatile uint32_t **a1) {
  volatile uint32_t *node; // r3
  int result; // r0

  node = *a1;
  if ( !*a1 )
    return 0;
  result = 0;
  do
  {
    node = (volatile uint32_t *)*node;
    ++result;
  }
  while ( node );
  return result;
}



// list_find @ 0x12d5a8
int list_find(int result, volatile uint32_t *a2, int ( *a3)(volatile uint32_t *, volatile uint32_t *)) {
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



// list_remove_1 @ 0x12d5f0
volatile uint32_t * list_remove_1(volatile uint32_t *result, volatile uint32_t **a2, volatile uint32_t *a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r4
  volatile uint32_t **v5; // r3

  v3 = (volatile uint32_t *)*result;
  if ( !a2 )
    return (volatile uint32_t *)check_abort_flag_2((int)result, a3);
  if ( v3 )
  {
    v4 = result;
    if ( v3 == a2 )
    {
LABEL_8:
      v5 = (volatile uint32_t **)result[1];
      result = *a2;
      *a3 = (int)(uintptr_t)(*a2);
      *a2 = a3;
      if ( v5 == a2 )
        v4[1] = (int)(uintptr_t)(a3);
    }
    else
    {
      while ( 1 )
      {
        v3 = (volatile uint32_t *)*v3;
        if ( !v3 )
          break;
        if ( a2 == v3 )
          goto LABEL_8;
      }
    }
  }
  return result;
}



// list_find_prev @ 0x12d62c
volatile uint32_t * list_find_prev(volatile uint32_t *result, volatile uint32_t *a2, volatile uint32_t *a3) {
  volatile uint32_t **v3; // r3

  if ( !a2 )
    return (volatile uint32_t *)check_abort_flag((int)result, a3);
  v3 = (volatile uint32_t **)*result;
  if ( (volatile uint32_t *)*result == a2 )
    return (volatile uint32_t *)check_abort_flag_2((int)result, a3);
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


// list_merge @ 0x12d658
/* luna: Merges a source list onto the tail of a destination list, using an O(1) tail append when non-empty or a head/tail copy when empty, then clears the sou */
volatile uint32_t * list_merge(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *src_head; // r1
  volatile uint32_t *dst_head_tail; // r2
  int src_tail; // r1

  src_head = (volatile uint32_t *)*a2;
  if ( src_head )
  {
    dst_head_tail = result;
    if ( *result )
    {
      result = (volatile uint32_t *)a2[1];
      *(volatile uint32_t *)dst_head_tail[1] = (int)(uintptr_t)(src_head);
      dst_head_tail[1] = (int)(uintptr_t)(result);
    }
    else
    {
      result = (volatile uint32_t *)*a2;
      src_tail = a2[1];
      *dst_head_tail = *a2;
      dst_head_tail[1] = src_tail;
    }
    *a2 = 0;
  }
  return result;
}



// check_abort_flag_4 @ 0x12d688
int check_abort_flag_4(int result, volatile uint32_t *a2, volatile uint32_t *a3) {
  volatile int16_t **v3; // r7
  volatile uint32_t *v4; // r6

  v3 = (volatile int16_t **)off_12D708;
  v4 = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_12D708 < 0 )
  {
    if ( result || (result = mmio_irq_clear(dword_12D718, dword_12D70C, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (volatile uint32_t *)*a2 != a3 )
        {
          result = mmio_irq_clear(dword_12D710, dword_12D70C, 385);
          if ( **v3 >= 0 )
            goto LABEL_3;
        }
        if ( a3 )
          goto LABEL_3;
      }
      else if ( a3 )
      {
        goto LABEL_14;
      }
      result = mmio_irq_clear(dword_12D714, dword_12D70C, 386);
    }
  }
  if ( a2 )
  {
LABEL_3:
    *a2 = *a3;
    goto LABEL_4;
  }
LABEL_14:
  *v4 = *a3;
LABEL_4:
  if ( (volatile uint32_t *)v4[1] == a3 )
    v4[1] = (int)(uintptr_t)(a2);
  *a3 = 0;
  return result;
}



// crc32_update @ 0x12d71c
/* luna: Updates a CRC-32 accumulator by processing a buffer of bytes using a table-driven MSB-first polynomial routine. */
unsigned int crc32_update(volatile uint8_t *a1, int a2, unsigned int a3) {
  volatile uint8_t *data_end; // r1
  int input_byte; // t1

  if ( !a2 )
    return a3;
  data_end = &a1[a2];
  do
  {
    input_byte = *a1++;
    a3 = *(volatile uint32_t *)(dword_12D744 + 4 * (input_byte ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( data_end != a1 );
  return a3;
}



// load_const_table @ 0x12d748
int load_const_table(int a1) {
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
  v1 = (volatile int *)off_12D7C0;
  memcpy((volatile char *)_frame.v11, (volatile char *)off_12D7C0, 0x80u);
  memcpy(_frame.v12, (volatile char *)v1 + 128, 0x80u);
  v3 = ((uint64_t (*)())__aeabi_f2d)(a1);
  v4 = ((uint64_t (*)())__aeabi_dmul)(v3, *(volatile uint64_t *)&dword_12D7B8);
  v5 = (v5 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12D7C4) << 32);
  v5 = (v5 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v6 = ((uint64_t (*)())__aeabi_dmul)(v4, v5);
  v7 = (v7 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12D7C8) << 32);
  v7 = (v7 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v8 = __aeabi_dadd(v6, v7);
  v9 = ((uint64_t (*)())__aeabi_d2lz)(v8);
  return v9 & 0x7F800000
       | ((((int64_t)(int32_t)(v9 & 0x7FFFFF) * (int64_t)(int32_t)(_frame.v11[(v9 >> 18) & 0x1F])) >> 23) + *(volatile uint32_t *)&_frame.v12[4 * ((v9 >> 18) & 0x1F)]);
}


// float32_decompose @ 0x12d7cc
unsigned int float32_decompose(unsigned int a1) {
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
        v4 = (float)((float)v2 * flt_12D8DC) + flt_12D8E0;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * flt_12D8EC) + flt_12D8F0;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = flt_12D8F8;
          else
            v7 = flt_12D8F4;
          if ( v1 >= 0x700000 )
            v8 = flt_12D900;
          else
            v8 = flt_12D8FC;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_12D8E4) + flt_12D8E8;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_12D8D4) + flt_12D8D8;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_12D8CC) + flt_12D8D0;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_12D8C0) + flt_12D8C4;
  }
  *(volatile float *)&result = (float)(v3 - 127) + (float)(v4 * flt_12D8C8);
  return result;
}


// system_init_sequence @ 0x12d908
unsigned int system_init_sequence(unsigned int a1) {
  unsigned int v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0

  v1 = float32_decompose(a1);
  v2 = ((uint64_t (*)())__aeabi_f2d)(v1);
  v3 = ((uint64_t (*)())__aeabi_dmul)(v2, *(volatile uint64_t *)&dword_12D928);
  return ((int (*)(uint64_t))double_to_float)(v3);
}


// tail_call_14274c @ 0x12d930
int tail_call_14274c(int a1) {
  return float_to_i24(a1);
}


// setup_stack_copy @ 0x12d934
float setup_stack_copy(float a1) {
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

  v1 = *(volatile uint32_t *)(dword_12D9AC + 260);
  v2 = *(volatile uint32_t *)(dword_12D9AC + 264);
  v3 = *(volatile uint32_t *)(dword_12D9AC + 268);
  v27[0] = *(volatile uint32_t *)(dword_12D9AC + 256);
  v27[1] = v1;
  v27[2] = v2;
  v27[3] = v3;
  v4 = *(volatile uint32_t *)(dword_12D9AC + 276);
  v5 = *(volatile uint32_t *)(dword_12D9AC + 280);
  v6 = *(volatile uint32_t *)(dword_12D9AC + 284);
  v27[4] = *(volatile uint32_t *)(dword_12D9AC + 272);
  v27[5] = v4;
  v27[6] = v5;
  v27[7] = v6;
  v7 = *(volatile uint32_t *)(dword_12D9AC + 292);
  v8 = *(volatile uint32_t *)(dword_12D9AC + 296);
  v9 = *(volatile uint32_t *)(dword_12D9AC + 300);
  v27[8] = *(volatile uint32_t *)(dword_12D9AC + 288);
  v27[9] = v7;
  v27[10] = v8;
  v27[11] = v9;
  v10 = *(volatile uint32_t *)(dword_12D9AC + 308);
  v11 = *(volatile uint32_t *)(dword_12D9AC + 312);
  v12 = *(volatile uint32_t *)(dword_12D9AC + 316);
  v27[12] = *(volatile uint32_t *)(dword_12D9AC + 304);
  v27[13] = v10;
  v27[14] = v11;
  v27[15] = v12;
  v13 = *(volatile uint32_t *)(dword_12D9AC + 324);
  v14 = *(volatile uint32_t *)(dword_12D9AC + 328);
  v15 = *(volatile uint32_t *)(dword_12D9AC + 332);
  v28[0] = *(volatile uint32_t *)(dword_12D9AC + 320);
  v28[1] = v13;
  v28[2] = v14;
  v28[3] = v15;
  v16 = *(volatile uint32_t *)(dword_12D9AC + 340);
  v17 = *(volatile uint32_t *)(dword_12D9AC + 344);
  v18 = *(volatile uint32_t *)(dword_12D9AC + 348);
  v28[4] = *(volatile uint32_t *)(dword_12D9AC + 336);
  v28[5] = v16;
  v28[6] = v17;
  v28[7] = v18;
  v19 = *(volatile uint32_t *)(dword_12D9AC + 356);
  v20 = *(volatile uint32_t *)(dword_12D9AC + 360);
  v21 = *(volatile uint32_t *)(dword_12D9AC + 364);
  v28[8] = *(volatile uint32_t *)(dword_12D9AC + 352);
  v28[9] = v19;
  v28[10] = v20;
  v28[11] = v21;
  v22 = *(volatile uint32_t *)(dword_12D9AC + 372);
  v23 = *(volatile uint32_t *)(dword_12D9AC + 376);
  v24 = *(volatile uint32_t *)(dword_12D9AC + 380);
  v28[12] = *(volatile uint32_t *)(dword_12D9AC + 368);
  v28[13] = v22;
  v28[14] = v23;
  v28[15] = v24;
  v25 = COERCE_FLOAT(v28[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF] + (COERCE_UNSIGNED_INT(a1) >> 1)) * *(volatile float *)&v27[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}



