// write_reg_70001408 @ 0x10ed6c
int write_reg_70001408() {
  return atomic_reg_write(dword_10ED78, 0, 2, 1);
}



// get_periph_status @ 0x10ed7c
int get_periph_status() {
  return (uint16_t)atomic_reg_read(dword_10ED8C, 1) >> 11;
}



// set_periph_status @ 0x10ed90
int set_periph_status(int a1) {
  return atomic_reg_write(dword_10EDA4, (a1 << 11) & 0xF800, 63488, 1);
}



// periph_enable @ 0x10eda8
int periph_enable() {
  int result; // r0

  atomic_reg_write(1879048192, 256, 264, 1);
  atomic_reg_write(dword_10EF58, 0x8000000, 0x8000000, 1);
  atomic_reg_write(dword_10EF5C, 21, 31, 1);
  atomic_reg_write(dword_10EF68, dword_10EF64, dword_10EF60, 1);
  atomic_reg_write(dword_10EF6C, 2560, 2560, 1);
  atomic_reg_write(dword_10EF70, 255, 255, 1);
  atomic_reg_write(dword_10EF74, 0, 100663296, 1);
  atomic_reg_write(dword_10EF78, 0, 983040, 1);
  atomic_reg_write(dword_10EF7C, 96, 96, 1);
  atomic_reg_write(dword_10EF80, 256, 256, 1);
  atomic_reg_write(dword_10EF84, 469762048, 469762048, 1);
  atomic_reg_write(dword_10EF88, 104, 252, 1);
  atomic_reg_write(dword_10EF8C, 6, 6, 1);
  atomic_reg_write(dword_10EF90, 320, 992, 1);
  atomic_reg_write(dword_10EF9C, dword_10EF98, dword_10EF94, 1);
  atomic_reg_write(dword_10EFA0, 0x400000, 15728640, 1);
  atomic_reg_write(dword_10EFA4, 16, 63, 1);
  atomic_reg_write(dword_10EFA8, 0, 60, 1);
  atomic_reg_write(dword_10EFAC, 0, 256, 1);
  atomic_reg_write(dword_10EFB0, 2048, 16128, 1);
  result = atomic_reg_write(dword_10EFB4, 1, 1, 1);
  if ( **(volatile uint8_t **)off_10EFB8 == 1 )
  {
    atomic_reg_read_alt(dword_10EFC0, dword_10EFBC, 1);
    atomic_reg_read_alt(dword_10EFC8, dword_10EFC4, 1);
    atomic_reg_write(dword_10EFB4, 0x100000, 0x100000, 1);
    result = atomic_reg_write(dword_10EFCC, 2, 31, 1);
    if ( !*((volatile uint8_t *)off_10EFD0 + 375) )
    {
      atomic_reg_write(dword_10EFD4, 1, 1, 1);
      atomic_reg_write(dword_10EFAC, 256, 256, 1);
      atomic_reg_write(dword_10EFB0, 0x2000, 16128, 1);
      atomic_reg_write(dword_10EF74, 2359296, 16515072, 1);
      return atomic_reg_write(dword_10EFB4, 256, 256, 1);
    }
  }
  return result;
}



// fw_set_cmd @ 0x10efd8
unsigned int fw_set_cmd() {
  unsigned int result; // r0

  result = write_mmio_byte(0xC2u);
  *((volatile uint8_t *)off_10EFEC + 7) = -62;
  return result;
}



// phy_get_status @ 0x10eff0
int phy_get_status() {
  volatile uint8_t *v0; // r6
  int v1; // r5
  int v2; // r4
  int result; // r0
  volatile unsigned int v4; // r3

  v0 = (void *)(uintptr_t)(off_10F050);
  v1 = (char)(*((volatile uint8_t *)off_10F050 + 5) + (*(volatile uint8_t *)off_10F04C & 3));
  v2 = *((volatile char *)off_10F050 + 7) - v1;
  if ( v2 < -62 )
    v2 = (v2 & ~0xFFu) | ((uint8_t)(-62) & 0xFFu);
  write_mmio_byte(v2);
  v0[7] = v2;
  result = ke_event_schedule_1("update# =%d %d\r\n", (char)v2, v1);
  if ( (char)v2 < -61 )
  {
    v0[11] = 0;
  }
  else
  {
    v4 = (*(volatile uint32_t *)0x40501010u);
    return ke_event_lock((volatile uint32_t *)v0 + 3, v4 + 30000 * *((volatile uint16_t *)v0 + 4));
  }
  return result;
}


// copy_stats @ 0x10f05c
int copy_stats() {
  int v0; // r2
  uint64_t v1; // kr00_8
  volatile char *v2; // r3
  uint64_t v3; // r0
  int v4; // r4
  int v5; // r2
  uint64_t v6; // kr10_8

  v0 = *(volatile uint32_t *)off_10F0A8;
  v1 = *(volatile uint64_t *)(*(volatile uint32_t *)off_10F0A8 + 24);
  v2 = (volatile char *)off_10F0AC;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)(*(volatile uint32_t *)off_10F0A8 + 36)) & 0xFFFFFFFFu);
  v4 = *(volatile uint32_t *)(*(volatile uint32_t *)off_10F0A8 + 32);
  *(volatile uint32_t *)off_10F0AC = v1;
  v6 = *(volatile uint64_t *)(v0 + 40);
  v5 = *(volatile uint32_t *)(v0 + 44);
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v6) << 32);
  *((volatile uint32_t *)v2 + 1) = HIDWORD(v1);
  *((volatile uint32_t *)v2 + 2) = v4;
  *(volatile uint64_t *)(v2 + 12) = v3;
  *((volatile uint32_t *)v2 + 5) = v5;
  hw_enable();
  hw_config_init_0688();
  enable_nvic_irq();
  if ( **(volatile uint8_t **)off_10F0B0 == 3 )
    clear_context_182b48();
  return (int)(uintptr_t)(clear_182b70_struct());
}


// check_hw_flag @ 0x10f0b4
int check_hw_flag() {
  volatile uint8_t *v0; // r3
  int result; // r0
  int v2; // r1
  int v3; // r2

  if ( *((volatile uint8_t *)off_10F0E8 + 362) )
  {
    *(volatile uint8_t *)off_10F0EC = 0;
  }
  else
  {
    v0 = (void *)(uintptr_t)(off_10F0EC);
    *(volatile uint32_t *)off_10F0EC = dword_10F0F0;
    v2 = dword_10F0F4;
    v3 = dword_10F0F8;
    v0[7] = -62;
    *((volatile uint32_t *)v0 + 2) = 1000;
    *((volatile uint16_t *)v0 + 2) = 1752;
    *((volatile uint32_t *)v0 + 4) = v2;
    *((volatile uint32_t *)v0 + 8) = v3;
    return 1752;
  }
  return result;
}



// wait_event @ 0x10f1c8
int wait_event(int a1, int a2) {
  memory_pool_free((void *)(uintptr_t)(a2));
  return 1;
}



// send_msg @ 0x10f1d4
int send_msg() {
  volatile uint8_t *v0; // r4
  volatile char *v1; // r0

  v0 = (void *)(uintptr_t)(off_10F204);
  v1 = (volatile char *)off_10F204 + 1624;
  *((volatile uint16_t *)off_10F204 + 810) = 80;
  v0[1622] = 81;
  zero_struct((void *)(v1));
  *((volatile uint16_t *)v0 + 1216) = 39;
  v0[2434] = 40;
  return (int)(uintptr_t)(zero_struct((void *)(v0 + 2436)));
}



