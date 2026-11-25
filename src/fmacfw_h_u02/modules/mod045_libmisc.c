// wlan_ioctl_handler_1 @ 0x12d108
/* luna: Appends an element to the end of a list and clears the element’s next pointer. */
int wlan_ioctl_handler_1(int result, volatile uint32_t *a2) {
  int v2; // r5

  v2 = result;
  if ( **(volatile int16_t **)off_12D144 < 0 && !a2 )
    result = irq_disable_mmio_write((int)aListHdrNull, (int)aCoListPushBack, 72);
  if ( *(volatile uint32_t *)v2 )
    **(volatile uint32_t **)(v2 + 4) = (int)(uintptr_t)(a2);
  else
    *(volatile uint32_t *)v2 = (int)(uintptr_t)(a2);
  *(volatile uint32_t *)(v2 + 4) = (int)(uintptr_t)(a2);
  *a2 = 0;
  return result;
}


// wlan_ioctl_handler_2 @ 0x12d150
/* luna: Prepends a node to a singly linked list and sets the tail when the list was empty. */
int wlan_ioctl_handler_2(int result, volatile uint32_t *a2) {
  volatile uint32_t *list_header; // r5

  list_header = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_12D184 < 0 && !a2 )
    result = irq_disable_mmio_write(dword_12D18C, dword_12D188, 95);
  if ( *list_header )
  {
    *a2 = *list_header;
  }
  else
  {
    list_header[1] = (int)(uintptr_t)(a2);
    *a2 = 0;
  }
  *list_header = (int)(uintptr_t)(a2);
  return result;
}



// list_pop @ 0x12d190
/* luna: Removes and returns the head node, clearing the tail pointer when the list becomes empty. */
volatile uint32_t * list_pop(int a1) {
  volatile uint32_t *popped_node; // r3
  volatile uint32_t *tail_node; // r2

  popped_node = *(volatile uint32_t **)a1;
  if ( *(volatile uint32_t *)a1 )
  {
    tail_node = *(volatile uint32_t **)(a1 + 4);
    *(volatile uint32_t *)a1 = *popped_node;
    if ( tail_node == popped_node )
      *(volatile uint32_t *)(a1 + 4) = 0;
  }
  return popped_node;
}



// wlan_ioctl_handler_3 @ 0x12d1a8
/* luna: Unlinks the specified node from a head/tail singly linked list, updating the head or tail as needed. */
int wlan_ioctl_handler_3(int result, volatile uint32_t *a2) {
  int list; // r5
  volatile uint32_t *current_node; // r3
  volatile uint32_t *previous_node; // r2
  volatile uint32_t *tail_node; // r3

  list = result;
  if ( **(volatile int16_t **)off_12D204 < 0 && !result )
    result = irq_disable_mmio_write(dword_12D20C, dword_12D208, 132);
  current_node = *(volatile uint32_t **)list;
  if ( *(volatile uint32_t *)list )
  {
    if ( current_node == a2 )
    {
      tail_node = *(volatile uint32_t **)(list + 4);
      *(volatile uint32_t *)list = *a2;
      if ( tail_node == a2 )
        *(volatile uint32_t *)(list + 4) = 0;
    }
    else
    {
      while ( 1 )
      {
        previous_node = current_node;
        current_node = (volatile uint32_t *)*current_node;
        if ( !current_node )
          break;
        if ( current_node == a2 )
        {
          if ( *(volatile uint32_t **)(list + 4) == a2 )
            *(volatile uint32_t *)(list + 4) = (int)(uintptr_t)(previous_node);
          *previous_node = *a2;
          return result;
        }
      }
    }
  }
  return result;
}



// list_contains @ 0x12d210
/* luna: Returns whether the target pointer occurs in the linked chain, treating a null target as present even when the list is empty. */
BOOL list_contains(volatile uint32_t **a1, volatile uint32_t *a2) {
  volatile uint32_t *current_node; // r3

  current_node = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( current_node )
  {
    current_node = (volatile uint32_t *)*current_node;
    if ( a2 == current_node )
      return 1;
  }
  return a2 == 0;
}



// list_length @ 0x12d22c
/* luna: Returns the number of nodes in a singly linked list by following each node’s next pointer. */
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



