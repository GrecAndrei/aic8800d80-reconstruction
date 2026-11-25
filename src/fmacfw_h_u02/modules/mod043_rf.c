// is_phy_ready @ 0x12aec8
int is_phy_ready() {
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(volatile uint32_t *)off_12AF2C;
  v1 = *((volatile uint8_t *)off_12AF2C + 10);
  if ( hci_cmd_handler(2u) != 2 )
  {
    v2 = hci_cmd_handler(2u);
    alloc_tx_event("start st=%d\n", v2);
  }
  if ( **(volatile int16_t **)off_12AF34 < 0 && hci_cmd_handler(2u) != 2 )
    irq_disable_mmio_write((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(volatile uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    get_fw_info();
  hci_cmd_preprocess(2u, 3);
  return 0;
}


// send_vendor_command @ 0x12af40
int send_vendor_command(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v6; // r4
  int v7; // r0
  volatile uint8_t *v8; // r2

  v6 = (volatile uint8_t *)tx_send_pdu(2049, a4, a3, 1);
  v7 = hci_cmd_handler(2u);
  check_feature_flag(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( hci_cmd_handler(2u) )
  {
    *v6 = 8;
    rx_process_packet_1((int)v6);
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_12AFC4 < 0 && !*(volatile uint8_t *)(a2 + 367) )
      irq_disable_mmio_write((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = (void *)(uintptr_t)(off_12AFC8);
    *v6 = 0;
    *(volatile uint32_t *)v8 = a2;
    v8[10] = 0;
    *((volatile uint16_t *)v8 + 4) = a4;
    log_trace_event(a2);
    rx_process_packet_1((int)v6);
    return 1;
  }
}


// get_event_payload @ 0x12afd4
int get_event_payload(volatile uint16_t *a1) {
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B02C + 16);
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



// reset_global_config @ 0x12b030
int reset_global_config() {
  int result; // r0
  volatile uint32_t *v1; // r3

  memset((volatile int *)dword_12B058, 0, 0xCu);
  result = hci_cmd_preprocess(2u, 0);
  v1 = (void *)(uintptr_t)(off_12B05C);
  *(volatile uint32_t *)off_12B05C = dword_12B060;
  v1[2] = (int)(uintptr_t)(v1 + 5);
  v1[4] = 0;
  v1[1] = 0;
  return result;
}


// process_entry_list @ 0x12b064
int process_entry_list() {
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

  v0 = (void *)(uintptr_t)(off_12B124);
  v1 = *(volatile uint32_t *)off_12B124;
  v2 = *(volatile uint32_t *)off_12B124 + 6 * *((volatile uint8_t *)off_12B124 + 10);
  v3 = 6 * *((volatile uint8_t *)off_12B124 + 10);
  v4 = *(volatile uint8_t *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B128 + 20);
    if ( !v5 )
    {
      v5 = dword_12B12C;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = get_event_payload((volatile uint16_t *)(*(volatile uint32_t *)off_12B124 + 6 * *((volatile uint8_t *)off_12B124 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((volatile uint8_t *)off_12B134 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  wifi_disable_get((volatile int16_t *)v2, v5, *(volatile uint8_t *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(volatile uint8_t *)(v2 + 2);
    v8 = *(volatile uint16_t *)(v1 + v3);
    if ( *(volatile uint8_t *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(volatile uint8_t *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B130 * (uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
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
          return hci_cmd_preprocess(2u, 2);
        }
        v7 = (v7 & ~0xFFu) | ((uint8_t)((unsigned int)(((unsigned int)dword_12B130 * (uint64_t)(unsigned int)(v8 - 2407)) >> 32) >> 2) & 0xFFu);
      }
      *(volatile uint8_t *)(v6 + 2) = v7;
    }
  }
  return hci_cmd_preprocess(2u, 2);
}


// log_trace_event @ 0x12b138
int log_trace_event(int a1) {
  volatile uint32_t *v1; // r6
  volatile char *v2; // r4
  int result; // r0

  v1 = (void *)(uintptr_t)(off_12B168);
  v2 = (volatile char *)off_12B16C;
  v1[1] = (int)(uintptr_t)(test_arg2_one_12da20((void *)(uintptr_t)(off_12B16C), *(volatile uint16_t *)(*(volatile uint32_t *)off_12B168 + 364)));
  result = process_entry_list();
  *(volatile uint32_t *)&v2[-8] = *(volatile uint32_t *)&v2[-12] - 1 + *(volatile uint16_t *)(a1 + 364);
  *((volatile uint32_t *)v2 - 1) = 0;
  return result;
}



// get_bt_device_state @ 0x12b170
int get_bt_device_state(int a1, int a2, int a3) {
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

  v3 = dword_12B250;
  v4 = dword_12B250 + 1320 * a1;
  v6 = *(volatile uint8_t *)(v4 + 116);
  if ( *(volatile uint8_t *)(v4 + 1224) )
  {
    result = (int)(uintptr_t)(lock_acquire(1, 26));
    v12 = result;
    if ( result )
    {
LABEL_5:
      v13 = (void *)(uintptr_t)(off_12B254);
      v14 = dword_12B24C + 696 * v6;
      v15 = *(volatile uint64_t *)(result + 72);
      v16 = *((volatile uint16_t *)off_12B254 + 254);
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
      return sec_check(v12, 5);
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(v4 + 72);
    v10 = *(volatile uint8_t *)(v9 + 4);
    if ( *(volatile uint8_t *)(v9 + 4) )
      v10 = 1;
    result = (int)(uintptr_t)(lock_acquire(v10, 26));
    v12 = result;
    if ( result )
      goto LABEL_5;
  }
  return result;
}



// get_fw_info @ 0x12b258
void get_fw_info() {
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

  v0 = *(volatile uint32_t *)off_12B390;
  v22 = *((volatile uint8_t *)off_12B390 + 10);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_12B390 + 368) )
  {
    v21 = dword_12B394 + 1320 * *(volatile uint8_t *)(*(volatile uint32_t *)off_12B390 + 366);
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
      v4 = (int)(uintptr_t)(lock_acquire(v3, *(volatile uint16_t *)(v0 + 364) + (uint8_t)*(v1 - 1) + 26));
      v5 = v1;
      v6 = v4;
      if ( !v4 )
        break;
      v7 = (void *)(uintptr_t)(off_12B39C);
      v8 = *(volatile uint32_t *)(v4 + 72);
      v9 = *((volatile uint16_t *)off_12B39C + 254);
      v10 = (volatile int *)off_12B3A0;
      v11 = *(volatile uint32_t *)(v4 + 76);
      v12 = *((volatile uint16_t *)off_12B3A0 + 2);
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
      *(volatile uint32_t *)(v11 + 24) = dword_12B398;
      *(volatile uint32_t *)(v11 + 32) = v20 - v19;
      *(volatile uint32_t *)(v6 + 88) = 0;
      *(volatile uint32_t *)(v6 + 92) = 0;
      *(volatile uint8_t *)(v6 + 28) = *(volatile uint8_t *)(v0 + 366);
      *(volatile uint8_t *)(v6 + 29) = -1;
      sec_check(v6, 5);
      ++v2;
      v1 += 33;
    }
    while ( *(volatile uint8_t *)(v0 + 368) > v2 );
  }
}



// rf_execute_cmd @ 0x12b3a4
volatile uint32_t * rf_execute_cmd(char a1, uint16_t a2) {
  volatile char *v3; // r4

  v3 = (volatile char *)tx_send_pdu(2052, a2, 2, 1);
  check_feature_flag(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return rx_process_packet_1((int)v3);
}


// rf_get_buffer @ 0x12b3d4
int rf_get_buffer() {
  return *(volatile uint32_t *)off_12B3E4 + 6 * *((volatile uint8_t *)off_12B3E4 + 10);
}



// hci_buffer_get @ 0x12b3e8
int hci_buffer_get(int a1) {
  if ( (*(volatile uint8_t *)(a1 + 3) & 5) != 0 )
    return *(volatile uint32_t *)(*(volatile uint32_t *)off_12B3FC + 20);
  else
    return get_event_payload((volatile uint16_t *)a1);
}



// rf_get_short_status @ 0x12b400
int rf_get_short_status() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(volatile int16_t **)off_12B448 < 0 && *(volatile uint32_t *)off_12B454 << 28 )
    return unknown_12f2c8((int)aNxmacCurrentSt, (int)aHalMachwIdleIr, 105);
  if ( (*(volatile uint32_t *)off_12B44C & 0x80) != 0 )
  {
    v0 = (void *)(uintptr_t)(off_12B450);
    v1 = *((volatile uint32_t *)off_12B450 + 1) & 0xFFFFFFFB;
    *(volatile uint32_t *)off_12B44C &= ~0x80u;
    v0[1] = v1;
    return irq_disable_global_2(0x2000000);
  }
  return result;
}


// rf_irq_service @ 0x12b460
unsigned int rf_irq_service(unsigned int result) {
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

  v1 = (volatile unsigned int *)off_12B688;
  v2 = (uint8_t)*(volatile uint32_t *)off_12B688;
  if ( result != v2 )
  {
    v3 = dword_12B68C;
    v4 = dword_12B690;
    v5 = dword_12B6C0;
    *(volatile uint32_t *)off_12B6BC = ((0xF0 / result) << 8) & 0xF00 | *(volatile uint32_t *)off_12B6BC & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = double_exp_check(*(volatile uint64_t *)&dword_12B680);
      v22 = ((int (*)(uint64_t))double_to_float_rounding)(v21);
      v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12B6B8) << 32);
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (volatile unsigned int *)off_12B69C;
      v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v25 = double_exp_check(v23);
      *v24 = dword_12B6A0 & (((int (*)(uint64_t))double_to_float_rounding)(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = signed_int_to_double(result);
      v8 = ((uint64_t (*)())double_compare_common)(v7, *(volatile uint64_t *)&dword_12B678);
      v9 = ((int (*)(uint64_t))double_to_int)(v8);
      v10 = ((uint64_t (*)())float_to_double)(v9);
      v11 = double_exp_check(v10);
      *v1 = v4 & (((int (*)(uint64_t))double_to_float_rounding)(v11) << 18) | *v1 & v5;
    }
    v12 = (volatile unsigned int *)off_12B69C;
    *(volatile uint32_t *)off_12B694 = dword_12B698 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12B694 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12B694 & 0xFF0000FF;
    *v12 = dword_12B6A0 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(volatile uint32_t *)off_12B6A4 & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(volatile uint32_t *)off_12B6A4 = v14;
    }
    v15 = (void *)(uintptr_t)(off_12B6A8);
    v16 = dword_12B698;
    v17 = dword_12B6AC;
    v18 = (volatile unsigned int *)off_12B6B0;
    *(volatile uint32_t *)off_12B6A8 = dword_12B698 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12B6A8 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12B6A8 & dword_12B6AC;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (volatile unsigned int *)off_12B6B4;
    v20 = dword_12B6A0;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}


// rf_status_check @ 0x12b6c4
int rf_status_check() {
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

  if ( **(volatile int16_t **)off_12B73C < 0 && !(*(volatile uint32_t *)off_12B758 << 28) )
    return unknown_12f2c8((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12B740 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12B748);
  v1 = REG_4032_0120;
  v2 = *(volatile uint32_t *)off_12B748;
  v3 = (void *)(uintptr_t)(off_12B74C);
  v4 = (void *)(uintptr_t)(off_12B750);
  v5 = (void *)(uintptr_t)(off_12B754);
  v6 = (void *)(uintptr_t)(off_12B758);
  result = *(volatile uint32_t *)off_12B748 + 1;
  *(volatile uint32_t *)off_12B748 = result;
  *v3 = v1 + 25000;
  v8 = (void *)(uintptr_t)(off_12B75C);
  *v4 = 128;
  v9 = v8[1] | 4;
  *v5 |= 0x80u;
  v8[1] = v9;
  *v6 = 0;
  if ( result )
  {
    v10 = (volatile int *)off_12B740;
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


// rf_set_power_on @ 0x12b768
void rf_set_power_on() {
  volatile uint32_t *v0; // r2

  v0 = (void *)(uintptr_t)(off_12B778);
  *(volatile uint32_t *)off_12B778 = 1;
  while ( (uint8_t)*v0 )
    ;
}



// rf_hw_init_1 @ 0x12b77c
int rf_hw_init_1() {
  volatile uint32_t *v0; // r2
  unsigned int v1; // r0
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
  v0 = (void *)(uintptr_t)(off_12B974);
  *(volatile uint32_t *)off_12B974 = 1;
  while ( (uint8_t)*v0 )
    ;
  v1 = global_state_get_byte();
  rf_irq_service(v1);
  v2 = (void *)(uintptr_t)(off_12B97C);
  *(volatile uint32_t *)off_12B978 = dword_12B980;
  v3 = (void *)(uintptr_t)(off_12B984);
  *v2 = 0x80000000;
  v4 = (volatile int16_t **)off_12B988;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(volatile uint32_t *)off_12B98C < 0x2F000000u )
    irq_disable_mmio_write(dword_12B9D8, dword_12B9D4, 284);
  v5 = (volatile char *)off_12B98C;
  v6 = (volatile int *)off_12B990;
  v7 = (void *)(uintptr_t)(off_12B984);
  v8 = dword_12B998;
  *(volatile uint32_t *)off_12B98C = dword_12B994;
  *v6 = v8;
  v9 = (volatile int *)off_12B99C;
  v10 = dword_12B9A0;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = (void *)(uintptr_t)(off_12B9A4);
  v12 = v6 - 8199;
  *(volatile uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = (void *)(uintptr_t)(off_12B9A8);
  v14 = (void *)(uintptr_t)(off_12B984);
  v15 = (volatile unsigned int *)off_12B9B0;
  *(volatile uint32_t *)off_12B9AC = 12288;
  *v13 = 0;
  get_calibration_offsets(&_frame.v26, &_frame.v25);
  v16 = (void *)(uintptr_t)(off_12B9B8);
  *(volatile uint32_t *)off_12B9B4 = (_frame.v26 << 8) | (_frame.v25 << 16) | _frame.v26;
  v17 = (void *)(uintptr_t)(off_12B9BC);
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = get_rf_field_mid();
  v19 = (void *)(uintptr_t)(off_12B9C0);
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (volatile uint8_t **)off_12B9C4;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(volatile uint32_t *)off_12B9C8 &= 0x80FFFFFF;
  v21 = (void *)(uintptr_t)(off_12B984);
  v22 = (void *)(uintptr_t)(off_12B9CC);
  *(volatile uint32_t *)off_12B984 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = rf_status_bit28();
    if ( result )
    {
      v23 = get_rf_field_hi();
      v24 = (volatile unsigned int *)off_12B9DC;
      result = v23 << 8;
      *(volatile uint32_t *)off_12B9DC = result & 0x700 | *(volatile uint32_t *)off_12B9DC & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = rf_status_bit21();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(volatile uint32_t *)off_12B9CC & 0x20000) != 0 )
      {
        result = rf_status_bit30();
        if ( result )
          *(volatile uint32_t *)off_12B9DC |= 2u;
      }
    }
  }
  *(volatile uint32_t *)off_12B9D0 |= 1u;
  return result;
}



// rf_irq_clear_1 @ 0x12b9e0
void *rf_irq_clear_1() {
  void *result; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  result = (void *)(uintptr_t)(off_12BA00);
  v1 = (void *)(uintptr_t)(off_12BA04);
  v2 = (void *)(uintptr_t)(off_12BA08);
  *(volatile uint32_t *)off_12BA00 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}



// rf_radio_calibrate @ 0x12ba0c
volatile int *rf_radio_calibrate() {
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

  v0 = (void *)(uintptr_t)(off_12BA90);
  v1 = (void *)(uintptr_t)(off_12BA94);
  *(volatile uint32_t *)off_12BA8C &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = (void *)(uintptr_t)(off_12BA94);
  v3 = (void *)(uintptr_t)(off_12BA98);
  v4 = (void *)(uintptr_t)(off_12BA9C);
  v5 = (volatile int *)off_12BAA0;
  v6 = dword_12BAA4;
  *(volatile uint32_t *)off_12BA94 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = (void *)(uintptr_t)(off_12BAA8);
  v8 = (void *)(uintptr_t)(off_12BAAC);
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}



// rf_write_frequency @ 0x12bab0
int rf_write_frequency(volatile int *a1) {
  volatile uint32_t *v1; // r2
  volatile int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = (void *)(uintptr_t)(off_12BAE4);
  v2 = (volatile int *)off_12BAE8;
  v3 = *a1;
  v4 = *((volatile uint16_t *)a1 + 2);
  *(volatile uint32_t *)off_12BAE0 = v3;
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



// rf_set_power_off @ 0x12baec
unsigned int rf_set_power_off() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile int16_t **v2; // r5
  volatile int *v3; // r4
  int v4; // r3
  volatile int16_t *v5; // r2
  unsigned int result; // r0
  volatile uint32_t *v7; // r2

  v0 = (void *)(uintptr_t)(off_12BB5C);
  v1 = (void *)(uintptr_t)(off_12BB60);
  *(volatile uint32_t *)off_12BB5C &= ~1u;
  v2 = (volatile int16_t **)off_12BB64;
  v3 = (volatile int *)off_12BB68;
  v4 = dword_12BB6C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(volatile uint32_t *)off_12BB74 << 28 )
  {
    mmio_write_field(dword_12BB7C, dword_12BB78, 472);
    v4 = *v3;
  }
  *(volatile uint32_t *)off_12BB70 = v4 | v3[1];
  result = mmio_reg_update(1);
  v7 = (void *)(uintptr_t)(off_12BB60);
  *(volatile uint32_t *)off_12BB60 = *(volatile uint32_t *)off_12BB60 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}



// abs_i32 @ 0x12bb80
int abs_i32(int a1) {
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
    *(volatile uint32_t *)off_12BBF0 = 1;
  }
  v2 = (void *)(uintptr_t)(off_12BBF4);
  v3 = *(volatile uint32_t *)off_12BBF4;
  v4 = *(volatile uint32_t *)off_12BBF8;
  v5 = *(volatile uint32_t *)off_12BBF4 + 1;
  v6 = *(volatile uint32_t *)off_12BBFC;
  *(volatile uint32_t *)off_12BBF4 = v5;
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
  v8 = (volatile int *)off_12BBFC;
  v9 = (volatile int *)off_12BBF8;
  v10 = *(volatile uint32_t *)off_12BBFC - a1;
  *(volatile uint32_t *)off_12BBFC = v10;
  *v9 = v7;
  *v8 = v10;
  *v9 = v7;
  *v8 = v10;
  result = 0;
  *v9 = v7;
LABEL_6:
  if ( v5 )
  {
    v12 = (volatile int *)off_12BBF0;
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



// rf_radio_status @ 0x12bc00
int rf_radio_status() {
  int v0; // r4
  int v1; // r5
  volatile uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  volatile uint32_t *v6; // r3

  v0 = (*(volatile uint32_t *)off_12BCD8 >> 25) & 1;
  if ( (*(volatile uint32_t *)off_12BCD8 & 0x2000000) == 0
    && (int)(32 * *(volatile uint32_t *)off_12BCE0
     - 2000
     - *((volatile uint16_t *)off_12BCE4 + 92)
     - *((volatile uint16_t *)off_12BCE4 + 93)) < 0 )
  {
    return v0;
  }
  v1 = *(volatile uint32_t *)off_12BCE8;
  if ( !*(volatile uint32_t *)off_12BCE8 )
    return 1;
  v2 = (volatile uint16_t *)off_12BCE4;
  v3 = *(volatile uint32_t *)(v1 + 12);
  v4 = *((volatile uint16_t *)off_12BCE4 + 93);
  if ( (int)(v3 - *((volatile uint32_t *)off_12BCDC + 4) - 2000 - *((volatile uint16_t *)off_12BCE4 + 92) - v4) < 0 )
  {
    if ( **(volatile int16_t **)off_12BCF0 < 0 && (int)(v3 - *((volatile uint32_t *)off_12BCDC + 4) + 5000) < 0 )
    {
      irq_disable_mmio_write(dword_12BCF8, dword_12BCF4, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(volatile uint8_t **)off_12BCEC != 1 )
      return 1;
    if ( **(volatile int16_t **)off_12BCF0 < 0 && (int)(v3 - *((volatile uint32_t *)off_12BCDC + 4) - v4) < 0 )
    {
      irq_disable_mmio_write(dword_12BCFC, dword_12BCF4, 580);
      v3 = *(volatile uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = (void *)(uintptr_t)(off_12BCDC);
    *((volatile uint32_t *)off_12BCDC + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}



// rf_delay @ 0x12bd00
int rf_delay() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  volatile uint32_t *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12BD3C = 1;
  }
  v0 = (void *)(uintptr_t)(off_12BD40);
  v1 = *(volatile uint32_t *)off_12BD40;
  result = *(volatile uint32_t *)off_12BD48;
  v3 = *(volatile uint32_t *)off_12BD40 + 1;
  *(volatile uint32_t *)off_12BD40 = v3;
  if ( v3 )
  {
    v4 = (void *)(uintptr_t)(off_12BD3C);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}



// rf_sync_status @ 0x12bd4c
int rf_sync_status() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r4
  int v3; // r1

  v0 = *(volatile uint32_t *)off_12BE64;
  *(volatile uint32_t *)off_12BE68 = *(volatile uint32_t *)off_12BE64;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    alloc_tx_event(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    alloc_tx_event(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = seq_num_read();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_modify_bit(4);
    result = phy_get_cfg_ptr(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(volatile uint8_t *)off_12BE6C )
    {
      v2 = (volatile int *)off_12BE90;
      rf_reg_write_byte(HIBYTE(((volatile uint32_t *)(uintptr_t)off_12BE90)[102]));
      v3 = *((volatile char *)v2 + 411);
      *((volatile uint8_t *)off_12BE94 + 9) = v3;
      return alloc_tx_event("update:%d\n", v3);
    }
    if ( *(volatile uint8_t *)off_12BE70 )
    {
      result = *(volatile uint32_t *)off_12BE74 << 28;
      if ( result )
        *((volatile uint8_t *)off_12BE70 + 6) = 1;
    }
  }
  if ( **(volatile int16_t **)off_12BE78 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return unknown_12f2c8((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return unknown_12f2c8((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}


// rf_wait_event @ 0x12beb0
void rf_wait_event() {
  int v0; // r4
  int v1; // r3
  int v2; // r5

  v0 = *(volatile uint32_t *)off_12C048 & *(volatile uint32_t *)off_12C044;
  v1 = dword_12C04C & v0;
  *((volatile uint32_t *)off_12C044 + 1) = v0;
  if ( v1 )
    irq_disable_global_2(0x1000000);
  if ( (dword_12C050 & v0) != 0 )
    irq_disable_global_2(0x800000);
  if ( (v0 & 4) != 0 )
    rf_get_short_status();
  if ( (v0 & 8) != 0 )
    rf_sync_status();
  if ( (v0 & 0x10000000) != 0 )
  {
    v2 = *(volatile uint32_t *)off_12C060;
    *((volatile uint8_t *)off_12C064 + 30) |= *(volatile uint8_t *)off_12C060 & 0x3F;
    irq_disable_global_2(0x40000);
    *(volatile uint32_t *)off_12C068 = v2;
  }
  if ( **(volatile int16_t **)off_12C054 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else if ( (v0 & 0x1000000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
    }
    else if ( (v0 & 0x2000000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
    }
    else if ( (v0 & 0x100000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
    }
    else if ( (v0 & 0x8000000) != 0 )
    {
      unknown_12f2c8((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
    }
  }
}


// rf_process_event @ 0x12c0a0
void rf_process_event(int a1, volatile int *a2) {
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

  v2 = *(volatile uint32_t *)dword_12C1C4 & *(volatile uint32_t *)dword_12C1C8;
  *(volatile uint32_t *)(dword_12C1C4 + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (volatile uint32_t *)dword_12C1CC;
    v4 = (volatile uint32_t *)dword_12C1D0;
    v5 = *(volatile uint32_t *)dword_12C1CC;
    v6 = *(volatile uint32_t *)dword_12C1D0;
    if ( (v2 & 1) != 0 && !*(volatile uint8_t *)(dword_12C1D4 + 0x24) )
    {
      *(volatile uint32_t *)dword_12C1CC = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      alloc_tx_event(aWf);
    }
    else
    {
      v7 = (volatile uint32_t *)dword_12C1D0;
      *(volatile uint32_t *)dword_12C1CC = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      alloc_tx_event(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(volatile uint32_t *)dword_12C1DC & 1) != 0 )
    {
      *(volatile uint32_t *)dword_12C1E0 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (volatile uint32_t *)dword_12C1EC;
      v11 = (volatile uint32_t *)dword_12C1F0;
      *(volatile uint32_t *)dword_12C1E8 = *(volatile uint32_t *)dword_12C1E8 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (volatile uint32_t *)dword_12C1F0;
      *(volatile uint32_t *)dword_12C1DC &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(volatile uint32_t *)dword_12C1F0 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (volatile uint32_t *)dword_12C1F0;
      *(volatile uint32_t *)dword_12C1DC |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(volatile uint32_t *)dword_12C1E0 &= 0xFF9FFFFF;
      alloc_tx_event(aUnlock, &REG_4050_1000);
    }
    else
    {
      *(volatile uint32_t *)dword_12C1EC |= 1u;
      alloc_tx_event(aUnlock, a2);
    }
  }
}


// deinit_bt_global_0x190688 @ 0x12c1fc
int deinit_bt_global_0x190688() {
  int v0; // r4

  v0 = dword_12C214;
  clear_stats_buf((void *)(uintptr_t)(dword_12C214));
  return (int)(uintptr_t)(clear_stats_buf((void *)(uintptr_t)(v0 + 8)));
}



