// ke_task_dispatch @ 0x12c580
int ke_task_dispatch(int a1) {
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

  v1 = *(volatile uint8_t *)(dword_12C634 + a1);
  if ( a1 )
    set_system_flag_2(0x40000000);
  else
    set_system_flag_2(1024);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C638 = 1;
  }
  v3 = (volatile int *)off_12C63C;
  v4 = dword_12C64C;
  v5 = dword_12C64C + 8 * a1;
  ++*(volatile uint32_t *)off_12C63C;
  v6 = (int)(uintptr_t)(list_pop_front(v5));
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(volatile uint32_t *)off_12C638, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(volatile int16_t **)off_12C640 >= 0 )
      goto LABEL_8;
  }
  else if ( **(volatile int16_t **)off_12C640 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    mmio_irq_clear(dword_12C648, dword_12C644, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(volatile uint32_t *)(v7 + 12), a1);
  v12 = ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] | 1;
  ++*(volatile uint16_t *)(v4 + 2 * (a1 + 12));
  ((volatile uint32_t *)(uintptr_t)0x40021000u)[16 * v1 + 2] = v12;
  return 4104;
}



// mmio_tail_write @ 0x12c650
int mmio_tail_write() {
  *(volatile uint32_t *)(dword_12C668 + 4680) &= ~1u;
  return set_system_flag_1(1024);
}



// mmio_tail_write_alt @ 0x12c66c
int mmio_tail_write_alt() {
  *(volatile uint32_t *)(dword_12C684 + 4808) &= ~1u;
  return set_system_flag_1(0x40000000);
}



