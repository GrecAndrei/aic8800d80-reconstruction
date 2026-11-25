// llc_env_lookup @ 0x1265d4
/* luna: Queues a channel-switch request, scheduling its hardware instant when sufficiently far away or dispatching it immediately otherwise. */
int llc_env_lookup(int a1, int a2, int a3) {
  volatile uint32_t *v6; // r0
  volatile uint32_t *v7; // r4
  volatile uint32_t *v8; // r5
  volatile char *v9; // r0
  int v10; // r6
  int result; // r0
  volatile int *v12; // r6
  int v13; // r1
  volatile unsigned int v14; // r3
  int v15; // r0
  int v16; // r2
  volatile int *v17; // r3
  int v18; // r3
  int v19; // r3
  int v20; // r2

  v6 = list_pop(dword_12667C);
  v7 = v6;
  if ( **(volatile int16_t **)off_126680 < 0 && !v6 )
    irq_disable_mmio_write((int)aChSwitchNull, (int)aChanSwitchAllo, 227);
  v8 = (void *)(uintptr_t)(off_126684);
  v9 = (volatile char *)off_126684 + 32;
  v10 = *((volatile uint32_t *)off_126684 + 8);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = wlan_ioctl_handler_1((int)v9, v7);
  if ( !v10 )
  {
    v8[18] = (int)(uintptr_t)(v7);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_126690 = 1;
    }
    v12 = (volatile int *)off_126698;
    v13 = v7[1];
    v14 = (*(volatile uint32_t *)0x40501010u);
    v15 = *(volatile uint32_t *)off_126698;
    v16 = *(volatile uint32_t *)off_126698 + 1;
    *(volatile uint32_t *)off_126698 = v16;
    if ( (int)(v13 - v14 - 64) >= 0 )
    {
      result = mem_copy_util((volatile uint32_t *)dword_12669C, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(volatile uint32_t *)off_126690;
        *v12 = v19;
        if ( !v19 )
        {
          if ( v20 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v16 )
      {
        v17 = (volatile int *)off_126690;
        *v12 = v15;
        v18 = *v17;
        if ( !v15 )
        {
          if ( v18 )
            __enable_irq();
        }
      }
      return ((int ( *)(volatile uint32_t *))v8[17])(v7);
    }
  }
  return result;
}


// llc_env_get @ 0x1266a0
/* luna: Resets an LLC environment field and transfers entries from its embedded source list to its destination list when an initial list entry is available. */
volatile uint32_t *llc_env_get() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  result = list_pop(dword_1266D8);
  a2 = result;
  if ( result )
  {
    v1 = (void *)(uintptr_t)(off_1266DC);
    mem_set_util((int)(uintptr_t)((volatile uint32_t *)dword_1266E0));
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      wlan_ioctl_handler_1(v3, v2);
      result = list_pop(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}


// llc_tx_evt_handler @ 0x1266e4
/* luna: Selects the LLC environment and event time for transmit scheduling, accounting for the active link and RF trim timing. */
int llc_tx_evt_handler(int a1, int a2, unsigned int a3) {
  int v3; // r7
  int v4; // r5
  int v5; // r8
  int v6; // r9
  int v7; // r11
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r6
  int result; // r0
  int v16; // r10
  int v17; // r8
  unsigned int v18; // r6
  int v19; // r6
  int v20; // r0
  int v21; // r0
  int v22; // r3
  int v23; // r11
  int v24; // r2
  int v25; // r9
  int v26; // r0
  int v27; // r6
  int v28; // r7
  volatile char *v29; // r6
  int v30; // r10
  int v31; // r11
  unsigned int v32; // r11
  int v33; // r0
  unsigned int v34; // r3
  int v35; // r3
  volatile uint8_t *v36; // r1
  int v37; // zf
  int v38; // r3
  volatile uint8_t *v39; // r6
  int v40; // r6
  int v41; // r7
  int v42; // cf
  int v43; // r6
  int v44; // r8
  int v45; // r0
  int v46; // r6
  int v47; // r10
  int v48; // r1
  int v49; // r2
  volatile char *v50; // r1
  int v51; // r6
  struct __attribute__((packed)) { union { int v52; // [sp+4h] [bp-20h]
  int v53; // [sp+4h] [bp-20h]
  int v54; // [sp+4h] [bp-20h]
  int v55; // [sp+4h] [bp-20h]
  int v56; }; // [sp+4h] [bp-20h]
  union { int v57; // [sp+8h] [bp-1Ch]
  int v58; // [sp+8h] [bp-1Ch]
  int v59; }; // [sp+8h] [bp-1Ch]
  char _pad2[4]; union { int v61; // [sp+10h] [bp-14h]
  int v62; }; // [sp+10h] [bp-14h]
  int v63; // [sp+14h] [bp-10h]
  int v64; // [sp+18h] [bp-Ch] BYREF
  int v65[2]; // [sp+1Ch] [bp-8h] BYREF
  } _frame;
  v3 = dword_1269F8;
  v4 = *((volatile uint32_t *)off_1269F4 + 4);
  v5 = *(volatile uint32_t *)(a1 + 72);
  v6 = *(volatile uint8_t *)(v4 + 8);
  v7 = dword_1269F8 + 1320 * v6;
  _frame.v52 = *(volatile uint32_t *)(v4 + 4) - 4000;
  _frame.v53 = _frame.v52 - a2 - get_timeout_1000();
  if ( *(volatile uint32_t *)(v7 + 72) != v5 )
  {
    _frame.v57 = *(volatile uint32_t *)(v4 + 4);
    v10 = get_timeout_1000();
    v11 = *(volatile uint8_t *)(v5 + 27);
    _frame.v61 = v10;
    v12 = _frame.v57 - 4000;
    _frame.v58 = _frame.v57 - 4000 - v10;
    if ( v11 == 255 )
    {
      v13 = *(volatile uint8_t *)(a1 + 86);
      _frame.v63 = v12;
      if ( v13 == 255 )
      {
        if ( a3 > (_frame.v53 + a3) >> 1 )
          goto LABEL_31;
        v14 = a2 - a3 + ((_frame.v53 + a3) >> 1);
LABEL_6:
        if ( a2 != v14 )
          return llc_env_lookup(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
LABEL_31:
        llc_env_get();
        v14 = a2;
        return llc_env_lookup(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
      }
      v30 = v3 + 1320 * v13;
      v31 = rf_check_trim(v30, (void *)(&_frame.v64), (void *)(_frame.v65));
      v14 = _frame.v64 - 4000 - get_timeout_1000();
      _frame.v64 = v14;
      if ( !v31 )
      {
        if ( v14 + _frame.v61 - _frame.v63 >= 0 )
          v14 = _frame.v58;
        if ( _frame.v61 - _frame.v63 + _frame.v65[0] + 9000 + get_timeout_1000() < 0 )
        {
          llc_env_lookup(v14, *(volatile uint32_t *)(v30 + 72), 0);
          v14 = _frame.v58;
          llc_env_lookup(_frame.v65[0], v5, 0);
        }
        goto LABEL_6;
      }
      if ( _frame.v65[0] + 9000 + _frame.v61 - _frame.v63 + get_timeout_1000() < 0 )
      {
        llc_env_lookup(a2, *(volatile uint32_t *)(v30 + 72), 0);
        llc_env_lookup(_frame.v65[0], v5, 0);
        v14 = _frame.v64;
        if ( _frame.v64 + _frame.v61 - _frame.v63 >= 0 )
          v14 = _frame.v58;
        goto LABEL_6;
      }
LABEL_26:
      v14 = a2;
      goto LABEL_6;
    }
    v16 = v3 + 1320 * v11;
    v17 = *(volatile uint32_t *)(v7 + 72);
    _frame.v54 = v12;
if ( rf_check_trim(v16, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
      {
        if ( _frame.v64 - _frame.v54 + _frame.v61 >= 0 )
          goto LABEL_6;
        v18 = _frame.v64 - _frame.v65[0];
        if ( v18 > get_timeout_1000() + 9000 )
        {
          llc_env_lookup(_frame.v65[0], v17, 0);
          v19 = _frame.v64;
          v20 = v19 - 4000 - get_timeout_1000();
          v14 = _frame.v58;
          llc_env_lookup(v20, *(volatile uint32_t *)(v16 + 72), 0);
          goto LABEL_6;
        }
      }
    }
    else
    {
      if ( _frame.v58 - _frame.v64 < 0 )
        goto LABEL_26;
      v32 = _frame.v64 - a2;
      if ( v32 > get_timeout_1000() + 9000 )
      {
        llc_env_lookup(a2, v17, 0);
        v44 = _frame.v64;
        v45 = get_timeout_1000();
        llc_env_lookup(v44 - 4000 - v45, *(volatile uint32_t *)(v16 + 72), 0);
      }
      v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
        goto LABEL_6;
    }
    v14 = _frame.v58;
    goto LABEL_6;
  }
  result = get_timeout_1000();
  _frame.v55 = _frame.v53 - 4000 - result;
  if ( _frame.v55 <= 4999 )
    return result;
  _frame.v59 = *(volatile uint32_t *)(v4 + 4);
  v21 = get_timeout_1000();
  _frame.v62 = *(volatile uint8_t *)(v5 + 27);
  v22 = _frame.v59 - v21;
  v23 = v21;
  v24 = _frame.v55;
  v25 = _frame.v59 - v21 - 4000;
  if ( _frame.v62 == 255 )
  {
    v33 = *(volatile uint8_t *)(a1 + 86);
    _frame.v56 = v22;
    if ( v33 == 255 )
    {
      v34 = (v24 + a3) >> 1;
      if ( a3 > v34 )
      {
        v29 = (volatile char *)off_1269FC;
        goto LABEL_39;
      }
      v29 = (volatile char *)off_126B2C;
      v28 = a2 - a3 + v34;
    }
    else
    {
      rf_check_trim(v3 + 1320 * v33, (void *)(&_frame.v64), (void *)(_frame.v65));
      v40 = _frame.v64;
      result = get_timeout_1000();
      if ( _frame.v56 - v40 + result < 0 )
        return result;
      v41 = _frame.v64;
      v29 = (volatile char *)off_1269FC;
      v28 = v41 - 4000 - get_timeout_1000();
      v42 = v25 - _frame.v65[0] < 0;
      v25 &= (v25 - _frame.v65[0]) >> 31;
      if ( !v42 )
        v25 = _frame.v65[0];
    }
LABEL_51:
    if ( a2 != v28 )
    {
LABEL_40:
      v35 = *(volatile uint8_t *)(v5 + 24);
      if ( v35 == 2 )
      {
        if ( (uint8_t)v29[24] == 255 )
        {
          v38 = 1;
LABEL_44:
          v39 = (volatile uint8_t *)&v29[28 * v38];
          if ( v39[24] == 255 )
            v36 = 0;
          else
            v36 = v39;
          goto LABEL_47;
        }
        v36 = (volatile uint8_t *)off_126B2C;
      }
      else
      {
        v36 = (volatile uint8_t *)&v29[28 * v35 + 28];
        if ( v36[24] == 255 )
        {
          v37 = v35 == 1;
          v38 = v35 + 2;
          if ( v37 )
            v38 = 0;
          goto LABEL_44;
        }
      }
LABEL_47:
      llc_env_lookup(v28, (int)v36, 0);
      return llc_env_lookup(v25, v5, v4);
    }
LABEL_39:
    llc_env_get();
    v28 = a2;
    goto LABEL_40;
  }
if ( rf_check_trim(v3 + 1320 * _frame.v62, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v43 = _frame.v64;
    v28 = _frame.v65[0];
    if ( v43 - _frame.v59 + v23 - get_timeout_1000() < 0 )
    {
      v46 = _frame.v64;
      v25 = v46 - 4000 - get_timeout_1000();
    }
    result = v25 - v28 - 9000 - get_timeout_1000();
    if ( result >= 0 )
      goto LABEL_19;
    return result;
  }
  v26 = get_timeout_1000();
  v27 = _frame.v64;
  if ( 5000 - _frame.v64 + a2 + 2 * (v26 + 4000) < 0 )
  {
    if ( v27 - _frame.v59 + v23 - get_timeout_1000() < 0 )
    {
      v51 = _frame.v64;
      v47 = v51 - 4000 - get_timeout_1000();
    }
    else
    {
      v47 = v25;
    }
    if ( _frame.v65[0] + 9000 - v25 + get_timeout_1000() >= 0 )
    {
      v29 = (volatile char *)off_126B2C;
      v25 = v47;
      goto LABEL_39;
    }
    v29 = (volatile char *)off_126B2C;
    v48 = *(volatile uint8_t *)(*(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72) + 24);
    v49 = v48 + 1;
    if ( v48 == 2 )
    {
      if ( *((volatile uint8_t *)off_126B2C + 24) != 255 )
      {
        v49 = 0;
        goto LABEL_77;
      }
      v49 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_126B2C + 28 * v49 + 24) != 255 )
        goto LABEL_77;
      v49 = v48 + 2;
      if ( v48 == 1 )
        v49 = 0;
    }
    if ( *((volatile uint8_t *)off_126B2C + 28 * v49 + 24) == 255 )
    {
      v50 = 0;
LABEL_70:
      llc_env_lookup(a2, (int)v50, 0);
      llc_env_lookup(v47, *(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72), 0);
      v28 = _frame.v65[0];
      goto LABEL_51;
    }
LABEL_77:
    v50 = (volatile char *)off_126B2C + 28 * v49;
    goto LABEL_70;
  }
  result = get_timeout_1000();
  v28 = _frame.v65[0];
  if ( _frame.v65[0] + 9000 - v25 + result < 0 )
  {
LABEL_19:
    v29 = (volatile char *)off_1269FC;
    goto LABEL_51;
  }
  return result;
}



// llc_irq_status_get @ 0x126b30
/* luna: Acknowledges interrupt-related register bits, then scans eligible LLC environments matching the IRQ selector and invokes PHY channel validation for th */
void llc_irq_status_get() {
  volatile int *v0; // r4
  int v1; // r5
  volatile uint8_t *v2; // r7
  int v3; // r8
  volatile uint32_t *v4; // r6

  v0 = *((volatile int **)off_126BAC + 2);
  v1 = *((volatile uint32_t *)off_126BB0 + 10);
  mmio_set_register_bit();
  *(volatile uint32_t *)off_126BB4 &= ~4u;
  if ( v0 )
  {
    v2 = (void *)(uintptr_t)(off_126BB8);
    v3 = dword_126BC0;
    v4 = (void *)(uintptr_t)(off_126BBC);
    do
    {
      while ( 1 )
      {
        if ( v0[18] == v1 && !*((volatile uint8_t *)v0 + 106) && *((volatile uint8_t *)v0 + 108) )
        {
          if ( v2[2] )
            *v4 &= ~0x80000000;
          if ( !*((volatile uint8_t *)v0 + 1224) || *(volatile uint8_t *)(v3 + 140 * *((volatile uint8_t *)v0 + 1225) + 133) )
            break;
        }
        v0 = (volatile int *)*v0;
        if ( !v0 )
          return;
      }
      phy_is_channel_valid(*((volatile uint8_t *)v0 + 116), 0, 0);
      v0 = (volatile int *)*v0;
    }
    while ( v0 );
  }
}



// llc_rx_complete @ 0x126bc4
/* luna: Checks matching link contexts for PHY-invalid channels, updates the shared invalid-channel count, and triggers RF state handling based on the result. */
int llc_rx_complete(int a1) {
  volatile uint32_t *v1; // r6
  volatile int *v2; // r4
  int v3; // r7
  int v4; // r5
  volatile uint32_t *v5; // r2
  volatile uint8_t *v6; // r1
  int v7; // r8
  int v8; // r7
  volatile uint8_t *v9; // r10
  int v10; // r9
  int v11; // r0
  char v12; // r11
  int v13; // r4
  int v14; // r5
  int v15; // r4

  v1 = (void *)(uintptr_t)(off_126CC4);
  v2 = *((volatile int **)off_126CC0 + 2);
  v3 = *((volatile uint8_t *)off_126CC4 + 89);
  ((int (*)())nullsub_8)(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = (void *)(uintptr_t)(off_126CC8);
  v6 = (void *)(uintptr_t)(off_126CCC);
  *(volatile uint32_t *)off_126CC8 |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_126CD0;
    v9 = (void *)(uintptr_t)(off_126CD4);
    v10 = dword_126CD8;
    do
    {
      while ( 1 )
      {
        if ( v4 == v2[18] && !*((volatile uint8_t *)v2 + 106) )
        {
          if ( *((volatile uint8_t *)v2 + 108) )
          {
            v11 = *((volatile uint8_t *)v2 + 116);
            if ( v11 != 255 && (!*((volatile uint8_t *)v2 + 1224) || *(volatile uint8_t *)(v10 + 140 * *((volatile uint8_t *)v2 + 1225) + 133)) )
              break;
          }
        }
        v2 = (volatile int *)*v2;
        if ( !v2 )
          goto LABEL_16;
      }
      v12 = *(volatile uint8_t *)(v4 + 16);
      *(volatile uint8_t *)(v4 + 16) = 6;
      if ( !phy_is_channel_valid(v11, v8, 0) )
      {
        ++v7;
        *v9 = 1;
      }
      *(volatile uint8_t *)(v4 + 16) = v12;
      v2 = (volatile int *)*v2;
    }
    while ( v2 );
LABEL_16:
    v3 = (v3 & ~0xFFu) | ((uint8_t)(v7) & 0xFFu);
  }
  v13 = *((volatile uint8_t *)v1 + 89);
  v14 = v1[11];
  *((volatile uint8_t *)v1 + 89) = v3;
  v15 = v7 - v13;
  if ( !v14 )
  {
    rf_write_reg();
    if ( v7 )
    {
      v15 = 0;
      --*((volatile uint8_t *)v1 + 89);
      return v15;
    }
    return 0;
  }
  if ( !v15 )
    return v15;
  *(volatile uint8_t *)(v14 + 16) = 3;
  rf_write_reg();
  return v15;
}



// llc_sem_lock @ 0x126cdc
/* luna: Processes the current LLC procedure request, updates the active procedure, and prepares a control response when required. */
int llc_sem_lock() {
  volatile uint32_t *v0; // r5
  volatile uint32_t *v1; // r6
  int v2; // r4
  volatile uint8_t *v3; // r0
  int v4; // r3
  int16_t v5; // r3
  BOOL v6; // r7
  int v7; // r3
  unsigned int v8; // r3
  int v9; // r5
  int v10; // r7
  volatile unsigned int *v11; // r2
  volatile uint32_t *v12; // r4
  int v13; // r1
  int v14; // r3
  unsigned int v16; // r3
  int v17; // r2
  int v18; // r3
  volatile uint32_t *v19; // r3
  int v20; // r0
  int v21; // r2
  volatile uint16_t *v22; // r1

  v0 = (void *)(uintptr_t)(off_126EC0);
  v1 = (void *)(uintptr_t)(off_126EC4);
  v2 = *((volatile uint32_t *)off_126EC0 + 11);
  check_boot_flag((volatile uint16_t *)(v2 + 4), 0);
  call_stack_helper(*(volatile char *)(v2 + 12));
  *(volatile uint32_t *)off_126EC8 = v1[*(volatile uint8_t *)(v2 + 4) + 5];
  if ( *(volatile uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(volatile uint8_t *)(v2 + 16) = 4;
      if ( *((volatile uint8_t *)v0 + 90) || !*((volatile uint8_t *)off_126ECC + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (volatile uint8_t *)tx_send_pdu(68, 13, 0, 4);
  v4 = *(volatile uint8_t *)(v2 + 24);
  *v3 = v4;
  if ( v4 == 4 )
  {
    v5 = *(volatile uint16_t *)(v2 + 14);
    if ( v5 )
      v5 = (v5 & ~0xFFu) | ((uint8_t)(1) & 0xFFu);
  }
  else
  {
    v5 = (v5 & ~0xFFu) | ((uint8_t)(0) & 0xFFu);
  }
  v6 = 0;
  v3[1] = v5;
  v3[3] = 0;
  v3[2] = *(volatile uint8_t *)(v2 + 26);
  rx_process_packet_1((int)(uintptr_t)(v3));
  v7 = v0[10];
  if ( v7 )
  {
    if ( *(volatile uint8_t *)(v2 + 24) == 4
      && *(volatile uint16_t *)(v7 + 4) == *(volatile uint16_t *)(v2 + 4)
      && *(volatile uint8_t *)(v7 + 13) == *(volatile uint8_t *)(v2 + 13)
      && *(volatile uint16_t *)(v7 + 6) == *(volatile uint16_t *)(v2 + 6)
      && *(volatile uint16_t *)(v7 + 8) == *(volatile uint16_t *)(v2 + 8) )
    {
      v6 = *(volatile uint16_t *)(v7 + 10) == *(volatile uint16_t *)(v2 + 10);
    }
LABEL_7:
    *(volatile uint8_t *)(v7 + 16) = 1;
    v8 = *(volatile uint8_t *)(v2 + 24);
    goto LABEL_8;
  }
  v6 = 0;
  v8 = *(volatile uint8_t *)(v2 + 24);
LABEL_8:
  v0[10] = v2;
  v0[11] = 0;
  *(volatile uint8_t *)(v2 + 16) = 4;
  if ( v8 > 2 )
  {
    if ( *((volatile uint8_t *)v0 + 90) && !v6 || !*((volatile uint8_t *)off_126ECC + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((volatile uint8_t *)off_126ECC + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  critical_section_enter_alt();
  v16 = *(volatile uint8_t *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(volatile int16_t **)off_126EE0;
      v18 = v1[1] | 0x2200;
      *(volatile uint32_t *)off_126EE4 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(volatile uint32_t *)off_126EFC << 28 )
      {
        mmio_write_field(dword_126F04, dword_126F00, 472);
        v18 = v1[1];
      }
      *(volatile uint32_t *)off_126EE8 = v18 | *v1;
      mac_write_header_word(141, 2, 255);
      if ( *((volatile uint8_t *)off_126EEC + 3851) == 1 && !*((volatile uint8_t *)off_126EF0 + 10) )
      {
        v19 = *(volatile uint32_t **)off_126EF4;
        if ( *(volatile uint32_t *)off_126EF4 )
        {
          v20 = dword_126EF8;
          do
          {
            v21 = v19[15];
            if ( v21 >= 0 )
            {
              v22 = (volatile uint16_t *)v19[4];
              if ( v22 )
              {
                if ( (*v22 & 0xFC) == 0x40 )
                  v19[15] = v21 | v20;
              }
            }
            v19 = (volatile uint32_t *)v19[1];
          }
          while ( v19 );
        }
      }
    }
LABEL_22:
    v11 = (volatile unsigned int *)off_126ED8;
    v12 = (void *)(uintptr_t)(off_126EDC);
    v13 = *(volatile uint32_t *)off_126ED8;
    v14 = *((volatile uint32_t *)off_126EDC + 1) | 2;
    *((volatile uint8_t *)v0 + 92) = (*(volatile uint32_t *)off_126ED8 & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return rf_write_reg();
  }
LABEL_10:
  llc_irq_status_get();
  v9 = *((volatile uint32_t *)off_126ED0 + 2);
  if ( v9 )
  {
    v10 = dword_126ED4;
    do
    {
      while ( *(volatile uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(volatile uint32_t *)v9;
        if ( !v9 )
          return rf_write_reg();
      }
      *(volatile uint8_t *)(v10 + 32 * *(volatile uint8_t *)(v9 + 107) + 31) = 1;
      get_hw_tsf(v9);
      v9 = *(volatile uint32_t *)v9;
    }
    while ( v9 );
  }
  return rf_write_reg();
}



// llc_flag_test_bit3 @ 0x126f08
/* luna: Selects a pending LLC request from the status flags, marks the previous request when replacing it, and invokes the semaphore lock when a request is ac */
int llc_flag_test_bit3() {
  volatile uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_126F34);
  if ( (*((volatile uint8_t *)off_126F34 + 88) & 8) != 0 )
  {
    v1 = dword_126F38;
    goto LABEL_6;
  }
  if ( (*((volatile uint8_t *)off_126F34 + 88) & 4) != 0 )
  {
    v1 = dword_126F3C;
LABEL_6:
    v2 = *((volatile uint32_t *)off_126F34 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(volatile uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return llc_sem_lock();
  }
  if ( *((volatile uint32_t *)off_126F34 + 11) )
    return llc_sem_lock();
  return result;
}



// llc_state_get @ 0x126f40
/* luna: Decrements the LLC event countdown and, when it expires with the pending-event flag set, clears the flag and invokes the kernel event handler. */
int llc_state_get() {
  char v0; // r3
  int result; // r0

  if ( *((volatile uint8_t *)off_126F6C + 89) )
  {
    v0 = *((volatile uint8_t *)off_126F6C + 89) - 1;
    *((volatile uint8_t *)off_126F6C + 89) = v0;
    if ( !v0 && *(volatile uint8_t *)off_126F70 == 1 )
    {
      *(volatile uint8_t *)off_126F70 = 0;
      ke_evt_handler();
      return llc_flag_test_bit3();
    }
  }
  return result;
}



// bt_event_handler_1 @ 0x126f74
/* luna: Processes a kernel event through LLC receive completion and falls back to testing LLC flag bit 3 when completion returns zero. */
int bt_event_handler_1() {
  int v0; // r0
  int result; // r0

  v0 = ke_evt_handler();
  result = llc_rx_complete(v0);
  if ( !result )
    return llc_flag_test_bit3();
  return result;
}



// llc_conn_command @ 0x126f8c
/* luna: Queues a requested connection if a switch is already pending; otherwise updates the active connection and processes the connection command. */
int llc_conn_command(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  volatile uint8_t *v4; // r0
  volatile int *v5; // r6
  int v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r0

  v1 = (void *)(uintptr_t)(off_12701C);
  v2 = result;
  if ( *((volatile uint32_t *)off_12701C + 11) )
  {
    *((volatile uint32_t *)off_12701C + 11) = result;
  }
  else
  {
    v3 = *((volatile uint32_t *)off_12701C + 10);
    if ( v3 == result )
    {
      *(volatile uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(volatile uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (volatile uint8_t *)tx_send_pdu(69, 13, 0, 1);
        *v4 = *(volatile uint8_t *)(v3 + 24);
        rx_process_packet_1((int)(uintptr_t)(v4));
      }
      if ( *((volatile int *)off_127020 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_127024 = 1;
        }
        v5 = (volatile int *)off_127028;
        ++*(volatile uint32_t *)off_127028;
        mmio_modify_bit(4);
        phy_get_cfg_ptr(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(volatile uint32_t *)off_127024;
          *v5 = v6;
          if ( !v6 )
          {
            if ( v7 )
              __enable_irq();
          }
        }
      }
      v1[11] = v2;
      *(volatile uint8_t *)(v2 + 16) = 2;
      v8 = (volatile uint32_t *)tx_send_pdu(140, 0, 255, 4);
      *v8 = dword_12702C;
      return (int)(uintptr_t)(rx_process_packet_1((int)(uintptr_t)(v8)));
    }
  }
  return result;
}



// llc_hw_reg_sync @ 0x127030
/* luna: Records a connection event and its target time, processes overdue RX events, and dispatches the connection command unless event handling is deferred. */
int llc_hw_reg_sync(int result) {
  volatile uint8_t *v1; // r5
  uint64_t v2; // r6
  int v3; // r4
  char v4; // r3
  int v5; // r4
  int v6; // r9
  int v7; // r10
  int v8; // r7
  int v9; // r3
  int v10; // r11
  int v11; // r1
  int v12; // r0

  v1 = (void *)(uintptr_t)(off_127144);
  v2 = (v2 & ~0xFFFFFFFFull) | ((uint32_t)(result) & 0xFFFFFFFFu);
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_12713C + 4) + *(volatile uint32_t *)(result + 20)) << 32);
  if ( result != dword_127140 || (*((volatile uint8_t *)off_127144 + 88) & 4) != 0 )
  {
    if ( *((volatile uint32_t *)off_127144 + 10) != result )
    {
      result = get_timeout_1000();
      v2 = (v2 & 0xFFFFFFFFull) | ((uint64_t)(uint32_t)(((uint32_t)(v2 >> 32) & 0xFFFFFFFFu) + (uint32_t)(4000 + result))) << 32;;
    }
    v3 = (uint8_t)v1[91];
    v4 = v1[88];
    *((volatile uint64_t *)v1 + 10) = v2;
    if ( v3 )
    {
      v1[88] = v4 | 0x40;
    }
    else
    {
      v1[88] = v4 & 0xBF;
      llc_env_get();
      result = llc_env_lookup(SHIDWORD(v2), 0, 0);
      v5 = *((volatile uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_127158;
        v7 = dword_12715C;
        v8 = dword_127148 - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(volatile uint32_t *)(v5 + 4);
          result = v10 - get_timeout_1000();
          if ( result + v8 >= 0 )
            break;
          v11 = *(volatile uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(volatile uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(volatile uint8_t *)(v12 + 106) )
          {
            if ( *(volatile uint8_t *)(v12 + 106) == 2 )
              v9 = *(volatile uint16_t *)(v12 + 222) << 10;
            result = llc_rx_event_save(v12, v11 + v9, 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = llc_rx_event_save(v12, v11 + *(volatile uint32_t *)(v7 + 696 * *(volatile uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((volatile uint32_t *)v1 + 11) )
      {
        if ( **(volatile int16_t **)off_12714C < 0 && (v1[88] & 0xC) == 0 )
          return irq_disable_mmio_write(dword_127154, dword_127150, 1698);
      }
      else
      {
        return llc_conn_command(v2);
      }
    }
  }
  else
  {
    *((volatile uint8_t *)off_127144 + 88) &= ~0x40u;
  }
  return result;
}



// llc_flag_test_bit0 @ 0x127160
/* luna: Advances the LLC flag state from bit 0 to bit 2 or from bit 1 to bit 3, then synchronizes the corresponding hardware register. */
int llc_flag_test_bit0() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_1271E8);
  v1 = *((volatile uint8_t *)off_1271E8 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(volatile int16_t **)off_1271EC < 0 && (v1 & 4) != 0 )
    {
      irq_disable_mmio_write(dword_1271FC, dword_1271F8, 1720);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xFA | 4;
    return llc_hw_reg_sync(dword_1271F0);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(volatile int16_t **)off_1271EC < 0 && (v1 & 8) != 0 )
    {
      irq_disable_mmio_write(dword_127200, dword_1271F8, 1731);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xF5 | 8;
    return llc_hw_reg_sync(dword_1271F4);
  }
  return result;
}



// llc_flag_test_bit4 @ 0x127204
/* luna: If context flag bit 4 is clear, sets it and either copies data into the context buffer or calls the bit-0 handler based on the byte at offset 90. */
int llc_flag_test_bit4() {
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127234);
  if ( (*((volatile uint8_t *)off_127234 + 88) & 0x10) == 0 )
  {
    v1 = *((volatile uint8_t *)off_127234 + 90);
    *((volatile uint8_t *)off_127234 + 88) |= 0x10u;
    if ( v1 )
      return mem_copy_util((void *)(uintptr_t)((int)v0 + 48), *((volatile uint32_t *)off_127238 + 4) + 30000);
    else
      return llc_flag_test_bit0();
  }
  return result;
}



