// conn_schedule @ 0x1174b4
int conn_schedule(int result) {
  int v1; // r6
  unsigned int v2; // r4
  unsigned int v3; // r7
  int v4; // r3
  volatile unsigned int *v5; // r8
  int v6; // r5
  int v7; // r3
  int v8; // r2
  unsigned int v9; // r3
  uint16_t v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r5
  volatile uint32_t *v15; // r11
  int v16; // r10
  int v17; // r3
  int v18; // r1
  int v19; // r0
  unsigned int v20; // r3
  volatile unsigned int v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  int v24; // r10
  int v25; // r3
  volatile uint32_t *v26; // r2
  volatile uint32_t *v27; // r5
  int v28; // r1
  volatile int *v29; // r3
  int v30; // r3
  unsigned int v31; // r1
  int v32; // r10
  volatile unsigned int v33; // r2
  volatile int *v34; // r3
  int v35; // r3
  volatile uint32_t *v36; // r2
  volatile uint32_t *v37; // r4
  int v38; // r1
  volatile int *v39; // r3
  int v40; // r3
  int v41; // [sp+0h] [bp-14h]
  int v42; // [sp+4h] [bp-10h]
  unsigned int v43; // [sp+8h] [bp-Ch]
  int v44; // [sp+Ch] [bp-8h]

  v1 = result;
  if ( result == 5 )
    v2 = dword_1178C4;
  else
    v2 = dword_11777C + 84 * result;
  v3 = dword_117784;
  v41 = 1 << result;
  v4 = *(volatile uint8_t *)(v2 + 26);
  v43 = result + dword_117780;
  v5 = (volatile unsigned int *)(4 * (result + dword_117780));
  v42 = ~(1 << result);
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !v4 )
        goto LABEL_14;
      v6 = *(volatile uint32_t *)(v2 + 36);
      v7 = *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1);
      v8 = *(volatile uint32_t *)(v6 + 144);
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1) )
      {
        if ( v8 >= 0 )
          return result;
        if ( *(volatile uint32_t *)(v6 + 88) || *(volatile uint8_t *)(v2 + 80) != 1 )
        {
          v9 = REG_4032_0120 + *(volatile uint32_t *)(dword_117788 + 4 * v1);
          *v5 = v9;
LABEL_9:
          if ( (v8 & 0x800000) != 0 )
          {
            v10 = *(volatile uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) == 0 )
            {
              mac_irq_handler_1();
              v32 = 4;
              while ( 1 )
              {
                v10 = *(volatile uint16_t *)(v6 + 8);
                if ( (v10 & 0x20) != 0 )
                  break;
                mac_irq_handler_1();
                if ( !--v32 )
                {
                  v10 = *(volatile uint16_t *)(v6 + 8);
                  if ( **(volatile int16_t **)dword_1178AC < 0 && (v10 & 0x20) == 0 )
                    return ke_int_lock_1((int)aAggDescStatusA, (int)aTxlFrameExchan_0, 1262);
                  goto LABEL_11;
                }
              }
            }
          }
          else
          {
LABEL_36:
            list_pop_front(v2 + 28);
            v10 = *(volatile uint16_t *)(v6 + 8);
          }
          goto LABEL_11;
        }
      }
      else
      {
        if ( *(volatile int *)(v6 + 76) >= 0 )
          return result;
        if ( *(volatile uint32_t *)(v6 + 20) || *(volatile uint8_t *)(v2 + 80) != 1 )
        {
          v23 = REG_4032_0120 + *(volatile uint32_t *)(dword_117788 + 4 * v1);
          *v5 = v23;
          goto LABEL_31;
        }
      }
      if ( *(volatile uint32_t *)(v2 + 44)
        && !*(volatile uint32_t *)(dword_1177A8 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
        && !*(volatile uint8_t *)(dword_1178D8 + 0x1FF) )
      {
        v44 = *(volatile uint32_t *)(v6 + 144);
        llc_tx_llcp_handler(v1);
        v8 = v44;
        v7 = *(volatile uint8_t *)(*(volatile uint32_t *)v3 + 1);
      }
      v31 = REG_4032_0120 + *(volatile uint32_t *)(dword_117788 + 4 * v1);
      *v5 = v31;
      if ( v7 )
        goto LABEL_9;
LABEL_31:
      v10 = *(volatile uint16_t *)(v6 + 8);
      if ( (v10 & 0x20) == 0 )
      {
        mac_irq_handler_1();
        v24 = 4;
        while ( 1 )
        {
          v10 = *(volatile uint16_t *)(v6 + 8);
          if ( (v10 & 0x20) != 0 )
            break;
          mac_irq_handler_1();
          if ( !--v24 )
          {
            v10 = *(volatile uint16_t *)(v6 + 8);
            if ( (v10 & 0x20) != 0 )
              break;
            goto LABEL_36;
          }
        }
      }
LABEL_11:
      v11 = *(volatile uint32_t *)(dword_11778C + 4 * v1);
      *(volatile uint16_t *)(v6 + 8) = v10 | 0x10;
      result = set_system_flag_1(v11);
      v12 = *(volatile uint32_t *)v3;
      --*(volatile uint8_t *)(v2 + 80);
      *(volatile uint8_t *)(v2 + 26) = 0;
      *(volatile uint32_t *)(v2 + 36) = 0;
      if ( *(volatile uint8_t *)(v12 + 1) )
        break;
      v13 = *(volatile uint32_t *)(v6 + 20);
      if ( v13 )
        goto LABEL_13;
LABEL_38:
      *(volatile uint32_t *)v2 = v13;
      v25 = *(volatile uint32_t *)dword_117798;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)dword_11779C = 1;
      }
      v26 = (volatile uint32_t *)dword_1177A0;
      result = *(volatile uint32_t *)dword_1177A0;
      v27 = (volatile uint32_t *)dword_117798;
      v28 = *(volatile uint32_t *)dword_1177A0 + 1;
      *(volatile uint32_t *)dword_1177A0 = v28;
      *v27 = v25 & v42;
      if ( v28 )
      {
        v29 = (volatile int *)dword_11779C;
        *v26 = result;
        v30 = *v29;
        if ( !result )
        {
          if ( v30 )
            __enable_irq();
        }
      }
      *(volatile uint32_t *)dword_1177A4 = v41;
      v4 = *(volatile uint8_t *)(v2 + 26);
    }
    v13 = *(volatile uint32_t *)(v6 + 88);
    if ( !v13 )
      goto LABEL_38;