// list_foreach @ 0x12d240
/* luna: Inserts a node before the first node accepted by the ordering predicate, or appends it if none is accepted. */
int list_foreach(int result, volatile uint32_t *a2, int ( *a3)(volatile uint32_t *, volatile uint32_t *)) {
  volatile uint32_t *current_node; // r4
  volatile uint32_t *list; // r7
  volatile uint32_t *previous_node; // r8

  current_node = *(volatile uint32_t **)result;
  list = (volatile uint32_t *)result;
  if ( *(volatile uint32_t *)result )
  {
    previous_node = 0;
    for ( result = a3(a2, current_node); !result; result = a3(a2, current_node) )
    {
      previous_node = current_node;
      if ( !*current_node )
      {
        list[1] = (int)(uintptr_t)(a2);
        *a2 = 0;
        goto LABEL_9;
      }
      current_node = (volatile uint32_t *)*current_node;
    }
    *a2 = (int)(uintptr_t)(current_node);
    if ( !previous_node )
      goto LABEL_7;
LABEL_9:
    *previous_node = (int)(uintptr_t)(a2);
  }
  else
  {
    *(volatile uint32_t *)(result + 4) = (int)(uintptr_t)(a2);
    *a2 = 0;
LABEL_7:
    *list = (int)(uintptr_t)(a2);
  }
  return result;
}



// list_remove @ 0x12d288
/* luna: Searches the list for a position node, inserts a new node after it, and updates the tail when inserting after the old tail. */
volatile uint32_t * list_remove(volatile uint32_t *result, volatile uint32_t **a2, volatile uint32_t *a3) {
  volatile uint32_t *current_node; // r3
  volatile uint32_t *list_header; // r4
  volatile uint32_t **tail_node; // r3

  current_node = (volatile uint32_t *)*result;
  if ( !a2 )
    return (volatile uint32_t *)wlan_ioctl_handler_2((int)result, a3);
  if ( current_node )
  {
    list_header = result;
    if ( current_node == a2 )
    {
LABEL_8:
      tail_node = (volatile uint32_t **)result[1];
      result = *a2;
      *a3 = (int)(uintptr_t)(*a2);
      *a2 = a3;
      if ( tail_node == a2 )
        list_header[1] = (int)(uintptr_t)(a3);
    }
    else
    {
      while ( 1 )
      {
        current_node = (volatile uint32_t *)*current_node;
        if ( !current_node )
          break;
        if ( a2 == current_node )
          goto LABEL_8;
      }
    }
  }
  return result;
}



