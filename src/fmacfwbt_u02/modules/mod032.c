// send_le_scan_command @ 0x122f5c
int send_le_scan_command(int a1, volatile int *a2, uint16_t a3, uint16_t a4) {
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
  v5 = bt_buf_alloc(106, a4, a3, 16);
  if ( (*(volatile uint32_t *)off_123134 & 0x2000000) != 0 )
  {
    syscall6_get_status(_frame.a1a);
    syscall6_check_done(&_frame.a1a[1]);
    ke_event_schedule_1("read xtal_cap efuse=%x,%x\n", _frame.a1a[0], _frame.a1a[1]);
    v6 = _frame.a1a[0];
  }
  else
  {
    *(volatile uint32_t *)_frame.v17 = 0;
    if ( ioctl_cmd_1((int)_frame.v17) )
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
    ke_event_schedule_1("user cap:0x%x\n", *((volatile uint8_t *)a2 + 20));
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
    ke_event_schedule_1("user cap_fine:0x%x\n", *((volatile uint8_t *)a2 + 21));
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
  set_periph_status(v8);
  ke_event_schedule_1("set xtal_cap 0x%x\n", _frame.a1a[0]);
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
  *(volatile uint32_t *)off_123154 = *(volatile uint32_t *)off_123154 & 0xFF03FFFF | v14;
  ke_event_schedule_1("set xtal_cap_fine 0x%x\n", v13);
  if ( !a2[3] )
    goto LABEL_11;
LABEL_23:
  bt_dispatch();
LABEL_11:
  v9 = *a2;
  _frame.v16[1] = a2[2];
  _frame.v16[0] = v9;
  sdio_transfer_setup(0, 2437, (int)_frame.v16, (int)_frame.v17, 1u, 0);
  if ( LOBYTE(((volatile uint32_t *)(uintptr_t)off_123138)[47]) )
  {
    _frame.v16[0] = a2[1];
    sdio_transfer_setup(1, 5700, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    sdio_transfer_setup(1, 5250, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    sdio_transfer_setup(1, 5500, (int)_frame.v16, (int)_frame.v17, 1u, 0);
    sdio_transfer_setup(1, 5500, (int)_frame.v16, (int)_frame.v17, 0, 1u);
    format_log_message(0, 2437, 0x985u, 0, 0, 0);
  }
  v10 = (v10 & ~0xFFFFFFFFull) | ((uint32_t)(((volatile uint32_t *)(uintptr_t)off_12313C)[2]) & 0xFFFFFFFFu);
  v10 = (v10 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*(volatile uint32_t *)off_123140) << 32);
  v11 = (volatile int *)off_123148;
  *(volatile uint32_t *)(v5 + 12) = *(volatile uint32_t *)off_123144;
  *(volatile uint64_t *)(v5 + 4) = v10;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v11);
  hci_evt_send(v5);
  return 0;
}


// send_hci_reset_cmd @ 0x123164
int send_hci_reset_cmd(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  struct __attribute__((packed)) { unsigned int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF
  } _frame;
  _frame.v8 = 0;
  _frame.a2a = 0;
  v4 = (volatile uint8_t *)bt_buf_alloc(116, a4, a3, 6);
  if ( (*(volatile uint32_t *)off_1231DC & 0x2000000) != 0 )
  {
    syscall8_op((void *)(&_frame.v8), &_frame.a2a);
    v6 = _frame.v8;
    v5 = _frame.a2a;
  }
  else
  {
    memset((void *)(_frame.v10), 0, 6);
    ioctl2_cmd_2((int)_frame.v10);
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
  ke_event_schedule_1(aGetMacaddrXX, HIBYTE(v5), (uint8_t)v6, HIBYTE(v6), _frame.v8, _frame.a2a);
  hci_evt_send((int)v4);
  return 0;
}


// send_cmd_0x7c @ 0x1231e4
int send_cmd_0x7c(int a1, volatile uint8_t *a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v5; // r5
  int v6; // r2
  volatile int *v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (volatile uint8_t *)bt_buf_alloc(124, a4, a3, 2);
  if ( *a2 )
  {
    ke_event_schedule_1(aDriverStart);
    **(volatile uint8_t **)off_1232A4 = 0;
  }
  else
  {
    ke_event_schedule_1(aDriverStop);
    **(volatile uint8_t **)off_1232A4 = 3;
  }
  rom_call_extract_byte(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = (volatile int *)off_1232A8;
    ((volatile uint32_t *)(uintptr_t)off_1232A8)[47] = (((volatile uint32_t *)(uintptr_t)off_1232A8)[47] & ~0xFFu) | ((uint8_t)((v6 & 0x20) != 0) & 0xFFu);
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = (volatile int *)off_1232A8;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    ((volatile uint32_t *)(uintptr_t)off_1232A8)[47] = (((volatile uint32_t *)(uintptr_t)off_1232A8)[47] & ~0xFFu) | ((uint8_t)((v11 & 0x20) != 0) & 0xFFu);
  }
  if ( get_hw_info_bit20() )
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
    ke_event_schedule_1("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    v9 = (v9 & ~0xFFu) | ((uint8_t)(*((volatile uint8_t *)v7 + 188)) & 0xFFu);
  }
  *v5 = v9;
  hci_evt_send((int)v5);
  return 0;
}


// lookup_tx_power_table @ 0x1232b4
int lookup_tx_power_table(int a1, int a2, int a3, int a4) {
  unsigned int v4; // r4
  int v5; // r6
  int v6; // r7
  unsigned int v7; // r5
  unsigned int v9; // r0
  int v10; // r3
  int v12; // r3
  int v13; // [sp+0h] [bp-Ch]
  int v14; // [sp+0h] [bp-Ch]
  int v15; // [sp+0h] [bp-Ch]
  int v16; // [sp+4h] [bp-8h]
  int v17; // [sp+4h] [bp-8h]
  int v18; // [sp+4h] [bp-8h]

  v4 = *(volatile uint8_t *)(a2 + 5);
  v5 = *(volatile uint8_t *)(a2 + 6);
  v6 = dword_123378;
  v7 = *(volatile uint32_t *)a2;
  *(volatile uint32_t *)(dword_123378 + 4 * (v4 + 330 * v5 + 2)) = *(volatile uint32_t *)a2;
  if ( v4 == 1 )
  {
    v12 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12337C + 4);
    if ( v12 )
    {
      if ( (v12 & 0xFFF) != 0 )
        v7 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12337C + 4);
      else
        v7 = v7 & 0xFFF | v12 & 0xFFFFF000;
    }
    v10 = *(volatile uint8_t *)(v6 + 1320 * v5 + 108);
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      *(volatile uint32_t *)off_123384 = v7;
      v14 = a3;
      v17 = a4;
      wait_rf_calibration();
      a3 = v14;
      a4 = v17;
    }
  }
  else
  {
    v9 = *(volatile uint32_t *)(*(volatile uint32_t *)off_12337C + 4 * v4);
    v10 = *(volatile uint8_t *)(v6 + 1320 * v5 + 108);
    if ( !v9 )
      v9 = v7;
    if ( *(volatile uint8_t *)(v6 + 1320 * v5 + 108) )
    {
      if ( v4 == 2 )
      {
        *(volatile uint32_t *)off_12338C = v9;
        v15 = a3;
        v18 = a4;
        wait_rf_calibration();
        a3 = v15;
        a4 = v18;
      }
      else
      {
        if ( v4 > 2 )
          *(volatile uint32_t *)off_123388 = v9;
        else
          *(volatile uint32_t *)off_123380 = v9;
        v13 = a3;
        v16 = a4;
        wait_rf_calibration();
        a3 = v13;
        a4 = v16;
      }
    }
  }
  ((int (*)())hci_evt_alloc_send)(27, a4, a3, v10);
  return 0;
}



