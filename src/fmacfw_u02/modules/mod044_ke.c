// rf_set_channel_2 @ 0x12c358
int rf_set_channel_2(int a1) {
  int v1; // r5
  volatile int *v3; // r7
  int v4; // r8
  int v5; // r0
  int v6; // r0
  int v7; // r6
  int v8; // r3
  int v9; // r2
  void ( *v10)(uint32_t, int); // r3
  int v12; // r2

  v1 = *(volatile uint8_t *)(dword_12C40C + a1);
  if ( a1 )
    unknown_func_12d14c(0x40000000);
  else
    unknown_func_12d14c(1024);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C410 = 1;
  }
  v3 = (volatile int *)off_12C414;
  v4 = dword_12C424;
  v5 = dword_12C424 + 8 * a1;
  ++*(volatile uint32_t *)off_12C414;
  v6 = (int)(uintptr_t)(mem_word_load(v5));
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(volatile uint32_t *)off_12C410, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(volatile int16_t **)off_12C418 >= 0 )
      goto LABEL_8;
  }
  else if ( **(volatile int16_t **)off_12C418 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    mmio_clear_register(dword_12C420, dword_12C41C, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(volatile uint32_t *)(v7 + 12), a1);
  v12 = ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] | 1;
  ++*(volatile uint16_t *)(v4 + 2 * (a1 + 12));
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] = v12;
  return 4104;
}



// uart_disable @ 0x12c428
int uart_disable() {
  *(volatile uint32_t *)(dword_12C440 + 4680) &= ~1u;
  return unknown_func_12d104(1024);
}



// uart_reset @ 0x12c444
int uart_reset() {
  *(volatile uint32_t *)(dword_12C45C + 4808) &= ~1u;
  return unknown_func_12d104(0x40000000);
}



// util_format @ 0x12c484
int util_format(char a1) {
  int result; // r0
  volatile unsigned int *v2; // r2
  struct __attribute__((packed)) { uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  _frame.v3[0] = a1;
  result = rf_poll_handler((int)_frame.v3, &_frame.v4, _frame.v5);
  v2 = (volatile unsigned int *)off_12C4C4;
  *(volatile uint32_t *)off_12C4C4 = *(volatile uint32_t *)off_12C4C4 & 0xFFFF00FF | (_frame.v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | _frame.v5[0];
  return result;
}



// rf_get_rssi_2 @ 0x12c4c8
int rf_get_rssi_2(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v3; // r3
  int result; // r0

  v3 = *(volatile char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(volatile uint32_t *)off_12C4E4;
  else
    result = (uint8_t)v3;
  if ( v3 == 127 )
    result = (uint8_t)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}



// rf_check_temperature @ 0x12c4e8
void rf_check_temperature(int a1, int a2) {
  int v2; // r4
  int v3; // r0

  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_12C528)[49]) )
  {
    v2 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v3 = rx_packet_handler(
           (*(volatile uint32_t *)(v2 + 20) >> 11) & 7,
           *(volatile uint32_t *)(v2 + 20) & 0x7F,
           (volatile uint8_t *)(*(volatile uint32_t *)(a1 + 72) + 4));
    *(volatile uint32_t *)(v2 + 36) = v3 | (v3 << 8);
  }
  else if ( **(volatile int16_t **)off_12C52C < 0 )
  {
    mmio_clear_register(off_12C534, (int)aTpcUpdateFrame, 92);
  }
}


// rf_check_battery @ 0x12c538
void rf_check_battery(int a1, int a2) {
  volatile uint8_t *v2; // r2
  int v3; // r4
  int v4; // r0

  if ( BYTE1(((volatile uint32_t *)(uintptr_t)off_12C574)[49]) )
  {
    v3 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v4 = rx_packet_handler((*(volatile uint32_t *)(v3 + 20) >> 11) & 7, *(volatile uint32_t *)(v3 + 20) & 0x7F, v2);
    *(volatile uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(volatile int16_t **)off_12C578 < 0 )
  {
    mmio_clear_register(off_12C580, (int)aTpcUpdateFrame_0, 109);
  }
}


// rf_temperature_comp @ 0x12c584
int rf_temperature_comp(int result) {
  volatile int *i; // r3
  int v2; // r2
  int v3; // r3

  v2 = *(volatile char *)(result + 110);
  v3 = (char)(*(volatile uint8_t *)(result + 420) - *(volatile uint8_t *)(result + 464));
  if ( v2 == 127 )
  {
    *(volatile uint8_t *)(result + 109) = 127;
    if ( v3 == 127 )
      return result;
  }
  else if ( v3 >= v2 )
  {
    v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(result + 110)) & 0xFFu);
  }
  *(volatile uint8_t *)(result + 109) = v3;
  for ( i = *(volatile int **)(result + 240); i; i = (volatile int *)*i )
    *((volatile uint8_t *)i + 350) |= 0x10u;
  result = *(volatile uint32_t *)(result + 72);
  if ( result )
    return get_control_byte(result);
  return result;
}



