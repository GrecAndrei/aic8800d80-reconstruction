// set_adv_type @ 0x124b04
int set_adv_type(int a1, int a2) {
  uint8_t v3; // r0
  unsigned int v4; // r4
  int v5; // r3
  volatile int *v6; // r1
  unsigned int v8; // r5
  struct __attribute__((packed)) { uint64_t result; // [sp+4h] [bp-18h] BYREF
  char v10; // [sp+Ch] [bp-10h] BYREF
  uint8_t a4[5]; // [sp+Dh] [bp-Fh]
  uint16_t v12; // [sp+12h] [bp-Ah]
  char _pad4[2]; char v13; // [sp+16h] [bp-6h]
  } _frame;
  v3 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( a1 <= 1 || (v4 = v3) == 0 )
  {
    dispatch_event_handler_1(asc_130184);
    return -1;
  }
  *(volatile uint32_t *)off_124C58 |= 0x500000u;
  mac_time_get(&_frame.result, 0);
  if ( v4 <= 0x23 )
  {
    v5 = BYTE1(_frame.result);
    _frame.v10 = 0;
    _frame.a4[0] = BYTE1(_frame.result);
    if ( v4 > 0xD )
    {
      if ( v4 != 14 )
      {
        dispatch_event_handler_1("Not supported chan: %d\n", v4);
        return -2;
      }
      *(volatile uint16_t *)&_frame.a4[3] = 2484;
      _frame.v12 = 0;
      _frame.v13 = 0;
      if ( !BYTE1(_frame.result) )
        goto LABEL_6;
LABEL_13:
      v8 = WORD1(_frame.result);
      if ( v5 == 1 )
      {
        if ( v8 < WORD2(_frame.result) )
          goto LABEL_21;
      }
      else
      {
        if ( v5 != 2 )
          goto LABEL_7;
        if ( (int)(v8 + 20) < WORD2(_frame.result) )
        {
          *(volatile uint16_t *)&_frame.a4[1] = *(volatile uint16_t *)&_frame.a4[3] - 30;
          goto LABEL_7;
        }
        if ( v8 < WORD2(_frame.result) )
        {
LABEL_21:
          *(volatile uint16_t *)&_frame.a4[1] = *(volatile uint16_t *)&_frame.a4[3] - 10;
          goto LABEL_7;
        }
        if ( WORD2(_frame.result) < (int)(v8 - 19) )
        {
          *(volatile uint16_t *)&_frame.a4[1] = *(volatile uint16_t *)&_frame.a4[3] + 30;
          goto LABEL_7;
        }
      }
      *(volatile uint16_t *)&_frame.a4[1] = *(volatile uint16_t *)&_frame.a4[3] + 10;
      goto LABEL_7;
    }
    *(volatile uint16_t *)&_frame.a4[3] = 5 * v4 + 2407;
  }
  else
  {
    v5 = BYTE1(_frame.result);
    *(volatile uint16_t *)&_frame.a4[3] = 5 * v4 + 5000;
    _frame.v10 = 1;
    _frame.a4[0] = BYTE1(_frame.result);
  }
  _frame.v12 = 0;
  _frame.v13 = 0;
  if ( v5 )
    goto LABEL_13;
LABEL_6:
  *(volatile uint16_t *)&_frame.a4[1] = *(volatile uint16_t *)&_frame.a4[3];
LABEL_7:
  *(volatile uint8_t *)off_124C5C = 1;
  rx_process_pending(0, (int)&_frame.v10);
  v6 = (volatile int *)off_124C60;
  *(volatile uint32_t *)off_124C58 &= 0xFF87FFFF;
  if ( *v6 )
    init_with_stack(*v6);
  dispatch_event_handler_1("\x9A\x88""Chan %d, Freq. %d, BW %d\n", v4, *(volatile uint16_t *)&_frame.a4[3], _frame.a4[0]);
  return 0;
}


// set_adv_data @ 0x124c70
int set_adv_data(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r4
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r0
  int v8; // r2
  volatile uint8_t *v9; // r4
  int v10; // r1
  int v11; // r0
  int v12; // r0
  struct __attribute__((packed)) { uint64_t result; // [sp+4h] [bp-14h] BYREF
  uint16_t a1a; // [sp+Ch] [bp-Ch] BYREF
  uint16_t a1_2; // [sp+Eh] [bp-Ah]
  int a3; // [sp+10h] [bp-8h]
  char _pad4[2]; char v17; // [sp+16h] [bp-2h]
  } _frame;
  mac_time_get(&_frame.result, 0);
  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1301C8);
    return -1;
  }
  v4 = parse_number((volatile uint8_t *)a2[1], nullptr, 0xAu);
  v5 = parse_number((volatile uint8_t *)a2[2], nullptr, 0xAu);
  v6 = parse_number((volatile uint8_t *)a2[3], nullptr, 0xAu);
  if ( a1 > 3 )
    v7 = parse_number((volatile uint8_t *)a2[4], nullptr, 0xAu);
  else
    v7 = 0;
  if ( v4 == 5 )
  {
    _frame.a1a = (uint8_t)_frame.result;
    _frame.v17 = 0;
    _frame.a3 = HIDWORD(_frame.result);
    _frame.a1_2 = WORD2(_frame.result);
    rx_process_pending(0, (int)&_frame.a1a);
    set_reg_180800_bits7_8(0);
    v8 = 2;
  }
  else
  {
    if ( v4 == 10 )
    {
      _frame.a1a = (uint8_t)_frame.result;
      _frame.v17 = 0;
      _frame.a3 = HIDWORD(_frame.result);
      _frame.a1_2 = WORD2(_frame.result);
      rx_process_pending(0, (int)&_frame.a1a);
      set_reg_180800_bits7_8(0);
    }
    else
    {
      if ( (*(volatile uint8_t *)off_124E18 & 8) == 0 && (v4 > 1 || v5 > 1) )
      {
        dispatch_event_handler_1("invalid bw:%d,%d\n", v4, v5);
        return -2;
      }
      _frame.a3 = HIDWORD(_frame.result);
      _frame.a1a = (_frame.a1a & ~0xFF00u) | (((uint8_t)(v4) & 0xFFu) << 8);
      _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(_frame.result) & 0xFFu);
      _frame.v17 = 0;
      if ( v4 )
      {
        if ( v4 == 1 )
        {
          if ( v6 )
            goto LABEL_25;
        }
        else
        {
          if ( !v6 )
          {
            if ( !v7 )
            {
              _frame.a1_2 = WORD2(_frame.result) + 30;
LABEL_14:
              rx_process_pending(0, (int)&_frame.a1a);
              set_reg_180800_bits7_8(v5);
              v8 = 0;
              goto LABEL_16;
            }
LABEL_25:
            _frame.a1_2 = WORD2(_frame.result) - 10;
            goto LABEL_14;
          }
          if ( v7 )
          {
            _frame.a1_2 = WORD2(_frame.result) - 30;
            goto LABEL_14;
          }
        }
        _frame.a1_2 = WORD2(_frame.result) + 10;
        goto LABEL_14;
      }
      _frame.a1_2 = WORD2(_frame.result);
      rx_process_pending(0, (int)&_frame.a1a);
      set_reg_180800_bits7_8(v5);
    }
    v8 = v4 == 10;
  }
LABEL_16:
  v9 = (void *)(uintptr_t)(off_124E20);
  v10 = HIBYTE(_frame.a1a);
  v11 = (uint8_t)_frame.a1a;
  *(volatile uint8_t *)off_124E1C = v8;
  *v9 = v8;
  clock_set_source(v11, v10, v8);
  dispatch_event_handler_1("\x9A\x88""BW Set Done : prim freq %d, center freq %d\n", _frame.a1_2, (uint16_t)_frame.a3);
  v12 = *(volatile uint32_t *)off_124E28;
  if ( *(volatile uint32_t *)off_124E28 )
  {
    init_with_stack(v12);
    return 0;
  }
  return v12;
}


// set_adv_channel_map @ 0x124e34
int set_adv_channel_map(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_13022C, a2);
    return -1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    gpio_set_high(v2);
    return 0;
  }
}


// set_scan_params @ 0x124e60
int set_scan_params(int a1, int a2) {
  volatile int *v3; // r5
  int v4; // r3
  volatile uint8_t *v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r5
  int v10; // r1
  int v11; // r2
  const volatile char *v12; // r1
  const volatile char *v13; // r2
  struct __attribute__((packed)) { uint16_t v15; // [sp+0h] [bp-14h] BYREF
  char v16; // [sp+2h] [bp-12h]
  char _pad2[1]; uint16_t v17; // [sp+4h] [bp-10h] BYREF
  char v18; // [sp+6h] [bp-Eh]
  char _pad4[1]; uint16_t v19; // [sp+8h] [bp-Ch] BYREF
  char v20; // [sp+Ah] [bp-Ah]
  char _pad6[1]; uint16_t v21; // [sp+Ch] [bp-8h] BYREF
  char v22; // [sp+Eh] [bp-6h]
  } _frame;
  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_130254, a2);
    return -1;
  }
  else
  {
    v3 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_124F08)[0]);
    v4 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    v5 = *(volatile uint8_t **)(a2 + 8);
    v6 = v4;
    v7 = parse_number(v5, nullptr, 0xAu);
    v8 = *(volatile uint32_t *)(uintptr_t)(off_124F0C);
    v9 = *v3;
    v10 = *(volatile uint32_t *)off_124F10;
    v11 = *(volatile uint32_t *)off_124F14;
    _frame.v15 = *(volatile uint32_t *)(uintptr_t)(off_124F0C);
    _frame.v16 = BYTE2(v8);
    _frame.v17 = v9;
    _frame.v18 = BYTE2(v9);
    _frame.v19 = v10;
    _frame.v20 = BYTE2(v10);
    _frame.v21 = v11;
    _frame.v22 = BYTE2(v11);
    if ( v6 )
    {
      if ( v7 )
      {
        gpio_set_pin(0);
        v12 = (const volatile char *)&_frame.v19;
      }
      else
      {
        gpio_set_pin(1);
        v12 = (const volatile char *)&_frame.v21;
      }
      v13 = (const volatile char *)&_frame.v15;
    }
    else
    {
      if ( v7 )
      {
        gpio_clear_pin(0);
        v12 = (const volatile char *)&_frame.v19;
      }
      else
      {
        gpio_clear_pin(1);
        v12 = (const volatile char *)&_frame.v21;
      }
      v13 = (const volatile char *)&_frame.v17;
    }
    dispatch_event_handler_1("%s table in %s mode\n", v12, v13);
    return 0;
  }
}


