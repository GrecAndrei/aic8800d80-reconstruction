// ke_send_msg_6a @ 0x122be8
int ke_send_msg_6a(int a1, volatile int *a2, uint16_t a3, uint16_t a4) {
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
  v5 = tx_send_pdu(106, a4, a3, 16);
  if ( (*(volatile uint32_t *)off_122DC0 & 0x2000000) != 0 )
  {
    rf_cmd_6_read(_frame.a1a);
    rf_cmd_6_version(&_frame.a1a[1]);
    alloc_tx_event("read xtal_cap efuse=%x,%x\n", _frame.a1a[0], _frame.a1a[1]);
    v6 = _frame.a1a[0];
  }
  else
  {
    *(volatile uint32_t *)_frame.v17 = 0;
    if ( send_smc_cmd_2((int)_frame.v17) )
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
    alloc_tx_event("user cap:0x%x\n", *((volatile uint8_t *)a2 + 20));
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
    alloc_tx_event("user cap_fine:0x%x\n", *((volatile uint8_t *)a2 + 21));
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
  padding_data(v8);
  alloc_tx_event("set xtal_cap 0x%x\n", _frame.a1a[0]);
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
  *(volatile uint32_t *)off_122DE0 = *(volatile uint32_t *)off_122DE0 & 0xFF03FFFF | v14;
  alloc_tx_event("set xtal_cap_fine 0x%x\n", v13);
  if ( !a2[3] )
    goto LABEL_11;
LABEL_23:
  interrupt_dispatcher();
LABEL_11:
  v9 = *a2;
  _frame.v16[1] = a2[2];
  _frame.v16[0] = v9;
  rf_register_write(0, 2437, (int)_frame.v16, (int)_frame.v17, 1u, 0);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_122DC4)[47]) )
  {
    _frame.v16[0] = a2[1];
    rf_register_write(1, 5700, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rf_register_write(1, 5250, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rf_register_write(1, 5500, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    rf_register_write(1, 5500, (int)_frame.v16, (int)_frame.v17, 0, 1u);
    rf_calibrate_tx(0, 0x985u, 0x985u, 0, 0, 0);
  }
  v10 = __PAIR64__(*(volatile unsigned int *)aX, (unsigned int)off_151B28);
  v11 = (volatile int *)off_122DD4;
  *(volatile uint32_t *)(v5 + 12) = ((volatile uint32_t *)(uintptr_t)off_122DD0)[0];
  *(volatile uint64_t *)(v5 + 4) = v10;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v11);
  rx_process_packet_1(v5);
  return 0;
}


// ke_send_msg_74 @ 0x122df0
/* luna: Reads the device's six-byte MAC address from the RF or SMC source and sends it in a response packet. */
int ke_send_msg_74(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *response_payload; // r4
  uint16_t mac_bytes_0_1; // r3
  unsigned int mac_bytes_2_5; // r2
  struct __attribute__((packed)) { unsigned int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF
  } _frame;
  _frame.v8 = 0;
  _frame.a2a = 0;
  response_payload = (volatile uint8_t *)tx_send_pdu(116, a4, a3, 6);
  if ( (*(volatile uint32_t *)off_122E68 & 0x2000000) != 0 )
  {
    rf_cmd_8_write((void *)(&_frame.v8), &_frame.a2a);
    mac_bytes_2_5 = _frame.v8;
    mac_bytes_0_1 = _frame.a2a;
  }
  else
  {
    memset((void *)(_frame.v10), 0, 6);
    send_smc_cmd_0x400000((int)_frame.v10);
    mac_bytes_0_1 = __rev16(LOWORD(_frame.v10[0]));
    mac_bytes_2_5 = bswap32(*(volatile unsigned int *)((volatile char *)_frame.v10 + 2));
    _frame.v8 = mac_bytes_2_5;
    _frame.a2a = mac_bytes_0_1;
  }
  response_payload[1] = mac_bytes_0_1;
  response_payload[5] = mac_bytes_2_5;
  *response_payload = HIBYTE(mac_bytes_0_1);
  response_payload[3] = BYTE2(mac_bytes_2_5);
  response_payload[2] = HIBYTE(mac_bytes_2_5);
  response_payload[4] = BYTE1(mac_bytes_2_5);
  alloc_tx_event(aGetMacaddrXX, HIBYTE(mac_bytes_0_1), (uint8_t)mac_bytes_2_5, HIBYTE(mac_bytes_2_5), _frame.v8, _frame.a2a);
  rx_process_packet_1((int)response_payload);
  return 0;
}


// ke_send_msg_7c @ 0x122e70
int ke_send_msg_7c(int a1, volatile uint8_t *a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v5; // r5
  int v6; // r2
  volatile int *v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (volatile uint8_t *)tx_send_pdu(124, a4, a3, 2);
  if ( *a2 )
  {
    alloc_tx_event(aDriverStart);
    **(volatile uint8_t **)off_122F30 = 0;
  }
  else
  {
    alloc_tx_event(aDriverStop);
    **(volatile uint8_t **)off_122F30 = 3;
  }
  invoke_rom_api(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = (volatile int *)off_122F34;
    ((volatile uint32_t *)(uintptr_t)off_122F34)[47] = (((volatile uint32_t *)(uintptr_t)off_122F34)[47] & ~0xFFu) | ((uint8_t)((v6 & 0x20) != 0) & 0xFFu);
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = (volatile int *)off_122F34;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    ((volatile uint32_t *)(uintptr_t)off_122F34)[47] = (((volatile uint32_t *)(uintptr_t)off_122F34)[47] & ~0xFFu) | ((uint8_t)((v11 & 0x20) != 0) & 0xFFu);
  }
  if ( rf_reg_0x0f_bit_20() )
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
    alloc_tx_event("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    v9 = (v9 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v7 + 188)) & 0xFFu);
  }
  *v5 = v9;
  rx_process_packet_1((int)v5);
  return 0;
}


// rf_calib_table_lookup @ 0x122f40
int rf_calib_table_lookup(int a1, int a2, int a3, int a4) {
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
  v6 = dword_123004;
  v7 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(dword_123004 + 4 * (v4 + 330 * v5 + 2)) = *(volatile uint32_t *)a2;
  v8 = a4;
  if ( v4 == 1 )
  {
    v11 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123008 + 4);
    if ( v11 )
    {
      if ( (v11 & 0xFFF) != 0 )
        v7 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123008 + 4);
      else
        v7 = v7 & 0xFFF | v11 & 0xFFFFF000;
    }
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      *(volatile uint32_t *)off_123010 = v7;
      v13 = a3;
      v16 = v8;
      get_mac_ver();
      a3 = v13;
      v8 = v16;
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(*(volatile uint32_t *)off_123008 + 4 * v4);
    if ( !v9 )
      v9 = v7;
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(volatile uint32_t *)off_123018 = v9;
        v14 = a3;
        get_mac_ver();
        a3 = v14;
        v8 = a4;
      }
      else
      {
        if ( v4 > 2 )
          *(volatile uint32_t *)off_123014 = v9;
        else
          *(volatile uint32_t *)off_12300C = v9;
        v12 = a3;
        get_mac_ver();
        a3 = v12;
        v8 = a4;
      }
    }
  }
  mac_write_header_word(27, v8, a3);
  return 0;
}



