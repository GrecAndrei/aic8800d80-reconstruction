// mmio_rmw32 @ 0x10ecec
int mmio_rmw32(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r5
  volatile uint32_t *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10ED34 = 1;
  }
  v4 = (volatile int *)off_10ED38;
  ++*(volatile uint32_t *)off_10ED38;
  if ( a4 )
  {
    v5 = (void *)(uintptr_t)(off_10ED3C);
    while ( !*(volatile uint32_t *)off_10ED3C )
      ;
    result = call_patch_hook_2();
    *v5 = 1;
  }
  else
  {
    result = call_patch_hook_2();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(volatile uint32_t *)off_10ED34;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}



// rf_set_frequency @ 0x10ed40
int rf_set_frequency(int a1) {
  alloc_tx_event("Reboot:%x\n", a1);
  mmio_rmw32(dword_10ED8C, 196608, dword_10ED88, 1);
  mmio_rmw32(1879048192, 1, 1, 1);
  mmio_read32_variant(dword_10ED90, a1, 1);
  return mmio_rmw32(dword_10ED94, 2, 2, 1);
}


// rf_set_channel_1 @ 0x10ed98
int rf_set_channel_1(int a1) {
  mmio_rmw32(dword_10EDCC, 196608, dword_10EDC8, 1);
  mmio_read32_variant(dword_10EDD0, a1 << 15, 1);
  return mmio_rmw32(1879048192, 1, 1, 1);
}



// write_mmio_register @ 0x10edd4
int write_mmio_register() {
  return mmio_rmw32(dword_10EDE0, 0, 2, 1);
}



// rf_get_status @ 0x10ede4
int rf_get_status() {
  return (uint16_t)mmio_read32_1(dword_10EDF4, 1) >> 11;
}



// padding_data @ 0x10edf8
int padding_data(int a1) {
  return mmio_rmw32(dword_10EE0C, (a1 << 11) & 0xF800, 63488, 1);
}



// rf_enable_rx @ 0x10ee10
int rf_enable_rx() {
  int result; // r0

  mmio_rmw32(1879048192, 256, 264, 1);
  mmio_rmw32(dword_10EFC0, 0x8000000, 0x8000000, 1);
  mmio_rmw32(dword_10EFC4, 21, 31, 1);
  mmio_rmw32(dword_10EFD0, dword_10EFCC, dword_10EFC8, 1);
  mmio_rmw32(dword_10EFD4, 2560, 2560, 1);
  mmio_rmw32(dword_10EFD8, 255, 255, 1);
  mmio_rmw32(dword_10EFDC, 0, 100663296, 1);
  mmio_rmw32(dword_10EFE0, 0, 983040, 1);
  mmio_rmw32(dword_10EFE4, 96, 96, 1);
  mmio_rmw32(dword_10EFE8, 256, 256, 1);
  mmio_rmw32(dword_10EFEC, 469762048, 469762048, 1);
  mmio_rmw32(dword_10EFF0, 104, 252, 1);
  mmio_rmw32(dword_10EFF4, 6, 102, 1);
  mmio_rmw32(dword_10EFF8, 320, 992, 1);
  mmio_rmw32(dword_10F004, dword_10F000, dword_10EFFC, 1);
  mmio_rmw32(dword_10F008, 0x400000, 15728640, 1);
  mmio_rmw32(dword_10F00C, 16, 63, 1);
  mmio_rmw32(dword_10F010, 0, 60, 1);
  mmio_rmw32(dword_10F014, 0, 256, 1);
  mmio_rmw32(dword_10F018, 2048, 16128, 1);
  result = mmio_rmw32(dword_10F01C, 1, 1, 1);
  if ( **(volatile uint8_t **)off_10F020 == 1 )
  {
    mmio_read32_variant(dword_10F028, dword_10F024, 1);
    mmio_read32_variant(dword_10F030, dword_10F02C, 1);
    mmio_rmw32(dword_10F01C, 0x100000, 0x100000, 1);
    result = mmio_rmw32(dword_10F034, 2, 31, 1);
    if ( !*((volatile uint8_t *)off_10F038 + 375) )
    {
      mmio_rmw32(dword_10F03C, 1, 1, 1);
      mmio_rmw32(dword_10F014, 256, 256, 1);
      mmio_rmw32(dword_10F018, 0x2000, 16128, 1);
      mmio_rmw32(dword_10EFDC, 2359296, 16515072, 1);
      return mmio_rmw32(dword_10F01C, 256, 256, 1);
    }
  }
  return result;
}



// rf_cal_init @ 0x10f040
unsigned int rf_cal_init() {
  unsigned int result; // r0

  result = rf_reg_write_byte(0xC2u);
  *((volatile uint8_t *)off_10F054 + 7) = -62;
  return result;
}



// rf_get_rssi @ 0x10f058
int rf_get_rssi() {
  volatile uint8_t *v0; // r6
  int v1; // r5
  int v2; // r4
  int result; // r0
  volatile unsigned int v4; // r3

  v0 = (void *)(uintptr_t)(off_10F0B8);
  v1 = (char)(*((volatile uint8_t *)off_10F0B8 + 5) + (*(volatile uint8_t *)off_10F0B4 & 3));
  v2 = *((volatile char *)off_10F0B8 + 7) - v1;
  if ( v2 < -62 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(-62) & 0xFFu);
  rf_reg_write_byte(v2);
  v0[7] = v2;
  result = alloc_tx_event("update# =%d %d\r\n", (char)v2, v1);
  if ( (char)v2 < -61 )
  {
    v0[11] = 0;
  }
  else
  {
    v4 = (*(volatile uint32_t *)0x40501010u);
    return mem_copy_util((volatile uint32_t *)v0 + 3, v4 + 30000 * *((volatile uint16_t *)v0 + 4));
  }
  return result;
}


