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
/* luna: Fills the requested byte range with the specified byte value and returns the original destination pointer. */
volatile int * memset(volatile int *result, uint8_t a2, unsigned int a3) {
  unsigned int remaining_length; // r4
  volatile int *current_destination; // r3
  int fill_word; // r5
  volatile uint8_t *bulk_store_pointer; // r2
  volatile int *word_tail_pointer; // r2
  int tail_length; // r6
  volatile int *tail_end; // r4

  if ( (uint32_t)result << 30 )
  {
    remaining_length = a3 - 1;
    if ( !a3 )
      return result;
    current_destination = result;
    while ( 1 )
    {
      *(volatile uint8_t *)current_destination = a2;
      current_destination = (volatile int *)((volatile char *)current_destination + 1);
      if ( !((uint32_t)current_destination << 30) )
        break;
      if ( remaining_length-- == 0 )
        return result;
    }
  }
  else
  {
    remaining_length = a3;
    current_destination = result;
  }
  if ( remaining_length > 3 )
  {
    fill_word = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
    if ( remaining_length <= 0xF )
    {
      word_tail_pointer = current_destination;
      tail_length = remaining_length;
    }
    else
    {
      bulk_store_pointer = (void *)(current_destination + 4);
      do
      {
        *((volatile uint32_t *)bulk_store_pointer - 4) = fill_word;
        *((volatile uint32_t *)bulk_store_pointer - 3) = fill_word;
        *((volatile uint32_t *)bulk_store_pointer - 2) = fill_word;
        *((volatile uint32_t *)bulk_store_pointer - 1) = fill_word;
        bulk_store_pointer += 16;
      }
      while ( bulk_store_pointer != (volatile char *)current_destination + ((remaining_length - 16) & 0xFFFFFFF0) + 32 );
      word_tail_pointer = &current_destination[4 * ((remaining_length - 16) >> 4) + 4];
      tail_length = remaining_length & 0xF;
      if ( (remaining_length & 0xC) == 0 )
      {
        remaining_length &= 0xFu;
        current_destination = word_tail_pointer;
        if ( !tail_length )
          return result;
        goto LABEL_16;
      }
    }
    current_destination = (volatile int *)((volatile char *)word_tail_pointer + ((tail_length - 4) & 0xFFFFFFFC) + 4);
    do
      *word_tail_pointer++ = fill_word;
    while ( current_destination != word_tail_pointer );
    remaining_length = tail_length & 3;
  }
  if ( !remaining_length )
    return result;
LABEL_16:
  tail_end = (volatile int *)((volatile char *)current_destination + remaining_length);
  do
  {
    *(volatile uint8_t *)current_destination = a2;
    current_destination = (volatile int *)((volatile char *)current_destination + 1);
  }
  while ( tail_end != current_destination );
  return result;
}



