// send_event_to_host @ 0x126938
int send_event_to_host(int a1, int a2, int a3) {
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

  v6 = list_pop_front(dword_1269E0);
  v7 = v6;
  if ( **(volatile int16_t **)off_1269E4 < 0 && !v6 )
    mmio_irq_clear((int)aChSwitchNull, (int)aChanSwitchAllo, 227);
  v8 = (void *)(uintptr_t)(off_1269E8);
  v9 = (volatile char *)off_1269E8 + 32;
  v10 = *((volatile uint32_t *)off_1269E8 + 8);
  v7[3] = a3;
  v7[1] = a1;
  v7[2] = a2;
  result = check_abort_flag((int)v9, v7);
  if ( !v10 )
  {
    v8[18] = (int)(uintptr_t)(v7);
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_1269F4 = 1;
    }
    v12 = (volatile int *)off_1269FC;
    v13 = v7[1];
    v14 = (*(volatile uint32_t *)0x40501010u);
    v15 = *(volatile uint32_t *)off_1269FC;
    v16 = *(volatile uint32_t *)off_1269FC + 1;
    *(volatile uint32_t *)off_1269FC = v16;
    if ( (int)(v13 - v14 - 64) >= 0 )
    {
      result = ke_event_lock((volatile uint32_t *)dword_126A00, v13);
      if ( *v12 )
      {
        v19 = *v12 - 1;
        v20 = *(volatile uint32_t *)off_1269F4;
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
        v17 = (volatile int *)off_1269F4;
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


// hci_acl_buf_alloc @ 0x126a04
volatile uint32_t *hci_acl_buf_alloc() {
  volatile uint32_t *result; // r0
  volatile uint32_t *v1; // r4
  volatile uint32_t *v2; // r1
  int v3; // r5
  int v4; // r4
  volatile uint32_t *a2; // [sp+4h] [bp-8h]

  result = list_pop_front(dword_126A3C);
  a2 = result;
  if ( result )
  {
    v1 = (void *)(uintptr_t)(off_126A40);
    ke_event_set_lock((int)(uintptr_t)((volatile uint32_t *)dword_126A44));
    v2 = a2;
    v1[18] = 0;
    v3 = (int)(v1 + 6);
    v4 = (int)(v1 + 8);
    do
    {
      check_abort_flag(v3, v2);
      result = list_pop_front(v4);
      v2 = result;
    }
    while ( result );
  }
  return result;
}


// hci_send_acl @ 0x126a48
int hci_send_acl(int a1, int a2, unsigned int a3) {
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
  v3 = dword_126D5C;
  v4 = *((volatile uint32_t *)off_126D58 + 4);
  v5 = *(volatile uint32_t *)(a1 + 72);
  v6 = *(volatile uint8_t *)(v4 + 8);
  v7 = dword_126D5C + 1320 * v6;
  _frame.v52 = *(volatile uint32_t *)(v4 + 4) - 4000;
  _frame.v53 = _frame.v52 - a2 - return_1000();
  if ( *(volatile uint32_t *)(v7 + 72) != v5 )
  {
    _frame.v57 = *(volatile uint32_t *)(v4 + 4);
    v10 = return_1000();
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
          return send_event_to_host(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
LABEL_31:
        hci_acl_buf_alloc();
        v14 = a2;
        return send_event_to_host(v14, *(volatile uint32_t *)(v3 + 1320 * v6 + 72), v4);
      }
      v30 = v3 + 1320 * v13;
      v31 = util_feature_get(v30, (void *)(&_frame.v64), (void *)(_frame.v65));
      v14 = _frame.v64 - 4000 - return_1000();
      _frame.v64 = v14;
      if ( !v31 )
      {
        if ( v14 + _frame.v61 - _frame.v63 >= 0 )
          v14 = _frame.v58;
        if ( _frame.v61 - _frame.v63 + _frame.v65[0] + 9000 + return_1000() < 0 )
        {
          send_event_to_host(v14, *(volatile uint32_t *)(v30 + 72), 0);
          v14 = _frame.v58;
          send_event_to_host(_frame.v65[0], v5, 0);
        }
        goto LABEL_6;
      }
      if ( _frame.v65[0] + 9000 + _frame.v61 - _frame.v63 + return_1000() < 0 )
      {
        send_event_to_host(a2, *(volatile uint32_t *)(v30 + 72), 0);
        send_event_to_host(_frame.v65[0], v5, 0);
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
if ( util_feature_get(v16, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
      {
        if ( _frame.v64 - _frame.v54 + _frame.v61 >= 0 )
          goto LABEL_6;
        v18 = _frame.v64 - _frame.v65[0];
        if ( v18 > return_1000() + 9000 )
        {
          send_event_to_host(_frame.v65[0], v17, 0);
          v19 = _frame.v64;
          v20 = v19 - 4000 - return_1000();
          v14 = _frame.v58;
          send_event_to_host(v20, *(volatile uint32_t *)(v16 + 72), 0);
          goto LABEL_6;
        }
      }
    }
    else
    {
      if ( _frame.v58 - _frame.v64 < 0 )
        goto LABEL_26;
      v32 = _frame.v64 - a2;
      if ( v32 > return_1000() + 9000 )
      {
        send_event_to_host(a2, v17, 0);
        v44 = _frame.v64;
        v45 = return_1000();
        send_event_to_host(v44 - 4000 - v45, *(volatile uint32_t *)(v16 + 72), 0);
      }
      v14 = _frame.v65[0];
      if ( _frame.v58 - _frame.v65[0] >= 0 )
        goto LABEL_6;
    }
    v14 = _frame.v58;
    goto LABEL_6;
  }
  result = return_1000();
  _frame.v55 = _frame.v53 - 4000 - result;
  if ( _frame.v55 <= 4999 )
    return result;
  _frame.v59 = *(volatile uint32_t *)(v4 + 4);
  v21 = return_1000();
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
        v29 = (volatile char *)off_126D60;
        goto LABEL_39;
      }
      v29 = (volatile char *)off_126E90;
      v28 = a2 - a3 + v34;
    }
    else
    {
      util_feature_get(v3 + 1320 * v33, (void *)(&_frame.v64), (void *)(_frame.v65));
      v40 = _frame.v64;
      result = return_1000();
      if ( _frame.v56 - v40 + result < 0 )
        return result;
      v41 = _frame.v64;
      v29 = (volatile char *)off_126D60;
      v28 = v41 - 4000 - return_1000();
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
        v36 = (volatile uint8_t *)off_126E90;
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
      send_event_to_host(v28, (int)v36, 0);
      return send_event_to_host(v25, v5, v4);
    }
LABEL_39:
    hci_acl_buf_alloc();
    v28 = a2;
    goto LABEL_40;
  }
if ( util_feature_get(v3 + 1320 * _frame.v62, (void *)(&_frame.v64), (void *)(_frame.v65)) ) { v43 = _frame.v64;
    v28 = _frame.v65[0];
    if ( v43 - _frame.v59 + v23 - return_1000() < 0 )
    {
      v46 = _frame.v64;
      v25 = v46 - 4000 - return_1000();
    }
    result = v25 - v28 - 9000 - return_1000();
    if ( result >= 0 )
      goto LABEL_19;
    return result;
  }
  v26 = return_1000();
  v27 = _frame.v64;
  if ( 5000 - _frame.v64 + a2 + 2 * (v26 + 4000) < 0 )
  {
    if ( v27 - _frame.v59 + v23 - return_1000() < 0 )
    {
      v51 = _frame.v64;
      v47 = v51 - 4000 - return_1000();
    }
    else
    {
      v47 = v25;
    }
    if ( _frame.v65[0] + 9000 - v25 + return_1000() >= 0 )
    {
      v29 = (volatile char *)off_126E90;
      v25 = v47;
      goto LABEL_39;
    }
    v29 = (volatile char *)off_126E90;
    v48 = *(volatile uint8_t *)(*(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72) + 24);
    v49 = v48 + 1;
    if ( v48 == 2 )
    {
      if ( *((volatile uint8_t *)off_126E90 + 24) != 255 )
      {
        v49 = 0;
        goto LABEL_77;
      }
      v49 = 1;
    }
    else
    {
      if ( *((volatile uint8_t *)off_126E90 + 28 * v49 + 24) != 255 )
        goto LABEL_77;
      v49 = v48 + 2;
      if ( v48 == 1 )
        v49 = 0;
    }
    if ( *((volatile uint8_t *)off_126E90 + 28 * v49 + 24) == 255 )
    {
      v50 = 0;
LABEL_70:
      send_event_to_host(a2, (int)v50, 0);
      send_event_to_host(v47, *(volatile uint32_t *)(v3 + 1320 * _frame.v62 + 72), 0);
      v28 = _frame.v65[0];
      goto LABEL_51;
    }
LABEL_77:
    v50 = (volatile char *)off_126E90 + 28 * v49;
    goto LABEL_70;
  }
  result = return_1000();
  v28 = _frame.v65[0];
  if ( _frame.v65[0] + 9000 - v25 + result < 0 )
  {
LABEL_19:
    v29 = (volatile char *)off_126D60;
    goto LABEL_51;
  }
  return result;
}



// patch_mmio_write @ 0x126e94
void patch_mmio_write() {
  volatile int *v0; // r4
  int v1; // r5
  volatile uint8_t *v2; // r7
  int v3; // r8
  volatile uint32_t *v4; // r6

  v0 = *((volatile int **)off_126F10 + 2);
  v1 = *((volatile uint32_t *)off_126F14 + 10);
  enable_irq();
  *(volatile uint32_t *)off_126F18 &= ~4u;
  if ( v0 )
  {
    v2 = (void *)(uintptr_t)(off_126F1C);
    v3 = dword_126F24;
    v4 = (void *)(uintptr_t)(off_126F20);
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
      phy_channel_validate(*((volatile uint8_t *)v0 + 116), 0, 0);
      v0 = (volatile int *)*v0;
    }
    while ( v0 );
  }
}



// timer_tick_handler @ 0x126f28
int timer_tick_handler(int a1) {
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

  v1 = (void *)(uintptr_t)(off_127028);
  v2 = *((volatile int **)off_127024 + 2);
  v3 = *((volatile uint8_t *)off_127028 + 89);
  ((int (*)())nullsub_8)(a1);
  v4 = v1[10];
  if ( !v4 )
    return 0;
  v5 = (void *)(uintptr_t)(off_12702C);
  v6 = (void *)(uintptr_t)(off_127030);
  *(volatile uint32_t *)off_12702C |= 4u;
  v7 = v3;
  if ( v6[2] )
    v5[250] |= 0x80000000;
  if ( v2 )
  {
    v8 = dword_127034;
    v9 = (void *)(uintptr_t)(off_127038);
    v10 = dword_12703C;
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
      if ( !phy_channel_validate(v11, v8, 0) )
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
    write_pmu_control();
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
  write_pmu_control();
  return v15;
}



// clear_tx_buffer @ 0x127040
int clear_tx_buffer() {
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
  int v19; // r3
  volatile uint32_t *v20; // r3
  int v21; // r0
  int v22; // r2
  volatile uint16_t *v23; // r1

  v0 = (void *)(uintptr_t)(off_127224);
  v1 = (void *)(uintptr_t)(off_127228);
  v2 = *((volatile uint32_t *)off_127224 + 11);
  phy_set_channel((volatile uint16_t *)(v2 + 4), 0);
  util_format_string(*(volatile char *)(v2 + 12));
  *(volatile uint32_t *)off_12722C = v1[*(volatile uint8_t *)(v2 + 4) + 5];
  if ( *(volatile uint8_t *)(v2 + 24) == 3 )
  {
    v7 = v0[10];
    if ( !v7 )
    {
      v0[10] = v2;
      v0[11] = 0;
      *(volatile uint8_t *)(v2 + 16) = 4;
      if ( *((volatile uint8_t *)v0 + 90) || !*((volatile uint8_t *)off_127230 + 511) )
        goto LABEL_29;
      goto LABEL_27;
    }
    v6 = 0;
    goto LABEL_7;
  }
  v3 = (volatile uint8_t *)bt_buf_alloc(68, 13, 0, 4);
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
  hci_evt_send((int)(uintptr_t)(v3));
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
    if ( *((volatile uint8_t *)v0 + 90) && !v6 || !*((volatile uint8_t *)off_127230 + 511) )
    {
      if ( v8 == 3 )
        goto LABEL_29;
      goto LABEL_22;
    }
  }
  else if ( !*((volatile uint8_t *)off_127230 + 511) )
  {
    goto LABEL_10;
  }
LABEL_27:
  sleep_critical_exit();
  v16 = *(volatile uint8_t *)(v2 + 24);
  if ( v16 > 2 )
  {
    if ( v16 == 3 )
    {
LABEL_29:
      v17 = **(volatile int16_t **)off_127244;
      v18 = v1[1] | 0x2200;
      *(volatile uint32_t *)off_127248 = 0;
      v1[1] = v18;
      if ( v17 < 0 && *(volatile uint32_t *)off_127260 << 28 )
      {
        mmio_field_update(dword_127268, dword_127264, 472);
        v18 = v1[1];
      }
      v19 = v18 | *v1;
      *(volatile uint32_t *)off_12724C = v19;
      ((int (*)())hci_evt_alloc_send)(141, 2, 255, v19);
      if ( *((volatile uint8_t *)off_127250 + 3851) == 1 && !*((volatile uint8_t *)off_127254 + 10) )
      {
        v20 = *(volatile uint32_t **)off_127258;
        if ( *(volatile uint32_t *)off_127258 )
        {
          v21 = dword_12725C;
          do
          {
            v22 = v20[15];
            if ( v22 >= 0 )
            {
              v23 = (volatile uint16_t *)v20[4];
              if ( v23 )
              {
                if ( (*v23 & 0xFC) == 0x40 )
                  v20[15] = v22 | v21;
              }
            }
            v20 = (volatile uint32_t *)v20[1];
          }
          while ( v20 );
        }
      }
    }
LABEL_22:
    v11 = (volatile unsigned int *)off_12723C;
    v12 = (void *)(uintptr_t)(off_127240);
    v13 = *(volatile uint32_t *)off_12723C;
    v14 = *((volatile uint32_t *)off_127240 + 1) | 2;
    *((volatile uint8_t *)v0 + 92) = (*(volatile uint32_t *)off_12723C & 4) != 0;
    *v11 = v13 & 0xFFFFFFFB;
    v12[1] = v14;
    return write_pmu_control();
  }
LABEL_10:
  patch_mmio_write();
  v9 = *((volatile uint32_t *)off_127234 + 2);
  if ( v9 )
  {
    v10 = dword_127238;
    do
    {
      while ( *(volatile uint32_t *)(v9 + 72) != v2 )
      {
        v9 = *(volatile uint32_t *)v9;
        if ( !v9 )
          return write_pmu_control();
      }
      *(volatile uint8_t *)(v10 + 32 * *(volatile uint8_t *)(v9 + 107) + 31) = 1;
      wlc_bsscfg_detach(v9);
      v9 = *(volatile uint32_t *)v9;
    }
    while ( v9 );
  }
  return write_pmu_control();
}



// tx_ready_check @ 0x12726c
int tx_ready_check() {
  volatile uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127298);
  if ( (*((volatile uint8_t *)off_127298 + 88) & 8) != 0 )
  {
    v1 = dword_12729C;
    goto LABEL_6;
  }
  if ( (*((volatile uint8_t *)off_127298 + 88) & 4) != 0 )
  {
    v1 = dword_1272A0;
LABEL_6:
    v2 = *((volatile uint32_t *)off_127298 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(volatile uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return clear_tx_buffer();
  }
  if ( *((volatile uint32_t *)off_127298 + 11) )
    return clear_tx_buffer();
  return result;
}



// timeout_decrement @ 0x1272a4
int timeout_decrement() {
  char v0; // r3
  int result; // r0

  if ( *((volatile uint8_t *)off_1272D0 + 89) )
  {
    v0 = *((volatile uint8_t *)off_1272D0 + 89) - 1;
    *((volatile uint8_t *)off_1272D0 + 89) = v0;
    if ( !v0 && *(volatile uint8_t *)off_1272D4 == 1 )
    {
      *(volatile uint8_t *)off_1272D4 = 0;
      mac_cmd_send();
      return tx_ready_check();
    }
  }
  return result;
}



// check_irq_handler @ 0x1272d8
int check_irq_handler() {
  int v0; // r0
  int result; // r0

  v0 = mac_cmd_send();
  result = timer_tick_handler(v0);
  if ( !result )
    return tx_ready_check();
  return result;
}



// set_tx_buffer @ 0x1272f0
int set_tx_buffer(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  volatile uint8_t *v4; // r0
  volatile int *v5; // r6
  int v6; // r3
  int v7; // r2
  volatile uint32_t *v8; // r0

  v1 = (void *)(uintptr_t)(off_127380);
  v2 = result;
  if ( *((volatile uint32_t *)off_127380 + 11) )
  {
    *((volatile uint32_t *)off_127380 + 11) = result;
  }
  else
  {
    v3 = *((volatile uint32_t *)off_127380 + 10);
    if ( v3 == result )
    {
      *(volatile uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(volatile uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (volatile uint8_t *)bt_buf_alloc(69, 13, 0, 1);
        *v4 = *(volatile uint8_t *)(v3 + 24);
        hci_evt_send((int)(uintptr_t)(v4));
      }
      if ( *((volatile int *)off_127384 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(volatile uint32_t *)off_127388 = 1;
        }
        v5 = (volatile int *)off_12738C;
        ++*(volatile uint32_t *)off_12738C;
        mmio_set_bit(4);
        conn_get(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(volatile uint32_t *)off_127388;
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
      v8 = (volatile uint32_t *)bt_buf_alloc(140, 0, 255, 4);
      *v8 = dword_127390;
      return (int)(uintptr_t)(hci_evt_send((int)(uintptr_t)(v8)));
    }
  }
  return result;
}



// rf_tx_packet @ 0x127394
int rf_tx_packet(int result) {
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

  v1 = (void *)(uintptr_t)(off_1274A8);
  v2 = (v2 & ~0xFFFFFFFFull) | ((uint32_t)(result) & 0xFFFFFFFFu);
  v2 = (v2 & 0xFFFFFFFFu) | ((uint64_t)(uint32_t)(*((volatile uint32_t *)off_1274A0 + 4) + *(volatile uint32_t *)(result + 20)) << 32);
  if ( result != dword_1274A4 || (*((volatile uint8_t *)off_1274A8 + 88) & 4) != 0 )
  {
    if ( *((volatile uint32_t *)off_1274A8 + 10) != result )
    {
      result = return_1000();
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
      hci_acl_buf_alloc();
      result = send_event_to_host(SHIDWORD(v2), 0, 0);
      v5 = *((volatile uint32_t *)v1 + 4);
      if ( v5 )
      {
        v6 = dword_1274BC;
        v7 = dword_1274C0;
        v8 = dword_1274AC - HIDWORD(v2);
        while ( 1 )
        {
          v10 = *(volatile uint32_t *)(v5 + 4);
          result = v10 - return_1000();
          if ( result + v8 >= 0 )
            break;
          v11 = *(volatile uint32_t *)(v5 + 4);
          v12 = v6 + 1320 * *(volatile uint8_t *)(v5 + 8);
          v9 = 102400;
          if ( *(volatile uint8_t *)(v12 + 106) )
          {
            if ( *(volatile uint8_t *)(v12 + 106) == 2 )
              v9 = *(volatile uint16_t *)(v12 + 222) << 10;
            result = scan_adv_report(v12, v11 + v9, 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
          else
          {
            result = scan_adv_report(v12, v11 + *(volatile uint32_t *)(v7 + 696 * *(volatile uint8_t *)(v12 + 116) + 8), 0);
            v5 = *((volatile uint32_t *)v1 + 4);
            if ( !v5 )
              break;
          }
        }
      }
      if ( *((volatile uint32_t *)v1 + 11) )
      {
        if ( **(volatile int16_t **)off_1274B0 < 0 && (v1[88] & 0xC) == 0 )
          return mmio_irq_clear(dword_1274B8, dword_1274B4, 1698);
      }
      else
      {
        return set_tx_buffer(v2);
      }
    }
  }
  else
  {
    *((volatile uint8_t *)off_1274A8 + 88) &= ~0x40u;
  }
  return result;
}



// read_rssi @ 0x1274c4
int read_rssi() {
  volatile uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = (void *)(uintptr_t)(off_12754C);
  v1 = *((volatile uint8_t *)off_12754C + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(volatile int16_t **)off_127550 < 0 && (v1 & 4) != 0 )
    {
      mmio_irq_clear(dword_127560, dword_12755C, 1720);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_tx_packet(dword_127554);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(volatile int16_t **)off_127550 < 0 && (v1 & 8) != 0 )
    {
      mmio_irq_clear(dword_127564, dword_12755C, 1731);
      v1 = (v1 & ~0xFFu) | ((uint8_t)(v0[88]) & 0xFFu);
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_tx_packet(dword_127558);
  }
  return result;
}



// set_advertising_flag @ 0x127568
int set_advertising_flag() {
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = (void *)(uintptr_t)(off_127598);
  if ( (*((volatile uint8_t *)off_127598 + 88) & 0x10) == 0 )
  {
    v1 = *((volatile uint8_t *)off_127598 + 90);
    *((volatile uint8_t *)off_127598 + 88) |= 0x10u;
    if ( v1 )
      return ke_event_lock((void *)(uintptr_t)((int)v0 + 48), *((volatile uint32_t *)off_12759C + 4) + 30000);
    else
      return read_rssi();
  }
  return result;
}



