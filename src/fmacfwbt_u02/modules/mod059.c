// rf_get_power_by_index @ 0x135924
void rf_get_power_by_index(int a1) {
  int v1; // r4
  int v2; // r2
  int v3; // r3
  int v5; // r2
  int v6; // r6
  int16_t v7; // r8
  volatile uint32_t *v8; // r0
  int v9; // r7
  int16_t v10; // r3
  volatile uint16_t *v11; // r12
  int v12; // r3
  int16_t v13; // r1
  int v14; // r2
  int v15; // r0
  int16_t v16; // r6
  int v17; // r4
  volatile uint16_t *v18; // r4
  int v19; // r3
  volatile char *v20; // r2
  int v21; // r1
  int64_t v22; // r2
  struct __attribute__((packed)) { int v23; // [sp+4h] [bp-10h] BYREF
  int v24; // [sp+8h] [bp-Ch]
  int16_t v25; // [sp+Ch] [bp-8h]
  } _frame;
  v1 = dword_135A60 + 1320 * *(volatile uint8_t *)(a1 + 8);
  v2 = *(volatile uint8_t *)(v1 + 108);
  _frame.v23 = 0;
  _frame.v24 = 0;
  _frame.v25 = 0;
  if ( v2 )
  {
    if ( !*(volatile uint8_t *)(v1 + 106) )
    {
      v3 = *(volatile uint8_t *)(a1 + 7);
      if ( v3 != 255 )
      {
        v5 = *(volatile uint8_t *)(v1 + 116);
        if ( v5 == v3 )
        {
          v6 = dword_135A64 + 696 * v5;
          if ( *(volatile uint8_t *)(v6 + 52) == 2 && !*(volatile uint8_t *)(a1 + 13) )
          {
            v7 = *(volatile uint16_t *)(a1 + 14);
            v8 = event_notify(*(volatile uint8_t *)(a1 + 6) != 0, 512);
            v9 = (int)v8;
            if ( v8 )
            {
              v10 = *(volatile uint16_t *)(a1 + 4);
              _frame.v23 = (_frame.v23 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a1 + 6)) & 0xFFu);
              _frame.v24 = (_frame.v24 & ~0xFFFFu) | ((uint16_t)(v10) & 0xFFFFu);
              _frame.v23 = (_frame.v23 & ~0xFFFF0000u) | (((uint16_t)(v10) & 0xFFFFu) << 16);
              scan_done_check_alt(v1, (int)(uintptr_t)(v8), (void *)(&_frame.v23));
              v11 = (void *)(uintptr_t)(off_135A68);
              v12 = *(volatile uint32_t *)(v9 + 72);
              v13 = *((volatile uint16_t *)off_135A68 + 254);
              v14 = v6 + 38;
              *(volatile uint32_t *)(v12 + 112) = *(volatile uint32_t *)(v6 + 38);
              *(volatile uint8_t *)(v12 + 108) = -48;
              *(volatile uint16_t *)(v12 + 116) = *(volatile uint16_t *)(v6 + 42);
              ++v13;
              v15 = *(volatile uint32_t *)(v1 + 100);
              v16 = *(volatile uint16_t *)(v1 + 104);
              v17 = *(volatile uint32_t *)v14;
              *(volatile uint32_t *)(v12 + 118) = v15;
              v15 = (v15 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v14 + 4)) & 0xFFFFu);
              *(volatile uint8_t *)(v12 + 109) = 0;
              *(volatile uint8_t *)(v12 + 110) = 0;
              *(volatile uint8_t *)(v12 + 111) = 0;
              *(volatile uint16_t *)(v12 + 122) = v16;
              *(volatile uint32_t *)(v12 + 124) = v17;
              *(volatile uint16_t *)(v12 + 128) = v15;
              v11[254] = v13;
              *(volatile uint16_t *)(v12 + 130) = 16 * v13;
              *(volatile uint8_t *)(v9 + 28) = *(volatile uint8_t *)(a1 + 8);
              *(volatile uint8_t *)(v9 + 29) = *(volatile uint8_t *)(a1 + 7);
              v18 = (volatile uint16_t *)(v12 + 108);
              *(volatile uint8_t *)(v9 + 51) = 0;
              *(volatile uint8_t *)(v9 + 53) = 0;
              bt_get_conn_ctx(v9, 208, 8);
              mac_rx_process_ack(v9, v18, 24);
              v19 = *(volatile uint8_t *)(v9 + 51) + 24;
              v20 = (volatile char *)v18 + v19;
              *((volatile uint8_t *)v18 + v19) = 8;
              v20[1] = 1;
              v21 = *(volatile uint32_t *)(v9 + 76);
              *((volatile uint16_t *)v20 + 1) = v7;
              v22 = (v22 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v19 + *(volatile uint8_t *)(v9 + 53) + 4) << 32);
              v22 = (v22 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v21 + 28) - 1 + HIDWORD(v22)) & 0xFFFFFFFFu);
              v22 = (v22 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v22 >> 32) & 0xFFFFFFFFu) + (uint32_t)(4))) << 32;;
              *(volatile uint64_t *)(v21 + 32) = v22;
              ble_event_dispatch(v9, 5);
            }
          }
        }
      }
    }
  }
}