// init_fw_table @ 0x10f208
uint64_t init_fw_table() {
  volatile uint16_t *v0; // r5
  volatile int *v1; // r4
  volatile int *v2; // r5
  int v3; // r6
  volatile int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  volatile uint32_t *v7; // r3

  v0 = (void *)(uintptr_t)(off_10F2A4);
  v1 = (volatile int *)dword_10F2A8;
  *((volatile uint16_t *)off_10F2A4 + 3080) = -16193;
  v0[1536] = -16193;
  *((volatile uint8_t *)v0 + 6162) = 0;
  *((volatile uint32_t *)v0 + 1541) = 0;
  *((volatile uint8_t *)v0 + 6176) = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  zero_struct((volatile uint32_t *)v0 + 770);
  zero_struct((void *)(v1 - 3));
  zero_struct((void *)(v1 + 512));
  zero_struct((void *)(v1 + 514));
  v0[4122] = 0;
  *((volatile uint8_t *)v0 + 3074) = 0;
  *((volatile uint32_t *)v0 + 769) = 0;
  memset(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = (int)(v1 + 512);
  do
  {
    v4 = v1;
    v1 += 4;
    check_abort_flag(v3, (void *)(v4));
  }
  while ( v1 != v2 );
  v5 = dword_10F2AC;
  result = (unsigned int)(dword_10F2AC + 1152);
  do
  {
    v7 = (volatile uint32_t *)(v5 - 36);
    do
      *v7++ = 0;
    while ( v7 != (volatile uint32_t *)v5 );
    v5 = (int)(v7 + 9);
  }
  while ( v7 + 9 != (volatile uint32_t *)result );
  return result;
}


// process_state @ 0x10f2b0
int process_state() {
  volatile uint8_t **v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r3
  int v3; // r2
  uint64_t v4; // r0
  int v5; // r3
  volatile uint32_t *v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r3
  int v9; // r2
  int ( **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int ( **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int ( **v17)(int); // r5
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (volatile uint8_t **)off_10F370;
  v1 = **(volatile uint8_t **)off_10F370;
  switch ( v1 )
  {
    case 1:
      v8 = (void *)(uintptr_t)(off_10F374);
      v9 = dword_10F38C;
      *((volatile uint32_t *)off_10F374 + 2) = dword_10F388;
      v8[3] = v9;
      break;
    case 2:
      v2 = (void *)(uintptr_t)(off_10F374);
      v3 = dword_10F37C;
      *((volatile uint32_t *)off_10F374 + 6) = dword_10F378;
      v2[7] = v3;
      break;
    case 3:
      v6 = (void *)(uintptr_t)(off_10F374);
      v7 = dword_10F384;
      *((volatile uint32_t *)off_10F374 + 8) = dword_10F380;
      v6[9] = v7;
      break;
  }
  send_msg();
  v4 = init_fw_table();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int ( **)(int))off_10F374;
    *(volatile uint32_t *)off_10F390 = dword_10F3A4;
    v18 = (int)(uintptr_t)(tx_irq_handler(v4, HIDWORD(v4)));
    v19 = (int)(uintptr_t)(adv_irq_handler(v18));
    v20 = (int)(uintptr_t)(scan_irq_handler(v19));
    rx_irq_handler(v20);
    v21 = v17[2](dword_10F398);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v17[3](v21)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F3A0;
    *(volatile uint32_t *)off_10F390 = dword_10F39C;
    v13 = (int ( **)(int))off_10F374;
    *(volatile uint16_t *)(v12 + 8244) = 0;
    v14 = (int)(uintptr_t)(bt_evt_sched_low());
    bt_evt_sched_high(v14);
    v15 = v13[6](dword_10F398);
    v16 = v13[7](v15);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(log_and_handle(v16)) & 0xFFFFFFFFu);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int ( **)(int))off_10F374;
    *(volatile uint32_t *)off_10F390 = dword_10F394;
    init_hw_timers();
    v11 = v10[8](dword_10F398);
    v4 = (v4 & ~0xFFFFFFFFull) | ((uint32_t)(v10[9](v11)) & 0xFFFFFFFFu);
  }
  return v4;
}



// ke_msg_alloc @ 0x10f3a8
int ke_msg_alloc() {
  int result; // r0
  volatile int *v1; // r9
  volatile uint32_t *v2; // r0
  int v3; // r2
  volatile int *v4; // r3
  int v5; // r3
  int v6; // r11
  volatile int16_t **v7; // r6
  int v8; // r5
  int v9; // r8
  int v10; // r7
  volatile uint32_t *v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r2
  int v15; // r1
  int v16; // r10
  volatile uint8_t *v17; // r3
  volatile uint32_t *v18; // r8
  int v19; // r2
  int v20; // r1
  volatile uint32_t *v21; // r0
  int v22; // r3
  int v23; // r2
  volatile uint32_t *v24; // r0
  int v25; // [sp+0h] [bp-Ch]
  int v26; // [sp+0h] [bp-Ch]
  int a1; // [sp+4h] [bp-8h]

  result = set_system_flag_2(512);
  a1 = *((volatile uint32_t *)off_10F68C + 2);
  if ( !a1 )
    return result;
  v1 = (volatile int *)off_10F6B8;
  while ( 2 )
  {
    result = init_once(a1);
    if ( !result && *(volatile uint8_t *)(a1 + 108) )
      goto LABEL_4;
    for ( ; *(volatile uint32_t *)(a1 + 1312); result = tx_prepare_frame_path((unsigned int)v2, 3) )
    {
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_10F690 = 1;
      }
      ++*v1;
      v2 = list_pop_front(a1 + 1312);
      v3 = *v1 - 1;
      if ( *v1 )
      {
        v4 = (volatile int *)off_10F690;
        *v1 = v3;
        v5 = *v4;
        if ( !v3 )
        {
          if ( v5 )
            __enable_irq();
        }
      }
    }
    if ( *((volatile uint8_t *)off_10F694 + 511) )
      goto LABEL_4;
    v6 = a1;
    v7 = (volatile int16_t **)off_10F698;
    v8 = dword_10F69C;
    v9 = 4;
    if ( *(volatile uint32_t *)(a1 + 1304) )
    {
LABEL_16:
      v10 = (uint8_t)v9;
      v25 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v11 = list_pop_front(v6 + 1304);
          v12 = *((volatile uint8_t *)v11 + 29);
          v13 = (unsigned int)v11;
          if ( **v7 < 0 && v12 > 0x1F )
          {
            mmio_irq_clear((int)aTxdescTmpHostS, (int)aReplenishSend, 374);
            v12 = *(volatile uint8_t *)(v13 + 29);
          }
          v14 = v8 + 696 * v12;
          if ( *(volatile uint8_t *)(v14 + 37) || (*(volatile uint16_t *)(v13 + 30) & 8) != 0 )
            break;
          ke_event_schedule_1("sta invalid:%d\n", *(volatile uint8_t *)(v14 + 35));
          rf_set_band_config(v13, v10, 0x80000000);
          if ( !*(volatile uint32_t *)(v6 + 1304) )
          {
LABEL_25:
            v9 = v25;
            goto LABEL_26;
          }
        }
        if ( *(volatile uint8_t *)(v8 + 696 * v12 + 36) != 1 )
        {
          tx_prepare_frame_path(v13, v10);
          goto LABEL_24;
        }
        if ( **v7 < 0 )
        {
          if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          {
LABEL_56:
            check_abort_flag(v8 + 8 * (87 * (int16_t)v12 + v25 + 78), (volatile uint32_t *)v13);
            goto LABEL_23;
          }
          mmio_irq_clear((int)aTxdescTmpHostF, (int)aReplenishSend, 383);
        }
        if ( (*(volatile uint16_t *)(v13 + 30) & 1) != 0 )
          goto LABEL_56;
LABEL_23:
        ke_event_schedule_1("push rt sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v12 + 35));
LABEL_24:
        if ( !*(volatile uint32_t *)(v6 + 1304) )
          goto LABEL_25;
      }
    }
    while ( 2 )
    {
      v10 = (uint8_t)v9;
LABEL_26:
      v15 = *(volatile uint32_t *)(v6 + 1264);
      if ( !v15 )
        goto LABEL_39;
      v26 = v9;
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = *(volatile uint8_t *)(v15 + 29);
          v17 = (volatile uint8_t *)(v8 + 696 * v16);
          if ( v17[37] )
            break;
          ke_event_schedule_1("sta invalid:%d\n", v17[35]);
          v24 = list_pop_front(v6 + 1264);
          rf_set_band_config((int)v24, v10, 0x80000000);
          v15 = *(volatile uint32_t *)(v6 + 1264);
          if ( !v15 )
          {
LABEL_38:
            v9 = v26;
            goto LABEL_39;
          }
        }
        if ( v17[36] != 1 )
          break;
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_10F690 = 1;
        }
        ++*v1;
        v18 = list_pop_front(v6 + 1264);
        ke_event_schedule_1("push sta:%d\r\n", *(volatile uint8_t *)(v8 + 696 * v16 + 35));
        if ( *v1 )
        {
          v19 = *v1 - 1;
          v20 = *(volatile uint32_t *)off_10F690;
          *v1 = v19;
          if ( !v19 )
          {
            if ( v20 )
              __enable_irq();
          }
        }
        check_abort_flag(v8 + 8 * (87 * (int16_t)v16 + v26 + 73), v18);
