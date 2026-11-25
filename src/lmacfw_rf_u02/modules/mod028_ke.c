// exit_critical_section @ 0x123240
int exit_critical_section() {
  volatile int *v0; // r6
  int v1; // r0
  int result; // r0
  int v3; // r4
  int v4; // r3
  int v5; // r2
  volatile uint8_t **v6; // r7
  int v7; // r5
  int v8; // r0
  int v9; // r3
  int v10; // r2
  volatile uint8_t **v11; // r0
  int v12; // r0
  volatile uint8_t *a1[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_123330 = 1;
  }
  v0 = (volatile int *)off_123334;
  v1 = dword_123338;
  ++*(volatile uint32_t *)off_123334;
  result = (int)list_pop_front(v1);
  v3 = result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(volatile uint32_t *)off_123330;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (volatile uint8_t **)off_12333C;
    do
    {
      v7 = str_skip_spaces((volatile uint8_t *)(v3 + 4), (int)a1);
      if ( v7 )
      {
        v11 = (void *)(parse_dot_separated((int)(uintptr_t)(a1[0]), (void *)(v6), 55));
        if ( v11 )
        {
          if ( *((volatile uint16_t *)v11 + 5) < v7 || *((volatile uint16_t *)v11 + 4) > v7 )
          {
            log_printf(aUsageSS, *v11, v11[1]);
          }
          else
          {
            v12 = ((int ( *)(int, volatile uint8_t **))v11[3])(v7, a1);
            if ( v12 )
              log_printf("Command fail, ret=%d\r\n", v12);
          }
        }
        else
        {
          log_printf("Unknown command '%s'\r\n", (const volatile char *)a1[0]);
        }
      }
      else
      {
        uart_tx_string(aNoCommand);
      }
      uart_tx_string(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_123330 = 1;
      }
      v8 = dword_123348;
      ++*v0;
      check_kernel_state(v8, (volatile uint32_t *)v3);
      result = (int)list_pop_front(dword_123338);
      v3 = result;
      if ( *v0 )
      {
        v9 = *v0 - 1;
        v10 = *(volatile uint32_t *)off_123330;
        *v0 = v9;
        if ( !v9 )
        {
          if ( v10 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}


// wait_hw_interrupt_flag @ 0x123358
void wait_hw_interrupt_flag() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r0

  v0 = (void *)(uintptr_t)(off_12338C);
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = uart_rx_byte();
      if ( process_queue_message(v1) > 0 )
      {
        if ( *(volatile uint8_t *)off_123390 )
          exit_critical_section();
        return;
      }
    }
  }
}



// increment_debug_counter @ 0x123394
int increment_debug_counter(int a1) {
  volatile uint32_t *v1; // r1
  int v2; // r0
  int result; // r0

  v1 = (void *)(uintptr_t)(off_1233C0);
  v2 = *(volatile uint32_t *)(a1 + 4);
  ++*(volatile uint16_t *)off_1233BC;
  result = mmio_write_register(v2 + *v1);
  *(volatile uint32_t *)off_1233C4 += *(volatile char *)off_1233C8;
  return result;
}



// check_chip_version @ 0x1233cc
float check_chip_version(volatile uint8_t *a1) {
  int v1; // r2
  int v2; // r5
  int v3; // r4
  int v4; // r6
  volatile int *v5; // r7
  int v6; // r2
  int v7; // r1
  int v8; // r6
  int v9; // r3
  volatile unsigned int v10; // r0
  float v11; // s16
  float result; // r0

  v1 = (uint8_t)*(volatile uint8_t *)(uintptr_t)(off_123474);
  v2 = HIWORD(*(volatile uint32_t *)off_123478) & 0x3F;
  v3 = *(volatile uint32_t *)off_123478 & 0xFFF;
  if ( v1 == a1[1] )
  {
    v4 = dword_12347C;
    v5 = (volatile int *)off_123480;
    v6 = v1 - 1;
    *(volatile uint16_t *)(dword_12347C + 8 * v6) = a1[4] | (a1[5] << 8);
    v7 = v4 + 8 * v6;
    v6 = (v6 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v7 + 2)) & 0xFFu);
    v8 = *v5;
    v9 = *(volatile char *)off_123484;
    *(volatile uint8_t *)(v7 + 5) = a1[6];
    *(volatile uint8_t *)(v7 + 2) = v6 + 1;
    *v5 = v9 + v8;
  }
  v10 = REG_4032_0120;
  mmio_write_register(v10 + 20000);
  v11 = COERCE_FLOAT(float_to_double(COERCE_UNSIGNED_INT((float)(unsigned int)v3)));
  result = COERCE_FLOAT(float_to_double(COERCE_UNSIGNED_INT((float)(1 << v2))));
  *(volatile float *)off_12348C = (float)((float)(v11 * 10.0) - (float)(result * 10.0)) + *(volatile float *)off_12348C;
  return result;
}


// validate_signature @ 0x123490
volatile uint8_t * validate_signature(volatile uint8_t *result) {
  int v1; // r4
  volatile uint32_t *v2; // r3
  char v3; // r2

  if ( result[1] == 192 && result[2] == 181 && result[3] == 122 )
  {
    v1 = result[4];
    if ( (uint8_t)(v1 + 106) <= 1u )
    {
      v2 = (void *)(uintptr_t)(off_1234DC);
      *(volatile uint8_t *)off_1234D8 = result[5];
      result = (volatile uint8_t *)mmio_write_register(*v2 + 20000);
      if ( v1 == 150 )
        v3 = 2;
      else
        v3 = 0;
      *(volatile uint8_t *)off_1234E0 = v3;
    }
  }
  return result;
}



