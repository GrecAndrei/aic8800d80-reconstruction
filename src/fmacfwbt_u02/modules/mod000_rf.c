// start @ 0x1001a8
int start() {
  int v0; // r2
  int v1; // r3

  if ( (uint16_t)*(volatile uint32_t *)off_1001EC == 49729
    || (*((volatile uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v0 = *((volatile uint32_t *)off_1001F4 + 92), v1 = *((volatile uint32_t *)off_1001F4 + 93), v0 >= 0)
    || v1 >= 0 )
  {
    _R0 = dword_1001F8;
    __asm volatile("msr msp, %0" : : "r"(_R0) : "memory");
    return off_1001FC();
  }
  else
  {
    _R2 = v0 & 0xFFFFFFF;
    __asm volatile("msr msp, %0" : : "r"(_R2) : "memory");
    return ((int (*)(void))(v1 & 0xFFFFFFF))();
  }
}


// memset @ 0x100200
/* luna: Fills the destination with the low byte of the value, using aligned word stores for bulk data, and returns the original destination. */
volatile int * memset(volatile int *result, uint8_t a2, unsigned int a3) {
  unsigned int remaining_bytes; // r4
  volatile int *dst_cursor; // r3
  int repeated_fill_word; // r5
  volatile uint8_t *bulk_store_cursor; // r2
  volatile int *word_dst; // r2
  int chunk_bytes; // r6
  volatile int *tail_end; // r4

  if ( (uint32_t)result << 30 )
  {
    remaining_bytes = a3 - 1;
    if ( !a3 )
      return result;
    dst_cursor = result;
    while ( 1 )
    {
      *(volatile uint8_t *)dst_cursor = a2;
      dst_cursor = (volatile int *)((volatile char *)dst_cursor + 1);
      if ( !((uint32_t)dst_cursor << 30) )
        break;
      if ( remaining_bytes-- == 0 )
        return result;
    }
  }
  else
  {
    remaining_bytes = a3;
    dst_cursor = result;
  }
  if ( remaining_bytes > 3 )
  {
    repeated_fill_word = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
    if ( remaining_bytes <= 0xF )
    {
      word_dst = dst_cursor;
      chunk_bytes = remaining_bytes;
    }
    else
    {
      bulk_store_cursor = (void *)(dst_cursor + 4);
      do
      {
        *((volatile uint32_t *)bulk_store_cursor - 4) = repeated_fill_word;
        *((volatile uint32_t *)bulk_store_cursor - 3) = repeated_fill_word;
        *((volatile uint32_t *)bulk_store_cursor - 2) = repeated_fill_word;
        *((volatile uint32_t *)bulk_store_cursor - 1) = repeated_fill_word;
        bulk_store_cursor += 16;
      }
      while ( bulk_store_cursor != (volatile char *)dst_cursor + ((remaining_bytes - 16) & 0xFFFFFFF0) + 32 );
      word_dst = &dst_cursor[4 * ((remaining_bytes - 16) >> 4) + 4];
      chunk_bytes = remaining_bytes & 0xF;
      if ( (remaining_bytes & 0xC) == 0 )
      {
        remaining_bytes &= 0xFu;
        dst_cursor = word_dst;
        if ( !chunk_bytes )
          return result;
        goto LABEL_16;
      }
    }
    dst_cursor = (volatile int *)((volatile char *)word_dst + ((chunk_bytes - 4) & 0xFFFFFFFC) + 4);
    do
      *word_dst++ = repeated_fill_word;
    while ( dst_cursor != word_dst );
    remaining_bytes = chunk_bytes & 3;
  }
  if ( !remaining_bytes )
    return result;
LABEL_16:
  tail_end = (volatile int *)((volatile char *)dst_cursor + remaining_bytes);
  do
  {
    *(volatile uint8_t *)dst_cursor = a2;
    dst_cursor = (volatile int *)((volatile char *)dst_cursor + 1);
  }
  while ( tail_end != dst_cursor );
  return result;
}



// ke_evt_handler @ 0x1002a0
int ke_evt_handler(int a1, int a2, int a3, int a4) {
  volatile uint8_t **v4; // r5
  int v5; // r7
  int v6; // r3
  volatile int *v7; // r4
  int v8; // r2
  unsigned int v9; // lr
  volatile uint32_t *v10; // r12
  unsigned int v11; // r8
  uint64_t v12; // kr00_8
  uint64_t v13; // kr08_8
  unsigned int v14; // r7
  unsigned int v15; // r3
  volatile int *v16; // r4
  int v17; // r3
  unsigned int v18; // r6
  unsigned int v19; // r0
  unsigned int v20; // r3
  volatile int16_t **v21; // r6
  int v22; // r3
  volatile int **v23; // r0
  int v24; // r2
  volatile int *v25; // r12
  uint64_t v26; // kr10_8
  int v27; // r1
  int v28; // r7
  int v29; // r4
  uint64_t v30; // kr18_8
  int v31; // r0
  volatile uint32_t *v32; // r7
  int v33; // r2
  volatile int *v34; // r1
  unsigned int v35; // r4
  int v36; // r2
  unsigned int v37; // r3
  unsigned int v38; // r3
  unsigned int v39; // r7
  int result; // r0
  volatile uint8_t *v41; // r3
  int v42; // r2
  unsigned int v43; // r2

  v4 = (volatile uint8_t **)off_100418;
  v5 = dword_10041C;
  v6 = *(volatile uint32_t *)off_100418;
  v7 = (volatile int *)off_100420;
  v8 = *(volatile uint16_t *)(*(volatile uint32_t *)off_100418 + 8);
  v9 = *(volatile uint32_t *)(*(volatile uint32_t *)off_100418 + 52);
  v10 = (void *)(uintptr_t)(off_100470);
  v11 = dword_100474;
  *((volatile uint32_t *)off_100470 + 4) = v9;
  v12 = *(volatile uint64_t *)(v6 + 36);
  v13 = *(volatile uint64_t *)(v6 + 44);
  *v7 = v5;
  v14 = v5 + 88 * v8 + 88;
  v15 = (unsigned int)v12 >> 3;
  v16 = (void *)(uintptr_t)(off_100424);
  *v10 = v12;
  if ( (unsigned int)v12 >> 3 < 3 )
    v15 = 3;
  *v16 = v15;
  v17 = HIDWORD(v12) >> 3;
  v18 = (unsigned int)v13 >> 3;
  if ( HIDWORD(v12) >> 3 < 3 )
    v17 = 3;
  v10[1] = HIDWORD(v12);
  v19 = HIDWORD(v13) >> 3;
  if ( (unsigned int)v12 < 3 )
    v18 = 3;
  v16[1] = v17;
  v20 = v9 >> 3;
  if ( v19 < 3 )
    v19 = 3;
  v16[2] = v18;
  v21 = (volatile int16_t **)off_100428;
  v10[3] = HIDWORD(v13);
  if ( v20 < 3 )
    v20 = 3;
  v16[3] = v19;
  v16[4] = v20;
  v10[2] = v13;
  printf_wrapper("stk_start=%x, ptr_bss=%x\n", v11, v14);
  if ( **v21 < 0 && v14 >= v11 )
    mmio_irq_clear((int)aPtrBssStartSta, (int)aPostponedArray, 120);
  v22 = dword_100430;
  v23 = (volatile int **)off_100438;
  v24 = dword_100430 + 80 * (*((volatile uint16_t *)*v4 + 4) + 1);
  *(volatile uint32_t *)off_100434 = v24;
  v25 = *v23;
  v26 = *(volatile uint64_t *)(v16 + 1);
  v27 = v24 + 360 * *v16;
  v28 = v27 + 360 * v26;
  *(volatile uint32_t *)off_10043C = v27;
  v30 = *(volatile uint64_t *)(v16 + 3);
  v29 = v16[4];
  v31 = v28 + 360 * HIDWORD(v26);
  *(volatile uint32_t *)off_100440 = v28;
  v32 = (void *)(uintptr_t)(off_100448);
  *(volatile uint32_t *)off_100444 = v31;
  v33 = v31 + 360 * v30;
  v34 = (volatile int *)off_10044C;
  *v32 = v33;
  v35 = v33 + 360 * v29;
  v36 = *v25;
  *v34 = v22;
  if ( !v36 )
  {
    v37 = (v25[1] + 4) & 0xFFFFFFFC;
    *v25 = v35 + 4;
    v35 += v37;
  }
  if ( !v25[2] )
  {
    v38 = (v25[3] + 4) & 0xFFFFFFFC;
    v25[2] = v35 + 4;
    v35 += v38;
  }
  v39 = dword_100450;
  result = printf_wrapper("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_100430, dword_100450, v35);
  if ( **v21 < 0 && v35 >= v39 )
    result = mmio_irq_clear((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
  v41 = *v4;
  ((volatile uint32_t *)(uintptr_t)off_100458)[0] = *((volatile uint32_t *)*v4 + 3);
  v42 = *v41;
  if ( v42 == 2 )
  {
    v43 = *((volatile uint32_t *)v41 + 4);
  }
  else
  {
    if ( v42 != 1 )
      return result;
    v43 = *((volatile uint32_t *)v41 + 5);
  }
  if ( v43 )
  {
    if ( dword_10045C > v43 )
      return printf_wrapper("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_10045C, v43);
  }
  return result;
}


// ke_task_init @ 0x100478
void ke_task_init() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r5
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r2
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r1
  volatile uint32_t *v7; // r3
  volatile uint8_t *v8; // r6
  volatile uint32_t *v9; // r2

  v0 = (volatile int *)off_100568;
  v1 = (void *)(uintptr_t)(off_100570);
  v2 = (void *)(uintptr_t)(off_100574);
  v3 = (void *)(uintptr_t)(off_100578);
  *(volatile uint32_t *)off_10056C = off_100568;
  v4 = (void *)(uintptr_t)(off_10057C);
  *v1 = (int)(uintptr_t)(v0 + 19);
  *v2 = (int)(uintptr_t)(v0 + 3);
  *v3 = (int)(uintptr_t)(v0 + 34);
  v5 = (void *)(uintptr_t)(off_100580);
  v6 = (volatile uint32_t *)off_100584;
  *v4 = (int)(uintptr_t)(v0 + 38);
  *v5 = (int)(uintptr_t)((volatile char *)v0 + 178);
  *v6 = (int)(uintptr_t)(v0 + 44);
  ke_evt_handler((int)(v0 + 44), (int)v6, (int)v0 + 178, (int)v5);
  if ( *(volatile uint8_t *)*v1 == 1 )
  {
    v7 = (void *)(uintptr_t)(off_10058C);
    *((volatile uint32_t *)off_100588 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  v8 = (void *)(uintptr_t)(off_100594);
  *((volatile uint8_t *)off_100594 + 2) = (*(volatile uint32_t *)off_100590 & 0xF) == 10;
  ke_irq_lock();
  gpio_pad_config();
  copy_stats();
  shutdown_sequence();
  if ( *((volatile uint8_t *)v0 + 363) )
  {
    mmio_init_check();
    rf_afe_enable();
  }
  ke_event_schedule_1("hosttype=%d, asic_ver=0x%x\r\n", *((volatile uint8_t *)v0 + 76), *(volatile uint8_t *)off_100598);
  rf_channel_config();
  process_state();
  if ( v8[2] )
  {
    log_debug_c();
    v9 = (void *)(uintptr_t)(off_100590);
    *(volatile uint32_t *)off_1005A0 &= ~8u;
    *v9 &= 0xFFFFFFF0;
    state_check_feature(2, aWakeup);
  }
  else
  {
    state_check_feature(2, aWifimain);
  }
  if ( *(volatile uint8_t *)*v1 == 3 )
    *(volatile uint32_t *)off_1005A8 = 1;
  ke_init_structures();
}


// timer_read @ 0x1005b0
int timer_read(int a1) {
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(volatile uint32_t *)off_100634;
  v3 = *(volatile uint32_t *)off_100634;
  v4 = return_one();
  v5 = sys_status_get_bit21();
  v6 = (v2 >> 8) & 0xF;
  v7 = (v3 >> 27) & 1;
  if ( a1 == 1 )
  {
    if ( v5 )
    {
      return 11;
    }
    else if ( v6 == 1 )
    {
      return 2;
    }
    else if ( v4 )
    {
      return 9;
    }
    else
    {
      return 3;
    }
  }
  else if ( a1 == 2 )
  {
    if ( v6 == 1 )
    {
      if ( v7 )
        return 7;
      else
        return 4;
    }
    else
    {
      return v7 + 5;
    }
  }
  else if ( a1 )
  {
    if ( **(volatile int16_t **)off_100638 < 0 )
      mmio_irq_clear(dword_100640, dword_10063C, 434);
    return 0;
  }
  else if ( v5 )
  {
    return 10;
  }
  else if ( v7 )
  {
    return 8;
  }
  else
  {
    return v6 != 1;
  }
}



// timer_set @ 0x100644
int timer_set(int a1) {
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((volatile uint32_t *)off_10066C + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( (int)(*((volatile uint32_t *)off_10066C + 4) - result) < 0 );
  return result;
}



// timer_poll @ 0x100670
int timer_poll(int a1) {
  int result; // r0

  result = timer_read(a1);
  if ( *(volatile uint8_t *)off_100684 != result )
    *(volatile uint8_t *)off_100684 = result;
  return result;
}



// hw_config_init_0688 @ 0x100688
int hw_config_init_0688() {
  volatile int *v0; // r4
  int v1; // r5
  int result; // r0
  int16_t v3; // r2

  v0 = (volatile int *)off_1006C0;
  v1 = timer_read(HIBYTE(*(volatile uint32_t *)off_1006BC) & 3);
  memset(v0, 0, 8u);
  result = dword_1006C4 + 16 * v1;
  v3 = *(volatile uint16_t *)(result + 6);
  *(volatile uint32_t *)off_1006C8 = *(volatile uint16_t *)(result + 4);
  *((volatile uint8_t *)v0 + 1) = v3;
  *(volatile uint8_t *)v0 = -1;
  return result;
}



// get_timer_flag @ 0x1006cc
int get_timer_flag() {
  return *((volatile uint8_t *)off_1006D4 + 1);
}



// clock_start @ 0x1006d8
int clock_start() {
  volatile unsigned int v0; // r0
  unsigned int v1; // r0
  int v3; // r2
  volatile unsigned int v4; // r1
  int result; // r0
  unsigned int v6; // r1
  int v8; // r3
  int v9; // [sp+0h] [bp-Ch]
  int v10; // [sp+4h] [bp-8h]

  *(volatile uint32_t *)dword_100728 = 17;
  v0 = (*(volatile uint32_t *)0x40501010u);
  v1 = v0 + 10;
  do
  {
    v9 = 32;
    while ( v9-- )
      ;
    v3 = (*(volatile uint32_t *)0x40501010u) - v1;
  }
  while ( v3 < 0 );
  *(volatile uint32_t *)dword_100728 = 0;
  v4 = (*(volatile uint32_t *)0x40501010u);
  result = 32;
  v6 = v4 + 10;
  do
  {
    v10 = 32;
    while ( v10-- )
      ;
    v8 = (*(volatile uint32_t *)0x40501010u) - v6;
  }
  while ( v8 < 0 );
  return result;
}


// gpio_pin_set @ 0x100730
volatile uint32_t *gpio_pin_set() {
  volatile uint32_t *result; // r0
  volatile int *v1; // r2

  result = (void *)(uintptr_t)(off_100764);
  v1 = (volatile int *)off_100768;
  *(volatile uint32_t *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}



// gpio_pin_clear @ 0x10076c
volatile uint32_t *gpio_pin_clear() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2

  result = (void *)(uintptr_t)(off_10079C);
  v1 = (volatile unsigned int *)off_1007A0;
  *(volatile uint32_t *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}



// sub_1007a4 @ 0x1007a4
int sub_1007a4(int result, int a2, int a3, unsigned int a4) {
  int v4; // r8
  unsigned int v5; // r12
  unsigned int v6; // r11
  int v7; // r7
  int v8; // r10
  int v9; // r10
  unsigned int v10; // r3
  unsigned int v11; // r4
  int v12; // r4
  int v13; // r5
  int v14; // r2
  int v15; // r5
  int v16; // zf
  int v17; // r5
  int v18; // r5
  int v19; // r3
  volatile uint32_t *v20; // r2
  int v21; // t1
  int v22; // [sp+4h] [bp-10h]

  v4 = result - 4;
  v5 = 16;
  v6 = 31;
  v22 = 0;
  do
  {
    v7 = 32 * v22;
    if ( ((a4 >> v22) & 1) != 0 )
    {
      if ( v5 - 15 <= v5 + 16 )
        v8 = 32;
      else
        v8 = 1;
      v9 = v8 + v7;
      v10 = 32 * v22;
      do
      {
        while ( 1 )
        {
          v14 = v10 >= v5 ? v10 - 16 : v10 + 16;
          v15 = *(volatile uint32_t *)(result + 4 * v14);
          v11 = v14 + 1;
          if ( v15 != *(volatile uint32_t *)(v4 + 64) )
            break;
          ++v10;
          *(volatile uint32_t *)(a2 + 4 * v14) = v15;
          if ( v10 == v9 )
            goto LABEL_17;
        }
        if ( v11 > v6 )
          v11 = 32 * v22;
        v12 = *(volatile uint32_t *)(result + 4 * v11);
        v13 = (uint8_t)v12;
        if ( (uint8_t)v12 <= 0x97u )
          v13 = (uint8_t)(v12 - 1);
        ++v10;
        *(volatile uint32_t *)(a2 + 4 * v14) = ((uint8_t)v12
                                   - ((unsigned int)(((unsigned int)dword_100894
                                                    * (uint64_t)(unsigned int)(v13 + 10)) >> 32) >> 2))
                                  | v12 & 0xFFFFFF00;
      }
      while ( v10 != v9 );
    }
    else
    {
      if ( v5 - 15 <= v5 + 16 )
        v17 = 32;
      else
        v17 = 1;
      v18 = result - 4 + 4 * (v17 + v7);
      v19 = v4;
      do
      {
        v20 = (volatile uint32_t *)(a2 + 4 - result + v19);
        v21 = *(volatile uint32_t *)(v19 + 4);
        v19 += 4;
        *v20 = v21;
      }
      while ( v19 != v18 );
    }
LABEL_17:
    v16 = v22++ == 2;
    v4 += 128;
    v6 += 32;
    v5 += 32;
  }
  while ( !v16 );
  return result;
}



// heap_alloc @ 0x100898
int heap_alloc(int a1, unsigned int a2, volatile uint32_t *a3) {
  volatile char *v3; // r5
  int v4; // r7
  int v5; // r1
  int v6; // r6
  int j; // r3
  int v8; // t1
  int v9; // nf
  int v10; // r0
  int result; // r0
  int v12; // r7
  int v13; // r5
  volatile char *v14; // r6
  int v15; // r1
  volatile uint8_t *v16; // r4
  int i; // r5
  int v18; // t1
  int v19; // r3
  int v20; // zf

  if ( a1 )
  {
    if ( a2 > 0x1666 )
    {
      v13 = 1920;
      v12 = 5;
    }
    else if ( a2 > 0x1616 )
    {
      v13 = 1536;
      v12 = 4;
    }
    else if ( a2 > 0x15C6 )
    {
      v13 = 1152;
      v12 = 3;
    }
    else if ( a2 > 0x1571 )
    {
      v13 = 768;
      v12 = 2;
    }
    else
    {
      v12 = a2 > 0x1486;
      if ( a2 <= 0x1486 )
        v13 = 0;
      else
        v13 = 384;
    }
    v14 = (volatile char *)dword_10099C;
    v15 = 0;
    result = dword_100998 + v13;
    v16 = (volatile uint8_t *)(*(volatile uint32_t *)off_100994 + v12);
    for ( i = 0; i != 3; ++i )
    {
      v18 = *v14++;
      v19 = *v16 + v18 + *((volatile uint8_t *)off_100988 + 1);
      v20 = (v19 & 1) == 0;
      if ( (v19 & 1) != 0 )
        v19 = 1 << i;
      if ( !v20 )
        v15 |= v19;
      v16 += 6;
    }
    *a3 = v15;
  }
  else
  {
    if ( a2 > 0x97B )
    {
      if ( a2 > 0x994 )
        a1 = 2;
      else
        a1 = 1;
    }
    v3 = (volatile char *)dword_10098C;
    v4 = *(volatile uint8_t *)off_100988;
    v5 = 0;
    v6 = *(volatile uint32_t *)off_100984 + a1;
    for ( j = 0; j != 3; ++j )
    {
      v8 = *v3++;
      v10 = (*(volatile uint8_t *)(v6 + 3 * j) + v8 + v4) << 31;
      v9 = ((*(volatile uint8_t *)(v6 + 3 * j) + v8 + v4) & 1) != 0;
      if ( ((*(volatile uint8_t *)(v6 + 3 * j) + v8 + v4) & 1) != 0 )
        v10 = 1 << j;
      if ( v9 )
        v5 |= v10;
    }
    result = dword_100990;
    *a3 = v5;
  }
  return result;
}



// radio_init @ 0x1009a0
int radio_init(int a1, unsigned int a2) {
  volatile unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (volatile unsigned int *)off_1009D4;
  v3 = heap_alloc(a1, a2, (void *)(&v6));
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = sub_1007a4(v3, dword_1009D8, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}



// radio_irq_setup @ 0x1009dc
int radio_irq_setup(int a1, int a2) {
  volatile unsigned int *v2; // r3
  int v3; // r7
  volatile unsigned int *v5; // r8
  int v6; // lr
  int v7; // r12
  int v8; // r5
  int v9; // r5
  int v10; // r1
  int v11; // r3
  volatile uint32_t *v12; // r2
  int v13; // t1
  volatile uint32_t *v14; // r2
  int v15; // r5
  int i; // r4
  int v17; // r1
  int result; // r0

  v2 = (volatile unsigned int *)off_100A98;
  *(volatile uint32_t *)off_100A94 |= 0x100u;
  v3 = 0;
  *v2 &= 0xFFFCFFFF;
  v5 = v2;
  v6 = -a1;
  v7 = 0;
  v8 = 128;
  while ( 1 )
  {
    v9 = a1 + 4 * (v8 + v3);
    v10 = dword_100A9C + v6;
    v11 = -v6;
    do
    {
      v12 = (volatile uint32_t *)(v10 + v11);
      v13 = *(volatile uint32_t *)v11;
      v11 += 4;
      *v12 = v13;
    }
    while ( v11 != v9 );
    ++v7;
    if ( v3 == 384 )
      break;
    v3 += 128;
    v6 -= 512;
    *v5 = *v5 & 0xFFFCFFFF | (v7 << 16);
    if ( v7 == 3 )
      v8 = 48;
    else
      v8 = 128;
  }
  v14 = (void *)(uintptr_t)(off_100AA0);
  *(volatile uint32_t *)off_100A94 &= ~0x100u;
  *v14 |= 0x1000000u;
  v15 = 1;
  for ( i = 0; i != 12; ++i )
  {
    mmio_irq_enable((2 * i) & 0xFE, *(volatile uint32_t *)(a2 + 8 * i));
    v17 = *(volatile uint32_t *)(a2 + 4 + 8 * i);
    result = mmio_irq_enable(v15, v17);
    v15 = (uint8_t)(v15 + 2);
  }
  *(volatile uint32_t *)off_100AA4 &= ~2u;
  return result;
}



// pll_enable @ 0x100aa8
int pll_enable() {
  volatile uint32_t *v0; // r2
  volatile int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r3

  v0 = (void *)(uintptr_t)(off_100B04);
  *(volatile uint32_t *)off_100B04 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (volatile int *)dword_100B08;
  v2 = dword_100B08 + 2048;
  result = dword_100B0C - dword_100B08;
  do
  {
    v4 = *v1;
    v5 = (void *)((volatile int *)((volatile char *)v1++ + result));
    *v5 = v4;
  }
  while ( v1 != (volatile int *)v2 );
  v6 = (void *)(uintptr_t)(off_100B04);
  *(volatile uint32_t *)off_100B04 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(volatile uint32_t *)off_100B10 &= ~0x20000000u;
  return result;
}



// call_1006d8_with_args @ 0x100b14
volatile char * call_1006d8_with_args(int a1, unsigned int a2, unsigned int a3, int a4, char a5) {
  volatile uint32_t *v9; // r2
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r1
  int v12; // r3
  volatile char *v13; // r0
  volatile unsigned int *v14; // r5
  volatile unsigned int *v15; // r1
  int v16; // r2
  volatile unsigned int *v17; // r1
  volatile char *result; // r0
  volatile unsigned int *v19; // r2
  signed int v20; // r3
  int v21; // r2
  volatile unsigned int *v22; // r1
  volatile unsigned int *v23; // r2
  int v24; // r2
  volatile uint32_t *v25; // r1
  volatile uint32_t *v26; // r0

  clock_start();
  v9 = (void *)(uintptr_t)(off_100CA4);
  *(volatile uint32_t *)off_100CA4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v25 = (void *)(uintptr_t)(off_100CA8);
    v26 = (void *)(uintptr_t)(off_100CAC);
    *(volatile uint32_t *)off_100CA8 = *(volatile uint32_t *)off_100CA8 & 0xFFFE3FFF | 0x18000;
    *v26 &= ~1u;
    v25[27857] |= 0x100u;
    if ( (a5 & 4) != 0 )
      *v9 |= 0x40u;
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_100CA8);
    v11 = (void *)(uintptr_t)(off_100CAC);
    *(volatile uint32_t *)off_100CA8 = *(volatile uint32_t *)off_100CA8 & 0xFFFE3FFF | 0xC000;
    *v11 |= 1u;
    v10[27857] &= ~0x100u;
  }
  if ( a4 == 1 )
  {
    if ( a2 >= a3 )
      v24 = 2;
    else
      v24 = 1;
    *(volatile uint32_t *)off_100CB0 = v24;
    v12 = a2 >= a3;
  }
  else if ( a4 == 2 )
  {
    v20 = a3 - a2;
    if ( (int)(a3 - a2) <= 0 )
    {
      if ( v20 >= -10 )
        v21 = 2;
      else
        v21 = 3;
    }
    else
    {
      v21 = v20 <= 10;
    }
    v12 = ((uint8_t)((int)((uint64_t)((int32_t)dword_100CC4 * (int64_t)(int32_t)(int)(a2 - (a3 - 30))) >> 32) >> 3)
         - (uint8_t)((int)(a2 - (a3 - 30)) >> 31))
        & 7;
    *(volatile uint32_t *)off_100CB0 = v21;
  }
  else
  {
    v12 = 0;
    *(volatile uint32_t *)off_100CB0 = 0;
  }
  v13 = (volatile char *)off_100CB4;
  v14 = (volatile unsigned int *)off_100CB8;
  v15 = (volatile unsigned int *)off_100CBC;
  *(volatile uint32_t *)off_100CB4 = v12 | *(volatile uint32_t *)off_100CB4 & 0xFFFFFFF8;
  v16 = (a4 << 24) & 0x3000000;
  *v14 = *v14 & 0xFCFFFFFF | v16;
  *v15 = (a4 << 16) & 0x30000 | *v15 & 0xFFFCFFFF;
  v17 = v15 + 16708;
  *(volatile uint32_t *)&v13[-80] = *(volatile uint32_t *)&v13[-80] & 0xFFFFFFF0 | a4 & 0xF;
  result = v13 - 80;
  *v17 = v16 | *v17 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = (volatile char *)off_100CC8;
      v22 = (volatile unsigned int *)off_100CCC;
      v23 = (volatile unsigned int *)off_100CC0;
      *(volatile uint32_t *)off_100CC8 = *(volatile uint32_t *)off_100CC8 & 0xFFFFFF | 0x18000000;
      *v22 = *v22 & 0xFFFFFFCF | 0x10;
      *v23 = *v23 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v19 = (volatile unsigned int *)off_100CC0;
    *((volatile uint32_t *)result + 1) = *((volatile uint32_t *)result + 1) & 0xFFFFFF | 0x19000000;
    v17[15866] &= 0xFFFFFFCF;
    *v19 = *v19 & 0xFFFF00FF | 0x9C00;
  }
  return result;
}


// adc_read_ch0 @ 0x100cd0
int adc_read_ch0(int result) {
  volatile unsigned int *v1; // r3
  volatile uint32_t *v2; // r1
  unsigned int v3; // r5
  volatile uint32_t *v4; // r4
  volatile uint32_t *v5; // r3

  v1 = (volatile unsigned int *)off_100D84;
  v2 = (void *)(uintptr_t)(off_100D88);
  v3 = *(volatile uint32_t *)off_100D84;
  v4 = (void *)(uintptr_t)(off_100D8C);
  *(volatile uint32_t *)off_100D88 = (*(volatile uint8_t *)off_100D80 << 10) & 0x1FC00 | *(volatile uint32_t *)off_100D88 & 0xFFFE03FF;
  *v1 |= 0x18u;
  *v1 = *v1 & 0xFFFFFFF8 | 3;
  *v2 |= 0x80000u;
  *v2 |= 0x40000u;
  *v1 = *v1 & 0xFFFFFC1F | 0xE0;
  *v4 &= ~2u;
  *v4 |= 1u;
  if ( !result && ((v3 >> 5) & 0x1F) != 7 )
  {
    v5 = (void *)(uintptr_t)(off_100D90);
    *(volatile uint32_t *)off_100D90 |= 0x80u;
    *v5 &= ~0x40u;
    *v5 |= 0x40u;
    *v5 &= ~0x80u;
  }
  return result;
}



// adc_read_ch1 @ 0x100d94
volatile uint32_t *adc_read_ch1() {
  volatile unsigned int *v0; // r3
  volatile uint32_t *v1; // r1
  unsigned int v2; // r4
  volatile uint32_t *result; // r0
  volatile uint32_t *v4; // r3

  v0 = (volatile unsigned int *)off_100E44;
  v1 = (void *)(uintptr_t)(off_100E48);
  v2 = *(volatile uint32_t *)off_100E44;
  result = (void *)(uintptr_t)(off_100E4C);
  *(volatile uint32_t *)off_100E48 = (*((volatile uint8_t *)off_100E40 + 1) << 10) & 0x1FC00 | *(volatile uint32_t *)off_100E48 & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 8;
  *v0 |= 7u;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = (void *)(uintptr_t)(off_100E50);
    *(volatile uint32_t *)off_100E50 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}



// rf_analog_enable @ 0x100e54
/* luna: Powers up and configures the RF analog circuitry for the requested frequency and mode, applying band-dependent settings and initializing the radio. */
int rf_analog_enable(unsigned int a1, int a2) {
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r4
  int v7; // r1
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r2
  int band_profile_offset; // r4
  volatile unsigned int *v12; // r0
  int v13; // r2
  volatile unsigned int *v14; // r3
  int band_profile_entry; // r4
  volatile unsigned int *v16; // r5
  int v17; // r1
  volatile uint32_t *v18; // r4
  volatile unsigned int *v19; // r1
  volatile uint8_t *v20; // r0
  volatile unsigned int *v21; // r2
  volatile char *v22; // r2
  volatile unsigned int *v23; // r1
  volatile uint32_t *v24; // r5
  volatile uint32_t *v25; // r0
  volatile uint32_t *v26; // r4
  volatile uint32_t *v27; // r2
  int result; // r0

  v2 = (void *)(uintptr_t)(off_1010BC);
  v3 = (void *)(uintptr_t)(off_1010C0);
  v4 = (void *)(uintptr_t)(off_1010C4);
  v5 = (void *)(uintptr_t)(off_1010C8);
  *(volatile uint32_t *)off_1010BC |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = (void *)(uintptr_t)(off_1010CC);
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) = *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = (void *)(uintptr_t)(off_1010D0);
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = (void *)(uintptr_t)(off_1010D4);
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  sub_102d10(1, 0, 16, *v9);
  sub_102d10(1, 16, 16, *(volatile uint32_t *)off_1010D8);
  radio_init(0, a1);
  if ( a1 > 0x98A )
  {
    band_profile_offset = 6;
  }
  else if ( a1 <= 0x97B )
  {
    band_profile_offset = 0;
  }
  else
  {
    band_profile_offset = 3;
  }
  v12 = (volatile unsigned int *)off_1010DC;
  v13 = dword_1010E0;
  v14 = (volatile unsigned int *)off_1010E4;
  *(volatile uint32_t *)off_1010DC = *(volatile uint32_t *)off_1010DC & 0xFE01FFFF | (*(volatile uint8_t *)(dword_1010E0 + band_profile_offset) << 17);
  band_profile_entry = band_profile_offset + v13;
  v16 = (volatile unsigned int *)off_1010E8;
  *v12 = *v12 & 0xFFFFFF00 | *(volatile uint8_t *)(band_profile_entry + 1);
  v17 = *(volatile uint8_t *)(band_profile_entry + 2);
  v18 = (void *)(uintptr_t)(off_1010EC);
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v19 = (volatile unsigned int *)off_1010C8;
  v12 -= 64;
  *v16 = *v16 & 0xFF00FFFF | 0x2F0000;
  *v12 |= 8u;
  *v12 |= 4u;
  v20 = (void *)(uintptr_t)(off_1010F0);
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  *v18 &= 0xFFFFC7FF;
  *v19 = *v19 & 0xFFFFE3FF | 0x1000;
  v16[19966] = v16[19966] & 0xFFFFF83F | 0x400;
  if ( !v20[1] )
  {
    v21 = (volatile unsigned int *)off_1010F4;
    *v19 = *v19 & 0xFFFFFC7F | 0x100;
    *v21 = *v21 & 0x16000 | 0x8000 | *v21 & 0xFFFE1FFF;
  }
  v22 = (volatile char *)off_1010F8;
  v23 = (volatile unsigned int *)off_1010C8;
  v24 = (void *)(uintptr_t)(off_1010FC);
  v25 = (void *)(uintptr_t)(off_1010D0);
  v26 = (void *)(uintptr_t)(off_101100);
  *(volatile uint32_t *)off_1010F8 |= 0xC00u;
  *v23 = *v23 & 0xFFFFFF87 | 0x48;
  *v24 |= 4u;
  *v25 &= ~2u;
  *v26 |= 0x20000u;
  *(volatile uint32_t *)&v22[-12] = *(volatile uint32_t *)&v22[-12] & 0xFFF8FFFF | 0x20000;
  *(volatile uint32_t *)&v22[-12] = *(volatile uint32_t *)&v22[-12] & 0xFFFFFFF0 | 8;
  v27 = (void *)(uintptr_t)(off_101104);
  v24[1905] = v24[1905] & 0xFFFFE3FF | 0x800;
  *(volatile uint32_t *)((volatile char *)v26 + 0xFFFFFFE8) = *(volatile uint32_t *)((volatile char *)v26 + 0xFFFFFFE8) & 0xFC7FFFFF | 0x1000000;
  *v25 &= ~0x20u;
  *v23 = *v23 & 0xFFF1FFFF | 0x60000;
  while ( !*v27 )
    ;
  result = *(volatile uint32_t *)off_101108 & 1;
  if ( !result )
    result = adc_read_ch0(0);
  *(volatile uint32_t *)off_101104 = 1;
  return result;
}



// rf_analog_disable @ 0x10110c
volatile uint32_t * rf_analog_disable(unsigned int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r4
  volatile unsigned int *v5; // r6
  volatile uint32_t *v6; // r1
  volatile unsigned int *v7; // r5
  volatile unsigned int *v8; // r3
  volatile uint32_t *v9; // r4
  unsigned int v10; // r12
  volatile int *v12; // r0
  int v13; // r3
  volatile int *v14; // r8
  volatile int *v15; // r7
  int v16; // r1
  int v17; // r2
  unsigned int v18; // lr
  int v19; // r10
  int v20; // r1
  volatile unsigned int *v21; // r2
  unsigned int v22; // r0
  uint64_t v23; // r4
  volatile uint32_t *v24; // r3
  volatile unsigned int *v25; // r2
  int v26; // r2
  int v27; // r1
  int v28; // r5
  int v29; // r3
  int v30; // r2
  volatile unsigned int *v31; // r0
  volatile uint8_t *v32; // r4
  volatile uint32_t *v33; // r2
  volatile uint32_t *v34; // r0
  unsigned int v35; // r3
  volatile unsigned int *v36; // r2
  volatile unsigned int *v37; // r1
  volatile uint64_t *v38; // r3
  uint64_t v39; // r0
  int v40; // r5
  volatile uint8_t *v41; // r4
  volatile uint32_t *v42; // r2
  volatile uint32_t *result; // r0
  volatile uint64_t *v44; // r3
  uint64_t v45; // r0
  uint64_t v46; // r0
  int v47; // r2
  int v48; // r2

  v1 = (void *)(uintptr_t)(off_101398);
  v2 = (void *)(uintptr_t)(off_10139C);
  *(volatile uint32_t *)off_101398 &= ~0x400u;
  v3 = (void *)(uintptr_t)(off_1013A0);
  v4 = (void *)(uintptr_t)(off_1013A4);
  v5 = (volatile unsigned int *)off_1013A8;
  *v1 &= ~0x800u;
  *v3 |= 4u;
  v6 = (void *)(uintptr_t)(off_1013AC);
  *v4 |= 0x80000u;
  *v4 &= ~0x100000u;
  *v2 |= 0x400u;
  *v2 &= ~0x100u;
  *v2 |= 0x80u;
  v7 = (volatile unsigned int *)off_1013B0;
  v1[16] |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  v4[4] |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  v4[24] &= ~0x8000u;
  v4[24] |= 0x4000u;
  *v5 = *v5 & 0xFFF9FFFF | 0x20000;
  *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFC0) = *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFC0) & 0xFFFFE3FF | 0x800;
  v4[7] = v4[7] & 0xFC7FFFFF | 0x1000000;
  v8 = (volatile unsigned int *)off_1013B4;
  *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v9 = (void *)(uintptr_t)(off_1013B8);
  v1[16] = v1[16] & 0xFFFFFF87 | 0x48;
  v7 -= 1921;
  *v8 &= ~1u;
  *v7 |= 8u;
  *v7 |= 4u;
  *v8 &= ~2u;
  *v9 &= ~0x20000u;
  v10 = (uint16_t)(a1 - 5000);
  *v8 |= 0x20u;
  if ( v10 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v14 = (volatile int *)off_1015FC;
        v15 = (volatile int *)off_1015E4;
        v13 = dword_1015E8;
        v16 = dword_1015EC;
        v47 = dword_1015F0;
        *(volatile uint32_t *)off_1015E0 = dword_1015E8;
        *v14 = v47;
        *v15 = v16;
        v18 = 0x80000000;
        v19 = 1610612736;
        goto LABEL_4;
      }
      if ( a1 <= 0x1612 )
      {
        v14 = (volatile int *)off_1013F0;
        v15 = (volatile int *)off_1013C4;
        v13 = dword_1013E4;
        v16 = dword_1013E8;
        v30 = dword_1013EC;
        *(volatile uint32_t *)off_1013BC = dword_1013E4;
        *v14 = v30;
        *v15 = v16;
        v18 = 0;
        v19 = 1610612736;
        goto LABEL_4;
      }
      v12 = (volatile int *)off_1015E0;
      v13 = dword_1015E8;
      v14 = (volatile int *)off_1015FC;
      v15 = (volatile int *)off_1015E4;
      v16 = dword_1015EC;
      if ( a1 <= 0x1662 )
      {
        v48 = dword_1015F4;
        *(volatile uint32_t *)off_1015E0 = dword_1015E8;
        *v14 = v48;
        *v15 = v16;
        v18 = 0;
        v19 = 0x40000000;
        goto LABEL_4;
      }
      v17 = dword_1015F8;
    }
    else
    {
      v12 = (volatile int *)off_1013BC;
      v13 = dword_1013C0;
      v14 = (volatile int *)off_1013F0;
      v15 = (volatile int *)off_1013C4;
      v16 = dword_1013C8;
      v17 = dword_1013E0;
    }
  }
  else
  {
    v12 = (volatile int *)off_1013BC;
    v13 = dword_1013C0;
    v14 = (volatile int *)off_1013F0;
    v15 = (volatile int *)off_1013C4;
    v16 = dword_1013C8;
    v17 = dword_1013CC;
  }
  *v12 = v13;
  v18 = 0;
  *v14 = v17;
  *v15 = v16;
  v19 = 0;
LABEL_4:
  v20 = v16 + 4;
  v21 = (volatile unsigned int *)v13;
  do
  {
    if ( v10 > 0x140 )
    {
      v22 = v21[1] & 0xFFFFFFFE;
      *v21 = *v21 & 0x1FFFFFFF | v19 | v18;
      v21[1] = v22;
      v23 = *(volatile uint64_t *)(v20 - 4);
      v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(v23 & 0x1FFFFFFF | v19 | v18) & 0xFFFFFFFFu);
      v23 = (v23 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v23 >> 32) & 0xFFFFFFFFu) & (uint32_t)(~1u))) << 32;;
      *(volatile uint64_t *)(v20 - 4) = v23;
    }
    v21 += 3;
    v20 += 12;
  }
  while ( (volatile unsigned int *)(v13 + 192) != v21 );
  sub_102d10(1, 0, 16, v13);
  sub_102d10(1, 16, 16, *v14);
  sub_102d10(1, 32, 16, *v15);
  radio_init(1, a1);
  v24 = (void *)(uintptr_t)(off_1013D0);
  v25 = (volatile unsigned int *)off_1013D4;
  *(volatile uint32_t *)off_1013D0 |= 8u;
  *v24 |= 4u;
  *v25 = *v25 & 0xFFFC7FFF | 0x10000;
  *v25 = *v25 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v28 = 10;
    v27 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v28 = 8;
    v27 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v28 = 6;
    v27 = 3;
  }
  else
  {
    if ( a1 <= 0x1571 )
    {
      v26 = *(volatile uint8_t *)off_1013D8;
      v27 = a1 > 0x1486;
      if ( a1 <= 0x1486 )
        v28 = 0;
      else
        v28 = 2;
      if ( v26 == 3 )
        goto LABEL_16;
      goto LABEL_24;
    }
    v28 = 4;
    v27 = 2;
  }
  v26 = *(volatile uint8_t *)off_101584;
  if ( v26 == 3 )
  {
LABEL_16:
    v29 = dword_1013DC;
    goto LABEL_26;
  }
