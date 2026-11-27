// bt_evt_sched_high @ 0x113670
/* luna: Initializes the USB WLAN RX packet free list by allocating the configured receive buffers and reporting allocation failures. */
volatile uint32_t *bt_evt_sched_high() {
  void *v0; // r7
  volatile uint32_t *result; // r0
  volatile int *v2; // r9
  volatile uint16_t *initialized_buffer_count; // r6
  int v4; // r8
  volatile uint16_t **v5; // r10
  int16_t buffer_index; // r5
  unsigned int v7; // r1
  volatile uint32_t *rx_packet_item; // r4

  v0 = (void *)(uintptr_t)(off_1136EC);
  result = zero_struct((volatile uint32_t *)dword_1136F0);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (volatile int *)off_113700;
    initialized_buffer_count = (void *)(uintptr_t)(off_1136F4);
    v4 = dword_113704;
    v5 = (volatile uint16_t **)off_11370C;
    buffer_index = 0;
    do
    {
      rx_packet_item = rx_process_item(v4, (uint16_t)(*((volatile uint16_t *)v2 + 153) - 4));
      if ( !rx_packet_item )
      {
        ke_event_schedule_1("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", buffer_index);
        if ( **v5 < 0 )
          mmio_irq_clear(off_1136FC, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (volatile uint32_t *)check_abort_flag(dword_1136F0, rx_packet_item);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++buffer_index;
      ++*initialized_buffer_count;
    }
    while ( v7 > buffer_index );
  }
  return result;
}


// critical_section_enter @ 0x113760
int critical_section_enter(volatile uint32_t *a1) {
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
    *(volatile uint32_t *)off_1137FC = 1;
  }
  v2 = (volatile int *)off_113800;
  v3 = dword_113804;
  ++*(volatile uint32_t *)off_113800;
  check_abort_flag(v3, a1);
  v4 = (void *)(uintptr_t)(off_11380C);
  result = *(volatile uint8_t *)off_11380C;
  v6 = *(volatile uint16_t *)off_113808 + 1;
  *(volatile uint16_t *)off_113808 = v6;
  if ( result && *(volatile uint8_t *)off_113810 <= (unsigned int)v6 )
  {
    v9 = *(volatile uint8_t *)off_113814;
    *v4 = 0;
    if ( v9 )
      *((volatile uint32_t *)off_113818 + 512) &= ~0x2000u;
    else
      *((volatile uint32_t *)off_113818 + 713) &= ~1u;
    phy_reg_modify(1);
    irq_lock((volatile char *)0x42D, 1);
    result = state_check_feature(512, aWfr);
    if ( !*(volatile uint8_t *)off_113820 )
      bt_ctrl_main_task();
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(volatile uint32_t *)off_1137FC;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}


// bt_evt_sched_low @ 0x113824
volatile uint32_t *bt_evt_sched_low() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_113858);
  result = zero_struct((volatile uint32_t *)dword_11385C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_113860;
    v3 = dword_11385C;
    v4 = 0;
    do
    {
      v5 = rx_process_item(v2, 0x7Cu);
      result = (volatile uint32_t *)check_abort_flag(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// int_disable_set_flag @ 0x113864
int int_disable_set_flag() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113898 = 1;
  }
  v0 = (volatile int *)off_11389C;
  v1 = dword_1138A0;
  ++*(volatile uint32_t *)off_11389C;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_113898;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// critical_section_enter_no_set @ 0x1138a4
int critical_section_enter_no_set(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1138DC = 1;
  }
  v2 = (volatile int *)off_1138E0;
  v3 = dword_1138E4;
  ++*(volatile uint32_t *)off_1138E0;
  result = check_abort_flag(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_1138DC;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// is_rf_calib_running @ 0x1138e8
/* luna: Returns whether the RF calibration-in-progress flag is set. */
BOOL is_rf_calib_running() {
  return *((volatile uint8_t *)off_1138F8 + 8) == 1;
}



// init_memory_regions @ 0x1138fc
int init_memory_regions() {
  sys_cmu_clock_get(off_113910);
  ke_event_schedule_1(aHostUsbStart);
  return 1;
}


// rf_stat_read @ 0x113918
int rf_stat_read(int a1) {
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

  v1 = (void *)(uintptr_t)(off_113A20);
  v2 = (void *)(uintptr_t)(off_113A28);
  v3 = *(volatile int **)(*(volatile uint32_t *)off_113A20 + 16);
  v4 = (void *)(uintptr_t)(off_113A2C);
  *(volatile uint32_t *)off_113A24 = (int)(uintptr_t)(v3);
  *v2 = (int)(uintptr_t)(v3 + 16);
  v5 = (void *)(uintptr_t)(off_113A30);
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset(v3, 0, 0x140u);
  v6 = *(volatile int **)(*(volatile uint32_t *)v1 + 20);
  v7 = (void *)(uintptr_t)(off_113A38);
  v8 = (void *)(uintptr_t)(off_113A3C);
  *(volatile uint32_t *)off_113A34 = (int)(uintptr_t)(v6);
  *v7 = (int)(uintptr_t)(v6 + 2);
  *v8 = (int)(uintptr_t)(v6 + 4);
  v8[1] = (int)(uintptr_t)(v6 + 6);
  v8[2] = (int)(uintptr_t)(v6 + 8);
  v8[3] = (int)(uintptr_t)(v6 + 10);
  v9 = (void *)(uintptr_t)(off_113A40);
  v8[4] = (int)(uintptr_t)(v6 + 12);
  *v9 = (int)(uintptr_t)(v6 + 14);
  memset(v6, 0, 0xCB8u);
  if ( **(volatile int16_t **)off_113A44 < 0 && *(volatile uint32_t *)(*(volatile uint32_t *)v1 + 24) <= 0xCB7u )
    mmio_irq_clear((int)aIndexHostIfPar, (int)aHostUsbWlanIni, 758);
  v10 = (volatile int *)off_113A48;
  v11 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113A48)[82]);
  v12 = LOWORD(((volatile uint32_t *)(uintptr_t)off_113A48)[77]);
  v13 = dword_113A50;
  v14 = (void *)(uintptr_t)(off_113A54);
  *(volatile uint32_t *)off_113A58 = HIWORD(((volatile uint32_t *)(uintptr_t)off_113A48)[76]) - *(volatile uint32_t *)(uintptr_t)(off_113A4C) - 4;
  v15 = (volatile int *)off_113A5C;
  v16 = (void *)(uintptr_t)(off_113A60);
  v17 = v13 * v11;
  v18 = (void *)(uintptr_t)(off_113A64);
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = (int)off_113A68;
  else
    v15 = (volatile int *)off_113A68;
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
    *(volatile uint8_t *)off_113A6C = v21;
    ke_event_schedule_1("usb in agg cnt %d\n", v21);
  }
  else
  {
    *(volatile uint8_t *)off_113A6C = 10;
    ke_event_schedule_1("usb in agg cnt %d\n", 10);
  }
  return 1;
}


