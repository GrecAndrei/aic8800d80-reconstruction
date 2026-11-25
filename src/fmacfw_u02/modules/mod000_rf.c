// start @ 0x1001a8
/* luna: Selects a marked alternate firmware vector pair when the hardware checks pass, switches the main stack pointer, and otherwise enters the default start */
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
/* luna: Fills the destination with the low byte of the fill value for the requested number of bytes and returns the original destination. */
volatile int * memset(volatile int *result, uint8_t a2, unsigned int a3) {
  unsigned int remaining_bytes; // r4
  volatile int *write_pointer; // r3
  int repeated_fill_word; // r5
  volatile uint8_t *v7; // r2
  volatile int *v8; // r2
  int v9; // r6
  volatile int *v10; // r4

  if ( (uint32_t)result << 30 )
  {
    remaining_bytes = a3 - 1;
    if ( !a3 )
      return result;
    write_pointer = result;
    while ( 1 )
    {
      *(volatile uint8_t *)write_pointer = a2;
      write_pointer = (volatile int *)((volatile char *)write_pointer + 1);
      if ( !((uint32_t)write_pointer << 30) )
        break;
      if ( remaining_bytes-- == 0 )
        return result;
    }
  }
  else
  {
    remaining_bytes = a3;
    write_pointer = result;
  }
  if ( remaining_bytes > 3 )
  {
    repeated_fill_word = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
    if ( remaining_bytes <= 0xF )
    {
      v8 = write_pointer;
      v9 = remaining_bytes;
    }
    else
    {
      v7 = (void *)(write_pointer + 4);
      do
      {
        *((volatile uint32_t *)v7 - 4) = repeated_fill_word;
        *((volatile uint32_t *)v7 - 3) = repeated_fill_word;
        *((volatile uint32_t *)v7 - 2) = repeated_fill_word;
        *((volatile uint32_t *)v7 - 1) = repeated_fill_word;
        v7 += 16;
      }
      while ( v7 != (volatile char *)write_pointer + ((remaining_bytes - 16) & 0xFFFFFFF0) + 32 );
      v8 = &write_pointer[4 * ((remaining_bytes - 16) >> 4) + 4];
      v9 = remaining_bytes & 0xF;
      if ( (remaining_bytes & 0xC) == 0 )
      {
        remaining_bytes &= 0xFu;
        write_pointer = v8;
        if ( !v9 )
          return result;
        goto LABEL_16;
      }
    }
    write_pointer = (volatile int *)((volatile char *)v8 + ((v9 - 4) & 0xFFFFFFFC) + 4);
    do
      *v8++ = repeated_fill_word;
    while ( write_pointer != v8 );
    remaining_bytes = v9 & 3;
  }
  if ( !remaining_bytes )
    return result;
LABEL_16:
  v10 = (volatile int *)((volatile char *)write_pointer + remaining_bytes);
  do
  {
    *(volatile uint8_t *)write_pointer = a2;
    write_pointer = (volatile int *)((volatile char *)write_pointer + 1);
  }
  while ( v10 != write_pointer );
  return result;
}



// ke_event_handler @ 0x1002a0
/* luna: Initializes the kernel task and memory-pool layout from configured counts and sizes, then sets the associated region pointers. */
int ke_event_handler(int a1, int a2, int a3, int a4) {
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
  log_printf("stk_start=%x, ptr_bss=%x\n", v11, v14);
  if ( **v21 < 0 && v14 >= v11 )
    mmio_clear_register((int)aPtrBssStartSta, (int)aPostponedArray, 120);
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
  result = log_printf("emacsh=%x, lmacsh=%x, ptr_macsh=%x\n", dword_100430, dword_100450, v35);
  if ( **v21 < 0 && v35 >= v39 )
    result = mmio_clear_register((int)aPtrMacshLmacsh, (int)aPostponedArray, 156);
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
      return log_printf("mem overlaps: stk_end=%x, host_base=%x\r\n", dword_10045C, v43);
  }
  return result;
}


