// rx_pkt_status_update @ 0x115754
volatile int * rx_pkt_status_update(int a1, int a2, int a3, int a4) {
  int v5; // r1
  volatile int16_t **v9; // r8
  int v10; // r7
  int v11; // r3
  int v12; // r3
  int v13; // zf
  int16_t v14; // r2
  volatile uint16_t *v15; // r3
  int16_t v16; // r1

  v5 = *(volatile uint16_t *)(a2 + 4);
  *(volatile uint16_t *)(a1 + 38) |= 4u;
  if ( !v5 )
    return (void *)(uintptr_t)(pdu_type_init(*(volatile uint32_t *)(a1 + 32) + 8, *(volatile uint32_t *)(a1 + 32) + 8, a4, a4));
  v9 = (volatile int16_t **)off_11581C;
  v10 = *(volatile uint32_t *)(a2 + 32);
  if ( **(volatile int16_t **)off_11581C < 0 )
  {
    if ( *(volatile uint32_t *)(a2 + 28) )
    {
      v11 = *(volatile uint32_t *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
    }
    else
    {
      flash_ctrl_init(dword_115818, dword_11580C, 518);
      v11 = *(volatile uint32_t *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
      if ( **v9 >= 0 )
        goto LABEL_5;
    }
    v12 = *(volatile uint32_t *)(v10 + 20);
    if ( v12 )
      goto LABEL_6;
    flash_ctrl_init(dword_115810, dword_11580C, 525);
LABEL_5:
    v12 = *(volatile uint32_t *)(v10 + 20);
LABEL_6:
    v11 = *(volatile uint32_t *)(v12 + 8);
    goto LABEL_7;
  }
  v11 = *(volatile uint32_t *)(v10 + 24);
  if ( !v11 )
    goto LABEL_5;
LABEL_7:
  if ( *(volatile uint8_t *)(a2 + 14) == 255 )
  {
    v14 = *(volatile uint8_t *)(v11 + 22) & 0xF;
    v13 = (*(volatile uint8_t *)(v11 + 22) & 0xF) == 0;
    v15 = (volatile uint16_t *)(v11 + 22);
    if ( v13 )
    {
      v16 = *((volatile uint16_t *)off_115814 + 70) + 1;
      *((volatile uint16_t *)off_115814 + 70) = v16;
    }
    else
    {
      v16 = *((volatile uint16_t *)off_115814 + 70);
    }
    *v15 = v14 | (16 * v16);
  }
  llm_adv_pdu_build(a2);
  return (void *)(uintptr_t)(pdu_type_init(*(volatile uint32_t *)(a1 + 32) + 8, *(volatile uint32_t *)(a1 + 32) + 8, a4, a4));
}



// ble_ll_init @ 0x115820
int ble_ll_init() {
  volatile int *v0; // r4
  int v1; // r0
  int v2; // r0
  int result; // r0

  v0 = (volatile int *)off_11588C;
  v1 = read_sensor_value();
  v2 = ((int (*)())nullsub_4)(v1);
  clear_config_32(v2);
  wlan_attach(0);
  memset(v0, 0, 0x94u);
  list_init_1((void *)(v0 + 3));
  *v0 = 0;
  *((volatile uint8_t *)v0 + 26) = 0;
  list_init_1((void *)(v0 + 10));
  v0[7] = 0;
  *((volatile uint8_t *)v0 + 54) = 0;
  list_init_1((void *)(v0 + 17));
  v0[14] = 0;
  *((volatile uint8_t *)v0 + 82) = 0;
  list_init_1((void *)(v0 + 24));
  v0[21] = 0;
  *((volatile uint8_t *)v0 + 110) = 0;
  result = (int)(uintptr_t)(list_init_1((void *)(v0 + 31)));
  v0[28] = 0;
  *((volatile uint8_t *)v0 + 138) = 0;
  *((volatile uint16_t *)v0 + 70) = 0;
  return result;
}



// rf_is_idle @ 0x115890
BOOL rf_is_idle() {
  return *((volatile uint8_t *)off_1158A0 + 142) == 0;
}



// mmio_irq_set @ 0x1158a4
int mmio_irq_set(int result) {
  int v1; // r3
  int v2; // r6
  volatile uint32_t *v3; // r2
  volatile int *v4; // r5
  int v5; // r4
  int v6; // r1
  volatile int *v7; // r3
  int v8; // r3
  volatile uint32_t *v9; // r2
  volatile uint32_t *v10; // r2
  volatile uint32_t *v11; // r2
  volatile uint32_t *v12; // r2
  volatile uint32_t *v13; // r2

  v1 = *(volatile uint32_t *)off_1159A0;
  v2 = 1 << result;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1159A4 = 1;
  }
  v3 = (void *)(uintptr_t)(off_1159A8);
  v4 = (volatile int *)off_1159A0;
  v5 = *(volatile uint32_t *)off_1159A8;
  v6 = *(volatile uint32_t *)off_1159A8 + 1;
  *(volatile uint32_t *)off_1159A8 = v6;
  *v4 = v1 & ~v2;
  if ( v6 )
  {
    v7 = (volatile int *)off_1159A4;
    *v3 = v5;
    v8 = *v7;
    if ( !v5 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_1159AC = v2;
  switch ( result )
  {
    case 0:
      v10 = (void *)(uintptr_t)(off_1159B4);
      *(volatile uint32_t *)off_1159B0 = 0x10000;
      while ( (*v10 & 0x30) != 0 )
        ;
      *(volatile uint32_t *)off_1159B8 = 0x10000;
      break;
    case 1:
      v12 = (void *)(uintptr_t)(off_1159B4);
      *(volatile uint32_t *)off_1159B0 = 0x20000;
      while ( (*v12 & 0x300) != 0 )
        ;
      *(volatile uint32_t *)off_1159B8 = 0x20000;
      break;
    case 2:
      v11 = (void *)(uintptr_t)(off_1159B4);
      *(volatile uint32_t *)off_1159B0 = 0x40000;
      while ( (*v11 & 0x3000) != 0 )
        ;
      *(volatile uint32_t *)off_1159B8 = 0x40000;
      break;
    case 3:
      v13 = (void *)(uintptr_t)(off_1159B4);
      *(volatile uint32_t *)off_1159B0 = 0x80000;
      while ( (*v13 & 0x30000) != 0 )
        ;
      *(volatile uint32_t *)off_1159B8 = 0x80000;
      break;
    case 5:
      v9 = (void *)(uintptr_t)(off_1159B4);
      *(volatile uint32_t *)off_1159B0 = 0x200000;
      while ( (*v9 & 0x3000000) != 0 )
        ;
      *(volatile uint32_t *)off_1159B8 = 0x200000;
      break;
    default:
      if ( **(volatile int16_t **)off_1159BC < 0 )
        result = flash_ctrl_init(dword_1159C4, dword_1159C0, 2338);
      break;
  }
  return result;
}



// llm_pdu_cfg_update @ 0x1159c8
int llm_pdu_cfg_update(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r4
  int v3; // r11
  volatile uint32_t *v4; // r9
  int v5; // r8
  volatile uint32_t *v6; // r7
  volatile int *v7; // r3
  int v8; // r10
  int v9; // r2
  int v10; // r3
  volatile uint32_t *v11; // r2
  volatile int *v12; // r5
  int v13; // r1
  int v14; // r4
  volatile int *v15; // r3
  int v16; // r3
  int v17; // [sp+4h] [bp-8h]

  if ( result == 5 )
    v1 = (volatile uint32_t *)dword_115AB0;
  else
    v1 = (volatile uint32_t *)dword_115AAC;
  if ( result != 5 )
    v1 += 7 * result;
  v2 = v1[3];
  v3 = result;
  if ( v2 )
  {
    v4 = (void *)(uintptr_t)(off_115AC8);
    v5 = dword_115ACC;
    v17 = result + dword_115AB4;
    v6 = (volatile uint32_t *)(4 * (result + dword_115AB4));
    while ( 1 )
    {
      v7 = *(volatile int **)(v2 + 32);
      v8 = v7[17];
      if ( v8 >= 0 )
        break;
      v9 = v7[3];
      *v7 = v8;
      if ( v9 )
      {
        if ( *(volatile int *)(v9 + 60) >= 0 )
        {
          *(volatile uint32_t *)(4 * v17) = *(volatile uint32_t *)off_115AC8 + *(volatile uint32_t *)(dword_115ACC + 4 * v3);
          return result;
        }
      }
      else
      {
        *v1 = 0;
        mmio_irq_set(v3);
      }
      list_pop_front((int)(uintptr_t)(v1 + 3));
      if ( *(volatile uint16_t *)(v2 + 4) )
        result = event_cb_register(v2, v8, v3);
      else
        result = ((int (*)())log_and_disable_irq)((void *)(uintptr_t)(v2), v8, v3);
      v2 = v1[3];
      *v6 = *v4 + *(volatile uint32_t *)(v5 + 4 * v3);
      if ( !v2 )
        goto LABEL_16;
    }
  }
  else
  {
LABEL_16:
    v10 = *(volatile uint32_t *)off_115AB8;
    *v1 = 0;
    result = 1 << v3;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_115ABC = 1;
    }
    v11 = (void *)(uintptr_t)(off_115AC0);
    v12 = (volatile int *)off_115AB8;
    v13 = *(volatile uint32_t *)off_115AC0;
    v14 = *(volatile uint32_t *)off_115AC0 + 1;
    *(volatile uint32_t *)off_115AC0 = v14;
    *v12 = v10 & ~result;
    if ( v14 )
    {
      v15 = (volatile int *)off_115ABC;
      *v11 = v13;
      v16 = *v15;
      if ( !v13 )
      {
        if ( v16 )
          __enable_irq();
      }
    }
    *(volatile uint32_t *)off_115AC4 = result;
  }
  return result;
}



// llm_pdu_tx_cfg @ 0x115ad0
int llm_pdu_tx_cfg(int a1) {
  volatile uint32_t *v1; // r5
  int v3; // r3
  int v4; // r4
  volatile uint32_t *v5; // r2
  volatile int *v6; // r5
  int v7; // r1
  int result; // r0
  volatile int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v1 = (volatile uint32_t *)dword_115B4C;
  else
    v1 = (volatile uint32_t *)dword_115B48;
  if ( a1 != 5 )
    v1 += 7 * a1;
  ((int (*)())wlan_hw_init)(a1, dword_115B44 + 8 * a1, 0);
  ((int (*)())wlan_hw_init)(a1, (int)(uintptr_t)(v1 + 3), 0);
  *v1 = 0;
  v1[5] = 0;
  get_channel_params(a1);
  v3 = *(volatile uint32_t *)off_115B50;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115B54 = 1;
  }
  v5 = (void *)(uintptr_t)(off_115B58);
  v6 = (volatile int *)off_115B50;
  v7 = *(volatile uint32_t *)off_115B58;
  result = *(volatile uint32_t *)off_115B58 + 1;
  *(volatile uint32_t *)off_115B58 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (volatile int *)off_115B54;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_115B5C = v4;
  return result;
}



// llm_scan_pdu_cfg @ 0x115b60
int llm_scan_pdu_cfg(int a1, int a2) {
  volatile uint8_t *v4; // r3
  volatile char *v5; // r0
  volatile int *v6; // r5
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2
  int v11; // r2
  int v12; // r1
  int16_t v13; // r3
  volatile int *v14; // r3
  int v15; // r3
  int v16; // r2
  int v17; // r3
  int v18; // r2
  int v20; // r3
  int v21; // r0
  volatile uint32_t *v22; // r3

  if ( a2 == 5 )
  {
    v5 = (volatile char *)dword_115C84;
    v4 = (volatile uint8_t *)(dword_115C84 - 112);
  }
  else
  {
    v4 = (void *)(uintptr_t)(off_115C74);
    v5 = (volatile char *)off_115C74 + 28 * a2;
  }
  if ( v4[142] )
  {
    v20 = *(volatile uint8_t *)(a1 + 16);
    if ( v20 == 255 )
    {
      wlan_tx_kick(a1, 0);
      return 0;
    }
    else
    {
      v21 = dword_115C80;
      *(volatile uint8_t *)(a1 + 14) = a2;
      *(volatile uint8_t *)(a1 + 53) = 1;
      check_kernel_state(v21 + 152 * (int16_t)v20 + 48, (volatile uint32_t *)a1);
      return 1;
    }
  }
  *(volatile uint32_t *)(*(volatile uint32_t *)(a1 + 32) + 64) |= 0x100u;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115C78 = 1;
  }
  v6 = (volatile int *)off_115C7C;
  v7 = *((volatile uint32_t *)v5 + 5);
  ++*(volatile uint32_t *)off_115C7C;
  if ( v7 )
  {
    check_kernel_state((int)(v5 + 12), (volatile uint32_t *)a1);
    v8 = *v6;
    if ( *v6 )
    {
LABEL_8:
      v9 = v8 - 1;
      v10 = *(volatile uint32_t *)off_115C78;
      *v6 = v9;
      if ( !v9 && v10 )
        __enable_irq();
    }
  }
  else
  {
    v22 = *(volatile uint32_t **)(a1 + 28);
    v22[4] = dword_115C88;
    v22[2] = a1;
    v22[3] = a1;
    check_kernel_state((int)(v5 + 12), (volatile uint32_t *)a1);
    v8 = *v6;
    if ( *v6 )
      goto LABEL_8;
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115C78 = 1;
  }
  v11 = *v6;
  v12 = *v6 + 1;
  v13 = *(volatile uint16_t *)(a1 + 38) | 1;
  *v6 = v12;
  *(volatile uint16_t *)(a1 + 38) = v13;
  if ( v12 )
  {
    v14 = (volatile int *)off_115C78;
    *v6 = v11;
    v15 = *v14;
    if ( !v11 )
    {
      if ( v15 )
        __enable_irq();
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115C78 = 1;
  }
  v16 = *(volatile uint32_t *)(a1 + 28);
  ++*v6;
  rx_pkt_status_update(a1, a1, v16, a2);
  if ( *v6 )
  {
    v17 = *v6 - 1;
    v18 = *(volatile uint32_t *)off_115C78;
    *v6 = v17;
    if ( !v17 )
    {
      if ( v18 )
        __enable_irq();
    }
  }
  return 1;
}


// nullsub_7 @ 0x115c8c
int nullsub_7(void) {
  return 0;
}


// mmio_status_clear @ 0x115c90
void mmio_status_clear() {
  *((volatile uint32_t *)off_115C9C + 1) = dword_115CA0 & *(volatile uint32_t *)off_115C9C;
}



// mmio_status_write @ 0x115d4c
void mmio_status_write() {
  *(volatile uint32_t *)off_115D60 = *(volatile uint32_t *)off_115D5C & 0xF00000;
}



// critical_section_enter_1 @ 0x115d64
int critical_section_enter_1() {
  volatile int *v0; // r6
  volatile uint8_t *v1; // r7
  volatile uint8_t *v2; // r5
  int i; // r4
  int v4; // r3
  int result; // r0
  int v6; // r3
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115DB0 = 1;
  }
  v0 = (volatile int *)off_115DB4;
  v1 = (void *)(uintptr_t)(off_115DB8);
  ++*(volatile uint32_t *)off_115DB4;
  v2 = v1;
  for ( i = 4; i != -1; --i )
  {
    v4 = *((volatile uint32_t *)v2 + 28);
    result = (uint8_t)i;
    v2 -= 28;
    if ( v4 )
      result = mmio_irq_set(result);
  }
  v6 = *v0;
  v1[143] = 1;
  if ( v6 )
  {
    v7 = v6 - 1;
    v8 = *(volatile uint32_t *)off_115DB0;
    *v0 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}



// critical_section_exit @ 0x115dbc
int critical_section_exit() {
  volatile int *v0; // r10
  volatile uint8_t *v1; // r5
  volatile uint32_t *v2; // r8
  int v3; // r9
  int v4; // r7
  volatile uint32_t *v5; // r6
  volatile int *v6; // r11
  int i; // r4
  int v8; // r0
  int v9; // r1
  int v10; // r3
  volatile int *v11; // r3
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_115E78 = 1;
  }
  v0 = (volatile int *)off_115E88;
  v1 = (void *)(uintptr_t)(off_115E7C);
  v2 = (void *)(uintptr_t)(off_115E8C);
  v3 = dword_115E90;
  v4 = dword_115E80;
  v5 = (void *)(uintptr_t)(off_115E84);
  v6 = (volatile int *)off_115E94;
  ++*(volatile uint32_t *)off_115E88;
  v1[143] = 0;
  for ( i = 4; i != -1; --i )
  {
    if ( *((volatile uint32_t *)v1 + 28) )
    {
      radio_pdu_type_cfg((uint8_t)i);
      *(volatile uint32_t *)(v4 + 4 * i) = *v2 + *(volatile uint32_t *)(v3 + 4 * i);
      *v5 = 1 << i;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_115E78 = 1;
      }
      v8 = *v0;
      v9 = *v0 + 1;
      v10 = (1 << i) | *v6;
      *v0 = v9;
      *v6 = v10;
      if ( v9 )
      {
        v11 = (volatile int *)off_115E78;
        *v0 = v8;
        v12 = *v11;
        if ( !v8 )
        {
          if ( v12 )
            __enable_irq();
        }
      }
    }
    v1 -= 28;
  }
  if ( *v0 )
  {
    v13 = *v0 - 1;
    v14 = *(volatile uint32_t *)off_115E78;
    *v0 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return set_busy_flag_alt(4096);
}



