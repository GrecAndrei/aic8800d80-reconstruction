// rf_irq_handler_1 @ 0x110d00
int rf_irq_handler_1() {
  int v0; // r4
  volatile uint32_t *v1; // r0
  int v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint8_t *v4; // r6
  unsigned int v5; // r1
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r2
  volatile char *v9; // r3
  volatile uint32_t *v10; // r7
  volatile uint32_t *v11; // r0
  int v12; // r3
  volatile char *v13; // r1
  int v14; // r2
  volatile uint32_t *v15; // r0
  volatile uint8_t *v16; // r5
  unsigned int v17; // r1
  unsigned int v18; // r2
  int result; // r0
  volatile uint8_t *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r2
  volatile uint32_t *v23; // r3
  volatile uint16_t *v24; // r0
  unsigned int v25; // r2
  volatile uint32_t *v26; // r3
  unsigned int v27; // r3
  volatile uint32_t *v28; // r7
  volatile uint32_t *v29; // r1
  unsigned int v30; // r3
  volatile char *v31; // r2
  volatile uint32_t *v32; // r5
  int v33; // r6
  int v34; // r7
  unsigned int v35; // r3
  volatile char *v36; // r2
  int v37; // r5
  int v38; // r1
  int v39; // r1
  volatile uint32_t *v40; // r2
  int v41; // r5
  volatile uint8_t *v42; // r6
  volatile uint32_t *v43; // r2

  v0 = *(volatile uint32_t *)off_110F94;
  if ( **(volatile int16_t **)off_110F90 < 0 && !v0 )
  {
    flash_cmd_exec((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v40 = (volatile uint32_t *)off_11113C;
    v41 = *(volatile uint32_t *)off_111150;
    *(volatile uint32_t *)off_111150 = *(volatile uint32_t *)off_111150;
    *v40 &= ~0x20u;
    check_interrupt_flag(2, "int2dev:%d\n", v41);
    if ( (v41 & 4) != 0 )
    {
      *(volatile uint8_t *)off_11115C = 1;
      check_interrupt_flag(2, &aClrPreSleep[4]);
    }
    if ( (v41 & 1) != 0 )
    {
      v42 = (void *)(uintptr_t)(off_11115C);
      *(volatile uint32_t *)off_111158 = 16;
      if ( *v42 )
      {
        check_interrupt_flag(2, aClrPreSleep);
        *v42 = 0;
      }
      if ( *(volatile uint8_t *)off_111160 )
      {
        v43 = (void *)(uintptr_t)(off_111180);
        *((volatile uint8_t *)off_111160 + 1) = 1;
        *v43 |= 1u;
        check_interrupt_flag(2, aSoftwk);
      }
      *(volatile uint8_t *)off_111164 = 0;
    }
    if ( (v41 & 2) != 0 )
    {
      *(volatile uint8_t *)off_111164 = 1;
      check_interrupt_flag(2, aBit1);
    }
    if ( (v41 & 8) != 0 )
      dispatch_event_handler_1(aNotUsed);
  }
  if ( (v0 & 1) != 0 )
  {
    dispatch_event_handler_1(aSdioHostSoftRe, v0 << 31);
    *(volatile uint32_t *)off_110F9C = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    rf_reg_update(*(volatile uint32_t *)off_110FA0);
    *(volatile uint32_t *)off_110F9C = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = (void *)(uintptr_t)(off_110FA8);
    v2 = *(volatile uint32_t *)off_110FA4;
    v3 = (void *)(uintptr_t)(off_110FAC);
    *(volatile uint32_t *)off_110FA4 = *(volatile uint32_t *)off_110FA4;
    dispatch_event_handler_1("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v37 = *(volatile uint32_t *)off_111134;
  *(volatile uint32_t *)off_111134 = *(volatile uint32_t *)off_111134;
  dispatch_event_handler_1("sdio func1 other bit:%x\r\n", v37);
  if ( (v37 & 4) != 0 )
    *(volatile uint32_t *)off_11113C &= ~1u;
  if ( (v37 & 8) == 0 )
  {
LABEL_10:
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_50:
    v38 = *(volatile uint32_t *)off_111140;
    *(volatile uint32_t *)off_111140 = *(volatile uint32_t *)off_111140;
    dispatch_event_handler_1("sdio func2 error bit:%x\r\n", v38);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_51;
  }
  *(volatile uint32_t *)off_11113C &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_50;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_51:
  v39 = *(volatile uint32_t *)off_111148;
  *(volatile uint32_t *)off_111148 = *(volatile uint32_t *)off_111148;
  dispatch_event_handler_1("sdio func2 other bit:%x\r\n", v39);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v4 = (void *)(uintptr_t)(off_110FB4);
    v5 = *((volatile uint8_t *)off_110FB4 + 1621);
    v6 = *((volatile uint8_t *)off_110FB4 + 1622);
    if ( v5 >= v6 )
    {
      dispatch_event_handler_1("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(volatile uint32_t *)off_110FBC;
      v8 = *((volatile uint8_t *)off_110FB4 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_110FB8
                          * (uint64_t)((unsigned int)*((volatile uint8_t *)off_110FB4 + 1620) + 1)) >> 32) >> 6);
      v9 = (volatile char *)off_110FB4 + 20 * v8;
      v10 = (void *)(uintptr_t)(off_110FC4);
      *((volatile uint32_t *)v9 + 1) = *(volatile uint32_t *)off_110FC0;
      v4[1621] = v5 + 1;
      v11 = (void *)(uintptr_t)(off_110FC8);
      *((volatile uint32_t *)v9 + 2) = *v10;
      v9[12] = v7;
      v4[1620] = v8;
      v9[13] = BYTE1(v7) & 7;
      *v11 = 16;
      do
        v12 = *v11 & 0x20;
      while ( v12 );
      v13 = &v4[20 * v8];
      v14 = 5 * v8;
      if ( (v13[13] & 4) == 0 )
        v12 = *(volatile uint32_t *)(*((volatile uint32_t *)v13 + 2) + 4);
      v15 = (void *)(uintptr_t)(off_110FD0);
      *(volatile uint32_t *)off_110FCC = v12;
      *v15 = 16;
      check_kernel_state(dword_110FD4, (void *)(&v4[4 * v14]));
      set_busy_flag_alt(2048);
    }
    *(volatile uint32_t *)off_110F9C = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler_1(aUnexpectH2dCon);
    *(volatile uint32_t *)off_111170 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v16 = (void *)(uintptr_t)(off_110FB4);
    v17 = *((volatile uint8_t *)off_110FB4 + 2433);
    v18 = *((volatile uint8_t *)off_110FB4 + 2434);
    if ( v17 < v18 )
    {
      v33 = *(volatile uint32_t *)off_111014;
      v34 = *(volatile uint32_t *)off_11100C;
      v35 = *((volatile uint8_t *)off_110FB4 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_111010
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_110FB4 + 2432) + 1)) >> 32) >> 5);
      v36 = (volatile char *)off_110FB4 + 20 * v35;
      *((volatile uint8_t *)off_110FB4 + 2432) = v35;
      v36[1645] = BYTE1(v33) & 7;
      *((volatile uint32_t *)v36 + 409) = v34;
      *((volatile uint32_t *)v36 + 410) = v34;
      v36[1644] = v33;
      v16[2433] = v17 + 1;
      check_kernel_state((int)(v16 + 2436), (volatile uint32_t *)v36 + 408);
      set_busy_flag_alt(0x1000000);
    }
    else
    {
      dispatch_event_handler_1("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(volatile uint32_t *)off_110F9C = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    v20 = (void *)(uintptr_t)(off_110FDC);
    v21 = *((volatile uint8_t *)off_110FDC + 3074);
    v22 = *((volatile uint8_t *)off_110FDC + 3073);
    if ( v21 < v22 )
    {
      v30 = *((volatile uint8_t *)off_110FDC + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_110FDC + 3072) + 1)) >> 32) >> 7);
      v31 = (volatile char *)off_110FDC + 16 * v30;
      *((volatile uint32_t *)v31 + 1) = *(volatile uint32_t *)off_111004;
      v32 = (void *)(uintptr_t)(off_111008);
      v20[3072] = v30;
      *((volatile uint16_t *)v31 + 4) = *v32;
      v20[3074] = v21 + 1;
      check_kernel_state((int)(v20 + 3080), (void *)(v31));
      result = set_busy_flag_alt(1024);
    }
    else
    {
      result = dispatch_event_handler_1("txcused=%d, total=%d\r\n", v21, v22);
    }
    v23 = (void *)(uintptr_t)(off_110FE4);
    *(volatile uint32_t *)off_110F9C = 4096;
    if ( !*v23 )
      *(volatile uint8_t *)off_110FE8 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    v24 = (void *)(uintptr_t)(off_110FDC);
    v25 = *((volatile uint8_t *)off_110FDC + 6162);
    if ( *((volatile uint8_t *)off_110FDC + 6161) > v25 )
    {
      v27 = *((volatile uint8_t *)off_110FDC + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (uint64_t)((unsigned int)*((volatile uint8_t *)off_110FDC + 6160) + 1)) >> 32) >> 7);
      v28 = (void *)(uintptr_t)(off_110FF8);
      *((volatile uint8_t *)off_110FDC + 6160) = v27;
      v29 = (void *)(&v24[8 * v27 + 1544]);
      v29[1] = *v28;
      v24[8 * v27 + 1548] = *(volatile uint32_t *)off_110FFC;
      *((volatile uint8_t *)v24 + 6162) = v25 + 1;
      check_kernel_state(dword_111000, v29);
      result = set_busy_flag_alt(512);
    }
    else
    {
      result = dispatch_event_handler_1("txcmsgused=%d, msgtotal=%d\r\n", v25, v25);
    }
    v26 = (void *)(uintptr_t)(off_110FF0);
    *(volatile uint32_t *)off_110F9C = 2048;
    if ( !*v26 )
      *(volatile uint8_t *)off_110FE8 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(volatile uint32_t *)off_110F9C = 4;
  if ( (v0 & 8) != 0 )
    *(volatile uint32_t *)off_110F9C = 8;
  return result;
}


