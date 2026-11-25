// ke_msg_dispatch_1 @ 0x135940
int ke_msg_dispatch_1(int a1) {
  volatile uint32_t *v1; // r5

  v1 = (void *)(uintptr_t)(off_13596C);
  invalid_handler_12c5fc(6154, 6);
  memcpy((void *)(uintptr_t)(a1), (void *)(uintptr_t)(v1[4]), 54);
  tx_process_jump(v1[4] - 12);
  v1[4] = a1;
  return mac_dma_setup();
}



// mac_backoff_rand @ 0x135970
volatile uint8_t * mac_backoff_rand(volatile uint8_t *a1, int a2) {
  volatile uint8_t *result; // r0
  int v3; // r2
  unsigned int v4; // r3
  volatile uint8_t *v5; // r0
  int v6; // r1
  unsigned int v7; // r3
  volatile uint8_t *v8; // r0
  char v9[5]; // [sp+7h] [bp-5h] BYREF

  result = check_buf_range_12d854(a1, a2, v9);
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



// rf_chan_pwr_calc @ 0x1359bc
int rf_chan_pwr_calc(int a1, int a2, volatile char *a3) {
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
  v3 = dword_135D44;
  v4 = dword_135D48;
  v5 = *(volatile uint8_t *)(dword_135D44 + 1320 * a1 + 116);
  v6 = dword_135D48 + 696 * v5;
  _frame.v53 = *(volatile uint32_t *)(v6 + 184);
  v9 = 7;
  while ( 1 )
  {
    v10 = rf_validate_freq(*(volatile uint8_t *)(v6 + 35), v9);
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
  _frame.v58 = *(volatile uint8_t *)(dword_135D3C + v12);
  _frame.v57 = *a3;
  result = (int)(uintptr_t)(lock_acquire(*(volatile uint8_t *)(v13 + 412) != 0, 512));
  v15 = result;
  if ( result )
  {
    get_status_flag_c5(v3 + 1320 * a1, result);
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
          if ( **(volatile int16_t **)off_135E8C < 0 )
            irq_disable_mmio_write(dword_135E94, dword_135E90, 1636);
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
    v24 = (void *)(uintptr_t)(off_135D40);
    v25 = *((volatile uint32_t *)off_135D40 + 1);
    v26 = _frame.v61 + v23;
    _frame.v65[0] = *(volatile uint32_t *)off_135D40;
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
    if ( v35 != 33 && hci_cmd_handler((v35 << 8) | 8) == 1 )
    {
      _frame.v55 = *(volatile uint32_t *)(dword_135E88 + 32 * v35 + 28);
      ((int (*)())call_callback)();
      get_bt_state(_frame.v55);
    }
    if ( (a3[1] & 0x40) != 0 && *(volatile uint8_t *)(_frame.v53 + 96) == 1 )
    {
      memcpy((void *)(uintptr_t)(v15 + 12), (void *)(uintptr_t)(a2), 6);
      memcpy((void *)(uintptr_t)(v15 + 18), (void *)(uintptr_t)(_frame.v59 + 100 + v3), 6);
      v51 = v32 - (*(volatile uint8_t *)(v15 + 51) + *(volatile uint8_t *)(v15 + 53));
      *(volatile uint8_t *)(v15 + 27) = 0;
      rf_channel_select(v15, _frame.v53 + 80, v26, v51 - 26);
    }
    return sec_check(v15, _frame.v58);
  }
  return result;
}



// tx_desc_get @ 0x135e98
int tx_desc_get(int a1, volatile uint8_t *a2, int16_t a3, int16_t a4) {
  uint16_t v5; // r7
  volatile uint8_t *v8; // r0

  v5 = *((volatile uint16_t *)a2 + 1);
  memcpy((void *)(uintptr_t)(dword_135EDC + (*a2 << 9)), a2 + 4, v5);
  *(volatile uint16_t *)(dword_135EE0 + 2 * *a2) = v5;
  v8 = (volatile uint8_t *)tx_send_pdu(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  rx_process_packet_1((int)v8);
  return 0;
}



// patch_table_read @ 0x135ee4
/* luna: Copies an AP basic-rate update into the indexed station context when its state is 2, refreshes PHY status, and emits the associated header word. */
int patch_table_read(int a1, volatile uint16_t *a2, int a3, int a4) {
  int station_idx; // r2
  int station_ctx; // r7
  int v10; // r1
  int v11; // r2
  char v12; // r12

  check_feature_flag(256, "apm_update_basicrate:%d\r\n", *a2);
  station_idx = *a2;
  if ( *(volatile uint8_t *)(dword_135F58 + 1320 * station_idx + 106) == 2 )
  {
    station_ctx = dword_135F5C + 696 * (station_idx + 32);
    v10 = *(volatile uint32_t *)(a2 + 3);
    v11 = *(volatile uint32_t *)(a2 + 5);
    v12 = *((volatile uint8_t *)a2 + 14);
    *(volatile uint32_t *)(station_ctx + 192) = *(volatile uint32_t *)(a2 + 1);
    *(volatile uint32_t *)(station_ctx + 196) = v10;
    *(volatile uint32_t *)(station_ctx + 200) = v11;
    *(volatile uint8_t *)(station_ctx + 204) = v12;
    check_feature_flag(256, "param->basic_rates:%d\r\n", *((volatile uint8_t *)a2 + 2));
    get_phy_status_byte(station_ctx);
  }
  mac_write_header_word(7179, a4, a3);
  return 0;
}


// patch_code_load @ 0x135f64
/* luna: Processes an APM stop-CAC request, conditionally updates the indexed interface state under IRQ protection, and writes a response header. */
int patch_code_load(int a1, volatile uint8_t *a2, int a3, int a4) {
  int v6; // r2
  int interface_ctx; // r0
  int v9; // r0
  volatile uint32_t *v10; // r1
  volatile uint32_t *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  volatile int *v15; // r3
  int v16; // r3

  alloc_tx_event("%s\n", aApmStopCacReqH);
  v6 = a3;
  interface_ctx = dword_136000 + 1320 * *a2;
  if ( *(volatile uint8_t *)(interface_ctx + 106) == 2 && !*(volatile uint8_t *)(interface_ctx + 108) )
  {
    v9 = hci_cmd_handler(7u);
    v6 = a3;
    if ( !v9 )
    {
      bsscfg_get(*a2);
      *(volatile uint8_t *)off_136004 = 0;
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(volatile uint32_t *)off_136008 = 1;
      }
      v10 = (void *)(uintptr_t)(off_13600C);
      v11 = (void *)(uintptr_t)(off_136010);
      v12 = *(volatile uint32_t *)off_13600C;
      v13 = *(volatile uint32_t *)off_13600C + 1;
      v14 = *((volatile uint32_t *)off_136010 + 1) & 0xFFFFFFEF;
      *(volatile uint32_t *)off_13600C = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (volatile int *)off_136008;
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
  mac_write_header_word(7175, a4, v6);
  return 0;
}


// rf_config_from_params @ 0x136014
/* luna: Validates an AP start-CAC request against interface and radio state, then sends a confirmation with the resulting status. */
int rf_config_from_params(int a1, volatile uint8_t *a2, int a3, int a4) {
  uint16_t v5; // r6
  uint16_t v6; // r5
  int v7; // r2
  int v8; // r3
  int interface_context; // r1
  char status; // r7
  volatile char *v11; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r0
  int interface_index; // r0
  int v17; // r1
  uint8_t a2a[5]; // [sp+7h] [bp-5h] BYREF

  v5 = a3;
  v6 = a4;
  v7 = a2[9];
  v8 = *a2;
  a2a[0] = 0;
  alloc_tx_event("%s %x %d\n", aApmStartCacReq, v7, v8);
  interface_context = dword_1360B0 + 1320 * a2[10];
  if ( *(volatile uint8_t *)(interface_context + 106) == 2 )
  {
    if ( *(volatile uint8_t *)(interface_context + 108) || hci_cmd_handler(7u) )
    {
      status = 8;
    }
    else
    {
      v15 = ((int (*)())cfm_radio_check)(a2, a2a, v13, v14);
      status = v15;
      if ( v15 )
      {
        status = 1;
      }
      else
      {
        interface_index = a2[10];
        v17 = a2a[0];
        *(volatile uint8_t *)off_1360B4 = 1;
        bsscfg_index(interface_index, v17);
        *((volatile uint32_t *)off_1360B8 + 1) |= 0x10u;
      }
    }
  }
  else
  {
    status = 4;
  }
  v11 = (volatile char *)tx_send_pdu(7173, v6, v5, 2);
  *v11 = status;
  v11[1] = a2a[0];
  rx_process_packet_1((int)v11);
  return 0;
}


