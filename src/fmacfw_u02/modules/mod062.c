// bt_rx_process @ 0x136478
int bt_rx_process(int a1, int a2, int a3, int a4) {
  int v4; // r8
  uint16_t v6; // r7
  uint16_t v7; // r9
  int v8; // r6
  int v9; // r5
  char v10; // r5
  volatile char *v11; // r0
  char v13; // r2
  int16_t v14; // r3
  int v15; // r3
  volatile uint8_t *v16; // r10
  char v17; // r2
  int v18; // r1
  int16_t v19; // r2
  int v20; // r9
  int v21; // r3
  unsigned int v22; // r2
  volatile uint32_t *v23; // r0
  unsigned int v24; // r0
  struct __attribute__((packed)) { uint8_t a2a; // [sp+3h] [bp-11h] BYREF
  int a1a; // [sp+4h] [bp-10h] BYREF
  int v27; // [sp+8h] [bp-Ch]
  uint16_t v28; // [sp+Ch] [bp-8h]
  } _frame;
  v4 = dword_136660;
  v6 = a3;
  v7 = a4;
  check_status_bits(256, "ap start:%d, radar=%d\r\n", *(volatile uint32_t *)(a2 + 20), BYTE1(((volatile uint32_t *)(uintptr_t)off_13663C)[103]));
  v8 = *(volatile uint8_t *)(a2 + 51);
  v9 = v4 + 1320 * v8;
  if ( *(volatile uint8_t *)(v9 + 106) != 2 )
  {
    v10 = 4;
LABEL_3:
    v11 = (volatile char *)ke_msg_alloc(7169, v7, v6, 4);
    *v11 = v10;
    v11[1] = *(volatile uint8_t *)(a2 + 51);
    ke_msg_send_2((int)v11);
    return 0;
  }
  if ( rx_rate_field_parse(7u) )
  {
    v10 = 8;
    goto LABEL_3;
  }
  if ( *(volatile uint8_t *)(v9 + 108) )
  {
    v10 = 9;
    goto LABEL_3;
  }
  if ( **(volatile int16_t **)off_136644 < 0 && *(volatile uint32_t *)(v9 + 72) )
    mmio_clear_register((int)aVifChanCtxtNul_0, (int)aApmStartReqHan, 105);
  v13 = *(volatile uint8_t *)(a2 + 28);
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 16)) & 0xFFu);
  v14 = *(volatile uint16_t *)(a2 + 14);
  _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(v13) & 0xFFu);
  _frame.a1a = (_frame.a1a & ~0xFFFF0000u) | (((uint16_t)(v14) & 0xFFFFu) << 16);
  v15 = *(volatile uint32_t *)(a2 + 24);
  v16 = (void *)(uintptr_t)(off_136664);
  _frame.v27 = (_frame.v27 & ~0xFFFFu) | ((uint16_t)(*(volatile uint32_t *)(a2 + 20)) & 0xFFFFu);
  v17 = *(volatile uint8_t *)(a2 + 18);
  _frame.v27 = (_frame.v27 & ~0xFFFF0000u) | (((uint16_t)(v15) & 0xFFFFu) << 16);
  v15 = (v15 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 17)) & 0xFFu);
  *(volatile uint32_t *)off_136664 = a2;
  _frame.v28 = (_frame.v28 & ~0xFFu) | ((uint8_t)(v17) & 0xFFu);
  _frame.v28 = (_frame.v28 & ~0xFF00u) | (((uint8_t)(v15) & 0xFFu) << 8);
  if ( scan_find_empty_slot((volatile uint8_t *)&_frame.a1a, &_frame.a2a) )
  {
    v10 = 1;
    goto LABEL_3;
  }
  v18 = _frame.v27;
  v19 = _frame.v28;
  v20 = v4 + 1320 * v8;
  *(volatile uint32_t *)(v20 + 412) = _frame.a1a;
  *(volatile uint32_t *)(v20 + 416) = v18;
  *(volatile uint8_t *)(v20 + 464) = 0;
  *(volatile uint16_t *)(v20 + 420) = v19;
  rf_temperature_comp(v20);
  if ( BYTE1(_frame.a1a) == 2 )
    is_valid_id((volatile int *)(v4 + 1320 * v8), 1, 0);
  sta_lookup_by_bss(*(volatile uint8_t *)(a2 + 51), _frame.a2a);
  if ( *((volatile uint8_t *)off_136650 + 18) + *((volatile uint8_t *)off_136650 + 17) == 1
    && !*(volatile uint8_t *)(v4 + 1320 * v8 + 1224) )
  {
    *(volatile uint8_t *)off_13665C = 0;
    set_bt_irq_flag();
  }
  if ( !*(volatile uint8_t *)(a2 + 16) )
  {
    v24 = bt_process_msg((volatile uint8_t *)(1320 * v8 + 424 + v4), 1) & 0xF;
    if ( v24 )
      *(volatile uint8_t *)(v4 + 1320 * v8 + 461) = 31 - __clz(v24);
    else
      *(volatile uint8_t *)(v4 + 1320 * v8 + 461) = 1;
  }
  ke_send_event_0x18();
  if ( !*(volatile uint32_t *)off_136654 )
  {
    v21 = v4 + 1320 * v8;
    v22 = *(volatile uint16_t *)(v21 + 416);
    if ( v22 <= 0x1387 )
      callback_post(v22 | (*(volatile uint8_t *)(v21 + 413) << 16) | 0x80000000);
  }
  v23 = (volatile uint32_t *)dword_136658;
  v16[14] = v16[15];
  v16[13] = 0;
  fault_handler((int)(uintptr_t)(v23));
  return 1;
}