// set_random_addr @ 0x124f20
int set_random_addr(int a1, int a2) {
  int v2; // r0

  v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  set_reg_180800_bit9(v2);
  dispatch_event_handler_1(asc_1302A4);
  return 0;
}


// set_private_addr @ 0x124f40
int set_private_addr(int a1, int a2) {
  uint8_t v2; // r0

  v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
  rf_write_synth(v2);
  dispatch_event_handler_1(asc_1302BC);
  return 0;
}


// set_conn_interval @ 0x124f60
/* luna: BLE command handler that parses a decimal connection-interval value and writes it into the corresponding hardware bit-field, emitting usage/error trac */
int set_conn_interval(int a1, int a2) {
  int conn_interval; // r4

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1302D0, a2);
    return 1;
  }
  else
  {
    conn_interval = (uint8_t)parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_1807fc_bit6(conn_interval);
    if ( conn_interval )
      dispatch_event_handler_1(asc_1302EC);
    return 0;
  }
}


// set_conn_latency @ 0x124f9c
/* luna: Handles a Bluetooth/LE connection-latency shell command by reporting usage when no value is supplied or parsing a decimal latency and applying it. */
int set_conn_latency(int a1, int a2) {
  uint8_t latency; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130304, a2);
    return 1;
  }
  else
  {
    latency = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    rf_disable_1(latency);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_super_timeout @ 0x124fd0
int set_super_timeout(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_13032C, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    rf_set_bit18(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_adv_timeout @ 0x125004
int set_adv_timeout(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130348, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_1807fc_bit20(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_rf_channel_map @ 0x125038
int set_rf_channel_map(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130364, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_1807fc_bit21(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_rf_byte @ 0x12506c
/* luna: Command handler that parses a decimal byte argument and writes it to an RF register field, dispatching a usage event when no argument is supplied. */
int set_rf_byte(int a1, int a2) {
  uint8_t rf_value; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_130380, a2);
    return 1;
  }
  else
  {
    rf_value = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_158a08_bit16(rf_value);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_rx_gain @ 0x1250a0
int set_rx_gain(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_13039C, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_1807fc_bit0(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_tx_offset @ 0x1250d4
int set_tx_offset(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1303B8, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_158a08_bits20_25(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_clock_offset @ 0x125108
int set_clock_offset(int a1, int a2) {
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1303D0, a2);
    return 1;
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
    set_reg_1807fc_bits24_27(v2);
    dispatch_event_handler_1(asc_130320);
    return 0;
  }
}


// set_bdaddr @ 0x12513c
int set_bdaddr(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r3
  int v8; // r6
  unsigned int v9; // r3
  int v10; // r9
  int v11; // r1
  int v12; // r2
  char v13; // r10
  int v14; // r4
  int v15; // r3
  int a5; // r7

  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_1303E8, a2);
    return 1;
  }
  else
  {
    v4 = (uint16_t)parse_number((volatile uint8_t *)a2[1], nullptr, 0xAu);
    if ( a1 == 3 )
    {
      v5 = v4;
      v6 = parse_number((volatile uint8_t *)a2[2], nullptr, 0x10u);
    }
    else
    {
      v5 = (uint16_t)parse_number((volatile uint8_t *)a2[2], nullptr, 0xAu);
      v6 = parse_number((volatile uint8_t *)a2[3], nullptr, 0x10u);
    }
    v7 = *(volatile uint32_t *)off_125288 & 0x7F;
    if ( *((volatile uint8_t *)off_125284 + 36) == 1 )
    {
      v8 = (*(volatile uint32_t *)off_125288 >> 11) & 6;
      if ( v8 )
      {
        v8 = *(volatile uint32_t *)off_125288 & 0x78;
        if ( v8 )
        {
          v8 = *((volatile uint8_t *)off_125284 + 36);
        }
        else if ( v7 <= 2 )
        {
          v8 = 2;
        }
      }
      else if ( (*(volatile uint32_t *)off_125288 & 0x78) == 0 )
      {
        v8 = 2;
      }
    }
    else if ( ((*(volatile uint32_t *)off_125288 >> 11) & 6) != 0 )
    {
      v8 = v7 <= 4;
    }
    else
    {
      v8 = v7 <= 9;
    }
    if ( v5 > v4 )
    {
      v9 = v4;
      v4 = v5;
      v5 = v9;
    }
    v10 = (uint8_t)(v4 >> 5);
    v11 = (uint8_t)(v5 >> 5);
    if ( v10 == v11 )
    {
      mac_tx_frame(v8, v10, v5 & 0x1F, (1 << (v4 - v5 + 1)) - 1, v6 & ((1 << (v4 - v5 + 1)) - 1));
      goto LABEL_13;
    }
    v12 = v5 & 0x1F;
    if ( (v5 & 0x1F) != 0 )
    {
      v13 = 32 - v12;
      v14 = v4 & 0x1F;
      mac_tx_frame(v8, v11, v12, (1 << (32 - v12)) - 1, v6 & ((1 << (32 - v12)) - 1));
      v15 = (1 << (v14 + 1)) - 1;
      a5 = (v6 >> v13) & v15;
      if ( v14 != 31 )
      {
        mac_tx_frame(v8, v10, 0, v15, a5);
LABEL_13:
        dispatch_event_handler_1(asc_130320);
        return 0;
      }
      dispatch_event_handler_1(aPos1Err);
      return 1;
    }
    else
    {
      dispatch_event_handler_1(aPos2Err);
      return 1;
    }
  }
}


// rf_store_cal_byte @ 0x12529c
int rf_store_cal_byte() {
  dispatch_event_handler_1("RSSI : %d\r\n", *(volatile char *)off_1252B0);
  return 0;
}


// set_local_name @ 0x1252b8
int set_local_name(int a1, volatile uint32_t *a2) {
  int v4; // r0
  unsigned int v6; // r4
  int v7; // r0
  unsigned int v8; // r4
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r0
  unsigned int v12; // r1

  v4 = parse_number((volatile uint8_t *)a2[1], nullptr, 0);
  if ( v4 == 1 )
  {
    if ( a1 > 3 )
    {
      v8 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
      v9 = parse_number((volatile uint8_t *)a2[3], nullptr, 0x10u);
      dispatch_event_handler_1("wr efuse: [%d]=%08X\r\n", v8, v9);
      mmio_write32(v8, v9);
    }
  }
  else
  {
    if ( v4 != 2 )
      return -(v4 != 0);
    v6 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
    if ( v6 <= 0x1F )
    {
      if ( a1 > 3 )
      {
        v10 = parse_number((volatile uint8_t *)a2[3], nullptr, 0) + v6;
        if ( v10 >= 0x20 )
          v10 = 32;
        dispatch_event_handler_1(aRdEfuse);
        while ( v10 > v6 )
        {
          v11 = mmio_read32(v6);
          v12 = v6++;
          dispatch_event_handler_1("[%d]=%08X\r\n", v12, v11);
        }
      }
      else
      {
        dispatch_event_handler_1(aRdEfuse);
        v7 = mmio_read32(v6);
        dispatch_event_handler_1("[%d]=%08X\r\n", v6, v7);
      }
    }
  }
  return 0;
}


// bt_conditional_action @ 0x12537c
int bt_conditional_action(int a1, int a2) {
  BOOL v2; // r1

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1("txpwr_manual_mode: %x\r\n", *(volatile uint32_t *)off_1253B0);
  }
  else
  {
    v2 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0) != 0;
    *(volatile uint32_t *)off_1253B0 = v2;
    dispatch_event_handler_1("set txpwr_manual_mode: %x\r\n", v2);
  }
  return 0;
}


// process_bt_connection_event @ 0x1253bc
int process_bt_connection_event(int a1, volatile uint32_t *a2) {
  int v4; // r0
  int v5; // r7
  int v6; // r0
  int v7; // r7
  volatile uint32_t *v8; // r4
  int v9; // r10
  int m; // r5
  volatile uint8_t *v11; // t1
  char v12; // r0
  int v13; // r6
  int v14; // r11
  int v15; // r0
  volatile uint32_t *v16; // r4
  int v17; // r8
  unsigned int k; // r6
  volatile uint8_t *v19; // t1
  int v20; // r5
  volatile char *v21; // r9
  volatile uint8_t *v22; // r10
  volatile char *v23; // r6
  int i; // r4
  int v25; // r5
  int v26; // t1
  volatile char *v27; // r9
  int v28; // r8
  volatile char *v29; // r6
  unsigned int j; // r4
  int v31; // r5
  int v32; // t1
  int v34; // r0
  int v35; // r6
  BOOL v36; // r5
  char v37; // r0
  volatile char *v38; // r2
  char v39; // r3
  const volatile char *v40; // r0
  volatile char *v41; // r2
  int v42; // r0
  char v43; // r0

  v4 = parse_number((volatile uint8_t *)a2[1], nullptr, 0);
  v5 = v4;
  switch ( v4 )
  {
    case 0:
      v21 = (volatile char *)off_1256C8;
      v22 = (void *)(uintptr_t)(off_1256B4);
      dispatch_event_handler_1(aTxpwrLevel24g0);
      do
      {
        dispatch_event_handler_1("  [%x] =", v5);
        v23 = v21;
        for ( i = 0; i != 12; ++i )
        {
          v26 = *v23++;
          v25 = v26;
          if ( v26 != -128 )
          {
            if ( i && !(i << 30) )
              uart_tx_byte(32);
            dispatch_event_handler_1(" %2d", v25);
          }
        }
        ++v5;
        uart_tx_string(v22);
        v21 += 12;
      }
      while ( v5 != 3 );
      v27 = (volatile char *)off_1256B8;
      dispatch_event_handler_1(aTxpwrLevel5g01);
      v28 = 0;
      while ( 1 )
      {
        dispatch_event_handler_1("  [%x] =", v28);
        v29 = v27;
        for ( j = 0; ; ++j )
        {
          v32 = *v29++;
          v31 = v32;
          if ( v32 != -128 )
            break;
          if ( j > 3 )
            goto LABEL_48;
          dispatch_event_handler_1(aNa);
LABEL_49:
          ;
        }
        if ( j && !(j << 30) )
          uart_tx_byte(32);
        dispatch_event_handler_1(" %2d", v31);
LABEL_48:
        if ( j != 11 )
          goto LABEL_49;
        ++v28;
        uart_tx_string((void *)(uintptr_t)(off_1256B4));
        v27 += 12;
        if ( v28 == 3 )
          return 0;
      }
    case 1:
      if ( a1 > 4 )
      {
        v15 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
        v7 = v15;
        if ( v15 > 2 )
        {
          dispatch_event_handler_1("wrong lvl grp:%d\n", v15);
          return 0;
        }
        if ( a1 > 12 )
        {
          dispatch_event_handler_1("set txpwr_level_2.4g:\n  [%d] =", v15);
          v16 = a2 + 2;
          v17 = dword_1256A4 + 12 * v7;
          for ( k = 0; v7 != 1 || k <= 9; ++k )
          {
            v19 = (volatile uint8_t *)v16[1];
            ++v16;
            v20 = (char)parse_number(v19, nullptr, 0);
            if ( v20 >= 32 )
              v20 = 32;
            *(volatile uint8_t *)++v17 = v20;
            if ( k )
            {
              if ( !(k << 30) )
                uart_tx_byte(32);
              dispatch_event_handler_1(" %2d", v20);
              if ( k == 11 )
                goto LABEL_63;
            }
            else
            {
              dispatch_event_handler_1(" %2d", v20);
            }
          }
          goto LABEL_63;
        }
        v42 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
        v35 = v42;
        if ( v7 == 1 )
          v36 = v42 <= 9;
        else
          v36 = v42 <= 11;
        if ( v36 )
        {
          v43 = parse_number((volatile uint8_t *)a2[4], nullptr, 0);
          v38 = (volatile char *)off_1256C8;
          v39 = v43;
          v40 = aSetTxpwrLevel2;
          goto LABEL_59;
        }
        goto LABEL_65;
      }
      goto LABEL_72;
    case 2:
      if ( a1 > 4 )
      {
        v6 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
        v7 = v6;
        if ( v6 > 2 )
        {
          dispatch_event_handler_1("wrong lvl grp:%d\n", v6);
          return 0;
        }
        if ( a1 > 12 )
        {
          dispatch_event_handler_1("set txpwr_level_5g:\n  [%d] =", v6);
          v8 = a2 + 2;
          v9 = dword_12569C + 12 * v7;
          for ( m = 0; m != 12; ++m )
          {
            if ( v7 == 1 && m > 9 )
              break;
            v11 = (volatile uint8_t *)v8[1];
            ++v8;
            v12 = parse_number(v11, nullptr, 0);
            v13 = v12;
            v14 = v12;
            if ( v12 >= 32 )
              v14 = 32;
            *(volatile uint8_t *)++v9 = v14;
            if ( m && !(m << 30) )
              uart_tx_byte(32);
            if ( v13 == -128 )
              dispatch_event_handler_1(aNa, v14);
            else
              dispatch_event_handler_1(" %2d", v14);
          }
LABEL_63:
          uart_tx_string((void *)(uintptr_t)(off_1256B4));
          return 0;
        }
        v34 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
        v35 = v34;
        if ( v7 == 1 )
          v36 = v34 <= 9;
        else
          v36 = v34 <= 11;
        if ( v36 )
        {
          v37 = parse_number((volatile uint8_t *)a2[4], nullptr, 0);
          v38 = (volatile char *)off_1256B8;
          v39 = v37;
          v40 = aSetTxpwrLevel5;
LABEL_59:
          v41 = &v38[12 * v7];
          if ( v39 >= 32 )
            v39 = 32;
          v41[v35] = v39;
          dispatch_event_handler_1(v40, v7, v35);
          return 0;
        }
LABEL_65:
        dispatch_event_handler_1("wrong grp idx:%d\n", v35);
        return v36;
      }
LABEL_72:
      dispatch_event_handler_1(aWrongArgs_0);
      return -1;
  }
  dispatch_event_handler_1(aWrongFunc);
  return -1;
}


// process_bt_inquiry_event @ 0x1256e0
int process_bt_inquiry_event(int a1, volatile uint32_t *a2) {
  int v4; // r0
  int v5; // r5
  volatile uint8_t *v6; // r7
  int v7; // r5
  int v8; // r0
  int v9; // r6
  volatile uint8_t *v10; // r0
  volatile uint16_t *v11; // r4
  int v12; // r0
  int v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  int v16; // r2
  volatile uint8_t *v17; // r7
  int v18; // r5
  int v19; // r0
  int v20; // r6
  volatile uint8_t *v21; // r0
  volatile uint8_t *v22; // r4
  int v23; // r0
  int v24; // r3
  unsigned int v25; // r1
  int v26; // r2
  volatile uint32_t *v28; // r8
  int i; // r4
  int v30; // r1
  volatile uint32_t *v31; // r7
  int j; // r8
  int k; // r4
  int v34; // r1
  int v35; // [sp+4h] [bp-8h]
  int v36; // [sp+4h] [bp-8h]

  v4 = parse_number((volatile uint8_t *)a2[1], nullptr, 0);
  v5 = v4;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v17 = (volatile uint8_t *)off_125930;
      ++*(volatile uint8_t *)off_125930;
      if ( a1 <= 4 )
      {
LABEL_50:
        dispatch_event_handler_1(aWrongArgs);
        return -1;
      }
      v18 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
      v19 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
      v20 = v19;
      if ( v18 > 2 || v19 > 2 )
      {
LABEL_49:
        dispatch_event_handler_1(aWrongTypeChgrp);
        return -1;
      }
      v21 = (volatile uint8_t *)a2[4];
      v22 = (void *)(uintptr_t)(off_125934);
      v23 = parse_number(v21, nullptr, 0);
      v24 = -7;
      if ( v23 > -7 )
        v24 = v23;
      if ( v24 >= 7 )
        v24 = 7;
      *(volatile uint8_t *)(3 * v18 + *(volatile uint32_t *)off_12593C + v20) = v24;
      v25 = *((volatile uint16_t *)v22 + 20);
      if ( v25 > 0x97B )
      {
        if ( v25 > 0x994 )
          v26 = 2;
        else
          v26 = 1;
      }
      else
      {
        v26 = 0;
      }
      if ( !v22[36] && v26 == v20 )
      {
        v36 = v24;
        rf_ctrl_set(0, v25);
        v24 = v36;
        ++*v17;
      }
      dispatch_event_handler_1("set pwrofst2x_2.4g:\n  [%d][%d]=%d\n", v18, v20, v24);
      return 0;
    }
    else
    {
      if ( v4 == 2 )
      {
        v6 = (volatile uint8_t *)off_125930;
        ++*(volatile uint8_t *)off_125930;
        if ( a1 > 4 )
        {
          v7 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
          v8 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
          v9 = v8;
          if ( v7 <= 2 && v8 <= 5 )
          {
            v10 = (volatile uint8_t *)a2[4];
            v11 = (volatile uint16_t *)off_125934;
            v12 = parse_number(v10, nullptr, 0);
            v13 = -7;
            if ( v12 > -7 )
              v13 = v12;
            if ( v13 >= 7 )
              v13 = 7;
            *(volatile uint8_t *)(*(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)&off_125938)[0] + 6 * v7 + v9) = v13;
            v14 = v11[20];
            v15 = *((volatile uint8_t *)v11 + 36);
            if ( v14 > 0x1666 )
            {
              v16 = 5;
            }
            else
            {
              if ( v14 > 0x1616 )
              {
                v16 = 4;
                if ( v15 != 1 )
                  goto LABEL_40;
                goto LABEL_45;
              }
              if ( v14 > 0x15C6 )
              {
                v16 = 3;
              }
              else if ( v14 <= 0x1571 )
              {
                v16 = v14 > 0x1486;
              }
              else
              {
                v16 = 2;
              }
            }
            if ( v15 != 1 )
            {
LABEL_40:
              dispatch_event_handler_1("set pwrofst2x_5g:\n  [%d][%d]=%d\n", v7, v9, v13);
              return 0;
            }
LABEL_45:
            if ( v16 == v9 )
            {
              v35 = v13;
              rf_ctrl_set(v15, v14);
              v13 = v35;
              ++*v6;
            }
            goto LABEL_40;
          }
          goto LABEL_49;
        }
        goto LABEL_50;
      }
      dispatch_event_handler_1(aWrongFunc_0);
      return -1;
    }
  }
  else
  {
    v28 = (void *)(uintptr_t)(off_12593C);
    dispatch_event_handler_1(aPwrofst2x24g01);
    dispatch_event_handler_1(aChan14591013);
    do
    {
      dispatch_event_handler_1("\n  [%d] =", v5);
      for ( i = 0; i != 3; ++i )
      {
        v30 = *(volatile char *)(*v28 + 3 * v5 + i);
        dispatch_event_handler_1("\t%d", v30);
      }
      ++v5;
    }
    while ( v5 != 3 );
    v31 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_125938)[0]);
    dispatch_event_handler_1(aPwrofst2x5g0Of);
    dispatch_event_handler_1(aChan3650516498);
    for ( j = 0; j != 3; ++j )
    {
      dispatch_event_handler_1("\n  [%d] =", j);
      for ( k = 0; k != 6; ++k )
      {
        v34 = *(volatile char *)(*v31 + 6 * j + k);
        dispatch_event_handler_1("\t%d", v34);
      }
    }
    dispatch_event_handler_1((const volatile char *)off_12595C);
    return 0;
  }
}