// ke_send_msg_81 @ 0x12301c
int ke_send_msg_81(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (volatile uint8_t *)tx_send_pdu(129, a4, a3, 64);
  v5 = dword_123050;
  *v4 = 0;
  memcpy(v4 + 1, (void *)(uintptr_t)(v5), 36);
  v6 = (uint8_t)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  rx_process_packet_1((int)(uintptr_t)(v4));
  return 0;
}



// ke_send_msg_85 @ 0x123054
int ke_send_msg_85(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (volatile uint8_t *)tx_send_pdu(133, a4, a3, 1);
  v5 = mmio_read32_1(dword_12308C, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  alloc_tx_event("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  rx_process_packet_1((int)v4);
  return 0;
}


// ke_send_msg_88 @ 0x123094
int ke_send_msg_88(int a1, volatile uint32_t *a2, uint16_t a3, uint16_t a4) {
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
  v6 = tx_send_pdu(136, a4, a3, 8);
  v7 = v6;
  *(volatile uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((volatile uint8_t *)a2 + 4);
      ((volatile uint32_t *)(uintptr_t)off_123194)[93] = (((volatile uint32_t *)(uintptr_t)off_123194)[93] & ~0xFFu) | ((uint8_t)(v8) & 0xFFu);
      *(volatile uint8_t *)(v6 + 4) = v8;
      alloc_tx_event("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = (volatile int *)off_123194;
      v12 = *((volatile uint8_t *)a2 + 4);
      v13 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_123194)[90]);
      ((volatile uint32_t *)(uintptr_t)off_123194)[90] = (((volatile uint32_t *)(uintptr_t)off_123194)[90] & ~0xFF00u) | (((uint8_t)(v12) & 0xFFu) << 8);
      v11[91] = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          read_global_signed_flag(v6, v13);
          set_flag_send_event_42e();
        }
        else
        {
          clear_flag_send_event_42e();
        }
        v13 = *((volatile uint8_t *)v11 + 363);
      }
      *(volatile uint8_t *)(v7 + 4) = v13;
      alloc_tx_event("temp_comp_en:%x\n", v13);
      rx_process_packet_1(v7);
      result = 0;
      break;
    case 2:
      v14 = (volatile int *)off_123194;
      *(volatile uint8_t *)(v6 + 4) = HIBYTE(((volatile uint32_t *)(uintptr_t)off_123194)[90]);
      v15 = rf_power_adjust();
      *(volatile uint8_t *)(v7 + 5) = v15;
      alloc_tx_event("temp_comp_en:%x,t=%d\n", *((volatile uint8_t *)v14 + 363), v15);
      rx_process_packet_1(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = (volatile int *)off_123194;
      ((volatile uint32_t *)(uintptr_t)off_123194)[98] = v16;
      alloc_tx_event("set ext_flags:0x%x\n", v16);
      *(volatile uint32_t *)(v7 + 4) = v17[98];
      rx_process_packet_1(v7);
      result = 0;
      break;
    case 4:
      v18 = ((volatile uint32_t *)(uintptr_t)off_123194)[98];
      *(volatile uint32_t *)(v6 + 4) = v18;
      alloc_tx_event("get ext_flags:0x%x\n", v18);
      rx_process_packet_1(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ ((volatile uint32_t *)(uintptr_t)off_123194)[98]) & a2[1] ^ ((volatile uint32_t *)(uintptr_t)off_123194)[98];
      ((volatile uint32_t *)(uintptr_t)off_123194)[98] = v10;
      *(volatile uint32_t *)(v6 + 4) = v10;
      alloc_tx_event("mask set ext_flags:0x%x\n", v10);
      rx_process_packet_1(v7);
      result = 0;
      break;
    default:
LABEL_3:
      rx_process_packet_1(v7);
      result = 0;
      break;
  }
  return result;
}