// mac_event_handler @ 0x1002a0
int mac_event_handler(int a1, int a2, int a3, int a4) {
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
  debug_printf("stk_start=%x, ptr_bss=%x\n", v11, v14);
  if ( **v21 < 0 && v14 >= v11 )
    irq_disable_mmio_write((int)aPtrBssStartSta, (int)aPostponedArray, 120);
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
  result = debug_printf("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_100430, dword_100450, v35);
  if ( **v21 < 0 && v35 >= v39 )
    result = irq_disable_mmio_write((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
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
      return debug_printf("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_10045C, v43);
  }
  return result;
}


// mac_state_init @ 0x100478
void mac_state_init() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r5
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r2
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r1
  volatile uint32_t *v7; // r3
  volatile uint8_t *v8; // r6
  int v9; // r0
  int v10; // r1
  volatile uint32_t *v11; // r2
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3

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
  mac_event_handler((int)(v0 + 44), (int)v6, (int)v0 + 178, (int)v5);
  if ( *(volatile uint8_t *)*v1 == 1 )
  {
    v7 = (void *)(uintptr_t)(off_10058C);
    *((volatile uint32_t *)off_100588 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  v8 = (void *)(uintptr_t)(off_100594);
  *((volatile uint8_t *)off_100594 + 2) = (*(volatile uint32_t *)off_100590 & 0xF) == 10;
  debug_assert();
  power_domain_enable();
  rx_copy_stats();
  v9 = system_init();
  if ( *((volatile uint8_t *)v0 + 363) )
  {
    read_global_signed_flag(v9, v10);
    set_flag_send_event_42e();
  }
  alloc_tx_event("hosttype=%d, asic_ver=0x%x\r\n", *((volatile uint8_t *)v0 + 76), *(volatile uint8_t *)off_100598);
  get_rx_stats();
  rf_get_state();
  if ( v8[2] )
  {
    get_config_c();
    v11 = (void *)(uintptr_t)(off_100590);
    *(volatile uint32_t *)off_1005A0 &= ~8u;
    *v11 &= 0xFFFFFFF0;
    v12 = check_feature_flag(2, aWakeup);
  }
  else
  {
    v12 = check_feature_flag(2, aWifimain);
  }
  v15 = *(volatile uint8_t *)*v1;
  if ( v15 == 3 )
  {
    v15 = off_1005A8;
    v14 = 1;
    *(volatile uint32_t *)off_1005A8 = 1;
  }
  ll_init_tables(v12, v13, v14, v15);
}


// chip_identify @ 0x1005b0
int chip_identify(int a1) {
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(volatile uint32_t *)off_100634;
  v3 = *(volatile uint32_t *)off_100634;
  v4 = return_true();
  v5 = rf_status_bit21();
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
      irq_disable_mmio_write(dword_100640, dword_10063C, 434);
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



// mmio_read32 @ 0x100644
/* luna: Busy-waits until the hardware counter reaches its current value plus the requested number of ticks, then returns that deadline. */
int mmio_read32(int a1) {
  int result; // r0
  int spin_count; // [sp+4h] [bp-8h]

  result = a1 + *((volatile uint32_t *)off_10066C + 4);
  do
  {
    spin_count = 32;
    while ( spin_count-- )
      ;
  }
  while ( (int)(*((volatile uint32_t *)off_10066C + 4) - result) < 0 );
  return result;
}



// variant_update_cache @ 0x100670
/* luna: Identifies the chip, updates the cached chip identifier if it changed, and returns the identifier. */
int variant_update_cache(int a1) {
  int result; // r0

  result = chip_identify(a1);
  if ( *(volatile uint8_t *)off_100684 != result )
    *(volatile uint8_t *)off_100684 = result;
  return result;
}



// hw_config_init @ 0x100688
int hw_config_init() {
  volatile int *v0; // r4
  int v1; // r5
  int result; // r0
  int16_t v3; // r2

  v0 = (volatile int *)off_1006C0;
  v1 = chip_identify(HIBYTE(*(volatile uint32_t *)off_1006BC) & 3);
  memset(v0, 0, 8u);
  result = dword_1006C4 + 16 * v1;
  v3 = *(volatile uint16_t *)(result + 6);
  *(volatile uint32_t *)off_1006C8 = *(volatile uint16_t *)(result + 4);
  *((volatile uint8_t *)v0 + 1) = v3;
  *(volatile uint8_t *)v0 = -1;
  return result;
}



// global_state_get_byte @ 0x1006cc
int global_state_get_byte() {
  return *((volatile uint8_t *)off_1006D4 + 1);
}



// mmio_write_cmd @ 0x1006d8
/* luna: Writes 17 to the configured MMIO register, waits for the timer to advance 10 ticks, clears the register, then waits another 10 ticks. */
void mmio_write_cmd() {
  volatile unsigned int initial_timer; // r0
  unsigned int first_deadline; // r0
  int first_timer_delta; // r2
  volatile unsigned int second_timer; // r1
  unsigned int second_deadline; // r1
  int second_timer_delta; // r3
  int first_spin_count; // [sp+0h] [bp-Ch]
  int second_spin_count; // [sp+4h] [bp-8h]

  *(volatile uint32_t *)dword_100728 = 17;
  initial_timer = (*(volatile uint32_t *)0x40501010u);
  first_deadline = initial_timer + 10;
  do
  {
    first_spin_count = 32;
    while ( first_spin_count-- )
      ;
    first_timer_delta = (*(volatile uint32_t *)0x40501010u) - first_deadline;
  }
  while ( first_timer_delta < 0 );
  *(volatile uint32_t *)dword_100728 = 0;
  second_timer = (*(volatile uint32_t *)0x40501010u);
  second_deadline = second_timer + 10;
  do
  {
    second_spin_count = 32;
    while ( second_spin_count-- )
      ;
    second_timer_delta = (*(volatile uint32_t *)0x40501010u) - second_deadline;
  }
  while ( second_timer_delta < 0 );
}


// mmio_set_bit @ 0x100730
volatile uint32_t *mmio_set_bit() {
  volatile uint32_t *result; // r0
  volatile int *v1; // r2

  result = (void *)(uintptr_t)(off_100764);
  v1 = (volatile int *)off_100768;
  *(volatile uint32_t *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}



// mmio_clear_bit @ 0x10076c
volatile uint32_t *mmio_clear_bit() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2

  result = (void *)(uintptr_t)(off_10079C);
  v1 = (volatile unsigned int *)off_1007A0;
  *(volatile uint32_t *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}



// memcpy_opt @ 0x1007a4
int memcpy_opt(int result, int a2, int a3, unsigned int a4) {
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



// mmio_poll @ 0x100898
int mmio_poll(int a1, unsigned int a2, volatile uint32_t *a3) {
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



// sdio_irq_enable @ 0x1009a0
int sdio_irq_enable(int a1, unsigned int a2) {
  volatile unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (volatile unsigned int *)off_1009D4;
  v3 = mmio_poll(a1, a2, (void *)(&v6));
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = memcpy_opt(v3, dword_1009D8, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}



// sdio_irq_mask_enable @ 0x1009dc
int sdio_irq_mask_enable(int a1, int a2) {
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
    rf_enable_switch((2 * i) & 0xFE, *(volatile uint32_t *)(a2 + 8 * i));
    v17 = *(volatile uint32_t *)(a2 + 4 + 8 * i);
    result = rf_enable_switch(v15, v17);
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



// pmu_init @ 0x100b14
/* luna: Initializes PMU MMIO registers, encoding the supplied value into a register field and enabling several control bits. */
volatile uint32_t * pmu_init(int a1) {
  uint64_t v1; // r0
  uint64_t v2; // r2
  volatile unsigned int *pmu_field_reg; // r5
  volatile unsigned int *pmu_control_reg; // r4
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint16_t v7; // r0
  volatile uint32_t *pmu_control_reg2; // r2
  volatile uint32_t *pmu_config_reg; // r1
  volatile uint32_t *result; // r0
  volatile uint8_t *pmu_enable_byte; // r5

  v1 = signed_int_to_double(a1);
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_100B74) << 32);
  pmu_field_reg = (volatile unsigned int *)off_100B78;
  pmu_control_reg = (volatile unsigned int *)off_100B7C;
  v2 = (v2 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v5 = ((uint64_t (*)())double_divide)(v1, v2);
  v6 = double_exp_check(v5);
  v7 = ((int (*)(uint64_t))double_to_uint32)(v6);
  pmu_control_reg2 = (void *)(uintptr_t)(off_100B80);
  pmu_config_reg = (void *)(uintptr_t)(off_100B84);
  *pmu_field_reg = (uint16_t)(v7 << 8) | *pmu_field_reg & 0xFFFF00FF;
  result = (void *)(uintptr_t)(off_100B88);
  pmu_enable_byte = (void *)(uintptr_t)(off_100B8C);
  *pmu_control_reg = *pmu_control_reg & 0xFFFFF9FF | 0x200;
  *pmu_control_reg2 |= 0x40000000u;
  *pmu_control_reg2 |= 0x80000000;
  *pmu_config_reg = 4096;
  *result |= 0x1000u;
  *pmu_enable_byte = 1;
  return result;
}


// radio_clock_disable @ 0x100b90
/* luna: Clears radio-related clock and control bits in several MMIO registers and zeros a final control byte. */
volatile uint32_t *radio_clock_disable() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r1
  volatile uint8_t *v3; // r4

  v0 = (void *)(uintptr_t)(off_100BD0);
  result = (void *)(uintptr_t)(off_100BD4);
  v2 = (void *)(uintptr_t)(off_100BD8);
  v3 = (void *)(uintptr_t)(off_100BDC);
  *(volatile uint32_t *)off_100BCC &= 0xFFFFF9FF;
  *v0 &= ~0x40000000u;
  *v0 &= ~0x80000000;
  *result &= ~0x1000u;
  *v2 &= 0xCFFFFFFF;
  *v3 = 0;
  return result;
}



// save_and_call_handler @ 0x100be0
void save_and_call_handler(int a1, int a2, int a3, int a4, char a5) {
  volatile int *v5; // r8
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r1
  volatile char *v12; // r2
  volatile uint32_t *v13; // r2
  volatile uint32_t *v14; // r1
  int v15; // r3
  volatile char *v16; // r0
  volatile unsigned int *v17; // r5
  volatile unsigned int *v18; // r1
  int v19; // r2
  volatile unsigned int *v20; // r1
  volatile char *v21; // r0
  volatile unsigned int *v22; // r2
  int v23; // r3
  int v24; // r2
  volatile unsigned int *v25; // r1
  volatile unsigned int *v26; // r2
  volatile unsigned int *v27; // r2
  volatile uint32_t *v28; // r1
  volatile uint32_t *v29; // r2
  volatile uint32_t *v30; // r1
  int v31; // r2

  v5 = (volatile int *)off_100E20;
  mmio_write_cmd();
  if ( *((volatile uint8_t *)v5 + 413) && *(volatile uint8_t *)off_100DE8 )
  {
    radio_clock_disable();
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_100DEC);
    v11 = (void *)(uintptr_t)(off_100DF0);
    *(volatile uint32_t *)off_100DEC &= ~0x800u;
    *v11 &= ~0x20u;
    v10[33] &= ~0x1000u;
  }
  v12 = (volatile char *)off_100DF4;
  *(volatile uint32_t *)off_100DF4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v27 = (volatile unsigned int *)(v12 - 728);
    v28 = (void *)(uintptr_t)(off_100DFC);
    *v27 = *v27 & 0xFFFE3FFF | 0x18000;
    *v28 &= ~1u;
    v27[27857] |= 0x100u;
    if ( (a5 & 4) != 0 )
    {
      if ( *((volatile uint8_t *)v5 + 413) && *(volatile uint8_t *)off_100DE8 )
      {
        pmu_init(a3);
      }
      else
      {
        v29 = (void *)(uintptr_t)(off_100DEC);
        v30 = (void *)(uintptr_t)(off_100DF0);
        *(volatile uint32_t *)off_100DEC |= 0x800u;
        *v30 |= 0x20u;
        v29[33] |= 0x1000u;
      }
      *(volatile uint32_t *)off_100DF4 |= 0x40u;
      if ( a4 != 1 )
        goto LABEL_7;
      goto LABEL_22;
    }
  }
  else
  {
    v13 = (void *)(uintptr_t)(off_100DF8);
    v14 = (void *)(uintptr_t)(off_100DFC);
    *(volatile uint32_t *)off_100DF8 = *(volatile uint32_t *)off_100DF8 & 0xFFFE3FFF | 0xC000;
    *v14 |= 1u;
    v13[27857] &= ~0x100u;
  }
  if ( a4 != 1 )
  {
LABEL_7:
    if ( a4 == 2 )
    {
      v23 = a3 - a2;
      if ( a3 - a2 <= 0 )
      {
        if ( v23 >= -10 )
          v24 = 2;
        else
          v24 = 3;
      }
      else
      {
        v24 = v23 <= 10;
      }
      v15 = ((uint8_t)((int)((uint64_t)((int32_t)dword_100E14 * (int64_t)(int32_t)(a2 - (a3 - 30))) >> 32) >> 3)
           - (uint8_t)((a2 - (a3 - 30)) >> 31))
          & 7;
      *(volatile uint32_t *)off_100E00 = v24;
    }
    else
    {
      v15 = 0;
      *(volatile uint32_t *)off_100E00 = 0;
    }
    goto LABEL_9;
  }
LABEL_22:
  if ( a3 <= (unsigned int)a2 )
    v31 = 2;
  else
    v31 = 1;
  *(volatile uint32_t *)off_100E00 = v31;
  v15 = a3 <= (unsigned int)a2;
LABEL_9:
  v16 = (volatile char *)off_100E04;
  v17 = (volatile unsigned int *)off_100E08;
  v18 = (volatile unsigned int *)off_100E0C;
  *(volatile uint32_t *)off_100E04 = v15 | *(volatile uint32_t *)off_100E04 & 0xFFFFFFF8;
  v19 = (a4 << 24) & 0x3000000;
  *v17 = *v17 & 0xFCFFFFFF | v19;
  *v18 = (a4 << 16) & 0x30000 | *v18 & 0xFFFCFFFF;
  v20 = v18 + 16708;
  *(volatile uint32_t *)&v16[-80] = *(volatile uint32_t *)&v16[-80] & 0xFFFFFFF0 | a4 & 0xF;
  v21 = v16 - 80;
  *v20 = v19 | *v20 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      v25 = (volatile unsigned int *)off_100E1C;
      v26 = (volatile unsigned int *)off_100E10;
      *(volatile uint32_t *)off_100E18 = *(volatile uint32_t *)off_100E18 & 0xFFFFFF | 0x18000000;
      *v25 = *v25 & 0xFFFFFFCF | 0x10;
      *v26 = *v26 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v22 = (volatile unsigned int *)off_100E10;
    *((volatile uint32_t *)v21 + 1) = *((volatile uint32_t *)v21 + 1) & 0xFFFFFF | 0x19000000;
    v20[15866] &= 0xFFFFFFCF;
    *v22 = *v22 & 0xFFFF00FF | 0x9C00;
  }
}


// rf_config_read_a @ 0x100e24
int rf_config_read_a(int result) {
  volatile unsigned int *v1; // r3
  volatile uint32_t *v2; // r1
  unsigned int v3; // r5
  volatile uint32_t *v4; // r4
  volatile uint32_t *v5; // r3

  v1 = (volatile unsigned int *)off_100ED8;
  v2 = (void *)(uintptr_t)(off_100EDC);
  v3 = *(volatile uint32_t *)off_100ED8;
  v4 = (void *)(uintptr_t)(off_100EE0);
  *(volatile uint32_t *)off_100EDC = (*(volatile uint8_t *)off_100ED4 << 10) & 0x1FC00 | *(volatile uint32_t *)off_100EDC & 0xFFFE03FF;
  *v1 |= 0x18u;
  *v1 = *v1 & 0xFFFFFFF8 | 4;
  *v2 |= 0x80000u;
  *v2 |= 0x40000u;
  *v1 = *v1 & 0xFFFFFC1F | 0xE0;
  *v4 &= ~2u;
  *v4 |= 1u;
  if ( !result && ((v3 >> 5) & 0x1F) != 7 )
  {
    v5 = (void *)(uintptr_t)(off_100EE4);
    *(volatile uint32_t *)off_100EE4 |= 0x80u;
    *v5 &= ~0x40u;
    *v5 |= 0x40u;
    *v5 &= ~0x80u;
  }
  return result;
}



// rf_config_read_b @ 0x100ee8
volatile uint32_t *rf_config_read_b() {
  volatile unsigned int *v0; // r3
  volatile uint32_t *v1; // r1
  unsigned int v2; // r4
  volatile uint32_t *result; // r0
  volatile uint32_t *v4; // r3

  v0 = (volatile unsigned int *)off_100F9C;
  v1 = (void *)(uintptr_t)(off_100FA0);
  v2 = *(volatile uint32_t *)off_100F9C;
  result = (void *)(uintptr_t)(off_100FA4);
  *(volatile uint32_t *)off_100FA0 = (*((volatile uint8_t *)off_100F98 + 1) << 10) & 0x1FC00 | *(volatile uint32_t *)off_100FA0 & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 0x10;
  *v0 = *v0 & 0xFFFFFFF8 | 1;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = (void *)(uintptr_t)(off_100FA8);
    *(volatile uint32_t *)off_100FA8 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}



// arm_core_enable @ 0x100fac
int arm_core_enable(unsigned int a1, int a2) {
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r4
  int v7; // r1
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r2
  int v11; // r4
  volatile unsigned int *v12; // r0
  int v13; // r2
  volatile unsigned int *v14; // r3
  int v15; // r4
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

  v2 = (void *)(uintptr_t)(off_101210);
  v3 = (void *)(uintptr_t)(off_101214);
  v4 = (void *)(uintptr_t)(off_101218);
  v5 = (void *)(uintptr_t)(off_10121C);
  *(volatile uint32_t *)off_101210 |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = (void *)(uintptr_t)(off_101220);
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) = *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = (void *)(uintptr_t)(off_101224);
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = (void *)(uintptr_t)(off_101228);
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  uart_send_data(1, 0, 16, *v9);
  uart_send_data(1, 16, 16, *(volatile uint32_t *)off_10122C);
  sdio_irq_enable(0, a1);
  if ( a1 > 0x98A )
  {
    v11 = 6;
  }
  else if ( a1 <= 0x97B )
  {
    v11 = 0;
  }
  else
  {
    v11 = 3;
  }
  v12 = (volatile unsigned int *)off_101230;
  v13 = dword_101234;
  v14 = (volatile unsigned int *)off_101238;
  *(volatile uint32_t *)off_101230 = *(volatile uint32_t *)off_101230 & 0xFE01FFFF | (*(volatile uint8_t *)(dword_101234 + v11) << 17);
  v15 = v11 + v13;
  v16 = (volatile unsigned int *)off_10123C;
  *v12 = *v12 & 0xFFFFFF00 | *(volatile uint8_t *)(v15 + 1);
  v17 = *(volatile uint8_t *)(v15 + 2);
  v18 = (void *)(uintptr_t)(off_101240);
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v19 = (volatile unsigned int *)off_10121C;
  v12 -= 64;
  *v16 = *v16 & 0xFF00FFFF | 0x2F0000;
  *v12 |= 8u;
  *v12 |= 4u;
  v20 = (void *)(uintptr_t)(off_101244);
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  *v18 &= 0xFFFFC7FF;
  *v19 = *v19 & 0xFFFFE3FF | 0x1000;
  v16[19966] = v16[19966] & 0xFFFFF83F | 0x400;
  if ( !v20[1] )
  {
    v21 = (volatile unsigned int *)off_101248;
    *v19 = *v19 & 0xFFFFFC7F | 0x100;
    *v21 = *v21 & 0x16000 | 0x8000 | *v21 & 0xFFFE1FFF;
  }
  v22 = (volatile char *)off_10124C;
  v23 = (volatile unsigned int *)off_10121C;
  v24 = (void *)(uintptr_t)(off_101250);
  v25 = (void *)(uintptr_t)(off_101224);
  v26 = (void *)(uintptr_t)(off_101254);
  *(volatile uint32_t *)off_10124C |= 0xC00u;
  *v23 = *v23 & 0xFFFFFF87 | 0x48;
  *v24 |= 4u;
  *v25 &= ~2u;
  *v26 |= 0x20000u;
  *(volatile uint32_t *)&v22[-12] = *(volatile uint32_t *)&v22[-12] & 0xFFF8FFFF | 0x20000;
  *(volatile uint32_t *)&v22[-12] = *(volatile uint32_t *)&v22[-12] & 0xFFFFFFF0 | 8;
  v27 = (void *)(uintptr_t)(off_101258);
  v24[1905] = v24[1905] & 0xFFFFE3FF | 0x800;
  *(volatile uint32_t *)((volatile char *)v26 + 0xFFFFFFE8) = *(volatile uint32_t *)((volatile char *)v26 + 0xFFFFFFE8) & 0xFC7FFFFF | 0x1000000;
  *v25 &= ~0x20u;
  *v23 |= 0xE0000u;
  while ( !*v27 )
    ;
  result = *(volatile uint32_t *)off_10125C & 1;
  if ( !result )
    result = rf_config_read_a(0);
  *(volatile uint32_t *)off_101258 = 1;
  return result;
}



// mmio_ahb_gate_release_n_60 @ 0x101260
volatile uint32_t * mmio_ahb_gate_release_n_60(unsigned int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r3
  volatile unsigned int *v5; // r6
  volatile uint32_t *v6; // r1
  volatile unsigned int *v7; // r5
  volatile unsigned int *v8; // r3
  volatile int *v10; // r6
  volatile int *v11; // r5
  int v12; // r3
  int v13; // r2
  volatile uint32_t *v14; // r3
  volatile unsigned int *v15; // r2
  int v16; // r0
  int v17; // r6
  int v18; // r2
  int v19; // r2
  int v20; // r2
  volatile unsigned int *v21; // r1
  int v22; // r5
  volatile uint8_t *v23; // r2
  volatile uint32_t *v24; // r2
  volatile uint32_t *v25; // r1
  unsigned int v26; // r3
  volatile uint32_t *v27; // r0
  volatile unsigned int *v28; // r2
  volatile uint64_t *v29; // r3
  uint64_t v30; // r0
  int v31; // r6
  volatile uint8_t *v32; // r5
  volatile uint32_t *v33; // r2
  volatile uint32_t *result; // r0
  volatile uint64_t *v35; // r3
  uint64_t v36; // r0
  uint64_t v37; // r0
  int v38; // r2
  int v39; // r2

  v1 = (void *)(uintptr_t)(off_101478);
  *(volatile uint32_t *)off_101478 &= ~0x400u;
  v2 = (void *)(uintptr_t)(off_10147C);
  v3 = (void *)(uintptr_t)(off_101480);
  v4 = (void *)(uintptr_t)(off_101484);
  v5 = (volatile unsigned int *)off_101488;
  *v1 &= ~0x800u;
  *v2 |= 4u;
  v6 = (void *)(uintptr_t)(off_10148C);
  *v3 |= 0x80000u;
  *v3 &= ~0x100000u;
  *v4 |= 0x400u;
  *v4 &= ~0x100u;
  *v4 |= 0x80u;
  v7 = (volatile unsigned int *)off_101490;
  v1[16] |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  v3[4] |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  v3[24] &= ~0x8000u;
  v3[24] |= 0x4000u;
  *v5 = *v5 & 0xFFF9FFFF | 0x40000;
  *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFC0) = *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFC0) & 0xFFFFE3FF | 0x800;
  v3[7] = v3[7] & 0xFC7FFFFF | 0x1000000;
  v8 = (volatile unsigned int *)off_101494;
  *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v1[16] = v1[16] & 0xFFFFFF87 | 0x48;
  v7 -= 1921;
  *v8 &= ~1u;
  *v7 |= 8u;
  *v7 |= 4u;
  *v8 &= ~2u;
  *(volatile unsigned int *)((volatile char *)v5 + 0xFFFFFFD8) &= ~0x20000u;
  *v8 |= 0x20u;
  if ( a1 - 5000 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v10 = (volatile int *)off_101688;
        v11 = (volatile int *)off_10168C;
        v12 = dword_101690;
        v38 = dword_101694;
        *(volatile uint32_t *)off_101684 = dword_101690;
        *v10 = v12;
        *v11 = v38;
      }
      else if ( a1 > 0x1612 )
      {
        v10 = (volatile int *)off_101688;
        v11 = (volatile int *)off_10168C;
        if ( a1 > 0x1662 )
        {
          v12 = dword_1016A0;
          v39 = dword_1016A4;
          *(volatile uint32_t *)off_101684 = dword_1016A0;
        }
        else
        {
          v12 = dword_101698;
          v39 = dword_10169C;
          *(volatile uint32_t *)off_101684 = dword_101698;
        }
        *v10 = v12;
        *v11 = v39;
      }
      else
      {
        v10 = (volatile int *)off_10149C;
        v11 = (volatile int *)off_1014A0;
        v12 = dword_1014BC;
        v19 = dword_1014C0;
        *(volatile uint32_t *)off_101498 = dword_1014BC;
        *v10 = v12;
        *v11 = v19;
      }
    }
    else
    {
      v10 = (volatile int *)off_10149C;
      v11 = (volatile int *)off_1014A0;
      v12 = dword_1014B4;
      v18 = dword_1014B8;
      *(volatile uint32_t *)off_101498 = dword_1014B4;
      *v10 = v12;
      *v11 = v18;
    }
  }
  else
  {
    v10 = (volatile int *)off_10149C;
    v11 = (volatile int *)off_1014A0;
    v12 = dword_1014A4;
    v13 = dword_1014A8;
    *(volatile uint32_t *)off_101498 = dword_1014A4;
    *v10 = v12;
    *v11 = v13;
  }
  uart_send_data(1, 0, 16, v12);
  uart_send_data(1, 16, 16, *v11);
  uart_send_data(1, 32, 16, *v10);
  sdio_irq_enable(1, a1);
  v14 = (void *)(uintptr_t)(off_1014AC);
  v15 = (volatile unsigned int *)off_1014B0;
  *(volatile uint32_t *)off_1014AC |= 8u;
  *v14 |= 4u;
  *v15 = *v15 & 0xFFFC7FFF | 0x10000;
  *v15 = *v15 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v17 = 10;
    v16 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v17 = 8;
    v16 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v17 = 6;
    v16 = 3;
  }
  else if ( a1 > 0x1571 )
  {
    v17 = 4;
    v16 = 2;
  }
  else
  {
    v16 = a1 > 0x1486;
    if ( a1 <= 0x1486 )
      v17 = 0;
    else
      v17 = 2;
  }
  v20 = dword_101630;
  v21 = (volatile unsigned int *)off_101634;
  *(volatile uint32_t *)off_10162C = *(volatile uint32_t *)off_10162C & 0xFFFFFF00 | *(volatile uint8_t *)(dword_101630 + v17);
  v22 = *(volatile uint8_t *)(v20 + v17 + 1);
  v23 = (void *)(uintptr_t)(off_101638);
  *v21 = *v21 & 0xFFFFFF00 | v22;
  if ( !v23[1] )
  {
    v24 = (void *)(uintptr_t)(off_10163C);
    v21[1918] &= 0xFFFFFC7F;
    *v24 &= ~0x8000u;
  }
  v25 = (void *)(uintptr_t)(off_101644);
  v26 = *(volatile uint32_t *)off_101640 & 0xFF00FFFF;
  if ( v16 <= 1 )
    v26 |= 0x1F0000u;
  v27 = (void *)(uintptr_t)(off_101648);
  *(volatile uint32_t *)off_101640 = v26;
  v28 = (volatile unsigned int *)off_10164C;
  *v27 &= ~0x4000u;
  *v28 = *v28 & 0xFFF8FFFF | 0x20000;
  *v28 = *v28 & 0xFFFFFFF0 | 8;
  *v25 |= 0xE0000u;
  if ( a1 <= 0x15E4 )
  {
    v35 = (volatile uint64_t *)off_101650;
    if ( a1 <= 0x14D6 )
    {
      v37 = qword_101678;
      *((volatile uint32_t *)off_101650 + 2) = dword_101680;
      *v35 = v37;
      v31 = 0;
    }
    else
    {
      v36 = qword_10166C;
      *((volatile uint32_t *)off_101650 + 2) = dword_101674;
      *v35 = v36;
      v31 = 1;
    }
  }
  else
  {
    v29 = (volatile uint64_t *)off_101650;
    v30 = qword_101654;
    *((volatile uint32_t *)off_101650 + 2) = dword_10165C;
    *v29 = v30;
    v31 = 2;
  }
  v32 = (void *)(uintptr_t)(off_101660);
  if ( *(volatile uint8_t *)off_101660 != v31 )
    hci_send_command(0);
  v33 = (void *)(uintptr_t)(off_101664);
  *v32 = v31;
  while ( !*v33 )
    ;
  result = (volatile uint32_t *)(*(volatile uint32_t *)off_101668 & 1);
  if ( result )
    goto LABEL_30;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = rf_config_read_b();
