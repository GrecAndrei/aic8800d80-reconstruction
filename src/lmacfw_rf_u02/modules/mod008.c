// map_event_type @ 0x112ef4
volatile uint32_t * map_event_type(int a1) {
  volatile uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = (void *)(uintptr_t)(off_112F4C);
      v3 = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(off_112F4C), (void *)(uintptr_t)(dword_112F50), 18));
      if ( *((volatile uint8_t *)off_112F54 + 370) && rf_get_reg1_bit9(v3) )
      {
        v4 = rf_get_reg2();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (uint16_t)v4;
        return v2;
      }
      else
      {
        return (void *)(uintptr_t)(off_112F4C);
      }
    case 6:
      return (volatile uint32_t *)dword_112F48;
    case 15:
      return (volatile uint32_t *)dword_112F44;
    default:
      return 0;
  }
}



// lookup_table_value @ 0x112f58
int lookup_table_value(unsigned int a1) {
  if ( a1 > 7 )
    return 0;
  else
    return *(volatile uint32_t *)(dword_112F68 + 4 * a1);
}



// main_event_handler @ 0x112f6c
void main_event_handler(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r5
  volatile uint16_t *v5; // r2
  int v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r8
  volatile int *v9; // r6
  int v10; // r1
  int v11; // r0
  int v12; // r0
  volatile uint8_t *v13; // r7
  int v14; // r9
  int v15; // r1
  int v16; // r0
  int v17; // r0
  volatile uint16_t *v18; // r3

  v4 = (void *)(uintptr_t)(off_113098);
  if ( *(volatile uint8_t *)off_113098 )
  {
    if ( !*(volatile uint16_t *)off_1130A4 )
    {
      check_interrupt_flag(512, "#we\n");
      return;
    }
    if ( *(volatile uint8_t *)off_1130A0 >= (unsigned int)*(volatile uint16_t *)off_1130A4 )
    {
      v18 = (volatile uint16_t *)off_1130A8;
      *(volatile uint8_t *)off_11309C = 1;
      check_interrupt_flag(512, "#wf:%X\n", *v18);
    }
  }
  else
  {
    if ( *(volatile uint8_t *)off_11309C )
      return;
    if ( *(volatile uint8_t *)off_1130A0 >= (unsigned int)*(volatile uint16_t *)off_1130A4 && !*(volatile uint8_t *)off_11309C )
    {
      v5 = (volatile uint16_t *)off_1130A8;
      *(volatile uint8_t *)off_11309C = 1;
      check_interrupt_flag(512, "#wf:%X\n", *v5);
      return;
    }
  }
  v6 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_1130B0 + 2) + 16))(*((volatile uint32_t *)off_1130B0 + 1));
  v7 = (volatile uint32_t *)v6;
  if ( v6 )
  {
    if ( *v4 )
    {
      v8 = (volatile uint32_t *)off_1130C8;
      v9 = (volatile int *)off_1130B4;
      v10 = *(volatile uint32_t *)off_1130B4;
      v11 = *(volatile uint32_t *)off_1130C8 + v6;
      if ( *(volatile uint8_t *)off_11309C )
        v12 = send_control_packet(v11, v10);
      else
        v12 = send_data_packet(v11, v10);
    }
    else
    {
      v8 = (volatile uint32_t *)off_1130C8;
      v9 = (volatile int *)off_1130B4;
      v12 = send_data_packet(*(volatile uint32_t *)off_1130C8 + v6, *(volatile uint32_t *)off_1130B4);
    }
    if ( v12 )
    {
      v13 = (void *)(uintptr_t)(off_11309C);
      log_printf("wd rx %d\r\n", v12);
      v14 = 5;
      while ( 1 )
      {
        if ( *v4 )
        {
          v15 = *v9;
          v16 = (int)v7 + *v8;
          v17 = *v13 ? send_control_packet(v16, v15) : send_data_packet(v16, v15);
        }
        else
        {
          v17 = send_data_packet((int)v7 + *v8, *v9);
        }
        if ( !v17 )
          break;
        if ( !--v14 )
        {
          log_printf("wd rx max time %d\r\n", 5);
          mem_free(v7);
          set_busy_flag_alt(256);
          return;
        }
      }
    }
  }
  else
  {
    set_busy_flag_alt(256);
    log_printf(aErrWdNoRxBuf);
  }
}


