// ke_task_handler @ 0x114318
int ke_task_handler(int a1, int a2, unsigned int a3) {
  int v6; // r4
  unsigned int v7; // r5
  union {
    uint8_t _rom_block[72];
    struct __attribute__((packed)) {
      uint32_t v9[2];       // +0x00 magic, +0x04 flags
      uint8_t _rom_pad1[8]; // +0x08..+0x0f unused
      uint8_t v10[4];       // +0x10
      uint8_t v11[12];      // +0x14
      uint8_t v12[20];      // +0x20
      uint8_t v13[4];       // +0x34
      uint8_t _rom_pad2[4]; // +0x38..+0x3b unused
      uint8_t v14[4];       // +0x3c
      uint8_t v15[4];       // +0x40
      uint8_t v16[4];       // +0x44
    } f;
  } _frame;
  if ( !*(volatile uint32_t *)off_114410 )
    ke_event_busy_check();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114414 + 0x2000, 72, _frame._rom_block);
  if ( _frame.f.v9[0] != dword_114418 )
    return -1;
  v6 = a1 & _frame.f.v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    memcpy((void *)(uintptr_t)(a2), _frame.f.v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
LABEL_7:
      if ( (v6 & 4) == 0 )
        goto LABEL_8;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_7;
  }
  memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
LABEL_8:
    if ( (v6 & 8) == 0 )
      goto LABEL_9;
    goto LABEL_20;
  }
LABEL_22:
  memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
LABEL_9:
    if ( (v6 & 0x20) == 0 )
      goto LABEL_10;
    goto LABEL_18;
  }
LABEL_20:
  memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
LABEL_10:
    if ( (v6 & 0x40) == 0 )
      goto LABEL_11;
    goto LABEL_16;
  }
LABEL_18:
  memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
LABEL_11:
    if ( (v6 & 0x80) == 0 )
      goto LABEL_12;
    goto LABEL_15;
  }
LABEL_16:
  memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
LABEL_15:
    memcpy((void *)(uintptr_t)(a2 + v7), _frame.f.v16, 4);
    v7 += 4;
  }
LABEL_12:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}



// ke_task_process @ 0x11441c
int ke_task_process(int a1, volatile char *a2, unsigned int a3) {
  volatile uint32_t *v6; // r7
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3
  struct __attribute__((packed)) { int v13; // [sp+0h] [bp-48h] BYREF
  int v14; // [sp+4h] [bp-44h]
  char _pad2[8]; char a1a[4]; // [sp+10h] [bp-38h] BYREF
  char v16[12]; // [sp+14h] [bp-34h] BYREF
  char v17[20]; // [sp+20h] [bp-28h] BYREF
  char v18[8]; // [sp+34h] [bp-14h] BYREF
  char v19[4]; // [sp+3Ch] [bp-Ch] BYREF
  char v20[4]; // [sp+40h] [bp-8h] BYREF
  char v21[4]; // [sp+44h] [bp-4h] BYREF
  } _frame;
  if ( !*(volatile uint32_t *)off_114548 )
    ke_event_busy_check(a1);
  v6 = (void *)(uintptr_t)(off_11454C);
  v7 = dword_114550;
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_11454C + 0x2000, 72, &_frame.v13);
  if ( _frame.v13 == v7 )
  {
    v8 = a1 & 1;
    _frame.v14 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    memset(&_frame.v13, 0xFFu, 0x48u);
    _frame.v13 = v7;
    v8 = a1 & 1;
    _frame.v14 = a1;
    if ( (a1 & 1) == 0 )
    {
LABEL_5:
      if ( (a1 & 2) == 0 )
        goto LABEL_6;
      goto LABEL_15;
    }
  }
  memcpy(_frame.a1a, a2, 4u);
  v8 = 4;
  if ( (a1 & 2) == 0 )
  {
LABEL_6:
    if ( (a1 & 4) == 0 )
      goto LABEL_7;
    goto LABEL_16;
  }
LABEL_15:
  memcpy(_frame.v16, &a2[v8], 0xCu);
  v8 += 12;
  if ( (a1 & 4) == 0 )
  {
LABEL_7:
    if ( (a1 & 8) == 0 )
      goto LABEL_8;
    goto LABEL_17;
  }
LABEL_16:
  memcpy(_frame.v17, &a2[v8], 0x14u);
  v8 += 20;
  if ( (a1 & 8) == 0 )
  {
LABEL_8:
    v9 = a1 << 26;
    if ( (a1 & 0x20) == 0 )
      goto LABEL_9;
    goto LABEL_18;
  }
