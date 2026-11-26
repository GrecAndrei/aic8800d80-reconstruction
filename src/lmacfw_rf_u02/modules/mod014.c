// wlan_tx_enqueue @ 0x1164c4
int wlan_tx_enqueue(int a1, int a2, int a3) {
  uint64_t v3; // kr00_8
  int v6; // r1
  int v7; // r7
  int result; // r0
  int v9; // r2
  int v10; // r3
  int v11; // r2
  uint64_t v12; // kr08_8

  v3 = *(volatile uint64_t *)(a1 + 28);
  if ( a3 > 4096 )
  {
    v12 = (unsigned int)dword_11657C * (uint64_t)(unsigned int)(v3 - dword_116578);
    *(volatile uint32_t *)(HIDWORD(v3) + 28) = *(volatile uint32_t *)(HIDWORD(v3) + 24) + 4095;
    *(volatile uint32_t *)(HIDWORD(v3) + 32) = init_timer_slot((void *)(uintptr_t)(HIDWORD(v3) + 8), a3, HIDWORD(v12) >> 12) + 4;
  }
  else
  {
    *(volatile uint32_t *)(HIDWORD(v3) + 28) = *(volatile uint32_t *)(HIDWORD(v3) + 24) + a3 - 1;
    *(volatile uint32_t *)(HIDWORD(v3) + 32) = a3 + 4;
    *(volatile uint32_t *)(HIDWORD(v3) + 20) = 0;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
      v6 = dword_116574;
    else
      v6 = v3 + 44;
    v7 = v3 + 44;
  }
  else
  {
    v6 = dword_116570;
    v7 = v3 + 44;
  }
  result = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(v7), (void *)(uintptr_t)(v6), 52));
  v9 = *(volatile uint32_t *)off_11656C;
  if ( *(volatile uint32_t *)(v3 + 64) & 0x7C | (*(volatile uint32_t *)(v3 + 64) >> 11) & 6 )
    v10 = (uint16_t)((uint16_t)*(volatile uint32_t *)off_11656C << 8) | (uint8_t)v9;
  else
    v10 = *(volatile uint32_t *)off_11656C & 0xFF00 | BYTE1(v9);
  v11 = *(volatile uint32_t *)(a1 + 28);
  *(volatile uint32_t *)(v3 + 80) = v10;
  *(volatile uint32_t *)(HIDWORD(v3) + 40) = 0;
  *(volatile uint32_t *)(HIDWORD(v3) + 44) = v7;
  *(volatile uint32_t *)(HIDWORD(v3) + 64) = 0;
  *(volatile uint32_t *)(a1 + 44) = 0;
  *(volatile uint32_t *)(a1 + 48) = 0;
  *(volatile uint32_t *)(v11 + 40) = 0;
  *(volatile uint16_t *)(a1 + 38) = 0;
  return result;
}



// call_global_185c7c @ 0x116580
volatile uint32_t * call_global_185c7c(int a1, int a2) {
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r4

  v4 = list_pop_front(dword_1165A8);
  v5 = v4;
  if ( v4 )
  {
    wlan_tx_enqueue((int)v4, a1, a2);
    return v5;
  }
  else
  {
    dispatch_event_handler_1(aNoTxlFrame);
    return nullptr;
  }
}


// wlan_tx_submit @ 0x1165b0
int wlan_tx_submit(int a1, int a2) {
  uint64_t v2; // kr00_8
  int v5; // r2

  v2 = *(volatile uint64_t *)(a1 + 28);
  if ( **(volatile int16_t **)off_116600 < 0 && (*(volatile uint32_t *)(HIDWORD(v2) + 24) & 1) != 0 )
    flash_ctrl_init(dword_116608, dword_116604, 389);
  v5 = *(volatile uint32_t *)(HIDWORD(v2) + 40);
  *(volatile uint32_t *)(HIDWORD(v2) + 64) &= 0xFF87FFFF;
  *(volatile uint64_t *)(HIDWORD(v2) + 12) = 0;
  *(volatile uint32_t *)(HIDWORD(v2) + 60) = 0;
  *(volatile uint32_t *)(HIDWORD(v2) + 68) = 0;
  *(volatile uint32_t *)(v2 + 96) = 0;
  *(volatile uint32_t *)(v2 + 100) = v5;
  return llm_scan_pdu_cfg(a1, a2);
}



// log_and_disable_irq @ 0x11660c
int log_and_disable_irq(volatile uint32_t *a1) {
  check_kernel_state(dword_116624, a1);
  return set_busy_flag_alt(0x200000);
}


// wlan_tx_kick @ 0x116628
int wlan_tx_kick(int result, int a2) {
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(volatile uint8_t *)(result + 52) )
    result = check_kernel_state(dword_116650, (volatile uint32_t *)result);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 44);
    if ( v4 )
      return v4(*(volatile uint32_t *)(v2 + 48), 0);
  }
  return result;
}


// pool_alloc_init @ 0x116654
volatile uint32_t *pool_alloc_init() {
  volatile int *v0; // r5
  volatile int *v1; // r7
  int v2; // r6
  volatile uint32_t *result; // r0
  volatile uint32_t *v4; // r4
  int v5; // r2
  int v6; // r3
  void ( *v7)(uint32_t, uint32_t); // r3

  enter_critical_section_1(0x200000);
  v0 = (volatile int *)off_1166BC;
  v1 = (volatile int *)off_1166C0;
  v2 = dword_1166C4;
  while ( 1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v1 = 1;
    }
    ++*v0;
    result = list_pop_front(v2);
    v4 = result;
    v5 = *v0 - 1;
    if ( *v0 )
    {
      v6 = *v1;
      *v0 = v5;
      if ( !v5 )
      {
        if ( v6 )
          __enable_irq();
      }
    }
    if ( !result )
      break;
    v7 = (void ( *)(uint32_t, uint32_t))result[11];
    if ( v7 )
      v7(result[12], *(volatile uint32_t *)(result[8] + 68));
    if ( !*((volatile uint8_t *)v4 + 52) )
      check_kernel_state(dword_1166C8, v4);
  }
  return result;
}


