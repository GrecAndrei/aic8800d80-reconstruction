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
/* luna: Optimized volatile byte-fill utility that aligns the destination and writes repeated 32-bit byte patterns to initialize a memory region. */
volatile int * memset(volatile int *result, uint8_t a2, unsigned int a3) {
  unsigned int remaining_bytes; // r4
  volatile int *dest_ptr; // r3
  int fill_word; // r5
  volatile uint8_t *v7; // r2
  volatile int *word_dest; // r2
  int tail_bytes; // r6
  volatile int *tail_ptr; // r4

  if ( (uint32_t)result << 30 )
  {
    remaining_bytes = a3 - 1;
    if ( !a3 )
      return result;
    dest_ptr = result;
    while ( 1 )
    {
      *(volatile uint8_t *)dest_ptr = a2;
      dest_ptr = (volatile int *)((volatile char *)dest_ptr + 1);
      if ( !((uint32_t)dest_ptr << 30) )
        break;
      if ( remaining_bytes-- == 0 )
        return result;
    }
  }
  else
  {
    remaining_bytes = a3;
    dest_ptr = result;
  }
  if ( remaining_bytes > 3 )
  {
    fill_word = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
    if ( remaining_bytes <= 0xF )
    {
      word_dest = dest_ptr;
      tail_bytes = remaining_bytes;
    }
    else
    {
      v7 = (void *)(dest_ptr + 4);
      do
      {
        *((volatile uint32_t *)v7 - 4) = fill_word;
        *((volatile uint32_t *)v7 - 3) = fill_word;
        *((volatile uint32_t *)v7 - 2) = fill_word;
        *((volatile uint32_t *)v7 - 1) = fill_word;
        v7 += 16;
      }
      while ( v7 != (volatile char *)dest_ptr + ((remaining_bytes - 16) & 0xFFFFFFF0) + 32 );
      word_dest = &dest_ptr[4 * ((remaining_bytes - 16) >> 4) + 4];
      tail_bytes = remaining_bytes & 0xF;
      if ( (remaining_bytes & 0xC) == 0 )
      {
        remaining_bytes &= 0xFu;
        dest_ptr = word_dest;
        if ( !tail_bytes )
          return result;
        goto LABEL_16;
      }
    }
    dest_ptr = (volatile int *)((volatile char *)word_dest + ((tail_bytes - 4) & 0xFFFFFFFC) + 4);
    do
      *word_dest++ = fill_word;
    while ( dest_ptr != word_dest );
    remaining_bytes = tail_bytes & 3;
  }
  if ( !remaining_bytes )
    return result;
LABEL_16:
  tail_ptr = (volatile int *)((volatile char *)dest_ptr + remaining_bytes);
  do
  {
    *(volatile uint8_t *)dest_ptr = a2;
    dest_ptr = (volatile int *)((volatile char *)dest_ptr + 1);
  }
  while ( tail_ptr != dest_ptr );
  return result;
}



