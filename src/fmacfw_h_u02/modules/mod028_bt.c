// rf_setup_channel @ 0x122044
int rf_setup_channel(int a1) {
  volatile int *v1; // r3
  int v2; // r6
  int v3; // r5
  volatile int *v4; // r0
  volatile int *v5; // r1
  int v6; // r2
  int v7; // t1
  int v8; // r4
  volatile int *v9; // r4
  volatile uint8_t *v10; // r1
  volatile uint8_t *v11; // r2
  uint32_t v13[7]; // [sp+0h] [bp-1Ch] BYREF

  v1 = (volatile int *)dword_1220BC;
  v2 = dword_1220C0;
  v3 = dword_1220C4;
  v4 = (volatile int *)(a1 + 12);
  v5 = (volatile int *)(*(volatile uint32_t *)off_1220B8 + 4);
  do
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFF;
    if ( v7 )
    {
      if ( !v8 )
      {
        *v1 = *v4 & 0xFFF | v6 & v2;
        goto LABEL_5;
      }
    }
    else
    {
      v6 = *v4;
    }
    *v1 = v6;
LABEL_5:
    ++v1;
    ++v4;
  }
  while ( v1 != (volatile int *)v3 );
  v9 = (volatile int *)off_1220C8;
  rf_reg_write_byte(BYTE1(((volatile uint32_t *)(uintptr_t)off_1220C8)[102]));
  v10 = (void *)(uintptr_t)(off_1220D0);
  v11 = (void *)(uintptr_t)(off_1220D4);
  *((volatile uint8_t *)off_1220CC + 7) = *((volatile uint8_t *)v9 + 409);
  memset((void *)(&v13[1]), 0, 16);
  *v10 = 0;
  v13[0] = 0;
  *v11 = 0;
  v13[5] = 0;
  poll_hw_ready((int)v13);
  return alloc_tx_event(aEdcaM0);
}


// rf_switch_channel @ 0x1220dc
int rf_switch_channel(int a1) {
  int v1; // r4
  volatile int *v2; // r2
  int v3; // r5
  int v4; // r6
  volatile int *v5; // r0
  volatile int *v6; // r1
  int v7; // t1
  int v8; // zf
  int v9; // r3
  volatile int *v10; // r4
  volatile uint32_t *v11; // r5
  volatile uint8_t *v12; // r0
  volatile uint8_t *v13; // r1
  volatile unsigned int v14; // r1
  volatile uint32_t *v15; // r2

  v2 = (volatile int *)dword_122154;
  v3 = dword_122158;
  v4 = dword_12215C;
  v5 = (volatile int *)(a1 + 444);
  v6 = (volatile int *)(*(volatile uint32_t *)off_122150 + 4);
  do
  {
    v7 = *v6++;
    v9 = v7 & v3;
    v8 = (v7 & v3) == 0;
    if ( (v7 & v3) != 0 )
      v1 = *v5;
    else
      v9 = *v5;
    if ( !v8 )
    {
      v1 &= 0xFFFu;
      v9 |= v1;
    }
    *v2++ = v9;
    ++v5;
  }
  while ( v2 != (volatile int *)v4 );
  v10 = (volatile int *)off_122160;
  v11 = (void *)(uintptr_t)(off_122164);
  rf_reg_write_byte(BYTE2(((volatile uint32_t *)(uintptr_t)off_122160)[102]));
  v12 = (void *)(uintptr_t)(off_12216C);
  v13 = (void *)(uintptr_t)(off_122170);
  *((volatile uint8_t *)off_122168 + 9) = *((volatile uint8_t *)v10 + 410);
  *v12 = 1;
  *v13 = 1;
  v14 = REG_4032_0120;
  v15 = (void *)(uintptr_t)(off_122178);
  *v11 = v14 + 15000;
  *v15 = 15000;
  v15[1] = 15000;
  v15[2] = 15000;
  v15[3] = 15000;
  v15[4] = 15000;
  v15[5] = 15000;
  return alloc_tx_event(aEdcaM1);
}


