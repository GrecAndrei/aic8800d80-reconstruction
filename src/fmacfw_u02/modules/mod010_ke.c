// ke_task_handler @ 0x114c30
/* luna: Copies environment payload blocks selected by the requested and available masks, returning status codes for an invalid magic value, no selected blocks */
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
  if ( !*(volatile uint32_t *)off_114D28 )
    get_ke_env();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114D2C + 0x2000, 72, _frame._rom_block);
  if ( _frame.f.v9[0] != dword_114D30 )
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



// ke_event_send_2 @ 0x114d34
/* luna: Requests event bit 2 for the specified task by calling the kernel task handler with event mask 4. */
int ke_event_send_2(int a1) {
  return ke_task_handler(1, a1, 4u);
}



// ke_event_send_4 @ 0x114d40
/* luna: Forwards its input unchanged to the kernel task handler with fixed arguments 2 and 0x0C. */
int ke_event_send_4(int a1) {
  return ke_task_handler(2, a1, 0xCu);
}



// ke_event_send_0x20 @ 0x114d4c
/* luna: Dispatches the 0x20 kernel event through task handler 4 with the supplied argument. */
int ke_event_send_0x20(int a1) {
  return ke_task_handler(4, a1, 0x14u);
}



// ke_event_send_0x40 @ 0x114d58
/* luna: Forwards the supplied argument to the kernel task handler with fixed selector 32 and mode 4. */
int ke_event_send_0x40(int a1) {
  return ke_task_handler(32, a1, 4u);
}



// ke_event_send_0x80 @ 0x114d64
/* luna: Forwards its argument to the kernel task handler with selector 64 and a four-byte payload size. */
int ke_event_send_0x80(int a1) {
  return ke_task_handler(64, a1, 4u);
}



// ke_task_handler_short @ 0x114d70
/* luna: Delegates to `ke_task_handler` with fixed arguments 128 and 4, passing the caller's argument as the second parameter. */
int ke_task_handler_short(int a1) {
  return ke_task_handler(128, a1, 4u);
}



// ke_task_handler_large @ 0x114d7c
/* luna: Reads the KE environment record from MEMD, copies mask-selected payload blocks into the output buffer, and returns status codes for bad magic, no matc */
int ke_task_handler_large(int a1, int a2, unsigned int a3) {
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
  if ( !*(volatile uint32_t *)off_114E60 )
    get_ke_env();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114E64 + 4096, 320, _frame._rom_block);
  if ( _frame.f.v8 != dword_114E68 )
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



// ke_event_send_0x400000 @ 0x114e6c
/* luna: Forwards the supplied value to the large task handler with fixed selector arguments 2 and 6. */
int ke_event_send_0x400000(int a1) {
  return ke_task_handler_large(2, a1, 6u);
}



// patch_get_field @ 0x114e78
/* luna: Forwards the supplied argument to the large kernel handler with selector 0x400000 and a 4-byte size. */
int patch_get_field(int a1) {
  return ke_task_handler_large(0x400000, a1, 4u);
}



// patch_check_valid @ 0x114e84
/* luna: Checks the referenced 16-bit status and invokes the register-clear routine if it is negative, then loops indefinitely. */
void patch_check_valid() {
  if ( **(volatile int16_t **)off_114EA0 < 0 )
    mmio_clear_register(off_114EA8, (int)aDummyHandler, 242);
  while ( 1 )
    ;
}


