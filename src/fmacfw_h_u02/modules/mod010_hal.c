// patch_apply @ 0x114af0
int patch_apply(int a1, int a2, unsigned int a3) {
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
  if ( !*(volatile uint32_t *)off_114BE8 )
    get_global_context();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114BEC + 0x2000, 72, _frame._rom_block);
  if ( _frame.f.v9[0] != dword_114BF0 )
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



// send_smc_cmd_2 @ 0x114bf4
int send_smc_cmd_2(int a1) {
  return patch_apply(1, a1, 4u);
}



// send_smc_cmd_4 @ 0x114c00
int send_smc_cmd_4(int a1) {
  return patch_apply(2, a1, 0xCu);
}



// send_smc_cmd_0x20 @ 0x114c0c
/* luna: Forwards the supplied argument to patch_apply with selector 4 and size 0x14, returning its result. */
int send_smc_cmd_0x20(int a1) {
  return patch_apply(4, a1, 0x14u);
}



// send_smc_cmd_0x40 @ 0x114c18
int send_smc_cmd_0x40(int a1) {
  return patch_apply(32, a1, 4u);
}



// send_smc_cmd_0x80 @ 0x114c24
int send_smc_cmd_0x80(int a1) {
  return patch_apply(64, a1, 4u);
}



// patch_validate @ 0x114c30
int patch_validate(int a1) {
  return patch_apply(128, a1, 4u);
}



