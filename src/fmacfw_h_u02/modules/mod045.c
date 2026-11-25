// wlan_ioctl_handler_1 @ 0x12d108
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
int wlan_ioctl_handler_2(int result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r5

  v2 = (volatile uint32_t *)result;
  if ( **(volatile int16_t **)off_12D184 < 0 && !a2 )
    result = irq_disable_mmio_write(dword_12D18C, dword_12D188, 95);
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



// list_pop @ 0x12d190
volatile uint32_t * list_pop(int a1) {
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r2

  v1 = *(volatile uint32_t **)a1;
  if ( *(volatile uint32_t *)a1 )
  {
    v2 = *(volatile uint32_t **)(a1 + 4);
    *(volatile uint32_t *)a1 = *v1;
    if ( v2 == v1 )
      *(volatile uint32_t *)(a1 + 4) = 0;
  }
  return v1;
}



// wlan_ioctl_handler_3 @ 0x12d1a8
int wlan_ioctl_handler_3(int result, volatile uint32_t *a2) {
  int v2; // r5
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r3

  v2 = result;
  if ( **(volatile int16_t **)off_12D204 < 0 && !result )
    result = irq_disable_mmio_write(dword_12D20C, dword_12D208, 132);
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



// list_contains @ 0x12d210
BOOL list_contains(volatile uint32_t **a1, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (volatile uint32_t *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == 0;
}



// list_length @ 0x12d22c
int list_length(volatile uint32_t **a1) {
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



// list_foreach @ 0x12d240
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



// list_remove @ 0x12d288
volatile uint32_t * list_remove(volatile uint32_t *result, volatile uint32_t **a2, volatile uint32_t *a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r4
  volatile uint32_t **v5; // r3

  v3 = (volatile uint32_t *)*result;
  if ( !a2 )
    return (volatile uint32_t *)wlan_ioctl_handler_2((int)result, a3);
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
volatile uint32_t * get_ptr_value(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r2
  int v5; // r1

  v3 = (volatile uint32_t *)*a2;
  if ( v3 )
  {
    v4 = result;
    if ( *result )
    {
      result = (volatile uint32_t *)a2[1];
      *(volatile uint32_t *)v4[1] = (int)(uintptr_t)(v3);
      v4[1] = (int)(uintptr_t)(result);
    }
    else
    {
      result = (volatile uint32_t *)*a2;
      v5 = a2[1];
      *v4 = *a2;
      v4[1] = v5;
    }
    *a2 = 0;
  }
  return result;
}



// is_global_flag_set @ 0x12d320
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
unsigned int f32_to_f16(unsigned int a1) {
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
        v4 = (float)((float)v2 * flt_12D574) + flt_12D578;
      }
      else if ( v1 >= 0x400000 )
      {
        v6 = (float)(unsigned int)v2;
        if ( v1 < 0x500000 )
        {
          v4 = (float)(v6 * flt_12D584) + flt_12D588;
        }
        else if ( v1 >= 0x600000 )
        {
          if ( v1 >= 0x700000 )
            v7 = flt_12D590;
          else
            v7 = flt_12D58C;
          if ( v1 >= 0x700000 )
            v8 = flt_12D598;
          else
            v8 = flt_12D594;
          v4 = (float)(v6 * v7) + v8;
        }
        else
        {
          v4 = (float)(v6 * flt_12D57C) + flt_12D580;
        }
      }
      else
      {
        v4 = (float)((float)v2 * flt_12D56C) + flt_12D570;
      }
    }
    else
    {
      v4 = (float)((float)v2 * flt_12D564) + flt_12D568;
    }
  }
  else
  {
    v4 = (float)((float)v2 * flt_12D558) + flt_12D55C;
  }
  *(volatile float *)&result = (float)(v3 - 127) + (float)(v4 * flt_12D560);
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
int trampoline_142570(int a1) {
  return float_to_int_convert(a1);
}


// read_config_block @ 0x12d5cc
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
  float v25; // s15
  uint32_t v27[16]; // [sp+0h] [bp-80h]
  uint32_t v28[16]; // [sp+40h] [bp-40h]

  v1 = *(volatile uint32_t *)(dword_12D644 + 260);
  v2 = *(volatile uint32_t *)(dword_12D644 + 264);
  v3 = *(volatile uint32_t *)(dword_12D644 + 268);
  v27[0] = *(volatile uint32_t *)(dword_12D644 + 256);
  v27[1] = v1;
  v27[2] = v2;
  v27[3] = v3;
  v4 = *(volatile uint32_t *)(dword_12D644 + 276);
  v5 = *(volatile uint32_t *)(dword_12D644 + 280);
  v6 = *(volatile uint32_t *)(dword_12D644 + 284);
  v27[4] = *(volatile uint32_t *)(dword_12D644 + 272);
  v27[5] = v4;
  v27[6] = v5;
  v27[7] = v6;
  v7 = *(volatile uint32_t *)(dword_12D644 + 292);
  v8 = *(volatile uint32_t *)(dword_12D644 + 296);
  v9 = *(volatile uint32_t *)(dword_12D644 + 300);
  v27[8] = *(volatile uint32_t *)(dword_12D644 + 288);
  v27[9] = v7;
  v27[10] = v8;
  v27[11] = v9;
  v10 = *(volatile uint32_t *)(dword_12D644 + 308);
  v11 = *(volatile uint32_t *)(dword_12D644 + 312);
  v12 = *(volatile uint32_t *)(dword_12D644 + 316);
  v27[12] = *(volatile uint32_t *)(dword_12D644 + 304);
  v27[13] = v10;
  v27[14] = v11;
  v27[15] = v12;
  v13 = *(volatile uint32_t *)(dword_12D644 + 324);
  v14 = *(volatile uint32_t *)(dword_12D644 + 328);
  v15 = *(volatile uint32_t *)(dword_12D644 + 332);
  v28[0] = *(volatile uint32_t *)(dword_12D644 + 320);
  v28[1] = v13;
  v28[2] = v14;
  v28[3] = v15;
  v16 = *(volatile uint32_t *)(dword_12D644 + 340);
  v17 = *(volatile uint32_t *)(dword_12D644 + 344);
  v18 = *(volatile uint32_t *)(dword_12D644 + 348);
  v28[4] = *(volatile uint32_t *)(dword_12D644 + 336);
  v28[5] = v16;
  v28[6] = v17;
  v28[7] = v18;
  v19 = *(volatile uint32_t *)(dword_12D644 + 356);
  v20 = *(volatile uint32_t *)(dword_12D644 + 360);
  v21 = *(volatile uint32_t *)(dword_12D644 + 364);
  v28[8] = *(volatile uint32_t *)(dword_12D644 + 352);
  v28[9] = v19;
  v28[10] = v20;
  v28[11] = v21;
  v22 = *(volatile uint32_t *)(dword_12D644 + 372);
  v23 = *(volatile uint32_t *)(dword_12D644 + 376);
  v24 = *(volatile uint32_t *)(dword_12D644 + 380);
  v28[12] = *(volatile uint32_t *)(dword_12D644 + 368);
  v28[13] = v22;
  v28[14] = v23;
  v28[15] = v24;
  v25 = COERCE_FLOAT(v28[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF] + (COERCE_UNSIGNED_INT(a1) >> 1)) * *(volatile float *)&v27[(COERCE_UNSIGNED_INT(a1) >> 20) & 0xF];
  return (float)((float)(a1 / v25) + v25) * 0.5;
}



