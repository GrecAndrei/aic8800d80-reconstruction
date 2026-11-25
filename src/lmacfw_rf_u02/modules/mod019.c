// ke_enter_critical @ 0x11ab18
int ke_enter_critical(volatile uint32_t *a1, int a2) {
  volatile int *v4; // r7
  volatile unsigned int *v5; // r2
  int v6; // r3
  volatile uint32_t *v7; // r6
  void *v8; // r2
  int result; // r0
  volatile uint32_t *v10; // r3
  int v11; // r3
  int v12; // r2
  void *v13; // r2
  volatile unsigned int *v14; // r2
  int v15; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11ABEC = 1;
  }
  v4 = (volatile int *)off_11ABF0;
  v5 = (void *)(uintptr_t)(off_11ABF4);
  ++*(volatile uint32_t *)off_11ABF0;
  v6 = *((volatile uint32_t *)v5 + 4);
  if ( a2 - v6 < 0 )
  {
    dispatch_event_handler_1("timer past: cb=%x, time=%x, curr=%x\r\n", a1[1], a2, v6);
    if ( **(volatile int16_t **)off_11AC04 < 0 )
      flash_ctrl_init(off_11AC0C, (int)aMmTimerSet, 131);
  }
  v7 = (volatile uint32_t *)off_11ABF8;
  if ( a1 == *(volatile uint32_t **)off_11ABF8 )
  {
    list_pop_front(off_11ABF8);
    v13 = (void *)(uintptr_t)(off_11ABFC);
    a1[3] = a2;
    result = list_foreach((int)v7, a1, (int ( *)(volatile uint32_t *, volatile uint32_t *))v13);
    v10 = (volatile uint32_t *)*v7;
    if ( !*v7 )
    {
      *((volatile uint32_t *)off_11ABF4 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  check_kernel_state_alt2(off_11ABF8, a1);
  v8 = (void *)(uintptr_t)(off_11ABFC);
  a1[3] = a2;
  result = list_foreach((int)v7, a1, (int ( *)(volatile uint32_t *, volatile uint32_t *))v8);
  v10 = (volatile uint32_t *)*v7;
  if ( a1 == (volatile uint32_t *)*v7 )
  {
LABEL_14:
    v14 = (void *)(uintptr_t)(off_11ABF4);
    v15 = v10[3];
    result = 0x40000;
    *((volatile uint32_t *)off_11ABF4 + 2) = 0x40000;
    *((volatile uint32_t *)v14 + 12) = v15;
    *((volatile uint32_t *)v14 + 2) = 4;
  }
LABEL_6:
  if ( *v4 && (v11 = *v4 - 1, v12 = *(volatile uint32_t *)off_11ABEC, (*v4 = v11) == 0) && v12 )
  {
    __enable_irq();
    if ( (int)(a2 - *((volatile uint32_t *)off_11ABF4 + 4)) < 0 )
      return set_busy_flag_alt(0x20000000);
  }
  else if ( (int)(a2 - *((volatile uint32_t *)off_11ABF4 + 4)) < 0 )
  {
    return set_busy_flag_alt(0x20000000);
  }
  return result;
}


// ke_exit_critical @ 0x11ac10
int ke_exit_critical(int a1) {
  volatile int *v1; // r4
  void *v2; // r5
  int v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  volatile uint32_t *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11AC70 = 1;
  }
  v1 = (volatile int *)off_11AC74;
  v2 = (void *)(uintptr_t)(off_11AC78);
  v3 = *(volatile uint32_t *)off_11AC78 == a1;
  ++*(volatile uint32_t *)off_11AC74;
  if ( v3 )
  {
    result = (int)(uintptr_t)(list_pop_front((int)(uintptr_t)(v2)));
    v7 = (void *)(uintptr_t)(off_11AC7C);
    if ( *(volatile uint32_t *)v2 )
    {
      v8 = *(volatile uint32_t *)(*(volatile uint32_t *)v2 + 12);
      result = 0x40000;
      *((volatile uint32_t *)off_11AC7C + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((volatile uint32_t *)off_11AC7C + 2) = 1024;
    }
  }
  else
  {
    result = check_kernel_state_alt2((int)(uintptr_t)(v2), (void *)(uintptr_t)(a1));
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(volatile uint32_t *)off_11AC70;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// ke_schedule @ 0x11ac80
int ke_schedule() {
  volatile uint32_t *v0; // r7
  volatile int *v1; // r6
  volatile int *v2; // r8
  volatile uint32_t *v3; // r5
  void *v4; // r9
  int result; // r0
  volatile uint32_t *v6; // r4
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r2
  void ( *v11)(uint32_t); // r3
  volatile int *v12; // r3
  int v13; // r3
  volatile int *v14; // r3

  v0 = (void *)(uintptr_t)(off_11AD3C);
  v1 = (volatile int *)off_11AD40;
  v2 = (volatile int *)off_11AD54;
  v3 = (void *)(uintptr_t)(off_11AD44);
  v4 = (void *)(uintptr_t)(off_11AD3C);
  while ( 1 )
  {
    enter_critical_section_1(0x20000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    result = *v1;
    v6 = (volatile uint32_t *)*v0;
    v7 = *v1 + 1;
    *v1 = v7;
    if ( !v6 )
      break;
    v8 = v6[3];
    if ( v8 - v3[4] - 50 >= 0 )
    {
      v3[2] = 0x40000;
      v3[12] = v8;
      v3[2] = 4;
      if ( v8 - v3[4] >= 0 )
      {
        if ( !v7 )
          return result;
        v14 = (volatile int *)off_11AD54;
        *v1 = result;
        v13 = *v14;
        if ( result )
          return result;
        goto LABEL_17;
      }
    }
    list_pop_front((int)(uintptr_t)(v4));
    if ( *v1 )
    {
      v9 = *v1 - 1;
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    v11 = (void ( *)(uint32_t))v6[1];
    if ( **(volatile int16_t **)off_11AD48 >= 0 || v11 )
    {
      v11(v6[2]);
    }
    else
    {
      flash_ctrl_init(dword_11AD50, dword_11AD4C, 246);
      ((void ( *)(uint32_t))v6[1])(v6[2]);
    }
  }
  *((volatile uint32_t *)off_11AD44 + 2) = 1024;
  if ( !v7 )
    return result;
  v12 = (volatile int *)off_11AD54;
  *v1 = result;
  v13 = *v12;
  if ( result )
    return result;
LABEL_17:
  if ( v13 )
    __enable_irq();
  return result;
}



// send_hci_event_1 @ 0x11ad58
int send_hci_event_1(int a1) {
  volatile uint8_t *v2; // r0
  volatile uint32_t *v3; // r2

  v2 = (volatile uint8_t *)ke_msg_send_1(72, *(volatile uint16_t *)(a1 + 14), 0, 2);
  v2[1] = *(volatile uint8_t *)(a1 + 24);
  v3 = (void *)(uintptr_t)(off_11AD84);
  *v2 = *(volatile uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return (int)(uintptr_t)(rx_irq_handler_1((int)(uintptr_t)(v2)));
}



// time_delta @ 0x11ad88
BOOL time_delta(int a1, int a2) {
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v6; // r6
  int v7; // r0

  v3 = *(volatile uint32_t *)(a1 + 4);
  v4 = os_get_tick_hz();
  v5 = *(volatile uint32_t *)(a2 + 4);
  v6 = v4;
  v7 = os_get_tick_hz();
  return v3 - v5 < 0 && v5 - 14000 - v3 - v6 < 0 || v5 - v3 < 0 && v3 - v5 - 14000 - v7 < 0 || v3 == v5;
}



// list_search @ 0x11add0
int list_search(int result) {
  volatile uint32_t *v1; // r6
  int v2; // r5
  int v3; // r4
  volatile uint8_t *v4; // r0
  volatile uint32_t *v5; // r0

  v1 = (void *)(uintptr_t)(off_11AE1C);
  v2 = *((volatile uint32_t *)off_11AE1C + 10);
  if ( v2 == result )
  {
    *(volatile uint8_t *)(v2 + 16) = 4;
  }
  else
  {
    v3 = result;
    if ( v2 )
    {
      if ( *(volatile uint8_t *)(v2 + 24) != 3 )
      {
        v4 = (volatile uint8_t *)ke_msg_send_1(69, 4, 0, 1);
        *v4 = *(volatile uint8_t *)(v2 + 24);
        rx_irq_handler_1((int)(uintptr_t)(v4));
      }
    }
    v1[11] = v3;
    *(volatile uint8_t *)(v3 + 16) = 2;
    v5 = (volatile uint32_t *)ke_msg_send_1(140, 0, 255, 4);
    *v5 = dword_11AE20;
    return (int)(uintptr_t)(rx_irq_handler_1((int)(uintptr_t)(v5)));
  }
  return result;
}



// rf_event_dispatch @ 0x11ae24
int rf_event_dispatch(int a1, int a2, int a3) {
  int v3; // r8
  volatile uint32_t *v4; // r9
  int v5; // r11
  int v8; // r10
  int v9; // r7
  int v10; // r3
  int v11; // r0
  int v12; // r4
  int v13; // r7
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r7
  volatile uint32_t *v20; // [sp+4h] [bp-8h]

  v3 = a3;
  v4 = (void *)(uintptr_t)(off_11AF70);
  v5 = dword_11AF74;
  v8 = a1 + 76;
  if ( !a3 )
    goto LABEL_21;
  while ( 1 )
  {
    v9 = *(volatile uint32_t *)(a1 + 72);
    if ( v4[8] )
      break;
    v10 = v4[20];
    if ( !v10 )
      goto LABEL_5;
    if ( v9 == v10 )
      goto LABEL_5;
    v19 = v4[21];
    if ( a2 - v19 - 4000 - os_get_tick_hz() >= 0 )
      goto LABEL_5;
LABEL_18:
    if ( *(volatile uint8_t *)(a1 + 94) )
      v18 = 102400;
    else
      v18 = *(volatile uint32_t *)(dword_11AF6C + 152 * *(volatile uint8_t *)(a1 + 102) + 8);
    ++v3;
    a2 += v18;
    if ( !v3 )
    {
LABEL_21:
      if ( (*(volatile uint8_t *)(a1 + 85) & 1) != 0 )
      {
        check_kernel_state_alt2(dword_11AF68, (void *)(uintptr_t)(v8));
        *(volatile uint8_t *)(a1 + 85) &= ~1u;
      }
    }
  }
  v20 = (volatile uint32_t *)v4[9];
  v16 = v20[1];
  v17 = v16 + 4000 + os_get_tick_hz();
  if ( v9 != v20[2] )
  {
    v17 += 4000 + os_get_tick_hz();
    if ( v20[3] )
      v17 += 10000;
  }
  if ( a2 - v17 < 0 )
    goto LABEL_18;
LABEL_5:
  *(volatile uint32_t *)(a1 + 80) = a2;
  v11 = os_get_tick_hz();
  v12 = v4[4];
  v13 = a2 + 13999 + v11;
  if ( v12 )
  {
    while ( 1 )
    {
      v14 = *(volatile uint32_t *)(v12 + 4);
      if ( v13 - v14 < 0 )
        break;
      if ( *(volatile uint32_t *)(v5 + 224 * *(volatile uint8_t *)(a1 + 84) + 72) != *(volatile uint32_t *)(v5
                                                                                   + 224 * *(volatile uint8_t *)(v12 + 8)
                                                                                   + 72) )
      {
        if ( time_delta(v8, v12) )
          goto LABEL_18;
        v14 = *(volatile uint32_t *)(v12 + 4);
      }
      if ( a2 - v14 < 0 )
        break;
      v12 = *(volatile uint32_t *)v12;
      if ( !v12 )
        goto LABEL_24;
    }
  }
  else
  {
LABEL_24:
    v12 = 0;
  }
  result = (int)(uintptr_t)(list_find((void *)(uintptr_t)(dword_11AF68), (void *)(uintptr_t)(v12), (void *)(uintptr_t)(v8)));
  *(volatile uint8_t *)(a1 + 85) |= 1u;
  return result;
}



// ke_task_handler_1 @ 0x11af78
int ke_task_handler_1(int a1, int a2, int a3) {
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r4
  int v8; // r5
  int v9; // r0
  int v10; // r6
  int result; // r0
  volatile int *v12; // r6
  int v13; // r1
  volatile unsigned int v14; // r3
  int v15; // r0
  int v16; // r2
  volatile int *v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r2

  v6 = list_pop_front(dword_11B020);
  v7 = v6;
  if ( **(volatile int16_t **)off_11B024 < 0 && !v6 )
    flash_ctrl_init((int)aChSwitchNull, (int)aChanSwitchAllo, 227);
  v8 = off_11B028;
  v9 = off_11B028 + 0x20;
  v10 = *(volatile uint32_t *)(off_11B028 + 0x20);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = check_kernel_state(v9, v7);
  if ( !v10 )
  {
    *(volatile uint32_t *)(v8 + 0x48) = (int)(uintptr_t)(v7);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11B034 = 1;
    }
    v12 = (volatile int *)off_11B03C;
    v13 = v7[1];
    v14 = (*(volatile uint32_t *)0x40501010u);
    v15 = *(volatile uint32_t *)off_11B03C;
    v16 = *(volatile uint32_t *)off_11B03C + 1;
    *(volatile uint32_t *)off_11B03C = v16;
    if ( (int)(v13 - v14 - 64) >= 0 )
    {
      result = ke_enter_critical((volatile uint32_t *)dword_11B040, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(volatile uint32_t *)off_11B034;
        *v12 = v19;
        if ( !v19 )
        {
          if ( v20 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v16 )
      {
        v17 = (volatile int *)off_11B034;
        *v12 = v15;
        v18 = *v17;
        if ( !v15 )
        {
          if ( v18 )
            __enable_irq();
        }
      }
      return (*(int ( **)(volatile uint32_t *))(v8 + 0x44))(v7);
    }
  }
  return result;
}


// rx_buffer_alloc @ 0x11b044
volatile uint32_t *rx_buffer_alloc() {
  volatile uint32_t *result; // r0
  volatile int *v1; // r4
  volatile uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  result = list_pop_front(dword_11B07C);
  a2 = result;
  if ( result )
  {
    v1 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_11B080)[0]);
    ke_exit_critical((int)(uintptr_t)((volatile uint32_t *)dword_11B084));
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      check_kernel_state(v3, v2);
      result = list_pop_front(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}


// rf_calibrate_1 @ 0x11b088
int rf_calibrate_1(int a1, int a2, unsigned int a3) {
  int v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r7
  int v7; // r4
  int v10; // r4
  int v11; // r0
  int v12; // r4
  int v13; // r7
  int v14; // r7
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r3
  volatile char *v18; // r1
  int v19; // zf
  int v20; // r3
  volatile char *v21; // r3
  int result; // r0

  v3 = dword_11B1A0;
  v4 = *((volatile uint32_t *)off_11B198 + 4);
  v5 = *(volatile uint32_t *)(a1 + 72);
  v6 = *(volatile uint8_t *)(v4 + 8);
  v7 = *(volatile uint32_t *)(v4 + 4) - 4000;
  v10 = v7 - a2 - os_get_tick_hz();
  if ( *(volatile uint32_t *)(v3 + 224 * v6 + 72) == v5 )
  {
    result = os_get_tick_hz();
    v12 = v10 - 4000 - result;
    if ( v12 <= 4999 )
      return result;
    v13 = *(volatile uint32_t *)(v4 + 4);
    v14 = v13 - 4000 - os_get_tick_hz();
    v15 = (v12 + a3) >> 1;
    if ( a3 > v15 || (v16 = v15 + a2 - a3, a2 == v16) )
    {
      rx_buffer_alloc();
      v16 = a2;
    }
    v17 = *(volatile uint8_t *)(v5 + 24);
    v18 = (volatile char *)off_11B19C;
    if ( v17 == 2 )
    {
      if ( *((volatile uint8_t *)off_11B19C + 24) != 255 )
        goto LABEL_18;
      v20 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_11B19C + 28 * v17 + 52) != 255 )
      {
        v18 = (volatile char *)off_11B19C + 28 * v17 + 28;
LABEL_18:
        ke_task_handler_1(v16, (int)v18, 0);
        return ke_task_handler_1(v14, v5, v4);
      }
      v19 = v17 == 1;
      v20 = v17 + 2;
      if ( v19 )
        v20 = 0;
    }
    v21 = (volatile char *)off_11B19C + 28 * v20;
    if ( (uint8_t)v21[24] == 255 )
      v18 = 0;
    else
      v18 = v21;
    goto LABEL_18;
  }
  os_get_tick_hz();
  if ( a3 > (v10 + a3) >> 1 || (v11 = ((v10 + a3) >> 1) + a2 - a3, a2 == v11) )
  {
    rx_buffer_alloc();
    v11 = a2;
  }
  return ke_task_handler_1(v11, *(volatile uint32_t *)(v3 + 224 * v6 + 72), v4);
}



// rf_register_access @ 0x11b1a4
int rf_register_access(int result) {
  volatile uint8_t *v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r7
  char v5; // r3
  int v6; // r9
  int v7; // r7
  int v8; // r8
  int v9; // r6
  int v10; // r10
  int v11; // r0
  int v12; // r3

  v1 = (void *)(uintptr_t)(off_11B2AC);
  v2 = result;
  v3 = *((volatile uint32_t *)off_11B2A4 + 4) + *(volatile uint32_t *)(result + 20);
  if ( result != dword_11B2A8 || (*((volatile uint8_t *)off_11B2AC + 88) & 4) != 0 )
  {
    if ( *((volatile uint32_t *)off_11B2AC + 10) != result )
    {
      result = os_get_tick_hz();
      v3 += 4000 + result;
    }
    v4 = (uint8_t)v1[91];
    v5 = v1[88];
    *((volatile uint32_t *)v1 + 20) = v2;
    *((volatile uint32_t *)v1 + 21) = v3;
    if ( v4 )
    {
      v1[88] = v5 | 0x40;
    }
    else
    {
      v1[88] = v5 & 0xBF;
      rx_buffer_alloc();
      result = ke_task_handler_1(v3, 0, 0);
      v6 = *((volatile uint32_t *)v1 + 4);
      if ( v6 )
      {
        v7 = dword_11B2B4;
        v8 = dword_11B2C4;
        v9 = dword_11B2B0 - v3;
        do
        {
          v10 = *(volatile uint32_t *)(v6 + 4);
          result = v10 - os_get_tick_hz();
          if ( result + v9 >= 0 )
            break;
          v11 = v7 + 224 * *(volatile uint8_t *)(v6 + 8);
          v12 = 102400;
          if ( !*(volatile uint8_t *)(v11 + 94) )
            v12 = *(volatile uint32_t *)(v8 + 152 * *(volatile uint8_t *)(v11 + 102) + 8);
          result = rf_event_dispatch(v11, *(volatile uint32_t *)(v6 + 4) + v12, 0);
          v6 = *((volatile uint32_t *)v1 + 4);
        }
        while ( v6 );
      }
      if ( *((volatile uint32_t *)v1 + 11) )
      {
        if ( **(volatile int16_t **)off_11B2B8 < 0 && (v1[88] & 0xC) == 0 )
          return flash_ctrl_init(dword_11B2C0, dword_11B2BC, 1698);
      }
      else
      {
        return list_search(v2);
      }
    }
  }
  else
  {
    *((volatile uint8_t *)off_11B2AC + 88) &= ~0x40u;
  }
  return result;
}



// rf_status_check_1 @ 0x11b2c8
int rf_status_check_1() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11B350);
  v1 = *((volatile uint8_t *)off_11B350 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(volatile int16_t **)off_11B354 < 0 && (v1 & 4) != 0 )
    {
      flash_ctrl_init(dword_11B364, dword_11B360, 1720);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_register_access(dword_11B358);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(volatile int16_t **)off_11B354 < 0 && (v1 & 8) != 0 )
    {
      flash_ctrl_init(dword_11B368, dword_11B360, 1731);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_register_access(dword_11B35C);
  }
  return result;
}



// rf_flag_set @ 0x11b36c
int rf_flag_set() {
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11B39C);
  if ( (*((volatile uint8_t *)off_11B39C + 88) & 0x10) == 0 )
  {
    v1 = *((volatile uint8_t *)off_11B39C + 90);
    *((volatile uint8_t *)off_11B39C + 88) |= 0x10u;
    if ( v1 )
      return ke_enter_critical((void *)(uintptr_t)((int)v0 + 48), *((volatile uint32_t *)off_11B3A0 + 4) + 30000);
    else
      return rf_status_check_1();
  }
  return result;
}



