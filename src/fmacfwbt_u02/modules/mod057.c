// llm_reset_cleanup @ 0x134608
volatile uint32_t *llm_reset_cleanup() {
  if ( **(volatile int16_t **)off_13463C >= 0 || !*((volatile uint32_t *)off_134644 + 6) )
    return zero_struct((void *)(uintptr_t)(off_134640));
  mmio_irq_clear(dword_134648, dword_13464C, 132);
  return zero_struct((void *)(uintptr_t)(off_134640));
}



// llm_get_ctrl_flags @ 0x134650
int llm_get_ctrl_flags() {
  volatile uint32_t *v0; // r4
  volatile uint16_t *v1; // r3
  int v2; // r0

  v0 = (void *)(uintptr_t)(off_134688);
  v1 = (void *)(uintptr_t)(off_13468C);
  v2 = *((volatile uint32_t *)off_134688 + 4);
  *((volatile uint8_t *)off_13468C + 13) = 0;
  v1[7] = 0;
  *((volatile uint8_t *)v1 + 3) = 0;
  if ( v2 )
  {
    jump_to_tx_entry((int)(uintptr_t)((volatile char *)(v2 - 12)));
    jump_to_tx_entry((int)(uintptr_t)((volatile char *)(v0[5] - 12)));
  }
  memset((volatile int *)off_134688, 0, 0x2Cu);
  return hci_cmd_send(6u, 0);
}


// ull_scan_event_start @ 0x134690
int ull_scan_event_start(volatile uint32_t *a1, volatile uint32_t *a2) {
  int v2; // r6
  int result; // r0

  v2 = *((volatile uint32_t *)off_1346D8 + 4);
  *a1 = 0;
  *a2 = 0;
  if ( (*(volatile uint8_t *)(v2 + 34) & 1) != 0 )
  {
    result = (int)(uintptr_t)(parse_pdu_data((void *)(uintptr_t)(v2)));
    if ( result )
    {
      *a1 = result + 2;
LABEL_4:
      *a2 = *(volatile uint32_t *)(result + 44);
      return result;
    }
  }
  else
  {
    *a1 = v2 + 34;
    result = ((int (*)())lookup_handle_entry)();
    if ( result )
      goto LABEL_4;
  }
  if ( *(volatile uint16_t *)(v2 + 40) != 0xFFFF )
    *a2 = v2 + 40;
  return result;
}



