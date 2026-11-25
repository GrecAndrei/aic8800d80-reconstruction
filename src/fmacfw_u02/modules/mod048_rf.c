// parse_large_ioctl @ 0x130170
int parse_large_ioctl(int a1, int a2) {
  volatile int *v2; // r6
  int v3; // r0
  int result; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r2
  volatile uint8_t **v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  volatile uint8_t **v13; // r0
  int v14; // r0
  volatile uint8_t *a1a[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_130260 = 1;
  }
  v2 = (volatile int *)off_130264;
  v3 = dword_130268;
  ++*(volatile uint32_t *)off_130264;
  result = (int)mem_word_load(v3);
  v5 = result;
  if ( *v2 )
  {
    v6 = *v2 - 1;
    v7 = *(volatile uint32_t *)off_130260;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v8 = (volatile uint8_t **)off_13026C;
    do
    {
      v9 = parse_token_until_space((volatile uint8_t *)(v5 + 4), (int)a1a);
      if ( v9 )
      {
        v13 = (void *)(parse_ipv4_dot((int)(uintptr_t)(a1a[0]), (void *)(v8), 7));
        if ( v13 )
        {
          if ( *((volatile int16_t *)v13 + 5) < v9 || *((volatile int16_t *)v13 + 4) > v9 )
          {
            log_printf(aUsageSS, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, volatile uint8_t **))v13[3])(v9, a1a);
            if ( v14 )
              log_printf("Command fail, ret=%d\r\n", v14);
          }
        }
        else
        {
          log_printf("Unknown command '%s'\r\n", (const volatile char *)a1a[0]);
        }
      }
      else
      {
        read_memory_byte(aNoCommand);
      }
      read_memory_byte(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_130260 = 1;
      }
      v10 = dword_130278;
      ++*v2;
      co_list_push_back(v10, (volatile uint32_t *)v5);
      result = (int)mem_word_load(dword_130268);
      v5 = result;
      if ( *v2 )
      {
        v11 = *v2 - 1;
        v12 = *(volatile uint32_t *)off_130260;
        *v2 = v11;
        if ( !v11 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}


// read_mmio_reg @ 0x130288
void read_mmio_reg() {
  volatile uint32_t *v0; // r4
  unsigned int byte_uart; // r0

  v0 = (void *)(uintptr_t)(off_1302BC);
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      byte_uart = gpio_read();
      if ( find_by_index(byte_uart) > 0 )
      {
        if ( *(volatile uint8_t *)off_1302C0 )
          ((int (*)())parse_large_ioctl)();
        return;
      }
    }
  }
}



// rf_xtal_cap_adjust @ 0x1302c4
unsigned int rf_xtal_cap_adjust() {
  volatile uint8_t *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  uint8_t v3; // r0

  v0 = (volatile uint8_t *)off_1302F0;
  result = *((volatile uint8_t *)off_1302F0 + 6);
  v2 = *((volatile uint8_t *)off_1302F0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((volatile uint8_t *)off_1302F0 + 6) = v3;
    rf_get_state(v3);
    return event_dispatch("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v0[5], v0[6]);
  }
  return result;
}


// rf_calibrate_channel_power @ 0x1302f8
int rf_calibrate_channel_power(int a1) {
  volatile uint8_t *v1; // r3
  int v2; // r2
  int v3; // r0
  char v4; // lr
  char v5; // r9
  char v6; // r8
  char v7; // r5
  int v8; // r7
  int v9; // r6
  char v10; // r4
  char v11; // r12
  char v12; // r1

  v1 = (void *)(uintptr_t)(off_130364);
  v2 = *((volatile char *)off_130364 + 2) + 7;
  v3 = a1 + 7;
  v4 = *(volatile uint8_t *)(dword_13036C + v2);
  v5 = *(volatile uint8_t *)(dword_130368 + v2 + 16);
  v6 = *(volatile uint8_t *)(dword_130368 + v2 + 32);
  v7 = *(volatile uint8_t *)(dword_130368 + v3 + 16);
  v8 = dword_13036C + v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_130368 + v3) - *(volatile uint8_t *)(dword_130368 + v2)) & 0xFFu);
  v9 = dword_13036C + v3;
  v10 = *(volatile uint8_t *)(dword_130368 + v3 + 32);
  v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_13036C + v3)) & 0xFFu);
  v11 = *(volatile uint8_t *)(v8 + 16);
  v12 = *(volatile uint8_t *)(v9 + 16);
  v8 = (v8 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v8 + 32)) & 0xFFu);
  *((volatile uint8_t *)off_130364 + 8) = v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v9 + 32) - v8) & 0xFFu);
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return handle_event();
}



// call_phy_op @ 0x130370
int call_phy_op() {
  return rf_core_reset_alt();
}



// rf_get_bandwidth @ 0x130374
int rf_get_bandwidth() {
  if ( *((volatile uint8_t *)off_13039C + 1) )
    return *((volatile char *)off_13039C + 3);
  rf_core_reset_alt();
  return (int)COERCE_FLOAT(rf_core_is_ready());
}



// rf_configure_channel @ 0x1303a0
int rf_configure_channel() {
  volatile uint8_t *v0; // r4
  int v1; // r4
  int v2; // r0
  int v4; // [sp+14h] [bp-4h]

  v0 = (volatile uint8_t *)off_130418;
  event_dispatch(
    "temp_comp: init=%d, en=%d, lvl_cal=%d, t_last=%d C\n",
    *(volatile char *)off_130418,
    *((volatile char *)off_130418 + 1),
    *((volatile char *)off_130418 + 2),
    *((volatile char *)off_130418 + 3));
  event_dispatch("xtal_cap: cal=0x%x, tgt=0x%x, cur=0x%x\n", v0[4], v0[5], v0[6]);
  event_dispatch(
    "ofst2x: 2G4=%d,%d,%d; 5G=%d,%d,%d\n",
    (char)v0[8],
    (char)v0[9],
    (char)v0[10],
    (char)v0[11],
    (char)v0[12],
    (char)v0[13]);
  v1 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_130428)[90]);
  v4 = ((volatile uint32_t *)(uintptr_t)off_130428)[91];
  v2 = ke_task_find(1070, 1);
  return event_dispatch("settings: en=%d, tmr=%d, act=%d\n", v1, v4, v2);
}