// poll_rf_register_done @ 0x122180
int poll_rf_register_done() {
  volatile uint32_t *v0; // r1
  int result; // r0
  int i; // r3

  v0 = (void *)(uintptr_t)(off_1221AC);
  result = dword_1221B0;
  for ( i = 0; i != 6; ++i )
  {
    if ( ((*v0 >> i) & 1) != 0 )
      *(volatile uint32_t *)(result + 4 * i) += 15000;
  }
  return result;
}



// process_hci_packet @ 0x1221b4
volatile uint32_t * process_hci_packet(volatile uint32_t *result, int a2) {
  unsigned int v2; // r4
  int v3; // r7
  volatile uint32_t *v4; // r5
  int v5; // r6
  int v6; // r8
  float v7; // s17
  float v8; // s16
  int v9; // r3
  volatile uint8_t *v10; // r7
  volatile uint32_t *v11; // r10
  volatile unsigned int *v12; // r9
  volatile unsigned int *v13; // r8
  volatile uint32_t *v14; // r0
  unsigned int v15; // r12
  volatile char *v16; // r11
  int v17; // lr
  volatile uint32_t *v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r0
  unsigned int v22; // r2
  char v23; // r2
  int v24; // r1
  int v25; // r2
  int v26; // r1
  volatile uint32_t *v27; // r3
  volatile unsigned int *v28; // r2
  unsigned int v29; // r3
  int v30; // r2
  volatile uint32_t *v31; // r12
  volatile uint32_t *v32; // r1
  int v33; // r2
  volatile uint8_t *v34; // r2
  int v35; // r3
  volatile uint8_t *v36; // r0
  int v37; // r2
  int v39; // [sp+14h] [bp-10h]
  unsigned int v40; // [sp+18h] [bp-Ch]
  volatile uint8_t *v41; // [sp+18h] [bp-Ch]

  v2 = off_122448;
  v3 = *(volatile char *)off_122448;
  if ( !*(volatile uint8_t *)off_122448 )
    return result;
  v4 = result;
  v5 = *(volatile uint8_t *)(off_122448 + 2);
  v6 = *(volatile char *)(off_122448 + 1);
  v7 = *(volatile float *)(off_122448 + 4);
  result = (volatile uint32_t *)hci_cmd_handler(4u);
  if ( result )
    return result;
  v8 = (float)((float)(v7 * flt_12244C) + (float)a2) * flt_122450;
  v9 = (char)(int)v8;
  v39 = v9;
  if ( v9 < v3 - v6 )
  {
    v10 = (void *)(uintptr_t)(off_122458);
    v5 = 1;
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_122454)[102]) )
      goto LABEL_8;
LABEL_27:
    v30 = *(volatile uint8_t *)off_122480;
    v31 = (void *)(uintptr_t)(off_122494);
    result = (void *)(uintptr_t)(off_122484);
    v32 = (void *)(uintptr_t)(off_122488);
    *(volatile uint8_t *)off_122498 = 0;
    *(volatile uint32_t *)v10 = 0;
    *v31 = 0;
    *result = 0;
    *v32 = 0;
    if ( !v30 )
      goto LABEL_22;
    goto LABEL_28;
  }
  if ( v3 < v9 )
    v5 = 0;
  v10 = (void *)(uintptr_t)(off_122458);
  if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_122454)[102]) )
    goto LABEL_27;