// read_irq_status @ 0x1234e4
int read_irq_status(int result) {
  volatile uint8_t *v1; // r6
  volatile uint8_t *v2; // r5
  volatile uint8_t *v3; // r7
  uint64_t v4; // r2
  uint8_t v5; // r4
  int v6; // r3
  int v7; // r3
  int v8; // r7
  int v9; // r4
  int v10; // r0
  int v11; // r4
  int v12; // r3
  int v13; // r6
  int v14; // r4
  int v15; // r0
  volatile int *v16; // r2
  int v17; // r4
  int v18; // r3
  int v19; // r4
  int v20; // r2
  int v21; // r1
  int v22; // r4
  struct __attribute__((packed)) { uint8_t a1; // [sp+Eh] [bp-6h] BYREF
  uint8_t v24[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  v1 = (void *)(uintptr_t)(off_1236C4);
  v2 = (volatile uint8_t *)off_1236C8;
  v3 = (void *)(uintptr_t)(off_1236CC);
  v4 = (v4 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint8_t *)off_1236CC) << 32);
  v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint8_t *)off_1236C4 | *(volatile uint8_t *)off_1236C8) & 0xFFFFFFFFu);
  v5 = BYTE4(v4) | v4;
  if ( !v4 )
  {
    result = mmio_set_control();
    if ( (*(volatile uint8_t *)off_1236D0 & 0xFD) == 1 )
    {
      _frame.a1 = v5;
      _frame.v24[0] = v5;
      mmio_read_status(&_frame.a1);
      mmio_read_byte(_frame.v24);
      dispatch_event_handler_1("xtal efuse=%x,%x\n", _frame.a1, _frame.v24[0]);
      result = _frame.a1;
      if ( _frame.a1 )
      {
        if ( _frame.a1 > 0x1Fu )
        {
          result = 31;
          _frame.a1 = 31;
        }
        set_xtal_ftune(result);
        result = dispatch_event_handler_1("set xtal_cap 0x%x\n", _frame.a1);
      }
      v21 = _frame.v24[0];
      if ( _frame.v24[0] )
      {
        if ( _frame.v24[0] > 0x3Fu )
        {
          v21 = 63;
          _frame.v24[0] = 63;
          v22 = 16515072;
        }
        else
        {
          v22 = (_frame.v24[0] << 18) & 0xFC0000;
        }
        *(volatile uint32_t *)off_1236DC = *(volatile uint32_t *)off_1236DC & 0xFF03FFFF | v22;
        result = dispatch_event_handler_1("set xtal_cap_fine 0x%x\n", v21);
      }
    }
    v4 = (v4 & ~0xFF000000u) | (((uint8_t)(*v3) & 0xFFu) << 24);
  }
  v6 = (uint8_t)(BYTE4(v4) + 1);
  if ( v6 != 8 )
  {
    *v3 = v6;
    return result;
  }
  v7 = (uint8_t)*v1;
  *v3 = 0;
  if ( !v7 )
  {
    v8 = *(volatile uint32_t *)off_1236D4;
    if ( (*(volatile uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v8 & 0x1000000) != 0 )
        v9 = 1;
      else
        v9 = -1;
      v10 = get_xtal_ftune() + v9;
      if ( v10 < 1 )
        v10 = 1;
      if ( v10 >= 31 )
        v10 = 31;
      set_xtal_ftune(v10);
    }
    v11 = get_xtal_ftune();
    rf_cmd_check(v11);
    result = dispatch_event_handler_1("xtal_cap : cnt%d %x %x\n", *v2, v11, v8);
    v12 = (uint8_t)(*v2 + 1);
    if ( v12 != 16 )
      goto LABEL_15;
    goto LABEL_33;
  }
  if ( v7 == 1 )
  {
    v18 = *(volatile uint32_t *)off_1236D4;
    if ( (*(volatile uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v18 & 0x1000000) != 0 )
        v19 = 1;
      else
        v19 = -1;
      v20 = ((*(volatile uint32_t *)off_1236DC >> 18) & 0x3F) + v19;
      if ( v20 < 1 )
        v20 = 1;
      if ( v20 >= 63 )
        v20 = 63;
      *(volatile uint32_t *)off_1236DC = *(volatile uint32_t *)off_1236DC & 0xFF03FFFF | (v20 << 18);
    }
    result = dispatch_event_handler_1("cur_cap_fine : cnt%d %x %x\n", *v2, (*(volatile uint32_t *)off_1236DC >> 18) & 0x3F, v18);
    v12 = (uint8_t)(*v2 + 1);
    if ( v12 != 32 )
      goto LABEL_15;
LABEL_33:
    ++*v1;
    *v2 = 0;
    return result;
  }
  v13 = *(volatile uint32_t *)off_1236D4;
  if ( (*(volatile uint32_t *)off_1236D4 & 0x1000000) != 0 )
    v14 = 0x2000000 - v13;
  else
    v14 = *(volatile uint32_t *)off_1236D4;
  v15 = get_xtal_ftune();
  result = dispatch_event_handler_1(
             "xtal_cap %x cap_fine %x cfophase %x %d\n",
             v15,
             (*(volatile uint32_t *)off_1236DC >> 18) & 0x3F,
             v13,
             v14);
  v16 = (volatile int *)off_1236E4;
  v12 = (uint8_t)(*v2 + 1);
  v17 = v14 + *(volatile uint32_t *)off_1236E4;
  *(volatile uint32_t *)off_1236E4 = v17;
  if ( v12 != 16 )
  {
LABEL_15:
    *v2 = v12;
    return result;
  }
  *v2 = 0;
  *v16 = v17 / 16;
  dispatch_event_handler_1("mean abs cfophase %d\n", v17 / 16);
  if ( (unsigned int)*(volatile uint8_t *)off_1236D0 - 2 <= 1 )
    return ll_state_reset();
  else
    return rf_set_flag(2);
}


// handle_cmd_type2 @ 0x1236fc
volatile uint8_t * handle_cmd_type2(volatile uint8_t *result) {
  volatile uint8_t *v1; // r3
  char v2; // r1
  char v3; // r2

  if ( *result == 2 )
  {
    if ( *(volatile uint8_t *)off_123730 == (uint8_t)result[1] )
    {
      v1 = (void *)(uintptr_t)(off_123734);
      v2 = result[3];
      v3 = result[4];
      *((volatile uint8_t *)off_123734 + 2) = result[2];
      v1[3] = v2;
      v1[4] = v3;
    }
    return (volatile uint8_t *)mmio_write_register(*(volatile uint32_t *)off_123738 + 20000);
  }
  return result;
}



// wait_for_hw_event @ 0x12373c
int wait_for_hw_event() {
  volatile char *v0; // r5
  volatile uint8_t *v1; // r8
  volatile int *v2; // r7
  int v3; // r1
  unsigned int v4; // r4
  int result; // r0
  char v6; // r3
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r1
  int v11; // r1
  volatile uint16_t *v12; // r3
  int v13; // r2
  int v14; // r6
  volatile uint8_t *v15; // r0
  int v16; // r2
  struct __attribute__((packed)) { int v17; // [sp+0h] [bp-20h] BYREF
  int16_t v18; // [sp+4h] [bp-1Ch]
  char _pad2[2]; int v19; // [sp+8h] [bp-18h] BYREF
  int16_t v20; // [sp+Ch] [bp-14h]
  char _pad4[2]; uint16_t v21; // [sp+10h] [bp-10h] BYREF
  int16_t v22; // [sp+12h] [bp-Eh]
  int16_t v23; // [sp+14h] [bp-Ch]
  char _pad7[2]; uint16_t v24[4]; // [sp+18h] [bp-8h] BYREF
  } _frame;
  v0 = (volatile char *)off_1238C0;
  v1 = (void *)(uintptr_t)(off_1238DC);
  v2 = (volatile int *)dword_1238C4;
  while ( 1 )
  {
    v4 = timer_event_check();
    result = enter_critical_section_1(0x4000);
    if ( !v4 )
      break;
    rf_cal_offset_apply(v4);
    v6 = *(volatile uint8_t *)(v4 + 65);
    *v0 = v6;
    v0[1] = v6;
    v7 = *(volatile uint32_t *)(v4 + 28);
    v8 = chip_info_nibble0_get();
    v9 = *v0;
    if ( v8 == 1 )
      v9 = (int)((v9 + v0[1] + ((unsigned int)(v9 + v0[1]) >> 31)) << 23) >> 24;
    *v1 = v9;
    if ( rf_flag_is_set() || !*(volatile uint8_t *)off_1238C8 )
    {
      v10 = v2[1];
      _frame.v17 = *v2;
      _frame.v18 = v10;
      v11 = *(volatile uint32_t *)(dword_1238CC + 4);
      _frame.v19 = *(volatile uint32_t *)dword_1238CC;
      _frame.v20 = v11;
      memcpy((void *)(&_frame.v21), (void *)(&_frame.v17), 6);
      memcpy((void *)(_frame.v24), (void *)(&_frame.v19), 6);
      v12 = *(volatile uint16_t **)(v7 + 8);
      v13 = (uint16_t)v12[2];
      if ( (*v12 & 0x80) != 0 )
        v14 = 13;
      else
        v14 = 12;
      v15 = (volatile uint8_t *)&v12[v14];
      if ( _frame.v24[0] == v13 && _frame.v24[1] == (uint16_t)v12[3] && _frame.v24[2] == (uint16_t)v12[4] )
      {
        v3 = _frame.v21;
        if ( (uint16_t)v12[5] == _frame.v21 && _frame.v22 == v12[6] && _frame.v23 == v12[7] )
        {
          if ( *(volatile uint8_t *)off_1238C8 == 1 )
          {
            v16 = *(volatile uint8_t *)off_1238D0;
            switch ( v16 )
            {
              case 2:
                if ( LOBYTE(v12[v14]) == 1 && v15[1] == *(volatile uint8_t *)off_1238D8 )
                  increment_debug_counter((int)v15);
                break;
              case 4:
                handle_cmd_type2(v15);
                break;
              case 1:
                ((int (*)())read_irq_status)();
                break;
            }
          }
          goto LABEL_4;
        }
      }
      else
      {
        v3 = _frame.v21;
      }
      if ( v13 == v3 && _frame.v22 == v12[3] && _frame.v23 == v12[4] && !*(volatile uint8_t *)off_1238C8 )
      {
        if ( *(volatile uint8_t *)off_1238D0 )
        {
          if ( *(volatile uint8_t *)off_1238D0 == 3 && LOBYTE(v12[v14]) == 129 )
            check_chip_version(v15);
        }
        else if ( LOBYTE(v12[v14]) == 128 )
        {
          validate_signature(v15);
        }
      }
    }
LABEL_4:
    ll_event_timer_handler(v4);
  }
  *(volatile uint32_t *)off_1238D4 |= 0x10000u;
  return result;
}