LABEL_24:
  v29 = dword_101588;
  if ( v26 != 7 )
    v29 = 0;
LABEL_26:
  v31 = (volatile unsigned int *)off_101590;
  *(volatile uint32_t *)off_10158C = *(volatile uint32_t *)off_10158C & 0xFFFFFF00 | *(volatile uint8_t *)(v29 + v28);
  v32 = (void *)(uintptr_t)(off_101594);
  *v31 = *v31 & 0xFFFFFF00 | *(volatile uint8_t *)(v29 + v28 + 1);
  if ( !v32[1] )
  {
    v33 = (void *)(uintptr_t)(off_101598);
    v31[1918] &= 0xFFFFFC7F;
    *v33 &= ~0x8000u;
  }
  v34 = (void *)(uintptr_t)(off_1015A0);
  v35 = *(volatile uint32_t *)off_10159C & 0xFF00FFFF;
  if ( v27 <= 1 )
    v35 |= 0x1F0000u;
  *(volatile uint32_t *)off_10159C = v35;
  v36 = (volatile unsigned int *)off_1015A4;
  v37 = (volatile unsigned int *)off_1015A8;
  *v34 &= ~0x4000u;
  *v36 = *v36 & 0xFFF8FFFF | 0x20000;
  *v36 = *v36 & 0xFFFFFFF0 | 8;
  *v37 = *v37 & 0xFFF1FFFF | 0x60000;
  if ( a1 <= 0x15E4 )
  {
    v44 = (volatile uint64_t *)off_1015AC;
    if ( a1 <= 0x14D6 )
    {
      v46 = qword_1015D4;
      *((volatile uint32_t *)off_1015AC + 2) = dword_1015DC;
      *v44 = v46;
      v40 = 0;
    }
    else
    {
      v45 = qword_1015C8;
      *((volatile uint32_t *)off_1015AC + 2) = dword_1015D0;
      *v44 = v45;
      v40 = 1;
    }
  }
  else
  {
    v38 = (volatile uint64_t *)off_1015AC;
    v39 = qword_1015B0;
    *((volatile uint32_t *)off_1015AC + 2) = dword_1015B8;
    *v38 = v39;
    v40 = 2;
  }
  v41 = (void *)(uintptr_t)(off_1015BC);
  if ( *(volatile uint8_t *)off_1015BC != v40 )
    copy_config_struct(0);
  v42 = (void *)(uintptr_t)(off_1015C0);
  *v41 = v40;
  while ( !*v42 )
    ;
  result = (volatile uint32_t *)(*(volatile uint32_t *)off_1015C4 & 1);
  if ( result )
    goto LABEL_40;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = adc_read_ch1();