// timer_event_handler @ 0x1130cc
volatile uint32_t *timer_event_handler() {
  void *v0; // r7
  volatile uint32_t *result; // r0
  int v2; // r9
  volatile uint16_t *v3; // r6
  int v4; // r8
  volatile int16_t **v5; // r10
  int16_t v6; // r5
  unsigned int v7; // r1
  volatile uint32_t *v8; // r4

  v0 = (void *)(uintptr_t)(off_113148);
  result = list_init_1((volatile uint32_t *)dword_11314C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = ((volatile uint32_t *)(uintptr_t)&off_11315C)[0];
    v3 = (void *)(uintptr_t)(off_113150);
    v4 = dword_113160;
    v5 = (volatile int16_t **)off_113168;
    v6 = 0;
    do
    {
      v8 = list_iterate(v4, (uint16_t)(*(volatile uint16_t *)(v2 + 0x132) - 4));
      if ( !v8 )
      {
        dispatch_event_handler_1("usb_wlan_rx_pkt_free_list_init alloc fail: %d\n", v6);
        if ( **v5 < 0 )
          flash_ctrl_init(off_113158, (int)aUsbWlanRxPktFr_0, 495);
      }
      result = (volatile uint32_t *)check_kernel_state(dword_11314C, v8);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v6;
      ++*v3;
    }
    while ( v7 > v6 );
  }
  return result;
}


// critical_section_enter_arg @ 0x1131bc
int critical_section_enter_arg(volatile uint32_t *a1) {
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
    *(volatile uint32_t *)off_113258 = 1;
  }
  v2 = (volatile int *)off_11325C;
  v3 = dword_113260;
  ++*(volatile uint32_t *)off_11325C;
  check_kernel_state(v3, a1);
  v4 = (void *)(uintptr_t)(off_113268);
  result = *(volatile uint8_t *)off_113268;
  v6 = *(volatile uint16_t *)off_113264 + 1;
  *(volatile uint16_t *)off_113264 = v6;
  if ( result && *(volatile uint8_t *)off_11326C <= (unsigned int)v6 )
  {
    v9 = *(volatile uint8_t *)off_113270;
    *v4 = 0;
    if ( v9 )
      *((volatile uint32_t *)off_113274 + 512) &= ~0x2000u;
    else
      *((volatile uint32_t *)off_113274 + 713) &= ~1u;
    rf_read_status(1);
    ke_int_lock((int)(uintptr_t)((volatile char *)0x42D), 1);
    result = check_interrupt_flag(512, aWfr);
    if ( !*(volatile uint8_t *)off_11327C )
      main_event_handler(result, v10, v11, *(volatile uint8_t *)off_11327C);
  }
  if ( *v2 )
  {
    v7 = *v2 - 1;
    v8 = *(volatile uint32_t *)off_113258;
    *v2 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}


