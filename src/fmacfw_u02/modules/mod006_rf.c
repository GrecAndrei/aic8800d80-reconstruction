// mmio_rmw32 @ 0x10ee2c
int mmio_rmw32(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r5
  volatile uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10EE74 = 1;
  }
  v4 = (volatile int *)off_10EE78;
  ++*(volatile uint32_t *)off_10EE78;
  if ( a4 )
  {
    v5 = (void *)(uintptr_t)(off_10EE7C);
    while ( !*(volatile uint32_t *)off_10EE7C )
      ;
    result = call_ptr_1b8();
    *v5 = 1;
  }
  else
  {
    result = call_ptr_1b8();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(volatile uint32_t *)off_10EE74;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}



// rf_set_channel_1 @ 0x10ee80
int rf_set_channel_1(int a1) {
  event_dispatch("Reboot:%x\n", a1);
  mmio_rmw32(dword_10EECC, 196608, dword_10EEC8, 1);
  mmio_rmw32(1879048192, 1, 1, 1);
  mmio_write32(dword_10EED0, a1, 1);
  return mmio_rmw32(dword_10EED4, 2, 2, 1);
}


// rf_set_frequency @ 0x10eed8
int rf_set_frequency(int a1) {
  mmio_rmw32(dword_10EF0C, 196608, dword_10EF08, 1);
  mmio_write32(dword_10EF10, a1 << 15, 1);
  return mmio_rmw32(1879048192, 1, 1, 1);
}



// mmio_write_70001408 @ 0x10ef14
int mmio_write_70001408() {
  return mmio_rmw32(dword_10EF20, 0, 2, 1);
}



// rf_get_rssi @ 0x10ef24
/* luna: Reads the RSSI field from an MMIO register and returns bits 11–15 of its low 16 bits. */
int rf_get_rssi() {
  return (uint16_t)mmio_read32(dword_10EF34, 1) >> 11;
}



// rf_get_state @ 0x10ef38
int rf_get_state(int a1) {
  return mmio_rmw32(dword_10EF4C, (a1 << 11) & 0xF800, 63488, 1);
}



// rf_enable_1 @ 0x10ef50
int rf_enable_1() {
  int result; // r0

  mmio_rmw32(1879048192, 256, 264, 1);
  mmio_rmw32(dword_10F100, 0x8000000, 0x8000000, 1);
  mmio_rmw32(dword_10F104, 21, 31, 1);
  mmio_rmw32(dword_10F110, dword_10F10C, dword_10F108, 1);
  mmio_rmw32(dword_10F114, 2560, 2560, 1);
  mmio_rmw32(dword_10F118, 255, 255, 1);
  mmio_rmw32(dword_10F11C, 0, 100663296, 1);
  mmio_rmw32(dword_10F120, 0, 983040, 1);
  mmio_rmw32(dword_10F124, 96, 96, 1);
  mmio_rmw32(dword_10F128, 256, 256, 1);
  mmio_rmw32(dword_10F12C, 469762048, 469762048, 1);
  mmio_rmw32(dword_10F130, 104, 252, 1);
  mmio_rmw32(dword_10F134, 6, 6, 1);
  mmio_rmw32(dword_10F138, 320, 992, 1);
  mmio_rmw32(dword_10F144, dword_10F140, dword_10F13C, 1);
  mmio_rmw32(dword_10F148, 0x400000, 15728640, 1);
  mmio_rmw32(dword_10F14C, 16, 63, 1);
  mmio_rmw32(dword_10F150, 0, 60, 1);
  mmio_rmw32(dword_10F154, 0, 256, 1);
  mmio_rmw32(dword_10F158, 2048, 16128, 1);
  result = mmio_rmw32(dword_10F15C, 1, 1, 1);
  if ( **(volatile uint8_t **)off_10F160 == 1 )
  {
    mmio_write32(dword_10F168, dword_10F164, 1);
    mmio_write32(dword_10F170, dword_10F16C, 1);
    mmio_rmw32(dword_10F15C, 0x100000, 0x100000, 1);
    result = mmio_rmw32(dword_10F174, 2, 31, 1);
    if ( !*((volatile uint8_t *)off_10F178 + 375) )
    {
      mmio_rmw32(dword_10F17C, 1, 1, 1);
      mmio_rmw32(dword_10F154, 256, 256, 1);
      mmio_rmw32(dword_10F158, 0x2000, 16128, 1);
      mmio_rmw32(dword_10F11C, 2359296, 16515072, 1);
      return mmio_rmw32(dword_10F15C, 256, 256, 1);
    }
  }
  return result;
}



// rf_save_rssi @ 0x10f180
unsigned int rf_save_rssi() {
  unsigned int result; // r0

  result = write_phy_config(0xC2u);
  *((volatile uint8_t *)off_10F194 + 7) = -62;
  return result;
}



// rf_update_rx_status @ 0x10f198
int rf_update_rx_status() {
  volatile uint8_t *v0; // r6
  int v1; // r5
  int v2; // r4
  int result; // r0
  volatile unsigned int v4; // r3

  v0 = (void *)(uintptr_t)(off_10F1F8);
  v1 = (char)(*((volatile uint8_t *)off_10F1F8 + 5) + (*(volatile uint8_t *)off_10F1F4 & 3));
  v2 = *((volatile char *)off_10F1F8 + 7) - v1;
  if ( v2 < -62 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(-62) & 0xFFu);
  write_phy_config(v2);
  v0[7] = v2;
  result = event_dispatch("update# =%d %d\r\n", (char)v2, v1);
  if ( (char)v2 < -61 )
  {
    v0[11] = 0;
  }
  else
  {
    v4 = (*(volatile uint32_t *)0x40501010u);
    return unknown_worker((volatile uint32_t *)v0 + 3, v4 + 30000 * *((volatile uint16_t *)v0 + 4));
  }
  return result;
}


// rf_copy_stats @ 0x10f204
int rf_copy_stats() {
  int v0; // r2
  uint64_t v1; // kr00_8
  volatile char *v2; // r3
  uint64_t v3; // r0
  int v4; // r4
  int v5; // r2
  uint64_t v6; // kr10_8

  v0 = *(volatile uint32_t *)off_10F250;
  v1 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10F250 + 24);
  v2 = (volatile char *)off_10F254;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(*(volatile uint32_t *)off_10F250 + 36)) & 0xFFFFFFFFu);
  v4 = *(volatile uint32_t *)(*(volatile uint32_t *)off_10F250 + 32);
  *(volatile uint32_t *)off_10F254 = v1;
  v6 = *(volatile uint64_t *)(v0 + 40);
  v5 = *(volatile uint32_t *)(v0 + 44);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v6) << 32);
  *((volatile uint32_t *)v2 + 1) = HIDWORD(v1);
  *((volatile uint32_t *)v2 + 2) = v4;
  *(volatile uint64_t *)(v2 + 12) = v3;
  *((volatile uint32_t *)v2 + 5) = v5;
  init_radio_hw();
  dispatch_interrupt();
  install_isr();
  if ( **(volatile uint8_t **)off_10F258 == 3 )
    zero_buffer_range();
  return (int)(uintptr_t)(clear_global_182aac());
}


// bt_get_state @ 0x10f25c
int bt_get_state() {
  volatile uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((volatile uint8_t *)off_10F290 + 362) )
  {
    *(volatile uint8_t *)off_10F294 = 0;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_10F294);
    *(volatile uint32_t *)off_10F294 = dword_10F298;
    v2 = dword_10F29C;
    v3 = (void *)(uintptr_t)(off_10F2A0);
    v0[7] = -62;
    *((volatile uint32_t *)v0 + 2) = 1000;
    *((volatile uint16_t *)v0 + 2) = 1752;
    *((volatile uint32_t *)v0 + 4) = v2;
    *((volatile uint32_t *)v0 + 8) = (int)(uintptr_t)(v3);
    return 1752;
  }
  return result;
}



