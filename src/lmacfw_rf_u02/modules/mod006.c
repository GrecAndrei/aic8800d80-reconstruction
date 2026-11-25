// mem_free @ 0x10fef8
int mem_free(volatile uint32_t *a1) {
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = mem_is_in_heap((unsigned int)a1);
  if ( !result )
  {
    result = log_printf("get_native_pool_id: Invalid buffer passed: %x\n", a1);
    v5 = **(volatile uint8_t **)off_10FFD4;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return lock_acquire(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !mem_is_in_heap((unsigned int)a1) )
          log_printf("get_user_id: Invalid buffer passed: %x\n", a1);
        return sorted_list_search(dword_10FFE0, a1);
      }
      if ( **(volatile int16_t **)off_10FFD8 < 0 )
        return flash_ctrl_init((int)aNativeId3, (int)aPktMemFree, 204);
      return result;
    }
    return irq_disable_set_flag_preserve_2(a1);
  }
  v3 = *((volatile uint8_t *)a1 - 4);
  v4 = **(volatile uint8_t **)off_10FFD4;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return irq_disable_set(a1);
    if ( v3 == 2 )
      return irq_disable_set_flag_preserve(a1);
    if ( *((volatile uint8_t *)a1 - 4) )
      return result;
    return irq_disable_set_flag_preserve_2(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(volatile int16_t **)off_10FFD8 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return enter_critical_section(a1);
      }
      if ( v3 == 3 )
        return enter_critical_section(a1);
      return flash_ctrl_init((int)aNativeId3, (int)aPktMemFree, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return critical_section_enter_arg(a1);
  if ( !*((volatile uint8_t *)a1 - 4) )
    return lock_acquire(a1);
  return result;
}


// rf_tx_power_get @ 0x10fff0
int rf_tx_power_get() {
  void *v0; // r4
  int v1; // r3
  volatile int *v2; // r0
  int16_t v3; // r2
  int16_t v4; // r1
  uint64_t v5; // kr00_8
  struct __attribute__((packed)) { uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_11006C);
  v1 = *(volatile uint32_t *)off_11006C;
  v2 = (void *)(uintptr_t)(off_110074);
  v3 = *((volatile uint16_t *)((volatile uint32_t *)(uintptr_t)&off_110070)[0] + 153);
  v4 = *((volatile uint16_t *)((volatile uint32_t *)(uintptr_t)&off_110070)[0] + 154) - 4;
  _frame.v7[1] = *(volatile uint16_t *)(*(volatile uint32_t *)off_11006C + 2);
  _frame.v8[1] = *(volatile uint16_t *)(v1 + 4);
  _frame.v8[5] = *(volatile uint16_t *)(v1 + 6);
  _frame.v8[7] = *(volatile uint16_t *)(v1 + 8);
  v5 = *(volatile uint64_t *)(v1 + 20);
  *(volatile uint32_t *)(uintptr_t)(off_110074) = v5;
  v2[3] = dword_110078;
  v2[1] = HIDWORD(v5);
  *((volatile uint8_t *)v2 + 8) = 1;
  _frame.v8[2] = v4;
  _frame.v8[6] = v3 - 4;
  _frame.v7[0] = 12;
  _frame.v8[4] = 1596;
  _frame.v8[0] = 124;
  _frame.v8[3] = 0;
  ke_msg_send(v2, (int)_frame.v7, 0x20u);
  return mem_region_init((int)_frame.v8, *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 28), *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 32));
}


