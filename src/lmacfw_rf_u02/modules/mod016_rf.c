// rf_read_status_1 @ 0x118d40
unsigned int rf_read_status_1(volatile int *a1) {
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r7
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r1
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  volatile int16_t **v9; // r0
  volatile int *v10; // r4
  int v11; // r2
  volatile int16_t *v12; // r3

  v1 = (void *)(uintptr_t)(off_118DB8);
  v2 = (void *)(uintptr_t)(off_118DBC);
  v3 = (void *)(uintptr_t)(off_118DC0);
  v4 = (void *)(uintptr_t)(off_118DC4);
  v5 = (void *)(uintptr_t)(off_118DC8);
  v6 = (void *)(uintptr_t)(off_118DCC);
  *(volatile uint32_t *)off_118DB8 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((volatile uint16_t *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (volatile int16_t **)off_118DD0;
  v10 = (volatile int *)off_118DD4;
  v11 = dword_118DD8;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(volatile uint32_t *)off_118DE0 << 28 )
  {
    flash_cmd_exec(dword_118DE8, dword_118DE4, 472);
    v11 = *v10;
  }
  *(volatile uint32_t *)off_118DDC = v11 | v10[1];
  return gpio_set_bit10(0);
}



// rf_enable_1 @ 0x118dec
unsigned int rf_enable_1() {
  unsigned int result; // r0
  int v1; // r1
  volatile uint32_t *v2; // r2

  *(volatile uint32_t *)off_118E10 |= 2u;
  result = gpio_set_bit10(0);
  v1 = dword_118E18;
  v2 = (void *)(uintptr_t)(off_118E1C);
  *(volatile uint32_t *)off_118E14 = dword_118E18;
  *v2 |= v1;
  return result;
}



// rf_disable @ 0x118e20
/* luna: Disables the RF subsystem by clearing its control-enable bits and setting the associated GPIO, while returning the GPIO result. */
unsigned int rf_disable() {
  unsigned int result; // r0
  volatile uint32_t *rf_ctrl_ptr; // r2

  *(volatile uint32_t *)off_118E48 &= ~2u;
  result = gpio_set_bit10(0);
  rf_ctrl_ptr = (void *)(uintptr_t)(off_118E50);
  *(volatile uint32_t *)off_118E4C = dword_118E54;
  *rf_ctrl_ptr &= 0xFFFBFFFE;
  return result;
}



// rf_packet_available @ 0x118e58
int rf_packet_available() {
  if ( **(volatile int16_t **)off_118EB0 < 0 && flash_write_byte(0) != 3 )
    flash_ctrl_init((int)aKeStateGetTask_0, (int)aMmBackToHostId, 1785);
if ( *((volatile uint8_t *)((volatile uint32_t *)(uintptr_t)&off_118EB4)[0] + 28) && *((volatile uint8_t *)off_118EB8 + 18) + *((volatile uint8_t *)off_118EB8 + 17) <= 1 ) { return flash_erase_sector(0, 0);
  }
  *(volatile uint32_t *)off_118EBC = 48;
  return flash_erase_sector(0, 1);
}


// rf_state_process @ 0x118ec8
int rf_state_process() {
  volatile int *v0; // r8
  volatile int *v1; // r4
  int v2; // r3
  volatile unsigned int v3; // r7
  int v4; // r9
  unsigned int v5; // r3
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int result; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2

  if ( **(volatile int16_t **)off_118FA0 < 0 && flash_write_byte(0) == 4 )
    flash_ctrl_init((int)aKeStateGetTask, (int)aMmForceIdleReq, 1799);
  check_interrupt_flag(4, aForceIdle);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_118FA8 = 1;
  }
  v0 = (volatile int *)off_118FD4;
  v1 = (volatile int *)off_118FAC;
  ++*(volatile uint32_t *)off_118FD4;
  v2 = *v1;
  *v1 = 0;
  v3 = (*(volatile uint32_t *)0x40501010u);
  v4 = v2 & 0xF;
  while ( *v1 << 28 )
  {
    mmio_status_write();
    v5 = (*(volatile uint32_t *)0x40501010u) - v3;
    if ( v5 > 0x7530 )
      check_interrupt_flag(4, aIdleErr);
  }
  v6 = *(volatile uint32_t *)off_118FB4;
  v7 = *(volatile uint32_t *)off_118FB8;
  if ( v4 )
  {
    while ( (v7 & v6 & 4) == 0 )
    {
      v6 = *(volatile uint32_t *)off_118FB4;
      v7 = *(volatile uint32_t *)off_118FB8;
    }
  }
  v8 = *((volatile uint8_t *)off_118FBC + 90);
  *(volatile uint32_t *)off_118FC0 = 4;
  if ( v8 )
    critical_section_enter_1();
  result = flash_erase_sector(0, 3);
  v10 = *v0;
  *(volatile uint16_t *)(off_118FC4 + 0x10) = 0;
  if ( v10 )
  {
    v11 = v10 - 1;
    v12 = *(volatile uint32_t *)off_118FA8;
    *v0 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}


// memory_allocate @ 0x118fd8
int memory_allocate(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v6; // r4
  int v8; // r8
  int v9; // r9
  int v10; // r3
  volatile uint8_t *v11; // r8

  v6 = btcoex_update_bt_info((volatile int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(volatile uint8_t *)(a1 + 25);
  v9 = dword_11904C + 152 * (uint8_t)*a2;
  *(volatile uint8_t *)(v9 + 125) = 0;
  *(volatile uint16_t *)(v9 + 126) = 0;
  *a3 = update_rx_credits((uint8_t)*a2, v8);
  v10 = *(volatile uint32_t *)(v9 + 44);
  if ( v10 )
    update_rx_credits(*(volatile uint8_t *)(v10 + 33), *(volatile uint8_t *)(a1 + 25));
  v11 = (volatile uint8_t *)(dword_119050 + 224 * v8);
  if ( v11[94] )
    return v6;
  v11[102] = *a2;
  v11[103] = *(volatile uint8_t *)(a1 + 29);
  v11[104] = *(volatile uint8_t *)(a1 + 30);
  return 0;
}



// rf_channel_calibrate @ 0x119054
int rf_channel_calibrate(int a1) {
  int v1; // r7
  int v2; // r9
  int v4; // r5
  int v5; // r4
  int v6; // r8
  int v7; // r10
  int v8; // r3
  int v9; // r1
  int v10; // r9
  volatile uint32_t *v11; // r1
  volatile char *v12; // r0
  volatile uint32_t *v13; // r5
  volatile uint32_t *v14; // r4
  volatile int *v15; // r1
  volatile int *v16; // r2
  int v17; // r1
  volatile char *v18; // r4
  volatile uint32_t *v19; // r5
  uint8_t v20; // r0
  volatile uint32_t *v21; // r1
  volatile uint32_t *v22; // r1

  v1 = dword_119158;
  v2 = *(volatile uint8_t *)(dword_119158 + 152 * a1 + 32);
  v4 = dword_119158 + 152 * a1;
  v5 = dword_119158 + 8 * (19 * (int16_t)a1 + 11);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6++;
    if ( *(volatile uint32_t *)(v4 + 56) )
      wlan_hw_init(v7, v5 - 32);
    v8 = *(volatile uint32_t *)(v4 + 88);
    v9 = v5;
    v4 += 8;
    v5 += 8;
    if ( v8 )
      wlan_hw_init(v7, v9);
  }
  while ( v6 != 4 );
  v10 = dword_11915C + 224 * v2;
  if ( *(volatile uint8_t *)(v10 + 94) )
  {
    if ( *(volatile uint8_t *)(v10 + 94) == 2 )
      return rf_calibration_table_get(a1);
  }
  else
  {
    *(volatile uint8_t *)(v10 + 102) = -1;
  }
  v11 = (void *)(uintptr_t)(off_119160);
  v12 = (volatile char *)off_119164;
  v13 = (void *)(uintptr_t)(off_119168);
  v14 = (void *)(uintptr_t)(off_11916C);
  *(volatile uint32_t *)off_119164 = -1;
  *v11 = -1;
  *v13 = 0;
  v15 = (void *)(v11 + 1);
  *v14 = 0;
  *(volatile int *)((volatile char *)v15 + 0xFFFFFFF0) = 0;
  *(volatile uint32_t *)&v12[-4] = 0;
  v16 = v15;
  *v15 = ((uint8_t)(a1 + 16) << 16) | 0x40000000;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  v17 = *(volatile uint32_t *)(v1 + 152 * a1 + 44);
  if ( v17 )
  {
    v18 = (volatile char *)off_119164;
    v19 = (void *)(uintptr_t)(off_119160);
    v20 = *(volatile uint8_t *)(v17 + 33) + 16;
    *(volatile uint32_t *)off_119164 = -1;
    *v19 = -1;
    v21 = (void *)(uintptr_t)(off_11916C);
    *(volatile uint32_t *)&v18[-16] = 0;
    *v21 = 0;
    *(volatile uint32_t *)((volatile char *)v19 + 0xFFFFFFF4) = 0;
    v22 = v21 + 5;
    *(volatile uint32_t *)&v18[-4] = 0;
    *v16 = (v20 << 16) | 0x40000000;
    while ( (*v22 & 0x40000000) != 0 )
      ;
  }
  return rf_calibration_table_get(a1);
}



// kernel_send_evt @ 0x119170
int kernel_send_evt(int a1) {
  volatile uint8_t *v2; // r0

  v2 = (volatile uint8_t *)ke_msg_send_1(67, 4, 0, 1);
  *v2 = *(volatile uint8_t *)(a1 + 95);
  return (int)(uintptr_t)(rx_irq_handler_1((int)(uintptr_t)(v2)));
}



// rf_agc_control @ 0x119190
int rf_agc_control(int result, int a2, int a3) {
  int v3; // r4

  v3 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(volatile uint8_t *)(result + 116) = 0;
  }
  else
  {
    check_interrupt_flag(1024, aBcnLinkloss, a3, a2 << 8);
    return (int)kernel_send_evt(v3);
  }
  return result;
}


// rf_temp_compensate @ 0x1191b8
int rf_temp_compensate(volatile uint8_t *a1, int a2) {
  int v2; // r3
  int result; // r0
  char v5; // r2
  int v6; // r6
  char v7; // r5
  volatile uint8_t *v8; // r0

  v2 = (char)a1[118];
  result = (char)a1[117];
  v5 = a1[119];
  v6 = (uint8_t)a1[120];
  a1[117] = a2;
  if ( v2 )
  {
    v7 = a2;
    if ( v6 )
    {
      if ( v6 != 1 || result >= a2 || a2 <= v2 + v5 )
        goto LABEL_7;
      v6 = (v6 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
    }
    else
    {
      if ( result <= a2 || a2 >= v2 - v5 )
        goto LABEL_7;
      v6 = (v6 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    }
    v8 = (volatile uint8_t *)ke_msg_send_1(87, 4, 0, 3);
    *v8 = a1[95];
    v8[1] = v6;
    v8[2] = v7;
    result = (int)(uintptr_t)(rx_irq_handler_1((int)(uintptr_t)(v8)));
LABEL_7:
    a1[120] = v6;
  }
  return result;
}



// timer_start_capture @ 0x119218
BOOL timer_start_capture(int a1, int a2, int a3, volatile int *a4) {
  int v5; // r10
  volatile uint32_t *v6; // r4
  int v7; // r8
  int v8; // r1
  int v9; // r6
  int v10; // r0
  int v11; // r7
  int v13; // r0
  volatile int *v14; // r6
  volatile uint8_t *v15; // r1
  int v16; // r7
  unsigned int v17; // r5
  int v18; // r11
  volatile uint8_t *v19; // r4
  int v21; // [sp+Ch] [bp-10h]
  int v23; // [sp+14h] [bp-8h]
  int v24; // [sp+14h] [bp-8h]

  v5 = *(volatile uint16_t *)(a1 + 28);
  v6 = (void *)(uintptr_t)(off_119300);
  v7 = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 8) + 8);
  v8 = dword_119304;
  v9 = a1;
  v11 = *(volatile uint32_t *)(a2 + 112);
  v10 = *(volatile uint32_t *)(a2 + 108);
  *(volatile uint8_t *)(a2 + 116) = 0;
  v21 = v11;
  if ( v8 - v6[4] + v10 < 0 && !rate_index_lookup_fast(*(volatile uint8_t *)(a2 + 102), 0, 0) )
    *(volatile uint32_t *)(a2 + 108) = v6[4];
  v23 = *(volatile char *)(v9 + 45);
  chip_info_nibble0_get();
  rf_temp_compensate((volatile uint8_t *)a2, v23);
  v13 = crc32_update_msb((void *)(uintptr_t)(v7 + 32), 4, 0);
  *a4 = 0;
  if ( (uint16_t)(v5 - 36) > 1u )
  {
    v24 = v9;
    v14 = a4;
    v15 = (volatile uint8_t *)(v7 + 36);
    v16 = a2;
    v17 = (uint16_t)(v5 - 36);
    do
    {
      v18 = (uint8_t)v15[1];
      v19 = v15 + 2;
      if ( v18 + 1 >= (int)v17 )
        break;
      if ( *v15 == 5 )
        *v14 = (int)v15;
      else
        v13 = crc32_update_msb(v19, (uint8_t)v15[1], v13);
      v17 = (uint16_t)(v17 + -2 - v18);
      v15 = &v19[v18];
    }
    while ( v17 > 1 );
    a2 = v16;
    a4 = v14;
    v9 = v24;
  }
  *(volatile uint32_t *)(a2 + 112) = v13;
  send_acl_packet(v7, v5, v9, (volatile uint32_t *)a2, a3, *a4);
  return *(volatile uint32_t *)(a2 + 112) != v21;
}



// return_zero @ 0x119308
int return_zero() {
  return 0;
}



// kernel_send_msg @ 0x11930c
int kernel_send_msg(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)ke_msg_send_1(11, a4, a3, 3);
  *v5 = memory_allocate(a2, v5 + 1, v5 + 2);
  return 0;
}