// patch_check_magic @ 0x114eac
/* luna: Checks the patch header magic markers, applies its relocation entries, and copies enabled aligned patch regions. */
void patch_check_magic() {
  volatile uint32_t *patch_header; // r3
  int relocation_entries; // r2
  unsigned int relocation_index; // r1
  int relocation_value; // r4
  volatile uint32_t *relocation_target; // t1
  volatile int *copy_table_cursor; // r2
  int copy_table_end; // r5
  int copy_destination; // r0
  int v8; // t1
  volatile uint32_t *copy_source; // r3
  unsigned int copy_word_index; // r1
  int destination_source_delta; // r0

  patch_header = (void *)(uintptr_t)(off_114F1C);
  if ( *(volatile uint32_t *)off_114F1C == dword_114F20 && *((volatile uint32_t *)off_114F1C + 2) == dword_114F20 + 135327480 )
  {
    relocation_entries = *((volatile uint32_t *)off_114F1C + 1);
    relocation_index = relocation_entries & 3;
    if ( (relocation_entries & 3) == 0 )
    {
      if ( *((volatile uint32_t *)off_114F1C + 3) )
      {
        do
        {
          relocation_value = *(volatile uint32_t *)(relocation_entries + 4);
          relocation_target = *(volatile uint32_t **)relocation_entries;
          relocation_entries += 8;
          *relocation_target = relocation_value;
          ++relocation_index;
        }
        while ( patch_header[3] > relocation_index );
      }
      copy_table_cursor = (volatile int *)dword_114F24;
      copy_table_end = dword_114F24 + 16;
      do
      {
        v8 = *copy_table_cursor++;
        copy_destination = v8;
        if ( !(v8 << 30) )
        {
          copy_source = (volatile uint32_t *)copy_table_cursor[3];
          copy_word_index = (uint8_t)copy_source & 3;
          if ( ((uint8_t)copy_source & 3) == 0 )
          {
            if ( copy_table_cursor[7] )
            {
              destination_source_delta = copy_destination - (uint32_t)copy_source;
              do
              {
                *(volatile uint32_t *)((volatile char *)copy_source + destination_source_delta) = *copy_source;
                ++copy_word_index;
                ++copy_source;
              }
              while ( copy_word_index < copy_table_cursor[7] );
            }
          }
        }
      }
      while ( copy_table_cursor != (volatile int *)copy_table_end );
    }
  }
}