LABEL_13:
    *(volatile uint32_t *)(v2 + 40) = v6;
    ++*(volatile uint8_t *)(v6 + 14);
LABEL_14:
    v14 = *(volatile uint32_t *)(v2 + 12);
    if ( !v14 )
      break;
    v15 = *(volatile uint32_t **)(v14 + 76);
    v16 = v15[18];
    if ( v16 >= 0 )
    {
      if ( (*(volatile uint32_t *)(v14 + 36) & 0x380000) == 0x280000 )
        return assert_fail_handler(*(volatile uint32_t *)(v14 + 68) + 16, v1);
      return result;
    }
    v15[1] = v16;
    llc_conn_timer_tick(v1);
    v17 = *(volatile uint32_t *)(v14 + 36) & 0x200000;
    if ( !v17 )
    {
      v18 = v15[4];
      if ( v18 )
      {
        v19 = v15[4];
        if ( (*(volatile uint32_t *)(v18 + 56) & 0x380000) == 0x200000 )
        {
          if ( **(volatile int16_t **)dword_1177AC < 0 && !*(volatile uint32_t *)(v18 + 8) )
          {
            mmio_irq_clear((int)aNextdescNull, (int)aTxlFrameExchan_0, 1077);
            __und(0xFFu);
          }
          v17 = v15[4];
          v19 = *(volatile uint32_t *)(v18 + 8);
        }
        if ( *(volatile int *)(v19 + 60) >= 0 )
        {
          result = v17;
          if ( v17 )
            result = assert_fail_handler(v17, v1);
          v33 = REG_4032_0120;
          *(volatile uint32_t *)(4 * v43) = v33 + *(volatile uint32_t *)(dword_1178B8 + 4 * v1);
          return result;
        }
      }
      else
      {
        *(volatile uint32_t *)v2 = 0;
        mmio_set_bit(v1);
        if ( *(volatile uint8_t *)(v2 + 80) == 1
          && *(volatile uint32_t *)(v2 + 44)
          && !*(volatile uint32_t *)(dword_1177A8 + 8 * (165 * *(volatile uint8_t *)(*(volatile uint32_t *)(v2 + 48) + 28) + v1 + 154))
          && !*(volatile uint8_t *)(dword_11777C + 0x1FF) )
        {
          llc_tx_llcp_handler(v1);
        }
      }
    }
    if ( (v16 & 0x800000) != 0 )
    {
      v20 = *(volatile uint8_t *)(v14 + 29);
      if ( v20 <= 0x23 )
      {
        v21 = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(dword_117790 + 696 * v20 + 664) = v21;
      }
    }
    list_pop_front(v2 + 12);
    if ( *(volatile uint16_t *)(v14 + 4) )
      list_append((volatile uint32_t *)v14, v16, v1);
    else
      btlp_enter_sleep((volatile uint32_t *)v14);
    v22 = *(volatile uint32_t *)(v14 + 36);
    result = v22 << 10;
    if ( (v22 & 0x200000) != 0 )
    {
      if ( (v22 & 0x380000) == 0x380000 )
      {
        *(volatile uint32_t *)(v2 + 36) = *(volatile uint32_t *)(v14 + 68);
        *(volatile uint8_t *)(v2 + 26) = 1;
        result = set_system_flag_1(512);
      }
    }
    else
    {
      --*(volatile uint8_t *)(v2 + 80);
    }
    *v5 = REG_4032_0120 + *(volatile uint32_t *)(dword_117788 + 4 * v1);
    v4 = *(volatile uint8_t *)(v2 + 26);
  }
  v34 = (volatile int *)dword_1178C8;
  *(volatile uint32_t *)v2 = 0;
  v35 = *v34;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_1178CC = 1;
  }
  v36 = (volatile uint32_t *)dword_1178D0;
  result = *(volatile uint32_t *)dword_1178D0;
  v37 = (volatile uint32_t *)dword_1178C8;
  v38 = *(volatile uint32_t *)dword_1178D0 + 1;
  *(volatile uint32_t *)dword_1178D0 = v38;
  *v37 = v35 & v42;
  if ( v38 )
  {
    v39 = (volatile int *)dword_1178CC;
    *v36 = result;
    v40 = *v39;
    if ( !result )
    {
      if ( v40 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)dword_1178D4 = v41;
  return result;
}


// conn_get @ 0x1178dc
int conn_get(int a1) {
  volatile uint32_t *v2; // r5
  int v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r2
  volatile int *v6; // r5
  int v7; // r1
  int result; // r0
  volatile int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v2 = (volatile uint32_t *)dword_117970;
  else
    v2 = (volatile uint32_t *)(dword_117958 + 84 * a1);
  rf_calib_config(a1, dword_11795C + 8 * a1, 0);
  rf_calib_config(a1, (int)(uintptr_t)(v2 + 3), 0);
  *v2 = 0;
  v2[5] = 0;
  bt_clear_entry(a1);
  v3 = *(volatile uint32_t *)off_117960;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117964 = 1;
  }
  v5 = (void *)(uintptr_t)(off_117968);
  v6 = (volatile int *)off_117960;
  v7 = *(volatile uint32_t *)off_117968;
  result = *(volatile uint32_t *)off_117968 + 1;
  *(volatile uint32_t *)off_117968 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (volatile int *)off_117964;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_11796C = v4;
  return result;
}



