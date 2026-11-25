// bt_get_conn_by_index @ 0x135708
int bt_get_conn_by_index(int result) {
  int v1; // r4
  int v2; // r2
  int v3; // r3
  int v4; // r5
  int v5; // r2
  int v6; // r6
  int16_t v7; // r8
  int v8; // r7
  int16_t v9; // r3
  volatile uint16_t *v10; // r12
  int v11; // r3
  int16_t v12; // r1
  int v13; // r2
  int v14; // r0
  int16_t v15; // r6
  int v16; // r4
  int v17; // r4
  int v18; // r3
  int v19; // r2
  int v20; // r1
  uint64_t v21; // r2
  struct __attribute__((packed)) { int v22; // [sp+4h] [bp-10h] BYREF
  int v23; // [sp+8h] [bp-Ch]
  int16_t v24; // [sp+Ch] [bp-8h]
  } _frame;
  v1 = dword_135844 + 1320 * *(volatile uint8_t *)(result + 8);
  v2 = *(volatile uint8_t *)(v1 + 108);
  _frame.v22 = 0;
  _frame.v23 = 0;
  _frame.v24 = 0;
  if ( v2 )
  {
    if ( !*(volatile uint8_t *)(v1 + 106) )
    {
      v3 = *(volatile uint8_t *)(result + 7);
      v4 = result;
      if ( v3 != 255 )
      {
        v5 = *(volatile uint8_t *)(v1 + 116);
        if ( v5 == v3 )
        {
          v6 = dword_135848 + 696 * v5;
          if ( *(volatile uint8_t *)(v6 + 52) == 2 && !*(volatile uint8_t *)(result + 13) )
          {
            v7 = *(volatile uint16_t *)(result + 14);
            result = (int)(uintptr_t)(ke_mutex_guard(*(volatile uint8_t *)(result + 6) != 0, 512));
            v8 = result;
            if ( result )
            {
              v9 = *(volatile uint16_t *)(v4 + 4);
              _frame.v22 = (_frame.v22 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v4 + 6)) & 0xFFu);
              _frame.v23 = (_frame.v23 & ~0xFFFFu) | ((uint16_t)(v9) & 0xFFFFu);
              _frame.v22 = (_frame.v22 & ~0xFFFF0000u) | (((uint16_t)(v9) & 0xFFFFu) << 16);
              ((int (*)())rf_check_battery)(v1, result, (volatile uint8_t *)&_frame.v22);
              v10 = (void *)(uintptr_t)(off_13584C);
              v11 = *(volatile uint32_t *)(v8 + 72);
              v12 = *((volatile uint16_t *)off_13584C + 254);
              v13 = v6 + 38;
              *(volatile uint32_t *)(v11 + 112) = *(volatile uint32_t *)(v6 + 38);
              *(volatile uint8_t *)(v11 + 108) = -48;
              *(volatile uint16_t *)(v11 + 116) = *(volatile uint16_t *)(v6 + 42);
              ++v12;
              v14 = *(volatile uint32_t *)(v1 + 100);
              v15 = *(volatile uint16_t *)(v1 + 104);
              v16 = *(volatile uint32_t *)v13;
              *(volatile uint32_t *)(v11 + 118) = v14;
              v14 = (v14 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v13 + 4)) & 0xFFFFu);
              *(volatile uint8_t *)(v11 + 109) = 0;
              *(volatile uint8_t *)(v11 + 110) = 0;
              *(volatile uint8_t *)(v11 + 111) = 0;
              *(volatile uint16_t *)(v11 + 122) = v15;
              *(volatile uint32_t *)(v11 + 124) = v16;
              *(volatile uint16_t *)(v11 + 128) = v14;
              v10[254] = v12;
              *(volatile uint16_t *)(v11 + 130) = 16 * v12;
              *(volatile uint8_t *)(v8 + 28) = *(volatile uint8_t *)(v4 + 8);
              *(volatile uint8_t *)(v8 + 29) = *(volatile uint8_t *)(v4 + 7);
              v17 = v11 + 108;
              *(volatile uint8_t *)(v8 + 51) = 0;
              *(volatile uint8_t *)(v8 + 53) = 0;
              get_channel_tx_power(v8, 208, 8);
              ll_conn_window_calc(v8, (void *)(uintptr_t)(v17), 24);
              v18 = *(volatile uint8_t *)(v8 + 51) + 24;
              v19 = v18 + v17;
              *(volatile uint8_t *)(v18 + v17) = 8;
              *(volatile uint8_t *)(v19 + 1) = 1;
              v20 = *(volatile uint32_t *)(v8 + 76);
              *(volatile uint16_t *)(v19 + 2) = v7;
              v21 = (v21 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v18 + *(volatile uint8_t *)(v8 + 53) + 4) << 32);
              v21 = (v21 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v20 + 28) - 1 + HIDWORD(v21)) & 0xFFFFFFFFu);
              v21 = (v21 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v21 >> 32) & 0xFFFFFFFFu) + (uint32_t)(4))) << 32;;
              *(volatile uint64_t *)(v20 + 32) = v21;
              return tx_path_status(v8, 5);
            }
          }
        }
      }
    }
  }
  return result;
}