// rx_process_packet @ 0x119330
int rx_process_packet(int a1, int a2, int a3, int a4) {
  int v4; // r6
  int v6; // r7
  int v9; // r8
  int v10; // r4
  char v11; // r1
  int v12; // r2
  int v13; // r3

  v4 = dword_1193D0;
  v6 = *(volatile uint8_t *)(a2 + 5);
  if ( **(volatile int16_t **)off_1193CC < 0 )
  {
    v9 = 8 * v6;
    if ( *(volatile uint8_t *)(dword_1193D0 + 224 * v6 + 94) )
      flash_ctrl_init((int)aVifTypeVifSta, (int)aMmSetArpoffloa, 2660);
  }
  else
  {
    v9 = 8 * v6;
  }
  v10 = v4 + 32 * (v9 - v6);
  v11 = *(volatile uint8_t *)(a2 + 4);
  v12 = *(volatile uint8_t *)(v10 + 121);
  v13 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(v10 + 144) = *(volatile uint32_t *)a2;
  *(volatile uint8_t *)(v10 + 140) = v11;
  if ( v12 == 1 )
  {
    ke_exit_critical((int)(uintptr_t)((volatile uint32_t *)(v4 + 224 * v6 + 124)));
    v13 = *(volatile uint32_t *)(v10 + 144);
    *(volatile uint8_t *)(v10 + 121) = 0;
  }
  check_interrupt_flag(256, "DHCPed:%d,%x.\r\n", *(volatile uint8_t *)(v4 + 32 * (v9 - v6) + 140), v13);
  ke_evt_handler(98, a4, a3);
  return 0;
}


