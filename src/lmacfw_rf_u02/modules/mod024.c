// util_flash_erase @ 0x11d8f0
int util_flash_erase(int a1) {
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

  v1 = *(volatile uint8_t *)(dword_11D9A4 + a1);
  if ( a1 )
    enter_critical_section_1(0x40000000);
  else
    enter_critical_section_1(0x8000);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11D9A8 = 1;
  }
  v3 = (volatile int *)off_11D9AC;
  v4 = dword_11D9BC;
  v5 = dword_11D9BC + 8 * a1;
  ++*(volatile uint32_t *)off_11D9AC;
  v6 = (int)(uintptr_t)(list_pop_front(v5));
  v7 = v6;
  if ( *v3 && (v8 = *v3 - 1, v9 = *(volatile uint32_t *)off_11D9A8, (*v3 = v8) == 0) && v9 )
  {
    __enable_irq();
    if ( **(volatile int16_t **)off_11D9B0 >= 0 )
      goto LABEL_8;
  }
  else if ( **(volatile int16_t **)off_11D9B0 >= 0 )
  {
    goto LABEL_8;
  }
  if ( !v6 )
    flash_ctrl_init(dword_11D9B8, dword_11D9B4, 190);
LABEL_8:
  v10 = *(void ( **)(uint32_t, int))(v7 + 8);
  if ( v10 )
    v10(*(volatile uint32_t *)(v7 + 12), a1);
  v12 = ((volatile uint32_t *)(uintptr_t)0x40021008u)[16 * v1] | 1;
  ++*(volatile uint16_t *)(v4 + 2 * (a1 + 12));
  ((volatile uint32_t *)(uintptr_t)0x40021008u)[16 * v1] = v12;
  return 4104;
}



// timer_disable_delay @ 0x11d9c0
int timer_disable_delay() {
  *(volatile uint32_t *)(dword_11D9D8 + 4680) &= ~1u;
  return set_busy_flag_alt(0x8000);
}



// timer_disable_delay_alt @ 0x11d9dc
int timer_disable_delay_alt() {
  *(volatile uint32_t *)(dword_11D9F4 + 4808) &= ~1u;
  return set_busy_flag_alt(0x40000000);
}



// util_byte_to_hex @ 0x11d9f8
int util_byte_to_hex(char a1) {
  int result; // r0
  volatile unsigned int *v2; // r2
  struct __attribute__((packed)) { uint8_t v3[7]; // [sp+7h] [bp-Dh] BYREF
  uint8_t v4; // [sp+Eh] [bp-6h] BYREF
  uint8_t v5[5]; // [sp+Fh] [bp-5h] BYREF
  } _frame;
  _frame.v3[0] = a1;
  result = rf_get_status((int)_frame.v3, &_frame.v4, _frame.v5);
  v2 = (volatile unsigned int *)off_11DA38;
  *(volatile uint32_t *)off_11DA38 = *(volatile uint32_t *)off_11DA38 & 0xFFFF00FF | (_frame.v4 << 8);
  *v2 = *v2 & 0xFFFFFF00 | _frame.v5[0];
  return result;
}



// rf_get_temperature @ 0x11da3c
/* luna: Reads the RF temperature field from a context, returning an invalid/0x7f raw value when sensor data is unavailable and otherwise returning a processed */
int rf_get_temperature(int a1, volatile uint8_t *a2, volatile uint8_t *a3) {
  int raw_temp; // r3
  int result; // r0

  raw_temp = *(volatile char *)(a1 + 97);
  if ( raw_temp == 127 )
    result = *(volatile uint32_t *)off_11DA58;
  else
    result = (uint8_t)raw_temp;
  if ( raw_temp == 127 )
    result = (uint8_t)result;
  if ( a2 )
    *a2 = raw_temp;
  if ( a3 )
    *a3 = result;
  return result;
}



// rf_set_temperature @ 0x11da5c
int rf_set_temperature(int result, int a2) {
  int v2; // r3

  if ( a2 != 127 )
  {
    v2 = *(volatile char *)(result + 97);
    *(volatile uint8_t *)(result + 97) = a2;
    if ( v2 != a2 )
    {
      result = *(volatile uint32_t *)(result + 72);
      if ( result )
        return bt_conn_find_by_ptr(result);
    }
  }
  return result;
}



