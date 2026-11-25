// adv_pdu_scan_req_handler @ 0x13b39c
int adv_pdu_scan_req_handler(int a1, volatile char *a2, unsigned int a3) {
  volatile char *v6; // r8
  char v7; // r10
  volatile unsigned int v8; // r3
  char v9; // r5
  char v10; // r6
  volatile char *v11; // r0
  uint16_t v12; // r3
  volatile char *v13; // r5
  volatile unsigned int v14; // r3

  if ( rx_rate_field_parse(a3) == 3 )
  {
    v6 = (volatile char *)off_13B540 + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          rf_get_chan_state(a3 >> 8);
          cmd_handler_a(dword_13B55C, (void *)(v6));
          rx_phy_status_parse(a3, 0);
        }
        else
        {
          v7 = v6[20];
          reset_tx_descriptor((int)off_13B540 + 32 * (a3 >> 8));
          v8 = (*(volatile uint32_t *)0x40501010u);
          *((volatile uint32_t *)v6 + 2) = v8;
          v9 = *a2;
          v10 = a2[1];
          v11 = (volatile char *)ke_msg_alloc(5131, 13, 5, 3);
          v11[2] = v7 - 4;
          *v11 = v9;
          v11[1] = v10;
          ke_msg_send_2((int)v11);
          rf_set_freq(a3 >> 8);
          rx_phy_status_parse(a3, 1);
        }
      }
      else if ( **(volatile int16_t **)off_13B53C < 0 )
      {
        call_shared_handler(off_13B54C, (int)aMmBaAddCfmHand, 218);
      }
    }
    else
    {
      v12 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_13B550)[92]);
      if ( HIBYTE(((volatile uint32_t *)(uintptr_t)off_13B550)[92]) )
        v12 = *(volatile uint8_t *)(dword_13B558
                                 + 1320
                                 * *(volatile uint8_t *)(dword_13B554 + 696 * *((volatile uint8_t *)off_13B540 + 16) + 34)
                                 + 106) == 0;
      v13 = (volatile char *)off_13B540 + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        adv_set_params(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((volatile uint16_t *)v13 + 10) << 6),
          0x25u,
          0);
        cmd_handler_a(dword_13B560, (void *)(v13));
        rx_phy_status_parse(a3, 0);
      }
      else
      {
        adv_set_params(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((volatile uint16_t *)v13 + 10) << 6),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        *(volatile uint8_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B554 + 452) = BYTE1(a3);
        v14 = (*(volatile uint32_t *)0x40501010u);
        *((volatile uint32_t *)v13 + 2) = v14;
        rf_set_freq(a3 >> 8);
        rx_phy_status_parse(a3, 1);
      }
    }
    return 0;
  }
  if ( **(volatile int16_t **)off_13B53C >= 0 )
    return 0;
  call_shared_handler(off_13B54C, (int)aMmBaAddCfmHand, 109);
  return 0;
}