// rf_stat_apply @ 0x113a7c
int rf_stat_apply(int a1) {
  volatile uint8_t *v1; // r2
  char v2; // r3

  rf_stat_read(a1);
  v1 = (void *)(uintptr_t)(off_113AA0);
  v2 = *((volatile uint8_t *)off_113A98 + 352);
  *(volatile uint8_t *)off_113A9C = *((volatile uint8_t *)off_113A98 + 326);
  *v1 = v2;
  return 1;
}



// rx_packet_parse @ 0x113aa4
int rx_packet_parse(int a1) {
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
  if ( v1 <= 0x1F && !*(volatile uint8_t *)(dword_113BE4 + 696 * v1 + 37) )
  {
    ke_event_schedule_1(aPktDiscardSinc);
    return memory_pool_free((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113BF0) - 4));
  }
  v4 = dword_113C08;
  if ( (*(volatile uint16_t *)(a1 + 26) & 8) == 0 )
  {
    if ( *(volatile uint8_t *)(dword_113C08 + 1320 * v2 + 108) )
    {
      v5 = *(volatile uint8_t *)(a1 + 22);
      if ( **(volatile int16_t **)off_113BE8 < 0 && v5 > 4 )
        mmio_irq_clear((int)aAcNxTxqCnt_0, (int)aHandleUsbRx, 926);
      v6 = (void *)(uintptr_t)(scan_check_response());
      if ( v6 )
        goto LABEL_7;
LABEL_13:
      printf_wrapper(" host rx: dscr used = %d\r\n", *(volatile uint8_t *)(dword_113BEC + v5));
      while ( 1 )
        ;
    }
    return memory_pool_free((volatile uint32_t *)(a1 - *(volatile uint32_t *)(uintptr_t)(off_113BF0) - 4));
  }
  v5 = 3;
  v6 = (void *)(uintptr_t)(scan_check_response());
  if ( !v6 )
    goto LABEL_13;
