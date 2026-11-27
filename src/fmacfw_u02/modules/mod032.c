// send_command_6a @ 0x122d28
int send_command_6a(int a1, volatile int *a2, uint16_t a3, uint16_t a4) {
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  int v9; // r7
  uint64_t v10; // r0
  volatile int *v11; // r3
  int v13; // r1
  int v14; // r6
  struct __attribute__((packed)) { uint8_t a1a[2]; // [sp+Ah] [bp-92h] BYREF
  uint32_t v16[2]; // [sp+Ch] [bp-90h] BYREF
  uint8_t v17[136]; // [sp+14h] [bp-88h] BYREF
  } _frame;
  _frame.a1a[0] = 0;
  _frame.a1a[1] = 0;
  v5 = ke_msg_alloc(106, a4, a3, 16);
  if ( (*(volatile uint32_t *)off_122F00 & 0x2000000) != 0 )
  {
    rf_cmd6_read(_frame.a1a);
    rf_cmd6_read_hi(&_frame.a1a[1]);
    event_dispatch("read xtal_cap efuse=%x,%x\n", _frame.a1a[0], _frame.a1a[1]);
    v6 = _frame.a1a[0];
  }
  else
  {
    *(volatile uint32_t *)_frame.v17 = 0;
    if ( ke_event_send_2((int)_frame.v17) )
    {
      v6 = _frame.a1a[0];
    }
    else
    {
      v6 = _frame.v17[0];
      _frame.a1a[0] = _frame.v17[0];
      _frame.a1a[1] = _frame.v17[1];
    }
  }
  if ( !v6 && *((volatile uint8_t *)a2 + 20) )
  {
    event_dispatch("user cap:0x%x\n", *((volatile uint8_t *)a2 + 20));
    _frame.a1a[0] = *((volatile uint8_t *)a2 + 20);
  }
  v7 = _frame.a1a[1];
  if ( _frame.a1a[1] )
  {
    v8 = _frame.a1a[0];
    if ( !_frame.a1a[0] )
      goto LABEL_20;
  }
  else if ( *((volatile uint8_t *)a2 + 21) )
  {
    event_dispatch("user cap_fine:0x%x\n", *((volatile uint8_t *)a2 + 21));
    v8 = _frame.a1a[0];
    v7 = *((volatile uint8_t *)a2 + 21);
    _frame.a1a[1] = *((volatile uint8_t *)a2 + 21);
    if ( !_frame.a1a[0] )
      goto LABEL_19;
  }
  else
  {
    v8 = _frame.a1a[0];
    if ( !_frame.a1a[0] )
      goto LABEL_10;
  }
  if ( v8 > 0x1F )
  {
    v8 = 31;
    _frame.a1a[0] = 31;
  }
  rf_get_state(v8);
  event_dispatch("set xtal_cap 0x%x\n", _frame.a1a[0]);
  v7 = _frame.a1a[1];
LABEL_19:
  if ( !v7 )
  {
LABEL_10:
    if ( !a2[3] )
      goto LABEL_11;
    goto LABEL_23;
  }
LABEL_20:
  if ( v7 > 0x3F )
  {
    v13 = 63;
    _frame.a1a[1] = 63;
    v14 = 16515072;
  }
  else
  {
    v13 = _frame.a1a[1];
    v14 = (_frame.a1a[1] << 18) & 0xFC0000;
  }
  *(volatile uint32_t *)off_122F20 = *(volatile uint32_t *)off_122F20 & 0xFF03FFFF | v14;
  event_dispatch("set xtal_cap_fine 0x%x\n", v13);
  if ( !a2[3] )
    goto LABEL_11;
LABEL_23:
  gpio_write();
LABEL_11:
  v9 = *a2;
  _frame.v16[1] = a2[2];
  _frame.v16[0] = v9;
  rx_packet_init(0, 2437, (int)_frame.v16, (int)_frame.v17, 1u, 0);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_122F04)[47]) )
  {
    _frame.v16[0] = a2[1];
    rx_packet_init(1, 5700, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rx_packet_init(1, 5250, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rx_packet_init(1, 5500, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rx_packet_init(1, 5500, (int)_frame.v16, (int)_frame.v17, 0, 1u);
    tx_packet_handler(0, 2437, 0x985u, 0, 0, 0);
  }
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(((volatile uint32_t *)(uintptr_t)off_122F08)[2]) & 0xFFFFFFFFu);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint32_t *)off_122F0C) << 32);
  v11 = (volatile int *)off_122F14;
  *(volatile uint32_t *)(v5 + 12) = *(volatile uint32_t *)off_122F10;
  *(volatile uint64_t *)(v5 + 4) = v10;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v11);
  ke_msg_send_2(v5);
  return 0;
}


