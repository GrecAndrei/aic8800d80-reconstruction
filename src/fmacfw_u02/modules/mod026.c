// update_object_index @ 0x120038
uint64_t update_object_index(volatile uint8_t *a1, char a2) {
  int v3; // r6
  int v4; // r8
  int v5; // r4
  volatile uint8_t *v6; // r7
  int v7; // r10
  volatile int *v8; // r9
  volatile int *v9; // r0
  int v10; // r2
  int v11; // r3
  uint64_t result; // r0
  uint64_t v13; // r2
  int v14; // r4
  int v15; // r0

  v3 = *a1;
  v4 = a1[41];
  v5 = dword_120188;
  v6 = (volatile uint8_t *)(1320 * v4 + 120 * v3 + dword_120188);
  v7 = 120 * v3 + 1320 * v4;
  v6[578] = a2;
  v6[576] = a1[40];
  v8 = (volatile int *)(v7 + 480 + v5);
  v6[577] = v3;
  v9 = memset(v8, 0, 0x48u);
  switch ( v6[576] )
  {
    case 0:
    case 3:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = scale_timer_value(v9) & 0xFFFFFFLL;
      break;
    case 1:
      v15 = 1320 * v4 + 120 * v3 + v5;
      *(volatile uint32_t *)(v15 + 560) = *((volatile uint32_t *)a1 + 6);
      *(volatile uint32_t *)(v15 + 564) = *((volatile uint32_t *)a1 + 7);
      *(volatile uint32_t *)(v15 + 568) = *((volatile uint32_t *)a1 + 8);
      *(volatile uint32_t *)(v15 + 572) = *((volatile uint32_t *)a1 + 9);
      *(volatile uint64_t *)(v15 + 552) = 0;
      break;
    case 4:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = *(volatile uint64_t *)&dword_120180;
      break;
    case 5:
      memcpy((void *)(uintptr_t)(v7 + 560 + v5), a1 + 8, 16);
      goto LABEL_3;
    default:
LABEL_3:
      *(volatile uint64_t *)(1320 * v4 + 120 * v3 + v5 + 552) = 0;
      break;
  }
  v10 = 1320 * v4 + 120 * v3 + v5;
  v11 = 1320 * v4 + v5;
  if ( *(volatile uint8_t *)(v10 + 576) == 5 )
    *(volatile uint32_t *)(v11 + 1204) = (int)(uintptr_t)(v8);
  else
    *(volatile uint32_t *)(v11 + 1200) = (int)(uintptr_t)(v8);
  *(volatile uint8_t *)(v10 + 579) = 1;
  result = *((volatile uint64_t *)a1 + 1);
  v13 = *((volatile uint64_t *)a1 + 2);
  v14 = v5 + 1320 * v4 + 120 * v3;
  *(volatile uint64_t *)(v14 + 580) = result;
  *(volatile uint64_t *)(v14 + 588) = v13;
  *(volatile uint8_t *)(v14 + 596) = a1[4];
  return result;
}



// adjust_table_pointers @ 0x12018c
int adjust_table_pointers(int result, int a2) {
  int v2; // r3
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r3
  int v7; // r3

  v2 = 15 * a2;
  v3 = *(volatile uint32_t *)(result + 1200);
  v4 = result + 120 * a2 + 480;
  *(volatile uint8_t *)(result + 8 * v2 + 579) = 0;
  if ( v3 == v4 )
  {
    v5 = *(volatile uint8_t *)(result + 579);
    *(volatile uint32_t *)(result + 1200) = 0;
    v4 = result + 480;
    if ( v5
      || (v4 = result + 600, *(volatile uint8_t *)(result + 699))
      || (v4 = result + 720, *(volatile uint8_t *)(result + 819))
      || (v4 = result + 840, *(volatile uint8_t *)(result + 939)) )
    {
      *(volatile uint32_t *)(result + 1200) = v4;
      return result;
    }
  }
  if ( *(volatile uint32_t *)(result + 1204) == v4 )
  {
    v6 = *(volatile uint8_t *)(result + 1059);
    *(volatile uint32_t *)(result + 1204) = 0;
    if ( v6 )
    {
      v7 = result + 960;
    }
    else
    {
      if ( !*(volatile uint8_t *)(result + 1179) )
        return result;
      v7 = result + 1080;
    }
    *(volatile uint32_t *)(result + 1204) = v7;
  }
  return result;
}



// read_descriptor @ 0x120214
int read_descriptor(int result) {
  volatile uint32_t *v1; // r4
  int v2; // r5

  v1 = *(volatile uint32_t **)(result + 240);
  if ( v1 )
  {
    v2 = result;
    do
    {
      result = llc_ccm_encrypt(v2, (int)v1, 0);
      v1 = (volatile uint32_t *)*v1;
    }
    while ( v1 );
  }
  return result;
}



// configure_mmio @ 0x120230
int configure_mmio(int a1) {
  return unknown_worker((void *)(uintptr_t)(a1 + 48), *((volatile uint32_t *)off_120240 + 4) + 10000);
}



// get_radio_state_1 @ 0x120244
int get_radio_state_1(int result) {
  int v1; // r4

  if ( *(volatile uint8_t *)off_12026C && (*((volatile uint32_t *)off_12026C + 1) & 8) == 0 )
  {
    v1 = result;
    if ( !*(volatile uint32_t *)(result + 4) )
    {
      fault_handler(result + 48);
      return llm_conn_active_check(v1);
    }
  }
  return result;
}