// list_find_prev @ 0x12d2c4
volatile uint32_t * list_find_prev(volatile uint32_t *result, volatile uint32_t *a2, volatile uint32_t *a3) {
  volatile uint32_t **v3; // r3

  if ( !a2 )
    return (volatile uint32_t *)wlan_ioctl_handler_1((int)result, a3);
  v3 = (volatile uint32_t **)*result;
  if ( (volatile uint32_t *)*result == a2 )
    return (volatile uint32_t *)wlan_ioctl_handler_2((int)result, a3);
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


// get_ptr_value @ 0x12d2f0
/* luna: Appends the source chain to the destination list and clears the source head field. */
volatile uint32_t * get_ptr_value(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *src_head; // r1
  volatile uint32_t *dst_list_alias; // r2
  int src_tail_link; // r1

  src_head = (volatile uint32_t *)*a2;
  if ( src_head )
  {
    dst_list_alias = result;
    if ( *result )
    {
      result = (volatile uint32_t *)a2[1];
      *(volatile uint32_t *)dst_list_alias[1] = (int)(uintptr_t)(src_head);
      dst_list_alias[1] = (int)(uintptr_t)(result);
    }
    else
    {
      result = (volatile uint32_t *)*a2;
      src_tail_link = a2[1];
      *dst_list_alias = *a2;
      dst_list_alias[1] = src_tail_link;
    }
    *a2 = 0;
  }
  return result;
}



// is_global_flag_set @ 0x12d320
/* luna: Removes a node from a singly linked list, updates the head or tail as needed, and clears the removed node’s next pointer. */
int is_global_flag_set(int result, volatile uint32_t *a2, volatile uint32_t *a3) {
  volatile int16_t **v3; // r7
  volatile uint32_t *v4; // r6

  v3 = (volatile int16_t **)off_12D3A0;
  v4 = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_12D3A0 < 0 )
  {
    if ( result || (result = irq_disable_mmio_write(dword_12D3B0, dword_12D3A4, 384), **v3 < 0) )
    {
      if ( a2 )
      {
        if ( (volatile uint32_t *)*a2 != a3 )
        {
          result = irq_disable_mmio_write(dword_12D3A8, dword_12D3A4, 385);
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
      result = irq_disable_mmio_write(dword_12D3AC, dword_12D3A4, 386);
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



// crc32_update @ 0x12d3b4
/* luna: Updates a CRC-32 accumulator by processing the specified bytes through a lookup table. */
unsigned int crc32_update(volatile uint8_t *a1, int a2, unsigned int a3) {
  volatile uint8_t *v3; // r1
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(volatile uint32_t *)(dword_12D3DC + 4 * (v4 ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( v3 != a1 );
  return a3;
}



// load_version_string @ 0x12d3e0
int load_version_string(int a1) {
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
  v1 = (volatile int *)off_12D458;
  memcpy((volatile char *)_frame.v11, (volatile char *)off_12D458, 0x80u);
  memcpy(_frame.v12, (volatile char *)v1 + 128, 0x80u);
  v3 = ((uint64_t (*)())float_to_double)(a1);
  v4 = ((uint64_t (*)())double_compare_common)(v3, *(volatile uint64_t *)&dword_12D450);
  v5 = (v5 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12D45C) << 32);
  v5 = (v5 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v6 = ((uint64_t (*)())double_compare_common)(v4, v5);
  v7 = (v7 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12D460) << 32);
  v7 = (v7 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v8 = double_compare_eq(v6, v7);
  v9 = ((int (*)(uint64_t))double_to_float_1)(v8);
  return v9 & 0x7F800000
       | ((((int64_t)(int32_t)(v9 & 0x7FFFFF) * (int64_t)(int32_t)(_frame.v11[(v9 >> 18) & 0x1F])) >> 23) + *(volatile uint32_t *)&_frame.v12[4 * ((v9 >> 18) & 0x1F)]);
}


// f32_to_f16 @ 0x12d464
/* luna: Approximates log2 of a positive normal IEEE-754 float by adding its exponent to a piecewise-linear approximation of the mantissa contribution. */
unsigned int f32_to_f16(unsigned int a1) {
  unsigned int mantissa_bits; // r3
  int mantissa_bits_copy; // s15
  int exponent_field; // r0
  float mantissa_log_approx; // s15
  unsigned int result; // r0
  float mantissa_as_float; // s15
  float segment_slope; // s13
  float segment_intercept; // s14

  mantissa_bits = a1 & 0x7FFFFF;
  mantissa_bits_copy = a1 & 0x7FFFFF;
  exponent_field = (uint8_t)(a1 >> 23);
  if ( (a1 & 0x7FFFFFu) >= 0x100000 )
  {
    if ( mantissa_bits >= 0x200000 )
    {
      if ( mantissa_bits < 0x300000 )
      {
        mantissa_log_approx = (float)((float)mantissa_bits_copy * flt_12D574) + flt_12D578;
      }
      else if ( mantissa_bits >= 0x400000 )
      {
        mantissa_as_float = (float)(unsigned int)mantissa_bits_copy;
        if ( mantissa_bits < 0x500000 )
        {
          mantissa_log_approx = (float)(mantissa_as_float * flt_12D584) + flt_12D588;
        }
        else if ( mantissa_bits >= 0x600000 )
        {
          if ( mantissa_bits >= 0x700000 )
            segment_slope = flt_12D590;
          else
            segment_slope = flt_12D58C;
          if ( mantissa_bits >= 0x700000 )
            segment_intercept = flt_12D598;
          else
            segment_intercept = flt_12D594;
          mantissa_log_approx = (float)(mantissa_as_float * segment_slope) + segment_intercept;
        }
        else
        {
          mantissa_log_approx = (float)(mantissa_as_float * flt_12D57C) + flt_12D580;
        }
      }
      else
      {
        mantissa_log_approx = (float)((float)mantissa_bits_copy * flt_12D56C) + flt_12D570;
      }
    }
    else
    {
      mantissa_log_approx = (float)((float)mantissa_bits_copy * flt_12D564) + flt_12D568;
    }
  }
  else
  {
    mantissa_log_approx = (float)((float)mantissa_bits_copy * flt_12D558) + flt_12D55C;
  }
  *(volatile float *)&result = (float)(exponent_field - 127) + (float)(mantissa_log_approx * flt_12D560);
  return result;
}


// log_float_converted @ 0x12d5a0
unsigned int log_float_converted(unsigned int a1) {
  unsigned int v1; // r0
  uint64_t v2; // r0
  uint64_t v3; // r0

  v1 = f32_to_f16(a1);
  v2 = ((uint64_t (*)())float_to_double)(v1);
  v3 = ((uint64_t (*)())double_compare_common)(v2, *(volatile uint64_t *)&dword_12D5C0);
  return ((int (*)(uint64_t))double_to_int)(v3);
}


// trampoline_142570 @ 0x12d5c8
/* luna: Forwards the input to the float-to-integer conversion helper and returns the converted value. */
int trampoline_142570(int a1) {
  return float_to_int_convert(a1);
}


// read_config_block @ 0x12d5cc
/* luna: Estimates the square root of a positive float using a table-derived initial guess and one Newton iteration. */
float read_config_block(float a1) {
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
  float sqrt_estimate; // s15
  uint32_t sqrt_scale_table[16]; // [sp+0h] [bp-80h]
  uint32_t sqrt_bit_adjust_table[16]; // [sp+40h] [bp-40h]

  v1 = *(volatile uint32_t *)(dword_12D644 + 260);
  v2 = *(volatile uint32_t *)(dword_12D644 + 264);
  v3 = *(volatile uint32_t *)(dword_12D644 + 268);
  sqrt_scale_table[0] = *(volatile uint32_t *)(dword_12D644 + 256);
  sqrt_scale_table[1] = v1;
  sqrt_scale_table[2] = v2;
  sqrt_scale_table[3] = v3;
  v4 = *(volatile uint32_t *)(dword_12D644 + 276);
  v5 = *(volatile uint32_t *)(dword_12D644 + 280);
  v6 = *(volatile uint32_t *)(dword_12D644 + 284);
  sqrt_scale_table[4] = *(volatile uint32_t *)(dword_12D644 + 272);
  sqrt_scale_table[5] = v4;
  sqrt_scale_table[6] = v5;
  sqrt_scale_table[7] = v6;
  v7 = *(volatile uint32_t *)(dword_12D644 + 292);
  v8 = *(volatile uint32_t *)(dword_12D644 + 296);
  v9 = *(volatile uint32_t *)(dword_12D644 + 300);
  sqrt_scale_table[8] = *(volatile uint32_t *)(dword_12D644 + 288);
  sqrt_scale_table[9] = v7;
  sqrt_scale_table[10] = v8;
  sqrt_scale_table[11] = v9;
  v10 = *(volatile uint32_t *)(dword_12D644 + 308);
  v11 = *(volatile uint32_t *)(dword_12D644 + 312);
  v12 = *(volatile uint32_t *)(dword_12D644 + 316);
  sqrt_scale_table[12] = *(volatile uint32_t *)(dword_12D644 + 304);
  sqrt_scale_table[13] = v10;
  sqrt_scale_table[14] = v11;
  sqrt_scale_table[15] = v12;
  v13 = *(volatile uint32_t *)(dword_12D644 + 324);
  v14 = *(volatile uint32_t *)(dword_12D644 + 328);
  v15 = *(volatile uint32_t *)(dword_12D644 + 332);
  sqrt_bit_adjust_table[0] = *(volatile uint32_t *)(dword_12D644 + 320);
  sqrt_bit_adjust_table[1] = v13;
  sqrt_bit_adjust_table[2] = v14;
  sqrt_bit_adjust_table[3] = v15;
  v16 = *(volatile uint32_t *)(dword_12D644 + 340);
  v17 = *(volatile uint32_t *)(dword_12D644 + 344);
  v18 = *(volatile uint32_t *)(dword_12D644 + 348);
  sqrt_bit_adjust_table[4] = *(volatile uint32_t *)(dword_12D644 + 336);
  sqrt_bit_adjust_table[5] = v16;
  sqrt_bit_adjust_table[6] = v17;
  sqrt_bit_adjust_table[7] = v18;
  v19 = *(volatile uint32_t *)(dword_12D644 + 356);
  v20 = *(volatile uint32_t *)(dword_12D644 + 360);
  v21 = *(volatile uint32_t *)(dword_12D644 + 364);
  sqrt_bit_adjust_table[8] = *(volatile uint32_t *)(dword_12D644 + 352);
  sqrt_bit_adjust_table[9] = v19;
  sqrt_bit_adjust_table[10] = v20;
  sqrt_bit_adjust_table[11] = v21;
  v22 = *(volatile uint32_t *)(dword_12D644 + 372);
  v23 = *(volatile uint32_t *)(dword_12D644 + 376);
  v24 = *(volatile uint32_t *)(dword_12D644 + 380);
  sqrt_bit_adjust_table[12] = *(volatile uint32_t *)(dword_12D644 + 368);
  sqrt_bit_adjust_table[13] = v22;
  sqrt_bit_adjust_table[14] = v23;
  sqrt_bit_adjust_table[15] = v24;
  sqrt_estimate = COERCE_FLOAT(sqrt_bit_adjust_table[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF] + (COERCE_UNSIGNED_INT(a1) >> 1)) * *(volatile float *)&sqrt_scale_table[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF];
  return (float)((float)(a1 / sqrt_estimate) + sqrt_estimate) * 0.5;
}