// send_cmd_74 @ 0x122f30
int send_cmd_74(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  struct __attribute__((packed)) { unsigned int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF
  } _frame;
  _frame.v8 = 0;
  _frame.a2a = 0;
  v4 = (volatile uint8_t *)ke_msg_alloc(116, a4, a3, 6);
  if ( (*(volatile uint32_t *)off_122FA8 & 0x2000000) != 0 )
  {
    rf_cmd8_read((void *)(&_frame.v8), &_frame.a2a);
    v6 = _frame.v8;
    v5 = _frame.a2a;
  }
  else
  {
    memset(_frame.v10, 0, 6);
    ke_event_send_0x400000((int)_frame.v10);
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
  event_dispatch(aGetMacaddrXX, HIBYTE(v5), (uint8_t)v6, HIBYTE(v6), _frame.v8, _frame.a2a);
  ke_msg_send_2((int)v4);
  return 0;
}


// send_cmd_7c @ 0x122fb0
int send_cmd_7c(int a1, volatile uint8_t *a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v5; // r5
  int v6; // r2
  volatile int *v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (volatile uint8_t *)ke_msg_alloc(124, a4, a3, 2);
  if ( *a2 )
  {
    event_dispatch(aDriverStart);
    **(volatile uint8_t **)off_123070 = 0;
  }
  else
  {
    event_dispatch(aDriverStop);
    **(volatile uint8_t **)off_123070 = 3;
  }
  rom_get_chip_metal(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = (volatile int *)off_123074;
    ((volatile uint32_t *)(uintptr_t)off_123074)[47] = (((volatile uint32_t *)(uintptr_t)off_123074)[47] & ~0xFFu) | ((uint8_t)((v6 & 0x20) != 0) & 0xFFu);
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = (volatile int *)off_123074;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    ((volatile uint32_t *)(uintptr_t)off_123074)[47] = (((volatile uint32_t *)(uintptr_t)off_123074)[47] & ~0xFFu) | ((uint8_t)((v11 & 0x20) != 0) & 0xFFu);
  }
  if ( get_hook_bit_20() )
  {
    *((volatile uint8_t *)v7 + 188) = 0;
    v9 = 0;
  }
  else
  {
    v9 = *((volatile uint8_t *)v7 + 188);
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((volatile uint16_t *)v7 + 89) |= 0x4000u;
    event_dispatch("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    v9 = (v9 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v7 + 188)) & 0xFFu);
  }
  *v5 = v9;
  ke_msg_send_2((int)v5);
  return 0;
}


// lookup_connection_entry @ 0x123080
int lookup_connection_entry(int a1, int a2, int a3, int a4) {
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r7
  unsigned int v7; // r5
  int v8; // r1
  unsigned int v9; // r0
  int v11; // r3
  int v12; // [sp+0h] [bp-Ch]
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v16; // [sp+4h] [bp-8h]

  v4 = *(volatile uint8_t *)(a2 + 5);
  v5 = *(volatile uint8_t *)(a2 + 6);
  v6 = dword_123144;
  v7 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(dword_123144 + 4 * (v4 + 330 * v5 + 2)) = *(volatile uint32_t *)a2;
  v8 = a4;
  if ( v4 == 1 )
  {
    v11 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123148 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123148 + 4);
      else
        v7 = v7 & 0xFFF | v11 & 0xFFFFF000;
    }
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      *(volatile uint32_t *)off_123150 = v7;
      v13 = a3;
      v16 = v8;
      read_hw_register();
      a3 = v13;
      v8 = v16;
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123148 + 4 * v4);
    if ( !v9 )
      v9 = v7;
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(volatile uint32_t *)off_123158 = v9;
        v14 = a3;
        read_hw_register();
        a3 = v14;
        v8 = a4;
      }
      else
      {
        if ( v4 > 2 )
          *(volatile uint32_t *)off_123154 = v9;
        else
          *(volatile uint32_t *)off_12314C = v9;
        v12 = a3;
        read_hw_register();
        a3 = v12;
        v8 = a4;
      }
    }
  }
  ke_msg_send_no_param(27, v8, a3);
  return 0;
}



