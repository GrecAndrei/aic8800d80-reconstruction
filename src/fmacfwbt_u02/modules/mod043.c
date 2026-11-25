// bt_link_connected @ 0x12b22c
int bt_link_connected() {
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(volatile uint32_t *)off_12B290;
  v1 = *((volatile uint8_t *)off_12B290 + 10);
  if ( hci_cmd_send_short(2u) != 2 )
  {
    v2 = hci_cmd_send_short(2u);
    ke_event_schedule_1("start st=%d\n", v2);
  }
  if ( **(volatile int16_t **)off_12B298 < 0 && hci_cmd_send_short(2u) != 2 )
    mmio_irq_clear((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(volatile uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    bt_update_conn_state();
  hci_cmd_send(2u, 3);
  return 0;
}


// bt_send_hci_801 @ 0x12b2a4
int bt_send_hci_801(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v6; // r4
  int v7; // r0
  volatile uint8_t *v8; // r2

  v6 = (volatile uint8_t *)bt_buf_alloc(2049, a4, a3, 1);
  v7 = hci_cmd_send_short(2u);
  state_check_feature(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( hci_cmd_send_short(2u) )
  {
    *v6 = 8;
    hci_evt_send((int)v6);
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_12B328 < 0 && !*(volatile uint8_t *)(a2 + 367) )
      mmio_irq_clear((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = (void *)(uintptr_t)(off_12B32C);
    *v6 = 0;
    *(volatile uint32_t *)v8 = a2;
    v8[10] = 0;
    *((volatile uint16_t *)v8 + 4) = a4;
    bt_save_conn_info(a2);
    hci_evt_send((int)v6);
    return 1;
  }
}


// bt_check_vendor_cmd @ 0x12b338
int bt_check_vendor_cmd(volatile uint16_t *a1) {
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B390 + 16);
  if ( v1 == 2412
    || v1 == 2437
    || v1 == 2462
    || v1 == 2472
    || v1 == 5180
    || v1 == 5220
    || v1 == 5765
    || v1 == 5785
    || v1 == 5805 )
  {
    result += 20000;
  }
  return result;
}



// bt_reset_controller @ 0x12b394
int bt_reset_controller() {
  int result; // r0
  volatile uint32_t *v1; // r3

  memset((volatile int *)dword_12B3BC, 0, 0xCu);
  result = hci_cmd_send(2u, 0);
  v1 = (void *)(uintptr_t)(off_12B3C0);
  *(volatile uint32_t *)off_12B3C0 = dword_12B3C4;
  v1[2] = (int)(uintptr_t)(v1 + 5);
  v1[4] = 0;
  v1[1] = 0;
  return result;
}


// bt_get_link_state @ 0x12b3c8
int bt_get_link_state() {
  volatile uint32_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  char v4; // r8
  int v5; // r1
  int v6; // r3
  int v7; // r2
  int v8; // r1
  int v10; // r1

  v0 = (void *)(uintptr_t)(off_12B488);
  v1 = *(volatile uint32_t *)off_12B488;
  v2 = *(volatile uint32_t *)off_12B488 + 6 * *((volatile uint8_t *)off_12B488 + 10);
  v3 = 6 * *((volatile uint8_t *)off_12B488 + 10);
  v4 = *(volatile uint8_t *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B48C + 20);
    if ( !v5 )
    {
      v5 = dword_12B490;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = bt_check_vendor_cmd((volatile uint16_t *)(*(volatile uint32_t *)off_12B488 + 6 * *((volatile uint8_t *)off_12B488 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((volatile uint8_t *)off_12B498 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  acl_send_packet((volatile int16_t *)v2, v5, *(volatile uint8_t *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(volatile uint8_t *)(v2 + 2);
    v8 = *(volatile uint16_t *)(v1 + v3);
    if ( *(volatile uint8_t *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(volatile uint8_t *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B494 * (uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(volatile uint8_t *)(v6 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v8 - 2412) <= 0x48 )
      {
        if ( v8 == 2484 )
        {
          *(volatile uint8_t *)(v6 + 2) = 14;
          return hci_cmd_send(2u, 2);
        }
        v7 = (v7 & ~0xFFu) | ((uint8_t)((unsigned int)(((unsigned int)dword_12B494 * (uint64_t)(unsigned int)(v8 - 2407)) >> 32) >> 2) & 0xFFu);
      }
      *(volatile uint8_t *)(v6 + 2) = v7;
    }
  }
  return hci_cmd_send(2u, 2);
}


// bt_save_conn_info @ 0x12b49c
int bt_save_conn_info(int a1) {
  volatile uint32_t *v1; // r6
  volatile char *v2; // r4
  int result; // r0

  v1 = (void *)(uintptr_t)(off_12B4CC);
  v2 = (volatile char *)off_12B4D0;
  v1[1] = (int)(uintptr_t)(sub_12dd88((void *)(uintptr_t)(off_12B4D0), *(volatile uint16_t *)(*(volatile uint32_t *)off_12B4CC + 364)));
  result = bt_get_link_state();
  *(volatile uint32_t *)&v2[-8] = *(volatile uint32_t *)&v2[-12] - 1 + *(volatile uint16_t *)(a1 + 364);
  *((volatile uint32_t *)v2 - 1) = 0;
  return result;
}



// bt_get_conn_entry @ 0x12b4d4
int bt_get_conn_entry(int a1, int a2, int a3) {
  int v3; // r9
  int v4; // r3
  int v6; // r5
  int v9; // r3
  int v10; // r0
  int result; // r0
  int v12; // r4
  volatile uint16_t *v13; // lr
  int v14; // r1
  uint64_t v15; // kr00_8
  int16_t v16; // r5
  int v17; // r9
  int v18; // r0
  int v19; // r9

  v3 = dword_12B5B4;
  v4 = dword_12B5B4 + 1320 * a1;
  v6 = *(volatile uint8_t *)(v4 + 116);
  if ( *(volatile uint8_t *)(v4 + 1224) )
  {
    result = (int)(uintptr_t)(event_notify(1, 26));
    v12 = result;
    if ( result )
    {
LABEL_5:
      v13 = (void *)(uintptr_t)(off_12B5B8);
      v14 = dword_12B5B0 + 696 * v6;
      v15 = *(volatile uint64_t *)(result + 72);
      v16 = *((volatile uint16_t *)off_12B5B8 + 254);
      *(volatile uint32_t *)(v15 + 112) = *(volatile uint32_t *)(v14 + 38);
      v17 = v3 + 1320 * a1;
      *(volatile uint8_t *)(v15 + 108) = 64;
      *(volatile uint16_t *)(v15 + 116) = *(volatile uint16_t *)(v14 + 42);
      v18 = *(volatile uint32_t *)(v17 + 100);
      v17 = (v17 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v17 + 104)) & 0xFFFFu);
      *(volatile uint32_t *)(v15 + 118) = v18;
      v18 = (v18 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v14 + 42)) & 0xFFFFu);
      *(volatile uint16_t *)(v15 + 122) = v17;
      ++v16;
      v19 = *(volatile uint32_t *)(v14 + 38);
      *(volatile uint16_t *)(v15 + 128) = v18;
      *(volatile uint8_t *)(v15 + 109) = 0;
      *(volatile uint8_t *)(v15 + 110) = 0;
      *(volatile uint8_t *)(v15 + 111) = 0;
      *(volatile uint32_t *)(v15 + 124) = v19;
      v13[254] = v16;
      *(volatile uint8_t *)(v15 + 132) = 0;
      *(volatile uint8_t *)(v15 + 133) = 0;
      *(volatile uint16_t *)(v15 + 130) = 16 * v16;
      *(volatile uint32_t *)(HIDWORD(v15) + 24) = 0;
      *(volatile uint8_t *)(v12 + 28) = a1;
      *(volatile uint8_t *)(v12 + 29) = *(volatile uint8_t *)(v14 + 35);
      *(volatile uint32_t *)(v12 + 88) = a2;
      *(volatile uint32_t *)(v12 + 92) = a3;
      return ble_event_dispatch(v12, 5);
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(v4 + 72);
    v10 = *(volatile uint8_t *)(v9 + 4);
    if ( *(volatile uint8_t *)(v9 + 4) )
      v10 = 1;
    result = (int)(uintptr_t)(event_notify(v10, 26));
    v12 = result;
    if ( result )
      goto LABEL_5;
  }
  return result;
}



// bt_update_conn_state @ 0x12b5bc
void bt_update_conn_state() {
  int v0; // r5
  volatile char *v1; // r6
  int v2; // r7
  int v3; // r0
  int v4; // r0
  volatile char *v5; // r2
  int v6; // r1
  volatile uint16_t *v7; // lr
  int v8; // r3
  int16_t v9; // r4
  volatile int *v10; // r9
  int v11; // r12
  int16_t v12; // r10
  int v13; // r0
  int v14; // r0
  int16_t v15; // r10
  int v16; // r0
  int v17; // r3
  char v18; // t1
  int v19; // r2
  int v20; // r3
  int v21; // [sp+0h] [bp-Ch]
  int v22; // [sp+4h] [bp-8h]

  v0 = *(volatile uint32_t *)off_12B6F4;
  v22 = *((volatile uint8_t *)off_12B6F4 + 10);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_12B6F4 + 368) )
  {
    v21 = dword_12B6F8 + 1320 * *(volatile uint8_t *)(*(volatile uint32_t *)off_12B6F4 + 366);
    v1 = (volatile char *)(v0 + 253);
    v2 = 0;
    do
    {
      if ( *(volatile uint8_t *)(v21 + 1224) || *(volatile uint8_t *)(v0 + 6 * v22 + 2) )
      {
        v3 = 1;
      }
      else
      {
        v3 = *(volatile uint8_t *)(v0 + 369);
        if ( *(volatile uint8_t *)(v0 + 369) )
          v3 = 1;
      }
      v4 = (int)(uintptr_t)(event_notify(v3, *(volatile uint16_t *)(v0 + 364) + (uint8_t)*(v1 - 1) + 26));
      v5 = v1;
      v6 = v4;
      if ( !v4 )
        break;
      v7 = (void *)(uintptr_t)(off_12B700);
      v8 = *(volatile uint32_t *)(v4 + 72);
      v9 = *((volatile uint16_t *)off_12B700 + 254);
      v10 = (volatile int *)off_12B704;
      v11 = *(volatile uint32_t *)(v4 + 76);
      v12 = *((volatile uint16_t *)off_12B704 + 2);
      *(volatile uint32_t *)(v8 + 118) = *(volatile uint32_t *)(v21 + 100);
      v13 = *v10;
      v10 = (void *)(uintptr_t)(((uintptr_t)(v10) & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v21 + 104)) & 0xFFFFu));
      *(volatile uint32_t *)(v8 + 112) = v13;
      ++v9;
      v14 = *(volatile uint32_t *)(v0 + 352);
      *(volatile uint16_t *)(v8 + 116) = v12;
      v15 = *(volatile uint16_t *)(v0 + 356);
      *(volatile uint16_t *)(v8 + 122) = (uint16_t)v10;
      *(volatile uint32_t *)(v8 + 124) = v14;
      *(volatile uint8_t *)(v8 + 108) = 64;
      *(volatile uint16_t *)(v8 + 128) = v15;
      *(volatile uint8_t *)(v8 + 109) = 0;
      *(volatile uint8_t *)(v8 + 110) = 0;
      *(volatile uint8_t *)(v8 + 111) = 0;
      v7[254] = v9;
      *(volatile uint8_t *)(v8 + 132) = 0;
      *(volatile uint8_t *)(v8 + 133) = *(v1 - 1);
      v16 = (uint8_t)*(v1 - 1);
      *(volatile uint16_t *)(v8 + 130) = 16 * v9;
      if ( v16 )
      {
        v17 = v8 + 133;
        do
        {
          v18 = *v5++;
          *(volatile uint8_t *)++v17 = v18;
        }
        while ( v5 != &v1[v16] );
      }
      v19 = *(volatile uint16_t *)(v0 + 364);
      v20 = *(volatile uint32_t *)(v11 + 32);
      *(volatile uint32_t *)(v11 + 24) = dword_12B6FC;
      *(volatile uint32_t *)(v11 + 32) = v20 - v19;
      *(volatile uint32_t *)(v6 + 88) = 0;
      *(volatile uint32_t *)(v6 + 92) = 0;
      *(volatile uint8_t *)(v6 + 28) = *(volatile uint8_t *)(v0 + 366);
      *(volatile uint8_t *)(v6 + 29) = -1;
      ble_event_dispatch(v6, 5);
      ++v2;
      v1 += 33;
    }
    while ( *(volatile uint8_t *)(v0 + 368) > v2 );
  }
}



// bt_send_hci_804 @ 0x12b708
volatile uint32_t * bt_send_hci_804(char a1, uint16_t a2) {
  volatile char *v3; // r4

  v3 = (volatile char *)bt_buf_alloc(2052, a2, 2, 1);
  state_check_feature(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return hci_evt_send((int)v3);
}


// bt_get_active_conn @ 0x12b738
int bt_get_active_conn() {
  return *(volatile uint32_t *)off_12B748 + 6 * *((volatile uint8_t *)off_12B748 + 10);
}



// get_bt_status @ 0x12b74c
int get_bt_status(int a1) {
  if ( (*(volatile uint8_t *)(a1 + 3) & 5) != 0 )
    return *(volatile uint32_t *)(*(volatile uint32_t *)off_12B760 + 20);
  else
    return bt_check_vendor_cmd((volatile uint16_t *)a1);
}



// rf_read_irq_status @ 0x12b764
int rf_read_irq_status() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(volatile int16_t **)off_12B7AC < 0 && *(volatile uint32_t *)off_12B7B8 << 28 )
    return ke_int_lock_1((int)aNxmacCurrentSt, (int)aHalMachwIdleIr, 105);
  if ( (*(volatile uint32_t *)off_12B7B0 & 0x80) != 0 )
  {
    v0 = (void *)(uintptr_t)(off_12B7B4);
    v1 = *((volatile uint32_t *)off_12B7B4 + 1) & 0xFFFFFFFB;
    *(volatile uint32_t *)off_12B7B0 &= ~0x80u;
    v0[1] = v1;
    return set_system_flag_1(0x2000000);
  }
  return result;
}


// rf_wait_event @ 0x12b7c8
unsigned int rf_wait_event(unsigned int result) {
  volatile unsigned int *v1; // r6
  unsigned int v2; // r5
  int v3; // r2
  int v4; // r7
  int v5; // r8
  unsigned int v6; // r4
  uint64_t v7; // r0
  uint64_t v8; // r0
  unsigned int v9; // r0
  uint64_t v10; // r0
  uint64_t v11; // r0
  volatile unsigned int *v12; // r2
  unsigned int v13; // r3
  int v14; // r3
  volatile uint32_t *v15; // r6
  int v16; // r2
  int v17; // r0
  volatile unsigned int *v18; // r1
  volatile unsigned int *v19; // r2
  int v20; // r1
  uint64_t v21; // r0
  unsigned int v22; // r0
  uint64_t v23; // r0
  volatile unsigned int *v24; // r7
  uint64_t v25; // r0

  v1 = (volatile unsigned int *)off_12B9F0;
  v2 = (uint8_t)*(volatile uint32_t *)off_12B9F0;
  if ( result != v2 )
  {
    v3 = dword_12B9F4;
    v4 = dword_12B9F8;
    v5 = dword_12BA28;
    *(volatile uint32_t *)off_12BA24 = ((0xF0 / result) << 8) & 0xF00 | *(volatile uint32_t *)off_12BA24 & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = softfloat_float_op(*(volatile uint64_t *)&dword_12B9E8);
      v22 = ((uint64_t (*)())__aeabi_d2ulz)(v21);
      v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12BA20) << 32);
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (volatile unsigned int *)off_12BA04;
      v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v25 = softfloat_float_op(v23);
      *v24 = dword_12BA08 & (((uint64_t (*)())__aeabi_d2ulz)(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = __aeabi_i2d(result);
      v8 = ((uint64_t (*)())__aeabi_dmul)(v7, *(volatile uint64_t *)&dword_12B9E0);
      v9 = ((int (*)(uint64_t))double_to_float)(v8);
      v10 = ((uint64_t (*)())__aeabi_f2d)(v9);
      v11 = softfloat_float_op(v10);
      *v1 = v4 & (((uint64_t (*)())__aeabi_d2ulz)(v11) << 18) | *v1 & v5;
    }
    v12 = (volatile unsigned int *)off_12BA04;
    *(volatile uint32_t *)off_12B9FC = dword_12BA00 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12B9FC >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12B9FC & 0xFF0000FF;
    *v12 = dword_12BA08 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(volatile uint32_t *)off_12BA0C & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(volatile uint32_t *)off_12BA0C = v14;
    }
    v15 = (void *)(uintptr_t)(off_12BA10);
    v16 = dword_12BA00;
    v17 = dword_12BA14;
    v18 = (volatile unsigned int *)off_12BA18;
    *(volatile uint32_t *)off_12BA10 = dword_12BA00 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12BA10 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12BA10 & dword_12BA14;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (volatile unsigned int *)off_12BA1C;
    v20 = dword_12BA08;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}


// rf_check_clk_state @ 0x12ba2c
int rf_check_clk_state() {
  volatile uint32_t *v0; // r1
  volatile unsigned int v1; // r3
  int v2; // r6
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r2
  volatile uint32_t *v5; // r5
  volatile uint32_t *v6; // r7
  int result; // r0
  volatile uint32_t *v8; // r4
  int v9; // r3
  volatile int *v10; // r3
  int v11; // r3

  if ( **(volatile int16_t **)off_12BAA4 < 0 && !(*(volatile uint32_t *)off_12BAC0 << 28) )
    return ke_int_lock_1((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12BAA8 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12BAB0);
  v1 = REG_4032_0120;
  v2 = *(volatile uint32_t *)off_12BAB0;
  v3 = (void *)(uintptr_t)(off_12BAB4);
  v4 = (void *)(uintptr_t)(off_12BAB8);
  v5 = (void *)(uintptr_t)(off_12BABC);
  v6 = (void *)(uintptr_t)(off_12BAC0);
  result = *(volatile uint32_t *)off_12BAB0 + 1;
  *(volatile uint32_t *)off_12BAB0 = result;
  *v3 = v1 + 25000;
  v8 = (void *)(uintptr_t)(off_12BAC4);
  *v4 = 128;
  v9 = v8[1] | 4;
  *v5 |= 0x80u;
  v8[1] = v9;
  *v6 = 0;
  if ( result )
  {
    v10 = (volatile int *)off_12BAA8;
    *v0 = v2;
    v11 = *v10;
    if ( !v2 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_write_poll_clear @ 0x12bad0
void mmio_write_poll_clear() {
  volatile uint32_t *v0; // r2

  v0 = (void *)(uintptr_t)(off_12BAE0);
  *(volatile uint32_t *)off_12BAE0 = 1;
  while ( (uint8_t)*v0 )
    ;
}



// mmio_poll_status @ 0x12bae4
int mmio_poll_status() {
  volatile uint32_t *v0; // r2
  unsigned int variant_cached; // r0
  volatile uint32_t *v2; // r3
  volatile uint32_t *v3; // r2
  volatile int16_t **v4; // r1
  volatile char *v5; // r0
  volatile int *v6; // r3
  volatile uint32_t *v7; // r1
  int v8; // r2
  volatile int *v9; // r4
  int v10; // r5
  volatile uint8_t *v11; // r1
  volatile int *v12; // r3
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r4
  volatile unsigned int *v15; // r6
  volatile uint32_t *v16; // r2
  volatile uint32_t *v17; // r5
  int result; // r0
  volatile uint32_t *v19; // r1
  volatile uint8_t **v20; // r2
  volatile uint32_t *v21; // r4
  volatile uint32_t *v22; // r6
  int v23; // r0
  volatile unsigned int *v24; // r5
  struct __attribute__((packed)) { uint8_t v25; // [sp+6h] [bp-2h] BYREF
  uint8_t v26; // [sp+7h] [bp-1h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_12BCDC);
  *(volatile uint32_t *)off_12BCDC = 1;
  while ( (uint8_t)*v0 )
    ;
  variant_cached = get_timer_flag();
  rf_wait_event(variant_cached);
  v2 = (void *)(uintptr_t)(off_12BCE4);
  *(volatile uint32_t *)off_12BCE0 = dword_12BCE8;
  v3 = (void *)(uintptr_t)(off_12BCEC);
  *v2 = 0x80000000;
  v4 = (volatile int16_t **)off_12BCF0;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(volatile uint32_t *)off_12BCF4 < 0x2F000000u )
    mmio_irq_clear(dword_12BD40, dword_12BD3C, 284);
  v5 = (volatile char *)off_12BCF4;
  v6 = (volatile int *)off_12BCF8;
  v7 = (void *)(uintptr_t)(off_12BCEC);
  v8 = dword_12BD00;
  *(volatile uint32_t *)off_12BCF4 = dword_12BCFC;
  *v6 = v8;
  v9 = (volatile int *)off_12BD04;
  v10 = dword_12BD08;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = (void *)(uintptr_t)(off_12BD0C);
  v12 = v6 - 8199;
  *(volatile uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = (void *)(uintptr_t)(off_12BD10);
  v14 = (void *)(uintptr_t)(off_12BCEC);
  v15 = (volatile unsigned int *)off_12BD18;
  *(volatile uint32_t *)off_12BD14 = 12288;
  *v13 = 0;
  read_calibration_offsets(&_frame.v26, &_frame.v25);
  v16 = (void *)(uintptr_t)(off_12BD20);
  *(volatile uint32_t *)off_12BD1C = (_frame.v26 << 8) | (_frame.v25 << 16) | _frame.v26;
  v17 = (void *)(uintptr_t)(off_12BD24);
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = irq47_status_handler();
  v19 = (void *)(uintptr_t)(off_12BD28);
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (volatile uint8_t **)off_12BD2C;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(volatile uint32_t *)off_12BD30 &= 0x80FFFFFF;
  v21 = (void *)(uintptr_t)(off_12BCEC);
  v22 = (void *)(uintptr_t)(off_12BD34);
  *(volatile uint32_t *)off_12BCEC |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = sys_status_get_bit28();
    if ( result )
    {
      v23 = sys_mode_get();
      v24 = (volatile unsigned int *)off_12BD44;
      result = v23 << 8;
      *(volatile uint32_t *)off_12BD44 = result & 0x700 | *(volatile uint32_t *)off_12BD44 & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = sys_status_get_bit21();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(volatile uint32_t *)off_12BD34 & 0x20000) != 0 )
      {
        result = sys_status_get_bit30();
        if ( result )
          *(volatile uint32_t *)off_12BD44 |= 2u;
      }
    }
  }
  *(volatile uint32_t *)off_12BD38 |= 1u;
  return result;
}



// mmio_clear_high_bits @ 0x12bd48
void *mmio_clear_high_bits() {
  void *result; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  result = (void *)(uintptr_t)(off_12BD68);
  v1 = (void *)(uintptr_t)(off_12BD6C);
  v2 = (void *)(uintptr_t)(off_12BD70);
  *(volatile uint32_t *)off_12BD68 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}



// mac_config_clear @ 0x12bd74
volatile int *mac_config_clear() {
  volatile uint32_t *v0; // r1
  volatile uint32_t *v1; // r0
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r1
  volatile uint32_t *v4; // r5
  volatile int *v5; // r0
  int v6; // r4
  volatile uint32_t *v7; // r1
  volatile uint32_t *v8; // r4
  int v9; // r3
  volatile int *result; // r0

  v0 = (void *)(uintptr_t)(off_12BDF8);
  v1 = (void *)(uintptr_t)(off_12BDFC);
  *(volatile uint32_t *)off_12BDF4 &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = (void *)(uintptr_t)(off_12BDFC);
  v3 = (void *)(uintptr_t)(off_12BE00);
  v4 = (void *)(uintptr_t)(off_12BE04);
  v5 = (volatile int *)off_12BE08;
  v6 = dword_12BE0C;
  *(volatile uint32_t *)off_12BDFC |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = (void *)(uintptr_t)(off_12BE10);
  v8 = (void *)(uintptr_t)(off_12BE14);
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}



// mac_dma_write @ 0x12be18
int mac_dma_write(volatile int *a1) {
  volatile uint32_t *v1; // r2
  volatile int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = (void *)(uintptr_t)(off_12BE4C);
  v2 = (volatile int *)off_12BE50;
  v3 = *a1;
  v4 = *((volatile uint16_t *)a1 + 2);
  *(volatile uint32_t *)off_12BE48 = v3;
  *v1 = v4;
  *v2 = 0x20000000;
  do
    v5 = *v2;
  while ( (*v2 & 0x20000000) != 0 );
  if ( (v5 & 0x10000000) != 0 )
    return 255;
  else
    return (uint8_t)(BYTE2(v5) - 16);
}



// mmio_disable_irq @ 0x12be54
unsigned int mmio_disable_irq() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile int16_t **v2; // r5
  volatile int *v3; // r4
  int v4; // r3
  volatile int16_t *v5; // r2
  unsigned int result; // r0
  volatile uint32_t *v7; // r2

  v0 = (void *)(uintptr_t)(off_12BEC4);
  v1 = (void *)(uintptr_t)(off_12BEC8);
  *(volatile uint32_t *)off_12BEC4 &= ~1u;
  v2 = (volatile int16_t **)off_12BECC;
  v3 = (volatile int *)off_12BED0;
  v4 = dword_12BED4;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(volatile uint32_t *)off_12BEDC << 28 )
  {
    mmio_field_update(dword_12BEE4, dword_12BEE0, 472);
    v4 = *v3;
  }
  *(volatile uint32_t *)off_12BED8 = v4 | v3[1];
  result = rf_ant_switch_set(1);
  v7 = (void *)(uintptr_t)(off_12BEC8);
  *(volatile uint32_t *)off_12BEC8 = *(volatile uint32_t *)off_12BEC8 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}



// ke_enter_critical @ 0x12bee8
int ke_enter_critical(int a1) {
  unsigned int v1; // r2
  volatile uint32_t *v2; // r5
  int v3; // r6
  int v4; // r3
  int v5; // r7
  unsigned int v6; // r1
  int v7; // r3
  volatile int *v8; // r1
  volatile int *v9; // r4
  int v10; // r0
  int result; // r0
  volatile int *v12; // r3
  int v13; // r3

  v1 = abs32(a1);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12BF58 = 1;
  }
  v2 = (void *)(uintptr_t)(off_12BF5C);
  v3 = *(volatile uint32_t *)off_12BF5C;
  v4 = *(volatile uint32_t *)off_12BF60;
  v5 = *(volatile uint32_t *)off_12BF5C + 1;
  v6 = *(volatile uint32_t *)off_12BF64;
  *(volatile uint32_t *)off_12BF5C = v5;
  v7 = v4 | 0x1000000;
  if ( a1 <= 0 )
  {
    if ( !a1 || ~v6 >= v1 + 32 )
      goto LABEL_5;
LABEL_13:
    result = -1;
    goto LABEL_6;
  }
  if ( v1 > v6 )
    goto LABEL_13;
LABEL_5:
  v8 = (volatile int *)off_12BF64;
  v9 = (volatile int *)off_12BF60;
  v10 = *(volatile uint32_t *)off_12BF64 - a1;
  *(volatile uint32_t *)off_12BF64 = v10;
  *v9 = v7;
  *v8 = v10;
  *v9 = v7;
  *v8 = v10;
  result = 0;
  *v9 = v7;
LABEL_6:
  if ( v5 )
  {
    v12 = (volatile int *)off_12BF58;
    *v2 = v3;
    v13 = *v12;
    if ( !v3 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}



// mac_isr_handler @ 0x12bf68
int mac_isr_handler() {
  int v0; // r4
  int v1; // r5
  volatile uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  volatile uint32_t *v6; // r3

  v0 = (*(volatile uint32_t *)off_12C040 >> 25) & 1;
  if ( (*(volatile uint32_t *)off_12C040 & 0x2000000) == 0
    && (int)(32 * *(volatile uint32_t *)off_12C048
     - 2000
     - *((volatile uint16_t *)off_12C04C + 92)
     - *((volatile uint16_t *)off_12C04C + 93)) < 0 )
  {
    return v0;
  }
  v1 = *(volatile uint32_t *)off_12C050;
  if ( !*(volatile uint32_t *)off_12C050 )
    return 1;
  v2 = (volatile uint16_t *)off_12C04C;
  v3 = *(volatile uint32_t *)(v1 + 12);
  v4 = *((volatile uint16_t *)off_12C04C + 93);
  if ( (int)(v3 - *((volatile uint32_t *)off_12C044 + 4) - 2000 - *((volatile uint16_t *)off_12C04C + 92) - v4) < 0 )
  {
    if ( **(volatile int16_t **)off_12C058 < 0 && (int)(v3 - *((volatile uint32_t *)off_12C044 + 4) + 5000) < 0 )
    {
      mmio_irq_clear(dword_12C060, dword_12C05C, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(volatile uint8_t **)off_12C054 != 1 )
      return 1;
    if ( **(volatile int16_t **)off_12C058 < 0 && (int)(v3 - *((volatile uint32_t *)off_12C044 + 4) - v4) < 0 )
    {
      mmio_irq_clear(dword_12C064, dword_12C05C, 580);
      v3 = *(volatile uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = (void *)(uintptr_t)(off_12C044);
    *((volatile uint32_t *)off_12C044 + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}



// ke_critical_enter @ 0x12c068
int ke_critical_enter() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  volatile uint32_t *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C0A4 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12C0A8);
  v1 = *(volatile uint32_t *)off_12C0A8;
  result = *(volatile uint32_t *)off_12C0B0;
  v3 = *(volatile uint32_t *)off_12C0A8 + 1;
  *(volatile uint32_t *)off_12C0A8 = v3;
  if ( v3 )
  {
    v4 = (void *)(uintptr_t)(off_12C0A4);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}



// power_state_read @ 0x12c0b4
int power_state_read() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r4
  int v3; // r1

  v0 = *(volatile uint32_t *)off_12C1CC;
  *(volatile uint32_t *)off_12C1D0 = *(volatile uint32_t *)off_12C1CC;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    ke_event_schedule_1(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    ke_event_schedule_1(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = seq_count_restart();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_set_bit(4);
    result = conn_get(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(volatile uint8_t *)off_12C1D4 )
    {
      v2 = (volatile int *)off_12C1F8;
      write_mmio_byte(HIBYTE(((volatile uint32_t *)(uintptr_t)off_12C1F8)[102]));
      v3 = *((volatile char *)v2 + 411);
      *((volatile uint8_t *)off_12C1FC + 9) = v3;
      return ke_event_schedule_1("update:%d\n", v3);
    }
    if ( *(volatile uint8_t *)off_12C1D8 )
    {
      result = *(volatile uint32_t *)off_12C1DC << 28;
      if ( result )
        *((volatile uint8_t *)off_12C1D8 + 6) = 1;
    }
  }
  if ( **(volatile int16_t **)off_12C1E0 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return ke_int_lock_1((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return ke_int_lock_1((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}


// mac_irq_status @ 0x12c218
void mac_irq_status() {
  int v0; // r4
  int v1; // r3
  int v2; // r5

  v0 = *(volatile uint32_t *)off_12C3B0 & *(volatile uint32_t *)off_12C3AC;
  v1 = dword_12C3B4 & v0;
  *((volatile uint32_t *)off_12C3AC + 1) = v0;
  if ( v1 )
    set_system_flag_1(0x1000000);
  if ( (dword_12C3B8 & v0) != 0 )
    set_system_flag_1(0x800000);
  if ( (v0 & 4) != 0 )
    rf_read_irq_status();
  if ( (v0 & 8) != 0 )
    power_state_read();
  if ( (v0 & 0x10000000) != 0 )
  {
    v2 = *(volatile uint32_t *)off_12C3C8;
    *((volatile uint8_t *)off_12C3CC + 30) |= *(volatile uint8_t *)off_12C3C8 & 0x3F;
    set_system_flag_1(0x40000);
    *(volatile uint32_t *)off_12C3D0 = v2;
  }
  if ( **(volatile int16_t **)off_12C3BC < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else if ( (v0 & 0x1000000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
    }
    else if ( (v0 & 0x2000000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
    }
    else if ( (v0 & 0x100000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
    }
    else if ( (v0 & 0x8000000) != 0 )
    {
      ke_int_lock_1((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
    }
  }
}


// mac_irq_clear @ 0x12c408
void mac_irq_clear(int a1, int a2) {
  int v2; // r4
  volatile uint32_t *v3; // r0
  volatile uint32_t *v4; // r1
  int v5; // r2
  int v6; // r3
  volatile uint32_t *v7; // r1
  volatile unsigned int v8; // r2
  signed int v9; // r3
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r5
  signed int v12; // r3
  volatile uint32_t *v13; // r4
  signed int v14; // r3
  signed int v15; // r3
  volatile uint32_t *v16; // r4
  unsigned int v17; // r2
  int v18; // r3

  v2 = *(volatile uint32_t *)dword_12C52C & *(volatile uint32_t *)dword_12C530;
  *(volatile uint32_t *)(dword_12C52C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (volatile uint32_t *)dword_12C534;
    v4 = (volatile uint32_t *)dword_12C538;
    v5 = *(volatile uint32_t *)dword_12C534;
    v6 = *(volatile uint32_t *)dword_12C538;
    if ( (v2 & 1) != 0 && !*(volatile uint8_t *)(dword_12C53C + 0x24) )
    {
      *(volatile uint32_t *)dword_12C534 = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      ke_event_schedule_1(aWf);
    }
    else
    {
      v7 = (volatile uint32_t *)dword_12C538;
      *(volatile uint32_t *)dword_12C534 = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      ke_event_schedule_1(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(volatile uint32_t *)dword_12C544 & 1) != 0 )
    {
      *(volatile uint32_t *)dword_12C548 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (volatile uint32_t *)dword_12C554;
      v11 = (volatile uint32_t *)dword_12C558;
      *(volatile uint32_t *)dword_12C550 = *(volatile uint32_t *)dword_12C550 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (volatile uint32_t *)dword_12C558;
      *(volatile uint32_t *)dword_12C544 &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(volatile uint32_t *)dword_12C558 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (volatile uint32_t *)dword_12C558;
      *(volatile uint32_t *)dword_12C544 |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(volatile uint32_t *)dword_12C548 &= 0xFF9FFFFF;
      ke_event_schedule_1(aUnlock, REG_4050_1000);
    }
    else
    {
      *(volatile uint32_t *)dword_12C554 |= 1u;
      ke_event_schedule_1(aUnlock, a2);
    }
  }
}


// rx_env_list_init @ 0x12c564
int rx_env_list_init() {
  int v0; // r4

  v0 = dword_12C57C;
  zero_struct((void *)(uintptr_t)(dword_12C57C));
  return (int)(uintptr_t)(zero_struct((void *)(uintptr_t)(v0 + 8)));
}