// process_state_update @ 0x1002a0
int process_state_update() {
  volatile uint8_t **v0; // r5
  int v1; // r0
  unsigned int v2; // r7
  uint64_t v3; // kr00_8
  uint64_t v4; // kr08_8
  int v5; // r2
  volatile uint32_t *v6; // r3
  unsigned int v7; // r4
  volatile int16_t **v8; // r6
  volatile uint32_t *v9; // r2
  int v10; // r1
  int v11; // r4
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r3
  unsigned int v15; // r3
  unsigned int v16; // r7
  int result; // r0
  volatile uint8_t *v18; // r3
  int v19; // r2
  unsigned int v20; // r2

  v0 = (volatile uint8_t **)off_10038C;
  v1 = dword_100390;
  v2 = dword_100398;
  v3 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10038C + 36);
  v4 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10038C + 44);
  v5 = 44 * *(volatile uint16_t *)(*(volatile uint32_t *)off_10038C + 8) + 44;
  v6 = (void *)(uintptr_t)(off_10039C);
  *(volatile uint32_t *)off_100394 = dword_100390;
  v7 = v5 + v1;
  v8 = (volatile int16_t **)off_1003A0;
  *(volatile uint64_t *)v6 = v3;
  v6[2] = v4;
  v6[3] = HIDWORD(v4);
  log_printf("stk_start=%x, ptr_bss=%x\n", v2, v5 + v1);
  if ( **v8 < 0 && v7 >= v2 )
    flash_ctrl_init((int)aPtrBssStartSta, (int)aPostponedArray, 120);
  v9 = *(volatile uint32_t **)off_1003A8;
  v10 = dword_1003AC;
  v11 = 76 * *((volatile uint16_t *)*v0 + 4) + 76;
  v12 = **(volatile uint32_t **)off_1003A8;
  *(volatile uint32_t *)off_1003B0 = dword_1003AC;
  v13 = v11 + v10;
  if ( !v12 )
  {
    v14 = (v9[1] + 4) & 0xFFFFFFFC;
    *v9 = v13 + 4;
    v13 += v14;
  }
  if ( !v9[2] )
  {
    v15 = (v9[3] + 4) & 0xFFFFFFFC;
    v9[2] = v13 + 4;
    v13 += v15;
  }
  v16 = dword_1003B4;
  result = log_printf("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_1003AC, dword_1003B4, v13);
  if ( **v8 < 0 && v13 >= v16 )
    result = flash_ctrl_init((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
  v18 = *v0;
  *(volatile uint32_t *)off_1003BC = *((volatile uint32_t *)*v0 + 3);
  v19 = *v18;
  if ( v19 == 2 )
  {
    v20 = *((volatile uint32_t *)v18 + 4);
  }
  else
  {
    if ( v19 != 1 )
      return result;
    v20 = *((volatile uint32_t *)v18 + 5);
  }
  if ( v20 )
  {
    if ( dword_1003C0 > v20 )
      return log_printf("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_1003C0, v20);
  }
  return result;
}


// init_buffer_list @ 0x1003d4
void init_buffer_list() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r5
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r6
  volatile uint32_t *v7; // r3
  volatile uint16_t *v8; // r2
  volatile uint8_t *v9; // r6

  v0 = (void *)(uintptr_t)(off_100498);
  v1 = (void *)(uintptr_t)(off_10049C);
  v2 = (void *)(uintptr_t)(off_1004A0);
  *(volatile uint32_t *)off_100494 = off_100498;
  *v1 = (int)(uintptr_t)(v0 + 3);
  v3 = (void *)(uintptr_t)(off_1004A4);
  v4 = (void *)(uintptr_t)(off_1004A8);
  v5 = (void *)(uintptr_t)(off_1004AC);
  v6 = (void *)(uintptr_t)(off_1004B0);
  *v2 = (int)(uintptr_t)(v0 + 19);
  *v3 = (int)(uintptr_t)(v0 + 34);
  *v4 = (int)(uintptr_t)(v0 + 38);
  *v6 = (int)(uintptr_t)((volatile char *)v0 + 178);
  *v5 = (int)(uintptr_t)(v0 + 44);
  process_state_update();
  if ( *(volatile uint8_t *)*v2 == 1 )
  {
    v7 = (void *)(uintptr_t)(off_1004B8);
    *((volatile uint32_t *)off_1004B4 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  enter_critical_section_2();
  mem_get_stats();
  sys_init();
  v8 = (volatile uint16_t *)*v6;
  v9 = (volatile uint8_t *)off_1004BC;
  *v8 |= 0x2000u;
  dispatch_event_handler_1("asic_ver=0x%x\r\n", *v9);
  radio_timer_snapshot();
  if ( *((volatile uint8_t *)v0 + 363) )
  {
    rf_read_trim();
    rf_enable_2();
  }
  dispatch_event_handler_1("hosttype=%d, asic_ver=0x%x\r\n", *((volatile uint8_t *)v0 + 76), *v9);
  rf_tx_power_get();
  bt_state_dispatch();
  if ( *(volatile uint8_t *)*v2 == 3 )
    *(volatile uint32_t *)off_1004C8 = 1;
  bt_driver_init();
}


// read_control_reg @ 0x1004cc
int read_control_reg(int a1) {
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(volatile uint32_t *)off_100550;
  v3 = *(volatile uint32_t *)off_100550;
  v4 = is_initialized();
  v5 = sys_status_bit21_get();
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
    if ( **(volatile int16_t **)off_100554 < 0 )
      flash_ctrl_init(dword_10055C, dword_100558, 434);
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



// write_timer_reg @ 0x100560
int write_timer_reg(int a1) {
  int result; // r0
  int v3; // [sp+4h] [bp-8h]

  result = a1 + *((volatile uint32_t *)off_100588 + 4);
  do
  {
    v3 = 32;
    while ( v3-- )
      ;
  }
  while ( (int)(*((volatile uint32_t *)off_100588 + 4) - result) < 0 );
  return result;
}



// store_byte_value @ 0x10058c
int store_byte_value(int a1) {
  int result; // r0

  result = read_control_reg(a1);
  if ( *(volatile uint8_t *)off_1005A0 != result )
    *(volatile uint8_t *)off_1005A0 = result;
  return result;
}



// get_device_config @ 0x1005a4
int get_device_config() {
  volatile int *v0; // r4
  int v1; // r5
  int result; // r0
  int16_t v3; // r2

  v0 = (volatile int *)off_1005DC;
  v1 = read_control_reg(HIBYTE(*(volatile uint32_t *)off_1005D8) & 3);
  memset(v0, 0, 8u);
  result = dword_1005E0 + 16 * v1;
  v3 = *(volatile uint16_t *)(result + 6);
  *(volatile uint32_t *)off_1005E4 = *(volatile uint16_t *)(result + 4);
  *((volatile uint8_t *)v0 + 1) = v3;
  *(volatile uint8_t *)v0 = -1;
  return result;
}



// read_byte_register @ 0x1005e8
int read_byte_register() {
  return *((volatile uint8_t *)off_1005F0 + 1);
}



// periph_write_read @ 0x1005f4
int periph_write_read() {
  volatile unsigned int v0; // r0
  unsigned int v1; // r0
  int v3; // r2
  volatile unsigned int v4; // r1
  int result; // r0
  unsigned int v6; // r1
  int v8; // r3
  int v9; // [sp+0h] [bp-Ch]
  int v10; // [sp+4h] [bp-8h]

  *(volatile uint32_t *)dword_100644 = 17;
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
  *(volatile uint32_t *)dword_100644 = 0;
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


// periph_config @ 0x10064c
volatile uint32_t *periph_config() {
  volatile uint32_t *result; // r0
  volatile int *v1; // r2

  result = (void *)(uintptr_t)(off_100680);
  v1 = (volatile int *)off_100684;
  *(volatile uint32_t *)off_10067C |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}



// get_device_config_1 @ 0x100688
volatile uint32_t *get_device_config_1() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2

  result = (void *)(uintptr_t)(off_1006B8);
  v1 = (volatile unsigned int *)off_1006BC;
  *(volatile uint32_t *)off_1006B4 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}



// periph_process @ 0x1006c0
int periph_process(int result, int a2, int a3, unsigned int a4) {
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
                                   - ((unsigned int)(((unsigned int)dword_1007B0
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



// smem_access @ 0x1007b4
volatile int * smem_access(int a1, unsigned int a2, volatile uint32_t *a3) {
  int v4; // r4
  volatile int *v5; // r6
  volatile uint8_t *v6; // r7
  int v8; // r12
  int v9; // r0
  int v10; // r12
  volatile char *v11; // r7
  int v12; // r0
  int v13; // r3
  int v14; // t1
  int v15; // nf
  int v16; // r2
  volatile char *v17; // r7
  volatile uint8_t *v18; // r2
  int i; // r0
  int v20; // t1
  int v21; // r3
  int v22; // zf

  if ( !a1 )
  {
    if ( a2 > 0x97B )
    {
      v4 = *(volatile uint32_t *)off_1008E4;
      if ( a2 > 0x994 )
        a1 = 2;
      else
        a1 = 1;
      if ( v4 )
        goto LABEL_4;
    }
    else
    {
      v4 = *(volatile uint32_t *)off_1008E4;
      if ( *(volatile uint32_t *)off_1008E4 )
      {
LABEL_4:
        v4 = 0;
LABEL_5:
        v5 = (volatile int *)off_1008E8;
        goto LABEL_6;
      }
    }
    v10 = *(volatile uint8_t *)off_1008F8;
    v11 = (volatile char *)dword_1008FC;
    v12 = a1 + *(volatile uint32_t *)off_1008F4;
    v13 = v4;
    do
    {
      v14 = *v11++;
      v16 = (*(volatile uint8_t *)(v12 + 3 * v13) + v14 + v10) << 31;
      v15 = ((*(volatile uint8_t *)(v12 + 3 * v13) + v14 + v10) & 1) != 0;
      if ( ((*(volatile uint8_t *)(v12 + 3 * v13) + v14 + v10) & 1) != 0 )
        v16 = 1 << v13;
      ++v13;
      if ( v15 )
        v4 |= v16;
    }
    while ( v13 != 3 );
    goto LABEL_5;
  }
  if ( a2 > 0x1666 )
  {
    v9 = 480;
    v8 = 5;
  }
  else if ( a2 > 0x1616 )
  {
    v9 = 384;
    v8 = 4;
  }
  else if ( a2 > 0x15C6 )
  {
    v9 = 288;
    v8 = 3;
  }
  else if ( a2 > 0x1571 )
  {
    v9 = 192;
    v8 = 2;
  }
  else
  {
    v8 = a2 > 0x1486;
    if ( a2 <= 0x1486 )
      v9 = 0;
    else
      v9 = 96;
  }
  v4 = *(volatile uint32_t *)off_1008E4;
  v5 = (void *)(&((volatile uint32_t *)(uintptr_t)off_100900)[v9]);
  if ( *(volatile uint32_t *)off_1008E4 )
  {
    v4 = 0;
  }
  else
  {
    v17 = (volatile char *)dword_100908;
    v18 = (volatile uint8_t *)(*(volatile uint32_t *)off_100904 + v8);
    for ( i = 0; i != 3; ++i )
    {
      v20 = *v17++;
      v21 = *v18 + v20 + *((volatile uint8_t *)off_1008F8 + 1);
      v22 = (v21 & 1) == 0;
      if ( (v21 & 1) != 0 )
        v21 = 1 << i;
      if ( !v22 )
        v4 |= v21;
      v18 += 6;
    }
  }
LABEL_6:
  v6 = (volatile uint8_t *)off_1008EC;
  if ( *(volatile char *)off_1008EC > 0 )
  {
    dispatch_event_handler_1("DEBUG: freq=%d, comp_bits=%x\n", a2, v4);
    --*v6;
  }
  *a3 = v4;
  return v5;
}


// rf_ctrl_set @ 0x10090c
int rf_ctrl_set(int a1, int a2) {
  volatile unsigned int *v2; // r5
  volatile int *v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int a3; // [sp+4h] [bp-8h] BYREF

  v2 = (volatile unsigned int *)off_100940;
  v3 = smem_access(a1, a2, (void *)(&a3));
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = periph_process((int)v3, dword_100944, 96, a3);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}


// rf_reg_init @ 0x100948
int rf_reg_init(int a1, int a2) {
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

  v2 = (volatile unsigned int *)off_100A04;
  *(volatile uint32_t *)off_100A00 |= 0x100u;
  v3 = 0;
  *v2 &= 0xFFFCFFFF;
  v5 = v2;
  v6 = -a1;
  v7 = 0;
  v8 = 128;
  while ( 1 )
  {
    v9 = a1 + 4 * (v8 + v3);
    v10 = dword_100A08 + v6;
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
  v14 = (void *)(uintptr_t)(off_100A0C);
  *(volatile uint32_t *)off_100A00 &= ~0x100u;
  *v14 |= 0x1000000u;
  v15 = 1;
  for ( i = 0; i != 12; ++i )
  {
    enable_rf_dll((2 * i) & 0xFE, *(volatile uint32_t *)(a2 + 8 * i));
    v17 = *(volatile uint32_t *)(a2 + 4 + 8 * i);
    result = enable_rf_dll(v15, v17);
    v15 = (uint8_t)(v15 + 2);
  }
  *(volatile uint32_t *)off_100A10 &= ~2u;
  return result;
}



// rf_band_config @ 0x100a14
int rf_band_config() {
  volatile uint32_t *v0; // r2
  volatile int *v1; // r3
  int v2; // r4
  int result; // r0
  int v4; // r1
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r3

  v0 = (void *)(uintptr_t)(off_100A70);
  *(volatile uint32_t *)off_100A70 |= 0x1000u;
  v0[4896] |= 0x20000000u;
  v1 = (volatile int *)dword_100A74;
  v2 = dword_100A74 + 2048;
  result = dword_100A78 - dword_100A74;
  do
  {
    v4 = *v1;
    v5 = (void *)((volatile int *)((volatile char *)v1++ + result));
    *v5 = v4;
  }
  while ( v1 != (volatile int *)v2 );
  v6 = (void *)(uintptr_t)(off_100A70);
  *(volatile uint32_t *)off_100A70 |= 0x80000u;
  *v6 &= ~0x1000u;
  *(volatile uint32_t *)off_100A7C &= ~0x20000000u;
  return result;
}



// mac_send_frame @ 0x100a80
volatile char * mac_send_frame(int a1, unsigned int a2, unsigned int a3, int a4, char a5) {
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

  periph_write_read();
  v9 = (void *)(uintptr_t)(off_100C10);
  *(volatile uint32_t *)off_100C10 &= ~0x40u;
  if ( a1 == 1 )
  {
    v25 = (void *)(uintptr_t)(off_100C14);
    v26 = (void *)(uintptr_t)(off_100C18);
    *(volatile uint32_t *)off_100C14 = *(volatile uint32_t *)off_100C14 & 0xFFFE3FFF | 0x18000;
    *v26 &= ~1u;
    v25[27857] |= 0x100u;
    if ( (a5 & 4) != 0 )
      *v9 |= 0x40u;
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_100C14);
    v11 = (void *)(uintptr_t)(off_100C18);
    *(volatile uint32_t *)off_100C14 = *(volatile uint32_t *)off_100C14 & 0xFFFE3FFF | 0xC000;
    *v11 |= 1u;
    v10[27857] &= ~0x100u;
  }
  if ( a4 == 1 )
  {
    if ( a2 >= a3 )
      v24 = 2;
    else
      v24 = 1;
    *(volatile uint32_t *)off_100C1C = v24;
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
    v12 = ((uint8_t)((int)((uint64_t)((int32_t)dword_100C30 * (int64_t)(int32_t)(int)(a2 - (a3 - 30))) >> 32) >> 3)
         - (uint8_t)((int)(a2 - (a3 - 30)) >> 31))
        & 7;
    *(volatile uint32_t *)off_100C1C = v21;
  }
  else
  {
    v12 = 0;
    *(volatile uint32_t *)off_100C1C = 0;
  }
  v13 = (volatile char *)off_100C20;
  v14 = (volatile unsigned int *)off_100C24;
  v15 = (volatile unsigned int *)off_100C28;
  *(volatile uint32_t *)off_100C20 = v12 | *(volatile uint32_t *)off_100C20 & 0xFFFFFFF8;
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
      result = (volatile char *)off_100C34;
      v22 = (volatile unsigned int *)off_100C38;
      v23 = (volatile unsigned int *)off_100C2C;
      *(volatile uint32_t *)off_100C34 = *(volatile uint32_t *)off_100C34 & 0xFFFFFF | 0x18000000;
      *v22 = *v22 & 0xFFFFFFCF | 0x10;
      *v23 = *v23 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v19 = (volatile unsigned int *)off_100C2C;
    *((volatile uint32_t *)result + 1) = *((volatile uint32_t *)result + 1) & 0xFFFFFF | 0x19000000;
    v17[15866] &= 0xFFFFFFCF;
    *v19 = *v19 & 0xFFFF00FF | 0x9C00;
  }
  return result;
}


// rf_cal_read_0 @ 0x100c3c
int rf_cal_read_0(int result) {
  volatile int *v1; // r2
  unsigned int v2; // r1
  volatile uint8_t *v3; // r6
  volatile unsigned int *v4; // r5
  unsigned int v5; // r3
  int v6; // r3
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r2
  volatile uint32_t *v9; // r3

  v1 = (volatile int *)off_100D04;
  v2 = *(volatile uint32_t *)off_100D04;
  v3 = (void *)(uintptr_t)(off_100D0C);
  *(volatile uint32_t *)off_100D08 = (*(volatile uint8_t *)off_100D00 << 10) & 0x1FC00 | *(volatile uint32_t *)off_100D08 & 0xFFFE03FF;
  v4 = (volatile unsigned int *)off_100D04;
  *v1 |= 0x18u;
  v5 = *v1 & 0xFFFFFFF8;
  if ( (*v3 & 0xC0) == 0xC0 )
    v6 = v5 | 4;
  else
    v6 = v5 | 3;
  *v1 = v6;
  v7 = (void *)(uintptr_t)(off_100D08);
  v8 = (void *)(uintptr_t)(off_100D10);
  *(volatile uint32_t *)off_100D08 |= 0x80000u;
  *v7 |= 0x40000u;
  *v4 = *v4 & 0xFFFFFC1F | 0xE0;
  *v8 &= ~2u;
  *v8 |= 1u;
  if ( !result && ((v2 >> 5) & 0x1F) != 7 )
  {
    v9 = (void *)(uintptr_t)(off_100D14);
    *(volatile uint32_t *)off_100D14 |= 0x80u;
    *v9 &= ~0x40u;
    *v9 |= 0x40u;
    *v9 &= ~0x80u;
  }
  return result;
}



// rf_cal_read_1 @ 0x100d18
unsigned int rf_cal_read_1() {
  volatile unsigned int *v0; // r2
  unsigned int v1; // r1
  volatile uint8_t *v2; // r5
  int v3; // r1
  unsigned int v4; // r3
  volatile unsigned int *v5; // r3
  volatile unsigned int *v6; // r4
  volatile uint32_t *v7; // r2
  unsigned int result; // r0
  volatile uint32_t *v9; // r3

  v0 = (volatile unsigned int *)off_100DEC;
  v1 = *(volatile uint32_t *)off_100DEC;
  v2 = (void *)(uintptr_t)(off_100DF4);
  *(volatile uint32_t *)off_100DF0 = (*((volatile uint8_t *)off_100DE8 + 1) << 10) & 0x1FC00 | *(volatile uint32_t *)off_100DF0 & 0xFFFE03FF;
  v3 = (v1 >> 5) & 0x1F;
  v4 = *v0 & 0xFFFFFFE7;
  if ( (*v2 & 0xC0) == 0xC0 )
  {
    *v0 = v4 | 0x10;
    *v0 = *v0 & 0xFFFFFFF8 | 1;
  }
  else
  {
    *v0 = v4 | 8;
    *v0 |= 7u;
  }
  v5 = (volatile unsigned int *)off_100DF0;
  v6 = (volatile unsigned int *)off_100DEC;
  v7 = (void *)(uintptr_t)(off_100DF8);
  *(volatile uint32_t *)off_100DF0 &= ~0x80000u;
  result = *v5 & 0xFFFBFFFF;
  *v5 = result;
  *v6 = *v6 & 0xFFFFFC1F | 0x80;
  *v7 |= 2u;
  *v7 &= ~1u;
  if ( v3 != 4 )
  {
    v9 = (void *)(uintptr_t)(off_100DFC);
    *(volatile uint32_t *)off_100DFC |= 0x80u;
    *v9 &= ~0x40u;
    *v9 |= 0x40u;
    *v9 &= ~0x80u;
  }
  return result;
}



// mac_ctrl_set @ 0x100e00
int mac_ctrl_set(unsigned int a1, int a2) {
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r4
  int v7; // r1
  volatile uint32_t *v8; // r1
  volatile int *v9; // r2
  int v11; // r4
  volatile int *v12; // r3
  volatile unsigned int *v13; // r5
  volatile unsigned int *v14; // r2
  int v15; // r1
  volatile char *v16; // r4
  int v17; // r5
  volatile unsigned int *v18; // r4
  volatile uint32_t *v19; // r0
  volatile uint32_t *v20; // r5
  volatile uint8_t *v21; // r2
  volatile unsigned int *v22; // r4
  volatile unsigned int *v23; // r2
  volatile uint32_t *v24; // r5
  volatile unsigned int *v25; // r0
  volatile unsigned int *v26; // r4
  volatile uint32_t *v27; // r2
  unsigned int v28; // r3
  volatile uint32_t *v29; // r2
  unsigned int v30; // r3
  int result; // r0

  v2 = (void *)(uintptr_t)(off_10107C);
  v3 = (void *)(uintptr_t)(off_101080);
  v4 = (void *)(uintptr_t)(off_101084);
  v5 = (void *)(uintptr_t)(off_101088);
  *(volatile uint32_t *)off_10107C |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = (void *)(uintptr_t)(off_10108C);
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) = *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = (void *)(uintptr_t)(off_101090);
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = (volatile int *)off_101094;
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  memcpy_advance(1, 0, 0x10u, *v9);
  memcpy_advance(1, 16, 0x10u, *(volatile uint32_t *)off_101098);
  rf_ctrl_set(0, a1);
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
  v12 = (volatile int *)off_1010A4;
  v13 = (volatile unsigned int *)off_1010A8;
  v14 = (volatile unsigned int *)off_1010AC;
  v15 = *(volatile uint8_t *)off_10109C & 0xC0;
  if ( v15 == 192 )
    v12 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1010A0)[0];
  *(volatile uint32_t *)off_1010A8 = *(volatile uint32_t *)off_1010A8 & 0xFE01FFFF | (*((volatile uint8_t *)v12 + v11) << 17);
  v16 = (volatile char *)v12 + v11;
  *v13 = *v13 & 0xFFFFFF00 | (uint8_t)v16[1];
  v17 = (uint8_t)v16[2];
  v18 = (volatile unsigned int *)off_1010B0;
  v19 = (void *)(uintptr_t)(off_1010B4);
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v20 = (void *)(uintptr_t)(off_1010B8);
  *v18 = *v18 & 0xFF00FFFF | 0x2F0000;
  *v19 |= 8u;
  *v19 |= 4u;
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  v21 = (void *)(uintptr_t)(off_1010BC);
  v22 = v18 + 19964;
  *v20 &= 0xFFFFC7FF;
  *v22 = *v22 & 0xFFFFE3FF | 0x1000;
  v19[1984] = v19[1984] & 0xFFFFF83F | 0x400;
  if ( !v21[1] )
  {
    v23 = (volatile unsigned int *)off_1010C0;
    *v22 = *v22 & 0xFFFFFC7F | 0x100;
    *v23 = *v23 & 0x16000 | 0x8000 | *v23 & 0xFFFE1FFF;
  }
  v24 = (void *)(uintptr_t)(off_1010C4);
  v25 = (volatile unsigned int *)off_101088;
  v26 = (volatile unsigned int *)off_1010C8;
  v27 = (void *)(uintptr_t)(off_101090);
  *(volatile uint32_t *)off_1010C4 |= 0xC00u;
  *v25 = *v25 & 0xFFFFFF87 | 0x48;
  *v26 |= 4u;
  *v27 &= ~2u;
  v26 += 1907;
  v24[2] |= 0x20000u;
  *v26 = *v26 & 0xFFF8FFFF | 0x20000;
  *v26 = *v26 & 0xFFFFFFF0 | 8;
  *(volatile uint32_t *)((volatile char *)v24 + 0xFFFFFFEC) = *(volatile uint32_t *)((volatile char *)v24 + 0xFFFFFFEC) & 0xFFFFE3FF | 0x800;
  *(volatile unsigned int *)((volatile char *)v26 + 0xFFFFFFFC) = *(volatile unsigned int *)((volatile char *)v26 + 0xFFFFFFFC) & 0xFC7FFFFF | 0x1000000;
  *v27 &= ~0x20u;
  v28 = *v25;
  v29 = (void *)(uintptr_t)(off_1010CC);
  if ( v15 == 192 )
    v30 = v28 | 0xE0000;
  else
    v30 = v28 & 0xFFF1FFFF;
  if ( v15 != 192 )
    v30 |= 0x60000u;
  *v25 = v30;
  while ( !*v29 )
    ;
  result = *(volatile uint32_t *)off_1010D0 & 1;
  if ( !result )
    result = rf_cal_read_0(0);
  *(volatile uint32_t *)off_1010CC = 1;
  return result;
}


// mac_ctrl_clear @ 0x1010d4
int mac_ctrl_clear(unsigned int a1) {
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r1
  volatile unsigned int *v7; // r4
  volatile uint32_t *v8; // r2
  int v9; // r5
  volatile uint32_t *v11; // r0
  volatile unsigned int *v12; // r4
  volatile uint32_t *v13; // r1
  volatile unsigned int *v14; // r3
  unsigned int v15; // r3
  volatile int *v16; // r4
  volatile int *v17; // r0
  volatile int *v18; // r3
  int (**v19)[48]; // r11
  volatile uint32_t *v20; // r2
  volatile int *v21; // r1
  unsigned int v22; // r12
  int v23; // r10
  int v24; // r8
  unsigned int v25; // r9
  int v26; // lr
  volatile int *v27; // r3
  unsigned int v28; // r4
  unsigned int v29; // r4
  volatile uint32_t *v30; // r3
  volatile unsigned int *v31; // r2
  int v32; // r1
  int v33; // r2
  int v34; // r0
  int v35; // r7
  volatile int *v36; // r1
  volatile int *v37; // r1
  volatile unsigned int *v38; // r4
  int v39; // r5
  volatile uint8_t *v40; // r1
  volatile uint32_t *v41; // r1
  unsigned int v42; // r3
  volatile uint32_t *v43; // r0
  volatile unsigned int *v44; // r1
  int v45; // zf
  volatile unsigned int *v46; // r2
  unsigned int v47; // r3
  unsigned int v48; // r3
  volatile uint32_t *v49; // r2
  volatile int *v50; // r1
  volatile int *v51; // r4
  volatile int *v52; // r0
  volatile int *v53; // r1
  volatile uint32_t *v54; // r3
  volatile int *v55; // r4
  volatile int *v56; // r0
  volatile int *v57; // r1
  volatile int *v58; // r2
  int v59; // r5
  volatile uint8_t *v60; // r4
  BOOL v61; // r0
  volatile uint32_t *v62; // r2
  int result; // r0
  volatile uint32_t *v64; // r2
  volatile uint32_t *v65; // r3
  void *v66; // r1
  void *v67; // r4
  void *v68; // r0
  void *v69; // r1
  void *v70; // r4
  void *v71; // r0
  void *v72; // r1
  void *v73; // r2
  volatile int **v74; // r0
  volatile int *v75; // r3
  volatile int **v76; // r2
  volatile int *v77; // r1
  void *v78; // r1
  volatile int *v79; // r4
  volatile int *v80; // r0
  void *v81; // r1
  void *v82; // r4
  void *v83; // r0
  volatile int *v84; // r1
  void *v85; // r2
  volatile int *v86; // [sp+4h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_101378);
  v2 = (void *)(uintptr_t)(off_10137C);
  v3 = (void *)(uintptr_t)(off_101380);
  v4 = (void *)(uintptr_t)(off_101384);
  v5 = (void *)(uintptr_t)(off_101388);
  *(volatile uint32_t *)off_101378 &= ~0x400u;
  *v1 &= ~0x800u;
  *v4 |= 4u;
  v6 = (void *)(uintptr_t)(off_10138C);
  *v2 |= 0x80000u;
  *v2 &= ~0x100000u;
  v7 = (volatile unsigned int *)off_101390;
  *v3 |= 0x400u;
  *v3 &= ~0x100u;
  *v3 |= 0x80u;
  v8 = (void *)(uintptr_t)(off_101394);
  *v5 |= 0x8000u;
  *v6 |= 1u;
  *v6 &= ~2u;
  *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFFA4) |= 0x40u;
  *v7 = *v7 & 0xFFC01FFF | 0x32000;
  *v8 &= ~0x8000u;
  *v8 |= 0x4000u;
  v9 = *(volatile uint8_t *)off_101398 & 0xC0;
  if ( v9 == 192 )
    *(volatile uint32_t *)((volatile char *)v8 + 0xFFFFFFFC) = *(volatile uint32_t *)((volatile char *)v8 + 0xFFFFFFFC) & 0xFFF9FFFF | 0x40000;
  else
    *(volatile uint32_t *)off_10139C = *(volatile uint32_t *)off_10139C & 0xFFF9FFFF | 0x20000;
  v11 = (void *)(uintptr_t)(off_1013A0);
  v12 = (volatile unsigned int *)off_1013A4;
  v13 = (void *)(uintptr_t)(off_1013A8);
  v14 = (volatile unsigned int *)off_1013AC;
  *(volatile uint32_t *)off_1013A0 = *(volatile uint32_t *)off_1013A0 & 0xFFFFE3FF | 0x800;
  *v12 = *v12 & 0xFC7FFFFF | 0x1000000;
  *v13 &= 0xFFFFC7FF;
  *v14 = *v14 & 0xFFFFF83F | 0x400;
  v11[4] = v11[4] & 0xFFFFE3FF | 0x1000;
  v12[4] |= 0xC00u;
  v11[4] = v11[4] & 0xFFFFFF87 | 0x48;
  v13 -= 1904;
  *v14 &= ~1u;
  *v13 |= 8u;
  *v13 |= 4u;
  *v14 &= ~2u;
  v12[6] &= ~0x20000u;
  *v14 |= 0x20u;
  v15 = (uint16_t)(a1 - 5000);
  if ( v9 == 192 )
  {
    if ( v15 <= 0xFA )
    {
      v74 = (volatile int **)off_101700;
      v75 = (volatile int *)off_10173C;
      v76 = (volatile int **)off_101708;
      v19 = (void *)(uintptr_t)(off_101770);
      v77 = (volatile int *)off_101740;
      v86 = (volatile int *)off_101700;
    }
    else if ( a1 > 0x14C8 )
    {
      if ( a1 <= 0x15C2 )
      {
        v74 = (volatile int **)off_101700;
        v75 = (volatile int *)off_101764;
        v76 = (volatile int **)off_101708;
        v19 = (void *)(uintptr_t)(off_101770);
        v77 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_101768)[0]);
        v86 = (volatile int *)off_101700;
      }
      else if ( a1 > 0x1612 )
      {
        v74 = (volatile int **)off_1017A0;
        if ( a1 > 0x1662 )
        {
          v75 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1017B4)[0];
          v76 = (volatile int **)off_1017A8;
          v19 = (void *)(uintptr_t)(off_1017BC);
          v77 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1017B8)[0];
        }
        else
        {
          v75 = (volatile int *)off_1017A4;
          v76 = (volatile int **)off_1017A8;
          v19 = (void *)(uintptr_t)(off_1017BC);
          v77 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1017AC)[0];
        }
        v86 = (volatile int *)off_1017A0;
      }
      else
      {
        v74 = (volatile int **)off_101700;
        v75 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_101750)[0];
        v76 = (volatile int **)off_101708;
        v19 = (void *)(uintptr_t)(off_101770);
        v77 = (volatile int *)off_101754;
        v86 = (volatile int *)off_101700;
      }
    }
    else
    {
      v74 = (volatile int **)off_101700;
      v75 = (volatile int *)off_101704;
      v76 = (volatile int **)off_101708;
      v19 = (void *)(uintptr_t)(off_101770);
      v77 = (volatile int *)off_10170C;
      v86 = (volatile int *)off_101700;
    }
    v26 = 0;
    *v76 = v75;
    *v74 = v75;
    v20 = (void *)(v75);
    v23 = (int)v75;
    *v19 = (int (*)[48])v77;
    v25 = 0;
    v24 = 0;
    v22 = 0;
    goto LABEL_7;
  }
  if ( v15 > 0xFA )
  {
    if ( a1 > 0x14C8 )
    {
      if ( a1 > 0x15C2 )
      {
        if ( a1 <= 0x1612 )
        {
          v18 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_10175C)[0];
          v16 = (volatile int *)off_101700;
          v19 = (void *)(uintptr_t)(off_101770);
          v20 = (void *)(uintptr_t)(off_101758);
          v37 = (void *)(uintptr_t)(off_10176C);
          v86 = (volatile int *)off_101700;
          *(int (**)[48])off_101708 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_10175C)[0]);
          v22 = 0;
          v24 = 1610612736;
        }
        else
        {
          v16 = (volatile int *)off_101700;
          v17 = (volatile int *)off_101708;
          v19 = (void *)(uintptr_t)(off_101770);
          v20 = (void *)(uintptr_t)(off_101758);
          v86 = (volatile int *)off_101700;
          v18 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_10175C)[0];
          if ( a1 > 0x1662 )
          {
            v21 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1017B0)[0];
            goto LABEL_6;
          }
          v37 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_101760)[0];
          *(int (**)[48])off_101708 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_10175C)[0]);
          v22 = 0;
          v24 = 0x40000000;
        }
      }
      else
      {
        v18 = (volatile int *)off_1013D0;
        v16 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1013B0)[0]);
        v19 = (void *)(uintptr_t)(off_1013DC);
        v20 = (void *)(uintptr_t)(off_1013D4);
        v37 = (volatile int *)off_1013D8;
        v86 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1013B0)[0]);
        *(volatile uint32_t *)(uintptr_t)(off_1013B4) = (int)off_1013D0;
        v22 = 0x80000000;
        v24 = 1610612736;
      }
      v23 = (int)v18;
      *v19 = (int (*)[48])v37;
      *v16 = (int)v20;
      v25 = v22;
      v26 = v24;
      goto LABEL_7;
    }
    v16 = (volatile int *)off_101700;
    v17 = (volatile int *)off_101708;
    v18 = (volatile int *)off_101744;
    v19 = (void *)(uintptr_t)(off_101770);
    v20 = (void *)(uintptr_t)(off_101748);
    v21 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_10174C)[0];
    v86 = (volatile int *)off_101700;
  }
  else
  {
    v16 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1013B0)[0]);
    v17 = (void *)(uintptr_t)(off_1013B4);
    v18 = (volatile int *)off_1013B8;
    v19 = (void *)(uintptr_t)(off_1013DC);
    v20 = (void *)(uintptr_t)(off_1013BC);
    v21 = (volatile int *)off_1013C0;
    v86 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1013B0)[0]);
  }