// rf_is_channel_valid @ 0x130430
int rf_is_channel_valid(int a1) {
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_1304AC * (uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((uint64_t)((int32_t)dword_1304A0 * (int64_t)(int32_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((volatile uint8_t *)off_1304A4 + 4)
     + (char)(*(volatile uint8_t *)(dword_1304A8 + v1 + 7) - *(volatile uint8_t *)(dword_1304A8 + *((volatile char *)off_1304A4 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  *((volatile uint8_t *)off_1304A4 + 5) = v2;
  rf_calibrate_channel_power(v1);
  result = get_flag_bit(9u, 4u);
  if ( result )
    return rf_configure_channel();
  return result;
}



// rf_temperature_compensation @ 0x1304b0
int rf_temperature_compensation() {
  int v0; // s15
  int v1; // r3

  v0 = (int)COERCE_FLOAT(rf_core_is_ready());
  event_dispatch("\x9D\x89t=%d C\n", v0);
  v1 = (char)v0 - *((volatile char *)off_1304F4 + 3);
  if ( v1 < 0 )
    v1 = *((volatile char *)off_1304F4 + 3) - (char)v0;
  if ( v1 > 4 )
  {
    *((volatile uint8_t *)off_1304F4 + 3) = v0;
    rf_is_channel_valid((char)v0);
  }
  return rf_xtal_cap_adjust();
}


// rf_get_channel_calibration @ 0x1304f8
void rf_get_channel_calibration() {
  volatile uint8_t *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  struct __attribute__((packed)) { uint8_t a1; // [sp+3h] [bp-Dh] BYREF
  int v8; // [sp+4h] [bp-Ch] BYREF
  int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_1305A8);
  v1 = *(volatile char *)off_1305A8;
  if ( *(volatile uint8_t *)off_1305A8 )
    return;
  _frame.a1 = *(volatile uint8_t *)off_1305A8;
  v2 = *(volatile uint32_t *)off_1305AC;
  _frame.v8 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    rf_cmd6_read(&_frame.a1);
    rom_get_chip_version(&_frame.v8);
    goto LABEL_4;
  }
  _frame.v9 = 0;
  _frame.v10 = 0;
  if ( !ke_event_send_2((int)&_frame.v9) )
    _frame.a1 = _frame.v9;
  if ( ke_event_send_0x80((int)&_frame.v10) )
  {
LABEL_4:
    v3 = _frame.a1;
    if ( _frame.a1 )
      goto LABEL_5;
    goto LABEL_19;
  }
  _frame.v8 = (char)_frame.v10;
  v3 = _frame.a1;
  if ( _frame.a1 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      v3 = (v3 & ~0xFFu) | ((uint8_t)(31) & 0xFFu);
      _frame.a1 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  v3 = (v3 & ~0xFFu) | ((uint8_t)(15) & 0xFFu);
LABEL_7:
  v0[4] = v3;
  v4 = rf_get_rssi();
  v5 = _frame.v8;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      _frame.v8 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      _frame.v8 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v0[2] = v6;
    event_dispatch("\x9D\x89temp_lvl_calibed=%d\n", v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}


// rf_enable_2 @ 0x1305b4
int rf_enable_2() {
  volatile uint8_t *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2

  v0 = (void *)(uintptr_t)(off_13060C);
  *((volatile uint8_t *)off_13060C + 1) = 1;
  result = ke_task_find(1070, 1);
  if ( !result )
  {
    rf_core_reset_alt();
    v0[6] = rf_get_rssi();
    rf_temperature_compensation();
    v2 = (uint8_t)v0[5];
    if ( (uint8_t)v0[6] != v2 )
    {
      rf_get_state(v2);
      v3 = (uint8_t)v0[5];
      v0[6] = v3;
      event_dispatch("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v3, v3);
    }
    return ke_timer_set(1070, 1, 1000 * ((volatile uint32_t *)(uintptr_t)off_130610)[91]);
  }
  return result;
}


// rf_disable @ 0x130618
int rf_disable() {
  int result; // r0

  *((volatile uint8_t *)off_13063C + 1) = 0;
  result = ke_task_find(1070, 1);
  if ( result )
    return ke_int_lock(1070, 1);
  return result;
}



// mac_append_ht_capabilities_ie @ 0x130640
int mac_append_ht_capabilities_ie(volatile int *a1) {
  volatile char *v1; // r4
  int16_t v2; // r3
  int v3; // r2
  int v4; // r6
  volatile char *v5; // r3
  char v6; // t1
  volatile char *v7; // r2
  int v8; // r5
  volatile uint8_t *v9; // r3
  volatile uint8_t *v10; // r5
  char v11; // t1

  v1 = (volatile char *)off_1306B8;
  v2 = *((volatile uint16_t *)off_1306B8 + 6);
  *(volatile uint8_t *)*a1 = 45;
  *(volatile uint8_t *)(*a1 + 1) = 26;
  v3 = *a1;
  *(volatile uint16_t *)(v3 + 2) = v2 & 0xFFE3 | 0xC;
  *(volatile uint8_t *)(v3 + 4) = v1[14];
  v4 = *a1;
  v5 = v1 + 15;
  do
  {
    v6 = *v5++;
    *(volatile uint8_t *)(v5 - v1 + v4 - 11) = v6;
  }
  while ( v5 != v1 + 31 );
  v7 = (volatile char *)dword_1306BC;
  *(volatile uint8_t *)(*a1 + 15) = 0;
  *(volatile uint8_t *)(*a1 + 16) = 0;
  v8 = *a1;
  *(volatile uint16_t *)(v8 + 21) = *((volatile uint16_t *)v1 + 16);
  v9 = (volatile uint8_t *)(v8 + 23);
  v10 = (volatile uint8_t *)(v8 + 27);
  do
  {
    v11 = *v7++;
    *v9++ = v11;
  }
  while ( v9 != v10 );
  *(volatile uint8_t *)(*a1 + 27) = v1[40];
  *a1 += 28;
  return 28;
}



// format_bt_address @ 0x1306c0
volatile char * format_bt_address(int a1) {
  int v1; // r2
  volatile uint16_t *v2; // r5
  volatile uint8_t *v4; // r3
  int v5; // r0
  char v6; // t1
  int v7; // r2
  int v8; // r4
  int v9; // r0
  int v10; // r3
  char v11; // t1
  int v12; // r3
  int16_t v13; // r2
  volatile uint16_t *v14; // r7
  int16_t v15; // r1
  int16_t v16; // r3
  volatile char *result; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  char v23; // t1

  v1 = dword_13078C;
  **(volatile uint8_t **)a1 = -1;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 2) = 35;
  v2 = *(volatile uint16_t **)a1;
  v4 = (volatile uint8_t *)(*(volatile uint32_t *)a1 + 3);
  v5 = *(volatile uint32_t *)a1 + 9;
  do
  {
    v6 = *(volatile uint8_t *)++v1;
    *v4++ = v6;
  }
  while ( v4 != (volatile uint8_t *)v5 );
  v7 = dword_130790;
  v8 = dword_130790 - 65;
  v9 = dword_130790 + 11;
  do
  {
    v10 = v7 - 56;
    v11 = *(volatile uint8_t *)++v7;
    *((volatile uint8_t *)v2 + v10 - v8) = v11;
  }
  while ( v7 != v9 );
  v12 = *(volatile uint8_t *)(v8 + 0x42);
  v13 = *(volatile uint16_t *)(v8 + 0x4E);
  v2[11] = *(volatile uint16_t *)(v8 + 0x50);
  v2[10] = v13;
  v14 = v2 + 12;
  if ( (v12 & 8) != 0 )
  {
    v15 = *(volatile uint16_t *)(v8 + 0x52);
    v2[13] = *(volatile uint16_t *)(v8 + 0x54);
    v2[12] = v15;
    v14 = v2 + 14;
  }
  if ( ((v12 >> 1) & 8) != 0 )
  {
    v16 = *(volatile uint16_t *)(v8 + 0x56);
    *v14 = v16;
    v14[1] = v16;
    v14 += 2;
  }
  if ( *(volatile uint8_t *)(v8 + 0x48) >> 7 )
  {
    v18 = ((int (*)())util_extract_bits)();
    v19 = v18 + 1 + *(volatile uint8_t *)(v8 + 0x175) * (v18 + 1);
    v20 = (uint8_t)((unsigned int)(6 * v19 + 14) >> 3);
    if ( (uint8_t)((unsigned int)(6 * v19 + 14) >> 3) )
    {
      v21 = dword_130794;
      do
      {
        v22 = v21 - 89;
        v23 = *(volatile uint8_t *)++v21;
        *((volatile uint8_t *)v14 + v22 - v8) = v23;
      }
      while ( v8 + 89 + v20 != v21 );
      v14 = (volatile uint16_t *)((volatile char *)v14 + v20);
    }
  }
  result = (volatile char *)v14 - *(volatile uint32_t *)a1;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 1) = (uint8_t)result - 2;
  *(volatile uint32_t *)a1 = *(volatile uint32_t *)a1 + (int)(uintptr_t)( result);
  return result;
}



// format_hw_version @ 0x130798
int format_hw_version(int a1) {
  volatile uint32_t *v2; // r1
  volatile uint16_t *v3; // r2
  int16_t v4; // r6
  int16_t v5; // r5
  int16_t v6; // r4

  v2 = (void *)(uintptr_t)(off_1307D0);
  **(volatile uint8_t **)a1 = -65;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 1) = 12;
  *(volatile uint32_t *)(*(volatile uint32_t *)a1 + 2) = v2[12];
  v3 = *(volatile uint16_t **)a1;
  v4 = *((volatile uint16_t *)v2 + 26);
  v5 = *((volatile uint16_t *)v2 + 27);
  v6 = *((volatile uint16_t *)v2 + 28);
  v3[6] = *((volatile uint16_t *)v2 + 29);
  v3[3] = v4;
  v3[4] = v5;
  v3[5] = v6;
  *(volatile uint32_t *)a1 = (int)(uintptr_t)(v3 + 7);
  return 14;
}



// chip_id_to_string @ 0x1307d4
int chip_id_to_string(int a1) {
  **(volatile uint8_t **)a1 = 70;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 1) = 5;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 2) = 112;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 3) = 0;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 4) = 0;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 5) = 0;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 6) = 0;
  *(volatile uint32_t *)a1 += 7;
  return 7;
}