// patch_check_region @ 0x114f28
/* luna: Clears and populates patch RAM, configures patch-control fields, performs magic and queue initialization, and then remains in an infinite idle loop. */
void patch_check_region() {
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

  v0 = (volatile uint32_t *)dword_114FE4;
  if ( dword_114FE4 < (unsigned int)dword_114FE8 )
  {
    v1 = ((dword_114FE8 - 1 - dword_114FE4) & 0xFFFFFFFC) + 4 + dword_114FE4;
    do
      *v0++ = 0;
    while ( v0 != (volatile uint32_t *)v1 );
  }
  v2 = dword_114FEC;
  if ( dword_114FEC < (unsigned int)dword_114FF0 )
  {
    v3 = (volatile int *)off_114FF4;
    v4 = (volatile int *)((volatile char *)&((volatile uint32_t *)(uintptr_t)off_114FF4)[1] + ((dword_114FF0 - 1 - dword_114FEC) & 0xFFFFFFFC));
    v5 = (volatile uint32_t *)dword_114FEC;
    do
    {
      v6 = *v3++;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = (void *)(uintptr_t)(off_114FF8);
  v8 = dword_114FFC;
  *((volatile uint32_t *)off_114FF8 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(volatile uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(volatile uint32_t *)off_114FF8 == 49729 )
    *(volatile uint32_t *)off_115000 = 1;
  v11 = HIBYTE(*(volatile uint32_t *)off_115004);
  *(volatile uint8_t *)off_115008 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = (void *)(uintptr_t)(off_115010);
    *(volatile uint32_t *)(uintptr_t)(off_11500C) = dword_115014;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(volatile uint32_t *)off_115018 &= ~0x4000u;
  *(volatile uint8_t *)off_11501C = BYTE2(*(volatile uint32_t *)off_115004);
  load_and_store_block();
  patch_check_magic();
  queue_init();
  while ( 1 )
    ;
}


// patch_get_state @ 0x115020
/* luna: Returns the patch-state value, or 16 when unavailable, after handling pending software-reset completion and hardware interrupt flags. */
int patch_get_state() {
  int v0; // r4
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3
  volatile uint32_t *v6; // r2

  if ( **(volatile uint8_t **)off_115108 == 2 )
  {
    if ( mmio_read_flag_b() )
      v0 = ((volatile uint32_t *)(uintptr_t)off_115128)[87];
    else
      v0 = 16;
    mmio_read_flag();
    *((volatile uint32_t *)off_115114 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    event_dispatch(aSftDis);
    v6 = (void *)(uintptr_t)(off_115120);
    *((volatile uint32_t *)off_115120 + 513) |= 2u;
    v6[4] |= 1u;
    while ( (v6[4] & 1) != 0 )
      ;
    event_dispatch(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = (void *)(uintptr_t)(off_11510C);
  if ( (*((volatile uint32_t *)off_11510C + 74) & 0x80) != 0 )
  {
    v2 = (void *)(uintptr_t)(off_115110);
    *((volatile uint32_t *)off_11510C + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = (void *)(uintptr_t)(off_115110);
  if ( (*((volatile uint32_t *)off_115110 + 2) & 0x20000) != 0 )
  {
    *((volatile uint32_t *)off_11510C + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = (void *)(uintptr_t)(off_115114);
  *((volatile uint32_t *)off_115114 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  nvic_set_priority();
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_115118 + 3) )
    check_bt_ptr_state();
  __disable_irq();
  return v0;
}


// patch_copy_table @ 0x11512c
/* luna: Logs the saved Cortex-M register context, SCB fault status, execution mode, and memory around the saved MSP and PSP. */
int patch_copy_table() {
  volatile uint32_t *saved_context; // r7
  volatile int *v1; // r5
  int i; // r4
  int v3; // r1
  int v4; // t1
  volatile uint32_t *scb_registers; // r5
  unsigned int cfsr; // r4
  int v7; // r3
  int v8; // r1
  int result; // r0
  int msp; // r4
  int psp; // r4
  unsigned int v12; // r4
  unsigned int v13; // r5
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  saved_context = (void *)(uintptr_t)(off_1152FC);
  v1 = (volatile int *)off_1152FC;
  for ( i = 0; i != 13; ++i )
  {
    v3 = i;
    v4 = *v1++;
    log_printf("\nR%-4d: %08X", v3, v4);
  }
  scb_registers = (void *)(uintptr_t)(off_115304);
  log_printf(aSp08xLr08xPc08, saved_context[13], saved_context[14], saved_context[15], saved_context[16], saved_context[17], saved_context[18]);
  log_printf("\nCPUID: %08X\nICSR : %08X\nVTOR : %08X\nAIRCR: %08X", *scb_registers, scb_registers[1], scb_registers[2], scb_registers[3]);
  log_printf(
    "\nSHCSR: %08X\nCFSR : %08X\nHFSR : %08X\nDFSR : %08X\nAFSR : %08X",
    scb_registers[9],
    scb_registers[10],
    scb_registers[11],
    scb_registers[12],
    scb_registers[15]);
  cfsr = scb_registers[10];
  if ( (uint8_t)cfsr )
  {
    log_printf(
      "\nMMFSR: %02X\n  IACCVIOL :%d\tDACCVIOL :%d\n  MUNSTKERR:%d\tMSTKERR  :%d\n  MLSPERR  :%d\tMMARVALID:%d",
      (uint8_t)scb_registers[10],
      cfsr & 1,
      (cfsr >> 1) & 1,
      (cfsr >> 3) & 1,
      (cfsr >> 4) & 1,
      (cfsr >> 5) & 1,
      (cfsr >> 7) & 1);
    if ( (cfsr & 0x80) != 0 )
      log_printf("\nMMFAR: %08X", scb_registers[13]);
  }
  if ( (cfsr & 0xFF00) != 0 )
  {
    log_printf(
      "\n"
      "BFSR : %02X\n"
      "  IBUSERR    :%d\tPRECISERR:%d\n"
      "  IMPRECISERR:%d\tUNSTKERR :%d\n"
      "  STKERR     :%d\tLSPERR   :%d\n"
      "  BFARVALID  :%d",
      BYTE1(cfsr),
      (cfsr >> 8) & 1,
      (cfsr >> 9) & 1,
      (cfsr >> 10) & 1,
      (cfsr >> 11) & 1,
      (cfsr >> 12) & 1,
      (cfsr >> 13) & 1,
      (cfsr >> 15) & 1);
    if ( (cfsr & 0x8000) != 0 )
      log_printf("\nBFAR : %08X", *((volatile uint32_t *)off_115304 + 14));
  }
  if ( HIWORD(cfsr) )
    log_printf(
      "\nUFSR : %04X\n  UNDEFINSTR:%d\tINVSTATE :%d\n  INVPC     :%d\tNOCP     :%d\n  UNALIGNED :%d\tDIVBYZERO:%d",
      HIWORD(cfsr),
      HIWORD(cfsr) & 1,
      (cfsr >> 17) & 1,
      (cfsr >> 18) & 1,
      (cfsr >> 19) & 1,
      HIBYTE(cfsr) & 1,
      (cfsr >> 25) & 1);
  if ( (saved_context[19] & 8) == 0 )
  {
    log_printf(aModeHandler);
    goto LABEL_9;
  }
  log_printf(aModeThread);
  if ( (saved_context[20] & 1) == 0 )
  {
LABEL_9:
    log_printf(aPrivPrivileged);
    goto LABEL_10;
  }
  log_printf(aPrivUser);
LABEL_10:
  v7 = saved_context[19];
  v8 = v7 << 29;
  if ( (v7 & 4) != 0 )
    log_printf(aStackPsp, v8);
  else
    log_printf(aStackMsp, v8);
  result = log_printf(aCntrl08xPmask0, saved_context[20], __get_CPSR(), __get_CPSR(), __get_CPSR());
  msp = saved_context[18];
  if ( msp )
  {
    v15 = msp & 0xFFFFFFF0;
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
  psp = saved_context[17];
  if ( psp )
  {
    v12 = psp & 0xFFFFFFF0;
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


// patch_init @ 0x115354
/* luna: Logs the startup message, conditionally sets the RF channel from patch state, then polls a GPIO-driven command value and dispatches it indefinitely. */
void patch_init() {
  int v0; // r0
  int v1; // r0
  int v2; // r1
  int v3; // r0

  log_printf(aPanic_0);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11538C + 6) == 2 )
  {
    v3 = patch_get_state();
    rf_set_channel_1(v3);
  }
  while ( 1 )
  {
    while ( !gpio_read_pin() )
      ;
    v0 = gpio_read();
    v1 = find_by_index(v0);
    parse_large_ioctl(v1, v2);
  }
}


// cli_parse_char @ 0x115390
/* luna: Logs the selected fault category and context, then copies and initializes the patch table. */
void cli_parse_char(int a1) {
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
  patch_copy_table();
  log_printf(aFaultHandler);
  patch_init();
}


// event_reset @ 0x1154c4
/* luna: Clears the AP power-save forbid timeout flag and dispatches the `ap_ps_forbid_to` event. */
int event_reset() {
  *(volatile uint8_t *)off_1154D0 = 0;
  return event_dispatch(aApPsForbidTo);
}


// check_init_status @ 0x1154d8
/* luna: Checks initialization status bits, updates the one-shot status latch, and schedules the status worker at a mode-scaled timer deadline. */
int check_init_status() {
  volatile uint8_t *v0; // r4
  int result; // r0
  volatile uint32_t *v2; // r3
  int v3; // r3
  volatile unsigned int v4; // r1

  v0 = (void *)(uintptr_t)(off_11558C);
  if ( !*(volatile uint8_t *)off_11558C && *(volatile uint8_t *)off_115590 )
  {
    result = check_status_bits(2, aPsall);
    v2 = (void *)(uintptr_t)(off_1155A0);
    *v0 = 1;
    if ( (uint16_t)*v2 )
    {
switch ( *(volatile uint32_t *)(uintptr_t)(off_1155A4) ) { case 1: v3 = 700 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
        case 2:
          v3 = 500 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
        case 3:
          v3 = 300 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
        case 4:
          v3 = 200 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
        case 5:
          v3 = 100 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
        default:
          v3 = 100 * (uint16_t)*(volatile uint32_t *)off_1155A0;
          break;
      }
      v4 = (*(volatile uint32_t *)0x40501010u);
      return unknown_worker((void *)(uintptr_t)(off_1155AC), v4 + v3);
    }
  }
  else
  {
    result = check_status_bits(2, aPsnotall);
    if ( *((volatile uint8_t *)off_115598 + 18) )
      *v0 = 0;
  }
  return result;
}


// check_nvic_irq_status @ 0x1155b0
/* luna: Handles controller-specific status flags and reports a special condition or an enabled NVIC pending interrupt, ignoring bit 4 of the second pending ba */
int check_nvic_irq_status(int a1, int a2) {
  volatile uint32_t *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = (void *)(uintptr_t)(off_115628);
  v3 = *((volatile uint32_t *)off_115628 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(volatile uint32_t *)off_11562C;
  if ( (dword_115630 & *(volatile uint32_t *)off_11562C) == 0 )
  {
    v6 = dword_115634 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = sub_1145ac(0);
      v10 = (void *)(uintptr_t)(off_11563C);
      *(volatile uint32_t *)off_11563C = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        get_global_1671e0(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      get_global_1671e0(0, a2, v4);
      if ( !*((volatile uint8_t *)off_115638 + 3) )
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



// peripheral_clock_enable_1 @ 0x115640
/* luna: Completes the RWNX low-power wake handshake, restores clock-gating state, and refreshes timer snapshots for active contexts. */
unsigned int peripheral_clock_enable_1() {
  volatile uint32_t *v0; // r2
  volatile uint8_t *v1; // r4
  volatile uint32_t *wake_handshake_reg; // r2
  volatile int *v3; // r6
  volatile uint32_t *v4; // r3
  volatile uint8_t **v5; // r5
  int v6; // r3
  unsigned int result; // r0
  volatile uint8_t *v8; // r7
  int v9; // r3
  int context_entry; // r3
  int context_end; // r1

  v0 = (void *)(uintptr_t)(off_11576C);
  *((volatile uint32_t *)off_115768 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = (void *)(uintptr_t)(off_115774);
  check_status_bits(2, aW);
  wake_handshake_reg = (void *)(uintptr_t)(off_115778);
  *(volatile uint32_t *)off_115778 |= 0x80000000;
  v1[1] = 0;
  while ( (*wake_handshake_reg & 0x40000000) == 0 )
    ;
  v3 = (volatile int *)off_11577C;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_11577C)[47]) && **(volatile int16_t **)off_115780 < 0 && *v1 != (*(volatile uint32_t *)off_115794 & 0xF) )
    mmio_clear_register((int)aRwnxEnvPrevHwS, (int)aRwnxlWakeup, 968);
  v4 = (void *)(uintptr_t)(off_115778);
  v5 = (volatile uint8_t **)off_115784;
  *(volatile uint32_t *)off_115778 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(volatile uint32_t *)off_1157A8 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(volatile uint32_t *)off_1157A4 &= ~0x20u;
  }
  if ( *(volatile uint8_t *)off_115788 )
    *(volatile uint32_t *)off_11576C |= 0x2000000u;
  else
    *((volatile uint32_t *)off_115768 + 14) &= ~0x10u;
  result = check_status_bits(2, aWe_0);
  v8 = *(volatile uint8_t **)off_115790;
  v9 = **(volatile uint8_t **)off_115790;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(volatile uint32_t *)off_1157A8 &= ~1u;
  }
  else
  {
    if ( !*((volatile uint8_t *)v3 + 189) )
    {
      *(volatile uint32_t *)off_115794 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      context_entry = dword_115798;
      context_end = dword_11579C;
      do
      {
        if ( *(volatile uint8_t *)(context_entry + 37) )
        {
          result = (*(volatile uint32_t *)0x40501010u);
          **(volatile uint32_t **)(context_entry + 340) = result;
        }
        context_entry += 696;
      }
      while ( context_entry != context_end );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}


// system_init @ 0x1157b4
/* luna: Clears a startup flag and invokes initialization helpers for kernel and Bluetooth state. */
int system_init() {
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((volatile uint8_t *)off_1157D4 + 1) = 0;
  v0 = (int)(uintptr_t)(reset_global_0x18274c());
  v1 = ke_task_reset(v0);
  v2 = (int)(uintptr_t)(get_bt_state(v1));
  v3 = assert_fail_record(v2);
  return init_global_0x1922d4(v3);
}



// check_event_flag @ 0x1157d8
/* luna: Handles a firmware reset event by reinitializing radio-related state, applying any pending PHY update, and releasing the reset critical section. */
volatile uint32_t * check_event_flag(int a1, int a2) {
  volatile int *reset_refcount; // r4
  volatile uint32_t *v3; // r3
  volatile unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r3
  volatile uint32_t *v7; // r5
  unsigned int phy_update_state; // r5
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

  if ( (**(volatile uint16_t **)dword_115934 & 1) != 0 )
    sub_12F194();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_115938 = 1;
  }
  reset_refcount = (volatile int *)dword_11593C;
  ++*(volatile uint32_t *)dword_11593C;
  check_status_bits(1024, "%s\r\n", aRwnxlResetEvt);
  unknown_func_12d14c(0x80000000);
  rf_clear_status();
  v3 = (volatile uint32_t *)dword_115948;
  *(volatile uint32_t *)dword_115948 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (volatile uint32_t *)dword_115950;
  *(volatile uint32_t *)dword_115950 |= 0x111u;
  mem_pool_init();
  *(volatile uint32_t *)dword_115948 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  radio_is_ready();
  if ( !rx_rate_field_parse(0) )
    unknown_func_12d14c(0x2000000);
  phy_update_state = dword_115954;
  ble_sched_poll();
  if ( *(volatile uint8_t *)phy_update_state && !*(volatile uint8_t *)dword_115958 && *(volatile uint8_t *)(phy_update_state + 6) )
  {
    v16 = (char)(*(volatile uint8_t *)(phy_update_state + 5) + (*(volatile uint8_t *)dword_115974 & 3));
    v17 = *(volatile char *)(phy_update_state + 7) + v16;
    if ( v17 >= *(volatile char *)(phy_update_state + 4) )
      v17 = (v17 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(phy_update_state + 4)) & 0xFFu);
    write_phy_config(v17);
    v18 = *(volatile uint16_t *)(phy_update_state + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(volatile uint8_t *)(phy_update_state + 7) = v17;
    *(volatile uint8_t *)(phy_update_state + 0xB) = 1;
    unknown_worker((volatile uint32_t *)(phy_update_state + 12), v19 + 60000 * v18);
    event_dispatch("update %d, %d\r\n", (char)v17, v16);
  }
  *(volatile uint8_t *)(phy_update_state + 6) = 0;
  check_status_bits(1024, aResetDone);
  if ( rf_status_poll() )
    unknown_func_12d104(0x80000);
  v9 = (volatile uint32_t *)dword_115968;
  v10 = (volatile uint32_t *)dword_11596C;
  v11 = *(volatile uint64_t *)(*(volatile uint32_t *)dword_115960 + 8);
  *(volatile uint32_t *)dword_115964 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (volatile uint32_t *)dword_115970;
  v13 = *reset_refcount;
  *(volatile uint32_t *)(dword_115970 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(volatile uint32_t *)dword_115938;
    *reset_refcount = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}


// gpio_read_input @ 0x11597c
/* luna: Performs mode-dependent peripheral setup and sets the shared status byte if any enabled NVIC interrupt among IRQs 0–95 is pending. */
volatile uint8_t *gpio_read_input() {
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

  v0 = (void *)(uintptr_t)(off_115AA8);
  v1 = (void *)(uintptr_t)(off_115AAC);
  *(volatile uint8_t *)off_115AAC = *(volatile uint8_t *)off_115AA8 & 0xF;
  check_status_bits(2, "d %d,", *v0 & 0xF);
  if ( *v0 << 28 )
  {
    v2 = (void *)(uintptr_t)(off_115AB8);
    *(volatile uint32_t *)off_115AB4 &= ~0x80000000;
    *v0 = 0;
    while ( (*v2 & 4) == 0 )
      ;
    v3 = (void *)(uintptr_t)(off_115AB4);
    v4 = (volatile int *)off_115AC0;
    *(volatile uint32_t *)off_115ABC = 4;
    v5 = *((volatile uint8_t *)v4 + 189);
    *v3 |= 0x80000000;
    if ( v5 )
      *(volatile uint32_t *)((volatile char *)v3 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(volatile uint32_t *)off_115AD0 &= ~0x8000000u;
  }
  v6 = (void *)(uintptr_t)(off_115AC4);
  v7 = (void *)(uintptr_t)(off_115AA8);
  *(volatile uint32_t *)off_115AC4 |= 0x111u;
  v1[1] = 1;
  *v7 = 32;
  v8 = (volatile uint8_t **)off_115AC8;
  *v6 &= 0xFFFFFEEE;
  v9 = **v8;
  if ( v9 == 3 )
  {
    v13 = (void *)(uintptr_t)(off_115AD4);
    *(volatile uint32_t *)off_115AD4 |= 1u;
    if ( (*v13 & 4) != 0 )
      *(volatile uint32_t *)off_115AD8 = 512;
  }
  else if ( v9 == 1 )
  {
    ipc_wait_flag();
    v14 = (void *)(uintptr_t)(off_115AE0);
    *(volatile uint32_t *)off_115ADC |= 0x20u;
    v14[20] |= 0x20000u;
    v14[20] |= 0x8000u;
    v14[20] |= 0x10000u;
    v14[20] = v14[20] & 0xFFFFFFC0 | 0x37;
    v14[23] = v14[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = (void *)(uintptr_t)(off_115ACC);
  v11 = 0;
  *(volatile uint8_t *)off_115ACC = 0;
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


// clear_rx_config @ 0x115ae4
/* luna: Checks Wi-Fi/BT coexistence state and RF/GPIO gates, then dispatches the corresponding idle or BT event when eligible. */
void clear_rx_config(int result) {
  volatile uint8_t **v1; // r5
  volatile uint8_t *v2; // r1
  volatile uint8_t **v3; // r6
  int v4; // r3
  volatile int *v5; // r3
  volatile uint8_t *v6; // r4
  volatile uint8_t *v7; // r4
  int v8; // r3
  volatile unsigned int v9; // r2
  volatile unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  char v14; // r0
  char v15; // r0
  char v16; // r0

  if ( !*(volatile uint8_t *)dword_115CF8 || (*(volatile uint32_t *)(dword_115CFC + 0x10) & 0xFFFF00) != 0x10000 )
  {
    if ( *(volatile uint8_t *)(dword_115CFC + 0x12) )
    {
      v6 = (volatile uint8_t *)dword_115D14;
      goto LABEL_23;
    }
    v1 = (volatile uint8_t **)dword_115D00;
    v2 = *(volatile uint8_t **)dword_115D00;
    if ( **(volatile uint8_t **)dword_115D00 )
    {
      v3 = (volatile uint8_t **)dword_115D04;
    }
    else
    {
      v5 = *(volatile int **)(dword_115CFC + 8);
      v6 = (volatile uint8_t *)dword_115D14;
      *(volatile uint8_t *)dword_115D14 = 1;
      while ( v5 )
      {
        if ( *((volatile uint8_t *)v5 + 106) )
        {
          if ( *((volatile uint8_t *)v5 + 106) == 2 )
          {
LABEL_20:
            if ( **(volatile uint8_t **)dword_115D04 != 3 )
              check_status_bits(2, "lp=%d, ignore=%d\n", *v2, 0);
LABEL_23:
            *v6 = 0;
            return;
          }
        }
        else if ( *((volatile uint8_t *)v5 + 108) )
        {
          goto LABEL_20;
        }
        v5 = (volatile int *)*v5;
      }
      v3 = (volatile uint8_t **)dword_115D04;
      if ( **(volatile uint8_t **)dword_115D04 == 3 )
        goto LABEL_8;
      check_status_bits(2, "lp=%d, ignore=%d\n", *v2, 1);
      *v6 = 1;
    }
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v15 = rf_read_status_bit();
        *(volatile uint8_t *)dword_115D20 = v15;
        if ( v15 )
          event_dispatch(aWifiidleBtAllo);
        else
          event_dispatch(aWifiidleBtNotA);
        if ( get_status_flag() )
          gpio_read_input();
        ipc_wait_flag();
        return;
      }
      if ( !get_status_flag() || *(volatile uint8_t *)dword_115D30 )
        return;
    }
    else if ( v4 == 2 )
    {
      return;
    }
LABEL_8:
    if ( !wlc_bss_state()
      || *(volatile uint32_t *)(dword_115D08 + 0x1F8)
      || !((*(volatile uint32_t *)dword_115D0C >> 25) & 1 | *(volatile uint8_t *)(dword_115D10 + 0x24))
      || *(volatile uint8_t *)(dword_115D10 + 0x1D)
      || !rf_read_irq_flags() )
    {
      return;
    }
    v14 = rf_read_status_bit();
    *(volatile uint8_t *)dword_115D20 = v14;
    if ( !v14 )
    {
      event_dispatch(aBt1);
      ipc_wait_flag();
    }
    if ( (uint8_t)**v1 > 1u )
      return;
LABEL_46:
    gpio_read_input();
    return;
  }
  v7 = (volatile uint8_t *)dword_115D20;
  v8 = *(volatile uint8_t *)dword_115D1C;
  *(volatile uint8_t *)dword_115D20 = 0;
  if ( v8 )
  {
    check_status_bits(2, aApPsForbid);
    return;
  }
  if ( !*(volatile uint8_t *)dword_115D24 )
  {
    check_status_bits(2, aAa);
    return;
  }
  if ( *(volatile uint32_t *)dword_115D28 )
  {
    v9 = (*(volatile uint32_t *)0x40501010u);
    if ( (int)(*(volatile uint32_t *)(*(volatile uint32_t *)dword_115D28 + 12) - v9 - 5000) < 0 )
    {
      check_status_bits(2, aMm);
      return;
    }
  }
  if ( !*(volatile uint8_t *)dword_115D30
    && !*(volatile uint32_t *)(dword_115D08 + 0x1F8)
    && ((dword_115D38 & *(volatile uint32_t *)dword_115D34) == 0 || (unsigned int)(32 * *(volatile uint32_t *)dword_115D3C) > 0x1387) )
  {
    ipc_wait_flag();
    v10 = (*(volatile uint32_t *)0x40501010u);
    v11 = v10 + 28;
    do
      v12 = v11 - (*(volatile uint32_t *)0x40501010u);
    while ( v12 >= 0 );
    if ( **(volatile uint8_t **)dword_115D04 == 1 )
    {
      v16 = rf_read_status_bit();
      *v7 = v16;
      if ( !v16 )
      {
        check_status_bits(2, aWifiidleBtNotA);
        return;
      }
    }
    v13 = dword_115D40;
    *(volatile uint8_t *)dword_115D14 = 1;
    *(volatile uint32_t *)(v13 + 0x38) |= 0x10u;
    if ( !get_status_flag() )
    {
      check_status_bits(2, aSdioNotAllowed);
      return;
    }
    goto LABEL_46;
  }
}


// copy_global_data @ 0x115d60
/* luna: Initializes radio state, then repeatedly services transmit and configuration work and waits for event or interrupt conditions. */
void copy_global_data() {
  unsigned int v0; // r5
  volatile uint8_t **v1; // r10
  int v2; // r3
  int v3; // r0
  int v4; // r1
  volatile uint8_t *v5; // r7
  volatile int *v6; // r8
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

  v0 = dword_115F30;
  event_dispatch("\x9A%s - build: %s\n", aV6911, aLaJul032024152);
  if ( *(volatile uint32_t *)dword_115F34 )
  {
    mmio_write_70001408();
    if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
      rf_set_frequency(*(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8));
  }
  v1 = (volatile uint8_t **)dword_115F5C;
  if ( **(volatile uint8_t **)dword_115F5C == 2 )
  {
    v2 = *(volatile uint32_t *)v0;
    *(volatile uint8_t *)(v2 + 6) = 2;
    *(volatile uint8_t *)(v2 + 3) = 1;
  }
  v3 = load_global_ptr_182558(*(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4));
  if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
    clear_global_flag_2();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v5 = (volatile uint8_t *)dword_115F38;
  v6 = (volatile int *)dword_115F60;
  v7 = (volatile int *)dword_115F3C;
  v8 = (volatile int *)dword_115F40;
  v9 = dword_115F64;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
        dummy_store_global();
      if ( !*v5 )
        tx_ring_peek();
      v3 = parse_large_ioctl(v3, v4);
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
    clear_rx_config(v3);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
      clear_global_flag_2();
    if ( **v1 == 1 && *(volatile uint8_t *)dword_115F44 )
      break;
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
      v3 = ((int (*)())check_nvic_irq_status)();
    }
    while ( !v3 );
    if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v0 + 3) )
      goto LABEL_23;
LABEL_28:
    set_global_flag_2();
    if ( *(volatile uint8_t *)(v9 + 1) )
LABEL_29:
      v3 = peripheral_clock_enable_1();
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
  v14 = **(volatile uint8_t **)dword_115F48;
  if ( v14 == 3 )
  {
    v3 = get_status_flag();
    if ( v3 )
      goto LABEL_36;
    v14 = **(volatile uint8_t **)dword_115F48;
  }
  if ( v14 == 1 )
  {
    if ( !*(volatile uint8_t *)(v9 + 1) || *(volatile uint8_t *)dword_115F58 )
      goto LABEL_21;
  }
  else if ( v14 || !*(volatile uint8_t *)dword_115F4C || !*(volatile uint8_t *)(v9 + 1) )
  {
    goto LABEL_21;
  }
LABEL_36:
  ipc_wait_flag();
  v15 = (*(volatile uint32_t *)0x40501010u);
  v16 = v15 + 28;
  do
    v17 = (*(volatile uint32_t *)0x40501010u);
  while ( (int)(v16 - v17) >= 0 );
  v18 = (volatile uint32_t *)dword_115F54;
  *(volatile uint32_t *)(dword_115F54 + 4) |= 0x1000u;
  v18[21] |= 0x1000u;
  *v18 |= 0x1000u;
  goto LABEL_21;
}