// rx_channel_event @ 0x11007c
volatile uint32_t *rx_channel_event() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_1100D0);
  result = list_init_1((volatile uint32_t *)dword_1100C4);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6) )
  {
    v2 = (void *)(uintptr_t)(off_1100C8);
    v3 = dword_1100CC;
    v4 = dword_1100C4;
    v5 = 0;
    do
    {
      v6 = list_iterate(v3, 0x63Cu);
      result = (volatile uint32_t *)check_kernel_state(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// rx_packet_event @ 0x1100d4
volatile uint32_t *rx_packet_event() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_110108);
  result = list_init_1((volatile uint32_t *)dword_11010C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) )
  {
    v2 = dword_110110;
    v3 = dword_11010C;
    v4 = 0;
    do
    {
      v5 = list_iterate(v2, 0xCu);
      result = (volatile uint32_t *)check_kernel_state(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// rf_lmac_init_n114 @ 0x110114
int rf_lmac_init_n114() {
  void *v0; // r8
  int result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = (void *)(uintptr_t)(off_110168);
  result = (int)(uintptr_t)(list_init_1((void *)(uintptr_t)(dword_11015C)));
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (void *)(uintptr_t)(off_110160);
    v3 = dword_110164;
    v4 = dword_11015C;
    v5 = 0;
    do
    {
      list_iterate(v3, 0x6B8u);
      result = ((int (*)())check_kernel_state)(v4);
      v6 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (uint16_t)v5 );
  }
  return result;
}



// rx_adv_event @ 0x11016c
volatile uint32_t *rx_adv_event() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_1101A0);
  result = list_init_1((volatile uint32_t *)dword_1101A4);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_1101A8;
    v3 = dword_1101A4;
    v4 = 0;
    do
    {
      v5 = list_iterate(v2, 0x7Cu);
      result = (volatile uint32_t *)check_kernel_state(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// irq_disable @ 0x1101ac
int irq_disable() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1101E0 = 1;
  }
  v0 = (volatile int *)off_1101E4;
  v1 = dword_1101E8;
  ++*(volatile uint32_t *)off_1101E4;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1101E0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// irq_disable_arg @ 0x1101ec
int irq_disable_arg(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110224 = 1;
  }
  v2 = (volatile int *)off_110228;
  v3 = dword_11022C;
  ++*(volatile uint32_t *)off_110228;
  result = check_kernel_state(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_110224;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// irq_disable_set @ 0x110280
int irq_disable_set(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1102C0 = 1;
  }
  v2 = (volatile int *)off_1102C4;
  v3 = dword_1102C8;
  ++*(volatile uint32_t *)off_1102C4;
  result = check_kernel_state(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_1102CC;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_1102C0;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// irq_disable_set_flag @ 0x1102d0
int irq_disable_set_flag() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110310 = 1;
  }
  v0 = (volatile int *)off_110314;
  v1 = dword_110318;
  ++*(volatile uint32_t *)off_110314;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( result )
    --*(volatile uint32_t *)off_11031C;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_110310;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// irq_disable_set_flag_preserve @ 0x110320
int irq_disable_set_flag_preserve(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110360 = 1;
  }
  v2 = (volatile int *)off_110364;
  v3 = dword_110368;
  ++*(volatile uint32_t *)off_110364;
  result = check_kernel_state(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_11036C;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_110360;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// irq_disable_set_flag_2 @ 0x110370
int irq_disable_set_flag_2() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1103A4 = 1;
  }
  v0 = (volatile int *)off_1103A8;
  v1 = dword_1103AC;
  ++*(volatile uint32_t *)off_1103A8;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1103A4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// irq_disable_set_flag_preserve_2 @ 0x1103b0
int irq_disable_set_flag_preserve_2(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1103E8 = 1;
  }
  v2 = (volatile int *)off_1103EC;
  v3 = dword_1103F0;
  ++*(volatile uint32_t *)off_1103EC;
  result = check_kernel_state(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_1103E8;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// rx_irq_handler @ 0x1103f4
int rx_irq_handler(int result) {
  volatile uint32_t *v1; // r4
  unsigned int v2; // r3
  volatile int *v3; // r6
  volatile uint32_t *v4; // r9
  volatile uint32_t *v5; // r8
  int v6; // r5
  volatile int *v7; // r7
  volatile uint32_t *v8; // r10
  volatile uint32_t *v9; // r0
  volatile uint32_t *v10; // r11
  int v11; // r1
  int v12; // r2
  int16_t v13; // r3
  int v14; // r1
  int v15; // r2
  int v16; // r3

  v1 = (void *)(uintptr_t)(off_1104F8);
  v2 = *(volatile uint16_t *)(result + 28);
  v3 = (volatile int *)off_1104FC;
  v4 = (void *)(uintptr_t)(off_110524);
  v5 = (void *)(uintptr_t)(off_110528);
  v6 = result;
LABEL_2:
  v7 = (volatile int *)off_110500;
  while ( v2 <= 1 )
  {
    v8 = (void *)(uintptr_t)(irq_disable_set_flag());
    if ( !v8 )
    {
      result = log_printf("rep: no rxmsg buffer, %d\r\n", *(volatile uint32_t *)off_110518);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return set_busy_flag_alt(256);
    }
    v9 = (void *)(uintptr_t)(irq_disable());
    v10 = v9;
    if ( !v9 )
    {
      log_printf(aRepRxmsgNoDesc);
      result = irq_disable_set_flag_preserve(v8);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return set_busy_flag_alt(256);
    }
    *v9 = (int)(uintptr_t)(v8);
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_110504 = 1;
    }
    v11 = *v7 + 1;
    *v7 = v11;
    *v1 = 1024;
    while ( (*v1 & 0x800) != 0 )
      ;
    if ( (uint8_t)*v3 )
    {
      v16 = *(volatile uint32_t *)(v6 + 20);
      if ( v16 )
      {
        *(volatile uint32_t *)(v16 + 4) = (int)(uintptr_t)(v9);
      }
      else
      {
        log_printf(aRxmsgTailError);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(volatile int16_t **)off_110508 < 0 && *v4 )
      {
        flash_ctrl_init((int)aSdioFunc1H2dFr, (int)aSdioReplenishR, 261);
        v11 = *v7;
      }
      *v4 = (int)(uintptr_t)(v10);
    }
    v12 = *v3;
    v13 = *(volatile uint16_t *)(v6 + 28);
    *(volatile uint32_t *)(v6 + 20) = (int)(uintptr_t)(v10);
    v2 = (uint16_t)(v13 + 1);
    result = 1024;
    *(volatile uint16_t *)(v6 + 28) = v2;
    *v3 = (uint8_t)(v12 + 1);
    *v5 = 1024;
    if ( v11 )
    {
      v14 = v11 - 1;
      v15 = *(volatile uint32_t *)off_110504;
      *v7 = v14;
      if ( !v14 )
      {
        if ( v15 )
        {
          __enable_irq();
          v2 = *(volatile uint16_t *)(v6 + 28);
        }
      }
      goto LABEL_2;
    }
  }
  return result;
}


// tx_irq_handler @ 0x11052c
int tx_irq_handler(int a1, int a2) {
  volatile uint32_t *v2; // r4
  volatile int *v3; // r7
  unsigned int v6; // r2
  volatile uint32_t *v7; // r9
  volatile int *v8; // r11
  int v9; // r10
  volatile uint32_t *v10; // r0
  volatile uint32_t *v11; // r5
  int v12; // r0
  volatile int *v13; // r3
  int v14; // r0
  int v15; // r1
  int16_t v16; // r2
  volatile uint32_t *v17; // r1
  int v18; // r0
  int v19; // r2
  unsigned int v21; // [sp+4h] [bp-8h]

  v2 = (void *)(uintptr_t)(off_110650);
  v3 = (volatile int *)off_110654;
  v21 = *(volatile uint16_t *)(*(volatile uint32_t *)off_11064C + 48);
  rx_irq_handler(a2);
  v6 = *(volatile uint16_t *)(a2 + 12);
LABEL_2:
  v7 = (void *)(uintptr_t)(off_11067C);
  v8 = (void *)(uintptr_t)(off_110680);
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(volatile uint32_t *)(a1 + 8) + 16))(*(volatile uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      log_printf("rep: no buffer, %d\r\n", *v7);
LABEL_23:
      if ( *(volatile uint16_t *)(a2 + 12) >= (unsigned int)*(volatile uint16_t *)(*(volatile uint32_t *)off_11064C + 50) )
        return 1;
LABEL_24:
      set_busy_flag_alt(256);
      return 1;
    }
    v10 = (void *)(uintptr_t)(irq_disable());
    v11 = v10;
    if ( !v10 )
    {
      log_printf(aRepNoDesc);
      (*(void ( **)(uint32_t, int))(*(volatile uint32_t *)(a1 + 8) + 20))(*(volatile uint32_t *)(a1 + 4), v9);
      goto LABEL_23;
    }
    *v10 = 0;
    v12 = *v8;
    v11[1] = 0;
    v11[2] = 0;
    *v11 = v12 + v9;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_110658 = 1;
    }
    v13 = (volatile int *)off_11065C;
    v14 = *(volatile uint32_t *)off_11065C + 1;
    *(volatile uint32_t *)off_11065C = v14;
    *v2 = 1;
    while ( (*v2 & 2) != 0 )
      ;
    if ( *v3 )
    {
      v19 = *(volatile uint32_t *)(a2 + 4);
      if ( v19 )
        *(volatile uint32_t *)(v19 + 4) = (int)(uintptr_t)(v11);
    }
    else
    {
      if ( **(volatile int16_t **)off_110660 < 0 && *(volatile uint32_t *)off_110664 )
      {
        flash_ctrl_init((int)aSdioFunc1H2dFr_0, (int)aHostSdioReplen, 400);
        v13 = (volatile int *)off_11065C;
        v14 = *(volatile uint32_t *)off_11065C;
      }
      *(volatile uint32_t *)off_110664 = (int)(uintptr_t)(v11);
    }
    v15 = *v3;
    v16 = *(volatile uint16_t *)(a2 + 12);
    *(volatile uint32_t *)(a2 + 4) = (int)(uintptr_t)(v11);
    v6 = (uint16_t)(v16 + 1);
    *(volatile uint16_t *)(a2 + 12) = v6;
    *v3 = (uint16_t)(v15 + 1);
    *(volatile uint32_t *)off_110668 = 1;
    if ( v14 )
    {
      v17 = (void *)(uintptr_t)(off_110658);
      v18 = v14 - 1;
      *v13 = v18;
      if ( !v18 )
      {
        if ( *v17 )
        {
          __enable_irq();
          v6 = *(volatile uint16_t *)(a2 + 12);
        }
      }
      goto LABEL_2;
    }
  }
  return 1;
}


// invoke_sub_1108c0 @ 0x110684
int invoke_sub_1108c0() {
  rf_cmd_start();
  return 1;
}



// list_init @ 0x110690
int list_init(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_1106C4);
  v2 = (void *)(uintptr_t)(off_1106C8);
  *(volatile uint32_t *)off_1106C4 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((volatile uint16_t *)v2 + 6) = 0;
  v2[2] = 0;
  *((volatile uint8_t *)v2 + 14) = 0;
  *((volatile uint16_t *)v2 + 14) = 0;
  v2[6] = 0;
  *((volatile uint8_t *)v2 + 30) = 0;
  tx_irq_handler((int)v1, (int)v2);
  return 1;
}