LABEL_7:
  v7 = v6[19];
  v8 = *((volatile uint16_t *)v6 + 15) & 0xFFFE;
  ++*(volatile uint8_t *)(dword_113BEC + v5);
  *((volatile uint16_t *)v6 + 15) = v8;
  v6[17] = 0;
  *(volatile uint32_t *)(v7 + 4) = 0;
  *(volatile uint32_t *)(v7 + 72) = 0;
  v6[11] = 0;
  memcpy((volatile char *)v6 + 4, (volatile char *)a1, 0x1Cu);
  v9 = *((volatile uint16_t *)v6 + 15);
  v10 = *(volatile uint32_t *)(uintptr_t)(off_113BF0);
  *((volatile uint16_t *)v6 + 3) = 0;
  v6[18] = a1 - v10 - 4;
  *((volatile uint8_t *)v6 + 66) = 0;
  v6[9] = 0;
  v6[21] = 0;
  *((volatile uint16_t *)v6 + 41) = 0;
  *((volatile uint16_t *)v6 + 15) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return check_abort_flag(v4 + 1320 * v2 + 1312, v6);
  v11 = *((volatile uint8_t *)v6 + 29);
  if ( v11 <= 0x1F )
  {
    v12 = *((volatile uint8_t *)v6 + 27);
    if ( v12 <= 8 )
      *(volatile uint32_t *)(dword_113BF4 + 4 * (9 * v11 + v12 + 2062)) += *((volatile uint16_t *)v6 + 2);
  }
  return check_abort_flag(v4 + 8 * (v5 + 165 * v2 + 154), v6);
}


// sleep_exit_critical @ 0x113eb4
int sleep_exit_critical() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  rf_wait_idle();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113EEC = 1;
  }
  v0 = (volatile int *)off_113EF0;
  ++*(volatile uint32_t *)off_113EF0;
  result = set_system_flag_2(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_113EEC;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// bt_task_tail_dispatch @ 0x113f60
void bt_task_tail_dispatch() {
  if ( !*(volatile uint8_t *)off_113F6C )
    bt_ctrl_main_task();
}



// dispatch_function_ptr @ 0x113f70
int dispatch_function_ptr() {
  int v0; // r0
  volatile uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_113FB0 + 2) + 16))(*((volatile uint32_t *)off_113FB0 + 1));
  if ( !v0 )
    return printf_wrapper(aErrNoWlanDataB);
  v1 = (volatile uint32_t *)v0;
  result = global_env_init(*(volatile uint32_t *)off_113FB4 + v0, *(volatile uint32_t *)off_113FB8);
  if ( result < 0 )
  {
    memory_pool_free(v1);
    return printf_wrapper(aWlanDataRecvRe);
  }
  return result;
}


// log_and_handle @ 0x113fc4
int log_and_handle() {
  ke_event_schedule_1(aHostReady);
  return dispatch_function_ptr();
}


// band_is_supported @ 0x114024
int band_is_supported(int a1) {
  int result; // r0
  int v2; // r2

  if ( a1 == *(volatile uint32_t *)off_114078 )
  {
    v2 = 0;
  }
  else
  {
    if ( a1 != *((volatile uint32_t *)off_114078 + 1) )
    {
      result = ke_event_schedule_1("%s, func 0x%x unknown\n", (const volatile char *)a1, *(volatile uint32_t *)off_114078);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = ke_event_schedule_1("%s, func is %s\n", aUsbTransErrorH, *(const volatile char **)&*((volatile uint8_t *)(uintptr_t)((volatile uint32_t *)(uintptr_t)&off_114084)[0] + (4 * v2)));
LABEL_4:
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_114080)[88]) )
    return patch_aware_dispatch(1068, 1, 1000 * BYTE2(((volatile uint32_t *)(uintptr_t)off_114080)[88]));
  return result;
}


