// mac_set_flag @ 0x116ef4
int mac_set_flag(int a1, int a2, int a3, int a4) {
  int v5; // r6
  int result; // r0
  int v9; // r8
  int v10; // r6
  int v11; // r3
  int v12; // r3
  char v13; // r2
  char v14; // r2
  int16_t v15; // r3
  int16_t v16; // r2
  int16_t v17; // r1
  char v18; // r3
  char v19; // r3
  char v20; // r3
  uint8_t v21[8]; // [sp+0h] [bp-8h] BYREF

  v5 = *(volatile uint16_t *)(a2 + 4);
  result = *(volatile uint16_t *)(a1 + 82) | 4;
  *(volatile uint16_t *)(a1 + 82) = result;
  if ( !v5 )
    goto LABEL_4;
  if ( (*(volatile uint32_t *)(a2 + 36) & 0x200000) == 0 )
  {
    v9 = *(volatile uint32_t *)(a2 + 76);
    if ( **(volatile int16_t **)off_117074 >= 0 )
    {
      v10 = *(volatile uint32_t *)(v9 + 28);
      if ( v10 )
      {
LABEL_11:
        if ( a4 == 4 )
        {
          v12 = dword_117078 + 1320 * *(volatile uint8_t *)(a2 + 28);
          v13 = *(volatile uint8_t *)(v12 + 230);
          if ( (*(volatile uint16_t *)v10 & 0x2000) != 0 )
            v14 = v13 | 2;
          else
            v14 = v13 & 0xFD;
          *(volatile uint8_t *)(v12 + 230) = v14;
        }
        if ( *(volatile uint8_t *)(a2 + 27) == 255 )
        {
          v15 = *(volatile uint8_t *)(v10 + 22) & 0xF;
          if ( (*(volatile uint8_t *)(v10 + 22) & 0xF) != 0 )
          {
            v16 = *((volatile uint16_t *)off_11707C + 254);
          }
          else
          {
            v16 = *((volatile uint16_t *)off_11707C + 254) + 1;
            *((volatile uint16_t *)off_11707C + 254) = v16;
          }
          v17 = *(volatile uint16_t *)(a2 + 30);
          *(volatile uint16_t *)(v10 + 22) = v15 | (16 * v16);
          if ( (v17 & 8) != 0 )
          {
            if ( (*(volatile uint16_t *)v10 & 0xDC) == 0x10 && !*(volatile uint16_t *)(v10 + 26) )
            {
              *(volatile uint16_t *)(a2 + 30) = v17 | 0x20;
              v18 = *(volatile uint8_t *)(v10 + 5);
              v21[0] = *(volatile uint8_t *)(v10 + 4);
              v21[1] = v18;
              v19 = *(volatile uint8_t *)(v10 + 7);
              v21[2] = *(volatile uint8_t *)(v10 + 6);
              v21[3] = v19;
              v20 = *(volatile uint8_t *)(v10 + 9);
              v21[4] = *(volatile uint8_t *)(v10 + 8);
              v21[5] = v20;
              rf_save_cal_values((void *)(v21));
              v17 = *(volatile uint16_t *)(a2 + 30);
            }
            if ( (v17 & 0x80) != 0 )
            {
              if ( *(volatile uint8_t *)(a2 + 51) )
              {
                mac_rx_process_ack(a2, (void *)(uintptr_t)(v10), 24);
              }
              else if ( *(volatile uint8_t *)(a2 + 53) )
              {
                ((int (*)())bt_check_conn_active)(a2, v10, *(volatile uint16_t *)(a2 + 4), 0);
              }
            }
          }
        }
        goto LABEL_3;
      }
      goto LABEL_9;
    }
    if ( *(volatile uint32_t *)(a2 + 72) )
    {
      v10 = *(volatile uint32_t *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
    }
    else
    {
      mmio_irq_clear(dword_117088, dword_117080, 518);
      v10 = *(volatile uint32_t *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
      if ( **(volatile int16_t **)off_117074 >= 0 )
        goto LABEL_9;
    }
    v11 = *(volatile uint32_t *)(v9 + 24);
    if ( v11 )
      goto LABEL_10;
    mmio_irq_clear(dword_117084, dword_117080, 525);
LABEL_9:
    v11 = *(volatile uint32_t *)(v9 + 24);
LABEL_10:
    v10 = *(volatile uint32_t *)(v11 + 8);
    goto LABEL_11;
  }
LABEL_3:
  result = process_rx_status(a2);
LABEL_4:
  if ( (*(volatile uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return get_bt_param(*(volatile uint32_t *)(a1 + 76) + 12, *(volatile uint32_t *)(a1 + 76) + 12, a4);
  *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 68) + 8) |= 2u;
  return result;
}



// ke_timer_calc @ 0x11708c
int ke_timer_calc(int a1, int a2, char a3) {
  int v4; // r0
  int v5; // r8
  int v8; // r3
  int v9; // r4
  volatile uint32_t *v10; // r2
  volatile int *v12; // r3
  int v13; // r5
  volatile int *v14; // r4
  int v15; // t1
  int v16; // r4
  int v17; // r5
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r2
  volatile int16_t **v21; // r6
  int v22; // r5
  volatile uint16_t *v23; // r3
  int v24; // r3
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r2
  unsigned int v28; // r2
  volatile int *v29; // [sp+4h] [bp-4h]

  v4 = *(volatile uint32_t *)(a1 + 36);
  v5 = *(volatile uint32_t *)(a1 + 72);
  if ( (v4 & 0x200000) == 0 || (v4 & 0x380000) == 0x280000 )
  {
    v12 = *(volatile int **)(a1 + 44);
    v13 = v5 + 40;
    v14 = v12;
    do
    {
      v15 = *v14++;
      *(volatile uint32_t *)(v13 + 4) = v15;
      v13 += 4;
    }
    while ( v14 != v12 + 16 );
    if ( (*(volatile uint16_t *)(a1 + 30) & 0x2000) != 0 )
    {
      v16 = *(volatile uint32_t *)(dword_117274 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
      if ( **(volatile int16_t **)off_117270 >= 0 || v16 )
      {
        v17 = v5;
      }
      else
      {
        v29 = v12;
        mmio_irq_clear((int)aRcSsNull, (int)aRcGetStaStats, 475);
        v17 = *(volatile uint32_t *)(a1 + 72);
        v12 = v29;
      }
      v18 = *(volatile uint32_t *)(v16 + 156);
      *(volatile uint32_t *)(v5 + 68) = v12[5];
      v19 = *(volatile uint32_t *)(v16 + 160);
      *(volatile uint32_t *)(v5 + 84) = v12[9];
      *(volatile uint32_t *)(v5 + 64) = v18;
      *(volatile uint32_t *)(v5 + 80) = v19;
      if ( ((v18 >> 11) & 5) == 5 )
      {
        v25 = v19 & 0xFFFCFFFF;
        if ( (v18 & 0x600) == 0x400 )
          v26 = 0x20000;
        else
          v26 = 0x10000;
        v27 = v25 | v26;
        if ( *(volatile uint8_t *)(v16 + 165) )
          v28 = v27 | 0x40000;
        else
          v28 = v27 & 0xFFFBFFFF;
        *(volatile uint32_t *)(v5 + 80) = v28;
      }
      if ( (v12[15] & 4) == 0 )
        *(volatile uint32_t *)(v5 + 48) &= 0xFFFFFE7F;
      v5 = v17;
    }
  }
  *(volatile uint8_t *)(v5 + 36) = a3;
  build_tx_packet(a1, a2);
  if ( *(volatile uint16_t *)(a1 + 24) == 36488 )
    ke_event_schedule_1("txl :%x, len=%d\r\n", 36488, *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 76) + 36));
  v8 = *(volatile uint32_t *)(a1 + 8);
  v9 = *(volatile uint32_t *)(a1 + 72);
  if ( v8 >= 0 || (v20 = *(volatile uint16_t *)(a1 + 24), *(volatile uint32_t *)(a1 + 84) = v8, v20 != 36488) )
  {
    if ( hci_cmd_send_short(6u) == 6 )
      goto LABEL_24;
LABEL_7:
    v10 = *(volatile uint32_t **)(a1 + 72);
    goto LABEL_8;
  }
  *(volatile uint32_t *)(v9 + 60) = *(volatile uint32_t *)(v9 + 60) & 0xFFFF00FF | 0xE00;
  if ( hci_cmd_send_short(6u) != 6 )
    goto LABEL_7;
LABEL_24:
  v21 = (volatile int16_t **)off_117270;
  v22 = *(volatile uint32_t *)(a1 + 76);
  if ( **(volatile int16_t **)off_117270 >= 0 )
  {
    v23 = *(volatile uint16_t **)(v22 + 28);
    if ( v23 )
    {
LABEL_28:
      v10 = *(volatile uint32_t **)(a1 + 72);
      goto LABEL_29;
    }
    goto LABEL_26;
  }
  v10 = *(volatile uint32_t **)(a1 + 72);
  if ( !v10 )
  {
    mmio_irq_clear((int)aTxlBufferGetTx, (int)aTxlBufferMachd, 518);
    v23 = *(volatile uint16_t **)(v22 + 28);
    if ( v23 )
      goto LABEL_28;
    if ( **v21 >= 0 )
      goto LABEL_26;
    goto LABEL_41;
  }
  v23 = *(volatile uint16_t **)(v22 + 28);
  if ( !v23 )
  {
LABEL_41:
    v24 = *(volatile uint32_t *)(v22 + 24);
    if ( v24 )
      goto LABEL_27;
    mmio_irq_clear((int)aThdFirstPbdPtr, (int)aTxlBufferMachd, 525);
LABEL_26:
    v24 = *(volatile uint32_t *)(v22 + 24);
LABEL_27:
    v23 = *(volatile uint16_t **)(v24 + 8);
    goto LABEL_28;
  }
LABEL_29:
  if ( (*v23 & 0xFC) == 0xB0 )
    *(volatile uint32_t *)(v9 + 60) = *(volatile uint32_t *)(v9 + 60) & 0xFFFF00FF | 0x1400;
LABEL_8:
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_117268)[90]) && (*(volatile uint16_t *)(a1 + 30) & 8) == 0 && (*(volatile uint32_t *)(a1 + 8) & 0x40000000) == 0 )
    *(volatile uint8_t *)(v9 + 61) = ((volatile uint32_t *)(uintptr_t)off_117268)[90];
  v10[4] = dword_11726C;
  v10[2] = a1;
  v10[3] = a1;
  mac_set_flag(a1, a1, (int)v10, a2);
  return 0;
}