LABEL_6:
  v22 = 0;
  *v17 = (int)v18;
  v23 = (int)v18;
  *v19 = (int (*)[48])v21;
  *v16 = (int)v20;
  v24 = 0;
  v25 = 0;
  v26 = 0;
LABEL_7:
  v27 = (volatile int *)v23;
  do
  {
    if ( v9 != 192 && (uint16_t)(a1 - 5000) > 0x140u )
    {
      v28 = v27[1] & 0xFFFFFFFE;
      *v27 = *v27 & 0x1FFFFFFF | v26 | v25;
      v27[1] = v28;
      v29 = v20[1] & 0xFFFFFFFE;
      *v20 = *v20 & 0x1FFFFFFF | v24 | v22;
      v20[1] = v29;
    }
    v27 += 3;
    v20 += 3;
  }
  while ( v27 != (volatile int *)(v23 + 192) );
  memcpy_advance(1, 0, 0x10u, v23);
  memcpy_advance(1, 16, 0x10u, (int)*v19);
  memcpy_advance(1, 32, 0x10u, *v86);
  rf_ctrl_set(1, a1);
  v30 = (void *)(uintptr_t)(off_1013C4);
  v31 = (volatile unsigned int *)off_1013C8;
  *(volatile uint32_t *)off_1013C4 |= 8u;
  *v30 |= 4u;
  *v31 = *v31 & 0xFFFC7FFF | 0x10000;
  *v31 = *v31 & 0xFFFF8FFF | 0x3000;
  if ( a1 > 0x1666 )
  {
    v35 = 10;
    v34 = 5;
  }
  else if ( a1 > 0x1616 )
  {
    v35 = 8;
    v34 = 4;
  }
  else if ( a1 > 0x15C6 )
  {
    v35 = 6;
    v34 = 3;
  }
  else
  {
    if ( a1 <= 0x1571 )
    {
      v32 = *(volatile uint8_t *)off_101398;
      v33 = v32 & 0xC0;
      v34 = a1 > 0x1486;
      if ( a1 <= 0x1486 )
        v35 = 0;
      else
        v35 = 2;
      if ( v33 == 192 )
        goto LABEL_20;
      goto LABEL_27;
    }
    v35 = 4;
    v34 = 2;
  }
  v32 = *(volatile uint8_t *)off_101674;
  v33 = v32 & 0xC0;
  if ( v33 == 192 )
  {
LABEL_20:
    v36 = (volatile int *)off_1013CC;
    goto LABEL_31;
  }
