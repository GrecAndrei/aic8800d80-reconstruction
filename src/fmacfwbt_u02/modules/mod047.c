// msg_alloc_410 @ 0x12ef48
int msg_alloc_410(int a1, int a2, int a3, int a4) {
  int v5; // r0
  int v6; // r1
  volatile uint32_t *v7; // r4
  volatile uint32_t *v9; // r2
  volatile uint8_t *v10; // r0
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r3

  v5 = bt_buf_alloc(1040, a4, a3, 4);
  v6 = *(volatile uint16_t *)(a2 + 4);
  v7 = (volatile uint32_t *)v5;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_12EFC0)[44]) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v9 = (void *)(uintptr_t)(off_12EFCC);
    *(volatile uint32_t *)off_12EFC8 |= 0x2000000u;
    v10 = (void *)(uintptr_t)(off_12EFD0);
    v9[14] |= 0x10u;
    *v10 = 1;
  }
  if ( v6 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_12EFCC);
    *((volatile uint32_t *)off_12EFCC + 18) = *(volatile uint32_t *)a2;
    v11[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v12 = (void *)(uintptr_t)(off_12EFCC);
    *((volatile uint32_t *)off_12EFCC + 19) = *(volatile uint32_t *)a2;
    v12[75] = 128;
  }
LABEL_5:
  *v7 = 0;
  ke_event_schedule_1("\x9D\x81""DBG: Boot NPC %d\n", v6);
  hci_evt_send((int)v7);
  return 0;
}


// msg_alloc_40a_zero @ 0x12efd4
int msg_alloc_40a_zero(int a1, int a2, int16_t a3, int16_t a4) {
  volatile uint32_t *v4; // r0

  v4 = (volatile uint32_t *)bt_buf_alloc(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  hci_evt_send((int)v4);
  return 0;
}



// msg_alloc_424 @ 0x12eff4
int msg_alloc_424(int a1, volatile char **a2, int a3, int a4) {
  int v5; // r0
  volatile char *v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = bt_buf_alloc(1060, a4, a3, 1032);
  v7 = (unsigned int)a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v6);
  *(volatile uint32_t *)(v5 + 4) = v7;
  v8 = v5;
  memcpy((volatile char *)(v5 + 8), v6, v7);
  ke_event_schedule_1(asc_14AE60, *a2, &(*a2)[*(volatile uint32_t *)(v8 + 4)], *(volatile uint32_t *)(v8 + 8));
  hci_evt_send(v8);
  return 0;
}


// msg_alloc_40c @ 0x12f03c
int msg_alloc_40c(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint32_t *v5; // r5
  volatile char *v6; // r0
  int v7; // zf
  unsigned int v8; // r2

  v5 = (volatile uint32_t *)bt_buf_alloc(1036, a4, a3, 4);
  v6 = (volatile char *)*a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  memcpy(v6, (volatile char *)a2 + 8, v8);
  ke_event_schedule_1(asc_14AEA4, *a2, a2[1] + *a2, a2[2], *v5);
  hci_evt_send((int)v5);
  return 0;
}


// msg_alloc_412 @ 0x12f094
int msg_alloc_412(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint64_t *v5; // r0
  int v6; // r5
  volatile uint32_t *v7; // r0
  uint64_t v8; // r2
  int v9; // r0

  v5 = (volatile uint64_t *)bt_buf_alloc(1042, a4, a3, 8);
  v6 = (int)v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12F148 - 1 <= 1 )
  {
    v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
    if ( *a2 == dword_12F150 || (uint32_t)v8 == dword_12F150 - 36184 )
    {
      *(volatile uint32_t *)v8 ^= (a2[2] ^ *(volatile uint32_t *)v8) & a2[1];
      v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
      v9 = HIDWORD(v8);
      *(volatile uint64_t *)v6 = v8;
    }
    else
    {
      v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
      *v5 = v8;
      v9 = HIDWORD(v8);
    }
  }
  else
  {
    v7 = (volatile uint32_t *)*a2;
    if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      atomic_reg_write((int)v7, a2[2], a2[1], 1);
      v9 = atomic_reg_read(*a2, 1);
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
    }
    else
    {
      *v7 ^= (a2[2] ^ *v7) & a2[1];
      v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
      v9 = *(volatile uint32_t *)*a2;
    }
    *(volatile uint32_t *)(v6 + 4) = v9;
    v8 = (v8 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(a2[2]) << 32);
    *(volatile uint32_t *)v6 = v8;
  }
  ke_event_schedule_1(
    "\x9D\x81""DBG: Writing memory with mask:0x%08x, data:0x%08x / %d: [0x%08x] = 0x%08x / %d\n",
    a2[1],
    HIDWORD(v8),
    HIDWORD(v8),
    (uint32_t)v8,
    v9,
    v9);
  hci_evt_send(v6);
  return 0;
}