// wait_for_tx_ready @ 0x1238e0
unsigned int wait_for_tx_ready() {
  volatile int *v0; // r10
  volatile int *v1; // r8
  volatile uint32_t *v2; // r7
  int v3; // r11
  unsigned int v4; // r9
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r2
  int v9; // r0
  int v10; // r2
  unsigned int v11; // r6
  unsigned int v12; // r6
  int v13; // r1
  volatile uint8_t *v14; // r4
  unsigned int result; // r0
  int v16; // r4
  unsigned int v17; // r3
  volatile unsigned int *v18; // r3
  int v19; // [sp+14h] [bp-10h]
  int v20; // [sp+18h] [bp-Ch]

  ke_int_lock((int)(uintptr_t)((volatile char *)0x90), 0);
  v0 = (volatile int *)off_123A18;
  v1 = (volatile int *)off_123A1C;
  v2 = (void *)(uintptr_t)(off_1239F8);
  ke_event_loop(144, 0, dword_1239F4);
  v3 = *(volatile uint32_t *)off_1239FC;
  v19 = *(volatile uint32_t *)off_123A00;
  v4 = *(volatile uint32_t *)off_1239FC - *v0;
  v5 = *(volatile uint32_t *)off_123A00 - *v1;
  v6 = *v2;
  v7 = i32_abs(v4);
  if ( i32_abs(v5) > 50000 )
    v8 = 2;
  else
    v8 = v7 > 50000;
  v20 = v8;
  v9 = i32_abs(-v6);
  v10 = v20;
  v11 = v4 + v5;
  if ( v9 > 50000 )
    v10 = 3;
  if ( v6 == v11 || (v12 = v11 - v6, v12 < v4) || v12 < v5 || v12 < -v6 )
  {
    v13 = 4;
LABEL_8:
    v14 = (void *)(uintptr_t)(off_123A08);
    result = dispatch_event_handler_1(
               "\x9A\x88""err=%x,fcs_ok=(%x,%x),fcs_err=(%x,%x),other_err=(%x,%x)\r\n",
               v13,
               *v0,
               v3,
               *v1,
               v19,
               *v2,
               0);
    goto LABEL_9;
  }
  v16 = v5 - v6;
  v13 = v10;
  v17 = 100 * v16 / v12;
  result = 10000 * v16 / v12;
  if ( v10 )
    goto LABEL_8;
  v14 = (void *)(uintptr_t)(off_123A08);
  if ( !*(volatile uint8_t *)off_123A08 )
    goto LABEL_12;
  result = dispatch_event_handler_1("\x9A\x88%4d / %4d, per:%02d.%02d%%\r\n", v4, v12, v17, result - 100 * v17);
  v18 = (volatile unsigned int *)off_123A14;
  *(volatile uint32_t *)off_123A10 = v4;
  *v18 = v12;
LABEL_9:
  if ( !*v14 )
LABEL_12:
    *v14 = 1;
  *v0 = v3;
  *v1 = v19;
  *v2 = 0;
  return result;
}


// build_hci_command @ 0x123a20
int build_hci_command(int a1) {
  int v2; // r1
  uint64_t v3; // r0
  volatile uint16_t *v4; // r2
  int16_t v5; // r3
  int16_t v6; // r1
  int16_t v7; // r5
  int v8; // r0
  struct __attribute__((packed)) { int v10; // [sp+0h] [bp-34h] BYREF
  int16_t v11; // [sp+4h] [bp-30h]
  char _pad2[2]; int v12; // [sp+8h] [bp-2Ch] BYREF
  int16_t v13; // [sp+Ch] [bp-28h]
  char _pad4[2]; int v14; // [sp+10h] [bp-24h] BYREF
  int16_t v15; // [sp+14h] [bp-20h]
  char _pad6[2]; int v16; // [sp+18h] [bp-1Ch] BYREF
  int16_t v17; // [sp+1Ch] [bp-18h]
  char _pad8[2]; uint8_t v18[8]; // [sp+20h] [bp-14h] BYREF
  int v19; // [sp+28h] [bp-Ch] BYREF
  int16_t v20; // [sp+2Ch] [bp-8h]
  } _frame;
  v2 = *((volatile uint32_t *)off_123AA8 + 1);
  _frame.v10 = *(volatile uint32_t *)off_123AA8;
  _frame.v11 = v2;
  v3 = *((volatile uint64_t *)off_123AA8 + 1);
  _frame.v13 = *((volatile uint32_t *)off_123AA8 + 3);
  _frame.v12 = v3;
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint32_t *)(dword_123AAC + 4)) << 32);
  _frame.v14 = *(volatile uint32_t *)dword_123AAC;
  _frame.v15 = WORD2(v3);
  memcpy((void *)(&_frame.v16), (void *)(&_frame.v10), 6);
  memcpy(_frame.v18, (void *)(&_frame.v12), 6);
  memcpy((void *)(&_frame.v19), (void *)(&_frame.v14), 6);
  v4 = (void *)(uintptr_t)(off_123AB0);
  v5 = *((volatile uint16_t *)off_123AB0 + 70);
  *(volatile uint32_t *)(a1 + 10) = _frame.v16;
  v6 = _frame.v20;
  v7 = _frame.v17;
  *(volatile uint8_t *)a1 = 8;
  ++v5;
  v8 = _frame.v19;
  *(volatile uint16_t *)(a1 + 14) = v7;
  *(volatile uint16_t *)(a1 + 8) = v6;
  *(volatile uint16_t *)(a1 + 20) = v6;
  *(volatile uint32_t *)(a1 + 4) = v8;
  *(volatile uint32_t *)(a1 + 16) = v8;
  *(volatile uint8_t *)(a1 + 1) = 2;
  *(volatile uint8_t *)(a1 + 2) = 1;
  *(volatile uint8_t *)(a1 + 3) = 0;
  v4[70] = v5;
  *(volatile uint16_t *)(a1 + 22) = 16 * v5;
  return 24;
}



// build_hci_event @ 0x123ab4
int build_hci_event(int a1) {
  uint64_t v2; // r0
  volatile uint16_t *v3; // r2
  int16_t v4; // r3
  int16_t v5; // r1
  int v6; // r0
  int16_t v7; // r7
  struct __attribute__((packed)) { int v9; // [sp+0h] [bp-24h] BYREF
  int16_t v10; // [sp+4h] [bp-20h]
  char _pad2[2]; int v11; // [sp+8h] [bp-1Ch] BYREF
  int16_t v12; // [sp+Ch] [bp-18h]
  char _pad4[2]; int v13; // [sp+10h] [bp-14h] BYREF
  int16_t v14; // [sp+14h] [bp-10h]
  char _pad6[2]; int v15; // [sp+18h] [bp-Ch] BYREF
  int16_t v16; // [sp+1Ch] [bp-8h]
  } _frame;
  v2 = *((volatile uint64_t *)off_123B28 + 1);
  _frame.v10 = *((volatile uint32_t *)off_123B28 + 3);
  _frame.v9 = v2;
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_123B28 + 1)) << 32);
  _frame.v11 = *(volatile uint32_t *)off_123B28;
  _frame.v12 = WORD2(v2);
  memcpy((void *)(&_frame.v13), (void *)(&_frame.v9), 6);
  memcpy((void *)(&_frame.v15), (void *)(&_frame.v11), 6);
  v3 = (void *)(uintptr_t)(off_123B2C);
  v4 = *((volatile uint16_t *)off_123B2C + 70);
  *(volatile uint32_t *)(a1 + 4) = _frame.v15;
  v5 = _frame.v16;
  *(volatile uint32_t *)(a1 + 10) = _frame.v13;
  ++v4;
  v6 = _frame.v15;
  v7 = _frame.v14;
  *(volatile uint16_t *)(a1 + 8) = v5;
  *(volatile uint16_t *)(a1 + 20) = v5;
  *(volatile uint8_t *)a1 = 8;
  *(volatile uint32_t *)(a1 + 16) = v6;
  *(volatile uint16_t *)(a1 + 14) = v7;
  *(volatile uint8_t *)(a1 + 3) = 0;
  *(volatile uint8_t *)(a1 + 1) = 1;
  *(volatile uint8_t *)(a1 + 2) = 1;
  v3[70] = v4;
  *(volatile uint16_t *)(a1 + 22) = 16 * v4;
  return 24;
}



