// hci_vendor_cmd_send @ 0x11ec94
int hci_vendor_cmd_send(int a1) {
  int v2; // r0
  int v3; // r1
  int v4; // r4

  v2 = ke_msg_alloc(139, 13, 0, 24);
  v3 = a1;
  v4 = v2;
  memcpy((void *)(uintptr_t)(v2), (void *)(uintptr_t)(v3), 24);
  return (int)(uintptr_t)(ke_msg_send_2(v4));
}



// hci_uart_dma_rx_start @ 0x11ecb8
int hci_uart_dma_rx_start() {
  volatile uint32_t *v0; // r4
  volatile int *v1; // r5
  int v2; // r1
  int v3; // r2
  volatile uint32_t *v4; // r3
  int v5; // r1
  int result; // r0
  int v7; // r2
  volatile uint32_t *v8; // r2
  volatile uint32_t *v9; // r3
  uint32_t _0[10]; // [sp+0h] [bp-18h] BYREF

  unknown_func_12d14c(16);
  v0 = (void *)(uintptr_t)(off_11ED40);
  v1 = (volatile int *)off_11ED44;
  v2 = 0;
  while ( (*v0 & 8) == 0 )
  {
    v3 = *v1;
    *v0 |= 1u;
    if ( v3 )
    {
      v9 = &_0[v2 + 6];
      v2 = (uint8_t)(v2 + 1);
      *(v9 - 6) = v3;
      if ( v2 == 4 || (*v0 & 8) != 0 )
      {
        _0[4] = 0;
        _0[5] = v2;
        hci_vendor_cmd_send((int)_0);
        v2 = 0;
      }
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11ED48 = 1;
  }
  v4 = (void *)(uintptr_t)(off_11ED4C);
  v5 = *(volatile uint32_t *)off_11ED4C;
  result = *(volatile uint8_t *)off_11ED50;
  v7 = *(volatile uint32_t *)off_11ED4C + 1;
  *(volatile uint32_t *)off_11ED4C = v7;
  if ( result )
  {
    result = *(volatile uint32_t *)off_11ED54 | 0x1000;
    *(volatile uint32_t *)off_11ED54 = result;
  }
  if ( v7 )
  {
    v8 = (void *)(uintptr_t)(off_11ED48);
    *v4 = v5;
    if ( !v5 )
    {
      if ( *v8 )
        __enable_irq();
    }
  }
  return result;
}



// timer_get_counter @ 0x11ed58
volatile uint64_t *timer_get_counter() {
  volatile uint64_t *result; // r0
  struct __attribute__((packed)) { uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]
  } _frame;
  _frame.v2 = *(volatile uint32_t *)off_11ED9C;
  _frame.v3 = *(volatile uint32_t *)dword_11EDA0;
  _frame.v4 = *(volatile uint32_t *)(dword_11EDA0 + 8 + 0xFFFFFFFC);
  _frame.v5 = *(volatile uint32_t *)(dword_11EDA0 + 8);
  result = rf_call_handler(&_frame.v1, 0);
  if ( (_frame.v2 & 0xF) == 2 )
    return (volatile uint64_t *)check_chip_mode((int)(uintptr_t)(&_frame.v1));
  return result;
}



// llc_aes_ccm_setup @ 0x11eda4
volatile int * llc_aes_ccm_setup(int a1) {
  int v2; // r5
  int v3; // r0
  volatile int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(volatile uint32_t *)(a1 + 572) )
  {
    v3 = (int)(uintptr_t)(mem_word_load(v2));
    scan_control(v3, 1);
  }
  result = memset((volatile int *)a1, 0, 0x2B8u);
  v5 = a1;
  do
  {
    *(volatile uint8_t *)(v5 + 452) = 33;
    *(volatile uint8_t *)(v5 + 453) = 33;
    v5 += 12;
  }
  while ( v5 != a1 + 108 );
  *(volatile uint8_t *)(a1 + 34) = -1;
  return result;
}