LABEL_30:
    *(volatile uint32_t *)off_101664 = 1;
    return result;
  }
  result = (volatile uint32_t *)rf_config_read_a(0);
  *(volatile uint32_t *)off_101664 = 1;
  return result;
}



// is_scan_active @ 0x1016a8
int is_scan_active() {
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

  if ( **(volatile int16_t **)off_101830 < 0
    && (uint8_t)BYTE2(*(volatile uint32_t *)off_10187C) + 10 * (HIBYTE(*(volatile uint32_t *)off_10187C) + 2) != 32 )
  {
    irq_disable_mmio_write((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  mmio_write_cmd();
  v0 = (void *)(uintptr_t)(off_101838);
  v1 = (void *)(uintptr_t)(off_10183C);
  *(volatile uint32_t *)off_101834 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(volatile uint32_t *)off_10183C >> 4 == 2 )
    *(volatile uint32_t *)off_101840 = dword_101844;
  v2 = (void *)(uintptr_t)(off_101848);
  v3 = (volatile unsigned int *)off_10184C;
  v4 = (volatile unsigned int *)off_101850;
  v5 = (void *)(uintptr_t)(off_101854);
  v6 = (void *)(uintptr_t)(off_101858);
  v7 = (void *)(uintptr_t)(off_101834);
  *(volatile uint32_t *)off_101848 = *(volatile uint32_t *)off_101848 & 0xFFFFF800 | 0x700;
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
  v9 = (volatile unsigned int *)off_10185C;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v10 = (volatile unsigned int *)off_101860;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = (void *)(uintptr_t)(off_101868);
  v12 = (void *)(uintptr_t)(off_10186C);
  result = dword_101874;
  *(volatile uint32_t *)off_101864 = dword_101870;
  *v11 = result;
  v14 = BYTE2(((volatile uint32_t *)(uintptr_t)off_101878)[101]);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
  return result;
}


// mmio_wait_bit @ 0x101888
int mmio_wait_bit(int result, int a2, int a3) {
  if ( (*(volatile uint32_t *)off_1018A0 & 8) != 0 )
  {
    result = (int)(uintptr_t)(read_hw_clock(result, a2, a3, *(volatile uint32_t *)off_1018A0 << 28));
    *(volatile uint32_t *)off_1018A4 = 8;
  }
  return result;
}



// copy_hw_register @ 0x1018a8
int copy_hw_register() {
  volatile char *v0; // r2
  int v1; // r1

  v0 = (volatile char *)off_1018CC;
  v1 = *(volatile uint32_t *)off_1018CC;
  *(volatile uint32_t *)off_1018D0 = *(volatile uint32_t *)off_1018CC;
  if ( (v1 & 0x1000) == 0 )
    return alloc_tx_event("no other rc isr: %x\n", v1);
  *(volatile uint32_t *)&v0[-8] &= ~0x1000u;
  return irq_disable_global_2(16);
}


// read_mmio_pair @ 0x1018d8
/* luna: Reads two fixed 32-bit MMIO locations into the caller-provided output pointers and returns the first output pointer. */
volatile uint32_t * read_mmio_pair(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *second_register; // r3

  second_register = (void *)(uintptr_t)(off_1018EC);
  *result = *(volatile uint32_t *)off_1018E8;
  *a2 = *second_register;
  return result;
}



// unknown_1018f0 @ 0x1018f0
/* luna: Copies the stored 64-bit channel value to the output and logs an error when a nonzero radio ID is requested. */
volatile uint64_t * unknown_1018f0(volatile uint64_t *result, int a2) {
  volatile uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (volatile uint64_t *)alloc_tx_event("\x9B\x87%s: radio %d does not exist\n", aPhyGetChannel, a2);
    *v2 = *(volatile uint64_t *)((volatile char *)off_101918 + 36);
  }
  else
  {
    *result = *(volatile uint64_t *)((volatile char *)off_101918 + 36);
  }
  return result;
}


// check_clock_status @ 0x101924
/* luna: Returns the supplied value when the MAC state is idle; otherwise emits the PHY-stop MAC-state error and returns the result of alloc_tx_event. */
int check_clock_status(int a1, int a2, int a3) {
  if ( *(volatile uint32_t *)off_101938 << 28 )
    return alloc_tx_event("\x9B%s MAC state != IDLE\n", aPhyStop);
  return a1;
}


// get_timeout_1000 @ 0x101944
int get_timeout_1000() {
  return 1000;
}



// return_true @ 0x10194c
/* luna: Always returns 1. */
int return_true() {
  return 1;
}



// rf_status_bit21 @ 0x101950
/* luna: Returns bit 21 of the RF status register. */
int rf_status_bit21() {
  return (*(volatile uint32_t *)off_10195C >> 21) & 1;
}



// check_rf_ready @ 0x101960
BOOL check_rf_ready() {
  return *(volatile uint32_t *)off_101970 > 1u;
}



// set_rf_control_bit @ 0x101974
/* luna: Sets bit 3 of the RF control register to the low bit of the supplied value and returns the updated register value. */
unsigned int set_rf_control_bit(int a1) {
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(volatile uint32_t *)off_101988 & 0xFFFFFFF7;
  *(volatile uint32_t *)off_101988 = result;
  return result;
}



// rf_status_bit26 @ 0x10198c
/* luna: Returns bit 26 of the RF status register. */
int rf_status_bit26() {
  return (*(volatile uint32_t *)off_101998 >> 26) & 1;
}



// rf_status_bit28 @ 0x10199c
/* luna: Returns bit 28 of the RF status register. */
int rf_status_bit28() {
  return (*(volatile uint32_t *)off_1019A8 >> 28) & 1;
}



// rf_status_bit30 @ 0x1019ac
/* luna: Returns bit 30 of the RF status register at 0x1019B8. */
int rf_status_bit30() {
  return (*(volatile uint32_t *)off_1019B8 >> 30) & 1;
}



// write_rf_cal_data @ 0x1019bc
/* luna: Copies two words from the first input and four from the second into six consecutive RF calibration storage words at a fixed address. */
volatile uint32_t * write_rf_cal_data(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_1019D8);
  *(volatile uint32_t *)off_1019D8 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}