// set_attribute_word @ 0x120270
int set_attribute_word(int result, unsigned int a2) {
  volatile uint32_t *v2; // r5
  volatile uint8_t *v3; // r3
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r4
  volatile int *i; // r3
  unsigned int v9; // r2
  volatile int *v10; // r3
  int v11; // r3

  *(volatile uint16_t *)(result + 222) = a2;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_120300 = 1;
  }
  v2 = (void *)(uintptr_t)(off_120304);
  v3 = (void *)(uintptr_t)(off_120308);
  v4 = *(volatile uint32_t *)off_120304;
  v5 = *((volatile uint8_t *)off_120308 + 18);
  v6 = *(volatile uint32_t *)off_120304 + 1;
  *(volatile uint32_t *)off_120304 = v6;
  if ( v5 <= 1 )
  {
    v3[20] = *(volatile uint8_t *)(result + 107);
    v7 = a2;
    *(volatile uint16_t *)(result + 224) = 257;
  }
  else
  {
    v7 = *(volatile uint16_t *)(dword_12030C + 1320 * (uint8_t)v3[20] + 222);
    if ( a2 < v7 )
    {
      v3[20] = *(volatile uint8_t *)(result + 107);
      v7 = a2;
    }
    for ( i = *((volatile int **)v3 + 2); i; i = (volatile int *)*i )
    {
      v9 = *((volatile uint16_t *)i + 111);
      *((volatile uint8_t *)i + 225) = 1;
      *((volatile uint8_t *)i + 224) = v9 / v7;
    }
  }
  *(volatile uint32_t *)off_120310 = (HIWORD(*(volatile uint32_t *)off_120310) << 16) | v7;
  if ( v6 )
  {
    v10 = (volatile int *)off_120300;
    *v2 = v4;
    v11 = *v10;
    if ( !v4 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}



// alloc_kernel_message @ 0x120314
int alloc_kernel_message(int a1) {
  volatile uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (volatile uint8_t *)ke_msg_alloc(88, 13, 0, 3);
  v3 = *(volatile uint8_t *)(a1 + 107);
  v10[0] = -1;
  sta_get_by_index(v3);
  v4 = *(volatile uint32_t *)(a1 + 1216);
  *(volatile uint32_t *)(a1 + 412) = *(volatile uint32_t *)(a1 + 1212);
  *(volatile uint32_t *)(a1 + 416) = v4;
  *(volatile uint16_t *)(a1 + 420) = *(volatile uint16_t *)(a1 + 1220);
  *(volatile uint8_t *)(a1 + 464) = 0;
  rf_temperature_comp(a1);
  v5 = scan_find_empty_slot((void *)(uintptr_t)(a1 + 1212), v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(volatile uint8_t *)(a1 + 107);
  v7 = *(volatile uint8_t *)(a1 + 106);
  if ( *(volatile uint8_t *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(volatile uint8_t *)(a1 + 231) = 0;
      if ( !v5 )
      {
        sta_lookup_by_bss(*(volatile uint8_t *)(a1 + 107), (uint8_t)v6);
        *((volatile uint8_t *)off_1203F0 + 9) = 1;
      }
    }
    return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v2)));
  }
  *(volatile uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(volatile uint8_t *)(a1 + 116);
    sta_lookup_by_bss(*(volatile uint8_t *)(a1 + 107), (uint8_t)v6);
    fault_handler(a1 + 48);
    unknown_worker((void *)(uintptr_t)(a1 + 24), *((volatile uint32_t *)off_1203EC + 4) + *(volatile uint32_t *)(dword_1203E8 + 696 * v8 + 8));
    *(volatile uint8_t *)(a1 + 128) = 0;
    *(volatile uint8_t *)(a1 + 147) = 1;
    return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v2)));
  }
  send_fw_cmd(a1);
  return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v2)));
}



// is_radio_ready @ 0x1203f4
int is_radio_ready() {
  int result; // r0

  if ( *((volatile uint8_t *)off_120414 + 18) + *((volatile uint8_t *)off_120414 + 17) != 1 )
    return 0;
  result = *((volatile uint32_t *)off_120414 + 2);
  if ( *(volatile uint8_t *)(result + 106) )
    return 0;
  return result;
}



// clear_irq_if_idle @ 0x120418
void clear_irq_if_idle() {
  int v0; // r3

  v0 = *((volatile uint8_t *)off_120430 + 18) + *((volatile uint8_t *)off_120430 + 17);
  *(volatile uint32_t *)off_120434 = 0;
  if ( v0 <= 1 )
    scan_active_get();
}



// clear_device_flag @ 0x120438
int clear_device_flag(volatile uint8_t *a1) {
  volatile uint32_t *v1; // r3
  volatile int *v2; // r3
  int result; // r0

  v1 = (void *)(uintptr_t)(off_120488);
  *a1 = 0;
  v2 = (volatile int *)v1[2];
  if ( v2 )
  {
    result = 0;
    while ( 1 )
    {
      if ( *((volatile uint8_t *)v2 + 106) )
      {
        if ( *((volatile uint8_t *)v2 + 108) && *((volatile uint8_t *)v2 + 1224) )
          goto LABEL_10;
LABEL_6:
        v2 = (volatile int *)*v2;
        if ( !v2 )
          return result;
      }
      else
      {
        if ( !*((volatile uint8_t *)v2 + 108) )
          goto LABEL_6;
        if ( !*((volatile uint8_t *)v2 + 1224) )
        {
          ++result;
          goto LABEL_6;
        }
LABEL_10:
        *a1 = 1;
        v2 = (volatile int *)*v2;
        if ( !v2 )
          return result;
      }
    }
  }
  return 0;
}



// alloc_bt_message @ 0x12048c
int alloc_bt_message(int a1) {
  volatile uint32_t *v2; // r0

  v2 = (volatile uint32_t *)ke_msg_alloc(143, 0, 255, 4);
  *v2 = a1;
  return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v2)));
}