// queue_init @ 0x100478
/* luna: Initializes device state and event plumbing, then performs system and RF startup and selects the wakeup or main status path. */
void queue_init() {
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
  ke_event_handler((int)(v0 + 44), (int)v6, (int)v0 + 178, (int)v5);
  if ( *(volatile uint8_t *)*v1 == 1 )
  {
    v7 = (void *)(uintptr_t)(off_10058C);
    *((volatile uint32_t *)off_100588 + 22) &= ~1u;
    v7[20] |= 1u;
    v7[20] &= ~2u;
  }
  v8 = (void *)(uintptr_t)(off_100594);
  *((volatile uint8_t *)off_100594 + 2) = (*(volatile uint32_t *)off_100590 & 0xF) == 10;
  call_handler();
  dma_reset_regs();
  rf_copy_stats();
  system_init();
  if ( *((volatile uint8_t *)v0 + 363) )
  {
    rf_get_channel_calibration();
    rf_enable_2();
  }
  event_dispatch("hosttype=%d, asic_ver=0x%x\r\n", *((volatile uint8_t *)v0 + 76), *(volatile uint8_t *)off_100598);
  calculate_rf_power();
  rf_wait_ready();
  if ( v8[2] )
  {
    get_global_167204();
    v9 = (void *)(uintptr_t)(off_100590);
    *(volatile uint32_t *)off_1005A0 &= ~8u;
    *v9 &= 0xFFFFFFF0;
    check_status_bits(2, aWakeup);
  }
  else
  {
    check_status_bits(2, aWifimain);
  }
  if ( *(volatile uint8_t *)*v1 == 3 )
    *(volatile uint32_t *)off_1005A8 = 1;
  copy_global_data();
}


