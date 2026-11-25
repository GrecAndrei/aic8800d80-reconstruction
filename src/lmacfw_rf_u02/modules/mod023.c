// ke_timer_check @ 0x11c88c
int ke_timer_check() {
  int v0; // r0
  int v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( flash_write_byte(2u) != 3 )
  {
    v0 = flash_write_byte(2u);
    dispatch_event_handler_1("end st=%d\n", v0);
  }
  if ( **(volatile int16_t **)off_11C91C < 0 && flash_write_byte(2u) != 3 )
    flash_ctrl_init((int)aKeStateGetTask_1, (int)aMmScanChannelE, 201);
  v1 = off_11C920;
  v2 = *(volatile uint32_t *)off_11C920;
  v3 = *(volatile uint8_t *)(*(volatile uint32_t *)off_11C920 + 367);
  v4 = (uint8_t)(*(volatile uint8_t *)(off_11C920 + 0xA) + 1);
  *(volatile uint8_t *)(off_11C920 + 0xA) = v4;
  if ( v3 <= v4 || *(volatile uint8_t *)(v1 + 0xB) )
  {
    isr_forward((int)(uintptr_t)((volatile char *)(v2 - 12)));
    v5 = *(volatile uint16_t *)(v1 + 8);
    if ( *(volatile uint8_t *)(v1 + 0xB) )
    {
      tx_buf_alloc(0, v5);
      *(volatile uint8_t *)(v1 + 0xB) = 0;
    }
    else
    {
      ke_evt_handler(2050, v5, 2);
    }
    flash_erase_sector(2u, 0);
    return 0;
  }
  else
  {
    queue_remove();
    return 0;
  }
}