// ipc_send_message @ 0x10f370
int ipc_send_message(int a1, int a2) {
  is_controller_mode((void *)(uintptr_t)(a2));
  return 1;
}



// tx_send_packet @ 0x10f37c
int tx_send_packet() {
  volatile uint8_t *v0; // r4
  volatile char *v1; // r0

  v0 = (void *)(uintptr_t)(off_10F3AC);
  v1 = (volatile char *)off_10F3AC + 1624;
  *((volatile uint16_t *)off_10F3AC + 810) = 80;
  v0[1622] = 81;
  zero_8_bytes((void *)(v1));
  *((volatile uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return (int)(uintptr_t)(zero_8_bytes((void *)(v0 + 2436)));
}



// rf_timer_init @ 0x10f3b0
uint64_t rf_timer_init() {
  volatile uint16_t *v0; // r5
  volatile int *v1; // r4
  volatile int *v2; // r5
  int v3; // r6
  volatile int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  volatile uint32_t *v7; // r3

  v0 = (void *)(uintptr_t)(off_10F44C);
  v1 = (volatile int *)dword_10F450;
  *((volatile uint16_t *)off_10F44C + 3080) = -16193;
  v0[1536] = -16193;
  *((volatile uint8_t *)v0 + 6162) = 0;
  *((volatile uint32_t *)v0 + 1541) = 0;
  *((volatile uint8_t *)v0 + 6176) = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  zero_8_bytes((volatile uint32_t *)v0 + 770);
  zero_8_bytes((void *)(v1 - 3));
  zero_8_bytes((void *)(v1 + 512));
  zero_8_bytes((void *)(v1 + 514));
  v0[4122] = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  memset(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = (int)(v1 + 512);
  do
  {
    v4 = v1;
    v1 += 4;
    co_list_push_back(v3, (void *)(v4));
  }
  while ( v1 != v2 );
  v5 = dword_10F454;
  result = (unsigned int)(dword_10F454 + 1152);
  do
  {
    v7 = (volatile uint32_t *)(v5 - 36);
    do
      *v7++ = 0;
    while ( v7 != (volatile uint32_t *)v5 );
    v5 = (int)(v7 + 9);
  }
  while ( v7 + 9 != (volatile uint32_t *)result );
  return result;
}


// rf_wait_ready @ 0x10f458
int rf_wait_ready() {
  volatile uint8_t **v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r3
  int v3; // r2
  uint64_t v4; // r0
  int v5; // r3
  volatile uint32_t *v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r3
  void *v9; // r2
  int ( **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int ( **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int ( **v17)(int); // r5
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (volatile uint8_t **)off_10F518;
  v1 = **(volatile uint8_t **)off_10F518;
  switch ( v1 )
  {
    case 1:
      v8 = (void *)(uintptr_t)(off_10F51C);
      v9 = (void *)(uintptr_t)(off_10F534);
      *((volatile uint32_t *)off_10F51C + 2) = dword_10F530;
      v8[3] = (int)(uintptr_t)(v9);
      break;
    case 2:
      v2 = (void *)(uintptr_t)(off_10F51C);
      v3 = dword_10F524;
      *((volatile uint32_t *)off_10F51C + 6) = dword_10F520;
      v2[7] = v3;
      break;
    case 3:
      v6 = (void *)(uintptr_t)(off_10F51C);
      v7 = dword_10F52C;
      *((volatile uint32_t *)off_10F51C + 8) = dword_10F528;
      v6[9] = v7;
      break;
  }
  tx_send_packet();
  v4 = rf_timer_init();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F51C;
    *(volatile uint32_t *)off_10F538 = dword_10F54C;
    v18 = (int)(uintptr_t)(get_link_rate(v4, HIDWORD(v4)));
    v19 = (int)(uintptr_t)(get_modulation_type(v18));
    v20 = (int)(uintptr_t)(get_link_tx_power(v19));
    get_link_channel(v20);
    v21 = v17[2](dword_10F540);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v17[3](v21)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F548;
    *(volatile uint32_t *)off_10F538 = dword_10F544;
    v13 = (int ( **)(int))off_10F51C;
    *(volatile uint16_t *)(v12 + 8244) = 0;
    v14 = (int)(uintptr_t)(ke_state_get_fast());
    usb_wlan_rx_pkt_free_list_init(v14);
    v15 = v13[6](dword_10F540);
    v16 = v13[7](v15);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(store_byte_field(v16)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F51C;
    *(volatile uint32_t *)off_10F538 = dword_10F53C;
    process_task_queue();
    v11 = v10[8](dword_10F540);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v10[9](v11)) & 0xFFFFFFFFu);
  }
  return v4;
}



// os_task_init @ 0x10f550
int os_task_init() {
  int result; // r0
  volatile int *v1; // r9
  volatile uint32_t *v2; // r0
  int v3; // r2
  volatile int *v4; // r3
  int v5; // r3
  int v6; // r11
  volatile int16_t **v7; // r6
  int v8; // r5
  int v9; // r8
  int v10; // r7
  volatile uint32_t *v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r10
  volatile uint8_t *v17; // r3
  volatile uint32_t *v18; // r8
  int v19; // r2
  int v20; // r1
  volatile uint32_t *v21; // r0
  int v22; // r3
  int v23; // r2
  volatile uint32_t *v24; // r0
  int v25; // [sp+0h] [bp-Ch]
  int v26; // [sp+0h] [bp-Ch]
  int a1; // [sp+4h] [bp-8h]

  result = unknown_func_12d14c(512);
  a1 = *((volatile uint32_t *)off_10F834 + 2);
  if ( !a1 )
    return result;
  v1 = (volatile int *)off_10F860;
  while ( 2 )
  {
    result = isr_flag_dispatch(a1);
    if ( !result && *(volatile uint8_t *)(a1 + 108) )
      goto LABEL_4;
    for ( ; *(volatile uint32_t *)(a1 + 1312); result = ll_conn_state_dispatch((unsigned int)v2, 3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_10F838 = 1;
      }
      ++*v1;
      v2 = mem_word_load(a1 + 1312);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (volatile int *)off_10F838;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((volatile uint8_t *)off_10F83C + 511) )
      goto LABEL_4;
    v6 = a1;
    v7 = (volatile int16_t **)off_10F840;
    v8 = dword_10F844;
    v9 = 4;
    if ( *(volatile uint32_t *)(a1 + 1304) )
    {
LABEL_16:
      v10 = (uint8_t)v9;
      v25 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v11 = mem_word_load(v6 + 1304);
          v12 = *((volatile uint8_t *)v11 + 29);
          v13 = (unsigned int)v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            mmio_clear_register((int)aTxdescTmpHostS, (int)aReplenishSend, 374);
            v12 = *(volatile uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( *(volatile uint8_t *)(v14 + 37) || (*(volatile uint16_t *)(v13 + 30) & 8) != 0 )
            break;
          event_dispatch("sta invalid:%d\n", *(volatile uint8_t *)(v14 + 35));
          ll_conn_event_prepare(v13, v10, 0x80000000);
          if ( !*(volatile uint32_t *)(v6 + 1304) )
          {
LABEL_25:
            v9 = v25;
            goto LABEL_26;
          }
        }
        if ( *(volatile uint8_t *)(v8 + 696 * v12 + 36) != 1 )
        {
          ll_conn_state_dispatch(v13, v10);
          goto LABEL_24;
        }
        if ( **v7 < 0 )
        {
          if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          {
LABEL_56:
            co_list_push_back(v8 + 8 * (87 * (int16_t)v12 + v25 + 78), (volatile uint32_t *)v13);
            goto LABEL_23;
          }
          mmio_clear_register((int)aTxdescTmpHostF, (int)aReplenishSend, 383);
        }
        if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          goto LABEL_56;
LABEL_23:
        event_dispatch("push rt sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v12 + 35));
LABEL_24:
        if ( !*(volatile uint32_t *)(v6 + 1304) )
          goto LABEL_25;
      }
    }
    while ( 2 )
    {
      v10 = (uint8_t)v9;
LABEL_26:
      v15 = *(volatile uint32_t *)(v6 + 1264);
      if ( !v15 )
        goto LABEL_39;
      v26 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = *(volatile uint8_t *)(v15 + 29);
          v17 = (volatile uint8_t *)(v8 + 696 * v16);
          if ( v17[37] )
            break;
          event_dispatch("sta invalid:%d\n", v17[35]);
          v24 = mem_word_load(v6 + 1264);
          ll_conn_event_prepare((int)v24, v10, 0x80000000);
          v15 = *(volatile uint32_t *)(v6 + 1264);
          if ( !v15 )
          {
LABEL_38:
            v9 = v26;
            goto LABEL_39;
          }
        }
        if ( v17[36] != 1 )
          break;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_10F838 = 1;
        }
        ++*v1;
        v18 = mem_word_load(v6 + 1264);
        event_dispatch("push sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v16 + 35));
        if ( *v1 )
        {
          v19 = *v1 - 1;
          v20 = *(volatile uint32_t *)off_10F838;
          *v1 = v19;
          if ( !v19 )
          {
            if ( v20 )
              __enable_irq();
          }
        }
        co_list_push_back(v8 + 8 * (87 * (int16_t)v16 + v26 + 73), v18);
LABEL_37:
        v15 = *(volatile uint32_t *)(v6 + 1264);
        if ( !v15 )
          goto LABEL_38;
      }
      if ( lookup_interface_info(v16, *(volatile uint8_t *)(v15 + 27)) )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_10F838 = 1;
        }
        ++*v1;
        v21 = mem_word_load(v6 + 1264);
        if ( *v1 )
        {
          v22 = *v1 - 1;
          v23 = *(volatile uint32_t *)off_10F838;
          *v1 = v22;
          if ( !v22 )
          {
            if ( v23 )
              __enable_irq();
          }
        }
        ll_conn_state_dispatch((unsigned int)v21, v10);
        goto LABEL_37;
      }
      v9 = v26;
      *((volatile uint8_t *)off_10F83C + 512) = 1;
LABEL_39:
      --v9;
      result = test_flag(v10);
      v6 -= 8;
      if ( v9 != -1 )
      {
        if ( *(volatile uint32_t *)(v6 + 1304) )
          goto LABEL_16;
        continue;
      }
      break;
    }
LABEL_4:
    a1 = *(volatile uint32_t *)a1;
    if ( a1 )
      continue;
    return result;
  }
}