// rf_acquire @ 0x115e98
volatile uint32_t *rf_acquire() {
  volatile uint8_t *v0; // r5
  int v1; // r8
  int v2; // r7
  volatile int *v3; // r4
  int v4; // r6
  unsigned int v5; // r9
  int v6; // r6
  uint16_t v7; // r4
  int v8; // r2
  volatile uint32_t *result; // r0
  volatile uint32_t *v10; // r3
  int buf[9]; // [sp+0h] [bp-24h] BYREF

  v0 = (void *)(uintptr_t)(off_115F68);
  v1 = dword_115F74;
  enter_critical_section_1(1966080);
  v0[142] = 1;
  v2 = (int)(v0 + 12);
  v3 = buf;
  v4 = 0;
  do
  {
    v5 = (uint8_t)v4;
    list_init_1((void *)(v3));
    wlan_hw_init((uint8_t)v4++, v1);
    wlan_hw_init(v5, v2);
    v1 += 8;
    v3 += 2;
    v2 += 28;
  }
  while ( v4 != 4 );
  v6 = off_115F6C;
  wlan_clk_init(5, off_115F6C);
  clear_config_32();
  v7 = *((volatile uint16_t *)v0 + 70);
  memset((volatile int *)(v6 - 124), 0, 0x94u);
  *((volatile uint16_t *)v0 + 70) = v7;
  list_init_1((volatile uint32_t *)(v6 - 112));
  *(volatile uint32_t *)(v6 + 0xFFFFFF84) = 0;
  v0[26] = 0;
  list_init_1((volatile uint32_t *)(v6 - 84));
  *((volatile uint32_t *)v0 + 7) = 0;
  v0[54] = 0;
  list_init_1((volatile uint32_t *)(v6 - 56));
  *((volatile uint32_t *)v0 + 14) = 0;
  v0[82] = 0;
  list_init_1((volatile uint32_t *)(v6 - 28));
  v8 = dword_115F70;
  *((volatile uint32_t *)v0 + 21) = 0;
  v0[110] = 0;
  result = (volatile uint32_t *)(v8 + 144);
  do
  {
    v10 = (volatile uint32_t *)(v8 - 36);
    do
      *v10++ = 0;
    while ( v10 != (volatile uint32_t *)v8 );
    v8 = (int)(v10 + 9);
  }
  while ( v10 + 9 != result );
  return result;
}