// wlan_hw_init @ 0x1346dc
int wlan_hw_init(int a1, int a2) {
  volatile int *v4; // r5
  int v5; // r0
  int v6; // r4
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int16_t v15; // r3
  int v16; // r5
  int v17; // r0
  int v18; // r3
  int v19; // r0
  int v20; // r2
  uint32_t v21[2]; // [sp+8h] [bp-8h]

  v4 = *((volatile int **)off_1347D0 + 4);
  v5 = bt_buf_alloc(4096, 4, 6, 376);
  *(volatile uint8_t *)(v5 + 366) = *((volatile uint8_t *)v4 + 61);
  v6 = v5;
  v7 = *v4;
  v8 = v4[1];
  v9 = v4[2];
  v10 = v4[3];
  v4 += 4;
  *(volatile uint32_t *)(v6 + 360) = 0;
  *(volatile uint16_t *)(v6 + 364) = 0;
  *(volatile uint32_t *)(v6 + 252) = v7;
  *(volatile uint32_t *)(v6 + 256) = v8;
  *(volatile uint32_t *)(v6 + 260) = v9;
  *(volatile uint32_t *)(v6 + 264) = v10;
  v11 = v4[1];
  v12 = v4[2];
  v13 = v4[3];
  *(volatile uint32_t *)(v6 + 268) = *v4;
  *(volatile uint32_t *)(v6 + 272) = v11;
  *(volatile uint32_t *)(v6 + 276) = v12;
  *(volatile uint32_t *)(v6 + 280) = v13;
  *(volatile uint8_t *)(v6 + 284) = v4[4];
  *(volatile uint8_t *)(v6 + 368) = 1;
  if ( a1 )
  {
    *(volatile uint32_t *)(v6 + 352) = *(volatile uint32_t *)a1;
    *(volatile uint16_t *)(v6 + 356) = *(volatile uint16_t *)(a1 + 4);
    if ( a2 )
    {
LABEL_3:
      *(volatile uint32_t *)v6 = *(volatile uint32_t *)a2;
      *(volatile uint16_t *)(v6 + 4) = *(volatile uint16_t *)(a2 + 4);
      *(volatile uint8_t *)(v6 + 367) = 1;
      goto LABEL_4;
    }
  }
  else
  {
    v15 = *((volatile uint16_t *)off_1347D4 + 2);
    *(volatile uint32_t *)(v6 + 352) = *(volatile uint32_t *)(uintptr_t)(off_1347D4);
    *(volatile uint16_t *)(v6 + 356) = v15;
    if ( a2 )
      goto LABEL_3;
  }
  v21[0] = off_1347D8;
  v16 = *((volatile uint8_t *)off_1347D8 + 253);
  v17 = *((volatile uint8_t *)off_1347D8 + 252);
  v21[1] = (int)(uintptr_t)((volatile char *)off_1347D8 + 84);
  *(volatile uint8_t *)(v6 + 367) = a2;
  while ( 1 )
  {
    if ( v17 )
    {
      v18 = v21[a2];
      v19 = 6 * (int16_t)v17 + v18;
      do
      {
        if ( (*(volatile uint8_t *)(v18 + 3) & 2) == 0 )
        {
          v20 = *(volatile uint8_t *)(v6 + 367);
          *(volatile uint8_t *)(v6 + 367) = v20 + 1;
          v20 *= 3;
          *(volatile uint32_t *)(v6 + 2 * v20) = *(volatile uint32_t *)v18;
          *(volatile uint16_t *)(v6 + 2 * v20 + 4) = *(volatile uint16_t *)(v18 + 4);
        }
        v18 += 6;
      }
      while ( v18 != v19 );
    }
    if ( a2 )
      break;
    v17 = v16;
    a2 = 1;
  }
LABEL_4:
  hci_evt_send(v6);
  return hci_cmd_send(6u, 1);
}