// ble_event_set @ 0x11edf0
int ble_event_set() {
  int v0; // r5
  int v1; // r7
  volatile uint32_t *v2; // r6
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r0
  int i; // r5
  volatile uint32_t *v6; // r4
  volatile uint32_t *v7; // r0
  int v8; // r4
  int v9; // r6
  int v10; // r5
  int v11; // r3
  int result; // r0
  int v13; // r3

  v0 = dword_11EEEC;
  v1 = dword_11EEE8;
  zero_8_bytes((volatile uint32_t *)dword_11EEE8);
  v2 = (volatile uint32_t *)(v0 + 22272);
  do
  {
    llc_aes_ccm_setup(v0 - 624);
    co_list_push_back(v1, (volatile uint32_t *)(v0 - 624));
    v3 = (volatile uint32_t *)(v0 - 40);
    do
    {
      zero_8_bytes(v3);
      v4 = v3 + 10;
      v3 += 2;
      zero_8_bytes(v4);
    }
    while ( v3 != (volatile uint32_t *)v0 );
    v0 = (int)(v3 + 174);
  }
  while ( v3 + 174 != v2 );
  for ( i = 2784; i != 3132; i += 87 )
  {
    v6 = v2 - 10;
    do
    {
      zero_8_bytes(v6);
      v7 = v6 + 10;
      v6 += 2;
      zero_8_bytes(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 174;
  }
  v8 = off_11EEF0;
  v9 = dword_11EEF4;
  v10 = dword_11EEF8;
  llc_aes_ccm_setup(off_11EEF0);
  *(volatile uint32_t *)(v8 + 0x20) = 0x20000000;
  *(volatile uint32_t *)(v8 + 0x150) = v9;
  *(volatile uint32_t *)(v8 + 0xBC) = v10;
  *(volatile uint8_t *)(v8 + 0x34) = 0;
  llc_aes_ccm_setup(v8 + 696);
  *(volatile uint32_t *)(v8 + 0x408) = v9 + 64;
  v11 = dword_11EEFC;
  *(volatile uint32_t *)(v8 + 0x374) = v10 + 1320;
  *(volatile uint32_t *)(v8 + 0x2D8) = v11;
  *(volatile uint8_t *)(v8 + 0x2EC) = 0;
  llc_aes_ccm_setup(v8 + 1392);
  *(volatile uint32_t *)(v8 + 0x6C0) = v9 + 128;
  *(volatile uint32_t *)(v8 + 0x590) = dword_11EF00;
  *(volatile uint8_t *)(v8 + 0x5A4) = 0;
  *(volatile uint32_t *)(v8 + 0x62C) = v10 + 2640;
  result = (int)(uintptr_t)(llc_aes_ccm_setup(v8 + 2088));
  v13 = dword_11EF04;
  *(volatile uint8_t *)(v8 + 0x85C) = 0;
  *(volatile uint32_t *)(v8 + 0x978) = v9 + 192;
  *(volatile uint32_t *)(v8 + 0x8E4) = v10 + 3960;
  *(volatile uint32_t *)(v8 + 0x848) = v13;
  return result;
}


// ble_event_wait @ 0x11ef08
int ble_event_wait(volatile int *a1, volatile uint8_t *a2) {
  int v3; // r8
  volatile uint32_t *v5; // r0
  volatile uint32_t *v6; // r4
  int v7; // r7
  volatile char *v8; // r2
  int v9; // r1
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  char v13; // r3
  int v14; // r0
  int v15; // r3
  int v16; // r2
  volatile uint32_t *v17; // r2
  volatile uint32_t *v18; // r3
  int v19; // r8
  int v20; // r1
  int v21; // r12
  int v22; // r2
  volatile unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r2
  volatile uint32_t *v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r1
  volatile uint32_t *v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r7
  volatile unsigned int v33; // r3
  volatile uint32_t *v35; // r0
  char v36; // r1
  int16_t v37; // r12
  int16_t v38; // r3
  int16_t v39; // r1
  int16_t v40; // r3
  int v41; // r1

  v3 = *((volatile uint8_t *)a1 + 25);
  v5 = mem_word_load(dword_11F100);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((volatile uint8_t *)a1 + 29) )
  {
    v35 = mem_word_load(dword_11F100);
    if ( !v35 )
    {
      co_list_push_back(dword_11F100, v6);
      return 1;
    }
    v6[11] = (int)(uintptr_t)(v35);
    v35[11] = (int)(uintptr_t)(v6);
    v36 = *((volatile uint8_t *)a1 + 30);
    v8 = (volatile char *)a1 + 18;
    v37 = *((volatile uint8_t *)a1 + 29);
    *(volatile uint32_t *)((volatile char *)v35 + 38) = *(volatile int *)((volatile char *)a1 + 18);
    *((volatile uint16_t *)v35 + 21) = *((volatile uint16_t *)a1 + 11);
    v7 = dword_11F104;
    v38 = ((1 << v36) - 1) << 8;
    v39 = *((volatile uint16_t *)v35 + 21) & ~v38;
    *((volatile uint16_t *)v35 + 21) = v39;
    v40 = v38 & (*((volatile uint16_t *)a1 + 11) - (v37 << 8)) | v39;
    v41 = dword_11F108 * (((int)v35 - v7) >> 3);
    *((volatile uint16_t *)v35 + 21) = v40;
    *((volatile uint8_t *)v35 + 35) = v41;
    *((volatile uint16_t *)v35 + 16) = -1;
  }
  else
  {
    v7 = dword_11F104;
    v8 = (volatile char *)a1 + 18;
  }
  v9 = *(volatile uint32_t *)v8;
  v10 = *a1;
  *((volatile uint16_t *)v6 + 21) = *((volatile uint16_t *)v8 + 2);
  *(volatile uint32_t *)((volatile char *)v6 + 38) = v9;
  v6[1] = v10;
  v11 = *((volatile uint8_t *)a1 + 24);
  v12 = dword_11F108;
  if ( v11 < 0x10 )
    v11 = (v11 & ~0xFFu) | ((uint8_t)(16) & 0xFFu);
  *((volatile uint8_t *)v6 + 28) = v11;
  *((volatile uint16_t *)v6 + 10) = *((volatile uint16_t *)a1 + 8);
  v6[4] = a1[2];
  v6[3] = a1[1];
  v6[6] = a1[3];
  v13 = v12 * (((int)v6 - v7) >> 3);
  *((volatile uint8_t *)v6 + 34) = *((volatile uint8_t *)a1 + 25);
  *a2 = v13;
  *((volatile uint8_t *)v6 + 35) = v13;
  check_status_bits(256, aSStaIdxD, aStaMgmtRegiste);
  v14 = dword_11F114;
  v15 = dword_11F114 + 1320 * v3;
  v16 = *(volatile uint8_t *)(v15 + 1224);
  v6[2] = 102400;
  if ( v16 )
    ++*(volatile uint8_t *)(v15 + 1226);
  *((volatile uint16_t *)v6 + 276) = -1;
  v17 = v6 + 138;
  v18 = v6;
  do
  {
    *((volatile uint16_t *)v17 + 1) = -1;
    v17 = (volatile uint32_t *)((volatile char *)v17 + 2);
  }
  while ( v17 != (volatile uint32_t *)((volatile char *)v6 + 570) );
  v19 = 1320 * v3;
  v20 = (uint8_t)*a2;
  *((volatile uint8_t *)v6 + 52) = 0;
  v21 = *(volatile uint32_t *)(v14 + v19 + 1208);
  v6[84] = dword_11F118 + (v20 << 6);
  if ( (v21 & 8) != 0 )
    v22 = (int)(v6 + 46);
  else
    v22 = v19 + 1200;
  if ( (v21 & 8) == 0 )
    v22 += v14;
  v6[47] = v22;
  v23 = (*(volatile uint32_t *)0x40501010u);
  v24 = v23 - 1000000;
  v25 = v23 - 500000;
  do
  {
    v18[111] = v24;
    v18[112] = v25;
    v18 += 3;
  }
  while ( v6 + 27 != v18 );
  if ( (v21 & 0x10) != 0 )
    v6[1] |= 8u;
  co_list_push_back(v14 + v19 + 240, v6);
  v6[145] = dword_11F120;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11F124 = 1;
  }
  v26 = (void *)(uintptr_t)(off_11F128);
  v27 = v6[11];
  v28 = *(volatile uint32_t *)off_11F128;
  v29 = *(volatile uint32_t *)off_11F128 + 1;
  *(volatile uint32_t *)off_11F128 = v29;
  *((volatile uint8_t *)v6 + 37) = 1;
  if ( v27 )
    *(volatile uint8_t *)(v27 + 37) = 1;
  if ( v29 )
  {
    v30 = (void *)(uintptr_t)(off_11F124);
    *v26 = v28;
    if ( !v28 )
    {
      if ( *v30 )
        __enable_irq();
    }
  }
  v31 = (uint8_t)*a2;
  if ( v31 <= 0x23 )
  {
    v32 = v7 + 696 * v31;
    v33 = (*(volatile uint32_t *)0x40501010u);
    *(volatile uint32_t *)(v32 + 664) = v33;
  }
  *((volatile uint8_t *)v6 + 668) = 0;
  return 0;
}


