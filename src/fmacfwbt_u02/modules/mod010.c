// ioctl_dispatch @ 0x11526c
int ioctl_dispatch(int a1, int a2, unsigned int a3) {
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
  if ( !*(volatile uint32_t *)off_115364 )
    check_status_flags();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_115368 + 0x2000, 72, _frame._rom_block);
  if ( _frame.f.v9[0] != dword_11536C )
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



// ioctl_cmd_1 @ 0x115370
int ioctl_cmd_1(int a1) {
  return ioctl_dispatch(1, a1, 4u);
}



// ioctl_cmd_2 @ 0x11537c
int ioctl_cmd_2(int a1) {
  return ioctl_dispatch(2, a1, 0xCu);
}



// ioctl_cmd_4 @ 0x115388
int ioctl_cmd_4(int a1) {
  return ioctl_dispatch(4, a1, 0x14u);
}



// ioctl_cmd_0x20 @ 0x115394
int ioctl_cmd_0x20(int a1) {
  return ioctl_dispatch(32, a1, 4u);
}



// ioctl_cmd_0x40 @ 0x1153a0
int ioctl_cmd_0x40(int a1) {
  return ioctl_dispatch(64, a1, 4u);
}



// ioctl_cmd_0x80 @ 0x1153ac
int ioctl_cmd_0x80(int a1) {
  return ioctl_dispatch(128, a1, 4u);
}



// ioctl_dispatch2 @ 0x1153b8
int ioctl_dispatch2(int a1, volatile char *a2, unsigned int a3) {
  unsigned int v6; // r4
  union {
    uint8_t _rom_block[320];
    struct __attribute__((packed)) {
      int v8;               // +0x00 magic
      int v9;               // +0x04 flags
      char _pad2[12];       // +0x08..+0x13 unused
      char v10[272];         // +0x14 (first 6 bytes are the bit-2 payload)
      char v11[2];           // +0x124
      uint8_t _rom_pad3[2]; // +0x126..+0x127 unused
      char v12[8];           // +0x128
      char v13[4];           // +0x130
      char v14[2];           // +0x134
      char a2a[10];       // +0x136
    } f;
  } _frame;
  if ( !*(volatile uint32_t *)off_11549C )
    check_status_flags();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_1154A0 + 4096, 320, _frame._rom_block);
  if ( _frame.f.v8 != dword_1154A4 )
    return -1;
  if ( (_frame.f.v9 & a1) == 0 )
    return 1;
  v6 = (uint8_t)_frame.f.v9 & (uint8_t)a1 & 2;
  if ( ((uint8_t)_frame.f.v9 & (uint8_t)a1 & 2) != 0 )
  {
    memcpy(a2, _frame.f.v10, 6u);
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
  memcpy(&a2[v6], _frame.f.v11, 2u);
  v6 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_19:
  memcpy(&a2[v6], _frame.f.v12, 8u);
  v6 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_10;
    goto LABEL_15;
  }
LABEL_17:
  memcpy(&a2[v6], _frame.f.v13, 4u);
  v6 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_10:
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_11;
    goto LABEL_14;
  }
LABEL_15:
  memcpy(&a2[v6], _frame.f.v14, 2u);
  v6 += 2;
  if ( (a1 & 0x1000000) != 0 )
  {
LABEL_14:
    memcpy(&a2[v6], _frame.f.a2a, 0xAu);
    v6 += 10;
  }
LABEL_11:
  if ( a3 < v6 )
    return -2;
  else
    return 0;
}


// ioctl2_cmd_2 @ 0x1154a8
int ioctl2_cmd_2(int a1) {
  return ioctl_dispatch2(2, (void *)(uintptr_t)(a1), 6u);
}



// ioctl2_cmd_0x400000 @ 0x1154b4
int ioctl2_cmd_0x400000(int a1) {
  return ioctl_dispatch2(0x400000, (void *)(uintptr_t)(a1), 4u);
}



// check_signed_status @ 0x1154c0
void check_signed_status() {
  if ( **(volatile int16_t **)off_1154DC < 0 )
    mmio_irq_clear(dword_1154E4, dword_1154E0, 242);
  while ( 1 )
    ;
}