LABEL_40:
    *(volatile uint32_t *)off_1015C0 = 1;
    return result;
  }
  result = (volatile uint32_t *)adc_read_ch0(0);
  *(volatile uint32_t *)off_1015C0 = 1;
  return result;
}



// llc_event_loop @ 0x101600
int llc_event_loop() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile uint32_t *v2; // r5
  volatile unsigned int *v3; // r1
  volatile unsigned int *v4; // r4
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r6
  volatile uint32_t *v8; // r4
  volatile unsigned int *v9; // r3
  volatile unsigned int *v10; // r2
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r2
  int result; // r0
  int v14; // r1

  if ( **(volatile int16_t **)off_101788 < 0
    && (uint8_t)BYTE2(*(volatile uint32_t *)off_1017D4) + 10 * (HIBYTE(*(volatile uint32_t *)off_1017D4) + 2) != 32 )
  {
    mmio_irq_clear((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  clock_start();
  v0 = (void *)(uintptr_t)(off_101790);
  v1 = (void *)(uintptr_t)(off_101794);
  *(volatile uint32_t *)off_10178C |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(volatile uint32_t *)off_101794 >> 4 == 2 )
    *(volatile uint32_t *)off_101798 = dword_10179C;
  v2 = (void *)(uintptr_t)(off_1017A0);
  v3 = (volatile unsigned int *)off_1017A4;
  v4 = (volatile unsigned int *)off_1017A8;
  v5 = (void *)(uintptr_t)(off_1017AC);
  v6 = (void *)(uintptr_t)(off_1017B0);
  v7 = (void *)(uintptr_t)(off_10178C);
  *(volatile uint32_t *)off_1017A0 = *(volatile uint32_t *)off_1017A0 & 0xFFFFF800 | 0x700;
  *v3 = 256;
  *v4 = *v4 & 0xFFFFE000 | 0x580;
  *v5 |= 0x10000u;
  *v5 |= 0x10000000u;
  *v5 |= 2u;
  v2 -= 236;
  *v6 |= 2u;
  *v2 = 1;
  v8 = (void *)(v4 + 16846);
  *v5 &= 0xFFFFFF8F;
  *v8 = 1;
  *v3 = *v3 & 0xFFFFFCFF | 0x100;
  v2 -= 10753;
  *v7 |= 0x8000000u;
  v9 = (volatile unsigned int *)off_1017B4;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v10 = (volatile unsigned int *)off_1017B8;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = (void *)(uintptr_t)(off_1017C0);
  v12 = (void *)(uintptr_t)(off_1017C4);
  result = dword_1017CC;
  *(volatile uint32_t *)off_1017BC = dword_1017C8;
  *v11 = result;
  v14 = BYTE2(((volatile uint32_t *)(uintptr_t)off_1017D0)[101]);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
  return result;
}


// rf_irq_check @ 0x1017e0
int rf_irq_check(int result, int a2, int a3) {
  if ( (*(volatile uint32_t *)off_1017F8 & 8) != 0 )
  {
    result = (int)(uintptr_t)(timer_timestamp_get(result, a2, a3, *(volatile uint32_t *)off_1017F8 << 28));
    *(volatile uint32_t *)off_1017FC = 8;
  }
  return result;
}



// sys_status_read @ 0x101800
volatile uint32_t * sys_status_read(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_101814);
  *result = *(volatile uint32_t *)off_101810;
  *a2 = *v2;
  return result;
}