// llm_conn_calc_ptr @ 0x11f12c
int llm_conn_calc_ptr(unsigned int a1, int a2, int a3, int a4) {
  int v4; // r7
  int v5; // r8
  int v6; // r5
  int v7; // r9
  int v8; // r6
  int v9; // r3
  volatile uint32_t *v11; // r2
  unsigned int v12; // r3
  int v13; // r1
  int v14; // r0
  int v15; // r12
  int result; // r0
  int v17; // r8
  volatile int *v18; // r0
  int v19; // r2
  volatile int *v20; // r3
  int v21; // r3

  v4 = dword_11F270;
  v5 = dword_11F294;
  v6 = dword_11F270 + 696 * a1;
  v7 = *(volatile uint8_t *)(v6 + 34);
  v8 = 1320 * v7;
  v9 = dword_11F294 + 1320 * v7;
  if ( *(volatile uint8_t *)(v9 + 1224) )
    --*(volatile uint8_t *)(v9 + 1226);
  check_status_bits(256, "%s: sta_idx=%d\n", aStaMgmtUnregis, a1);
  cmd_handler_c(v8 + 240 + v5, (volatile uint32_t *)v6);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11F27C = 1;
  }
  v11 = (void *)(uintptr_t)(off_11F280);
  v12 = v4 + 696 * a1;
  v13 = *(volatile uint32_t *)off_11F280;
  v14 = *(volatile uint32_t *)(v12 + 44);
  v15 = *(volatile uint32_t *)off_11F280 + 1;
  *(volatile uint32_t *)off_11F280 = v15;
  *(volatile uint8_t *)(v12 + 37) = 0;
  if ( v14 )
  {
    *(volatile uint8_t *)(v14 + 37) = 0;
    if ( !v15 )
    {
LABEL_7:
      llc_aes_ccm_setup(v14);
      co_list_push_back(dword_11F284, *(volatile uint32_t **)(v4 + 696 * a1 + 44));
      goto LABEL_8;
    }
    v18 = (volatile int *)off_11F27C;
    *v11 = v13;
    v19 = *v18;
    if ( v13 )
    {
      v14 = *(volatile uint32_t *)(v12 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v15 )
      goto LABEL_8;
    v20 = (volatile int *)off_11F27C;
    *v11 = v13;
    v19 = *v20;
    if ( v13 )
      goto LABEL_8;
  }
  if ( v19 )
    __enable_irq();
  v14 = *(volatile uint32_t *)(v4 + 696 * a1 + 44);
  if ( v14 )
    goto LABEL_7;
LABEL_8:
  llc_aes_ccm_setup(v6);
  co_list_push_back(dword_11F284, (volatile uint32_t *)v6);
  result = get_phy_channel();
  if ( !result )
  {
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11F288)[102]) )
      result = mmio_update(v5 + v8);
    else
      result = write_phy_config(0xC2u);
  }
  if ( a1 <= 0x1F )
  {
    v17 = v5 + 1320 * v7;
    if ( *(volatile uint8_t *)(v17 + 106) == 2 && !*(volatile uint8_t *)(v17 + 1224) )
    {
      if ( !*(volatile uint8_t *)off_11F28C
        || (v21 = (uint8_t)(*(volatile uint8_t *)off_11F28C - 1), *(volatile uint8_t *)off_11F28C = v21, !v21) )
      {
        if ( *((volatile uint8_t *)off_11F290 + 18) + *((volatile uint8_t *)off_11F290 + 17) == 1 )
          return set_bt_irq_flag();
      }
    }
  }
  return result;
}


// llm_conn_set_flag @ 0x11f298
int llm_conn_set_flag(int a1, uint8_t a2) {
  int v2; // r4
  int v3; // r8
  volatile uint8_t *v4; // r7
  volatile int *v5; // r6
  int v7; // r9
  volatile int *v8; // r0
  int v9; // r0
  volatile int *v10; // r2
  int v11; // r3
  int result; // r0
  uint64_t v13; // kr00_8
  int v14; // r1
  int v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r3

  v2 = *(volatile uint8_t *)(a1 + 1);
  v3 = dword_11F3B4;
  v4 = (volatile uint8_t *)(dword_11F3B4 + 696 * v2);
  v4[162] = a2;
  v4[160] = *(volatile uint8_t *)(a1 + 40);
  v4[161] = *(volatile uint8_t *)a1;
  v5 = (volatile int *)(696 * v2 + 64 + v3);
  v7 = v4[34];
  v8 = memset(v5, 0, 0x48u);
  switch ( v4[160] )
  {
    case 0u:
    case 3u:
      v9 = scale_timer_value(v8);
      v10 = (volatile int *)(v3 + 696 * v2 + 136);
      *v10 = v9 & 0xFFFFFF;
      v10[1] = 0;
      break;
    case 1u:
      v18 = v3 + 696 * v2;
      *(volatile uint32_t *)(v18 + 144) = *(volatile uint32_t *)(a1 + 24);
      *(volatile uint32_t *)(v18 + 148) = *(volatile uint32_t *)(a1 + 28);
      *(volatile uint32_t *)(v18 + 152) = *(volatile uint32_t *)(a1 + 32);
      *(volatile uint32_t *)(v18 + 156) = *(volatile uint32_t *)(a1 + 36);
      *(volatile uint64_t *)(v18 + 136) = 0;
      break;
    case 4u:
      v16 = *(volatile uint8_t *)(dword_11F3B0 + 1320 * v7 + 106);
      v17 = v3 + 696 * v2;
      *(volatile uint64_t *)(v17 + 136) = *(volatile uint64_t *)&dword_11F3A0;
      if ( v16 == 2 )
        *(volatile uint64_t *)(v17 + 136) = *(volatile uint64_t *)&dword_11F3A8;
      break;
    default:
      *(volatile uint64_t *)(v3 + 696 * v2 + 136) = 0;
      break;
  }
  v11 = v3 + 696 * v2;
  v13 = *(volatile uint64_t *)(a1 + 8);
  result = *(volatile uint32_t *)(a1 + 12);
  v14 = *(volatile uint32_t *)(a1 + 16);
  *(volatile uint8_t *)(v11 + 163) = 1;
  v15 = *(volatile uint32_t *)(a1 + 20);
  *(volatile uint32_t *)(v11 + 184) = (int)(uintptr_t)(v5);
  *(volatile uint64_t *)(v11 + 164) = v13;
  *(volatile uint32_t *)(v11 + 172) = v14;
  *(volatile uint32_t *)(v11 + 176) = v15;
  *(volatile uint8_t *)(v11 + 180) = *(volatile uint8_t *)(a1 + 4);
  return result;
}



