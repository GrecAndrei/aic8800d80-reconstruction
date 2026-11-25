// mm_timer_set @ 0x124bfc
/* luna: Updates a timer’s expiration, reorders it in the pending-timer list, and adjusts timer state when it becomes the earliest deadline. */
int mm_timer_set(volatile uint32_t *a1, int a2) {
  volatile int *timer_lock_count_ptr; // r7
  volatile unsigned int *v5; // r2
  int v6; // r3
  volatile uint32_t *timer_list_head_ptr; // r6
  void *v8; // r2
  int result; // r0
  volatile uint32_t *first_timer_entry; // r3
  int v11; // r3
  int v12; // r2
  void *v13; // r2
  volatile unsigned int *v14; // r2
  int v15; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_124CD0 = 1;
  }
  timer_lock_count_ptr = (volatile int *)off_124CD4;
  v5 = (void *)(uintptr_t)(off_124CD8);
  ++*(volatile uint32_t *)off_124CD4;
  v6 = *((volatile uint32_t *)v5 + 4);
  if ( a2 - v6 < 0 )
  {
    alloc_tx_event("timer past: cb=%x, time=%x, curr=%x\r\n", a1[1], a2, v6);
    if ( **(volatile int16_t **)off_124CE8 < 0 )
      irq_disable_mmio_write(off_124CF0, (int)aMmTimerSet, 131);
  }
  timer_list_head_ptr = (volatile uint32_t *)off_124CDC;
  if ( a1 == *(volatile uint32_t **)off_124CDC )
  {
    list_pop(off_124CDC);
    v13 = (void *)(uintptr_t)(off_124CE0);
    a1[3] = a2;
    result = list_foreach((int)timer_list_head_ptr, a1, (int ( *)(volatile uint32_t *, volatile uint32_t *))v13);
    first_timer_entry = (volatile uint32_t *)*timer_list_head_ptr;
    if ( !*timer_list_head_ptr )
    {
      *((volatile uint32_t *)off_124CD8 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  wlan_ioctl_handler_3(off_124CDC, a1);
  v8 = (void *)(uintptr_t)(off_124CE0);
  a1[3] = a2;
  result = list_foreach((int)timer_list_head_ptr, a1, (int ( *)(volatile uint32_t *, volatile uint32_t *))v8);
  first_timer_entry = (volatile uint32_t *)*timer_list_head_ptr;
  if ( a1 == (volatile uint32_t *)*timer_list_head_ptr )
  {
LABEL_14:
    v14 = (void *)(uintptr_t)(off_124CD8);
    v15 = first_timer_entry[3];
    result = 0x40000;
    *((volatile uint32_t *)off_124CD8 + 2) = 0x40000;
    *((volatile uint32_t *)v14 + 12) = v15;
    *((volatile uint32_t *)v14 + 2) = 4;
  }
LABEL_6:
  if ( *timer_lock_count_ptr && (v11 = *timer_lock_count_ptr - 1, v12 = *(volatile uint32_t *)off_124CD0, (*timer_lock_count_ptr = v11) == 0) && v12 )
  {
    __enable_irq();
    if ( (int)(a2 - *((volatile uint32_t *)off_124CD8 + 4)) < 0 )
      return irq_disable_global_2(0x20000000);
  }
  else if ( (int)(a2 - *((volatile uint32_t *)off_124CD8 + 4)) < 0 )
  {
    return irq_disable_global_2(0x20000000);
  }
  return result;
}


// mem_set_util @ 0x124cf4
int mem_set_util(int a1) {
  volatile int *v1; // r4
  void *v2; // r5
  int v3; // zf
  int result; // r0
  int v5; // r3
  int v6; // r2
  volatile uint32_t *v7; // r3
  int v8; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_124D54 = 1;
  }
  v1 = (volatile int *)off_124D58;
  v2 = (void *)(uintptr_t)(off_124D5C);
  v3 = *(volatile uint32_t *)off_124D5C == a1;
  ++*(volatile uint32_t *)off_124D58;
  if ( v3 )
  {
    result = (int)(uintptr_t)(list_pop((int)(uintptr_t)(v2)));
    v7 = (void *)(uintptr_t)(off_124D60);
    if ( *(volatile uint32_t *)v2 )
    {
      v8 = *(volatile uint32_t *)(*(volatile uint32_t *)v2 + 12);
      result = 0x40000;
      *((volatile uint32_t *)off_124D60 + 2) = 0x40000;
      v7[12] = v8;
      v7[2] = 4;
    }
    else
    {
      *((volatile uint32_t *)off_124D60 + 2) = 1024;
    }
  }
  else
  {
    result = wlan_ioctl_handler_3((int)(uintptr_t)(v2), (void *)(uintptr_t)(a1));
  }
  if ( *v1 )
  {
    v5 = *v1 - 1;
    v6 = *(volatile uint32_t *)off_124D54;
    *v1 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// ble_irq_handler @ 0x124d64
int ble_irq_handler() {
  volatile uint32_t *v0; // r7
  volatile int *v1; // r6
  volatile int *v2; // r8
  volatile uint32_t *v3; // r5
  void *v4; // r9
  int result; // r0
  volatile uint32_t *v6; // r4
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r2
  void ( *v11)(uint32_t); // r3
  volatile int *v12; // r3
  int v13; // r3
  volatile int *v14; // r3

  v0 = (void *)(uintptr_t)(off_124E20);
  v1 = (volatile int *)off_124E24;
  v2 = (volatile int *)off_124E38;
  v3 = (void *)(uintptr_t)(off_124E28);
  v4 = (void *)(uintptr_t)(off_124E20);
  while ( 1 )
  {
    irq_disable_global_3(0x20000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    result = *v1;
    v6 = (volatile uint32_t *)*v0;
    v7 = *v1 + 1;
    *v1 = v7;
    if ( !v6 )
      break;
    v8 = v6[3];
    if ( v8 - v3[4] - 50 >= 0 )
    {
      v3[2] = 0x40000;
      v3[12] = v8;
      v3[2] = 4;
      if ( v8 - v3[4] >= 0 )
      {
        if ( !v7 )
          return result;
        v14 = (volatile int *)off_124E38;
        *v1 = result;
        v13 = *v14;
        if ( result )
          return result;
        goto LABEL_17;
      }
    }
    list_pop((int)(uintptr_t)(v4));
    if ( *v1 )
    {
      v9 = *v1 - 1;
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    v11 = (void ( *)(uint32_t))v6[1];
    if ( **(volatile int16_t **)off_124E2C >= 0 || v11 )
    {
      v11(v6[2]);
    }
    else
    {
      irq_disable_mmio_write(dword_124E34, dword_124E30, 246);
      ((void ( *)(uint32_t))v6[1])(v6[2]);
    }
  }
  *((volatile uint32_t *)off_124E28 + 2) = 1024;
  if ( !v7 )
    return result;
  v12 = (volatile int *)off_124E38;
  *v1 = result;
  v13 = *v12;
  if ( result )
    return result;
LABEL_17:
  if ( v13 )
    __enable_irq();
  return result;
}



// get_mmio_state @ 0x124e3c
/* luna: Returns 1 if the given node is present in the global singly linked list, and 0 otherwise. */
int get_mmio_state(volatile uint32_t *a1) {
  volatile uint32_t *current; // r3

  current = *(volatile uint32_t **)off_124E5C;
  if ( !*(volatile uint32_t *)off_124E5C )
    return (int)current;
  if ( current != a1 )
  {
    while ( 1 )
    {
      current = (volatile uint32_t *)*current;
      if ( !current )
        break;
      if ( a1 == current )
        return 1;
    }
    return (int)current;
  }
  return 1;
}



// mac_isr_check @ 0x124e60
/* luna: Handles a station-probe completion, recording the hardware timestamp on success and reporting the station after ten consecutive failures. */
int mac_isr_check(volatile uint8_t *a1, int a2) {
  int failure_count; // r2
  int result; // r0
  unsigned int station_index; // r3
  volatile unsigned int hardware_timestamp; // r2
  volatile uint8_t *failure_report_pdu; // r0
  int failure_report_pdu_address; // r6

  if ( (a2 & 0x800000) != 0 )
  {
    result = alloc_tx_event("%s: sta probe succ\n", aApmProbeStaCfm);
    station_index = (uint8_t)a1[35];
    a1[668] = 0;
    if ( station_index <= 0x23 )
    {
      hardware_timestamp = (*(volatile uint32_t *)0x40501010u);
      *(volatile uint32_t *)(dword_124EF4 + 696 * station_index + 664) = hardware_timestamp;
      return 696;
    }
  }
  else
  {
    failure_count = (uint8_t)(a1[668] + 1);
    a1[668] = failure_count;
    result = alloc_tx_event("%s: sta probe fail:%d\n", aApmProbeStaCfm, failure_count);
    if ( (uint8_t)a1[668] > 9u )
    {
      failure_report_pdu = (volatile uint8_t *)tx_send_pdu(125, 13, 0, 8);
      *failure_report_pdu = a1[35];
      failure_report_pdu[1] = a1[34];
      failure_report_pdu_address = (int)failure_report_pdu;
      a1[668] = 0;
      memcpy(failure_report_pdu + 2, a1 + 38, 6u);
      return (int)rx_process_packet_1(failure_report_pdu_address);
    }
  }
  return result;
}


// bt_config_check @ 0x124efc
int bt_config_check(int a1, int a2) {
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_124F98;
      *(volatile uint32_t *)(dword_124F9C + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_124F98;
      get_channel_entry_info(*(volatile uint8_t *)(dword_124F98 + 1320 * a1 + 1225), dword_124FA8 + 38 * a1);
      break;
    case 1:
      v4 = dword_124F98;
      *(volatile uint32_t *)(dword_124F9C + 20 * a1 + 4) = dword_124FA0 + 20 * a1;
      break;
    default:
      v4 = dword_124F98;
      if ( **(volatile int16_t **)off_124F94 < 0 )
        irq_disable_mmio_write(dword_124FB0, dword_124FAC, 1214);
      break;
  }
  *(volatile uint8_t *)(a1 + dword_124FA4 + 20) = 0;
  return is_state_arg_valid(*(volatile uint8_t *)(v4 + 1320 * a1 + 1225), a2);
}



// rf_chan_table_update @ 0x124fb4
int rf_chan_table_update(int result) {
  int v1; // r9
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r2
  volatile uint8_t *v6; // r3
  int v7; // r4
  volatile uint32_t *v8; // r11
  int v9; // r2
  unsigned int v10; // r5
  int v11; // cc
  int v12; // r6
  volatile uint8_t *v13; // r5
  volatile uint8_t *v14; // lr
  unsigned int v15; // r12
  int v16; // r6
  unsigned int v17; // lr
  int v18; // r7
  int v19; // r8
  int v20; // r5
  unsigned int v21; // r7
  int v22; // r8
  unsigned int v23; // r8
  int v24; // r6
  int v25; // r12
  int v26; // r5
  int16_t v27; // r8
  int v28; // lr
  int v29; // [sp+0h] [bp-Ch]
  int v30; // [sp+4h] [bp-8h]

  v1 = dword_12517C;
  v2 = 696 * (*(volatile uint8_t *)(result + 107) + 32);
  v3 = dword_12517C + v2;
  v4 = dword_12517C + 40 + v2;
  while ( !*(volatile uint32_t *)(v3 + 584) )
  {
    v5 = *(volatile uint32_t *)(v3 + 624);
    v3 += 8;
    if ( v5 )
      break;
    if ( v3 == v4 )
      goto LABEL_5;
  }
  *(volatile uint8_t *)off_125178 = 1;
LABEL_5:
  v6 = (volatile uint8_t *)dword_125164;
  v7 = dword_125168;
  v8 = (void *)(uintptr_t)(off_125180);
  v9 = dword_125164 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[5] && result == v7 + 1320 * v6[2] )
      {
        v10 = v6[3];
        v11 = v10 > 0x23;
        if ( v10 > 0x23 )
        {
          v12 = 0;
        }
        else
        {
          v12 = 696;
          v10 = v1 + 696 * v10;
        }
        if ( !v11 )
          v12 = *(volatile uint32_t *)(v10 + 664);
        v13 = v6 - 32;
        v14 = v6 - 24;
        if ( !*((volatile uint32_t *)v6 + 138) )
        {
          while ( !*((volatile uint32_t *)v13 + 156) )
          {
            if ( v6 == v13 )
            {
              if ( 15000000 - v8[4] + v12 >= 0 )
                goto LABEL_6;
              break;
            }
            v13 = v14;
            v14 += 8;
            if ( *((volatile uint32_t *)v13 + 146) )
              break;
          }
        }
        v15 = *v6;
        v29 = *(volatile uint8_t *)(result + 107);
        v16 = dword_12516C + 252 * v29;
        v17 = v15 >> 3;
        v18 = 1 << (v15 & 7);
        v19 = *(volatile uint8_t *)((v15 >> 3) + v16);
        v30 = v16 + (v15 >> 3);
        v20 = v29;
        if ( (v18 & v19) == 0 )
          break;
      }
LABEL_6:
      v6 += 696;
      if ( (volatile uint8_t *)v9 == v6 )
        return result;
    }
    *(volatile uint8_t *)(v17 + v16) = v18 | v19;
    v21 = *(volatile uint8_t *)(result + 228);
    ++*(volatile uint16_t *)(result + 220);
    if ( v21 > v17 )
    {
      v21 = (v21 & ~0xFFFFu) | ((uint16_t)(v17 & 0x1E) & 0xFFFFu);
      v22 = dword_125170 + 40 * v29;
      v20 = v29;
      *(volatile uint8_t *)(result + 228) = v17 & 0x1E;
      *(volatile uint32_t *)(v22 + 28) = v16 + ((v15 >> 3) & 0x1E);
    }
    v23 = *(volatile uint8_t *)(result + 229);
    v24 = 4 * v20;
    if ( v23 < v17 )
    {
      *(volatile uint8_t *)(result + 229) = v17;
      *(volatile uint32_t *)(dword_125170 + 8 * (v24 + v29) + 32) = v30;
      v23 = (v23 & ~0xFFFFu) | ((uint16_t)(v15 >> 3) & 0xFFFFu);
    }
    v25 = dword_125174 + 8 * v29;
    v26 = dword_125170;
    v27 = v23 + 6 - v21;
    v28 = dword_125170 + 8 * (v24 + v29);
    *(volatile uint16_t *)(result + 218) = v27;
    *(volatile uint8_t *)(v25 + 1) = v27 - 2;
    v6 += 696;
    *(volatile uint8_t *)(v25 + 4) = *(volatile uint8_t *)(result + 228);
    *(volatile uint32_t *)(v28 + 12) = v25 + 4;
    *(volatile uint32_t *)(v28 + 4) = v26 + 40 * v29 + 20;
  }
  while ( (volatile uint8_t *)v9 != v6 );
  return result;
}



// rx_pkt_parse @ 0x125184
int rx_pkt_parse(volatile uint16_t *a1) {
  unsigned int v1; // r2
  int v2; // r3
  int v5; // r0
  unsigned int v6; // r1
  int v7; // r2
  char v8; // r7
  volatile uint8_t *v9; // r6
  char v10; // r12
  int v11; // r5
  int v12; // lr
  int v13; // r2
  unsigned int v14; // r12
  int v15; // r7
  int v16; // r0
  unsigned int v17; // r8
  int v18; // lr
  int16_t v19; // r2
  int v20; // r1
  int16_t v21; // r2
  int v22; // lr
  int v23; // r12
  int v24; // r7
  int v25; // r7
  int v26; // r2
  int v27; // r7
  int v28; // r3
  int16_t v29; // r1
  int16_t v30; // r1
  uint8_t v31; // r8
  int v32; // r2
  int v33; // r7
  int v34; // r7
  volatile uint8_t *v35; // r12
  int v36; // r2
  char v37; // r1
  volatile uint32_t *v38; // r3
  int v39; // r2

  v1 = *a1;
  v2 = *((volatile uint8_t *)a1 + 3);
  if ( *a1 )
  {
    v5 = dword_1253C0 + 252 * v2;
    v6 = (uint8_t)(v1 >> 3);
    v7 = 1 << (v1 & 7);
    v8 = *(volatile uint8_t *)(v6 + v5);
    v9 = (volatile uint8_t *)(v6 + v5);
    v10 = v7;
    v11 = dword_1253C4 + 8 * v2;
    if ( *((volatile uint8_t *)a1 + 2) )
    {
      if ( ((uint8_t)v7 & *(volatile uint8_t *)(v6 + v5)) == 0 )
      {
        v12 = dword_1253BC;
        v13 = dword_1253BC + 1320 * v2;
        *v9 = v10 | v8;
        v14 = *(volatile uint8_t *)(v13 + 228);
        ++*(volatile uint16_t *)(v13 + 220);
        v15 = dword_1253C8;
        if ( v14 > v6 )
        {
          *(volatile uint32_t *)(dword_1253C8 + 40 * v2 + 28) = v5 + (v6 & 0xFE);
          *(volatile uint8_t *)(v13 + 228) = v6 & 0xFE;
        }
        v16 = v12 + 1320 * v2;
        v17 = *(volatile uint8_t *)(v16 + 229);
        if ( v17 < v6 )
        {
          *(volatile uint8_t *)(v16 + 229) = v6;
          v17 = (v17 & ~0xFFFFu) | ((uint16_t)(v6) & 0xFFFFu);
          *(volatile uint32_t *)(v15 + 40 * v2 + 32) = (int)(uintptr_t)(v9);
        }
        v18 = v12 + 1320 * v2;
        v19 = *(volatile uint8_t *)(v18 + 228);
        *(volatile uint8_t *)(v11 + 4) = v19;
        v20 = v15 + 40 * v2;
        v21 = 6 - v19 + v17;
        *(volatile uint32_t *)(v20 + 12) = v11 + 4;
        *(volatile uint32_t *)(v20 + 4) = v20 + 20;
        *(volatile uint16_t *)(v18 + 218) = v21;
        *(volatile uint8_t *)(v11 + 1) = v21 - 2;
      }
    }
    else if ( ((uint8_t)v7 & *(volatile uint8_t *)(v6 + v5)) != 0 )
    {
      v22 = dword_1253BC;
      v23 = dword_1253BC + 1320 * v2;
      *v9 = v8 & ~(uint8_t)v7;
      v24 = (uint16_t)(*(volatile uint16_t *)(v23 + 220) - 1);
      *(volatile uint16_t *)(v23 + 220) = v24;
      if ( v24 )
      {
        v25 = *(volatile uint8_t *)(v23 + 228);
        if ( v25 == (v6 & 0xFE) )
        {
          while ( 1 )
          {
            if ( v25 == 251 )
            {
              v32 = 250;
              v33 = (v33 & ~0xFFu) | ((uint8_t)(-6) & 0xFFu);
              goto LABEL_22;
            }
            v31 = v25 + 1;
            if ( *(volatile uint8_t *)(v25 + v5) )
              break;
            v25 = v31;
            *(volatile uint8_t *)(v23 + 228) = v31;
          }
          v33 = v25 & 0xFE;
          v32 = v33;
LABEL_22:
          *(volatile uint32_t *)(dword_1253C8 + 40 * v2 + 28) = v32 + v5;
          *(volatile uint8_t *)(v22 + 1320 * v2 + 228) = v33;
        }
        v26 = v22 + 1320 * v2;
        v27 = *(volatile uint8_t *)(v26 + 229);
        if ( v27 == v6 )
        {
          while ( 1 )
          {
            if ( !v6 )
            {
              v27 = (v27 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
              goto LABEL_28;
            }
            v34 = (uint8_t)*v9;
            v35 = v9;
            v6 = (uint8_t)(v6 - 1);
            --v9;
            if ( v34 )
              break;
            *(volatile uint8_t *)(v26 + 229) = v6;
          }
          v5 = (int)v35;
          v27 = (v27 & ~0xFFFFu) | ((uint16_t)(*(volatile uint8_t *)(v22 + 1320 * v2 + 229)) & 0xFFFFu);
LABEL_28:
          *(volatile uint32_t *)(dword_1253C8 + 40 * v2 + 32) = v5;
        }
        v28 = v22 + 1320 * v2;
        v29 = *(volatile uint8_t *)(v28 + 228);
        *(volatile uint8_t *)(v11 + 4) = v29;
        v30 = 6 - v29 + v27;
        *(volatile uint16_t *)(v28 + 218) = v30;
        *(volatile uint8_t *)(v11 + 1) = v30 - 2;
      }
      else
      {
        *(volatile uint16_t *)(v23 + 218) = 6;
        *(volatile uint16_t *)(v22 + 1320 * v2 + 228) = 255;
        v36 = dword_1253C8;
        v37 = *(volatile uint8_t *)(v23 + 218);
        *(volatile uint8_t *)(v11 + 4) = 0;
        v38 = (volatile uint32_t *)(v36 + 40 * v2);
        v38[3] = v11 + 5;
        *(volatile uint8_t *)(v11 + 1) = v37 - 2;
        v39 = dword_1253CC + 20 * *((volatile uint8_t *)a1 + 3);
        v38[8] = v5 + *(volatile uint8_t *)(v23 + 229);
        v38[1] = v39;
      }
    }
  }
  else if ( *((volatile uint8_t *)a1 + 2) )
  {
    *(volatile uint8_t *)(dword_1253BC + 1320 * v2 + 230) = 1;
  }
  else
  {
    *(volatile uint8_t *)(dword_1253BC + 1320 * v2 + 230) = 0;
  }
  mac_write_header_word(66, *(a1 - 2), 0);
  return tx_process_jump((int)(uintptr_t)(a1 - 6));
}



// tx_pkt_complete @ 0x1253d0
int tx_pkt_complete(int a1, int a2) {
  volatile uint32_t *v3; // r5
  int v4; // r1
  int v5; // r3
  int v6; // r8
  int v7; // r7
  int v8; // r11
  int v9; // r6
  int v10; // r10
  int v12; // r3
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r6
  int v17; // r11
  uint64_t v18; // r2
  int v19; // r7
  volatile uint32_t *v20; // r1
  int result; // r0

  v3 = *(volatile uint32_t **)(a1 + 192);
  v4 = *(volatile uint16_t *)(a2 + 4);
  v5 = *(volatile uint8_t *)(a2 + 8);
  v6 = v3[7];
  v7 = *(volatile uint16_t *)(a2 + 6);
  v8 = *(volatile uint8_t *)(a1 + 107);
  v9 = dword_12548C;
  v10 = v4 - v5;
  *(volatile uint16_t *)(a1 + 216) = v4 - v5;
  ((int (*)())ble_ll_conn_process)();
  v12 = *(volatile uint16_t *)(a2 + 6);
  v13 = dword_125490;
  v14 = v3[7] + v12 - 1;
  v3[8] = v14;
  v15 = *(volatile uint32_t *)(a1 + 72);
  v16 = v9 + 8 * v8;
  v17 = v13 + 20 * v8;
  v18 = (v18 & ~0xFFFFFFFFull) | ((uint32_t)(v14 + *(volatile uint8_t *)(a2 + 8) + 1) & 0xFFFFFFFFu);
  v18 = (v18 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(~v12 + v10 + v18) << 32);
  *(volatile uint64_t *)(v17 + 8) = v18;
  v19 = v7 + 3;
  *(volatile uint32_t *)(v17 + 16) = 0;
  if ( v15 )
  {
    v20 = (void *)(uintptr_t)(off_125494);
    if ( !*(volatile uint8_t *)(a1 + 1224) && !*(volatile uint8_t *)(v15 + 4) )
      v20 = (void *)(uintptr_t)(off_1254A4);
  }
  else
  {
    v20 = (void *)(uintptr_t)(off_125494);
  }
  result = dword_12549C;
  v20[9] = (uint16_t)(*(volatile uint16_t *)off_125498 << 8) | (uint8_t)*(volatile uint32_t *)off_125498;
  v3[11] = 0;
  v3[12] = (int)(uintptr_t)(v20);
  v3[17] = result;
  v3[6] = dword_1254A0 + 40 * *(volatile uint8_t *)(a1 + 107);
  *(volatile uint8_t *)(a1 + 226) = 1;
  *(volatile uint8_t *)(v16 + 3) = *(volatile uint8_t *)(v6 + v19);
  return result;
}



// tx_path_setup @ 0x1254a8
int tx_path_setup(int a1) {
  int v1; // r8
  volatile uint8_t *v2; // r5
  char v4; // r7
  int v5; // r6
  int v6; // r0
  int v7; // r1
  int16_t v8; // r3
  int v9; // r3
  int v10; // r9
  char v11; // r7
  int v12; // r5
  int v13; // r3
  int v14; // r5
  int v15; // r0
  int v16; // r2
  int v17; // r3
  char v18; // r7
  volatile uint8_t *v19; // r0

  v1 = *(volatile uint32_t *)(a1 + 192);
  v2 = (volatile uint8_t *)(dword_1255E4 + 8 * *(volatile uint8_t *)(a1 + 107));
  v4 = v2[4];
  v5 = a1 + 116;
  v6 = rf_chan_table_update(a1);
  *(volatile uint32_t *)(v1 + 36) = *(volatile uint16_t *)(v6 + 216) + *(volatile uint16_t *)(v6 + 218) + 4;
  if ( *(volatile uint8_t *)(v6 + 1224) )
  {
    v15 = is_channel_entry_valid(*(volatile uint8_t *)(v6 + 1225));
    if ( v15 )
    {
      v16 = dword_1255F0 + 20 * *(volatile uint8_t *)(a1 + 107);
      v17 = *(volatile uint32_t *)(v16 + 8);
      *(volatile uint32_t *)(v1 + 36) += v15;
      *(volatile uint32_t *)(v16 + 12) = v15 + v17 - 1;
    }
  }
  v7 = *(volatile uint32_t *)(v1 + 28);
  v8 = *((volatile uint16_t *)off_1255E8 + 254) + 1;
  *((volatile uint16_t *)off_1255E8 + 254) = v8;
  *(volatile uint16_t *)(v7 + 22) = 16 * v8;
  v9 = *(volatile uint8_t *)(a1 + 227);
  v2[2] = v9;
  v10 = *(volatile uint8_t *)(a1 + 230);
  if ( v9 )
  {
    v10 &= 2u;
    if ( v10 )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
  }
  else
  {
    if ( *(volatile uint8_t *)(a1 + 230) )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
    if ( *(volatile uint8_t *)off_1255EC )
      v11 |= 1u;
    *(volatile uint8_t *)(a1 + 227) = v2[3];
  }
  v2[4] = v11;
  v12 = *(volatile uint8_t *)(a1 + 231);
  --*(volatile uint8_t *)(a1 + 227);
  if ( v12 )
  {
    v13 = *(volatile uint8_t *)(a1 + 232);
    v14 = (uint8_t)(v12 - 1);
    *(volatile uint8_t *)(a1 + 231) = v14;
    if ( v13 )
    {
      *(volatile uint8_t *)(*(volatile uint32_t *)(v1 + 28) + v13) = v14;
      if ( *(volatile uint8_t *)(a1 + 233) )
        *(volatile uint8_t *)(*(volatile uint32_t *)(v1 + 28) + *(volatile uint8_t *)(a1 + 233)) = *(volatile uint8_t *)(a1 + 231);
      v14 = *(volatile uint8_t *)(a1 + 231);
    }
    if ( !v14
      || (v18 = *(volatile uint8_t *)(a1 + 107),
          v19 = (volatile uint8_t *)tx_send_pdu(78, 13, 0, 2),
          *v19 = v18,
          v19[1] = v14,
          rx_process_packet_1((int)(uintptr_t)(v19)),
          !*(volatile uint8_t *)(a1 + 231)) )
    {
      *(volatile uint8_t *)(a1 + 231) = 1;
    }
  }
  get_status_flag_c5(a1, v5);
  return v10;
}



// init_bt_global_0x190310 @ 0x1255f4
int init_bt_global_0x190310() {
  int v0; // r5
  int v1; // r4

  v0 = dword_125630;
  v1 = dword_125634;
  memset((volatile int *)dword_125630, 0, 0x18u);
  clear_stats_buf((void *)(uintptr_t)(v0 + 12));
  init_fixed_packet_header((void *)(uintptr_t)(v1));
  init_fixed_packet_header((void *)(uintptr_t)(v1 + 38));
  init_fixed_packet_header((void *)(uintptr_t)(v1 + 76));
  return (int)(uintptr_t)(init_fixed_packet_header((void *)(uintptr_t)(v1 + 114)));
}



// rf_chan_load @ 0x125638
volatile int * rf_chan_load(int a1) {
  int v1; // r7
  int v2; // r9
  int v4; // r3
  int v5; // r1
  int v6; // r12
  int v7; // r0
  volatile uint8_t *v8; // r2
  int v9; // r8
  volatile int *v10; // r0
  volatile uint32_t *v11; // r6
  int v12; // r3
  volatile int *result; // r0
  volatile int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r1
  volatile uint32_t *v18; // r2
  volatile uint32_t *v19; // r3
  void *v20; // r1

  v1 = dword_125740;
  v2 = dword_12575C;
  zero_struct(
    a1 + 116,
    dword_125738 + 620 * *(volatile uint8_t *)(a1 + 107),
    (volatile uint32_t *)(dword_12573C + 80 * *(volatile uint8_t *)(a1 + 107)),
    (volatile int *)(dword_125744 + (*(volatile uint8_t *)(a1 + 107) << 6)));
  v4 = *(volatile uint8_t *)(a1 + 107);
  v5 = dword_125748;
  v6 = dword_125760;
  v7 = dword_12574C;
  *(volatile uint16_t *)(a1 + 218) = 6;
  v8 = (volatile uint8_t *)(v5 + 8 * v4);
  *(volatile uint16_t *)(a1 + 228) = 255;
  *(volatile uint8_t *)(a1 + 227) = 0;
  *(volatile uint16_t *)(a1 + 220) = 0;
  *(volatile uint8_t *)(a1 + 230) = 0;
  *v8 = 5;
  v8[1] = 4;
  v8[2] = *(volatile uint8_t *)(a1 + 227);
  v8[4] = 0;
  v8[5] = 0;
  v8[3] = 1;
  v9 = 5 * v4;
  v10 = (volatile int *)(v7 + 252 * v4);
  v11 = (volatile uint32_t *)(v6 + 40 * v4);
  v12 = v1 + 20 * v4;
  v11[8] = (int)(uintptr_t)((volatile char *)v10 + *(volatile uint8_t *)(a1 + 229));
  v11[3] = (int)(uintptr_t)(v8 + 5);
  v11[4] = 0;
  *(volatile uint32_t *)(v6 + 8 * v9) = v2;
  v11[2] = (int)(uintptr_t)(v8);
  v11[1] = v12;
  v11[6] = v12;
  v11[5] = v2;
  result = memset(v10, 0, 0xFCu);
  v14 = (volatile int *)(v1 + 4 * v9);
  *v14 = v2;
  v14[1] = 0;
  v14[4] = 0;
  if ( *(volatile uint8_t *)(a1 + 1224) )
  {
    v15 = *(volatile uint8_t *)(a1 + 107);
    result = (volatile int *)dword_125750;
    v16 = 19 * v15;
    v15 *= 5;
    v17 = dword_125754 + 2 * v16;
    v18 = (volatile uint32_t *)(dword_125750 + 4 * v15);
    v18[1] = 0;
    v18[2] = v17;
    result[v15] = v2;
    v18[4] = 0;
  }
  v19 = *(volatile uint32_t **)(a1 + 192);
  v20 = (void *)(uintptr_t)(off_125758);
  v19[11] = 0;
  v19[17] = 0;
  v19[6] = 0;
  *(volatile uint32_t *)(a1 + 204) = (int)(uintptr_t)(v20);
  *(volatile uint32_t *)(a1 + 208) = a1;
  return result;
}



// co_list_push @ 0x125764
int co_list_push(int a1) {
  if ( *((volatile uint32_t *)off_12577C + 1) )
    return co_list_push_back((int)off_12577C + 12, (volatile uint32_t *)(a1 - 12));
  else
    return (int)rx_pkt_parse((volatile uint16_t *)a1);
}


// patch_check_enable @ 0x125780
void patch_check_enable() {
  int v0; // r4
  volatile uint8_t *v1; // r6
  int v2; // r5
  volatile uint32_t *v3; // r2
  int v4; // r7
  volatile uint8_t *v5; // r8
  char v6; // r9
  int v7; // r10
  int v8; // r0
  int v9; // r3

  v0 = *((volatile uint32_t *)off_125888 + 2);
  v1 = (void *)(uintptr_t)(off_12588C);
  if ( **(volatile int16_t **)off_125884 < 0 && *((volatile uint32_t *)off_12588C + 1) )
  {
    irq_disable_mmio_write(dword_125898, dword_125894, 1074);
    v2 = (uint8_t)v1[9];
    if ( v1[9] )
      goto LABEL_20;
  }
  else
  {
    v2 = *((volatile uint8_t *)off_12588C + 9);
    if ( *((volatile uint8_t *)off_12588C + 9) )
    {
LABEL_20:
      v1[8] = 1;
      return;
    }
  }
  v3 = (void *)(uintptr_t)(off_125890);
  v1[8] = v2;
  v4 = 32 * *v3;
  if ( v0 )
  {
    v5 = (void *)(uintptr_t)(off_12589C);
    v6 = v2;
    v7 = 1;
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v0 + 106) != 2
        || !*(volatile uint8_t *)(v0 + 226)
        || !*(volatile uint8_t *)(v0 + 108)
        || *(volatile uint8_t *)(v0 + 225) != *(volatile uint8_t *)(v0 + 224) )
      {
        goto LABEL_6;
      }
      if ( tx_path_setup(v0) )
        ++*v5;
      if ( v7 && (unsigned int)(v4 - 50) > 0xBB6 )
      {
        cfm_ops_get(v0);
LABEL_16:
        *v5 = v6;
        v0 = *(volatile uint32_t *)v0;
        v7 = 0;
        v2 = 1;
        if ( !v0 )
          return;
      }
      else
      {
        if ( v2 )
          goto LABEL_16;
        v7 = cfm_ops_get(v0);
        if ( v7 )
        {
          *(volatile uint8_t *)(v0 + 144) = *(volatile uint8_t *)(v0 + 107);
          *(volatile uint8_t *)(v0 + 145) = -1;
          v8 = sec_check(v0 + 116, 4);
          v9 = *((volatile uint32_t *)v1 + 1);
          if ( v8 )
            *((volatile uint32_t *)v1 + 1) = ++v9;
          if ( v9 == 1 )
            ke_evt_peek();
          v7 = 0;
        }
        else
        {
          *v5 = 0;
        }
LABEL_6:
        v0 = *(volatile uint32_t *)v0;
        if ( !v0 )
          return;
      }
    }
  }
}