// timer_count_read @ 0x101818
volatile uint64_t * timer_count_read(volatile uint64_t *result, int a2) {
  volatile uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (volatile uint64_t *)ke_event_schedule_1("\x9B\x87%s: radio %d does not exist\n", aPhyGetChannel, a2);
    *v2 = *(volatile uint64_t *)((volatile char *)off_101840 + 36);
  }
  else
  {
    *result = *(volatile uint64_t *)((volatile char *)off_101840 + 36);
  }
  return result;
}


// sys_irq_dispatch @ 0x10184c
int sys_irq_dispatch(int a1, int a2, int a3) {
  if ( *(volatile uint32_t *)off_101860 << 28 )
    return ke_event_schedule_1("\x9B%s MAC state != IDLE\n", aPhyStop);
  return a1;
}


// return_1000 @ 0x10186c
int return_1000() {
  return 1000;
}



// return_one @ 0x101874
/* luna: Returns the integer constant 1. */
int return_one() {
  return 1;
}



// sys_status_get_bit21 @ 0x101878
/* luna: Returns bit 21 of the system status register. */
int sys_status_get_bit21() {
  return (*(volatile uint32_t *)off_101884 >> 21) & 1;
}



// rf_calibration_done @ 0x101888
BOOL rf_calibration_done() {
  return *(volatile uint32_t *)off_101898 > 1u;
}