// rf_cmd_set_tone_power_offset @ 0x125970
int rf_cmd_set_tone_power_offset(int a1, int a2) {
  int v4; // r0
  int v5; // r0
  int v6; // r1
  volatile uint8_t *v8; // r7
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r4
  volatile uint8_t *v13; // r7
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r4

  v4 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
  switch ( v4 )
  {
    case 0:
      dispatch_event_handler_1(
        "rf_tone_pwr_ofst=%d,%d,%d\n",
        *(volatile char *)off_125A98,
        *(volatile char *)(off_125A98 + 1),
        *(volatile char *)(off_125A98 + 2));
      return 0;
    case 1:
      v8 = (volatile uint8_t *)off_125AA0;
      ++*(volatile uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v9 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      v10 = off_125AA4;
      v11 = *(volatile uint8_t *)(off_125AA4 + 0x24);
      if ( v9 < -7 )
        v9 = -7;
      if ( v9 >= 7 )
        v9 = 7;
      v12 = v9;
      *(volatile uint8_t *)off_125A98 = v9;
      if ( !v11 )
      {
        rf_ctrl_set(0, *(volatile uint16_t *)(v10 + 0x28));
        ++*v8;
      }
      dispatch_event_handler_1("set rf_tone_pwr_ofst_2g4=%d\n", v12);
      return 0;
    case 2:
      v13 = (volatile uint8_t *)off_125AA0;
      ++*(volatile uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v14 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      v15 = off_125AA4;
      v16 = *(volatile uint8_t *)(off_125AA4 + 0x24);
      if ( v14 < -7 )
        v14 = -7;
      if ( v14 >= 7 )
        v14 = 7;
      v17 = v14;
      *(volatile uint8_t *)(off_125A98 + 1) = v14;
      if ( v16 == 1 )
      {
        rf_ctrl_set(1, *(volatile uint16_t *)(v15 + 0x28));
        ++*v13;
      }
      dispatch_event_handler_1("set rf_tone_pwr_ofst_5g=%d\n", v17);
      return 0;
    case 3:
      if ( a1 > 2 )
      {
        v5 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
        if ( v5 < -7 )
          v5 = -7;
        v6 = v5;
        if ( v5 >= 7 )
          v6 = 7;
        *(volatile uint8_t *)(off_125A98 + 2) = v6;
        dispatch_event_handler_1("set rf_tone_pwr_ofst_bt=%d\n", v6);
        return 0;
      }
LABEL_28:
      dispatch_event_handler_1(aWrongArgs);
      return -1;
    default:
      dispatch_event_handler_1(aWrongFunc_0);
      return -1;
  }
}


// bt_control_block_cleanup @ 0x125abc
int bt_control_block_cleanup(int a1, int a2) {
  parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
  dispatch_event_handler_1(aWrongFunc);
  return -1;
}


// bt_state_machine_dispatch @ 0x125ad8
unsigned int bt_state_machine_dispatch(unsigned int result) {
  unsigned int v1; // r4
  int v2; // r3
  int v3; // r1
  volatile int *v4; // r3
  int v5; // r2
  volatile int *v6; // r3
  int v7; // r2
  volatile int *v8; // r3
  int v9; // r2
  volatile uint32_t *v10; // r3
  int v11; // r2
  uint64_t v12; // [sp+0h] [bp-8h] BYREF

  if ( result )
  {
    v1 = result;
    if ( result <= 2 )
    {
      mac_time_get(&v12, 0);
      v2 = off_125B78;
      v3 = BYTE1(v12);
      *(volatile uint32_t *)off_125B78 = dword_125B7C;
      if ( v1 == 1 )
      {
        if ( v3 )
        {
          v10 = (void *)(uintptr_t)(off_125BBC);
          *(volatile uint32_t *)off_125BB8 = 2047;
          *v10 = 341;
        }
        else
        {
          v11 = dword_125BD0;
          *(volatile uint32_t *)off_125B80 = dword_125BCC;
          *(volatile uint32_t *)(v2 + 0xFFFFFF74) = v11;
        }
        *(volatile uint32_t *)off_125B90 = dword_125BC0;
      }
      else
      {
        if ( v3 )
        {
          v4 = (volatile int *)off_125BBC;
          v5 = dword_125BC8;
          *(volatile uint32_t *)off_125BB8 = dword_125BC4;
        }
        else
        {
          v4 = (volatile int *)off_125B84;
          v5 = dword_125B8C;
          *(volatile uint32_t *)off_125B80 = dword_125B88;
        }
        *v4 = v5;
        *(volatile uint32_t *)off_125B90 = dword_125B94;
      }
      v6 = (volatile int *)off_125B9C;
      v7 = dword_125BA0;
      *(volatile uint32_t *)off_125B98 = dword_125BA4;
      *v6 = v7;
      return dispatch_event_handler_1(aSetPapr);
    }
  }
  else
  {
    v8 = (volatile int *)off_125B9C;
    v9 = dword_125BAC;
    *(volatile uint32_t *)off_125B78 = dword_125BB0;
    *v8 = v9;
    return dispatch_event_handler_1(aUnsetPapr);
  }
  return result;
}


// process_bt_ble_event @ 0x125bfc
int process_bt_ble_event(int a1, volatile uint32_t *a2) {
  int v4; // r8
  int v5; // r4
  int v6; // r5
  int v7; // r6
  BOOL v9; // r0
  BOOL v10; // r0

  v4 = *(volatile uint8_t *)(*a2 + 4);
  v5 = parse_number((volatile uint8_t *)a2[1], nullptr, 0);
  v6 = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
  if ( v6 )
  {
    if ( a1 <= 3 )
      return -1;
    v7 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
    if ( v4 == 97 )
      goto LABEL_4;
  }
  else
  {
    v7 = 0;
    if ( v4 == 97 )
    {
LABEL_4:
      if ( v5 <= 15 )
      {
        rf_channel_valid(v5);
        if ( v6 )
        {
          gpio_cfg_set(v5);
          if ( v7 )
            gpio_out_set(v5);
          else
            gpio_out_clear(v5);
          dispatch_event_handler_1("gpioa%d output %d\n", v5, v7);
          return 0;
        }
        else
        {
          gpio_cfg_clear(v5);
          v10 = gpio_read_pin(v5);
          dispatch_event_handler_1("gpioa%d input %d\n", v5, v10);
          return 0;
        }
      }
      dispatch_event_handler_1("invalid gpioa idx: %d\n", v5);
      return -2;
    }
  }
  if ( v5 > 15 )
  {
    dispatch_event_handler_1("invalid gpiob idx: %d\n", v5);
    return -2;
  }
  pinmux_config_1(v5);
  if ( !v6 )
  {
    gpio_disable_interrupt(v5);
    v9 = gpio_get_pin(v5);
    dispatch_event_handler_1("gpiob%d input %d\n", v5, v9);
    return v6;
  }
  gpio_set_pin_1(v5);
  if ( v7 )
    gpio_set_pin_out(v5);
  else
    gpio_clear_pin_1(v5);
  dispatch_event_handler_1("gpiob%d output %d\n", v5, v7);
  return 0;
}


// bt_conn_init @ 0x125d18
int bt_conn_init(int a1, int a2) {
  uint8_t v3; // r0

  if ( a1 > 1 )
  {
    v3 = parse_number(*(volatile uint8_t **)(a2 + 4), 0, 0xAu);
    ll_state_process(0, 0, v3);
  }
  else
  {
    ll_state_process(0, 0, 0);
  }
  return 0;
}



// parse_bt_name_field @ 0x125d44
int parse_bt_name_field(int a1, int a2) {
  uint16_t v3; // r3
  volatile uint8_t *v4; // r0
  uint16_t v5; // r4
  uint16_t v6; // r5
  int v7; // r3
  int v9[2]; // [sp+4h] [bp-8h] BYREF

  v3 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0x10u);
  v4 = *(volatile uint8_t **)(a2 + 8);
  v5 = v3;
  v6 = parse_number(v4, nullptr, 0x10u);
  memset(v9, 0, 4u);
  v9[0] = (v9[0] & ~0xFFFFu) | ((uint16_t)(v5) & 0xFFFFu);
  v7 = *(volatile uint32_t *)off_125D9C;
  v9[0] = (v9[0] & ~0xFFFF0000u) | (((uint16_t)(v6) & 0xFFFFu) << 16);
  if ( (v7 & 0x2000000) == 0 )
  {
    mmio_write_400000_4_alt((int)v9);
    dispatch_event_handler_1("set vid 0x%x, pid 0x%x\n", v5, v6);
  }
  return 0;
}


// check_mmio_status_flag @ 0x125da4
int check_mmio_status_flag() {
  int v1; // r4
  int result[3]; // [sp+4h] [bp-Ch] BYREF

  if ( (*(volatile uint32_t *)off_125DFC & 0x2000000) != 0 )
    return 0;
  memset(result, 0, 4u);
  v1 = mmio_write_400000_4((int)result);
  dispatch_event_handler_1("ret %d\n", v1);
  if ( v1 || HIWORD(result[0]) == 0xFFFF || LOWORD(result[0]) == 0xFFFF )
    dispatch_event_handler_1(aNoUsbInfoInFla_0);
  else
    dispatch_event_handler_1("get vid 0x%x, pid 0x%x\r\n", LOWORD(result[0]), HIWORD(result[0]));
  return 0;
}


// bt_msg_send_if_allocated @ 0x125e0c
int bt_msg_send_if_allocated(volatile uint8_t **a1, volatile uint8_t *a2) {
  if ( a2 )
    return util_list_find(a1, a2);
  else
    return 0;
}



// acl_rx_handler @ 0x125e18
int acl_rx_handler(int a1, int a2) {
  volatile uint8_t *v3; // r1
  volatile uint8_t *v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r0
  volatile char *a2a; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1305D8, a2);
    return -1;
  }
  else
  {
    if ( strlen(*(volatile uint32_t *)(a2 + 4)) == 1 || strlen(*(volatile uint32_t *)(a2 + 4)) == 2 )
    {
      if ( strlen(*(volatile uint32_t *)(a2 + 4)) == 1 )
      {
        v3 = *(volatile uint8_t **)(a2 + 4);
        if ( !v3 || !util_list_find((volatile uint8_t **)off_125ECC, v3) )
        {
LABEL_7:
          dispatch_event_handler_1(aCountrycodeErr);
          return 0;
        }
      }
      else
      {
        if ( strlen(*(volatile uint32_t *)(a2 + 4)) != 2 )
          return 0;
        v5 = *(volatile uint8_t **)(a2 + 4);
        if ( !v5 || !util_list_find((volatile uint8_t **)off_125ED4, v5) )
          goto LABEL_7;
      }
      dispatch_event_handler_1(aSetccSuccess);
      a2a = *(volatile char **)(a2 + 4);
      v6 = strlen((unsigned int)a2a);
      memcpy((volatile char *)dword_125EDC, a2a, v6);
      dispatch_event_handler_1("country code: %s\n", (const volatile char *)dword_125EDC);
      if ( (*(volatile uint32_t *)off_125EE4 & 0x2000000) == 0 )
        mmio_write_100000_2(dword_125EDC);
      return 0;
    }
    v7 = strlen(*(volatile uint32_t *)(a2 + 4));
    dispatch_event_handler_1("wrong len of countrycode %d\n", v7);
    return -1;
  }
}