// ipc_trace_send @ 0x1258a0
int ipc_trace_send(int a1) {
  volatile int *v1; // r5
  int v2; // r6
  int v4; // r2
  int v5; // r3
  int v6; // r6
  int v7; // r2

  v1 = (volatile int *)off_125900;
  v2 = *(volatile uint32_t *)off_125900;
  mac_write_header_word(64, *(volatile uint16_t *)(*(volatile uint32_t *)off_125900 - 4), 0);
  tx_pkt_complete(a1, *v1);
  v4 = *v1;
  *(volatile uint8_t *)(a1 + 231) = 0;
  v5 = *(volatile uint8_t *)(v4 + 10);
  *(volatile uint8_t *)(a1 + 232) = v5;
  *(volatile uint8_t *)(a1 + 233) = *(volatile uint8_t *)(v4 + 11);
  v6 = v2 - 12;
  if ( v5 )
    *(volatile uint8_t *)(a1 + 231) = *(volatile uint8_t *)(*(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 192) + 28) + v5) + 1;
  v7 = *((volatile uint8_t *)v1 + 8);
  *((volatile uint8_t *)v1 + 9) = 0;
  if ( v7 )
    patch_check_enable();
  *v1 = 0;
  return tx_process_jump(v6);
}



// bt_task_init @ 0x125904
int bt_task_init(int a1) {
  int v2; // r0
  volatile uint8_t *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v2 = *(volatile uint8_t *)(a1 + 9);
  v3 = (void *)(uintptr_t)(off_125950);
  v4 = dword_125954;
  v5 = dword_125948 + 1320 * v2;
  v6 = dword_12594C + 620 * v2;
  v7 = *(volatile uint8_t *)(v5 + 107);
  *((volatile uint8_t *)off_125950 + 9) = 1;
  v3[10] = 0;
  memcpy((void *)(uintptr_t)(v6 + 108), (void *)(uintptr_t)(v4 + (v7 << 9)), *(volatile uint16_t *)(a1 + 4));
  return ipc_trace_send(v5);
}



// ke_event_set @ 0x125958
int ke_event_set(int a1) {
  volatile uint8_t *v1; // r3
  int v2; // r2

  v1 = (void *)(uintptr_t)(off_12596C);
  v2 = *((volatile uint32_t *)off_12596C + 1);
  *(volatile uint32_t *)off_12596C = a1;
  if ( !v2 )
    return bt_task_init(a1);
  v1[10] = 1;
  return a1;
}