// rx_copy_stats @ 0x10f0c4
int rx_copy_stats() {
  int v0; // r2
  uint64_t v1; // kr00_8
  volatile char *v2; // r3
  uint64_t v3; // r0
  int v4; // r4
  int v5; // r2
  uint64_t v6; // kr10_8

  v0 = *(volatile uint32_t *)off_10F110;
  v1 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10F110 + 24);
  v2 = (volatile char *)off_10F114;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(*(volatile uint32_t *)off_10F110 + 36)) & 0xFFFFFFFFu);
  v4 = *(volatile uint32_t *)(*(volatile uint32_t *)off_10F110 + 32);
  *(volatile uint32_t *)off_10F114 = v1;
  v6 = *(volatile uint64_t *)(v0 + 40);
  v5 = *(volatile uint32_t *)(v0 + 44);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v6) << 32);
  *((volatile uint32_t *)v2 + 1) = HIDWORD(v1);
  *((volatile uint32_t *)v2 + 2) = v4;
  *(volatile uint64_t *)(v2 + 12) = v3;
  *((volatile uint32_t *)v2 + 5) = v5;
  crypto_init();
  hw_config_init();
  patch_interrupt_vector();
  if ( **(volatile uint8_t **)off_10F118 == 3 )
    phy_context_init();
  return (int)(uintptr_t)(clear_queue_buffer());
}


// ke_get_state @ 0x10f11c
int ke_get_state() {
  volatile uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  void *v3; // r2

  if ( *((volatile uint8_t *)off_10F150 + 362) )
  {
    *(volatile uint8_t *)off_10F154 = 0;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_10F154);
    *(volatile uint32_t *)off_10F154 = dword_10F158;
    v2 = dword_10F15C;
    v3 = (void *)(uintptr_t)(off_10F160);
    v0[7] = -62;
    *((volatile uint32_t *)v0 + 2) = 1000;
    *((volatile uint16_t *)v0 + 2) = 1752;
    *((volatile uint32_t *)v0 + 4) = v2;
    *((volatile uint32_t *)v0 + 8) = (int)(uintptr_t)(v3);
    return 1752;
  }
  return result;
}



// bt_send_data @ 0x10f230
int bt_send_data(int a1, int a2) {
  wait_for_state((void *)(uintptr_t)(a2));
  return 1;
}



// tx_store_packet @ 0x10f23c
int tx_store_packet() {
  volatile uint8_t *v0; // r4
  volatile char *v1; // r0

  v0 = (void *)(uintptr_t)(off_10F26C);
  v1 = (volatile char *)off_10F26C + 1624;
  *((volatile uint16_t *)off_10F26C + 810) = 80;
  v0[1622] = 81;
  clear_stats_buf((void *)(v1));
  *((volatile uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return (int)(uintptr_t)(clear_stats_buf((void *)(v0 + 2436)));
}



// rf_config_bb @ 0x10f270
uint64_t rf_config_bb() {
  volatile uint16_t *v0; // r5
  volatile int *v1; // r4
  volatile int *v2; // r5
  int v3; // r6
  volatile int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  volatile uint32_t *v7; // r3

  v0 = (void *)(uintptr_t)(off_10F30C);
  v1 = (volatile int *)dword_10F310;
  *((volatile uint16_t *)off_10F30C + 3080) = -16193;
  v0[1536] = -16193;
  *((volatile uint8_t *)v0 + 6162) = 0;
  *((volatile uint32_t *)v0 + 1541) = 0;
  *((volatile uint8_t *)v0 + 6176) = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  clear_stats_buf((volatile uint32_t *)v0 + 770);
  clear_stats_buf((void *)(v1 - 3));
  clear_stats_buf((void *)(v1 + 512));
  clear_stats_buf((void *)(v1 + 514));
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
    wlan_ioctl_handler_1(v3, (void *)(v4));
  }
  while ( v1 != v2 );
  v5 = dword_10F314;
  result = (unsigned int)(dword_10F314 + 1152);
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


// rf_get_state @ 0x10f318
int rf_get_state() {
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

  v0 = (volatile uint8_t **)off_10F3D8;
  v1 = **(volatile uint8_t **)off_10F3D8;
  switch ( v1 )
  {
    case 1:
      v8 = (void *)(uintptr_t)(off_10F3DC);
      v9 = (void *)(uintptr_t)(off_10F3F4);
      *((volatile uint32_t *)off_10F3DC + 2) = dword_10F3F0;
      v8[3] = (int)(uintptr_t)(v9);
      break;
    case 2:
      v2 = (void *)(uintptr_t)(off_10F3DC);
      v3 = dword_10F3E4;
      *((volatile uint32_t *)off_10F3DC + 6) = dword_10F3E0;
      v2[7] = v3;
      break;
    case 3:
      v6 = (void *)(uintptr_t)(off_10F3DC);
      v7 = dword_10F3EC;
      *((volatile uint32_t *)off_10F3DC + 8) = dword_10F3E8;
      v6[9] = v7;
      break;
  }
  tx_store_packet();
  v4 = rf_config_bb();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F3DC;
    *(volatile uint32_t *)off_10F3F8 = dword_10F40C;
    v18 = (int)(uintptr_t)(get_current_channel(v4, HIDWORD(v4)));
    v19 = (int)(uintptr_t)(get_core_temp(v18));
    v20 = (int)(uintptr_t)(get_tx_power(v19));
    get_noise_floor(v20);
    v21 = v17[2](dword_10F400);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v17[3](v21)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F408;
    *(volatile uint32_t *)off_10F3F8 = dword_10F404;
    v13 = (int ( **)(int))off_10F3DC;
    *(volatile uint16_t *)(v12 + 8244) = 0;
    v14 = (int)(uintptr_t)(rf_read_channel());
    rf_read_status_1(v14);
    v15 = v13[6](dword_10F400);
    v16 = v13[7](v15);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(set_config_field(v16)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F3DC;
    *(volatile uint32_t *)off_10F3F8 = dword_10F3FC;
    rf_power_down();
    v11 = v10[8](dword_10F400);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v10[9](v11)) & 0xFFFFFFFFu);
  }
  return v4;
}