// rf_copy_cal_params @ 0x1359cc
void rf_copy_cal_params( int a1, int16_t a2, volatile int *a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11) {
  int v11; // r4
  int v12; // r5
  int v13; // r7
  int16_t v14; // r8
  char v15; // r9
  int v16; // r12
  int16_t v17; // r1
  int v18; // r0
  int16_t v19; // r6
  int v20; // r4
  int v21; // r4
  int v22; // r3
  int v23; // r2
  int v24; // r1
  uint64_t v25; // r2

  *(volatile uint16_t *)(a4 + 116) = *((volatile uint16_t *)a3 + 2);
  v17 = a2 + 1;
  v18 = *(volatile uint32_t *)(v11 + 100);
  v19 = *(volatile uint16_t *)(v11 + 104);
  v20 = *a3;
  *(volatile uint32_t *)(a4 + 118) = v18;
  v18 = (v18 & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)a3 + 2)) & 0xFFFFu);
  *(volatile uint8_t *)(a4 + 109) = v15;
  *(volatile uint8_t *)(a4 + 110) = v15;
  *(volatile uint8_t *)(a4 + 111) = v15;
  *(volatile uint16_t *)(a4 + 122) = v19;
  *(volatile uint32_t *)(a4 + 124) = v20;
  *(volatile uint16_t *)(a4 + 128) = v18;
  *(volatile uint16_t *)(v16 + 508) = v17;
  *(volatile uint16_t *)(a4 + 130) = 16 * v17;
  *(volatile uint8_t *)(v13 + 28) = *(volatile uint8_t *)(v12 + 8);
  *(volatile uint8_t *)(v13 + 29) = *(volatile uint8_t *)(v12 + 7);
  v21 = a4 + 108;
  *(volatile uint8_t *)(v13 + 51) = v15;
  *(volatile uint8_t *)(v13 + 53) = v15;
  bt_get_conn_ctx(v13, 208, 8);
  mac_rx_process_ack(v13, (void *)(uintptr_t)(v21), 24);
  v22 = *(volatile uint8_t *)(v13 + 51) + 24;
  v23 = v22 + v21;
  *(volatile uint8_t *)(v22 + v21) = 8;
  *(volatile uint8_t *)(v23 + 1) = 1;
  v24 = *(volatile uint32_t *)(v13 + 76);
  *(volatile uint16_t *)(v23 + 2) = v14;
  v25 = (v25 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v22 + *(volatile uint8_t *)(v13 + 53) + 4) << 32);
  v25 = (v25 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v24 + 28) - 1 + HIDWORD(v25)) & 0xFFFFFFFFu);
  v25 = (v25 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v25 >> 32) & 0xFFFFFFFFu) + (uint32_t)(4))) << 32;;
  *(volatile uint64_t *)(v24 + 32) = v25;
  ble_event_dispatch(v13, 5);
  return;
}