LABEL_37:
        v15 = *(volatile uint32_t *)(v6 + 1264);
        if ( !v15 )
          goto LABEL_38;
      }
      if ( phy_set_chan(v16, *(volatile uint8_t *)(v15 + 27)) )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_10F690 = 1;
        }
        ++*v1;
        v21 = list_pop_front(v6 + 1264);
        if ( *v1 )
        {
          v22 = *v1 - 1;
          v23 = *(volatile uint32_t *)off_10F690;
          *v1 = v22;
          if ( !v22 )
          {
            if ( v23 )
              __enable_irq();
          }
        }
        tx_prepare_frame_path((unsigned int)v21, v10);
        goto LABEL_37;
      }
      v9 = v26;
      *((volatile uint8_t *)off_10F694 + 512) = 1;
LABEL_39:
      --v9;
      result = ke_int_disable(v10);
      v6 -= 8;
      if ( v9 != -1 )
      {
        if ( *(volatile uint32_t *)(v6 + 1304) )
          goto LABEL_16;
        continue;
      }
      break;
    }
LABEL_4:
    a1 = *(volatile uint32_t *)a1;
    if ( a1 )
      continue;
    return result;
  }
}


// send_cmd_040d @ 0x10f764
int send_cmd_040d() {
  int v0; // r0

  v0 = bt_buf_alloc(1037, 1, 13, 8);
  return (int)(uintptr_t)(hci_evt_send(v0));
}



// ke_msg_handler @ 0x10f77c
unsigned int ke_msg_handler(volatile int *a1, int a2, unsigned int a3) {
  unsigned int result; // r0
  unsigned int v6; // r2
  unsigned int v7; // r3
  volatile int *v8; // r8
  volatile uint32_t *v9; // r9
  int v10; // r7
  volatile int *v11; // r11
  int v12; // r4
  unsigned int v13; // r5
  int v14; // r6
  volatile uint32_t *v15; // r5
  volatile uint32_t *v16; // r10
  int v17; // r3
  int v18; // r3
  int v19; // r3
  volatile uint32_t *v20; // r7
  int v21; // r5
  unsigned int v22; // r3
  unsigned int v23; // r2
  unsigned int v24; // r3
  int v25; // [sp+0h] [bp-24h]
  int v26; // [sp+4h] [bp-20h]
  unsigned int v27; // [sp+8h] [bp-1Ch]
  unsigned int v28; // [sp+Ch] [bp-18h]
  char v29; // [sp+10h] [bp-14h]

  result = *a1;
  v28 = result;
  if ( a3 )
  {
    v6 = result % a3;
    v7 = a3;
    if ( v6 )
    {
      v7 = a3 - v6;
      if ( a3 - v6 <= 3 )
        v7 += a3;
    }
    v28 = result + v7 - 4;
  }
  if ( !*((volatile uint8_t *)a1 + 8) )
    return result;
  v8 = (volatile int *)off_10F978;
  v9 = (void *)(uintptr_t)(off_10F97C);
  v25 = 0;
  v10 = 0;
  v11 = a1;
  while ( 2 )
  {
    result = *(volatile uint16_t *)(a2 + 4 * v10);
    v12 = 0;
    v13 = *(volatile uint16_t *)(a2 + 4 * v10 + 2);
    v14 = v11[3] + 12 * v10;
    *(volatile uint32_t *)v14 = 0;
    *(volatile uint16_t *)(v14 + 4) = 0;
    if ( !v13 )
      goto LABEL_6;
    v26 = result + 4;
    *(volatile uint16_t *)(v14 + 2) = v13;
    v27 = v13;
    *(volatile uint16_t *)(v14 + 4) = result;
    v15 = (volatile uint32_t *)(v28 + 4);
    v16 = nullptr;
    v29 = v10;
    do
    {
      v20 = v16;
      v16 = v15;
      if ( *v8 <= (unsigned int)v15 && *v8 + v8[1] >= (unsigned int)v15
        || *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
        *((volatile uint8_t *)v15 - 4) = v29;
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      else
      {
        printf_wrapper("set_native_pool_id: Invalid buffer passed: %x\n", v15);
        v17 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_22;
      }
      if ( v17 + v8[1] >= (unsigned int)v15 )
        goto LABEL_12;
LABEL_22:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_12:
        *((volatile uint8_t *)v15 - 3) = 85;
        v18 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_25;
        goto LABEL_13;
      }
      printf_wrapper("set_pattern: Invalid buffer passed: %x\n", v15);
      v18 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_25;
LABEL_13:
      if ( v18 + v8[1] >= (unsigned int)v15 )
        goto LABEL_14;
LABEL_25:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_14:
        *((volatile uint8_t *)v15 - 2) = 0;
        v19 = *v8;
        if ( *v8 > (unsigned int)v15 )
          goto LABEL_28;
        goto LABEL_15;
      }
      printf_wrapper("set_num_users: Invalid buffer passed: %x\n", v15);
      v19 = *v8;
      if ( *v8 > (unsigned int)v15 )
        goto LABEL_28;
LABEL_15:
      if ( v19 + v8[1] >= (unsigned int)v15 )
        goto LABEL_16;
LABEL_28:
      if ( *v9 <= (unsigned int)v15 && *v9 + v9[1] >= (unsigned int)v15 )
      {
LABEL_16:
        *v15 = (int)(uintptr_t)(v20);
        goto LABEL_17;
      }
      printf_wrapper("set_next_buffer_addr: Invalid buffer passed: %x\n", v15);
LABEL_17:
      ++v12;
      ++*(volatile uint16_t *)v14;
      v15 = (volatile uint32_t *)((volatile char *)v15 + v26);
    }
    while ( v27 > (uint16_t)v12 );
    v21 = (uint16_t)(v27 - 1);
    v22 = v28 + v21 * v26;
    result = v28 + v26 + v21 * v26;
    v28 = result;
    *(volatile uint32_t *)(v14 + 8) = v22 + 4;
    if ( a3 )
    {
      v23 = result % a3;
      v24 = a3;
      if ( result % a3 )
      {
        v24 = a3 - v23;
        if ( a3 - v23 <= 3 )
          v24 += a3;
      }
      v28 = result + v24 - 4;
    }
LABEL_6:
    v10 = (uint8_t)++v25;
    if ( *((volatile uint8_t *)v11 + 8) > (unsigned int)(uint8_t)v25 )
      continue;
    return result;
  }
}


