// llm_ctrl_msg_handler @ 0x126714
int llm_ctrl_msg_handler(int a1, int a2, int a3) {
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

  v6 = mem_word_load(dword_1267BC);
  v7 = v6;
  if ( **(volatile int16_t **)off_1267C0 < 0 && !v6 )
    mmio_clear_register((int)aChSwitchNull, (int)aChanSwitchAllo, 227);
  v8 = (void *)(uintptr_t)(off_1267C4);
  v9 = (volatile char *)off_1267C4 + 32;
  v10 = *((volatile uint32_t *)off_1267C4 + 8);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = cmd_handler_a((int)v9, v7);
  if ( !v10 )
  {
    v8[18] = (int)(uintptr_t)(v7);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_1267D0 = 1;
    }
    v12 = (volatile int *)off_1267D8;
    v13 = v7[1];
    v14 = (*(volatile uint32_t *)0x40501010u);
    v15 = *(volatile uint32_t *)off_1267D8;
    v16 = *(volatile uint32_t *)off_1267D8 + 1;
    *(volatile uint32_t *)off_1267D8 = v16;
    if ( (int)(v13 - v14 - 64) >= 0 )
    {
      result = unknown_worker((volatile uint32_t *)dword_1267DC, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(volatile uint32_t *)off_1267D0;
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
        v17 = (volatile int *)off_1267D0;
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


// ke_task_poll @ 0x1267e0
volatile uint32_t *ke_task_poll() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  result = mem_word_load(dword_126818);
  a2 = result;
  if ( result )
  {
    v1 = (void *)(uintptr_t)(off_12681C);
    fault_handler((int)(uintptr_t)((volatile uint32_t *)dword_126820));
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      cmd_handler_a(v3, v2);
      result = mem_word_load(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}


// bt_link_cfg_set @ 0x126824
int bt_link_cfg_set(int a1, int a2, unsigned int a3) {
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
  v3 = dword_126B38;
  v4 = *((volatile uint32_t *)off_126B34 + 4);
  v5 = *(volatile uint32_t *)(a1 + 72);
  v6 = *(volatile uint8_t *)(v4 + 8);
  v7 = dword_126B38 + 1320 * v6;
  _frame.v52 = *(volatile uint32_t *)(v4 + 4) - 4000;
  _frame.v53 = _frame.v52 - a2 - get_constant_1000();
  if ( *(volatile uint32_t *)(v7 + 72) != v5 )
  {
    _frame.v57 = *(volatile uint32_t *)(v4 + 4);
    v10 = get_constant_1000();
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
          return llm_ctrl_msg_handler(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
LABEL_31:
        ke_task_poll();
        v14 = a2;
        return llm_ctrl_msg_handler(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
      }
      v30 = v3 + 1320 * v13;
      v31 = bt_runtime_check(v30, (void *)(&_frame.v64), (void *)(_frame.v65));
      v14 = _frame.v64 - 4000 - get_constant_1000();
      _frame.v64 = v14;
      if ( !v31 )
      {
        if ( v14 + _frame.v61 - _frame.v63 >= 0 )
          v14 = _frame.v58;
        if ( _frame.v61 - _frame.v63 + _frame.v65[0] + 9000 + get_constant_1000() < 0 )
        {
          llm_ctrl_msg_handler(v14, *(volatile uint32_t *)(v30 + 72), 0);
          v14 = _frame.v58;
          llm_ctrl_msg_handler(_frame.v65[0], v5, 0);
        }
        goto LABEL_6;
      }
      if ( _frame.v65[0] + 9000 + _frame.v61 - _frame.v63 + get_constant_1000() < 0 )
      {
        llm_ctrl_msg_handler(a2, *(volatile uint32_t *)(v30 + 72), 0);
        llm_ctrl_msg_handler(_frame.v65[0], v5, 0);
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
if ( bt_runtime_check(v16, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
      {
        if ( _frame.v64 - _frame.v54 + _frame.v61 >= 0 )
          goto LABEL_6;
        v18 = _frame.v64 - _frame.v65[0];
        if ( v18 > get_constant_1000() + 9000 )
        {
          llm_ctrl_msg_handler(_frame.v65[0], v17, 0);
          v19 = _frame.v64;
          v20 = v19 - 4000 - get_constant_1000();
          v14 = _frame.v58;
          llm_ctrl_msg_handler(v20, *(volatile uint32_t *)(v16 + 72), 0);
          goto LABEL_6;
        }
      }
    }
    else
    {
      if ( _frame.v58 - _frame.v64 < 0 )
        goto LABEL_26;
      v32 = _frame.v64 - a2;
      if ( v32 > get_constant_1000() + 9000 )
      {
        llm_ctrl_msg_handler(a2, v17, 0);
        v44 = _frame.v64;
        v45 = get_constant_1000();
        llm_ctrl_msg_handler(v44 - 4000 - v45, *(volatile uint32_t *)(v16 + 72), 0);
      }
      v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
        goto LABEL_6;
    }
    v14 = _frame.v58;
    goto LABEL_6;
  }
  result = get_constant_1000();
  _frame.v55 = _frame.v53 - 4000 - result;
  if ( _frame.v55 <= 4999 )
    return result;
  _frame.v59 = *(volatile uint32_t *)(v4 + 4);
  v21 = get_constant_1000();
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
        v29 = (volatile char *)off_126B3C;
        goto LABEL_39;
      }
      v29 = (volatile char *)off_126C6C;
      v28 = a2 - a3 + v34;
    }
    else
    {
      bt_runtime_check(v3 + 1320 * v33, (void *)(&_frame.v64), (void *)(_frame.v65));
      v40 = _frame.v64;
      result = get_constant_1000();
      if ( _frame.v56 - v40 + result < 0 )
        return result;
      v41 = _frame.v64;
      v29 = (volatile char *)off_126B3C;
      v28 = v41 - 4000 - get_constant_1000();
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
        v36 = (volatile uint8_t *)off_126C6C;
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
      llm_ctrl_msg_handler(v28, (int)v36, 0);
      return llm_ctrl_msg_handler(v25, v5, v4);
    }
LABEL_39:
    ke_task_poll();
    v28 = a2;
    goto LABEL_40;
  }
if ( bt_runtime_check(v3 + 1320 * _frame.v62, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v43 = _frame.v64;
    v28 = _frame.v65[0];
    if ( v43 - _frame.v59 + v23 - get_constant_1000() < 0 )
    {
      v46 = _frame.v64;
      v25 = v46 - 4000 - get_constant_1000();
    }
    result = v25 - v28 - 9000 - get_constant_1000();
    if ( result >= 0 )
      goto LABEL_19;
    return result;
  }
  v26 = get_constant_1000();
  v27 = _frame.v64;
  if ( 5000 - _frame.v64 + a2 + 2 * (v26 + 4000) < 0 )
  {
    if ( v27 - _frame.v59 + v23 - get_constant_1000() < 0 )
    {
      v51 = _frame.v64;
      v47 = v51 - 4000 - get_constant_1000();
    }
    else
    {
      v47 = v25;
    }
    if ( _frame.v65[0] + 9000 - v25 + get_constant_1000() >= 0 )
    {
      v29 = (volatile char *)off_126C6C;
      v25 = v47;
      goto LABEL_39;
    }
    v29 = (volatile char *)off_126C6C;
    v48 = *(volatile uint8_t *)(*(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72) + 24);
    v49 = v48 + 1;
    if ( v48 == 2 )
    {
      if ( *((volatile uint8_t *)off_126C6C + 24) != 255 )
      {
        v49 = 0;
        goto LABEL_77;
      }
      v49 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_126C6C + 28 * v49 + 24) != 255 )
        goto LABEL_77;
      v49 = v48 + 2;
      if ( v48 == 1 )
        v49 = 0;
    }
    if ( *((volatile uint8_t *)off_126C6C + 28 * v49 + 24) == 255 )
    {
      v50 = 0;
LABEL_70:
      llm_ctrl_msg_handler(a2, (int)v50, 0);
      llm_ctrl_msg_handler(v47, *(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72), 0);
      v28 = _frame.v65[0];
      goto LABEL_51;
    }
LABEL_77:
    v50 = (volatile char *)off_126C6C + 28 * v49;
    goto LABEL_70;
  }
  result = get_constant_1000();
  v28 = _frame.v65[0];
  if ( _frame.v65[0] + 9000 - v25 + result < 0 )
  {
LABEL_19:
    v29 = (volatile char *)off_126B3C;
    goto LABEL_51;
  }
  return result;
}



// rf_mmio_write @ 0x126c70
void rf_mmio_write() {
  volatile int *v0; // r4
  int v1; // r5
  volatile uint8_t *v2; // r7
  int v3; // r8
  volatile uint32_t *v4; // r6

  v0 = *((volatile int **)off_126CEC + 2);
  v1 = *((volatile uint32_t *)off_126CF0 + 10);
  mmio_set_radio_bit();
  *(volatile uint32_t *)off_126CF4 &= ~4u;
  if ( v0 )
  {
    v2 = (void *)(uintptr_t)(off_126CF8);
    v3 = dword_126D00;
    v4 = (void *)(uintptr_t)(off_126CFC);
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
      phy_channel_is_5g(*((volatile uint8_t *)v0 + 116), 0, 0);
      v0 = (volatile int *)*v0;
    }
    while ( v0 );
  }
}



// rf_mmio_read @ 0x126d04
int rf_mmio_read(int a1) {
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

  v1 = (void *)(uintptr_t)(off_126E04);
  v2 = *((volatile int **)off_126E00 + 2);
  v3 = *((volatile uint8_t *)off_126E04 + 89);
  ((int (*)())nullsub_8)(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = (void *)(uintptr_t)(off_126E08);
  v6 = (void *)(uintptr_t)(off_126E0C);
  *(volatile uint32_t *)off_126E08 |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_126E10;
    v9 = (void *)(uintptr_t)(off_126E14);
    v10 = dword_126E18;
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
      if ( !phy_channel_is_5g(v11, v8, 0) )
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
    set_clock_divisor();
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
  set_clock_divisor();
  return v15;
}



// ctrl_poll_events @ 0x126e1c
int ctrl_poll_events() {
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

  v0 = (void *)(uintptr_t)(off_127000);
  v1 = (void *)(uintptr_t)(off_127004);
  v2 = *((volatile uint32_t *)off_127000 + 11);
  rf_enable((volatile uint16_t *)(v2 + 4), 0);
  util_format(*(volatile char *)(v2 + 12));
  *(volatile uint32_t *)off_127008 = v1[*(volatile uint8_t *)(v2 + 4) + 5];
  if ( *(volatile uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(volatile uint8_t *)(v2 + 16) = 4;
      if ( *((volatile uint8_t *)v0 + 90) || !*((volatile uint8_t *)off_12700C + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (volatile uint8_t *)ke_msg_alloc(68, 13, 0, 4);
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
  ke_msg_send_2((int)(uintptr_t)(v3));
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
    if ( *((volatile uint8_t *)v0 + 90) && !v6 || !*((volatile uint8_t *)off_12700C + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((volatile uint8_t *)off_12700C + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  fatal_error_handler();
  v16 = *(volatile uint8_t *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(volatile int16_t **)off_127020;
      v18 = v1[1] | 0x2200;
      *(volatile uint32_t *)off_127024 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(volatile uint32_t *)off_12703C << 28 )
      {
        call_shared_handler(dword_127044, dword_127040, 472);
        v18 = v1[1];
      }
      *(volatile uint32_t *)off_127028 = v18 | *v1;
      ke_msg_send_no_param(141, 2, 255);
      if ( *((volatile uint8_t *)off_12702C + 3851) == 1 && !*((volatile uint8_t *)off_127030 + 10) )
      {
        v19 = *(volatile uint32_t **)off_127034;
        if ( *(volatile uint32_t *)off_127034 )
        {
          v20 = dword_127038;
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
    v11 = (volatile unsigned int *)off_127018;
    v12 = (void *)(uintptr_t)(off_12701C);
    v13 = *(volatile uint32_t *)off_127018;
    v14 = *((volatile uint32_t *)off_12701C + 1) | 2;
    *((volatile uint8_t *)v0 + 92) = (*(volatile uint32_t *)off_127018 & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return set_clock_divisor();
  }
LABEL_10:
  rf_mmio_write();
  v9 = *((volatile uint32_t *)off_127010 + 2);
  if ( v9 )
  {
    v10 = dword_127014;
    do
    {
      while ( *(volatile uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(volatile uint32_t *)v9;
        if ( !v9 )
          return set_clock_divisor();
      }
      *(volatile uint8_t *)(v10 + 32 * *(volatile uint8_t *)(v9 + 107) + 31) = 1;
      read_descriptor(v9);
      v9 = *(volatile uint32_t *)v9;
    }
    while ( v9 );
  }
  return set_clock_divisor();
}



// ctrl_check_flags @ 0x127048
int ctrl_check_flags() {
  volatile uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127074);
  if ( (*((volatile uint8_t *)off_127074 + 88) & 8) != 0 )
  {
    v1 = dword_127078;
    goto LABEL_6;
  }
  if ( (*((volatile uint8_t *)off_127074 + 88) & 4) != 0 )
  {
    v1 = dword_12707C;
LABEL_6:
    v2 = *((volatile uint32_t *)off_127074 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(volatile uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return ctrl_poll_events();
  }
  if ( *((volatile uint32_t *)off_127074 + 11) )
    return ctrl_poll_events();
  return result;
}



// ctrl_timer_tick @ 0x127080
int ctrl_timer_tick() {
  char v0; // r3
  int result; // r0

  if ( *((volatile uint8_t *)off_1270AC + 89) )
  {
    v0 = *((volatile uint8_t *)off_1270AC + 89) - 1;
    *((volatile uint8_t *)off_1270AC + 89) = v0;
    if ( !v0 && *(volatile uint8_t *)off_1270B0 == 1 )
    {
      *(volatile uint8_t *)off_1270B0 = 0;
      shared_s16_worker();
      return ctrl_check_flags();
    }
  }
  return result;
}



// check_hw_state_1 @ 0x1270b4
int check_hw_state_1() {
  int v0; // r0
  int result; // r0

  v0 = shared_s16_worker();
  result = rf_mmio_read(v0);
  if ( !result )
    return ctrl_check_flags();
  return result;
}



// ctrl_register_handler @ 0x1270cc
int ctrl_register_handler(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  volatile uint8_t *v4; // r0
  volatile int *v5; // r6
  int v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r0

  v1 = (void *)(uintptr_t)(off_12715C);
  v2 = result;
  if ( *((volatile uint32_t *)off_12715C + 11) )
  {
    *((volatile uint32_t *)off_12715C + 11) = result;
  }
  else
  {
    v3 = *((volatile uint32_t *)off_12715C + 10);
    if ( v3 == result )
    {
      *(volatile uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(volatile uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (volatile uint8_t *)ke_msg_alloc(69, 13, 0, 1);
        *v4 = *(volatile uint8_t *)(v3 + 24);
        ke_msg_send_2((int)(uintptr_t)(v4));
      }
      if ( *((volatile int *)off_127160 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_127164 = 1;
        }
        v5 = (volatile int *)off_127168;
        ++*(volatile uint32_t *)off_127168;
        mmio_set_bit_1(4);
        phy_band_validate(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(volatile uint32_t *)off_127164;
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
      v8 = (volatile uint32_t *)ke_msg_alloc(140, 0, 255, 4);
      *v8 = dword_12716C;
      return (int)(uintptr_t)(ke_msg_send_2((int)(uintptr_t)(v8)));
    }
  }
  return result;
}



// dma_setup_transfer @ 0x127170
int dma_setup_transfer(int result) {
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

  v1 = (void *)(uintptr_t)(off_127284);
  v2 = (v2 & ~0xFFFFFFFFull) | ((uint32_t)(result) & 0xFFFFFFFFu);
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_12727C + 4) + *(volatile uint32_t *)(result + 20)) << 32);
  if ( result != dword_127280 || (*((volatile uint8_t *)off_127284 + 88) & 4) != 0 )
  {
    if ( *((volatile uint32_t *)off_127284 + 10) != result )
    {
      result = get_constant_1000();
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
      ke_task_poll();
      result = llm_ctrl_msg_handler(SHIDWORD(v2), 0, 0);
      v5 = *((volatile uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_127298;
        v7 = dword_12729C;
        v8 = dword_127288 - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(volatile uint32_t *)(v5 + 4);
          result = v10 - get_constant_1000();
          if ( result + v8 >= 0 )
            break;
          v11 = *(volatile uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(volatile uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(volatile uint8_t *)(v12 + 106) )
          {
            if ( *(volatile uint8_t *)(v12 + 106) == 2 )
              v9 = *(volatile uint16_t *)(v12 + 222) << 10;
            result = llm_scan_sm_execute(v12, v11 + v9, 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = llm_scan_sm_execute(v12, v11 + *(volatile uint32_t *)(v7 + 696 * *(volatile uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((volatile uint32_t *)v1 + 11) )
      {
        if ( **(volatile int16_t **)off_12728C < 0 && (v1[88] & 0xC) == 0 )
          return mmio_clear_register(dword_127294, dword_127290, 1698);
      }
      else
      {
        return ctrl_register_handler(v2);
      }
    }
  }
  else
  {
    *((volatile uint8_t *)off_127284 + 88) &= ~0x40u;
  }
  return result;
}



// rf_read_calibration @ 0x1272a0
int rf_read_calibration() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127328);
  v1 = *((volatile uint8_t *)off_127328 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(volatile int16_t **)off_12732C < 0 && (v1 & 4) != 0 )
    {
      mmio_clear_register(dword_12733C, dword_127338, 1720);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xFA | 4;
    return dma_setup_transfer(dword_127330);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(volatile int16_t **)off_12732C < 0 && (v1 & 8) != 0 )
    {
      mmio_clear_register(dword_127340, dword_127338, 1731);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xF5 | 8;
    return dma_setup_transfer(dword_127334);
  }
  return result;
}



// scan_start_request @ 0x127344
int scan_start_request() {
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127374);
  if ( (*((volatile uint8_t *)off_127374 + 88) & 0x10) == 0 )
  {
    v1 = *((volatile uint8_t *)off_127374 + 90);
    *((volatile uint8_t *)off_127374 + 88) |= 0x10u;
    if ( v1 )
      return unknown_worker((void *)(uintptr_t)((int)v0 + 48), *((volatile uint32_t *)off_127378 + 4) + 30000);
    else
      return rf_read_calibration();
  }
  return result;
}