// util_format_string @ 0x12c6ac
int util_format_string(char a1) {
  int result; // r0
  volatile unsigned int *v2; // r2
  struct __attribute__((packed)) { uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  _frame.v3[0] = a1;
  result = llm_task_handler((int)_frame.v3, &_frame.v4, _frame.v5);
  v2 = (volatile unsigned int *)off_12C6EC;
  *(volatile uint32_t *)off_12C6EC = *(volatile uint32_t *)off_12C6EC & 0xFFFF00FF | (_frame.v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | _frame.v5[0];
  return result;
}



// util_chk_field @ 0x12c6f0
int util_chk_field(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int v3; // r3
  int result; // r0

  v3 = *(volatile char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(volatile uint32_t *)off_12C70C;
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



// scan_done_check @ 0x12c710
int scan_done_check(int result, int a2) {
  int v2; // r4
  int v3; // r0

  if ( *((volatile uint8_t *)off_12C750 + 197) )
  {
    v2 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v3 = llm_rx_pdu_handler(
           (*(volatile uint32_t *)(v2 + 20) >> 11) & 7,
           *(volatile uint32_t *)(v2 + 20) & 0x7F,
           (volatile uint8_t *)(*(volatile uint32_t *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(volatile uint32_t *)(v2 + 36) = result;
  }
  else if ( **(volatile int16_t **)off_12C754 < 0 )
  {
    return mmio_irq_clear(dword_12C75C, dword_12C758, 92);
  }
  return result;
}



// scan_done_check_alt @ 0x12c760
void scan_done_check_alt(int a1, int a2, volatile uint8_t *a3) {
  int v3; // r4
  int v4; // r0

  if ( *((volatile uint8_t *)off_12C79C + 197) )
  {
    v3 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 76) + 48);
    v4 = llm_rx_pdu_handler((*(volatile uint32_t *)(v3 + 20) >> 11) & 7, *(volatile uint32_t *)(v3 + 20) & 0x7F, a3);
    *(volatile uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(volatile int16_t **)off_12C7A0 < 0 )
  {
    mmio_irq_clear(dword_12C7A8, dword_12C7A4, 109);
  }
}



// scan_rssi_compare @ 0x12c7ac
int scan_rssi_compare(int result) {
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
    return remove_entry_by_owner(result);
  return result;
}



// timeout_exceeded @ 0x12c7dc
BOOL timeout_exceeded(int a1, int a2, int a3, int a4) {
  return a4 - a3 > (unsigned int)dword_12C7EC;
}



// match_and_sub @ 0x12c7f0
BOOL match_and_sub(int a1, unsigned int a2) {
  return *(volatile uint16_t *)(a1 + 4) == HIWORD(a2) && *(volatile uint16_t *)(a1 + 6) == (uint16_t)a2;
}



// patch_aware_dispatch @ 0x12c80c
int patch_aware_dispatch(int a1, int a2, unsigned int a3) {
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

  v3 = (volatile int16_t **)off_12C958;
  if ( **(volatile int16_t **)off_12C958 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C944 )
        mmio_irq_clear(dword_12C94C, dword_12C948, 148);
    }
    else
    {
      mmio_irq_clear(dword_12C950, dword_12C948, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C92C = 1;
  }
  v7 = (volatile int *)off_12C95C;
  v8 = (void *)(uintptr_t)(off_12C960);
  v9 = *((volatile uint32_t *)off_12C960 + 5);
  ++*(volatile uint32_t *)off_12C95C;
  if ( v9 )
    v9 = *(volatile uint16_t *)(v9 + 4) == a1 && *(volatile uint16_t *)(v9 + 6) == a2;
  v10 = (int)(uintptr_t)(tx_list_foreach(dword_12C934, (void *)(uintptr_t)(dword_12C930), a2 | (a1 << 16)));
  if ( !v10 )
  {
    v17 = mem_alloc_align(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      mmio_irq_clear(dword_12C954, dword_12C948, 165);
    *(volatile uint16_t *)(v10 + 4) = a1;
    *(volatile uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C93C;
  v12 = dword_12C934;
  v13 = a3 + *((volatile uint32_t *)off_12C938 + 4);
  *(volatile uint32_t *)(v10 + 8) = v13;
  result = list_find(v12, (void *)(uintptr_t)(v10), (void *)(uintptr_t)(v11));
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = ke_event_lock((void *)(uintptr_t)(dword_12C940), *(volatile uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(volatile uint32_t *)off_12C92C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((volatile uint32_t *)off_12C938 + 4)) < 0 )
      return set_system_flag_1(0x10000000);
  }
  else if ( (int)(v13 - *((volatile uint32_t *)off_12C938 + 4)) < 0 )
  {
    return set_system_flag_1(0x10000000);
  }
  return result;
}



// irq_lock @ 0x12c964
volatile char * irq_lock(volatile char *result, int a2) {
  volatile int *v2; // r5
  volatile uint32_t *v3; // r6
  volatile char *v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  volatile uint32_t *v9; // r0
  volatile unsigned int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12C9FC = 1;
  }
  v2 = (volatile int *)off_12CA00;
  v3 = (void *)(uintptr_t)(off_12CA04);
  v4 = *((volatile char **)off_12CA04 + 5);
  v5 = *(volatile uint32_t *)off_12CA00 + 1;
  *(volatile uint32_t *)off_12CA00 = v5;
  if ( v4 )
  {
    if ( (volatile char *)*((volatile uint16_t *)v4 + 2) == result && *((volatile uint16_t *)v4 + 3) == a2 )
    {
      list_pop_front((int)(v3 + 5));
      v8 = v3[5];
      v9 = v3 + 8;
      if ( v8 )
      {
        ke_event_lock(v9, *(volatile uint32_t *)(v8 + 8));
        if ( **(volatile int16_t **)off_12CA10 < 0 )
        {
          v10 = (*(volatile uint32_t *)0x40501010u);
          if ( (int)(*(volatile uint32_t *)(v8 + 8) - v10) < 0 )
            mmio_irq_clear((int)aFirstHalMachwT, (int)aKeTimerClear, 232);
        }
      }
      else
      {
        ke_event_set_lock((int)(uintptr_t)(v9));
      }
    }
    else
    {
      result = (volatile char *)tx_list_foreach(
                         dword_12CA0C,
                         (int ( *)(volatile uint32_t *, int))off_12CA08,
                         a2 | ((uint32_t)result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = (volatile char *)hci_tx_packet(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_12C9FC;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// hci_tx_queue_drain @ 0x12ca20
int hci_tx_queue_drain() {
  volatile uint32_t *v0; // r7
  volatile int *v1; // r5
  volatile int *v2; // r9
  volatile uint32_t *v3; // r6
  volatile char *v4; // r8
  int v5; // r1
  int result; // r0
  int v7; // r0
  int v8; // r3
  int v9; // r4
  int v10; // r2
  int v11; // r2
  int v12; // r4
  int v13; // r3
  volatile int *v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r2

  v0 = (void *)(uintptr_t)(off_12CAC8);
  v1 = (volatile int *)off_12CACC;
  v2 = (volatile int *)off_12CAD8;
  v3 = (void *)(uintptr_t)(off_12CAD0);
  v4 = (volatile char *)off_12CAC8 + 32;
  while ( 1 )
  {
    set_system_flag_2(0x10000000);
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
      result = ke_event_lock((void *)(uintptr_t)((int)v4), v5);
      if ( *(volatile uint32_t *)(v12 + 8) - v3[4] >= 0 )
      {
        if ( *v1 )
        {
          v16 = *v1 - 1;
          v17 = *(volatile uint32_t *)off_12CAD8;
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
    v7 = (int)(uintptr_t)(list_pop_front(dword_12CAD4));
    v8 = *v1;
    v9 = v7;
    v10 = *v1 - 1;
    if ( *v1 )
    {
      v8 = *v2;
      *v1 = v10;
      if ( !v10 )
      {
        if ( v8 )
          __enable_irq();
      }
    }
    ((int (*)())hci_evt_alloc_send)(*(volatile uint16_t *)(v7 + 4), *(volatile uint16_t *)(v7 + 6), 255, v8);
    hci_tx_packet((void *)(uintptr_t)(v9));
  }
  if ( v13 )
  {
    v14 = (volatile int *)off_12CAD8;
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



// find_hci_conn_by_handle @ 0x12cadc
int find_hci_conn_by_handle(int a1, int a2) {
  volatile int **v2; // r3

  v2 = *((volatile int ***)off_12CAFC + 5);
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



// irq_lock_small @ 0x12cb00
int irq_lock_small() {
  volatile int *v0; // r5
  int v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CB48 = 1;
  }
  v0 = (volatile int *)off_12CB4C;
  v1 = dword_12CB50;
  ++*(volatile uint32_t *)off_12CB4C;
  set_system_flag_2(0x10000000);
  while ( 1 )
  {
    result = (int)(uintptr_t)(list_pop_front(v1));
    if ( !result )
      break;
    hci_tx_packet((void *)(uintptr_t)(result));
  }
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_12CB48;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// bt_buf_alloc @ 0x12cb54
int bt_buf_alloc(int16_t a1, int16_t a2, int16_t a3, unsigned int a4) {
  int v8; // r0
  int v9; // r4

  v8 = mem_alloc_align(a4 + 12);
  v9 = v8;
  if ( **(volatile int16_t **)off_12CBA8 < 0 && !v8 )
    mmio_irq_clear(dword_12CBB0, dword_12CBAC, 145);
  *(volatile uint16_t *)(v9 + 4) = a1;
  *(volatile uint16_t *)(v9 + 6) = a2;
  *(volatile uint16_t *)(v9 + 8) = a3;
  *(volatile uint16_t *)(v9 + 10) = a4;
  *(volatile uint32_t *)v9 = 0;
  memset((volatile int *)(v9 + 12), 0, a4);
  return v9 + 12;
}



// hci_evt_send @ 0x12cbb4
volatile uint32_t * hci_evt_send(int a1) {
  int v1; // r3
  volatile char *v4; // r0

  v1 = *(volatile uint16_t *)(a1 - 6);
  if ( **(volatile int16_t **)off_12CC20 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      check_abort_flag(dword_12CC24, (volatile uint32_t *)(a1 - 12));
      return (volatile uint32_t *)set_system_flag_1(0x4000000);
    }
  }
  else
  {
    mmio_irq_clear((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    v1 = *(volatile uint16_t *)(a1 - 6);
  }
  ke_event_schedule_1(
    "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(volatile uint16_t *)(a1 - 8),
    *(volatile uint16_t *)(a1 - 4),
    v1);
  v4 = (volatile char *)(a1 - 12);
  if ( *(volatile uint8_t *)off_12CC34 )
    return hci_tx_packet(v4);
  else
    return (volatile uint32_t *)patch_jump((void *)(v4));
}


// hci_evt_alloc_send @ 0x12cc38
int hci_evt_alloc_send(int16_t a1, int16_t a2, int16_t a3) {
  int v3; // r0

  v3 = bt_buf_alloc(a1, a2, a3, 0);
  return (int)(uintptr_t)(hci_evt_send(v3));
}



// hci_evt_prepare @ 0x12cc48
int hci_evt_prepare(int a1, int16_t a2, int16_t a3, int16_t a4) {
  *(volatile uint16_t *)(a1 - 8) = a2;
  *(volatile uint16_t *)(a1 - 6) = a3;
  *(volatile uint16_t *)(a1 - 4) = a4;
  return (int)(uintptr_t)(hci_evt_send(a1));
}



// jump_to_tx_entry @ 0x12cc60
int jump_to_tx_entry(int a1) {
  return (int)(uintptr_t)(hci_tx_packet((void *)(uintptr_t)(a1)));
}



// tx_list_foreach @ 0x12cc64
volatile uint32_t * tx_list_foreach(int a1, int ( *a2)(volatile uint32_t *, int), int a3) {
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



// align_and_irq_lock @ 0x12ccbc
volatile uint32_t *align_and_irq_lock() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  volatile int *v5; // r3
  int v6; // r3

  result = (volatile uint32_t *)(dword_12CCFC & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CD00 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12CD04);
  v2 = *(volatile uint32_t *)off_12CD04;
  v3 = *(volatile uint32_t *)off_12CD04 + 1;
  v4 = (dword_12CD08 & 0xFFFFFFFC) - (uint32_t)result;
  *(volatile uint32_t *)off_12CD04 = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (volatile int *)off_12CD00;
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



// mem_alloc_align @ 0x12cd0c
int mem_alloc_align(int a1) {
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

  v1 = (volatile int16_t **)off_12CDD4;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(volatile int16_t **)off_12CDD4 < 0 && v3 <= 7 )
    mmio_irq_clear(dword_12CDEC, dword_12CDE4, 132);
  v4 = *((volatile uint32_t **)off_12CDD8 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CDDC = 1;
  }
  v5 = (volatile int *)off_12CDE0;
  v6 = *(volatile uint32_t *)off_12CDE0 + 1;
  *(volatile uint32_t *)off_12CDE0 = v6;
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
  mmio_irq_clear(dword_12CDE8, dword_12CDE4, 160);
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
    v12 = *(volatile uint32_t *)off_12CDDC;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}



// hci_tx_packet @ 0x12cdf0
volatile uint32_t * hci_tx_packet(volatile char *a1) {
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

  v1 = (volatile int16_t **)off_12CEEC;
  v2 = *((volatile char **)off_12CED4 + 7);
  v3 = *((volatile uint32_t *)a1 - 1);
  v5 = a1 - 4;
  if ( **(volatile int16_t **)off_12CEEC < 0 && a1 <= v2 )
    mmio_irq_clear(dword_12CEE4, dword_12CEE0, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12CED8 = 1;
  }
  result = (void *)(uintptr_t)(off_12CEDC);
  v7 = *(volatile uint32_t *)off_12CEDC;
  v8 = *(volatile uint32_t *)off_12CEDC + 1;
  *(volatile uint32_t *)off_12CEDC = v8;
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
        mmio_irq_clear(dword_12CEE8, dword_12CEE0, 247);
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
    v11 = (volatile int *)off_12CED8;
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



// list_process_count @ 0x12cefc
int list_process_count(int a1, volatile int *a2, int a3) {
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
  if ( **(volatile int16_t **)off_12CF50 < 0 && !result )
  {
    mmio_irq_clear((int)aStateHandlerMs, (int)aKeHandlerSearc, 239);
    return *(volatile uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}


// hci_cmd_send @ 0x12cf5c
int hci_cmd_send(unsigned int a1, int a2) {
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

  v2 = (volatile int16_t **)off_12D074;
  v5 = a1 >> 8;
  v6 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12D074 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_irq_clear((int)aTypeTaskMax, (int)aKeStateSet, 173);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v7 = (volatile uint16_t *)(((volatile uint32_t *)(uintptr_t)off_12D078)[4 * v6 + 2] + 2 * v5);
      goto LABEL_3;
    }
    if ( v6 != 14 )
      mmio_irq_clear((int)aIdTaskMax, (int)aKeTaskLocal_0, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_16;
  }
  mmio_irq_clear((int)aKeTaskLocalTyp, (int)aKeStateSet, 174);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_16:
  v17 = (void *)(&((volatile uint32_t *)(uintptr_t)off_12D078)[4 * v6]);
  if ( *((volatile uint16_t *)v17 + 7) > v5 )
  {
    v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
    if ( v7 )
      goto LABEL_3;
    goto LABEL_18;
  }
  mmio_irq_clear((int)aIdxTaskDescTyp, (int)aKeStateSet, 175);
  v7 = (volatile uint16_t *)(v17[2] + 2 * v5);
  if ( **v2 < 0 && !v7 )
LABEL_18:
    mmio_irq_clear((int)aKeStateidPtr, (int)aKeStateSet, 180);
LABEL_3:
  result = ke_event_schedule_1("\x80\x9Dset tsk:%x:%x\n", a1, a2);
  if ( (uint16_t)*v7 != a2 )
  {
    v9 = (int ( *)(volatile uint32_t *, int))off_12D0AC;
    v10 = dword_12D080;
    v11 = (volatile int *)off_12D084;
    *v7 = a2;
    while ( 1 )
    {
      result = (int)tx_list_foreach(v10, v9, a1);
      v16 = (volatile uint32_t *)result;
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (volatile int *)off_12D088;
      v13 = dword_12D08C;
      ++*(volatile uint32_t *)off_12D088;
      check_abort_flag(v13, v16);
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
      set_system_flag_1(0x4000000);
    }
  }
  return result;
}


// hci_cmd_send_short @ 0x12d0b0
int hci_cmd_send_short(unsigned int a1) {
  volatile int16_t **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (volatile int16_t **)off_12D134;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_12D134 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    mmio_irq_clear(dword_12D144, dword_12D13C, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12D138;
      v5 = 16 * v3;
      return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      mmio_irq_clear(dword_12D14C, dword_12D148, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  mmio_irq_clear(dword_12D150, dword_12D13C, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12D138;
  v7 = dword_12D138 + 16 * v3;
  v5 = 16 * v3;
  if ( *(volatile uint16_t *)(v7 + 14) > v2 )
    return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
  mmio_irq_clear(dword_12D140, dword_12D13C, 212);
  return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
}



// hci_cmd_send_vendor @ 0x12d154
int hci_cmd_send_vendor(int a1, unsigned int a2) {
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

  v2 = (volatile int16_t **)off_12D1FC;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(volatile int16_t **)off_12D1FC >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a2 > 0xDu )
  {
    mmio_irq_clear(dword_12D20C, dword_12D204, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12D200;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      mmio_irq_clear(dword_12D214, dword_12D210, 183);
  }
  else if ( (uint8_t)a2 != 13 )
  {
    goto LABEL_10;
  }
  mmio_irq_clear(dword_12D218, dword_12D204, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12D200;
  v13 = dword_12D200 + 16 * v4;
  v7 = 16 * v4;
  if ( *(volatile uint16_t *)(v13 + 14) <= v5 )
    mmio_irq_clear(dword_12D208, dword_12D204, 269);
LABEL_3:
  v8 = *(volatile uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(volatile uint16_t *)(*(volatile uint32_t *)(v9 + 8) + 2 * v5),
        (result = list_process_count(a1, (volatile int *)v10, *(volatile uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(volatile uint32_t *)(v9 + 4);
    if ( v12 )
      return list_process_count(a1, (volatile int *)v12, *(volatile uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}



// set_system_flag @ 0x12d21c
volatile uint32_t *set_system_flag() {
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
    *(volatile uint32_t *)off_12D2FC = 1;
  }
  v0 = (volatile int *)off_12D300;
  v1 = dword_12D304;
  ++*(volatile uint32_t *)off_12D300;
  result = list_pop_front(v1);
  v3 = (volatile char *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(volatile uint32_t *)off_12D2FC;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, volatile char *, uint32_t, uint32_t))hci_cmd_send_vendor(
                                                               *((volatile uint16_t *)result + 2),
                                                               *((volatile uint16_t *)result + 3));
    ke_event_schedule_1(
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
        result = (volatile uint32_t *)check_abort_flag(dword_12D318, (void *)(v3));
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(volatile int16_t **)off_12D30C < 0 )
          result = (volatile uint32_t *)mmio_irq_clear(off_12D320, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      ke_event_schedule_1(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((volatile uint16_t *)v3 + 2),
        *((volatile uint16_t *)v3 + 4),
        *((volatile uint16_t *)v3 + 3));
    }
    result = (void *)(uintptr_t)(jump_to_tx_entry((int)(uintptr_t)(v3)));
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_12D2FC = 1;
  }
  v7 = *((volatile uint32_t *)off_12D310 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = (volatile uint32_t *)set_system_flag_2(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(volatile uint32_t *)off_12D2FC;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// return_zero @ 0x12d324
int return_zero() {
  return 0;
}



// return_two @ 0x12d328
int return_two() {
  return 2;
}



// set_system_flag_1 @ 0x12d32c
int set_system_flag_1(int a1) {
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
    *(volatile uint32_t *)off_12D360 = 1;
  }
  v1 = (void *)(uintptr_t)(off_12D364);
  v2 = (volatile int *)off_12D368;
  v3 = *(volatile uint32_t *)off_12D364;
  v4 = *(volatile uint32_t *)off_12D364 + 1;
  result = a1 | *(volatile uint32_t *)off_12D368;
  *(volatile uint32_t *)off_12D364 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12D360;
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



// pmu_sleep_10000000 @ 0x12d36c
int pmu_sleep_10000000() {
  return set_system_flag_1(0x10000000);
}



// set_system_flag_2 @ 0x12d374
int set_system_flag_2(int a1) {
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
    *(volatile uint32_t *)off_12D3AC = 1;
  }
  v1 = (void *)(uintptr_t)(off_12D3B0);
  v2 = (volatile int *)off_12D3B4;
  v3 = *(volatile uint32_t *)off_12D3B0;
  v4 = *(volatile uint32_t *)off_12D3B0 + 1;
  result = *(volatile uint32_t *)off_12D3B4 & ~a1;
  *(volatile uint32_t *)off_12D3B0 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_12D3AC;
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



// process_event_queue @ 0x12d3b8
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

  v0 = (volatile unsigned int *)off_12D420;
  v1 = *(volatile uint32_t *)off_12D420;
  if ( *(volatile uint32_t *)off_12D420 )
  {
    v2 = (volatile int16_t **)off_12D42C;
    v3 = dword_12D424;
    v4 = (void *)(uintptr_t)(off_12D428);
    v5 = dword_12D430;
    v6 = dword_12D434;
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
        mmio_irq_clear(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(volatile uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      {
        hw_sync_write();
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



// state_init @ 0x12d438
int state_init() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1

  v0 = align_and_irq_lock();
  v1 = (void *)(uintptr_t)(off_12D460);
  v2 = dword_12D464;
  *((volatile uint32_t *)off_12D460 + 7) = (int)(uintptr_t)(v0);
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return set_system_flag_2(-1);
}



// zero_struct @ 0x12d468
volatile uint32_t * zero_struct(volatile uint32_t *result) {
  *result = 0;
  result[1] = 0;
  return result;
}