// patch_apply_ext @ 0x114c3c
int patch_apply_ext(int a1, int a2, unsigned int a3) {
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
  if ( !*(volatile uint32_t *)off_114D20 )
    get_global_context();
  ((int (*)())MEMD(0x1D8))(*(volatile uint32_t *)off_114D24 + 4096, 320, _frame._rom_block);
  if ( _frame.f.v8 != dword_114D28 )
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



// send_smc_cmd_0x400000 @ 0x114d2c
/* luna: Forwards the supplied value to patch_apply_ext with fixed parameters 2 and 6. */
int send_smc_cmd_0x400000(int a1) {
  return patch_apply_ext(2, a1, 6u);
}



// get_rssi @ 0x114d38
/* luna: Queries RSSI through the 0x400000 extension command and returns its result. */
int get_rssi(int a1) {
  return patch_apply_ext(0x400000, a1, 4u);
}



// is_rssi_valid @ 0x114d44
void is_rssi_valid() {
  if ( **(volatile int16_t **)off_114D60 < 0 )
    irq_disable_mmio_write(dword_114D68, dword_114D64, 242);
  while ( 1 )
    ;
}



// check_patch_signature @ 0x114d6c
void check_patch_signature() {
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

  v0 = (void *)(uintptr_t)(off_114DDC);
  if ( *(volatile uint32_t *)off_114DDC == dword_114DE0 && *((volatile uint32_t *)off_114DDC + 2) == dword_114DE0 + 135327480 )
  {
    v1 = *((volatile uint32_t *)off_114DDC + 1);
    v2 = v1 & 3;
    if ( (v1 & 3) == 0 )
    {
      if ( *((volatile uint32_t *)off_114DDC + 3) )
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
      v5 = (volatile int *)dword_114DE4;
      v6 = dword_114DE4 + 16;
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



// is_patch_loaded @ 0x114de8
/* luna: Clears and copies firmware memory sections, configures startup state, loads the AES key, checks the patch signature, initializes MAC state, and then e */
void is_patch_loaded() {
  volatile uint32_t *zero_fill_ptr; // r2
  unsigned int zero_fill_end; // r3
  int initialized_data_start; // r1
  volatile int *initialized_data_source; // r2
  volatile int *initialized_data_source_end; // r3
  volatile uint32_t *initialized_data_dest; // r0
  int copied_word; // t1
  volatile uint32_t *platform_state_base; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int boot_flags; // r3
  volatile char *v12; // r2

  zero_fill_ptr = (volatile uint32_t *)dword_114EA4;
  if ( dword_114EA4 < (unsigned int)dword_114EA8 )
  {
    zero_fill_end = ((dword_114EA8 - 1 - dword_114EA4) & 0xFFFFFFFC) + 4 + dword_114EA4;
    do
      *zero_fill_ptr++ = 0;
    while ( zero_fill_ptr != (volatile uint32_t *)zero_fill_end );
  }
  initialized_data_start = dword_114EAC;
  if ( dword_114EAC < (unsigned int)dword_114EB0 )
  {
    initialized_data_source = (volatile int *)off_114EB4;
    initialized_data_source_end = (volatile int *)((volatile char *)&((volatile uint32_t *)(uintptr_t)off_114EB4)[1] + ((dword_114EB0 - 1 - dword_114EAC) & 0xFFFFFFFC));
    initialized_data_dest = (volatile uint32_t *)dword_114EAC;
    do
    {
      copied_word = *initialized_data_source++;
      *initialized_data_dest++ = copied_word;
    }
    while ( initialized_data_source != initialized_data_source_end );
  }
  platform_state_base = (void *)(uintptr_t)(off_114EB8);
  v8 = dword_114EBC;
  *((volatile uint32_t *)off_114EB8 + 34) |= 0xF00000u;
  platform_state_base[2] = initialized_data_start;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(volatile uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(volatile uint32_t *)off_114EB8 == 49729 )
    *(volatile uint32_t *)off_114EC0 = 1;
  boot_flags = HIBYTE(*(volatile uint32_t *)off_114EC4);
  *(volatile uint8_t *)off_114EC8 = boot_flags;
  if ( (boot_flags & 4) != 0 )
  {
    v12 = (void *)(uintptr_t)(off_114ED0);
    *(volatile uint32_t *)(uintptr_t)(off_114ECC) = dword_114ED4;
    *v12 = 26;
  }
  if ( (boot_flags & 0x10) == 0 )
    *(volatile uint32_t *)off_114ED8 &= ~0x4000u;
  *(volatile uint8_t *)off_114EDC = BYTE2(*(volatile uint32_t *)off_114EC4);
  aes_load_key();
  check_patch_signature();
  mac_state_init();
  while ( 1 )
    ;
}


// get_phy_state @ 0x114ee0
int get_phy_state() {
  int v0; // r4
  volatile uint32_t *v1; // r3
  volatile uint32_t *v2; // r2
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3
  volatile uint32_t *v6; // r2

  if ( **(volatile uint8_t **)off_114FC8 == 2 )
  {
    if ( phy_get_status() )
      v0 = ((volatile uint32_t *)(uintptr_t)off_114FE8)[87];
    else
      v0 = 16;
    phy_is_calibrated();
    *((volatile uint32_t *)off_114FD4 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    alloc_tx_event(aSftDis);
    v6 = (void *)(uintptr_t)(off_114FE0);
    *((volatile uint32_t *)off_114FE0 + 513) |= 2u;
    v6[4] |= 1u;
    while ( (v6[4] & 1) != 0 )
      ;
    alloc_tx_event(aSftrstDone);
  }
  else
  {
    v0 = 16;
  }
  v1 = (void *)(uintptr_t)(off_114FCC);
  if ( (*((volatile uint32_t *)off_114FCC + 74) & 0x80) != 0 )
  {
    v2 = (void *)(uintptr_t)(off_114FD0);
    *((volatile uint32_t *)off_114FCC + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = (void *)(uintptr_t)(off_114FD0);
  if ( (*((volatile uint32_t *)off_114FD0 + 2) & 0x20000) != 0 )
  {
    *((volatile uint32_t *)off_114FCC + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = (void *)(uintptr_t)(off_114FD4);
  *((volatile uint32_t *)off_114FD4 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  nvic_disable_irq15();
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114FD8 + 3) )
    check_initialized();
  __disable_irq();
  return v0;
}


// apply_patch_table @ 0x114fec
/* luna: Prints the saved Cortex-M register context and SCB fault status, then dumps 256 bytes of the captured stack. */
int apply_patch_table() {
  volatile uint32_t *saved_context; // r7
  volatile int *saved_context_word_ptr; // r5
  int i; // r4
  int v3; // r1
  int register_value; // t1
  volatile uint32_t *scb_registers; // r5
  unsigned int cfsr; // r4
  int exception_return; // r3
  int v8; // r1
  int result; // r0
  int stack_pointer; // r4
  int v11; // r4
  unsigned int v12; // r4
  unsigned int v13; // r5
  int v14; // t1
  unsigned int dump_address; // r4
  unsigned int dump_end; // r5
  int stack_word; // t1

  saved_context = (void *)(uintptr_t)(off_1151BC);
  saved_context_word_ptr = (volatile int *)off_1151BC;
  for ( i = 0; i != 13; ++i )
  {
    v3 = i;
    register_value = *saved_context_word_ptr++;
    debug_printf("\nR%-4d: %08X", v3, register_value);
  }
  scb_registers = (void *)(uintptr_t)(off_1151C4);
  debug_printf(aSp08xLr08xPc08, saved_context[13], saved_context[14], saved_context[15], saved_context[16], saved_context[17], saved_context[18]);
  debug_printf("\nCPUID: %08X\nICSR : %08X\nVTOR : %08X\nAIRCR: %08X", *scb_registers, scb_registers[1], scb_registers[2], scb_registers[3]);
  debug_printf(
    "\nSHCSR: %08X\nCFSR : %08X\nHFSR : %08X\nDFSR : %08X\nAFSR : %08X",
    scb_registers[9],
    scb_registers[10],
    scb_registers[11],
    scb_registers[12],
    scb_registers[15]);
  cfsr = scb_registers[10];
  if ( (uint8_t)cfsr )
  {
    debug_printf(
      "\nMMFSR: %02X\n  IACCVIOL :%d\tDACCVIOL :%d\n  MUNSTKERR:%d\tMSTKERR  :%d\n  MLSPERR  :%d\tMMARVALID:%d",
      (uint8_t)scb_registers[10],
      cfsr & 1,
      (cfsr >> 1) & 1,
      (cfsr >> 3) & 1,
      (cfsr >> 4) & 1,
      (cfsr >> 5) & 1,
      (cfsr >> 7) & 1);
    if ( (cfsr & 0x80) != 0 )
      debug_printf("\nMMFAR: %08X", scb_registers[13]);
  }
  if ( (cfsr & 0xFF00) != 0 )
  {
    debug_printf(
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
      debug_printf("\nBFAR : %08X", *((volatile uint32_t *)off_1151C4 + 14));
  }
  if ( HIWORD(cfsr) )
    debug_printf(
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
    debug_printf(aModeHandler);
    goto LABEL_9;
  }
  debug_printf(aModeThread);
  if ( (saved_context[20] & 1) == 0 )
  {
LABEL_9:
    debug_printf(aPrivPrivileged);
    goto LABEL_10;
  }
  debug_printf(aPrivUser);
LABEL_10:
  exception_return = saved_context[19];
  v8 = exception_return << 29;
  if ( (exception_return & 4) != 0 )
    debug_printf(aStackPsp, v8);
  else
    debug_printf(aStackMsp, v8);
  result = debug_printf(aCntrl08xPmask0, saved_context[20], __get_CPSR(), __get_CPSR(), __get_CPSR());
  stack_pointer = saved_context[18];
  if ( stack_pointer )
  {
    dump_address = stack_pointer & 0xFFFFFFF0;
    debug_printf(aDumpmsp_0);
    dump_end = dump_address + 256;
    do
    {
      if ( !(dump_address << 28) )
        debug_printf("\n[%08x]:", dump_address);
      stack_word = *(volatile uint32_t *)dump_address;
      dump_address += 4;
      result = debug_printf(" %08X", stack_word);
    }
    while ( dump_end != dump_address );
  }
  v11 = saved_context[17];
  if ( v11 )
  {
    v12 = v11 & 0xFFFFFFF0;
    debug_printf(aDumppsp_0);
    v13 = v12 + 256;
    do
    {
      if ( !(v12 << 28) )
        debug_printf("\n[%08x]:", v12);
      v14 = *(volatile uint32_t *)v12;
      v12 += 4;
      result = debug_printf(" %08X", v14);
    }
    while ( v13 != v12 );
  }
  return result;
}


// log_boot_message @ 0x115214
void log_boot_message() {
  int v0; // r0
  int v1; // r0
  int v2; // r1
  int v3; // r0

  debug_printf(aPanic_0);
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_11524C + 6) == 2 )
  {
    v3 = get_phy_state();
    rf_set_frequency(v3);
  }
  while ( 1 )
  {
    while ( !radio_rx_status() )
      ;
    v0 = radio_rx_read_byte();
    v1 = lock_with_timeout(v0);
    rf_calibration_proc(v1, v2);
  }
}


// process_debug_char @ 0x115250
void process_debug_char(int a1) {
  debug_printf(aFaultHandlerFa);
  switch ( a1 )
  {
    case '0':
      debug_printf(aBusfault);
      break;
    case '@':
      debug_printf(aUsagefault);
      break;
    case ' ':
      debug_printf(aMemmanagefault);
      break;
    default:
      debug_printf(aHardfault);
      break;
  }
  debug_printf(aContext);
  apply_patch_table();
  debug_printf(aFaultHandler);
  log_boot_message();
}


// int_flag_clear @ 0x115384
int int_flag_clear() {
  *(volatile uint8_t *)off_115390 = 0;
  return alloc_tx_event(aApPsForbidTo);
}


// int_flag_get @ 0x115398
int int_flag_get() {
  volatile uint8_t *v0; // r4
  int result; // r0
  volatile uint32_t *v2; // r3
  int v3; // r3
  volatile unsigned int v4; // r1

  v0 = (void *)(uintptr_t)(off_11544C);
  if ( !*(volatile uint8_t *)off_11544C && *(volatile uint8_t *)off_115450 )
  {
    result = check_feature_flag(2, aPsall);
    v2 = (volatile uint32_t *)off_115460;
    *v0 = 1;
    if ( (uint16_t)*v2 )
    {
      switch ( *(volatile uint8_t *)off_115464 )
      {
        case 1:
          v3 = 700 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
        case 2:
          v3 = 500 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
        case 3:
          v3 = 300 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
        case 4:
          v3 = 200 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
        case 5:
          v3 = 100 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
        default:
          v3 = 100 * (uint16_t)*(volatile uint32_t *)off_115460;
          break;
      }
      v4 = (*(volatile uint32_t *)0x40501010u);
      return mem_copy_util((void *)(uintptr_t)(off_11546C), v4 + v3);
    }
  }
  else
  {
    result = check_feature_flag(2, aPsnotall);
    if ( *((volatile uint8_t *)off_115458 + 18) )
      *v0 = 0;
  }
  return result;
}


// fault_status_read @ 0x115470
int fault_status_read(int a1, int a2) {
  volatile uint32_t *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = (void *)(uintptr_t)(off_1154E8);
  v3 = *((volatile uint32_t *)off_1154E8 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(volatile uint32_t *)off_1154EC;
  if ( (dword_1154F0 & *(volatile uint32_t *)off_1154EC) == 0 )
  {
    v6 = dword_1154F4 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = default_handler(0);
      v10 = (void *)(uintptr_t)(off_1154FC);
      *(volatile uint32_t *)off_1154FC = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        get_config_b(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      get_config_b(0, a2, v4);
      if ( !*((volatile uint8_t *)off_1154F8 + 3) )
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



// rf_power_control @ 0x115500
unsigned int rf_power_control() {
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

  v0 = (void *)(uintptr_t)(off_11562C);
  *((volatile uint32_t *)off_115628 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = (void *)(uintptr_t)(off_115634);
  check_feature_flag(2, aW);
  v2 = (void *)(uintptr_t)(off_115638);
  *(volatile uint32_t *)off_115638 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = (volatile int *)off_11563C;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_11563C)[47]) && **(volatile int16_t **)off_115640 < 0 && *v1 != (*(volatile uint32_t *)off_115654 & 0xF) )
    irq_disable_mmio_write((int)aRwnxEnvPrevHwS, (int)aRwnxlWakeup, 968);
  v4 = (void *)(uintptr_t)(off_115638);
  v5 = (volatile uint8_t **)off_115644;
  *(volatile uint32_t *)off_115638 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(volatile uint32_t *)off_115668 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(volatile uint32_t *)off_115664 &= ~0x20u;
  }
  if ( *(volatile uint8_t *)off_115648 )
    *(volatile uint32_t *)off_11562C |= 0x2000000u;
  else
    *((volatile uint32_t *)off_115628 + 14) &= ~0x10u;
  result = check_feature_flag(2, aWe_0);
  v8 = *(volatile uint8_t **)off_115650;
  v9 = **(volatile uint8_t **)off_115650;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(volatile uint32_t *)off_115668 &= ~1u;
  }
  else
  {
    if ( !*((volatile uint8_t *)v3 + 189) )
    {
      *(volatile uint32_t *)off_115654 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115658;
      v11 = dword_11565C;
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


// system_init @ 0x115674
int system_init() {
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((volatile uint8_t *)off_115694 + 1) = 0;
  v0 = (int)(uintptr_t)(lock_init_0x18274c());
  v1 = vendor_platform_init(v0);
  v2 = (int)(uintptr_t)(get_rf_state(v1));
  v3 = update_modulation_mode(v2);
  return timer_init_0x1922d4(v3);
}



// rx_packet_pending @ 0x115698
volatile uint32_t * rx_packet_pending(int a1, int a2) {
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

  if ( (**(volatile uint16_t **)dword_1157F4 & 1) != 0 )
    dump_tx_queue_state();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_1157F8 = 1;
  }
  v2 = (volatile int *)dword_1157FC;
  ++*(volatile uint32_t *)dword_1157FC;
  check_feature_flag(1024, "%s\r\n", aRwnxlResetEvt);
  irq_disable_global_3(0x80000000);
  rf_radio_calibrate();
  v3 = (volatile uint32_t *)dword_115808;
  *(volatile uint32_t *)dword_115808 &= 0xFFFFFFu;
  *v3 |= 0x10u;
  v4 = (*(volatile uint32_t *)0x40501010u);
  v5 = v4 + 100;
  do
    v6 = v5 - (*(volatile uint32_t *)0x40501010u);
  while ( v6 >= 0 );
  v7 = (volatile uint32_t *)dword_115810;
  *(volatile uint32_t *)dword_115810 |= 0x111u;
  alloc_shared_ctx();
  *(volatile uint32_t *)dword_115808 &= ~0x10u;
  *v7 &= 0xFFFFFEEE;
  is_band_5g();
  if ( !hci_cmd_handler(0) )
    irq_disable_global_3(0x2000000);
  v8 = dword_115814;
  is_sleep_state_active();
  if ( *(volatile uint8_t *)v8 && !*(volatile uint8_t *)dword_115818 && *(volatile uint8_t *)(v8 + 6) )
  {
    v16 = (char)(*(volatile uint8_t *)(v8 + 5) + (*(volatile uint8_t *)dword_115834 & 3));
    v17 = *(volatile char *)(v8 + 7) + v16;
    if ( v17 >= *(volatile char *)(v8 + 4) )
      v17 = (v17 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v8 + 4)) & 0xFFu);
    rf_reg_write_byte(v17);
    v18 = *(volatile uint16_t *)(v8 + 8);
    v19 = (*(volatile uint32_t *)0x40501010u);
    *(volatile uint8_t *)(v8 + 7) = v17;
    *(volatile uint8_t *)(v8 + 0xB) = 1;
    mem_copy_util((volatile uint32_t *)(v8 + 12), v19 + 60000 * v18);
    alloc_tx_event("update %d, %d\r\n", (char)v17, v16);
  }
  *(volatile uint8_t *)(v8 + 6) = 0;
  check_feature_flag(1024, aResetDone);
  if ( check_fw_rom_signature() )
    irq_disable_global_2(0x80000);
  v9 = (volatile uint32_t *)dword_115828;
  v10 = (volatile uint32_t *)dword_11582C;
  v11 = *(volatile uint64_t *)(*(volatile uint32_t *)dword_115820 + 8);
  *(volatile uint32_t *)dword_115824 = v11;
  *v9 = HIDWORD(v11) + v11 - 4;
  *v10 = v11;
  v9[2] = v11;
  result = (volatile uint32_t *)dword_115830;
  v13 = *v2;
  *(volatile uint32_t *)(dword_115830 + 0x14) = v11;
  result[3] = v11;
  result[4] = HIDWORD(v11) + v11;
  if ( v13 )
  {
    v14 = v13 - 1;
    v15 = *(volatile uint32_t *)dword_1157F8;
    *v2 = v14;
    if ( !v14 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  return result;
}


// chip_revision_read @ 0x11583c
volatile uint8_t *chip_revision_read() {
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

  v0 = (void *)(uintptr_t)(off_115968);
  v1 = (void *)(uintptr_t)(off_11596C);
  *(volatile uint8_t *)off_11596C = *(volatile uint8_t *)off_115968 & 0xF;
  check_feature_flag(2, "d %d,", *v0 & 0xF);
  if ( *v0 << 28 )
  {
    v2 = (void *)(uintptr_t)(off_115978);
    *(volatile uint32_t *)off_115974 &= ~0x80000000;
    *v0 = 0;
    while ( (*v2 & 4) == 0 )
      ;
    v3 = (void *)(uintptr_t)(off_115974);
    v4 = (volatile int *)off_115980;
    *(volatile uint32_t *)off_11597C = 4;
    v5 = *((volatile uint8_t *)v4 + 189);
    *v3 |= 0x80000000;
    if ( v5 )
      *(volatile uint32_t *)((volatile char *)v3 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(volatile uint32_t *)off_115990 &= ~0x8000000u;
  }
  v6 = (void *)(uintptr_t)(off_115984);
  v7 = (void *)(uintptr_t)(off_115968);
  *(volatile uint32_t *)off_115984 |= 0x111u;
  v1[1] = 1;
  *v7 = 32;
  v8 = (volatile uint8_t **)off_115988;
  *v6 &= 0xFFFFFEEE;
  v9 = **v8;
  if ( v9 == 3 )
  {
    v13 = (void *)(uintptr_t)(off_115994);
    *(volatile uint32_t *)off_115994 |= 1u;
    if ( (*v13 & 4) != 0 )
      *(volatile uint32_t *)off_115998 = 512;
  }
  else if ( v9 == 1 )
  {
    mmio_read_bit13();
    v14 = (void *)(uintptr_t)(off_1159A0);
    *(volatile uint32_t *)off_11599C |= 0x20u;
    v14[20] |= 0x20000u;
    v14[20] |= 0x8000u;
    v14[20] |= 0x10000u;
    v14[20] = v14[20] & 0xFFFFFFC0 | 0x37;
    v14[23] = v14[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = (void *)(uintptr_t)(off_11598C);
  v11 = 0;
  *(volatile uint8_t *)off_11598C = 0;
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


// sleep_mode_read @ 0x1159a4
void sleep_mode_read(int result) {
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

  if ( !*(volatile uint8_t *)dword_115BB8 || (*(volatile uint32_t *)(dword_115BBC + 0x10) & 0xFFFF00) != 0x10000 )
  {
    if ( *(volatile uint8_t *)(dword_115BBC + 0x12) )
    {
      v6 = (volatile uint8_t *)dword_115BD4;
      goto LABEL_23;
    }
    v1 = (volatile uint8_t **)dword_115BC0;
    v2 = *(volatile uint8_t **)dword_115BC0;
    if ( **(volatile uint8_t **)dword_115BC0 )
    {
      v3 = (volatile uint8_t **)dword_115BC4;
    }
    else
    {
      v5 = *(volatile int **)(dword_115BBC + 8);
      v6 = (volatile uint8_t *)dword_115BD4;
      *(volatile uint8_t *)dword_115BD4 = 1;
      while ( v5 )
      {
        if ( *((volatile uint8_t *)v5 + 106) )
        {
          if ( *((volatile uint8_t *)v5 + 106) == 2 )
          {
LABEL_20:
            if ( **(volatile uint8_t **)dword_115BC4 != 3 )
              check_feature_flag(2, "lp=%d, ignore=%d\n", *v2, 0);
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
      v3 = (volatile uint8_t **)dword_115BC4;
      if ( **(volatile uint8_t **)dword_115BC4 == 3 )
        goto LABEL_8;
      check_feature_flag(2, "lp=%d, ignore=%d\n", *v2, 1);
      *v6 = 1;
    }
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v15 = wait_radio_flag();
        *(volatile uint8_t *)dword_115BE0 = v15;
        if ( v15 )
          alloc_tx_event(aWifiidleBtAllo);
        else
          alloc_tx_event(aWifiidleBtNotA);
        if ( get_init_flag() )
          chip_revision_read();
        mmio_read_bit13();
        return;
      }
      if ( !get_init_flag() || *(volatile uint8_t *)dword_115BF0 )
        return;
    }
    else if ( v4 == 2 )
    {
      return;
    }
LABEL_8:
    if ( !mfp_key_get_status()
      || *(volatile uint32_t *)(dword_115BC8 + 0x1F8)
      || !((*(volatile uint32_t *)dword_115BCC >> 25) & 1 | *(volatile uint8_t *)(dword_115BD0 + 0x24))
      || *(volatile uint8_t *)(dword_115BD0 + 0x1D)
      || !rf_radio_status() )
    {
      return;
    }
    v14 = wait_radio_flag();
    *(volatile uint8_t *)dword_115BE0 = v14;
    if ( !v14 )
    {
      alloc_tx_event(aBt1);
      mmio_read_bit13();
    }
    if ( (uint8_t)**v1 > 1u )
      return;
LABEL_46:
    chip_revision_read();
    return;
  }
  v7 = (volatile uint8_t *)dword_115BE0;
  v8 = *(volatile uint8_t *)dword_115BDC;
  *(volatile uint8_t *)dword_115BE0 = 0;
  if ( v8 )
  {
    check_feature_flag(2, aApPsForbid);
    return;
  }
  if ( !*(volatile uint8_t *)dword_115BE4 )
  {
    check_feature_flag(2, aAa);
    return;
  }
  if ( *(volatile uint32_t *)dword_115BE8 )
  {
    v9 = (*(volatile uint32_t *)0x40501010u);
    if ( (int)(*(volatile uint32_t *)(*(volatile uint32_t *)dword_115BE8 + 12) - v9 - 5000) < 0 )
    {
      check_feature_flag(2, aMm);
      return;
    }
  }
  if ( !*(volatile uint8_t *)dword_115BF0
    && !*(volatile uint32_t *)(dword_115BC8 + 0x1F8)
    && ((dword_115BF8 & *(volatile uint32_t *)dword_115BF4) == 0 || (unsigned int)(32 * *(volatile uint32_t *)dword_115BFC) > 0x1387) )
  {
    mmio_read_bit13();
    v10 = (*(volatile uint32_t *)0x40501010u);
    v11 = v10 + 28;
    do
      v12 = v11 - (*(volatile uint32_t *)0x40501010u);
    while ( v12 >= 0 );
    if ( **(volatile uint8_t **)dword_115BC4 == 1 )
    {
      v16 = wait_radio_flag();
      *v7 = v16;
      if ( !v16 )
      {
        check_feature_flag(2, aWifiidleBtNotA);
        return;
      }
    }
    v13 = dword_115C00;
    *(volatile uint8_t *)dword_115BD4 = 1;
    *(volatile uint32_t *)(v13 + 0x38) |= 0x10u;
    if ( !get_init_flag() )
    {
      check_feature_flag(2, aSdioNotAllowed);
      return;
    }
    goto LABEL_46;
  }
}


// ll_init_tables @ 0x115c20
void ll_init_tables(int a1, int a2, int a3, int a4) {
  unsigned int v4; // r5
  volatile uint8_t **v5; // r10
  int v6; // r3
  int v7; // r0
  int v8; // r1
  volatile uint8_t *v9; // r7
  volatile int *v10; // r8
  volatile int *v11; // r4
  volatile int *v12; // r6
  unsigned int v13; // r11
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r2
  int v18; // r3
  volatile unsigned int v19; // r2
  unsigned int v20; // r2
  volatile unsigned int v21; // r3
  volatile uint32_t *v22; // r2

  v4 = dword_115DF0;
  alloc_tx_event("\x9A%s - build: %s\n", aV6911, aLaJul032024152);
  if ( *(volatile uint32_t *)dword_115DF4 )
  {
    write_mmio_register();
    if ( *(volatile uint16_t *)(*(volatile uint32_t *)v4 + 8) )
      rf_set_channel_1(*(volatile uint16_t *)(*(volatile uint32_t *)v4 + 8));
  }
  v5 = (volatile uint8_t **)dword_115E1C;
  if ( **(volatile uint8_t **)dword_115E1C == 2 )
  {
    v6 = *(volatile uint32_t *)v4;
    *(volatile uint8_t *)(v6 + 6) = 2;
    *(volatile uint8_t *)(v6 + 3) = 1;
  }
  v7 = scheduler_entry(*(volatile uint16_t *)(*(volatile uint32_t *)v4 + 4));
  if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
    rf_emit_setup_word();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v9 = (volatile uint8_t *)dword_115DF8;
  v10 = (volatile int *)dword_115E20;
  v11 = (volatile int *)dword_115DFC;
  v12 = (volatile int *)dword_115E00;
  v13 = dword_115E24;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
        memory_barrier();
      if ( !*v9 )
        process_event_queue();
      v7 = rf_calibration_proc(v7, v8);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v10 = 1;
      }
      v14 = *v12;
      v15 = *v11 + 1;
      *v11 = v15;
      if ( !v14 )
        break;
      if ( v15 )
        goto LABEL_15;
    }
    sleep_mode_read(v7);
    if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      rf_emit_setup_word();
    if ( **v5 == 1 && *(volatile uint8_t *)dword_115E04 )
      break;
    do
    {
LABEL_21:
      __dsb(0xFu);
      __wfi();
      __isb(0xFu);
      if ( **v5 != 3 )
      {
        if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
          goto LABEL_28;
LABEL_23:
        if ( *(volatile uint8_t *)(v13 + 1) )
          goto LABEL_29;
        goto LABEL_24;
      }
      v7 = ((int (*)())fault_status_read)();
    }
    while ( !v7 );
    if ( !*(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      goto LABEL_23;
LABEL_28:
    set_state_flag();
    if ( *(volatile uint8_t *)(v13 + 1) )
LABEL_29:
      v7 = rf_power_control();
LABEL_24:
    v15 = *v11;
    if ( *v11 )
    {
LABEL_15:
      v16 = v15 - 1;
      v17 = *v10;
      *v11 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
  }
  v18 = **(volatile uint8_t **)dword_115E08;
  if ( v18 == 3 )
  {
    v7 = get_init_flag();
    if ( v7 )
      goto LABEL_36;
    v18 = **(volatile uint8_t **)dword_115E08;
  }
  if ( v18 == 1 )
  {
    if ( !*(volatile uint8_t *)(v13 + 1) || *(volatile uint8_t *)dword_115E18 )
      goto LABEL_21;
  }
  else if ( v18 || !*(volatile uint8_t *)dword_115E0C || !*(volatile uint8_t *)(v13 + 1) )
  {
    goto LABEL_21;
  }
LABEL_36:
  mmio_read_bit13();
  v19 = (*(volatile uint32_t *)0x40501010u);
  v20 = v19 + 28;
  do
    v21 = (*(volatile uint32_t *)0x40501010u);
  while ( (int)(v20 - v21) >= 0 );
  v22 = (volatile uint32_t *)dword_115E14;
  *(volatile uint32_t *)(dword_115E14 + 4) |= 0x1000u;
  v22[21] |= 0x1000u;
  *v22 |= 0x1000u;
  goto LABEL_21;
}


