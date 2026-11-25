// rx_process_buffer @ 0x13b438
int rx_process_buffer(int a1, volatile char *a2, unsigned int a3) {
  volatile char *v6; // r8
  char v7; // r10
  volatile unsigned int v8; // r3
  char v9; // r5
  char v10; // r6
  volatile char *v11; // r0
  uint16_t v12; // r3
  volatile char *v13; // r5
  volatile unsigned int v14; // r3

  if ( hci_cmd_send_short(a3) == 3 )
  {
    v6 = (volatile char *)off_13B5DC + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          rf_get_chan_cfg(a3 >> 8);
          check_abort_flag(dword_13B5F8, (void *)(v6));
          hci_cmd_send(a3, 0);
        }
        else
        {
          v7 = v6[20];
          tx_init_data_buffer((int)off_13B5DC + 32 * (a3 >> 8));
          v8 = (*(volatile uint32_t *)0x40501010u);
          *((volatile uint32_t *)v6 + 2) = v8;
          v9 = *a2;
          v10 = a2[1];
          v11 = (volatile char *)bt_buf_alloc(5131, 13, 5, 3);
          v11[2] = v7 - 4;
          *v11 = v9;
          v11[1] = v10;
          hci_evt_send((int)v11);
          sdio_wr_reg(a3 >> 8);
          hci_cmd_send(a3, 1);
        }
      }
      else if ( **(volatile int16_t **)off_13B5D8 < 0 )
      {
        mmio_field_update(off_13B5E8, (int)aMmBaAddCfmHand, 218);
      }
    }
    else
    {
      v12 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_13B5EC)[92]);
      if ( HIBYTE(((volatile uint32_t *)(uintptr_t)off_13B5EC)[92]) )
        v12 = *(volatile uint8_t *)(dword_13B5F4
                                 + 1320
                                 * *(volatile uint8_t *)(dword_13B5F0 + 696 * *((volatile uint8_t *)off_13B5DC + 16) + 34)
                                 + 106) == 0;
      v13 = (volatile char *)off_13B5DC + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        dbg_printf(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((volatile uint16_t *)v13 + 10) << 6),
          0x25u,
          0);
        check_abort_flag(dword_13B5FC, (void *)(v13));
        hci_cmd_send(a3, 0);
      }
      else
      {
        dbg_printf(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((volatile uint16_t *)v13 + 10) << 6),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        *(volatile uint8_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B5F0 + 452) = BYTE1(a3);
        v14 = (*(volatile uint32_t *)0x40501010u);
        *((volatile uint32_t *)v13 + 2) = v14;
        sdio_wr_reg(a3 >> 8);
        hci_cmd_send(a3, 1);
      }
    }
    return 0;
  }
  if ( **(volatile int16_t **)off_13B5D8 >= 0 )
    return 0;
  mmio_field_update(off_13B5E8, (int)aMmBaAddCfmHand, 109);
  return 0;
}