// conn_prepare @ 0x117974
int conn_prepare(int a1) {
  int v1; // r4
  int v2; // r5
  int v3; // r0
  int result; // r0
  int v5; // [sp+4h] [bp-8h]

  v1 = a1 + 1272;
  v2 = 0;
  do
  {
    v3 = (uint8_t)v2;
    v5 = (uint8_t)v2++;
    rf_calib_config(v3, v1, 0);
    result = (int)(uintptr_t)(rf_calib_config(v5, v1 - 40, 0));
    v1 += 8;
  }
  while ( v2 != 5 );
  return result;
}



// conn_tx @ 0x1179a4
int conn_tx(int a1, int a2) {
  volatile char *v4; // r7
  int v5; // r0
  int16_t v6; // r1
  volatile uint32_t *v7; // r3
  int v8; // r3
  volatile uint8_t *v9; // r2
  volatile int *v10; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2
  volatile unsigned int v15; // r2

  if ( a2 == 5 )
    v4 = (volatile char *)dword_117AC8;
  else
    v4 = (volatile char *)off_117AA4 + 84 * a2;
  v5 = dword_117AA8;
  v6 = *(volatile uint16_t *)(a1 + 30);
  v7 = *(volatile uint32_t **)(a1 + 76);
  v7[9] = *(volatile uint8_t *)(a1 + 51) + *(volatile uint8_t *)(a1 + 53) + *(volatile uint16_t *)(a1 + 4) + 4;
  v7[8] = 0;
  v7[13] = 0;
  v7[14] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[3] = v5;
  v7[15] = 0;
  v7[12] = 0;
  v7[17] = 0;
  v7[10] = 0;
  if ( (v6 & 1) == 0 )
    v7[18] = 0;
  v8 = *((volatile uint32_t *)off_117AAC + 8);
  if ( v8 )
  {
    v9 = *(volatile uint8_t **)off_117AB0;
    *(volatile uint32_t *)off_117AB4 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117AC0 + 1320 * *(volatile uint8_t *)(a1 + 28) )
    {
      v15 = (*(volatile uint32_t *)0x40501010u);
      *(volatile uint32_t *)(v8 + 120) = v15;
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117AB8 = 1;
  }
  v10 = (volatile int *)off_117ABC;
  ++*(volatile uint32_t *)off_117ABC;
  llc_rx_llcp_handler(a1, a2);
  check_abort_flag((int)(v4 + 12), (volatile uint32_t *)a1);
  tx_slot_counter_inc(*(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(a1 + 29), 0);
  if ( (*(volatile uint16_t *)(a1 + 30) & 1) == 0 )
    ++*((volatile uint32_t *)off_117AA4 + 126);
  rf_isr_1(a1);
  result = ke_timer_calc(a1, a2, 0);
  v12 = *v10;
  *(volatile uint16_t *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(volatile uint32_t *)off_117AB8;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}


// irq_counter_inc @ 0x117acc
void irq_counter_inc() {
  ++*((volatile uint32_t *)off_117ADC + 126);
}



// conn_rx @ 0x117ae0
/* luna: Handles a received 802.11 frame for a connection/channel, validating RF channel and PHY state, updating RX counters and packet descriptors under IRQ c */
int conn_rx(int a1, int a2) {
  volatile char *rx_conn_state; // r7
  int rf_channel; // r10
  int channel_context_base; // r8
  int pkt_control; // r11
  int rf_channel_context; // r9
  int v10; // r3
  int16_t frame_control_byte; // r1
  int current_rx_pkt; // r6
  int channel_expected_pkt; // r3
  volatile int *rx_irq_counter; // r6
  int llcp_pending; // r2
  char v16; // r3
  int v17; // r1
  volatile uint8_t *v18; // r3
  volatile unsigned int hw_timestamp; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r2
  int v23; // r1
  int16_t v24; // r3
  volatile int *v25; // r3
  int v26; // r3
  int v27; // r2
  int v28; // r3
  int v29; // r2
  volatile uint32_t *rx_pkt_desc; // r3
  int v31; // [sp+4h] [bp-8h]

  if ( a2 == 5 )
    rx_conn_state = (volatile char *)dword_117CCC;
  else
    rx_conn_state = (volatile char *)off_117CC8 + 84 * a2;
  rf_channel = *(volatile uint8_t *)(a1 + 28);
  channel_context_base = dword_117D00;
  pkt_control = *(volatile uint32_t *)(a1 + 76);
  rf_channel_context = dword_117D00 + 1320 * rf_channel;
  if ( init_once(rf_channel_context)
    && ((v10 = *(volatile uint8_t *)(a1 + 28), *(volatile uint8_t *)(channel_context_base + 1320 * v10 + 106))
     || *(volatile uint8_t *)(a1 + 29) > 0x23u
     || *(volatile uint16_t *)(a1 + 4)
     || (frame_control_byte = *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108), (uint8_t)frame_control_byte != 192)
     && (uint8_t)frame_control_byte != 176
     && (frame_control_byte & 0xDF) != 0
     || (current_rx_pkt = *((volatile uint32_t *)off_117CD0 + 10)) == 0
     || *(volatile uint8_t *)(current_rx_pkt + 24) <= 2u
     || (channel_expected_pkt = *(volatile uint32_t *)(channel_context_base + 1320 * v10 + 72)) == 0
     || (v31 = channel_expected_pkt, ke_event_schedule_1("is_on_chan:%d, %x\n", current_rx_pkt == channel_expected_pkt, (uint8_t)frame_control_byte), current_rx_pkt == v31))
    && phy_check_core_mode(a1) )
  {
    *(volatile uint32_t *)(pkt_control + 68) |= 0x100u;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117CD8 = 1;
    }
    rx_irq_counter = (volatile int *)off_117CDC;
    llcp_pending = *((volatile uint32_t *)rx_conn_state + 11);
    v16 = rx_conn_state[80] + 1;
    ++*(volatile uint32_t *)off_117CDC;
    rx_conn_state[80] = v16;
    if ( llcp_pending )
      llc_tx_llcp_handler(a2);
    if ( !*((volatile uint32_t *)rx_conn_state + 5) )
    {
      rx_pkt_desc = *(volatile uint32_t **)(a1 + 72);
      rx_pkt_desc[4] = dword_117CFC;
      rx_pkt_desc[2] = a1;
      rx_pkt_desc[3] = a1;
    }
    check_abort_flag((int)(rx_conn_state + 12), (volatile uint32_t *)a1);
    v17 = *((volatile uint32_t *)off_117CE0 + 8);
    ++*((volatile uint32_t *)off_117CC8 + 126);
    if ( v17 )
    {
      v18 = *(volatile uint8_t **)off_117CE4;
      *(volatile uint32_t *)off_117CE8 = 0x80000000;
      if ( *v18 == 3 && v17 == rf_channel_context )
      {
        hw_timestamp = (*(volatile uint32_t *)0x40501010u);
        *(volatile uint32_t *)(channel_context_base + 1320 * rf_channel + 120) = hw_timestamp;
      }
    }
    if ( **(volatile uint8_t **)off_117CF0 == 2 && (*(volatile uint32_t *)off_117CF4 & dword_117CF8) == 0 )
      log_and_check_hw();
    if ( *rx_irq_counter )
    {
      v20 = *rx_irq_counter - 1;
      v21 = *(volatile uint32_t *)off_117CD8;
      *rx_irq_counter = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117CD8 = 1;
    }
    v22 = *rx_irq_counter;
    v23 = *rx_irq_counter + 1;
    v24 = *(volatile uint16_t *)(a1 + 82) | 1;
    *rx_irq_counter = v23;
    *(volatile uint16_t *)(a1 + 82) = v24;
    if ( v23 )
    {
      v25 = (volatile int *)off_117CD8;
      *rx_irq_counter = v22;
      v26 = *v25;
      if ( !v22 )
      {
        if ( v26 )
          __enable_irq();
      }
    }
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_117CD8 = 1;
    }
    v27 = *(volatile uint32_t *)(a1 + 72);
    ++*rx_irq_counter;
    mac_set_flag(a1, a1, v27, a2);
    if ( *rx_irq_counter )
    {
      v28 = *rx_irq_counter - 1;
      v29 = *(volatile uint32_t *)off_117CD8;
      *rx_irq_counter = v28;
      if ( !v28 )
      {
        if ( v29 )
          __enable_irq();
      }
    }
    return 1;
  }
  else if ( *(volatile uint8_t *)(a1 + 29) == 255 )
  {
    ble_conn_event_handler(a1, 0);
    return 0;
  }
  else
  {
    get_sta_entry(a1, a2);
    return 1;
  }
}