// sys_command_40d @ 0x10f90c
int sys_command_40d() {
  int v0; // r0

  v0 = ke_msg_alloc(1037, 1, 13, 8);
  return (int)(uintptr_t)(ke_msg_send_2(v0));
}



// hci_handle_command @ 0x10f924
unsigned int hci_handle_command(volatile int *a1, int a2, unsigned int a3) {
  unsigned int result; // r0
  unsigned int v6; // r2
  unsigned int v7; // r3
  volatile int *v8; // r8
  volatile uint32_t *v9; // r9
  int v10; // r7
  volatile int *v11; // r11
  int v12; // r4
  unsigned int v13; // r5
  int v14; // r6
  volatile uint32_t *v15; // r5
  volatile uint32_t *v16; // r10
  int v17; // r3
  int v18; // r3
  int v19; // r3
  volatile uint32_t *v20; // r7
  int v21; // r5
  unsigned int v22; // r3
  unsigned int v23; // r2
  unsigned int v24; // r3
  int v25; // [sp+0h] [bp-24h]
  int v26; // [sp+4h] [bp-20h]
  unsigned int v27; // [sp+8h] [bp-1Ch]
  unsigned int v28; // [sp+Ch] [bp-18h]
  char v29; // [sp+10h] [bp-14h]

  result = *a1;
  v28 = result;
  if ( a3 )
  {
    v6 = result % a3;
    v7 = a3;
    if ( v6 )
    {
      v7 = a3 - v6;
      if ( a3 - v6 <= 3 )
        v7 += a3;
    }
    v28 = result + v7 - 4;
  }
  if ( !*((volatile uint8_t *)a1 + 8) )
    return result;
  v8 = (volatile int *)off_10FB20;
  v9 = (void *)(uintptr_t)(off_10FB24);
  v25 = 0;
  v10 = 0;
  v11 = a1;
  while ( 2 )
  {
    result = *(volatile uint16_t *)(a2 + 4 * v10);
    v12 = 0;
    v13 = *(volatile uint16_t *)(a2 + 4 * v10 + 2);
    v14 = v11[3] + 12 * v10;
    *(volatile uint32_t *)v14 = 0;
    *(volatile uint16_t *)(v14 + 4) = 0;
    if ( !v13 )
      goto LABEL_6;
    v26 = result + 4;
    *(volatile uint16_t *)(v14 + 2) = v13;
    v27 = v13;
    *(volatile uint16_t *)(v14 + 4) = result;
    v15 = (volatile uint32_t *)(v28 + 4);
    v16 = nullptr;
    v29 = v10;
    do
    {
      v20 = v16;
      v16 = v15;
      if ( *v8 <= (unsigned int)v15 && *v8 + v8[1] >= (unsigned int)v15
        || *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
        *((volatile uint8_t *)v15 - 4) = v29;
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      else
      {
        log_printf("set_native_pool_id: Invalid buffer passed: %x\n", v15);
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      if ( v17 + v8[1] >= (unsigned int)v15 )
        goto LABEL_12;
LABEL_22:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_12:
        *((volatile uint8_t *)v15 - 3) = 85;
        v18 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_25;
        goto LABEL_13;
      }
      log_printf("set_pattern: Invalid buffer passed: %x\n", v15);
      v18 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_25;
LABEL_13:
      if ( v18 + v8[1] >= (unsigned int)v15 )
        goto LABEL_14;
LABEL_25:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_14:
        *((volatile uint8_t *)v15 - 2) = 0;
        v19 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_28;
        goto LABEL_15;
      }
      log_printf("set_num_users: Invalid buffer passed: %x\n", v15);
      v19 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_28;
LABEL_15:
      if ( v19 + v8[1] >= (unsigned int)v15 )
        goto LABEL_16;
LABEL_28:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_16:
        *v15 = (int)(uintptr_t)(v20);
        goto LABEL_17;
      }
      log_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", v15);
LABEL_17:
      ++v12;
      ++*(volatile uint16_t *)v14;
      v15 = (volatile uint32_t *)((volatile char *)v15 + v26);
    }
    while ( v27 > (uint16_t)v12 );
    v21 = (uint16_t)(v27 - 1);
    v22 = v28 + v21 * v26;
    result = v28 + v26 + v21 * v26;
    v28 = result;
    *(volatile uint32_t *)(v14 + 8) = v22 + 4;
    if ( a3 )
    {
      v23 = result % a3;
      v24 = a3;
      if ( result % a3 )
      {
        v24 = a3 - v23;
        if ( a3 - v23 <= 3 )
          v24 += a3;
      }
      v28 = result + v24 - 4;
    }
LABEL_6:
    v10 = (uint8_t)++v25;
    if ( *((volatile uint8_t *)v11 + 8) > (unsigned int)(uint8_t)v25 )
      continue;
    return result;
  }
}


