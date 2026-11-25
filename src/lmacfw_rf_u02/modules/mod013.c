// rx_scan_timing_update @ 0x11601c
int rx_scan_timing_update(int a1) {
  int v1; // r5
  int v2; // r6
  int v4; // r7
  int result; // r0
  int v6; // r10
  volatile uint8_t *v7; // r6
  volatile int *v8; // r11
  volatile int *v9; // r9
  int v10; // r2
  int v11; // r3

  v1 = dword_1160E0;
  v2 = *(volatile uint32_t *)(dword_1160DC + 4 * a1);
  v4 = dword_1160E0 + 8 * a1;
  if ( **(volatile int16_t **)off_1160D8 < 0 && (v2 & *(volatile uint32_t *)off_1160E8) == 0 )
    flash_ctrl_init(dword_1160F0, dword_1160EC, 612);
  result = enter_critical_section_1(v2);
  v6 = *(volatile uint32_t *)(v1 + 8 * a1);
  if ( v6 )
  {
    v7 = (void *)(uintptr_t)(off_1160E4);
    v8 = (volatile int *)off_1160F4;
    v9 = (volatile int *)off_1160F8;
    do
    {
      if ( v7[144] == 1 )
      {
        v7[144] = 0;
        set_busy_flag_alt(4096);
      }
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v9 = 1;
      }
      ++*v8;
      list_pop_front(v4);
      v10 = *v8 - 1;
      if ( *v8 )
      {
        v11 = *v9;
        *v8 = v10;
        if ( !v10 )
        {
          if ( v11 )
            __enable_irq();
        }
      }
      result = ((int (*)())ke_int_lock_mode)((uint8_t)a1, v6, v10);
      v6 = *(volatile uint32_t *)(v1 + 8 * a1);
    }
    while ( v6 );
  }
  return result;
}



