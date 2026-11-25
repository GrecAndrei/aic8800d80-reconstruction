// bt_conn_tx_schedule @ 0x11c38c
int bt_conn_tx_schedule(int a1, int a2) {
  volatile int16_t **v2; // r9
  int v3; // r7
  int v4; // r10
  volatile uint32_t *v7; // r6
  int v8; // r11
  int v9; // r8
  int v10; // r3
  int v11; // r5
  int v12; // r2
  int v13; // r5
  char v15; // r0
  volatile int16_t *v16; // r1
  unsigned int v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r1

  v2 = (volatile int16_t **)off_11C53C;
  v3 = dword_11C510;
  v4 = dword_11C538;
  v7 = (volatile uint32_t *)(dword_11C510 + 28 * a2);
  if ( **(volatile int16_t **)off_11C53C < 0 )
  {
    v8 = 8 * a1;
    if ( *(volatile uint32_t *)(dword_11C538 + 224 * a1 + 72)
      && (flash_ctrl_init((int)aVifChanCtxtNul, (int)aChanCtxtLink, 3061), **v2 >= 0) )
    {
      v9 = 8 * a2;
    }
    else
    {
      v9 = 8 * a2;
      if ( *(volatile uint8_t *)(v3 + 28 * a2 + 24) == 255 )
        flash_ctrl_init((int)aCtxtIdxChanCtx, (int)aChanCtxtLink, 3062);
    }
  }
  else
  {
    v8 = 8 * a1;
    v9 = 8 * a2;
  }
  v10 = v3 + 4 * (v9 - a2);
  v11 = v4 + 32 * (v8 - a1);
  v12 = (uint8_t)(*(volatile uint8_t *)(v10 + 25) + 1);
  *(volatile uint32_t *)(v11 + 72) = (int)(uintptr_t)(v7);
  *(volatile uint8_t *)(v11 + 85) = 0;
  *(volatile uint8_t *)(v10 + 25) = v12;
  v13 = off_11C514;
  if ( v12 == 1 )
  {
    v15 = *(volatile uint8_t *)(off_11C514 + 0x5A);
    *(volatile uint8_t *)(v10 + 16) = 1;
    v16 = *v2;
    v17 = (uint8_t)(v15 + 1);
    *(volatile uint8_t *)(v13 + 0x5A) = v17;
    if ( *v16 < 0 && v17 > 2 )
    {
      flash_ctrl_init((int)aChanEnvNbSched_0, (int)aChanCtxtLink, 3082);
      v17 = *(volatile uint8_t *)(v13 + 0x5A);
    }
    if ( v17 == 2 )
    {
      list_init_1((volatile uint32_t *)dword_11C534);
      v19 = dword_11C538;
      v20 = dword_11C538 + 896;
      do
      {
        *(volatile uint8_t *)(v19 + 85) &= ~1u;
        v19 += 224;
      }
      while ( v20 != v19 );
    }
    check_kernel_state(dword_11C528, v7);
    if ( (*(volatile uint8_t *)(v13 + 0x58) & 0xC) != 0 )
    {
      v18 = *(volatile uint32_t *)(v13 + 0x20);
      if ( **v2 < 0 && !v18 )
      {
        flash_ctrl_init((int)aChSwitch, (int)aChanCtxtLink, 3097);
        v18 = 0;
      }
      *(volatile uint32_t *)(v18 + 8) = (int)(uintptr_t)(v7);
      v12 = *(volatile uint8_t *)(v3 + 4 * (v9 - a2) + 25);
    }
    else
    {
      if ( *(volatile uint32_t *)(v13 + 0x2C) )
        *(volatile uint32_t *)(v13 + 0x2C) = (int)(uintptr_t)(v7);
      else
        list_search((int)(uintptr_t)(v7));
      v12 = *(volatile uint8_t *)(v3 + 4 * (v9 - a2) + 25);
    }
  }
  check_interrupt_flag(
    256,
    "chan link:%d,%d,%d,%d\r\n",
    v12,
    a2,
    *(volatile uint8_t *)(v13 + 0x5A),
    *(volatile uint8_t *)(v13 + 0x5B));
  return bt_conn_find_by_ptr((int)v7);
}