// nullsub_7 @ 0x117d04
int nullsub_7(void) {
  return 0;
}


// rf_irq_status @ 0x117d08
unsigned int rf_irq_status() {
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117D58 & *(volatile uint32_t *)off_117D54;
  if ( (*(volatile uint32_t *)off_117D54 & 0x10) != 0 )
  {
    if ( (*(volatile uint32_t *)off_117D54 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((volatile uint32_t *)off_117D60 + 52) |= 4u;
    }
    ((int (*)())global_flag_set)();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = get_84_entry((uint8_t)(11 - __clz(result)));
  *(volatile uint32_t *)off_117D5C = v0;
  return result;
}



// rf_irq_check_1 @ 0x117d64
int rf_irq_check_1(int result) {
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(volatile uint32_t *)off_117E0C;
  if ( (*(volatile uint32_t *)off_117E0C & 0x1000) != 0 )
  {
    result = ((int (*)())poll_hw_cmd)(result, *(volatile uint32_t *)off_117E0C << 19);
    *(volatile uint32_t *)off_117E20 = 4096;
  }
  v2 = dword_117E10;
  if ( (v1 & dword_117E10) != 0 )
  {
    result = ((int (*)())rf_init_1)();
    *(volatile uint32_t *)off_117E20 = v2;
  }
  if ( (dword_117E14 & v1) != 0 && (*(volatile uint32_t *)off_117E18 & 0x300000) == 0 )
  {
    *(volatile uint32_t *)off_117E28 |= 0x200u;
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_117E1C & v1;
    if ( (dword_117E1C & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(volatile uint32_t *)off_117E20 = 0x80000;
    return conn_schedule(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(volatile int16_t **)off_117E24 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    mmio_irq_clear(dword_117E30, dword_117E2C, 2883);
  }
  *(volatile uint32_t *)off_117E20 = 1 << (v4 + 6);
  return conn_schedule(v4);
}



// rf_irq_clear @ 0x117e34
/* luna: Reads pending RF interrupt status bits, maps the highest set bit to an entry, and writes the pending mask to clear the RF IRQ state. */
int rf_irq_clear() {
  unsigned int pending_rf_irq_bits; // r4
  int result; // r0

  pending_rf_irq_bits = *(volatile uint32_t *)off_117E5C & 0xF00000;
  if ( pending_rf_irq_bits )
  {
    result = get_84_entry((uint8_t)(11 - __clz(pending_rf_irq_bits)));
    *(volatile uint32_t *)off_117E60 = pending_rf_irq_bits;
  }
  else
  {
    *(volatile uint32_t *)off_117E60 = 0;
  }
  return result;
}



// sleep_critical_enter @ 0x117e64
/* luna: Enter a nested sleep-critical section by disabling interrupts if enabled, incrementing a global depth, requesting wake bits for controller contexts, a */
void sleep_critical_enter() {
  volatile int *sleep_depth_ptr; // r9
  volatile uint32_t *v1; // r7
  volatile uint8_t *v2; // r8
  volatile uint32_t *v3; // r5
  volatile uint8_t *v4; // r6
  int i; // r4
  int depth_before; // r3
  int depth_after; // r3
  int irq_disable_saved; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117EE8 = 1;
  }
  sleep_depth_ptr = (volatile int *)off_117EF0;
  v1 = (void *)(uintptr_t)(off_117EEC);
  v2 = (void *)(uintptr_t)(off_117EF4);
  ++*(volatile uint32_t *)off_117EF0;
  v3 = v1;
  v4 = v2;
  for ( i = 4; i != -1; --i )
  {
    if ( !*((volatile uint8_t *)v3 + 158)
      && ((v1[52] & 1) == 0 || *((volatile uint8_t *)v1 + 190) != (uint8_t)i)
      && *((volatile uint32_t *)v4 + 84) )
    {
      mmio_set_bit((uint8_t)i);
    }
    v3 -= 7;
    v4 -= 84;
  }
  depth_before = *sleep_depth_ptr;
  v2[511] = 1;
  if ( depth_before )
  {
    depth_after = depth_before - 1;
    irq_disable_saved = *(volatile uint32_t *)off_117EE8;
    *sleep_depth_ptr = depth_after;
    if ( !depth_after )
    {
      if ( irq_disable_saved )
        __enable_irq();
    }
  }
}



// sleep_critical_exit @ 0x117ef8
int sleep_critical_exit() {
  volatile int *v0; // r7
  volatile uint8_t *v1; // r5
  volatile uint32_t *v2; // r8
  volatile uint32_t *v3; // r11
  int v4; // r10
  volatile int *v5; // r9
  volatile uint32_t *v6; // r6
  int i; // r4
  int v8; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  volatile int *v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117FD8 = 1;
  }
  v0 = (volatile int *)off_117FDC;
  v1 = (void *)(uintptr_t)(off_117FE0);
  v2 = (void *)(uintptr_t)(off_117FEC);
  v3 = (void *)(uintptr_t)(off_117FF0);
  v4 = dword_117FF4;
  v5 = (volatile int *)off_117FF8;
  ++*(volatile uint32_t *)off_117FDC;
  v1[511] = 0;
  v6 = v2;
  for ( i = 4; i != -1; --i )
  {
    v8 = (uint8_t)i;
    if ( !*((volatile uint8_t *)v6 + 158) && ((v2[52] & 1) == 0 || *((volatile uint8_t *)v2 + 190) != (uint8_t)i) )
    {
      if ( *((volatile uint32_t *)v1 + 84) )
      {
        switch_rf_path((uint8_t)i);
        *(volatile uint32_t *)(dword_117FE4 + 4 * i) = *v3 + *(volatile uint32_t *)(v4 + 4 * i);
        *(volatile uint32_t *)off_117FE8 = 1 << i;
        v8 = (uint8_t)i;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_117FD8 = 1;
        }
        v9 = *v0;
        v10 = *v0 + 1;
        v11 = (1 << i) | *v5;
        *v0 = v10;
        *v5 = v11;
        if ( v10 )
        {
          v12 = (volatile int *)off_117FD8;
          *v0 = v9;
          v13 = *v12;
          if ( !v9 )
          {
            if ( v13 )
              __enable_irq();
          }
        }
      }
      ke_int_disable(v8);
    }
    v6 -= 7;
    v1 -= 84;
  }
  if ( *v0 )
  {
    v14 = *v0 - 1;
    v15 = *(volatile uint32_t *)off_117FD8;
    *v0 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return set_system_flag_1(512);
}



// controller_init @ 0x117ffc
uint64_t controller_init() {
  volatile uint8_t *v0; // r8
  int v1; // r10
  volatile char *v2; // r5
  volatile uint8_t *v3; // r4
  int v4; // r9
  volatile uint32_t *v5; // r7
  int v6; // r6
  unsigned int v7; // r11
  int v8; // r9
  volatile uint32_t *v9; // r0
  uint16_t v10; // r7
  volatile uint32_t *v11; // r0
  int i; // r6
  volatile uint32_t *v13; // r0
  int v14; // r2
  uint64_t result; // r0
  volatile uint32_t *v16; // r3
  uint8_t v17[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = (void *)(uintptr_t)(off_1180FC);
  v1 = dword_118100;
  set_system_flag_2(126976);
  v2 = v0 + 12;
  v3 = v17;
  v0[510] = 1;
  v4 = (int)(v0 + 12);
  v5 = (void *)(v17);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6;
    zero_struct(v5);
    rf_calib_config((uint8_t)v6++, v1, (int)v5);
    rf_calib_config(v7, v4, (int)v5);
    v1 += 8;
    v5 += 2;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_1180F4;
  rf_tx_freq_set(5, dword_1180F4);
  llc_tx_process();
  v9 = (void *)(uintptr_t)(llm_env_init());
  mac_process_queue((int)v9);
  v10 = *((volatile uint16_t *)v0 + 254);
  memset((volatile int *)(v8 - 432), 0, 0x204u);
  *((volatile uint16_t *)v0 + 254) = v10;
  do
  {
    zero_struct((void *)(v2));
    *((volatile uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((volatile uint32_t *)v2 + 6) = 0;
    *((volatile uint32_t *)v2 + 7) = 0;
    v11 = (void *)(v2 + 16);
    v2 += 84;
    zero_struct(v11);
  }
  while ( v2 != (volatile char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    v13 = list_pop_front((int)v3);
    if ( v13 )
    {
      do
      {
        mac_reset_tx_queue((int)v13, (uint8_t)i);
        v13 = list_pop_front((int)v3);
      }
      while ( v13 );
      ke_int_disable((uint8_t)i);
    }
    v3 += 8;
  }
  v14 = dword_1180F8;
  result = (unsigned int)(dword_1180F8 + 1152);
  do
  {
    v16 = (volatile uint32_t *)(v14 - 36);
    do
      *v16++ = 0;
    while ( (volatile uint32_t *)v14 != v16 );
    v14 += 36;
  }
  while ( (uint32_t)result != v14 );
  return result;
}


// delay_loop @ 0x118104
int delay_loop(int a1) {
  volatile uint64_t *v1; // r6
  volatile uint64_t *v2; // r7
  int v3; // r2
  volatile uint32_t *v4; // r4
  int result; // r0
  volatile int *v6; // r1
  int v7; // r3
  int v8; // t1
  uint64_t v9; // kr00_8
  uint64_t v10; // r2

  v1 = (void *)(uintptr_t)(off_118148);
  v2 = (void *)(uintptr_t)(off_11814C);
  v3 = a1 - 4;
  v4 = (void *)(uintptr_t)(off_118148);
  result = a1 + 12;
  v6 = (volatile int *)off_11814C;
  do
  {
    v8 = *(volatile uint32_t *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v9 = v2[2];
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(1000 * v9) & 0xFFFFFFFFu);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(1000 * HIDWORD(v9)) << 32);
  v1[2] = v10;
  return result;
}



// timer_ticks_diff @ 0x118150
BOOL timer_ticks_diff(int a1, int a2) {
  unsigned int v2; // r3
  unsigned int v3; // r0

  v2 = *(volatile uint16_t *)(a1 + 32);
  v3 = *(volatile uint16_t *)(a2 + 32);
  if ( v2 > v3 )
    return 0;
  if ( v2 >= v3 )
    return 1;
  return (int)(v3 - v2) <= 63;
}



// timer_check_state @ 0x118170
int timer_check_state(int result, volatile uint32_t *a2) {
  int v2; // r3
  int v3; // r2
  int v4; // r4
  volatile uint8_t *v6; // r6
  volatile uint8_t *v7; // r9
  volatile uint32_t *v8; // r0
  int v9; // r12
  volatile uint32_t *v10; // r7
  unsigned int v11; // r3
  int16_t v12; // lr
  int v13; // r2
  volatile uint32_t *v14; // r1
  int v15; // r3
  volatile int *v16; // r12
  volatile int *v17; // r6
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r6
  struct __attribute__((packed)) { int v23; // [sp+0h] [bp-28h] BYREF
  int v24; // [sp+4h] [bp-24h]
  } _frame;
  v2 = *(volatile uint32_t *)(result + 84);
  if ( v2 < 0 )
  {
    v3 = **(volatile uint8_t **)off_1182EC;
    v4 = result;
    switch ( v3 )
    {
      case 2:
        v6 = (void *)(uintptr_t)(int_disable_set_flag());
        if ( v6 )
        {
          v7 = (void *)(uintptr_t)(off_118318);
          if ( *((volatile uint32_t *)off_118318 + 2057) )
          {
            v8 = list_pop_front(dword_1182F0);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            _frame.v24 = *(volatile uint32_t *)(v4 + 84) & 0x3FFFFFFF;
            _frame.v23 = v9;
            memcpy(v6 + 4, (volatile char *)&_frame.v23, 8u);
            v11 = *((volatile uint16_t *)v7 + 4122);
            if ( v11 > 0x186 )
            {
              v13 = 0;
              v11 = (v11 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
              v12 = 1;
            }
            else
            {
              v12 = v11 + 1;
              v13 = 8 * v11;
            }
            v14 = (void *)(uintptr_t)(off_1182F4);
            *((volatile uint16_t *)v10 + 6) = v11;
            v15 = dword_1182F8;
            v16 = (volatile int *)(*v14 + v13);
            v16[1] = (int)v6;
            *v16 = v15 & *v16 | 0x400000C;
            v15 = (v15 & ~0xFFu) | ((uint8_t)(v7[3074]) & 0xFFu);
            *((volatile uint16_t *)v7 + 4122) = v12;
            v7[3074] = v15 + 1;
            v10[1] = (int)(uintptr_t)(v16);
            *((volatile uint8_t *)v10 + 14) = 1;
            *v10 = 0;
            v10[2] = 12;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(volatile uint32_t *)off_1182FC = 1;
            }
            v17 = (volatile int *)off_118300;
            v18 = *(volatile uint16_t *)(v4 + 32);
            v19 = *a2 & 0xF;
            ++*(volatile uint32_t *)off_118300;
            ke_event_schedule_1("cfms: %x, sn=%d, st=%d\r\n", v4, v18, v19);
            check_abort_flag(dword_118308, v10);
            result = rf_calib_init();
            if ( *v17 )
            {
              v20 = *v17 - 1;
              v21 = *(volatile uint32_t *)off_1182FC;
              *v17 = v20;
              if ( !v20 )
              {
                if ( v21 )
                  __enable_irq();
              }
            }
          }
          else
          {
            return printf_wrapper(aErrTxlCfmNoBuf);
          }
        }
        else
        {
          return printf_wrapper(aErrNoMsgPkt);
        }
        break;
      case 1:
        v22 = *a2 & 0xF;
        _frame.v24 = v2 & 0x3FFFFFFF;
        _frame.v23 = v22;
        ke_mem_alloc(18, (volatile char *)&_frame.v23, 8u);
        return ke_event_schedule_1("cfms: %x, sn=%d, st=%d\r\n", v4, *(volatile uint16_t *)(v4 + 32), *a2 & 0xF);
      case 3:
        *(volatile uint32_t *)((volatile uint32_t *)(uintptr_t)off_11830C)[0] = *a2 & 0xF;
        pmu_ctrl_write_256();
        break;
    }
  }
  return result;
}


// llm_env_init @ 0x11831c
int llm_env_init() {
  int v0; // r4

  v0 = dword_118354;
  memset((volatile int *)dword_118354, 0, 0x28u);
  zero_struct((void *)(uintptr_t)(v0));
  zero_struct((void *)(uintptr_t)(v0 + 8));
  zero_struct((void *)(uintptr_t)(v0 + 16));
  zero_struct((void *)(uintptr_t)(v0 + 24));
  return (int)(uintptr_t)(zero_struct((void *)(uintptr_t)(v0 + 32)));
}



// list_append @ 0x118358
int list_append(volatile uint32_t *a1, int a2, int a3) {
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = a1[19];
  v5 = dword_118384;
  *(volatile uint32_t *)(v3 + 4) = a2;
  result = check_abort_flag(v5 + 8 * a3, a1);
  if ( (a1[9] & 0x200000) == 0 )
    return set_system_flag_1(((volatile uint32_t *)(uintptr_t)off_118388)[a3]);
  return result;
}


