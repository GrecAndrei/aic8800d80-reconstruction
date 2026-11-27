// hci_vendor_get_state @ 0x135c9c
volatile uint32_t * hci_vendor_get_state(int a1) {
  volatile uint32_t *v1; // r5

  v1 = (void *)(uintptr_t)(off_135CC8);
  irq_lock((void *)(uintptr_t)(6154), 6);
  memcpy((void *)(uintptr_t)(a1), (void *)(uintptr_t)(v1[4]), 54);
  jump_to_tx_entry(v1[4] - 12);
  v1[4] = a1;
  return (void *)(uintptr_t)(rf_lookup_alt_by_index());
}



// hci_event_parse @ 0x135ccc
volatile uint8_t * hci_event_parse(volatile uint8_t *a1, int a2) {
  volatile uint8_t *result; // r0
  int v3; // r2
  unsigned int v4; // r3
  volatile uint8_t *v5; // r0
  int v6; // r1
  unsigned int v7; // r3
  volatile uint8_t *v8; // r0
  char v9[5]; // [sp+7h] [bp-5h] BYREF

  result = find_char_3(a1, a2, v9);
  if ( result )
  {
    if ( (uint8_t)v9[0] <= 0x1Du )
      return 0;
    v3 = (uint16_t)(4 * *((volatile uint16_t *)result + 4));
    v4 = (uint8_t)(v9[0] - 10 - 4 * result[8]);
    if ( v4 <= 0x15 )
      return 0;
    v5 = result + 10;
    v6 = (uint16_t)(4 * *(volatile uint16_t *)&v5[v3]);
    v7 = (uint8_t)(v4 - 2 - 4 * v5[v3]);
    v8 = &v5[v3];
    if ( v7 <= 0x13 )
      return 0;
    else
      return (volatile uint8_t *)*(volatile uint16_t *)&v8[v6 + 4];
  }
  return result;
}