// init_timer_slot @ 0x123b30
int init_timer_slot(volatile uint32_t *a1, int a2, int a3) {
  int v3; // r2
  int v4; // r4
  int v5; // r7
  int v6; // r5
  volatile int *v7; // r8
  int v8; // r2
  int v10; // r0
  volatile int *v11; // r3
  int v12; // r12
  volatile int *v13; // r4

  v3 = 300 * a3;
  v4 = dword_123BB4;
  v5 = dword_123BB8;
  v6 = a1[4];
  *(volatile uint32_t *)(dword_123BB4 + v3) = dword_123BB8;
  if ( a2 >= 0x10000 )
    a2 = 0x10000;
  v7 = (volatile int *)(v4 + v3);
  v8 = a2 - 4096;
  v7[2] = v6;
  v7[4] = 0;
  if ( a2 - 4096 <= 4096 )
  {
    v12 = a2 - 4096;
    v13 = v7;
  }
  else
  {
    v10 = a1[5];
    v11 = v7 + 5;
    v12 = a2 - 61440;
    while ( 1 )
    {
      v8 -= 4096;
      v13 = v11;
      *(v11 - 2) = v10;
      *v11 = v5;
      v11[2] = v6;
      v11[4] = 0;
      *(v11 - 4) = (int)v11;
      v11 += 5;
      if ( v8 <= 4096 )
        break;
      if ( v8 == v12 )
        goto LABEL_7;
    }
    v12 = v8;
  }
LABEL_7:
  v13[3] = v6 - 1 + v12;
  v13[1] = 0;
  a1[3] = (int)(uintptr_t)(v7);
  return a2;
}



// wait_for_state @ 0x123bbc
int wait_for_state() {
  volatile int *v0; // r4
  int v1; // r11
  int v2; // r0
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r5
  volatile uint32_t *v5; // r6
  unsigned int v6; // r3
  int v7; // r4
  unsigned int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  volatile uint32_t *v11; // r0
  int v12; // r2
  volatile char *v13; // r3
  unsigned int v15; // r3
  unsigned int v16; // r8
  unsigned int v17; // r10
  int v18; // r1
  unsigned int v19; // r12
  unsigned int v20; // lr
  int v21; // r7
  int v22; // r2
  int v23; // r8
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r2
  char v27; // r9
  signed int v28; // r4
  int v29; // r9
  int v30; // r2
  volatile int *v31; // r8
  int v32; // r1
  int v33; // r2
  int v34; // r4
  signed int v35; // r3
  volatile char *v36; // r0
  struct __attribute__((packed)) { int a3; // [sp+Ch] [bp-10h]
  uint64_t result; // [sp+10h] [bp-Ch] BYREF
  } _frame;
  v0 = (volatile int *)off_123EAC;
  if ( *(volatile uint32_t *)off_123EAC <= 0x17u )
    *(volatile uint32_t *)off_123EAC = 1000;
  mac_time_get(&_frame.result, 0);
  v1 = (uint8_t)_frame.result;
  v2 = (uint8_t)_frame.result;
  if ( (uint8_t)_frame.result )
    v2 = 1;
  v3 = call_global_185c7c(v2, *v0);
  v4 = v3;
  if ( v3 )
  {
    v5 = (volatile uint32_t *)v3[7];
    v6 = v5[20];
    v7 = *(volatile uint32_t *)off_123EB4;
    v8 = *(volatile uint32_t *)off_123EB0;
    v5[16] = *(volatile uint32_t *)off_123EB0;
    v9 = v6 >> 19 << 19;
    v5[20] = v9;
    if ( v7 )
    {
      v10 = *(volatile uint32_t *)(uintptr_t)(off_123EB8);
      v11 = v5;
LABEL_8:
      v12 = *(volatile uint32_t *)(uintptr_t)(off_123EC0);
      v5[12] = *(volatile uint32_t *)off_123EBC;
      v5[20] = v10 | v9;
      v5[13] = v12;
      build_hci_command((int)(v11 + 26));
      v13 = (void *)(uintptr_t)(off_123EC4);
      v4[11] = 0;
      v4[12] = 0;
      wlan_tx_submit((int)v4, (uint8_t)*v13);
      return 0;
    }
    v15 = v8 & 0x7F;
    v16 = *((volatile uint16_t *)off_123EC8 + 20);
    v17 = (v8 >> 11) & 7;
    if ( v1 )
    {
      v18 = (v8 >> 11) & 6;
      if ( v18 )
      {
        if ( v17 >= 5 )
          v18 = 2;
        else
          v18 = 1;
        v19 = 4;
        v20 = 7;
      }
      else
      {
        v19 = 7;
        v20 = 11;
      }
      v21 = *((volatile char *)off_123ECC + 12 * v18 + v15);
      if ( v15 <= v19 )
      {
        _frame.a3 = 0;
      }
      else
      {
        if ( v20 < v15 )
          v22 = 1;
        else
          v22 = 2;
        if ( v20 < v15 )
          v7 = 6;
        else
          v7 = 12;
        _frame.a3 = v22;
      }
      if ( v16 > 0x1666 )
      {
        v23 = 5;
      }
      else if ( v16 > 0x1616 )
      {
        v23 = 4;
      }
      else if ( v16 > 0x15C6 )
      {
        v23 = 3;
      }
      else if ( v16 > 0x1571 )
      {
        v23 = 2;
      }
      else
      {
        v23 = v16 > 0x1486;
      }
      v27 = *(volatile uint8_t *)(v7 + *(volatile uint32_t *)off_123EF8 + v23)
          + *(volatile uint8_t *)(off_123F00 + 1)
          + *(volatile uint8_t *)(dword_123ED8 + _frame.a3 + 11);
      v28 = v27;
      if ( *((volatile uint8_t *)off_123EDC + 396) )
        v21 = (char)(v21 + *(volatile uint8_t *)(*(volatile uint32_t *)off_123EFC + v23));
LABEL_45:
      if ( *(volatile char *)off_123EE4 > 0 )
      {
        dispatch_event_handler_1("band=%d, formatModTx=%d, mcsIndexTx=%d\n", v1, v17, v15);
        v29 = v27 & 1;
        if ( v29 )
          v35 = v28 - 1 + ((unsigned int)(v28 - 1) >> 31);
        else
          v35 = v28 + ((unsigned int)v28 >> 31);
        dispatch_event_handler_1("DEBUG: pwrlvl=%d, ofst[%x][%x]=%d, res=%d\n", v21, _frame.a3, v23, v28, (v35 >> 1) + v21);
        --*(volatile uint8_t *)off_123EE4;
        v30 = 1;
      }
      else
      {
        v29 = v27 & 1;
        v30 = 0;
      }
      if ( v17 > 4 )
      {
        v31 = (void *)(uintptr_t)(off_123EB8);
        if ( (v5[16] & 0x600) == 0x400 )
          *(volatile uint32_t *)(uintptr_t)(off_123EB8) = *(volatile uint32_t *)(uintptr_t)(off_123EB8) & 0xFFFCFFFF | 0x20000;
      }
      else
      {
        v31 = (void *)(uintptr_t)(off_123EB8);
      }
      v32 = *(volatile char *)off_123EE8;
      if ( v32 < v21 )
      {
        v21 = *(volatile char *)off_123EE8;
        if ( v30 )
        {
          if ( v29 )
            v33 = (v28 - 1) / 2;
          else
            v33 = v28 / 2;
          dispatch_event_handler_1("max=%d, res=%d\n", v32, v33 + v32);
        }
      }
      if ( v29 )
        v34 = (v28 - 1) / 2;
      else
        v34 = v28 / 2;
      v9 = v5[20];
      v11 = (volatile uint32_t *)v4[7];
      v10 = *v31 & 0x70000 | (v21 + v34) | ((v21 + v34) << 8);
      goto LABEL_8;
    }
    if ( ((v8 >> 11) & 6) != 0 )
    {
      v36 = (volatile char *)off_123ED0 + v15;
      if ( v17 <= 4 )
        v21 = v36[12];
      else
        v21 = v36[24];
      v25 = 2;
    }
    else
    {
      v24 = v8 & 0x7C | v17;
      if ( !v24 )
      {
        _frame.a3 = 0;
        v21 = *((volatile char *)off_123ED0 + v15);
        goto LABEL_39;
      }
      v21 = *((volatile char *)off_123ED0 + v15);
      v25 = 9;
    }
    if ( v15 > v25 )
      v26 = 1;
    else
      v26 = 2;
    if ( v15 > v25 )
      v24 = 3;
    else
      v24 = 6;
    _frame.a3 = v26;
LABEL_39:
    if ( v16 <= 0x97B )
    {
      v23 = 0;
    }
    else if ( v16 > 0x994 )
    {
      v23 = 2;
    }
    else
    {
      v23 = 1;
    }
    v27 = *(volatile uint8_t *)(*(volatile uint32_t *)off_123ED4 + v23 + v24) + *(volatile uint8_t *)off_123F00 + *(volatile uint8_t *)(dword_123ED8 + _frame.a3 + 8);
    v28 = v27;
    if ( *((volatile uint8_t *)off_123EDC + 396) )
      v21 = (char)(v21 + *(volatile uint8_t *)(*(volatile uint32_t *)off_123EE0 + v23));
    goto LABEL_45;
  }
  return 1;
}