// rf_control_set_bit3 @ 0x10189c
unsigned int rf_control_set_bit3(int a1) {
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(volatile uint32_t *)off_1018B0 & 0xFFFFFFF7;
  *(volatile uint32_t *)off_1018B0 = result;
  return result;
}



// sys_status_get_bit26 @ 0x1018b4
/* luna: Returns bit 26 of the system status register. */
int sys_status_get_bit26() {
  return (*(volatile uint32_t *)off_1018C0 >> 26) & 1;
}



// sys_status_get_bit28 @ 0x1018c4
/* luna: Returns bit 28 of the system status register. */
int sys_status_get_bit28() {
  return (*(volatile uint32_t *)off_1018D0 >> 28) & 1;
}



// sys_status_get_bit30 @ 0x1018d4
/* luna: Returns bit 30 of the system status register. */
int sys_status_get_bit30() {
  return (*(volatile uint32_t *)off_1018E0 >> 30) & 1;
}



// rf_config_write @ 0x1018e4
volatile uint32_t * rf_config_write(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_101900);
  *(volatile uint32_t *)off_101900 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}



// rf_channel_set @ 0x101904
int rf_channel_set(int16_t a1) {
  int v1; // r4
  volatile uint32_t *v2; // r1
  volatile int *v3; // r2
  int result; // r0

  v1 = dword_101934;
  v2 = (void *)(uintptr_t)(off_101938);
  v3 = (volatile int *)off_10193C;
  result = a1 & 0x7FF;
  *(volatile uint32_t *)off_101930 = *(volatile uint32_t *)off_101930 & dword_101934 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}