// rf_cmd_start @ 0x1108c0
int rf_cmd_start() {
  volatile uint32_t *v0; // r3
  volatile uint32_t *v1; // r1
  volatile int *v2; // r4
  volatile unsigned int *v3; // r5
  volatile unsigned int *v4; // r2
  volatile uint32_t *v5; // r0
  volatile uint32_t *v6; // r7
  volatile uint32_t *v7; // r6
  int v8; // r1
  volatile uint32_t *v9; // r3
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r0
  int v12; // r1
  volatile int *v13; // r3
  int v14; // r1
  int v15; // r2
  volatile uint32_t *v16; // r1
  int result; // r0
  volatile uint32_t *v18; // r3
  volatile unsigned int *v19; // r2
  volatile unsigned int *v20; // r1

  v0 = (void *)(uintptr_t)(off_110A64);
  *(volatile uint32_t *)off_110A60 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (volatile unsigned int *)off_110A94;
    v20 = (volatile unsigned int *)off_110A78;
    *(volatile uint32_t *)off_110A94 = *(volatile uint32_t *)off_110A94 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)ipc_send_0x40d();
  }
  else
  {
    dispatch_event_handler_1(aWaitCmd5);
    do
    {
      while ( (*(volatile uint32_t *)off_110A6C & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110A6C < 0 );
    v1 = (volatile uint32_t *)off_110A6C;
    *(volatile uint32_t *)off_110A6C = dword_110A70;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(volatile uint32_t *)off_110A64 & 1) == 0 )
        ;
    }
    v2 = (volatile int *)off_110A74;
    v3 = (volatile unsigned int *)off_110A78;
    v4 = (volatile unsigned int *)off_110A7C;
    v5 = (void *)(uintptr_t)(off_110A80);
    v6 = (void *)(uintptr_t)(off_110A84);
    v7 = (void *)(uintptr_t)(off_110A88);
    *(volatile uint32_t *)off_110A64 = 2;
    v8 = dword_110A8C;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = (void *)(uintptr_t)(off_110A90);
    *v5 &= v8;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = (void *)(uintptr_t)(off_110A94);
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = (void *)(uintptr_t)(off_110A98);
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_110A9C;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    dispatch_event_handler_1(aWaitIoEnable);
    v13 = (volatile int *)off_110A6C;
    v14 = dword_110A70;
    while ( 1 )
    {
      while ( (*v13 & 0x20000000) != 0 )
        ;
      if ( *v13 >= 0 )
      {
        *v13 = v14;
        while ( (*v13 & 0x20000000) != 0 )
          ;
        if ( (*v13 & 6) != 0 )
          break;
      }
    }
    v15 = off_110A6C;
    do
    {
      while ( (*(volatile uint32_t *)off_110A6C & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110A6C < 0 );
    v16 = (volatile uint32_t *)off_110A6C;
    *(volatile uint32_t *)off_110A6C = dword_110AA4;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = dispatch_event_handler_1(aIoEnable, v16, v15, 4 * *v16);
    *(volatile uint32_t *)off_110A78 = *(volatile uint32_t *)off_110A78 & 0xFFFFF000 | 0x960;
  }
  v18 = (void *)(uintptr_t)(off_110AB0);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_110AAC + 2) + 324) = off_110AB4;
  v18[2] = 2;
  return result;
}