// init_hw_timers @ 0x114090
volatile uint32_t *init_hw_timers() {
  volatile int *v0; // r5
  void *v1; // r7
  volatile uint32_t *result; // r0
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (volatile int *)off_1140D8;
  v1 = (void *)(uintptr_t)(off_1140DC);
  zero_struct((volatile uint32_t *)(((volatile uint32_t *)(uintptr_t)off_1140D8)[0] + 564));
  result = zero_struct((volatile uint32_t *)(*v0 + 572));
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) )
  {
    v3 = dword_1140E0;
    v4 = 0;
    do
    {
      v5 = rx_process_item(v3, 0x6B8u);
      result = (volatile uint32_t *)check_abort_flag(*v0 + 564, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// set_busy_flag @ 0x1140e8
int set_busy_flag(volatile uint32_t *a1) {
  volatile int *v1; // r5
  volatile uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114130 = 1;
  }
  v1 = (volatile int *)off_114134;
  v2 = (void *)(uintptr_t)(off_114138);
  ++*(volatile uint32_t *)off_114134;
  while ( !*v2 )
    ;
  result = check_abort_flag(((volatile uint32_t *)(uintptr_t)off_11413C)[0] + 564, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(volatile uint32_t *)off_114130;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}


// init_queue_buffer @ 0x114140
int init_queue_buffer() {
  state_check_feature(256, aHostIpcStart);
  return 1;
}


// init_hw_state @ 0x114154
int init_hw_state(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint16_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_11416C);
  v2 = (void *)(uintptr_t)(off_114170);
  *((volatile uint32_t *)off_11416C + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}



// log_debug_a @ 0x1143ac
int log_debug_a() {
  return ke_event_schedule_1(aErrorLpLevelPo_1);
}


// log_debug_b @ 0x1143b8
int log_debug_b() {
  return ke_event_schedule_1(aErrorLpLevelPo);
}


// log_debug_c @ 0x1143c4
int log_debug_c() {
  return ke_event_schedule_1(aErrorLpLevelPo_0);
}


// log_and_check_hw @ 0x1143d0
int log_and_check_hw() {
  int result; // r0
  volatile uint8_t *v1; // r3
  volatile uint32_t *v2; // r1

  result = ke_event_schedule_1(aErrorLpLevelPo_0);
  v1 = (void *)(uintptr_t)(off_1143FC);
  if ( *((volatile uint8_t *)off_1143FC + 3) )
  {
    v2 = (void *)(uintptr_t)(off_114404);
    *(volatile uint32_t *)off_114400 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}


// check_radio_flag_1 @ 0x114408
unsigned int check_radio_flag_1(unsigned int result) {
  int v1; // r2

  if ( !result )
  {
    v1 = *(volatile uint32_t *)off_114478;
    if ( *(volatile uint32_t *)off_114478
      && (result = (*(volatile uint32_t *)0x40501010u), (int)(*(volatile uint32_t *)(v1 + 12) - result - LOWORD(((volatile uint32_t *)(uintptr_t)off_114480)[46]) - 2000) < 0) )
    {
      result = state_check_feature(2, "timer: not allow %x\r\n", *(volatile uint32_t *)(v1 + 4));
    }
    else
    {
      if ( !*(volatile uint8_t *)off_114484
        || (result = (*(volatile uint32_t *)0x40501010u),
            (int)(*((volatile uint32_t *)off_114484 + 1)
                + *((volatile uint32_t *)off_114484 + 2)
                - result
                - LOWORD(((volatile uint32_t *)(uintptr_t)off_114480)[46])
                - *(volatile uint16_t *)(*(volatile uint32_t *)off_114488 + 52)) >= 0) )
      {
        *(volatile uint32_t *)off_11448C = 0x40000000;
        return result;
      }
      result = state_check_feature(2, aOffsetNotAllow);
    }
  }
  *(volatile uint32_t *)off_11448C = 0x80000000;
  return result;
}


// init_chip_state @ 0x114498
int init_chip_state(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  volatile uint8_t *v6; // r1
  volatile uint32_t *v8; // r1

  if ( *(volatile uint32_t *)off_1144F8 )
  {
    v8 = (void *)(uintptr_t)(off_11450C);
    v1 = (volatile int *)dword_114510;
    *(volatile uint32_t *)off_1144FC = dword_114510;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(volatile int **)off_1144FC;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114500 + 6) == 1 )
    *((volatile uint32_t *)off_114504 + 83) |= v4;
  v6 = (void *)(uintptr_t)(off_114508);
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((volatile uint32_t *)v6 + 2) = v3;
  return 236;
}



// hw_sync_write @ 0x114514
void hw_sync_write() {
  **(volatile uint32_t **)off_114520 = **(volatile uint32_t **)off_114520;
}



// clear_hw_flag_bit @ 0x114524
/* luna: Clears bit 1 in the hardware flag word at offset 8 from the configured base address. */
void clear_hw_flag_bit() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_114534 + 8) &= ~2u;
}



// set_hw_flag_bit @ 0x114538
void set_hw_flag_bit() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_114548 + 8) |= 2u;
}