// msg_alloc_401 @ 0x12f154
int msg_alloc_401(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v5; // r0
  volatile int *v6; // r1
  volatile int **v7; // r4
  int v8; // r3
  int v10; // r0

  v5 = bt_buf_alloc(1025, a4, a3, 8);
  v6 = (volatile int *)*a2;
  v7 = (volatile int **)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v10 = atomic_reg_read(*a2, 1);
    v6 = (volatile int *)*a2;
    v7[1] = (volatile int *)v10;
    v8 = v10;
  }
  else
  {
    v8 = *v6;
    *(volatile uint32_t *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  ke_event_schedule_1("\x9D\x81""DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", v6, v8, v8);
  hci_evt_send((int)v7);
  return 0;
}


// ke_event_send_a @ 0x12f1a0
int ke_event_send_a(int a1, volatile uint32_t *a2, int a3, int a4) {
  ke_event_schedule_1("\x9D\x81""DBG: Setting severity filter: 0x%08x\n", *a2);
  *((volatile uint32_t *)off_12F1D0 + 1) = *a2;
  hci_evt_alloc_send(1031, a4, a3);
  return 0;
}


// ke_event_send_b @ 0x12f1d4
int ke_event_send_b(int a1, volatile uint32_t *a2, int a3, int a4) {
  ke_event_schedule_1("\x9D\x81""DBG: Setting module filter: 0x%08x\n", *a2);
  *(volatile uint32_t *)off_12F204 = *a2;
  hci_evt_alloc_send(1029, a4, a3);
  return 0;
}


// msg_alloc_403 @ 0x12f208
int msg_alloc_403(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile int *v5; // r0
  volatile int *v6; // r5
  volatile uint32_t *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (volatile int *)bt_buf_alloc(1027, a4, a3, 8);
  v6 = v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12F280 - 1 <= 1 )
  {
    v10 = a2[1];
    v8 = *a2;
    *(volatile uint64_t *)v5 = *(volatile uint64_t *)a2;
    v9 = v10;
  }
  else
  {
    v7 = (volatile uint32_t *)*a2;
    if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      atomic_reg_read_alt((int)v7, a2[1], 1);
      v9 = atomic_reg_read(*a2, 1);
      v8 = *a2;
    }
    else
    {
      *v7 = a2[1];
      v8 = *a2;
      v9 = *(volatile uint32_t *)*a2;
    }
    v6[1] = v9;
    v10 = a2[1];
    *v6 = v8;
  }
  ke_event_schedule_1("\x9D\x81""DBG: Writing memory with 0x%08x / %d: [0x%08x] = 0x%08x / %d\n", v10, v10, v8, v9, v9);
  hci_evt_send((int)v6);
  return 0;
}


// rf_command_start @ 0x12f288
int rf_command_start() {
  volatile uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = (void *)(uintptr_t)(off_12F2E4);
  v1 = (int)(uintptr_t)(irq_lock((void *)(uintptr_t)(1070), 1));
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    sub_123058C();
    patch_aware_dispatch(1070, 1, dword_12F2E8);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_calibrate_value(v1);
      patch_aware_dispatch(1070, 1, 1000 * *((volatile uint32_t *)off_12F2EC + 91));
      v0[1] = 1;
    }
    return 0;
  }
}



// task_poll_loop @ 0x12f2f0
void task_poll_loop() {
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = rf_mode_switch();
  ((int (*)())periph_trigger_write)(v0, v1, v2);
  while ( 1 )
    ;
}



// send_hci_event_42d @ 0x12f2fc
void send_hci_event_42d() {
  volatile char *v0; // r0

  ke_event_schedule_1(aErrWlanFcTimeo);
  v0 = irq_lock((volatile char *)0x42D, 1);
  task_poll_loop((int)v0);
}


// send_hci_event_42c @ 0x12f318
void send_hci_event_42c() {
  volatile char *v0; // r0

  ke_event_schedule_1(aReboot);
  v0 = irq_lock((volatile char *)0x42C, 1);
  task_poll_loop((int)v0);
}