// rf_reg_write_81 @ 0x123390
int rf_reg_write_81(int a1, int a2, int a3, int a4) {
  volatile uint8_t *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (volatile uint8_t *)bt_buf_alloc(129, a4, a3, 64);
  v5 = dword_1233C4;
  *v4 = 0;
  memcpy(v4 + 1, (void *)(uintptr_t)(v5), 36);
  v6 = (uint8_t)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  hci_evt_send((int)(uintptr_t)(v4));
  return 0;
}



// rf_reg_write_85 @ 0x1233c8
int rf_reg_write_85(int a1, int a2, uint16_t a3, uint16_t a4) {
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r3

  v4 = (volatile uint8_t *)bt_buf_alloc(133, a4, a3, 1);
  v5 = atomic_reg_read(dword_123400, 1);
  v6 = (BYTE2(v5) ^ 1) & 1;
  *v4 = v6;
  ke_event_schedule_1("read reg =%x, wifi disable regbit = %d, cfm->wifi_disable=%d\n", v5, HIWORD(v5) & 1, v6);
  hci_evt_send((int)v4);
  return 0;
}


// rf_reg_write_88 @ 0x123408
int rf_reg_write_88(int a1, volatile uint32_t *a2, uint16_t a3, uint16_t a4) {
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
  v6 = bt_buf_alloc(136, a4, a3, 8);
  v7 = v6;
  *(volatile uint32_t *)v6 = v5;
  switch ( v5 )
  {
    case 0:
      v8 = *((volatile uint8_t *)a2 + 4);
      ((volatile uint32_t *)(uintptr_t)off_123508)[93] = (((volatile uint32_t *)(uintptr_t)off_123508)[93] & ~0xFFu) | ((uint8_t)(v8) & 0xFFu);
      *(volatile uint8_t *)(v6 + 4) = v8;
      ke_event_schedule_1("tim_bcmc_ign:%x\n", v8);
      goto LABEL_3;
    case 1:
      v11 = (volatile int *)off_123508;
      v12 = *((volatile uint8_t *)a2 + 4);
      v13 = HIBYTE(((volatile uint32_t *)(uintptr_t)off_123508)[90]);
      ((volatile uint32_t *)(uintptr_t)off_123508)[90] = (((volatile uint32_t *)(uintptr_t)off_123508)[90] & ~0xFF00u) | (((uint8_t)(v12) & 0xFFu) << 8);
      v11[91] = a2[2];
      if ( v12 != v13 )
      {
        if ( v12 )
        {
          mmio_init_check();
          rf_afe_enable();
        }
        else
        {
          rf_afe_disable();
        }
        v13 = *((volatile uint8_t *)v11 + 363);
      }
      *(volatile uint8_t *)(v7 + 4) = v13;
      ke_event_schedule_1("temp_comp_en:%x\n", v13);
      hci_evt_send(v7);
      result = 0;
      break;
    case 2:
      v14 = (volatile int *)off_123508;
      *(volatile uint8_t *)(v6 + 4) = HIBYTE(((volatile uint32_t *)(uintptr_t)off_123508)[90]);
      v15 = ke_event_handler();
      *(volatile uint8_t *)(v7 + 5) = v15;
      ke_event_schedule_1("temp_comp_en:%x,t=%d\n", *((volatile uint8_t *)v14 + 363), v15);
      hci_evt_send(v7);
      result = 0;
      break;
    case 3:
      v16 = a2[1];
      v17 = (volatile int *)off_123508;
      ((volatile uint32_t *)(uintptr_t)off_123508)[98] = v16;
      ke_event_schedule_1("set ext_flags:0x%x\n", v16);
      *(volatile uint32_t *)(v7 + 4) = v17[98];
      hci_evt_send(v7);
      result = 0;
      break;
    case 4:
      v18 = ((volatile uint32_t *)(uintptr_t)off_123508)[98];
      *(volatile uint32_t *)(v6 + 4) = v18;
      ke_event_schedule_1("get ext_flags:0x%x\n", v18);
      hci_evt_send(v7);
      result = 0;
      break;
    case 5:
      v10 = (a2[2] ^ ((volatile uint32_t *)(uintptr_t)off_123508)[98]) & a2[1] ^ ((volatile uint32_t *)(uintptr_t)off_123508)[98];
      ((volatile uint32_t *)(uintptr_t)off_123508)[98] = v10;
      *(volatile uint32_t *)(v6 + 4) = v10;
      ke_event_schedule_1("mask set ext_flags:0x%x\n", v10);
      hci_evt_send(v7);
      result = 0;
      break;
    default:
LABEL_3:
      hci_evt_send(v7);
      result = 0;
      break;
  }
  return result;
}


