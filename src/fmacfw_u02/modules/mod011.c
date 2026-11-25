// tx_txdesc_init @ 0x115f68
int tx_txdesc_init() {
  volatile int **v0; // r5
  volatile uint32_t *v1; // r6
  volatile int *v2; // r0
  void *v3; // r8
  int v4; // r7
  uint16_t v5; // r9
  volatile int *v6; // r1
  int result; // r0

  v0 = (volatile int **)off_115FF0;
  zero_8_bytes((volatile uint32_t *)dword_115FEC);
  if ( **(volatile int16_t **)off_115FF4 < 0 )
  {
    v2 = *v0;
    v1 = (void *)(uintptr_t)(off_115FF8);
    if ( !*v0 || !*(volatile uint32_t *)off_115FF8 )
    {
      mmio_clear_register((int)aTxdescArray0Tx, (int)aTxTxdescInit, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = (void *)(uintptr_t)(off_115FF8);
    v2 = *v0;
  }
  v3 = (void *)(uintptr_t)(off_116004);
  v4 = dword_115FEC;
  memset(v2, 0, 88 * *(volatile uint16_t *)(*(volatile uint32_t *)off_116004 + 8) + 88);
  v5 = 0;
  do
  {
    v6 = &(*v0)[22 * v5];
    v6[19] = *v1 + 80 * v5;
    result = co_list_push_back(v4, (void *)(v6));
    ++v5;
  }
  while ( *(volatile uint16_t *)(*(volatile uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}


// kernel_event_get @ 0x116008
int kernel_event_get() {
  int v0; // r0
  int v1; // r4

  v0 = (int)(uintptr_t)(mem_word_load(dword_116034));
  v1 = v0;
  if ( **(volatile int16_t **)off_116038 < 0 && !v0 )
    mmio_clear_register(dword_116040, dword_11603C, 119);
  return v1;
}



// call_func_182588 @ 0x116044
int call_func_182588(volatile uint32_t *a1) {
  return co_list_push_back(dword_11604C, a1);
}


// init_event_slot @ 0x116050
int init_event_slot(int a1) {
  int v1; // r1
  int v2; // r3
  int result; // r0

  v1 = dword_116088;
  v2 = dword_116088 + 36 * a1;
  *(volatile uint32_t *)v2 = 0;
  result = v1 + 8 * (a1 + 22);
  *(volatile uint32_t *)(v2 + 8) = 4978;
  *(volatile uint32_t *)(v2 + 12) = -1;
  *(volatile uint32_t *)(result + 4) = 0;
  *(volatile uint32_t *)(result + 8) = 0;
  *(volatile uint32_t *)(v2 + 4) = 0;
  *(volatile uint8_t *)(v2 + 32) = 0;
  *(volatile uint32_t *)(v2 + 20) = 0;
  *(volatile uint32_t *)(v2 + 16) = -1;
  return result;
}



// call_delayed_callback @ 0x11608c
volatile uint32_t * call_delayed_callback(int a1) {
  volatile uint32_t *result; // r0

  result = *(volatile uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (volatile uint32_t *)is_controller_mode(result);
    *(volatile uint32_t *)(a1 + 72) = 0;
  }
  return result;
}



// set_table_callback_data @ 0x1160a0
/* luna: Appends a callback node to the list selected by `index + 22` and clears the node’s next link. */
int set_table_callback_data(int a1, int a2) {
  int table_base; // r3
  int result; // r0
  int v4; // r2

  table_base = dword_1160C4;
  result = a1 + 22;
  v4 = dword_1160C4 + 8 * result;
  if ( *(volatile uint32_t *)(v4 + 4) )
    v4 = *(volatile uint32_t *)(v4 + 8);
  *(volatile uint32_t *)(v4 + 4) = a2;
  *(volatile uint32_t *)(table_base + 8 * result + 8) = a2;
  *(volatile uint32_t *)(a2 + 4) = 0;
  return result;
}



// parse_control_packet @ 0x1160c8
int parse_control_packet(int result, int a2) {
  int v2; // r3
  int v3; // r8
  int v4; // r12
  volatile uint32_t *v5; // r7
  int v6; // lr
  int v7; // r6
  int v8; // r4
  int v9; // r2
  int v10; // r6
  int v11; // r2
  int v12; // r1

  v2 = *(volatile uint32_t *)(result + 72);
  v3 = *(volatile uint8_t *)(result + 50);
  v4 = *(volatile uint32_t *)(v2 + 40);
  v5 = *(volatile uint32_t **)(result + 76);
  v6 = *(volatile uint8_t *)(v2 + 36);
  v7 = v2 - *(volatile uint8_t *)(result + 66) + 172;
  v8 = v3 + v2 + 172 - *(volatile uint8_t *)(result + 51);
  v9 = *(volatile uint8_t *)(result + 53) + *(volatile uint16_t *)(result + 4) - 1 + v2 + 172;
  *(volatile uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFD;
  if ( v3 )
  {
    v5[7] = v7;
    v5[8] = v3 + v7 - 1;
  }
  v10 = v5[17];
  *(volatile uint32_t *)(v2 + 24) = v8;
  *(volatile uint32_t *)(v2 + 28) = v9;
  *(volatile uint32_t *)(v2 + 20) = 0;
  v5[6] = v2 + 16;
  *(volatile uint32_t *)(v2 + 32) = 0;
  v5[17] = v10 | 0x100;
  if ( (v4 & 1) == 0 )
  {
    v11 = *(volatile uint32_t *)(result + 36);
    result = v11 & 0x380000;
    if ( (v11 & 0x380000) == 0x380000 || (v11 & 0x200000) == 0 )
    {
      v12 = dword_116170 + 36 * (a2 + v6);
      result = *(volatile uint8_t *)(v12 + 32);
      *(volatile uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFC | 1;
      *(volatile uint8_t *)(v12 + 32) = result + 1;
      v5[17] = v10 | 0x100;
    }
  }
  *(volatile uint32_t *)(v2 + 20) = 0;
  return result;
}



// append_tkip_mic @ 0x116174
volatile int * append_tkip_mic(int a1, int a2, int a3, int a4) {
  volatile int *result; // r0
  volatile char *v7; // r4
  int v8; // r5
  char v9; // t1
  struct __attribute__((packed)) { uint8_t v10[8]; // [sp+8h] [bp-14h] BYREF
  char v11; // [sp+10h] [bp-Ch] BYREF
  } _frame;
  if ( (**(volatile uint8_t **)off_1161D0 & 1) != 0 )
    return memset((volatile int *)(a3 + a4), 0, 8u);
  v7 = _frame.v10;
  crypto_load_args((int)(uintptr_t)(_frame.v10), (void *)(uintptr_t)(a2), a1 + 12, (void *)(uintptr_t)(a1 + 18), *(volatile uint8_t *)(a1 + 27));
  unaligned_read((void *)(_frame.v10), a3, a4);
  patch_handle_data((int)(uintptr_t)(_frame.v10));
  v8 = a4 + a3;
  do
  {
    result = (volatile int *)((uintptr_t)(v7) - (uintptr_t)(_frame.v10));
    v9 = *v7++;
    *((volatile uint8_t *)result + v8) = v9;
  }
  while ( v7 != &_frame.v11 );
  return result;
}



// configure_hardware_regs @ 0x1161d4
int configure_hardware_regs() {
  volatile int *v0; // r4
  int v1; // r8
  int v2; // r7
  volatile uint16_t *v3; // r5
  int v4; // r6
  int v5; // r0
  int v6; // r3
  volatile int *v7; // r4
  int v8; // r7
  int v9; // r6
  volatile int *v10; // r8
  int v11; // r5
  int result; // r0
  int v13; // r2
  int v14; // r1

  v0 = (volatile int *)dword_1162A8;
  v1 = dword_1162B8;
  v2 = dword_1162AC;
  v3 = (void *)(uintptr_t)(off_1162B0);
  v4 = dword_1162A8 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = rf_get_field4() << 14;
    v5 = get_hw_clock_multiplier();
    v0[3] = 0;
    v0[4] = v2;
    v0[5] = 0;
    v0[6] = 0;
    v0[7] = 0;
    v0[8] = 0;
    v0[2] = v5;
    v0[9] = (uint16_t)(*v3 << 8) | (uint8_t)*(volatile uint32_t *)v3;
    v0[10] = (uint16_t)(*v3 << 8) | (uint8_t)*(volatile uint32_t *)v3;
    v0[11] = (uint16_t)(*v3 << 8) | (uint8_t)*(volatile uint32_t *)v3;
    v6 = (uint16_t)(*v3 << 8) | (uint8_t)*(volatile uint32_t *)v3;
    v0[14] = 4128768;
    v0[12] = v6;
    v0[13] = 8704;
    v0 += 16;
  }
  while ( v0 != (volatile int *)v4 );
  v7 = (volatile int *)dword_1162B4;
  v8 = dword_1162B8;
  v9 = dword_1162AC;
  v10 = (volatile int *)off_1162B0;
  v11 = dword_1162B4 + 256;
  do
  {
    *v7 = v8;
    v7[1] = rf_get_field4() << 14;
    result = get_hw_clock_multiplier();
    v7[3] = 0;
    v7[4] = v9;
    v7[5] = 0;
    v7[6] = 0;
    v7[7] = 0;
    v7[8] = 0;
    v7[2] = result;
    v13 = *v10;
    v14 = *v10;
    v7[10] = 0;
    v7[9] = (uint16_t)((uint16_t)v13 << 8) | (uint8_t)v14;
    v7[11] = 0;
    v7[12] = 0;
    v7[13] = 0;
    v7[14] = 4128768;
    v7 += 16;
  }
  while ( v7 != (volatile int *)v11 );
  return result;
}



// dispatch_config_command @ 0x1162bc
int dispatch_config_command(int result) {
  switch ( result )
  {
    case 0:
      *(volatile uint32_t *)off_116314 = 2;
      break;
    case 1:
      *(volatile uint32_t *)off_116314 = 4;
      break;
    case 2:
      *(volatile uint32_t *)off_116314 = 8;
      break;
    case 3:
      *(volatile uint32_t *)off_116314 = 16;
      break;
    case 4:
      *(volatile uint32_t *)off_116314 = 1;
      break;
    case 5:
      *(volatile uint32_t *)off_116314 = 32;
      break;
    default:
      if ( **(volatile int16_t **)off_116318 < 0 )
        result = mmio_clear_register(dword_116320, dword_11631C, 944);
      break;
  }
  return result;
}