// get_core_state @ 0x11454c
int get_core_state() {
  int v0; // r2
  int v1; // r1
  volatile uint32_t *v2; // r3

  if ( *(volatile uint32_t *)off_114594 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(volatile uint32_t *)off_114594 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114590 + 6) == 1 )
    *((volatile uint32_t *)off_114598 + 83) &= ~v1;
  v2 = (void *)(uintptr_t)(off_1145A0);
  *(volatile uint32_t *)(*(volatile uint32_t *)off_11459C + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}



// phy_calibrate_1 @ 0x1145a4
void phy_calibrate_1() {
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CONTROL; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_114664;
  v1 = *(volatile uint32_t *)(*(volatile uint32_t *)off_114664 + 16);
  ke_event_schedule_1("\nINT:%x,%x,%x", v1, *(volatile uint32_t *)off_11466C, *(volatile uint32_t *)off_114668);
  if ( (v1 & 1) != 0 )
    *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 12) = 1;
  CONTROL = __get_CONTROL();
  v4 = __get_XPSR();
  v5 = __get_PSP();
  v6 = __get_MSP();
  ke_event_schedule_1(aControl08xXpsr_0, CONTROL, v4, v5, v6, __get_PRIMASK(), (int)__get_LR());
  if ( v5 )
  {
    ke_event_schedule_1(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_114694 - v7) >> 2;
  ke_event_schedule_1(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  rx_packet_handler_2(v7, v9, 4, 0);
LABEL_5:
  ke_event_schedule_1(aIser);
  rx_packet_handler_2(dword_11467C, 8, 4, 0);
  ke_event_schedule_1(aIspr);
  rx_packet_handler_2(dword_114684, 8, 4, 0);
  ke_event_schedule_1(aTim2);
  rx_packet_handler_2((int)&REG_4050_1000, 16, 4, 0);
  check_op_mode();
}


// invoke_callback @ 0x11469c
int invoke_callback(volatile int *a1) {
  int result; // r0

  if ( *(volatile uint32_t *)off_1146C8 )
    return check_abort_flag(off_1146C8, (void *)(a1));
  result = sys_control((int)(a1 + 1), *a1);
  if ( result )
  {
    ke_event_schedule_1("sdio bt MB send err %d\n", result);
    return check_abort_flag(off_1146C8, (void *)(a1));
  }
  return result;
}


// lock_acquire @ 0x1146d0
int lock_acquire() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114704 = 1;
  }
  v0 = (volatile int *)off_114708;
  v1 = dword_11470C;
  ++*(volatile uint32_t *)off_114708;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_114704;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// lock_release @ 0x114710
