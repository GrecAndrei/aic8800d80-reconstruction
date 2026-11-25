// str_skip_spaces @ 0x121be0
int str_skip_spaces(volatile uint8_t *a1, int a2) {
  int v2; // r4
  volatile uint8_t *v4; // r0
  int v5; // r2
  int v6; // t1
  int v7; // r3
  int v8; // r5
  int v9; // r6
  int v10; // t1
  volatile uint8_t *v12; // r2
  int v13; // r3
  int v14; // t1

  v2 = 0;
  while ( 1 )
  {
    do
    {
      do
      {
        v4 = a1;
        v6 = *a1++;
        v5 = v6;
      }
      while ( v6 == 32 );
    }
    while ( v5 == 9 );
    if ( !v5 )
    {
      *(volatile uint32_t *)(a2 + 4 * v2) = 0;
      return v2;
    }
    if ( v5 == 34 )
      break;
    *(volatile uint32_t *)(a2 + 4 * v2) = (int)(uintptr_t)(v4);
    v7 = *v4;
    v8 = v2 + 1;
    v9 = v2 + 1;
    if ( !*v4 )
      goto rf_mem_write_n_3d0;
    while ( v7 != 32 && v7 != 9 )
    {
      v10 = *++v4;
      v7 = v10;
      if ( !v10 )
        goto rf_mem_write_n_3d0;
    }
rf_bus_mark_n_unknown:
    if ( !*v4 )
      goto rf_mem_write_n_3d0;
    *v4 = 0;
    a1 = v4 + 1;
    v2 = v9;
    if ( v9 == 16 )
    {
      uart_tx_string((volatile uint8_t *)dword_121C68);
      return 16;
    }
  }
  v12 = v4 + 1;
  *(volatile uint32_t *)(a2 + 4 * v2) = (int)(uintptr_t)(v4 + 1);
  v13 = v4[1];
  v8 = v2 + 1;
  v9 = v2 + 1;
  if ( v4[1] )
  {
    while ( v13 != 34 )
    {
      v14 = *++v12;
      v13 = v14;
      if ( !v14 )
        goto rf_mem_write_n_3d0;
    }
    v4 = v12;
    goto rf_bus_mark_n_unknown;
  }
rf_mem_write_n_3d0:
  *(volatile uint32_t *)(a2 + 4 * v9) = 0;
  return v8;
}