// tx_event_handler @ 0x113280
volatile uint32_t *tx_event_handler() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1132B4);
  result = list_init_1((volatile uint32_t *)dword_1132B8);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_1132BC;
    v3 = dword_1132B8;
    v4 = 0;
    do
    {
      v5 = list_iterate(v2, 0x7Cu);
      result = (volatile uint32_t *)check_kernel_state(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// disable_interrupts @ 0x1132c0
int disable_interrupts() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1132F4 = 1;
  }
  v0 = (volatile int *)off_1132F8;
  v1 = dword_1132FC;
  ++*(volatile uint32_t *)off_1132F8;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1132F4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// lock_acquire @ 0x113300
int lock_acquire(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113338 = 1;
  }
  v2 = (volatile int *)off_11333C;
  v3 = dword_113340;
  ++*(volatile uint32_t *)off_11333C;
  result = check_kernel_state(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_113338;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// is_radio_powered @ 0x113344
BOOL is_radio_powered() {
  return *((volatile uint8_t *)off_113354 + 8) == 1;
}



// init_driver_states @ 0x113358
int init_driver_states() {
  wait_rf_ready_1(off_11336C);
  dispatch_event_handler_1(aHostUsbStart);
  return 1;
}


// update_hw_config @ 0x113374
int update_hw_config(int a1) {
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

  v1 = (void *)(uintptr_t)(off_11347C);
  v2 = (void *)(uintptr_t)(off_113484);
  v3 = *(volatile int **)(*(volatile uint32_t *)off_11347C + 16);
  v4 = (void *)(uintptr_t)(off_113488);
  *(volatile uint32_t *)off_113480 = (int)(uintptr_t)(v3);
  *v2 = (int)(uintptr_t)(v3 + 16);
  v5 = (void *)(uintptr_t)(off_11348C);
  v4[2] = a1;
  *v4 = 0;
  v4[1] = 0;
  v4[4] = 0;
  v4[5] = 0;
  v4[3] = 0;
  v5[6] = 0;
  memset(v3, 0, 0x140u);
  v6 = *(volatile int **)(*(volatile uint32_t *)v1 + 20);
  v7 = (void *)(uintptr_t)(off_113494);
  v8 = (void *)(uintptr_t)(off_113498);
  *(volatile uint32_t *)off_113490 = (int)(uintptr_t)(v6);
  *v7 = (int)(uintptr_t)(v6 + 2);
  *v8 = (int)(uintptr_t)(v6 + 4);
  v8[1] = (int)(uintptr_t)(v6 + 6);
  v8[2] = (int)(uintptr_t)(v6 + 8);
  v8[3] = (int)(uintptr_t)(v6 + 10);
  v9 = (void *)(uintptr_t)(off_11349C);
  v8[4] = (int)(uintptr_t)(v6 + 12);
  *v9 = (int)(uintptr_t)(v6 + 14);
  memset(v6, 0, 0xCB8u);
  if ( **(volatile int16_t **)off_1134A0 < 0 && *(volatile uint32_t *)(*(volatile uint32_t *)v1 + 24) <= 0xCB7u )
    flash_ctrl_init((int)aIndexHostIfPar, (int)aHostUsbWlanIni, 758);
  v10 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_1134A4)[0]);
  v11 = *((volatile uint16_t *)((volatile uint32_t *)(uintptr_t)&off_1134A4)[0] + 164);
  v12 = *((volatile uint16_t *)((volatile uint32_t *)(uintptr_t)&off_1134A4)[0] + 154);
  v13 = dword_1134AC;
  v14 = (void *)(uintptr_t)(off_1134B0);
  *(volatile uint32_t *)off_1134B4 = *((volatile uint16_t *)((volatile uint32_t *)(uintptr_t)&off_1134A4)[0] + 153) - *(volatile uint32_t *)(uintptr_t)(off_1134A8) - 4;
  v15 = (volatile int *)off_1134B8;
  v16 = (void *)(uintptr_t)(off_1134BC);
  v17 = v13 * v11;
  v18 = (void *)(uintptr_t)(off_1134C0);
  *v14 = v12 - 4;
  v19 = v17 <= (int)v15;
  if ( v17 > (int)v15 )
    v17 = off_1134C4;
  else
    v15 = (volatile int *)off_1134C4;
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
    *(volatile uint8_t *)off_1134C8 = v21;
    dispatch_event_handler_1("usb in agg cnt %d\n", v21);
  }
  else
  {
    *(volatile uint8_t *)off_1134C8 = 10;
    dispatch_event_handler_1("usb in agg cnt %d\n", 10);
  }
  return 1;
}


// refresh_config_params @ 0x1134d8
int refresh_config_params(int a1) {
  volatile uint8_t *v1; // r2
  char v2; // r3

  update_hw_config(a1);
  v1 = (void *)(uintptr_t)(off_1134FC);
  v2 = *((volatile uint8_t *)off_1134F4 + 352);
  *(volatile uint8_t *)off_1134F8 = *((volatile uint8_t *)off_1134F4 + 326);
  *v1 = v2;
  return 1;
}



// check_and_process @ 0x113630
void check_and_process(int a1, int a2, int a3) {
  if ( !*(volatile uint8_t *)off_11363C )
    main_event_handler(a1, a2, a3, *(volatile uint8_t *)off_11363C);
}



// dispatch_event_handler @ 0x113640
int dispatch_event_handler() {
  int v0; // r0
  volatile uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((volatile uint32_t *)off_113680 + 2) + 16))(*((volatile uint32_t *)off_113680 + 1));
  if ( !v0 )
    return log_printf(aErrNoWlanDataB);
  v1 = (volatile uint32_t *)v0;
  result = send_data_packet(*(volatile uint32_t *)off_113684 + v0, *(volatile uint32_t *)off_113688);
  if ( result < 0 )
  {
    mem_free(v1);
    return log_printf(aWlanDataRecvRe);
  }
  return result;
}