int lock_release(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114748 = 1;
  }
  v2 = (volatile int *)off_11474C;
  v3 = dword_114750;
  ++*(volatile uint32_t *)off_11474C;
  result = check_abort_flag(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_114748;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// init_osal_objects @ 0x114754
volatile uint32_t *init_osal_objects() {
  int v0; // r4
  volatile uint32_t *v1; // r6
  volatile uint32_t *v2; // r5

  v0 = dword_114788;
  v1 = (volatile uint32_t *)dword_11478C;
  v2 = (volatile uint32_t *)(dword_114788 + 8);
  zero_struct((volatile uint32_t *)dword_114788);
  zero_struct(v2);
  check_abort_flag((int)v2, v1);
  check_abort_flag((int)v2, v1 + 256);
  return zero_struct((volatile uint32_t *)(v0 + 16));
}


// dispatch_by_cmd @ 0x114790
/* luna: Returns the total H:4 frame length from its packet indicator and type-specific payload length field, or -1 for an unsupported packet type. */
int dispatch_by_cmd(volatile uint8_t *a1) {
  int packet_type; // r3

  packet_type = *a1;
  switch ( packet_type )
  {
    case 1:
      return a1[3] + 4;
    case 2:
      return *(volatile uint16_t *)(a1 + 3) + 5;
    case 3:
      return a1[3] + 4;
    case 4:
      return a1[2] + 3;
  }
  return -1;
}



// wait_for_value @ 0x1147bc
unsigned int wait_for_value(volatile char *a1, unsigned int a2) {
  int v4; // r0
  void *v5; // r7
  volatile char *v6; // r6

  v4 = dispatch_by_cmd((volatile uint8_t *)a1);
  if ( v4 < 0 )
  {
    ke_event_schedule_1("err type:%x\n", (uint8_t)*a1);
    return a2;
  }
  else if ( v4 == a2 )
  {
    v5 = (void *)(uintptr_t)(off_11481C);
    if ( *((volatile uint32_t *)off_11481C + 2) )
    {
      v6 = (volatile char *)lock_acquire();
      memcpy(v6 + 4, a1, a2);
      check_abort_flag((int)v5 + 16, (void *)(v6));
      set_system_flag_1(16);
    }
    else
    {
      ke_event_schedule_1(aErrNoFreeCom, v4);
    }
    return a2;
  }
  else
  {
    ke_event_schedule_1("err len:%d,%d\n", v4, a2);
    return a2;
  }
}


// malloc_from_heap @ 0x11482c
volatile uint32_t * malloc_from_heap(int a1) {
  volatile int *v1; // r4
  volatile uint32_t *result; // r0
  int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int v7; // r0

  v1 = (volatile int *)off_114874;
  result = (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)((volatile char *)(a1 - 16))));
  v3 = *v1;
  if ( *v1 )
  {
    v4 = v3 + 4;
    v5 = dispatch_by_cmd((volatile uint8_t *)(v3 + 4));
    if ( v5 < 0 )
    {
      return (volatile uint32_t *)ke_event_schedule_1("err typ:%x\n", *(volatile uint8_t *)(v6 + 4));
    }
    else
    {
      v7 = sys_control(v4, v5);
      if ( v7 )
        return (volatile uint32_t *)ke_event_schedule_1("MB send err %d\n", v7);
      else
        return list_pop_front((int)v1);
    }
  }
  return result;
}


// semaphore_create @ 0x114880
int semaphore_create(int a1, volatile int *a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r0
  volatile uint16_t *v11; // r3

  v7 = (volatile uint8_t *)bt_buf_alloc(3089, a4, a3, 1);
  v8 = *a2;
  v9 = *((volatile uint8_t *)a2 + 4);
  v10 = dispatch_by_cmd((volatile uint8_t *)a2 + 4);
  if ( v10 < 0 )
  {
    ke_event_schedule_1("bt type err:%d, len=%d\n", v9, v8);
    hci_evt_send((int)v7);
    return 0;
  }
  else if ( v8 == v10 )
  {
    v11 = (void *)(uintptr_t)(off_114904);
    *((volatile uint16_t *)off_114904 + 12) = a3;
    v11[13] = a4;
    invoke_callback(a2);
    *v7 = 1;
    ke_event_schedule_1("\x9D\x81sdio_bt: [%d] len=%d\n", v9, v8);
    hci_evt_send((int)v7);
    return 1;
  }
  else
  {
    ke_event_schedule_1("bt len err:%d,%d\n", v10, v8);
    hci_evt_send((int)v7);
    return 0;
  }
}


// setup_patch_data @ 0x114914
int setup_patch_data() {
  command_enqueue(0, 0, off_114938, off_11493C, 1);
  init_osal_objects();
  return ke_event_schedule_1(aSdioBtInit);
}