// poll_radio_status @ 0x125ef0
int poll_radio_status(int a1, int a2, int a3) {
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(volatile uint32_t *)off_125F48 & 0x2000000) != 0 )
  {
    dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)dword_125F50);
    return 0;
  }
  else
  {
    *(volatile uint16_t *)v4 = 0;
    bus_read_2((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      dispatch_event_handler_1(aNoCountrycodeI);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)v4);
      return 0;
    }
  }
}


// ll_data_handler @ 0x125f58
int ll_data_handler(int a1, int a2) {
  volatile uint8_t *v3; // r1
  unsigned int v5; // r0
  volatile char *a2a; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1305D8, a2);
    return -1;
  }
  else if ( strlen(*(volatile uint32_t *)(a2 + 4)) == 2 )
  {
    v3 = *(volatile uint8_t **)(a2 + 4);
if ( v3 && util_list_find((volatile uint8_t **)((volatile uint32_t *)(uintptr_t)&off_125FDC)[0], v3) ) { dispatch_event_handler_1(aSetccSuccess);
      a2a = *(volatile char **)(a2 + 4);
      v5 = strlen((unsigned int)a2a);
      memcpy((volatile char *)dword_125FE8, a2a, v5);
      dispatch_event_handler_1("country code: %s\n", (const volatile char *)dword_125FE8);
      if ( (*(volatile uint32_t *)off_125FF0 & 0x2000000) == 0 )
        mmio_write_800000_2(dword_125FE8);
      return 0;
    }
    else
    {
      dispatch_event_handler_1(aCountrycodeErr);
      return 0;
    }
  }
  else
  {
    dispatch_event_handler_1(aWrongLenOfCoun_0);
    return -1;
  }
}