// read_controller_info @ 0x12315c
int read_controller_info(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (volatile uint8_t *)ke_msg_alloc(129, a4, a3, 64);
  v5 = dword_123190;
  *v4 = 0;
  memcpy(v4 + 1, (void *)(uintptr_t)(v5), 36);
  v6 = (uint8_t)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  ke_msg_send_2((int)(uintptr_t)(v4));
  return 0;
}



// send_cmd_85 @ 0x123194
int send_cmd_85(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (volatile uint8_t *)ke_msg_alloc(133, a4, a3, 1);
  v5 = mmio_read32(dword_1231CC, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  event_dispatch("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  ke_msg_send_2((int)v4);
  return 0;
}


// send_cmd_88 @ 0x1231d4
int send_cmd_88(int a1, volatile uint32_t *a2, uint16_t a3, uint16_t a4) {
  int v5; // r6
  int v6; // r0
  int v7; // r4
  int v8; // r1
  int result; // r0
  int v10; // r1
  volatile int *v11; // r6
  int v12; // r3
  int v13; // r1
  volatile int *v14; // r5
  char v15; // r0
  int v16; // r1
  volatile int *v17; // r5
  int v18; // r1

  v5 = *a2;
  v6 = ke_msg_alloc(136, a4, a3, 8);
  v7 = v6;
  *(volatile uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((volatile uint8_t *)a2 + 4);
      ((volatile uint32_t *)(uintptr_t)off_1232D4)[93] = (((volatile uint32_t *)(uintptr_t)off_1232D4)[93] & ~0xFFu) | ((uint8_t)(v8) & 0xFFu);
      *(volatile uint8_t *)(v6 + 4) = v8;
      event_dispatch("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = (volatile int *)off_1232D4;
      v12 = *((volatile uint8_t *)a2 + 4);
      v13 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_1232D4)[90]);
      ((volatile uint32_t *)(uintptr_t)off_1232D4)[90] = (((volatile uint32_t *)(uintptr_t)off_1232D4)[90] & ~0xFF00u) | (((uint8_t)(v12) & 0xFFu) << 8);
      v11[91] = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          rf_get_channel_calibration();
          rf_enable_2();
        }
        else
        {
          rf_disable();
        }
        v13 = *((volatile uint8_t *)v11 + 363);
      }
      *(volatile uint8_t *)(v7 + 4) = v13;
      event_dispatch("temp_comp_en:%x\n", v13);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 2:
      v14 = (volatile int *)off_1232D4;
      *(volatile uint8_t *)(v6 + 4) = HIBYTE(((volatile uint32_t *)(uintptr_t)off_1232D4)[90]);
      v15 = rf_get_bandwidth();
      *(volatile uint8_t *)(v7 + 5) = v15;
      event_dispatch("temp_comp_en:%x,t=%d\n", *((volatile uint8_t *)v14 + 363), v15);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = (volatile int *)off_1232D4;
      ((volatile uint32_t *)(uintptr_t)off_1232D4)[98] = v16;
      event_dispatch("set ext_flags:0x%x\n", v16);
      *(volatile uint32_t *)(v7 + 4) = v17[98];
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 4:
      v18 = ((volatile uint32_t *)(uintptr_t)off_1232D4)[98];
      *(volatile uint32_t *)(v6 + 4) = v18;
      event_dispatch("get ext_flags:0x%x\n", v18);
      ke_msg_send_2(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ ((volatile uint32_t *)(uintptr_t)off_1232D4)[98]) & a2[1] ^ ((volatile uint32_t *)(uintptr_t)off_1232D4)[98];
      ((volatile uint32_t *)(uintptr_t)off_1232D4)[98] = v10;
      *(volatile uint32_t *)(v6 + 4) = v10;
      event_dispatch("mask set ext_flags:0x%x\n", v10);
      ke_msg_send_2(v7);
      result = 0;
      break;
    default:
LABEL_3:
      ke_msg_send_2(v7);
      result = 0;
      break;
  }
  return result;
}