LABEL_8:
  if ( !v10[8] )
    goto LABEL_27;
  v11 = (void *)(uintptr_t)(off_122494);
  v12 = (volatile unsigned int *)off_122484;
  v13 = (volatile unsigned int *)off_122488;
  v14 = (void *)(uintptr_t)(off_122460);
  v15 = *(volatile uint32_t *)v10;
  v16 = (volatile char *)off_122498;
  v17 = *(volatile uint32_t *)off_12245C + *(volatile uint32_t *)off_122494;
  v18 = (volatile uint32_t *)((volatile char *)off_12245C + 268);
  *(volatile uint32_t *)off_122494 = v17;
  v19 = *v13;
  v20 = *v18 + *v12;
  *v12 = v20;
  v21 = *v14 + v19;
  if ( v21 <= v15 )
    v22 = 0;
  else
    v22 = v21 - v15;
  v40 = v22;
  v23 = *v16;
  v24 = *(volatile uint8_t *)off_122464;
  *v13 = v21;
  v25 = (uint8_t)(v23 + 1);
  *v16 = v25;
  if ( v24 == v25 )
  {
    if ( *(volatile uint8_t *)off_122474 == 1 && v20 <= 0x13 && v40 <= 9 )
    {
      v41 = (volatile uint8_t *)off_122468;
      v33 = 2;
      *(volatile uint8_t *)off_122468 = 2;
    }
    else if ( *(volatile uint8_t *)(off_122464 + 3) <= v40 || v20 <= v40 * *(volatile uint8_t *)(off_122464 + 2) )
    {
      v41 = (volatile uint8_t *)off_122468;
      v33 = 0;
      *(volatile uint8_t *)off_122468 = 0;
    }
    else
    {
      v41 = (volatile uint8_t *)off_122468;
      v33 = 1;
      *(volatile uint8_t *)off_122468 = 1;
    }
    check_feature_flag(64, "$%d %d,%d,%d,%d %d\n", v33, v20, v21, v15, v17, v39);
    v26 = *v41;
    *v16 = 0;
    *v11 = 0;
    *v12 = 0;
    *v13 = 0;
    *(volatile uint32_t *)v10 = 0;
    if ( v26 == 1 )
    {
      v36 = (void *)(uintptr_t)(off_122470);
      v37 = *(volatile uint8_t *)off_122470;
      *(volatile uint8_t *)off_12248C = 0;
      if ( v37 != 255 )
        *v36 = v37 + 1;
    }
    else if ( !v26 )
    {
      v34 = (void *)(uintptr_t)(off_12248C);
      v35 = *(volatile uint8_t *)off_12248C;
      *(volatile uint8_t *)off_122470 = 0;
      if ( v35 != 255 )
        *v34 = v35 + 1;
    }
  }
  else
  {
    v26 = *(volatile uint8_t *)off_122468;
  }
  v27 = (void *)(uintptr_t)(off_12246C);
  *(volatile uint32_t *)off_12246C &= ~0x4000u;
  *v27 = (uint16_t)*v27;
  *v27 = *v27 & 0xFFFFFC00 | 0x44;
  *v27 |= 0x8000u;
  while ( (*v27 & 0x8000) != 0 )
    ;
  v28 = (volatile unsigned int *)off_12246C;
  *v27 = *v27 & 0xFFFFFC00 | 0x54;
  result = (volatile uint32_t *)(*v27 | 0x8000);
  *v27 = (int)(uintptr_t)(result);
  while ( (*v28 & 0x8000) != 0 )
    ;
  *v28 = *v28 & 0xFFFFFC00 | 1;
  *v28 |= 0x8000u;
  if ( v26 == 2 )
    goto LABEL_22;
  v29 = *(volatile uint8_t *)(off_122464 + 1);
  if ( *(volatile uint8_t *)off_122470 > v29 )
  {
    if ( *(volatile uint8_t *)off_122474 != 1 )
      result = (volatile uint32_t *)rf_switch_channel((int)v4);
    goto LABEL_22;
  }
  if ( *(volatile uint8_t *)off_12248C > v29 >> 1 && *(volatile uint8_t *)off_122474 )
LABEL_28:
    result = (volatile uint32_t *)rf_setup_channel((int)v4);
LABEL_22:
  if ( !v5 || *((volatile uint8_t *)off_12247C + 18) )
    *(volatile uint32_t *)off_122478 &= ~0x200u;
  else
    *(volatile uint32_t *)off_122478 |= 0x200u;
  *(volatile uint8_t *)(v2 + 2) = v5;
  *(volatile float *)(v2 + 4) = v8;
  return result;
}


// send_hci_event @ 0x12249c
int send_hci_event(char a1, char a2) {
  volatile uint8_t *v4; // r0

  v4 = (volatile uint8_t *)tx_send_pdu(89, 13, 0, 2);
  *v4 = a1;
  v4[1] = a2;
  return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v4)));
}