// rf_check_status_1 @ 0x135a6c
int rf_check_status_1(unsigned int a1) {
  int v1; // r8
  int v2; // r7
  int v3; // r5
  volatile uint8_t *v5; // r0
  volatile uint32_t *v6; // r3
  int v7; // r1
  volatile int *v8; // r2
  int v9; // r4
  volatile int *v10; // r1
  int v11; // lr
  int v12; // r12
  int v13; // r0
  int v14; // r5
  int v15; // r0

  v1 = *((volatile uint32_t *)off_135B38 + 4);
  v2 = dword_135B3C;
  v3 = *(volatile uint8_t *)(v1 + 61);
  if ( **(volatile int16_t **)off_135B34 < 0 && *(volatile int *)(dword_135B3C + 1320 * v3 + 472) >= 0 )
    mmio_irq_clear((int)aBssCapaBssVali, (int)aSmExternalAuth, 1398);
  v5 = (volatile uint8_t *)bt_buf_alloc(6150, 13, 6, 44);
  *v5 = *(volatile uint8_t *)(v1 + 61);
  v6 = (void *)(v5 + 1);
  v7 = v2 + 1320 * v3;
  v8 = (volatile int *)(v7 + 374);
  v9 = (int)v5;
  v10 = (volatile int *)(v7 + 406);
  do
  {
    v11 = *v8;
    v12 = v8[1];
    v13 = v8[2];
    v6[3] = v8[3];
    v8 += 4;
    *v6 = v11;
    v6[1] = v12;
    v6[2] = v13;
    v6 += 4;
  }
  while ( v8 != v10 );
  *(volatile uint8_t *)v6 = *(volatile uint8_t *)v8;
  v14 = v2 + 1320 * v3;
  v15 = *(volatile uint32_t *)(v14 + 368);
  *(volatile uint16_t *)(v9 + 38) = *(volatile uint16_t *)(v14 + 372);
  *(volatile uint32_t *)(v9 + 34) = v15;
  *(volatile uint32_t *)(v9 + 40) = bswap32(a1);
  hci_cmd_send(6u, 6);
  patch_aware_dispatch(6154, 6, off_135B40);
  return (int)hci_evt_send(v9);
}


// hci_vendor_cmd_dispatch @ 0x135b4c
int hci_vendor_cmd_dispatch(int a1) {
  irq_lock((volatile char *)0x180A, 6);
  if ( !a1 )
    return rf_lookup_alt_by_index();
  state_check_feature(256, "ext auth st %x\n", a1);
  return event_dispatch_1(a1);
}


// is_pll_freq_6 @ 0x135b80
BOOL is_pll_freq_6() {
  return hci_cmd_send_short(6u) == 6;
}



// send_hci_vendor_cmd @ 0x135b94
int send_hci_vendor_cmd(char a1, int a2, unsigned int a3) {
  unsigned int v3; // r4
  int v6; // r0
  volatile int16_t **v7; // r3
  volatile int16_t *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = bt_buf_alloc(6152, 13, 6, (uint16_t)(a3 + 4));
  v7 = (volatile int16_t **)off_135C0C;
  *(volatile uint8_t *)v6 = a1;
  v8 = *v7;
  *(volatile uint16_t *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= get_shared_buf_size() - 4 )
      mmio_irq_clear((int)aIndFtIeLenMaci, (int)aSmFtAuthOverAi, 1444);
    v3 = *(volatile uint16_t *)(v9 + 2);
  }
  if ( v3 )
  {
    v10 = v9 + 3;
    v11 = v3 + v9 + 3;
    do
    {
      *(volatile uint8_t *)(v10 + 1) = *(volatile uint8_t *)(a2 - 3 - v9 + v10);
      ++v10;
    }
    while ( v10 != v11 );
  }
  hci_cmd_send(6u, 7);
  patch_aware_dispatch(6154, 6, dword_135C10);
  return (int)hci_evt_send(v9);
}


// hci_vendor_read_rf_cache @ 0x135c1c
int hci_vendor_read_rf_cache(volatile uint16_t *a1) {
  volatile uint16_t *v1; // r6
  int v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  irq_lock((volatile char *)0x180A, 6);
  v3 = v1[2];
  result = state_check_feature(256, "auth_handler:%d\r\n", v3);
  if ( v3 )
    return event_dispatch_1(v3);
  v5 = a1[6];
  if ( !a1[6] )
    return rf_lookup_alt_by_index();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return send_hci_vendor_cmd(*((volatile uint8_t *)a1 + 8), (int)(a1 + 9), (uint16_t)(*a1 - 6));
    return result;
  }
  v6 = v1[1];
  if ( v6 == 4 )
  {
    wait_for_hw_data(0xBB8u);
    return rf_lookup_alt_by_index();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return rf_lookup_by_index(3, (int)(a1 + 10));
  return result;
}