LABEL_17:
  memcpy(_frame.v18, &a2[v8], 4u);
  v9 = a1 << 26;
  v8 += 4;
  if ( (a1 & 0x20) == 0 )
  {
LABEL_9:
    v10 = a1 << 25;
    if ( (a1 & 0x40) == 0 )
      goto LABEL_10;
    goto LABEL_19;
  }
LABEL_18:
  memcpy(_frame.v19, &a2[v8], 4u);
  v10 = a1 << 25;
  v8 += 4;
  if ( (a1 & 0x40) == 0 )
  {
LABEL_10:
    v11 = a1 << 24;
    if ( (a1 & 0x80) == 0 )
      goto LABEL_11;
LABEL_20:
    memcpy(_frame.v21, &a2[v8], 4u);
    if ( a3 >= v8 + 4 )
      goto LABEL_12;
LABEL_21:
    dispatch_event_handler_1(aFlashCalibInfo, v9, v10, v11, _frame.v13, _frame.v14);
    goto LABEL_12;
  }
LABEL_19:
  memcpy(_frame.v20, &a2[v8], 4u);
  v11 = a1 << 24;
  v8 += 4;
  if ( (a1 & 0x80) != 0 )
    goto LABEL_20;
LABEL_11:
  if ( a3 < v8 )
    goto LABEL_21;
LABEL_12:
  ke_event_schedule_alt();
  ke_event_schedule_prio();
  return ((int (*)())MEMD(0x1E0))(*v6 + 0x2000, 72);
}


// bus_read32 @ 0x114558
int bus_read32(int a1) {
  return ke_task_handler(1, a1, 4u);
}



// bus_write32 @ 0x114564
int bus_write32(int a1) {
  return ke_task_process(1, (void *)(uintptr_t)(a1), 4u);
}



// bus_read_12 @ 0x114570
int bus_read_12(int a1) {
  return ke_task_handler(2, a1, 0xCu);
}



// mmio_write_2 @ 0x11457c
int mmio_write_2(int a1) {
  return ke_task_process(2, (void *)(uintptr_t)(a1), 0xCu);
}



// mmio_read_4 @ 0x114588
int mmio_read_4(int a1) {
  return ke_task_handler(4, a1, 0x14u);
}



// mmio_write_4 @ 0x114594
int mmio_write_4(int a1) {
  return ke_task_process(4, (void *)(uintptr_t)(a1), 0x14u);
}



// mmio_read_8 @ 0x1145a0
int mmio_read_8(int a1) {
  return ke_task_handler(8, a1, 4u);
}



// mmio_write_8 @ 0x1145ac
int mmio_write_8(int a1) {
  return ke_task_process(8, (void *)(uintptr_t)(a1), 4u);
}



// mmio_read_32 @ 0x1145b8
int mmio_read_32(int a1) {
  return ke_task_handler(32, a1, 4u);
}



// mmio_read_64 @ 0x1145c4
int mmio_read_64(int a1) {
  return ke_task_handler(64, a1, 4u);
}



// mmio_write_64 @ 0x1145d0
int mmio_write_64(int a1) {
  return ke_task_process(64, (void *)(uintptr_t)(a1), 4u);
}



// mmio_read_128 @ 0x1145dc
int mmio_read_128(int a1) {
  return ke_task_handler(128, a1, 4u);
}



// mmio_write_128 @ 0x1145e8
int mmio_write_128(int a1) {
  return ke_task_process(128, (void *)(uintptr_t)(a1), 4u);
}



// bus_read_buf @ 0x1145f4
int bus_read_buf(int a1, int a2, unsigned int a3) {
  unsigned int v6; // r4
  union {
    uint8_t _rom_block[320];
    struct __attribute__((packed)) {
      int v8;               // +0x00 magic
      int v9;               // +0x04 flags
      char _pad2[12];       // +0x08..+0x13 unused
      uint8_t v10[272];         // +0x14 (first 6 bytes are the bit-2 payload)
      uint8_t v11[2];           // +0x124
      uint8_t _rom_pad3[2]; // +0x126..+0x127 unused
      uint8_t v12[8];           // +0x128
      uint8_t v13[4];           // +0x130
      uint8_t v14[2];           // +0x134
      uint8_t v15[10];       // +0x136
    } f;
  } _frame;
  if ( !*(volatile uint32_t *)off_1146D8 )
    ke_event_busy_check();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_1146DC + 4096, 320, _frame._rom_block);
  if ( _frame.f.v8 != dword_1146E0 )
    return -1;
  if ( (_frame.f.v9 & a1) == 0 )
    return 1;
  v6 = (uint8_t)_frame.f.v9 & (uint8_t)a1 & 2;
  if ( ((uint8_t)_frame.f.v9 & (uint8_t)a1 & 2) != 0 )
  {
    memcpy((void *)(uintptr_t)(a2), _frame.f.v10, 6);
    v6 = 6;
    if ( (a1 & 0x100000) == 0 )
    {
LABEL_7:
      if ( (a1 & 0x200000) == 0 )
        goto LABEL_8;
      goto LABEL_19;
    }
  }
  else if ( (a1 & 0x100000) == 0 )
  {
    goto LABEL_7;
  }
  memcpy((void *)(uintptr_t)(a2 + v6), _frame.f.v11, 2);
  v6 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_19:
  memcpy((void *)(uintptr_t)(a2 + v6), _frame.f.v12, 8);
  v6 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_10;
    goto LABEL_15;
  }