// timer_set_alarm @ 0x11118c
int timer_set_alarm() {
  int v0; // r3
  volatile int *v1; // r2
  volatile uint32_t *v2; // r1
  int result; // r0
  int v4; // r3
  int v5; // r1
  volatile char *v6; // r3
  volatile uint32_t *v7; // r4
  int v8; // r6
  uint64_t v9; // kr00_8
  uint64_t v10; // kr08_8

  v0 = *(volatile uint32_t *)off_111204;
  v1 = (volatile int *)off_111208;
  v2 = (void *)(uintptr_t)(off_11120C);
  *(volatile uint32_t *)(v0 + 4) = *(volatile uint32_t *)off_111200;
  result = *v1;
  v2[709] = v0;
  v4 = *(volatile uint32_t *)off_111210;
  *(volatile uint8_t *)(result + 3) |= 0xC0u;
  v5 = v4 + 3200;
  do
  {
    *(volatile uint8_t *)(v4 + 3) |= 0xC0u;
    v4 += 8;
  }
  while ( v4 != v5 );
  v6 = (volatile char *)off_111214;
  v7 = (void *)(uintptr_t)(off_11120C);
  v8 = *((volatile uint32_t *)off_111214 + 2);
  v9 = *(volatile uint64_t *)off_111214;
  *(volatile uint8_t *)(*(volatile uint32_t *)off_111214 + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v9) + 3) |= 0xC0u;
  v10 = *(volatile uint64_t *)(v6 + 12);
  *(volatile uint8_t *)(v8 + 3) |= 0xC0u;
  *(volatile uint8_t *)(v10 + 3) |= 0xC0u;
  *(volatile uint8_t *)(HIDWORD(v10) + 3) |= 0xC0u;
  v7[581] = result;
  return result;
}



// timer_read_count @ 0x111218
int timer_read_count() {
  volatile uint32_t *v0; // r1
  int v1; // r0
  volatile uint32_t *v2; // r3
  int result; // r0

  v0 = *(volatile uint32_t **)off_111264;
  v1 = *(volatile uint32_t *)off_111268;
  v2 = (void *)(uintptr_t)(off_11126C);
  *((volatile uint16_t *)off_111270 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = (int)(uintptr_t)(v0);
  v2[576] |= 0x84000000;
  return result;
}


// timer_entry_clear @ 0x111274
volatile int * timer_entry_clear(int a1) {
  int v2; // r0
  int v3; // r5
  volatile int *result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_1112A4 + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 8);
  result = memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    result = (volatile int *)dword_1112A8;
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1112A8 + 4 * a1 + 32);
    if ( v5 )
      return (volatile int *)v5(0, 0, 1);
  }
  return result;
}



// timer_entry_reset @ 0x1112ac
int timer_entry_reset(int a1) {
  int v2; // r0
  int v3; // r5
  int result; // r0
  int ( *v5)(uint32_t, uint32_t, int); // r3

  v2 = dword_1112DC + 16 * (a1 - 1);
  v3 = *(volatile uint8_t *)(v2 + 11);
  result = (int)memset((volatile int *)v2, 0, 0x10u);
  if ( v3 )
  {
    v5 = *(int ( **)(uint32_t, uint32_t, int))(dword_1112E0 + 4 * (a1 + 13));
    if ( v5 )
      return v5(0, 0, 1);
  }
  return result;
}


// timer_init @ 0x1112e4
volatile int *timer_init() {
  int i; // r4
  int v1; // r0
  volatile int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    timer_entry_clear(v1);
    result = (void *)(uintptr_t)(timer_entry_reset(v3));
  }
  return result;
}



// timer_start @ 0x111304
int timer_start() {
  int v0; // r2
  int v1; // r2
  int v2; // r1
  volatile uint32_t *v3; // r2
  volatile uint32_t *v4; // r1
  int v5; // r3
  volatile uint32_t *v6; // r2

  v0 = off_1113F8;
  *(volatile uint32_t *)(off_1113F8 + 0x10) |= 1u;
  while ( (*(volatile uint32_t *)(v0 + 0x10) & 1) != 0 )
    ;
  v1 = off_1113F8;
  while ( *(volatile int *)(off_1113F8 + 0x10) >= 0 )
    ;
  v2 = off_1113F8;
  *(volatile uint32_t *)(off_1113F8 + 0xC) |= 0x40000007u;
  *(volatile uint32_t *)(v1 + 0xC) = *(volatile uint32_t *)(v1 + 0xC) & 0xFFFFC0FF | 0x2700;
  *(volatile uint32_t *)(v1 + 0x10) |= 1u;
  while ( (*(volatile uint32_t *)(v2 + 0x10) & 1) != 0 )
    ;
  v3 = (volatile uint32_t *)off_1113F8;
  while ( *(volatile int *)(off_1113F8 + 0x10) >= 0 )
    ;
  v4 = (volatile uint32_t *)off_1113F8;
  *(volatile uint32_t *)(off_1113F8 + 0xC) |= 0x40000007u;
  v3[3] = v3[3] & 0xFFFFC0FF | 0x2700;
  v3[512] &= 0xFFFFE7FC;
  v3[512] |= 0x800004u;
  v3[6] = 0;
  v5 = 1;
  v3[5] = -1;
  v3[519] = 0;
  v3[517] = 0;
  v3[516] = 0;
  while ( 1 )
  {
    v6 = &v4[8 * v5 - 16];
    if ( v5 != 1 )
      break;
    v4[706] = -1;
    v4[578] = -1;
LABEL_11:
    ++v5;
  }
  v6[714] = -1;
  v6[586] = -1;
  if ( v5 != 6 )
    goto LABEL_11;
  v4[6] = dword_1113FC;
  v4[513] &= ~2u;
  v4[513] |= 0x8000u;
  v4[2] = 46;
  v4[2] |= 1u;
  return dispatch_event_handler_1(aUsbInitDone);
}


// rf_set_param @ 0x111404
int rf_set_param(int result, int a2) {
  volatile int *v2; // r4
  int v3; // r5
  int v4; // r3
  char v5; // r2
  volatile uint32_t *v6; // r2

  v2 = (volatile int *)off_111460;
  v3 = *(volatile uint32_t *)off_11145C;
  v4 = *(volatile uint32_t *)off_111460;
  *((volatile uint16_t *)off_111464 + 5) = a2;
  if ( a2 == 64 )
    v5 = -54;
  else
    v5 = -50;
  *(volatile uint32_t *)v4 = -1073741824;
  *(volatile uint32_t *)(v4 + 4) = v3;
  *(volatile uint8_t *)(v4 + 3) = v5;
  *(volatile uint16_t *)v4 = a2;
  if ( result && a2 )
  {
    result = (int)(uintptr_t)(memcpy((void *)(uintptr_t)(v3), (void *)(uintptr_t)(result), a2));
    v4 = *v2;
  }
  v6 = (void *)(uintptr_t)(off_111468);
  *(volatile uint8_t *)(v4 + 3) &= 0x3Fu;
  v6[578] = v6[578];
  v6[581] = v4;
  v6[576] |= 0x84000000;
  return result;
}



// rf_channel_set_flag @ 0x11146c
/* luna: Sets or clears bits in the selected RF channel flag word, performs the RF hardware update handshake, and clears the associated timer entry. */
volatile int * rf_channel_set_flag(int a1, int a2, int a3) {
  volatile uint32_t *chan_ctrl; // r6
  volatile int *chan_flags; // r5
  int old_flags; // r7
  volatile uint32_t *rf_mmio; // r4

  if ( a1 )
  {
    chan_ctrl = (volatile uint32_t *)(dword_111510 + 32 * (a1 - 1) + 8);
    chan_flags = (volatile int *)(dword_111510 + 32 * (a1 - 1));
  }
  else
  {
    chan_ctrl = (volatile uint32_t *)dword_11151C;
    chan_flags = (volatile int *)dword_111520;
  }
  old_flags = *chan_flags;
  if ( (*chan_flags & 0x80008000) != 0 && ((dword_111514 & old_flags) != 0x20000 || a2 != 0x8000000 || a3) )
  {
    rf_mmio = (void *)(uintptr_t)(off_111518);
    *((volatile uint32_t *)off_111518 + 513) |= 0x200u;
    while ( (rf_mmio[5] & 0x80) == 0 )
      ;
    *chan_flags |= a2 | 0x8008000;
    if ( a3 )
      *chan_flags &= ~a3;
    if ( !a1 )
      goto LABEL_10;
    if ( old_flags < 0 )
    {
      *chan_ctrl = 2;
      *chan_flags |= 0x40000000u;
      while ( (*chan_ctrl & 2) == 0 )
        ;
      if ( (old_flags & 0x8000) != 0 )
        goto LABEL_10;
    }
    else if ( (old_flags & 0x8000) != 0 )
    {
LABEL_10:
      *((volatile uint32_t *)off_111518 + 513) |= 0x400u;
      return timer_entry_clear(a1);
    }
    *chan_flags &= ~0x8000u;
    goto LABEL_10;
  }
  return timer_entry_clear(a1);
}



// rf_channel_get_flag @ 0x111524
int rf_channel_get_flag(int result, int a2, int a3) {
  int v3; // r6
  volatile uint32_t *v4; // r4
  int v5; // r5
  volatile uint32_t *v6; // r3
  volatile uint32_t *v7; // r2

  if ( result )
  {
    v3 = 32 * (result - 1);
    v4 = (volatile uint32_t *)(dword_111604 + v3);
    v5 = *(volatile uint32_t *)(v3 + dword_111604);
    if ( (v5 & 0x80008000) == 0 )
      return timer_entry_reset(result);
    v6 = (volatile uint32_t *)(dword_111604 + v3 + 8);
    if ( (dword_111608 & v5) == 0x20000 )
      goto LABEL_4;
    goto LABEL_15;
  }
  v4 = (void *)(uintptr_t)(off_111610);
  v5 = *(volatile uint32_t *)off_111610;
  if ( (*(volatile uint32_t *)off_111610 & 0x80008000) != 0 )
  {
    v6 = (volatile uint32_t *)dword_111614;
    if ( (dword_111608 & v5) == 0x20000 )
    {
LABEL_4:
      if ( a2 == 0x8000000 )
      {
        if ( !a3 )
          goto LABEL_11;
        *v6 = 64;
        *v4 |= 0x8008000u;
LABEL_27:
        *v4 &= ~a3;
LABEL_7:
        v7 = (void *)(uintptr_t)(off_11160C);
        *((volatile uint32_t *)off_11160C + 4) = (result << 6) | 0x20;
        while ( (v7[4] & 0x20) != 0 )
          ;
        if ( (v5 & 0x8000) == 0 )
          *v4 &= ~0x8000u;
LABEL_11:
        if ( !result )
          return result;
        return timer_entry_reset(result);
      }
      *v6 = 64;
      *v4 |= a2 | 0x8008000;
LABEL_6:
      if ( !a3 )
        goto LABEL_7;
      goto LABEL_27;
    }
LABEL_15:
    *v6 = 64;
    *v4 |= a2 | 0x8008000;
    if ( v5 < 0 )
    {
      if ( (v5 & 0x20000) == 0 )
      {
        while ( (*v6 & 0x40) == 0 )
          ;
        *v6 = 64;
      }
      if ( a3 )
        *v4 &= ~a3;
      *v6 = 2;
      *v4 |= 0x40000000u;
      while ( (*v6 & 2) == 0 )
        ;
      goto LABEL_7;
    }
    goto LABEL_6;
  }
  return result;
}