// rf_calibration_2 @ 0x10f410
int rf_calibration_2() {
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

  result = irq_disable_global_3(512);
  a1 = *((volatile uint32_t *)off_10F6F4 + 2);
  if ( !a1 )
    return result;
  v1 = (volatile int *)off_10F720;
  while ( 2 )
  {
    result = phy_lock(a1);
    if ( !result && *(volatile uint8_t *)(a1 + 108) )
      goto LABEL_4;
    for ( ; *(volatile uint32_t *)(a1 + 1312); result = phy_txpower_calc((unsigned int)v2, 3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_10F6F8 = 1;
      }
      ++*v1;
      v2 = list_pop(a1 + 1312);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (volatile int *)off_10F6F8;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((volatile uint8_t *)off_10F6FC + 511) )
      goto LABEL_4;
    v6 = a1;
    v7 = (volatile int16_t **)off_10F700;
    v8 = dword_10F704;
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
          v11 = list_pop(v6 + 1304);
          v12 = *((volatile uint8_t *)v11 + 29);
          v13 = (unsigned int)v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            irq_disable_mmio_write((int)aTxdescTmpHostS, (int)aReplenishSend, 374);
            v12 = *(volatile uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( *(volatile uint8_t *)(v14 + 37) || (*(volatile uint16_t *)(v13 + 30) & 8) != 0 )
            break;
          alloc_tx_event("sta invalid:%d\n", *(volatile uint8_t *)(v14 + 35));
          phy_set_channel_1(v13, v10, 0x80000000);
          if ( !*(volatile uint32_t *)(v6 + 1304) )
          {
LABEL_25:
            v9 = v25;
            goto LABEL_26;
          }
        }
        if ( *(volatile uint8_t *)(v8 + 696 * v12 + 36) != 1 )
        {
          phy_txpower_calc(v13, v10);
          goto LABEL_24;
        }
        if ( **v7 < 0 )
        {
          if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          {
LABEL_56:
            wlan_ioctl_handler_1(v8 + 8 * (87 * (int16_t)v12 + v25 + 78), (volatile uint32_t *)v13);
            goto LABEL_23;
          }
          irq_disable_mmio_write((int)aTxdescTmpHostF, (int)aReplenishSend, 383);
        }
        if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          goto LABEL_56;
LABEL_23:
        alloc_tx_event("push rt sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v12 + 35));
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
          alloc_tx_event("sta invalid:%d\n", v17[35]);
          v24 = list_pop(v6 + 1264);
          phy_set_channel_1((int)v24, v10, 0x80000000);
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
          *(volatile uint32_t *)off_10F6F8 = 1;
        }
        ++*v1;
        v18 = list_pop(v6 + 1264);
        alloc_tx_event("push sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v16 + 35));
        if ( *v1 )
        {
          v19 = *v1 - 1;
          v20 = *(volatile uint32_t *)off_10F6F8;
          *v1 = v19;
          if ( !v19 )
          {
            if ( v20 )
              __enable_irq();
          }
        }
        wlan_ioctl_handler_1(v8 + 8 * (87 * (int16_t)v16 + v26 + 73), v18);
LABEL_37:
        v15 = *(volatile uint32_t *)(v6 + 1264);
        if ( !v15 )
          goto LABEL_38;
      }
      if ( rf_validate_freq(v16, *(volatile uint8_t *)(v15 + 27)) )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_10F6F8 = 1;
        }
        ++*v1;
        v21 = list_pop(v6 + 1264);
        if ( *v1 )
        {
          v22 = *v1 - 1;
          v23 = *(volatile uint32_t *)off_10F6F8;
          *v1 = v22;
          if ( !v22 )
          {
            if ( v23 )
              __enable_irq();
          }
        }
        phy_txpower_calc((unsigned int)v21, v10);
        goto LABEL_37;
      }
      v9 = v26;
      *((volatile uint8_t *)off_10F6FC + 512) = 1;
LABEL_39:
      --v9;
      result = invalid_handler(v10);
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


// ipc_send_command @ 0x10f7cc
int ipc_send_command() {
  int v0; // r0

  v0 = tx_send_pdu(1037, 1, 13, 8);
  return (int)(uintptr_t)(rx_process_packet_1(v0));
}