LABEL_17:
  memcpy((void *)(uintptr_t)(a2 + v6), _frame.f.v13, 4);
  v6 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_10:
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_11;
    goto LABEL_14;
  }
LABEL_15:
  memcpy((void *)(uintptr_t)(a2 + v6), _frame.f.v14, 2);
  v6 += 2;
  if ( (a1 & 0x1000000) != 0 )
  {
LABEL_14:
    memcpy((void *)(uintptr_t)(a2 + v6), _frame.f.v15, 10);
    v6 += 10;
  }
LABEL_11:
  if ( a3 < v6 )
    return -2;
  else
    return 0;
}



// bus_write_buf @ 0x1146e4
int bus_write_buf(int a1, volatile char *a2, unsigned int a3) {
  volatile uint32_t *v6; // r6
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r1
  int v10; // r2
  int v11; // r3
  struct __attribute__((packed)) { int v13; // [sp+0h] [bp-140h] BYREF
  int v14; // [sp+4h] [bp-13Ch]
  char _pad2[8]; int v15; // [sp+10h] [bp-130h]
  char a1a[120]; // [sp+14h] [bp-12Ch] BYREF
  int v17; // [sp+8Ch] [bp-B4h]
  char _pad5[124]; int v18; // [sp+10Ch] [bp-34h]
  char _pad6[20]; char v19[4]; // [sp+124h] [bp-1Ch] BYREF
  char v20[8]; // [sp+128h] [bp-18h] BYREF
  char v21[4]; // [sp+130h] [bp-10h] BYREF
  char v22[2]; // [sp+134h] [bp-Ch] BYREF
  char v23[10]; // [sp+136h] [bp-Ah] BYREF
  } _frame;
  if ( !*(volatile uint32_t *)off_114810 )
    ke_event_busy_check(a1);
  v6 = (void *)(uintptr_t)(off_114814);
  v7 = dword_114818;
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114814 + 4096, 320, &_frame.v13);
  if ( _frame.v13 == v7 )
  {
    v8 = a1 & 2;
    _frame.v14 |= a1;
    if ( (a1 & 2) == 0 )
      goto LABEL_5;
  }
  else
  {
    memset(&_frame.v13, 0xFFu, 0x140u);
    _frame.v13 = v7;
    _frame.v15 = 0;
    _frame.v17 = 0;
    _frame.v18 = 0;
    v8 = a1 & 2;
    _frame.v14 = a1;
    if ( (a1 & 2) == 0 )
    {
LABEL_5:
      if ( (a1 & 0x100000) == 0 )
        goto LABEL_6;
      goto LABEL_14;
    }
  }
  memcpy(_frame.a1a, a2, 6u);
  v8 = 6;
  if ( (a1 & 0x100000) == 0 )
  {
LABEL_6:
    if ( (a1 & 0x200000) == 0 )
      goto LABEL_7;
    goto LABEL_15;
  }
LABEL_14:
  memcpy(_frame.v19, &a2[v8], 2u);
  v8 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_7:
    v9 = a1 << 9;
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_8;
    goto LABEL_16;
  }
LABEL_15:
  memcpy(_frame.v20, &a2[v8], 8u);
  v9 = a1 << 9;
  v8 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_8:
    v10 = a1 << 8;
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_16:
  memcpy(_frame.v21, &a2[v8], 4u);
  v10 = a1 << 8;
  v8 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_9:
    v11 = a1 << 7;
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_10;
LABEL_18:
    memcpy(_frame.v23, &a2[v8], 0xAu);
    if ( a3 >= v8 + 10 )
      goto LABEL_11;
LABEL_19:
    dispatch_event_handler_1(aFlashWifiInfoW, v9, v10, v11, _frame.v13, _frame.v14);
    goto LABEL_11;
  }
LABEL_17:
  memcpy(_frame.v22, &a2[v8], 2u);
  v11 = a1 << 7;
  v8 += 2;
  if ( (a1 & 0x1000000) != 0 )
    goto LABEL_18;