// rf_init_check @ 0x11da78
int rf_init_check(int result, int a2) {
  int v2; // r4
  int v3; // r0

  if ( *((volatile uint8_t *)off_11DAB8 + 197) )
  {
    v2 = *(volatile uint32_t *)(*(volatile uint32_t *)(a2 + 32) + 44);
    v3 = rf_set_channel((*(volatile uint32_t *)(v2 + 20) >> 11) & 7, *(volatile uint32_t *)(v2 + 20) & 0x7F, *(volatile uint32_t *)(result + 72) + 4);
    result = v3 | (v3 << 8);
    *(volatile uint32_t *)(v2 + 36) = result;
  }
  else if ( **(volatile int16_t **)off_11DABC < 0 )
  {
    return flash_ctrl_init(dword_11DAC4, dword_11DAC0, 92);
  }
  return result;
}



// time_is_after @ 0x11dac8
BOOL time_is_after(int a1, int a2) {
  return *(volatile uint32_t *)(a1 + 8) - *(volatile uint32_t *)(a2 + 8) > (unsigned int)dword_11DADC;
}



// util_compare_key @ 0x11dae0
BOOL util_compare_key(int a1, unsigned int a2) {
  return *(volatile uint16_t *)(a1 + 4) == HIWORD(a2) && *(volatile uint16_t *)(a1 + 6) == (uint16_t)a2;
}



