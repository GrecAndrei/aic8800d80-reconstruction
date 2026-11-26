// usb_wlan_rx_pkt_free_list_init @ 0x113814
volatile uint32_t *usb_wlan_rx_pkt_free_list_init() {
  void *v0; // r7
  volatile uint32_t *result; // r0
  volatile int *v2; // r9
  volatile uint16_t *v3; // r6
  int v4; // r8
  volatile uint16_t **v5; // r10
  int16_t v6; // r5
  unsigned int v7; // r1
  volatile uint32_t *v8; // r4

  v0 = (void *)(uintptr_t)(off_113890);
  result = zero_8_bytes((volatile uint32_t *)dword_113894);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (volatile int *)off_1138A4;
    v3 = (void *)(uintptr_t)(off_113898);
    v4 = dword_1138A8;
    v5 = (volatile uint16_t **)off_1138B0;
    v6 = 0;
    do
    {
      v8 = buffer_pool_alloc(v4, (uint16_t)(*((volatile uint16_t *)v2 + 153) - 4));
      if ( !v8 )
      {
        event_dispatch("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          mmio_clear_register(off_1138A0, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (volatile uint32_t *)co_list_push_back(dword_113894, v8);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}


// assert_fault @ 0x113904
int assert_fault(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  volatile uint8_t *v4; // r1
  int result; // r0
  uint16_t v6; // r3
  int v7; // r3
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1139A0 = 1;
  }
  v2 = (volatile int *)off_1139A4;
  v3 = dword_1139A8;
  ++*(volatile uint32_t *)off_1139A4;
  co_list_push_back(v3, a1);
  v4 = (void *)(uintptr_t)(off_1139B0);
  result = *(volatile uint8_t *)off_1139B0;
  v6 = *(volatile uint16_t *)off_1139AC + 1;
  *(volatile uint16_t *)off_1139AC = v6;
  if ( result && *(volatile uint8_t *)off_1139B4 <= (unsigned int)v6 )
  {
    v9 = *(volatile uint8_t *)off_1139B8;
    *v4 = 0;
    if ( v9 )
      *((volatile uint32_t *)off_1139BC + 512) &= ~0x2000u;
    else
      *((volatile uint32_t *)off_1139BC + 713) &= ~1u;
    state_check_4_b(1);
    ke_int_lock((int)(uintptr_t)((volatile char *)0x42D), 1);
    result = check_status_bits(512, aWfr);
    if ( !*(volatile uint8_t *)off_1139C4 )
      read_state_flag();
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(volatile uint32_t *)off_1139A0;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}


// ke_state_get_fast @ 0x1139c8
volatile uint32_t *ke_state_get_fast() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1139FC);
  result = zero_8_bytes((volatile uint32_t *)dword_113A00);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_113A04;
    v3 = dword_113A00;
    v4 = 0;
    do
    {
      v5 = buffer_pool_alloc(v2, 0x7Cu);
      result = (volatile uint32_t *)co_list_push_back(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// error_trap @ 0x113a08
volatile uint32_t *error_trap() {
  volatile int *v0; // r4
  int v1; // r0
  volatile uint32_t *result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113A3C = 1;
  }
  v0 = (volatile int *)off_113A40;
  v1 = dword_113A44;
  ++*(volatile uint32_t *)off_113A40;
  result = mem_word_load(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_113A3C;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// assert_error @ 0x113a48
int assert_error(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113A80 = 1;
  }
  v2 = (volatile int *)off_113A84;
  v3 = dword_113A88;
  ++*(volatile uint32_t *)off_113A84;
  result = co_list_push_back(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_113A80;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// is_flag_one @ 0x113a8c
BOOL is_flag_one() {
  return *((volatile uint8_t *)off_113A9C + 8) == 1;
}



// bt_init_1 @ 0x113aa0
int bt_init_1() {
  irq_state_load(off_113AB4);
  event_dispatch(aHostUsbStart);
  return 1;
}


// save_task_ptr @ 0x113abc
int save_task_ptr(int a1) {
  void *v1; // r5
  volatile uint32_t *v2; // r1
  volatile int *v3; // r2
  volatile uint32_t *v4; // r3
  volatile uint16_t *v5; // r6
  volatile int *v6; // r0
  volatile uint32_t *v7; // r2
  volatile uint32_t *v8; // r3
  volatile uint32_t *v9; // r4
  volatile int *v10; // r3
  int v11; // r5
  int v12; // r0
  int v13; // r1
  volatile uint32_t *v14; // r6
  volatile int *v15; // r2
  volatile uint8_t *v16; // r4
  int v17; // r1
  volatile uint8_t *v18; // r5
  int v19; // cc
  char v20; // r0
  int v21; // r3

  v1 = (void *)(uintptr_t)(off_113BC4);
  v2 = (void *)(uintptr_t)(off_113BCC);
  v3 = *(volatile int **)(*(volatile uint32_t *)off_113BC4 + 16);
  v4 = (void *)(uintptr_t)(off_113BD0);
  *(volatile uint32_t *)off_113BC8 = (int)(uintptr_t)(v3);
  *v2 = (int)(uintptr_t)(v3 + 16);
  v5 = (void *)(uintptr_t)(off_113BD4);
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset(v3, 0, 0x140u);
  v6 = *(volatile int **)(*(volatile uint32_t *)v1 + 20);
  v7 = (void *)(uintptr_t)(off_113BDC);
  v8 = (void *)(uintptr_t)(off_113BE0);
  *(volatile uint32_t *)off_113BD8 = (int)(uintptr_t)(v6);
  *v7 = (int)(uintptr_t)(v6 + 2);
  *v8 = (int)(uintptr_t)(v6 + 4);
  v8[1] = (int)(uintptr_t)(v6 + 6);
  v8[2] = (int)(uintptr_t)(v6 + 8);
  v8[3] = (int)(uintptr_t)(v6 + 10);
  v9 = (void *)(uintptr_t)(off_113BE4);
  v8[4] = (int)(uintptr_t)(v6 + 12);
  *v9 = (int)(uintptr_t)(v6 + 14);
  memset(v6, 0, 0xCB8u);
  if ( **(volatile int16_t **)off_113BE8 < 0 && *(volatile uint32_t *)(*(volatile uint32_t *)v1 + 24) <= 0xCB7u )
    mmio_clear_register((int)aIndexHostIfPar, (int)aHostUsbWlanIni, 758);
  v10 = (volatile int *)off_113BEC;
  v11 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113BEC)[82]);
  v12 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113BEC)[77]);
  v13 = dword_113BF4;
  v14 = (void *)(uintptr_t)(off_113BF8);
  *(volatile uint32_t *)off_113BFC = HIWORD(((volatile uint32_t *)(uintptr_t)off_113BEC)[76]) - *(volatile uint32_t *)(uintptr_t)(off_113BF0) - 4;
  v15 = (volatile int *)off_113C00;
  v16 = (void *)(uintptr_t)(off_113C04);
  v17 = v13 * v11;
  v18 = (void *)(uintptr_t)(off_113C08);
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113C0C;
  else
    v15 = (volatile int *)off_113C0C;
  *v18 = *((volatile uint8_t *)v10 + 320);
  v20 = *((volatile uint8_t *)v10 + 321);
  v21 = *((volatile uint8_t *)v10 + 368);
  *v16 = v20;
  if ( v19 )
    *v15 = v17;
  else
    *(volatile uint32_t *)v17 = (int)(uintptr_t)(v15);
  if ( v21 )
  {
    *(volatile uint8_t *)off_113C10 = v21;
    event_dispatch("usb in agg cnt %d\n", v21);
  }
  else
  {
    *(volatile uint8_t *)off_113C10 = 10;
    event_dispatch("usb in agg cnt %d\n", 10);
  }
  return 1;
}


// update_config_bytes @ 0x113c20
int update_config_bytes(int a1) {
  volatile uint8_t *v1; // r2
  char v2; // r3

  save_task_ptr(a1);
  v1 = (void *)(uintptr_t)(off_113C44);
  v2 = ((volatile uint32_t *)(uintptr_t)off_113C3C)[88];
  *(volatile uint8_t *)off_113C40 = BYTE2(((volatile uint32_t *)(uintptr_t)off_113C3C)[81]);
  *v1 = v2;
  return 1;
}


// check_packet_length @ 0x113c48
int check_packet_length(int a1) {
  unsigned int v1; // r3
  int v2; // r7
  int v4; // r8
  unsigned int v5; // r6
  volatile uint32_t *v6; // r4
  int v7; // r1
  int16_t v8; // r3
  int16_t v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r2

  v1 = *(volatile uint8_t *)(a1 + 25);
  v2 = *(volatile uint8_t *)(a1 + 24);
  if ( v1 <= 0x1F && !*(volatile uint8_t *)(dword_113D88 + 696 * v1 + 37) )
  {
    event_dispatch(aPktDiscardSinc);
    return is_controller_mode((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113D94) - 4));
  }
  v4 = dword_113DAC;
  if ( (*(volatile uint16_t *)(a1 + 26) & 8) == 0 )
  {
    if ( *(volatile uint8_t *)(dword_113DAC + 1320 * v2 + 108) )
    {
      v5 = *(volatile uint8_t *)(a1 + 22);
      if ( **(volatile int16_t **)off_113D8C < 0 && v5 > 4 )
        mmio_clear_register((int)aAcNxTxqCnt_0, (int)aHandleUsbRx, 926);
      v6 = (void *)(uintptr_t)(kernel_event_get());
      if ( v6 )
        goto LABEL_7;
LABEL_13:
      log_printf(" host rx: dscr used = %d\r\n", *(volatile uint8_t *)(dword_113D90 + v5));
      while ( 1 )
        ;
    }
    return is_controller_mode((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113D94) - 4));
  }
  v5 = 3;
  v6 = (void *)(uintptr_t)(kernel_event_get());
  if ( !v6 )
    goto LABEL_13;
LABEL_7:
  v7 = v6[19];
  v8 = *((volatile uint16_t *)v6 + 15) & 0xFFFE;
  ++*(volatile uint8_t *)(dword_113D90 + v5);
  *((volatile uint16_t *)v6 + 15) = v8;
  v6[17] = 0;
  *(volatile uint32_t *)(v7 + 4) = 0;
  *(volatile uint32_t *)(v7 + 72) = 0;
  v6[11] = 0;
  memcpy((volatile char *)v6 + 4, (volatile char *)a1, 0x1Cu);
  v9 = *((volatile uint16_t *)v6 + 15);
  v10 = *(volatile uint32_t *)(uintptr_t)(off_113D94);
  *((volatile uint16_t *)v6 + 3) = 0;
  v6[18] = a1 - v10 - 4;
  *((volatile uint8_t *)v6 + 66) = 0;
  v6[9] = 0;
  v6[21] = 0;
  *((volatile uint16_t *)v6 + 41) = 0;
  *((volatile uint16_t *)v6 + 15) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return co_list_push_back(v4 + 1320 * v2 + 1312, v6);
  v11 = *((volatile uint8_t *)v6 + 29);
  if ( v11 <= 0x1F )
  {
    v12 = *((volatile uint8_t *)v6 + 27);
    if ( v12 <= 8 )
      *(volatile uint32_t *)(dword_113D98 + 4 * (9 * v11 + v12 + 2062)) += *((volatile uint16_t *)v6 + 2);
  }
  return co_list_push_back(v4 + 8 * (v5 + 165 * v2 + 154), v6);
}


// call_checked @ 0x114058
int call_checked() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  mac_wait_scan();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114090 = 1;
  }
  v0 = (volatile int *)off_114094;
  ++*(volatile uint32_t *)off_114094;
  result = unknown_func_12d14c(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_114090;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// timer_delay_1 @ 0x114104
void timer_delay_1() {
  if ( !*(volatile uint8_t *)off_114110 )
    read_state_flag();
}



// invoke_callback @ 0x114114
int invoke_callback() {
  int v0; // r0
  volatile uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_114154 + 2) + 16))(*((volatile uint32_t *)off_114154 + 1));
  if ( !v0 )
    return log_printf(aErrNoWlanDataB);
  v1 = (volatile uint32_t *)v0;
  result = irq_state_load_b(*(volatile uint32_t *)off_114158 + v0, *(volatile uint32_t *)off_11415C);
  if ( result < 0 )
  {
    is_controller_mode(v1);
    return log_printf(aWlanDataRecvRe);
  }
  return result;
}