LABEL_10:
  if ( a3 < v8 )
    goto LABEL_19;
LABEL_11:
  ke_event_schedule_alt();
  ke_event_schedule_prio();
  return ((int (*)())MEMD(0x1E0))(*v6 + 4096, 320);
}


// bus_read_6 @ 0x114820
int bus_read_6(int a1) {
  return bus_read_buf(2, a1, 6u);
}



// bus_write_6 @ 0x11482c
int bus_write_6(int a1) {
  return bus_write_buf(2, (void *)(uintptr_t)(a1), 6u);
}



// bus_read_2 @ 0x114838
int bus_read_2(int a1) {
  return bus_read_buf(0x100000, a1, 2u);
}



// mmio_write_100000_2 @ 0x114844
int mmio_write_100000_2(int a1) {
  return bus_write_buf(0x100000, (void *)(uintptr_t)(a1), 2u);
}



// mmio_write_400000_4 @ 0x114850
int mmio_write_400000_4(int a1) {
  return bus_read_buf(0x400000, a1, 4u);
}



// mmio_write_400000_4_alt @ 0x11485c
int mmio_write_400000_4_alt(int a1) {
  return bus_write_buf(0x400000, (void *)(uintptr_t)(a1), 4u);
}



// rf_cmd_wait_n_7e @ 0x114868
int rf_cmd_wait_n_7e(int a1) {
  return bus_read_buf(0x800000, a1, 2u);
}



// mmio_write_800000_2 @ 0x114874
int mmio_write_800000_2(int a1) {
  return bus_write_buf(0x800000, (void *)(uintptr_t)(a1), 2u);
}



// mmio_write_1000000_10 @ 0x114880
int mmio_write_1000000_10(int a1) {
  return bus_read_buf(0x1000000, a1, 0xAu);
}



// send_cmd_short @ 0x11488c
int send_cmd_short(int a1) {
  return bus_write_buf(0x1000000, (void *)(uintptr_t)(a1), 0xAu);
}



// hci_tx_data @ 0x114898
int hci_tx_data(int a1, int a2, unsigned int a3) {
  int v6; // r4
  struct __attribute__((packed)) { uint32_t v8[4]; // [sp+0h] [bp-50h] BYREF
  uint8_t v9[64]; // [sp+10h] [bp-40h] BYREF
  } _frame;
  if ( !*(volatile uint32_t *)off_1148F8 )
    ke_event_busy_check();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_1148FC, 80, _frame.v8);
  if ( _frame.v8[0] != dword_114900 )
    return -1;
  v6 = a1 & _frame.v8[1];
  if ( !v6 )
    return 1;
  if ( (v6 & 1) != 0 )
  {
    memcpy((void *)(uintptr_t)(a2), _frame.v9, 64);
    if ( a3 <= 0x3F )
      return -2;
  }
  return 0;
}



// hci_rx_data @ 0x114904
int hci_rx_data(int a1, volatile char *a2, unsigned int a3) {
  volatile uint32_t *v6; // r4
  int v7; // r8
  struct __attribute__((packed)) { int v9; // [sp+0h] [bp-50h] BYREF
  int v10; // [sp+4h] [bp-4Ch]
  char _pad2[8]; char a1a[64]; // [sp+10h] [bp-40h] BYREF
  } _frame;
  if ( !*(volatile uint32_t *)off_114994 )
    ke_event_busy_check(a1);
  v6 = (void *)(uintptr_t)(off_114998);
  v7 = dword_1149A0;
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114998, 80, &_frame.v9);
  if ( _frame.v9 == v7 )
  {
    _frame.v10 |= a1;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  else
  {
    memset(&_frame.v9, 0xFFu, 0x50u);
    _frame.v10 = a1;
    _frame.v9 = v7;
    if ( (a1 & 1) == 0 )
      goto LABEL_5;
  }
  memcpy(_frame.a1a, a2, 0x40u);
  if ( a3 <= 0x3F )
    dispatch_event_handler_1(aFlashBtdmInfoW);
LABEL_5:
  ke_event_schedule_alt();
  ke_event_schedule_prio();
  return ((int (*)())MEMD(0x1E0))(*v6, 80);
}


// hci_tx_packet @ 0x1149a4
int hci_tx_packet(int a1) {
  return hci_tx_data(1, a1, 0x40u);
}



// hci_rx_packet @ 0x1149b0
int hci_rx_packet(int a1) {
  return hci_rx_data(1, (void *)(uintptr_t)(a1), 0x40u);
}