// rf_select_base @ 0x111618
int rf_select_base(int a1, int a2) {
  volatile uint32_t *v2; // r0
  int v4; // r0

  if ( a2 )
  {
    if ( a1 == 1 )
      v4 = dword_111644;
    else
      v4 = dword_111648;
    return (*(volatile uint32_t *)(v4 + 32 * a2) >> 21) & 1;
  }
  else
  {
    if ( a1 == 1 )
      v2 = (volatile uint32_t *)dword_111644;
    else
      v2 = (volatile uint32_t *)dword_111648;
    return (*v2 >> 21) & 1;
  }
}


// rf_enable_tx_patch @ 0x11164c
volatile int * rf_enable_tx_patch(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)rf_channel_get_flag(a2, 0x8000000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_channel_set_flag(a2, 0x8000000, 0);
  }
  return result;
}



// rf_enable_rx_patch @ 0x111670
volatile int * rf_enable_rx_patch(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)rf_channel_get_flag(a2, 0x200000, 0);
  }
  else if ( a2 <= 5 )
  {
    return rf_channel_set_flag(a2, 0x200000, 0);
  }
  return result;
}



// rf_enable_txrx_patch @ 0x111694
volatile int * rf_enable_txrx_patch(volatile int *result, unsigned int a2) {
  if ( result )
  {
    if ( a2 <= 5 )
      return (volatile int *)rf_channel_get_flag(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return rf_channel_set_flag(a2, 0x8000000, 0x200000);
  }
  return result;
}



// rf_enable_tx_patch_wrapper @ 0x1116bc
volatile int * rf_enable_tx_patch_wrapper(volatile int *result, unsigned int a2) {
  return rf_enable_tx_patch(result, a2);
}



// ke_send_event @ 0x1116c0
int ke_send_event(int a1, int a2) {
  volatile uint8_t *v4; // r6
  int v5; // r7
  volatile char *v6; // r0
  int v7; // r1
  volatile uint32_t *v8; // r4
  volatile uint32_t *v9; // r3
  volatile uint8_t *v11; // r7
  int v12; // r0
  int v13; // r1
  volatile uint32_t *v14; // r3
  void ( *v15)(int); // r2

  dispatch_event_handler_1("open:%d/%d\n", 0, a2);
  if ( !a1 )
    return 1;
  if ( !*(volatile uint32_t *)a1 || !*(volatile uint32_t *)(a1 + 4) || !*(volatile uint32_t *)(a1 + 8) || !*(volatile uint32_t *)(a1 + 20) )
    return 2;
  v4 = (void *)(uintptr_t)(off_1117CC);
  if ( *(volatile uint8_t *)off_1117CC )
    return 3;
  v5 = off_1117D0;
  v6 = (volatile char *)off_1117D4;
  *(volatile uint8_t *)off_1117CC = 1;
  memcpy(v6, (volatile char *)a1, 0x50u);
  v7 = *(volatile uint32_t *)(v5 + 0x184);
  if ( v7 )
  {
    dispatch_event_handler_1("usb sftdiscon delay %d\n", v7);
    write_timer_reg(*(volatile uint32_t *)(v5 + 0x184));
  }
  v8 = (void *)(uintptr_t)(off_1117D8);
  if ( (*((volatile uint32_t *)off_1117D8 + 512) & 0x7F0) != 0 )
  {
    v11 = (void *)(uintptr_t)(off_1117F0);
    *((volatile uint32_t *)off_1117F0 + 1) = 0;
    *((volatile uint32_t *)v11 + 2) = 0;
    *v11 = 0;
    *v4 = 4;
    v12 = timer_set_alarm();
    v13 = *(volatile uint32_t *)off_1117F4;
    v14 = *(volatile uint32_t **)off_1117F8;
    *v14 = dword_1117FC;
    v14[1] = v13;
    v8[709] = (int)(uintptr_t)(v14);
    v8[706] = v8[706];
    v15 = *(void ( **)(int))&((volatile uint32_t *)(uintptr_t)off_1117D4)[76];
    v8[704] |= 0x84000000;
    *v11 = 1;
    if ( v15 )
      v15(v12);
  }
  else
  {
    if ( (*((volatile uint32_t *)off_1117D8 + 2) & 1) != 0 )
    {
      *((volatile uint32_t *)off_1117D8 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    timer_start();
  }
  dispatch_event_handler_1(aEnableIrq);
  v9 = (void *)(uintptr_t)(off_1117E8);
  *(volatile uint32_t *)(*((volatile uint32_t *)off_1117E0 + 2) + 320) = off_1117E4;
  v9[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  dispatch_event_handler_1(aOpenDone);
  return 0;
}


// util_process_cmd @ 0x111804
int util_process_cmd(int result, int a2, int a3, unsigned int a4) {
  int v4; // r6
  unsigned int v7; // r11
  int v8; // r7
  int v9; // r10
  int v10; // r9
  int v11; // r2
  volatile uint16_t *v12; // r4
  int v13; // r1
  volatile uint32_t *v14; // r2
  int v15; // r5
  int v16; // r6
  volatile uint32_t *v17; // r2
  unsigned int v18; // r3
  int v19; // cf

  v4 = a2 - 1;
  if ( (uint8_t)(a2 - 1) <= 4u )
  {
    v7 = a4;
    if ( result )
    {
      if ( (a3 & 0xFD) == 1 )
      {
        if ( a4 > 0x320 )
        {
          v9 = 400;
          v8 = (v8 & ~0xFFFFu) | ((uint16_t)(400) & 0xFFFFu);
          v10 = 26214400;
        }
        else
        {
          v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
          v9 = v8;
          v10 = (uint16_t)v8 << 16;
        }
        if ( a4 > 0x400 )
        {
          v18 = -1025;
          v19 = v7 - 1025 >= 0x400;
          if ( v7 - 1025 < 0x400 )
            v7 >>= 1;
          else
            v18 = ((unsigned int)dword_111948 * (uint64_t)v7) >> 32;
          if ( v19 )
            v7 = (v7 & ~0xFFFFu) | ((uint16_t)(v18 >> 1) & 0xFFFFu);
        }
      }
      else
      {
        v8 = (uint16_t)(2 * ((int)(a4 + 3) >> 2));
        v9 = v8;
        v10 = (uint16_t)v8 << 16;
      }
      if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(rf_enable_tx_patch((void *)(uintptr_t)(result), a2));
      v11 = (a3 << 18) & 0xC0000;
      v12 = (void *)(uintptr_t)(off_111940);
      v13 = *(volatile uint16_t *)off_111940;
      *((volatile uint32_t *)&REG_4020_0900 + 8 * a2) = v7 & 0x7FF | v11 | (a2 << 22) | 0x18008000;
      if ( v13 + v9 > 2048 )
      {
        result = log_printf("FIFO ERROR: overflow, addr is %d, size is %d, Total RAM is %d", v13, v9, 2048);
        v13 = (uint16_t)*v12;
      }
      v14 = (void *)(uintptr_t)(off_111944);
      *((volatile uint32_t *)off_111944 + v4 + 65) = v13 | v10;
      v15 = (1 << a2) | v14[519];
      *v12 = v8 + v13;
      v14[519] = v15;
    }
    else
    {
      v16 = 32 * a2 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a2) & 0x80008000) != 0 )
        result = (int)(uintptr_t)(rf_enable_tx_patch(0, a2));
      v17 = (void *)(uintptr_t)(off_111944);
      *(volatile uint32_t *)(v16 + 2816) = v7 & 0x7FF | (a3 << 18) & 0xC0000 | 0x18008000;
      v17[519] |= 0x10000 << a2;
    }
  }
  return result;
}


// rf_channel_update @ 0x111950
int rf_channel_update(int a1, int a2, unsigned int a3) {
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(volatile uint8_t *)off_1119F0 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    log_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    v4 = dword_1119F4 + 16 * v3;
    if ( *(volatile uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_1119F8;
        *(volatile uint32_t *)(dword_1119F4 + 16 * v3) = a2;
        v7 = *(volatile uint32_t *)(v6 + 4 * v3);
        v8 = dword_1119FC;
        *(volatile uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(volatile uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(volatile uint32_t *)(v4 + 4) = a3;
        *(volatile uint16_t *)v7 = a3;
        *(volatile uint32_t *)(v7 + 4) = a2;
        *(volatile uint8_t *)(v7 + 3) = v10 | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = v7;
        *(volatile uint32_t *)(v5 + 2816) |= 0x84000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// rf_read_status @ 0x111a04
int rf_read_status(int a1) {
  int result; // r0
  int v2; // r3

  result = 32 * a1 + 1075838976;
  v2 = *(volatile uint32_t *)(result + 2816);
  if ( v2 < 0 )
    *(volatile uint32_t *)(result + 2816) = v2 & 0x7BFFFFFF | 0x4000000;
  return result;
}



// rf_channel_update_dup @ 0x111a24
int rf_channel_update_dup(int a1, int a2, unsigned int a3) {
  int v3; // r4
  int v4; // r12
  int v5; // r3
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r7
  int v9; // r4
  char v10; // r6

  if ( *(volatile uint8_t *)off_111AC8 != 4 )
    return 1;
  v3 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( a2 << 30 )
  {
    log_printf(aErrAlignmentEr);
    return 3;
  }
  else
  {
    v4 = dword_111ACC + 16 * v3;
    if ( *(volatile uint32_t *)v4 )
    {
      return 4;
    }
    else
    {
      v5 = 32 * a1 + 1075838976;
      if ( (*((volatile uint32_t *)&REG_4020_0b00 + 8 * a1) & 0x8000) != 0 )
      {
        v6 = dword_111AD0;
        *(volatile uint32_t *)(dword_111ACC + 16 * v3) = a2;
        v7 = *(volatile uint32_t *)(v6 + 4 * v3);
        v8 = dword_111AD4;
        *(volatile uint8_t *)(v4 + 8) = 1;
        v9 = 32 * v3 + 1075838976;
        v10 = *(volatile uint8_t *)(v7 + 3) & 0x31;
        if ( a3 >= v8 )
          a3 = v8;
        *(volatile uint32_t *)(v4 + 4) = a3;
        *(volatile uint16_t *)v7 = a3;
        *(volatile uint32_t *)(v7 + 4) = a2;
        *(volatile uint8_t *)(v7 + 3) = v10 | 0xE;
        *(volatile uint32_t *)(v9 + 2868) = v7;
        *(volatile uint32_t *)(v5 + 2816) = *(volatile uint32_t *)(v5 + 2816) & 0x7BFFFFFF | 0x80000000;
        return 0;
      }
      else
      {
        return 5;
      }
    }
  }
}


// ke_timeout_tick @ 0x111adc
int ke_timeout_tick() {
  volatile uint8_t *v0; // r4
  int v1; // r0
  int ( *v3)(uint32_t); // r3

  v0 = (void *)(uintptr_t)(off_111B20);
  v1 = *((volatile uint16_t *)off_111B20 + 7);
  *(volatile uint16_t *)off_111B24 = v1;
  if ( v1 )
  {
    v3 = *((int ( **)(uint32_t))off_111B2C + 5);
    if ( v3 && v3((uint8_t)v1) )
    {
      *(volatile uint8_t *)off_111B28 = 4;
      *v0 = 7;
      if ( !is_radio_powered() )
        prepare_and_dispatch(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(volatile uint8_t *)off_111B28 = 3;
    return 1;
  }
}



// util_check_flags @ 0x111b30
int util_check_flags(uint64_t a1, volatile uint32_t *a2) {
  int v2; // r4
  volatile uint8_t *v3; // r5
  void *v4; // r6
  volatile uint8_t *v5; // r3
  uint8_t v6; // r2
  int v7; // r3
  volatile uint32_t *v8; // r3
  volatile char *v9; // r4
  int ( *v10)(void *); // r1
  volatile uint8_t *v11; // r8
  char v12; // r2
  int v13; // r7
  int v14; // r0
  int v15; // r3
  int v16; // r3
  volatile uint32_t *v17; // r2
  int v18; // r3
  volatile uint32_t *v19; // r3
  volatile uint32_t *v20; // r3
  int v21; // r1
  volatile uint32_t *v22; // r2
  volatile uint32_t *v23; // r3
  int v24; // r3
  volatile uint32_t *v25; // r2
  volatile uint32_t *v26; // r3
  volatile uint32_t *v27; // r2
  int v28; // r0
  volatile uint32_t *v29; // r3
  int v30; // r3
  void *v31; // r3
  unsigned int v32; // r0
  unsigned int v33; // r1
  int v34; // r1
  int ( *v35)(uint32_t, uint32_t); // r3
  volatile uint8_t *v36; // r3
  volatile uint16_t *v37; // r3
  void *v38; // r2
  int v39; // r4
  unsigned int v40; // r1
  volatile uint8_t *v41; // r0
  int v42; // r3
  unsigned int v43; // r3
  volatile uint8_t *v44; // r0
  volatile uint8_t *v45; // r0
  uint16_t v46; // r2
  uint16_t v47; // r3
  char v48; // r3
  char v49; // r3
  volatile uint32_t *v50; // r4
  int v51; // r0
  volatile int *v52; // r8
  int v53; // r7
  int v54; // r3
  int v55; // r7
  volatile uint32_t *v56; // r2
  volatile uint32_t *v57; // r3
  uint16_t v58; // r2
  int v59; // r6
  unsigned int v60; // r2
  unsigned int v61; // r1
  volatile uint32_t *v62; // r2
  void ( *v63)(volatile uint8_t *); // r3
  volatile uint32_t *v64; // r2
  int v65; // r0
  volatile uint32_t *v66; // r3
  unsigned int v67; // r0
  int v68; // r0

  v2 = HIDWORD(a1);
  if ( (uint32_t)a1 )
  {
    v3 = (volatile uint8_t *)off_111E3C;
    v15 = *(volatile uint8_t *)off_111E3C;
    if ( v15 == 2 )
    {
      v4 = (void *)(uintptr_t)(off_111E40);
      log_printf(aEp0SetupErrorD, HIDWORD(a1), a2);
      goto LABEL_7;
    }
    if ( (a1 & 0x100000000LL) == 0 )
      goto LABEL_18;
    if ( v15 == 4 )
    {
      a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint16_t *)off_111E3C + 4)) << 32);
      v58 = *((volatile uint16_t *)off_111E3C + 5);
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)((uint16_t)(WORD2(a1) - v58)) & 0xFFFFFFFFu);
      if ( WORD2(a1) == v58 )
      {
        *(volatile uint8_t *)off_111E3C = 5;
        return a1;
      }
      if ( (uint32_t)a1 == 64 )
      {
        v59 = 1;
      }
      else
      {
        if ( (unsigned int)a1 >= 0x40 )
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(64) & 0xFFFFFFFFu);
        v59 = 0;
      }
      v60 = (uint16_t)(v58 + a1);
      *((volatile uint16_t *)off_111E3C + 5) = v60;
      if ( HIDWORD(a1) < v60 )
      {
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(log_printf("Ep0 send length err %u-%u", HIDWORD(a1), v60)) & 0xFFFFFFFFu);
        a1 = (a1 & ~0xFFFF0000u) | (((uint16_t)(*((volatile uint16_t *)v3 + 4)) & 0xFFFFu) << 16);
        v60 = *((volatile uint16_t *)v3 + 5);
      }
      v61 = (uint16_t)(WORD2(a1) - v60);
      if ( v61 > 0x40 )
      {
        v61 = 64;
      }
      else if ( !v61 )
      {
        if ( !v59 )
        {
          v62 = (void *)(uintptr_t)(off_1122D8);
          *v3 = 5;
          v62[516] |= 0x10u;
          return a1;
        }
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(rf_set_param((int)(uintptr_t)(nullptr), 0)) & 0xFFFFFFFFu);
        goto LABEL_18;
      }
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(rf_set_param((int)(uintptr_t)((volatile char *)(*((volatile uint32_t *)v3 + 1) + v60)), v61)) & 0xFFFFFFFFu);
LABEL_18:
      if ( (v2 & 0x20) == 0 )
        return a1;
LABEL_19:
      if ( *v3 == 6 )
      {
        v27 = *(volatile uint32_t **)off_111E40;
        v28 = *(volatile uint32_t *)off_111E4C;
        v29 = (void *)(uintptr_t)(off_111E44);
        *v27 = dword_111E50;
        v27[1] = v28;
        v29[709] = (int)(uintptr_t)(v27);
        v29[706] = v29[706];
        v29[704] |= 0x84000000;
        *v3 = 7;
        v29[517] |= 0x10u;
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(timer_read_count()) & 0xFFFFFFFFu);
      }
      return a1;
    }
    if ( v15 != 7 )
      goto LABEL_18;
    v23 = (void *)(uintptr_t)(off_111E44);
    a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(off_111E58) << 32);
    a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
    *(volatile uint8_t *)off_111E3C = 0;
    v23[517] &= ~0x10u;
    v23[516] &= ~0x10u;
    if ( *(volatile uint8_t *)HIDWORD(a1) )
    {
      v23[513] = (16 * (uint8_t)*(volatile uint8_t *)HIDWORD(a1)) & 0x70 | v23[513] & 0xFFFFFF8F;
      *(volatile uint8_t *)HIDWORD(a1) = 0;
    }
  }
  else
  {
    if ( (BYTE4(a1) & 0x21) == 0x21 )
    {
      v17 = (void *)(uintptr_t)(off_111E44);
      if ( (*((volatile uint32_t *)off_111E44 + 708) & 0x7F) == 0x40 )
      {
        v18 = *((volatile uint32_t *)off_111E44 + 708);
        a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v18 << 12) & 0xFFFFFFFFu);
        if ( (v18 & 0x80000) != 0 )
        {
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_111E4C) & 0xFFFFFFFFu);
          v19 = *(volatile uint32_t **)off_111E40;
          *v19 = dword_111E50;
          v19[1] = a1;
          v17[709] = (int)(uintptr_t)(v19);
          v17[706] = v17[706];
          v17[704] |= 0x84000000;
          return a1;
        }
      }
    }
    if ( (a1 & 0x100000000LL) == 0 )
    {
      v3 = (volatile uint8_t *)off_111E3C;
      v16 = *(volatile uint8_t *)off_111E3C;
      if ( (a1 & 0x800000000LL) != 0 )
      {
        if ( v16 != 1 )
          return a1;
        goto LABEL_6;
      }
      if ( v16 == 2 )
      {
LABEL_6:
        v4 = (void *)(uintptr_t)(off_111E40);
        goto LABEL_7;
      }
      goto LABEL_18;
    }
    if ( (a1 & 0x800000000LL) != 0 )
    {
      v3 = (volatile uint8_t *)off_111E3C;
      if ( !*(volatile uint8_t *)off_111E3C )
        goto LABEL_6;
      rf_enable_tx_patch((void *)(uintptr_t)(1), 0);
      v4 = (void *)(uintptr_t)(off_112198);
LABEL_7:
      if ( (v2 & 0x40) != 0 )
        v5 = (volatile uint8_t *)(*((volatile uint32_t *)off_111E44 + 709) - 8);
      else
        v5 = *(volatile uint8_t **)(*(volatile uint32_t *)v4 + 4);
      *((volatile uint32_t *)v3 + 1) = 0;
      *((volatile uint32_t *)v3 + 2) = 0;
      *v3 = 2;
      v3[12] = v3[12] & 0x7F | (*v5 >> 7 << 7);
      v6 = v3[12] & 0x9F | (32 * (((int)*v5 >> 5) & 3));
      v3[12] = v6;
      v3[12] = v6 & 0xE0 | *v5 & 0x1F;
      v3[13] = v5[1];
      *((volatile uint16_t *)v3 + 7) = v5[2] | (v5[3] << 8);
      *((volatile uint16_t *)v3 + 8) = v5[4] | (v5[5] << 8);
      v7 = v5[6] | (v5[7] << 8);
      *((volatile uint16_t *)v3 + 9) = v7;
      if ( !v7 && (v3[12] & 0x80u) != 0 )
        log_printf(aEp0SetupErrorW);
      v8 = (void *)(uintptr_t)(off_111E44);
      v9 = (volatile char *)off_111E48;
      v10 = *(int ( **)(void *))&((volatile uint32_t *)(uintptr_t)off_111E48)[12];
      *((volatile uint32_t *)off_111E44 + 517) &= ~0x10u;
      v8[516] &= ~0x10u;
if ( !v10 || !v10((void *)(uintptr_t)(off_111E3C)) ) { v11 = (void *)(uintptr_t)(off_111E64);
        v12 = *(volatile uint8_t *)off_111E64;
        v13 = *(volatile uint8_t *)off_111E64;
        if ( (v3[12] & 0x60) != 0 )
        {
LABEL_54:
          if ( v13 == 4 && *v11 != 4 )
LABEL_56:
            timer_init();
          goto LABEL_49;
        }
        v14 = v3[13];
        switch ( v3[13] )
        {
          case 0u:
            if ( *(volatile uint8_t *)off_111E64 == 4 )
            {
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
                goto LABEL_66;
              v67 = *((volatile uint16_t *)v3 + 8);
              v40 = v67 & 0xF;
              if ( v40 > 5 )
                goto LABEL_156;
              v14 = (v67 >> 7) & 1;
            }
            else
            {
              if ( *((volatile uint16_t *)v3 + 8) )
                goto LABEL_54;
              v30 = v3[12] & 0x1F;
              if ( v30 == 1 )
                goto LABEL_156;
              if ( v30 != 2 )
              {
LABEL_66:
                if ( v30 )
                  goto LABEL_59;
                v31 = (void *)(uintptr_t)(off_11217C);
                *(volatile uint16_t *)off_11217C = *(volatile uint8_t *)off_112178;
                goto LABEL_68;
              }
              v40 = v3[13];
            }
            if ( rf_select_base(v14, v40) )
            {
              v31 = (void *)(uintptr_t)(off_11217C);
              *(volatile uint16_t *)off_11217C = 1;
LABEL_68:
              *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v31);
              *((volatile uint16_t *)v3 + 4) = 2;
              *v3 = 4;
              goto LABEL_86;
            }
LABEL_156:
            v31 = (void *)(uintptr_t)(off_1122E8);
            *(volatile uint16_t *)off_1122E8 = 0;
            goto LABEL_68;
          case 1u:
            if ( *(volatile uint8_t *)off_111E64 != 4 && *((volatile uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 2 || *((volatile uint16_t *)v3 + 7) )
              goto LABEL_79;
            rf_enable_txrx_patch((void *)(uintptr_t)((*((volatile uint16_t *)v3 + 8) >> 7) & 1), *((volatile uint16_t *)v3 + 8) & 0xF);
            *v3 = 7;
            if ( v13 == 4 )
              goto LABEL_44;
            goto LABEL_73;
          case 3u:
            if ( *(volatile uint8_t *)off_111E64 != 4 && *((volatile uint16_t *)v3 + 8) )
              goto LABEL_54;
            if ( (v3[12] & 0x1F) != 0 )
            {
              if ( (v3[12] & 0x1F) != 2 || *((volatile uint16_t *)v3 + 7) )
              {
LABEL_79:
                *v3 = 7;
                if ( v12 == 4 )
                {
LABEL_60:
                  if ( *v11 != 4 )
                    goto LABEL_56;
                }
                goto LABEL_49;
              }
              rf_enable_rx_patch((void *)(uintptr_t)((*((volatile uint16_t *)v3 + 8) >> 7) & 1), *((volatile uint16_t *)v3 + 8) & 0xF);
              *v3 = 7;
              if ( v13 != 4 )
                goto LABEL_73;
            }
            else
            {
              v68 = *((volatile uint16_t *)v3 + 7);
              if ( v68 != 2 )
              {
                v39 = v68 == 1;
                *v3 = 7;
LABEL_89:
                if ( v13 != 4 || *v11 == 4 )
                {
                  if ( v39 )
                    break;
                }
                else
                {
                  timer_init();
                  if ( v39 )
                    break;
                }
                goto LABEL_49;
              }
              *(volatile uint8_t *)off_1122EC = HIBYTE(*((volatile uint16_t *)v3 + 8));
              *v3 = 7;
              if ( v12 != 4 )
                goto LABEL_73;
            }
LABEL_44:
            if ( *v11 == 4 )
              goto LABEL_73;
LABEL_45:
            timer_init();
            break;
          case 5u:
            v34 = *((volatile uint16_t *)v3 + 7);
            *((volatile uint32_t *)off_112180 + 512) = (16 * v34) & 0x7F0 | *((volatile uint32_t *)off_112180 + 512) & 0xFFFFF80F;
            *v3 = 7;
            if ( v34 )
              *v11 = 3;
            else
              *v11 = 2;
            goto LABEL_72;
          case 6u:
            v32 = *((volatile uint16_t *)v3 + 7);
            v33 = v32 >> 8;
            switch ( v32 >> 8 )
            {
              case 1u:
                v41 = (volatile uint8_t *)(*(int ( **)(int, unsigned int))v9)(1, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 18 || v41[1] != 1 )
                  goto LABEL_54;
                goto LABEL_102;
              case 2u:
                v45 = (volatile uint8_t *)(*((int ( **)(uint32_t, unsigned int))v9 + 1))(0, v33);
                if ( !v45 || *v45 != 9 || v45[1] != 2 )
                  goto LABEL_54;
                v46 = (uint8_t)v45[3];
                v47 = (uint8_t)v45[2];
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v45);
                *((volatile uint16_t *)v3 + 4) = v47 | (v46 << 8);
                v48 = *(volatile uint8_t *)off_112178;
                if ( (v45[7] & 0x40) != 0 )
                  v49 = v48 | 1;
                else
                  v49 = v48 & 0xFE;
                *(volatile uint8_t *)off_112178 = v49;
                goto LABEL_103;
              case 3u:
                v44 = (volatile uint8_t *)(*((int ( **)(uint32_t, unsigned int))v9 + 2))(
                                           (uint8_t)v32,
                                           v33);
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v44);
                if ( !v44 )
                  goto LABEL_54;
                *((volatile uint16_t *)v3 + 4) = *v44;
                goto LABEL_103;
              case 4u:
              case 5u:
                goto LABEL_59;
              case 6u:
                v41 = (volatile uint8_t *)(*(int ( **)(int, unsigned int))v9)(6, v33);
                if ( !v41 )
                  goto LABEL_54;
                v42 = *v41;
                if ( v42 != 10 || v41[1] != 6 )
                  goto LABEL_54;
                goto LABEL_102;
              case 0xFu:
                v41 = (volatile uint8_t *)(*(int ( **)(int, unsigned int))v9)(15, v33);
                if ( !v41 || *v41 != 5 || v41[1] != 15 )
                  goto LABEL_54;
                v42 = (v42 & ~0xFFFFu) | ((uint16_t)(v41[2]) & 0xFFFFu);
LABEL_102:
                *((volatile uint16_t *)v3 + 4) = v42;
                *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v41);
LABEL_103:
                v43 = *((volatile uint16_t *)v3 + 9);
                if ( *((volatile uint16_t *)v3 + 4) > v43 )
                  *((volatile uint16_t *)v3 + 4) = v43;
                *v3 = 4;
                break;
              default:
                log_printf("Unknown descriptor: %d", v33);
                goto LABEL_54;
            }
            goto LABEL_86;
          case 8u:
            *((volatile uint32_t *)v3 + 1) = dword_11218C;
            *((volatile uint16_t *)v3 + 4) = 2;
            *v3 = 4;
            goto LABEL_86;
          case 9u:
            v39 = ke_timeout_tick();
            goto LABEL_89;
          case 0xAu:
            if ( *(volatile uint8_t *)off_111E64 != 4 )
              goto LABEL_54;
            v37 = (void *)(uintptr_t)(off_112184);
            *v3 = *(volatile uint8_t *)off_111E64;
            v38 = (void *)(uintptr_t)(off_112188);
            *((volatile uint16_t *)v3 + 8) = *v37;
            *((volatile uint32_t *)v3 + 1) = (int)(uintptr_t)(v38);
            *((volatile uint16_t *)v3 + 4) = 1;
LABEL_86:
            if ( v13 != 4 )
              goto LABEL_87;
            goto LABEL_152;
          case 0xBu:
            v35 = *((int ( **)(uint32_t, uint32_t))v9 + 6);
            if ( !v35 || !v35(*((volatile uint16_t *)v3 + 8), *((volatile uint16_t *)v3 + 7)) )
              goto LABEL_54;
            v36 = (void *)(uintptr_t)(off_112188);
            *(volatile uint16_t *)off_112184 = *((volatile uint16_t *)v3 + 8);
            *v36 = *((volatile uint16_t *)v3 + 7);
            *v3 = 7;
LABEL_72:
            if ( v13 != 4 )
              goto LABEL_73;
LABEL_152:
            if ( *v11 != 4 )
              goto LABEL_45;
            break;
          default:
LABEL_59:
            if ( v13 != 4 )
              goto LABEL_49;
            goto LABEL_60;
        }
      }
      v24 = *v3;
      switch ( v24 )
      {
        case 3:
          if ( !*((volatile uint32_t *)v3 + 1) )
            *((volatile uint32_t *)v3 + 1) = dword_111E60;
          goto LABEL_50;
        case 4:
LABEL_87:
          rf_set_param((int)(uintptr_t)(*((volatile char **)v3 + 1)), *((volatile uint16_t *)v3 + 4));
          goto LABEL_50;
        case 7:
LABEL_73:
          timer_read_count();
          goto LABEL_50;
      }
