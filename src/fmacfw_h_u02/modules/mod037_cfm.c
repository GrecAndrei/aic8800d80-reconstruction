// llc_state_reset @ 0x12723c
/* luna: Resets shared LLC bookkeeping under interrupt protection, then conditionally handles state-specific events and IPC notifications for the supplied cont */
int llc_state_reset(int a1, int a2) {
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

  v2 = (void *)(uintptr_t)(off_1274DC);
  *((volatile uint32_t *)off_1274DC + 10) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_1274E0 = 1;
  }
  v5 = (void *)(uintptr_t)(off_1274E4);
  v6 = (void *)(uintptr_t)(off_1274E8);
  v7 = *(volatile uint32_t *)off_1274E4;
  result = *(volatile uint32_t *)off_1274E4 + 1;
  v9 = *((volatile uint32_t *)off_1274E8 + 1) & 0xFFFFFFFD;
  *(volatile uint32_t *)off_1274E4 = result;
  v6[1] = v9;
  if ( result )
  {
    v10 = (volatile int *)off_1274E0;
    *v5 = v7;
    v11 = *v10;
    if ( !v7 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  *(volatile uint32_t *)off_1274EC = (4 * (uint8_t)v2[92]) & 4 | *(volatile uint32_t *)off_1274EC & 0xFFFFFFFB;
  if ( a2 )
    goto LABEL_6;
  result = ke_evt_handler();
  if ( !LOBYTE(((volatile uint32_t *)(uintptr_t)off_1274F0)[102]) )
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
        result = (int)ipc_post_msg(a1);
        v14 = (uint8_t)v2[88];
      }
      else
      {
        v14 &= 0xDBu;
      }
    }
    goto LABEL_8;
  }
  v15 = *((volatile uint8_t *)off_1274F4 + 3850);
  if ( v15 || *((volatile uint8_t *)off_1274F8 + 10) + 1 != *(volatile uint8_t *)(*(volatile uint32_t *)off_1274F8 + 367) )
    goto LABEL_23;
  v16 = *(volatile uint32_t *)off_1274F4;
  if ( *(volatile uint8_t *)(*(volatile uint32_t *)off_1274F4 + 367) )
  {
    v17 = 0;
    do
    {
      v18 = *(volatile uint8_t *)(v16 + 2);
      ++v17;
      v16 += 6;
      if ( v18 == *((volatile uint8_t *)off_1274F4 + 3851) + 1 )
        goto LABEL_23;
    }
    while ( v17 != *(volatile uint8_t *)(*(volatile uint32_t *)off_1274F4 + 367) );
  }
  v30 = (void *)(uintptr_t)(off_127524);
  if ( *((volatile uint16_t *)off_127524 + 2) <= 1u && *((volatile uint16_t *)off_127524 + 3) <= 1u )
  {
LABEL_50:
    v39 = (void *)(uintptr_t)(off_127508);
    v40 = **(volatile int16_t **)off_127504;
    *((volatile uint32_t *)off_127508 + 1) |= 0x100040u;
    if ( v40 < 0 && *(volatile uint32_t *)off_127510 << 28 )
      mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
    v38 = 1;
    *(volatile uint32_t *)off_12750C = *v39 | v39[1];
    v15 = 1;
    goto LABEL_48;
  }
  v31 = 0;
  while ( !*((volatile uint16_t *)off_1274F4 + 2) )
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
    v34 = (volatile char *)off_1274F4 + 60 * v32;
    v35 = (uint8_t)(v32 + 1);
    v32 = v35;
    if ( *(volatile uint8_t *)(*((volatile uint32_t *)v34 + 13) + 2) != v31 || !v34[16] || v34[64] < -79 )
      goto LABEL_38;
    if ( v33 )
      break;
    v33 = 1;
LABEL_38:
    if ( v35 >= *((volatile uint16_t *)off_1274F4 + 2) )
      goto LABEL_44;
  }
  v36 = (void *)(uintptr_t)(off_127508);
  v37 = **(volatile int16_t **)off_127504;
  *((volatile uint32_t *)off_127508 + 1) &= 0xFFEFFFBF;
  if ( v37 < 0 && *(volatile uint32_t *)off_127510 << 28 )
    mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
  *(volatile uint32_t *)off_12750C = *v36 | v36[1];
  v38 = 0;
LABEL_48:
  v30[8] = v15;
  result = alloc_tx_event("single ssid %d\n", v38);
LABEL_6:
  v12 = *(volatile uint8_t *)(a1 + 24);
  if ( v12 != 3 )
    goto LABEL_7;