// set_rf_frequency @ 0x1019dc
/* luna: Writes the requested 11-bit frequency value to an RF register and applies the associated register bit updates. */
int set_rf_frequency(int16_t a1) {
  int register_preserve_mask; // r4
  volatile uint32_t *v2; // r1
  volatile int *v3; // r2
  int result; // r0

  register_preserve_mask = dword_101A0C;
  v2 = (void *)(uintptr_t)(off_101A10);
  v3 = (volatile int *)off_101A14;
  result = a1 & 0x7FF;
  *(volatile uint32_t *)off_101A08 = *(volatile uint32_t *)off_101A08 & dword_101A0C | result;
  *v2 &= register_preserve_mask;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}



// get_rf_field_hi @ 0x101a18
/* luna: Returns the RF high-field value encoded in bits 8–11 of the register, minus one. */
int get_rf_field_hi() {
  return (uint8_t)((BYTE1(*(volatile uint32_t *)off_101A28) & 0xF) - 1);
}



// get_rf_field_mid @ 0x101a2c
/* luna: Reads an RF MMIO register, extracts bits 4–7, and returns the extracted value minus one. */
int get_rf_field_mid() {
  return (uint8_t)(((uint8_t)*(volatile uint32_t *)off_101A3C >> 4) - 1);
}