LABEL_49:
      *v3 = 0;
      rf_channel_set_flag(0, 0x200000, 0);
      rf_channel_get_flag(0, 0x200000, 0);
LABEL_50:
      v25 = *(volatile uint32_t **)v4;
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_111E4C) & 0xFFFFFFFFu);
      v26 = (void *)(uintptr_t)(off_111E44);
      *v25 = dword_111E50;
      v25[1] = a1;
LABEL_51:
      v26[709] = (int)(uintptr_t)(v25);
      v26[706] = v26[706];
      v26[704] |= 0x84000000;
      return a1;
    }
    v4 = (void *)(uintptr_t)(off_111E40);
    v3 = (volatile uint8_t *)off_111E3C;
    v20 = *(volatile uint32_t **)off_111E40;
    if ( (*(volatile uint8_t *)(*(volatile uint32_t *)off_111E40 + 3) & 1) == 0 )
    {
      v21 = *(volatile uint8_t *)off_111E3C;
      switch ( v21 )
      {
        case 2:
          goto LABEL_7;
        case 3:
          v51 = *((volatile uint16_t *)off_111E3C + 5);
          v52 = (volatile int *)off_112190;
          v53 = 64 - *(volatile uint16_t *)v20;
          if ( v53 >= (uint16_t)(*((volatile uint16_t *)off_111E3C + 4) - v51) )
            v53 = (v53 & ~0xFFFFu) | ((uint16_t)(*((volatile uint16_t *)off_111E3C + 4) - v51) & 0xFFFFu);
          memcpy((volatile char *)(v51 + *((volatile uint32_t *)off_111E3C + 1)), *(volatile char **)off_112190, (uint16_t)v53);
          v54 = *((volatile uint16_t *)v3 + 4);
          v55 = (uint16_t)(v53 + *((volatile uint16_t *)v3 + 5));
          *((volatile uint16_t *)v3 + 5) = v55;
          if ( v54 == v55 )
          {
            v63 = *(void ( **)(volatile uint8_t *))&((volatile uint32_t *)(uintptr_t)off_1122DC)[16];
            if ( v63 )
              v63(v3);
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 26) & 0xFFFFFFFFu);
            if ( (v2 & 0x20) == 0 )
            {
              *v3 = 6;
              return a1;
            }
            v64 = *(volatile uint32_t **)v4;
            v65 = *v52;
            v66 = (void *)(uintptr_t)(off_1122D8);
            *v64 = dword_1122E4;
            v64[1] = v65;
            v66[709] = (int)(uintptr_t)(v64);
            v66[706] = v66[706];
            v66[704] |= 0x84000000;
            *v3 = 7;
            v66[517] |= 0x10u;
            a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(timer_read_count()) & 0xFFFFFFFFu);
            goto LABEL_19;
          }
          v56 = *(volatile uint32_t **)v4;
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*v52) & 0xFFFFFFFFu);
          v57 = (void *)(uintptr_t)(off_112180);
          *v56 = dword_112194;
          v56[1] = a1;
          v57[709] = (int)(uintptr_t)(v56);
          v57[706] = v57[706];
          v57[704] |= 0x84000000;
          break;
        case 5:
          v26 = (void *)(uintptr_t)(off_112180);
          *(volatile uint8_t *)off_111E3C = 0;
          v25 = *(volatile uint32_t **)v4;
          v50 = (void *)(uintptr_t)(off_112190);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(dword_112194) & 0xFFFFFFFFu);
          v26[517] &= ~0x10u;
          v26[516] &= ~0x10u;
          a1 = (a1 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v50) << 32);
          *(volatile uint64_t *)v25 = a1;
          goto LABEL_51;
        default:
          v22 = (void *)(uintptr_t)(off_111E44);
          a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(*(volatile uint32_t *)off_111E4C) & 0xFFFFFFFFu);
          *v20 = dword_111E50;
          v20[1] = a1;
          v22[709] = (int)(uintptr_t)(v20);
          v22[706] = v22[706];
          v22[704] |= 0x84000000;
          break;
      }
      goto LABEL_18;
    }
    if ( *(volatile uint8_t *)off_111E3C )
      a1 = (a1 & ~0xFFFFFFFFull) | ((uint32_t)(rf_enable_tx_patch((void *)(uintptr_t)(1), 0)) & 0xFFFFFFFFu);
    *v3 = 1;
  }
  return a1;
}