// tx_power_config @ 0x12f334
int tx_power_config(int a1, volatile int *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  volatile uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = bt_buf_alloc(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (volatile uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      ke_event_schedule_1("\x9D\x81""Auto boot to 0x%08x\r\n", *(volatile uint32_t *)(*a2 + 4));
      break;
    case 2:
      ke_event_schedule_1("\x9D\x81""Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = ke_event_schedule_1("delay %d\r\n", v9);
      if ( !v9 )
        task_poll_loop(v10);
      patch_aware_dispatch(1068, 1, v9 << 10);
      break;
    default:
      ke_event_schedule_1(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)call_vector_1fc(15);
  ke_event_schedule_1(asc_14B084);
  hci_evt_send((int)v7);
  return 0;
}


// radio_init_2 @ 0x12f3bc
int radio_init_2() {
  volatile uint32_t *v0; // r4
  volatile uint32_t *v1; // r10
  volatile uint32_t *v2; // r6
  volatile uint32_t *v3; // r7
  volatile uint32_t *v4; // r8
  volatile uint32_t *v5; // r9
  volatile uint32_t *v6; // r5
  int v7; // r0
  int v8; // r3
  volatile uint32_t *v9; // r7
  volatile uint32_t *v10; // r5
  int v11; // r4
  int v13; // nf
  volatile uint32_t **v14; // r3

  v0 = (void *)(uintptr_t)(off_12F584);
  v1 = (void *)(uintptr_t)(off_12F620);
  v2 = (void *)(uintptr_t)(off_12F588);
  v3 = (void *)(uintptr_t)(off_12F58C);
  v4 = (void *)(uintptr_t)(off_12F624);
  v5 = (void *)(uintptr_t)(off_12F628);
  v6 = (void *)(uintptr_t)(off_12F590);
  ke_event_schedule_1("\x9B""current state is %d\r\n", *(volatile uint32_t *)off_12F57C & 0xF);
  ke_event_schedule_1("\x9B""40328188=%08x, 4032818c=%x\r\n", *v0, *(volatile uint32_t *)off_12F594);
  ke_event_schedule_1("txlist cptr 40128540=%08x \r\n", *v1);
  ke_event_schedule_1("ac0 sptr 40328528=%08x \r\n", *v2);
  ke_event_schedule_1("ac1 sptr 4032852c=%08x \r\n", *v3);
  ke_event_schedule_1("ac2 sptr 40328530=%08x \r\n", *v4);
  ke_event_schedule_1("ac3 sptr 40328534=%08x \r\n", *v5);
  ke_event_schedule_1("hiq sptr 4032853c=%08x \r\n", *v6);
  ke_event_schedule_1(
    "\x9B""ac0header=%08x, ac1header=%08x, ac2header=%08x, ac3header=%08x, hiqheader=%x\r\n",
    *(volatile uint32_t *)off_12F5B4,
    *(volatile uint32_t *)off_12F5B8,
    *(volatile uint32_t *)off_12F5BC,
    *(volatile uint32_t *)off_12F5C0,
    *(volatile uint32_t *)off_12F62C);
  ke_event_schedule_1("\x9Bstatus of 0x40328528=%08x\r\n", *(volatile uint32_t *)(*v2 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x4032852c=%08x\r\n", *(volatile uint32_t *)(*v3 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x40328530=%08x\r\n", *(volatile uint32_t *)(*v4 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x40328534=%08x\r\n", *(volatile uint32_t *)(*v5 + 60));
  ke_event_schedule_1("\x9Bstatus of 0x4032853c=%08x\r\n", *(volatile uint32_t *)(*v6 + 60));
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (volatile uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(volatile uint32_t **)off_12F618;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (volatile uint32_t *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (volatile uint32_t *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (volatile uint32_t *)*v4;
  }
  else if ( (*v0 & 0x20000) != 0 )
  {
    v0 = (volatile uint32_t *)*v5;
  }
  else
  {
    v14 = (volatile uint32_t **)(*v0 << 30);
    v13 = (*v0 & 2) != 0;
    if ( (*v0 & 2) != 0 )
      v14 = (volatile uint32_t **)dword_12F61C;
    else
      v0 = (volatile uint32_t *)*v1;
    if ( v13 )
      v0 = *v14;
  }
  if ( v0 )
  {
    rx_packet_handler_2((int)v0, 68, 1, 0);
    rx_packet_handler_2(v0[9], 52, 1, 0);
    ke_event_schedule_1("\x9B""frmlen=%x\r\n", v0[6]);
    v7 = v0[4];
    if ( v7 )
    {
      rx_packet_handler_2(v7, v0[5] + 1 - v7, 1, 0);
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    else
    {
      v8 = v0[3];
      if ( !v8 )
        goto LABEL_6;
    }
    rx_packet_handler_2(*(volatile uint32_t *)(v8 + 8), *(volatile uint32_t *)(v8 + 12) + 1 - *(volatile uint32_t *)(v8 + 8), 1, 0);
  }
LABEL_6:
  v9 = (void *)(uintptr_t)(off_12F5E0);
  v10 = (void *)(uintptr_t)(off_12F5E8);
  v11 = (v11 & ~0xFFu) | ((uint8_t)(8) & 0xFFu);
  do
  {
    ke_event_schedule_1("\x9B""0x40320500=%08x\r\n", *v9);
    ke_event_schedule_1("\x9B""0x40320504=%08x\r\n", *v10);
    v11 = (uint8_t)(v11 - 1);
  }
  while ( v11 );
  ke_event_schedule_1("\x9B""0x40320514=%08x\r\n", *(volatile uint32_t *)off_12F5F0);
  ke_event_schedule_1("\x9B""0x40320518=%08x\r\n", *(volatile uint32_t *)off_12F5F8);
  ke_event_schedule_1("\x9B""0x4032051c=%08x\r\n", *(volatile uint32_t *)off_12F600);
  ke_event_schedule_1("\x9B""0x40320520=%08x\r\n", *(volatile uint32_t *)off_12F608);
  return ke_event_schedule_1("\x9B""0x40320560=%08x\r\n", *(volatile uint32_t *)off_12F610);
}


// ke_int_lock_1 @ 0x12f630
int ke_int_lock_1(int a1, int a2, int a3) {
  volatile int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F684 = 1;
  }
  v3 = (volatile int *)off_12F688;
  ++*(volatile uint32_t *)off_12F688;
  result = ke_event_schedule_1("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
  if ( *(volatile int *)off_12F690 >= 0 )
  {
    mmio_clear_high_bits();
    result = set_system_flag_1(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F684;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_irq_clear @ 0x12f694
int mmio_irq_clear(int a1, int a2, int a3) {
  int result; // r0

  __disable_irq();
  *(volatile uint32_t *)off_12F6B8 = 0;
  result = ke_event_schedule_1("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
while ( *(volatile uint32_t *)(uintptr_t)(off_12F6C0) ) ;
  return result;
}


// mmio_field_update @ 0x12f6c4
int mmio_field_update(int a1, int a2, int a3) {
  return ke_event_schedule_1("\x9BWARNING (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
}


// ke_int_unlock @ 0x12f6e0
void ke_int_unlock() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F708 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12F70C);
  v1 = *(volatile uint32_t *)off_12F70C;
  v2 = *(volatile uint32_t *)off_12F70C + 1;
  *(volatile uint32_t *)off_12F70C = v2;
  if ( v2 )
  {
    v3 = (void *)(uintptr_t)(off_12F708);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}



// timer_clear @ 0x12f710
volatile int *timer_clear() {
  volatile uint64_t *v0; // r4
  volatile int *result; // r0

  v0 = (void *)(uintptr_t)(off_12F72C);
  result = memset((volatile int *)off_12F72C, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}



// reset_hci_scratch @ 0x12f730
int reset_hci_scratch() {
  memset((volatile int *)dword_12F740, 0, 8u);
  return 0;
}



// j_rf_phy_mmio_poll_n_cb @ 0x12f744
int j_rf_phy_mmio_poll_n_cb() {
  return pmu_isr_extra();
}



// patch_jump @ 0x12f748
int patch_jump(volatile uint16_t *a1) {
  return (int)(uintptr_t)(host_event_process((int)(uintptr_t)(a1)));
}



// return_two_stub @ 0x12f74c
int return_two_stub() {
  return 2;
}



// j_nullsub_6 @ 0x12f750
int j_nullsub_6(void) {
  return nullsub_6();
}



// state_ready_check @ 0x12f754
int state_ready_check() {
  int result; // r0

  if ( **(volatile uint8_t **)off_12F768 != 3 )
    return 1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_10CA30 + 548);
  *(volatile uint32_t *)off_10CA34 = 32;
  if ( result )
    return 1;
  *(volatile uint32_t *)off_10CA38 = 32;
  return result;
}



// jump_to_10ca3c @ 0x12f76c
int jump_to_10ca3c() {
  return pmu_isr_224();
}



// process_pending_queue @ 0x12f770
volatile int * process_pending_queue(volatile int *result, int a2) {
  volatile uint32_t *v2; // r4
  volatile int *v3; // r6
  volatile int *v4; // r5
  int v5; // r2

  v2 = (volatile uint32_t *)*result;
  if ( *result )
  {
    v3 = (volatile int *)dword_12F7A0;
    v4 = result;
    do
    {
      while ( 1 )
      {
        list_pop_front((int)v4);
        result = v3;
        if ( !v2[3] )
          break;
        result = (volatile int *)check_abort_flag((int)v3, v2);
        v2 = (volatile uint32_t *)*v4;
        if ( !*v4 )
          return result;
      }
      v5 = v2[2];
      v2 = (volatile uint32_t *)*v4;
      *(volatile uint16_t *)(v5 + 8) = 0;
    }
    while ( v2 );
  }
  return result;
}


// dispatch_if_ready @ 0x12f7a4
int dispatch_if_ready(int result) {
  int v1; // r4
  volatile char *v2; // r0
  volatile char *v3; // r5
  volatile uint32_t *v4; // r4

  if ( **(volatile uint8_t **)off_12F7F8 == 3 )
  {
    v1 = result;
    v2 = (volatile char *)pmu_isr_214();
    v3 = v2;
    if ( v2 )
    {
      *(volatile uint32_t *)(v1 + 24) = 49374;
      memcpy(v2, (volatile char *)v1, 0x1Cu);
      v4 = (void *)(uintptr_t)(off_12F7FC);
      while ( !*(volatile uint32_t *)off_12F7FC )
        ;
      check_abort_flag(((volatile uint32_t *)(uintptr_t)off_12F800)[0] + 540, (volatile uint32_t *)v3 - 1);
      *v4 = 1;
      pmu_ctrl_write_128();
    }
    else
    {
      return ke_event_schedule_1(aErrUfHostRxBuf);
    }
  }
  return result;
}


// jump_to_10c824_zero @ 0x12f808
int jump_to_10c824_zero() {
  return pmu_poll_delay(0);
}



// irq_lock_save_1 @ 0x12f810
int irq_lock_save_1(unsigned int a1, int a2) {
  volatile int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F860 = 1;
  }
  v3 = (volatile int *)off_12F864;
  ++*(volatile uint32_t *)off_12F864;
  result = send_to_global_queue((volatile uint32_t *)a2);
  if ( a1 <= 4 )
    --*(volatile uint8_t *)(dword_12F868 + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F860;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  --*((volatile uint32_t *)off_12F86C + 126);
  return result;
}


// get_shared_buf_size @ 0x12f870
int get_shared_buf_size() {
  return 1024;
}



// rx_packet_process @ 0x12f878
unsigned int rx_packet_process(unsigned int a1, int a2, int a3) {
  unsigned int v3; // r7
  volatile int *v4; // r5
  volatile uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  volatile uint8_t *v11; // r4
  volatile uint8_t *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(volatile uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (volatile int *)off_12F908;
    if ( a3 < (int)*(volatile uint32_t *)off_12F908 )
    {
      v8 = (volatile uint8_t *)dword_12F910;
      do
      {
        uart_puts(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F914;
      v11 = (volatile uint8_t *)(a1 - 1);
      v12 = (volatile uint8_t *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          uart_putc(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        uart_puts((volatile uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    uart_puts((volatile uint8_t *)dword_12F910);
    --*(volatile uint32_t *)off_12F908;
  }
LABEL_10:
  --*(volatile uint32_t *)off_12F90C;
  return v3;
}



// parse_space_token @ 0x12f918
int parse_space_token(volatile uint8_t *a1, int a2) {
  int v2; // r4
  volatile uint8_t *v4; // r0
  int v5; // r2
  int v6; // t1
  int v7; // r3
  int v8; // r5
  int v9; // r6
  int v10; // t1
  volatile uint8_t *v12; // r2
  int v13; // r3
  int v14; // t1

  v2 = 0;
  while ( 1 )
  {
    do
    {
      do
      {
        v4 = a1;
        v6 = *a1++;
        v5 = v6;
      }
      while ( v6 == 32 );
    }
    while ( v5 == 9 );
    if ( !v5 )
    {
      *(volatile uint32_t *)(a2 + 4 * v2) = 0;
      return v2;
    }
    if ( v5 == 34 )
      break;
    *(volatile uint32_t *)(a2 + 4 * v2) = (int)(uintptr_t)(v4);
    v7 = *v4;
    v8 = v2 + 1;
    v9 = v2 + 1;
    if ( !*v4 )
      goto LABEL_20;
    while ( v7 != 32 && v7 != 9 )
    {
      v10 = *++v4;
      v7 = v10;
      if ( !v10 )
        goto LABEL_20;
    }
LABEL_11:
    if ( !*v4 )
      goto LABEL_20;
    *v4 = 0;
    a1 = v4 + 1;
    v2 = v9;
    if ( v9 == 16 )
    {
      uart_puts((volatile uint8_t *)dword_12F9A0);
      return 16;
    }
  }
  v12 = v4 + 1;
  *(volatile uint32_t *)(a2 + 4 * v2) = (int)(uintptr_t)(v4 + 1);
  v13 = v4[1];
  v8 = v2 + 1;
  v9 = v2 + 1;
  if ( v4[1] )
  {
    while ( v13 != 34 )
    {
      v14 = *++v12;
      v13 = v14;
      if ( !v14 )
        goto LABEL_20;
    }
    v4 = v12;
    goto LABEL_11;
  }
LABEL_20:
  *(volatile uint32_t *)(a2 + 4 * v9) = 0;
  return v8;
}



// find_extension @ 0x12f9a4
volatile uint32_t * find_extension(int a1, volatile uint32_t *a2, int a3) {
  int v5; // r0
  int v6; // r11
  int v7; // r9
  volatile uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  volatile uint32_t *v11; // r10

  v5 = (int)(uintptr_t)(strchr((void *)(uintptr_t)(a1), 46));
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = strlen(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
if ( !strncasecmp((volatile uint8_t *)(uintptr_t)a1, (volatile uint8_t *)(uintptr_t)*v8, v6) ) break;
        v8 += 4;
        if ( a3 == v9 )
          goto LABEL_9;
      }
      if ( strlen(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
LABEL_9:
    if ( v7 == 1 )
      return a2;
  }
  return 0;
}



// queue_operation @ 0x12fa2c
int queue_operation(unsigned int a1, volatile uint8_t *a2, int a3) {
  volatile int *v3; // r6
  char v4; // r4
  volatile int *v6; // r7
  volatile uint32_t *v7; // r3
  int v8; // r2
  volatile int *v9; // r8
  int result; // r0
  int v11; // r0
  volatile int *v12; // r2
  volatile uint32_t *v13; // r3
  volatile int *v14; // r8
  int v15; // r1
  unsigned int v16; // r0
  volatile uint8_t *v17; // r0
  int v18; // r2
  int v19; // r3
  unsigned int v20; // r1
  volatile uint8_t *v21; // r0
  volatile uint32_t *v22; // r3
  volatile uint8_t *v23; // r3
  int v24; // r2

  v3 = (volatile int *)off_12FB5C;
  v4 = a1;
  if ( *(volatile uint32_t *)off_12FB5C )
  {
    if ( !a3 )
      goto LABEL_3;
LABEL_11:
    v11 = strlen(a3);
    v12 = (volatile int *)off_12FB60;
    v13 = (void *)(uintptr_t)(off_12FB68);
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(volatile uint32_t *)off_12FB5C = (int)(uintptr_t)(a2);
  if ( a3 )
    goto LABEL_11;
LABEL_3:
  v6 = (volatile int *)off_12FB60;
  v7 = (void *)(uintptr_t)(off_12FB64);
  v8 = *(volatile uint32_t *)off_12FB60;
  *(volatile uint32_t *)off_12FB64 = *(volatile uint32_t *)off_12FB60;
  if ( a1 <= 0x17 )
  {
    switch ( a1 )
    {
      case 0u:
        return -1;
      case 3u:
        result = 0;
        *a2 = 0;
        return result;
      case 8u:
        goto LABEL_19;
      case 0xAu:
      case 0xDu:
        v21 = (volatile uint8_t *)dword_12FB6C;
        *(volatile uint8_t *)*v3 = 0;
        uart_puts(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = (void *)(uintptr_t)(off_12FB68);
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (volatile int *)off_12FB68;
        v15 = *v3;
        if ( *(volatile uint32_t *)off_12FB68 )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (volatile uint8_t *)rx_packet_process(v16, v15, v8);
            v18 = *v14;
            *v3 = (int)v17;
            v15 = (int)v17;
            if ( v18 <= 0 )
              break;
            v19 = *v17;
            v16 = (unsigned int)a2;
            if ( v19 == 32 )
              break;
            v8 = *v6;
          }
        }
        return -1;
      default:
        v9 = (volatile int *)off_12FB68;
        if ( *(volatile int *)off_12FB68 > 61 )
          goto LABEL_7;
        if ( a1 != 9 )
          goto LABEL_28;
        uart_puts((volatile uint8_t *)(dword_12FB70 + (v8 & 7)));
        *(volatile uint32_t *)off_12FB64 = (*(volatile uint32_t *)off_12FB64 & 0xFFFFFFF8) + 8;
        break;
    }
    goto LABEL_27;
  }
  if ( a1 == 127 )
  {
LABEL_19:
    v20 = *v3;
    if ( *(volatile uint32_t *)off_12FB68 )
      v20 = rx_packet_process((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (volatile int *)off_12FB68;
    if ( *(volatile int *)off_12FB68 <= 61 )
    {
LABEL_28:
      *v7 = v8 + 1;
      uart_putc(a1);
LABEL_27:
      v23 = (volatile uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
LABEL_7:
    uart_putc(7);
    return -1;
  }
}



// parse_integer @ 0x12fb74
int parse_integer(volatile uint8_t *a1, volatile uint32_t *a2, unsigned int a3) {
  int v3; // r5
  int v4; // r7
  int i; // r6
  unsigned int v6; // r3
  int v8; // t1
  int v9; // r3
  int v10; // r3

  v3 = *a1;
  if ( v3 == 48 )
  {
    v3 = a1[1];
    if ( (unsigned int)(v3 - 65) > 0x19 )
      v9 = a1[1];
    else
      v9 = (uint8_t)(v3 + 32);
    if ( v9 == 120 && ((v10 = a1[2], (unsigned int)(v10 - 48) <= 9) || (v10 & 0xFFFFFFDF) - 65 <= 5) )
    {
      a1 += 2;
      v3 = v10;
      a3 = 16;
    }
    else
    {
      ++a1;
      if ( !a3 )
      {
        a3 = 8;
        if ( v3 != 45 )
          goto LABEL_5;
LABEL_25:
        v4 = 1;
        v3 = *++a1;
        goto LABEL_6;
      }
    }
  }
  else if ( !a3 )
  {
    a3 = 10;
  }
  if ( v3 == 45 )
    goto LABEL_25;
LABEL_5:
  v4 = 0;
LABEL_6:
  for ( i = 0; ; i = v6 + i * a3 )
  {
    v6 = v3 - 48;
    if ( (uint8_t)(v3 - 48) > 9u )
    {
      if ( (v3 & 0xFFFFFFDF) - 65 > 5 )
        break;
      if ( (unsigned int)(v3 - 97) > 0x19 )
        v6 = v3 - 55;
      else
        v6 = (uint8_t)(v3 - 32) - 55;
    }
    if ( a3 <= v6 )
      break;
    v8 = *++a1;
    v3 = v8;
  }
  if ( v4 )
    i = -i;
  if ( a2 )
    *a2 = (int)(uintptr_t)(a1);
  return i;
}



// event_handlers_dispatch @ 0x12fc20
int event_handlers_dispatch() {
  unsigned int v0; // r4
  unsigned int v1; // r5
  const volatile char *v2; // r2

  v0 = off_12FC40;
  v1 = off_12FC40 + 112;
  do
  {
    v2 = *(const volatile char **)(v0 + 4);
    if ( v2 )
      printf_wrapper("%s %s\r\n", *(const volatile char **)v0, v2);
    v0 += 16;
  }
  while ( v0 != v1 );
  return 0;
}


// has_dot_extension @ 0x12fc48
int has_dot_extension(int a1) {
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = strlen(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(volatile uint8_t *)(v3 - 2) != 46 )
    return 4;
  v5 = *(volatile uint8_t *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}



// buf_clear16 @ 0x12fc7c
int buf_clear16(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int a2a; // [sp+4h] [bp-4h]

  v4 = parse_integer((volatile uint8_t *)a2[1], nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = has_dot_extension(*a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    printf_wrapper("Unknown data size:%d\r\n", v5);
    return -1;
  }
  a2a = parse_integer((volatile uint8_t *)a2[2], nullptr, 0);
  v5 = has_dot_extension(*a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( a2a == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = jump_table_1b0();
      printf_wrapper("[0x%08X] = 0x%08X\r\n", v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      printf_wrapper("[0x%08lX] = 0x%08lX\r\n", v4, *(volatile uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      printf_wrapper("[0x%08lX] = 0x%04X\r\n", v4, *(volatile uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        printf_wrapper("[0x%08lX] = 0x%02X\r\n", v4, *(volatile uint8_t *)v4);
      return 0;
    }
  }
  v7 = *(volatile uint8_t *)*a2 == 82 && v4 < 0x40000000;
  rx_packet_handler_2(v4, a2a, (uint8_t)v5, v7);
  return 0;
}


// packet_header_parse @ 0x12fd64
int packet_header_parse(int a1, volatile uint32_t *a2) {
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r4
  int v10; // r0

  v4 = has_dot_extension(*a2);
  if ( v4 < 0 )
  {
    printf_wrapper("Unknown data size:%d\r\n", v4);
    return -1;
  }
  else
  {
    v5 = parse_integer((volatile uint8_t *)a2[1], nullptr, 0x10u);
    v6 = parse_integer((volatile uint8_t *)a2[2], nullptr, 0x10u);
    if ( a1 <= 3 )
    {
      v7 = 0;
      goto LABEL_9;
    }
    v10 = parse_integer((volatile uint8_t *)a2[3], nullptr, 0);
    if ( v10 )
    {
      v7 = v10 - 1;
      do
      {
LABEL_9:
        while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
        {
          v8 = v5 & 0xFFFFFFFC;
          printf_wrapper("[0x%08X] = 0x%08lX\r\n", v8, v6);
          --v7;
          jump_table_1b4();
          v5 = v8 + v4;
          if ( v7 == -1 )
            return 0;
        }
        switch ( v4 )
        {
          case 4:
            printf_wrapper("[0x%08lX] = 0x%08lX\r\n", v5, v6);
            *(volatile uint32_t *)v5 = v6;
            break;
          case 2:
            printf_wrapper("[0x%08lX] = 0x%04X\r\n", v5, (uint16_t)v6);
            *(volatile uint16_t *)v5 = v6;
            break;
          case 1:
            printf_wrapper("[0x%08lX] = 0x%02X\r\n", v5, (uint8_t)v6);
            *(volatile uint8_t *)v5 = v6;
            break;
        }
        --v7;
        v5 += v4;
      }
      while ( v7 != -1 );
    }
    return 0;
  }
}


// buf_clear10 @ 0x12fe54
int buf_clear10(int a1, int a2) {
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_integer(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_integer(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(volatile uint16_t **)off_12FEE8 = v6;
      ke_event_schedule_1("cfg dbg_msk: 0x%x\n", v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        ke_event_schedule_1(aInvalidArgs);
        return 0;
      }
      v8 = parse_integer(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      ke_event_schedule_1("cfg dbg mod: %08X\n", v8);
      state_set_flags(v8);
      return 0;
    }
    else
    {
      ke_event_schedule_1("invalid func: %d\n", v4);
      return 0;
    }
  }
  else
  {
    ke_event_schedule_1("cur dbg_msk: 0x%x\n", **(volatile uint16_t **)off_12FEE8);
    v7 = state_get_flags();
    ke_event_schedule_1("dbg mod: %08X\n", v7);
    return 0;
  }
}


// l2cap_pdu_check @ 0x12ff00
int l2cap_pdu_check(int a1, int a2) {
  int v3; // r6
  unsigned int v4; // r6
  uint16_t v5; // r0
  int v6; // r5
  uint16_t v7; // r7
  unsigned int v8; // r8
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r12
  volatile uint32_t *v12; // lr
  volatile uint32_t *v13; // r3
  volatile uint32_t *v14; // r9
  volatile uint32_t *v15; // lr
  volatile uint32_t *v16; // r0
  volatile uint32_t *v17; // r12
  volatile unsigned int *v18; // r1
  unsigned int v19; // r3
  volatile char *v20; // r0
  volatile int *v21; // r12
  int v22; // lr
  int v23; // r9
  struct __attribute__((packed)) { char a1a[4]; // [sp+8h] [bp-Ch] BYREF
  char v26; // [sp+Ch] [bp-8h]
  } _frame;
  if ( strlen(*(volatile uint32_t *)(a2 + 4)) != 12 || strlen(*(volatile uint32_t *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(volatile uint32_t *)(a2 + 4);
  memcpy(_frame.a1a, (volatile char *)(v3 + 8), 4u);
  *(volatile uint8_t *)(v3 + 8) = 0;
  _frame.v26 = 0;
  v4 = parse_integer((volatile uint8_t *)v3, nullptr, 0x10u);
  v5 = parse_integer((volatile uint8_t *)_frame.a1a, nullptr, 0x10u);
  v6 = *(volatile uint32_t *)(a2 + 8);
  v7 = v5;
  memcpy(_frame.a1a, (volatile char *)(v6 + 8), 4u);
  *(volatile uint8_t *)(v6 + 8) = 0;
  _frame.v26 = 0;
  v8 = parse_integer((volatile uint8_t *)v6, nullptr, 0x10u);
  v6 = (v6 & ~0xFFFFu) | ((uint16_t)(parse_integer((volatile uint8_t *)_frame.a1a, nullptr, 0x10u)) & 0xFFFFu);
  ke_event_schedule_1(aSetMonitor);
  v9 = (void *)(uintptr_t)(off_130074);
  v10 = (void *)(uintptr_t)(off_130078);
  v11 = (void *)(uintptr_t)(off_1300A0);
  v12 = (void *)(uintptr_t)(off_1300A4);
  v13 = (void *)(uintptr_t)(off_13007C);
  *(volatile uint32_t *)off_130070 = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_130080;
  v14 = (void *)(uintptr_t)(off_1300A8);
  v15 = (void *)(uintptr_t)(off_1300AC);
  v16 = (void *)(uintptr_t)(off_130088);
  v13[37597] = dword_130084;
  v17 = (void *)(uintptr_t)(off_1300B0);
  v18 = (volatile unsigned int *)off_13008C;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(volatile uint32_t *)off_130090 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (volatile char *)off_130094;
  *(volatile uint32_t *)off_130094 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (volatile int *)off_1300B4;
  v22 = dword_1300B8;
  v23 = dword_1300BC;
  *(volatile uint32_t *)off_130098 = __rev16((uint16_t)v6);
  *(volatile uint32_t *)&v20[-148] = 7;
  *(volatile uint32_t *)&v20[-148] = v23;
  *v21 = v22;
  ke_event_schedule_1("set mon: mac=%08x%04x, bssid=%08x%04x\n", v4, v7, v8, (uint16_t)v6);
  return 0;
}


// buf_array_clear_multiple @ 0x1300c0
int buf_array_clear_multiple(int a1, int a2) {
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_integer(*(volatile uint8_t **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = state_get_value();
    ke_event_schedule_1("dbg sev: %d\n", v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      ke_event_schedule_1(aInvalidArgs);
    }
    else
    {
      v7 = parse_integer(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        ke_event_schedule_1("invalid sev_idx:%d\n", v7);
      }
      else
      {
        ke_event_schedule_1("Cfg dbg sev: %d\n", v7);
        state_set_value(v7);
      }
    }
    return 0;
  }
  ke_event_schedule_1(aInvalidFunc);
  return 0;
}


// buf_array_clear_single @ 0x13013c
int buf_array_clear_single(int a1, int a2) {
  int v4; // r0
  int v5; // r7
  int v6; // r6
  volatile int *v7; // r4
  unsigned int v9; // r0

  if ( a1 == 1 )
  {
    log_mac_state();
    return 0;
  }
  else
  {
    v4 = parse_integer(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = (volatile int *)off_1301AC;
      v9 = parse_integer(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v9 > 0x7D0 )
        v7[91] = v9;
    }
    else
    {
      v7 = (volatile int *)off_1301AC;
    }
    if ( *((volatile uint8_t *)v7 + 363) != v5 )
    {
      *((volatile uint8_t *)v7 + 363) = v5;
      if ( v6 )
      {
        mmio_init_check();
        rf_afe_enable();
      }
      else
      {
        rf_afe_disable();
      }
    }
    ke_event_schedule_1("temp_comp en=%d, peroid_ms=%d\n", v5, v7[91]);
    return 0;
  }
}


// ke_irq_lock @ 0x1301b4
int ke_irq_lock() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  event_loop_check();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_130214 = 1;
  }
  v0 = (volatile int *)off_130218;
  v1 = (volatile uint32_t *)dword_13021C;
  ++*(volatile uint32_t *)off_130218;
  zero_struct(v1);
  zero_struct((volatile uint32_t *)dword_130220);
  check_abort_flag(dword_13021C, (volatile uint32_t *)dword_130224);
  check_abort_flag(dword_13021C, (volatile uint32_t *)dword_130228);
  check_abort_flag(dword_13021C, (volatile uint32_t *)dword_13022C);
  result = check_abort_flag(dword_13021C, (volatile uint32_t *)dword_130230);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_130214;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// ke_malloc @ 0x130234
int ke_malloc(int a1) {
  int v1; // r0
  int v2; // r4
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r5
  unsigned int CPSR; // r1
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r5
  volatile uint8_t *v10; // r2
  int v11; // r0
  unsigned int v12; // r5
  unsigned int v13; // r6
  int v14; // t1
  unsigned int v15; // r4
  unsigned int v16; // r5
  int v17; // t1

  v1 = queue_operation(a1, (volatile uint8_t *)dword_130354, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( strlen(off_13035C) != v1 || strcmp(off_13035C, (volatile unsigned int *)dword_130354) )
      {
        v4 = list_pop_front(dword_130360);
        v5 = v4;
        if ( v4 )
        {
          strcpy((unsigned int)(v4 + 1), dword_130354);
          check_abort_flag(dword_130364, v5);
        }
        else
        {
          uart_puts(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        printf_wrapper(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          uart_puts(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              printf_wrapper("\r\n[%08x]:", v12);
            v14 = *(volatile uint32_t *)v12;
            v12 += 4;
            printf_wrapper(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          uart_puts(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              printf_wrapper("\r\n[%08x]:", v15);
            v17 = *(volatile uint32_t *)v15;
            v15 += 4;
            printf_wrapper(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        uart_puts(aAic_0);
        v10 = (void *)(uintptr_t)(off_130370);
        v11 = *(volatile uint8_t *)off_130370;
        if ( *(volatile uint8_t *)off_130370 )
        {
          *((volatile uint8_t *)off_130374 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((volatile uint8_t *)off_130374 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      uart_puts(aAic);
    }
    queue_operation(0x30u, (volatile uint8_t *)dword_130354, (unsigned int)aAic);
  }
  return v2;
}


// ke_event_send_1 @ 0x13038c
int ke_event_send_1(int a1, int a2) {
  volatile int *v2; // r6
  int v3; // r0
  int result; // r0
  int v5; // r4
  int v6; // r3
  int v7; // r2
  volatile uint8_t **v8; // r7
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r2
  volatile uint8_t **v13; // r0
  int v14; // r0
  volatile uint8_t *a1a[18]; // [sp+4h] [bp-48h] BYREF

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_13047C = 1;
  }
  v2 = (volatile int *)off_130480;
  v3 = dword_130484;
  ++*(volatile uint32_t *)off_130480;
  result = (int)list_pop_front(v3);
  v5 = result;
  if ( *v2 )
  {
    v6 = *v2 - 1;
    v7 = *(volatile uint32_t *)off_13047C;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v8 = (volatile uint8_t **)off_130488;
    do
    {
      v9 = parse_space_token((volatile uint8_t *)(v5 + 4), (int)a1a);
      if ( v9 )
      {
        v13 = (void *)(find_extension((int)(uintptr_t)(a1a[0]), (void *)(v8), 7));
        if ( v13 )
        {
          if ( *((volatile int16_t *)v13 + 5) < v9 || *((volatile int16_t *)v13 + 4) > v9 )
          {
            printf_wrapper(aUsageSS, *v13, v13[1]);
          }
          else
          {
            v14 = ((int ( *)(int, volatile uint8_t **))v13[3])(v9, a1a);
            if ( v14 )
              printf_wrapper("Command fail, ret=%d\r\n", v14);
          }
        }
        else
        {
          printf_wrapper("Unknown command '%s'\r\n", (const volatile char *)a1a[0]);
        }
      }
      else
      {
        uart_puts(aNoCommand);
      }
      uart_puts(aAic);
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_13047C = 1;
      }
      v10 = dword_130494;
      ++*v2;
      check_abort_flag(v10, (volatile uint32_t *)v5);
      result = (int)list_pop_front(dword_130484);
      v5 = result;
      if ( *v2 )
      {
        v11 = *v2 - 1;
        v12 = *(volatile uint32_t *)off_13047C;
        *v2 = v11;
        if ( !v11 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    while ( result );
  }
  return result;
}