// rx_process_item @ 0x10f980
volatile uint32_t * rx_process_item(int a1, unsigned int a2) {
  unsigned int v2; // r6
  volatile uint32_t *v3; // r5
  volatile uint16_t *v4; // r4
  unsigned int v5; // r3
  volatile int *v6; // r6
  int v7; // r3
  int v8; // r2
  volatile unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r2
  uint16_t v14; // r3
  int v15; // cc
  unsigned int v16; // r3
  volatile int *v18; // r3
  int v19; // r3
  int v20; // r3
  int v21; // r2

  v2 = *(volatile uint8_t *)(a1 + 8);
  if ( !*(volatile uint8_t *)(a1 + 8) )
  {
LABEL_57:
    printf_wrapper("SwEr:NoSizeAlloc : %d\n\r", a2);
    return nullptr;
  }
  v3 = *(volatile uint32_t **)(a1 + 12);
  if ( !v3 )
  {
    printf_wrapper(aMemmgrerrSubpo, a2);
    return v3;
  }
  v4 = *(volatile uint16_t **)(a1 + 12);
  v5 = 1;
  while ( v4[2] < a2 )
  {
    if ( v2 <= v5 )
      goto LABEL_11;
    v4 = (volatile uint16_t *)&v3[3 * v5];
LABEL_7:
    v5 = (uint8_t)(v5 + 1);
  }
  if ( *v4 )
    goto LABEL_12;
  if ( v2 > v5 )
  {
    v4 = (volatile uint16_t *)&v3[3 * v5];
    goto LABEL_7;
  }
LABEL_11:
  if ( v2 == v5 )
    goto LABEL_57;
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FB0C = 1;
  }
  v6 = (volatile int *)off_10FB10;
  v7 = *v4;
  v3 = *(volatile uint32_t **)off_10FB10;
  v8 = *(volatile uint32_t *)off_10FB10 + 1;
  *(volatile uint32_t *)off_10FB10 = v8;
  if ( !v7 )
  {
    if ( v8 )
    {
      v18 = (volatile int *)off_10FB0C;
      *v6 = (int)v3;
      v19 = *v18;
      if ( !v3 )
      {
        if ( v19 )
          goto LABEL_43;
      }
    }
    return nullptr;
  }
  v9 = (volatile unsigned int *)off_10FB14;
  v3 = *((volatile uint32_t **)v4 + 2);
  v10 = *(volatile uint32_t *)off_10FB14;
  if ( *(volatile uint32_t *)off_10FB14 <= (unsigned int)v3 && (unsigned int)v3 <= *((volatile uint32_t *)off_10FB14 + 1) + v10
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FB18
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FB18 + *((volatile uint32_t *)off_10FB18 + 1) )
  {
    *((volatile uint32_t *)v4 + 2) = *v3;
    *v4 = v7 - 1;
    if ( v10 <= (unsigned int)v3 )
      goto LABEL_18;
  }
  else
  {
    printf_wrapper("get_next_buffer_addr: Invalid buffer passed: %x\n", *((volatile uint32_t *)v4 + 2));
    v10 = *v9;
    v14 = *v4 - 1;
    v15 = *v9 > (unsigned int)v3;
    *((volatile uint32_t *)v4 + 2) = 0;
    *v4 = v14;
    if ( !v15 )
    {
LABEL_18:
      if ( v9[1] + v10 >= (unsigned int)v3 )
      {
        v11 = *((volatile uint8_t *)v3 - 3);
        if ( v11 == 85 )
          goto LABEL_20;
        goto LABEL_45;
      }
    }
  }
  v16 = *(volatile uint32_t *)off_10FB18;
  if ( *(volatile uint32_t *)off_10FB18 > (unsigned int)v3 || *((volatile uint32_t *)off_10FB18 + 1) + v16 < (unsigned int)v3 )
  {
    printf_wrapper("get_pattern: Invalid buffer passed: %x\n", v3);
    v11 = 0;
    goto LABEL_45;
  }
  v11 = *((volatile uint8_t *)v3 - 3);
  if ( v11 != 85 )
  {
LABEL_45:
    if ( *v6 )
    {
      v20 = *v6 - 1;
      v21 = *(volatile uint32_t *)off_10FB0C;
      *v6 = v20;
      if ( !v20 )
      {
        if ( v21 )
          __enable_irq();
      }
    }
    printf_wrapper("SwEr:AllcErrPtrn : %d, buffer: 0x%x\n\r", v11, v3);
    return nullptr;
  }
  if ( v10 > (unsigned int)v3 )
    goto LABEL_36;
  if ( (unsigned int)v3 <= v10 + v9[1] )
    goto LABEL_20;
  if ( (unsigned int)v3 < v16 )
  {
LABEL_37:
    printf_wrapper("set_pattern: Invalid buffer passed: %x\n", v3);
  }
  else
  {
LABEL_36:
    if ( (unsigned int)v3 > v16 + *((volatile uint32_t *)off_10FB18 + 1) )
      goto LABEL_37;
LABEL_20:
    *((volatile uint8_t *)v3 - 3) = -86;
  }
  if ( (unsigned int)v3 >= *v9 && (unsigned int)v3 <= *v9 + v9[1]
    || (unsigned int)v3 >= *(volatile uint32_t *)off_10FB18
    && (unsigned int)v3 <= *(volatile uint32_t *)off_10FB18 + *((volatile uint32_t *)off_10FB18 + 1) )
  {
    *((volatile uint8_t *)v3 - 2) = 1;
  }
  else
  {
    printf_wrapper("set_num_users: Invalid buffer passed: %x\n", v3);
  }
  if ( *v6 )
  {
    v12 = *v6 - 1;
    v13 = *(volatile uint32_t *)off_10FB0C;
    *v6 = v12;
    if ( !v12 )
    {
      if ( v13 )
LABEL_43:
        __enable_irq();
    }
  }
  return v3;
}


// list_insert @ 0x10fb38
int list_insert(int a1, volatile uint32_t *a2) {
  volatile unsigned int *v4; // r7
  unsigned int v5; // r6
  int v6; // r8
  volatile int *v7; // r5
  unsigned int v8; // r0
  int v9; // cf
  int v10; // r9
  int result; // r0
  int v12; // r3
  int v13; // r2
  volatile int *v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r6
  volatile uint16_t *v19; // r9
  int v20; // r6
  int16_t v21; // r3
  int v22; // r0
  int v23; // r3
  int v24; // r3
  int v25; // r2

  if ( !a2 )
    return -1;
  if ( *(volatile uint32_t *)a1 > (unsigned int)a2 || (unsigned int)a2 > *(volatile uint32_t *)a1 + *(volatile uint32_t *)(a1 + 4) )
    return -1;
  if ( (v4 = (volatile unsigned int *)off_10FD64, (unsigned int)a2 >= *(volatile uint32_t *)off_10FD64)
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FD64 + *((volatile uint32_t *)off_10FD64 + 1)
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FD70
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FD70 + *((volatile uint32_t *)off_10FD70 + 1) )
  {
    v5 = *((volatile uint8_t *)a2 - 4);
  }
  else
  {
    printf_wrapper("get_native_pool_id: Invalid buffer passed: %x\n", a2);
    v5 = 0;
  }
  if ( *(volatile uint8_t *)(a1 + 8) <= v5 )
    return -1;
  v6 = *(volatile uint32_t *)(a1 + 12);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_10FD68 = 1;
  }
  v7 = (volatile int *)off_10FD6C;
  v8 = *v4;
  v9 = (unsigned int)a2 >= *v4;
  ++*(volatile uint32_t *)off_10FD6C;
  if ( !v9 || (unsigned int)a2 > v4[1] + v8 )
  {
    v14 = (volatile int *)off_10FD70;
    v15 = *(volatile uint32_t *)off_10FD70;
    if ( (unsigned int)a2 < *(volatile uint32_t *)off_10FD70 || (unsigned int)a2 > *((volatile uint32_t *)off_10FD70 + 1) + v15 )
    {
      printf_wrapper("get_pattern: Invalid buffer passed: %x\n", a2);
    }
    else
    {
      v10 = *((volatile uint8_t *)a2 - 3);
      if ( v10 == 170 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_37;
        goto LABEL_15;
      }
      if ( v10 == 255 )
      {
        if ( (unsigned int)a2 < v8 )
          goto LABEL_36;
        goto LABEL_15;
      }
    }
LABEL_24:
    if ( *v7 )
    {
      v16 = *v7 - 1;
      v17 = *(volatile uint32_t *)off_10FD68;
      *v7 = v16;
      if ( !v16 )
      {
        if ( v17 )
          __enable_irq();
      }
    }
    return -1;
  }
  v10 = *((volatile uint8_t *)a2 - 3);
  if ( v10 == 170 )
  {
    result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
    *((volatile uint8_t *)a2 - 2) = result;
    if ( result )
    {
LABEL_17:
      if ( *v7 )
      {
        v12 = *v7 - 1;
        v13 = *(volatile uint32_t *)off_10FD68;
        *v7 = v12;
        if ( !v12 )
        {
          if ( v13 )
            __enable_irq();
        }
      }
      return (char)result;
    }
LABEL_40:
    v18 = 3 * v5;
    v19 = (volatile uint16_t *)(v6 + 4 * v18);
    v20 = 4 * v18;
    if ( *v19 < (unsigned int)v19[1] )
    {
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FD70
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FD70 + *((volatile uint32_t *)off_10FD70 + 1) )
      {
        *((volatile uint8_t *)a2 - 3) = 85;
      }
      else
      {
        printf_wrapper("set_pattern: Invalid buffer passed: %x\n", a2);
      }
      if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
        || (unsigned int)a2 >= *(volatile uint32_t *)off_10FD70
        && (unsigned int)a2 <= *(volatile uint32_t *)off_10FD70 + *((volatile uint32_t *)off_10FD70 + 1) )
      {
        *a2 = *((volatile uint32_t *)v19 + 2);
      }
      else
      {
        printf_wrapper("set_next_buffer_addr: Invalid buffer passed: %x\n", a2);
      }
      v21 = *(volatile uint16_t *)(v6 + v20);
      v22 = *v7;
      *((volatile uint32_t *)v19 + 2) = (int)(uintptr_t)(a2);
      *(volatile uint16_t *)(v6 + v20) = v21 + 1;
      if ( !v22 )
        return 0;
      result = v22 - 1;
      v23 = *(volatile uint32_t *)off_10FD68;
      *v7 = result;
      if ( result || !v23 )
        return 0;
      __enable_irq();
      return result;
    }
    goto LABEL_24;
  }
  if ( v10 != 255 )
    goto LABEL_24;