// check_patch_magic @ 0x1154e8
void check_patch_magic() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  unsigned int v2; // r1
  int v3; // r4
  volatile uint32_t *v4; // t1
  volatile int *v5; // r2
  int v6; // r5
  int v7; // r0
  int v8; // t1
  volatile uint32_t *v9; // r3
  unsigned int v10; // r1
  int v11; // r0

  v0 = (void *)(uintptr_t)(off_115558);
  if ( *(volatile uint32_t *)off_115558 == dword_11555C && *((volatile uint32_t *)off_115558 + 2) == dword_11555C + 135327480 )
  {
    v1 = *((volatile uint32_t *)off_115558 + 1);
    v2 = v1 & 3;
    if ( (v1 & 3) == 0 )
    {
      if ( *((volatile uint32_t *)off_115558 + 3) )
      {
        do
        {
          v3 = *(volatile uint32_t *)(v1 + 4);
          v4 = *(volatile uint32_t **)v1;
          v1 += 8;
          *v4 = v3;
          ++v2;
        }
        while ( v0[3] > v2 );
      }
      v5 = (volatile int *)dword_115560;
      v6 = dword_115560 + 16;
      do
      {
        v8 = *v5++;
        v7 = v8;
        if ( !(v8 << 30) )
        {
          v9 = (volatile uint32_t *)v5[3];
          v10 = (uint8_t)v9 & 3;
          if ( ((uint8_t)v9 & 3) == 0 )
          {
            if ( v5[7] )
            {
              v11 = v7 - (uint32_t)v9;
              do
              {
                *(volatile uint32_t *)((volatile char *)v9 + v11) = *v9;
                ++v10;
                ++v9;
              }
              while ( v10 < v5[7] );
            }
          }
        }
      }
      while ( v5 != (volatile int *)v6 );
    }
  }
}