// llm_conn_reset_state @ 0x11f3b8
int llm_conn_reset_state(int result) {
  *(volatile uint8_t *)(result + 52) = 1;
  *(volatile uint8_t *)(result + 163) = 0;
  *(volatile uint32_t *)(result + 184) = 0;
  return result;
}



// llc_ccm_encrypt @ 0x11f3cc
int llc_ccm_encrypt(int a1, int a2, int a3) {
  int v3; // r10
  int v4; // r4
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v12; // [sp+4h] [bp-4h] BYREF

  v3 = *(volatile uint32_t *)(a2 + 572);
  if ( !v3 )
    return 0;
  v4 = 0;
  v8 = a2 + 572;
  do
  {
    v12 = 0;
    if ( !isr_flag_dispatch(a1) )
      break;
    if ( !bt_is_link_active(v3) )
      break;
    v10 = (int)(uintptr_t)(bt_handle_state_event(a1, a2, (void *)(&v12)));
    if ( v12 )
      break;
    if ( !v10 )
      v10 = (int)(uintptr_t)(mem_word_load(v8));
    v9 = *(volatile uint8_t *)(v10 + 27);
    *(volatile uint8_t *)(v10 + 97) = 0;
    ++v4;
    phy_radio_init(v10, v9);
    if ( a3 )
    {
      if ( v4 == a3 )
        break;
    }
    v3 = *(volatile uint32_t *)(a2 + 572);
  }
  while ( v3 );
  return v4;
}



// llc_ctrl_pdu_send @ 0x11f448
int llc_ctrl_pdu_send(int a1, int a2, int a3) {
  int v3; // r5
  int v7; // r10
  int v8; // r11
  int v9; // r3
  int v10; // r8
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v15; // [sp+4h] [bp-8h]

  v3 = 0;
  v7 = a2 + 624;
  v8 = a2 + 584;
  v15 = 0;
  while ( isr_flag_dispatch(a1) )
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = (uint8_t)v9;
      if ( *(volatile uint32_t *)(v7 + 8 * v9) )
      {
        v11 = (int)(uintptr_t)(mem_word_load(a2 + 8 * (v9 + 78)));
        goto LABEL_9;
      }
      if ( *(volatile uint32_t *)(v8 + 8 * v9) )
        break;
      if ( ++v9 == 4 )
        return v3;
    }
    v11 = (int)(uintptr_t)(mem_word_load(a2 + 8 * (v9 + 73)));
LABEL_9:
    if ( !v11 )
      break;
    v12 = a2;
    while ( !*(volatile uint32_t *)(v12 + 624) )
    {
      v13 = *(volatile uint32_t *)(v12 + 584);
      v12 += 8;
      if ( v13 )
        break;
      if ( a2 + 32 == v12 )
      {
        if ( !v15 )
          goto LABEL_15;
        break;
      }
    }
    v12 = *(volatile uint32_t *)(v11 + 72);
    *(volatile uint16_t *)(v12 + 108) |= 0x2000u;
    v15 = 1;
LABEL_15:
    ((int (*)())ll_conn_state_dispatch)(v11, v10, v12);
    ++v3;
    test_flag(v10);
    if ( a3 )
    {
      if ( v3 == a3 )
        break;
    }
  }
  return v3;
}