LABEL_15:
  if ( (unsigned int)a2 <= v8 + v4[1] )
    goto LABEL_16;
  v14 = (volatile int *)off_10FD70;
LABEL_36:
  v15 = *v14;
  if ( (unsigned int)a2 < *v14 )
  {
LABEL_38:
    printf_wrapper("decr_num_users: Invalid buffer passed: %x\n", a2);
    goto LABEL_39;
  }
LABEL_37:
  if ( (unsigned int)a2 > v15 + v14[1] )
    goto LABEL_38;
LABEL_16:
  result = (uint8_t)(*((volatile uint8_t *)a2 - 2) - 1);
  *((volatile uint8_t *)a2 - 2) = result;
  if ( result )
    goto LABEL_17;
LABEL_39:
  if ( v10 != 255 )
    goto LABEL_40;
  if ( (unsigned int)a2 >= *v4 && (unsigned int)a2 <= *v4 + v4[1]
    || (unsigned int)a2 >= *(volatile uint32_t *)off_10FD70
    && (unsigned int)a2 <= *(volatile uint32_t *)off_10FD70 + *((volatile uint32_t *)off_10FD70 + 1) )
  {
    *((volatile uint8_t *)a2 - 2) = 1;
  }
  else
  {
    printf_wrapper("set_num_users: Invalid buffer passed: %x\n", a2);
  }
  if ( *v7 )
  {
    v24 = *v7 - 1;
    v25 = *(volatile uint32_t *)off_10FD68;
    *v7 = v24;
    if ( !v24 )
    {
      if ( v25 )
        __enable_irq();
    }
  }
  return 1;
}


// is_address_in_heap @ 0x10fd8c
BOOL is_address_in_heap(unsigned int a1) {
  if ( *(volatile uint32_t *)off_10FDBC <= a1 && a1 <= *(volatile uint32_t *)off_10FDBC + *((volatile uint32_t *)off_10FDBC + 1) )
    return 1;
  if ( a1 < *(volatile uint32_t *)off_10FDC0 )
    return 0;
  return a1 <= *(volatile uint32_t *)off_10FDC0 + *((volatile uint32_t *)off_10FDC0 + 1);
}



// timer_arm @ 0x10fdc4
int timer_arm(int a1, int a2, int a3) {
  volatile uint32_t *v3; // r3
  volatile uint32_t *v4; // r3

  v3 = (void *)(uintptr_t)(off_10FE08);
  *((volatile uint32_t *)off_10FE08 + 3) = dword_10FE0C;
  *v3 = a2;
  v3[1] = a3;
  *((volatile uint8_t *)v3 + 8) = 4;
  ke_msg_handler((void *)(v3), a1, 0x20u);
  v4 = (void *)(uintptr_t)(off_10FE10);
  *((volatile uint32_t *)off_10FE10 + 5) = 4;
  v4[1] = 0x10000;
  v4[3] = 131074;
  v4[6] = 0x40000;
  *v4 = 1;
  v4[2] = 1;
  v4[4] = 0;
  *((volatile uint16_t *)v4 + 14) = 0;
  return 0x40000;
}



// set_user_id @ 0x10fe14
volatile uint32_t * set_user_id(char a1) {
  volatile uint32_t *v2; // r4

  if ( **(volatile uint8_t **)off_10FE54 == 1 )
    v2 = (void *)(uintptr_t)(critical_enter_6());
  else
    v2 = rx_process_item(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( is_address_in_heap((unsigned int)v2) )
  {
    *((volatile uint8_t *)v2 - 1) = a1;
    return v2;
  }
  printf_wrapper("set_user_id: Invalid buffer passed: %x\n", v2);
  return v2;
}


// memory_pool_free @ 0x10fe60
int memory_pool_free(volatile uint32_t *a1) {
  int result; // r0
  int v3; // r2
  int v4; // r3
  int v5; // r3

  result = is_address_in_heap((unsigned int)a1);
  if ( !result )
  {
    result = printf_wrapper("get_native_pool_id: Invalid buffer passed: %x\n", a1);
    v5 = **(volatile uint8_t **)off_10FF3C;
    if ( v5 != 1 )
    {
      if ( v5 == 2 )
        return critical_section_enter_no_set(a1);
      if ( v5 != 3 )
      {
LABEL_11:
        if ( !is_address_in_heap((unsigned int)a1) )
          printf_wrapper("get_user_id: Invalid buffer passed: %x\n", a1);
        return list_insert(dword_10FF48, a1);
      }
      if ( **(volatile int16_t **)off_10FF40 < 0 )
        return mmio_irq_clear((int)aNativeId3, (int)aPktMemFree, 204);
      return result;
    }
    return critical_enter_7(a1);
  }
  v3 = *((volatile uint8_t *)a1 - 4);
  v4 = **(volatile uint8_t **)off_10FF3C;
  if ( v4 == 1 )
  {
    if ( v3 == 3 )
      return critical_enter_3(a1);
    if ( v3 == 2 )
      return critical_enter_5(a1);
    if ( *((volatile uint8_t *)a1 - 4) )
      return result;
    return critical_enter_7(a1);
  }
  if ( v4 != 2 )
  {
    if ( v4 == 3 )
    {
      if ( **(volatile int16_t **)off_10FF40 >= 0 )
      {
        if ( v3 != 3 )
          return result;
        return set_busy_flag(a1);
      }
      if ( v3 == 3 )
        return set_busy_flag(a1);
      return mmio_irq_clear((int)aNativeId3, (int)aPktMemFree, 204);
    }
    goto LABEL_11;
  }
  if ( v3 == 3 )
    return critical_section_enter(a1);
  if ( !*((volatile uint8_t *)a1 - 4) )
    return critical_section_enter_no_set(a1);
  return result;
}


// rf_channel_config @ 0x10ff58
int rf_channel_config() {
  void *v0; // r4
  int v1; // r3
  volatile uint32_t *v2; // r0
  int16_t v3; // r2
  int16_t v4; // r1
  uint64_t v5; // kr00_8
  struct __attribute__((packed)) { uint16_t v7[2]; // [sp+4h] [bp-14h] BYREF
  uint16_t v8[8]; // [sp+8h] [bp-10h] BYREF
  } _frame;
  v0 = (void *)(uintptr_t)(off_10FFD4);
  v1 = *(volatile uint32_t *)off_10FFD4;
  v2 = (void *)(uintptr_t)(off_10FFDC);
  v3 = *((volatile uint16_t *)off_10FFD8 + 153);
  v4 = *((volatile uint16_t *)off_10FFD8 + 154) - 4;
  _frame.v7[1] = *(volatile uint16_t *)(*(volatile uint32_t *)off_10FFD4 + 2);
  _frame.v8[1] = *(volatile uint16_t *)(v1 + 4);
  _frame.v8[5] = *(volatile uint16_t *)(v1 + 6);
  _frame.v8[7] = *(volatile uint16_t *)(v1 + 8);
  v5 = *(volatile uint64_t *)(v1 + 20);
  *(volatile uint32_t *)off_10FFDC = v5;
  v2[3] = dword_10FFE0;
  v2[1] = HIDWORD(v5);
  *((volatile uint8_t *)v2 + 8) = 1;
  _frame.v8[2] = v4;
  _frame.v8[6] = v3 - 4;
  _frame.v7[0] = 12;
  _frame.v8[4] = 1596;
  _frame.v8[0] = 124;
  _frame.v8[3] = 0;
  ke_msg_handler((void *)(v2), (int)_frame.v7, 0x20u);
  return timer_arm((int)_frame.v8, *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 28), *(volatile uint32_t *)(*(volatile uint32_t *)v0 + 32));
}