// bt_get_buffer @ 0x136668
volatile uint32_t *bt_get_buffer() {
  if ( **(volatile int16_t **)off_13669C >= 0 || !*((volatile uint32_t *)off_1366A4 + 1) )
    return zero_8_bytes((volatile uint32_t *)dword_1366A0);
  mmio_clear_register(dword_1366A8, dword_1366AC, 46);
  return zero_8_bytes((volatile uint32_t *)dword_1366A0);
}



// bt_link_active @ 0x1366b0
volatile uint32_t * bt_link_active(volatile uint32_t *result) {
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r6
  int v3; // r3
  int v4; // r1

  if ( *((volatile uint8_t *)result + 108) )
  {
    v1 = result;
    if ( *((volatile uint8_t *)result + 412) == 1 )
    {
      v2 = (void *)(uintptr_t)(off_1366F8);
      if ( *((volatile uint8_t *)off_1366F8 + 13) )
      {
        *((volatile uint8_t *)off_1366F8 + 13) = 0;
        return rf_config();
      }
      else
      {
        ((int (*)())bt_init)();
        v3 = v2[4];
        v4 = *((volatile uint32_t *)off_1366FC + 4);
        *((volatile uint8_t *)v2 + 13) = 1;
        v2[7] = (int)(uintptr_t)(v1);
        return (volatile uint32_t *)unknown_worker((void *)(uintptr_t)((int)(v2 + 5)), v4 + v3);
      }
    }
  }
  return result;
}



// bt_cmd_buf_clear @ 0x136700
int bt_cmd_buf_clear() {
  volatile uint8_t *v0; // r4
  void *v1; // r3

  v0 = (void *)(uintptr_t)(off_13672C);
  memset((volatile int *)off_13672C, 0, 0x24u);
  v1 = (void *)(uintptr_t)(off_136730);
  v0[15] = 3;
  *((volatile uint32_t *)v0 + 4) = 20000;
  *((volatile uint32_t *)v0 + 6) = (int)(uintptr_t)(v1);
  v0[12] = 0;
  return rx_phy_status_parse(7u, 0);
}