// llm_conn_active_check @ 0x11f4f4
int llm_conn_active_check(int result) {
  int v1; // r4
  volatile int *v2; // r2
  unsigned int v3; // r1
  volatile uint32_t *v4; // r3
  volatile uint32_t *v5; // r0
  int v6; // r1
  volatile int *v7; // r6
  volatile uint32_t *v8; // r5
  volatile unsigned int v9; // r8
  unsigned int v10; // r3
  volatile unsigned int v11; // r10
  volatile uint32_t *v12; // r9
  volatile uint32_t *v13; // r8
  unsigned int v14; // r3
  int v15; // r5
  int v16; // r3
  int v17; // r2
  volatile uint32_t *v18; // r5
  int v19; // r2
  int v20; // r3
  volatile uint32_t *v21; // r2
  int v22; // r1

  v1 = result;
  if ( *(volatile uint8_t *)(result + 1224) )
    result = (int)(uintptr_t)(llc_clear_evt_state(result));
  if ( *(volatile uint32_t *)(v1 + 72) )
    result = rx_validate_entry(v1);
  if ( (*(volatile uint32_t *)(v1 + 4) & 1) != 0 )
  {
    if ( (*(volatile uint32_t *)off_11F690 & 0x2000000) != 0 || (result = *(volatile uint32_t *)off_11F690 << 6, *((volatile uint8_t *)off_11F694 + 36)) )
    {
      result = check_status_bits(2, "M,%d\r\n", *(volatile uint8_t *)(v1 + 128));
      v2 = (volatile int *)off_11F69C;
      v3 = *((volatile uint8_t *)off_11F69C + 1);
      *(volatile uint32_t *)(v1 + 4) &= ~1u;
      *v2 = v3 > 1;
      if ( BYTE2(((volatile uint32_t *)(uintptr_t)off_11F6A0)[47]) )
      {
        if ( **(volatile uint8_t **)off_11F6A4 == 2 )
        {
          result = fatal_error_handler();
          v4 = (void *)(uintptr_t)(off_11F6A8);
          *(volatile uint32_t *)off_11F6A8 &= ~1u;
          *v4 &= ~0x80u;
          if ( *(volatile uint8_t *)(v1 + 128) > 9u )
          {
            v5 = (void *)(uintptr_t)(off_11F6AC);
            v6 = dword_11F6B0;
            *(volatile uint32_t *)off_11F690 &= ~4u;
            if ( (*v5 & v6) == 0 )
              process_global_167204();
            if ( *(volatile uint32_t *)off_11F6B4 << 28 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_11F6B8 = 1;
              }
              v7 = (volatile int *)off_11F6BC;
              v8 = (void *)(uintptr_t)(off_11F6B4);
              ++*(volatile uint32_t *)off_11F6BC;
              *v8 = 0;
              v9 = (*(volatile uint32_t *)0x40501010u);
              while ( *v8 << 28 )
              {
                v10 = (*(volatile uint32_t *)0x40501010u) - v9;
                if ( v10 > 0x7530 )
                  check_status_bits(2, aIdleErr, 30000);
              }
              v11 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(volatile uint32_t *)off_11F6C4 & *(volatile uint32_t *)off_11F6C8 & 4) == 0 )
              {
                v12 = (void *)(uintptr_t)(off_11F6C4);
                v13 = (void *)(uintptr_t)(off_11F6C8);
                do
                {
                  v14 = (*(volatile uint32_t *)0x40501010u) - v11;
                  v15 = *v12 & *v13;
                  if ( v14 > 0x7530 )
                    check_status_bits(2, aIdleIntErr);
                }
                while ( (v15 & 4) == 0 );
              }
              *(volatile uint32_t *)off_11F6D0 = 4;
              if ( *v7 )
              {
                v16 = *v7 - 1;
                v17 = *(volatile uint32_t *)off_11F6B8;
                *v7 = v16;
                if ( !v16 )
                {
                  if ( v17 )
                    __enable_irq();
                }
              }
            }
            v18 = (void *)(uintptr_t)(off_11F6D8);
            v19 = **(volatile int16_t **)off_11F6D4;
            v20 = *((volatile uint32_t *)off_11F6D8 + 1) | 0x200;
            *((volatile uint32_t *)off_11F6D8 + 1) = v20;
            if ( v19 < 0 )
            {
              if ( *(volatile uint32_t *)off_11F6B4 << 28 )
              {
                call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
                v20 = v18[1];
              }
            }
            v21 = (void *)(uintptr_t)(off_11F6B4);
            v22 = off_11F6E0;
            *(volatile uint32_t *)off_11F6DC = v20 | *v18;
            *v21 = 48;
            return link_get_connection_info(*(volatile uint8_t *)(v1 + 107), v22, v1);
          }
        }
      }
    }
  }
  return result;
}


// scan_active_get @ 0x11f6f0
void scan_active_get() {
  volatile uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((volatile uint8_t **)off_11F71C + 2);
  if ( !v0[106] && v0[108] && v0[117] )
  {
    v1 = (uint8_t)v0[118];
    if ( v1 <= 8 )
      *(volatile uint32_t *)off_11F720 = ((1 << v1) - 1) << 8;
  }
}



// ble_sched_init @ 0x11f724
int ble_sched_init() {
  volatile uint32_t *v0; // r8
  int v1; // r4
  void *v2; // r7
  int v3; // r6
  volatile uint32_t *v4; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11F788);
  memset((volatile int *)off_11F788, 0, 0x18u);
  zero_8_bytes(v0);
  v1 = dword_11F78C;
  v2 = (void *)(uintptr_t)(off_11F790);
  zero_8_bytes(v0 + 2);
  v3 = v1 + 5280;
  do
  {
    memset((volatile int *)v1, 0, 0x528u);
    *(volatile uint32_t *)(v1 + 52) = (int)(uintptr_t)(v2);
    *(volatile uint32_t *)(v1 + 56) = v1;
    *(volatile uint8_t *)(v1 + 106) = 5;
    *(volatile uint8_t *)(v1 + 109) = 127;
    *(volatile uint8_t *)(v1 + 110) = 127;
    v4 = (volatile uint32_t *)v1;
    v1 += 1320;
    result = co_list_push_back((int)v0, v4);
  }
  while ( v1 != v3 );
  *((volatile uint8_t *)v0 + 16) = -1;
  return result;
}


// ble_sched_poll @ 0x11f794
int ble_sched_poll() {
  volatile uint32_t *i; // r5
  volatile uint32_t *j; // r4
  int result; // r0

  for ( i = *((volatile uint32_t **)off_11F7BC + 2); i; i = (volatile uint32_t *)*i )
  {
    for ( j = (volatile uint32_t *)i[60]; j; j = (volatile uint32_t *)*j )
      result = llc_ccm_encrypt((int)i, (int)j, 0);
  }
  return result;
}