// process_rx_packet @ 0x1224bc
/* luna: Processes a received 802.11 beacon by checking its advertised channel, hashing information elements while excluding the TIM element, and forwarding it */
int process_rx_packet(int a1, int a2, int a3, volatile int *a4) {
  int v4; // r7
  int packet_len; // r11
  int frame_data; // r9
  int v7; // r4
  int channel_ie; // r0
  int advertised_channel; // r2
  int v11; // r3
  volatile uint32_t *v12; // r3
  int v13; // r1
  int frame_crc; // r0
  volatile int *v15; // r7
  volatile uint8_t *ie_cursor; // r1
  int v17; // r8
  unsigned int remaining_ie_len; // r4
  int ie_len; // r5
  volatile uint8_t *v20; // r10
  int result; // r0
  int rssi; // [sp+10h] [bp-Ch]
  int v24; // [sp+10h] [bp-Ch]
  int previous_crc; // [sp+14h] [bp-8h]

  v4 = a1;
  packet_len = *(volatile uint16_t *)(a1 + 28);
  frame_data = *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 8) + 8);
  v7 = a2;
  previous_crc = *(volatile uint32_t *)(a2 + 124);
  channel_ie = (int)(uintptr_t)(test_arg2_one_12da20((void *)(uintptr_t)(frame_data + 36), (uint16_t)(packet_len - 36)));
  if ( !channel_ie )
    goto LABEL_7;
  advertised_channel = *(volatile uint8_t *)(channel_ie + 2);
  v11 = *((volatile uint8_t *)off_122644 + 36);
  if ( !*((volatile uint8_t *)off_122644 + 36) )
  {
    if ( (unsigned int)(advertised_channel - 1) <= 0xD )
    {
      if ( advertised_channel == 14 )
        v11 = 2484;
      else
        v11 = 5 * advertised_channel + 2407;
    }
LABEL_6:
    if ( *(volatile uint16_t *)(v7 + 414) != v11 )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( v11 == 1 && (uint8_t)(advertised_channel - 1) <= 0xB0u )
  {
    v11 = 5 * advertised_channel + 5000;
    goto LABEL_6;
  }
  if ( !*(volatile uint16_t *)(v7 + 414) )
LABEL_7:
    *(volatile uint8_t *)(v7 + 128) = 0;
LABEL_8:
  if ( *(volatile uint8_t *)(v7 + 147) )
  {
    send_hci_event(*(volatile uint8_t *)(v7 + 107), 1);
    *(volatile uint16_t *)(v7 + 146) = 0;
    *(volatile uint8_t *)(v7 + 148) = 0;
  }
  v12 = (void *)(uintptr_t)(off_122648);
  *(volatile uint8_t *)(v7 + 141) = 1;
  if ( (int)(dword_12264C - v12[4] + *(volatile uint32_t *)(v7 + 120)) < 0 && !phy_is_channel_valid(*(volatile uint8_t *)(v7 + 116), 0, 0) )
    *(volatile uint32_t *)(v7 + 120) = *((volatile uint32_t *)off_122648 + 4);
  rssi = *(volatile char *)(v4 + 45);
  get_rf_field_lo();
  v13 = rssi;
  if ( *((volatile uint8_t *)off_122650 + 17) == 1 )
  {
    process_hci_packet((volatile uint32_t *)v7, rssi);
    v13 = rssi;
  }
  set_rf_tx_power_compensation((volatile uint8_t *)v7, v13);
  frame_crc = crc32_update((void *)(uintptr_t)(frame_data + 32), 4, 0);
  *a4 = 0;
  if ( (uint16_t)(packet_len - 36) > 1u )
  {
    v24 = v4;
    v15 = a4;
    ie_cursor = (volatile uint8_t *)(frame_data + 36);
    v17 = v7;
    remaining_ie_len = (uint16_t)(packet_len - 36);
    do
    {
      ie_len = (uint8_t)ie_cursor[1];
      v20 = ie_cursor + 2;
      if ( ie_len + 1 >= (int)remaining_ie_len )
        break;
      if ( *ie_cursor == 5 )
        *v15 = (int)ie_cursor;
      else
        frame_crc = crc32_update(v20, (uint8_t)ie_cursor[1], frame_crc);
      remaining_ie_len = (uint16_t)(remaining_ie_len + -2 - ie_len);
      ie_cursor = &v20[ie_len];
    }
    while ( remaining_ie_len > 1 );
    v7 = v17;
    a4 = v15;
    v4 = v24;
  }
  *(volatile uint32_t *)(v7 + 124) = frame_crc;
  rx_packet_proc(frame_data, packet_len, v4, v7, a3, *a4);
  result = hci_cmd_handler(4);
  if ( result != 1 )
    return *(volatile uint32_t *)(v7 + 124) != previous_crc;
  return result;
}