// chip_periph_init @ 0x1005b0
/* luna: Returns an RF status code based on the requested status class and current peripheral status bits. */
int chip_periph_init(int a1) {
  unsigned int v2; // r6
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r0
  int v6; // r6
  int v7; // r5

  v2 = *(volatile uint32_t *)off_100634;
  v3 = *(volatile uint32_t *)off_100634;
  v4 = return_true();
  v5 = rf_get_status_bit21();
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
      mmio_clear_register(dword_100640, dword_10063C, 434);
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



// timer_delay @ 0x100644
/* luna: Busy-waits until the free-running hardware timer reaches its initial value plus the requested number of ticks. */
int timer_delay(int a1) {
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



// update_status_byte @ 0x100670
/* luna: Initializes the chip peripheral, caches its returned status byte when it changes, and returns that status. */
int update_status_byte(int a1) {
  int result; // r0

  result = chip_periph_init(a1);
  if ( *(volatile uint8_t *)off_100684 != result )
    *(volatile uint8_t *)off_100684 = result;
  return result;
}



// dispatch_interrupt @ 0x100688
/* luna: Selects the chip-specific RF configuration entry, programs its register value, and initializes the associated status bytes. */
int dispatch_interrupt() {
  volatile int *v0; // r4
  int v1; // r5
  int result; // r0
  int16_t v3; // r2

  v0 = (volatile int *)off_1006C0;
  v1 = chip_periph_init(HIBYTE(*(volatile uint32_t *)off_1006BC) & 3);
  memset(v0, 0, 8u);
  result = dword_1006C4 + 16 * v1;
  v3 = *(volatile uint16_t *)(result + 6);
  *(volatile uint32_t *)off_1006C8 = *(volatile uint16_t *)(result + 4);
  *((volatile uint8_t *)v0 + 1) = v3;
  *(volatile uint8_t *)v0 = -1;
  return result;
}



// get_status_byte @ 0x1006cc
/* luna: Returns the volatile RF status byte at offset 1 from the status buffer base. */
int get_status_byte() {
  return *((volatile uint8_t *)off_1006D4 + 1);
}



// send_command @ 0x1006d8
/* luna: Writes 0x11 to the hardware control register, waits for ten timer ticks, clears the register, then waits another ten ticks before returning 32. */
int send_command() {
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


// enable_interrupt @ 0x100730
/* luna: Enables the RF interrupt path by setting control bits and clearing the associated status register. */
volatile uint32_t *enable_interrupt() {
  volatile uint32_t *result; // r0
  volatile int *v1; // r2

  result = (void *)(uintptr_t)(off_100764);
  v1 = (volatile int *)off_100768;
  *(volatile uint32_t *)off_100760 |= 0x10000u;
  *result = 0;
  *v1 = *v1 & 0x1FFFFFFE | 0x20000001;
  return result;
}



// disable_interrupt @ 0x10076c
/* luna: Disables the RF interrupt by clearing bit 16 in one MMIO register and updating two related control registers. */
volatile uint32_t *disable_interrupt() {
  volatile uint32_t *result; // r0
  volatile unsigned int *v1; // r2

  result = (void *)(uintptr_t)(off_10079C);
  v1 = (volatile unsigned int *)off_1007A0;
  *(volatile uint32_t *)off_100798 &= ~0x10000u;
  *result = 1;
  *v1 = *v1 & 0x1FFFFFFE | 0xC0000000;
  return result;
}



// memcpy_words @ 0x1007a4
/* luna: Copies three 32-word blocks from source to destination, applying a byte-level conversion to mask-selected blocks while preserving marker-matching word */
int memcpy_words(int result, int a2, int a3, unsigned int a4) {
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



// prepare_operation @ 0x100898
/* luna: Selects a band- and frequency-dependent RF profile value, writes a three-bit derived mask to the output pointer, and returns the selected value. */
int prepare_operation(int a1, unsigned int a2, volatile uint32_t *a3) {
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



// bt_enable @ 0x1009a0
/* luna: Prepares a destination and copies 96 words from a static operation table while temporarily enabling bit 26 in a control register. */
int bt_enable(int a1, unsigned int a2) {
  volatile unsigned int *v2; // r5
  int v3; // r0
  unsigned int v4; // r4
  int result; // r0
  unsigned int v6; // [sp+4h] [bp-8h] BYREF

  v2 = (volatile unsigned int *)off_1009D4;
  v3 = prepare_operation(a1, a2, (void *)(&v6));
  v4 = *v2;
  *v2 |= 0x4000000u;
  result = memcpy_words(v3, dword_1009D8, 96, v6);
  *v2 = v4 & 0xFBFFFFFF;
  return result;
}



// bt_control_set @ 0x1009dc
/* luna: Copies a fixed configuration block through a four-bank hardware window, then programs 24 MAC reset-control values from paired input words. */
int bt_control_set(int a1, int a2) {
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
    mac_reset_control((2 * i) & 0xFE, *(volatile uint32_t *)(a2 + 8 * i));
    v17 = *(volatile uint32_t *)(a2 + 4 + 8 * i);
    result = mac_reset_control(v15, v17);
    v15 = (uint8_t)(v15 + 2);
  }
  *(volatile uint32_t *)off_100AA4 &= ~2u;
  return result;
}



// clock_enable @ 0x100aa8
/* luna: Sets RF clock-control bits, copies a 0x2000-byte block to its configured destination, and returns the destination-minus-source offset. */
int clock_enable() {
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



// bt_init @ 0x100b14
/* luna: Configures and enables the RF hardware, programming a parameter-derived register field and fixed control bits. */
volatile uint32_t * bt_init(int a1) {
  uint64_t v1; // r0
  uint64_t v2; // r2
  volatile unsigned int *v3; // r5
  volatile unsigned int *v4; // r4
  uint64_t v5; // r0
  uint64_t v6; // r0
  uint16_t v7; // r0
  volatile uint32_t *v8; // r2
  volatile uint32_t *v9; // r1
  volatile uint32_t *result; // r0
  volatile uint8_t *v11; // r5

  v1 = int_to_double(a1);
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_100B74) << 32);
  v3 = (volatile unsigned int *)off_100B78;
  v4 = (volatile unsigned int *)off_100B7C;
  v2 = (v2 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
  v5 = ((uint64_t (*)())double_subtract)(v1, v2);
  v6 = double_add(v5);
  v7 = ((int (*)(uint64_t))double_to_int)(v6);
  v8 = (void *)(uintptr_t)(off_100B80);
  v9 = (void *)(uintptr_t)(off_100B84);
  *v3 = (uint16_t)(v7 << 8) | *v3 & 0xFFFF00FF;
  result = (void *)(uintptr_t)(off_100B88);
  v11 = (void *)(uintptr_t)(off_100B8C);
  *v4 = *v4 & 0xFFFFF9FF | 0x200;
  *v8 |= 0x40000000u;
  *v8 |= 0x80000000;
  *v9 = 4096;
  *result |= 0x1000u;
  *v11 = 1;
  return result;
}


// rf_config @ 0x100b90
/* luna: Clears selected bits in several RF control registers, zeroes a byte-sized setting, and returns the address of the register whose bit 12 was cleared. */
volatile uint32_t *rf_config() {
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



// variadic_call_1006d8 @ 0x100be0
/* luna: Configures RF hardware and related band and channel-control registers using the supplied mode, frequency values, and flags. */
volatile char * variadic_call_1006d8(int a1, unsigned int a2, unsigned int a3, int a4, char a5) {
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
  volatile char *result; // r0
  volatile unsigned int *v22; // r2
  signed int v23; // r3
  int v24; // r2
  volatile unsigned int *v25; // r1
  volatile unsigned int *v26; // r2
  volatile unsigned int *v27; // r2
  volatile uint32_t *v28; // r1
  volatile uint32_t *v29; // r2
  volatile uint32_t *v30; // r1
  int v31; // r2

  v5 = (volatile int *)off_100E20;
  send_command();
  if ( *((volatile uint8_t *)v5 + 413) && *(volatile uint8_t *)off_100DE8 )
  {
    rf_config();
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
        bt_init(a3);
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
      if ( (int)(a3 - a2) <= 0 )
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
      v15 = ((uint8_t)((int)((uint64_t)((int32_t)dword_100E14 * (int64_t)(int32_t)(int)(a2 - (a3 - 30))) >> 32) >> 3)
           - (uint8_t)((int)(a2 - (a3 - 30)) >> 31))
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
  if ( a3 <= a2 )
    v31 = 2;
  else
    v31 = 1;
  *(volatile uint32_t *)off_100E00 = v31;
  v15 = a3 <= a2;
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
  result = v16 - 80;
  *v20 = v19 | *v20 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = (volatile char *)off_100E18;
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
    *((volatile uint32_t *)result + 1) = *((volatile uint32_t *)result + 1) & 0xFFFFFF | 0x19000000;
    v20[15866] &= 0xFFFFFFCF;
    *v22 = *v22 & 0xFFFF00FF | 0x9C00;
  }
  return result;
}


// rng_read @ 0x100e24
/* luna: Configures the RF-side random source registers and conditionally pulses a control bit when the input is zero and the existing mode field is not 7. */
int rng_read(int result) {
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
  *v1 = *v1 & 0xFFFFFFF8 | 3;
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



// rng_read_alt @ 0x100ee8
/* luna: Programs RF control fields from the stored configuration and pulses an update control when the prior mode field is not 4. */
volatile uint32_t *rng_read_alt() {
  volatile unsigned int *v0; // r3
  volatile uint32_t *v1; // r1
  unsigned int v2; // r4
  volatile uint32_t *result; // r0
  volatile uint32_t *v4; // r3

  v0 = (volatile unsigned int *)off_100F98;
  v1 = (void *)(uintptr_t)(off_100F9C);
  v2 = *(volatile uint32_t *)off_100F98;
  result = (void *)(uintptr_t)(off_100FA0);
  *(volatile uint32_t *)off_100F9C = (*((volatile uint8_t *)off_100F94 + 1) << 10) & 0x1FC00 | *(volatile uint32_t *)off_100F9C & 0xFFFE03FF;
  *v0 = *v0 & 0xFFFFFFE7 | 8;
  *v0 |= 7u;
  *v1 &= ~0x80000u;
  *v1 &= ~0x40000u;
  *v0 = *v0 & 0xFFFFFC1F | 0x80;
  *result |= 2u;
  *result &= ~1u;
  if ( ((v2 >> 5) & 0x1F) != 4 )
  {
    v4 = (void *)(uintptr_t)(off_100FA4);
    *(volatile uint32_t *)off_100FA4 |= 0x80u;
    *v4 &= ~0x40u;
    *v4 |= 0x40u;
    *v4 &= ~0x80u;
  }
  return result;
}



// bb_enable @ 0x100fa8
/* luna: Enables and configures the baseband/RF path for the requested 2.4-GHz frequency, applying frequency-dependent register settings. */
int bb_enable(unsigned int a1, int a2) {
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
  peripheral_read_32(1, 0, 16, *v9);
  peripheral_read_32(1, 16, 16, *(volatile uint32_t *)off_10122C);
  bt_enable(0, a1);
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
  *v23 = *v23 & 0xFFF1FFFF | 0x60000;
  while ( !*v27 )
    ;
  result = *(volatile uint32_t *)off_10125C & 1;
  if ( !result )
    result = rng_read(0);
  *(volatile uint32_t *)off_101258 = 1;
  return result;
}



// bb_disable @ 0x101260
/* luna: Configures RF and baseband registers for the requested operating frequency. */
volatile uint32_t * bb_disable(unsigned int a1) {
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

  v1 = (void *)(uintptr_t)(off_1014EC);
  v2 = (void *)(uintptr_t)(off_1014F0);
  *(volatile uint32_t *)off_1014EC &= ~0x400u;
  v3 = (void *)(uintptr_t)(off_1014F4);
  v4 = (void *)(uintptr_t)(off_1014F8);
  v5 = (volatile unsigned int *)off_1014FC;
  *v1 &= ~0x800u;
  *v3 |= 4u;
  v6 = (void *)(uintptr_t)(off_101500);
  *v4 |= 0x80000u;
  *v4 &= ~0x100000u;
  *v2 |= 0x400u;
  *v2 &= ~0x100u;
  *v2 |= 0x80u;
  v7 = (volatile unsigned int *)off_101504;
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
  v8 = (volatile unsigned int *)off_101508;
  *(volatile unsigned int *)((volatile char *)v7 + 0xFFFFFFBC) &= 0xFFFFC7FF;
  *v8 = *v8 & 0xFFFFF83F | 0x400;
  v1[16] = v1[16] & 0xFFFFE3FF | 0x1000;
  *v6 |= 0xC00u;
  v9 = (void *)(uintptr_t)(off_10150C);
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
        v14 = (volatile int *)off_101750;
        v15 = (volatile int *)off_101738;
        v13 = dword_10173C;
        v16 = dword_101740;
        v47 = dword_101744;
        *(volatile uint32_t *)off_101734 = dword_10173C;
        *v14 = v47;
        *v15 = v16;
        v18 = 0x80000000;
        v19 = 1610612736;
        goto LABEL_4;
      }
      if ( a1 <= 0x1612 )
      {
        v14 = (volatile int *)off_101544;
        v15 = (volatile int *)off_101518;
        v13 = dword_101538;
        v16 = dword_10153C;
        v30 = dword_101540;
        *(volatile uint32_t *)off_101510 = dword_101538;
        *v14 = v30;
        *v15 = v16;
        v18 = 0;
        v19 = 1610612736;
        goto LABEL_4;
      }
      v12 = (volatile int *)off_101734;
      v13 = dword_10173C;
      v14 = (volatile int *)off_101750;
      v15 = (volatile int *)off_101738;
      v16 = dword_101740;
      if ( a1 <= 0x1662 )
      {
        v48 = dword_101748;
        *(volatile uint32_t *)off_101734 = dword_10173C;
        *v14 = v48;
        *v15 = v16;
        v18 = 0;
        v19 = 0x40000000;
        goto LABEL_4;
      }
      v17 = dword_10174C;
    }
    else
    {
      v12 = (volatile int *)off_101510;
      v13 = dword_101514;
      v14 = (volatile int *)off_101544;
      v15 = (volatile int *)off_101518;
      v16 = dword_10151C;
      v17 = dword_101534;
    }
  }
  else
  {
    v12 = (volatile int *)off_101510;
    v13 = dword_101514;
    v14 = (volatile int *)off_101544;
    v15 = (volatile int *)off_101518;
    v16 = dword_10151C;
    v17 = dword_101520;
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
  peripheral_read_32(1, 0, 16, v13);
  peripheral_read_32(1, 16, 16, *v14);
  peripheral_read_32(1, 32, 16, *v15);
  bt_enable(1, a1);
  v24 = (void *)(uintptr_t)(off_101524);
  v25 = (volatile unsigned int *)off_101528;
  *(volatile uint32_t *)off_101524 |= 8u;
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
      v26 = *(volatile uint8_t *)off_10152C;
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
  v26 = *(volatile uint8_t *)off_1016D8;
  if ( v26 == 3 )
  {
LABEL_16:
    v29 = dword_101530;
    goto LABEL_26;
  }
LABEL_24:
  v29 = dword_1016DC;
  if ( v26 != 7 )
    v29 = 0;
LABEL_26:
  v31 = (volatile unsigned int *)off_1016E4;
  *(volatile uint32_t *)off_1016E0 = *(volatile uint32_t *)off_1016E0 & 0xFFFFFF00 | *(volatile uint8_t *)(v29 + v28);
  v32 = (void *)(uintptr_t)(off_1016E8);
  *v31 = *v31 & 0xFFFFFF00 | *(volatile uint8_t *)(v29 + v28 + 1);
  if ( !v32[1] )
  {
    v33 = (void *)(uintptr_t)(off_1016EC);
    v31[1918] &= 0xFFFFFC7F;
    *v33 &= ~0x8000u;
  }
  v34 = (void *)(uintptr_t)(off_1016F4);
  v35 = *(volatile uint32_t *)off_1016F0 & 0xFF00FFFF;
  if ( v27 <= 1 )
    v35 |= 0x1F0000u;
  *(volatile uint32_t *)off_1016F0 = v35;
  v36 = (volatile unsigned int *)off_1016F8;
  v37 = (volatile unsigned int *)off_1016FC;
  *v34 &= ~0x4000u;
  *v36 = *v36 & 0xFFF8FFFF | 0x20000;
  *v36 = *v36 & 0xFFFFFFF0 | 8;
  *v37 = *v37 & 0xFFF1FFFF | 0x60000;
  if ( a1 <= 0x15E4 )
  {
    v44 = (volatile uint64_t *)off_101700;
    if ( a1 <= 0x14D6 )
    {
      v46 = qword_101728;
      *((volatile uint32_t *)off_101700 + 2) = dword_101730;
      *v44 = v46;
      v40 = 0;
    }
    else
    {
      v45 = qword_10171C;
      *((volatile uint32_t *)off_101700 + 2) = dword_101724;
      *v44 = v45;
      v40 = 1;
    }
  }
  else
  {
    v38 = (volatile uint64_t *)off_101700;
    v39 = qword_101704;
    *((volatile uint32_t *)off_101700 + 2) = dword_10170C;
    *v38 = v39;
    v40 = 2;
  }
  v41 = (void *)(uintptr_t)(off_101710);
  if ( *(volatile uint8_t *)off_101710 != v40 )
    call_transfer(0);
  v42 = (void *)(uintptr_t)(off_101714);
  *v41 = v40;
  while ( !*v42 )
    ;
  result = (volatile uint32_t *)(*(volatile uint32_t *)off_101718 & 1);
  if ( result )
    goto LABEL_40;
  if ( a1 - 5270 <= 0x32 || a1 - 5550 <= 0x64 )
  {
    result = rng_read_alt();
LABEL_40:
    *(volatile uint32_t *)off_101714 = 1;
    return result;
  }
  result = (volatile uint32_t *)rng_read(0);
  *(volatile uint32_t *)off_101714 = 1;
  return result;
}



// event_queue_check @ 0x101754
/* luna: Configures RF and baseband control registers with revision-dependent settings and returns the initialization value. */
int event_queue_check() {
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

  if ( **(volatile int16_t **)off_1018DC < 0
    && (uint8_t)BYTE2(*(volatile uint32_t *)off_101928) + 10 * (HIBYTE(*(volatile uint32_t *)off_101928) + 2) != 32 )
  {
    mmio_clear_register((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  send_command();
  v0 = (void *)(uintptr_t)(off_1018E4);
  v1 = (void *)(uintptr_t)(off_1018E8);
  *(volatile uint32_t *)off_1018E0 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(volatile uint32_t *)off_1018E8 >> 4 == 2 )
    *(volatile uint32_t *)off_1018EC = dword_1018F0;
  v2 = (void *)(uintptr_t)(off_1018F4);
  v3 = (volatile unsigned int *)off_1018F8;
  v4 = (volatile unsigned int *)off_1018FC;
  v5 = (void *)(uintptr_t)(off_101900);
  v6 = (void *)(uintptr_t)(off_101904);
  v7 = (void *)(uintptr_t)(off_1018E0);
  *(volatile uint32_t *)off_1018F4 = *(volatile uint32_t *)off_1018F4 & 0xFFFFF800 | 0x700;
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
  v9 = (volatile unsigned int *)off_101908;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v10 = (volatile unsigned int *)off_10190C;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = (void *)(uintptr_t)(off_101914);
  v12 = (void *)(uintptr_t)(off_101918);
  result = dword_101920;
  *(volatile uint32_t *)off_101910 = dword_10191C;
  *v11 = result;
  v14 = BYTE2(((volatile uint32_t *)(uintptr_t)off_101924)[101]);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
  return result;
}


// poll_status @ 0x101934
/* luna: When status bit 3 is set, reads the timer counter and acknowledges that status bit; otherwise returns the incoming value unchanged. */
int poll_status(int result, int a2, int a3) {
  if ( (*(volatile uint32_t *)off_10194C & 8) != 0 )
  {
    result = (int)(uintptr_t)(timer_get_counter(result, a2, a3, *(volatile uint32_t *)off_10194C << 28));
    *(volatile uint32_t *)off_101950 = 8;
  }
  return result;
}



// rf_copy_register @ 0x101954
/* luna: Copies the RF status register, dispatches event 16 when bit 12 is set after clearing that bit in the preceding register, and otherwise logs the status */
int rf_copy_register() {
  volatile char *v0; // r2
  int v1; // r1

  v0 = (volatile char *)off_101978;
  v1 = *(volatile uint32_t *)off_101978;
  *(volatile uint32_t *)off_10197C = *(volatile uint32_t *)off_101978;
  if ( (v1 & 0x1000) == 0 )
    return event_dispatch("no other rc isr: %x\n", v1);
  *(volatile uint32_t *)&v0[-8] &= ~0x1000u;
  return unknown_func_12d104(16);
}


// rf_read_timestamps @ 0x101984
/* luna: Reads two RF timestamp register values into caller-provided locations and returns the first output pointer. */
volatile uint32_t * rf_read_timestamps(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_101998);
  *result = *(volatile uint32_t *)off_101994;
  *a2 = *v2;
  return result;
}



// rf_call_handler @ 0x10199c
/* luna: Stores the configured 64-bit fallback value in the output and logs an error if the requested radio does not exist. */
volatile uint64_t * rf_call_handler(volatile uint64_t *result, int a2) {
  volatile uint64_t *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (volatile uint64_t *)event_dispatch("\x9B\x87%s: radio %d does not exist\n", aPhyGetChannel, a2);
    *v2 = *(volatile uint64_t *)((volatile char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(volatile uint64_t *)((volatile char *)off_1019C4 + 36);
  }
  return result;
}


// rf_get_status @ 0x1019d0
/* luna: Logs when the MAC state is non-idle; otherwise returns the first argument. */
int rf_get_status(int a1, int a2, int a3) {
  if ( *(volatile uint32_t *)off_1019E4 << 28 )
    return event_dispatch("\x9B%s MAC state != IDLE\n", aPhyStop);
  return a1;
}


// get_constant_1000 @ 0x1019f0
/* luna: Returns the constant value 1000. */
int get_constant_1000() {
  return 1000;
}



// return_true @ 0x1019f8
/* luna: Returns 1 unconditionally. */
int return_true() {
  return 1;
}



// rf_get_status_bit21 @ 0x1019fc
/* luna: Returns bit 21 of the RF status register. */
int rf_get_status_bit21() {
  return (*(volatile uint32_t *)off_101A08 >> 21) & 1;
}



// rf_check_status @ 0x101a0c
/* luna: Returns true when the RF status word at its fixed address is greater than one. */
BOOL rf_check_status() {
  return *(volatile uint32_t *)off_101A1C > 1u;
}



// rf_set_pa_bit @ 0x101a20
/* luna: Sets bit 3 of the RF control register from the low bit of the argument and returns the updated register value. */
unsigned int rf_set_pa_bit(int a1) {
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(volatile uint32_t *)off_101A34 & 0xFFFFFFF7;
  *(volatile uint32_t *)off_101A34 = result;
  return result;
}



// rf_get_status_bit26 @ 0x101a38
/* luna: Returns bit 26 of the RF status register. */
int rf_get_status_bit26() {
  return (*(volatile uint32_t *)off_101A44 >> 26) & 1;
}



// rf_get_status_bit28 @ 0x101a48
/* luna: Returns bit 28 of the RF status register. */
int rf_get_status_bit28() {
  return (*(volatile uint32_t *)off_101A54 >> 28) & 1;
}



// rf_get_status_bit30 @ 0x101a58
/* luna: Returns bit 30 of the RF status register. */
int rf_get_status_bit30() {
  return (*(volatile uint32_t *)off_101A64 >> 30) & 1;
}



// rf_set_address @ 0x101a68
/* luna: Copies two 32-bit words from the first input and four from the second into a fixed RF block, then returns the first input pointer. */
volatile uint32_t * rf_set_address(volatile uint32_t *result, volatile uint32_t *a2) {
  volatile uint32_t *v2; // r3

  v2 = (void *)(uintptr_t)(off_101A84);
  *(volatile uint32_t *)off_101A84 = *result;
  v2[1] = result[1];
  v2[2] = *a2;
  v2[3] = a2[1];
  v2[4] = a2[2];
  v2[5] = a2[3];
  return result;
}



// rf_set_channel @ 0x101a88
/* luna: Writes the low 11 bits of the requested channel to an RF register, clears the corresponding field in another register, and sets the low 11 bits of a t */
int rf_set_channel(int16_t a1) {
  int v1; // r4
  volatile uint32_t *v2; // r1
  volatile int *v3; // r2
  int result; // r0

  v1 = dword_101AB8;
  v2 = (void *)(uintptr_t)(off_101ABC);
  v3 = (volatile int *)off_101AC0;
  result = a1 & 0x7FF;
  *(volatile uint32_t *)off_101AB4 = *(volatile uint32_t *)off_101AB4 & dword_101AB8 | result;
  *v2 &= v1;
  *v3 = ~(~((unsigned int)*v3 >> 11) << 11);
  return result;
}



// rf_get_field8 @ 0x101ac4
/* luna: Returns bits 8–11 of the RF register minus one, truncated to an unsigned byte. */
int rf_get_field8() {
  return (uint8_t)((BYTE1(*(volatile uint32_t *)off_101AD4) & 0xF) - 1);
}



// rf_get_field4 @ 0x101ad8
/* luna: Returns the value of bits 4–7 from the RF register at off_101AE8, minus one. */
int rf_get_field4() {
  return (uint8_t)(((uint8_t)*(volatile uint32_t *)off_101AE8 >> 4) - 1);
}



// rf_get_field0 @ 0x101aec
/* luna: Returns the low nibble of the RF status byte at 0x101AFC, decremented with 8-bit wraparound. */
int rf_get_field0() {
  return (uint8_t)((*(volatile uint8_t *)off_101AFC & 0xF) - 1);
}



// rf_poll_handler @ 0x101b00
/* luna: Computes per-chain RF gain IDs using frequency-dependent calibration and optional channel-event limits. */
int rf_poll_handler(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
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

  result = *((volatile uint8_t *)off_101D28 + 36);
  v5 = *((volatile uint16_t *)off_101D28 + 20);
  if ( !*((volatile uint8_t *)off_101D28 + 36) )
  {
    if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_101D2C)[49]) )
    {
      if ( v5 > 0x97B )
      {
        if ( v5 > 0x994 )
          result = 2;
        else
          result = 1;
      }
      v7 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101D2C)[49]);
      v8 = SBYTE2(((volatile uint32_t *)(uintptr_t)off_101D2C)[52]);
      v9 = *(volatile uint8_t *)(off_101D34 + 0xA) + *(volatile uint8_t *)off_101D38 + *(volatile uint8_t *)(*(volatile uint32_t *)off_101D30 + result + 6);
      v10 = *(volatile uint8_t *)off_101D38 + *(volatile uint8_t *)(off_101D34 + 8) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101D30 + result);
      v11 = v10;
      if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101D2C)[99]) )
      {
        result = *(volatile uint8_t *)(*(volatile uint32_t *)off_101D3C + result);
        v7 = (char)(result + v7);
        v8 = (char)(v8 + result);
      }
      if ( (((volatile uint32_t *)(uintptr_t)off_101D2C)[98] & 2) != 0 )
      {
        result = (int)ke_event_get(0, *((volatile uint16_t *)off_101D28 + 20));
        v11 = v10;
        if ( result )
        {
          v20 = *(volatile char *)(result + 4);
        }
        else
        {
          if ( **(volatile int16_t **)off_101D48 < 0 )
          {
            call_shared_handler(off_101D50, (int)aPhyGetRfGainId, 6857);
            v11 = v10;
          }
          v22 = v11;
          result = event_dispatch("invalid chan, band=%d, freq=%d\n", 0, v5);
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
    if ( **(volatile int16_t **)off_101D48 >= 0 )
      return result;
    v19 = 6875;
    return mmio_clear_register(off_101D50, (int)aPhyGetRfGainId, v19);
  }
  if ( !BYTE1(((volatile uint32_t *)(uintptr_t)off_101D2C)[49]) )
  {
    if ( **(volatile int16_t **)off_101D48 >= 0 )
      return result;
    v19 = 6921;
    return mmio_clear_register(off_101D50, (int)aPhyGetRfGainId, v19);
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
  result = LOBYTE(((volatile uint32_t *)(uintptr_t)off_101D2C)[99]);
  v15 = SLOBYTE(((volatile uint32_t *)(uintptr_t)off_101D2C)[59]);
  v16 = *(volatile uint8_t *)(off_101D38 + 1) + *(volatile uint8_t *)(off_101D34 + 0xB) + *(volatile uint8_t *)(*(volatile uint32_t *)off_101D40 + v14);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101D2C)[99]) )
    v15 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101D44 + v14) + v15);
  if ( (((volatile uint32_t *)(uintptr_t)off_101D2C)[98] & 2) != 0 )
  {
    result = (int)ke_event_get(1, *((volatile uint16_t *)off_101D28 + 20));
    if ( result )
    {
      v21 = *(volatile char *)(result + 4);
    }
    else
    {
      if ( **(volatile int16_t **)off_101D48 < 0 )
        call_shared_handler(off_101D50, (int)aPhyGetRfGainId, 6907);
      result = event_dispatch("invalid chan, band=%d, freq=%d\n", 1, v5);
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


// rx_packet_handler @ 0x101d58
/* luna: Calculates a frequency- and mode-dependent transmit-power setting from RF calibration tables and applies the channel power limit. */
int rx_packet_handler(unsigned int a1, signed int a2, volatile uint8_t *a3) {
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
      v8 = *((volatile char *)&((volatile uint32_t *)(uintptr_t)off_101EFC)[49] + a2 + 2);
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
      v6 = (volatile char *)off_101EFC + a2;
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
    v12 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101F00 + v11 + v9) + *(volatile uint8_t *)(dword_101F04 + v10 + 8) + *(volatile uint8_t *)off_101F08;
    v13 = v12;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101EFC)[99]) )
      v8 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101F0C + v11) + v8);
    goto LABEL_18;
  }
  v16 = (volatile char *)off_101EFC + a2;
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
  v12 = *(volatile uint8_t *)(*(volatile uint32_t *)off_101F10 + v21 + v19) + *(volatile uint8_t *)(dword_101F04 + v20 + 11) + *(volatile uint8_t *)(off_101F08 + 1);
  v13 = v12;
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_101EFC)[99]) )
    v8 = (char)(*(volatile uint8_t *)(*(volatile uint32_t *)off_101F14 + v21) + v8);
LABEL_18:
  if ( (((volatile uint32_t *)(uintptr_t)off_101EFC)[98] & 2) != 0 )
  {
    v22 = ke_event_get(v3, v4);
    if ( v22 )
    {
      v23 = v22[4];
    }
    else
    {
      if ( **(volatile int16_t **)off_101F18 < 0 )
        call_shared_handler(off_101F24, (int)aPhyGetTxpwrLev, 7022);
      event_dispatch("invalid chan, band=%d, freq=%d\n", v3, v4);
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


// rf_set_tx_power @ 0x101f28
/* luna: Encodes the requested TX power into an RF register, selects control bits based on its sign and parity, and returns the input value. */
int rf_set_tx_power(int result) {
  volatile uint32_t *v1; // r2
  unsigned int v2; // r3
  int v3; // r3

  v1 = (void *)(uintptr_t)(off_101F68);
  *(volatile uint32_t *)off_101F64 = *(volatile uint32_t *)off_101F64 & 0xFFFFFF | ((uint8_t)(result / 2) << 24);
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