// format_message @ 0x123f04
int format_message(int a1, int a2, int16_t a3, int16_t a4) {
  int v5; // r0
  int v6; // r4
  struct __attribute__((packed)) { int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  chip_id_get((void *)(&_frame.v9), (void *)(&_frame.v10));
  v5 = ke_msg_send_1(2, a4, a3, 0x48u);
  v6 = v5;
  if ( (BYTE2(_frame.v9) & 3) == 2 )
    memcpy((void *)(uintptr_t)(v5), (void *)(uintptr_t)(dword_123F48), 33);
  *(volatile uint32_t *)(v6 + 64) = 255;
  rx_irq_handler_1(v6);
  return 0;
}



// set_state_checked @ 0x123f4c
int set_state_checked(unsigned int a1) {
  if ( a1 <= 0x17 )
    return 1;
  *(volatile uint32_t *)dword_123F60 = a1;
  return 0;
}



// set_reg_1807fc_bit6 @ 0x123f64
int set_reg_1807fc_bit6(int result) {
  *(volatile uint32_t *)off_123F74 = *(volatile uint32_t *)off_123F74 & 0xFFFFFFBF | (result << 6);
  return result;
}



// set_reg_1807fc_bit20 @ 0x123f78
/* luna: Set bit 20 of the target register from the low bit of value, clearing it first, and return the original value. */
int set_reg_1807fc_bit20(int result) {
  *(volatile uint32_t *)off_123F88 = *(volatile uint32_t *)off_123F88 & 0xFFEFFFFF | (result << 20);
  return result;
}



// set_reg_1807fc_bit21 @ 0x123f8c
int set_reg_1807fc_bit21(int result) {
  *(volatile uint32_t *)off_123F9C = *(volatile uint32_t *)off_123F9C & 0xFFDFFFFF | (result << 21);
  return result;
}



// set_reg_1807fc_bit0 @ 0x123fa0
int set_reg_1807fc_bit0(int result) {
  *(volatile uint32_t *)off_123FB0 = *(volatile uint32_t *)off_123FB0 & 0xFFFFFFFE | result;
  return result;
}



// set_reg_1807fc_bits24_27 @ 0x123fb4
int set_reg_1807fc_bits24_27(int result) {
  *(volatile uint32_t *)off_123FC4 = *(volatile uint32_t *)off_123FC4 & 0xF0FFFFFF | (result << 24);
  return result;
}



// set_reg_158a08_bit16 @ 0x123fc8
/* luna: Shifts the input value into bit 16 of the hardware register referenced by off_123FD8, preserving the other bits below 16, and returns the input value. */
int set_reg_158a08_bit16(int result) {
  *(volatile uint32_t *)off_123FD8 = *(volatile uint32_t *)off_123FD8 & 0xFFFEFFFF | (result << 16);
  return result;
}



// set_reg_158a08_bits20_25 @ 0x123fdc
/* luna: Writes a six-bit field into bits 20 through 25 of the RF/control register referenced by off_123FEC while preserving the other register bits. */
int set_reg_158a08_bits20_25(int result) {
  *(volatile uint32_t *)off_123FEC = *(volatile uint32_t *)off_123FEC & 0xFC0FFFFF | (result << 20);
  return result;
}



// configure_hw_regs @ 0x123ff0
int configure_hw_regs(unsigned int a1, int a2, int a3) {
  int v3; // r4
  volatile int *v4; // r5
  unsigned int v5; // r2
  volatile int *v6; // r5
  int v7; // r3

  if ( !a1 )
  {
    if ( !a2 )
    {
      v3 = 1024;
      goto LABEL_4;
    }
LABEL_3:
    v3 = a3 << 9;
LABEL_4:
    v4 = (void *)(uintptr_t)(off_12406C);
    v5 = *(volatile uint32_t *)(uintptr_t)(off_12406C) & 0xE3FFFFFF;
    *(volatile uint32_t *)off_124068 = *(volatile uint32_t *)off_124068 & 0xFFFFC180 | a2 & 0xFFFFF9FF | (a1 << 11) | v3;
    *v4 = v5;
LABEL_8:
    ++*(volatile uint8_t *)off_124074;
    return 0;
  }
  if ( a1 <= 4 )
    goto LABEL_3;
  if ( (*(volatile uint32_t *)off_124070 & 1) == 0 )
  {
    v6 = (void *)(uintptr_t)(off_12406C);
    v7 = *(volatile uint32_t *)(uintptr_t)(off_12406C) | 0x10000000;
    *(volatile uint32_t *)off_124068 = *(volatile uint32_t *)off_124068 & 0xFFFFC780 | a2 | (a1 << 11);
    *v6 = v7;
    goto LABEL_8;
  }
  dispatch_event_handler_1("un-support fmt=%d\n", a1);
  return 1;
}


// set_reg_180800_bits7_8 @ 0x12407c
int set_reg_180800_bits7_8(int a1) {
  *(volatile uint32_t *)off_124090 = *(volatile uint32_t *)off_124090 & 0xFFFFFE7F | (a1 << 7);
  return 0;
}



// set_reg_180800_bit9 @ 0x124094
int set_reg_180800_bit9(int a1) {
  *(volatile uint32_t *)off_1240A8 = *(volatile uint32_t *)off_1240A8 & 0xFFFFFDFF | (a1 << 9);
  return 0;
}



// rf_disable_1 @ 0x1240ac
int rf_disable_1(int a1) {
  volatile unsigned int *v1; // r1
  volatile unsigned int *v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v1 = (volatile unsigned int *)off_124130;
  v2 = (volatile unsigned int *)off_124134;
  v3 = *(volatile uint32_t *)off_124130 & 0xFFFCFFFF;
  v4 = *(volatile uint32_t *)off_124134 & 0xFFFFF9FF;
  *(volatile uint32_t *)off_124134 = v4;
  *v1 = v3;
  switch ( a1 )
  {
    case 0:
      dispatch_event_handler_1(aGi08us1xHeLtf3);
      result = 0;
      break;
    case 1:
      *v1 = v3 | 0x10000;
      dispatch_event_handler_1(aGi08us2xHeLtf6);
      result = 0;
      break;
    case 2:
      *v1 = v3 | 0x10000;
      *v2 = v4 | 0x200;
      dispatch_event_handler_1(aGi16us2xHeLtf6);
      result = 0;
      break;
    case 3:
      *v1 = v3 | 0x20000;
      dispatch_event_handler_1(aGi08us4xHeLtf1);
      result = 0;
      break;
    case 4:
      *v1 = v3 | 0x20000;
      *v2 = v4 | 0x400;
      dispatch_event_handler_1(aGi32us4xHeLtf1);
      goto LABEL_3;
    default:
      dispatch_event_handler_1(aUnsupportValue);
LABEL_3:
      result = 0;
      break;
  }
  return result;
}


// rf_write_synth @ 0x124150
int rf_write_synth(int a1) {
  int v1; // r1

  v1 = (HIWORD(*(volatile uint32_t *)off_124170) << 16) | (a1 << 8) | a1;
  *(volatile uint32_t *)off_124170 = v1;
  dispatch_event_handler_1(" %x\r\n", v1);
  return 0;
}


// rf_set_bit18 @ 0x124178
int rf_set_bit18(int a1) {
  unsigned int v1; // r1

  v1 = *(volatile uint32_t *)off_124194 & 0xFFFBFFFF | (a1 << 18);
  *(volatile uint32_t *)off_124194 = v1;
  dispatch_event_handler_1(" %x\r\n", v1);
  return 0;
}


// mac_tx_frame @ 0x12419c
int mac_tx_frame(int a1, int a2, int a3, int a4, int a5) {
  volatile uint8_t *v5; // r9
  char v8; // r8
  int v10; // r3
  volatile int *v11; // r3
  int v12; // r5
  int v13; // r6
  int v14; // r4
  int v15; // r5

  v5 = (void *)(uintptr_t)(off_124240);
  v8 = a3;
  dispatch_event_handler_1("set apc : %d %d %d %x %x, band %d\n", a1, a2, a3, a4, a5, *((volatile uint8_t *)off_124240 + 36));
  if ( v5[36] )
  {
    if ( a1 == 2 )
    {
      v10 = *(volatile uint32_t *)(uintptr_t)(off_12423C);
    }
    else
    {
      if ( a1 == 1 )
        v11 = (volatile int *)off_124230;
      else
        v11 = (void *)(uintptr_t)(off_124234);
      v10 = *v11;
    }
  }
  else if ( a1 )
  {
    v10 = *(volatile uint32_t *)off_12422C;
  }
  else
  {
    v10 = *(volatile uint32_t *)off_124238;
  }
  v12 = v10 + 4 * a2;
  v13 = ~(a4 << v8);
  v14 = v12 + 12;
  v15 = v12 + 204;
  do
  {
    *(volatile uint32_t *)(v14 - 12) = *(volatile uint32_t *)(v14 - 12) & v13 | (a5 << v8);
    v14 += 12;
  }
  while ( v15 != v14 );
  return memcpy_advance(1, (16 * a1) & 0xF0, 0x10u, v10);
}


// mac_validate_rate @ 0x124244
unsigned int mac_validate_rate(unsigned int result, unsigned int a2, int a3) {
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r5
  int v7; // r4
  int v8; // r3
  volatile unsigned int *v9; // r1
  unsigned int v10; // t1

  if ( result <= 1 )
  {
    if ( !result && a2 <= 3 )
    {
      *(volatile uint32_t *)off_1242D4 = 0;
      return result;
    }
    v4 = dword_1242E0;
    v3 = 512;
    *(volatile uint32_t *)off_1242D4 = 512;
  }
  else if ( result > 4 )
  {
    if ( a3 )
    {
      v3 = 2048;
      v4 = dword_1242EC;
    }
    else
    {
      v3 = 2048;
      v4 = dword_1242DC;
    }
    *(volatile uint32_t *)off_1242D4 = 2048;
  }
  else
  {
    if ( a3 )
    {
      v3 = 512;
      v4 = dword_1242E8;
    }
    else
    {
      v3 = 512;
      v4 = dword_1242D8;
    }
    *(volatile uint32_t *)off_1242D4 = 512;
  }
  v5 = v4 + 4 * v3 - 4;
  v6 = (*(volatile uint32_t *)off_1242E4 >> 5) & 3;
  *(volatile uint32_t *)off_1242E4 &= 0xFFFFFF9F;
  v7 = 1048580 - v4;
  v8 = v4 - 4;
  do
  {
    v9 = (volatile unsigned int *)(v7 + v8);
    v10 = *(volatile uint32_t *)(v8 + 4);
    v8 += 4;
    result = v10;
    *v9 = v10;
  }
  while ( v8 != v5 );
  if ( v6 )
    *(volatile uint32_t *)off_1242E4 = *(volatile uint32_t *)off_1242E4 & 0xFFFFFF9F | (32 * v6);
  return result;
}



// ke_handle_message @ 0x1242f0
int ke_handle_message(unsigned int a1) {
  int v2; // r7
  int v3; // r5
  int v4; // r0
  int result; // r0
  int v6; // r6
  int v7; // r5
  int v8; // r3
  int v9; // r2
  volatile uint8_t *v10; // r3
  char v11; // r0
  char v12; // r1
  volatile uint8_t *v13; // r1
  int16_t v14; // r3
  int16_t v15; // r2
  volatile char *v16; // r7
  char v17; // r0
  volatile unsigned int v18; // r1
  volatile int16_t *v19; // r8
  unsigned int v20; // r4
  uint16_t v21; // r3
  volatile char *v22; // r2
  char v23; // r1
  unsigned int v24; // r3
  volatile char *v25; // r0
  uint16_t v26; // r2
  int v27; // cc
  char v28; // r3
  volatile unsigned int v29; // r3
  uint64_t v30; // [sp+0h] [bp-8h] BYREF

  if ( a1 == 128 )
  {
    v3 = 100;
    v2 = 10240;
  }
  else if ( a1 == 129 )
  {
    v3 = 500;
    v2 = 10244;
  }
  else
  {
    v2 = 10249;
    if ( a1 == 1 )
    {
      v3 = 2000;
    }
    else
    {
      v3 = 200;
      v2 = 10240;
    }
  }
  mac_time_get(&v30, 0);
  v4 = (uint8_t)v30;
  if ( (uint8_t)v30 )
    v4 = 1;
  result = (int)call_global_185c7c(v4, v3);
  v6 = result;
  if ( result )
  {
    v7 = *(volatile uint32_t *)(result + 28);
    v8 = *(volatile uint32_t *)(uintptr_t)(off_1244D0);
    *(volatile uint32_t *)(v7 + 48) = *(volatile uint32_t *)off_1244CC;
    v9 = dword_1244D4;
    *(volatile uint32_t *)(v7 + 64) = v2;
    *(volatile uint32_t *)(v7 + 80) = v9;
    *(volatile uint32_t *)(v7 + 52) = v8;
    if ( a1 == 128 )
    {
      build_hci_event(v7 + 104);
      v24 = *(volatile uint8_t *)off_1244EC;
      v25 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1244E0)[0]);
      v26 = *(volatile int16_t *)off_1244DC;
      *(volatile uint8_t *)(v7 + 128) = 0x80;
      v24 -= 2;
      v27 = v24 > 1;
      if ( v24 <= 1 )
        v23 = -106;
      v28 = *v25;
      *(volatile uint8_t *)(v7 + 134) = v26;
      if ( v27 )
        v23 = -105;
      *(volatile uint8_t *)(v7 + 132) = v23;
      *(volatile uint8_t *)(v7 + 133) = v28;
      *(volatile uint8_t *)(v7 + 135) = HIBYTE(v26);
      *(volatile uint8_t *)(v7 + 129) = -64;
      *(volatile uint8_t *)(v7 + 130) = -75;
      *(volatile uint8_t *)(v7 + 131) = 122;
      *(volatile uint8_t *)(v7 + 136) = -1;
      goto LABEL_14;
    }
    if ( a1 > 0x80 )
    {
      if ( a1 == 129 )
      {
        build_hci_event(v7 + 104);
        v13 = (void *)(uintptr_t)(off_1244D8);
        v14 = *(volatile int16_t *)off_1244DC;
        v15 = *(volatile uint16_t *)off_1244D8;
        v16 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1244E0)[0]);
        *(volatile uint8_t *)(v7 + 130) = *(volatile int16_t *)off_1244DC;
        v17 = v13[5];
        *(volatile uint8_t *)(v7 + 128) = -127;
        v13 = (void *)(uintptr_t)(((uintptr_t)(v13) & ~0xFFu) | ((uint8_t)(*v16) & 0xFFu));
        *(volatile uint8_t *)(v7 + 131) = HIBYTE(v14);
        *(volatile uint16_t *)(v7 + 132) = v15;
        *(volatile uint8_t *)(v7 + 134) = v17;
        *(volatile uint8_t *)(v7 + 129) = (uint8_t)v13;
        *(volatile uint8_t *)(v7 + 135) = -1;
        goto LABEL_14;
      }
    }
    else
    {
      if ( a1 == 1 )
      {
        v18 = REG_4032_0120;
        v19 = (volatile int16_t *)off_1244DC;
        v20 = *(volatile uint32_t *)off_1244E8 - v18;
        if ( v20 <= 0x4E1F )
        {
          v29 = REG_4032_0120;
          v20 = (1000 - *(volatile int16_t *)off_1244DC)
              * ((v29 - *(volatile uint32_t *)off_1244F0)
               / *(volatile int16_t *)off_1244DC)
              + 20000;
          *(volatile uint32_t *)off_1244E8 = v29 + v20;
          dispatch_event_handler_1("txpwr_measure_time move %d\n", v20);
        }
        build_hci_command(v7 + 104);
        v21 = *v19;
        v22 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1244E0)[0]);
        *(volatile uint8_t *)(v7 + 130) = *v19;
        v22 = (void *)(uintptr_t)(((uintptr_t)(v22) & ~0xFFu) | ((uint8_t)(*v22) & 0xFFu));
        *(volatile uint8_t *)(v7 + 131) = HIBYTE(v21);
        *(volatile uint8_t *)(v7 + 132) = v20;
        *(volatile uint8_t *)(v7 + 129) = (uint8_t)v22;
        *(volatile uint8_t *)(v7 + 128) = 1;
        *(volatile uint8_t *)(v7 + 133) = BYTE1(v20);
        *(volatile uint8_t *)(v7 + 134) = BYTE2(v20);
        *(volatile uint8_t *)(v7 + 135) = HIBYTE(v20);
        *(volatile uint8_t *)(v7 + 136) = -1;
        goto LABEL_14;
      }
      if ( a1 == 2 )
      {
        build_hci_command(v7 + 104);
        v10 = (void *)(uintptr_t)(off_1244D8);
        *(volatile uint8_t *)(v7 + 128) = 2;
        v11 = v10[3];
        v12 = v10[4];
        *(volatile uint8_t *)(v7 + 130) = v10[2];
        *(volatile uint8_t *)(v7 + 131) = v11;
        *(volatile uint8_t *)(v7 + 132) = v12;
        *(volatile uint8_t *)(v7 + 129) = 1;
        *(volatile uint8_t *)(v7 + 133) = -1;
LABEL_14:
        *(volatile uint32_t *)(v6 + 44) = 0;
        *(volatile uint32_t *)(v6 + 48) = 0;
        return wlan_tx_submit(v6, 0);
      }
    }
    build_hci_command(v7 + 104);
    *(volatile uint8_t *)(v7 + 128) = 0;
    *(volatile uint8_t *)(v7 + 129) = -1;
    goto LABEL_14;
  }
  return result;
}


