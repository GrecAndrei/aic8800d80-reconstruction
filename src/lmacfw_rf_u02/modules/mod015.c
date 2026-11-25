// process_pending_events @ 0x117e5c
int process_pending_events(int a1, int a2, int a3, volatile uint8_t *a4) {
  volatile uint8_t *v4; // r5
  int v9; // r7
  volatile uint32_t *v10; // r0
  volatile uint32_t *v11; // r4
  char v12; // r1
  int v13; // r3
  uint8_t v14; // r1
  int v15; // r2
  int v16; // r3
  volatile int *v17; // r7
  int v18; // r1
  int v19; // r2
  int v20; // r2
  int v21; // r3
  volatile uint32_t *v22; // r3
  int v23; // zf
  int result; // r0
  uint8_t v25; // r2
  uint8_t v26; // r3
  int v27; // r3
  int v28; // r3

  v4 = (volatile uint8_t *)off_118064;
  if ( !*(volatile uint32_t *)off_118064 )
    return 1;
  if ( !*(volatile uint32_t *)(off_118064 + 8) )
    rf_read_status_1((volatile int *)a1);
  v9 = dword_11806C;
  v10 = list_pop_front(off_118064);
  *((volatile uint8_t *)v10 + 94) = a2;
  v11 = v10;
  v10[22] = *(volatile uint32_t *)a1;
  v12 = dword_118070;
  *((volatile uint16_t *)v10 + 46) = *(volatile uint16_t *)(a1 + 4);
  v10[2] = 2631;
  v10[3] = 2627;
  v13 = dword_118078;
  v10[4] = dword_118074;
  v14 = v12 * (((int)v10 - v9) >> 5);
  v10[5] = v13;
  *((volatile uint8_t *)v10 + 97) = 127;
  v10[18] = 0;
  *((volatile uint8_t *)v10 + 95) = v14;
  *((volatile uint8_t *)v10 + 84) = v14;
  if ( a2 == 2 )
  {
    v25 = v4[18];
    if ( !v25 )
    {
      rf_enable_1();
      v25 = v4[18];
    }
    v15 = (uint8_t)(v25 + 1);
    v16 = v4[17] + v15;
    v4[18] = v15;
    if ( v16 > 1 )
      goto LABEL_8;
    goto LABEL_19;
  }
  if ( a2 != 4 )
  {
    if ( a2 )
    {
      v15 = v4[18];
      v16 = v4[17] + v15;
      if ( v16 > 1 )
        goto LABEL_8;
    }
    else
    {
      v26 = v4[17];
      v10[7] = off_1180B0;
      *((volatile uint16_t *)v10 + 50) = 100;
      v10[32] = off_1180B4;
      v15 = v4[18];
      v10[8] = (int)(uintptr_t)(v10);
      v27 = (uint8_t)(v26 + 1);
      v4[17] = v27;
      v16 = v27 + v15;
      v10[33] = (int)(uintptr_t)(v10);
      *((volatile uint8_t *)v10 + 102) = -1;
      if ( v16 > 1 )
        goto LABEL_8;
    }
    goto LABEL_19;
  }
  if ( v4[16] != 255 )
    return 1;
  v15 = v4[18];
  v28 = v4[17];
  v4[16] = v14;
  v16 = v28 + v15;
  if ( v16 > 1 )
    goto LABEL_8;
LABEL_19:
  if ( v15 )
  {
LABEL_8:
    v17 = (void *)(uintptr_t)(off_118080);
    v18 = **(volatile int16_t **)off_11807C;
    v19 = ((volatile uint32_t *)(uintptr_t)off_118080)[1] | 0x100;
    ((volatile uint32_t *)(uintptr_t)off_118080)[1] = v19;
    if ( v18 < 0 && *(volatile uint32_t *)off_1180A0 << 28 )
    {
      flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
      v19 = v17[1];
      v16 = v4[17] + v4[18];
    }
    *(volatile uint32_t *)off_118084 = v19 | *v17;
  }
  if ( v16 == 1 )
    *(volatile uint32_t *)off_11809C |= 1u;
  *a4 = *((volatile uint8_t *)v11 + 95);
  check_kernel_state(dword_118088, v11);
  list_init_1(v11 + 37);
  list_init_1(v11 + 45);
  list_init_1(v11 + 39);
  list_init_1(v11 + 47);
  list_init_1(v11 + 41);
  list_init_1(v11 + 49);
  list_init_1(v11 + 43);
  list_init_1(v11 + 51);
  list_init_1(v11 + 53);
  v20 = v4[18];
  v21 = v4[17] + v20;
  *(volatile uint32_t *)off_11808C = 0;
  if ( v21 <= 1 )
  {
    btcoex_check_state();
    v20 = v4[18];
    v21 = v4[17] + v20;
  }
  check_interrupt_flag(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v21, v20, a2, a3, *a4);
  v22 = (volatile uint32_t *)(v4[18] + v4[17]);
  v23 = v22 == (volatile uint32_t *)1;
  if ( v22 == (volatile uint32_t *)1 )
    v22 = (void *)(uintptr_t)(off_118098);
  result = 0;
  if ( v23 )
    *v22 = 0;
  return result;
}