// irq_disable_set_flag_3 @ 0x110ab8
int irq_disable_set_flag_3(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r5
  volatile uint32_t *v4; // r4
  int v5; // r6
  int v6; // r7
  volatile uint32_t *v7; // r3
  volatile uint32_t *v8; // r12
  int result; // r0
  volatile int *v10; // r3
  int v11; // r3
  volatile uint32_t *v12; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110B28 = 1;
  }
  v3 = (void *)(uintptr_t)(off_110B2C);
  v4 = (void *)(uintptr_t)(off_110B30);
  v5 = *(volatile uint32_t *)off_110B2C;
  v6 = *(volatile uint32_t *)off_110B2C + 1;
  *(volatile uint32_t *)off_110B2C = v6;
  *v4 = 256;
  while ( (*v4 & 0x200) != 0 )
    ;
  if ( *(volatile uint32_t *)off_110B34 )
  {
    v7 = (void *)(uintptr_t)(off_110B38);
    v8 = (void *)(uintptr_t)(off_110B40);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_110B38 + 769) + 4) = a1;
    *v8 += a2;
  }
  else
  {
    v12 = (void *)(uintptr_t)(off_110B40);
    *(volatile uint32_t *)off_110B34 = a1;
    v7 = (void *)(uintptr_t)(off_110B38);
    *v12 += a2;
  }
  result = 256;
  *(volatile uint32_t *)off_110B3C = 256;
  v7[769] = a3;
  if ( v6 )
  {
    v10 = (volatile int *)off_110B28;
    *v3 = v5;
    v11 = *v10;
    if ( !v5 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}



// set_radio_channel @ 0x110b44
volatile uint32_t * set_radio_channel(volatile uint32_t *result, int a2, int a3, uint16_t a4, int a5) {
  result[2] = dword_110B60 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}



// irq_disable_set_flag_4 @ 0x110b64
int irq_disable_set_flag_4(int result) {
  volatile uint32_t *v1; // r1
  volatile uint32_t *v2; // r2
  int v3; // r4
  int v4; // r5
  int v5; // r6
  volatile uint32_t *v6; // r2
  volatile uint32_t *v7; // r7
  volatile int *v8; // r3
  int v9; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110BD8 = 1;
  }
  v1 = (void *)(uintptr_t)(off_110BDC);
  v2 = (void *)(uintptr_t)(off_110BE0);
  v3 = *(volatile uint32_t *)off_110BDC;
  v4 = *(volatile uint32_t *)off_110BDC + 1;
  *(volatile uint32_t *)off_110BDC = v4;
  *v2 = 64;
  while ( (*v2 & 0x80) != 0 )
    ;
  if ( *(volatile uint32_t *)off_110BE4 )
  {
    v5 = dword_110BE8;
    v6 = (void *)(uintptr_t)(off_110BEC);
    *(volatile uint32_t *)(*(volatile uint32_t *)(dword_110BE8 + 6164) + 4) = result;
  }
  else
  {
    v6 = (void *)(uintptr_t)(off_110BEC);
    *(volatile uint32_t *)off_110BE4 = result;
    v5 = dword_110BE8;
  }
  ++*v6;
  v7 = (void *)(uintptr_t)(off_110BF4);
  *(volatile uint8_t *)off_110BF0 |= 2u;
  *v7 = 64;
  *(volatile uint32_t *)(v5 + 6164) = result;
  if ( v4 )
  {
    v8 = (volatile int *)off_110BD8;
    *v1 = v3;
    v9 = *v8;
    if ( !v3 )
    {
      if ( v9 )
        __enable_irq();
    }
  }
  return result;
}