// rate_index_lookup @ 0x1166cc
int rate_index_lookup(int a1, int a2, int a3) {
  int v3; // r10
  int v4; // r11
  int v6; // r5
  int v8; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  int16_t v15; // r1
  int v16; // r0
  int16_t v17; // r5
  int v18; // r0
  int16_t v19; // r5
  char v20; // r2
  int v22; // r1
  int v23; // r0
  int16_t v24; // r2
  int v25; // r0

  v3 = dword_116830;
  v4 = dword_116834;
  v6 = *(volatile uint8_t *)(dword_116830 + 152 * a1 + 32);
  v8 = *(volatile uint32_t *)(dword_116834 + 224 * v6 + 72);
  if ( !v8 )
  {
    if ( **(volatile int16_t **)off_116820 >= 0 )
    {
LABEL_9:
      v11 = (int)(uintptr_t)(call_global_185c7c(1, 24));
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    flash_ctrl_init(dword_11682C, dword_116828, 520);
    goto LABEL_9;
  }
  v10 = *(volatile uint8_t *)(v8 + 4);
  if ( **(volatile int16_t **)off_116820 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = (int)(uintptr_t)(call_global_185c7c(v10 != 0, 24));
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 224 * v6;
  rf_init_check(v12, v11);
  v13 = *(volatile uint32_t *)(v11 + 28);
  if ( *(volatile uint8_t *)(v12 + 94) == 2 )
  {
    v22 = v3 + 152 * a1;
    *(volatile uint32_t *)(v13 + 108) = *(volatile uint32_t *)(v22 + 36);
    v22 = (v22 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v22 + 40)) & 0xFFFFu);
    v23 = *(volatile uint32_t *)(v12 + 88);
    *(volatile uint8_t *)(v13 + 105) = 2;
    *(volatile uint32_t *)(v13 + 114) = v23;
    v24 = *(volatile uint16_t *)(v12 + 92);
    v25 = *(volatile uint32_t *)(v12 + 88);
    *(volatile uint16_t *)(v13 + 112) = v22;
    *(volatile uint16_t *)(v13 + 118) = *(volatile uint16_t *)(v12 + 92);
    *(volatile uint8_t *)(v13 + 106) = 0;
    *(volatile uint8_t *)(v13 + 107) = 0;
    *(volatile uint8_t *)(v13 + 104) = 72;
    *(volatile uint32_t *)(v13 + 120) = v25;
    *(volatile uint16_t *)(v13 + 124) = v24;
  }
  else
  {
    v14 = v3 + 152 * a1;
    v15 = *(volatile uint16_t *)(v12 + 92);
    *(volatile uint32_t *)(v13 + 108) = *(volatile uint32_t *)(v14 + 36);
    v16 = *(volatile uint32_t *)(v12 + 88);
    v17 = *(volatile uint16_t *)(v14 + 40);
    *(volatile uint32_t *)(v13 + 114) = v16;
    v18 = *(volatile uint32_t *)(v14 + 36);
    *(volatile uint16_t *)(v13 + 112) = v17;
    *(volatile uint16_t *)(v13 + 118) = v15;
    *(volatile uint32_t *)(v13 + 120) = v18;
    *(volatile uint16_t *)(v13 + 124) = v17;
    *(volatile uint8_t *)(v13 + 106) = 0;
    *(volatile uint8_t *)(v13 + 107) = 0;
    *(volatile uint8_t *)(v13 + 104) = 72;
    *(volatile uint8_t *)(v13 + 105) = 1;
  }
  v19 = *((volatile uint16_t *)off_116824 + 70) + 1;
  *((volatile uint16_t *)off_116824 + 70) = v19;
  v20 = *(volatile uint8_t *)(v3 + 152 * a1 + 32);
  *(volatile uint16_t *)(v13 + 126) = 16 * v19;
  *(volatile uint32_t *)(v11 + 44) = a2;
  *(volatile uint32_t *)(v11 + 48) = a3;
  *(volatile uint8_t *)(v11 + 15) = v20;
  *(volatile uint8_t *)(v11 + 16) = a1;
  wlan_tx_submit(v11, 5);
  return 0;
}



// rate_index_lookup_fast @ 0x116838
int rate_index_lookup_fast(int a1, int a2, int a3) {
  return rate_index_lookup(a1, a2, a3);
}



// event_count_update @ 0x11683c
int event_count_update() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_116854);
  v1 = (int)(uintptr_t)(list_init_1((void *)(uintptr_t)(off_116854)));
  result = (uint8_t)(return_2(v1) - 1);
  v0[11] = result;
  v0[10] = result;
  return result;
}



// wlan_rx_process @ 0x116858
/* luna: Handles an incoming 802.11 RX PBD by validating the security key and station context and updating RX status and counter fields. */
int wlan_rx_process(int a1) {
  volatile int16_t **v1; // r7
  int v2; // r5
  int v3; // r1
  volatile int16_t *pbd_data_ptr; // r0
  int16_t frame_control; // r8
  unsigned int rx_status; // r3
  int key_idx; // r6
  unsigned int sec_desc; // r2
  int v11; // r5
  int sta_idx; // r9
  unsigned int sta_table_base; // r3
  unsigned int sta_entry; // r2
  int v15; // r2
  int v16; // r11
  int v17; // r8
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r8
  volatile uint32_t *v20; // r4
  volatile unsigned int v21; // r6
  unsigned int v22; // r3
  volatile unsigned int v23; // r6
  volatile uint32_t *v24; // r11
  volatile uint32_t *v25; // r10
  int v26; // r4
  unsigned int v27; // r9
  int v28; // r4
  int v29; // r0
  uint64_t v30; // r0
  uint64_t v31; // r6
  uint64_t v32; // r0
  uint64_t v33; // r0
  uint64_t v34; // r0
  int v35; // r0
  int v36; // r11
  volatile uint32_t *v37; // r4
  int v38; // r1
  unsigned int v39; // r3
  int v40; // r3
  int v41; // r2
  volatile uint32_t *v42; // r4
  int v43; // r2
  unsigned int v44; // r3
  struct __attribute__((packed)) { int v45; // [sp+4h] [bp-10h]
  char _pad1[4]; volatile uint8_t *a4; // [sp+Ch] [bp-8h] BYREF
  } _frame;
  if ( *(volatile uint16_t *)(a1 + 48) )
  {
    v1 = (volatile int16_t **)dword_116B48;
    v2 = *(volatile uint32_t *)(a1 + 28);
    v3 = **(volatile int16_t **)dword_116B48;
    if ( v3 < 0 && !v2 )
    {
      ke_int_lock_1((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v2;
    }
    pbd_data_ptr = *(volatile uint16_t **)(v2 + 8);
    frame_control = *pbd_data_ptr;
    rx_status = *(volatile uint32_t *)(a1 + 84);
    if ( *(volatile uint8_t *)(dword_116B4C + 0x198)
      && (*(volatile uint32_t *)(dword_116B50 + 4) & 0x40) != 0
      && (*(volatile uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (frame_control & 0xFC) == 0xC4 )
        ++*(volatile uint32_t *)dword_116B80;
    }
    else
    {
      if ( (dword_116B54 & ~rx_status) != 0 )
        return 0;
      *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v2 = (rx_status >> 15) & 0x1F0;
        if ( !v2 )
        {
          ke_int_lock_1((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v2;
        }
      }
      key_idx = (uint8_t)((rx_status >> 15) - 16);
      sec_desc = dword_116B58 + 152 * key_idx;
      v2 = *(volatile uint8_t *)(sec_desc + 35);
      if ( !*(volatile uint8_t *)(sec_desc + 35) )
      {
        *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFCFFFFFF;
        return v2;
      }
      if ( *(volatile uint16_t *)(sec_desc + 30) == 0xFFFF )
      {
        if ( (frame_control & 0xFC) != 0x80 )
        {
          *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFCFFFFFF;
          return 0;
        }
        v11 = *(volatile uint32_t *)(sec_desc + 44);
        *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFE007FFF | ((*(volatile uint8_t *)(v11 + 33) + 16) << 15);
      }
      else
      {
        v11 = dword_116B58 + 152 * key_idx;
      }
      sta_idx = *(volatile uint8_t *)(v11 + 32);
      sta_table_base = dword_116B5C;
      sta_entry = dword_116B5C + 224 * sta_idx;
      if ( !*(volatile uint8_t *)(sta_entry + 96) )
        return 0;
      v15 = *(volatile uint8_t *)(sta_entry + 94);
      v16 = 224 * sta_idx;
      if ( v15 )
      {
        if ( (frame_control & 4) != 0 )
          goto LABEL_44;
        goto LABEL_42;
      }
      if ( (frame_control & 0x300) != 0x200 )
      {
        if ( (frame_control & 4) != 0 )
        {
LABEL_17:
          v17 = frame_control & 0xFC;
          if ( v17 == 128 )
          {
            v36 = v16 + sta_table_base;
            _frame.a4 = nullptr;
            v2 = !timer_start_capture(a1 + 20, v36, v11, (void *)(&_frame.a4));
            setup_packet_buffer(v36);
            return v2;
          }
          if ( v17 == 80 )
          {
            v18 = (volatile uint32_t *)dword_116B60;
            _frame.v45 = *(volatile uint32_t *)dword_116B60 & 0xF;
            if ( _frame.v45 )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)dword_116B64 = 1;
              }
              v19 = (volatile uint32_t *)dword_116B8C;
              v20 = (volatile uint32_t *)dword_116B60;
              ++*(volatile uint32_t *)dword_116B8C;
              *v20 = 0;
              v21 = (*(volatile uint32_t *)0x40501010u);
              while ( 1 )
              {
                v2 = *v20 & 0xF;
                if ( !v2 )
                  break;
                v22 = (*(volatile uint32_t *)0x40501010u) - v21;
                if ( v22 > 0x7530 )
                  check_interrupt_flag(2, aIdleErr, 30000);
              }
              v23 = (*(volatile uint32_t *)0x40501010u);
              if ( (*(volatile uint32_t *)dword_116B70 & *(volatile uint32_t *)dword_116B6C & 4) == 0 )
              {
                v24 = (volatile uint32_t *)dword_116B6C;
                v25 = (volatile uint32_t *)dword_116B70;
                do
                {
                  v26 = *v25 & *v24;
                  if ( (*(volatile uint32_t *)0x40501010u) - v23 > 0x7530 )
                    check_interrupt_flag(2, aIdleIntErr);
                }
                while ( (v26 & 4) == 0 );
              }
              *(volatile uint32_t *)dword_116C28 = 4;
              if ( *v19 )
              {
                v40 = *v19 - 1;
                v41 = *(volatile uint32_t *)dword_116C2C;
                *v19 = v40;
                if ( !v40 )
                {
                  if ( v41 )
                    __enable_irq();
                }
              }
              v42 = (volatile uint32_t *)dword_116C30;
              v43 = **v1;
              v44 = *(volatile uint32_t *)(dword_116C30 + 4) & 0xFFFFFDFF;
              *(volatile uint32_t *)(dword_116C30 + 4) = v44;
              if ( v43 < 0 )
              {
                if ( *(volatile uint32_t *)dword_116C38 << 28 )
                {
                  flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
                  v44 = v42[1];
                }
              }
              *(volatile uint32_t *)dword_116C34 = v44 | *v42;
              *(volatile uint32_t *)dword_116C38 = 16 * _frame.v45;
              return v2;
            }
            v37 = (volatile uint32_t *)dword_116B50;
            v38 = **v1;
            v39 = *(volatile uint32_t *)(dword_116B50 + 4) & 0xFFFFFDFF;
            *(volatile uint32_t *)(dword_116B50 + 4) = v39;
            if ( v38 >= 0 )
            {
              v2 = 0;
              *(volatile uint32_t *)dword_116B88 = v39 | *v37;
              return v2;
            }
            v2 = *v18 & 0xF;
            if ( !v2 )
            {
              *(volatile uint32_t *)dword_116C34 = v39 | *v37;
              return v2;
            }
            flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
            *(volatile uint32_t *)dword_116C34 = v37[1] | *v37;
          }
          return 0;
        }
        goto LABEL_42;
      }
      v35 = memcmp((unsigned int)(pbd_data_ptr + 8), v16 + 88 + dword_116B5C, 6u);
      sta_table_base = dword_116B5C;
      if ( v35 )
      {
        if ( (frame_control & 4) != 0 )
        {
LABEL_43:
          v27 = sta_table_base + 224 * sta_idx;
          v15 = *(volatile uint8_t *)(v27 + 94);
          if ( !*(volatile uint8_t *)(v27 + 94) )
            goto LABEL_17;
LABEL_44:
          if ( v15 == 2 && *(volatile uint8_t *)(v11 + 33) <= 3u )
          {
            v28 = *(volatile char *)(a1 + 65);
            chip_info_nibble0_get();
            v29 = *(volatile char *)(v11 + 145);
            if ( !*(volatile uint8_t *)(v11 + 145) )
            {
              *(volatile uint8_t *)(v11 + 145) = v28;
              return v29;
            }
            v30 = aeabi_i2d(v29);
            v31 = ((uint64_t (*)())aeabi_dadd)(v30, *(volatile uint64_t *)&dword_116B38);
            v32 = aeabi_i2d(v28);
            v33 = ((uint64_t (*)())aeabi_dadd)(v32, *(volatile uint64_t *)&dword_116B40);
            v34 = double_add(v31, v33);
            *(volatile uint8_t *)(v11 + 145) = ((int (*)(uint64_t))double_to_float_1)(v34);
          }
          return 0;
        }
LABEL_42:
        tx_slot_ref(*(volatile uint8_t *)(sta_table_base + 224 * sta_idx + 95), key_idx, 1);
        sta_table_base = dword_116B5C;
        goto LABEL_43;
      }
    }
  }
  return 1;
}


// counter_increment @ 0x116c48
int counter_increment() {
  volatile uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_116C68);
  v1 = *((volatile uint8_t *)off_116C68 + 11);
  v2 = (uint8_t)(*((volatile uint8_t *)off_116C68 + 10) + 1);
  *((volatile uint8_t *)off_116C68 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}



// hw_timer_load @ 0x116c6c
int hw_timer_load() {
  volatile uint8_t *v0; // r4
  volatile unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_116C8C);
  if ( *((volatile uint8_t *)off_116C8C + 10) )
    result = j_nullsub_6();
  v1 = (volatile unsigned int *)off_116C90;
  v2 = *(volatile uint32_t *)off_116C90;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}