// rx_security_check @ 0x1347dc
int rx_security_check(int a1, int a2, int a3) {
  volatile uint32_t *v4; // r3
  volatile uint8_t *v7; // r9
  volatile int *v8; // r10
  int v9; // r4
  int16_t v10; // lr
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  int v16; // r2
  int v17; // r3
  int result; // r0
  volatile uint32_t *v19; // r6
  volatile uint32_t *v20; // r4
  unsigned int v21; // r2

  v4 = (void *)(uintptr_t)(off_1348E0);
  if ( !*(volatile uint8_t *)(a2 + 2)
    && *((volatile uint8_t *)off_1348E0 + 1)
    && *(volatile int *)off_1348E4 < 0
    && (*((volatile uint32_t *)off_1348E8 + 75) & 0x80) != 0 )
  {
    if ( *((volatile uint8_t *)off_1348E0 + 14) == 1 )
    {
      v19 = (void *)(uintptr_t)(off_1348F0);
      *(volatile uint32_t *)off_1348EC = dword_1348F4;
      v20 = (void *)(uintptr_t)(off_1348F8);
      *v19 &= 0xFFFFFFF0;
      *v20 &= ~0x80000000;
      v4[1] = a1;
      v4[2] = a2;
      *((volatile uint8_t *)v4 + 12) = a3;
      *((volatile uint8_t *)v4 + 13) = 1;
      *((volatile uint16_t *)v4 + 1) = 257;
      v21 = dword_1348FC;
      v19[35594] = 0;
      patch_aware_dispatch(6155, 6, v21);
      clock_disable();
      return result;
    }
    *((volatile uint8_t *)off_1348E0 + 3) = 0;
  }
  else
  {
    *((volatile uint8_t *)off_1348E0 + 14) = 0;
    *((volatile uint8_t *)v4 + 13) = 0;
    *((volatile uint8_t *)v4 + 3) = 0;
  }
  v7 = (void *)(uintptr_t)(off_134900);
  v8 = *((volatile int **)off_134900 + 4);
  v9 = bt_buf_alloc(4098, 4, 6, 376);
  *(volatile uint32_t *)v9 = *(volatile uint32_t *)a2;
  v10 = *(volatile uint16_t *)(a2 + 4);
  *(volatile uint8_t *)(v9 + 367) = 1;
  v11 = *v8;
  v12 = v8[1];
  v13 = v8[2];
  v14 = v8[3];
  *(volatile uint16_t *)(v9 + 4) = v10;
  *(volatile uint32_t *)(v9 + 252) = v11;
  *(volatile uint32_t *)(v9 + 256) = v12;
  *(volatile uint32_t *)(v9 + 260) = v13;
  *(volatile uint32_t *)(v9 + 264) = v14;
  v15 = v8[5];
  v16 = v8[6];
  v17 = v8[7];
  *(volatile uint32_t *)(v9 + 268) = v8[4];
  *(volatile uint32_t *)(v9 + 272) = v15;
  *(volatile uint32_t *)(v9 + 276) = v16;
  *(volatile uint32_t *)(v9 + 280) = v17;
  *(volatile uint8_t *)(v9 + 284) = v8[8];
  *(volatile uint8_t *)(v9 + 368) = 1;
  *(volatile uint16_t *)(v9 + 364) = 0;
  *(volatile uint32_t *)(v9 + 360) = 0;
  *(volatile uint8_t *)(v9 + 366) = *((volatile uint8_t *)v8 + 61);
  *(volatile uint32_t *)(v9 + 352) = *(volatile uint32_t *)a1;
  *(volatile uint16_t *)(v9 + 356) = *(volatile uint16_t *)(a1 + 4);
  if ( a3 )
    *(volatile uint8_t *)(v9 + 3) |= 1u;
  v7[32] = a3;
  hci_evt_send(v9);
  return hci_cmd_send(6u, 2);
}


// rx_descriptor_reset @ 0x134904
int rx_descriptor_reset() {
  volatile char *v0; // r5
  volatile uint8_t *v1; // r8
  int v2; // r9
  volatile int *v3; // r10
  int v4; // r4
  uint64_t v5; // r2
  int16_t v6; // lr
  int v7; // r0
  int v8; // r1
  uint64_t v9; // r2
  int v10; // r1
  uint64_t v11; // r2

  v0 = (volatile char *)off_1349AC;
  v1 = (void *)(uintptr_t)(off_1349B4);
  v2 = *((volatile uint8_t *)off_1349AC + 12);
  v3 = *((volatile int **)off_1349B4 + 4);
  v4 = bt_buf_alloc(4098, 4, 6, 376);
  ke_event_schedule_1(aTs1);
  irq_lock((volatile char *)0x180B, 6);
  v5 = *(volatile uint64_t *)(v0 + 4);
  v0[14] = 0;
  *(volatile uint32_t *)(v4 + 352) = *(volatile uint32_t *)v5;
  v0 = (void *)(uintptr_t)(((uintptr_t)(v0) & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v5 + 4)) & 0xFFFFu));
  *(volatile uint32_t *)v4 = *(volatile uint32_t *)HIDWORD(v5);
  v6 = *(volatile uint16_t *)(HIDWORD(v5) + 4);
  *(volatile uint8_t *)(v4 + 367) = 1;
  v7 = *v3;
  v8 = v3[1];
  v9 = *((volatile uint64_t *)v3 + 1);
  *(volatile uint16_t *)(v4 + 356) = (uint16_t)v0;
  *(volatile uint16_t *)(v4 + 4) = v6;
  *(volatile uint32_t *)(v4 + 252) = v7;
  *(volatile uint32_t *)(v4 + 256) = v8;
  *(volatile uint64_t *)(v4 + 260) = v9;
  v10 = v3[5];
  v11 = *((volatile uint64_t *)v3 + 3);
  *(volatile uint32_t *)(v4 + 268) = v3[4];
  *(volatile uint32_t *)(v4 + 272) = v10;
  *(volatile uint64_t *)(v4 + 276) = v11;
  *(volatile uint8_t *)(v4 + 284) = v3[8];
  *(volatile uint8_t *)(v4 + 368) = 1;
  *(volatile uint16_t *)(v4 + 364) = 0;
  *(volatile uint32_t *)(v4 + 360) = 0;
  *(volatile uint8_t *)(v4 + 366) = *((volatile uint8_t *)v3 + 61);
  if ( v2 )
    *(volatile uint8_t *)(v4 + 3) |= 1u;
  v1[32] = v2;
  hci_evt_send(v4);
  return hci_cmd_send(6u, 2);
}


