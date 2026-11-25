// rx_queue_init @ 0x11b3a4
int rx_queue_init(int result, int a2, int a3) {
  volatile uint8_t *v3; // r6
  int v4; // r4
  int v6; // r3
  int v7; // zf
  int v8; // r3
  volatile uint16_t *v9; // r8
  volatile uint16_t *v10; // r0
  volatile uint16_t *v11; // r7
  int v12; // r0
  int v13; // r2
  volatile unsigned int *v14; // r12
  volatile uint32_t *v15; // r1
  char v16; // r3
  volatile uint32_t *v17; // r7
  int v18; // r2
  unsigned int v19; // r3

  v3 = (void *)(uintptr_t)(off_11B4C0);
  v4 = result;
  *((volatile uint32_t *)off_11B4C0 + 10) = 0;
  if ( a2 )
  {
    v6 = *(volatile uint8_t *)(result + 24);
    if ( v6 != 3 )
      goto LABEL_3;
  }
  else
  {
    result = rf_state_process(result, 0, a3);
    v6 = *(volatile uint8_t *)(v4 + 24);
    if ( v6 != 3 )
    {
LABEL_3:
      v7 = v6 == 4;
      v8 = (uint8_t)v3[88];
      if ( v7 )
      {
        v3[88] = v8 & 0xFB;
        if ( *(volatile uint16_t *)(v4 + 14) )
        {
          result = send_hci_event_1(v4);
          v8 = (uint8_t)v3[88];
        }
        else
        {
          v8 &= 0xDBu;
        }
      }
      goto LABEL_4;
    }
  }
  v3[88] &= ~8u;
  v9 = (volatile uint16_t *)rf_get_tx_entry();
  v10 = (volatile uint16_t *)ke_msg_send_1(79, 4, 0, 12);
  *v10 = *v9;
  v11 = v10;
  v12 = rf_get_tx_power((int)(uintptr_t)(v9));
  v13 = dword_11B4C4;
  v14 = (volatile unsigned int *)off_11B4E4;
  v15 = (void *)(uintptr_t)(off_11B4C8);
  *((volatile uint32_t *)v11 + 1) = (unsigned int)(((unsigned int)dword_11B4C4 * (uint64_t)(unsigned int)v12) >> 32) >> 6;
  *((volatile uint32_t *)v11 + 2) = (unsigned int)(((unsigned int)v13 * (uint64_t)*v14) >> 32) >> 6;
  *((volatile uint8_t *)v11 + 2) = 0;
  v16 = 10;
  while ( 1 )
  {
    --v16;
    if ( (uint8_t)*v15 )
      break;
    if ( !v16 )
      goto LABEL_13;
  }
  *((volatile uint8_t *)v11 + 2) = *v15;
LABEL_13:
  rx_irq_handler_1((int)(uintptr_t)(v11));
  v17 = (void *)(uintptr_t)(off_11B4D0);
  v18 = **(volatile int16_t **)off_11B4CC;
  v19 = *((volatile uint32_t *)off_11B4D0 + 1) & 0xFFFFDDFF;
  *((volatile uint32_t *)off_11B4D0 + 1) = v19;
  if ( v18 < 0 && *(volatile uint32_t *)off_11B4D8 << 28 )
  {
    flash_cmd_exec(dword_11B4E0, dword_11B4DC, 472);
    v19 = v17[1];
  }
  *(volatile uint32_t *)off_11B4D4 = v19 | *v17;
  result = ke_evt_handler(142, 2, 255);
  v8 = (uint8_t)v3[88];
LABEL_4:
  *(volatile uint8_t *)(v4 + 24) = -1;
  v3[88] = v8 & 0xEF;
  if ( !(v8 << 30) )
  {
    if ( a2 )
      return result;
    return rf_packet_available();
  }
  result = rf_flag_set();
  if ( !a2 )
    return rf_packet_available();
  return result;
}