LABEL_27:
  if ( v32 == 3 )
  {
    v36 = (volatile int *)off_101738;
  }
  else if ( v32 == 7 )
  {
    v36 = (volatile int *)off_101678;
  }
  else
  {
    v36 = nullptr;
  }
LABEL_31:
  v38 = (volatile unsigned int *)off_101680;
  *(volatile uint32_t *)off_10167C = *(volatile uint32_t *)off_10167C & 0xFFFFFF00 | *((volatile uint8_t *)v36 + v35);
  v39 = *((volatile uint8_t *)v36 + v35 + 1);
  v40 = (void *)(uintptr_t)(off_101684);
  *v38 = *v38 & 0xFFFFFF00 | v39;
  if ( !v40[1] )
  {
    v41 = (void *)(uintptr_t)(off_101688);
    v38[1918] &= 0xFFFFFC7F;
    *v41 &= ~0x8000u;
  }
  v42 = *(volatile uint32_t *)off_10168C & 0xFF00FFFF;
  if ( v34 <= 1 )
    v42 |= 0x1F0000u;
  v43 = (void *)(uintptr_t)(off_101690);
  *(volatile uint32_t *)off_10168C = v42;
  v44 = (volatile unsigned int *)off_101694;
  *v43 &= ~0x4000u;
  *v44 = *v44 & 0xFFF8FFFF | 0x20000;
  v45 = v33 == 192;
  v46 = (volatile unsigned int *)off_101698;
  *v44 = *v44 & 0xFFFFFFF0 | 8;
  v47 = *v46;
  if ( v45 )
    v48 = v47 | 0xE0000;
  else
    v48 = v47 & 0xFFF1FFFF;
  if ( !v45 )
    v48 |= 0x60000u;
  *v46 = v48;
  if ( a1 <= 0x15E4 )
  {
    v64 = (void *)(uintptr_t)(off_10169C);
    v65 = (void *)(uintptr_t)(off_1016B4);
    if ( a1 <= 0x14D6 )
    {
      v78 = (void *)(uintptr_t)(off_101714);
      v79 = (volatile int *)off_101718;
      *(volatile uint32_t *)off_10169C = off_101710;
      v64[1] = (int)(uintptr_t)(v78);
      v80 = (volatile int *)off_10171C;
      v81 = (void *)(uintptr_t)(off_101720);
      v64[2] = (int)(uintptr_t)(v79);
      v64[3] = (int)(uintptr_t)(v80);
      v64[4] = (int)(uintptr_t)(v81);
      v82 = (void *)(uintptr_t)(off_101724);
      v83 = (void *)(uintptr_t)(off_101728);
      v84 = (volatile int *)off_10172C;
      v85 = (void *)(uintptr_t)(off_101730);
      *v65 = off_101734;
      v65[1] = (int)(uintptr_t)(v82);
      v65[2] = (int)(uintptr_t)(v83);
      v65[3] = (int)(uintptr_t)(v84);
      v65[4] = (int)(uintptr_t)(v85);
      v59 = 0;
    }
    else
    {
      v66 = (void *)(uintptr_t)(off_1016DC);
      v67 = (void *)(uintptr_t)(off_1016E0);
      *(volatile uint32_t *)off_10169C = off_1016D8;
      v64[1] = (int)(uintptr_t)(v66);
      v68 = (void *)(uintptr_t)(off_1016E4);
      v69 = (void *)(uintptr_t)(off_1016E8);
      v64[2] = (int)(uintptr_t)(v67);
      v64[3] = (int)(uintptr_t)(v68);
      v64[4] = (int)(uintptr_t)(v69);
      v70 = (void *)(uintptr_t)(off_1016EC);
      v71 = (void *)(uintptr_t)(off_1016F0);
      v72 = (void *)(uintptr_t)(off_1016F4);
      v73 = (void *)(uintptr_t)(off_1016F8);
      *v65 = off_1016FC;
      v65[1] = (int)(uintptr_t)(v70);
      v65[2] = (int)(uintptr_t)(v71);
      v65[3] = (int)(uintptr_t)(v72);
      v65[4] = (int)(uintptr_t)(v73);
      v59 = 1;
    }
  }
  else
  {
    v49 = (void *)(uintptr_t)(off_10169C);
    v50 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016A4)[0];
    v51 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016A8)[0];
    *(int (**)[80])off_10169C = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1016A0)[0]);
    v49[1] = (int)(uintptr_t)(v50);
    v52 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016AC)[0];
    v53 = (volatile int *)off_1016B0;
    v54 = (void *)(uintptr_t)(off_1016B4);
    v49[2] = (int)(uintptr_t)(v51);
    v49[3] = (int)(uintptr_t)(v52);
    v49[4] = (int)(uintptr_t)(v53);
    v55 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016B8)[0];
    v56 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016BC)[0];
    v57 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016C0)[0];
    v58 = (volatile int *)((volatile uint32_t *)(uintptr_t)&off_1016C4)[0];
    *v54 = off_1016C8;
    v54[1] = (int)(uintptr_t)(v55);
    v54[2] = (int)(uintptr_t)(v56);
    v54[3] = (int)(uintptr_t)(v57);
    v54[4] = (int)(uintptr_t)(v58);
    v59 = 2;
  }
  v60 = (void *)(uintptr_t)(off_1016CC);
  if ( *(volatile uint8_t *)off_1016CC != v59 )
  {
    v61 = get_reset_reason();
    dma_init(v61);
  }
  v62 = (void *)(uintptr_t)(off_1016D0);
  *v60 = v59;
  while ( !*v62 )
    ;
  result = *(volatile uint32_t *)off_1016D4 & 1;
  if ( !result )
  {
    if ( a1 - 5270 > 0x32 && a1 - 5550 > 0x64 )
      result = rf_cal_read_0(0);
    else
      result = rf_cal_read_1();
  }
  *(volatile uint32_t *)off_1016D0 = 1;
  return result;
}