// rf_timer_comp @ 0x12c5b0
BOOL rf_timer_comp(int a1, int a2) {
  return *(volatile uint32_t *)(a1 + 8) - *(volatile uint32_t *)(a2 + 8) > (unsigned int)dword_12C5C4;
}



// bt_id_match @ 0x12c5c8
BOOL bt_id_match(int a1, unsigned int a2) {
  return *(volatile uint16_t *)(a1 + 4) == HIWORD(a2) && *(volatile uint16_t *)(a1 + 6) == (uint16_t)a2;
}



// ke_timer_set @ 0x12c5e4
int ke_timer_set(int a1, int a2, unsigned int a3) {
  volatile int16_t **v3; // r11
  volatile int *v7; // r8
  volatile uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (volatile int16_t **)off_12C730;
  if ( **(volatile int16_t **)off_12C730 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C71C )
        mmio_clear_register(dword_12C724, dword_12C720, 148);
    }
    else
    {
      mmio_clear_register(dword_12C728, dword_12C720, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C704 = 1;
  }
  v7 = (volatile int *)off_12C734;
  v8 = (void *)(uintptr_t)(off_12C738);
  v9 = *((volatile uint32_t *)off_12C738 + 5);
  ++*(volatile uint32_t *)off_12C734;
  if ( v9 )
    v9 = *(volatile uint16_t *)(v9 + 4) == a1 && *(volatile uint16_t *)(v9 + 6) == a2;
  v10 = (int)(uintptr_t)(pkt_word_get(dword_12C70C, (void *)(uintptr_t)(dword_12C708), a2 | (a1 << 16)));
  if ( !v10 )
  {
    v17 = pkt_buf_alloc(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      mmio_clear_register(dword_12C72C, dword_12C720, 165);
    *(volatile uint16_t *)(v10 + 4) = a1;
    *(volatile uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C714;
  v12 = dword_12C70C;
  v13 = a3 + *((volatile uint32_t *)off_12C710 + 4);
  *(volatile uint32_t *)(v10 + 8) = v13;
  result = list_process(v12, (void *)(uintptr_t)(v10), (void *)(uintptr_t)(v11));
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = unknown_worker((void *)(uintptr_t)(dword_12C718), *(volatile uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(volatile uint32_t *)off_12C704, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((volatile uint32_t *)off_12C710 + 4)) < 0 )
      return unknown_func_12d104(0x10000000);
  }
  else if ( (int)(v13 - *((volatile uint32_t *)off_12C710 + 4)) < 0 )
  {
    return unknown_func_12d104(0x10000000);
  }
  return result;
}



// ke_int_lock @ 0x12c73c
/* luna: Cancels the kernel timer identified by its message ID and task ID, updating timer scheduling state under the interrupt lock. */
int ke_int_lock(int result, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r6
  int current_timer; // r4
  int lock_depth; // r3
  int v6; // r3
  int v7; // r2
  int active_timer; // r7
  int timer_queue; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C7D4 = 1;
  }
  v2 = (volatile int *)off_12C7D8;
  v3 = (void *)(uintptr_t)(off_12C7DC);
  current_timer = *((volatile uint32_t *)off_12C7DC + 5);
  lock_depth = *(volatile uint32_t *)off_12C7D8 + 1;
  *(volatile uint32_t *)off_12C7D8 = lock_depth;
  if ( current_timer )
  {
    if ( *(volatile uint16_t *)(current_timer + 4) == result && *(volatile uint16_t *)(current_timer + 6) == a2 )
    {
      mem_word_load((int)(uintptr_t)(v3 + 5));
      active_timer = v3[5];
      timer_queue = (int)(v3 + 8);
      if ( active_timer )
      {
        unknown_worker((void *)(uintptr_t)(timer_queue), *(volatile uint32_t *)(active_timer + 8));
        if ( **(volatile int16_t **)off_12C7E8 < 0 && (int)(*(volatile uint32_t *)(active_timer + 8) - *((volatile uint32_t *)off_12C7EC + 4)) < 0 )
          mmio_clear_register(dword_12C7F4, dword_12C7F0, 232);
      }
      else
      {
        fault_handler(timer_queue);
      }
    }
    else
    {
      result = (int)(uintptr_t)(pkt_word_get(dword_12C7E4, (void *)(uintptr_t)(dword_12C7E0), a2 | (result << 16)));
      current_timer = result;
      if ( !result )
      {
        lock_depth = *v2;
        goto LABEL_8;
      }
    }
    result = (int)(uintptr_t)(tx_pkt_enqueue((void *)(uintptr_t)(current_timer)));
    lock_depth = *v2;
  }
LABEL_8:
  if ( lock_depth )
  {
    v6 = lock_depth - 1;
    v7 = *(volatile uint32_t *)off_12C7D4;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// ke_event_schedule @ 0x12c7f8
int ke_event_schedule() {
  unsigned int v0; // r7
  volatile int *v1; // r5
  volatile int *v2; // r9
  volatile uint32_t *v3; // r8
  int v4; // r1
  unsigned int v5; // r3
  int result; // r0
  volatile unsigned int v7; // r2
  volatile char *v8; // r0
  volatile char *v9; // r4
  int v10; // r2
  int v11; // r3
  int v12; // r2
  int v13; // r4
  int v14; // r3
  volatile int *v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r2

  v0 = dword_12C8A0;
  v1 = (volatile int *)dword_12C8A4;
  v2 = (volatile int *)dword_12C8B0;
  v3 = (volatile uint32_t *)(dword_12C8A0 + 32);
  while ( 1 )
  {
    unknown_func_12d14c(0x10000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    v12 = *v1;
    v13 = *(volatile uint32_t *)(v0 + 0x14);
    v14 = *v1 + 1;
    result = (int)v3;
    *v1 = v14;
    if ( !v13 )
      break;
    v4 = *(volatile uint32_t *)(v13 + 8);
    v5 = v4 - (*(volatile uint32_t *)0x40501010u);
    if ( (int)(v5 - 50) >= 0 )
    {
      result = unknown_worker(v3, v4);
      v7 = (*(volatile uint32_t *)0x40501010u);
      if ( (int)(*(volatile uint32_t *)(v13 + 8) - v7) >= 0 )
      {
        if ( *v1 )
        {
          v17 = *v1 - 1;
          v18 = *(volatile uint32_t *)dword_12C8B0;
          *v1 = v17;
          if ( !v17 )
          {
            if ( v18 )
              goto LABEL_15;
          }
        }
        return result;
      }
    }
    v8 = (volatile char *)mem_word_load(dword_12C8AC);
    v9 = v8;
    v10 = *v1 - 1;
    if ( *v1 )
    {
      v11 = *v2;
      *v1 = v10;
      if ( !v10 )
      {
        if ( v11 )
          __enable_irq();
      }
    }
    ke_msg_send_no_param(*((volatile uint16_t *)v8 + 2), *((volatile uint16_t *)v8 + 3), 255);
    tx_pkt_enqueue(v9);
  }
  if ( v14 )
  {
    v15 = (volatile int *)dword_12C8B0;
    *v1 = v12;
    v16 = *v15;
    if ( !v12 )
    {
      if ( v16 )
LABEL_15:
        __enable_irq();
    }
  }
  return result;
}


// ke_task_find @ 0x12c8b4
int ke_task_find(int a1, int a2) {
  volatile int **v2; // r3

  v2 = *((volatile int ***)off_12C8D4 + 5);
  if ( !v2 )
    return (int)v2;
  while ( *((volatile uint16_t *)v2 + 2) != a1 || *((volatile uint16_t *)v2 + 3) != a2 )
  {
    v2 = (volatile int **)*v2;
    if ( !v2 )
      return (int)v2;
  }
  return 1;
}



// ke_int_lock_save @ 0x12c8d8
int ke_int_lock_save() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C920 = 1;
  }
  v0 = (volatile int *)off_12C924;
  v1 = dword_12C928;
  ++*(volatile uint32_t *)off_12C924;
  unknown_func_12d14c(0x10000000);
  while ( 1 )
  {
    result = (int)(uintptr_t)(mem_word_load(v1));
    if ( !result )
      break;
    tx_pkt_enqueue((void *)(uintptr_t)(result));
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_12C920;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// ke_msg_alloc @ 0x12c92c
/* luna: Allocates a kernel message, initializes its header, zeroes the parameter payload, and returns a pointer to that payload. */
int ke_msg_alloc(int16_t a1, int16_t a2, int16_t a3, unsigned int a4) {
  int v8; // r0
  int msg_header; // r4

  v8 = pkt_buf_alloc(a4 + 12);
  msg_header = v8;
  if ( **(volatile int16_t **)off_12C980 < 0 && !v8 )
    mmio_clear_register(dword_12C988, dword_12C984, 145);
  *(volatile uint16_t *)(msg_header + 4) = a1;
  *(volatile uint16_t *)(msg_header + 6) = a2;
  *(volatile uint16_t *)(msg_header + 8) = a3;
  *(volatile uint16_t *)(msg_header + 10) = a4;
  *(volatile uint32_t *)msg_header = 0;
  memset((volatile int *)(msg_header + 12), 0, a4);
  return msg_header + 12;
}



// ke_msg_send_2 @ 0x12c98c
/* luna: Routes a kernel message according to its destination and runtime mode, emitting a trace with its ID and source and destination tasks. */
volatile uint32_t * ke_msg_send_2(int a1) {
  int destination_task_id; // r3
  volatile char *message_header; // r0

  destination_task_id = *(volatile uint16_t *)(a1 - 6);
  if ( **(volatile int16_t **)off_12C9F8 >= 0 || (uint8_t)destination_task_id <= 0xEu )
  {
    if ( (uint8_t)destination_task_id <= 0xCu )
    {
      co_list_push_back(dword_12C9FC, (volatile uint32_t *)(a1 - 12));
      return (volatile uint32_t *)unknown_func_12d104(0x4000000);
    }
  }
  else
  {
    mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    destination_task_id = *(volatile uint16_t *)(a1 - 6);
  }
  event_dispatch(
    "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(volatile uint16_t *)(a1 - 8),
    *(volatile uint16_t *)(a1 - 4),
    destination_task_id);
  message_header = (volatile char *)(a1 - 12);
  if ( *(volatile uint8_t *)off_12CA0C )
    return tx_pkt_enqueue(message_header);
  else
    return (volatile uint32_t *)read_mode_0x182ba0((void *)(message_header));
}


// ke_msg_send_no_param @ 0x12ca10
/* luna: Allocates and sends a kernel message with no payload. */
int ke_msg_send_no_param(int16_t a1, int16_t a2, int16_t a3) {
  int message; // r0

  message = ke_msg_alloc(a1, a2, a3, 0);
  return (int)(uintptr_t)(ke_msg_send_2(message));
}



// store_three_halfwords_tail @ 0x12ca20
int store_three_halfwords_tail(int a1, int16_t a2, int16_t a3, int16_t a4) {
  *(volatile uint16_t *)(a1 - 8) = a2;
  *(volatile uint16_t *)(a1 - 6) = a3;
  *(volatile uint16_t *)(a1 - 4) = a4;
  return (int)(uintptr_t)(ke_msg_send_2(a1));
}



// branch_to_12cbc8 @ 0x12ca38
/* luna: Forwards the packet pointer to the transmit packet enqueue routine. */
int branch_to_12cbc8(int a1) {
  return (int)(uintptr_t)(tx_pkt_enqueue((void *)(uintptr_t)(a1)));
}



// pkt_word_get @ 0x12ca3c
volatile uint32_t * pkt_word_get(int a1, int ( *a2)(volatile uint32_t *, int), int a3) {
  volatile uint32_t *v3; // r4
  volatile uint32_t *v7; // r8
  int i; // r0
  int v9; // r3

  v3 = *(volatile uint32_t **)a1;
  if ( !*(volatile uint32_t *)a1 )
    return 0;
  v7 = 0;
  for ( i = a2(v3, a3); ; i = a2(v3, a3) )
  {
    v9 = *v3;
    if ( i )
      break;
    v7 = v3;
    if ( !v9 )
      return 0;
    v3 = (volatile uint32_t *)*v3;
  }
  if ( v7 )
  {
    *v7 = v9;
    if ( *v3 )
    {
LABEL_8:
      *v3 = 0;
      return v3;
    }
  }
  else
  {
    *(volatile uint32_t *)a1 = v9;
    if ( v9 )
      goto LABEL_8;
  }
  *(volatile uint32_t *)(a1 + 4) = (int)(uintptr_t)(v7);
  return v3;
}



// mmio_base_read @ 0x12ca94
volatile uint32_t *mmio_base_read() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  volatile int *v5; // r3
  int v6; // r3

  result = (volatile uint32_t *)(dword_12CAD4 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CAD8 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12CADC);
  v2 = *(volatile uint32_t *)off_12CADC;
  v3 = *(volatile uint32_t *)off_12CADC + 1;
  v4 = (dword_12CAE0 & 0xFFFFFFFC) - (uint32_t)result;
  *(volatile uint32_t *)off_12CADC = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (volatile int *)off_12CAD8;
    *v1 = v2;
    v6 = *v5;
    if ( !v2 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}



// pkt_buf_alloc @ 0x12cae4
int pkt_buf_alloc(int a1) {
  volatile int16_t **v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r6
  volatile uint32_t *v4; // r3
  volatile int *v5; // r5
  int v6; // r12
  volatile uint32_t *v7; // r1
  unsigned int v8; // r2
  volatile uint32_t *v9; // r2
  unsigned int v10; // r3
  int result; // r0
  int v12; // r2

  v1 = (volatile int16_t **)off_12CBAC;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(volatile int16_t **)off_12CBAC < 0 && v3 <= 7 )
    mmio_clear_register(dword_12CBC4, dword_12CBBC, 132);
  v4 = *((volatile uint32_t **)off_12CBB0 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CBB4 = 1;
  }
  v5 = (volatile int *)off_12CBB8;
  v6 = *(volatile uint32_t *)off_12CBB8 + 1;
  *(volatile uint32_t *)off_12CBB8 = v6;
  if ( v4 )
  {
    v7 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = v4[1];
        if ( v8 >= v2 + 12 )
          break;
LABEL_8:
        v4 = (volatile uint32_t *)*v4;
        if ( !v4 )
          goto LABEL_12;
      }
      if ( v7 )
      {
        if ( v8 < v7[1] )
          v7 = v4;
        goto LABEL_8;
      }
      v7 = v4;
      v4 = (volatile uint32_t *)*v4;
      if ( !v4 )
      {
LABEL_12:
        if ( **v1 < 0 && !v7 )
          goto LABEL_20;
        v9 = v7;
        goto LABEL_14;
      }
    }
  }
  if ( **v1 >= 0 )
    __und(0xFFu);
LABEL_20:
  mmio_clear_register(dword_12CBC0, dword_12CBBC, 160);
  v9 = 0;
  v6 = *v5;
  v7 = 0;
LABEL_14:
  v10 = v7[1] - v3;
  v7[1] = v10;
  result = (int)v9 + v10 + 4;
  *(volatile uint32_t *)((volatile char *)v9 + v10) = v3;
  if ( v6 )
  {
    v12 = *(volatile uint32_t *)off_12CBB4;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}



// tx_pkt_enqueue @ 0x12cbc8
/* luna: Inserts the allocation preceding the supplied pointer into the kernel’s address-ordered free list and coalesces adjacent blocks under interrupt protec */
volatile uint32_t * tx_pkt_enqueue(volatile char *a1) {
  volatile int16_t **v1; // r9
  volatile char *current_free_block; // r4
  int freed_block_size; // r8
  volatile char *freed_block_header; // r5
  volatile uint32_t *result; // r0
  int previous_critical_section_depth; // r12
  int critical_section_depth; // r7
  int current_free_block_size; // r3
  volatile char **predecessor_link; // r1
  volatile int *v11; // r3
  int v12; // r3
  int v13; // r3
  volatile char *v14; // r2
  int v15; // r1
  uint64_t v16; // r2

  v1 = (volatile int16_t **)off_12CCC4;
  current_free_block = *((volatile char **)off_12CCAC + 7);
  freed_block_size = *((volatile uint32_t *)a1 - 1);
  freed_block_header = a1 - 4;
  if ( **(volatile int16_t **)off_12CCC4 < 0 && a1 <= current_free_block )
    mmio_clear_register((int)aUint32TMemPtrU, (int)aKeFree, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CCB0 = 1;
  }
  result = (void *)(uintptr_t)(off_12CCB4);
  previous_critical_section_depth = *(volatile uint32_t *)off_12CCB4;
  critical_section_depth = *(volatile uint32_t *)off_12CCB4 + 1;
  *(volatile uint32_t *)off_12CCB4 = critical_section_depth;
  if ( !current_free_block )
  {
    MEMD(0) = (int)(uintptr_t)(freed_block_header);
    __und(0xFFu);
  }
  current_free_block_size = *((volatile uint32_t *)current_free_block + 1);
  if ( &current_free_block[current_free_block_size] != freed_block_header )
  {
    if ( current_free_block > freed_block_header )
    {
      if ( **v1 < 0 )
        mmio_clear_register((int)aPrevNodeNull, (int)aKeFree, 247);
      MEMD(0) = (int)(uintptr_t)(freed_block_header);
      __und(0xFFu);
    }
    while ( 1 )
    {
      predecessor_link = (volatile char **)current_free_block;
      current_free_block = *(volatile char **)current_free_block;
      if ( !current_free_block )
        break;
      current_free_block_size = *((volatile uint32_t *)current_free_block + 1);
      if ( &current_free_block[current_free_block_size] == freed_block_header )
        goto LABEL_20;
      if ( current_free_block > freed_block_header )
      {
        *predecessor_link = freed_block_header;
        if ( current_free_block == &freed_block_header[freed_block_size] )
        {
          *((volatile uint32_t *)a1 - 1) = *(volatile uint32_t *)current_free_block;
          *(volatile uint32_t *)a1 = &current_free_block[current_free_block_size] - freed_block_header;
          goto LABEL_13;
        }
LABEL_12:
        *((volatile uint32_t *)a1 - 1) = (int)(uintptr_t)(current_free_block);
        *(volatile uint32_t *)a1 = freed_block_size;
        goto LABEL_13;
      }
    }
    *predecessor_link = freed_block_header;
    goto LABEL_12;
  }
LABEL_20:
  v13 = current_free_block_size + freed_block_size;
  v14 = *(volatile char **)current_free_block;
  *((volatile uint32_t *)current_free_block + 1) = v13;
  if ( v14 == &current_free_block[v13] )
  {
    v15 = *((volatile uint32_t *)v14 + 1);
    v16 = (v16 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)v14) & 0xFFFFFFFFu);
    v16 = (v16 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v13 + v15) << 32);
    *(volatile uint64_t *)current_free_block = v16;
  }