// osal_int_enter @ 0x1149bc
int osal_int_enter() {
  volatile int *v0; // r4
  int ( *v1)(char); // r2
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1149F0 = 1;
  }
  v0 = (volatile int *)off_1149F4;
  v1 = (int ( *)(char))off_1149F8;
  ++*(volatile uint32_t *)off_1149F4;
  result = v1(2);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1149F0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// osal_int_exit @ 0x1149fc
int osal_int_exit(int a1) {
  int v1; // r0
  volatile int *v2; // r4
  int ( *v3)(char); // r2
  int result; // r0
  int v5; // r3
  int v6; // r2

  v1 = a1 != 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114A34 = 1;
  }
  v2 = (volatile int *)off_114A38;
  v3 = (int ( *)(char))off_114A3C;
  ++*(volatile uint32_t *)off_114A38;
  result = v3(v1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_114A34;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// assert_handler @ 0x114a40
void assert_handler() {
  if ( **(volatile int16_t **)off_114A5C < 0 )
    flash_ctrl_init(dword_114A64, dword_114A60, 242);
  while ( 1 )
    ;
}



// get_free_heap_size @ 0x114a68
void get_free_heap_size() {
  volatile uint32_t *v0; // r2
  unsigned int v1; // r3
  int v2; // r1
  volatile int *v3; // r2
  volatile int *v4; // r3
  volatile uint32_t *v5; // r0
  int v6; // t1
  volatile uint32_t *v7; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int v11; // r3
  volatile char *v12; // r2

  v0 = (volatile uint32_t *)dword_114B20;
  if ( dword_114B20 < (unsigned int)dword_114B24 )
  {
    v1 = ((dword_114B24 - 1 - dword_114B20) & 0xFFFFFFFC) + 4 + dword_114B20;
    do
      *v0++ = 0;
    while ( v0 != (volatile uint32_t *)v1 );
  }
  v2 = dword_114B28;
  if ( dword_114B28 < (unsigned int)dword_114B2C )
  {
    v3 = (volatile int *)off_114B30;
    v4 = (volatile int *)((volatile char *)&((volatile uint32_t *)(uintptr_t)off_114B30)[1] + ((dword_114B2C - 1 - dword_114B28) & 0xFFFFFFFC));
    v5 = (volatile uint32_t *)dword_114B28;
    do
    {
      v6 = *v3++;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = (void *)(uintptr_t)(off_114B34);
  v8 = dword_114B38;
  *((volatile uint32_t *)off_114B34 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(volatile uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(volatile uint32_t *)off_114B34 == 49729 )
    *(volatile uint32_t *)off_114B3C = 1;
  v11 = HIBYTE(*(volatile uint32_t *)off_114B40);
  *(volatile uint8_t *)off_114B44 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = (void *)(uintptr_t)(off_114B4C);
    *(volatile uint32_t *)(uintptr_t)(off_114B48) = dword_114B50;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(volatile uint32_t *)off_114B54 &= ~0x4000u;
  *(volatile uint8_t *)off_114B58 = BYTE2(*(volatile uint32_t *)off_114B40);
  save_rf_context();
  init_buffer_list();
  ((int (*)())JUMPOUT)(0x114B1C);
}


// wait_hw_ready @ 0x114b5c
int wait_hw_ready() {
  int v0; // r4
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r3
  int v4; // r3
  int v6; // r2

  if ( **(volatile uint8_t **)off_114C44 == 2 )
  {
    if ( util_read_status() )
      v0 = ((volatile uint32_t *)(uintptr_t)off_114C64)[87];
    else
      v0 = 16;
    rf_init_1();
    *(volatile uint32_t *)(off_114C50 + 136) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    dispatch_event_handler_1(aSftDis);
    v6 = off_114C5C;
    *(volatile uint32_t *)(off_114C5C + 0x804) |= 2u;
    *(volatile uint32_t *)(v6 + 0x10) |= 1u;
    while ( (*(volatile uint32_t *)(v6 + 0x10) & 1) != 0 )
      ;
    dispatch_event_handler_1(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = (void *)(uintptr_t)(off_114C48);
  if ( (*((volatile uint32_t *)off_114C48 + 74) & 0x80) != 0 )
  {
    v2 = (void *)(uintptr_t)(off_114C4C);
    *((volatile uint32_t *)off_114C48 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = (void *)(uintptr_t)(off_114C4C);
  if ( (*((volatile uint32_t *)off_114C4C + 2) & 0x20000) != 0 )
  {
    *((volatile uint32_t *)off_114C48 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_114C50;
  *(volatile uint32_t *)(off_114C50 + 136) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  *(volatile uint32_t *)(v4 + 136) = 1;
  __dsb(0xFu);
  __isb(0xFu);
  trace_sync();
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114C54 + 3) )
    check_rx_active();
  __disable_irq();
  return v0;
}


// init_ram_table @ 0x114c68
int init_ram_table() {
  volatile uint32_t *v0; // r7
  volatile int *v1; // r5
  int i; // r4
  int v3; // r1
  int v4; // t1
  volatile uint32_t *v5; // r5
  unsigned int v6; // r4
  int v7; // r3
  int v8; // r1
  int result; // r0
  int v10; // r4
  int v11; // r4
  unsigned int v12; // r4
  unsigned int v13; // r5
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v0 = (void *)(uintptr_t)(off_114E38);
  v1 = (volatile int *)off_114E38;
  for ( i = 0; i != 13; ++i )
  {
    v3 = i;
    v4 = *v1++;
    log_printf("\nR%-4d: %08X", v3, v4);
  }
  v5 = (void *)(uintptr_t)(off_114E40);
  log_printf(aSp08xLr08xPc08, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  log_printf("\nCPUID: %08X\nICSR : %08X\nVTOR : %08X\nAIRCR: %08X", *v5, v5[1], v5[2], v5[3]);
  log_printf(
    "\nSHCSR: %08X\nCFSR : %08X\nHFSR : %08X\nDFSR : %08X\nAFSR : %08X",
    v5[9],
    v5[10],
    v5[11],
    v5[12],
    v5[15]);
  v6 = v5[10];
  if ( (uint8_t)v6 )
  {
    log_printf(
      "\nMMFSR: %02X\n  IACCVIOL :%d\tDACCVIOL :%d\n  MUNSTKERR:%d\tMSTKERR  :%d\n  MLSPERR  :%d\tMMARVALID:%d",
      (uint8_t)v5[10],
      v6 & 1,
      (v6 >> 1) & 1,
      (v6 >> 3) & 1,
      (v6 >> 4) & 1,
      (v6 >> 5) & 1,
      (v6 >> 7) & 1);
    if ( (v6 & 0x80) != 0 )
      log_printf("\nMMFAR: %08X", v5[13]);
  }
  if ( (v6 & 0xFF00) != 0 )
  {
    log_printf(
      "\n"
      "BFSR : %02X\n"
      "  IBUSERR    :%d\tPRECISERR:%d\n"
      "  IMPRECISERR:%d\tUNSTKERR :%d\n"
      "  STKERR     :%d\tLSPERR   :%d\n"
      "  BFARVALID  :%d",
      BYTE1(v6),
      (v6 >> 8) & 1,
      (v6 >> 9) & 1,
      (v6 >> 10) & 1,
      (v6 >> 11) & 1,
      (v6 >> 12) & 1,
      (v6 >> 13) & 1,
      (v6 >> 15) & 1);
    if ( (v6 & 0x8000) != 0 )
      log_printf("\nBFAR : %08X", *((volatile uint32_t *)off_114E40 + 14));
  }
  if ( HIWORD(v6) )
    log_printf(
      "\nUFSR : %04X\n  UNDEFINSTR:%d\tINVSTATE :%d\n  INVPC     :%d\tNOCP     :%d\n  UNALIGNED :%d\tDIVBYZERO:%d",
      HIWORD(v6),
      HIWORD(v6) & 1,
      (v6 >> 17) & 1,
      (v6 >> 18) & 1,
      (v6 >> 19) & 1,
      HIBYTE(v6) & 1,
      (v6 >> 25) & 1);
  if ( (v0[19] & 8) == 0 )
  {
    log_printf(aModeHandler);
    goto LABEL_9;
  }
  log_printf(aModeThread);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    log_printf(aPrivPrivileged);
    goto LABEL_10;
  }
  log_printf(aPrivUser);
LABEL_10:
  v7 = v0[19];
  v8 = v7 << 29;
  if ( (v7 & 4) != 0 )
    log_printf(aStackPsp, v8);
  else
    log_printf(aStackMsp, v8);
  result = log_printf(aCntrl08xPmask0, v0[20], __get_CPSR(), __get_CPSR(), __get_CPSR());
  v10 = v0[18];
  if ( v10 )
  {
    v15 = v10 & 0xFFFFFFF0;
    log_printf(aDumpmsp_0);
    v16 = v15 + 256;
    do
    {
      if ( !(v15 << 28) )
        log_printf("\n[%08x]:", v15);
      v17 = *(volatile uint32_t *)v15;
      v15 += 4;
      result = log_printf(" %08X", v17);
    }
    while ( v16 != v15 );
  }
  v11 = v0[17];
  if ( v11 )
  {
    v12 = v11 & 0xFFFFFFF0;
    log_printf(aDumppsp_0);
    v13 = v12 + 256;
    do
    {
      if ( !(v12 << 28) )
        log_printf("\n[%08x]:", v12);
      v14 = *(volatile uint32_t *)v12;
      v12 += 4;
      result = log_printf(" %08X", v14);
    }
    while ( v13 != v12 );
  }
  return result;
}


// bt_check_state @ 0x114e90
void bt_check_state() {
  int v0; // r0
  int v1; // r0

  log_printf(aPanic_0);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114EC8 + 6) == 2 )
  {
    v1 = wait_hw_ready();
    ke_event_set(v1);
  }
  while ( 1 )
  {
    while ( !uart_rx_ready() )
      ;
    v0 = uart_rx_byte();
    process_queue_message(v0);
    exit_critical_section();
  }
}


// cli_process_char @ 0x114ecc
void cli_process_char(int a1) {
  log_printf(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      log_printf(aBusfault);
      break;
    case '@':
      log_printf(aUsagefault);
      break;
    case ' ':
      log_printf(aMemmanagefault);
      break;
    default:
      log_printf(aHardfault);
      break;
  }
  log_printf(aContext);
  init_ram_table();
  log_printf(aFaultHandler);
  bt_check_state();
}


// sys_init @ 0x115000
int sys_init() {
  int v0; // r0
  int v1; // r0
  int v2; // r0

  v0 = nullsub_5();
  v1 = (int)(uintptr_t)(start_firmware(v0));
  v2 = init_event_control(v1);
  return clear_global_187218(v2);
}



// bt_driver_init @ 0x115018
void bt_driver_init() {
  volatile int *v0; // r4
  int v1; // r3
  volatile uint8_t *v2; // r5

  v0 = (volatile int *)off_115098;
  dispatch_event_handler_1("\x9A%s - build: %s\n", aV6911, aLaJul032024153);
  if ( *(volatile uint32_t *)off_11509C )
  {
    mmio_set_reg_0x70001408();
    if ( *(volatile uint16_t *)(*v0 + 8) )
      pmu_write_clock_ctrl(*(volatile uint16_t *)(*v0 + 8));
  }
  if ( **(volatile uint8_t **)off_1150A0 == 2 )
  {
    v1 = *v0;
    *(volatile uint8_t *)(v1 + 6) = 2;
    *(volatile uint8_t *)(v1 + 3) = 1;
  }
  bt_module_init(*(volatile uint16_t *)(*v0 + 4));
  if ( !*(volatile uint8_t *)(*v0 + 3) )
    clear_irq_flag();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v2 = (void *)(uintptr_t)(off_1150A4);
  while ( 1 )
  {
    if ( *(volatile uint8_t *)(*v0 + 3) )
      memory_barrier_write();
    if ( !*v2 )
      process_event_queue();
    exit_critical_section();
  }
}


// mmio_wait_flag @ 0x1150a8
int mmio_wait_flag(int a1, int a2) {
  volatile uint32_t *v2; // r4
  volatile uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  volatile uint32_t *v7; // r5
  unsigned int v8; // r5
  int result; // r0
  int v10; // r3
  int v11; // r2
  int v12; // r7
  int v13; // r6
  int v14; // r2
  volatile unsigned int v15; // r3

  if ( (**(volatile uint16_t **)dword_1151F4 & 1) != 0 )
    rf_init_phy();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_1151F8 = 1;
  }
  v2 = (volatile uint32_t *)dword_1151FC;
  ++*(volatile uint32_t *)dword_1151FC;
  check_interrupt_flag(1024, "%s\r\n", aRwnxlResetEvt);
  enter_critical_section_1(0x80000000);
  rf_cmd_wait();
  v3 = (volatile uint32_t *)dword_115208;
  *(volatile uint32_t *)dword_115208 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (volatile uint32_t *)dword_115210;
  *(volatile uint32_t *)dword_115210 |= 0x111u;
  rf_acquire();
  *(volatile uint32_t *)dword_115208 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  chip_id_is_one();
  if ( !flash_write_byte(0) )
    enter_critical_section_1(0x2000000);
  v8 = dword_115214;
  find_link_in_list();
  if ( *(volatile uint8_t *)v8 && !*(volatile uint8_t *)dword_115218 && *(volatile uint8_t *)(v8 + 6) )
  {
    v12 = (char)(*(volatile uint8_t *)(v8 + 5) + (*(volatile uint8_t *)dword_115224 & 3));
    v13 = *(volatile char *)(v8 + 7) + v12;
    if ( v13 >= *(volatile char *)(v8 + 4) )
      v13 = (v13 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v8 + 4)) & 0xFFu);
    gpio_config(v13);
    v14 = *(volatile uint16_t *)(v8 + 8);
    v15 = (*(volatile uint32_t *)0x40501010u);
    *(volatile uint8_t *)(v8 + 7) = v13;
    *(volatile uint8_t *)(v8 + 0xB) = 1;
    ke_enter_critical((volatile uint32_t *)(v8 + 12), v15 + 60000 * v14);
    dispatch_event_handler_1("update %d, %d\r\n", (char)v13, v12);
  }
  *(volatile uint8_t *)(v8 + 6) = 0;
  check_interrupt_flag(1024, aResetDone);
  if ( *(volatile uint32_t *)dword_115220 )
    set_busy_flag_alt(0x2000);
  result = timer_event_check();
  if ( result )
    result = set_busy_flag_alt(0x400000);
  if ( *v2 )
  {
    v10 = *v2 - 1;
    v11 = *(volatile uint32_t *)dword_1151F8;
    *v2 = v10;
    if ( !v10 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}


// read_sensor_value @ 0x11522c
int read_sensor_value() {
  volatile int **v0; // r5
  volatile uint32_t *v1; // r6
  volatile int *v2; // r0
  void *v3; // r9
  int v4; // r8
  uint16_t v5; // r10
  volatile int *v6; // r1
  int result; // r0

  v0 = (volatile int **)off_1152B4;
  list_init_1((volatile uint32_t *)dword_1152B0);
  if ( **(volatile int16_t **)off_1152B8 < 0 )
  {
    v2 = *v0;
    v1 = (void *)(uintptr_t)(off_1152BC);
    if ( !*v0 || !*(volatile uint32_t *)off_1152BC )
    {
      flash_ctrl_init((int)aTxdescArray0Tx, (int)aTxTxdescInit, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = (void *)(uintptr_t)(off_1152BC);
    v2 = *v0;
  }
  v3 = (void *)(uintptr_t)(off_1152C8);
  v4 = dword_1152B0;
  memset(v2, 0, 44 * *(volatile uint16_t *)(*(volatile uint32_t *)off_1152C8 + 8) + 44);
  v5 = 0;
  do
  {
    v6 = &(*v0)[11 * v5];
    v6[8] = *v1 + 76 * v5;
    result = check_kernel_state(v4, (void *)(v6));
    ++v5;
  }
  while ( *(volatile uint16_t *)(*(volatile uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}


// log_u32_value @ 0x1152cc
int log_u32_value(volatile uint32_t *a1) {
  return check_kernel_state(dword_1152D4, a1);
}


// get_channel_params @ 0x1152d8
uint64_t get_channel_params(int a1) {
  int v1; // r1
  int v2; // r3
  int v3; // r5
  int v4; // r0
  int v5; // r3
  int v6; // r4

  v1 = dword_115310;
  v2 = 9 * a1;
  v3 = 36 * a1;
  v4 = a1 + 18;
  v5 = dword_115310 + 4 * v2;
  v6 = dword_115310 + 8 * v4;
  *(volatile uint32_t *)(dword_115310 + v3) = 0;
  *(volatile uint32_t *)(v1 + 8 * v4) = 0;
  *(volatile uint32_t *)(v6 + 4) = 0;
  *(volatile uint64_t *)(v5 + 8) = -4294966370LL;
  *(volatile uint32_t *)(v5 + 4) = 0;
  *(volatile uint8_t *)(v5 + 32) = 0;
  *(volatile uint32_t *)(v5 + 20) = 0;
  *(volatile uint32_t *)(v5 + 16) = -1;
  return -4294966370LL;
}



// deferred_cb_clear @ 0x115314
volatile uint32_t * deferred_cb_clear(int a1) {
  volatile uint32_t *result; // r0

  result = *(volatile uint32_t **)(a1 + 28);
  if ( result )
  {
    result = (volatile uint32_t *)mem_free(result);
    *(volatile uint32_t *)(a1 + 28) = 0;
  }
  return result;
}



// nullsub_4 @ 0x115328
int nullsub_4(void) {
  return 0;
}


// radio_pdu_type_cfg @ 0x11532c
int radio_pdu_type_cfg(int result) {
  switch ( result )
  {
    case 0:
      *(volatile uint32_t *)off_11537C = 2;
      break;
    case 1:
      *(volatile uint32_t *)off_11537C = 4;
      break;
    case 2:
      *(volatile uint32_t *)off_11537C = 8;
      break;
    case 3:
      *(volatile uint32_t *)off_11537C = 16;
      break;
    case 5:
      *(volatile uint32_t *)off_11537C = 32;
      break;
    default:
      if ( **(volatile int16_t **)off_115380 < 0 )
        result = flash_ctrl_init(dword_115388, dword_115384, 944);
      break;
  }
  return result;
}