// wlan_hw_init @ 0x1160fc
volatile uint32_t * wlan_hw_init(unsigned int a1, int a2) {
  volatile uint8_t **v2; // r11
  volatile uint32_t *v5; // r4
  volatile int *v6; // r5
  int v8; // r3
  int v9; // r2
  int v10; // r1
  volatile uint32_t *v11; // r8
  volatile uint32_t *v12; // r0
  int v13; // r12
  volatile uint32_t *v14; // r9
  volatile int16_t *v15; // lr
  unsigned int v16; // r1
  int v17; // r2
  volatile int *v18; // r3
  int v19; // r1
  int v20; // r3
  volatile uint8_t *v21; // r3
  volatile int *v22; // r8
  int v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r2
  struct __attribute__((packed)) { uint16_t v27; // [sp+4h] [bp-10h]
  char _pad1[2]; int v28; // [sp+8h] [bp-Ch] BYREF
  int v29; // [sp+Ch] [bp-8h]
  } _frame;
  v2 = (volatile uint8_t **)off_116318;
  while ( 1 )
  {
    v5 = list_pop_front(a2);
    if ( !v5 )
      break;
    while ( 1 )
    {
      v6 = (volatile int *)v5[8];
      if ( v5[6] )
      {
        *v6 = 2080374784;
      }
      else if ( *v6 >= 0 )
      {
        *v6 = 0x40000000;
      }
      if ( *((volatile uint16_t *)v5 + 2) )
        break;
      log_and_disable_irq(v5);
      v5 = list_pop_front(a2);
      if ( !v5 )
        return pool_alloc_init();
    }
    v8 = *v6;
    v9 = v5[10];
    *v6 |= 0x800000u;
    if ( v9 < 0 )
    {
      v10 = **v2;
      switch ( v10 )
      {
        case 2:
          v11 = (void *)(uintptr_t)(disable_interrupts());
          if ( v11 )
          {
            if ( *(volatile uint32_t *)off_1162F8 )
            {
              v12 = list_pop_front(off_1162F8);
              *(volatile uint8_t *)v11 = 8;
              *((volatile uint8_t *)v11 + 1) = 0;
              *((volatile uint16_t *)v11 + 1) = 18;
              v13 = v5[10] & 0x3FFFFFFF;
              v14 = v12;
              _frame.v28 = *v6 & 0xF;
              _frame.v29 = v13;
              memcpy((volatile char *)v11 + 4, (volatile char *)&_frame.v28, 8u);
              v15 = (volatile int16_t *)off_116320;
              v16 = *(volatile int16_t *)off_116320;
              if ( v16 > 0x186 )
              {
                v17 = 0;
                v16 = (v16 & ~0xFFFFu) | ((uint16_t)(0) & 0xFFFFu);
                _frame.v27 = 1;
              }
              else
              {
                _frame.v27 = v16 + 1;
                v17 = 8 * v16;
              }
              v18 = (volatile int *)off_1162FC;
              *((volatile uint16_t *)v14 + 6) = v16;
              v19 = *v18;
              v20 = dword_116300;
              *(volatile uint32_t *)(v19 + v17 + 4) = (int)(uintptr_t)(v11);
              *(volatile uint32_t *)(v19 + v17) = v20 & *(volatile uint32_t *)(v19 + v17) | 0x400000C;
              v21 = (void *)(uintptr_t)(off_116304);
              *v15 = _frame.v27;
              ++v21[3074];
              v14[1] = v19 + v17;
              *((volatile uint8_t *)v14 + 14) = 1;
              *v14 = 0;
              v14[2] = 12;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_116308 = 1;
              }
              v22 = (volatile int *)off_116324;
              v23 = *((volatile uint16_t *)v5 + 11);
              v24 = *v6 & 0xF;
              ++*(volatile uint32_t *)off_116324;
              dispatch_event_handler_1("cfms: %x, sn=%d, st=%d\r\n", v5, v23, v24);
              check_kernel_state(dword_11630C, v14);
              ((int (*)())process_event)();
              if ( *v22 )
              {
                v25 = *v22 - 1;
                v26 = *(volatile uint32_t *)off_116308;
                *v22 = v25;
                if ( !v25 )
                {
                  if ( v26 )
                    __enable_irq();
                }
              }
            }
            else
            {
              log_printf(aErrTxlCfmNoBuf);
            }
          }
          else
          {
            log_printf(aErrNoMsgPkt);
          }
          break;
        case 1:
          _frame.v28 = v8 & 0xF;
          _frame.v29 = v9 & 0x3FFFFFFF;
          ke_alloc_node(18, (volatile char *)&_frame.v28, 8u, _frame.v28);
          dispatch_event_handler_1("cfms: %x, sn=%d, st=%d\r\n", v5, *((volatile uint16_t *)v5 + 11), *v6 & 0xF);
          break;
        case 3:
          **(volatile uint32_t **)off_1162F4 = v8 & 0xF;
          enable_uart();
          break;
      }
    }
    deferred_cb_clear((int)v5);
    ke_int_lock_mode(a1, (int)v5);
  }
  return pool_alloc_init();
}


// wlan_clk_init @ 0x116328
int wlan_clk_init(int a1, int a2) {
  volatile int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v6; // r0
  int v7; // r1
  int v8; // r3
  volatile int *v9; // r2
  int v10; // r0

  v2 = (volatile int16_t **)off_116390;
  v3 = dword_116394;
  v4 = dword_116398;
LABEL_2:
  v6 = (int)(uintptr_t)(list_pop_front(a2));
  v7 = 2080374784;
  v8 = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v9 = *(volatile int **)(v8 + 32);
      if ( *(volatile uint32_t *)(v8 + 24) )
        goto LABEL_4;
      v7 = *v9;
      if ( *v9 >= 0 )
        break;
LABEL_5:
      if ( !*(volatile uint16_t *)(v8 + 4) )
      {
        ((int (*)())log_and_disable_irq)((void *)(uintptr_t)(v8), v7, *(volatile uint16_t *)(v8 + 4));
        goto LABEL_2;
      }
      if ( **v2 >= 0 )
        goto LABEL_2;
      flash_ctrl_init(v4, v3, 1147);
      v10 = (int)(uintptr_t)(list_pop_front(a2));
      v7 = 2080374784;
      v8 = v10;
      if ( !v10 )
        return (int)(uintptr_t)(pool_alloc_init());
    }
    v7 = 0x40000000;
