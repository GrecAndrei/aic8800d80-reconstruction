// rf_calibration_proc @ 0x130030
/* luna: Drains queued console commands, validates their argument counts against command descriptors, invokes the matching handlers, and releases each processe */
int rf_calibration_proc(int a1, int a2) {
  volatile int *lock_depth_ptr; // r6
  int v3; // r0
  int result; // r0
  int queued_command; // r4
  int v6; // r3
  int v7; // r2
  volatile uint8_t **command_table; // r7
  int argument_count; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  volatile uint8_t **command_entry; // r0
  int v14; // r0
  volatile uint8_t *a1a[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_130120 = 1;
  }
  lock_depth_ptr = (volatile int *)off_130124;
  v3 = dword_130128;
  ++*(volatile uint32_t *)off_130124;
  result = (int)list_pop(v3);
  queued_command = result;
  if ( *lock_depth_ptr )
  {
    v6 = *lock_depth_ptr - 1;
    v7 = *(volatile uint32_t *)off_130120;
    *lock_depth_ptr = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  if ( result )
  {
    command_table = (volatile uint8_t **)off_13012C;
    do
    {
      argument_count = skip_leading_spaces((volatile uint8_t *)(queued_command + 4), (int)a1a);
      if ( argument_count )
      {
        command_entry = (void *)(split_on_dot((int)(uintptr_t)(a1a[0]), (void *)(command_table), 7));
        if ( command_entry )
        {
          if ( *((volatile int16_t *)command_entry + 5) < argument_count || *((volatile int16_t *)command_entry + 4) > argument_count )
          {
            debug_printf(aUsageSS, *command_entry, command_entry[1]);
          }
          else
          {
            v14 = ((int ( *)(int, volatile uint8_t **))command_entry[3])(argument_count, a1a);
            if ( v14 )
              debug_printf("Command fail, ret=%d\r\n", v14);
          }
        }
        else
        {
          debug_printf("Unknown command '%s'\r\n", (const volatile char *)a1a[0]);
        }
      }
      else
      {
        radio_tx_write_string(aNoCommand);
      }
      radio_tx_write_string(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_130120 = 1;
      }
      v10 = dword_130138;
      ++*lock_depth_ptr;
      wlan_ioctl_handler_1(v10, (volatile uint32_t *)queued_command);
      result = (int)list_pop(dword_130128);
      queued_command = result;
      if ( *lock_depth_ptr )
      {
        v11 = *lock_depth_ptr - 1;
        v12 = *(volatile uint32_t *)off_130120;
        *lock_depth_ptr = v11;
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


// mmio_register_access @ 0x130148
void mmio_register_access() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r0

  v0 = (void *)(uintptr_t)(off_13017C);
  while ( (*v0 & 1) == 0 )
  {
    if ( (*v0 & 0xF) == 4 )
    {
      v1 = radio_rx_read_byte();
      if ( lock_with_timeout(v1) > 0 )
      {
        if ( *(volatile uint8_t *)off_130180 )
          ((int (*)())rf_calibration_proc)();
        return;
      }
    }
  }
}



// compare_calibration_levels @ 0x130184
/* luna: Moves the current XTAL capacitor value one step toward its target and logs the adjustment. */
unsigned int compare_calibration_levels() {
  volatile uint8_t *calibration_state; // r4
  unsigned int result; // r0
  unsigned int target_xtal_cap; // r3
  uint8_t adjusted_xtal_cap; // r0

  calibration_state = (volatile uint8_t *)off_1301B0;
  result = *((volatile uint8_t *)off_1301B0 + 6);
  target_xtal_cap = *((volatile uint8_t *)off_1301B0 + 5);
  if ( result != target_xtal_cap )
  {
    if ( result >= target_xtal_cap )
      adjusted_xtal_cap = result - 1;
    else
      adjusted_xtal_cap = result + 1;
    *((volatile uint8_t *)off_1301B0 + 6) = adjusted_xtal_cap;
    padding_data(adjusted_xtal_cap);
    return alloc_tx_event("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", calibration_state[5], calibration_state[6]);
  }
  return result;
}


// rf_temp_compensation @ 0x1301b8
int rf_temp_compensation(int a1) {
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

  v1 = (void *)(uintptr_t)(off_130224);
  v2 = *((volatile char *)off_130224 + 2) + 7;
  v3 = a1 + 7;
  v4 = *(volatile uint8_t *)(dword_13022C + v2);
  v5 = *(volatile uint8_t *)(dword_130228 + v2 + 16);
  v6 = *(volatile uint8_t *)(dword_130228 + v2 + 32);
  v7 = *(volatile uint8_t *)(dword_130228 + v3 + 16);
  v8 = dword_13022C + v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_130228 + v3) - *(volatile uint8_t *)(dword_130228 + v2)) & 0xFFu);
  v9 = dword_13022C + v3;
  v10 = *(volatile uint8_t *)(dword_130228 + v3 + 32);
  v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(dword_13022C + v3)) & 0xFFu);
  v11 = *(volatile uint8_t *)(v8 + 16);
  v12 = *(volatile uint8_t *)(v9 + 16);
  v8 = (v8 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v8 + 32)) & 0xFFu);
  *((volatile uint8_t *)off_130224 + 8) = v2;
  v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v9 + 32) - v8) & 0xFFu);
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return rf_read_cal_values();
}