// tx_path_check @ 0x1017c0
int tx_path_check() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile uint32_t *v2; // r5
  volatile unsigned int *v3; // r1
  volatile unsigned int *v4; // r4
  volatile uint32_t *v5; // r3
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r6
  int result; // r0
  volatile uint32_t *v9; // r4
  volatile unsigned int *v10; // r3
  volatile unsigned int *v11; // r2
  volatile uint8_t *v12; // r3
  volatile int *v13; // r1
  int v14; // r2
  volatile uint32_t *v15; // r2
  int v16; // r1

  if ( **(volatile int16_t **)off_101954 < 0
    && (uint8_t)BYTE2(*(volatile uint32_t *)off_1019A8) + 10 * (HIBYTE(*(volatile uint32_t *)off_1019A8) + 2) != 32 )
  {
    flash_ctrl_init((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  periph_write_read();
  v0 = (void *)(uintptr_t)(off_10195C);
  v1 = (void *)(uintptr_t)(off_101960);
  *(volatile uint32_t *)off_101958 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(volatile uint32_t *)off_101960 >> 4 == 2 )
    *(volatile uint32_t *)off_101964 = dword_101968;
  v2 = (void *)(uintptr_t)(off_10196C);
  v3 = (volatile unsigned int *)off_101970;
  v4 = (volatile unsigned int *)off_101974;
  v5 = (void *)(uintptr_t)(off_101978);
  v6 = (void *)(uintptr_t)(off_10197C);
  v7 = (void *)(uintptr_t)(off_101958);
  *(volatile uint32_t *)off_10196C = *(volatile uint32_t *)off_10196C & 0xFFFFF800 | 0x700;
  *v3 = 256;
  *v4 = *v4 & 0xFFFFE000 | 0x580;
  *v5 |= 0x10000u;
  *v5 |= 0x10000000u;
  *v5 |= 2u;
  v2 -= 236;
  *v6 |= 2u;
  result = 1;
  *v2 = 1;
  v9 = (void *)(v4 + 16846);
  *v5 &= 0xFFFFFF8F;
  *v9 = 1;
  *v3 = *v3 & 0xFFFFFCFF | 0x100;
  v2 -= 10753;
  *v7 |= 0x8000000u;
  v10 = (volatile unsigned int *)off_101980;
  *v2 &= 0xFFFFF0FF;
  *v10 |= 0x800000u;
  *v10 |= 0x400000u;
  *v10 |= 1u;
  *v10 = *v10 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v11 = (volatile unsigned int *)off_101984;
    *v9 = 1;
    *v11 = *v11 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v12 = (void *)(uintptr_t)(off_101990);
  *(volatile uint32_t *)off_101988 = dword_10198C;
  v13 = (void *)(uintptr_t)(off_101994);
  if ( (*v12 & 0xC0) == 0xC0 )
    v14 = dword_10199C;
  else
    v14 = dword_1019A0;
  *(volatile uint32_t *)off_101998 = v14;
  v15 = (void *)(uintptr_t)(off_1019A4);
  v16 = *((volatile uint8_t *)v13 + 406);
  *(volatile uint32_t *)off_1019A4 |= 0x10u;
  if ( !v16 )
    *(v15 - 10802) &= ~0x40u;
  return result;
}


// irq_handler @ 0x1019b4
int irq_handler(int result, int a2, int a3) {
  if ( (*(volatile uint32_t *)off_1019CC & 8) != 0 )
  {
    result = (int)(uintptr_t)(stack_canary_setup(result, a2, a3, *(volatile uint32_t *)off_1019CC << 28));
    *(volatile uint32_t *)off_1019D0 = 8;
  }
  return result;
}



// chip_id_get @ 0x1019d4
volatile uint32_t * chip_id_get(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_1019E8);
  *result = *(volatile uint32_t *)off_1019E4;
  *a2 = *v2;
  return result;
}