// rx_handle_packet @ 0x10f7e4
unsigned int rx_handle_packet(volatile int *a1, int a2, unsigned int a3) {
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
  v8 = (volatile int *)off_10F9E0;
  v9 = (void *)(uintptr_t)(off_10F9E4);
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
        debug_printf("set_native_pool_id: Invalid buffer passed: %x\n", v15);
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
      debug_printf("set_pattern: Invalid buffer passed: %x\n", v15);
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
      debug_printf("set_num_users: Invalid buffer passed: %x\n", v15);
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
      debug_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", v15);
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


// tx_irq_handler @ 0x10f9e8
volatile uint32_t * tx_irq_handler(int a1, unsigned int a2) {
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
    debug_printf("SwEr:NoSizeAlloc : %d\n\r", a2);
    return nullptr;
  }
  v3 = *(volatile uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    debug_printf(aMemmgrerrSubpo, a2);
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
    *(volatile uint32_t *)off_10FB74 = 1;
  }
  v6 = (volatile int *)off_10FB78;
  v7 = *v4;
  v3 = *(volatile uint32_t **)off_10FB78;
  v8 = *(volatile uint32_t *)off_10FB78 + 1;
  *(volatile uint32_t *)off_10FB78 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (volatile int *)off_10FB74;
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
  v9 = (volatile unsigned int *)off_10FB7C;
  v3 = *((volatile uint32_t **)v4 + 2);
  v10 = *(volatile uint32_t *)off_10FB7C;
  if ( *(volatile uint32_t *)off_10FB7C <= (unsigned int)v3 && (unsigned int)v3 <= *((volatile uint32_t *)off_10FB7C + 1) + v10
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FB80
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FB80 + *((volatile uint32_t *)off_10FB80 + 1) )
  {
    *((volatile uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    debug_printf("get_next_buffer_addr: Invalid buffer passed: %x\n", *((volatile uint32_t *)v4 + 2));
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
  v16 = *(volatile uint32_t *)off_10FB80;
  if ( *(volatile uint32_t *)off_10FB80 > (unsigned int)v3 || *((volatile uint32_t *)off_10FB80 + 1) + v16 < (unsigned int)v3 )
  {
    debug_printf("get_pattern: Invalid buffer passed: %x\n", v3);
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
      v21 = *(volatile uint32_t *)off_10FB74;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    debug_printf("SwEr:AllcErrPtrn : %d, buffer: 0x%x\n\r", v11, v3);
    return nullptr;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    debug_printf("set_pattern: Invalid buffer passed: %x\n", v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *((volatile uint32_t *)off_10FB80 + 1) )
      goto LABEL_37;
LABEL_20:
    *((volatile uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FB80
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FB80 + *((volatile uint32_t *)off_10FB80 + 1) )
  {
    *((volatile uint8_t *)v3 - 2) = 1;
  }
  else
  {
    debug_printf("set_num_users: Invalid buffer passed: %x\n", v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(volatile uint32_t *)off_10FB74;
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


// util_check_arg @ 0x10fba0
int util_check_arg(int a1, volatile uint32_t *a2) {
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
  if ( (v4 = (volatile unsigned int *)off_10FDCC, (unsigned int)a2 >= *(volatile uint32_t *)off_10FDCC)
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDCC + *((volatile uint32_t *)off_10FDCC + 1)
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FDD8
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDD8 + *((volatile uint32_t *)off_10FDD8 + 1) )
  {
    v5 = *((volatile uint8_t *)a2 - 4);
  }
  else
  {
    debug_printf("get_native_pool_id: Invalid buffer passed: %x\n", a2);
    v5 = 0;
  }
  if ( *(volatile uint8_t *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(volatile uint32_t *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FDD0 = 1;
  }
  v7 = (volatile int *)off_10FDD4;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(volatile uint32_t *)off_10FDD4;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (volatile int *)off_10FDD8;
    v15 = *(volatile uint32_t *)off_10FDD8;
    if ( (unsigned int)a2 < *(volatile uint32_t *)off_10FDD8 || (unsigned int)a2 > *((volatile uint32_t *)off_10FDD8 + 1) + v15 )
    {
      debug_printf("get_pattern: Invalid buffer passed: %x\n", a2);
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
      v17 = *(volatile uint32_t *)off_10FDD0;
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
        v13 = *(volatile uint32_t *)off_10FDD0;
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
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FDD8
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDD8 + *((volatile uint32_t *)off_10FDD8 + 1) )
      {
        *((volatile uint8_t *)a2 - 3) = 85;
      }
      else
      {
        debug_printf("set_pattern: Invalid buffer passed: %x\n", a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FDD8
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDD8 + *((volatile uint32_t *)off_10FDD8 + 1) )
      {
        *a2 = *((volatile uint32_t *)v19 + 2);
      }
      else
      {
        debug_printf("set_next_buffer_addr: Invalid buffer passed: %x\n", a2);
      }
      v21 = *(volatile uint16_t *)(v6 + v20);
      v22 = *v7;
      *((volatile uint32_t *)v19 + 2) = (int)(uintptr_t)(a2);
      *(volatile uint16_t *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(volatile uint32_t *)off_10FDD0;
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
  v14 = (volatile int *)off_10FDD8;
LABEL_36:
  v15 = *v14;
  if ( (unsigned int)a2 < *v14 )
  {
LABEL_38:
    debug_printf("decr_num_users: Invalid buffer passed: %x\n", a2);
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
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FDD8
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FDD8 + *((volatile uint32_t *)off_10FDD8 + 1) )
  {
    *((volatile uint8_t *)a2 - 2) = 1;
  }
  else
  {
    debug_printf("set_num_users: Invalid buffer passed: %x\n", a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(volatile uint32_t *)off_10FDD0;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}


// check_state_flag @ 0x10fdf4
BOOL check_state_flag(unsigned int a1) {
  if ( *(volatile uint32_t *)off_10FE24 <= a1 && a1 <= *(volatile uint32_t *)off_10FE24 + *((volatile uint32_t *)off_10FE24 + 1) )
    return 1;
  if ( a1 < *(volatile uint32_t *)off_10FE28 )
    return 0;
  return a1 <= *(volatile uint32_t *)off_10FE28 + *((volatile uint32_t *)off_10FE28 + 1);
}



// log_event @ 0x10fe2c
int log_event(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3

  v3 = (void *)(uintptr_t)(off_10FE70);
  *((volatile uint32_t *)off_10FE70 + 3) = dword_10FE74;
  *v3 = a2;
  v3[1] = a3;
  *((volatile uint8_t *)v3 + 8) = 4;
  rx_handle_packet((void *)(v3), a1, 0x20u);
  v4 = (void *)(uintptr_t)(off_10FE78);
  *((volatile uint32_t *)off_10FE78 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((volatile uint16_t *)v4 + 14) = 0;
  return 0x40000;
}



// is_chip_ready @ 0x10fe7c
volatile uint32_t * is_chip_ready(char a1) {
  volatile uint32_t *v2; // r4

  if ( **(volatile uint8_t **)off_10FEBC == 1 )
    v2 = (void *)(uintptr_t)(mmio_read_2());
  else
    v2 = tx_irq_handler(dword_10FEC0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( check_state_flag((unsigned int)v2) )
  {
    *((volatile uint8_t *)v2 - 1) = a1;
    return v2;
  }
  debug_printf("set_user_id: Invalid buffer passed: %x\n", v2);
  return v2;
}


// wait_for_state @ 0x10fec8
int wait_for_state(volatile uint32_t *a1) {
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = check_state_flag((unsigned int)a1);
  if ( !result )
  {
    result = debug_printf("get_native_pool_id: Invalid buffer passed: %x\n", a1);
    v5 = **(volatile uint8_t **)off_10FFA4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return util_call_arg(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !check_state_flag((unsigned int)a1) )
          debug_printf("get_user_id: Invalid buffer passed: %x\n", a1);
        return util_check_arg(dword_10FFB0, a1);
      }
      if ( **(volatile int16_t **)off_10FFA8 < 0 )
        return irq_disable_mmio_write((int)aNativeId3, (int)aPktMemFree, 204);
      return result;
    }
    return mmio_write_3(a1);
  }
  v3 = *((volatile uint8_t *)a1 - 4);
  v4 = **(volatile uint8_t **)off_10FFA4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return mmio_write_1(a1);
    if ( v3 == 2 )
      return mmio_write_2(a1);
    if ( *((volatile uint8_t *)a1 - 4) )
      return result;
    return mmio_write_3(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(volatile int16_t **)off_10FFA8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return assert_fail(a1);
      }
      if ( v3 == 3 )
        return assert_fail(a1);
      return irq_disable_mmio_write((int)aNativeId3, (int)aPktMemFree, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return util_call_raw(a1);
  if ( !*((volatile uint8_t *)a1 - 4) )
    return util_call_arg(a1);
  return result;
}


// get_rx_stats @ 0x10ffc0
int get_rx_stats() {
  void *v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r0
  int16_t v3; // r2
  int16_t v4; // r1
  uint64_t v5; // kr00_8
  struct __attribute__((packed)) { uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_11003C);
  v1 = *(volatile uint32_t *)off_11003C;
  v2 = (void *)(uintptr_t)(off_110044);
  v3 = *((volatile uint16_t *)off_110040 + 153);
  v4 = *((volatile uint16_t *)off_110040 + 154) - 4;
  _frame.v7[1] = *(volatile uint16_t *)(*(volatile uint32_t *)off_11003C + 2);
  _frame.v8[1] = *(volatile uint16_t *)(v1 + 4);
  _frame.v8[5] = *(volatile uint16_t *)(v1 + 6);
  _frame.v8[7] = *(volatile uint16_t *)(v1 + 8);
  v5 = *(volatile uint64_t *)(v1 + 20);
  *(volatile uint32_t *)off_110044 = v5;
  v2[3] = dword_110048;
  v2[1] = HIDWORD(v5);
  *((volatile uint8_t *)v2 + 8) = 1;
  _frame.v8[2] = v4;
  _frame.v8[6] = v3 - 4;
  _frame.v7[0] = 12;
  _frame.v8[4] = 1596;
  _frame.v8[0] = 124;
  _frame.v8[3] = 0;
  rx_handle_packet((void *)(v2), (int)_frame.v7, 0x20u);
  return log_event((int)_frame.v8, *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 28), *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 32));
}



// get_noise_floor @ 0x11004c
volatile uint32_t *get_noise_floor() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_1100A0);
  result = clear_stats_buf((volatile uint32_t *)dword_110094);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6) )
  {
    v2 = (void *)(uintptr_t)(off_110098);
    v3 = dword_11009C;
    v4 = dword_110094;
    v5 = 0;
    do
    {
      v6 = tx_irq_handler(v3, 0x63Cu);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// get_current_channel @ 0x1100a4
volatile uint32_t *get_current_channel() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1100D8);
  result = clear_stats_buf((volatile uint32_t *)dword_1100DC);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) )
  {
    v2 = dword_1100E0;
    v3 = dword_1100DC;
    v4 = 0;
    do
    {
      v5 = tx_irq_handler(v2, 0xCu);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// get_core_temp @ 0x1100e4
volatile uint32_t *get_core_temp() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_110138);
  result = clear_stats_buf((volatile uint32_t *)dword_11012C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (void *)(uintptr_t)(off_110130);
    v3 = dword_110134;
    v4 = dword_11012C;
    v5 = 0;
    do
    {
      v6 = tx_irq_handler(v3, 0x6B8u);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// get_tx_power @ 0x11013c
volatile uint32_t *get_tx_power() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_110170);
  result = clear_stats_buf((volatile uint32_t *)dword_110174);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_110178;
    v3 = dword_110174;
    v4 = 0;
    do
    {
      v5 = tx_irq_handler(v2, 0x7Cu);
      result = (volatile uint32_t *)wlan_ioctl_handler_1(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// mmio_read_0 @ 0x11017c
int mmio_read_0() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1101B0 = 1;
  }
  v0 = (volatile int *)off_1101B4;
  v1 = dword_1101B8;
  ++*(volatile uint32_t *)off_1101B4;
  result = (int)(uintptr_t)(list_pop(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1101B0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write_0 @ 0x1101bc
int mmio_write_0(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1101F4 = 1;
  }
  v2 = (volatile int *)off_1101F8;
  v3 = dword_1101FC;
  ++*(volatile uint32_t *)off_1101F8;
  result = wlan_ioctl_handler_1(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_1101F4;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_write_1 @ 0x110250
int mmio_write_1(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110290 = 1;
  }
  v2 = (volatile int *)off_110294;
  v3 = dword_110298;
  ++*(volatile uint32_t *)off_110294;
  result = wlan_ioctl_handler_1(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_11029C;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_110290;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_read_1 @ 0x1102a0
int mmio_read_1() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1102E0 = 1;
  }
  v0 = (volatile int *)off_1102E4;
  v1 = dword_1102E8;
  ++*(volatile uint32_t *)off_1102E4;
  result = (int)(uintptr_t)(list_pop(v1));
  if ( result )
    --*(volatile uint32_t *)off_1102EC;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1102E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write_2 @ 0x1102f0
int mmio_write_2(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110330 = 1;
  }
  v2 = (volatile int *)off_110334;
  v3 = dword_110338;
  ++*(volatile uint32_t *)off_110334;
  result = wlan_ioctl_handler_1(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_11033C;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_110330;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_read_2 @ 0x110340
int mmio_read_2() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110374 = 1;
  }
  v0 = (volatile int *)off_110378;
  v1 = dword_11037C;
  ++*(volatile uint32_t *)off_110378;
  result = (int)(uintptr_t)(list_pop(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_110374;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write_3 @ 0x110380
int mmio_write_3(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1103B8 = 1;
  }
  v2 = (volatile int *)off_1103BC;
  v3 = dword_1103C0;
  ++*(volatile uint32_t *)off_1103BC;
  result = wlan_ioctl_handler_1(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_1103B8;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// mac_tx_setup @ 0x1103c4
int mac_tx_setup(int result) {
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

  v1 = (void *)(uintptr_t)(off_1104C8);
  v2 = *(volatile uint16_t *)(result + 28);
  v3 = (volatile int *)off_1104CC;
  v4 = (void *)(uintptr_t)(off_1104F4);
  v5 = (void *)(uintptr_t)(off_1104F8);
  v6 = result;
LABEL_2:
  v7 = (volatile int *)off_1104D0;
  while ( v2 <= 1 )
  {
    v8 = (void *)(uintptr_t)(mmio_read_1());
    if ( !v8 )
    {
      result = debug_printf("rep: no rxmsg buffer, %d\r\n", *(volatile uint32_t *)off_1104E8);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return irq_disable_global_2(32);
    }
    v9 = (void *)(uintptr_t)(mmio_read_0());
    v10 = v9;
    if ( !v9 )
    {
      debug_printf(aRepRxmsgNoDesc);
      result = mmio_write_2(v8);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return irq_disable_global_2(32);
    }
    *v9 = (int)(uintptr_t)(v8);
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_1104D4 = 1;
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
        debug_printf(aRxmsgTailError);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(volatile int16_t **)off_1104D8 < 0 && *v4 )
      {
        irq_disable_mmio_write((int)aSdioFunc1H2dFr, (int)aSdioReplenishR, 261);
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
      v15 = *(volatile uint32_t *)off_1104D4;
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


// phy_calibrate @ 0x1104fc
int phy_calibrate(int a1, int a2) {
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

  v2 = (void *)(uintptr_t)(off_110620);
  v3 = (volatile int *)off_110624;
  v21 = *(volatile uint16_t *)(*(volatile uint32_t *)off_11061C + 48);
  mac_tx_setup(a2);
  v6 = *(volatile uint16_t *)(a2 + 12);
LABEL_2:
  v7 = (void *)(uintptr_t)(off_11064C);
  v8 = (void *)(uintptr_t)(off_110650);
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(volatile uint32_t *)(a1 + 8) + 16))(*(volatile uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      debug_printf("rep: no buffer, %d\r\n", *v7);
LABEL_23:
      if ( *(volatile uint16_t *)(a2 + 12) >= (unsigned int)*(volatile uint16_t *)(*(volatile uint32_t *)off_11061C + 50) )
        return 1;
LABEL_24:
      irq_disable_global_2(32);
      return 1;
    }
    v10 = (void *)(uintptr_t)(mmio_read_0());
    v11 = v10;
    if ( !v10 )
    {
      debug_printf(aRepNoDesc);
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
      *(volatile uint32_t *)off_110628 = 1;
    }
    v13 = (volatile int *)off_11062C;
    v14 = *(volatile uint32_t *)off_11062C + 1;
    *(volatile uint32_t *)off_11062C = v14;
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
      if ( **(volatile int16_t **)off_110630 < 0 && *(volatile uint32_t *)off_110634 )
      {
        irq_disable_mmio_write((int)aSdioFunc1H2dFr_0, (int)aHostSdioReplen, 400);
        v13 = (volatile int *)off_11062C;
        v14 = *(volatile uint32_t *)off_11062C;
      }
      *(volatile uint32_t *)off_110634 = (int)(uintptr_t)(v11);
    }
    v15 = *v3;
    v16 = *(volatile uint16_t *)(a2 + 12);
    *(volatile uint32_t *)(a2 + 4) = (int)(uintptr_t)(v11);
    v6 = (uint16_t)(v16 + 1);
    *(volatile uint16_t *)(a2 + 12) = v6;
    *v3 = (uint16_t)(v15 + 1);
    *(volatile uint32_t *)off_110638 = 1;
    if ( v14 )
    {
      v17 = (void *)(uintptr_t)(off_110628);
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


// check_hardware_ready @ 0x110654
int check_hardware_ready() {
  mmio_write_reg();
  return 1;
}



// event_queue_init @ 0x110660
int event_queue_init(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_110694);
  v2 = (void *)(uintptr_t)(off_110698);
  *(volatile uint32_t *)off_110694 = 0;
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
  phy_calibrate((int)v1, (int)v2);
  return 1;
}



// rx_task @ 0x110b20
int rx_task() {
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

  v0 = (void *)(uintptr_t)(off_110C04);
  v1 = (volatile int *)off_110BFC;
  v2 = (volatile int *)off_110C00;
  v3 = (volatile char *)off_110C04 + 3080;
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
            ((int (*)())mmio_write_0)();
            v9 = v7;
            if ( v7 >= v5 )
              goto LABEL_8;
          }
          v17 = v10;
          dma_ring_alloc_1();
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(v8 + (*(volatile uint8_t *)(v17 + 11) & 0x7F)) & 0xFFFFu);
          ((int (*)())mmio_write_0)();
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
      list_pop((int)(uintptr_t)(v3));
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
    *(volatile uint32_t *)off_110C00 = 1;
  }
  ++*v1;
  result = irq_disable_global_3(128);
  if ( *v1 )
  {
    v15 = *v1 - 1;
    v16 = *(volatile uint32_t *)off_110C00;
    *v1 = v15;
    if ( !v15 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_write_reg @ 0x110ce4
int mmio_write_reg() {
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

  v0 = (void *)(uintptr_t)(off_110E88);
  *(volatile uint32_t *)off_110E84 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (volatile unsigned int *)off_110EB8;
    v20 = (volatile unsigned int *)off_110E9C;
    *(volatile uint32_t *)off_110EB8 = *(volatile uint32_t *)off_110EB8 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)ipc_send_command();
  }
  else
  {
    alloc_tx_event(aWaitCmd5);
    do
    {
      while ( (*(volatile uint32_t *)off_110E90 & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110E90 < 0 );
    v1 = (void *)(uintptr_t)(off_110E90);
    *(volatile uint32_t *)off_110E90 = dword_110E94;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(volatile uint32_t *)off_110E88 & 1) == 0 )
        ;
    }
    v2 = (volatile int *)off_110E98;
    v3 = (volatile unsigned int *)off_110E9C;
    v4 = (volatile unsigned int *)off_110EA0;
    v5 = (void *)(uintptr_t)(off_110EA4);
    v6 = (void *)(uintptr_t)(off_110EA8);
    v7 = (void *)(uintptr_t)(off_110EAC);
    *(volatile uint32_t *)off_110E88 = 2;
    v8 = dword_110EB0;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = (void *)(uintptr_t)(off_110EB4);
    *v5 &= v8;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = (void *)(uintptr_t)(off_110EB8);
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = (void *)(uintptr_t)(off_110EBC);
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_110EC0;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    alloc_tx_event(aWaitIoEnable);
    v13 = (volatile int *)off_110E90;
    v14 = dword_110E94;
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
    v15 = (void *)(uintptr_t)(off_110E90);
    do
    {
      while ( (*(volatile uint32_t *)off_110E90 & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110E90 < 0 );
    v16 = (void *)(uintptr_t)(off_110E90);
    *(volatile uint32_t *)off_110E90 = dword_110EC8;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = alloc_tx_event(aIoEnable, v16, v15, 4 * *v16);
    *(volatile uint32_t *)off_110E9C = *(volatile uint32_t *)off_110E9C & 0xFFFFF000 | 0x960;
  }
  v18 = (void *)(uintptr_t)(off_110ED4);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_110ED0 + 2) + 324) = off_110ED8;
  v18[2] = 2;
  return result;
}


// sub_110edc @ 0x110edc
int sub_110edc(int a1, int a2, int a3) {
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
    *(volatile uint32_t *)off_110FCC = 1;
  }
  v6 = (volatile int *)off_110FF8;
  v7 = *(volatile uint8_t **)off_110FD0;
  v8 = *(volatile uint32_t *)off_110FF8 + 1;
  *(volatile uint32_t *)off_110FF8 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = (void *)(uintptr_t)(off_110FE8);
    if ( *(volatile uint8_t *)off_110FE8 )
    {
      v19 = (void *)(uintptr_t)(off_110FEC);
      v20 = *((volatile uint8_t *)off_110FEC + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = get_mmio_state((void *)(uintptr_t)(dword_110FF0));
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        mmio_clear_bit_1(v20);
      else
        mmio_set_bit_1(v20);
    }
    else
    {
      v17 = (volatile uint8_t *)off_110FEC;
      if ( *((volatile uint8_t *)off_110FEC + 369) )
        result = mmio_clear_bit_1(1);
      else
        result = mmio_set_bit_1(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = mem_copy_util((void *)(uintptr_t)(dword_110FF0), *((volatile uint32_t *)off_110FF4 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = (void *)(uintptr_t)(off_110FD4);
  *(volatile uint32_t *)off_110FD4 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(volatile uint32_t *)off_110FD8 )
  {
    v11 = (void *)(uintptr_t)(off_110FDC);
    v12 = (void *)(uintptr_t)(off_110FE0);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_110FDC + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = (void *)(uintptr_t)(off_110FE0);
    *(volatile uint32_t *)off_110FD8 = a1;
    v11 = (void *)(uintptr_t)(off_110FDC);
    *v15 += a2;
  }
  *(volatile uint32_t *)off_110FE4 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(volatile uint32_t *)off_110FCC;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}



// tx_desc_set_control @ 0x110ffc
volatile uint32_t * tx_desc_set_control(volatile uint32_t *result, int a2, int a3, uint16_t a4, int a5) {
  result[2] = dword_111018 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}



// sub_11101c @ 0x11101c
int sub_11101c(int a1) {
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
    *(volatile uint32_t *)off_1110FC = 1;
  }
  v2 = (volatile int *)off_111100;
  v3 = *(volatile uint8_t **)off_111104;
  v4 = *(volatile uint32_t *)off_111100 + 1;
  *(volatile uint32_t *)off_111100 = v4;
  if ( *v3 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_111120);
    v12 = (void *)(uintptr_t)(off_111124);
    if ( *(volatile uint8_t *)off_111120 )
    {
      v14 = *((volatile uint8_t *)off_111124 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
if ( get_mmio_state((void *)(uintptr_t)(dword_111128)) ) goto LABEL_18;
      if ( v12[369] )
        mmio_clear_bit_1(v14);
      else
        mmio_set_bit_1(v14);
    }
    else
    {
      if ( *((volatile uint8_t *)off_111124 + 369) )
        mmio_clear_bit_1(1);
      else
        mmio_set_bit_1(1);
      v13 = (uint8_t)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    mem_copy_util((void *)(uintptr_t)(dword_111128), *((volatile uint32_t *)off_11112C + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = (void *)(uintptr_t)(off_111108);
  *(volatile uint32_t *)off_111108 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(volatile uint32_t *)off_11110C )
  {
    result = dword_111110;
    v7 = (void *)(uintptr_t)(off_111114);
    *(volatile uint32_t *)(*(volatile uint32_t *)(dword_111110 + 6164) + 4) = a1;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_111114);
    *(volatile uint32_t *)off_11110C = a1;
    result = dword_111110;
  }
  ++*v7;
  v8 = (void *)(uintptr_t)(off_11111C);
  *(volatile uint8_t *)off_111118 |= 2u;
  *v8 = 64;
  *(volatile uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(volatile uint32_t *)off_1110FC;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}



// kmalloc @ 0x111130
int kmalloc(char a1, volatile char *a2, unsigned int a3, int a4) {
  volatile uint32_t *v7; // r0
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r6
  int v10; // r2
  int v11; // r3

  v7 = is_chip_ready(4);
  if ( !v7 )
    return debug_printf(aErrNoMsgPkt);
  v8 = v7;
  v9 = (void *)(uintptr_t)(mmio_read_0());
  if ( v9 )
  {
    *(volatile uint8_t *)v8 = a3;
    *((volatile uint8_t *)v8 + 1) = BYTE1(a3) & 0xF;
    *((volatile uint8_t *)v8 + 2) = a1;
    *((volatile uint8_t *)v8 + 3) = 0;
    memcpy((volatile char *)v8 + 4, a2, a3);
    v10 = v9[2];
    v11 = dword_1111A8;
    v9[1] = 0;
    *v9 = (int)(uintptr_t)(v8);
    v9[2] = (uint16_t)(a3 + 4) | v11 & v10 | 0x80000000;
    return sub_11101c((int)v9);
  }
  else
  {
    debug_printf(aErrSendMsgCfgT);
    return wait_for_state(v8);
  }
}


// get_init_flag @ 0x1111b4
int get_init_flag() {
  if ( *(volatile uint8_t *)off_1111C4 )
    return 1;
  else
    return *(volatile uint8_t *)off_1111C8;
}



// timer_get_raw @ 0x1111cc
int timer_get_raw(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (volatile int *)off_111248;
  v2 = a1 & 0x3FFFFF;
  v3 = *(volatile uint32_t *)off_111248 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(volatile uint32_t *)off_111248 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(volatile uint32_t *)off_111248 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return debug_printf("sdio pahse cfg %x\n", *(volatile uint32_t *)off_111248 & 0x3FFFFF);
}