// platform_hw_init @ 0x123524
int platform_hw_init(int a1, int a2, int a3, int a4) {
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
  *(volatile uint8_t *)off_123788 = 1;
  ke_event_schedule_1("%s: %d\n", aMmSetResumeRes, 708);
  ke_event_schedule_1(
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
  ke_event_schedule_1("sizeof %d, %d, %d, %d\n", 32, 44, 108, 112);
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
        ke_event_schedule_1("sub_msg_id: 0x%x\n", v9);
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
        ke_event_schedule_1("skip sub_msg_id: 0x%x\n", v8);
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
        ke_event_schedule_1(
          "add vif req:cnt=%d, p2p=%d, macaddr=%x,%x,%x\n",
          *(volatile uint32_t *)(a2 + 704),
          *(volatile uint8_t *)(a2 + 668),
          *(volatile uint16_t *)(a2 + 662),
          *(volatile uint16_t *)(a2 + 664),
          *(volatile uint16_t *)(a2 + 666));
        if ( *(volatile uint32_t *)(a2 + 704) )
        {
          wlc_ioctl(
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
        v14 = (void ( *)(unsigned int, int, unsigned int, int))hci_cmd_send_vendor(v8, v12);
        v15 = v14;
        if ( v14 )
        {
          ke_event_schedule_1("func %p for msg_id:0x%x dest_id:0x%x\n", v14, v8, _frame.v16);
          v15(v8, v13, v12, a4);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else
        {
          ke_event_schedule_1("func not found for msg_id:0x%x dest_id:0x%x\n", v8, _frame.v16);
          if ( *(volatile uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
      }
    }
  }
LABEL_9:
  *(volatile uint8_t *)off_123788 = 0;
  return 0;
}


// rf_reg_write_54 @ 0x1237b0
int rf_reg_write_54(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0

  v3 = (volatile uint8_t *)bt_buf_alloc(84, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 || !*(volatile uint8_t *)(dword_123800 + 1320 * v5 + 1224) )
    goto LABEL_5;
  *v4 = 0;
  if ( a2[1] )
  {
    bt_conn_set_flag(dword_123800 + 1320 * v5, a2[1]);
LABEL_5:
    hci_evt_send((int)(uintptr_t)(v4));
    return 0;
  }
  bt_conn_get_flag(dword_123800 + 1320 * v5);
  hci_evt_send((int)(uintptr_t)(v4));
  return 0;
}



// rf_reg_write_53 @ 0x123804
int rf_reg_write_53(int a1, volatile uint8_t *a2) {
  volatile uint8_t *v3; // r0
  volatile uint8_t *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (volatile uint8_t *)bt_buf_alloc(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_123890 + 1320 * v5;
  if ( !*(volatile uint8_t *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( bt_conn_state_machine(
           v6,
           0,
           a2[3],
           a2[2],
           *((volatile uint32_t *)a2 + 2),
           *((volatile uint32_t *)a2 + 1),
           (*(volatile uint16_t *)(v6 + 222) << 10)
         + *(volatile uint32_t *)off_123894 / (*(volatile uint16_t *)(v6 + 222) << 10) * (*(volatile uint16_t *)(v6 + 222) << 10)
         + *((volatile uint32_t *)off_123898 + 4)
         - *(volatile uint32_t *)off_123894
         + *((volatile uint32_t *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    hci_evt_send((int)(uintptr_t)(v4));
    return 0;
  }
  *v4 = ((int (*)())bt_conn_get_state)();
  hci_evt_send((int)(uintptr_t)(v4));
  return 0;
}



// ipc_msg_send_byte @ 0x12389c
int ipc_msg_send_byte(int a1, volatile uint8_t *a2, int a3, uint16_t a4) {
  ipc_msg_send(*a2, a4);
  return 0;
}


// call_125ac8 @ 0x1238ac
int call_125ac8(int a1, int a2) {
  list_remove(a2);
  return 1;
}



// call_125cbc @ 0x1238b8
int call_125cbc(int a1, int a2) {
  callback_set(a2);
  return 1;
}



// call_127d80_remapped @ 0x1238c4
int call_127d80_remapped(int a1, volatile uint8_t *a2, int a3, int a4) {
  char v7; // r0
  char v9; // r6
  volatile uint8_t *v10; // r0

  v7 = rx_packet_handler_1(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (volatile uint8_t *)bt_buf_alloc(71, a4, a3, 3);
    *v10 = *a2;
    v10[1] = v9;
    v10[2] = 4;
    hci_evt_send((int)(uintptr_t)(v10));
  }
  return 0;
}



// output_byte_colon @ 0x1238fc
int output_byte_colon(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r3

  get_entry_by_index(*a2);
  ((int (*)())hci_evt_alloc_send)(58, a4, a3, v4);
  return 0;
}



// load_three_bytes @ 0x12391c
int load_three_bytes(int a1, volatile uint8_t *a2, int a3, int a4) {
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
    v14 = phy_read_channel(v6, v7);
    v10 = a3;
    if ( v14 )
    {
      ((int (*)())get_instance_handle_cond)(dword_1239AC + 696 * a2[1], a2[2], a3);
      v11 = 2;
      v10 = a3;
      goto LABEL_4;
    }
  }
  else
  {
    v9 = phy_read_band(v6, v7);
    v10 = a3;
    if ( v9 )
    {
      v15 = 696 * a2[1];
      v16 = dword_1239B0 + 32 * *(volatile uint8_t *)(v15 + 12 * a2[2] + dword_1239AC + 453);
      *(volatile uint16_t *)(v15 + 6 * a2[2] + dword_1239AC + 354) = 0;
      *(volatile uint16_t *)(v16 + 12) = 0;
      v11 = 2;
      goto LABEL_4;
    }
  }
  v11 = 3;
LABEL_4:
  v12 = (volatile uint8_t *)bt_buf_alloc(43, a4, v10, 3);
  *v12 = a2[1];
  v12[1] = a2[2];
  v12[2] = v11;
  hci_evt_send((int)(uintptr_t)(v12));
  return 0;
}



// output_byte_cr @ 0x1239b4
int output_byte_cr(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r3

  phy_txpower_calc(*a2);
  ((int (*)())hci_evt_alloc_send)(13, a4, a3, v4);
  return 0;
}



// check_wlc_state @ 0x1239d4
int check_wlc_state(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v7; // r0
  int v8; // r3

  if ( **(volatile int16_t **)off_123A18 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(volatile uint32_t *)off_123A1C) + 8 >= v7 )
      goto LABEL_3;
    mmio_irq_clear(dword_123A24, dword_123A20, 1801);
  }
  v7 = *a2;
LABEL_3:
  check_hw_version(v7);
  ((int (*)())hci_evt_alloc_send)(39, a4, a3, v8);
  return 0;
}



// process_percent_char @ 0x123a28
int process_percent_char(int a1, volatile uint8_t *a2, int a3, int a4) {
  volatile uint8_t *v5; // r0
  volatile int16_t **v6; // r6
  volatile uint8_t *v7; // r5
  int v8; // r3

  v5 = (volatile uint8_t *)bt_buf_alloc(37, a4, a3, 2);
  v6 = (volatile int16_t **)off_123AE0;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( *a2 <= 5u || (mmio_irq_clear(dword_123AF0, dword_123AE8, 1725), **v6 < 0) )
    {
      if ( a2[4] > 0x20u )
        mmio_irq_clear(dword_123AEC, dword_123AE8, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0u:
    case 1u:
    case 3u:
      v8 = (*(volatile uint32_t *)off_123AE4 >> 6) & 1;
      goto LABEL_4;
    case 2u:
    case 5u:
    case 8u:
      v8 = (*(volatile uint32_t *)off_123AE4 >> 7) & 1;
      goto LABEL_4;
    case 4u:
      v8 = (*(volatile uint32_t *)off_123AE4 >> 13) & 1;
      goto LABEL_4;
    case 6u:
    case 7u:
      v8 = (*(volatile uint32_t *)off_123AE4 >> 9) & 1;
LABEL_4:
      if ( v8 && a2[4] <= 0x20u && *a2 <= 5u )
      {
        v7[1] = ((int (*)())rx_handle_frame)(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  hci_evt_send((int)(uintptr_t)(v7));
  return 0;
}



// bsscfg_indexed_lookup @ 0x123af4
int bsscfg_indexed_lookup(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r5
  int v6; // r0
  int v7; // r4

  v4 = dword_123B30 + 1320 * *a2;
  v6 = bt_buf_alloc(47, a4, a3, 2);
  *(volatile uint8_t *)(v4 + 110) = a2[1];
  v7 = v6;
  scan_rssi_compare(v4);
  util_chk_field(v4, (void *)(uintptr_t)(v7 + 1), (void *)(uintptr_t)(v7));
  hci_evt_send(v7);
  return 0;
}



// output_n_char @ 0x123b34
int output_n_char(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v4; // r3

  set_rf_channel(a2);
  ((int (*)())hci_evt_alloc_send)(110, a4, a3, v4);
  return 0;
}



// log_debug @ 0x123b54
int log_debug(int a1, int a2, int a3, int a4) {
  tx_buffer_cleanup(a2);
  state_check_feature(256, aSetMuEdca);
  hci_evt_alloc_send(108, a4, a3);
  return 0;
}


// irq_disable_save @ 0x123b80
int irq_disable_save(int a1, int a2, int a3, int a4) {
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
    *(volatile uint32_t *)off_123BEC = 1;
  }
  v4 = (volatile int *)off_123BF0;
  v5 = (void *)(uintptr_t)(off_123BF4);
  v6 = *(volatile uint32_t *)off_123BF4;
  ++*(volatile uint32_t *)off_123BF0;
  mmio_write_poll_clear();
  sys_irq_dispatch(v7, v8, v9);
  irq_lock_small();
  llm_env_reset();
  controller_init();
  run_deferred_init();
  v10 = *v4;
  *v5 = v6;
  if ( v10 )
  {
    v11 = v10 - 1;
    v12 = *(volatile uint32_t *)off_123BEC;
    *v4 = v11;
    if ( !v11 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  hci_evt_alloc_send(1, a4, a3);
  hci_cmd_send(0, 0);
  return 0;
}