// tx_processing @ 0x11b4e8
int tx_processing(volatile uint32_t *a1) {
  volatile int16_t **v1; // r7
  volatile uint8_t *v2; // r6
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r3
  volatile int *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  volatile char *v12; // r0
  int v13; // r0
  int result; // r0
  volatile int *v15; // r5
  int v16; // r1
  volatile unsigned int v17; // r3
  int v18; // r6
  int v19; // r2
  volatile int *v20; // r3
  int v21; // r3
  int v22; // r3
  int v23; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r2
  int v27; // r7
  int v28; // r3
  int v29; // r2

  v1 = (volatile int16_t **)off_11B6A8;
  v2 = (void *)(uintptr_t)(off_11B6AC);
  v4 = list_pop_front(dword_11B6B0);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = (void *)(uintptr_t)(off_11B6B4);
      goto LABEL_4;
    }
LABEL_26:
    v7 = (void *)(uintptr_t)(off_11B6B4);
    v8 = ((volatile uint32_t *)(uintptr_t)off_11B6B4)[10];
    goto LABEL_6;
  }
  if ( a1 == v4 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    flash_ctrl_init((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
      goto LABEL_26;
  }
  v7 = (void *)(uintptr_t)(off_11B6B4);
  v8 = ((volatile uint32_t *)(uintptr_t)off_11B6B4)[10];
  if ( !v8 )
  {
    flash_ctrl_init((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
    v6 = (uint8_t)*v2;
LABEL_4:
    if ( v6 != 1 )
    {
LABEL_5:
      v8 = v7[10];
      goto LABEL_6;
    }
    dispatch_event_handler_1("cb:%x,%x\n", *((volatile uint8_t *)v7 + 88), v7[11]);
    v22 = *((volatile uint8_t *)v7 + 88);
    v23 = v22 << 28;
    if ( (v22 & 8) != 0 )
    {
      v24 = dword_11B6E8;
    }
    else
    {
      if ( (v22 & 4) == 0 )
      {
        v24 = v7[11];
        if ( !v24 )
          goto LABEL_5;
LABEL_33:
        v26 = v7[10];
        if ( v26 )
        {
          v23 = 1;
          *(volatile uint8_t *)(v26 + 16) = 1;
        }
        v7[10] = v24;
        v7[11] = 0;
        v27 = *(volatile uint8_t *)(v24 + 24);
        *(volatile uint8_t *)(v24 + 16) = 4;
        if ( v27 == 3 )
        {
          dispatch_event_handler_1(aCbSetState, v23);
          flash_erase_sector(2u, 3);
        }
        goto LABEL_5;
      }
      v24 = dword_11B6D0;
    }
    v25 = v7[11];
    if ( v25 != v24 && v25 )
    {
      v23 = 1;
      *(volatile uint8_t *)(v25 + 16) = 1;
    }
    goto LABEL_33;
  }
LABEL_6:
  *(volatile uint8_t *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((volatile uint8_t *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      v5[2] = 0;
      goto LABEL_15;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (volatile char *)off_11B6EC;
      if ( *((volatile uint8_t *)off_11B6EC + 24) == 255 )
      {
        if ( *((volatile uint8_t *)off_11B6EC + 52) == 255 )
        {
          if ( *((volatile uint8_t *)off_11B6EC + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_15;
          }
          v12 = (volatile char *)off_11B6EC + 56;
        }
        else
        {
          v12 = (volatile char *)off_11B6EC + 28;
        }
      }
    }
    else
    {
      v12 = *(volatile char **)(dword_11B6B8 + 224 * *(volatile uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = (int)(uintptr_t)(v12);
  }
  else
  {
    v12 = (volatile char *)v5[2];
  }
  if ( v12 )
  {
    if ( v7[11] )
      v7[11] = (int)v12;
    else
      list_search((int)(uintptr_t)(v12));
  }
LABEL_15:
  check_kernel_state(dword_11B6BC, v5);
  v13 = v7[10];
  if ( *(volatile uint8_t *)(v13 + 24) > 2u )
    ((int (*)())rx_queue_init)(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11B6C0 = 1;
    }
    v15 = (volatile int *)off_11B6C8;
    v16 = *(volatile uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(volatile uint32_t *)off_11B6C8;
    v19 = *(volatile uint32_t *)off_11B6C8 + 1;
    *(volatile uint32_t *)off_11B6C8 = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = ke_enter_critical((volatile uint32_t *)dword_11B6D8, v16);
      if ( *v15 )
      {
        v28 = *v15 - 1;
        v29 = *(volatile uint32_t *)off_11B6C0;
        *v15 = v28;
        if ( !v28 )
        {
          if ( v29 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v19 )
      {
        v20 = (volatile int *)off_11B6C0;
        *v15 = v18;
        v21 = *v20;
        if ( !v18 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}


// rf_reg_update_1 @ 0x11b6f0
int rf_reg_update_1() {
  volatile int *v0; // r4
  int v1; // r5
  int result; // r0

  v0 = *((volatile int **)off_11B738 + 2);
  v1 = *((volatile uint32_t *)off_11B73C + 10);
  for ( *(volatile uint32_t *)off_11B734 &= ~4u; v0; v0 = (volatile int *)*v0 )
  {
    while ( v0[18] != v1 || *((volatile uint8_t *)v0 + 94) || !*((volatile uint8_t *)v0 + 96) )
    {
      v0 = (volatile int *)*v0;
      if ( !v0 )
        return result;
    }
    result = rate_index_lookup_fast(
               *((volatile uint8_t *)v0 + 102),
               *((volatile uint8_t *)v0 + 94),
               *((volatile uint8_t *)v0 + 94));
  }
  return result;
}



// tx_schedule @ 0x11b740
int tx_schedule() {
  volatile uint32_t *v0; // r6
  int v1; // r5
  int v2; // r7
  volatile int *v3; // r4
  char v4; // r2
  int v5; // r8
  volatile uint8_t *v6; // r10
  int v7; // r2
  int v8; // r0
  char v9; // r11
  int v10; // r4
  int v11; // r5
  int v12; // r4

  v0 = (void *)(uintptr_t)(off_11B7F8);
  v1 = *((volatile uint32_t *)off_11B7F8 + 10);
  v2 = *((volatile uint8_t *)off_11B7F8 + 89);
  if ( !v1 )
    return 0;
  v3 = *((volatile int **)off_11B800 + 2);
  v4 = *((volatile uint8_t *)off_11B7F8 + 89);
  *(volatile uint32_t *)off_11B7FC |= 4u;
  if ( v3 )
  {
    v5 = dword_11B804;
    v6 = (void *)(uintptr_t)(off_11B808);
    do
    {
      while ( 1 )
      {
        if ( v1 == v3[18] )
        {
          v7 = *((volatile uint8_t *)v3 + 94);
          if ( !*((volatile uint8_t *)v3 + 94) )
          {
            if ( *((volatile uint8_t *)v3 + 96) )
            {
              v8 = *((volatile uint8_t *)v3 + 102);
              if ( v8 != 255 )
                break;
            }
          }
        }
        v3 = (volatile int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      v9 = *(volatile uint8_t *)(v1 + 16);
      *(volatile uint8_t *)(v1 + 16) = 6;
      if ( !rate_index_lookup_fast(v8, v5, v7) )
      {
        ++v2;
        *v6 = 1;
      }
      *(volatile uint8_t *)(v1 + 16) = v9;
      v3 = (volatile int *)*v3;
    }
    while ( v3 );
LABEL_12:
    v4 = v2;
  }
  v10 = *((volatile uint8_t *)v0 + 89);
  v11 = v0[11];
  *((volatile uint8_t *)v0 + 89) = v4;
  v12 = v2 - v10;
  if ( !v11 )
  {
    write_bb_control();
    if ( v2 )
    {
      v12 = 0;
      --*((volatile uint8_t *)v0 + 89);
      return v12;
    }
    return 0;
  }
  if ( !v12 )
    return v12;
  *(volatile uint8_t *)(v11 + 16) = 3;
  write_bb_control();
  return v12;
}