// task_event_handler @ 0x11f7c0
int task_event_handler(int a1, int a2, int a3, volatile uint8_t *a4) {
  int v4; // r9
  volatile int **v5; // r4
  int result; // r0
  int v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r11
  int v11; // r5
  int v12; // r10
  volatile int *v13; // r3
  volatile int *v14; // r1
  volatile int *v15; // r2
  volatile uint32_t *v16; // r0
  int v17; // r2
  int v18; // r4
  char v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  volatile uint32_t *v24; // r5
  int v25; // r1
  int v26; // r2
  int v27; // r0
  volatile uint32_t *v28; // r5
  volatile uint32_t *v29; // r0
  int v30; // r2
  int v31; // r3
  volatile uint32_t *v32; // r3
  int v33; // zf
  int v34; // r0
  int v35; // r1
  int v36; // r0
  volatile int16_t **v37; // r3
  char v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r6
  volatile int *v42; // r5
  int v43; // r3
  int v44; // r2
  int v45; // r2
  void *v46; // r2
  int v47; // r0
  struct __attribute__((packed)) { int v52; // [sp+20h] [bp-1Ch]
  int v53; // [sp+24h] [bp-18h]
  char _pad2[3]; uint8_t a2a; // [sp+2Bh] [bp-11h] BYREF
  uint8_t v55[4]; // [sp+2Ch] [bp-10h] BYREF
  int v56; // [sp+30h] [bp-Ch]
  } _frame;
  v4 = off_11FAFC;
  if ( !*(volatile uint32_t *)off_11FAFC )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(volatile uint8_t *)off_11FB58 )
      return 1;
    v5 = *(volatile int ***)(off_11FAFC + 8);
    if ( v5 )
    {
      if ( *(volatile uint8_t *)(off_11FAFC + 0x13) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    read_mac_int_status((volatile int *)a1);
    goto LABEL_11;
  }
  v5 = *(volatile int ***)(off_11FAFC + 8);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = *(volatile uint32_t *)a1;
  _frame.v52 = *(volatile uint32_t *)a1;
  v8 = 0;
  _frame.v53 = *(volatile uint16_t *)(a1 + 4);
  v9 = 0;
  v10 = _frame.v53;
  do
  {
    v11 = (int)v5[25];
    v12 = *((volatile uint16_t *)v5 + 52);
    event_dispatch(aMacIsXXP2pD, v11, v12, *((volatile uint8_t *)v5 + 1224));
    v5 = (volatile int **)*v5;
    v9 |= v11 ^ v7;
    v7 &= v11;
    v8 |= v12 ^ v10;
    v10 &= v12;
  }
  while ( v5 );
  v13 = (volatile int *)off_11FAEC;
  v14 = (volatile int *)off_11FAF0;
  v15 = (volatile int *)off_11FAF4;
  *(volatile uint32_t *)off_11FAE8 = v8 | 0x300;
  *v13 = v9;
  *v14 = _frame.v52;
  *v15 = _frame.v53;
  event_dispatch("set mac:%x,%x, mask:%x,%x,p2p=%d\r\n", _frame.v52, _frame.v53, v9, v8, a3);
LABEL_11:
  v16 = mem_word_load(off_11FAFC);
  v17 = dword_11FB00;
  *((volatile uint8_t *)v16 + 106) = a2;
  v18 = (int)v16;
  v19 = dword_11FB04;
  v16[25] = *(volatile uint32_t *)a1;
  *((volatile uint16_t *)v16 + 52) = *(volatile uint16_t *)(a1 + 4);
  v20 = (uint8_t)(v19 * (((int)v16 - v17) >> 3));
  *((volatile uint8_t *)v16 + 1224) = a3;
  v21 = dword_11FB08;
  v16[3] = 2627;
  v16[4] = v21;
  v16[5] = dword_11FB0C;
  *((volatile uint16_t *)v16 + 611) = 1023;
  v16[2] = 2631;
  *((volatile uint8_t *)v16 + 107) = v20;
  *((volatile uint8_t *)v16 + 84) = v20;
  *((volatile uint8_t *)v16 + 109) = 127;
  *((volatile uint8_t *)v16 + 110) = 127;
  v16[18] = 0;
  *((volatile uint8_t *)v16 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = *(volatile uint8_t *)(v4 + 0x12);
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      mac_irq_enable_1();
      v38 = *(volatile uint8_t *)(v4 + 0x12);
      v20 = *(volatile uint8_t *)(v18 + 107);
      v39 = *(volatile uint8_t *)(v18 + 1224);
    }
    v40 = dword_11FB44 + 696 * (v20 + 32);
    *(volatile uint8_t *)(v4 + 0x12) = v38 + 1;
    *(volatile uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(volatile uint32_t *)(v18 + 28) = off_11FB48;
      *(volatile uint32_t *)(v18 + 32) = v18;
    }
    stack_canary_check(v18);
    v22 = *(volatile uint8_t *)(v4 + 0x11);
  }
  else if ( a2 == 4 )
  {
    if ( *(volatile uint8_t *)(v4 + 0x10) != 255 )
      return 1;
    v41 = *(volatile uint32_t *)(v4 + 8);
    *(volatile uint8_t *)(v4 + 0x10) = v20;
    if ( v41 )
    {
      v42 = (volatile int *)off_11FB14;
      v43 = dword_11FB4C;
      v44 = **(volatile int16_t **)off_11FB10;
      *(volatile uint32_t *)off_11FB14 = dword_11FB4C;
      if ( v44 < 0 && *(volatile uint32_t *)off_11FBA8 << 28 )
      {
        call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
        v43 = *v42;
      }
      v45 = *(volatile uint32_t *)(v41 + 72);
      *(volatile uint32_t *)off_11FB18 = v43 | v42[1];
      if ( v45 )
        sta_get_current(*(volatile uint8_t *)(v45 + 24));
      v22 = *(volatile uint8_t *)(v4 + 0x11);
    }
    else
    {
      *(volatile uint32_t *)_frame.v55 = dword_11FBB4;
      _frame.v56 = 2437;
      mmio_disable_bit();
      if ( scan_find_empty_slot(_frame.v55, &_frame.a2a) )
        return 1;
      v47 = _frame.a2a;
      *(volatile uint32_t *)(v18 + 4) |= 0x80u;
      sta_get_current(v47);
      v22 = *(volatile uint8_t *)(v4 + 0x11);
    }
  }
  else
  {
    v22 = *(volatile uint8_t *)(v4 + 0x11);
    if ( !a2 )
    {
      v16[7] = off_11FB50;
      v46 = (void *)(uintptr_t)(off_11FB54);
      v16[8] = (int)(uintptr_t)(v16);
      v22 = (uint8_t)(v22 + 1);
      *((volatile uint16_t *)v16 + 73) = 0;
      v16[40] = (int)(uintptr_t)(v16);
      *(volatile uint8_t *)(v4 + 0x11) = v22;
      *((volatile uint8_t *)v16 + 116) = -1;
      v16[39] = (int)(uintptr_t)(v46);
    }
  }
  v23 = v22 + *(volatile uint8_t *)(v4 + 0x12);
  if ( v23 > 1 || *(volatile uint8_t *)(v4 + 0x12) )
  {
    v24 = (void *)(uintptr_t)(off_11FB14);
    v25 = **(volatile int16_t **)off_11FB10;
    v26 = *((volatile uint32_t *)off_11FB14 + 1) | 0x100;
    *((volatile uint32_t *)off_11FB14 + 1) = v26;
    if ( v25 < 0 && *(volatile uint32_t *)off_11FB38 << 28 )
    {
      call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
      v26 = v24[1];
      v23 = *(volatile uint8_t *)(v4 + 0x11) + *(volatile uint8_t *)(v4 + 0x12);
    }
    *(volatile uint32_t *)off_11FB18 = v26 | *v24;
  }
  if ( v23 == 1 )
    *(volatile uint32_t *)off_11FB1C |= 1u;
  if ( a3 )
  {
    v34 = *(volatile uint8_t *)(v18 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++*(volatile uint8_t *)(v4 + 0x13);
    v36 = llc_poll_active(v34, v35);
    v37 = (volatile int16_t **)off_11FB10;
    *(volatile uint8_t *)(v18 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      mmio_clear_register((int)aVifP2pIndexP2p, (int)aVifMgmtRegiste_0, 498);
  }
  v27 = dword_11FB20;
  *a4 = *(volatile uint8_t *)(v18 + 107);
  co_list_push_back(v27, (volatile uint32_t *)v18);
  v28 = (volatile uint32_t *)(v18 + 1232);
  do
  {
    zero_8_bytes(v28);
    v29 = v28 + 10;
    v28 += 2;
    zero_8_bytes(v29);
  }
  while ( v28 != (volatile uint32_t *)(v18 + 1272) );
  zero_8_bytes((volatile uint32_t *)(v18 + 1312));
  v30 = *(volatile uint8_t *)(v4 + 0x12);
  v31 = *(volatile uint8_t *)(v4 + 0x11) + v30;
  *(volatile uint32_t *)off_11FB24 = 0;
  if ( v31 <= 1 )
  {
    scan_active_get();
    v30 = *(volatile uint8_t *)(v4 + 0x12);
    v31 = *(volatile uint8_t *)(v4 + 0x11) + v30;
  }
  check_status_bits(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v31, v30, a2, a3, *a4);
  v32 = (volatile uint32_t *)(*(volatile uint8_t *)(v4 + 0x12) + *(volatile uint8_t *)(v4 + 0x11));
  v33 = v32 == (volatile uint32_t *)1;
  if ( v32 == (volatile uint32_t *)1 )
    v32 = (void *)(uintptr_t)(off_11FAE8);
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}


// get_object_by_index @ 0x11fbb8
int get_object_by_index(int a1) {
  int v2; // r6
  volatile int *v3; // r8
  int v4; // r3
  volatile uint8_t *v5; // r5
  int v6; // r2
  int v7; // r3
  int v8; // r3
  int v9; // r4
  void *v10; // r6
  int v11; // r3
  volatile int *v13; // r10
  int v14; // r9
  int v15; // r3
  volatile uint32_t **v16; // r7
  int v17; // r5
  int v18; // r11
  int v19; // r0
  int v20; // r3
  int v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r2
  volatile int16_t **v25; // r10
  volatile uint32_t *v26; // r7
  int v27; // r1
  int v28; // r9
  unsigned int v29; // r3
  volatile uint32_t *v30; // r0
  volatile uint32_t *v31; // r3
  int v32; // r1
  int v33; // r2
  unsigned int v34; // r3
  int v35; // r3
  int v36; // r0
  int v37; // r3
  int v38; // r1
  volatile int *v39; // r7
  int v40; // r3
  int v41; // r1
  int v42; // r2
  int v43; // r3
  volatile uint32_t *v44; // r12
  volatile uint32_t *v45; // r1
  int v46; // r0
  int v47; // [sp+0h] [bp-24h]
  int v48; // [sp+4h] [bp-20h]
  int a2; // [sp+8h] [bp-1Ch]
  int v50; // [sp+Ch] [bp-18h]
  int v51; // [sp+10h] [bp-14h]
  volatile int *v52; // [sp+14h] [bp-10h]
  int v53; // [sp+1Ch] [bp-8h]

  v2 = dword_11FEBC;
  v3 = (volatile int *)(dword_11FEBC + 1320 * a1);
  v50 = 1320 * a1;
  cmd_handler_c(dword_11FEC0, (void *)(v3));
  if ( *((volatile int **)off_11FEC4 + 8) == v3 )
    *((volatile uint32_t *)off_11FEC4 + 8) = 0;
  v4 = *(volatile uint8_t *)(v2 + 1320 * a1 + 106);
  if ( v4 == 2 )
  {
    v13 = (volatile int *)off_11FF04;
    v52 = v3;
    v14 = dword_11FEE4 + 696 * (a1 + 32);
    v15 = dword_11FEE4 + 8 * (87 * (a1 + 32) + 78);
    v53 = off_11FEC8;
    --*(volatile uint8_t *)(off_11FEC8 + 0x12);
    a2 = v15;
    *(volatile uint8_t *)(v14 + 37) = 0;
    v16 = (volatile uint32_t **)(v2 + 8 * (165 * (int16_t)a1 + 159));
    v17 = 0;
    do
    {
      if ( *(volatile uint32_t *)(v14 + 584) )
        rf_tx_setup((uint8_t)v17, a2 - 40, 0);
      if ( *(volatile uint32_t *)(v14 + 624) )
        rf_tx_setup((uint8_t)v17, a2, 0);
      if ( v3[318] || v3[308] )
      {
        v18 = (int)(v16 - 10);
        v51 = list_count(v16);
        v19 = list_count(v16 - 10);
        event_dispatch("vif unregister:%d, %d\n", v51, v19);
      }
      else
      {
        v18 = (int)(v16 - 10);
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11FEEC = 1;
      }
      ++*v13;
      rf_tx_setup((uint8_t)v17, (int)v16, 0);
      rf_tx_setup((uint8_t)v17, v18, 0);
      if ( *v13 )
      {
        v20 = *v13 - 1;
        v21 = *(volatile uint32_t *)off_11FEEC;
        *v13 = v20;
        if ( !v20 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      ++v17;
      v14 += 8;
      v16 += 2;
      v3 += 2;
      a2 += 8;
    }
    while ( v17 != 5 );
    v3 = v52;
    v5 = (volatile uint8_t *)v53;
    if ( *(volatile uint32_t *)(v2 + 1320 * a1 + 1312) )
    {
      v22 = list_count((volatile uint32_t **)(v50 + 1312 + v2));
      event_dispatch("vif unregister mgmt:%d\n", v22);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11FEEC = 1;
    }
    ++*v13;
    rf_tx_setup(5u, v50 + 1312 + v2, 0);
    if ( *v13 )
    {
      v23 = *v13 - 1;
      v24 = *(volatile uint32_t *)off_11FEEC;
      *v13 = v23;
      if ( !v23 )
      {
        if ( v24 )
          __enable_irq();
      }
    }
    v6 = *(volatile uint8_t *)(v53 + 18);
    if ( !*(volatile uint8_t *)(v53 + 18) )
    {
      mac_irq_disable_1();
LABEL_6:
      v6 = (uint8_t)v5[18];
      v7 = (uint8_t)v5[17] + v6;
      if ( v7 != 1 )
        goto LABEL_7;
      goto LABEL_40;
    }
    if ( *(volatile uint8_t *)(v53 + 17) + v6 != 1 )
      goto LABEL_9;
  }
  else
  {
    if ( v4 != 4 )
    {
      v5 = (volatile uint8_t *)off_11FEC8;
      if ( !*(volatile uint8_t *)(v2 + 1320 * a1 + 106) )
      {
        v6 = *(volatile uint8_t *)(off_11FEC8 + 0x12);
        v35 = (uint8_t)(*(volatile uint8_t *)(off_11FEC8 + 0x11) - 1);
        *(volatile uint8_t *)(off_11FEC8 + 0x11) = v35;
        v7 = v35 + v6;
        if ( v7 != 1 )
          goto LABEL_7;
        goto LABEL_40;
      }
      goto LABEL_6;
    }
    if ( rf_check_status() )
      rf_set_pa_bit(0);
    v5 = (void *)(uintptr_t)(off_12000C);
    v36 = *((volatile uint8_t *)off_12000C + 16);
    v37 = v2 + 1320 * v36;
    v38 = *(volatile uint32_t *)(v37 + 72);
    *(volatile uint32_t *)(v37 + 4) &= ~0x80u;
    if ( v38 )
      sta_get_by_index(v36);
    v6 = (uint8_t)v5[18];
    if ( v5[18] )
    {
      mac_irq_enable_1();
      v6 = (uint8_t)v5[18];
    }
    else
    {
      v39 = (volatile int *)off_120014;
      v40 = dword_120018;
      v41 = **(volatile int16_t **)off_120010;
      *(volatile uint32_t *)off_120014 = dword_120018;
      if ( v41 < 0 )
      {
        v6 = *(volatile uint32_t *)off_120020 & 0xF;
        if ( v6 )
        {
          call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
          v40 = *v39;
          v6 = (uint8_t)v5[18];
        }
      }
      *(volatile uint32_t *)off_12001C = v40 | v39[1];
    }
    v7 = (uint8_t)v5[17] + v6;
    v5[16] = -1;
    if ( v7 != 1 )
      goto LABEL_7;
  }
LABEL_40:
  v25 = (volatile int16_t **)off_11FF08;
  v26 = (void *)(uintptr_t)(off_11FEF4);
  v27 = **(volatile int16_t **)off_11FF08;
  v28 = *((volatile uint32_t *)v5 + 2);
  v29 = *((volatile uint32_t *)off_11FEF4 + 1) & 0xFFFFFFEF;
  *((volatile uint32_t *)off_11FEF4 + 1) = v29;
  if ( v27 >= 0 || !(*(volatile uint32_t *)off_120020 << 28) )
  {
    v30 = (void *)(uintptr_t)(off_11FEF8);
    *(volatile uint32_t *)off_11FF00 = v29 | *v26;
    v31 = (void *)(uintptr_t)(off_11FEFC);
    v32 = *(volatile uint16_t *)(v28 + 68);
    *v30 = *(volatile uint32_t *)(v28 + 64);
    *v31 = v32;
    if ( v6 )
      goto LABEL_9;
LABEL_42:
    v33 = **v25;
    v34 = v26[1] & 0xFFFFFEFF;
    v26[1] = v34;
    if ( v33 >= 0 || !(*(volatile uint32_t *)off_120020 << 28) )
    {
      *(volatile uint32_t *)off_11FF00 = v34 | *v26;
      goto LABEL_9;
    }
    call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
    v7 = (uint8_t)v5[17] + (uint8_t)v5[18];
    *(volatile uint32_t *)off_12001C = *v26 | v26[1];
    goto LABEL_7;
  }
  call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
  v42 = (uint8_t)v5[18];
  v43 = (uint8_t)v5[17];
  v44 = (void *)(uintptr_t)(off_120030);
  *(volatile uint32_t *)off_12001C = *v26 | v26[1];
  v7 = v43 + v42;
  v45 = (void *)(uintptr_t)(off_12002C);
  v46 = *(volatile uint16_t *)(v28 + 68);
  *v44 = *(volatile uint32_t *)(v28 + 64);
  *v45 = v46;
  if ( v7 == 1 )
  {
    if ( v42 )
      goto LABEL_9;
    goto LABEL_42;
  }
LABEL_7:
  if ( !v7 )
    *(volatile uint32_t *)off_11FECC = 0;
LABEL_9:
  fault_handler((int)(uintptr_t)((volatile uint32_t *)(v50 + 24 + v2)));
  fault_handler((int)(uintptr_t)((volatile uint32_t *)(v50 + 48 + v2)));
  v8 = v2 + 1320 * a1;
  if ( *(volatile uint8_t *)(v8 + 1224) )
  {
    llc_evt_is_valid(*(volatile uint8_t *)(v8 + 1225), 1);
    --v5[19];
  }
  tx_queue_entry_get(*(volatile uint8_t *)(v2 + 1320 * a1 + 107));
  if ( *((volatile int **)off_11FED0 + 4) == v3 )
    *((volatile uint32_t *)off_11FED0 + 4) = 0;
  *(volatile uint32_t *)off_11FED4 = 0;
  if ( (uint8_t)v5[18] + (uint8_t)v5[17] <= 1 )
    scan_active_get();
  memset(v3, 0, 0x528u);
  v48 = a1;
  v9 = v2 + 1320 * a1;
  v10 = (void *)(uintptr_t)(off_11FED8);
  v47 = (uint8_t)v5[18];
  v11 = v47 + (uint8_t)v5[17];
  *(volatile uint8_t *)(v9 + 106) = 5;
  *(volatile uint32_t *)(v9 + 56) = (int)(uintptr_t)(v3);
  *(volatile uint32_t *)(v9 + 52) = (int)(uintptr_t)(v10);
  *(volatile uint8_t *)(v9 + 109) = 127;
  *(volatile uint8_t *)(v9 + 110) = 127;
  check_status_bits(256, "%s:%d,%d,%d\r\n", aVifMgmtUnregis, v11, v47, v48);
  return co_list_push_back(off_11FEC8, (void *)(v3));
}


