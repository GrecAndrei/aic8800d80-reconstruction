// scan_process_advertisement @ 0x1163a8
/* luna: Initializes the transmit descriptor array and assigns each descriptor its corresponding transmit-buffer address. */
int scan_process_advertisement() {
  volatile int **tx_desc_array_ref; // r5
  volatile uint32_t *tx_buffer_base_ref; // r6
  volatile int *tx_desc_array; // r0
  void *tx_desc_config; // r8
  int v4; // r7
  uint16_t desc_index; // r9
  volatile int *tx_desc_entry; // r1
  int result; // r0

  tx_desc_array_ref = (volatile int **)off_116430;
  zero_struct((volatile uint32_t *)dword_11642C);
  if ( **(volatile int16_t **)off_116434 < 0 )
  {
    tx_desc_array = *tx_desc_array_ref;
    tx_buffer_base_ref = (void *)(uintptr_t)(off_116438);
    if ( !*tx_desc_array_ref || !*(volatile uint32_t *)off_116438 )
    {
      mmio_irq_clear((int)aTxdescArray0Tx, (int)aTxTxdescInit, 90);
      tx_desc_array = *tx_desc_array_ref;
    }
  }
  else
  {
    tx_buffer_base_ref = (void *)(uintptr_t)(off_116438);
    tx_desc_array = *tx_desc_array_ref;
  }
  tx_desc_config = (void *)(uintptr_t)(off_116444);
  v4 = dword_11642C;
  memset(tx_desc_array, 0, 88 * *(volatile uint16_t *)(*(volatile uint32_t *)off_116444 + 8) + 88);
  desc_index = 0;
  do
  {
    tx_desc_entry = &(*tx_desc_array_ref)[22 * desc_index];
    tx_desc_entry[19] = *tx_buffer_base_ref + 80 * desc_index;
    result = check_abort_flag(v4, (void *)(tx_desc_entry));
    ++desc_index;
  }
  while ( *(volatile uint16_t *)(*(volatile uint32_t *)tx_desc_config + 8) >= (unsigned int)desc_index );
  return result;
}


// scan_check_response @ 0x116448
int scan_check_response() {
  int v0; // r0
  int v1; // r4

  v0 = (int)(uintptr_t)(list_pop_front(dword_116474));
  v1 = v0;
  if ( **(volatile int16_t **)off_116478 < 0 && !v0 )
    mmio_irq_clear(dword_116480, dword_11647C, 119);
  return v1;
}



// send_to_global_queue @ 0x116484
int send_to_global_queue(volatile uint32_t *a1) {
  return check_abort_flag(dword_11648C, a1);
}


// bt_clear_entry @ 0x116490
int bt_clear_entry(int a1) {
  int v1; // r1
  int v2; // r3
  int result; // r0

  v1 = dword_1164C8;
  v2 = dword_1164C8 + 36 * a1;
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



// release_buffer @ 0x1164cc
volatile uint32_t * release_buffer(int a1) {
  volatile uint32_t *result; // r0

  result = *(volatile uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (volatile uint32_t *)memory_pool_free(result);
    *(volatile uint32_t *)(a1 + 72) = 0;
  }
  return result;
}



// set_callback_arg @ 0x1164e0
int set_callback_arg(int a1, int a2) {
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_116504;
  result = a1 + 22;
  v4 = dword_116504 + 8 * result;
  if ( *(volatile uint32_t *)(v4 + 4) )
    v4 = *(volatile uint32_t *)(v4 + 8);
  *(volatile uint32_t *)(v4 + 4) = a2;
  *(volatile uint32_t *)(v2 + 8 * result + 8) = a2;
  *(volatile uint32_t *)(a2 + 4) = 0;
  return result;
}



// build_tx_packet @ 0x116508
int build_tx_packet(int result, int a2) {
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
      v12 = dword_1165B0 + 36 * (a2 + v6);
      result = *(volatile uint8_t *)(v12 + 32);
      *(volatile uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFC | 1;
      *(volatile uint8_t *)(v12 + 32) = result + 1;
      v5[17] = v10 | 0x100;
    }
  }
  *(volatile uint32_t *)(v2 + 20) = 0;
  return result;
}



// check_radio_flag_2 @ 0x1165b4
volatile int * check_radio_flag_2(int a1, int a2, int a3, int a4) {
  volatile int *result; // r0
  volatile char *v7; // r4
  int v8; // r5
  char v9; // t1
  struct __attribute__((packed)) { uint8_t v10[8]; // [sp+8h] [bp-14h] BYREF
  char v11; // [sp+10h] [bp-Ch] BYREF
  } _frame;
  if ( (**(volatile uint8_t **)off_116610 & 1) != 0 )
    return memset((volatile int *)(a3 + a4), 0, 8u);
  v7 = _frame.v10;
  assemble_bt_descriptor((int)(uintptr_t)(_frame.v10), (void *)(uintptr_t)(a2), a1 + 12, (void *)(uintptr_t)(a1 + 18), *(volatile uint8_t *)(a1 + 27));
  unaligned_memcpy((void *)(_frame.v10), a3, a4);
  bt_process_rx_data((int)(uintptr_t)(_frame.v10));
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



// hw_init_magic @ 0x116614
int hw_init_magic() {
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

  v0 = (volatile int *)dword_1166E8;
  v1 = dword_1166F8;
  v2 = dword_1166EC;
  v3 = (void *)(uintptr_t)(off_1166F0);
  v4 = dword_1166E8 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = irq47_status_handler() << 14;
    v5 = get_hw_flash_size();
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
  v7 = (volatile int *)dword_1166F4;
  v8 = dword_1166F8;
  v9 = dword_1166EC;
  v10 = (volatile int *)off_1166F0;
  v11 = dword_1166F4 + 256;
  do
  {
    *v7 = v8;
    v7[1] = irq47_status_handler() << 14;
    result = get_hw_flash_size();
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



// switch_rf_path @ 0x1166fc
int switch_rf_path(int result) {
  switch ( result )
  {
    case 0:
      *(volatile uint32_t *)off_116754 = 2;
      break;
    case 1:
      *(volatile uint32_t *)off_116754 = 4;
      break;
    case 2:
      *(volatile uint32_t *)off_116754 = 8;
      break;
    case 3:
      *(volatile uint32_t *)off_116754 = 16;
      break;
    case 4:
      *(volatile uint32_t *)off_116754 = 1;
      break;
    case 5:
      *(volatile uint32_t *)off_116754 = 32;
      break;
    default:
      if ( **(volatile int16_t **)off_116758 < 0 )
        result = mmio_irq_clear(dword_116760, dword_11675C, 944);
      break;
  }
  return result;
}