// ll_get_state @ 0x122654
volatile char * ll_get_state(volatile char *result) {
  int v1; // r4
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  volatile uint8_t *v6; // r1
  unsigned int v7; // r2
  volatile uint8_t *v8; // r3
  unsigned int v9; // r3

  if ( result[108] )
  {
    v1 = (int)result;
    if ( result[146] && result[148] )
    {
      v9 = (uint8_t)(result[146] - 1);
      result[146] = v9;
      if ( v9 <= 1 )
        return (volatile char *)alloc_ctrl_block((int)result);
      if ( v9 == 2 )
        send_hci_event(result[107], 0);
    }
    v2 = *(volatile uint32_t *)(v1 + 36);
    v3 = *(volatile uint32_t *)(dword_12272C + 696 * *(volatile uint8_t *)(v1 + 116) + 8) + v2;
    if ( v1 != *((volatile uint32_t *)off_122730 + 8)
      || (v8 = (void *)(uintptr_t)(off_122738), *(volatile uint32_t *)(v1 + 36) = v3, !v8[189]) && **(volatile uint8_t **)off_12273C != 2 )
    {
      mm_timer_set((void *)(uintptr_t)(v1 + 24), v3);
    }
    mmio_reg_addr(v1);
    bt_scan_poll((void *)(uintptr_t)(v1), *(volatile uint32_t *)(v1 + 136) + v2);
    result = (volatile char *)cfm_dword_get(v1, v2, v3);
    if ( !result )
    {
      v4 = (uint8_t)(*(volatile uint8_t *)(v1 + 128) + 1);
      v5 = *(volatile uint32_t *)(v1 + 4) | 1;
      v6 = *(volatile uint8_t **)off_122734;
      *(volatile uint8_t *)(v1 + 128) = v4;
      *(volatile uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (volatile char *)phy_is_channel_valid(*(volatile uint8_t *)(v1 + 116), (int)off_122740, v1);
      }
      else if ( v4 == v7 )
      {
        return (volatile char *)wifi_disable_action(v1);
      }
    }
  }
  return result;
}



// check_adv_enabled @ 0x122744
volatile char *check_adv_enabled() {
  int v0; // r4

  v0 = *(volatile uint32_t *)off_122794 & 0x1800000;
  if ( **(volatile int16_t **)off_122790 < 0 && v0 == 25165824 )
    irq_disable_mmio_write(dword_1227A4, dword_1227A0, 1308);
  irq_disable_global_3(v0);
  if ( *((volatile uint8_t *)off_122798 + 18) )
    return (volatile char *)((int (*)())ke_timer_handler)();
  else
    return ll_get_state(*((volatile char **)off_12279C + 8));
}



// get_rx_pdu @ 0x1227a8
int get_rx_pdu() {
  volatile int *v0; // r2
  int result; // r0
  volatile uint32_t *v2; // r3

  v0 = *((volatile int **)off_1227EC + 2);
  if ( v0 )
  {
    result = 0;
    while ( !*((volatile uint8_t *)v0 + 106) )
    {
      if ( *((volatile uint8_t *)v0 + 108) && (v2 = (volatile uint32_t *)v0[60]) != 0 )
      {
        do
        {
          v2 = (volatile uint32_t *)*v2;
          if ( *((volatile uint8_t *)v0 + 116) != 255 )
            result = (uint8_t)(result + 1);
        }
        while ( v2 );
        v0 = (volatile int *)*v0;
        if ( !v0 )
          return result;
      }
      else
      {
        v0 = (volatile int *)*v0;
        if ( !v0 )
          return result;
      }
    }
  }
  return 0;
}



// send_hci_command_status @ 0x1227f0
int send_hci_command_status(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)tx_send_pdu(11, a4, a3, 3);
  *v5 = ke_send_msg(a2, v5 + 1, v5 + 2);
  rx_process_packet_1((int)(uintptr_t)(v5));
  return 0;
}



