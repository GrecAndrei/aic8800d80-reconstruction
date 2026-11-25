// process_global_167204 @ 0x114574
int process_global_167204() {
  int result; // r0
  volatile uint8_t *v1; // r3
  volatile uint32_t *v2; // r1

  result = event_dispatch(aErrorLpLevelPo_0);
  v1 = (void *)(uintptr_t)(off_1145A0);
  if ( *((volatile uint8_t *)off_1145A0 + 3) )
  {
    v2 = (void *)(uintptr_t)(off_1145A8);
    *(volatile uint32_t *)off_1145A4 &= ~8u;
    *v2 &= 0xFFFFFFF0;
    v1[3] = 0;
    return 0;
  }
  return result;
}


// sub_1145ac @ 0x1145ac
unsigned int sub_1145ac(unsigned int result) {
  int v1; // r2

  if ( !result )
  {
    v1 = *(volatile uint32_t *)off_11461C;
    if ( *(volatile uint32_t *)off_11461C
      && (result = (*(volatile uint32_t *)0x40501010u), (int)(*(volatile uint32_t *)(v1 + 12) - result - LOWORD(((volatile uint32_t *)(uintptr_t)off_114624)[46]) - 2000) < 0) )
    {
      result = check_status_bits(2, "timer: not allow %x\r\n", *(volatile uint32_t *)(v1 + 4));
    }
    else
    {
      if ( !*(volatile uint8_t *)off_114628
        || (result = (*(volatile uint32_t *)0x40501010u),
            (int)(*((volatile uint32_t *)off_114628 + 1)
                + *((volatile uint32_t *)off_114628 + 2)
                - result
                - LOWORD(((volatile uint32_t *)(uintptr_t)off_114624)[46])
                - *(volatile uint16_t *)(*(volatile uint32_t *)off_11462C + 52)) >= 0) )
      {
        *(volatile uint32_t *)off_114630 = 0x40000000;
        return result;
      }
      result = check_status_bits(2, aOffsetNotAllow);
    }
  }
  *(volatile uint32_t *)off_114630 = 0x80000000;
  return result;
}


// load_global_ptr_182558 @ 0x11463c
int load_global_ptr_182558(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r4
  int v4; // r1
  int v5; // r0
  volatile uint8_t *v6; // r1
  volatile uint32_t *v8; // r1

  if ( *(volatile uint32_t *)off_11469C )
  {
    v8 = (void *)(uintptr_t)(off_1146B0);
    v1 = (volatile int *)dword_1146B4;
    *(volatile uint32_t *)off_1146A0 = dword_1146B4;
    v8[19] = 1;
    v3 = 2048;
    v4 = 1;
    v2 = 75;
  }
  else
  {
    v1 = *(volatile int **)off_1146A0;
    v2 = 76;
    v3 = 4096;
    v4 = 2;
  }
  v5 = a1 << 15;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_1146A4 + 6) == 1 )
    *((volatile uint32_t *)off_1146A8 + 83) |= v4;
  v6 = (void *)(uintptr_t)(off_1146AC);
  *v1 = v5;
  v1[3] = 1;
  v1[2] = 3;
  v6[v2 + 768] = -20;
  *((volatile uint32_t *)v6 + 2) = v3;
  return 236;
}



// dummy_store_global @ 0x1146b8
/* luna: Reads the 32-bit word referenced by a global pointer and writes the unchanged value back to the same location. */
void dummy_store_global() {
  **(volatile uint32_t **)off_1146C4 = **(volatile uint32_t **)off_1146C4;
}



// clear_global_flag_2 @ 0x1146c8
void clear_global_flag_2() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_1146D8 + 8) &= ~2u;
}



// set_global_flag_2 @ 0x1146dc
void set_global_flag_2() {
  *(volatile uint32_t *)(*(volatile uint32_t *)off_1146EC + 8) |= 2u;
}



// check_bt_ptr_state @ 0x1146f0
int check_bt_ptr_state() {
  int v0; // r2
  int v1; // r1
  volatile uint32_t *v2; // r3

  if ( *(volatile uint32_t *)off_114738 )
    v0 = 2048;
  else
    v0 = 4096;
  if ( *(volatile uint32_t *)off_114738 )
    v1 = 1;
  else
    v1 = 2;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_114734 + 6) == 1 )
    *((volatile uint32_t *)off_11473C + 83) &= ~v1;
  v2 = (void *)(uintptr_t)(off_114744);
  *(volatile uint32_t *)(*(volatile uint32_t *)off_114740 + 8) = 0;
  v2[34] = v0;
  __dsb(0xFu);
  __isb(0xFu);
  return 0;
}



