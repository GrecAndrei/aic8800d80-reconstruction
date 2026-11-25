// rf_rx_check @ 0x11d320
/* luna: Handles an incoming RXL header descriptor, including its packet buffer and receive-status checks. */
BOOL rf_rx_check(int a1) {
  volatile int16_t **v1; // r10
  int first_pbd; // r8
  int v3; // r3
  volatile uint32_t *first_pbd_data; // r9
  int16_t frame_control; // r11
  unsigned int rx_status; // r6
  int v8; // r5
  int v10; // r2
  unsigned int hw_key_index; // r7
  int key_entry; // r3
  volatile unsigned int v13; // r1
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
    v1 = (volatile int16_t **)off_11D66C;
    first_pbd = *(volatile uint32_t *)(a1 + 28);
    v3 = **(volatile int16_t **)off_11D66C;
    if ( v3 < 0 && !first_pbd )
    {
      v8 = 0;
      bad_func_0x12f408((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v8;
    }
    first_pbd_data = *(volatile uint32_t **)(first_pbd + 8);
    frame_control = *(volatile uint16_t *)first_pbd_data;
    rx_status = *(volatile uint32_t *)(a1 + 84);
    if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11D630)[102])
      && (*((volatile uint32_t *)off_11D634 + 1) & 0x40) != 0
      && (*(volatile uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (frame_control & 0xFC) == 0xC4 )
        ++*(volatile uint32_t *)off_11D650;
    }
    else
    {
      if ( (dword_11D638 & ~rx_status) != 0 )
        return 0;
      *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v8 = (rx_status >> 15) & 0x1F0;
        if ( !v8 )
        {
          bad_func_0x12f408((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v8;
        }
      }
      v10 = dword_11D63C;
      hw_key_index = (uint8_t)((rx_status >> 15) - 16);
      key_entry = dword_11D63C + 696 * hw_key_index;
      v8 = *(volatile uint8_t *)(key_entry + 37);
      if ( !*(volatile uint8_t *)(key_entry + 37) )
      {
        *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFCFFFFFF;
        return v8;
      }
      if ( hw_key_index <= 0x23 )
      {
        v13 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(key_entry + 664) = v13;
      }
      v14 = v10 + 696 * hw_key_index;
      if ( *(volatile uint16_t *)(v14 + 32) == 0xFFFF )
      {
        if ( (frame_control & 0xFC) != 0x80 )
        {
          *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFCFFFFFF;
          return 0;
        }
        _frame.a3 = *(volatile uint32_t *)(v14 + 44);
        *(volatile uint32_t *)(a1 + 84) = rx_status & 0xFE007FFF | ((*(volatile uint8_t *)(_frame.a3 + 35) + 16) << 15);
      }
      else
      {
        _frame.a3 = v10 + 696 * hw_key_index;
      }
      _frame.v54 = *(volatile uint8_t *)(_frame.a3 + 34);
      v15 = (volatile uint8_t *)(dword_11D644 + 1320 * _frame.v54);
      _frame.v55 = 1320 * _frame.v54;
      radio_event_loop(first_pbd_data, hw_key_index, v15[107]);
      if ( !v15[108] )
        return 0;
      v16 = v15[106];
      v17 = dword_11D644;
      if ( v15[106] )
      {
        if ( (frame_control & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (frame_control & 0x300) != 0x200 )
      {
        v8 = frame_control & 4;
        if ( (frame_control & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v29 = memcmp((unsigned int)(first_pbd_data + 4), _frame.v55 + 100 + dword_11D644, 6u);
      v17 = dword_11D644;
      if ( v29 )
      {
        v8 = frame_control & 4;
        if ( (frame_control & 4) != 0 )
        {
LABEL_37:
          v16 = *(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106);
          if ( !*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 106) )
          {
LABEL_19:
            v18 = frame_control & 0xFC;
            v19 = _frame.v55 + v17;
            v20 = (volatile uint8_t *)(_frame.v55 + v17);
            if ( v18 == 128 )
            {
              _frame.a4 = nullptr;
              v43 = rx_process_packet(a1 + 20, (int)v20, _frame.a3, (void *)(&_frame.a4));
              wlc_ioctl_handler((unsigned int)_frame.a4, *(volatile uint16_t *)(a1 + 48), (int)v20);
              get_radio_state_1((int)v20);
              if ( v43 )
                llc_conn_idx_valid(v20, first_pbd, a1 + 20);
              return v43 == 0;
            }
            if ( v18 == 80 )
            {
              v30 = (void *)(uintptr_t)(off_11D658);
              if ( *((volatile uint8_t *)off_11D658 + 29) == 7 )
              {
                v8 = *((volatile uint8_t *)off_11D658 + 36);
                if ( !*((volatile uint8_t *)off_11D658 + 36) )
                {
                  v31 = (void *)(uintptr_t)(off_11D65C);
                  v32 = *(volatile uint32_t *)off_11D65C & 0xF;
                  if ( v32 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(volatile uint32_t *)off_11D660 = 1;
                    }
                    v33 = (volatile int *)off_11D670;
                    v34 = (void *)(uintptr_t)(off_11D65C);
                    ++*(volatile uint32_t *)off_11D670;
                    *v34 = 0;
                    v35 = (*(volatile uint32_t *)0x40501010u);
                    while ( *v34 << 28 )
                    {
                      v36 = (*(volatile uint32_t *)0x40501010u) - v35;
                      if ( v36 > 0x7530 )
                        check_status_bits(2, aIdleErr, 30000);
                    }
                    v37 = (void *)(uintptr_t)(off_11D664);
                    v38 = (*(volatile uint32_t *)0x40501010u);
                    if ( (*(volatile uint32_t *)off_11D668 & *(volatile uint32_t *)off_11D664 & 4) == 0 )
                    {
                      _frame.a3a = v8;
                      v39 = (void *)(uintptr_t)(off_11D668);
                      v40 = v38;
                      do
                      {
                        v41 = (*(volatile uint32_t *)0x40501010u) - v40;
                        v42 = *v37 & *v39;
                        if ( v41 > 0x7530 )
                        {
                          check_status_bits(2, aIdleIntErr);
                          v37 = (void *)(uintptr_t)(off_11D78C);
                        }
                      }
                      while ( (v42 & 4) == 0 );
                      v8 = _frame.a3a;
                    }
                    *(volatile uint32_t *)off_11D790 = 4;
                    if ( *v33 )
                    {
                      v44 = *v33 - 1;
                      v45 = *(volatile uint32_t *)off_11D794;
                      *v33 = v44;
                      if ( !v44 )
                      {
                        if ( v45 )
                          __enable_irq();
                      }
                    }
                    v46 = (void *)(uintptr_t)(off_11D798);
                    v47 = **v1;
                    v48 = *((volatile uint32_t *)off_11D798 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11D798 + 1) = v48;
                    if ( v47 < 0 && *(volatile uint32_t *)off_11D7A0 << 28 )
                    {
                      call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v48 = v46[1];
                    }
                    *(volatile uint32_t *)off_11D79C = v48 | *v46;
                    *(volatile uint32_t *)off_11D7A0 = 16 * v32;
                  }
                  else
                  {
                    v49 = (void *)(uintptr_t)(off_11D798);
                    v50 = **v1;
                    v51 = *((volatile uint32_t *)off_11D798 + 1) & 0xFFFFFDFF;
                    *((volatile uint32_t *)off_11D798 + 1) = v51;
                    if ( v50 < 0 && *v31 << 28 )
                    {
                      call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v51 = v49[1];
                    }
                    *(volatile uint32_t *)off_11D79C = v51 | *v49;
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
                wlc_bus_state((void *)(uintptr_t)((int)first_pbd_data), rx_status, v19);
                return 0;
              }
            }
            else
            {
              wlc_bus_state((void *)(uintptr_t)((int)first_pbd_data), rx_status, v19);
              if ( *(volatile uint8_t *)(dword_11D644 + 1320 * _frame.v54 + 1224) && v18 == 208 )
              {
                hci_cmd_preprocess((int)v20, *(volatile uint8_t **)(first_pbd + 8), *(volatile uint16_t *)(a1 + 48), *(volatile uint32_t *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v16 == 2 && *(volatile uint8_t *)(_frame.a3 + 35) <= 0x23u )
          {
            v21 = *(volatile char *)(a1 + 65);
            rf_get_field0();
            if ( !*(volatile uint8_t *)(_frame.a3 + 689) )
            {
              v8 = *(volatile char *)(_frame.a3 + 689);
              *(volatile uint8_t *)(_frame.a3 + 689) = v21;
              return v8;
            }
            v22 = int_to_double(*(volatile char *)(_frame.a3 + 689));
            v23 = ((uint64_t (*)())double_add_1)(v22, *(volatile uint64_t *)&dword_11D620);
            v24 = v23;
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(v21) & 0xFFFFFFFFu);
            v25 = __PAIR64__(HIDWORD(v23), v24);
            v26 = int_to_double(v23);
            v27 = ((uint64_t (*)())double_add_1)(v26, *(volatile uint64_t *)&dword_11D628);
            v28 = double_compare(v25, v27);
            *(volatile uint8_t *)(_frame.a3 + 689) = ((int (*)(uint64_t))double_to_float_1)(v28);
          }
          return 0;
        }
LABEL_36:
        tx_len_check(*(volatile uint8_t *)(v17 + 1320 * _frame.v54 + 107), hw_key_index, 1);
        v17 = dword_11D644;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}


// rf_counter_inc @ 0x11d7b0
int rf_counter_inc() {
  volatile uint8_t *v0; // r4
  unsigned int v1; // r2
  unsigned int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11D7D0);
  v1 = *((volatile uint8_t *)off_11D7D0 + 11);
  v2 = (uint8_t)(*((volatile uint8_t *)off_11D7D0 + 10) + 1);
  *((volatile uint8_t *)off_11D7D0 + 10) = v2;
  if ( v1 < v2 )
  {
    result = j_nullsub_6();
    v0[10] = 0;
  }
  return result;
}



// rf_counter_get @ 0x11d7d4
int rf_counter_get() {
  volatile uint8_t *v0; // r4
  volatile unsigned int *v1; // r2
  int v2; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11D7F4);
  if ( *((volatile uint8_t *)off_11D7F4 + 10) )
    result = j_nullsub_6();
  v1 = (volatile unsigned int *)off_11D7F8;
  v2 = *(volatile uint32_t *)off_11D7F8;
  v0[10] = v0[11];
  *v1 = v2 & 0xFFFFFEFF;
  return result;
}



// rf_poll @ 0x11d7fc
int rf_poll() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = (void *)(uintptr_t)(off_11D820);
  radio_read_fifo();
  v1 = (int)(uintptr_t)(zero_8_bytes((void *)(v0)));
  v2 = get_phy_type(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return (int)(uintptr_t)(bt_init_mod());
}



// nullsub_4 @ 0x11d824
int nullsub_4(void) {
  return 0;
}


// set_event_200000 @ 0x11d828
int set_event_200000() {
  return unknown_func_12d104(0x200000);
}



// mac_wait_rx @ 0x11d830
int mac_wait_rx() {
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

  v0 = (void *)(uintptr_t)(off_11D8D0);
  v1 = *(volatile uint32_t *)off_11D8D0;
  result = unknown_func_12d14c(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11D8E8;
    v4 = (volatile int *)off_11D8D4;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
        ++v0[4];
      mem_word_load((int)(uintptr_t)(v0));
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
        result = ((int (*)())radio_get_status)();
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
    v8 = (void *)(uintptr_t)(off_11D8E0);
    v9 = (void *)(uintptr_t)(off_11D8E4);
    *(volatile uint32_t *)off_11D8DC = *((volatile uint32_t *)off_11D8D8 + 4) + 200;
    *v8 = 256;
    *v9 |= 0x100u;
    return 256;
  }
  return result;
}



// mac_wait_tx @ 0x11d8ec
int mac_wait_tx() {
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

  v0 = (volatile int *)off_11D990;
  v1 = *(volatile uint32_t *)off_11D990;
  result = unknown_func_12d14c(0x200000);
  if ( v1 )
  {
    v3 = (volatile int *)off_11D99C;
    v4 = (volatile int *)off_11D9A0;
    v5 = 0;
    do
    {
      if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 )
      {
        if ( v5 )
          break;
        v5 = 1;
      }
      mem_word_load((int)v0);
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
        result = radio_get_status(result);
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
  v9 = (void *)(uintptr_t)(off_11D994);
  if ( *((volatile uint8_t *)off_11D994 + 69) )
  {
    unknown_func_12d104(0x80000);
    result = check_status_bits(1024, aHostBufferReco);
    v9[69] = 0;
  }
  return result;
}


// mac_wait_scan @ 0x11d9a4
int mac_wait_scan() {
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

  v0 = (volatile int *)off_11DA58;
  v1 = *(volatile uint32_t *)off_11DA58;
  result = unknown_func_12d14c(0x200000);
  if ( v1 )
  {
    v3 = (void *)(uintptr_t)(off_11DA5C);
    if ( *(volatile uint16_t *)off_11DA5C )
    {
      v4 = (volatile int *)off_11DA68;
      v5 = (volatile int *)off_11DA6C;
      do
      {
        if ( (*(volatile uint8_t *)(v1 + 16) & 1) == 0 && !*v3 )
          break;
        mem_word_load((int)v0);
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
          result = radio_get_status(result);
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
      v10 = (void *)(uintptr_t)(off_11DA60);
      if ( *((volatile uint8_t *)off_11DA60 + 69) )
      {
        unknown_func_12d104(0x80000);
        result = check_status_bits(1024, aHostBufferReco);
        v10[69] = 0;
      }
    }
  }
  return result;
}


// radio_init @ 0x11da70
int radio_init(int a1) {
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

  v1 = (void *)(uintptr_t)(off_11DBD4);
  v2 = (volatile int *)off_11DBF4;
  v3 = dword_11DC00;
  v4 = (void *)(uintptr_t)(off_11DC04);
  v5 = (void *)(uintptr_t)(off_11DC08);
  for ( i = 0; ; ++i )
  {
    v11 = rf_status_poll();
    *v1 = 0x10000;
    result = unknown_func_12d14c(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((volatile uint8_t *)v2 + 192) )
      {
        if ( *(volatile uint32_t *)off_11DBD8 > 0x80000u || i > 31 )
          return unknown_func_12d104(0x80000);
      }
      else if ( i > 3 )
      {
        return unknown_func_12d104(0x80000);
      }
    }
    if ( !check_rom_state() || !rf_chan_enabled() )
    {
      *((volatile uint8_t *)off_11DBEC + 69) = 1;
      v14 = rf_chan_enabled();
      return check_status_bits(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(volatile uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      event_dispatch(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(volatile uint32_t *)off_11DBDC,
        *((volatile uint32_t *)off_11DBDC + 1),
        *((volatile uint32_t *)off_11DBDC + 2),
        *v4,
        *v5);
    ke_task_state_get(v11);
    v9 = rf_rx_check(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( tx_check_allow(v11) )
    {
      goto LABEL_10;
    }
    llm_evt_queue_pop(v11);
LABEL_10:
    v10 = **(volatile uint8_t **)off_11DBE4;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(volatile uint32_t *)off_11DBE8 || *(volatile uint32_t *)(*(volatile uint32_t *)off_11DBE8 + 12) != v11 || (*(volatile uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          mac_wait_scan();
          continue;
        }
        v16 = *(volatile uint32_t *)off_11DBE8;
        mem_word_load(off_11DBE8);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(volatile uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(volatile uint32_t *)(v16 + 8));
        radio_get_status(v11);
        break;
      case 3:
        mac_wait_tx();
        break;
    }
  }
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_11DBF4)[48]) )
  {
    v15 = (void *)(uintptr_t)(off_11DBF8);
    if ( *((volatile uint8_t *)off_11DBF8 + 33) )
    {
      result = unknown_1(*((volatile uint32_t *)off_11DBF8 + 4), *((volatile uint32_t *)off_11DBF8 + 5), *((volatile uint32_t *)off_11DBF8 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((volatile uint8_t *)v15 + 33) = 0;
    }
  }
  *(volatile uint32_t *)off_11DBFC |= 0x10000u;
  return result;
}


// mac_rx_handler @ 0x11dc0c
int mac_rx_handler(volatile int *a1, int a2, volatile uint16_t *a3) {
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

  v3 = (void *)(uintptr_t)(off_11DD24);
  v4 = *a1;
  v5 = (uint16_t)*a3;
  v6 = (volatile int *)off_11DD38;
  v7 = (void *)(uintptr_t)(off_11DD3C);
  v8 = (volatile int *)off_11DD40;
  v9 = 0;
  *((volatile uint8_t *)off_11DD24 + 2) = 0;
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
      *(volatile uint32_t *)off_11DD28 = 1;
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
      v22 = (volatile int *)off_11DD28;
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
    v16 = (volatile int *)off_11DD28;
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
    if ( **(volatile int16_t **)off_11DD2C < 0 && !v18 )
    {
      mmio_clear_register(dword_11DD34, dword_11DD30, 615);
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



// mac_tx_handler @ 0x11dd44
volatile uint32_t * mac_tx_handler(volatile uint32_t *a1, int a2, volatile uint16_t *a3) {
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

  v3 = (volatile int *)off_11DE50;
  v4 = (uint16_t)*a3;
  v5 = (volatile uint32_t *)*a1;
  v6 = (volatile int16_t **)off_11DE60;
  v7 = 0;
  *((volatile uint8_t *)off_11DE50 + 32) = 1;
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
    v11 = (int)(uintptr_t)(is_scan_enabled());
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
      mmio_clear_register(dword_11DE58, dword_11DE54, 683);
      v16 = v5[2];
      v12 = (v12 & ~0xFFFFu) | ((uint16_t)(v24) & 0xFFFFu);
    }
    pack_control_word(v13, v16, 0, v12, v9);
    if ( v7 )
      v7[1] = (int)(uintptr_t)(v13);
    v3[2] = (int)v13;
    if ( !v10 )
      goto LABEL_16;
    v17 = (volatile uint32_t *)v5[1];
    if ( **v6 < 0 && !v17 )
    {
      mmio_clear_register(dword_11DE5C, dword_11DE54, 704);
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
  v11 = (int)(uintptr_t)(is_scan_enabled());
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



// mac_mlme_request @ 0x11de64
volatile uint32_t * mac_mlme_request(volatile uint32_t *a1, unsigned int a2, int a3, volatile uint32_t *a4, int a5) {
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

  v5 = (volatile uint8_t **)off_11DF74;
  v6 = (volatile uint32_t *)*a1;
  v7 = *(volatile uint16_t *)a4;
  v8 = **(volatile uint8_t **)off_11DF74;
  v9 = (volatile int16_t **)off_11DF78;
  v22 = (void *)(a4);
  if ( a2 >= 0x640 )
    a2 = 1600;
  if ( v8 == 3 )
    a4 = (void *)(uintptr_t)(off_11DF68);
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
      mmio_clear_register(dword_11DF70, dword_11DF6C, 928);
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
    v20 = (void *)(uintptr_t)(off_11DF68);
    v10[8] = 0;
    v20[1] = (int)(uintptr_t)(v10);
  }
  *a1 = (int)(uintptr_t)(v6);
  *v22 = v7;
  return result;
}



// get_connection_state @ 0x11df7c
int get_connection_state(int a1, int a2) {
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
    v4 = (void *)(uintptr_t)(off_11DFEC);
    v5 = *((volatile uint32_t *)off_11DFEC + 2);
    if ( *((volatile uint32_t *)off_11DFEC + 1) == v3 )
      v3 = *(volatile uint32_t *)off_11DFEC;
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
    if ( **(volatile int16_t **)off_11DFE0 < 0 && !a2 )
      return bad_func_0x12f408((int)aPdNull, (int)aRxlGoToLastRbd, 1119);
    if ( (*(volatile uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}


// radio_read_fifo @ 0x11dff0
int radio_read_fifo() {
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

  v0 = (volatile int *)off_11E058;
  v1 = *(volatile uint32_t *)off_11E054;
  v2 = (void *)(uintptr_t)(off_11E05C);
  v3 = (void *)(uintptr_t)(off_11E078);
  v4 = *(volatile uint64_t *)*(volatile uint32_t *)off_11E054;
  v5 = (void *)(uintptr_t)(off_11E060);
  *(volatile uint32_t *)off_11E058 = v4;
  *v5 = v4;
  *v2 = HIDWORD(v4) + v4 - 4;
  v6 = (void *)(uintptr_t)(off_11E068);
  v7 = *v0;
  *(volatile uint32_t *)off_11E064 = *v0;
  *v6 = v7;
  v8 = *(volatile uint64_t *)(v1 + 8);
  v9 = (void *)(uintptr_t)(off_11E07C);
  v10 = (void *)(uintptr_t)(off_11E06C);
  v0[1] = HIDWORD(v4) + v4;
  v6[1] = v8;
  v12 = (volatile int *)off_11E070;
  v0[2] = v4;
  v13 = dword_11E074;
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



// radio_set_peripheral_field @ 0x11e080
unsigned int radio_set_peripheral_field(int a1) {
  volatile unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (volatile unsigned int *)off_11E0B0;
  *(volatile uint32_t *)off_11E0AC = (a1 << 10) & 0x400 | *(volatile uint32_t *)off_11E0AC & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}



// radio_get_status @ 0x11e0b4
int radio_get_status(int result) {
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(volatile uint32_t *)(result + 152);
  if ( *(volatile uint8_t *)(result + 156) )
  {
    v3 = *(volatile uint32_t *)off_11E0FC & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11E0FC & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(volatile uint32_t *)off_11E0FC = v1 | v3;
  }
  else
  {
    v2 = *(volatile uint32_t *)off_11E0F8 & 0x80000000;
    if ( v1 < (*(volatile uint32_t *)off_11E0F8 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(volatile uint32_t *)off_11E0F8 = v1 | v2;
  }
  return result;
}



// rf_tx_frame @ 0x11e100
int rf_tx_frame(int a1) {
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
    if ( **(volatile int16_t **)off_11E1BC < 0 && !v1 )
    {
      v10 = aPdNull;
      v11 = 393;
      return bad_func_0x12f408((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v2 = *(volatile uint32_t *)(a1 + 84);
    v3 = **(volatile uint16_t **)(v1 + 8) & 0xFC;
    *(volatile uint32_t *)(a1 + 84) = v2 & 0xFEFFFFFF;
    if ( v3 == 36 )
    {
      if ( (v2 & 0x2000) != 0 )
      {
        a1b = a1;
        update_phy_status(a1);
        a1 = a1b;
      }
    }
    else if ( v3 == 148 && (~v2 & 0x2002) == 0 )
    {
      a1a = a1;
      init_flag_check(a1, v2 & 0xFEFFFFFF, v2, 0);
      a1 = a1a;
    }
    v4 = (*(volatile uint32_t *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(volatile int16_t **)off_11E1BC < 0 && *(volatile uint32_t *)(a1 + 28) )
    {
      v10 = aDmaHdrdescHdFi;
      v11 = 436;
      return bad_func_0x12f408((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v4 = a1 + 160;
  }
  v5 = (void *)(uintptr_t)(off_11E1C0);
  v6 = *((volatile uint32_t *)off_11E1C0 + 5);
  if ( *((volatile uint32_t *)off_11E1C0 + 4) == v4 )
    v4 = *((volatile uint32_t *)off_11E1C0 + 3);
  *(volatile uint32_t *)(a1 + 152) = v4;
  v7 = v4 >= (v6 & 0x7FFFFFFFu);
  v8 = v6 & 0x80000000;
  if ( !v7 )
    v8 += 0x80000000;
  v5[5] = v4 | v8;
  return radio_get_status(a1);
}


// mem_is_null @ 0x11e1d0
int mem_is_null(int result, int a2, int a3, int a4) {
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
    v5 = (volatile int16_t **)off_11E268;
    v6 = dword_11E26C;
    result = a2;
    v7 = dword_11E264;
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
        mmio_clear_register(v6, v7, 1189);
        v7 = dword_11E264;
      }
      result = v12;
      a3 = 0;
    }
  }
  return result;
}



// mac_get_flag @ 0x11e270
int mac_get_flag(int a1) {
  volatile uint32_t *v1; // r4
  int result; // r0
  unsigned int v3; // r3
  int v4; // r1
  int v5; // r2

  v1 = (void *)(uintptr_t)(off_11E2C0);
  if ( *((volatile uint8_t *)off_11E2C0 + 33) )
    *(volatile uint32_t *)(*((volatile uint32_t *)off_11E2C0 + 6) + 4) = a1;
  else
    *((volatile uint32_t *)off_11E2C0 + 4) = a1;
  result = *((volatile uint8_t *)off_11E2C4 + 193);
  v3 = v1[7] + v1[3];
  v4 = v1[5] + v1[1];
  v5 = v1[2];
  v1[5] = v4;
  v1[7] = v3;
  *((volatile uint8_t *)v1 + 33) = 1;
  v1[6] = v5;
  if ( v3 >= result << 9 )
  {
    result = unknown_1(v1[4], v4, v5);
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    *((volatile uint8_t *)v1 + 33) = 0;
  }
  return result;
}



// mac_mcps_request @ 0x11e2c8
int mac_mcps_request(int a1, int a2, int a3, uint16_t a4, int a5, int a6) {
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
  v7 = (volatile uint8_t **)off_11E55C;
  v8 = *(volatile uint32_t *)(a1 + 28);
  v9 = *(volatile uint8_t **)off_11E55C;
  _frame.a1a[0] = v8;
  _frame.a4a = (_frame.a4a & ~0xFFFFu) | ((uint16_t)(a4) & 0xFFFFu);
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v22 = (void *)(uintptr_t)(off_11E56C);
  if ( *((volatile uint32_t *)off_11E56C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E570 = 1;
    }
    v23 = (volatile int *)off_11E590;
    v24 = dword_11E594;
    v25 = (uint16_t)v22[4122] > 0x186u;
    ++*(volatile uint32_t *)off_11E590;
    v26 = dword_11E574;
    if ( v25 )
      v22[4122] = 0;
    v27 = mem_word_load(v26);
    v28 = *(volatile uint32_t *)off_11E578;
    v29 = (uint16_t)v22[4122];
    v6 = v27;
    v30 = *(volatile uint32_t *)off_11E578 + 8 * v29;
    *((volatile uint16_t *)v6 + 6) = v29;
    *(volatile uint32_t *)(v30 + 4) = a1 + 48;
    *(volatile uint32_t *)(v28 + 8 * v29) = v24;
    v31 = (void *)(uintptr_t)(off_11E57C);
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
      v35 = *(volatile uint32_t *)off_11E570;
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
      mac_rx_handler(_frame.a1a, a2, (void *)(&_frame.a4a));
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v36 = (void *)(uintptr_t)(off_11E57C);
      if ( !*((volatile uint8_t *)off_11E57C + 2) )
        goto LABEL_6;
      v37 = v6[1];
      v6[2] = *(volatile uint16_t *)off_11E57C + 58;
      *(volatile uint8_t *)(v37 + 3) &= 0x3Fu;
      *((volatile uint8_t *)v6 + 14) = v36[3];
      *v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11E570 = 1;
      }
      v38 = (volatile int *)off_11E590;
      v39 = dword_11E580;
      ++*(volatile uint32_t *)off_11E590;
      co_list_push_back(v39, v6);
      check_init_flag();
      if ( *v38 )
      {
        v40 = *v38 - 1;
        v41 = *(volatile uint32_t *)off_11E570;
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
        v18 = (volatile int *)off_11E564;
        if ( *((volatile uint8_t *)off_11E564 + 32) )
        {
          v42 = is_scan_enabled();
          v43 = (int)v42;
          if ( v42 )
          {
            if ( *((volatile uint8_t *)v18 + 32) )
            {
              v44 = *v18;
              v45 = v18[1] + 1;
              v42[2] = (v45 << 24) & 0x7F000000 | v42[2] & 0x80FFFFFF;
              v18[1] = v45;
              pack_control_word(v42, a1 + 48, v44, 0x3Au, 0);
              v46 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11E588)[48]);
              v18[3] += 58;
              if ( v46 )
                mac_get_flag(v43);
              else
                unknown_1(v43, v18[1], v18[2]);
              *(volatile uint8_t *)off_11E58C |= 1u;
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
            event_dispatch("partial no tx_dscr_hdr\r\n");
            *((volatile uint8_t *)v18 + 32) = 0;
          }
        }
        check_status_bits(1024, "partial no tx_dscr_hdr!!\r\n");
        v19 = (volatile uint32_t *)*v18;
        *(volatile uint8_t *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v21 = v19;
            v19 = (volatile uint32_t *)v19[1];
            is_inquiry_enabled(v21);
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
      get_connection_state(a1, _frame.a1a[0]);
      v15 = (void *)(uintptr_t)(off_11E560);
      *(volatile uint32_t *)(a1 + 4) = a5;
      v16 = v15[14];
      *(volatile uint32_t *)(a1 + 8) = a6;
      if ( v16 )
        return co_list_push_back((int)(v15 + 14), (volatile uint32_t *)a1);
      else
        return co_list_push_back(dword_11E584, (volatile uint32_t *)a1);
    }
LABEL_2:
    if ( v11 == 1 )
      mac_tx_handler((void *)(_frame.a1a), a2, (void *)(&_frame.a4a));
    else
      mac_mlme_request((void *)(_frame.a1a), a2, a3, (void *)(&_frame.a4a), 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(volatile uint8_t *)(a1 + 16) |= 1u;
  get_connection_state(a1, v8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11E5F4 = 1;
  }
  v47 = (volatile int *)off_11E5F8;
  ++*(volatile uint32_t *)off_11E5F8;
  v48 = check_init_flag();
  if ( *v47 )
  {
    v49 = *v47 - 1;
    v50 = *(volatile uint32_t *)off_11E5F4;
    *v47 = v49;
    if ( !v49 )
    {
      if ( v50 )
        __enable_irq();
    }
  }
  return log_printf("rxl err, no buf %d\n", v48);
}


// mac_mlme_scan @ 0x11e604
int mac_mlme_scan(int a1) {
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
  v4 = (void *)(uintptr_t)(off_11E838);
  v5 = (volatile uint8_t **)off_11E83C;
  v6 = *((volatile uint8_t *)off_11E838 + 50);
  v7 = *(volatile uint8_t **)off_11E83C;
  v8 = a1;
  _frame.a4_2[0] = *(volatile uint32_t *)(a1 + 28);
  _frame.a4 = v6;
  v9 = *v7;
  if ( v9 == 3 )
  {
    v2 = j_fmac_tx_dispatch();
    v9 = **v5;
    v3 = v2 + 60;
  }
  if ( v9 == 2 )
  {
    v27 = (void *)(uintptr_t)(off_11E85C);
    if ( !*((volatile uint32_t *)off_11E85C + 2057) )
    {
      v59 = _frame.a4_2[0];
      *(volatile uint8_t *)(v8 + 16) |= 1u;
      get_connection_state(v8, v59);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11EA6C = 1;
      }
      v60 = (volatile int *)off_11EA70;
      ++*(volatile uint32_t *)off_11EA70;
      v61 = check_init_flag();
      if ( *v60 )
      {
        v62 = *v60 - 1;
        v63 = *(volatile uint32_t *)off_11EA6C;
        *v60 = v62;
        if ( !v62 )
        {
          if ( v63 )
            __enable_irq();
        }
      }
      return log_printf("err, no buf %d\n", v61);
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11E850 = 1;
    }
    v28 = (volatile int *)off_11E854;
    v29 = (uint16_t)v27[4122];
    v30 = dword_11E860;
    ++*(volatile uint32_t *)off_11E854;
    if ( v29 > 0x186 )
      v27[4122] = 0;
    v31 = mem_word_load(v30);
    v32 = *(volatile uint32_t *)off_11E864;
    v33 = (uint16_t)v27[4122];
    *((volatile uint16_t *)v31 + 6) = v33;
    v34 = (volatile uint32_t *)(v32 + 8 * v33);
    v34[1] = v8 + 48;
    *v34 = dword_11E868;
    v35 = (void *)(uintptr_t)(off_11E84C);
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
      v39 = *(volatile uint32_t *)off_11E850;
      *v28 = v38;
      if ( !v38 )
      {
        if ( v39 )
          __enable_irq();
      }
    }
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11E840 >= 0 )
    {
LABEL_37:
      v9 = **v5;
      if ( v9 == 2 )
      {
        mac_rx_handler(_frame.a4_2, v10, &_frame.a4);
        goto LABEL_7;
      }
LABEL_5:
      if ( v9 == 1 )
      {
        mac_tx_handler((void *)(_frame.a4_2), v10, &_frame.a4);
      }
      else
      {
        mac_mlme_request((void *)(_frame.a4_2), v10, v3, (void *)(&_frame.a4), 0);
        v4[7] = v10 + v3;
      }
LABEL_7:
      rf_call_handler((volatile uint64_t *)(v8 + 88), 0);
      v11 = **v5;
      if ( v11 == 3 )
      {
        v40 = (volatile int *)off_11EA58;
        v41 = *((volatile uint32_t *)off_11EA58 + 1);
        *(volatile uint32_t *)(v8 + 100) = dword_11EA5C;
        *(volatile uint32_t *)(v8 + 104) = v8 + 48;
        v42 = dword_11EA60;
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
          v20 = (volatile uint16_t *)off_11EA80;
          if ( *((volatile uint8_t *)off_11EA80 + 2) )
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
              *(volatile uint32_t *)off_11E850 = 1;
            }
            v22 = (volatile int *)off_11E854;
            v23 = dword_11E858;
            ++*(volatile uint32_t *)off_11E854;
            co_list_push_back(v23, v1);
            check_init_flag();
            if ( *v22 )
            {
              v24 = *v22 - 1;
              v25 = *(volatile uint32_t *)off_11E850;
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
              return get_connection_state(v8, _frame.a4_2[0]);
            goto LABEL_65;
          }
        }
        return get_connection_state(v8, _frame.a4_2[0]);
      }
      v12 = (volatile int *)off_11E844;
      if ( *((volatile uint8_t *)off_11E844 + 32) )
      {
        v51 = is_scan_enabled();
        v52 = (int)v51;
        if ( v51 )
        {
          if ( *((volatile uint8_t *)v12 + 32) )
          {
            v53 = *v12;
            v54 = v12[1] + 1;
            v51[2] = (v54 << 24) & 0x7F000000 | v51[2] & 0x80FFFFFF;
            v12[1] = v54;
            pack_control_word(v51, v8 + 48, v53, 0x3Au, 0);
            v55 = LOBYTE(((volatile uint32_t *)(uintptr_t)off_11EA84)[48]);
            v12[3] += 58;
            if ( v55 )
              mac_get_flag(v52);
            else
              unknown_1(v52, v12[1], v12[2]);
            v56 = (void *)(uintptr_t)(off_11EA88);
            v57 = *(volatile uint8_t *)off_11EA88;
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
          event_dispatch(aNoTxDscrHdr_0);
          *((volatile uint8_t *)v12 + 32) = 0;
        }
      }
      check_status_bits(1024, aNoTxDscrHdr);
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
          is_inquiry_enabled(v18);
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
        v20 = (volatile uint16_t *)off_11E84C;
        if ( *((volatile uint8_t *)off_11E84C + 2) )
          goto LABEL_17;
        return get_connection_state(v8, _frame.a4_2[0]);
      }
LABEL_64:
      if ( v19 == 3 )
      {
LABEL_65:
        v40 = (volatile int *)off_11EA58;
LABEL_41:
        read_global_halfword(*v40, _frame.a2, 5);
        while ( (*(volatile uint32_t *)off_11EA64 & 0x800) == 0 )
          ;
        v43 = *(volatile uint32_t *)off_11EA64;
        if ( (*(volatile uint32_t *)off_11EA64 & 0x40000) != 0 )
          *(volatile uint32_t *)off_11EA64 |= 0x4000000u;
        if ( (v43 & 0x800) != 0 )
        {
          CPSR = __get_CPSR();
          *(volatile uint32_t *)(dword_11EA68 + 4428) |= 0x8000000u;
          if ( CPSR )
          {
            *((volatile uint32_t *)off_11EA74 + 5) = 0;
          }
          else
          {
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_11EA6C = 1;
            }
            v45 = (void *)(uintptr_t)(off_11EA70);
            v46 = (void *)(uintptr_t)(off_11EA74);
            v47 = *(volatile uint32_t *)off_11EA70;
            v48 = *(volatile uint32_t *)off_11EA70 + 1;
            *(volatile uint32_t *)off_11EA70 = v48;
            v46[5] = 0;
            if ( v48 )
            {
              v49 = (void *)(uintptr_t)(off_11EA6C);
              *v45 = v47;
              if ( !v47 )
              {
                if ( *v49 )
                  __enable_irq();
              }
            }
          }
        }
        v50 = (void *)(uintptr_t)(off_11EA78);
        while ( !*(volatile uint32_t *)off_11EA78 )
          ;
        co_list_push_back(((volatile uint32_t *)(uintptr_t)off_11EA7C)[0] + 620, (volatile uint32_t *)(v2 - 20));
        *v50 = 1;
        gpio_set_pin3();
        return get_connection_state(v8, _frame.a4_2[0]);
      }
      return get_connection_state(v8, _frame.a4_2[0]);
    }
  }
  else
  {
    v10 = *(volatile uint16_t *)(v8 + 48);
    if ( **(volatile int16_t **)off_11E840 >= 0 )
      goto LABEL_5;
  }
  if ( !v10 )
    return bad_func_0x12f408((int)aMpduLen0, (int)aRxlMpduTransfe, 1545);
  if ( v10 <= 0x3000 )
    goto LABEL_37;
  return bad_func_0x12f408((int)aMpduLenRwnxMax, (int)aRxlMpduTransfe, 1547);
}


// llm_evt_queue_pop @ 0x11eaa0
int llm_evt_queue_pop(int a1) {
  void *v2; // r0
  volatile uint32_t *v3; // r1
  int v4; // r0
  char v5; // r2

  get_connection_state(a1, *(volatile uint32_t *)(a1 + 28));
  v2 = (void *)(uintptr_t)(off_11EAF0);
  if ( *((volatile uint32_t *)off_11EAF0 + 14) )
  {
    *(volatile uint8_t *)(a1 + 16) |= 1u;
    *(volatile uint32_t *)(a1 + 4) = 0;
    v3 = (volatile uint32_t *)a1;
    v4 = (int)v2 + 56;
    return co_list_push_back(v4, v3);
  }
  v4 = off_11EAF4;
  if ( *(volatile uint32_t *)off_11EAF4 )
  {
    v5 = *(volatile uint8_t *)(a1 + 16);
    *(volatile uint32_t *)(a1 + 4) = 0;
    *(volatile uint8_t *)(a1 + 16) = v5 | 1;
    v3 = (volatile uint32_t *)a1;
    return co_list_push_back(v4, v3);
  }
  return radio_get_status(a1);
}


// rf_status_poll @ 0x11eaf8
unsigned int rf_status_poll() {
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((volatile uint32_t *)off_11EB2C + 2);
  if ( v0 == *(volatile uint32_t *)off_11EB30 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((volatile uint32_t *)off_11EB2C + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(volatile uint32_t *)off_11EB2C )
      v2 += 0x80000000;
    v3 = v2 | *(volatile uint32_t *)off_11EB2C;
    *((volatile uint32_t *)off_11EB2C + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}



// ke_task_state_get @ 0x11eb34
int ke_task_state_get(int result) {
  int v1; // r4
  int16_t v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(volatile int16_t **)off_11EBB0 < 0 && *(volatile uint32_t *)(result + 20) != dword_11EBB8 )
    result = mmio_clear_register(dword_11EBC0, dword_11EBBC, 1811);
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
  v3 = dword_11EBB4;
  *(volatile uint8_t *)(v1 + 16) = 2;
  *(volatile uint8_t *)(v1 + 156) = 0;
  *(volatile uint32_t *)(v1 + 12) = v1;
  *(volatile uint32_t *)(v1 + 4) = v3;
  return result;
}



// rf_ctrl_enable @ 0x11ebc4
int rf_ctrl_enable() {
  volatile uint32_t *v0; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11EBF4);
  *(volatile uint32_t *)off_11EBF0 = 0x10000;
  *v0 &= ~0x10000u;
  result = unknown_func_12d104(0x80000);
  if ( *(volatile uint8_t *)off_11EBF8 )
    return poll_register_bit(result);
  return result;
}



// rf_irq_status_check @ 0x11ebfc
void rf_irq_status_check() {
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

  v0 = (void *)(uintptr_t)(off_11EC80);
  v1 = (void *)(uintptr_t)(off_11EC84);
  v2 = *((volatile uint32_t *)off_11EC80 + 5);
  if ( v2 != *(volatile uint32_t *)off_11EC84 )
  {
    v3 = dword_11EC88;
    v4 = (void *)(uintptr_t)(off_11EC90);
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
        event_dispatch(
          "rxbuf2 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
          v5 & 0x7FFFFFFF,
          v7,
          v0[3],
          v8,
          v5,
          *v1,
          *v4);
      ke_task_state_get(v6);
      *(volatile uint8_t *)(v6 + 156) = 1;
      rf_tx_frame(v6);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}


