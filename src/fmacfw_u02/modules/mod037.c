// ctrl_reset_handler @ 0x12737c
int ctrl_reset_handler(int a1, int a2) {
  volatile uint8_t *v2; // r4
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r7
  int v7; // r1
  int result; // r0
  unsigned int v9; // r3
  volatile int *v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // zf
  int v14; // r3
  char v15; // r8
  int v16; // r3
  int v17; // r2
  int v18; // r1
  volatile uint16_t *v19; // r8
  volatile uint16_t *v20; // r0
  int v21; // r7
  int v22; // r0
  int v23; // r2
  volatile unsigned int *v24; // r12
  volatile uint32_t *v25; // r1
  char v26; // r3
  volatile uint32_t *v27; // r7
  int v28; // r2
  unsigned int v29; // r3
  volatile uint8_t *v30; // r9
  int v31; // r7
  unsigned int v32; // r3
  int v33; // lr
  volatile char *v34; // r2
  unsigned int v35; // r10
  volatile uint32_t *v36; // r7
  int v37; // r2
  int v38; // r1
  volatile uint32_t *v39; // r7
  int v40; // r2

  v2 = (void *)(uintptr_t)(off_12761C);
  *((volatile uint32_t *)off_12761C + 10) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_127620 = 1;
  }
  v5 = (void *)(uintptr_t)(off_127624);
  v6 = (void *)(uintptr_t)(off_127628);
  v7 = *(volatile uint32_t *)off_127624;
  result = *(volatile uint32_t *)off_127624 + 1;
  v9 = *((volatile uint32_t *)off_127628 + 1) & 0xFFFFFFFD;
  *(volatile uint32_t *)off_127624 = result;
  v6[1] = v9;
  if ( result )
  {
    v10 = (volatile int *)off_127620;
    *v5 = v7;
    v11 = *v10;
    if ( !v7 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_12762C = (4 * (uint8_t)v2[92]) & 4 | *(volatile uint32_t *)off_12762C & 0xFFFFFFFB;
  if ( a2 )
    goto LABEL_6;
  result = shared_s16_worker();
  if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_127630)[102]) )
    goto LABEL_6;
  v12 = *(volatile uint8_t *)(a1 + 24);
  if ( v12 != 3 )
  {
LABEL_7:
    v13 = v12 == 4;
    v14 = (uint8_t)v2[88];
    if ( v13 )
    {
      v2[88] = v14 & 0xFB;
      if ( *(volatile uint16_t *)(a1 + 14) )
      {
        result = (int)hci_cmd_send_simple(a1);
        v14 = (uint8_t)v2[88];
      }
      else
      {
        v14 &= 0xDBu;
      }
    }
    goto LABEL_8;
  }
  v15 = *((volatile uint8_t *)off_127634 + 3850);
  if ( v15 || *((volatile uint8_t *)off_127638 + 10) + 1 != *(volatile uint8_t *)(*(volatile uint32_t *)off_127638 + 367) )
    goto LABEL_23;
  v16 = *(volatile uint32_t *)off_127634;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_127634 + 367) )
  {
    v17 = 0;
    do
    {
      v18 = *(volatile uint8_t *)(v16 + 2);
      ++v17;
      v16 += 6;
      if ( v18 == *((volatile uint8_t *)off_127634 + 3851) + 1 )
        goto LABEL_23;
    }
    while ( v17 != *(volatile uint8_t *)(*(volatile uint32_t *)off_127634 + 367) );
  }
  v30 = (void *)(uintptr_t)(off_127664);
  if ( *((volatile uint16_t *)off_127664 + 2) <= 1u && *((volatile uint16_t *)off_127664 + 3) <= 1u )
  {
LABEL_50:
    v39 = (void *)(uintptr_t)(off_127648);
    v40 = **(volatile int16_t **)off_127644;
    *((volatile uint32_t *)off_127648 + 1) |= 0x100040u;
    if ( v40 < 0 && *(volatile uint32_t *)off_127650 << 28 )
      call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
    v38 = 1;
    *(volatile uint32_t *)off_12764C = *v39 | v39[1];
    v15 = 1;
    goto LABEL_48;
  }
  v31 = 0;
  while ( !*((volatile uint16_t *)off_127634 + 2) )
  {
LABEL_44:
    if ( v31 )
      goto LABEL_50;
    v31 = 1;
  }
  v32 = 0;
  v33 = 0;
  while ( 1 )
  {
    v34 = (volatile char *)off_127634 + 60 * v32;
    v35 = (uint8_t)(v32 + 1);
    v32 = v35;
    if ( *(volatile uint8_t *)(*((volatile uint32_t *)v34 + 13) + 2) != v31 || !v34[16] || v34[64] < -79 )
      goto LABEL_38;
    if ( v33 )
      break;
    v33 = 1;
LABEL_38:
    if ( v35 >= *((volatile uint16_t *)off_127634 + 2) )
      goto LABEL_44;
  }
  v36 = (void *)(uintptr_t)(off_127648);
  v37 = **(volatile int16_t **)off_127644;
  *((volatile uint32_t *)off_127648 + 1) &= 0xFFEFFFBF;
  if ( v37 < 0 && *(volatile uint32_t *)off_127650 << 28 )
    call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
  *(volatile uint32_t *)off_12764C = *v36 | v36[1];
  v38 = 0;
LABEL_48:
  v30[8] = v15;
  result = event_dispatch("single ssid %d\n", v38);
LABEL_6:
  v12 = *(volatile uint8_t *)(a1 + 24);
  if ( v12 != 3 )
    goto LABEL_7;