// mac_time_get @ 0x1019ec
volatile uint64_t * mac_time_get(volatile uint64_t *result, int a2) {
  volatile uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (volatile uint64_t *)dispatch_event_handler_1("\x9B\x87%s: radio %d does not exist\n", aPhyGetChannel, a2);
    *v2 = *(volatile uint64_t *)((volatile char *)off_101A14 + 36);
  }
  else
  {
    *result = *(volatile uint64_t *)((volatile char *)off_101A14 + 36);
  }
  return result;
}


// os_get_tick_hz @ 0x101a20
int os_get_tick_hz() {
  return 1000;
}



// is_initialized @ 0x101a28
int is_initialized() {
  return 1;
}



// sys_status_bit21_get @ 0x101a2c
int sys_status_bit21_get() {
  return (*(volatile uint32_t *)off_101A38 >> 21) & 1;
}



// sys_ready_check @ 0x101a3c
BOOL sys_ready_check() {
  return *(volatile uint32_t *)off_101A4C > 1u;
}



// ctrl_bit3_set @ 0x101a50
unsigned int ctrl_bit3_set(int a1) {
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(volatile uint32_t *)off_101A64 & 0xFFFFFFF7;
  *(volatile uint32_t *)off_101A64 = result;
  return result;
}



// sys_status_bit28_get @ 0x101a68
/* luna: Return bit 28 of the system status word referenced by off_101A74. */
int sys_status_bit28_get() {
  return (*(volatile uint32_t *)off_101A74 >> 28) & 1;
}