// read_hw_register @ 0x1204a8
int read_hw_register() {
  int result; // r0
  volatile uint32_t *v1; // r1
  volatile uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  volatile uint32_t *v5; // r1
  int16_t v6; // r2
  volatile uint32_t *v7; // r1
  int16_t v8; // r2

  if ( (uint16_t)(*(volatile uint32_t *)off_120534 >> 12) && (uint16_t)(*(volatile uint32_t *)off_120534 >> 12) <= 0x96u )
    result = (uint16_t)(*(volatile uint32_t *)off_120534 >> 12);
  else
    result = 150;
  v1 = (void *)(uintptr_t)(off_120538);
  v2 = (void *)(uintptr_t)(off_12053C);
  v3 = *(volatile uint32_t *)off_120538;
  *((volatile uint16_t *)off_12053C + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = (void *)(uintptr_t)(off_120540);
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = (void *)(uintptr_t)(off_120544);
  v2[6] = v6;
  if ( (uint16_t)(*v7 >> 12) && (uint16_t)(*v7 >> 12) <= 0x96u )
  {
    v8 = *v7 >> 12;
    v2[7] = v8;
    v2[8] = v8;
  }
  else
  {
    v2[7] = 150;
    v2[8] = 150;
  }
  return result;
}



// clear_transmit_context @ 0x120548
int clear_transmit_context() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  volatile int16_t *v2; // r1
  int v3; // r1
  int result; // r0

  v0 = (void *)(uintptr_t)(off_12059C);
  memset((volatile int *)off_12059C, 0, 0x34u);
  v1 = dword_1205A4;
  v2 = *(volatile int16_t **)off_1205A0;
  *(volatile uint32_t *)v0 = dword_1205A4;
  v0[31] = 1;
  *((volatile uint16_t *)v0 + 9) = 0;
  v3 = *v2;
  *((volatile uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(volatile uint32_t *)off_1205B0 << 28 )
  {
    call_shared_handler(dword_1205B8, dword_1205B4, 472);
    v1 = *(volatile uint32_t *)v0 | *((volatile uint32_t *)v0 + 1);
  }
  *(volatile uint32_t *)off_1205A8 = v1;
  result = read_hw_register();
  *((volatile uint32_t *)v0 + 9) = dword_1205AC;
  return result;
}



// poll_rf_interrupts @ 0x1205bc
volatile uint32_t *poll_rf_interrupts() {
  volatile int *v0; // r4
  volatile int *v1; // r5
  volatile int *v2; // r6
  int v3; // r0
  int v4; // r0
  volatile uint32_t *v5; // r0
  volatile unsigned int *v6; // r1
  volatile unsigned int *v7; // r3
  int v8; // r4
  int v9; // r3
  char v10; // r2
  int v11; // zf
  int v12; // r2
  unsigned int v13; // r2
  volatile uint32_t *v14; // r2
  volatile uint32_t *v15; // r6
  volatile uint32_t *v16; // r5
  volatile uint32_t *v17; // r4
  volatile uint32_t *result; // r0
  volatile uint8_t **v19; // r1
  int v20; // r3

  v0 = (volatile int *)off_1206D8;
  v1 = (volatile int *)off_1206DC;
  v2 = (volatile int *)off_1206E0;
  v3 = noop_success();
  v4 = ((int (*)())nullsub_2)(v3);
  ((int (*)())nullsub_3)(v4);
  v5 = (void *)(uintptr_t)(off_1206E4);
  v6 = (volatile unsigned int *)off_1206E8;
  v7 = (volatile unsigned int *)off_1206EC;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1206F0;
  *v5 |= 0x8000000u;
  *v6 = *v6 & 0xFF0FFFFF | 0x200000;
  *v7 = *v7 & 0xFFFFF8FF | 0x600;
  *v7 = *v7 & 0xFFFFC7FF | 0x2000;
  *v7 = *v7 & 0xFFFE3FFF | 0xC000;
  *v7 |= 0xE0000u;
  *v1 = *v1 & v8 | 0x5DC;
  v5[1] = v5[1] & v8 | 0xBB8;
  *(v6 - 205) = *(v6 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v2;
  v10 = *(volatile uint8_t *)(*v2 + 2);
  if ( (v10 & 0x10) != 0 )
    v5[16] &= ~0x80000000;
  else
    *(volatile uint32_t *)off_12071C |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(volatile uint32_t *)off_1206F4;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(volatile uint32_t *)off_1206F4 = v13;
  v14 = (void *)(uintptr_t)(off_1206F8);
  *(volatile uint32_t *)off_1206F8 = dword_1206FC;
  if ( *(volatile uint8_t *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = (void *)(uintptr_t)(off_120704);
  v16 = (void *)(uintptr_t)(off_120708);
  v17 = (void *)(uintptr_t)(off_12070C);
  result = (void *)(uintptr_t)(off_120710);
  v19 = (volatile uint8_t **)off_120714;
  *(volatile uint32_t *)off_120700 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(volatile uint32_t *)off_120718 |= 0x80000000;
  return result;
}



// get_bt_state @ 0x120720
volatile uint32_t *get_bt_state() {
  volatile uint8_t *v0; // r4
  volatile int *v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v0 = (void *)(uintptr_t)(off_120778);
  if ( !*((volatile uint8_t *)off_120778 + 2) )
    bb_enable_1();
  clear_transmit_context();
  ble_sched_init();
  v1 = (void *)(uintptr_t)(ble_event_set());
  v2 = (int)(uintptr_t)(tx_queue_flush(v1));
  v3 = wlc_mfp_key_clear(v2);
  llc_reset(v3);
  v4 = chip_init_sequence();
  if ( v0[2] )
    v5 = ((int (*)())nullsub_4)(v4);
  else
    v5 = rf_poll();
  v6 = get_soc_handle(v5);
  v7 = rf_env_reset(v6);
  v8 = stat_clear(v7);
  v9 = lock_core_pair(v8);
  init_timer(v9);
  bt_get_state();
  return poll_rf_interrupts();
}



// is_valid_id @ 0x12077c
volatile int * is_valid_id(volatile int *result, int a2, int a3) {
  volatile int *v3; // r3
  volatile unsigned int *v4; // r3
  volatile unsigned int *v5; // r3
  volatile unsigned int *v6; // r3

  if ( !a2 )
  {
    v3 = *((volatile int **)off_120838 + 2);
    if ( !v3 )
    {
      if ( a3 )
        goto LABEL_13;
      goto LABEL_4;
    }
    while ( 1 )
    {
      while ( result == v3 || !*((volatile uint8_t *)v3 + 108) )
      {
LABEL_7:
        v3 = (volatile int *)*v3;
        if ( !v3 )
          goto LABEL_12;
      }
      if ( *((volatile uint8_t *)v3 + 413) == 2 )
      {
        if ( *((volatile uint8_t *)v3 + 106) == 2 )
          break;
        a2 = 1;
        goto LABEL_7;
      }
      v3 = (volatile int *)*v3;
      if ( !v3 )
      {
LABEL_12:
        if ( a2 | a3 )
        {
LABEL_13:
          v5 = (volatile unsigned int *)off_12083C;
          *(volatile uint32_t *)off_12083C = *(volatile uint32_t *)off_12083C & 0xFFFFFF00 | 0x68;
          *v5 = *v5 & 0xFFFF00FF | 0x7800;
          *v5 = *v5 & 0xFF00FFFF | 0x780000;
          return result;
        }
LABEL_4:
        v4 = (volatile unsigned int *)off_12083C;
        *(volatile uint32_t *)off_12083C = *(volatile uint32_t *)off_12083C & 0xFFFFFF00 | 0x80;
        *v4 = *v4 & 0xFFFF00FF | 0x8000;
        *v4 = *v4 & 0xFF00FFFF | 0x800000;
        return result;
      }
    }
  }
  v6 = (volatile unsigned int *)off_12083C;
  *(volatile uint32_t *)off_12083C = *(volatile uint32_t *)off_12083C & 0xFFFFFF00 | 0x60;
  *v6 = *v6 & 0xFFFF00FF | 0x6000;
  *v6 = *v6 & 0xFF00FFFF | 0x600000;
  return result;
}



// handle_rx_data @ 0x120840
int handle_rx_data(int a1, int a2, int a3, int a4, int a5, int a6) {
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r7
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r5
  volatile char *v14; // r2
  volatile int *v15; // r8
  volatile int *v16; // r0
  volatile uint32_t *v17; // r2
  volatile int16_t **v18; // r3
  int v19; // r5
  volatile char *v20; // r1
  volatile int *v21; // r0
  volatile uint32_t *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  uint64_t v26; // kr08_8
  uint64_t v27; // r0
  int v28; // r3
  uint64_t v29; // r0
  int v30; // r2
  int v31; // r1
  volatile unsigned int v32; // r5
  int v33; // r5
  signed int v34; // r0
  int v35; // r3
  int v36; // r1
  volatile unsigned int v37; // r3
  int v38; // r0
  volatile unsigned int v39; // r3
  int result; // r0
  volatile uint8_t *v41; // r3
  volatile uint32_t *v42; // r2
  volatile uint8_t *v43; // r5
  int v44; // r1
  volatile uint8_t *v45; // r1
  volatile uint32_t *v46; // r2
  uint64_t v47; // [sp+8h] [bp-1Ch]
  int v48; // [sp+10h] [bp-14h]
  unsigned int v49; // [sp+14h] [bp-10h]
  int v51; // [sp+1Ch] [bp-8h]

  v8 = *(volatile uint32_t *)(a3 + 32);
  v9 = *(volatile uint16_t *)(a1 + 32);
  v49 = *(volatile uint32_t *)(a3 + 36);
  v10 = *(volatile uint32_t *)(a1 + 24);
  v11 = *(volatile uint32_t *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(volatile uint8_t *)(a4 + 106) && (v13 = *(volatile uint16_t *)(a4 + 112), *(volatile uint16_t *)(a4 + 112)) )
  {
    tx_arbiter_calc(*(volatile uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v51 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(volatile uint8_t *)(a6 + 2);
    if ( !*(volatile uint8_t *)(a6 + 2) )
    {
      v13 = *(volatile uint8_t *)(a6 + 3);
      tx_arbiter_calc(*(volatile uint8_t *)(a4 + 107), v9, v13);
    }
    v51 = v12 * v13;
  }
  else
  {
    v51 = v9 << 10;
    v13 = 1;
  }
  v48 = v13 * *(volatile uint16_t *)(a5 + 30);
  if ( *(volatile uint8_t *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (volatile char *)off_120B54;
    v15 = (volatile int *)off_120BA4;
    v16 = (volatile int *)off_120B58;
    *(volatile uint32_t *)off_120B54 = *((volatile uint8_t *)off_120BA4 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(volatile uint32_t *)off_120B54 & 0xFFFFFF80;
    v17 = (void *)(v14 + 8);
    *v16 = a2 | (*(volatile uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (volatile int16_t **)off_120B5C;
    if ( **(volatile int16_t **)off_120B5C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(volatile uint32_t *)off_120B60;
    }
    else
    {
      bad_func_0x12f408((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
      v19 = 500;
      v18 = (volatile int16_t **)off_120B5C;
    }
    if ( !(*(volatile uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (volatile char *)off_120B54;
      v21 = (volatile int *)off_120B58;
      *(volatile uint32_t *)off_120B54 = *((volatile uint8_t *)v15 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(volatile uint32_t *)off_120B54 & 0xFFFFFF80;
      v22 = (void *)(v20 + 8);
      *v21 = (*(volatile uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(volatile uint32_t *)off_120B60;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      bad_func_0x12f408((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(volatile uint8_t *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v49, v8) + (unsigned int)v24;
  *(volatile uint64_t *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(volatile uint32_t *)(a4 + 132) = v26;
    *(volatile uint32_t *)(a4 + 136) = v48 + 400;
  }
  v27 = validate_args(__PAIR64__(v11, v10), v12);
  v47 = __PAIR64__(v11, v10) - (unsigned int)v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (uint64_t)(unsigned int)v12;
  v29 = (v29 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v29 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v28))) << 32;;
  if ( v29 < v47 )
    v47 = v29;
  v30 = v47 + v51;
  if ( (*(volatile uint32_t *)off_120B64 & 0x2000000) != 0 )
    v31 = dword_120B74 - v48 - v26 + v30;
  else
    v31 = v30 - v48 - 400;
  v32 = (*(volatile uint32_t *)0x40501010u);
  v33 = v32 - *(volatile uint32_t *)off_120B6C + v31;
  v34 = v33 - (*(volatile uint32_t *)0x40501010u) - 4300 - get_constant_1000();
  if ( v34 < 0 )
    v33 += v12;
  if ( (*(volatile uint32_t *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(volatile uint8_t *)(a4 + 85);
    v36 = v35 << 30;
    if ( (v35 & 2) != 0 )
    {
      v37 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(v33 - v37 - 10000) < 0 )
      {
        v33 += v12;
        event_dispatch(aMoveTbtt, v36);
      }
    }
  }
  v38 = get_constant_1000();
  v39 = (*(volatile uint32_t *)0x40501010u);
  result = v33 - v39 - 4300 - v38;
  if ( result >= 0 && *(volatile uint32_t *)(a4 + 36) != v33 )
  {
    v41 = (void *)(uintptr_t)(off_120B70);
if ( *((volatile uint32_t *)off_120B70 + 8) != a4 || (v42 = (void *)(uintptr_t)(off_120B64), *(volatile uint32_t *)(a4 + 36) = v33, (*v42 & 0x2000000) != 0) ) { unknown_worker((volatile uint32_t *)(a4 + 24), v33);
    }
    else
    {
      v43 = (volatile uint8_t *)off_120B84;
      v44 = (uint8_t)v41[36];
      *(volatile uint8_t *)off_120B84 = BYTE2(*(volatile uint32_t *)off_120B80);
      if ( !v44 )
      {
        v45 = *(volatile uint8_t **)off_120B8C;
        v43[1] = *(volatile uint32_t *)off_120B88;
        v41[36] = 1;
        if ( *v45 == 1 )
        {
          v46 = (void *)(uintptr_t)(off_120B94);
          *(volatile uint32_t *)off_120B90 = 1;
          *v46 |= 1u;
        }
        if ( *v43 >= (unsigned int)v43[1] )
          event_dispatch(
            "dtim:%d,%d,%d,%d\r\n",
            *v43,
            v43[1],
            HIWORD(*(volatile uint32_t *)off_120BC8),
            (uint8_t)*(volatile uint32_t *)off_120BC4);
        if ( **(volatile int16_t **)off_120B5C < 0 && *v43 >= (unsigned int)v43[1] )
          mmio_clear_register((int)aVolatileUint8T, (int)aMmTbttCompute, 523);
      }
    }
    return wlc_is_running(a4);
  }
  return result;
}


// wait_for_hw_flag @ 0x120bd0
int wait_for_hw_flag() {
  unsigned int v0; // r10
  int v1; // r8
  int result; // r0
  unsigned int v3; // r4
  int v4; // r1
  volatile uint32_t *v5; // r7
  volatile uint32_t *v6; // r5
  volatile uint32_t *v7; // r9
  int v8; // r3
  volatile unsigned int v9; // r2
  int v10; // r1
  int v11; // r1
  unsigned int v12; // r3
  int v13; // r6
  unsigned int v14; // r5
  unsigned int v15; // r6
  int v16; // r1
  int v17; // r3
  volatile unsigned int v18; // r2
  char v19; // r5
  volatile uint8_t **v20; // r7
  volatile uint8_t *v21; // r1
  volatile uint32_t *v22; // r3
  int v23; // r3
  volatile int16_t **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r1
  char v29; // r1
  volatile unsigned int v30; // r3
  volatile uint32_t *v31; // r2
  volatile uint32_t *v32; // r7
  volatile uint32_t *v33; // r1
  unsigned int v34; // r3
  volatile uint32_t *v35; // r9
  volatile uint32_t *v36; // r5
  int v37; // r2
  volatile unsigned int v38; // r6
  int v39; // r2
  unsigned int v40; // r3
  volatile uint32_t *v41; // r6
  volatile unsigned int v42; // r3
  int v43; // r3
  int v44; // r2
  volatile uint32_t *v45; // r2
  volatile unsigned int v46; // r8
  unsigned int v47; // r1
  int v48; // r5
  uint64_t v49; // [sp+0h] [bp-Ch]
  int v50; // [sp+0h] [bp-Ch]
  int v51; // [sp+0h] [bp-Ch]

  v0 = dword_120F54;
  v1 = *(volatile uint32_t *)(dword_120F54 + 0x20);
  result = unknown_func_12d14c(0x40000);
  if ( v1 )
  {
    v3 = dword_120EDC;
    v4 = *(volatile uint8_t *)(dword_120EDC + 0x1E);
LABEL_3:
    v5 = (volatile uint32_t *)dword_120EE0;
    v6 = (volatile uint32_t *)dword_120EE4;
    v7 = (volatile uint32_t *)dword_120F5C;
    while ( 1 )
    {
      if ( !v4 )
        return result;
      if ( (v4 & 8) != 0 )
      {
        v8 = *(volatile uint32_t *)dword_120EE8;
        *(volatile uint32_t *)dword_120EEC = 0x80000000;
        v9 = (*(volatile uint32_t *)0x40501010u);
        if ( (int)(*(volatile uint32_t *)(v8 + 4) + *(volatile uint32_t *)(v1 + 120) - v9) < 0
          && !rf_channel_get(*(volatile uint8_t *)(v1 + 116), 0, 0) )
        {
          v30 = (*(volatile uint32_t *)0x40501010u);
          *(volatile uint32_t *)(v1 + 120) = v30;
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xF7;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 4) != 0 )
      {
        check_status_bits(2, (const volatile char *)dword_120F14);
        v24 = (volatile int16_t **)dword_120EF8;
        v25 = *(volatile uint32_t *)(v3 + 4);
        *v5 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *(volatile uint32_t *)(v3 + 4) = v27;
        if ( v26 < 0 && *(volatile uint32_t *)dword_120F24 << 28 )
        {
          call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_1, 472);
          v27 = *(volatile uint32_t *)(v3 + 4);
        }
        v28 = off_120F18;
        *(volatile uint32_t *)dword_120F1C = v27 | *(volatile uint32_t *)v3;
        link_get_connection_info(*(volatile uint8_t *)(v1 + 107), v28, v1);
        v29 = *(volatile uint8_t *)(v3 + 0x1E);
        *v6 &= 0xFC0FFFFF;
        v4 = v29 & 0xFB;
        *v7 |= 0x400000u;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      if ( (v4 & 2) != 0 )
      {
        *(volatile uint32_t *)(v1 + 4) &= ~2u;
        if ( *(volatile uint8_t *)(v0 + 0x1D) == 5 )
        {
          fault_handler((int)(uintptr_t)((volatile uint32_t *)dword_120F34));
          v4 = (v4 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v3 + 0x1E)) & 0xFFu);
          *(volatile uint8_t *)(v0 + 0x1D) = 0;
        }
        v4 &= 0xFDu;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
      }
      result = v4 << 31;
      if ( (v4 & 1) != 0 )
        break;
LABEL_20:
      if ( (v4 & 0x20) != 0 )
      {
        v14 = *(volatile uint32_t *)dword_120F00;
        v15 = (*(volatile uint32_t *)dword_120F00 >> 5) & 3;
        check_status_bits(2, "BCN:%d[%d]\r\n", v15, HIWORD(*(volatile uint32_t *)(dword_120F00 - 12)) & 0x7FFF);
        v16 = *(volatile uint32_t *)(v1 + 120);
        v17 = *(volatile uint32_t *)(*(volatile uint32_t *)dword_120EE8 + 4);
        *(volatile uint8_t *)(v1 + 128) = 0;
        v18 = (*(volatile uint32_t *)0x40501010u);
        v19 = v14 >> 5;
        if ( (int)(v17 + v16 - v18) < 0 )
        {
          *(volatile uint8_t *)(v3 + 0x1E) |= 8u;
          check_status_bits(2, aNull);
        }
        if ( v15 )
        {
          while ( (*(volatile uint32_t *)dword_120F00 & 8) == 0 )
            ;
          v32 = (volatile uint32_t *)dword_120F00;
          *(volatile uint32_t *)dword_120F00 &= ~8u;
          if ( (*v32 & 0x10) != 0 )
          {
            check_status_bits(2, aFcsOk);
            *(volatile uint8_t *)dword_120F08 = BYTE2(*(volatile uint32_t *)dword_120F4C);
            wlc_rx_reclaim(v15 >> 1, v19 & 1, v1);
            *v32 &= ~0x10u;
          }
          else
          {
            *(volatile uint32_t *)dword_121078 = 1;
            check_status_bits(2, aFcsNotOk);
            v33 = (volatile uint32_t *)dword_121084;
            *(volatile uint8_t *)dword_121080 = *(volatile uint8_t *)(dword_121080 + 1) > 1u;
            *v33 = 1;
          }
        }
        else
        {
          *(volatile uint8_t *)dword_120F08 = *(volatile uint8_t *)(dword_120F08 + 1);
        }
        v20 = (volatile uint8_t **)dword_120F10;
        *(volatile uint32_t *)dword_120F0C &= ~0x200u;
        *(volatile uint32_t *)(v1 + 4) &= ~1u;
        result = fault_handler((int)(uintptr_t)((volatile uint32_t *)(v1 + 48)));
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(volatile uint32_t *)dword_121094 = 1;
          }
          v35 = (volatile uint32_t *)dword_1210B0;
          v36 = (volatile uint32_t *)dword_121088;
          v37 = *(volatile uint32_t *)dword_121088;
          ++*(volatile uint32_t *)dword_1210B0;
          *v36 = 0;
          v38 = (*(volatile uint32_t *)0x40501010u);
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            v40 = (*(volatile uint32_t *)0x40501010u) - v38;
            if ( v40 > 0x7530 )
            {
              v50 = v39;
              check_status_bits(2, aIdleErr);
              v39 = v50;
            }
          }
          v41 = (volatile uint32_t *)dword_12109C;
          result = *(volatile uint32_t *)dword_12109C;
          v42 = (*(volatile uint32_t *)0x40501010u);
          if ( v39 )
          {
            result &= *(volatile uint32_t *)dword_121098;
            if ( (result & 4) == 0 )
            {
              v51 = v1;
              v45 = (volatile uint32_t *)dword_121098;
              v46 = v42;
              do
              {
                result = 30000;
                v47 = (*(volatile uint32_t *)0x40501010u) - v46;
                v48 = *v45 & *v41;
                if ( v47 > 0x7530 )
                {
                  result = check_status_bits(2, aIdleIntErr);
                  v45 = (volatile uint32_t *)dword_121098;
                }
              }
              while ( (v48 & 4) == 0 );
              v1 = v51;
            }
          }
          *(volatile uint32_t *)dword_1210A0 = 4;
          if ( *v35 )
          {
            v43 = *v35 - 1;
            v44 = *(volatile uint32_t *)dword_121094;
            *v35 = v43;
            if ( !v43 )
            {
              if ( v44 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = (volatile uint32_t *)dword_120F00;
        *(volatile uint32_t *)dword_120F00 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          v34 = (*(volatile uint32_t *)0x40501010u) + 32 * *(volatile uint32_t *)dword_12108C;
          result = unknown_worker((volatile uint32_t *)(v1 + 24), v34 - *(volatile uint16_t *)(dword_121090 + 0xBA));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(volatile uint32_t *)dword_121088 = 48;
          result = fatal_error_handler();
        }
        v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xDF;
        *(volatile uint8_t *)(v3 + 0x1E) = v4;
        goto LABEL_3;
      }
    }
    if ( (*(volatile uint32_t *)dword_120EF0 & 0x4000000) != 0 )
    {
      v10 = HIWORD(*(volatile uint32_t *)dword_120EF0);
      if ( (v10 & 0x3F0) != 0 )
      {
        v11 = (uint8_t)(v10 - 16);
        v12 = dword_120EF4 + 696 * v11;
        if ( *(volatile uint8_t *)(v12 + 37) )
        {
          result = 1320;
          v13 = dword_120EFC + 1320 * *(volatile uint8_t *)(v12 + 34);
          if ( **(volatile int16_t **)dword_120EF8 >= 0 || v1 == v13 )
          {
            if ( (*v6 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = mmio_clear_register((int)aVifStaVif, (int)aMmSleepinfoRxE, 864);
            if ( (*v6 & 0x70000) == 0 )
            {
LABEL_43:
              v49 = (v49 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)dword_120EF0 >> 31) & 0xFFFFFFFFu);
              v49 = (v49 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)((*(volatile uint32_t *)dword_120EF0 >> 30) & 1) << 32);
              check_status_bits(2, "T=%d,%d\r\n", (uint32_t)v49, HIDWORD(v49));
              result = v49;
              if ( v49 )
              {
                result = wlc_rx_reclaim(v49, SHIDWORD(v49), v13);
                v31 = (volatile uint32_t *)dword_120EF0;
                *(volatile uint32_t *)dword_120EF0 &= ~0x80000000;
                *v31 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = event_dispatch("\x9B\x84Invalid STA:%d\n", v11);
        }
      }
      else
      {
        result = event_dispatch(asc_148810);
      }
    }
    else
    {
      result = event_dispatch("\x9B\x84Keyidx invalid,%02X\n", v4);
    }
    v4 = *(volatile uint8_t *)(v3 + 0x1E) & 0xFE;
    *(volatile uint8_t *)(v3 + 0x1E) = v4;
    goto LABEL_20;
  }
  return result;
}


// radio_is_ready @ 0x1210b4
int radio_is_ready() {
  if ( rx_rate_field_parse(0) != 1 )
    return ke_state_set(0, 0);
  *(volatile uint32_t *)off_1210E0 = 48;
  return ke_state_set(0, 1);
}


// set_clock_divisor @ 0x1210e4
int set_clock_divisor() {
  *(volatile uint32_t *)off_1210F4 = 48;
  return ke_state_set(0, 1);
}


// event_queue_drain @ 0x1210f8
void event_queue_drain() {
  unsigned int v0; // r6
  int v1; // r4
  volatile uint32_t *v2; // r5
  int v3; // r3
  int v4; // r2
  volatile uint32_t *v5; // r7
  volatile uint32_t *v6; // r9
  int v7; // r5
  int v8; // r3
  volatile uint32_t *v9; // r3
  unsigned int v10; // r10
  unsigned int v11; // r2
  int v12; // r10
  unsigned int v13; // r4
  volatile unsigned int v14; // r2
  unsigned int v15; // r3
  int v16; // zf
  int v17; // cc
  int v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r2
  int v22; // r3
  volatile unsigned int v23; // r1
  volatile uint32_t *v24; // r0
  volatile int **i; // r3
  int v26; // r2
  int v27; // r1
  int v28; // r0
  int v29; // r12
  int v30; // r2

  v0 = dword_121300;
  v1 = *(volatile uint32_t *)(dword_121300 + 8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_121304 = 1;
  }
  v2 = (volatile uint32_t *)dword_121308;
  ++*(volatile uint32_t *)dword_121308;
  mmio_set_bit_1(4);
  phy_band_validate(4u);
  if ( *v2 && (v3 = *v2 - 1, v4 = *(volatile uint32_t *)dword_121304, (*v2 = v3) == 0) && v4 )
  {
    __enable_irq();
    if ( !v1 )
      goto LABEL_32;
  }
  else if ( !v1 )
  {
LABEL_32:
    ke_event_dispatch();
    return;
  }
  v5 = (volatile uint32_t *)dword_12130C;
  v6 = (volatile uint32_t *)dword_121338;
  v7 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(volatile uint8_t *)(v1 + 106) != 2 )
        goto LABEL_7;
      v8 = (uint8_t)(*(volatile uint8_t *)(v1 + 225) - 1);
      *(volatile uint8_t *)(v1 + 225) = v8;
      if ( v8 )
        goto LABEL_7;
      v9 = *(volatile uint32_t **)dword_121310;
      *(volatile uint8_t *)(v1 + 225) = *(volatile uint8_t *)(v1 + 224);
      if ( !v9 )
        break;
      while ( v9 != (volatile uint32_t *)(v1 + 48) )
      {
        v9 = (volatile uint32_t *)*v9;
        if ( !v9 )
          goto LABEL_15;
      }
      event_dispatch(aNextTbttTooClo);
LABEL_7:
      v1 = *(volatile uint32_t *)v1;
      if ( !v1 )
        goto LABEL_26;
    }
LABEL_15:
    configure_mmio(v1);
    llc_get_conn_idx((void *)(uintptr_t)(v1), *(volatile uint32_t *)(v1 + 36) + 3048);
    v10 = 32 * *v5;
    if ( v10 <= 0xBE7 )
      v10 += *(volatile uint16_t *)(v1 + 222) << 10;
    v11 = (*(volatile uint32_t *)0x40501010u) - 3048;
    v12 = v10 + v11;
    if ( *(volatile uint32_t *)(v1 + 72) )
      rx_dispatch_frame(v1, *(volatile uint32_t *)(v1 + 36), v12);
    if ( *(volatile uint8_t *)(v1 + 1224) )
    {
      unknown_worker((volatile uint32_t *)(v1 + 24), v12);
    }
    else
    {
      if ( *(volatile uint8_t *)(dword_121314 + 0x5A) > 1u )
      {
        for ( i = *(volatile int ***)(dword_121314 + 0x10); i; i = (volatile int **)*i )
        {
          if ( *((volatile uint8_t *)i + 8) == *(volatile uint8_t *)(v1 + 107) )
          {
            v26 = *(volatile uint16_t *)(v1 + 222);
            v27 = *(volatile uint32_t *)(v1 + 36);
            v28 = (int)i[1];
            v29 = v27 + (v26 << 10);
            v30 = v26 << 10;
            if ( v28 == v29 )
            {
              i[1] = (volatile int *)v12;
              v28 = v12;
              v30 = *(volatile uint16_t *)(v1 + 222) << 10;
            }
            if ( v27 + 2 * v30 == v28 )
              i[1] = (volatile int *)(v30 + v12);
          }
        }
      }
      if ( *(volatile uint8_t *)dword_121318 && (*(volatile uint32_t *)(v0 + 0x10) & 0xFFFF00) == 0x10000 && (uint16_t)*v6 > 0x14u )
      {
        v14 = (*(volatile uint32_t *)0x40501010u);
        v15 = *(volatile uint8_t *)dword_121328;
        v16 = v15 == 2;
        v17 = v15 > 2;
        v18 = (uint16_t)*v6;
        if ( v17 )
        {
          unknown_worker((volatile uint32_t *)dword_12132C, v14 + 500 * v18);
        }
        else
        {
          if ( v16 )
            v19 = 250;
          else
            v19 = 200;
          unknown_worker((volatile uint32_t *)dword_12132C, v14 + v19 * v18);
        }
      }
      *(volatile uint32_t *)(v1 + 36) = v12;
    }
    if ( *(volatile uint8_t *)(v1 + 412) == 1 )
      v7 = v1;
    v1 = *(volatile uint32_t *)v1;
  }
  while ( v1 );
LABEL_26:
  ke_event_dispatch();
  if ( *(volatile uint8_t *)(dword_12131C + 0x19D) )
  {
    if ( v7 )
    {
      v13 = dword_121320;
      if ( *(volatile uint8_t *)(dword_121320 + 0xF) )
      {
        if ( rx_rate_field_parse(4u) != 1 )
        {
          if ( !*(volatile uint8_t *)(v13 + 0xE)
            || (v20 = (uint8_t)(*(volatile uint8_t *)(v13 + 0xE) - 1), *(volatile uint8_t *)(v13 + 0xE) = v20, !v20) )
          {
            v21 = *(volatile uint16_t *)(v7 + 222);
            v22 = *(volatile uint32_t *)(v13 + 0x10);
            v23 = (*(volatile uint32_t *)0x40501010u);
            v24 = (volatile uint32_t *)dword_121334;
            *(volatile uint32_t *)(v13 + 0x1C) = v7;
            *(volatile uint8_t *)(v13 + 0xE) = *(volatile uint8_t *)(v13 + 0xF);
            unknown_worker(v24, v23 + ((unsigned int)((v21 << 10) - v22) >> 1));
          }
        }
      }
    }
  }
}


// jump_to_12ad08 @ 0x12133c
int jump_to_12ad08(int a1) {
  return ctx_byte_get(a1);
}



// mac_core_setup @ 0x121340
int mac_core_setup(int a1, int a2) {
  int v2; // r6
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // lr
  volatile uint32_t *v5; // r12
  volatile uint32_t *v6; // r7
  volatile uint16_t *v7; // r2
  volatile uint32_t *v8; // r5
  volatile int *v9; // r2
  int v10; // r4
  unsigned int v11; // r5
  volatile uint32_t *v12; // r12
  volatile uint32_t *v13; // r7
  volatile uint16_t *v14; // r3
  volatile uint32_t *v15; // r2

  v2 = dword_1213F8;
  v3 = (void *)(uintptr_t)(off_1213FC);
  v4 = (void *)(uintptr_t)(off_121410);
  v5 = (void *)(uintptr_t)(off_121414);
  v6 = (void *)(uintptr_t)(off_121400);
  v7 = (volatile uint16_t *)(dword_1213F8 + 696 * a1);
  *(volatile uint32_t *)off_1213FC = v7[19] | (v7[20] << 16);
  v8 = (void *)(uintptr_t)(off_121404);
  v3[1] = v7[21];
  v9 = (volatile int *)off_121408;
  *v4 = 0;
  *v5 = 0;
  *v8 = 0;
  *v6 = 0;
  v10 = (uint8_t)(a1 + 16);
  *v9 = 0x20000000;
  while ( (*v9 & 0x20000000) != 0 )
    ;
  if ( (*v9 & 0x10000000) == 0 )
  {
    v11 = HIWORD(*v9);
    if ( (uint8_t)BYTE2(*v9) != v10 )
    {
      v12 = (void *)(uintptr_t)(off_12140C);
      v13 = (void *)(uintptr_t)(off_121408);
      *(volatile uint32_t *)off_1213FC = -1;
      *v12 = -1;
      *v9 = ((uint8_t)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (volatile uint16_t *)(v2 + 696 * a1);
      *(volatile uint32_t *)off_1213FC = v14[19] | (v14[20] << 16);
      *(volatile uint32_t *)off_12140C = v14[21];
    }
  }
  v15 = (void *)(uintptr_t)(off_121408);
  *(volatile uint32_t *)off_121408 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (uint8_t)(a1 + 16);
}



// rx_packet_parse_header @ 0x121418
int rx_packet_parse_header(volatile char *a1) {
  unsigned int v4; // r7
  int v5; // r5
  int v7; // r6
  volatile uint32_t *v8; // r2
  volatile uint16_t *v9; // r7
  volatile uint32_t *v10; // r3
  volatile uint8_t *v11; // r3
  volatile uint32_t *v12; // r3
  int v13; // r0
  int v14; // r1
  volatile uint32_t *v15; // r3
  volatile uint32_t *v16; // r2
  char v18; // r6
  volatile uint32_t *v19; // r2
  volatile uint32_t *v20; // r3
  volatile uint32_t *v21; // r3
  volatile uint32_t *v22; // r3
  volatile uint32_t *v23; // r3
  volatile uint32_t *v24; // r3
  int v25; // r5

  v4 = (uint8_t)a1[1];
  v5 = (uint8_t)a1[41];
  if ( v4 == 255 )
  {
    if ( a1[40] == 5 )
    {
      v25 = HIBYTE(*(volatile uint32_t *)off_121668) - 3 + (uint8_t)*a1 + 2 * v5;
      v7 = (uint8_t)v25;
      update_object_index((volatile uint8_t *)a1, v25);
      return v7;
    }
    v18 = *a1;
    v19 = (void *)(uintptr_t)(off_121640);
    *(volatile uint32_t *)off_12163C = -1;
    *v19 = -1;
    v7 = (uint8_t)(v18 + 4 * v5);
    check_status_bits(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
    update_object_index((volatile uint8_t *)a1, v7);
  }
  else
  {
    if ( **(volatile int16_t **)off_121630 < 0 && v4 > 0x23 )
      mmio_clear_register((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    v7 = (uint8_t)(v4 + 16);
    check_status_bits(256, "add ptk:%d,%d\r\n", v4, (uint8_t)a1[40]);
    llm_conn_set_flag((int)a1, v4 + 16);
    v8 = (void *)(uintptr_t)(off_121640);
    v9 = (volatile uint16_t *)(dword_121638 + 696 * v4);
    *(volatile uint32_t *)off_12163C = v9[19] | (v9[20] << 16);
    *v8 = v9[21];
  }
  switch ( a1[40] )
  {
    case 0:
      v20 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v20[1] = *((volatile uint32_t *)a1 + 3);
      v20[2] = *((volatile uint32_t *)a1 + 4);
      v20[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 256;
      v14 = 0;
      break;
    case 1:
      v10 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v10[1] = *((volatile uint32_t *)a1 + 3);
      v10[2] = *((volatile uint32_t *)a1 + 4);
      v11 = *(volatile uint8_t **)off_121650;
      *(volatile uint32_t *)off_121654 = *((volatile uint32_t *)a1 + 5);
      if ( (*v11 & 1) != 0 )
      {
        v12 = (void *)(uintptr_t)(off_121658);
        *(volatile uint32_t *)off_121658 = *((volatile uint32_t *)a1 + 6);
        v12[1] = *((volatile uint32_t *)a1 + 7);
        v12[2] = *((volatile uint32_t *)a1 + 8);
        v12[3] = *((volatile uint32_t *)a1 + 9);
      }
      else
      {
        *(volatile uint32_t *)off_121664 &= ~1u;
      }
      v13 = 512;
      v14 = 4096;
      break;
    case 2:
      v15 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v15[1] = *((volatile uint32_t *)a1 + 3);
      v15[2] = *((volatile uint32_t *)a1 + 4);
      v15[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 768;
      v14 = 0;
      break;
    case 3:
      v13 = 256;
      v14 = 4096;
      goto LABEL_22;
    case 4:
      v24 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v24[1] = *((volatile uint32_t *)a1 + 3);
      v24[2] = *((volatile uint32_t *)a1 + 4);
      v24[3] = *((volatile uint32_t *)a1 + 5);
      v13 = 1024;
      v14 = 4096;
      goto LABEL_20;
    case 6:
      v13 = 1280;
      v14 = 0;
      goto LABEL_22;
    case 7:
      v13 = 1280;
      goto LABEL_19;
    case 8:
      v13 = 768;
LABEL_19:
      v21 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v21[1] = *((volatile uint32_t *)a1 + 3);
      v21[2] = *((volatile uint32_t *)a1 + 4);
      v21[3] = *((volatile uint32_t *)a1 + 5);
      v14 = 0x2000;
LABEL_20:
      v22 = (void *)(uintptr_t)(off_121658);
      *(volatile uint32_t *)off_121658 = *((volatile uint32_t *)a1 + 6);
      v22[1] = *((volatile uint32_t *)a1 + 7);
      v22[2] = *((volatile uint32_t *)a1 + 8);
      v22[3] = *((volatile uint32_t *)a1 + 9);
      break;
    default:
      if ( **(volatile int16_t **)off_121630 < 0 )
        mmio_clear_register(off_121670, (int)aMmKeyRamParamG, 159);
      v13 = 0;
      v14 = 4096;
LABEL_22:
      v23 = (void *)(uintptr_t)(off_12164C);
      *(volatile uint32_t *)off_12164C = *((volatile uint32_t *)a1 + 2);
      v23[1] = *((volatile uint32_t *)a1 + 3);
      v23[2] = *((volatile uint32_t *)a1 + 4);
      v23[3] = *((volatile uint32_t *)a1 + 5);
      break;
  }
  v16 = (void *)(uintptr_t)(off_12165C);
  *(volatile uint32_t *)off_12165C = (16 * v5) | (4 * (uint8_t)a1[42]) | v13 | (v7 << 16) | v14 | 0x40000000;
  while ( (*v16 & 0x40000000) != 0 )
    ;
  return v7;
}


// get_core_rev @ 0x121674
volatile uint32_t * get_core_rev(int a1) {
  int v2; // r1
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r2
  volatile int *v5; // r1
  volatile uint32_t *v6; // r5
  volatile uint32_t *result; // r0
  int v8; // r5
  int v9; // r6
  volatile uint32_t *v10; // r2

  if ( (unsigned int)a1 > HIBYTE(*(volatile uint32_t *)off_12173C) )
    return (volatile uint32_t *)adjust_table_pointers(
                       dword_121744 + 1320 * ((a1 - (HIBYTE(*(volatile uint32_t *)off_12173C) + 1)) / 2),
                       (((uint8_t)a1 - 1 - HIBYTE(*(volatile uint32_t *)off_12173C)) & 1) + 4);
  if ( (unsigned int)a1 > 0xF )
  {
    v8 = dword_121760 + 696 * (uint8_t)(a1 - 16);
    v9 = *(volatile uint8_t *)(v8 + 34);
    result = (volatile uint32_t *)llm_conn_reset_state(v8);
    if ( *(volatile uint8_t *)(dword_121744 + 1320 * v9 + 106) == 2 )
      return result;
    v10 = (void *)(uintptr_t)(off_121748);
    *(volatile uint32_t *)off_121740 = *(volatile uint16_t *)(v8 + 38) | (*(volatile uint16_t *)(v8 + 40) << 16);
    *v10 = *(volatile uint16_t *)(v8 + 42);
  }
  else
  {
    v2 = dword_121744;
    v3 = (void *)(uintptr_t)(off_121748);
    *(volatile uint32_t *)off_121740 = -1;
    *v3 = -1;
    adjust_table_pointers(v2 + 1320 * (a1 >> 2), a1 & 3);
  }
  v4 = (void *)(uintptr_t)(off_12174C);
  v5 = (volatile int *)off_121750;
  v6 = (void *)(uintptr_t)(off_121758);
  result = (void *)(uintptr_t)(off_12175C);
  *(volatile uint32_t *)off_121754 = 0;
  *v6 = 0;
  *v4 = 0;
  *result = 0;
  *v5 = (a1 << 16) | 0x40000000;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}



// delay_and_clear_flag @ 0x121764
int delay_and_clear_flag() {
  unknown_func_12d14c(0x2000000);
  *((volatile uint32_t *)off_121784 + 1) &= ~4u;
  return ke_state_set(0, 0);
}


