// get_config_b @ 0x11441c
/* luna: Allocates and returns a transmit event using the low-power-level error message. */
int get_config_b() {
  return alloc_tx_event(aErrorLpLevelPo);
}


// get_config_c @ 0x114428
/* luna: Allocates and returns a transmit event containing the fixed LP-level-power error message. */
int get_config_c() {
  return alloc_tx_event(aErrorLpLevelPo_0);
}


// process_event @ 0x114434
/* luna: Requests allocation of the LP-level power error TX event and, when the state flag is set, clears related control bits and resets that flag. */
int process_event() {
  int result; // r0
  volatile uint8_t *v1; // r3
  volatile uint32_t *v2; // r1

  result = alloc_tx_event(aErrorLpLevelPo_0);
  v1 = (void *)(uintptr_t)(off_114460);
  if ( *((volatile uint8_t *)off_114460 + 3) )
  {
    v2 = (void *)(uintptr_t)(off_114468);
    *(volatile uint32_t *)off_114464 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}


// default_handler @ 0x11446c
/* luna: Checks whether a timer request meets the configured timing constraints and stores an allow or deny status word. */
unsigned int default_handler(unsigned int result) {
  int v1; // r2

  if ( !result )
  {
    v1 = *(volatile uint32_t *)off_1144DC;
    if ( *(volatile uint32_t *)off_1144DC
      && (result = (*(volatile uint32_t *)0x40501010u), (int)(*(volatile uint32_t *)(v1 + 12) - result - LOWORD(((volatile uint32_t *)(uintptr_t)off_1144E4)[46]) - 2000) < 0) )
    {
      result = check_feature_flag(2, "timer: not allow %x\r\n", *(volatile uint32_t *)(v1 + 4));
    }
    else
    {
      if ( !*(volatile uint8_t *)off_1144E8
        || (result = (*(volatile uint32_t *)0x40501010u),
            (int)(*((volatile uint32_t *)off_1144E8 + 1)
                + *((volatile uint32_t *)off_1144E8 + 2)
                - result
                - LOWORD(((volatile uint32_t *)(uintptr_t)off_1144E4)[46])
                - *(volatile uint16_t *)(*(volatile uint32_t *)off_1144EC + 52)) >= 0) )
      {
        *(volatile uint32_t *)off_1144F0 = 0x40000000;
        return result;
      }
      result = check_feature_flag(2, aOffsetNotAllow);
    }
  }
  *(volatile uint32_t *)off_1144F0 = 0x80000000;
  return result;
}


// scheduler_entry @ 0x1144fc
/* luna: Selects an RF setup path, writes the shifted input and mode-specific setup values, and returns the fixed status 236. */
int scheduler_entry(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  volatile uint8_t *v6; // r1
  volatile uint32_t *v8; // r1

  if ( *(volatile uint32_t *)off_11455C )
  {
    v8 = (void *)(uintptr_t)(off_114570);
    v1 = (volatile int *)dword_114574;
    *(volatile uint32_t *)off_114560 = dword_114574;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(volatile int **)off_114560;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114564 + 6) == 1 )
    *((volatile uint32_t *)off_114568 + 83) |= v4;
  v6 = (void *)(uintptr_t)(off_11456C);
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((volatile uint32_t *)v6 + 2) = v3;
  return 236;
}



// memory_barrier @ 0x114578
/* luna: Reads and writes back the value at the register address stored at 0x114584, likely to synchronize RF register access. */
void memory_barrier() {
  **(volatile uint32_t **)off_114584 = **(volatile uint32_t **)off_114584;
}



// rf_emit_setup_word @ 0x114588
/* luna: Clears bit 1 in the 32-bit word at offset 8 of the object referenced by the global pointer. */
void rf_emit_setup_word() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_114598 + 8) &= ~2u;
}



// set_state_flag @ 0x11459c
/* luna: Sets bit 1 in the RF context flags field at offset 8. */
void set_state_flag() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_1145AC + 8) |= 2u;
}



// check_initialized @ 0x1145b0
/* luna: Selects one of two RF mode values, conditionally clears the corresponding state bit, zeros a control register, and issues data and instruction barrier */
int check_initialized() {
  int v0; // r2
  int v1; // r1
  volatile uint32_t *v2; // r3

  if ( *(volatile uint32_t *)off_1145F8 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(volatile uint32_t *)off_1145F8 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_1145F4 + 6) == 1 )
    *((volatile uint32_t *)off_1145FC + 83) &= ~v1;
  v2 = (void *)(uintptr_t)(off_114604);
  *(volatile uint32_t *)(*(volatile uint32_t *)off_114600 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}