// get_rf_field_lo @ 0x101a40
/* luna: Returns the low four bits of the RF field register minus one, truncated to 8 bits. */
int get_rf_field_lo() {
  return (uint8_t)((*(volatile uint8_t *)off_101A50 & 0xF) - 1);
}



// bt_event_handler @ 0x101a54
int bt_event_handler(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
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

  result = *((volatile uint8_t *)off_101C7C + 36);
  v5 = *((volatile uint16_t *)off_101C7C + 20);
  if ( !*((volatile uint8_t *)off_101C7C + 36) )
  {
    if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_101C80)[49]) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101C80)[49]);
      v8 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101C80)[52]);
      v9 = *(volatile uint8_t *)(off_101C88 + 0xA) + *(volatile uint8_t *)off_101C8C + *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + result + 6);
      v10 = *(volatile uint8_t *)off_101C8C + *(volatile uint8_t *)(off_101C88 + 8) + *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + result);
      v11 = v10;
      if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101C80)[99]) )
      {
        result = *(volatile uint8_t *)(*(volatile uint32_t *)asc_151880 + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (((volatile uint32_t *)(uintptr_t)off_101C80)[98] & 2) != 0 )
      {
        result = (int)is_adv_enabled(0, *((volatile uint16_t *)off_101C7C + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(volatile char *)(result + 4);
        }
        else
        {
          if ( **(volatile int16_t **)off_101C9C < 0 )
          {
            log_warning(off_101CA4, (int)aPhyGetRfGainId, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = alloc_tx_event("invalid chan, band=%d, freq=%d\n", 0, v5);
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
    if ( **(volatile int16_t **)off_101C9C >= 0 )
      return result;
    v19 = 6875;
    return irq_disable_mmio_write(off_101CA4, (int)aPhyGetRfGainId, v19);
  }
  if ( !BYTE1(((volatile uint32_t *)(uintptr_t)off_101C80)[49]) )
  {
    if ( **(volatile int16_t **)off_101C9C >= 0 )
      return result;
    v19 = 6921;
    return irq_disable_mmio_write(off_101CA4, (int)aPhyGetRfGainId, v19);
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
  result = LOBYTE(((volatile uint32_t *)(uintptr_t)off_101C80)[99]);
  v15 = SLOBYTE(((volatile uint32_t *)(uintptr_t)off_101C80)[59]);
  v16 = *(volatile uint8_t *)(off_101C8C + 1) + *(volatile uint8_t *)(off_101C88 + 0xB) + *(volatile uint8_t *)(*(volatile uint32_t *)a2_0 + v14);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101C80)[99]) )
    v15 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)asc_151884 + v14) + v15);
  if ( (((volatile uint32_t *)(uintptr_t)off_101C80)[98] & 2) != 0 )
  {
    result = (int)is_adv_enabled(1, *((volatile uint16_t *)off_101C7C + 20));
    if ( result )
    {
      v21 = *(volatile char *)(result + 4);
    }
    else
    {
      if ( **(volatile int16_t **)off_101C9C < 0 )
        log_warning(off_101CA4, (int)aPhyGetRfGainId, 6907);
      result = alloc_tx_event("invalid chan, band=%d, freq=%d\n", 1, v5);
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


// rf_get_tx_power @ 0x101cac
/* luna: Computes a rate- and channel-dependent transmit-power setting, applying the channel power limit when enabled. */
int rf_get_tx_power(unsigned int a1, signed int a2, volatile uint8_t *a3) {
  int v3; // r6
  unsigned int frequency_mhz; // r7
  int v5; // cc
  volatile char *v6; // r0
  signed int v7; // r2
  int power_level; // r5
  int v9; // r12
  int v10; // r4
  int v11; // r0
  char v12; // r8
  unsigned int channel_power_offset; // r4
  unsigned int v14; // r0
  volatile char *v16; // r2
  signed int v17; // r0
  signed int v18; // r2
  int v19; // r12
  int v20; // r4
  int frequency_bucket; // r0
  volatile char *channel_info; // r0
  int maximum_channel_power; // r3

  v3 = *a3;
  frequency_mhz = *((volatile uint16_t *)a3 + 2);
  if ( !*a3 )
  {
    if ( a1 <= 1 )
    {
      power_level = *((volatile char *)&((volatile uint32_t *)(uintptr_t)off_101E50)[49] + a2 + 2);
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
      v6 = (volatile char *)off_101E50 + a2;
      v7 = 2;
      if ( v5 )
        power_level = v6[220];
      else
        power_level = v6[210];
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
    if ( frequency_mhz <= 0x97B )
    {
      v11 = 0;
    }
    else if ( frequency_mhz > 0x994 )
    {
      v11 = 2;
    }
    else
    {
      v11 = 1;
    }
    v12 = *(volatile uint8_t *)(*(volatile uint32_t *)asc_151888 + v11 + v9) + *(volatile uint8_t *)(dword_101E58 + v10 + 8) + *(volatile uint8_t *)off_101E5C;
    channel_power_offset = v12;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101E50)[99]) )
      power_level = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)asc_151880 + v11) + power_level);
    goto LABEL_18;
  }
  v16 = (volatile char *)off_101E50 + a2;
  if ( a1 <= 1 )
  {
    power_level = v16[232];
    v17 = 11;
    v18 = 7;
  }
  else
  {
    if ( a1 > 4 )
      power_level = v16[254];
    else
      power_level = v16[244];
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
  if ( frequency_mhz > 0x1666 )
  {
    frequency_bucket = 5;
  }
  else if ( frequency_mhz > 0x1616 )
  {
    frequency_bucket = 4;
  }
  else if ( frequency_mhz > 0x15C6 )
  {
    frequency_bucket = 3;
  }
  else if ( frequency_mhz <= 0x1571 )
  {
    frequency_bucket = frequency_mhz > 0x1486;
  }
  else
  {
    frequency_bucket = 2;
  }
  v12 = *(volatile uint8_t *)(*(volatile uint32_t *)a2_0 + frequency_bucket + v19) + *(volatile uint8_t *)(dword_101E58 + v20 + 11) + *(volatile uint8_t *)(off_101E5C + 1);
  channel_power_offset = v12;
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101E50)[99]) )
    power_level = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)asc_151884 + frequency_bucket) + power_level);