// fw_version_get @ 0x130230
int fw_version_get() {
  return hw_block_reset();
}



// rf_power_adjust @ 0x130234
int rf_power_adjust() {
  if ( *((volatile uint8_t *)off_13025C + 1) )
    return *((volatile char *)off_13025C + 3);
  hw_block_reset();
  return (int)COERCE_FLOAT(hw_poll_status());
}



// rf_tx_power_lookup @ 0x130260
/* luna: Logs the current temperature-compensation, crystal-capacitance, RF offset, and RF control settings. */
int rf_tx_power_lookup() {
  volatile uint8_t *calibration_state; // r4
  int settings_enabled; // r4
  int active_state; // r0
  int timer_setting; // [sp+14h] [bp-4h]

  calibration_state = (volatile uint8_t *)off_1302D8;
  alloc_tx_event(
    "temp_comp: init=%d, en=%d, lvl_cal=%d, t_last=%d C\n",
    *(volatile char *)off_1302D8,
    *((volatile char *)off_1302D8 + 1),
    *((volatile char *)off_1302D8 + 2),
    *((volatile char *)off_1302D8 + 3));
  alloc_tx_event("xtal_cap: cal=0x%x, tgt=0x%x, cur=0x%x\n", calibration_state[4], calibration_state[5], calibration_state[6]);
  alloc_tx_event(
    "ofst2x: 2G4=%d,%d,%d; 5G=%d,%d,%d\n",
    (char)calibration_state[8],
    (char)calibration_state[9],
    (char)calibration_state[10],
    (char)calibration_state[11],
    (char)calibration_state[12],
    (char)calibration_state[13]);
  settings_enabled = HIBYTE(((volatile uint32_t *)(uintptr_t)off_1302E8)[90]);
  timer_setting = ((volatile uint32_t *)(uintptr_t)off_1302E8)[91];
  active_state = rf_get_state_1(1070, 1);
  return alloc_tx_event("settings: en=%d, tmr=%d, act=%d\n", settings_enabled, timer_setting, active_state);
}