// mac_build_control_frame @ 0x13b600
int mac_build_control_frame(int a1, volatile char *a2, unsigned int a3) {
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
  if ( hci_cmd_send_short(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B690 + 32 * v5;
    if ( *(volatile uint8_t *)(v6 + 17) == 1 )
    {
      v7 = scan_parse_adv_data(*(volatile uint32_t *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(volatile uint8_t *)(v6 + 20) + v7;
      v11 = (volatile uint8_t *)bt_buf_alloc(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      hci_evt_send((int)v11);
    }
    *(volatile uint32_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B694 + 448) = *((volatile uint32_t *)off_13B698
                                                                                                 + 4);
    sdio_rd_reg(v5);
  }
  return 0;
}



// rx_measure_rssi @ 0x13b69c
int rx_measure_rssi(int a1, int a2, unsigned int a3) {
  int v4; // r0

  if ( hci_cmd_send_short(a3) == 1 )
  {
    if ( a3 < 0x1000 )
      v4 = dword_13B6D0;
    else
      v4 = dword_13B6CC;
    check_abort_flag(v4, (volatile uint32_t *)(dword_13B6C8 + 32 * (a3 >> 8)));
  }
  return 0;
}


// rf_is_ready @ 0x13b6d4
int rf_is_ready(int a1, int a2, unsigned int a3) {
  if ( hci_cmd_send_short(a3) == 2 )
  {
    rf_get_chan_cfg(a3 >> 8);
    check_abort_flag(dword_13B70C, (volatile uint32_t *)(dword_13B708 + 32 * (a3 >> 8)));
    hci_cmd_send(a3, 0);
  }
  return 0;
}


// mac_filter_check @ 0x13b724
int mac_filter_check(int a1, int a2) {
  return *(volatile uint8_t *)(a1 + 264) & (a2 + *(volatile uint8_t *)(a1 + 262));
}



// dbg_printf @ 0x13b734
int dbg_printf(int a1, int a2, int a3, char a4, int16_t a5, int16_t a6, int a7) {
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

  v7 = dword_13B990;
  v8 = dword_13B974;
  v9 = *(volatile uint8_t *)(dword_13B990 + 696 * a1 + 34);
  v10 = (volatile int16_t **)off_13B994;
  v13 = *(volatile uint32_t *)(dword_13B974 + 1320 * v9 + 72);
  if ( !v13 )
  {
    if ( **(volatile int16_t **)off_13B994 >= 0 )
    {
LABEL_19:
      result = (int)(uintptr_t)(event_notify(1, 512));
      v16 = result;
      if ( !result )
        return result;
      goto LABEL_4;
    }
LABEL_18:
    mmio_irq_clear(dword_13B980, dword_13B97C, 520);
    goto LABEL_19;
  }
  v14 = *(volatile uint8_t *)(v13 + 4);
  if ( **(volatile int16_t **)off_13B994 < 0 && v14 == 2 )
    goto LABEL_18;
  result = (int)(uintptr_t)(event_notify((*(volatile uint8_t *)(dword_13B974 + 1320 * v9 + 1224) | v14) != 0, 512));
  v16 = result;
  if ( !result )
    return result;
LABEL_4:
  scan_done_check(v8 + 1320 * v9, v16);
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
  v22 = *((volatile uint16_t *)off_13B978 + 254) + 1;
  *((volatile uint16_t *)off_13B978 + 254) = v22;
  *(volatile uint16_t *)(v17 + 130) = 16 * v22;
  *(volatile uint8_t *)(v16 + 51) = 0;
  *(volatile uint8_t *)(v16 + 53) = 0;
  *(volatile uint8_t *)(v16 + 28) = v9;
  *(volatile uint8_t *)(v16 + 29) = a1;
  if ( bt_get_conn_ctx(v16, 208, 3) == 1 )
  {
    mac_rx_process_ack(v16, v28, 24);
    v23 = *(volatile uint8_t *)(v16 + 51) + 24;
  }
  else
  {
    v23 = 24;
  }
  if ( a3 == 1 )
  {
    v24 = 3;
    v23 += rf_build_cal_block_v3_extra((int)v28 + v23, a2, a5, a4, a6);
  }
  else if ( a3 == 2 )
  {
    v24 = *(volatile uint8_t *)(dword_13B984 + *(volatile uint8_t *)(a2 + 22));
    v23 += rf_build_cal_block_v2((int)v28 + v23, a2, a6);
  }
  else if ( a3 )
  {
    if ( **v10 < 0 )
      mmio_field_update(dword_13B98C, dword_13B988, 269);
    v24 = 3;
  }
  else
  {
    v24 = *(volatile uint8_t *)(dword_13B984 + *(volatile uint8_t *)(a2 + 22));
    v23 += rf_build_cal_block_v3((int)v28 + v23, a2);
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
  return ble_event_dispatch(v16, v24);
}



// timer_elapsed @ 0x13b998
unsigned int timer_elapsed(int a1) {
  return ((unsigned int)(a1 - (*((volatile uint32_t *)off_13B9A8 + 4) >> 10)) >> 15) & 1;
}



// rf_scan_entry @ 0x13b9ac
int rf_scan_entry(int a1) {
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



// rx_invoke_cb @ 0x13b9f0
int rx_invoke_cb(int a1, int16_t a2, char a3) {
  int result; // r0

  result = (*(int ( **)(int, int))a1)(a1, (a2 - *(volatile uint16_t *)(a1 + 4)) & 0xFFF) + a1;
  *(volatile uint8_t *)(result + 6) = a3;
  return result;
}



// rf_init_queues @ 0x13ba08
int rf_init_queues() {
  volatile uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  int result; // r0

  v0 = (volatile uint32_t *)dword_13BA9C;
  zero_struct((volatile uint32_t *)dword_13BA9C);
  zero_struct(v0 + 2);
  zero_struct(v0 + 4);
  zero_struct(v0 + 6);
  zero_struct(v0 + 8);
  zero_struct(v0 + 10);
  v1 = dword_13BAA0;
  v2 = dword_13BAA4;
  for ( i = 0; ; ++i )
  {
    *(volatile uint8_t *)(v1 + 16) = -1;
    *(volatile uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    check_abort_flag((int)v0, (volatile uint32_t *)v1);
    hci_cmd_send((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(volatile uint32_t *)(v1 + 28) = v2 + 268 * i;
  check_abort_flag((int)(v0 + 6), (volatile uint32_t *)v1);
  result = hci_cmd_send((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}


// sdio_wr_reg @ 0x13baa8
int sdio_wr_reg(int16_t a1) {
  return patch_aware_dispatch(8194, (uint16_t)(a1 << 8) | 8, 0x1F4000u);
}



// rf_get_chan_cfg @ 0x13bac0
volatile uint8_t * rf_get_chan_cfg(int a1) {
  volatile uint8_t *result; // r0
  int v2; // r1
  int v3; // r3

  result = (volatile uint8_t *)(dword_13BB0C + 32 * a1);
  v2 = result[16];
  v3 = result[22];
  if ( result[17] )
  {
    if ( result[17] == 1 )
      *(volatile uint8_t *)(696 * v2 + 12 * v3 + dword_13BB10 + 453) = 33;
  }
  else
  {
    *(volatile uint8_t *)(696 * v2 + 12 * v3 + dword_13BB10 + 452) = 33;
  }
  return result;
}



// rx_queue_flush @ 0x13bb14
int rx_queue_flush(volatile int **a1) {
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
    v6 = *((volatile uint32_t *)off_13BB5C + 4) - (uint32_t)v5;
    if ( v6 > v3 )
      result = *((volatile uint8_t *)v4 + 26);
    v4 = (volatile int **)*v4;
    if ( v6 > v3 )
      v3 = *((volatile uint32_t *)off_13BB5C + 4) - (uint32_t)v5;
  }
  while ( v4 );
  v7 = dword_13BB60 + 32 * result;
  if ( v3 <= *(volatile uint16_t *)(v7 + 14) << 10 || *(volatile uint32_t *)(v7 + 4) )
    return *((volatile uint8_t *)v1 + 26);
  else
    return (uint16_t)result;
}



// rf_set_mode @ 0x13bb64
int rf_set_mode(int a1, volatile uint16_t *a2, int a3) {
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
          return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BCB4 + 452);
        else
          return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v13 + dword_13BCB4 + 453);
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
        if ( phy_read_channel((uint8_t)a1, (v7 >> 2) & 0xF) )
          return *(volatile uint8_t *)(696 * v9 + 12 * v8 + dword_13BCB4 + 452);
        if ( *((volatile uint32_t *)off_13BCB8 + 4) - 500000 - *(volatile uint32_t *)(696 * v9 + 12 * v8 + dword_13BCB4 + 448) >= 0 )
        {
          if ( *(volatile uint8_t *)(dword_13BCB4 + 696 * a1 + 36) == 1 )
            goto LABEL_22;
          if ( *(volatile uint32_t *)off_13BCBC )
          {
            v4 = *((volatile uint8_t *)list_pop_front((int)off_13BCBC) + 26);
            if ( v4 != 33 )
              return v4;
          }
          v11 = rx_queue_flush((volatile int **)dword_13BCC0);
          if ( v11 == 33 )
          {
LABEL_22:
            dbg_printf(v9, 0, 1, v10, v7, 37, 0);
            return 33;
          }
          else
          {
            v4 = v11;
            hci_evt_alloc_send(8193, ((uint16_t)v11 << 8) | 8, 255);
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
  return *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * v6 + dword_13BCB4 + 453);
}



// sdio_rd_reg @ 0x13bcc4
int sdio_rd_reg(unsigned int a1) {
  unsigned int v1; // r5
  int v3; // r1
  volatile uint8_t *v4; // r3
  int v5; // r2
  int v6; // r0
  int v7; // r3
  volatile uint32_t *v8; // r1
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  v1 = (a1 << 8) | 8;
  irq_lock((volatile char *)0x2000, v1);
  irq_lock((volatile char *)0x2002, v1);
  v3 = dword_13BD6C;
  v4 = (volatile uint8_t *)(dword_13BD6C + 32 * a1);
  v5 = v4[17];
  v6 = v4[16];
  v7 = v4[22];
  if ( v5 )
  {
    if ( v5 == 1 )
      *(volatile uint8_t *)(696 * v6 + 12 * v7 + dword_13BD70 + 453) = 33;
    v8 = (volatile uint32_t *)(v3 + 32 * a1);
    a2 = v8;
    if ( a1 <= 0xF )
      goto LABEL_5;
LABEL_7:
    check_abort_flag_3(dword_13BD7C, v8);
    check_abort_flag(dword_13BD80, a2);
    return hci_cmd_send(v1, 0);
  }
  v8 = (volatile uint32_t *)(dword_13BD6C + 32 * a1);
  *(volatile uint8_t *)(696 * v6 + 12 * v7 + dword_13BD70 + 452) = 33;
  a2 = v8;
  if ( a1 > 0xF )
    goto LABEL_7;
LABEL_5:
  check_abort_flag_3(dword_13BD74, v8);
  check_abort_flag(dword_13BD78, a2);
  return hci_cmd_send(v1, 0);
}


// rf_scan_start @ 0x13bd84
int rf_scan_start(int result) {
  int v1; // r4
  int v2; // r5
  void *a7; // r10
  int v4; // r7
  int16_t v5; // r9
  int v6; // r6
  int v7; // t1

  v1 = dword_13BDF0;
  v2 = dword_13BDF4;
  a7 = (void *)(uintptr_t)(off_13BDF8);
  v4 = result;
  v5 = -128 * dword_13BDF0;
  v6 = dword_13BDF0 + 64;
  do
  {
    v7 = *(volatile uint16_t *)(v1 + 2);
    v1 += 2;
    if ( v7 )
    {
      if ( *(volatile uint8_t *)(v2 + 16) == v4 )
      {
        hci_cmd_send((uint16_t)(v5 + ((uint16_t)v1 << 7) - 256) | 8, 4);
        *(volatile uint8_t *)(v2 + 25) = 0;
        result = dbg_printf(v4, v2, 2, 0, 0, 0x27u, (int)a7);
      }
    }
    v2 += 32;
  }
  while ( v1 != v6 );
  return result;
}


// sdio_cmd52_wr @ 0x13bdfc
int sdio_cmd52_wr(char a1, int a2) {
  int v2; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v2 = a2;
  v4 = bt_buf_alloc(40, 0, ((uint16_t)a2 << 8) | 8, 8u);
  v5 = dword_13BE3C + 32 * v2;
  v6 = *(volatile uint8_t *)(v5 + 17);
  *(volatile uint8_t *)(v4 + 1) = a1;
  *(volatile uint8_t *)v4 = v6 != 1;
  *(volatile uint8_t *)(v4 + 2) = *(volatile uint8_t *)(v5 + 22);
  v2 = (v2 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 20)) & 0xFFFFu);
  *(volatile uint16_t *)(v4 + 6) = *(volatile uint16_t *)(v5 + 12);
  *(volatile uint16_t *)(v4 + 4) = v2;
  return (int)(uintptr_t)(hci_evt_send(v4));
}



// sdio_cmd53_rd @ 0x13be40
int sdio_cmd53_rd(int a1, int a2) {
  unsigned int v2; // r5
  volatile int *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (uint16_t)((uint16_t)a2 << 8) | 8;
  v5 = (volatile int *)bt_buf_alloc(42, 0, ((uint16_t)a2 << 8) | 8, 3u);
  if ( **(volatile int16_t **)off_13BEA0 < 0 && hci_cmd_send_short(v2) != 4 )
    mmio_irq_clear(dword_13BEAC, dword_13BEA8, 891);
  v6 = dword_13BEA4 + 32 * a2;
  v7 = *(volatile uint8_t *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(volatile uint8_t *)(v6 + 22);
  return (int)(uintptr_t)(hci_evt_send((int)v5));
}



// rf_calibrate_1 @ 0x13beb0
int rf_calibrate_1(int result) {
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BF34;
  v2 = dword_13BF28;
  v3 = dword_13BF2C;
  v4 = result;
  v5 = dword_13BF34 - 8;
  v6 = dword_13BF34 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(volatile uint16_t *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(volatile uint8_t *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        check_abort_flag_3(v6, (volatile uint32_t *)v3);
        check_abort_flag(dword_13BF30, (volatile uint32_t *)v3);
      }
      else
      {
        check_abort_flag_3(v1, (volatile uint32_t *)v3);
        check_abort_flag(v5, (volatile uint32_t *)v3);
      }
      hci_cmd_send((uint16_t)((uint16_t)i << 8) | 8, 4);
      result = sdio_cmd53_rd(v4, (uint16_t)i);
    }
    v3 += 32;
  }
  return result;
}


// rf_get_chan_info @ 0x13bf94
int rf_get_chan_info(unsigned int a1) {
  int v1; // r5
  int v2; // r6
  int v3; // r7
  unsigned int v5; // r8
  unsigned int v6; // r0
  void *v7; // r4

  v1 = dword_13BFFC;
  v2 = dword_13BFFC + 32 * a1;
  v3 = *(volatile uint8_t *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    check_abort_flag_3(dword_13C00C, (volatile uint32_t *)v2);
    check_abort_flag(dword_13C010, (volatile uint32_t *)v2);
  }
  else
  {
    check_abort_flag_3(dword_13C000, (volatile uint32_t *)v2);
    check_abort_flag(dword_13C004, (volatile uint32_t *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = (void *)(uintptr_t)(off_13C008);
  hci_cmd_send(v6 | 8, 4);
  *(volatile uint8_t *)(v1 + v5 + 25) = 0;
  return dbg_printf(v3, v2, 2, 0, 0, 0x27u, (int)v7);
}


// phy_is_ready @ 0x13c014
int phy_is_ready() {
  volatile uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = (void *)(uintptr_t)(off_13C048);
  if ( !*((volatile uint32_t *)off_13C048 + 6)
    || (result = *((volatile uint8_t *)list_pop_front((int)off_13C048 + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (uint8_t)rx_queue_flush((volatile int **)dword_13C04C);
    if ( (uint8_t)v2 == 33 )
    {
      return 33;
    }
    else
    {
      rf_get_chan_info(v2);
      return 33;
    }
  }
  return result;
}



// rf_apply_cfg @ 0x13c050
int rf_apply_cfg(int a1, int a2, uint16_t a3) {
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

  v6 = phy_is_ready(a1, a2);
  v7 = v6;
  if ( (uint8_t)v6 == 33 )
    return 3;
  v8 = dword_13C130 + 32 * (uint8_t)v6;
  v9 = v6;
  *(volatile uint8_t *)(v8 + 22) = a2;
  *(volatile uint8_t *)(v8 + 16) = a1;
  v10 = random();
  v12 = dword_13C134;
  *(volatile uint8_t *)(v8 + 23) = v10;
  v13 = (*(volatile uint32_t *)(v12 + 696 * a1 + 4) & 0x20) == 0;
  v14 = *(volatile uint16_t *)(*(volatile uint32_t *)off_13C138 + 2);
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
  dbg_printf(a1, v8, 2, 0, 0, 0x27u, 0);
  v17 = (v9 << 8) | 8;
  dbg_printf(a1, v8, 0, 0, 0, 0, 0);
  v18 = (*(volatile uint32_t *)0x40501010u);
  *(volatile uint32_t *)(v15 + 444) = v18;
  patch_aware_dispatch(0x2000, v17, 0x7D000u);
  hci_cmd_send(v17, 2);
  return 0;
}


// phy_set_chan @ 0x13c140
int phy_set_chan(int a1, int a2) {
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13C1AC;
  v5 = *(volatile uint8_t *)(696 * (uint8_t)a1 + 12 * (uint8_t)a2 + dword_13C1AC + 453);
  return v5 == 33
      || hci_cmd_send_short((v5 << 8) | 8) != 1
      || *(volatile uint16_t *)(dword_13C1B0 + 32 * v5 + 20) > ((*(volatile uint16_t *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(volatile uint16_t *)(*(volatile uint32_t *)(dword_13C1B0 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}



// rf_modem_status_check @ 0x13c1b4
unsigned int rf_modem_status_check(unsigned int result) {
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
  v2 = *((volatile uint32_t *)off_13C30C + 4);
  if ( v1 != 255 )
  {
    v3 = *(volatile uint8_t *)(result + 29);
    v4 = dword_13C310;
    v5 = dword_13C310 + 696 * v3;
    v6 = result;
    result = *(volatile uint32_t *)(v5 + 4) << 30;
    if ( (*(volatile uint32_t *)(v5 + 4) & 2) != 0 )
    {
      v7 = 696 * v3 + 12 * v1 + dword_13C310;
      v8 = *(volatile uint8_t *)(v7 + 453);
      ++*(volatile uint8_t *)(v7 + 455);
      if ( v8 == 33 )
      {
        result = v2 + 1000000 - *(volatile uint32_t *)(v7 + 444);
        if ( result > dword_13C328 && v2 - 500000 - *(volatile uint32_t *)(v7 + 448) >= 0 && *(volatile uint8_t *)(v5 + 36) != 1 )
        {
          result = dword_13C318;
          v9 = *(volatile uint8_t *)(dword_13C314 + v1);
          if ( !*(volatile uint32_t *)(dword_13C318 + 84 * v9)
            && !*(volatile uint32_t *)(dword_13C320 + 8 * v9)
            && !*(volatile uint32_t *)(v4 + 8 * (v9 + 87 * v3 + 78)) )
          {
            result = dword_13C324;
            if ( !*(volatile uint32_t *)(dword_13C324 + 8 * (165 * *(volatile uint8_t *)(v6 + 28) + v9 + 159)) )
              return rf_apply_cfg(v3, v1, *(volatile uint16_t *)(v6 + 32));
          }
        }
      }
      else
      {
        v10 = dword_13C32C;
        v11 = dword_13C32C + 32 * v8;
        *(volatile uint32_t *)(v11 + 8) = v2;
        result = hci_cmd_send_short((v8 << 8) | 8);
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
              *(volatile uint16_t *)(v6 + 64) = *((volatile uint16_t *)off_13C31C + 22) + (*((volatile uint32_t *)off_13C30C + 4) >> 10);
            ++*(volatile uint32_t *)(v12 + v10 + 4);
          }
        }
      }
    }
  }
  return result;
}



// bt_get_ctx_by_phy @ 0x13c330
int bt_get_ctx_by_phy(int a1, int a2, int a3) {
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
  if ( (*(volatile uint32_t *)(dword_13C438 + v4 + 4) & 2) == 0 )
    return 1;
  v5 = v4 + 12 * *(volatile uint8_t *)(a1 + 27) + dword_13C438;
  --*(volatile uint8_t *)(v5 + 455);
  if ( (*(volatile uint16_t *)(a1 + 30) & 2) == 0 )
    return 1;
  v8 = *(volatile uint8_t *)(v5 + 453);
  if ( v8 == 33 || hci_cmd_send_short((v8 << 8) | 8) != 1 )
    return 1;
  v11 = dword_13C43C + 32 * v8;
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
          ke_event_schedule_1("move win since flush: succ=%d, timepast=%d\n", 0, ((v14 - (v16 >> 10)) >> 15) & 1);
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


// tx_init_data_buffer @ 0x13c448
int tx_init_data_buffer(int a1) {
  int v1; // r5
  int result; // r0
  int16_t v4; // r2
  int v5; // r3
  int v6; // zf

  v1 = *(volatile uint32_t *)(a1 + 28);
  memset((volatile int *)(v1 + 6), 0, 0x100u);
  result = 348;
  v4 = *(volatile uint16_t *)(dword_13C490 + 2 * (*(volatile uint8_t *)(a1 + 22) + 348 * *(volatile uint8_t *)(a1 + 16)) + 316);
  *(volatile uint8_t *)(v1 + 262) = 0;
  v5 = *(volatile uint8_t *)(a1 + 20);
  *(volatile uint16_t *)(v1 + 4) = v4;
  v6 = ((v5 - 1) & v5) == 0;
  *(volatile uint8_t *)(v1 + 263) = v5;
  if ( ((v5 - 1) & v5) != 0 )
    v5 = dword_13C494;
  else
    *(volatile uint8_t *)(v1 + 264) = v5 - 1;
  if ( v6 )
    v5 = dword_13C498;
  *(volatile uint32_t *)v1 = v5;
  return result;
}



// scan_parse_adv_data @ 0x13c49c
int scan_parse_adv_data(int a1) {
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



// rf_get_channel_param @ 0x13c4c0
int rf_get_channel_param(int a1, int a2) {
  int result; // r0
  unsigned int v3; // r4

  result = 696 * a1 + 12 * a2 + dword_13C50C;
  v3 = *(volatile uint8_t *)(result + 452);
  if ( **(volatile int16_t **)off_13C508 < 0 && v3 > 0x20 )
    result = mmio_irq_clear(dword_13C51C, dword_13C518, 1152);
  *(volatile uint32_t *)(dword_13C510 + 32 * v3 + 8) = *((volatile uint32_t *)off_13C514 + 4);
  return result;
}



// is_rate_valid @ 0x13c520
BOOL is_rate_valid(char a1, unsigned int a2) {
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


// tx_prepare_ll_packet @ 0x13c5b4
unsigned int tx_prepare_ll_packet(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
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
  if ( !is_rate_valid(v5, v6) )
    return 0;
  v11 = a1[9];
  if ( v11 == 255 )
    goto LABEL_9;
  v12 = a1[10];
  if ( v12 == 255 )
    goto LABEL_9;
  v13 = v10;
  if ( !*(volatile uint32_t *)(dword_13C72C + 1320 * v12 + 1200) )
    return 0;
  if ( (a1[48] & 8) == 0 )
  {
    if ( (*(volatile uint32_t *)(dword_13C730 + 696 * v11 + 4) & 8) != 0 && (v5 & 0x4000) == 0 )
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
    if ( *(volatile uint32_t *)(dword_13C72C + 1320 * v12 + 1204) )
    {
      if ( v4 + 19 >= v10 )
        goto LABEL_9;
      v15 = memmove_1_1((volatile uint8_t *)(v4 + a2 + 2), (uint16_t)(v10 - 2 - v4));
      if ( !v15 )
        goto LABEL_9;
      v16 = *((volatile uint16_t *)v15 + 1);
      if ( (unsigned int)(v16 - 4) > 1 )
        goto LABEL_9;
      v17 = 1320 * v12 + 120 * v16 + dword_13C72C;
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
      v24 = ke_process_event(1320 * v12 + 480 + 120 * v16 + dword_13C72C, (void *)(uintptr_t)(a2), v13 - 18, v4, 0);
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



// bt_get_conn_ctx @ 0x13c734
int bt_get_conn_ctx(int a1, int a2, int a3) {
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
  v5 = dword_13C7A4;
  result = *(volatile uint32_t *)(dword_13C7A4 + 1320 * v4 + 1200);
  if ( result )
  {
    v7 = a2;
    result = is_rate_valid(a2, a3);
    if ( result )
    {
      v9 = 696 * v3;
      result = *(volatile uint8_t *)(v9 + dword_13C7A8) & 1;
      if ( (*(volatile uint8_t *)(v9 + dword_13C7A8) & 1) != 0 )
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
        return (*(volatile uint32_t *)(v9 + dword_13C7A8 - 34) >> 3) & 1;
      }
    }
  }
  return result;
}



// bt_check_conn_active @ 0x13c7ac
int bt_check_conn_active(int a1, int a2, int a3, int a4) {
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

  result = *(volatile uint32_t *)(dword_13C86C + 1320 * *(volatile uint8_t *)(a1 + 28) + 1204);
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
    v14 = ke_process_event(result, (void *)(uintptr_t)(a2), a3, 24, a4);
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



// mac_compute_transform @ 0x13c870
int mac_compute_transform(volatile uint32_t *a1, volatile uint32_t *a2) {
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
  v3 = dword_13CB34;
  v4 = dword_13CB3C;
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
    v13 = v11 ^ *(volatile uint8_t *)(v4 + (uint8_t)v44) ^ *(volatile uint8_t *)(dword_13CB38 + HIBYTE(v45)) ^ v49;
    v14 = ((*(volatile uint8_t *)(v4 + HIBYTE(v45))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v44)
          ^ v49
          ^ *(volatile uint8_t *)(dword_13CB38 + BYTE2(v46))) << 16)
        | ((*(volatile uint8_t *)(dword_13CB38 + BYTE1(v41))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v44)
          ^ *(volatile uint8_t *)(v3 + HIBYTE(v45))
          ^ *(volatile uint8_t *)(v4 + BYTE2(v46))) << 8)
        | v11
        ^ *(volatile uint8_t *)(v3 + HIBYTE(v45))
        ^ *(volatile uint8_t *)(dword_13CB38 + (uint8_t)v44)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v41));
    v15 = v12 ^ *(volatile uint8_t *)(dword_13CB38 + HIBYTE(v44)) ^ *(volatile uint8_t *)(v4 + (uint8_t)v41) ^ v51;
    v16 = ((*(volatile uint8_t *)(dword_13CB38 + BYTE2(v45))
          ^ v51
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v41)
          ^ *(volatile uint8_t *)(v4 + HIBYTE(v44))) << 16)
        | ((*(volatile uint8_t *)(v3 + HIBYTE(v44))
          ^ *(volatile uint8_t *)(v3 + (uint8_t)v41)
          ^ *(volatile uint8_t *)(dword_13CB38 + BYTE1(v46))
          ^ *(volatile uint8_t *)(v4 + BYTE2(v45))) << 8)
        | v12
        ^ *(volatile uint8_t *)(v3 + HIBYTE(v44))
        ^ *(volatile uint8_t *)(dword_13CB38 + (uint8_t)v41)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v46));
    v17 = (uint8_t)v46;
    v18 = HIBYTE(v46);
    v47 = v14 | (v13 << 24);
    *a2 = v47;
    v19 = *(volatile uint8_t *)(v3 + BYTE1(v45));
    a2[1] = v16 | (v15 << 24);
    v20 = *(volatile uint8_t *)(v3 + HIBYTE(v41));
    v21 = *(volatile uint8_t *)(v3 + v17);
    v52 = *(volatile uint8_t *)(dword_13CB38 + HIBYTE(v41));
    v22 = BYTE2(v41);
    v23 = *(volatile uint8_t *)(v3 + (uint8_t)v45);
    v24 = *(volatile uint8_t *)(v4 + HIBYTE(v41)) ^ v21 ^ v19 ^ *(volatile uint8_t *)(dword_13CB38 + BYTE2(v44));
    v42 = *(volatile uint8_t *)(v3 + BYTE1(v44));
    v25 = (v24 << 16)
        | ((*(volatile uint8_t *)(dword_13CB38 + BYTE1(v45)) ^ v21 ^ v20 ^ *(volatile uint8_t *)(v4 + BYTE2(v44))) << 8)
        | v20
        ^ *(volatile uint8_t *)(dword_13CB38 + v17)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v45))
        ^ *(volatile uint8_t *)(v3 + BYTE2(v44))
        | ((v19 ^ *(volatile uint8_t *)(v3 + BYTE2(v44)) ^ *(volatile uint8_t *)(v4 + v17) ^ v52) << 24);
    v26 = ((*(volatile uint8_t *)(v4 + v18) ^ v23 ^ v42 ^ *(volatile uint8_t *)(dword_13CB38 + v22)) << 16)
        | ((*(volatile uint8_t *)(dword_13CB38 + BYTE1(v44))
          ^ *(volatile uint8_t *)(v3 + v18)
          ^ v23
          ^ *(volatile uint8_t *)(v4 + v22)) << 8)
        | *(volatile uint8_t *)(v3 + v22)
        ^ *(volatile uint8_t *)(v3 + v18)
        ^ *(volatile uint8_t *)(dword_13CB38 + (uint8_t)v45)
        ^ *(volatile uint8_t *)(v4 + BYTE1(v44))
        | ((v42
          ^ *(volatile uint8_t *)(v3 + v22)
          ^ *(volatile uint8_t *)(v4 + (uint8_t)v45)
          ^ *(volatile uint8_t *)(dword_13CB38 + v18)) << 24);
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



// rx_parse_packet_header @ 0x13cc18
volatile unsigned int * rx_parse_packet_header(volatile unsigned int *result) {
  uint64_t v1; // r2
  int v2; // r1
  unsigned int v3; // r5
  unsigned int v4; // r7
  unsigned int v5; // r1

  v1 = *(volatile uint64_t *)(result + 1);
  v2 = dword_13CC84;
  v3 = *result;
  v4 = result[3];
  *result = dword_13CC84 & (*result >> 15) | ((uint32_t)v1 << 17) & 0x1000000 | (2 * *result) & 0xFEFEFEFE;
  v1 = (v1 & ~0xFFFFFFFFull) | ((uint32_t)((2 * v1) & 0xFEFEFEFE | v2 & ((unsigned int)v1 >> 15) | (HIDWORD(v1) << 17) & 0x1000000) & 0xFFFFFFFFu);
  v1 = (v1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((2 * HIDWORD(v1)) & 0xFEFEFEFE | v2 & (HIDWORD(v1) >> 15) | (v4 << 17) & 0x1000000) << 32);
  v5 = v2 & (v4 >> 15) | (2 * v4) & 0xFEFEFEFE;
  *(volatile uint64_t *)(result + 1) = v1;
  if ( (v3 & 0x80) != 0 )
    v5 ^= 0x87000000;
  result[3] = v5;
  return result;
}