// load_multiple_globals @ 0x114748
void load_multiple_globals() {
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

  v0 = off_114808;
  v1 = *(volatile uint32_t *)(*(volatile uint32_t *)off_114808 + 16);
  event_dispatch("\nINT:%x,%x,%x", v1, *(volatile uint32_t *)off_114810, *(volatile uint32_t *)off_11480C);
  if ( (v1 & 1) != 0 )
    *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 12) = 1;
  CPSR = __get_CPSR();
  v4 = __get_CPSR();
  v5 = __get_CPSR();
  v6 = __get_CPSR();
  event_dispatch(aControl08xXpsr_0, CPSR, v4, v5, v6, __get_CPSR(), v2);
  if ( v5 )
  {
    event_dispatch(aWrongPsp);
    if ( !v6 )
      goto LABEL_5;
  }
  else if ( !v6 )
  {
    goto LABEL_5;
  }
  v7 = v6 & 0xFFFFFFF0;
  v8 = (dword_114838 - v7) >> 2;
  event_dispatch(aDumpmsp_0);
  v9 = v8;
  if ( v8 >= 0x100 )
    v9 = 256;
  send_msg(v7, v9, 4, 0);
LABEL_5:
  event_dispatch(aIser);
  send_msg(dword_114820, 8, 4, 0);
  event_dispatch(aIspr);
  send_msg(dword_114828, 8, 4, 0);
  event_dispatch(aTim2);
  send_msg((int)REG_4050_1000, 16, 4, 0);
  patch_init();
}


// call_hook_1 @ 0x114840
/* luna: Invokes the function pointer stored at address 0x1FC and returns its result. */
int call_hook_1() {
  return ((int (*)())MEMD(0x1FC))();
}



// get_hook_bit_9 @ 0x114848
/* luna: Calls the installed hook with selector 1 and returns bit 9 of its result. */
unsigned int get_hook_bit_9() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(1) >> 9) & 1;
}



// call_hook_2 @ 0x11485c
/* luna: Calls the function pointer stored at 0x1FC with argument 2 and returns its result. */
int call_hook_2() {
  return ((int (*)())MEMD(0x1FC))(2);
}



// rf_cmd6_read @ 0x114868
/* luna: Calls the command-6 hook, writes its high byte when nonzero or otherwise its low byte, and returns 0, 1, or 2 according to the result. */
int rf_cmd6_read(volatile uint8_t *a1) {
  int16_t hook_result; // r0

  hook_result = ((int (*)())MEMD(0x1FC))(6);
  if ( (hook_result & 0xFF00) != 0 )
  {
    *a1 = HIBYTE(hook_result);
    return 0;
  }
  else
  {
    *a1 = hook_result;
    if ( (uint8_t)hook_result )
      return 1;
    else
      return 2;
  }
}



// rf_cmd6_read_hi @ 0x114894
/* luna: Reads RF command 6, stores its highest nonzero response byte (or zero), and returns 0, 1, or 2 depending on which of the top two bytes was present. */
int rf_cmd6_read_hi(volatile uint8_t *a1) {
  unsigned int response; // r0
  char selected_byte; // r3

  response = ((int (*)())MEMD(0x1FC))(6);
  if ( HIBYTE(response) )
  {
    *a1 = HIBYTE(response);
    return 0;
  }
  else
  {
    selected_byte = BYTE2(response);
    if ( !HIWORD(response) )
      selected_byte = 0;
    *a1 = selected_byte;
    if ( HIWORD(response) )
      return 1;
    else
      return 2;
  }
}