// rf_init_1 @ 0x1122f0
int rf_init_1() {
  volatile uint8_t *v0; // r3
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r3
  volatile int *v3; // r1
  int v4; // r5
  volatile uint32_t *v5; // r4
  int i; // r0
  int v7; // r3
  volatile uint32_t *v8; // r3
  volatile int *v9; // r1
  int v10; // lr
  int v11; // r12
  volatile int *v12; // r6
  int v13; // r5
  int v14; // r0
  volatile int *v15; // r2
  volatile uint32_t *v16; // r4
  volatile uint32_t *v17; // r3
  volatile uint32_t *v18; // r3
  volatile int *v19; // r0
  int result; // r0
  int ( *v21)(uint32_t); // r3
  volatile uint16_t *v22; // r2
  int v23; // r4
  volatile uint32_t *v24; // r1
  volatile uint32_t *v25; // r3
  volatile uint32_t *v26; // r2
  volatile uint32_t *v27; // r3

  v0 = (void *)(uintptr_t)(off_11253C);
  v1 = (void *)(uintptr_t)(off_112540);
  *(volatile uint8_t *)off_112538 = 2;
  *v0 = 0;
  v1[896] &= ~1u;
  v1[513] &= ~1u;
  timer_init();
  if ( (v1[6] & 0x80) != 0 )
    v1[6] &= ~0x80u;
  v2 = (void *)(uintptr_t)(off_112540);
  *((volatile uint32_t *)off_112540 + 513) |= 0x200u;
  while ( (v2[5] & 0x80) == 0 )
    ;
  v3 = (volatile int *)off_112544;
  v4 = dword_112548;
  v5 = (void *)(uintptr_t)(off_112544);
  for ( i = 1; ; ++i )
  {
    if ( i == 1 )
    {
      if ( (*v5 & 0x80008000) != 0 )
        *v5 |= v4;
      goto LABEL_11;
    }
    v7 = *v3;
    if ( (*v3 & 0x80008000) != 0 )
    {
      *v3 |= v4;
      if ( v7 < 0 )
      {
        v3[2] = 2;
        *v3 |= 0x40000000u;
        while ( (v3[2] & 2) == 0 )
          ;
      }
      if ( (v7 & 0x8000) == 0 )
        *v3 &= ~0x8000u;
    }
    if ( i == 6 )
      break;
LABEL_11:
    v3 += 8;
  }
  v8 = (void *)(uintptr_t)(off_112540);
  *((volatile uint32_t *)off_112540 + 513) |= 0x400u;
  v8[513] |= 0x80u;
  while ( (v8[5] & 0x40) == 0 )
    ;
  v9 = (volatile int *)off_11254C;
  v10 = dword_112568;
  v11 = dword_112548;
  v12 = (volatile int *)off_11254C;
  v13 = 1;
  while ( 2 )
  {
    if ( v13 == 1 )
    {
      v14 = *v12;
      if ( (*v12 & 0x80008000) != 0 )
      {
        v16 = (volatile uint32_t *)v10;
        v15 = v12;
LABEL_20:
        *v16 = 64;
        *v15 |= v11;
        if ( v14 < 0 )
        {
          if ( (v14 & 0x20000) == 0 )
          {
            while ( (*v16 & 0x40) == 0 )
              ;
            *v16 = 64;
          }
          *v16 = 2;
          *v15 |= 0x40000000u;
          while ( (*v16 & 2) == 0 )
            ;
        }
        if ( (v14 & 0x8000) == 0 )
          *v15 &= ~0x8000u;
        goto LABEL_23;
      }
      goto LABEL_24;
    }
    v14 = *v9;
    v15 = v9;
    if ( (*v9 & 0x80008000) != 0 )
    {
      v16 = (void *)(v9 + 2);
      goto LABEL_20;
    }
LABEL_23:
    if ( v13 != 6 )
    {
LABEL_24:
      ++v13;
      v9 += 8;
      continue;
    }
    break;
  }
  v17 = (void *)(uintptr_t)(off_112540);
  *((volatile uint32_t *)off_112540 + 4) = 1072;
  while ( (v17[4] & 0x30) != 0 )
    ;
  v17[513] |= 0x100u;
  v17[519] = 65537;
  v17[517] = 41;
  v17[516] = 9;
  v17[6] |= 0xC0000u;
  if ( (v17[18] & 0x80000) != 0 )
  {
    v22 = (void *)(uintptr_t)(off_112560);
    v23 = dword_112564;
    v24 = (void *)(uintptr_t)(off_112540);
    v17[9] = 285;
    v17[10] = v23;
    *v22 = 318;
    v17[513] |= 0x80u;
    while ( (v24[5] & 0x40) == 0 )
      ;
    while ( *((volatile int *)off_112540 + 4) >= 0 )
      ;
    v25 = (void *)(uintptr_t)(off_112540);
    *((volatile uint32_t *)off_112540 + 4) = 1056;
    while ( (v25[4] & 0x20) != 0 )
      ;
    v26 = (void *)(uintptr_t)(off_112540);
    v25[513] |= 0x100u;
    v25[513] |= 0x200u;
    while ( (v26[5] & 0x80) == 0 )
      ;
    v27 = (void *)(uintptr_t)(off_112540);
    v26[4] |= 0x10u;
    while ( (v27[4] & 0x10) != 0 )
      ;
    v27[513] |= 0x400u;
  }
  v18 = (void *)(uintptr_t)(off_112550);
  v19 = (volatile int *)dword_112554;
  *((volatile uint32_t *)off_112540 + 512) &= 0xFFFFF80F;
  v18[1] = 0;
  v18[2] = 0;
  *(volatile uint8_t *)v18 = 0;
  memset(v19, 0, 0x50u);
  memset((volatile int *)dword_112558, 0, 0x50u);
  result = timer_set_alarm();
  v21 = *(int ( **)(uint32_t))&((volatile uint32_t *)(uintptr_t)off_11255C)[32];
  if ( v21 )
    return v21(0);
  return result;
}