LABEL_23:
  v2[88] &= ~8u;
  v19 = (volatile uint16_t *)rf_get_buffer();
  v20 = (volatile uint16_t *)tx_send_pdu(79, 13, 0, 12);
  *v20 = *v19;
  v21 = (int)v20;
  v22 = hci_buffer_get((int)v19);
  v23 = dword_1274FC;
  v24 = (volatile unsigned int *)off_127520;
  v25 = (void *)(uintptr_t)(off_127500);
  *(volatile uint32_t *)(v21 + 4) = (unsigned int)(((unsigned int)dword_1274FC * (uint64_t)(unsigned int)v22) >> 32) >> 6;
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
  rx_process_packet_1(v21);
  v27 = (void *)(uintptr_t)(off_127508);
  v28 = **(volatile int16_t **)off_127504;
  v29 = *((volatile uint32_t *)off_127508 + 1) & 0xFFFFDDFF;
  *((volatile uint32_t *)off_127508 + 1) = v29;
  if ( v28 < 0 && *(volatile uint32_t *)off_127510 << 28 )
  {
    mmio_write_field((int)aNxmacCurrentSt, (int)aMmRxFilterSet_2, 472);
    v29 = v27[1];
  }
  *(volatile uint32_t *)off_12750C = v29 | *v27;
  result = mac_write_header_word(142, 2, 255);
  v14 = (uint8_t)v2[88];
LABEL_8:
  *(volatile uint8_t *)(a1 + 24) = -1;
  v2[88] = v14 & 0xEF;
  if ( !(v14 << 30) )
  {
    if ( a2 )
      return result;
    return ke_evt_poll();
  }
  result = llc_flag_test_bit4();
  if ( !a2 )
    return ke_evt_poll();
  return result;
}


// llc_version_read @ 0x127528
/* luna: Handles a channel-timer switch by reconciling the current and pending descriptors and advancing the selected descriptor's state. */
int llc_version_read(volatile uint32_t *a1) {
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

  v1 = (volatile int16_t **)off_127738;
  v2 = (void *)(uintptr_t)(off_12773C);
  v4 = list_pop(dword_127740);
  v5 = v4;
  if ( **v1 >= 0 )
  {
    v6 = (uint8_t)*v2;
    if ( *v2 )
    {
LABEL_3:
      v7 = (void *)(uintptr_t)(off_127744);
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
    irq_disable_mmio_write((int)aVoidChSwitchEn, (int)aChanTmrSwitchC, 1958);
    v6 = (uint8_t)*v2;
    if ( *v2 )
      goto LABEL_3;
    if ( **v1 >= 0 )
    {
LABEL_25:
      v7 = (void *)(uintptr_t)(off_127744);
      goto LABEL_5;
    }
  }
  v7 = (void *)(uintptr_t)(off_127744);
  v8 = *((volatile uint32_t *)off_127744 + 10);
  if ( v8 )
    goto LABEL_6;
  irq_disable_mmio_write((int)aChanEnvCurrent, (int)aChanTmrSwitchC, 1960);
  v6 = (uint8_t)*v2;
LABEL_4:
  if ( v6 != 1 )
  {
LABEL_5:
    v8 = v7[10];
    goto LABEL_6;
  }
  alloc_tx_event("cb:%x,%x\n", *((volatile uint8_t *)v7 + 88), v7[11]);
  v23 = *((volatile uint8_t *)v7 + 88);
  if ( (v23 & 8) != 0 )
  {
    v24 = dword_12777C;
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
    v24 = dword_127760;
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
    alloc_tx_event(aCbSetState, v22);
    hci_cmd_preprocess(2u, 3);
    v27 = *(volatile uint8_t *)(v24 + 24);
  }
  if ( v27 <= 2 )
    goto LABEL_5;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(volatile uint32_t *)off_127750 = 1;
  }
  v28 = (void *)(uintptr_t)(off_127758);
  v29 = (void *)(uintptr_t)(off_127764);
  v30 = *(volatile uint32_t *)off_127758;
  v31 = *(volatile uint32_t *)off_127758 + 1;
  v32 = *((volatile uint32_t *)off_127764 + 1) | 2;
  *(volatile uint32_t *)off_127758 = v31;
  v29[1] = v32;
  if ( v31 )
  {
    v33 = (volatile int *)off_127750;
    *v28 = v30;
    v34 = *v33;
    if ( !v30 )
    {
      if ( v34 )
        __enable_irq();
    }
  }
  v35 = (void *)(uintptr_t)(off_127768);
  v8 = v7[10];
  *((volatile uint8_t *)v7 + 92) = (*(volatile uint32_t *)off_127768 & 4) != 0;
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
      v12 = (volatile char *)off_127780;
      if ( *((volatile uint8_t *)off_127780 + 24) == 255 )
      {
        if ( *((volatile uint8_t *)off_127780 + 52) == 255 )
        {
          if ( *((volatile uint8_t *)off_127780 + 80) == 255 )
          {
            v5[2] = v10;
            goto LABEL_14;
          }
          v12 = (volatile char *)off_127780 + 56;
        }
        else
        {
          v12 = (volatile char *)off_127780 + 28;
        }
      }
    }
    else
    {
      v12 = *(volatile char **)(dword_127748 + 1320 * *(volatile uint8_t *)(v10 + 8) + 72);
    }
    v5[2] = (int)(uintptr_t)(v12);
  }
  else
  {
    v12 = (volatile char *)v5[2];
  }
  if ( v12 )
    llc_conn_command((int)(uintptr_t)(v12));
