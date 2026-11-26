// rx_process_packet @ 0x11d760
/* luna: Handles a received MAC frame descriptor by validating the first PBD and RX error/status bits, updating or filtering per-context fields and timestamps, */
BOOL rx_process_packet(int a1) {
  volatile int16_t **v1; // r10
  int first_pbd; // r8
  int hw_error_code; // r3
  volatile uint32_t *frame_buffer; // r9
  int16_t frame_ctl; // r11
  unsigned int rx_info; // r6
  int v8; // r5
  int ctx_table_base; // r2
  unsigned int ctx_index; // r7
  int ctx_entry; // r3
  volatile unsigned int timer_tick; // r1
  unsigned int v14; // r3
  volatile uint8_t *v15; // r5
  int v16; // r2
  int v17; // r3
  int v18; // r11
  int v19; // r2
  volatile uint8_t *v20; // r7
  int v21; // r4
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // r2
  uint64_t v25; // r4
  uint64_t v26; // r0
  uint64_t v27; // r0
  uint64_t v28; // r0
  int v29; // r0
  volatile uint8_t *v30; // r4
  volatile uint32_t *v31; // r2
  int v32; // r8
  volatile int *v33; // r11
  volatile uint32_t *v34; // r7
  volatile unsigned int v35; // r9
  unsigned int v36; // r3
  volatile uint32_t *v37; // r3
  volatile unsigned int v38; // r2
  volatile uint32_t *v39; // r9
  volatile unsigned int v40; // r5
  unsigned int v41; // r1
  int v42; // r6
  int v43; // r5
  int v44; // r3
  int v45; // r2
  volatile uint32_t *v46; // r6
  int v47; // r2
  unsigned int v48; // r3
  volatile uint32_t *v49; // r6
  int v50; // r1
  unsigned int v51; // r3
  struct __attribute__((packed)) { union { int a3; // [sp+4h] [bp-18h]
  int a3a; }; // [sp+4h] [bp-18h]
  int v54; // [sp+8h] [bp-14h]
  int v55; // [sp+Ch] [bp-10h]
  char _pad3[4]; volatile uint8_t *a4; // [sp+14h] [bp-8h] BYREF
  } _frame;
  if ( *(volatile uint16_t *)(a1 + 48) )
  {
    v1 = (volatile int16_t **)off_11DAAC;
    first_pbd = *(volatile uint32_t *)(a1 + 28);
    hw_error_code = **(volatile int16_t **)off_11DAAC;
    if ( hw_error_code < 0 && !first_pbd )
    {
      v8 = 0;
      ke_int_lock_1((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v8;
    }
    frame_buffer = *(volatile uint32_t **)(first_pbd + 8);
    frame_ctl = *(volatile uint16_t *)frame_buffer;
    rx_info = *(volatile uint32_t *)(a1 + 84);
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11DA70)[102])
      && (*((volatile uint32_t *)off_11DA74 + 1) & 0x40) != 0
      && (*(volatile uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (frame_ctl & 0xFC) == 0xC4 )
        ++*(volatile uint32_t *)off_11DA90;
    }
    else
    {
      if ( (dword_11DA78 & ~rx_info) != 0 )
        return 0;
      *(volatile uint32_t *)(a1 + 84) = rx_info & 0xFEFFFFFF;
      if ( hw_error_code < 0 )
      {
        v8 = (rx_info >> 15) & 0x1F0;
        if ( !v8 )
        {
          ke_int_lock_1((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v8;
        }
      }
      ctx_table_base = dword_11DA7C;
      ctx_index = (uint8_t)((rx_info >> 15) - 16);
      ctx_entry = dword_11DA7C + 696 * ctx_index;
      v8 = *(volatile uint8_t *)(ctx_entry + 37);
      if ( !*(volatile uint8_t *)(ctx_entry + 37) )
      {
        *(volatile uint32_t *)(a1 + 84) = rx_info & 0xFCFFFFFF;
        return v8;
      }
      if ( ctx_index <= 0x23 )
      {
        timer_tick = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(ctx_entry + 664) = timer_tick;
      }
      v14 = ctx_table_base + 696 * ctx_index;
      if ( *(volatile uint16_t *)(v14 + 32) == 0xFFFF )
      {
        if ( (frame_ctl & 0xFC) != 0x80 )
        {
          *(volatile uint32_t *)(a1 + 84) = rx_info & 0xFCFFFFFF;
          return 0;
        }
        _frame.a3 = *(volatile uint32_t *)(v14 + 44);
        *(volatile uint32_t *)(a1 + 84) = rx_info & 0xFE007FFF | ((*(volatile uint8_t *)(_frame.a3 + 35) + 16) << 15);
      }
      else
      {
        _frame.a3 = ctx_table_base + 696 * ctx_index;
      }
      _frame.v54 = *(volatile uint8_t *)(_frame.a3 + 34);
      v15 = (volatile uint8_t *)(dword_11DA84 + 1320 * _frame.v54);
      _frame.v55 = 1320 * _frame.v54;
      get_channel_config(frame_buffer, ctx_index, v15[107]);
      if ( !v15[108] )
        return 0;
      v16 = v15[106];
      v17 = dword_11DA84;
      if ( v15[106] )
      {
        if ( (frame_ctl & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (frame_ctl & 0x300) != 0x200 )
      {
        v8 = frame_ctl & 4;
        if ( (frame_ctl & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v29 = memcmp((unsigned int)(frame_buffer + 4), _frame.v55 + 100 + dword_11DA84, 6u);
      v17 = dword_11DA84;
      if ( v29 )
      {
        v8 = frame_ctl & 4;
        if ( (frame_ctl & 4) != 0 )
        {
LABEL_37:
          v16 = *(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106);
          if ( !*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106) )
          {
LABEL_19:
            v18 = frame_ctl & 0xFC;
            v19 = _frame.v55 + v17;
            v20 = (volatile uint8_t *)(_frame.v55 + v17);
            if ( v18 == 128 )
            {
              _frame.a4 = nullptr;
              v43 = rx_process_packet_1(a1 + 20, (int)v20, _frame.a3, (void *)(&_frame.a4));
              ipc_msg_receive((unsigned int)_frame.a4, *(volatile uint16_t *)(a1 + 48), (int)v20);
              si_watchdog((int)v20);
              if ( v43 )
                bt_conn_validate(v20, first_pbd, a1 + 20);
              return v43 == 0;
            }
            if ( v18 == 80 )
            {
              v30 = (void *)(uintptr_t)(off_11DA98);
              if ( *((volatile uint8_t *)off_11DA98 + 29) == 7 )
              {
                v8 = *((volatile uint8_t *)off_11DA98 + 36);
                if ( !*((volatile uint8_t *)off_11DA98 + 36) )
                {
                  v31 = (void *)(uintptr_t)(off_11DA9C);
                  v32 = *(volatile uint32_t *)off_11DA9C & 0xF;
                  if ( v32 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(volatile uint32_t *)off_11DAA0 = 1;
                    }
                    v33 = (volatile int *)off_11DAB0;
                    v34 = (void *)(uintptr_t)(off_11DA9C);
                    ++*(volatile uint32_t *)off_11DAB0;
                    *v34 = 0;
                    v35 = (*(volatile uint32_t *)0x40501010u);
                    while ( *v34 << 28 )
                    {
                      v36 = (*(volatile uint32_t *)0x40501010u) - v35;
                      if ( v36 > 0x7530 )
                        state_check_feature(2, aIdleErr, 30000);
                    }
                    v37 = (void *)(uintptr_t)(off_11DAA4);
                    v38 = (*(volatile uint32_t *)0x40501010u);
                    if ( (*(volatile uint32_t *)off_11DAA8 & *(volatile uint32_t *)off_11DAA4 & 4) == 0 )
                    {
                      _frame.a3a = v8;
                      v39 = (void *)(uintptr_t)(off_11DAA8);
                      v40 = v38;
                      do
                      {
                        v41 = (*(volatile uint32_t *)0x40501010u) - v40;
                        v42 = *v37 & *v39;
                        if ( v41 > 0x7530 )
                        {
                          state_check_feature(2, aIdleIntErr);
                          v37 = (void *)(uintptr_t)(off_11DBCC);
                        }
                      }
                      while ( (v42 & 4) == 0 );
                      v8 = _frame.a3a;
                    }
                    *(volatile uint32_t *)off_11DBD0 = 4;
                    if ( *v33 )
                    {
                      v44 = *v33 - 1;
                      v45 = *(volatile uint32_t *)off_11DBD4;
                      *v33 = v44;
                      if ( !v44 )
                      {
                        if ( v45 )
                          __enable_irq();
                      }
                    }
                    v46 = (void *)(uintptr_t)(off_11DBD8);
                    v47 = **v1;
                    v48 = *((volatile uint32_t *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11DBD8 + 1) = v48;
                    if ( v47 < 0 && *(volatile uint32_t *)off_11DBE0 << 28 )
                    {
                      mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v48 = v46[1];
                    }
                    *(volatile uint32_t *)off_11DBDC = v48 | *v46;
                    *(volatile uint32_t *)off_11DBE0 = 16 * v32;
                  }
                  else
                  {
                    v49 = (void *)(uintptr_t)(off_11DBD8);
                    v50 = **v1;
                    v51 = *((volatile uint32_t *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11DBD8 + 1) = v51;
                    if ( v50 < 0 && *v31 << 28 )
                    {
                      mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v51 = v49[1];
                    }
                    *(volatile uint32_t *)off_11DBDC = v51 | *v49;
                  }
                  v30[36] = 1;
                  v30[29] = 0;
                  return v8;
                }
              }
            }
            else if ( v8 )
            {
              if ( v18 == 132 )
              {
                rf_tx_power_configure((void *)(uintptr_t)((int)frame_buffer), rx_info, v19);
                return 0;
              }
            }
            else
            {
              rf_tx_power_configure((void *)(uintptr_t)((int)frame_buffer), rx_info, v19);
              if ( *(volatile uint8_t *)(dword_11DA84 + 1320 * _frame.v54 + 1224) && v18 == 208 )
              {
                bt_packet_parse((int)v20, *(volatile uint8_t **)(first_pbd + 8), *(volatile uint16_t *)(a1 + 48), *(volatile uint32_t *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v16 == 2 && *(volatile uint8_t *)(_frame.a3 + 35) <= 0x23u )
          {
            v21 = *(volatile char *)(a1 + 65);
            sys_mode_get_low();
            if ( !*(volatile uint8_t *)(_frame.a3 + 689) )
            {
              v8 = *(volatile char *)(_frame.a3 + 689);
              *(volatile uint8_t *)(_frame.a3 + 689) = v21;
              return v8;
            }
            v22 = __aeabi_i2d(*(volatile char *)(_frame.a3 + 689));
            v23 = ((uint64_t (*)())__aeabi_dmul)(v22, *(volatile uint64_t *)&dword_11DA60);
            v24 = v23;
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(v21) & 0xFFFFFFFFu);
            v25 = __PAIR64__(HIDWORD(v23), v24);
            v26 = __aeabi_i2d(v23);
            v27 = ((uint64_t (*)())__aeabi_dmul)(v26, *(volatile uint64_t *)&dword_11DA68);
            v28 = __aeabi_dadd(v25, v27);
            *(volatile uint8_t *)(_frame.a3 + 689) = ((uint64_t (*)())__aeabi_d2lz)(v28);
          }
          return 0;
        }
LABEL_36:
        tx_slot_counter_inc(*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 107), ctx_index, 1);
        v17 = dword_11DA84;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}


// seq_count_inc @ 0x11dbf0
int seq_count_inc() {
  volatile uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11DC10);
  v1 = *((volatile uint8_t *)off_11DC10 + 11);
  v2 = (uint8_t)(*((volatile uint8_t *)off_11DC10 + 10) + 1);
  *((volatile uint8_t *)off_11DC10 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}



// seq_count_restart @ 0x11dc14
int seq_count_restart() {
  volatile uint8_t *v0; // r4
  volatile unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11DC34);
  if ( *((volatile uint8_t *)off_11DC34 + 10) )
    result = j_nullsub_6();
  v1 = (volatile unsigned int *)off_11DC38;
  v2 = *(volatile uint32_t *)off_11DC38;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}



// is_tx_ready @ 0x11dc3c
int is_tx_ready() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = (void *)(uintptr_t)(off_11DC60);
  rf_fifo_status();
  v1 = (int)(uintptr_t)(zero_struct((void *)(v0)));
  v2 = return_two_stub(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return (int)(uintptr_t)(init_driver_locks());
}



// nullsub_4 @ 0x11dc64
int nullsub_4(void) {
  return 0;
}


// pmu_sleep_200000 @ 0x11dc68
int pmu_sleep_200000() {
  return set_system_flag_1(0x200000);
}



// tx_lock @ 0x11dc70
int tx_lock() {
  volatile uint16_t *v0; // r5
  int v1; // r4
  int result; // r0
  volatile int *v3; // r9
  volatile int *v4; // r7
  void ( *v5)(uint32_t); // r2
  int v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r1
  volatile uint32_t *v9; // r2

  v0 = (void *)(uintptr_t)(off_11DD10);
  v1 = *(volatile uint32_t *)off_11DD10;
  result = set_system_flag_2(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11DD28;
    v4 = (volatile int *)off_11DD14;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      list_pop_front((int)(uintptr_t)(v0));
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v4 = 1;
      }
      v5 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v3;
      *(volatile uint8_t *)(v1 + 16) = 0;
      if ( v5 )
        v5(*(volatile uint32_t *)(v1 + 8));
      result = *(volatile uint32_t *)(v1 + 12);
      if ( result )
        result = rf_tx_timestamp_check(result);
      if ( *v3 )
      {
        v6 = *v3 - 1;
        v7 = *v4;
        *v3 = v6;
        if ( !v6 )
        {
          if ( v7 )
            __enable_irq();
        }
      }
      v1 = *(volatile uint32_t *)v0;
    }
    while ( *(volatile uint32_t *)v0 );
  }
  if ( *((volatile uint8_t *)v0 + 10) != *((volatile uint8_t *)v0 + 11) )
  {
    v8 = (void *)(uintptr_t)(off_11DD20);
    v9 = (void *)(uintptr_t)(off_11DD24);
    *(volatile uint32_t *)off_11DD1C = *((volatile uint32_t *)off_11DD18 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}



// tx_unlock @ 0x11dd2c
int tx_unlock() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  volatile int *v3; // r8
  volatile int *v4; // r9
  int v5; // r7
  void ( *v6)(uint32_t); // r2
  int v7; // r3
  int v8; // r2
  volatile uint8_t *v9; // r4

  v0 = (volatile int *)off_11DDD0;
  v1 = *(volatile uint32_t *)off_11DDD0;
  result = set_system_flag_2(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11DDDC;
    v4 = (volatile int *)off_11DDE0;
    v5 = 0;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
        v5 = 1;
      }
      list_pop_front((int)v0);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v3 = 1;
      }
      v6 = *(void ( **)(uint32_t))(v1 + 4);
      ++*v4;
      *(volatile uint8_t *)(v1 + 16) = 0;
      if ( v6 )
        v6(*(volatile uint32_t *)(v1 + 8));
      result = *(volatile uint32_t *)(v1 + 12);
      if ( result )
        result = rf_tx_timestamp_check(result);
      if ( *v4 )
      {
        v7 = *v4 - 1;
        v8 = *v3;
        *v4 = v7;
        if ( !v7 )
        {
          if ( v8 )
            __enable_irq();
        }
      }
      v1 = *v0;
    }
    while ( *v0 );
  }
  v9 = (void *)(uintptr_t)(off_11DDD4);
  if ( *((volatile uint8_t *)off_11DDD4 + 69) )
  {
    set_system_flag_1(0x80000);
    result = state_check_feature(1024, aHostBufferReco);
    v9[69] = 0;
  }
  return result;
}


// rf_wait_idle @ 0x11dde4
int rf_wait_idle() {
  volatile int *v0; // r6
  int v1; // r4
  int result; // r0
  volatile uint16_t *v3; // r5
  volatile int *v4; // r8
  volatile int *v5; // r9
  char v6; // r2
  void ( *v7)(uint32_t); // r3
  int v8; // r3
  int v9; // r2
  volatile uint8_t *v10; // r4

  v0 = (volatile int *)off_11DE98;
  v1 = *(volatile uint32_t *)off_11DE98;
  result = set_system_flag_2(0x200000);
  if ( v1 )
  {
    v3 = (void *)(uintptr_t)(off_11DE9C);
    if ( *(volatile uint16_t *)off_11DE9C )
    {
      v4 = (volatile int *)off_11DEA8;
      v5 = (volatile int *)off_11DEAC;
      do
      {
        if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        list_pop_front((int)v0);
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *v4 = 1;
        }
        v6 = *(volatile uint8_t *)(v1 + 16);
        ++*v5;
        if ( (v6 & 1) == 0 )
          --*v3;
        v7 = *(void ( **)(uint32_t))(v1 + 4);
        *(volatile uint8_t *)(v1 + 16) = 0;
        if ( v7 )
          v7(*(volatile uint32_t *)(v1 + 8));
        result = *(volatile uint32_t *)(v1 + 12);
        if ( result )
          result = rf_tx_timestamp_check(result);
        if ( *v5 )
        {
          v8 = *v5 - 1;
          v9 = *v4;
          *v5 = v8;
          if ( !v8 )
          {
            if ( v9 )
              __enable_irq();
          }
        }
        v1 = *v0;
      }
      while ( *v0 );
      v10 = (void *)(uintptr_t)(off_11DEA0);
      if ( *((volatile uint8_t *)off_11DEA0 + 69) )
      {
        set_system_flag_1(0x80000);
        result = state_check_feature(1024, aHostBufferReco);
        v10[69] = 0;
      }
    }
  }
  return result;
}


// rf_hw_init @ 0x11deb0
int rf_hw_init(int a1) {
  volatile uint32_t *v1; // r7
  volatile int *v2; // r9
  int v3; // r8
  volatile uint32_t *v4; // r11
  volatile uint32_t *v5; // r10
  int i; // r5
  int v8; // r2
  BOOL v9; // r0
  int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  void ( *v13)(uint32_t); // r2
  BOOL v14; // r0
  volatile uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_11E014);
  v2 = (volatile int *)off_11E034;
  v3 = dword_11E040;
  v4 = (void *)(uintptr_t)(off_11E044);
  v5 = (void *)(uintptr_t)(off_11E048);
  for ( i = 0; ; ++i )
  {
    v11 = mac_irq_check();
    *v1 = 0x10000;
    result = set_system_flag_2(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((volatile uint8_t *)v2 + 192) )
      {
        if ( *(volatile uint32_t *)off_11E018 > 0x80000u || i > 31 )
          return set_system_flag_1(0x80000);
      }
      else if ( i > 3 )
      {
        return set_system_flag_1(0x80000);
      }
    }
    if ( !state_ready_check() || !rf_is_channel_idle() )
    {
      *((volatile uint8_t *)off_11E02C + 69) = 1;
      v14 = rf_is_channel_idle();
      return state_check_feature(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(volatile uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      ke_event_schedule_1(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(volatile uint32_t *)off_11E01C,
        *((volatile uint32_t *)off_11E01C + 1),
        *((volatile uint32_t *)off_11E01C + 2),
        *v4,
        *v5);
    rx_timeout_check(v11);
    v9 = rx_process_packet(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( rf_cal_check_band(v11) )
    {
      goto LABEL_10;
    }
    tx_packet_finish(v11);
LABEL_10:
    v10 = **(volatile uint8_t **)off_11E024;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(volatile uint32_t *)off_11E028 || *(volatile uint32_t *)(*(volatile uint32_t *)off_11E028 + 12) != v11 || (*(volatile uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          rf_wait_idle();
          continue;
        }
        v16 = *(volatile uint32_t *)off_11E028;
        list_pop_front(off_11E028);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(volatile uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(volatile uint32_t *)(v16 + 8));
        rf_tx_timestamp_check(v11);
        break;
      case 3:
        tx_unlock();
        break;
    }
  }
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11E034)[48]) )
  {
    v15 = (void *)(uintptr_t)(off_11E038);
    if ( *((volatile uint8_t *)off_11E038 + 33) )
    {
      result = ke_int_lock(*((volatile uint32_t *)off_11E038 + 4), *((volatile uint32_t *)off_11E038 + 5), *((volatile uint32_t *)off_11E038 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((volatile uint8_t *)v15 + 33) = 0;
    }
  }
  *(volatile uint32_t *)off_11E03C |= 0x10000u;
  return result;
}


// rx_packet_isr @ 0x11e04c
/* luna: Interrupt routine that walks linked hardware Wi-Fi receive buffer descriptors, publishes packet lengths and buffer offsets into the RX descriptor ring */
int rx_packet_isr(volatile int *a1, int a2, volatile uint16_t *a3) {
  volatile uint8_t *rx_status_block; // r7
  int hw_desc; // r6
  int buf_offset; // r5
  volatile int *v6; // r9
  volatile uint16_t *v7; // r10
  volatile int *rx_ring_base_ptr; // r11
  int16_t total_rx_len; // r8
  int continuation_len; // r4
  int rx_slot_idx; // r3
  int v12; // r12
  int rx_ring_slot; // r0
  char v14; // r2
  char v15; // r3
  volatile int *v16; // r3
  int v17; // r3
  int next_hw_desc; // r3
  int16_t v19; // r0
  int16_t v20; // r3
  int hw_buf_avail_len; // r2
  volatile int *v22; // r3
  int v23; // r3
  int rx_ring_base; // [sp+0h] [bp-14h]
  int last_hw_desc; // [sp+4h] [bp-10h]

  rx_status_block = (void *)(uintptr_t)(off_11E164);
  hw_desc = *a1;
  buf_offset = (uint16_t)*a3;
  v6 = (volatile int *)off_11E178;
  v7 = (void *)(uintptr_t)(off_11E17C);
  rx_ring_base_ptr = (volatile int *)off_11E180;
  total_rx_len = 0;
  *((volatile uint8_t *)off_11E164 + 2) = 0;
  last_hw_desc = 0;
  while ( 1 )
  {
    v19 = *(volatile uint16_t *)(hw_desc + 8);
    v20 = *(volatile uint32_t *)(hw_desc + 12) + 1;
    hw_buf_avail_len = (uint16_t)(v20 - v19);
    if ( a2 + buf_offset >= hw_buf_avail_len )
    {
      continuation_len = (continuation_len & ~0xFFFFu) | ((uint16_t)(v19 - v20 + buf_offset + a2) & 0xFFFFu);
      a2 = (uint16_t)(hw_buf_avail_len - buf_offset);
      continuation_len = (uint16_t)continuation_len;
      buf_offset = 0;
    }
    else
    {
      continuation_len = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E168 = 1;
    }
    rx_slot_idx = (uint16_t)*v7;
    v12 = *v6;
    rx_ring_base = *rx_ring_base_ptr;
    rx_ring_slot = *rx_ring_base_ptr + 8 * rx_slot_idx;
    *(volatile uint32_t *)(rx_ring_slot + 4) = *(volatile uint32_t *)(hw_desc + 8);
    *v6 = v12 + 1;
    *(volatile uint32_t *)(rx_ring_base + 8 * rx_slot_idx) = a2;
    v14 = rx_status_block[3] + 1;
    total_rx_len += a2;
    *v7 = rx_slot_idx + 1;
    rx_status_block[3] = v14;
    if ( continuation_len )
    {
      if ( v12 == -1 )
        goto LABEL_10;
      v22 = (volatile int *)off_11E168;
      *v6 = v12;
      v23 = *v22;
      if ( v12 || !v23 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v15 = *(volatile uint8_t *)(rx_ring_slot + 3);
    *(volatile uint16_t *)rx_status_block = total_rx_len;
    *(volatile uint8_t *)(rx_ring_slot + 3) = v15 | 4;
    rx_status_block[2] = 1;
    *((volatile uint32_t *)rx_status_block + 2) = rx_ring_slot;
    if ( v12 == -1 )
      break;
    v16 = (volatile int *)off_11E168;
    *v6 = v12;
    v17 = *v16;
    if ( v12 || !v17 )
      break;
LABEL_9:
    __enable_irq();
    if ( !continuation_len )
      break;
LABEL_10:
    next_hw_desc = *(volatile uint32_t *)(hw_desc + 4);
    if ( **(volatile int16_t **)off_11E16C < 0 && !next_hw_desc )
    {
      mmio_irq_clear(dword_11E174, dword_11E170, 615);
      next_hw_desc = 0;
    }
    last_hw_desc = hw_desc;
    a2 = continuation_len;
    hw_desc = next_hw_desc;
  }
  *a1 = hw_desc;
  *a3 = buf_offset;
  return last_hw_desc;
}



// tx_packet_isr @ 0x11e184
/* luna: WiFi MAC TX packet interrupt handler that walks the TX descriptor queue, enqueues packet buffers, programs the RF transmit channel for scheduled packe */
volatile uint32_t * tx_packet_isr(volatile uint32_t *a1, int a2, volatile uint16_t *a3) {
  volatile int *tx_state; // r7
  int v4; // r10
  volatile uint32_t *tx_desc; // r6
  volatile int16_t **tx_irq_status; // r11
  volatile uint32_t *v7; // r8
  int tx_busy; // r9
  int v10; // r5
  int v11; // r0
  int pkt_len; // r3
  volatile uint32_t *pkt; // r4
  int v14; // r2
  int v15; // r0
  int tx_channel; // r1
  volatile uint32_t *next_desc; // r3
  int16_t v18; // r5
  int16_t v19; // r2
  int v20; // r1
  int v22; // [sp+8h] [bp-14h]
  int v23; // [sp+8h] [bp-14h]
  int16_t v24; // [sp+8h] [bp-14h]
  volatile uint32_t *v25; // [sp+Ch] [bp-10h]

  tx_state = (volatile int *)off_11E290;
  v4 = (uint16_t)*a3;
  tx_desc = (volatile uint32_t *)*a1;
  tx_irq_status = (volatile int16_t **)off_11E2A0;
  v7 = 0;
  *((volatile uint8_t *)off_11E290 + 32) = 1;
  tx_busy = 0;
  v25 = 0;
  while ( 1 )
  {
    v18 = *((volatile uint16_t *)tx_desc + 4);
    v19 = tx_desc[3] + 1;
    v20 = (uint16_t)(v19 - v18);
    if ( a2 + v4 >= v20 )
      break;
    v23 = a2;
    v11 = critical_enter_0();
    v10 = 0;
    pkt_len = v23;
    tx_busy = 1;
    pkt = (volatile uint32_t *)v11;
    if ( !v11 )
      goto LABEL_15;
LABEL_5:
    v14 = tx_state[1];
    if ( !v14 )
      *tx_state = v11;
    v15 = **tx_irq_status;
    tx_state[3] += pkt_len;
    tx_state[1] = v14 + 1;
    tx_channel = tx_desc[2];
    if ( v15 < 0 && !tx_channel )
    {
      v24 = pkt_len;
      mmio_irq_clear(dword_11E298, dword_11E294, 683);
      tx_channel = tx_desc[2];
      pkt_len = (pkt_len & ~0xFFFFu) | ((uint16_t)(v24) & 0xFFFFu);
    }
    rf_set_tx_channel(pkt, tx_channel, 0, pkt_len, tx_busy);
    if ( v7 )
      v7[1] = (int)(uintptr_t)(pkt);
    tx_state[2] = (int)pkt;
    if ( !v10 )
      goto LABEL_16;
    next_desc = (volatile uint32_t *)tx_desc[1];
    if ( **tx_irq_status < 0 && !next_desc )
    {
      mmio_irq_clear(dword_11E29C, dword_11E294, 704);
      next_desc = 0;
    }
    v25 = tx_desc;
    v7 = pkt;
    tx_desc = next_desc;
    a2 = v10;
  }
  v10 = (uint16_t)(v18 + a2 + v4 - v19);
  v22 = (uint16_t)(v20 - v4);
  if ( !v10 )
    tx_busy = 1;
  v11 = critical_enter_0();
  v4 = 0;
  pkt_len = v22;
  pkt = (volatile uint32_t *)v11;
  if ( v11 )
    goto LABEL_5;
LABEL_15:
  *((volatile uint8_t *)tx_state + 32) = v11;
LABEL_16:
  *a1 = (int)(uintptr_t)(tx_desc);
  *a3 = v4;
  return v25;
}



// rx_adv_packet_isr @ 0x11e2a4
volatile uint32_t * rx_adv_packet_isr(volatile uint32_t *a1, unsigned int a2, int a3, volatile uint32_t *a4, int a5) {
  volatile uint8_t **v5; // r9
  volatile uint32_t *v6; // r7
  int v7; // r5
  int v8; // r12
  volatile int16_t **v9; // r10
  volatile uint32_t *v10; // r6
  volatile uint32_t *result; // r0
  unsigned int v13; // r4
  int v14; // r3
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r11
  int v17; // r4
  int16_t v18; // r3
  signed int v19; // r2
  volatile uint32_t *v20; // r3
  volatile uint16_t *v22; // [sp+Ch] [bp-8h]

  v5 = (volatile uint8_t **)off_11E3B4;
  v6 = (volatile uint32_t *)*a1;
  v7 = *(volatile uint16_t *)a4;
  v8 = **(volatile uint8_t **)off_11E3B4;
  v9 = (volatile int16_t **)off_11E3B8;
  v22 = (void *)(a4);
  if ( a2 >= 0x640 )
    a2 = 1600;
  if ( v8 == 3 )
    a4 = (void *)(uintptr_t)(off_11E3A8);
  v10 = &v6[12 * a5 + 5];
  if ( v8 == 3 )
    *a4 = (int)(uintptr_t)(v10);
  result = 0;
  while ( 1 )
  {
    v17 = v6[2];
    v18 = v6[3] + 1;
    v19 = (uint16_t)(v18 - v17);
    v10[1] = a3;
    *v10 = v7 + v17;
    if ( (int)(a2 + v7) >= v19 )
    {
      v13 = (uint16_t)(v17 - v18 + v7 + a2);
      a2 = (uint16_t)(v19 - v7);
      v7 = 0;
    }
    else
    {
      v13 = 0;
    }
    if ( v8 == 3 )
    {
      v14 = a2;
      if ( a2 >= 0x800 )
        v14 = 2048;
      v10[2] = v14 | 0xA3000000;
      v10[3] = a2;
      v10[4] = a2;
      v10[5] = 262148;
    }
    a3 += a2;
    if ( !v13 )
      break;
    v15 = (volatile uint32_t *)v6[1];
    v16 = v15 + 5;
    if ( **v9 < 0 && !v15 )
    {
      mmio_irq_clear(dword_11E3B0, dword_11E3AC, 928);
      v15 = 0;
      v8 = **v5;
    }
    if ( v8 == 3 )
      v10[8] = (int)(uintptr_t)(v16);
    result = v6;
    v10 = v16;
    v6 = v15;
    a2 = v13;
  }
  if ( v8 == 3 )
  {
    v20 = (void *)(uintptr_t)(off_11E3A8);
    v10[8] = 0;
    v20[1] = (int)(uintptr_t)(v10);
  }
  *a1 = (int)(uintptr_t)(v6);
  *v22 = v7;
  return result;
}



// tx_timestamp_get @ 0x11e3bc
int tx_timestamp_get(int a1, int a2) {
  int result; // r0
  unsigned int v3; // r3
  volatile uint32_t *v4; // r1
  int v5; // r2
  int v6; // cf
  unsigned int v7; // r2

  if ( !a2 )
  {
    v3 = a1 + 160;
    goto LABEL_9;
  }
  if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v3 = (*(volatile uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v4 = (void *)(uintptr_t)(off_11E42C);
    v5 = *((volatile uint32_t *)off_11E42C + 2);
    if ( *((volatile uint32_t *)off_11E42C + 1) == v3 )
      v3 = *(volatile uint32_t *)off_11E42C;
    *(volatile uint32_t *)(a1 + 152) = v3;
    result = v5 & 0x7FFFFFFF;
    v6 = v3 >= (v5 & 0x7FFFFFFFu);
    v7 = v5 & 0x80000000;
    if ( !v6 )
      v7 += 0x80000000;
    v4[2] = v3 | v7;
    return result;
  }
  while ( 1 )
  {
    a2 = *(volatile uint32_t *)(a2 + 4);
    if ( **(volatile int16_t **)off_11E420 < 0 && !a2 )
      return ke_int_lock_1((int)aPdNull, (int)aRxlGoToLastRbd, 1119);
    if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}


// rf_fifo_status @ 0x11e430
int rf_fifo_status() {
  volatile int *v0; // r2
  int v1; // r0
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r12
  uint64_t v4; // kr00_8
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r5
  int v7; // r1
  uint64_t v8; // kr08_8
  volatile uint32_t *v9; // lr
  volatile uint32_t *v10; // r7
  volatile int *v12; // r4
  int v13; // r6
  int v14; // r3

  v0 = (volatile int *)off_11E498;
  v1 = *(volatile uint32_t *)off_11E494;
  v2 = (void *)(uintptr_t)(off_11E49C);
  v3 = (void *)(uintptr_t)(off_11E4B8);
  v4 = *(volatile uint64_t *)*(volatile uint32_t *)off_11E494;
  v5 = (void *)(uintptr_t)(off_11E4A0);
  *(volatile uint32_t *)off_11E498 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = (void *)(uintptr_t)(off_11E4A8);
  v7 = *v0;
  *(volatile uint32_t *)off_11E4A4 = *v0;
  *v6 = v7;
  v8 = *(volatile uint64_t *)(v1 + 8);
  v9 = (void *)(uintptr_t)(off_11E4BC);
  v10 = (void *)(uintptr_t)(off_11E4AC);
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (volatile int *)off_11E4B0;
  v0[2] = v4;
  v13 = dword_11E4B4;
  *v9 = HIDWORD(v8) + v8 - 4;
  *v3 = v8;
  *v10 = v8;
  v6[5] = v13;
  v14 = *v12;
  v0[4] = HIDWORD(v8) + v8;
  v0[3] = v8;
  v0[5] = v8;
  *v12 = v14 & 0x80000 | 0x78025;
  return HIDWORD(v8) + v8;
}



// rf_ant_switch_set @ 0x11e4c0
unsigned int rf_ant_switch_set(int a1) {
  volatile unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_11E4F0;
  *(volatile uint32_t *)off_11E4EC = (a1 << 10) & 0x400 | *(volatile uint32_t *)off_11E4EC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}



// rf_tx_timestamp_check @ 0x11e4f4
int rf_tx_timestamp_check(int result) {
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(volatile uint32_t *)(result + 152);
  if ( *(volatile uint8_t *)(result + 156) )
  {
    v3 = *(volatile uint32_t *)off_11E53C & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11E53C & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(volatile uint32_t *)off_11E53C = v1 | v3;
  }
  else
  {
    v2 = *(volatile uint32_t *)off_11E538 & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11E538 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(volatile uint32_t *)off_11E538 = v1 | v2;
  }
  return result;
}



// tx_timeout_check @ 0x11e540
int tx_timeout_check(int a1) {
  int v1; // r4
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r3
  volatile uint32_t *v5; // r1
  int v6; // r2
  int v7; // cf
  unsigned int v8; // r2
  volatile char *v10; // r0
  int v11; // r2
  int a1b; // [sp+4h] [bp-4h]
  int a1a; // [sp+4h] [bp-4h]

  if ( *(volatile uint16_t *)(a1 + 48) )
  {
    v1 = *(volatile uint32_t *)(a1 + 28);
    if ( **(volatile int16_t **)off_11E5FC < 0 && !v1 )
    {
      v10 = aPdNull;
      v11 = 393;
      return ke_int_lock_1((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v2 = *(volatile uint32_t *)(a1 + 84);
    v3 = **(volatile uint16_t **)(v1 + 8) & 0xFC;
    *(volatile uint32_t *)(a1 + 84) = v2 & 0xFEFFFFFF;
    if ( v3 == 36 )
    {
      if ( (v2 & 0x2000) != 0 )
      {
        a1b = a1;
        rxreorder_process(a1);
        a1 = a1b;
      }
    }
    else if ( v3 == 148 && (~v2 & 0x2002) == 0 )
    {
      a1a = a1;
      ke_event_loop(a1, v2 & 0xFEFFFFFF, v2, 0);
      a1 = a1a;
    }
    v4 = (*(volatile uint32_t *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(volatile int16_t **)off_11E5FC < 0 && *(volatile uint32_t *)(a1 + 28) )
    {
      v10 = aDmaHdrdescHdFi;
      v11 = 436;
      return ke_int_lock_1((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v4 = a1 + 160;
  }
  v5 = (void *)(uintptr_t)(off_11E600);
  v6 = *((volatile uint32_t *)off_11E600 + 5);
  if ( *((volatile uint32_t *)off_11E600 + 4) == v4 )
    v4 = *((volatile uint32_t *)off_11E600 + 3);
  *(volatile uint32_t *)(a1 + 152) = v4;
  v7 = v4 >= (v6 & 0x7FFFFFFFu);
  v8 = v6 & 0x80000000;
  if ( !v7 )
    v8 += 0x80000000;
  v5[5] = v4 | v8;
  return rf_tx_timestamp_check(a1);
}


// ke_message_send @ 0x11e610
int ke_message_send(int result, int a2, int a3, int a4) {
  int v4; // r7
  volatile int16_t **v5; // r10
  int v6; // r11
  int v7; // r1
  unsigned int v9; // r8
  int16_t v10; // r3
  uint64_t v11; // r4
  int v12; // r6
  int v13; // r4
  int v14; // r3
  volatile uint32_t *v15; // r2
  volatile uint32_t *v16; // r5
  int v17; // r3

  if ( a2 )
  {
    v4 = result;
    v5 = (volatile int16_t **)off_11E6A8;
    v6 = dword_11E6AC;
    result = a2;
    v7 = dword_11E6A4;
    v9 = 0;
    while ( 1 )
    {
      v11 = *(volatile uint64_t *)(v4 + 8);
      v10 = WORD2(v11) + 1;
      v11 = (v11 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((uint16_t)(WORD2(v11) + 1 - v11) - a3) << 32);
      if ( result < SHIDWORD(v11) )
      {
        v12 = 0;
      }
      else
      {
        v12 = (uint16_t)(v11 - v10 + a3 + result);
        result = WORD2(v11);
      }
      v13 = v11 + a3;
      v14 = a4 + 4 * (v9 >> 2);
      if ( (unsigned int)(result + 3) >> 2 )
      {
        v15 = (volatile uint32_t *)(a4 + 4 * (v9 >> 2));
        v16 = (volatile uint32_t *)(v14 + 4 * ((unsigned int)(result + 3) >> 2));
        v17 = v13 - v14;
        do
        {
          *v15 = *(volatile uint32_t *)((volatile char *)v15 + v17);
          ++v15;
        }
        while ( v15 != v16 );
      }
      if ( !v12 )
        break;
      v4 = *(volatile uint32_t *)(v4 + 4);
      v9 = (uint16_t)(v9 + result);
      if ( **v5 < 0 && !v4 )
      {
        mmio_irq_clear(v6, v7, 1189);
        v7 = dword_11E6A4;
      }
      result = v12;
      a3 = 0;
    }
  }
  return result;
}



// bt_notify_event @ 0x11e6b0
int bt_notify_event(int a1) {
  volatile uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = (void *)(uintptr_t)(off_11E700);
  if ( *((volatile uint8_t *)off_11E700 + 33) )
    *(volatile uint32_t *)(*((volatile uint32_t *)off_11E700 + 6) + 4) = a1;
  else
    *((volatile uint32_t *)off_11E700 + 4) = a1;
  result = *((volatile uint8_t *)off_11E704 + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((volatile uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = ke_int_lock(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((volatile uint8_t *)v1 + 33) = 0;
  }
  return result;
}



// tx_packet_setup @ 0x11e708
int tx_packet_setup(int a1, int a2, int a3, uint16_t a4, int a5, int a6) {
  volatile uint32_t *v6; // r8
  volatile uint8_t **v7; // r7
  int v8; // r12
  volatile uint8_t *v9; // r5
  int v11; // r3
  int v14; // r3
  volatile uint32_t *v15; // r0
  int v16; // r3
  volatile int *v18; // r5
  volatile uint32_t *v19; // r8
  uint8_t v20; // r7
  volatile uint32_t *v21; // r0
  volatile uint16_t *v22; // r5
  volatile int *v23; // r9
  int v24; // r10
  int v25; // cc
  int v26; // r0
  volatile uint32_t *v27; // r0
  int v28; // r1
  int v29; // r3
  int v30; // r0
  volatile uint8_t *v31; // r1
  int v32; // r2
  char v33; // r10
  int v34; // r2
  int v35; // r3
  volatile uint8_t *v36; // r5
  int v37; // r2
  volatile int *v38; // r9
  int v39; // r0
  int v40; // r3
  int v41; // r2
  volatile uint32_t *v42; // r0
  int v43; // r7
  int v44; // r2
  int v45; // r12
  int v46; // r2
  volatile int *v47; // r4
  int v48; // r0
  int v49; // r3
  int v50; // r2
  struct __attribute__((packed)) { int a4a; // [sp+Eh] [bp-Eh] BYREF
  char _pad1[2]; int a1a[2]; // [sp+14h] [bp-8h] BYREF
  } _frame;
  v7 = (volatile uint8_t **)off_11E99C;
  v8 = *(volatile uint32_t *)(a1 + 28);
  v9 = *(volatile uint8_t **)off_11E99C;
  _frame.a1a[0] = v8;
  _frame.a4a = (_frame.a4a & ~0xFFFFu) | ((uint16_t)(a4) & 0xFFFFu);
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v22 = (void *)(uintptr_t)(off_11E9AC);
  if ( *((volatile uint32_t *)off_11E9AC + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E9B0 = 1;
    }
    v23 = (volatile int *)off_11E9D0;
    v24 = dword_11E9D4;
    v25 = (uint16_t)v22[4122] > 0x186u;
    ++*(volatile uint32_t *)off_11E9D0;
    v26 = dword_11E9B4;
    if ( v25 )
      v22[4122] = 0;
    v27 = list_pop_front(v26);
    v28 = *(volatile uint32_t *)off_11E9B8;
    v29 = (uint16_t)v22[4122];
    v6 = v27;
    v30 = *(volatile uint32_t *)off_11E9B8 + 8 * v29;
    *((volatile uint16_t *)v6 + 6) = v29;
    *(volatile uint32_t *)(v30 + 4) = a1 + 48;
    *(volatile uint32_t *)(v28 + 8 * v29) = v24;
    v31 = (void *)(uintptr_t)(off_11E9BC);
    v6[1] = v30;
    v32 = *v23;
    v33 = *((volatile uint8_t *)v22 + 3074) + 1;
    v30 = (v30 & ~0xFFu) | ((uint8_t)(v31[3] + 1) & 0xFFu);
    v22[4122] = v29 + 1;
    *((volatile uint8_t *)v22 + 3074) = v33;
    v31[3] = v30;
    if ( v32 )
    {
      v34 = v32 - 1;
      v35 = *(volatile uint32_t *)off_11E9B0;
      *v23 = v34;
      if ( !v34 )
      {
        if ( v35 )
          __enable_irq();
      }
    }
    v11 = **v7;
    if ( v11 == 2 )
    {
      rx_packet_isr(_frame.a1a, a2, (void *)(&_frame.a4a));
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v36 = (void *)(uintptr_t)(off_11E9BC);
      if ( !*((volatile uint8_t *)off_11E9BC + 2) )
        goto LABEL_6;
      v37 = v6[1];
      v6[2] = *(volatile uint16_t *)off_11E9BC + 58;
      *(volatile uint8_t *)(v37 + 3) &= 0x3Fu;
      *((volatile uint8_t *)v6 + 14) = v36[3];
      *v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11E9B0 = 1;
      }
      v38 = (volatile int *)off_11E9D0;
      v39 = dword_11E9C0;
      ++*(volatile uint32_t *)off_11E9D0;
      check_abort_flag(v39, v6);
      rf_calib_init();
      if ( *v38 )
      {
        v40 = *v38 - 1;
        v41 = *(volatile uint32_t *)off_11E9B0;
        *v38 = v40;
        if ( !v40 )
        {
          if ( v41 )
            __enable_irq();
        }
      }
      *(volatile uint32_t *)v36 = 0;
      *((volatile uint32_t *)v36 + 1) = 0;
      v14 = **v7;
LABEL_5:
      if ( v14 == 1 )
      {
        v18 = (volatile int *)off_11E9A4;
        if ( *((volatile uint8_t *)off_11E9A4 + 32) )
        {
          v42 = (void *)(uintptr_t)(critical_enter_0());
          v43 = (int)v42;
          if ( v42 )
          {
            if ( *((volatile uint8_t *)v18 + 32) )
            {
              v44 = *v18;
              v45 = v18[1] + 1;
              v42[2] = (v45 << 24) & 0x7F000000 | v42[2] & 0x80FFFFFF;
              v18[1] = v45;
              rf_set_tx_channel(v42, a1 + 48, v44, 0x3Au, 0);
              v46 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11E9C8)[48]);
              v18[3] += 58;
              if ( v46 )
                bt_notify_event(v43);
              else
                ke_int_lock(v43, v18[1], v18[2]);
              *(volatile uint8_t *)off_11E9CC |= 1u;
              v18[1] = 0;
              v18[3] = 0;
              *v18 = 0;
              v18[2] = 0;
              *((volatile uint8_t *)v18 + 32) = 0;
              goto LABEL_6;
            }
          }
          else
          {
            *(volatile uint8_t *)(a1 + 16) |= 1u;
            ke_event_schedule_1("partial no tx_dscr_hdr\r\n");
            *((volatile uint8_t *)v18 + 32) = 0;
          }
        }
        state_check_feature(1024, "partial no tx_dscr_hdr!!\r\n");
        v19 = (volatile uint32_t *)*v18;
        *(volatile uint8_t *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v21 = v19;
            v19 = (volatile uint32_t *)v19[1];
            critical_enter_1(v21);
            ++v20;
          }
          while ( v20 < (unsigned int)v18[1] );
        }
        v18[1] = 0;
        v18[3] = 0;
        *v18 = 0;
        v18[2] = 0;
      }
LABEL_6:
      tx_timestamp_get(a1, _frame.a1a[0]);
      v15 = (void *)(uintptr_t)(off_11E9A0);
      *(volatile uint32_t *)(a1 + 4) = a5;
      v16 = v15[14];
      *(volatile uint32_t *)(a1 + 8) = a6;
      if ( v16 )
        return check_abort_flag((int)(v15 + 14), (volatile uint32_t *)a1);
      else
        return check_abort_flag(dword_11E9C4, (volatile uint32_t *)a1);
    }
LABEL_2:
    if ( v11 == 1 )
      tx_packet_isr((void *)(_frame.a1a), a2, (void *)(&_frame.a4a));
    else
      rx_adv_packet_isr((void *)(_frame.a1a), a2, a3, (void *)(&_frame.a4a), 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(volatile uint8_t *)(a1 + 16) |= 1u;
  tx_timestamp_get(a1, v8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11EA34 = 1;
  }
  v47 = (volatile int *)off_11EA38;
  ++*(volatile uint32_t *)off_11EA38;
  v48 = rf_calib_init();
  if ( *v47 )
  {
    v49 = *v47 - 1;
    v50 = *(volatile uint32_t *)off_11EA34;
    *v47 = v49;
    if ( !v49 )
    {
      if ( v50 )
        __enable_irq();
    }
  }
  return printf_wrapper("rxl err, no buf %d\n", v48);
}


// rx_packet_setup @ 0x11ea44
int rx_packet_setup(int a1) {
  volatile uint32_t *v1; // r8
  int v2; // r10
  int v3; // r11
  volatile uint32_t *v4; // r6
  volatile uint8_t **v5; // r5
  int16_t v6; // r2
  volatile uint8_t *v7; // r3
  int v8; // r4
  int v9; // r3
  unsigned int v10; // r7
  int v11; // r3
  volatile int *v12; // r6
  int v13; // r11
  int v14; // r3
  uint8_t v15; // r7
  volatile uint32_t *v16; // r4
  int v17; // r11
  volatile uint32_t *v18; // r0
  int v19; // r3
  volatile uint16_t *v20; // r6
  int v21; // r2
  volatile int *v22; // r7
  int v23; // r0
  int v24; // r3
  int v25; // r2
  volatile uint16_t *v27; // r7
  volatile int *v28; // r9
  unsigned int v29; // r1
  int v30; // r0
  volatile uint32_t *v31; // r0
  int v32; // r12
  int v33; // r3
  volatile uint32_t *v34; // r1
  volatile uint8_t *v35; // r12
  int v36; // r0
  char v37; // r2
  int v38; // r0
  int v39; // r3
  volatile int *v40; // r2
  int v41; // r3
  int v42; // r1
  int v43; // r3
  unsigned int CPSR; // r0
  volatile uint32_t *v45; // r3
  volatile uint32_t *v46; // r0
  int v47; // r1
  int v48; // r2
  volatile uint32_t *v49; // r2
  volatile uint32_t *v50; // r5
  volatile uint32_t *v51; // r0
  int v52; // r7
  int v53; // r2
  int v54; // r12
  int v55; // r2
  volatile uint8_t *v56; // r1
  char v57; // r2
  volatile uint8_t *v58; // r3
  int v59; // r1
  volatile int *v60; // r4
  int v61; // r0
  int v62; // r3
  int v63; // r2
  struct __attribute__((packed)) { int a2; // [sp+Ch] [bp-10h]
  char _pad1[2]; uint16_t a4; // [sp+12h] [bp-Ah] BYREF
  int a4_2[2]; // [sp+14h] [bp-8h] BYREF
  } _frame;
  v4 = (void *)(uintptr_t)(off_11EC78);
  v5 = (volatile uint8_t **)off_11EC7C;
  v6 = *((volatile uint8_t *)off_11EC78 + 50);
  v7 = *(volatile uint8_t **)off_11EC7C;
  v8 = a1;
  _frame.a4_2[0] = *(volatile uint32_t *)(a1 + 28);
  _frame.a4 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = jump_to_10ca3c();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v27 = (void *)(uintptr_t)(off_11EC9C);
    if ( !*((volatile uint32_t *)off_11EC9C + 2057) )
    {
      v59 = _frame.a4_2[0];
      *(volatile uint8_t *)(v8 + 16) |= 1u;
      tx_timestamp_get(v8, v59);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11EEAC = 1;
      }
      v60 = (volatile int *)off_11EEB0;
      ++*(volatile uint32_t *)off_11EEB0;
      v61 = rf_calib_init();
      if ( *v60 )
      {
        v62 = *v60 - 1;
        v63 = *(volatile uint32_t *)off_11EEAC;
        *v60 = v62;
        if ( !v62 )
        {
          if ( v63 )
            __enable_irq();
        }
      }
      return printf_wrapper("err, no buf %d\n", v61);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11EC90 = 1;
    }
    v28 = (volatile int *)off_11EC94;
    v29 = (uint16_t)v27[4122];
    v30 = dword_11ECA0;
    ++*(volatile uint32_t *)off_11EC94;
    if ( v29 > 0x186 )
      v27[4122] = 0;
    v31 = list_pop_front(v30);
    v32 = *(volatile uint32_t *)off_11ECA4;
    v33 = (uint16_t)v27[4122];
    *((volatile uint16_t *)v31 + 6) = v33;
    v34 = (volatile uint32_t *)(v32 + 8 * v33);
    v34[1] = v8 + 48;
    *v34 = dword_11ECA8;
    v35 = (void *)(uintptr_t)(off_11EC8C);
    v31[1] = (int)(uintptr_t)(v34);
    v1 = v31;
    v36 = *v28;
    v34 = (void *)(uintptr_t)(((uintptr_t)(v34) & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v27 + 3074) + 1) & 0xFFu));
    v37 = v35[3] + 1;
    v27[4122] = v33 + 1;
    *((volatile uint8_t *)v27 + 3074) = (uint8_t)v34;
    v35[3] = v37;
    if ( v36 )
    {
      v38 = v36 - 1;
      v39 = *(volatile uint32_t *)off_11EC90;
      *v28 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11EC80 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        rx_packet_isr(_frame.a4_2, v10, &_frame.a4);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        tx_packet_isr((void *)(_frame.a4_2), v10, &_frame.a4);
      }
      else
      {
        rx_adv_packet_isr((void *)(_frame.a4_2), v10, v3, (void *)(&_frame.a4), 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      timer_count_read((volatile uint64_t *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = (volatile int *)off_11EE98;
        v41 = *((volatile uint32_t *)off_11EE98 + 1);
        *(volatile uint32_t *)(v8 + 100) = dword_11EE9C;
        *(volatile uint32_t *)(v8 + 104) = v8 + 48;
        v42 = dword_11EEA0;
        *(volatile uint32_t *)(v8 + 108) = v2;
        *(volatile uint32_t *)(v41 + 32) = v8 + 104;
        *(volatile uint32_t *)(v8 + 112) = v42;
        *(volatile uint32_t *)(v8 + 116) = 58;
        *(volatile uint32_t *)(v8 + 120) = 58;
        _frame.a2 = v8 + 104;
        *(volatile uint32_t *)(v8 + 124) = 262148;
        *(volatile uint32_t *)(v8 + 136) = 0;
        goto LABEL_41;
      }
      if ( v11 != 1 )
      {
        if ( v11 == 2 )
        {
          v20 = (volatile uint16_t *)off_11EEC0;
          if ( *((volatile uint8_t *)off_11EEC0 + 2) )
          {
LABEL_17:
            v21 = v1[1];
            v1[2] = *v20 + 58;
            *(volatile uint8_t *)(v21 + 3) &= 0x3Fu;
            *((volatile uint8_t *)v1 + 14) = *((volatile uint8_t *)v20 + 3);
            *v1 = 0;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_11EC90 = 1;
            }
            v22 = (volatile int *)off_11EC94;
            v23 = dword_11EC98;
            ++*(volatile uint32_t *)off_11EC94;
            check_abort_flag(v23, v1);
            rf_calib_init();
            if ( *v22 )
            {
              v24 = *v22 - 1;
              v25 = *(volatile uint32_t *)off_11EC90;
              *v22 = v24;
              if ( !v24 )
              {
                if ( v25 )
                  __enable_irq();
              }
            }
            *(volatile uint32_t *)v20 = 0;
            *((volatile uint32_t *)v20 + 1) = 0;
            if ( **v5 != 3 )
              return tx_timestamp_get(v8, _frame.a4_2[0]);
            goto LABEL_65;
          }
        }
        return tx_timestamp_get(v8, _frame.a4_2[0]);
      }
      v12 = (volatile int *)off_11EC84;
      if ( *((volatile uint8_t *)off_11EC84 + 32) )
      {
        v51 = (void *)(uintptr_t)(critical_enter_0());
        v52 = (int)v51;
        if ( v51 )
        {
          if ( *((volatile uint8_t *)v12 + 32) )
          {
            v53 = *v12;
            v54 = v12[1] + 1;
            v51[2] = (v54 << 24) & 0x7F000000 | v51[2] & 0x80FFFFFF;
            v12[1] = v54;
            rf_set_tx_channel(v51, v8 + 48, v53, 0x3Au, 0);
            v55 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11EEC4)[48]);
            v12[3] += 58;
            if ( v55 )
              bt_notify_event(v52);
            else
              ke_int_lock(v52, v12[1], v12[2]);
            v56 = (void *)(uintptr_t)(off_11EEC8);
            v57 = *(volatile uint8_t *)off_11EEC8;
            v12[1] = 0;
            v12[3] = 0;
            *v12 = 0;
            v12[2] = 0;
            *((volatile uint8_t *)v12 + 32) = 0;
            v58 = *v5;
            *v56 = v57 | 1;
            v19 = *v58;
            if ( v19 == 2 )
              goto LABEL_16;
            goto LABEL_64;
          }
        }
        else
        {
          *(volatile uint8_t *)(v8 + 16) |= 1u;
          ke_event_schedule_1(aNoTxDscrHdr_0);
          *((volatile uint8_t *)v12 + 32) = 0;
        }
      }
      state_check_feature(1024, aNoTxDscrHdr);
      v13 = *v12;
      *(volatile uint8_t *)(v8 + 16) |= 1u;
      if ( v13 && v12[1] )
      {
        v14 = v8;
        v15 = 0;
        v16 = (volatile uint32_t *)v13;
        v17 = v14;
        do
        {
          v18 = v16;
          v16 = (volatile uint32_t *)v16[1];
          critical_enter_1(v18);
          ++v15;
        }
        while ( v15 < (unsigned int)v12[1] );
        v8 = v17;
      }
      v12[1] = 0;
      v12[3] = 0;
      *v12 = 0;
      v12[2] = 0;
      v19 = **v5;
      if ( v19 == 2 )
      {
LABEL_16:
        v20 = (volatile uint16_t *)off_11EC8C;
        if ( *((volatile uint8_t *)off_11EC8C + 2) )
          goto LABEL_17;
        return tx_timestamp_get(v8, _frame.a4_2[0]);
      }
LABEL_64:
      if ( v19 == 3 )
      {
LABEL_65:
        v40 = (volatile int *)off_11EE98;
LABEL_41:
        ke_event_process(*v40, _frame.a2, 5);
        while ( (*(volatile uint32_t *)off_11EEA4 & 0x800) == 0 )
          ;
        v43 = *(volatile uint32_t *)off_11EEA4;
        if ( (*(volatile uint32_t *)off_11EEA4 & 0x40000) != 0 )
          *(volatile uint32_t *)off_11EEA4 |= 0x4000000u;
        if ( (v43 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(volatile uint32_t *)(dword_11EEA8 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((volatile uint32_t *)off_11EEB4 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_11EEAC = 1;
            }
            v45 = (void *)(uintptr_t)(off_11EEB0);
            v46 = (void *)(uintptr_t)(off_11EEB4);
            v47 = *(volatile uint32_t *)off_11EEB0;
            v48 = *(volatile uint32_t *)off_11EEB0 + 1;
            *(volatile uint32_t *)off_11EEB0 = v48;
            v46[5] = 0;
            if ( v48 )
            {
              v49 = (void *)(uintptr_t)(off_11EEAC);
              *v45 = v47;
              if ( !v47 )
              {
                if ( *v49 )
                  __enable_irq();
              }
            }
          }
        }
        v50 = (void *)(uintptr_t)(off_11EEB8);
        while ( !*(volatile uint32_t *)off_11EEB8 )
          ;
        check_abort_flag(((volatile uint32_t *)(uintptr_t)off_11EEBC)[0] + 556, (volatile uint32_t *)(v2 - 20));
        *v50 = 1;
        pmu_ctrl_write_8();
        return tx_timestamp_get(v8, _frame.a4_2[0]);
      }
      return tx_timestamp_get(v8, _frame.a4_2[0]);
    }
  }
  else
  {
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11EC80 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return ke_int_lock_1((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return ke_int_lock_1((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}


// tx_packet_finish @ 0x11eee0
int tx_packet_finish(int a1) {
  void *v2; // r0
  volatile uint32_t *v3; // r1
  int v4; // r0
  char v5; // r2

  tx_timestamp_get(a1, *(volatile uint32_t *)(a1 + 28));
  v2 = (void *)(uintptr_t)(off_11EF30);
  if ( *((volatile uint32_t *)off_11EF30 + 14) )
  {
    *(volatile uint8_t *)(a1 + 16) |= 1u;
    *(volatile uint32_t *)(a1 + 4) = 0;
    v3 = (volatile uint32_t *)a1;
    v4 = (int)v2 + 56;
    return check_abort_flag(v4, v3);
  }
  v4 = off_11EF34;
  if ( *(volatile uint32_t *)off_11EF34 )
  {
    v5 = *(volatile uint8_t *)(a1 + 16);
    *(volatile uint32_t *)(a1 + 4) = 0;
    *(volatile uint8_t *)(a1 + 16) = v5 | 1;
    v3 = (volatile uint32_t *)a1;
    return check_abort_flag(v4, v3);
  }
  return rf_tx_timestamp_check(a1);
}


// mac_irq_check @ 0x11ef38
unsigned int mac_irq_check() {
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((volatile uint32_t *)off_11EF6C + 2);
  if ( v0 == *(volatile uint32_t *)off_11EF70 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((volatile uint32_t *)off_11EF6C + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(volatile uint32_t *)off_11EF6C )
      v2 += 0x80000000;
    v3 = v2 | *(volatile uint32_t *)off_11EF6C;
    *((volatile uint32_t *)off_11EF6C + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}



// rx_timeout_check @ 0x11ef74
int rx_timeout_check(int result) {
  int v1; // r4
  int16_t v2; // r2
  void *v3; // r1

  v1 = result;
  if ( **(volatile int16_t **)off_11EFF0 < 0 && *(volatile uint32_t *)(result + 20) != dword_11EFF8 )
    result = mmio_irq_clear(dword_11F000, dword_11EFFC, 1811);
  v2 = *(volatile uint16_t *)(v1 + 48);
  if ( v2 )
  {
    switch ( *(volatile uint32_t *)(v1 + 84) & 0x7C )
    {
      case 4:
      case 8:
        *(volatile uint16_t *)(v1 + 48) = v2 - 8;
        break;
      case 0xC:
        *(volatile uint16_t *)(v1 + 48) = v2 - 12;
        break;
      case 0x10:
      case 0x14:
      case 0x18:
      case 0x1C:
        *(volatile uint16_t *)(v1 + 48) = v2 - 20;
        break;
      default:
        *(volatile uint16_t *)(v1 + 48) = v2 - 4;
        break;
    }
  }
  v3 = (void *)(uintptr_t)(off_11EFF4);
  *(volatile uint8_t *)(v1 + 16) = 2;
  *(volatile uint8_t *)(v1 + 156) = 0;
  *(volatile uint32_t *)(v1 + 12) = v1;
  *(volatile uint32_t *)(v1 + 4) = (int)(uintptr_t)(v3);
  return result;
}



// rf_clock_reset @ 0x11f004
int rf_clock_reset() {
  volatile uint32_t *v0; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11F034);
  *(volatile uint32_t *)off_11F030 = 0x10000;
  *v0 &= ~0x10000u;
  result = set_system_flag_1(0x80000);
  if ( *(volatile uint8_t *)off_11F038 )
    return util_wait_loop(result);
  return result;
}



// mac_irq_handler_1 @ 0x11f03c
void mac_irq_handler_1() {
  volatile uint32_t *v0; // r5
  volatile uint32_t *v1; // r6
  int v2; // r3
  int v3; // r7
  volatile uint32_t *v4; // r8
  int v5; // r3
  int v6; // r4
  int v7; // r2
  int v8; // r12
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r2

  v0 = (void *)(uintptr_t)(off_11F0C0);
  v1 = (void *)(uintptr_t)(off_11F0C4);
  v2 = *((volatile uint32_t *)off_11F0C0 + 5);
  if ( v2 != *(volatile uint32_t *)off_11F0C4 )
  {
    v3 = dword_11F0C8;
    v4 = (void *)(uintptr_t)(off_11F0D0);
    do
    {
      v8 = v0[4];
      v9 = v2 & 0x7FFFFFFF;
      v10 = v8 - (v2 & 0x7FFFFFFF);
      v11 = v2 & 0x80000000;
      if ( v10 > 0x9F )
      {
        v5 = v0[5];
      }
      else
      {
        v12 = v0[3];
        if ( v9 > v12 )
          v11 += 0x80000000;
        v5 = v11 | v12;
        v0[5] = v5;
      }
      v6 = v5 & 0x7FFFFFFF;
      v7 = *(volatile uint32_t *)((v5 & 0x7FFFFFFF) + 0x14);
      if ( v7 != v3 )
        ke_event_schedule_1(
          "rxbuf2 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
          v5 & 0x7FFFFFFF,
          v7,
          v0[3],
          v8,
          v5,
          *v1,
          *v4);
      rx_timeout_check(v6);
      *(volatile uint8_t *)(v6 + 156) = 1;
      tx_timeout_check(v6);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}


// timer_timestamp_get @ 0x11f0d4
volatile uint64_t *timer_timestamp_get() {
  volatile uint64_t *result; // r0
  struct __attribute__((packed)) { uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]
  } _frame;
  _frame.v2 = *(volatile uint32_t *)off_11F118;
  _frame.v3 = *(volatile uint32_t *)dword_11F11C;
  _frame.v4 = *(volatile uint32_t *)(dword_11F11C + 8 + 0xFFFFFFFC);
  _frame.v5 = *(volatile uint32_t *)(dword_11F11C + 8);
  result = timer_count_read(&_frame.v1, 0);
  if ( (_frame.v2 & 0xF) == 2 )
    return (volatile uint64_t *)dispatch_if_ready((int)(uintptr_t)(&_frame.v1));
  return result;
}



// wlc_bsscfg_llc_flush @ 0x11f120
volatile int * wlc_bsscfg_llc_flush(int a1) {
  int v2; // r5
  int v3; // r0
  volatile int *result; // r0
  int v5; // r3

  v2 = a1 + 572;
  while ( *(volatile uint32_t *)(a1 + 572) )
  {
    v3 = (int)(uintptr_t)(list_pop_front(v2));
    ble_conn_event_handler(v3, 1);
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



// wlc_attach @ 0x11f16c
int wlc_attach() {
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

  v0 = dword_11F268;
  v1 = dword_11F264;
  zero_struct((volatile uint32_t *)dword_11F264);
  v2 = (volatile uint32_t *)(v0 + 22272);
  do
  {
    wlc_bsscfg_llc_flush(v0 - 624);
    check_abort_flag(v1, (volatile uint32_t *)(v0 - 624));
    v3 = (volatile uint32_t *)(v0 - 40);
    do
    {
      zero_struct(v3);
      v4 = v3 + 10;
      v3 += 2;
      zero_struct(v4);
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
      zero_struct(v6);
      v7 = v6 + 10;
      v6 += 2;
      zero_struct(v7);
    }
    while ( v6 != v2 );
    v2 = v6 + 174;
  }
  v8 = off_11F26C;
  v9 = dword_11F270;
  v10 = dword_11F274;
  wlc_bsscfg_llc_flush(off_11F26C);
  *(volatile uint32_t *)(v8 + 0x20) = 0x20000000;
  *(volatile uint32_t *)(v8 + 0x150) = v9;
  *(volatile uint32_t *)(v8 + 0xBC) = v10;
  *(volatile uint8_t *)(v8 + 0x34) = 0;
  wlc_bsscfg_llc_flush(v8 + 696);
  *(volatile uint32_t *)(v8 + 0x408) = v9 + 64;
  v11 = dword_11F278;
  *(volatile uint32_t *)(v8 + 0x374) = v10 + 1320;
  *(volatile uint32_t *)(v8 + 0x2D8) = v11;
  *(volatile uint8_t *)(v8 + 0x2EC) = 0;
  wlc_bsscfg_llc_flush(v8 + 1392);
  *(volatile uint32_t *)(v8 + 0x6C0) = v9 + 128;
  *(volatile uint32_t *)(v8 + 0x590) = dword_11F27C;
  *(volatile uint8_t *)(v8 + 0x5A4) = 0;
  *(volatile uint32_t *)(v8 + 0x62C) = v10 + 2640;
  result = (int)(uintptr_t)(wlc_bsscfg_llc_flush(v8 + 2088));
  v13 = dword_11F280;
  *(volatile uint8_t *)(v8 + 0x85C) = 0;
  *(volatile uint32_t *)(v8 + 0x978) = v9 + 192;
  *(volatile uint32_t *)(v8 + 0x8E4) = v10 + 3960;
  *(volatile uint32_t *)(v8 + 0x848) = v13;
  return result;
}


// wlc_detach @ 0x11f284
int wlc_detach(volatile int *a1, volatile uint8_t *a2) {
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
  v5 = list_pop_front(dword_11F47C);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((volatile uint8_t *)a1 + 29) )
  {
    v35 = list_pop_front(dword_11F47C);
    if ( !v35 )
    {
      check_abort_flag(dword_11F47C, v6);
      return 1;
    }
    v6[11] = (int)(uintptr_t)(v35);
    v35[11] = (int)(uintptr_t)(v6);
    v36 = *((volatile uint8_t *)a1 + 30);
    v8 = (volatile char *)a1 + 18;
    v37 = *((volatile uint8_t *)a1 + 29);
    *(volatile uint32_t *)((volatile char *)v35 + 38) = *(volatile int *)((volatile char *)a1 + 18);
    *((volatile uint16_t *)v35 + 21) = *((volatile uint16_t *)a1 + 11);
    v7 = dword_11F480;
    v38 = ((1 << v36) - 1) << 8;
    v39 = *((volatile uint16_t *)v35 + 21) & ~v38;
    *((volatile uint16_t *)v35 + 21) = v39;
    v40 = v38 & (*((volatile uint16_t *)a1 + 11) - (v37 << 8)) | v39;
    v41 = dword_11F484 * (((int)v35 - v7) >> 3);
    *((volatile uint16_t *)v35 + 21) = v40;
    *((volatile uint8_t *)v35 + 35) = v41;
    *((volatile uint16_t *)v35 + 16) = -1;
  }
  else
  {
    v7 = dword_11F480;
    v8 = (volatile char *)a1 + 18;
  }
  v9 = *(volatile uint32_t *)v8;
  v10 = *a1;
  *((volatile uint16_t *)v6 + 21) = *((volatile uint16_t *)v8 + 2);
  *(volatile uint32_t *)((volatile char *)v6 + 38) = v9;
  v6[1] = v10;
  v11 = *((volatile uint8_t *)a1 + 24);
  v12 = dword_11F484;
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
  state_check_feature(256, aSStaIdxD, aStaMgmtRegiste);
  v14 = dword_11F490;
  v15 = dword_11F490 + 1320 * v3;
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
  v6[84] = dword_11F494 + (v20 << 6);
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
  check_abort_flag(v14 + v19 + 240, v6);
  v6[145] = dword_11F49C;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11F4A0 = 1;
  }
  v26 = (void *)(uintptr_t)(off_11F4A4);
  v27 = v6[11];
  v28 = *(volatile uint32_t *)off_11F4A4;
  v29 = *(volatile uint32_t *)off_11F4A4 + 1;
  *(volatile uint32_t *)off_11F4A4 = v29;
  *((volatile uint8_t *)v6 + 37) = 1;
  if ( v27 )
    *(volatile uint8_t *)(v27 + 37) = 1;
  if ( v29 )
  {
    v30 = (void *)(uintptr_t)(off_11F4A0);
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


// wlc_phy_cal_init @ 0x11f4a8
/* luna: Unregisters a station management context by clearing its list/registration state, adjusting interface association counters, flushing LLC queues, and f */
int wlc_phy_cal_init(int a1) {
  int sta_mgmt_base; // r7
  int vif_info_base; // r8
  int sta_ctx; // r4
  int vif_info_offset; // r6
  volatile uint32_t *v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r12
  int result; // r0
  volatile int *v12; // r0
  int irq_save_state; // r2
  volatile int *v14; // r3

  sta_mgmt_base = dword_11F5AC;
  vif_info_base = dword_11F5C8;
  sta_ctx = dword_11F5AC + 696 * a1;
  vif_info_offset = 1320 * *(volatile uint8_t *)(sta_ctx + 34);
  if ( *(volatile uint8_t *)(dword_11F5C8 + vif_info_offset + 1224) )
    --*(volatile uint8_t *)(dword_11F5C8 + vif_info_offset + 1226);
  state_check_feature(256, "%s: sta_idx=%d\n", aStaMgmtUnregis, a1);
  check_abort_flag_3(vif_info_offset + 240 + vif_info_base, (volatile uint32_t *)sta_ctx);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11F5B8 = 1;
  }
  v6 = (void *)(uintptr_t)(off_11F5BC);
  v7 = sta_mgmt_base + 696 * a1;
  v8 = *(volatile uint32_t *)off_11F5BC;
  v9 = *(volatile uint32_t *)(v7 + 44);
  v10 = *(volatile uint32_t *)off_11F5BC + 1;
  *(volatile uint32_t *)off_11F5BC = v10;
  *(volatile uint8_t *)(v7 + 37) = 0;
  if ( v9 )
  {
    *(volatile uint8_t *)(v9 + 37) = 0;
    if ( !v10 )
    {
LABEL_7:
      wlc_bsscfg_llc_flush(v9);
      check_abort_flag(dword_11F5C0, *(volatile uint32_t **)(sta_mgmt_base + 696 * a1 + 44));
      goto LABEL_8;
    }
    v12 = (volatile int *)off_11F5B8;
    *v6 = v8;
    irq_save_state = *v12;
    if ( v8 )
    {
      v9 = *(volatile uint32_t *)(v7 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v10 )
      goto LABEL_8;
    v14 = (volatile int *)off_11F5B8;
    *v6 = v8;
    irq_save_state = *v14;
    if ( v8 )
      goto LABEL_8;
  }
  if ( irq_save_state )
    __enable_irq();
  v9 = *(volatile uint32_t *)(sta_mgmt_base + 696 * a1 + 44);
  if ( v9 )
    goto LABEL_7;
LABEL_8:
  wlc_bsscfg_llc_flush(sta_ctx);
  check_abort_flag(dword_11F5C0, (volatile uint32_t *)sta_ctx);
  result = find_pending_command();
  if ( !result )
  {
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11F5C4)[102]) )
      return dma_tx_setup(vif_info_base + vif_info_offset);
    else
      return write_mmio_byte(0xC2u);
  }
  return result;
}


// wlc_phy_radio_set @ 0x11f5d0
int wlc_phy_radio_set(int a1, uint8_t a2) {
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
  v3 = dword_11F6EC;
  v4 = (volatile uint8_t *)(dword_11F6EC + 696 * v2);
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
      v9 = random(v8);
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
      v16 = *(volatile uint8_t *)(dword_11F6E8 + 1320 * v7 + 106);
      v17 = v3 + 696 * v2;
      *(volatile uint64_t *)(v17 + 136) = *(volatile uint64_t *)&dword_11F6D8;
      if ( v16 == 2 )
        *(volatile uint64_t *)(v17 + 136) = *(volatile uint64_t *)&dword_11F6E0;
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



// wlc_phy_band_init @ 0x11f6f0
int wlc_phy_band_init(int result) {
  *(volatile uint8_t *)(result + 52) = 1;
  *(volatile uint8_t *)(result + 163) = 0;
  *(volatile uint32_t *)(result + 184) = 0;
  return result;
}



// wlc_bsscfg_down @ 0x11f704
int wlc_bsscfg_down(int a1, int a2, int a3) {
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
    if ( !init_once(a1) )
      break;
    if ( !phy_check_core_mode(v3) )
      break;
    v10 = (int)(uintptr_t)(txpwr_process_config(a1, a2, (void *)(&v12)));
    if ( v12 )
      break;
    if ( !v10 )
      v10 = (int)(uintptr_t)(list_pop_front(v8));
    v9 = *(volatile uint8_t *)(v10 + 27);
    *(volatile uint8_t *)(v10 + 97) = 0;
    ++v4;
    conn_rx(v10, v9);
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



// wlc_bsscfg_dump @ 0x11f780
int wlc_bsscfg_dump(int a1, int a2, int a3) {
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
  while ( init_once(a1) )
  {
    v9 = 0;
    while ( 1 )
    {
      v10 = (uint8_t)v9;
      if ( *(volatile uint32_t *)(v7 + 8 * v9) )
      {
        v11 = (int)(uintptr_t)(list_pop_front(a2 + 8 * (v9 + 78)));
        goto LABEL_9;
      }
      if ( *(volatile uint32_t *)(v8 + 8 * v9) )
        break;
      if ( ++v9 == 4 )
        return v3;
    }
    v11 = (int)(uintptr_t)(list_pop_front(a2 + 8 * (v9 + 73)));
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
    ((int (*)())tx_prepare_frame_path)(v11, v10, v12);
    ++v3;
    ke_int_disable(v10);
    if ( a3 )
    {
      if ( v3 == a3 )
        break;
    }
  }
  return v3;
}