// ke_poll_event_a @ 0x11256c
int ke_poll_event_a() {
  int result; // r0

  if ( (*(volatile uint16_t *)(off_112594 + 0xB2) & 0x4000) != 0 )
    result = (int)uart_tx_string(aUsbSusp_0);
  else
    result = dispatch_event_handler_1(aUsbSusp);
  *(volatile uint8_t *)off_11259C = 1;
  return result;
}


// util_read_status @ 0x1125a4
int util_read_status() {
  return *(volatile uint8_t *)off_1125AC;
}



// ke_poll_event_b @ 0x1125b0
int ke_poll_event_b() {
  int result; // r0
  volatile uint32_t *v1; // r2

  if ( (*(volatile uint16_t *)(off_1125E0 + 0xB2) & 0x4000) != 0 )
    result = (int)uart_tx_string(aUsbWkup_0);
  else
    result = dispatch_event_handler_1(aUsbWkup);
  v1 = (void *)(uintptr_t)(off_1125EC);
  *(volatile uint8_t *)off_1125E8 = 0;
  v1[896] &= ~1u;
  return result;
}


// mmio_read_irq_status @ 0x1125f4
int mmio_read_irq_status() {
  volatile uint32_t *v0; // r3
  int v1; // r2
  int v2; // r4
  uint64_t v3; // r0
  int v4; // r10
  int v5; // r2
  int v6; // r8
  int v7; // r11
  volatile uint32_t *v8; // r6
  int v9; // r5
  unsigned int v10; // r2
  int v11; // r4
  int v12; // r9
  volatile char *v13; // r3
  int v14; // r1
  int ( *v15)(int, int, BOOL); // r3
  volatile uint32_t *v16; // r5
  int v17; // r6
  int v18; // r9
  int v19; // r7
  int i; // r4
  volatile char *v21; // r3
  int v22; // r2
  uint64_t v23; // r0
  int v24; // r3
  int v25; // r3
  int v26; // r3
  volatile uint32_t *v27; // r3
  volatile uint32_t *v28; // r4
  volatile int *v29; // r0
  int v30; // r1
  int v31; // r4
  int ( *v32)(int, int, uint32_t); // r3
  BOOL v34; // [sp+4h] [bp-10h]
  int v35; // [sp+4h] [bp-10h]
  int v36; // [sp+8h] [bp-Ch]
  int v37; // [sp+8h] [bp-Ch]
  int v38; // [sp+Ch] [bp-8h]
  int v39; // [sp+Ch] [bp-8h]

  v0 = (void *)(uintptr_t)(off_112848);
  v1 = *((volatile uint32_t *)off_112848 + 5);
  *((volatile uint32_t *)off_112848 + 5) = v1;
  v2 = v0[6] & v1;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v2 << 19) & 0xFFFFFFFFu);
  if ( (v2 & 0x1000) != 0 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(rf_init_1()) & 0xFFFFFFFFu);
    v4 = v2 & 0x2000;
    if ( (v2 & 0x2000) == 0 )
      return v3;
    v7 = 0;
    v6 = 0;
    v5 = 0;
  }
  else
  {
    v4 = v2 & dword_112870;
    v5 = v2 & 0x40000;
    v6 = v2 & 0x80000;
    v7 = v2 & 0x800;
    if ( (v2 & 0x2000) == 0 )
      goto LABEL_3;
  }
  v26 = *((volatile uint32_t *)off_112848 + 514);
  if ( (v26 & 6) != 0 && (v26 & 2) != 0 )
    *(volatile uint32_t *)off_11285C = 1;
  v27 = (void *)(uintptr_t)(off_112848);
  v28 = (void *)(uintptr_t)(off_112860);
  v29 = (volatile int *)off_112864;
  v30 = dword_112868;
  *((volatile uint32_t *)off_112848 + 576) = dword_112868;
  v27[704] = v30;
  v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*v28) << 32);
  v31 = *v29;
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(dword_11286C) & 0xFFFFFFFFu);
  *(volatile uint32_t *)HIDWORD(v3) = dword_11286C;
  *(volatile uint32_t *)(HIDWORD(v3) + 4) = v31;
  v27[709] = HIDWORD(v3);
  v27[706] = v27[706];
  v27[704] |= 0x84000000;