LABEL_23:
  v2[88] &= ~8u;
  v19 = (volatile uint16_t *)get_queue_entry_ptr();
  v20 = (volatile uint16_t *)ke_msg_alloc(79, 13, 0, 12);
  *v20 = *v19;
  v21 = (int)v20;
  v22 = rx_get_packet((int)v19);
  v23 = dword_12763C;
  v24 = (volatile unsigned int *)off_127660;
  v25 = (void *)(uintptr_t)(off_127640);
  *(volatile uint32_t *)(v21 + 4) = (unsigned int)(((unsigned int)dword_12763C * (uint64_t)(unsigned int)v22) >> 32) >> 6;
  *(volatile uint32_t *)(v21 + 8) = (unsigned int)(((unsigned int)v23 * (uint64_t)*v24) >> 32) >> 6;
  *(volatile uint8_t *)(v21 + 2) = 0;
  v26 = 10;
  while ( 1 )
  {
    --v26;
    if ( (uint8_t)*v25 )
      break;
    if ( !v26 )
      goto LABEL_26;
  }
  *(volatile uint8_t *)(v21 + 2) = *v25;
LABEL_26:
  ke_msg_send_2(v21);
  v27 = (void *)(uintptr_t)(off_127648);
  v28 = **(volatile int16_t **)off_127644;
  v29 = *((volatile uint32_t *)off_127648 + 1) & 0xFFFFDDFF;
  *((volatile uint32_t *)off_127648 + 1) = v29;
  if ( v28 < 0 && *(volatile uint32_t *)off_127650 << 28 )
  {
    call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
    v29 = v27[1];
  }
  *(volatile uint32_t *)off_12764C = v29 | *v27;
  result = ke_msg_send_no_param(142, 2, 255);
  v14 = (uint8_t)v2[88];
LABEL_8:
  *(volatile uint8_t *)(a1 + 24) = -1;
  v2[88] = v14 & 0xEF;
  if ( !(v14 << 30) )
  {
    if ( a2 )
      return result;
    return get_shared_s16();
  }
  result = scan_start_request();
  if ( !a2 )
    return get_shared_s16();
  return result;
}