// ke_timer_update @ 0x11c92c
int ke_timer_update() {
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(volatile uint32_t *)off_11C990;
  v1 = *(volatile uint8_t *)(off_11C990 + 0xA);
  if ( flash_write_byte(2u) != 2 )
  {
    v2 = flash_write_byte(2u);
    dispatch_event_handler_1("start st=%d\n", v2);
  }
  if ( **(volatile int16_t **)off_11C998 < 0 && flash_write_byte(2u) != 2 )
    flash_ctrl_init((int)aKeStateGetTask_2, (int)aMmScanChannelS, 163);
  if ( (*(volatile uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    ll_rx_handler();
  flash_erase_sector(2u, 3);
  return 0;
}


// radio_send_command @ 0x11c9a4
int radio_send_command(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v6; // r4
  int v7; // r0
  int v8; // r2

  v6 = (volatile uint8_t *)ke_msg_send_1(2049, a4, a3, 1);
  v7 = flash_write_byte(2u);
  check_interrupt_flag(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( flash_write_byte(2u) )
  {
    *v6 = 8;
    rx_irq_handler_1((int)v6);
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_11CA28 < 0 && !*(volatile uint8_t *)(a2 + 367) )
      flash_ctrl_init((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = off_11CA2C;
    *v6 = 0;
    *(volatile uint32_t *)v8 = a2;
    *(volatile uint8_t *)(v8 + 0xA) = 0;
    *(volatile uint16_t *)(v8 + 8) = a4;
    aes_encrypt(a2);
    rx_irq_handler_1((int)v6);
    return 1;
  }
}


// rf_channel_compare @ 0x11ca38
int rf_channel_compare(volatile uint16_t *a1) {
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_11CA90 + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}



// ke_timer_flush @ 0x11ca94
int ke_timer_flush() {
  int result; // r0
  volatile uint32_t *v1; // r3

  memset((volatile int *)dword_11CABC, 0, 0xCu);
  result = flash_erase_sector(2u, 0);
  v1 = (void *)(uintptr_t)(off_11CAC0);
  *(volatile uint32_t *)off_11CAC0 = dword_11CAC4;
  v1[2] = (int)(uintptr_t)(v1 + 5);
  v1[4] = 0;
  v1[1] = 0;
  return result;
}


// queue_remove @ 0x11cac8
int queue_remove() {
  unsigned int v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r1
  int v9; // r0
  int v10; // r1

  v0 = off_11CB74;
  v1 = *(volatile uint32_t *)off_11CB74;
  v2 = *(volatile uint32_t *)off_11CB74 + 6 * *(volatile uint8_t *)(off_11CB74 + 0xA);
  v3 = 6 * *(volatile uint8_t *)(off_11CB74 + 0xA);
  if ( (*(volatile uint8_t *)(v2 + 3) & 5) != 0 )
  {
    v4 = *(volatile uint32_t *)(*(volatile uint32_t *)off_11CB78 + 20);
    if ( !v4 )
      v4 = dword_11CB7C;
  }
  else
  {
    v9 = rf_channel_compare((volatile uint16_t *)(*(volatile uint32_t *)off_11CB74 + 6 * *(volatile uint8_t *)(off_11CB74 + 0xA)));
    v4 = 30000;
    if ( v9 )
      v4 = v9;
  }
  rf_status_read((void *)(uintptr_t)(v2), v4, *(volatile uint8_t *)(v1 + 366));
  v5 = *(volatile uint32_t *)(v0 + 4);
  if ( v5 )
  {
    v6 = *(volatile uint8_t *)(v2 + 2);
    v7 = *(volatile uint16_t *)(v1 + v3);
    if ( *(volatile uint8_t *)(v2 + 2) )
    {
      if ( v6 == 1 && (v10 = v7 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(volatile uint8_t *)(v5 + 2) = (unsigned int)(((unsigned int)dword_11CB80 * (uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(volatile uint8_t *)(v5 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v7 - 2412) <= 0x48 )
      {
        if ( v7 == 2484 )
        {
          *(volatile uint8_t *)(v5 + 2) = 14;
          return flash_erase_sector(2u, 2);
        }
        v6 = (v6 & ~0xFFu) | ((uint8_t)((unsigned int)(((unsigned int)dword_11CB80 * (uint64_t)(unsigned int)(v7 - 2407)) >> 32) >> 2) & 0xFFu);
      }
      *(volatile uint8_t *)(v5 + 2) = v6;
    }
  }
  return flash_erase_sector(2u, 2);
}


// aes_encrypt @ 0x11cb84
int aes_encrypt(int a1) {
  volatile char *v1; // r4
  volatile uint32_t *v2; // r6
  int result; // r0

  v1 = (volatile char *)off_11CBC0;
  v2 = (void *)(uintptr_t)(off_11CBC4);
  memcpy((void *)(uintptr_t)(off_11CBC0), (void *)(uintptr_t)(*(volatile uint32_t *)(a1 + 360)), *(volatile uint16_t *)(a1 + 364));
  v2[1] = (int)(uintptr_t)(memchr(v1, *(volatile uint16_t *)(*v2 + 364)));
  result = queue_remove();
  *(volatile uint32_t *)&v1[-8] = *(volatile uint32_t *)&v1[-12] - 1 + *(volatile uint16_t *)(a1 + 364);
  *((volatile uint32_t *)v1 - 1) = 0;
  return result;
}



// ll_rx_handler @ 0x11cbc8
void ll_rx_handler() {
  int v0; // r5
  int v1; // r8
  volatile char *v2; // r6
  int v3; // r7
  int v4; // r0
  int v5; // r0
  volatile char *v6; // r2
  int v7; // r1
  volatile uint16_t *v8; // lr
  int v9; // r3
  int16_t v10; // r4
  volatile int *v11; // r9
  int v12; // r12
  int16_t v13; // r10
  int v14; // r0
  int v15; // r0
  int16_t v16; // r10
  int v17; // r0
  int v18; // r3
  char v19; // t1
  int v20; // r2
  int v21; // r3
  int v22; // [sp+0h] [bp-Ch]
  int v23; // [sp+4h] [bp-8h]

  v0 = *(volatile uint32_t *)off_11CCF8;
  v22 = *((volatile uint8_t *)off_11CCF8 + 10);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11CCF8 + 368) )
  {
    v1 = dword_11CCFC + 224 * *(volatile uint8_t *)(*(volatile uint32_t *)off_11CCF8 + 366) + 88;
    v2 = (volatile char *)(v0 + 253);
    v3 = 0;
    v23 = 2 * *((volatile uint8_t *)off_11CCF8 + 10);
    do
    {
      if ( *(volatile uint8_t *)(v0 + 2 * (v23 + v22) + 2) )
      {
        v4 = 1;
      }
      else
      {
        v4 = *(volatile uint8_t *)(v0 + 369);
        if ( *(volatile uint8_t *)(v0 + 369) )
          v4 = 1;
      }
      v5 = (int)(uintptr_t)(call_global_185c7c(v4, *(volatile uint16_t *)(v0 + 364) + (uint8_t)*(v2 - 1) + 26));
      v6 = v2;
      v7 = v5;
      if ( !v5 )
        break;
      v8 = (void *)(uintptr_t)(off_11CD04);
      v9 = *(volatile uint32_t *)(v5 + 28);
      v10 = *((volatile uint16_t *)off_11CD04 + 70);
      v11 = (volatile int *)off_11CD08;
      v12 = *(volatile uint32_t *)(v5 + 32);
      v13 = *((volatile uint16_t *)off_11CD08 + 2);
      *(volatile uint32_t *)(v9 + 114) = *(volatile uint32_t *)v1;
      v14 = *v11;
      v11 = (void *)(uintptr_t)(((uintptr_t)(v11) & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v1 + 4)) & 0xFFFFu));
      *(volatile uint32_t *)(v9 + 108) = v14;
      ++v10;
      v15 = *(volatile uint32_t *)(v0 + 352);
      *(volatile uint16_t *)(v9 + 112) = v13;
      v16 = *(volatile uint16_t *)(v0 + 356);
      *(volatile uint16_t *)(v9 + 118) = (uint16_t)v11;
      *(volatile uint32_t *)(v9 + 120) = v15;
      *(volatile uint8_t *)(v9 + 104) = 64;
      *(volatile uint16_t *)(v9 + 124) = v16;
      *(volatile uint8_t *)(v9 + 105) = 0;
      *(volatile uint8_t *)(v9 + 106) = 0;
      *(volatile uint8_t *)(v9 + 107) = 0;
      v8[70] = v10;
      *(volatile uint8_t *)(v9 + 128) = 0;
      *(volatile uint8_t *)(v9 + 129) = *(v2 - 1);
      v17 = (uint8_t)*(v2 - 1);
      *(volatile uint16_t *)(v9 + 126) = 16 * v10;
      if ( v17 )
      {
        v18 = v9 + 129;
        do
        {
          v19 = *v6++;
          *(volatile uint8_t *)++v18 = v19;
        }
        while ( v6 != &v2[v17] );
      }
      v20 = *(volatile uint16_t *)(v0 + 364);
      v21 = *(volatile uint32_t *)(v12 + 28);
      *(volatile uint32_t *)(v12 + 20) = dword_11CD00;
      *(volatile uint32_t *)(v12 + 28) = v21 - v20;
      *(volatile uint32_t *)(v7 + 44) = 0;
      *(volatile uint32_t *)(v7 + 48) = 0;
      *(volatile uint8_t *)(v7 + 15) = *(volatile uint8_t *)(v0 + 366);
      *(volatile uint8_t *)(v7 + 16) = -1;
      wlan_tx_submit(v7, 5);
      ++v3;
      v2 += 33;
    }
    while ( *(volatile uint8_t *)(v0 + 368) > v3 );
  }
}



// tx_buf_alloc @ 0x11cd0c
volatile uint32_t * tx_buf_alloc(char a1, uint16_t a2) {
  volatile char *v3; // r4

  v3 = (volatile char *)ke_msg_send_1(2052, a2, 2, 1);
  check_interrupt_flag(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return rx_irq_handler_1((int)v3);
}


// rf_get_tx_entry @ 0x11cd3c
int rf_get_tx_entry() {
  return *(volatile uint32_t *)off_11CD4C + 6 * *((volatile uint8_t *)off_11CD4C + 10);
}



// rf_get_tx_power @ 0x11cd50
int rf_get_tx_power(int a1) {
  if ( (*(volatile uint8_t *)(a1 + 3) & 5) != 0 )
    return *(volatile uint32_t *)(*(volatile uint32_t *)off_11CD64 + 20);
  else
    return rf_channel_compare((volatile uint16_t *)a1);
}



// rf_read_rssi @ 0x11cd68
int rf_read_rssi() {
  int result; // r0

  if ( **(volatile int16_t **)off_11CDA0 < 0 && *(volatile uint32_t *)off_11CDA8 << 28 )
    return ke_int_lock_1((int)aNxmacCurrentSt, (int)aHalMachwIdleIr, 105);
  if ( (*(volatile uint32_t *)off_11CDA4 & 0x80) != 0 )
  {
    *(volatile uint32_t *)off_11CDA4 &= ~0x80u;
    return set_busy_flag_alt(0x2000000);
  }
  return result;
}


// rf_set_frequency @ 0x11cdb8
unsigned int rf_set_frequency(unsigned int result) {
  volatile unsigned int *v1; // r6
  unsigned int v2; // r5
  int v3; // r2
  int v4; // r7
  int v5; // r8
  unsigned int v6; // r4
  uint64_t v7; // r0
  uint64_t v8; // r0
  unsigned int v9; // r0
  uint64_t v10; // r0
  uint64_t v11; // r0
  volatile unsigned int *v12; // r2
  unsigned int v13; // r3
  int v14; // r3
  volatile uint32_t *v15; // r6
  int v16; // r2
  int v17; // r0
  volatile unsigned int *v18; // r1
  volatile unsigned int *v19; // r2
  int v20; // r1
  uint64_t v21; // r0
  unsigned int v22; // r0
  uint64_t v23; // r0
  volatile unsigned int *v24; // r7
  uint64_t v25; // r0

  v1 = (volatile unsigned int *)off_11CFE0;
  v2 = (uint8_t)*(volatile uint32_t *)off_11CFE0;
  if ( result != v2 )
  {
    v3 = dword_11CFE4;
    v4 = dword_11CFE8;
    v5 = dword_11D018;
    *(volatile uint32_t *)off_11D014 = ((0xF0 / result) << 8) & 0xF00 | *(volatile uint32_t *)off_11D014 & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = parse_data_field(*(volatile uint64_t *)&dword_11CFD8);
      v22 = ((int (*)(uint64_t))aeabi_d2iz)(v21);
      v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_11D010) << 32);
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (volatile unsigned int *)off_11CFF4;
      v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v25 = parse_data_field(v23);
      *v24 = dword_11CFF8 & (((int (*)(uint64_t))aeabi_d2iz)(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = aeabi_i2d(result);
      v8 = ((uint64_t (*)())aeabi_dadd)(v7, *(volatile uint64_t *)&dword_11CFD0);
      v9 = ((int (*)(uint64_t))aeabi_dmul)(v8);
      v10 = ((uint64_t (*)())aeabi_d2f)(v9);
      v11 = parse_data_field(v10);
      *v1 = v4 & (((int (*)(uint64_t))aeabi_d2iz)(v11) << 18) | *v1 & v5;
    }
    v12 = (volatile unsigned int *)off_11CFF4;
    *(volatile uint32_t *)off_11CFEC = dword_11CFF0 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_11CFEC >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_11CFEC & 0xFF0000FF;
    *v12 = dword_11CFF8 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(volatile uint32_t *)off_11CFFC & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(volatile uint32_t *)off_11CFFC = v14;
    }
    v15 = (void *)(uintptr_t)(off_11D000);
    v16 = dword_11CFF0;
    v17 = dword_11D004;
    v18 = (volatile unsigned int *)off_11D008;
    *(volatile uint32_t *)off_11D000 = dword_11CFF0 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_11D000 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_11D000 & dword_11D004;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (volatile unsigned int *)off_11D00C;
    v20 = dword_11CFF8;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}


// rf_cal_trim_check @ 0x11d01c
volatile uint32_t *rf_cal_trim_check() {
  volatile uint32_t *v0; // r2
  volatile unsigned int v1; // r3
  int v2; // r4
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r5
  int v5; // r1
  volatile uint32_t *result; // r0
  volatile int *v7; // r3
  int v8; // r3

  if ( **(volatile int16_t **)off_11D094 < 0 && !(*(volatile uint32_t *)off_11D0AC << 28) )
    return (volatile uint32_t *)ke_int_lock_1((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11D098 = 1;
  }
  v0 = (void *)(uintptr_t)(off_11D0A0);
  v1 = REG_4032_0120;
  v2 = *(volatile uint32_t *)off_11D0A0;
  v3 = (void *)(uintptr_t)(off_11D0A4);
  v4 = (void *)(uintptr_t)(off_11D0A8);
  v5 = *(volatile uint32_t *)off_11D0A0 + 1;
  *(volatile uint32_t *)off_11D0A0 = v5;
  *v3 = v1 + 25000;
  result = v3 + 8146;
  *v4 = 128;
  *result |= 0x80u;
  *(v4 - 8212) = 0;
  if ( v5 )
  {
    v7 = (volatile int *)off_11D098;
    *v0 = v2;
    v8 = *v7;
    if ( !v2 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}


// rf_cmd_strobe @ 0x11d0b8
int rf_cmd_strobe() {
  volatile uint32_t *v0; // r2
  unsigned int v1; // r0
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  volatile int16_t **v4; // r1
  volatile char *v5; // r0
  volatile int *v6; // r3
  volatile uint32_t *v7; // r1
  int v8; // r2
  volatile int *v9; // r4
  int v10; // r5
  volatile uint8_t *v11; // r1
  volatile int *v12; // r3
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r4
  volatile unsigned int *v15; // r6
  volatile uint32_t *v16; // r2
  volatile uint32_t *v17; // r5
  int result; // r0
  volatile uint32_t *v19; // r1
  volatile uint8_t **v20; // r2
  volatile uint32_t *v21; // r4
  volatile uint32_t *v22; // r6
  int v23; // r0
  volatile unsigned int *v24; // r5
  struct __attribute__((packed)) { uint8_t v25; // [sp+6h] [bp-2h] BYREF
  uint8_t v26; // [sp+7h] [bp-1h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_11D2B0);
  *(volatile uint32_t *)off_11D2B0 = 1;
  while ( (uint8_t)*v0 )
    ;
  v1 = read_byte_register();
  rf_set_frequency(v1);
  v2 = (void *)(uintptr_t)(off_11D2B8);
  *(volatile uint32_t *)off_11D2B4 = dword_11D2BC;
  v3 = (void *)(uintptr_t)(off_11D2C0);
  *v2 = 0x80000000;
  v4 = (volatile int16_t **)off_11D2C4;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(volatile uint32_t *)off_11D2C8 < 0x13000000u )
    flash_ctrl_init(dword_11D314, dword_11D310, 284);
  v5 = (volatile char *)off_11D2C8;
  v6 = (volatile int *)off_11D2CC;
  v7 = (void *)(uintptr_t)(off_11D2C0);
  v8 = dword_11D2D4;
  *(volatile uint32_t *)off_11D2C8 = dword_11D2D0;
  *v6 = v8;
  v9 = (volatile int *)off_11D2D8;
  v10 = dword_11D2DC;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = (void *)(uintptr_t)(off_11D2E0);
  v12 = v6 - 8199;
  *(volatile uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = (void *)(uintptr_t)(off_11D2E4);
  v14 = (void *)(uintptr_t)(off_11D2C0);
  v15 = (volatile unsigned int *)off_11D2EC;
  *(volatile uint32_t *)off_11D2E8 = 12288;
  *v13 = 0;
  rf_get_rssi(&_frame.v26, &_frame.v25);
  v16 = (void *)(uintptr_t)(off_11D2F4);
  *(volatile uint32_t *)off_11D2F0 = (_frame.v26 << 8) | (_frame.v25 << 16) | _frame.v26;
  v17 = (void *)(uintptr_t)(off_11D2F8);
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = chip_info_nibble1_get();
  v19 = (void *)(uintptr_t)(off_11D2FC);
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (volatile uint8_t **)off_11D300;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(volatile uint32_t *)off_11D304 &= 0x80FFFFFF;
  v21 = (void *)(uintptr_t)(off_11D2C0);
  v22 = (void *)(uintptr_t)(off_11D308);
  *(volatile uint32_t *)off_11D2C0 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = sys_status_bit28_get();
    if ( result )
    {
      v23 = chip_info_nibble2_get();
      v24 = (volatile unsigned int *)off_11D318;
      result = v23 << 8;
      *(volatile uint32_t *)off_11D318 = result & 0x700 | *(volatile uint32_t *)off_11D318 & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = sys_status_bit21_get();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(volatile uint32_t *)off_11D308 & 0x20000) != 0 )
      {
        result = sys_status_bit30_get();
        if ( result )
          *(volatile uint32_t *)off_11D318 |= 2u;
      }
    }
  }
  *(volatile uint32_t *)off_11D30C |= 1u;
  return result;
}



// rf_cmd_cancel @ 0x11d31c
void *rf_cmd_cancel() {
  void *result; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  result = (void *)(uintptr_t)(off_11D33C);
  v1 = (void *)(uintptr_t)(off_11D340);
  v2 = (void *)(uintptr_t)(off_11D344);
  *(volatile uint32_t *)off_11D33C &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}



// rf_cmd_wait @ 0x11d348
volatile int *rf_cmd_wait() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r0
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r2
  volatile int *result; // r0
  volatile uint32_t *v5; // r6
  volatile uint32_t *v6; // r4
  int v7; // r5

  v0 = (void *)(uintptr_t)(off_11D3C0);
  v1 = (void *)(uintptr_t)(off_11D3C4);
  *(volatile uint32_t *)off_11D3BC &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = (void *)(uintptr_t)(off_11D3C4);
  v3 = (void *)(uintptr_t)(off_11D3C8);
  result = (volatile int *)off_11D3CC;
  v5 = (void *)(uintptr_t)(off_11D3D0);
  v6 = (void *)(uintptr_t)(off_11D3D4);
  v7 = dword_11D3D8;
  *(volatile uint32_t *)off_11D3C4 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v5 = -1;
  *result = v7;
  *v6 |= 0x80000000;
  result[4] |= 0x80000000;
  v2[8197] |= 0x80000000;
  *(v3 - 8208) |= 0x80u;
  return result;
}



// rf_shutdown @ 0x11d3dc
unsigned int rf_shutdown() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile int16_t **v2; // r5
  volatile int *v3; // r4
  int v4; // r3
  volatile int16_t *v5; // r2
  unsigned int result; // r0
  volatile uint32_t *v7; // r2

  v0 = (void *)(uintptr_t)(off_11D44C);
  v1 = (void *)(uintptr_t)(off_11D450);
  *(volatile uint32_t *)off_11D44C &= ~1u;
  v2 = (volatile int16_t **)off_11D454;
  v3 = (volatile int *)off_11D458;
  v4 = dword_11D45C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(volatile uint32_t *)off_11D464 << 28 )
  {
    flash_cmd_exec(dword_11D46C, dword_11D468, 472);
    v4 = *v3;
  }
  *(volatile uint32_t *)off_11D460 = v4 | v3[1];
  result = gpio_set_bit10(1);
  v7 = (void *)(uintptr_t)(off_11D450);
  *(volatile uint32_t *)off_11D450 = *(volatile uint32_t *)off_11D450 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}



// rf_irq_handler_2 @ 0x11d470
int rf_irq_handler_2() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r4
  int v3; // r1

  v0 = *(volatile uint32_t *)off_11D59C;
  *(volatile uint32_t *)off_11D5A0 = *(volatile uint32_t *)off_11D59C;
  if ( (v0 & 0x400) != 0 )
    rf_state_machine();
  result = v0 << 23;
  if ( (v0 & 0x100) != 0 )
    result = hw_timer_load();
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler_1(aErrorThereIsNo, v0 << 22);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x800) == 0 )
  {
    if ( (v0 & 0x10) == 0 )
      goto LABEL_8;
LABEL_23:
    mmio_irq_set(4);
    result = llm_pdu_tx_cfg(4u);
    if ( (v0 & 0x2F) == 0 )
      goto LABEL_13;
    goto LABEL_9;
  }
  result = set_busy_flag_alt(0x2000);
  if ( (v0 & 0x10) != 0 )
    goto LABEL_23;
LABEL_8:
  if ( (v0 & 0x2F) == 0 )
    goto LABEL_13;
LABEL_9:
  if ( *(volatile uint8_t *)off_11D5A4 )
  {
    v2 = (void *)(uintptr_t)(off_11D5C0);
    gpio_config(*((volatile uint8_t *)off_11D5C0 + 411));
    v3 = *((volatile char *)v2 + 411);
    *(volatile uint8_t *)(off_11D5C4 + 9) = v3;
    return dispatch_event_handler_1("update:%d\n", v3);
  }
  if ( *(volatile uint8_t *)off_11D5A8 )
  {
    result = *(volatile uint32_t *)off_11D5AC << 28;
    if ( result )
      *((volatile uint8_t *)off_11D5A8 + 6) = 1;
  }
LABEL_13:
  if ( **(volatile int16_t **)off_11D5B0 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}


// rf_cmd_set @ 0x11d5e4
int rf_cmd_set() {
  int v0; // r4
  int result; // r0

  v0 = *(volatile uint32_t *)off_11D730 & *(volatile uint32_t *)off_11D734;
  result = v0 << 29;
  *(volatile uint32_t *)((volatile char *)off_11D730 + 0xFFFFFFFC) = v0;
  if ( (v0 & 4) != 0 )
    result = rf_read_rssi();
  if ( (v0 & 8) != 0 )
    result = rf_irq_handler_2();
  if ( **(volatile int16_t **)off_11D738 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      return ke_int_lock_1((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else
    {
      result = v0 << 7;
      if ( (v0 & 0x1000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
      }
      else if ( (v0 & 0x2000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
      }
      else if ( (v0 & 0x100000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
      }
      else if ( (v0 & 0x8000000) != 0 )
      {
        return ke_int_lock_1((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
      }
    }
  }
  return result;
}


// rf_cmd_clear @ 0x11d778
void rf_cmd_clear(int a1, int a2) {
  int v2; // r4
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r1
  int v5; // r2
  int v6; // r3
  volatile uint32_t *v7; // r1
  volatile unsigned int v8; // r2
  signed int v9; // r3
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r5
  signed int v12; // r3
  volatile uint32_t *v13; // r4
  signed int v14; // r3
  signed int v15; // r3
  volatile uint32_t *v16; // r4
  unsigned int v17; // r2
  int v18; // r3

  v2 = *(volatile uint32_t *)dword_11D89C & *(volatile uint32_t *)dword_11D8A0;
  *(volatile uint32_t *)(dword_11D89C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (volatile uint32_t *)dword_11D8A4;
    v4 = (volatile uint32_t *)dword_11D8A8;
    v5 = *(volatile uint32_t *)dword_11D8A4;
    v6 = *(volatile uint32_t *)dword_11D8A8;
    if ( (v2 & 1) != 0 && !*(volatile uint8_t *)(dword_11D8AC + 0x24) )
    {
      *(volatile uint32_t *)dword_11D8A4 = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      dispatch_event_handler_1(aWf);
    }
    else
    {
      v7 = (volatile uint32_t *)dword_11D8A8;
      *(volatile uint32_t *)dword_11D8A4 = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      dispatch_event_handler_1(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(volatile uint32_t *)dword_11D8B4 & 1) != 0 )
    {
      *(volatile uint32_t *)dword_11D8B8 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (volatile uint32_t *)dword_11D8C4;
      v11 = (volatile uint32_t *)dword_11D8C8;
      *(volatile uint32_t *)dword_11D8C0 = *(volatile uint32_t *)dword_11D8C0 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (volatile uint32_t *)dword_11D8C8;
      *(volatile uint32_t *)dword_11D8B4 &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(volatile uint32_t *)dword_11D8C8 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (volatile uint32_t *)dword_11D8C8;
      *(volatile uint32_t *)dword_11D8B4 |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(volatile uint32_t *)dword_11D8B8 &= 0xFF9FFFFF;
      dispatch_event_handler_1(aUnlock, REG_4050_1000);
    }
    else
    {
      *(volatile uint32_t *)dword_11D8C4 |= 1u;
      dispatch_event_handler_1(aUnlock, a2);
    }
  }
}


// log_two_strings @ 0x11d8d4
int log_two_strings() {
  int v0; // r4

  v0 = dword_11D8EC;
  list_init_1((void *)(uintptr_t)(dword_11D8EC));
  return (int)(uintptr_t)(list_init_1((void *)(uintptr_t)(v0 + 8)));
}