// parse_dot_separated @ 0x121c6c
volatile uint32_t * parse_dot_separated(int a1, volatile uint32_t *a2, int a3) {
  int v5; // r0
  int v6; // r11
  int v7; // r9
  volatile uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  volatile uint32_t *v11; // r10

  v5 = (int)(uintptr_t)(strchr((void *)(uintptr_t)(a1), 46));
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = memset_ff(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
if ( !crc32((void *)(uintptr_t)(a1), (void *)(uintptr_t)(*v8), v6) ) break;
        v8 += 4;
        if ( a3 == v9 )
          goto rf_cmd_dispatch_1ccc;
      }
      if ( memset_ff(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
rf_cmd_dispatch_1ccc:
    if ( v7 == 1 )
      return a2;
  }
  return 0;
}



// co_list_insert @ 0x121cf4
int co_list_insert(unsigned int a1, volatile uint8_t *a2, int a3) {
  volatile int *v3; // r6
  char v4; // r4
  volatile int *v6; // r7
  volatile uint32_t *v7; // r3
  int v8; // r2
  volatile int *v9; // r8
  int result; // r0
  int v11; // r0
  volatile int *v12; // r2
  volatile uint32_t *v13; // r3
  volatile int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  volatile uint8_t *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  volatile uint8_t *v21; // r0
  volatile uint32_t *v22; // r3
  volatile uint8_t *v23; // r3
  int v24; // r2

  v3 = (volatile int *)off_121E24;
  v4 = a1;
  if ( *(volatile uint32_t *)off_121E24 )
  {
    if ( !a3 )
      goto LABEL_3;
LABEL_11:
    v11 = memset_ff(a3);
    v12 = (volatile int *)off_121E28;
    v13 = (void *)(uintptr_t)(off_121E30);
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(volatile uint32_t *)off_121E24 = (int)(uintptr_t)(a2);
  if ( a3 )
    goto LABEL_11;
LABEL_3:
  v6 = (volatile int *)off_121E28;
  v7 = (void *)(uintptr_t)(off_121E2C);
  v8 = *(volatile uint32_t *)off_121E28;
  *(volatile uint32_t *)off_121E2C = *(volatile uint32_t *)off_121E28;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto LABEL_19;
      case 0xAu:
      case 0xDu:
        v21 = (volatile uint8_t *)dword_121E34;
        *(volatile uint8_t *)*v3 = 0;
        uart_tx_string(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = (void *)(uintptr_t)(off_121E30);
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (volatile int *)off_121E30;
        v15 = *v3;
        if ( *(volatile uint32_t *)off_121E30 )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (volatile uint8_t *)tlv_find(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (volatile int *)off_121E30;
        if ( *(volatile int *)off_121E30 > 61 )
          goto LABEL_7;
        if ( a1 != 9 )
          goto LABEL_28;
        uart_tx_string((volatile uint8_t *)(dword_121E38 + (v8 & 7)));
        *(volatile uint32_t *)off_121E2C = (*(volatile uint32_t *)off_121E2C & 0xFFFFFFF8) + 8;
        break;
    }
    goto LABEL_27;
  }
  if ( a1 == 127 )
  {
LABEL_19:
    v20 = *v3;
    if ( *(volatile uint32_t *)off_121E30 )
      v20 = tlv_find((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (volatile int *)off_121E30;
    if ( *(volatile int *)off_121E30 <= 61 )
    {
LABEL_28:
      *v7 = v8 + 1;
      uart_tx_byte(a1);
LABEL_27:
      v23 = (volatile uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
LABEL_7:
    uart_tx_byte(7);
    return -1;
  }
}



// parse_number @ 0x121e3c
int parse_number(volatile uint8_t *a1, volatile uint32_t *a2, unsigned int a3) {
  int v3; // r5
  int v4; // r7
  int i; // r6
  unsigned int v6; // r3
  int v8; // t1
  int v9; // r3
  int v10; // r3

  v3 = *a1;
  if ( v3 == 48 )
  {
    v3 = a1[1];
    if ( (unsigned int)(v3 - 65) > 0x19 )
      v9 = a1[1];
    else
      v9 = (uint8_t)(v3 + 32);
    if ( v9 == 120 && ((v10 = a1[2], (unsigned int)(v10 - 48) <= 9) || (v10 & 0xFFFFFFDF) - 65 <= 5) )
    {
      a1 += 2;
      v3 = v10;
      a3 = 16;
    }
    else
    {
      ++a1;
      if ( !a3 )
      {
        a3 = 8;
        if ( v3 != 45 )
          goto LABEL_5;
rf_mem_write_n_168:
        v4 = 1;
        v3 = *++a1;
        goto LABEL_6;
      }
    }
  }
  else if ( !a3 )
  {
    a3 = 10;
  }
  if ( v3 == 45 )
    goto rf_mem_write_n_168;
LABEL_5:
  v4 = 0;
LABEL_6:
  for ( i = 0; ; i = v6 + i * a3 )
  {
    v6 = v3 - 48;
    if ( (uint8_t)(v3 - 48) > 9u )
    {
      if ( (v3 & 0xFFFFFFDF) - 65 > 5 )
        break;
      if ( (unsigned int)(v3 - 97) > 0x19 )
        v6 = v3 - 55;
      else
        v6 = (uint8_t)(v3 - 32) - 55;
    }
    if ( a3 <= v6 )
      break;
    v8 = *++a1;
    v3 = v8;
  }
  if ( v4 )
    i = -i;
  if ( a2 )
    *a2 = (int)(uintptr_t)(a1);
  return i;
}



// buffer_flush @ 0x121ee8
int buffer_flush() {
  unsigned int v0; // r4
  unsigned int v1; // r5
  const volatile char *v2; // r2

  v0 = off_121F08;
  v1 = off_121F08 + 880;
  do
  {
    v2 = *(const volatile char **)(v0 + 4);
    if ( v2 )
      log_printf("%s %s\r\n", *(const volatile char **)v0, v2);
    v0 += 16;
  }
  while ( v0 != v1 );
  return 0;
}


// str_has_extension @ 0x121f10
int str_has_extension(int a1) {
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = memset_ff(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(volatile uint8_t *)(v3 - 2) != 46 )
    return 4;
  v5 = *(volatile uint8_t *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}



// parse_hex_value @ 0x121f44
int parse_hex_value(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int a2a; // [sp+4h] [bp-4h]

  v4 = parse_number((volatile uint8_t *)a2[1], nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = str_has_extension(*a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    log_printf("Unknown data size:%d\r\n", v5);
    return -1;
  }
  a2a = parse_number((volatile uint8_t *)a2[2], nullptr, 0);
  v5 = str_has_extension(*a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( a2a == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = call_indirect_table();
      log_printf("[0x%08X] = 0x%08X\r\n", v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      log_printf("[0x%08lX] = 0x%08lX\r\n", v4, *(volatile uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      log_printf("[0x%08lX] = 0x%04X\r\n", v4, *(volatile uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        log_printf("[0x%08lX] = 0x%02X\r\n", v4, *(volatile uint8_t *)v4);
      return 0;
    }
  }
  v7 = *(volatile uint8_t *)*a2 == 82 && v4 < 0x40000000;
  handle_ipc_request(v4, a2a, (uint8_t)v5, v7);
  return 0;
}


// parse_mac_addr @ 0x12202c
int parse_mac_addr(int a1, volatile uint32_t *a2) {
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r4
  int v10; // r0

  v4 = str_has_extension(*a2);
  if ( v4 < 0 )
  {
    log_printf("Unknown data size:%d\r\n", v4);
    return -1;
  }
  else
  {
    v5 = parse_number((volatile uint8_t *)a2[1], nullptr, 0x10u);
    v6 = parse_number((volatile uint8_t *)a2[2], nullptr, 0x10u);
    if ( a1 <= 3 )
    {
      v7 = 0;
      goto LABEL_9;
    }
    v10 = parse_number((volatile uint8_t *)a2[3], nullptr, 0);
    if ( v10 )
    {
      v7 = v10 - 1;
      do
      {
LABEL_9:
        while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
        {
          v8 = v5 & 0xFFFFFFFC;
          log_printf("[0x%08X] = 0x%08lX\r\n", v8, v6);
          --v7;
          call_slot_0x1b4();
          v5 = v8 + v4;
          if ( v7 == -1 )
            return 0;
        }
        switch ( v4 )
        {
          case 4:
            log_printf("[0x%08lX] = 0x%08lX\r\n", v5, v6);
            *(volatile uint32_t *)v5 = v6;
            break;
          case 2:
            log_printf("[0x%08lX] = 0x%04X\r\n", v5, (uint16_t)v6);
            *(volatile uint16_t *)v5 = v6;
            break;
          case 1:
            log_printf("[0x%08lX] = 0x%02X\r\n", v5, (uint8_t)v6);
            *(volatile uint8_t *)v5 = v6;
            break;
        }
        --v7;
        v5 += v4;
      }
      while ( v7 != -1 );
    }
    return 0;
  }
}


// parse_len_value @ 0x12211c
int parse_len_value(int a1, int a2) {
  int v3; // r5
  void ( *v4)(int); // r4
  int v5; // r0
  volatile uint32_t *v6; // r3

  if ( a1 <= 2 )
  {
    v4 = (void ( *)(int))parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0x10u);
    dispatch_event_handler_1("Goto %p\r\n", v4);
    goto LABEL_5;
  }
  v3 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
  v4 = (void ( *)(int))parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
  dispatch_event_handler_1("Goto %p\r\n", v4);
  if ( v3 == 1 )
LABEL_5:
    v4 = *((void ( **)(int))v4 + 1);
  v5 = dispatch_event_handler_1("PC=%p\r\n", v4);
  v6 = (void *)(uintptr_t)(off_122194);
  *((volatile uint32_t *)off_122190 + 65) = 8;
  v6[2] &= ~0x20000u;
  v6[2] |= 0x40000u;
  v4(v5);
  return 0;
}


// parse_decimal_value @ 0x122198
int parse_decimal_value(int a1, int a2) {
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(volatile uint16_t **)off_12222C = v6;
      dispatch_event_handler_1("cfg dbg_msk: 0x%x\n", v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        dispatch_event_handler_1(aInvalidArgs);
        return 0;
      }
      v8 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      dispatch_event_handler_1("cfg dbg mod: %08X\n", v8);
      set_global_ptr(v8);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("invalid func: %d\n", v4);
      return 0;
    }
  }
  else
  {
    dispatch_event_handler_1("cur dbg_msk: 0x%x\n", **(volatile uint16_t **)off_12222C);
    v7 = get_event_flags();
    dispatch_event_handler_1("dbg mod: %08X\n", v7);
    return 0;
  }
}


// rf_set_frequency_1 @ 0x122244
int rf_set_frequency_1() {
  float v0; // r0
  float v1; // r0
  float v2; // r0
  float v3; // r0
  float v4; // r0

  v0 = sdio_core_config_1();
  dispatch_event_handler_1("AVDD18 : %d mV\n", (unsigned int)v0);
  v1 = sdio_core_config_2();
  dispatch_event_handler_1("AVDD13 : %d mV\n", (unsigned int)v1);
  v2 = sdio_core_config_0();
  dispatch_event_handler_1("VBAT   : %d mV\n", (unsigned int)v2);
  v3 = sdio_core_config_3();
  dispatch_event_handler_1("VRTC0  : %d mV\n", (unsigned int)v3);
  v4 = sdio_core_init();
  dispatch_event_handler_1("VCORE  : %d mV\n", (unsigned int)v4);
  return 0;
}


// check_message_len @ 0x1222cc
int check_message_len(int a1, int a2) {
  int v3; // r6
  unsigned int v4; // r6
  uint16_t v5; // r0
  int v6; // r5
  uint16_t v7; // r7
  unsigned int v8; // r8
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r12
  volatile uint32_t *v12; // lr
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r9
  volatile uint32_t *v15; // lr
  volatile uint32_t *v16; // r0
  volatile uint32_t *v17; // r12
  volatile unsigned int *v18; // r1
  unsigned int v19; // r3
  volatile char *v20; // r0
  volatile int *v21; // r12
  int v22; // lr
  int v23; // r9
  struct __attribute__((packed)) { char a1a[4]; // [sp+8h] [bp-Ch] BYREF
  char v26; // [sp+Ch] [bp-8h]
  } _frame;
  if ( memset_ff(*(volatile uint32_t *)(a2 + 4)) != 12 || memset_ff(*(volatile uint32_t *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(volatile uint32_t *)(a2 + 4);
  memcpy(_frame.a1a, (volatile char *)(v3 + 8), 4u);
  *(volatile uint8_t *)(v3 + 8) = 0;
  _frame.v26 = 0;
  v4 = parse_number((volatile uint8_t *)v3, nullptr, 0x10u);
  v5 = parse_number((volatile uint8_t *)_frame.a1a, nullptr, 0x10u);
  v6 = *(volatile uint32_t *)(a2 + 8);
  v7 = v5;
  memcpy(_frame.a1a, (volatile char *)(v6 + 8), 4u);
  *(volatile uint8_t *)(v6 + 8) = 0;
  _frame.v26 = 0;
  v8 = parse_number((volatile uint8_t *)v6, nullptr, 0x10u);
  v6 = (v6 & ~0xFFFFu) | ((uint16_t)(parse_number((volatile uint8_t *)_frame.a1a, nullptr, 0x10u)) & 0xFFFFu);
  dispatch_event_handler_1(aSetMonitor);
  v9 = (void *)(uintptr_t)(off_122440);
  v10 = (void *)(uintptr_t)(off_122444);
  v11 = (void *)(uintptr_t)(off_12246C);
  v12 = (void *)(uintptr_t)(off_122470);
  v13 = (void *)(uintptr_t)(off_122448);
  *(volatile uint32_t *)off_12243C = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_12244C;
  v14 = (void *)(uintptr_t)(off_122474);
  v15 = (void *)(uintptr_t)(off_122478);
  v16 = (void *)(uintptr_t)(off_122454);
  v13[37597] = dword_122450;
  v17 = (void *)(uintptr_t)(off_12247C);
  v18 = (volatile unsigned int *)off_122458;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(volatile uint32_t *)off_12245C = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (volatile char *)off_122460;
  *(volatile uint32_t *)off_122460 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (volatile int *)off_122480;
  v22 = dword_122484;
  v23 = dword_122488;
  *(volatile uint32_t *)off_122464 = __rev16((uint16_t)v6);
  *(volatile uint32_t *)&v20[-148] = 7;
  *(volatile uint32_t *)&v20[-148] = v23;
  *v21 = v22;
  dispatch_event_handler_1("set mon: mac=%08x%04x, bssid=%08x%04x\n", v4, v7, v8, (uint16_t)v6);
  return 0;
}


// process_items @ 0x12248c
int process_items(int a1, int a2) {
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = get_event_handler();
    dispatch_event_handler_1("dbg sev: %d\n", v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      dispatch_event_handler_1(aInvalidArgs);
    }
    else
    {
      v7 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        dispatch_event_handler_1("invalid sev_idx:%d\n", v7);
      }
      else
      {
        dispatch_event_handler_1("Cfg dbg sev: %d\n", v7);
        set_global_variable(v7);
      }
    }
    return 0;
  }
  dispatch_event_handler_1(aInvalidFunc);
  return 0;
}


// copy_packet_data @ 0x122508
int copy_packet_data(int a1, int a2) {
  int result; // r0
  int v5; // r6
  int v6; // r7
  int v7; // r4
  const volatile char *v8; // r8
  volatile float *v9; // r5
  int v10; // r4
  float v11; // s15
  struct __attribute__((packed)) { float v12; // [sp+0h] [bp-200h] BYREF
  char v13; // [sp+4h] [bp-1FCh] BYREF
  } _frame;
  result = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
  v5 = result;
  if ( a1 == 2 )
  {
    if ( result )
      return result;
    sdio_core_reset((unsigned int)&_frame.v12, 64);
    dispatch_event_handler_1("Temp[0 ~ %d]:\n", 63);
    v6 = 64;
    goto LABEL_10;
  }
  result = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
  v6 = result;
  v7 = result;
  if ( result >= 128 )
    v6 = 128;
  if ( !v5 )
  {
    sdio_core_reset((unsigned int)&_frame.v12, v6);
    result = dispatch_event_handler_1("Temp[0 ~ %d]:\n", v6 - 1);
    if ( v7 > 0 )
    {
LABEL_10:
      v8 = (const volatile char *)off_1225C0;
      dispatch_event_handler_1(" %3d", (int)_frame.v12);
      v9 = (volatile float *)&_frame.v13;
      v10 = 0;
      while ( 1 )
      {
        ++v10;
        result = (int)a3d;
        if ( v10 == v6 )
          break;
        v11 = *v9++;
        dispatch_event_handler_1(" %3d", (int)v11);
        if ( (v10 & 7) == 7 )
          dispatch_event_handler_1(v8);
      }
    }
  }
  return result;
}


// call_copy_packet_data @ 0x1225c4
int call_copy_packet_data(int a1) {
  int v1; // r1
  float v3; // r0

  if ( a1 <= 1 )
  {
    v3 = COERCE_FLOAT(gpio_port_init());
    dispatch_event_handler_1("Temp      : %d C\n", (int)v3);
    rf_param_build();
  }
  else
  {
    copy_packet_data(a1, v1);
  }
  return 0;
}


// parse_records @ 0x1225f4
int parse_records(int a1, int a2) {
  int v4; // r0
  int v5; // r7
  int v6; // r6
  int v7; // r4
  unsigned int v9; // r0

  if ( a1 == 1 )
  {
    rf_param_build();
    return 0;
  }
  else
  {
    v4 = parse_number(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = off_122664;
      v9 = parse_number(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v9 > 0x7D0 )
        *(volatile uint32_t *)(v7 + 0x16C) = v9;
    }
    else
    {
      v7 = off_122664;
    }
    if ( *(volatile uint8_t *)(v7 + 0x16B) != v5 )
    {
      *(volatile uint8_t *)(v7 + 0x16B) = v5;
      if ( v6 )
      {
        rf_read_trim();
        rf_enable_2();
      }
      else
      {
        rf_disable_2();
      }
    }
    dispatch_event_handler_1("temp_comp en=%d, peroid_ms=%d\n", v5, *(volatile uint32_t *)(v7 + 0x16C));
    return 0;
  }
}


// get_elapsed_ticks @ 0x12266c
int get_elapsed_ticks(int a1) {
  int result; // r0

  result = *(volatile uint32_t *)off_122684 + 1000 * a1;
  while ( *(volatile uint32_t *)off_122684 - result < 0 )
    ;
  return result;
}



// check_system_flag @ 0x122688
int check_system_flag(int result, int a2) {
  int v2; // r4
  uint8_t v4[8]; // [sp+4h] [bp-8h] BYREF

  v2 = HIBYTE(*(volatile uint32_t *)off_122710) & 2;
  if ( result )
  {
    if ( result == 1 )
    {
      if ( (unsigned int)(a2 - 1) > 6 )
      {
        dispatch_event_handler_1("wrong ibit:%x\r\n", a2);
        return -12;
      }
      else if ( v2 )
      {
        return 0;
      }
      else
      {
        v4[0] = a2;
        *(volatile uint16_t *)&v4[1] = 0;
        v4[3] = 0;
        mmio_write_8((int)v4);
        dispatch_event_handler_1("set flash txgain 2.4g pa_drv_ibit=%x\n", a2);
        return a2;
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc, a2);
      return -21;
    }
  }
  else if ( !v2 )
  {
    *(volatile uint32_t *)v4 = 0;
    if ( mmio_read_8((int)v4) )
    {
      dispatch_event_handler_1(aUnset);
      return 0;
    }
    else
    {
      dispatch_event_handler_1("flash txgain 2.4g pa_drv_ibit=%x\n", v4[0]);
      return v4[0];
    }
  }
  return result;
}


// init_system @ 0x122728
int init_system(int a1, unsigned int a2, unsigned int a3, int a4) {
  int v4; // r4
  int v5; // r5
  volatile uint32_t *v6; // r6
  int v7; // r10
  volatile uint8_t *v8; // r8
  int v9; // r7
  int v10; // r4
  int v11; // r1
  volatile uint32_t *v12; // r6
  int k; // r8
  int v14; // r11
  volatile uint8_t *v15; // r7
  int v16; // r5
  int v17; // r4
  int v18; // r1
  int v23; // r0
  char v24; // r4
  int v25; // r0
  unsigned int v26; // r9
  unsigned int v27; // r1
  int v28; // r3
  int v29; // r10
  volatile int *v30; // r6
  volatile char *v31; // r7
  volatile uint8_t *v32; // r11
  int j; // r5
  char v34; // t1
  int v35; // r3
  int v36; // r3
  unsigned int v37; // r6
  unsigned int v38; // r3
  volatile uint8_t *v39; // r6
  int v40; // r1
  unsigned int v41; // r1
  int v42; // r3
  unsigned int v43; // r6
  int v44; // r3
  volatile uint8_t *v45; // r6
  int v46; // r1
  int v47; // r5
  volatile uint32_t *v48; // r6
  int v49; // r8
  volatile uint8_t *v50; // r11
  volatile char *v51; // r7
  volatile uint8_t *v52; // r9
  int i; // r5
  char v54; // t1
  int v55; // r3
  int v56; // r0
  char v57; // r4
  int v58; // r0
  unsigned int v59; // r9
  struct __attribute__((packed)) { union { int v60; // [sp+0h] [bp-2Ch]
  int v61; // [sp+0h] [bp-2Ch]
  int v62; // [sp+0h] [bp-2Ch]
  volatile uint32_t *v63; }; // [sp+0h] [bp-2Ch]
  volatile int *p_a3a; // [sp+4h] [bp-28h]
  uint32_t v65[3]; // [sp+8h] [bp-24h] BYREF
  int a3a; // [sp+14h] [bp-18h] BYREF
  int v67; // [sp+18h] [bp-14h]
  int v68; // [sp+1Ch] [bp-10h]
  int v69; // [sp+20h] [bp-Ch]
  int v70; // [sp+24h] [bp-8h]
  uint8_t v71[4]; // [sp+28h] [bp-4h] BYREF
  } _frame;
  v4 = HIBYTE(*(volatile uint32_t *)off_122A40) & 2;
  v5 = a1;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( a2 <= 2 && a3 <= 2 )
      {
        if ( (uint8_t)(a4 + 7) <= 0xEu )
        {
          if ( v4 )
          {
            v56 = tx_packet_prepare(a2, a3, a4);
            v57 = v56;
            if ( v56 < 0 )
            {
              dispatch_event_handler_1(aNoRoom);
              v59 = 2 * a2;
            }
            else
            {
              dispatch_event_handler_1("set ef_pwrofst2x_2.4g:\n  [%d][%d]=%d\n", a2, a3, a4);
              *(volatile uint8_t *)(*(volatile uint32_t *)off_122C60 + 3 * a2 + a3) = a4;
              v58 = tx_desc_build(a2, a3, (void *)(&_frame.a3a));
              v57 = v58;
              v59 = 2 * a2;
              if ( (char)_frame.a3a == a4 )
                mmio_reg_write_1b(v5);
              else
                dispatch_event_handler_1("failed to set, rd=%d(rem:%d)\n", (char)_frame.a3a, v58);
            }
            *(volatile uint8_t *)(dword_122C5C + a2 + v59 + a3) = v57;
          }
          else
          {
            _frame.a3a = 0;
            _frame.v67 = 0;
            _frame.v68 = 0;
            bus_read_12((int)&_frame.a3a);
            dispatch_event_handler_1("set fl_pwrofst2x_2.4g:\n  [%d][%d]=%d\n", a2, a3, a4);
            v37 = 3 * a2;
            v38 = *(volatile uint32_t *)off_122A50 + v37;
            v39 = &_frame.v71[v37 + a3];
            *(volatile uint8_t *)(v38 + a3) = a4;
            *(v39 - 20) = a4;
            mmio_write_2((int)&_frame.a3a);
            bus_read_12((int)&_frame.a3a);
            v40 = (char)*(v39 - 20);
            if ( v40 == a4 )
            {
              _frame.v65[0] = 0;
              mmio_write_128((int)_frame.v65);
            }
            else
            {
              dispatch_event_handler_1("failed to set, rd=%d\n", v40);
            }
          }
          v41 = *((volatile uint16_t *)off_122A74 + 20);
          if ( v41 <= 0x97B )
          {
            v42 = 0;
          }
          else if ( v41 > 0x994 )
          {
            v42 = 2;
          }
          else
          {
            v42 = 1;
          }
          if ( !*((volatile uint8_t *)off_122A74 + 36) && v42 == a3 )
          {
            rf_ctrl_set(*((volatile uint8_t *)off_122A74 + 36), v41);
            return 0;
          }
          return 0;
        }
LABEL_78:
        dispatch_event_handler_1(aWrongOfstVal);
        return -11;
      }
    }
    else
    {
      if ( a1 != 2 )
      {
        dispatch_event_handler_1(aWrongFunc_0);
        return -21;
      }
      if ( a2 <= 2 && a3 <= 5 )
      {
        if ( (uint8_t)(a4 + 7) <= 0xEu )
        {
          if ( v4 )
          {
            v23 = rx_packet_prepare(a2, a3, a4);
            v24 = v23;
            if ( v23 < 0 )
            {
              dispatch_event_handler_1(aNoRoom);
              v26 = 2 * a2;
            }
            else
            {
              dispatch_event_handler_1("set ef_pwrofst2x_5g:\n  [%d][%d]=%d\n", a2, a3, a4);
              *(volatile uint8_t *)(*(volatile uint32_t *)off_122A64 + 6 * a2 + a3) = a4;
              v25 = rx_desc_build(a2, a3, (void *)(&_frame.a3a));
              v24 = v25;
              v26 = 2 * a2;
              if ( (char)_frame.a3a == a4 )
                mmio_reg_write_1b(1);
              else
                dispatch_event_handler_1("failed to set, rd=%d(rem:%d)\n", (char)_frame.a3a, v25);
            }
            *(volatile uint8_t *)(dword_122A58 + 2 * (a2 + v26) + a3) = v24;
          }
          else
          {
            _frame.a3a = 0;
            _frame.v67 = 0;
            _frame.v68 = 0;
            _frame.v69 = 0;
            _frame.v70 = 0;
            mmio_read_4((int)&_frame.a3a);
            dispatch_event_handler_1("set fl_pwrofst2x_5g:\n  [%d][%d]=%d\n", a2, a3, a4);
            v43 = 3 * a2;
            v44 = *(volatile uint32_t *)off_122C50 + 2 * v43;
            v45 = &_frame.v71[2 * v43 + a3];
            *(volatile uint8_t *)(v44 + a3) = a4;
            *(v45 - 20) = a4;
            mmio_write_4((int)&_frame.a3a);
            mmio_read_4((int)&_frame.a3a);
            v46 = (char)*(v45 - 20);
            if ( v46 == a4 )
            {
              _frame.v65[0] = 0;
              mmio_write_128((int)_frame.v65);
            }
            else
            {
              dispatch_event_handler_1("failed to set, rd=%d\n", v46);
            }
          }
          v27 = *((volatile uint16_t *)off_122A74 + 20);
          if ( v27 > 0x1666 )
          {
            v28 = 5;
          }
          else if ( v27 > 0x1616 )
          {
            v28 = 4;
          }
          else if ( v27 > 0x15C6 )
          {
            v28 = 3;
          }
          else if ( v27 > 0x1571 )
          {
            v28 = 2;
          }
          else
          {
            v28 = v27 > 0x1486;
          }
          if ( *((volatile uint8_t *)off_122A74 + 36) == 1 && v28 == a3 )
            rf_ctrl_set(1, v27);
          return 0;
        }
        goto LABEL_78;
      }
    }
    dispatch_event_handler_1(aWrongTypeChgrp);
    return -12;
  }
  if ( !v4 )
  {
    memset((void *)(_frame.v65), 0, sizeof(_frame.v65));
    _frame.v67 = 0;
    _frame.v68 = 0;
    _frame.v69 = 0;
    _frame.v70 = 0;
    _frame.a3a = 0;
    dispatch_event_handler_1(aFlPwrofst2x24g, a2, a3, a4);
    if ( bus_read_12((int)_frame.v65) )
    {
      memset((volatile int *)dword_122A48, 0xFu, 9u);
      dispatch_event_handler_1(aEmpty);
    }
    else
    {
      v47 = dword_122C5C;
      v48 = (void *)(uintptr_t)(off_122C60);
      dispatch_event_handler_1(a011b1OfdmHighr);
      dispatch_event_handler_1(aChan14591013);
      v49 = 0;
      _frame.v63 = _frame.v65;
      v50 = (volatile uint8_t *)v47;
      do
      {
        dispatch_event_handler_1("\n  [%d] =", v49);
        v51 = (volatile char *)_frame.v63;
        v52 = v50;
        for ( i = 0; i != 3; ++i )
        {
          v54 = *v51++;
          *(volatile uint8_t *)(*v48 + i + 3 * v49) = v54;
          v55 = *v48 + i;
          *v52++ = 15;
          dispatch_event_handler_1("\t%d", *(volatile char *)(v55 + 3 * v49));
        }
        ++v49;
        _frame.v63 = (volatile uint32_t *)((volatile char *)_frame.v63 + 3);
        v50 += 3;
      }
      while ( v49 != 3 );
      dispatch_event_handler_1((const volatile char *)off_122C6C);
    }
    dispatch_event_handler_1(aFlPwrofst2x5g);
    v29 = mmio_read_4((int)&_frame.a3a);
    if ( v29 )
    {
      memset((volatile int *)dword_122C70, 0xFu, 0x12u);
      dispatch_event_handler_1(aEmpty);
    }
    else
    {
      _frame.v62 = dword_122A58;
      dispatch_event_handler_1(a0OfdmLowrate1O);
      v30 = (volatile int *)off_122A64;
      dispatch_event_handler_1(aChan3650516498);
      _frame.p_a3a = &_frame.a3a;
      do
      {
        dispatch_event_handler_1("\n  [%d] =", v29);
        v32 = (volatile uint8_t *)_frame.v62;
        v31 = (volatile char *)_frame.p_a3a;
        for ( j = 0; j != 6; ++j )
        {
          v34 = *v31++;
          *(volatile uint8_t *)(*v30 + j + v4) = v34;
          v35 = *v30;
          *v32++ = 15;
          v36 = v35 + j;
          dispatch_event_handler_1("\t%d", *(volatile char *)(v36 + v4));
        }
        _frame.p_a3a = (volatile int *)((volatile char *)_frame.p_a3a + 6);
        v4 += 6;
        ++v29;
        _frame.v62 += 6;
      }
      while ( v4 != 18 );
      dispatch_event_handler_1((const volatile char *)off_122A5C);
    }
    return 0;
  }
  _frame.v60 = dword_122A48;
  dispatch_event_handler_1(aEfPwrofst2x24g, a2, a3);
  v6 = (void *)(uintptr_t)(off_122A50);
  dispatch_event_handler_1(aChan14591013);
  do
  {
    v7 = tx_desc_init(v5, *v6 + 3 * v5);
    dispatch_event_handler_1("\n  [%d] =", v5);
    v8 = (volatile uint8_t *)_frame.v60;
    v9 = 0;
    do
    {
      v10 = (v7 >> (4 * v9)) & 0xF;
      v11 = *(volatile char *)(*v6 + v9++ + 3 * v5);
      dispatch_event_handler_1("\t%d(r%x)", v11, v10);
      *v8++ = v10;
    }
    while ( v9 != 3 );
    ++v5;
    _frame.v60 += 3;
  }
  while ( v5 != 3 );
  _frame.v61 = dword_122A58;
  dispatch_event_handler_1((const volatile char *)off_122A5C);
  v12 = (void *)(uintptr_t)(off_122A64);
  dispatch_event_handler_1("ef_pwrofst2x_5g: [0]:ofdm_lowrate, [1]:ofdm_highrate, [2]:ofdm_midrate");
  dispatch_event_handler_1(aChan3650516498);
  for ( k = 0; k != 3; ++k )
  {
    v14 = rx_desc_init(k, *v12 + 6 * k);
    dispatch_event_handler_1("\n  [%d] =", k);
    v15 = (volatile uint8_t *)_frame.v61;
    v16 = 0;
    do
    {
      v17 = (v14 >> (4 * v16)) & 0xF;
      v18 = *(volatile char *)(*v12 + v16++ + 6 * k);
      dispatch_event_handler_1("\t%d(r%x)", v18, v17);
      *v15++ = v17;
    }
    while ( v16 != 6 );
    _frame.v61 += 6;
  }
  dispatch_event_handler_1((const volatile char *)off_122A5C);
  return 0;
}


// check_radio_status @ 0x122c94
int check_radio_status(int a1, int a2, int a3) {
  int v3; // r3
  int v4; // r0
  int v7; // r5
  int v8; // r6
  int a1a; // [sp+Ch] [bp-4h] BYREF

  v3 = HIBYTE(*(volatile uint32_t *)off_122D94) & 2;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( (unsigned int)(a2 + 7) > 0xF )
      {
        dispatch_event_handler_1("wrong temp level:%d\n", a2);
        return -12;
      }
      else
      {
        v7 = 10 * a2;
        if ( v3 )
        {
          v8 = rf_reg10_low_check(a2);
          if ( v8 < 0 )
          {
            dispatch_event_handler_1(aNoRoom);
            return -11;
          }
          else
          {
            dispatch_event_handler_1("set efuse calib temp_level=%d (rem:%x), temp_range:%d~%d\n", a2, v8, v7 + 30, v7 + 39);
            return a2 | (v8 << 8);
          }
        }
        else
        {
          *(volatile uint16_t *)((volatile char *)&a1a + 1) = 0;
          a1a = (a1a & ~0xFF00u) | (((uint8_t)(0) & 0xFFu) << 8);
          a1a = (a1a & ~0xFFu) | ((uint8_t)(a2) & 0xFFu);
          mmio_write_64((int)&a1a);
          dispatch_event_handler_1("set flash calib temp_level=%d, temp_range:%d~%d\n", a2, v7 + 30, v7 + 39);
          return (char)a1a | 0xF00;
        }
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0, a2, a3, v3);
      return -21;
    }
  }
  else if ( v3 )
  {
    v4 = rf_reg10_status(&a1a);
    dispatch_event_handler_1(
      "read efuse calib temp_level:%d (rem:%x), temp_range:%d~%d\n",
      a1a,
      v4,
      10 * a1a + 30,
      10 * a1a + 39);
    return (char)a1a;
  }
  else
  {
    a1a = 0;
    if ( mmio_read_64((int)&a1a) )
    {
      dispatch_event_handler_1(aEmpty_0);
      return 3584;
    }
    else
    {
      dispatch_event_handler_1(
        "read flash calib temp_level:%d, temp_range:%d~%d\n",
        (char)a1a,
        10 * (char)a1a + 30,
        10 * (char)a1a + 39);
      return (char)a1a | 0xF00;
    }
  }
}


// pack_control_data @ 0x122db8
int pack_control_data(int a1, unsigned int a2) {
  unsigned int v2; // r3
  int v3; // r5
  int v6; // r5
  int v7; // r4
  int v8; // r1
  int v9; // r0
  int v11; // r0
  unsigned int v12; // r4
  int v13; // r1
  unsigned int v14; // r1
  int v15; // r6
  int v16; // r5
  int v17; // r2
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1
  struct __attribute__((packed)) { uint16_t a1a; // [sp+Ah] [bp-6h] BYREF
  int a3; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  _frame.a1a = 0;
  v2 = *(volatile uint32_t *)off_122F10;
  _frame.a3 = 0;
  v3 = HIBYTE(v2) & 2;
  if ( v3 )
  {
    if ( !a1 )
    {
      v6 = mmio_read_status((void *)(&_frame.a1a));
      v7 = mmio_read_byte((volatile uint8_t *)&_frame.a1a + 1);
      dispatch_event_handler_1(
        "read efuse cap:0x%x (remain:%x), cap_fine:0x%x (remain:%x)\n",
        (uint8_t)_frame.a1a,
        v6,
        HIBYTE(_frame.a1a),
        v7);
      v8 = v7 << 24;
      v9 = v6 << 16;
      return (uint8_t)_frame.a1a | (HIBYTE(_frame.a1a) << 8) | v8 | v9;
    }
  }
  else
  {
    v11 = bus_read32((int)&_frame.a3);
    if ( !a1 )
    {
      if ( v11 )
      {
        dispatch_event_handler_1(aEmpty_0);
        v9 = 917504;
        v8 = 234881024;
      }
      else
      {
        _frame.a1a = _frame.a3;
        dispatch_event_handler_1("read flash cap:0x%x, cap_fine:0x%x\n", (uint8_t)_frame.a3, BYTE1(_frame.a3));
        v9 = 983040;
        v8 = 251658240;
      }
      return (uint8_t)_frame.a1a | (HIBYTE(_frame.a1a) << 8) | v8 | v9;
    }
  }
  if ( a1 == 1 )
  {
    v13 = *(volatile uint8_t *)(off_122F18 + 4);
    if ( a2 >= 0x1F )
      a2 = 31;
    if ( a2 == v13 )
    {
      v15 = *(volatile char *)(off_122F18 + 2);
      if ( v3 )
      {
        v16 = mmio_get_field(a2);
        if ( v16 < 0 )
        {
          dispatch_event_handler_1(aNoRoom_0);
          v12 = 65280;
        }
        else
        {
          dispatch_event_handler_1("set xtal_cap to efuse: 0x%x\n", a2);
          v12 = a2 | (v16 << 8);
        }
      }
      else
      {
        _frame.a3 = (_frame.a3 & ~0xFFu) | ((uint8_t)(a2) & 0xFFu);
        bus_write32((int)&_frame.a3);
        v20 = a2;
        v12 = a2 | 0xF00;
        dispatch_event_handler_1("set xtal_cap to flash: 0x%x\r\n", v20);
      }
      check_radio_status(1, v15, v17);
    }
    else
    {
      v12 = ~((unsigned int)~(v13 << 23) >> 23);
      dispatch_event_handler_1("xtal_cap error, not the calibed val:0x%x\n", v13);
    }
  }
  else if ( a1 == 2 )
  {
    if ( a2 >= 0x3F )
      a2 = 63;
    if ( v3 )
    {
      v18 = mmio_wait_bit((uint8_t)a2);
      if ( v18 < 0 )
      {
        dispatch_event_handler_1(aNoRoom_0);
        return 65280;
      }
      else
      {
        v19 = a2;
        v12 = a2 | (v18 << 8);
        dispatch_event_handler_1("set xtal_cap_fine to efuse: 0x%x, r %d\n", v19, v18);
      }
    }
    else
    {
      _frame.a3 = (_frame.a3 & ~0xFFu) | ((uint8_t)(a2) & 0xFFu);
      bus_write32((int)&_frame.a3);
      v14 = a2;
      v12 = a2 | 0xF00;
      dispatch_event_handler_1("set xtal_cap_fine to flash: 0x%x\r\n", v14);
    }
  }
  else
  {
    return 0;
  }
  return v12;
}


// check_address_alignment @ 0x122f3c
int check_address_alignment(int a1, int a2, int a3, int a4) {
  unsigned int v5; // r5
  unsigned int v7; // r5

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( !(a2 << 28) || (a2 & 0xFFFFFFF0) != 0 )
      {
        dispatch_event_handler_1("invalid cfg: %x\n", a2);
        return -11;
      }
      else
      {
        v5 = mmio_rmw_field((uint8_t)a2);
        dispatch_event_handler_1("set ef_sdio_cfg=%x, cur=%x\n", a2, v5);
      }
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0, a2, a3);
      return -21;
    }
    return v5;
  }
  else
  {
    v7 = rf_get_reg1_bits13_16();
    dispatch_event_handler_1("get ef_sdio_cfg=%x\n", v7);
    return v7;
  }
}


// lookup_entry @ 0x122fa4
int lookup_entry(int a1, int a2) {
  unsigned int v4; // r0
  int v5; // r4

  v4 = rf_get_reg1_bit9();
  v5 = v4;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( v4 )
      {
        dispatch_event_handler_1(aAlreadySet);
      }
      else
      {
        dispatch_event_handler_1("set ef_usb_id=%x\n", a2);
        mmio_write_reg2(__ROR4__(a2, 16));
        rf_set_reg1_bit9();
      }
      return __ROR4__(rf_get_reg2(), 16);
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0);
      return 0;
    }
  }
  else
  {
    if ( v4 )
    {
      v5 = __ROR4__(rf_get_reg2(), 16);
      dispatch_event_handler_1("get ef_usb_id=%x\n", v5);
    }
    else
    {
      dispatch_event_handler_1(aUnset);
    }
    return v5;
  }
}


// handle_state_change @ 0x123020
int handle_state_change(int a1) {
  unsigned int v1; // r4
  unsigned int v3; // r4

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      rf_set_reg0xf_bit19();
      v1 = rf_get_reg0xf_bit19();
      dispatch_event_handler_1("set ef_he_off=1(%x)\n", v1);
    }
    else
    {
      dispatch_event_handler_1(aWrongFunc_0);
      return -21;
    }
    return v1;
  }
  else
  {
    v3 = rf_get_reg0xf_bit19();
    dispatch_event_handler_1("get ef_he_off=%x\n", v3);
    return v3;
  }
}