// check_radio_flag @ 0x125ffc
int check_radio_flag(int a1, int a2, int a3) {
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  if ( (*(volatile uint32_t *)off_126054 & 0x2000000) != 0 )
  {
    dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)dword_12605C);
    return 0;
  }
  else
  {
    *(volatile uint16_t *)v4 = 0;
    rf_cmd_wait_n_7e((int)v4);
    if ( v4[0] == 255 || v4[1] == 255 )
    {
      dispatch_event_handler_1(aNoCountrycodeI);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("getcc: %s\r\n", (const volatile char *)v4);
      return 0;
    }
  }
}


// pkt_buf_clear @ 0x126064
int pkt_buf_clear(int a1, volatile uint32_t *a2) {
  uint16_t v3; // r6
  uint16_t v4; // r7
  uint16_t v5; // r8
  uint16_t v6; // r3
  volatile uint8_t *v7; // r0
  uint16_t v8; // r4
  uint8_t v9; // r5
  int v10; // r3
  struct __attribute__((packed)) { int result; // [sp+Ch] [bp-Ch] BYREF
  uint16_t v13; // [sp+10h] [bp-8h]
  uint16_t v14; // [sp+12h] [bp-6h]
  uint8_t v15; // [sp+14h] [bp-4h]
  } _frame;
  v3 = parse_number((volatile uint8_t *)a2[1], nullptr, 0x10u);
  v4 = parse_number((volatile uint8_t *)a2[2], nullptr, 0x10u);
  v5 = parse_number((volatile uint8_t *)a2[3], nullptr, 0x10u);
  v6 = parse_number((volatile uint8_t *)a2[4], nullptr, 0x10u);
  v7 = (volatile uint8_t *)a2[5];
  v8 = v6;
  v9 = parse_number(v7, nullptr, 0x10u);
  memset(&_frame.result, 0, 0xAu);
  _frame.v15 = v9;
  v10 = *(volatile uint32_t *)off_1260FC;
  _frame.result = (_frame.result & ~0xFFFFu) | ((uint16_t)(v3) & 0xFFFFu);
  _frame.result = (_frame.result & ~0xFFFF0000u) | (((uint16_t)(v4) & 0xFFFFu) << 16);
  _frame.v13 = v5;
  _frame.v14 = v8;
  if ( (v10 & 0x2000000) == 0 )
  {
    send_cmd_short((int)&_frame.result);
    dispatch_event_handler_1("set vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\n", v3, v4, v5, v8, v9);
  }
  return 0;
}


// rf_is_ready @ 0x126104
int rf_is_ready() {
  int v1; // r4
  struct __attribute__((packed)) { int result; // [sp+Ch] [bp-14h] BYREF
  uint16_t a4; // [sp+10h] [bp-10h]
  uint16_t a4_2; // [sp+12h] [bp-Eh]
  uint8_t v5; // [sp+14h] [bp-Ch]
  } _frame;
  if ( (*(volatile uint32_t *)off_126164 & 0x2000000) != 0 )
    return 0;
  memset(&_frame.result, 0, 0xAu);
  v1 = mmio_write_1000000_10((int)&_frame.result);
  dispatch_event_handler_1("ret %d\n", v1);
  if ( v1 )
    dispatch_event_handler_1(aNoPcieInfoInFl_0);
  else
    dispatch_event_handler_1(
      "get vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\r\n",
      (uint16_t)_frame.result,
      HIWORD(_frame.result),
      _frame.a4,
      _frame.a4_2,
      _frame.v5);
  return 0;
}