// ke_timer_tick @ 0x1244f8
int ke_timer_tick() {
  int result; // r0
  int v1; // r3

  result = ke_handle_message(2u);
  v1 = (uint16_t)(*(volatile uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(volatile uint16_t *)off_12451C = 0;
    return ll_state_reset(result);
  }
  else
  {
    *(volatile uint16_t *)off_12451C = v1;
  }
  return result;
}



// ke_state_event_0 @ 0x124520
void ke_state_event_0() {
  volatile uint16_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v3; // r3

  if ( *(volatile uint8_t *)off_12457C != 1 )
  {
    v0 = (void *)(uintptr_t)(off_124580);
    v1 = ke_handle_message(0);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 1000 )
    {
      if ( (unsigned int)*(volatile uint8_t *)off_124584 - 2 <= 1 )
      {
        *v0 = 0;
        ll_state_reset(v1);
      }
      else
      {
        rf_set_flag(2);
        v3 = *(volatile uint32_t *)off_124588;
        *(volatile uint32_t *)off_12458C = *(volatile uint32_t *)off_124588;
        *v0 = 0;
        *(volatile uint32_t *)off_124590 = v3 + 1000000;
      }
    }
  }
}



// ke_state_event_1 @ 0x124594
/* luna: Handles kernel state event 1 by dispatching message queue 1 and incrementing a 16-bit periodic call counter, triggering RF flag 3, zeroing related tim */
int ke_state_event_1() {
  volatile uint16_t *msg_counter_ptr; // r4
  int result; // r0
  int msg_counter; // r3
  volatile uint32_t *v3; // r2
  int mmio_write_base; // r0

  if ( *(volatile uint8_t *)off_1245DC != 1 )
  {
    msg_counter_ptr = (void *)(uintptr_t)(off_1245E0);
    result = ke_handle_message(1u);
    msg_counter = (uint16_t)(*msg_counter_ptr + 1);
    *msg_counter_ptr = msg_counter;
    if ( msg_counter == 1000 )
    {
      rf_set_flag(3);
      v3 = (void *)(uintptr_t)(off_1245EC);
      mmio_write_base = *(volatile uint32_t *)off_1245E4 + 19968;
      *(volatile uint32_t *)off_1245E8 = 0;
      *msg_counter_ptr = 0;
      *v3 = 0;
      return mmio_write_register(mmio_write_base + 32);
    }
  }
  return result;
}