// ring_buf_used @ 0x115564
void ring_buf_used() {
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

  v0 = (volatile uint32_t *)dword_115620;
  if ( dword_115620 < (unsigned int)dword_115624 )
  {
    v1 = ((dword_115624 - 1 - dword_115620) & 0xFFFFFFFC) + 4 + dword_115620;
    do
      *v0++ = 0;
    while ( v0 != (volatile uint32_t *)v1 );
  }
  v2 = dword_115628;
  if ( dword_115628 < (unsigned int)dword_11562C )
  {
    v3 = (volatile int *)off_115630;
    v4 = (volatile int *)((volatile char *)&((volatile uint32_t *)(uintptr_t)off_115630)[1] + ((dword_11562C - 1 - dword_115628) & 0xFFFFFFFC));
    v5 = (volatile uint32_t *)dword_115628;
    do
    {
      v6 = *v3++;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = (void *)(uintptr_t)(off_115634);
  v8 = dword_115638;
  *((volatile uint32_t *)off_115634 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(volatile uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(volatile uint32_t *)off_115634 == 49729 )
    *(volatile uint32_t *)off_11563C = 1;
  v11 = HIBYTE(*(volatile uint32_t *)off_115640);
  *(volatile uint8_t *)off_115644 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = (void *)(uintptr_t)(off_11564C);
    *(volatile uint32_t *)(uintptr_t)(off_115648) = dword_115650;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(volatile uint32_t *)off_115654 &= ~0x4000u;
  *(volatile uint8_t *)off_115658 = BYTE2(*(volatile uint32_t *)off_115640);
  read_hw_status();
  check_patch_magic();
  ke_task_init();
  while ( 1 )
    ;
}


// rf_mode_switch @ 0x11565c
int rf_mode_switch() {
  int v0; // r4
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3
  volatile uint32_t *v6; // r2

  if ( **(volatile uint8_t **)off_115744 == 2 )
  {
    if ( get_global_state() )
      v0 = ((volatile uint32_t *)(uintptr_t)off_115764)[87];
    else
      v0 = 16;
    rf_init_bb();
    *((volatile uint32_t *)off_115750 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    ke_event_schedule_1(aSftDis);
    v6 = (void *)(uintptr_t)(off_11575C);
    *((volatile uint32_t *)off_11575C + 513) |= 2u;
    v6[4] |= 1u;
    while ( (v6[4] & 1) != 0 )
      ;
    ke_event_schedule_1(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = (void *)(uintptr_t)(off_115748);
  if ( (*((volatile uint32_t *)off_115748 + 74) & 0x80) != 0 )
  {
    v2 = (void *)(uintptr_t)(off_11574C);
    *((volatile uint32_t *)off_115748 + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = (void *)(uintptr_t)(off_11574C);
  if ( (*((volatile uint32_t *)off_11574C + 2) & 0x20000) != 0 )
  {
    *((volatile uint32_t *)off_115748 + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = (void *)(uintptr_t)(off_115750);
  *((volatile uint32_t *)off_115750 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  irq_disable();
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_115754 + 3) )
    get_core_state();
  __disable_irq();
  return v0;
}


// init_queue_table @ 0x115768
int init_queue_table() {
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

  v0 = (void *)(uintptr_t)(off_115938);
  v1 = (volatile int *)off_115938;
  for ( i = 0; i != 13; ++i )
  {
    v3 = i;
    v4 = *v1++;
    printf_wrapper("\nR%-4d: %08X", v3, v4);
  }
  v5 = (void *)(uintptr_t)(off_115940);
  printf_wrapper(aSp08xLr08xPc08, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  printf_wrapper("\nCPUID: %08X\nICSR : %08X\nVTOR : %08X\nAIRCR: %08X", *v5, v5[1], v5[2], v5[3]);
  printf_wrapper(
    "\nSHCSR: %08X\nCFSR : %08X\nHFSR : %08X\nDFSR : %08X\nAFSR : %08X",
    v5[9],
    v5[10],
    v5[11],
    v5[12],
    v5[15]);
  v6 = v5[10];
  if ( (uint8_t)v6 )
  {
    printf_wrapper(
      "\nMMFSR: %02X\n  IACCVIOL :%d\tDACCVIOL :%d\n  MUNSTKERR:%d\tMSTKERR  :%d\n  MLSPERR  :%d\tMMARVALID:%d",
      (uint8_t)v5[10],
      v6 & 1,
      (v6 >> 1) & 1,
      (v6 >> 3) & 1,
      (v6 >> 4) & 1,
      (v6 >> 5) & 1,
      (v6 >> 7) & 1);
    if ( (v6 & 0x80) != 0 )
      printf_wrapper("\nMMFAR: %08X", v5[13]);
  }
  if ( (v6 & 0xFF00) != 0 )
  {
    printf_wrapper(
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
      printf_wrapper("\nBFAR : %08X", *((volatile uint32_t *)off_115940 + 14));
  }
  if ( HIWORD(v6) )
    printf_wrapper(
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
    printf_wrapper(aModeHandler);
    goto LABEL_9;
  }
  printf_wrapper(aModeThread);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    printf_wrapper(aPrivPrivileged);
    goto LABEL_10;
  }
  printf_wrapper(aPrivUser);
LABEL_10:
  v7 = v0[19];
  v8 = v7 << 29;
  if ( (v7 & 4) != 0 )
    printf_wrapper(aStackPsp, v8);
  else
    printf_wrapper(aStackMsp, v8);
  result = printf_wrapper(aCntrl08xPmask0, v0[20], __get_CPSR(), __get_CPSR(), __get_CPSR());
  v10 = v0[18];
  if ( v10 )
  {
    v15 = v10 & 0xFFFFFFF0;
    printf_wrapper(aDumpmsp_0);
    v16 = v15 + 256;
    do
    {
      if ( !(v15 << 28) )
        printf_wrapper("\n[%08x]:", v15);
      v17 = *(volatile uint32_t *)v15;
      v15 += 4;
      result = printf_wrapper(" %08X", v17);
    }
    while ( v16 != v15 );
  }
  v11 = v0[17];
  if ( v11 )
  {
    v12 = v11 & 0xFFFFFFF0;
    printf_wrapper(aDumppsp_0);
    v13 = v12 + 256;
    do
    {
      if ( !(v12 << 28) )
        printf_wrapper("\n[%08x]:", v12);
      v14 = *(volatile uint32_t *)v12;
      v12 += 4;
      result = printf_wrapper(" %08X", v14);
    }
    while ( v13 != v12 );
  }
  return result;
}


// check_op_mode @ 0x115990
void check_op_mode() {
  int v0; // r0
  int v1; // r0
  int v2; // r1
  int v3; // r0

  printf_wrapper(aPanic_0);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_1159C8 + 6) == 2 )
  {
    v3 = rf_mode_switch();
    periph_trigger_write(v3);
  }
  while ( 1 )
  {
    while ( !uart_rx_ready() )
      ;
    v0 = uart_getc();
    v1 = ke_malloc(v0);
    ke_event_send_1(v1, v2);
  }
}


// handle_debug_cmd @ 0x1159cc
void handle_debug_cmd(int a1) {
  printf_wrapper(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      printf_wrapper(aBusfault);
      break;
    case '@':
      printf_wrapper(aUsagefault);
      break;
    case ' ':
      printf_wrapper(aMemmanagefault);
      break;
    default:
      printf_wrapper(aHardfault);
      break;
  }
  printf_wrapper(aContext);
  init_queue_table();
  printf_wrapper(aFaultHandler);
  check_op_mode();
}


// check_nvic_irq @ 0x115b00
int check_nvic_irq(int a1, int a2) {
  volatile uint32_t *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = (void *)(uintptr_t)(off_115B78);
  v3 = *((volatile uint32_t *)off_115B78 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(volatile uint32_t *)off_115B7C;
  if ( (dword_115B80 & *(volatile uint32_t *)off_115B7C) == 0 )
  {
    v6 = dword_115B84 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = check_radio_flag_1(0);
      v10 = (void *)(uintptr_t)(off_115B8C);
      *(volatile uint32_t *)off_115B8C = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        log_debug_b(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      log_debug_b(0, a2, v4);
      if ( !*((volatile uint8_t *)off_115B88 + 3) )
      {
LABEL_6:
        for ( i = 0; ; ++i )
        {
          result = *(volatile uint32_t *)(4 * i - 536813056) & *(volatile uint32_t *)(4 * i - 536813312);
          if ( i == 1 )
          {
            if ( (result & 0xFFFFFFEF) != 0 )
              return 1;
          }
          else
          {
            if ( result )
              return 1;
            if ( i == 2 )
              return result;
          }
        }
      }
    }
  }
  return 1;
}



// rf_clock_enable @ 0x115b90
unsigned int rf_clock_enable() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *v1; // r4
  volatile uint32_t *v2; // r2
  volatile int *v3; // r6
  volatile uint32_t *v4; // r3
  volatile uint8_t **v5; // r5
  int v6; // r3
  unsigned int result; // r0
  volatile uint8_t *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1

  v0 = (void *)(uintptr_t)(off_115CBC);
  *((volatile uint32_t *)off_115CB8 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = (void *)(uintptr_t)(off_115CC4);
  state_check_feature(2, aW);
  v2 = (void *)(uintptr_t)(off_115CC8);
  *(volatile uint32_t *)off_115CC8 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = (volatile int *)off_115CCC;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_115CCC)[47]) && **(volatile int16_t **)off_115CD0 < 0 && *v1 != (*(volatile uint32_t *)off_115CE4 & 0xF) )
    mmio_irq_clear((int)aRwnxEnvPrevHwS, (int)aRwnxlWakeup, 968);
  v4 = (void *)(uintptr_t)(off_115CC8);
  v5 = (volatile uint8_t **)off_115CD4;
  *(volatile uint32_t *)off_115CC8 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(volatile uint32_t *)off_115CF8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(volatile uint32_t *)off_115CF4 &= ~0x20u;
  }
  if ( *(volatile uint8_t *)off_115CD8 )
    *(volatile uint32_t *)off_115CBC |= 0x2000000u;
  else
    *((volatile uint32_t *)off_115CB8 + 14) &= ~0x10u;
  result = state_check_feature(2, aWe_0);
  v8 = *(volatile uint8_t **)off_115CE0;
  v9 = **(volatile uint8_t **)off_115CE0;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(volatile uint32_t *)off_115CF8 &= ~1u;
  }
  else
  {
    if ( !*((volatile uint8_t *)v3 + 189) )
    {
      *(volatile uint32_t *)off_115CE4 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115CE8;
      v11 = dword_115CEC;
      do
      {
        if ( *(volatile uint8_t *)(v10 + 37) )
        {
          result = (*(volatile uint32_t *)0x40501010u);
          **(volatile uint32_t **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}


// shutdown_sequence @ 0x115d04
int shutdown_sequence() {
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((volatile uint8_t *)off_115D24 + 1) = 0;
  v0 = (int)(uintptr_t)(timer_clear());
  v1 = llm_env_reset(v0);
  v2 = (int)(uintptr_t)(run_deferred_init(v1));
  v3 = state_init(v2);
  return reset_hci_scratch(v3);
}



// mac_status_check @ 0x115d28
volatile uint32_t * mac_status_check(int a1, int a2) {
  volatile int *v2; // r4
  volatile uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  volatile uint32_t *v7; // r5
  unsigned int v8; // r5
  volatile uint32_t *v9; // r1
  volatile uint32_t *v10; // r0
  uint64_t v11; // kr00_8
  volatile uint32_t *result; // r0
  int v13; // r1
  int v14; // r1
  int v15; // r3
  int v16; // r7
  int v17; // r6
  int v18; // r2
  volatile unsigned int v19; // r3

  if ( (**(volatile uint16_t **)dword_115E84 & 1) != 0 )
    radio_init_2();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_115E88 = 1;
  }
  v2 = (volatile int *)dword_115E8C;
  ++*(volatile uint32_t *)dword_115E8C;
  state_check_feature(1024, "%s\r\n", aRwnxlResetEvt);
  set_system_flag_2(0x80000000);
  mac_config_clear();
  v3 = (volatile uint32_t *)dword_115E98;
  *(volatile uint32_t *)dword_115E98 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (volatile uint32_t *)dword_115EA0;
  *(volatile uint32_t *)dword_115EA0 |= 0x111u;
  controller_init();
  *(volatile uint32_t *)dword_115E98 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  check_isr_handler();
  if ( !hci_cmd_send_short(0) )
    set_system_flag_2(0x2000000);
  v8 = dword_115EA4;
  si_detach();
  if ( *(volatile uint8_t *)v8 && !*(volatile uint8_t *)dword_115EA8 && *(volatile uint8_t *)(v8 + 6) )
  {
    v16 = (char)(*(volatile uint8_t *)(v8 + 5) + (*(volatile uint8_t *)dword_115EC4 & 3));
    v17 = *(volatile char *)(v8 + 7) + v16;
    if ( v17 >= *(volatile char *)(v8 + 4) )
      v17 = (v17 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v8 + 4)) & 0xFFu);
    write_mmio_byte(v17);
    v18 = *(volatile uint16_t *)(v8 + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(volatile uint8_t *)(v8 + 7) = v17;
    *(volatile uint8_t *)(v8 + 0xB) = 1;
    ke_event_lock((volatile uint32_t *)(v8 + 12), v19 + 60000 * v18);
    ke_event_schedule_1("update %d, %d\r\n", (char)v17, v16);
  }
  *(volatile uint8_t *)(v8 + 6) = 0;
  state_check_feature(1024, aResetDone);
  if ( mac_irq_check() )
    set_system_flag_1(0x80000);
  v9 = (volatile uint32_t *)dword_115EB8;
  v10 = (volatile uint32_t *)dword_115EBC;
  v11 = *(volatile uint64_t *)(*(volatile uint32_t *)dword_115EB0 + 8);
  *(volatile uint32_t *)dword_115EB4 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (volatile uint32_t *)dword_115EC0;
  v13 = *v2;
  *(volatile uint32_t *)(dword_115EC0 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(volatile uint32_t *)dword_115E88;
    *v2 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_read_low_nibble @ 0x115ecc
volatile uint8_t *mmio_read_low_nibble() {
  volatile uint32_t *v0; // r4
  volatile uint8_t *v1; // r5
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r2
  volatile int *v4; // r1
  int v5; // r1
  volatile uint32_t *v6; // r2
  volatile uint32_t *v7; // r1
  volatile uint8_t **v8; // r1
  int v9; // r3
  volatile uint8_t *result; // r0
  int v11; // r2
  volatile uint32_t *v12; // r3
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r3

  v0 = (void *)(uintptr_t)(off_115FF8);
  v1 = (void *)(uintptr_t)(off_115FFC);
  *(volatile uint8_t *)off_115FFC = *(volatile uint8_t *)off_115FF8 & 0xF;
  state_check_feature(2, "d %d,", *v0 & 0xF);
  if ( *v0 << 28 )
  {
    v2 = (void *)(uintptr_t)(off_116008);
    *(volatile uint32_t *)off_116004 &= ~0x80000000;
    *v0 = 0;
    while ( (*v2 & 4) == 0 )
      ;
    v3 = (void *)(uintptr_t)(off_116004);
    v4 = (volatile int *)off_116010;
    *(volatile uint32_t *)off_11600C = 4;
    v5 = *((volatile uint8_t *)v4 + 189);
    *v3 |= 0x80000000;
    if ( v5 )
      *(volatile uint32_t *)((volatile char *)v3 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(volatile uint32_t *)off_116020 &= ~0x8000000u;
  }
  v6 = (void *)(uintptr_t)(off_116014);
  v7 = (void *)(uintptr_t)(off_115FF8);
  *(volatile uint32_t *)off_116014 |= 0x111u;
  v1[1] = 1;
  *v7 = 32;
  v8 = (volatile uint8_t **)off_116018;
  *v6 &= 0xFFFFFEEE;
  v9 = **v8;
  if ( v9 == 3 )
  {
    v13 = (void *)(uintptr_t)(off_116024);
    *(volatile uint32_t *)off_116024 |= 1u;
    if ( (*v13 & 4) != 0 )
      *(volatile uint32_t *)off_116028 = 512;
  }
  else if ( v9 == 1 )
  {
    hw_poll_flag();
    v14 = (void *)(uintptr_t)(off_116030);
    *(volatile uint32_t *)off_11602C |= 0x20u;
    v14[20] |= 0x20000u;
    v14[20] |= 0x8000u;
    v14[20] |= 0x10000u;
    v14[20] = v14[20] & 0xFFFFFFC0 | 0x37;
    v14[23] = v14[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = (void *)(uintptr_t)(off_11601C);
  v11 = 0;
  *(volatile uint8_t *)off_11601C = 0;
  while ( 1 )
  {
    v12 = (volatile uint32_t *)(4 * v11++ - 536813312);
    if ( (v12[64] & *v12) != 0 )
      break;
    if ( v11 == 3 )
      return result;
  }
  *result = 1;
  return result;
}


// rx_check_buffers @ 0x116034
void rx_check_buffers(int a1) {
  volatile uint8_t **v1; // r4
  volatile uint8_t *v2; // r1
  int v3; // r3
  volatile uint8_t *v4; // r6
  volatile int *v5; // r3
  volatile uint8_t **v6; // r5
  char v7; // r0
  char v8; // r0

  v1 = (volatile uint8_t **)off_116154;
  v2 = *(volatile uint8_t **)off_116154;
  if ( **(volatile uint8_t **)off_116154 )
  {
    v3 = **(volatile uint8_t **)off_116158;
    if ( v3 != 1 )
      goto LABEL_3;
    goto LABEL_12;
  }
  v4 = (void *)(uintptr_t)(off_11616C);
  v5 = *((volatile int **)off_116168 + 2);
  *(volatile uint8_t *)off_11616C = 1;
  if ( !v5 )
  {
LABEL_10:
    v6 = (volatile uint8_t **)off_116158;
    if ( **(volatile uint8_t **)off_116158 == 3 )
      goto LABEL_4;
    state_check_feature(2, "lp=%d, ignore=%d\n", *v2, 1);
    *v4 = 1;
    v3 = **v6;
    if ( v3 != 1 )
    {
LABEL_3:
      if ( v3 == 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    if ( **v1 == 3 )
    {
      v8 = status_poll();
      *(volatile uint8_t *)off_116178 = v8;
      if ( v8 )
        ke_event_schedule_1(aWifiidleBtAllo);
      else
        ke_event_schedule_1(aWifiidleBtNotA);
      if ( ll_util_get_state() )
        mmio_read_low_nibble();
      hw_poll_flag();
      return;
    }
    if ( !ll_util_get_state() || *(volatile uint8_t *)off_116174 )
      return;
LABEL_4:
    if ( mm_state_run()
      && !*((volatile uint32_t *)off_11615C + 126)
      && (*(volatile uint32_t *)off_116160 >> 25) & 1 | *((volatile uint8_t *)off_116164 + 36)
      && !*((volatile uint8_t *)off_116164 + 29)
      && mac_isr_handler() )
    {
      v7 = status_poll();
      *(volatile uint8_t *)off_116178 = v7;
      if ( !v7 )
      {
        ke_event_schedule_1(aBt1);
        hw_poll_flag();
      }
      if ( (uint8_t)**v1 <= 1u )
        mmio_read_low_nibble();
    }
    return;
  }
  while ( !*((volatile uint8_t *)v5 + 106) )
  {
    if ( *((volatile uint8_t *)v5 + 108) )
      goto LABEL_20;
LABEL_17:
    v5 = (volatile int *)*v5;
    if ( !v5 )
      goto LABEL_10;
  }
  if ( *((volatile uint8_t *)v5 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(volatile uint8_t **)off_116158 != 3 )
    state_check_feature(2, "lp=%d, ignore=%d\n", *v2, 0);
  *v4 = 0;
}


// ke_init_structures @ 0x116188
void ke_init_structures() {
  unsigned int v0; // r5
  volatile uint8_t **v1; // r8
  int v2; // r3
  int v3; // r0
  int v4; // r1
  volatile uint8_t *v5; // r7
  volatile int *v6; // r9
  volatile int *v7; // r4
  volatile int *v8; // r6
  unsigned int v9; // r11
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2
  int v14; // r3
  volatile unsigned int v15; // r2
  unsigned int v16; // r2
  volatile unsigned int v17; // r3
  volatile uint32_t *v18; // r2

  v0 = dword_11636C;
  ke_event_schedule_1("\x9A%s - build: %s\n", aV6911, aLaJul032024152);
  if ( *(volatile uint32_t *)dword_116370 )
  {
    write_reg_70001408();
    if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
      periph_field_set(*(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8));
  }
  v1 = (volatile uint8_t **)dword_11639C;
  if ( **(volatile uint8_t **)dword_11639C == 2 )
  {
    v2 = *(volatile uint32_t *)v0;
    *(volatile uint8_t *)(v2 + 6) = 2;
    *(volatile uint8_t *)(v2 + 3) = 1;
  }
  v3 = init_chip_state(*(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4));
  if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
    clear_hw_flag_bit();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v5 = (volatile uint8_t *)dword_116374;
  v6 = (volatile int *)dword_1163A0;
  v7 = (volatile int *)dword_116378;
  v8 = (volatile int *)dword_11637C;
  v9 = dword_1163A4;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
        hw_sync_write();
      if ( !*v5 )
        process_event_queue();
      v3 = ke_event_send_1(v3, v4);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v6 = 1;
      }
      v10 = *v8;
      v11 = *v7 + 1;
      *v7 = v11;
      if ( !v10 )
        break;
      if ( v11 )
        goto LABEL_15;
    }
    if ( *(volatile uint8_t *)(dword_116380 + 0x12) )
    {
      *(volatile uint8_t *)dword_11638C = 0;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
LABEL_40:
        clear_hw_flag_bit();
    }
    else
    {
      rx_check_buffers(v3);
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
        goto LABEL_40;
    }
    if ( **v1 == 1 && *(volatile uint8_t *)dword_116384 )
    {
      v14 = **(volatile uint8_t **)dword_116388;
      if ( v14 == 3 )
      {
        v3 = ll_util_get_state();
        if ( !v3 )
        {
          v14 = **(volatile uint8_t **)dword_116388;
          goto LABEL_32;
        }
      }
      else
      {
LABEL_32:
        if ( v14 == 1 )
        {
          if ( !*(volatile uint8_t *)(v9 + 1) || *(volatile uint8_t *)dword_116398 )
            goto LABEL_21;
        }
        else if ( v14 || !*(volatile uint8_t *)dword_11638C || !*(volatile uint8_t *)(v9 + 1) )
        {
          goto LABEL_21;
        }
      }
      hw_poll_flag();
      v15 = (*(volatile uint32_t *)0x40501010u);
      v16 = v15 + 28;
      do
        v17 = (*(volatile uint32_t *)0x40501010u);
      while ( (int)(v16 - v17) >= 0 );
      v18 = (volatile uint32_t *)dword_116394;
      *(volatile uint32_t *)(dword_116394 + 4) |= 0x1000u;
      v18[21] |= 0x1000u;
      *v18 |= 0x1000u;
      goto LABEL_21;
    }
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v1 != 3 )
      {
        if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(volatile uint8_t *)(v9 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v3 = ((int (*)())check_nvic_irq)();
    }
    while ( !v3 );
    if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_hw_flag_bit();
    if ( *(volatile uint8_t *)(v9 + 1) )
LABEL_29:
      v3 = rf_clock_enable();
LABEL_24:
    v11 = *v7;
    if ( *v7 )
    {
LABEL_15:
      v12 = v11 - 1;
      v13 = *v6;
      *v7 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
  }
}