// enter_critical_section_2 @ 0x123068
int enter_critical_section_2() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  mac_tx_irq();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1230C8 = 1;
  }
  v0 = (volatile int *)off_1230CC;
  v1 = (volatile uint32_t *)dword_1230D0;
  ++*(volatile uint32_t *)off_1230CC;
  list_init_1(v1);
  list_init_1((volatile uint32_t *)dword_1230D4);
  check_kernel_state(dword_1230D0, (volatile uint32_t *)dword_1230D8);
  check_kernel_state(dword_1230D0, (volatile uint32_t *)dword_1230DC);
  check_kernel_state(dword_1230D0, (volatile uint32_t *)dword_1230E0);
  result = check_kernel_state(dword_1230D0, (volatile uint32_t *)dword_1230E4);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1230C8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// process_queue_message @ 0x1230e8
int process_queue_message(int a1) {
  int v1; // r0
  int v2; // r4
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  volatile uint8_t *v10; // r2
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v1 = co_list_insert(a1, (volatile uint8_t *)dword_123208, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( memset_ff(off_123210) != v1 || strcmp(off_123210, (volatile unsigned int *)dword_123208) )
      {
        v4 = list_pop_front(dword_123214);
        v5 = v4;
        if ( v4 )
        {
          strcpy((unsigned int)(v4 + 1), dword_123208);
          check_kernel_state(dword_123218, v5);
        }
        else
        {
          uart_tx_string(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        log_printf(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          uart_tx_string(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              log_printf("\r\n[%08x]:", v12);
            v14 = *(volatile uint32_t *)v12;
            v12 += 4;
            log_printf(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          uart_tx_string(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              log_printf("\r\n[%08x]:", v15);
            v17 = *(volatile uint32_t *)v15;
            v15 += 4;
            log_printf(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        uart_tx_string(aAic_0);
        v10 = (void *)(uintptr_t)(off_123224);
        v11 = *(volatile uint8_t *)off_123224;
        if ( *(volatile uint8_t *)off_123224 )
        {
          *((volatile uint8_t *)off_123228 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((volatile uint8_t *)off_123228 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      uart_tx_string(aAic);
    }
    co_list_insert(0x30u, (volatile uint8_t *)dword_123208, (unsigned int)aAic);
  }
  return v2;
}