// pack_4_uint16 @ 0x130804
int pack_4_uint16(int a1, int16_t a2, int16_t a3, int16_t a4, volatile char *a5) {
  volatile char *v5; // r2
  volatile uint8_t *v6; // r3
  char v7; // t1

  *(volatile uint16_t *)a1 = a2;
  *(volatile uint16_t *)(a1 + 2) = a3;
  *(volatile uint16_t *)(a1 + 4) = a4;
  if ( !a5 )
    return 6;
  *(volatile uint8_t *)(a1 + 6) = 16;
  *(volatile uint8_t *)(a1 + 7) = 0x80;
  v5 = a5;
  do
  {
    v6 = v5 + 8;
    v7 = *v5++;
    *(volatile uint8_t *)((uintptr_t)(v6) - (uintptr_t)(a5) + a1) = v7;
  }
  while ( v5 != a5 + 128 );
  return 136;
}



// store_uint16_ret2 @ 0x130838
int store_uint16_ret2(volatile uint16_t *a1, int16_t a2) {
  *a1 = a2;
  return 2;
}



// rx_status_handler @ 0x130840
int rx_status_handler(volatile uint8_t *a1, int a2, volatile uint16_t *a3, int a4, volatile uint32_t *a5, volatile uint16_t *a6, int a7) {
  int v8; // r5
  int16_t v9; // r7
  int v10; // r6
  int v12; // r0
  volatile uint16_t *v13; // r3
  int v14; // r0
  volatile uint8_t *v15; // r7
  int v16; // r2
  int16_t v17; // r9
  int v18; // r0
  int v19; // lr
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r12
  int v23; // r3
  int v24; // r8
  volatile char *v25; // r2
  int v26; // r12
  char v27; // t1
  unsigned int v28; // r12
  int v29; // r3
  int v30; // lr
  unsigned int v31; // r12
  volatile char *v32; // r2
  char v33; // t1
  int16_t v34; // r0
  int v35; // r3
  volatile char *v36; // r2
  char v37; // t1
  int v38; // r5
  int v39; // r3
  int v40; // r9
  int v41; // r2
  int v42; // r1
  int v43; // r2
  int v44; // r3
  volatile uint8_t *v45; // r2
  char i; // r1
  char v47; // t1
  volatile uint16_t *v48; // r10
  int v49; // r3
  volatile uint8_t *v50; // r5
  int v51; // r2
  int v52; // r3
  int16_t v53; // r3
  int v55; // r0
  volatile char *v56; // r2
  char v57; // t1
  int v58; // r5
  int16_t v59; // r9
  char v60; // r0
  volatile uint8_t *v61; // r3
  volatile uint8_t *v62; // r3
  volatile uint8_t *v63; // r3
  volatile uint8_t *v64; // r3
  volatile uint8_t *v65; // r3
  volatile uint8_t *v66; // r10
  unsigned int v67; // r9
  volatile char *v68; // r2
  int v69; // r1
  int v70; // r0
  int v71; // lr
  char v72; // r4
  int v73; // r3
  int v74; // r12
  unsigned int v75; // r11
  char v76; // r1
  char v77; // r3
  int16_t v78; // lr
  volatile uint8_t *v79; // r2
  int v80; // r12
  volatile uint8_t *v81; // r12
  uint16_t v82; // r0
  struct __attribute__((packed)) { int16_t v83; // [sp+4h] [bp-60h]
  char _pad1[2]; int a3a; // [sp+8h] [bp-5Ch]
  char v85; // [sp+Ch] [bp-58h]
  char _pad3[3]; volatile char *v86; // [sp+10h] [bp-54h]
  int v87; // [sp+14h] [bp-50h]
  int v88; // [sp+18h] [bp-4Ch]
  int a1a; // [sp+1Ch] [bp-48h] BYREF
  char _pad7[3]; char a2a; // [sp+23h] [bp-41h] BYREF
  uint32_t result[2]; // [sp+24h] [bp-40h] BYREF
  uint8_t v92[2]; // [sp+2Ch] [bp-38h] BYREF
  int v93; // [sp+2Eh] [bp-36h]
  int16_t v94; // [sp+32h] [bp-32h]
  char _pad12[32]; int v95; // [sp+54h] [bp-10h]
  } _frame;
  v8 = a7;
  v9 = *(volatile uint16_t *)(a7 + 56);
  v10 = *(volatile uint16_t *)(a7 + 54);
  if ( !v9 )
    v9 = 5;
  _frame.a1a = (int)a1;
  v12 = rf_get_channel_cal(a4);
  v13 = (volatile uint16_t *)_frame.a1a;
  v14 = v12 | (*(volatile uint32_t *)(a2 + 224) >> 1) & 0x10;
  *(volatile uint16_t *)(_frame.a1a + 2) = v9;
  *v13 = v14;
  _frame.a3a = (uint16_t)v14;
  v15 = (volatile uint8_t *)(a7 + 64);
  if ( a3 )
  {
    v13[2] = *a3;
    v13[3] = a3[1];
    v13[4] = a3[2];
    v16 = 5;
    v17 = 10;
  }
  else
  {
    v16 = 2;
    v17 = 4;
  }
  *a5 = (int)(uintptr_t)(&v13[v16]);
  v18 = *(volatile uint8_t *)(a2 + 126);
  _frame.a1a = (int)&v13[v16];
  v13[v16] = (v13[v16] & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  v19 = v18 + 2;
  *(volatile uint8_t *)(_frame.a1a + 1) = v18;
  if ( v18 )
  {
    v20 = _frame.a1a;
    v55 = v18 + 127 + a2;
    v56 = (volatile char *)(a2 + 127);
    do
    {
      v57 = *v56++;
      v56[v20 - a2 - 126] = v57;
    }
    while ( (volatile char *)v55 != v56 );
  }
  else
  {
    v20 = _frame.a1a;
  }
  v21 = *(volatile uint8_t *)(a2 + 176);
  _frame.a1a = v19 + v20;
  *(volatile uint8_t *)(v19 + v20) = 1;
  v22 = v21;
  if ( v21 >= 8 )
    v22 = 8;
  *(volatile uint8_t *)(_frame.a1a + 1) = v22;
  v23 = _frame.a1a;
  v24 = v22 + 2;
  v25 = (volatile char *)(a2 + 177);
  if ( v21 )
  {
    v26 = v22 + 177 + a2;
    do
    {
      v27 = *v25++;
      v25[v23 - a2 - 176] = v27;
    }
    while ( v25 != (volatile char *)v26 );
  }
  v28 = *(volatile uint8_t *)(a2 + 176);
  _frame.v83 = v17 + v19 + v24;
  _frame.a1a = v24 + v23;
  if ( v28 > 8 )
  {
    *(volatile uint8_t *)(v24 + v23) = 50;
    *(volatile uint8_t *)(_frame.a1a + 1) = v28 - 8;
    v29 = _frame.a1a;
    v30 = v28 + 177 + a2;
    v31 = v28 - 6;
    v32 = (volatile char *)(a2 + 185);
    do
    {
      v33 = *v32++;
      v32[v29 - a2 - 184] = v33;
    }
    while ( v32 != (volatile char *)v30 );
    _frame.a1a = v29 + v31;
    _frame.v83 += v31;
  }
  if ( (_frame.a3a & 0x100) == 0 )
    goto LABEL_17;
  v61 = (volatile uint8_t *)_frame.a1a++;
  *v61 = 33;
  v62 = (volatile uint8_t *)_frame.a1a++;
  *v62 = 2;
  get_calibration_offsets((void *)(_frame.result), &_frame.a2a);
  if ( SLOBYTE(_frame.result[0]) > *(volatile char *)(a2 + 172) )
    _frame.result[0] = (_frame.result[0] & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 172)) & 0xFFu);
  v63 = (volatile uint8_t *)_frame.a1a++;
  *v63 = _frame.a2a;
  v64 = (volatile uint8_t *)_frame.a1a++;
  *v64 = _frame.result[0];
  v65 = (volatile uint8_t *)_frame.a1a++;
  *v65 = 36;
  _frame.v86 = (volatile char *)_frame.a1a;
  v66 = (volatile uint8_t *)(_frame.a1a + 1);
  if ( *(volatile uint8_t *)(a2 + 164) )
  {
    v67 = *((volatile uint8_t *)off_130CA8 + 371);
    _frame.v87 = 4;
    v68 = (volatile char *)off_130CA8 + 202;
  }
  else
  {
    v67 = *((volatile uint8_t *)off_130CA8 + 370);
    _frame.v87 = 1;
    v68 = (volatile char *)off_130CA8 + 118;
  }
  if ( v67 )
  {
    v69 = 0;
    _frame.v88 = a2;
    _frame.v85 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    while ( 1 )
    {
      v73 = v68[3] & 2;
      if ( (v68[3] & 2) == 0 )
        break;
LABEL_62:
      if ( v67 <= (uint8_t)++v69 )
      {
        v8 = a7;
        v76 = v72;
        v77 = _frame.v85 + 2;
        a2 = _frame.v88;
        v78 = (uint8_t)(_frame.v85 + 2);
        goto LABEL_64;
      }
    }
    v74 = *(volatile uint16_t *)v68;
    if ( v68[2] )
    {
      if ( v68[2] == 1 )
      {
        v80 = v74 - 4992;
        if ( (uint16_t)(v80 - 13) <= 0x370u )
        {
          v75 = (unsigned int)(((unsigned int)dword_130CB8 * (uint64_t)(unsigned int)(v80 - 8)) >> 32) >> 2;
          v73 = (uint8_t)v75;
          goto LABEL_58;
        }
      }
    }
    else if ( (unsigned int)(v74 - 2412) <= 0x48 )
    {
      if ( v74 == 2484 )
      {
        v73 = 14;
        v75 = 14;
      }
      else
      {
        v75 = (unsigned int)(((unsigned int)dword_130CB8 * (uint64_t)(unsigned int)(v74 - 2407)) >> 32) >> 2;
        v73 = (uint8_t)v75;
      }
LABEL_58:
      if ( !v70 )
      {
        v71 = v73;
        v72 = v73;
        v70 = 1;
        goto LABEL_61;
      }
      if ( v75 - v71 == _frame.v87 )
      {
        v70 = (uint8_t)(v70 + 1);
        v71 = v73;
LABEL_61:
        v68 += 6;
        goto LABEL_62;
      }
      goto LABEL_71;
    }
    if ( !v70 )
    {
      v71 = 0;
      v72 = 0;
      v70 = 1;
      goto LABEL_61;
    }
LABEL_71:
    _frame.a1a = (int)(v66 + 1);
    *v66 = v72;
    v81 = (volatile uint8_t *)_frame.a1a++;
    *v81 = v70;
    _frame.v85 += 2;
    v71 = v73;
    v70 = (uint8_t)(v70 + 2);
    v66 = (volatile uint8_t *)_frame.a1a;
    goto LABEL_61;
  }
  v77 = 2;
  v70 = (v70 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  v76 = 0;
  v78 = 2;
LABEL_64:
  _frame.a1a = (int)(v66 + 1);
  *v66 = v76;
  v79 = (volatile uint8_t *)_frame.a1a++;
  *v79 = v70;
  _frame.v83 += v78 + 6;
  *_frame.v86 = v77;
LABEL_17:
  v34 = chip_id_to_string((int)&_frame.a1a);
  v35 = _frame.a1a;
  if ( v10 )
  {
    v36 = (volatile char *)(a7 + 64);
    do
    {
      v37 = *v36++;
      v36[v35 - v8 - 65] = v37;
    }
    while ( v36 != &v15[v10] );
  }
  v38 = *(volatile uint32_t *)(a2 + 224);
  v39 = v35 + v10;
  v40 = (uint16_t)(_frame.v83 + v10 + v34);
  _frame.a1a = v39;
  v41 = (v41 & ~0xFFu) | ((uint8_t)(v38) & 0xFFu);
  if ( (v38 & 1) != 0 )
  {
    v42 = ((volatile uint32_t *)(uintptr_t)off_130CA4)[1];
    v43 = ((volatile uint32_t *)(uintptr_t)off_130CA4)[2];
    _frame.result[0] = ((volatile uint32_t *)(uintptr_t)off_130CA4)[0];
    _frame.result[1] = v42;
    _frame.v92[1] = BYTE1(v43);
    _frame.v94 = 0;
    _frame.v93 = 0;
    _frame.v92[0] = 0;
    v44 = v39 - (uint32_t)_frame.result;
    v45 = (void *)(_frame.result);
    for ( i = -35; ; i = v47 )
    {
      v45[v44] = i;
      if ( v45 == _frame.v92 )
        break;
      v47 = *++v45;
    }
    v40 = (uint16_t)(v40 + 9);
    _frame.a1a += 9;
    v41 = (v41 & ~0xFFu) | ((uint8_t)(v38) & 0xFFu);
  }
  if ( (v38 & 2) != 0 && (*((volatile uint8_t *)off_130CA8 + 374) & 1) != 0 )
  {
    v82 = mac_append_ht_capabilities_ie(&_frame.a1a);
    v41 = *(volatile uint32_t *)(a2 + 224);
    v40 = (uint16_t)(v82 + v40);
  }
  if ( (v41 & 4) != 0 )
  {
    v48 = (volatile uint16_t *)off_130CA8;
    v49 = *((volatile uint8_t *)off_130CA8 + 374);
    if ( (v49 & 2) != 0 )
    {
      v58 = *((volatile uint8_t *)off_130CA8 + 373);
      if ( (*(volatile uint8_t *)off_130CB4 & 8) != 0
        || (event_dispatch(aAssocReq8800d4, v49 << 30), *((volatile uint8_t *)v48 + 373) <= 1u) )
      {
        v59 = v40 + format_hw_version((int)&_frame.a1a);
        v60 = util_extract_bits(v48[28]);
        if ( v58 == 4 )
          v58 = (v58 & ~0xFFu) | ((uint8_t)(3) & 0xFFu);
      }
      else
      {
        v59 = v40 + format_hw_version((int)&_frame.a1a);
        v60 = util_extract_bits(v48[28]);
        v58 = (v58 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
      }
      *(volatile uint8_t *)_frame.a1a = -57;
      *(volatile uint8_t *)(_frame.a1a + 1) = 1;
      *(volatile uint8_t *)(_frame.a1a + 2) = v58 | (16 * v60);
      v41 = *(volatile uint32_t *)(a2 + 224);
      v40 = (uint16_t)(v59 + 3);
      _frame.a1a += 3;
    }
  }
  if ( (v41 & 8) != 0 && (*((volatile uint8_t *)off_130CA8 + 374) & 4) != 0 )
    v40 = (uint16_t)((uint16_t)format_bt_address((int)&_frame.a1a) + v40);
  v50 = check_one_12dca0(v15, v10);
  init_sched_context((void *)(uintptr_t)((int)v15), v10, _frame.a3a, (int)_frame.result);
  if ( *(volatile uint16_t *)(a2 + 228)
    && (!v50 && (v51 = _frame.v95 << 26, (_frame.v95 & 0x20) != 0) || (*(volatile uint32_t *)(*((volatile uint32_t *)off_130CB0 + 4) + 48) & 0x40) != 0) )
  {
    check_status_bits(256, aAddMde, v51);
    *(volatile uint8_t *)_frame.a1a = 54;
    *(volatile uint8_t *)(_frame.a1a + 1) = 3;
    v52 = _frame.a1a;
    *(volatile uint16_t *)(_frame.a1a + 2) = *(volatile uint16_t *)(a2 + 228);
    *(volatile uint8_t *)(v52 + 4) = *(volatile uint8_t *)(a2 + 230);
    v40 = (uint16_t)(v40 + 5);
    v53 = _frame.a1a + 5;
  }
  else
  {
    v53 = _frame.a1a;
  }
  *a6 = v53 - *(volatile uint16_t *)a5;
  return v40;
}


// build_tx_power_cfg @ 0x130d14
int build_tx_power_cfg(int a1, int a2) {
  int16_t v2; // r3
  int16_t v3; // r4
  int16_t v4; // r2

  *(volatile uint8_t *)a1 = 3;
  *(volatile uint8_t *)(a1 + 1) = 0;
  *(volatile uint8_t *)(a1 + 2) = *(volatile uint8_t *)(a2 + 23);
  v2 = *(volatile uint8_t *)(a2 + 22);
  v3 = *(volatile uint8_t *)(a2 + 18);
  v4 = *(volatile uint16_t *)(a2 + 20);
  *(volatile uint16_t *)(a1 + 5) = *(volatile uint16_t *)(a2 + 14);
  *(volatile uint16_t *)(a1 + 3) = (4 * v2) | (2 * v3) | (v4 << 6);
  *(volatile uint16_t *)(a1 + 7) = 16 * *(volatile uint16_t *)(a2 + 12);
  return 9;
}



// build_packet_header @ 0x130d4c
int build_packet_header(int a1, int a2, int16_t a3, char a4, int16_t a5) {
  volatile uint8_t *v5; // r4

  *(volatile uint8_t *)(a1 + 2) = a4;
  *(volatile uint8_t *)a1 = 3;
  v5 = (void *)(uintptr_t)(off_130D8C);
  *(volatile uint16_t *)(a1 + 3) = a5;
  *(volatile uint8_t *)(a1 + 1) = 1;
  if ( !v5[371] )
    a3 &= ~1u;
  *(volatile uint16_t *)(a1 + 5) = a3;
  if ( a5 )
  {
    *(volatile uint8_t *)(a1 + 7) = 0;
    *(volatile uint8_t *)(a1 + 8) = 0;
  }
  else
  {
    *(volatile uint16_t *)(a1 + 7) = *(volatile uint16_t *)(a2 + 14);
  }
  return 9;
}



// build_packet_header_v2 @ 0x130d90
int build_packet_header_v2(int a1, int a2, int16_t a3) {
  int16_t v3; // r3
  int v4; // r1
  int16_t v5; // r3

  *(volatile uint8_t *)a1 = 3;
  *(volatile uint8_t *)(a1 + 1) = 2;
  v3 = *(volatile uint8_t *)(a2 + 22);
  v4 = *(volatile uint8_t *)(a2 + 17);
  *(volatile uint16_t *)(a1 + 4) = a3;
  v5 = v3 << 12;
  if ( v4 == 1 )
    v5 |= 0x800u;
  *(volatile uint16_t *)(a1 + 2) = v5;
  return 6;
}



// hexstr_to_bytes @ 0x130db8
volatile uint8_t * hexstr_to_bytes(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  int v7; // r4
  volatile uint8_t *v8; // r3
  volatile uint8_t *v9; // r0
  int v10; // r5
  volatile uint8_t *v11; // r1
  volatile uint8_t *v12; // r7
  int v13; // r2
  unsigned int v14; // r3
  uint8_t v15; // [sp+7h] [bp-1h] BYREF

  result = buf_calc_1(a1, a2, &v15);
  if ( result )
  {
    v7 = v15;
    v8 = result + 2;
    if ( v15 )
    {
      v9 = &result[v15 + 2];
      v7 = 0;
      do
      {
        v10 = *v8++;
        if ( (v10 & 0xFFFFFF7E) != 0x7E )
        {
          a3[v7 + 1] = v10;
          v7 = (uint8_t)(v7 + 1);
        }
      }
      while ( v9 != v8 );
    }
    result = buf_calc_2(a1, a2, &v15);
    if ( result )
    {
      v11 = result + 2;
      if ( v15 )
      {
        v12 = &result[v15 + 2];
        do
        {
          v13 = *v11;
          result = (volatile uint8_t *)(v13 & 0xFFFFFF7E);
          ++v11;
          v14 = (uint8_t)(v7 + 1);
          if ( (v13 & 0xFFFFFF7E) != 0x7E )
          {
            a3[v7 + 1] = v13;
            v7 = (uint8_t)(v7 + 1);
            if ( v14 > 0xB )
              break;
          }
        }
        while ( v12 != v11 );
      }
    }
    *a3 = v7;
  }
  else
  {
    *a3 = 0;
  }
  return result;
}



// call_config_setter @ 0x130e44
volatile uint8_t * call_config_setter(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0

  result = check_one_12dc60(a1, a2);
  if ( result )
    result = (volatile uint8_t *)(uint8_t)result[2];
  *(volatile uint8_t *)(a3 + 216) = (uint8_t)result;
  return result;
}



// parse_scan_report @ 0x130e58
/* luna: Finds the Country Information Element, converts the supplied band and frequency to a channel number, and stores the matching subband's maximum transmi */
volatile uint8_t * parse_scan_report(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  int target_channel; // r5
  int frequency_mhz; // r3
  char channel_step; // r6
  int triplet_offset; // r2
  int first_channel; // r3
  int channel_offset; // r1
  int v11; // zf
  uint8_t v12[5]; // [sp+7h] [bp-5h] BYREF

  result = buf_calc_4(a1, a2, v12);
  if ( result )
  {
    target_channel = *(volatile uint8_t *)(a3 + 164);
    if ( *(volatile uint8_t *)(a3 + 164) )
    {
      if ( target_channel == 1 && (uint16_t)(*(volatile uint16_t *)(a3 + 166) - 5005) <= 0x370u )
      {
        target_channel = (uint8_t)((unsigned int)(((unsigned int)dword_130F24
                                             * (uint64_t)((unsigned int)*(volatile uint16_t *)(a3 + 166) - 5000)) >> 32) >> 2);
        channel_step = 4;
      }
      else
      {
        target_channel = 0;
        channel_step = 4;
      }
    }
    else
    {
      frequency_mhz = *(volatile uint16_t *)(a3 + 166);
      if ( (unsigned int)(frequency_mhz - 2412) > 0x48 )
      {
        channel_step = 1;
      }
      else
      {
        target_channel = frequency_mhz == 2484
           ? 14
           : (uint8_t)((unsigned int)(((unsigned int)dword_130F24 * (uint64_t)(unsigned int)(frequency_mhz - 2407)) >> 32) >> 2);
        channel_step = 1;
      }
    }
    v12[0] += 2;
    if ( v12[0] > 7u )
    {
      triplet_offset = 5;
      do
      {
        first_channel = (uint8_t)result[triplet_offset];
        if ( result[triplet_offset + 1] )
        {
          if ( first_channel == target_channel )
          {
LABEL_7:
            *(volatile uint8_t *)(a3 + 172) = result[triplet_offset + 2];
            return result;
          }
          channel_offset = 0;
          while ( 1 )
          {
            v11 = channel_offset == (uint8_t)(result[triplet_offset + 1] - 1);
            first_channel = (uint8_t)(first_channel + channel_step);
            ++channel_offset;
            if ( v11 )
              break;
            if ( first_channel == target_channel )
              goto LABEL_7;
          }
        }
        triplet_offset = (uint8_t)(triplet_offset + 3);
      }
      while ( v12[0] > triplet_offset + 2 );
    }
  }
  return result;
}



// extract_le_u16 @ 0x130f28
volatile uint8_t * extract_le_u16(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0

  result = check_one_12dca0(a1, a2);
  if ( result )
  {
    *(volatile uint16_t *)(a3 + 228) = result[2] | (result[3] << 8);
    *(volatile uint8_t *)(a3 + 230) = result[4];
  }
  else
  {
    *(volatile uint8_t *)(a3 + 230) = 0;
    *(volatile uint16_t *)(a3 + 228) = 0;
  }
  return result;
}



// rx_packet_handler_2 @ 0x130f50
int rx_packet_handler_2(volatile uint8_t *a1, int a2, volatile uint8_t *a3, int a4) {
  unsigned int v8; // r7
  unsigned int v9; // r0
  volatile uint8_t *v10; // r8
  volatile uint8_t *v11; // r9
  volatile uint8_t *v12; // r0
  int v13; // r5
  unsigned int v14; // r3
  unsigned int v15; // r2
  int16_t v16; // r3
  int v18; // r2
  int v19; // [sp+7h] [bp-1h] BYREF

  v8 = (unsigned int)check_one_12da38(a1, a2);
  v9 = (unsigned int)check_one_12da78(a1, a2);
  if ( !(v8 | v9) )
    return 0;
  v10 = (volatile uint8_t *)v9;
  v11 = check_one_12dab8(a1, a2, &v19);
  if ( v11 )
  {
    if ( !v19 )
      return 0;
  }
  v12 = check_one_12dafc(a1, a2, &v19);
  if ( v12 )
  {
    if ( !v19 )
      return 0;
  }
  if ( v8 )
  {
    v13 = *(volatile uint8_t *)(v8 + 4);
    *a3 = *(volatile uint8_t *)(v8 + 2);
    v14 = *(volatile uint8_t *)(v8 + 3);
  }
  else
  {
    v13 = (uint8_t)v10[5];
    *a3 = v10[2];
    v14 = (uint8_t)v10[4];
  }
  if ( !v13 )
    v13 = 2;
  *(volatile uint8_t *)a4 = v14 > 0xE;
  v15 = v14 - 1;
  if ( v14 > 0xE )
  {
    if ( (uint8_t)v15 <= 0xB0u )
    {
      v16 = 5 * v14 + 5000;
      goto LABEL_17;
    }
    goto LABEL_23;
  }
  if ( v15 > 0xD )
  {
LABEL_23:
    v16 = 0;
    goto LABEL_17;
  }
  if ( v14 == 14 )
    v16 = 2484;
  else
    v16 = 5 * v14 + 2407;
LABEL_17:
  *(volatile uint16_t *)(a4 + 2) = v16;
  *(volatile uint16_t *)(a4 + 4) = v16;
  *(volatile uint8_t *)(a4 + 1) = 0;
  *(volatile uint16_t *)(a4 + 6) = 0;
  if ( v11 )
  {
    v18 = (uint8_t)v11[2];
    if ( v18 == 1 )
    {
      *(volatile uint16_t *)(a4 + 4) = v16 + 10;
      *(volatile uint8_t *)(a4 + 1) = 1;
    }
    else if ( v18 == 3 )
    {
      *(volatile uint16_t *)(a4 + 4) = v16 - 10;
      *(volatile uint8_t *)(a4 + 1) = 1;
      if ( !v12 )
        goto LABEL_21;
LABEL_25:
      null_sub(v12[2], v12[3], v12[4], (void *)(uintptr_t)(a4));
      goto LABEL_21;
    }
  }
  if ( v12 )
    goto LABEL_25;
LABEL_21:
  rx_parse_header_1((void *)(uintptr_t)(a4));
  return v13;
}



// ll_get_conn_state @ 0x13105c
volatile uint8_t * ll_get_conn_state(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
  volatile uint8_t *result; // r0
  uint8_t v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r5
  uint64_t v10; // r2

  result = log_format_message(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = result[8];
    if ( *(volatile uint8_t *)(a3 + 18) != (v7 & 0xF) )
    {
      *a4 = 1;
      *(volatile uint8_t *)(a3 + 16) = v7;
      *(volatile uint8_t *)(a3 + 18) = v7 & 0xF;
      v8 = *(volatile uint32_t *)(result + 14);
      v9 = *(volatile uint32_t *)(result + 10);
      v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint32_t *)(result + 22) & 0xF | (16 * (*(volatile uint32_t *)(result + 22) >> 8))) << 32);
      v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(result + 18) & 0xF | (16 * (*(volatile uint32_t *)(result + 18) >> 8))) & 0xFFFFFFFFu);
      *(volatile uint8_t *)(a3 + 17) = ((v8 & 0x10) != 0)
                          | (*(volatile uint32_t *)(result + 18) >> 2) & 4
                          | (*(volatile uint32_t *)(result + 22) >> 1) & 8
                          | (v9 >> 3) & 2;
      *(volatile uint32_t *)a3 = v8 & 0xF | (16 * (v8 >> 8));
      *(volatile uint32_t *)(a3 + 4) = v9 & 0xF | (16 * (v9 >> 8));
      *(volatile uint64_t *)(a3 + 8) = v10;
    }
    return (volatile uint8_t *)1;
  }
  else
  {
    *(volatile uint32_t *)a3 = 2627;
    *(volatile uint32_t *)(a3 + 4) = 2627;
    *(volatile uint32_t *)(a3 + 8) = 2627;
    *(volatile uint32_t *)(a3 + 12) = 2627;
  }
  return result;
}



