// controller_init @ 0x12ecf8
int controller_init() {
  event_dispatch(aUsbOff);
  ke_int_lock((int)(uintptr_t)((volatile char *)0x42F), 1);
  *((volatile uint32_t *)off_12ED1C + 20) &= ~2u;
  return 0;
}


// send_command_event @ 0x12ed20
int send_command_event(int a1, int a2, int a3, int a4) {
  int v5; // r0
  int v6; // r1
  volatile uint32_t *v7; // r4
  volatile uint32_t *v9; // r2
  volatile uint8_t *v10; // r0
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r3

  v5 = ke_msg_alloc(1040, a4, a3, 4);
  v6 = *(volatile uint16_t *)(a2 + 4);
  v7 = (volatile uint32_t *)v5;
  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_12ED98)[44]) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v9 = (void *)(uintptr_t)(off_12EDA4);
    *(volatile uint32_t *)off_12EDA0 |= 0x2000000u;
    v10 = (void *)(uintptr_t)(off_12EDA8);
    v9[14] |= 0x10u;
    *v10 = 1;
  }
  if ( v6 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_12EDA4);
    *((volatile uint32_t *)off_12EDA4 + 18) = *(volatile uint32_t *)a2;
    v11[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v12 = (void *)(uintptr_t)(off_12EDA4);
    *((volatile uint32_t *)off_12EDA4 + 19) = *(volatile uint32_t *)a2;
    v12[75] = 128;
  }
LABEL_5:
  *v7 = 0;
  event_dispatch("\x9D\x81""DBG: Boot NPC %d\n", v6);
  ke_msg_send_2((int)v7);
  return 0;
}


// msg_alloc_0x40a @ 0x12edac
int msg_alloc_0x40a(int a1, int a2, int16_t a3, int16_t a4) {
  volatile uint32_t *v4; // r0

  v4 = (volatile uint32_t *)ke_msg_alloc(1034, a4, a3, 0xCu);
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  ke_msg_send_2((int)v4);
  return 0;
}



// msg_alloc_0x424 @ 0x12edcc
int msg_alloc_0x424(int a1, volatile char **a2, int a3, int a4) {
  int v5; // r0
  volatile char *v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = ke_msg_alloc(1060, a4, a3, 1032);
  v7 = (unsigned int)a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *(volatile uint32_t *)v5 = (int)(uintptr_t)(v6);
  *(volatile uint32_t *)(v5 + 4) = v7;
  v8 = v5;
  memcpy((volatile char *)(v5 + 8), v6, v7);
  event_dispatch(asc_14ACE8, *a2, &(*a2)[*(volatile uint32_t *)(v8 + 4)], *(volatile uint32_t *)(v8 + 8));
  ke_msg_send_2(v8);
  return 0;
}


// msg_alloc_0x40c @ 0x12ee14
int msg_alloc_0x40c(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint32_t *v5; // r5
  volatile char *v6; // r0
  int v7; // zf
  unsigned int v8; // r2

  v5 = (volatile uint32_t *)ke_msg_alloc(1036, a4, a3, 4);
  v6 = (volatile char *)*a2;
  v7 = *a2 << 30 == 0;
  v8 = a2[1];
  *v5 = 0;
  if ( !v7 )
    *v5 = 255;
  if ( v8 << 30 )
    *v5 = 1;
  memcpy(v6, (volatile char *)a2 + 8, v8);
  event_dispatch(asc_14AD2C, *a2, a2[1] + *a2, a2[2], *v5);
  ke_msg_send_2((int)v5);
  return 0;
}


// msg_alloc_0x412 @ 0x12ee6c
int msg_alloc_0x412(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile uint64_t *v5; // r0
  int v6; // r5
  volatile uint32_t *v7; // r0
  uint64_t v8; // r2
  int v9; // r0

  v5 = (volatile uint64_t *)ke_msg_alloc(1042, a4, a3, 8);
  v6 = (int)v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12EF20 - 1 <= 1 )
  {
    v8 = (v8 & ~0xFFFFFFFFull) | ((uint32_t)(*a2) & 0xFFFFFFFFu);
    if ( *a2 == dword_12EF28 || (uint32_t)v8 == dword_12EF28 - 36184 )
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
      mmio_rmw32((int)v7, a2[2], a2[1], 1);
      v9 = mmio_read32(*a2, 1);
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
  event_dispatch(
    "\x9D\x81""DBG: Writing memory with mask:0x%08x, data:0x%08x / %d: [0x%08x] = 0x%08x / %d\n",
    a2[1],
    HIDWORD(v8),
    HIDWORD(v8),
    (uint32_t)v8,
    v9,
    v9);
  ke_msg_send_2(v6);
  return 0;
}


