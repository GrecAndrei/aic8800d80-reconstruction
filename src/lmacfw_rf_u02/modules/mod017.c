// ke_alloc_msg_0x6a @ 0x11954c
int ke_alloc_msg_0x6a(int a1, int a2, uint16_t a3, uint16_t a4) {
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  uint64_t v9; // r0
  volatile int *v10; // r3
  int v12; // r1
  int v13; // r5
  struct __attribute__((packed)) { uint16_t a1a; // [sp+2h] [bp-Ah] BYREF
  int a3a; // [sp+4h] [bp-8h] BYREF
  } _frame;
  _frame.a1a = 0;
  v5 = ke_msg_send_1(106, a4, a3, 16);
  if ( (*(volatile uint32_t *)off_11966C & 0x2000000) != 0 )
  {
    mmio_read_status((void *)(&_frame.a1a));
    mmio_read_byte((volatile uint8_t *)&_frame.a1a + 1);
    dispatch_event_handler_1("read xtal_cap efuse=%x,%x\n", (uint8_t)_frame.a1a, HIBYTE(_frame.a1a));
    goto LABEL_16;
  }
  _frame.a3a = 0;
  if ( bus_read32((int)&_frame.a3a) )
  {
LABEL_16:
    v6 = (uint8_t)_frame.a1a;
    goto LABEL_4;
  }
  v6 = (uint8_t)_frame.a3a;
  _frame.a1a = _frame.a3a;
LABEL_4:
  if ( !v6 && *(volatile uint8_t *)(a2 + 20) )
  {
    dispatch_event_handler_1("user cap:0x%x\n", *(volatile uint8_t *)(a2 + 20));
    _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(a2 + 20)) & 0xFFu);
  }
  v7 = HIBYTE(_frame.a1a);
  if ( !HIBYTE(_frame.a1a) )
  {
    if ( *(volatile uint8_t *)(a2 + 21) )
    {
      dispatch_event_handler_1("user cap_fine:0x%x\n", *(volatile uint8_t *)(a2 + 21));
      v8 = (uint8_t)_frame.a1a;
      v7 = *(volatile uint8_t *)(a2 + 21);
      _frame.a1a = (_frame.a1a & ~0xFF00u) | (((uint8_t)(*(volatile uint8_t *)(a2 + 21)) & 0xFFu) << 8);
      if ( !(uint8_t)_frame.a1a )
        goto LABEL_13;
    }
    else
    {
      v8 = (uint8_t)_frame.a1a;
      if ( !(uint8_t)_frame.a1a )
        goto LABEL_14;
    }
LABEL_10:
    if ( v8 > 0x1F )
    {
      v8 = 31;
      _frame.a1a = (_frame.a1a & ~0xFFu) | ((uint8_t)(31) & 0xFFu);
    }
    set_xtal_ftune(v8);
    dispatch_event_handler_1("set xtal_cap 0x%x\n", (uint8_t)_frame.a1a);
    v7 = HIBYTE(_frame.a1a);
LABEL_13:
    if ( !v7 )
      goto LABEL_14;
    goto LABEL_18;
  }
  v8 = (uint8_t)_frame.a1a;
  if ( (uint8_t)_frame.a1a )
    goto LABEL_10;
LABEL_18:
  if ( v7 > 0x3F )
  {
    v12 = 63;
    _frame.a1a = (_frame.a1a & ~0xFF00u) | (((uint8_t)(63) & 0xFFu) << 8);
    v13 = 16515072;
  }
  else
  {
    v12 = HIBYTE(_frame.a1a);
    v13 = (HIBYTE(_frame.a1a) << 18) & 0xFC0000;
  }
  *(volatile uint32_t *)off_119688 = *(volatile uint32_t *)off_119688 & 0xFF03FFFF | v13;
  dispatch_event_handler_1("set xtal_cap_fine 0x%x\n", v12);