// rx_irq_handler @ 0x10ffe4
volatile uint32_t *rx_irq_handler() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_110038);
  result = zero_struct((volatile uint32_t *)dword_11002C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6) )
  {
    v2 = (void *)(uintptr_t)(off_110030);
    v3 = dword_110034;
    v4 = dword_11002C;
    v5 = 0;
    do
    {
      v6 = rx_process_item(v3, 0x63Cu);
      result = (volatile uint32_t *)check_abort_flag(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// tx_irq_handler @ 0x11003c
volatile uint32_t *tx_irq_handler() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_110070);
  result = zero_struct((volatile uint32_t *)dword_110074);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) )
  {
    v2 = dword_110078;
    v3 = dword_110074;
    v4 = 0;
    do
    {
      v5 = rx_process_item(v2, 0xCu);
      result = (volatile uint32_t *)check_abort_flag(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 2) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// adv_irq_handler @ 0x11007c
volatile uint32_t *adv_irq_handler() {
  void *v0; // r8
  volatile uint32_t *result; // r0
  volatile uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  volatile uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = (void *)(uintptr_t)(off_1100D0);
  result = zero_struct((volatile uint32_t *)dword_1100C4);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8) )
  {
    v2 = (void *)(uintptr_t)(off_1100C8);
    v3 = dword_1100CC;
    v4 = dword_1100C4;
    v5 = 0;
    do
    {
      v6 = rx_process_item(v3, 0x6B8u);
      result = (volatile uint32_t *)check_abort_flag(v4, v6);
      v7 = *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}


// scan_irq_handler @ 0x1100d4
volatile uint32_t *scan_irq_handler() {
  void *v0; // r5
  volatile uint32_t *result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4
  volatile uint32_t *v5; // r0

  v0 = (void *)(uintptr_t)(off_110108);
  result = zero_struct((volatile uint32_t *)dword_11010C);
  if ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) )
  {
    v2 = dword_110110;
    v3 = dword_11010C;
    v4 = 0;
    do
    {
      v5 = rx_process_item(v2, 0x7Cu);
      result = (volatile uint32_t *)check_abort_flag(v3, v5);
      ++v4;
    }
    while ( *(volatile uint16_t *)(*(volatile uint32_t *)v0 + 4) > (unsigned int)(uint16_t)v4 );
  }
  return result;
}


// critical_enter_0 @ 0x110114
int critical_enter_0() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110148 = 1;
  }
  v0 = (volatile int *)off_11014C;
  v1 = dword_110150;
  ++*(volatile uint32_t *)off_11014C;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_110148;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// critical_enter_1 @ 0x110154
int critical_enter_1(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11018C = 1;
  }
  v2 = (volatile int *)off_110190;
  v3 = dword_110194;
  ++*(volatile uint32_t *)off_110190;
  result = check_abort_flag(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_11018C;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// critical_enter_2 @ 0x110198
int critical_enter_2() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1101D8 = 1;
  }
  v0 = (volatile int *)off_1101DC;
  v1 = dword_1101E0;
  ++*(volatile uint32_t *)off_1101DC;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( result )
    --*(volatile uint32_t *)off_1101E4;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_1101D8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// critical_enter_3 @ 0x1101e8
int critical_enter_3(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110228 = 1;
  }
  v2 = (volatile int *)off_11022C;
  v3 = dword_110230;
  ++*(volatile uint32_t *)off_11022C;
  result = check_abort_flag(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_110234;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_110228;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// critical_enter_4 @ 0x110238
volatile uint32_t *critical_enter_4() {
  volatile int *v0; // r4
  int v1; // r0
  volatile uint32_t *result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110278 = 1;
  }
  v0 = (volatile int *)off_11027C;
  v1 = dword_110280;
  ++*(volatile uint32_t *)off_11027C;
  result = list_pop_front(v1);
  if ( result )
    --*(volatile uint32_t *)off_110284;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_110278;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}


// critical_enter_5 @ 0x110288
int critical_enter_5(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1102C8 = 1;
  }
  v2 = (volatile int *)off_1102CC;
  v3 = dword_1102D0;
  ++*(volatile uint32_t *)off_1102CC;
  result = check_abort_flag(v3, a1);
  v5 = *v2;
  ++*(volatile uint32_t *)off_1102D4;
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(volatile uint32_t *)off_1102C8;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}


// critical_enter_6 @ 0x1102d8
int critical_enter_6() {
  volatile int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_11030C = 1;
  }
  v0 = (volatile int *)off_110310;
  v1 = dword_110314;
  ++*(volatile uint32_t *)off_110310;
  result = (int)(uintptr_t)(list_pop_front(v1));
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(volatile uint32_t *)off_11030C;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}



// critical_enter_7 @ 0x110318
int critical_enter_7(volatile uint32_t *a1) {
  volatile int *v2; // r4
  int v3; // r0
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110350 = 1;
  }
  v2 = (volatile int *)off_110354;
  v3 = dword_110358;
  ++*(volatile uint32_t *)off_110354;
  result = check_abort_flag(v3, a1);
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(volatile uint32_t *)off_110350;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}