// phy_channel_index_lookup @ 0x1349b8
int phy_channel_index_lookup(volatile uint8_t *a1) {
  return find_free_conn(
           (volatile uint8_t *)(dword_1349D4 + 1320 * *(volatile uint8_t *)(*((volatile uint32_t *)off_1349D0 + 4) + 61)),
           a1);
}



// check_hw_ready_status @ 0x1349d8
int check_hw_ready_status() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r4

  v0 = list_pop_front(dword_134A0C);
  v1 = v0;
  if ( **(volatile int16_t **)off_134A10 < 0 && !v0 )
    mmio_irq_clear(dword_134A18, dword_134A14, 766);
  return (int)(uintptr_t)(hci_evt_send((int)(v1 + 3)));
}



// write_hw_mmio_word @ 0x134a1c
int write_hw_mmio_word(int a1) {
  int v1; // lr
  int v3; // r7
  volatile uint8_t *v4; // r6
  int v5; // r0
  volatile unsigned int *v6; // r3
  volatile uint8_t *v7; // r5
  volatile uint8_t *v8; // r0
  volatile uint8_t *v9; // r0
  int v10; // r0
  int v11; // r1
  int v13; // r0

  v3 = v1;
  v4 = (volatile uint8_t *)bt_buf_alloc(5145, 5, 6, 2);
  v5 = bt_buf_alloc(5143, 5, 6, 2);
  v6 = (volatile unsigned int *)off_134B1C;
  v7 = (volatile uint8_t *)v5;
  if ( (*(volatile uint32_t *)off_134B1C & 0x4000000) != 0 )
  {
    *(volatile uint32_t *)off_134B1C &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  *((volatile uint8_t *)off_134B24 + 73) = *(volatile uint8_t *)off_134B20;
  ke_event_schedule_1("delete reources: %x\n", v3);
  llm_reset_cleanup();
  conn_prepare(a1);
  rf_calibrate_1(*(volatile uint8_t *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(volatile uint8_t *)(a1 + 107);
  check_abort_flag(dword_134B2C, (volatile uint32_t *)v4 - 3);
  if ( *(volatile uint8_t *)(a1 + 108) )
  {
    v13 = bt_buf_alloc(30, 0, 6, 4);
    *(volatile uint8_t *)(v13 + 2) = 0;
    *(volatile uint8_t *)(v13 + 3) = *(volatile uint8_t *)(a1 + 107);
    check_abort_flag(dword_134B2C, (volatile uint32_t *)(v13 - 12));
  }
  if ( *(volatile uint8_t *)(a1 + 116) != 255 )
  {
    v8 = (volatile uint8_t *)bt_buf_alloc(12, 0, 6, 1);
    *v8 = *(volatile uint8_t *)(a1 + 116);
    check_abort_flag(dword_134B2C, (volatile uint32_t *)v8 - 3);
  }
  if ( *(volatile uint32_t *)(a1 + 72) )
  {
    v9 = (volatile uint8_t *)bt_buf_alloc(57, 0, 6, 1);
    *v9 = *(volatile uint8_t *)(a1 + 107);
    check_abort_flag(dword_134B2C, (volatile uint32_t *)v9 - 3);
  }
  *v7 = 0;
  v7[1] = *(volatile uint8_t *)(a1 + 107);
  v10 = check_abort_flag(dword_134B2C, (volatile uint32_t *)v7 - 3);
  return check_hw_ready_status(v10, v11);
}


// mac_tx_start @ 0x134b30
int mac_tx_start() {
  volatile uint16_t *v0; // r6
  int v1; // r4
  int v2; // r5
  int16_t v3; // r7
  volatile int *v4; // r3
  int v5; // r1
  unsigned int v6; // r2
  int result; // r0
  volatile uint32_t *v8; // r1
  volatile int *v9; // r2
  volatile uint32_t *v10; // r12
  volatile int *v11; // r0

  v0 = (void *)(uintptr_t)(off_134C6C);
  v1 = *((volatile uint32_t *)off_134C6C + 2);
  state_check_feature(256, aSmDisconnectFi);
  v2 = bt_buf_alloc(6149, 13, 6, 6);
  if ( *((volatile uint8_t *)v0 + 4) )
    v3 = 0;
  else
    v3 = v0[6];
  *(volatile uint8_t *)(v1 + 149) = 0;
  ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)(v1 + 152)));
  v4 = *((volatile int **)off_134C74 + 2);
  if ( !v4 )
  {
LABEL_14:
    hw_reg_write(0);
    goto LABEL_15;
  }
  v5 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !*((volatile uint8_t *)v4 + 106) )
      {
        if ( !*((volatile uint8_t *)v4 + 108) )
          goto LABEL_8;
        ++v5;
        if ( (volatile int *)v1 == v4 )
          goto LABEL_8;
        break;
      }
      if ( (volatile int *)v1 == v4 )
        goto LABEL_8;
      if ( *((volatile uint8_t *)v4 + 108) )
        break;
      v4 = (volatile int *)*v4;
      if ( !v4 )
      {
LABEL_13:
        if ( *(volatile int *)off_134C78 < 0 && v5 == 1 )
        {
          v8 = (void *)(uintptr_t)(off_134C80);
          *((volatile uint8_t *)off_134C7C + 2) = (uint8_t)v4;
          v9 = (volatile int *)off_134C84;
          *v8 |= 0x80000000;
          *v9 = (HIWORD(*v9) << 16) | 0x5DC;
        }
        goto LABEL_14;
      }
    }
    v6 = *((volatile uint16_t *)v4 + 208);
    if ( v6 <= 0x1387 )
      break;
