// ke_task_state_get_1 @ 0x12b008
int ke_task_state_get_1() {
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(volatile uint32_t *)off_12B06C;
  v1 = *((volatile uint8_t *)off_12B06C + 10);
  if ( rx_rate_field_parse(2u) != 2 )
  {
    v2 = rx_rate_field_parse(2u);
    event_dispatch("start st=%d\n", v2);
  }
  if ( **(volatile int16_t **)off_12B074 < 0 && rx_rate_field_parse(2u) != 2 )
    mmio_clear_register((int)aKeStateGetTask_3, (int)aMmScanChannelS, 163);
  if ( (*(volatile uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    controller_read_features();
  rx_phy_status_parse(2u, 3);
  return 0;
}


// ke_msg_send_1 @ 0x12b080
int ke_msg_send_1(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v6; // r4
  int v7; // r0
  volatile uint8_t *v8; // r2

  v6 = (volatile uint8_t *)ke_msg_alloc(2049, a4, a3, 1);
  v7 = rx_rate_field_parse(2u);
  check_status_bits(4, "%s:%d\r\n", aScanStartReqHa, v7);
  if ( rx_rate_field_parse(2u) )
  {
    *v6 = 8;
    ke_msg_send_2((int)v6);
    return 0;
  }
  else
  {
    if ( **(volatile int16_t **)off_12B104 < 0 && !*(volatile uint8_t *)(a2 + 367) )
      mmio_clear_register((int)aParamChanCnt0, (int)aScanStartReqHa_0, 73);
    v8 = (void *)(uintptr_t)(off_12B108);
    *v6 = 0;
    *(volatile uint32_t *)v8 = a2;
    v8[10] = 0;
    *((volatile uint16_t *)v8 + 4) = a4;
    controller_get_event(a2);
    ke_msg_send_2((int)v6);
    return 1;
  }
}


// ke_msg_handler_lookup @ 0x12b114
int ke_msg_handler_lookup(volatile uint16_t *a1) {
  int v1; // r3
  int result; // r0

  v1 = *a1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B16C + 16);
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



// rf_env_reset @ 0x12b170
int rf_env_reset() {
  int result; // r0
  volatile uint32_t *v1; // r3

  memset((volatile int *)dword_12B198, 0, 0xCu);
  result = rx_phy_status_parse(2u, 0);
  v1 = (void *)(uintptr_t)(off_12B19C);
  *(volatile uint32_t *)off_12B19C = dword_12B1A0;
  v1[2] = (int)(uintptr_t)(v1 + 5);
  v1[4] = 0;
  v1[1] = 0;
  return result;
}


// ke_timer_setup @ 0x12b1a4
int ke_timer_setup() {
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

  v0 = (void *)(uintptr_t)(off_12B264);
  v1 = *(volatile uint32_t *)off_12B264;
  v2 = *(volatile uint32_t *)off_12B264 + 6 * *((volatile uint8_t *)off_12B264 + 10);
  v3 = 6 * *((volatile uint8_t *)off_12B264 + 10);
  v4 = *(volatile uint8_t *)(v2 + 3);
  if ( (v4 & 5) != 0 )
  {
    v5 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12B268 + 20);
    if ( !v5 )
    {
      v5 = dword_12B26C;
      goto LABEL_4;
    }
  }
  else
  {
    v5 = ke_msg_handler_lookup((volatile uint16_t *)(*(volatile uint32_t *)off_12B264 + 6 * *((volatile uint8_t *)off_12B264 + 10)));
    if ( !v5 )
    {
      v5 = 30000;
      goto LABEL_4;
    }
  }
  if ( (v4 & 1) == 0 && *((volatile uint8_t *)off_12B274 + 3850) == 1 )
    v5 += 170000;
LABEL_4:
  wlc_check_chip_ready((volatile int16_t *)v2, v5, *(volatile uint8_t *)(v1 + 366));
  v6 = v0[1];
  if ( v6 )
  {
    v7 = *(volatile uint8_t *)(v2 + 2);
    v8 = *(volatile uint16_t *)(v1 + v3);
    if ( *(volatile uint8_t *)(v2 + 2) )
    {
      if ( v7 == 1 && (v10 = v8 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(volatile uint8_t *)(v6 + 2) = (unsigned int)(((unsigned int)dword_12B270 * (uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
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
          return rx_phy_status_parse(2u, 2);
        }
        v7 = (v7 & ~0xFFu) | ((uint8_t)((unsigned int)(((unsigned int)dword_12B270 * (uint64_t)(unsigned int)(v8 - 2407)) >> 32) >> 2) & 0xFFu);
      }
      *(volatile uint8_t *)(v6 + 2) = v7;
    }
  }
  return rx_phy_status_parse(2u, 2);
}


// controller_get_event @ 0x12b278
int controller_get_event(int a1) {
  volatile uint32_t *v1; // r6
  volatile char *v2; // r4
  int result; // r0

  v1 = (void *)(uintptr_t)(off_12B2A8);
  v2 = (volatile char *)off_12B2AC;
  v1[1] = (int)(uintptr_t)(check_one_12db60((void *)(uintptr_t)(off_12B2AC), *(volatile uint16_t *)(*(volatile uint32_t *)off_12B2A8 + 364)));
  result = ke_timer_setup();
  *(volatile uint32_t *)&v2[-8] = *(volatile uint32_t *)&v2[-12] - 1 + *(volatile uint16_t *)(a1 + 364);
  *((volatile uint32_t *)v2 - 1) = 0;
  return result;
}



// link_get_connection_info @ 0x12b2b0
int link_get_connection_info(int a1, int a2, int a3) {
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

  v3 = dword_12B390;
  v4 = dword_12B390 + 1320 * a1;
  v6 = *(volatile uint8_t *)(v4 + 116);
  if ( *(volatile uint8_t *)(v4 + 1224) )
  {
    result = (int)(uintptr_t)(ke_mutex_guard(1, 26));
    v12 = result;
    if ( result )
    {
LABEL_5:
      v13 = (void *)(uintptr_t)(off_12B394);
      v14 = dword_12B38C + 696 * v6;
      v15 = *(volatile uint64_t *)(result + 72);
      v16 = *((volatile uint16_t *)off_12B394 + 254);
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
      return tx_path_status(v12, 5);
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(v4 + 72);
    v10 = *(volatile uint8_t *)(v9 + 4);
    if ( *(volatile uint8_t *)(v9 + 4) )
      v10 = 1;
    result = (int)(uintptr_t)(ke_mutex_guard(v10, 26));
    v12 = result;
    if ( result )
      goto LABEL_5;
  }
  return result;
}



// controller_read_features @ 0x12b398
void controller_read_features() {
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

  v0 = *(volatile uint32_t *)off_12B4D0;
  v22 = *((volatile uint8_t *)off_12B4D0 + 10);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_12B4D0 + 368) )
  {
    v21 = dword_12B4D4 + 1320 * *(volatile uint8_t *)(*(volatile uint32_t *)off_12B4D0 + 366);
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
      v4 = (int)(uintptr_t)(ke_mutex_guard(v3, *(volatile uint16_t *)(v0 + 364) + (uint8_t)*(v1 - 1) + 26));
      v5 = v1;
      v6 = v4;
      if ( !v4 )
        break;
      v7 = (void *)(uintptr_t)(off_12B4DC);
      v8 = *(volatile uint32_t *)(v4 + 72);
      v9 = *((volatile uint16_t *)off_12B4DC + 254);
      v10 = (volatile int *)off_12B4E0;
      v11 = *(volatile uint32_t *)(v4 + 76);
      v12 = *((volatile uint16_t *)off_12B4E0 + 2);
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
      *(volatile uint32_t *)(v11 + 24) = dword_12B4D8;
      *(volatile uint32_t *)(v11 + 32) = v20 - v19;
      *(volatile uint32_t *)(v6 + 88) = 0;
      *(volatile uint32_t *)(v6 + 92) = 0;
      *(volatile uint8_t *)(v6 + 28) = *(volatile uint8_t *)(v0 + 366);
      *(volatile uint8_t *)(v6 + 29) = -1;
      tx_path_status(v6, 5);
      ++v2;
      v1 += 33;
    }
    while ( *(volatile uint8_t *)(v0 + 368) > v2 );
  }
}



// reg_read_indirect @ 0x12b4e4
volatile uint32_t * reg_read_indirect(char a1, uint16_t a2) {
  volatile char *v3; // r4

  v3 = (volatile char *)ke_msg_alloc(2052, a2, 2, 1);
  check_status_bits(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return ke_msg_send_2((int)v3);
}


// get_queue_entry_ptr @ 0x12b514
int get_queue_entry_ptr() {
  return *(volatile uint32_t *)off_12B524 + 6 * *((volatile uint8_t *)off_12B524 + 10);
}



// rx_get_packet @ 0x12b528
int rx_get_packet(int a1) {
  if ( (*(volatile uint8_t *)(a1 + 3) & 5) != 0 )
    return *(volatile uint32_t *)(*(volatile uint32_t *)off_12B53C + 20);
  else
    return ke_msg_handler_lookup((volatile uint16_t *)a1);
}



// read_cal_value @ 0x12b540
int read_cal_value() {
  volatile uint32_t *v0; // r4
  unsigned int v1; // r2
  int result; // r0

  if ( **(volatile int16_t **)off_12B588 < 0 && *(volatile uint32_t *)off_12B594 << 28 )
    return bad_func_0x12f408((int)aNxmacCurrentSt, (int)aHalMachwIdleIr, 105);
  if ( (*(volatile uint32_t *)off_12B58C & 0x80) != 0 )
  {
    v0 = (void *)(uintptr_t)(off_12B590);
    v1 = *((volatile uint32_t *)off_12B590 + 1) & 0xFFFFFFFB;
    *(volatile uint32_t *)off_12B58C &= ~0x80u;
    v0[1] = v1;
    return unknown_func_12d104(0x2000000);
  }
  return result;
}


// rf_get_irq_status @ 0x12b5a0
unsigned int rf_get_irq_status(unsigned int result) {
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

  v1 = (volatile unsigned int *)off_12B7C8;
  v2 = (uint8_t)*(volatile uint32_t *)off_12B7C8;
  if ( result != v2 )
  {
    v3 = dword_12B7CC;
    v4 = dword_12B7D0;
    v5 = dword_12B800;
    *(volatile uint32_t *)off_12B7FC = ((0xF0 / result) << 8) & 0xF00 | *(volatile uint32_t *)off_12B7FC & 0xFFFFF0FF;
    *v1 = *v1 & 0xFFFFFF00 | result;
    *v1 = v3 & ((result * ((*v1 >> 8) & 0x3FF) / v2) << 8) | *v1 & 0xFFFC00FF;
    v6 = result;
    *v1 = v4 & ((result * ((*v1 >> 18) & 0x3FF) / v2) << 18) | *v1 & v5;
    if ( result == 240 )
    {
      v21 = double_add(*(volatile uint64_t *)&dword_12B7C0);
      v22 = ((int (*)(uint64_t))double_to_int)(v21);
      v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(dword_12B7F8) << 32);
      *v1 = v4 & (v22 << 18) | *v1 & v5;
      v24 = (volatile unsigned int *)off_12B7DC;
      v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
      v25 = double_add(v23);
      *v24 = dword_12B7E0 & (((int (*)(uint64_t))double_to_int)(v25) << 20) | *v24 & 0xC00FFFFF;
    }
    else
    {
      v7 = int_to_double(result);
      v8 = ((uint64_t (*)())double_add_1)(v7, *(volatile uint64_t *)&dword_12B7B8);
      v9 = ((int (*)(uint64_t))double_to_uint)(v8);
      v10 = ((uint64_t (*)())float_to_double)(v9);
      v11 = double_add(v10);
      *v1 = v4 & (((int (*)(uint64_t))double_to_int)(v11) << 18) | *v1 & v5;
    }
    v12 = (volatile unsigned int *)off_12B7DC;
    *(volatile uint32_t *)off_12B7D4 = dword_12B7D8 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12B7D4 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12B7D4 & 0xFF0000FF;
    *v12 = dword_12B7E0 & ((v6 * ((*v12 >> 20) & 0x3FF) / v2) << 20) | *v12 & 0xC00FFFFF;
    *v12 = (v6 * (*v12 & 0x3FF) / v2) & 0x3FF | *v12 & 0xFFFFFC00;
    if ( v6 <= 0x1D )
    {
      v12[1] |= 3u;
    }
    else
    {
      v13 = *(volatile uint32_t *)off_12B7E4 & 0xFFFFFFFC;
      if ( v6 > 0x3B )
        v14 = v13 | 1;
      else
        v14 = v13 | 2;
      *(volatile uint32_t *)off_12B7E4 = v14;
    }
    v15 = (void *)(uintptr_t)(off_12B7E8);
    v16 = dword_12B7D8;
    v17 = dword_12B7EC;
    v18 = (volatile unsigned int *)off_12B7F0;
    *(volatile uint32_t *)off_12B7E8 = dword_12B7D8 & ((v6 * (uint16_t)(*(volatile uint32_t *)off_12B7E8 >> 8) / v2) << 8)
                          | *(volatile uint32_t *)off_12B7E8 & dword_12B7EC;
    *v18 = v16 & ((v6 * (uint16_t)(*v18 >> 8) / v2) << 8) | v17 & *v18;
    v19 = (volatile unsigned int *)off_12B7F4;
    v20 = dword_12B7E0;
    v15[2] = (uint16_t)v15[2] | (v6 << 19);
    *v19 = v20 & ((v6 * ((*v19 >> 20) & 0x3FF) / v2) << 20) | *v19 & 0xC00FFFFF;
    result = *v19 & 0x3FF;
    *v19 = (v6 * result / v2) & 0x3FF | *v19 & 0xFFFFFC00;
  }
  return result;
}


// read_cal_trim @ 0x12b804
int read_cal_trim() {
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

  if ( **(volatile int16_t **)off_12B87C < 0 && !(*(volatile uint32_t *)off_12B898 << 28) )
    return bad_func_0x12f408((int)aNxmacCurrentSt_0, (int)aHalMachwIdleRe, 213);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12B880 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12B888);
  v1 = REG_4032_0120;
  v2 = *(volatile uint32_t *)off_12B888;
  v3 = (void *)(uintptr_t)(off_12B88C);
  v4 = (void *)(uintptr_t)(off_12B890);
  v5 = (void *)(uintptr_t)(off_12B894);
  v6 = (void *)(uintptr_t)(off_12B898);
  result = *(volatile uint32_t *)off_12B888 + 1;
  *(volatile uint32_t *)off_12B888 = result;
  *v3 = v1 + 25000;
  v8 = (void *)(uintptr_t)(off_12B89C);
  *v4 = 128;
  v9 = v8[1] | 4;
  *v5 |= 0x80u;
  v8[1] = v9;
  *v6 = 0;
  if ( result )
  {
    v10 = (volatile int *)off_12B880;
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


// mmio_write_one @ 0x12b8a8
void mmio_write_one() {
  volatile uint32_t *v0; // r2

  v0 = (void *)(uintptr_t)(off_12B8B8);
  *(volatile uint32_t *)off_12B8B8 = 1;
  while ( (uint8_t)*v0 )
    ;
}



// bb_enable_1 @ 0x12b8bc
int bb_enable_1() {
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
  v0 = (void *)(uintptr_t)(off_12BAB4);
  *(volatile uint32_t *)off_12BAB4 = 1;
  while ( (uint8_t)*v0 )
    ;
  v1 = get_status_byte();
  rf_get_irq_status(v1);
  v2 = (void *)(uintptr_t)(off_12BABC);
  *(volatile uint32_t *)off_12BAB8 = dword_12BAC0;
  v3 = (void *)(uintptr_t)(off_12BAC4);
  *v2 = 0x80000000;
  v4 = (volatile int16_t **)off_12BAC8;
  *v3 &= ~0x800u;
  if ( **v4 < 0 && *(volatile uint32_t *)off_12BACC < 0x2F000000u )
    mmio_clear_register(dword_12BB18, dword_12BB14, 284);
  v5 = (volatile char *)off_12BACC;
  v6 = (volatile int *)off_12BAD0;
  v7 = (void *)(uintptr_t)(off_12BAC4);
  v8 = dword_12BAD8;
  *(volatile uint32_t *)off_12BACC = dword_12BAD4;
  *v6 = v8;
  v9 = (volatile int *)off_12BADC;
  v10 = dword_12BAE0;
  *v7 |= 0x40007C0u;
  *v7 &= ~0x4000000u;
  v11 = (void *)(uintptr_t)(off_12BAE4);
  v12 = v6 - 8199;
  *(volatile uint32_t *)&v5[-132] |= 0x10000u;
  *v9 = v10;
  *v12 |= 0xFF000000;
  *v12 |= 0x800000u;
  *v12 = *v12 & 0xFF80FFFF | 0x100000;
  if ( !v11[2] )
    *v12 = (HIWORD(*v12) << 16) | 0x64;
  v13 = (void *)(uintptr_t)(off_12BAE8);
  v14 = (void *)(uintptr_t)(off_12BAC4);
  v15 = (volatile unsigned int *)off_12BAF0;
  *(volatile uint32_t *)off_12BAEC = 12288;
  *v13 = 0;
  get_calibration_offsets(&_frame.v26, &_frame.v25);
  v16 = (void *)(uintptr_t)(off_12BAF8);
  *(volatile uint32_t *)off_12BAF4 = (_frame.v26 << 8) | (_frame.v25 << 16) | _frame.v26;
  v17 = (void *)(uintptr_t)(off_12BAFC);
  *v14 |= 0x1000u;
  *v14 |= 0x2000u;
  *v16 |= 0x80000u;
  *v16 &= ~0x80u;
  result = rf_get_field4();
  v19 = (void *)(uintptr_t)(off_12BB00);
  *v15 = ((result + 1) << 26) & 0x1C000000 | *v15 & 0xE3FFFFFF;
  v20 = (volatile uint8_t **)off_12BB04;
  *v14 |= 0x20u;
  *v17 &= ~1u;
  *v19 |= 2u;
  if ( **v20 == 1 )
    *(volatile uint32_t *)off_12BB08 &= 0x80FFFFFF;
  v21 = (void *)(uintptr_t)(off_12BAC4);
  v22 = (void *)(uintptr_t)(off_12BB0C);
  *(volatile uint32_t *)off_12BAC4 |= 0x2000000u;
  if ( (*v22 & 0x20000) != 0 )
  {
    result = rf_get_status_bit28();
    if ( result )
    {
      v23 = rf_get_field8();
      v24 = (volatile unsigned int *)off_12BB1C;
      result = v23 << 8;
      *(volatile uint32_t *)off_12BB1C = result & 0x700 | *(volatile uint32_t *)off_12BB1C & 0xFFFFF8FF;
      *v24 = *v24 & 0xFFFFFF1F | 0x60;
      *v24 |= 4u;
      *v24 |= 1u;
      if ( (*v22 & 0x8000) != 0 )
      {
        result = rf_get_status_bit21();
        if ( result )
        {
          *v21 |= 0x80000u;
          *v24 = *v24 & 0xF1FFFFFF | 0x4000000;
        }
      }
      if ( (*(volatile uint32_t *)off_12BB0C & 0x20000) != 0 )
      {
        result = rf_get_status_bit30();
        if ( result )
          *(volatile uint32_t *)off_12BB1C |= 2u;
      }
    }
  }
  *(volatile uint32_t *)off_12BB10 |= 1u;
  return result;
}



// mmio_clear_irqs @ 0x12bb20
void *mmio_clear_irqs() {
  void *result; // r0
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2

  result = (void *)(uintptr_t)(off_12BB40);
  v1 = (void *)(uintptr_t)(off_12BB44);
  v2 = (void *)(uintptr_t)(off_12BB48);
  *(volatile uint32_t *)off_12BB40 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}



// rf_clear_status @ 0x12bb4c
volatile int *rf_clear_status() {
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

  v0 = (void *)(uintptr_t)(off_12BBD0);
  v1 = (void *)(uintptr_t)(off_12BBD4);
  *(volatile uint32_t *)off_12BBCC &= ~0x80u;
  *v0 = 0;
  *v1 = 60;
  while ( *v0 << 28 )
    ;
  v2 = (void *)(uintptr_t)(off_12BBD4);
  v3 = (void *)(uintptr_t)(off_12BBD8);
  v4 = (void *)(uintptr_t)(off_12BBDC);
  v5 = (volatile int *)off_12BBE0;
  v6 = dword_12BBE4;
  *(volatile uint32_t *)off_12BBD4 |= 0x10000u;
  *v3 &= 0xFFFFFF00;
  *v4 = -1;
  *v5 = v6;
  v7 = (void *)(uintptr_t)(off_12BBE8);
  v8 = (void *)(uintptr_t)(off_12BBEC);
  v2[8200] |= 0x80000000;
  v9 = v7[1];
  v4[1] |= 0x80000000;
  result = v5 - 8201;
  *v8 |= 0x80000000;
  *result |= 0x80u;
  v7[1] = v9 & 0xFFFFFFFB;
  return result;
}



// fifo_write @ 0x12bbf0
int fifo_write(volatile int *a1) {
  volatile uint32_t *v1; // r2
  volatile int *v2; // r3
  int v3; // r4
  int v4; // r0
  int v5; // r0

  v1 = (void *)(uintptr_t)(off_12BC24);
  v2 = (volatile int *)off_12BC28;
  v3 = *a1;
  v4 = *((volatile uint16_t *)a1 + 2);
  *(volatile uint32_t *)off_12BC20 = v3;
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



// mmio_disable_bit @ 0x12bc2c
unsigned int mmio_disable_bit() {
  volatile uint32_t *v0; // r2
  volatile uint32_t *v1; // r0
  volatile int16_t **v2; // r5
  volatile int *v3; // r4
  int v4; // r3
  volatile int16_t *v5; // r2
  unsigned int result; // r0
  volatile uint32_t *v7; // r2

  v0 = (void *)(uintptr_t)(off_12BC9C);
  v1 = (void *)(uintptr_t)(off_12BCA0);
  *(volatile uint32_t *)off_12BC9C &= ~1u;
  v2 = (volatile int16_t **)off_12BCA4;
  v3 = (volatile int *)off_12BCA8;
  v4 = dword_12BCAC;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(volatile uint32_t *)off_12BCB4 << 28 )
  {
    call_shared_handler(dword_12BCBC, dword_12BCB8, 472);
    v4 = *v3;
  }
  *(volatile uint32_t *)off_12BCB0 = v4 | v3[1];
  result = radio_set_peripheral_field(1);
  v7 = (void *)(uintptr_t)(off_12BCA0);
  *(volatile uint32_t *)off_12BCA0 = *(volatile uint32_t *)off_12BCA0 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}



// util_abs @ 0x12bcc0
int util_abs(int a1) {
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
    *(volatile uint32_t *)off_12BD30 = 1;
  }
  v2 = (void *)(uintptr_t)(off_12BD34);
  v3 = *(volatile uint32_t *)off_12BD34;
  v4 = *(volatile uint32_t *)off_12BD38;
  v5 = *(volatile uint32_t *)off_12BD34 + 1;
  v6 = *(volatile uint32_t *)off_12BD3C;
  *(volatile uint32_t *)off_12BD34 = v5;
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
  v8 = (volatile int *)off_12BD3C;
  v9 = (volatile int *)off_12BD38;
  v10 = *(volatile uint32_t *)off_12BD3C - a1;
  *(volatile uint32_t *)off_12BD3C = v10;
  *v9 = v7;
  *v8 = v10;
  *v9 = v7;
  *v8 = v10;
  result = 0;
  *v9 = v7;
LABEL_6:
  if ( v5 )
  {
    v12 = (volatile int *)off_12BD30;
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



// rf_read_irq_flags @ 0x12bd40
int rf_read_irq_flags() {
  int v0; // r4
  int v1; // r5
  volatile uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  volatile uint32_t *v6; // r3

  v0 = (*(volatile uint32_t *)off_12BE18 >> 25) & 1;
  if ( (*(volatile uint32_t *)off_12BE18 & 0x2000000) == 0
    && (int)(32 * *(volatile uint32_t *)off_12BE20
     - 2000
     - *((volatile uint16_t *)off_12BE24 + 92)
     - *((volatile uint16_t *)off_12BE24 + 93)) < 0 )
  {
    return v0;
  }
  v1 = *(volatile uint32_t *)off_12BE28;
  if ( !*(volatile uint32_t *)off_12BE28 )
    return 1;
  v2 = (volatile uint16_t *)off_12BE24;
  v3 = *(volatile uint32_t *)(v1 + 12);
  v4 = *((volatile uint16_t *)off_12BE24 + 93);
  if ( (int)(v3 - *((volatile uint32_t *)off_12BE1C + 4) - 2000 - *((volatile uint16_t *)off_12BE24 + 92) - v4) < 0 )
  {
    if ( **(volatile int16_t **)off_12BE30 < 0 && (int)(v3 - *((volatile uint32_t *)off_12BE1C + 4) + 5000) < 0 )
    {
      mmio_clear_register(dword_12BE38, dword_12BE34, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(volatile uint8_t **)off_12BE2C != 1 )
      return 1;
    if ( **(volatile int16_t **)off_12BE30 < 0 && (int)(v3 - *((volatile uint32_t *)off_12BE1C + 4) - v4) < 0 )
    {
      mmio_clear_register(dword_12BE3C, dword_12BE34, 580);
      v3 = *(volatile uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = (void *)(uintptr_t)(off_12BE1C);
    *((volatile uint32_t *)off_12BE1C + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}



// util_unknown @ 0x12be40
int util_unknown() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int result; // r0
  int v3; // r4
  volatile uint32_t *v4; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12BE7C = 1;
  }
  v0 = (void *)(uintptr_t)(off_12BE80);
  v1 = *(volatile uint32_t *)off_12BE80;
  result = *(volatile uint32_t *)off_12BE88;
  v3 = *(volatile uint32_t *)off_12BE80 + 1;
  *(volatile uint32_t *)off_12BE80 = v3;
  if ( v3 )
  {
    v4 = (void *)(uintptr_t)(off_12BE7C);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v4 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_copy_reg @ 0x12be8c
int mmio_copy_reg() {
  int v0; // r4
  int result; // r0
  volatile int *v2; // r4
  int v3; // r1

  v0 = *(volatile uint32_t *)off_12BFA4;
  *(volatile uint32_t *)off_12BFA8 = *(volatile uint32_t *)off_12BFA4;
  result = v0 << 21;
  if ( (v0 & 0x400) != 0 )
  {
    event_dispatch(aErrorThereIsNo_0);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x100) == 0 )
  {
    if ( (v0 & 0x200) == 0 )
      goto LABEL_4;
LABEL_13:
    event_dispatch(aErrorThereIsNo);
    while ( 1 )
      ;
  }
  result = rf_counter_get();
  if ( (v0 & 0x200) != 0 )
    goto LABEL_13;
LABEL_4:
  if ( (v0 & 0x10) != 0 )
  {
    mmio_set_bit_1(4);
    result = phy_band_validate(4u);
  }
  if ( (v0 & 0x2F) != 0 )
  {
    if ( *(volatile uint8_t *)off_12BFAC )
    {
      v2 = (volatile int *)off_12BFD0;
      write_phy_config(HIBYTE(((volatile uint32_t *)(uintptr_t)off_12BFD0)[102]));
      v3 = *((volatile char *)v2 + 411);
      *((volatile uint8_t *)off_12BFD4 + 9) = v3;
      return event_dispatch("update:%d\n", v3);
    }
    if ( *(volatile uint8_t *)off_12BFB0 )
    {
      result = *(volatile uint32_t *)off_12BFB4 << 28;
      if ( result )
        *((volatile uint8_t *)off_12BFB0 + 6) = 1;
    }
  }
  if ( **(volatile int16_t **)off_12BFB8 < 0 )
  {
    if ( (v0 & 1) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_0, (int)aHalMachwAbsTim, 760);
    }
    else if ( (v0 & 2) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_5, (int)aHalMachwAbsTim, 761);
    }
    else if ( (v0 & 4) != 0 )
    {
      return bad_func_0x12f408((int)aTimerPendingHa_4, (int)aHalMachwAbsTim, 762);
    }
    else
    {
      result = v0 << 28;
      if ( (v0 & 8) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_3, (int)aHalMachwAbsTim, 763);
      }
      else if ( (v0 & 0x80) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_2, (int)aHalMachwAbsTim, 765);
      }
      else if ( (v0 & 0x40) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa_1, (int)aHalMachwAbsTim, 767);
      }
      else if ( (v0 & 0x20) != 0 )
      {
        return bad_func_0x12f408((int)aTimerPendingHa, (int)aHalMachwAbsTim, 769);
      }
    }
  }
  return result;
}


// irq_combined_status @ 0x12bff0
void irq_combined_status() {
  int v0; // r4
  int v1; // r3
  int v2; // r5

  v0 = *(volatile uint32_t *)off_12C188 & *(volatile uint32_t *)off_12C184;
  v1 = dword_12C18C & v0;
  *((volatile uint32_t *)off_12C184 + 1) = v0;
  if ( v1 )
    unknown_func_12d104(0x1000000);
  if ( (dword_12C190 & v0) != 0 )
    unknown_func_12d104(0x800000);
  if ( (v0 & 4) != 0 )
    read_cal_value();
  if ( (v0 & 8) != 0 )
    mmio_copy_reg();
  if ( (v0 & 0x10000000) != 0 )
  {
    v2 = *(volatile uint32_t *)off_12C1A0;
    *((volatile uint8_t *)off_12C1A4 + 30) |= *(volatile uint8_t *)off_12C1A0 & 0x3F;
    unknown_func_12d104(0x40000);
    *(volatile uint32_t *)off_12C1A8 = v2;
  }
  if ( **(volatile int16_t **)off_12C194 < 0 )
  {
    if ( (v0 & 0x400000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_0, (int)aHalMachwGenHan, 847);
    }
    else if ( (v0 & 0x200000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_1, (int)aHalMachwGenHan, 848);
    }
    else if ( (v0 & 0x40) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_2, (int)aHalMachwGenHan, 849);
    }
    else if ( (v0 & 0x100) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_3, (int)aHalMachwGenHan, 850);
    }
    else if ( (v0 & 0x1000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_4, (int)aHalMachwGenHan, 851);
    }
    else if ( (v0 & 0x2000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_5, (int)aHalMachwGenHan, 852);
    }
    else if ( (v0 & 0x4000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_6, (int)aHalMachwGenHan, 853);
    }
    else if ( (v0 & 0x8000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_7, (int)aHalMachwGenHan, 854);
    }
    else if ( (v0 & 0x10000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_8, (int)aHalMachwGenHan, 855);
    }
    else if ( (v0 & 0x20000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_9, (int)aHalMachwGenHan, 856);
    }
    else if ( (v0 & 0x1000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_10, (int)aHalMachwGenHan, 857);
    }
    else if ( (v0 & 0x2000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_11, (int)aHalMachwGenHan, 858);
    }
    else if ( (v0 & 0x100000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN_12, (int)aHalMachwGenHan, 859);
    }
    else if ( (v0 & 0x8000000) != 0 )
    {
      bad_func_0x12f408((int)aGenirqPendingN, (int)aHalMachwGenHan, 860);
    }
  }
}


// ipc_lock_acquire @ 0x12c1e0
void ipc_lock_acquire(int a1, int a2) {
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

  v2 = *(volatile uint32_t *)dword_12C304 & *(volatile uint32_t *)dword_12C308;
  *(volatile uint32_t *)(dword_12C304 + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (volatile uint32_t *)dword_12C30C;
    v4 = (volatile uint32_t *)dword_12C310;
    v5 = *(volatile uint32_t *)dword_12C30C;
    v6 = *(volatile uint32_t *)dword_12C310;
    if ( (v2 & 1) != 0 && !*(volatile uint8_t *)(dword_12C314 + 0x24) )
    {
      *(volatile uint32_t *)dword_12C30C = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      *v4 = v6 | 0xF00000;
      event_dispatch(aWf);
    }
    else
    {
      v7 = (volatile uint32_t *)dword_12C310;
      *(volatile uint32_t *)dword_12C30C = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      event_dispatch(aBt);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(volatile uint32_t *)dword_12C31C & 1) != 0 )
    {
      *(volatile uint32_t *)dword_12C320 |= 0x400000u;
      v8 = (*(volatile uint32_t *)0x40501010u);
      do
        v9 = v8 + 3 - (*(volatile uint32_t *)0x40501010u);
      while ( v9 >= 0 );
      v10 = (volatile uint32_t *)dword_12C32C;
      v11 = (volatile uint32_t *)dword_12C330;
      *(volatile uint32_t *)dword_12C328 = *(volatile uint32_t *)dword_12C328 & 0xFFFE1FFF | 0xE000;
      *v10 |= 1u;
      *v11 = 0;
      do
        v12 = v8 + 4 - (*(volatile uint32_t *)0x40501010u);
      while ( v12 >= 0 );
      v13 = (volatile uint32_t *)dword_12C330;
      *(volatile uint32_t *)dword_12C31C &= ~1u;
      *v13 = 1;
      do
        v14 = v8 + 5 - (*(volatile uint32_t *)0x40501010u);
      while ( v14 >= 0 );
      *(volatile uint32_t *)dword_12C330 = 0;
      do
        v15 = v8 + 6 - (*(volatile uint32_t *)0x40501010u);
      while ( v15 >= 0 );
      v16 = (volatile uint32_t *)dword_12C330;
      *(volatile uint32_t *)dword_12C31C |= 1u;
      v17 = v8 + 36;
      *v16 = 1;
      do
        v18 = v17 - (*(volatile uint32_t *)0x40501010u);
      while ( v18 >= 0 );
      *(volatile uint32_t *)dword_12C320 &= 0xFF9FFFFF;
      event_dispatch(aUnlock, REG_4050_1000);
    }
    else
    {
      *(volatile uint32_t *)dword_12C32C |= 1u;
      event_dispatch(aUnlock, a2);
    }
  }
}


// lock_core_pair @ 0x12c33c
int lock_core_pair() {
  int v0; // r4

  v0 = dword_12C354;
  zero_8_bytes((void *)(uintptr_t)(dword_12C354));
  return (int)(uintptr_t)(zero_8_bytes((void *)(uintptr_t)(v0 + 8)));
}