LABEL_14:
  wlan_ioctl_handler_1(dword_12774C, v5);
  v13 = v7[10];
  if ( *(volatile uint8_t *)(v13 + 24) > 2u )
    llc_state_reset(v13, 0);
  result = v7[8];
  v7[18] = result;
  if ( result )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_127750 = 1;
    }
    v15 = (volatile int *)off_127758;
    v16 = *(volatile uint32_t *)(result + 4);
    v17 = (*(volatile uint32_t *)0x40501010u);
    v18 = *(volatile uint32_t *)off_127758;
    v19 = *(volatile uint32_t *)off_127758 + 1;
    *(volatile uint32_t *)off_127758 = v19;
    if ( (int)(v16 - v17 - 64) >= 0 )
    {
      result = mem_copy_util((volatile uint32_t *)dword_12776C, v16);
      if ( *v15 )
      {
        v36 = *v15 - 1;
        v37 = *(volatile uint32_t *)off_127750;
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
        v20 = (volatile int *)off_127750;
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


// llc_obj_release @ 0x127788
/* luna: Refreshes the connection's RF readiness value, passes it to low-level RF processing, and updates a connection flag. */
int llc_obj_release(int a1) {
  int v2; // r0
  int result; // r0

  v2 = rf_is_ready(*(volatile uint32_t *)(a1 + 88));
  *(volatile uint32_t *)(a1 + 88) = v2;
  result = lll_conn_rf_process(a1, v2);
  *(volatile uint8_t *)(a1 + 85) = *(volatile uint8_t *)(a1 + 85) & 0x9F | 0x20;
  return result;
}



// llc_buf_advance @ 0x1277b0
/* luna: Copies the pending payload into the LLC event buffer, clears a status flag, and saves the receive event, optionally dispatching a matching transmit ev */
int llc_buf_advance(int a1) {
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = mem_copy_util((void *)(uintptr_t)(a1 + 24), *(volatile uint32_t *)(a1 + 36) + *(volatile uint32_t *)(a1 + 88));
  v3 = *(volatile uint8_t *)(a1 + 85);
  *(volatile uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((volatile uint32_t *)off_127810 + 9);
    if ( v4 && *(volatile uint32_t *)(v4 + 12) == a1 + 76 )
    {
      llc_env_get();
      llc_rx_event_save(a1, *(volatile uint32_t *)(a1 + 36), 0);
      return llc_tx_evt_handler(a1, *((volatile uint32_t *)off_127814 + 4), 0);
    }
    else
    {
      return llc_rx_event_save(a1, *(volatile uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}



// llc_env_by_conhdl @ 0x127818
/* luna: Checks calibration for the indexed link, records its signed offset, and may derive a shared compensation from matching peer offsets. */
int llc_env_by_conhdl(int result, int16_t a2) {
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

  v2 = dword_1278D8;
  v3 = *(volatile uint8_t *)(result + 86);
  v4 = dword_1278D8 + 1320 * v3;
  v5 = *(volatile uint8_t *)(v4 + 85) & 0x60;
  if ( (*(volatile uint8_t *)(v4 + 85) & 0x60) == 0 )
  {
    v6 = result;
    result = rf_check_cal_state(dword_1278D8 + 1320 * v3, *(volatile uint8_t *)(result + 87));
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
      v10 = *((volatile uint32_t *)off_1278D4 + 2);
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



// llc_env_init @ 0x1278dc
/* luna: Initializes the LLC environment, resets its per-entry state and statistics buffers, and installs static environment pointers. */
int llc_env_init() {
  volatile int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  volatile int *i; // r4
  int result; // r0
  volatile uint32_t *v5; // r3
  void *v6; // r1

  v0 = (volatile int *)off_12796C;
  v1 = (void *)(uintptr_t)(off_127968);
  memset((volatile int *)off_127968, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    memset(i, 0, 0x1Cu);
    *((volatile uint16_t *)i + 7) = 255;
    *((volatile uint8_t *)i + 24) = -1;
    *((volatile uint8_t *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      wlan_ioctl_handler_1((int)v1, (void *)(i));
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
  clear_stats_buf((volatile uint32_t *)dword_127970);
  clear_stats_buf((volatile uint32_t *)dword_127974);
  wlan_ioctl_handler_1(dword_127970, (volatile uint32_t *)dword_127978);
  wlan_ioctl_handler_1(dword_127970, (volatile uint32_t *)dword_12797C);
  wlan_ioctl_handler_1(dword_127970, (volatile uint32_t *)dword_127980);
  result = wlan_ioctl_handler_1(dword_127970, (volatile uint32_t *)dword_127984);
  v5 = (void *)(uintptr_t)(off_127968);
  v6 = (void *)(uintptr_t)(off_12798C);
  *((volatile uint32_t *)off_127968 + 13) = off_127988;
  v5[17] = (int)(uintptr_t)(v6);
  v5[18] = 0;
  return result;
}


// wifi_disable_get @ 0x127990
/* luna: Copies the supplied Wi-Fi disable parameters into CFM state, marks the operation active, sets a related control flag, and returns LLC flag bit 4. */
int wifi_disable_get(volatile int16_t *a1, int a2, char a3) {
  volatile uint8_t *v3; // r4
  int16_t v7; // r3
  volatile uint8_t *v8; // r2

  v3 = (void *)(uintptr_t)(off_127A0C);
  if ( **(volatile int16_t **)off_127A08 < 0 && *((volatile uint8_t *)off_127A0C + 108) != 255 )
    irq_disable_mmio_write(dword_127A18, dword_127A14, 2838);
  v3[108] = 3;
  *((volatile uint16_t *)v3 + 49) = 255;
  v3[88] = *((volatile uint8_t *)a1 + 2);
  v7 = *a1;
  *((volatile uint16_t *)v3 + 46) = *a1;
  *((volatile uint16_t *)v3 + 45) = v7;
  v8 = (void *)(uintptr_t)(off_127A10);
  v3[96] = *((volatile uint8_t *)a1 + 4);
  v7 = (v7 & ~0xFFu) | ((uint8_t)(v8[88]) & 0xFFu);
  v3[97] = *((volatile uint8_t *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((volatile uint32_t *)v3 + 26) = a2;
  v3[100] = 1;
  return llc_flag_test_bit4();
}



// cfm_event_handler @ 0x127a1c
/* luna: Processes remain-on-channel events, updating ROC state, posting IPC notifications, and clearing associated radio state. */
int cfm_event_handler(volatile uint8_t *a1, int a2) {
  volatile uint8_t *roc_context; // r7
  int event_status; // r5
  unsigned int roc_state; // r3
  volatile uint32_t *v7; // r8
  char v8; // r3
  volatile uint8_t *v10; // r8
  char v11; // r3
  volatile uint32_t *v12; // r0
  volatile uint8_t *v13; // r2
  int16_t v14; // r1
  unsigned int event_duration; // r1
  int adjusted_duration_ms; // r2
  int v17; // r0
  volatile uint32_t *v18; // r0

  roc_context = (void *)(uintptr_t)(off_127BDC);
  check_feature_flag(8, "roc: %d, dur=%d, st=%d\r\n", *a1, *((volatile uint32_t *)a1 + 3), *((volatile uint8_t *)off_127BDC + 128));
  event_status = *a1;
  if ( *a1 )
  {
    if ( event_status == 1 )
    {
      if ( (uint8_t)roc_context[136] == 255 )
        return 0;
      roc_state = (uint8_t)roc_context[128];
      v7 = (void *)(uintptr_t)(off_127BF0);
      if ( roc_state > 3 )
      {
        if ( roc_state == 4 )
        {
          mem_set_util((int)(uintptr_t)((volatile uint32_t *)off_127BF0 + 16));
          v12 = (volatile uint32_t *)v7[8];
          v7[18] = 0;
          llc_version_read(v12);
        }
      }
      else if ( roc_state > 1 )
      {
        v13 = *((volatile uint8_t **)off_127BF0 + 11);
        *((volatile uint8_t *)off_127BF0 + 88) &= ~4u;
        if ( v13 )
        {
          if ( v13 == roc_context + 112 && (volatile uint8_t *)v7[20] == v13 )
          {
            mem_set_util((int)(uintptr_t)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        ipc_post_msg(dword_127BE4);
      }
      else if ( roc_state == 1 )
      {
        *((volatile uint8_t *)off_127BF0 + 88) &= 0xFAu;
        ipc_post_msg((int)(roc_context + 112));
      }
      v8 = *((volatile uint8_t *)v7 + 88);
      roc_context[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v18 = (volatile uint32_t *)dword_127BEC;
      *((volatile uint8_t *)v7 + 88) = v8 & 0xEF;
      event_status = 0;
      mem_set_util((int)(uintptr_t)(v18));
      return event_status;
    }
    return 1;
  }
  if ( (uint8_t)roc_context[136] != 255 || roc_context[128] == 4 || hci_cmd_handler(4u) == 1 )
  {
    v10 = (void *)(uintptr_t)(off_127BF0);
    v11 = *((volatile uint8_t *)off_127BF0 + 88);
    if ( (v11 & 0x20) == 0 )
      return 1;
  }
  else
  {
    v10 = (void *)(uintptr_t)(off_127BF0);
    if ( !*((volatile uint8_t *)off_127BF0 + 91) )
    {
      v11 = *((volatile uint8_t *)off_127BF0 + 88);
      goto LABEL_25;
    }
    v11 = *((volatile uint8_t *)off_127BF0 + 88);
    if ( (v11 & 0x20) == 0 )
    {
LABEL_25:
      roc_context[136] = 4;
      roc_context[116] = a1[2];
      roc_context[117] = a1[3];
      v14 = *((volatile uint16_t *)a1 + 3);
      *((volatile uint16_t *)roc_context + 59) = *((volatile uint16_t *)a1 + 2);
      *((volatile uint16_t *)roc_context + 61) = *((volatile uint16_t *)a1 + 4);
      *((volatile uint16_t *)roc_context + 60) = v14;
      roc_context[124] = a1[16];
      roc_context[128] = 1;
      roc_context[125] = 0;
      event_duration = *((volatile uint32_t *)a1 + 3);
      *((volatile uint16_t *)roc_context + 63) = a2;
      adjusted_duration_ms = 1000 * event_duration;
      if ( event_duration > 0x23 )
        adjusted_duration_ms -= 35000;
      *((volatile uint32_t *)roc_context + 33) = adjusted_duration_ms;
      roc_context[138] = a1[1];
      if ( a2 )
      {
        v10[88] = v11 | 1;
        llc_flag_test_bit4();
      }
      else
      {
        v17 = dword_127BE4;
        v10[88] = v11 | 4;
        llc_hw_reg_sync(v17);
      }
      *(volatile uint32_t *)off_127BE8 |= 4u;
      return event_status;
    }
  }
  v10[88] = v11 & 0xDF;
  return 1;
}


// cfm_radio_check @ 0x127bf4
/* luna: Finds or updates a matching radio record, allocating a free record on a miss and returning its handle, or 1 if none is available. */
int cfm_radio_check(volatile uint8_t *a1, volatile uint8_t *a2) {
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

  v2 = dword_127CB4;
  v5 = dword_127CB4;
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
          v13 = dword_127CB4 + 28 * i;
          v14 = (void *)(uintptr_t)(off_127CB8);
          *(volatile uint8_t *)(v13 + 5) = v12;
          v15 = *((volatile uint16_t *)a1 + 2);
          *(volatile uint16_t *)(v13 + 10) = *((volatile uint16_t *)a1 + 3);
          v16 = v14[10];
          *(volatile uint16_t *)(v13 + 8) = v15;
          if ( v16 == v13 && *((volatile uint8_t *)v14 + 90) == 1 )
            check_boot_flag((volatile uint16_t *)(v2 + 28 * i + 4), 0);
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
  v7 = (int)(uintptr_t)(list_pop(off_127CB8));
  if ( !v7 )
    return 1;
  v8 = dword_127CBC * ((v7 - v2) >> 2);
  *(volatile uint8_t *)(v7 + 24) = v8;
  *a2 = v8;
  v9 = *((volatile uint32_t *)a1 + 1);
  *(volatile uint32_t *)(v7 + 4) = *(volatile uint32_t *)a1;
  *(volatile uint32_t *)(v7 + 8) = v9;
  *(volatile uint16_t *)(v7 + 12) = *((volatile uint16_t *)a1 + 4);
  return 0;
}



// wifi_disable_calc @ 0x127cc0
/* luna: Notifies the hardware about channel-context removal when needed, then clears the indexed 28-byte context entry. */
int wifi_disable_calc(int a1) {
  volatile int16_t **v1; // r8
  int chan_ctx_table; // r5
  volatile int *chan_ctx; // r6
  int v5; // r7
  int v6; // r4
  int result; // r0

  v1 = (volatile int16_t **)off_127D60;
  chan_ctx_table = dword_127D4C;
  chan_ctx = (volatile int *)(dword_127D4C + 28 * a1);
  if ( **(volatile int16_t **)off_127D60 < 0 )
  {
    v5 = 8 * a1;
    if ( *(volatile uint8_t *)(dword_127D4C + 28 * a1 + 24) != 255
      || (irq_disable_mmio_write((int)aCtxtIdxChanCtx, (int)aChanCtxtDel, 3044), **v1 < 0) )
    {
      if ( *(volatile uint8_t *)(chan_ctx_table + 4 * (v5 - a1) + 25) )
        irq_disable_mmio_write((int)aCtxtNbLinkedVi, (int)aChanCtxtDel, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  wlan_ioctl_handler_1(dword_127D50, (void *)(chan_ctx));
  v6 = chan_ctx_table + 4 * (v5 - a1);
  result = (int)memset(chan_ctx, 0, 0x1Cu);
  *(volatile uint16_t *)(v6 + 14) = 255;
  *(volatile uint8_t *)(v6 + 24) = -1;
  *(volatile uint8_t *)(v6 + 27) = -1;
  return result;
}


// cfm_mac_info @ 0x127d64
/* luna: Copies the indexed 10-byte MAC-info payload into its record and, if that record is active, runs the guarded DMA and boot initialization sequence. */
int cfm_mac_info(volatile uint8_t *a1) {
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
  v4 = dword_127DF0;
  v5 = *((volatile uint32_t *)off_127DEC + 10);
  v6 = *((volatile uint32_t *)v3 + 1);
  v7 = dword_127DF0 + 28 * v1 + 4;
  *(volatile uint32_t *)v7 = result;
  *(volatile uint32_t *)(v7 + 4) = v6;
  *(volatile uint16_t *)(v7 + 8) = *((volatile uint16_t *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(volatile uint32_t *)off_127DF4 = 1;
    }
    v8 = (volatile int *)off_127DF8;
    ++*(volatile uint32_t *)off_127DF8;
    disable_watchdog();
    dma_ring_init(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(volatile uint32_t *)off_127DF4;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    check_boot_flag((volatile uint16_t *)v3, 0);
    return call_stack_helper(*(volatile char *)(v4 + 28 * v1 + 12));
  }
  return result;
}



// cfm_dword_get @ 0x127dfc
/* luna: Processes a CFM receive-activity event, prunes older queued entries, updates per-link event state, and reports whether the link's cached state differs */
BOOL cfm_dword_get(int a1, int a2, int a3) {
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

  v3 = (void *)(uintptr_t)(off_127FD4);
  v4 = *((volatile int **)off_127FD4 + 4);
  if ( v4 )
  {
    v8 = v4[1];
    v9 = *((volatile uint32_t *)off_127FD4 + 10);
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
        alloc_tx_event("actually remove:%d\n", v10);
        wlan_ioctl_handler_3((int)(v3 + 16), (void *)(v4));
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
    v9 = *((volatile uint32_t *)off_127FD4 + 10);
    v19 = *(volatile uint32_t *)(a1 + 72);
  }
  v11 = 1;
  if ( (uint8_t)v3[90] <= 1u )
    goto LABEL_9;
LABEL_12:
  if ( *(volatile uint8_t *)(a1 + 86) != 255 )
  {
    llc_env_by_conhdl(a1, a2);
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
  v13 = dword_127FCC;
  v14 = *(volatile uint8_t *)(a1 + 1225);
  if ( *(volatile uint8_t *)(dword_127FCC + 140 * v14 + 112) != 1 )
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
    rf_mode_setup((volatile uint32_t *)a1);
    *(volatile uint8_t *)(a1 + 85) &= ~0x10u;
    if ( v11 )
      goto LABEL_30;
LABEL_24:
    if ( !*(volatile uint8_t *)(a1 + 1224) || *(volatile uint8_t *)(dword_127FCC + 140 * *(volatile uint8_t *)(a1 + 1225) + 112) != 1 )
    {
LABEL_25:
      wlan_ioctl_handler_3(dword_127FD0, (volatile uint32_t *)(a1 + 76));
      v17 = *(volatile uint8_t *)(a1 + 85) & 0xFE;
LABEL_26:
      *(volatile uint8_t *)(a1 + 85) = v17 | 2;
      ++v3[91];
      return v9 != v19;
    }
LABEL_35:
    llc_rx_event_save(a1, a3, 0);
    v17 = *(volatile uint8_t *)(a1 + 85) | 8;
    goto LABEL_26;
  }
  if ( (*(volatile uint8_t *)(a1 + 85) & 0x40) == 0 )
  {
    if ( v11 )
      goto LABEL_17;
    goto LABEL_35;
  }
  ((int (*)())llc_obj_release)(a1, dword_127FCC);
  if ( !v11 )
    goto LABEL_24;
LABEL_30:
  v18 = *(volatile uint8_t *)(a1 + 1224);
  *(volatile uint8_t *)(a1 + 85) |= 4u;
  if ( v18 )
  {
    v13 = dword_127FCC;
    v14 = *(volatile uint8_t *)(a1 + 1225);
    goto LABEL_18;
  }
  return v9 != v19;
}


// radio_disabled_check @ 0x127fdc
/* luna: Processes a timed LLC RX event, applying pending RF-mode changes and saving events that do not match the active context. */
int radio_disabled_check(int result) {
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

  v1 = (void *)(uintptr_t)(off_128140);
  if ( *((volatile uint8_t *)off_128140 + 90) > 1u )
  {
    v2 = *(volatile uint8_t *)(result + 85);
    v3 = result;
    if ( (v2 & 0x10) != 0 )
    {
      v4 = dword_128144;
      while ( 1 )
      {
        if ( *(volatile uint8_t *)(v4 + 24) != 255 )
        {
          v5 = *(volatile uint8_t *)(v4 + 27);
          if ( v5 != 255 )
            break;
        }
        v4 += 28;
        if ( dword_128144 + 84 == v4 )
          goto LABEL_7;
      }
      rf_mode_setup((volatile uint32_t *)(dword_128158 + 1320 * v5));
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
        return llc_rx_event_save(v3, *(volatile uint32_t *)(v3 + 36), 0);
      v9 = *(volatile uint32_t *)(v3 + 80);
      v10 = *(volatile uint32_t *)(v3 + 36);
      if ( v9 - v10 < 0 )
      {
        if ( v10 - 4000 - v9 - get_timeout_1000() < 0 )
        {
LABEL_23:
          v11 = *(volatile uint32_t *)(v3 + 36);
          *(volatile uint32_t *)(v3 + 80) = v11;
          result = get_timeout_1000();
          if ( (int)(v11 - *(volatile uint32_t *)(v6 + 4) - result - 4000) < 0 )
          {
            v12 = *(volatile uint32_t *)(v3 + 80);
            result = get_timeout_1000();
            v13 = v1[18];
            *(volatile uint32_t *)(v6 + 4) = v12 - 4000 - result;
            if ( v13 == v6 )
            {
              mem_set_util(dword_128148);
              v1[18] = v6;
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(volatile uint32_t *)off_12814C = 1;
              }
              v14 = (volatile int *)off_128154;
              v15 = *(volatile uint32_t *)(v6 + 4);
              v16 = *(volatile uint32_t *)off_128154;
              v17 = v15 - *((volatile uint32_t *)off_128150 + 4);
              v18 = *(volatile uint32_t *)off_128154 + 1;
              *(volatile uint32_t *)off_128154 = v18;
              if ( v17 - 64 >= 0 )
              {
                result = mem_copy_util((void *)(uintptr_t)(dword_128148), v15);
                if ( *v14 )
                {
                  v7 = *v14 - 1;
                  v8 = *(volatile uint32_t *)off_12814C;
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
                  v19 = (volatile int *)off_12814C;
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
      if ( v10 - v9 >= 0 || v9 - 4000 - v10 - get_timeout_1000() >= 0 )
      {
        llc_env_get();
        llc_rx_event_save(v3, *(volatile uint32_t *)(v3 + 36), 0);
        return llc_tx_evt_handler(v3, *((volatile uint32_t *)off_128150 + 4), 0);
      }
      goto LABEL_23;
    }
  }
  return result;
}



// radio_disable_check @ 0x12815c
/* luna: Processes an LLC event buffer according to radio state, clearing consumed flags and routing pending receive or transmit data. */
int radio_disable_check(int result) {
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

  v1 = (void *)(uintptr_t)(off_128288);
  v2 = result;
  v3 = *(volatile uint8_t *)(result + 85);
  if ( *((volatile uint8_t *)off_128288 + 90) <= 1u )
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
        result = llc_hw_reg_sync(*((volatile uint32_t *)v1 + 20));
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
      result = llc_buf_advance(result);
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
              result = llc_hw_reg_sync(*((volatile uint32_t *)v1 + 20));
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
              v10 = *(volatile uint32_t *)(dword_128290 + 696 * *(volatile uint8_t *)(v2 + 116) + 8);
            }
            v8 -= v10;
          }
          else
          {
            result = llc_rx_event_save(v2, v5, 0);
          }
          if ( v4 )
          {
            if ( !*((volatile uint32_t *)v1 + 11) )
              return llc_tx_evt_handler(v2, *((volatile uint32_t *)off_12828C + 4), *((volatile uint32_t *)off_12828C + 4) - v8);
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
      result = llc_rx_event_save(v2, v5, 0);
      v3 = (v3 & ~0xFFu) | ((uint8_t)(*(volatile uint8_t *)(v2 + 85)) & 0xFFu);
    }
    *(volatile uint8_t *)(v2 + 85) = v3 & 0xFB;
  }
  return result;
}



// wifi_disable_action @ 0x128294
/* luna: When the CFM one-shot flag is clear and the state byte exceeds 1, it builds and processes a 20-byte Wi-Fi-disable PDU from the context record and sets */
int wifi_disable_action(int result) {
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
  if ( **(volatile int16_t **)off_128334 < 0 && !v1 )
    result = irq_disable_mmio_write(dword_128348, dword_128344, 3591);
  v3 = (void *)(uintptr_t)(off_128338);
  if ( (*((volatile uint8_t *)off_128338 + 88) & 0x20) == 0 && *((volatile uint8_t *)off_128338 + 90) > 1u )
  {
    v4 = *(volatile uint8_t *)(v2 + 116);
    v5 = tx_send_pdu(70, *((volatile uint8_t *)off_128338 + 88) & 0x20, *((volatile uint8_t *)off_128338 + 88) & 0x20, 20);
    *(volatile uint8_t *)v5 = 0;
    *(volatile uint8_t *)(v5 + 1) = *(volatile uint8_t *)(v2 + 107);
    *(volatile uint8_t *)(v5 + 2) = *(volatile uint8_t *)(v1 + 4);
    *(volatile uint8_t *)(v5 + 3) = *(volatile uint8_t *)(v1 + 5);
    v6 = *(volatile uint16_t *)(v1 + 8);
    v7 = *(volatile uint16_t *)(v1 + 10);
    v8 = dword_12833C;
    *(volatile uint16_t *)(v5 + 4) = *(volatile uint16_t *)(v1 + 6);
    *(volatile uint16_t *)(v5 + 6) = v6;
    *(volatile uint16_t *)(v5 + 8) = v7;
    *(volatile uint8_t *)(v5 + 16) = *(volatile uint8_t *)(v1 + 12);
    *(volatile uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_128340
                                         * (uint64_t)(unsigned int)(*(volatile uint32_t *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = (int)(uintptr_t)(rx_process_packet_1(v5));
    v3[88] |= 0x20u;
  }
  return result;
}



// nullsub_5 @ 0x12834c
int nullsub_5(void) {
  return 0;
}


// cfm_ops_get @ 0x128350
/* luna: Returns whether the global CFM operations descriptor matches the descriptor referenced at offset 72 in the supplied object. */
BOOL cfm_ops_get(int a1) {
  int v1; // r3
  int v2; // r2

  v1 = *((volatile uint32_t *)off_12838C + 10);
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



// cfm_ops_get2 @ 0x128390
/* luna: Checks whether the active CFM operation matches the supplied context using type-specific pointer or identifier comparisons. */
BOOL cfm_ops_get2(int a1) {
  int v1; // r3
  unsigned int v2; // r1

  v1 = *((volatile uint32_t *)off_1283DC + 10);
  if ( !v1 )
    return 0;
  v2 = *(volatile uint8_t *)(v1 + 24);
  if ( v2 <= 2 )
    return *(volatile uint32_t *)(a1 + 72) == v1;
  if ( *(volatile uint32_t *)(a1 + 72) && !*(volatile uint8_t *)(a1 + 1224) && v2 == 4 )
    return cfm_ops_get(a1);
  return *(volatile uint8_t *)(v1 + 26) == *(volatile uint8_t *)(a1 + 107);
}



// cfm_call_ops @ 0x1283e0
/* luna: Returns true when the requested CFM ops entry exists and either the global gate is clear or the associated object's type discriminator equals 6. */
BOOL cfm_call_ops(int a1) {
  BOOL result; // r0

  result = cfm_ops_get2(a1);
  if ( result )
    return !*((volatile uint32_t *)off_128404 + 11) || *(volatile uint8_t *)(*((volatile uint32_t *)off_128404 + 10) + 16) == 6;
  return result;
}



// type_get @ 0x128408
/* luna: Sets the object's type byte from its matching CFM slot, using 15 when the object is inactive, unmatched, or has an invalid slot value. */
int type_get(int result) {
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
    v2 = dword_128474;
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
    v7 = dword_128474 + 1320 * v1;
    v8 = *(volatile char *)(v7 + 110);
    v4 = *(volatile char *)(v7 + 109);
    if ( v4 >= v8 )
      v4 = v8;
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = (void *)(uintptr_t)(off_128478);
    *(volatile uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return call_stack_helper(v4);
  }
  else
  {
    v6 = (void *)(uintptr_t)(off_128478);
    *(volatile uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return call_stack_helper(15);
  }
  return result;
}