// sys_status_bit30_get @ 0x101a78
int sys_status_bit30_get() {
  return (*(volatile uint32_t *)off_101A84 >> 30) & 1;
}



// chip_info_nibble2_get @ 0x101a88
int chip_info_nibble2_get() {
  return (uint8_t)((BYTE1(*(volatile uint32_t *)off_101A98) & 0xF) - 1);
}



// chip_info_nibble1_get @ 0x101a9c
int chip_info_nibble1_get() {
  return (uint8_t)(((uint8_t)*(volatile uint32_t *)off_101AAC >> 4) - 1);
}



// chip_info_nibble0_get @ 0x101ab0
int chip_info_nibble0_get() {
  return (uint8_t)((*(volatile uint8_t *)off_101AC0 & 0xF) - 1);
}



// rf_get_status @ 0x101ac4
int rf_get_status(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int result; // r0
  unsigned int v4; // r3
  int v5; // r7
  char v6; // r4
  int v7; // r3
  char v8; // r5
  unsigned int v9; // r0
  int v10; // r0
  uint8_t v11; // r5
  int v12; // r3
  char v13; // r3
  char v14; // r5

  result = *((volatile uint8_t *)off_101C44 + 36);
  v4 = *((volatile uint16_t *)off_101C44 + 20);
  if ( *((volatile uint8_t *)off_101C44 + 36) )
  {
    result = *((volatile uint8_t *)off_101C48 + 197);
    if ( *((volatile uint8_t *)off_101C48 + 197) )
    {
      if ( v4 <= 0x1666 )
      {
        if ( v4 > 0x1616 )
        {
          v10 = 4;
        }
        else if ( v4 > 0x15C6 )
        {
          v10 = 3;
        }
        else if ( v4 > 0x1571 )
        {
          v10 = 2;
        }
        else
        {
          v10 = v4 > 0x1486;
        }
      }
      else
      {
        v10 = 5;
      }
      v11 = *((volatile uint8_t *)off_101C48 + 236);
      v12 = (char)(*((volatile uint8_t *)off_101C54 + 1) + *((volatile uint8_t *)off_101C50 + 11) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101C58 + v10));
      if ( *((volatile uint8_t *)off_101C48 + 396) )
        result = (uint8_t)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101C6C + v10) + v11);
      else
        result = v11;
      if ( (v12 & 1) != 0 )
        v12 = (char)v12 - 1;
      v13 = v12 / 2 + result;
      *a3 = v13;
      *a2 = v13;
    }
    else if ( **(volatile int16_t **)off_101C5C < 0 )
    {
      return flash_ctrl_init(dword_101C64, dword_101C60, 6921);
    }
  }
  else if ( *((volatile uint8_t *)off_101C48 + 197) )
  {
    if ( v4 > 0x97B )
    {
      if ( v4 > 0x994 )
        result = 2;
      else
        result = 1;
    }
    v5 = (v5 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)off_101C48 + 198)) & 0xFFu);
    v6 = *(volatile uint8_t *)off_101C54 + *((volatile uint8_t *)off_101C50 + 8) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101C4C + result);
    v7 = (char)(*((volatile uint8_t *)off_101C50 + 10) + *(volatile uint8_t *)off_101C54 + *(volatile uint8_t *)(*(volatile uint32_t *)off_101C4C + result + 6));
    if ( *((volatile uint8_t *)off_101C48 + 396) )
    {
      v14 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101C68 + result);
      v5 = (uint8_t)(v5 + v14);
      v8 = v14 + *((volatile uint8_t *)off_101C48 + 210);
    }
    else
    {
      v5 = (uint8_t)v5;
      v8 = *((volatile uint8_t *)off_101C48 + 210);
    }
    if ( ((*(volatile uint8_t *)off_101C54 + *((volatile uint8_t *)off_101C50 + 8) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101C4C + result)) & 1) != 0 )
      v9 = v6 - 1 + ((unsigned int)(v6 - 1) >> 31);
    else
      v9 = v6 + ((unsigned int)v6 >> 31);
    if ( (v7 & 1) != 0 )
      v7 = (char)v7 - 1;
    result = (uint8_t)(v9 >> 1) + v5;
    *a2 = result;
    *a3 = v7 / 2 + v8;
  }
  else if ( **(volatile int16_t **)off_101C5C < 0 )
  {
    return flash_ctrl_init(dword_101C64, dword_101C60, 6875);
  }
  return result;
}