// rf_map_to_cal @ 0x135d18
int rf_map_to_cal(int a1, int a2, volatile char *a3) {
  int v3; // r10
  int v4; // r8
  int v5; // r9
  int v6; // r4
  int v9; // r11
  int v10; // r0
  int v11; // r3
  int v12; // r2
  int v13; // r11
  int result; // r0
  int v15; // r4
  int v16; // r5
  int v17; // r0
  int v18; // r2
  int v19; // r3
  int v20; // r12
  char v21; // r2
  char v22; // r11
  int v23; // r3
  volatile uint64_t *v24; // r5
  int v25; // r1
  int v26; // r11
  int v27; // r7
  volatile uint8_t *v28; // r1
  int v29; // r2
  volatile uint32_t *v30; // r1
  int v31; // r12
  int v32; // r7
  int v33; // r8
  int v34; // r2
  int v35; // r8
  int v36; // r1
  int v37; // r3
  unsigned int v38; // r2
  int v39; // cc
  unsigned int v40; // r3
  unsigned int v41; // r2
  int16_t v42; // r0
  int16_t v43; // r1
  int16_t v44; // r2
  int16_t v45; // r3
  int16_t v46; // r2
  int16_t v47; // r3
  uint8_t v48; // r3
  int16_t v49; // r0
  int16_t v50; // r1
  int v51; // r7
  uint64_t v52; // kr00_8
  struct __attribute__((packed)) { int v53; // [sp+Ch] [bp-40h]
  union { uint8_t v54; // [sp+10h] [bp-3Ch]
  int v55; }; // [sp+10h] [bp-3Ch]
  char _pad2[4]; char v57; // [sp+18h] [bp-34h]
  char _pad3[3]; int v58; // [sp+1Ch] [bp-30h]
  int v59; // [sp+20h] [bp-2Ch]
  int16_t v60; // [sp+24h] [bp-28h]
  char _pad6[2]; int v61; // [sp+28h] [bp-24h]
  int v62; // [sp+2Ch] [bp-20h]
  int v63; // [sp+30h] [bp-1Ch] BYREF
  int v64; // [sp+34h] [bp-18h]
  uint32_t v65[2]; // [sp+38h] [bp-14h] BYREF
  uint64_t v66; // [sp+40h] [bp-Ch] BYREF
  } _frame;
  v3 = dword_1360A0;
  v4 = dword_1360A4;
  v5 = *(volatile uint8_t *)(dword_1360A0 + 1320 * a1 + 116);
  v6 = dword_1360A4 + 696 * v5;
  _frame.v53 = *(volatile uint32_t *)(v6 + 184);
  v9 = 7;
  while ( 1 )
  {
    v10 = phy_set_chan(*(volatile uint8_t *)(v6 + 35), v9);
    v11 = (char)v9;
    v9 = (uint16_t)(v9 - 1);
    if ( v10 )
      break;
    if ( v9 == 0xFFFF )
    {
      v12 = -1;
      v11 = (v11 & ~0xFFu) | ((uint8_t)(-1) & 0xFFu);
      goto LABEL_5;
    }
  }
  v12 = v11;
LABEL_5:
  _frame.v54 = v11;
  v13 = v3 + 1320 * a1;
  _frame.v59 = 1320 * a1;
  _frame.v58 = *(volatile uint8_t *)(dword_136098 + v12);
  _frame.v57 = *a3;
  result = (int)(uintptr_t)(event_notify(*(volatile uint8_t *)(v13 + 412) != 0, 512));
  v15 = result;
  if ( result )
  {
    scan_done_check(v3 + 1320 * a1, result);
    v16 = *(volatile uint32_t *)(v15 + 72);
    v17 = *(volatile uint32_t *)(v13 + 100);
    v18 = v4 + 696 * v5;
    v19 = v4 + 2 * (_frame.v54 + 348 * *(volatile uint8_t *)(v18 + 35) + 156);
    v20 = *(volatile uint32_t *)(v18 + 38);
    _frame.v60 = *(volatile uint16_t *)(v19 + 4);
    v18 = (v18 & ~0xFFFFu) | ((uint16_t)(*(volatile uint16_t *)(v18 + 42)) & 0xFFFFu);
    *(volatile uint8_t *)(v16 + 108) = -120;
    *(volatile uint8_t *)(v16 + 109) = 1;
    *(volatile uint16_t *)(v19 + 4) = (_frame.v60 + 1) & 0xFFF;
    *(volatile uint16_t *)(v16 + 122) = *(volatile uint16_t *)(v13 + 104);
    *(volatile uint16_t *)(v16 + 116) = v18;
    *(volatile uint32_t *)(v16 + 118) = v17;
    *(volatile uint8_t *)(v16 + 110) = 0;
    *(volatile uint8_t *)(v16 + 111) = 0;
    *(volatile uint32_t *)(v16 + 112) = v20;
    memcpy((void *)(uintptr_t)(v16 + 124), (void *)(uintptr_t)(a2), 6);
    v21 = *(volatile uint8_t *)(v13 + 107);
    *(volatile uint16_t *)(v16 + 130) = 16 * _frame.v60;
    *(volatile uint8_t *)(v15 + 28) = v21;
    *(volatile uint8_t *)(v15 + 29) = *(volatile uint8_t *)(v13 + 116);
    *(volatile uint16_t *)(v16 + 132) = _frame.v54;
    v22 = a3[1];
    _frame.v63 = 0;
    _frame.v61 = v16 + 108;
    _frame.v64 = 0;
    if ( (v22 & 0x40) != 0 )
    {
      v36 = *(volatile uint32_t *)(*(volatile uint32_t *)(v15 + 76) + 48);
      v37 = *(volatile uint32_t *)(v36 + 12);
      *(volatile uint16_t *)(v16 + 108) |= 0x4000u;
      v38 = *(volatile uint8_t *)(_frame.v53 + 98);
      *(volatile uint32_t *)(v36 + 12) = v37 & 0xFFFFFC00 | v38;
      switch ( *(volatile uint8_t *)(_frame.v53 + 96) )
      {
        case 0:
        case 3:
          *(volatile uint8_t *)(v15 + 51) = 4;
          *(volatile uint8_t *)(v15 + 53) = 4;
          ++*(volatile uint64_t *)(_frame.v53 + 72);
          memcpy((void *)(&_frame.v63), (void *)(uintptr_t)(_frame.v53 + 72), 6);
          *(volatile uint16_t *)(v16 + 134) = _frame.v63;
          *(volatile uint16_t *)(v16 + 136) = HIWORD(_frame.v63) | (*(volatile uint8_t *)(_frame.v53 + 97) << 14);
          _frame.v62 = *(volatile uint8_t *)(v15 + 51);
          v23 = _frame.v62 + 26;
          break;
        case 1:
          *(volatile uint8_t *)(v15 + 51) = 8;
          *(volatile uint8_t *)(v15 + 53) = 12;
          ++*(volatile uint64_t *)(_frame.v53 + 72);
          memcpy((void *)(&_frame.v63), (void *)(uintptr_t)(_frame.v53 + 72), 6);
          v48 = _frame.v63;
          v49 = HIWORD(_frame.v63);
          v46 = _frame.v64;
          *(volatile uint16_t *)(v16 + 134) = _frame.v63 & 0x5F00 | 0x2000 | BYTE1(_frame.v63);
          v50 = *(volatile uint8_t *)(_frame.v53 + 97);
          *(volatile uint16_t *)(v16 + 138) = v49;
          v47 = v48 | (uint16_t)(v50 << 14);
          goto LABEL_31;
        case 2:
          *(volatile uint8_t *)(v15 + 51) = 8;
          *(volatile uint8_t *)(v15 + 53) = 8;
          ++*(volatile uint64_t *)(_frame.v53 + 72);
          memcpy((void *)(&_frame.v63), (void *)(uintptr_t)(_frame.v53 + 72), 6);
          *(volatile uint16_t *)(v16 + 134) = _frame.v63;
          v45 = *(volatile uint8_t *)(_frame.v53 + 97);
          v46 = _frame.v64;
          *(volatile uint16_t *)(v16 + 138) = HIWORD(_frame.v63);
          v47 = v45 << 14;
LABEL_31:
          *(volatile uint16_t *)(v16 + 136) = v47 | 0x2000;
          *(volatile uint16_t *)(v16 + 140) = v46;
          _frame.v62 = *(volatile uint8_t *)(v15 + 51);
          v23 = _frame.v62 + 26;
          break;
        case 4:
          v39 = v38 > 0xF;
          *(volatile uint8_t *)(v15 + 51) = 18;
          *(volatile uint8_t *)(v15 + 53) = 16;
          v40 = *(volatile uint32_t *)(_frame.v53 + 72);
          v41 = *(volatile uint32_t *)(_frame.v53 + 76);
          if ( v39 )
            v52 = __PAIR64__(v41, v40) + 2;
          else
            v52 = __PAIR64__(v41, v40) + 1;
          *(volatile uint64_t *)(_frame.v53 + 72) = v52;
          memcpy((void *)(&_frame.v63), (void *)(uintptr_t)(_frame.v53 + 72), 8);
          *(volatile uint16_t *)(v16 + 134) = *(volatile uint8_t *)(_frame.v53 + 97);
          v42 = HIWORD(_frame.v63);
          v43 = _frame.v64;
          v44 = HIWORD(_frame.v64);
          *(volatile uint16_t *)(v16 + 136) = _frame.v63;
          *(volatile uint16_t *)(v16 + 138) = v42;
          *(volatile uint16_t *)(v16 + 140) = v43;
          *(volatile uint16_t *)(v16 + 142) = v44;
          *(volatile uint16_t *)(v16 + 144) = 23606;
          *(volatile uint16_t *)(v16 + 146) = 23606;
          *(volatile uint16_t *)(v16 + 148) = 23606;
          *(volatile uint16_t *)(v16 + 150) = 23606;
          _frame.v62 = *(volatile uint8_t *)(v15 + 51);
          v23 = _frame.v62 + 26;
          break;
        default:
          if ( **(volatile int16_t **)off_1361E8 < 0 )
            mmio_irq_clear(dword_1361F0, dword_1361EC, 1636);
          _frame.v62 = *(volatile uint8_t *)(v15 + 51);
          v23 = _frame.v62 + 26;
          break;
      }
    }
    else
    {
      *(volatile uint8_t *)(v15 + 51) = 0;
      *(volatile uint8_t *)(v15 + 53) = 0;
      _frame.v62 = 0;
      v23 = 26;
    }
    v24 = (void *)(uintptr_t)(off_13609C);
    v25 = *((volatile uint32_t *)off_13609C + 1);
    v26 = _frame.v61 + v23;
    _frame.v65[0] = *(volatile uint32_t *)off_13609C;
    _frame.v65[1] = v25;
    memcpy((void *)(uintptr_t)(_frame.v61 + v23), (void *)(_frame.v65), 8);
    _frame.v66 = v24[1];
    memcpy((void *)(uintptr_t)(v26 + 8), (void *)(&_frame.v66), 8);
    memcpy((void *)(uintptr_t)(v26 + 16), (void *)(uintptr_t)(_frame.v59 + 100 + v3), 6);
    v27 = v3 + 1320 * a1;
    *(volatile uint16_t *)(v26 + 22) = *(volatile uint32_t *)(v27 + 1228);
    *(volatile uint8_t *)(v26 + 24) = *(volatile uint16_t *)(v27 + 1230);
    *(volatile uint8_t *)(v26 + 25) = *(volatile uint8_t *)(v27 + 1231);
    if ( (a3[1] & 0x40) != 0 )
    {
      if ( _frame.v57 >= 0 )
        v28 = a3 + 48;
      else
        v28 = a3 + 50;
    }
    else if ( _frame.v57 >= 0 )
    {
      v28 = a3 + 40;
    }
    else
    {
      v28 = a3 + 42;
    }
    memcpy((void *)(uintptr_t)(v26 + 26), v28, 10);
    v29 = *(volatile uint8_t *)(v4 + 696 * v5 + 35);
    v30 = *(volatile uint32_t **)(v15 + 76);
    v31 = *(volatile uint8_t *)(v15 + 53);
    *(volatile uint32_t *)(v15 + 92) = v15;
    v32 = _frame.v62 + v31 + 62;
    v33 = v4 + 696 * v29 + 12 * _frame.v54;
    v34 = v30[7] - 1 + v32;
    *(volatile uint32_t *)(v15 + 88) = 0;
    v30[8] = v34;
    v30[9] = _frame.v62 + v31 + 66;
    v35 = *(volatile uint8_t *)(v33 + 453);
    if ( v35 != 33 && hci_cmd_send_short((v35 << 8) | 8) == 1 )
    {
      _frame.v55 = *(volatile uint32_t *)(dword_1361E4 + 32 * v35 + 28);
      rx_invoke_cb(_frame.v55, _frame.v60, 2);
      rf_scan_entry(_frame.v55);
    }
    if ( (a3[1] & 0x40) != 0 && *(volatile uint8_t *)(_frame.v53 + 96) == 1 )
    {
      memcpy((void *)(uintptr_t)(v15 + 12), (void *)(uintptr_t)(a2), 6);
      memcpy((void *)(uintptr_t)(v15 + 18), (void *)(uintptr_t)(_frame.v59 + 100 + v3), 6);
      v51 = v32 - (*(volatile uint8_t *)(v15 + 51) + *(volatile uint8_t *)(v15 + 53));
      *(volatile uint8_t *)(v15 + 27) = 0;
      check_radio_flag_2(v15, _frame.v53 + 80, v26, v51 - 26);
    }
    return ble_event_dispatch(v15, _frame.v58);
  }
  return result;
}