// tx_check_ready @ 0x117290
int tx_check_ready(int result) {
  int v1; // r4

  if ( *(volatile uint16_t *)(result + 4) )
  {
    v1 = result;
    result = *(volatile uint32_t *)(result + 72);
    if ( result )
    {
      if ( (*(volatile uint32_t *)(v1 + 36) & 0x200000) == 0 )
      {
        result = memory_pool_free((volatile uint32_t *)result);
        *(volatile uint32_t *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}



// get_chunk_size @ 0x1172b0
int get_chunk_size(unsigned int a1) {
  if ( a1 > 0x2000 )
    return 4;
  else
    return 2;
}



// bt_init @ 0x1172bc
int bt_init() {
  int v0; // r0
  int inited; // r0
  volatile char *v2; // r5
  volatile char *v3; // r6
  volatile char *v4; // r0
  volatile uint32_t *v5; // r5
  int result; // r0

  timer_ticks_compare();
  scan_process_advertisement();
  v0 = hw_init_magic();
  llm_env_init(v0);
  inited = ke_task_init_1(0);
  mac_reset_controller(inited);
  v2 = (volatile char *)off_117338 + 12;
  memset((volatile int *)off_117338, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    zero_struct((void *)(v2));
    *((volatile uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((volatile uint32_t *)v2 + 6) = 0;
    *((volatile uint32_t *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    zero_struct((void *)(v4));
  }
  while ( v2 != v3 );
  v5 = (void *)(uintptr_t)(off_117338);
  zero_struct((void *)((volatile char *)off_117338 + 432));
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((volatile uint8_t *)v5 + 446) = 0;
  *((volatile uint8_t *)v5 + 500) = 0;
  result = (int)(uintptr_t)(zero_struct(v5 + 112));
  *((volatile uint16_t *)v5 + 254) = 0;
  return result;
}



// init_once @ 0x11733c
BOOL init_once(int a1) {
  if ( *((volatile uint8_t *)off_117370 + 510) )
    return 0;
if ( !bt_link_type(a1) ) return 0;
  if ( *(volatile uint8_t *)(a1 + 1224) )
    return rf_channel_offset_get(*(volatile uint8_t *)(a1 + 1225)) != 0;
  return 1;
}



// mmio_set_bit @ 0x117374
int mmio_set_bit(int result) {
  int v1; // r3
  int v2; // r6
  volatile uint32_t *v3; // r2
  volatile int *v4; // r5
  int v5; // r4
  int v6; // r1
  volatile int *v7; // r3
  int v8; // r3
  volatile uint32_t *v9; // r2
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r2
  volatile uint32_t *v12; // r2
  volatile uint32_t *v13; // r2
  volatile uint32_t *v14; // r2

  v1 = *(volatile uint32_t *)off_11748C;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_117490 = 1;
  }
  v3 = (void *)(uintptr_t)(off_117494);
  v4 = (volatile int *)off_11748C;
  v5 = *(volatile uint32_t *)off_117494;
  v6 = *(volatile uint32_t *)off_117494 + 1;
  *(volatile uint32_t *)off_117494 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (volatile int *)off_117490;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_117498 = v2;
  switch ( result )
  {
    case 0:
      v10 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x10000;
      break;
    case 1:
      v11 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x20000;
      while ( (*v11 & 0x300) != 0 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x20000;
      break;
    case 2:
      v13 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x40000;
      while ( (*v13 & 0x3000) != 0 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x40000;
      break;
    case 3:
      v12 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x80000;
      while ( (*v12 & 0x30000) != 0 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x80000;
      break;
    case 4:
      v14 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x8000;
      while ( *v14 << 30 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x8000;
      break;
    case 5:
      v9 = (void *)(uintptr_t)(off_1174A0);
      *(volatile uint32_t *)off_11749C = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(volatile uint32_t *)off_1174A4 = 0x200000;
      break;
    default:
      if ( **(volatile int16_t **)off_1174A8 < 0 )
        result = mmio_irq_clear(dword_1174B0, dword_1174AC, 2338);
      break;
  }
  return result;
}