// call_sub_117410_then_11683c @ 0x116c94
int call_sub_117410_then_11683c() {
  ipc_regs_init();
  return event_count_update();
}



// timestamp_add @ 0x116ca4
int timestamp_add() {
  volatile uint32_t *v0; // r3
  uint64_t v1; // kr00_8
  uint64_t v2; // kr08_8

  v0 = (void *)(uintptr_t)(off_116CD0);
  v1 = *((volatile uint64_t *)off_116CCC + 17);
  v2 = *((volatile uint64_t *)off_116CCC + 18);
  *((volatile uint32_t *)off_116CD0 + 1) = HIDWORD(v1) + v1;
  v0[2] = v1;
  v0[3] = v2;
  v0[4] = HIDWORD(v2) + v2;
  *v0 = v1;
  v0[5] = v2;
  return event_count_update();
}



// disable_irq_800000 @ 0x116cd4
int disable_irq_800000() {
  return set_busy_flag_alt(0x800000);
}



// task_queue_handler_a @ 0x116cdc
int task_queue_handler_a() {
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

  v0 = (void *)(uintptr_t)(off_116D7C);
  v1 = *(volatile uint32_t *)off_116D7C;
  result = enter_critical_section_1(0x800000);
  if ( v1 )
  {
    v3 = (volatile int *)off_116D94;
    v4 = (volatile int *)off_116D80;
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
        result = timer_is_past(result);
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
    v8 = (void *)(uintptr_t)(off_116D8C);
    v9 = (void *)(uintptr_t)(off_116D90);
    *(volatile uint32_t *)off_116D88 = *((volatile uint32_t *)off_116D84 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}



// task_queue_handler_b @ 0x116d98
int task_queue_handler_b() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  volatile int *v3; // r8
  volatile int *v4; // r9
  int v5; // r7
  void ( *v6)(uint32_t); // r2
  int v7; // r3
  int v8; // r2

  v0 = (volatile int *)off_116E18;
  v1 = *(volatile uint32_t *)off_116E18;
  result = enter_critical_section_1(0x800000);
  if ( v1 )
  {
    v3 = (volatile int *)off_116E1C;
    v4 = (volatile int *)off_116E20;
    v5 = 0;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          return result;
        v5 = 1;
      }
      list_pop_front((int)(uintptr_t)(v0));
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
        result = timer_is_past(result);
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
  return result;
}



// task_queue_handler_c @ 0x116e24
int task_queue_handler_c() {
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

  v0 = (volatile int *)off_116EB4;
  v1 = *(volatile uint32_t *)off_116EB4;
  result = enter_critical_section_1(0x800000);
  if ( v1 )
  {
    v3 = (void *)(uintptr_t)(off_116EB8);
    if ( *(volatile uint16_t *)off_116EB8 )
    {
      v4 = (volatile int *)off_116EBC;
      v5 = (volatile int *)off_116EC0;
      do
      {
        if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        list_pop_front((int)(uintptr_t)(v0));
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
          result = timer_is_past(result);
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
    }
  }
  return result;
}



// mmio_regs_init @ 0x116ec4
int mmio_regs_init(int a1) {
  volatile uint32_t *v1; // r7
  volatile int *v2; // r9
  int v3; // r8
  volatile uint32_t *v4; // r11
  volatile uint32_t *v5; // r10
  int i; // r5
  int result; // r0
  int v9; // r2
  int v10; // r0
  int v11; // r3
  unsigned int v12; // r4
  void ( *v13)(uint32_t); // r2
  volatile uint32_t *v14; // r5
  int v15; // [sp+14h] [bp-8h]

  v1 = (void *)(uintptr_t)(off_116FFC);
  v2 = (void *)(uintptr_t)(off_117014);
  v3 = dword_117020;
  v4 = (void *)(uintptr_t)(off_117024);
  v5 = (void *)(uintptr_t)(off_117028);
  for ( i = 0; ; ++i )
  {
    v12 = timer_event_check();
    *v1 = 0x10000;
    result = enter_critical_section_1(0x400000);
    if ( !v12 )
      break;
    if ( !a1 )
    {
      if ( *((volatile uint8_t *)v2 + 192) )
      {
        if ( *(volatile uint32_t *)off_117000 > 0x400000u || i > 31 )
          return set_busy_flag_alt(0x400000);
      }
      else if ( i > 3 )
      {
        return set_busy_flag_alt(0x400000);
      }
    }
    result = patch_check_enabled();
    if ( !result )
      return result;
    v9 = *(volatile uint32_t *)(v12 + 20);
    if ( v9 != v3 )
      dispatch_event_handler_1(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v12,
        v9,
        *(volatile uint32_t *)off_117004,
        *((volatile uint32_t *)off_117004 + 1),
        *((volatile uint32_t *)off_117004 + 2),
        *v4,
        *v5);
    rf_cal_offset_apply(v12);
    v10 = wlan_rx_process(v12);
    if ( v10 )
    {
      if ( v10 == 1 )
        ll_event_timer_handler(v12);
    }
    else
    {
      tx_acl_queue_process(v12);
    }
    v11 = **(volatile uint8_t **)off_11700C;
    switch ( v11 )
    {
      case 2:
LABEL_22:
        task_queue_handler_c();
        continue;
      case 4:
        if ( !*(volatile uint32_t *)off_117010 || *(volatile uint32_t *)(*(volatile uint32_t *)off_117010 + 12) != v12 || (*(volatile uint8_t *)(v12 + 16) & 1) == 0 )
          goto LABEL_22;
        v15 = *(volatile uint32_t *)off_117010;
        list_pop_front(off_117010);
        v13 = *(void ( **)(uint32_t))(v15 + 4);
        *(volatile uint8_t *)(v15 + 16) = 0;
        if ( v13 )
          v13(*(volatile uint32_t *)(v15 + 8));
        timer_is_past(v12);
        break;
      case 3:
        task_queue_handler_b();
        break;
    }
  }
  if ( *((volatile uint8_t *)off_117014 + 192) )
  {
    v14 = (void *)(uintptr_t)(off_117018);
    if ( *((volatile uint8_t *)off_117018 + 33) )
    {
      result = irq_disable_set_flag_3(*((volatile uint32_t *)off_117018 + 4), *((volatile uint32_t *)off_117018 + 5), *((volatile uint32_t *)off_117018 + 6));
      v14[5] = 0;
      v14[7] = 0;
      v14[4] = 0;
      v14[6] = 0;
      *((volatile uint8_t *)v14 + 33) = 0;
    }
  }
  *(volatile uint32_t *)off_11701C |= 0x10000u;
  return result;
}


// wlan_rf_init @ 0x11702c
int wlan_rf_init(volatile int *a1, int a2, volatile uint16_t *a3) {
  volatile uint8_t *v3; // r7
  int v4; // r6
  int v5; // r5
  volatile int *v6; // r9
  volatile uint16_t *v7; // r10
  volatile int *v8; // r11
  int16_t v9; // r8
  int v10; // r4
  int v11; // r3
  int v12; // r12
  int v13; // r0
  char v14; // r2
  char v15; // r3
  volatile int *v16; // r3
  int v17; // r3
  int v18; // r3
  int16_t v19; // r0
  int16_t v20; // r3
  int v21; // r2
  volatile int *v22; // r3
  int v23; // r3
  int v25; // [sp+0h] [bp-14h]
  int v26; // [sp+4h] [bp-10h]

  v3 = (void *)(uintptr_t)(off_117144);
  v4 = *a1;
  v5 = (uint16_t)*a3;
  v6 = (volatile int *)off_117158;
  v7 = (void *)(uintptr_t)(off_11715C);
  v8 = (volatile int *)off_117160;
  v9 = 0;
  *((volatile uint8_t *)off_117144 + 2) = 0;
  v26 = 0;
  while ( 1 )
  {
    v19 = *(volatile uint16_t *)(v4 + 8);
    v20 = *(volatile uint32_t *)(v4 + 12) + 1;
    v21 = (uint16_t)(v20 - v19);
    if ( a2 + v5 >= v21 )
    {
      v10 = (v10 & ~0xFFFFu) | ((uint16_t)(v19 - v20 + v5 + a2) & 0xFFFFu);
      a2 = (uint16_t)(v21 - v5);
      v10 = (uint16_t)v10;
      v5 = 0;
    }
    else
    {
      v10 = 0;
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117148 = 1;
    }
    v11 = (uint16_t)*v7;
    v12 = *v6;
    v25 = *v8;
    v13 = *v8 + 8 * v11;
    *(volatile uint32_t *)(v13 + 4) = *(volatile uint32_t *)(v4 + 8);
    *v6 = v12 + 1;
    *(volatile uint32_t *)(v25 + 8 * v11) = a2;
    v14 = v3[3] + 1;
    v9 += a2;
    *v7 = v11 + 1;
    v3[3] = v14;
    if ( v10 )
    {
      if ( v12 == -1 )
        goto LABEL_10;
      v22 = (volatile int *)off_117148;
      *v6 = v12;
      v23 = *v22;
      if ( v12 || !v23 )
        goto LABEL_10;
      goto LABEL_9;
    }
    v15 = *(volatile uint8_t *)(v13 + 3);
    *(volatile uint16_t *)v3 = v9;
    *(volatile uint8_t *)(v13 + 3) = v15 | 4;
    v3[2] = 1;
    *((volatile uint32_t *)v3 + 2) = v13;
    if ( v12 == -1 )
      break;
    v16 = (volatile int *)off_117148;
    *v6 = v12;
    v17 = *v16;
    if ( v12 || !v17 )
      break;
LABEL_9:
    __enable_irq();
    if ( !v10 )
      break;
LABEL_10:
    v18 = *(volatile uint32_t *)(v4 + 4);
    if ( **(volatile int16_t **)off_11714C < 0 && !v18 )
    {
      flash_ctrl_init(dword_117154, dword_117150, 615);
      v18 = 0;
    }
    v26 = v4;
    a2 = v10;
    v4 = v18;
  }
  *a1 = v4;
  *a3 = v5;
  return v26;
}



// tx_send_packet @ 0x117164
volatile uint32_t * tx_send_packet(volatile uint32_t *a1, int a2, volatile uint16_t *a3) {
  volatile int *v3; // r7
  int v4; // r10
  volatile uint32_t *v5; // r6
  volatile int16_t **v6; // r11
  volatile uint32_t *v7; // r8
  int v9; // r9
  int v10; // r5
  int v11; // r0
  int v12; // r3
  volatile uint32_t *v13; // r4
  int v14; // r2
  int v15; // r0
  int v16; // r1
  volatile uint32_t *v17; // r3
  int16_t v18; // r5
  int16_t v19; // r2
  int v20; // r1
  int v22; // [sp+8h] [bp-14h]
  int v23; // [sp+8h] [bp-14h]
  int16_t v24; // [sp+8h] [bp-14h]
  volatile uint32_t *v25; // [sp+Ch] [bp-10h]

  v3 = (volatile int *)off_117270;
  v4 = (uint16_t)*a3;
  v5 = (volatile uint32_t *)*a1;
  v6 = (volatile int16_t **)off_117280;
  v7 = 0;
  *((volatile uint8_t *)off_117270 + 32) = 1;
  v9 = 0;
  v25 = 0;
  while ( 1 )
  {
    v18 = *((volatile uint16_t *)v5 + 4);
    v19 = v5[3] + 1;
    v20 = (uint16_t)(v19 - v18);
    if ( a2 + v4 >= v20 )
      break;
    v23 = a2;
    v11 = irq_disable();
    v10 = 0;
    v12 = v23;
    v9 = 1;
    v13 = (volatile uint32_t *)v11;
    if ( !v11 )
      goto LABEL_15;
LABEL_5:
    v14 = v3[1];
    if ( !v14 )
      *v3 = v11;
    v15 = **v6;
    v3[3] += v12;
    v3[1] = v14 + 1;
    v16 = v5[2];
    if ( v15 < 0 && !v16 )
    {
      v24 = v12;
      flash_ctrl_init(dword_117278, dword_117274, 683);
      v16 = v5[2];
      v12 = (v12 & ~0xFFFFu) | ((uint16_t)(v24) & 0xFFFFu);
    }
    set_radio_channel(v13, v16, 0, v12, v9);
    if ( v7 )
      v7[1] = (int)(uintptr_t)(v13);
    v3[2] = (int)v13;
    if ( !v10 )
      goto LABEL_16;
    v17 = (volatile uint32_t *)v5[1];
    if ( **v6 < 0 && !v17 )
    {
      flash_ctrl_init(dword_11727C, dword_117274, 704);
      v17 = 0;
    }
    v25 = v5;
    v7 = v13;
    v5 = v17;
    a2 = v10;
  }
  v10 = (uint16_t)(v18 + a2 + v4 - v19);
  v22 = (uint16_t)(v20 - v4);
  if ( !v10 )
    v9 = 1;
  v11 = irq_disable();
  v4 = 0;
  v12 = v22;
  v13 = (volatile uint32_t *)v11;
  if ( v11 )
    goto LABEL_5;
LABEL_15:
  *((volatile uint8_t *)v3 + 32) = v11;
LABEL_16:
  *a1 = (int)(uintptr_t)(v5);
  *a3 = v4;
  return v25;
}



// rx_parse_packet @ 0x117284
volatile uint32_t * rx_parse_packet(volatile uint32_t *a1, unsigned int a2, int a3, volatile uint32_t *a4, int a5) {
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

  v5 = (volatile uint8_t **)off_117394;
  v6 = (volatile uint32_t *)*a1;
  v7 = *(volatile uint16_t *)a4;
  v8 = **(volatile uint8_t **)off_117394;
  v9 = (volatile int16_t **)off_117398;
  v22 = (void *)(a4);
  if ( a2 >= 0x640 )
    a2 = 1600;
  if ( v8 == 3 )
    a4 = (void *)(uintptr_t)(off_117388);
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
      flash_ctrl_init(dword_117390, dword_11738C, 928);
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
    v20 = (void *)(uintptr_t)(off_117388);
    v10[8] = 0;
    v20[1] = (int)(uintptr_t)(v10);
  }
  *a1 = (int)(uintptr_t)(v6);
  *v22 = v7;
  return result;
}



// ll_timer_offset_get @ 0x11739c
int ll_timer_offset_get(int a1, int a2) {
  int result; // r0
  unsigned int v3; // r3
  volatile uint32_t *v4; // r1
  int v5; // r2
  int v6; // cf
  unsigned int v7; // r2

  if ( !a2 )
  {
    v3 = a1 + 156;
    goto LABEL_9;
  }
  if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v3 = (*(volatile uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v4 = (void *)(uintptr_t)(off_11740C);
    v5 = *((volatile uint32_t *)off_11740C + 2);
    if ( *((volatile uint32_t *)off_11740C + 1) == v3 )
      v3 = *(volatile uint32_t *)off_11740C;
    *(volatile uint32_t *)(a1 + 148) = v3;
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
    if ( **(volatile int16_t **)off_117400 < 0 && !a2 )
      return ke_int_lock_1((int)aPdNull, (int)aRxlGoToLastRbd, 1119);
    if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}


// ipc_regs_init @ 0x117410
int ipc_regs_init() {
  int v0; // r3
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r12
  volatile int *v3; // r5
  volatile uint32_t *v4; // r4
  volatile uint32_t *v5; // r8
  volatile uint32_t *v6; // lr
  volatile uint32_t *v7; // r7
  int v8; // r3
  volatile uint32_t *v9; // r6
  volatile uint32_t *v10; // r5
  int v11; // r3
  uint64_t v12; // r0

  v0 = dword_117488;
  v1 = (void *)(uintptr_t)(off_11748C);
  v12 = (v12 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_117490) << 32);
  v2 = (void *)(uintptr_t)(off_1174AC);
  v3 = (volatile int *)off_117494;
  v4 = (void *)(uintptr_t)(off_117498);
  *(volatile uint32_t *)off_11748C = dword_117488;
  v12 = (v12 & ~0xFFFFFFFFull) | ((uint32_t)(v0 + 24832) & 0xFFFFFFFFu);
  *v3 = v0;
  *v4 = v0 + 24884;
  v5 = (void *)(uintptr_t)(off_1174B0);
  v6 = (void *)(uintptr_t)(off_1174B4);
  v1[2] = v0;
  v7 = (void *)(uintptr_t)(off_11749C);
  v8 = *v1;
  v9 = (void *)(uintptr_t)(off_1174A0);
  *v5 = *v1;
  *v6 = v8;
  *v2 = HIDWORD(v12);
  v10 = (void *)(uintptr_t)(off_1174A4);
  *v7 = HIDWORD(v12) + 664;
  *v9 = HIDWORD(v12);
  v4[6] = HIDWORD(v12);
  v4 -= 0x2000;
  *v10 = dword_1174A8;
  v11 = *(volatile uint32_t *)((volatile char *)v4 + 0xFFFFFF40);
  v1[3] = HIDWORD(v12);
  v1[1] = v12 + 56;
  v12 = (v12 & ~0xFFFFFFFFull) | ((uint32_t)(HIDWORD(v12) + 668) & 0xFFFFFFFFu);
  *((volatile uint64_t *)v1 + 2) = v12;
  *(v4 - 48) = v11 & 0x80000 | 0x78025;
  return v12;
}



// gpio_set_bit10 @ 0x1174b8
unsigned int gpio_set_bit10(int a1) {
  volatile unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_1174E8;
  *(volatile uint32_t *)off_1174E4 = (a1 << 10) & 0x400 | *(volatile uint32_t *)off_1174E4 & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}



// timer_is_past @ 0x1174ec
int timer_is_past(int result) {
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(volatile uint32_t *)(result + 148);
  if ( *(volatile uint8_t *)(result + 152) )
  {
    v3 = *(volatile uint32_t *)off_117534 & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_117534 & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(volatile uint32_t *)off_117534 = v1 | v3;
  }
  else
  {
    v2 = *(volatile uint32_t *)off_117530 & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_117530 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(volatile uint32_t *)off_117530 = v1 | v2;
  }
  return result;
}



// scan_ctrl_update @ 0x117538
int scan_ctrl_update(int a1) {
  volatile uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = (void *)(uintptr_t)(off_117588);
  if ( *((volatile uint8_t *)off_117588 + 33) )
    *(volatile uint32_t *)(*((volatile uint32_t *)off_117588 + 6) + 4) = a1;
  else
    *((volatile uint32_t *)off_117588 + 4) = a1;
  result = *((volatile uint8_t *)off_11758C + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((volatile uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = irq_disable_set_flag_3(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((volatile uint8_t *)v1 + 33) = 0;
  }
  return result;
}



// tx_acl_queue_process @ 0x117590
int tx_acl_queue_process(int a1) {
  int v1; // r2
  int v2; // r6
  volatile uint32_t *v3; // r9
  volatile uint8_t **v4; // r5
  volatile uint8_t *v5; // r3
  int v7; // r3
  unsigned int v8; // r1
  int v9; // r3
  volatile int *v10; // r6
  volatile uint32_t *v11; // r10
  uint8_t v12; // r8
  volatile uint32_t *v13; // r0
  volatile uint8_t *v14; // r2
  volatile uint8_t *v15; // r5
  int v16; // r2
  volatile int *v17; // r6
  int v18; // r0
  int v19; // r3
  int v20; // r2
  volatile uint16_t *v22; // r7
  volatile int *v23; // r8
  int v24; // cc
  int v25; // r0
  int v26; // r10
  volatile uint32_t *v27; // r0
  int v28; // r12
  int v29; // r3
  volatile int *v30; // r0
  volatile uint8_t *v31; // r12
  int v32; // r1
  char v33; // r10
  int v34; // r1
  int v35; // r3
  volatile uint32_t *v36; // r1
  int v37; // r1
  int v38; // r0
  volatile uint32_t *v39; // r0
  int v40; // r8
  int v41; // r2
  int v42; // r12
  int v43; // r2
  volatile uint8_t *v44; // r0
  int v45; // r1
  volatile int *v46; // r4
  int v47; // r0
  int v48; // r3
  int v49; // r2
  struct __attribute__((packed)) { int v50; // [sp+Ch] [bp-Ch]
  char _pad1[2]; uint8_t a4[6]; // [sp+12h] [bp-6h] BYREF
  } _frame;
  v4 = (volatile uint8_t **)off_11786C;
  v5 = *(volatile uint8_t **)off_11786C;
  *(volatile uint32_t *)&_frame.a4[2] = *(volatile uint32_t *)(a1 + 28);
  *(volatile uint16_t *)_frame.a4 = 0;
  v7 = *v5;
  if ( v7 == 3 )
  {
    v2 = return_0();
    v7 = **v4;
    v1 = v2 + 56;
  }
  if ( v7 == 2 )
  {
    v22 = (void *)(uintptr_t)(off_117890);
    if ( !*((volatile uint32_t *)off_117890 + 2057) )
    {
      v45 = *(volatile uint32_t *)&_frame.a4[2];
      *(volatile uint8_t *)(a1 + 16) |= 1u;
      ll_timer_offset_get(a1, v45);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_117944 = 1;
      }
      v46 = (volatile int *)off_117948;
      ++*(volatile uint32_t *)off_117948;
      v47 = ((int (*)())process_event)();
      if ( *v46 )
      {
        v48 = *v46 - 1;
        v49 = *(volatile uint32_t *)off_117944;
        *v46 = v48;
        if ( !v48 )
        {
          if ( v49 )
            __enable_irq();
        }
      }
      return log_printf("err, no buf %d\n", v47);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117880 = 1;
    }
    v23 = (volatile int *)off_117884;
    _frame.v50 = v1;
    v24 = (uint16_t)v22[4122] > 0x186u;
    ++*(volatile uint32_t *)off_117884;
    v25 = dword_117894;
    v26 = dword_1178B0;
    if ( v24 )
      v22[4122] = 0;
    v27 = list_pop_front(v25);
    v1 = _frame.v50;
    v28 = *(volatile uint32_t *)off_117898;
    v3 = v27;
    v29 = (uint16_t)v22[4122];
    *((volatile uint16_t *)v27 + 6) = v29;
    v30 = (volatile int *)(v28 + 8 * v29);
    v30[1] = a1 + 48;
    *v30 = v26;
    v31 = (void *)(uintptr_t)(off_11787C);
    v3[1] = (int)(uintptr_t)(v30);
    v32 = *v23;
    v33 = *((volatile uint8_t *)v22 + 3074) + 1;
    v30 = (void *)(uintptr_t)(((uintptr_t)(v30) & ~0xFFu) | ((uint8_t)(v31[3] + 1) & 0xFFu));
    v22[4122] = v29 + 1;
    *((volatile uint8_t *)v22 + 3074) = v33;
    v31[3] = (uint8_t)v30;
    if ( v32 )
    {
      v34 = v32 - 1;
      v35 = *(volatile uint32_t *)off_117880;
      *v23 = v34;
      if ( !v34 )
      {
        if ( v35 )
          __enable_irq();
      }
    }
    v8 = *(volatile uint16_t *)(a1 + 48);
    if ( **(volatile int16_t **)off_117870 >= 0 )
    {
LABEL_37:
      v7 = **v4;
      if ( v7 == 2 )
      {
        wlan_rf_init((volatile int *)&_frame.a4[2], v8, (void *)(_frame.a4));
        goto LABEL_7;
      }
LABEL_5:
      if ( v7 == 1 )
        tx_send_packet((void *)((volatile int *)&_frame.a4[2]), v8, (void *)(_frame.a4));
      else
        rx_parse_packet((void *)(&_frame.a4[2]), v8, v1, (void *)(_frame.a4), 0);
LABEL_7:
      mac_time_get((volatile uint64_t *)(a1 + 88), 0);
      v9 = **v4;
      if ( v9 == 3 )
      {
        v36 = (void *)(uintptr_t)(off_11789C);
        *(volatile uint32_t *)(a1 + 96) = dword_1178A0;
        v37 = v36[1];
        *(volatile uint32_t *)(a1 + 104) = v2;
        *(volatile uint32_t *)(a1 + 100) = a1 + 48;
        v38 = dword_1178A4;
        *(volatile uint32_t *)(v37 + 32) = a1 + 100;
        *(volatile uint32_t *)(a1 + 108) = v38;
        *(volatile uint32_t *)(a1 + 132) = 0;
        *(volatile uint32_t *)(a1 + 112) = 54;
        *(volatile uint32_t *)(a1 + 116) = 54;
        *(volatile uint32_t *)(a1 + 120) = 262148;
LABEL_24:
        ll_timer_offset_get(a1, *(volatile int *)&_frame.a4[2]);
        return check_kernel_state(dword_11788C, (volatile uint32_t *)a1);
      }
      if ( v9 == 1 )
      {
        v10 = (volatile int *)off_117874;
        if ( !*((volatile uint8_t *)off_117874 + 32) )
          goto LABEL_10;
        v39 = (void *)(uintptr_t)(irq_disable());
        v40 = (int)v39;
        if ( v39 )
        {
          if ( *((volatile uint8_t *)v10 + 32) )
          {
            v41 = *v10;
            v42 = v10[1] + 1;
            v39[2] = (v42 << 24) & 0x7F000000 | v39[2] & 0x80FFFFFF;
            v10[1] = v42;
            set_radio_channel(v39, a1 + 48, v41, 0x36u, 0);
            v43 = *((volatile uint8_t *)off_1178A8 + 192);
            v10[3] += 54;
            if ( v43 )
              scan_ctrl_update(v40);
            else
              irq_disable_set_flag_3(v40, v10[1], v10[2]);
            v44 = *v4;
            *(volatile uint8_t *)off_1178AC |= 1u;
            v10[1] = 0;
            v10[3] = 0;
            *v10 = 0;
            v10[2] = 0;
            *((volatile uint8_t *)v10 + 32) = 0;
            v9 = *v44;
            goto LABEL_15;
          }
        }
        else
        {
          *(volatile uint8_t *)(a1 + 16) |= 1u;
          dispatch_event_handler_1(aNoTxDscrHdr_0);
          *((volatile uint8_t *)v10 + 32) = 0;
        }
LABEL_10:
        check_interrupt_flag(1024, aNoTxDscrHdr);
        v11 = (volatile uint32_t *)*v10;
        *(volatile uint8_t *)(a1 + 16) |= 1u;
        if ( v11 && v10[1] )
        {
          v12 = 0;
          do
          {
            v13 = v11;
            v11 = (volatile uint32_t *)v11[1];
            irq_disable_arg(v13);
            ++v12;
          }
          while ( v12 < (unsigned int)v10[1] );
        }
        v14 = *v4;
        v10[1] = 0;
        v10[3] = 0;
        *v10 = 0;
        v10[2] = 0;
        v9 = *v14;
      }
LABEL_15:
      if ( v9 == 2 )
      {
        v15 = (void *)(uintptr_t)(off_11787C);
        if ( *((volatile uint8_t *)off_11787C + 2) )
        {
          v16 = v3[1];
          v3[2] = *(volatile uint16_t *)off_11787C + 58;
          *(volatile uint8_t *)(v16 + 3) &= 0x3Fu;
          *((volatile uint8_t *)v3 + 14) = v15[3];
          *v3 = 0;
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)off_117880 = 1;
          }
          v17 = (volatile int *)off_117884;
          v18 = dword_117888;
          ++*(volatile uint32_t *)off_117884;
          check_kernel_state(v18, v3);
          ((int (*)())process_event)();
          if ( *v17 )
          {
            v19 = *v17 - 1;
            v20 = *(volatile uint32_t *)off_117880;
            *v17 = v19;
            if ( !v19 )
            {
              if ( v20 )
                __enable_irq();
            }
          }
          *(volatile uint32_t *)v15 = 0;
          *((volatile uint32_t *)v15 + 1) = 0;
        }
      }
      goto LABEL_24;
    }
  }
  else
  {
    v8 = *(volatile uint16_t *)(a1 + 48);
    if ( **(volatile int16_t **)off_117870 >= 0 )
      goto LABEL_5;
  }
  if ( !v8 )
    return ke_int_lock_1((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v8 <= 0x3000 )
    goto LABEL_37;
  return ke_int_lock_1((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}


// ll_event_timer_handler @ 0x117954
int ll_event_timer_handler(int a1) {
  int v2; // r0

  ll_timer_offset_get(a1, *(volatile uint32_t *)(a1 + 28));
  v2 = off_117988;
  if ( !*(volatile uint32_t *)off_117988 )
    return timer_is_past(a1);
  *(volatile uint8_t *)(a1 + 16) |= 1u;
  *(volatile uint32_t *)(a1 + 4) = 0;
  return check_kernel_state(v2, (volatile uint32_t *)a1);
}


// timer_event_check @ 0x11798c
unsigned int timer_event_check() {
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((volatile uint32_t *)off_1179C0 + 2);
  if ( v0 == *(volatile uint32_t *)off_1179C4 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((volatile uint32_t *)off_1179C0 + 1) - (v0 & 0x7FFFFFFFu) <= 0x9B )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(volatile uint32_t *)off_1179C0 )
      v2 += 0x80000000;
    v3 = v2 | *(volatile uint32_t *)off_1179C0;
    *((volatile uint32_t *)off_1179C0 + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}



// rf_cal_offset_apply @ 0x1179c8
int rf_cal_offset_apply(int result) {
  int v1; // r4
  int16_t v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(volatile int16_t **)off_117A44 < 0 && *(volatile uint32_t *)(result + 20) != dword_117A4C )
    result = flash_ctrl_init(dword_117A54, dword_117A50, 1811);
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
  v3 = dword_117A48;
  *(volatile uint8_t *)(v1 + 16) = 2;
  *(volatile uint8_t *)(v1 + 152) = 0;
  *(volatile uint32_t *)(v1 + 12) = v1;
  *(volatile uint32_t *)(v1 + 4) = v3;
  return result;
}



// mmio_bit16_toggle @ 0x117a58
int mmio_bit16_toggle() {
  volatile uint32_t *v0; // r2

  v0 = (void *)(uintptr_t)(off_117A78);
  *(volatile uint32_t *)off_117A74 = 0x10000;
  *v0 &= ~0x10000u;
  return set_busy_flag_alt(0x4000);
}



// stack_canary_setup @ 0x117a7c
volatile uint64_t *stack_canary_setup() {
  volatile uint64_t *result; // r0
  struct __attribute__((packed)) { uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]
  } _frame;
  _frame.v2 = *(volatile uint32_t *)off_117AC0;
  _frame.v3 = *(volatile uint32_t *)dword_117AC4;
  _frame.v4 = *(volatile uint32_t *)(dword_117AC4 + 8 + 0xFFFFFFFC);
  _frame.v5 = *(volatile uint32_t *)(dword_117AC4 + 8);
  result = mac_time_get(&_frame.v1, 0);
  if ( (_frame.v2 & 0xF) == 2 )
    return (volatile uint64_t *)patch_check_enabled_ctx((int)(uintptr_t)(&_frame.v1));
  return result;
}



// mutex_acquire_if_ready @ 0x117ac8
volatile int * mutex_acquire_if_ready(int a1) {
  int v2; // r5
  int v3; // r0
  volatile int *result; // r0

  v2 = a1 + 48;
  while ( *(volatile uint32_t *)(a1 + 48) )
  {
    v3 = (int)(uintptr_t)(list_pop_front(v2));
    wlan_tx_kick(v3, 1);
  }
  result = memset((volatile int *)a1, 0, 0x98u);
  *(volatile uint8_t *)(a1 + 32) = -1;
  return result;
}



// init_table_185d40 @ 0x117af8
volatile uint32_t *init_table_185d40() {
  int v0; // r5
  int v1; // r7
  int i; // r6
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r0
  volatile uint32_t *result; // r0

  v0 = dword_117B48;
  v1 = dword_117B44;
  list_init_1((volatile uint32_t *)dword_117B44);
  for ( i = 0; i != 76; i += 19 )
  {
    mutex_acquire_if_ready(v0 - 88);
    check_kernel_state(v1, (volatile uint32_t *)(v0 - 88));
    v3 = (volatile uint32_t *)(v0 - 32);
    do
    {
      list_init_1(v3);
      v4 = v3 + 8;
      v3 += 2;
      result = list_init_1(v4);
    }
    while ( v3 != (volatile uint32_t *)v0 );
    v0 = (int)(v3 + 38);
  }
  return result;
}


// btcoex_update_bt_info @ 0x117b4c
int btcoex_update_bt_info(volatile int *a1, volatile uint8_t *a2) {
  int v3; // r6
  volatile uint32_t *v5; // r0
  volatile uint32_t *v6; // r4
  int v7; // r1
  volatile char *v8; // r2
  int v9; // r0
  int v10; // r3
  unsigned int v11; // r0
  char v12; // r3
  int v13; // r3
  int v14; // r6
  int v15; // r3
  volatile uint32_t *v16; // r3
  int v17; // r0
  int v18; // r2
  int v19; // r1
  volatile uint32_t *v20; // r1
  volatile uint32_t *v22; // r0
  char v23; // r1
  uint16_t v24; // lr
  int v25; // r3
  int16_t v26; // r12
  int v27; // r12

  v3 = *((volatile uint8_t *)a1 + 25);
  v5 = list_pop_front(dword_117C94);
  if ( !v5 )
    return 1;
  v6 = v5;
  if ( *((volatile uint8_t *)a1 + 29) )
  {
    v22 = list_pop_front(dword_117C94);
    if ( !v22 )
    {
      check_kernel_state(dword_117C94, v6);
      return 1;
    }
    v6[11] = (int)(uintptr_t)(v22);
    v22[11] = (int)(uintptr_t)(v6);
    v23 = *((volatile uint8_t *)a1 + 30);
    v8 = (volatile char *)a1 + 18;
    v24 = *((volatile uint8_t *)a1 + 29);
    v22[9] = *(volatile int *)((volatile char *)a1 + 18);
    *((volatile uint16_t *)v22 + 20) = *((volatile uint16_t *)a1 + 11);
    v25 = (1 << v23) - 1;
    v7 = dword_117C98;
    v25 = (v25 & ~0xFFFFu) | ((uint16_t)((uint16_t)v25 << 8) & 0xFFFFu);
    v26 = v22[10] & ~(uint16_t)v25;
    *((volatile uint16_t *)v22 + 20) = v26;
    v25 = (v25 & ~0xFFFFu) | ((uint16_t)(v26 | v25 & (*((volatile uint16_t *)a1 + 11) - (v24 << 8))) & 0xFFFFu);
    v27 = dword_117C9C * (((int)v22 - v7) >> 3);
    *((volatile uint16_t *)v22 + 20) = v25;
    *((volatile uint8_t *)v22 + 33) = v27;
    *((volatile uint16_t *)v22 + 15) = -1;
  }
  else
  {
    v7 = dword_117C98;
    v8 = (volatile char *)a1 + 18;
  }
  v9 = *(volatile uint32_t *)v8;
  v10 = *a1;
  *((volatile uint16_t *)v6 + 20) = *((volatile uint16_t *)v8 + 2);
  v6[1] = v10;
  v6[9] = v9;
  v11 = *((volatile uint8_t *)a1 + 24);
  v12 = dword_117C9C;
  if ( v11 < 0x10 )
    v11 = (v11 & ~0xFFu) | ((uint8_t)(16) & 0xFFu);
  *((volatile uint8_t *)v6 + 28) = v11;
  *((volatile uint16_t *)v6 + 10) = *((volatile uint16_t *)a1 + 8);
  v6[4] = a1[2];
  v6[3] = a1[1];
  v6[6] = a1[3];
  v13 = (uint8_t)(v12 * (((int)v6 - v7) >> 3));
  *((volatile uint8_t *)v6 + 32) = *((volatile uint8_t *)a1 + 25);
  *a2 = v13;
  *((volatile uint8_t *)v6 + 33) = v13;
  check_interrupt_flag(256, "%s: sta_idx=%d\n", aStaMgmtRegiste, v13);
  v14 = dword_117CA8 + 224 * v3;
  if ( *(volatile uint8_t *)(v14 + 94) )
    v15 = 102400;
  else
    v15 = *(volatile uint16_t *)(v14 + 100) << 10;
  v6[2] = v15;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117CAC = 1;
  }
  v16 = (void *)(uintptr_t)(off_117CB0);
  v17 = v6[11];
  v18 = *(volatile uint32_t *)off_117CB0;
  v19 = *(volatile uint32_t *)off_117CB0 + 1;
  *(volatile uint32_t *)off_117CB0 = v19;
  *((volatile uint8_t *)v6 + 35) = 1;
  if ( v17 )
    *(volatile uint8_t *)(v17 + 35) = 1;
  if ( v19 )
  {
    v20 = (void *)(uintptr_t)(off_117CAC);
    *v16 = v18;
    if ( !v18 )
    {
      if ( *v20 )
        __enable_irq();
    }
  }
  *((volatile uint8_t *)v6 + 124) = 0;
  return 0;
}


// rf_calibration_table_get @ 0x117cb4
/* luna: Unregisters the station context for a given station index by clearing its active/registered flag and notifying the associated kernel object under a cr */
int rf_calibration_table_get(int a1) {
  int sta_table_base; // r6
  int v3; // r5
  volatile uint32_t *sta_ctx; // r5
  volatile uint32_t *v5; // r2
  int v6; // r3
  int v7; // r1
  int assoc_obj_ptr; // r0
  int v9; // r7
  volatile int *v11; // r0
  int irq_disabled_saved; // r2
  volatile int *v13; // r3

  sta_table_base = dword_117D54;
  v3 = 19 * a1;
  check_interrupt_flag(256, "%s: sta_idx=%d\n", aStaMgmtUnregis, a1);
  sta_ctx = (volatile uint32_t *)(sta_table_base + 8 * v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117D60 = 1;
  }
  v5 = (void *)(uintptr_t)(off_117D64);
  v6 = sta_table_base + 152 * a1;
  v7 = *(volatile uint32_t *)off_117D64;
  assoc_obj_ptr = *(volatile uint32_t *)(v6 + 44);
  v9 = *(volatile uint32_t *)off_117D64 + 1;
  *(volatile uint32_t *)off_117D64 = v9;
  *(volatile uint8_t *)(v6 + 35) = 0;
  if ( assoc_obj_ptr )
  {
    *(volatile uint8_t *)(assoc_obj_ptr + 35) = 0;
    if ( !v9 )
    {
LABEL_5:
      mutex_acquire_if_ready(assoc_obj_ptr);
      check_kernel_state(dword_117D68, *(volatile uint32_t **)(sta_table_base + 152 * a1 + 44));
      goto LABEL_6;
    }
    v11 = (volatile int *)off_117D60;
    *v5 = v7;
    irq_disabled_saved = *v11;
    if ( v7 )
    {
      assoc_obj_ptr = *(volatile uint32_t *)(v6 + 44);
      goto LABEL_5;
    }
  }
  else
  {
    if ( !v9 )
      goto LABEL_6;
    v13 = (volatile int *)off_117D60;
    *v5 = v7;
    irq_disabled_saved = *v13;
    if ( v7 )
      goto LABEL_6;
  }
  if ( irq_disabled_saved )
    __enable_irq();
  assoc_obj_ptr = *(volatile uint32_t *)(sta_table_base + 152 * a1 + 44);
  if ( assoc_obj_ptr )
    goto LABEL_5;
LABEL_6:
  mutex_acquire_if_ready((int)sta_ctx);
  return check_kernel_state(dword_117D68, sta_ctx);
}


// rx_queue_flush @ 0x117d6c
int rx_queue_flush(int a1, int a2, int a3) {
  int v3; // r4
  int v6; // r8
  int v7; // r0
  int v8; // r1

  v3 = *(volatile uint32_t *)(a2 + 48);
  if ( v3 )
  {
    v3 = 0;
    v6 = a2 + 48;
    do
    {
      if ( !rf_is_idle() )
        break;
      v7 = (int)(uintptr_t)(list_pop_front(v6));
      v8 = *(volatile uint8_t *)(v7 + 14);
      *(volatile uint8_t *)(v7 + 53) = 0;
      ++v3;
      llm_scan_pdu_cfg(v7, v8);
      if ( a3 )
      {
        if ( v3 == a3 )
          break;
      }
    }
    while ( *(volatile uint32_t *)(a2 + 48) );
  }
  return v3;
}



// capability_dispatch @ 0x117db4
int capability_dispatch(int result) {
  if ( *(volatile uint32_t *)(result + 72) )
    return ((int (*)())bt_link_rx_check)();
  return result;
}



// btcoex_check_state @ 0x117dc0
void btcoex_check_state() {
  volatile uint8_t *v0; // r3
  unsigned int v1; // r2

  v0 = *((volatile uint8_t **)off_117DEC + 2);
  if ( !v0[94] && v0[96] && v0[103] )
  {
    v1 = (uint8_t)v0[104];
    if ( v1 <= 8 )
      *(volatile uint32_t *)off_117DF0 = ((1 << v1) - 1) << 8;
  }
}



// btcoex_reset_context @ 0x117df4
int btcoex_reset_context() {
  volatile int *v0; // r8
  int v1; // r4
  void *v2; // r7
  int v3; // r6
  volatile uint32_t *v4; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_117E50);
  memset((void *)(uintptr_t)(off_117E50), 0, 0x14u);
  list_init_1((void *)(v0));
  v1 = dword_117E54;
  v2 = (void *)(uintptr_t)(off_117E58);
  list_init_1((void *)(v0 + 2));
  v3 = v1 + 896;
  do
  {
    memset((volatile int *)v1, 0, 0xE0u);
    *(volatile uint8_t *)(v1 + 94) = 5;
    *(volatile uint8_t *)(v1 + 97) = 127;
    *(volatile uint32_t *)(v1 + 52) = (int)(uintptr_t)(v2);
    *(volatile uint32_t *)(v1 + 56) = v1;
    v4 = (volatile uint32_t *)v1;
    v1 += 224;
    result = check_kernel_state((int)v0, v4);
  }
  while ( v1 != v3 );
  *((volatile uint8_t *)v0 + 16) = -1;
  return result;
}