// ke_start_event_80 @ 0x1245f0
int ke_start_event_80() {
  volatile uint16_t *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r0

  if ( *(volatile uint8_t *)off_12462C )
  {
    v0 = (void *)(uintptr_t)(off_124630);
    result = ke_handle_message(0x80u);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 10 )
    {
      rf_set_flag(1);
      v3 = *(volatile uint32_t *)off_124634 + 39936;
      *v0 = 0;
      return mmio_write_register(v3 + 64);
    }
  }
  return result;
}



// ke_stop_event_81 @ 0x124638
int ke_stop_event_81() {
  volatile uint16_t *v0; // r4
  int result; // r0
  int v2; // r3

  if ( *(volatile uint8_t *)off_124664 )
  {
    v0 = (void *)(uintptr_t)(off_124668);
    result = ke_handle_message(0x81u);
    v2 = (uint16_t)(*v0 + 1);
    *v0 = v2;
    if ( v2 == 100 )
    {
      result = rf_set_flag(4);
      *v0 = 0;
    }
  }
  return result;
}



// util_alloc_buffer @ 0x12466c
void util_alloc_buffer() {
  int v0; // r0

  v0 = enter_critical_section_1(0x2000);
  if ( rf_flag_is_set(v0) )
  {
    switch ( *(volatile uint8_t *)off_1246DC )
    {
      case 1:
        ke_state_event_0();
        break;
      case 2:
        ke_state_event_1();
        break;
      case 3:
        ke_stop_event_81();
        break;
      case 4:
        if ( *(volatile uint8_t *)off_1246EC != 1 )
          ke_timer_tick();
        break;
      case 5:
        ke_start_event_80();
        break;
      default:
        return;
    }
  }
  else if ( *(volatile uint32_t *)off_1246E0 )
  {
    if ( !*(volatile uint8_t *)off_1246E8 )
      wait_for_state();
  }
  else
  {
    *(volatile uint32_t *)off_1246E4 = 0;
  }
}



// rx_process_pending @ 0x1246f0
int rx_process_pending(int a1, int a2) {
  int v3; // r1
  unsigned int v4; // r2
  volatile uint8_t *v5; // r6
  volatile int *v6; // r5
  int v7; // r3
  int v8; // r2
  volatile uint32_t *v9; // r5
  int v10; // r4

  if ( (*(volatile uint32_t *)off_124788 & 2) != 0
    && ((v3 = *(volatile uint8_t *)a2, v4 = *(volatile uint16_t *)(a2 + 4), v3 == 1) || v4 > 0x1387) )
  {
    dispatch_event_handler_1("un-support band=%d, freq=%d\n", v3, v4);
    return -1;
  }
  else
  {
    v5 = (volatile uint8_t *)off_12478C;
    if ( !*(volatile uint8_t *)off_12478C )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_124790 = 1;
      }
      v6 = (volatile int *)off_124794;
      ++*(volatile uint32_t *)off_124794;
      rf_cmd_wait();
      rf_acquire();
      if ( *v6 )
      {
        v7 = *v6 - 1;
        v8 = *(volatile uint32_t *)off_124790;
        *v6 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
    }
    v9 = (void *)(uintptr_t)(off_12479C);
    ++*(volatile uint8_t *)off_124798;
    *v9 |= 0x500000u;
    tx_set_power((volatile uint8_t *)a2, 0);
    *v9 &= 0xFF87FFFF;
    v10 = (uint8_t)*v5;
    if ( *v5 )
    {
      return 0;
    }
    else
    {
      write_bb_control();
      util_alloc_buffer();
      return v10;
    }
  }
}