// radio_timer_snapshot @ 0x126174
int radio_timer_snapshot() {
  volatile uint64_t *v0; // r5
  volatile uint32_t *v1; // r7
  int v2; // r1
  uint64_t v3; // r0
  volatile uint32_t *v4; // r12
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r1
  volatile uint32_t *v7; // r5
  struct __attribute__((packed)) { char v9; // [sp+6h] [bp-46h] BYREF
  char v10; // [sp+7h] [bp-45h] BYREF
  int v11; // [sp+8h] [bp-44h] BYREF
  uint16_t v12; // [sp+Ch] [bp-40h]
  char _pad4[2]; int v13; // [sp+10h] [bp-3Ch] BYREF
  int16_t v14; // [sp+14h] [bp-38h]
  char _pad6[2]; uint8_t v15[8]; // [sp+18h] [bp-34h] BYREF
  int v16; // [sp+20h] [bp-2Ch] BYREF
  int16_t v17; // [sp+24h] [bp-28h]
  char _pad9[2]; uint8_t v18[18]; // [sp+28h] [bp-24h] BYREF
  uint8_t v19[18]; // [sp+3Ah] [bp-12h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_12623C);
  v1 = (void *)(uintptr_t)(off_126240);
  v2 = *((volatile uint32_t *)off_12623C + 1);
  _frame.v13 = *(volatile uint32_t *)off_12623C;
  _frame.v14 = v2;
  _frame.v9 = 0;
  _frame.v10 = 1;
  memcpy((void *)(&_frame.v11), (void *)(&_frame.v13), 6);
  memcpy(_frame.v19, (void *)(&_frame.v11), 6);
  _frame.v19[7] = 0;
  format_message(0, 0, 0, 0);
  process_pending_events((int)&_frame.v11, 0, 0, &_frame.v10);
  kernel_send_msg(0, (int)_frame.v18, 0, 0);
  v3 = v0[1];
  _frame.v17 = *((volatile uint32_t *)v0 + 3);
  _frame.v16 = v3;
  memcpy(_frame.v15, (void *)(&_frame.v16), 6);
  process_pending_events((int)_frame.v15, 0, 0, &_frame.v9);
  v4 = (void *)(uintptr_t)(off_126254);
  *(volatile uint32_t *)off_126244 = _frame.v11;
  v5 = (void *)(uintptr_t)(off_126248);
  v6 = (void *)(uintptr_t)(off_12624C);
  v7 = (void *)(uintptr_t)(off_126250);
  *v4 = _frame.v12;
  *v5 = 0xFFFF;
  *v6 = -1;
  *v1 = 0xFFFF;
  *v7 = -1;
  configure_hw_regs(2u, 0, 0);
  set_reg_180800_bits7_8(0);
  set_reg_1807fc_bit6(1);
  return rf_set_bit18(0);
}



// ll_state_process @ 0x126258
int ll_state_process(int a1, int a2, char a3) {
  volatile uint8_t *v3; // r5
  volatile uint8_t *v5; // r3
  volatile uint8_t *v6; // r0
  volatile uint8_t *v7; // r1
  volatile char *v8; // r2
  volatile uint32_t *v9; // r3
  volatile int *v10; // r0
  volatile uint32_t *v11; // r0
  volatile uint8_t *v12; // r1
  volatile char *v13; // r2

  v3 = (void *)(uintptr_t)(off_1262EC);
  if ( *(volatile uint8_t *)off_1262EC )
    dispatch_event_handler_1("cob isn't idle: %d\n", *(volatile uint8_t *)off_1262EC);
  v5 = (void *)(uintptr_t)(off_1262F4);
  v6 = (void *)(uintptr_t)(off_1262F8);
  v7 = (void *)(uintptr_t)(off_1262FC);
  v8 = (volatile char *)off_126300;
  *(volatile uint32_t *)(uintptr_t)(off_1262F0) = -1;
  *v5 = 0;
  v9 = (void *)(uintptr_t)(off_126304);
  *v6 = 0;
  *v7 = 0;
  *v8 = a3;
  v10 = (volatile int *)dword_126308;
  *v9 |= 0x100u;
  *v9 |= 0x200u;
  *v9 |= 0x400u;
  memset(v10, 0, 8u);
  dispatch_event_handler_1(aCobDutStart);
  v11 = (void *)(uintptr_t)(off_126314);
  v12 = (void *)(uintptr_t)(off_126318);
  v13 = (void *)(uintptr_t)(off_12631C);
  *(volatile uint16_t *)off_126310 = 0;
  *v11 = 0;
  *v12 = 1;
  *v13 = 1;
  set_xtal_ftune(16);
  *(volatile uint32_t *)off_126320 = *(volatile uint32_t *)off_126320 & 0xFF03FFFF | 0x800000;
  *v3 = 5;
  dispatch_event_handler_1("cob state -> %d\n", 5);
  return set_busy_flag_alt(0x2000);
}


// ll_state_reset @ 0x12632c
int ll_state_reset() {
  int v0; // r4
  volatile char *v1; // r8
  volatile uint16_t *v2; // r5
  int v3; // r1
  volatile uint8_t *v4; // r5
  volatile uint16_t *v5; // r4
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r2
  volatile uint32_t *v8; // r2
  volatile unsigned int *v9; // r4
  int v10; // r1
  int result; // r0
  unsigned int v12; // r3
  volatile int *v13; // r3
  int v14; // r3
  volatile uint32_t *v15; // r3

  *(volatile uint8_t *)off_126424 = 0;
  dispatch_event_handler_1("cob state -> %d\n", 0);
  v0 = *(volatile uint8_t *)off_12642C;
  if ( v0 == 1 )
  {
    v15 = (void *)(uintptr_t)(off_126450);
    *(volatile uint32_t *)off_126450 &= ~0x100u;
    *v15 &= ~0x200u;
    *v15 &= ~0x400u;
    goto LABEL_15;
  }
  if ( *(volatile uint8_t *)off_12642C )
  {
LABEL_15:
    dispatch_event_handler_1(
      "dut%d,%d,%d,%d,%d,%d\n",
      *(volatile uint8_t *)off_126434,
      *(volatile uint16_t *)off_126430,
      *((volatile uint8_t *)off_126430 + 2),
      *((volatile char *)off_126430 + 3),
      *((volatile char *)off_126430 + 4),
      *((volatile char *)off_126430 + 5));
    goto LABEL_7;
  }
  v1 = (void *)(uintptr_t)(off_126458);
if ( *(volatile uint32_t *)(uintptr_t)(off_126458) ) { v2 = (volatile uint16_t *)off_126430;
    v3 = *(volatile uint8_t *)off_12642C;
    do
    {
      dispatch_event_handler_1(
        "dut%d,%d,%d,%d,%d,%d\n",
        v3 + 1,
        v2[4 * v3],
        LOBYTE(v2[4 * v3 + 1]),
        SHIBYTE(v2[4 * v3 + 1]),
        SLOBYTE(v2[4 * v3 + 2]),
        SHIBYTE(v2[4 * v3 + 2]));
      v3 = (uint8_t)++v0;
    }
    while ( (uint8_t)*v1 > (unsigned int)(uint8_t)v0 );
  }
  v4 = (volatile uint8_t *)off_126434;
  v5 = (void *)(uintptr_t)(off_126438);
  memset((volatile int *)off_126430, 0, 8u);
  v6 = (void *)(uintptr_t)(off_12643C);
  v7 = (void *)(uintptr_t)(off_126440);
  *v4 = 1;
  *v1 = 1;
  *v5 = 0;
  *v6 = 0;
  *v7 = 0;
LABEL_7:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_126444 = 1;
  }
  v8 = (void *)(uintptr_t)(off_126448);
  v9 = (volatile unsigned int *)off_12644C;
  v10 = *(volatile uint32_t *)off_126448;
  result = *(volatile uint32_t *)off_126448 + 1;
  v12 = *(volatile uint32_t *)off_12644C & 0xFFFFFBFF;
  *(volatile uint32_t *)off_126448 = result;
  *v9 = v12;
  if ( result )
  {
    v13 = (volatile int *)off_126444;
    *v8 = v10;
    v14 = *v13;
    if ( !v10 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}


// rf_flag_is_set @ 0x12645c
int rf_flag_is_set() {
  int result; // r0

  result = *(volatile uint8_t *)off_126468;
  if ( *(volatile uint8_t *)off_126468 )
    return 1;
  return result;
}



// rf_set_flag @ 0x12646c
int rf_set_flag(char a1) {
  *(volatile uint8_t *)off_126478 = a1;
  return dispatch_event_handler_1("cob state -> %d\n", a1);
}


// mmio_write_register @ 0x1264dc
int mmio_write_register(int a1) {
  volatile uint32_t *v1; // r3
  volatile int *v2; // r4
  int v3; // r1
  int v4; // r2
  int result; // r0
  int v6; // nf
  volatile uint32_t *v7; // r2

  *(volatile uint32_t *)off_126524 = a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_126528 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12652C);
  v2 = (volatile int *)off_126530;
  v3 = *(volatile uint32_t *)off_12652C;
  v4 = *(volatile uint32_t *)off_126530;
  result = *(volatile uint32_t *)off_12652C + 1;
  v6 = (*(volatile uint32_t *)off_126530 & 0x400) != 0;
  *(volatile uint32_t *)off_12652C = result;
  if ( !v6 )
  {
    *(volatile uint32_t *)off_126534 = 1024;
    *v2 = v4 | 0x400;
  }
  if ( result )
  {
    v7 = (void *)(uintptr_t)(off_126528);
    *v1 = v3;
    if ( !v3 )
    {
      if ( *v7 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_set_control @ 0x126538
int mmio_set_control() {
  volatile uint32_t *v0; // r2
  volatile unsigned int *v1; // r4
  int v2; // r1
  int result; // r0
  unsigned int v4; // r3
  volatile int *v5; // r3
  int v6; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_126578 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12657C);
  v1 = (volatile unsigned int *)off_126580;
  v2 = *(volatile uint32_t *)off_12657C;
  result = *(volatile uint32_t *)off_12657C + 1;
  v4 = *(volatile uint32_t *)off_126580 & 0xFFFFFBFF;
  *(volatile uint32_t *)off_12657C = result;
  *v1 = v4;
  if ( result )
  {
    v5 = (volatile int *)off_126578;
    *v0 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_126584 = 1024;
  return result;
}



// rf_state_machine @ 0x126588
int rf_state_machine() {
  int v0; // r3
  volatile uint8_t *v1; // r5
  volatile uint8_t *v2; // r6
  volatile char *v3; // r4
  int v4; // r7
  volatile char *v5; // r3
  int v6; // r7
  int v7; // r10
  float v8; // r3
  unsigned int v9; // r9
  uint64_t v10; // r0
  uint64_t v11; // r0
  unsigned int v12; // r2
  uint64_t v13; // r8
  uint64_t v14; // r0
  uint64_t v15; // r2
  uint64_t v16; // r0
  uint64_t v17; // r8
  volatile char *v18; // r4
  char v19; // r0
  int v20; // r2
  int v21; // r3
  volatile unsigned int *v22; // r1
  volatile uint32_t *v23; // r2
  volatile unsigned int v24; // r3
  volatile uint8_t *v25; // r4
  int v26; // r6
  uint64_t v27; // r0
  unsigned int v28; // r2
  uint64_t v29; // r6
  uint64_t v30; // r0
  uint64_t v31; // r0
  unsigned int v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  uint64_t v36; // r8
  uint64_t v37; // r0
  uint64_t v38; // r0
  volatile uint32_t *v39; // r3

  v0 = *(volatile uint8_t *)off_12672C;
  v1 = (void *)(uintptr_t)(off_126734);
  *(volatile uint16_t *)off_126730 = 0;
  if ( v0 )
  {
    if ( *v1 == 2 )
    {
      v25 = (void *)(uintptr_t)(off_12673C);
      v26 = *(volatile uint16_t *)off_12673C;
      if ( *(volatile uint16_t *)off_12673C )
      {
        v27 = aeabi_i2d(*(volatile uint32_t *)off_126758);
        v28 = v27;
        v27 = (v27 & ~0xFFFFFFFFull) | ((uint32_t)(v26) & 0xFFFFFFFFu);
        v29 = __PAIR64__(HIDWORD(v27), v28);
        v30 = aeabi_i2d(v27);
        v31 = ((uint64_t (*)())aeabi_dsub)(v29, v30);
        v32 = ((int (*)(uint64_t))aeabi_dmul)(v31);
        v33 = ((uint64_t (*)())aeabi_d2f)(v32);
      }
      else
      {
        v33 = 0;
      }
      v34 = parse_data_field(v33);
      v25[5] = ((int (*)(uint64_t))double_to_float_1)(v34);
      *v1 = 3;
      dispatch_event_handler_1("cob state -> %d\n", 3);
      return set_busy_flag_alt(0x2000);
    }
    else
    {
      return ll_state_reset();
    }
  }
  else if ( *v1 )
  {
    v2 = (volatile uint8_t *)off_126738;
    v3 = (volatile char *)off_12673C;
    v4 = *(volatile uint8_t *)off_126738 - 1;
    v5 = (volatile char *)off_12673C + 8 * v4;
    v6 = 8 * v4;
    v7 = (uint8_t)v5[2];
    if ( v5[2] )
    {
      v36 = aeabi_i2d(*(volatile uint32_t *)off_126758);
      v37 = aeabi_i2d(v7);
      v38 = ((uint64_t (*)())aeabi_dsub)(v36, v37);
      v9 = ((int (*)(uint64_t))aeabi_dmul)(v38);
      v8 = *(volatile float *)off_126740 / (float)v7;
      *(volatile float *)off_126740 = v8;
    }
    else
    {
      v8 = *(volatile float *)off_126740;
      v9 = 0;
    }
    v10 = ((uint64_t (*)())aeabi_d2f)(COERCE_UNSIGNED_INT(v8));
    v11 = parse_data_field(v10);
    v12 = v11;
    v11 = (v11 & ~0xFFFFFFFFull) | ((uint32_t)(v9) & 0xFFFFFFFFu);
    v13 = __PAIR64__(HIDWORD(v11), v12);
    v14 = ((uint64_t (*)())aeabi_d2f)(v11);
    v15 = parse_data_field(v14);
    v16 = v13;
    v17 = v15;
    v18 = &v3[v6];
    v18[4] = ((int (*)(uint64_t))double_to_float_1)(v16);
    v19 = ((int (*)(uint64_t))double_to_float_1)(v17);
    v20 = (uint8_t)*v2;
    v21 = *(volatile uint8_t *)off_126744;
    v18[3] = v19;
    if ( v20 == v21 )
    {
      *v1 = 4;
      dispatch_event_handler_1("cob state -> %d\n", 4);
    }
    else
    {
      *v1 = 2;
      dispatch_event_handler_1("cob state -> %d\n", 2);
      v22 = (volatile unsigned int *)off_126750;
      v23 = (void *)(uintptr_t)(off_126754);
      ++*v2;
      v24 = REG_4032_0120;
      *v22 = v24;
      *v23 = v24 + 1000000;
    }
    return set_busy_flag_alt(0x2000);
  }
  else
  {
    dispatch_event_handler_1(aCobGoldenStart);
    *v1 = 1;
    dispatch_event_handler_1("cob state -> %d\n", 1);
    v39 = (void *)(uintptr_t)(off_126760);
    *(volatile uint32_t *)off_126760 |= 0x100u;
    *v39 |= 0x200u;
    *v39 |= 0x400u;
    return set_busy_flag_alt(0x2000);
  }
}


// rf_config_load @ 0x126764
volatile uint32_t * rf_config_load(int a1) {
  int v2; // r1
  int v3; // r2
  int v4; // r3
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  volatile uint32_t *v11; // r0
  int v12; // r4
  volatile uint32_t *v13; // r1
  volatile uint32_t *v14; // r4
  volatile uint32_t *v15; // r3
  int v17; // r2
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r1
  volatile uint32_t *v20; // r4
  union {
    uint64_t _rf_align;
    uint32_t _rf_words[16];
    struct __attribute__((packed)) {
      char _rf_pad0[8];   // sp+0x00..sp+0x07: raw scratch before result
      uint64_t result;    // sp+0x08
      int v23;            // sp+0x10
      int v24;            // sp+0x14
      int v25;            // sp+0x18
      int v26;            // sp+0x1c
      int v27;            // sp+0x20
      int v28;            // sp+0x24
      int v29;            // sp+0x28
      int v30;            // sp+0x2c
      int v31;            // sp+0x30
      int v32;            // sp+0x34
      int v33;            // sp+0x38
      int v34;            // sp+0x3c
    } f;
  } _frame;
  v2 = ((volatile uint32_t *)(uintptr_t)off_126848)[1];
  v3 = ((volatile uint32_t *)(uintptr_t)off_126848)[2];
  v4 = ((volatile uint32_t *)(uintptr_t)off_126848)[3];
  _frame.f.v23 = ((volatile uint32_t *)(uintptr_t)off_126848)[0];
  _frame.f.v24 = v2;
  _frame.f.v25 = v3;
  _frame.f.v26 = v4;
  v5 = ((volatile uint32_t *)(uintptr_t)off_126848)[5];
  v6 = ((volatile uint32_t *)(uintptr_t)off_126848)[6];
  v7 = ((volatile uint32_t *)(uintptr_t)off_126848)[7];
  _frame.f.v27 = ((volatile uint32_t *)(uintptr_t)off_126848)[4];
  _frame.f.v28 = v5;
  _frame.f.v29 = v6;
  _frame.f.v30 = v7;
  v8 = ((volatile uint32_t *)(uintptr_t)off_126848)[9];
  v9 = ((volatile uint32_t *)(uintptr_t)off_126848)[10];
  v10 = ((volatile uint32_t *)(uintptr_t)off_126848)[11];
  _frame.f.v31 = ((volatile uint32_t *)(uintptr_t)off_126848)[8];
  _frame.f.v32 = v8;
  _frame.f.v33 = v9;
  _frame.f.v34 = v10;
  if ( !a1 )
  {
    v11 = (volatile uint32_t *)dispatch_event_handler_1(aNotchOff);
    v18 = (void *)(uintptr_t)(off_126858);
    *(volatile uint32_t *)off_126854 |= 0x80000000;
    *v18 |= 0x80000000;
    return v11;
  }
  if ( a1 > 3 )
    return (volatile uint32_t *)dispatch_event_handler_1("invalid func:%d\n", a1);
  mac_time_get(&_frame.f.result, 0);
  v12 = BYTE1(_frame.f.result);
  v11 = (volatile uint32_t *)dispatch_event_handler_1("notch%d on @%d,%d,%d\n", a1, WORD2(_frame.f.result), WORD1(_frame.f.result), BYTE1(_frame.f.result));
  if ( !v12 )
  {
    v19 = (void *)(uintptr_t)(off_126858);
    v20 = (void *)(uintptr_t)(off_12685C);
    v11 = (void *)(uintptr_t)(off_126860);
    *(volatile uint32_t *)off_126854 &= ~0x80000000;
    v15 = (void *)(uintptr_t)(off_126864);
    *v19 &= ~0x80000000;
    *v20 = _frame._rf_words[(0x10 + 8 * (a1 - 1)) / 4];
    v17 = _frame._rf_words[(0x14 + 8 * (a1 - 1)) / 4];
    goto LABEL_8;
  }
  if ( v12 == 1 )
  {
    v13 = (void *)(uintptr_t)(off_126858);
    v14 = (void *)(uintptr_t)(off_12685C);
    v11 = (void *)(uintptr_t)(off_126860);
    *(volatile uint32_t *)off_126854 &= ~0x80000000;
    v15 = (void *)(uintptr_t)(off_126864);
    *v13 &= ~0x80000000;
    *v14 = _frame._rf_words[(0x20 + 8 * a1) / 4];
    v17 = _frame._rf_words[(0x24 + 8 * a1) / 4];
LABEL_8:
    *v11 = v17;
    *v15 |= 2u;
    *v15 |= 1u;
  }
  return v11;
}


// tx_descriptor_config @ 0x12686c
int tx_descriptor_config(int result) {
  volatile uint16_t *v1; // r7
  volatile int *v2; // r1
  int v3; // r12
  int v4; // r6
  int v5; // r5
  volatile int *v6; // r4
  int v7; // r2
  unsigned int v8; // r3
  unsigned int v9; // t1
  unsigned int v10; // r2
  int v11; // r2

  v1 = (volatile uint16_t *)off_1268D8;
  if ( !*((volatile uint8_t *)off_1268D8 + 36) )
  {
    v2 = (volatile int *)off_1268DC;
    v3 = dword_1268E8;
    v4 = dword_1268E0;
    v5 = dword_1268E4;
    v6 = (volatile int *)((volatile char *)off_1268DC + 128);
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = v2[1];
        ++v2;
        v8 = v9;
        v10 = v9 >> 8;
        if ( ((v9 >> 8) & 0xC) != 0 )
          break;
LABEL_7:
        if ( v6 == v2 )
          return rf_ctrl_set(0, v1[20]);
      }
      v11 = v10 & 0xF;
      if ( result )
      {
        if ( v11 == 4 )
        {
          v7 = 0x1000000;
        }
        else if ( v11 == 7 )
        {
          v7 = 0;
        }
        else
        {
          v7 = (15 - v11) << 24;
        }
        *v2 = v8 & v5 | v7;
        goto LABEL_7;
      }
      *v2 = v8 & v3 | v4;
      if ( v6 == v2 )
        return rf_ctrl_set(0, v1[20]);
    }
  }
  return result;
}


// init_with_stack @ 0x1268ec
volatile unsigned int * init_with_stack(int a1) {
  volatile unsigned int *v2; // r0
  int v3; // r6
  unsigned int v4; // r5
  volatile uint32_t *v5; // r1
  volatile uint32_t *v6; // r2
  volatile uint32_t *v7; // r2
  volatile int *v8; // r3
  int v9; // r2
  volatile uint32_t *v10; // r3
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r5
  volatile uint32_t *v13; // r4
  volatile uint32_t *v14; // r1
  volatile uint32_t *v15; // r1
  volatile int *v16; // r3
  int v17; // r2
  volatile unsigned int *v18; // r4
  volatile uint32_t *v19; // r2
  int v20; // r2
  volatile uint32_t *v21; // r8
  unsigned int v22; // r6
  unsigned int v23; // r7
  int v24; // r5
  unsigned int v25; // r4
  volatile uint32_t *v26; // r0
  volatile unsigned int *v27; // r3
  int v28; // r2
  volatile uint32_t *v29; // r2
  volatile uint32_t *v30; // r5
  volatile int *v31; // r3
  int v32; // r2
  unsigned int v33; // r4
  volatile int *v34; // r1
  volatile int *v35; // r5
  int v36; // r6
  unsigned int v37; // r4
  int v38; // r2
  volatile uint32_t *v39; // r2
  volatile int *v40; // r3
  int v41; // r2
  volatile uint32_t *v42; // r1
  volatile int *v43; // r3
  volatile unsigned int *v44; // r0
  int v45; // r4
  int v46; // r2
  volatile uint32_t *v47; // r2
  int v48; // r2
  volatile int *v49; // r3
  int v50; // r2
  uint64_t result; // [sp+8h] [bp-8h] BYREF

  if ( a1 )
  {
    if ( a1 != 1 )
    {
      if ( (unsigned int)(a1 - 2) > 1 )
        return (volatile unsigned int *)dispatch_event_handler_1("invalid func:%d\n", a1);
      mac_time_get(&result, 0);
      v3 = BYTE1(result);
      v4 = WORD1(result);
      dispatch_event_handler_1("srrc%d on @%d,%d,%d\n", a1, WORD2(result), WORD1(result), BYTE1(result));
      v2 = (volatile unsigned int *)off_126BD0;
      v5 = (void *)(uintptr_t)(off_126BD4);
      v6 = (volatile uint32_t *)off_126BD8;
      *(volatile uint32_t *)off_126BD0 = *(volatile uint32_t *)off_126BCC & 0xFFFFBFFF;
      *v5 |= 0x80000000;
      *v6 |= 0x8000u;
      if ( a1 == 3 )
      {
        v6[80] |= 0x1000u;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v42 = (void *)(uintptr_t)(off_126D3C);
            v43 = (volatile int *)off_126D40;
            v44 = (volatile unsigned int *)off_126D44;
            v45 = dword_126D48;
            v46 = dword_126D4C;
            *(volatile uint32_t *)off_126D3C = dword_126D48;
            *v43 = v46;
            v47 = (void *)(uintptr_t)(off_126D24);
            *v44 = *v44 & 0xFFFFFF00 | 1;
            *v44 = *v44 & 0xFFFF00FF | 0x7F00;
            *(volatile uint32_t *)(v45 + 1174608113) = *(volatile uint32_t *)(v45 + 1174608113) & 0xC000FFFF | 0x1490000;
            v42[5] = v42[5] & 0xFFFFF0FF | 0x100;
            v2 = v44 - 146;
            *v47 &= ~0x80000000;
            *v2 &= ~0x80000000;
            if ( v4 == 2412 )
            {
              v49 = (volatile int *)off_126D30;
              v2 = (volatile unsigned int *)dword_126D58;
              v50 = dword_126D5C;
              *(volatile uint32_t *)off_126D2C = dword_126D58;
              *v49 = v50;
            }
            else if ( v4 == 2472 )
            {
              v2 = (volatile unsigned int *)dword_126D50;
              v48 = dword_126D54;
              *(volatile uint32_t *)off_126D2C = dword_126D50;
              REG_4034_2088 = v48;
            }
          }
          else
          {
            v39 = (void *)(uintptr_t)(off_126D28);
            *(volatile uint32_t *)off_126D24 &= ~0x80000000;
            *v39 &= ~0x80000000;
          }
        }
        else
        {
          v15 = v5 - 101;
          v16 = (volatile int *)off_126C04;
          v17 = dword_126C0C;
          *v15 = dword_126C08;
          *v16 = v17;
          v18 = (volatile unsigned int *)off_126C10;
          v19 = (void *)(uintptr_t)(off_126BDC);
          v2[21] = v2[21] & 0xFFFFFF00 | 1;
          v2[21] = v2[21] & 0xFFFF00FF | 0x7F00;
          *v18 = *v18 & 0xC000FFFF | 0x390000;
          v15[5] = v15[5] & 0xFFFFF0FF | 0x100;
          v2 -= 125;
          *v19 &= ~0x80000000;
          *v2 &= ~0x80000000;
          if ( v4 == 2412 )
          {
            v40 = (volatile int *)off_126D30;
            v2 = (volatile unsigned int *)dword_126D34;
            v41 = dword_126D38;
            *(volatile uint32_t *)off_126D2C = dword_126D34;
            *v40 = v41;
          }
          else if ( v4 == 2472 )
          {
            v2 = (volatile unsigned int *)dword_126C14;
            v20 = dword_126C18;
            *(volatile uint32_t *)off_126BE4 = dword_126C14;
            REG_4034_2088 = v20;
          }
        }
      }
      else
      {
        v7 = (void *)(uintptr_t)(off_126BE0);
        *(volatile uint32_t *)off_126BDC &= ~0x80000000;
        *v7 &= ~0x80000000;
        if ( v3 )
        {
          if ( v3 == 1 )
          {
            v31 = (volatile int *)off_126BE8;
            v2 = (volatile unsigned int *)dword_126C38;
            v32 = dword_126C3C;
            *(volatile uint32_t *)off_126BE4 = dword_126C38;
            *v31 = v32;
          }
        }
        else
        {
          v8 = (volatile int *)off_126BE8;
          v2 = (volatile unsigned int *)dword_126BEC;
          v9 = dword_126BF0;
          *(volatile uint32_t *)off_126BE4 = dword_126BEC;
          *v8 = v9;
        }
      }
      v10 = (volatile uint32_t *)off_126BF4;
LABEL_10:
      *v10 |= 2u;
      *v10 |= 1u;
      return v2;
    }
    v21 = (void *)(uintptr_t)(off_126C40);
    v22 = (*(volatile uint32_t *)off_126C1C >> 11) & 7;
    v23 = *(volatile uint32_t *)off_126C1C & 0x7F;
    v24 = (*(volatile uint32_t *)off_126C1C >> 7) & 3;
    mac_validate_rate(v22, v23, v24);
    if ( !*v21 )
    {
      mac_time_get(&result, 0);
      v33 = WORD1(result);
      v2 = (volatile unsigned int *)dispatch_event_handler_1("srrc on @%d,%d,%d\n", WORD2(result), WORD1(result), BYTE1(result));
      if ( v33 == 2412 )
      {
        v34 = (volatile int *)off_126D28;
        v35 = (volatile int *)off_126D2C;
        v2 = (volatile unsigned int *)off_126D30;
        v36 = dword_126D34;
        v37 = dword_126D38;
        *(volatile uint32_t *)off_126D24 &= ~0x80000000;
        v38 = *v34;
      }
      else
      {
        if ( v33 != 2472 )
          return v2;
        v34 = (volatile int *)off_126BE0;
        v35 = (volatile int *)off_126BE4;
        v2 = (volatile unsigned int *)off_126BE8;
        v36 = dword_126C14;
        v37 = dword_126C18;
        *(volatile uint32_t *)off_126BDC &= ~0x80000000;
        v38 = *v34;
      }
      v10 = (volatile uint32_t *)off_126BF4;
      *v34 = v38 & 0x7FFFFFFF;
      *v35 = v36;
      *v2 = v37;
      goto LABEL_10;
    }
    dispatch_event_handler_1("srrc on @%d,%d,%d\n", v22, v23, v24);
    v2 = (volatile unsigned int *)tx_descriptor_config(a1);
    if ( !*(volatile uint8_t *)off_126C24 && *(volatile uint32_t *)off_126C28 )
    {
      v25 = off_126BD8;
      v26 = (void *)(uintptr_t)(off_126BFC);
      v27 = (volatile unsigned int *)off_126C2C;
      v28 = dword_126C30;
      *(volatile uint32_t *)off_126BD8 |= 0x4000u;
      *v26 |= 0x10000u;
      *v27 = v28 & ((*v21 - 1) << 16) | *v27 & 0x8000FFFF;
      *v27 |= 0x60u;
      *v27 |= 1u;
      v2 = (void *)(v26 + 2071);
      *(volatile uint32_t *)(v25 + 0x13C) = *(volatile uint32_t *)(v25 + 0x13C) & 0xFFFFFF | 0xA0000000;
      *v2 = *v2 & 0xFF87FFFF | 0x700000;
    }
  }
  else
  {
    v2 = (volatile unsigned int *)dispatch_event_handler_1(aSrrcOff);
    v11 = (void *)(uintptr_t)(off_126BFC);
    if ( (*(volatile uint32_t *)off_126BFC & 0x10000) != 0 )
    {
      v29 = (void *)(uintptr_t)(off_126C2C);
      v30 = (void *)(uintptr_t)(off_126C34);
      *(volatile uint32_t *)off_126BD8 &= ~0x4000u;
      *v11 &= ~0x10000u;
      *v29 &= ~1u;
      *v29 &= 0xFFFFFF9F;
      *v30 &= 0xFF87FFFF;
      v2 = (volatile unsigned int *)tx_descriptor_config(0);
    }
    if ( *(volatile int *)off_126BDC >= 0 )
    {
      v12 = (void *)(uintptr_t)(off_126BE0);
      v13 = (void *)(uintptr_t)(off_126BD4);
      v2 = (volatile unsigned int *)off_126BD8;
      v14 = (void *)(uintptr_t)(off_126C00);
      *(volatile uint32_t *)off_126BDC |= 0x80000000;
      *v12 |= 0x80000000;
      *v13 &= ~0x80000000;
      *v2 &= ~0x8000u;
      *v14 &= ~0x1000u;
    }
  }
  return v2;
}


// mmio_bit_set @ 0x126d60
int mmio_bit_set(int a1) {
  int v1; // r1
  volatile unsigned int *v2; // r2
  int v3; // r3
  const volatile char *v4; // r0
  unsigned int v5; // r3

  v1 = off_126D94;
  v2 = (volatile unsigned int *)off_126D98;
  v3 = *(volatile uint32_t *)off_126D94;
  if ( a1 )
  {
    *(volatile uint32_t *)off_126D94 = v3 | 0x10000;
    v4 = aFssOn;
    v5 = *v2 & 0xFF87FFFF | 0x700000;
  }
  else
  {
    *(volatile uint32_t *)off_126D94 = v3 & 0xFFFEFFFF;
    v4 = aFssOff;
    v5 = *v2 & 0xFF87FFFF;
  }
  *v2 = v5;
  return dispatch_event_handler_1(v4, v1, v2, v5);
}


// rx_index_update @ 0x126da4
unsigned int rx_index_update() {
  volatile uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (volatile uint8_t *)off_126DD0;
  result = *((volatile uint8_t *)off_126DD0 + 6);
  v2 = *((volatile uint8_t *)off_126DD0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((volatile uint8_t *)off_126DD0 + 6) = v3;
    set_xtal_ftune(v3);
    return dispatch_event_handler_1("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v0[5], v0[6]);
  }
  return result;
}