// buffer_pool_alloc @ 0x10fb28
volatile uint32_t * buffer_pool_alloc(int a1, unsigned int a2) {
  unsigned int v2; // r6
  volatile uint32_t *v3; // r5
  volatile uint16_t *v4; // r4
  unsigned int v5; // r3
  volatile int *v6; // r6
  int v7; // r3
  int v8; // r2
  volatile unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r2
  uint16_t v14; // r3
  int v15; // cc
  unsigned int v16; // r3
  volatile int *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r2

  v2 = *(volatile uint8_t *)(a1 + 8);
  if ( !*(volatile uint8_t *)(a1 + 8) )
  {
LABEL_57:
    log_printf("SwEr:NoSizeAlloc : %d\n\r", a2);
    return nullptr;
  }
  v3 = *(volatile uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    log_printf(aMemmgrerrSubpo, a2);
    return v3;
  }
  v4 = *(volatile uint16_t **)(a1 + 12);
  v5 = 1;
  while ( v4[2] < a2 )
  {
    if ( v2 <= v5 )
      goto LABEL_11;
    v4 = (volatile uint16_t *)&v3[3 * v5];
LABEL_7:
    v5 = (uint8_t)(v5 + 1);
  }
  if ( *v4 )
    goto LABEL_12;
  if ( v2 > v5 )
  {
    v4 = (volatile uint16_t *)&v3[3 * v5];
    goto LABEL_7;
  }
LABEL_11:
  if ( v2 == v5 )
    goto LABEL_57;
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FCB4 = 1;
  }
  v6 = (volatile int *)off_10FCB8;
  v7 = *v4;
  v3 = *(volatile uint32_t **)off_10FCB8;
  v8 = *(volatile uint32_t *)off_10FCB8 + 1;
  *(volatile uint32_t *)off_10FCB8 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (volatile int *)off_10FCB4;
      *v6 = (int)v3;
      v19 = *v18;
      if ( !v3 )
      {
        if ( v19 )
          goto LABEL_43;
      }
    }
    return nullptr;
  }
  v9 = (volatile unsigned int *)off_10FCBC;
  v3 = *((volatile uint32_t **)v4 + 2);
  v10 = *(volatile uint32_t *)off_10FCBC;
  if ( *(volatile uint32_t *)off_10FCBC <= (unsigned int)v3 && (unsigned int)v3 <= *((volatile uint32_t *)off_10FCBC + 1) + v10
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FCC0
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FCC0 + *((volatile uint32_t *)off_10FCC0 + 1) )
  {
    *((volatile uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    log_printf("get_next_buffer_addr: Invalid buffer passed: %x\n", *((volatile uint32_t *)v4 + 2));
    v10 = *v9;
    v14 = *v4 - 1;
    v15 = *v9 > (unsigned int)v3;
    *((volatile uint32_t *)v4 + 2) = 0;
    *v4 = v14;
    if ( !v15 )
    {
LABEL_18:
      if ( v9[1] + v10 >= (unsigned int)v3 )
      {
        v11 = *((volatile uint8_t *)v3 - 3);
        if ( v11 == 85 )
          goto LABEL_20;
        goto LABEL_45;
      }
    }
  }
  v16 = *(volatile uint32_t *)off_10FCC0;
  if ( *(volatile uint32_t *)off_10FCC0 > (unsigned int)v3 || *((volatile uint32_t *)off_10FCC0 + 1) + v16 < (unsigned int)v3 )
  {
    log_printf("get_pattern: Invalid buffer passed: %x\n", v3);
    v11 = 0;
    goto LABEL_45;
  }
  v11 = *((volatile uint8_t *)v3 - 3);
  if ( v11 != 85 )
  {
LABEL_45:
    if ( *v6 )
    {
      v20 = *v6 - 1;
      v21 = *(volatile uint32_t *)off_10FCB4;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    log_printf("SwEr:AllcErrPtrn : %d, buffer: 0x%x\n\r", v11, v3);
    return nullptr;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    log_printf("set_pattern: Invalid buffer passed: %x\n", v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *((volatile uint32_t *)off_10FCC0 + 1) )
      goto LABEL_37;
LABEL_20:
    *((volatile uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FCC0
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FCC0 + *((volatile uint32_t *)off_10FCC0 + 1) )
  {
    *((volatile uint8_t *)v3 - 2) = 1;
  }
  else
  {
    log_printf("set_num_users: Invalid buffer passed: %x\n", v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(volatile uint32_t *)off_10FCB4;
    *v6 = v12;
    if ( !v12 )
    {
      if ( v13 )
LABEL_43:
        __enable_irq();
    }
  }
  return v3;
}


// util_is_nonnull @ 0x10fce0
int util_is_nonnull(int a1, volatile uint32_t *a2) {
  volatile unsigned int *v4; // r7
  unsigned int v5; // r6
  int v6; // r8
  volatile int *v7; // r5
  unsigned int v8; // r0
  int v9; // cf
  int v10; // r9
  int result; // r0
  int v12; // r3
  int v13; // r2
  volatile int *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r6
  volatile uint16_t *v19; // r9
  int v20; // r6
  int16_t v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r2

  if ( !a2 )
    return -1;
  if ( *(volatile uint32_t *)a1 > (unsigned int)a2 || (unsigned int)a2 > *(volatile uint32_t *)a1 + *(volatile uint32_t *)(a1 + 4) )
    return -1;
  if ( (v4 = (volatile unsigned int *)off_10FF0C, (unsigned int)a2 >= *(volatile uint32_t *)off_10FF0C)
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FF0C + *((volatile uint32_t *)off_10FF0C + 1)
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FF18
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FF18 + *((volatile uint32_t *)off_10FF18 + 1) )
  {
    v5 = *((volatile uint8_t *)a2 - 4);
  }
  else
  {
    log_printf("get_native_pool_id: Invalid buffer passed: %x\n", a2);
    v5 = 0;
  }
  if ( *(volatile uint8_t *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(volatile uint32_t *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FF10 = 1;
  }
  v7 = (volatile int *)off_10FF14;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(volatile uint32_t *)off_10FF14;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (volatile int *)off_10FF18;
    v15 = *(volatile uint32_t *)off_10FF18;
    if ( (unsigned int)a2 < *(volatile uint32_t *)off_10FF18 || (unsigned int)a2 > *((volatile uint32_t *)off_10FF18 + 1) + v15 )
    {
      log_printf("get_pattern: Invalid buffer passed: %x\n", a2);
    }
    else
    {
      v10 = *((volatile uint8_t *)a2 - 3);
      if ( v10 == 170 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_37;
        goto LABEL_15;
      }
      if ( v10 == 255 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_36;
        goto LABEL_15;
      }
    }
LABEL_24:
    if ( *v7 )
    {
      v16 = *v7 - 1;
      v17 = *(volatile uint32_t *)off_10FF10;
      *v7 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
    return -1;
  }
  v10 = *((volatile uint8_t *)a2 - 3);
  if ( v10 == 170 )
  {
    result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
    *((volatile uint8_t *)a2 - 2) = result;
    if ( result )
    {
LABEL_17:
      if ( *v7 )
      {
        v12 = *v7 - 1;
        v13 = *(volatile uint32_t *)off_10FF10;
        *v7 = v12;
        if ( !v12 )
        {
          if ( v13 )
            __enable_irq();
        }
      }
      return (char)result;
    }
LABEL_40:
    v18 = 3 * v5;
    v19 = (volatile uint16_t *)(v6 + 4 * v18);
    v20 = 4 * v18;
    if ( *v19 < (unsigned int)v19[1] )
    {
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FF18
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FF18 + *((volatile uint32_t *)off_10FF18 + 1) )
      {
        *((volatile uint8_t *)a2 - 3) = 85;
      }
      else
      {
        log_printf("set_pattern: Invalid buffer passed: %x\n", a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FF18
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FF18 + *((volatile uint32_t *)off_10FF18 + 1) )
      {
        *a2 = *((volatile uint32_t *)v19 + 2);
      }
      else
      {
        log_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", a2);
      }
      v21 = *(volatile uint16_t *)(v6 + v20);
      v22 = *v7;
      *((volatile uint32_t *)v19 + 2) = (int)(uintptr_t)(a2);
      *(volatile uint16_t *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(volatile uint32_t *)off_10FF10;
      *v7 = result;
      if ( result || !v23 )
        return 0;
      __enable_irq();
      return result;
    }
    goto LABEL_24;
  }
  if ( v10 != 255 )
    goto LABEL_24;
LABEL_15:
  if ( (unsigned int)a2 <= v8 + v4[1] )
    goto LABEL_16;
  v14 = (volatile int *)off_10FF18;
LABEL_36:
  v15 = *v14;
  if ( (unsigned int)a2 < *v14 )
  {
LABEL_38:
    log_printf("decr_num_users: Invalid buffer passed: %x\n", a2);
    goto LABEL_39;
  }
LABEL_37:
  if ( (unsigned int)a2 > v15 + v14[1] )
    goto LABEL_38;
LABEL_16:
  result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
  *((volatile uint8_t *)a2 - 2) = result;
  if ( result )
    goto LABEL_17;
LABEL_39:
  if ( v10 != 255 )
    goto LABEL_40;
  if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FF18
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FF18 + *((volatile uint32_t *)off_10FF18 + 1) )
  {
    *((volatile uint8_t *)a2 - 2) = 1;
  }
  else
  {
    log_printf("set_num_users: Invalid buffer passed: %x\n", a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(volatile uint32_t *)off_10FF10;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}


// check_controller_mode @ 0x10ff34
BOOL check_controller_mode(unsigned int a1) {
  if ( *(volatile uint32_t *)off_10FF64 <= a1 && a1 <= *(volatile uint32_t *)off_10FF64 + *((volatile uint32_t *)off_10FF64 + 1) )
    return 1;
  if ( a1 < *(volatile uint32_t *)off_10FF68 )
    return 0;
  return a1 <= *(volatile uint32_t *)off_10FF68 + *((volatile uint32_t *)off_10FF68 + 1);
}



// hci_send_command @ 0x10ff6c
int hci_send_command(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3

  v3 = (void *)(uintptr_t)(off_10FFB0);
  *((volatile uint32_t *)off_10FFB0 + 3) = dword_10FFB4;
  *v3 = a2;
  v3[1] = a3;
  *((volatile uint8_t *)v3 + 8) = 4;
  hci_handle_command((void *)(v3), a1, 0x20u);
  v4 = (void *)(uintptr_t)(off_10FFB8);
  *((volatile uint32_t *)off_10FFB8 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((volatile uint16_t *)v4 + 14) = 0;
  return 0x40000;
}



// set_user_id @ 0x10ffbc
volatile uint32_t * set_user_id(char a1) {
  volatile uint32_t *v2; // r4

  if ( **(volatile uint8_t **)off_10FFFC == 1 )
    v2 = is_hold_mode();
  else
    v2 = buffer_pool_alloc(dword_110000, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( check_controller_mode((unsigned int)v2) )
  {
    *((volatile uint8_t *)v2 - 1) = a1;
    return v2;
  }
  log_printf("set_user_id: Invalid buffer passed: %x\n", v2);
  return v2;
}


// is_controller_mode @ 0x110008
int is_controller_mode(volatile uint32_t *a1) {
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = check_controller_mode((unsigned int)a1);
  if ( !result )
  {
    result = log_printf("get_native_pool_id: Invalid buffer passed: %x\n", a1);
    v5 = **(volatile uint8_t **)off_1100E4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return assert_error(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !check_controller_mode((unsigned int)a1) )
          log_printf("get_user_id: Invalid buffer passed: %x\n", a1);
        return util_is_nonnull(dword_1100F0, a1);
      }
      if ( **(volatile int16_t **)off_1100E8 < 0 )
        return mmio_clear_register((int)aNativeId3, (int)aPktMemFree, 204);
      return result;
    }
    return is_park_mode(a1);
  }
  v3 = *((volatile uint8_t *)a1 - 4);
  v4 = **(volatile uint8_t **)off_1100E4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return is_connected_flag(a1);
    if ( v3 == 2 )
      return is_sniff_mode(a1);
    if ( *((volatile uint8_t *)a1 - 4) )
      return result;
    return is_park_mode(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(volatile int16_t **)off_1100E8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return sub_11428c(a1);
      }
      if ( v3 == 3 )
        return sub_11428c(a1);
      return mmio_clear_register((int)aNativeId3, (int)aPktMemFree, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return assert_fault(a1);
  if ( !*((volatile uint8_t *)a1 - 4) )
    return assert_error(a1);
  return result;
}


// calculate_rf_power @ 0x110100
int calculate_rf_power() {
  void *v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r0
  int16_t v3; // r2
  int16_t v4; // r1
  uint64_t v5; // kr00_8
  struct __attribute__((packed)) { uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_11017C);
  v1 = *(volatile uint32_t *)off_11017C;
  v2 = (void *)(uintptr_t)(off_110184);
  v3 = HIWORD(((volatile uint32_t *)(uintptr_t)off_110180)[76]);
  v4 = LOWORD(((volatile uint32_t *)(uintptr_t)off_110180)[77]) - 4;
  _frame.v7[1] = *(volatile uint16_t *)(*(volatile uint32_t *)off_11017C + 2);
  _frame.v8[1] = *(volatile uint16_t *)(v1 + 4);
  _frame.v8[5] = *(volatile uint16_t *)(v1 + 6);
  _frame.v8[7] = *(volatile uint16_t *)(v1 + 8);
  v5 = *(volatile uint64_t *)(v1 + 20);
  *(volatile uint32_t *)off_110184 = v5;
  v2[3] = dword_110188;
  v2[1] = HIDWORD(v5);
  *((volatile uint8_t *)v2 + 8) = 1;
  _frame.v8[2] = v4;
  _frame.v8[6] = v3 - 4;
  _frame.v7[0] = 12;
  _frame.v8[4] = 1596;
  _frame.v8[0] = 124;
  _frame.v8[3] = 0;
  hci_handle_command((void *)(v2), (int)_frame.v7, 0x20u);
  return hci_send_command((int)_frame.v8, *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 28), *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 32));
}


// get_link_channel @ 0x11018c
volatile uint32_t *get_link_channel() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_1101E0);
  result = zero_8_bytes((volatile uint32_t *)dword_1101D4);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6) )
  {
    v2 = (void *)(uintptr_t)(off_1101D8);
    v3 = dword_1101DC;
    v4 = dword_1101D4;
    v5 = 0;
    do
    {
      v6 = buffer_pool_alloc(v3, 0x63Cu);
      result = (volatile uint32_t *)co_list_push_back(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// get_link_rate @ 0x1101e4
volatile uint32_t *get_link_rate() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_110218);
  result = zero_8_bytes((volatile uint32_t *)dword_11021C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) )
  {
    v2 = dword_110220;
    v3 = dword_11021C;
    v4 = 0;
    do
    {
      v5 = buffer_pool_alloc(v2, 0xCu);
      result = (volatile uint32_t *)co_list_push_back(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// get_modulation_type @ 0x110224
volatile uint32_t *get_modulation_type() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_110278);
  result = zero_8_bytes((volatile uint32_t *)dword_11026C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (void *)(uintptr_t)(off_110270);
    v3 = dword_110274;
    v4 = dword_11026C;
    v5 = 0;
    do
    {
      v6 = buffer_pool_alloc(v3, 0x6B8u);
      result = (volatile uint32_t *)co_list_push_back(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// get_link_tx_power @ 0x11027c
volatile uint32_t *get_link_tx_power() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1102B0);
  result = zero_8_bytes((volatile uint32_t *)dword_1102B4);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_1102B8;
    v3 = dword_1102B4;
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


// is_scan_enabled @ 0x1102bc
volatile uint32_t *is_scan_enabled() {
  volatile int *v0; // r4
  int v1; // r0
  volatile uint32_t *result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1102F0 = 1;
  }
  v0 = (volatile int *)off_1102F4;
  v1 = dword_1102F8;
  ++*(volatile uint32_t *)off_1102F4;
  result = mem_word_load(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1102F0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// is_inquiry_enabled @ 0x1102fc
int is_inquiry_enabled(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110334 = 1;
  }
  v2 = (volatile int *)off_110338;
  v3 = dword_11033C;
  ++*(volatile uint32_t *)off_110338;
  result = co_list_push_back(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_110334;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// is_connected_flag @ 0x110390
int is_connected_flag(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1103D0 = 1;
  }
  v2 = (volatile int *)off_1103D4;
  v3 = dword_1103D8;
  ++*(volatile uint32_t *)off_1103D4;
  result = co_list_push_back(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_1103DC;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_1103D0;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// is_page_scan_active @ 0x1103e0
int is_page_scan_active() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110420 = 1;
  }
  v0 = (volatile int *)off_110424;
  v1 = dword_110428;
  ++*(volatile uint32_t *)off_110424;
  result = (int)(uintptr_t)(mem_word_load(v1));
  if ( result )
    --*(volatile uint32_t *)off_11042C;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_110420;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// is_sniff_mode @ 0x110430
int is_sniff_mode(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110470 = 1;
  }
  v2 = (volatile int *)off_110474;
  v3 = dword_110478;
  ++*(volatile uint32_t *)off_110474;
  result = co_list_push_back(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_11047C;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_110470;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// is_hold_mode @ 0x110480
volatile uint32_t *is_hold_mode() {
  volatile int *v0; // r4
  int v1; // r0
  volatile uint32_t *result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1104B4 = 1;
  }
  v0 = (volatile int *)off_1104B8;
  v1 = dword_1104BC;
  ++*(volatile uint32_t *)off_1104B8;
  result = mem_word_load(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1104B4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// is_park_mode @ 0x1104c0
int is_park_mode(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1104F8 = 1;
  }
  v2 = (volatile int *)off_1104FC;
  v3 = dword_110500;
  ++*(volatile uint32_t *)off_1104FC;
  result = co_list_push_back(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_1104F8;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// replenish_rxmsg_buffers @ 0x110504
int replenish_rxmsg_buffers(int result) {
  volatile uint32_t *v1; // r4
  unsigned int v2; // r3
  volatile int *v3; // r6
  volatile uint32_t *v4; // r9
  volatile uint32_t *v5; // r8
  int v6; // r5
  volatile int *v7; // r7
  volatile uint32_t *v8; // r10
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r11
  int v11; // r1
  int v12; // r2
  int16_t v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3

  v1 = (void *)(uintptr_t)(off_110608);
  v2 = *(volatile uint16_t *)(result + 28);
  v3 = (volatile int *)off_11060C;
  v4 = (void *)(uintptr_t)(off_110634);
  v5 = (void *)(uintptr_t)(off_110638);
  v6 = result;
LABEL_2:
  v7 = (volatile int *)off_110610;
  while ( v2 <= 1 )
  {
    v8 = (void *)(uintptr_t)(is_page_scan_active());
    if ( !v8 )
    {
      result = log_printf("rep: no rxmsg buffer, %d\r\n", *(volatile uint32_t *)off_110628);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return unknown_func_12d104(32);
    }
    v9 = is_scan_enabled();
    v10 = v9;
    if ( !v9 )
    {
      log_printf(aRepRxmsgNoDesc);
      result = is_sniff_mode(v8);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return unknown_func_12d104(32);
    }
    *v9 = (int)(uintptr_t)(v8);
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_110614 = 1;
    }
    v11 = *v7 + 1;
    *v7 = v11;
    *v1 = 1024;
    while ( (*v1 & 0x800) != 0 )
      ;
    if ( (uint8_t)*v3 )
    {
      v16 = *(volatile uint32_t *)(v6 + 20);
      if ( v16 )
      {
        *(volatile uint32_t *)(v16 + 4) = (int)(uintptr_t)(v9);
      }
      else
      {
        log_printf(aRxmsgTailError);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(volatile int16_t **)off_110618 < 0 && *v4 )
      {
        mmio_clear_register((int)aSdioFunc1H2dFr, (int)aSdioReplenishR, 261);
        v11 = *v7;
      }
      *v4 = (int)(uintptr_t)(v10);
    }
    v12 = *v3;
    v13 = *(volatile uint16_t *)(v6 + 28);
    *(volatile uint32_t *)(v6 + 20) = (int)(uintptr_t)(v10);
    v2 = (uint16_t)(v13 + 1);
    result = 1024;
    *(volatile uint16_t *)(v6 + 28) = v2;
    *v3 = (uint8_t)(v12 + 1);
    *v5 = 1024;
    if ( v11 )
    {
      v14 = v11 - 1;
      v15 = *(volatile uint32_t *)off_110614;
      *v7 = v14;
      if ( !v14 )
      {
        if ( v15 )
        {
          __enable_irq();
          v2 = *(volatile uint16_t *)(v6 + 28);
        }
      }
      goto LABEL_2;
    }
  }
  return result;
}


// rf_bb_config @ 0x11063c
int rf_bb_config(int a1, int a2) {
  volatile uint32_t *v2; // r4
  volatile int *v3; // r7
  unsigned int v6; // r2
  volatile uint32_t *v7; // r9
  volatile int *v8; // r11
  int v9; // r10
  volatile uint32_t *v10; // r0
  volatile uint32_t *v11; // r5
  int v12; // r0
  volatile int *v13; // r3
  int v14; // r0
  int v15; // r1
  int16_t v16; // r2
  volatile uint32_t *v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v21; // [sp+4h] [bp-8h]

  v2 = (void *)(uintptr_t)(off_110760);
  v3 = (volatile int *)off_110764;
  v21 = *(volatile uint16_t *)(*(volatile uint32_t *)off_11075C + 48);
  replenish_rxmsg_buffers(a2);
  v6 = *(volatile uint16_t *)(a2 + 12);
LABEL_2:
  v7 = (void *)(uintptr_t)(off_11078C);
  v8 = (void *)(uintptr_t)(off_110790);
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(volatile uint32_t *)(a1 + 8) + 16))(*(volatile uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      log_printf("rep: no buffer, %d\r\n", *v7);
LABEL_23:
      if ( *(volatile uint16_t *)(a2 + 12) >= (unsigned int)*(volatile uint16_t *)(*(volatile uint32_t *)off_11075C + 50) )
        return 1;
LABEL_24:
      unknown_func_12d104(32);
      return 1;
    }
    v10 = is_scan_enabled();
    v11 = v10;
    if ( !v10 )
    {
      log_printf(aRepNoDesc);
      (*(void ( **)(uint32_t, int))(*(volatile uint32_t *)(a1 + 8) + 20))(*(volatile uint32_t *)(a1 + 4), v9);
      goto LABEL_23;
    }
    *v10 = 0;
    v12 = *v8;
    v11[1] = 0;
    v11[2] = 0;
    *v11 = v12 + v9;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_110768 = 1;
    }
    v13 = (volatile int *)off_11076C;
    v14 = *(volatile uint32_t *)off_11076C + 1;
    *(volatile uint32_t *)off_11076C = v14;
    *v2 = 1;
    while ( (*v2 & 2) != 0 )
      ;
    if ( *v3 )
    {
      v19 = *(volatile uint32_t *)(a2 + 4);
      if ( v19 )
        *(volatile uint32_t *)(v19 + 4) = (int)(uintptr_t)(v11);
    }
    else
    {
      if ( **(volatile int16_t **)off_110770 < 0 && *(volatile uint32_t *)off_110774 )
      {
        mmio_clear_register((int)aSdioFunc1H2dFr_0, (int)aHostSdioReplen, 400);
        v13 = (volatile int *)off_11076C;
        v14 = *(volatile uint32_t *)off_11076C;
      }
      *(volatile uint32_t *)off_110774 = (int)(uintptr_t)(v11);
    }
    v15 = *v3;
    v16 = *(volatile uint16_t *)(a2 + 12);
    *(volatile uint32_t *)(a2 + 4) = (int)(uintptr_t)(v11);
    v6 = (uint16_t)(v16 + 1);
    *(volatile uint16_t *)(a2 + 12) = v6;
    *v3 = (uint16_t)(v15 + 1);
    *(volatile uint32_t *)off_110778 = 1;
    if ( v14 )
    {
      v17 = (void *)(uintptr_t)(off_110768);
      v18 = v14 - 1;
      *v13 = v18;
      if ( !v18 )
      {
        if ( *v17 )
        {
          __enable_irq();
          v6 = *(volatile uint16_t *)(a2 + 12);
        }
      }
      goto LABEL_2;
    }
  }
  return 1;
}


// call_110e24 @ 0x110794
int call_110e24() {
  mmio_write_config();
  return 1;
}



// event_queue_init @ 0x1107a0
int event_queue_init(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_1107D4);
  v2 = (void *)(uintptr_t)(off_1107D8);
  *(volatile uint32_t *)off_1107D4 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((volatile uint16_t *)v2 + 6) = 0;
  v2[2] = 0;
  *((volatile uint8_t *)v2 + 14) = 0;
  *((volatile uint16_t *)v2 + 14) = 0;
  v2[6] = 0;
  *((volatile uint8_t *)v2 + 30) = 0;
  rf_bb_config((int)v1, (int)v2);
  return 1;
}



// bt_scheduler_run @ 0x110c60
int bt_scheduler_run() {
  volatile uint32_t *v0; // r8
  volatile int *v1; // r7
  volatile int *v2; // r10
  volatile char *v3; // r9
  int v4; // r3
  unsigned int v5; // r6
  int v6; // r11
  uint16_t v7; // r4
  int v8; // r5
  int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // [sp+4h] [bp-8h]

  v0 = (void *)(uintptr_t)(off_110D44);
  v1 = (volatile int *)off_110D3C;
  v2 = (volatile int *)off_110D40;
  v3 = (volatile char *)off_110D44 + 3080;
  while ( 1 )
  {
    v4 = v0[770];
    if ( !v4 )
      break;
    while ( 1 )
    {
      v5 = *(volatile uint16_t *)(v4 + 8);
      v6 = *(volatile uint32_t *)(v4 + 4);
      if ( *(volatile uint16_t *)(v4 + 8) )
      {
        v7 = 0;
        v8 = 0;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            v10 = v6;
            ++v7;
            v6 = *(volatile uint32_t *)(v6 + 4);
            if ( v9 == v8 )
              break;
            is_inquiry_enabled((volatile uint32_t *)(uintptr_t)v10);
            v9 = v7;
            if ( v7 >= v5 )
              goto LABEL_8;
          }
          v17 = v10;
          mac_wait_tx();
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(v8 + (*(volatile uint8_t *)(v17 + 11) & 0x7F)) & 0xFFFFu);
          is_inquiry_enabled((volatile uint32_t *)(uintptr_t)v17);
          v9 = v7;
          v8 = (uint16_t)v8;
        }
        while ( v7 < v5 );
      }
LABEL_8:
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v2 = 1;
      }
      ++*v1;
      mem_word_load((int)(uintptr_t)(v3));
      v11 = *v1;
      --*((volatile uint8_t *)v0 + 3074);
      if ( !v11 )
        break;
      v12 = v11 - 1;
      v13 = *v2;
      *v1 = v12;
      if ( v12 || !v13 )
        break;
      __enable_irq();
      v4 = v0[770];
      if ( !v4 )
        goto LABEL_14;
    }
  }
LABEL_14:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110D40 = 1;
  }
  ++*v1;
  result = unknown_func_12d14c(128);
  if ( *v1 )
  {
    v15 = *v1 - 1;
    v16 = *(volatile uint32_t *)off_110D40;
    *v1 = v15;
    if ( !v15 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write_config @ 0x110e24
int mmio_write_config() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r1
  volatile int *v2; // r4
  volatile unsigned int *v3; // r5
  volatile unsigned int *v4; // r2
  volatile uint32_t *v5; // r0
  volatile uint32_t *v6; // r7
  volatile uint32_t *v7; // r6
  int v8; // r1
  volatile uint32_t *v9; // r3
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r0
  int v12; // r1
  volatile int *v13; // r3
  int v14; // r1
  void *v15; // r2
  volatile uint32_t *v16; // r1
  int result; // r0
  volatile uint32_t *v18; // r3
  volatile unsigned int *v19; // r2
  volatile unsigned int *v20; // r1

  v0 = (void *)(uintptr_t)(off_110FC8);
  *(volatile uint32_t *)off_110FC4 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (volatile unsigned int *)off_110FF8;
    v20 = (volatile unsigned int *)off_110FDC;
    *(volatile uint32_t *)off_110FF8 = *(volatile uint32_t *)off_110FF8 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)sys_command_40d();
  }
  else
  {
    event_dispatch(aWaitCmd5);
    do
    {
      while ( (*(volatile uint32_t *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110FD0 < 0 );
    v1 = (void *)(uintptr_t)(off_110FD0);
    *(volatile uint32_t *)off_110FD0 = dword_110FD4;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(volatile uint32_t *)off_110FC8 & 1) == 0 )
        ;
    }
    v2 = (volatile int *)off_110FD8;
    v3 = (volatile unsigned int *)off_110FDC;
    v4 = (volatile unsigned int *)off_110FE0;
    v5 = (void *)(uintptr_t)(off_110FE4);
    v6 = (void *)(uintptr_t)(off_110FE8);
    v7 = (void *)(uintptr_t)(off_110FEC);
    *(volatile uint32_t *)off_110FC8 = 2;
    v8 = dword_110FF0;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = (void *)(uintptr_t)(off_110FF4);
    *v5 &= v8;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = (void *)(uintptr_t)(off_110FF8);
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = (void *)(uintptr_t)(off_110FFC);
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_111000;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    event_dispatch(aWaitIoEnable);
    v13 = (volatile int *)off_110FD0;
    v14 = dword_110FD4;
    while ( 1 )
    {
      while ( (*v13 & 0x20000000) != 0 )
        ;
      if ( *v13 >= 0 )
      {
        *v13 = v14;
        while ( (*v13 & 0x20000000) != 0 )
          ;
        if ( (*v13 & 6) != 0 )
          break;
      }
    }
    v15 = (void *)(uintptr_t)(off_110FD0);
    do
    {
      while ( (*(volatile uint32_t *)off_110FD0 & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110FD0 < 0 );
    v16 = (void *)(uintptr_t)(off_110FD0);
    *(volatile uint32_t *)off_110FD0 = dword_111008;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = event_dispatch(aIoEnable, v16, v15, 4 * *v16);
    *(volatile uint32_t *)off_110FDC = *(volatile uint32_t *)off_110FDC & 0xFFFFF000 | 0x960;
  }
  v18 = (void *)(uintptr_t)(off_111014);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_111010 + 2) + 324) = off_111018;
  v18[2] = 2;
  return result;
}


// unknown_1 @ 0x11101c
int unknown_1(int a1, int a2, int a3) {
  volatile int *v6; // r9
  volatile uint8_t *v7; // r3
  int v8; // r5
  int result; // r0
  volatile uint32_t *v10; // r4
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r1
  int v13; // r5
  int v14; // r3
  volatile uint32_t *v15; // r2
  volatile uint8_t *v16; // r4
  volatile uint8_t *v17; // r5
  int v18; // r3
  volatile uint8_t *v19; // r10
  int v20; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11110C = 1;
  }
  v6 = (volatile int *)off_111138;
  v7 = *(volatile uint8_t **)off_111110;
  v8 = *(volatile uint32_t *)off_111138 + 1;
  *(volatile uint32_t *)off_111138 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = (void *)(uintptr_t)(off_111128);
    if ( *(volatile uint8_t *)off_111128 )
    {
      v19 = (void *)(uintptr_t)(off_11112C);
      v20 = *((volatile uint8_t *)off_11112C + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = global_state_get((void *)(uintptr_t)(dword_111130));
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        gpio_clear_bit(v20);
      else
        gpio_set_bit(v20);
    }
    else
    {
      v17 = (volatile uint8_t *)off_11112C;
      if ( *((volatile uint8_t *)off_11112C + 369) )
        result = gpio_clear_bit(1);
      else
        result = gpio_set_bit(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = unknown_worker((void *)(uintptr_t)(dword_111130), *((volatile uint32_t *)off_111134 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = (void *)(uintptr_t)(off_111114);
  *(volatile uint32_t *)off_111114 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(volatile uint32_t *)off_111118 )
  {
    v11 = (void *)(uintptr_t)(off_11111C);
    v12 = (void *)(uintptr_t)(off_111120);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_11111C + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = (void *)(uintptr_t)(off_111120);
    *(volatile uint32_t *)off_111118 = a1;
    v11 = (void *)(uintptr_t)(off_11111C);
    *v15 += a2;
  }
  *(volatile uint32_t *)off_111124 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(volatile uint32_t *)off_11110C;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}



// pack_control_word @ 0x11113c
volatile uint32_t * pack_control_word(volatile uint32_t *result, int a2, int a3, uint16_t a4, int a5) {
  result[2] = dword_111158 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}



// unknown_3 @ 0x11115c
int unknown_3(int a1) {
  volatile int *v2; // r5
  volatile uint8_t *v3; // r3
  int v4; // r1
  volatile uint32_t *v5; // r2
  int result; // r0
  volatile uint32_t *v7; // r2
  volatile uint32_t *v8; // r6
  int v9; // r1
  int v10; // r3
  volatile uint8_t *v11; // r6
  volatile uint8_t *v12; // r7
  int v13; // r3
  int v14; // r6

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11123C = 1;
  }
  v2 = (volatile int *)off_111240;
  v3 = *(volatile uint8_t **)off_111244;
  v4 = *(volatile uint32_t *)off_111240 + 1;
  *(volatile uint32_t *)off_111240 = v4;
  if ( *v3 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_111260);
    v12 = (void *)(uintptr_t)(off_111264);
    if ( *(volatile uint8_t *)off_111260 )
    {
      v14 = *((volatile uint8_t *)off_111264 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
if ( global_state_get((void *)(uintptr_t)(dword_111268)) ) goto LABEL_18;
      if ( v12[369] )
        gpio_clear_bit(v14);
      else
        gpio_set_bit(v14);
    }
    else
    {
      if ( *((volatile uint8_t *)off_111264 + 369) )
        gpio_clear_bit(1);
      else
        gpio_set_bit(1);
      v13 = (uint8_t)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    unknown_worker((void *)(uintptr_t)(dword_111268), *((volatile uint32_t *)off_11126C + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = (void *)(uintptr_t)(off_111248);
  *(volatile uint32_t *)off_111248 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(volatile uint32_t *)off_11124C )
  {
    result = dword_111250;
    v7 = (void *)(uintptr_t)(off_111254);
    *(volatile uint32_t *)(*(volatile uint32_t *)(dword_111250 + 6164) + 4) = a1;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_111254);
    *(volatile uint32_t *)off_11124C = a1;
    result = dword_111250;
  }
  ++*v7;
  v8 = (void *)(uintptr_t)(off_11125C);
  *(volatile uint8_t *)off_111258 |= 2u;
  *v8 = 64;
  *(volatile uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(volatile uint32_t *)off_11123C;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}



// mutex_lock @ 0x111270
int mutex_lock(char a1, volatile char *a2, unsigned int a3, int a4) {
  volatile uint32_t *v7; // r0
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r6
  int v10; // r2
  int v11; // r3

  v7 = set_user_id(4);
  if ( !v7 )
    return log_printf(aErrNoMsgPkt);
  v8 = v7;
  v9 = is_scan_enabled();
  if ( v9 )
  {
    *(volatile uint8_t *)v8 = a3;
    *((volatile uint8_t *)v8 + 1) = BYTE1(a3) & 0xF;
    *((volatile uint8_t *)v8 + 2) = a1;
    *((volatile uint8_t *)v8 + 3) = 0;
    memcpy((volatile char *)v8 + 4, a2, a3);
    v10 = v9[2];
    v11 = dword_1112E8;
    v9[1] = 0;
    *v9 = (int)(uintptr_t)(v8);
    v9[2] = (uint16_t)(a3 + 4) | v11 & v10 | 0x80000000;
    return unknown_3((int)v9);
  }
  else
  {
    log_printf(aErrSendMsgCfgT);
    return is_controller_mode(v8);
  }
}


// get_status_flag @ 0x1112f4
int get_status_flag() {
  if ( *(volatile uint8_t *)off_111304 )
    return 1;
  else
    return *(volatile uint8_t *)off_111308;
}



// set_sdio_phase_config @ 0x11130c
int set_sdio_phase_config(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (volatile int *)off_111388;
  v2 = a1 & 0x3FFFFF;
  v3 = *(volatile uint32_t *)off_111388 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(volatile uint32_t *)off_111388 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(volatile uint32_t *)off_111388 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return log_printf("sdio pahse cfg %x\n", *(volatile uint32_t *)off_111388 & 0x3FFFFF);
}