// rf_cmd8_read @ 0x1148c4
int rf_cmd8_read(volatile uint32_t *a1, volatile unsigned int *a2) {
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



// copy_global_1672ec @ 0x114920
/* luna: Executes the selected RF command, decodes its three signed-magnitude nibble values into the output buffer, and returns packed per-value status flags. */
int copy_global_1672ec(int a1, int a2) {
  int v3; // r1
  int v4; // r2
  unsigned int response_word; // r0
  int result_index; // r3
  int status_flags; // r1
  unsigned int response_field; // r2
  char decoded_value; // r5
  unsigned int encoded_value_nibble; // r4
  char sign_factor; // r2
  volatile uint8_t *v12; // r2
  uint32_t rf_command_words[3]; // [sp+4h] [bp-10h]

  v3 = *(volatile uint32_t *)(dword_114998 + 4);
  v4 = *(volatile uint32_t *)(dword_114998 + 8);
  rf_command_words[0] = *(volatile uint32_t *)dword_114998;
  rf_command_words[1] = v3;
  rf_command_words[2] = v4;
  response_word = ((int (*)())MEMD(0x1FC))(rf_command_words[a1]);
  result_index = 0;
  status_flags = 0;
  do
  {
    response_field = response_word >> (8 * result_index);
    decoded_value = response_field;
    encoded_value_nibble = (uint8_t)response_field >> 4;
    if ( (response_field & 0xF0) == 0 )
    {
      if ( !(uint8_t)response_field )
      {
        status_flags |= 2 << (4 * result_index);
        v12 = (volatile uint8_t *)(a2 + result_index);
        goto LABEL_9;
      }
      status_flags |= 1 << (4 * result_index);
      encoded_value_nibble = (uint8_t)response_field;
    }
    if ( (encoded_value_nibble & 1) != 0 )
      sign_factor = -1;
    else
      sign_factor = 1;
    decoded_value = (encoded_value_nibble >> 1) * sign_factor;
    v12 = (volatile uint8_t *)(a2 + result_index);
LABEL_9:
    ++result_index;
    *v12 = decoded_value;
  }
  while ( result_index != 3 );
  return status_flags;
}



// copy_global_1672f8 @ 0x11499c
int copy_global_1672f8(int a1, int a2) {
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
  v3 = ((volatile uint32_t *)(uintptr_t)off_114A38)[1];
  v4 = ((volatile uint32_t *)(uintptr_t)off_114A38)[2];
  _frame.v18[0] = ((volatile uint32_t *)(uintptr_t)off_114A38)[0];
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


// rf_cmd_a_write @ 0x114a3c
int rf_cmd_a_write(char a1, volatile uint8_t *a2) {
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



// rf_cmd_b_write @ 0x114a84
int rf_cmd_b_write(char a1, volatile uint8_t *a2) {
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



// rom_get_chip_version @ 0x114acc
int rom_get_chip_version(volatile int *a1) {
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



// get_hook_bits_0_2 @ 0x114b08
/* luna: Returns bits 0–2 of the hook value queried with selector 17. */
int get_hook_bits_0_2() {
  return ((int (*)())MEMD(0x1FC))(17) & 7;
}



// get_hook_bits_3_5 @ 0x114b1c
/* luna: Returns bits 3–5 of the hook value obtained by calling the ROM service with argument 17. */
unsigned int get_hook_bits_3_5() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 3) & 7;
}



// get_hook_bits_6_8 @ 0x114b30
/* luna: Returns bits 6–8 of the hook value obtained by calling the ROM accessor with selector 17. */
unsigned int get_hook_bits_6_8() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(17) >> 6) & 7;
}



// rom_get_chip_metal @ 0x114b44
int rom_get_chip_metal(volatile uint8_t *a1) {
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



// get_hook_bit_18 @ 0x114b70
/* luna: Returns bit 18 of the hook value queried with index 15. */
unsigned int get_hook_bit_18() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 18) & 1;
}



// get_hook_bit_19 @ 0x114b84
/* luna: Returns bit 19 of the value returned by the hook provider when called with selector 15. */
unsigned int get_hook_bit_19() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 19) & 1;
}



// get_hook_bit_20 @ 0x114b98
/* luna: Returns bit 20 of the value obtained by querying the hook provider with selector 15. */
unsigned int get_hook_bit_20() {
  return ((unsigned int)((int (*)())MEMD(0x1FC))(15) >> 20) & 1;
}



// call_hook_27 @ 0x114bac
/* luna: Calls the hook function stored at address 0x1FC with hook index 27 and returns its result. */
int call_hook_27() {
  return ((int (*)())MEMD(0x1FC))(27);
}



// invalid_handler @ 0x114bb8
int invalid_handler() {
  volatile int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_114BF0 = 1;
  }
  v0 = (volatile int *)off_114BF4;
  ++*(volatile uint32_t *)off_114BF4;
  result = ((int (*)())MEMD(0x1C8))();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(volatile uint32_t *)off_114BF0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}


// get_ke_env @ 0x114bf8
void get_ke_env() {
  volatile int *v0; // r4

  v0 = (volatile int *)off_114C24;
  if ( !*(volatile uint32_t *)off_114C24 )
    *v0 = invalid_handler();
  if ( !*(volatile uint32_t *)off_114C28 )
    *(volatile uint32_t *)off_114C28 = *v0 + 67092480;
  *(volatile uint32_t *)off_114C2C = 1;
}



