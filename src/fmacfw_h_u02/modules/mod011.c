// txdesc_pool_init @ 0x115e28
int txdesc_pool_init() {
  volatile int **v0; // r5
  volatile uint32_t *v1; // r6
  volatile int *v2; // r0
  void *v3; // r8
  int v4; // r7
  uint16_t v5; // r9
  volatile int *v6; // r1
  int result; // r0

  v0 = (volatile int **)off_115EB0;
  clear_stats_buf((volatile uint32_t *)dword_115EAC);
  if ( **(volatile int16_t **)off_115EB4 < 0 )
  {
    v2 = *v0;
    v1 = (void *)(uintptr_t)(off_115EB8);
    if ( !*v0 || !*(volatile uint32_t *)off_115EB8 )
    {
      irq_disable_mmio_write((int)aTxdescArray0Tx, (int)aTxTxdescInit, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = (void *)(uintptr_t)(off_115EB8);
    v2 = *v0;
  }
  v3 = (void *)(uintptr_t)(off_115EC4);
  v4 = dword_115EAC;
  memset(v2, 0, 88 * *(volatile uint16_t *)(*(volatile uint32_t *)off_115EC4 + 8) + 88);
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


// rssi_compare @ 0x115ec8
int rssi_compare() {
  int v0; // r0
  int v1; // r4

  v0 = (int)(uintptr_t)(list_pop(dword_115EF4));
  v1 = v0;
  if ( **(volatile int16_t **)off_115EF8 < 0 && !v0 )
    irq_disable_mmio_write(dword_115F00, dword_115EFC, 119);
  return v1;
}



// set_string_0x182588 @ 0x115f04
int set_string_0x182588(volatile uint32_t *a1) {
  return co_list_push_back(dword_115F0C, a1);
}


// ll_event_clear @ 0x115f10
/* luna: Resets the indexed Bluetooth link-layer event entry and clears its associated auxiliary state. */
int ll_event_clear(int a1) {
  int event_storage_base; // r1
  int event_record; // r3
  int result; // r0

  event_storage_base = dword_115F48;
  event_record = dword_115F48 + 36 * a1;
  *(volatile uint32_t *)event_record = 0;
  result = event_storage_base + 8 * (a1 + 22);
  *(volatile uint32_t *)(event_record + 8) = 4978;
  *(volatile uint32_t *)(event_record + 12) = -1;
  *(volatile uint32_t *)(result + 4) = 0;
  *(volatile uint32_t *)(result + 8) = 0;
  *(volatile uint32_t *)(event_record + 4) = 0;
  *(volatile uint8_t *)(event_record + 32) = 0;
  *(volatile uint32_t *)(event_record + 20) = 0;
  *(volatile uint32_t *)(event_record + 16) = -1;
  return result;
}



// conn_handle_get @ 0x115f4c
volatile uint32_t * conn_handle_get(int a1) {
  volatile uint32_t *result; // r0

  result = *(volatile uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (volatile uint32_t *)pkt_mem_free(result);
    *(volatile uint32_t *)(a1 + 72) = 0;
  }
  return result;
}



// ll_event_lookup @ 0x115f60
/* luna: Appends an event node to the FIFO for queue index `a1`, clears its next link, and returns the internal queue slot (`a1 + 22`). */
int ll_event_lookup(int a1, int a2) {
  int event_queue_table; // r3
  int result; // r0
  int insertion_target; // r2

  event_queue_table = dword_115F84;
  result = a1 + 22;
  insertion_target = dword_115F84 + 8 * result;
  if ( *(volatile uint32_t *)(insertion_target + 4) )
    insertion_target = *(volatile uint32_t *)(insertion_target + 8);
  *(volatile uint32_t *)(insertion_target + 4) = a2;
  *(volatile uint32_t *)(event_queue_table + 8 * result + 8) = a2;
  *(volatile uint32_t *)(a2 + 4) = 0;
  return result;
}



// rx_packet_process_1 @ 0x115f88
int rx_packet_process_1(int result, int a2) {
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
      v12 = dword_116030 + 36 * (a2 + v6);
      result = *(volatile uint8_t *)(v12 + 32);
      *(volatile uint32_t *)(v2 + 40) = v4 & 0xFFFFFFFC | 1;
      *(volatile uint8_t *)(v12 + 32) = result + 1;
      v5[17] = v10 | 0x100;
    }
  }
  *(volatile uint32_t *)(v2 + 20) = 0;
  return result;
}



// rf_channel_select @ 0x116034
volatile int * rf_channel_select(int a1, int a2, int a3, int a4) {
  volatile int *result; // r0
  volatile char *v7; // r4
  int v8; // r5
  char v9; // t1
  struct __attribute__((packed)) { uint8_t v10[8]; // [sp+8h] [bp-14h] BYREF
  char v11; // [sp+10h] [bp-Ch] BYREF
  } _frame;
  if ( (**(volatile uint8_t **)off_116090 & 1) != 0 )
    return memset((volatile int *)(a3 + a4), 0, 8u);
  v7 = _frame.v10;
  bt_packet_parse((int)(uintptr_t)(_frame.v10), (void *)(uintptr_t)(a2), a1 + 12, (void *)(uintptr_t)(a1 + 18), *(volatile uint8_t *)(a1 + 27));
  unaligned_word_load((void *)(_frame.v10), a3, a4);
  ble_state_check_13362c((int)(uintptr_t)(_frame.v10));
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



// patch_enable @ 0x116094
int patch_enable() {
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

  v0 = (volatile int *)dword_116168;
  v1 = dword_116178;
  v2 = dword_11616C;
  v3 = (void *)(uintptr_t)(off_116170);
  v4 = dword_116168 + 2048;
  do
  {
    *v0 = v1;
    v0[1] = get_rf_field_mid() << 14;
    v5 = get_clock_prescaler();
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
  v7 = (volatile int *)dword_116174;
  v8 = dword_116178;
  v9 = dword_11616C;
  v10 = (volatile int *)off_116170;
  v11 = dword_116174 + 256;
  do
  {
    *v7 = v8;
    v7[1] = get_rf_field_mid() << 14;
    result = get_clock_prescaler();
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



// adv_type_valid @ 0x11617c
int adv_type_valid(int result) {
  switch ( result )
  {
    case 0:
      *(volatile uint32_t *)off_1161D4 = 2;
      break;
    case 1:
      *(volatile uint32_t *)off_1161D4 = 4;
      break;
    case 2:
      *(volatile uint32_t *)off_1161D4 = 8;
      break;
    case 3:
      *(volatile uint32_t *)off_1161D4 = 16;
      break;
    case 4:
      *(volatile uint32_t *)off_1161D4 = 1;
      break;
    case 5:
      *(volatile uint32_t *)off_1161D4 = 32;
      break;
    default:
      if ( **(volatile int16_t **)off_1161D8 < 0 )
        result = irq_disable_mmio_write(dword_1161E0, dword_1161DC, 944);
      break;
  }
  return result;
}