// check_frame_len @ 0x1302f0
int check_frame_len(int a1) {
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_13036C * (uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((uint64_t)((int32_t)dword_130360 * (int64_t)(int32_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((volatile uint8_t *)off_130364 + 4)
     + (char)(*(volatile uint8_t *)(dword_130368 + v1 + 7) - *(volatile uint8_t *)(dword_130368 + *((volatile char *)off_130364 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  *((volatile uint8_t *)off_130364 + 5) = v2;
  rf_temp_compensation(v1);
  result = is_id_lt_10(9u, 4u);
  if ( result )
    return rf_tx_power_lookup();
  return result;
}



// rf_timer_toggle_start @ 0x130370
/* luna: Reads and logs the current RF temperature, updates the cached value and triggers a check when it changes by more than four degrees, then compares cali */
int rf_timer_toggle_start() {
  int current_temperature; // s15
  int temperature_delta; // r3

  current_temperature = (int)COERCE_FLOAT(hw_poll_status());
  alloc_tx_event("\x9D\x89t=%d C\n", current_temperature);
  temperature_delta = (char)current_temperature - *((volatile char *)off_1303B4 + 3);
  if ( temperature_delta < 0 )
    temperature_delta = *((volatile char *)off_1303B4 + 3) - (char)current_temperature;
  if ( temperature_delta > 4 )
  {
    *((volatile uint8_t *)off_1303B4 + 3) = current_temperature;
    check_frame_len((char)current_temperature);
  }
  return compare_calibration_levels();
}


// read_global_signed_flag @ 0x1303b8
void read_global_signed_flag(int a1, int a2) {
  volatile uint8_t *v2; // r4
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3
  char v6; // r0
  int v7; // r1
  char v8; // r3
  struct __attribute__((packed)) { uint8_t a1a; // [sp+3h] [bp-Dh] BYREF
  int v10; // [sp+4h] [bp-Ch] BYREF
  int v11; // [sp+8h] [bp-8h] BYREF
  int v12; // [sp+Ch] [bp-4h] BYREF
  } _frame;
  v2 = (void *)(uintptr_t)(off_130468);
  v3 = *(volatile char *)off_130468;
  if ( *(volatile uint8_t *)off_130468 )
    return;
  _frame.a1a = *(volatile uint8_t *)off_130468;
  v4 = *(volatile uint32_t *)off_13046C;
  _frame.v10 = v3;
  if ( (v4 & 0x2000000) != 0 )
  {
    rf_cmd_6_read(&_frame.a1a);
    rf_cmd_10(&_frame.v10);
    goto LABEL_4;
  }
  _frame.v11 = 0;
  _frame.v12 = 0;
  if ( !send_smc_cmd_2((int)&_frame.v11) )
    _frame.a1a = _frame.v11;
  if ( send_smc_cmd_0x80((int)&_frame.v12) )
  {
LABEL_4:
    v5 = _frame.a1a;
    if ( _frame.a1a )
      goto LABEL_5;
    goto LABEL_19;
  }
  _frame.v10 = (char)_frame.v12;
  v5 = _frame.a1a;
  if ( _frame.a1a )
  {
LABEL_5:
    if ( v5 > 0x1F )
    {
      v5 = (v5 & ~0xFFu) | ((uint8_t)(31) & 0xFFu);
      _frame.a1a = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  v5 = (v5 & ~0xFFu) | ((uint8_t)(15) & 0xFFu);
LABEL_7:
  v2[4] = v5;
  v6 = rf_get_status();
  v7 = _frame.v10;
  v2[6] = v6;
  if ( v7 )
  {
    if ( v7 < -7 )
    {
      v8 = -7;
      _frame.v10 = -7;
      v7 = -7;
    }
    else if ( v7 > 8 )
    {
      v8 = 8;
      _frame.v10 = 8;
      v7 = 8;
    }
    else
    {
      v8 = v7;
    }
    v2[2] = v8;
    alloc_tx_event("\x9D\x89temp_lvl_calibed=%d\n", v7);
  }
  v2[3] = 0x80;
  *v2 = 1;
}


// set_flag_send_event_42e @ 0x130474
/* luna: Marks the xtal-cap adjustment loop active, applies the configured target when the cached RF value differs, and schedules the next check. */
int set_flag_send_event_42e() {
  volatile uint8_t *xtal_cap_state; // r4
  int result; // r0
  int target_xtal_cap; // r0
  int v3; // r2

  xtal_cap_state = (void *)(uintptr_t)(off_1304CC);
  *((volatile uint8_t *)off_1304CC + 1) = 1;
  result = rf_get_state_1(1070, 1);
  if ( !result )
  {
    hw_block_reset();
    xtal_cap_state[6] = rf_get_status();
    rf_timer_toggle_start();
    target_xtal_cap = (uint8_t)xtal_cap_state[5];
    if ( (uint8_t)xtal_cap_state[6] != target_xtal_cap )
    {
      padding_data(target_xtal_cap);
      v3 = (uint8_t)xtal_cap_state[5];
      xtal_cap_state[6] = v3;
      alloc_tx_event("\x9D\x89""adjust xtal_cap: tgt=0x%x, cur=0x%x\n", v3, v3);
    }
    return ke_event_handler(1070, 1, 1000 * ((volatile uint32_t *)(uintptr_t)off_1304D0)[91]);
  }
  return result;
}


// clear_flag_send_event_42e @ 0x1304d8
int clear_flag_send_event_42e() {
  int result; // r0

  *((volatile uint8_t *)off_1304FC + 1) = 0;
  result = rf_get_state_1(1070, 1);
  if ( result )
    return invalid_handler_12c5fc(1070, 1);
  return result;
}



// write_dash_header @ 0x130500
int write_dash_header(volatile int *a1) {
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

  v1 = (volatile char *)off_130578;
  v2 = *((volatile uint16_t *)off_130578 + 6);
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
  v7 = (volatile char *)dword_13057C;
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



// write_hash_header @ 0x130580
volatile char * write_hash_header(int a1) {
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

  v1 = dword_13064C;
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
  v7 = dword_130650;
  v8 = dword_130650 - 65;
  v9 = dword_130650 + 11;
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
    v18 = ((int (*)())phy_get_rate_code)();
    v19 = v18 + 1 + *(volatile uint8_t *)(v8 + 0x175) * (v18 + 1);
    v20 = (uint8_t)((unsigned int)(6 * v19 + 14) >> 3);
    if ( (uint8_t)((unsigned int)(6 * v19 + 14) >> 3) )
    {
      v21 = dword_130654;
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



// write_bf_header @ 0x130658
/* luna: Writes a 14-byte BF header and its template fields at the current output cursor, advances the cursor, and returns 14. */
int write_bf_header(int a1) {
  volatile uint32_t *header_template; // r1
  volatile uint16_t *header_out; // r2
  int16_t v4; // r6
  int16_t v5; // r5
  int16_t v6; // r4

  header_template = (void *)(uintptr_t)(off_130690);
  **(volatile uint8_t **)a1 = -65;
  *(volatile uint8_t *)(*(volatile uint32_t *)a1 + 1) = 12;
  *(volatile uint32_t *)(*(volatile uint32_t *)a1 + 2) = header_template[12];
  header_out = *(volatile uint16_t **)a1;
  v4 = *((volatile uint16_t *)header_template + 26);
  v5 = *((volatile uint16_t *)header_template + 27);
  v6 = *((volatile uint16_t *)header_template + 28);
  header_out[6] = *((volatile uint16_t *)header_template + 29);
  header_out[3] = v4;
  header_out[4] = v5;
  header_out[5] = v6;
  *(volatile uint32_t *)a1 = (int)(uintptr_t)(header_out + 7);
  return 14;
}



// write_f5p_header @ 0x130694
/* luna: Writes the seven-byte `F5p\0\0\0\0` header at the output cursor, advances the cursor, and returns 7. */
int write_f5p_header(int a1) {
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



// store_four_halfwords @ 0x1306c4
int store_four_halfwords(int a1, int16_t a2, int16_t a3, int16_t a4, volatile char *a5) {
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



// store_half_return_two @ 0x1306f8
/* luna: Writes a 16-bit value to the destination and returns the number of bytes written (2). */
int store_half_return_two(volatile uint16_t *a1, int16_t a2) {
  *a1 = a2;
  return 2;
}



// ampdu_negotiate_params @ 0x130700
int ampdu_negotiate_params(volatile uint8_t *a1, int a2, volatile uint16_t *a3, int a4, volatile uint32_t *a5, volatile uint16_t *a6, int a7) {
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
  int16_t v82; // r0
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
  v12 = get_phy_config_entry(a4);
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
    v67 = *((volatile uint8_t *)off_130B68 + 371);
    _frame.v87 = 4;
    v68 = (volatile char *)off_130B68 + 202;
  }
  else
  {
    v67 = *((volatile uint8_t *)off_130B68 + 370);
    _frame.v87 = 1;
    v68 = (volatile char *)off_130B68 + 118;
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
          v75 = (unsigned int)(((unsigned int)dword_130B78 * (uint64_t)(unsigned int)(v80 - 8)) >> 32) >> 2;
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
        v75 = (unsigned int)(((unsigned int)dword_130B78 * (uint64_t)(unsigned int)(v74 - 2407)) >> 32) >> 2;
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
  v34 = write_f5p_header((int)&_frame.a1a);
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
    v42 = ((volatile uint32_t *)(uintptr_t)off_130B64)[1];
    v43 = ((volatile uint32_t *)(uintptr_t)off_130B64)[2];
    _frame.result[0] = ((volatile uint32_t *)(uintptr_t)off_130B64)[0];
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
  if ( (v38 & 2) != 0 && (*((volatile uint8_t *)off_130B68 + 374) & 1) != 0 )
  {
    v82 = write_dash_header(&_frame.a1a);
    v41 = *(volatile uint32_t *)(a2 + 224);
    v40 = (uint16_t)(v82 + v40);
  }
  if ( (v41 & 4) != 0 )
  {
    v48 = (volatile uint16_t *)off_130B68;
    v49 = *((volatile uint8_t *)off_130B68 + 374);
    if ( (v49 & 2) != 0 )
    {
      v58 = *((volatile uint8_t *)off_130B68 + 373);
      if ( (*(volatile uint8_t *)off_130B74 & 8) != 0
        || (alloc_tx_event(aAssocReq8800d4, v49 << 30), *((volatile uint8_t *)v48 + 373) <= 1u) )
      {
        v59 = v40 + write_bf_header((int)&_frame.a1a);
        v60 = phy_get_rate_code(v48[28]);
        if ( v58 == 4 )
          v58 = (v58 & ~0xFFu) | ((uint8_t)(3) & 0xFFu);
      }
      else
      {
        v59 = v40 + write_bf_header((int)&_frame.a1a);
        v60 = phy_get_rate_code(v48[28]);
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
  if ( (v41 & 8) != 0 && (*((volatile uint8_t *)off_130B68 + 374) & 4) != 0 )
    v40 = (uint16_t)((uint16_t)write_hash_header((int)&_frame.a1a) + v40);
  v50 = test_arg2_one_12db60(v15, v10);
  rf_set_antenna_cfg((void *)(uintptr_t)((int)v15), v10, _frame.a3a, (int)_frame.result);
  if ( *(volatile uint16_t *)(a2 + 228)
    && (!v50 && (v51 = _frame.v95 << 26, (_frame.v95 & 0x20) != 0) || (*(volatile uint32_t *)(*((volatile uint32_t *)off_130B70 + 4) + 48) & 0x40) != 0) )
  {
    check_feature_flag(256, aAddMde, v51);
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


// build_addba_request @ 0x130bd4
/* luna: Serializes a 9-byte 802.11 ADDBA Request action body from block-ack parameters and returns its length. */
int build_addba_request(int a1, int a2) {
  int16_t tid; // r3
  int16_t ba_policy; // r4
  int16_t buffer_size; // r2

  *(volatile uint8_t *)a1 = 3;
  *(volatile uint8_t *)(a1 + 1) = 0;
  *(volatile uint8_t *)(a1 + 2) = *(volatile uint8_t *)(a2 + 23);
  tid = *(volatile uint8_t *)(a2 + 22);
  ba_policy = *(volatile uint8_t *)(a2 + 18);
  buffer_size = *(volatile uint16_t *)(a2 + 20);
  *(volatile uint16_t *)(a1 + 5) = *(volatile uint16_t *)(a2 + 14);
  *(volatile uint16_t *)(a1 + 3) = (4 * tid) | (2 * ba_policy) | (buffer_size << 6);
  *(volatile uint16_t *)(a1 + 7) = 16 * *(volatile uint16_t *)(a2 + 12);
  return 9;
}



// build_addba_response @ 0x130c0c
/* luna: Serializes a 9-byte ADDBA response action body, applying the configured BA policy and copying the agreement timeout only on success. */
int build_addba_response(int a1, int a2, int16_t a3, char a4, int16_t a5) {
  volatile uint8_t *v5; // r4

  *(volatile uint8_t *)(a1 + 2) = a4;
  *(volatile uint8_t *)a1 = 3;
  v5 = (void *)(uintptr_t)(off_130C4C);
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



// build_delba @ 0x130c50
/* luna: Builds a DELBA action frame body containing the TID, initiator flag, and reason code. */
int build_delba(int a1, int a2, int16_t a3) {
  int16_t tid; // r3
  int initiator_flag; // r1
  int16_t delba_parameters; // r3

  *(volatile uint8_t *)a1 = 3;
  *(volatile uint8_t *)(a1 + 1) = 2;
  tid = *(volatile uint8_t *)(a2 + 22);
  initiator_flag = *(volatile uint8_t *)(a2 + 17);
  *(volatile uint16_t *)(a1 + 4) = a3;
  delba_parameters = tid << 12;
  if ( initiator_flag == 1 )
    delba_parameters |= 0x800u;
  *(volatile uint16_t *)(a1 + 2) = delba_parameters;
  return 6;
}



// handle_addba_request @ 0x130c78
volatile uint8_t * handle_addba_request(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
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

  result = check_buf_range_12d75c(a1, a2, &v15);
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
    result = check_buf_range_12d79c(a1, a2, &v15);
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



// addba_request_ack @ 0x130d04
volatile uint8_t * addba_request_ack(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0

  result = test_arg2_one_12db20(a1, a2);
  if ( result )
    result = (volatile uint8_t *)(uint8_t)result[2];
  *(volatile uint8_t *)(a3 + 216) = (uint8_t)result;
  return result;
}



// handle_addba_response @ 0x130d18
/* luna: Finds the country-information triplet covering the channel record’s channel and stores that triplet’s maximum transmit power in the record. */
volatile uint8_t * handle_addba_response(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  int target_channel; // r5
  int v6; // r3
  char channel_step; // r6
  int triplet_offset; // r2
  int candidate_channel; // r3
  int channel_index; // r1
  int v11; // zf
  uint8_t v12[5]; // [sp+7h] [bp-5h] BYREF

  result = check_buf_range_12d818(a1, a2, v12);
  if ( result )
  {
    target_channel = *(volatile uint8_t *)(a3 + 164);
    if ( *(volatile uint8_t *)(a3 + 164) )
    {
      if ( target_channel == 1 && (uint16_t)(*(volatile uint16_t *)(a3 + 166) - 5005) <= 0x370u )
      {
        target_channel = (uint8_t)((unsigned int)(((unsigned int)dword_130DE4
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
      v6 = *(volatile uint16_t *)(a3 + 166);
      if ( (unsigned int)(v6 - 2412) > 0x48 )
      {
        channel_step = 1;
      }
      else
      {
        target_channel = v6 == 2484
           ? 14
           : (uint8_t)((unsigned int)(((unsigned int)dword_130DE4 * (uint64_t)(unsigned int)(v6 - 2407)) >> 32) >> 2);
        channel_step = 1;
      }
    }
    v12[0] += 2;
    if ( v12[0] > 7u )
    {
      triplet_offset = 5;
      do
      {
        candidate_channel = (uint8_t)result[triplet_offset];
        if ( result[triplet_offset + 1] )
        {
          if ( candidate_channel == target_channel )
          {
LABEL_7:
            *(volatile uint8_t *)(a3 + 172) = result[triplet_offset + 2];
            return result;
          }
          channel_index = 0;
          while ( 1 )
          {
            v11 = channel_index == (uint8_t)(result[triplet_offset + 1] - 1);
            candidate_channel = (uint8_t)(candidate_channel + channel_step);
            ++channel_index;
            if ( v11 )
              break;
            if ( candidate_channel == target_channel )
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



// delba_ack @ 0x130de8
volatile uint8_t * delba_ack(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0

  result = test_arg2_one_12db60(a1, a2);
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



// handle_ampdu_action @ 0x130e10
/* luna: Parses a channel number and optional secondary-channel offset, then populates the output band and frequency fields. */
int handle_ampdu_action(volatile uint8_t *a1, int a2, volatile uint8_t *a3, int a4) {
  unsigned int v8; // r7
  unsigned int v9; // r0
  volatile uint8_t *v10; // r8
  volatile uint8_t *v11; // r9
  volatile uint8_t *v12; // r0
  int v13; // r5
  unsigned int channel_number; // r3
  unsigned int v15; // r2
  int16_t channel_frequency_mhz; // r3
  int secondary_offset_mode; // r2
  int v19; // [sp+7h] [bp-1h] BYREF

  v8 = (unsigned int)check_buf_range_12d8f8(a1, a2);
  v9 = (unsigned int)check_buf_range_12d938(a1, a2);
  if ( !(v8 | v9) )
    return 0;
  v10 = (volatile uint8_t *)v9;
  v11 = test_arg2_one_12d978(a1, a2, &v19);
  if ( v11 )
  {
    if ( !v19 )
      return 0;
  }
  v12 = test_arg2_one_12d9bc(a1, a2, &v19);
  if ( v12 )
  {
    if ( !v19 )
      return 0;
  }
  if ( v8 )
  {
    v13 = *(volatile uint8_t *)(v8 + 4);
    *a3 = *(volatile uint8_t *)(v8 + 2);
    channel_number = *(volatile uint8_t *)(v8 + 3);
  }
  else
  {
    v13 = (uint8_t)v10[5];
    *a3 = v10[2];
    channel_number = (uint8_t)v10[4];
  }
  if ( !v13 )
    v13 = 2;
  *(volatile uint8_t *)a4 = channel_number > 0xE;
  v15 = channel_number - 1;
  if ( channel_number > 0xE )
  {
    if ( (uint8_t)v15 <= 0xB0u )
    {
      channel_frequency_mhz = 5 * channel_number + 5000;
      goto LABEL_17;
    }
    goto LABEL_23;
  }
  if ( v15 > 0xD )
  {
LABEL_23:
    channel_frequency_mhz = 0;
    goto LABEL_17;
  }
  if ( channel_number == 14 )
    channel_frequency_mhz = 2484;
  else
    channel_frequency_mhz = 5 * channel_number + 2407;
LABEL_17:
  *(volatile uint16_t *)(a4 + 2) = channel_frequency_mhz;
  *(volatile uint16_t *)(a4 + 4) = channel_frequency_mhz;
  *(volatile uint8_t *)(a4 + 1) = 0;
  *(volatile uint16_t *)(a4 + 6) = 0;
  if ( v11 )
  {
    secondary_offset_mode = (uint8_t)v11[2];
    if ( secondary_offset_mode == 1 )
    {
      *(volatile uint16_t *)(a4 + 4) = channel_frequency_mhz + 10;
      *(volatile uint8_t *)(a4 + 1) = 1;
    }
    else if ( secondary_offset_mode == 3 )
    {
      *(volatile uint16_t *)(a4 + 4) = channel_frequency_mhz - 10;
      *(volatile uint8_t *)(a4 + 1) = 1;
      if ( !v12 )
        goto LABEL_21;
LABEL_25:
      empty_ret(v12[2], v12[3], v12[4], (void *)(uintptr_t)(a4));
      goto LABEL_21;
    }
  }
  if ( v12 )
    goto LABEL_25;
LABEL_21:
  get_device_id((void *)(uintptr_t)(a4));
  return v13;
}



// ampdu_action_complete @ 0x130f1c
volatile uint8_t * ampdu_action_complete(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
  volatile uint8_t *result; // r0
  uint8_t v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r5
  uint64_t v10; // r2

  result = format_log_message_12dba0(a1, a2);
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



// table_read_le16 @ 0x130fc0
int table_read_le16(volatile uint8_t *a1, int a2, int a3) {
  int result; // r0
  int v5; // r3
  int16_t v6; // r3
  int16_t v7; // r2

  result = (int)test_arg2_one_12dbc8(a1, a2);
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



// table_read_caps @ 0x131008
volatile uint8_t * table_read_caps(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  int16_t v5; // r1
  int16_t v6; // r6
  int16_t v7; // r5
  int16_t v8; // r2
  int v9; // r7
  int16_t v10; // r3
  int16_t v11; // r0

  result = test_arg2_one_12dd10(a1, a2);
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



// rate_info_query @ 0x131044
int rate_info_query(volatile uint8_t *a1, int a2, int a3) {
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

  v4 = emit_hash_12dd50(a1, a2, v18);
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



// get_hw_timestamp @ 0x1310f0
volatile uint8_t * get_hw_timestamp(volatile uint8_t *a1, int a2, int a3) {
  volatile uint8_t *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = emit_dollar_12ddf8(a1, a2, &v5);
  if ( result )
    *(volatile uint32_t *)(a3 + 220) = *(volatile uint32_t *)(result + 3);
  else
    *(volatile uint32_t *)(a3 + 220) = 0x80000000;
  return result;
}



// get_adv_report @ 0x131118
int get_adv_report(volatile uint8_t *a1, int a2, int a3, volatile uint8_t *a4) {
  int result; // r0
  char v7; // r2
  int v8; // r2
  int v9; // r7
  int v10; // r5
  int v11; // r3

  result = (int)emit_ampersand_12de20(a1, a2);
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



// decode_adv_type @ 0x131170
volatile uint8_t * decode_adv_type(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  unsigned int v5; // r3

  result = emit_percent_12de40(a1, a2);
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



// hci_send_cmd @ 0x131198
int hci_send_cmd(int a1, volatile uint8_t *a2, int a3, int a4) {
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

  check_feature_flag(2, "set lp:%d, disable_filter=%d\n", *a2, a2[1]);
  v7 = *a2;
  v8 = (volatile int *)off_131388;
  **(volatile uint8_t **)off_131384 = v7;
  *((volatile uint8_t *)v8 + 412) = a2[1];
  if ( v7 == 1 )
  {
    if ( *((volatile uint8_t *)v8 + 189) )
    {
      v27 = (void *)(uintptr_t)(off_1313B8);
      v28 = (void *)(uintptr_t)(off_131398);
      *(volatile uint32_t *)off_131394 &= ~0x2000000u;
      *v27 |= 0x200000u;
      *v28 = 36;
    }
    else
    {
      v18 = (void *)(uintptr_t)(off_131394);
      v19 = (void *)(uintptr_t)(off_1313AC);
      v20 = *((volatile uint8_t *)off_1313AC + 18);
      v21 = (void *)(uintptr_t)(off_131398);
      *(volatile uint32_t *)off_131394 |= 0x2000000u;
      *v21 = 4;
      if ( !v20 )
      {
        *(volatile uint32_t *)off_1313B0 = 1;
        v18[8202] &= 0xFFFBFFFE;
      }
      v22 = (void *)(uintptr_t)(off_13139C);
      if ( *((volatile uint8_t *)off_13139C + 28) )
      {
        if ( !*((volatile uint8_t *)off_13139C + 29) )
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
            v25 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1313A4 + 54);
            v26 = (volatile uint32_t *)dword_1313B4;
            *((volatile uint32_t *)off_13139C + 5) = (int)(uintptr_t)(v23);
            v22[29] = 4;
            mem_copy_util(v26, v25 + v24);
            v23[1] |= 0x200u;
          }
        }
      }
    }
LABEL_21:
    *((volatile uint32_t *)off_1313A0 + 20) |= 0x40000u;
  }
  else if ( v7 == 2 )
  {
    v10 = (void *)(uintptr_t)(off_131390);
    v11 = (void *)(uintptr_t)(off_131394);
    v12 = (void *)(uintptr_t)(off_131398);
    v13 = (void *)(uintptr_t)(off_13139C);
    *(volatile uint32_t *)off_131390 |= 0x10000u;
    v14 = v13[8];
    *v11 &= ~0x2000000u;
    *v12 = 63;
    v15 = (void *)(uintptr_t)(off_1313A0);
    v10[10] &= ~1u;
    v15[20] &= ~0x40000u;
    if ( v14 && *(volatile uint8_t *)(v14 + 108) )
    {
      v16 = (*(volatile uint32_t *)0x40501010u);
      v17 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1313A4 + 54);
      v13[5] = v14;
      *((volatile uint8_t *)v13 + 29) = 4;
      mem_copy_util(v13 + 3, v17 + v16);
      *(volatile uint32_t *)(v14 + 4) |= 0x200u;
      mem_set_util((int)(uintptr_t)((volatile uint32_t *)(v14 + 24)));
    }
  }
  else if ( !v7 && **(volatile uint8_t **)off_13138C == 3 )
  {
    v29 = (void *)(uintptr_t)(off_131390);
    v30 = (void *)(uintptr_t)(off_131394);
    v31 = (void *)(uintptr_t)(off_131398);
    *(volatile uint32_t *)off_131390 &= ~0x10000u;
    *v30 |= 0x2000000u;
    *v31 = 0;
    v32 = (void *)(uintptr_t)(off_1313A0);
    v29[10] |= 1u;
    v32[20] |= 0x40000u;
    if ( (*v30 & 4) != 0 )
    {
      if ( *((volatile uint8_t *)v8 + 190) )
      {
        v33 = (void *)(uintptr_t)(off_1313C0);
        *(volatile uint32_t *)off_1313BC &= ~0x200u;
        *v33 &= ~1u;
        *v33 &= ~0x80u;
      }
      *(volatile uint32_t *)off_1313C4 = 48;
      critical_section_enter_alt();
      mfp_get_config();
    }
    if ( !*((volatile uint8_t *)off_1313C8 + 36) )
    {
      v34 = (volatile unsigned int *)off_1313D0;
      v35 = (void *)(uintptr_t)(off_1313D4);
      *(volatile uint32_t *)off_1313CC &= ~0x40000u;
      *v34 = *v34 & 0xFFFFFFF0 | 8;
      *v35 |= 1u;
    }
  }
  mac_write_header_word(5142, a4, a3);
  return 0;
}