// sys_mode_get @ 0x101940
int sys_mode_get() {
  return (uint8_t)((BYTE1(*(volatile uint32_t *)off_101950) & 0xF) - 1);
}



// irq47_status_handler @ 0x101954
int irq47_status_handler() {
  return (uint8_t)(((uint8_t)*(volatile uint32_t *)off_101964 >> 4) - 1);
}



// sys_mode_get_low @ 0x101968
int sys_mode_get_low() {
  return (uint8_t)((*(volatile uint8_t *)off_101978 & 0xF) - 1);
}



// llm_task_handler @ 0x10197c
int llm_task_handler(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int result; // r0
  unsigned int v5; // r10
  int v7; // r9
  int v8; // r6
  char v9; // r8
  char v10; // r11
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r6
  char v16; // r8
  unsigned int v17; // r3
  char v18; // r3
  int v19; // r2
  int v20; // r2
  int v21; // r3
  unsigned int v22; // [sp+4h] [bp-8h]

  result = *((volatile uint8_t *)off_101BA4 + 36);
  v5 = *((volatile uint16_t *)off_101BA4 + 20);
  if ( !*((volatile uint8_t *)off_101BA4 + 36) )
  {
    if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_101BA8)[49]) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101BA8)[49]);
      v8 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101BA8)[52]);
      v9 = *(volatile uint8_t *)(off_101BB0 + 0xA) + *(volatile uint8_t *)off_101BB4 + *(volatile uint8_t *)(*(volatile uint32_t *)off_101BAC + result + 6);
      v10 = *(volatile uint8_t *)off_101BB4 + *(volatile uint8_t *)(off_101BB0 + 8) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101BAC + result);
      v11 = v10;
      if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101BA8)[99]) )
      {
        result = *(volatile uint8_t *)(*(volatile uint32_t *)off_101BB8 + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (((volatile uint32_t *)(uintptr_t)off_101BA8)[98] & 2) != 0 )
      {
        result = (int)llm_adv_state_get(0, *((volatile uint16_t *)off_101BA4 + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(volatile char *)(result + 4);
        }
        else
        {
          if ( **(volatile int16_t **)off_101BC4 < 0 )
          {
            mmio_field_update(off_101BCC, (int)aPhyGetRfGainId, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = ke_event_schedule_1("invalid chan, band=%d, freq=%d\n", 0, v5);
          v11 = v22;
          v20 = 15;
        }
        if ( v7 >= v20 )
          v7 = (v7 & ~0xFFu) | ((uint8_t)(v20) & 0xFFu);
        if ( v8 >= v20 )
          v8 = (v8 & ~0xFFu) | ((uint8_t)(v20) & 0xFFu);
      }
      if ( (v10 & 1) != 0 )
        v12 = v11 - 1;
      else
        v12 = v11 + (v11 >> 31);
      if ( (v10 & 1) != 0 )
        v12 += v12 >> 31;
      if ( (v9 & 1) != 0 )
        v13 = v9 - 1 + ((unsigned int)(v9 - 1) >> 31);
      else
        v13 = v9 + ((unsigned int)v9 >> 31);
      *a2 = (v12 >> 1) + v7;
      *a3 = (v13 >> 1) + v8;
      return result;
    }
    if ( **(volatile int16_t **)off_101BC4 >= 0 )
      return result;
    v19 = 6875;
    return mmio_irq_clear(off_101BCC, (int)aPhyGetRfGainId, v19);
  }
  if ( !BYTE1(((volatile uint32_t *)(uintptr_t)off_101BA8)[49]) )
  {
    if ( **(volatile int16_t **)off_101BC4 >= 0 )
      return result;
    v19 = 6921;
    return mmio_irq_clear(off_101BCC, (int)aPhyGetRfGainId, v19);
  }
  if ( v5 <= 0x1666 )
  {
    if ( v5 > 0x1616 )
    {
      v14 = 4;
    }
    else if ( v5 > 0x15C6 )
    {
      v14 = 3;
    }
    else if ( v5 > 0x1571 )
    {
      v14 = 2;
    }
    else
    {
      v14 = v5 > 0x1486;
    }
  }
  else
  {
    v14 = 5;
  }
  result = LOBYTE(((volatile uint32_t *)(uintptr_t)off_101BA8)[99]);
  v15 = SLOBYTE(((volatile uint32_t *)(uintptr_t)off_101BA8)[59]);
  v16 = *(volatile uint8_t *)(off_101BB4 + 1) + *(volatile uint8_t *)(off_101BB0 + 0xB) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101BBC + v14);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101BA8)[99]) )
    v15 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101BC0 + v14) + v15);
  if ( (((volatile uint32_t *)(uintptr_t)off_101BA8)[98] & 2) != 0 )
  {
    result = (int)llm_adv_state_get(1, *((volatile uint16_t *)off_101BA4 + 20));
    if ( result )
    {
      v21 = *(volatile char *)(result + 4);
    }
    else
    {
      if ( **(volatile int16_t **)off_101BC4 < 0 )
        mmio_field_update(off_101BCC, (int)aPhyGetRfGainId, 6907);
      result = ke_event_schedule_1("invalid chan, band=%d, freq=%d\n", 1, v5);
      v21 = 15;
    }
    if ( v15 >= v21 )
      v15 = (v15 & ~0xFFu) | ((uint8_t)(v21) & 0xFFu);
  }
  if ( (v16 & 1) != 0 )
    v17 = v16 - 1 + ((unsigned int)(v16 - 1) >> 31);
  else
    v17 = v16 + ((unsigned int)v16 >> 31);
  v18 = (v17 >> 1) + v15;
  *a3 = v18;
  *a2 = v18;
  return result;
}