// rf_wait_timeout @ 0x115f78
int rf_wait_timeout(int a1) {
  volatile uint32_t *v1; // r6
  volatile uint32_t *v2; // r7
  int v3; // r2
  volatile uint32_t *v4; // r4
  int result; // r0
  volatile int *v6; // r1
  int v7; // r3
  int v8; // t1

  v1 = (void *)(uintptr_t)(off_115FB4);
  v2 = (void *)(uintptr_t)(off_115FB8);
  v3 = a1 - 4;
  v4 = (void *)(uintptr_t)(off_115FB4);
  result = a1 + 12;
  v6 = (volatile int *)off_115FB8;
  do
  {
    v8 = *(volatile uint32_t *)(v3 + 4);
    v3 += 4;
    v7 = v8;
    if ( !v8 )
      v7 = *v6;
    *v4++ = 1000 * v7;
    ++v6;
  }
  while ( v3 != result );
  v1[4] = 1000 * v2[4];
  return result;
}



// clear_config_32 @ 0x115fbc
int clear_config_32() {
  int v0; // r4

  v0 = dword_115FEC;
  memset((volatile int *)dword_115FEC, 0, 0x20u);
  list_init_1((void *)(uintptr_t)(v0));
  list_init_1((void *)(uintptr_t)(v0 + 8));
  list_init_1((void *)(uintptr_t)(v0 + 16));
  return (int)(uintptr_t)(list_init_1((void *)(uintptr_t)(v0 + 24)));
}



// event_cb_register @ 0x115ff0
int event_cb_register(int a1, int a2, int a3) {
  int v3; // r3

  v3 = dword_116014;
  **(volatile uint32_t **)(a1 + 32) = a2;
  check_kernel_state(v3 + 8 * a3, (volatile uint32_t *)a1);
  return set_busy_flag_alt(((volatile uint32_t *)(uintptr_t)off_116018)[a3]);
}