// bt_vendor_send @ 0x136734
int bt_vendor_send(int a1) {
  volatile uint32_t *v1; // r8
  int v3; // r6
  volatile uint8_t *v4; // r4
  char v5; // r3
  int v7; // r7
  int v8; // r0
  int v9; // r9
  int16_t v10; // r2
  int v11; // r3
  int v12; // r12
  int v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r7
  char v17; // r3

  v1 = (void *)(uintptr_t)(off_136818);
  v3 = *(volatile uint32_t *)off_136818;
  v4 = (volatile uint8_t *)ke_msg_alloc(7169, 13, 7, 4);
  if ( a1 )
  {
    v5 = *(volatile uint8_t *)(v3 + 51);
  }
  else
  {
    v7 = *(volatile uint8_t *)(v3 + 51);
    v8 = ke_msg_alloc(30, 0, 7, 4);
    v9 = dword_136814 + 1320 * v7;
    *(volatile uint8_t *)(v8 + 2) = 1;
    *(volatile uint8_t *)(v8 + 3) = *(volatile uint8_t *)(v9 + 107);
    ke_msg_send_2(v8);
    v10 = *(volatile uint16_t *)(v3 + 48);
    v11 = *(volatile uint32_t *)(v9 + 72);
    *(volatile uint32_t *)(v9 + 1208) = *(volatile uint32_t *)(v3 + 44);
    *(volatile uint16_t *)(v9 + 236) = v10;
    *(volatile uint8_t *)(v9 + 234) = 0;
    v4[2] = *(volatile uint8_t *)(v11 + 24);
    v12 = dword_13681C;
    v4[3] = *(volatile uint8_t *)(v3 + 51) + 32;
    v13 = *(volatile uint32_t *)(v3 + 4);
    v14 = *(volatile uint32_t *)(v3 + 8);
    v15 = *(volatile uint32_t *)(v3 + 12);
    v16 = v12 + 696 * (v7 + 32);
    *(volatile uint32_t *)(v16 + 192) = *(volatile uint32_t *)v3;
    *(volatile uint32_t *)(v16 + 196) = v13;
    *(volatile uint32_t *)(v16 + 200) = v14;
    *(volatile uint8_t *)(v16 + 52) = 2;
    *(volatile uint8_t *)(v16 + 204) = v15;
    patch_check_version(v16);
    v17 = *(volatile uint8_t *)(v16 + 350);
    *(volatile uint16_t *)(v16 + 38) = 1;
    *(volatile uint8_t *)(v16 + 350) = v17 | 0x10;
    v5 = *(volatile uint8_t *)(v3 + 51);
    *(volatile uint8_t *)(v16 + 37) = 1;
    *(volatile uint8_t *)(v16 + 35) = v5 + 32;
  }
  v4[1] = v5;
  *v4 = a1;
  ke_msg_send_2((int)v4);
  branch_to_12cbc8((int)(uintptr_t)((volatile char *)(v3 - 12)));
  *v1 = 0;
  return rx_phy_status_parse(7u, 0);
}


// bt_ready_check @ 0x136820
int bt_ready_check() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r4

  v0 = mem_word_load(dword_136854);
  v1 = v0;
  if ( **(volatile int16_t **)off_136858 < 0 && !v0 )
    mmio_clear_register(dword_136860, dword_13685C, 210);
  return (int)(uintptr_t)(ke_msg_send_2((int)(v1 + 3)));
}