// usb_irq_handler @ 0x11035c
int usb_irq_handler(int result) {
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

  v1 = (void *)(uintptr_t)(off_110460);
  v2 = *(volatile uint16_t *)(result + 28);
  v3 = (volatile int *)off_110464;
  v4 = (void *)(uintptr_t)(off_11048C);
  v5 = (void *)(uintptr_t)(off_110490);
  v6 = result;
LABEL_2:
  v7 = (volatile int *)off_110468;
  while ( v2 <= 1 )
  {
    v8 = critical_enter_4();
    if ( !v8 )
    {
      result = printf_wrapper("rep: no rxmsg buffer, %d\r\n", *(volatile uint32_t *)off_110480);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return set_system_flag_1(32);
    }
    v9 = (void *)(uintptr_t)(critical_enter_0());
    v10 = v9;
    if ( !v9 )
    {
      printf_wrapper(aRepRxmsgNoDesc);
      result = critical_enter_5(v8);
      if ( *(volatile uint16_t *)(v6 + 28) > 1u )
        return result;
      return set_system_flag_1(32);
    }
    *v9 = (int)(uintptr_t)(v8);
    v9[1] = 0;
    v9[2] = 0;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_11046C = 1;
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
        printf_wrapper(aRxmsgTailError);
        v11 = *v7;
      }
    }
    else
    {
      if ( **(volatile int16_t **)off_110470 < 0 && *v4 )
      {
        mmio_irq_clear((int)aSdioFunc1H2dFr, (int)aSdioReplenishR, 261);
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
      v15 = *(volatile uint32_t *)off_11046C;
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


// rf_isr @ 0x110494
int rf_isr(int a1, int a2) {
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

  v2 = (void *)(uintptr_t)(off_1105B8);
  v3 = (volatile int *)off_1105BC;
  v21 = *(volatile uint16_t *)(*(volatile uint32_t *)off_1105B4 + 48);
  usb_irq_handler(a2);
  v6 = *(volatile uint16_t *)(a2 + 12);
LABEL_2:
  v7 = (void *)(uintptr_t)(off_1105E4);
  v8 = (void *)(uintptr_t)(off_1105E8);
  while ( v21 > v6 )
  {
    if ( *v7 <= 4u )
      goto LABEL_24;
    v9 = (*(int ( **)(uint32_t))(*(volatile uint32_t *)(a1 + 8) + 16))(*(volatile uint32_t *)(a1 + 4));
    if ( !v9 )
    {
      printf_wrapper("rep: no buffer, %d\r\n", *v7);
LABEL_23:
      if ( *(volatile uint16_t *)(a2 + 12) >= (unsigned int)*(volatile uint16_t *)(*(volatile uint32_t *)off_1105B4 + 50) )
        return 1;
LABEL_24:
      set_system_flag_1(32);
      return 1;
    }
    v10 = (void *)(uintptr_t)(critical_enter_0());
    v11 = v10;
    if ( !v10 )
    {
      printf_wrapper(aRepNoDesc);
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
      *(volatile uint32_t *)off_1105C0 = 1;
    }
    v13 = (volatile int *)off_1105C4;
    v14 = *(volatile uint32_t *)off_1105C4 + 1;
    *(volatile uint32_t *)off_1105C4 = v14;
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
      if ( **(volatile int16_t **)off_1105C8 < 0 && *(volatile uint32_t *)off_1105CC )
      {
        mmio_irq_clear((int)aSdioFunc1H2dFr_0, (int)aHostSdioReplen, 400);
        v13 = (volatile int *)off_1105C4;
        v14 = *(volatile uint32_t *)off_1105C4;
      }
      *(volatile uint32_t *)off_1105CC = (int)(uintptr_t)(v11);
    }
    v15 = *v3;
    v16 = *(volatile uint16_t *)(a2 + 12);
    *(volatile uint32_t *)(a2 + 4) = (int)(uintptr_t)(v11);
    v6 = (uint16_t)(v16 + 1);
    *(volatile uint16_t *)(a2 + 12) = v6;
    *v3 = (uint16_t)(v15 + 1);
    *(volatile uint32_t *)off_1105D0 = 1;
    if ( v14 )
    {
      v17 = (void *)(uintptr_t)(off_1105C0);
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


// init_after_reset @ 0x1105ec
int init_after_reset() {
  int v0; // r0

  v0 = rf_tx_start();
  setup_patch_data(v0);
  return 1;
}



// ke_event_init @ 0x1105fc
int ke_event_init(int a1) {
  volatile uint32_t *v1; // r2
  volatile uint32_t *v2; // r1

  v1 = (void *)(uintptr_t)(off_110630);
  v2 = (void *)(uintptr_t)(off_110634);
  *(volatile uint32_t *)off_110630 = 0;
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
  rf_isr((int)v1, (int)v2);
  return 1;
}



// sch_arbitrate @ 0x110abc
int sch_arbitrate() {
  volatile uint32_t *v0; // r8
  volatile int *v1; // r7
  volatile int *v2; // r10
  volatile char *v3; // r9
  int v4; // r3
  unsigned int v5; // r6
  int v6; // r11
  uint16_t v7; // r4
  int v8; // r5
  int v9; // r2
  int v10; // r0
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // [sp+4h] [bp-8h]

  v0 = (void *)(uintptr_t)(off_110BA0);
  v1 = (volatile int *)off_110B98;
  v2 = (volatile int *)off_110B9C;
  v3 = (volatile char *)off_110BA0 + 3080;
  while ( 1 )
  {
    v4 = v0[770];
    if ( !v4 )
      break;
    while ( 1 )
    {
      v5 = *(volatile uint16_t *)(v4 + 8);
      v6 = *(volatile uint32_t *)(v4 + 4);
      if ( *(volatile uint16_t *)(v4 + 8) )
      {
        v7 = 0;
        v8 = 0;
        v9 = 0;
        do
        {
          while ( 1 )
          {
            v10 = v6;
            ++v7;
            v6 = *(volatile uint32_t *)(v6 + 4);
            if ( v9 == v8 )
              break;
            ((int (*)())critical_enter_1)();
            v9 = v7;
            if ( v7 >= v5 )
              goto LABEL_8;
          }
          v17 = v10;
          tx_unlock();
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(v8 + (*(volatile uint8_t *)(v17 + 11) & 0x7F)) & 0xFFFFu);
          ((int (*)())critical_enter_1)();
          v9 = v7;
          v8 = (uint16_t)v8;
        }
        while ( v7 < v5 );
      }
LABEL_8:
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v2 = 1;
      }
      ++*v1;
      list_pop_front((int)(uintptr_t)(v3));
      v11 = *v1;
      --*((volatile uint8_t *)v0 + 3074);
      if ( !v11 )
        break;
      v12 = v11 - 1;
      v13 = *v2;
      *v1 = v12;
      if ( v12 || !v13 )
        break;
      __enable_irq();
      v4 = v0[770];
      if ( !v4 )
        goto LABEL_14;
    }
  }
LABEL_14:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110B9C = 1;
  }
  ++*v1;
  result = set_system_flag_2(128);
  if ( *v1 )
  {
    v15 = *v1 - 1;
    v16 = *(volatile uint32_t *)off_110B9C;
    *v1 = v15;
    if ( !v15 )
    {
      if ( v16 )
        __enable_irq();
    }
  }
  return result;
}



// rf_tx_start @ 0x110c80
int rf_tx_start() {
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
  void *v15; // r2
  volatile uint32_t *v16; // r1
  int result; // r0
  volatile uint32_t *v18; // r3
  volatile unsigned int *v19; // r2
  volatile unsigned int *v20; // r1

  v0 = (void *)(uintptr_t)(off_110E24);
  *(volatile uint32_t *)off_110E20 = 16;
  if ( (*v0 & 4) != 0 )
  {
    v19 = (volatile unsigned int *)off_110E54;
    v20 = (volatile unsigned int *)off_110E38;
    *(volatile uint32_t *)off_110E54 = *(volatile uint32_t *)off_110E54 & 0x8000FFFF | 0x4E200000;
    *v19 = *v19 & 0xFFFF8000 | 0x4E20;
    *v20 = *v20 & 0xFFFFF000 | 0x960;
    result = (int)send_cmd_040d();
  }
  else
  {
    ke_event_schedule_1(aWaitCmd5);
    do
    {
      while ( (*(volatile uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110E2C < 0 );
    v1 = (void *)(uintptr_t)(off_110E2C);
    *(volatile uint32_t *)off_110E2C = dword_110E30;
    while ( (*v1 & 0x20000000) != 0 )
      ;
    if ( (*v1 & 2) == 0 )
    {
      while ( (*(volatile uint32_t *)off_110E24 & 1) == 0 )
        ;
    }
    v2 = (volatile int *)off_110E34;
    v3 = (volatile unsigned int *)off_110E38;
    v4 = (volatile unsigned int *)off_110E3C;
    v5 = (void *)(uintptr_t)(off_110E40);
    v6 = (void *)(uintptr_t)(off_110E44);
    v7 = (void *)(uintptr_t)(off_110E48);
    *(volatile uint32_t *)off_110E24 = 2;
    v8 = dword_110E4C;
    *v2 = (HIWORD(*v2) << 16) | 0x7E0;
    *v3 = *v3 & 0xFFFFF000 | 0x50;
    *v4 = *v4 & 0xFFFFFF00 | 8;
    *v4 = *v4 & 0xFFFF00FF | 0xF00;
    v9 = (void *)(uintptr_t)(off_110E50);
    *v5 &= v8;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFF8) = 385;
    v3[136] = 385;
    v10 = (void *)(uintptr_t)(off_110E54);
    *v9 &= ~0x80000000;
    *v9 &= ~0x20u;
    v11 = (void *)(uintptr_t)(off_110E58);
    *v10 = *v10 & v8 | 0x4E200000;
    *v10 = *v10 & 0xFFFF8000 | 0x4E20;
    v3[3] = -1;
    *(volatile int *)((volatile char *)v2 + 0xFFFFFFD8) = -1;
    *v11 = 0x1FFFFFF;
    v12 = dword_110E5C;
    *v6 = 15;
    *v7 = 15;
    *(v10 - 75) = v12;
    ke_event_schedule_1(aWaitIoEnable);
    v13 = (volatile int *)off_110E2C;
    v14 = dword_110E30;
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
    v15 = (void *)(uintptr_t)(off_110E2C);
    do
    {
      while ( (*(volatile uint32_t *)off_110E2C & 0x20000000) != 0 )
        ;
    }
    while ( *(volatile int *)off_110E2C < 0 );
    v16 = (void *)(uintptr_t)(off_110E2C);
    *(volatile uint32_t *)off_110E2C = dword_110E64;
    while ( (*v16 & 0x20000000) != 0 )
      ;
    result = ke_event_schedule_1(aIoEnable, v16, v15, 4 * *v16);
    *(volatile uint32_t *)off_110E38 = *(volatile uint32_t *)off_110E38 & 0xFFFFF000 | 0x960;
  }
  v18 = (void *)(uintptr_t)(off_110E70);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_110E6C + 2) + 324) = off_110E74;
  v18[2] = 2;
  return result;
}


// ke_int_lock @ 0x110e78
int ke_int_lock(int a1, int a2, int a3) {
  volatile int *v6; // r9
  volatile uint8_t *v7; // r3
  int v8; // r5
  int result; // r0
  volatile uint32_t *v10; // r4
  volatile uint32_t *v11; // r3
  volatile uint32_t *v12; // r1
  int v13; // r5
  int v14; // r3
  volatile uint32_t *v15; // r2
  volatile uint8_t *v16; // r4
  volatile uint8_t *v17; // r5
  int v18; // r3
  volatile uint8_t *v19; // r10
  int v20; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_110F68 = 1;
  }
  v6 = (volatile int *)off_110F94;
  v7 = *(volatile uint8_t **)off_110F6C;
  v8 = *(volatile uint32_t *)off_110F94 + 1;
  *(volatile uint32_t *)off_110F94 = v8;
  result = *v7;
  if ( result == 1 )
  {
    v16 = (void *)(uintptr_t)(off_110F84);
    if ( *(volatile uint8_t *)off_110F84 )
    {
      v19 = (void *)(uintptr_t)(off_110F88);
      v20 = *((volatile uint8_t *)off_110F88 + 374);
      if ( v20 != 1 )
        goto LABEL_4;
      result = ke_event_pending((void *)(uintptr_t)(dword_110F8C));
      if ( result )
        goto LABEL_18;
      if ( v19[369] )
        gpio_clear_bit_reg0(v20);
      else
        gpio_set_bit_reg0(v20);
    }
    else
    {
      v17 = (volatile uint8_t *)off_110F88;
      if ( *((volatile uint8_t *)off_110F88 + 369) )
        result = gpio_clear_bit_reg0(1);
      else
        result = gpio_set_bit_reg0(1);
      v18 = v17[374];
      *v16 = 1;
      if ( v18 != 1 )
        goto LABEL_18;
    }
    result = ke_event_lock((void *)(uintptr_t)(dword_110F8C), *((volatile uint32_t *)off_110F90 + 4) + 10000);
LABEL_18:
    v8 = *v6;
  }
LABEL_4:
  v10 = (void *)(uintptr_t)(off_110F70);
  *(volatile uint32_t *)off_110F70 = 256;
  while ( (*v10 & 0x200) != 0 )
    ;
  if ( *(volatile uint32_t *)off_110F74 )
  {
    v11 = (void *)(uintptr_t)(off_110F78);
    v12 = (void *)(uintptr_t)(off_110F7C);
    *(volatile uint32_t *)(*((volatile uint32_t *)off_110F78 + 769) + 4) = a1;
    *v12 += a2;
  }
  else
  {
    v15 = (void *)(uintptr_t)(off_110F7C);
    *(volatile uint32_t *)off_110F74 = a1;
    v11 = (void *)(uintptr_t)(off_110F78);
    *v15 += a2;
  }
  *(volatile uint32_t *)off_110F80 = 256;
  v11[769] = a3;
  if ( v8 )
  {
    v13 = v8 - 1;
    v14 = *(volatile uint32_t *)off_110F68;
    *v6 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}



// rf_set_tx_channel @ 0x110f98
volatile uint32_t * rf_set_tx_channel(volatile uint32_t *result, int a2, int a3, uint16_t a4, int a5) {
  result[2] = dword_110FB4 & result[2] | a4 | (a5 << 31);
  *result = a2;
  result[1] = a3;
  return result;
}



// ke_mutex_lock @ 0x110fb8
int ke_mutex_lock(int a1) {
  volatile int *v2; // r5
  volatile uint8_t *v3; // r3
  int v4; // r1
  volatile uint32_t *v5; // r2
  int result; // r0
  volatile uint32_t *v7; // r2
  volatile uint32_t *v8; // r6
  int v9; // r1
  int v10; // r3
  volatile uint8_t *v11; // r6
  volatile uint8_t *v12; // r7
  int v13; // r3
  int v14; // r6

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_111098 = 1;
  }
  v2 = (volatile int *)off_11109C;
  v3 = *(volatile uint8_t **)off_1110A0;
  v4 = *(volatile uint32_t *)off_11109C + 1;
  *(volatile uint32_t *)off_11109C = v4;
  if ( *v3 == 1 )
  {
    v11 = (void *)(uintptr_t)(off_1110BC);
    v12 = (void *)(uintptr_t)(off_1110C0);
    if ( *(volatile uint8_t *)off_1110BC )
    {
      v14 = *((volatile uint8_t *)off_1110C0 + 374);
      if ( v14 != 1 )
        goto LABEL_4;
if ( ke_event_pending((void *)(uintptr_t)(dword_1110C4)) ) goto LABEL_18;
      if ( v12[369] )
        gpio_clear_bit_reg0(v14);
      else
        gpio_set_bit_reg0(v14);
    }
    else
    {
      if ( *((volatile uint8_t *)off_1110C0 + 369) )
        gpio_clear_bit_reg0(1);
      else
        gpio_set_bit_reg0(1);
      v13 = (uint8_t)v12[374];
      *v11 = 1;
      if ( v13 != 1 )
        goto LABEL_18;
    }
    ke_event_lock((void *)(uintptr_t)(dword_1110C4), *((volatile uint32_t *)off_1110C8 + 4) + 10000);
LABEL_18:
    v4 = *v2;
  }
LABEL_4:
  v5 = (void *)(uintptr_t)(off_1110A4);
  *(volatile uint32_t *)off_1110A4 = 64;
  while ( (*v5 & 0x80) != 0 )
    ;
  if ( *(volatile uint32_t *)off_1110A8 )
  {
    result = dword_1110AC;
    v7 = (void *)(uintptr_t)(off_1110B0);
    *(volatile uint32_t *)(*(volatile uint32_t *)(dword_1110AC + 6164) + 4) = a1;
  }
  else
  {
    v7 = (void *)(uintptr_t)(off_1110B0);
    *(volatile uint32_t *)off_1110A8 = a1;
    result = dword_1110AC;
  }
  ++*v7;
  v8 = (void *)(uintptr_t)(off_1110B8);
  *(volatile uint8_t *)off_1110B4 |= 2u;
  *v8 = 64;
  *(volatile uint32_t *)(result + 6164) = a1;
  if ( v4 )
  {
    v9 = v4 - 1;
    v10 = *(volatile uint32_t *)off_111098;
    *v2 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}



// ke_mem_alloc @ 0x1110cc
int ke_mem_alloc(char a1, volatile char *a2, unsigned int a3) {
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = set_user_id(4);
  if ( !v6 )
    return printf_wrapper(aErrNoMsgPkt);
  v7 = v6;
  v8 = (void *)(uintptr_t)(critical_enter_0());
  if ( v8 )
  {
    *(volatile uint8_t *)v7 = a3;
    *((volatile uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((volatile uint8_t *)v7 + 2) = a1;
    *((volatile uint8_t *)v7 + 3) = 0;
    memcpy((volatile char *)v7 + 4, a2, a3);
    v9 = v8[2];
    v10 = dword_111144;
    v8[1] = 0;
    *v8 = (int)(uintptr_t)(v7);
    v8[2] = (uint16_t)(a3 + 4) | v10 & v9 | 0x80000000;
    return ke_mutex_lock((int)v8);
  }
  else
  {
    printf_wrapper(aErrSendMsgCfgT);
    return memory_pool_free(v7);
  }
}


// ll_util_get_state @ 0x111150
int ll_util_get_state() {
  if ( *(volatile uint8_t *)off_111160 )
    return 1;
  else
    return *(volatile uint8_t *)off_111164;
}



// rf_set_tx_power_1 @ 0x111168
int rf_set_tx_power_1(int a1) {
  volatile int *v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r1

  v1 = (volatile int *)off_1111E4;
  v2 = a1 & 0x3FFFFF;
  v3 = *(volatile uint32_t *)off_1111E4 & 0x3FFFFF;
  if ( (a1 & 0x400000) != 0 )
  {
    *(volatile uint32_t *)off_1111E4 = v3 | 0x800000;
    *v1 = v3;
    *v1 = v2;
    v4 = v2 | 0x800000;
  }
  else
  {
    *(volatile uint32_t *)off_1111E4 = v3 | 0x400000;
    v4 = v2 | 0x400000;
  }
  *v1 = v4;
  *v1 = v2 | 0xC00000;
  return printf_wrapper("sdio pahse cfg %x\n", *(volatile uint32_t *)off_1111E4 & 0x3FFFFF);
}


