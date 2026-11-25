// mac_update_flags @ 0x116974
int mac_update_flags(int a1, int a2, int a3, int a4) {
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
    if ( **(volatile int16_t **)off_116AF4 >= 0 )
    {
      v10 = *(volatile uint32_t *)(v9 + 28);
      if ( v10 )
      {
LABEL_11:
        if ( a4 == 4 )
        {
          v12 = dword_116AF8 + 1320 * *(volatile uint8_t *)(a2 + 28);
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
            v16 = *((volatile uint16_t *)off_116AFC + 254);
          }
          else
          {
            v16 = *((volatile uint16_t *)off_116AFC + 254) + 1;
            *((volatile uint16_t *)off_116AFC + 254) = v16;
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
              set_mac_addr((void *)(v21));
              v17 = *(volatile uint16_t *)(a2 + 30);
            }
            if ( (v17 & 0x80) != 0 )
            {
              if ( *(volatile uint8_t *)(a2 + 51) )
              {
                get_config_flag(a2, (void *)(uintptr_t)(v10), 24);
              }
              else if ( *(volatile uint8_t *)(a2 + 53) )
              {
                ((int (*)())bt_conn_is_connected)(a2, v10, *(volatile uint16_t *)(a2 + 4));
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
      irq_disable_mmio_write(dword_116B08, dword_116B00, 518);
      v10 = *(volatile uint32_t *)(v9 + 28);
      if ( v10 )
        goto LABEL_11;
      if ( **(volatile int16_t **)off_116AF4 >= 0 )
        goto LABEL_9;
    }
    v11 = *(volatile uint32_t *)(v9 + 24);
    if ( v11 )
      goto LABEL_10;
    irq_disable_mmio_write(dword_116B04, dword_116B00, 525);
LABEL_9:
    v11 = *(volatile uint32_t *)(v9 + 24);
LABEL_10:
    v10 = *(volatile uint32_t *)(v11 + 8);
    goto LABEL_11;
  }
LABEL_3:
  result = tx_pending_check(a2, a4);
LABEL_4:
  if ( (*(volatile uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return phy_set_cfg(*(volatile uint32_t *)(a1 + 76) + 12, *(volatile uint32_t *)(a1 + 76) + 12, a4);
  *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 68) + 8) |= 2u;
  return result;
}



// rx_process_packet @ 0x116b0c
int rx_process_packet(int a1, int a2, char a3) {
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
      v16 = *(volatile uint32_t *)(dword_116CF4 + 696 * *(volatile uint8_t *)(a1 + 29) + 340);
      if ( **(volatile int16_t **)off_116CF0 >= 0 || v16 )
      {
        v17 = v5;
      }
      else
      {
        v29 = v12;
        irq_disable_mmio_write((int)aRcSsNull, (int)aRcGetStaStats, 475);
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
  rx_packet_process_1(a1, a2);
  if ( *(volatile uint16_t *)(a1 + 24) == 36488 )
    alloc_tx_event("txl :%x, len=%d\r\n", 36488, *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 76) + 36));
  v8 = *(volatile uint32_t *)(a1 + 8);
  v9 = *(volatile uint32_t *)(a1 + 72);
  if ( v8 >= 0 || (v20 = *(volatile uint16_t *)(a1 + 24), *(volatile uint32_t *)(a1 + 84) = v8, v20 != 36488) )
  {
    if ( hci_cmd_handler(6u) == 6 )
      goto LABEL_24;
LABEL_7:
    v10 = *(volatile uint32_t **)(a1 + 72);
    goto LABEL_8;
  }
  *(volatile uint32_t *)(v9 + 60) = *(volatile uint32_t *)(v9 + 60) & 0xFFFF00FF | 0xE00;
  if ( hci_cmd_handler(6u) != 6 )
    goto LABEL_7;
LABEL_24:
  v21 = (volatile int16_t **)off_116CF0;
  v22 = *(volatile uint32_t *)(a1 + 76);
  if ( **(volatile int16_t **)off_116CF0 >= 0 )
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
    irq_disable_mmio_write((int)aTxlBufferGetTx, (int)aTxlBufferMachd, 518);
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
    irq_disable_mmio_write((int)aThdFirstPbdPtr, (int)aTxlBufferMachd, 525);
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
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_116CE8)[90]) && (*(volatile uint16_t *)(a1 + 30) & 8) == 0 && (*(volatile uint32_t *)(a1 + 8) & 0x40000000) == 0 )
    *(volatile uint8_t *)(v9 + 61) = ((volatile uint32_t *)(uintptr_t)off_116CE8)[90];
  v10[4] = dword_116CEC;
  v10[2] = a1;
  v10[3] = a1;
  mac_update_flags(a1, a1, (int)v10, a2);
  return 0;
}