// ke_send_event_0x18 @ 0x136864
int ke_send_event_0x18() {
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  volatile uint8_t *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int v12; // r1
  volatile uint8_t *v14; // r0

  v0 = dword_136988;
  v1 = *(volatile uint32_t *)off_13697C;
  v2 = *(volatile uint8_t *)(*(volatile uint32_t *)off_13697C + 51);
  v3 = ke_msg_alloc(24, 0, 7, 8);
  v4 = ke_msg_alloc(22, 0, 7, 8);
  v5 = ke_msg_alloc(20, 0, 7, 4);
  v6 = v0 + 1320 * v2;
  v7 = (volatile uint8_t *)ke_msg_alloc(5143, 5, 7, 2);
  bt_get_buffer();
  if ( *(volatile uint8_t *)(v6 + 1224) )
  {
    *(volatile uint32_t *)off_136980 &= ~4u;
    *(volatile uint32_t *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v14 = (volatile uint8_t *)ke_msg_alloc(5145, 5, 7, 2);
    *v14 = 1;
    v14[1] = *(volatile uint8_t *)(v6 + 107);
    cmd_handler_a((int)off_13697C + 4, (volatile uint32_t *)v14 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(volatile uint32_t *)(v8 + 100);
  *(volatile uint16_t *)(v3 + 4) = *(volatile uint16_t *)(v8 + 104);
  *(volatile uint32_t *)v3 = v9;
  *(volatile uint8_t *)(v3 + 6) = *(volatile uint8_t *)(v1 + 51);
  cmd_handler_a(dword_136984, (volatile uint32_t *)(v3 - 12));
  *(volatile uint8_t *)(v4 + 5) = *(volatile uint8_t *)(v1 + 16);
  *(volatile uint32_t *)v4 = bt_process_msg((volatile uint8_t *)v1, 1);
  *(volatile uint8_t *)(v4 + 4) = *(volatile uint8_t *)(v1 + 51);
  cmd_handler_a(dword_136984, (volatile uint32_t *)(v4 - 12));
  *(volatile uint16_t *)v5 = *(volatile uint16_t *)(v1 + 40);
  *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 51);
  cmd_handler_a(dword_136984, (volatile uint32_t *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136984;
  v7[1] = *(volatile uint8_t *)(v1 + 51);
  v11 = cmd_handler_a(v10, (volatile uint32_t *)v7 - 3);
  bt_ready_check(v11, v12);
  return rx_phy_status_parse(7u, 1);
}


// ke_send_event_0x3f @ 0x13698c
int ke_send_event_0x3f() {
  int v0; // r4
  int v1; // r0
  int16_t v2; // r1
  int16_t v3; // r2

  v0 = *(volatile uint32_t *)off_1369C8;
  v1 = ke_msg_alloc(63, 0, 7, 12);
  v2 = *(volatile uint16_t *)(v0 + 36);
  v3 = *(volatile uint16_t *)(v0 + 38);
  *(volatile uint32_t *)v1 = *(volatile uint32_t *)(v0 + 32);
  *(volatile uint16_t *)(v1 + 4) = v2;
  *(volatile uint16_t *)(v1 + 6) = v3;
  *(volatile uint8_t *)(v1 + 8) = *(volatile uint8_t *)(v0 + 50);
  *(volatile uint8_t *)(v1 + 9) = *(volatile uint8_t *)(v0 + 51);
  ke_msg_send_2(v1);
  return rx_phy_status_parse(7u, 2);
}


// rf_send_command_0x1419 @ 0x1369cc
int rf_send_command_0x1419(int a1) {
  volatile uint8_t *v2; // r6
  int v3; // r0
  volatile uint8_t *v4; // r5
  volatile int *v5; // r3
  unsigned int v6; // r2
  volatile uint8_t *v7; // r0
  int v8; // r0
  int v9; // r1
  volatile uint8_t *v10; // r3
  volatile uint32_t *v11; // r0
  int v13; // r0

  v2 = (volatile uint8_t *)ke_msg_alloc(5145, 5, 7, 2);
  v3 = ke_msg_alloc(5143, 5, 7, 2);
  *(volatile uint8_t *)(dword_136AF0 + 696 * (*(volatile uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (volatile uint8_t *)v3;
  bt_get_buffer();
  *v2 = 0;
  v2[1] = *(volatile uint8_t *)(a1 + 107);
  cmd_handler_a(dword_136AF4, (volatile uint32_t *)v2 - 3);
  v5 = *((volatile int **)off_136AF8 + 2);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( (volatile int *)a1 != v5 )
      {
        if ( *((volatile uint8_t *)v5 + 108) )
        {
          v6 = *((volatile uint16_t *)v5 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v5 = (volatile int *)*v5;
      if ( !v5 )
        goto LABEL_6;
    }
    callback_post(v6 | (*((volatile uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    callback_post(0);
  }
  is_valid_id((volatile int *)a1, 0, 0);
  if ( *(volatile uint8_t *)(a1 + 108) )
  {
    v13 = ke_msg_alloc(30, 0, 7, 4);
    *(volatile uint8_t *)(v13 + 2) = 0;
    *(volatile uint8_t *)(v13 + 3) = *(volatile uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (volatile uint32_t *)(v13 - 12));
  }
  if ( *(volatile uint32_t *)(a1 + 72) )
  {
    v7 = (volatile uint8_t *)ke_msg_alloc(57, 0, 7, 1);
    *v7 = *(volatile uint8_t *)(a1 + 107);
    cmd_handler_a(dword_136AF4, (volatile uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v4[1] = *(volatile uint8_t *)(a1 + 107);
  v8 = cmd_handler_a(dword_136AF4, (volatile uint32_t *)v4 - 3);
  bt_ready_check(v8, v9);
  if ( !*(volatile uint8_t *)(a1 + 1224) )
  {
    *(volatile uint8_t *)off_136B00 = 0;
    event_dispatch(aApLpExit);
  }
  v10 = (void *)(uintptr_t)(off_136AFC);
  v11 = (volatile uint32_t *)((volatile char *)off_136AFC + 20);
  *((volatile uint8_t *)off_136AFC + 13) = 0;
  v10[14] = 0;
  fault_handler((int)(uintptr_t)(v11));
  return rx_phy_status_parse(7u, 3);
}


// bt_is_link_active @ 0x136b08
int bt_is_link_active(int a1) {
  unsigned int v1; // r3
  int v2; // r2
  int v3; // r3

  if ( *(volatile uint8_t *)(dword_136B60 + 1320 * *(volatile uint8_t *)(a1 + 28) + 106) != 2 )
    return 1;
  v1 = *(volatile uint8_t *)(a1 + 29);
  if ( v1 > 0x23 || !*(volatile uint16_t *)(a1 + 4) && *(volatile uint16_t *)(*(volatile uint32_t *)(a1 + 72) + 108) == 584 )
    return 1;
  v2 = dword_136B64 + 696 * v1;
  v3 = *(volatile uint8_t *)(v2 + 36);
  if ( v3 != 1 )
    return 1;
  if ( (*(volatile uint8_t *)(v2 + 54) & 3) == 0 )
  {
    v3 = 0;
    *(volatile uint16_t *)(a1 + 30) |= 0x1000u;
  }
  return v3;
}



// tx_handle_pending_flag @ 0x136b68
int tx_handle_pending_flag(int result, int a2) {
  int v3; // r3
  int v4; // r0

  if ( (*(volatile uint16_t *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(volatile uint8_t *)(a2 + 310);
    if ( ((uint8_t)v3 & *(volatile uint8_t *)(dword_136BCC + *(volatile uint8_t *)(result + 27))) != 0 )
    {
      if ( (*(volatile uint8_t *)(a2 + 53) & 8) == 0 )
      {
        *(volatile uint8_t *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(volatile uint8_t *)(a2 + 53) & 2) == 0 )
    {
      *(volatile uint8_t *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = ke_msg_alloc(65, 0, 5, 4u);
      *(volatile uint16_t *)v4 = *(volatile uint16_t *)(a2 + 32);
      *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(a2 + 34);
      *(volatile uint8_t *)(v4 + 2) = 1;
      return (int)(uintptr_t)(ke_msg_send_2(v4));
    }
  }
  return result;
}



// bt_handle_state_event @ 0x136bd0
volatile int ** bt_handle_state_event(int a1, int a2, volatile uint32_t *a3) {
  int v3; // r7
  int v5; // r2
  int v7; // r8
  volatile int **v8; // r4
  char v9; // r1
  int v10; // r5
  BOOL v11; // r2
  volatile int ***v12; // r10
  int v13; // r1
  char v14; // r3
  volatile int **v15; // r3
  BOOL v16; // r1
  int v18; // r7
  int v19; // r0

  v3 = *(volatile uint8_t *)(a1 + 106);
  if ( v3 != 2 || (v5 = *(volatile uint8_t *)(a2 + 54), !*(volatile uint8_t *)(a2 + 54)) )
  {
    *a3 = 0;
    return 0;
  }
  v7 = v5 & 1;
  if ( (v5 & 1) == 0 )
  {
    v3 = 8;
    v7 = 4;
  }
  if ( ((uint8_t)v3 & *(volatile uint8_t *)(a2 + 53)) == 0 )
    goto LABEL_26;
  v8 = *(volatile int ***)(a2 + 572);
  if ( !v8 )
  {
LABEL_24:
    if ( **(volatile int16_t **)off_136D08 < 0 )
      call_shared_handler(dword_136D10, dword_136D0C, 441);
LABEL_26:
    *a3 = 1;
    return 0;
  }
  v9 = *(volatile uint8_t *)(a2 + 310);
  v10 = dword_136D04;
  v11 = v5 == 2;
  v12 = 0;
  while ( ((uint8_t)(v9 & *(volatile uint8_t *)(dword_136D04 + *((volatile uint8_t *)v8 + 27))) == 0) == v11 )
  {
    v12 = (volatile int ***)v8;
    if ( !*v8 )
      goto LABEL_24;
    v8 = (volatile int **)*v8;
  }
  rf_cal_check(a2 + 572, (void *)(v12), (void *)(v8));
  v13 = *(volatile uint8_t *)(a2 + 54);
  if ( (v13 & 8) != 0 )
    v14 = 4;
  else
    v14 = 3;
  *((volatile uint8_t *)v8 + 27) = v14;
  if ( v12 )
    v15 = *v12;
  else
    v15 = *(volatile int ***)(a2 + 572);
  if ( v15 )
  {
    v16 = v13 == 2;
    while ( ((uint8_t)(*(volatile uint8_t *)(a2 + 310) & *(volatile uint8_t *)(v10 + *((volatile uint8_t *)v15 + 27))) == 0) == v16 )
    {
      v15 = (volatile int **)*v15;
      if ( !v15 )
        goto LABEL_22;
    }
    goto LABEL_20;
  }
LABEL_22:
  v18 = *(volatile uint8_t *)(a2 + 53) & ~v3;
  *(volatile uint8_t *)(a2 + 53) = v18;
  if ( (v18 & v7) != 0 )
  {
LABEL_20:
    *((volatile uint16_t *)v8[18] + 54) |= 0x2000u;
    return v8;
  }
  v19 = ke_msg_alloc(65, 0, 5, 4u);
  *(volatile uint16_t *)v19 = *(volatile uint16_t *)(a2 + 32);
  *(volatile uint8_t *)(v19 + 3) = *(volatile uint8_t *)(a2 + 34);
  *(volatile uint8_t *)(v19 + 2) = 0;
  ke_msg_send_2(v19);
  return v8;
}



// bt_get_link_context @ 0x136d14
int bt_get_link_context(int result, int a2) {
  int v2; // r4
  char v3; // r1
  int v4; // r0
  int16_t v5; // r1

  if ( *(volatile uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136D68 + 696 * a2;
    result = llc_ccm_encrypt(result, v2, 0);
    v3 = *(volatile uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(volatile uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = ke_msg_alloc(65, 0, 5, 4u);
        v5 = *(volatile uint16_t *)(v2 + 32);
        *(volatile uint8_t *)(v4 + 3) = *(volatile uint8_t *)(v2 + 34);
        *(volatile uint8_t *)(v4 + 2) = 0;
        *(volatile uint16_t *)v4 = v5;
        return (int)(uintptr_t)(ke_msg_send_2(v4));
      }
    }
  }
  return result;
}



// rx_process_callback @ 0x136d6c
int rx_process_callback(int a1, int a2) {
  int v2; // r3
  int v5; // r3
  int result; // r0
  int v7; // r5
  int v8; // r6
  volatile uint16_t *v9; // r2
  int16_t v10; // r3
  int16_t v11; // r1
  int v12; // r0
  int v13; // r0
  int v14; // r1
  uint64_t v15; // r2

  v2 = *(volatile uint32_t *)(a1 + 72);
  if ( v2 )
  {
    v5 = *(volatile uint8_t *)(v2 + 4);
    if ( **(volatile int16_t **)off_136E64 >= 0 || v5 != 2 )
    {
      result = (int)(uintptr_t)(ke_mutex_guard((v5 | *(volatile uint8_t *)(a1 + 1224)) != 0, 512));
      v7 = result;
      if ( !result )
        return result;
LABEL_4:
      rf_check_temperature(a1, result);
      v8 = *(volatile uint32_t *)(v7 + 72);
      *(volatile uint8_t *)(v8 + 108) = -64;
      *(volatile uint8_t *)(v8 + 109) = 0;
      *(volatile uint8_t *)(v8 + 110) = 0;
      *(volatile uint8_t *)(v8 + 111) = 0;
      memcpy((void *)(uintptr_t)(v8 + 112), (void *)(uintptr_t)(a2), 6);
      v9 = (void *)(uintptr_t)(off_136E68);
      v10 = *((volatile uint16_t *)off_136E68 + 254);
      v11 = *(volatile uint16_t *)(a1 + 104);
      *(volatile uint32_t *)(v8 + 118) = *(volatile uint32_t *)(a1 + 100);
      ++v10;
      v12 = *(volatile uint32_t *)(a1 + 100);
      *(volatile uint16_t *)(v8 + 122) = v11;
      *(volatile uint32_t *)(v8 + 124) = v12;
      *(volatile uint16_t *)(v8 + 128) = v11;
      v9[254] = v10;
      *(volatile uint16_t *)(v8 + 130) = 16 * v10;
      *(volatile uint32_t *)(v7 + 88) = 0;
      *(volatile uint32_t *)(v7 + 92) = a1;
      *(volatile uint8_t *)(v7 + 28) = *(volatile uint8_t *)(a1 + 107);
      *(volatile uint8_t *)(v7 + 29) = -1;
      v13 = store_uint16_ret2((volatile uint16_t *)(v8 + 132), 7);
      v14 = *(volatile uint32_t *)(v7 + 76);
      v15 = (v15 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(v14 + 28) + 23 + v13) & 0xFFFFFFFFu);
      v15 = (v15 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v13 + 28) << 32);
      *(volatile uint64_t *)(v14 + 32) = v15;
      return tx_path_status(v7, 5);
    }
    goto LABEL_6;
  }
  if ( **(volatile int16_t **)off_136E64 < 0 )
LABEL_6:
    mmio_clear_register(dword_136E70, dword_136E6C, 520);
  result = (int)(uintptr_t)(ke_mutex_guard(1, 512));
  v7 = result;
  if ( result )
    goto LABEL_4;
  return result;
}



// set_bt_irq_flag @ 0x136e74
int set_bt_irq_flag() {
  *(volatile uint8_t *)off_136E80 = 1;
  return event_dispatch(aApLpEnter);
}


// rf_power_off_1 @ 0x136e88
int rf_power_off_1() {
  *(volatile uint8_t *)off_136E94 = 0;
  return event_dispatch(aApLpExit);
}


// rf_write_cmd_1006 @ 0x136e9c
int rf_write_cmd_1006(int a1, volatile uint8_t *a2, int a3, int16_t a4) {
  volatile uint16_t *v4; // r4
  volatile uint8_t *v6; // r0
  volatile uint32_t *v7; // r6
  unsigned int v8; // r2
  volatile int *v10; // r4
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2

  v4 = (void *)(uintptr_t)(off_136EF8);
  v6 = (volatile uint8_t *)ke_msg_alloc(4102, a4, 4, 0x3Cu);
  v7 = (void *)(v6);
  if ( v4[2] && (v8 = *a2, (uint16_t)v4[2] > v8) )
  {
    v10 = (volatile int *)&v4[30 * v8 + 4];
    v11 = *v10;
    v12 = v10[1];
    v13 = v10[2];
    v14 = v10[3];
    v10 += 4;
    *v7 = v11;
    v7[1] = v12;
    v7[2] = v13;
    v7[3] = v14;
    v15 = *v10;
    v16 = v10[1];
    v17 = v10[2];
    v18 = v10[3];
    v10 += 4;
    v7[4] = v15;
    v7[5] = v16;
    v7[6] = v17;
    v7[7] = v18;
    v19 = *v10;
    v20 = v10[1];
    v21 = v10[2];
    v22 = v10[3];
    v10 += 4;
    v7[8] = v19;
    v7[9] = v20;
    v7[10] = v21;
    v7[11] = v22;
    v23 = v10[1];
    v24 = v10[2];
    v7[12] = *v10;
    v7[13] = v23;
    v7[14] = v24;
    ke_msg_send_2((int)v7);
    return 0;
  }
  else
  {
    *v6 = 0;
    ke_msg_send_2((int)v6);
    return 0;
  }
}



// rf_enable_3 @ 0x136efc
int rf_enable_3(int a1, int a2, int a3, int a4) {
  int v4; // r0

  v4 = ke_msg_alloc(4107, a4, 4, 1);
  ke_msg_send_2(v4);
  check_status_bits(8, aScanuIdleCance);
  return 0;
}


// rf_send_channel @ 0x136f20
int rf_send_channel() {
  volatile uint16_t *v0; // r4
  int v1; // r0

  v0 = (volatile uint16_t *)off_136F48;
  v1 = ke_msg_alloc(4107, *((volatile uint16_t *)off_136F48 + 1924), 4, 1);
  ke_msg_send_2(v1);
  check_status_bits(8, "scan idle cancel cfm %d\r\n", v0[1924]);
  return 0;
}


// rf_set_band @ 0x136f50
int rf_set_band(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)ke_msg_alloc(4104, a4, 4, 2);
  check_status_bits(8, aScanuScanningV);
  *v5 = 1;
  v5[1] = *(volatile uint8_t *)(a2 + 2);
  ke_msg_send_2((int)v5);
  return 0;
}


// rf_read_cal_data @ 0x136f84
int rf_read_cal_data(int a1, int a2, int a3, int a4) {
  check_status_bits(8, "scanning scanu req:%d,%d\n", a4, *((volatile uint16_t *)off_136F9C + 1924));
  return 2;
}


// rf_set_band_alt @ 0x136fa4
int rf_set_band_alt(int a1, volatile char *a2, int a3, int a4) {
  volatile uint8_t *v5; // r4
  volatile char *v6; // r0
  unsigned int v7; // r2

  v5 = (volatile uint8_t *)ke_msg_alloc(4104, a4, 4, 2);
  check_status_bits(8, aScanuVndrIe);
  v6 = (volatile char *)off_136FE8;
  v7 = *(volatile uint16_t *)a2;
  *(volatile uint16_t *)off_136FE8 = v7;
  memcpy(v6 + 3, a2 + 3, v7);
  *v5 = 1;
  v5[1] = a2[2];
  ke_msg_send_2((int)v5);
  return 0;
}