// msg_alloc_0x401 @ 0x12ef2c
int msg_alloc_0x401(int a1, volatile uint32_t *a2, int a3, int a4) {
  int v5; // r0
  volatile int *v6; // r1
  volatile int **v7; // r4
  int v8; // r3
  int v10; // r0

  v5 = ke_msg_alloc(1025, a4, a3, 8);
  v6 = (volatile int *)*a2;
  v7 = (volatile int **)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v10 = mmio_read32(*a2, 1);
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
  event_dispatch("\x9D\x81""DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", v6, v8, v8);
  ke_msg_send_2((int)v7);
  return 0;
}


// cb_send_0x16ae04 @ 0x12ef78
int cb_send_0x16ae04(int a1, volatile uint32_t *a2, int a3, int a4) {
  event_dispatch("\x9D\x81""DBG: Setting severity filter: 0x%08x\n", *a2);
  *((volatile uint32_t *)off_12EFA8 + 1) = *a2;
  ke_msg_send_no_param(1031, a4, a3);
  return 0;
}


// cb_send_0x16ae2c @ 0x12efac
int cb_send_0x16ae2c(int a1, volatile uint32_t *a2, int a3, int a4) {
  event_dispatch("\x9D\x81""DBG: Setting module filter: 0x%08x\n", *a2);
  *(volatile uint32_t *)off_12EFDC = *a2;
  ke_msg_send_no_param(1029, a4, a3);
  return 0;
}


// msg_alloc_0x403 @ 0x12efe0
int msg_alloc_0x403(int a1, volatile uint32_t *a2, int a3, int a4) {
  volatile int *v5; // r0
  volatile int *v6; // r5
  volatile uint32_t *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (volatile int *)ke_msg_alloc(1027, a4, a3, 8);
  v6 = v5;
  if ( (unsigned int)**(volatile uint8_t **)off_12F058 - 1 <= 1 )
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
      mmio_write32((int)v7, a2[1], 1);
      v9 = mmio_read32(*a2, 1);
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
  event_dispatch("\x9D\x81""DBG: Writing memory with 0x%08x / %d: [0x%08x] = 0x%08x / %d\n", v10, v10, v8, v9, v9);
  ke_msg_send_2((int)v6);
  return 0;
}