// ll_get_conn_interval @ 0x131100
int ll_get_conn_interval(volatile uint8_t *a1, int a2, int a3) {
  int result; // r0
  int v5; // r3
  int16_t v6; // r3
  int16_t v7; // r2

  result = (int)check_one_12dd08(a1, a2);
  if ( result )
  {
    *(volatile uint16_t *)a3 = *(volatile uint8_t *)(result + 2) | (*(volatile uint8_t *)(result + 3) << 8);
    *(volatile uint8_t *)(a3 + 2) = *(volatile uint8_t *)(result + 4);
    v5 = a3 + 2;
    do
    {
      *(volatile uint8_t *)(v5 + 1) = *(volatile uint8_t *)(result + v5 + 3 - a3);
      ++v5;
    }
    while ( v5 != a3 + 18 );
    v6 = *(volatile uint8_t *)(result + 21);
    v7 = *(volatile uint8_t *)(result + 22);
    *(volatile uint32_t *)(a3 + 24) = *(volatile uint16_t *)(result + 23);
    *(volatile uint16_t *)(a3 + 20) = v6 | (v7 << 8);
    *(volatile uint8_t *)(a3 + 28) = *(volatile uint8_t *)(result + 27);
    return 1;
  }
  return result;
}



// ll_get_conn_evt_cnt @ 0x131148
volatile uint8_t * ll_get_conn_evt_cnt(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  int16_t v5; // r1
  int16_t v6; // r6
  int16_t v7; // r5
  int16_t v8; // r2
  int v9; // r7
  int16_t v10; // r3
  int16_t v11; // r0

  result = check_one_12de50(a1, a2);
  if ( result )
  {
    v5 = result[10];
    v6 = result[11];
    v7 = result[6] | (result[7] << 8);
    v8 = result[8] | (result[9] << 8);
    v9 = *(volatile uint32_t *)(result + 2);
    v10 = result[12];
    v11 = result[13];
    *(volatile uint32_t *)a3 = v9;
    *(volatile uint16_t *)(a3 + 4) = v7;
    *(volatile uint16_t *)(a3 + 8) = v5 | (v6 << 8);
    *(volatile uint16_t *)(a3 + 6) = v8;
    *(volatile uint16_t *)(a3 + 10) = v10 | (v11 << 8);
    return (volatile uint8_t *)1;
  }
  return result;
}