// mm_set_resume_res @ 0x1232f0
int mm_set_resume_res(int a1, int a2, int a3, int a4) {
  int v6; // r8
  int v7; // r9
  unsigned int v8; // r4
  unsigned int v9; // t1
  int v11; // r3
  unsigned int v12; // r5
  int v13; // r6
  void ( *v14)(unsigned int, int, unsigned int, int); // r0
  void ( *v15)(unsigned int, int, unsigned int, int); // r10
  struct __attribute__((packed)) { int v16; // [sp+40h] [bp-2Ch]
  char _pad1[8]; int v17; // [sp+4Ch] [bp-20h]
  char _pad2[23]; char v18[5]; // [sp+67h] [bp-5h] BYREF
  } _frame;
  *(volatile uint8_t *)off_123554 = 1;
  event_dispatch("%s: %d\n", aMmSetResumeRes, 708);
  event_dispatch(
    "offset: %d %d %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d\n",
    0,
    4,
    73,
    83,
    112,
    136,
    248,
    504,
    520,
    592,
    640,
    660,
    670,
    702,
    703,
    704);
  event_dispatch("sizeof %d, %d, %d, %d\n", 32, 44, 108, 112);
  if ( *(volatile uint8_t *)(a2 + 702) )
  {
    v6 = 0;
    _frame.v17 = 0;
    v7 = a2 + 668;
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = *(volatile uint16_t *)(v7 + 2);
        v7 += 2;
        v8 = v9;
        event_dispatch("sub_msg_id: 0x%x\n", v9);
        if ( v9 <= 0x89 )
          break;
        if ( v8 == 5120 )
        {
          v11 = 5;
          v13 = a2 + 136;
          v12 = 5;
          goto LABEL_12;
        }
        if ( v8 == 5122 )
        {
          v11 = 5;
          v13 = a2 + 248;
          v12 = 5;
          goto LABEL_12;
        }
LABEL_16:
        event_dispatch("skip sub_msg_id: 0x%x\n", v8);
        if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
          goto LABEL_9;
      }
      if ( v8 > 0x64 )
      {
        switch ( v8 )
        {
          case 0x65u:
            v11 = 0;
            v13 = a2 + 504;
            v12 = 0;
            goto LABEL_12;
          case 0x69u:
            v11 = 0;
            v13 = a2 + 112;
            v12 = 0;
            goto LABEL_12;
          case 0x77u:
            v11 = 0;
            v13 = a2 + 4;
            v12 = 0;
            goto LABEL_12;
          case 0x79u:
            v11 = 0;
            v13 = a2 + 83;
            v12 = 0;
            goto LABEL_12;
          case 0x7Bu:
            v11 = 0;
            v12 = 0;
            v13 = a2;
            goto LABEL_12;
          case 0x87u:
            v11 = 0;
            v13 = a2 + 12 * _frame.v17 + 592;
            _frame.v17 = (uint8_t)(_frame.v17 + 1);
            v12 = 0;
            goto LABEL_12;
          case 0x89u:
            v11 = 0;
            v13 = a2 + 73;
            v12 = 0;
            goto LABEL_12;
          default:
            goto LABEL_16;
        }
      }
      if ( v8 == 2 )
      {
        v11 = 0;
        v13 = a2 + 520;
        v12 = 0;
        goto LABEL_12;
      }
      if ( v8 == 6 )
      {
        event_dispatch(
          "add vif req:cnt=%d, p2p=%d, macaddr=%x,%x,%x\n",
          *(volatile uint32_t *)(a2 + 704),
          *(volatile uint8_t *)(a2 + 668),
          *(volatile uint16_t *)(a2 + 662),
          *(volatile uint16_t *)(a2 + 664),
          *(volatile uint16_t *)(a2 + 666));
        if ( *(volatile uint32_t *)(a2 + 704) )
        {
          task_event_handler(
            a2 + 662,
            *(volatile uint8_t *)(a2 + 660),
            *(volatile uint8_t *)(a2 + 668),
            (volatile uint8_t *)_frame.v18);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
        {
          break;
        }
      }
      else
      {
        if ( v8 )
          goto LABEL_16;
        v12 = 0;
        v11 = 0;
        v13 = 0;
LABEL_12:
        _frame.v16 = v11;
        v14 = (void ( *)(unsigned int, int, unsigned int, int))rx_format_field_parse(v8, v12);
        v15 = v14;
        if ( v14 )
        {
          event_dispatch("func %p for msg_id:0x%x dest_id:0x%x\n", v14, v8, _frame.v16);
          v15(v8, v13, v12, a4);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else
        {
          event_dispatch("func not found for msg_id:0x%x dest_id:0x%x\n", v8, _frame.v16);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
      }
    }
  }
LABEL_9:
  *(volatile uint8_t *)off_123554 = 0;
  return 0;
}


// rf_tx_start_cmd @ 0x12357c
int rf_tx_start_cmd(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (volatile uint8_t *)ke_msg_alloc(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(volatile uint8_t *)(dword_1235CC + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    llc_get_conn_state(dword_1235CC + 1320 * v5, a2[1]);
LABEL_5:
    ke_msg_send_2((int)(uintptr_t)(v4));
    return 0;
  }
  llc_get_conn_role(dword_1235CC + 1320 * v5);
  ke_msg_send_2((int)(uintptr_t)(v4));
  return 0;
}



// rf_tx_stop_cmd @ 0x1235d0
int rf_tx_stop_cmd(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (volatile uint8_t *)ke_msg_alloc(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_12365C + 1320 * v5;
  if ( !*(volatile uint8_t *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( llc_evt_dispatch(
           v6,
           0,
           a2[3],
           a2[2],
           *((volatile uint32_t *)a2 + 2),
           *((volatile uint32_t *)a2 + 1),
           (*(volatile uint16_t *)(v6 + 222) << 10)
         + *(volatile uint32_t *)off_123660 / (*(volatile uint16_t *)(v6 + 222) << 10) * (*(volatile uint16_t *)(v6 + 222) << 10)
         + *((volatile uint32_t *)off_123664 + 4)
         - *(volatile uint32_t *)off_123660
         + *((volatile uint32_t *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    ke_msg_send_2((int)(uintptr_t)(v4));
    return 0;
  }
  *v4 = rf_calib_required(v6, a2[1], 1);
  ke_msg_send_2((int)(uintptr_t)(v4));
  return 0;
}



// debug_byte_cb @ 0x123668
int debug_byte_cb(int a1, volatile uint8_t *a2, int a3, uint16_t a4) {
  wlc_band_set(*a2, a4);
  return 0;
}


// queue_remove_item @ 0x123678
/* luna: Removes the supplied item from its intrusive queue and returns 1. */
int queue_remove_item(int a1, int a2) {
  co_list_remove(a2);
  return 1;
}



// queue_add_item @ 0x123684
int queue_add_item(int a1, int a2) {
  co_list_push(a2);
  return 1;
}



// link_layer_control @ 0x123690
int link_layer_control(int a1, volatile uint8_t *a2, int a3, int a4) {
  char v7; // r0
  char v9; // r6
  volatile uint8_t *v10; // r0

  v7 = rx_prep_descriptor(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (volatile uint8_t *)ke_msg_alloc(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    ke_msg_send_2((int)(uintptr_t)(v10));
  }
  return 0;
}



// trace_printf @ 0x1236c8
int trace_printf(int a1, volatile uint8_t *a2, int a3, int a4) {
  sta_get_by_index(*a2);
  ke_msg_send_no_param(58, a4, a3);
  return 0;
}



// co_read_3_bytes @ 0x1236e8
int co_read_3_bytes(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v5; // r6
  int v6; // r0
  int v7; // r1
  int v9; // r0
  int v10; // r2
  char v11; // r6
  volatile uint8_t *v12; // r0
  BOOL v14; // r0
  int v15; // r3
  int v16; // r1

  v5 = *a2;
  v6 = a2[1];
  v7 = a2[2];
  if ( v5 )
  {
    v14 = phy_read_offset_b(v6, v7);
    v10 = a3;
    if ( v14 )
    {
      ((int (*)())tx_slot_get)(dword_123778 + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = phy_read_offset_a(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_12377C + 32 * *(volatile uint8_t *)(v15 + 12 * a2[2] + dword_123778 + 453);
      *(volatile uint16_t *)(v15 + 6 * a2[2] + dword_123778 + 354) = 0;
      *(volatile uint16_t *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (volatile uint8_t *)ke_msg_alloc(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  ke_msg_send_2((int)(uintptr_t)(v12));
  return 0;
}



// ble_msg_helper @ 0x123780
int ble_msg_helper(int a1, volatile uint8_t *a2, int a3, int a4) {
  rf_channel_calc(*a2);
  ke_msg_send_no_param(13, a4, a3);
  return 0;
}



// lld_evt_is_active @ 0x1237a0
int lld_evt_is_active(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r0

  if ( **(volatile int16_t **)off_1237E4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(volatile uint32_t *)off_1237E8) + 8 >= v7 )
      goto LABEL_3;
    mmio_clear_register(dword_1237F0, dword_1237EC, 1801);
  }
  v7 = *a2;
LABEL_3:
  get_core_rev(v7);
  ke_msg_send_no_param(39, a4, a3);
  return 0;
}



// ke_msg_send_event @ 0x1237f4
int ke_msg_send_event(int a1, volatile uint8_t *a2, int a3, int a4) {
  volatile uint8_t *v5; // r0
  volatile int16_t **v6; // r6
  volatile uint8_t *v7; // r5
  int v8; // r3

  v5 = (volatile uint8_t *)ke_msg_alloc(37, a4, a3, 2);
  v6 = (volatile int16_t **)off_1238AC;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (mmio_clear_register(dword_1238BC, dword_1238B4, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        mmio_clear_register(dword_1238B8, dword_1238B4, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(volatile uint32_t *)off_1238B0 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(volatile uint32_t *)off_1238B0 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(volatile uint32_t *)off_1238B0 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(volatile uint32_t *)off_1238B0 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = ((int (*)())rx_packet_parse_header)(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  ke_msg_send_2((int)(uintptr_t)(v7));
  return 0;
}



// ke_task_env_get @ 0x1238c0
int ke_task_env_get(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_1238FC + 1320 * *a2;
  v6 = ke_msg_alloc(47, a4, a3, 2);
  *(volatile uint8_t *)(v4 + 110) = a2[1];
  v7 = v6;
  rf_temperature_comp(v4);
  rf_get_rssi_2(v4, (void *)(uintptr_t)(v7 + 1), (void *)(uintptr_t)(v7));
  ke_msg_send_2(v7);
  return 0;
}



// lld_evt_time_get @ 0x123900
int lld_evt_time_get(int a1, volatile uint8_t *a2, int a3, int a4) {
  set_short_address(a2);
  ke_msg_send_no_param(110, a4, a3);
  return 0;
}



// lld_evt_timer_set @ 0x123920
int lld_evt_timer_set(int a1, int a2, int a3, int a4) {
  remove_tx_buffer(a2);
  check_status_bits(256, aSetMuEdca);
  ke_msg_send_no_param(108, a4, a3);
  return 0;
}


// unknown_handler @ 0x12394c
int unknown_handler(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r4
  volatile uint32_t *v5; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r3
  int v12; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1239B8 = 1;
  }
  v4 = (volatile int *)off_1239BC;
  v5 = (void *)(uintptr_t)(off_1239C0);
  v6 = *(volatile uint32_t *)off_1239C0;
  ++*(volatile uint32_t *)off_1239BC;
  mmio_write_one();
  rf_get_status(v7, v8, v9);
  ke_int_lock_save();
  ke_task_reset();
  mem_pool_init();
  get_bt_state();
  v10 = *v4;
  *v5 = v6;
  if ( v10 )
  {
    v11 = v10 - 1;
    v12 = *(volatile uint32_t *)off_1239B8;
    *v4 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  ke_msg_send_no_param(1, a4, a3);
  ke_state_set(0, 0);
  return 0;
}