LABEL_14:
  v9 = (v9 & ~0xFFFFFFFFull) | ((uint32_t)(((volatile uint32_t *)(uintptr_t)off_119674)[2]) & 0xFFFFFFFFu);
  v9 = (v9 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint32_t *)off_119678) << 32);
  v10 = (volatile int *)off_119680;
  *(volatile uint32_t *)(v5 + 12) = *(volatile uint32_t *)off_11967C;
  *(volatile uint64_t *)(v5 + 4) = v9;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v10);
  rx_irq_handler_1(v5);
  return 0;
}


// ke_send_msg_0x76 @ 0x119698
int ke_send_msg_0x76(int a1, int a2, int a3, int a4) {
  int v4; // r0

  v4 = ke_msg_send_1(118, a4, a3, 12);
  rx_irq_handler_1(v4);
  return 0;
}



// ke_alloc_msg_0x74 @ 0x1196ac
int ke_alloc_msg_0x74(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  struct __attribute__((packed)) { int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF
  } _frame;
  _frame.v8 = 0;
  _frame.a2a = 0;
  v4 = (volatile uint8_t *)ke_msg_send_1(116, a4, a3, 6);
  if ( (*(volatile uint32_t *)off_119724 & 0x2000000) != 0 )
  {
    mmio_read_pair(&_frame.v8, &_frame.a2a);
    v6 = _frame.v8;
    v5 = _frame.a2a;
  }
  else
  {
    memset((void *)(_frame.v10), 0, 6);
    bus_read_6((int)_frame.v10);
    v5 = __rev16(LOWORD(_frame.v10[0]));
    v6 = bswap32(*(volatile unsigned int *)((volatile char *)_frame.v10 + 2));
    _frame.v8 = v6;
    _frame.a2a = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v4[4] = BYTE1(v6);
  dispatch_event_handler_1(aGetMacaddrXX, HIBYTE(v5), (uint8_t)v6, HIBYTE(v6), _frame.v8, _frame.a2a);
  rx_irq_handler_1((int)v4);
  return 0;
}


// store_adv_addr @ 0x11972c
int store_adv_addr(int a1, int a2, int a3, int a4) {
  int v4; // r8
  int v5; // r7

  v4 = dword_1197A0;
  v5 = dword_11979C;
  memcpy((void *)(uintptr_t)(dword_1197A0), (void *)(uintptr_t)(a2 + 1), 12);
  memcpy((void *)(uintptr_t)(v4 + 12), (void *)(uintptr_t)(a2 + 13), 10);
  memcpy((void *)(uintptr_t)(v4 + 24), (void *)(uintptr_t)(a2 + 23), 12);
  memcpy((void *)(uintptr_t)(v5), (void *)(uintptr_t)(a2 + 35), 12);
  memcpy((void *)(uintptr_t)(v5 + 12), (void *)(uintptr_t)(a2 + 47), 10);
  memcpy((void *)(uintptr_t)(v5 + 24), (void *)(uintptr_t)(a2 + 57), 12);
  ke_evt_handler(120, a4, a3);
  return 0;
}



// ke_alloc_msg_0x81 @ 0x1197a4
int ke_alloc_msg_0x81(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (volatile uint8_t *)ke_msg_send_1(129, a4, a3, 64);
  v5 = dword_1197D8;
  *v4 = 0;
  memcpy(v4 + 1, (void *)(uintptr_t)(v5), 36);
  v6 = (uint8_t)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  rx_irq_handler_1((int)(uintptr_t)(v4));
  return 0;
}



// ke_alloc_msg_0x7c @ 0x1197dc
int ke_alloc_msg_0x7c(int a1, volatile uint8_t *a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v5; // r5
  int v6; // r2
  int v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (volatile uint8_t *)ke_msg_send_1(124, a4, a3, 2);
  if ( *a2 )
  {
    dispatch_event_handler_1(aDriverStart);
    **(volatile uint8_t **)off_11989C = 0;
  }
  else
  {
    dispatch_event_handler_1(aDriverStop);
    **(volatile uint8_t **)off_11989C = 3;
  }
  rf_regf_high_check(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = off_1198A0;
    *(volatile uint8_t *)(off_1198A0 + 0xBC) = (v6 & 0x20) != 0;
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = off_1198A0;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    *(volatile uint8_t *)(off_1198A0 + 0xBC) = (v11 & 0x20) != 0;
  }
  if ( rf_get_reg0xf_bit20() )
  {
    *(volatile uint8_t *)(v7 + 0xBC) = 0;
    v9 = 0;
  }
  else
  {
    v9 = *(volatile uint8_t *)(v7 + 0xBC);
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *(volatile uint16_t *)(v7 + 0xB2) |= 0x4000u;
    dispatch_event_handler_1("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    v9 = (v9 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v7 + 0xBC)) & 0xFFu);
  }
  *v5 = v9;
  rx_irq_handler_1((int)v5);
  return 0;
}


// parse_ll_pdu_header @ 0x1198ac
int parse_ll_pdu_header(int a1, int a2, int a3, int a4) {
  int v4; // r0
  unsigned int v5; // r4
  int v6; // r7
  unsigned int v7; // r12
  int v8; // r1
  unsigned int v9; // r3
  int v11; // r4
  int v12; // [sp+0h] [bp-Ch]
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v15; // [sp+4h] [bp-8h]
  int v17; // [sp+4h] [bp-8h]

  v4 = *(volatile uint8_t *)(a2 + 6);
  v5 = *(volatile uint8_t *)(a2 + 5);
  v6 = dword_119974;
  v7 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(dword_119974 + 4 * (v5 + 56 * v4 + 2)) = *(volatile uint32_t *)a2;
  v8 = a4;
  if ( v5 == 1 )
  {
    v11 = *(volatile uint32_t *)(*(volatile uint32_t *)off_119978 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(volatile uint32_t *)(*(volatile uint32_t *)off_119978 + 4);
      else
        v7 = v11 & 0xFFFFF000 | v7 & 0xFFF;
    }
    if ( *(volatile uint8_t *)(v6 + 224 * v4 + 96) )
    {
      *(volatile uint32_t *)off_119980 = v7;
      v13 = a3;
      poll_hw_status_1();
      a3 = v13;
      v8 = a4;
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(*(volatile uint32_t *)off_119978 + 4 * v5);
    if ( !v9 )
      v9 = v7;
    if ( *(volatile uint8_t *)(v6 + 224 * v4 + 96) )
    {
      if ( v5 == 2 )
      {
        *(volatile uint32_t *)off_119988 = v9;
        v14 = a3;
        v17 = v8;
        poll_hw_status_1();
        a3 = v14;
        v8 = v17;
      }
      else
      {
        if ( v5 > 2 )
          *(volatile uint32_t *)off_119984 = v9;
        else
          *(volatile uint32_t *)off_11997C = v9;
        v12 = a3;
        v15 = v8;
        poll_hw_status_1();
        a3 = v12;
        v8 = v15;
      }
    }
  }
  ke_evt_handler(27, v8, a3);
  return 0;
}



// ke_cmd_write_mmio @ 0x11998c
int ke_cmd_write_mmio(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (volatile uint8_t *)ke_msg_send_1(133, a4, a3, 1);
  v5 = critical_enter(dword_1199C4, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  dispatch_event_handler_1("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  rx_irq_handler_1((int)v4);
  return 0;
}


// ke_alloc_msg_0x88 @ 0x1199cc
int ke_alloc_msg_0x88(int a1, volatile int *a2, uint16_t a3, uint16_t a4) {
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int result; // r0
  int v10; // r1
  int v11; // r6
  int v12; // r3
  int v13; // r1
  int v14; // r5
  char v15; // r0
  int v16; // r1
  int v17; // r5
  int v18; // r1

  v5 = *a2;
  v6 = ke_msg_send_1(136, a4, a3, 8);
  v7 = v6;
  *(volatile uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((volatile uint8_t *)a2 + 4);
      *(volatile uint8_t *)(off_119ACC + 0x175) = v8;
      *(volatile uint8_t *)(v6 + 4) = v8;
      dispatch_event_handler_1("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = off_119ACC;
      v12 = *((volatile uint8_t *)a2 + 4);
      v13 = *(volatile uint8_t *)(off_119ACC + 0x16B);
      *(volatile uint8_t *)(off_119ACC + 0x16B) = v12;
      *(volatile uint32_t *)(v11 + 0x16C) = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          rf_read_trim();
          rf_enable_2();
        }
        else
        {
          rf_disable_2();
        }
        v13 = *(volatile uint8_t *)(v11 + 0x16B);
      }
      *(volatile uint8_t *)(v7 + 4) = v13;
      dispatch_event_handler_1("temp_comp_en:%x\n", v13);
      rx_irq_handler_1(v7);
      result = 0;
      break;
    case 2:
      v14 = off_119ACC;
      *(volatile uint8_t *)(v6 + 4) = *(volatile uint8_t *)(off_119ACC + 0x16B);
      v15 = mac_packet_dispatch();
      *(volatile uint8_t *)(v7 + 5) = v15;
      dispatch_event_handler_1("temp_comp_en:%x,t=%d\n", *(volatile uint8_t *)(v14 + 0x16B), v15);
      rx_irq_handler_1(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = off_119ACC;
      *(volatile uint32_t *)(off_119ACC + 0x188) = v16;
      dispatch_event_handler_1("set ext_flags:0x%x\n", v16);
      *(volatile uint32_t *)(v7 + 4) = *(volatile uint32_t *)(v17 + 0x188);
      rx_irq_handler_1(v7);
      result = 0;
      break;
    case 4:
      v18 = *(volatile uint32_t *)(off_119ACC + 0x188);
      *(volatile uint32_t *)(v6 + 4) = v18;
      dispatch_event_handler_1("get ext_flags:0x%x\n", v18);
      rx_irq_handler_1(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ *(volatile uint32_t *)(off_119ACC + 0x188)) & a2[1] ^ *(volatile uint32_t *)(off_119ACC + 0x188);
      *(volatile uint32_t *)(off_119ACC + 0x188) = v10;
      *(volatile uint32_t *)(v6 + 4) = v10;
      dispatch_event_handler_1("mask set ext_flags:0x%x\n", v10);
      rx_irq_handler_1(v7);
      result = 0;
      break;
    default:
LABEL_3:
      rx_irq_handler_1(v7);
      result = 0;
      break;
  }
  return result;
}


// call_1238e0_return_zero @ 0x119ae8
int call_1238e0_return_zero() {
  wait_for_tx_ready();
  return 0;
}



// process_llcp_pdu @ 0x119af4
int process_llcp_pdu(int a1, volatile uint8_t *a2, int a3, int a4) {
  char v7; // r0
  char v9; // r6
  volatile uint8_t *v10; // r0

  v7 = tx_header_prepare(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (volatile uint8_t *)ke_msg_send_1(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    rx_irq_handler_1((int)(uintptr_t)(v10));
  }
  return 0;
}



// hci_build_event_0x3a @ 0x119b2c
int hci_build_event_0x3a(int a1, volatile uint8_t *a2, int a3, int a4) {
  bt_conn_rx_schedule(*a2);
  ke_evt_handler(58, a4, a3);
  return 0;
}



// call_packet_helper @ 0x119b4c
int call_packet_helper(int a1, int a2, int a3, int a4) {
  rf_tx_packet_check(a2, a4);
  return 0;
}



// check_adv_pdu_type @ 0x119b5c
int check_adv_pdu_type(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // [sp+4h] [bp-8h]
  int v8; // [sp+4h] [bp-8h]

  if ( a2[2] )
  {
    v8 = a3;
    bt_conn_rx_schedule(*a2);
    a3 = v8;
  }
  v7 = a3;
  bt_conn_tx_schedule(*a2, a2[1]);
  ke_evt_handler(56, a4, v7);
  return 0;
}



// hci_build_event_0x36 @ 0x119b90
int hci_build_event_0x36(int a1, volatile uint8_t *a2, int a3, int a4) {
  lookup_7byte_channel(*a2);
  ke_evt_handler(54, a4, a3);
  return 0;
}



// ke_alloc_msg_0x34 @ 0x119bb0
int ke_alloc_msg_0x34(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v5; // r4

  v5 = (volatile uint8_t *)ke_msg_send_1(52, a4, a3, 2);
  *v5 = env_get(a2, v5 + 1);
  rx_irq_handler_1((int)(uintptr_t)(v5));
  return 0;
}



// hci_build_event_0x0d @ 0x119bd8
int hci_build_event_0x0d(int a1, volatile uint8_t *a2, int a3, int a4) {
  rf_channel_calibrate(*a2);
  ke_evt_handler(13, a4, a3);
  return 0;
}



// get_bt_state_word @ 0x119bf8
int get_bt_state_word(int a1, volatile uint8_t *a2, int a3, int a4) {
  unsigned int v7; // r0

  if ( **(volatile int16_t **)off_119C3C < 0 )
  {
    v7 = *a2;
    if ( v7 <= HIBYTE(*(volatile uint32_t *)off_119C40) )
      goto LABEL_3;
    flash_ctrl_init(dword_119C48, dword_119C44, 1803);
  }
  v7 = *a2;
LABEL_3:
  convert_handle_index(v7);
  ke_evt_handler(39, a4, a3);
  return 0;
}



// ke_alloc_msg_0x25 @ 0x119c4c
int ke_alloc_msg_0x25(int a1, volatile char *a2, int a3, int a4) {
  volatile uint8_t *v5; // r0
  volatile int16_t **v6; // r6
  volatile uint8_t *v7; // r5
  int v8; // r3

  v5 = (volatile uint8_t *)ke_msg_send_1(37, a4, a3, 2);
  v6 = (volatile int16_t **)off_119D04;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( (uint8_t)*a2 <= 3u || (flash_ctrl_init(dword_119D14, dword_119D0C, 1725), **v6 < 0) )
    {
      if ( (uint8_t)a2[4] > 0x20u )
        flash_ctrl_init(dword_119D10, dword_119D0C, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0:
    case 1:
    case 3:
      v8 = (*(volatile uint32_t *)off_119D08 >> 6) & 1;
      goto LABEL_4;
    case 2:
    case 8:
      v8 = (*(volatile uint32_t *)off_119D08 >> 7) & 1;
      goto LABEL_4;
    case 4:
      v8 = (*(volatile uint32_t *)off_119D08 >> 13) & 1;
      goto LABEL_4;
    case 6:
    case 7:
      v8 = (*(volatile uint32_t *)off_119D08 >> 9) & 1;
LABEL_4:
      if ( v8 && (uint8_t)a2[4] <= 0x20u && (uint8_t)*a2 <= 3u )
      {
        v7[1] = handle_hci_event(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  rx_irq_handler_1((int)(uintptr_t)(v7));
  return 0;
}



// util_scale_index @ 0x119d18
int util_scale_index(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r5
  int v9; // r1
  int v10; // r4

  v4 = dword_119D54;
  v6 = 7 * *a2;
  v7 = ke_msg_send_1(47, a4, a3, 2);
  v8 = v4 + 32 * v6;
  v9 = (char)a2[1];
  v10 = v7;
  rf_set_temperature(v8, v9);
  rf_get_temperature(v8, (void *)(uintptr_t)(v10 + 1), (void *)(uintptr_t)(v10));
  rx_irq_handler_1(v10);
  return 0;
}



// timer_start_reset @ 0x119d58
int timer_start_reset(int a1, int a2, int a3, int a4) {
  ke_evt_handler(1, a4, a3);
  flash_erase_sector(0, 0);
  return 0;
}