LABEL_18:
  if ( (((volatile uint32_t *)(uintptr_t)off_101E50)[98] & 2) != 0 )
  {
    channel_info = is_adv_enabled(v3, frequency_mhz);
    if ( channel_info )
    {
      maximum_channel_power = channel_info[4];
    }
    else
    {
      if ( **(volatile int16_t **)off_101E6C < 0 )
        log_warning(off_101E78, (int)aPhyGetTxpwrLev, 7022);
      alloc_tx_event("invalid chan, band=%d, freq=%d\n", v3, frequency_mhz);
      maximum_channel_power = 15;
    }
    if ( power_level >= maximum_channel_power )
      power_level = (power_level & ~0xFFu) | ((uint8_t)(maximum_channel_power) & 0xFFu);
  }
  if ( (v12 & 1) != 0 )
    v14 = channel_power_offset - 1 + ((channel_power_offset - 1) >> 31);
  else
    v14 = channel_power_offset + (channel_power_offset >> 31);
  return (char)((v14 >> 1) + power_level);
}


// set_clock_divider @ 0x101e7c
int set_clock_divider(int result) {
  volatile uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = (void *)(uintptr_t)(off_101EBC);
  *(volatile uint32_t *)off_101EB8 = *(volatile uint32_t *)off_101EB8 & 0xFFFFFF | ((uint8_t)(result / 2) << 24);
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