// ke_alloc_node @ 0x110bf8
int ke_alloc_node(char a1, volatile char *a2, unsigned int a3, int a4) {
  volatile uint32_t *v7; // r0
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r6
  int v10; // r2
  int v11; // r3

  v7 = mem_alloc_checked(4);
  if ( !v7 )
    return log_printf(aErrNoMsgPkt);
  v8 = v7;
  v9 = (void *)(uintptr_t)(irq_disable());
  if ( v9 )
  {
    *(volatile uint8_t *)v8 = a3;
    *((volatile uint8_t *)v8 + 1) = BYTE1(a3) & 0xF;
    *((volatile uint8_t *)v8 + 2) = a1;
    *((volatile uint8_t *)v8 + 3) = 0;
    memcpy((volatile char *)v8 + 4, a2, a3);
    v10 = v9[2];
    v11 = dword_110C70;
    v9[1] = 0;
    *v9 = (int)(uintptr_t)(v8);
    v9[2] = (uint16_t)(a3 + 4) | v11 & v10 | 0x80000000;
    return irq_disable_set_flag_4((int)v9);
  }
  else
  {
    log_printf(aErrSendMsgCfgT);
    return mem_free(v8);
  }
}


// rf_reg_update @ 0x110c7c
int rf_reg_update(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (volatile int *)off_110CF8;
  v2 = a1 & 0x3FFFFF;
  v3 = *(volatile uint32_t *)off_110CF8 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(volatile uint32_t *)off_110CF8 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(volatile uint32_t *)off_110CF8 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return log_printf("sdio pahse cfg %x\n", *(volatile uint32_t *)off_110CF8 & 0x3FFFFF);
}