// bt_get_current_profile_conn @ 0x135850
int bt_get_current_profile_conn(unsigned int a1) {
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

  v1 = *((volatile uint32_t *)off_13591C + 4);
  v2 = dword_135920;
  v3 = *(volatile uint8_t *)(v1 + 61);
  if ( **(volatile int16_t **)off_135918 < 0 && *(volatile int *)(dword_135920 + 1320 * v3 + 472) >= 0 )
    mmio_clear_register((int)aBssCapaBssVali, (int)aSmExternalAuth, 1398);
  v5 = (volatile uint8_t *)ke_msg_alloc(6150, 13, 6, 44);
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
  ke_state_set(6u, 6);
  ke_timer_set(6154, 6, off_135924);
  return (int)ke_msg_send_2(v9);
}


// hci_send_vendor_command @ 0x135930
int hci_send_vendor_command(int a1) {
  ke_int_lock((int)(uintptr_t)((volatile char *)0x180A), 6);
  if ( !a1 )
    return sm_assoc_req_send();
  check_status_bits(256, "ext auth st %x\n", a1);
  return bt_setup_conn_profile(a1);
}


// is_hw_feature_6 @ 0x135964
BOOL is_hw_feature_6() {
  return rx_rate_field_parse(6u) == 6;
}



// bt_send_ack_message @ 0x135978
int bt_send_ack_message(char a1, int a2, unsigned int a3) {
  unsigned int v3; // r4
  int v6; // r0
  volatile int16_t **v7; // r3
  volatile int16_t *v8; // r3
  int v9; // r5
  int v10; // r3
  unsigned int v11; // r4

  v3 = a3;
  v6 = ke_msg_alloc(6152, 13, 6, (uint16_t)(a3 + 4));
  v7 = (volatile int16_t **)off_1359F0;
  *(volatile uint8_t *)v6 = a1;
  v8 = *v7;
  *(volatile uint16_t *)(v6 + 2) = v3;
  v9 = v6;
  if ( *v8 < 0 )
  {
    if ( v3 >= get_dma_ring_bytes() - 4 )
      mmio_clear_register((int)aIndFtIeLenMaci, (int)aSmFtAuthOverAi, 1444);
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
  ke_state_set(6u, 7);
  ke_timer_set(6154, 6, dword_1359F4);
  return (int)ke_msg_send_2(v9);
}


// bt_send_acl_event @ 0x135a00
int bt_send_acl_event(volatile uint16_t *a1) {
  volatile uint16_t *v1; // r6
  int v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r3

  v1 = a1 + 6;
  ke_int_lock((int)(uintptr_t)((volatile char *)0x180A), 6);
  v3 = v1[2];
  result = check_status_bits(256, "auth_handler:%d\r\n", v3);
  if ( v3 )
    return bt_setup_conn_profile(v3);
  v5 = a1[6];
  if ( !a1[6] )
    return sm_assoc_req_send();
  if ( v5 != 1 )
  {
    if ( v5 == 2 )
      return bt_send_ack_message(*((volatile uint8_t *)a1 + 8), (int)(a1 + 9), (uint16_t)(*a1 - 6));
    return result;
  }
  v6 = v1[1];
  if ( v6 == 4 )
  {
    wait_timer_ticks(0xBB8u);
    return sm_assoc_req_send();
  }
  if ( v6 == 2 && *a1 > 0x22u )
    return bt_get_profile_by_id(3, (int)(a1 + 10));
  return result;
}