LABEL_3:
  if ( v5 )
  {
    v8 = (void *)(uintptr_t)(off_112848);
    v9 = dword_11284C;
    v10 = *((volatile uint32_t *)off_112848 + 518);
    v11 = 0;
    v12 = v10 & *((volatile uint32_t *)off_112848 + 519);
    while ( 1 )
    {
      v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(1) & 0xFFFFFFFFu);
      if ( ((1 << v11) & v12) != 0 )
      {
        if ( !v11 )
        {
          v3 = (v3 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v8[578]) << 32);
          v8[578] = HIDWORD(v3);
          v25 = v8[516] & HIDWORD(v3);
          if ( (v25 & 0x18) != 0 )
          {
            v8[516] &= ~0x10u;
            rf_channel_get_flag(0, 0x200000, 0);
          }
          else if ( (v25 & 1) != 0 )
          {
            util_check_flags(v3, (volatile uint32_t *)v10);
          }
          goto LABEL_14;
        }
        v13 = (volatile char *)&v8[8 * v11 - 8];
        v10 = *((volatile uint32_t *)v13 + 586);
        *((volatile uint32_t *)v13 + 586) = v10;
        v14 = v8[516] & v10;
        if ( (v14 & 9) != 0 )
        {
          if ( *(volatile uint8_t *)(v9 - 5) )
          {
            v36 = *(volatile uint32_t *)(v9 - 12);
            v38 = *(volatile uint32_t *)(v9 - 16);
            v34 = (v10 & 1) == 0;
            if ( (v10 & 1) == 0 )
              rf_enable_tx_patch((void *)(uintptr_t)(1), (uint8_t)v11);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v9 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v15 = *(int ( **)(int, int, BOOL))(dword_112850 + 4 * v11 + 52);
            if ( v15 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v15(v38, v36, v34)) & 0xFFFFFFFFu);
          }
        }
        else
        {
          v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(log_printf("irq %x\r\n", v14)) & 0xFFFFFFFFu);
        }
      }
      if ( (uint8_t)v11 == 5 )
        break;
LABEL_14:
      ++v11;
      v9 += 16;
    }
  }
  if ( v6 )
  {
    v16 = (void *)(uintptr_t)(off_112848);
    v17 = dword_112854;
    v18 = dword_112874;
    v19 = *((volatile uint32_t *)off_112848 + 518) & *((volatile uint32_t *)off_112848 + 519);
    for ( i = 0; ; ++i )
    {
      if ( ((0x10000 << i) & v19) != 0 )
      {
        if ( !i )
        {
          v23 = (v23 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(v16[706]) << 32);
          v16[706] = HIDWORD(v23);
          v24 = v16[517] & HIDWORD(v23);
          if ( (v24 & 0x10) != 0 )
          {
            v16[517] &= ~0x10u;
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(rf_channel_set_flag(0, 0x200000, 0)) & 0xFFFFFFFFu);
          }
          else if ( (v24 & 0x29) != 0 )
          {
            v23 = (v23 & ~0xFFFFFFFFull) | ((uint32_t)(0) & 0xFFFFFFFFu);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(util_check_flags(v23, (volatile uint32_t *)(v24 << 27))) & 0xFFFFFFFFu);
          }
          goto LABEL_19;
        }
        v21 = (volatile char *)&v16[8 * i - 8];
        v22 = *((volatile uint32_t *)v21 + 714);
        *((volatile uint32_t *)v21 + 714) = v22;
        if ( (v16[517] & v22 & 1) != 0 )
        {
          if ( *(volatile uint8_t *)(v17 - 8) )
          {
            v37 = **(volatile uint16_t **)(v18 + 4 * i);
            v35 = *(volatile uint32_t *)(v17 - 12);
            v39 = *(volatile uint32_t *)(v17 - 16);
            v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(memset((volatile int *)(v17 - 16), 0, 0x10u)) & 0xFFFFFFFFu);
            v32 = *(int ( **)(int, int, uint32_t))(4 * i + dword_112850 + 32);
            if ( v32 )
              v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(v32(v39, v35 - v37, 0)) & 0xFFFFFFFFu);
          }
        }
      }
      if ( (uint8_t)i == 5 )
        break;
LABEL_19:
      v17 += 16;
    }
  }
  if ( v7 )
  {
    v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(ke_poll_event_a()) & 0xFFFFFFFFu);
    if ( v4 >= 0 )
      return v3;
  }
  else if ( v4 >= 0 )
  {
    return v3;
  }
  v3 = (v3 & ~0xFFFFFFFFull) | ((uint32_t)(ke_poll_event_b()) & 0xFFFFFFFFu);
  return v3;
}


// critical_section_enter @ 0x112878
int critical_section_enter() {
  volatile int *v0; // r4
  volatile uint8_t *v1; // r5
  int v2; // r2
  int v3; // r3
  volatile unsigned int v4; // r2
  unsigned int v5; // r2
  int v6; // r3
  uint16_t v7; // r1
  int result; // r0
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)dword_1128F8 = 1;
  }
  v0 = (volatile int *)dword_1128FC;
  v1 = (volatile uint8_t *)dword_112900;
  v2 = *(volatile uint8_t *)dword_112900;
  v3 = *(volatile uint32_t *)dword_1128FC + 1;
  *(volatile uint32_t *)dword_1128FC = v3;
  if ( v2 )
  {
    *(volatile uint32_t *)(dword_112904 + 0x804) |= 1u;
    v4 = (*(volatile uint32_t *)0x40501010u);
    v5 = v4 + 9000;
    do
      v6 = v5 - (*(volatile uint32_t *)0x40501010u);
    while ( v6 >= 0 );
    v7 = *(volatile uint16_t *)(dword_11290C + 0xB2);
    *(volatile uint32_t *)(dword_112904 + 0x804) &= ~1u;
    if ( (v7 & 0x4000) != 0 )
      result = (int)uart_tx_string(aUsbRmtwkup);
    else
      result = dispatch_event_handler_1(aUsbRmtwkup_0);
    v3 = *v0;
    *v1 = 0;
  }
  if ( v3 )
  {
    v9 = v3 - 1;
    v10 = *(volatile uint32_t *)dword_1128F8;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}