// rf_perform_calibration @ 0x127668
int rf_perform_calibration(volatile uint32_t *a1) {
  volatile int16_t **v1; // r7
  volatile uint8_t *v2; // r6
  volatile uint32_t *v4; // r0
  volatile uint32_t *v5; // r5
  int v6; // r3
  volatile uint32_t *v7; // r4
  int v8; // r3
  int v9; // r2
  int v10; // r3
  int v11; // r2
  volatile char *v12; // r0
  int v13; // r0
  int result; // r0
  volatile int *v15; // r5
  int v16; // r1
  volatile unsigned int v17; // r3
  int v18; // r6
  int v19; // r2
  volatile int *v20; // r3
  int v21; // r3
  int v22; // r1
  int v23; // r3
  int v24; // r7
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r8
  volatile uint32_t *v28; // r2
  volatile uint32_t *v29; // r7
  int v30; // r1
  int v31; // r0
  int v32; // r3
  volatile int *v33; // r3
  int v34; // r3
  volatile uint32_t *v35; // r2
  int v36; // r3
  int v37; // r2

  v1 = (volatile int16_t **)off_127878;
  v2 = (void *)(uintptr_t)(off_12787C);
  v4 = mem_word_load(dword_127880);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = (void *)(uintptr_t)(off_127884);
      goto LABEL_4;
    }
    goto LABEL_25;
  }
  if ( a1 == v4 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
  }
  else
  {
    mmio_clear_register((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = (void *)(uintptr_t)(off_127884);
      goto LABEL_5;
    }
  }
  v7 = (void *)(uintptr_t)(off_127884);
  v8 = *((volatile uint32_t *)off_127884 + 10);
  if ( v8 )
    goto LABEL_6;
  mmio_clear_register((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
  v6 = (uint8_t)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  event_dispatch("cb:%x,%x\n", *((volatile uint8_t *)v7 + 88), v7[11]);
  v23 = *((volatile uint8_t *)v7 + 88);
  if ( (v23 & 8) != 0 )
  {
    v24 = dword_1278BC;
  }
  else
  {
    v22 = v23 << 29;
    if ( (v23 & 4) == 0 )
    {
      v24 = v7[11];
      if ( !v24 )
        goto LABEL_5;
      goto LABEL_32;
    }
    v24 = dword_1278A0;
  }
  v25 = v7[11];
  if ( v25 != v24 && v25 )
    *(volatile uint8_t *)(v25 + 16) = 1;
LABEL_32:
  v26 = v7[10];
  if ( v26 )
    *(volatile uint8_t *)(v26 + 16) = 1;
  v7[10] = v24;
  v7[11] = 0;
  v27 = *(volatile uint8_t *)(v24 + 24);
  *(volatile uint8_t *)(v24 + 16) = 4;
  if ( v27 == 3 )
  {
    event_dispatch(aCbSetState, v22);
    ke_state_set(2u, 3);
    v27 = *(volatile uint8_t *)(v24 + 24);
  }
  if ( v27 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_127890 = 1;
  }
  v28 = (void *)(uintptr_t)(off_127898);
  v29 = (void *)(uintptr_t)(off_1278A4);
  v30 = *(volatile uint32_t *)off_127898;
  v31 = *(volatile uint32_t *)off_127898 + 1;
  v32 = *((volatile uint32_t *)off_1278A4 + 1) | 2;
  *(volatile uint32_t *)off_127898 = v31;
  v29[1] = v32;
  if ( v31 )
  {
    v33 = (volatile int *)off_127890;
    *v28 = v30;
    v34 = *v33;
    if ( !v30 )
    {
      if ( v34 )
        __enable_irq();
    }
  }
  v35 = (void *)(uintptr_t)(off_1278A8);
  v8 = v7[10];
  *((volatile uint8_t *)v7 + 92) = (*(volatile uint32_t *)off_1278A8 & 4) != 0;
  *v35 &= ~4u;
LABEL_6:
  *(volatile uint8_t *)(v8 + 16) = 1;
  v9 = v7[20];
  v10 = 0;
  *v2 = 0;
  if ( v9 )
  {
    v11 = *((volatile uint8_t *)v7 + 90);
    v7[20] = 0;
    if ( !v11 )
    {
      v5[2] = 0;
      goto LABEL_14;
    }
    if ( v11 == 1 || (v10 = v7[4]) == 0 )
    {
      v12 = (volatile char *)off_1278C0;
      if ( *((volatile uint8_t *)off_1278C0 + 24) == 255 )
      {
        if ( *((volatile uint8_t *)off_1278C0 + 52) == 255 )
        {
          if ( *((volatile uint8_t *)off_1278C0 + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_14;
          }
          v12 = (volatile char *)off_1278C0 + 56;
        }
        else
        {
          v12 = (volatile char *)off_1278C0 + 28;
        }
      }
    }
    else
    {
      v12 = *(volatile char **)(dword_127888 + 1320 * *(volatile uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = (int)(uintptr_t)(v12);
  }
  else
  {
    v12 = (volatile char *)v5[2];
  }
  if ( v12 )
    ctrl_register_handler((int)(uintptr_t)(v12));
LABEL_14:
  co_list_push_back(dword_12788C, v5);
  v13 = v7[10];
  if ( *(volatile uint8_t *)(v13 + 24) > 2u )
    ctrl_reset_handler(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_127890 = 1;
    }
    v15 = (volatile int *)off_127898;
    v16 = *(volatile uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(volatile uint32_t *)off_127898;
    v19 = *(volatile uint32_t *)off_127898 + 1;
    *(volatile uint32_t *)off_127898 = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = unknown_worker((volatile uint32_t *)dword_1278AC, v16);
      if ( *v15 )
      {
        v36 = *v15 - 1;
        v37 = *(volatile uint32_t *)off_127890;
        *v15 = v36;
        if ( !v36 )
        {
          if ( v37 )
            __enable_irq();
        }
      }
    }
    else
    {
      if ( v19 )
      {
        v20 = (volatile int *)off_127890;
        *v15 = v18;
        v21 = *v20;
        if ( !v18 )
        {
          if ( v21 )
            __enable_irq();
        }
      }
      return ((int (*)(void))v7[17])();
    }
  }
  return result;
}


// ke_process_event @ 0x1278c8
int ke_process_event(int a1) {
  int v2; // r0
  int result; // r0

  v2 = chip_state_handler(*(volatile uint32_t *)(a1 + 88));
  *(volatile uint32_t *)(a1 + 88) = v2;
  result = rf_power_table_update(a1, v2);
  *(volatile uint8_t *)(a1 + 85) = *(volatile uint8_t *)(a1 + 85) & 0x9F | 0x20;
  return result;
}



// wlc_calc_txrate @ 0x1278f0
int wlc_calc_txrate(int a1) {
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = unknown_worker((void *)(uintptr_t)(a1 + 24), *(volatile uint32_t *)(a1 + 36) + *(volatile uint32_t *)(a1 + 88));
  v3 = *(volatile uint8_t *)(a1 + 85);
  *(volatile uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((volatile uint32_t *)off_127950 + 9);
    if ( v4 && *(volatile uint32_t *)(v4 + 12) == a1 + 76 )
    {
      ke_task_poll();
      llm_scan_sm_execute(a1, *(volatile uint32_t *)(a1 + 36), 0);
      return bt_link_cfg_set(a1, *((volatile uint32_t *)off_127954 + 4), 0);
    }
    else
    {
      return llm_scan_sm_execute(a1, *(volatile uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}



// sta_get_flags @ 0x127958
int sta_get_flags(int result, int16_t a2) {
  int v2; // r8
  int v3; // r7
  int v4; // r5
  int v5; // r9
  int v6; // r4
  int v8; // r2
  uint16_t v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r7
  char v13; // r2

  v2 = dword_127A18;
  v3 = *(volatile uint8_t *)(result + 86);
  v4 = dword_127A18 + 1320 * v3;
  v5 = *(volatile uint8_t *)(v4 + 85) & 0x60;
  if ( (*(volatile uint8_t *)(v4 + 85) & 0x60) == 0 )
  {
    v6 = result;
    result = bt_runtime_check2(dword_127A18 + 1320 * v3, *(volatile uint8_t *)(result + 87));
    v8 = *(volatile uint32_t *)(v6 + 92);
    v9 = abs16(v8 - (result - a2));
    *(volatile uint16_t *)(v6 + 96) = v8 - (result - a2);
    if ( v9 > 0x7D0u )
    {
      *(volatile uint8_t *)(v4 + 85) = *(volatile uint8_t *)(v4 + 85) & 0xAF | 0x10;
      return result;
    }
    if ( v9 > 0xC8u )
    {
      v10 = *((volatile uint32_t *)off_127A14 + 2);
      if ( !v10 )
      {
LABEL_16:
        v12 = v2 + 1320 * v3;
        v13 = *(volatile uint8_t *)(v12 + 85);
        *(volatile uint32_t *)(v12 + 88) = v10;
        *(volatile uint8_t *)(v12 + 85) = v13 | 0x40;
        return result;
      }
      result = 0;
      do
      {
        if ( *(volatile uint8_t *)(v10 + 86) == *(volatile uint8_t *)(v4 + 107) )
        {
          v11 = *(volatile int16_t *)(v10 + 96);
          if ( result >= v11 )
            result = *(volatile int16_t *)(v10 + 96);
          if ( v5 < v11 )
            v5 = *(volatile int16_t *)(v10 + 96);
        }
        v10 = *(volatile uint32_t *)v10;
      }
      while ( v10 );
      if ( !result )
      {
        v10 = v5 >> 1;
        goto LABEL_16;
      }
      if ( !v5 )
      {
        v10 = result / 2;
        goto LABEL_16;
      }
    }
  }
  return result;
}



// stat_clear @ 0x127a1c
int stat_clear() {
  volatile int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  volatile int *i; // r4
  int result; // r0
  volatile uint32_t *v5; // r3
  void *v6; // r1

  v0 = (volatile int *)off_127AAC;
  v1 = (void *)(uintptr_t)(off_127AA8);
  memset((volatile int *)off_127AA8, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    memset(i, 0, 0x1Cu);
    *((volatile uint16_t *)i + 7) = 255;
    *((volatile uint8_t *)i + 24) = -1;
    *((volatile uint8_t *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      co_list_push_back((int)v1, (void *)(i));
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((volatile uint16_t *)v0 + 47) = 0;
    *((volatile uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  zero_8_bytes((volatile uint32_t *)dword_127AB0);
  zero_8_bytes((volatile uint32_t *)dword_127AB4);
  co_list_push_back(dword_127AB0, (volatile uint32_t *)dword_127AB8);
  co_list_push_back(dword_127AB0, (volatile uint32_t *)dword_127ABC);
  co_list_push_back(dword_127AB0, (volatile uint32_t *)dword_127AC0);
  result = co_list_push_back(dword_127AB0, (volatile uint32_t *)dword_127AC4);
  v5 = (void *)(uintptr_t)(off_127AA8);
  v6 = (void *)(uintptr_t)(off_127ACC);
  *((volatile uint32_t *)off_127AA8 + 13) = off_127AC8;
  v5[17] = (int)(uintptr_t)(v6);
  v5[18] = 0;
  return result;
}


// wlc_check_chip_ready @ 0x127ad0
int wlc_check_chip_ready(volatile int16_t *a1, int a2, char a3) {
  volatile uint8_t *v3; // r4
  int16_t v7; // r3
  volatile uint8_t *v8; // r2

  v3 = (void *)(uintptr_t)(off_127B4C);
  if ( **(volatile int16_t **)off_127B48 < 0 && *((volatile uint8_t *)off_127B4C + 108) != 255 )
    mmio_clear_register(dword_127B58, dword_127B54, 2838);
  v3[108] = 3;
  *((volatile uint16_t *)v3 + 49) = 255;
  v3[88] = *((volatile uint8_t *)a1 + 2);
  v7 = *a1;
  *((volatile uint16_t *)v3 + 46) = *a1;
  *((volatile uint16_t *)v3 + 45) = v7;
  v8 = (void *)(uintptr_t)(off_127B50);
  v3[96] = *((volatile uint8_t *)a1 + 4);
  v7 = (v7 & ~0xFFu) | ((uint8_t)(v8[88]) & 0xFFu);
  v3[97] = *((volatile uint8_t *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((volatile uint32_t *)v3 + 26) = a2;
  v3[100] = 1;
  return scan_start_request();
}



// rx_prep_descriptor @ 0x127b5c
int rx_prep_descriptor(volatile uint8_t *a1, int a2) {
  volatile uint8_t *v2; // r7
  int v5; // r5
  unsigned int v6; // r3
  volatile uint32_t *v7; // r8
  char v8; // r3
  volatile uint8_t *v10; // r8
  char v11; // r3
  volatile uint32_t *v12; // r0
  volatile uint8_t *v13; // r2
  int16_t v14; // r1
  unsigned int v15; // r1
  int v16; // r2
  int v17; // r0
  volatile uint32_t *v18; // r0

  v2 = (void *)(uintptr_t)(off_127D1C);
  check_status_bits(8, "roc: %d, dur=%d, st=%d\r\n", *a1, *((volatile uint32_t *)a1 + 3), *((volatile uint8_t *)off_127D1C + 128));
  v5 = *a1;
  if ( *a1 )
  {
    if ( v5 == 1 )
    {
      if ( (uint8_t)v2[136] == 255 )
        return 0;
      v6 = (uint8_t)v2[128];
      v7 = (void *)(uintptr_t)(off_127D30);
      if ( v6 > 3 )
      {
        if ( v6 == 4 )
        {
          fault_handler((int)(uintptr_t)((volatile uint32_t *)off_127D30 + 16));
          v12 = (volatile uint32_t *)v7[8];
          v7[18] = 0;
          rf_perform_calibration(v12);
        }
      }
      else if ( v6 > 1 )
      {
        v13 = *((volatile uint8_t **)off_127D30 + 11);
        *((volatile uint8_t *)off_127D30 + 88) &= ~4u;
        if ( v13 )
        {
          if ( v13 == v2 + 112 && (volatile uint8_t *)v7[20] == v13 )
          {
            fault_handler((int)(uintptr_t)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        hci_cmd_send_simple(dword_127D24);
      }
      else if ( v6 == 1 )
      {
        *((volatile uint8_t *)off_127D30 + 88) &= 0xFAu;
        hci_cmd_send_simple((int)(v2 + 112));
      }
      v8 = *((volatile uint8_t *)v7 + 88);
      v2[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v18 = (volatile uint32_t *)dword_127D2C;
      *((volatile uint8_t *)v7 + 88) = v8 & 0xEF;
      v5 = 0;
      fault_handler((int)(uintptr_t)(v18));
      return v5;
    }
    return 1;
  }
  if ( (uint8_t)v2[136] != 255 || v2[128] == 4 || rx_rate_field_parse(4u) == 1 )
  {
    v10 = (void *)(uintptr_t)(off_127D30);
    v11 = *((volatile uint8_t *)off_127D30 + 88);
    if ( (v11 & 0x20) == 0 )
      return 1;
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_127D30);
    if ( !*((volatile uint8_t *)off_127D30 + 91) )
    {
      v11 = *((volatile uint8_t *)off_127D30 + 88);
      goto LABEL_25;
    }
    v11 = *((volatile uint8_t *)off_127D30 + 88);
    if ( (v11 & 0x20) == 0 )
    {
LABEL_25:
      v2[136] = 4;
      v2[116] = a1[2];
      v2[117] = a1[3];
      v14 = *((volatile uint16_t *)a1 + 3);
      *((volatile uint16_t *)v2 + 59) = *((volatile uint16_t *)a1 + 2);
      *((volatile uint16_t *)v2 + 61) = *((volatile uint16_t *)a1 + 4);
      *((volatile uint16_t *)v2 + 60) = v14;
      v2[124] = a1[16];
      v2[128] = 1;
      v2[125] = 0;
      v15 = *((volatile uint32_t *)a1 + 3);
      *((volatile uint16_t *)v2 + 63) = a2;
      v16 = 1000 * v15;
      if ( v15 > 0x23 )
        v16 -= 35000;
      *((volatile uint32_t *)v2 + 33) = v16;
      v2[138] = a1[1];
      if ( a2 )
      {
        v10[88] = v11 | 1;
        scan_start_request();
      }
      else
      {
        v17 = dword_127D24;
        v10[88] = v11 | 4;
        dma_setup_transfer(v17);
      }
      *(volatile uint32_t *)off_127D28 |= 4u;
      return v5;
    }
  }
  v10[88] = v11 & 0xDF;
  return 1;
}


// scan_find_empty_slot @ 0x127d34
int scan_find_empty_slot(volatile uint8_t *a1, volatile uint8_t *a2) {
  int v2; // r6
  int v5; // r3
  int i; // r5
  int v7; // r0
  char v8; // r6
  int v9; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  int v13; // r0
  volatile uint32_t *v14; // r1
  int16_t v15; // lr
  int v16; // r2

  v2 = dword_127DF4;
  v5 = dword_127DF4;
  for ( i = 0; i != 3; ++i )
  {
    if ( *(volatile uint8_t *)(v5 + 24) != 255
      && *(volatile uint8_t *)(v5 + 4) == *a1
      && *(volatile uint16_t *)(v5 + 6) == *((volatile uint16_t *)a1 + 1) )
    {
      v11 = *(volatile uint8_t *)(v5 + 5);
      v12 = a1[1];
      if ( v11 == v12 )
      {
        if ( *(volatile uint16_t *)(v5 + 8) == *((volatile uint16_t *)a1 + 2)
          && *(volatile uint16_t *)(v5 + 10) == *((volatile uint16_t *)a1 + 3) )
        {
          goto LABEL_16;
        }
      }
      else
      {
        if ( v11 < v12 && v11 != 3 )
        {
          v13 = dword_127DF4 + 28 * i;
          v14 = (void *)(uintptr_t)(off_127DF8);
          *(volatile uint8_t *)(v13 + 5) = v12;
          v15 = *((volatile uint16_t *)a1 + 2);
          *(volatile uint16_t *)(v13 + 10) = *((volatile uint16_t *)a1 + 3);
          v16 = v14[10];
          *(volatile uint16_t *)(v13 + 8) = v15;
          if ( v16 == v13 && *((volatile uint8_t *)v14 + 90) == 1 )
            rf_enable((volatile uint16_t *)(v2 + 28 * i + 4), 0);
LABEL_16:
          *a2 = i;
          return 0;
        }
        if ( v11 > v12 && v12 != 3 )
          goto LABEL_16;
      }
    }
    v5 += 28;
  }
  v7 = (int)(uintptr_t)(mem_word_load(off_127DF8));
  if ( !v7 )
    return 1;
  v8 = dword_127DFC * ((v7 - v2) >> 2);
  *(volatile uint8_t *)(v7 + 24) = v8;
  *a2 = v8;
  v9 = *((volatile uint32_t *)a1 + 1);
  *(volatile uint32_t *)(v7 + 4) = *(volatile uint32_t *)a1;
  *(volatile uint32_t *)(v7 + 8) = v9;
  *(volatile uint16_t *)(v7 + 12) = *((volatile uint16_t *)a1 + 4);
  return 0;
}



// wlc_validate_chip_queue @ 0x127e00
int wlc_validate_chip_queue(int a1) {
  volatile int16_t **v1; // r8
  int v2; // r5
  volatile int *v4; // r6
  int v5; // r7
  int v6; // r4
  int result; // r0

  v1 = (volatile int16_t **)off_127EA0;
  v2 = dword_127E8C;
  v4 = (volatile int *)(dword_127E8C + 28 * a1);
  if ( **(volatile int16_t **)off_127EA0 < 0 )
  {
    v5 = 8 * a1;
    if ( *(volatile uint8_t *)(dword_127E8C + 28 * a1 + 24) != 255
      || (mmio_clear_register((int)aCtxtIdxChanCtx, (int)aChanCtxtDel, 3044), **v1 < 0) )
    {
      if ( *(volatile uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        mmio_clear_register((int)aCtxtNbLinkedVi, (int)aChanCtxtDel, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  co_list_push_back(dword_127E90, (void *)(v4));
  v6 = v2 + 4 * (v5 - a1);
  result = (int)memset(v4, 0, 0x1Cu);
  *(volatile uint16_t *)(v6 + 14) = 255;
  *(volatile uint8_t *)(v6 + 24) = -1;
  *(volatile uint8_t *)(v6 + 27) = -1;
  return result;
}


// rx_parse_header @ 0x127ea4
int rx_parse_header(volatile uint8_t *a1) {
  int v1; // r4
  int result; // r0
  volatile uint8_t *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  volatile int *v8; // r7
  int v9; // r3
  int v10; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(volatile uint32_t *)(a1 + 2);
  v4 = dword_127F30;
  v5 = *((volatile uint32_t *)off_127F2C + 10);
  v6 = *((volatile uint32_t *)v3 + 1);
  v7 = dword_127F30 + 28 * v1 + 4;
  *(volatile uint32_t *)v7 = result;
  *(volatile uint32_t *)(v7 + 4) = v6;
  *(volatile uint16_t *)(v7 + 8) = *((volatile uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_127F34 = 1;
    }
    v8 = (volatile int *)off_127F38;
    ++*(volatile uint32_t *)off_127F38;
    rf_ctrl_enable();
    radio_init(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(volatile uint32_t *)off_127F34;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    rf_enable((volatile uint16_t *)v3, 0);
    return util_format(*(volatile char *)(v4 + 28 * v1 + 12));
  }
  return result;
}



// rx_dispatch_frame @ 0x127f3c
BOOL rx_dispatch_frame(int a1, int a2, int a3) {
  volatile uint8_t *v3; // r11
  volatile int *v4; // r4
  int v8; // r3
  int v9; // r7
  int v10; // r1
  int v11; // r4
  int v13; // r1
  int v14; // r3
  char v15; // r2
  int v16; // r3
  char v17; // r3
  int v18; // r2
  int v19; // [sp+4h] [bp-8h]

  v3 = (void *)(uintptr_t)(off_128114);
  v4 = *((volatile int **)off_128114 + 4);
  if ( v4 )
  {
    v8 = v4[1];
    v9 = *((volatile uint32_t *)off_128114 + 10);
    v19 = *(volatile uint32_t *)(a1 + 72);
    if ( v8 == a2 )
    {
LABEL_8:
      v11 = 0;
      if ( (uint8_t)v3[90] > 1u )
        goto LABEL_12;
LABEL_9:
      *(volatile uint8_t *)(a1 + 85) |= 2u;
      ++v3[91];
      return v9 != v19;
    }
    while ( v8 - a2 < 0 )
    {
      v10 = *((volatile uint8_t *)v4 + 8);
      if ( v10 == *(volatile uint8_t *)(a1 + 107) )
      {
        event_dispatch("actually remove:%d\n", v10);
        cmd_handler_c((int)(v3 + 16), (void *)(v4));
        *((volatile uint8_t *)v4 + 9) &= ~1u;
      }
      v4 = (volatile int *)*v4;
      if ( !v4 )
        break;
      v8 = v4[1];
      if ( v8 == a2 )
        goto LABEL_8;
    }
  }
  else
  {
    v9 = *((volatile uint32_t *)off_128114 + 10);
    v19 = *(volatile uint32_t *)(a1 + 72);
  }
  v11 = 1;
  if ( (uint8_t)v3[90] <= 1u )
    goto LABEL_9;
LABEL_12:
  if ( *(volatile uint8_t *)(a1 + 86) != 255 )
  {
    sta_get_flags(a1, a2);
    if ( v11 )
      goto LABEL_30;
    goto LABEL_24;
  }
  if ( !*(volatile uint8_t *)(a1 + 1224) )
  {
    if ( v11 )
    {
      *(volatile uint8_t *)(a1 + 85) |= 4u;
      return v9 != v19;
    }
    goto LABEL_25;
  }
  v13 = dword_12810C;
  v14 = *(volatile uint8_t *)(a1 + 1225);
  if ( *(volatile uint8_t *)(dword_12810C + 140 * v14 + 112) != 1 )
  {
    if ( v11 )
    {
      v15 = *(volatile uint8_t *)(a1 + 85);
LABEL_17:
      *(volatile uint8_t *)(a1 + 85) = v15 | 4;
LABEL_18:
      if ( *(volatile uint8_t *)(v13 + 140 * v14 + 112) == 1 )
      {
        v16 = *(volatile uint32_t *)(a1 + 80);
        if ( v16 != a3 && v16 - a3 - 50 < 0 && a3 - v16 - 50 < 0 )
          *(volatile uint32_t *)(a1 + 80) = a3;
      }
      return v9 != v19;
    }
    goto LABEL_25;
  }
  v15 = *(volatile uint8_t *)(a1 + 85);
  if ( (v15 & 0x10) != 0 )
  {
    lld_evt_schedule((volatile uint32_t *)a1);
    *(volatile uint8_t *)(a1 + 85) &= ~0x10u;
    if ( v11 )
      goto LABEL_30;
LABEL_24:
    if ( !*(volatile uint8_t *)(a1 + 1224) || *(volatile uint8_t *)(dword_12810C + 140 * *(volatile uint8_t *)(a1 + 1225) + 112) != 1 )
    {
LABEL_25:
      cmd_handler_c(dword_128110, (volatile uint32_t *)(a1 + 76));
      v17 = *(volatile uint8_t *)(a1 + 85) & 0xFE;
LABEL_26:
      *(volatile uint8_t *)(a1 + 85) = v17 | 2;
      ++v3[91];
      return v9 != v19;
    }
LABEL_35:
    llm_scan_sm_execute(a1, a3, 0);
    v17 = *(volatile uint8_t *)(a1 + 85) | 8;
    goto LABEL_26;
  }
  if ( (*(volatile uint8_t *)(a1 + 85) & 0x40) == 0 )
  {
    if ( v11 )
      goto LABEL_17;
    goto LABEL_35;
  }
  ((int (*)())ke_process_event)(a1, dword_12810C);
  if ( !v11 )
    goto LABEL_24;
LABEL_30:
  v18 = *(volatile uint8_t *)(a1 + 1224);
  *(volatile uint8_t *)(a1 + 85) |= 4u;
  if ( v18 )
  {
    v13 = dword_12810C;
    v14 = *(volatile uint8_t *)(a1 + 1225);
    goto LABEL_18;
  }
  return v9 != v19;
}


// wlc_is_running @ 0x12811c
int wlc_is_running(int result) {
  volatile uint32_t *v1; // r5
  int v2; // r2
  int v3; // r4
  int v4; // r3
  int v5; // r1
  int v6; // r6
  int v7; // r3
  int v8; // r2
  int v9; // r7
  int v10; // r8
  int v11; // r7
  int v12; // r4
  int v13; // r3
  volatile int *v14; // r4
  int v15; // r1
  int v16; // r3
  int v17; // r2
  int v18; // r0
  volatile int *v19; // r2
  int v20; // r2

  v1 = (void *)(uintptr_t)(off_128280);
  if ( *((volatile uint8_t *)off_128280 + 90) > 1u )
  {
    v2 = *(volatile uint8_t *)(result + 85);
    v3 = result;
    if ( (v2 & 0x10) != 0 )
    {
      v4 = dword_128284;
      while ( 1 )
      {
        if ( *(volatile uint8_t *)(v4 + 24) != 255 )
        {
          v5 = *(volatile uint8_t *)(v4 + 27);
          if ( v5 != 255 )
            break;
        }
        v4 += 28;
        if ( dword_128284 + 84 == v4 )
          goto LABEL_7;
      }
      lld_evt_schedule((volatile uint32_t *)(dword_128298 + 1320 * v5));
      v2 = (v2 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v3 + 85)) & 0xFFu);
LABEL_7:
      v2 &= 0xEFu;
      *(volatile uint8_t *)(v3 + 85) = v2;
    }
    result = v2 << 30;
    if ( (v2 & 2) == 0 )
    {
      v6 = v1[9];
      if ( (v2 & 4) != 0 )
        *(volatile uint8_t *)(v3 + 85) = v2 & 0xFB;
      if ( !v6 || *(volatile uint32_t *)(v6 + 12) != v3 + 76 )
        return llm_scan_sm_execute(v3, *(volatile uint32_t *)(v3 + 36), 0);
      v9 = *(volatile uint32_t *)(v3 + 80);
      v10 = *(volatile uint32_t *)(v3 + 36);
      if ( v9 - v10 < 0 )
      {
        if ( v10 - 4000 - v9 - get_constant_1000() < 0 )
        {
LABEL_23:
          v11 = *(volatile uint32_t *)(v3 + 36);
          *(volatile uint32_t *)(v3 + 80) = v11;
          result = get_constant_1000();
          if ( (int)(v11 - *(volatile uint32_t *)(v6 + 4) - result - 4000) < 0 )
          {
            v12 = *(volatile uint32_t *)(v3 + 80);
            result = get_constant_1000();
            v13 = v1[18];
            *(volatile uint32_t *)(v6 + 4) = v12 - 4000 - result;
            if ( v13 == v6 )
            {
              fault_handler(dword_128288);
              v1[18] = v6;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_12828C = 1;
              }
              v14 = (volatile int *)off_128294;
              v15 = *(volatile uint32_t *)(v6 + 4);
              v16 = *(volatile uint32_t *)off_128294;
              v17 = v15 - *((volatile uint32_t *)off_128290 + 4);
              v18 = *(volatile uint32_t *)off_128294 + 1;
              *(volatile uint32_t *)off_128294 = v18;
              if ( v17 - 64 >= 0 )
              {
                result = unknown_worker((void *)(uintptr_t)(dword_128288), v15);
                if ( *v14 )
                {
                  v7 = *v14 - 1;
                  v8 = *(volatile uint32_t *)off_12828C;
                  *v14 = v7;
                  if ( !v7 )
                  {
                    if ( v8 )
                      __enable_irq();
                  }
                }
              }
              else
              {
                if ( v18 )
                {
                  v19 = (volatile int *)off_12828C;
                  *v14 = v16;
                  v20 = *v19;
                  if ( !v16 )
                  {
                    if ( v20 )
                      __enable_irq();
                  }
                }
                return ((int ( *)(int))v1[17])(v6);
              }
            }
          }
          return result;
        }
        v10 = *(volatile uint32_t *)(v3 + 36);
        v9 = *(volatile uint32_t *)(v3 + 80);
      }
      if ( v10 - v9 >= 0 || v9 - 4000 - v10 - get_constant_1000() >= 0 )
      {
        ke_task_poll();
        llm_scan_sm_execute(v3, *(volatile uint32_t *)(v3 + 36), 0);
        return bt_link_cfg_set(v3, *((volatile uint32_t *)off_128290 + 4), 0);
      }
      goto LABEL_23;
    }
  }
  return result;
}



// rx_validate_entry @ 0x12829c
int rx_validate_entry(int result) {
  void *v1; // r5
  int v2; // r4
  int v3; // r3
  int v4; // r6
  int v5; // r7
  char v6; // r3
  char v7; // r2
  int v8; // r8
  int v9; // r2
  int v10; // r3
  char v11; // r2

  v1 = (void *)(uintptr_t)(off_1283C8);
  v2 = result;
  v3 = *(volatile uint8_t *)(result + 85);
  if ( *((volatile uint8_t *)off_1283C8 + 90) <= 1u )
  {
    result = v3 << 30;
    if ( (v3 & 2) != 0 )
    {
      v3 = (v3 & ~0xFFu) | ((uint8_t)(v3 & 0xFD) & 0xFFu);
      *(volatile uint8_t *)(v2 + 85) = v3;
      v11 = *((volatile uint8_t *)v1 + 91) - 1;
      *((volatile uint8_t *)v1 + 91) = v11;
      if ( !v11 && (*((volatile uint8_t *)v1 + 88) & 0x40) != 0 )
      {
        result = dma_setup_transfer(*((volatile uint32_t *)v1 + 20));
        v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v2 + 85)) & 0xFFu);
      }
    }
    if ( (v3 & 4) != 0 )
    {
      v3 = (v3 & ~0xFFu) | ((uint8_t)(v3 & 0xFB) & 0xFFu);
      *(volatile uint8_t *)(v2 + 85) = v3;
    }
    if ( (v3 & 0x20) != 0 )
      *(volatile uint8_t *)(v2 + 85) = v3 & 0xDF;
  }
  else
  {
    if ( (v3 & 0x20) != 0 )
    {
      result = wlc_calc_txrate(result);
      v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v2 + 85)) & 0xFFu);
      v5 = *(volatile uint32_t *)(v2 + 36);
      v4 = v3 & 4;
      if ( (v3 & 4) == 0 )
      {
LABEL_4:
        if ( (v3 & 2) != 0 )
        {
          v6 = v3 & 0xFD;
          *(volatile uint8_t *)(v2 + 85) = v6;
          v7 = *((volatile uint8_t *)v1 + 91) - 1;
          *((volatile uint8_t *)v1 + 91) = v7;
          if ( !v7 )
          {
            if ( (*((volatile uint8_t *)v1 + 88) & 0x40) != 0 )
            {
              result = dma_setup_transfer(*((volatile uint32_t *)v1 + 20));
              v6 = *(volatile uint8_t *)(v2 + 85);
            }
            else
            {
              v4 = 1;
            }
          }
          v8 = *(volatile uint32_t *)(v2 + 80);
          if ( (v6 & 8) != 0 )
          {
            v9 = *(volatile uint8_t *)(v2 + 106);
            *(volatile uint8_t *)(v2 + 85) = v6 & 0xF7;
            if ( v9 )
            {
              if ( v9 == 2 )
                v10 = *(volatile uint16_t *)(v2 + 222);
              else
                v10 = 102400;
              if ( v9 == 2 )
                v10 <<= 10;
            }
            else
            {
              v10 = *(volatile uint32_t *)(dword_1283D0 + 696 * *(volatile uint8_t *)(v2 + 116) + 8);
            }
            v8 -= v10;
          }
          else
          {
            result = llm_scan_sm_execute(v2, v5, 0);
          }
          if ( v4 )
          {
            if ( !*((volatile uint32_t *)v1 + 11) )
              return bt_link_cfg_set(v2, *((volatile uint32_t *)off_1283CC + 4), *((volatile uint32_t *)off_1283CC + 4) - v8);
          }
        }
        return result;
      }
    }
    else
    {
      v4 = v3 & 4;
      v5 = *(volatile uint32_t *)(result + 36);
      if ( (v3 & 4) == 0 )
        goto LABEL_4;
    }
    if ( (v3 & 1) == 0 )
    {
      result = llm_scan_sm_execute(v2, v5, 0);
      v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v2 + 85)) & 0xFFu);
    }
    *(volatile uint8_t *)(v2 + 85) = v3 & 0xFB;
  }
  return result;
}



// tx_enqueue_frame @ 0x1283d4
int tx_enqueue_frame(int result) {
  int v1; // r7
  int v2; // r5
  volatile uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  int16_t v6; // r5
  int16_t v7; // r4
  int v8; // r2

  v1 = *(volatile uint32_t *)(result + 72);
  v2 = result;
  if ( **(volatile int16_t **)off_128474 < 0 && !v1 )
    result = mmio_clear_register(dword_128488, dword_128484, 3591);
  v3 = (void *)(uintptr_t)(off_128478);
  if ( (*((volatile uint8_t *)off_128478 + 88) & 0x20) == 0 && *((volatile uint8_t *)off_128478 + 90) > 1u )
  {
    v4 = *(volatile uint8_t *)(v2 + 116);
    v5 = ke_msg_alloc(70, *((volatile uint8_t *)off_128478 + 88) & 0x20, *((volatile uint8_t *)off_128478 + 88) & 0x20, 20);
    *(volatile uint8_t *)v5 = 0;
    *(volatile uint8_t *)(v5 + 1) = *(volatile uint8_t *)(v2 + 107);
    *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 4);
    *(volatile uint8_t *)(v5 + 3) = *(volatile uint8_t *)(v1 + 5);
    v6 = *(volatile uint16_t *)(v1 + 8);
    v7 = *(volatile uint16_t *)(v1 + 10);
    v8 = dword_12847C;
    *(volatile uint16_t *)(v5 + 4) = *(volatile uint16_t *)(v1 + 6);
    *(volatile uint16_t *)(v5 + 6) = v6;
    *(volatile uint16_t *)(v5 + 8) = v7;
    *(volatile uint8_t *)(v5 + 16) = *(volatile uint8_t *)(v1 + 12);
    *(volatile uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_128480
                                         * (uint64_t)(unsigned int)(*(volatile uint32_t *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = (int)(uintptr_t)(ke_msg_send_2(v5));
    v3[88] |= 0x20u;
  }
  return result;
}



// nullsub_5 @ 0x12848c
int nullsub_5(void) {
  return 0;
}


// wlc_get_ops @ 0x128490
BOOL wlc_get_ops(int a1) {
  int v1; // r3
  int v2; // r2

  v1 = *((volatile uint32_t *)off_1284CC + 10);
  if ( v1
    && (v2 = *(volatile uint32_t *)(a1 + 72), *(volatile uint16_t *)(v1 + 4) == *(volatile uint16_t *)(v2 + 4))
    && *(volatile uint8_t *)(v1 + 13) == *(volatile uint8_t *)(v2 + 13)
    && *(volatile uint16_t *)(v1 + 6) == *(volatile uint16_t *)(v2 + 6)
    && *(volatile uint16_t *)(v1 + 8) == *(volatile uint16_t *)(v2 + 8) )
  {
    return *(volatile uint16_t *)(v1 + 10) == *(volatile uint16_t *)(v2 + 10);
  }
  else
  {
    return 0;
  }
}



// wlc_get_ops_alt @ 0x1284d0
BOOL wlc_get_ops_alt(int a1) {
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((volatile uint32_t *)off_12851C + 10);
  if ( !v1 )
    return 0;
  v2 = *(volatile uint8_t *)(v1 + 24);
  if ( v2 <= 2 )
    return *(volatile uint32_t *)(a1 + 72) == v1;
  if ( *(volatile uint32_t *)(a1 + 72) && !*(volatile uint8_t *)(a1 + 1224) && v2 == 4 )
    return wlc_get_ops(a1);
  return *(volatile uint8_t *)(v1 + 26) == *(volatile uint8_t *)(a1 + 107);
}



// wlc_ops_wrapper @ 0x128520
BOOL wlc_ops_wrapper(int a1) {
  BOOL result; // r0

  result = wlc_get_ops_alt(a1);
  if ( result )
    return !*((volatile uint32_t *)off_128544 + 11) || *(volatile uint8_t *)(*((volatile uint32_t *)off_128544 + 10) + 16) == 6;
  return result;
}



// get_control_byte @ 0x128548
int get_control_byte(int result) {
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  volatile uint32_t *v5; // r2
  volatile uint32_t *v6; // r2
  int v7; // r3
  int v8; // r2

  if ( *(volatile uint8_t *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_1285B4;
    while ( 1 )
    {
      v3 = *(volatile uint32_t *)(v2 + 72);
      v2 += 1320;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v7 = dword_1285B4 + 1320 * v1;
    v8 = *(volatile char *)(v7 + 110);
    v4 = *(volatile char *)(v7 + 109);
    if ( v4 >= v8 )
      v4 = v8;
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = (void *)(uintptr_t)(off_1285B8);
    *(volatile uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return util_format(v4);
  }
  else
  {
    v6 = (void *)(uintptr_t)(off_1285B8);
    *(volatile uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return util_format(15);
  }
  return result;
}