LABEL_13:
  if ( critical_section_depth )
  {
    v11 = (volatile int *)off_12CCB0;
    *result = previous_critical_section_depth;
    v12 = *v11;
    if ( !previous_critical_section_depth )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}


// iterate_word_array @ 0x12ccd4
int iterate_word_array(int a1, volatile int *a2, int a3) {
  int v3; // r3
  int v5; // r2
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int result; // r0

  if ( !a3 )
    return 0;
  v3 = a3 - 1;
  v5 = *a2;
  while ( 1 )
  {
    v6 = *(volatile uint16_t *)(v5 + 8 * v3);
    v7 = 8 * v3;
    v8 = v5 + 8 * v3--;
    if ( v6 == a1 )
      break;
    if ( v3 == -1 )
      return 0;
  }
  result = *(volatile uint32_t *)(v8 + 4);
  if ( **(volatile int16_t **)off_12CD28 < 0 && !result )
  {
    mmio_clear_register((int)aStateHandlerMs, (int)aKeHandlerSearc, 239);
    return *(volatile uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}


// ke_state_set @ 0x12cd34
int ke_state_set(unsigned int a1, int a2) {
  volatile int16_t **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  volatile uint16_t *v7; // r9
  int result; // r0
  int ( *v9)(volatile uint32_t *, int); // r8
  int v10; // r7
  volatile int *v11; // r6
  volatile int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  volatile uint32_t *v16; // r1
  volatile int *v17; // r6

  v2 = (volatile int16_t **)off_12CE4C;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12CE4C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_clear_register((int)aTypeTaskMax, (int)aKeStateSet, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (volatile uint16_t *)(((volatile uint32_t *)(uintptr_t)off_12CE50)[4 * v6 + 2] + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      mmio_clear_register((int)aIdTaskMax, (int)aKeTaskLocal_0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  mmio_clear_register((int)aKeTaskLocalTyp, (int)aKeStateSet, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v17 = (void *)(&((volatile uint32_t *)(uintptr_t)off_12CE50)[4 * v6]);
  if ( *((volatile uint16_t *)v17 + 7) > v5 )
  {
    v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  mmio_clear_register((int)aIdxTaskDescTyp, (int)aKeStateSet, 175);
  v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    mmio_clear_register((int)aKeStateidPtr, (int)aKeStateSet, 180);
LABEL_3:
  result = event_dispatch("\x80\x9Dset tsk:%x:%x\n", a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(volatile uint32_t *, int))off_12CE84;
    v10 = dword_12CE58;
    v11 = (volatile int *)off_12CE5C;
    *v7 = a2;
    while ( 1 )
    {
      result = (int)pkt_word_get(v10, v9, a1);
      v16 = (volatile uint32_t *)result;
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (volatile int *)off_12CE60;
      v13 = dword_12CE64;
      ++*(volatile uint32_t *)off_12CE60;
      co_list_push_back(v13, v16);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      unknown_func_12d104(0x4000000);
    }
  }
  return result;
}


// rx_rate_field_parse @ 0x12ce88
int rx_rate_field_parse(unsigned int a1) {
  volatile int16_t **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (volatile int16_t **)off_12CF0C;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12CF0C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_clear_register(dword_12CF1C, dword_12CF14, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12CF10;
      v5 = 16 * v3;
      return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      mmio_clear_register(dword_12CF24, dword_12CF20, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  mmio_clear_register(dword_12CF28, dword_12CF14, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12CF10;
  v7 = dword_12CF10 + 16 * v3;
  v5 = 16 * v3;
  if ( *(volatile uint16_t *)(v7 + 14) > v2 )
    return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
  mmio_clear_register(dword_12CF18, dword_12CF14, 212);
  return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
}



// rx_format_field_parse @ 0x12cf2c
int rx_format_field_parse(int a1, unsigned int a2) {
  volatile int16_t **v2; // r4
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  int v13; // r3

  v2 = (volatile int16_t **)off_12CFD4;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(volatile int16_t **)off_12CFD4 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a2 > 0xDu )
  {
    mmio_clear_register(dword_12CFE4, dword_12CFDC, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12CFD8;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      mmio_clear_register(dword_12CFEC, dword_12CFE8, 183);
  }
  else if ( (uint8_t)a2 != 13 )
  {
    goto LABEL_10;
  }
  mmio_clear_register(dword_12CFF0, dword_12CFDC, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12CFD8;
  v13 = dword_12CFD8 + 16 * v4;
  v7 = 16 * v4;
  if ( *(volatile uint16_t *)(v13 + 14) <= v5 )
    mmio_clear_register(dword_12CFE0, dword_12CFDC, 269);
LABEL_3:
  v8 = *(volatile uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(volatile uint16_t *)(*(volatile uint32_t *)(v9 + 8) + 2 * v5),
        (result = iterate_word_array(a1, (volatile int *)v10, *(volatile uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(volatile uint32_t *)(v9 + 4);
    if ( v12 )
      return iterate_word_array(a1, (volatile int *)v12, *(volatile uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}



// unknown_func_12cff4 @ 0x12cff4
/* luna: Pops a queued kernel message, invokes its destination task handler, and applies the handler’s message-retention result. */
volatile uint32_t *unknown_func_12cff4() {
  volatile int *critical_nesting; // r5
  int v1; // r0
  volatile uint32_t *result; // r0
  volatile char *message; // r4
  int v4; // r3
  int v5; // r2
  int ( *message_handler)(uint32_t, volatile char *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12D0D4 = 1;
  }
  critical_nesting = (volatile int *)off_12D0D8;
  v1 = dword_12D0DC;
  ++*(volatile uint32_t *)off_12D0D8;
  result = mem_word_load(v1);
  message = (volatile char *)result;
  if ( *critical_nesting )
  {
    v4 = *critical_nesting - 1;
    v5 = *(volatile uint32_t *)off_12D0D4;
    *critical_nesting = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    message_handler = (int ( *)(uint32_t, volatile char *, uint32_t, uint32_t))rx_format_field_parse(
                                                               *((volatile uint16_t *)result + 2),
                                                               *((volatile uint16_t *)result + 3));
    event_dispatch(
      "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *((volatile uint16_t *)message + 2),
      *((volatile uint16_t *)message + 4),
      *((volatile uint16_t *)message + 3));
    if ( message_handler )
    {
      result = (volatile uint32_t *)message_handler(
                           *((volatile uint16_t *)message + 2),
                           message + 12,
                           *((volatile uint16_t *)message + 3),
                           *((volatile uint16_t *)message + 4));
      if ( result == (volatile uint32_t *)1 )
        goto LABEL_12;
      if ( result == (volatile uint32_t *)2 )
      {
        result = (volatile uint32_t *)co_list_push_back(dword_12D0F0, (void *)(message));
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(volatile int16_t **)off_12D0E4 < 0 )
          result = (volatile uint32_t *)mmio_clear_register(off_12D0F8, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      event_dispatch(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((volatile uint16_t *)message + 2),
        *((volatile uint16_t *)message + 4),
        *((volatile uint16_t *)message + 3));
    }
    result = (void *)(uintptr_t)(branch_to_12cbc8((int)(uintptr_t)(message)));
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12D0D4 = 1;
  }
  v7 = *((volatile uint32_t *)off_12D0E8 + 1);
  v8 = *critical_nesting + 1;
  *critical_nesting = v8;
  if ( !v7 )
  {
    result = (volatile uint32_t *)unknown_func_12d14c(0x4000000);
    v8 = *critical_nesting;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(volatile uint32_t *)off_12D0D4;
    *critical_nesting = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// get_band_2g @ 0x12d0fc
int get_band_2g() {
  return 0;
}



// get_band_all @ 0x12d100
int get_band_all() {
  return 2;
}



// unknown_func_12d104 @ 0x12d104
int unknown_func_12d104(int a1) {
  volatile uint32_t *v1; // r2
  volatile int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  volatile int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12D138 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12D13C);
  v2 = (volatile int *)off_12D140;
  v3 = *(volatile uint32_t *)off_12D13C;
  v4 = *(volatile uint32_t *)off_12D13C + 1;
  result = a1 | *(volatile uint32_t *)off_12D140;
  *(volatile uint32_t *)off_12D13C = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12D138;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// get_band_mask @ 0x12d144
int get_band_mask() {
  return unknown_func_12d104(0x10000000);
}



// unknown_func_12d14c @ 0x12d14c
int unknown_func_12d14c(int a1) {
  volatile uint32_t *v1; // r2
  volatile int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  volatile int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12D184 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12D188);
  v2 = (volatile int *)off_12D18C;
  v3 = *(volatile uint32_t *)off_12D188;
  v4 = *(volatile uint32_t *)off_12D188 + 1;
  result = *(volatile uint32_t *)off_12D18C & ~a1;
  *(volatile uint32_t *)off_12D188 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12D184;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// tx_ring_peek @ 0x12d190
void tx_ring_peek() {
  volatile unsigned int *v0; // r6
  unsigned int v1; // r4
  volatile int16_t **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void ( *v8)(uint32_t); // r3

  v0 = (volatile unsigned int *)off_12D1F8;
  v1 = *(volatile uint32_t *)off_12D1F8;
  if ( *(volatile uint32_t *)off_12D1F8 )
  {
    v2 = (volatile int16_t **)off_12D204;
    v3 = dword_12D1FC;
    v4 = (void *)(uintptr_t)(off_12D200);
    v5 = dword_12D208;
    v6 = dword_12D20C;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 27 )
        {
          v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        mmio_clear_register(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(volatile uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      {
        dummy_store_global();
        if ( !v1 )
          return;
      }
      else if ( !v1 )
      {
        return;
      }
    }
  }
}



// assert_fail_record @ 0x12d210
int assert_fail_record() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  void *v2; // r1

  v0 = mmio_base_read();
  v1 = (void *)(uintptr_t)(off_12D238);
  v2 = (void *)(uintptr_t)(off_12D23C);
  *((volatile uint32_t *)off_12D238 + 7) = (int)(uintptr_t)(v0);
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = (int)(uintptr_t)(v2);
  return unknown_func_12d14c(-1);
}



// zero_8_bytes @ 0x12d240
/* luna: Clears two volatile 32-bit words at the supplied address and returns that address. */
volatile uint32_t * zero_8_bytes(volatile uint32_t *result) {
  *result = 0;
  result[1] = 0;
  return result;
}