// send_event_0x66 @ 0x1193e0
int send_event_0x66(int a1, int a2, int a3, int a4) {
  ke_evt_handler(102, a4, a3);
  return 0;
}



// send_event_0x68 @ 0x1193f0
int send_event_0x68(int a1, int a2, int a3, int a4) {
  ke_evt_handler(104, a4, a3);
  return 0;
}



// trace_record_event @ 0x119400
int trace_record_event(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_11941C;
  v7 = a2[1];
  v5 = (void *)(uintptr_t)(((uintptr_t)(v5) & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)dword_11941C = v4;
  *(volatile uint32_t *)(v6 + 4) = v7;
  *(volatile uint16_t *)(v6 + 8) = (uint16_t)v5;
  ke_evt_handler(138, a4, a3);
  return 0;
}



// event_dispatch @ 0x119420
int event_dispatch(int a1, volatile int *a2, int a3, int a4) {
  volatile char *v7; // r7
  volatile uint32_t *v8; // r3
  int v9; // r6
  int v10; // r4
  int v11; // r12
  int v12; // r5
  int v13; // r6

  if ( *(volatile uint8_t *)a2 )
  {
    v7 = (volatile char *)off_119470;
    if ( (*((volatile uint8_t *)off_11946C + 1) & 1) == 0 || (*((volatile uint32_t *)off_119470 + 98) & 1) != 0 )
    {
      v8 = (void *)(uintptr_t)(off_119474);
      v9 = *a2;
      v10 = a2[2];
      v11 = a2[3];
      *((volatile uint32_t *)off_119474 + 1) = a2[1];
      *(volatile uint32_t *)(v7 + 266) = v9;
      v12 = a2[5];
      v13 = a2[4];
      v8[2] = v10;
      v8[6] = a2[6];
      v8[3] = v11;
      v8[4] = v13;
      v8[5] = v12;
    }
  }
  ke_evt_handler(122, a4, a3);
  return 0;
}



// rx_packet_check @ 0x119478
int rx_packet_check(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r4
  int v6; // r8
  int v9; // r7
  volatile uint8_t *v10; // r4

  v4 = dword_1194E8;
  v6 = *a2;
  if ( **(volatile int16_t **)off_1194E4 < 0 )
  {
    v9 = 8 * v6;
    if ( *(volatile uint8_t *)(dword_1194E8 + 224 * v6 + 94) )
      flash_ctrl_init(dword_1194F0, dword_1194EC, 3702);
  }
  else
  {
    v9 = 8 * v6;
  }
  v10 = (volatile uint8_t *)(v4 + 32 * (v9 - v6));
  v10[118] = a2[1];
  v10[119] = a2[2];
  v10[120] = 0;
  ke_evt_handler(134, a4, a3);
  return 0;
}



// send_event_0x70 @ 0x1194f4
/* luna: Thin wrapper that sends kernel event 0x70 with the supplied event arguments. */
int send_event_0x70(int a1, int a2, int a3, int a4) {
  ke_evt_handler(112, a4, a3);
  return 0;
}



// send_event_0x72 @ 0x119504
int send_event_0x72(int a1, int a2, int a3, int a4) {
  ke_evt_handler(114, a4, a3);
  return 0;
}



// ke_send_msg_0x6e @ 0x119514
int ke_send_msg_0x6e(int a1, int a2, int a3, int a4) {
  ke_evt_handler(110, a4, a3);
  return 0;
}



// alloc_hci_rx_buffer @ 0x119524
int alloc_hci_rx_buffer(int a1, int a2, int a3, int a4) {
  check_interrupt_flag(256, aSetMuEdca);
  ke_evt_handler(108, a4, a3);
  return 0;
}