// state_get_0x42e @ 0x12f060
int state_get_0x42e() {
  volatile uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = (void *)(uintptr_t)(off_12F0BC);
  v1 = ke_int_lock(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    call_phy_op();
    ke_task_create(1070, 1, dword_12F0C0);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      rf_temperature_compensation(v1);
      ke_task_create(1070, 1, 1000 * *((volatile uint32_t *)off_12F0C4 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}



// read_state_flag_1 @ 0x12f0c8
void read_state_flag_1() {
  int v0; // r0
  int v1; // r1
  int v2; // r2

  v0 = patch_get_state();
  ((int (*)())rf_set_channel_1)(v0, v1, v2);
  while ( 1 )
    ;
}



// log_event_1069 @ 0x12f0d4
void log_event_1069() {
  volatile char *v0; // r0

  event_dispatch(aErrWlanFcTimeo);
  v0 = (void *)(uintptr_t)(ke_int_lock((int)(uintptr_t)((volatile char *)0x42D), 1));
  read_state_flag_1((int)v0);
}


// log_event_1068 @ 0x12f0f0
void log_event_1068() {
  volatile char *v0; // r0

  event_dispatch(aReboot);
  v0 = (void *)(uintptr_t)(ke_int_lock((int)(uintptr_t)((volatile char *)0x42C), 1));
  read_state_flag_1((int)v0);
}


// msg_alloc_0x40e @ 0x12f10c
int msg_alloc_0x40e(int a1, volatile int *a2, int a3, int a4) {
  int v5; // r0
  int v6; // r3
  volatile uint32_t *v7; // r4
  int v9; // r5
  int v10; // r0

  v5 = ke_msg_alloc(1038, a4, a3, 4);
  v6 = a2[1];
  v7 = (volatile uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      event_dispatch("\x9D\x81""Auto boot to 0x%08x\r\n", *(volatile uint32_t *)(*a2 + 4));
      break;
    case 2:
      event_dispatch("\x9D\x81""Custom boot to 0x%08x\r\n", *a2);
      break;
    case 3:
      v9 = *a2;
      v10 = event_dispatch("delay %d\r\n", v9);
      if ( !v9 )
        read_state_flag_1(v10);
      ke_task_create(1068, 1, v9 << 10);
      break;
    default:
      event_dispatch(aInvalidBootTyp);
      break;
  }
  *v7 = (uint8_t)call_hook_1(15);
  event_dispatch(asc_14AF0C);
  ke_msg_send_2((int)v7);
  return 0;
}


// sub_12F194 @ 0x12f194
int sub_12F194() {
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

  v0 = (void *)(uintptr_t)(off_12F35C);
  v1 = (void *)(uintptr_t)(off_12F3F8);
  v2 = (void *)(uintptr_t)(off_12F360);
  v3 = (void *)(uintptr_t)(off_12F364);
  v4 = (void *)(uintptr_t)(off_12F3FC);
  v5 = (void *)(uintptr_t)(off_12F400);
  v6 = (void *)(uintptr_t)(off_12F368);
  event_dispatch("\x9B""current state is %d\r\n", *(volatile uint32_t *)off_12F354 & 0xF);
  event_dispatch("\x9B""40328188=%08x, 4032818c=%x\r\n", *v0, *(volatile uint32_t *)off_12F36C);
  event_dispatch("txlist cptr 40128540=%08x \r\n", *v1);
  event_dispatch("ac0 sptr 40328528=%08x \r\n", *v2);
  event_dispatch("ac1 sptr 4032852c=%08x \r\n", *v3);
  event_dispatch("ac2 sptr 40328530=%08x \r\n", *v4);
  event_dispatch("ac3 sptr 40328534=%08x \r\n", *v5);
  event_dispatch("hiq sptr 4032853c=%08x \r\n", *v6);
  event_dispatch(
    "\x9B""ac0header=%08x, ac1header=%08x, ac2header=%08x, ac3header=%08x, hiqheader=%x\r\n",
    *(volatile uint32_t *)off_12F38C,
    *(volatile uint32_t *)off_12F390,
    *(volatile uint32_t *)off_12F394,
    *(volatile uint32_t *)off_12F398,
    *(volatile uint32_t *)off_12F404);
  event_dispatch("\x9Bstatus of 0x40328528=%08x\r\n", *(volatile uint32_t *)(*v2 + 60));
  event_dispatch("\x9Bstatus of 0x4032852c=%08x\r\n", *(volatile uint32_t *)(*v3 + 60));
  event_dispatch("\x9Bstatus of 0x40328530=%08x\r\n", *(volatile uint32_t *)(*v4 + 60));
  event_dispatch("\x9Bstatus of 0x40328534=%08x\r\n", *(volatile uint32_t *)(*v5 + 60));
  event_dispatch("\x9Bstatus of 0x4032853c=%08x\r\n", *(volatile uint32_t *)(*v6 + 60));
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (volatile uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(volatile uint32_t **)off_12F3F0;
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
      v14 = (volatile uint32_t **)dword_12F3F4;
    else
      v0 = (volatile uint32_t *)*v1;
    if ( v13 )
      v0 = *v14;
  }
  if ( v0 )
  {
    send_msg((int)v0, 68, 1, 0);
    send_msg(v0[9], 52, 1, 0);
    event_dispatch("\x9B""frmlen=%x\r\n", v0[6]);
    v7 = v0[4];
    if ( v7 )
    {
      send_msg(v7, v0[5] + 1 - v7, 1, 0);
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
    send_msg(*(volatile uint32_t *)(v8 + 8), *(volatile uint32_t *)(v8 + 12) + 1 - *(volatile uint32_t *)(v8 + 8), 1, 0);
  }
LABEL_6:
  v9 = (void *)(uintptr_t)(off_12F3B8);
  v10 = (void *)(uintptr_t)(off_12F3C0);
  v11 = (v11 & ~0xFFu) | ((uint8_t)(8) & 0xFFu);
  do
  {
    event_dispatch("\x9B""0x40320500=%08x\r\n", *v9);
    event_dispatch("\x9B""0x40320504=%08x\r\n", *v10);
    v11 = (uint8_t)(v11 - 1);
  }
  while ( v11 );
  event_dispatch("\x9B""0x40320514=%08x\r\n", *(volatile uint32_t *)off_12F3C8);
  event_dispatch("\x9B""0x40320518=%08x\r\n", *(volatile uint32_t *)off_12F3D0);
  event_dispatch("\x9B""0x4032051c=%08x\r\n", *(volatile uint32_t *)off_12F3D8);
  event_dispatch("\x9B""0x40320520=%08x\r\n", *(volatile uint32_t *)off_12F3E0);
  return event_dispatch("\x9B""0x40320560=%08x\r\n", *(volatile uint32_t *)off_12F3E8);
}


// bad_func_0x12f408 @ 0x12f408
int bad_func_0x12f408(int a1, int a2, int a3) {
  volatile int *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F45C = 1;
  }
  v3 = (volatile int *)off_12F460;
  ++*(volatile uint32_t *)off_12F460;
  result = event_dispatch("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
  if ( *(volatile int *)off_12F468 >= 0 )
  {
    mmio_clear_irqs();
    result = unknown_func_12d104(0x80000000);
  }
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F45C;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// mmio_clear_register @ 0x12f46c
int mmio_clear_register(int a1, int a2, int a3) {
  int result; // r0

  __disable_irq();
  *(volatile uint32_t *)off_12F490 = 0;
  result = event_dispatch("\x9B""ASSERT (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
while ( *(volatile uint32_t *)(uintptr_t)(off_12F498) ) ;
  return result;
}


// call_shared_handler @ 0x12f49c
int call_shared_handler(int a1, int a2, int a3) {
  return event_dispatch("\x9BWARNING (%s) at %s:%d\n", (const volatile char *)a1, (const volatile char *)a2, a3 & 0xFFFFF);
}


// bad_func_0x12f4b8 @ 0x12f4b8
void bad_func_0x12f4b8() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F4E0 = 1;
  }
  v0 = (void *)(uintptr_t)(off_12F4E4);
  v1 = *(volatile uint32_t *)off_12F4E4;
  v2 = *(volatile uint32_t *)off_12F4E4 + 1;
  *(volatile uint32_t *)off_12F4E4 = v2;
  if ( v2 )
  {
    v3 = (void *)(uintptr_t)(off_12F4E0);
    *v0 = v1;
    if ( !v1 )
    {
      if ( *v3 )
        __enable_irq();
    }
  }
}



// reset_global_0x18274c @ 0x12f4e8
volatile int *reset_global_0x18274c() {
  volatile uint64_t *v0; // r4
  volatile int *result; // r0

  v0 = (void *)(uintptr_t)(off_12F504);
  result = memset((volatile int *)off_12F504, 0, 8u);
  *v0 = 0x2FFFFFFFFLL;
  return result;
}



// init_global_0x1922d4 @ 0x12f508
int init_global_0x1922d4() {
  int v0; // r4

  v0 = dword_12F524;
  memset((volatile int *)dword_12F524, 0, 0x10u);
  zero_8_bytes((volatile uint32_t *)(v0 + 8));
  return 0;
}



// j_check_mac_status @ 0x12f528
int j_check_mac_status() {
  return interrupt_wait();
}



// read_mode_0x182ba0 @ 0x12f52c
int read_mode_0x182ba0(volatile uint16_t *a1) {
  return (int)(uintptr_t)(rx_state_process((int)(uintptr_t)(a1)));
}



// get_phy_type @ 0x12f530
int get_phy_type() {
  return 2;
}



// j_nullsub_6 @ 0x12f534
int j_nullsub_6(void) {
  return nullsub_6();
}



// check_rom_state @ 0x12f538
int check_rom_state() {
  int result; // r0

  if ( **(volatile uint8_t **)off_12F54C != 3 )
    return 1;
  result = *(volatile uint32_t *)(*(volatile uint32_t *)off_10CBD8 + 612);
  *(volatile uint32_t *)off_10CBDC = 32;
  if ( result )
    return 1;
  *(volatile uint32_t *)off_10CBE0 = 32;
  return result;
}



// j_fmac_tx_dispatch @ 0x12f550
int j_fmac_tx_dispatch() {
  return controller_status_read();
}



// load_and_process_r0 @ 0x12f554
volatile int * load_and_process_r0(volatile int *result, int a2) {
  volatile uint32_t *v2; // r4
  volatile int *v3; // r6
  volatile int *v4; // r5
  int v5; // r2

  v2 = (volatile uint32_t *)*result;
  if ( *result )
  {
    v3 = (volatile int *)dword_12F584;
    v4 = result;
    do
    {
      while ( 1 )
      {
        mem_word_load((int)v4);
        result = v3;
        if ( !v2[3] )
          break;
        result = (volatile int *)cmd_handler_a((int)v3, v2);
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


// check_chip_mode @ 0x12f588
int check_chip_mode(int result) {
  int v1; // r4
  volatile char *v2; // r0
  volatile char *v3; // r5
  volatile uint32_t *v4; // r4

  if ( **(volatile uint8_t **)off_12F5DC == 3 )
  {
    v1 = result;
    v2 = (volatile char *)controller_config_read();
    v3 = v2;
    if ( v2 )
    {
      *(volatile uint32_t *)(v1 + 24) = 49374;
      memcpy(v2, (volatile char *)v1, 0x1Cu);
      v4 = (void *)(uintptr_t)(off_12F5E0);
      while ( !*(volatile uint32_t *)off_12F5E0 )
        ;
      cmd_handler_a(((volatile uint32_t *)(uintptr_t)off_12F5E4)[0] + 604, (volatile uint32_t *)v3 - 1);
      *v4 = 1;
      gpio_set_pin7();
    }
    else
    {
      return event_dispatch(aErrUfHostRxBuf);
    }
  }
  return result;
}


// get_chip_opt @ 0x12f5ec
int get_chip_opt() {
  return memory_buffer_alloc(0);
}



// save_context_args @ 0x12f5f4
int save_context_args(unsigned int a1, int a2) {
  volatile int *v3; // r5
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12F644 = 1;
  }
  v3 = (volatile int *)off_12F648;
  ++*(volatile uint32_t *)off_12F648;
  result = call_func_182588((volatile uint32_t *)a2);
  if ( a1 <= 4 )
    --*(volatile uint8_t *)(dword_12F64C + a1);
  if ( *v3 )
  {
    v5 = *v3 - 1;
    v6 = *(volatile uint32_t *)off_12F644;
    *v3 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  --*((volatile uint32_t *)off_12F650 + 126);
  return result;
}


// get_dma_ring_bytes @ 0x12f654
int get_dma_ring_bytes() {
  return 1024;
}



// trim_leading_tab @ 0x12f65c
unsigned int trim_leading_tab(unsigned int a1, int a2, int a3) {
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
    v4 = (volatile int *)off_12F6EC;
    if ( a3 < (int)*(volatile uint32_t *)off_12F6EC )
    {
      v8 = (volatile uint8_t *)dword_12F6F4;
      do
      {
        read_memory_byte(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F6F8;
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
          gpio_write_1(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        read_memory_byte((volatile uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    read_memory_byte((volatile uint8_t *)dword_12F6F4);
    --*(volatile uint32_t *)off_12F6EC;
  }
LABEL_10:
  --*(volatile uint32_t *)off_12F6F0;
  return v3;
}



// parse_token_until_space @ 0x12f6fc
int parse_token_until_space(volatile uint8_t *a1, int a2) {
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
      read_memory_byte((volatile uint8_t *)dword_12F784);
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



// parse_ipv4_dot @ 0x12f788
volatile uint32_t * parse_ipv4_dot(int a1, volatile uint32_t *a2, int a3) {
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



// fetch_global_ptr @ 0x12f810
int fetch_global_ptr(unsigned int a1, volatile uint8_t *a2, int a3) {
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

  v3 = (volatile int *)off_12F940;
  v4 = a1;
  if ( *(volatile uint32_t *)off_12F940 )
  {
    if ( !a3 )
      goto LABEL_3;
LABEL_11:
    v11 = strlen(a3);
    v12 = (volatile int *)off_12F944;
    v13 = (void *)(uintptr_t)(off_12F94C);
    *v3 = (int)a2;
    *v12 = v11;
    *v13 = 0;
    return 0;
  }
  *(volatile uint32_t *)off_12F940 = (int)(uintptr_t)(a2);
  if ( a3 )
    goto LABEL_11;
LABEL_3:
  v6 = (volatile int *)off_12F944;
  v7 = (void *)(uintptr_t)(off_12F948);
  v8 = *(volatile uint32_t *)off_12F944;
  *(volatile uint32_t *)off_12F948 = *(volatile uint32_t *)off_12F944;
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
        v21 = (volatile uint8_t *)dword_12F950;
        *(volatile uint8_t *)*v3 = 0;
        read_memory_byte(v21);
        return *v3 - (uint32_t)a2;
      case 0x15u:
        v22 = (void *)(uintptr_t)(off_12F94C);
        *v3 = (int)a2;
        *v22 = 0;
        return -1;
      case 0x17u:
        v14 = (volatile int *)off_12F94C;
        v15 = *v3;
        if ( *(volatile uint32_t *)off_12F94C )
        {
          v16 = (unsigned int)a2;
          while ( 1 )
          {
            v17 = (volatile uint8_t *)trim_leading_tab(v16, v15, v8);
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
        v9 = (volatile int *)off_12F94C;
        if ( *(volatile int *)off_12F94C > 61 )
          goto LABEL_7;
        if ( a1 != 9 )
          goto LABEL_28;
        read_memory_byte((volatile uint8_t *)(dword_12F954 + (v8 & 7)));
        *(volatile uint32_t *)off_12F948 = (*(volatile uint32_t *)off_12F948 & 0xFFFFFFF8) + 8;
        break;
    }
    goto LABEL_27;
  }
  if ( a1 == 127 )
  {
LABEL_19:
    v20 = *v3;
    if ( *(volatile uint32_t *)off_12F94C )
      v20 = trim_leading_tab((unsigned int)a2, v20, v8);
    *v3 = v20;
    return -1;
  }
  else
  {
    v9 = (volatile int *)off_12F94C;
    if ( *(volatile int *)off_12F94C <= 61 )
    {
LABEL_28:
      *v7 = v8 + 1;
      gpio_write_1(a1);
LABEL_27:
      v23 = (volatile uint8_t *)*v3;
      *v23 = v4;
      v24 = *v9 + 1;
      *v3 = (int)(v23 + 1);
      *v9 = v24;
      return -1;
    }
LABEL_7:
    gpio_write_1(7);
    return -1;
  }
}



// parse_hex_or_dec @ 0x12f958
int parse_hex_or_dec(volatile uint8_t *a1, volatile uint32_t *a2, unsigned int a3) {
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



// init_static_tables @ 0x12fa04
int init_static_tables() {
  unsigned int v0; // r4
  unsigned int v1; // r5
  const volatile char *v2; // r2

  v0 = off_12FA24;
  v1 = off_12FA24 + 112;
  do
  {
    v2 = *(const volatile char **)(v0 + 4);
    if ( v2 )
      log_printf("%s %s\r\n", *(const volatile char **)v0, v2);
    v0 += 16;
  }
  while ( v0 != v1 );
  return 0;
}


// is_strlen_two @ 0x12fa2c
int is_strlen_two(int a1) {
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



// parse_hex16 @ 0x12fa60
int parse_hex16(int a1, volatile uint32_t *a2) {
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int a2a; // [sp+4h] [bp-4h]

  v4 = parse_hex_or_dec((volatile uint8_t *)a2[1], nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = is_strlen_two(*a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    log_printf("Unknown data size:%d\r\n", v5);
    return -1;
  }
  a2a = parse_hex_or_dec((volatile uint8_t *)a2[2], nullptr, 0);
  v5 = is_strlen_two(*a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( a2a == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = call_ptr_1b0();
      log_printf("[0x%08X] = 0x%08X\r\n", v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      log_printf("[0x%08lX] = 0x%08lX\r\n", v4, *(volatile uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      log_printf("[0x%08lX] = 0x%04X\r\n", v4, *(volatile uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        log_printf("[0x%08lX] = 0x%02X\r\n", v4, *(volatile uint8_t *)v4);
      return 0;
    }
  }
  v7 = *(volatile uint8_t *)*a2 == 82 && v4 < 0x40000000;
  send_msg(v4, a2a, (uint8_t)v5, v7);
  return 0;
}


// parse_config_entry @ 0x12fb48
int parse_config_entry(int a1, volatile uint32_t *a2) {
  int v4; // r10
  unsigned int v5; // r4
  int v6; // r6
  int v7; // r5
  unsigned int v8; // r4
  int v10; // r0

  v4 = is_strlen_two(*a2);
  if ( v4 < 0 )
  {
    log_printf("Unknown data size:%d\r\n", v4);
    return -1;
  }
  else
  {
    v5 = parse_hex_or_dec((volatile uint8_t *)a2[1], nullptr, 0x10u);
    v6 = parse_hex_or_dec((volatile uint8_t *)a2[2], nullptr, 0x10u);
    if ( a1 <= 3 )
    {
      v7 = 0;
      goto LABEL_9;
    }
    v10 = parse_hex_or_dec((volatile uint8_t *)a2[3], nullptr, 0);
    if ( v10 )
    {
      v7 = v10 - 1;
      do
      {
LABEL_9:
        while ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
        {
          v8 = v5 & 0xFFFFFFFC;
          log_printf("[0x%08X] = 0x%08lX\r\n", v8, v6);
          --v7;
          call_ptr_1b4();
          v5 = v8 + v4;
          if ( v7 == -1 )
            return 0;
        }
        switch ( v4 )
        {
          case 4:
            log_printf("[0x%08lX] = 0x%08lX\r\n", v5, v6);
            *(volatile uint32_t *)v5 = v6;
            break;
          case 2:
            log_printf("[0x%08lX] = 0x%04X\r\n", v5, (uint16_t)v6);
            *(volatile uint16_t *)v5 = v6;
            break;
          case 1:
            log_printf("[0x%08lX] = 0x%02X\r\n", v5, (uint8_t)v6);
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


// parse_hex10 @ 0x12fc38
int parse_hex10(int a1, int a2) {
  int v4; // r0
  uint16_t v6; // r0
  int v7; // r0
  int v8; // r4

  v4 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      if ( a1 <= 2 )
        goto LABEL_5;
      v6 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      **(volatile uint16_t **)off_12FCCC = v6;
      event_dispatch("cfg dbg_msk: 0x%x\n", v6);
      return 0;
    }
    else if ( v4 == 2 )
    {
      if ( a1 <= 2 )
      {
LABEL_5:
        event_dispatch(aInvalidArgs);
        return 0;
      }
      v8 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 8), nullptr, 0x10u);
      event_dispatch("cfg dbg mod: %08X\n", v8);
      ipc_set_data0(v8);
      return 0;
    }
    else
    {
      event_dispatch("invalid func: %d\n", v4);
      return 0;
    }
  }
  else
  {
    event_dispatch("cur dbg_msk: 0x%x\n", **(volatile uint16_t **)off_12FCCC);
    v7 = ipc_get_data0();
    event_dispatch("dbg mod: %08X\n", v7);
    return 0;
  }
}


// parse_hex12 @ 0x12fce4
int parse_hex12(int a1, int a2) {
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
  v4 = parse_hex_or_dec((volatile uint8_t *)v3, nullptr, 0x10u);
  v5 = parse_hex_or_dec((volatile uint8_t *)_frame.a1a, nullptr, 0x10u);
  v6 = *(volatile uint32_t *)(a2 + 8);
  v7 = v5;
  memcpy(_frame.a1a, (volatile char *)(v6 + 8), 4u);
  *(volatile uint8_t *)(v6 + 8) = 0;
  _frame.v26 = 0;
  v8 = parse_hex_or_dec((volatile uint8_t *)v6, nullptr, 0x10u);
  v6 = (v6 & ~0xFFFFu) | ((uint16_t)(parse_hex_or_dec((volatile uint8_t *)_frame.a1a, nullptr, 0x10u)) & 0xFFFFu);
  event_dispatch(aSetMonitor);
  v9 = (void *)(uintptr_t)(off_12FE58);
  v10 = (void *)(uintptr_t)(off_12FE5C);
  v11 = (void *)(uintptr_t)(off_12FE84);
  v12 = (void *)(uintptr_t)(off_12FE88);
  v13 = (void *)(uintptr_t)(off_12FE60);
  *(volatile uint32_t *)off_12FE54 = 512;
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
  *(v10 - 457698) = dword_12FE64;
  v14 = (void *)(uintptr_t)(off_12FE8C);
  v15 = (void *)(uintptr_t)(off_12FE90);
  v16 = (void *)(uintptr_t)(off_12FE6C);
  v13[37597] = dword_12FE68;
  v17 = (void *)(uintptr_t)(off_12FE94);
  v18 = (volatile unsigned int *)off_12FE70;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(volatile uint32_t *)off_12FE74 = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (volatile char *)off_12FE78;
  *(volatile uint32_t *)off_12FE78 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (volatile int *)off_12FE98;
  v22 = dword_12FE9C;
  v23 = dword_12FEA0;
  *(volatile uint32_t *)off_12FE7C = __rev16((uint16_t)v6);
  *(volatile uint32_t *)&v20[-148] = 7;
  *(volatile uint32_t *)&v20[-148] = v23;
  *v21 = v22;
  event_dispatch("set mon: mac=%08x%04x, bssid=%08x%04x\n", v4, v7, v8, (uint16_t)v6);
  return 0;
}


// is_mode_one @ 0x12fea4
int is_mode_one(int a1, int a2) {
  int v4; // r0
  int v5; // r0
  unsigned int v7; // r4

  if ( a1 <= 1 || (v4 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 4), nullptr, 0)) == 0 )
  {
    v5 = ipc_get_data1();
    event_dispatch("dbg sev: %d\n", v5);
    return 0;
  }
  if ( v4 == 1 )
  {
    if ( a1 == 2 )
    {
      event_dispatch(aInvalidArgs);
    }
    else
    {
      v7 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v7 > 5 )
      {
        event_dispatch("invalid sev_idx:%d\n", v7);
      }
      else
      {
        event_dispatch("Cfg dbg sev: %d\n", v7);
        ipc_set_data1(v7);
      }
    }
    return 0;
  }
  event_dispatch(aInvalidFunc);
  return 0;
}


// is_mode_one_v2 @ 0x12ff20
int is_mode_one_v2(int a1, int a2) {
  int v4; // r0
  int v5; // r7
  int v6; // r6
  volatile int *v7; // r4
  unsigned int v9; // r0

  if ( a1 == 1 )
  {
    rf_configure_channel();
    return 0;
  }
  else
  {
    v4 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 4), nullptr, 0);
    v5 = v4;
    if ( v4 )
      v5 = 1;
    v6 = v4;
    if ( a1 > 2 )
    {
      v7 = (volatile int *)off_12FF90;
      v9 = parse_hex_or_dec(*(volatile uint8_t **)(a2 + 8), nullptr, 0);
      if ( v9 > 0x7D0 )
        v7[91] = v9;
    }
    else
    {
      v7 = (volatile int *)off_12FF90;
    }
    if ( *((volatile uint8_t *)v7 + 363) != v5 )
    {
      *((volatile uint8_t *)v7 + 363) = v5;
      if ( v6 )
      {
        rf_get_channel_calibration();
        rf_enable_2();
      }
      else
      {
        rf_disable();
      }
    }
    event_dispatch("temp_comp en=%d, peroid_ms=%d\n", v5, v7[91]);
    return 0;
  }
}


// call_handler @ 0x12ff98
int call_handler() {
  volatile int *v0; // r4
  volatile uint32_t *v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  nvic_configure();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12FFF8 = 1;
  }
  v0 = (volatile int *)off_12FFFC;
  v1 = (volatile uint32_t *)dword_130000;
  ++*(volatile uint32_t *)off_12FFFC;
  zero_8_bytes(v1);
  zero_8_bytes((volatile uint32_t *)dword_130004);
  cmd_handler_a(dword_130000, (volatile uint32_t *)dword_130008);
  cmd_handler_a(dword_130000, (volatile uint32_t *)dword_13000C);
  cmd_handler_a(dword_130000, (volatile uint32_t *)dword_130010);
  result = cmd_handler_a(dword_130000, (volatile uint32_t *)dword_130014);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_12FFF8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// find_by_index @ 0x130018
int find_by_index(int a1) {
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

  v1 = fetch_global_ptr(a1, (volatile uint8_t *)dword_130138, 0);
  v2 = v1;
  if ( v1 >= 0 )
  {
    if ( v1 )
    {
      if ( strlen(off_130140) != v1 || strcmp(off_130140, (volatile unsigned int *)dword_130138) )
      {
        v4 = mem_word_load(dword_130144);
        v5 = v4;
        if ( v4 )
        {
          strcpy((unsigned int)(v4 + 1), dword_130138);
          cmd_handler_a(dword_130148, v5);
        }
        else
        {
          read_memory_byte(aErrCmdFreeList);
        }
      }
      else
      {
        CPSR = __get_CPSR();
        v7 = __get_CPSR();
        v8 = __get_CPSR();
        v9 = __get_CPSR();
        log_printf(aControl08xXpsr, CPSR, v7, v8, v9, __get_CPSR(), __get_CPSR());
        if ( v9 )
        {
          v12 = v9 & 0xFFFFFFF0;
          read_memory_byte(aDumpmsp);
          v13 = v12 + 256;
          do
          {
            if ( !(v12 << 28) )
              log_printf("\r\n[%08x]:", v12);
            v14 = *(volatile uint32_t *)v12;
            v12 += 4;
            log_printf(" %08X", v14);
          }
          while ( v13 != v12 );
        }
        if ( v8 )
        {
          v15 = v8 & 0xFFFFFFF0;
          read_memory_byte(aDumppsp);
          v16 = v15 + 256;
          do
          {
            if ( !(v15 << 28) )
              log_printf("\r\n[%08x]:", v15);
            v17 = *(volatile uint32_t *)v15;
            v15 += 4;
            log_printf(" %08X", v17);
          }
          while ( v16 != v15 );
        }
        read_memory_byte(aAic_0);
        v10 = (void *)(uintptr_t)(off_130154);
        v11 = *(volatile uint8_t *)off_130154;
        if ( *(volatile uint8_t *)off_130154 )
        {
          *((volatile uint8_t *)off_130158 + 783) = -4;
          v2 = 0;
          *v10 = 0;
        }
        else
        {
          *((volatile uint8_t *)off_130158 + 783) = -12;
          v2 = v11;
          *v10 = 1;
        }
      }
    }
    else
    {
      read_memory_byte(aAic);
    }
    fetch_global_ptr(0x30u, (volatile uint8_t *)dword_130138, (unsigned int)aAic);
  }
  return v2;
}