// rf_set_channel @ 0x101c70
int rf_set_channel(unsigned int a1, signed int a2, int a3) {
  unsigned int v3; // r4
  volatile char *v4; // r2
  char v5; // r2
  int v6; // r3
  int v7; // r7
  int v8; // r5
  char v9; // r1
  int v10; // r3
  volatile char *v12; // r3
  int v13; // r0
  int v14; // r3
  int v15; // cc
  int v16; // r0
  int v17; // r1
  int v18; // r5

  v3 = *(volatile uint16_t *)(a3 + 4);
  if ( !*(volatile uint8_t *)a3 )
  {
    if ( a1 <= 1 )
    {
      v5 = *((volatile uint8_t *)off_101DB4 + a2 + 198);
      if ( !a1 && (unsigned int)a2 <= 3 )
      {
        v7 = 0;
        goto LABEL_13;
      }
      v6 = 9;
    }
    else
    {
      v4 = (volatile char *)off_101DB4 + a2;
      if ( a1 > 4 )
        v5 = v4[220];
      else
        v5 = v4[210];
      v6 = 2;
    }
    if ( v6 < a2 )
      a1 = 3;
    else
      a1 = 6;
    if ( v6 < a2 )
      v7 = 1;
    else
      v7 = 2;
LABEL_13:
    if ( v3 <= 0x97B )
    {
      v8 = 0;
    }
    else if ( v3 > 0x994 )
    {
      v8 = 2;
    }
    else
    {
      v8 = 1;
    }
    v9 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101DB8 + v8 + a1) + *(volatile uint8_t *)(dword_101DBC + v7 + 8) + *(volatile uint8_t *)off_101DC0;
    v10 = v9;
    if ( *((volatile uint8_t *)off_101DB4 + 396) )
      v5 += *(volatile uint8_t *)(*(volatile uint32_t *)off_101DC4 + v8);
    goto LABEL_19;
  }
  v12 = (volatile char *)off_101DB4 + a2;
  if ( a1 <= 1 )
  {
    v5 = v12[232];
    v13 = 11;
    v14 = 7;
  }
  else
  {
    if ( a1 > 4 )
      v5 = v12[254];
    else
      v5 = v12[244];
    v13 = 7;
    v14 = 4;
  }
  if ( v14 >= a2 )
  {
    v16 = 0;
    v17 = 0;
  }
  else
  {
    v15 = v13 < a2;
    if ( v13 < a2 )
      v16 = 6;
    else
      v16 = 12;
    if ( v15 )
      v17 = 1;
    else
      v17 = 2;
  }
  if ( v3 > 0x1666 )
  {
    v18 = 5;
  }
  else if ( v3 > 0x1616 )
  {
    v18 = 4;
  }
  else if ( v3 > 0x15C6 )
  {
    v18 = 3;
  }
  else if ( v3 <= 0x1571 )
  {
    v18 = v3 > 0x1486;
  }
  else
  {
    v18 = 2;
  }
  v9 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101DC8 + v18 + v16) + *(volatile uint8_t *)(dword_101DBC + v17 + 11) + *((volatile uint8_t *)off_101DC0 + 1);
  v10 = v9;
  if ( *((volatile uint8_t *)off_101DB4 + 396) )
    v5 += *(volatile uint8_t *)(*(volatile uint32_t *)off_101DCC + v18);
LABEL_19:
  if ( (v9 & 1) != 0 )
    --v10;
  return (char)(v10 / 2 + v5);
}



// pll_set_output @ 0x101dd0
int pll_set_output(int result) {
  volatile uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = (void *)(uintptr_t)(off_101E10);
  *(volatile uint32_t *)off_101E0C = *(volatile uint32_t *)off_101E0C & 0xFFFFFF | ((uint8_t)(result / 2) << 24);
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