// timeout_handler @ 0x114608
/* luna: Logs interrupt and processor state, dumps a bounded stack trace, and records pending-interrupt and timer state during timeout handling. */
void timeout_handler() {
  unsigned int v0; // r5
  int v1; // r4
  int v2; // lr
  unsigned int CPSR; // r1
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r4
  unsigned int v8; // r5
  int v9; // r1

  v0 = off_1146C8;
  v1 = *(volatile uint32_t *)(*(volatile uint32_t *)off_1146C8 + 16);
  alloc_tx_event("\nINT:%x,%x,%x", v1, *(volatile uint32_t *)off_1146D0, *(volatile uint32_t *)off_1146CC);
  if ( (v1 & 1) != 0 )
    *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  alloc_tx_event(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    alloc_tx_event(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_1146F8 - v7) >> 2;
  alloc_tx_event(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  process_packet_params(v7, v9, 4, 0);
LABEL_5:
  alloc_tx_event(aIser);
  process_packet_params(dword_1146E0, 8, 4, 0);
  alloc_tx_event(aIspr);
  process_packet_params(dword_1146E8, 8, 4, 0);
  alloc_tx_event(aTim2);
  process_packet_params((int)&REG_4050_1000, 16, 4, 0);
  log_boot_message();
}


// call_patch_1fc_0 @ 0x114700
/* luna: Invokes the function pointer stored at MEMD(0x1FC) with no arguments and returns its result. */
int call_patch_1fc_0() {
  return ((int (*)())MEMD(0x1FC))();
}



// call_patch_1fc_check @ 0x114708
/* luna: Calls the routine at 0x1FC with argument 1 and returns bit 9 of its result. */
unsigned int call_patch_1fc_check() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(1) >> 9) & 1;
}



// call_patch_1fc_arg2 @ 0x11471c
/* luna: Calls the function pointer stored at address 0x1FC with argument 2 and returns its result. */
int call_patch_1fc_arg2() {
  return ((int (*)())MEMD(0x1FC))(2);
}



// rf_cmd_6_read @ 0x114728
/* luna: Calls the patch at 0x1FC with selector 6, stores the returned high byte when nonzero or otherwise the low byte, and returns a status based on the resu */
int rf_cmd_6_read(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = ((int (*)())MEMD(0x1FC))(6);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// rf_cmd_6_version @ 0x114754
/* luna: Queries RF command 6, writes byte 3 if nonzero or otherwise byte 2 (zero if both are zero), and returns 0, 1, or 2 to indicate which case applied. */
int rf_cmd_6_version(volatile uint8_t *a1) {
  unsigned int packed_response; // r0
  char version_byte; // r3

  packed_response = ((int (*)())MEMD(0x1FC))(6);
  if ( HIBYTE(packed_response) )
  {
    *a1 = HIBYTE(packed_response);
    return 0;
  }
  else
  {
    version_byte = BYTE2(packed_response);
    if ( !HIWORD(packed_response) )
      version_byte = 0;
    *a1 = version_byte;
    if ( HIWORD(packed_response) )
      return 1;
    else
      return 2;
  }
}



// rf_cmd_8_write @ 0x114784
/* luna: Reads RF command data through the patch dispatcher, packing the command-8/9 response halves or falling back to command-7/8 results. */
int rf_cmd_8_write(volatile uint32_t *a1, volatile unsigned int *a2) {
  unsigned int v4; // r4
  unsigned int v5; // r0
  unsigned int v6; // r4
  int v7; // r4
  uint16_t v8; // r0
  unsigned int v9; // r3
  int result; // r0

  v4 = ((int (*)())MEMD(0x1FC))(8);
  v5 = ((int (*)())MEMD(0x1FC))(9);
  v6 = HIWORD(v4) << 16;
  if ( v6 | v5 )
  {
    *a1 = (v5 << 16) | HIWORD(v6);
    *a2 = HIWORD(v5);
    return 0;
  }
  else
  {
    v7 = ((int (*)())MEMD(0x1FC))(7);
    v8 = ((int (*)())MEMD(0x1FC))(8);
    v9 = v8;
    if ( v7 )
    {
      *a1 = v7;
      *a2 = v8;
      return 1;
    }
    else
    {
      *a1 = 0;
      if ( v8 )
        result = 1;
      else
        result = 2;
      *a2 = v9;
    }
  }
  return result;
}



// packet_prepare_a @ 0x1147e0
/* luna: Decodes three signed-magnitude values from a selected RF packed-data source into the output buffer and returns per-value status nibbles. */
int packet_prepare_a(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  unsigned int v5; // r0
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r2
  char v9; // r5
  unsigned int v10; // r4
  char v11; // r2
  volatile uint8_t *v12; // r2
  uint32_t v14[3]; // [sp+4h] [bp-10h]

  v3 = *(volatile uint32_t *)(dword_114858 + 4);
  v4 = *(volatile uint32_t *)(dword_114858 + 8);
  v14[0] = *(volatile uint32_t *)dword_114858;
  v14[1] = v3;
  v14[2] = v4;
  v5 = ((int (*)())MEMD(0x1FC))(v14[a1]);
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = v5 >> (8 * v6);
    v9 = v8;
    v10 = (uint8_t)v8 >> 4;
    if ( (v8 & 0xF0) == 0 )
    {
      if ( !(uint8_t)v8 )
      {
        v7 |= 2 << (4 * v6);
        v12 = (volatile uint8_t *)(a2 + v6);
        goto LABEL_9;
      }
      v7 |= 1 << (4 * v6);
      v10 = (uint8_t)v8;
    }
    if ( (v10 & 1) != 0 )
      v11 = -1;
    else
      v11 = 1;
    v9 = (v10 >> 1) * v11;
    v12 = (volatile uint8_t *)(a2 + v6);
LABEL_9:
    ++v6;
    *v12 = v9;
  }
  while ( v6 != 3 );
  return v7;
}



