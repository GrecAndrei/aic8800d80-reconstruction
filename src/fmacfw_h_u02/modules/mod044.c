// rf_table_lookup_1 @ 0x12c218
int rf_table_lookup_1(int a1) {
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

  v1 = *(volatile uint8_t *)(dword_12C2CC + a1);
  if ( a1 )
    irq_disable_global_3(0x40000000);
  else
    irq_disable_global_3(1024);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C2D0 = 1;
  }
  v3 = (volatile int *)off_12C2D4;
  v4 = dword_12C2E4;
  v5 = dword_12C2E4 + 8 * a1;
  ++*(volatile uint32_t *)off_12C2D4;
  v6 = (int)(uintptr_t)(list_pop(v5));
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(volatile uint32_t *)off_12C2D0, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(volatile int16_t **)off_12C2D8 >= 0 )
      goto LABEL_8;
  }
  else if ( **(volatile int16_t **)off_12C2D8 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    irq_disable_mmio_write(dword_12C2E0, dword_12C2DC, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(volatile uint32_t *)(v7 + 12), a1);
  v12 = ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] | 1;
  ++*(volatile uint16_t *)(v4 + 2 * (a1 + 12));
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] = v12;
  return 4104;
}



// rf_clock_enable_1 @ 0x12c2e8
int rf_clock_enable_1() {
  *(volatile uint32_t *)(dword_12C300 + 4680) &= ~1u;
  return irq_disable_global_2(1024);
}



// mmio_clear_bit_2 @ 0x12c304
int mmio_clear_bit_2() {
  *(volatile uint32_t *)(dword_12C31C + 4808) &= ~1u;
  return irq_disable_global_2(0x40000000);
}