// rx_packet_ready @ 0x116d10
int rx_packet_ready(int result) {
  int v1; // r4

  if ( *(volatile uint16_t *)(result + 4) )
  {
    v1 = result;
    result = *(volatile uint32_t *)(result + 72);
    if ( result )
    {
      if ( (*(volatile uint32_t *)(v1 + 36) & 0x200000) == 0 )
      {
        result = wait_for_state((volatile uint32_t *)result);
        *(volatile uint32_t *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}



// size_to_class @ 0x116d30
int size_to_class(unsigned int a1) {
  if ( a1 > 0x2000 )
    return 4;
  else
    return 2;
}



// system_init_seq @ 0x116d3c
int system_init_seq() {
  int v0; // r0
  int v1; // r0
  volatile char *v2; // r5
  volatile char *v3; // r6
  volatile char *v4; // r0
  volatile uint32_t *v5; // r5
  int result; // r0

  compare_global_counters();
  rssi_sample();
  v0 = patch_enable();
  init_mac_global_0x188290(v0);
  v1 = verify_header_magic(0);
  wifi_core_init(v1);
  v2 = (volatile char *)off_116DB8 + 12;
  memset((volatile int *)off_116DB8, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    clear_stats_buf((void *)(v2));
    *((volatile uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((volatile uint32_t *)v2 + 6) = 0;
    *((volatile uint32_t *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    clear_stats_buf((void *)(v4));
  }
  while ( v2 != v3 );
  v5 = (void *)(uintptr_t)(off_116DB8);
  clear_stats_buf((void *)((volatile char *)off_116DB8 + 432));
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((volatile uint8_t *)v5 + 446) = 0;
  *((volatile uint8_t *)v5 + 500) = 0;
  result = (int)(uintptr_t)(clear_stats_buf(v5 + 112));
  *((volatile uint16_t *)v5 + 254) = 0;
  return result;
}



// phy_lock @ 0x116dbc
BOOL phy_lock(int a1) {
  if ( *((volatile uint8_t *)off_116DF0 + 510) )
    return 0;
if ( !((int (*)())cfm_call_ops)() ) return 0;
  if ( *(volatile uint8_t *)(a1 + 1224) )
    return bt_get_conn_channel(*(volatile uint8_t *)(a1 + 1225)) != 0;
  return 1;
}



// mmio_modify_bit @ 0x116df4
int mmio_modify_bit(int result) {
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

  v1 = *(volatile uint32_t *)off_116F0C;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_116F10 = 1;
  }
  v3 = (void *)(uintptr_t)(off_116F14);
  v4 = (volatile int *)off_116F0C;
  v5 = *(volatile uint32_t *)off_116F14;
  v6 = *(volatile uint32_t *)off_116F14 + 1;
  *(volatile uint32_t *)off_116F14 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (volatile int *)off_116F10;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_116F18 = v2;
  switch ( result )
  {
    case 0:
      v10 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x10000;
      break;
    case 1:
      v11 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x20000;
      while ( (*v11 & 0x300) != 0 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x20000;
      break;
    case 2:
      v13 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x40000;
      while ( (*v13 & 0x3000) != 0 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x40000;
      break;
    case 3:
      v12 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x80000;
      while ( (*v12 & 0x30000) != 0 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x80000;
      break;
    case 4:
      v14 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x8000;
      while ( *v14 << 30 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x8000;
      break;
    case 5:
      v9 = (void *)(uintptr_t)(off_116F20);
      *(volatile uint32_t *)off_116F1C = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(volatile uint32_t *)off_116F24 = 0x200000;
      break;
    default:
      if ( **(volatile int16_t **)off_116F28 < 0 )
        result = irq_disable_mmio_write(dword_116F30, dword_116F2C, 2338);
      break;
  }
  return result;
}