// packet_prepare_b @ 0x11485c
/* luna: Reads six packed signed-magnitude nibble values from the selected RF data source, expands them to bytes, and returns per-value fallback flags. */
int packet_prepare_b(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  int v5; // r7
  unsigned int v6; // r4
  int v7; // r0
  int v8; // r2
  int result; // r0
  unsigned int v10; // r4
  int v11; // zf
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r5
  volatile uint8_t *v15; // r4
  struct __attribute__((packed)) { int v16; // [sp+4h] [bp-18h]
  int v17; // [sp+8h] [bp-14h]
  uint32_t v18[4]; // [sp+Ch] [bp-10h] BYREF
  } _frame;
  v3 = *(volatile uint32_t *)(dword_1148F8 + 4);
  v4 = *(volatile uint32_t *)(dword_1148F8 + 8);
  _frame.v18[0] = *(volatile uint32_t *)dword_1148F8;
  _frame.v18[1] = v3;
  _frame.v18[2] = v4;
  v5 = _frame.v18[a1];
  _frame.v16 = ((int (*)())MEMD(0x1FC))(v5);
  v6 = _frame.v16;
  v7 = ((int (*)())MEMD(0x1FC))(v5 + 1);
  v8 = 0;
  _frame.v17 = v7;
  result = 0;
  while ( 1 )
  {
    v12 = v6 >> (8 * (v8 & 3));
    v14 = (uint8_t)v12;
    v10 = (uint8_t)v12 >> 4;
    if ( (v12 & 0xF0) == 0 )
    {
      v12 = 1 << (4 * v8);
      if ( !v14 )
      {
        result |= 2 << (4 * v8);
        v15 = (volatile uint8_t *)(a2 + v8);
        goto LABEL_8;
      }
      result |= v12;
      v10 = v14;
    }
    v11 = (v10 & 1) == 0;
    if ( (v10 & 1) != 0 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(-1) & 0xFFu);
    v13 = v10 >> 1;
    if ( v11 )
      v12 = (v12 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
    v14 = (v14 & ~0xFFu) | ((uint8_t)(v13 * v12) & 0xFFu);
    v15 = (volatile uint8_t *)(a2 + v8);
LABEL_8:
    ++v8;
    *v15 = v14;
    if ( v8 == 6 )
      return result;
    v6 = *(volatile uint32_t *)((volatile char *)&_frame.v18[-2] + (v8 & 0xFFFFFFFC));
  }
}



// rf_cmd_a @ 0x1148fc
/* luna: Selects the high nibble when nonzero, otherwise the low nibble, decodes it as a signed-magnitude value, and returns 0, 1, or 2 for high-nibble, low-ni */
int rf_cmd_a(char a1, volatile uint8_t *a2) {
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)((int (*)())MEMD(0x1FC))(10) >> (8 * a1);
  v4 = (uint8_t)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (uint8_t)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}