// llm_rx_pdu_handler @ 0x101bd4
int llm_rx_pdu_handler(unsigned int a1, signed int a2, volatile uint8_t *a3) {
  int v3; // r6
  unsigned int v4; // r7
  int v5; // cc
  volatile char *v6; // r0
  signed int v7; // r2
  int v8; // r5
  int v9; // r12
  int v10; // r4
  int v11; // r0
  char v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r0
  volatile char *v16; // r2
  signed int v17; // r0
  signed int v18; // r2
  int v19; // r12
  int v20; // r4
  int v21; // r0
  volatile char *v22; // r0
  int v23; // r3

  v3 = *a3;
  v4 = *((volatile uint16_t *)a3 + 2);
  if ( !*a3 )
  {
    if ( a1 <= 1 )
    {
      v8 = *((volatile char *)&((volatile uint32_t *)(uintptr_t)off_101D78)[49] + a2 + 2);
      if ( !a1 && (unsigned int)a2 <= 3 )
      {
        v9 = *a3;
        v10 = v9;
        goto LABEL_12;
      }
      v7 = 9;
    }
    else
    {
      v5 = a1 > 4;
      v6 = (volatile char *)off_101D78 + a2;
      v7 = 2;
      if ( v5 )
        v8 = v6[220];
      else
        v8 = v6[210];
    }
    if ( v7 < a2 )
      v9 = 3;
    else
      v9 = 6;
    if ( v7 < a2 )
      v10 = 1;
    else
      v10 = 2;
LABEL_12:
    if ( v4 <= 0x97B )
    {
      v11 = 0;
    }
    else if ( v4 > 0x994 )
    {
      v11 = 2;
    }
    else
    {
      v11 = 1;
    }
    v12 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101D7C + v11 + v9) + *(volatile uint8_t *)(dword_101D80 + v10 + 8) + *(volatile uint8_t *)off_101D84;
    v13 = v12;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101D78)[99]) )
      v8 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101D88 + v11) + v8);
    goto LABEL_18;
  }
  v16 = (volatile char *)off_101D78 + a2;
  if ( a1 <= 1 )
  {
    v8 = v16[232];
    v17 = 11;
    v18 = 7;
  }
  else
  {
    if ( a1 > 4 )
      v8 = v16[254];
    else
      v8 = v16[244];
    v17 = 7;
    v18 = 4;
  }
  if ( v18 >= a2 )
  {
    v19 = 0;
    v20 = 0;
  }
  else
  {
    if ( v17 < a2 )
      v19 = 6;
    else
      v19 = 12;
    if ( v17 < a2 )
      v20 = 1;
    else
      v20 = 2;
  }
  if ( v4 > 0x1666 )
  {
    v21 = 5;
  }
  else if ( v4 > 0x1616 )
  {
    v21 = 4;
  }
  else if ( v4 > 0x15C6 )
  {
    v21 = 3;
  }
  else if ( v4 <= 0x1571 )
  {
    v21 = v4 > 0x1486;
  }
  else
  {
    v21 = 2;
  }
  v12 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101D8C + v21 + v19) + *(volatile uint8_t *)(dword_101D80 + v20 + 11) + *(volatile uint8_t *)(off_101D84 + 1);
  v13 = v12;
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101D78)[99]) )
    v8 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101D90 + v21) + v8);