LABEL_4:
    *v9 = v7;
    goto LABEL_5;
  }
  return (int)(uintptr_t)(pool_alloc_init());
}



// wlan_attach @ 0x11639c
int wlan_attach(int a1) {
  int v2; // r5
  volatile uint32_t *v3; // r4
  volatile uint32_t *v4; // r11
  int v5; // r7
  int v6; // r10
  int v7; // r9
  int v8; // r8
  volatile uint32_t *v9; // r6
  int v10; // r8
  int v11; // r0
  volatile int *v12; // r5
  int v13; // r7
  int result; // r0
  int v15; // r3
  int v16; // r2
  volatile uint32_t *v17; // r1
  int v18; // r0

  v2 = dword_11649C;
  v3 = (volatile uint32_t *)dword_1164A0;
  v4 = (volatile uint32_t *)dword_1164B8;
  v5 = dword_1164A4;
  v6 = dword_1164BC;
  v7 = dword_1164C0;
  v8 = dword_116498;
  list_init_1((volatile uint32_t *)dword_116498);
  list_init_1((volatile uint32_t *)(v8 + 8));
  do
  {
    if ( !a1 || !*(volatile uint8_t *)(v2 + 53) )
    {
      memset((volatile int *)v2, 0, 0x38u);
      v15 = 0;
      *(volatile uint32_t *)(v2 + 28) = (int)(uintptr_t)(v3);
      *(volatile uint32_t *)(v2 + 32) = (int)(uintptr_t)(v4);
      v4[12] = 0;
      v4[13] = 0;
      v3[24] = 0;
      v3[25] = 0;
      v16 = dword_1164B4;
      v4[6] = (int)(uintptr_t)(v3 + 26);
      v4[2] = v6;
      v3[11] = v7;
      *(volatile uint8_t *)(v2 + 52) = 0;
      v4[9] = 0;
      v4[14] = 0;
      v17 = v3 + 25;
      do
      {
        v18 = v16 | v15++;
        v17[1] = v18;
        ++v17;
        v16 -= 0x10000;
      }
      while ( v15 != 1024 );
      check_kernel_state(v8, (volatile uint32_t *)v2);
    }
    v3 += 1050;
    v2 += 56;
    v4 += 19;
  }
  while ( v3 != (volatile uint32_t *)v5 );
  v9 = (void *)(uintptr_t)(off_1164A8);
  v10 = dword_1164C0;
  *(volatile uint32_t *)off_1164A8 = dword_1164C0;
  v9[1] = chip_info_nibble1_get() << 14;
  v11 = clock_get_divider();
  v12 = (volatile int *)off_1164AC;
  v13 = dword_1164B0;
  v9[2] = v11;
  v9[5] = 1024;
  v9[6] = 0;
  v9[7] = 0;
  v9[10] = 0;
  v9[11] = 0;
  *v12 = v10;
  v9[3] = 0;
  v9[8] = 0;
  v9[12] = 0;
  v9[4] = v13;
  v12[1] = chip_info_nibble1_get() << 14;
  result = clock_get_divider();
  v12[2] = result;
  v12[3] = 0;
  v12[6] = 0;
  v12[7] = 0;
  v12[10] = 0;
  v12[11] = 0;
  v12[4] = v13;
  v12[8] = 0;
  v12[12] = 0;
  v12[5] = 4;
  return result;
}