// find_object_by_key @ 0x114944
int find_object_by_key(char a1, uint16_t a2, int a3) {
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r6
  unsigned int v9; // r5
  volatile uint16_t *v10; // r3
  int v11; // r5
  uint16_t v12; // r1
  uint16_t v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r3
  uint64_t v17; // r4

  v6 = (void *)(uintptr_t)(critical_enter_2());
  if ( v6 )
  {
    v7 = v6;
    v8 = (void *)(uintptr_t)(critical_enter_0());
    if ( v8 )
    {
      v9 = *(volatile uint32_t *)a3;
      v10 = (void *)(uintptr_t)(off_1149E8);
      *((volatile uint8_t *)v7 + 2) = a1;
      v11 = (uint16_t)(v9 + 4);
      *(volatile uint8_t *)v7 = v11 + 12;
      *((volatile uint8_t *)v7 + 1) = ((uint16_t)(v11 + 12) >> 8) & 0xF;
      *((volatile uint8_t *)v7 + 3) = 0;
      v12 = v10[13];
      v13 = v10[12];
      v14 = dword_1149EC;
      *((volatile uint16_t *)v7 + 3) = v12;
      *((volatile uint16_t *)v7 + 4) = v13;
      *((volatile uint16_t *)v7 + 5) = v11;
      *((volatile uint16_t *)v7 + 2) = a2;
      v7[3] = v14;
      if ( v11 )
      {
        v7[4] = *(volatile uint32_t *)a3;
        memcpy((volatile char *)v7 + 20, (volatile char *)(a3 + 4), *(volatile uint32_t *)a3);
      }
      v15 = v8[2];
      v16 = dword_1149F0;
      *v8 = (int)(uintptr_t)(v7);
      v17 = (v17 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v17 = (v17 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((uint16_t)(v11 + 16) | v16 & v15 | 0x80000000) << 32);
      *(volatile uint64_t *)(v8 + 1) = v17;
      ke_mutex_lock((int)v8);
      return 0;
    }
    else
    {
      ke_event_schedule_1(aErrSendMsgCfgT);
      memory_pool_free(v7);
      return -2;
    }
  }
  else
  {
    ke_event_schedule_1(aErrSdioBtNoDat);
    return -1;
  }
}


// alloc_small_buffer @ 0x1149fc
volatile int *alloc_small_buffer() {
  volatile int *v0; // r4
  volatile int *result; // r0
  int v2; // r2
  int v3; // r1
  int v4; // r3
  volatile int *v5; // r5
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r3
  int v10; // r2
  int v11; // r3
  int v12; // r2
  volatile int *v13; // r3
  int v14; // r3

  set_system_flag_2(16);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114AD8 = 1;
  }
  v0 = (volatile int *)off_114ADC;
  result = (volatile int *)off_114AE0;
  v2 = *(volatile uint32_t *)off_114ADC;
  v3 = *((volatile uint32_t *)off_114AE0 + 4);
  v4 = *(volatile uint32_t *)off_114ADC + 1;
  *(volatile uint32_t *)off_114ADC = v4;
  if ( v3 )
  {
    result = (void *)(list_pop_front((int)(result + 4)));
    v5 = result;
    if ( *v0 )
    {
      v11 = *v0 - 1;
      v12 = *(volatile uint32_t *)off_114AD8;
      *v0 = v11;
      if ( !v11 )
      {
        if ( v12 )
          __enable_irq();
      }
    }
    if ( result )
    {
      v6 = dispatch_by_cmd((volatile uint8_t *)result + 4);
      if ( v6 < 0 )
      {
        return (volatile int *)ke_event_schedule_1("err typ:%x\n", *((volatile uint8_t *)v5 + 4));
      }
      else
      {
        *v5 = v6;
        v7 = find_object_by_key(17, 3090, (int)v5);
        if ( v7 )
        {
          ke_event_schedule_1("bt ahb2sdio err %d\n", v7);
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_114AD8 = 1;
          }
          v8 = dword_114AE8;
          ++*v0;
          check_abort_flag_2(v8, (void *)(v5));
          if ( *v0 )
          {
            v9 = *v0 - 1;
            v10 = *(volatile uint32_t *)off_114AD8;
            *v0 = v9;
            if ( !v9 )
            {
              if ( v10 )
                __enable_irq();
            }
          }
          return (volatile int *)set_system_flag_1(16);
        }
        else
        {
          lock_release((void *)(v5));
          return (volatile int *)periph_write(0);
        }
      }
    }
  }
  else if ( v4 )
  {
    v13 = (volatile int *)off_114AD8;
    *v0 = v2;
    v14 = *v13;
    if ( !v2 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}