// ke_event_loop @ 0x11dafc
int ke_event_loop(int a1, int a2, unsigned int a3) {
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

  v3 = (volatile int16_t **)off_11DC48;
  if ( **(volatile int16_t **)off_11DC48 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_11DC34 )
        flash_ctrl_init(dword_11DC3C, dword_11DC38, 148);
    }
    else
    {
      flash_ctrl_init(dword_11DC40, dword_11DC38, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11DC1C = 1;
  }
  v7 = (volatile int *)off_11DC4C;
  v8 = (void *)(uintptr_t)(off_11DC50);
  v9 = *((volatile uint32_t *)off_11DC50 + 5);
  ++*(volatile uint32_t *)off_11DC4C;
  if ( v9 )
    v9 = *(volatile uint16_t *)(v9 + 4) == a1 && *(volatile uint16_t *)(v9 + 6) == a2;
  v10 = (int)(uintptr_t)(co_list_process(dword_11DC24, (void *)(uintptr_t)(dword_11DC20), a2 | (a1 << 16)));
  if ( !v10 )
  {
    v17 = align_size_plus4(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      flash_ctrl_init(dword_11DC44, dword_11DC38, 165);
    *(volatile uint16_t *)(v10 + 4) = a1;
    *(volatile uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_11DC2C;
  v12 = dword_11DC24;
  v13 = a3 + *((volatile uint32_t *)off_11DC28 + 4);
  *(volatile uint32_t *)(v10 + 8) = v13;
  result = list_foreach(v12, (void *)(uintptr_t)(v10), (void *)(uintptr_t)(v11));
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = ke_enter_critical((void *)(uintptr_t)(dword_11DC30), *(volatile uint32_t *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(volatile uint32_t *)off_11DC1C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((volatile uint32_t *)off_11DC28 + 4)) < 0 )
      return set_busy_flag_alt(0x10000000);
  }
  else if ( (int)(v13 - *((volatile uint32_t *)off_11DC28 + 4)) < 0 )
  {
    return set_busy_flag_alt(0x10000000);
  }
  return result;
}



// ke_int_lock @ 0x11dc54
int ke_int_lock(int result, int a2) {
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
    *(volatile uint32_t *)off_11DCEC = 1;
  }
  v2 = (volatile int *)off_11DCF0;
  v3 = (void *)(uintptr_t)(off_11DCF4);
  v4 = *((volatile uint32_t *)off_11DCF4 + 5);
  v5 = *(volatile uint32_t *)off_11DCF0 + 1;
  *(volatile uint32_t *)off_11DCF0 = v5;
  if ( v4 )
  {
    if ( *(volatile uint16_t *)(v4 + 4) == result && *(volatile uint16_t *)(v4 + 6) == a2 )
    {
      list_pop_front((int)(uintptr_t)(v3 + 5));
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        ke_enter_critical((void *)(uintptr_t)(v9), *(volatile uint32_t *)(v8 + 8));
        if ( **(volatile int16_t **)off_11DD00 < 0 && (int)(*(volatile uint32_t *)(v8 + 8) - *((volatile uint32_t *)off_11DD04 + 4)) < 0 )
          flash_ctrl_init(dword_11DD0C, dword_11DD08, 232);
      }
      else
      {
        ke_exit_critical(v9);
      }
    }
    else
    {
      result = (int)(uintptr_t)(co_list_process(dword_11DCFC, (void *)(uintptr_t)(dword_11DCF8), a2 | (result << 16)));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = (int)(uintptr_t)(check_buffer_size((void *)(uintptr_t)(v4)));
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_11DCEC;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}



// mmio_poll_wait @ 0x11dd10
int mmio_poll_wait() {
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

  v0 = (void *)(uintptr_t)(off_11DDB8);
  v1 = (volatile int *)off_11DDBC;
  v2 = (volatile int *)off_11DDC8;
  v3 = (void *)(uintptr_t)(off_11DDC0);
  v4 = (volatile char *)off_11DDB8 + 32;
  while ( 1 )
  {
    enter_critical_section_1(0x10000000);
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
      result = ke_enter_critical((void *)(uintptr_t)((int)v4), v5);
      if ( *(volatile uint32_t *)(v12 + 8) - v3[4] >= 0 )
      {
        if ( *v1 )
        {
          v16 = *v1 - 1;
          v17 = *(volatile uint32_t *)off_11DDC8;
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
    v7 = (int)(uintptr_t)(list_pop_front(dword_11DDC4));
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
    ke_evt_handler(*(volatile uint16_t *)(v7 + 4), *(volatile uint16_t *)(v7 + 6), 255);
    check_buffer_size((void *)(uintptr_t)(v8));
  }
  if ( v13 )
  {
    v14 = (volatile int *)off_11DDC8;
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



// ke_task_retrieve @ 0x11ddcc
int ke_task_retrieve(int a1, int a2) {
  volatile int **v2; // r3

  v2 = *((volatile int ***)off_11DDEC + 5);
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



// ke_msg_send_1 @ 0x11ddf0
/* luna: Allocates a kernel message block, initializes its 12-byte header, and returns a pointer to the zeroed payload area. */
int ke_msg_send_1(int16_t a1, int16_t a2, int16_t a3, unsigned int a4) {
  int msg_block; // r0
  int msg_header; // r4

  msg_block = align_size_plus4(a4 + 12);
  msg_header = msg_block;
  if ( **(volatile int16_t **)off_11DE44 < 0 && !msg_block )
    flash_ctrl_init(dword_11DE4C, dword_11DE48, 145);
  *(volatile uint16_t *)(msg_header + 4) = a1;
  *(volatile uint16_t *)(msg_header + 6) = a2;
  *(volatile uint16_t *)(msg_header + 8) = a3;
  *(volatile uint16_t *)(msg_header + 10) = a4;
  *(volatile uint32_t *)msg_header = 0;
  memset((volatile int *)(msg_header + 12), 0, a4);
  return msg_header + 12;
}



// rx_irq_handler_1 @ 0x11de50
volatile uint32_t * rx_irq_handler_1(int a1) {
  int16_t v1; // r5

  v1 = *(volatile uint16_t *)(a1 - 6);
  if ( **(volatile int16_t **)off_11DEC0 < 0 && (uint8_t)v1 > 5u )
    flash_ctrl_init((int)aIdTaskMax, (int)aKeTaskLocal, 183);
  if ( (v1 & 0xFC) != 0 )
  {
    dispatch_event_handler_1(
      "\x9D\x80""Dispatching msg:%x from tsk:%x to tsk:%x\n",
      *(volatile uint16_t *)(a1 - 8),
      *(volatile uint16_t *)(a1 - 4),
      *(volatile uint16_t *)(a1 - 6));
    if ( *(volatile uint8_t *)off_11DECC )
      return check_buffer_size((volatile char *)(a1 - 12));
    else
      return (volatile uint32_t *)patch_trampoline((volatile uint16_t *)(uintptr_t)(a1 - 12));
  }
  else
  {
    check_kernel_state(dword_11DEC4, (volatile uint32_t *)(a1 - 12));
    return (volatile uint32_t *)set_busy_flag_alt(0x4000000);
  }
}


// ke_evt_handler @ 0x11ded8
int ke_evt_handler(int16_t a1, int16_t a2, int16_t a3) {
  int v3; // r0

  v3 = ke_msg_send_1(a1, a2, a3, 0);
  return (int)(uintptr_t)(rx_irq_handler_1(v3));
}



// isr_forward @ 0x11dee8
int isr_forward(int a1) {
  return (int)(uintptr_t)(check_buffer_size((void *)(uintptr_t)(a1)));
}



// co_list_process @ 0x11deec
/* luna: Removes and returns the first node in a singly linked co_list whose predicate callback returns true, updating the list head and tail pointers as neede */
volatile uint32_t * co_list_process(int a1, int ( *a2)(volatile uint32_t *, int), int a3) {
  volatile uint32_t *node; // r4
  volatile uint32_t *prev; // r8
  int i; // r0
  int next; // r3

  node = *(volatile uint32_t **)a1;
  if ( !*(volatile uint32_t *)a1 )
    return 0;
  prev = 0;
  for ( i = a2(node, a3); ; i = a2(node, a3) )
  {
    next = *node;
    if ( i )
      break;
    prev = node;
    if ( !next )
      return 0;
    node = (volatile uint32_t *)*node;
  }
  if ( prev )
  {
    *prev = next;
    if ( *node )
    {
LABEL_8:
      *node = 0;
      return node;
    }
  }
  else
  {
    *(volatile uint32_t *)a1 = next;
    if ( next )
      goto LABEL_8;
  }
  *(volatile uint32_t *)(a1 + 4) = (int)(uintptr_t)(prev);
  return node;
}



// critical_enter_1 @ 0x11df44
volatile uint32_t *critical_enter_1() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r2
  int v2; // r1
  int v3; // r4
  unsigned int v4; // r3
  volatile int *v5; // r3
  int v6; // r3

  result = (volatile uint32_t *)(dword_11DF84 & 0xFFFFFFFC);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11DF88 = 1;
  }
  v1 = (void *)(uintptr_t)(off_11DF8C);
  v2 = *(volatile uint32_t *)off_11DF8C;
  v3 = *(volatile uint32_t *)off_11DF8C + 1;
  v4 = (dword_11DF90 & 0xFFFFFFFC) - (uint32_t)result;
  *(volatile uint32_t *)off_11DF8C = v3;
  *result = 0;
  result[1] = v4;
  if ( v3 )
  {
    v5 = (volatile int *)off_11DF88;
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



// align_size_plus4 @ 0x11df94
int align_size_plus4(int a1) {
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

  v1 = (volatile int16_t **)off_11E05C;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(volatile int16_t **)off_11E05C < 0 && v3 <= 7 )
    flash_ctrl_init(dword_11E074, dword_11E06C, 132);
  v4 = *((volatile uint32_t **)off_11E060 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11E064 = 1;
  }
  v5 = (volatile int *)off_11E068;
  v6 = *(volatile uint32_t *)off_11E068 + 1;
  *(volatile uint32_t *)off_11E068 = v6;
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
  flash_ctrl_init(dword_11E070, dword_11E06C, 160);
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
    v12 = *(volatile uint32_t *)off_11E064;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}



// check_buffer_size @ 0x11e078
volatile uint32_t * check_buffer_size(volatile char *a1) {
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

  v1 = (volatile int16_t **)off_11E174;
  v2 = *((volatile char **)off_11E15C + 7);
  v3 = *((volatile uint32_t *)a1 - 1);
  v5 = a1 - 4;
  if ( **(volatile int16_t **)off_11E174 < 0 && a1 <= v2 )
    flash_ctrl_init(dword_11E16C, dword_11E168, 220);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11E160 = 1;
  }
  result = (void *)(uintptr_t)(off_11E164);
  v7 = *(volatile uint32_t *)off_11E164;
  v8 = *(volatile uint32_t *)off_11E164 + 1;
  *(volatile uint32_t *)off_11E164 = v8;
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
        flash_ctrl_init(dword_11E170, dword_11E168, 247);
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
    v11 = (volatile int *)off_11E160;
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



// process_list_entries @ 0x11e184
int process_list_entries(int a1, volatile int *a2, int a3) {
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
  if ( **(volatile int16_t **)off_11E1D8 < 0 && !result )
  {
    flash_ctrl_init(dword_11E1E0, dword_11E1DC, 239);
    return *(volatile uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}



// flash_erase_sector @ 0x11e1e4
/* luna: Sets the kernel task state for a packed task identifier and processes the task's pending kernel message list when the state changes. */
int flash_erase_sector(unsigned int a1, int a2) {
  volatile int16_t **v2; // r7
  unsigned int task_index; // r9
  unsigned int task_type; // r6
  volatile uint16_t *state_ptr; // r9
  int result; // r0
  int ( *callback)(volatile uint32_t *, int); // r8
  int message_list; // r7
  volatile int *v11; // r6
  volatile int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  volatile uint32_t *v16; // r1
  volatile int *v17; // r6

  v2 = (volatile int16_t **)off_11E310;
  task_index = a1 >> 8;
  task_type = (uint8_t)a1;
  if ( **(volatile int16_t **)off_11E310 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 <= 4u )
    goto LABEL_15;
  flash_ctrl_init((int)aTypeTaskMax, (int)aKeStateSet, 173);
  if ( **v2 >= 0 )
  {
LABEL_2:
    state_ptr = (volatile uint16_t *)(((volatile uint32_t *)(uintptr_t)off_11E314)[4 * task_type + 2] + 2 * task_index);
    goto LABEL_3;
  }
  if ( task_type <= 5 )
  {
LABEL_15:
    if ( (a1 & 0xFC) == 0 )
    {
      v17 = (void *)(&((volatile uint32_t *)(uintptr_t)off_11E314)[4 * task_type]);
      if ( *((volatile uint16_t *)v17 + 7) > task_index )
        goto LABEL_17;
      goto LABEL_25;
    }
  }
  else
  {
    flash_ctrl_init((int)aIdTaskMax, (int)aKeTaskLocal_0, 183);
    if ( (a1 & 0xFC) == 0 )
      goto LABEL_23;
  }
  flash_ctrl_init((int)aKeTaskLocalTyp, (int)aKeStateSet, 174);
LABEL_23:
  if ( **v2 >= 0 )
    goto LABEL_2;
  v17 = (void *)(&((volatile uint32_t *)(uintptr_t)off_11E314)[4 * task_type]);
  if ( *((volatile uint16_t *)v17 + 7) > task_index )
  {
LABEL_17:
    state_ptr = (volatile uint16_t *)(v17[2] + 2 * task_index);
    if ( state_ptr )
      goto LABEL_3;
    goto LABEL_18;
  }
LABEL_25:
  flash_ctrl_init((int)aIdxTaskDescTyp, (int)aKeStateSet, 175);
  state_ptr = (volatile uint16_t *)(v17[2] + 2 * task_index);
  if ( **v2 < 0 && !state_ptr )
LABEL_18:
    flash_ctrl_init((int)aKeStateidPtr, (int)aKeStateSet, 180);
LABEL_3:
  result = dispatch_event_handler_1("\x80\x9Dset tsk:%x:%x\n", a1, a2);
  if ( (uint16_t)*state_ptr != a2 )
  {
    callback = (int ( *)(volatile uint32_t *, int))off_11E348;
    message_list = dword_11E31C;
    v11 = (volatile int *)off_11E320;
    *state_ptr = a2;
    while ( 1 )
    {
      result = (int)co_list_process(message_list, callback, a1);
      v16 = (volatile uint32_t *)result;
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (volatile int *)off_11E324;
      v13 = dword_11E328;
      ++*(volatile uint32_t *)off_11E324;
      check_kernel_state(v13, v16);
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
      set_busy_flag_alt(0x4000000);
    }
  }
  return result;
}


// flash_write_byte @ 0x11e34c
int flash_write_byte(unsigned int a1) {
  volatile int16_t **v1; // r6
  unsigned int v2; // r7
  unsigned int v3; // r5
  int v4; // r4
  int v5; // r5
  char v7; // r4
  int v8; // r3

  v1 = (volatile int16_t **)off_11E3DC;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(volatile int16_t **)off_11E3DC >= 0 )
    goto LABEL_2;
  v7 = a1;
  if ( (uint8_t)a1 <= 4u )
    goto LABEL_5;
  flash_ctrl_init(dword_11E3EC, dword_11E3E4, 210);
  if ( **v1 >= 0 )
  {
LABEL_2:
    v4 = dword_11E3E0;
    v5 = 16 * v3;
    return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
  }
  if ( v3 <= 5 )
  {
LABEL_5:
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_6;
  }
  else
  {
    flash_ctrl_init(dword_11E3F4, dword_11E3F0, 183);
    if ( (v7 & 0xFC) == 0 )
      goto LABEL_12;
  }
  flash_ctrl_init(dword_11E3F8, dword_11E3E4, 211);
LABEL_12:
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_11E3E0;
  v8 = dword_11E3E0 + 16 * v3;
  v5 = 16 * v3;
  if ( *(volatile uint16_t *)(v8 + 14) > v2 )
    return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
  flash_ctrl_init(dword_11E3E8, dword_11E3E4, 212);
  return *(volatile uint16_t *)(*(volatile uint32_t *)(v4 + v5 + 8) + 2 * v2);
}



// flash_read_byte @ 0x11e3fc
int flash_read_byte(int a1, unsigned int a2) {
  volatile int16_t **v2; // r4
  unsigned int v4; // r7
  unsigned int v5; // r8
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  char v13; // r5
  int v14; // r3

  v2 = (volatile int16_t **)off_11E4B8;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(volatile int16_t **)off_11E4B8 >= 0 )
    goto LABEL_2;
  v13 = a2;
  if ( (uint8_t)a2 <= 4u )
    goto LABEL_9;
  flash_ctrl_init(dword_11E4C8, dword_11E4C0, 267);
  if ( **v2 >= 0 )
  {
LABEL_2:
    v6 = dword_11E4BC;
    v7 = 16 * v4;
    goto LABEL_3;
  }
  if ( v4 <= 5 )
  {
LABEL_9:
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_10;
  }
  else
  {
    flash_ctrl_init(dword_11E4D0, dword_11E4CC, 183);
    if ( (v13 & 0xFC) == 0 )
      goto LABEL_16;
  }
  flash_ctrl_init(dword_11E4D4, dword_11E4C0, 268);
LABEL_16:
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_11E4BC;
  v14 = dword_11E4BC + 16 * v4;
  v7 = 16 * v4;
  if ( *(volatile uint16_t *)(v14 + 14) <= v5 )
    flash_ctrl_init(dword_11E4C4, dword_11E4C0, 269);
LABEL_3:
  v8 = *(volatile uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(volatile uint16_t *)(*(volatile uint32_t *)(v9 + 8) + 2 * v5),
        (result = process_list_entries(a1, (volatile int *)v10, *(volatile uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(volatile uint32_t *)(v9 + 4);
    if ( v12 )
      return process_list_entries(a1, (volatile int *)v12, *(volatile uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}



// ke_task_schedule @ 0x11e4d8
volatile uint32_t *ke_task_schedule() {
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
    *(volatile uint32_t *)off_11E5B8 = 1;
  }
  v0 = (volatile int *)off_11E5BC;
  v1 = dword_11E5C0;
  ++*(volatile uint32_t *)off_11E5BC;
  result = list_pop_front(v1);
  v3 = (volatile char *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(volatile uint32_t *)off_11E5B8;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, volatile char *, uint32_t, uint32_t))flash_read_byte(
                                                               *((volatile uint16_t *)result + 2),
                                                               *((volatile uint16_t *)result + 3));
    dispatch_event_handler_1(
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
        result = (volatile uint32_t *)check_kernel_state(dword_11E5D4, (void *)(v3));
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(volatile int16_t **)off_11E5C8 < 0 )
          result = (volatile uint32_t *)flash_ctrl_init(off_11E5DC, (int)aKeTaskSchedule, 360);
        goto LABEL_12;
      }
    }
    else
    {
      dispatch_event_handler_1(
        "\x9A\x80No handler found for msg:%x from tsk:%x to tsk:%x\n",
        *((volatile uint16_t *)v3 + 2),
        *((volatile uint16_t *)v3 + 4),
        *((volatile uint16_t *)v3 + 3));
    }
    result = (void *)(uintptr_t)(isr_forward((int)(uintptr_t)(v3)));
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11E5B8 = 1;
  }
  v7 = *((volatile uint32_t *)off_11E5CC + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = (volatile uint32_t *)enter_critical_section_1(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(volatile uint32_t *)off_11E5B8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// set_busy_flag_alt @ 0x11e5e0
int set_busy_flag_alt(int a1) {
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
    *(volatile uint32_t *)off_11E614 = 1;
  }
  v1 = (void *)(uintptr_t)(off_11E618);
  v2 = (volatile int *)off_11E61C;
  v3 = *(volatile uint32_t *)off_11E618;
  v4 = *(volatile uint32_t *)off_11E618 + 1;
  result = a1 | *(volatile uint32_t *)off_11E61C;
  *(volatile uint32_t *)off_11E618 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_11E614;
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



// disable_irq_10000000 @ 0x11e620
int disable_irq_10000000() {
  return set_busy_flag_alt(0x10000000);
}



// enter_critical_section_1 @ 0x11e628
int enter_critical_section_1(int a1) {
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
    *(volatile uint32_t *)off_11E660 = 1;
  }
  v1 = (void *)(uintptr_t)(off_11E664);
  v2 = (volatile int *)off_11E668;
  v3 = *(volatile uint32_t *)off_11E664;
  v4 = *(volatile uint32_t *)off_11E664 + 1;
  result = *(volatile uint32_t *)off_11E668 & ~a1;
  *(volatile uint32_t *)off_11E664 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (volatile int *)off_11E660;
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



// process_event_queue @ 0x11e66c
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

  v0 = (volatile unsigned int *)off_11E6D4;
  v1 = *(volatile uint32_t *)off_11E6D4;
  if ( *(volatile uint32_t *)off_11E6D4 )
  {
    v2 = (volatile int16_t **)off_11E6E0;
    v3 = dword_11E6D8;
    v4 = (void *)(uintptr_t)(off_11E6DC);
    v5 = dword_11E6E4;
    v6 = dword_11E6E8;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 23 )
        {
          v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        flash_ctrl_init(v6, v5, 230);
      }
      v8 = *(void ( **)(uint32_t))(v3 + 8 * v7);
LABEL_5:
      v8(*(volatile uint32_t *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(volatile uint8_t *)(*(volatile uint32_t *)v4 + 3) )
      {
        memory_barrier_write();
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



// init_event_control @ 0x11e6ec
int init_event_control() {
  volatile uint32_t *v0; // r0
  volatile uint32_t *v1; // r3
  int v2; // r1

  v0 = critical_enter_1();
  v1 = (void *)(uintptr_t)(off_11E714);
  v2 = dword_11E718;
  *((volatile uint32_t *)off_11E714 + 7) = (int)(uintptr_t)(v0);
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return enter_critical_section_1(-1);
}



// list_init_1 @ 0x11e71c
volatile uint32_t * list_init_1(volatile uint32_t *result) {
  *result = 0;
  result[1] = 0;
  return result;
}