// prepare_and_dispatch @ 0x113694
int prepare_and_dispatch() {
  dispatch_event_handler_1(aHostReady);
  return dispatch_event_handler();
}


// lookup_task_id @ 0x1136f4
int lookup_task_id(int a1) {
  int result; // r0
  int v2; // r2

  if ( a1 == *(volatile uint32_t *)off_113748 )
  {
    v2 = 0;
  }
  else
  {
    if ( a1 != *((volatile uint32_t *)off_113748 + 1) )
    {
      result = dispatch_event_handler_1("%s, func 0x%x unknown\n", (const volatile char *)a1, *(volatile uint32_t *)off_113748);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = dispatch_event_handler_1("%s, func is %s\n", aUsbTransErrorH, *(const volatile char **)(off_113754 + 4 * v2));
LABEL_4:
  if ( *((volatile uint8_t *)off_113750 + 353) )
    return ke_event_loop(1068, 1, 1000 * *((volatile uint8_t *)off_113750 + 354));
  return result;
}


// controller_state_machine @ 0x113760
volatile uint32_t *controller_state_machine() {
  void *v0; // r5
  void *v1; // r7
  volatile uint32_t *result; // r0
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1137A8);
  v1 = (void *)(uintptr_t)(off_1137AC);
  list_init_1((volatile uint32_t *)(*(volatile uint32_t *)off_1137A8 + 580));
  result = list_init_1((volatile uint32_t *)(*(volatile uint32_t *)v0 + 588));
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) )
  {
    v3 = dword_1137B0;
    v4 = 0;
    do
    {
      v5 = list_iterate(v3, 0x6B8u);
      result = (volatile uint32_t *)check_kernel_state(*(volatile uint32_t *)v0 + 580, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v1 + 8) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// enter_critical_section @ 0x1137b8
int enter_critical_section(volatile uint32_t *a1) {
  volatile int *v1; // r5
  volatile uint32_t *v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_113800 = 1;
  }
  v1 = (volatile int *)off_113804;
  v2 = (void *)(uintptr_t)(off_113808);
  ++*(volatile uint32_t *)off_113804;
  while ( !*v2 )
    ;
  result = check_kernel_state(*(volatile uint32_t *)off_11380C + 580, a1);
  *v2 = 1;
  if ( *v1 )
  {
    v4 = *v1 - 1;
    v5 = *(volatile uint32_t *)off_113800;
    *v1 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}


// send_hci_event @ 0x113810
int send_hci_event() {
  check_interrupt_flag(256, aHostIpcStart);
  return 1;
}


// fw_sub_1213824_load_struct_call @ 0x113824
int fw_sub_1213824_load_struct_call(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint16_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_11383C);
  v2 = (void *)(uintptr_t)(off_113840);
  *((volatile uint32_t *)off_11383C + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}



// bt_module_init @ 0x113854
int bt_module_init(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  volatile uint8_t *v6; // r1
  volatile uint32_t *v8; // r1

  if ( *(volatile uint32_t *)off_1138B4 )
  {
    v8 = (void *)(uintptr_t)(off_1138C8);
    v1 = (volatile int *)dword_1138CC;
    *(volatile uint32_t *)off_1138B8 = dword_1138CC;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(volatile int **)off_1138B8;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_1138BC + 6) == 1 )
    *((volatile uint32_t *)off_1138C0 + 83) |= v4;
  v6 = (void *)(uintptr_t)(off_1138C4);
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((volatile uint32_t *)v6 + 2) = v3;
  return 236;
}



// memory_barrier_write @ 0x1138d0
void memory_barrier_write() {
  **(volatile uint32_t **)off_1138DC = **(volatile uint32_t **)off_1138DC;
}



// clear_irq_flag @ 0x1138e0
void clear_irq_flag() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_1138F0 + 8) &= ~2u;
}



// check_rx_active @ 0x1138f4
int check_rx_active() {
  int v0; // r2
  int v1; // r1
  volatile uint32_t *v2; // r3

  if ( *(volatile uint32_t *)off_11393C )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(volatile uint32_t *)off_11393C )
    v1 = 1;
  else
    v1 = 2;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_113938 + 6) == 1 )
    *((volatile uint32_t *)off_113940 + 83) &= ~v1;
  v2 = (void *)(uintptr_t)(off_113948);
  *(volatile uint32_t *)(*(volatile uint32_t *)off_113944 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}