LABEL_18:
  if ( (((volatile uint32_t *)(uintptr_t)off_101D78)[98] & 2) != 0 )
  {
    v22 = llm_adv_state_get(v3, v4);
    if ( v22 )
    {
      v23 = v22[4];
    }
    else
    {
      if ( **(volatile int16_t **)off_101D94 < 0 )
        mmio_field_update(off_101DA0, (int)aPhyGetTxpwrLev, 7022);
      ke_event_schedule_1("invalid chan, band=%d, freq=%d\n", v3, v4);
      v23 = 15;
    }
    if ( v8 >= v23 )
      v8 = (v8 & ~0xFFu) | ((uint8_t)(v23) & 0xFFu);
  }
  if ( (v12 & 1) != 0 )
    v14 = v13 - 1 + ((v13 - 1) >> 31);
  else
    v14 = v13 + (v13 >> 31);
  return (char)((v14 >> 1) + v8);
}


// rf_tx_power_set @ 0x101da4
int rf_tx_power_set(int result) {
  volatile uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = (void *)(uintptr_t)(off_101DE4);
  *(volatile uint32_t *)off_101DE0 = *(volatile uint32_t *)off_101DE0 & 0xFFFFFF | ((uint8_t)(result / 2) << 24);
  v2 = *v1 & 0xFFFFF0FF;
  if ( (result & 1) != 0 )
  {
    if ( result >= 0 )
      v3 = v2 | 0xB00;
    else
      v3 = v2 | 0x500;
    *v1 = v3;
  }
  else
  {
    *v1 = v2 | 0x800;
  }
  return result;
}