// bt_patch_apply @ 0x1231b0
int bt_patch_apply(int a1, int a2, int a3, int a4) {
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
  *(volatile uint8_t *)off_123414 = 1;
  alloc_tx_event("%s: %d\n", aMmSetResumeRes, 708);
  alloc_tx_event(
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
  alloc_tx_event("sizeof %d, %d, %d, %d\n", 32, 44, 108, 112);
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
        alloc_tx_event("sub_msg_id: 0x%x\n", v9);
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
        alloc_tx_event("skip sub_msg_id: 0x%x\n", v8);
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
        alloc_tx_event(
          "add vif req:cnt=%d, p2p=%d, macaddr=%x,%x,%x\n",
          *(volatile uint32_t *)(a2 + 704),
          *(volatile uint8_t *)(a2 + 668),
          *(volatile uint16_t *)(a2 + 662),
          *(volatile uint16_t *)(a2 + 664),
          *(volatile uint16_t *)(a2 + 666));
        if ( *(volatile uint32_t *)(a2 + 704) )
        {
          transmit_radio_packet(
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
        v14 = (void ( *)(unsigned int, int, unsigned int, int))hci_event_handler(v8, v12);
        v15 = v14;
        if ( v14 )
        {
          alloc_tx_event("func %p for msg_id:0x%x dest_id:0x%x\n", v14, v8, _frame.v16);
          v15(v8, v13, v12, a4);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else
        {
          alloc_tx_event("func not found for msg_id:0x%x dest_id:0x%x\n", v8, _frame.v16);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
      }
    }
  }
LABEL_9:
  *(volatile uint8_t *)off_123414 = 0;
  return 0;
}


// ke_send_msg_54 @ 0x12343c
int ke_send_msg_54(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (volatile uint8_t *)tx_send_pdu(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(volatile uint8_t *)(dword_12348C + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    ((int (*)())lll_conn_phy_get)();
LABEL_5:
    rx_process_packet_1((int)(uintptr_t)(v4));
    return 0;
  }
  ((int (*)())lll_conn_phy_ld_get)();
  rx_process_packet_1((int)(uintptr_t)(v4));
  return 0;
}



// parse_subframe_header @ 0x123490
int parse_subframe_header(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (volatile uint8_t *)tx_send_pdu(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_12351C + 1320 * v5;
  if ( !*(volatile uint8_t *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( lll_conn_state_match(
           v6,
           0,
           a2[3],
           a2[2],
           *((volatile uint32_t *)a2 + 2),
           *((volatile uint32_t *)a2 + 1),
           (*(volatile uint16_t *)(v6 + 222) << 10)
         + *(volatile uint32_t *)off_123520 / (*(volatile uint16_t *)(v6 + 222) << 10) * (*(volatile uint16_t *)(v6 + 222) << 10)
         + *((volatile uint32_t *)off_123524 + 4)
         - *(volatile uint32_t *)off_123520
         + *((volatile uint32_t *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    rx_process_packet_1((int)(uintptr_t)(v4));
    return 0;
  }
  *v4 = ((int (*)())lll_conn_ready_check)();
  rx_process_packet_1((int)(uintptr_t)(v4));
  return 0;
}



// util_read_u8 @ 0x123528
int util_read_u8(int a1, volatile uint8_t *a2, int a3, uint16_t a4) {
  mfp_key_update(*a2, a4);
  return 0;
}


// ke_msg_send @ 0x123538
int ke_msg_send(int a1, int a2) {
  co_list_push(a2);
  return 1;
}



// ke_event_schedule @ 0x123544
int ke_event_schedule(int a1, int a2) {
  ke_event_set(a2);
  return 1;
}



// mac_data_request @ 0x123550
int mac_data_request(int a1, volatile uint8_t *a2, int a3, int a4) {
  char v7; // r0
  char v9; // r6
  volatile uint8_t *v10; // r0

  v7 = cfm_event_handler(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (volatile uint8_t *)tx_send_pdu(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    rx_process_packet_1((int)(uintptr_t)(v10));
  }
  return 0;
}



// bt_parse_colon @ 0x123588
int bt_parse_colon(int a1, volatile uint8_t *a2, int a3, int a4) {
  bsscfg_get(*a2);
  mac_write_header_word(58, a4, a3);
  return 0;
}



// rx_parse_hdr @ 0x1235a8
int rx_parse_hdr(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v5; // r6
  int v6; // r0
  int v7; // r1
  BOOL v9; // r0
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
    v14 = ll_get_tx_power_alt(v6, v7);
    v10 = a3;
    if ( v14 )
    {
      ((int (*)())dma_rx_ring)(dword_123638 + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = ll_get_tx_power(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_12363C + 32 * *(volatile uint8_t *)(v15 + 12 * a2[2] + dword_123638 + 453);
      *(volatile uint16_t *)(v15 + 6 * a2[2] + dword_123638 + 354) = 0;
      *(volatile uint16_t *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (volatile uint8_t *)tx_send_pdu(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  rx_process_packet_1((int)(uintptr_t)(v12));
  return 0;
}



// bt_parse_cr @ 0x123640
int bt_parse_cr(int a1, volatile uint8_t *a2, int a3, int a4) {
  ll_channel_hop(*a2);
  mac_write_header_word(13, a4, a3);
  return 0;
}



// rf_get_status_1 @ 0x123660
int rf_get_status_1(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r0

  if ( **(volatile int16_t **)off_1236A4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(volatile uint32_t *)off_1236A8) + 8 >= v7 )
      goto LABEL_3;
    irq_disable_mmio_write(dword_1236B0, dword_1236AC, 1801);
  }
  v7 = *a2;
LABEL_3:
  rf_get_version(v7);
  mac_write_header_word(39, a4, a3);
  return 0;
}



// ke_mem_alloc @ 0x1236b4
int ke_mem_alloc(int a1, volatile uint8_t *a2, int a3, int a4) {
  volatile uint8_t *v5; // r0
  volatile int16_t **v6; // r6
  volatile uint8_t *v7; // r5
  int v8; // r3

  v5 = (volatile uint8_t *)tx_send_pdu(37, a4, a3, 2);
  v6 = (volatile int16_t **)off_12376C;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (irq_disable_mmio_write(dword_12377C, dword_123774, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        irq_disable_mmio_write(dword_123778, dword_123774, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(volatile uint32_t *)off_123770 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(volatile uint32_t *)off_123770 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(volatile uint32_t *)off_123770 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(volatile uint32_t *)off_123770 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = ((int (*)())ll_parse_pdu)(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  rx_process_packet_1((int)(uintptr_t)(v7));
  return 0;
}



// trace_printf @ 0x123780
int trace_printf(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_1237BC + 1320 * *a2;
  v6 = tx_send_pdu(47, a4, a3, 2);
  *(volatile uint8_t *)(v4 + 110) = a2[1];
  v7 = v6;
  compute_byte_delta(v4);
  get_calibration_value(v4, (void *)(uintptr_t)(v7 + 1), (void *)(uintptr_t)(v7));
  rx_process_packet_1(v7);
  return 0;
}



// mem_copy_log @ 0x1237c0
int mem_copy_log(int a1, volatile uint8_t *a2, int a3, int a4) {
  set_global_config_bytes(a2);
  mac_write_header_word(110, a4, a3);
  return 0;
}



// mem_setup_log @ 0x1237e0
int mem_setup_log(int a1, int a2, int a3, int a4) {
  rx_buf_align_desc(a2);
  check_feature_flag(256, aSetMuEdca);
  mac_write_header_word(108, a4, a3);
  return 0;
}


// parse_parameter @ 0x12380c
int parse_parameter(int a1, int a2, int a3, int a4) {
  volatile int *v4; // r4
  volatile uint32_t *v5; // r5
  int v6; // r6
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_123878 = 1;
  }
  v4 = (volatile int *)off_12387C;
  v5 = (void *)(uintptr_t)(off_123880);
  v6 = *(volatile uint32_t *)off_123880;
  ++*(volatile uint32_t *)off_12387C;
  rf_set_power_on();
  check_clock_status(v7, v8, v9);
  unknown_handler_12c798();
  vendor_platform_init();
  v10 = alloc_shared_ctx();
  get_rf_state(v10);
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(volatile uint32_t *)off_123878;
    *v4 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  mac_write_header_word(1, a4, a3);
  hci_cmd_preprocess(0, 0);
  return 0;
}