// patch_get_entry @ 0x1361f4
int patch_get_entry(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  uint16_t v5; // r7
  volatile uint8_t *v8; // r0

  v5 = *((volatile uint16_t *)a2 + 1);
  memcpy((void *)(uintptr_t)(dword_136238 + (*a2 << 9)), a2 + 4, v5);
  *(volatile uint16_t *)(dword_13623C + 2 * *a2) = v5;
  v8 = (volatile uint8_t *)bt_buf_alloc(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  hci_evt_send((int)v8);
  return 0;
}



// patch_copy_data @ 0x136240
int patch_copy_data(int a1, volatile uint16_t *a2, int a3, int a4) {
  int v7; // r2
  int v9; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  state_check_feature(256, "apm_update_basicrate:%d\r\n", *a2);
  v7 = *a2;
  if ( *(volatile uint8_t *)(dword_1362B4 + 1320 * v7 + 106) == 2 )
  {
    v9 = dword_1362B8 + 696 * (v7 + 32);
    v10 = *(volatile uint32_t *)(a2 + 3);
    v11 = *(volatile uint32_t *)(a2 + 5);
    v12 = *((volatile uint8_t *)a2 + 14);
    *(volatile uint32_t *)(v9 + 192) = *(volatile uint32_t *)(a2 + 1);
    *(volatile uint32_t *)(v9 + 196) = v10;
    *(volatile uint32_t *)(v9 + 200) = v11;
    *(volatile uint8_t *)(v9 + 204) = v12;
    state_check_feature(256, "param->basic_rates:%d\r\n", *((volatile uint8_t *)a2 + 2));
    bt_get_local_addr_type(v9);
  }
  hci_evt_alloc_send(7179, a4, a3);
  return 0;
}


// tx_send_packet @ 0x1362c0
int tx_send_packet(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v6; // r2
  int v7; // r0
  int v9; // r0
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  volatile int *v15; // r3
  int v16; // r3

  ke_event_schedule_1("%s\n", aApmStopCacReqH);
  v6 = a3;
  v7 = dword_136358 + 1320 * *a2;
  if ( *(volatile uint8_t *)(v7 + 106) == 2 && !*(volatile uint8_t *)(v7 + 108) )
  {
    v9 = hci_cmd_send_short(7u);
    v6 = a3;
    if ( !v9 )
    {
      get_entry_by_index(*a2);
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_13635C = 1;
      }
      v10 = (void *)(uintptr_t)(off_136360);
      v11 = (void *)(uintptr_t)(off_136364);
      v12 = *(volatile uint32_t *)off_136360;
      v13 = *(volatile uint32_t *)off_136360 + 1;
      v14 = *((volatile uint32_t *)off_136364 + 1) & 0xFFFFFFEF;
      *(volatile uint32_t *)off_136360 = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (volatile int *)off_13635C;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  hci_evt_alloc_send(7175, a4, v6);
  return 0;
}


// tx_build_packet @ 0x136368
int tx_build_packet(int a1, volatile uint8_t *a2, int a3, int a4) {
  uint16_t v5; // r6
  uint16_t v6; // r5
  int v7; // r2
  int v8; // r3
  int v9; // r1
  char v10; // r7
  volatile char *v11; // r0
  int v13; // r0
  uint8_t a2a[5]; // [sp+7h] [bp-5h] BYREF

  v5 = a3;
  v6 = a4;
  v7 = a2[9];
  v8 = *a2;
  a2a[0] = 0;
  ke_event_schedule_1("%s %x %d\n", aApmStartCacReq, v7, v8);
  v9 = dword_136400 + 1320 * a2[10];
  if ( *(volatile uint8_t *)(v9 + 106) == 2 )
  {
    if ( *(volatile uint8_t *)(v9 + 108) || hci_cmd_send_short(7u) )
    {
      v10 = 8;
    }
    else
    {
      v13 = find_free_conn(a2, a2a);
      v10 = v13;
      if ( v13 )
      {
        v10 = 1;
      }
      else
      {
        update_entries_from_config(a2[10], a2a[0]);
        *((volatile uint32_t *)off_136404 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = (volatile char *)bt_buf_alloc(7173, v6, v5, 2);
  *v11 = v10;
  v11[1] = a2a[0];
  hci_evt_send((int)v11);
  return 0;
}