// bt_conn_rx_schedule @ 0x11c540
int bt_conn_rx_schedule(int a1) {
  volatile int16_t **v1; // r8
  int v2; // r6
  int v3; // r5
  int v5; // r10
  int v6; // r9
  int v7; // r7
  char v8; // r3
  char v9; // r3
  int v10; // r6
  int v11; // r3
  char v12; // r4
  volatile uint16_t *v14; // r2
  unsigned int v15; // r3
  int v16; // r1
  int v17; // r3
  int v18; // r2
  volatile char *v19; // r1
  int v20; // r3
  int v21; // r1
  int v22; // r3
  volatile uint32_t *v23; // r4
  int v24; // r2
  int v25; // r3

  v1 = (volatile int16_t **)off_11C77C;
  v2 = dword_11C74C;
  v3 = *(volatile uint32_t *)(dword_11C74C + 224 * a1 + 72);
  v5 = 8 * a1;
  if ( **(volatile int16_t **)off_11C77C < 0 && !v3 )
    flash_ctrl_init((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 32 * (v5 - a1);
  v7 = off_11C750;
  check_interrupt_flag(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(volatile uint8_t *)(v3 + 25),
    *(volatile uint8_t *)(off_11C750 + 0x5B),
    *(volatile uint8_t *)(off_11C750 + 0x5A),
    *(volatile uint8_t *)(v6 + 85),
    *(volatile uint8_t *)(v3 + 16));
  check_kernel_state_alt2(v7 + 16, (volatile uint32_t *)(v2 + 224 * a1 + 76));
  v8 = *(volatile uint8_t *)(v6 + 85);
  *(volatile uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = *(volatile uint8_t *)(v7 + 0x5B) - 1;
    *(volatile uint8_t *)(v7 + 0x5B) = v9;
    if ( !v9 && (*(volatile uint8_t *)(v7 + 0x58) & 0x40) != 0 )
    {
      dispatch_event_handler_1(aUnlinkFixUntil);
      rf_register_access(*(volatile uint32_t *)(v7 + 0x50));
    }
  }
  v10 = v2 + 32 * (v5 - a1);
  *(volatile uint8_t *)(v10 + 85) = 0;
  *(volatile uint32_t *)(v10 + 72) = 0;
  v11 = *(volatile uint8_t *)(v3 + 16);
  v12 = *(volatile uint8_t *)(v3 + 25) - 1;
  *(volatile uint8_t *)(v3 + 25) = v12;
  if ( v11 && !v12 )
  {
    check_kernel_state_alt2(dword_11C764, (volatile uint32_t *)v3);
    *(volatile uint8_t *)(v3 + 16) = 0;
    v14 = *v1;
    v15 = (uint8_t)(*(volatile uint8_t *)(v7 + 0x5A) - 1);
    *(volatile uint8_t *)(v7 + 0x5A) = v15;
    if ( *v14 < 0 && v15 > 1 )
    {
      flash_ctrl_init((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v15 = *(volatile uint8_t *)(v7 + 0x5A);
    }
    if ( v15 )
    {
      list_init_1((volatile uint32_t *)dword_11C774);
      v20 = dword_11C74C;
      v21 = dword_11C74C + 896;
      do
      {
        *(volatile uint8_t *)(v20 + 85) &= ~1u;
        v20 += 224;
      }
      while ( v21 != v20 );
      if ( !*(volatile uint32_t *)(v7 + 0x50) )
        rx_buffer_alloc();
    }
    if ( *(volatile uint32_t *)(v7 + 0x28) != v3 )
    {
      if ( *(volatile uint32_t *)(v7 + 0x2C) != v3 )
        return bt_conn_find_by_ptr(v3);
      v16 = *(volatile uint8_t *)(v3 + 24);
      v17 = v16 + 1;
      if ( v16 == 2 )
      {
        if ( *((volatile uint8_t *)off_11C768 + 24) != 255 )
        {
          v17 = 0;
          v18 = 0;
          goto LABEL_41;
        }
        v17 = 1;
      }
      else
      {
        v18 = 8 * v17;
        if ( *((volatile uint8_t *)off_11C768 + 28 * v17 + 24) != 255 )
          goto LABEL_41;
        v17 = v16 + 2;
        if ( v16 == 1 )
          v17 = 0;
      }
      v18 = 8 * v17;
      if ( *((volatile uint8_t *)off_11C768 + 28 * v17 + 24) == 255 )
      {
        v19 = nullptr;
LABEL_22:
        *(volatile uint32_t *)(v7 + 0x2C) = (int)(uintptr_t)(v19);
        dispatch_event_handler_1("unlink replace sw ctxt:%x\n", v19);
        return bt_conn_find_by_ptr(v3);
      }
LABEL_41:
      v19 = (volatile char *)off_11C768 + 4 * (v18 - v17);
      goto LABEL_22;
    }
    v22 = *(volatile uint8_t *)(v7 + 0x5A);
    *(volatile uint32_t *)(v7 + 0x28) = 0;
    if ( !v22 )
      return bt_conn_find_by_ptr(v3);
    v23 = *(volatile uint32_t **)(v7 + 0x2C);
    if ( v23 )
      return bt_conn_find_by_ptr(v3);
    dispatch_event_handler_1(aUnlinkSwChan);
    v24 = *(volatile uint8_t *)(v3 + 24);
    v25 = v24 + 1;
    if ( v24 == 2 )
    {
      if ( *((volatile uint8_t *)off_11C768 + 24) == 255 )
      {
        v25 = 1;
        goto LABEL_35;
      }
      v25 = 0;
    }
    else if ( *((volatile uint8_t *)off_11C768 + 28 * v25 + 24) == 255 )
    {
      v25 = v24 + 2;
      if ( v24 == 1 )
        v25 = 0;
LABEL_35:
      if ( *((volatile uint8_t *)off_11C768 + 28 * v25 + 24) == 255 )
        goto LABEL_36;
    }
    v23 = (volatile uint32_t *)((volatile char *)off_11C768 + 28 * v25);
LABEL_36:
    if ( *(volatile uint32_t *)(v7 + 0x2C) )
      *(volatile uint32_t *)(v7 + 0x2C) = (int)(uintptr_t)(v23);
    else
      list_search((int)(uintptr_t)(v23));
  }
  return bt_conn_find_by_ptr(v3);
}


// tx_slot_get_busy @ 0x11c7dc
volatile int * tx_slot_get_busy(int a1) {
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int v5; // r4
  volatile int *result; // r0
  int v7; // r3

  v1 = dword_11C80C;
  v2 = dword_11C80C + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(volatile uint8_t *)(v2 + 30) )
    ke_exit_critical(dword_11C80C + 32 * a1);
  v5 = v1 + v4;
  result = memset((volatile int *)v2, 0, 0x20u);
  v7 = dword_11C810;
  *(volatile uint32_t *)(v5 + 8) = v2;
  *(volatile uint8_t *)(v5 + 28) = v3;
  *(volatile uint32_t *)(v5 + 4) = v7;
  return result;
}



// init_three_entries @ 0x11c814
volatile int *init_three_entries() {
  tx_slot_get_busy(0);
  tx_slot_get_busy(1);
  tx_slot_get_busy(2);
  return tx_slot_get_busy(3);
}



// tx_slot_ref @ 0x11c834
int tx_slot_ref(int a1, int a2, int a3) {
  int result; // r0

  result = dword_11C84C + 32 * a1;
  if ( a3 )
    ++*(volatile uint32_t *)(result + 20);
  else
    ++*(volatile uint32_t *)(result + 16);
  return result;
}



// ke_timer_register @ 0x11c850
int ke_timer_register(int a1, int a2, int a3, uint16_t a4) {
  int v5; // r4

  v5 = flash_write_byte(2u);
  check_interrupt_flag(4, "%s:%d\r\n", aScanCancelReqH, v5);
  if ( v5 )
    *((volatile uint8_t *)off_11C888 + 11) = 1;
  else
    tx_buf_alloc(1, a4);
  return 0;
}


