// rx_queue_reset @ 0x11b80c
int rx_queue_reset() {
  volatile int *v0; // r5
  volatile int *v1; // r6
  int v2; // r4
  volatile uint8_t *v3; // r0
  int v4; // r3
  int16_t v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  int v11; // r1
  unsigned int v13; // r3
  int v14; // r2
  int v15; // r3

  v0 = (void *)(uintptr_t)(((volatile uint32_t *)(uintptr_t)&off_11B9B0)[0]);
  v1 = (void *)(uintptr_t)(off_11B9B4);
  v2 = *((volatile uint8_t *)(uintptr_t)((volatile uint32_t *)(uintptr_t)&off_11B9B0)[0] + (11));
  tx_set_power((volatile uint8_t *)(v2 + 4), 0);
  util_byte_to_hex(*(volatile uint8_t *)(v2 + 12));
  *(volatile uint32_t *)off_11B9B8 = v1[*(volatile uint8_t *)(v2 + 4) + 5];
  if ( *(volatile uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(volatile uint8_t *)(v2 + 16) = 4;
      if ( *((volatile uint8_t *)v0 + 90) || !*((volatile uint8_t *)off_11B9BC + 143) )
        goto LABEL_31;
      goto LABEL_29;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (volatile uint8_t *)ke_msg_send_1(68, 4, 0, 4);
  v4 = *(volatile uint8_t *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(volatile uint16_t *)(v2 + 14);
    if ( v5 )
      v5 = (v5 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  }
  else
  {
    v5 = (v5 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(volatile uint8_t *)(v2 + 26);
  rx_irq_handler_1((int)v3);
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(volatile uint8_t *)(v2 + 24) == 4
      && *(volatile uint16_t *)(v7 + 4) == *(volatile uint16_t *)(v2 + 4)
      && *(volatile uint8_t *)(v7 + 13) == *(volatile uint8_t *)(v2 + 13)
      && *(volatile uint16_t *)(v7 + 6) == *(volatile uint16_t *)(v2 + 6)
      && *(volatile uint16_t *)(v7 + 8) == *(volatile uint16_t *)(v2 + 8) )
    {
      v6 = *(volatile uint16_t *)(v7 + 10) == *(volatile uint16_t *)(v2 + 10);
    }
LABEL_7:
    *(volatile uint8_t *)(v7 + 16) = 1;
    v8 = *(volatile uint8_t *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(volatile uint8_t *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(volatile uint8_t *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((volatile uint8_t *)v0 + 90) && !v6 || !*((volatile uint8_t *)off_11B9BC + 143) )
    {
      if ( v8 != 3 )
        return write_bb_control();
      goto LABEL_31;
    }
    goto LABEL_29;
  }
  if ( *((volatile uint8_t *)off_11B9BC + 143) )
  {
LABEL_29:
    critical_section_exit();
    v13 = *(volatile uint8_t *)(v2 + 24);
    if ( v13 <= 2 )
      goto LABEL_10;
    if ( v13 != 3 )
      return write_bb_control();
LABEL_31:
    v14 = **(volatile int16_t **)off_11B9C8;
    v15 = v1[1] | 0x2200;
    *(volatile uint32_t *)off_11B9CC = 0;
    v1[1] = v15;
    if ( v14 < 0 && *(volatile uint32_t *)off_11B9D4 << 28 )
    {
      flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet_1, 472);
      v15 = v1[1];
    }
    *(volatile uint32_t *)off_11B9D0 = v15 | *v1;
    ke_evt_handler(141, 2, 255);
    return write_bb_control();
  }
LABEL_10:
  rf_reg_update_1();
  v9 = ((volatile uint32_t *)(uintptr_t)off_11B9C0)[2];
  if ( v9 )
  {
    v10 = dword_11B9C4;
    do
    {
      while ( *(volatile uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(volatile uint32_t *)v9;
        if ( !v9 )
          goto LABEL_15;
      }
      *(volatile uint8_t *)(v10 + 32 * *(volatile uint8_t *)(v9 + 95) + 31) = 1;
      check_link_id(v9);
      v9 = *(volatile uint32_t *)v9;
    }
    while ( v9 );
  }
LABEL_15:
  v11 = *(volatile uint16_t *)(v2 + 14);
  if ( v11 != 255 )
  {
    ke_evt_handler(62, v11, 0);
    *(volatile uint16_t *)(v2 + 14) = 255;
  }
  return write_bb_control();
}


// state_flag_check @ 0x11b9e0
int state_flag_check() {
  volatile uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_11BA0C);
  if ( (*((volatile uint8_t *)off_11BA0C + 88) & 8) != 0 )
  {
    v1 = dword_11BA10;
    goto LABEL_6;
  }
  if ( (*((volatile uint8_t *)off_11BA0C + 88) & 4) != 0 )
  {
    v1 = dword_11BA14;
LABEL_6:
    v2 = *((volatile uint32_t *)off_11BA0C + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(volatile uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return rx_queue_reset();
  }
  if ( *((volatile uint32_t *)off_11BA0C + 11) )
    return rx_queue_reset();
  return result;
}



// timer_countdown @ 0x11ba18
int timer_countdown(int result) {
  char v1; // r3
  void *v2; // r2

  if ( *((volatile uint8_t *)off_11BA44 + 89) )
  {
    v1 = *((volatile uint8_t *)off_11BA44 + 89) - 1;
    *((volatile uint8_t *)off_11BA44 + 89) = v1;
    if ( !v1 )
    {
      v2 = (void *)(uintptr_t)(off_11BA48);
      if ( *(volatile uint8_t *)off_11BA48 == 1 )
      {
        *(volatile uint8_t *)off_11BA48 = 0;
        rf_state_process(result, 1, (int)v2);
        return state_flag_check();
      }
    }
  }
  return result;
}



// scheduler_run @ 0x11ba4c
int scheduler_run(int a1, int a2, int a3) {
  int result; // r0

  rf_state_process(a1, a2, a3);
  result = tx_schedule();
  if ( !result )
    return state_flag_check();
  return result;
}



// env_reset @ 0x11ba64
int env_reset() {
  volatile int *v0; // r7
  volatile int *v1; // r6
  unsigned int v2; // r5
  volatile int *i; // r4
  int result; // r0
  volatile int *v5; // r3
  void *v6; // r1

  v0 = (volatile int *)off_11BAF4;
  v1 = (void *)(uintptr_t)(off_11BAF0);
  memset((void *)(uintptr_t)(off_11BAF0), 0, 0x5Cu);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    memset(i, 0, 0x1Cu);
    *((volatile uint16_t *)i + 7) = 255;
    *((volatile uint8_t *)i + 24) = -1;
    if ( v2 <= 2 )
    {
      check_kernel_state((int)v1, (void *)(i));
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((volatile uint16_t *)v0 + 47) = 0;
    *((volatile uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  list_init_1((volatile uint32_t *)dword_11BAF8);
  list_init_1((volatile uint32_t *)dword_11BAFC);
  check_kernel_state(dword_11BAF8, (volatile uint32_t *)dword_11BB00);
  check_kernel_state(dword_11BAF8, (volatile uint32_t *)dword_11BB04);
  check_kernel_state(dword_11BAF8, (volatile uint32_t *)dword_11BB08);
  result = check_kernel_state(dword_11BAF8, (volatile uint32_t *)dword_11BB0C);
  v5 = (void *)(uintptr_t)(off_11BAF0);
  v6 = (void *)(uintptr_t)(off_11BB14);
  ((volatile uint32_t *)(uintptr_t)off_11BAF0)[13] = (int)off_11BB10;
  v5[17] = (int)v6;
  v5[18] = 0;
  return result;
}


// rf_status_read @ 0x11bb18
int rf_status_read(volatile int16_t *a1, int a2, char a3) {
  volatile uint8_t *v3; // r4
  int16_t v7; // r3
  volatile uint8_t *v8; // r2

  v3 = (void *)(uintptr_t)(off_11BB94);
  if ( **(volatile int16_t **)off_11BB90 < 0 && *((volatile uint8_t *)off_11BB94 + 108) != 255 )
    flash_ctrl_init(dword_11BBA0, dword_11BB9C, 2838);
  v3[108] = 3;
  *((volatile uint16_t *)v3 + 49) = 255;
  v3[88] = *((volatile uint8_t *)a1 + 2);
  v7 = *a1;
  *((volatile uint16_t *)v3 + 46) = *a1;
  *((volatile uint16_t *)v3 + 45) = v7;
  v8 = (void *)(uintptr_t)(off_11BB98);
  v3[96] = *((volatile uint8_t *)a1 + 4);
  v7 = (v7 & ~0xFFu) | ((uint8_t)(v8[88]) & 0xFFu);
  v3[97] = *((volatile uint8_t *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((volatile uint32_t *)v3 + 26) = a2;
  v3[100] = 1;
  return rf_flag_set();
}



// tx_header_prepare @ 0x11bba4
int tx_header_prepare(volatile uint8_t *a1, int a2) {
  volatile uint8_t *v2; // r7
  int v5; // r5
  unsigned int v6; // r3
  volatile int *v7; // r4
  char v8; // r3
  volatile uint32_t *v10; // r0
  int v11; // r2
  int16_t v12; // r2
  unsigned int v13; // r2
  int v14; // r3
  volatile int *v15; // r2
  volatile uint32_t *v16; // r0
  int v17; // r0

  v2 = (void *)(uintptr_t)(off_11BD2C);
  check_interrupt_flag(8, "roc: %d, dur=%d, st=%d\r\n", *a1, *((volatile uint32_t *)a1 + 3), *((volatile uint8_t *)off_11BD2C + 128));
  v5 = *a1;
  if ( *a1 )
  {
    if ( v5 == 1 )
    {
      if ( (uint8_t)v2[136] == 255 )
        return 0;
      v6 = (uint8_t)v2[128];
      v7 = (void *)(uintptr_t)(off_11BD34);
      if ( v6 > 3 )
      {
        if ( v6 == 4 )
        {
          ke_exit_critical(off_11BD34 + 16);
          v10 = (volatile uint32_t *)v7[8];
          v7[18] = 0;
          tx_processing(v10);
        }
      }
      else if ( v6 > 1 )
      {
        v11 = ((volatile uint32_t *)(uintptr_t)off_11BD34)[11];
        *((volatile uint8_t *)off_11BD34 + 88) &= ~4u;
        if ( v11 )
        {
          if ( (volatile uint8_t *)v11 == v2 + 112 && v7[20] == v11 )
          {
            ke_exit_critical((int)(uintptr_t)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        send_hci_event_1(dword_11BD38);
      }
      else if ( v6 == 1 )
      {
        *((volatile uint8_t *)off_11BD34 + 88) &= 0xFAu;
        send_hci_event_1((int)(v2 + 112));
      }
      v8 = *((volatile uint8_t *)v7 + 88);
      v2[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v16 = (volatile uint32_t *)dword_11BD40;
      *((volatile uint8_t *)v7 + 88) = v8 & 0xEF;
      v5 = 0;
      ke_exit_critical((int)(uintptr_t)(v16));
      return v5;
    }
    return 1;
  }
  if ( (uint8_t)v2[136] == 255 && v2[128] != 4 )
  {
    v2[136] = 4;
    v2[116] = a1[2];
    v2[117] = a1[3];
    v12 = *((volatile uint16_t *)a1 + 3);
    *((volatile uint16_t *)v2 + 59) = *((volatile uint16_t *)a1 + 2);
    *((volatile uint16_t *)v2 + 61) = *((volatile uint16_t *)a1 + 4);
    *((volatile uint16_t *)v2 + 60) = v12;
    v2[124] = a1[16];
    v2[128] = 1;
    v2[125] = v5;
    v13 = *((volatile uint32_t *)a1 + 3);
    *((volatile uint16_t *)v2 + 63) = a2;
    v14 = 1000 * v13;
    if ( v13 > 0x23 )
      v14 -= 35000;
    *((volatile uint32_t *)v2 + 33) = v14;
    v15 = (void *)(uintptr_t)(off_11BD34);
    v2[138] = a1[1];
    if ( a2 )
    {
      *((volatile uint8_t *)v15 + 88) |= 1u;
      rf_flag_set();
    }
    else
    {
      v17 = dword_11BD38;
      *((volatile uint8_t *)v15 + 88) |= 4u;
      rf_register_access(v17);
    }
    *(volatile uint32_t *)off_11BD3C |= 4u;
    return v5;
  }
if ( (((volatile uint32_t *)(uintptr_t)off_11BD34)[22] & 0x20) == 0 ) return 1;
  *((volatile uint8_t *)off_11BD34 + 88) &= ~0x20u;
  return 1;
}


// env_get @ 0x11bd44
int env_get(int a1, volatile uint8_t *a2) {
  int v4; // r0
  char v5; // r2
  int v6; // r1

  v4 = (int)(uintptr_t)(list_pop_front(dword_11BD7C));
  if ( !v4 )
    return 1;
  v5 = dword_11BD84 * ((v4 - dword_11BD80) >> 2);
  *(volatile uint8_t *)(v4 + 24) = v5;
  *a2 = v5;
  v6 = *(volatile uint32_t *)(a1 + 4);
  *(volatile uint32_t *)(v4 + 4) = *(volatile uint32_t *)a1;
  *(volatile uint32_t *)(v4 + 8) = v6;
  *(volatile uint16_t *)(v4 + 12) = *(volatile uint16_t *)(a1 + 8);
  return 0;
}



// lookup_7byte_channel @ 0x11bd88
/* luna: Deletes a channel context by index, performing deletion-state checks and then zeroing the context record while marking it unavailable. */
int lookup_7byte_channel(int a1) {
  volatile int16_t **chan_ctxt_count_ptr; // r8
  int chan_ctxt_table_base; // r5
  volatile int *target_chan_ctxt; // r6
  int v5; // r7
  int v6; // r5
  int result; // r0

  chan_ctxt_count_ptr = (volatile int16_t **)off_11BE24;
  chan_ctxt_table_base = dword_11BE10;
  target_chan_ctxt = (volatile int *)(dword_11BE10 + 28 * a1);
  if ( **(volatile int16_t **)off_11BE24 < 0 )
  {
    v5 = 8 * a1;
    if ( *(volatile uint8_t *)(dword_11BE10 + 28 * a1 + 24) != 255
      || (flash_ctrl_init((int)aCtxtIdxChanCtx, (int)aChanCtxtDel, 3044), **chan_ctxt_count_ptr < 0) )
    {
      if ( *(volatile uint8_t *)(chan_ctxt_table_base + 4 * (v5 - a1) + 25) )
        flash_ctrl_init((int)aCtxtNbLinkedVi, (int)aChanCtxtDel, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  check_kernel_state(dword_11BE14, (void *)(target_chan_ctxt));
  v6 = chan_ctxt_table_base + 4 * (v5 - a1);
  result = (int)memset(target_chan_ctxt, 0, 0x1Cu);
  *(volatile uint16_t *)(v6 + 14) = 255;
  *(volatile uint8_t *)(v6 + 24) = -1;
  return result;
}


// rx_desc_parse @ 0x11be28
int rx_desc_parse(volatile uint8_t *a1) {
  int v1; // r4
  int result; // r0
  volatile uint8_t *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  volatile int *v8; // r7
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(volatile uint32_t *)(a1 + 2);
  v4 = dword_11BEB4;
  v5 = *((volatile uint32_t *)off_11BEB0 + 10);
  v6 = *((volatile uint32_t *)v3 + 1);
  v7 = dword_11BEB4 + 28 * v1 + 4;
  *(volatile uint32_t *)v7 = result;
  *(volatile uint32_t *)(v7 + 4) = v6;
  *(volatile uint16_t *)(v7 + 8) = *((volatile uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11BEB8 = 1;
    }
    v8 = (volatile int *)off_11BEBC;
    ++*(volatile uint32_t *)off_11BEBC;
    mmio_bit16_toggle();
    ((int (*)())mmio_regs_init)(0, v9, v10, v11);
    if ( *v8 )
    {
      v12 = *v8 - 1;
      v13 = *(volatile uint32_t *)off_11BEB8;
      *v8 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
    tx_set_power(v3, 0);
    return util_byte_to_hex(*(volatile char *)(v4 + 28 * v1 + 12));
  }
  return result;
}



// rf_tx_packet_check @ 0x11bec0
int rf_tx_packet_check(int result, int a2) {
  int v2; // r4
  int v3; // r5
  int v5; // r7
  unsigned int v6; // r3
  int v7; // r8

  v2 = *(volatile uint8_t *)(result + 1);
  v3 = dword_11BF2C;
  if ( **(volatile int16_t **)off_11BF28 < 0 )
  {
    v7 = dword_11BF2C + 28 * v2;
    v5 = 8 * v2;
    v6 = *(volatile uint8_t *)(v7 + 16);
    if ( !*(volatile uint8_t *)(v7 + 16) )
    {
      result = flash_ctrl_init(dword_11BF34, dword_11BF30, 3289);
      if ( *(volatile uint8_t *)(v7 + 16) <= 3u )
        goto LABEL_4;
      return ke_evt_handler(62, a2, 0);
    }
  }
  else
  {
    v5 = 8 * v2;
    v6 = *(volatile uint8_t *)(dword_11BF2C + 28 * v2 + 16);
  }
  if ( v6 <= 3 )
  {
LABEL_4:
    *(volatile uint16_t *)(v3 + 4 * (v5 - v2) + 14) = a2;
    return result;
  }
  return ke_evt_handler(62, a2, 0);
}



// ke_event_process @ 0x11bf38
BOOL ke_event_process(int a1, int a2) {
  int v2; // r10
  volatile int *v3; // r4
  int v5; // r3
  int v6; // r7
  int v7; // r9
  int v9; // r1

  v2 = off_11C014;
  v3 = *(volatile int **)(off_11C014 + 0x10);
  if ( !v3 )
  {
    v6 = *(volatile uint32_t *)(a1 + 72);
    v7 = *(volatile uint32_t *)(off_11C014 + 0x28);
    goto LABEL_10;
  }
  v5 = v3[1];
  v6 = *(volatile uint32_t *)(a1 + 72);
  v7 = *(volatile uint32_t *)(off_11C014 + 0x28);
  if ( v5 != a2 )
  {
    while ( v5 - a2 < 0 )
    {
      v9 = *((volatile uint8_t *)v3 + 8);
      if ( v9 == *(volatile uint8_t *)(a1 + 95) )
      {
        dispatch_event_handler_1("actually remove:%d\n", v9);
        check_kernel_state_alt2(v2 + 16, (void *)(v3));
        *((volatile uint8_t *)v3 + 9) &= ~1u;
        v3 = (volatile int *)*v3;
        if ( !v3 )
          break;
      }
      else
      {
        v3 = (volatile int *)*v3;
        if ( !v3 )
          break;
      }
      v5 = v3[1];
      if ( v5 == a2 )
        goto LABEL_7;
    }
LABEL_10:
    if ( *(volatile uint8_t *)(v2 + 0x5A) > 1u )
    {
      *(volatile uint8_t *)(a1 + 85) |= 4u;
      return v6 != v7;
    }
    goto LABEL_13;
  }
LABEL_7:
  if ( *(volatile uint8_t *)(v2 + 0x5A) > 1u )
  {
    check_kernel_state_alt2(dword_11C010, (volatile uint32_t *)(a1 + 76));
    *(volatile uint8_t *)(a1 + 85) = *(volatile uint8_t *)(a1 + 85) & 0xFC | 2;
    ++*(volatile uint8_t *)(v2 + 0x5B);
    return v6 != v7;
  }
LABEL_13:
  *(volatile uint8_t *)(a1 + 85) |= 2u;
  ++*(volatile uint8_t *)(v2 + 0x5B);
  return v6 != v7;
}


// bt_link_tx_check @ 0x11c01c
int bt_link_tx_check(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r3
  int v5; // r2
  int v6; // r7
  int v7; // r8
  int v8; // r7
  int v9; // r4
  int v10; // r3
  volatile int *v11; // r4
  int v12; // r1
  int v13; // r3
  int v14; // r2
  int v15; // r0
  volatile int *v16; // r2
  int v17; // r2

  v1 = (void *)(uintptr_t)(off_11C144);
  if ( *((volatile uint8_t *)off_11C144 + 90) <= 1u )
    return result;
  v2 = result;
  if ( (*(volatile uint8_t *)(result + 85) & 2) != 0 )
    return result;
  v3 = *((volatile uint32_t *)off_11C144 + 9);
  if ( (*(volatile uint8_t *)(result + 85) & 4) != 0 )
    *(volatile uint8_t *)(result + 85) &= ~4u;
  if ( !v3 || *(volatile uint32_t *)(v3 + 12) != result + 76 )
    return rf_event_dispatch(result, *(volatile uint32_t *)(result + 36), 0);
  v6 = *(volatile uint32_t *)(result + 80);
  v7 = *(volatile uint32_t *)(result + 36);
  if ( v6 - v7 >= 0 )
    goto LABEL_14;
  if ( v7 - 4000 - v6 - os_get_tick_hz() >= 0 )
  {
    v7 = *(volatile uint32_t *)(v2 + 36);
    v6 = *(volatile uint32_t *)(v2 + 80);
LABEL_14:
    if ( v7 - v6 >= 0 || v6 - 4000 - v7 - os_get_tick_hz() >= 0 )
    {
      rx_buffer_alloc();
      rf_event_dispatch(v2, *(volatile uint32_t *)(v2 + 36), 0);
      return rf_calibrate_1(v2, *((volatile uint32_t *)off_11C150 + 4), 0);
    }
  }
  v8 = *(volatile uint32_t *)(v2 + 36);
  *(volatile uint32_t *)(v2 + 80) = v8;
  result = os_get_tick_hz();
  if ( (int)(v8 - *(volatile uint32_t *)(v3 + 4) - result - 4000) < 0 )
  {
    v9 = *(volatile uint32_t *)(v2 + 80);
    result = os_get_tick_hz();
    v10 = v1[18];
    *(volatile uint32_t *)(v3 + 4) = v9 - 4000 - result;
    if ( v10 == v3 )
    {
      ke_exit_critical(dword_11C148);
      v1[18] = v3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_11C14C = 1;
      }
      v11 = (volatile int *)off_11C154;
      v12 = *(volatile uint32_t *)(v3 + 4);
      v13 = *(volatile uint32_t *)off_11C154;
      v14 = v12 - *((volatile uint32_t *)off_11C150 + 4);
      v15 = *(volatile uint32_t *)off_11C154 + 1;
      *(volatile uint32_t *)off_11C154 = v15;
      if ( v14 - 64 >= 0 )
      {
        result = ke_enter_critical((void *)(uintptr_t)(dword_11C148), v12);
        if ( *v11 )
        {
          v4 = *v11 - 1;
          v5 = *(volatile uint32_t *)off_11C14C;
          *v11 = v4;
          if ( !v4 )
          {
            if ( v5 )
              __enable_irq();
          }
        }
      }
      else
      {
        if ( v15 )
        {
          v16 = (volatile int *)off_11C14C;
          *v11 = v13;
          v17 = *v16;
          if ( !v13 )
          {
            if ( v17 )
              __enable_irq();
          }
        }
        return ((int ( *)(int))v1[17])(v3);
      }
    }
  }
  return result;
}



// bt_link_rx_check @ 0x11c158
int bt_link_rx_check(int result) {
  void *v1; // r5
  int v2; // r4
  int v3; // r3
  int v4; // r6
  int v5; // r7
  char v6; // r3
  char v7; // r2
  int v8; // r8
  int v9; // r2
  int v10; // r3
  char v11; // r2

  v1 = (void *)(uintptr_t)(off_11C260);
  v2 = result;
  v3 = *(volatile uint8_t *)(result + 85);
  if ( *((volatile uint8_t *)off_11C260 + 90) <= 1u )
  {
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFDu;
      *(volatile uint8_t *)(result + 85) = v3;
      v11 = *((volatile uint8_t *)v1 + 91) - 1;
      *((volatile uint8_t *)v1 + 91) = v11;
      if ( !v11 && (*((volatile uint8_t *)v1 + 88) & 0x40) != 0 )
      {
        rf_register_access(*((volatile uint32_t *)v1 + 20));
        v3 = *(volatile uint8_t *)(v2 + 85);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFBu;
      *(volatile uint8_t *)(v2 + 85) = v3;
    }
    result = v3 << 26;
    if ( (v3 & 0x20) != 0 )
      *(volatile uint8_t *)(v2 + 85) = v3 & 0xDF;
  }
  else
  {
    v4 = v3 & 4;
    v5 = *(volatile uint32_t *)(result + 36);
    if ( (v3 & 4) != 0 )
    {
      if ( (v3 & 1) == 0 )
      {
        result = rf_event_dispatch(result, *(volatile uint32_t *)(result + 36), 0);
        v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v2 + 85)) & 0xFFu);
      }
      *(volatile uint8_t *)(v2 + 85) = v3 & 0xFB;
    }
    else if ( (v3 & 2) != 0 )
    {
      v6 = v3 & 0xFD;
      *(volatile uint8_t *)(result + 85) = v6;
      v7 = *((volatile uint8_t *)v1 + 91) - 1;
      *((volatile uint8_t *)v1 + 91) = v7;
      if ( !v7 )
      {
        if ( (*((volatile uint8_t *)v1 + 88) & 0x40) != 0 )
        {
          result = rf_register_access(*((volatile uint32_t *)v1 + 20));
          v6 = *(volatile uint8_t *)(v2 + 85);
        }
        else
        {
          v4 = 1;
        }
      }
      v8 = *(volatile uint32_t *)(v2 + 80);
      if ( (v6 & 8) != 0 )
      {
        v9 = *(volatile uint8_t *)(v2 + 94);
        *(volatile uint8_t *)(v2 + 85) = v6 & 0xF7;
        if ( v9 )
          v10 = 102400;
        else
          v10 = *(volatile uint32_t *)(dword_11C268 + 152 * *(volatile uint8_t *)(v2 + 102) + 8);
        v8 -= v10;
      }
      else
      {
        result = rf_event_dispatch(v2, v5, 0);
      }
      if ( v4 )
      {
        if ( !*((volatile uint32_t *)v1 + 11) )
          return rf_calibrate_1(v2, *((volatile uint32_t *)off_11C264 + 4), *((volatile uint32_t *)off_11C264 + 4) - v8);
      }
    }
  }
  return result;
}



// rf_get_status_1 @ 0x11c26c
int rf_get_status_1(int result) {
  int v1; // r7
  int v2; // r5
  volatile uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  int16_t v6; // r5
  int16_t v7; // r4
  int v8; // r2

  v1 = *(volatile uint32_t *)(result + 72);
  v2 = result;
  if ( **(volatile int16_t **)off_11C30C < 0 && !v1 )
    result = flash_ctrl_init(dword_11C320, dword_11C31C, 3591);
  v3 = (void *)(uintptr_t)(off_11C310);
  if ( (*((volatile uint8_t *)off_11C310 + 88) & 0x20) == 0 && *((volatile uint8_t *)off_11C310 + 90) > 1u )
  {
    v4 = *(volatile uint8_t *)(v2 + 102);
    v5 = ke_msg_send_1(70, *((volatile uint8_t *)off_11C310 + 88) & 0x20, *((volatile uint8_t *)off_11C310 + 88) & 0x20, 20);
    *(volatile uint8_t *)v5 = 0;
    *(volatile uint8_t *)(v5 + 1) = *(volatile uint8_t *)(v2 + 95);
    *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 4);
    *(volatile uint8_t *)(v5 + 3) = *(volatile uint8_t *)(v1 + 5);
    v6 = *(volatile uint16_t *)(v1 + 8);
    v7 = *(volatile uint16_t *)(v1 + 10);
    v8 = dword_11C314;
    *(volatile uint16_t *)(v5 + 4) = *(volatile uint16_t *)(v1 + 6);
    *(volatile uint16_t *)(v5 + 6) = v6;
    *(volatile uint16_t *)(v5 + 8) = v7;
    *(volatile uint8_t *)(v5 + 16) = *(volatile uint8_t *)(v1 + 12);
    *(volatile uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_11C318
                                         * (uint64_t)(unsigned int)(*(volatile uint32_t *)(v8 + 152 * v4 + 8) - 5000)) >> 32) >> 6;
    result = (int)(uintptr_t)(rx_irq_handler_1(v5));
    v3[88] |= 0x20u;
  }
  return result;
}



// bt_conn_find_by_ptr @ 0x11c324
int bt_conn_find_by_ptr(int result) {
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r2

  if ( *(volatile uint8_t *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_11C384;
    while ( 1 )
    {
      v3 = *(volatile uint32_t *)(v2 + 72);
      v2 += 224;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v4 = *(volatile char *)(dword_11C384 + 224 * v1 + 97);
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = (void *)(uintptr_t)(off_11C388);
    *(volatile uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return util_byte_to_hex(v4);
  }
  else
  {
    v6 = (void *)(uintptr_t)(off_11C388);
    *(volatile uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return util_byte_to_hex(15);
  }
  return result;
}