// ll_ctl_terminate_ind @ 0x13b564
int ll_ctl_terminate_ind(int a1, volatile char *a2, unsigned int a3) {
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  uint8_t v9; // r7
  char v10; // r6
  volatile uint8_t *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( rx_rate_field_parse(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B5F4 + 32 * v5;
    if ( *(volatile uint8_t *)(v6 + 17) == 1 )
    {
      v7 = find_rates_ie(*(volatile uint32_t *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(volatile uint8_t *)(v6 + 20) + v7;
      v11 = (volatile uint8_t *)ke_msg_alloc(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      ke_msg_send_2((int)v11);
    }
    *(volatile uint32_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B5F8 + 448) = *((volatile uint32_t *)off_13B5FC
                                                                                                 + 4);
    rf_set_channel_3(v5);
  }
  return 0;
}



// adv_pdu_conn_req_check @ 0x13b600
int adv_pdu_conn_req_check(int a1, int a2, unsigned int a3) {
  int v4; // r0

  if ( rx_rate_field_parse(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B634;
    else
      v4 = dword_13B630;
    cmd_handler_a(v4, (volatile uint32_t *)(dword_13B62C + 32 * (a3 >> 8)));
  }
  return 0;
}


// adv_pdu_type_handler @ 0x13b638
int adv_pdu_type_handler(int a1, int a2, unsigned int a3) {
  if ( rx_rate_field_parse(a3) == 2 )
  {
    rf_get_chan_state(a3 >> 8);
    cmd_handler_a(dword_13B670, (volatile uint32_t *)(dword_13B66C + 32 * (a3 >> 8)));
    rx_phy_status_parse(a3, 0);
  }
  return 0;
}


// adv_flags_check @ 0x13b688
int adv_flags_check(int a1, int a2) {
  return *(volatile uint8_t *)(a1 + 264) & (a2 + *(volatile uint8_t *)(a1 + 262));
}



// adv_set_params @ 0x13b698
int adv_set_params(int a1, int a2, int a3, char a4, int16_t a5, int16_t a6, int a7) {
  int v7; // r9
  int v8; // r7
  int v9; // r8
  volatile int16_t **v10; // r10
  int v13; // r0
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // r5
  int v21; // r12
  int16_t v22; // r2
  int v23; // r5
  int v24; // r6
  volatile uint32_t *v25; // r1
  int v26; // r5
  volatile uint16_t *v28; // [sp+18h] [bp-14h]

  v7 = dword_13B8F4;
  v8 = dword_13B8D8;
  v9 = *(volatile uint8_t *)(dword_13B8F4 + 696 * a1 + 34);
  v10 = (volatile int16_t **)off_13B8F8;
  v13 = *(volatile uint32_t *)(dword_13B8D8 + 1320 * v9 + 72);
  if ( !v13 )
  {
    if ( **(volatile int16_t **)off_13B8F8 >= 0 )
    {
LABEL_19:
      result = (int)(uintptr_t)(ke_mutex_guard(1, 512));
      v16 = result;
      if ( !result )
        return result;
      goto LABEL_4;
    }
LABEL_18:
    mmio_clear_register(dword_13B8E4, dword_13B8E0, 520);
    goto LABEL_19;
  }
  v14 = *(volatile uint8_t *)(v13 + 4);
  if ( **(volatile int16_t **)off_13B8F8 < 0 && v14 == 2 )
    goto LABEL_18;
  result = (int)(uintptr_t)(ke_mutex_guard((*(volatile uint8_t *)(dword_13B8D8 + 1320 * v9 + 1224) | v14) != 0, 512));
  v16 = result;
  if ( !result )
    return result;
LABEL_4:
  rf_check_temperature(v8 + 1320 * v9, v16);
  v17 = *(volatile uint32_t *)(v16 + 72);
  v18 = 696 * a1 + 38;
  *(volatile uint8_t *)(v17 + 108) = -48;
  *(volatile uint8_t *)(v17 + 109) = 0;
  *(volatile uint8_t *)(v17 + 110) = 0;
  *(volatile uint8_t *)(v17 + 111) = 0;
  *(volatile uint16_t *)(v17 + 112) = *(volatile uint16_t *)(v7 + v18);
  v19 = v7 + v18;
  v20 = 1320 * v9 + 100;
  *(volatile uint16_t *)(v17 + 114) = *(volatile uint16_t *)(v7 + v18 + 2);
  *(volatile uint16_t *)(v17 + 116) = *(volatile uint16_t *)(v7 + v18 + 4);
  *(volatile uint16_t *)(v17 + 118) = *(volatile uint16_t *)(v8 + v20);
  v21 = v8 + v20;
  *(volatile uint16_t *)(v17 + 120) = *(volatile uint16_t *)(v8 + v20 + 2);
  v28 = (volatile uint16_t *)(v17 + 108);
  *(volatile uint16_t *)(v17 + 122) = *(volatile uint16_t *)(v8 + v20 + 4);
  if ( *(volatile uint8_t *)(v8 + 1320 * v9 + 106) == 2 )
  {
    *(volatile uint16_t *)(v17 + 124) = *(volatile uint16_t *)(v8 + v20);
    *(volatile uint16_t *)(v17 + 126) = *(volatile uint16_t *)(v21 + 2);
    *(volatile uint16_t *)(v17 + 128) = *(volatile uint16_t *)(v21 + 4);
  }
  else
  {
    *(volatile uint16_t *)(v17 + 124) = *(volatile uint16_t *)(v7 + v18);
    *(volatile uint16_t *)(v17 + 126) = *(volatile uint16_t *)(v19 + 2);
    *(volatile uint16_t *)(v17 + 128) = *(volatile uint16_t *)(v19 + 4);
  }
  v22 = *((volatile uint16_t *)off_13B8DC + 254) + 1;
  *((volatile uint16_t *)off_13B8DC + 254) = v22;
  *(volatile uint16_t *)(v17 + 130) = 16 * v22;
  *(volatile uint8_t *)(v16 + 51) = 0;
  *(volatile uint8_t *)(v16 + 53) = 0;
  *(volatile uint8_t *)(v16 + 28) = v9;
  *(volatile uint8_t *)(v16 + 29) = a1;
  if ( get_channel_tx_power(v16, 208, 3) == 1 )
  {
    ll_conn_window_calc(v16, v28, 24);
    v23 = *(volatile uint8_t *)(v16 + 51) + 24;
  }
  else
  {
    v23 = 24;
  }
  if ( a3 == 1 )
  {
    v24 = 3;
    v23 += build_packet_header((int)v28 + v23, a2, a5, a4, a6);
  }
  else if ( a3 == 2 )
  {
    v24 = *(volatile uint8_t *)(dword_13B8E8 + *(volatile uint8_t *)(a2 + 22));
    v23 += build_packet_header_v2((int)v28 + v23, a2, a6);
  }
  else if ( a3 )
  {
    if ( **v10 < 0 )
      call_shared_handler(dword_13B8F0, dword_13B8EC, 269);
    v24 = 3;
  }
  else
  {
    v24 = *(volatile uint8_t *)(dword_13B8E8 + *(volatile uint8_t *)(a2 + 22));
    v23 += build_tx_power_cfg((int)v28 + v23, a2);
  }
  v25 = *(volatile uint32_t **)(v16 + 76);
  v26 = v23 + *(volatile uint8_t *)(v16 + 53);
  v25[8] = v25[7] - 1 + v26;
  v25[9] = v26 + 4;
  if ( a7 )
  {
    *(volatile uint32_t *)(v16 + 88) = a7;
    *(volatile uint32_t *)(v16 + 92) = a2;
  }
  return tx_path_status(v16, v24);
}



// radio_timer_expired @ 0x13b8fc
unsigned int radio_timer_expired(int a1) {
  return ((unsigned int)(a1 - (*((volatile uint32_t *)off_13B90C + 4) >> 10)) >> 15) & 1;
}



// adv_pdu_rx_handler @ 0x13b910
int adv_pdu_rx_handler(int a1) {
  int v1; // r3
  int v2; // r6
  int ( *v4)(int, int); // r2
  uint8_t v5; // r0

  v1 = *(volatile uint8_t *)(a1 + 262) + a1;
  if ( *(volatile uint8_t *)(v1 + 6) != 2 )
    return 0;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  do
  {
    *(volatile uint8_t *)(v1 + 6) = 0;
    v4 = *(int ( **)(int, int))a1;
    *(volatile uint16_t *)(a1 + 4) = (*(volatile uint16_t *)(a1 + 4) + 1) & 0xFFF;
    v5 = v4(a1, 1);
    v1 = a1 + v5;
    *(volatile uint8_t *)(a1 + 262) = v5;
    v2 = (char)(v2 + 1);
  }
  while ( *(volatile uint8_t *)(v1 + 6) == 2 );
  return v2;
}



// event_timer_callback @ 0x13b954
int event_timer_callback(int a1, int16_t a2, char a3) {
  int result; // r0

  result = (*(int ( **)(int, int))a1)(a1, (a2 - *(volatile uint16_t *)(a1 + 4)) & 0xFFF) + a1;
  *(volatile uint8_t *)(result + 6) = a3;
  return result;
}



// ll_global_init @ 0x13b96c
int ll_global_init() {
  volatile uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  int result; // r0

  v0 = (volatile uint32_t *)dword_13BA00;
  zero_8_bytes((volatile uint32_t *)dword_13BA00);
  zero_8_bytes(v0 + 2);
  zero_8_bytes(v0 + 4);
  zero_8_bytes(v0 + 6);
  zero_8_bytes(v0 + 8);
  zero_8_bytes(v0 + 10);
  v1 = dword_13BA04;
  v2 = dword_13BA08;
  for ( i = 0; ; ++i )
  {
    *(volatile uint8_t *)(v1 + 16) = -1;
    *(volatile uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    cmd_handler_a((int)v0, (volatile uint32_t *)v1);
    rx_phy_status_parse((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(volatile uint32_t *)(v1 + 28) = v2 + 268 * i;
  cmd_handler_a((int)(v0 + 6), (volatile uint32_t *)v1);
  result = rx_phy_status_parse((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}


// rf_set_freq @ 0x13ba0c
int rf_set_freq(int16_t a1) {
  return ke_task_create(8194, (uint16_t)(a1 << 8) | 8, 0x1F4000u);
}



// rf_get_chan_state @ 0x13ba24
volatile uint8_t * rf_get_chan_state(int a1) {
  volatile uint8_t *result; // r0
  int v2; // r1
  int v3; // r3

  result = (volatile uint8_t *)(dword_13BA70 + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(volatile uint8_t *)(696 * v2 + 12 * v3 + dword_13BA74 + 453) = 33;
  }
  else
  {
    *(volatile uint8_t *)(696 * v2 + 12 * v3 + dword_13BA74 + 452) = 33;
  }
  return result;
}



// tx_done_queue @ 0x13ba78
int tx_done_queue(volatile int **a1) {
  volatile int *v1; // r6
  int result; // r0
  unsigned int v3; // r4
  volatile int **v4; // r3
  volatile int *v5; // r1
  unsigned int v6; // r2
  int v7; // r3

  v1 = *a1;
  if ( !*a1 )
    return 33;
  result = 0;
  v3 = 0;
  v4 = (volatile int **)v1;
  do
  {
    v5 = v4[2];
    v6 = *((volatile uint32_t *)off_13BAC0 + 4) - (uint32_t)v5;
    if ( v6 > v3 )
      result = *((volatile uint8_t *)v4 + 26);
    v4 = (volatile int **)*v4;
    if ( v6 > v3 )
      v3 = *((volatile uint32_t *)off_13BAC0 + 4) - (uint32_t)v5;
  }
  while ( v4 );
  v7 = dword_13BAC4 + 32 * result;
  if ( v3 <= *(volatile uint16_t *)(v7 + 14) << 10 || *(volatile uint32_t *)(v7 + 4) )
    return *((volatile uint8_t *)v1 + 26);
  else
    return (uint16_t)result;
}



// ll_cmd_handler @ 0x13bac8
int ll_cmd_handler(int a1, volatile uint16_t *a2, int a3) {
  int v4; // r4
  unsigned int v6; // r3
  unsigned int v7; // r8
  unsigned int v8; // r5
  int v9; // r6
  char v10; // r7
  int v11; // r0
  unsigned int v12; // r3
  unsigned int v13; // r2

  if ( a3 != 1 )
  {
    if ( a3 == 2 )
    {
      v12 = a2[1];
      v13 = v12 >> 12;
      if ( v12 < 0x9000 && a1 != 255 )
      {
        if ( (v12 & 0x800) != 0 )
          return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BC18 + 452);
        else
          return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BC18 + 453);
      }
    }
    else if ( !a3 )
    {
      v7 = *(volatile uint16_t *)((volatile char *)a2 + 3);
      v8 = (v7 >> 2) & 0xF;
      if ( v8 <= 8 )
      {
        v9 = (uint8_t)a1;
        v10 = *((volatile uint8_t *)a2 + 2);
        if ( phy_read_offset_b((uint8_t)a1, (v7 >> 2) & 0xF) )
          return *(volatile uint8_t *)(696 * v9 + 12 * v8 + dword_13BC18 + 452);
        if ( *((volatile uint32_t *)off_13BC1C + 4) - 500000 - *(volatile uint32_t *)(696 * v9 + 12 * v8 + dword_13BC18 + 448) >= 0 )
        {
          if ( *(volatile uint8_t *)(dword_13BC18 + 696 * a1 + 36) == 1 )
            goto LABEL_22;
          if ( *(volatile uint32_t *)off_13BC20 )
          {
            v4 = *((volatile uint8_t *)mem_word_load((int)off_13BC20) + 26);
            if ( v4 != 33 )
              return v4;
          }
          v11 = tx_done_queue((volatile int **)dword_13BC24);
          if ( v11 == 33 )
          {
LABEL_22:
            adv_set_params(v9, 0, 1, v10, v7, 37, 0);
            return 33;
          }
          else
          {
            v4 = v11;
            ke_msg_send_no_param(8193, ((uint16_t)v11 << 8) | 8, 255);
          }
          return v4;
        }
      }
    }
    return 33;
  }
  v6 = (*(volatile uint16_t *)((volatile char *)a2 + 5) >> 2) & 0xF;
  if ( v6 > 8 )
    return 33;
  return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v6 + dword_13BC18 + 453);
}



// rf_set_channel_3 @ 0x13bc28
int rf_set_channel_3(unsigned int a1) {
  unsigned int v1; // r5
  int v3; // r1
  volatile uint8_t *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  volatile uint32_t *v8; // r1
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  ke_int_lock((int)(uintptr_t)((volatile char *)0x2000), v1);
  ke_int_lock((int)(uintptr_t)((volatile char *)0x2002), v1);
  v3 = dword_13BCD0;
  v4 = (volatile uint8_t *)(dword_13BCD0 + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(volatile uint8_t *)(696 * v6 + 12 * v7 + dword_13BCD4 + 453) = 33;
    v8 = (volatile uint32_t *)(v3 + 32 * a1);
    a2 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    cmd_handler_c(dword_13BCE0, v8);
    cmd_handler_a(dword_13BCE4, a2);
    return rx_phy_status_parse(v1, 0);
  }
  v8 = (volatile uint32_t *)(dword_13BCD0 + 32 * a1);
  *(volatile uint8_t *)(696 * v6 + 12 * v7 + dword_13BCD4 + 452) = 33;
  a2 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  cmd_handler_c(dword_13BCD8, v8);
  cmd_handler_a(dword_13BCDC, a2);
  return rx_phy_status_parse(v1, 0);
}


// rf_pll_calibrate @ 0x13bce8
int rf_pll_calibrate(int result) {
  int v1; // r4
  int v2; // r5
  void *a7; // r10
  int v4; // r7
  int16_t v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BD54;
  v2 = dword_13BD58;
  a7 = (void *)(uintptr_t)(off_13BD5C);
  v4 = result;
  v5 = -128 * dword_13BD54;
  v6 = dword_13BD54 + 64;
  do
  {
    v7 = *(volatile uint16_t *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(volatile uint8_t *)(v2 + 16) == v4 )
      {
        rx_phy_status_parse((uint16_t)(v5 + ((uint16_t)v1 << 7) - 256) | 8, 4);
        *(volatile uint8_t *)(v2 + 25) = 0;
        result = adv_set_params(v4, v2, 2, 0, 0, 0x27u, (int)a7);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}


// rf_ctrl_send @ 0x13bd60
int rf_ctrl_send(char a1, int a2) {
  int v2; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v2 = a2;
  v4 = ke_msg_alloc(40, 0, ((uint16_t)a2 << 8) | 8, 8u);
  v5 = dword_13BDA0 + 32 * v2;
  v6 = *(volatile uint8_t *)(v5 + 17);
  *(volatile uint8_t *)(v4 + 1) = a1;
  *(volatile uint8_t *)v4 = v6 != 1;
  *(volatile uint8_t *)(v4 + 2) = *(volatile uint8_t *)(v5 + 22);
  v2 = (v2 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 20)) & 0xFFFFu);
  *(volatile uint16_t *)(v4 + 6) = *(volatile uint16_t *)(v5 + 12);
  *(volatile uint16_t *)(v4 + 4) = v2;
  return (int)(uintptr_t)(ke_msg_send_2(v4));
}



// rf_phy_write @ 0x13bda4
int rf_phy_write(int a1, int a2) {
  unsigned int v2; // r5
  volatile int *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (uint16_t)((uint16_t)a2 << 8) | 8;
  v5 = (volatile int *)ke_msg_alloc(42, 0, ((uint16_t)a2 << 8) | 8, 3u);
  if ( **(volatile int16_t **)off_13BE04 < 0 && rx_rate_field_parse(v2) != 4 )
    mmio_clear_register(dword_13BE10, dword_13BE0C, 891);
  v6 = dword_13BE08 + 32 * a2;
  v7 = *(volatile uint8_t *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(volatile uint8_t *)(v6 + 22);
  return (int)(uintptr_t)(ke_msg_send_2((int)v5));
}



// rf_scan_chan @ 0x13be14
int rf_scan_chan(int result) {
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BE98;
  v2 = dword_13BE8C;
  v3 = dword_13BE90;
  v4 = result;
  v5 = dword_13BE98 - 8;
  v6 = dword_13BE98 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(volatile uint16_t *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(volatile uint8_t *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        cmd_handler_c(v6, (volatile uint32_t *)v3);
        cmd_handler_a(dword_13BE94, (volatile uint32_t *)v3);
      }
      else
      {
        cmd_handler_c(v1, (volatile uint32_t *)v3);
        cmd_handler_a(v5, (volatile uint32_t *)v3);
      }
      rx_phy_status_parse((uint16_t)((uint16_t)i << 8) | 8, 4);
      result = rf_phy_write(v4, (uint16_t)i);
    }
    v3 += 32;
  }
  return result;
}


// rf_get_chan_param_1 @ 0x13bef8
int rf_get_chan_param_1(unsigned int a1) {
  int v1; // r5
  int v2; // r6
  int v3; // r7
  unsigned int v5; // r8
  unsigned int v6; // r0
  void *v7; // r4

  v1 = dword_13BF60;
  v2 = dword_13BF60 + 32 * a1;
  v3 = *(volatile uint8_t *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    cmd_handler_c(dword_13BF70, (volatile uint32_t *)v2);
    cmd_handler_a(dword_13BF74, (volatile uint32_t *)v2);
  }
  else
  {
    cmd_handler_c(dword_13BF64, (volatile uint32_t *)v2);
    cmd_handler_a(dword_13BF68, (volatile uint32_t *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = (void *)(uintptr_t)(off_13BF6C);
  rx_phy_status_parse(v6 | 8, 4);
  *(volatile uint8_t *)(v1 + v5 + 25) = 0;
  return adv_set_params(v3, v2, 2, 0, 0, 0x27u, (int)v7);
}


// read_global_state_byte @ 0x13bf78
int read_global_state_byte() {
  volatile uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = (void *)(uintptr_t)(off_13BFAC);
  if ( !*((volatile uint32_t *)off_13BFAC + 6)
    || (result = *((volatile uint8_t *)mem_word_load((int)off_13BFAC + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (uint8_t)tx_done_queue((volatile int **)dword_13BFB0);
    if ( (uint8_t)v2 == 33 )
    {
      return 33;
    }
    else
    {
      rf_get_chan_param_1(v2);
      return 33;
    }
  }
  return result;
}



// check_fw_state_byte @ 0x13bfb4
int check_fw_state_byte(int a1, int a2, uint16_t a3) {
  uint16_t v6; // r0
  char v7; // r11
  int v8; // r4
  uint16_t v9; // r6
  char v10; // r0
  uint16_t v11; // r12
  int v12; // r2
  int v13; // zf
  uint16_t v14; // r0
  int v15; // r7
  volatile unsigned int v16; // r2
  uint16_t v17; // r6
  volatile unsigned int v18; // r3

  v6 = read_global_state_byte(a1, a2);
  v7 = v6;
  if ( (uint8_t)v6 == 33 )
    return 3;
  v8 = dword_13C094 + 32 * (uint8_t)v6;
  v9 = v6;
  *(volatile uint8_t *)(v8 + 22) = a2;
  *(volatile uint8_t *)(v8 + 16) = a1;
  v10 = scale_timer_value();
  v12 = dword_13C098;
  *(volatile uint8_t *)(v8 + 23) = v10;
  v13 = (*(volatile uint32_t *)(v12 + 696 * a1 + 4) & 0x20) == 0;
  v14 = *(volatile uint16_t *)(*(volatile uint32_t *)off_13C09C + 2);
  *(volatile uint8_t *)(v8 + 18) = 1;
  *(volatile uint8_t *)(v8 + 17) = 1;
  *(volatile uint32_t *)(v8 + 4) = 0;
  v15 = v12 + 696 * a1 + 12 * a2;
  if ( !v13 )
    v11 = 256;
  v16 = (*(volatile uint32_t *)0x40501010u);
  if ( v13 )
    v11 = 64;
  *(volatile uint16_t *)(v8 + 20) = v11;
  *(volatile uint16_t *)(v8 + 14) = v14;
  *(volatile uint32_t *)(v8 + 8) = v16;
  *(volatile uint16_t *)(v8 + 12) = a3;
  *(volatile uint8_t *)(v15 + 453) = v7;
  adv_set_params(a1, v8, 2, 0, 0, 0x27u, 0);
  v17 = (v9 << 8) | 8;
  adv_set_params(a1, v8, 0, 0, 0, 0, 0);
  v18 = (*(volatile uint32_t *)0x40501010u);
  *(volatile uint32_t *)(v15 + 444) = v18;
  ke_task_create(0x2000, v17, 0x7D000u);
  rx_phy_status_parse(v17, 2);
  return 0;
}


// lookup_interface_info @ 0x13c0a4
int lookup_interface_info(int a1, int a2) {
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13C110;
  v5 = *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * (uint8_t)a2 + dword_13C110 + 453);
  return v5 == 33
      || rx_rate_field_parse((v5 << 8) | 8) != 1
      || *(volatile uint16_t *)(dword_13C114 + 32 * v5 + 20) > ((*(volatile uint16_t *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(volatile uint16_t *)(*(volatile uint32_t *)(dword_13C114 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}



// read_tx_power_cal @ 0x13c118
unsigned int read_tx_power_cal(unsigned int result) {
  int v1; // r1
  int v2; // r2
  int v3; // r5
  int v4; // r6
  int v5; // r12
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r7
  int v9; // r2
  int v10; // r8
  int v11; // r9
  int v12; // r7
  int v13; // r9
  int16_t v14; // r3
  int ( *v15)(int, int); // r2
  int16_t v16; // r1

  v1 = *(volatile uint8_t *)(result + 27);
  v2 = *((volatile uint32_t *)off_13C270 + 4);
  if ( v1 != 255 )
  {
    v3 = *(volatile uint8_t *)(result + 29);
    v4 = dword_13C274;
    v5 = dword_13C274 + 696 * v3;
    v6 = result;
    result = *(volatile uint32_t *)(v5 + 4) << 30;
    if ( (*(volatile uint32_t *)(v5 + 4) & 2) != 0 )
    {
      v7 = 696 * v3 + 12 * v1 + dword_13C274;
      v8 = *(volatile uint8_t *)(v7 + 453);
      ++*(volatile uint8_t *)(v7 + 455);
      if ( v8 == 33 )
      {
        result = v2 + 1000000 - *(volatile uint32_t *)(v7 + 444);
        if ( result > dword_13C28C && v2 - 500000 - *(volatile uint32_t *)(v7 + 448) >= 0 && *(volatile uint8_t *)(v5 + 36) != 1 )
        {
          result = dword_13C27C;
          v9 = *(volatile uint8_t *)(dword_13C278 + v1);
          if ( !*(volatile uint32_t *)(dword_13C27C + 84 * v9)
            && !*(volatile uint32_t *)(dword_13C284 + 8 * v9)
            && !*(volatile uint32_t *)(v4 + 8 * (v9 + 87 * v3 + 78)) )
          {
            result = dword_13C288;
            if ( !*(volatile uint32_t *)(dword_13C288 + 8 * (165 * *(volatile uint8_t *)(v6 + 28) + v9 + 159)) )
              return check_fw_state_byte(v3, v1, *(volatile uint16_t *)(v6 + 32));
          }
        }
      }
      else
      {
        v10 = dword_13C290;
        v11 = dword_13C290 + 32 * v8;
        *(volatile uint32_t *)(v11 + 8) = v2;
        result = rx_rate_field_parse((v8 << 8) | 8);
        v12 = 32 * v8;
        if ( result == 1 )
        {
          v13 = *(volatile uint32_t *)(v11 + 28);
          v14 = *(volatile uint16_t *)(v6 + 30);
          result = *(volatile uint16_t *)(v13 + 4);
          *(volatile uint16_t *)(v6 + 34) = result;
          if ( (v14 & 1) == 0 || (v14 & 3) == 3 )
          {
            if ( (*(volatile uint8_t *)(*(volatile uint32_t *)(v4 + 696 * v3 + 340) + 166) & 4) != 0 )
              *(volatile uint32_t *)(v6 + 36) |= 0x200000u;
            v15 = *(int ( **)(int, int))v13;
            v16 = *(volatile uint16_t *)(v6 + 32) - result;
            *(volatile uint16_t *)(v6 + 30) = v14 | 2;
            result = v15(v13, v16 & 0xFFF) + v13;
            *(volatile uint8_t *)(result + 6) = 1;
            if ( (*(volatile uint16_t *)(v6 + 30) & 1) == 0 )
              *(volatile uint16_t *)(v6 + 64) = *((volatile uint16_t *)off_13C280 + 22) + (*((volatile uint32_t *)off_13C270 + 4) >> 10);
            ++*(volatile uint32_t *)(v12 + v10 + 4);
          }
        }
      }
    }
  }
  return result;
}



// get_tx_power_cal_entry @ 0x13c294
int get_tx_power_cal_entry(int a1, int a2, int a3) {
  int v4; // r3
  int v5; // r3
  int i; // r4
  int v8; // r4
  int v11; // r4
  int v12; // r0
  int v13; // r6
  int v14; // r2
  volatile unsigned int v15; // r3
  volatile unsigned int v16; // r3
  int v17; // r3
  int ( *v18)(int, int); // r2
  uint8_t v19; // r0
  volatile unsigned int v20; // r2

  v4 = 696 * *(volatile uint8_t *)(a1 + 29);
  if ( (*(volatile uint32_t *)(dword_13C39C + v4 + 4) & 2) == 0 )
    return 1;
  v5 = v4 + 12 * *(volatile uint8_t *)(a1 + 27) + dword_13C39C;
  --*(volatile uint8_t *)(v5 + 455);
  if ( (*(volatile uint16_t *)(a1 + 30) & 2) == 0 )
    return 1;
  v8 = *(volatile uint8_t *)(v5 + 453);
  if ( v8 == 33 || rx_rate_field_parse((v8 << 8) | 8) != 1 )
    return 1;
  v11 = dword_13C3A0 + 32 * v8;
  v12 = *(volatile uint32_t *)(a1 + 36) << 10;
  v13 = *(volatile uint32_t *)(v11 + 28);
  --*(volatile uint32_t *)(v11 + 4);
  if ( v12 < 0 )
  {
    if ( a3 )
    {
      if ( !a2 )
      {
        v14 = *(volatile uint16_t *)(a1 + 64);
        v15 = (*(volatile uint32_t *)0x40501010u);
        if ( ((v14 - (v15 >> 10)) & 0x8000) == 0 )
        {
          v16 = (*(volatile uint32_t *)0x40501010u);
          event_dispatch("move win since flush: succ=%d, timepast=%d\n", 0, ((v14 - (v16 >> 10)) >> 15) & 1);
        }
      }
    }
    else if ( !a2 )
    {
      v20 = (*(volatile uint32_t *)0x40501010u);
      if ( ((*(volatile uint16_t *)(a1 + 64) - (v20 >> 10)) & 0x8000) == 0 )
      {
        i = 0;
        *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 76) + 4) |= 2u;
        return i;
      }
    }
  }
  *(volatile uint8_t *)((*(int ( **)(int, int))v13)(v13, (*(volatile uint16_t *)(a1 + 32) - *(volatile uint16_t *)(v13 + 4)) & 0xFFF) + v13 + 6) = 2;
  v17 = *(volatile uint8_t *)(v13 + 262) + v13;
  for ( i = 0; *(volatile uint8_t *)(v17 + 6) == 2; i = (char)(i + 1) )
  {
    *(volatile uint8_t *)(v17 + 6) = 0;
    v18 = *(int ( **)(int, int))v13;
    *(volatile uint16_t *)(v13 + 4) = (*(volatile uint16_t *)(v13 + 4) + 1) & 0xFFF;
    v19 = v18(v13, 1);
    v17 = v13 + v19;
    *(volatile uint8_t *)(v13 + 262) = v19;
  }
  return i;
}


// reset_tx_descriptor @ 0x13c3ac
int reset_tx_descriptor(int a1) {
  int v1; // r5
  int result; // r0
  int16_t v4; // r2
  int v5; // r3
  int v6; // zf

  v1 = *(volatile uint32_t *)(a1 + 28);
  memset((volatile int *)(v1 + 6), 0, 0x100u);
  result = 348;
  v4 = *(volatile uint16_t *)(dword_13C3F4 + 2 * (*(volatile uint8_t *)(a1 + 22) + 348 * *(volatile uint8_t *)(a1 + 16)) + 316);
  *(volatile uint8_t *)(v1 + 262) = 0;
  v5 = *(volatile uint8_t *)(a1 + 20);
  *(volatile uint16_t *)(v1 + 4) = v4;
  v6 = ((v5 - 1) & v5) == 0;
  *(volatile uint8_t *)(v1 + 263) = v5;
  if ( ((v5 - 1) & v5) != 0 )
    v5 = dword_13C3F8;
  else
    *(volatile uint8_t *)(v1 + 264) = v5 - 1;
  if ( v6 )
    v5 = dword_13C3FC;
  *(volatile uint32_t *)v1 = v5;
  return result;
}



// find_rates_ie @ 0x13c400
int find_rates_ie(int a1) {
  int v1; // r3
  int v2; // r1
  int result; // r0
  int v4; // t1

  if ( !*(volatile uint8_t *)(a1 + 263) )
    return *(volatile uint8_t *)(a1 + 263);
  v1 = a1 + 5;
  v2 = *(volatile uint8_t *)(a1 + 263) + a1 + 5;
  result = 0;
  do
  {
    v4 = *(volatile uint8_t *)++v1;
    if ( v4 == 2 )
      result = (char)(result + 1);
  }
  while ( v1 != v2 );
  return result;
}



// lookup_tx_power_limit @ 0x13c424
int lookup_tx_power_limit(int a1, int a2) {
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C470;
  v3 = *(volatile uint8_t *)(result + 452);
  if ( **(volatile int16_t **)off_13C46C < 0 && v3 > 0x20 )
    result = mmio_clear_register(dword_13C480, dword_13C47C, 1152);
  *(volatile uint32_t *)(dword_13C474 + 32 * v3 + 8) = *((volatile uint32_t *)off_13C478 + 4);
  return result;
}



// is_mgmt_action_frame @ 0x13c484
BOOL is_mgmt_action_frame(char a1, unsigned int a2) {
  int v2; // r3

  if ( (a1 & 0xC) != 0 )
    return 0;
  v2 = a1 & 0xF0;
  if ( v2 == 192 )
    return 1;
  if ( v2 != 208 )
    return v2 == 160;
  if ( a2 <= 0x16 )
  {
    if ( a2 > 3 )
    {
      switch ( a2 )
      {
        case 4u:
        case 7u:
        case 0xBu:
        case 0xFu:
        case 0x16u:
          return 0;
        default:
          return 1;
      }
    }
    return 1;
  }
  return a2 != 127;
}


// lookup_rate_table_entry @ 0x13c518
unsigned int lookup_rate_table_entry(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
  int v4; // r6
  int v5; // r11
  int v6; // r9
  int v10; // r2
  int v11; // r3
  int v12; // r8
  int v13; // r7
  volatile uint8_t *v15; // r0
  int v16; // lr
  int v17; // r12
  volatile uint8_t *v18; // r1
  volatile uint8_t *v19; // r0
  volatile uint8_t *v20; // r1
  int v21; // t1
  int v22; // r9
  int v23; // r10
  int v24; // r0
  int v25; // r1
  int v26; // zf
  int v27; // r11
  uint64_t v28; // [sp+8h] [bp-Ch]

  v4 = a1[8];
  v5 = *(volatile uint16_t *)a1;
  v6 = *(volatile uint8_t *)(v4 + a2);
  if ( !is_mgmt_action_frame(v5, v6) )
    return 0;
  v11 = a1[9];
  if ( v11 == 255 )
    goto LABEL_9;
  v12 = a1[10];
  if ( v12 == 255 )
    goto LABEL_9;
  v13 = v10;
  if ( !*(volatile uint32_t *)(dword_13C690 + 1320 * v12 + 1200) )
    return 0;
  if ( (a1[48] & 8) == 0 )
  {
    if ( (*(volatile uint32_t *)(dword_13C694 + 696 * v11 + 4) & 8) != 0 && (v5 & 0x4000) == 0 )
    {
      v27 = v5 & 0xFC;
      if ( (v27 == 192 || v27 == 160) && (unsigned int)(v6 - 6) <= 1 )
      {
        *a4 = 1;
        return 1;
      }
LABEL_9:
      *a4 = 0;
      return 1;
    }
    return 0;
  }
  if ( (v5 & 0xFC) != 0xD0 || (unsigned int)(v6 - 13) > 1 )
  {
    if ( *(volatile uint32_t *)(dword_13C690 + 1320 * v12 + 1204) )
    {
      if ( v4 + 19 >= v10 )
        goto LABEL_9;
      v15 = check_one_12dba0((volatile uint8_t *)(v4 + a2 + 2), (uint16_t)(v10 - 2 - v4));
      if ( !v15 )
        goto LABEL_9;
      v16 = *((volatile uint16_t *)v15 + 1);
      if ( (unsigned int)(v16 - 4) > 1 )
        goto LABEL_9;
      v17 = 1320 * v12 + 120 * v16 + dword_13C690;
      if ( !*(volatile uint8_t *)(v17 + 579) )
        goto LABEL_9;
      v28 = *((volatile uint32_t *)v15 + 1) & 0xFFFFFFLL;
      if ( *(volatile uint64_t *)(v17 + 480) >= (uint64_t)(*((volatile uint32_t *)v15 + 1) & 0xFFFFFF) )
        goto LABEL_9;
      v18 = v15;
      v19 = v15 + 18;
      v21 = *(volatile uint32_t *)(v18 + 10);
      v20 = v18 + 10;
      v22 = v21;
      v23 = *((volatile uint32_t *)v20 + 1);
      *(volatile uint64_t *)(v17 + 480) = v28;
      do
        *v20++ = 0;
      while ( v20 != v19 );
      v24 = rf_get_tx_pwr(1320 * v12 + 480 + 120 * v16 + dword_13C690, (void *)(uintptr_t)(a2), v13 - 18, v4, 0);
      v26 = v23 == v25;
      if ( v23 == v25 )
        v26 = v22 == v24;
      if ( !v26 )
        goto LABEL_9;
    }
    return 0;
  }
  return ((v5 ^ 0x4000u) >> 14) & 1;
}



// get_channel_tx_power @ 0x13c698
int get_channel_tx_power(int a1, int a2, int a3) {
  int v3; // r5
  int v4; // r6
  int v5; // r7
  int result; // r0
  char v7; // r4
  int v8; // r2
  int v9; // r5

  v3 = *(volatile uint8_t *)(a1 + 29);
  v4 = *(volatile uint8_t *)(a1 + 28);
  if ( v3 == 255 )
    return 0;
  v5 = dword_13C708;
  result = *(volatile uint32_t *)(dword_13C708 + 1320 * v4 + 1200);
  if ( result )
  {
    v7 = a2;
    result = is_mgmt_action_frame(a2, a3);
    if ( result )
    {
      v9 = 696 * v3;
      result = *(volatile uint8_t *)(v9 + dword_13C70C) & 1;
      if ( (*(volatile uint8_t *)(v9 + dword_13C70C) & 1) != 0 )
      {
        if ( (v7 & 0xFC) != 0xD0 || (unsigned int)(v8 - 13) > 1 )
        {
          if ( *(volatile uint32_t *)(v5 + 1320 * v4 + 1204) )
            return 2;
          else
            return 0;
        }
      }
      else
      {
        return (*(volatile uint32_t *)(v9 + dword_13C70C - 34) >> 3) & 1;
      }
    }
  }
  return result;
}



// is_conn_active @ 0x13c710
int is_conn_active(int a1, int a2, int a3, int a4) {
  int result; // r0
  int v5; // lr
  uint64_t v6; // r4
  uint64_t v7; // kr00_8
  volatile uint8_t *v8; // r8
  int v9; // r5
  unsigned int v10; // r4
  int v11; // r6
  volatile uint8_t *v12; // r6
  volatile uint8_t *v13; // r4
  unsigned int v14; // r0
  unsigned int v15; // r1
  int i; // r3
  int v17; // r2
  unsigned int v18; // r4

  result = *(volatile uint32_t *)(dword_13C7D0 + 1320 * *(volatile uint8_t *)(a1 + 28) + 1204);
  if ( result )
  {
    if ( a4 )
      v5 = a4;
    else
      v5 = a3 + a2;
    *(volatile uint8_t *)v5 = 76;
    *(volatile uint8_t *)(v5 + 1) = 16;
    v6 = *(volatile uint64_t *)(result + 72);
    *(volatile uint16_t *)(v5 + 2) = *(volatile uint8_t *)(result + 97);
    v7 = v6 + 1;
    *(volatile uint64_t *)(result + 72) = v6 + 1;
    v8 = (volatile uint8_t *)(v5 + 4);
    v9 = 0;
    while ( 1 )
    {
      v10 = ((unsigned int)v7 >> v9) | (HIDWORD(v7) << (32 - v9));
      v11 = HIDWORD(v7) >> (v9 - 32);
      v9 += 8;
      *v8++ = v10 | v11;
      if ( v9 == 48 )
        break;
      v7 = *(volatile uint64_t *)(result + 72);
    }
    v12 = (volatile uint8_t *)(v5 + 10);
    v13 = (volatile uint8_t *)(v5 + 10);
    do
      *v13++ = 0;
    while ( (volatile uint8_t *)(v5 + 18) != v13 );
    v14 = rf_get_tx_pwr(result, (void *)(uintptr_t)(a2), a3, 24, a4);
    for ( i = 0; i != 64; i += 8 )
    {
      v17 = (v14 >> i) | (v15 << (32 - i));
      v18 = v15 >> (i - 32);
      *v12++ = v17 | v18;
    }
    return 18;
  }
  return result;
}



// bt_get_dev_info @ 0x13c7d4
int bt_get_dev_info(volatile uint32_t *a1, volatile uint32_t *a2) {
  int v2; // r3
  int v3; // r4
  int v4; // r8
  int v7; // r0
  int v8; // r1
  int v9; // r5
  int v10; // r9
  int v11; // lr
  int v12; // r9
  int v13; // r5
  int v14; // r2
  int v15; // r11
  int v16; // r12
  int v17; // lr
  unsigned int v18; // r9
  int v19; // r7
  int v20; // r2
  int v21; // r1
  uint8_t v22; // r6^2
  int v23; // r5
  int v24; // r3
  int v25; // r1
  int v26; // r0
  unsigned int v27; // r7
  unsigned int v28; // r6
  int v29; // r1
  int v30; // r3
  int v31; // r1
  int v32; // r0
  int v33; // r8
  int v34; // r6
  int v35; // r7
  int v36; // r1
  int v37; // r4
  int v38; // r0
  int v39; // r6
  int result; // r0
  unsigned int v41; // [sp+0h] [bp-3Ch]
  int v42; // [sp+0h] [bp-3Ch]
  int v43; // [sp+0h] [bp-3Ch]
  unsigned int v44; // [sp+4h] [bp-38h]
  unsigned int v45; // [sp+8h] [bp-34h]
  unsigned int v46; // [sp+Ch] [bp-30h]
  int v47; // [sp+Ch] [bp-30h]
  int v49; // [sp+14h] [bp-28h]
  volatile uint32_t *v50; // [sp+1Ch] [bp-20h]
  int v51; // [sp+24h] [bp-18h]
  int v52; // [sp+28h] [bp-14h]
  volatile uint32_t *v53; // [sp+30h] [bp-Ch]

  v2 = a2[1];
  v3 = dword_13CA98;
  v4 = dword_13CAA0;
  v44 = *a2 ^ *a1;
  v7 = a2[3];
  v8 = a2[2];
  *a2 = v44;
  v50 = a1;
  v9 = v2 ^ a1[1];
  a2[1] = v9;
  v41 = v9;
  v10 = v8 ^ a1[2];
  a2[2] = v10;
  v46 = v10;
  v45 = a1[3] ^ v7;
  v53 = a1 + 36;
  do
  {
    v49 = *(volatile uint8_t *)(v3 + BYTE1(v41));
    v51 = *(volatile uint8_t *)(v3 + BYTE1(v46));
    v11 = *(volatile uint8_t *)(v3 + BYTE2(v46));
    v12 = *(volatile uint8_t *)(v3 + BYTE2(v45));
    v13 = v11 ^ *(volatile uint8_t *)(v4 + (uint8_t)v44) ^ *(volatile uint8_t *)(dword_13CA9C + HIBYTE(v45)) ^ v49;
    v14 = ((*(volatile uint8_t *)(v4 + HIBYTE(v45))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v44)
          ^ v49
          ^ *(volatile uint8_t *)(dword_13CA9C + BYTE2(v46))) << 16)
        | ((*(volatile uint8_t *)(dword_13CA9C + BYTE1(v41))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v44)
          ^ *(volatile uint8_t *)(v3 + HIBYTE(v45))
          ^ *(volatile uint8_t *)(v4 + BYTE2(v46))) << 8)
        | v11
        ^ *(volatile uint8_t *)(v3 + HIBYTE(v45))
        ^ *(volatile uint8_t *)(dword_13CA9C + (uint8_t)v44)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v41));
    v15 = v12 ^ *(volatile uint8_t *)(dword_13CA9C + HIBYTE(v44)) ^ *(volatile uint8_t *)(v4 + (uint8_t)v41) ^ v51;
    v16 = ((*(volatile uint8_t *)(dword_13CA9C + BYTE2(v45))
          ^ v51
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v41)
          ^ *(volatile uint8_t *)(v4 + HIBYTE(v44))) << 16)
        | ((*(volatile uint8_t *)(v3 + HIBYTE(v44))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v41)
          ^ *(volatile uint8_t *)(dword_13CA9C + BYTE1(v46))
          ^ *(volatile uint8_t *)(v4 + BYTE2(v45))) << 8)
        | v12
        ^ *(volatile uint8_t *)(v3 + HIBYTE(v44))
        ^ *(volatile uint8_t *)(dword_13CA9C + (uint8_t)v41)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v46));
    v17 = (uint8_t)v46;
    v18 = HIBYTE(v46);
    v47 = v14 | (v13 << 24);
    *a2 = v47;
    v19 = *(volatile uint8_t *)(v3 + BYTE1(v45));
    a2[1] = v16 | (v15 << 24);
    v20 = *(volatile uint8_t *)(v3 + HIBYTE(v41));
    v21 = *(volatile uint8_t *)(v3 + v17);
    v52 = *(volatile uint8_t *)(dword_13CA9C + HIBYTE(v41));
    v22 = BYTE2(v41);
    v23 = *(volatile uint8_t *)(v3 + (uint8_t)v45);
    v24 = *(volatile uint8_t *)(v4 + HIBYTE(v41)) ^ v21 ^ v19 ^ *(volatile uint8_t *)(dword_13CA9C + BYTE2(v44));
    v42 = *(volatile uint8_t *)(v3 + BYTE1(v44));
    v25 = (v24 << 16)
        | ((*(volatile uint8_t *)(dword_13CA9C + BYTE1(v45)) ^ v21 ^ v20 ^ *(volatile uint8_t *)(v4 + BYTE2(v44))) << 8)
        | v20
        ^ *(volatile uint8_t *)(dword_13CA9C + v17)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v45))
        ^ *(volatile uint8_t *)(v3 + BYTE2(v44))
        | ((v19 ^ *(volatile uint8_t *)(v3 + BYTE2(v44)) ^ *(volatile uint8_t *)(v4 + v17) ^ v52) << 24);
    v26 = ((*(volatile uint8_t *)(v4 + v18) ^ v23 ^ v42 ^ *(volatile uint8_t *)(dword_13CA9C + v22)) << 16)
        | ((*(volatile uint8_t *)(dword_13CA9C + BYTE1(v44))
          ^ *(volatile uint8_t *)(v3 + v18)
          ^ v23
          ^ *(volatile uint8_t *)(v4 + v22)) << 8)
        | *(volatile uint8_t *)(v3 + v22)
        ^ *(volatile uint8_t *)(v3 + v18)
        ^ *(volatile uint8_t *)(dword_13CA9C + (uint8_t)v45)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v44))
        | ((v42
          ^ *(volatile uint8_t *)(v3 + v22)
          ^ *(volatile uint8_t *)(v4 + (uint8_t)v45)
          ^ *(volatile uint8_t *)(dword_13CA9C + v18)) << 24);
    a2[2] = v25;
    a2[3] = v26;
    v27 = v47 ^ v50[4];
    *a2 = v27;
    v44 = v27;
    v28 = v50[5] ^ (v16 | (v15 << 24));
    a2[1] = v28;
    v41 = v28;
    v29 = v25 ^ v50[6];
    a2[2] = v29;
    v46 = v29;
    v45 = v50[7] ^ v26;
    a2[3] = v45;
    v50 += 4;
  }
  while ( v53 != v50 );
  v43 = *(volatile uint8_t *)(v3 + (uint8_t)v28) | (*(volatile uint8_t *)(v3 + HIBYTE(v27)) << 24);
  v30 = *(volatile uint8_t *)(v3 + (uint8_t)v29) | (*(volatile uint8_t *)(v3 + HIBYTE(v28)) << 24);
  v31 = *(volatile uint8_t *)(v3 + (uint8_t)v27)
      | (*(volatile uint8_t *)(v3 + HIBYTE(v45)) << 24)
      | (*(volatile uint8_t *)(v3 + BYTE1(v28)) << 8);
  v32 = *(volatile uint8_t *)(v3 + BYTE1(v45));
  v33 = *(volatile uint8_t *)(v3 + BYTE2(v27));
  v34 = *(volatile uint8_t *)(v3 + BYTE2(v28));
  v35 = *(volatile uint8_t *)(v3 + (uint8_t)v45)
      | (*(volatile uint8_t *)(v3 + HIBYTE(v46)) << 24)
      | (*(volatile uint8_t *)(v3 + BYTE1(v27)) << 8);
  v36 = v31 | (*(volatile uint8_t *)(v3 + BYTE2(v46)) << 16);
  v37 = v43 | (*(volatile uint8_t *)(v3 + BYTE1(v46)) << 8) | (*(volatile uint8_t *)(v3 + BYTE2(v45)) << 16);
  v38 = v30 | (v32 << 8) | (v33 << 16);
  v39 = v35 | (v34 << 16);
  *a2 = v36;
  a2[1] = v37;
  a2[2] = v38;
  a2[3] = v39;
  *a2 = v36 ^ a1[40];
  a2[1] = v37 ^ a1[41];
  result = v38 ^ a1[42];
  a2[2] = result;
  a2[3] = v39 ^ a1[43];
  return result;
}



// rx_parse_pkt_header @ 0x13cb7c
volatile unsigned int * rx_parse_pkt_header(volatile unsigned int *result) {
  uint64_t v1; // r2
  int v2; // r1
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r1

  v1 = *(volatile uint64_t *)(result + 1);
  v2 = dword_13CBE8;
  v3 = *result;
  v4 = result[3];
  *result = dword_13CBE8 & (*result >> 15) | ((uint32_t)v1 << 17) & 0x1000000 | (2 * *result) & 0xFEFEFEFE;
  v1 = (v1 & ~0xFFFFFFFFull) | ((uint32_t)((2 * v1) & 0xFEFEFEFE | v2 & ((unsigned int)v1 >> 15) | (HIDWORD(v1) << 17) & 0x1000000) & 0xFFFFFFFFu);
  v1 = (v1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((2 * HIDWORD(v1)) & 0xFEFEFEFE | v2 & (HIDWORD(v1) >> 15) | (v4 << 17) & 0x1000000) << 32);
  v5 = v2 & (v4 >> 15) | (2 * v4) & 0xFEFEFEFE;
  *(volatile uint64_t *)(result + 1) = v1;
  if ( (v3 & 0x80) != 0 )
    v5 ^= 0x87000000;
  result[3] = v5;
  return result;
}