// util_list_find @ 0x1247a4
int util_list_find(volatile uint8_t **a1, volatile uint8_t *a2) {
  volatile uint8_t *v2; // r3
  volatile uint8_t *v3; // t1

  v2 = *a1;
  if ( !*a1 )
    return 0;
  do
  {
    if ( *v2 == *a2 && v2[1] == a2[1] )
      return 1;
    v3 = a1[1];
    ++a1;
    v2 = v3;
  }
  while ( v3 );
  return 0;
}



// util_buf_clear @ 0x1247d8
int util_buf_clear(int a1, int a2) {
  volatile int *v2; // r5
  int v3; // r0
  volatile char *v4; // r3
  volatile int *v5; // r4
  int v6; // r3
  int v7; // r2
  int v9; // r0
  volatile uint8_t *v10; // r2

  if ( a1 > 1 )
  {
    v2 = (void *)(uintptr_t)(off_124880);
    v3 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    v4 = (void *)(uintptr_t)(off_124884);
    *v2 = v3;
    if ( *v4 == 1 )
    {
      v10 = (void *)(uintptr_t)(off_12489C);
      *v4 = 0;
      *v10 = 0;
      ke_int_lock((int)(uintptr_t)((volatile char *)0x90), 0);
      *(volatile uint32_t *)off_1248A0 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_124888 = 1;
    }
    v5 = (volatile int *)off_12488C;
    ++*(volatile uint32_t *)off_12488C;
    rf_cmd_wait();
    rf_acquire();
    write_bb_control();
    if ( *v5 )
    {
      v6 = *v5 - 1;
      v7 = *(volatile uint32_t *)off_124888;
      *v5 = v6;
      if ( !v6 )
      {
        if ( v7 )
          __enable_irq();
      }
    }
    if ( *v2 )
    {
      *(volatile uint32_t *)off_124894 = 2;
      util_alloc_buffer();
      util_alloc_buffer();
      v9 = *(volatile uint32_t *)off_124890;
      if ( !*(volatile uint32_t *)off_124890 )
        return 0;
      if ( *v2 )
      {
LABEL_15:
        init_with_stack(v9);
        return 0;
      }
    }
    else if ( !*(volatile uint32_t *)off_124890 )
    {
      return 0;
    }
    v9 = 0;
    goto LABEL_15;
  }
  dispatch_event_handler_1(asc_130050, a2);
  return 1;
}


// mmio_set_flag_1 @ 0x1248a4
int mmio_set_flag_1() {
  volatile uint8_t *v0; // r4
  volatile int *v1; // r3
  int v2; // r2

  if ( !*(volatile uint8_t *)off_1248D8 )
    *(volatile uint8_t *)off_1248D8 = 1;
  v0 = (void *)(uintptr_t)(off_1248DC);
  if ( *(volatile uint8_t *)off_1248DC )
  {
    dispatch_event_handler_1(asc_130078);
    return 0;
  }
  else
  {
    ke_event_loop(144, *(volatile uint8_t *)off_1248DC, dword_1248E0);
    v1 = (volatile int *)off_1248E4;
    v2 = dword_1248E8;
    *v0 = 1;
    *v1 = v2;
    return 0;
  }
}


// mmio_clear_flag @ 0x1248f0
int mmio_clear_flag() {
  *(volatile uint8_t *)off_12490C = 0;
  ke_int_lock((int)(uintptr_t)((volatile char *)0x90), 0);
  dispatch_event_handler_1(asc_130090);
  return 0;
}


// mmio_enable_clock @ 0x124914
int mmio_enable_clock() {
  volatile int *v0; // r1
  int v1; // r0

  v0 = (volatile int *)off_124938;
  v1 = dword_12493C;
  *(volatile uint32_t *)off_124934 |= 0x10u;
  *v0 = v1;
  write_bb_control();
  dispatch_event_handler_1(aRxStatStart);
  return 0;
}


// mmio_read_timer @ 0x124944
int mmio_read_timer() {
  dispatch_event_handler_1(
    "rx_stat get: fcsok=%d, total=%d\r\n",
    *(volatile uint32_t *)off_12495C,
    *(volatile uint32_t *)off_124960 + *(volatile uint32_t *)off_12495C);
  return 0;
}


// mmio_check_status @ 0x124968
int mmio_check_status() {
  volatile int *v0; // r6
  volatile uint32_t *v1; // r4
  volatile unsigned int v2; // r7
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r3
  int v6; // r2

  if ( *(volatile uint32_t *)off_1249E8 << 28 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_124A00 = 1;
    }
    v0 = (volatile int *)off_1249EC;
    v1 = (void *)(uintptr_t)(off_1249E8);
    ++*(volatile uint32_t *)off_1249EC;
    *v1 = 0;
    v2 = (*(volatile uint32_t *)0x40501010u);
    while ( *v1 << 28 )
    {
      v3 = (*(volatile uint32_t *)0x40501010u) - v2;
      if ( v3 > 0x7530 )
        dispatch_event_handler_1(aIdleErr, *v1 << 28, 30000);
    }
    v4 = off_1249F8;
    while ( (*(volatile uint32_t *)off_1249F8 & *(volatile uint32_t *)off_1249F4 & 4) == 0 )
      ;
    *(volatile uint32_t *)off_1249FC = 4;
    if ( *v0 )
    {
      v5 = *v0 - 1;
      v6 = *(volatile uint32_t *)off_124A00;
      *v0 = v5;
      if ( !v5 )
      {
        if ( v6 )
          __enable_irq();
      }
    }
    dispatch_event_handler_1(aForceIdled, v4);
  }
  dispatch_event_handler_1(aRxStatStop);
  return 0;
}


// set_channel @ 0x124a10
int set_channel(int a1, int a2) {
  int v2; // r3

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1300E4, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    if ( (unsigned int)(v2 - 1) <= 0x30 )
    {
      dispatch_event_handler_1(asc_1300FC);
      return 1;
    }
    else
    {
      *(volatile uint32_t *)off_124A44 = v2;
      return 0;
    }
  }
}


// set_tx_power @ 0x124a50
int set_tx_power(int a1, int a2) {
  int v2; // r4

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130118, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_state_checked((uint16_t)v2);
    dispatch_event_handler_1("\x9A\x88  TX Len  = %d\n", v2);
    return 0;
  }
}


// set_adv_interval @ 0x124a88
/* luna: Implements a BLE advertising-interval set command by parsing three decimal arguments and programming the corresponding hardware registers, with an err */
int set_adv_interval(int a1, volatile uint32_t *a2) {
  volatile int *v3; // r6
  unsigned int first_numeric_arg; // r5
  int v5; // r3
  volatile uint8_t *v6; // r0
  int second_numeric_arg; // r4
  int v8; // r0
  int third_numeric_arg; // r2
  int result; // r0
  int v11; // [sp+4h] [bp-4h]

  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_130144, a2);
    return -1;
  }
  else
  {
    v3 = (volatile int *)off_124AF8;
    first_numeric_arg = parse_number((volatile uint8_t *)a2[1], nullptr, 0xAu);
    v5 = parse_number((volatile uint8_t *)a2[2], nullptr, 0xAu);
    v6 = (volatile uint8_t *)a2[3];
    second_numeric_arg = v5;
    v8 = parse_number(v6, nullptr, 0xAu);
    third_numeric_arg = v8;
    if ( *v3 )
    {
      v11 = v8;
      init_with_stack(0);
      third_numeric_arg = v11;
    }
    configure_hw_regs(first_numeric_arg, second_numeric_arg, third_numeric_arg);
    dispatch_event_handler_1(asc_130170);
    result = *v3;
    if ( *v3 )
    {
      init_with_stack(result);
      return 0;
    }
  }
  return result;
}