// call_stack_helper @ 0x12c344
int call_stack_helper(char a1) {
  int result; // r0
  volatile unsigned int *v2; // r2
  struct __attribute__((packed)) { uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  _frame.v3[0] = a1;
  result = bt_event_handler((int)_frame.v3, &_frame.v4, _frame.v5);
  v2 = (volatile unsigned int *)off_12C384;
  *(volatile uint32_t *)off_12C384 = *(volatile uint32_t *)off_12C384 & 0xFFFF00FF | (_frame.v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | _frame.v5[0];
  return result;
}



// get_calibration_value @ 0x12c388
int get_calibration_value(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v3; // r3
  int result; // r0

  v3 = *(volatile char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(volatile uint32_t *)off_12C3A4;
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



// get_status_flag_c5 @ 0x12c3a8
int get_status_flag_c5(int result, int a2) {
  int v2; // r4
  int v3; // r0

  if ( *((volatile uint8_t *)off_12C3E8 + 197) )
  {
    v2 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v3 = rf_get_tx_power(
           (*(volatile uint32_t *)(v2 + 20) >> 11) & 7,
           *(volatile uint32_t *)(v2 + 20) & 0x7F,
           (volatile uint8_t *)(*(volatile uint32_t *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(volatile uint32_t *)(v2 + 36) = result;
  }
  else if ( **(volatile int16_t **)off_12C3EC < 0 )
  {
    return irq_disable_mmio_write(dword_12C3F4, dword_12C3F0, 92);
  }
  return result;
}



// get_alt_status_flag_c5 @ 0x12c3f8
void get_alt_status_flag_c5(int a1, int a2, volatile uint8_t *a3) {
  int v3; // r4
  int v4; // r0

  if ( *((volatile uint8_t *)off_12C434 + 197) )
  {
    v3 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v4 = rf_get_tx_power((*(volatile uint32_t *)(v3 + 20) >> 11) & 7, *(volatile uint32_t *)(v3 + 20) & 0x7F, a3);
    *(volatile uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(volatile int16_t **)off_12C438 < 0 )
  {
    irq_disable_mmio_write(dword_12C440, dword_12C43C, 109);
  }
}



// compute_byte_delta @ 0x12c444
int compute_byte_delta(int result) {
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
    return type_get(result);
  return result;
}



// is_delta_within_300m @ 0x12c470
BOOL is_delta_within_300m(int a1, int a2) {
  return *(volatile uint32_t *)(a1 + 8) - *(volatile uint32_t *)(a2 + 8) > (unsigned int)dword_12C484;
}



// match_packet_header @ 0x12c488
/* luna: Returns true when the 16-bit fields at offsets 4 and 6 match the high and low halves of the expected header, respectively. */
BOOL match_packet_header(int a1, unsigned int a2) {
  return *(volatile uint16_t *)(a1 + 4) == HIWORD(a2) && *(volatile uint16_t *)(a1 + 6) == (uint16_t)a2;
}



// ke_event_handler @ 0x12c4a4
int ke_event_handler(int a1, int a2, unsigned int a3) {
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

  v3 = (volatile int16_t **)off_12C5F0;
  if ( **(volatile int16_t **)off_12C5F0 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C5DC )
        irq_disable_mmio_write(dword_12C5E4, dword_12C5E0, 148);
    }
    else
    {
      irq_disable_mmio_write(dword_12C5E8, dword_12C5E0, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C5C4 = 1;
  }
  v7 = (volatile int *)off_12C5F4;
  v8 = (void *)(uintptr_t)(off_12C5F8);
  v9 = *((volatile uint32_t *)off_12C5F8 + 5);
  ++*(volatile uint32_t *)off_12C5F4;
  if ( v9 )
    v9 = *(volatile uint16_t *)(v9 + 4) == a1 && *(volatile uint16_t *)(v9 + 6) == a2;
  v10 = (int)(uintptr_t)(rx_read_buffer(dword_12C5CC, (void *)(uintptr_t)(off_12C5C8), a2 | (a1 << 16)));
  if ( !v10 )
  {
    v17 = ((int ( *)(int))hci_tx_alloc)(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      irq_disable_mmio_write(dword_12C5EC, dword_12C5E0, 165);
    *(volatile uint16_t *)(v10 + 4) = a1;
    *(volatile uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C5D4;
  v12 = dword_12C5CC;
  v13 = a3 + *((volatile uint32_t *)off_12C5D0 + 4);
  *(volatile uint32_t *)(v10 + 8) = v13;
  result = list_foreach(v12, (void *)(uintptr_t)(v10), (void *)(uintptr_t)(v11));
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = mm_timer_set((void *)(uintptr_t)(dword_12C5D8), *(volatile uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(volatile uint32_t *)off_12C5C4, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((volatile uint32_t *)off_12C5D0 + 4)) < 0 )
      return irq_disable_global_2(0x10000000);
  }
  else if ( (int)(v13 - *((volatile uint32_t *)off_12C5D0 + 4)) < 0 )
  {
    return irq_disable_global_2(0x10000000);
  }
  return result;
}



// invalid_handler_12c5fc @ 0x12c5fc
int invalid_handler_12c5fc(int result, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C694 = 1;
  }
  v2 = (volatile int *)off_12C698;
  v3 = (void *)(uintptr_t)(off_12C69C);
  v4 = *((volatile uint32_t *)off_12C69C + 5);
  v5 = *(volatile uint32_t *)off_12C698 + 1;
  *(volatile uint32_t *)off_12C698 = v5;
  if ( v4 )
  {
    if ( *(volatile uint16_t *)(v4 + 4) == result && *(volatile uint16_t *)(v4 + 6) == a2 )
    {
      list_pop((int)(uintptr_t)(v3 + 5));
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        mm_timer_set((void *)(uintptr_t)(v9), *(volatile uint32_t *)(v8 + 8));
        if ( **(volatile int16_t **)off_12C6A8 < 0 && (int)(*(volatile uint32_t *)(v8 + 8) - *((volatile uint32_t *)off_12C6AC + 4)) < 0 )
          irq_disable_mmio_write(dword_12C6B4, dword_12C6B0, 232);
      }
      else
      {
        mem_set_util(v9);
      }
    }
    else
    {
      result = (int)(uintptr_t)(rx_read_buffer(dword_12C6A4, (void *)(uintptr_t)(off_12C6A0), a2 | (result << 16)));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = (int)(uintptr_t)(heap_free_block((void *)(uintptr_t)(v4)));
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_12C694;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// rf_init_1 @ 0x12c6b8
int rf_init_1() {
  volatile uint32_t *v0; // r7
  volatile int *v1; // r5
  volatile int *v2; // r9
  volatile uint32_t *v3; // r6
  volatile char *v4; // r8
  int v5; // r1
  int result; // r0
  int v7; // r0
  int v8; // r4
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r4
  int v13; // r3
  volatile int *v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r2

  v0 = (void *)(uintptr_t)(off_12C760);
  v1 = (volatile int *)off_12C764;
  v2 = (volatile int *)off_12C770;
  v3 = (void *)(uintptr_t)(off_12C768);
  v4 = (volatile char *)off_12C760 + 32;
  while ( 1 )
  {
    irq_disable_global_3(0x10000000);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *v2 = 1;
    }
    v11 = *v1;
    v12 = v0[5];
    v13 = *v1 + 1;
    result = (int)v4;
    *v1 = v13;
    if ( !v12 )
      break;
    v5 = *(volatile uint32_t *)(v12 + 8);
    if ( v5 - v3[4] - 50 >= 0 )
    {
      result = mm_timer_set((void *)(uintptr_t)((int)v4), v5);
      if ( *(volatile uint32_t *)(v12 + 8) - v3[4] >= 0 )
      {
        if ( *v1 )
        {
          v16 = *v1 - 1;
          v17 = *(volatile uint32_t *)off_12C770;
          *v1 = v16;
          if ( !v16 )
          {
            if ( v17 )
              goto LABEL_15;
          }
        }
        return result;
      }
    }
    v7 = (int)(uintptr_t)(list_pop(dword_12C76C));
    v8 = v7;
    v9 = *v1 - 1;
    if ( *v1 )
    {
      v10 = *v2;
      *v1 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    mac_write_header_word(*(volatile uint16_t *)(v7 + 4), *(volatile uint16_t *)(v7 + 6), 255);
    heap_free_block((void *)(uintptr_t)(v8));
  }
  if ( v13 )
  {
    v14 = (volatile int *)off_12C770;
    *v1 = v11;
    v15 = *v14;
    if ( !v11 )
    {
      if ( v15 )
LABEL_15:
        __enable_irq();
    }
  }
  return result;
}



// rf_get_state_1 @ 0x12c774
int rf_get_state_1(int a1, int a2) {
  volatile int **v2; // r3

  v2 = *((volatile int ***)off_12C794 + 5);
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



// tx_process_queued_packets @ 0x12c798
int tx_process_queued_packets() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C7E0 = 1;
  }
  v0 = (volatile int *)off_12C7E4;
  v1 = dword_12C7E8;
  ++*(volatile uint32_t *)off_12C7E4;
  irq_disable_global_3(0x10000000);
  while ( 1 )
  {
    result = (int)(uintptr_t)(list_pop(v1));
    if ( !result )
      break;
    heap_free_block((void *)(uintptr_t)(result));
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_12C7E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// tx_send_pdu @ 0x12c7ec
int tx_send_pdu(int16_t a1, int16_t a2, int16_t a3, unsigned int a4) {
  int v8; // r0
  int v9; // r4

  v8 = ((int ( *)(unsigned int))hci_tx_alloc)(a4 + 12);
  v9 = v8;
  if ( **(volatile int16_t **)off_12C840 < 0 && !v8 )
    irq_disable_mmio_write(dword_12C848, dword_12C844, 145);
  *(volatile uint16_t *)(v9 + 4) = a1;
  *(volatile uint16_t *)(v9 + 6) = a2;
  *(volatile uint16_t *)(v9 + 8) = a3;
  *(volatile uint16_t *)(v9 + 10) = a4;
  *(volatile uint32_t *)v9 = 0;
  memset((volatile int *)(v9 + 12), 0, a4);
  return v9 + 12;
}



// rx_process_packet_1 @ 0x12c84c
/* luna: Routes a kernel message by destination task, sending low-numbered destinations through the WLAN ioctl handler and otherwise invoking the configured di */
volatile uint32_t * rx_process_packet_1(int a1) {
  int destination_task_id; // r3
  volatile char *message; // r0

  destination_task_id = *(volatile uint16_t *)(a1 - 6);
  if ( **(volatile int16_t **)off_12C8B8 >= 0 || (uint8_t)destination_task_id <= 0xEu )
  {
    if ( (uint8_t)destination_task_id <= 0xCu )
    {
      co_list_push_back(dword_12C8BC, (volatile uint32_t *)(a1 - 12));
      return (volatile uint32_t *)irq_disable_global_2(0x4000000);
    }
  }
  else
  {
    irq_disable_mmio_write((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    destination_task_id = *(volatile uint16_t *)(a1 - 6);
  }
  alloc_tx_event(
    "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(volatile uint16_t *)(a1 - 8),
    *(volatile uint16_t *)(a1 - 4),
    destination_task_id);
  message = (volatile char *)(a1 - 12);
  if ( *(volatile uint8_t *)off_12C8CC )
    return heap_free_block(message);
  else
    return (volatile uint32_t *)rx_packet_dispatch_wrapper((void *)(message));
}


// mac_write_header_word @ 0x12c8d0
int mac_write_header_word(int16_t a1, int16_t a2, int16_t a3) {
  int v3; // r0

  v3 = tx_send_pdu(a1, a2, a3, 0);
  return (int)(uintptr_t)(rx_process_packet_1(v3));
}



// nop_function @ 0x12c8e0
int nop_function(int a1, int16_t a2, int16_t a3, int16_t a4) {
  *(volatile uint16_t *)(a1 - 8) = a2;
  *(volatile uint16_t *)(a1 - 6) = a3;
  *(volatile uint16_t *)(a1 - 4) = a4;
  return (int)(uintptr_t)(rx_process_packet_1(a1));
}



// tx_process_jump @ 0x12c8f8
/* luna: Forwards the supplied packet context to `tx_pkt_process` and returns its result. */
int tx_process_jump(int a1) {
  return (int)(uintptr_t)(heap_free_block((void *)(uintptr_t)(a1)));
}



// rx_read_buffer @ 0x12c8fc
/* luna: Searches the queue for the first node accepted by the predicate, unlinks it, and returns it, or returns NULL if no node matches. */
volatile uint32_t * rx_read_buffer(int a1, int ( *a2)(volatile uint32_t *, int), int a3) {
  volatile uint32_t *current_node; // r4
  volatile uint32_t *previous_node; // r8
  int i; // r0
  int next_node; // r3

  current_node = *(volatile uint32_t **)a1;
  if ( !*(volatile uint32_t *)a1 )
    return 0;
  previous_node = 0;
  for ( i = a2(current_node, a3); ; i = a2(current_node, a3) )
  {
    next_node = *current_node;
    if ( i )
      break;
    previous_node = current_node;
    if ( !next_node )
      return 0;
    current_node = (volatile uint32_t *)*current_node;
  }
  if ( previous_node )
  {
    *previous_node = next_node;
    if ( *current_node )
    {
LABEL_8:
      *current_node = 0;
      return current_node;
    }
  }
  else
  {
    *(volatile uint32_t *)a1 = next_node;
    if ( next_node )
      goto LABEL_8;
  }
  *(volatile uint32_t *)(a1 + 4) = (int)(uintptr_t)(previous_node);
  return current_node;
}



// patch_alignment @ 0x12c954
volatile uint32_t *patch_alignment() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  volatile int *v5; // r3
  int v6; // r3

  result = (volatile uint32_t *)(dword_12C994 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C998 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12C99C);
  v2 = *(volatile uint32_t *)off_12C99C;
  v3 = *(volatile uint32_t *)off_12C99C + 1;
  v4 = (0x1922A4u & 0xFFFFFFFCu) - (uint32_t)result;
  *(volatile uint32_t *)off_12C99C = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (volatile int *)off_12C998;
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



// hci_tx_alloc @ 0x12c9a0
/* luna: Allocates an aligned HCI transmit buffer by carving space from a suitable free-list block and recording the allocation size. */
int hci_tx_alloc(int a1) {
  volatile int16_t **v1; // r7
  unsigned int aligned_request_size; // r4
  unsigned int allocation_size_with_header; // r6
  volatile uint32_t *free_block; // r3
  volatile int *v5; // r5
  int v6; // r12
  volatile uint32_t *best_fit_block; // r1
  unsigned int free_block_size; // r2
  volatile uint32_t *v9; // r2
  unsigned int remaining_block_size; // r3
  int result; // r0
  int v12; // r2

  v1 = (volatile int16_t **)off_12CA6C;
  aligned_request_size = (a1 + 3) & 0xFFFFFFFC;
  allocation_size_with_header = aligned_request_size + 4;
  if ( **(volatile int16_t **)off_12CA6C < 0 && allocation_size_with_header <= 7 )
    irq_disable_mmio_write(dword_12CA84, dword_12CA7C, 132);
  free_block = *((volatile uint32_t **)off_12CA70 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CA74 = 1;
  }
  v5 = (volatile int *)off_12CA78;
  v6 = *(volatile uint32_t *)off_12CA78 + 1;
  *(volatile uint32_t *)off_12CA78 = v6;
  if ( free_block )
  {
    best_fit_block = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        free_block_size = free_block[1];
        if ( free_block_size >= aligned_request_size + 12 )
          break;
LABEL_8:
        free_block = (volatile uint32_t *)*free_block;
        if ( !free_block )
          goto LABEL_12;
      }
      if ( best_fit_block )
      {
        if ( free_block_size < best_fit_block[1] )
          best_fit_block = free_block;
        goto LABEL_8;
      }
      best_fit_block = free_block;
      free_block = (volatile uint32_t *)*free_block;
      if ( !free_block )
      {
LABEL_12:
        if ( **v1 < 0 && !best_fit_block )
          goto LABEL_20;
        v9 = best_fit_block;
        goto LABEL_14;
      }
    }
  }
  if ( **v1 >= 0 )
    __und(0xFFu);
LABEL_20:
  irq_disable_mmio_write(dword_12CA80, dword_12CA7C, 160);
  v9 = 0;
  v6 = *v5;
  best_fit_block = 0;
LABEL_14:
  remaining_block_size = best_fit_block[1] - allocation_size_with_header;
  best_fit_block[1] = remaining_block_size;
  result = (int)v9 + remaining_block_size + 4;
  *(volatile uint32_t *)((volatile char *)v9 + remaining_block_size) = allocation_size_with_header;
  if ( v6 )
  {
    v12 = *(volatile uint32_t *)off_12CA74;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}



// heap_free_block @ 0x12ca88
volatile uint32_t * heap_free_block(volatile char *a1) {
  volatile int16_t **v1; // r9
  volatile char *v2; // r4
  int v3; // r8
  volatile char *v5; // r5
  volatile uint32_t *result; // r0
  int v7; // r12
  int v8; // r7
  int v9; // r3
  volatile uint32_t *v10; // r1
  volatile int *v11; // r3
  int v12; // r3
  int v13; // r3
  volatile char *v14; // r2
  int v15; // r1
  uint64_t v16; // r2

  v1 = (volatile int16_t **)off_12CB84;
  v2 = *((volatile char **)off_12CB6C + 7);
  v3 = *((volatile uint32_t *)a1 - 1);
  v5 = a1 - 4;
  if ( **(volatile int16_t **)off_12CB84 < 0 && a1 <= v2 )
    irq_disable_mmio_write(dword_12CB7C, dword_12CB78, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CB70 = 1;
  }
  result = (void *)(uintptr_t)(off_12CB74);
  v7 = *(volatile uint32_t *)off_12CB74;
  v8 = *(volatile uint32_t *)off_12CB74 + 1;
  *(volatile uint32_t *)off_12CB74 = v8;
  if ( !v2 )
  {
    MEMD(0) = (int)(uintptr_t)(v5);
    __und(0xFFu);
  }
  v9 = *((volatile uint32_t *)v2 + 1);
  if ( &v2[v9] != v5 )
  {
    if ( v2 > v5 )
    {
      if ( **v1 < 0 )
        irq_disable_mmio_write(dword_12CB80, dword_12CB78, 247);
      MEMD(0) = (int)(uintptr_t)(v5);
      __und(0xFFu);
    }
    while ( 1 )
    {
      v10 = (void *)(v2);
      v2 = *(volatile char **)v2;
      if ( !v2 )
        break;
      v9 = *((volatile uint32_t *)v2 + 1);
      if ( &v2[v9] == v5 )
        goto LABEL_20;
      if ( v2 > v5 )
      {
        *v10 = (int)(uintptr_t)(v5);
        if ( v2 == &v5[v3] )
        {
          *((volatile uint32_t *)a1 - 1) = *(volatile uint32_t *)v2;
          *(volatile uint32_t *)a1 = &v2[v9] - v5;
          goto LABEL_13;
        }
LABEL_12:
        *((volatile uint32_t *)a1 - 1) = (int)(uintptr_t)(v2);
        *(volatile uint32_t *)a1 = v3;
        goto LABEL_13;
      }
    }
    *v10 = (int)(uintptr_t)(v5);
    goto LABEL_12;
  }
LABEL_20:
  v13 = v9 + v3;
  v14 = *(volatile char **)v2;
  *((volatile uint32_t *)v2 + 1) = v13;
  if ( v14 == &v2[v13] )
  {
    v15 = *((volatile uint32_t *)v14 + 1);
    v16 = (v16 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)v14) & 0xFFFFFFFFu);
    v16 = (v16 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v13 + v15) << 32);
    *(volatile uint64_t *)v2 = v16;
  }
LABEL_13:
  if ( v8 )
  {
    v11 = (volatile int *)off_12CB70;
    *result = v7;
    v12 = *v11;
    if ( !v7 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}



// list_node_count @ 0x12cb94
int list_node_count(int a1, volatile int *a2, int a3) {
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
  if ( **(volatile int16_t **)off_12CBE8 < 0 && !result )
  {
    irq_disable_mmio_write(dword_12CBF0, dword_12CBEC, 239);
    return *(volatile uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}



// ke_state_set @ 0x12cbf4
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

  v2 = (volatile int16_t **)off_12CD0C;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12CD0C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    irq_disable_mmio_write((int)aTypeTaskMax, (int)aKeStateSet, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (volatile uint16_t *)(((volatile uint32_t *)(uintptr_t)off_12CD10)[4 * v6 + 2] + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      irq_disable_mmio_write((int)aIdTaskMax, (int)aKeTaskLocal_0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  irq_disable_mmio_write((int)aKeTaskLocalTyp, (int)aKeStateSet, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v17 = (void *)(&((volatile uint32_t *)(uintptr_t)off_12CD10)[4 * v6]);
  if ( *((volatile uint16_t *)v17 + 7) > v5 )
  {
    v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  irq_disable_mmio_write((int)aIdxTaskDescTyp, (int)aKeStateSet, 175);
  v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    irq_disable_mmio_write((int)aKeStateidPtr, (int)aKeStateSet, 180);
LABEL_3:
  result = alloc_tx_event("\x80\x9Dset tsk:%x:%x\n", a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(volatile uint32_t *, int))off_12CD44;
    v10 = dword_12CD18;
    v11 = (volatile int *)off_12CD1C;
    *v7 = a2;
    while ( 1 )
    {
      result = (int)rx_read_buffer(v10, v9, a1);
      v16 = (volatile uint32_t *)result;
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (volatile int *)off_12CD20;
      v13 = dword_12CD24;
      ++*(volatile uint32_t *)off_12CD20;
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
      irq_disable_global_2(0x4000000);
    }
  }
  return result;
}


// hci_cmd_handler @ 0x12cd48
/* luna: Returns the 16-bit HCI command-table entry selected by the packed table and entry indices, performing status and bounds checks along the way. */
int hci_cmd_handler(unsigned int a1) {
  volatile int16_t **v1; // r5
  unsigned int entry_index; // r6
  int table_index; // r4
  int command_table; // r5
  int row_offset; // r4
  int row_address; // r3

  v1 = (volatile int16_t **)off_12CDCC;
  entry_index = a1 >> 8;
  table_index = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12CDCC >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    irq_disable_mmio_write(dword_12CDDC, dword_12CDD4, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      command_table = dword_12CDD0;
      row_offset = 16 * table_index;
      return *(volatile uint16_t *)(*(volatile uint32_t *)(command_table + row_offset + 8) + 2 * entry_index);
    }
    if ( table_index != 14 )
      irq_disable_mmio_write(dword_12CDE4, dword_12CDE0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  irq_disable_mmio_write(dword_12CDE8, dword_12CDD4, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  command_table = dword_12CDD0;
  row_address = dword_12CDD0 + 16 * table_index;
  row_offset = 16 * table_index;
  if ( *(volatile uint16_t *)(row_address + 14) > entry_index )
    return *(volatile uint16_t *)(*(volatile uint32_t *)(command_table + row_offset + 8) + 2 * entry_index);
  irq_disable_mmio_write(dword_12CDD8, dword_12CDD4, 212);
  return *(volatile uint16_t *)(*(volatile uint32_t *)(command_table + row_offset + 8) + 2 * entry_index);
}



// hci_event_handler @ 0x12cdec
/* luna: Looks up the handler list for an HCI event and optional subevent, falls back to the event-wide list when needed, and returns the selected list’s node  */
int hci_event_handler(int a1, unsigned int a2) {
  volatile int16_t **v2; // r4
  int event_code; // r7
  unsigned int subevent_code; // r5
  int event_table; // r4
  int event_entry_offset; // r7
  int v8; // r1
  int event_entry; // r4
  int subevent_handler_list; // r1
  int result; // r0
  int fallback_handler_list; // r1
  int v13; // r3

  v2 = (volatile int16_t **)off_12CE94;
  event_code = (uint8_t)a2;
  subevent_code = a2 >> 8;
  if ( **(volatile int16_t **)off_12CE94 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a2 > 0xDu )
  {
    irq_disable_mmio_write(dword_12CEA4, dword_12CE9C, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      event_table = dword_12CE98;
      event_entry_offset = 16 * event_code;
      goto LABEL_3;
    }
    if ( event_code != 14 )
      irq_disable_mmio_write(dword_12CEAC, dword_12CEA8, 183);
  }
  else if ( (uint8_t)a2 != 13 )
  {
    goto LABEL_10;
  }
  irq_disable_mmio_write(dword_12CEB0, dword_12CE9C, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  event_table = dword_12CE98;
  v13 = dword_12CE98 + 16 * event_code;
  event_entry_offset = 16 * event_code;
  if ( *(volatile uint16_t *)(v13 + 14) <= subevent_code )
    irq_disable_mmio_write(dword_12CEA0, dword_12CE9C, 269);
LABEL_3:
  v8 = *(volatile uint32_t *)(event_table + event_entry_offset);
  event_entry = event_table + event_entry_offset;
  if ( !v8
    || (subevent_handler_list = v8 + 8 * *(volatile uint16_t *)(*(volatile uint32_t *)(event_entry + 8) + 2 * subevent_code),
        (result = list_node_count(a1, (volatile int *)subevent_handler_list, *(volatile uint16_t *)(subevent_handler_list + 4))) == 0) )
  {
    fallback_handler_list = *(volatile uint32_t *)(event_entry + 4);
    if ( fallback_handler_list )
      return list_node_count(a1, (volatile int *)fallback_handler_list, *(volatile uint16_t *)(fallback_handler_list + 4));
    else
      return 0;
  }
  return result;
}



// irq_disable_global @ 0x12ceb4
volatile uint32_t *irq_disable_global() {
  volatile int *v0; // r5
  int v1; // r0
  volatile uint32_t *result; // r0
  volatile char *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, volatile char *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CF94 = 1;
  }
  v0 = (volatile int *)off_12CF98;
  v1 = dword_12CF9C;
  ++*(volatile uint32_t *)off_12CF98;
  result = list_pop(v1);
  v3 = (volatile char *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(volatile uint32_t *)off_12CF94;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, volatile char *, uint32_t, uint32_t))hci_event_handler(
                                                               *((volatile uint16_t *)result + 2),
                                                               *((volatile uint16_t *)result + 3));
    alloc_tx_event(
      "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *((volatile uint16_t *)v3 + 2),
      *((volatile uint16_t *)v3 + 4),
      *((volatile uint16_t *)v3 + 3));
    if ( v6 )
    {
      result = (volatile uint32_t *)v6(
                           *((volatile uint16_t *)v3 + 2),
                           v3 + 12,
                           *((volatile uint16_t *)v3 + 3),
                           *((volatile uint16_t *)v3 + 4));
      if ( result == (volatile uint32_t *)1 )
        goto LABEL_12;
      if ( result == (volatile uint32_t *)2 )
      {
        result = (volatile uint32_t *)co_list_push_back(dword_12CFB0, (void *)(v3));
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(volatile int16_t **)off_12CFA4 < 0 )
          result = (volatile uint32_t *)irq_disable_mmio_write(off_12CFB8, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      alloc_tx_event(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((volatile uint16_t *)v3 + 2),
        *((volatile uint16_t *)v3 + 4),
        *((volatile uint16_t *)v3 + 3));
    }
    result = (void *)(uintptr_t)(tx_process_jump((int)(uintptr_t)(v3)));
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CF94 = 1;
  }
  v7 = *((volatile uint32_t *)off_12CFA8 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = (volatile uint32_t *)irq_disable_global_3(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(volatile uint32_t *)off_12CF94;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// return_zero @ 0x12cfbc
/* luna: Returns the constant value zero. */
int return_zero() {
  return 0;
}



// return_two @ 0x12cfc0
/* luna: Returns the constant integer value 2. */
int return_two() {
  return 2;
}



// irq_disable_global_2 @ 0x12cfc4
int irq_disable_global_2(int a1) {
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
    *(volatile uint32_t *)off_12CFF8 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12CFFC);
  v2 = (volatile int *)off_12D000;
  v3 = *(volatile uint32_t *)off_12CFFC;
  v4 = *(volatile uint32_t *)off_12CFFC + 1;
  result = a1 | *(volatile uint32_t *)off_12D000;
  *(volatile uint32_t *)off_12CFFC = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12CFF8;
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



// set_mmio_base @ 0x12d004
int set_mmio_base() {
  return irq_disable_global_2(0x10000000);
}



// irq_disable_global_3 @ 0x12d00c
int irq_disable_global_3(int a1) {
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
    *(volatile uint32_t *)off_12D044 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12D048);
  v2 = (volatile int *)off_12D04C;
  v3 = *(volatile uint32_t *)off_12D048;
  v4 = *(volatile uint32_t *)off_12D048 + 1;
  result = *(volatile uint32_t *)off_12D04C & ~a1;
  *(volatile uint32_t *)off_12D048 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12D044;
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



// process_event_queue @ 0x12d050
void process_event_queue() {
  volatile unsigned int *v0; // r6
  unsigned int v1; // r4
  volatile int16_t **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void ( *v8)(uint32_t); // r3

  v0 = (volatile unsigned int *)off_12D0B8;
  v1 = *(volatile uint32_t *)off_12D0B8;
  if ( *(volatile uint32_t *)off_12D0B8 )
  {
    v2 = (volatile int16_t **)off_12D0C4;
    v3 = dword_12D0BC;
    v4 = (void *)(uintptr_t)(off_12D0C0);
    v5 = dword_12D0C8;
    v6 = dword_12D0CC;
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
        irq_disable_mmio_write(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(volatile uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      {
        memory_barrier();
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



// update_modulation_mode @ 0x12d0d0
int update_modulation_mode() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  void *v2; // r1

  v0 = patch_alignment();
  v1 = (void *)(uintptr_t)(off_12D0F8);
  v2 = (void *)(uintptr_t)(off_12D0FC);
  *((volatile uint32_t *)off_12D0F8 + 7) = (int)(uintptr_t)(v0);
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = (int)(uintptr_t)(v2);
  return irq_disable_global_3(-1);
}



// clear_stats_buf @ 0x12d100
volatile uint32_t * clear_stats_buf(volatile uint32_t *result) {
  *result = 0;
  result[1] = 0;
  return result;
}