// ll_get_channel @ 0x131184
int ll_get_channel(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *v4; // r0
  unsigned int v5; // r6
  volatile uint8_t *v6; // r4
  int v7; // r3
  int v8; // r1
  int16_t v9; // r3
  int v10; // r2
  volatile uint8_t *v11; // r3
  volatile uint8_t *v12; // r1
  int16_t v13; // r4
  int16_t v14; // r0
  int16_t v15; // r1
  int16_t v16; // r3
  uint8_t v18[5]; // [sp+7h] [bp-5h] BYREF

  v4 = copy_config_data(a1, a2, v18);
  if ( !v4 )
    return 0;
  v5 = (unsigned int)&v4[v18[0] + 3];
  v6 = &v4[4 - a3];
  v7 = a3 - 1;
  do
  {
    *(volatile uint8_t *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 5 );
  do
  {
    *(volatile uint8_t *)(v7 + 1) = v6[v7];
    ++v7;
  }
  while ( v7 != a3 + 16 );
  v8 = *(volatile uint8_t *)(a3 + 6);
  v9 = v4[22] | (v4[23] << 8);
  *(volatile uint16_t *)(a3 + 18) = v4[20] | (v4[21] << 8);
  v10 = v8 >> 1;
  *(volatile uint16_t *)(a3 + 20) = v9;
  v11 = v4 + 24;
  if ( (v8 & 8) != 0 )
  {
    v12 = v4 + 28;
    if ( (unsigned int)(v4 + 28) <= v5 )
    {
      v13 = v4[24] | (v4[25] << 8);
      v14 = v4[26] | (v4[27] << 8);
      *(volatile uint16_t *)(a3 + 22) = v13;
      v11 = v12;
      *(volatile uint16_t *)(a3 + 24) = v14;
      goto LABEL_8;
    }
    return 0;
  }
LABEL_8:
  if ( (v10 & 8) != 0 )
  {
    if ( (unsigned int)(v11 + 4) <= v5 )
    {
      v15 = *v11 | (v11[1] << 8);
      v16 = v11[2] | (v11[3] << 8);
      *(volatile uint16_t *)(a3 + 26) = v15;
      *(volatile uint16_t *)(a3 + 28) = v16;
      return 1;
    }
    return 0;
  }
  return 1;
}



// ll_get_access_addr @ 0x131230
/* luna: Parses the supplied link-layer frame and stores its 32-bit access address at offset 220, or an invalid sentinel if parsing fails. */
volatile uint8_t * ll_get_access_addr(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = parse_frame_0x24(a1, a2, &v5);
  if ( result )
    *(volatile uint32_t *)(a3 + 220) = *(volatile uint32_t *)(result + 3);
  else
    *(volatile uint32_t *)(a3 + 220) = 0x80000000;
  return result;
}



// ll_get_adv_state @ 0x131258
int ll_get_adv_state(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
  int result; // r0
  char v7; // r2
  int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3

  result = (int)parse_frame_0x26(a1, a2);
  *a4 = 0;
  if ( result )
  {
    v7 = *(volatile uint8_t *)(result + 3);
    if ( *(volatile uint8_t *)(a3 + 17) == (v7 & 0xF) )
    {
      return 1;
    }
    else
    {
      *a4 = 1;
      *(volatile uint8_t *)(a3 + 16) = v7;
      *(volatile uint8_t *)(a3 + 17) = v7 & 0xF;
      v8 = *(volatile uint16_t *)(result + 8);
      v9 = *(volatile uint16_t *)(result + 11);
      v10 = *(volatile uint16_t *)(result + 14);
      *(volatile uint32_t *)(a3 + 4) = *(volatile uint8_t *)(result + 4) | (*(volatile uint16_t *)(result + 5) << 8);
      *(volatile uint32_t *)a3 = *(volatile uint8_t *)(result + 7) | (v8 << 8);
      *(volatile uint32_t *)(a3 + 8) = *(volatile uint8_t *)(result + 10) | (v9 << 8);
      v11 = *(volatile uint8_t *)(result + 13) | (v10 << 8);
      result = 1;
      *(volatile uint32_t *)(a3 + 12) = v11;
    }
  }
  return result;
}



// ll_get_phy_tx_power @ 0x1312b0
volatile uint8_t * ll_get_phy_tx_power(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  unsigned int v5; // r3

  result = parse_frame_0x25(a1, a2);
  if ( result )
  {
    v5 = result[3];
    *a3 = v5 & 7;
    a3[1] = (v5 >> 3) & 7;
    return (volatile uint8_t *)1;
  }
  else
  {
    *a3 = 3;
    a3[1] = 5;
  }
  return result;
}



// ke_event_lookup @ 0x1312d8
int ke_event_lookup(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r1
  volatile int *v8; // r3
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r2
  volatile uint32_t *v12; // r0
  volatile uint32_t *v13; // r7
  int v14; // r4
  volatile uint32_t *v15; // r2
  volatile unsigned int v16; // r3
  int v17; // r1
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r0
  int v20; // r4
  volatile uint32_t *v21; // r7
  volatile uint8_t *v22; // r2
  volatile int *v23; // r4
  volatile unsigned int v24; // r3
  int v25; // r1
  volatile uint32_t *v26; // r0
  volatile uint32_t *v27; // r2
  volatile uint32_t *v28; // r0
  volatile uint32_t *v29; // r4
  volatile uint32_t *v30; // r2
  volatile uint32_t *v31; // r7
  volatile uint32_t *v32; // r0
  volatile uint32_t *v33; // r3
  volatile unsigned int *v34; // r1
  volatile uint32_t *v35; // r2

  check_status_bits(2, "set lp:%d, disable_filter=%d\n", *a2, a2[1]);
  v7 = *a2;
  v8 = (volatile int *)off_1314C8;
  **(volatile uint8_t **)off_1314C4 = v7;
  *((volatile uint8_t *)v8 + 412) = a2[1];
  if ( v7 == 1 )
  {
    if ( *((volatile uint8_t *)v8 + 189) )
    {
      v27 = (void *)(uintptr_t)(off_1314F8);
      v28 = (void *)(uintptr_t)(off_1314D8);
      *(volatile uint32_t *)off_1314D4 &= ~0x2000000u;
      *v27 |= 0x200000u;
      *v28 = 36;
    }
    else
    {
      v18 = (void *)(uintptr_t)(off_1314D4);
      v19 = (void *)(uintptr_t)(off_1314EC);
      v20 = *((volatile uint8_t *)off_1314EC + 18);
      v21 = (void *)(uintptr_t)(off_1314D8);
      *(volatile uint32_t *)off_1314D4 |= 0x2000000u;
      *v21 = 4;
      if ( !v20 )
      {
        *(volatile uint32_t *)off_1314F0 = 1;
        v18[8202] &= 0xFFFBFFFE;
      }
      v22 = (void *)(uintptr_t)(off_1314DC);
      if ( *((volatile uint8_t *)off_1314DC + 28) )
      {
        if ( !*((volatile uint8_t *)off_1314DC + 29) )
        {
          v23 = (volatile int *)v19[2];
          if ( v23 )
          {
            while ( !*((volatile uint8_t *)v23 + 108) || *((volatile uint8_t *)v23 + 106) )
            {
              v23 = (volatile int *)*v23;
              if ( !v23 )
                goto LABEL_21;
            }
            v24 = (*(volatile uint32_t *)0x40501010u);
            v25 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1314E4 + 54);
            v26 = (volatile uint32_t *)dword_1314F4;
            *((volatile uint32_t *)off_1314DC + 5) = (int)(uintptr_t)(v23);
            v22[29] = 4;
            unknown_worker(v26, v25 + v24);
            v23[1] |= 0x200u;
          }
        }
      }
    }
LABEL_21:
    *((volatile uint32_t *)off_1314E0 + 20) |= 0x40000u;
  }
  else if ( v7 == 2 )
  {
    v10 = (void *)(uintptr_t)(off_1314D0);
    v11 = (void *)(uintptr_t)(off_1314D4);
    v12 = (void *)(uintptr_t)(off_1314D8);
    v13 = (void *)(uintptr_t)(off_1314DC);
    *(volatile uint32_t *)off_1314D0 |= 0x10000u;
    v14 = v13[8];
    *v11 &= ~0x2000000u;
    *v12 = 63;
    v15 = (void *)(uintptr_t)(off_1314E0);
    v10[10] &= ~1u;
    v15[20] &= ~0x40000u;
    if ( v14 && *(volatile uint8_t *)(v14 + 108) )
    {
      v16 = (*(volatile uint32_t *)0x40501010u);
      v17 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1314E4 + 54);
      v13[5] = v14;
      *((volatile uint8_t *)v13 + 29) = 4;
      unknown_worker(v13 + 3, v17 + v16);
      *(volatile uint32_t *)(v14 + 4) |= 0x200u;
      fault_handler((int)(uintptr_t)((volatile uint32_t *)(v14 + 24)));
    }
  }
  else if ( !v7 && **(volatile uint8_t **)off_1314CC == 3 )
  {
    v29 = (void *)(uintptr_t)(off_1314D0);
    v30 = (void *)(uintptr_t)(off_1314D4);
    v31 = (void *)(uintptr_t)(off_1314D8);
    *(volatile uint32_t *)off_1314D0 &= ~0x10000u;
    *v30 |= 0x2000000u;
    *v31 = 0;
    v32 = (void *)(uintptr_t)(off_1314E0);
    v29[10] |= 1u;
    v32[20] |= 0x40000u;
    if ( (*v30 & 4) != 0 )
    {
      if ( *((volatile uint8_t *)v8 + 190) )
      {
        v33 = (void *)(uintptr_t)(off_131500);
        *(volatile uint32_t *)off_1314FC &= ~0x200u;
        *v33 &= ~1u;
        *v33 &= ~0x80u;
      }
      *(volatile uint32_t *)off_131504 = 48;
      fatal_error_handler();
      wlc_core_state();
    }
    if ( !*((volatile uint8_t *)off_131508 + 36) )
    {
      v34 = (volatile unsigned int *)off_131510;
      v35 = (void *)(uintptr_t)(off_131514);
      *(volatile uint32_t *)off_13150C &= ~0x40000u;
      *v34 = *v34 & 0xFFFFFFF0 | 8;
      *v35 |= 1u;
    }
  }
  ke_msg_send_no_param(5142, a4, a3);
  return 0;
}