LABEL_8:
    v4 = (volatile int *)*v4;
    if ( !v4 )
      goto LABEL_13;
  }
  if ( *(volatile int *)off_134C78 < 0 && v5 == 1 )
  {
    v10 = (void *)(uintptr_t)(off_134C80);
    *((volatile uint8_t *)off_134C7C + 2) = 0;
    v11 = (volatile int *)off_134C84;
    *v10 |= 0x80000000;
    *v11 = (HIWORD(*v11) << 16) | 0x5DC;
    hw_reg_write(v6 | (*((volatile uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
  else
  {
    hw_reg_write(v6 | (*((volatile uint8_t *)v4 + 413) << 16) | 0x80000000);
  }
LABEL_15:
  bt_coex_control((volatile int *)v1, 0, 0);
  result = write_hw_mmio_word(v1);
  *(volatile uint16_t *)v2 = v3;
  *(volatile uint8_t *)(v2 + 2) = *(volatile uint8_t *)(v1 + 107);
  *(volatile uint8_t *)(v2 + 4) = *((volatile uint8_t *)v0 + 33);
  *(volatile uint32_t *)v0 = v2 - 12;
  return result;
}


// mac_irq_dispatch @ 0x134c88
int mac_irq_dispatch(int a1, int a2) {
  if ( (a2 & 0x810000) == 0x10000 )
    ke_event_schedule_1(aSendDeauthFail);
  return mac_tx_start();
}