// store_byte_field @ 0x114168
int store_byte_field() {
  event_dispatch(aHostReady);
  return invoke_callback();
}


// is_current_task @ 0x1141c8
int is_current_task(int a1) {
  int result; // r0
  int v2; // r2

  if ( a1 == *(volatile uint32_t *)off_11421C )
  {
    v2 = 0;
  }
  else
  {
    if ( a1 != *((volatile uint32_t *)off_11421C + 1) )
    {
      result = event_dispatch("%s, func 0x%x unknown\n", (const volatile char *)a1, *(volatile uint32_t *)off_11421C);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = event_dispatch("%s, func is %s\n", aUsbTransErrorH, *(const volatile char **)&*((volatile uint8_t *)(uintptr_t)((volatile uint32_t *)(uintptr_t)&off_114228)[0] + (4 * v2)));
LABEL_4:
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_114224)[88]) )
    return ke_timer_set(1068, 1, 1000 * BYTE2(((volatile uint32_t *)(uintptr_t)off_114224)[88]));
  return result;
}


// process_task_queue @ 0x114234
volatile uint32_t *process_task_queue() {
  volatile int *v0; // r5
  void *v1; // r7
  volatile uint32_t *result; // r0
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (volatile int *)off_11427C;
  v1 = (void *)(uintptr_t)(off_114280);
  zero_8_bytes((volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)off_11427C)[0] + 628));
  result = zero_8_bytes((volatile uint32_t *)(*v0 + 636));
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) )
  {
    v3 = dword_114284;
    v4 = 0;
    do
    {
      v5 = buffer_pool_alloc(v3, 0x6B8u);
      result = (volatile uint32_t *)co_list_push_back(*v0 + 628, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// sub_11428c @ 0x11428c
int sub_11428c(volatile uint32_t *a1) {
  volatile int *v1; // r5
  volatile uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1142D4 = 1;
  }
  v1 = (volatile int *)off_1142D8;
  v2 = (void *)(uintptr_t)(off_1142DC);
  ++*(volatile uint32_t *)off_1142D8;
  while ( !*v2 )
    ;
  result = co_list_push_back(((volatile uint32_t *)(uintptr_t)off_1142E0)[0] + 628, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(volatile uint32_t *)off_1142D4;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}


// set_tx_power @ 0x1142e4
int set_tx_power() {
  check_status_bits(256, aHostIpcStart);
  return 1;
}


// init_bt_global @ 0x1142f8
int init_bt_global(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint16_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_114310);
  v2 = (void *)(uintptr_t)(off_114314);
  *((volatile uint32_t *)off_114310 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}



// get_global_1671bc @ 0x114550
int get_global_1671bc() {
  return event_dispatch(aErrorLpLevelPo_1);
}


// get_global_1671e0 @ 0x11455c
int get_global_1671e0() {
  return event_dispatch(aErrorLpLevelPo);
}


// get_global_167204 @ 0x114568
int get_global_167204() {
  return event_dispatch(aErrorLpLevelPo_0);
}