// rf_cmd_b @ 0x114944
/* luna: Extracts byte `byte_index` from RF parameter 11, decodes its nonzero high nibble preferentially (otherwise the low nibble) as a signed-magnitude adjus */
int rf_cmd_b(char a1, volatile uint8_t *a2) {
  unsigned int v3; // r0
  unsigned int v4; // r3
  int result; // r0
  char v6; // r2

  v3 = (unsigned int)((int (*)())MEMD(0x1FC))(11) >> (8 * a1);
  v4 = (uint8_t)v3 >> 4;
  if ( (v3 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v3 )
    {
      *a2 = 0;
      return 2;
    }
    v4 = (uint8_t)v3;
    result = 1;
  }
  if ( (v4 & 1) != 0 )
    v6 = -1;
  else
    v6 = 1;
  *a2 = (v4 >> 1) * v6;
  return result;
}



// rf_cmd_10 @ 0x11498c
/* luna: Reads an RF value, decodes its selected nibble as a signed calibration adjustment into the output pointer, and returns a status for the encoding path  */
int rf_cmd_10(volatile int *a1) {
  uint8_t v2; // r0
  int v3; // r2
  int result; // r0
  int v5; // r3

  v2 = ((int (*)())MEMD(0x1FC))(16);
  v3 = v2 >> 4;
  if ( (v2 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !v2 )
    {
      *a1 = 0;
      return 2;
    }
    v3 = v2;
    result = 1;
  }
  if ( (v3 & 8) != 0 )
    v5 = v3 & 7;
  else
    v5 = -v3;
  if ( (v3 & 8) != 0 )
    ++v5;
  *a1 = v5;
  return result;
}



// rf_reg_0x11_bits_0_2 @ 0x1149c8
/* luna: Returns bits 0–2 of RF register 0x11 using a ROM API call. */
int rf_reg_0x11_bits_0_2() {
  return ((int (*)())MEMD(0x1FC))(17) & 7;
}



// rf_reg_0x11_bits_3_5 @ 0x1149dc
/* luna: Returns bits 3–5 of RF register 0x11, read through the ROM API. */
unsigned int rf_reg_0x11_bits_3_5() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 3) & 7;
}



// rf_reg_0x11_bits_6_8 @ 0x1149f0
/* luna: Returns bits 6–8 of RF register 0x11. */
unsigned int rf_reg_0x11_bits_6_8() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 6) & 7;
}



// invoke_rom_api @ 0x114a04
/* luna: Calls the ROM accessor for RF selector 0x0F, stores the high byte when nonzero or otherwise the low byte, and returns the corresponding status code. */
int invoke_rom_api(volatile uint8_t *a1) {
  int16_t v2; // r0

  v2 = ((int (*)())MEMD(0x1FC))(15);
  if ( (v2 & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(v2);
    return 0;
  }
  else
  {
    *a1 = v2;
    if ( (uint8_t)v2 )
      return 1;
    else
      return 2;
  }
}



// rf_reg_0x0f_bit_18 @ 0x114a30
/* luna: Returns bit 18 of RF register 0x0F. */
unsigned int rf_reg_0x0f_bit_18() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 18) & 1;
}



// rf_reg_0x0f_bit_19 @ 0x114a44
/* luna: Returns bit 19 of RF register 0x0F read through the ROM RF-register accessor. */
unsigned int rf_reg_0x0f_bit_19() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 19) & 1;
}



// rf_reg_0x0f_bit_20 @ 0x114a58
/* luna: Returns bit 20 of RF register 0x0F using the ROM register accessor. */
unsigned int rf_reg_0x0f_bit_20() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 20) & 1;
}



// rf_reg_0x1b @ 0x114a6c
/* luna: Returns the value read from RF register 0x1B through the global RF accessor. */
int rf_reg_0x1b() {
  return ((int (*)())MEMD(0x1FC))(27);
}



// undefined_instruction_handler @ 0x114a78
/* luna: Runs the configured no-argument hook with nested IRQ protection and restores interrupts when the outermost call exits if they were enabled on entry. */
int undefined_instruction_handler() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114AB0 = 1;
  }
  v0 = (volatile int *)off_114AB4;
  ++*(volatile uint32_t *)off_114AB4;
  result = ((int (*)())MEMD(0x1C8))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_114AB0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}



// get_global_context @ 0x114ab8
/* luna: Lazily initializes the RF context base and a derived address, then marks the context initialized. */
void get_global_context() {
  volatile int *v0; // r4

  v0 = (volatile int *)off_114AE4;
  if ( !*(volatile uint32_t *)off_114AE4 )
    *v0 = undefined_instruction_handler();
  if ( !*(volatile uint32_t *)off_114AE8 )
    *(volatile uint32_t *)off_114AE8 = *v0 + 67092480;
  *(volatile uint32_t *)off_114AEC = 1;
}