// link_context_by_index @ 0x1180b8
int link_context_by_index(int a1) {
  int v2; // r8
  int v3; // r9
  int v4; // r3
  int v5; // r5
  int v6; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r4
  void *v10; // r5
  int v11; // r3
  volatile int16_t **v13; // r11
  volatile int *v14; // r10
  int v15; // r1
  unsigned int v16; // r3
  int v17; // r2
  unsigned int v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // [sp+0h] [bp-Ch]
  int v22; // [sp+4h] [bp-8h]

  v2 = dword_1182BC;
  v3 = dword_1182BC + 224 * a1;
  check_kernel_state_alt2(dword_118290, (volatile uint32_t *)v3);
  v4 = *(volatile uint8_t *)(v3 + 94);
  v5 = 224 * a1;
  if ( v4 == 2 )
  {
    v6 = off_118294;
    v7 = (uint8_t)(*(volatile uint8_t *)(off_118294 + 0x12) - 1);
    *(volatile uint8_t *)(off_118294 + 0x12) = v7;
    if ( v7 )
    {
      if ( *(volatile uint8_t *)(v6 + 0x11) + v7 != 1 )
        goto LABEL_7;
      goto LABEL_12;
    }
    rf_disable();
LABEL_4:
    v7 = *(volatile uint8_t *)(v6 + 0x12);
    v8 = *(volatile uint8_t *)(v6 + 0x11) + v7;
    if ( v8 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  if ( v4 == 4 )
  {
    if ( sys_ready_check() )
      ctrl_bit3_set(0);
    v6 = off_118294;
    v7 = *(volatile uint8_t *)(off_118294 + 0x12);
    v8 = *(volatile uint8_t *)(off_118294 + 0x11) + v7;
    *(volatile uint8_t *)(off_118294 + 0x10) = -1;
    if ( v8 != 1 )
      goto LABEL_5;
    goto LABEL_12;
  }
  v6 = off_118294;
  if ( *(volatile uint8_t *)(v3 + 94) )
    goto LABEL_4;
  v7 = *(volatile uint8_t *)(off_118294 + 0x12);
  v19 = (uint8_t)(*(volatile uint8_t *)(off_118294 + 0x11) - 1);
  *(volatile uint8_t *)(off_118294 + 0x11) = v19;
  v8 = v19 + v7;
  if ( v8 != 1 )
    goto LABEL_5;
LABEL_12:
  v13 = (volatile int16_t **)off_1182C0;
  v14 = (void *)(uintptr_t)(off_1182C4);
  v15 = **(volatile int16_t **)off_1182C0;
  v16 = ((volatile uint32_t *)(uintptr_t)off_1182C4)[1] & 0xFFFFFFEF;
  ((volatile uint32_t *)(uintptr_t)off_1182C4)[1] = v16;
  if ( v15 < 0 && *(volatile uint32_t *)off_1182B0 << 28 )
  {
    flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
    v20 = *(volatile uint8_t *)(v6 + 0x12);
    v8 = *(volatile uint8_t *)(v6 + 0x11) + v20;
    *(volatile uint32_t *)off_1182AC = *v14 | v14[1];
    if ( v8 != 1 )
      goto LABEL_5;
    if ( v20 )
      goto LABEL_7;
  }
  else
  {
    *(volatile uint32_t *)off_1182AC = v16 | *v14;
    if ( v7 )
      goto LABEL_7;
  }
  v17 = **v13;
  v18 = v14[1] & 0xFFFFFEFF;
  v14[1] = v18;
  if ( v17 >= 0 )
  {
    *(volatile uint32_t *)off_1182AC = v18 | *v14;
    goto LABEL_7;
  }
  if ( !(*(volatile uint32_t *)off_1182B0 << 28) )
  {
    *(volatile uint32_t *)off_1182AC = v18 | *v14;
    goto LABEL_7;
  }
  flash_cmd_exec((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
  v8 = *(volatile uint8_t *)(v6 + 0x11) + *(volatile uint8_t *)(v6 + 0x12);
  *(volatile uint32_t *)off_1182AC = *v14 | v14[1];
LABEL_5:
  if ( !v8 )
    *(volatile uint32_t *)off_118298 = 0;
LABEL_7:
  ke_exit_critical((int)(uintptr_t)((volatile uint32_t *)(v5 + 24 + v2)));
  ke_exit_critical((int)(uintptr_t)((volatile uint32_t *)(v5 + 48 + v2)));
  tx_slot_get_busy(*(volatile uint8_t *)(v2 + 224 * a1 + 95));
  *(volatile uint32_t *)off_11829C = 0;
  if ( *(volatile uint8_t *)(v6 + 0x12) + *(volatile uint8_t *)(v6 + 0x11) <= 1 )
    btcoex_check_state();
  memset((volatile int *)v3, 0, 0xE0u);
  v22 = a1;
  v9 = v2 + 224 * a1;
  v10 = (void *)(uintptr_t)(off_1182A0);
  v21 = *(volatile uint8_t *)(v6 + 0x12);
  v11 = v21 + *(volatile uint8_t *)(v6 + 0x11);
  *(volatile uint32_t *)(v9 + 56) = v3;
  *(volatile uint8_t *)(v9 + 94) = 5;
  *(volatile uint8_t *)(v9 + 97) = 127;
  *(volatile uint32_t *)(v9 + 52) = (int)(uintptr_t)(v10);
  check_interrupt_flag(256, "%s:%d,%d,%d\r\n", aVifMgmtUnregis, v11, v21, v22);
  return check_kernel_state(off_118294, (volatile uint32_t *)v3);
}


// check_link_id @ 0x1182c8
int check_link_id(int result) {
  int v1; // r4
  int v2; // r5
  int v3; // r6

  v1 = dword_1182F0;
  v2 = result;
  v3 = dword_1182F0 + 608;
  do
  {
    if ( *(volatile uint8_t *)(v1 + 32) == *(volatile uint8_t *)(v2 + 95) )
      result = rx_queue_flush(v2, v1, 0);
    v1 += 152;
  }
  while ( v3 != v1 );
  return result;
}



// find_link_in_list @ 0x1182f4
int find_link_in_list() {
  volatile uint32_t *i; // r4
  int result; // r0

  for ( i = *((volatile uint32_t **)off_11830C + 2); i; i = (volatile uint32_t *)*i )
    result = check_link_id((int)i);
  return result;
}



// copy_patch_region @ 0x118310
int copy_patch_region(int a1) {
  return ke_enter_critical((void *)(uintptr_t)(a1 + 48), *((volatile uint32_t *)off_118320 + 4) + 10000);
}



// setup_packet_buffer @ 0x118324
int setup_packet_buffer(int a1) {
  int result; // r0

  result = ke_exit_critical(a1 + 48);
  if ( *(volatile uint32_t *)(a1 + 72) )
    return bt_link_rx_check(a1);
  return result;
}



// write_register_low16 @ 0x118340
void write_register_low16(int a1, int a2) {
  *(volatile uint32_t *)off_118350 = a2 | (HIWORD(*(volatile uint32_t *)off_118350) << 16);
}



// clear_bb_irq @ 0x118354
void clear_bb_irq() {
  int v0; // r3

  v0 = *((volatile uint8_t *)off_11836C + 18) + *((volatile uint8_t *)off_11836C + 17);
  *(volatile uint32_t *)off_118370 = 0;
  if ( v0 <= 1 )
    btcoex_check_state();
}



// reset_link_status @ 0x118374
int reset_link_status(volatile uint8_t *a1) {
  volatile uint32_t *v1; // r3
  volatile int *v2; // r3
  int result; // r0

  v1 = (void *)(uintptr_t)(off_11839C);
  *a1 = 0;
  v2 = (volatile int *)v1[2];
  if ( !v2 )
    return 0;
  result = 0;
  do
  {
    if ( !*((volatile uint8_t *)v2 + 94) )
    {
      if ( *((volatile uint8_t *)v2 + 96) )
        ++result;
    }
    v2 = (volatile int *)*v2;
  }
  while ( v2 );
  return result;
}



// poll_hw_status_1 @ 0x1183a0
int poll_hw_status_1() {
  int result; // r0
  volatile uint32_t *v1; // r1
  volatile uint16_t *v2; // r3
  unsigned int v3; // r2
  int16_t v4; // r2
  volatile uint32_t *v5; // r1
  int16_t v6; // r2
  volatile uint32_t *v7; // r1

  if ( (uint16_t)(*(volatile uint32_t *)off_118428 >> 12) && (uint16_t)(*(volatile uint32_t *)off_118428 >> 12) <= 0x96u )
    result = (uint16_t)(*(volatile uint32_t *)off_118428 >> 12);
  else
    result = 150;
  v1 = (void *)(uintptr_t)(off_11842C);
  v2 = (void *)(uintptr_t)(off_118430);
  v3 = *(volatile uint32_t *)off_11842C;
  *((volatile uint16_t *)off_118430 + 4) = result;
  if ( (uint16_t)(v3 >> 12) && (uint16_t)(*v1 >> 12) <= 0x96u )
    v4 = *v1 >> 12;
  else
    v4 = 150;
  v5 = (void *)(uintptr_t)(off_118434);
  v2[5] = v4;
  if ( (uint16_t)(*v5 >> 12) && (uint16_t)(*v5 >> 12) <= 0x96u )
    v6 = *v5 >> 12;
  else
    v6 = 150;
  v7 = (void *)(uintptr_t)(off_118438);
  v2[6] = v6;
  if ( (uint16_t)(*v7 >> 12) && (uint16_t)(*v7 >> 12) <= 0x96u )
    v2[7] = *v7 >> 12;
  else
    v2[7] = 150;
  return result;
}



// init_link_manager @ 0x11843c
int init_link_manager() {
  volatile uint16_t *v0; // r4
  int v1; // r3
  volatile int16_t *v2; // r1
  int v3; // r1

  v0 = (void *)(uintptr_t)(off_118494);
  memset((volatile int *)off_118494, 0, 0x20u);
  v1 = dword_11849C;
  v2 = *(volatile int16_t **)off_118498;
  *(volatile uint32_t *)v0 = dword_11849C;
  v0[8] = 0;
  v3 = *v2;
  *((volatile uint32_t *)v0 + 1) = 0;
  if ( v3 < 0 && *(volatile uint32_t *)off_1184A4 << 28 )
  {
    flash_cmd_exec(dword_1184AC, dword_1184A8, 472);
    *(volatile uint32_t *)off_1184A0 = *(volatile uint32_t *)v0 | *((volatile uint32_t *)v0 + 1);
  }
  else
  {
    *(volatile uint32_t *)off_1184A0 = v1;
  }
  return poll_hw_status_1();
}



// rf_clock_enable @ 0x1184b0
volatile uint32_t *rf_clock_enable() {
  volatile int *v0; // r4
  int v1; // r0
  int v2; // r0
  volatile uint32_t *v3; // r0
  volatile unsigned int *v4; // r1
  volatile unsigned int *v5; // r3
  volatile int *v6; // r5
  volatile int *v7; // r6
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

  v0 = (volatile int *)off_1185DC;
  *(volatile uint32_t *)off_1185D8 |= 0x10u;
  v1 = noop();
  v2 = ((int (*)())nullsub_2)(v1);
  ((int (*)())nullsub_3)(v2);
  v3 = (void *)(uintptr_t)(off_1185E0);
  v4 = (volatile unsigned int *)off_1185E4;
  v5 = (volatile unsigned int *)off_1185E8;
  v6 = (volatile int *)off_1185EC;
  v7 = (volatile int *)off_1185F0;
  *v0 = *v0 & 0x3FFFFF | 0x2800000;
  v8 = dword_1185F4;
  *v3 |= 0x8000000u;
  *v4 = *v4 & 0xFF0FFFFF | 0x200000;
  *v5 = *v5 & 0xFFFFF8FF | 0x600;
  *v5 = *v5 & 0xFFFFC7FF | 0x2000;
  *v5 = *v5 & 0xFFFE3FFF | 0xC000;
  *v5 |= 0xE0000u;
  *v6 = *v6 & v8 | 0x5DC;
  v3[1] = v3[1] & v8 | 0xBB8;
  *(v4 - 205) = *(v4 - 205) & 0xFFFF00FF | 0xDA00;
  v9 = *v7;
  v10 = *(volatile uint8_t *)(*v7 + 2);
  if ( (v10 & 0x10) != 0 )
    v3[16] &= ~0x80000000;
  else
    *(volatile uint32_t *)off_118620 |= 0x80000000;
  v11 = (v10 & 1) == 0;
  v12 = *(volatile uint32_t *)off_1185F8;
  if ( v11 )
    v13 = v12 & 0xFFFBFFFF;
  else
    v13 = v12 | 0x40000;
  *(volatile uint32_t *)off_1185F8 = v13;
  v14 = (void *)(uintptr_t)(off_1185FC);
  *(volatile uint32_t *)off_1185FC = dword_118600;
  if ( *(volatile uint8_t *)(v9 + 1) )
    *(v14 - 215) |= 0x40u;
  v15 = (void *)(uintptr_t)(off_118608);
  v16 = (void *)(uintptr_t)(off_11860C);
  v17 = (void *)(uintptr_t)(off_118610);
  result = (void *)(uintptr_t)(off_118614);
  v19 = (volatile uint8_t **)off_118618;
  *(volatile uint32_t *)off_118604 &= ~1u;
  *v15 = 0xFFFF;
  *v16 = -1;
  *v17 = 0xFFFF;
  *result = -1;
  v20 = **v19;
  if ( (unsigned int)(v20 - 1) <= 1 || v20 == 4 )
    *(volatile uint32_t *)off_11861C |= 0x80000000;
  return result;
}



// start_firmware @ 0x118624
volatile uint32_t *start_firmware() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0

  v0 = (void *)(uintptr_t)(off_118670);
  if ( !*((volatile uint8_t *)off_118670 + 2) )
    rf_cmd_strobe();
  init_link_manager();
  btcoex_reset_context();
  v1 = (int)(uintptr_t)(init_table_185d40());
  init_three_entries(v1);
  ble_ll_init();
  if ( v0[2] )
    v2 = timestamp_add();
  else
    v2 = call_sub_117410_then_11683c();
  v3 = log_18630c(v2);
  v4 = ke_timer_flush(v3);
  v5 = env_reset(v4);
  log_two_strings(v5);
  rf_init();
  return rf_clock_enable();
}



// send_acl_packet @ 0x118674
int send_acl_packet(int a1, int a2, int a3, volatile uint32_t *a4, int a5, int a6) {
  unsigned int v7; // r4
  uint64_t v8; // r10
  int v10; // r5
  int v11; // r3
  volatile char *v12; // r2
  volatile int *v13; // r9
  volatile int *v14; // r0
  volatile uint32_t *v15; // r2
  volatile int16_t **v16; // r3
  int v17; // r8
  volatile char *v18; // r1
  volatile int *v19; // r0
  volatile uint32_t *v20; // r1
  int v21; // r6
  int v22; // r8
  uint64_t v23; // kr08_8
  int v24; // cf
  int v25; // r4
  uint64_t v26; // r0
  int v27; // r3
  uint64_t v28; // r0
  int v29; // r2
  volatile unsigned int v30; // r4
  int v31; // r4
  int v32; // r0
  unsigned int v33; // r3
  int v34; // r0
  volatile unsigned int v35; // r3
  int result; // r0
  uint64_t v37; // [sp+0h] [bp-1Ch]
  int v38; // [sp+Ch] [bp-10h]
  unsigned int v39; // [sp+10h] [bp-Ch]

  v7 = *(volatile uint32_t *)(a3 + 32);
  v39 = *(volatile uint32_t *)(a3 + 36);
  v8 = *(volatile uint64_t *)(a1 + 24);
  v10 = *(volatile uint16_t *)(a1 + 32) << 10;
  if ( a6 )
  {
    v11 = *(volatile uint8_t *)(a6 + 2);
    if ( !*(volatile uint8_t *)(a6 + 2) )
      v11 = *(volatile uint8_t *)(a6 + 3);
    v38 = v10 * v11;
    if ( !(*(volatile uint8_t *)(a3 + 40) << 28) )
      goto LABEL_5;
LABEL_24:
    v21 = 500;
    v22 = 0;
    goto LABEL_14;
  }
  v38 = *(volatile uint16_t *)(a1 + 32) << 10;
  if ( *(volatile uint8_t *)(a3 + 40) << 28 )
    goto LABEL_24;
LABEL_5:
  v12 = (volatile char *)off_11889C;
  v13 = (volatile int *)off_1188C0;
  v14 = (volatile int *)off_1188A0;
  *(volatile uint32_t *)off_11889C = *((volatile uint8_t *)off_1188C0 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                        | *(volatile uint32_t *)off_11889C & 0xFFFFFF80;
  v15 = (void *)(v12 + 8);
  *v14 = a2 | (*(volatile uint8_t *)(a3 + 40) >> 7 << 20);
  *v15 = 0x80000000;
  __dsb(0xFu);
  while ( (*v15 & 0xC0000000) != 0x40000000 )
    ;
  v16 = (volatile int16_t **)off_1188A4;
  if ( **(volatile int16_t **)off_1188A4 >= 0 || (*v15 & 0x40000000) != 0 )
  {
    v17 = (uint16_t)*(volatile uint32_t *)off_1188A8;
  }
  else
  {
    ke_int_lock_1((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
    v17 = 500;
    v16 = (volatile int16_t **)off_1188A4;
  }
  if ( !(*(volatile uint8_t *)(a3 + 40) << 28) )
  {
    v18 = (volatile char *)off_11889C;
    v19 = (volatile int *)off_1188A0;
    *(volatile uint32_t *)off_11889C = *((volatile uint8_t *)v13 + (*(volatile uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(volatile uint32_t *)off_11889C & 0xFFFFFF80;
    v20 = (void *)(v18 + 8);
    *v19 = (*(volatile uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
    *v20 = 0x80000000;
    __dsb(0xFu);
    while ( (*v20 & 0xC0000000) != 0x40000000 )
      ;
    if ( **v16 >= 0 || (*v20 & 0x40000000) != 0 )
    {
      v21 = (uint16_t)*(volatile uint32_t *)off_1188A8;
      v22 = v17 - v21;
      goto LABEL_14;
    }
    ke_int_lock_1((int)aNxmacTimeOnAir, (int)aHalMachwRxBcnD, 430);
  }
  v22 = v17 - 500;
  v21 = 500;
LABEL_14:
  v23 = v8 - __PAIR64__(v39, v7);
  v24 = __CFADD__(v8 - v7, v22);
  v25 = v8 - v7 + v22;
  a4[10] = v25;
  a4[11] = HIDWORD(v23) + v24;
  v26 = util_is_zero(v8, v10);
  v37 = v8 - (unsigned int)v21;
  v27 = v26 * (v10 >> 31) + v10 * HIDWORD(v26);
  v28 = (unsigned int)v26 * (uint64_t)(unsigned int)v10;
  v28 = (v28 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v28 >> 32) & 0xFFFFFFFFu) + (uint32_t)(v27))) << 32;;
  if ( v28 < v37 )
    v37 = (v37 & ~0xFFFFFFFFull) | ((uint32_t)(v28) & 0xFFFFFFFFu);
  v29 = v37 + v38;
  if ( (*(volatile uint32_t *)off_1188B0 & 0x2000000) != 0 )
    v29 -= v25;
  v30 = (*(volatile uint32_t *)0x40501010u);
  v31 = v30 - *(volatile uint32_t *)off_1188B4 + v29 - 400;
  v32 = os_get_tick_hz();
  v33 = v31 - (*(volatile uint32_t *)0x40501010u) - 4300;
  if ( (int)(v33 - v32) < 0 )
    v31 += v10;
  v34 = os_get_tick_hz();
  v35 = (*(volatile uint32_t *)0x40501010u);
  result = v31 - v35 - 4300 - v34;
  if ( result >= 0 && a4[9] != v31 )
  {
    ke_enter_critical(a4 + 6, v31);
    return bt_link_tx_check((int)a4);
  }
  return result;
}


// chip_id_is_one @ 0x1188c4
int chip_id_is_one() {
  if ( flash_write_byte(0) != 1 )
    return flash_erase_sector(0, 0);
  *(volatile uint32_t *)off_1188F0 = 48;
  return flash_erase_sector(0, 1);
}


// write_bb_control @ 0x1188f4
int write_bb_control() {
  *(volatile uint32_t *)off_118904 = 48;
  return flash_erase_sector(0, 1);
}


// link_context_by_handle @ 0x118908
int link_context_by_handle(int result) {
  int v1; // r5
  int v2; // r4
  unsigned int v3; // r3
  volatile uint8_t *v4; // r2
  unsigned int v5; // r2
  int v6; // [sp+4h] [bp-14h]

  if ( *(volatile uint8_t *)(result + 96) )
  {
    v1 = *(volatile uint32_t *)(result + 36);
    v2 = result;
    v6 = *(volatile uint32_t *)(dword_118980 + 152 * *(volatile uint8_t *)(result + 102) + 8) + v1;
    ke_enter_critical((void *)(uintptr_t)(result + 24), v6);
    copy_patch_region(v2);
    result = ((int (*)())ke_event_process)(v2, v1, v6);
    if ( !result )
    {
      v3 = (uint8_t)(*(volatile uint8_t *)(v2 + 116) + 1);
      v4 = *(volatile uint8_t **)off_118984;
      *(volatile uint8_t *)(v2 + 116) = v3;
      v5 = *v4;
      if ( v3 > v5 )
      {
        return rate_index_lookup_fast(*(volatile uint8_t *)(v2 + 102), dword_118988, v2);
      }
      else if ( v3 == v5 )
      {
        return rf_get_status_1(v2);
      }
    }
  }
  return result;
}



// update_rx_credits @ 0x11898c
int update_rx_credits(int a1, int a2) {
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

  v2 = dword_118A40;
  v3 = (void *)(uintptr_t)(off_118A44);
  v4 = (void *)(uintptr_t)(off_118A58);
  v5 = (void *)(uintptr_t)(off_118A5C);
  v6 = (void *)(uintptr_t)(off_118A48);
  v7 = (volatile uint16_t *)(dword_118A40 + 152 * a1);
  *(volatile uint32_t *)off_118A44 = v7[18] | (v7[19] << 16);
  v8 = (void *)(uintptr_t)(off_118A4C);
  v3[1] = v7[20];
  v9 = (volatile int *)off_118A50;
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
      v12 = (void *)(uintptr_t)(off_118A54);
      v13 = (void *)(uintptr_t)(off_118A50);
      *(volatile uint32_t *)off_118A44 = -1;
      *v12 = -1;
      *v9 = ((uint8_t)v11 << 16) | 0x40000000;
      while ( (*v13 & 0x40000000) != 0 )
        ;
      v14 = (volatile uint16_t *)(v2 + 152 * a1);
      *(volatile uint32_t *)off_118A44 = v14[18] | (v14[19] << 16);
      *(volatile uint32_t *)off_118A54 = v14[20];
    }
  }
  v15 = (void *)(uintptr_t)(off_118A50);
  *(volatile uint32_t *)off_118A50 = (16 * a2) | (v10 << 16) | 0x40000002;
  while ( (*v15 & 0x40000000) != 0 )
    ;
  return (uint8_t)(a1 + 16);
}



// handle_hci_event @ 0x118a60
int handle_hci_event(volatile char *a1) {
  unsigned int v1; // r7
  int v2; // r5
  int v4; // r1
  volatile uint32_t *v5; // r3
  int v6; // r2
  int v7; // r6
  volatile uint32_t *v8; // r3
  volatile uint8_t *v9; // r3
  volatile uint32_t *v10; // r3
  int v11; // r0
  int v12; // r1
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r2
  volatile uint32_t *v16; // r2
  char v17; // r6
  volatile uint32_t *v18; // r3
  volatile uint32_t *v19; // r3
  volatile uint32_t *v20; // r3
  volatile uint32_t *v21; // r3
  volatile uint32_t *v22; // r3
  struct __attribute__((packed)) { int v23; // [sp+0h] [bp-14h] BYREF
  uint16_t v24; // [sp+4h] [bp-10h]
  char _pad2[2]; char a1a[4]; // [sp+8h] [bp-Ch] BYREF
  uint16_t v26; // [sp+Ch] [bp-8h]
  } _frame;
  v1 = (uint8_t)a1[1];
  v2 = (uint8_t)a1[41];
  if ( v1 == 255 )
  {
    v16 = (void *)(uintptr_t)(off_118C60);
    v17 = *a1;
    *(volatile uint32_t *)off_118C5C = -1;
    *v16 = -1;
    v7 = (uint8_t)(v17 + 4 * v2);
    check_interrupt_flag(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
  }
  else
  {
    if ( **(volatile int16_t **)off_118C50 < 0 && v1 > 3 )
      flash_ctrl_init((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    check_interrupt_flag(256, "add ptk:%d,%d\r\n", v1, (uint8_t)a1[40]);
    v4 = ((volatile uint32_t *)(uintptr_t)off_118C58)[1];
    _frame.v23 = ((volatile uint32_t *)(uintptr_t)off_118C58)[0];
    _frame.v24 = v4;
    memcpy(_frame.a1a, (volatile char *)&_frame.v23, 6u);
    v5 = (void *)(uintptr_t)(off_118C60);
    v6 = _frame.v26;
    *(volatile uint32_t *)off_118C5C = *(volatile uint32_t *)_frame.a1a;
    v7 = (uint8_t)(v1 + 16);
    *v5 = v6;
  }
  switch ( a1[40] )
  {
    case 0:
      v18 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v18[1] = *((volatile uint32_t *)a1 + 3);
      v18[2] = *((volatile uint32_t *)a1 + 4);
      v18[3] = *((volatile uint32_t *)a1 + 5);
      v11 = 256;
      v12 = 0;
      break;
    case 1:
      v8 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v8[1] = *((volatile uint32_t *)a1 + 3);
      v8[2] = *((volatile uint32_t *)a1 + 4);
      v9 = *(volatile uint8_t **)off_118C70;
      *(volatile uint32_t *)off_118C74 = *((volatile uint32_t *)a1 + 5);
      if ( (*v9 & 1) != 0 )
      {
        v10 = (void *)(uintptr_t)(off_118C78);
        *(volatile uint32_t *)off_118C78 = *((volatile uint32_t *)a1 + 6);
        v10[1] = *((volatile uint32_t *)a1 + 7);
        v10[2] = *((volatile uint32_t *)a1 + 8);
        v10[3] = *((volatile uint32_t *)a1 + 9);
      }
      else
      {
        *(volatile uint32_t *)off_118C84 &= ~1u;
      }
      v11 = 512;
      v12 = 4096;
      break;
    case 2:
      v13 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v13[1] = *((volatile uint32_t *)a1 + 3);
      v13[2] = *((volatile uint32_t *)a1 + 4);
      v13[3] = *((volatile uint32_t *)a1 + 5);
      v11 = 768;
      v12 = 0;
      break;
    case 3:
      v11 = 256;
      v12 = 4096;
      goto LABEL_21;
    case 4:
      v22 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v22[1] = *((volatile uint32_t *)a1 + 3);
      v22[2] = *((volatile uint32_t *)a1 + 4);
      v22[3] = *((volatile uint32_t *)a1 + 5);
      v11 = 1024;
      v12 = 4096;
      goto LABEL_19;
    case 6:
      v11 = 1280;
      v12 = 0;
      goto LABEL_21;
    case 7:
      v11 = 1280;
      goto LABEL_18;
    case 8:
      v11 = 768;
LABEL_18:
      v19 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v19[1] = *((volatile uint32_t *)a1 + 3);
      v19[2] = *((volatile uint32_t *)a1 + 4);
      v19[3] = *((volatile uint32_t *)a1 + 5);
      v12 = 0x2000;
LABEL_19:
      v20 = (void *)(uintptr_t)(off_118C78);
      *(volatile uint32_t *)off_118C78 = *((volatile uint32_t *)a1 + 6);
      v20[1] = *((volatile uint32_t *)a1 + 7);
      v20[2] = *((volatile uint32_t *)a1 + 8);
      v20[3] = *((volatile uint32_t *)a1 + 9);
      break;
    default:
      if ( **(volatile int16_t **)off_118C50 < 0 )
        flash_ctrl_init(off_118C8C, (int)aMmKeyRamParamG, 159);
      v11 = 0;
      v12 = 4096;
LABEL_21:
      v21 = (void *)(uintptr_t)(off_118C6C);
      *(volatile uint32_t *)off_118C6C = *((volatile uint32_t *)a1 + 2);
      v21[1] = *((volatile uint32_t *)a1 + 3);
      v21[2] = *((volatile uint32_t *)a1 + 4);
      v21[3] = *((volatile uint32_t *)a1 + 5);
      break;
  }
  v14 = (void *)(uintptr_t)(off_118C7C);
  *(volatile uint32_t *)off_118C7C = (16 * v2) | (4 * (uint8_t)a1[42]) | v11 | (v7 << 16) | v12 | 0x40000000;
  while ( (*v14 & 0x40000000) != 0 )
    ;
  return v7;
}


// convert_handle_index @ 0x118c90
unsigned int convert_handle_index(unsigned int result) {
  int v1; // r3
  volatile uint32_t *v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r2
  volatile unsigned int *v5; // r1
  volatile uint32_t *v6; // r5
  volatile uint32_t *v7; // r4

  if ( result <= 0xF )
  {
    v3 = (void *)(uintptr_t)(off_118D10);
    *(volatile uint32_t *)off_118D0C = -1;
    *v3 = -1;
  }
  else
  {
    v1 = dword_118D04 + 152 * (uint8_t)(result - 16);
    if ( *(volatile uint8_t *)(dword_118D08 + 224 * *(volatile uint8_t *)(v1 + 32) + 94) == 2 )
      return result;
    v2 = (void *)(uintptr_t)(off_118D10);
    *(volatile uint32_t *)off_118D0C = *(volatile uint16_t *)(v1 + 36) | (*(volatile uint16_t *)(v1 + 38) << 16);
    *v2 = *(volatile uint16_t *)(v1 + 40);
  }
  v4 = (void *)(uintptr_t)(off_118D14);
  v5 = (volatile unsigned int *)off_118D18;
  v6 = (void *)(uintptr_t)(off_118D20);
  v7 = (void *)(uintptr_t)(off_118D24);
  result = (result << 16) | 0x40000000;
  *(volatile uint32_t *)off_118D1C = 0;
  *v6 = 0;
  *v4 = 0;
  *v7 = 0;
  *v5 = result;
  while ( (*v5 & 0x40000000) != 0 )
    ;
  return result;
}



// enable_irq_2000000 @ 0x118d28
int enable_irq_2000000() {
  enter_critical_section_1(0x2000000);
  return flash_erase_sector(0, 0);
}