// wait_radio_state @ 0x112918
int wait_radio_state(int a1, volatile uint16_t *a2) {
  int v4; // r2
  int v5; // r3
  int v6; // r2

  critical_section_enter();
  if ( *(volatile uint8_t *)off_11297C != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (uint8_t)(a1 - 1) > 5u )
    return 2;
  if ( (*((volatile uint32_t *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112980 + 16 * v4;
  *(volatile uint32_t *)(v6 + 4) = *a2;
  *(volatile uint8_t *)(v6 + 11) = 1;
  *(volatile uint32_t *)(v5 + 2099508) = (int)(uintptr_t)(a2);
  *((volatile uint32_t *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}



// get_global_14b6ac @ 0x1129cc
int get_global_14b6ac() {
  return dword_1129D0;
}



// tick_counter_update @ 0x112a0c
int tick_counter_update(volatile uint8_t *a1, unsigned int a2, int a3) {
  volatile uint16_t *v3; // r7
  volatile uint8_t *v4; // r6
  volatile uint8_t *v5; // r4
  char v6; // r2
  int v9; // r8
  int v10; // r6
  volatile uint8_t *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  volatile uint32_t *v15; // r3

  v3 = (volatile uint16_t *)off_112B40;
  v4 = (volatile uint8_t *)off_112B44;
  v5 = (void *)(uintptr_t)(off_112B48);
  ++*(volatile uint16_t *)off_112B40;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  if ( *v4 != 2 )
  {
    log_printf("usb wlan recv err %X %d\n", *v3, *v4);
    lookup_task_id(off_112B5C);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf("len err %X %d\n", *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(volatile uint8_t *)off_112B4C )
      check_interrupt_flag(512, "R:%d\n", a2);
    if ( v9 == 17 )
    {
      v11 = (void *)(uintptr_t)(off_112B78);
      if ( *((volatile uint8_t *)off_112B78 + 2433) >= (unsigned int)*((volatile uint8_t *)off_112B78 + 2434) )
      {
        log_printf(aErrNoRxMsgElem);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          ((int (*)())check_and_process)();
          v12 = v11[2433];
          v13 = dword_112B54;
          v14 = (uint8_t)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_112B50
                               * (uint64_t)((unsigned int)(uint8_t)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = (void *)(&v11[20 * v14]);
          v15[409] = (int)(uintptr_t)(a1 + 4);
          v15[412] = v10;
          v11[2433] = v12 + 1;
          check_kernel_state(v13, v15 + 408);
          set_busy_flag_alt(0x1000000);
          return 1;
        }
        log_printf("wml err %X %d %d\n", *v3, v10, a2);
      }
    }
    else
    {
      log_printf("type err %X %X %d %d\r\n", *v3, v9, v10, a2);
    }
  }
  mem_free((void *)(&a1[-*(volatile uint32_t *)off_112B64]));
  ((int (*)())check_and_process)();
  return 1;
}


// wait_rf_ready_1 @ 0x112b7c
int wait_rf_ready_1(int a1) {
  volatile uint16_t *v2; // r4
  int v3; // r2
  int v4; // r1
  volatile uint8_t *v5; // r1
  volatile uint8_t *v6; // r2
  int v7; // r7
  int v8; // r1
  int v9; // r4

  if ( (*(volatile uint32_t *)off_112BFC & 0x2000000) != 0 )
  {
    memset((volatile int *)off_112C00, 0xFFu, 4u);
  }
  else
  {
    v2 = (volatile uint16_t *)off_112C00;
    memset((volatile int *)off_112C00, 0xFFu, 4u);
    if ( mmio_write_400000_4((int)v2) || (v3 = v2[1], v3 == 0xFFFF) || (v4 = *v2, v4 == 0xFFFF) )
      dispatch_event_handler_1(aNoUsbInfoInFla);
    else
      dispatch_event_handler_1("get vid %x, pid %x\r\n", v4, v3);
  }
  v5 = (void *)(uintptr_t)(off_112C0C);
  v6 = (void *)(uintptr_t)(off_112C10);
  *(volatile uint32_t *)off_112C08 = *(volatile uint32_t *)a1;
  v7 = off_112C14;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v8 = *(volatile uint8_t *)(a1 + 8);
    if ( *(volatile uint8_t *)(a1 + 8) )
      v8 = 1;
    v9 = ke_send_event(v7, v8);
    dispatch_event_handler_1("open res:%d\n", v9);
  }
  while ( v9 );
  return 0;
}


// send_data_packet @ 0x112c20
int send_data_packet(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r6
  volatile uint32_t *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = (void *)(uintptr_t)(off_112CA4);
  if ( *(volatile uint8_t *)off_112CA4 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_112CA8);
  if ( *(volatile uint8_t *)off_112CA8 )
  {
    log_printf("err: %s state=%d\r\n", aUsbWlanRecv, *(volatile uint8_t *)off_112CA8);
    return -3;
  }
  else
  {
    v4 = (void *)(uintptr_t)(off_112CAC);
    *(volatile uint8_t *)off_112CA8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_channel_update(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      log_printf("err: %s ret=%d\r\n", aUsbWlanRecv, v5);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_112CB0 = 1;
      if ( *v2 )
      {
        ((int (*)())rf_enable_tx_patch_wrapper)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}


// send_control_packet @ 0x112cc0
int send_control_packet(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint8_t *v3; // r5
  int v4; // r3
  volatile uint32_t *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = (void *)(uintptr_t)(off_112D64);
  if ( *(volatile uint8_t *)off_112D64 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = (void *)(uintptr_t)(off_112D68);
  if ( *(volatile uint8_t *)off_112D68 )
  {
    log_printf("err: %s state=%d\r\n", aUsbWlanRecvFcO, *(volatile uint8_t *)off_112D68);
    return -3;
  }
  else
  {
    v4 = *(volatile char *)off_112D6C;
    *(volatile uint8_t *)off_112D68 = 1;
    v5 = (void *)(uintptr_t)(off_112D70);
    if ( v4 )
    {
      *((volatile uint32_t *)off_112D70 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((volatile uint32_t *)off_112D70 + 713) |= 1u;
    }
    v6 = rf_channel_update_dup(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      log_printf("err: %s ret=%d\r\n", aUsbWlanRecvFcO, v6);
      return -1;
    }
    else
    {
      *(volatile uint8_t *)off_112D74 = 1;
      if ( *v2 )
      {
        ((int (*)())rf_enable_tx_patch_wrapper)(0, 1, 0);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}


// process_event @ 0x112d84
int process_event() {
  volatile uint8_t *v2; // r6
  volatile int **v3; // r4
  char v4; // r0
  volatile uint8_t *v5; // r12
  volatile int *v6; // r7
  volatile int *v7; // r5
  unsigned int v8; // r4
  volatile int *v9; // r1
  char v10; // r3
  char v11; // r2
  volatile uint16_t *v12; // r1
  int v13; // r2
  char v14; // r3

  v2 = (void *)(uintptr_t)(off_112E18);
  if ( *(volatile uint8_t *)off_112E18 )
    return -99;
  v3 = (volatile int **)off_112E1C;
  v4 = list_count((volatile uint32_t **)(uintptr_t)off_112E1C);
  v5 = (void *)(uintptr_t)(off_112E24);
  *(volatile uint8_t *)off_112E24 = v4;
  if ( v4 )
  {
    v6 = *v3;
    v7 = *(volatile int **)(dword_112E20 + 8240);
    if ( v4 != 1 )
    {
      v8 = *((volatile uint16_t *)v6 + 6);
      if ( *((volatile uint16_t *)v7 + 6) < v8 )
      {
        v9 = v6;
        v10 = v4;
        while ( 1 )
        {
          v11 = v4 - v10--;
          if ( !v8 )
            break;
          if ( !*v9 || !v10 )
          {
            *v5 = v10;
            v7 = v9;
            goto LABEL_11;
          }
          v8 = *(volatile uint16_t *)(*v9 + 12);
          v7 = v9;
          v9 = (volatile int *)*v9;
        }
        *v5 = v11;
      }
      goto LABEL_11;
    }
    if ( v7 )
    {
LABEL_11:
      v12 = (volatile uint16_t *)v6[1];
      v13 = v7[1] + 8 * (*((volatile uint8_t *)v7 + 14) - 1);
      v14 = *(volatile uint8_t *)(v13 + 3);
      *v2 = 1;
      *(volatile uint8_t *)(v13 + 3) = v14 & 0xF5 | 0xA;
      return wait_radio_state(1, v12);
    }
  }
  return -98;
}



// set_event_mode @ 0x112e28
int set_event_mode(int a1, int a2, int a3) {
  volatile uint8_t *v3; // r5
  char v4; // r3
  volatile uint8_t *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r6
  volatile uint32_t *v9; // r0
  int v10; // r8
  int v11; // r3

  v3 = (volatile uint8_t *)off_112ED8;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(volatile uint8_t *)off_112ED8 = v4;
  if ( *v3 == 2 )
  {
    v5 = (void *)(uintptr_t)(off_112EDC);
    v6 = *(volatile uint8_t *)off_112EDC;
    *v3 = 0;
    if ( v6 )
    {
      v7 = dword_112EE0;
      v8 = dword_112EE0 - 8;
      do
      {
        while ( 1 )
        {
          v9 = list_pop_front(v7);
          v10 = *(volatile uint32_t *)(v9[1] + 4);
          --*v5;
          check_kernel_state(v8, v9);
          v11 = *(volatile uint8_t *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(volatile uint16_t *)off_112EE8;
          set_busy_flag_alt(1024);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          mem_free((volatile uint32_t *)v10);
        }
        else
        {
          log_printf("###err### %x\r\n", v10);
          handle_ipc_request(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    process_event();
    return 1;
  }
  else
  {
    log_printf("usb wlan send err %d\n", *v3);
    lookup_task_id(off_112EF0);
    return 1;
  }
}


